# Description
Implement a counting bloom filter. Support the following method:

1. add(string). Add a string into bloom filter.
2. contains(string). Check a string whether exists in bloom filter.
3. remove(string). Remove a string from bloom filter.

# Input

```
CountingBloomFilter(3)
add("lint")
add("code")
contains("lint")
remove("lint")
contains("lint")
```

# Output

```
true
false
```
