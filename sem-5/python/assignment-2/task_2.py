import re


def count_words(text):
    words = re.split(r"\s+", text.strip())
    wordsCount = 0
    for word in words:
        if re.search(r"^[a-zA-Z0-9]", word):
            wordsCount += 1
    return wordsCount


def count_letters(text):
    lettersCount = 0
    for char in text:
        if char.isalpha():
            lettersCount += 1
    return lettersCount


def count_digits(text):
    digitsCount = 0
    for char in text:
        if char.isdigit():
            digitsCount += 1
    return digitsCount


def count_frequencies(text):
    frequencies = {}
    for char in text:
        if char.isalpha():
            char = char.lower()
            frequencies[char] = frequencies.get(char, 0) + 1
        elif char.isdigit():
            frequencies[char] = frequencies.get(char, 0) + 1
    return frequencies


def count_and_analyze_text(text):
    results = {
        "words": count_words(text),
        "letters": count_letters(text),
        "digits": count_digits(text),
        "frequencies": count_frequencies(text),
    }

    return results


def test(text, expected_results):
    actual_results = count_and_analyze_text(text)
    for key, value in expected_results.items():
        assert actual_results[key] == value


if __name__ == "__main__":
    test("", {"words": 0, "letters": 0, "digits": 0, "frequencies": {}})
    test(
        "test",
        {
            "words": 1,
            "letters": 4,
            "digits": 0,
            "frequencies": {"t": 2, "e": 1, "s": 1},
        },
    )
    test(
        "this is a test",
        {
            "words": 4,
            "letters": 11,
            "digits": 0,
            "frequencies": {"t": 3, "h": 1, "i": 2, "s": 3, "a": 1, "e": 1},
        },
    )
