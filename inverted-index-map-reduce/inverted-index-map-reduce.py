'''
    Definition of Document
    class Document:
    def __init__(self, id, cotent):
    self.id = id
    self.content = content
    '''
class InvertedIndex:
    
    # @param {Document} value is a document
    def mapper(self, _, value):
        # Write your code here
        # Please use 'yield key, value' here
        content = value.content
        id = value.id
        words = content.split(' ')
        for word in words:
            word.replace(' ', '')
            if len(word):
                yield word, id


# @param key is from mapper
# @param values is a set of value with the same key
def reducer(self, key, values):
    # Write your code here
    # Please use 'yield key, value' here
    if len(values) == 0:
        yield key, []
        values.sort()   # reduce should've gotten sorted data
        ans = [values[0]]
        pre = values[0]
        for v in values[1:]:
            if v != pre:
                ans.append(v)
                pre = v
    yield key, ans
