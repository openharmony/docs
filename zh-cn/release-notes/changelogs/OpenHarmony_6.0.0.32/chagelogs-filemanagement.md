# 文件管理子系统ChangeLog

## cl.filemanagement.1 @ohos.file.fs.d.ts中copy接口在拷贝后，对目标文件原有数据处理方式发生变更

**访问级别**

公开接口

**变更原因**

在目标文件存在且size大于源文件的场景下使用copy接口，拷贝后的目标文件的size会大于源文件且尾部存在冗余内容。

**变更影响**

此变更不涉及应用适配。

变更前：在目标文件存在且size大于源文件的场景下使用copy接口，拷贝后的目标文件的size会大于源文件且尾部存在冗余内容。

变更后：API version 20及以上版本开始，在目标文件存在且size大于源文件的场景下使用copy接口，拷贝后的目标文件与源文件内容及size相同；API version 20以下版本与变更前行为一致。

**起始API Level**

11

**变更发生版本**

从OpenHarmony SDK 6.0.0.32 开始。

**变更的接口/组件**

[@ohos.file.fs.d.ts](../../../application-dev/reference/apis-core-file-kit/js-apis-file-fs.md#fscopy11)
中的copy接口 。

**适配指导**

默认行为变更，无需适配。