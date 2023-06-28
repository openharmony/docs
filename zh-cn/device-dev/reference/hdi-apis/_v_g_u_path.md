# VGUPath


## 概述

路径对象，存放路径命令和坐标数据。

**相关模块:**

[Display](_display.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [segment](_display.md#segment) | uint8_t&nbsp;\*<br/>存放路径命令数据 | 
| [numSegments](_display.md#numsegments) | int32_t<br/>路径命令总数 | 
| [data](_display.md#data-22) | uint8_t&nbsp;\*<br/>存放路径命令对应坐标数据 | 
| [type](_display.md#type-47) | [VGUPathDataType](_display.md#vgupathdatatype)<br/>路径数据存储类型 | 
| [enAlias](_display.md#enalias) | bool<br/>抗锯齿开关 | 
| [boundBox](_display.md#boundbox) | [VGURect](_v_g_u_rect.md)<br/>路径最大边界 | 
