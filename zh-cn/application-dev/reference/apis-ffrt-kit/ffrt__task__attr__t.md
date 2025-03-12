# ffrt_task_attr_t


## 概述

并行任务属性结构。

**起始版本：** 10

**相关模块：**[FFRT](_f_f_r_t.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| uint32_t [storage](#storage) [([ffrt_task_attr_storage_size](_f_f_r_t.md)+sizeof(uint32_t) - 1)/sizeof(uint32_t)] | 任务属性所占空间  | 


## 结构体成员变量说明


### storage

```
uint32_t ffrt_task_attr_t::storage[(ffrt_task_attr_storage_size+sizeof(uint32_t) - 1)/sizeof(uint32_t)]
```
**描述**
任务属性所占空间
