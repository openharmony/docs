# JSVM_ScriptOrigin


## Overview

Source code information.

**Since**: 12

**Related module**: [JSVM](_j_s_v_m.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| const char \* [sourceMapUrl](#sourcemapurl) | Source map path. | 
| const char \* [resourceName](#resourcename) | Source file name. | 
| size_t [resourceLineOffset](#resourcelineoffset) | Start line number of the code in the source file. | 
| size_t [resourceColumnOffset](#resourcecolumnoffset) | Start column number of the code in the source file. | 


## Member Variable Description


### resourceColumnOffset

```
size_t JSVM_ScriptOrigin::resourceColumnOffset
```
**Description**
Start column number of the code in the source file.


### resourceLineOffset

```
size_t JSVM_ScriptOrigin::resourceLineOffset
```
**Description**
Start line number of the code in the source file.


### resourceName

```
const char* JSVM_ScriptOrigin::resourceName
```
**Description**
Source file name.


### sourceMapUrl

```
const char* JSVM_ScriptOrigin::sourceMapUrl
```
**Description**
Source map path.
