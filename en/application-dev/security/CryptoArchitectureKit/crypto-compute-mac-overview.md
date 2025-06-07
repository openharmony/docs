# MAC Overview and Algorithm Specifications

A message authentication code (MAC) is used to check the authenticity and integrity of a message transmitted between two parties that share a secret key.

This topic describes the key agreement algorithms and specifications supported by the system.

## HMAC
A Hash-based Message Authentication Code (HMAC) is a type of MAC involving a hash function and a secret key.

The specified message digest (MD) algorithm is used to generate a MAC based on the shared secret key and the message to be exchanged. The MAC is used to check the integrity of message. HMAC introduces the shared secret key, which ensures data authenticity. The generated MAC has a fixed length.

The **Supported Type** column in the following table lists the algorithm to be used when a **Mac** instance is created.

| MD Algorithm| Supported Type| API Version| 
| -------- | -------- | -------- |
| HASH | SHA1 | 9+ | 
| HASH | SHA224 | 9+ | 
| HASH | SHA256 | 9+ | 
| HASH | SHA384 | 9+ | 
| HASH | SHA512 | 9+ | 
| HASH | SM3 | 10+ | 
| HASH | MD5 | 12+ | 

## CMAC

A Cipher-based Message Authentication Code (‌CMAC) is a type of cryptographic checksum used to ensure data integrity and authenticity.

A block cipher (such as AES) and a key are used to generate an authentication code, which verifies that a message has not been alerted during transmission.

| Encryption Algorithm| API Version| 
| -------- | -------- |
| AES128 | 16+ |
| AES256 | 16+ |
