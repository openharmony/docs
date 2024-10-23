# MD Overview and Algorithm Specifications

The message digest (MD) algorithm allows a fixed-length digest to be generated from data of arbitrary size by using the hash algorithm. The MD algorithm is also referred to as a hash algorithm or a one-way hash algorithm.


When the same digest algorithm is used, the generated digest (hash value) has the following features:


- The same message always results in the same hash value.

- The digest generated is of the fixed length no matter the length of messages. (The digest length is determined by the algorithm used).

- It is almost impossible to find two different messages with the same hash value. (The probability still exists, depending on the length of the digest.)


## Supported Algorithms and Specifications

The **Supported Type** column in the following table lists the algorithm to be used when an **Md** instance is created.

| MD Algorithm| Supported Type| API Version| 
| -------- | -------- | -------- |
| HASH | SHA1 | 9+ | 
| HASH | SHA224 | 9+ | 
| HASH | SHA256 | 9+ | 
| HASH | SHA384 | 9+ | 
| HASH | SHA512 | 9+ | 
| HASH | MD5 | 9+ | 
| HASH | SM3 | 10+ | 
