# RDB


## 概述

关系型数据库（Relational Database，RDB）是一种基于关系模型来管理数据的数据库。关系型数据库基于SQLite组件提供了一套完整的 对本地数据库进行管理的机制，对外提供了一系列的增、删、改、查等接口，也可以直接运行用户输入的SQL语句来满足复杂的场景需要。

\@syscap SystemCapability.DistributedDataManager.RelationalStore.Core

**起始版本：**

10


## 汇总


### 文件

| 名称 | 描述 |
| -------- | -------- |
| [oh_cursor.h](oh__cursor_8h.md) | 提供通过查询数据库生成的数据库结果集的访问方法。 |
| [oh_predicates.h](oh__predicates_8h.md) | 表示关系型数据库（RDB）的谓词。 |
| [oh_value_object.h](oh__value__object_8h.md) | 提供类型转换方法。 |
| [oh_values_bucket.h](oh__values__bucket_8h.md) | 用于存储键值对的类型。 |
| [relation_error_code.h](relation__error__code_8h.md) | 声明关系型数据库（RDB）的错误码信息。 |
| [relation_store.h](relation__store_8h.md) | 提供管理关系数据库（RDB）方法的接口。 |


### 结构体

| 名称 | 描述 |
| -------- | -------- |
| [OH_Cursor](_o_h___cursor.md) | 表示结果集。 |
| [OH_Predicates](_o_h___predicates.md) | 表示谓词。 |
| [OH_VObject](_o_h___v_object.md) | 表示允许的数据字段类型。 |
| [OH_VBucket](_o_h___v_bucket.md) | 用于存储键值对的类型。 |
| [OH_Rdb_Config](_o_h___rdb___config.md) | 管理关系数据库配置。 |
| [OH_Rdb_Store](_o_h___rdb___store.md) | 表示数据库类型。 |


### 类型定义

