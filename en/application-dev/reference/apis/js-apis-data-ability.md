# DataAbilityPredicates

**DataAbility** provides APIs for creating predicates, which implement different query methods for relational database (RDB) stores.

> **NOTE**<br/>
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```js
import dataAbility from '@ohos.data.dataAbility';
```

## dataAbility.createRdbPredicates

createRdbPredicates(name: string, dataAbilityPredicates: DataAbilityPredicates): rdb.RdbPredicates

Creates an **RdbPredicates** object from a **DataAbilityPredicates** object.

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
  let predicates = dataAbility.createRdbPredicates("EMPLOYEE", dataAbilityPredicates)
  ```

## DataAbilityPredicates

Provides predicates for implementing diverse query methods.

### equalTo

equalTo(field: string, value: ValueType): DataAbilityPredicates

Sets a **DataAbilityPredicates** object to match the field with data type **ValueType** and value equal to the specified value.

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

Adds a left parenthesis to this **DataAbilityPredicates**.

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

Adds a right parenthesis to this **DataAbilityPredicates**.

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

Sets a **DataAbilityPredicates** object to match the specified string.

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

Sets a **DataAbilityPredicates** object to match the column with values sorted in ascending order.

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
  dataAbilityPredicates.orderByAsc("NAME")
  ```

### orderByDesc

orderByDesc(field: string): DataAbilityPredicates

Sets a **DataAbilityPredicates** object to match the column with values sorted in descending order.

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
  dataAbilityPredicates.orderByDesc("AGE")
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

Sets a **DataAbilityPredicates** object to specify the start position of the returned result.

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
  dataAbilityPredicates.equalTo("NAME", "Rose").offsetAs(3)
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

Sets a **DataAbilityPredicates** object to specify the index column.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | indexName | string | Yes| Name of the index column.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | [DataAbilityPredicates](#dataabilitypredicates) | **DataAbilityPredicates** object that specifies the index column.|

**Example**

  ```js
  dataAbilityPredicates.indexedBy("SALARY_INDEX")
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

Enumerates the value types.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

| Type   | Description                |
| ------- | -------------------- |
| number  | The value is a number.  |
| string  | The value is a string.  |
| boolean | The value is of Boolean type.|
