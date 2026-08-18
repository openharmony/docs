# Certificate Error Codes

<!--Kit: Device Certificate Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 19020001 Memory Error

**Error Message**

Memory malloc failed.

**Description**

A memory error occurs.

**Possible Causes**

The memory allocation failed.

**Solution**

1. Check whether the system is running properly.
2. Check whether the service data is too long. 

## 19020002 Runtime Error

**Error Message**

Runtime error.

**Description**

An external error occurs during running.

**Possible Causes**

An unexpected error occurs.

**Solution**

Check whether the system is running properly.

## 19020003 Parameter Check Failure

**Error Message**

Indicates that parameter check failed.

**Description**

An error occurs during parameter verification.

**Possible Causes**

The input value is out of range.

**Solution**

Check whether the input parameters are correct.

## 19030001 Crypto Operation Error

**Error Message**

Crypto operation error.

**Description**

Failed to invoke the third-party cryptographic API.

**Possible Causes**

An error occurs when the cryptography framework interacts with a third-party algorithm library.

**Solution**

1. Check whether the input parameters are correct.
2. Check whether the third-party algorithm library functions properly.

## 19030002 Certificate Signature Verification Failed

**Error Message**

The certificate signature verification failed.

**Description**

The certificate signature verification failed.

**Possible Causes**

Incorrect certificate signature information is found during the signature verification.

**Solution**

Check whether the certificate is correct.

## 19030003 Certificate Has Not Taken Effect

**Error Message**

The certificate has not taken effect.

**Description**

The certificate has not taken effect.

**Possible Causes**

The certificate has not taken effect. The effective time of the certificate is later than the current system time or the time specified by the service.

**Solution**

1. Check whether the certificate is correct.
2. Check whether the system time is correct.
3. Compare the certificate effective time with the current system time to determine whether the certificate has taken effect.

## 19030004 Certificate Expired

**Error Message**

The certificate has expired.

**Description**

The certificate has expired.

**Possible Causes**

The certificate has expired. The certificate expiration time is earlier than the current system time or the time specified by the service.

**Solution**

1. Check whether the certificate is correct.
2. Check whether the system time is correct.
3. Compare the certificate expiration time with the current system time to determine whether the certificate has expired.

## 19030005 Failed to Obtain the Certificate Issuer

**Error Message**

Failed to obtain the certificate issuer.

**Description**

Failed to obtain the certificate issuer.

**Possible Causes**

The certificate issuer cannot be obtained during certificate verification.

**Solution**

Check whether the certificate is correct.

## 19030006 Key Cannot be Used for Signing a Certificate

**Error Message**

The key cannot be used for signing a certificate.

**Description**

The key cannot be used for signing a certificate.

**Possible Causes**

The key cannot be used to sign certificates.

**Solution**

Check whether the certificate is correct.

## 19030007 Key Cannot be Used for Digital Signature

**Error Message**

The key cannot be used for digital signature.

**Description**

The key cannot be used for digital signature.

**Possible Causes**

The key cannot be used for digital signature.

**Solution**

Check whether the certificate is correct.

## 19030008 Incorrect Private Key Password

**Error Message**

The password may be wrong.

**Description**

The password for the private key is incorrect.

**Possible Causes**

The password for the private key is incorrect.

**Solution**

Check that the private key password is correct.

## 19030009 Untrusted Certificate

**Error Message**

The certificate is untrusted.

**Description**

This error code is reported if the certificate is untrusted.

**Possible Causes**

During certificate chain verification, the certificate is not a trust anchor certificate.

**Solution**

If you trust the root certificate of the certificate to be verified, add it to the trust certificate list and try again. Otherwise, do not trust the certificate to be verified.

## 19030010 Certificate Revoked

**Error Message**

The certificate has been revoked.

**Description**

This error code is reported if the certificate has been revoked.

**Possible Causes**

The certificate is in the CRL or the OCSP response indicates that the certificate has been revoked.

**Solution**

The certificate has been revoked. Do not trust the certificate. Replace the certificate with a valid one.

## 19030011 Unsupported Key Extensions

**Error Message**

Unknown critical extension.

**Description**

This error code is reported if the certificate has unsupported key extensions.

**Possible Causes**

The certificate has unidentified key extensions. All key extensions must be processed according to X.509.

**Solution**

You can ignore the error by setting ignoreErrs, and obtain the extension data through the certificate algorithm library APIs for verification.

## 19030012 Host Name Mismatch

**Error Message**

Hostname mismatch.

**Description**

This error code is reported if the hostname is not matched.

**Possible Causes**

The subject alternative name (SAN) or common name (CN) of the certificate does not contain the specified host name.

**Solution**

Check whether the hostnames parameter is correct. If it is correct, do not trust the certificate.

## 19030013 Email Address Mismatch

**Error Message**

Email address mismatch.

**Description**

This error code is reported if the email address in the certificate is not matched.

