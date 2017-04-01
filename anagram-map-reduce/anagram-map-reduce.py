class Anagram:
    
    # @param {str} line a text, for example "Bye Bye see you next"
    def mapper(self, _, line):
        # Write your code here
        # Please use 'yield key, value' here
        words = line.split(' ')
        for w in words:
            w.replace(' ', '')
            if len(w):
                yield ''.join(sorted(list(w))), w


# @param key is from mapper
# @param values is a set of value with the same key
def reducer(self, key, values):
    # Write your code here
    # Please use 'yield key, value' here
    yield key, list(values)
