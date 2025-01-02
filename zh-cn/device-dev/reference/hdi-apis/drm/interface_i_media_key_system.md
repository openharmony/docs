# IMediaKeySystem


## 概述

DRM实例功能接口，判断是否支持特定DRM方案，创建DRM实例。

**起始版本：** 4.1

**相关模块：**[HdiDrm](_hdi_drm.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [GetConfigurationString](#getconfigurationstring) ([in] String name, [out] String value) | 获取特定名称属性的字符串值（字符串）。 | 
| [SetConfigurationString](#setconfigurationstring) ([in] String name, [in] String value) | 设置特定名称属性的值（字符串）。 | 
| [GetConfigurationByteArray](#getconfigurationbytearray) ([in] String name, [out] unsigned char[] value) | 获取特定名称属性的值（字节数组）。 | 
| [SetConfigurationByteArray](#setconfigurationbytearray) ([in] String name, [in] unsigned char[] value) | 设置特定名称属性的值（字节数组）。 | 
| [GetStatistics](#getstatistics) ([out] Map&lt; String, String &gt; statistics) | 获取度量统计数据。 | 
| [GetMaxContentProtectionLevel](#getmaxcontentprotectionlevel) ([out] enum [ContentProtectionLevel](_hdi_drm.md#contentprotectionlevel) level) | 获取DRM方案支持的最大内容保护级别。 | 
| [GenerateKeySystemRequest](#generatekeysystemrequest) ([out] String defaultUrl, [out] unsigned char[] request) | 产生证书下载请求。 | 
| [ProcessKeySystemResponse](#processkeysystemresponse) ([in] unsigned char[] response) | 处理下载的证书。 | 
| [GetOemCertificateStatus](#getoemcertificatestatus) ([out] enum [CertificateStatus](_hdi_drm.md#certificatestatus) status) | 获取证书状态。 | 
| [SetCallback](#setcallback) ([in] [IMediaKeySystemCallback](interface_i_media_key_system_callback.md) systemCallback) | 设置DRM实例事件通知接口。 | 
| [CreateMediaKeySession](#createmediakeysession) ([in] enum [ContentProtectionLevel](_hdi_drm.md#contentprotectionlevel) level, [out] [IMediaKeySession](interface_i_media_key_session.md) keySession) | 创建DRM会话。 | 
| [GetOfflineMediaKeyIds](#getofflinemediakeyids) ([out] unsigned char[][] mediaKeyIds) | 获取离线许可证索引（数组）。 | 
| [GetOfflineMediaKeyStatus](#getofflinemediakeystatus) ([in] unsigned char[] mediaKeyId, [out] enum [OfflineMediaKeyStatus](_hdi_drm.md#offlinemediakeystatus) mediaKeyStatus) | 获取离线许可证状态。 | 
| [ClearOfflineMediaKeys](#clearofflinemediakeys) ([in] unsigned char[] mediaKeyId) | 删除离线许可证。 | 
| [GetOemCertificate](#getoemcertificate) ([out] [IOemCertificate](interface_i_oem_certificate.md) oemCert) | 获取证书下载接口。 | 
| [Destroy](#destroy) () | 销毁DRM实例。 | 


## 成员函数说明


### ClearOfflineMediaKeys()

```
IMediaKeySystem::ClearOfflineMediaKeys ([in] unsigned char[] mediaKeyId)
```

**描述**


删除离线许可证。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeyId | 离线许可证索引。 | 

**返回：**

0 表示执行成功。

其他值表示执行失败。


### CreateMediaKeySession()

```
IMediaKeySystem::CreateMediaKeySession ([in] enum ContentProtectionLevel level, [out] IMediaKeySession keySession )
```

**描述**


创建DRM会话。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| level | 待创建会话的内容保护等级。 | 
| keySession | 创建的DRM会话。 | 

**返回：**

0 表示执行成功。

其他值表示执行失败。


### Destroy()

```
IMediaKeySystem::Destroy ()
```

**描述**


销毁DRM实例。

**起始版本：** 4.1

**返回：**

0 表示执行成功。

其他值表示执行失败。


### GenerateKeySystemRequest()

```
IMediaKeySystem::GenerateKeySystemRequest ([out] String defaultUrl, [out] unsigned char[] request )
```

**描述**


产生证书下载请求。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| defaultUrl | 默认的证书服务器URL地址。 | 
| request | 证书下载请求报文，以字节数组定义。 | 

**返回：**

0 表示执行成功。

其他值表示执行失败。


### GetConfigurationByteArray()

```
IMediaKeySystem::GetConfigurationByteArray ([in] String name, [out] unsigned char[] value )
```

**描述**


获取特定名称属性的值（字节数组）。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| name | 属性名。 | 
| value | 返回值。 | 

**返回：**

0 表示执行成功。

其他值表示执行失败。


### GetConfigurationString()

```
IMediaKeySystem::GetConfigurationString ([in] String name, [out] String value )
```

**描述**


获取特定名称属性的字符串值（字符串）。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| name | 属性名。 | 
| value | 返回值。 | 

**返回：**

0 表示执行成功。

其他值表示执行失败。


### GetMaxContentProtectionLevel()

```
IMediaKeySystem::GetMaxContentProtectionLevel ([out] enum ContentProtectionLevel level)
```

**描述**


获取DRM方案支持的最大内容保护级别。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| level | 内容保护级别。 | 

**返回：**

0 表示执行成功。

其他值表示执行失败。


### GetOemCertificate()

```
IMediaKeySystem::GetOemCertificate ([out] IOemCertificate oemCert)
```

**描述**


获取证书下载接口。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| oemCert | 证书下载接口，参见[IOemCertificate](interface_i_oem_certificate.md)。 | 

**返回：**

0 表示执行成功。

其他值表示执行失败。


### GetOemCertificateStatus()

```
IMediaKeySystem::GetOemCertificateStatus ([out] enum CertificateStatus status)
```

**描述**


获取证书状态。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| status | 证书状态。 | 

**返回：**

0 表示执行成功。

其他值表示执行失败。


### GetOfflineMediaKeyIds()

```
IMediaKeySystem::GetOfflineMediaKeyIds ([out] unsigned char mediaKeyIds[][])
```

**描述**


获取离线许可证索引（数组）。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeyIds | 离线许可证索引数组。 | 

**返回：**

0 表示执行成功。

其他值表示执行失败。


### GetOfflineMediaKeyStatus()

```
IMediaKeySystem::GetOfflineMediaKeyStatus ([in] unsigned char[] mediaKeyId, [out] enum OfflineMediaKeyStatus mediaKeyStatus )
```

**描述**


获取离线许可证状态。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeyId | 离线许可证索引。 | 
| mediaKeyStatus | 离线许可证状态。 | 

**返回：**

0 表示执行成功。

其他值表示执行失败。


### GetStatistics()

```
IMediaKeySystem::GetStatistics ([out] Map< String, String > statistics)
```

**描述**


获取度量统计数据。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| statistics | DRM驱动自定义的度量统计数据，以字符串对形式表达。 | 

**返回：**

0 表示执行成功。

其他值表示执行失败。


### ProcessKeySystemResponse()

```
IMediaKeySystem::ProcessKeySystemResponse ([in] unsigned char[] response)
```

**描述**


处理下载的证书。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| response | 下载的证书报文。 | 

**返回：**

0 表示执行成功。

其他值表示执行失败。


### SetCallback()

```
IMediaKeySystem::SetCallback ([in] IMediaKeySystemCallback systemCallback)
```

**描述**


设置DRM实例事件通知接口。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| systemCallback | DRM实例事件通知接口。 | 

**返回：**

0 表示执行成功。

其他值表示执行失败。


### SetConfigurationByteArray()

```
IMediaKeySystem::SetConfigurationByteArray ([in] String name, [in] unsigned char[] value )
```

**描述**


设置特定名称属性的值（字节数组）。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| name | 属性名。 | 
| value | 待设置字节数组。 | 

**返回：**

0 表示执行成功。

其他值表示执行失败。


### SetConfigurationString()

```
IMediaKeySystem::SetConfigurationString ([in] String name, [in] String value )
```

**描述**


设置特定名称属性的值（字符串）。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| name | 属性名。 | 
| value | 待设置字符串。 | 

**返回：**

0 表示执行成功。

其他值表示执行失败。
