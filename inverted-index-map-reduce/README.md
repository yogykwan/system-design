# Desciption

Use map reduce to build inverted index for given documents.

# Input

```
[{"id":1,"content":"This is the content of document1"}, 
{"id":2,"content":"This is the content of document2"}]
```

# Output

```
{"This":[1,2],"content":[1,2],"document1":[1],"document2":[2],"is":[1,2],"of":[1,2],"the":[1,2]}
```
