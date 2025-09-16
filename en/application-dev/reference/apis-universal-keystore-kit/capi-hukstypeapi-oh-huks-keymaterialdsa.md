# OH_Huks_KeyMaterialDsa

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->

## Overview

Defines the struct of a DSA key.

**Since**: 9

**Related module:** [HuksTypeApi](capi-hukstypeapi.md)

**Header file**: [native_huks_type.h](capi-native-huks-type-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| enum [OH_Huks_KeyAlg](capi-native-huks-type-h.md#oh_huks_keyalg) keyAlg | Algorithm of the key.|
| uint32_t keySize | Length of the key.|
| uint32_t xSize | Length of **x**.|
| uint32_t ySize | Length of **y**.|
| uint32_t pSize | Length of **p**.|
| uint32_t qSize | Length of **q**.|
| uint32_t gSize | Length of **g**.|
