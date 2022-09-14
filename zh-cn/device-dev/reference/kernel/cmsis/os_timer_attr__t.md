# osTimerAttr_t


## **概述**

**Related Modules:**

[CMSIS](_c_m_s_i_s-_r_t_o_s.md)


## **汇总**


### 成员变量

  | 成员变量&nbsp;Name | 描述 | 
| -------- | -------- |
| [name](#name) | 定时器名称。 | 
| [attr_bits](#attr_bits) | 定时器属性位。 | 
| [cb_mem](#cb_mem) | 定时器控制块指针。 | 
| [cb_size](#cb_size) | 定时器控制块大小。 | 


## **详细描述**

定时器参数类型，不支持配置。


## **结构体成员变量说明**


### attr_bits

  
```
uint32_t osTimerAttr_t::attr_bits
```

**Description:**

定时器属性位


### cb_mem

  
```
void* osTimerAttr_t::cb_mem
```

**Description:**

定时器控制块指针


### cb_size

  
```
uint32_t osTimerAttr_t::cb_size
```

**Description:**

定时器控制块大小


### name

  
```
const char* osTimerAttr_t::name
```

**Description:**

定时器名称
