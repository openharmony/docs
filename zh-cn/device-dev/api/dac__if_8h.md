# dac_if.h


## **概述**

**所属模块:**

[DAC](_d_a_c.md)


## **汇总**


### 类

  | 类 | 描述 | 
| -------- | -------- |
| [DacIoMsg](_dac_io_msg.md) | DAC设备信息传输结构体&nbsp;[更多...](_dac_io_msg.md) | 


### 函数

  | 函数 | 描述 | 
| -------- | -------- |
| [DacOpen](_d_a_c.md#dacopen)&nbsp;(uint32_t&nbsp;number) | 获取DAC控制器的句柄。&nbsp;[更多...](_d_a_c.md#dacopen) | 
| [DacClose](_d_a_c.md#dacclose)&nbsp;(DevHandle&nbsp;handle) | 释放DAC控制器的句柄。&nbsp;[更多...](_d_a_c.md#dacclose) | 
| [DacWrite](_d_a_c.md#dacwrite)&nbsp;(DevHandle&nbsp;handle,&nbsp;uint32_t&nbsp;channel,&nbsp;uint32_t&nbsp;val) | 启动DAC设备进行传输，将目标值写入指定的DAC通道。&nbsp;[更多...](_d_a_c.md#dacwrite) | 


## **详细描述**

声明标准DAC接口函数。

**Since：**

3.1
