# IOemCertificate


## 概述

厂商证书下载接口。 产生证书下载请求，处理下载的证书。

**起始版本：** 4.1

**相关模块：**[HdiDrm](_hdi_drm.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [GenerateOemKeySystemRequest](#generateoemkeysystemrequest) ([out] String defaultUrl, [out] unsigned char[] request) | 产生证书下载请求。  | 
| [ProcessOemKeySystemResponse](#processoemkeysystemresponse) ([in] unsigned char[] response) | 处理下载的证书。  | 


## 成员函数说明


### GenerateOemKeySystemRequest()

```
IOemCertificate::GenerateOemKeySystemRequest ([out] String defaultUrl, [out] unsigned char[] request )
```
**描述**

产生证书下载请求。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| defaultUrl | 默认的证书服务器URL地址。  | 
| request | 证书下载请求报文，以字节数组定义。 | 

**返回：**

0 表示执行成功。

其他值表示执行失败。


### ProcessOemKeySystemResponse()

```
IOemCertificate::ProcessOemKeySystemResponse ([in] unsigned char[] response)
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
