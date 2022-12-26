# OHOS::AVSession::AVSessionPixelMap


## 概述

读取、设置图片及图片信息。


## 汇总


### Public 成员函数

  | 名称 | 描述 | 
| -------- | -------- |
| [Marshalling](#marshalling)&nbsp;(Parcel&nbsp;&amp;data)&nbsp;const&nbsp;override | 实现图片及图片信息的序列化。&nbsp; | 
| [GetPixelData](#getpixeldata)&nbsp;()&nbsp;const | 获取图片数据。&nbsp; | 
| [SetPixelData](#setpixeldata)&nbsp;(const&nbsp;std::vector&lt;&nbsp;uint8_t&nbsp;&gt;&nbsp;&amp;data) | 设置图片数据。&nbsp; | 
| [GetImageInfo](#getimageinfo)&nbsp;()&nbsp;const | 获取图片信息。&nbsp; | 
| [SetImageInfo](#setimageinfo)&nbsp;(const&nbsp;std::vector&lt;&nbsp;uint8_t&nbsp;&gt;&nbsp;&amp;imageInfo) | 设置图片信息。&nbsp; | 


### 静态 Public 成员函数

  | 名称 | 描述 | 
| -------- | -------- |
| [Unmarshalling](#unmarshalling)&nbsp;(Parcel&nbsp;&amp;data) | 实现图片及图片信息的反序列化。&nbsp; | 


## 成员函数说明


### GetImageInfo()

  
```
std::vector<uint8_t> OHOS::AVSession::AVSessionPixelMap::GetImageInfo () const
```
**描述:**
获取图片信息。

**返回:**

返回图片信息。

**参见:**

[SetImageInfo](#setimageinfo)


### GetPixelData()

  
```
std::vector<uint8_t> OHOS::AVSession::AVSessionPixelMap::GetPixelData () const
```
**描述:**
获取图片数据。

**返回:**

返回图片数据。

**参见:**

[SetPixelData](#setpixeldata)


### Marshalling()

  
```
bool OHOS::AVSession::AVSessionPixelMap::Marshalling (Parcel & data) const
```
**描述:**
实现图片及图片信息的序列化。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| data | 保存序列化值的对象**Parcel**。&nbsp; | 

**返回:**

如果序列化成功，则返回true；失败则返回false。

**参见:**

[Unmarshalling](#unmarshalling)


### SetImageInfo()

  
```
void OHOS::AVSession::AVSessionPixelMap::SetImageInfo (const std::vector< uint8_t > & imageInfo)
```
**描述:**
设置图片信息。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| imageInfo | 图片信息。&nbsp; | 

**参见:**

[GetImageInfo](#getimageinfo)


### SetPixelData()

  
```
void OHOS::AVSession::AVSessionPixelMap::SetPixelData (const std::vector< uint8_t > & data)
```
**描述:**
设置图片数据。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| data | 图片数据。&nbsp; | 

**参见:**

[GetPixelData](#getpixeldata)


### Unmarshalling()

  
```
static AVSessionPixelMap* OHOS::AVSession::AVSessionPixelMap::Unmarshalling (Parcel & data)
```
**描述:**
实现图片及图片信息的反序列化。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| data | 保存反序列化值的对象**Parcel**。&nbsp; | 

**返回:**

如果反序列化成功，则返回true；失败则返回false。

**参见:**

[Marshalling](#marshalling)
