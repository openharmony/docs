# @ohos.data.dataSharePredicates (DataShare Predicates)

<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @woodenarow-->
<!--Designer: @woodenarow; @xuelei3-->
<!--Tester: @chenwan188; @logic42-->
<!--Adviser: @ge-yafang-->
<!-- md-trans-meta sourceCommit=e5066c2f55fbac2949890593f85e3dd2d951dc38 translatedAt=2026-08-14T08:54:55.943Z pushedAt=2026-08-15T03:12:59.301Z -->

**DataSharePredicates** provides a filter object to query data in a database by using **DataShare** APIs. It is often used to update, delete, and query data.

The APIs provided by **DataSharePredicates** correspond to the filter criteria of the database. Before using the APIs, you need to have basic database knowledge.

**DataSharePredicates** applies to the following scenario:

- It is used as a search criterion in the media file management service. For details, see [FetchOptions](../apis-media-library-kit/arkts-apis-photoAccessHelper-i.md#fetchoptions) in the fetch options of the album management. In this scenario, you do not need to pay attention to the database type.

<!--Del-->

- It is used as the search criteria when APIs of the [RDB store](js-apis-data-relationalStore-sys.md) and [distributed KV store](js-apis-distributedKVStore-sys.md) are called. In this scenario, use the corresponding predicate based on the database type.

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

**System capability:** SystemCapability.DistributedDataManager.DataShare.Core

### equalTo

equalTo(field: string, value: ValueType): DataSharePredicates

Creates a **DataSharePredicates** object to search for the records in the specified column that are equal to the given value.

Currently, both the RDB store and KV store support this predicate.

**System capability:** SystemCapability.DistributedDataManager.DataShare.Core

**Atomic service API**: This API can be used in atomic services since API version 20.

**Parameters**

| Name| Type                                               | Mandatory| Description                  |
| ------ | --------------------------------------------------- | ---- | ---------------------- |
| field  | string                                              | Yes   | Column name in the database table.</br>If **field** is **undefined** or **null**, the predicate configured by this API call is invalid.     |
| value  | [ValueType](js-apis-data-valuesBucket.md#valuetype) | Yes   | Value to match against the predicate.</br>If **value** is **undefined** or **null**, the predicate configured by this API call is invalid.  |

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object created.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates();
predicates.equalTo("NAME", "Rose");
```

### and

and(): DataSharePredicates

Creates a **DataSharePredicates** object to add the AND condition.

Currently, both the RDB store and KV store support this predicate.

**System capability:** SystemCapability.DistributedDataManager.DataShare.Core

**Atomic service API**: This API can be used in atomic services since API version 20.

**Return value**

| Type                                       | Description                  |
| ------------------------------------------- | ---------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object with the AND operator.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates();
predicates.equalTo("NAME", "lisi")
    .and()
    .equalTo("SALARY", 200.5);
```

### orderByAsc

orderByAsc(field: string): DataSharePredicates

Creates a **DataSharePredicates** object that sorts records in ascending order.

Currently, both the RDB store and KV store support this predicate.

**System capability:** SystemCapability.DistributedDataManager.DataShare.Core

**Atomic service API**: This API can be used in atomic services since API version 20.

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| field  | string | Yes  | Column name in the database table. </br>If **field** is **undefined** or **null**, the predicate configured by this API call is invalid. |

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object created.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates();
predicates.orderByAsc("AGE");
```

### orderByDesc

orderByDesc(field: string): DataSharePredicates

Creates a **DataSharePredicates** object that sorts data in descending order.

Currently, both the RDB store and KV store support this predicate.

**System capability:** SystemCapability.DistributedDataManager.DataShare.Core

**Atomic service API**: This API can be used in atomic services since API version 20.

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| field  | string  | Yes   | Column name in the database table.</br>If **field** is **undefined** or **null**, the predicate configured by this API call is invalid.  |

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object created.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates();
predicates.orderByDesc("AGE");
```

### limit

limit(total: number, offset: number): DataSharePredicates

Creates a **DataSharePredicates** object to specify the number of records in the result and the start position.

Currently, both the RDB store and KV store support this predicate.

**System capability:** SystemCapability.DistributedDataManager.DataShare.Core

**Atomic service API**: This API can be used in atomic services since API version 20.

**Parameters**

| Name  | Type  | Mandatory| Description          |
| -------- | ------ | ---- | -------------- |
| total    | number | Yes  | Maximum number of records.<br>If the KV store is used and **total** is **undefined** or **null**, the maximum number of records is 0. For details about the value range, see the description of this parameter in [limit](./js-apis-distributedKVStore.md#limit).<br>If the RDB store is used and **total** is **undefined** or **null**, the maximum number of records is not limited. For details about the value range, see the description of this parameter in [limitAs](arkts-apis-data-relationalStore-RdbPredicates.md#limitas).|
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

### in

in(field: string, value: Array&lt;ValueType&gt;): DataSharePredicates

Creates a **DataSharePredicates** object to match the data that is within the specified range.

Currently, both the RDB store and KV store support this predicate.

**System capability:** SystemCapability.DistributedDataManager.DataShare.Core

**Atomic service API**: This API can be used in atomic services since API version 20.

**Parameters**

| Name | Type            | Mandatory| Description                                   |
| ------- | ---------------- | ---- | --------------------------------------- |
| field   | string           | Yes | Column name in the database table.</br>If **field** is **undefined** or **null**, the predicate configured by this API call is invalid.</br>When **field** is the string **'null'** or **'undefined'**, the key-value database and relational database APIs may return unexpected matching results or throw an exception when using this predicate.                   |
| value | Array<[ValueType](js-apis-data-valuesBucket.md#valuetype)> | Yes   | Value to match, specified as an array of **ValueType**.</br>If **value** is **undefined** or **null**, the predicate configured by this API call is invalid. |

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object created.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates();
predicates.in("AGE", [18, 20]);
```

### notEqualTo<sup>23+</sup>

notEqualTo(field: string, value: ValueType): DataSharePredicates

Creates a **DataSharePredicates** object to match the data that is not equal to the specified value.

Currently, both the RDB store and KV store support this predicate.

**System capability:** SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type                                               | Mandatory| Description                  |
| ------ | --------------------------------------------------- | ---- | ---------------------- |
| field  | string                                              | Yes  | Column name in the database table.<br>If this parameter is set to **undefined** or **null**, the predicate used is invalid.<br>If this parameter is set to **'null'** or **'undefined'** in string, the matching result may not be as expected or an exception may be thrown when the predicate is used by the KV store and RDB store APIs.    |
| value  | [ValueType](js-apis-data-valuesBucket.md#valuetype) | Yes  | Value to match.<br>If this parameter is set to **undefined** or **null**, the predicate used is invalid.|

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object created.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates();
predicates.notEqualTo("NAME", "Rose");
```

### beginWrap<sup>23+</sup>

beginWrap(): DataSharePredicates

Adds a left parenthesis to the predicate, which is equivalent to "(" in an SQL statement and must be used together with the right parenthesis.

Currently, only RDB store supports this predicate.

**System capability:** SystemCapability.DistributedDataManager.DataShare.Core

**Return value**

| Type                                       | Description                  |
| ------------------------------------------- | ---------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object with a left parenthesis.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates();
predicates.equalTo("NAME", "lisi")
    .beginWrap()
    .equalTo("AGE", 18)
    .or()
    .equalTo("SALARY", 200.5)
    .endWrap();
```

### endWrap<sup>23+</sup>

endWrap(): DataSharePredicates

Adds a right parenthesis to the predicate, which is equivalent to ")" in an SQL statement and must be used together with the left parenthesis.

Currently, only RDB store supports this predicate.

**System capability:** SystemCapability.DistributedDataManager.DataShare.Core

**Return value**

| Type                                       | Description                  |
| ------------------------------------------- | ---------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object with a right parenthesis.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates();
predicates.equalTo("NAME", "lisi")
    .beginWrap()
    .equalTo("AGE", 18)
    .or()
    .equalTo("SALARY", 200.5)
    .endWrap();
```

### or<sup>23+</sup>

or(): DataSharePredicates

Creates a **DataSharePredicates** object to add the OR condition.

Currently, both the RDB store and KV store support this predicate.

**System capability:** SystemCapability.DistributedDataManager.DataShare.Core

**Return value**

| Type                                       | Description                  |
| ------------------------------------------- | ---------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object with the OR operator.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.equalTo("NAME", "lisi")
    .or()
    .equalTo("NAME", "Rose");
```

### like<sup>23+</sup>

like(field: string, value: string): DataSharePredicates

Creates a **DataSharePredicates** object to match the data that matches the specified wildcard expression.

Currently, both the RDB store and KV store support this predicate.

**System capability:** SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | ---------------------- |
| field  | string | Yes  | Column name in the database table.<br>If this parameter is set to **undefined** or **null**, the predicate used is invalid.<br>If this parameter is set to **'null'** or **'undefined'** in string, the matching result may not be as expected or an exception may be thrown when the predicate is used by the KV store and RDB store APIs.    |
| value  | string | Yes  | Wildcard expression to match.<br>In the expression, '%' represents zero, one, or more digits or characters, and '_' represents a single digit or character. It is case insensitive.<br>If this parameter is set to **undefined** or **null**, the predicate used is invalid.|

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object created.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates();
predicates.like("NAME", "%os%");
```

### between<sup>23+</sup>

between(field: string, low: ValueType, high: ValueType): DataSharePredicates

Creates a **DataSharePredicates** object to match the data that is within the specified range, including the start and end values.

Currently, only RDB store supports this predicate.

**System capability:** SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type                                               | Mandatory| Description                    |
| ------ | --------------------------------------------------- | ---- | ------------------------ |
| field  | string                                              | Yes  | Column name in the database table.<br>If this parameter is set to **undefined** or **null**, the predicate used is invalid.<br>If this parameter is set to **'null'** or **'undefined'** in string, the matching result may not be as expected or an exception may be thrown when the predicate is used by the KV store and RDB store APIs.|
| low    | [ValueType](js-apis-data-valuesBucket.md#valuetype) | Yes  | Minimum value of the range to set.<br>If **low** is set to a number, the matching range is specified based on the numeric order.<br>If **low** is set to a string, the matching range is specified based on the lexicographical order.<br>If **low** is set to boolean, the matching range is specified based on the numeric order.|
| high   | [ValueType](js-apis-data-valuesBucket.md#valuetype) | Yes  | Maximum value to match the **DataAbilityPredicates**.<br>If **high** is set to a number, the matching range is specified based on the numeric order.<br>If **high** is set to a string, the matching range is specified based on the lexicographical order.<br>If **high** is set to boolean, the matching range is specified based on the numeric order.|

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object created.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates();
predicates.between("AGE", 10, 50);
```

### notBetween<sup>23+</sup>

notBetween(field: string, low: ValueType, high: ValueType): DataSharePredicates

Creates a **DataSharePredicates** object to match the data that is out of the specified range, excluding the start and end values.

Currently, only RDB store supports this predicate.

**System capability:** SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type                                               | Mandatory| Description                    |
| ------ | --------------------------------------------------- | ---- | ------------------------ |
| field  | string                                              | Yes  | Column name in the database table.<br>If this parameter is set to **undefined** or **null**, the predicate used is invalid.<br>If this parameter is set to **'null'** or **'undefined'** in string, the matching result may not be as expected or an exception may be thrown when the predicate is used by the KV store and RDB store APIs.      |
| low    | [ValueType](js-apis-data-valuesBucket.md#valuetype) | Yes  | Minimum value of the range to set.<br>If **low** is set to a number, the matching range is specified based on the numeric order.<br>If **low** is set to a string, the matching range is specified based on the lexicographical order.<br>If **low** is set to boolean, the matching range is specified based on the numeric order.|
| high   | [ValueType](js-apis-data-valuesBucket.md#valuetype) | Yes  | Maximum value to match the **DataAbilityPredicates**.<br>If **high** is set to a number, the matching range is specified based on the numeric order.<br>If **high** is set to a string, the matching range is specified based on the lexicographical order.<br>If **high** is set to boolean, the matching range is specified based on the numeric order.|

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object created.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates();
predicates.notBetween("AGE", 10, 50);
```

### greaterThan<sup>23+</sup>

greaterThan(field: string, value: ValueType): DataSharePredicates

Creates a **DataSharePredicates** object to match the data that is greater than the specified value.

Currently, both the RDB store and KV store support this predicate.

**System capability:** SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name | Type     | Mandatory| Description                  |
| ------- | --------- | ---- | ---------------------- |
| field   | string    | Yes  | Column name in the database table.<br>If this parameter is set to **undefined** or **null**, the predicate used is invalid.<br>If this parameter is set to **'null'** or **'undefined'** in string, the matching result may not be as expected or an exception may be thrown when the predicate is used by the KV store and RDB store APIs.    |
| value | [ValueType](js-apis-data-valuesBucket.md#valuetype) | Yes  | Value to match.<br>If this parameter is set to **undefined** or **null**, the predicate used is invalid.|

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object created.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates();
predicates.greaterThan("AGE", 10);
```

### lessThan<sup>23+</sup>

lessThan(field: string, value: ValueType): DataSharePredicates

Creates a **DataSharePredicates** object to match the data that is less than the specified value.

Currently, both the RDB store and KV store support this predicate.

**System capability:** SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type                                               | Mandatory| Description                  |
| ------ | --------------------------------------------------- | ---- | ---------------------- |
| field  | string                                              | Yes  | Column name in the database table.<br>If field is null or undefined, the predicate configured by calling this API is invalid.<br>If this parameter is set to **'null'** or **'undefined'** in string, the matching result may not be as expected or an exception may be thrown when the predicate is used by the KV store and RDB store APIs.    |
| value  | [ValueType](js-apis-data-valuesBucket.md#valuetype) | Yes  | Value to match.<br>If this parameter is set to **undefined** or **null**, the predicate used is invalid.|

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object created.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates();
predicates.lessThan("AGE", 50);
```

### greaterThanOrEqualTo<sup>23+</sup>

greaterThanOrEqualTo(field: string, value: ValueType): DataSharePredicates

Creates a **DataSharePredicates** object to match the data that is greater than or equal to the specified value.

Currently, both the RDB store and KV store support this predicate.

**System capability:** SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name | Type     | Mandatory| Description                  |
| ------- | --------- | ---- | ---------------------- |
| field   | string    | Yes  | Column name in the database table.<br>If this parameter is set to **undefined** or **null**, the predicate used is invalid.<br>If this parameter is set to **'null'** or **'undefined'** in string, the matching result may not be as expected or an exception may be thrown.    |
| value | [ValueType](js-apis-data-valuesBucket.md#valuetype) | Yes  | Value to match.<br>If this parameter is set to **undefined** or **null**, the predicate used is invalid.|

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object created.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates();
predicates.greaterThanOrEqualTo("AGE", 10);
```

### lessThanOrEqualTo<sup>23+</sup>

lessThanOrEqualTo(field: string, value: ValueType): DataSharePredicates

Creates a **DataSharePredicates** object to match the data that is less than or equal to the specified value.

Currently, both the RDB store and KV store support this predicate.

**System capability:** SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name | Type     | Mandatory| Description                  |
| ------- | --------- | ---- | ---------------------- |
| field   | string    | Yes  | Column name in the database table.<br>If this parameter is set to **undefined** or **null**, the predicate used is invalid.<br>If this parameter is set to **'null'** or **'undefined'** in string, the matching result may not be as expected or an exception may be thrown when the predicate is used by the KV store and RDB store APIs.    |
| value | [ValueType](js-apis-data-valuesBucket.md#valuetype) | Yes  | Value to match.<br>If this parameter is set to **undefined** or **null**, the predicate used is invalid.|

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object created.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates();
predicates.lessThanOrEqualTo("AGE", 50);
```

### notIn<sup>23+</sup>

notIn(field: string, value: Array&lt;ValueType&gt;): DataSharePredicates

Creates a **DataSharePredicates** object to match the data that is not in the specified value.

Currently, both the RDB store and KV store support this predicate.

**System capability:** SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name | Type            | Mandatory| Description                                   |
| ------- | ---------------- | ---- | --------------------------------------- |
| field   | string           | Yes  | Column name in the database table.<br>If this parameter is set to **undefined** or **null**, the predicate used is invalid.<br>If this parameter is set to **'null'** or **'undefined'** in string, the matching result may not be as expected or an exception may be thrown when the predicate is used by the KV store and RDB store APIs.     |
| value | Array&lt;[ValueType](js-apis-data-valuesBucket.md#valuetype)&gt; | Yes  | Array of the values to match.<br>If this parameter is set to **undefined** or **null**, the predicate used is invalid.|

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object created.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates();
predicates.notIn("NAME", ["Lisa", "Rose"]);
```