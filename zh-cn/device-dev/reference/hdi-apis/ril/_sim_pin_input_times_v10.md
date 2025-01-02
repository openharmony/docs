# SimPinInputTimes


## 概述

SIM密码输入次数信息。

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [serial](#serial) | 请求的序列号  | 
| int [times](#times) | 剩余次数  | 
| int [pukTimes](#puktimes) | PUK码剩余次数  | 
| int [pinTimes](#pintimes) | PIN码剩余次数  | 
| int [puk2Times](#puk2times) | PUK2码剩余次数  | 
| int [pin2Times](#pin2times) | PIN2码剩余次数  | 
| String [code](#code) | 请求字段，例如： SIM PIN2：表示SIM卡PIN2码请求  | 


## 类成员变量说明


### code

```
String SimPinInputTimes::code
```
**描述**

请求字段，例如： SIM PIN2：表示SIM卡PIN2码请求


### pin2Times

```
int SimPinInputTimes::pin2Times
```
**描述**

PIN2码剩余次数


### pinTimes

```
int SimPinInputTimes::pinTimes
```
**描述**

PIN码剩余次数


### puk2Times

```
int SimPinInputTimes::puk2Times
```
**描述**

PUK2码剩余次数


### pukTimes

```
int SimPinInputTimes::pukTimes
```
**描述**

PUK码剩余次数


### serial

```
int SimPinInputTimes::serial
```
**描述**

请求的序列号


### times

```
int SimPinInputTimes::times
```
**描述**

剩余次数
