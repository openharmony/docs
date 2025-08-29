# OH_Huks_Param

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->

## Overview

Defines the types of the parameters in a parameter set.

**Since**: 9

**Related module:** [HuksTypeApi](capi-hukstypeapi.md)

**Header file**: [native_huks_type.h](capi-native-huks-type-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| uint32_t tag | Tag value.|
| union {<br>  bool boolParam <br>  int32_t int32Param <br> uint32_t uint32Param <br>    uint64_t uint64Param <br>    [struct OH_Huks_Blob](capi-hukstypeapi-oh-huks-blob.md) blob <br> } | **boolParam**: The parameter is of the Boolean type.<br>**int32Param**: The parameter is of the int32_t type.<br>**uint32Param**: The parameter is of the uint32_t type.<br>**uint64Param**: The parameter is of the uint64_t type.<br>**blob**: The parameter is of the OH_Huks_Blob type. |
