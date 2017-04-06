# Description

Implement a standard bloom filter. Support the following method:

1. StandardBloomFilter(k),The constructor and you need to create k hash functions.
2. add(string). add a string into bloom filter.
3. contains(string). Check a string whether exists in bloom filter.

# Input

```
StandardBloomFilter(3)
add("lint")
add("code")
contains("lint")
contains("world")
```

# Output

```
true
false
```
