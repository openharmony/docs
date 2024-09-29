# MediaLibrary_RequestId


## 概述

定义请求Id。

当请求媒体库资源时，会返回此类型。 请求Id用于取消请求。 如果请求失败，值将全为零，如 "00000000-0000-0000-0000-000000000000"。

**起始版本：** 12

**相关模块：**[MediaAssetManager](_media_asset_manager.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| char [requestId](#requestid) [UUID_STR_MAX_LENGTH] | 定义UUID最大长度。  | 


## 结构体成员变量说明


### requestId

```
char MediaLibrary_RequestId::requestId[UUID_STR_MAX_LENGTH]
```
**描述**
定义UUID最大长度。
