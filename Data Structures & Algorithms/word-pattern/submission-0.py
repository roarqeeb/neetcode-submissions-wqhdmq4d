class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        charToWord = {}
        wordToChar = {}
        words = s.split()

        if len(pattern) != len(words):
            return False

        for i, (c, word) in enumerate(zip(pattern, words)):
            if charToWord.get(c, 0) != wordToChar.get(word, 0):
                return False
            charToWord[c] = i + 1
            wordToChar[word] = i + 1

        return True        