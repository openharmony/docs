# IUsbfnMtpInterface


## 概述

定义在usb上执行基本操作的函数。

操作包括获取usb信息、订阅或取消订阅usb数据、启用或禁用usb、设置usb数据报告模式以及设置准确性和测量范围等usb选项。

**起始版本：** 4.0

**相关模块：**[HdiUsbfnMtp](_hdi_usbfn_mtp.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [Start](#start) () | 打开USB MTP/PTP驱动程序。 | 
| [Stop](#stop) () | 关闭USB MTP/PTP驱动程序。 | 
| [Read](#read) ([out] unsigned char[] data) | 通过USB MTP/PTP驱动程序读取数据。 | 
| [Write](#write) ([in] unsigned char[] data) | 通过USB MTP/PTP驱动程序写入数据。 | 
| [ReceiveFile](#receivefile) ([in] struct [UsbFnMtpFileSlice](_usb_fn_mtp_file_slice.md) mfs) | 通过USB MTP/PTP驱动程序接收文件。 代理处理文件管理，包括fopen/fclose/feek/fread/fwrite和偏移量信息，Stub负责数据处理。 | 
| [SendFile](#sendfile) ([in] struct [UsbFnMtpFileSlice](_usb_fn_mtp_file_slice.md) mfs) | 通过USB MTP/PTP驱动程序发送文件。 代理处理文件管理，包括fopen/fclose/feek/fread/fwrite和偏移量信息，Stub负责数据处理。 | 
| [SendEvent](#sendevent) ([in] unsigned char[] eventData) | 通过USB MTP/PTP驱动程序发送事件数据。 | 
| [Init](#init) () | 初始化USB MTP/PTP驱动程序。由usb_host使用。 | 
| [Release](#release) () | 释放USB MTP/PTP驱动程序。由usb_host使用。 | 


## 成员函数说明


### Init()

```
IUsbfnMtpInterface::Init ()
```

**描述**


初始化USB MTP/PTP驱动程序。由usb_host使用。

**起始版本：** 4.0

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### Read()

```
IUsbfnMtpInterface::Read ([out] unsigned char[] data)
```

**描述**


通过USB MTP/PTP驱动程序读取数据。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| data | 表示USB MTP/PTP驱动程序读取的数据。 | 

**返回：**

如果操作成功返回读出的字节数，操作失败则返回-1或其他负值。


### ReceiveFile()

```
IUsbfnMtpInterface::ReceiveFile ([in] struct UsbFnMtpFileSlice mfs)
```

**描述**


通过USB MTP/PTP驱动程序接收文件。 代理处理文件管理，包括fopen/fclose/feek/fread/fwrite和偏移量信息，Stub负责数据处理。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mfs | 指示mtp文件切片信息。 | 

**返回：**

如果接收成功，则返回**0**；如果操作失败，则返回**-1**或其他负值。


### Release()

```
IUsbfnMtpInterface::Release ()
```

**描述**


释放USB MTP/PTP驱动程序。由usb_host使用。

**起始版本：** 4.0

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### SendEvent()

```
IUsbfnMtpInterface::SendEvent ([in] unsigned char[] eventData)
```

**描述**


通过USB MTP/PTP驱动程序发送事件数据。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| data | 指示事件数据写入USB MTP/PTP驱动程序。 | 

**返回：**

如果接收成功，则返回**0**；如果操作失败，则返回**-1**或其他负值。


### SendFile()

```
IUsbfnMtpInterface::SendFile ([in] struct UsbFnMtpFileSlice mfs)
```

**描述**


通过USB MTP/PTP驱动程序发送文件。 代理处理文件管理，包括fopen/fclose/feek/fread/fwrite和偏移量信息，Stub负责数据处理。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mfs | 指示mtp文件范围信息，使用的是数据包标头。 | 

**返回：**

如果接收成功，则返回**0**；如果操作失败，则返回**-1**或其他负值。


### Start()

```
IUsbfnMtpInterface::Start ()
```

**描述**


打开USB MTP/PTP驱动程序。

**起始版本：** 4.0

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### Stop()

```
IUsbfnMtpInterface::Stop ()
```

**描述**


关闭USB MTP/PTP驱动程序。

**起始版本：** 4.0

**返回：**

0 表示操作成功。

非零值 表示操作失败。


### Write()

```
IUsbfnMtpInterface::Write ([in] unsigned char[] data)
```

**描述**


通过USB MTP/PTP驱动程序写入数据。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| 通过USB | MTP/PTP驱动程序写入数据。data表示数据写入USB MTP/PT驱动程序。 | 

**返回：**

如果操作成功返回写入的字节数，操作失败则返回-1或其他负值。
