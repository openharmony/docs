# SimPinInputTimes


## 概述

SIM密码输入次数信息。

**相关模块:**

[Ril](_ril.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [serial](#serial) | int<br/>请求的序列号&nbsp; | 
| [times](#times) | int<br/>剩余次数&nbsp; | 
| [pukTimes](#puktimes) | int<br/>PUK码剩余次数&nbsp; | 
| [pinTimes](#pintimes) | int<br/>PIN码剩余次数&nbsp; | 
| [puk2Times](#puk2times) | int<br/>PUK2码剩余次数&nbsp; | 
| [pin2Times](#pin2times) | int<br/>PIN2码剩余次数&nbsp; | 
| [code](#code) | String<br/>请求字段，例如：&nbsp;SIM&nbsp;PIN2：表示SIM卡PIN2码请求&nbsp; | 


## 类成员变量说明


### code

  
```
String SimPinInputTimes::code
```
**描述:**
请求字段，例如： SIM PIN2：表示SIM卡PIN2码请求


### pin2Times

  
```
int SimPinInputTimes::pin2Times
```
**描述:**
PIN2码剩余次数


### pinTimes

  
```
int SimPinInputTimes::pinTimes
```
**描述:**
PIN码剩余次数


### puk2Times

  
```
int SimPinInputTimes::puk2Times
```
**描述:**
PUK2码剩余次数


### pukTimes

  
```
int SimPinInputTimes::pukTimes
```
**描述:**
PUK码剩余次数


### serial

  
```
int SimPinInputTimes::serial
```
**描述:**
请求的序列号


### times

  
```
int SimPinInputTimes::times
```
**描述:**
剩余次数
