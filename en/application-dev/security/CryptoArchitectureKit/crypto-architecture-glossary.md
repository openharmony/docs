# Glossary

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=aa06c886eeb3255af276443f6027a6aec8e8ffbf translatedAt=2026-08-17T10:44:15.302Z pushedAt=2026-08-17T10:59:54.872Z -->

## A

### AES Advanced Encryption Standard

The most common symmetric encryption algorithm, which is a block cipher algorithm. It has a block length of 128 bits and a key length of 128, 192, or 256 bits. Compared with 3DES, it offers higher security and faster processing speed, and is used to ensure data confidentiality in storage or transmission scenarios. It supports multiple encryption modes, including ECB, CBC, OFB, CFB, CTR, GCM, CCM, and XTS.

### AES-WRAP

A key encapsulation encryption algorithm based on AES for securely storing or transmitting symmetric keys. Its main purpose is to protect keys through encryption, preventing them from being leaked or tampered with during storage or transmission.

### Asymmetric Key

A key system that uses two keys, a public key and a private key, for algorithm operations. The public key is made public, while the private key is kept secret. For encryption and decryption, the public key is generally used for encryption and the private key for decryption. For signature generation and verification, the private key is used for signing and the public key for verification, thereby verifying whether the data has been tampered with.

## B

### Block Cipher

A symmetric encryption algorithm that divides plaintext into fixed-length data blocks and encrypts each block separately. AES, DES, 3DES, SM4, RC2, Blowfish, and CAST are all block ciphers. When the last block of plaintext is shorter than the block length, it must be padded to the required length using a padding scheme.

### Blowfish

A block cipher algorithm with a block length of 64 bits (8 bytes) and a key length from 32 to 448 bits (must be a multiple of 8). It supports block modes such as ECB, CBC, OFB, and CFB. This algorithm is insecure and not recommended.

## C

### CAST

A block cipher algorithm (such as CAST-128/CAST5) with a block length of 64 bits (8 bytes) and a key length from 40 to 128 bits (must be a multiple of 8). It supports block cipher modes such as ECB, CBC, OFB, and CFB. This is an insecure algorithm and is not recommended.

### ChaCha20 Stream Cipher Algorithm

A modern stream cipher symmetric encryption algorithm with a key length of 256 bits. ChaCha20 can be used alone, but it provides only confidentiality. More commonly, it is combined with the Poly1305 authenticator as the ChaCha20-Poly1305 AEAD mode, which provides both confidentiality and integrity.

### Cipher-based Message Authentication Code (CMAC)

A block cipher-based algorithm (such as AES) that generates a message authentication code using a key to ensure message integrity and authenticity, and to detect tampering during transmission.

### Compressed/Uncompressed Point Format

Two encoding formats for elliptic curve public key points. The uncompressed format stores both the x and y coordinates, while the compressed format stores only the x coordinate and a flag bit. ECC and SM2 public key point data can be converted between the compressed and uncompressed formats.

## D

### DES Data Encryption Standard

A block cipher algorithm that divides plaintext into 64-bit blocks for encryption. The encryption process consists of 16 rounds of the same encryption function, each round using a subkey generated from the original key through permutation and shifting. The key length is 64 bits.

### Diffie-Hellman Key Exchange Diffie-Hellman

A key agreement algorithm that involves only the exchange of public keys. Ephemeral DH (DHE) provides forward secrecy, so that the private keys of both parties are not exposed even when the communication channel is monitored. It supports well-known safe prime groups such as `modp` and `ffdhe`.

### Digital Signature Algorithm (DSA)

A public-key cryptography algorithm based on modular arithmetic and the discrete logarithm problem over finite fields of integers. It is commonly used for digital signature generation and verification, and cannot be used for encryption or decryption.

## E

### Elliptic Curve Cryptography (ECC)

A public-key cryptography algorithm based on elliptic curve mathematics, which can be regarded as operations on numbers defined over a special set. All ECC keys supported by the current algorithm library are elliptic curves over the Fp field (prime field).

### Elliptic Curve Diffie-Hellman Key Exchange (ECDH)

A Diffie-Hellman key agreement algorithm based on elliptic curves. The algorithm library provides ECDH capabilities over multiple elliptic curves (such as ECC224, ECC256, the Brainpool series, and Secp256k1) for negotiating a shared key over an insecure channel.

