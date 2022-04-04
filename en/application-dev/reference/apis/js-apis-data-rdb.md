# Relational Database

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br/>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.



## Modules to Import

```
import data_rdb from '@ohos.data.rdb'
```


## data_rdb.getRdbStore

getRdbStore(context: Context, config: StoreConfig, version: number, callback: AsyncCallback&lt;RdbStore&gt;): void

Obtains a relational database (RDB) store. This method uses an asynchronous callback to return the result. You can set parameters for the RDB store based on service requirements and call APIs to perform data operations.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| context<sup>8+</sup> | Context | Yes| Context of the app or functionality.|
| config | [StoreConfig](#storeconfig) | Yes| Configuration of the RDB store.|
| version | number | Yes| RDB store version.|
| callback | AsyncCallback&lt;[RdbStore](#rdbstore)&gt; | Yes| Callback invoked to return the RDB store obtained.|

**Example**

```
import data_rdb from '@ohos.data.rdb'
const STORE_CONFIG = { name: "RdbTest.db"}
const SQL_CREATE_TABLE = "CREATE TABLE IF NOT EXISTS EMPLOYEE (ID INTEGER PRIMARY KEY AUTOINCREMENT, NAME TEXT NOT NULL, AGE INTEGER, SALARY REAL, CODES BLOB)"
data_rdb.getRdbStore(STORE_CONFIG, 1, function (err, rdbStore) {
    rdbStore.executeSql(SQL_CREATE_TABLE)
    console.info('create table done.')
})
```

The sample code of API<sup>9</sup> is as follows:

```
import Ability from '@ohos.application.Ability'
import data_rdb from '@ohos.data.rdb'
export default class MainAbility extends Ability {
    const STORE_CONFIG = { name: "RdbTest.db"}
    const SQL_CREATE_TABLE = "CREATE TABLE IF NOT EXISTS EMPLOYEE (ID INTEGER PRIMARY KEY AUTOINCREMENT, NAME TEXT NOT NULL, AGE INTEGER, SALARY REAL, CODES BLOB)"
    data_rdb.getRdbStore(this.context, STORE_CONFIG, 1, function (err, rdbStore) {
        rdbStore.executeSql(SQL_CREATE_TABLE)
        console.info('create table done.')
    })
}
```

## data_rdb.getRdbStore

getRdbStore(context: Context, config: StoreConfig, version: number): Promise&lt;RdbStore&gt;

Obtains an RDB store. This method uses a promise to return the result. You can set parameters for the RDB store based on service requirements and call APIs to perform data operations.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| context<sup>8+</sup> | Context | Yes| Context of the app or functionality.|
| config | [StoreConfig](#storeconfig) | Yes| Configuration of the RDB store.|
| version | number | Yes| RDB store version.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[RdbStore](#rdbstore)&gt; | Promise used to return the RDB store obtained.|

**Example**

```
import data_rdb from '@ohos.data.rdb'
const STORE_CONFIG = { name: "RdbTest.db" }
const SQL_CREATE_TABLE = "CREATE TABLE IF NOT EXISTS EMPLOYEE (ID INTEGER PRIMARY KEY AUTOINCREMENT, NAME TEXT NOT NULL, AGE INTEGER, SALARY REAL, CODES BLOB)"
let promisegetRdb = data_rdb.getRdbStore(STORE_CONFIG, 1);
promisegetRdb.then(async (rdbStore) => {
    let promiseExecSql = rdbStore.executeSql(SQL_CREATE_TABLE, null)
    promiseExecSql.then(() => {
        console.info('executeSql creat done.')
    }).catch((err) => {
        console.log("executeSql creat err.")
    })
}).catch((err) => {
    console.log("getRdbStore err.")
})
```

The sample code of API<sup>9</sup> is as follows:

```
import Ability from '@ohos.application.Ability'
import data_rdb from '@ohos.data.rdb'
export default class MainAbility extends Ability {
    const STORE_CONFIG = { name: "RdbTest.db" }
    const SQL_CREATE_TABLE = "CREATE TABLE IF NOT EXISTS EMPLOYEE (ID INTEGER PRIMARY KEY AUTOINCREMENT, NAME TEXT NOT NULL, AGE INTEGER, SALARY REAL, CODES BLOB)"
    let promisegetRdb = data_rdb.getRdbStore(this.context, STORE_CONFIG, 1);
    promisegetRdb.then(async (rdbStore) => {
        let promiseExecSql = rdbStore.executeSql(SQL_CREATE_TABLE, null)
        promiseExecSql.then(() => {
            console.info('executeSql creat done.')
        }).catch((err) => {
            console.log("executeSql creat err.")
        })
    }).catch((err) => {
        console.log("getRdbStore err.")
    })
}
```

## data_rdb.deleteRdbStore

deleteRdbStore(context: Context, name: string, callback: AsyncCallback&lt;void&gt;): void

Deletes an RDB store. This method uses a callback to return the result. 

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| context<sup>8+</sup> | Context | Yes| Context of the app or functionality.|
| name | string | Yes| Name of the RDB store to delete.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback invoked to return the result.|

**Example**
  ```
  import data_rdb from '@ohos.data.rdb'
  data_rdb.deleteRdbStore("RdbTest.db", function (err, rdbStore) {
      console.info('delete store done.')
  })
  ```

The sample code of API<sup>9</sup> is as follows:

```
import Ability from '@ohos.application.Ability'
import data_rdb from '@ohos.data.rdb'
export default class MainAbility extends Ability {
    data_rdb.deleteRdbStore(this.context, "RdbTest.db", function (err, rdbStore) {
        console.info('delete store done.')
    })
}
```

## data_rdb.deleteRdbStore

deleteRdbStore(context: Context, name: string): Promise&lt;void&gt;

Deletes an RDB store. This method uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| context<sup>8+</sup> | Context | Yes| Context of the app or functionality.|
| name | string | Yes| Name of the RDB store to delete.|

**Return value**
| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**
  ```
  import data_rdb from '@ohos.data.rdb'
  let promisedeleteRdb = data_rdb.deleteRdbStore("RdbTest.db")
  promisedeleteRdb.then(()=>{
      console.info('delete store done.')
  }).catch((err) => {
      console.log("deleteRdbStore err.")
  })
  ```

The sample code of API<sup>9</sup> is as follows:

```
import Ability from '@ohos.application.Ability'
import data_rdb from '@ohos.data.rdb'
export default class MainAbility extends Ability {
    let promisedeleteRdb = data_rdb.deleteRdbStore(this.context, "RdbTest.db")
    promisedeleteRdb.then(()=>{
        console.info('delete store done.')
    }).catch((err) => {
        console.log("deleteRdbStore err.")
    })
}
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
  ```
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
  ```
  let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
  predicate.inDevices(['12345678abcde'])
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
  ```
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
  ```
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
  ```
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
  ```
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
  ```
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
  ```
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
  ```
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
  ```
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
  ```
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
  ```
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
  ```
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
  ```
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
  ```
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
| value | string | Yes| Value to match the **RdbPredicates**.<br><br>Wildcards are supported. ***** indicates zero, one, or multiple digits or characters. **?** indicates a single digit or character.|

**Return value**
| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that matches the specified field.|

**Example**
  ```
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
  ```
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
  ```
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
  ```
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
  ```
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
  ```
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
  ```
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
  ```
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
  ```
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
  ```
  let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
  predicates.equalTo("NAME", "Rose").distinct("NAME")
  let promisequery = rdbStore.query(predicates, ["NAME"])
  promisequery.then((resultSet) => {
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
  ```
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
  ```
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
  ```
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
  ```
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
  ```
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
  ```
  let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
  predicates.notIn("NAME", ["Lisa", "Rose"])
  ```


## RdbStore

Provides methods to manage an RDB store.


### insert

insert(name: string, values: ValuesBucket, callback: AsyncCallback&lt;number&gt;):void

Inserts a row of data into a table. This method uses a callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string | Yes| Name of the target table.|
| values | [ValuesBucket](#valuesbucket) | Yes| Row of data to insert.|
| callback | AsyncCallback&lt;number&gt; | Yes| Callback invoked to return the result. If the operation is successful, the row ID will be returned. Otherwise, **-1** will be returned.|

**Example**
  ```
  const valueBucket = {
      "NAME": "Lisa",
      "AGE": 18,
      "SALARY": 100.5,
      "CODES": new Uint8Array([1, 2, 3, 4, 5]),
  }
  rdbStore.insert("EMPLOYEE", valueBucket, function (err, ret) {
      console.log("insert first done: " + ret)
  })
  ```


### insert

insert(name: string, values: ValuesBucket):Promise&lt;number&gt;

Inserts a row of data into a table. This method uses a promise to return the result.

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
  ```
  const valueBucket = {
      "NAME": "Lisa",
      "AGE": 18,
      "SALARY": 100.5,
      "CODES": new Uint8Array([1, 2, 3, 4, 5]),
  }
  let promiseinsert = rdbStore.insert("EMPLOYEE", valueBucket)
  promiseinsert.then(async (ret) => {
      console.log("insert first done: " + ret)
  }).catch((err) => {
      console.log("insert err.")
  })
  ```


### update

update(values: ValuesBucket, rdbPredicates: RdbPredicates, callback: AsyncCallback&lt;number&gt;):void

Updates data in the database based on the specified RdbPredicates object. This method uses a callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| values | [ValuesBucket](#valuesbucket) | Yes| Data to update. The value specifies the row of data to be updated in the database. The key-value pair is associated with the column name in the target table.|
| rdbPredicates | [RdbPredicates](#rdbpredicates) | Yes| Row of data to insert.|
| callback | AsyncCallback&lt;number&gt; | Yes| Callback used to return the number of rows updated.|

**Example**
  ```
  const valueBucket = {
      "NAME": "Rose",
      "AGE": 22,
      "SALARY": 200.5,
      "CODES": new Uint8Array([1, 2, 3, 4, 5]),
  }
  let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
  predicates.equalTo("NAME", "Lisa")
  rdbStore.update(valueBucket, predicates, function (err, ret) {
      console.log("updated row count: " + changedRows)})
  ```


### update

update(values: ValuesBucket, rdbPredicates: RdbPredicates):Promise&lt;number&gt;

Updates data in the database based on the specified RdbPredicates object. This method uses a promise to return the result.

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
  ```
  const valueBucket = {
      "NAME": "Rose",
      "AGE": 22,
      "SALARY": 200.5,
      "CODES": new Uint8Array([1, 2, 3, 4, 5]),
  }
  let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
  predicates.equalTo("NAME", "Lisa")
  let promiseupdate = rdbStore.update(valueBucket, predicates)
  promiseupdate.then(async (ret) => {
       console.log("updated row count: " + changedRows)
  }).catch((err) => {
      console.log("update err.")
  })
  ```


### delete

delete(rdbPredicates: RdbPredicates, callback: AsyncCallback&lt;number&gt;):void


Deletes data from the database based on the specified RdbPredicates object. This method uses a callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| rdbPredicates | [RdbPredicates](#rdbpredicates) | Yes| Conditions specified for deleting data.|
| callback | AsyncCallback&lt;number&gt; | Yes| Callback invoked to return the number of rows updated.|

**Example**
  ```
  let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
  predicates.equalTo("NAME", "Lisa")
  rdbStore.delete(predicates, function (err, rows) {
      console.log("delete rows: " + rows)
  })
  ```


### delete

delete(rdbPredicates: RdbPredicates):Promise&lt;number&gt;

Deletes data from the database based on the specified RdbPredicates object. This method uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| rdbPredicates | [RdbPredicates](#rdbpredicates) | Yes| Conditions specified for deleting data.|

**Return value**
| Type| Description|
| -------- | -------- |
| Promise&lt;number&gt; | Promise used to return the number of rows updated.|

**Example**
  ```
  let predicatesdelete = new data_rdb.RdbPredicates("EMPLOYEE")
  predicatesdelete.equalTo("NAME", "Lisa")
  let promisedelete = rdbStore.delete(predicates)
  promisedelete.then((rows) => {
      console.log("delete rows: " + rows)
  }).catch((err) => {
      console.log("delete err.")
  })
  ```


### query

query(rdbPredicates: RdbPredicates, columns: Array&lt;string&gt;, callback: AsyncCallback&lt;ResultSet&gt;):void

Queries data in the database based on specified conditions. This method uses a callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| rdbPredicates | [RdbPredicates](#rdbpredicates) | Yes| Query conditions specified by the **RdbPredicates** object.|
| columns | Array&lt;string&gt; | Yes| Columns to query. If this parameter is not specified, the query applies to all columns.|
| callback | AsyncCallback&lt;[ResultSet](js-apis-data-resultset.md)&gt; | Yes| Callback invoked to return the result. If the operation is successful, a **ResultSet** object will be returned.|

**Example**
  ```
  let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
  predicates.equalTo("NAME", "Rose")
  rdbStore.query(predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"], function (err, resultSet) {
      console.log("resultSet column names:" + resultSet.columnNames)
      console.log("resultSet column count:" + resultSet.columnCount)
  })
  ```


### query

query(rdbPredicates: RdbPredicates, columns?: Array&lt;string&gt;):Promise&lt;ResultSet&gt;

Queries data in the database based on specified conditions. This method uses a promise to return the result.

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
  ```
  let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
  predicates.equalTo("NAME", "Rose")
  let promisequery = rdbStore.query(predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"])
  promisequery.then((resultSet) => {
      console.log("resultSet column names:" + resultSet.columnNames)
      console.log("resultSet column count:" + resultSet.columnCount)
  }).catch((err) => {
      console.log("query err.")
  })
  ```


### querySql<sup>8+</sup>

querySql(sql: string, bindArgs: Array&lt;ValueType&gt;, callback: AsyncCallback&lt;ResultSet&gt;):void

Queries data in the RDB store using the specified SQL statement. This method uses a callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| sql | string | Yes| SQL statement to run.|
| bindArgs | Array&lt;[ValueType](#valuetype)&gt; | Yes| Values of the parameters in the SQL statement.|
| callback | AsyncCallback&lt;[ResultSet](js-apis-data-resultset.md)&gt; | Yes| Callback invoked to return the result. If the operation is successful, a **ResultSet** object will be returned.|

**Example**
  ```
  rdbStore.querySql("SELECT * FROM EMPLOYEE CROSS JOIN BOOK WHERE BOOK.NAME = ?", ['sanguo'], function (err, resultSet) {
      console.log("resultSet column names:" + resultSet.columnNames)
      console.log("resultSet column count:" + resultSet.columnCount)
  })
  ```


### querySql<sup>8+</sup>

querySql(sql: string, bindArgs?: Array&lt;ValueType&gt;):Promise&lt;ResultSet&gt;

Queries data in the RDB store using the specified SQL statement. This method uses a promise to return the result.

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
  ```
  let promisequerySql = rdbStore.querySql("SELECT * FROM EMPLOYEE CROSS JOIN BOOK WHERE BOOK.NAME = ?", ['sanguo'])
  promisequerySql.then((resultSet) => {
      console.log("resultSet column names:" + resultSet.columnNames)
      console.log("resultSet column count:" + resultSet.columnCount)
  }).catch((err) => {
      console.log("querySql err.")
  })
  ```


### executeSql

executeSql(sql: string, bindArgs: Array&lt;ValueType&gt;, callback: AsyncCallback&lt;void&gt;):void

Runs the SQL statement that contains the specified parameters but does not return a value. This method uses a callback to return the execution result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| sql | string | Yes| SQL statement to run.|
| bindArgs | Array&lt;[ValueType](#valuetype)&gt; | Yes| Values of the parameters in the SQL statement.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback invoked to return the result.|

**Example**
  ```
  rdbStore.executeSql("DELETE FROM EMPLOYEE", null, function () {
      console.info('delete done.')
  })
  ```


### executeSql

executeSql(sql: string, bindArgs?: Array&lt;ValueType&gt;):Promise&lt;void&gt;

Runs the SQL statement that contains the specified parameters but does not return a value. This method uses a promise to return the execution result.

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
  ```
  let promiseexecuteSql = rdbStore.executeSql("DELETE FROM EMPLOYEE")
  promiseexecuteSql.then(() => {
      console.info('delete done.')
  }).catch((err) => {
      console.log("executeSql err.")
  })
  ```

### beginTransaction<sup>8+</sup>

beginTransaction():void

Starts the transaction before executing an SQL statement.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Example**
```
  rdbStore.beginTransaction()
  const valueBucket = {
      "name": "lisi",
      "age": 18,
      "salary": 100.5,
      "blobType": new Uint8Array([1, 2, 3]),
  }
  rdbStore.insert("test", valueBucket, function (err, ret) {
      console.log("insert done: " + ret)
  })
  rdbStore.commit()
```


### commit<sup>8+</sup>

commit():void

Commits the executed SQL statements.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Example**
```
  rdbStore.beginTransaction()
  const valueBucket = {
      "name": "lisi",
      "age": 18,
      "salary": 100.5,
      "blobType": new Uint8Array([1, 2, 3]),
  }

  rdbStore.insert("test", valueBucket, function (err, ret) {
      console.log("insert done: " + ret)
  })
  rdbStore.commit()
```


### rollBack<sup>8+</sup>

rollBack():void;

Rolls back the SQL statements that have been executed.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Example**
```
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
          console.log("insert done: " + ret)
      })
      rdbStore.commit()
  } catch (e) {
      rdbStore.rollBack()
  }
```


### setDistributedTables<sup>8+</sup>

setDistributedTables(tables: Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void

Sets a list of distributed tables. This method uses a callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| tables | Array&lt;string&gt; | Yes| Names of the distributed tables to set.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback invoked to return the result.|

**Example**
  ```
  rdbStore.setDistributedTables(["EMPLOYEE"], function (err) {
      if (err) {
          console.info('setDistributedTables failed.')
          return
      }
      console.info('setDistributedTables success.')
  })
  ```


### setDistributedTables<sup>8+</sup>

 setDistributedTables(tables: Array&lt;string&gt;): Promise&lt;void&gt;

Sets a list of distributed tables. This method uses a promise to return the result.

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
  ```
  let promiseset = rdbStore.setDistributedTables(["EMPLOYEE"])
  promiseset.then(() => {
      console.info("setDistributedTables success.")
  }).catch((err) => {
      console.info("setDistributedTables failed.")
  })
  ```

### obtainDistributedTableName<sup>8+</sup>

obtainDistributedTableName(device: string, table: string, callback: AsyncCallback&lt;string&gt;): void

Obtains the distributed table name for a remote device based on the local table name. The distributed table name is required when the database of a remote device is queried. This method uses a callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| device | string | Yes| Remote device.|
| table | string | Yes| Local table name.|
| callback | AsyncCallback&lt;string&gt; | Yes| Callback invoked to return the result. If the operation succeeds, the distributed table name of the remote device is returned.|

**Example**
  ```
  rdbStore.obtainDistributedTableName(deviceId, "EMPLOYEE", function (err, tableName) {
      if (err) {
          console.info('obtainDistributedTableName failed.')
          return
      }
      console.info('obtainDistributedTableName success, tableName=.' + tableName)
   })
  ```


### obtainDistributedTableName<sup>8+</sup>

 obtainDistributedTableName(device: string, table: string): Promise&lt;string&gt;

Obtains the distributed table name for a remote device based on the local table name. The distributed table name is required when the database of a remote device is queried. This method uses a promise to return the result.

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
  ```
  let promiseDistr = rdbStore.obtainDistributedTableName(deviceId, "EMPLOYEE")
  promiseDistr.then((tableName) => {
      console.info('obtainDistributedTableName success, tableName=' + tableName)
  }).catch((err) => {
      console.info('obtainDistributedTableName failed.')
  })
  ```

### sync<sup>8+</sup>

sync(mode: SyncMode, predicates: RdbPredicates, callback: AsyncCallback&lt;Array&lt;[string, number]&gt;&gt;): void

Synchronizes data between devices. This method uses a callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| mode | [SyncMode](#syncmode8) | Yes| Data synchronization mode. The value can be **push** or **pull**.|
| predicates | [RdbPredicates](#rdbpredicates) | Yes| **RdbPredicates** object that specifies the data and devices to synchronize.|
| callback | AsyncCallback&lt;Array&lt;[string, number]&gt;&gt; | Yes| Callback invoked to send the synchronization result to the caller. <br>**string** indicates the device ID. <br>**number** indicates the synchronization status of each device. The value **0** indicates a successful synchronization. Other values indicate a synchronization failure. |

**Example**
  ```
  let predicate = new rdb.RdbPredicates('EMPLOYEE')
  predicate.inDevices(['12345678abcde'])
  rdbStore.sync(rdb.SyncMode.SYNC_MODE_PUSH, predicate, function (err, result) {
      if (err) {
          console.log('sync failed')
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

Synchronizes data between devices. This method uses a promise to return the result.

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
  ```
  let predicatesync = new data_rdb.RdbPredicates('EMPLOYEE')
  predicatesync.inDevices(['12345678abcde'])
  let promisesync = rdbStore.sync(data_rdb.SyncMode.SYNC_MODE_PUSH, predicatesync)
  promisesync.then((result) =>{
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
  ```
  function storeObserver(devices) {
      for (let i = 0; i < devices.length; i++) {
          console.log('device=' + device[i] + ' data changed')
      }
  }
  try {
      rdbStore.on('dataChange', data_rdb.SubscribeType.SUBSCRIBE_TYPE_REMOTE, storeObserver)
  } catch (err) {
      console.log('register observer failed')
  }
  ```

### off('dataChange')<sup>8+</sup>

off(event:'dataChange', type: SubscribeType, observer: Callback&lt;Array&lt;string&gt;&gt;): void

Deletes the specified observer of the RDB store. This method uses a callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| event | string | Yes| The value is'dataChange', which indicates a data change event.|
| type | [SubscribeType](#subscribetype8)    | Yes| Type defined in **SubscribeType**.|
| observer | Callback&lt;Array&lt;string&gt;&gt; | Yes| Data change observer registered.|

**Example**

  ```
  function storeObserver(devices) {
      for (let i = 0; i < devices.length; i++) {
          console.log('device=' + device[i] + ' data changed')
      }
  }
  try {
      rdbStore.off('dataChange', data_rdb.SubscribeType.SUBSCRIBE_TYPE_REMOTE, storeObserver)
  } catch (err) {
      console.log('unregister observer failed')
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
