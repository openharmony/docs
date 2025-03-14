# IImageProcessService

## 概述

声明图像处理进程服务。

创建映像处理会话,注册后台捕获后回调。

**起始版本：** 4.1

**相关模块：**[Camera](_camera_v12.md)

## 汇总

### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [CreateImageProcessSession](#createimageprocesssession) ([in] int userId, [in] [IImageProcessCallback](interface_i_image_process_callback_v12.md) imageProcessCallback, [out] [IImageProcessSession](interface_i_image_process_session_v12.md) imageProcessSession) | 创建映像处理会话。  | 
| [RegisterBackgroundPostCaptureCallback](#registerbackgroundpostcapturecallback) ([in] [IImageProcessCallback](interface_i_image_process_callback_v12.md) imageProcessCallback) | 注册后台后捕获回调。  | 

## 成员函数说明

### CreateImageProcessSession()

```
IImageProcessService::CreateImageProcessSession ([in] int userId, [in] IImageProcessCallback imageProcessCallback, [out] IImageProcessSession imageProcessSession)
```
**描述**

创建映像处理会话。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| userId | 用户ID。  | 
| imageProcessCallback | 镜像进程回调。有关详细信息，请参阅 [IImageProcessCallback](interface_i_image_process_callback_v12.md)。  | 
| imageProcessSession | 指示图像处理会话。有关详细信息，请参阅 [IImageProcessSession](interface_i_image_process_session_v12.md)。 | 

### RegisterBackgroundPostCaptureCallback()

```
IImageProcessService::RegisterBackgroundPostCaptureCallback ([in] IImageProcessCallback imageProcessCallback)
```
**描述**

注册后台后捕获回调。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| imageProcessSession | 指示图像处理会话。有关详细信息，请参阅 [IImageProcessSession](interface_i_image_process_session_v12.md)。 | 
