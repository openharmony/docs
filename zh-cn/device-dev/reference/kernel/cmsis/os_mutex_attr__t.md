# osMutexAttr_t


## **概述**

**Related Modules:**

[CMSIS](_c_m_s_i_s-_r_t_o_s.md)


## **汇总**


### 成员变量

  | 成员变量&nbsp;Name | 描述 | 
| -------- | -------- |
| [name](#name) | 互斥锁名称。 | 
| [attr_bits](#attr_bits) | 互斥锁属性位。 | 
| [cb_mem](#cb_mem) | 互斥锁控制块指针。 | 
| [cb_size](#cb_size) | 互斥锁控制块大小。 | 


## **详细描述**

互斥锁参数类型，不支持配置。


## **结构体成员变量说明**


### attr_bits

  
```
uint32_t osMutexAttr_t::attr_bits
```

**描述:**

互斥锁属性位


### cb_mem

  
```
void* osMutexAttr_t::cb_mem
```

**描述:**

互斥锁控制块指针


### cb_size

  
```
uint32_t osMutexAttr_t::cb_size
```

**描述:**

互斥锁控制块大小


### name

  
```
const char* osMutexAttr_t::name
```

**描述:**

互斥锁名称
