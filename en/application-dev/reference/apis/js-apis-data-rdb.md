# Relational Database

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE:**
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.



## Modules to Import

```
import data_rdb from '@ohos.data.rdb'
```

## System Capabilities
SystemCapability.DistributedDataManager.RelationalStore.Core


## data_rdb.getRdbStore

getRdbStore(context: Context, config: StoreConfig, version: number, callback: AsyncCallback&lt;RdbStore&gt;): void

Obtains a relational database (RDB) store. You can set parameters for the RDB store based on service requirements, call APIs to perform data operations, and use a callback to return the result.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | context | Context | Yes| Context of the app or functionality.|
  | config | [StoreConfig](#storeconfig) | Yes| Configuration of the RDB store.|
  | version | number | Yes| RDB store version.|
  | callback | AsyncCallback&lt;[RdbStore](#rdbstore)&gt; | Yes| Callback invoked to return the RDB store obtained.|

- Example
  ```
  import Ability from '@ohos.application.Ability'
  import data_rdb from '@ohos.data.rdb'
  export default class MainAbility extends Ability {
      const STORE_CONFIG = { name: "RdbTest.db"}
      const SQL_CREATE_TABLE = "CREATE TABLE IF NOT EXISTS EMPLOYEE (ID INTEGER PRIMARY KEY AUTOINCREMENT, NAME TEXT NOT NULL, AGE INTEGER, SALARY REAL, CODES BLOB)"
      data_rdb.getRdbStore(this.context, STORE_CONFIG, 1, function (err, rdbStore) {
          rdbStore.executeSql(SQL_CREATE_TABLE)
          console.info(TAG + 'create table done.')
      })
  }
  ```

## data_rdb.getRdbStore

getRdbStore(context: Context, config: StoreConfig, version: number): Promise&lt;RdbStore&gt;

Obtains an RDB store. You can set parameters for the RDB store based on service requirements, call APIs to perform data operations, and use a promise to return the result.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | context | Context | Yes| Context of the app or functionality.|
  | config | [StoreConfig](#storeconfig) | Yes| Configuration of the RDB store.|
  | version | number | Yes| RDB store version.|

- Return value
  | Type| Description|
  | -------- | -------- |
  | Promise&lt;[RdbStore](#rdbstore)&gt; | Promise used to return the RDB store obtained.|

- Example
  ```
  import Ability from '@ohos.application.Ability'
  import data_rdb from '@ohos.data.rdb'
  export default class MainAbility extends Ability {
      const STORE_CONFIG = { name: "RdbTest.db" }
      const SQL_CREATE_TABLE = "CREATE TABLE IF NOT EXISTS EMPLOYEE (ID INTEGER PRIMARY KEY AUTOINCREMENT, NAME TEXT NOT NULL, AGE INTEGER, SALARY REAL, CODES BLOB)"
      let promise = data_rdb.getRdbStore(this.context, STORE_CONFIG, 1);
      promise.then(async (rdbStore) => {
          await rdbStore.executeSql(SQL_CREATE_TABLE, null)
      }).catch((err) => {
          expect(null).assertFail();
      })
  }
  ```

## data_rdb.deleteRdbStore

deleteRdbStore(context: Context, name: string, callback: AsyncCallback&lt;void&gt;): void

Deletes an RDB store. This method uses a callback to return the result. 

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | context | Context | Yes| Context of the app or functionality.|
  | name | string | Yes| Name of the RDB store to delete.|
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback invoked to return the result. If the RDB store is deleted, **true** will be returned. Otherwise, **false** will be returned.|

- Example
  ```
  import Ability from '@ohos.application.Ability'
  import data_rdb from '@ohos.data.rdb'
  export default class MainAbility extends Ability {
      data_rdb.deleteRdbStore(this.context, "RdbTest.db", function (err, rdbStore) {
          console.info(TAG + 'delete store done.')})
  }
  ```

## data_rdb.deleteRdbStore

deleteRdbStore(context: Context, name: string): Promise&lt;void&gt;

Deletes an RDB store. This method uses a promise to return the result.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | context | Context | Yes| Context of the app or functionality.|
  | name | string | Yes| Name of the RDB store to delete.|

- Return value
  | Type| Description|
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise used to return the result. If the RDB store is deleted, **true** will be returned. Otherwise, **false** will be returned.|

- Example
  ```
  import Ability from '@ohos.application.Ability'
  import data_rdb from '@ohos.data.rdb'
  export default class MainAbility extends Ability {
      let promise = data_rdb.deleteRdbStore(this.context, "RdbTest.db")
      promise.then(()=>{
          console.info(TAG + 'delete store done.')
      })
  }
  ```

## RdbPredicates

Defines predicates for an RDB store. This class determines whether the conditional expression for the RDB store is true or false.


### constructor

constructor(name: string)


A constructor used to create an **RdbPredicates** object.


- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | name | string | Yes| Database table name.|

- Example
  ```
  let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
  ```

### inDevices

inDevices(devices: Array<string>): RdbPredicates;


Specifies a remote device on the network during distributed database synchronization.


- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | devices | Array<string> | Yes| ID of the remote device to specify.|

- Return value
  | Type| Description|
  | -------- | -------- |
  | [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that matches the specified field.|

- Example
  ```
  let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
  predicate.inDevices(['12345678abcde'])
  ```

### inAllDevices

inAllDevices(): RdbPredicates;


Connects to all remote devices on the network during distributed database synchronization.


- Return value
  | Type| Description|
  | -------- | -------- |
  | [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that matches the specified field.|

- Example
  ```
  let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
  predicates.inAllDevices()
  ```

### equalTo

equalTo(field: string, value: ValueType): RdbPredicates


Sets the **RdbPredicates** to match the field with data type **ValueType** and value equal to the specified value.


- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | field | string | Yes| Column name in the database table.|
  | value | [ValueType](#valuetype) | Yes| Value to match the **RdbPredicates**.|

- Return value
  | Type| Description|
  | -------- | -------- |
  | [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that matches the specified field.|

- Example
  ```
  let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
  predicates.equalTo("NAME", "lisi")
  ```


### notEqualTo

notEqualTo(field: string, value: ValueType): RdbPredicates


Sets the **RdbPredicates** to match the field with data type **ValueType** and value not equal to the specified value.


- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | field | string | Yes| Column name in the database table.|
  | value | [ValueType](#valuetype) | Yes| Value to match the **RdbPredicates**.|

- Return value
  | Type| Description|
  | -------- | -------- |
  | [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that matches the specified field.|

- Example
  ```
  let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
  predicates.notEqualTo("NAME", "lisi")
  ```


### beginWrap

beginWrap(): RdbPredicates


Adds a left parenthesis to the **RdbPredicates**.


- Return value
  | Type| Description|
  | -------- | -------- |
  | [RdbPredicates](#rdbpredicates) | **RdbPredicates** with a left parenthesis.|

- Example
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


- Return value
  | Type| Description|
  | -------- | -------- |
  | [RdbPredicates](#rdbpredicates) | **RdbPredicates** with a right parenthesis.|

- Example
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


- Return value
  | Type| Description|
  | -------- | -------- |
  | [RdbPredicates](#rdbpredicates) | **RdbPredicates** with the OR condition.|

- Example
  ```
  let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
  predicates.equalTo("NAME", "Lisa")
      .or()
      .equalTo("NAME", "Rose")
  ```


### and

and(): RdbPredicates


Adds the AND condition to the **RdbPredicates**.


- Return value
  | Type| Description|
  | -------- | -------- |
  | [RdbPredicates](#rdbpredicates) | **RdbPredicates** with the AND condition.|

- Example
  ```
  let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
  predicates.equalTo("NAME", "Lisa")
      .and()
      .equalTo("SALARY", 200.5)
  ```


### contains

contains(field: string, value: string): RdbPredicat


Sets the **RdbPredicates** to match a string containing the specified value.


- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | field | string | Yes| Column name in the database table.|
  | value | string | Yes| Value to match the **RdbPredicates**.|

- Return value
  | Type| Description|
  | -------- | -------- |
  | [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that matches the specified field.|

- Example
  ```
  let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
  predicates.contains("NAME", "os")
  ```


### beginsWith

beginsWith(field: string, value: string): RdbPredicates


Sets the **RdbPredicates** to match a string that starts with the specified value.


- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | field | string | Yes| Column name in the database table.|
  | value | string | Yes| Value to match the **RdbPredicates**.|

- Return value
  | Type| Description|
  | -------- | -------- |
  | [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that matches the specified field.|

- Example
  ```
  let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
  predicates.beginsWith("NAME", "os")
  ```


### endsWith

endsWith(field: string, value: string): RdbPredicates


Sets the **RdbPredicates** to match a string that ends with the specified value.


- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | field | string | Yes| Column name in the database table.|
  | value | string | Yes| Value to match the **RdbPredicates**.|

- Return value
  | Type| Description|
  | -------- | -------- |
  | [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that matches the specified field.|

- Example
  ```
  let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
  predicates.endsWith("NAME", "se")
  ```


### isNull

isNull(field: string): RdbPredicates


Sets the **RdbPredicates** to match the field whose value is null.


- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | field | string | Yes| Column name in the database table.|

- Return value
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


- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | field | string | Yes| Column name in the database table.|

- Return value
  | Type| Description|
  | -------- | -------- |
  | [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that matches the specified field.|

- Example
  ```
  let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
  predicates.isNotNull("NAME")
  ```


### like

like(field: string, value: string): RdbPredicates


Sets the **RdbPredicates** to match a string that is similar to the specified value.


- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | field | string | Yes| Column name in the database table.|
  | value | string | Yes| Value to match the **RdbPredicates**.|

- Return value
  | Type| Description|
  | -------- | -------- |
  | [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that matches the specified field.|

- Example
  ```
  let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
  predicates.like("NAME", "%os%")
  ```


### glob

glob(field: string, value: string): RdbPredicates


Sets the **RdbPredicates** to match the specified string.


- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | field | string | Yes| Column name in the database table.|
  | value | string | Yes| Value to match the **RdbPredicates**. <br>Wildcards are supported. ***** indicates zero, one, or multiple digits or characters. **?** indicates a single digit or character.|

- Return value
  | Type| Description|
  | -------- | -------- |
  | [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that matches the specified field.|

- Example
  ```
  let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
  predicates.glob("NAME", "?h*g")
  ```


### between

between(field: string, low: ValueType, high: ValueType): RdbPredicates


Sets the **RdbPredicates** to match the field with data type **ValueType** and value within the specified range.


- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | field | string | Yes| Column name in the database table.|
  | low | [ValueType](#valuetype) | Yes| Minimum value to match the **RdbPredicates**.|
  | high | [ValueType](#valuetype) | Yes| Maximum value to match the **RdbPredicates**.|

- Return value
  | Type| Description|
  | -------- | -------- |
  | [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that matches the specified field.|

- Example
  ```
  let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
  predicates.between("AGE", 10, 50)
  ```


### notBetween

notBetween(field: string, low: ValueType, high: ValueType): RdbPredicates


Sets the **RdbPredicates** to match the field with data type **ValueType** and value out of the specified range.


- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | field | string | Yes| Column name in the database table.|
  | low | [ValueType](#valuetype) | Yes| Minimum value to match the **RdbPredicates**.|
  | high | [ValueType](#valuetype) | Yes| Maximum value to match the **RdbPredicates**.|

- Return value
  | Type| Description|
  | -------- | -------- |
  | [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that matches the specified field.|

- Example
  ```
  let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
  predicates.notBetween("AGE", 10, 50)
  ```


### greaterThan

greaterThan(field: string, value: ValueType): RdbPredicatesgr


Sets the **RdbPredicates** to match the field with data type **ValueType** and value greater than the specified value.


- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | field | string | Yes| Column name in the database table.|
  | value | [ValueType](#valuetype) | Yes| Value to match the **RdbPredicates**.|

- Return value
  | Type| Description|
  | -------- | -------- |
  | [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that matches the specified field.|

- Example
  ```
  let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
  predicates.greaterThan("AGE", 18)
  ```


### lessThan

lessThan(field: string, value: ValueType): RdbPredicates


Sets the **RdbPredicates** to match the field with data type **ValueType** and value less than the specified value.


- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | field | string | Yes| Column name in the database table.|
  | value | [ValueType](#valuetype) | Yes| Value to match the **RdbPredicates**.|

- Return value
  | Type| Description|
  | -------- | -------- |
  | [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that matches the specified field.|

- Example
  ```
  let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
  predicates.lessThan("AGE", 20)
  ```


### greaterThanOrEqualTo


greaterThanOrEqualTo(field: string, value: ValueType): RdbPredicates


Sets the **RdbPredicates** to match the field with data type **ValueType** and value greater than or equal to the specified value.


- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | field | string | Yes| Column name in the database table.|
  | value | [ValueType](#valuetype) | Yes| Value to match the **RdbPredicates**.|

- Return value
  | Type| Description|
  | -------- | -------- |
  | [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that matches the specified field.|

- Example
  ```
  let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
  predicates.greaterThanOrEqualTo("AGE", 18)
  ```


### lessThanOrEqualTo


lessThanOrEqualTo(field: string, value: ValueType): RdbPredicates


Sets the **RdbPredicates** to match the field with data type **ValueType** and value less than or equal to the specified value.


- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | field | string | Yes| Column name in the database table.|
  | value | [ValueType](#valuetype) | Yes| Value to match the **RdbPredicates**.|

- Return value
  | Type| Description|
  | -------- | -------- |
  | [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that matches the specified field.|

- Example
  ```
  let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
  predicates.lessThanOrEqualTo("AGE", 20)
  ```


### orderByAsc


orderByAsc(field: string): RdbPredicates


Sets the **RdbPredicates** to match the column with values sorted in ascending order.


- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | field | string | Yes| Column name in the database table.|

- Return value
  | Type| Description|
  | -------- | -------- |
  | [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that matches the specified field.|

- Example
  ```
  let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
  predicates.orderByAsc("NAME")
  ```


### orderByDesc


orderByDesc(field: string): RdbPredicates


Sets the **RdbPredicates** to match the column with values sorted in descending order.


- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | field | string | Yes| Column name in the database table.|

- Return value
  | Type| Description|
  | -------- | -------- |
  | [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that matches the specified field.|

- Example
  ```
  let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
  predicates.orderByDesc("AGE")
  ```


### distinct

distinct(): RdbPredicates


Sets the **RdbPredicates** to filter out duplicate records.


- Return value
  | Type| Description|
  | -------- | -------- |
  | [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that can filter out duplicate records.|

- Example
  ```
  let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
  predicates.equalTo("NAME", "Rose").distinct("NAME")
  let resultSet = await rdbStore.query(predicates, ["NAME"])
  ```


### limitAs

limitAs(value: number): RdbPredicates


Sets the **RdbPredicates** to specify the maximum number of records.


- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | value | number | Yes| Maximum number of records.|

- Return value
  | Type| Description|
  | -------- | -------- |
  | [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that specifies the maximum number of records.|

- Example
  ```
  let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
  predicates.equalTo("NAME", "Rose").limitAs(3)
  ```


### offsetAs

offsetAs(rowOffset: number): RdbPredicates


Sets the **RdbPredicates** to specify the start position of the returned result.


- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | rowOffset | number | Yes| Number of rows to offset from the beginning. The value is a positive integer.|

- Return value
  | Type| Description|
  | -------- | -------- |
  | [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that specifies the start position of the returned result.|

- Example
  ```
  let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
  predicates.equalTo("NAME", "Rose").offsetAs(3)
  ```


### groupBy

groupBy(fields: Array&lt;string&gt;): RdbPredicates


Sets the **RdbPredicates** to group rows that have the same value into summary rows.


- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | fields | Array&lt;string&gt; | Yes| Names of columns to group.|

- Return value
  | Type| Description|
  | -------- | -------- |
  | [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that groups rows with the same value.|

- Example
  ```
  let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
  predicates.groupBy(["AGE", "NAME"])
  ```


### indexedBy

indexedBy(indexName: string): RdbPredicates


Sets the **RdbPredicates** object to specify the index column.


- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | indexName | string | Yes| Name of the index column.|

- Return value
  | Type| Description|
  | -------- | -------- |
  | [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that specifies the index column.|

- Example
  ```
  let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
  predicates.indexedBy("SALARY_INDEX")
  ```


### in

in(field: string, value: Array&lt;ValueType&gt;): RdbPredicates


Sets the **RdbPredicates** to match the field with data type **Array&#60;ValueType&#62;** and value within the specified range.


- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | field | string | Yes| Column name in the database table.|
  | value | Array&lt;[ValueType](#valuetype)&gt; | Yes| Array of **ValueType**s to match.|


- Return value
  | Type| Description|
  | -------- | -------- |
  | [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that matches the specified field.|

- Example
  ```
  let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
  predicates.in("AGE", [18, 20])
  ```


### notIn

notIn(field: string, value: Array&lt;ValueType&gt;): RdbPredicates


Sets the **RdbPredicates** to match the field with data type **Array&#60;ValueType&#62;** and value out of the specified range.


- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | field | string | Yes| Column name in the database table.|
  | value | Array&lt;[ValueType](#valuetype)&gt; | Yes| Array of **ValueType**s to match.|


- Return value
  | Type| Description|
  | -------- | -------- |
  | [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that matches the specified field.|

- Example
  ```
  let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
  predicates.notIn("NAME", ["Lisa", "Rose"])
  ```


## RdbStore

Provides methods to manage an RDB store.


### insert

insert(name: string, values: ValuesBucket, callback: AsyncCallback&lt;number&gt;):void

Inserts a row of data into a table. This method uses a callback to return the result.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | name | string | Yes| Name of the target table.|
  | values | [ValuesBucket](#valuesbucket) | Yes| Row of data to insert.|
  | callback | AsyncCallback&lt;number&gt; | Yes| Callback invoked to return the result. If the operation is successful, the row ID will be returned. Otherwise, **-1** will be returned.|

- Example
  ```
  const valueBucket = {
      "NAME": "Lisa",
      "AGE": 18,
      "SALARY": 100.5,
      "CODES": new Uint8Array([1, 2, 3, 4, 5]),
  }
  rdbStore.insert("EMPLOYEE", valueBucket, function (err, ret) {
      expect(1).assertEqual(ret)
      console.log(TAG + "insert first done: " + ret)})
  ```


### insert

insert(name: string, values: ValuesBucket):Promise&lt;number&gt;

Inserts a row of data into a table. This method uses a promise to return the result.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | name | string | Yes| Name of the target table.|
  | values | [ValuesBucket](#valuesbucket) | Yes| Row of data to insert.|

- Return value
  | Type| Description|
  | -------- | -------- |
  | Promise&lt;number&gt; | Promise used to return the result. If the operation is successful, the row ID will be returned. Otherwise, **-1** will be returned.|

- Example
  ```
  const valueBucket = {
      "NAME": "Lisa",
      "AGE": 18,
      "SALARY": 100.5,
      "CODES": new Uint8Array([1, 2, 3, 4, 5]),
  }
  let promise = rdbStore.insert("EMPLOYEE", valueBucket)
  promise.then(async (ret) => {
      await console.log(TAG + "insert first done: " + ret)
  }).catch((err) => {})
  ```


### update

update(values: ValuesBucket, rdbPredicates: RdbPredicates, callback: AsyncCallback&lt;number&gt;):void

Updates data in the database based on the specified RdbPredicates object. This method uses a callback to return the result.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | values | [ValuesBucket](#valuesbucket) | Yes| Data to update. The value specifies the row of data to be updated in the database. The key-value pair is associated with the column name in the target table.|
  | rdbPredicates | [RdbPredicates](#rdbpredicates) | Yes| Row of data to insert.|
  | callback | AsyncCallback&lt;number&gt; | Yes| Callback invoked to return the number of rows updated.|

- Example
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
      console.log(TAG + "updated row count: " + changedRows)})
  ```


### update

update(values: ValuesBucket, rdbPredicates: RdbPredicates):Promise&lt;number&gt;

Updates data in the database based on the specified RdbPredicates object. This method uses a promise to return the result.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | values | [ValuesBucket](#valuesbucket) | Yes| Data to update. The value specifies the row of data to be updated in the database. The key-value pair is associated with the column name in the target table.|
  | rdbPredicates | [RdbPredicates](#rdbpredicates) | Yes| Row of data to insert.|

- Return value
  | Type| Description|
  | -------- | -------- |
  | Promise&lt;number&gt; | Promise used to return the number of rows updated.|

- Example
  ```
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
      await console.log(TAG + "updated row count: " + changedRows)
  }).catch((err) => {})
  ```


### delete

delete(rdbPredicates: RdbPredicates, callback: AsyncCallback&lt;number&gt;):void


Deletes data from the database based on the specified RdbPredicates object. This method uses a callback to return the result.


- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | rdbPredicates | [RdbPredicates](#rdbpredicates) | Yes| Conditions specified for deleting data.|
  | callback | AsyncCallback&lt;number&gt; | Yes| Callback invoked to return the number of rows deleted.|

- Example
  ```
  let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
  predicates.equalTo("NAME", "Lisa")
  rdbStore.delete(predicates, function (err, rows) {
      console.log(TAG + "delete rows: " + rows)})
  ```


### delete

delete(rdbPredicates: RdbPredicates):Promise&lt;number&gt;

Deletes data from the database based on the specified RdbPredicates object. This method uses a promise to return the result.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | rdbPredicates | [RdbPredicates](#rdbpredicates) | Yes| Conditions specified for deleting data.|

- Return value
  | Type| Description|
  | -------- | -------- |
  | Promise&lt;number&gt; | Promise used to return the number of rows deleted.|

- Example
  ```
  let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
  predicates.equalTo("NAME", "Lisa")
  let promise = rdbStore.delete(predicates)
  promise.then((rows) => {
      console.log(TAG + "delete rows: " + rows)
  }).catch((err) => {})
  ```


### query

query(rdbPredicates: RdbPredicates, columns: Array&lt;string&gt;, callback: AsyncCallback&lt;ResultSet&gt;):void

Queries data in the database based on specified conditions. This method uses a callback to return the result.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | rdbPredicates | [RdbPredicates](#rdbpredicates) | Yes| Query conditions specified by the **RdbPredicates** object.|
  | columns | Array&lt;string&gt; | Yes| Columns to query. If this parameter is not specified, the query applies to all columns.|
  | callback | AsyncCallback&lt;[ResultSet](js-apis-data-resultset.md)&gt; | Yes| Callback invoked to return the result. If the operation is successful, a **ResultSet** object will be returned.|

- Example
  ```
  let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
  predicates.equalTo("NAME", "Rose")
  rdbStore.query(predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"], function (err, resultSet) {
      console.log(TAG + "resultSet column names:" + resultSet.columnNames)
      console.log(TAG + "resultSet column count:" + resultSet.columnCount)})
  ```


### query

query(rdbPredicates: RdbPredicates, columns?: Array&lt;string&gt;):Promise&lt;ResultSet&gt;

Queries data in the database based on specified conditions. This method uses a promise to return the result.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | rdbPredicates | [RdbPredicates](#rdbpredicates) | Yes| Query conditions specified by the **RdbPredicates** object.|
  | columns | Array&lt;string&gt; | No| Columns to query. If this parameter is not specified, the query applies to all columns.|

- Return value
  | Type| Description|
  | -------- | -------- |
  | Promise&lt;[ResultSet](../apis/js-apis-data-resultset.md)&gt; | Promise used to return the result. If the operation is successful, a **ResultSet** object will be returned.|

- Example
  ```
  let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
  predicates.equalTo("NAME", "Rose")
  let promise = rdbStore.query(predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"])
  promise.then((resultSet) => {
      console.log(TAG + "resultSet column names:" + resultSet.columnNames)
      console.log(TAG + "resultSet column count:" + resultSet.columnCount)})
  ```


### querySql<sup>8+</sup>

querySql(sql: string, bindArgs: Array&lt;ValueType&gt;, callback: AsyncCallback&lt;ResultSet&gt;):void

Queries data in the RDB store using the specified SQL statement. This method uses a callback to return the result.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | sql | string | Yes| SQL statement to run.|
  | bindArgs | Array&lt;[ValueType](#valuetype)&gt; | Yes| Values of the parameters in the SQL statement.|
  | callback | AsyncCallback&lt;[ResultSet](js-apis-data-resultset.md)&gt; | Yes| Callback invoked to return the result. If the operation is successful, a **ResultSet** object will be returned.|

- Example
  ```
  rdbStore.querySql("SELECT * FROM EMPLOYEE CROSS JOIN BOOK WHERE BOOK.NAME = ?", ['sanguo'], function (err, resultSet) {
      console.log(TAG + "resultSet column names:" + resultSet.columnNames)
      console.log(TAG + "resultSet column count:" + resultSet.columnCount)})
  ```


### querySql<sup>8+</sup>

querySql(sql: string, bindArgs?: Array&lt;ValueType&gt;):Promise&lt;ResultSet&gt;

Queries data in the RDB store using the specified SQL statement. This method uses a promise to return the result.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | sql | string | Yes| SQL statement to run.|
  | bindArgs | Array&lt;[ValueType](#valuetype)&gt; | No| Values of the parameters in the SQL statement.|

- Return value
  | Type| Description|
  | -------- | -------- |
  | Promise&lt;[ResultSet](../apis/js-apis-data-resultset.md)&gt; | Promise used to return the result. If the operation is successful, a **ResultSet** object will be returned.|

- Example
  ```
  let promise = rdbStore.querySql("SELECT * FROM EMPLOYEE CROSS JOIN BOOK WHERE BOOK.NAME = ?", ['sanguo'])
  promise.then((resultSet) => {
      console.log(TAG + "resultSet column names:" + resultSet.columnNames)
      console.log(TAG + "resultSet column count:" + resultSet.columnCount)})
  ```


### executeSql

executeSql(sql: string, bindArgs: Array&lt;ValueType&gt;, callback: AsyncCallback&lt;void&gt;):void

Runs the SQL statement that contains the specified parameters but does not return a value. This method uses a callback to return the execution result.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | sql | string | Yes| SQL statement to run.|
  | bindArgs | Array&lt;[ValueType](#valuetype)&gt; | Yes| Values of the parameters in the SQL statement.|
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback invoked to return the result.|

- Example
  ```
  rdbStore.executeSql("DELETE FROM EMPLOYEE", null, function () {
      console.info(TAG + 'delete done.')})
  ```


### executeSql

executeSql(sql: string, bindArgs?: Array&lt;ValueType&gt;):Promise&lt;void&gt;

Runs the SQL statement that contains the specified parameters but does not return a value. This method uses a promise to return the execution result.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | sql | string | Yes| SQL statement to run.|
  | bindArgs | Array&lt;[ValueType](#valuetype)&gt; | No| Values of the parameters in the SQL statement.|

- Return value
  | Type| Description|
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise used to return the result.|

- Example
  ```
  let promise = rdbStore.executeSql("DELETE FROM EMPLOYEE")
  promise.then(() => {
      console.info(TAG + 'delete done.')})
  ```

### setDistributedTables

setDistributedTables(tables: Array<string>, callback: AsyncCallback<void>): void;

Sets a list of distributed tables. This method uses a callback to return the result.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | tables | Array<string> | Yes| Names of the distributed tables to be set.|
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback invoked to return the result.|

- Example
  ```
  rdbStore.setDistributedTables(["EMPLOYEE"], function (err) {
      if (err) {
          console.info('setDistributedTables failed.')
          return
      }
      console.info('setDistributedTables success.')
  })
  ```


### setDistributedTables

 setDistributedTables(tables: Array<string>): Promise<void>;

Sets a list of distributed tables. This method uses a promise to return the result.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | tables | Array<string> | Yes| Names of the distributed tables to be set.|

- Return value
  | Type| Description|
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise used to return the result.|

- Example
  ```
  let promise = rdbStore.setDistributedTables(["EMPLOYEE"])
  promise.then(() => {
      console.info("setDistributedTables success.")
  }).catch((err) => {
      console.info("setDistributedTables failed."")
  })
  ```

### obtainDistributedTableName

obtainDistributedTableName(device: string, table: string, callback: AsyncCallback<string>): void;

Obtains the distributed table name for a remote device based on the local table name. The distributed table name is required when the database of a remote device is queried. This method uses a callback to return the result.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | device | string | Yes| Remote device.|
  | table | string | Yes| Local table name.|
  | callback | AsyncCallback&lt;string&gt; | Yes| Callback invoked to return the result. If the operation succeeds, the distributed table name of the remote device is returned.|

- Example
  ```
  rdbStore.obtainDistributedTableName(deviceId, "EMPLOYEE", function (err, tableName) {
      if (err) {
          console.info('obtainDistributedTableName failed.')
          return
      }
      console.info('obtainDistributedTableName success, tableName=.' + tableName)
   })
  ```


### obtainDistributedTableName

 obtainDistributedTableName(device: string, table: string): Promise<string>;

Obtains the distributed table name for a remote device based on the local table name. The distributed table name is required when the database of a remote device is queried. This method uses a promise to return the result.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | device | string | Yes| Remote device.|
  | table | string | Yes| Local table name.|

- Return value
  | Type| Description|
  | -------- | -------- |
  | Promise&lt;string&gt; | Promise used to return the result. If the operation succeeds, the distributed table name of the remote device is returned.|

- Example
  ```
  let promise = rdbStore.obtainDistributedTableName(deviceId, "EMPLOYEE")
  promise.then((tableName) => {
      console.info('obtainDistributedTableName success, tableName=' + tableName)
  }).catch((err) => {
      console.info('obtainDistributedTableName failed.')
  })
  ```

### sync

sync(mode: SyncMode, predicates: RdbPredicates, callback: AsyncCallback<Array<[string, number]>>): void;

Synchronizes data between devices. This method uses a callback to return the result.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | mode | SyncMode | Yes| Data synchronization mode, which can be **push** or **pull**.|
  | predicates | RdbPredicates | Yes| **RdbPredicates** object that specifies the data and devices to synchronize.|
  | callback | AsyncCallback&lt;Array<[string, number]>&gt; | Yes| Callback invoked to send the synchronization result to the caller. <br>**string** indicates the device ID. <br>**number** indicates the synchronization status of each device. The value **0** indicates a successful synchronization. Other values indicate a synchronization failure. |

- Example
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


### sync

 sync(mode: SyncMode, predicates: RdbPredicates): Promise<Array<[string, number]>>;

Synchronizes data between devices. This method uses a promise to return the result.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | mode | SyncMode | Yes| Data synchronization mode, which can be **push** or **pull**.|
  | predicates | RdbPredicates | Yes| **RdbPredicates** object that specifies the data and devices to synchronize.|

- Return value
  | Type| Description|
  | -------- | -------- |
  | Promise&lt;Array<[string, number]>&gt; | Promise used to return the synchronization result to the caller. <br>**string** indicates the device ID. <br>**number** indicates the synchronization status of each device. The value **0** indicates a successful synchronization. Other values indicate a synchronization failure. |

- Example
  ```
  let predicate = new rdb.RdbPredicates('EMPLOYEE')
  predicate.inDevices(['12345678abcde'])
  let promise = rdbStore.sync(rdb.SyncMode.SYNC_MODE_PUSH, predicate)
  promise.then(result) {
      console.log('sync done.')
      for (let i = 0; i < result.length; i++) {
          console.log('device=' + result[i][0] + ' status=' + result[i][1])
      }
   }).catch((err) => {
       console.log('sync failed')
   })
  ```

### on

on(event: 'dataChange', type: SubscribeType, observer: Callback<Array<string>>): void;

Registers an observer for this RDB store. When the data in the RDB store changes, a callback is invoked to return the data changes.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | SubscribeType | Yes| Type defined in **SubscribeType**.|
  | observer | Callback<Array<string>> | Yes| Observer that listens for the data changes in the RDB store.|

- Example
  ```
  function storeObserver(devices) {
      for (let i = 0; i < devices.length; i++) {
          console.log('device=' + device[i] + ' data changed')
       }
   }
   try {
       rdbStore.on('dataChange', rdb.SubscribeType.SUBSCRIBE_TYPE_REMOTE, storeObserver)
   } catch (err) {
       console.log('register observer failed')
   }
  ```

### off

off(event:'dataChange', type: SubscribeType, observer: Callback<Array<string>>): void;

Deletes the specified observer of the RDB store. This method uses a callback to return the result.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | SubscribeType | Yes| Type defined in **SubscribeType**.|
  | observer | Callback<Array<string>> | Yes| Data change observer registered.|

- Example
  ```
  function storeObserver(devices) {
      for (let i = 0; i < devices.length; i++) {
          console.log('device=' + device[i] + ' data changed')
      }
  }
  try {
      rdbStore.off('dataChange', rdb.SubscribeType.SUBSCRIBE_TYPE_REMOTE, storeObserver)
  } catch (err) {
      console.log('unregister observer failed')
  }
  ```


## StoreConfig

Manages the configuration of an RDB store.

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string | Yes| Database file name.|


## ValueType

Defines the data types allowed.

| Name| Description|
| -------- | -------- |
| number | Number.|
| string | String.|
| boolean | Boolean.|


## ValuesBucket

Defines a bucket to store key-value pairs.


| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| [key:&nbsp;string] | [ValueType](#valuetype)\|&nbsp;Uint8Array&nbsp;\|&nbsp;null | Yes| Defines a bucket to store key-value pairs.|


## SyncMode

Defines the database synchronization mode.

| Name| Description|
| -------- | -------- |
| SYNC_MODE_PUSH | Data is pushed from a local device to a remote device.|
| SYNC_MODE_PULL | Data is loaded from a remote device to a local device.|

## SubscribeType

Defines the subscription type.

| Name| Description|
| -------- | -------- |
| SUBSCRIBE_TYPE_REMOTE | Subscribe to remote data changes.|
