# IMediaKeySessionCallback


## 概述

定义DRM会话的事件通知函数，用于DRM驱动通知DRM框架事件。

**起始版本：** 4.1

**相关模块：**[HdiDrm](_hdi_drm.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [SendEvent](#sendevent) ([in] enum [EventType](_hdi_drm.md#eventtype) eventType, [in] int extra, [in] unsigned char[] data) | 发送事件通知。  | 
| [SendEventKeyChange](#sendeventkeychange) ([in] Map&lt; unsigned char[], enum [MediaKeySessionKeyStatus](_hdi_drm.md#mediakeysessionkeystatus) &gt; keyStatus, [in] boolean newKeysAvailable) | 发送事件通知。  | 


## 成员函数说明


### SendEvent()

```
IMediaKeySessionCallback::SendEvent ([in] enum EventType eventType, [in] int extra, [in] unsigned char[] data )
```
**描述**

发送事件通知。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| eventType | 事件类型。  | 
| extra | 事件附加信息。  | 
| data | 事件详细信息。 | 

**返回：**

0 表示执行成功。

其他值表示执行失败。


### SendEventKeyChange()

```
IMediaKeySessionCallback::SendEventKeyChange ([in] Map< unsigned char[], enum MediaKeySessionKeyStatus > keyStatus, [in] boolean newKeysAvailable )
```
**描述**

发送事件通知。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| keyStatus | 许可证中密钥索引及其状态。  | 
| newKeysAvailable | 是否有新的许可证密钥可用，true表示有新的许可证密钥， false表示无新的许可证密钥。 | 

**返回：**

0 表示执行成功。

其他值表示执行失败。
