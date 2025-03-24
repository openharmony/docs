# @ohos.data.dataAbility (DataAbility Predicates)

The **DataAbility** module provides APIs to create predicates for querying data from relational database (RDB) stores.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```js
import { dataAbility } from '@kit.ArkData';
```

## dataAbility.createRdbPredicates

createRdbPredicates(name: string, dataAbilityPredicates: DataAbilityPredicates): rdb.RdbPredicates

Creates an **RdbPredicates** object with the specified table name and **DataAbilityPredicates** object.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string | Yes| Name of a database table.|
| dataAbilityPredicates | [DataAbilityPredicates](#dataabilitypredicates) | Yes| **DataAbilityPredicates** object.  |

**Return value**

| Type| Description|
| -------- | -------- |
| rdb.[RdbPredicates](js-apis-data-rdb.md#rdbpredicates) | **RdbPredicates** object created.|

**Example**

  ```js
  let dataAbilityPredicates = new dataAbility.DataAbilityPredicates()
  dataAbilityPredicates.equalTo("NAME", "Rose")
  // EMPLOYEE is a table created in a relational database.
  let predicates = dataAbility.createRdbPredicates("EMPLOYEE", dataAbilityPredicates)
  ```

## DataAbilityPredicates

Provides predicates for implementing diverse query methods.

**Initialization**

  ```js
  let dataAbilityPredicates = new dataAbility.DataAbilityPredicates()
  ```

### equalTo

equalTo(field: string, value: ValueType): DataAbilityPredicates

Sets a **DataAbilityPredicates** object to match the field with data type **ValueType** and value equals to the specified value.

This API is similar to the SQL equal to (=) operator.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the table.|
| value | [ValueType](#valuetype) | Yes| Value to match the **DataAbilityPredicates**.|

**Return value**

| Type| Description|
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | **DataAbilityPredicates** object that matches the specified field.|

**Example**

  ```js
  dataAbilityPredicates.equalTo("NAME", "lisi")
  ```

### notEqualTo

notEqualTo(field: string, value: ValueType): DataAbilityPredicates

Sets a **DataAbilityPredicates** object to match the field with data type **ValueType** and value not equal to the specified value.

This API is similar to the SQL not equal (!=) operator.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the table.|
| value | [ValueType](#valuetype) | Yes| Value to match the **DataAbilityPredicates**.|

**Return value**

| Type| Description|
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | **DataAbilityPredicates** object that matches the specified field.|

**Example**

  ```js
  dataAbilityPredicates.notEqualTo("NAME", "lisi")
  ```

### beginWrap

beginWrap(): DataAbilityPredicates

Adds a left parenthesis to this **DataAbilityPredicates**. This API is similar to "(" in an SQL statement and must be used with **endWrap**.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Return value**

| Type| Description|
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | **DataAbilityPredicates** object with a left parenthesis.|

**Example**

  ```js
  dataAbilityPredicates.equalTo("NAME", "lisi")
      .beginWrap()
      .equalTo("AGE", 18)
      .or()
      .equalTo("SALARY", 200.5)
      .endWrap()
  ```

### endWrap

endWrap(): DataAbilityPredicates

Adds a right parenthesis to this **DataAbilityPredicates**. This API is similar to ")" in an SQL statement and must be used with **beginWrap**.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Return value**

| Type| Description|
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | **DataAbilityPredicates** object with a right parenthesis.|

**Example**

  ```js
  dataAbilityPredicates.equalTo("NAME", "lisi")
      .beginWrap()
      .equalTo("AGE", 18)
      .or()
      .equalTo("SALARY", 200.5)
      .endWrap()
  ```

### or

or(): DataAbilityPredicates

Adds the OR condition to this **DataAbilityPredicates**.

This API is similar to the SQL **or** operator.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Return value**

| Type| Description|
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | **DataAbilityPredicates** object with the OR condition.|

**Example**

  ```js
  dataAbilityPredicates.equalTo("NAME", "Lisa")
      .or()
      .equalTo("NAME", "Rose")
  ```

### and

and(): DataAbilityPredicates

Adds the AND condition to this **DataAbilityPredicates**.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Return value**

| Type| Description|
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | **DataAbilityPredicates** object with the AND condition.|

**Example**

  ```js
  dataAbilityPredicates.equalTo("NAME", "Lisa")
      .and()
      .equalTo("SALARY", 200.5)
  ```

### contains

contains(field: string, value: string): DataAbilityPredicates

Sets a **DataAbilityPredicates** object to match a string containing the specified value.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the table.|
| value | string | Yes| Value to match the **DataAbilityPredicates**.|

**Return value**

| Type| Description|
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | **DataAbilityPredicates** object that matches the specified field.|

**Example**

  ```js
  dataAbilityPredicates.contains("NAME", "os")
  ```

### beginsWith

beginsWith(field: string, value: string): DataAbilityPredicates

Sets a **DataAbilityPredicates** object to match a string that starts with the specified value.

This API is similar to the percent sign (%) in SQL statements.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the table.|
| value | string | Yes| Value to match the **DataAbilityPredicates**.|

**Return value**

| Type| Description|
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | **DataAbilityPredicates** object that matches the specified field.|

**Example**

  ```js
  dataAbilityPredicates.beginsWith("NAME", "os")
  ```

### endsWith

endsWith(field: string, value: string): DataAbilityPredicates

Sets a **DataAbilityPredicates** object to match a string that ends with the specified value.

This API is similar to the percent sign (%) in SQL statements.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the table.|
| value | string | Yes| Value to match the **DataAbilityPredicates**.|

**Return value**

| Type| Description|
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | **DataAbilityPredicates** object that matches the specified field.|

**Example**

  ```
  dataAbilityPredicates.endsWith("NAME", "se")
  ```

### isNull

isNull(field: string): DataAbilityPredicates

Sets a **DataAbilityPredicates** object to match the field whose value is null.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the table.|

**Return value**

| Type| Description|
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | **DataAbilityPredicates** object that matches the specified field.|

**Example**

  ```js
  dataAbilityPredicates.isNull("NAME")
  ```

### isNotNull

isNotNull(field: string): DataAbilityPredicates

Sets a **DataAbilityPredicates** object to match the field whose value is not null.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the table.|

**Return value**

| Type| Description|
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | **DataAbilityPredicates** object that matches the specified field.|

**Example**

  ```js
  dataAbilityPredicates.isNotNull("NAME")
  ```

### like

like(field: string, value: string): DataAbilityPredicates

Sets a **DataAbilityPredicates** object to match a string that is similar to the specified value.

This API is similar to the SQL **like** statement.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the table.|
| value | string | Yes| Value to match the **DataAbilityPredicates**.|

**Return value**

| Type| Description|
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | **DataAbilityPredicates** object that matches the specified field.|

**Example**

  ```js
  dataAbilityPredicates.like("NAME", "%os%")
  ```

### glob

glob(field: string, value: string): DataAbilityPredicates

Sets a **DataAbilityPredicates** object to match the specified string. Different from **like**, the input parameters of this API are case-sensitive.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the table.|
| value | string | Yes| Value to match the **DataAbilityPredicates**.|

**Return value**

| Type| Description|
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | **DataAbilityPredicates** object that matches the specified field.|

**Example**

  ```js
  dataAbilityPredicates.glob("NAME", "?h*g")

  // Only the data with name of Lisa matches the specified predicate.
  dataAbilityPredicates.glob("NAME", "Lisa")

  // Only the data with name of lisa matches the specified predicate.
  dataAbilityPredicates.glob("NAME", "lisa")
  ```

### between

between(field: string, low: ValueType, high: ValueType): DataAbilityPredicates

Sets a **DataAbilityPredicates** object to match a field whose data type is **ValueType** and value is within the specified range.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the table.|
| low | [ValueType](#valuetype) | Yes| Minimum value to match the **DataAbilityPredicates**.|
| high | [ValueType](#valuetype) | Yes| Maximum value to match the **DataAbilityPredicates**.|

**Return value**

| Type| Description|
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | **DataAbilityPredicates** object that matches the specified field.|

**Example**

  ```js
  dataAbilityPredicates.between("AGE", 10, 50)
  ```

### notBetween

notBetween(field: string, low: ValueType, high: ValueType): DataAbilityPredicates

Sets a **DataAbilityPredicates** object to match the field with data type **ValueType** and value out of the specified range.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the table.|
| low | [ValueType](#valuetype) | Yes| Minimum value to match the **DataAbilityPredicates**.|
| high | [ValueType](#valuetype) | Yes| Maximum value to match the **DataAbilityPredicates**.|

**Return value**

| Type| Description|
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | **DataAbilityPredicates** object that matches the specified field.|

**Example**

  ```js
  dataAbilityPredicates.notBetween("AGE", 10, 50)
  ```

### greaterThan

greaterThan(field: string, value: ValueType): DataAbilityPredicates

Sets a **DataAbilityPredicates** object to match the field with data type **ValueType** and value greater than the specified value.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the table.|
| value | [ValueType](#valuetype) | Yes| Value to match the **DataAbilityPredicates**.|

**Return value**

| Type| Description|
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | **DataAbilityPredicates** object that matches the specified field.|

**Example**

  ```js
  dataAbilityPredicates.greaterThan("AGE", 18)
  ```

### lessThan

lessThan(field: string, value: ValueType): DataAbilityPredicates

Sets a **DataAbilityPredicates** object to match the field with data type **ValueType** and value less than the specified value.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the table.|
| value | [ValueType](#valuetype) | Yes| Value to match the **DataAbilityPredicates**.|

**Return value**

| Type| Description|
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | **DataAbilityPredicates** object that matches the specified field.|

**Example**

  ```js
  dataAbilityPredicates.lessThan("AGE", 20)
  ```

### greaterThanOrEqualTo

greaterThanOrEqualTo(field: string, value: ValueType): DataAbilityPredicates

Sets a **DataAbilityPredicates** object to match the field with data type **ValueType** and value greater than or equal to the specified value.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the table.|
| value | [ValueType](#valuetype) | Yes| Value to match the **DataAbilityPredicates**.|

**Return value**

| Type| Description|
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | **DataAbilityPredicates** object that matches the specified field.|

**Example**

  ```js
  dataAbilityPredicates.greaterThanOrEqualTo("AGE", 18)
  ```

### lessThanOrEqualTo

lessThanOrEqualTo(field: string, value: ValueType): DataAbilityPredicates

Sets a **DataAbilityPredicates** object to match the field with data type **ValueType** and value less than or equal to the specified value.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the table.|
| value | [ValueType](#valuetype) | Yes| Value to match the **DataAbilityPredicates**.|

**Return value**

| Type| Description|
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | **DataAbilityPredicates** object that matches the specified field.|

**Example**

  ```js
  dataAbilityPredicates.lessThanOrEqualTo("AGE", 20)
  ```

### orderByAsc

orderByAsc(field: string): DataAbilityPredicates

Sets a **DataAbilityPredicates** object to sort the data records in ascending order. When there are multiple **orderByAsc**s, the first **orderByAsc** used has the highest priority.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the table.|

**Return value**

| Type| Description|
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | **DataAbilityPredicates** object that matches the specified field.|

**Example**

  ```js
  // Sort data by name first; for the records with the same name, sort them by age; for the records with the same name and age, sort them by salary in ascending order.
  dataAbilityPredicates.orderByAsc("NAME").orderByAsc("AGE").orderByAsc("SALARY")
  ```

### orderByDesc

orderByDesc(field: string): DataAbilityPredicates

Sets a **DataAbilityPredicates** object to sort the data records in descending order. When there are multiple **orderByDesc**s, the first **orderByDesc** used has the highest priority.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the table.|

**Return value**

| Type| Description|
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | **DataAbilityPredicates** object that matches the specified field.|

**Example**

  ```js
  // Sort the data by age first. For the data records with the same age, sort them by salary.
  dataAbilityPredicates.orderByDesc("AGE").orderByDesc("SALARY")
  ```

### distinct

distinct(): DataAbilityPredicates

Sets a **DataAbilityPredicates** object to filter out duplicate records.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Return value**

| Type| Description|
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | **DataAbilityPredicates** object that can filter out duplicate records.|

**Example**

  ```js
  dataAbilityPredicates.equalTo("NAME", "Rose").distinct()
  ```

### limitAs

limitAs(value: number): DataAbilityPredicates

Set a **DataAbilityPredicates** object to specify the maximum number of records.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | number | Yes| Maximum number of records.|

**Return value**

| Type| Description|
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | **DataAbilityPredicates** object that specifies the maximum number of records.|

**Example**

  ```js
  dataAbilityPredicates.equalTo("NAME", "Rose").limitAs(3)
  ```

### offsetAs

offsetAs(rowOffset: number): DataAbilityPredicates

Sets a **DataAbilityPredicates** object to specify the start position of the returned result. This API must be used with **limitAs**.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| rowOffset | number | Yes| Number of rows to offset from the beginning. The value is a positive integer.|

**Return value**

| Type| Description|
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | **DataAbilityPredicates** object that specifies the start position of the returned result.|

**Example**

  ```js
  // Display the three data records following the first three records.
  dataAbilityPredicates.equalTo("NAME", "Rose").offsetAs(3).limitAs(3)
  ```


### groupBy

groupBy(fields: Array&lt;string&gt;): DataAbilityPredicates

Sets a **DataAbilityPredicates** object to group rows that have the same value into summary rows.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| fields | Array&lt;string&gt; | Yes| Names of columns to group.|

**Return value**

| Type| Description|
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | **DataAbilityPredicates** object that groups rows with the same value.|

**Example**

  ```js
  dataAbilityPredicates.groupBy(["AGE", "NAME"])
  ```

### indexedBy

indexedBy(field: string): DataAbilityPredicates

Sets a **DataAbilityPredicates** object to specify the index column. Before calling this API, you need to create an index column.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Name of the index.|

**Return value**

| Type| Description|
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | **DataAbilityPredicates** object that specifies the index column.|

**Example**

  ```js
  import { dataAbility, relationalStore } from '@kit.ArkData';

  let context = getContext(this);

  const STORE_CONFIG : relationalStore.StoreConfig = {
      name: 'RdbTest.db', // Database file name.
      securityLevel: relationalStore.SecurityLevel.S3,
  };
  // Table structure: EMPLOYEE (NAME, AGE, SALARY, CODES)
  const SQL_CREATE_TABLE = 'CREATE TABLE IF NOT EXISTS EMPLOYEE (ID INTEGER PRIMARY KEY AUTOINCREMENT, NAME TEXT NOT NULL, AGE INTEGER, SALARY REAL, CODES BLOB)'; // SQL statement for creating a data table.
  relationalStore.getRdbStore(context, STORE_CONFIG, async (err, store) => {
    if (err) {
      console.error(`Failed to get RdbStore. Code:${err.code}, message:${err.message}`);
      return;
    }
    console.info('Succeeded in getting RdbStore.');


    await store.executeSql(SQL_CREATE_TABLE); // Create a data table.


    // Create an index.
    const SQL_CREATE_INDEX = 'CREATE INDEX SALARY_INDEX ON EMPLOYEE(SALARY)'
    await store.executeSql(SQL_CREATE_INDEX);
    // ...

    let dataAbilityPredicates = new dataAbility.DataAbilityPredicates()
    dataAbilityPredicates.indexedBy("SALARY_INDEX")

    //  ...
  })
  ```

### in

in(field: string, value: Array&lt;ValueType&gt;): DataAbilityPredicates

Sets a **DataAbilityPredicates** object to match the field with data type Array\<ValueType> and value within the specified range.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the table.|
| value | Array&lt;[ValueType](#valuetype)&gt; | Yes| Array of **ValueType**s to match.|


**Return value**

| Type| Description|
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | **DataAbilityPredicates** object that matches the specified field.|

**Example**

  ```js
  dataAbilityPredicates.in("AGE", [18, 20])
  ```

### notIn

notIn(field: string, value: Array&lt;ValueType&gt;): DataAbilityPredicates

Sets a **DataAbilityPredicates** object to match the field with data type Array\<ValueType> and value out of the specified range.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the table.|
| value | Array&lt;[ValueType](#valuetype)&gt; | Yes| Array of **ValueType**s to match.|

**Return value**

| Type| Description|
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | **DataAbilityPredicates** object that matches the specified field.|

**Example**

  ```js
  dataAbilityPredicates.notIn("NAME", ["Lisa", "Rose"])
  ```

## ValueType

type ValueType = number | string | boolean

Enumerates the value types.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

| Type   | Description                |
| ------- | -------------------- |
| number  | The value is a number.  |
| string  | The value is a string.  |
| boolean | The value is of Boolean type.|
