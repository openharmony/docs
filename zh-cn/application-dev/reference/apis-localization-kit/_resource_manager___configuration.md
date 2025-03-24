# ResourceManager_Configuration


## 概述

设备状态的枚举。

**起始版本：** 12

**相关模块：**[Resourcemanager](resourcemanager.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [ResourceManager_Direction](resourcemanager.md#resourcemanager_direction) [direction](#direction) | 表示屏幕方向。  | 
| char \* [locale](#locale) | 表示语言文字国家地区，如zh-Hans-CN。  | 
| [ResourceManager_DeviceType](resourcemanager.md#resourcemanager_devicetype) [deviceType](#devicetype) | 表示设备类型。  | 
| [ScreenDensity](resourcemanager.md#screendensity) [screenDensity](#screendensity) | 表示屏幕密度。  | 
| [ResourceManager_ColorMode](resourcemanager.md#resourcemanager_colormode) [colorMode](#colormode) | 表示颜色模式。  | 
| uint32_t [mcc](#mcc) | 表示移动国家码。  | 
| uint32_t [mnc](#mnc) | 表示移动网络码。  | 
| uint32_t [reserved](#reserved)  | 保留属性。  | 


## 结构体成员变量说明


### colorMode

```
ResourceManager_ColorMode ResourceManager_Configuration::colorMode
```
**描述**

表示颜色模式。


### deviceType

```
ResourceManager_DeviceType ResourceManager_Configuration::deviceType
```
**描述**

表示设备类型。


### direction

```
ResourceManager_Direction ResourceManager_Configuration::direction
```
**描述**

表示屏幕方向。


### locale

```
char* ResourceManager_Configuration::locale
```
**描述**

表示语言文字国家地区，如zh-Hans-CN。


### mcc

```
uint32_t ResourceManager_Configuration::mcc
```
**描述**

表示移动国家码。


### mnc

```
uint32_t ResourceManager_Configuration::mnc
```
**描述**

表示移动网络码。


### reserved

```
uint32_t ResourceManager_Configuration::reserved[20]
```
**描述**

保留属性。


### screenDensity

```
ScreenDensity ResourceManager_Configuration::screenDensity
```
**描述**

表示屏幕密度。
