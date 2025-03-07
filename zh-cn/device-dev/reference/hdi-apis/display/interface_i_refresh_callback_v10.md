# IRefreshCallback


## 概述

定义显示刷新事件回调接口。

**起始版本：** 3.2

**相关模块：**[Display](_display_v10.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [OnRefresh](#onrefresh) ([in] unsigned int devId) | 显示刷新事件回调接口声明。 | 


## 成员函数说明


### OnRefresh()

```
IRefreshCallback::OnRefresh ([in] unsigned int devId)
```

**描述**


显示刷新事件回调接口声明。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devId | 显示设备的ID。 | 

**返回：**

0 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。
