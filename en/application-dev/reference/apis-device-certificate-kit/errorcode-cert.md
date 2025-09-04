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

Memory error.

**Possible Causes**

The memory allocation failed.

**Solution**

1. Check whether the system is running properly.
2. Check whether the service data is too long. 

## 19020002 Runtime Error

**Error Message**

Runtime error.

**Possible Causes**

An unexpected error occurs.

**Solution**

Check whether the system is running properly.

## 19020003 Parameter Check Failure

**Error Message**

Indicates that parameter check failed.

**Possible Causes**

The input value is out of range.

**Solution**

Check whether the input parameters are correct.

## 19030001 Crypto Operation Error

**Error Message**

Crypto operation error.

**Possible Causes**

An error occurs when the cryptography framework interacts with a third-party algorithm library.

**Solution**

1. Check whether the input parameters are correct.
2. Check whether the third-party algorithm library functions properly.

## 19030002 Certificate Signature Verification Failed

**Error Message**

The certificate signature verification failed.

**Possible Causes**

Incorrect certificate signature information is found during the signature verification.

**Solution**

Check whether the certificate is correct.

## 19030003 Certificate Has Not Taken Effect

**Error Message**

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

**Possible Causes**

The certificate has expired. The certificate expiration time is earlier than the current system time or the time specified by the service.

**Solution**

1. Check whether the certificate is correct.
2. Check whether the system time is correct.
3. Compare the certificate expiration time with the current system time to determine whether the certificate has expired.

## 19030005 Failed to Obtain the Certificate Issuer

**Error Message**

Failed to obtain the certificate issuer.

**Possible Causes**

The certificate issuer cannot be obtained during certificate verification.

**Solution**

Check whether the certificate is correct.

## 19030006 Key Cannot be Used for Signing a Certificate

**Error Message**

The key cannot be used for signing a certificate.

**Possible Causes**

The key cannot be used to sign certificates.

**Solution**

Check whether the certificate is correct.

## 19030007 Key Cannot be Used for Digital Signature

**Error Message**

The key cannot be used for digital signature.

**Possible Causes**

The key cannot be used for digital signature.

**Solution**

Check whether the certificate is correct.

## 19030008 Incorrect Private Key Password

**Error Message**

The password may be wrong.

**Possible Causes**

The password for the private key is incorrect.

**Solution**

Check that the private key password is correct.
