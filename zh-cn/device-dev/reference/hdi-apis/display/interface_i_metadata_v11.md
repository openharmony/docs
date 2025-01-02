# IMetadata


## 概述

定义显示数据映射接口。

**起始版本：** 4.1

**相关模块：**[Display](_display_v11.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [RegisterBuffer](#registerbuffer) ([in] NativeBuffer handle) | IPC后的初始化NativeBuffer | 
| [SetMetadata](#setmetadata) ([in] NativeBuffer handle, [in] unsigned int key, [in] unsigned char[] value) | 通过键值对的方式设置随帧数据 | 
| [GetMetadata](#getmetadata) ([in] NativeBuffer handle, [in] unsigned int key, [out] unsigned char[] value) | 通过键值对的方式设置随帧数据 | 
| [ListMetadataKeys](#listmetadatakeys) ([in] NativeBuffer handle, [out] unsigned int[] keys) | 列出bufferhandle中设置的所有key值 | 
| [EraseMetadataKey](#erasemetadatakey) ([in] NativeBuffer handle, [in] unsigned int key) | 按键值内存删除数据 | 


## 成员函数说明


### EraseMetadataKey()

```
IMetadata::EraseMetadataKey ([in] NativeBuffer handle, [in] unsigned int key )
```

**描述**


按键值内存删除数据

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 待无效cache的handle指针。 | 
| key | 要擦除的元数据密钥 | 

**返回：**

返回0 表示执行成功。

返回其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。


### GetMetadata()

```
IMetadata::GetMetadata ([in] NativeBuffer handle, [in] unsigned int key, [out] unsigned char[] value )
```

**描述**


通过键值对的方式设置随帧数据

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 待无效cache的handle指针。 | 
| key | metadata key | 
| value | metadata value | 

**返回：**

返回0 表示执行成功。

返回其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。


### ListMetadataKeys()

```
IMetadata::ListMetadataKeys ([in] NativeBuffer handle, [out] unsigned int[] keys )
```

**描述**


列出bufferhandle中设置的所有key值

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 待无效cache的handle指针。 | 
| keys | 数据键 | 

**返回：**

返回0 表示执行成功。

返回其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。


### RegisterBuffer()

```
IMetadata::RegisterBuffer ([in] NativeBuffer handle)
```

**描述**


IPC后的初始化NativeBuffer

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 待无效cache的handle指针。 | 

**返回：**

返回0 表示执行成功。

返回其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。


### SetMetadata()

```
IMetadata::SetMetadata ([in] NativeBuffer handle, [in] unsigned int key, [in] unsigned char[] value )
```

**描述**


通过键值对的方式设置随帧数据

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 待无效cache的handle指针。 | 
| key | 数据键 | 
| value | 数据值 | 

**返回：**

返回0 表示执行成功。

返回其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。
