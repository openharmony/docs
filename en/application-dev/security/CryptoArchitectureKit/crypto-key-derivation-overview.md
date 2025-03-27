# Key Derivation Overview and Algorithm Specifications

A key derivation function (KDF) is a cryptographic algorithm that derives one or more secrete keys from a secret value by using a pseudorandom function (PRF). It can be used to stretch keys into longer keys or to obtain keys in the required format.

## PBKDF2

Password-Based Key Derivation Function (PBKDF) is a key derivation function with a sliding computational cost. PBKDF2 is part of the PKCS series.

PBKDF2 applies a PRF, such as an [HMAC](crypto-compute-mac.md), to an input password together with a salt value, and repeats the process multiple times to generate a derived key.

When creating a **kDF** instance, you need to specify the algorithm specifications in a string parameter. The string parameter consists of the KDF algorithm and HMAC algorithm with a vertical bar (|) in between.
| KDF Algorithm| HMAC Algorithm| String Parameter| API Version|
| -------- | -------- | -------- | -------- |
| PBKDF2 | SHA1 | PBKDF2\|SHA1 | 11+ |
| PBKDF2 | SHA224 | PBKDF2\|SHA224 | 11+ |
| PBKDF2 | SHA256 | PBKDF2\|SHA256 | 11+ |
| PBKDF2 | SHA384 | PBKDF2\|SHA384 | 11+ |
| PBKDF2 | SHA512 | PBKDF2\|SHA512 | 11+ |
| PBKDF2 | SM3 | PBKDF2\|SM3 | 11+ |

## HKDF

HMAC-based Extract-and-Expand Key Derivation Function (HKDF) is a simple KDF based on an [HMAC](crypto-compute-mac.md). It is used to expand limited input key material into a cryptographically strong secret key.

The HKDF has three modes:

- **EXTRACT_ONLY**: generates a pseudorandom key (PRK) from the input key material (IKM) and an optional salt.
- **EXPAND_ONLY**: expands the PRK to a key of the specified length.
- **EXTRACT_AND_EXPAND**: generates a PRK from the IKM and salt, and expands it to a key of the specified length. 

When creating a **kDF** instance, you need to specify the algorithm specifications in a string parameter. The string parameter consists of the KDF algorithm, HMAC algorithm, and mode with a vertical bar (|) in between.
| KDF Algorithm| HMAC Algorithm| Mode| String Parameter| API Version|
| -------- | -------- | -------- | -------- | -------- |
| HKDF | SHA1 | [EXPAND_ONLY\|EXTRACT_ONLY\|EXTRACT_AND_EXPAND] | HKDF\|SHA1 | 12+ |
| HKDF | SHA224 | [EXPAND_ONLY\|EXTRACT_ONLY\|EXTRACT_AND_EXPAND] | HKDF\|SHA224 | 12+ |
| HKDF | SHA256 | [EXPAND_ONLY\|EXTRACT_ONLY\|EXTRACT_AND_EXPAND] | HKDF\|SHA256 | 12+ |
| HKDF | SHA384 | [EXPAND_ONLY\|EXTRACT_ONLY\|EXTRACT_AND_EXPAND] | HKDF\|SHA384 | 12+ |
| HKDF | SHA512 | [EXPAND_ONLY\|EXTRACT_ONLY\|EXTRACT_AND_EXPAND] | HKDF\|SHA512 | 12+ |
| HKDF | SM3 | [EXPAND_ONLY\|EXTRACT_ONLY\|EXTRACT_AND_EXPAND] | HKDF\|SM3 | 12+ |
