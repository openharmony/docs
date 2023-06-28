# CompVerInfo


## 概述

定义组件版本信息。

**相关模块:**

[Codec](_codec.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [compName](#compname)&nbsp;[[NAME_LENGTH](_codec.md#name_length)] | char<br/>组件名称。&nbsp; | 
| [compUUID](#compuuid)&nbsp;[[UUID_LENGTH](_codec.md#uuid_length)] | uint8_t<br/>组件的UUID标识符。&nbsp; | 
| [compVersion](#compversion) | union&nbsp;OMX_VERSIONTYPE<br/>OMX组件版本信息。&nbsp; | 
| [specVersion](#specversion) | union&nbsp;OMX_VERSIONTYPE<br/>构建组件所依据的规范的版本信息。&nbsp; | 


## 类成员变量说明


### compName

  
```
char CompVerInfo::compName[NAME_LENGTH]
```
**描述:**
组件名称。


### compUUID

  
```
uint8_t CompVerInfo::compUUID[UUID_LENGTH]
```
**描述:**
组件的UUID标识符。


### compVersion

  
```
union OMX_VERSIONTYPE CompVerInfo::compVersion
```
**描述:**
OMX组件版本信息。


### specVersion

  
```
union OMX_VERSIONTYPE CompVerInfo::specVersion
```
**描述:**
构建组件所依据的规范的版本信息。
