# Graph Store Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

##  31300000 Internal Error

**Error Message**

Inner error.

**Description**

Internal error.

**Possible Causes**

View the error log to determine the cause of the error. Possible causes include the following:
1. The GQL statement fails to be executed.
2. The internal state is abnormal.
3. There is API that is incorrectly used.
4. A system error, such as null pointer, unexpected restart of the data service, I/O error, or JS engine exception, occurs.

**Solution**

1. Check whether the APIs are called correctly. If not, apply necessary corrections.
2. If the problem persists, ask the user to restart or update the application or upgrade the device version.

##  31300001 Database File Corrupted

**Error Message**

Database corrupted.

**Description**

The database is corrupted when **read()** or **write()** is called.

**Possible Causes**

The database file is corrupted.

**Solution**

Currently, graph stores cannot be backed up or restored. If data loss is acceptable, delete the database and create a new one.

## 31300002 Database or Transaction Closed

**Error Message**

Already closed.

**Description**

The graph store or transaction is already closed.

**Possible Causes**

1. Before the current operation is performed, the graph store fails to be opened or [close](js-apis-data-graphStore-sys.md#close) is called to close the graph store.
2. Before the current operation is performed, [commit](js-apis-data-graphStore-sys.md#commit) is called to commit the transaction or [rollback](js-apis-data-graphStore-sys.md#rollback) is called to roll back the transaction.

**Solution**

1. Call [getStore](js-apis-data-graphStore-sys.md#graphstoregetstore) to open the graph store again. Ensure that the input parameters are correct.
2. Call [createTransaction](js-apis-data-graphStore-sys.md#createtransaction) to create a transaction.

## 31300003 Database not Respond

**Error Message**

The database is busy.

**Description**

The database does not respond.

**Possible Causes**

1. The graph store is being accessed by multiple processes of the same application.
2. Multiple threads in a process perform read and write operations at the same time, resulting in timeout on a thread.
3. The data written by a transaction using [write](js-apis-data-graphStore-sys.md#write) has not been committed or rolled back.

**Solution**

1. Avoid concurrent database operations from processes.
2. Wait for a while and try again.
3. Commit or roll back the unclosed transaction.

## 31300004 Insufficient Memory

**Error Message**

The database is out of memory.

**Description**

The graph store memory is insufficient.

**Possible Causes**

The data volume is too large or the memory allocated is insufficient.

**Solution**

Reduce the data volume or clear other processes to release the memory.

## 31300005 Database Is Full

**Error Message**

The database is full.

**Description**

The database is full.

**Possible Causes**

The data volume in the database reaches the upper limit or the disk space is insufficient.

**Solution**

Call [GraphStore.write](js-apis-data-graphStore-sys.md#write-1) or [Transaction.write](js-apis-data-graphStore-sys.md#write) to delete unnecessary data.

## 31300006 Duplicate Graph Name, Vertex Type or Property, or Edge Type or Property

**Error Message**

A duplicate graph name, vertex or edge type, or vertex or edge property name exists.

**Description**

Duplicate graph name, vertex type or property, or edge type or property exists.

**Possible Causes**

1. A graph with the same name already exists in the database.
2. Different vertexes use the same type or property.
3. Different edges use the same type or property.

**Solution**

When using [GraphStore.write](js-apis-data-graphStore-sys.md#write-1) or [Transaction.write](js-apis-data-graphStore-sys.md#write) to create a graph, check the graph name, vertex type ([Vertex.labels](js-apis-data-graphStore-sys.md#vertex)) and properties ([Vertex.properties](js-apis-data-graphStore-sys.md#vertex)), and edge type ([Edge.type](js-apis-data-graphStore-sys.md#edge)) and properties ([Edge.labels](js-apis-data-graphStore-sys.md#edge)) in the graph creation statement to prevent conflict.

## 31300007 Undefined Graph Name, Vertex Type or Property, or Edge Type or Property

**Error Message**

The graph name, vertex or edge type, or vertex or edge property is not defined.

**Description**

There is undefined graph name, vertex or edge type, or vertex or edge property.

**Possible Causes**

There is undefined graph name, vertex or edge type, or vertex or edge property.

**Solution**

Check for undefined graph name, vertex type ([Vertex.labels](js-apis-data-graphStore-sys.md#vertex)) or properties ([Vertex.properties](js-apis-data-graphStore-sys.md#vertex)), and edge type ([Edge.type](js-apis-data-graphStore-sys.md#edge)) or properties ([Edge.labels](js-apis-data-graphStore-sys.md#edge)) in [GraphStore.write](js-apis-data-graphStore-sys.md#write-1) or [Transaction.write](js-apis-data-graphStore-sys.md#write).

## 31300008 Invalid Graph Name, Vertex Type or Property, or Edge Type or Property

**Error Message**

The graph name, vertex or edge type, or vertex or edge property name does not conform to constraints.

**Description**

The specified graph name, vertex or edge type, or vertex or edge property violates constraints.

**Possible Causes**

1. The graph name exceeds 128 bytes.
2. The primary keys conflict.
3. Duplicate identifiers exist.

**Solution**

When using [GraphStore.write](js-apis-data-graphStore-sys.md#write-1) or [Transaction.write](js-apis-data-graphStore-sys.md#write) to create a graph, check the graph name, vertex type ([Vertex.labels](js-apis-data-graphStore-sys.md#vertex)) and properties ([Vertex.properties](js-apis-data-graphStore-sys.md#vertex)), and edge type ([Edge.type](js-apis-data-graphStore-sys.md#edge)) and properties ([Edge.labels](js-apis-data-graphStore-sys.md#edge)) in the graph creation statement to prevent conflict.

## 31300009 Syntax Error in the GQL Statement

**Error Message**

The GQL statement syntax error.

**Description**

The GQL statement has a syntax error.

**Possible Causes**

There is syntax error in the GQL statement.

**Solution**

Check and correct the syntax error in the GQL statement.

## 31300010 Semantic Error in the GQL Statement

**Error Message**

The GQL statement semantic error.

**Description**

The GQL statement has a semantic error.

**Possible Causes**

There is a semantic error in the GQL statement.

**Solution**

Check and correct the semantic error in the GQL statement.

## 31300012 Number of Graphs, Vertex Types or Properties, or Edge Types or Properties Exceeds the Limit

**Error Message**

The number of graph names, vertex or edge types, or vertex or edge properties exceeds the limit.

**Description**

The number of graph names, vertex types or properties, or edge types or properties exceeds the limit.

**Possible Causes**

The number of graph names, vertex types or properties, or edge types or properties exceeds the limit.

**Solution**

Reduce the number of vertex or edge types or properties. A graph store allows only one graph and a maximum of 1024 vertex or edge properties.

## 31300013 Conflict Constraints

**Error Message**

A conflicting constraint already exists.

**Description**

Conflict constraints are found.

**Possible Causes**

There are primary key conflicts, identifier conflicts, or other syntax conflicts.

**Solution**

Check for and resolve conflicts in the GQL statement.

## 31300014 Invalid Database Path

**Error Message**

Invalid database path.

**Description**

The graph store path is invalid.

**Possible Causes**

Access to the graph store is denied due to lack of permission.

**Solution**

Currently, graph stores do not support custom paths. The default sandbox path in [Context](../apis-ability-kit/js-apis-inner-app-context.md) is used. Correct the code by referring to the sample code in [getStore](js-apis-data-graphStore-sys.md#graphstoregetstore).

## 31300015 Key Configuration Changed

**Error Message**

Config changed.

**Description**

The key configuration of the graph store has been modified.

**Possible Causes**

Key configuration such as **name**, **securityLevel**, and **encrypt** is changed.

**Solution**

Restore the original configuration if required. Otherwise, delete the old graph store, use the new configuration to create a graph store, and import the data to the new graph store. **securityLevel** cannot be changed from a higher level to a lower one.
