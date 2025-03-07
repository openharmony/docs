# AGnssServerInfo


## 概述

定义AGNSS服务器信息结构体。

**起始版本：** 3.2

**相关模块：**[HdiAGnss](_hdi_a_gnss.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| enum AGnssUserPlaneProtocol [type](#type) | AGNSS用户面协议类型 | 
| String [server](#server) | AGNSS服务器地址 | 
| int [port](#port) | AGNSS服务器端口 | 


## 类成员变量说明


### port

```
int AGnssServerInfo::port
```

**描述**


AGNSS服务器端口


### server

```
String AGnssServerInfo::server
```

**描述**


AGNSS服务器地址


### type

```
enum AGnssUserPlaneProtocol AGnssServerInfo::type
```

**描述**


AGNSS用户面协议类型
