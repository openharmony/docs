# Glossary

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=9b9362f8b9e980655fa87ea58cc9f81d31fd5322 translatedAt=2026-08-13T08:23:46.794Z pushedAt=2026-08-13T10:20:24.708Z -->

## A

### Ability Privilege Level (APL)

A mechanism in the OpenHarmony system for identifying the privilege level of an app (Ability), defining the scope of system resources and APIs that the app can access.

### Abstract Syntax Notation One (ASN.1)

A standard notation defined by ISO/ITU-T for describing data structures, encoding rules, and transfer syntax.

### Authenticated Encryption with Associated Data (AEAD)

A symmetric encryption mode that verifies the integrity of associated data (such as protocol headers) while encrypting.

## C

### Cipher Block Chaining (CBC)

A block cipher mode of operation in which the previous ciphertext block is XORed with the current plaintext block before block encryption.

### Cipher-based Message Authentication Code (CMAC)

A message authentication code computed using a symmetric block cipher.

### Counter with CBC-MAC (CCM)

An authenticated encryption mode that combines `CTR` encryption with `CBC-MAC` integrity verification.

### CryptoExtensionAbility

A derived class of `ExtensionAbility` in the stage model. It provides the interface definition for driver vendors to extend external key management capabilities. By inheriting this class, you can implement external hardware key management extensions such as `UKey` and register the hardware capabilities with the HUKS framework.

### Curve25519

A high-performance elliptic curve designed by Bernstein, primarily used for key agreement.

## D

### Diffie-Hellman (DH)

A key agreement protocol based on the discrete logarithm hardness over finite fields.

### Digital Envelope

A key protection mechanism that combines symmetric keys with asymmetric encryption: a symmetric key is used to encrypt the service key, and then the recipient's asymmetric public key is used to encrypt the symmetric key to form an "envelope".

### Digital Signature Algorithm (DSA)

An asymmetric signature algorithm based on the discrete logarithm hardness over finite fields.

## E

### Edwards-curve Digital Signature Algorithm 25519 (ED25519)

An efficient digital signature algorithm based on the Edwards curve Curve25519.

### Elliptic Curve Cryptography (ECC)

An asymmetric cryptography system based on the discrete logarithm hardness of elliptic curves.

### Elliptic Curve Diffie-Hellman (ECDH)

A Diffie-Hellman key agreement protocol implemented over an elliptic curve group.

### ExtensionAbility

A component extension mechanism provided in the stage model, which allows an app to dynamically extend its capabilities without modifying the main component. CryptoExtensionAbility is a derived form of ExtensionAbility in the HUKS external key management scenario.

## F

### Federal Information Processing Standard Publication 203 (FIPS 203)

The key encapsulation standard released by NIST in 2024, which corresponds to the ML‑KEM algorithm.

### Finite Field Diffie-Hellman Ephemeral (FFDHE)

A set of safe prime groups standardized by the IETF in RFC 7919.

## G

### Galois/Counter Mode (GCM)

An authenticated encryption mode that combines Galois field authentication with CTR encryption.

### GMT 0016-2023 Smart Token Password Application Interface Specification

An interface standard for UKey devices published by the State Cryptography Administration of China.

## H

### Hash-based Message Authentication Code (HMAC)

A message authentication code algorithm that combines a hash function with a shared key.

### HMAC-based Key Derivation Function (HKDF)

A key derivation function defined in RFC 5869 that uses HMAC as the pseudorandom function.

## K

### Key Derivation Function (KDF)

A cryptographic primitive that derives one or more keys from a secret value using a pseudorandom function.

## M

### Module-Lattice-Based Digital Signature Algorithm (ML-DSA)

A post-quantum signature algorithm defined by the NIST FIPS 204 standard.

### Module-Lattice-Based Key-Encapsulation Mechanism (ML-KEM)

A post-quantum key encapsulation algorithm defined by the NIST FIPS 203 standard.

## N

### Number Used Once (NONCE)

A random value used only once to ensure the uniqueness of encryption or authentication results and prevent replay attacks.

## O

### Optimal Asymmetric Encryption Padding (OAEP)

An RSA encryption padding scheme proposed by Bellare and Rogaway that resists chosen-ciphertext attacks.

## P

### Password-Based Key Derivation Function 2 (PBKDF2)

A password-based key derivation function defined by the PKCS #5 standard.

### Personal Identification Number (PIN)

A numeric password used by a user to unlock a hardware device.

### Probabilistic Signature Scheme (PSS)

An RSA signature padding scheme defined in PKCS #1 v2.1 that uses a random salt to increase signature randomness.

### Provider

The registration entity in the HUKS external key management extension mechanism. When a third-party driver HAP detects external hardware such as a UKey, it calls the Provider registration API to register the extension capability with the HUKS framework, so that HUKS can forward operations to the corresponding hardware when you call key APIs.

### Public-Key Cryptography Standards #1 Version 1.5 (PKCS #1 v1.5)

A padding scheme for RSA encryption and signing defined by RSA Laboratories in its early days.

### Public-Key Cryptography Standards #7 (PKCS #7)

A data encapsulation and signature standard defined by RSA Laboratories.

## R

### Rivest-Shamir-Adleman (RSA)

An asymmetric cryptographic algorithm based on the hardness of factoring large integers.

## S

### Secure Hash Algorithm (SHA)

A family of cryptographic hash functions published by NIST.

### Secure Key Facility (SKF)

The set of function interfaces for UKey devices defined in the GMT 0016-2023 standard.

### SM2

An asymmetric cryptographic algorithm based on elliptic curves, released by the State Cryptography Administration of China, with a key length of 256 bits.

### SM3

A cryptographic hash algorithm released by the State Cryptography Administration of China, with an output length of 256 bits.

### SM4

A symmetric block cipher algorithm released by the State Cryptography Administration of China, with a key length of 128 bits and a block length of 128 bits.

## T

### Trusted Application (TA)

Trusted security software running inside the TEE that accesses device keys and sensitive data through the TEE isolation mechanism. On each startup, the HUKS TA re-derives the ATKEY from the device security root key, and its interaction with UserIAM also takes place entirely within the TEE environment.

### Trusted Execution Environment (TEE)

A secure area within the main processor of a mobile device, hardware‑isolated from the Rich Execution Environment (REE). The HUKS core layer must run inside the TEE to ensure that plaintext keys are accessed and processed only within the TEE and are never leaked to the REE. For devices that provide a secure environment, OEMs are required to complete the necessary adaptation.

## U

### Universal Keystore Kit (HUKS)

A key management service subsystem provided by OpenHarmony. It provides unified secure operations for the entire key lifecycle for services and apps, covering key generation, import, deletion, and attestation; encryption and decryption; signing and signature verification; key agreement, derivation, and wrapping; and access control.

### USB Key (UKey)

A hardware security device based on the USB interface that can store user private keys, certificates, and identity authentication information. The HUKS external key management extension uses UKey to meet the requirements of high-security scenarios such as mutual SSL authentication in browsers and signing and signature verification in finance and other fields.

### User Identity Authentication Manager (UserIAM)

A subsystem in OpenHarmony responsible for user identity authentication, such as face, fingerprint, and PIN.

## X

### X.25519

A key agreement algorithm based on the Curve25519 curve, with a key length of 256 bits.

### X.509

A public-key certificate format standard defined by ITU-T.