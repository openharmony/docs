# net_ssl_c_type.h

## Overview

Defines data structures for the C APIs of the SSL/TLS certificate chain verification module.

**File to include**: <network/netstack/net_ssl/net_ssl_c_type.h>

**Library**: libnet_ssl.so

**System capability**: SystemCapability.Communication.NetStack

**Since**: 11

**Related module**: [netstack](capi-netstack.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [NetStack_CertBlob](capi-netstack-netstack-certblob.md) | - | Certificate data structure.|
| [NetStack_CertificatePinning](capi-netstack-netstack-certificatepinning.md) | NetStack_CertificatePinning | Defines certificate pinning information.|
| [NetStack_Certificates](capi-netstack-netstack-certificates.md) | NetStack_Certificates | Define certificate information.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [NetStack_CertType](#netstack_certtype) | - | Certificate type enums.|
| [NetStack_CertificatePinningKind](#netstack_certificatepinningkind) | NetStack_CertificatePinningKind | Certificate pinning type enums.|
| [NetStack_HashAlgorithm](#netstack_hashalgorithm) | NetStack_HashAlgorithm | Hash algorithm enums.|


## Enum Description

### NetStack_CertType

```
enum NetStack_CertType
```

**Description**

Certificate type enums.

**Since**: 11

| Enum Item| Description|
| -- | -- |
| NETSTACK_CERT_TYPE_PEM = 0 | PEM certificate.|
| NETSTACK_CERT_TYPE_DER = 1 | DER certificate.|
| NETSTACK_CERT_TYPE_INVALID | Invalid certificate.|

### NetStack_CertificatePinningKind

```
enum NetStack_CertificatePinningKind
```

**Description**

Certificate pinning type enums.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| PUBLIC_KEY | Public key lock type.|

### NetStack_HashAlgorithm

```
enum NetStack_HashAlgorithm
```

**Description**

Hash algorithm enums.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| SHA_256 | Sha256 |
