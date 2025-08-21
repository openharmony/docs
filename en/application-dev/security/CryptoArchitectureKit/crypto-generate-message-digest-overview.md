# MD Overview and Algorithm Specifications

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

The message digest (MD) algorithm allows a fixed-length digest to be generated from data of arbitrary size by using the hash algorithm. The MD algorithm is also referred to as a hash algorithm or a one-way hash algorithm.

When the same digest algorithm is used, the generated digest (hash value) has the following features:

- The same message always results in the same hash value.

- The digest generated is of the fixed length no matter the length of messages. (The digest length is determined by the algorithm used). For example, SHA-256 generates a digest of 256 bits (32 bytes).

## Supported Algorithms and Specifications

The **Supported Type** column in the following table lists the algorithm to be used when an **MD** instance is created.

| MD Algorithm| Supported Type| Length (Bytes)|  API Version|
| -------- | -------- | -------- | -------- |
| HASH | SHA1 | 20 | 9+ |
| HASH | SHA224 | 28 | 9+ |
| HASH | SHA256 | 32 | 9+ |
| HASH | SHA384 | 48 | 9+ |
| HASH | SHA512 | 64 | 9+ |
| HASH | MD5 | 16 | 9+ |
| HASH | SM3 | 32 | 10+ |
