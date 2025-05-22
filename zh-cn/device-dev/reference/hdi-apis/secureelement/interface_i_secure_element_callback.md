# ISecureElementCallback


## 概述

声明从SecureElement HDF到SecureElement服务的报告状态回调。

**起始版本：** 4.0

**相关模块：**[HdiSecureElement](_hdi_secure_element.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [OnSeStateChanged](#onsestatechanged) ([in] boolean connected) | 通知SE状态已更改。  | 


## 成员函数说明


### OnSeStateChanged()

```
ISecureElementCallback::OnSeStateChanged ([in] boolean connected)
```
**描述**

通知SE状态已更改。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| connected | 当connected为true时表示SE已连接，反之为false的时候表示SE断开连接。 | 
