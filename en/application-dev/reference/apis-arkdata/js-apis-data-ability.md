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

Creates an **RdbPredicates** object with a table name and **DataAbilityPredicates** object.

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
  // EMPLOYEE is a table created in an RDB store.
  let predicates = dataAbility.createRdbPredicates("EMPLOYEE", dataAbilityPredicates)
  ```

## DataAbilityPredicates

Provides APIs for creating diverse query conditions.

**Initialization**

  ```js
  let dataAbilityPredicates = new dataAbility.DataAbilityPredicates()
  ```

### equalTo

equalTo(field: string, value: ValueType): DataAbilityPredicates

Creates a **DataAbilityPredicates** object to search for the records in the specified column that are equal to the given value.

This API is similar to the SQL equal to (=) operator.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the table.|
| value | [ValueType](#valuetype) | Yes| Value to match.|

**Return value**

| Type| Description|
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | **DataAbilityPredicates** object created.|

**Example**

  ```js
  dataAbilityPredicates.equalTo("NAME", "lisi")
  ```

### notEqualTo

notEqualTo(field: string, value: ValueType): DataAbilityPredicates

Creates a **DataAbilityPredicates** object to search for the records in the specified column that are not equal to the given value.

This API is similar to the SQL not equal (!=) operator.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the table.|
| value | [ValueType](#valuetype) | Yes| Value to match.|

**Return value**

| Type| Description|
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | **DataAbilityPredicates** object created.|

**Example**

  ```js
  dataAbilityPredicates.notEqualTo("NAME", "lisi")
  ```

### beginWrap

beginWrap(): DataAbilityPredicates

Creates a **DataAbilityPredicates** object to add a left parenthesis. This API is similar to "(" in an SQL statement and must be used with **endWrap**.

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

Creates a **DataAbilityPredicates** object to add a right parenthesis. This API is similar to ")" in an SQL statement and must be used with **beginWrap**.

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

Creates a **DataAbilityPredicates** object to add the OR condition.

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

Creates a **DataAbilityPredicates** object to add the AND condition.

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

Creates a **DataAbilityPredicates** object to search for the records in the specified column that contain the given value.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the table.|
| value | string | Yes| Value to match.|

**Return value**

| Type| Description|
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | **DataAbilityPredicates** object created.|

**Example**

  ```js
  dataAbilityPredicates.contains("NAME", "os")
  ```

### beginsWith

beginsWith(field: string, value: string): DataAbilityPredicates

Creates a **DataAbilityPredicates** object to search for the records in the specified column that begin with the given value.

This API is similar to the percent sign (%) in SQL statements.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the table.|
| value | string | Yes| Value to match.|

**Return value**

| Type| Description|
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | **DataAbilityPredicates** object created.|

**Example**

  ```js
  dataAbilityPredicates.beginsWith("NAME", "os")
  ```

### endsWith

endsWith(field: string, value: string): DataAbilityPredicates

Creates a **DataAbilityPredicates** object to search for the records in the specified column that end with the given value.

This API is similar to the percent sign (%) in SQL statements.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the table.|
| value | string | Yes| Value to match.|

**Return value**

| Type| Description|
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | **DataAbilityPredicates** object created.|

**Example**

  ```
  dataAbilityPredicates.endsWith("NAME", "se")
  ```

### isNull

isNull(field: string): DataAbilityPredicates

Creates a **DataAbilityPredicates** object to search for the records in the specified column that are **null**.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the table.|

**Return value**

| Type| Description|
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | **DataAbilityPredicates** object created.|

**Example**

  ```js
  dataAbilityPredicates.isNull("NAME")
  ```

### isNotNull

isNotNull(field: string): DataAbilityPredicates

Creates a **DataAbilityPredicates** object to search for the records in the specified column that are not **null**.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the table.|

**Return value**

| Type| Description|
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | **DataAbilityPredicates** object created.|

**Example**

  ```js
  dataAbilityPredicates.isNotNull("NAME")
  ```

### like

like(field: string, value: string): DataAbilityPredicates

Creates a **DataAbilityPredicates** object to search for the records in the specified column that are similar to the given value.

This API is similar to the SQL **like** statement.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the table.|
| value | string | Yes| Value to match.|

**Return value**

| Type| Description|
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | **DataAbilityPredicates** object created.|

**Example**

  ```js
  dataAbilityPredicates.like("NAME", "%os%")
  ```

### glob

glob(field: string, value: string): DataAbilityPredicates

Creates a **DataAbilityPredicates** object to search for the records in the specified column that match the given string. Different from **like**, the input parameters of this API are case-sensitive.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the table.|
| value | string | Yes| Value to match.|

**Return value**

| Type| Description|
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | **DataAbilityPredicates** object created.|

**Example**

  ```js
  dataAbilityPredicates.glob("NAME", "?h*g")

  // Only the records whose value is "Lisa" in the "name" column are matched.
  dataAbilityPredicates.glob("NAME", "Lisa")

  // Only the records whose value is "lisa" in the "name" column are matched.
  dataAbilityPredicates.glob("NAME", "lisa")
  ```

### between

between(field: string, low: ValueType, high: ValueType): DataAbilityPredicates

Creates a **DataAbilityPredicates** object to search for the records in the specified column that are within the given range.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the table.|
| low | [ValueType](#valuetype) | Yes| Minimum value to match.|
| high | [ValueType](#valuetype) | Yes| Maximum value to match.|

**Return value**

| Type| Description|
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | **DataAbilityPredicates** object created.|

**Example**

  ```js
  dataAbilityPredicates.between("AGE", 10, 50)
  ```

### notBetween

notBetween(field: string, low: ValueType, high: ValueType): DataAbilityPredicates

Creates a **DataAbilityPredicates** object to search for the records in the specified column that are out of the given range.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the table.|
| low | [ValueType](#valuetype) | Yes| Minimum value to match.|
| high | [ValueType](#valuetype) | Yes| Maximum value to match.|

**Return value**

| Type| Description|
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | **DataAbilityPredicates** object created.|

**Example**

  ```js
  dataAbilityPredicates.notBetween("AGE", 10, 50)
  ```

### greaterThan

greaterThan(field: string, value: ValueType): DataAbilityPredicates

Creates a **DataAbilityPredicates** object to search for the records in the specified column that are greater than the given value.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the table.|
| value | [ValueType](#valuetype) | Yes| Value to match.|

**Return value**

| Type| Description|
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | **DataAbilityPredicates** object created.|

**Example**

  ```js
  dataAbilityPredicates.greaterThan("AGE", 18)
  ```

### lessThan

lessThan(field: string, value: ValueType): DataAbilityPredicates

Creates a **DataAbilityPredicates** object to search for the records in the specified column that are less than the given value.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the table.|
| value | [ValueType](#valuetype) | Yes| Value to match.|

**Return value**

| Type| Description|
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | **DataAbilityPredicates** object created.|

**Example**

  ```js
  dataAbilityPredicates.lessThan("AGE", 20)
  ```

### greaterThanOrEqualTo

greaterThanOrEqualTo(field: string, value: ValueType): DataAbilityPredicates

Creates a **DataAbilityPredicates** object to search for the records in the specified column that are greater than or equal to the given value.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the table.|
| value | [ValueType](#valuetype) | Yes| Value to match.|

**Return value**

| Type| Description|
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | **DataAbilityPredicates** object created.|

**Example**

  ```js
  dataAbilityPredicates.greaterThanOrEqualTo("AGE", 18)
  ```

### lessThanOrEqualTo

lessThanOrEqualTo(field: string, value: ValueType): DataAbilityPredicates

Creates a **DataAbilityPredicates** object to search for the records in the specified column that are less than or equal to the given value.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the table.|
| value | [ValueType](#valuetype) | Yes| Value to match.|

**Return value**

| Type| Description|
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | **DataAbilityPredicates** object created.|

**Example**

  ```js
  dataAbilityPredicates.lessThanOrEqualTo("AGE", 20)
  ```

### orderByAsc

orderByAsc(field: string): DataAbilityPredicates

Creates a **DataAbilityPredicates** object to sort the records in the specified column in ascending order. When there are multiple **orderByAsc**s, the first **orderByAsc** used has the highest priority.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the table.|

**Return value**

| Type| Description|
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | **DataAbilityPredicates** object created.|

**Example**

  ```js
  // Sort data by name first; for the records with the same name, sort them by age; for the records with the same name and age, sort them by salary in ascending order.
  dataAbilityPredicates.orderByAsc("NAME").orderByAsc("AGE").orderByAsc("SALARY")
  ```

### orderByDesc

orderByDesc(field: string): DataAbilityPredicates

Creates a **DataAbilityPredicates** object to sort the records in the specified column in descending order. When there are multiple **orderByDesc**s, the first **orderByDesc** used has the highest priority.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the table.|

**Return value**

| Type| Description|
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | **DataAbilityPredicates** object created.|

**Example**

  ```js
  // Sort the data by age first. For the data records with the same age, sort them by salary.
  dataAbilityPredicates.orderByDesc("AGE").orderByDesc("SALARY")
  ```

### distinct

distinct(): DataAbilityPredicates

Creates a **DataAbilityPredicates** object to filter out duplicate records.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Return value**

| Type| Description|
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | **DataAbilityPredicates** object created.|

**Example**

  ```js
  dataAbilityPredicates.equalTo("NAME", "Rose").distinct()
  ```

### limitAs

limitAs(value: number): DataAbilityPredicates

Creates a **DataAbilityPredicates** object to limit the number of records.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | number | Yes| Maximum number of records. The value should be a positive integer. If a value less than or equal to **0** is specified, the number of records is not limited.|

**Return value**

| Type| Description|
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | **DataAbilityPredicates** object created.|

**Example**

  ```js
  dataAbilityPredicates.equalTo("NAME", "Rose").limitAs(3)
  ```

### offsetAs

offsetAs(rowOffset: number): DataAbilityPredicates

Creates a **DataAbilityPredicates** object to set the start position of the query result. This API must be used together with **limitAs**. Otherwise, no result will be returned. To query all rows after the specified offset, pass in **-1** in **limitAs**.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| rowOffset | number | Yes| Start position. The value should be a positive integer. If a value less than or equal to **0** is specified, the query result is returned from the first element.|

**Return value**

| Type| Description|
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | **DataAbilityPredicates** object created.|

**Example**

  ```js
  // Display the three data records following the first three records.
  dataAbilityPredicates.equalTo("NAME", "Rose").offsetAs(3).limitAs(3)
  ```


### groupBy

groupBy(fields: Array&lt;string&gt;): DataAbilityPredicates

Creates a **DataAbilityPredicates** object to group the query results based on the specified columns.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| fields | Array&lt;string&gt; | Yes| Names of columns to group.|

**Return value**

| Type| Description|
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | **DataAbilityPredicates** object created.|

**Example**

  ```js
  dataAbilityPredicates.groupBy(["AGE", "NAME"])
  ```

### indexedBy

indexedBy(field: string): DataAbilityPredicates

Creates a **DataAbilityPredicates** object to specify the index column. Before calling this API, you need to create an index column.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Name of the index.|

**Return value**

| Type| Description|
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | **DataAbilityPredicates** object created.|

**Example**

```js
import { UIAbility } from '@kit.AbilityKit';
import { dataAbility, relationalStore } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  async onCreate(): Promise<void> {
    let store: relationalStore.RdbStore | undefined = undefined;
    let context = this.context;

    try {
      const STORE_CONFIG: relationalStore.StoreConfig = {
        name: 'RdbTest.db', // Database file name.
        securityLevel: relationalStore.SecurityLevel.S3,
      };
      // Table structure: EMPLOYEE (NAME, AGE, SALARY, CODES)
      const SQL_CREATE_TABLE =
        'CREATE TABLE IF NOT EXISTS EMPLOYEE (ID INTEGER PRIMARY KEY AUTOINCREMENT, NAME TEXT NOT NULL, AGE INTEGER, SALARY REAL, CODES BLOB)'; // SQL statement for creating a data table.
      store = await relationalStore.getRdbStore(context, STORE_CONFIG);
      console.info('Succeeded in getting RdbStore.');
      await store.executeSql(SQL_CREATE_TABLE); // Create a data table.
    } catch (e) {
      const err = e as BusinessError;
      console.error(`Failed to get RdbStore. Code:${err.code}, message:${err.message}`);
    }

    if (!store) {
      return;
    }

    // Create an index.
    const SQL_CREATE_INDEX = 'CREATE INDEX SALARY_INDEX ON EMPLOYEE(SALARY)'
    await store.executeSql(SQL_CREATE_INDEX);
    // ...

    let dataAbilityPredicates = new dataAbility.DataAbilityPredicates()
    dataAbilityPredicates.indexedBy("SALARY_INDEX")

    //  ...
  }
}
```

### in

in(field: string, value: Array&lt;ValueType&gt;): DataAbilityPredicates

Creates a **DataAbilityPredicates** object to search for the records in the specified column that are in the given range.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the table.|
| value | Array&lt;[ValueType](#valuetype)&gt; | Yes| Array of **ValueType**s to match.|


**Return value**

| Type| Description|
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | **DataAbilityPredicates** object created.|

**Example**

  ```js
  dataAbilityPredicates.in("AGE", [18, 20])
  ```

### notIn

notIn(field: string, value: Array&lt;ValueType&gt;): DataAbilityPredicates

Creates a **DataAbilityPredicates** object to search for the records in the specified column that are out of the given range.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the table.|
| value | Array&lt;[ValueType](#valuetype)&gt; | Yes| Array of **ValueType**s to match.|

**Return value**

| Type| Description|
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | **DataAbilityPredicates** object created.|

**Example**

  ```js
  dataAbilityPredicates.notIn("NAME", ["Lisa", "Rose"])
  ```

## ValueType

type ValueType = number | string | boolean

Defines the value types.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

| Type   | Description                |
| ------- | -------------------- |
| number  | The value is a number.  |
| string  | The value is a string.  |
| boolean | The value is of Boolean type.|
