# OH_Huks_KeyMaterialDsa


## Overview

Defines the structure of a DSA key.

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
| [pSize](#psize) | Length of the p value.  | 
| [qSize](#qsize) | Length of the q value.  | 
| [gSize](#gsize) | Length of the g value.  | 


## Member Variable Description 


### gSize

  
```
uint32_t OH_Huks_KeyMaterialDsa::gSize
```
**Description**<br>
Length of the g value.


### keyAlg

  
```
enum OH_Huks_KeyAlg OH_Huks_KeyMaterialDsa::keyAlg
```
**Description**<br>
Algorithm of the key.


### keySize

  
```
uint32_t OH_Huks_KeyMaterialDsa::keySize
```
**Description**<br>
Length of the key.


### pSize

  
```
uint32_t OH_Huks_KeyMaterialDsa::pSize
```
**Description**<br>
Length of the p value.


### qSize

  
```
uint32_t OH_Huks_KeyMaterialDsa::qSize
```
**Description**<br>
Length of the q value.


### xSize

  
```
uint32_t OH_Huks_KeyMaterialDsa::xSize
```
**Description**<br>
Length of the x value.


### ySize

  
```
uint32_t OH_Huks_KeyMaterialDsa::ySize
```
**Description**<br>
Length of the y value.
