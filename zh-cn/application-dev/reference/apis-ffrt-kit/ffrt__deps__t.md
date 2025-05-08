# ffrt_deps_t


## 概述

依赖结构定义。

**起始版本：** 10

**相关模块：** [FFRT](_f_f_r_t.md)

**所在头文件：** [type_def.h](type__def_8h.md)

## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| uint32_t [len](#len) | 依赖数量  | 
| const [ffrt_dependence_t](ffrt__dependence__t.md) \* [items](#items) | 依赖数据  | 


## 结构体成员变量说明


### items

```
const ffrt_dependence_t* ffrt_deps_t::items
```
**描述**
依赖数据


### len

```
uint32_t ffrt_deps_t::len
```
**描述**
依赖数量
