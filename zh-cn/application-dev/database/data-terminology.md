# ArkData术语
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @widecode-->
<!--Designer: @widecode-->
<!--Tester: @logic42-->
<!--Adviser: @ge-yafang-->

## WAL模式

WAL（Write Ahead Log）模式是SQLite日志模式中的一种，区别于传统的rollback journal（回滚日志）模式，用于提升并发性能和写入效率。

详细介绍，请查看SQLite [Write-Ahead Logging](https://sqlite.org/wal.html)介绍。


## FULL模式

FULL模式是SQLite中数据库同步写入策略之一，当每次执行数据修改时，SQLite都会调用底层操作系统的xSync方法，保证所有数据均安全写入磁盘。可在系统崩溃、断电场景保证数据库不会损坏。

详细介绍，请查看SQLite [synchronous](https://sqlite.org/pragma.html#pragma_synchronous)。