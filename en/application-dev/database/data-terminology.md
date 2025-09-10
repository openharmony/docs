# ArkData Glossary
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @widecode-->
<!--Designer: @widecode-->
<!--Tester: @logic42-->
<!--Adviser: @ge-yafang-->

## Write Ahead Log (WAL)

WAL is a SQLite log mode, which is different from the traditional rollback journal mode. It is used to improve the concurrency performance and write efficiency.

For details, see SQLite [Write-Ahead Logging](https://sqlite.org/wal.html).


## FULL

FULL is one of the database synchronization write policies in SQLite. When data is modified each time, SQLite calls the xSync method of the underlying OS to ensure that all data is securely written to the disk. This ensures that the database is not damaged in the case of system breakdown or power failure.

For details, see SQLite [synchronous](https://sqlite.org/pragma.html#pragma_synchronous).
