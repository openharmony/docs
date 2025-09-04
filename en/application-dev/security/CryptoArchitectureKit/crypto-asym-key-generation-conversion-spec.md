# Asymmetric Key Generation and Conversion Specifications

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

This topic describes the supported algorithms and specifications. There are two ways to generate a key with specified specifications:

- String parameter: presents the specifications of the key to generate in the form of a string.

- Key parameter: constructs the detailed cryptographic information of the key to generate in an object.

For details, see the specifications of each algorithm.

## RSA

Rivest-Shamir-Adleman (RSA) is an asymmetric encryption algorithm widely used for secure data transmission. An RSA key can be generated based on a string parameter or key parameters.

### String Parameter

When creating an asymmetric key generator instance, you need to specify the key specifications in a string parameter. The string parameter consists of the RSA key type and prime count with a vertical bar (|) in between.

> **NOTE**
>
> When an RSA asymmetric key is generated, the default number of primes is 2 and the **PRIMES_2** parameter can be omitted.

| RSA Key Type| Prime Count| String Parameter| API Version| 
| -------- | -------- | -------- | -------- |
| RSA512 | 2 | RSA512\|PRIMES_2 | 9+ | 
| RSA768 | 2 | RSA768\|PRIMES_2 | 9+ | 
| RSA1024 | 2 | RSA1024\|PRIMES_2 | 9+ | 
| RSA1024 | 3 | RSA1024\|PRIMES_3 | 9+ | 
| RSA2048 | 2 | RSA2048\|PRIMES_2 | 9+ | 
| RSA2048 | 3 | RSA2048\|PRIMES_3 | 9+ | 
| RSA3072 | 2 | RSA3072\|PRIMES_2 | 9+ | 
| RSA3072 | 3 | RSA3072\|PRIMES_3 | 9+ | 
| RSA4096 | 2 | RSA4096\|PRIMES_2 | 9+ | 
| RSA4096 | 3 | RSA4096\|PRIMES_3 | 9+ | 
| RSA4096 | 4 | RSA4096\|PRIMES_4 | 9+ | 
| RSA8192 | 2 | RSA8192\|PRIMES_2 | 9+ | 
| RSA8192 | 3 | RSA8192\|PRIMES_3 | 9+ | 
| RSA8192 | 4 | RSA8192\|PRIMES_4 | 9+ | 
| RSA8192 | 5 | RSA8192\|PRIMES_5 | 9+ | 

> **NOTE**
>
> It takes a long time to generate RSA2048, RSA3072, RSA4096, and RSA8192 asymmetric keys using synchronous APIs.
>
> The system has a time limit on the main thread. Time-consuming threads may cause failures. You are advised to use the asynchronous API or [multi-thread concurrency capability](../../arkts-utils/multi-thread-concurrency-overview.md) when generating a large-bit key.
>
> When you create an RSA asymmetric key generator, if it is used to randomly generate keys, the specifications of the generated RSA keys match those specified at creation; if used for key conversion, the specifications of the generated RSA keys align with those specified during conversion.

### Key Parameter

Since API version 10, key parameters can be used to generate an RSA key.

The RSA key includes the following integers:

- **n**: modulus for both the private and public keys.

- **sk**: private exponent, which is often written as **d** in the formula.

- **pk**: public exponent, which is often written as **e** in the formula.

When you create an asymmetric key generator, the RSA key can be generated based on the specified public and private key parameters. For details, see the following table.

- √ indicates the property used to construct a key parameter.

- x indicates that the property that cannot be used to construct a key parameter.

|  | Common Parameter| Public Key Parameter| Private Key Parameter| Key Pair Parameter| 
| -------- | -------- | -------- | -------- | -------- |
| n | × | √ | × | √ | 
| pk | N/A | √ | N/A | √ | 
| sk | N/A | N/A | × | √ | 

According to the preceding table:

- The RSA key cannot be generated based on the common parameter (**n**).

- The RSA private key cannot be generated based on the private key parameter, which consists of **n** and **sk**.

## ECC

Elliptic-curve cryptography (ECC) is a public-key encryption algorithm based on elliptic curve mathematics.

