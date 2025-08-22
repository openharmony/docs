# MAC Overview and Algorithm Specifications

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

A message authentication code (MAC) is used to check the authenticity and integrity of a message transmitted between two parties that share a secret key.

This topic describes the key agreement algorithms and specifications supported by the system.

## HMAC
A hash-based message authentication code (HMAC) is a type of MAC involving a hash function and a secret key.

A HMAC uses a specified digest algorithm to generate a MAC based on the key and message shared by communicating parties. The MAC is used to check the integrity of transmitted packets. The HMAC adds key input on the basis of the message digest algorithm to ensure information correctness. The length of the generated MAC is fixed.

The **Supported Type** column in the following table lists the algorithm to be used when a **MAC** instance is created.

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

A block cipher (such as AES) and a key are used to generate a MAC, which verifies that a message has not been alerted during transmission.

| Encryption Algorithm| API Version| 
| -------- | -------- |
| AES128 | 16+ |
| AES256 | 16+ |
