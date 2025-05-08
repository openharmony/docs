# Camera_OutputCapability


## 概述

相机输出能力。

**起始版本：** 11

**相关模块：**[OH_Camera](_o_h___camera.md)

**所在头文件：**[camera.h](camera_8h.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [Camera_Profile](_camera___profile.md) \*\* [previewProfiles](#previewprofiles) | 预览配置文件列表。  | 
| uint32_t [previewProfilesSize](#previewprofilessize) | 预览配置文件列表的大小。  | 
| [Camera_Profile](_camera___profile.md) \*\* [photoProfiles](#photoprofiles) | 拍照配置文件列表。  | 
| uint32_t [photoProfilesSize](#photoprofilessize) | 拍照配置文件列表的大小。  | 
| [Camera_VideoProfile](_camera___video_profile.md) \*\* [videoProfiles](#videoprofiles) | 录像配置文件列表。  | 
| uint32_t [videoProfilesSize](#videoprofilessize) | 录像配置文件列表的大小。  | 
| [Camera_MetadataObjectType](_o_h___camera.md#camera_metadataobjecttype) \*\* [supportedMetadataObjectTypes](#supportedmetadataobjecttypes) | 元数据对象类型列表。  | 
| uint32_t [metadataProfilesSize](#metadataprofilessize) | 元数据对象类型列表的大小。  | 


## 结构体成员变量说明


### metadataProfilesSize

```
uint32_t Camera_OutputCapability::metadataProfilesSize
```
**描述**
元数据对象类型列表的大小。


### photoProfiles

```
Camera_Profile** Camera_OutputCapability::photoProfiles
```
**描述**
拍照配置文件列表。

配置文件中的size设置的是相机分辨率宽高，非实际出图宽高。


### photoProfilesSize

```
uint32_t Camera_OutputCapability::photoProfilesSize
```
**描述**
拍照配置文件列表的大小。


### previewProfiles

```
Camera_Profile** Camera_OutputCapability::previewProfiles
```
**描述**
预览配置文件列表。


### previewProfilesSize

```
uint32_t Camera_OutputCapability::previewProfilesSize
```
**描述**
预览配置文件列表的大小。


### supportedMetadataObjectTypes

```
Camera_MetadataObjectType** Camera_OutputCapability::supportedMetadataObjectTypes
```
**描述**
元数据对象类型列表。


### videoProfiles

```
Camera_VideoProfile** Camera_OutputCapability::videoProfiles
```
**描述**
录像配置文件列表。


### videoProfilesSize

```
uint32_t Camera_OutputCapability::videoProfilesSize
```
**描述**
录像配置文件列表的大小。
