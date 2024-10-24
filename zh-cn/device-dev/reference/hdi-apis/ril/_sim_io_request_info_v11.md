# SimIoRequestInfo


## 概述

SIM数据请求信息。

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v11.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [command](#command) | ME（Mobile Equipment）传递给SIM的命令，参考GSM 51.011[28]  | 
| int [fileId](#fileid) | SIM卡上基本数据文件的标识符  | 
| int [p1](#p1) | SIM数据请求命令参数1，参考3GPP TS 51.011[28]  | 
| int [p2](#p2) | SIM数据请求命令参数2，参考3GPP TS 51.011[28]  | 
| int [p3](#p3) | SIM数据请求命令参数3，参考3GPP TS 51.011[28]  | 
| int [serial](#serial) | 请求的序列号  | 
| String [data](#data) | 要写入SIM的数据信息  | 
| String [path](#path) | SIM卡文件路径，参考ETSI TS 102 221 [60]  | 
| String [pin2](#pin2) | PIN2码  | 
| String [aid](#aid) | 应用标识  | 


## 类成员变量说明


### aid

```
String SimIoRequestInfo::aid
```
**描述**

应用标识


### command

```
int SimIoRequestInfo::command
```
**描述**

ME（Mobile Equipment）传递给SIM的命令，参考GSM 51.011[28]


### data

```
String SimIoRequestInfo::data
```
**描述**

要写入SIM的数据信息


### fileId

```
int SimIoRequestInfo::fileId
```
**描述**

SIM卡上基本数据文件的标识符


### p1

```
int SimIoRequestInfo::p1
```
**描述**

SIM数据请求命令参数1，参考3GPP TS 51.011[28]


### p2

```
int SimIoRequestInfo::p2
```
**描述**

SIM数据请求命令参数2，参考3GPP TS 51.011[28]


### p3

```
int SimIoRequestInfo::p3
```
**描述**

SIM数据请求命令参数3，参考3GPP TS 51.011[28]


### path

```
String SimIoRequestInfo::path
```
**描述**

SIM卡文件路径，参考ETSI TS 102 221 [60]


### pin2

```
String SimIoRequestInfo::pin2
```
**描述**

PIN2码


### serial

```
int SimIoRequestInfo::serial
```
**描述**

请求的序列号
