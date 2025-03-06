# IImageProcessService


## 概述

声明图像处理进程服务。

创建映像处理会话，注册后台捕获后回调。

**起始版本：** 5.0

**相关模块：**[Camera](_camera_v13.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [CreateImageProcessSessionExt](#createimageprocesssessionext) ([in] int userId, [in] [IImageProcessCallback](interface_i_image_process_callback_v13.md) imageProcessCallback, [out] IImageProcessSession imageProcessSession) | 创建映像处理会话。 | 


## 成员函数说明


### CreateImageProcessSessionExt()

```
IImageProcessService::CreateImageProcessSessionExt ([in] int userId, [in] IImageProcessCallback imageProcessCallback, [out] IImageProcessSession imageProcessSession)
```

**描述**

创建映像处理会话。

**起始版本：** 5.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| userId | 用户ID。 | 
| imageProcessCallback | 镜像进程回调。有关详细信息，请参阅[IImageProcessCallback](interface_i_image_process_callback_v13.md)。 | 
| imageProcessSession | 指示图像处理会话。有关详细信息，请参阅**[IImageProcessSession](interface_i_image_process_session_v12.md)**。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看**[CamRetCode](_camera_v10.md#camretcode)**。
