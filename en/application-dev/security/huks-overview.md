# HUKS Overview

### Introduction

Openharmony Universal KeyStore (HUKS) provides KeyStore (KS) capabilities for applications, including key management and key cryptography operations. HUKS also provides APIs for applications to import or generate keys.

### Basic Concepts

- HUKS provides key management functions, including encryption and decryption, signing and signature verification, key agreement and derivation, and Hash-based Message Authentication Code (HMAC) calculation.
- HUKS supports the following algorithms: AES and RSA in encryption and decryption, RSA, ECC, DSA, and ED25519 in signing and signature verification, PBKDF2 in key derivation, and DH, ECDH, and X25519 in key agreement.
- HUKS uses the OpenSSL and Mbed TLS algorithm libraries.

### Working Principles

HUKS manages keys through the following APIs in an Init-Update-Finish model:

- **Init**: reads the key, creates a session ID, and returns the session ID to the caller.

- **Update**: updates data by segment based on the session ID obtained.

- **Finish**: processes all data transferred to HUKS and then releases resources.

    >![](../public_sys-resources/icon-notice.gif)**NOTICE**:<br/>**Abort()** must be called to terminate the use of the key when an error occurs in any of **Init()**, **Update()**, and **Finish()**.


### Constraints
N/A
