# Camera_OutputCapability

## 概述

相机输出能力。

**起始版本：** 11

**相关模块：** [OH_Camera](capi-oh-camera.md)

**所在头文件：** [camera.h](capi-camera-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| [Camera_Profile](capi-oh-camera-camera-profile.md)** previewProfiles | 预览配置文件列表。 |
| uint32_t previewProfilesSize | 预览配置文件列表的大小。 |
| [Camera_Profile](capi-oh-camera-camera-profile.md)** photoProfiles | 拍照配置文件列表。<br> 配置文件中的size设置的是相机分辨率宽高，非实际出图宽高。 |
| uint32_t photoProfilesSize | 拍照配置文件列表的大小。 |
| [Camera_VideoProfile](capi-oh-camera-camera-videoprofile.md)** videoProfiles | 录像配置文件列表。 |
| uint32_t videoProfilesSize | 录像配置文件列表的大小。 |
| [Camera_MetadataObjectType](capi-camera-h.md#camera_metadataobjecttype)** supportedMetadataObjectTypes | 元数据对象类型列表。 |
| uint32_t metadataProfilesSize | 元数据对象类型列表的大小。 |


