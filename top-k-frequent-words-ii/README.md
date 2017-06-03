# Desciption

Find top k frequent words in realtime data stream.

Implement three methods for Topk Class:

1. TopK(k). The constructor.
2. add(word). Add a new word.
3. topk(). Get the current top k frequent words.

# Notice

If two words have the same frequency, rank them by alphabet.

# Input

```
TopK(2)
add("lint")
add("code")
add("code")
topk()
```

# Output

```
["code", "lint"]
```
