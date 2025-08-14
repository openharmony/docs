# 开放匿名设备标识服务错误码

<!--Kit: Ads Kit-->
<!--Subsystem: Advertising-->
<!--Owner: @SukiEvas-->
<!--SE: @zhansf1988-->
<!--TSE: @hongmei_may-->

> **说明：**<br/>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 17300001 系统内部错误

**错误信息**

System internal error.

**错误描述**

系统内部错误。

**可能原因**

连接服务失败。

**处理步骤**

检查系统服务是否运行正常。

## 17300002 不在信任列表中

**错误信息**

Not in the trust list.

**错误描述**

该系统应用不在信任列表中。

**可能原因**

不在信任列表中的系统应用调用接口。

**处理步骤**

系统应用配置到[信任列表](../../ads-service/oaid/oaid-service-sys.md)中。