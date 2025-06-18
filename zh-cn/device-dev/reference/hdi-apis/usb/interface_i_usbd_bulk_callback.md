# IUsbdBulkCallback


## 概述

SB驱动的回调函数。

当USB驱动进行批量传输异步读/写数据时调用回调函数，处理对应的结果。

**起始版本：** 5.1

**相关模块：**[HdiUsb](_hdi_usb_v2_0.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [OnBulkWriteCallback](#onbulkwritecallback) ([in] int status, [in] int actLength) | 批量写数据的回调函数。 | 
| [OnBulkReadCallback()](#onbulkreadcallback) ([in] int status, [in] int actLength) | 批量读数据的回调函数。 | 


## 成员函数说明


### OnBulkReadCallback()

```
IUsbdBulkCallback::OnBulkReadCallback ([in] int status, [in] int actLength )
```

**描述**

批量读数据的回调函数。

**起始版本：** 5.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| status | 完成状态。 | 
| actLength | 读数据时实际接收的数据长度。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### OnBulkWriteCallback()

```
IUsbdBulkCallback::OnBulkWriteCallback ([in] int status, [in] int actLength )
```

**描述**

批量写数据的回调函数。

**起始版本：** 5.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| status | 完成状态。 | 
| actLength | 写数据时实际发送的数据长度。 | 

**返回：**

0 表示操作成功。

非零值 表示操作失败。
