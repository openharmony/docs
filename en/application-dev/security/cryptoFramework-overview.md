# Crypto Framework Overview
The crypto framework shields the implementation differences of third-party cryptographic algorithm libraries and implements encryption and decryption, signing and signature verification, message authentication code (MAC), hash, and secure random number. You can use the APIs provided by this framework to implement cipher development quickly.
## Working Principles
The crypto framework provides components in the following layers: 

- Interface layer: provides unified JS interface externally.
- Plugin layer: implements third-party algorithm libraries.
- Framework layer: flexibly loads the plugins in the plugin layer to adapt to third-party algorithm libraries and shields the implement differences between the third-party algorithm libraries.

## Basic Concepts
### Symmetric Key

A symmetric key is a key used both to encrypt and decrypt data. In symmetric encryption, the sender converts information in plaintext into ciphertext using a key and certain algorithm for security purposes. The receiver converts the ciphertext into plaintext using the same key and algorithm.

- AES

  Advanced Encryption Standard (AES) is the most common symmetric encryption algorithm. AES is a block cipher. A block cipher divides plaintext into fixed-length groups of bits, called blocks. A block is encrypted each time until the entire plaintext is encrypted. The block size in AES is 128 bits. That is, each block contains 16 bytes (8 bits/byte). The key length can be 128 bits, 192 bits, or 256 bits.
- 3DES
  
  Triple Data Encryption Standard (3DES), also called 3DESede or Triple DES, applies the DES cipher three times to each data block. It uses three 64-bit keys to encrypt a data block three times. Compared with DES, 3DES provides higher security due to longer key length, but its processing speed is lower. The AES is faster and more secure than 3DES.

### Asymmetric Key

In the asymmetric cryptography, a private and public key pair is required. The private key is used to encrypt the plaintext, and the public key is used to decrypt the ciphertext. The public key is public and open to anyone in the system, while the private key is private. For signing and signature verification, the private key is used to sign the plaintext, and the public key is used to verify the signature data.

- RSA key

  The security of RSA relies on the factoring problem, that is, the difficulty of factoring the product of two large prime numbers. The keys for the RSA algorithm are generated as follows:

  1. Generate two large prime numbers **p** and **q**.
  
  2. Compute **n** = **p** x **q**. 
  
     **n** is used as the modulus for both the public and private keys, and is released as part of the public key. 
  
  3. Choose an integer **e** such that 1 < **e** < (**p** - 1) x (**q** - 1), that is, **e** and (**p** - 1) x (**q** - 1) are coprime. 
  
  4. Compute **d**. 
  
     **e** x **d** - 1 is a multiple of (**p** - 1) and (**q** - 1). 
  
  The public key consists of the modulus **n** and the public exponent **e**. The private key consists of **n** and the private exponent **d**.
  
  In addition to the default RSA key generation from two primes, the crypto framework provides key generation from multiple primes. You can set the **primes** parameter (PRIMES_2, PRIMES_3, PRIMES_4, PRIMES_5) to specify the number of primes during key generation. The keys generated from multiple primes help reduce the computation workload in decryption and signing (Chinese remainder theorem). However, such keys are weak. The algorithm library defines specifications based on the rules for using OpenSSL prime numbers. For details, see **Constraints**.
  
- ECC key
  
  Elliptic-Curve Cryptography (ECC) is a public-key encryption based on the algebraic structure of elliptic curve over finite fields. The crypto framework provides a variety of ECC key generation capabilities.

### Encryption and Decryption

- Symmetric AES encryption and decryption

  The algorithm library provides the following cipher modes of operation for AES: ECB, CBC, OFB, CFB, CTR, GCM, and CCM. 
	
	AES is a block cipher, with a fixed block size of 128 bits. In actual applications, the last block of plaintext may be less than 128 bits and needs to be padded. The padding options are as follows:
	
	- **NoPadding**: no padding.
	
	- **PKCS5**: pads a block cipher with a block size of 8 bytes.
	- **PKCS7**: The PKCS #7 padding scheme is the same as that of PKCS #5 padding except that PKCS #5 padding is defined for 8-byte block sizes, while PKCS #5 padding works for any block size from 1 to 255 bytes.
	
	> **NOTE**
	>
	> In ECB and CBC modes, the plaintext length is not an integer multiple of 128 bits and must be padded.
	
