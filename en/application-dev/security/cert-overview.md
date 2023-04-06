# Certificate Overview
The **Certificate** module provides APIs for X.509 certificate operations. You can use the APIs to implement quick development.

## Basic Concepts

A digital certificate provides a method of digitally verifying the identity of a user, device, or service. X.509 is an international standard format public key certificates that securely associate cryptographic key pairs with identifies such as websites, individuals, or organizations. The crypto framework provides the following capabilities:

- X.509 certificate capabilities: parsing and serializing X.509 certificates, verifying X.509 certificate signatures, and querying certificate information.
- X.509 certificate revocation list (CRL) capabilities: parsing, serializing, and querying the X.509 CRL.
- Certificate chain validator capabilities: verifying the certificate chain (excluding the certificate validity period) and querying certificate chain algorithms.

## Constraints

- Multi-thread concurrent operations are not supported.

### Certificate Specifications

- Certificate chain verification

  The certificate chain validator does not verify the certificate validity period because the system time on the device is untrusted. To check the validity period of a certificate, use **checkValidityWithDate()** of the **X509Cert** class.

- Certificate formats
  
  Currently, only the certificates in DER and PEM formats are supported.
