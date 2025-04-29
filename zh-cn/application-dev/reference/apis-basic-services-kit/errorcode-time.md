# 时间时区服务错误码

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## -1 时间时区服务异常

**错误信息** 

Parameter check failed, permission denied, or system error.

**错误描述**

时间时区服务异常。

**可能原因**

系统运行异常。内存申请、多线程处理等内核通用错误。

**处理步骤**

系统运行异常。请确认内存是否充足。

## 13000001 网络或操作系统异常

**错误信息**

Network connection error or OS error.

**错误描述**

网络或操作系统异常。

**可能原因**

网络或操作系统异常。网络无法连接或无法创建套接字等系统异常。

**处理步骤**

网络或操作系统异常。确认网络连接是否成功，系统资源是否足够。


## 13000002 未更新NTP时间

**错误信息**

Location NTP time of the system is invalid.

**错误描述**

系统本地NTP时间无效。

**可能原因**

系统本地NTP时间无效。在获取NTP时间前，未能成功更新过NTP时间或系统本地NTP时间已失效。

**处理步骤**

系统本地NTP时间无效。调用updateNtpTime()更新NTP时间。