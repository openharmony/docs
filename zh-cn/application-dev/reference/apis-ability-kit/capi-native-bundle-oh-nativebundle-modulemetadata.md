# OH_NativeBundle_ModuleMetadata
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @memghaiyang-->
<!--Adviser: @HelloCrease-->

```c
typedef struct OH_NativeBundle_ModuleMetadata {...} OH_NativeBundle_ModuleMetadata
```

## 概述

模块元数据的信息。

**起始版本：** 20

**相关模块：** [Native_Bundle](capi-native-bundle.md)

**所在头文件：** [native_interface_bundle.h](capi-native-interface-bundle-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| char* moduleName | 模块名称。 |
| [OH_NativeBundle_Metadata*](capi-native-bundle-oh-nativebundle-metadata.md) metadataArray | 模块的元数据数组。 |
| size_t metadataArraySize | 模块的元数据数组大小。需与metadataArray配合使用，应等于metadataArray数组的实际元素数量，设置错误可能导致数组越界或数据访问异常。 |
