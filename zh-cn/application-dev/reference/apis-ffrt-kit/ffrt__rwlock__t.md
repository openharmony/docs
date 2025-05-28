# ffrt_rwlock_t


## 概述

FFRT读写锁结构。

**起始版本：** 18

**相关模块：** [FFRT](_f_f_r_t.md)

**所在头文件：** [type_def.h](type__def_8h.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| uint32_t [storage](#storage) ffrt_rwlock_storage_size+sizeof(uint32_t) - 1)/sizeof(uint32_t)] | FFRT读写锁所占空间  | 


## 结构体成员变量说明


### storage

```
uint32_t ffrt_rwlock_t::storage[(ffrt_rwlock_storage_size+sizeof(uint32_t) - 1)/sizeof(uint32_t)]
```
**描述**
FFRT读写锁所占空间
