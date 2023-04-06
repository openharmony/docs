# IUsbdBulkCallback


## **概述**

USB驱动的回调函数。

当USB驱动进行批量传输异步读/写数据时调用回调函数，处理对应的结果。

**Since:**

3.2

**Version:**

1.0

**相关模块:**

[USB](usb.md)


## **汇总**


### Public 成员函数

  | 名称 | 描述 | 
| -------- | -------- |
| [OnBulkWriteCallback](#onbulkwritecallback)&nbsp;([in]&nbsp;int&nbsp;status,&nbsp;[in]&nbsp;int&nbsp;actLength) | 批量写数据的回调函数。 | 
| [OnBulkReadCallback](#onbulkreadcallback)&nbsp;([in]&nbsp;int&nbsp;status,&nbsp;[in]&nbsp;int&nbsp;actLength) | 批量读数据的回调函数。 | 


## **成员函数说明**


### OnBulkReadCallback()

  
```
IUsbdBulkCallback::OnBulkReadCallback ([in] int status, [in] int actLength )
```

**描述：**

批量读数据的回调函数。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| status | 完成状态。 | 
| actLength | 读数据时实际接收的数据长度。 | 

**返回:**

0 表示操作成功。

非零值 表示操作失败。


### OnBulkWriteCallback()

  
```
IUsbdBulkCallback::OnBulkWriteCallback ([in] int status, [in] int actLength )
```

**描述：**

批量写数据的回调函数。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| status | 完成状态。 | 
| actLength | 写数据时实际发送的数据长度。 | 

**返回:**

0 表示操作成功。

非零值 表示操作失败。
