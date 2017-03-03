import bisect
import random


class Solution:
    
    # @param {int} n a positive integer
    # @param {int} k a positive integer
    # @return {Solution} a Solution object
    @classmethod
    def create(cls, n, k):
        # Write your code here
        solution = cls()
        solution.points = []
        solution.point_machine = {}
        solution.n_shards = n
        solution.n_points = k
        return solution
    
    # @param {int} machine_id an integer
    # @return {int[]} a list of shard ids
    def addMachine(self, machine_id):
        # write your code here
        point_list = []
        for i in range(self.n_points):
            while True:
                tmp = random.randint(0, self.n_shards - 1)
                index = bisect.bisect_left(self.points, tmp)
                if index == len(self.points) or self.points[index] != tmp:
                    bisect.insort(self.points, tmp)
                    self.point_machine[tmp] = machine_id
                    point_list.append(tmp)
                    break
        return point_list
    
    # @param {int} hashcode an integer
    # @return {int} a machine id
    def getMachineIdByHashCode(self, hashcode):
        # write your code here
        index = bisect.bisect_left(self.points, hashcode)
        if index == len(self.points):
            index = 0
        return self.point_machine[self.points[index]]
