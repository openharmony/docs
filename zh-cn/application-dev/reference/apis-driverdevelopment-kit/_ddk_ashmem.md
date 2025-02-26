# DDK_Ashmem


## 概述

共享内存结构体。

**起始版本：** 

12

**相关模块：**

[Base DDK](_base_ddk.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [ashmemFd](#ashmemfd) | 共享内存的文件描述符。 | 
| [address](#address) | 共享内存映射地址。 | 
| [size](#size) | 数组长度。 | 
| [offset](#offset) | 偏移量。 | 
| [bufferLength](#bufferlength) | 实际使用的数组长度。 | 
| [transferredLength](#transferredlength) | 传输数据的长度。 | 


## 结构体成员变量说明


### ashmemFd


~~~
int32_t ashmemFd
~~~

**描述:**

共享内存的文件描述符。


### address


~~~
const uint8_t * address
~~~

**描述:**

共享内存映射地址。


### size


~~~
const uint32_t size
~~~

**描述:**

数组长度。


### offset


~~~
uint32_t offset
~~~

**描述:**

偏移量。


### bufferLength


~~~
uint32_t bufferLength
~~~

**描述:**

实际使用的数组长度。


### transferredLength


~~~
uint32_t transferredLength
~~~

**描述:**

传输数据的长度。
