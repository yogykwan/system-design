# Description

LFU (Least Frequently Used) is a famous cache eviction algorithm.

For a cache with capacity k, if the cache is full and need to evict a key in it, the key with the lease frequently used will be kicked out.

Implement set and get method for LFU cache.

# Input

```
3, [set(2,2),set(1,1),get(2),get(1),get(2),set(3,3),set(4,4),get(3),get(2),get(1),get(4)]
```

# Output

```
[2,1,2,-1,2,1,4]
```