**Possible Causes**

The certificate does not contain the specified email address.

**Solution**

Check whether the emailAddresses parameter is correctly set. If it is correct, do not trust the certificate.

## 19030014 Key Usage Mismatch

**Error Message**

Key usage mismatch.

**Description**

This error code is reported if key usage is not matched in the certificate.

**Possible Causes**

The key usage extension of the certificate does not contain the specified key usage.

**Solution**

Check whether the keyUsage parameter is correct. If it is correct, do not trust the certificate.

## 19030015 CRL Not Found

**Error Message**

CRL not found.

**Description**

This error code is reported if the certificate revocation list (CRL) is not found.

**Possible Causes**

1. No CRL data is provided.
2. The certificate does not contain the CRL distribution point (CDP) extension.
3. The CRL cannot be downloaded from the CDP extension.

**Solution**

1. Check whether the CRL data is provided.
2. If online CRL download is enabled, check whether the certificate contains the CDP extension.
3. If online CRL download is enabled, check whether the Internet connection is normal and ensure normal Internet access.
4. You can set ignoreErrs to ignore the error indicating that the CRL is not found during verification of the certificate revocation status if it is allowed.

## 19030016 Invalid CRL

**Error Message**

CRL not yet valid.

**Description**

This error code is reported if the CRL has not taken effect.

**Possible Causes**

The effective time of the CRL is later than the current verification time.

**Solution**

1. You can set ignoreErrs to ignore the error if the CRL effective time is allowed to be later than the current verification time.
2. If date is not set, check whether the device time is correct.
3. If date is set, check whether the parameter is set properly.

## 19030017 CRL Expired

**Error Message**

CRL has expired.

**Description**

This error code is reported if the CRL has expired.

**Possible Causes**

The expiration time of the CRL is earlier than the current verification time.

**Solution**

1. You can set ignoreErrs to ignore the error if the CRL expiration time is allowed to be earlier than the current verification time.
2. If date is not set, check whether the device time is correct.
3. If date is set, check whether the parameter is set properly.

## 19030018 CRL Signature Verification Failure

**Error Message**

CRL signature verification failed.

**Description**

This error code is reported if the CRL signature verification fails.

**Possible Causes**

The CRL signature verification fails. The possible cause is that the signature is incorrect or the issuer certificate is not matched.

**Solution**

Check whether the CRL data is correct and whether the issuer certificate is matched.

## 19030019 CRL Issuer Not Found

**Error Message**

CRL issuer not found.

**Description**

This error code is reported if the CRL issuer certificate is not found.

**Possible Causes**

The CRL issuer certificate is not found.

**Solution**

This error may occur during partial certificate chain verification. You are advised to verify only the revocation status of the end entity certificate in this scenario. If you want to verify the revocation status of all certificates, do not to set partial certificate chain verification.

## 19030020 OCSP Response Not Found

**Error Message**

OCSP response not found.

**Description**

This error code is reported if the OCSP response cannot be found.

**Possible Causes**

1. No OCSP response data is provided.
2. The certificate does not contain the OCSP URL in the AIA extension.
3. No response can be obtained from the OCSP server.

**Solution**

1. Check whether the OCSP response data is provided.
2. If online OCSP check is enabled, check whether the certificate contains the OCSP URL.
3. If online OCSP check is enabled, check whether the Internet connection is normal and ensure normal Internet access.
4. You can set ignoreErrs to ignore the error indicating that no OCSP is found during verification of the certificate revocation status if it is allowed.

## 19030021 Invalid OCSP response.

**Error Message**

OCSP response invalid.

**Description**

The OCSP response is invalid.

**Possible Causes**

The OCSP response data is in an incorrect format, cannot be parsed, or has expired.

**Solution**

1. Check whether the OCSP response data is correct.

## 19030022 OCSP Signature Verification Failure

**Error Message**

OCSP signature verification failed.

**Description**

This error code is reported if the OCSP signature verification fails.

**Possible Causes**

The signature verification of the OCSP response fails. The possible cause is that the signature is incorrect or the signer certificate is not matched.

**Solution**

Add the signer certificate and issuer certificate of the OCSP response to the untrusted or trusted certificate list, and add the root certificate to the trusted certificate list.

## 19030023 Unknown OCSP Certificate Status

**Error Message**

OCSP certificate status unknown.

**Description**

The OCSP server returns an unknown certificate status.

**Possible Causes**

The OCSP server cannot determine the certificate status.

**Solution**

Check whether the OCSP server is working properly or verify the certificate revocation status using other methods.

## 19030024 Network Connection Timeout

**Error Message**

Network timeout.

**Description**

This error code is reported if network connection times out.

**Possible Causes**

1. Downloading the intermediate CA certificate times out.
2. CRL download times out.
3. The OCSP request times out.

**Solution**

Check the Internet connection and ensure that the related server can be accessed.
<!--no_check-->