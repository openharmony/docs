# ISeamlessChangeCallback


## 概述

更改帧速率需要使用的接口。

**起始版本：** 4.1

**相关模块：**[Display](_display_v11.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [OnSeamlessChange](#onseamlesschange) ([in] unsigned int devId) | 准备好更改帧速率时要调用的回调 | 


## 成员函数说明


### OnSeamlessChange()

```
ISeamlessChangeCallback::OnSeamlessChange ([in] unsigned int devId)
```

**描述**


准备好更改帧速率时要调用的回调

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devId | 表示需要操作的设备ID。 | 

**返回：**

0 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。
