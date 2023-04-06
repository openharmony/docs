# osMemoryPoolAttr_t


## **概述**

**Related Modules:**

[CMSIS](_c_m_s_i_s-_r_t_o_s.md)


## **汇总**


### 成员变量

  | 成员变量&nbsp;Name | 描述 | 
| -------- | -------- |
| [name](#name) | 内存池名称。 | 
| [attr_bits](#attr_bits) | 内存池属性位。 | 
| [cb_mem](#cb_mem) | 用户指定的控制块指针。 | 
| [cb_size](#cb_size) | 用户指定的控制块大小，单位:&nbsp;字节。 | 
| [mp_mem](#mp_mem) | 用户指定的内存池指针。 | 
| [mp_size](#mp_size) | 用户指定的内存池存储空间的大小，单位:&nbsp;字节。 | 


## **详细描述**

该类型用于初始化内存池的各项配置，使用限制参考[osMemoryPoolNew()](_c_m_s_i_s-_r_t_o_s.md#osmemorypoolnew)。


## **结构体成员变量说明**


### attr_bits

  
```
uint32_t osMemoryPoolAttr_t::attr_bits
```

**描述:**

内存池属性位


### cb_mem

  
```
void* osMemoryPoolAttr_t::cb_mem
```

**描述:**

用户指定的控制块指针


### cb_size

  
```
uint32_t osMemoryPoolAttr_t::cb_size
```

**描述:**

用户指定的控制块大小，单位: 字节


### mp_mem

  
```
void* osMemoryPoolAttr_t::mp_mem
```

**描述:**

用户指定的内存池指针


### mp_size

  
```
uint32_t osMemoryPoolAttr_t::mp_size
```

**描述:**

用户指定的内存池存储空间的大小，单位: 字节


### name

  
```
const char* osMemoryPoolAttr_t::name
```

**描述:**

内存池名称
