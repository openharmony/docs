# osMessageQueueAttr_t


## **概述**

**Related Modules:**

[CMSIS](_c_m_s_i_s-_r_t_o_s.md)


## **汇总**


### 成员变量

  | 成员变量&nbsp;Name | 描述 | 
| -------- | -------- |
| [name](#name) | 消息队列名称。 | 
| [attr_bits](#attr_bits) | 消息队列属性位。 | 
| [cb_mem](#cb_mem) | 用户指定内存的控制块指针。 | 
| [cb_size](#cb_size) | 用户指定内存的控制块大小，单位:&nbsp;字节。 | 
| [mq_mem](#mq_mem) | 用户指定内存作为消息队列空间的指针。 | 
| [mq_size](#mq_size) | 用户指定内存的大小，单位:&nbsp;字节。 | 


## **详细描述**

该类型用于初始化消息队列的各项配置，使用限制参考[osMessageQueueNew()](_c_m_s_i_s-_r_t_o_s.md#osmessagequeuenew)。


## **结构体成员变量说明**


### attr_bits

  
```
uint32_t osMessageQueueAttr_t::attr_bits
```

**描述:**

消息队列属性位


### cb_mem

  
```
void* osMessageQueueAttr_t::cb_mem
```

**描述:**

用户指定内存的控制块指针


### cb_size

  
```
uint32_t osMessageQueueAttr_t::cb_size
```

**描述:**

用户指定内存的控制块大小，单位: 字节


### mq_mem

  
```
void* osMessageQueueAttr_t::mq_mem
```

**描述:**

用户指定内存作为消息队列空间的指针


### mq_size

  
```
uint32_t osMessageQueueAttr_t::mq_size
```

**描述:**

用户指定内存的大小，单位: 字节


### name

  
```
const char* osMessageQueueAttr_t::name
```

**描述:**

消息队列名称
