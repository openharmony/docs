# Certificate Management Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 17500001 Internal Error

**Error Message**

Internal error.

**Possible Causes**

An internal error occurs when the API is called.

**Solution**

Check for and rectify the internal error.

## 17500002 Certificate Not Exist

**Error Message**

The certificate does not exist.

**Possible Causes**

The certificate does not exist during certificate management.

**Solution**

Check whether the certificate exists.

## 17500003 Invalid Certificate or Credential

**Error Message**

The keystore is in an invalid format or the keystore password is incorrect.

**Possible Causes**

The input certificate or credential is invalid.

**Solution**

Check that the certificate or credential is valid.

## 17500004 The Number of Certificates or Credentials Reaches the Limit

**Error Message**

The number of certificates or credentials reaches the maximum allowed.

**Possible Causes**

The number of installed certificates or credentials has reached the maximum.

**Solution**

Clear expired certificates or credentials.

## 17500005 Application Not Authorized

**Error Message**

The application is not authorized by the user.

**Possible Causes**

The user has not authorized the application to use the specified credential.

**Solution**

Check that the credential is correct, and authorize the application to use the credential.

## 17500007 Device in Advanced Security Mode

**Error Message**

The device enters advanced security mode.

**Possible Causes**

The user has enabled the advanced security mode.

**Solution**

Guide the user to disable the advanced security mode on the application UI.
