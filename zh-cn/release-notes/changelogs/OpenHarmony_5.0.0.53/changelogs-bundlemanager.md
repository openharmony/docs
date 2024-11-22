# 包管理子系统Changelog

## cl.bundlemanager.1 包管理优化分享场景下文件数量校验

**访问级别**

公开接口

**变更原因**

优化分享场景下文件数量校验。

**变更影响**

该变更为不兼容变更。

例如：<br/>
分享场景下接收文件的应用配置。
```
{
    "utd": "general.image",
    "maxFileSupported": 3
}
````
jpeg、png都属于general.image类型，如果有2个jpeg类型的图片、2个png类型的图片需要分享。

变更前：
因为jpeg类型的图片数量和png类型的图片数量都不超过maxFileSupported，所以拉起分享面板此应用在面板上显示。

变更后：
需要校验指定类型文件数量的总和，因为jpeg类型、png类型的图片都属于general.image类型，并且总和为4超过了maxFileSupported，所以拉起分享面板此应用在面板上不显示。

**起始API Level**

API 11

**变更发生版本**

从OpenHarmony 5.0.0.53 版本开始。

**变更的接口/组件**

[module.json5](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/quick-start/module-configuration-file.md#skills%E6%A0%87%E7%AD%BE)中maxFileSupported标签。

**适配指导**

maxFileSupported 对于指定类型的文件，标识一次能接收或打开的最大数量。在分享多个不同类型文件时，应用作为接收方需考虑指定类型文件的最大数量。