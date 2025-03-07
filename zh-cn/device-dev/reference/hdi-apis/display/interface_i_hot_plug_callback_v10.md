# IHotPlugCallback


## 概述

定义热插拔事件回调接口。

**起始版本：** 3.2

**相关模块：**[Display](_display_v10.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [OnHotPlug](#onhotplug) ([in] unsigned int outputId, [in] boolean connected) | 热插拔事件回调接口声明。  | 


## 成员函数说明


### OnHotPlug()

```
IHotPlugCallback::OnHotPlug ([in] unsigned int outputId, [in] boolean connected )
```
**描述**

热插拔事件回调接口声明。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| outputId | 指示显示设备的 ID。  | 
| connected | 设备是否连接。 | 

**返回：**

0 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。