### Elliptic Curve Digital Signature Algorithm (ECDSA)

A digital signature algorithm based on elliptic curve cryptography (ECC). Compared with public-key cryptosystems based on the discrete logarithm problem (DLP) and the integer factorization problem (IFP), elliptic curve cryptography offers higher strength per bit and supports the OnlySign/OnlyVerify modes.

### Elliptic Curve Integrated Encryption Scheme (ECIES)

A hybrid encryption algorithm based on elliptic curve cryptography that combines key agreement (ECC), key derivation (X963KDF), and symmetric encryption (AES-GCM) to perform encryption and decryption.

### Ed25519

Ed25519 is a digital signature algorithm based on the EdDSA algorithm and the Edwards curve (Curve25519), with a key length of 256 bits.

## H

### Hardware Entropy

A hardware random number entropy source obtained through HUKS from a secure environment (such as a TEE or a secure chip). It is used to generate secure random numbers with greater "true randomness", making the results harder to guess or reproduce.

### Hash-based Message Authentication Code (HMAC)

A hash-based message authentication code algorithm that takes a key shared by both communicating parties and the message as input to generate a fixed-length authentication code for verifying message integrity. It adds a key input on top of the message digest algorithm to ensure information correctness.

### HMAC-based Extract-and-Expand Key Derivation Function (HKDF)

A key derivation algorithm based on HMAC message authentication codes, used to derive a longer output key from a shorter input key. It provides three modes: extract (EXTRACT_ONLY), expand (EXPAND_ONLY), and extract and expand (EXTRACT_AND_EXPAND).

## K

### Key Derivation Function (KDF)

A function that derives one or more keys from a secret value using a pseudo-random function. It can be used to expand a key into a longer key.

### Key-Encapsulation Mechanism (KEM)

A mechanism used to securely negotiate a shared key over an insecure channel. The encapsulator uses a public key to generate a shared key and an encapsulated key, and the decapsulator uses the private key and the encapsulated key to recover the same shared key.

### Key Agreement

A mechanism by which two communicating parties negotiate a secure shared key over an insecure channel without pre-sharing any secret. Corresponding algorithms include ECDH, X25519, and DH.

## M

### Message Authentication Code (MAC)

A code used to verify message integrity. It detects information spoofing, tampering, and similar behaviors by using a key shared by both parties.

### Message Digest 5 (MD5)

A message digest algorithm that generates a 16-byte (128-bit) fixed-length digest. It has low security and is not suitable for scenarios with high security requirements.

### Message Digest

The process of mapping a message of arbitrary length to a fixed-length digest value through a hash algorithm, also known as cryptographic hashing. The digest length is determined by the algorithm.

### Module-Lattice-Based Digital Signature Algorithm (ML-DSA)

A module-lattice-based post-quantum digital signature cryptographic algorithm used for signature generation and verification. It supports parameter sets such as ML-DSA-44, ML-DSA-65, and ML-DSA-87.

### Module-Lattice-Based Key-Encapsulation Mechanism (ML-KEM)

A module-lattice-based post-quantum cryptographic algorithm for key encapsulation, used for key encapsulation and decapsulation, supporting parameter sets such as ML-KEM-512, ML-KEM-768, and ML-KEM-1024.

## P

### Password-Based Key Derivation Function 2 (PBKDF2)

One of the PKCS series of standards, a key derivation function with variable computational cost that derives keys by feeding the plaintext password and a salt into a pseudorandom function (such as hash-based HMAC) and repeating the operation multiple times.

### Public-Key Cryptography Standards (PKCS) #1

The PKCS #1 standard defines the format of RSA keys, the encryption schemes RSAES-OAEP and RSAES-PKCS1-v1_5, and the signature schemes RSASSA-PSS and RSASSA-PKCS1-v1_5.

### Public-Key Cryptography Standards (PKCS) #5

PKCS #5 is a password-based encryption standard that also defines the PKCS #5 padding algorithm, which supports only 8-byte padding.

### Public-Key Cryptography Standards (PKCS) #7

A general-purpose message encapsulation standard. The padding rule it defines is a generalized version of PKCS #5 padding (supporting any block size).

### Poly1305

