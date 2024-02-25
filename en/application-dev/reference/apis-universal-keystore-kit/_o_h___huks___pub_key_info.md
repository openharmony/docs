# OH_Huks_PubKeyInfo


## Overview

Defines the structure of a public key.

**Since:**
9

**Related Modules:**

[HuksTypeApi](_huks_type_api.md)


## Summary


### Member Variables

| Name | Description | 
| -------- | -------- |
| [keyAlg](#keyalg) |Algorithm of the public key.  | 
| [keySize](#keysize) | Length of the public key.  | 
| [nOrXSize](#norxsize) | Length of the n or X value.  | 
| [eOrYSize](#eorysize) | Length of the e or Y value.  | 
| [placeHolder](#placeholder) | Placeholder size.  | 


## Member Variable Description 


### eOrYSize

  
```
uint32_t OH_Huks_PubKeyInfo::eOrYSize
```
**Description**<br>
Length of the e or Y value.


### keyAlg

  
```
enum OH_Huks_KeyAlg OH_Huks_PubKeyInfo::keyAlg
```
**Description**<br>
Algorithm of the public key.


### keySize

  
```
uint32_t OH_Huks_PubKeyInfo::keySize
```
**Description**<br>
Length of the public key.


### nOrXSize

  
```
uint32_t OH_Huks_PubKeyInfo::nOrXSize
```
**Description**<br>
Length of the n or X value.


### placeHolder

  
```
uint32_t OH_Huks_PubKeyInfo::placeHolder
```
**Description**<br>
Placeholder size.
