# Device Certificate Kit Glossary

<!--Kit: Device Certificate Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3; @chaceli-->
<!--Designer: @lanming; @chande-->
<!--Tester: @PAFT; @zhangzhi1995-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=ea89afb9ae1513bcb89f85eac0b35098803eb4b4 translatedAt=2026-08-11T02:01:49.269Z pushedAt=2026-08-11T07:55:43.445Z -->

## C

### CA Certificate

A digital certificate that can issue subordinate CA certificates or physical certificates. CA certificates are managed and operated by a CA.

### Certificate Chain

Also known as a certificate path, a certificate chain is an ordered list of certificates consisting of a root CA certificate (a self-signed certificate with no superior CA certificate), multiple intermediate CA certificates, and a physical certificate.

### Certificate Credential

Contains the certificate chain and the private key corresponding to the physical certificate.

### Certificate File

A file used to store digital certificates and certificate chains. Common certificate file formats include der, pem, crt, and p7b.

### CertUri

An identifier used to uniquely identify an installed CA certificate in the certificate management service.

## D

### Digital Certificate

Abbreviated as certificate. A digital certificate that is digitally signed by a certificate authority (CA) and contains the public key owner information and the public key. Device Certificate Kit currently supports only digital certificates that comply with the X.509 standard.

## E

### Entity Certificate

Also known as an end-entity certificate or leaf certificate, it is a digital certificate used by business entities (websites, servers, devices, and individuals). A physical certificate cannot issue subordinate certificates and is primarily used for identity authentication and encrypted communication in actual services.

## K

### KeyStore

A container for storing certificate credentials, which can include certificate chains, private keys, CA certificates, and more. The common KeyStore file format is the P12 file (PKCS #12), and the KeyStore file can be encrypted and protected with a password.

### KeyUri

A URI used to uniquely identify an installed certificate credential in the certificate manager.

## S

### Signature

The ciphertext obtained by computing a digest of the data to be transmitted using a private key and then encrypting it.

### Signature Verification

The process of decrypting the signature ciphertext with the public key to obtain the digest of the text, then computing the digest of the text using the same method as the sender, and comparing it with the decrypted digest. If the two match, the text has not been tampered with.