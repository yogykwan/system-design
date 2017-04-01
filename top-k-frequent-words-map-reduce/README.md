# Desciption

Find top k frequent words with map reduce framework.

The mapper's key is the document id, value is the content of the document, words in a document are split by spaces.

For reducer, the output should be at most k key-value pairs, which are the top k words and their frequencies in this reducer. The judge will take care about how to merge different reducers' results to get the global top k frequent words, so you don't need to care about that part.

The k is given in the constructor of TopK class.

# Notice

For the words with same frequency, rank them with alphabet.

# Input

```
2
[{"id":1,"content":"lintcode is the best online judge I love lintcode"}, 
{"id":2,"content":"lintcode is an online judge for coding interview you can test your code online at lintcode"}]
```

# Output

```
"lintcode", 4
"online", 3
```
