# osThreadAttr_t


## **概述**

**Related Modules:**

[CMSIS](_c_m_s_i_s-_r_t_o_s.md)


## **汇总**


### 成员变量

  | 成员变量&nbsp;Name | 描述 | 
| -------- | -------- |
| [name](#name) | 线程名称。 | 
| [attr_bits](#attr_bits) | 线程属性位。 | 
| [cb_mem](#cb_mem) | 用户指定的控制块指针。 | 
| [cb_size](#cb_size) | 用户指定的控制块大小，单位：字节。 | 
| [stack_mem](#stack_mem) | 用户指定的线程栈指针。 | 
| [stack_size](#stack_size) | 线程栈大小，单位：字节。 | 
| [priority](#priority) | 线程优先级。 | 
| [tz_module](#tz_module) | 线程安全配置。 | 
| [reserved](#reserved) | 线程保留参数。 | 


## **详细描述**

该类型用于初始化线程的各项配置，使用限制参考[osThreadNew()](_c_m_s_i_s-_r_t_o_s.md#osthreadnew)。


## **结构体成员变量说明**


### attr_bits

  
```
uint32_t osThreadAttr_t::attr_bits
```

**Description:**

线程属性位


### cb_mem

  
```
void* osThreadAttr_t::cb_mem
```

**Description:**

用户指定的控制块指针


### cb_size

  
```
uint32_t osThreadAttr_t::cb_size
```

**Description:**

用户指定的控制块大小，单位：字节


### name

  
```
const char* osThreadAttr_t::name
```

**Description:**

线程名称


### priority

  
```
osPriority_t osThreadAttr_t::priority
```

**Description:**

线程优先级


### reserved

  
```
uint32_t osThreadAttr_t::reserved
```

**Description:**

线程保留参数


### stack_mem

  
```
void* osThreadAttr_t::stack_mem
```

**Description:**

用户指定的线程栈指针


### stack_size

  
```
uint32_t osThreadAttr_t::stack_size
```

**Description:**

线程栈大小，单位：字节


### tz_module

  
```
TZ_ModuleId_t osThreadAttr_t::tz_module
```

**Description:**

线程安全配置
