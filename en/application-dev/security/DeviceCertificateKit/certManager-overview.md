# Certificate Management Overview

<!--Kit: Device Certificate Kit-->
<!--Subsystem: Security-->
<!--Owner: @chaceli-->
<!--Designer: @chande-->
<!--Tester: @zhangzhi1995-->
<!--Adviser: @zengyawen-->

The **certManager** module provides system-level certificate management capabilities to implement management and secure use of certificates throughout their lifecycle (installation, storage, use, and destruction). In addition, it provides APIs for starting the certificate management dialog box so that you can view and manage certificates and credentials on the application UI.

## Basic Concepts

- Certificate: a file that is signed by a Certificate Authority (CA) and contains the public key owner information and public key. X.509 is a common certificate format.
- Credential: private key corresponding to the public key in a certificate.
- Keystore file: a file that contains the certificate and credential. PKCS#12 (.p12) is a common keystore file format.
- Signature: ciphertext obtained by encrypting the message digest using the private key of an asymmetric key pair.
- Signature verification: a process involving decrypting the signature using the signer's public key, generating a hash from the data received, and comparing the generated hash with the original hash. If the two hashes match, the signature is valid, which means the signed data has not been changed.

### Certificate Lifecycle Management

You can use the APIs provided by the **certManager** module to implement lifecycle management of service certificates/credentials and CA certificates. The certificate lifecycle management involves the following:

- Certificate installation: You can use **install()** to pass in a certificate.

- Certificate storage: The **certManager** module stores the installed certificate in a directory of the certificate manager service. The private key credential corresponding to the certificate is stored in the HUKS module.

- Certificate usage: You can obtain a certificate file and perform service-related operations, and use the APIs provided by **certManager** module to implement signing and signature verification with the certificate and private key.

- Certificate destruction: You can use APIs to destroy one or more certificates or credentials stored in the directory of the certificate manager service.

### Certificate Management Dialog Box

The certificate management dialog box allows you to view and manage certificates and credentials on the application UI.

- Certificate viewing: View the list and details of CA certificates and credentials.

- Certificate installation: Install user CA certificates and credentials from the storage device. For 2-in-1 devices, you can directly call the dialog box API for installing certificates to install CA certificates.

- Certificate deletion: Delete a specified user CA certificate. For 2-in-1 devices, you can directly call the dialog box API for deleting certificates to delete CA certificates.

- Certificate details: For 2-in-1 devices, you can call the dialog box API for viewing certificate details to display certificate details.

## Constraints

Currently, this module supports only the installation and use of application certificates and credentials of the RSA, ECC, and SM2 algorithms.

## Development

You can use this module to implement the following functionalities.

- [Application Certificate Development](certManager-private-credential-guidelines.md)
- [CA Certificate Development](certManager-ca-certs-guidelines.md)
- [Certificate Management Dialog Box Development](certManagerDialog-guidelines.md)
