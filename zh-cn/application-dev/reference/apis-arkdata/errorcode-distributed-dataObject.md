# 分布式数据对象错误码

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 15400001 创建内存数据库失败

**错误信息**

Failed to create the in-memory database.

**错误描述**

创建内存数据库失败。

**可能原因**

已有其他分布式数据对象设置了相同的sessionId。

**处理步骤**

使用[genSessionId](../../reference/apis-arkdata/js-apis-data-distributedobject.md#distributeddataobjectgensessionid)生成随机的sessionId，避免和其他分布式数据对象使用相同的sessionId。
