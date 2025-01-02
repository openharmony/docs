# IImageProcessSession


## 概述

图像处理会话进程。

获取Coucurrency、待处理图像，设置执行模式，处理流程图像，删除图像，执行会话中断，会话重启。

**起始版本：** 4.1

**相关模块：**[Camera](_camera_v12.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [GetCoucurrency](#getcoucurrency) ([in] enum [ExecutionMode](_camera_v12.md#executionmode) mode, [out] int taskCount) | 获取具有spacific后处理执行模式的流程会话的Coucurrency任务计数。  | 
| [GetPendingImages](#getpendingimages) ([out] List&lt; String &gt; imageIds) | 获取未处理的挂起图像的ID。  | 
| [SetExecutionMode](#setexecutionmode) ([in] [ExecutionMode](_camera_v12.md#executionmode) mode) | 设置处理后执行模式。  | 
| [ProcessImage](#processimage) ([in] String imageId) | 按镜像ID处理特定镜像。  | 
| [RemoveImage](#removeimage) ([in] String imageId) | 按映像ID删除特定映像。  | 
| [Interrupt](#interrupt) () | 中断进程会话。  | 
| [Reset](#reset) () | 重置进程会话。  | 


## 成员函数说明


### GetCoucurrency()

```
IImageProcessSession::GetCoucurrency ([in] enum ExecutionMode mode, [out] int taskCount )
```
**描述**

获取具有spacific后处理执行模式的流程会话的Coucurrency任务计数。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mode | 执行模式。  | 
| taskCount | coucurrency任务计数。 | 


### GetPendingImages()

```
IImageProcessSession::GetPendingImages ([out] List< String > imageIds)
```
**描述**

获取未处理的挂起图像的ID。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| imageIds | 待处理图像的 ID。 | 


### Interrupt()

```
IImageProcessSession::Interrupt ()
```
**描述**

中断进程会话。

**起始版本：** 4.1


### ProcessImage()

```
IImageProcessSession::ProcessImage ([in] String imageId)
```
**描述**

按镜像ID处理特定镜像。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| imageId | 图像ID。 | 


### RemoveImage()

```
IImageProcessSession::RemoveImage ([in] String imageId)
```
**描述**

按映像ID删除特定映像。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| imageId | 图像ID。 | 


### Reset()

```
IImageProcessSession::Reset ()
```
**描述**

重置进程会话。

**起始版本：** 4.1


### SetExecutionMode()

```
IImageProcessSession::SetExecutionMode ([in] ExecutionMode mode)
```
**描述**

设置处理后执行模式。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mode | 执行模式。 | 
