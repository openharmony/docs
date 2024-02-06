# OH_Huks_CertChain


## Overview

Defines the structure of the certificate chain.

**Since:**
9

**Related Modules:**

[HuksTypeApi](_huks_type_api.md)


## Summary


### Member Variables

| Name | Description | 
| -------- | -------- |
| [certs](#certs) | Pointer to the certificate data.  | 
| [certsCount](#certscount) | Number of certificates.  | 


## Member Variable Description 


### certs

  
```
struct OH_Huks_Blob* OH_Huks_CertChain::certs
```
**Description**<br>
Pointer to the certificate data.


### certsCount

  
```
uint32_t OH_Huks_CertChain::certsCount
```
**Description**<br>
Number of certificates.
