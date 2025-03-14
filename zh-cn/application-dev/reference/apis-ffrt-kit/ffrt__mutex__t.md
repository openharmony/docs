# ffrt_mutex_t


## 概述

FFRT互斥锁结构。

**起始版本：** 10

**相关模块：**[FFRT](_f_f_r_t.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| uint32_t [storage](#storage) [([ffrt_mutex_storage_size](_f_f_r_t.md)+sizeof(uint32_t) - 1)/sizeof(uint32_t)] | FFRT互斥锁所占空间  | 


## 结构体成员变量说明


### storage

```
uint32_t ffrt_mutex_t::storage[(ffrt_mutex_storage_size+sizeof(uint32_t) - 1)/sizeof(uint32_t)]
```
**描述**
FFRT互斥锁所占空间
