# 视频处理引擎错误码

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 29210001 未知错误

**错误信息**

Some unknown error occurred, such as GPU calculation failure or memcpy failure. 

**错误描述**

发生了一些未知错误。例如，GPU计算失败或内容拷贝失败。

**可能原因**

1. GPU计算失败。
2. 内容拷贝失败。

**处理步骤**

1. 检查资源是否已经初始化。
2. 检查内存是否有效。

## 29210002 初始化失败

**错误信息**

The global environment initialization for video processing failed, such as failure to initialize the GPU environment.

**错误描述**

视频处理全局环境初始化失败。例如，初始化GPU环境失败。

**可能原因**

GPU初始化失败。

**处理步骤**

查看log是否有GPU异常上报。

## 29210003 创建失败

**错误信息**

Failed to create video processing instance. For example, the number of instances exceeds the upper limit.

**错误描述**

创建视频处理实例失败。例如，实例数量超出上限。

**可能原因**

创建实例过多。

**处理步骤**

减少创建实例的数目。

## 29210004 处理失败

**错误信息**

Failed to process video buffer. For example, the processing times out.

**错误描述**

处理视频缓冲区失败。例如，处理超时。

**可能原因**

处理时间超时。

**处理步骤**

减小负载。

## 29210005 不支持的处理

**错误信息**

The processing is not supported. You may call OH_VideoProcessing_IsXXXSupported to check whether the capability is supported.

**错误描述**

不支持该处理。可以调用OH_VideoProcessing_IsXXXSupported来检查是否支持该能力。

**可能原因**

能力不支持。

**处理步骤**

检查log打印。

## 29210006 不被允许的操作

**错误信息**

The operation is not permitted. This may be caused by incorrect status.

**错误描述**

不允许该操作。由于状态不正确造成。

**可能原因**

状态异常。

**处理步骤**

检查log打印。

## 29210007 内存不足

**错误信息**

Out of memory.

**错误描述**

内存不足。

**可能原因**

内存不足。

**处理步骤**

减少内存申请。

## 29210008 实例无效

**错误信息**

The video processing instance is invalid. This may be caused by null instance.

**错误描述**

视频处理实例无效。可能由于实例为空导致。

**可能原因**

无效的实例。

**处理步骤**

检查实例的创建。

## 29210009 值无效

**错误信息**

Input value is invalid. This error is returned for all of the following error conditions:
1. Invalid input or output video buffer - The video buffer width(height) is too large or colorspace is incorrect.
2. Invalid parameter - The parameter does not contain valid information, such as detail enhancer level is incorrect.

**错误描述**

输入值无效。以下所有错误情况都会返回此错误：

1. 输入或输出视频缓冲区无效：视频缓冲区宽度（高度）过大或色彩空间不正确。
2. 参数无效：参数不包含有效信息（例如，算法档位不正确）。

**可能原因**

1. 输入或输出分辨率过大或色彩空间异常。
2. 算法档位错误。

**处理步骤**

1. 检查输入输出的分辨率和色彩空间。
2. 检查是否配置了算法档位。