- Symmetric 3DES encryption and decryption

  3DES encryption and decryption apply the DES cipher three times to each data block obtain the ciphertext or plaintext.

  The algorithm library provides the following cipher modes of operation for 3DES encryption and decryption: ECB, CBC, OFB, and CFB. 

  DES is a block cipher, with a fixed block size of 64 bits. In actual applications, the last block of plaintext may be less than 64 bits and needs to be padded. The padding options are as follows:

  - **NoPadding**: no padding.
  - **PKCS5**: pads a block cipher with a block size of 8 bytes.
  - **PKCS7**: The PKCS #7 padding scheme is the same as that of PKCS #5 padding except that PKCS #5 padding is defined for 8-byte block sizes, while PKCS #5 padding works for any block size from 1 to 255 bytes.

  > **NOTE** 
  >
  > In ECB and CBC, the plaintext length is not an integer multiple of 64 bits and must be padded.

- Asymmetric RSA encryption and decryption

  After the RSA public key (n, e) and private key (n, d) are held, the RSA encryption process is as follows:
	
	Ciphertext = Plaintext ^ **e** mod **n**
	
	The decryption process is as follows:
	
	Plaintext = Ciphertext ^ **d** mod **n** 
	
	The algorithm library provides the following modes of operation for RSA encryption and decryption: **PKCS1**, **PKCS1_ OAEP**, and **NoPadding**. 
	
	RSA is a block cipher, with fixed-length blocks. In actual applications, diverse padding modes are used. The padding options are as follows:
	
	- **NoPadding**: No padding is required. The length of the input or output data must be the same as that of the RSA key modulus.
	
	- **PKCS1**: PKCS #1 v1.5 is the default padding mode for RSA encryption and decryption. The length of the input data must be less than or equal to the RSA key modulus minus 11, and the length of the output data must be the same as that of the RSA key modulus.
	
	- **PKCS1_OAEP**: The RSA_PKCS1_OAEP_PADDING is a new padding mode provided by PKCS #1. In this mode, two digests (**md** and **mgf1_md**) must be set. The length of the input data must be less than RSA key modulus length minus **md** length, **mgf1_md** length, and two. The length of the output data must be the same as that of the RSA key modulus.
	
	  **NOTE**
	
	  Length of the RSA key modulus = (Number of RSA bits + 7)/8  

### Signing and Signature Verification

- RSA signing and signature verification

	After the RSA public key (n, e) and private key (n, d) are held, the RSA signature is generated as follows:
  
  Signature = Message ^ **d** mod **n**
  
  The signature verification process is as follows:
  
  Message = Signature ^ **d** mod **n** 
  
  The sender sends the message and the signature signed by the private key. The receiver decrypts the signature using the public key to verify the signature. Generally, the message sent is longer than the RSA key modulus. Therefore, the crypto framework provides two padding modes to extract the hash value of the message digest and then sign the message. The crypto framework provides the following padding modes for signing and signature verification:
  
  - **PKCS1**: PKCS #1 v1.5 is the default padding mode for RSA encryption and decryption. When this mode is used, the digest (**md**) must be set.
  - **PSS**: The PSS mode is a padding algorithm based on the RSA algorithm. When it is used, the digest (**md**) and mask function (**mgf1_md**) are required.
  
- ECDSA

  The Elliptic Curve Digital Signature Algorithm (ECDSA) is a Digital Signature Algorithm (DSA) that uses the ECC. Compared with the ordinary Discrete Logarithm Problem (DLP) and Integer Factorization Problem (IFP), the unit bit strength of ECC is higher than that of other public-key cryptographic systems. The crypto framework provides the ECDSA that combines multiple elliptic curve and digest algorithms.

### Key Agreement

**ECDH**

Elliptic Curve Diffie-Hellman (ECDH) allows two parties to establish a shared secret over an insecure channel. The crypto framework provides a variety of ECDH capabilities based on the open-source algorithm library.

### Digest

