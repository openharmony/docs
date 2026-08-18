# 截图错误码
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @yihao-lin-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @Brilliantry_Rui-->

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 160001 图像加载错误

**错误信息**

An image component in builder is not ready for taking a snapshot. The check for the ready state is required when the checkImageStatus option is enabled.

**错误描述**

图像加载错误。该错误码为string类型。

**可能原因**

在进行截图操作前，当启用checkImageStatus选项且builder中的Image组件解码检查失败或节点图像加载失败，调用截图接口可能触发相应的错误码。

**处理步骤**

设置相应截图接口的delay延时参数，延时时长应以图像加载完成为准，以确保图像加载成功。

## 160002 截图超时

**错误信息**

Timeout.

**错误描述**

截图操作超时。该错误码为string类型。

**可能原因**

系统任务未执行。

**处理步骤**

改用当前截图接口对应的异步接口。

## 160003 截图选项中设置的色彩空间或动态范围模式不受支持

**错误信息**

Unsupported color space or dynamic range mode in snapshot options.

**错误描述**

截图选项中设置的色彩空间或动态范围模式不受支持。该错误码为string类型。

**可能原因**

截图选项中设置的色彩空间或动态范围模式值不在支持范围内。

**处理步骤**

修改截图选项中设置的色彩空间或动态范围模式值为对应截图接口参数说明中列出的支持值。

## 160004 离屏节点截图不支持将色彩空间或动态范围模式对应的isAuto参数设置为true

**错误信息**

isAuto(true) is not supported for offscreen node snapshots.

**错误描述**

离屏节点截图不支持将色彩空间或动态范围模式对应的isAuto参数设置为true。该错误码为string类型。

**可能原因**

对离屏节点进行截图时，不支持将截图选项中色彩空间或动态范围模式对应的isAuto参数设置为true。

**处理步骤**

将截图选项中色彩空间或动态范围模式对应的isAuto参数设置为false。
