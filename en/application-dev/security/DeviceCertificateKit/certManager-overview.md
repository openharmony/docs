# Certificate Management Overview

The **certManager** module provides system-level certificate management capabilities to implement management and secure use of certificates throughout their lifecycle (installation, storage, use, and destruction).

## Basic Concepts

- Certificate: a file that is signed by a Certificate Authority (CA) and contains the public key owner information and public key. X.509 is a common certificate format.
- Credential: private key corresponding to the public key in a certificate.
- Keystore file: a file that contains the certificate and credential. PKCS#12 (.p12) is a common keystore file format.
- Signature: ciphertext obtained by encrypting the message digest using the private key of an asymmetric key pair.
- Signature verification: a process involving decrypting the signature using the signer's public key, generating a hash from the data received, and comparing the generated hash with the original hash. If the two hashes match, the signature is valid, which means the signed data has not been changed.

### Certificate Lifecycle Management

You can use the APIs provided by the **certManager** module to implement lifecycle management of service certificates and CA certificates. The certificate lifecycle management involves the following:

- Certificate installation: You can use **install()** to pass in a certificate.
- Certificate storage: The **certManager** module stores the installed certificate in a directory of the certificate manager service. The private key credential corresponding to the certificate is stored in the HUKS module.
- Certificate usage: You can obtain a certificate file and perform service-related operations, and use the APIs provided by **certManager** module to implement signing and signature verification with the certificate and private key.
- Certificate destruction: You can use APIs to destroy one or more certificates or credentials stored in the directory of the certificate manager service.

## Constraints
  
Currently, only service certificates can be used, and only the private credentials using the RSA or ECC algorithm can be installed and used.
