# Data Share Predicates

You can use **DataSharePredicates** to specify conditions for [updating](js-apis-data-dataShare.md#update), [deleting](js-apis-data-dataShare.md#delete), and [querying](js-apis-data-dataShare.md#query) data with **DataShare**.

>**NOTE**
>
>The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';
```

## equalTo

equalTo(field: string, value: ValueType): DataSharePredicates

Sets a **DataSharePredicates** object to match the field with data type **ValueType** and value equal to the specified value.

Currently, only the relational database (RDB) and key-value database (KVDB, schema) support this **DataSharePredicates** object.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type                                               | Mandatory| Description                  |
| ------ | --------------------------------------------------- | ---- | ---------------------- |
| field  | string                                              | Yes  | Column name in the database table.    |
| value  | [ValueType](js-apis-data-ValuesBucket.md#valuetype) | Yes  | Value to match.|

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object that matches the specified field.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.equalTo("NAME", "Rose")
```

## notEqualTo

notEqualTo(field: string, value: ValueType): DataSharePredicates

Sets a **DataSharePredicates** object to match the field with data type **ValueType** and value not equal to the specified value.

Currently, only the RDB and KVDB (schema) support this **DataSharePredicates** object.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type                                               | Mandatory| Description                  |
| ------ | --------------------------------------------------- | ---- | ---------------------- |
| field  | string                                              | Yes  | Column name in the database table.    |
| value  | [ValueType](js-apis-data-ValuesBucket.md#valuetype) | Yes  | Value to match.|

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object that matches the specified field.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.notEqualTo("NAME", "Rose")
```

## beginWrap

beginWrap(): DataSharePredicates

Adds a left parenthesis to this **DataSharePredicates**. Currently, only the RDB supports this **DataSharePredicates** object.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Return value**

| Type                                       | Description                  |
| ------------------------------------------- | ---------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object with a left parenthesis.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.equalTo("NAME", "lisi")
    .beginWrap()
    .equalTo("AGE", 18)
    .or()
    .equalTo("SALARY", 200.5)
    .endWrap()
```

## endWrap

endWrap(): DataSharePredicates

Adds a right parenthesis to this **DataSharePredicates** object. Currently, only the RDB supports this **DataSharePredicates** object.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Return value**

| Type                                       | Description                  |
| ------------------------------------------- | ---------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object with a right parenthesis.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.equalTo("NAME", "lisi")
    .beginWrap()
    .equalTo("AGE", 18)
    .or()
    .equalTo("SALARY", 200.5)
    .endWrap()
```

## or

or(): DataSharePredicates

Adds the OR condition to this **DataSharePredicates** object.

Currently, only the RDB and KVDB (schema) support this **DataSharePredicates** object.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Return value**

| Type                                       | Description                  |
| ------------------------------------------- | ---------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object with the OR condition.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.equalTo("NAME", "lisi")
    .or()
    .equalTo("NAME", "Rose")
```

## and

and(): DataSharePredicates

Adds the AND condition to this **DataSharePredicates** object.

Currently, only the RDB and KVDB (schema) support this **DataSharePredicates** object.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Return value**

| Type                                       | Description                  |
| ------------------------------------------- | ---------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object with the AND condition.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.equalTo("NAME", "lisi")
    .and()
    .equalTo("SALARY", 200.5)
```

## contains

contains(field: string, value: string): DataSharePredicates

Sets a **DataSharePredicates** object to match the string that contains the specified value. Currently, only the RDB supports this **DataSharePredicates** object.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type  | Mandatory| Description                |
| ------ | ------ | ---- | -------------------- |
| field  | string | Yes  | Column name in the database table.  |
| value  | string | Yes  | Value contained in the string.|

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object that matches the specified field.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.contains("NAME", "os")
```

## beginsWith

beginsWith(field: string, value: string): DataSharePredicates

Sets a **DataSharePredicates** object to match a string that starts with the specified value. Currently, only the RDB supports this **DataSharePredicates** object.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | ---------------------- |
| field  | string | Yes  | Column name in the database table.    |
| value  | string | Yes  | Start value of the string.|

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object that matches the specified field.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.beginsWith("NAME", "os")
```

## endsWith

endsWith(field: string, value: string): DataSharePredicates

Sets a **DataSharePredicates** object to match a string that ends with the specified value. Currently, only the RDB supports this **DataSharePredicates** object.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | ---------------------- |
| field  | string | Yes  | Column name in the database table.    |
| value  | string | Yes  | End value of the string.|

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object that matches the specified field.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.endsWith("NAME", "os")
```

## isNull

isNull(field: string): DataSharePredicates

Sets a **DataSharePredicates** object to match the field whose value is null.

Currently, only the RDB and KVDB (schema) support this **DataSharePredicates** object.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| field  | string | Yes  | Column name in the database table.|

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object that matches the specified field.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.isNull("NAME")
```

## isNotNull

isNotNull(field: string): DataSharePredicates

Sets a **DataSharePredicates** object to match the field whose value is not null.

Currently, only the RDB and KVDB (schema) support this **DataSharePredicates** object.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| field  | string | Yes  | Column name in the database table.|

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object that matches the specified field.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.isNotNull("NAME")
```

## like

like(field: string, value: string): DataSharePredicates

Sets a **DataSharePredicates** object to match a string that is similar to the specified value.

Currently, only the RDB and KVDB (schema) support this **DataSharePredicates** object.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | ---------------------- |
| field  | string | Yes  | Column name in the database table.    |
| value  | string | Yes  | Value to match.|

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object that matches the specified field.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.like("NAME", "%os%")
```

## unlike

unlike(field: string, value: string): DataSharePredicates

Sets a **DataSharePredicates** object to match a string that is not similar to the specified value.

Currently, only the RDB and KVDB (schema) support this **DataSharePredicates** object.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | ---------------------- |
| field  | string | Yes  | Column name in the database table.    |
| value  | string | Yes  | Value to match.|

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object that matches the specified field.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.unlike("NAME", "%os%")
```

## glob

glob(field: string, value: string): DataSharePredicates

Sets a **DataSharePredicates** object to match the specified string. Currently, only the RDB supports this **DataSharePredicates** object.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | ---------------------- |
| field  | string | Yes  | Column name in the database table.    |
| value  | string | Yes  | Value to match.|

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object that matches the specified string.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.glob("NAME", "?h*g")
```

## between

between(field: string, low: ValueType, high: ValueType): DataSharePredicates

Sets a **DataSharePredicates** object to match the field with data type **ValueType** and value within the specified range. Currently, only the RDB supports this **DataSharePredicates** object.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type                                               | Mandatory| Description                    |
| ------ | --------------------------------------------------- | ---- | ------------------------ |
| field  | string                                              | Yes  | Column name in the database table.      |
| low    | [ValueType](js-apis-data-ValuesBucket.md#valuetype) | Yes  | The lowest value of the range.|
| high   | [ValueType](js-apis-data-ValuesBucket.md#valuetype) | Yes  | The highest value of the range.|

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object that matches the specified field.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.between("AGE", 10, 50)
```

## notBetween

notBetween(field: string, low: ValueType, high: ValueType): DataSharePredicates

Sets a **DataSharePredicates** object to match the field with data type **ValueType** and value out of the specified range. Currently, only the RDB supports this **DataSharePredicates** object.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type                                               | Mandatory| Description                    |
| ------ | --------------------------------------------------- | ---- | ------------------------ |
| field  | string                                              | Yes  | Column name in the database table.      |
| low    | [ValueType](js-apis-data-ValuesBucket.md#valuetype) | Yes  | The lowest value of the range.|
| high   | [ValueType](js-apis-data-ValuesBucket.md#valuetype) | Yes  | The highest value of the range.|

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object that matches the specified field.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.notBetween("AGE", 10, 50)
```

## greaterThan

greaterThan(field: string, value: ValueType): DataSharePredicates

Sets a **DataSharePredicates** object to match the field with data type **ValueType** and value greater than the specified value.

Currently, only the RDB and KVDB (schema) support this **DataSharePredicates** object.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name | Type     | Mandatory| Description                  |
| ------- | --------- | ---- | ---------------------- |
| field   | string    | Yes  | Column name in the database table.    |
| value | [ValueType](js-apis-data-ValuesBucket.md#valuetype) | Yes  | Value to match.|

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object that matches the specified field.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.greaterThan("AGE", 10)
```

## lessThan

lessThan(field: string, value: ValueType): DataSharePredicates

Sets a **DataSharePredicates** object to match the field with data type **ValueType** and value less than the specified value.

Currently, only the RDB and KVDB (schema) support this **DataSharePredicates** object.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type                                               | Mandatory| Description                  |
| ------ | --------------------------------------------------- | ---- | ---------------------- |
| field  | string                                              | Yes  | Column name in the database table.    |
| value  | [ValueType](js-apis-data-ValuesBucket.md#valuetype) | Yes  | Value to match.|

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object that matches the specified field.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.lessThan("AGE", 50)
```

## greaterThanOrEqualTo

greaterThanOrEqualTo(field: string, value: ValueType): DataSharePredicates

Sets a **DataSharePredicates** object to match the field with data type **ValueType** and value greater than or equal to the specified value.

Currently, only the RDB and KVDB (schema) support this **DataSharePredicates** object.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name | Type     | Mandatory| Description                  |
| ------- | --------- | ---- | ---------------------- |
| field   | string    | Yes  | Column name in the database table.    |
| value | [ValueType](js-apis-data-ValuesBucket.md#valuetype) | Yes  | Value to match.|

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object that matches the specified field.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.greaterThanOrEqualTo("AGE", 10)
```

## lessThanOrEqualTo

lessThanOrEqualTo(field: string, value: ValueType): DataSharePredicates

Sets a **DataSharePredicates** object to match the field with data type **ValueType** and value less than or equal to the specified value.

Currently, only the RDB and KVDB (schema) support this **DataSharePredicates** object.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name | Type     | Mandatory| Description                  |
| ------- | --------- | ---- | ---------------------- |
| field   | string    | Yes  | Column name in the database table.    |
| value | [ValueType](js-apis-data-ValuesBucket.md#valuetype) | Yes  | Value to match.|

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object that matches the specified field.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.lessThanOrEqualTo("AGE", 50)
```

## orderByAsc

orderByAsc(field: string): DataSharePredicates

Sets a **DataSharePredicates** object that sorts the values in a column in ascending order.

Currently, only the RDB and KVDB (schema) support this **DataSharePredicates** object.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| field  | string | Yes  | Column name in the database table.|

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object that matches the specified field.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.orderByAsc("AGE")
```

## orderByDesc

orderByDesc(field: string): DataSharePredicates

Sets a **DataSharePredicates** object that sorts the values in a column in descending order.

Currently, only the RDB and KVDB (schema) support this **DataSharePredicates** object.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| field  | string | Yes  | Column name in the database table.|

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object that matches the specified field.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.orderByDesc("AGE")
```

## distinct

distinct(): DataSharePredicates

Sets a **DataSharePredicates** object to filter out duplicate records. Currently, only the RDB supports this **DataSharePredicates** object.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object that matches the specified field.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.equalTo("NAME", "Rose").distinct()
```

## limit

limit(total: number, offset: number): DataSharePredicates

Sets a **DataSharePredicates** object to specify the number of results and the start position.

Currently, only the RDB and KVDB (schema) support this **DataSharePredicates** object.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name  | Type  | Mandatory| Description          |
| -------- | ------ | ---- | -------------- |
| total    | number | Yes  | Number of results.  |
| offset | number | Yes  | Start position.|

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object that matches the specified field.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.equalTo("NAME", "Rose").limit(10, 3)
```

## groupBy

groupBy(fields: Array&lt;string&gt;): DataSharePredicates

Sets a **DataSharePredicates** object to group the records according to the specified parameters. Currently, only the RDB supports this **DataSharePredicates** object.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type         | Mandatory| Description                |
| ------ | ------------- | ---- | -------------------- |
| fields | Array&lt;string&gt; | Yes  | Names of the columns to group.|

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object that matches the specified field.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.groupBy(["AGE", "NAME"])
```

## indexedBy

indexedBy(field: string): DataSharePredicates

Sets a **DataSharePredicates** object to specify the index column. Currently, only the RDB supports this **DataSharePredicates** object.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type  | Mandatory| Description          |
| ------ | ------ | ---- | -------------- |
| field  | string | Yes  | Name of the index column.|

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object that matches the specified field.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.indexedBy("SALARY_INDEX")
```

## in

in(field: string, value: Array&lt;ValueType&gt;): DataSharePredicates

Sets a **DataSharePredicates** object to match the field with data type **Array<ValueType>** and value within the specified range.

Currently, only the RDB and KVDB (schema) support this **DataSharePredicates** object.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name | Type            | Mandatory| Description                                   |
| ------- | ---------------- | ---- | --------------------------------------- |
| field   | string           | Yes| Column name in the database table.                     |
| value | Array&lt;[ValueType](js-apis-data-ValuesBucket.md#valuetype)&gt; | Yes  | Array of **ValueType**s to match.|

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object that matches the specified field.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.in("AGE", [18, 20])
```

## notIn

notIn(field: string, value: Array&lt;ValueType&gt;): DataSharePredicates

Sets a **DataSharePredicates** object to match the field with data type **Array<ValueType>** and value out of the specified range.

Currently, only the RDB and KVDB (schema) support this **DataSharePredicates** object.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name | Type            | Mandatory| Description                                   |
| ------- | ---------------- | ---- | --------------------------------------- |
| field   | string           | Yes  | Column name in the database table.                     |
| value | Array&lt;[ValueType](js-apis-data-ValuesBucket.md#valuetype)&gt; | Yes  | Array of **ValueType**s to match.|

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object that matches the specified field.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.notIn("NAME", ["Lisa", "Rose"])
```

## prefixKey

prefixKey(prefix: string): DataSharePredicates

Sets a **DataSharePredicates** object to match a field with the specified key prefix. Currently, only the KVDB supports this **DataSharePredicates** object.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type  | Mandatory| Description          |
| ------ | ------ | ---- | -------------- |
| prefix | string | Yes  | Key prefix to match.|

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object that matches the specified field.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.prefixKey("NAME")
```

## inKeys

inKeys(keys: Array&lt;string&gt;): DataSharePredicates

Sets a **DataSharePredicates** object to match the fields whose keys are within the given range. Currently, only the KVDB supports this **DataSharePredicates** object.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type         | Mandatory| Description              |
| ------ | ------------- | ---- | ------------------ |
| inKeys | Array&lt;string&gt; | Yes  | Array of the keys to match.|

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object that matches the specified field.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.inKeys(["Lisa", "Rose"])
```
