"""
    Definition of Column:
    class Column:
    def __init__(self, key, value):
    self.key = key
    self.value = value
    """

import bisect


class MiniCassandra:
    
    def __init__(self):
        # initialize your data structure here.
        self.hashs = {}
        self.cols = {}
    
    # @param {string} raw_key a string
    # @param {int} column_key an integer
    # @param {string} column_value a string
    # @return nothing
    def insert(self, raw_key, column_key, column_value):
        # Write your code here
        if raw_key not in self.hashs:
            self.hashs[raw_key] = []
            self.cols[raw_key] = {}
        if column_key not in self.hashs[raw_key]:
            bisect.insort(self.hashs[raw_key], column_key)
        self.cols[raw_key][column_key] = column_value
    
    # @param {string} raw_key a string
    # @param {int} column_start an integer
    # @param {int} column_end an integer
    # @return {Column[]} a list of Columns
    def query(self, raw_key, column_start, column_end):
        # Write your code here
        ans = []
        if raw_key not in self.hashs:
            return ans
        index = bisect.bisect_left(self.hashs[raw_key], column_start)
        if index == len(self.hashs[raw_key]):
            return ans
        for i in range(index, len(self.hashs[raw_key])):
            col = self.hashs[raw_key][i]
            if col > column_end:
                break
            ans.append(Column(col, self.cols[raw_key][col]))
        return ans