The ECC algorithm can be regarded as an operation of numbers defined in a special set. Currently, the Crypto framework supports only elliptic curves in the **Fp** field for ECC keys, where **p** indicates a prime. The **Fp** field is also called prime field.

An ECC key can be generated based on a string parameter or key parameters, and the common parameter can be generated based on the curve name.

### String Parameter

When creating an asymmetric key generator instance, you need to specify the key specifications in a string parameter. The string parameter consists of the asymmetric key algorithm and key length.

| Asymmetric Key Algorithm| Key Length (Bit)| Curve Name| String Parameter| API Version| 
| -------- | -------- | -------- | -------- | -------- |
| ECC | 224 | NID_secp224r1 | ECC224 | 9+ | 
| ECC | 256 | NID_X9_62_prime256v1 | ECC256 | 9+ | 
| ECC | 384 | NID_secp384r1 | ECC384 | 9+ | 
| ECC | 521 | NID_secp521r1 | ECC521 | 9+ | 
| ECC | 160 | NID_brainpoolP160r1 | ECC_BrainPoolP160r1 | 11+ | 
| ECC | 160 | NID_brainpoolP160t1 | ECC_BrainPoolP160t1 | 11+ | 
| ECC | 192 | NID_brainpoolP192r1 | ECC_BrainPoolP192r1 | 11+ | 
| ECC | 192 | NID_brainpoolP192t1 | ECC_BrainPoolP192t1 | 11+ | 
| ECC | 224 | NID_brainpoolP224r1 | ECC_BrainPoolP224r1 | 11+ | 
| ECC | 224 | NID_brainpoolP224t1 | ECC_BrainPoolP224t1 | 11+ | 
| ECC | 256 | NID_brainpoolP256r1 | ECC_BrainPoolP256r1 | 11+ | 
| ECC | 256 | NID_brainpoolP256t1 | ECC_BrainPoolP256t1 | 11+ | 
| ECC | 320 | NID_brainpoolP320r1 | ECC_BrainPoolP320r1 | 11+ | 
| ECC | 320 | NID_brainpoolP320t1 | ECC_BrainPoolP320t1 | 11+ | 
| ECC | 384 | NID_brainpoolP384r1 | ECC_BrainPoolP384r1 | 11+ | 
| ECC | 384 | NID_brainpoolP384t1 | ECC_BrainPoolP384t1 | 11+ | 
| ECC | 512 | NID_brainpoolP512r1 | ECC_BrainPoolP512r1 | 11+ | 
| ECC | 512 | NID_brainpoolP512t1 | ECC_BrainPoolP512t1 | 11+ | 
| ECC | 256 | NID_secp256k1 | ECC_Secp256k1 | 14+ | 

> **NOTE**
>
> When you create an ECC asymmetric key generator, if it is used to randomly generate keys, the specifications of the generated ECC keys match those specified at creation; if used for key conversion, the specifications of the generated ECC keys align with those specified during conversion.

### Key Parameter

Since API version 10, key parameters can be used to generate an ECC key.

The ECC key in the **Fp** field includes the following properties:

- **p**: prime used to determine **Fp**.

- **a**, **b**: determine the elliptic curve equation.

- **g**: base point of the elliptic curve, which can be represented as **gx** or **gy**.

- **n**: order of the base point **g**.

- **h**: cofactor.

- **sk**: private key, which is a random integer less than **n**.

- **pk**: public key, which is a point on the elliptic curve. **pk** = **sk** x **g**.

When you create an asymmetric key generator, the ECC key can be generated based on the specified public and private key parameters. For details, see the following table.

- √ indicates the property used to construct a key parameter.

|  | Common Parameter| Public Key Parameter| Private Key Parameter| Key Pair Parameter| 
| -------- | -------- | -------- | -------- | -------- |
| fieldType | √ | √ | √ | √ | 
| p | √ | √ | √ | √ | 
| a | √ | √ | √ | √ | 
| b | √ | √ | √ | √ | 
| g | √ | √ | √ | √ | 
| n | √ | √ | √ | √ | 
| h | √ | √ | √ | √ | 
| pk | N/A | √ | N/A | √ | 
| sk | N/A | N/A | √ | √ | 

