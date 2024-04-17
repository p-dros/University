#! /usr/bin/env python
import socket
import unittest
import os


class TestUDPServer(unittest.TestCase):
    def setUp(self):
        self.server_address = ("127.0.0.1", 2020)  # replace with your server's address
        self.client = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    def tearDown(self):
        self.client.close()

    def test_responses(self):
        input_files = sorted([f for f in os.listdir("tests") if f.startswith("input_")])
        result_files = sorted(
            [f for f in os.listdir("tests") if f.startswith("result_")]
        )

        if len(input_files) != len(result_files):
            raise ValueError("Mismatch in number of input and result files")

        for input_file, result_file in zip(input_files, result_files):
            with open(os.path.join("tests", input_file), "rb") as input_f, open(
                os.path.join("tests", result_file), "rb"
            ) as result_f:
                input_data = input_f.read()
                expected_result = result_f.read()

                self.client.sendto(input_data, self.server_address)
                received_data, _ = self.client.recvfrom(1024)

                self.assertEqual(received_data, expected_result)


if __name__ == "__main__":
    unittest.main()
