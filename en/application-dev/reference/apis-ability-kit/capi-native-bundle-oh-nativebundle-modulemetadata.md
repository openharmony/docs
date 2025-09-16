# OH_NativeBundle_ModuleMetadata
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

## Overview

The struct describes the metadata of a module.

**Since**: 20

**Related module**: [Native_Bundle](capi-native-bundle.md)

**Header file**: [native_interface_bundle.h](capi-native-interface-bundle-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| char* moduleName | Pointer to the module name.|
| [OH_NativeBundle_Metadata*](capi-native-bundle-oh-nativebundle-metadata.md) metadataArray | Pointer to an array containing the module's metadata.|
| size_t metadataArraySize | Number of elements in the metadata array.|
