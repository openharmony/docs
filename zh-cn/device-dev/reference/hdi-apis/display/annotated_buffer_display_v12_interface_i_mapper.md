# IMapper


## 概述

定义释放显示内存接口，基于v1_0.IMapper增加获取图像位置接口GetImageLayout。

**起始版本：** 3.2

**相关模块：**[Display](index_buffer_display_v13.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [GetImageLayout](#getimagelayout) ([in] NativeBuffer handle, [out] struct [ImageLayout](annotated_buffer_display_v12_image_layout.md) layout) | 获取图像位置。 | 


## 成员函数说明


### GetImageLayout()

```
IMapper::GetImageLayout([in] NativeBuffer handle, [out] struct ImageLayout layout)
```

**描述**

获取图像位置。

**起始版本：** 5.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 输入句柄指针。 | 
| layout | 图像位置数据。 | 

**返回：**

返回0 表示执行成功。

返回其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。
