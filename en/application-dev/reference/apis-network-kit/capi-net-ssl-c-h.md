# net_ssl_c.h

## Overview

Defines data structures for the C APIs of the SSL/TLS certificate chain verification module.

**File to include**: <network/netstack/net_ssl/net_ssl_c.h>

**Library**: libnet_ssl.so

**System capability**: SystemCapability.Communication.NetStack

**Since**: 11

**Related module**: [netstack](capi-netstack.md)

## Summary

### Functions

| Name| Description|
| -- | -- |
| [uint32_t OH_NetStack_CertVerification(const struct NetStack_CertBlob *cert, const struct NetStack_CertBlob *caCert)](#oh_netstack_certverification) | Verifies the certificate chain.|
| [int32_t OH_NetStack_GetPinSetForHostName(const char *hostname, NetStack_CertificatePinning *pin)](#oh_netstack_getpinsetforhostname) | Obtains the certificate lock information.|
| [int32_t OH_NetStack_GetCertificatesForHostName(const char *hostname, NetStack_Certificates *certs)](#oh_netstack_getcertificatesforhostname) | Obtains certificate information.|
| [void OH_Netstack_DestroyCertificatesContent(NetStack_Certificates *certs)](#oh_netstack_destroycertificatescontent) | Releases the certificate content.|
| [int32_t OH_Netstack_IsCleartextPermitted(bool *isCleartextPermitted)](#oh_netstack_iscleartextpermitted) | Boolean value indicating whether plaintext HTTP is allowed.|
| [int32_t OH_Netstack_IsCleartextPermittedByHostName(const char *hostname, bool *isCleartextPermitted)](#oh_netstack_iscleartextpermittedbyhostname) | Boolean value indicating whether host name–based plaintext HTTP is allowed.|


## Function Description

### OH_NetStack_CertVerification()

```
uint32_t OH_NetStack_CertVerification(const struct NetStack_CertBlob *cert, const struct NetStack_CertBlob *caCert)
```

**Description**

Provides certificate chain verification APIs for external systems.

**System capability**: SystemCapability.Communication.NetStack

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [const struct NetStack_CertBlob](capi-netstack-netstack-certblob.md) *cert | Certificate to be verified.|
| [const struct NetStack_CertBlob](capi-netstack-netstack-certblob.md) *caCert |   Certificate specified by the user. If this parameter is left blank, the preset certificate is used for verification.|

**Returns**

| Type| Description|
| -- | -- |
| uint32_t | **0**: Success.<br> **2305001**: Unknown error.<br> **2305002**: Failed to obtain the issuer certificate.<br> **2305003**: Failed to obtain the certificate revocation list (CRL).<br> **2305004**: Failed to decrypt the certificate signature.<br> **2305005**: Failed to decrypt the CRL signature.<br> **2305006**: Failed to decode the issuer public key.<br> **2305007**: Failed to sign the certificate.<br> **2305008**: Failed to sign the CRL.<br> **2305009**: Certificate not activated.<br> **2305010**: Certificate expired.<br> **2305011**: CRL not activated.<br> **2305012**: CRL expired.<br> **2305023**: Certificate revoked.<br> **2305024**: Invalid certificate authority (CA).<br> **2305027**: Untrusted certificate.|

### OH_NetStack_GetPinSetForHostName()

```
int32_t OH_NetStack_GetPinSetForHostName(const char *hostname, NetStack_CertificatePinning *pin)
```

**Description**

Obtains the certificate lock information.

**System capability**: SystemCapability.Communication.NetStack

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const char *hostname | Host name.|
| [NetStack_CertificatePinning](capi-netstack-netstack-certificatepinning.md) *pin | Defines the certificate lock information structure.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **0**: Success.<br>         **401**: Parameter error.<br>         **2305999**: Memory error.|

### OH_NetStack_GetCertificatesForHostName()

```
int32_t OH_NetStack_GetCertificatesForHostName(const char *hostname, NetStack_Certificates *certs)
```

**Description**

Obtains the certificate information.

**System capability**: SystemCapability.Communication.NetStack

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const char *hostname | Host name.|
| [NetStack_Certificates](capi-netstack-netstack-certificates.md) *certs | Defines the certificate information structure.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **0**: Success.<br>         **401**: Parameter error.<br>         **2305999**: Memory error.|

### OH_Netstack_DestroyCertificatesContent()

```
void OH_Netstack_DestroyCertificatesContent(NetStack_Certificates *certs)
```

**Description**

Releases the certificate content.

**System capability**: SystemCapability.Communication.NetStack

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [NetStack_Certificates](capi-netstack-netstack-certificates.md) *certs | Represents the certificate information.|

### OH_Netstack_IsCleartextPermitted()

```
int32_t OH_Netstack_IsCleartextPermitted(bool *isCleartextPermitted)
```

**Description**

Boolean value indicating whether plaintext HTTP is allowed.

**Required permission**: ohos.permission.INTERNET

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| bool *isCleartextPermitted | Boolean value indicating whether plaintext HTTP is allowed. The value **true** means that plaintext HTTP is allowed, and the value **false** means the opposite.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **0**: Success.<br>         **201**: Permission denied.<br>         **401**: Parameter error.|

### OH_Netstack_IsCleartextPermittedByHostName()

```
int32_t OH_Netstack_IsCleartextPermittedByHostName(const char *hostname, bool *isCleartextPermitted)
```

**Description**

Boolean value indicating whether host name–based plaintext HTTP is allowed.

**Required permission**: ohos.permission.INTERNET

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| const char *hostname | Host name.|
| bool *isCleartextPermitted | Boolean value indicating whether host name–based plaintext HTTP is allowed. The value **true** means that host name–based plaintext HTTP is allowed, and the value **false** means the opposite.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **0**: Success.<br>         **201**: Permission denied.<br>         **401**: Parameter error.|
