import unittest


def add_next_element(structure):
    most_nested_lists = []
    max_depth = 0

    def traverse(element, depth=0):
        nonlocal most_nested_lists
        nonlocal max_depth

        if isinstance(element, list):
            if depth > max_depth:
                max_depth = depth
                most_nested_lists = [element]
            elif depth == max_depth:
                most_nested_lists.append(element)

            for sub_element in element:
                traverse(sub_element, depth + 1)
        if isinstance(element, dict):
            for sub_element in element.values():
                traverse(sub_element, depth)
        if isinstance(element, tuple):
            for sub_element in element:
                traverse(sub_element, depth + 1)

    traverse(structure)

    for sublist in most_nested_lists:
        sublist.append(
            max((x for x in sublist if not isinstance(x, (dict, tuple))), default=0) + 1
        )
    return structure


class TestNestedListUpdate(unittest.TestCase):
    def test_update_nested_list1(self):
        input_list = [1, [2, 3], 4]
        expected_output = [1, [2, 3, 4], 4]
        self.assertEqual(add_next_element(input_list), expected_output)

    def test_update_nested_list2(self):
        input_list = [3, 4, [2, [1, 2, [7, 8], 3, 4], 3, 4], 5, 6, 7]
        expected_output = [3, 4, [2, [1, 2, [7, 8, 9], 3, 4], 3, 4], 5, 6, 7]
        self.assertEqual(add_next_element(input_list), expected_output)

    def test_update_nested_list3(self):
        input_list = [1, [3], [2]]
        expected_output = [1, [3, 4], [2, 3]]
        self.assertEqual(add_next_element(input_list), expected_output)

    def test_update_nested_list4(self):
        input_list = [
            1,
            2,
            [3, 4, [5, {"klucz": [5, 6], "tekst": [1, 2]}], 5],
            "hello",
            3,
            [4, 5],
            (5, [6, [7, 8]]),
        ]
        expected_output = [
            1,
            2,
            [3, 4, [5, {"klucz": [5, 6, 7], "tekst": [1, 2, 3]}], 5],
            "hello",
            3,
            [4, 5],
            (5, [6, [7, 8, 9]]),
        ]
        self.assertEqual(add_next_element(input_list), expected_output)


if __name__ == "__main__":
    unittest.main()
