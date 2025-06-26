# Print_PrintAttributes


## Overview

Defines the print attributes.

**Since**: 13

**Related module**: [OH_Print](_o_h___print.md)

**Header file**: [ohprint.h](ohprint_8h.md)

## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| [Print_Range](_print___range.md) [pageRange](#pagerange) | Defines the page range. | 
| [Print_PageSize](_print___page_size.md) [pageSize](#pagesize) | Defines the page size. | 
| [Print_Margin](_print___margin.md) [pageMargin](#pagemargin) | Defines the page margin. | 
| uint32_t [copyNumber](#copynumber) | Defines the number of copies to print. | 
| uint32_t [duplexMode](#duplexmode) | Defines the duplex mode. | 
| uint32_t [colorMode](#colormode) | Defines the color mode. | 
| bool [isSequential](#issequential) | Defines whether to print in a sequential manner. | 
| bool [isLandscape](#islandscape) | Defines whether to print in the landscape mode. | 
| bool [hasOption](#hasoption) | Defines whether the printing has an option flag. | 
| char [options](#options) [256] | Defines the printing options. | 


## Member Variable Description


### colorMode

```
uint32_t Print_PrintAttributes::colorMode
```
**Description**

Defines the color mode.


### copyNumber

```
uint32_t Print_PrintAttributes::copyNumber
```
**Description**

Defines the number of copies to print.


### duplexMode

```
uint32_t Print_PrintAttributes::duplexMode
```
**Description**

Defines the duplex mode.


### hasOption

```
bool Print_PrintAttributes::hasOption
```
**Description**

Defines whether the printing has an option flag.


### isLandscape

```
bool Print_PrintAttributes::isLandscape
```
**Description**

Defines whether to print in the landscape mode.


### isSequential

```
bool Print_PrintAttributes::isSequential
```
**Description**

Defines whether to print in a sequential manner.


### options

```
char Print_PrintAttributes::options[256]
```
**Description**

Defines the printing options.


### pageMargin

```
Print_Margin Print_PrintAttributes::pageMargin
```
**Description**

Defines the page margin.


### pageRange

```
Print_Range Print_PrintAttributes::pageRange
```
**Description**

Defines the page range.


### pageSize

```
Print_PageSize Print_PrintAttributes::pageSize
```
**Description**

Defines the page size.
