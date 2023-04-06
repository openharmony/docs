# osSemaphoreAttr_t


## **概述**

**Related Modules:**

[CMSIS](_c_m_s_i_s-_r_t_o_s.md)


## **汇总**


### 成员变量

  | 成员变量&nbsp;Name | 描述 | 
| -------- | -------- |
| [name](#name) | 信号量名称。 | 
| [attr_bits](#attr_bits) | 信号量属性位。 | 
| [cb_mem](#cb_mem) | 信号量控制块指针。 | 
| [cb_size](#cb_size) | 信号量控制块大小。 | 


## **详细描述**

信号量参数类型，不支持配置。


## **结构体成员变量说明**


### attr_bits

  
```
uint32_t osSemaphoreAttr_t::attr_bits
```

**描述:**

信号量属性位


### cb_mem

  
```
void* osSemaphoreAttr_t::cb_mem
```

**描述:**

信号量控制块指针


### cb_size

  
```
uint32_t osSemaphoreAttr_t::cb_size
```

**描述:**

信号量控制块大小


### name

  
```
const char* osSemaphoreAttr_t::name
```

**描述:**

信号量名称
