# ICameraHostCallback


## 概述

定义Camera设备功能回调操作。

返回闪光灯状态。

**起始版本：** 4.1

**相关模块：**[Camera](_camera_v12.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [OnFlashlightStatusV1_2](#onflashlightstatusv1_2) ([in] enum FlashlightStatus status) | 当闪光状态发生变化时调用以报告最新状态。  | 


## 成员函数说明


### OnFlashlightStatusV1_2()

```
ICameraHostCallback::OnFlashlightStatusV1_2 ([in] enum FlashlightStatus status)
```
**描述**

当闪光状态发生变化时调用以报告最新状态。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| status | 闪光灯最新的状态。 | 
