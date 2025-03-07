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

## 31300002 数据库或事务关闭

**错误信息**

Already closed.

**错误描述**

数据库或事务关闭。

**可能原因**

1. 执行当前操作时，已调用过[close](js-apis-data-graphStore-sys.md#close)接口关闭图数据库或者开库未成功。
2. 执行当前操作时，已调用过[commit](js-apis-data-graphStore-sys.md#commit)接口提交事务或者调用过[rollback](js-apis-data-graphStore-sys.md#rollback)接口回滚事务。

**处理步骤**

1. 使用[getStore](js-apis-data-graphStore-sys.md#graphstoregetstore)接口重新开库，注意入参应与前一次成功开库时的入参保持一致。
2. 使用[createTransaction](js-apis-data-graphStore-sys.md#createtransaction)接口重新创建事务。

## 31300003 数据库BUSY

**错误信息**

The database is busy.

**错误描述**

数据库BUSY。

**可能原因**

1. 同一应用多个进程同时打开了同一个数据库，进行读写操作。
2. 进程内多线程同时进行读写操作，导致某一线程读写操作超时。
3. 存在一个事务调用过[write](js-apis-data-graphStore-sys.md#write)接口写入数据但未提交或回滚。

**处理步骤**

1. 避免进程并发操作数据库。
2. 等待一段时间重试。
3. 提交或回滚未关闭的事务。

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

使用[GraphStore.write](js-apis-data-graphStore-sys.md#write-1)或[Transaction.write](js-apis-data-graphStore-sys.md#write)接口删除同系列数据后再插入。

## 31300006 存在重复的图名、顶点的类型或属性、边的类型或属性

**错误信息**

A duplicate graph name, vertex or edge type, or vertex or edge property name exists.

**错误描述**

存在重复的图名、顶点的类型或属性、边的类型或属性。

**可能原因**

1. 数据库内已存在同名的图。
2. 不同顶点使用了相同的类型或属性。
3. 不同边使用了相同的类型或属性。

**处理步骤**

使用[GraphStore.write](js-apis-data-graphStore-sys.md#write-1)或[Transaction.write](js-apis-data-graphStore-sys.md#write)接口创建图时，检查建图语句中图名、顶点的类型（[Vertex.labels](js-apis-data-graphStore-sys.md#vertex)）或属性（[Vertex.properties](js-apis-data-graphStore-sys.md#vertex)）以及边的类型（[Edge.type](js-apis-data-graphStore-sys.md#edge)）或属性（[Edge.labels](js-apis-data-graphStore-sys.md#edge)）是否存在上述冲突。

## 31300007 未定义图名、顶点和边的类型或属性

**错误信息**

The graph name, vertex or edge type, or vertex or edge property is not defined.

**错误描述**

未定义图名、顶点和边的类型或属性。

**可能原因**

存在图名、顶点和边的类型或属性未被定义。

**处理步骤**

使用[GraphStore.write](js-apis-data-graphStore-sys.md#write-1)或[Transaction.write](js-apis-data-graphStore-sys.md#write)接口创建图或插入顶点和边时，检查本次创建图的图名或插入的顶点的类型（[Vertex.labels](js-apis-data-graphStore-sys.md#vertex)）或属性（[Vertex.properties](js-apis-data-graphStore-sys.md#vertex)）以及边的类型（[Edge.type](js-apis-data-graphStore-sys.md#edge)）或属性（[Edge.labels](js-apis-data-graphStore-sys.md#edge)）是否在创建图时已定义。

## 31300008 图名、顶点和边的类型或属性不符合约束

**错误信息**

The graph name, vertex or edge type, or vertex or edge property name does not conform to constraints.

**错误描述**

图名、顶点和边的类型或属性不符合约束。

**可能原因**

1. 图名长度超过上限（128字节）。
2. 主键冲突。
3. 唯一索引冲突。

**处理步骤**

使用[GraphStore.write](js-apis-data-graphStore-sys.md#write-1)或[Transaction.write](js-apis-data-graphStore-sys.md#write)接口创建图时，检查建图语句中图名、顶点的类型（[Vertex.labels](js-apis-data-graphStore-sys.md#vertex)）或属性（[Vertex.properties](js-apis-data-graphStore-sys.md#vertex)）以及边的类型（[Edge.type](js-apis-data-graphStore-sys.md#edge)）或属性（[Edge.labels](js-apis-data-graphStore-sys.md#edge)）是否符合上述约束。

## 31300009 GQL语句语法错误

**错误信息**

The GQL statement syntax error.

**错误描述**

GQL语句语法错误。

**可能原因**

GQL语句语法错误。

**处理步骤**

参照行业标准，检查修改确保GQL语句语法正确。

## 31300010 GQL语句语义错误

**错误信息**

The GQL statement semantic error.

**错误描述**

GQL语句语义错误。

**可能原因**

GQL语句语义错误。

**处理步骤**

参照行业标准，检查修改确保GQL语句语义正确。

## 31300012 图、顶点和边的类型或属性数量超过了上限

**错误信息**

The number of graph names, vertex or edge types, or vertex or edge properties exceeds the limit.

**错误描述**

图、顶点和边的类型或属性数量超过了上限。

**可能原因**

图、顶点和边的类型或属性数量超过了上限。

**处理步骤**

减少顶点和边的类型或属性数量。同一个数据库内，仅可创建一个图，顶点和边的属性上限均为1024个。

## 31300013 冲突约束已存在

**错误信息**

A conflicting constraint already exists.

**错误描述**

冲突约束已存在。

**可能原因**

主键冲突、唯一索引冲突或其他语法约束冲突。

**处理步骤**

参照行业标准，检查修改确保GQL语句无上述冲突存在。

## 31300014 数据库路径不合法

**错误信息**

Invalid database path.

**错误描述**

数据库路径不合法。

**可能原因**

数据库路径没有权限访问。

**处理步骤**

图数据库暂不支持自定义路径，目前仅支持使用[Context](../apis-ability-kit/js-apis-inner-app-context.md)中默认沙箱路径。请参考[getStore](js-apis-data-graphStore-sys.md#graphstoregetstore)接口示例代码进行修正。

## 31300015 关键配置已被更改

**错误信息**

Config changed.

**错误描述**

数据库关键配置已被更改。

**可能原因**

数据库的name（名称），securityLevel（安全级别），encrypt（是否加密）等关键配置发生变化。

**处理步骤**

保持原配置不变或者用原配置导出数据，删除旧库，用新配置创建新库，数据存入新库。支持安全级别从低到高变更。