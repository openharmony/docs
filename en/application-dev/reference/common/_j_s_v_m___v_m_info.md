# JSVM_VMInfo

## Overview

JavaScript Virtual Machine Information.

**Starting Version:** 11

**Related Module:** [JSVM](_j_s_v_m.md)

## Summary

### Member Variables

| Name                                                   | Description                                                |
| ------------------------------------------------------ | ---------------------------------------------------------- |
| uint32_t [apiVersion](#apiversion)                     | The highest API version supported by this virtual machine. |
| const char \* [engine](#engine)                         | The name of the engine implementing the virtual machine.   |
| const char \* [version](#version)                       | The version of the virtual machine.                        |
| uint32_t [cachedDataVersionTag](#cacheddataversiontag) | The cached data version tag.                               |

## Structure Member Variable Descriptions

### apiVersion

```
uint32_t JSVM_VMInfo::apiVersion
```
**Description**
The highest API version supported by this virtual machine.

### cachedDataVersionTag

```
uint32_t JSVM_VMInfo::cachedDataVersionTag
```
**Description**
The cached data version tag.

### engine

```
const char* JSVM_VMInfo::engine
```
**Description**
The name of the engine implementing the virtual machine.

### version

```
const char* JSVM_VMInfo::version
```
**Description**
The version of the virtual machine.