The message digest algorithm allows a fixed-length digest to be generated from data of arbitrary size by using the hash algorithm. The message digest algorithm is used for sensitive information encryption because it is infeasible to invert or reverse the computation. The MD algorithm is also referred to as a hash algorithm or a one-way hash algorithm.
When the same digest algorithm is used, the generated digest (hash value) has the following features:

- The same message always results in the same hash value.
- The digest generated is of the fixed length no matter the length of messages. (The digest length is determined by the algorithm used).
- It is almost impossible to find two different messages with the same hash value (the probability still exists, depending on the length of the digest).

There are three types of message digest algorithms: MD, SHA, and MAC. For details, see section "**HMAC**".
MD algorithms include MD2, MD4, and MD5.
Major SHA algorithms include SHA-1, SHA-224, SHA-256, SHA-384, and SHA-512.

### HMAC

Hash-based Message Authentication Code (HMAC) is a key-based message authentication code algorithm. HMAC provides authentication using a shared secret instead of using a digital signature. The MAC generated can be used to verify both the integrity and authenticity of the message. The length of the MAC generated by HMAC is fixed.

### Random Number

Random numbers are mainly used to generate temporary session keys or keys in asymmetric encryption. Random numbers can be generated by a hardware random number generator or software-based pseudo-random number generator. In encryption and decryption, a secure random number generator must feature randomness, repeatability, and unpredictability. The random numbers generated by the Cryptography Secure Random Number Generator (CSPRNG) meet the requirements of cryptography security pseudo-randomness.

- Internal state

  A value in the random number generator memory. The same internal state produces the same sequence of the random number.

- Seed

  A number used to initialize the internal state of a pseudorandom number generator. The random number generator generates a series of random sequences based on the seeds.


## Constraints

- The crypto framework does not support concurrent operations of multiple threads.

### Key Generation Specifications

**Symmetric Key Generation Specifications**

The following parameters are supported:

|Symmetric Key Algorithm|Key Length|String for Generating a Key|
|---|---|---|
|3DES|192|3DES192|
|AES|128|AES128|
|AES|192|AES192|
|AES|256|AES256|

**Asymmetric Key Generation Specifications**
- **RSA key generation**

  The following parameters are supported:

  |Asymmetric Key Algorithm|Key Length|Number of Primes|String for Generating a Key|
  |---|---|---|---|
  |RSA|512|2|RSA512\|PRIMES_2|
  |RSA|768|2|RSA768\|PRIMES_2|
  |RSA|1024|2|RSA1024\|PRIMES_2|
  |RSA|1024|3|RSA1024\|PRIMES_3|
  |RSA|2048|2|RSA2048\|PRIMES_2|
  |RSA|2048|3|RSA2048\|PRIMES_3|
  |RSA|3072|2|RSA3072\|PRIMES_2|
  |RSA|3072|3|RSA3072\|PRIMES_3|
  |RSA|4096|2|RSA4096\|PRIMES_2|
  |RSA|4096|3|RSA4096\|PRIMES_3|
  |RSA|4096|4|RSA4096\|PRIMES_4|
  |RSA|8192|2|RSA8192\|PRIMES_2|
  |RSA|8192|3|RSA8192\|PRIMES_3|
  |RSA|8192|4|RSA8192\|PRIMES_4|
  |RSA|8192|5|RSA8192\|PRIMES_5|

  > **NOTE**
  >
  > When the RSA asymmetric key is generated, the default number of primes is 2 and the **PRIMES_2** parameter can be omitted.

- **ECC key generation**

  The following parameters are supported:

  |Asymmetric Key Algorithm|Key Length|
  |---|---|
  |ECC|ECC224|
  |ECC|ECC256|
  |ECC|ECC384|
  |ECC|ECC512|

### Encryption and Decryption Specifications

**Symmetric Encryption and Decryption**

The following symmetric encryption algorithms are supported:

