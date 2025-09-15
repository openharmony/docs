# Network Security Error Codes

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 2305001 Unspecified Error

**Error Message**

Unspecified error.

**Description**

This error code is reported if an unspecified error occurs.

**Solution**

Check the input parameters, captured exceptions, and debug and log information.

## 2305002 Failed to Obtain the Issuer Certificate

**Error Message**

Unable to get issuer certificate.

**Description**

This error code is reported if the attempt to obtain the issuer certificate fails.

**Possible Cause**

The certificate chain is incomplete or an incorrect certificate is configured on the server.

**Solution**

Check whether the SSL/TLS connection is correctly set with a certificate path and certificate chain and whether the certificate verification is successful.

## 2305003 Failed to Obtain the Certificate Revocation List

**Error Message**

Unable to get certificate revocation list (CRL).

**Description**

This error code is reported if the attempt to obtain the CRL fails.

**Possible Cause**

The network is faulty, the CRL server is incorrectly configured, or the CA service is unavailable.

**Solution**

Check the network, ensure that the CRL server URI is correct, update the CRL file, or use the Online Certificate Status Protocol (OCSP) to check the certificate status.

## 2305004 Failed to Decrypt the Certificate Signature

**Error Message**

Unable to decrypt certificate signature.

**Description**

This error code is reported if the attempt to decrypt the certificate signature fails.

**Possible Cause**

The private key is missing or incorrect.

**Solution**

Check that the client has a correct private key, the private key matches the public key of the certificate, and the private key format is correct.

## 2305005 Failed to Decrypt the CRL Signature

**Error Message**

Unable to decrypt CRL signature.

**Description**

This error code is reported if the attempt to decrypt the CRL signature fails.

**Possible Cause**

The CRL encryption algorithm is not supported by the client, or the key used to encrypt the CRL signature cannot be identified by the client.

**Solution**

Check that the client has a correct private key, the private key matches the public key of the CRL, and the private key format is correct.

## 2305006 Failed to Decode the Issuer Public Key

**Error Message**

Unable to decode issuer public key.

**Description**

This error code is reported if the attempt to decode the public key fails.

**Possible Cause**

The certificate format is incorrect, or the public key data is damaged.

**Solution**

Check the certificate format and public key data, and regenerate the certificate.

## 2305007 Failed to Sign the Certificate

**Error Message**

Certificate signature failure.

**Description**

This error code is reported if the attempt to sign the certificate fails.

**Possible Cause**

The certificate signature is incorrectly calculated, or the digital signature algorithm used by the certificate is not supported by the client.

**Solution**

1. Check that the signature algorithm used by the certificate is supported by the client, the signature key of the certificate matches the public key, and the signature data is correct.
2. Regenerate or update the certificate.

## 2305008 Failed to Sign the CRL

**Error Message**

CRL signature failure.

**Description**

This error code is reported if the attempt to sign the CRL fails.

**Possible Cause**

The CRL signature is incorrectly calculated, or the digital signature algorithm used by the CRL is not supported by the client.

**Solution**

Check that the signature algorithm and signature key of the CRL are correct. Alternatively, regenerate or update the CRL.

## 2305009 Invalid Certificate

**Error Message**

Certificate is not yet valid.

**Description**

This error code is reported if the certificate has not taken effect.

**Possible Cause**

The start date of the certificate is later than the current date.

**Solution**

Check the start date and end date of the certificate, and update or regenerate the certificate.

## 2305010 Certificate Expired

**Error Message**

Certificate has expired.

**Description**

This error code is reported if the certificate has expired.

**Possible Cause**

The end date of the certificate is earlier than the current date.

**Solution**

Check the start date and end date of the certificate, and update or regenerate the certificate.

## 2305011 Invalid CRL

**Error Message**

CRL is not yet valid.

**Description**

This error code is reported if the CRL has not taken effect.

**Possible Cause**

The start date of the CRL is later than the current date.

**Solution**

1. Check that the validity period of the CRL is between the specified start date and end date.
2. Alternatively, regenerate or update the CRL.

## 2305012 CRL Expired

**Error Message**

CRL has expired.

**Description**

This error code is reported if the CRL has expired.

**Possible Cause**

The end date of the CRL is earlier than the current date.

**Solution**

Update the CRL using OCSP to obtain the latest CRL file.

## 2305018 Self-signed Certificate

**Error Message**

Self-signed certificate.

**Description**

This error code is reported if a self-signed certificate is used.

**Possible Cause**

The certificate signature is obtained through the public key of the certificate itself and is not issued by a trusted CA.

**Solution**

Check the certificate source, and add the self-signed certificate as a trusted CA.

## 2305020 Failed to Obtain the Local Issuer Certificate

**Error Message**

Unable to get local issuer certificate.

**Description**

This error code is reported if the attempt to obtain the local issuer certificate fails.

**Possible Cause**

The certificate storage on the client is not one issued by a trusted CA.

**Solution**

1. Check that the client has a correct CA certificate.
2. Update the certificate.
3. Check the network connection.
4. Reconfigure the client.

## 2305023 Certificate Revoked

**Error Message**

Certificate has been revoked.

**Description**

This error code is reported if certificate has been revoked.

**Possible Cause**

The certificate has expired or has been revoked, or the certificate chain is incomplete.

**Solution**

Check whether the certificate has been revoked. If yes, use an available certificate.

## 2305024 Invalid CA

**Error Message**

Invalid certificate authority (CA).

**Description**

This error code is reported if the CA is invalid.

**Possible Cause**

The CA certificate has expired or has been revoked, or the certificate is not issued by a trusted CA.

**Solution**

Check that the certificate is available and issued by a trusted CA. If not, replace it with one issued by a trusted CA.

## 2305027 Untrusted Certificate

**Error Message**

Certificate is untrusted.

**Description**

This error code is reported if the certificate is untrusted.

**Possible Cause**

The certificate is issued by an untrusted CA or the certificate has been revoked.

**Solution**

1. Ensure that the certificate is issued by a trusted CA. If the certificate is issued by an untrusted CA, replace it with one issued by a trusted CA.
2. Ensure that the signature key of the certificate matches the expected key of the client.
3. If the certificate has been revoked, apply for a new certificate issued by a trusted CA.

## 2305069 Invalid Certificate Verification Context

**Error Message**

Invalid certificate verification context.

**Description**

This error code is reported if the certificate verification context is invalid.

**Possible Cause**

An intermediate certificate is missing in the certificate chain, the public key of the certificate does not match the private key, the signature verification of the certificate fails, or the host name does not match the certificate.

**Solution**

Check the certificate chain to make sure that all certificates and signatures are correct.
