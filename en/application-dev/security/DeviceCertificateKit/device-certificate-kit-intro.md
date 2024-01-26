# Introduction to Device Certificate Kit

Device Certificate Kit provides the [Certificate Framework](#certificate-framework) and [Certificate Management](#certificate-management) capabilities.

## Certificate Framework

The certificate framework provides APIs for parsing and validating digital certificates.

You can use the APIs to parse and validate a certificate, certificate extensions, and a certificate revocation list (CRL), and validate a certificate chain.

The certificate framework shields the differences between third-party algorithm libraries to make development a more enjoyable experience.

**Scenarios**

Obtain the public key from a client certificate, and use the public key to verify the signature data.

### Working Principles

The system provides the certificate framework, which shields the differences between third-party algorithm libraries. You only need to use the APIs provided by the certificate framework to implement operations on certificates.

![](figures/certificate_framework_architecture.png)

### Related Kits

During the use of certificate framework functionalities, public keys need to be generated and obtained, which depends on [Crypto Architecture Kit](../CryptoArchitectureKit/crypto-architecture-kit-intro.md).

## Certificate Management

The **certManager** module provides system-level certificate management capabilities to ensure certificate security during transmission and storage and prevent unauthorized certificate access and use.

You can use the APIs provided by this module to implement secure management and use of certificates throughout their lifecycle (installation, storage, use, and destruction). You can also install, obtain, use, and uninstall private certificates.

**Scenarios**

- Install a private certificate.
- Obtain a private certificate.
- Use a private certificate to generate a signature and verify a signature.
- Uninstall a private certificate.

### Related Kits

During the use of the certificate management functionalities, certificates need to be installed and used, which depends on [Universal Keystore Kit](../UniversalKeystoreKit/huks-overview.md).

## Constraints

Device Certificate Kit does not provide the capabilities of generating or issuing certificates or CRLs. Such capabilities are implemented by a certificate authority (CA) rather than a single application.

<!--no_check-->
