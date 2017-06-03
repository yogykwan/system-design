class Solution:
    # @param {string[]} words a list of string
    # @param {int} k an integer
    # @return {string[]} a list of string
    def topKFrequentWords(self, words, k):
        # Write your code here
        records = {}
        for word in words:
            if word in records:
                records[word] += 1
            else:
                records[word] = 1
        ans = []
        for key, value in records.items():
            ans.append((-value, key))
        ans.sort()
        strs = []
        for i in range(min(k, len(ans))):
            strs.append(ans[i][1])
        return strs
