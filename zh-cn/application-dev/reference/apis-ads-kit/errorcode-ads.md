# 广告服务框架错误码

<!--Kit: Ads Kit-->
<!--Subsystem: Advertising-->
<!--Owner: @SukiEvas-->
<!--Designer: @zhansf1988-->
<!--Tester: @hongmei_may-->
<!--Adviser: @RayShih-->

> **说明：**<br/>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 21800001 系统内部错误

**错误信息**

System internal error.

**错误描述**

系统内部错误。

**可能原因**

连接服务失败。

**处理步骤**

检查系统服务是否运行正常。

## 21800003 广告请求加载失败

**错误信息**

Failed to load the ad request.

**错误描述**

广告请求加载失败。

**可能原因**

1. 网络连接异常。

2. 广告请求参数错误。

3. 服务器无合适广告填充。

**处理步骤**

1. 请检查网络状态。

2. 请根据API参考检查广告请求参数是否符合要求。

## 21800004 广告展示失败

**错误信息**

Failed to display the ad.

**错误描述**

广告展示失败。

**可能原因**

网络连接异常。

**处理步骤**

请检查网络状态。

## 21800005 广告数据解析失败

**错误信息**

Failed to parse the ad response.

**错误描述**

广告数据解析失败。

**可能原因**

广告响应数据缺失关键属性或存在结构错误。

**处理步骤**

请检查广告响应数据。

## 401 请求广告参数错误

**错误信息**

Invalid input parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.

**错误描述**

请求广告参数错误。

**可能原因**

媒体在写入请求广告参数，校验异常等。

**处理步骤**

参考开发指导文档检查广告请求参数是否正确。

## 801 请求广告返回错误码

**错误信息**

Device not supported.

**错误描述**

该设备不支持API，通常用于在设备已支持该SysCap时，针对其少量的API的支持处理。

**可能原因**

该设备不支持此API。

**处理步骤**

请检查该设备是否支持使用的API。