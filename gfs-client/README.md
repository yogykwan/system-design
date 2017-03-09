# Description

Implement a simple client for GFS (Google File System, a distributed file system), it provides the following methods:

1. read(filename). Read the file with given filename from GFS.
2. write(filename, content). Write a file with given filename & content to GFS.

There are two private methods that already implemented in the base class:

1. readChunk(filename, chunkIndex). Read a chunk from GFS.
2. writeChunk(filename, chunkIndex, chunkData). Write a chunk to GFS.

To simplify this question, we can assume that the chunk size is chunkSize bytes. (In a real world system, it is 64M). The GFS Client's job is splitting a file into multiple chunks (if need) and save to the remote GFS server. chunkSize will be given in the constructor. You need to call these two private methods to implement read & write methods.

# Input

```
GFSClient(5)
read("a.txt")
write("a.txt", "World")
read("a.txt")
write("b.txt", "111112222233")
write("b.txt", "aaaaabbbbb")
read("b.txt")
```

# Output

```
null
"World"
"aaaaabbbbb"
```

