class SortIntegers:
    
    # @param {int[]} nums a list of integer
    def mapper(self, _, nums):
        # Write your code here
        # Please use 'yield key, value' here
        for num in nums:
            yield num / 10000, num


    # @param key is from mapper
    # @param values is a set of value with the same key
    def reducer(self, key, values):
        # Write your code here
        # Please use 'yield key, value' here
        values.sort();
        yield key, values
