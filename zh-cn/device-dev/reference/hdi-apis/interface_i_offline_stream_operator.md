# IOfflineStreamOperator


## **概述**

定义Camera设备离线流操作。

对Camera设备离线流执行取消捕获和释放操作。

**相关模块:**

[Camera](camera.md)


## **汇总**


### Public 成员函数

  | 名称 | 描述 | 
| -------- | -------- |
| [CancelCapture](#cancelcapture)&nbsp;([in]&nbsp;int&nbsp;captureId) | 取消捕获请求。 | 
| [ReleaseStreams](#releasestreams)&nbsp;([in]&nbsp;int[]&nbsp;streamIds) | 释放离线流。 | 
| [Release](#release)&nbsp;() | 释放所有离线流。&nbsp;释放流的前置条件：<br/>1.&nbsp;所有单次捕获的Capture处理完成。<br/>2.&nbsp;所有连续捕获请求都已经被CancelCapture。 | 


## **成员函数说明**


### CancelCapture()

  
```
IOfflineStreamOperator::CancelCapture ([in] int captureId)
```

**描述：**

取消捕获请求。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| captureId | 用于标识要取消的捕获请求。 | 

**返回:**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看[CamRetCode](camera.md#camretcode)。


### Release()

  
```
IOfflineStreamOperator::Release ()
```

**描述：**

释放所有离线流。 释放流的前置条件：

1. 所有单次捕获的Capture处理完成。

2. 所有连续捕获请求都已经被CancelCapture。

**返回:**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看[CamRetCode](camera.md#camretcode)。


### ReleaseStreams()

  
```
IOfflineStreamOperator::ReleaseStreams ([in] int[] streamIds)
```

**描述：**

释放离线流。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| streamIds | 用于标识要释放的多条离线流。 | 

**返回:**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看[CamRetCode](camera.md#camretcode)。
