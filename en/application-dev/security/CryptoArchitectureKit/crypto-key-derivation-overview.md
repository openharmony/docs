# Key Derivation Overview and Algorithm Specifications

A key derivation function (KDF) is a cryptographic algorithm that derives one or more secrete keys from a secret value (such as a master key) by using a pseudorandom function. It can be used to stretch keys into longer keys or to obtain keys in the required format.

## Supported Algorithms and Specifications

### PBKDF2

Password-Based Key Derivation Function (PBKDF) is a key derivation function with a sliding computational cost. PBKDF2 is part of the PKCS series.

PBKDF2 applies a pseudorandom function (PRF), such as [HMAC](crypto-compute-mac.md), to an input password together with a salt value, and repeats the process multiple times to generate a derived key.

When creating a **kDF** instance, you need to specify the algorithm specifications in a string parameter. The string parameter consists of the KDF algorithm and HMAC algorithm with a vertical bar (|) in between.
| KDF Algorithm| HMAC Algorithm| String Parameter| API Version|
| -------- | -------- | -------- | -------- |
| PBKDF2 | SHA1 | PBKDF2\|SHA1 | 11+ |
| PBKDF2 | SHA224 | PBKDF2\|SHA224 | 11+ |
| PBKDF2 | SHA256 | PBKDF2\|SHA256 | 11+ |
| PBKDF2 | SHA384 | PBKDF2\|SHA384 | 11+ |
| PBKDF2 | SHA512 | PBKDF2\|SHA512 | 11+ |
| PBKDF2 | SM3 | PBKDF2\|SM3 | 11+ |

### HKDF

HMAC-based Extract-and-Expand Key Derivation Function (HKDF) is a simple key derivation function (KDF) based on the [HMAC](crypto-compute-mac.md) message authentication code. It is used to expand limited input key material into a cryptographically strong secret key.

HKDF consists of two modules: HKDF-Extract and HKDF-Expand.

HKDF-Extract: generates a cryptographic pseudorandom key (PRK) from the input key material and an optional salt.

HKDF-Expand: expands the PRK to a key of the specified length.

When creating a **kDF** instance, you need to specify the algorithm specifications in a string parameter. The string parameter consists of the KDF algorithm, HMAC algorithm, and mode with a vertical bar (|) in between.
| KDF Algorithm| HMAC Algorithm| String Parameter| API Version|
| -------- | -------- | -------- | -------- |
| HKDF | SHA1 | HKDF\|SHA1 | 12+ |
| HKDF | SHA224 | HKDF\|SHA224 | 12+ |
| HKDF | SHA256 | HKDF\|SHA256 | 12+ |
| HKDF | SHA384 | HKDF\|SHA384 | 12+ |
| HKDF | SHA512 | HKDF\|SHA512 | 12+ |
| HKDF | SM3 | HKDF\|SM3 | 12+ |
