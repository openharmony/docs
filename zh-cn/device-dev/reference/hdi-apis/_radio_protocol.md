# RadioProtocol


## 概述

主副卡协议栈信息。

**相关模块:**

[Ril](_ril.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [slotId](#slotid) | int<br/>卡槽ID&nbsp; | 
| [sessionId](#sessionid) | int<br/>会话ID&nbsp; | 
| [phase](#phase) | enum&nbsp;[RadioProtocolPhase](_ril.md#radioprotocolphase)<br/>Radio协议参数，具体查看[RadioProtocolPhase](_ril.md#radioprotocolphase) | 
| [technology](#technology) | int<br/>Radio协议技术信息。 | 
| [modemId](#modemid) | int<br/>modem&nbsp;ID，底层与slotId的对应字段&nbsp; | 
| [status](#status) | enum&nbsp;[RadioProtocolStatus](_ril.md#radioprotocolstatus)<br/>Radio协议状态，具体查看[RadioProtocolStatus](_ril.md#radioprotocolstatus) | 


## 类成员变量说明


### modemId

  
```
int RadioProtocol::modemId
```
**描述:**
modem ID，底层与slotId的对应字段


### phase

  
```
enum RadioProtocolPhase RadioProtocol::phase
```
**描述:**
Radio协议参数，具体查看[RadioProtocolPhase](_ril.md#radioprotocolphase)


### sessionId

  
```
int RadioProtocol::sessionId
```
**描述:**
会话ID


### slotId

  
```
int RadioProtocol::slotId
```
**描述:**
卡槽ID


### status

  
```
enum RadioProtocolStatus RadioProtocol::status
```
**描述:**
Radio协议状态，具体查看[RadioProtocolStatus](_ril.md#radioprotocolstatus)


### technology

  
```
int RadioProtocol::technology
```
**描述:**
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