Poly1305 is a high-speed, one-time message authentication code (MAC) algorithm. It is mainly used between two parties sharing a key to verify the authenticity and integrity of messages, ensuring that messages are not tampered with during transmission. A common use case is to combine it with the stream cipher algorithm ChaCha20 to form the ChaCha20-Poly1305 AEAD mode, which provides both confidentiality and integrity.

### Probabilistic Signature Scheme (PSS)

The RSASSA-PSS mode defined in RFC3447. PSS is a probabilistic padding scheme for RSA signatures. It requires two digests (`md` and `mgf1_md`) and allows setting the salt length.

## R

### RC2

A block cipher algorithm with a block length of 64 bits (8 bytes) and a key length from 8 to 1024 bits (must be a multiple of 8). It supports the ECB, CBC, OFB, and CFB block modes. It is an insecure algorithm and is not recommended.

### RC4

A stream cipher algorithm that requires no block division or padding. It supports a key length of 8 to 4096 bits (in multiples of 8). An insecure algorithm and is not recommended.

### Random Seed

Data used to initialize the internal state of a pseudorandom number generator. The generator generates a series of random sequences based on the seed.

### RIPEMD160

A message digest algorithm that generates a fixed-length 20-byte (160-bit) digest. It is an insecure algorithm and is not recommended.

### Rivest-Shamir-Adleman (RSA)

An asymmetric encryption and signature generation and verification algorithm. Its key specification is determined by the key length (in bits) and the number of primes, supporting 512 to 8192 bits and 2 to 5 primes. Encryption and decryption support the NoPadding, PKCS1, and PKCS1_OAEP padding schemes, and signature generation and verification support the PKCS1 and PSS padding schemes.

## S

### scrypt

A key derivation function that requires substantial memory and computational resources. It generates an encryption key from an input password and salt. Its main parameters include the iteration count `n`, block size `r`, and parallelism `p`, which can be tuned based on security requirements and hardware performance.

### Secure Random Number

A random number used in scenarios such as temporary session key generation and asymmetric encryption algorithm key generation. It must be random, unpredictable, and non-reproducible, and must satisfy the cryptographic security requirements for pseudorandomness.

### Secure Hash Algorithm (SHA)

A family of secure hash digest algorithms, including SHA1, SHA224, SHA256, SHA384, and SHA512, which generate fixed-length digests of 20, 28, 32, 48, and 64 bytes, respectively.

### Secure Hash Algorithm 3 (SHA-3)

The third generation of SHA digest algorithms, including SHA3-256, SHA3-384, and SHA3-512, which generate fixed-length digests of 32, 48, and 64 bytes, respectively.

### SM2

A public-key cryptography algorithm based on elliptic curves (over the Fp field), used for asymmetric encryption/decryption and signature generation and verification. The encryption result consists of three parts: `C1` (an elliptic curve point), `C2` (the ciphertext), and `C3` (a digest value). Signatures support only the SM3 digest.

### SM3

A message digest algorithm that generates a fixed-length 32-byte (256-bit) digest. It is the default and only digest algorithm supported by SM2 signatures.

### SM4

A block cipher algorithm with a block length of 128 bits and a key length of 128 bits. Both encryption and key expansion use a 32-round nonlinear iterative structure. Decryption and encryption share the same algorithm structure, differing only in the reverse order of round key usage.

### Stream Cipher

A symmetric algorithm that encrypts data in a stream manner. The ciphertext length equals the plaintext length, and no padding is required. ChaCha20 and RC4 are both stream ciphers.

### Symmetric Key

A key system in which both the encryption and decryption parties use the same key to encrypt and decrypt data. That is, the sender uses a key and an algorithm to encrypt plaintext into ciphertext, and the receiver uses the same key and the inverse operation of the same algorithm to decrypt and restore the plaintext.

## T

### Triple Data Encryption Algorithm (3DES)

Also known as 3DESede or TripleDES, it uses three 64-bit keys to encrypt-decrypt-encrypt data (equivalent to performing DES three times on each data block). It has a longer key length and higher security than DES, but lower processing speed. An insecure algorithm; its use is not recommended.

## X

### X25519

A Diffie-Hellman key exchange algorithm based on Curve25519, used for key agreement, with a key length of 256 bits.

### X963KDF

A key derivation function based on the X9.63 standard, typically used with elliptic curves to derive a key of a specified length from raw key material and shared information.