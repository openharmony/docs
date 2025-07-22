# OH_NativeBundle_ModuleMetadata

## Overview

The struct describes the metadata of a module.

**Since**: 20

**Related module**: [bundle](_bundle.md)

**Header file**: [native_interface_bundle.h](native__interface__bundle.md)

## Summary

### Member Variables

| Name| Description|
| -------- | -------- |
| [moduleName](#modulename) | Name of the module.|
| [metadataArray](#metadataarray) | An array containing the module's metadata.|
| [metadataArraySize](#metadataarraysize) | Number of elements in the metadata array.|

## Member Variable Description

### moduleName

```
char* OH_NativeBundle_ModuleMetadata::moduleName
```

**Description**

Name of the module.

**Since**: 20

### metadataArray

```
OH_NativeBundle_Metadata* OH_NativeBundle_ModuleMetadata::metadataArray
```

**Description**

An array containing the module's metadata.

**Since**: 20

### metadataArraySize

```
size_t OH_NativeBundle_ModuleMetadata::metadataArraySize
```

**Description**

Number of elements in the metadata array.

**Since**: 20
