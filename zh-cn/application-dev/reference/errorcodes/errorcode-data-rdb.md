# 关系型数据库错误码

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](errorcode-universal.md)。

##  14800000 内部错误

**错误信息**

Inner error.

**错误描述**

数据库底层发生错误。

**可能原因**

传入SQL语句非法等。

**处理步骤**

需通过日志信息确认错误发生原因。

## 14800010 数据库路径不合法

**错误信息**

Failed to open or delete database by invalid database path.

**错误描述**

数据库路径不合法。

**可能原因**

无效的数据库路径。

**处理步骤**

检查传入数据库路径。

## 14800011 数据库文件损坏

**错误信息**

Failed to open database by database corrupted.

**错误描述**

该错误码表示在调用数据库增、删、查、数据同步等接口时，数据库已损坏。

**可能原因**

调用数据库增、删、查、数据同步等接口操作数据库时，数据库文件已损坏。

**处理步骤**

1. 如果之前备份过数据库，可尝试使用已备份的数据库文件恢复数据库。
2. 如果之前没有备份过数据库，可尝试删除数据库后重新创建。

## 14800012 结果集为空或指定位置不合法

**错误信息**

The result set is empty or the specified location is invalid.

**错误描述**

结果集为空或指定位置不合法。

**可能原因**

结果集为空或结果集指定行号超出位置范围[0, m - 1]，m = resultsetV9.rowCount。

**处理步骤**

检查当前操作得到的结果集是否为空或指定的位置是否合法。

## 14800013 列值为空或列类型与当前调用接口不兼容

**错误信息**

The column value is  null or the column type is incompatible.

**错误描述**

列值为空或列类型与当前调用接口不兼容。

**可能原因**

1. 结果集为空。
2. 结果集当前行号超出范围[0, m - 1]，m = resultsetV9.rowCount。
3. 当前列号超出范围[0, n - 1]，n = resultsetV9.columnCount。
4. 当前列数据类型接口不支持。

**处理步骤**

1. 检查结果集是否为空。
2. 检查结果集当前行号、列号是否超出范围。
3. 检查当前列数据类型是否支持。

## 14800047 WAL文件大小超过默认上限

**错误信息**

The WAL file size exceeds the default limit.

**错误描述**

WAL文件大小超过默认上限（200M）。

**可能原因**

在开启读事务或者结果集未关闭的情况下，不断执行增删改操作，导致WAL文件大小超过默认上限。

**处理步骤**

检查结果集或者事务是否未关闭。

关闭所有的结果集或者事务。

## 14800050 获取订阅服务失败

**错误信息**

Failed to obtain subscription service.

**错误描述**

获取订阅服务失败。

**可能原因**

当前平台不支持订阅服务。

**处理步骤**

需要在当前平台部署订阅服务。

## 14801001 上下文环境非Stage模型

**错误信息**

 Only supported in stage mode.

**错误描述**

该操作仅支持Stage模型。

**可能原因**

当前上下文环境非Stage模型。

**处理步骤**

切换当前上下文环境，使用Stage模型。

## 14801002 storeConfig中传入的dataGroupId参数非法

**错误信息**

The data group id is not valid.

**错误描述**

使用非法dataGroupId参数。

**可能原因**

使用的dataGroupId不是从应用市场正常申请的。

**处理步骤**

从应用市场申请dataGroupId，并正确传入该参数。

## 14800051 分布式表类型不匹配

**错误信息**

The type of the distributed table does not match.

**错误描述**

对同一数据库表设置的分布式表类型前后不一致。

**可能原因**

对同一数据库表设置的分布式表类型前后不一致，分布式表类型可见[DistributedType](../apis/js-apis-data-relationalStore.md#distributedtype10)。

**处理步骤**

对同一数据库表设置的分布式表类型保持一致，属于端端同步的分布式表不可再设置为用于端云的同步表。