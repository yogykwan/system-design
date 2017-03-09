'''
Definition of BaseGFSClient
class BaseGFSClient:
    def readChunk(self, filename, chunkIndex):
        # Read a chunk from GFS
    def writeChunk(self, filename, chunkIndex, content):
        # Write a chunk to GFS
'''
class GFSClient(BaseGFSClient):

    # @param {int} chunkSize chunk size bytes
    def __init__(self, chunkSize):
        BaseGFSClient.__init__(self)
        # initialize your data structure here
        self.file_chunk = {}
        self.chunk_size = chunkSize

    # @param {str} filename a file name
    # @return {str} conetent of the file given from GFS
    def read(self, filename):
        # Write your code here
        if filename in self.file_chunk:
            n = self.file_chunk[filename]
        else:
            return None
        ans = ""
        for i in xrange(n):
            ans += BaseGFSClient.readChunk(self, filename, i)
        return ans

    # @param {str} filename a file name
    # @param {str} content a string
    # @return nothing
    def write(self, filename, content):
        # Write your code here
        le = len(content)
        for i in xrange(le / self.chunk_size):
            BaseGFSClient.writeChunk(self, filename, i, content[i * self.chunk_size: (i + 1) * self.chunk_size])
        self.file_chunk[filename] = le / self.chunk_size
        if le % self.chunk_size:
            BaseGFSClient.writeChunk(self, filename, le / self.chunk_size, content[le / self.chunk_size * self.chunk_size:])
            self.file_chunk[filename] += 1

