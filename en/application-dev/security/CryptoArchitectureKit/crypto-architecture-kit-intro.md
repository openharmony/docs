# Introduction to Crypto Architecture Kit

Crypto Architecture Kit provides cryptographic functionalities, such as encryption and decryption, signing and signature verification, message authentication code (MAC) generation, hash computation, random number generation, and key derivation.

Crypto Architecture Kit shields the implementation differences of third-party cryptographic algorithm libraries to elevate your app experience.

## Constraints

- Crypto Architecture Kit does not support multi-thread concurrent operations.

- Currently, Crypto Architecture Kit supports only OpenSSL.

- Crypto Architecture Kit provides common algorithms. Some algorithms and specifications, such as MD5, do not apply to security-critical scenarios. Use appropriate algorithms based on service requirements.

## Capability Scope

Crypto Architecture Kit provides the following functionalities, with algorithm specifications and development guides for your reference.

- [Key Generation and Conversion](crypto-key-generation-conversion-overview.md)

- [Encryption and Decryption](crypto-encryption-decryption-overview.md)

- [Signing and Signature Verification](crypto-sign-sig-verify-overview.md)

- [Key Agreement](crypto-key-agreement-overview.md)

- [MD](crypto-generate-message-digest-overview.md)

- [MAC](crypto-compute-mac-overview.md)

- [Random Number Generation](crypto-generate-random-number.md)

- [Key Derivation](crypto-key-derivation-overview.md)

## Basic Concepts

Before you get started, be sure to understand the following concepts:

- Symmetric key
  
  A symmetric key is a key used both to encrypt and decrypt data. In symmetric encryption, the sender converts information in plaintext into ciphertext using a key and certain algorithm for security purposes. The receiver converts the ciphertext into plaintext using the same key and algorithm.

- Asymmetric key
  
  In the asymmetric cryptography, a private and public key pair is required. The private key is used to encrypt the plaintext, and the public key is used to decrypt the ciphertext.

  For encryption and decryption operations, the public key is used to encrypt plaintext, and the public key is used to decrypt the ciphertext.

  For signing and signature verification, the private key is used to sign the plaintext, and the public key is used to verify the signature.

## Related Kits

Crypto Architecture Kit provides cryptographic operations, but not key management. It is used when temporary session keys are used only in the memory or the applications implement secure key storage.

If key management (such as key storage) is required, use [Universal Keystore Kit](../UniversalKeystoreKit/huks-overview.md).
