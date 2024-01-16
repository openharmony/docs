# Symmetric Key Generation and Conversion Specifications


This topic describes the symmetric key algorithms supported and specifications for symmetric key generation and conversion.


A key can be generated based on a string parameter, which holds key specifications. The string parameters supported by each algorithm are provided in the specific algorithm specifications.


## AES

Advanced Encryption Standard (AES) is the most common symmetric encryption algorithm.

It has the following features:

- AES is a block cipher with a block size of 128 bits.

- The key length can be 128 bits, 192 bits, or 256 bits.

- It provides higher security and faster processing speed than Triple Data Encryption Standard (3DES).


An AES key can be generated from a string parameter, which consists of the symmetric key algorithm and key length. The string parameter is used to specify the key specifications when a symmetric key generator is created.


| Symmetric Key Algorithm| Key Length (Bit)| String Parameter| API Version|
| -------- | -------- | -------- | -------- |
| AES | 128 | AES128 | 9+ |
| AES | 192 | AES192 | 9+ |
| AES | 256 | AES256 | 9+ |


## 3DES

3DES is also called 3DESede or Triple DES.

It has the following features:

- 3DES uses three 64-bit keys to encrypt a data block three times, which means to apply the DES cipher three times to each data block.

- Compared with DES, 3DES provides higher security due to longer key length, but lower processing speed.

A 3DES key can be generated from a string parameter, which consists of the symmetric key algorithm and key length. The string parameter is used to specify the key specifications when a symmetric key generator is created.

| Symmetric Key Algorithm| Key Length (Bit)| String Parameter| API Version|
| -------- | -------- | -------- | -------- |
| 3DES | 192 | 3DES192 | 9+ |


## SM4

ShangMi 4 (SM4) is a symmetric algorithm.

It has the following features:

- SM4 is a block cipher with a block size of 128 bits.

- The key length is also 128 bits, which can be extended by an expansion key.

- Both the encryption algorithm and the key expansion algorithm use a 32-round non-linear iteration structure. A non-linear key scheduler is used to produce the round keys. The decryption uses the same round keys as for encryption, except that they are in reversed order.

An SM4 key can be generated from a string parameter, which consists of the symmetric key algorithm and key length with an underscore (_) in between. The string parameter is used to specify the key specifications when a symmetric key generator is created.

| Symmetric Key Algorithm| Key Length (Bit)| String Parameter| API Version|
| -------- | -------- | -------- | -------- |
| SM4 | 128 | SM4_128 | 10+ |


## HMAC

Hash-based Message Authentication Code (HMAC) is a hash-based message authentication code algorithm. A symmetric key is required for calculation.

It has the following features:

An HMAC key can be of any length.

-  If the key length is greater than the HMAC block length, the one-way hash result of the key is used as the new key.

-  If the key length is less than the HMAC block length, 0s are padded at the end of the key as the new key. That is, the key length is the same as the HMAC block length.

- You are advised to use the output length of the message digest (MD) algorithm as the key length.

An HMAC key can be generated from a string parameter, which consists of the MAC algorithm and MD algorithm with a vertical bar (|) in between. The string parameter is used to specify the key specifications when a symmetric key generator is created.

| MAC Algorithm| MD Algorithm| Key Length (Bit)| String Parameter| API Version|
| -------- | -------- | -------- | -------- | -------- |
| HMAC | SHA1 | 160 | HMAC\|SHA1 | 11+ |
| HMAC | SHA224 | 224 | HMAC\|SHA224 | 11+ |
| HMAC | SHA256 | 256 | HMAC\|SHA256 | 11+ |
| HMAC | SHA384 | 384 | HMAC\|SHA384 | 11+ |
| HMAC | SHA512 | 512 | HMAC\|SHA512 | 11+ |
| HMAC | SM3 | 256 | HMAC\|SM3 | 11+ |
| HMAC | - | [1, 32768] | HMAC | 11+ |

If the key length to be used is not within the range of the listed digest algorithms, you can use the string parameter **HMAC** to create a symmetric key generator and then generate a key based on the binary data of the HMAC key.
