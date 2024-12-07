# Encryption and Decryption by Segment

The Crypto framework does not have a limit on the amount of the data to be passed in one time or cumulatively during the encryption/decryption process. However, when the amount of data is greater than 2 MB, you are advised to pass in and encrypt/decrypt the data by segment to improve processing efficiency.

## Symmetric Encryption and Decryption

Use [Cipher.update](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#update-1) to pass in and encrypt/decrypt the data of a symmetric key by segment.

You can set the amount of the data to be passed in each time (**updateLength** in the example) and call **update()** multiple times to pass in the data.

Currently, the amount of data that can be passed in each time cannot exceed **INT_MAX** (maximum length of the Uint8Array type).

The value returned by each **update** and **doFinal** must be checked. If the return value is not null, obtain and combine the data segments into the complete ciphertext or plaintext.

Example: [Encryption and Decryption by Segment with an AES Symmetric Key (GCM Mode)](crypto-aes-sym-encrypt-decrypt-gcm-by-segment.md)

Example: [Encryption and Decryption by Segment with an SM4 Symmetric Key (GCM Mode)](crypto-sm4-sym-encrypt-decrypt-gcm-by-segment.md)

## Asymmetric Encryption and Decryption

Use [Cipher.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-1) and [Cipher.doFinal](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#dofinal-1) to pass in and encrypt/decrypt the data of an asymmetric key pair by segment.

If the plaintext length is greater than the data length supported by a single encryption (see [Asymmetric Key Encryption and Decryption Algorithm Specifications](crypto-asym-encrypt-decrypt-spec.md)), divide the data to be encrypted into data segments of an appropriate length and encrypt each data segment. Specifically, create a **Cipher** instance and call [Cipher.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-1) and [Cipher.doFinal](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#dofinal-1).

The amount of data to be passed in each time varies, depending on the key specifications.

- RSA: The input data varies depending on the padding mode. Determine the amount of the data to be passed in at a time based on [RSA specifications](crypto-asym-encrypt-decrypt-spec.md#rsa).
- SM2: The amount of the data to be encrypted must be of the fixed length. For details, see [SM2](crypto-asym-encrypt-decrypt-spec.md#sm2).

The value returned by each **doFinal** must be checked. If the return value is not null, obtain and combine the data segments into the complete ciphertext or plaintext.

Example: [Encryption and Decryption by Segment with an RSA Asymmetric Key Pair](crypto-rsa-asym-encrypt-decrypt-by-segment.md)

## FAQs

- Does the cipher mode affect the amount of the data to be passed in by each **update** in encryption and decryption by segment?

   You can set the amount of the data to be passed in by each **update**. It has nothing to do with the cipher mode.

   The encryption/decryption parameters vary with the cipher mode. For details, see [ParamsSpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#paramsspec).
