# Camera_TorchStatusInfo


## 概述

手电筒状态信息。

**起始版本：** 12

**相关模块：**[OH_Camera](_o_h___camera.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| bool [isTorchAvailable](#istorchavailable) | 手电筒是否可用，true表示可用，false表示不可用。  | 
| bool [isTorchActive](#istorchactive) | 手电筒是否激活，true表示激活，false表示未激活。  | 
| float [torchLevel](#torchlevel) | 手电筒亮度等级。取值范围为[0,1]，越靠近1，亮度越大。  | 


## 结构体成员变量说明


### isTorchActive

```
bool Camera_TorchStatusInfo::isTorchActive
```
**描述**
手电筒是否激活。


### isTorchAvailable

```
bool Camera_TorchStatusInfo::isTorchAvailable
```
**描述**
手电筒是否可用。


### torchLevel

```
float Camera_TorchStatusInfo::torchLevel
```
**描述**
手电筒亮度等级。取值范围为[0,1]，越靠近1，亮度越大。
