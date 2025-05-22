# 文件管理子系统Changelog

## cl.filemanagement.1 DocumentPickerMode syscap标签变更

**访问级别**

公开接口

**变更原因**

syscap描述有误，修改前的DocumentPickerMode的syscap为SystemCapability.FileManagement.UserFileService.FolderSelection，表示该接口只支持2in1设备使用。但实际功能是手机和2in1设备都支持，需更改syscap。

**变更影响**

该变更为不兼容变更。

变更前：DocumentPickerMode的syscap为 SystemCapability.FileManagement.UserFileService.FolderSelection

变更后：DocumentPickerMode的syscap为 SystemCapability.FileManagement.UserFileService

**起始API Level**

API 12

**变更发生版本**

从OpenHarmony 5.0.0.57 版本开始。

**变更的接口/组件**

@ohos.file.picker.d.ts中如下接口：[DocumentPickerMode](../../../application-dev/reference/apis-core-file-kit/js-apis-file-picker.md#documentpickermode12)

**适配指导**

开发者在使用canIUse判断DocumentPickerMode接口时，syscap需改为SystemCapability.FileManagement.UserFileService。
