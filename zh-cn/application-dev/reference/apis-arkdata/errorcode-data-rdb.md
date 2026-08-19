# 关系型数据库错误码
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @baijidong-->
<!--Designer: @htt1997-->
<!--Tester: @logic42-->
<!--Adviser: @ge-yafang-->

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。
>
> 获取hilog系统日志的方法可参考：[hilog日志查看](../../dfx/hilog.md#hilog日志查看)。
>
> 以下可搜索的日志在不同版本上可能存在差异。

## 14800000 内部错误

**错误信息**

Inner error.

**错误描述**

内部错误。

**可能原因**

1. 设置分布式表不支持联合主键，因此调用[setDistributedTables](arkts-apis-data-relationalStore-RdbStore.md#setdistributedtables)等设置分布式表接口会失败。
2. 多进程操作数据库，其中一个进程被冻结，数据库锁会被当前冻结进程一直持有，直到解冻才会释放，在此期间其他进程调用[getRdbStore](arkts-apis-data-relationalStore-f.md#relationalstoregetrdbstore)等接口开库时获取锁会失败。
3. 使用读连接进行写操作。读连接不可用于执行写库操作，仅可执行读库操作。
4. 事务未提交时，调用[execute](arkts-apis-data-relationalStore-RdbStore.md#execute12)或者[executeSql](arkts-apis-data-relationalStore-RdbStore.md#executesql)等接口依次执行删除触发器、删除表、重建表等DDL操作，后续再次执行类似操作时会出现失败。
5. 并发查询和删除同一批数据。
6. 根密钥生成失败。HUKS生成根密钥失败，无法进一步生成加密数据库的密钥，因此调用[getRdbStore](arkts-apis-data-relationalStore-f.md#relationalstoregetrdbstore)等开库接口打开加密数据库会失败。
7. 远程查询时，没有查询到数据。在对端数据库中不存在要查询的数据的情况下，调用[remoteQuery](arkts-apis-data-relationalStore-RdbStore.md#remotequery)接口进行远程查询，获取到结果集后，再调用[goToFirstRow](arkts-apis-data-relationalStore-ResultSet.md#gotofirstrow)等接口获取数据会失败。
8. 数据管理服务启动失败。在数据管理服务启动失败的情况下，无法设置分布式表，因此调用[setDistributedTables](arkts-apis-data-relationalStore-RdbStore.md#setdistributedtables)等设置分布式表接口会失败。

**处理步骤**

1. 确认问题时间点附近，是否存在该日志打印：`Not support create distributed table with composite primary keys`。
   - 是：设置分布式表时不要使用联合主键。
   - 否：转下一步。
2. 确认问题时间点附近，是否可正则搜索到和进程冻结相关的日志：`Freeze pid: 进程号 success`或`PID 进程号 has been frozen`，以及开库失败的日志：`ConnectionPool.*code:-15`。
   - 是：进程退后台时不要操作数据库，避免多进程并发操作数据库；调用[requestSuspendDelay](../apis-backgroundtasks-kit/js-apis-resourceschedule-backgroundTaskManager.md#backgroundtaskmanagerrequestsuspenddelay)接口申请短时任务或调用[startBackgroundRunning](../apis-backgroundtasks-kit/js-apis-resourceschedule-backgroundTaskManager.md#backgroundtaskmanagerstartbackgroundrunning)接口申请长时任务，使得数据库操作在进程被冻结前可以执行结束。
   - 否：转下一步。
3. 排查业务代码是否存在使用读连接执行写操作的场景。
   - 是：使用读连接时仅执行读操作，写操作请使用写连接。
   - 否：转下一步。
4. 排查业务代码是否存在如下操作：调用[beginTransaction](arkts-apis-data-relationalStore-RdbStore.md#begintransaction)接口开启事务后，事务未提交时，调用[execute](arkts-apis-data-relationalStore-RdbStore.md#execute12)或者[executeSql](arkts-apis-data-relationalStore-RdbStore.md#executesql)接口依次执行：删除触发器a、删除表A、重建表A，后续再次删除触发器a时出现失败。
   - 是：避免在事务未提交的时候，依次执行删除触发器a、删除表A、重建表A以及再次删除触发器a的类似操作。
   - 否：转下一步。
5. 排查业务代码是否存在如下操作：获取结果集后，先调用[execute](arkts-apis-data-relationalStore-RdbStore.md#execute12)、[executeSql](arkts-apis-data-relationalStore-RdbStore.md#executesql)或[delete](arkts-apis-data-relationalStore-RdbStore.md#delete)接口删除待查询的数据，再调用[getLong](arkts-apis-data-relationalStore-ResultSet.md#getlong)等接口获取数据时出现失败。
   - 是：业务需要控制好时序，不要并发查询和删除同一批数据。
   - 否：转下一步。
6. 确认问题时间点附近，是否可正则搜索到关键日志：`01650.*Init.*retry.*error`，其中error不为0。
   - 是：根密钥可能生成失败，业务需要重试打开加密数据库。
   - 否：转下一步。
7. 确认对端设备的数据库中是否存在要查询的数据。
   - 是：转下一步。
   - 否：确保要查询的数据存在，再进行远程查询。
8. 确认问题时间点附近，是否可搜索到关键日志：`Get distributed data manager failed`。
   - 是：数据管理服务启动失败，业务需要重试设置分布式表。
   - 否：提供hilog系统日志，联系技术支撑人员定位。

## 14800001 无效的参数

**错误信息**

Invalid arguments. Possible causes: 1. Parameter is out of valid range; 2. Missing GROUP BY clause.

**错误描述**

无效的参数。

**可能原因**

入参不符合接口要求，如取值范围、长度、格式等。

**处理步骤**

参考接口参数说明修改参数符合要求。

## 14800010 数据库路径不合法

**错误信息**

Failed to open or delete the database by an invalid database path.

**错误描述**

数据库路径不合法，打开或删除数据库失败。

**可能原因**

无效的数据库路径。

**处理步骤**

检查传入数据库路径。

## 14800011 数据库文件异常

**错误信息**

The current operation failed because the database is corrupted.

**错误描述**

数据库异常，当前操作失败。

**可能原因**

1. 打开加密数据库时，自定义密钥不匹配，因此调用[getRdbStore](arkts-apis-data-relationalStore-f.md#relationalstoregetrdbstore)等接口开库时会失败。
2. 数据库文件描述符（fd）误用，导致数据库文件异常，因此调用增删改查等接口操作数据库会失败。
3. 业务进程内存在踩内存问题，导致数据库文件异常，因此调用增删改查等接口操作数据库会失败。
4. 文件拷贝或下载过程中断，使得文件内容不完整，导致数据库文件异常，因此调用增删改查等接口操作数据库会失败。
5. 在数据库使用过程中使用文件接口直接操作数据库，导致数据库文件异常，因此调用增删改查等接口操作数据库会失败。
6. 数据库文件不匹配：如：db文件和wal文件不是同一个数据库，导致数据库异常，因此调用增删改查等接口操作数据库会失败。

**处理步骤**

1. 排查自定义密钥参数和之前创建加密数据库的密钥参数是否一致。
   - 是：转下一步。
   - 否：每次打开加密数据库时，确保自定义的密钥参数都是一致的。
2. 搜索问题时间点附近是否存在日志：`fdsan`或排查业务代码中是否有操作fd的场景。
   - 是：参考[fdsan使用指导](../../napi/fdsan.md)开展问题定位，并同步处理数据库文件异常。如果可以接受数据丢失，可删除原有数据库并重新创建；否则，请先完成数据库备份，再执行恢复操作。具体操作可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。
   - 否：转下一步。
3. 排查业务代码中是否存在踩内存问题。
   - 是：解决业务代码中的踩内存问题，并同步处理数据库文件异常。如果可以接受数据丢失，可删除原有数据库并重新创建；否则，请先完成数据库备份，再执行恢复操作。具体操作可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。
   - 否：转下一步。
4. 排查业务是否存在中断拷贝或下载数据库文件的场景。
   - 是：避免在拷贝或下载数据库文件的过程中中断，并同步处理数据库文件异常。如果可以接受数据丢失，可删除原有数据库并重新创建；否则，请先完成数据库备份，再执行恢复操作。具体操作可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。
   - 否：转下一步。
5. 排查业务代码中是否存在使用文件接口操作数据库的场景。
   - 是：勿使用文件接口操作数据库，并同步处理数据库文件异常。如果可以接受数据丢失，可删除原有数据库并重新创建；否则，请先完成数据库备份，再执行恢复操作。具体操作可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。
   - 否：转下一步。
6. 排查业务代码中是否存在db文件或wal文件被覆盖或者被替换的场景。
   - 是：确保db文件和wal文件对应，并同步处理数据库文件异常。如果可以接受数据丢失，可删除原有数据库并重新创建；否则，请先完成数据库备份，再执行恢复操作。具体操作可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。
   - 否：提供hilog系统日志，联系技术支撑人员定位。

## 14800012 结果集为空或指针索引越界

**错误信息**

ResultSet is empty or pointer index is out of bounds.

**错误描述**

结果集为空或指针索引越界。

**可能原因**

1. SQL拼写错误、找不到表或字段、重复添加字段、违反SQLite系统限制、数据库文件异常等（参考错误码14800021的问题场景），调用[getLong](arkts-apis-data-relationalStore-ResultSet.md#getlong)等接口获取数据时会失败。
2. 查询的单条数据大小超过2M，调用[getLong](arkts-apis-data-relationalStore-ResultSet.md#getlong)等接口获取数据时会失败。
3. 表中无任何数据，调用[getLong](arkts-apis-data-relationalStore-ResultSet.md#getlong)等接口获取数据时会失败。
4. 表中无符合查询条件的数据，调用[getLong](arkts-apis-data-relationalStore-ResultSet.md#getlong)等接口获取数据时会失败。

**处理步骤**

1. 确认是否可以参考错误码14800021的处理步骤排查到问题。
   - 是：参考错误码14800021的处理步骤。
   - 否：转下一步。
2. 确认问题时间点附近，是否可正则搜索到关键日志：`ResetStatement.*over 2MB`或者排查单条数据的大小是否超过2M。
   - 是：调用[queryWithoutRowCount](arkts-apis-data-relationalStore-RdbStore.md#querywithoutrowcount23)接口获取结果集[LiteResultSet](arkts-apis-data-relationalStore-LiteResultSet.md)后，再查询单条大小超过2M的数据。
   - 否：转下一步。
3. 排查表中是否存在数据。
   - 是：转下一步。
   - 否：插入数据后再查询。
4. 排查表中是否存在符合查询条件的数据。
   - 是：提供hilog系统日志，联系技术支撑人员定位。
   - 否：确保查询条件符合预期，可以查询到数据。

## 14800013 列索引越界

**错误信息**

Column index is out of bounds.

**错误描述**

列索引越界。

**可能原因**

1. 调用[getColumnIndex](arkts-apis-data-relationalStore-ResultSet.md#getcolumnindex)接口时，传参为表中不存在的列名，然后将其返回结果作为[getLong](arkts-apis-data-relationalStore-ResultSet.md#getlong)或[getString](arkts-apis-data-relationalStore-ResultSet.md#getstring)等获取数据接口的入参，会导致接口执行失败。
2. 当传入的列索引参数超出有效范围：[0, 表字段数量 - 1]时，调用[getColumnType](arkts-apis-data-relationalStore-ResultSet.md#getcolumntype18)、[getColumnTypeSync](arkts-apis-data-relationalStore-ResultSet.md#getcolumntypesync18)、[getLong](arkts-apis-data-relationalStore-ResultSet.md#getlong)、[getString](arkts-apis-data-relationalStore-ResultSet.md#getstring)等接口获取数据时会失败。

**处理步骤**

1. 确认问题时间点附近，是否可搜索到关键日志：`GetColumnIndex:Failed, columnName`，同时排查[getColumnIndex](arkts-apis-data-relationalStore-ResultSet.md#getcolumnindex)的入参是否为表中不存在的列名。
   - 是：确保传入参数符合预期，必须为表中存在的列名。
   - 否：转下一步。
2. 确认问题时间点附近，是否可正则搜索到关键日志：`column index.*out of range`，同时排查[getColumnType](arkts-apis-data-relationalStore-ResultSet.md#getcolumntype18)、[getColumnTypeSync](arkts-apis-data-relationalStore-ResultSet.md#getcolumntypesync18)、[getLong](arkts-apis-data-relationalStore-ResultSet.md#getlong)、[getString](arkts-apis-data-relationalStore-ResultSet.md#getstring)等接口的列索引参数是否超出有效范围。
   - 是：确保传入参数的值处在有效范围内。
   - 否：提供hilog系统日志，联系技术支撑人员定位。

## 14800014 目标实例已关闭

**错误信息**

The target instance is already closed.

**错误描述**

目标实例已关闭。

**可能原因**

实例未成功打开，或者所属实例已关闭（如RdbStore、ResultSet对象已调用close方法，Transaction对象已调用commit或rollback方法）。

**处理步骤**

重新打开RdbStore或者重新查询获取得到ResultSet。

## 14800015 数据库没有响应

**错误信息**

The database does not respond.

**错误描述**

数据库没有响应。

**可能原因**

有读、写、attach、detach等操作正在执行，无法在指定的时间（默认2s）内执行当前操作。

**处理步骤**

1. 重新尝试。
2. 如果是[attach](arkts-apis-data-relationalStore-RdbStore.md#attach12)或[detach](arkts-apis-data-relationalStore-RdbStore.md#detach12)接口，增加waitTime值来增加等待时长。

## 14800016 数据库别名已被使用

**错误信息**

The database alias already exists.

**错误描述**

附加后的数据库别名已被使用。

**可能原因**

附加后的数据库的别名已被使用。

**处理步骤**

不进行附加数据库操作或者修改附加后数据库的别名。

## 14800017 关键配置已被更改

**错误信息**

StoreConfig is changed.

**错误描述**

数据库关键配置已被更改。

**可能原因**

数据库的area（区域）、securityLevel（安全级别）、数据库读写权限等关键配置发生变化。

**处理步骤**

保持原配置不变或者用原配置导出数据，删除旧库，用新配置创建新库，数据存入新库。

检查是否使用chmod修改了数据库文件的读写权限，确保当前用户有足够的权限来读写数据库文件。

## 14800018 查询结果没有数据符合条件

**错误信息**

No data meets the condition.

**错误描述**

未查询到符合条件的数据。

**可能原因**

没有编写查询正确结果集的SQL语句。

**处理步骤**

编写正确的查询语句或者添加数据库数据之后再做查询。

## 14800019 SQL必须是查询语句

**错误信息**

The SQL must be a query statement.

**错误描述**

SQL必须是查询语句。

**可能原因**

SQL语句不符合规定，导致查询失败。

**处理步骤**

SQL语句不符合规定导致执行失败时，编写满足规约的SQL语句。

## 14800020 密钥损坏或丢失

**错误信息**

The secret key is corrupted or lost.

**错误描述**

密钥损坏或丢失。

**可能原因**

根密钥丢失、无权限读取密钥文件、密钥文件损坏等。

**处理步骤**

1. 检查密钥文件权限、内容是否正常。
2. 重建或restore恢复数据库。

## 14800021 SQLite：通用错误

**错误信息**

SQLite: Generic error. Possible causes: Insert failed or the updated data does not exist.

**错误描述**

SQLite：通用错误。

**可能原因**

执行SQL语句过程中出现错误，如：
1. SQL拼写错误，存在语法问题，调用[executeSql](arkts-apis-data-relationalStore-RdbStore.md#executesql)、[execute](arkts-apis-data-relationalStore-RdbStore.md#execute12)或[executeSync](arkts-apis-data-relationalStore-RdbStore.md#executesync12)等接口执行SQL会失败。
2. 数据库中不存在某张表或者表中不存在某个字段，调用[executeSql](arkts-apis-data-relationalStore-RdbStore.md#executesql)、[execute](arkts-apis-data-relationalStore-RdbStore.md#execute12)或[executeSync](arkts-apis-data-relationalStore-RdbStore.md#executesync12)等接口执行SQL会失败。
3. 重复添加表中已存在的字段，调用[executeSql](arkts-apis-data-relationalStore-RdbStore.md#executesql)、[execute](arkts-apis-data-relationalStore-RdbStore.md#execute12)或[executeSync](arkts-apis-data-relationalStore-RdbStore.md#executesync12)等接口执行SQL会失败。
4. 违反SQLite系统限制（字符串或BLOB长度超限、列数过多、SQL变量过多、表达式树过深、复合SELECT过多或附加库过多等），调用[executeSql](arkts-apis-data-relationalStore-RdbStore.md#executesql)、[execute](arkts-apis-data-relationalStore-RdbStore.md#execute12)或[executeSync](arkts-apis-data-relationalStore-RdbStore.md#executesync12)等接口执行SQL会失败。
5. 数据库文件异常，调用[executeSql](arkts-apis-data-relationalStore-RdbStore.md#executesql)、[execute](arkts-apis-data-relationalStore-RdbStore.md#execute12)或[executeSync](arkts-apis-data-relationalStore-RdbStore.md#executesync12)等接口执行SQL会失败。

**处理步骤**

1. 确认问题时间点附近，是否可正则搜索到关键日志：`Error.*unrecognized token|Error.*syntax error|Error.*incomplete input`。
   - 是：SQL语句需要拼写完整；触发器语句中不要存在`RETURN`关键字；SQL语句开头不要包含注释；SQL语句包含`in`时，括号中的匹配值必须传`?`占位符或者具体的值，不要传空值；SQL中的表名或字段名附近，不要存在`{`、`}`或`$`等特殊字符。
   - 否：转下一步。
2. 确认问题时间点附近，是否可正则搜索到关键日志：`Error.*no such table|Error.*no such column`。
   - 是：建表或添加字段之后再操作数据库；进行加固，重新创建丢失的表或添加字段。
   - 否：转下一步。
3. 确认问题时间点附近，是否可正则搜索到关键日志：`Error.*duplicate column name`。
   - 是：不要重复添加表中已存在的字段。
   - 否：转下一步。
4. 确认问题时间点附近，是否可正则搜索到关键日志：`too many SQL variables|string or blob too big|too many columns|expression tree too deep|too many terms in compound SELECT|too many attached databases`。
   - 是：确保SQL执行时不违反SQLite系统限制，可参考官方文档：[SQLite系统限制](https://sqlite.org/limits.html)。
   - 否：转下一步。
5. 确认问题时间点附近，是否可正则搜索到关键日志：`Error.*unsupported file format|Error.*database corruption|Error.*check hmac error`。
   - 是：解决业务进程踩内存或误关fd的问题；接入备份恢复；删除重建数据库。
   - 否：提供hilog系统日志，联系技术支撑人员定位。

## 14800022 SQLite：异步回调请求被中止

**错误信息**

SQLite: Callback routine requested an abort.

**错误描述**

SQLite：异步回调请求被中止。

**可能原因**

1. 通常发生在使用SQLite的自定义函数机制时，回调被中止执行。
2. 参见SQLITE_ABORT的相关错误场景。

**处理步骤**

检查SQLite的钩子函数（callback）的实现，确保其正确性。

## 14800023 SQLite：访问权限被拒绝

**错误信息**

SQLite: Access permission denied.

**错误描述**

SQLite访问权限被拒绝。

**可能原因**

1. 操作系统级别的权限问题，意味着SQLite试图访问或修改一个文件，但是没有足够的权限去执行这个操作。
2. 参见SQLITE_PERM的相关错误场景。

**处理步骤**

1. 确认文件没有只读属性，如果有，去掉只读属性。
2. 检查文件和文件夹的权限，确保当前用户有足够的权限来读写文件。
3. 检查文件系统是否为只读，如果是，改为可写状态。
4. 确认没有其他进程锁定数据库文件，如果有，关闭占用文件的进程。
5. 在处理权限问题时，确保有足够的权限去更改相关的文件或文件夹权限。

## 14800024 SQLite：数据库文件已锁定

**错误信息**

SQLite: The database file is locked.

**错误描述**

SQLite数据库文件已锁定。

**可能原因**

1. 同一应用两个进程，例如UIAbility和DataShareExtensionAbility同时打开了同一个数据库，进行增删改操作，或者不同应用的同一个group组内的进程通过group组打开同一个数据库，进行增删改操作。
2. 参见SQLITE_BUSY的相关错误场景。

**处理步骤**

1. 避免进程并发操作数据库。
2. 等待一段时间重试。

## 14800025 SQLite：数据库中的表被锁定

**错误信息**

SQLite: A table in the database is locked.

**错误描述**

SQLite：数据库中的表被锁定。

**可能原因**

1. 在尝试写入SQLite数据库时，但数据库文件已被另一个进程锁定。这可能是因为数据库处于事务中，或者有其他的锁机制在阻止写入。
2. 参见SQLITE_LOCKED的相关错误场景。

**处理步骤**

1. 确保没有其他进程或线程正在对数据库文件进行写操作。
2. 如果使用了事务，请确保在开始事务后及提交事务前不要进行任何写操作。
3. 检查是否有其他锁机制（如文件锁）可能阻止了写入。
4. 如果数据库连接对象没有正确关闭，确保在完成数据库操作后关闭连接。
5. 如果在多线程环境中，确保对数据库操作加锁，防止竞争条件。

## 14800026 SQLite：数据库内存不足

**错误信息**

SQLite: The database is out of memory.

**错误描述**

SQLite：数据库内存不足。

**可能原因**

数据库内存不足，可能是由于数据量过大或内存分配不足导致的。

**处理步骤**

减小数据量或增加内存分配。

## 14800027 SQLite：尝试写入只读数据库

**错误信息**

SQLite: Attempt to write a readonly database.

**错误描述**

SQLite：尝试写入只读数据库。

**可能原因**

1. 尝试写入一个以只读模式打开的SQLite数据库文件时。这可能是因为文件权限问题，文件处于只读文件系统中或者数据库被标记为只读。
2. 参见SQLITE_READONLY的相关错误场景。

**处理步骤**

1. 确保有足够的权限去写入数据库文件。
2. 如果文件系统是只读的，需要将其改为读写模式。
3. 确认在打开数据库时没有使用只读模式参数。

## 14800028 SQLite：发生了某种磁盘I/O错误

**错误信息**

SQLite: Some kind of disk I/O error occurred.

**错误描述**

SQLite发生了某种磁盘I/O错误。

**可能原因**

可能是由于多种原因造成的，包括但不限于：
1. 文件不存在。
2. 文件是只读的。
3. 磁盘空间不足。
4. 文件损坏。
5. 参见SQLITE_IOERR的相关错误场景。

**处理步骤**

1. 检查文件路径是否正确，文件是否存在。
2. 确保文件没有设置为只读。
3. 检查磁盘空间是否足够，并清理不必要的文件释放空间。
4. 检查文件的权限，确保应用程序有足够的权限去读写文件。

## 14800029 SQLite：数据库已满

**错误信息**

SQLite: The database is full.

**错误描述**

SQLite数据库已满。

**可能原因**

数据库已满，可能是由于数据量过大或磁盘空间不足导致的。

**处理步骤**

减小数据量或增加磁盘空间。

## 14800030 SQLite：无法打开数据库文件

**错误信息**

SQLite: Unable to open the database file.

**错误描述**

SQLite：无法打开数据库文件。

**可能原因**

1. 文件不存在，并且创建新数据库失败。
2. 文件存在，但是数据库文件损坏。
3. 文件权限问题，SQLite无法读写文件。
4. 磁盘空间不足。
5. 参见SQLITE_CANTOPEN的相关错误场景。

**处理步骤**

1. 确认数据库文件路径是否正确，检查文件权限，确保应用程序有足够的权限去读写文件。
2. 确认磁盘空间足够。

## 14800031 SQLite：TEXT或BLOB超出大小限制

**错误信息**

SQLite: TEXT or BLOB exceeds size limit.

**错误描述**

SQLite：TEXT或BLOB超出大小限制。

**可能原因**

1. 查询的结果集超过了SQLite所能处理的大小限制。
2. 参见SQLITE_TOOBIG的相关错误场景。

**处理步骤**

将大查询分解为多个小查询，每次处理一部分数据。

## 14800032 SQLite：由于违反约束而中止

**错误信息**

SQLite: Abort due to constraint violation.

**错误描述**

SQLite：由于违反约束而中止。

**可能原因**

1. 尝试写入SQLite数据库时违反了数据库的完整性约束条件。
2. 参见SQLITE_CONSTRAINT的相关错误场景。

**处理步骤**

检查试图插入或更新的数据是否违反了上述约束。

## 14800033 SQLite：数据类型不匹配

**错误信息**

SQLite: Data type mismatch.

**错误描述**

SQLite：数据类型不匹配。

**可能原因**

1. 执行一个SQL语句时，其中涉及的数据类型与数据库中存储的数据类型不匹配。
2. 参见SQLITE_MISMATCH的相关错误场景。

**处理步骤**

检查SQL语句中涉及的列的数据类型，确保插入、更新或查询的数据类型与列的数据类型相匹配。

## 14800034 SQLite：库使用不正确

**错误信息**

SQLite: Library used incorrectly.

**错误描述**

SQLite：库使用不正确。

**可能原因**

1. 表示数据库操作或者使用上下文不正确。这个错误通常发生在以下几种情况：
    - 数据库还没有完成操作就进行下一个操作。
    - 在一个数据库连接已经关闭后，继续对该连接进行操作。
    - 使用了已经释放或无效的数据库对象。
2. 参见SQLITE_MISUSE的相关错误场景。

**处理步骤**

1. 确保数据库操作之间有适当的同步，比如使用锁或其他同步机制。
2. 确保数据库连接在使用前是打开的，在结束操作后是关闭的。
3. 确保所有数据库对象在使用完毕后都已正确释放。

## 14800041 类型转换失败

**错误信息**

Type conversion failed.

**错误描述**

类型转换失败。

**可能原因**

通过resultSet的获取数据时，传入字段的数据类型不匹配。

**处理步骤**

确保传入字段的数据类型与使用的接口匹配。

## 14800047 WAL文件大小超过默认上限

**错误信息**

The WAL file size exceeds the default limit.

**错误描述**

WAL文件大小超过默认上限（512MB）。

**可能原因**

在开启读事务或者结果集未关闭的情况下，不断执行增删改操作，导致WAL文件大小超过默认上限。

**处理步骤**

检查结果集或者事务是否未关闭。

关闭所有的结果集或者事务。

## 14800050 获取订阅服务失败

**错误信息**

Failed to obtain the subscription service.

**错误描述**

获取订阅服务失败。

**可能原因**

当前平台不支持订阅服务。

**处理步骤**

需要在当前平台部署订阅服务。

## 14801001 上下文环境非Stage模型

**错误信息**

The operation is supported in the stage model only.

**错误描述**

该操作仅支持Stage模型。

**可能原因**

当前上下文环境非Stage模型。

**处理步骤**

切换当前上下文环境，使用Stage模型。

## 14801002 storeConfig中传入的dataGroupId参数非法

**错误信息**

Invalid data group ID.

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

对同一数据库表设置的分布式表类型前后不一致，分布式表类型可见[DistributedType](arkts-apis-data-relationalStore-e.md#distributedtype10)。

**处理步骤**

对同一数据库表设置的分布式表类型保持一致，属于端端同步的分布式表不可再设置为用于端云的同步表。