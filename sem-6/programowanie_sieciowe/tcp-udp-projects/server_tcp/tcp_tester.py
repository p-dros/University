import sys 
import threading
import time
import socket
from collections import namedtuple


def run_test(host, port, test, test_number):
	with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
		s.connect((host, port))
		for request in test.test:
			s.sendall(request)
			time.sleep(0.01) 
		time.sleep(0.5)
		response = s.recv(1024)
		if response == test.answer:
			print(f"TEST {test_number} SUCCEED")
		else:
			print(f'''
				TEST {test_number} FAILED\n
				Sent: {test.test}\n
				Expected response: {test.answer}\n
				Got response: {response}
				''')

def main():

	ADDRESS = '127.0.0.1'
	if len(sys.argv) < 2:
		raise ValueError(f"Usage: {sys.argv[0]} port *tests_to_call")

	_, port, *tests_to_call = sys.argv
	port = int(port)


	Test = namedtuple("Test", "test answer")
	tests = {
			1:	Test([b'kajak\r\n'], b'1/1\r\n'),
			2: 	Test([b'Ala i kot\r\n'], b'2/3\r\n'),
			3:	Test([b'xyz\r\nnucho oko\r\n'], b'0/1\r\n1/2\r\n'),
			4:	Test([b'ABBA 1972\r\n', b'Oala ma psa.\r\n', b' nadmiarowe  spacje\r\n', b'a i o u w z\r\n'], b'ERROR\r\nERROR\r\nERROR\r\n6/6\r\n'),
			5:	Test([b'b\xc3\xb3b i fasola\r\n'], b'ERROR\r\n'),
			6: 	Test([b'oraz\x00zero\r\n'], b'ERROR\r\n'),
			12: 	Test([b'kot', b'\r\npies', b'\r\ni ala\r\n'], b'0/1\r\n0/1\r\n2/2\r\n'),
			13:	Test([b'a ',b'b ',b'c ',b'd ',b'e ',b'f ', b'g ', b'h ', b'i ', b'j ', b'k ', b'l ', b'm ', b'n ', b'o ', b'p ', b'q ', b'r ', b's ', b't ', b'u ', b'v ', b'w ', b'x ', b'y ', b'z\r\n'], b'26/26\r\n'),
			101: Test([b'kajak ala niepalindrom\r\n'], b'2/3\r\n'),
			102: Test([b'ala kajak faka\r\n', b'tu powinno tez zadzialac\r\n'], b'2/3\r\n0/4\r\n'),
			103: Test([b'pies', b' i', b' kot', b' i', b' Ala\r\n'], b'3/5\r\n'), 
			104: Test([b'\r\n'], b'0/0\r\n'),
			105: Test([b'a'*1024], b''),
			106: Test([b'a'*1022+b'\r\n'], b'1/1\r\n'),
			107: Test([b'ala\r', b'\ni kot\r\n', b'ono', b'mato', b'peja', b'\r', b'\n'], b'1/1\r\n1/2\r\n0/1\r\n'),

			108: Test([b'a', b'l', b'a', b'\r', b'\n'], b'1/1\r\n'), 
			109: Test([b'\r', b'\n', b'\r', b'\n'], b'0/0\r\n0/0\r\n'),
			110: Test([b'a' for _ in range(1022)] + [b'\r\n'], b'1/1\r\n'),
			111: Test([b'a'*1024], b''),
			112: Test([b' ' for _ in range(20)] + [b'\r', b'\n'], b'ERROR\r\n'),
			113: Test([b'\1\2\3\4\5', b'\1\2\3'], b''),
			114: Test([b'a'*1050], b''), 
		
		}
	if tests_to_call:
		tests = {num: test for num, test in tests.items() if num in [int(to_call) for to_call in tests_to_call]}
	threads = []
	for num, test in tests.items():
		thread = threading.Thread(target=run_test, args=(ADDRESS, port, test, num))
		threads.append(thread)
		thread.start()
		time.sleep(0.5)

	for thread in threads:
		thread.join()
if __name__ == "__main__":
	main()
