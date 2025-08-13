# IVBlankIdleCallback


## 概述

定义帧同步事件回调接口。

**起始版本：** 5.0

**相关模块：**[Display](index_composer_display_v12.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [OnVBlankIdleCallback](#onvblankidlecallback) ([in] unsigned int devId, [in] unsigned long ns) | 注册VBlank事件回调，当有VBlank事件发生时接口实现层需要回调注册的接口。 | 


## 成员函数说明


### OnVBlankIdleCallback()

```
IVBlankIdleCallback::OnVBlankIdleCallback([in] unsigned int devId, [in] unsigned long ns)
```

**描述**

注册VBlank事件回调，当有VBlank事件发生时接口实现层需要回调注册的接口。

**起始版本：** 5.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devId | 表示设备ID。 | 
| ns | 表示调用时间（无符号长整型）。 | 

**返回：**

0 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。
