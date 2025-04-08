# @ohos.data.dataSharePredicates (DataShare Predicates)

**DataSharePredicates** provides a filter object to query data in a database by using **DataShare** APIs. It is often used to update, delete, and query data.

The APIs provided by **DataSharePredicates** correspond to the filter criteria of the database. Before using the APIs, you need to have basic database knowledge.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs of this module can be used only in the stage model.



## Modules to Import

```ts
import { dataSharePredicates } from '@kit.ArkData';
```

## DataSharePredicates
Provides APIs for setting different **DataSharePredicates** objects. This type is not multi-thread safe. If a **DataSharePredicates** instance is operated by multiple threads at the same time in an application, use a lock for it.

### equalTo<sup>10+</sup>

equalTo(field: string, value: ValueType): DataSharePredicates

Creates a **DataSharePredicates** object to search for the records in the specified column that are equal to the given value.

Currently, only the relational database (RDB) and key-value database (KVDB, schema) support this **DataSharePredicates** object.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type                                               | Mandatory| Description                  |
| ------ | --------------------------------------------------- | ---- | ---------------------- |
| field  | string                                              | Yes  | Column name in the database table.    |
| value  | [ValueType](js-apis-data-valuesBucket.md#valuetype) | Yes  | Value to match.|

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object created.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.equalTo("NAME", "Rose")
```


### and<sup>10+</sup>

and(): DataSharePredicates

Creates a **DataSharePredicates** object to add the AND condition.

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

### orderByAsc<sup>10+</sup>

orderByAsc(field: string): DataSharePredicates

Creates a **DataSharePredicates** object that sorts records in ascending order.

Currently, only the RDB and KVDB (schema) support this **DataSharePredicates** object.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| field  | string | Yes  | Column name in the database table.|

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object created.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.orderByAsc("AGE")
```

### orderByDesc<sup>10+</sup>

orderByDesc(field: string): DataSharePredicates

Creates a **DataSharePredicates** object that sorts data in descending order.

Currently, only the RDB and KVDB (schema) support this **DataSharePredicates** object.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| field  | string | Yes  | Column name in the database table.|

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object created.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.orderByDesc("AGE")
```

### limit<sup>10+</sup>

limit(total: number, offset: number): DataSharePredicates

Creates a **DataSharePredicates** object to specify the number of records in the result and the start position.

Currently, only the RDB and KVDB (schema) support this **DataSharePredicates** object.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name  | Type  | Mandatory| Description          |
| -------- | ------ | ---- | -------------- |
| total    | number | Yes  | Number of records. The value should be a positive integer. If a value less than or equal to **0** is specified, the number of records is not limited.  |
| offset | number | Yes  | Start position. The value should be a positive integer. If a value less than or equal to **0** is specified, the query result is returned from the first element.|

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object created.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.equalTo("NAME", "Rose").limit(10, 3)
```

### in<sup>10+</sup>

in(field: string, value: Array&lt;ValueType&gt;): DataSharePredicates

Creates a **DataSharePredicates** object to search for the records in the specified column that are within the specified range.

Currently, only the RDB and KVDB (schema) support this **DataSharePredicates** object.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name | Type            | Mandatory| Description                                   |
| ------- | ---------------- | ---- | --------------------------------------- |
| field   | string           | Yes| Column name in the database table.                     |
| value | Array&lt;[ValueType](js-apis-data-valuesBucket.md#valuetype)&gt; | Yes  | Array of the values to match.|

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object created.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.in("AGE", [18, 20])
```