> **NOTE**
> - Currently, only the **Fp** field is supported. Therefore, **fieldType** has a fixed value of **Fp**. **fieldType** and **p** constitute **field**, which supports only [ECFieldFp](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#ecfieldfp10) currently.
> 
> - **g** and **pk** are points of the [Point](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#point10) type on the ECC curve. You need to specify their X and Y coordinates.

### Curve Name

Since API version 11, the ECC common parameter can be generated based on a curve name.

> **NOTE**
> - The curve name is a string parameter. For details about the supported curve names, see the **Curve Name** column in [ECC String Parameter](#string-parameter-1).
> 
> - The generated common parameter can be used to randomly generate public and private keys, or used to construct the public key parameter, private key parameter, or key pair parameter.

## DSA

Digital Signature Algorithm (DSA) is a public-key algorithm based on the modular exponentiation and discrete logarithm problem. It is used for digital signatures and signature verification, but not for encryption and decryption.

A DSA key can be generated based on a string parameter or key parameters.

### Constraints

It takes time to generate a DSA2048 or DSA3072 asymmetric key pair or when the plaintext length exceeds 2048 bits.

The system has a time limit on the main thread. Time-consuming threads may cause failures. You are advised to use the asynchronous API or [multi-thread concurrency capability](../../arkts-utils/multi-thread-concurrency-overview.md) when generating a large-bit key.

### String Parameter

When creating an asymmetric key generator instance, you need to specify the key specifications in a string parameter, which consists of the asymmetric key algorithm and key length.

| Asymmetric Key Algorithm| Key Length (Bit)| String Parameter| API Version| 
| -------- | -------- | -------- | -------- |
| DSA | 1024 | DSA1024 | 10+ | 
| DSA | 2048 | DSA2048 | 10+ | 
| DSA | 3072 | DSA3072 | 10+ | 

> **NOTE**
>
> It takes time to generate a DSA2048 or DSA3072 asymmetric key pair or when the plaintext length exceeds 2048 bits.
>
> The system has a time limit on the main thread. Time-consuming threads may cause failures. You are advised to use the asynchronous API or [multi-thread concurrency capability](../../arkts-utils/multi-thread-concurrency-overview.md) when generating a large-bit key.
>
> When you create a DSA asymmetric key generator, if it is used to randomly generate keys, the specifications of the generated DSA keys match those specified at creation; if used for key conversion, the specifications of the generated DSA keys align with those specified during conversion.

### Key Parameter

Since API version 10, key parameters can be used to generate a DSA key.

The DSA key includes the following properties:

- **p**: prime modulus, whose length is an integer multiple of 64.

- **q**: prime factor of **p** – 1. The length varies depending on the length of **p**.

- **g**: g = (h ^ ((p – 1)/q)) mod p, where **h** is an integer greater than 1 and less than **p** minus 1.

- **sk**: private key, which is a randomly generated integer greater than 0 and less than **q**.

- **pk**: public key. pk = (g ^ sk) mod p

When you create an asymmetric key generator, the DSA key can be generated based on the specified public and private key parameters. For details, see the following table.

- √ indicates the property used to construct a key parameter.

- x indicates that the property that cannot be used to construct a key parameter.

|  | Common Parameter| Public Key Parameter| Private Key Parameter| Key Pair Parameter| 
| -------- | -------- | -------- | -------- | -------- |
| p | √ | √ | × | √ | 
| q | √ | √ | × | √ | 
| g | √ | √ | × | √ | 
| pk | N/A | √ | N/A | √ | 
| sk | N/A | N/A | × | √ | 

> **NOTE**
> - The DSA private key cannot be generated based on the private key parameter, which consists of **p**, **q**, **g**, and **sk**.
> 
> - When the common parameter (**p**, **q**, **g**) is used to generate a DSA key pair, the DSA key length must be at least 1024 bits.

## SM2

SM2 is a public key cryptographic algorithm based on the elliptic curves in the **Fp** field.

An SM2 key can be generated based on a string parameter or key parameters, and the common parameter can be generated based on the curve name.

### String Parameter

When creating an asymmetric key generator instance, you need to specify the key specifications in a string parameter. The string parameter consists of the asymmetric key algorithm and key length with an underscore (_) in between.

| Asymmetric Key Algorithm| Key Length (Bit)| Curve Name| String Parameter| API Version| 
| -------- | -------- | -------- | -------- | -------- |
| SM2 | 256 | NID_sm2 | SM2_256 | 10+ | 

### Key Parameter

Since API version 11, key parameters can be used to generate an SM2 key.

The SM2 key in the **Fp** field includes the following properties:

- **p**: prime used to determine **Fp**.

- **a**, **b**: determine the elliptic curve equation.

- **g**: base point of the elliptic curve, which can be represented as **gx** or **gy**.

- **n**: order of the base point **g**.

- **h**: cofactor.

- **sk**: private key, which is a random integer less than **n**.

- **pk**: public key, which is a point on the elliptic curve. **pk** = **sk** x **g**.

When you create an asymmetric key generator, the SM2 key can be generated based on the specified public and private key parameters. For details, see the following table.

- √ indicates the property used to construct a key parameter.

|  | Common Parameter| Public Key Parameter| Private Key Parameter| Key Pair Parameter| 
| -------- | -------- | -------- | -------- | -------- |
| fieldType | √ | √ | √ | √ | 
| p | √ | √ | √ | √ | 
| a | √ | √ | √ | √ | 
| b | √ | √ | √ | √ | 
| g | √ | √ | √ | √ | 
| n | √ | √ | √ | √ | 
| h | √ | √ | √ | √ | 
| pk | N/A | √ | N/A | √ | 
| sk | N/A | N/A | √ | √ | 

> **NOTE**
> - Currently, only the **Fp** field is supported. Therefore, **fieldType** has a fixed value of **Fp**. **fieldType** and **p** constitute **field**, which supports only [ECFieldFp](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#ecfieldfp10) currently.
> 
> - **g** and **pk** are points of the [Point](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#point10) type on the SM2 curve. You need to specify their X and Y coordinates.

### Curve Name

Since API version 11, the SM2 public key parameter can be generated based on a curve name.

> **NOTE**
> - The curve name is a string parameter. The supported curve name is **NID_sm2**.
> 
> - The generated common parameter can be used to randomly generate public and private keys, or used to construct the public key parameter, private key parameter, or key pair parameter.

## Ed25519

The Ed25519 algorithm is a digital signature algorithm based on the EdDSA algorithm. It generates 256-bit keys using the Edwards curve. It is used for digital signature and verification, but cannot be used for encryption and decryption.

An Ed25519 key can be generated based on a string parameter or key parameters.

### String Parameter

When creating an asymmetric key generator instance, you need to specify the key specifications in a string parameter.

| Asymmetric Key Algorithm| String Parameter| API Version| 
| -------- | -------- | -------- |
| Ed25519 | Ed25519 | 11+ | 

### Key Parameter

Since API version 11, key parameters can be used to generate an Ed25519 key.

The Ed25519 key parameters include the following:

- **sk**: private key, which is a 32-byte random value.

- **pk**: public key, a 32-byte value derived from the private key.

When you create an asymmetric key generator, the Ed25519 key can be generated based on the specified public and private key parameters. For details, see the following table.

- √ indicates the property used to construct a key parameter.

|  | Public Key Parameter| Private Key Parameter| Key Pair Parameter| 
| -------- | -------- | -------- | -------- |
| pk | √ | N/A | √ | 
| sk | N/A | √ | √ | 

> **NOTE**
>
> Ed25519 does not have the common parameter.

## X25519

X25519 is a Diffie-Hellman key exchange algorithm used for key agreement.

An X25519 key can be generated based on a string parameter or key parameters.

### String Parameter

You can use a string parameter to generate X25519 keys and specify the key specifications.

| Asymmetric Key Algorithm| String Parameter| API Version| 
| -------- | -------- | -------- |
| X25519 | X25519 | 11+ | 

### Key Parameter

Since API version 11, key parameters can be used to generate an X25519 key.

The X25519 key parameters include the following:

- **sk**: private key, which is a 32-byte random value.

- **pk**: public key, a 32-byte value derived from the private key.

The following table illustrates the composition of the X25519 key parameters.

- √ indicates the property used to construct a key parameter.

|  | Public Key Parameter| Private Key Parameter| Key Pair Parameter| 
| -------- | -------- | -------- | -------- |
| pk | √ | N/A | √ | 
| sk | N/A | √ | √ | 

> **NOTE**
>
> X25519 does not have the common parameter.

## DH

Diffie–Hellman key exchange (DH) is a key agreement algorithm used to exchange the public key only. It provides forward secrecy, which protects the session keys against compromises even if the communication channel is intercepted.

A DH key can be generated based on a string parameter or key parameters, and the common parameter can be generated based on the prime length and private key length.

### String Parameter

When creating an asymmetric key generator instance, you need to specify the key specifications in a string parameter. The string parameter consists of the asymmetric key algorithm and named DH group with an underscore (_) in between.

| Asymmetric Key Algorithm| Named DH Group| Key Length (Bit)| String Parameter| API Version| 
| -------- | -------- | -------- | -------- | -------- |
| DH | modp1536 | 1536 | DH_modp1536 | 11+ | 
| DH | modp2048 | 2048 | DH_modp2048 | 11+ | 
| DH | modp3072 | 3072 | DH_modp3072 | 11+ | 
| DH | modp4096 | 4096 | DH_modp4096 | 11+ | 
| DH | modp6144 | 6144 | DH_modp6144 | 11+ | 
| DH | modp8192 | 8192 | DH_modp8192 | 11+ | 
| DH | ffdhe2048 | 2048 | DH_ffdhe2048 | 11+ | 
| DH | ffdhe3072 | 3072 | DH_ffdhe3072 | 11+ | 
| DH | ffdhe4096 | 4096 | DH_ffdhe4096 | 11+ | 
| DH | ffdhe6144 | 6144 | DH_ffdhe6144 | 11+ | 
| DH | ffdhe8192 | 8192 | DH_ffdhe8192 | 11+ | 

> **NOTE**
>
> When you create a DH asymmetric key generator, if it is used to randomly generate keys, the specifications of the generated DH keys match those specified at creation; if used for key conversion, the specifications of the generated DH keys align with those specified during conversion.

### Key Parameter

Since API version 11, key parameters can be used to generate a DH key.

The DH key includes the following properties:

- **p**: a large prime used as a modulus of a finite field. It is shared by all communicating parties.

- **g**: a primitive root modulo **p**. It is shared by all communicating parties.

- **l**: length of the private key, in bits. The value **0** means the length of the private key is not specified.

- **sk**: private key, which is a randomly generated value.

- **pk**: public key, which is calculated using the common parameter (**p** and **g**) and the private key.

The following table illustrates the composition of the DH key parameters.

- √ indicates the property used to construct a key parameter.

|  | Common Parameter| Public Key Parameter| Private Key Parameter| Key Pair Parameter| 
| -------- | -------- | -------- | -------- | -------- |
| p | √ | √ | √ | √ | 
| g | √ | √ | √ | √ | 
| l | √ | √ | √ | √ | 
| pk | N/A | √ | N/A | √ | 
| sk | N/A | N/A | √ | √ | 

### Common Parameter Generated Based on the Prime Length and Private Key Length

Since API version 11, the DH common parameter can be generated based on the prime length and private key length.

If the prime length is the same as that in the security prime number array, select the corresponding named DH group. The following shows the mapping.

| Prime Length (Bit)| Named DH Group| 
| -------- | -------- |
| 2048 | ffdhe2048 | 
| 3072 | ffdhe3072 | 
| 4096 | ffdhe4096 | 
| 6144 | ffdhe6144 | 
| 8192 | ffdhe8192 | 

- The number of bits for **p** must be greater than or equal to 512 and less than or equal to 10000.

- The parameter **l** (private key length) is optional. The default value is **0**. The value of **l** must meet the following requirements:<br>**l** > 2**(96 + (Length of p – 1)/1024* x 16)

- The generated common parameter can be used to randomly generate public and private keys, or used to construct the public key, private key, or key pair.

- Named DH groups are recommended because generating a key parameter with an unnamed DH group is time-consuming.
