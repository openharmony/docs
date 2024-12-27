# 图数据库错误码

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

##  31300000 内部错误

**错误信息**

Inner error.

**错误描述**

内部错误。

**可能原因**

优先查看错误日志，通过日志可以详细了解错误原因，主要有以下几种：
1. gql执行异常。
2. 内部状态异常。
3. 错误地使用接口。
4. 系统错误，如空指针、数据服务异常重启、I/O错误、JS引擎异常等。

**处理步骤**

1. 开发者排查是否按接口文档正确使用接口。
2. 尝试重试，如果依然无法解决，可以提示用户重启应用、升级应用或升级设备版本。

##  31300001 数据库文件损坏

**错误信息**

Database corrupted.

**错误描述**

该错误码表示在调用数据库read、write等接口时，数据库已损坏。

**可能原因**

调用数据库read、write等接口操作数据库时，数据库文件已损坏。

**处理步骤**

目前暂不支持图数据库的备份、恢复，如果可以接受数据库数据丢失，则可尝试删除数据库后重新创建。

## 31300002 数据库关闭

**错误信息**

Already closed.

**错误描述**

数据库关闭。

**可能原因**

GraphStore对象，打开失败或者已调用过[close](js-apis-data-graphStore-sys.md#close)接口关库。

**处理步骤**

使用[getStore](js-apis-data-graphStore-sys.md#graphstoregetstore)接口重新开库，注意保持入参一致。

## 31300003 数据库BUSY

**错误信息**

The database is busy.

**错误描述**

数据库BUSY。

**可能原因**

同一应用多个进程同时打开了同一个数据库，进行读写操作。

**处理步骤**

1. 避免进程并发操作数据库。
2. 等待一段时间重试。

## 31300004 数据库内存不足

**错误信息**

The database is out of memory.

**错误描述**

数据库内存不足。

**可能原因**
 
数据库内存不足，可能是由于数据量过大或内存分配不足导致的。

**处理步骤**

减小数据量或尝试通过清理其他进程增加内存分配。

## 31300005 数据库已满

**错误信息**

The database is full.

**错误描述**

数据库已满。

**可能原因**

数据库已满，可能是由于当前db数据量已达上限或磁盘空间不足导致的。

**处理步骤**

使用[write](js-apis-data-graphStore-sys.md#write)接口删除同系列数据后再插入。

## 31300006 顶点和边的类型或特性名称重复

**错误信息**

Duplicate type or properties name of vertex and edge.

**错误描述**

顶点和边的类型或特性名称重复。

**可能原因**

不同顶点或边使用了相同的类型或特性名称。

**处理步骤**

使用[write](js-apis-data-graphStore-sys.md#write)接口插入顶点和边时，检查本次插入的顶点的类型（[Vertex](js-apis-data-graphStore-sys.md#vertex).labels）或特性名称（[Vertex](js-apis-data-graphStore-sys.md#vertex).properties）以及边的类型（[Edge](js-apis-data-graphStore-sys.md#edge).type）或特性名称（[Edge](js-apis-data-graphStore-sys.md#edge).labels）是否冲突。

## 31300007 未定义顶点和边的类型或属性

**错误信息**

The type or properties of vertex and edge is not defined.

**错误描述**

未定义顶点和边的类型或属性。

**可能原因**

存在顶点和边的类型或属性未被定义。

**处理步骤**

使用[write](js-apis-data-graphStore-sys.md#write)接口插入顶点和边时，检查本次插入的顶点的类型（[Vertex](js-apis-data-graphStore-sys.md#vertex).labels）或特性名称（[Vertex](js-apis-data-graphStore-sys.md#vertex).properties）以及边的类型（[Edge](js-apis-data-graphStore-sys.md#edge).type）或特性名称（[Edge](js-apis-data-graphStore-sys.md#edge).labels）是否在创建图时已定义。

## 31300008 顶点和边的类型或特性名称不符合约束

**错误信息**

The type or properties name of vertex and edge does not conform to constraint.

**错误描述**

顶点和边的类型或特性名称不符合约束。

**可能原因**

存在顶点和边的类型或特性名称不符合约束。

**处理步骤**

使用[write](js-apis-data-graphStore-sys.md#write)接口插入顶点和边时，检查本次插入的顶点的类型（[Vertex](js-apis-data-graphStore-sys.md#vertex).labels）或特性名称（[Vertex](js-apis-data-graphStore-sys.md#vertex).properties）以及边的类型（[Edge](js-apis-data-graphStore-sys.md#edge).type）或特性名称（[Edge](js-apis-data-graphStore-sys.md#edge).labels）是否符合约束。

## 31300009 GQL语句语法错误

**错误信息**

The GQL statement syntax error.

**错误描述**

GQL语句语法错误。

**可能原因**

GQL语句语法错误。

**处理步骤**

检查GQL语句。可参考行业标准。

## 31300010 GQL语句语义错误

**错误信息**

The GQL statement semantic error.

**错误描述**

GQL语句语义错误。

**可能原因**

GQL语句语义错误。

**处理步骤**

检查GQL语句。可参考行业标准。

## 31300012 顶点和边的类型或属性数量超过了上限

**错误信息**

The number of types or properties of vertex and edge exceeds the upper limit.

**错误描述**

顶点和边的类型或属性数量超过了上限。

**可能原因**

顶点和边的类型或属性数量超过了上限。

**处理步骤**

减少顶点和边的类型或属性数量。顶点上限为2000个，边上限为10000条。

## 31300013 冲突约束已存在

**错误信息**

A conflicting constraint already exists.

**错误描述**

冲突约束已存在。

**可能原因**

主键冲突、唯一索引冲突或其他语法约束冲突。

**处理步骤**

检查GQL语句。可参考行业标准。

## 31300014 数据库路径不合法

**错误信息**

Invalid database path.

**错误描述**

数据库路径不合法。

**可能原因**

无效的数据库路径。

**处理步骤**

检查传入数据库路径。

## 31300015 关键配置已被更改

**错误信息**

Config changed.

**错误描述**

数据库关键配置已被更改。

**可能原因**

数据库的name（名称）, securityLevel（安全级别）等关键配置发生变化。

**处理步骤**

保持原配置不变或者用原配置导出数据，删除旧库，用新配置创建新库，数据存入新库。支持安全级别从低到高变更。