# OH_NativeBundle_ApplicationInfo
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wang19954-->
<!--SE: @hanfeng6; @lihaitao-->
<!--TSE: @kongjing2-->

## 概述

应用包信息数据结构，包含应用包名和应用指纹信息。

**起始版本：** 9

**相关模块：** [Native_Bundle](capi-native-bundle.md)

**所在头文件：** [native_interface_bundle.h](capi-native-interface-bundle-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| char* bundleName | 应用包名。 |
| char* fingerprint | 应用的指纹信息，由签名证书通过SHA-256算法计算哈希值生成。使用的签名证书发生变化时，该字段也会发生变化。 |
