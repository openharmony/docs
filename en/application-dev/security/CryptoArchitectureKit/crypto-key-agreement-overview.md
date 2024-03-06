# Key Agreement Overview and Algorithm Specifications


Key agreement allows two or more parties to jointly establish a shared key in a non-secure environment.


This topic describes the key agreement algorithms and specifications supported by the system.


## ECDH

The Crypto framework provides a variety of Elliptic Curve Diffie–Hellman key exchange (ECDH) capabilities.


When creating an ECDH key agreement instance, you need to specify the algorithm specifications in a string parameter, as listed in the table below.


| Asymmetric Key Algorithm| String Parameter| API Version| 
| -------- | -------- | -------- |
| ECC | ECC224 | 9+ | 
| ECC | ECC256 | 9+ | 
| ECC | ECC384 | 9+ | 
| ECC | ECC521 | 9+ | 
| ECC | ECC_BrainPoolP160r1 | 11+ | 
| ECC | ECC_BrainPoolP160t1 | 11+ | 
| ECC | ECC_BrainPoolP192r1 | 11+ | 
| ECC | ECC_BrainPoolP192t1 | 11+ | 
| ECC | ECC_BrainPoolP224r1 | 11+ | 
| ECC | ECC_BrainPoolP224t1 | 11+ | 
| ECC | ECC_BrainPoolP256r1 | 11+ | 
| ECC | ECC_BrainPoolP256t1 | 11+ | 
| ECC | ECC_BrainPoolP320r1 | 11+ | 
| ECC | ECC_BrainPoolP320t1 | 11+ | 
| ECC | ECC_BrainPoolP384r1 | 11+ | 
| ECC | ECC_BrainPoolP384t1 | 11+ | 
| ECC | ECC_BrainPoolP512r1 | 11+ | 
| ECC | ECC_BrainPoolP512t1 | 11+ | 
| ECC | ECC | 10+ | 


As indicated by the last row in the preceding table, you can specify the ECDH key type without the key length and curve name to ensure compatibility with the key generated based on the key parameter. In this case, the key agreement operation varies depending on the actual key length.


## X25519

The Crypto framework provides X25519 key agreement capabilities.


When creating an X25519 key agreement instance, you need to specify the algorithm specifications in a string parameter, as listed in the table below.


| Asymmetric Key Algorithm| String Parameter| API Version| 
| -------- | -------- | -------- |
| X25519 | X25519 | 11+ | 


## DH

The Crypto framework provides Diffie–Hellman key exchange (DH) key agreement capabilities.


When creating a DH key agreement instance, you need to specify the algorithm specifications in a string parameter, as listed in the table below.


| Asymmetric Key Algorithm| String Parameter| API Version| 
| -------- | -------- | -------- |
| DH | DH_modp1536 | 11+ | 
| DH | DH_modp2048 | 11+ | 
| DH | DH_modp3072 | 11+ | 
| DH | DH_modp4096 | 11+ | 
| DH | DH_modp6144 | 11+ | 
| DH | DH_modp8192 | 11+ | 
| DH | DH_ffdhe2048 | 11+ | 
| DH | DH_ffdhe3072 | 11+ | 
| DH | DH_ffdhe4096 | 11+ | 
| DH | DH_ffdhe6144 | 11+ | 
| DH | DH_ffdhe8192 | 11+ | 
| DH | DH | 11+ | 


As indicated by the last row in the preceding table, you can specify the DH key type without the named DH group to ensure compatibility with the key generated based on the key parameter. In this case, the key agreement operation varies depending on the actual key length, and unnamed DH groups are also supported.
