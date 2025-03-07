# RadioProtocol


## 概述

主副卡协议栈信息。

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [slotId](#slotid) | 卡槽ID  | 
| int [sessionId](#sessionid) | 会话ID  | 
| enum [RadioProtocolPhase](_ril_v10.md#radioprotocolphase)[phase](#phase) | Radio协议参数，具体查看[RadioProtocolPhase](_ril_v10.md#radioprotocolphase) | 
| int [technology](#technology) | Radio协议技术信息。 | 
| int [modemId](#modemid) | modem ID，底层与slotId的对应字段  | 
| enum [RadioProtocolStatus](_ril_v10.md#radioprotocolstatus)[status](#status) | Radio协议状态，具体查看[RadioProtocolStatus](_ril_v10.md#radioprotocolstatus) | 


## 类成员变量说明


### modemId

```
int RadioProtocol::modemId
```
**描述**

modem ID，底层与slotId的对应字段


### phase

```
enum RadioProtocolPhase RadioProtocol::phase
```
**描述**

Radio协议参数，具体查看[RadioProtocolPhase](_ril_v10.md#radioprotocolphase)


### sessionId

```
int RadioProtocol::sessionId
```
**描述**

会话ID


### slotId

```
int RadioProtocol::slotId
```
**描述**

卡槽ID


### status

```
enum RadioProtocolStatus RadioProtocol::status
```
**描述**

Radio协议状态，具体查看[RadioProtocolStatus](_ril_v10.md#radioprotocolstatus)


### technology

```
int RadioProtocol::technology
```
**描述**

Radio协议技术信息。

- 1：GSM

- 2：1XRTT

- 4：WCDMA

- 8：HSPA

- 16：HSPAP

- 32：TDSCDMA

- 64：EVDO

- 128：EHRPD

- 256：LTE

- 512：LTE_CA

- 1024：IWLAN

- 2048：NR 
