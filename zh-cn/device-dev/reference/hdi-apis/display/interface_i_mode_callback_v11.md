# IModeCallback


## 概述

显示模式更改时使用接口。

**起始版本：** 4.1

**相关模块：**[Display](_display_v11.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [OnMode](#onmode) ([in] unsigned int modeId, [in] unsigned long vBlankPeriod) | 显示模式更改时要调用的回调。 | 


## 成员函数说明


### OnMode()

```
IModeCallback::OnMode ([in] unsigned int modeId, [in] unsigned long vBlankPeriod )
```

**描述**


显示模式更改时要调用的回调。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| modeId | GetDisplaySupportedModes返回的显示模式 ID。 | 
| vBlankPeriod | modeId 指示的 vblank。 | 

**返回：**

0 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。
