# CompVerInfo


## 概述

定义了组件信息，包含组件名，UUID， 组件版本以及spec版本。

**起始版本：** 4.1

**相关模块：**[Codec](_codec_v20.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| String [compName](#compname) | 组件名称。  | 
| unsigned char[] [compUUID](#compuuid) | 组件的UUID标识符。  | 
| union [OMX_VERSIONTYPE](union_o_m_x___v_e_r_s_i_o_n_t_y_p_e_v20.md)[compVersion](#compversion) | OMX组件版本信息。  | 
| union [OMX_VERSIONTYPE](union_o_m_x___v_e_r_s_i_o_n_t_y_p_e_v20.md)[specVersion](#specversion) | 构建组件所依据的规范的版本信息。  | 


## 类成员变量说明


### compName

```
String CompVerInfo::compName
```
**描述**

组件名称。


### compUUID

```
unsigned char [] CompVerInfo::compUUID
```
**描述**

组件的UUID标识符。


### compVersion

```
union OMX_VERSIONTYPE CompVerInfo::compVersion
```
**描述**

OMX组件版本信息。


### specVersion

```
union OMX_VERSIONTYPE CompVerInfo::specVersion
```
**描述**

构建组件所依据的规范的版本信息。
