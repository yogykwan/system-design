class Typeahead:

    # @param dict: A dictionary of words dict
    def __init__(self, dict):
        # do initialize if necessary
        self.word_dict = {}
        for s in dict:
            s_len = len(s)
            for i in range(s_len):
                for j in range(i, s_len):
                    word = s[i: j + 1]
                    if word not in self.word_dict:
                        self.word_dict[word] = [s]
                    elif self.word_dict[word][-1] != s:
                        self.word_dict[word].append(s)

    # @param word: a string
    # @return a list of words
    def search(self, word):
        # write your code here
        if word in self.word_dict:
            return self.word_dict[word]
        else:
            return []
