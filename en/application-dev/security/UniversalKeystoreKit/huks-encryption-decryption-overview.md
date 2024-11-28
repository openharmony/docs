# Encryption and Decryption Overview and Algorithm Specifications

You can use the keys in HUKS to encrypt or decrypt data.

## Supported Algorithms

The following table lists the supported specifications for key encryption and decryption.
<!--Del-->
The key management service specifications include mandatory specifications and optional specifications. Mandatory specifications are algorithm specifications that must be supported. Optional specifications can be used based on actual situation. Before using the optional specifications, refer to the documents provided by the vendor to ensure that the specifications are supported.

**You are advised to use mandatory specifications in your development for compatibility purposes.**
<!--DelEnd-->
**Specifications for Standard-System Devices**
| Algorithm/Cipher Mode/Padding Mode| Description| API Version| <!--DelCol4-->Mandatory|
| -------- | -------- | -------- | -------- |
| <!--DelRow-->AES/ECB/NoPadding<br>AES/ECB/PKCS7 | - | 8+ | No|
| AES/CBC/NoPadding<br>AES/CBC/PKCS7<br>AES/CTR/NoPadding | **IV** is mandatory.| 8+ | Yes|
| AES/GCM/NoPadding | **Nonce** is mandatory for encryption.<br>**Nonce** and **AEAD** are mandatory for decryption.| 8+ | Yes|
| RSA/ECB/NoPadding<br>RSA/ECB/PKCS1_V1_5<br>RSA/ECB/OAEP | The OAEP padding mode supports the following MD algorithms: SHA-256, SHA-384, and SHA-512.| 8+ | Yes|
| <!--DelRow-->SM4/ECB/NoPadding<br>SM4/ECB/PKCS7<br>SM4/CBC/PKCS7 | **IV** is mandatory in CBC mode and is not recommended in ECB mode.| 9+ | No|
| SM4/CTR/NoPadding<br>SM4/CBC/NoPadding<br>SM4/CFB/NoPadding | **IV** is mandatory.| 12+ | Yes|
| SM4/OFB/NoPadding | **Nonce** is mandatory.| 12+ | Yes|
| SM2/-/NoPadding | SM3 is used as the MD algorithm.| 11+ | Yes|
