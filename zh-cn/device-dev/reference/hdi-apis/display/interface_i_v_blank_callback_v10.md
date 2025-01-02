# IVBlankCallback


## 概述

定义帧同步事件回调接口。

**起始版本：** 3.2

**相关模块：**[Display](_display_v10.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [OnVBlank](#onvblank) ([in] unsigned int sequence, [in] unsigned long ns) | 帧同步事件回调接口声明。  | 


## 成员函数说明


### OnVBlank()

```
IVBlankCallback::OnVBlank ([in] unsigned int sequence, [in] unsigned long ns )
```
**描述**

帧同步事件回调接口声明。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| sequence | 序列号。  | 
| ns | 调用时的时间。 | 

**返回：**

0 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。
