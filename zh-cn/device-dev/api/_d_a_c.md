# DAC


## **汇总**


### 文件

  | 文件 | 描述 | 
| -------- | -------- |
| [dac_if.h](dac__if_8h.md) | 声明标准DAC接口函数。 | 


### 类

  | 类 | 描述 | 
| -------- | -------- |
| [DacIoMsg](_dac_io_msg.md) | DAC设备信息传输结构体&nbsp;[更多...](_dac_io_msg.md) | 


### 函数

  | 函数 | 描述 | 
| -------- | -------- |
| [DacOpen](#dacopen)&nbsp;(uint32_t&nbsp;number) | 获取DAC控制器的句柄。&nbsp;[更多...](#dacopen) | 
| [DacClose](#dacclose)&nbsp;(DevHandle&nbsp;handle) | 释放DAC控制器的句柄。&nbsp;[更多...](#dacclose) | 
| [DacWrite](#dacwrite)&nbsp;(DevHandle&nbsp;handle,&nbsp;uint32_t&nbsp;channel,&nbsp;uint32_t&nbsp;val) | 启动DAC设备进行传输，将目标值写入指定的DAC通道。&nbsp;[更多...](#dacwrite) | 


### 变量

  | 变量&nbsp;名称 | 描述 | 
| -------- | -------- |
| [DacIoMsg::number](#number) | DAC设备号 | 
| [DacIoMsg::channel](#channel) | DAC设备通道号 | 


## **详细描述**

提供数模转换器 (DAC) 接口。

该模块允许驱动程序在DAC控制器上执行操作以访问DAC通道上的设备，包括创建和销毁DAC控制器句柄和写入数据。

**Since：**

3.1


## **函数说明**


### DacClose()

  
```
void DacClose (DevHandle handle)
```

**描述：**

释放DAC控制器的句柄。

如果不再需要访问DAC控制器，则应调用该函数关闭其句柄，以释放未使用的内存资源。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| handle | 表示指向DAC控制器的设备句柄的指针。 | 

**Since：**

3.1


### DacOpen()

  
```
DevHandle DacOpen (uint32_t number)
```

**描述：**

获取DAC控制器的句柄。

您必须在访问DAC设备之前调用此函数。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| number | 表示DAC控制器ID。 | 

**返回：**

DAC控制器的DevHandle指针 表示操作成功。

NULL 表示操作失败。

**Since：**

3.1


### DacWrite()

  
```
int32_t DacWrite (DevHandle handle, uint32_t channel, uint32_t val )
```

**描述：**

启动DAC设备进行传输，将目标值写入指定的DAC通道。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| handle | 表示通过DacOpen获取的DAC控制器设备句柄的指针。 | 
| channel | 表示DAC传输消息所通过的通道。 | 
| val | 表示设定的目标值。 | 

**返回：**

0 表示操作成功。

负值 表示操作失败。

**Since：**

3.1


## **变量说明**


### channel

  
```
uint32_t DacIoMsg::channel
```

**描述：**

DAC设备通道号


### number

  
```
uint32_t DacIoMsg::number
```

**描述：**

DAC设备号
