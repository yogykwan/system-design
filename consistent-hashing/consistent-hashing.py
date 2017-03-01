class Solution:
    # @param {int} n a positive integer
    # @return {int[][]} n x 3 matrix
    def consistentHashing(self, n):
        # Write your code here
        segments = []
        segments.append([0, 359, 1])
        for i in range(2, n + 1):
            j = 0
            for index, segment in enumerate(segments[1:]):
                tmp = segment[1] - segment[0]
                len = segments[j][1] - segments[j][0]
                if tmp > len or (tmp == len and segment[2] < segments[j][2]):
                    j = index + 1
            x = segments[j][0]
            y = segments[j][1]
            segments[j][1] = (x + y) / 2
            segments.append([(x + y) / 2 + 1, y, i])
        return segments