| 名称 | 描述 |
| -------- | -------- |
| [OH_Cursor](#oh_cursor) | 表示结果集。 |
| [OH_Predicates](#oh_predicates) | 表示谓词。 |
| [OH_VObject](#oh_vobject) | 表示允许的数据字段类型。 |
| [OH_VBucket](#oh_vbucket) | 用于存储键值对的类型。 |


### 枚举

| 名称 | 描述 |
| -------- | -------- |
| [OH_ColumnType](#oh_columntype)&nbsp;{<br/>TYPE_NULL&nbsp;=&nbsp;0,&nbsp;TYPE_INT64,&nbsp;TYPE_REAL,&nbsp;TYPE_TEXT,<br/>TYPE_BLOB<br/>} | 数据库字段类型. |
| [OH_OrderType](#oh_ordertype)&nbsp;{&nbsp;ASC&nbsp;=&nbsp;0,&nbsp;DESC&nbsp;=&nbsp;1&nbsp;} | 排序方式。 |
| [OH_Rdb_ErrCode](#oh_rdb_errcode)&nbsp;{&nbsp;RDB_ERR_INVALID_ARGS&nbsp;=&nbsp;-2,&nbsp;RDB_ERR&nbsp;=&nbsp;-1,&nbsp;RDB_ERR_OK&nbsp;=&nbsp;0&nbsp;} | 表示错误码信息。 |
| [OH_Rdb_SecurityLevel](#oh_rdb_securitylevel)&nbsp;{&nbsp;S1&nbsp;=&nbsp;1,&nbsp;S2,&nbsp;S3,&nbsp;S4&nbsp;} | 数据库的安全级别枚举。 |


### 函数

| 名称 | 描述 |
| -------- | -------- |
| [OH_Rdb_CreateValueObject](#oh_rdb_createvalueobject)&nbsp;() | 创建[OH_VObject](_o_h___v_object.md)实例。 |
| [OH_Rdb_CreateValuesBucket](#oh_rdb_createvaluesbucket)&nbsp;() | 创建[OH_VBucket](_o_h___v_bucket.md)实例。 |
| [OH_Rdb_CreatePredicates](#oh_rdb_createpredicates)&nbsp;(const&nbsp;char&nbsp;\*table) | 创建[OH_Predicates](_o_h___predicates.md)实例。 |
| [OH_Rdb_GetOrOpen](#oh_rdb_getoropen)&nbsp;(const&nbsp;[OH_Rdb_Config](_o_h___rdb___config.md)&nbsp;\*config,&nbsp;int&nbsp;\*errCode) | 获得一个相关的[OH_Rdb_Store](_o_h___rdb___store.md)实例，操作关系型数据库。 |
| [OH_Rdb_CloseStore](#oh_rdb_closestore)&nbsp;([OH_Rdb_Store](_o_h___rdb___store.md)&nbsp;\*store) | 销毁[OH_Rdb_Store](_o_h___rdb___store.md)对象，并回收该对象占用的内存。 |
| [OH_Rdb_DeleteStore](#oh_rdb_deletestore)&nbsp;(const&nbsp;char&nbsp;\*path) | 使用指定的数据库文件配置删除数据库。 |
| [OH_Rdb_Insert](#oh_rdb_insert)&nbsp;([OH_Rdb_Store](_o_h___rdb___store.md)&nbsp;\*store,&nbsp;const&nbsp;char&nbsp;\*table,&nbsp;[OH_VBucket](_o_h___v_bucket.md)&nbsp;\*valuesBucket) | 向目标表中插入一行数据。 |
| [OH_Rdb_Update](#oh_rdb_update)&nbsp;([OH_Rdb_Store](_o_h___rdb___store.md)&nbsp;\*store,&nbsp;[OH_VBucket](_o_h___v_bucket.md)&nbsp;\*valuesBucket,&nbsp;[OH_Predicates](_o_h___predicates.md)&nbsp;\*predicates) | 根据指定的条件更新数据库中的数据。 |
| [OH_Rdb_Delete](#oh_rdb_delete)&nbsp;([OH_Rdb_Store](_o_h___rdb___store.md)&nbsp;\*store,&nbsp;[OH_Predicates](_o_h___predicates.md)&nbsp;\*predicates) | 根据指定的条件删除数据库中的数据。 |
| [OH_Rdb_Query](#oh_rdb_query)&nbsp;([OH_Rdb_Store](_o_h___rdb___store.md)&nbsp;\*store,&nbsp;[OH_Predicates](_o_h___predicates.md)&nbsp;\*predicates,&nbsp;const&nbsp;char&nbsp;\*const&nbsp;\*columnNames,&nbsp;int&nbsp;length) | 根据指定条件查询数据库中的数据 |
| [OH_Rdb_Execute](#oh_rdb_execute)&nbsp;([OH_Rdb_Store](_o_h___rdb___store.md)&nbsp;\*store,&nbsp;const&nbsp;char&nbsp;\*sql) | 执行无返回值的SQL语句。 |
| [OH_Rdb_ExecuteQuery](#oh_rdb_executequery)&nbsp;([OH_Rdb_Store](_o_h___rdb___store.md)&nbsp;\*store,&nbsp;const&nbsp;char&nbsp;\*sql) | 根据指定SQL语句查询数据库中的数据。 |
| [OH_Rdb_BeginTransaction](#oh_rdb_begintransaction)&nbsp;([OH_Rdb_Store](_o_h___rdb___store.md)&nbsp;\*store) | 在开始执行SQL语句之前，开始事务。 |
| [OH_Rdb_RollBack](#oh_rdb_rollback)&nbsp;([OH_Rdb_Store](_o_h___rdb___store.md)&nbsp;\*store) | 回滚已经执行的SQL语句。 |
| [OH_Rdb_Commit](#oh_rdb_commit)&nbsp;([OH_Rdb_Store](_o_h___rdb___store.md)&nbsp;\*store) | 提交已执行的SQL语句 |
| [OH_Rdb_Backup](#oh_rdb_backup)&nbsp;([OH_Rdb_Store](_o_h___rdb___store.md)&nbsp;\*store,&nbsp;const&nbsp;char&nbsp;\*databasePath) | 以指定路径备份数据库。 |
| [OH_Rdb_Restore](#oh_rdb_restore)&nbsp;([OH_Rdb_Store](_o_h___rdb___store.md)&nbsp;\*store,&nbsp;const&nbsp;char&nbsp;\*databasePath) | 从指定的数据库备份文件恢复数据库。 |
| [OH_Rdb_GetVersion](#oh_rdb_getversion)&nbsp;([OH_Rdb_Store](_o_h___rdb___store.md)&nbsp;\*store,&nbsp;int&nbsp;\*version) | 获取数据库版本。 |
| [OH_Rdb_SetVersion](#oh_rdb_setversion)&nbsp;([OH_Rdb_Store](_o_h___rdb___store.md)&nbsp;\*store,&nbsp;int&nbsp;version) | 设置数据库版本。 |


### 变量

| 名称 | 描述 |
| -------- | -------- |
| OH_Cursor::id | OH_Cursor结构体的唯一标识符。 |
| [OH_Cursor::getColumnCount](#getcolumncount) | 函数指针，获取结果集中的列数。 |
| [OH_Cursor::getColumnType](#getcolumntype) | 函数指针，根据指定的列索引获取列名。 |
| [OH_Cursor::getColumnIndex](#getcolumnindex) | 函数指针，根据指定的列名获取列索引。 |
| [OH_Cursor::getColumnName](#getcolumnname) | 函数指针，根据指定的列索引获取列名。 |
| [OH_Cursor::getRowCount](#getrowcount) | 函数指针，获取结果集中的行数。 |
| [OH_Cursor::goToNextRow](#gotonextrow) | 函数指针，转到结果集的下一行。 |
| [OH_Cursor::getSize](#getsize) | 函数指针，当结果集中列的数据类型是BLOB或者TEXT时，获取其值所需的内存。 |
| [OH_Cursor::getText](#gettext) | 函数指针，以字符串形式获取当前行中指定列的值。 |
| [OH_Cursor::getInt64](#getint64) | 函数指针，以int64_t形式获取当前行中指定列的值。 |
| [OH_Cursor::getReal](#getreal) | 函数指针，以double形式获取当前行中指定列的值。 |
| [OH_Cursor::getBlob](#getblob) | 函数指针，以字节数组的形式获取当前行中指定列的值。 |
| [OH_Cursor::isNull](#isnull-12) | 函数指针，检查当前行中指定列的值是否为null。 |
| [OH_Cursor::close](#close) | 函数指针，关闭结果集。 |
| [OH_Predicates::id](#id-14) | OH_Predicates结构体的唯一标识符。 |
| [OH_Predicates::equalTo](#equalto) | 函数指针，配置谓词以匹配数据字段等于指定值的字段。 |
| [OH_Predicates::notEqualTo](#notequalto) | 函数指针，配置谓词以匹配数据字段不等于指定值的字段。 |
| [OH_Predicates::beginWrap](#beginwrap) | 函数指针，向谓词添加左括号。 |
| [OH_Predicates::endWrap](#endwrap) | 函数指针，向谓词添加右括号。 |
| [OH_Predicates::orOperate](#oroperate) | 函数指针，将或条件添加到谓词中。 |
| [OH_Predicates::andOperate](#andoperate) | 函数指针，向谓词添加和条件。 |
| [OH_Predicates::isNull](#isnull-22) | 函数指针，配置谓词以匹配值为null的字段。 |
| [OH_Predicates::isNotNull](#isnotnull) | 函数指针，配置谓词以匹配值不为null的指定字段。 |
| [OH_Predicates::like](#like) | 函数指针，配置谓词以匹配数据字段为field且值类似于指定字符串的字段。 |
| [OH_Predicates::between](#between) | 函数指针，将谓词配置为匹配数据字段为field且其值在给定范围内的指定字段。 |
| [OH_Predicates::notBetween](#notbetween) | 函数指针，将谓词配置为匹配数据字段为field且其值超出给定范围内的指定字段。 |
| [OH_Predicates::greaterThan](#greaterthan) | 函数指针，配置谓词以匹配数据字段为field且值大于指定值valueObject的字段。 |
| [OH_Predicates::lessThan](#lessthan) | 函数指针，配置谓词以匹配数据字段为field且值小于指定值valueObject的字段。 |
| [OH_Predicates::greaterThanOrEqualTo](#greaterthanorequalto) | 函数指针，配置谓词以匹配数据字段为field且值大于或等于指定值valueObject的字段。 |
| [OH_Predicates::lessThanOrEqualTo](#lessthanorequalto) | 函数指针，配置谓词以匹配数据字段为field且值小于或等于指定值valueObject的字段。 |
| [OH_Predicates::orderBy](#orderby) | 函数指针，配置谓词以匹配其值按升序或降序排序的列。 |
| [OH_Predicates::distinct](#distinct) | 函数指针，配置谓词以过滤重复记录并仅保留其中一个。 |
| [OH_Predicates::limit](#limit) | 函数指针，设置最大数据记录数的谓词。 |
| [OH_Predicates::offset](#offset) | 函数指针，配置谓词以指定返回结果的起始位置。 |
| [OH_Predicates::groupBy](#groupby) | 函数指针，配置R谓词按指定列分组查询结果。 |
| [OH_Predicates::in](#in) | 函数指针，配置谓词以匹配数据字段为field且值在给定范围内的指定字段。 |
| [OH_Predicates::notIn](#notin) | 函数指针，配置谓词以匹配数据字段为field且值超出给定范围内的指定字段。 |
| [OH_Predicates::clear](#clear-12) | 函数指针，清空谓词。 |
| [OH_Predicates::destroyPredicates](#destroypredicates) | 销毁[OH_Predicates](_o_h___predicates.md)对象，并回收该对象占用的内存。 |
| [OH_VObject::id](#id-24) | OH_VObject结构体的唯一标识符。 |
| [OH_VObject::putInt64](#putint64-22) | 将int64类型的单个参数或者数组转换为[OH_VObject](_o_h___v_object.md)类型的值。 |
| [OH_VObject::putDouble](#putdouble) | 将double类型的单个参数或者数组转换为[OH_VObject](_o_h___v_object.md)类型的值。 |
| [OH_VObject::putText](#puttext-22) | 将char&nbsp;\*类型的字符数组转换为[OH_VObject](_o_h___v_object.md)类型的值。 |
| [OH_VObject::putTexts](#puttexts) | 将char&nbsp;\*类型的字符串数组转换为[OH_VObject](_o_h___v_object.md)类型的值。 |
| [OH_VObject::destroyValueObject](#destroyvalueobject) | 销毁[OH_VObject](_o_h___v_object.md)对象，并回收该对象占用的内存。 |
| [OH_VBucket::id](#id-34) | OH_VBucket结构体的唯一标识符。 |
| [OH_VBucket::capability](#capability) | 表示结构体的存储键值对的数量 |
| [OH_VBucket::putText](#puttext-12) | 将const&nbsp;char\*值放入给定列名的[OH_VBucket](_o_h___v_bucket.md)对象中。 |
| [OH_VBucket::putInt64](#putint64-12) | 将int64_t值放入给定列名的[OH_VBucket](_o_h___v_bucket.md)对象中。 |
| [OH_VBucket::putReal](#putreal) | 将double值放入给定列名的[OH_VBucket](_o_h___v_bucket.md)对象中**。** |
| [OH_VBucket::putBlob](#putblob) | 将const&nbsp;uint8_t&nbsp;\*值放入给定列名的[OH_VBucket](_o_h___v_bucket.md)对象中。 |
| [OH_VBucket::putNull](#putnull) | 将NULL值放入给定列名的[OH_VBucket](_o_h___v_bucket.md)对象中。 |
| [OH_VBucket::clear](#clear-22) | 清空[OH_VBucket](_o_h___v_bucket.md)对象。 |
| [OH_VBucket::destroyValuesBucket](#destroyvaluesbucket) | 销毁[OH_VBucket](_o_h___v_bucket.md)对象，并回收该对象占用的内存。 |
| [OH_Rdb_Config::path](#path) | 数据库文件路径。 |
| [OH_Rdb_Config::isEncrypt](#isencrypt) | 指定数据库是否加密。 |
| [OH_Rdb_Config::securityLevel](#securitylevel) | 设置数据库安全级别[OH_Rdb_SecurityLevel](#oh_rdb_securitylevel)。 |
| [OH_Rdb_Store::id](#id-44) | OH_Rdb_Store结构体的唯一标识符。 |


## 类型定义说明


### OH_Cursor


```
typedef struct OH_Cursor OH_Cursor
```

**描述:**

表示结果集。

提供通过查询数据库生成的数据库结果集的访问方法。


### OH_Predicates


```
typedef struct OH_Predicates OH_Predicates
```

**描述:**

表示谓词。


### OH_VBucket


```
typedef struct OH_VBucket OH_VBucket
```

**描述:**

用于存储键值对的类型。


### OH_VObject


```
typedef struct OH_VObject OH_VObject
```

**描述:**

表示允许的数据字段类型。


## 枚举类型说明


### OH_ColumnType


```
enum OH_ColumnType
```

**描述:**

数据库字段类型.

| 枚举值 | 描述 |
| -------- | -------- |
| TYPE_NULL | 表示NULL类型。 |
| TYPE_INT64 | 表示INT64数据类型。 |
| TYPE_REAL | 表示REAL数据类型。 |
| TYPE_TEXT | 表示TEXT数据类型。 |
| TYPE_BLOB | 表示BLOB数据类型。 |


### OH_OrderType


```
enum OH_OrderType
```

**描述:**

排序方式。

| 枚举值 | 描述 |
| -------- | -------- |
| ASC | 升序排列。 |
| DESC | 降序排列。 |


### OH_Rdb_ErrCode


```
enum OH_Rdb_ErrCode
```

**描述:**

表示错误码信息。

| 枚举值 | 描述 |
| -------- | -------- |
| RDB_ERR_INVALID_ARGS | 参数非法。 |
| RDB_ERR | 执行出错。 |
| RDB_ERR_OK | 执行成功。 |


### OH_Rdb_SecurityLevel


```
enum OH_Rdb_SecurityLevel
```

**描述:**

数据库的安全级别枚举。

| 枚举值 | 描述 |
| -------- | -------- |
| S1 | S1:&nbsp;表示数据库的安全级别为低级别。<br/>当数据泄露时会产生较低影响。 |
| S2 | S2:&nbsp;表示数据库的安全级别为中级别。<br/>当数据泄露时会产生较大影响。 |
| S3 | S3:&nbsp;表示数据库的安全级别为高级别。<br/>当数据泄露时会产生重大影响。 |
| S4 | S4:&nbsp;表示数据库的安全级别为关键级别。<br/>当数据泄露时会产生严重影响。 |


## 函数说明


### OH_Rdb_Backup()


```
int OH_Rdb_Backup (OH_Rdb_Store * store, const char * databasePath )
```

**描述:**

以指定路径备份数据库。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| store | 表示指向[OH_Rdb_Store](_o_h___rdb___store.md)实例的指针。 |
| databasePath | 指定数据库的备份文件路径。 |

**返回:**

返回操作是否成功，出错时返回对应的错误码。

**参见:**

[OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_BeginTransaction()


```
int OH_Rdb_BeginTransaction (OH_Rdb_Store * store)
```

**描述:**

在开始执行SQL语句之前，开始事务。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| store | 表示指向[OH_Rdb_Store](_o_h___rdb___store.md)实例的指针。 |

**返回:**

返回操作是否成功，出错时返回对应的错误码。

**参见:**

[OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_CloseStore()


```
int OH_Rdb_CloseStore (OH_Rdb_Store * store)
```

**描述:**

销毁[OH_Rdb_Store](_o_h___rdb___store.md)对象，并回收该对象占用的内存。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| store | 表示指向[OH_Rdb_Store](_o_h___rdb___store.md)实例的指针。 |

**返回:**

返回操作是否成功，出错时返回对应的错误码。

**参见:**

[OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_Commit()


```
int OH_Rdb_Commit (OH_Rdb_Store * store)
```

**描述:**

提交已执行的SQL语句

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| store | 表示指向[OH_Rdb_Store](_o_h___rdb___store.md)实例的指针。 |

**返回:**

返回操作是否成功，出错时返回对应的错误码。

**参见:**

[OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_CreatePredicates()


```
OH_Predicates* OH_Rdb_CreatePredicates (const char * table)
```

**描述:**

创建[OH_Predicates](_o_h___predicates.md)实例。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| table | 表示数据库表名。 |

**返回:**

创建成功则返回一个指向[OH_Predicates](_o_h___predicates.md)结构体实例的指针，否则返回NULL。

**参见:**

[OH_Predicates](_o_h___predicates.md).


### OH_Rdb_CreateValueObject()


```
OH_VObject* OH_Rdb_CreateValueObject ()
```

**描述:**

创建[OH_VObject](_o_h___v_object.md)实例。

**返回:**

创建成功则返回一个指向[OH_VObject](_o_h___v_object.md)结构体实例的指针，否则返回NULL。

**参见:**

[OH_VObject](_o_h___v_object.md).


### OH_Rdb_CreateValuesBucket()


```
OH_VBucket* OH_Rdb_CreateValuesBucket ()
```

**描述:**

创建[OH_VBucket](_o_h___v_bucket.md)实例。

**返回:**

创建成功则返回一个指向[OH_VBucket](_o_h___v_bucket.md)结构体实例的指针，否则返回NULL。

**参见:**

[OH_VBucket](_o_h___v_bucket.md).


### OH_Rdb_Delete()


```
int OH_Rdb_Delete (OH_Rdb_Store * store, OH_Predicates * predicates )
```

**描述:**

根据指定的条件删除数据库中的数据。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| store | 表示指向[OH_Rdb_Store](_o_h___rdb___store.md)实例的指针。 |
| predicates | 表示指向[OH_Predicates](_o_h___predicates.md)实例的指针，指定删除条件。 |

**返回:**

如果更新成功，返回受影响的行数，否则返回特定的错误码。

**参见:**

[OH_Rdb_Store](_o_h___rdb___store.md), [OH_Predicates](_o_h___predicates.md).


### OH_Rdb_DeleteStore()


```
int OH_Rdb_DeleteStore (const char * path)
```

**描述:**

使用指定的数据库文件配置删除数据库。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| path | 表示数据库路径。 |

**返回:**

返回操作是否成功，出错时返回对应的错误码。


### OH_Rdb_Execute()


```
int OH_Rdb_Execute (OH_Rdb_Store * store, const char * sql )
```

**描述:**

执行无返回值的SQL语句。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| store | 表示指向[OH_Rdb_Store](_o_h___rdb___store.md)实例的指针。 |
| sql | 指定要执行的SQL语句。 |

**返回:**

返回操作是否成功，出错时返回对应的错误码。

**参见:**

[OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_ExecuteQuery()


```
OH_Cursor* OH_Rdb_ExecuteQuery (OH_Rdb_Store * store, const char * sql )
```

**描述:**

根据指定SQL语句查询数据库中的数据。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| store | 表示指向[OH_Rdb_Store](_o_h___rdb___store.md)实例的指针。 |
| sql | 指定要执行的SQL语句。 |

**返回:**

如果查询成功则返回一个指向[OH_Cursor](_o_h___cursor.md)结构体实例的指针，否则返回NULL。

**参见:**

[OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_GetOrOpen()


```
OH_Rdb_Store* OH_Rdb_GetOrOpen (const OH_Rdb_Config * config, int * errCode )
```

**描述:**

获得一个相关的[OH_Rdb_Store](_o_h___rdb___store.md)实例，操作关系型数据库。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| config | 表示指向[OH_Rdb_Config](_o_h___rdb___config.md)实例的指针，与此RDB存储相关的数据库配置。 |
| errCode | 该参数是输出参数，函数执行状态写入该变量。 |

**返回:**

创建成功则返回一个指向[OH_Rdb_Store](_o_h___rdb___store.md)结构体实例的指针，否则返回NULL。

**参见:**

[OH_Rdb_Config](_o_h___rdb___config.md), [OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_GetVersion()


```
int OH_Rdb_GetVersion (OH_Rdb_Store * store, int * version )
```

**描述:**

获取数据库版本。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| store | 表示指向[OH_Rdb_Store](_o_h___rdb___store.md)实例的指针。 |
| version | 表示版本号。 |

**返回:**

返回操作是否成功，出错时返回对应的错误码。

**参见:**

[OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_Insert()


```
int OH_Rdb_Insert (OH_Rdb_Store * store, const char * table, OH_VBucket * valuesBucket )
```

**描述:**

向目标表中插入一行数据。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| store | 表示指向[OH_Rdb_Store](_o_h___rdb___store.md)实例的指针。 |
| table | 表示指定的目标表名。 |
| valuesBucket | 表示要插入到表中的数据行[OH_VBucket](_o_h___v_bucket.md)。 |

**返回:**

如果插入成功，返回行ID。否则返回特定的错误码。

**参见:**

[OH_Rdb_Store](_o_h___rdb___store.md), [OH_VBucket](_o_h___v_bucket.md).


### OH_Rdb_Query()


```
OH_Cursor* OH_Rdb_Query (OH_Rdb_Store * store, OH_Predicates * predicates, const char *const * columnNames, int length )
```

**描述:**

根据指定条件查询数据库中的数据

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| store | 表示指向[OH_Rdb_Store](_o_h___rdb___store.md)实例的指针。 |
| predicates | 表示指向[OH_Predicates](_o_h___predicates.md)实例的指针，指定查询条件。 |
| columnNames | 表示要查询的列。如果值为空，则查询应用于所有列。 |
| length | 表示columnNames数组的长度。 |

**返回:**

如果查询成功则返回一个指向[OH_Cursor](_o_h___cursor.md)结构体实例的指针，否则返回NULL。

**参见:**

[OH_Rdb_Store](_o_h___rdb___store.md), [OH_Predicates](_o_h___predicates.md), [OH_Cursor](_o_h___cursor.md).


### OH_Rdb_Restore()


```
int OH_Rdb_Restore (OH_Rdb_Store * store, const char * databasePath )
```

**描述:**

从指定的数据库备份文件恢复数据库。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| store | 表示指向[OH_Rdb_Store](_o_h___rdb___store.md)实例的指针。 |
| databasePath | 指定数据库的备份文件路径。 |

**返回:**

返回操作是否成功，出错时返回对应的错误码。

**参见:**

[OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_RollBack()


```
int OH_Rdb_RollBack (OH_Rdb_Store * store)
```

**描述:**

回滚已经执行的SQL语句。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| store | 表示指向[OH_Rdb_Store](_o_h___rdb___store.md)实例的指针。 |

**返回:**

返回操作是否成功，出错时返回对应的错误码。

**参见:**

[OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_SetVersion()


```
int OH_Rdb_SetVersion (OH_Rdb_Store * store, int version )
```

**描述:**

设置数据库版本。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| store | 表示指向[OH_Rdb_Store](_o_h___rdb___store.md)实例的指针。 |
| version | 示版本号。 |

**返回:**

返回操作是否成功，出错时返回对应的错误码。

**参见:**

[OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_Update()


```
int OH_Rdb_Update (OH_Rdb_Store * store, OH_VBucket * valuesBucket, OH_Predicates * predicates )
```

**描述:**

根据指定的条件更新数据库中的数据。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| store | 表示指向[OH_Rdb_Store](_o_h___rdb___store.md)实例的指针。 |
| valuesBucket | 表示要更新到表中的数据行[OH_VBucket](_o_h___v_bucket.md)。 |
| predicates | 表示指向[OH_Predicates](_o_h___predicates.md)实例的指针，指定更新条件。 |

**返回:**

如果更新成功，返回受影响的行数，否则返回特定的错误码。

**参见:**

[OH_Rdb_Store](_o_h___rdb___store.md), OH_Bucket, [OH_Predicates](_o_h___predicates.md).


## 变量说明


### andOperate


```
OH_Predicates(* OH_Predicates::andOperate) (OH_Predicates *predicates)
```

**描述:**

函数指针，向谓词添加和条件。

该方法等同于SQL语句中的“AND”。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| predicates | 表示指向[OH_Predicates](_o_h___predicates.md)实例的指针。 |

**返回:**

返回带有和条件的谓词。

**参见:**

[OH_Predicates](_o_h___predicates.md).


### beginWrap


```
OH_Predicates(* OH_Predicates::beginWrap) (OH_Predicates *predicates)
```

**描述:**

函数指针，向谓词添加左括号。

该方法等同于SQL语句中的“(”。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| predicates | 表示指向[OH_Predicates](_o_h___predicates.md)实例的指针。 |

**返回:**

返回带有左括号的谓词。

**参见:**

[OH_Predicates](_o_h___predicates.md).


### between


```
OH_Predicates(* OH_Predicates::between) (OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**描述:**

函数指针，将谓词配置为匹配数据字段为field且其值在给定范围内的指定字段。

该方法等同于SQL语句中的“BETWEEN”。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| predicates | 表示指向[OH_Predicates](_o_h___predicates.md)实例的指针。 |
| field | 数据库表中的列名。 |
| valueObject | 表示指向[OH_VObject](_o_h___v_object.md)实例的指针，指示要与谓词匹配的值。 |

**返回:**

返回与指定字段匹配的谓词。

**参见:**

[OH_Predicates](_o_h___predicates.md), [OH_VObject](_o_h___v_object.md).


### capability


```
uint16_t OH_VBucket::capability
```

**描述:**

表示结构体的存储键值对的数量


### clear [1/2]


```
OH_Predicates(* OH_Predicates::clear) (OH_Predicates *predicates)
```

**描述:**

函数指针，清空谓词。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| predicates | 表示指向[OH_Predicates](_o_h___predicates.md)实例的指针。 |

**返回:**

返回清空后的谓词

**参见:**

[OH_Predicates](_o_h___predicates.md).


### clear [2/2]


```
int(* OH_VBucket::clear) (OH_VBucket *bucket)
```

**描述:**

清空[OH_VBucket](_o_h___v_bucket.md)对象。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| bucket | 表示指向[OH_VBucket](_o_h___v_bucket.md)实例的指针。 |

**返回:**

返回操作是否成功，出错时返回对应的错误码。

**参见:**

[OH_VBucket](_o_h___v_bucket.md).


### close


```
int(* OH_Cursor::close) (OH_Cursor *cursor)
```

**描述:**

函数指针，关闭结果集。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| cursor | 表示指向[OH_Cursor](_o_h___cursor.md)实例的指针。 |

**返回:**

返回操作是否成功，出错时返回对应的错误码。

**参见:**

[OH_Cursor](_o_h___cursor.md).


### destroyPredicates


```
int(* OH_Predicates::destroyPredicates) (OH_Predicates *predicates)
```

**描述:**

销毁[OH_Predicates](_o_h___predicates.md)对象，并回收该对象占用的内存。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| predicates | 表示指向[OH_Predicates](_o_h___predicates.md)实例的指针。 |

**返回:**

返回操作是否成功，出错时返回对应的错误码。

**参见:**

[OH_Predicates](_o_h___predicates.md).


### destroyValueObject


```
int(* OH_VObject::destroyValueObject) (OH_VObject *valueObject)
```

**描述:**

销毁[OH_VObject](_o_h___v_object.md)对象，并回收该对象占用的内存。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| valueObject | 表示指向[OH_VObject](_o_h___v_object.md)实例的指针。 |

**返回:**

返回操作是否成功，出错时返回对应的错误码。

**参见:**

[OH_VObject](_o_h___v_object.md).


### destroyValuesBucket


```
int(* OH_VBucket::destroyValuesBucket) (OH_VBucket *bucket)
```

**描述:**

销毁[OH_VBucket](_o_h___v_bucket.md)对象，并回收该对象占用的内存。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| bucket | 表示指向[OH_VBucket](_o_h___v_bucket.md)实例的指针。 |

**返回:**

返回操作是否成功，出错时返回对应的错误码。

**参见:**

[OH_VBucket](_o_h___v_bucket.md).


### distinct


```
OH_Predicates(* OH_Predicates::distinct) (OH_Predicates *predicates)
```

**描述:**

函数指针，配置谓词以过滤重复记录并仅保留其中一个。

该方法等同于SQL语句中的“DISTINCT”。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| predicates | 表示指向[OH_Predicates](_o_h___predicates.md)实例的指针。 |

**返回:**

返回可用于过滤重复记录的谓词。

**参见:**

[OH_Predicates](_o_h___predicates.md).


### endWrap


```
OH_Predicates(* OH_Predicates::endWrap) (OH_Predicates *predicates)
```

**描述:**

函数指针，向谓词添加右括号。

该方法等同于SQL语句中的“)”。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| predicates | 表示指向[OH_Predicates](_o_h___predicates.md)实例的指针。 |

**返回:**

返回带有右括号的谓词。

**参见:**

[OH_Predicates](_o_h___predicates.md).


### equalTo


```
OH_Predicates(* OH_Predicates::equalTo) (OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**描述:**

函数指针，配置谓词以匹配数据字段等于指定值的字段。

该方法等同于SQL语句中的“=”。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| predicates | 表示指向[OH_Predicates](_o_h___predicates.md)实例的指针。 |
| field | 数据库表中的列名 |
| valueObject | 表示指向[OH_VObject](_o_h___v_object.md)实例的指针，指示要与谓词匹配的值。 |

**返回:**

返回与指定字段匹配的谓词。

**参见:**

[OH_Predicates](_o_h___predicates.md), [OH_VObject](_o_h___v_object.md).


### getBlob


```
int(* OH_Cursor::getBlob) (OH_Cursor *cursor, int32_t columnIndex, unsigned char *value, int length)
```

**描述:**

函数指针，以字节数组的形式获取当前行中指定列的值。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| cursor | 表示指向[OH_Cursor](_o_h___cursor.md)实例的指针。 |
| columnIndex | 表示结果集中指定列的索引。 |
| value | 该参数是输出参数，结果集中指定列的值会以字节数组形式写入该变量。 |
| length | 表示value的长度，该值可通过getSize获取。 |

**返回:**

返回操作是否成功，出错时返回对应的错误码。

**参见:**

[OH_Cursor](_o_h___cursor.md).


### getColumnCount


```
int(* OH_Cursor::getColumnCount) (OH_Cursor *cursor, int *count)
```

**描述:**

函数指针，获取结果集中的列数。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| cursor | 表示指向[OH_Cursor](_o_h___cursor.md)实例的指针。 |
| count | 该参数是输出参数，结果集中的列数会写入该变量。 |

**返回:**

返回操作是否成功，出错时返回对应的错误码。

**参见:**

[OH_Cursor](_o_h___cursor.md).


### getColumnIndex


```
int(* OH_Cursor::getColumnIndex) (OH_Cursor *cursor, const char *name, int *columnIndex)
```

**描述:**

函数指针，根据指定的列名获取列索引。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| cursor | 表示指向[OH_Cursor](_o_h___cursor.md)实例的指针。 |
| name | 表示结果集中指定列的名称。 |
| columnIndex | 该参数是输出参数，结果集中指定列的索引会写入该变量。 |

**返回:**

返回操作是否成功，出错时返回对应的错误码。

**参见:**

[OH_Cursor](_o_h___cursor.md).


### getColumnName


```
int(* OH_Cursor::getColumnName) (OH_Cursor *cursor, int32_t columnIndex, char *name, int length)
```

**描述:**

函数指针，根据指定的列索引获取列名。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| cursor | 表示指向[OH_Cursor](_o_h___cursor.md)实例的指针。 |
| columnIndex | 表示结果集中指定列的索引。 |
| name | 该参数是输出参数，结果集中指定列的名称会写入该变量。 |
| length | 表示列名的长度。 |

**返回:**

返回操作是否成功，出错时返回对应的错误码。

**参见:**

[OH_Cursor](_o_h___cursor.md).


### getColumnType


```
int(* OH_Cursor::getColumnType) (OH_Cursor *cursor, int32_t columnIndex, OH_ColumnType *columnType)
```

**描述:**

函数指针，根据指定的列索引获取列名。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| cursor | 表示指向[OH_Cursor](_o_h___cursor.md)实例的指针。 |
| columnIndex | 表示结果集中指定列的索引。 |
| columnType | 该参数是输出参数，结果集中指定列的数据类型[OH_ColumnType](#oh_columntype)会写入该变量。 |

**返回:**

返回操作是否成功，出错时返回对应的错误码。

**参见:**

[OH_Cursor](_o_h___cursor.md), [OH_ColumnType](#oh_columntype).


### getInt64


```
int(* OH_Cursor::getInt64) (OH_Cursor *cursor, int32_t columnIndex, int64_t *value)
```

**描述:**

函数指针，以int64_t形式获取当前行中指定列的值。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| cursor | 表示指向[OH_Cursor](_o_h___cursor.md)实例的指针。 |
| columnIndex | 表示结果集中指定列的索引。 |
| value | 该参数是输出参数，结果集中指定列的值会以int64_t形式写入该变量。 |

**返回:**

返回操作是否成功，出错时返回对应的错误码。

**参见:**

[OH_Cursor](_o_h___cursor.md).


### getReal


```
int(* OH_Cursor::getReal) (OH_Cursor *cursor, int32_t columnIndex, double *value)
```

**描述:**

函数指针，以double形式获取当前行中指定列的值。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| cursor | 表示指向[OH_Cursor](_o_h___cursor.md)实例的指针。 |
| columnIndex | 表示结果集中指定列的索引。 |
| value | 该参数是输出参数，结果集中指定列的值会以double形式写入该变量。 |

**返回:**

返回操作是否成功，出错时返回对应的错误码。

**参见:**

[OH_Cursor](_o_h___cursor.md).


### getRowCount


```
int(* OH_Cursor::getRowCount) (OH_Cursor *cursor, int *count)
```

**描述:**

函数指针，获取结果集中的行数。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| cursor | 表示指向[OH_Cursor](_o_h___cursor.md)实例的指针。 |
| count | 该参数是输出参数，结果集中的行数会写入该变量。 |

**返回:**

返回操作是否成功，出错时返回对应的错误码。

**参见:**

[OH_Cursor](_o_h___cursor.md).


### getSize


```
int(* OH_Cursor::getSize) (OH_Cursor *cursor, int32_t columnIndex, size_t *size)
```

**描述:**

函数指针，当结果集中列的数据类型是BLOB或者TEXT时，获取其值所需的内存。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| cursor | 表示指向[OH_Cursor](_o_h___cursor.md)实例的指针。 |
| columnIndex | 表示结果集中指定列的索引。 |
| size | 该参数是输出参数，BLOB或者TEXT数据所需内存大小会写入该变量。 |

**返回:**

返回操作是否成功，出错时返回对应的错误码。

**参见:**

[OH_Cursor](_o_h___cursor.md).


### getText


```
int(* OH_Cursor::getText) (OH_Cursor *cursor, int32_t columnIndex, char *value, int length)
```

**描述:**

函数指针，以字符串形式获取当前行中指定列的值。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| cursor | 表示指向[OH_Cursor](_o_h___cursor.md)实例的指针。 |
| columnIndex | 表示结果集中指定列的索引。 |
| value | 该参数是输出参数，结果集中指定列的值会以字符串形式写入该变量。 |
| length | 表示value的长度，该值可通过getSize获取。 |

**返回:**

返回操作是否成功，出错时返回对应的错误码。

**参见:**

[OH_Cursor](_o_h___cursor.md).


### goToNextRow


```
int(* OH_Cursor::goToNextRow) (OH_Cursor *cursor)
```

**描述:**

函数指针，转到结果集的下一行。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| cursor | 表示指向[OH_Cursor](_o_h___cursor.md)实例的指针。 |

**返回:**

返回操作是否成功，出错时返回对应的错误码。

**参见:**

[OH_Cursor](_o_h___cursor.md).


### greaterThan


```
OH_Predicates(* OH_Predicates::greaterThan) (OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**描述:**

函数指针，配置谓词以匹配数据字段为field且值大于指定值valueObject的字段。

该方法等同于SQL语句中的“&gt;”。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| predicates | 表示指向[OH_Predicates](_o_h___predicates.md)实例的指针。 |
| field | 数据库表中的列名。 |
| valueObject | 表示指向[OH_VObject](_o_h___v_object.md)实例的指针，指示要与谓词匹配的值。 |

**返回:**

返回与指定字段匹配的谓词

**参见:**

[OH_Predicates](_o_h___predicates.md), [OH_VObject](_o_h___v_object.md).


### greaterThanOrEqualTo


```
OH_Predicates(* OH_Predicates::greaterThanOrEqualTo) (OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**描述:**

函数指针，配置谓词以匹配数据字段为field且值大于或等于指定值valueObject的字段

该方法等同于SQL语句中的“&gt;=”。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| predicates | 表示指向[OH_Predicates](_o_h___predicates.md)实例的指针。 |
| field | 数据库表中的列名。 |
| valueObject | 表示指向[OH_VObject](_o_h___v_object.md)实例的指针，指示要与谓词匹配的值。 |

**返回:**

返回与指定字段匹配的谓词。

**参见:**

[OH_Predicates](_o_h___predicates.md), [OH_VObject](_o_h___v_object.md).


### groupBy


```
OH_Predicates(* OH_Predicates::groupBy) (OH_Predicates *predicates, char const *const *fields, int length)
```

**描述:**

函数指针，配置R谓词按指定列分组查询结果。

该方法等同于SQL语句中的“GROUP BY”。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| predicates | 表示指向[OH_Predicates](_o_h___predicates.md)实例的指针。 |
| fields | 指定分组依赖的列名。 |
| length | 表示fields数值的长度。 |

**返回:**

返回分组查询列的谓词。

**参见:**

[OH_Predicates](_o_h___predicates.md).


### id [1/4]


```
int64_t OH_Predicates::id
```

**描述:**

OH_Predicates结构体的唯一标识符。


### id [2/4]


```
int64_t OH_VObject::id
```

**描述:**

OH_VObject结构体的唯一标识符。


### id [3/4]


```
int64_t OH_VBucket::id
```

**描述:**

OH_VBucket结构体的唯一标识符。


### id [4/4]


```
int64_t OH_Rdb_Store::id
```

**描述:**

OH_Rdb_Store结构体的唯一标识符。


### in


```
OH_Predicates(* OH_Predicates::in) (OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**描述:**

函数指针，配置谓词以匹配数据字段为field且值在给定范围内的指定字段。

该方法等同于SQL语句中的“IN”。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| predicates | 表示指向[OH_Predicates](_o_h___predicates.md)实例的指针。 |
| field | 表示数据库表中的列名。 |
| valueObject | 表示指向[OH_VObject](_o_h___v_object.md)实例的指针，指示要与谓词匹配的值。 |

**返回:**

返回与指定字段匹配的谓词。

**参见:**

[OH_Predicates](_o_h___predicates.md), [OH_VObject](_o_h___v_object.md).


### isEncrypt


```
bool OH_Rdb_Config::isEncrypt
```

**描述:**

指定数据库是否加密。


### isNotNull


```
OH_Predicates(* OH_Predicates::isNotNull) (OH_Predicates *predicates, const char *field)
```

**描述:**

函数指针，配置谓词以匹配值不为null的指定字段。

该方法等同于SQL语句中的“IS NOT NULL”。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| predicates | 表示指向[OH_Predicates](_o_h___predicates.md)实例的指针。 |
| field | 数据库表中的列名。 |

**返回:**

返回与指定字段匹配的谓词

**参见:**

[OH_Predicates](_o_h___predicates.md).


### isNull [1/2]


```
int(* OH_Cursor::isNull) (OH_Cursor *cursor, int32_t columnIndex, bool *isNull)
```

**描述:**

函数指针，检查当前行中指定列的值是否为null。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| cursor | 表示指向[OH_Cursor](_o_h___cursor.md)实例的指针。 |
| columnIndex | 表示结果集中指定列的索引。 |
| isNull | 该参数是输出参数，如果当前行中指定列的值为null，该值为true，否则为false。 |

**返回:**

返回操作是否成功，出错时返回对应的错误码。

**参见:**

[OH_Cursor](_o_h___cursor.md).


### isNull [2/2]


```
OH_Predicates(* OH_Predicates::isNull) (OH_Predicates *predicates, const char *field)
```

**描述:**

函数指针，配置谓词以匹配值为null的字段。

该方法等同于SQL语句中的“IS NULL”。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| predicates | 表示指向[OH_Predicates](_o_h___predicates.md)实例的指针。 |
| field | 数据库表中的列名。 |

**返回:**

返回与指定字段匹配的谓词。

**参见:**

[OH_Predicates](_o_h___predicates.md).


### lessThan


```
OH_Predicates(* OH_Predicates::lessThan) (OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**描述:**

函数指针，配置谓词以匹配数据字段为field且值小于指定值valueObject的字段

该方法等同于SQL语句中的“&lt;”。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| predicates | 表示指向[OH_Predicates](_o_h___predicates.md)实例的指针。 |
| field | 数据库表中的列名。 |
| valueObject | 表示指向[OH_VObject](_o_h___v_object.md)实例的指针，指示要与谓词匹配的值。 |

**返回:**

返回与指定字段匹配的谓词。

**参见:**

[OH_Predicates](_o_h___predicates.md), [OH_VObject](_o_h___v_object.md).


### lessThanOrEqualTo


```
OH_Predicates(* OH_Predicates::lessThanOrEqualTo) (OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**描述:**

函数指针，配置谓词以匹配数据字段为field且值小于或等于指定值valueObject的字段

该方法等同于SQL语句中的“&lt;=”。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| predicates | 表示指向[OH_Predicates](_o_h___predicates.md)实例的指针。 |
| field | 数据库表中的列名。 |
| valueObject | 表示指向[OH_VObject](_o_h___v_object.md)实例的指针，指示要与谓词匹配的值。 |

**返回:**

返回与指定字段匹配的谓词。

**参见:**

[OH_Predicates](_o_h___predicates.md), [OH_VObject](_o_h___v_object.md).


### like


```
OH_Predicates(* OH_Predicates::like) (OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**描述:**

函数指针，配置谓词以匹配数据字段为field且值类似于指定字符串的字段。

该方法等同于SQL语句中的“LIKE”。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| predicates | 表示指向[OH_Predicates](_o_h___predicates.md)实例的指针。 |
| field | 数据库表中的列名。 |
| valueObject | 表示指向[OH_VObject](_o_h___v_object.md)实例的指针，指示要与谓词匹配的值。 |

**返回:**

返回与指定字段匹配的谓词。

**参见:**

[OH_Predicates](_o_h___predicates.md), [OH_VObject](_o_h___v_object.md).


### limit


```
OH_Predicates(* OH_Predicates::limit) (OH_Predicates *predicates, unsigned int value)
```

**描述:**

函数指针，设置最大数据记录数的谓词。

该方法等同于SQL语句中的“LIMIT”。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| predicates | 表示指向[OH_Predicates](_o_h___predicates.md)实例的指针。 |
| value | 表示最大数据记录数。 |

**返回:**

返回可用于设置最大数据记录数的谓词。

**参见:**

[OH_Predicates](_o_h___predicates.md).


### notBetween


```
OH_Predicates(* OH_Predicates::notBetween) (OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**描述:**

函数指针，将谓词配置为匹配数据字段为field且其值超出给定范围内的指定字段。

该方法等同于SQL语句中的“NOT BETWEEN”。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| predicates | 表示指向[OH_Predicates](_o_h___predicates.md)实例的指针。 |
| field | 数据库表中的列名。 |
| valueObject | 表示指向[OH_VObject](_o_h___v_object.md)实例的指针，指示要与谓词匹配的值。 |

**返回:**

返回与指定字段匹配的谓词。

**参见:**

[OH_Predicates](_o_h___predicates.md), [OH_VObject](_o_h___v_object.md).


### notEqualTo


```
OH_Predicates(* OH_Predicates::notEqualTo) (OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**描述:**

函数指针，配置谓词以匹配数据字段不等于指定值的字段。

该方法等同于SQL语句中的“!=”。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| predicates | 表示指向[OH_Predicates](_o_h___predicates.md)实例的指针。 |
| field | 数据库表中的列名。 |
| valueObject | 表示指向[OH_VObject](_o_h___v_object.md)实例的指针，指示要与谓词匹配的值。 |

**返回:**

返回与指定字段匹配的谓词。

**参见:**

[OH_Predicates](_o_h___predicates.md), [OH_VObject](_o_h___v_object.md).


### notIn


```
OH_Predicates(* OH_Predicates::notIn) (OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**描述:**

函数指针，配置谓词以匹配数据字段为field且值超出给定范围内的指定字段。

该方法等同于SQL语句中的“NOT IN”。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| predicates | 表示指向[OH_Predicates](_o_h___predicates.md)实例的指针。 |
| field | 表示数据库表中的列名。 |
| valueObject | 表示指向[OH_VObject](_o_h___v_object.md)实例的指针，指示要与谓词匹配的值。 |

**返回:**

返回与指定字段匹配的谓词。

**参见:**

[OH_Predicates](_o_h___predicates.md), [OH_VObject](_o_h___v_object.md).


### offset


```
OH_Predicates(* OH_Predicates::offset) (OH_Predicates *predicates, unsigned int rowOffset)
```

**描述:**

函数指针，配置谓词以指定返回结果的起始位置。

该方法等同于SQL语句中的“OFFSET”。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| predicates | 表示指向[OH_Predicates](_o_h___predicates.md)实例的指针。 |
| rowOffset | 返回结果的起始位置，取值为正整数。 |

**返回:**

返回具有指定返回结果起始位置的谓词。

**参见:**

[OH_Predicates](_o_h___predicates.md).


### orderBy


```
OH_Predicates(* OH_Predicates::orderBy) (OH_Predicates *predicates, const char *field, OH_OrderType type)
```

**描述:**

函数指针，配置谓词以匹配其值按升序或降序排序的列。

该方法等同于SQL语句中的“ORDER BY”。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| predicates | 表示指向[OH_Predicates](_o_h___predicates.md)实例的指针。 |
| field | 数据库表中的列名。 |
| type | 表示排序类型&nbsp;[OH_OrderType](#oh_ordertype). |

**返回:**

返回与指定字段匹配的谓词。

**参见:**

[OH_Predicates](_o_h___predicates.md), [OH_OrderType](#oh_ordertype).


### orOperate


```
OH_Predicates(* OH_Predicates::orOperate) (OH_Predicates *predicates)
```

**描述:**

函数指针，将或条件添加到谓词中。

该方法等同于SQL语句中的“OR”。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| predicates | 表示指向[OH_Predicates](_o_h___predicates.md)实例的指针。 |

**返回:**

返回带有或条件的谓词。

**参见:**

[OH_Predicates](_o_h___predicates.md).


### path


```
const char* OH_Rdb_Config::path
```

**描述:**

数据库文件路径。


### putBlob


```
int(* OH_VBucket::putBlob) (OH_VBucket *bucket, const char *field, const uint8_t *value, uint32_t size)
```

**描述:**

将const uint8_t \*值放入给定列名的[OH_VBucket](_o_h___v_bucket.md)对象中。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| bucket | 表示指向[OH_VBucket](_o_h___v_bucket.md)实例的指针。 |
| field | 数据库表中的列名。 |
| value | 数据库表中指定列名对应的值。 |
| size | 表示value的长度。 |

**返回:**

返回操作是否成功，出错时返回对应的错误码。

**参见:**

[OH_VBucket](_o_h___v_bucket.md).


### putDouble


```
int(* OH_VObject::putDouble) (OH_VObject *valueObject, double *value, uint32_t count)
```

**描述:**

将double类型的单个参数或者数组转换为[OH_VObject](_o_h___v_object.md)类型的值。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| valueObject | 表示指向[OH_VObject](_o_h___v_object.md)实例的指针。 |
| value | 表示指向double类型的单个参数或者数组的指针。 |
| count | 如果value是指向单个数值的指针，则count&nbsp;=&nbsp;1；如果value是指向数组的指针，则count是数组的长度。 |

**返回:**

返回操作是否成功，出错时返回对应的错误码。

**参见:**

[OH_VObject](_o_h___v_object.md).


### putInt64 [1/2]


```
int(* OH_VBucket::putInt64) (OH_VBucket *bucket, const char *field, int64_t value)
```

**描述:**

将int64_t值放入给定列名的[OH_VBucket](_o_h___v_bucket.md)对象中。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| bucket | 表示指向[OH_VBucket](_o_h___v_bucket.md)实例的指针。 |
| field | 数据库表中的列名。 |
| value | 数据库表中指定列名对应的值。 |

**返回:**

返回操作是否成功，出错时返回对应的错误码。

**参见:**

[OH_VBucket](_o_h___v_bucket.md).


### putInt64 [2/2]


```
int(* OH_VObject::putInt64) (OH_VObject *valueObject, int64_t *value, uint32_t count)
```

**描述:**

将int64类型的单个参数或者数组转换为[OH_VObject](_o_h___v_object.md)类型的值。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| valueObject | 表示指向[OH_VObject](_o_h___v_object.md)实例的指针。 |
| value | 表示指向int64_t类型的单个参数或者数组的指针。 |
| count | 如果value是指向单个数值的指针，则count&nbsp;=&nbsp;1；如果value是指向数组的指针，则count是数组的长度。 |

**返回:**

返回操作是否成功，出错时返回对应的错误码。

**参见:**

[OH_VObject](_o_h___v_object.md).


### putNull


```
int(* OH_VBucket::putNull) (OH_VBucket *bucket, const char *field)
```

**描述:**

将NULL值放入给定列名的[OH_VBucket](_o_h___v_bucket.md)对象中。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| bucket | 表示指向[OH_VBucket](_o_h___v_bucket.md)实例的指针。 |
| field | 数据库表中的列名。 |

**返回:**

返回操作是否成功，出错时返回对应的错误码。

**参见:**

[OH_VBucket](_o_h___v_bucket.md).


### putReal


```
int(* OH_VBucket::putReal) (OH_VBucket *bucket, const char *field, double value)
```

**描述:**

将double值放入给定列名的｛**OH_VBucket｝对象中。**

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| bucket | 表示指向[OH_VBucket](_o_h___v_bucket.md)实例的指针。 |
| field | 数据库表中的列名。 |
| value | 数据库表中指定列名对应的值。 |

**返回:**

返回操作是否成功，出错时返回对应的错误码。

**参见:**

[OH_VBucket](_o_h___v_bucket.md).


### putText [1/2]


```
int(* OH_VBucket::putText) (OH_VBucket *bucket, const char *field, const char *value)
```

**描述:**

将const char\*值放入给定列名的[OH_VBucket](_o_h___v_bucket.md)对象中。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| bucket | 表示指向[OH_VBucket](_o_h___v_bucket.md)实例的指针。 |
| field | 数据库表中的列名。 |
| value | 数据库表中指定列名对应的值。 |

**返回:**

返回操作是否成功，出错时返回对应的错误码。

**参见:**

[OH_VBucket](_o_h___v_bucket.md).


### putText [2/2]


```
int(* OH_VObject::putText) (OH_VObject *valueObject, const char *value)
```

**描述:**

将char \*类型的字符数组转换为[OH_VObject](_o_h___v_object.md)类型的值。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| valueObject | 表示指向[OH_VObject](_o_h___v_object.md)实例的指针。 |
| value | 表示字符数组参数。 |

**返回:**

返回操作是否成功，出错时返回对应的错误码。

**参见:**

[OH_VObject](_o_h___v_object.md).


### putTexts


```
int(* OH_VObject::putTexts) (OH_VObject *valueObject, const char **value, uint32_t count)
```

**描述:**

将char \*类型的字符串数组转换为[OH_VObject](_o_h___v_object.md)类型的值。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| valueObject | 表示指向[OH_VObject](_o_h___v_object.md)实例的指针。 |
| value | 表示字符串数组参数。 |
| count | 表示字符串数组参数value的长度。 |

**返回:**

返回操作是否成功，出错时返回对应的错误码。

**参见:**

[OH_VObject](_o_h___v_object.md).


### securityLevel


```
enum OH_Rdb_SecurityLevel OH_Rdb_Config::securityLevel
```

**描述:**

设置数据库安全级别[OH_Rdb_SecurityLevel](#oh_rdb_securitylevel)。
