# OH_Huks_CertChain


## Overview

Defines the struct of a certificate chain.

**Since**: 9

**Related module**: [HuksTypeApi](_huks_type_api.md)

**Header file**: [native_huks_type.h](native__huks__type_8h.md)


## Summary


### Member Variables

| Name| Description|
| -------- | -------- |
| struct [OH_Huks_Blob](_o_h___huks___blob.md) \* [certs](#certs) | Pointer to the certificate data. |
| uint32_t [certsCount](#certscount) | Number of certificates in the certificate chain. |


## Member Variable Description


### certs

```
struct OH_Huks_Blob* OH_Huks_CertChain::certs
```
**Description**

Pointer to the certificate data.


### certsCount

```
uint32_t OH_Huks_CertChain::certsCount
```
**Description**

Number of certificates in the certificate chain.