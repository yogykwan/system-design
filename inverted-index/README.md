# Description
Create an inverted index with given documents.

# Notice
Ensure that data does not include punctuation.

# Input
```
[{"id":1,"content":"This is the content of document1"}, {"id":2,"content":"This is the content of document2"}]
```

# Output
```
{"This":[1,2],"content":[1,2],"document1":[1],"document2":[2],"is":[1,2],"of":[1,2],"the":[1,2]}
```
