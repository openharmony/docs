# @ohos.data.graphStore (Graph Database) (System API)

A graph database (GDB) is a data management system designed to efficiently store and query graph data. It organizes data as [vertexes](#vertex) and [edges](#edge). The **graphStore** module provides a complete set of mechanisms for local GDB management. It provides read (query), write (add, delete, and modify), and transaction management APIs that can directly run the Graph Query Language (GQL) statements to store, query, and analyze highly interconnected data.

- [Vertex](#vertex): represents an entity or instance, such as a person, enterprise, account, or any other item to be tracked. It is equivalent to a record, relationship, or row in a relational database, or a document in a document database.
- [Edge](#edge): represents the relationship between vertexes. Edge is a unique data abstraction exclusive to GDB, and must be materialized at runtime when queried.
- [Path](#path): a sequence of vertices and edges in a certain sequence.
- [PathSegment](#pathsegment): an edge along with its start and end vertexes in a path.

The **graphStore** module provides the following functionalities:

- [GraphStore](#graphstore): provides APIs for manipulating a GDB.
- [Result](#result): provides the result returned by the **read()** or **write()** API.
- [Transaction](#transaction): provides APIs for managing transaction objects.

> **NOTE**
> 
> - The initial APIs of this module are supported since API version 18. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The current page contains only the system interfaces of this module.

## Modules to Import

```ts
import { graphStore } from '@kit.ArkData';
```

## graphStore.getStore

getStore(context: Context, config: StoreConfig): Promise&lt;GraphStore&gt;

Obtains a GraphStore instance for GDB operations. You can set parameters for the instance as required and call related APIs through this instance to perform data operations. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.DataIntelligence.Core

**Parameters**

| Name | Type                            | Mandatory| Description                                                        |
| ------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| context | Context                          | Yes  | Application context. The stage model is recommended.<br>For details about the application context of the FA model, see [Context](../apis-ability-kit/js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md).|
| config  | [StoreConfig](#storeconfig) | Yes  | Configuration of the GDB.                               |

**Return value**

| Type                                     | Description                             |
| ----------------------------------------- | --------------------------------- |
| Promise&lt;[GraphStore](#graphstore)&gt; | Promise used to return the **GraphStore** instance obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Graph Store Error Codes](errorcode-data-gdb.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 202  | Permission verification failed, application which is not a system application uses system API. |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 31300000  | Inner error. |
| 31300001  | Database corrupted. |
| 31300014  | Failed to open or delete database with an invalid database path. |
| 31300015  | StoreConfig, for example, securityLevel or encrypt, is changed. |

**Example**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

let store: graphStore.GraphStore | null = null;

class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    const STORE_CONFIG: graphStore.StoreConfig = {
      name: "testGraphDb",
      securityLevel: graphStore.SecurityLevel.S2
    };

    graphStore.getStore(this.context, STORE_CONFIG).then(async (gdb: graphStore.GraphStore) => {
      store = gdb;
      console.info('Get GraphStore successfully.');
    }).catch((err: BusinessError) => {
      console.error(`Get GraphStore failed, code is ${err.code}, message is ${err.message}`);
    })
  }
}
```

## graphStore.deleteStore

deleteStore(context: Context, config: StoreConfig): Promise&lt;void&gt;

Deletes a graph store. This API uses a promise to return the result.

Before calling this API, call [close](#close) to close the graph store to be deleted. After the deletion, you are advised to set the graph store instance to null.

**System capability**: SystemCapability.DistributedDataManager.DataIntelligence.Core

**Parameters**

| Name | Type   | Mandatory| Description                                                        |
| ------- | ------- | ---- | ------------------------------------------------------------ |
| context | Context                          | Yes  | Application context. The stage model is recommended.<br>For details about the application context of the FA model, see [Context](../apis-ability-kit/js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md).|
| config  | [StoreConfig](#storeconfig) | Yes  | Configuration of the graph store to delete.<br>**Constraints**<br>Only **config.name** is used to identify the graph store to be deleted.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Graph Store Error Codes](errorcode-data-gdb.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 202  | Permission verification failed, application which is not a system application uses system API. |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 31300000  | Inner error. |
| 31300014  | Failed to open or delete database with an invalid database path. |

**Example**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

let store: graphStore.GraphStore | null = null;

const STORE_CONFIG: graphStore.StoreConfig = {
  name: "testGraphDb",
  securityLevel: graphStore.SecurityLevel.S2
};

class EntryAbility extends UIAbility {
  onWindowStageDestroy() {
    graphStore.deleteStore(this.context, STORE_CONFIG).then(() => {
      store = null;
      console.info('Delete GraphStore successfully.');
    }).catch((err: BusinessError) => {
      console.error(`Delete GraphStore failed, code is ${err.code},message is ${err.message}`);
    })
  }
}
```

## StoreConfig

Represents the configuration of a graph store.

**System capability**: SystemCapability.DistributedDataManager.DataIntelligence.Core

| Name       | Type         | Mandatory| Description                                                     |
| ------------- | ------------- | ---- | --------------------------------------------------------- |
| name          | string        | Yes  | Database file name, which is the unique identifier of the graph store.<br>**Constraints**<br>1. The file name cannot exceed 128 bytes.<br>2. The file name does not include the .db filename extension.|
| securityLevel | [SecurityLevel](#securitylevel) | Yes  | Security level of the graph store.<br>**Constraints**<br>1. The security level cannot be downgraded. For example, you can change the security level from S2 to S3, but not from S3 to S2.<br>2. If the security level of a graph store needs to be changed, call [close](#close) to close the graph store instance, and then call [getStore](#graphstoregetstore) with **StoreConfig**.|
| encrypt | boolean       | No  | Whether to encrypt the graph store.<br> The value **true** means to encrypt the graph store;<br> the value **false** means the opposite.<br>**Constraints**<br>1. It is not allowed to change **encrypt** from **true** to **false**.<br>2. If you need to change **encrypt** from **false** to **true**, call [close](#close) to close the graph store instance, and then call [getStore](#graphstoregetstore) with **StoreConfig**.|

## SecurityLevel

Enumerates the graph store security levels. Use the enum name rather than the enum value.

**System capability**: SystemCapability.DistributedDataManager.DataIntelligence.Core

| Name| Value  | Description                                                        |
| ---- | ---- | ------------------------------------------------------------ |
| S1   | 1    | Low security level, where any data leakage may result in minor impact. An example would be a graph store containing non-sensitive system data such as wallpapers.|
| S2   | 2    | Medium security level, where any data leakage may result in moderate impact. An example would be a graph store containing audio and video data created by users or call logs.|
| S3   | 3    | High security level, where any data leakage may result in severe impact. An example would be a graph store containing user fitness, health, and location data.|
| S4   | 4    | Critical security level, where any data leakage may result in critical impact. An example would be a graph store containing authentication credentials and financial data.|

## ValueType

type ValueType = null | number | string

Represents the allowed value types. The value type varies, depending on its usage. 

**System capability**: SystemCapability.DistributedDataManager.DataIntelligence.Core

| Type   | Description                |
| ------- | -------------------- |
| null    | The value is null.|
| number  | The value can be any number.|
| string  | The value can be any string.|

## Vertex

Represents information about a vertex. Vertex is used only as the type in the return value ([Result](#result)) and cannot be customized. You can use [read](#read) to obtain its value.

**System capability**: SystemCapability.DistributedDataManager.DataIntelligence.Core

| Name         | Type                         | Mandatory | Description          |
| ----------- | --------------------------- | --- | ------------ |
| vid        | string | Yes  | Identifier of the vertex. The value cannot be customized. It is a globally unique identifier allocated by the system when a vertex is written by [GraphStore.write](#write-1) or [Transaction.write](#write).|
| labels     | Array&lt;string&gt; | Yes  | Labels of the vertex. The labels are specified in the GQL statement in [GraphStore.write](#write-1) or [Transaction.write](#write). Each label is case-insensitive, stored in uppercase format, and cannot exceed 128 bytes.|
| properties | Record&lt;string, [ValueType](#valuetype)&gt; | Yes  | Properties of the vertex. The key has a maximum length of 128 bytes, with a limit of 1024 entries. It is specified in the GQL statement in [GraphStore.write](#write-1) or [Transaction.write](#write). If the value is a string, it cannot exceed 64 x 1024 bytes.|

## Edge

Represents information about an edge. **Edge** is used only as the type in the return value ([Result](#result)) and cannot be customized. You can use [read](#read) to obtain its value.

**System capability**: SystemCapability.DistributedDataManager.DataIntelligence.Core

| Name         | Type                         | Mandatory | Description          |
| ----------- | --------------------------- | --- | ------------ |
| eid        | string | Yes  | Identifier of the edge. The value cannot be customized. It is a globally unique identifier allocated by the system when an edge is written by [GraphStore.write](#write-1) or [Transaction.write](#write).|
| type       | string | Yes  | Type of the edge. It is specified in the GQL statement in [GraphStore.write](#write-1) or [Transaction.write](#write). It is case-insensitive, stored in uppercase format, and cannot exceed 128 bytes.|
| startVid   | string | Yes  | Identifier of the start vertex. The value cannot be customized. It is a globally unique identifier allocated by the system when a vertex is written by [GraphStore.write](#write-1) or [Transaction.write](#write).|
| endVid     | string | Yes  | Identifier of the end vertex. The value cannot be customized. It is a globally unique identifier allocated by the system when a vertex is written by [GraphStore.write](#write-1) or [Transaction.write](#write).|
| properties | Record&lt;string, [ValueType](#valuetype)&gt; | Yes  | Properties of the edge. The key has a maximum length of 128 bytes, with a limit of 1024 entries. It is specified in the GQL statement in [GraphStore.write](#write-1) or [Transaction.write](#write). If the value is a string, it cannot exceed 64 x 1024 bytes.|

## PathSegment

Represents information about a path segment, including the edge along with the start and end vertexes. **PathSegment** is used only as the type of the return value ([Path.segments](#path)) and cannot be customized. You can use the [read](#read) API to obtain related information.

**System capability**: SystemCapability.DistributedDataManager.DataIntelligence.Core

| Name         | Type                         | Mandatory | Description          |
| ----------- | --------------------------- | --- | ------------ |
| start | [Vertex](#vertex) | Yes  | Start vertex of the path segment.|
| end   | [Vertex](#vertex) | Yes  | End vertex of the path segment.|
| edge  | [Edge](#edge)     | Yes  | Edge of the path segment.|

## Path

Represents information about a path. **Path** is used only as the type in the return value ([Result](#result)) and cannot be customized. You can use [read](#read) to obtain its value.

**System capability**: SystemCapability.DistributedDataManager.DataIntelligence.Core

| Name         | Type                         | Mandatory | Description          |
| ----------- | --------------------------- | --- | ------------ |
| start    | [Vertex](#vertex) | Yes  | Start vertex of the path.|
| end      | [Vertex](#vertex) | Yes  | End vertex of the path.|
| length   | number            | Yes  | Number of segments in the path, which cannot exceed 1024.|
| segments | Array&lt;[PathSegment](#pathsegment)&gt; | Yes  | Segments in the path.|

## Result

Represents the GQL statement execution result.

**System capability**: SystemCapability.DistributedDataManager.DataIntelligence.Core

| Name         | Type                         | Mandatory | Description          |
| ----------- | --------------------------- | --- | ------------ |
| records | Array&lt;Record&lt;string, Object&gt;&gt; | No  | GQL statement execution result. It is left blank by default.<br>If there is an execution result, the object type varies depending on the GQL statement. It can be [Vertex](#vertex), [Edge](#edge), [Path](#path), or [ValueType](#valuetype).|


## Transaction

Provides APIs for transaction management in a graph store.

Operations on different transaction objects are isolated. The graph stores use database-level locks. If [commit](#commit) or [rollback](#rollback) is not called after a transaction is written using [write](#write), calling [read](#read) or [write](#write) for another transaction instance or calling [GraphStore.read](#read-1) or [GraphStore.write](#write-1) with the **GraphStore** instance will return error 31300003. If [commit](#commit) or [rollback](#rollback) is not called after [read](#read) is called for a transaction, calling [write](#write) for another transaction instance or calling [GraphStore.write](#write-1) with the **GraphStore** instance will return error 31300003.

Before calling any **Transaction** API, you must create a transaction instance using [createTransaction](#createtransaction).

### read

read(gql: string): Promise&lt;Result&gt;

Reads data, which includes the data written by using [GraphStore.write](#write-1), data written by another transaction using [write](#write) and committed by using [commit](#commit), and data written by the current transaction using [write](#write).

**System capability**: SystemCapability.DistributedDataManager.DataIntelligence.Core

**Parameters**

| Name| Type                         | Mandatory| Description                      |
| ------ | ----------------------------- | ---- | -------------------------- |
| gql  | string  | Yes  | GQL statement to execute, which cannot exceed 1024 x 1024 bytes.|

**Return value**

| Type                 | Description                                             |
| --------------------- | ------------------------------------------------- |
| Promise&lt;[Result](#result)&gt; | Promise used to return the execution result if the operation is successful.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Graph Store Error Codes](errorcode-data-gdb.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 202  | Permission verification failed, application which is not a system application uses system API. |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 31300000  | Inner error. |
| 31300001  | Database corrupted. |
| 31300002  | Already closed. |
| 31300003  | The database is busy. |
| 31300004  | The database is out of memory. |
| 31300005  | The database is full. |
| 31300006  | A duplicate graph name, vertex or edge type, or vertex or edge property name exists. |
| 31300007  | The graph name, vertex or edge type, or vertex or edge property is not defined. |
| 31300008  | The graph name, vertex or edge type, or vertex or edge property name does not conform to constraints. |
| 31300009  | The GQL statement syntax error. |
| 31300010  | The GQL statement semantic error. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const QUERY_PATH_GQL = "MATCH path=(a:Person {name : \'name_1\'})-[]->{2, 2}(b:Person {name : \'name_3\'}) RETURN path;";
if(transaction != undefined) {
  (transaction as graphStore.Transaction).read(QUERY_PATH_GQL).then((result: graphStore.Result) => {
    console.info('Read successfully');
    result.records?.forEach((data) => {
      for (let item of Object.entries(data)) {
        const key = item[0];
        const value = item[1];
        const path = value as graphStore.Path;
        console.info(`key : ${key}, path.length : ${path.length}`);
      }
    });
  }).catch((err: BusinessError) => {
    console.error(`Read failed, code is ${err.code}, message is ${err.message}`);
  })
}
```

### write

write(gql: string): Promise&lt;Result&gt;

Writes data. You can use this API to add, delete, and modify data. Currently, it cannot be used to modify the table structure (types or properties of [Vertex](#vertex) and [Edge](#edge)), create or delete graphs or indexes. This API cannot be used to execute transaction operation statements, including **START TRANSACTION**, **COMMIT**, and **ROLLBACK**.

**System capability**: SystemCapability.DistributedDataManager.DataIntelligence.Core

**Parameters**

| Name| Type                         | Mandatory| Description                      |
| ------ | ----------------------------- | ---- | -------------------------- |
| gql  | string  | Yes  | GQL statement to execute, which cannot exceed 1024 x 1024 bytes.|

**Return value**

| Type                 | Description                                             |
| --------------------- | ------------------------------------------------- |
| Promise&lt;[Result](#result)&gt; | Promise used to return the execution result if the operation is successful.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Graph Store Error Codes](errorcode-data-gdb.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 202  | Permission verification failed, application which is not a system application uses system API. |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 31300000  | Inner error. |
| 31300001  | Database corrupted. |
| 31300002  | Already closed. |
| 31300003  | The database is busy. |
| 31300004  | The database is out of memory. |
| 31300005  | The database is full. |
| 31300006  | A duplicate graph name, vertex or edge type, or vertex or edge property name exists. |
| 31300007  | The graph name, vertex or edge type, or vertex or edge property is not defined. |
| 31300008  | The graph name, vertex or edge type, or vertex or edge property name does not conform to constraints. |
| 31300009  | The GQL statement syntax error. |
| 31300010  | The GQL statement semantic error. |
| 31300012  | The number of graph names, vertex or edge types, or vertex or edge properties exceeds the limit. |
| 31300013  | A conflicting constraint already exists. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const INSERT_GQL = "INSERT (:Person {name: 'name_1', age: 11});";
if(transaction != undefined) {
  (transaction as graphStore.Transaction).write(INSERT_GQL).then(() => {
    console.info('Write successfully');
  }).catch((err: BusinessError) => {
    console.error(`Write failed, code is ${err.code}, message is ${err.message}`);
  })
}
```

### commit

commit(): Promise&lt;void&gt;

Commits the GQL statements executed in this transaction. After the commit, the transaction will be no longer available.

**System capability**: SystemCapability.DistributedDataManager.DataIntelligence.Core

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Graph Store Error Codes](errorcode-data-gdb.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 202  | Permission verification failed, application which is not a system application uses system API. |
| 31300000  | Inner error. |
| 31300001  | Database corrupted. |
| 31300002  | Already closed. |
| 31300003  | The database is busy. |
| 31300004  | The database is out of memory. |
| 31300005  | The database is full. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

if(transaction != undefined) {
  (transaction as graphStore.Transaction).commit().then(() => {
    console.info(`Commit successfully`);
  }).catch ((err: BusinessError) => {
    console.error(`Commit failed, code is ${err.code}, message is ${err.message}`);
  })
}
```

### rollback

rollback(): Promise&lt;void&gt;

Rolls back the GQL statements executed in this transaction. After the rollback, the transaction will be no longer available.

**System capability**: SystemCapability.DistributedDataManager.DataIntelligence.Core

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Graph Store Error Codes](errorcode-data-gdb.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 202  | Permission verification failed, application which is not a system application uses system API. |
| 31300000  | Inner error. |
| 31300001  | Database corrupted. |
| 31300002  | Already closed. |
| 31300003  | The database is busy. |
| 31300004  | The database is out of memory. |
| 31300005  | The database is full. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

if(transaction != undefined) {
  (transaction as graphStore.Transaction).rollback().then(() => {
    console.info(`Rollback successfully`);
  }).catch ((err: BusinessError) => {
    console.error(`Rollback failed, code is ${err.code}, message is ${err.message}`);
  })
}
```


## GraphStore

Provides APIs for managing the data in a graph store.

Before calling any **GraphStore** API, you must create a **GraphStore** instance by using [getStore](#graphstoregetstore).

### read

read(gql: string): Promise&lt;Result&gt;

Reads data, which includes the data written by using [write](#write-1) and the data written by using [Transaction.write](#write) and committed by [Transaction.commit](#commit) in all transactions.

**System capability**: SystemCapability.DistributedDataManager.DataIntelligence.Core

**Parameters**

| Name| Type                         | Mandatory| Description                      |
| ------ | ----------------------------- | ---- | -------------------------- |
| gql  | string  | Yes  | GQL statement to execute, which cannot exceed 1024 x 1024 bytes.|

**Return value**

| Type                 | Description                                             |
| --------------------- | ------------------------------------------------- |
| Promise&lt;[Result](#result)&gt; | Promise used to return the execution result if the operation is successful.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Graph Store Error Codes](errorcode-data-gdb.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 202  | Permission verification failed, application which is not a system application uses system API. |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 31300000  | Inner error. |
| 31300001  | Database corrupted. |
| 31300002  | Already closed. |
| 31300003  | The database is busy. |
| 31300004  | The database is out of memory. |
| 31300005  | The database is full. |
| 31300006  | A duplicate graph name, vertex or edge type, or vertex or edge property name exists. |
| 31300007  | The graph name, vertex or edge type, or vertex or edge property is not defined. |
| 31300008  | The graph name, vertex or edge type, or vertex or edge property name does not conform to constraints. |
| 31300009  | The GQL statement syntax error. |
| 31300010  | The GQL statement semantic error. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const QUERY_PATH_GQL = "MATCH path=(a:Person {name : \'name_1\'})-[]->{2, 2}(b:Person {name : \'name_3\'}) RETURN path;";
if(store != null) {
  (store as graphStore.GraphStore).read(QUERY_PATH_GQL).then((result: graphStore.Result) => {
    console.info('Read successfully');
    result.records?.forEach((data) => {
      for (let item of Object.entries(data)) {
        const key = item[0];
        const value = item[1];
        const path = value as graphStore.Path;
        console.info(`key : ${key}, path.length : ${path.length}`);
      }
    });
  }).catch((err: BusinessError) => {
    console.error(`Read failed, code is ${err.code}, message is ${err.message}`);
  })
}
```

### write

write(gql: string): Promise&lt;Result&gt;

Writes data. You can use this API to create or delete a graph, and add, delete, or modify data. Currently, the table structure (types or properties of [Vertex](#vertex) and [Edge](#edge)) cannot be modified. This API cannot be used to execute transaction operation statements, including **START TRANSACTION**, **COMMIT**, and **ROLLBACK**.

**System capability**: SystemCapability.DistributedDataManager.DataIntelligence.Core

**Parameters**

| Name| Type                         | Mandatory| Description                      |
| ------ | ----------------------------- | ---- | -------------------------- |
| gql  | string  | Yes  | GQL statement to execute, which cannot exceed 1024 x 1024 bytes.|

**Return value**

| Type                 | Description                                             |
| --------------------- | ------------------------------------------------- |
| Promise&lt;[Result](#result)&gt; | Promise used to return the execution result if the operation is successful.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Graph Store Error Codes](errorcode-data-gdb.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 202  | Permission verification failed, application which is not a system application uses system API. |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 31300000  | Inner error. |
| 31300001  | Database corrupted. |
| 31300002  | Already closed. |
| 31300003  | The database is busy. |
| 31300004  | The database is out of memory. |
| 31300005  | The database is full. |
| 31300006  | A duplicate graph name, vertex or edge type, or vertex or edge property name exists. |
| 31300007  | The graph name, vertex or edge type, or vertex or edge property is not defined. |
| 31300008  | The graph name, vertex or edge type, or vertex or edge property name does not conform to constraints. |
| 31300009  | The GQL statement syntax error. |
| 31300010  | The GQL statement semantic error. |
| 31300012  | The number of graph names, vertex or edge types, or vertex or edge properties exceeds the limit. |
| 31300013  | A conflicting constraint already exists. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const CREATE_GRAPH_GQL = "CREATE GRAPH test { (person:Person {name STRING, age INT}),(person)-[:Friend {year INT}]->(person) };"
if(store != null) {
  (store as graphStore.GraphStore).write(CREATE_GRAPH_GQL).then(() => {
    console.info('Write successfully');
  }).catch((err: BusinessError) => {
    console.error(`Write failed, code is ${err.code}, message is ${err.message}`);
  })
}
```

### createTransaction

createTransaction(): Promise&lt;Transaction&gt;

Creates a transaction instance. Currently, a maximum of four transaction instances can be created at a time in a graph store.

**System capability**: SystemCapability.DistributedDataManager.DataIntelligence.Core

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;[Transaction](#transaction)&gt; | Promise used to return the created transaction instance.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Graph Store Error Codes](errorcode-data-gdb.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 202  | Permission verification failed, application which is not a system application uses system API. |
| 31300000  | Inner error. |
| 31300001  | Database corrupted. |
| 31300002  | Already closed. |
| 31300003  | The database is busy. |
| 31300004  | The database is out of memory. |
| 31300005  | The database is full. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let transaction: graphStore.Transaction | undefined = undefined;

if(store != null) {
  (store as graphStore.GraphStore).createTransaction().then((trans: graphStore.Transaction) => {
    transaction = trans;
    console.info('createTransaction successfully');
  }).catch((err: BusinessError) => {
    console.error(`createTransaction failed, code is ${err.code}, message is ${err.message}`);
  })
}
```

### close

close(): Promise&lt;void&gt;

Closes this graph store. After this API is called, uncommitted transactions will be rolled back.

**System capability**: SystemCapability.DistributedDataManager.DataIntelligence.Core

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Graph Store Error Codes](errorcode-data-gdb.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 202  | Permission verification failed, application which is not a system application uses system API. |
| 31300000  | Inner error. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

if(store != null) {
  (store as graphStore.GraphStore).close().then(() => {
    console.info(`Close successfully`);
  }).catch ((err: BusinessError) => {
    console.error(`Close failed, code is ${err.code}, message is ${err.message}`);
  })
}
```
