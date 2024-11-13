# IOfflineStreamOperator


## 概述

定义Camera设备离线流操作。

对Camera设备离线流执行取消捕获和释放操作。

**起始版本：** 3.2

**相关模块：**[Camera](_camera_v10.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [CancelCapture](#cancelcapture) ([in] int captureId) | 取消捕获请求。  | 
| [ReleaseStreams](#releasestreams) ([in] int[] streamIds) | 释放离线流。  | 
| [Release](#release) () | 释放所有离线流。  | 


## 成员函数说明


### CancelCapture()

```
IOfflineStreamOperator::CancelCapture ([in] int captureId)
```
**描述**

取消捕获请求。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| captureId | 用于标识要取消的捕获请求。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看[CamRetCode](_camera_v10.md#camretcode)。


### Release()

```
IOfflineStreamOperator::Release ()
```
**描述**

释放所有离线流。

释放流的前置条件：

1. 所有单次捕获的Capture处理完成。

2. 所有连续捕获请求都已经被CancelCapture。

**起始版本：** 3.2

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看[CamRetCode](_camera_v10.md#camretcode)。


### ReleaseStreams()

```
IOfflineStreamOperator::ReleaseStreams ([in] int[] streamIds)
```
**描述**

释放离线流。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| streamIds | 用于标识要释放的多条离线流。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看[CamRetCode](_camera_v10.md#camretcode)。
