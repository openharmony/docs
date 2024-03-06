# OH_Huks_KeyMaterialEcc


## Overview

Defines the structure of an ECC key.

**Since:**
9

**Related Modules:**

[HuksTypeApi](_huks_type_api.md)


## Summary


### Member Variables

| Name | Description | 
| -------- | -------- |
| [keyAlg](#keyalg) |Algorithm of the key.  | 
| [keySize](#keysize) | Length of the key.  | 
| [xSize](#xsize) | Length of the x value.  | 
| [ySize](#ysize) | Length of the y value.  | 
| [zSize](#zsize) | Length of the z value.  | 


## Member Variable Description 


### keyAlg

  
```
enum OH_Huks_KeyAlg OH_Huks_KeyMaterialEcc::keyAlg
```
**Description**<br>
Algorithm of the key.


### keySize

  
```
uint32_t OH_Huks_KeyMaterialEcc::keySize
```
**Description**<br>
Length of the key.


### xSize

  
```
uint32_t OH_Huks_KeyMaterialEcc::xSize
```
**Description**<br>
Length of the x value.


### ySize

  
```
uint32_t OH_Huks_KeyMaterialEcc::ySize
```
**Description**<br>
Length of the y value.


### zSize

  
```
uint32_t OH_Huks_KeyMaterialEcc::zSize
```
**Description**<br>
Length of the z value.
