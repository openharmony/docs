# UsbCtrlTransfer


## **概述**

USB设备控制传输信息。

**Since:**

3.2

**Version:**

1.0

**相关模块:**

[USB](usb.md)


## **汇总**


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [requestType](#requesttype) | 请求类型。 | 
| [requestCmd](#requestcmd) | 请求命令。 | 
| [value](#value) | 请求值。 | 
| [index](#index) | 索引值。 | 
| [timeout](#timeout) | 超时时间。 | 


## **类成员变量说明**


### index

  
```
int UsbCtrlTransfer::index
```

**描述：**

索引值。


### requestCmd

  
```
int UsbCtrlTransfer::requestCmd
```

**描述：**

请求命令。


### requestType

  
```
int UsbCtrlTransfer::requestType
```

**描述：**

请求类型。


### timeout

  
```
int UsbCtrlTransfer::timeout
```

**描述：**

超时时间。


### value

  
```
int UsbCtrlTransfer::value
```

**描述：**

请求值。
