'''
Definition of Document
class Document:
    def __init__(self, id, cotent):
        self.id = id
        self.content = content
'''


class Solution:
    # @param {Document[]} docs a list of documents
    # @return {dict(string, int[])} an inverted index
    def invertedIndex(self, docs):
        # Write your code here
        ans = {}
        for doc in docs:
            words = doc.content.split(' ')
            for word in words:
                if len(word) == 0:
                    continue
                if word not in ans:
                    ans[word] = []
                if doc.id not in ans[word]:
                    ans[word].append(doc.id)
        return ans

