# IImageProcessCallback


## 概述

定义声明图像处理回调。

获取在流程完成时、状态已更改时、出错时的回调函数。

**起始版本：** 5.0

**相关模块：**[Camera](_camera_v13.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [OnProcessDoneExt](#onprocessdoneext) ([in] String imageId, [in] [ImageBufferInfoExt](_image_buffer_info_ext_v13.md) buffer) | 在进程完成时调用。 | 


## 成员函数说明


### OnProcessDoneExt()

```
IImageProcessCallback::OnProcessDoneExt ([in] String imageId, [in] ImageBufferInfoExt buffer)
```

**描述**

在进程完成时调用。

有关报告模式的详细信息，请参阅**[SetResultMode()](interface_i_camera_device_v10.md#setresultmode)**。

**起始版本：** 5.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| imageId | 镜像ID。 | 
| buffer | 缓冲区。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看**[CamRetCode](_camera_v10.md#camretcode)**。