|Algorithm|Block Cipher Mode|Algorithm String|
|---|---|---|
|3DES|ECB|3DES192\|ECB\|[NoPadding\|PKCS5\|PKCS7]|
|3DES|CBC|3DES192\|CBC\|[NoPadding\|PKCS5\|PKCS7]|
|3DES|OFB|3DES192\|OFB\|[NoPadding\|PKCS5\|PKCS7]|
|3DES|CFB|3DES192\|CFB\|[NoPadding\|PKCS5\|PKCS7]|
|AES|ECB|AES[128\|192\|256]\|ECB\|[NoPadding\|PKCS5\|PKCS7]|
|AES|CBC|AES[128\|192\|256]\|CBC\|[NoPadding\|PKCS5\|PKCS7]|
|AES|CTR|AES[128\|192\|256]\|CTR\|[NoPadding\|PKCS5\|PKCS7]|
|AES|OFB|AES[128\|192\|256]\|OFB\|[NoPadding\|PKCS5\|PKCS7]|
|AES|CFB|AES[128\|192\|256]\|CFB\|[NoPadding\|PKCS5\|PKCS7]|
|AES|GCM|AES[128\|192\|256]\|GCM\|[NoPadding\|PKCS5\|PKCS7]|
|AES|CCM|AES[128\|192\|256]\|CCM\|[NoPadding\|PKCS5\|PKCS7]|

> **NOTE**
>
> The options included in the square brackets ([]) are mutually exclusive.

**Asymmetric RSA Encryption and Decryption**

The following padding modes are involved in RSA encryption and decryption: **NoPadding**, **PKCS1**, and **PKCS1_OAEP**.
- When **NoPadding** is used, you can specify the following parameters:

  [RSA512|RSA768|RSA1024|RSA2048|RSA3072|RSA4096|RSA8192]|NoPadding

- When **PKCS1** is used, you can specify the following parameters:

  [RSA512|RSA768|RSA1024|RSA2048|RSA3072|RSA4096|RSA8192]|PKCS1

- When **PKCS1_OAEP** is used, you can specify the following parameters:

  [RSA512|RSA768|RSA1024|RSA2048|RSA3072|RSA4096|RSA8192]|PKCS1_OAEP|[MD5|SHA1|SHA224|SHA256|SHA384|SHA512]|[MGF1_MD5|MGF1_SHA1|MGF1_SHA224|MGF1_SHA256|MGF1_SHA384|MGF1_SHA512]

> **NOTE**
>
> The options included in the square brackets ([]) are mutually exclusive. The options outside the square brackets are fixed values.

### Signing and Signature Verification Specifications

**RSA Signing and Signature Verification**

The following padding modes are involved in RSA encryption and decryption: **PKCS1** and **PSS**.
- When **PKCS1** is used, you can specify the following parameters:

  [RSA512|RSA768|RSA1024|RSA2048|RSA3072|RSA4096|RSA8192]|PKCS1|[MD5|SHA1|SHA224|SHA256|SHA384|SHA512]

- When **PSS** is used, you can specify the following parameters:

  [RSA512|RSA768|RSA1024|RSA2048|RSA3072|RSA4096|RSA8192]|PSS|[MD5|SHA1|SHA224|SHA256|SHA384|SHA512]|[MGF1_MD5|MGF1_SHA1|MGF1_SHA224|MGF1_SHA256|MGF1_SHA384|MGF1_SHA512]
> **NOTE**
>
> The options included in the square brackets ([]) are mutually exclusive. The options outside the square brackets are fixed values.

**ECDSA Signing and Signature Verification**

The following ECDSA parameters are supported:

|Asymmetric Key Algorithm|Supported Types|
|---|---|
|ECC|ECC224|
|ECC|ECC256|
|ECC|ECC384|
|ECC|ECC512|

|Digest Algorithm|Supported Types|
|---|---|
|HASH|SHA-1|
|HASH|SHA-224|
|HASH|SHA-256|
|HASH|SHA-384|
|HASH|SHA-512|

### Key Agreement Specifications

**ECDH**

  The following ECDH parameters are supported:

|Asymmetric Key Algorithm|Supported Types|
|---|---|
|ECC|ECC224|
|ECC|ECC256|
|ECC|ECC384|
|ECC|ECC512|

### MD Algorithm Specifications
The crypto framework supports only MD5.

### SHA Algorithm Specifications
The crypto framework supports only SHA-1, SHA-224, SHA-256, SHA-384, and SHA-512.
