# OH_Huks_CertChain

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->

## Overview

Defines the struct of a certificate chain.

**Since**: 9

**Related module:** [HuksTypeApi](capi-hukstypeapi.md)

**Header file**: [native_huks_type.h](capi-native-huks-type-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| struct [OH_Huks_Blob](capi-hukstypeapi-oh-huks-blob.md) *certs | Pointer to the certificate data.|
| uint32_t certsCount | Number of certificates in the certificate chain.|
