# Relational Database

The relational database (RDB) manages data based on relational models. With the underlying SQLite database, the RDB provides a complete mechanism for managing local databases. To satisfy different needs in complicated scenarios, the RDB offers a series of methods for performing operations such as adding, deleting, modifying, and querying data, and supports direct execution of SQL statements.

This module provides the following RDB-related functions:

- [RdbPredicates](#rdbpredicates): predicates indicating the nature, feature, or relationship of a data entity in an RDB store. It is used to define the operation conditions for an RDB store.
- [RdbStore](#rdbstore): provides APIs for managing an RDB store.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import data_rdb from '@ohos.data.rdb';
```

## data_rdb.getRdbStore

getRdbStore(context: Context, config: StoreConfig, version: number, callback: AsyncCallback&lt;RdbStore&gt;): void

Obtains an RDB store. This API uses an asynchronous callback to return the result. You can set parameters for the RDB store based on service requirements and call APIs to perform data operations.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| context | Context | Yes| Context of the application or function.<br>See [Context](js-apis-Context.md) for versions earlier than API version 9.<br>See [Context](js-apis-ability-context.md) for API version 9 or later.|
| config | [StoreConfig](#storeconfig) | Yes| Configuration of the RDB store.|
| version | number | Yes| RDB store version.|
| callback | AsyncCallback&lt;[RdbStore](#rdbstore)&gt; | Yes| Callback invoked to return the RDB store obtained.|

**Example**

```js
const STORE_CONFIG = { name: "RdbTest.db"}
data_rdb.getRdbStore(this.context, STORE_CONFIG, 1, function (err, rdbStore) {
    if (err) {
        console.info("Failed to get RdbStore, err: " + err)
        return
    }
    console.log("Got RdbStore successfully.")
})
```

## data_rdb.getRdbStore

getRdbStore(context: Context, config: StoreConfig, version: number): Promise&lt;RdbStore&gt;

Obtains an RDB store. This API uses a promise to return the result. You can set parameters for the RDB store based on service requirements and call APIs to perform data operations.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| context | Context | Yes| Context of the application or function.<br>See [Context](js-apis-Context.md) for versions earlier than API version 9.<br>See [Context](js-apis-ability-context.md) for API version 9 or later.|
| config | [StoreConfig](#storeconfig) | Yes| Configuration of the RDB store.|
| version | number | Yes| RDB store version.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[RdbStore](#rdbstore)&gt; | Promise used to return the RDB store obtained.|

**Example**

```js
const STORE_CONFIG = { name: "RdbTest.db" }
let promise = data_rdb.getRdbStore(this.context, STORE_CONFIG, 1);
promise.then(async (rdbStore) => {
    console.log("Got RdbStore successfully.")
}).catch((err) => {
    console.log("Failed to get RdbStore, err: " + err)
})
```

## data_rdb.deleteRdbStore

deleteRdbStore(context: Context, name: string, callback: AsyncCallback&lt;void&gt;): void

Deletes an RDB store. This API uses an asynchronous callback to return the result. 

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| context | Context | Yes| Context of the application or function.<br>See [Context](js-apis-Context.md) for versions earlier than API version 9.<br>See [Context](js-apis-ability-context.md) for API version 9 or later.|
| name | string | Yes| Name of the RDB store to delete.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback invoked to return the result.|

**Example**
```js
data_rdb.deleteRdbStore(this.context, "RdbTest.db", function (err, rdbStore) {
    if (err) {
        console.info("Failed to delete RdbStore, err: " + err)
        return
    }
    console.log("Deleted RdbStore successfully.")
})
```

## data_rdb.deleteRdbStore

deleteRdbStore(context: Context, name: string): Promise&lt;void&gt;

Deletes an RDB store. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| context | Context | Yes| Context of the application or function.<br>See [Context](js-apis-Context.md) for versions earlier than API version 9.<br>See [Context](js-apis-ability-context.md) for API version 9 or later.|
| name | string | Yes| Name of the RDB store to delete.|

**Return value**
| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**
```js
let promise = data_rdb.deleteRdbStore(this.context, "RdbTest.db")
promise.then(()=>{
    console.log("Deleted RdbStore successfully.")
}).catch((err) => {
    console.info("Failed to delete RdbStore, err: " + err)
})
```


## RdbPredicates

Defines predicates for an RDB store. This class determines whether the conditional expression for the RDB store is true or false.


### constructor

constructor(name: string)


A constructor used to create an **RdbPredicates** object.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string | Yes| Database table name.|

**Example**
```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
```

### inDevices<sup>8+</sup>

inDevices(devices: Array&lt;string&gt;): RdbPredicates


Specifies a remote device on the network during distributed database synchronization.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| devices | Array&lt;string&gt; | Yes| ID of the remote device to specify.|

**Return value**
| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that matches the specified field.|

**Example**
```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.inDevices(['12345678abcde'])
```

### inAllDevices<sup>8+</sup>

inAllDevices(): RdbPredicates


Connects to all remote devices on the network during distributed database synchronization.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Return value**
| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that matches the specified field.|

**Example**
```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.inAllDevices()
```

### equalTo

equalTo(field: string, value: ValueType): RdbPredicates


Sets the **RdbPredicates** to match the field with data type **ValueType** and value equal to the specified value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the database table.|
| value | [ValueType](#valuetype) | Yes| Value to match the **RdbPredicates**.|

**Return value**
| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that matches the specified field.|

**Example**
```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.equalTo("NAME", "lisi")
```


### notEqualTo

notEqualTo(field: string, value: ValueType): RdbPredicates


Sets the **RdbPredicates** to match the field with data type **ValueType** and value not equal to the specified value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the database table.|
| value | [ValueType](#valuetype) | Yes| Value to match the **RdbPredicates**.|

**Return value**
| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that matches the specified field.|

**Example**
```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.notEqualTo("NAME", "lisi")
```


### beginWrap

beginWrap(): RdbPredicates


Adds a left parenthesis to the **RdbPredicates**.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Return value**
| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** with a left parenthesis.|

**Example**
```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.equalTo("NAME", "lisi")
    .beginWrap()
    .equalTo("AGE", 18)
    .or()
    .equalTo("SALARY", 200.5)
    .endWrap()
```


### endWrap

endWrap(): RdbPredicates


Adds a right parenthesis to the **RdbPredicates**.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Return value**
| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** with a right parenthesis.|

**Example**
```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.equalTo("NAME", "lisi")
    .beginWrap()
    .equalTo("AGE", 18)
    .or()
    .equalTo("SALARY", 200.5)
    .endWrap()
```


### or

or(): RdbPredicates


Adds the OR condition to the **RdbPredicates**.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Return value**
| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** with the OR condition.|

**Example**
```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.equalTo("NAME", "Lisa")
    .or()
    .equalTo("NAME", "Rose")
```


### and

and(): RdbPredicates


Adds the AND condition to the **RdbPredicates**.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Return value**
| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** with the AND condition.|

**Example**
```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.equalTo("NAME", "Lisa")
    .and()
    .equalTo("SALARY", 200.5)
```


### contains

contains(field: string, value: string): RdbPredicates

Sets the **RdbPredicates** to match a string containing the specified value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the database table.|
| value | string | Yes| Value to match the **RdbPredicates**.|

**Return value**
| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that matches the specified field.|

**Example**
```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.contains("NAME", "os")
```


### beginsWith

beginsWith(field: string, value: string): RdbPredicates


Sets the **RdbPredicates** to match a string that starts with the specified value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the database table.|
| value | string | Yes| Value to match the **RdbPredicates**.|

**Return value**
| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that matches the specified field.|

**Example**
```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.beginsWith("NAME", "os")
```


### endsWith

endsWith(field: string, value: string): RdbPredicates


Sets the **RdbPredicates** to match a string that ends with the specified value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the database table.|
| value | string | Yes| Value to match the **RdbPredicates**.|

**Return value**
| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that matches the specified field.|

**Example**
```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.endsWith("NAME", "se")
```


### isNull

isNull(field: string): RdbPredicates


Sets the **RdbPredicates** to match the field whose value is null.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the database table.|

**Return value**
| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that matches the specified field.|

- Example
```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.isNull("NAME")
```


### isNotNull

isNotNull(field: string): RdbPredicates


Sets the **RdbPredicates** to match the field whose value is not null.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the database table.|

**Return value**
| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that matches the specified field.|

**Example**
```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.isNotNull("NAME")
```


### like

like(field: string, value: string): RdbPredicates


Sets the **RdbPredicates** to match a string that is similar to the specified value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the database table.|
| value | string | Yes| Value to match the **RdbPredicates**.|

**Return value**
| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that matches the specified field.|

**Example**
```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.like("NAME", "%os%")
```


### glob

glob(field: string, value: string): RdbPredicates


Sets the **RdbPredicates** to match the specified string.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the database table.|
| value | string | Yes| Value to match the **RdbPredicates**.<br><br>Wildcards are supported. * indicates zero, one, or multiple digits or characters. **?** indicates a single digit or character.|

**Return value**
| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that matches the specified field.|

**Example**
```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.glob("NAME", "?h*g")
```


### between

between(field: string, low: ValueType, high: ValueType): RdbPredicates


Sets the **RdbPredicates** to match the field with data type **ValueType** and value within the specified range.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the database table.|
| low | [ValueType](#valuetype) | Yes| Minimum value to match the **RdbPredicates**.|
| high | [ValueType](#valuetype) | Yes| Maximum value to match the **RdbPredicates**.|

**Return value**
| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that matches the specified field.|

**Example**
```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.between("AGE", 10, 50)
```


### notBetween

notBetween(field: string, low: ValueType, high: ValueType): RdbPredicates


Sets the **RdbPredicates** to match the field with data type **ValueType** and value out of the specified range.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the database table.|
| low | [ValueType](#valuetype) | Yes| Minimum value to match the **RdbPredicates**.|
| high | [ValueType](#valuetype) | Yes| Maximum value to match the **RdbPredicates**.|

**Return value**
| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that matches the specified field.|

**Example**
```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.notBetween("AGE", 10, 50)
```


### greaterThan

greaterThan(field: string, value: ValueType): RdbPredicates

Sets the **RdbPredicates** to match the field with data type **ValueType** and value greater than the specified value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the database table.|
| value | [ValueType](#valuetype) | Yes| Value to match the **RdbPredicates**.|

**Return value**
| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that matches the specified field.|

**Example**
```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.greaterThan("AGE", 18)
```


### lessThan

lessThan(field: string, value: ValueType): RdbPredicates


Sets the **RdbPredicates** to match the field with data type **ValueType** and value less than the specified value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the database table.|
| value | [ValueType](#valuetype) | Yes| Value to match the **RdbPredicates**.|

**Return value**
| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that matches the specified field.|

**Example**
```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.lessThan("AGE", 20)
```


### greaterThanOrEqualTo


greaterThanOrEqualTo(field: string, value: ValueType): RdbPredicates


Sets the **RdbPredicates** to match the field with data type **ValueType** and value greater than or equal to the specified value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the database table.|
| value | [ValueType](#valuetype) | Yes| Value to match the **RdbPredicates**.|

**Return value**
| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that matches the specified field.|

**Example**
```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.greaterThanOrEqualTo("AGE", 18)
```


### lessThanOrEqualTo


lessThanOrEqualTo(field: string, value: ValueType): RdbPredicates


Sets the **RdbPredicates** to match the field with data type **ValueType** and value less than or equal to the specified value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the database table.|
| value | [ValueType](#valuetype) | Yes| Value to match the **RdbPredicates**.|

**Return value**
| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that matches the specified field.|

**Example**
```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.lessThanOrEqualTo("AGE", 20)
```


### orderByAsc


orderByAsc(field: string): RdbPredicates


Sets the **RdbPredicates** to match the column with values sorted in ascending order.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the database table.|

**Return value**
| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that matches the specified field.|

**Example**
```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.orderByAsc("NAME")
```


### orderByDesc


orderByDesc(field: string): RdbPredicates


Sets the **RdbPredicates** to match the column with values sorted in descending order.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the database table.|

**Return value**
| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that matches the specified field.|

**Example**
```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.orderByDesc("AGE")
```


### distinct

distinct(): RdbPredicates


Sets the **RdbPredicates** to filter out duplicate records.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Return value**
| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that can filter out duplicate records.|

**Example**
```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.equalTo("NAME", "Rose").distinct("NAME")
let promise = rdbStore.query(predicates, ["NAME"])
promise.then((resultSet) => {
    console.log("resultSet column names:" + resultSet.columnNames)
    console.log("resultSet column count:" + resultSet.columnCount)
}).catch((err) => {
    console.log("query err.")
})
```


### limitAs

limitAs(value: number): RdbPredicates


Sets the **RdbPredicates** to specify the maximum number of records.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | number | Yes| Maximum number of records.|

**Return value**
| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that specifies the maximum number of records.|

**Example**
```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.equalTo("NAME", "Rose").limitAs(3)
```


### offsetAs

offsetAs(rowOffset: number): RdbPredicates


Sets the **RdbPredicates** to specify the start position of the returned result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| rowOffset | number | Yes| Number of rows to offset from the beginning. The value is a positive integer.|

**Return value**
| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that specifies the start position of the returned result.|

**Example**
```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.equalTo("NAME", "Rose").offsetAs(3)
```


### groupBy

groupBy(fields: Array&lt;string&gt;): RdbPredicates


Sets the **RdbPredicates** to group rows that have the same value into summary rows.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| fields | Array&lt;string&gt; | Yes| Names of columns to group.|

**Return value**
| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that groups rows with the same value.|

**Example**
```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.groupBy(["AGE", "NAME"])
```


### indexedBy

indexedBy(field: string): RdbPredicates

Sets the **RdbPredicates** object to specify the index column.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Name of the index column.|

**Return value**

| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that specifies the index column.|

**Example**
```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.indexedBy("SALARY_INDEX")
```


### in

in(field: string, value: Array&lt;ValueType&gt;): RdbPredicates


Sets the **RdbPredicates** to match the field with data type **Array&#60;ValueType&#62;** and value within the specified range.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the database table.|
| value | Array&lt;[ValueType](#valuetype)&gt; | Yes| Array of **ValueType**s to match.|


**Return value**
| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that matches the specified field.|

**Example**
```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.in("AGE", [18, 20])
```


### notIn

notIn(field: string, value: Array&lt;ValueType&gt;): RdbPredicates


Sets the **RdbPredicates** to match the field with data type **Array&#60;ValueType&#62;** and value out of the specified range.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the database table.|
| value | Array&lt;[ValueType](#valuetype)&gt; | Yes| Array of **ValueType**s to match.|


**Return value**
| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that matches the specified field.|

**Example**
```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.notIn("NAME", ["Lisa", "Rose"])
```


## RdbStore

Provides methods to manage an RDB store.


### insert

insert(name: string, values: ValuesBucket, callback: AsyncCallback&lt;number&gt;):void

Inserts a row of data into a table. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string | Yes| Name of the target table.|
| values | [ValuesBucket](#valuesbucket) | Yes| Row of data to insert.|
| callback | AsyncCallback&lt;number&gt; | Yes| Callback invoked to return the result. If the operation is successful, the row ID will be returned. Otherwise, **-1** will be returned.|

**Example**
```js
const valueBucket = {
    "NAME": "Lisa",
    "AGE": 18,
    "SALARY": 100.5,
    "CODES": new Uint8Array([1, 2, 3, 4, 5]),
}
rdbStore.insert("EMPLOYEE", valueBucket, function (err, ret) {
    if (err) {
        console.info("Failed to insert data, err: " + err)
        return
    }
    console.log("Insert first done: " + ret)
})
```


### insert

insert(name: string, values: ValuesBucket):Promise&lt;number&gt;

Inserts a row of data into a table. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string | Yes| Name of the target table.|
| values | [ValuesBucket](#valuesbucket) | Yes| Row of data to insert.|

**Return value**
| Type| Description|
| -------- | -------- |
| Promise&lt;number&gt; | Promise used to return the result. If the operation is successful, the row ID will be returned. Otherwise, **-1** will be returned.|

**Example**
```js
const valueBucket = {
    "NAME": "Lisa",
    "AGE": 18,
    "SALARY": 100.5,
    "CODES": new Uint8Array([1, 2, 3, 4, 5]),
}
let promise = rdbStore.insert("EMPLOYEE", valueBucket)
promise.then(async (ret) => {
    console.log("Insert first done: " + ret)
}).catch((err) => {
    console.log("Failed to insert data, err: " + err)
})
```


### update

update(values: ValuesBucket, rdbPredicates: RdbPredicates, callback: AsyncCallback&lt;number&gt;):void

Updates data in the database based on the specified RdbPredicates object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| values | [ValuesBucket](#valuesbucket) | Yes| Data to update. The value specifies the row of data to be updated in the database. The key-value pair is associated with the column name in the target table.|
| rdbPredicates | [RdbPredicates](#rdbpredicates) | Yes| Row of data to insert.|
| callback | AsyncCallback&lt;number&gt; | Yes| Callback used to return the number of rows updated.|

**Example**
```js
const valueBucket = {
    "NAME": "Rose",
    "AGE": 22,
    "SALARY": 200.5,
    "CODES": new Uint8Array([1, 2, 3, 4, 5]),
}
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.equalTo("NAME", "Lisa")
rdbStore.update(valueBucket, predicates, function (err, ret) {
    if (err) {
        console.info("Failed to update data, err: " + err)
        return
    }
    console.log("Updated row count: " + ret)
})
```


### update

update(values: ValuesBucket, rdbPredicates: RdbPredicates):Promise&lt;number&gt;

Updates data in the database based on the specified RdbPredicates object. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| values | [ValuesBucket](#valuesbucket) | Yes| Data to update. The value specifies the row of data to be updated in the database. The key-value pair is associated with the column name in the target table.|
| rdbPredicates | [RdbPredicates](#rdbpredicates) | Yes| Row of data to insert.|

**Return value**
| Type| Description|
| -------- | -------- |
| Promise&lt;number&gt; | Promise used to return the number of rows updated.|

**Example**
```js
const valueBucket = {
    "NAME": "Rose",
    "AGE": 22,
    "SALARY": 200.5,
    "CODES": new Uint8Array([1, 2, 3, 4, 5]),
}
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.equalTo("NAME", "Lisa")
let promise = rdbStore.update(valueBucket, predicates)
promise.then(async (ret) => {
    console.log("Updated row count: " + ret)
}).catch((err) => {
    console.info("Failed to update data, err: " + err)
})
```


### delete

delete(rdbPredicates: RdbPredicates, callback: AsyncCallback&lt;number&gt;):void


Deletes data from the database based on the specified **RdbPredicates** object. This API uses a callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| rdbPredicates | [RdbPredicates](#rdbpredicates) | Yes| Conditions specified by the **RdbPredicates** object for deleting data.|
| callback | AsyncCallback&lt;number&gt; | Yes| Callback invoked to return the number of rows updated.|

**Example**
```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.equalTo("NAME", "Lisa")
rdbStore.delete(predicates, function (err, rows) {
    if (err) {
        console.info("Failed to delete data, err: " + err)
        return
    }
    console.log("Delete rows: " + rows)
})
```


### delete

delete(rdbPredicates: RdbPredicates):Promise&lt;number&gt;

Deletes data from the database based on the specified **RdbPredicates** object. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| rdbPredicates | [RdbPredicates](#rdbpredicates) | Yes| Conditions specified by the **RdbPredicates** object for deleting data.|

**Return value**
| Type| Description|
| -------- | -------- |
| Promise&lt;number&gt; | Promise used to return the number of rows updated.|

**Example**
```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.equalTo("NAME", "Lisa")
let promise = rdbStore.delete(predicates)
promise.then((rows) => {
    console.log("Delete rows: " + rows)
}).catch((err) => {
    console.info("Failed to delete data, err: " + err)
})
```


### query

query(rdbPredicates: RdbPredicates, columns: Array&lt;string&gt;, callback: AsyncCallback&lt;ResultSet&gt;):void

Queries data in the database based on specified conditions. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| rdbPredicates | [RdbPredicates](#rdbpredicates) | Yes| Query conditions specified by the **RdbPredicates** object.|
| columns | Array&lt;string&gt; | Yes| Columns to query. If this parameter is not specified, the query applies to all columns.|
| callback | AsyncCallback&lt;[ResultSet](js-apis-data-resultset.md)&gt; | Yes| Callback invoked to return the result. If the operation is successful, a **ResultSet** object will be returned.|

**Example**
```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.equalTo("NAME", "Rose")
rdbStore.query(predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"], function (err, resultSet) {
    if (err) {
        console.info("Failed to query data, err: " + err)
        return
    }
    console.log("resultSet column names:" + resultSet.columnNames)
    console.log("resultSet column count:" + resultSet.columnCount)
})
```


### query

query(rdbPredicates: RdbPredicates, columns?: Array&lt;string&gt;):Promise&lt;ResultSet&gt;

Queries data in the database based on specified conditions. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| rdbPredicates | [RdbPredicates](#rdbpredicates) | Yes| Query conditions specified by the **RdbPredicates** object.|
| columns | Array&lt;string&gt; | No| Columns to query. If this parameter is not specified, the query applies to all columns.|

**Return value**
| Type| Description|
| -------- | -------- |
| Promise&lt;[ResultSet](../apis/js-apis-data-resultset.md)&gt; | Promise used to return the result. If the operation is successful, a **ResultSet** object will be returned.|

**Example**
  ```js
  let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
  predicates.equalTo("NAME", "Rose")
  let promise = rdbStore.query(predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"])
  promise.then((resultSet) => {
      console.log("resultSet column names:" + resultSet.columnNames)
      console.log("resultSet column count:" + resultSet.columnCount)
  }).catch((err) => {
      console.info("Failed to query data, err: " + err)
  })
  ```


### querySql<sup>8+</sup>

querySql(sql: string, bindArgs: Array&lt;ValueType&gt;, callback: AsyncCallback&lt;ResultSet&gt;):void

Queries data in the RDB store using the specified SQL statement. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| sql | string | Yes| SQL statement to run.|
| bindArgs | Array&lt;[ValueType](#valuetype)&gt; | Yes| Values of the parameters in the SQL statement.|
| callback | AsyncCallback&lt;[ResultSet](js-apis-data-resultset.md)&gt; | Yes| Callback invoked to return the result. If the operation is successful, a **ResultSet** object will be returned.|

**Example**
```js
rdbStore.querySql("SELECT * FROM EMPLOYEE CROSS JOIN BOOK WHERE BOOK.NAME = ?", ['sanguo'], function (err, resultSet) {
    if (err) {
        console.info("Failed to query data, err: " + err)
        return
    }
    console.log("resultSet column names:" + resultSet.columnNames)
    console.log("resultSet column count:" + resultSet.columnCount)
})
```


### querySql<sup>8+</sup>

querySql(sql: string, bindArgs?: Array&lt;ValueType&gt;):Promise&lt;ResultSet&gt;

Queries data in the RDB store using the specified SQL statement. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| sql | string | Yes| SQL statement to run.|
| bindArgs | Array&lt;[ValueType](#valuetype)&gt; | No| Values of the parameters in the SQL statement.|

**Return value**
| Type| Description|
| -------- | -------- |
| Promise&lt;[ResultSet](../apis/js-apis-data-resultset.md)&gt; | Promise used to return the result. If the operation is successful, a **ResultSet** object will be returned.|

**Example**
```js
let promise = rdbStore.querySql("SELECT * FROM EMPLOYEE CROSS JOIN BOOK WHERE BOOK.NAME = ?", ['sanguo'])
promise.then((resultSet) => {
    console.log("resultSet column names:" + resultSet.columnNames)
    console.log("resultSet column count:" + resultSet.columnCount)
}).catch((err) => {
    console.info("Failed to query data, err: " + err)
})
```


### executeSql

executeSql(sql: string, bindArgs: Array&lt;ValueType&gt;, callback: AsyncCallback&lt;void&gt;):void

Runs the SQL statement that contains the specified parameters but does not return a value. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| sql | string | Yes| SQL statement to run.|
| bindArgs | Array&lt;[ValueType](#valuetype)&gt; | Yes| Values of the parameters in the SQL statement.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback invoked to return the result.|

**Example**
```js
const SQL_CREATE_TABLE = "CREATE TABLE IF NOT EXISTS EMPLOYEE (ID INTEGER PRIMARY KEY AUTOINCREMENT, NAME TEXT NOT NULL, AGE INTEGER, SALARY REAL, CODES BLOB)"
rdbStore.executeSql(SQL_CREATE_TABLE, null, function(err) {
    if (err) {
        console.info("Failed to execute SQL, err: " + err)
        return
    }
    console.info('create table done.')
})
```


### executeSql

executeSql(sql: string, bindArgs?: Array&lt;ValueType&gt;):Promise&lt;void&gt;

Runs the SQL statement that contains the specified parameters but does not return a value. This API uses a promise to return the execution result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| sql | string | Yes| SQL statement to run.|
| bindArgs | Array&lt;[ValueType](#valuetype)&gt; | No| Values of the parameters in the SQL statement.|

**Return value**
| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**
```js
const SQL_CREATE_TABLE = "CREATE TABLE IF NOT EXISTS EMPLOYEE (ID INTEGER PRIMARY KEY AUTOINCREMENT, NAME TEXT NOT NULL, AGE INTEGER, SALARY REAL, CODES BLOB)"
let promise = rdbStore.executeSql(SQL_CREATE_TABLE)
promise.then(() => {
    console.info('create table done.')
}).catch((err) => {
    console.info("Failed to execute SQL, err: " + err)
})
```

### beginTransaction<sup>8+</sup>

beginTransaction():void

Starts the transaction before executing an SQL statement.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Example**
```js
rdbStore.beginTransaction()
const valueBucket = {
    "name": "lisi",
    "age": 18,
    "salary": 100.5,
    "blobType": new Uint8Array([1, 2, 3]),
}
rdbStore.insert("test", valueBucket, function (err, ret) {
    if (err) {
        console.info("Failed to insert data, err: " + err)
        return
    }
    console.log("Inserted data successfully: " + ret)
})
rdbStore.commit()
```


### commit<sup>8+</sup>

commit():void

Commits the executed SQL statements.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Example**
```js
rdbStore.beginTransaction()
const valueBucket = {
    "name": "lisi",
    "age": 18,
    "salary": 100.5,
    "blobType": new Uint8Array([1, 2, 3]),
}

rdbStore.insert("test", valueBucket, function (err, ret) {
    if (err) {
        console.info("Failed to insert data, err: " + err)
        return
    }
    console.log("Inserted data successfully: " + ret)
})
rdbStore.commit()
```


### rollBack<sup>8+</sup>

rollBack():void;

Rolls back the SQL statements that have been executed.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Example**
```js
try {
    rdbStore.beginTransaction()
    const valueBucket = {
        "id": 1,
        "name": "lisi",
        "age": 18,
        "salary": 100.5,
        "blobType": new Uint8Array([1, 2, 3]),
    }
    rdbStore.insert("test", valueBucket, function (err, ret) {
        if (err) {
            console.info("Failed to insert data, err: " + err)
            return
        }
        console.log("Inserted data successfully: " + ret)
    })
    rdbStore.commit()
} catch (e) {
    rdbStore.rollBack()
}
```


### setDistributedTables<sup>8+</sup>

setDistributedTables(tables: Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void

Sets a list of distributed tables. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| tables | Array&lt;string&gt; | Yes| Names of the distributed tables to set.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback invoked to return the result.|

**Example**
```js
rdbStore.setDistributedTables(["EMPLOYEE"], function (err) {
    if (err) {
        console.info('Failed to set distributed tables, err: ' + err)
        return
    }
    console.info('setDistributedTables successfully.')
})
```


### setDistributedTables<sup>8+</sup>

 setDistributedTables(tables: Array&lt;string&gt;): Promise&lt;void&gt;

Sets a list of distributed tables. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| tables | Array&lt;string&gt; | Yes| Names of the distributed tables to set.|

**Return value**
| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**
```js
let promise = rdbStore.setDistributedTables(["EMPLOYEE"])
promise.then(() => {
    console.info("setDistributedTables successfully.")
}).catch((err) => {
    console.info('Failed to set distributed tables, err: ' + err)
})
```

### obtainDistributedTableName<sup>8+</sup>

obtainDistributedTableName(device: string, table: string, callback: AsyncCallback&lt;string&gt;): void

Obtains the distributed table name for a remote device based on the local table name. The distributed table name is required when the database of a remote device is queried. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| device | string | Yes| Remote device.|
| table | string | Yes| Local table name.|
| callback | AsyncCallback&lt;string&gt; | Yes| Callback invoked to return the result. If the operation succeeds, the distributed table name of the remote device is returned.|

**Example**
```js
rdbStore.obtainDistributedTableName("12345678abcde", "EMPLOYEE", function (err, tableName) {
    if (err) {
        console.info('Failed to obtain DistributedTableName, err: ' + err)
        return
    }
    console.info('obtainDistributedTableName successfully, tableName=.' + tableName)
})
```


### obtainDistributedTableName<sup>8+</sup>

 obtainDistributedTableName(device: string, table: string): Promise&lt;string&gt;

Obtains the distributed table name for a remote device based on the local table name. The distributed table name is required when the database of a remote device is queried. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| device | string | Yes| Remote device.|
| table | string | Yes| Local table name.|

**Return value**
| Type| Description|
| -------- | -------- |
| Promise&lt;string&gt; | Promise used to return the result. If the operation succeeds, the distributed table name of the remote device is returned.|

**Example**
```js
let promise = rdbStore.obtainDistributedTableName("12345678abcde", "EMPLOYEE")
promise.then((tableName) => {
    console.info('obtainDistributedTableName successfully, tableName=' + tableName)
}).catch((err) => {
    console.info('Failed to obtain DistributedTableName, err: ' + err)
})
```

### sync<sup>8+</sup>

sync(mode: SyncMode, predicates: RdbPredicates, callback: AsyncCallback&lt;Array&lt;[string, number]&gt;&gt;): void

Synchronizes data between devices. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| mode | [SyncMode](#syncmode8) | Yes| Data synchronization mode. The value can be **push** or **pull**.|
| predicates | [RdbPredicates](#rdbpredicates) | Yes| **RdbPredicates** object that specifies the data and devices to synchronize.|
| callback | AsyncCallback&lt;Array&lt;[string, number]&gt;&gt; | Yes| Callback invoked to send the synchronization result to the caller. <br>**string** indicates the device ID. <br>**number** indicates the synchronization status of each device. The value **0** indicates a successful synchronization. Other values indicate a synchronization failure. |

**Example**
```js
let predicates = new data_rdb.RdbPredicates('EMPLOYEE')
predicates.inDevices(['12345678abcde'])
rdbStore.sync(data_rdb.SyncMode.SYNC_MODE_PUSH, predicates, function (err, result) {
    if (err) {
        console.log('sync failed, err: ' + err)
        return
    }
    console.log('sync done.')
    for (let i = 0; i < result.length; i++) {
        console.log('device=' + result[i][0] + ' status=' + result[i][1])
    }
})
```


### sync<sup>8+</sup>

 sync(mode: SyncMode, predicates: RdbPredicates): Promise&lt;Array&lt;[string, number]&gt;&gt;

Synchronizes data between devices. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| mode | [SyncMode](#syncmode8) | Yes| Data synchronization mode. The value can be **push** or **pull**.|
| predicates | [RdbPredicates](#rdbpredicates) | Yes| **RdbPredicates** object that specifies the data and devices to synchronize.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;Array&lt;[string, number]&gt;&gt; | Promise used to return the synchronization result to the caller. <br>**string** indicates the device ID. <br>**number** indicates the synchronization status of each device. The value **0** indicates a successful synchronization. Other values indicate a synchronization failure. |

**Example**
```js
let predicates = new data_rdb.RdbPredicates('EMPLOYEE')
predicates.inDevices(['12345678abcde'])
let promise = rdbStore.sync(data_rdb.SyncMode.SYNC_MODE_PUSH, predicates)
promise.then((result) =>{
    console.log('sync done.')
    for (let i = 0; i < result.length; i++) {
        console.log('device=' + result[i][0] + ' status=' + result[i][1])
    }
}).catch((err) => {
    console.log('sync failed')
})
```

### on('dataChange')<sup>8+</sup>

on(event: 'dataChange', type: SubscribeType, observer: Callback&lt;Array&lt;string&gt;&gt;): void

Registers an observer for this RDB store. When the data in the RDB store changes, a callback is invoked to return the data changes.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| event | string | Yes| The value is'dataChange', which indicates a data change event.|
| type | [SubscribeType](#subscribetype8) | Yes| Type defined in **SubscribeType**.|
| observer | Callback&lt;Array&lt;string&gt;&gt; | Yes| Observer that listens for the data changes in the RDB store.|

**Example**
```js
function storeObserver(devices) {
    for (let i = 0; i < devices.length; i++) {
        console.log('device=' + devices[i] + ' data changed')
    }
}
try {
    rdbStore.on('dataChange', data_rdb.SubscribeType.SUBSCRIBE_TYPE_REMOTE, storeObserver)
} catch (err) {
    console.log('Failed to register observer')
}
```

### off('dataChange')<sup>8+</sup>

off(event:'dataChange', type: SubscribeType, observer: Callback&lt;Array&lt;string&gt;&gt;): void

Deletes the specified observer of the RDB store. This API uses a callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| event | string | Yes| The value is'dataChange', which indicates a data change event.|
| type | [SubscribeType](#subscribetype8)    | Yes| Type defined in **SubscribeType**.|
| observer | Callback&lt;Array&lt;string&gt;&gt; | Yes| Data change observer registered.|

**Example**
```js
function storeObserver(devices) {
    for (let i = 0; i < devices.length; i++) {
        console.log('device=' + devices[i] + ' data changed')
    }
}
try {
    rdbStore.off('dataChange', data_rdb.SubscribeType.SUBSCRIBE_TYPE_REMOTE, storeObserver)
} catch (err) {
    console.log('Failed to unregister observer')
}
```

## StoreConfig

Manages the configuration of an RDB store.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string | Yes| Database file name.|


## ValueType

Defines the data types allowed.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name| Description|
| -------- | -------- |
| number | Number.|
| string | String.|
| boolean | Boolean.|


## ValuesBucket

Defines a bucket to store key-value pairs.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| [key:&nbsp;string] | [ValueType](#valuetype)\|&nbsp;Uint8Array&nbsp;\|&nbsp;null | Yes| Defines a bucket to store key-value pairs.|


## SyncMode<sup>8+</sup>

Defines the database synchronization mode.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name      | Default Value| Description|
| --------  | ----- |----- |
| SYNC_MODE_PUSH | 0 | Data is pushed from a local device to a remote device.|
| SYNC_MODE_PULL | 1 | Data is pulled from a remote device to a local device.|

## SubscribeType<sup>8+</sup>

Defines the subscription type.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name     | Default Value| Description|
| -------- | ----- |---- |
| SUBSCRIBE_TYPE_REMOTE | 0 | Subscribe to remote data changes.|
