# Description

Given a long url, make it shorter. To make it simpler, let's ignore the domain name.

You should implement two methods:

1. longToShort(url). Convert a long url to a short url.
2. shortToLong(url). Convert a short url to a long url starts with http://tiny.url/.

You can design any shorten algorithm, the judge only cares about two things:

1. The short key's length should equal to 6 (without domain and slash). And the acceptable characters are [a-zA-Z0-9]. For example: abcD9E
2. No two long urls mapping to the same short url and no two short urls mapping to the same long url.

# Input

```
shortToLong(longToShort("http://www.lintcode.com/faq/?id=10"))
```

# Output

```
"http://www.lintcode.com/faq/?id=10"
```
