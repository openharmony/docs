# ffrt_mutex_t

<!--Kit: Function Flow Runtime Kit-->
<!--Subsystem: Resourceschedule-->
<!--Owner: @chuchihtung; @yanleo-->
<!--Designer: @geoffrey_guo; @huangyouzhong-->
<!--Tester: @lotsof; @sunxuhao-->
<!--Adviser: @foryourself-->

## 概述

FFRT互斥锁结构。

**起始版本：** 10

**相关模块：** [FFRT](capi-ffrt.md)

**所在头文件：** [type_def.h](capi-type-def-h.md)

## 汇总

### 成员变量	

| 名称 | 描述 |	
| -- | -- |	
| uint32_t storage[(ffrt_mutex_storage_size + sizeof(uint32_t) - 1) / sizeof(uint32_t)] | FFRT互斥锁所占空间 |


