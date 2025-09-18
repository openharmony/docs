# @ohos.data.dataSharePredicates (DataShare Predicates)
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @woodenarow-->
<!--Designer: @woodenarow; @xuelei3-->
<!--Tester: @chenwan188; @logic42-->
<!--Adviser: @ge-yafang-->

**DataSharePredicates** provides a filter object to query data in a database by using **DataShare** APIs. It is often used to update, delete, and query data.

The APIs provided by **DataSharePredicates** correspond to the filter criteria of the database. Before using the APIs, you need to have basic database knowledge.

**DataSharePredicates** applies to the following scenario:

- It is used as a search criterion in the media file management service. For details, see [Fetch Options of the Album Management](../apis-media-library-kit/arkts-apis-photoAccessHelper-i.md#fetchoptions). In this scenario, you do not need to pay attention to the database type.

<!--Del-->
- It is used as a search criterion when APIs of the [RDB store](js-apis-data-relationalStore-sys.md) and [KV store](js-apis-distributedKVStore-sys.md) are called. In this scenario, use the corresponding predicate based on the database type.
<!--DelEnd-->

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
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

Currently, both the RDB store and KV store support this predicate.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Atomic service API**: This API can be used in atomic services since API version 20.

**Parameters**

| Name| Type                                               | Mandatory| Description                  |
| ------ | --------------------------------------------------- | ---- | ---------------------- |
| field  | string                                              | Yes  | Column name in the database table.<br>If this parameter is set to **undefined** or **null**, the predicate used is invalid.    |
| value  | [ValueType](js-apis-data-valuesBucket.md#valuetype) | Yes  | Value to match.<br>If this parameter is set to **undefined** or **null**, the predicate used is invalid. |

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object created.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates();
predicates.equalTo("NAME", "Rose");
```


### and<sup>10+</sup>

and(): DataSharePredicates

Creates a **DataSharePredicates** object to add the AND condition.

Currently, both the RDB stote and KV store support this predicate.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Atomic service API**: This API can be used in atomic services since API version 20.

**Return value**

| Type                                       | Description                  |
| ------------------------------------------- | ---------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object with the AND condition.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates();
predicates.equalTo("NAME", "lisi")
    .and()
    .equalTo("SALARY", 200.5);
```

### orderByAsc<sup>10+</sup>

orderByAsc(field: string): DataSharePredicates

Creates a **DataSharePredicates** object that sorts records in ascending order.

Currently, both the RDB stote and KV store support this predicate.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Atomic service API**: This API can be used in atomic services since API version 20.

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| field  | string | Yes  | Column name in the database table.<br>If this parameter is set to **undefined** or **null**, the predicate used is invalid.|

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object created.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates();
predicates.orderByAsc("AGE");
```

### orderByDesc<sup>10+</sup>

orderByDesc(field: string): DataSharePredicates

Creates a **DataSharePredicates** object that sorts data in descending order.

Currently, both the RDB stote and KV store support this predicate.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Atomic service API**: This API can be used in atomic services since API version 20.

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| field  | string | Yes  | Column name in the database table.<br>If this parameter is set to **undefined** or **null**, the predicate used is invalid. |

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object created.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates();
predicates.orderByDesc("AGE");
```

### limit<sup>10+</sup>

limit(total: number, offset: number): DataSharePredicates

Creates a **DataSharePredicates** object to specify the number of records in the result and the start position.

Currently, both the RDB stote and KV store support this predicate.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Atomic service API**: This API can be used in atomic services since API version 20.

**Parameters**

| Name  | Type  | Mandatory| Description          |
| -------- | ------ | ---- | -------------- |
| total    | number | Yes  | Maximum number of records.<br>If the KV store is used and **total** is **undefined** or **null**, the maximum number of records is 0. For details about the value range, see the description of this parameter in [limit](./js-apis-distributedKVStore.md#limit).<br>If the RDB store is used and **total** is **undefined** or **null**, the maximum number of records is not limited. For details about the value range, see the description of this parameter in [limitAs](./js-apis-distributedKVStore.md#limit). |
| offset | number | Yes  | Start position of the query result.<br>If this parameter is set to **undefined** or **null**, the start position is the beginning of the result set.<br>For details about the value range in a KV store, see the description of this parameter in [limit](./js-apis-distributedKVStore.md#limit).<br>For details about the value range in an RDB store, see the description of the **rowOffset** parameter in [offsetAs](arkts-apis-data-relationalStore-RdbPredicates.md#offsetas).|

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object created.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates();
predicates.equalTo("NAME", "Rose").limit(10, 3);
```

### in<sup>10+</sup>

in(field: string, value: Array&lt;ValueType&gt;): DataSharePredicates

Sets a **DataSharePredicates** object to match the data that is within the specified range.

Currently, both the RDB stote and KV store support this predicate.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Atomic service API**: This API can be used in atomic services since API version 20.

**Parameters**

| Name | Type            | Mandatory| Description                                   |
| ------- | ---------------- | ---- | --------------------------------------- |
| field   | string           | Yes| Column name in the database table.<br>If this parameter is set to **undefined** or **null**, the predicate used is invalid.                  |
| value | Array&lt;[ValueType](js-apis-data-valuesBucket.md#valuetype)&gt; | Yes  | Array of the values to match.|

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object created.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates();
predicates.in("AGE", [18, 20]);
```
