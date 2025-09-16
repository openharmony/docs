# OH_Huks_KeyAliasSet

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->

## Overview

Defines the struct of a key alias set.

**Since**: 20

**Related module:** [HuksTypeApi](capi-hukstypeapi.md)

**Header file**: [native_huks_type.h](capi-native-huks-type-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| uint32_t aliasesCnt | Number of key aliases.|
| struct [OH_Huks_Blob](capi-hukstypeapi-oh-huks-blob.md) *aliases | Pointer to the key alias set.|
