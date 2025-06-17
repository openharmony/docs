# OH_NativeBundle_ModuleMetadata

## 概述

描述模块元数据的信息。

**起始版本：** 20

**相关模块：** [Bundle](_bundle.md)

**所在头文件：** [native_interface_bundle.h](native__interface__bundle.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -------- | -------- |
| [moduleName](#modulename) | 模块名称。 |
| [metadataArray](#metadataarray) | 模块的元数据数组。 |
| [metadataArraySize](#metadataarraysize) | 模块的元数据数组大小。 |

## 结构体成员变量说明

### moduleName

```
char* OH_NativeBundle_ModuleMetadata::moduleName
```

**描述：**

模块名称。

**起始版本**：20

### metadataArray

```
OH_NativeBundle_Metadata* OH_NativeBundle_ModuleMetadata::metadataArray
```

**描述：**

模块的元数据数组。

**起始版本**：20

### metadataArraySize

```
size_t OH_NativeBundle_ModuleMetadata::metadataArraySize
```

**描述：**

模块的元数据数组大小。

**起始版本**：20