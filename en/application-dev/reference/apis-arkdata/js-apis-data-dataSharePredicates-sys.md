# @ohos.data.dataSharePredicates (DataShare Predicates) (System API)

You can use **DataSharePredicates** to specify conditions for [updating](js-apis-data-dataShare-sys.md#update), [deleting](js-apis-data-dataShare-sys.md#delete), and [querying](js-apis-data-dataShare-sys.md#query) data when **DataShare** is used to manage data.

The APIs provided by **DataSharePredicates** correspond to the filter criteria of the database. Before using the APIs, you need to have basic database knowledge.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs of this module can be used only in the stage model.
>
> - This topic describes only the system APIs provided by the module. For details about its public APIs, see [@ohos.data.dataSharePredicates (Data Share Predicates)](js-apis-data-dataSharePredicates.md).



## Modules to Import

```ts
import { dataSharePredicates } from '@kit.ArkData';
```

## DataSharePredicates
Provides methods for setting different **DataSharePredicates** objects. This type is not multi-thread safe. If a **DataSharePredicates** instance is operated by multiple threads at the same time in an application, use a lock for the instance.

### notEqualTo

notEqualTo(field: string, value: ValueType): DataSharePredicates

Sets a **DataSharePredicates** object to match the data that is not equal to the specified value.

Currently, only the RDB and KVDB (schema) support this **DataSharePredicates** object.

**System API**: This is a system API.

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
predicates.notEqualTo("NAME", "Rose")
```

### beginWrap

beginWrap(): DataSharePredicates

Adds a left parenthesis to this **DataSharePredicates**. This API is similar to "(" in an SQL statement and must be used with **endWrap**.

Currently, only the RDB supports this **DataSharePredicates** object.

**System API**: This is a system API.

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

### endWrap

endWrap(): DataSharePredicates

Adds a right parenthesis to this **DataSharePredicates** object.

Currently, only the RDB supports this **DataSharePredicates** object.

**System API**: This is a system API.

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

### or

or(): DataSharePredicates

Adds the OR condition to this **DataSharePredicates** object.

Currently, only the RDB and KVDB (schema) support this **DataSharePredicates** object.

**System API**: This is a system API.

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

### contains

contains(field: string, value: string): DataSharePredicates

Sets a **DataSharePredicates** object to match the data that contains the specified value.

Currently, only the RDB supports this **DataSharePredicates** object.

**System API**: This is a system API.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type  | Mandatory| Description                |
| ------ | ------ | ---- | -------------------- |
| field  | string | Yes  | Column name in the database table.  |
| value  | string | Yes  | Value to match.|

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object created.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.contains("NAME", "os")
```

### beginsWith

beginsWith(field: string, value: string): DataSharePredicates

Sets a **DataSharePredicates** object to match the data that begins with the specified value.

Currently, only the RDB supports this **DataSharePredicates** object.

**System API**: This is a system API.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | ---------------------- |
| field  | string | Yes  | Column name in the database table.    |
| value  | string | Yes  | Start value to match.|

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object created.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.beginsWith("NAME", "os")
```

### endsWith

endsWith(field: string, value: string): DataSharePredicates

Sets a **DataSharePredicates** object to match the data that ends with the specified value.

Currently, only the RDB supports this **DataSharePredicates** object.

**System API**: This is a system API.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | ---------------------- |
| field  | string | Yes  | Column name in the database table.    |
| value  | string | Yes  | End value to match.|

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object created.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.endsWith("NAME", "os")
```

### isNull

isNull(field: string): DataSharePredicates

Sets a **DataSharePredicates** object to match the data whose value is null.

Currently, only the RDB and KVDB (schema) support this **DataSharePredicates** object.

**System API**: This is a system API.

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
predicates.isNull("NAME")
```

### isNotNull

isNotNull(field: string): DataSharePredicates

Sets a **DataSharePredicates** object to match the data whose value is not null.

Currently, only the RDB and KVDB (schema) support this **DataSharePredicates** object.

**System API**: This is a system API.

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
predicates.isNotNull("NAME")
```

### like

like(field: string, value: string): DataSharePredicates

Sets a **DataSharePredicates** object to match the data that matches the specified wildcard expression.

Currently, only the RDB and KVDB (schema) support this **DataSharePredicates** object.

**System API**: This is a system API.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | ---------------------- |
| field  | string | Yes  | Column name in the database table.    |
| value  | string | Yes  | Wildcard expression to match.<br>In the expression, '%' represents zero, one, or more digits or characters, and '_' represents a single digit or character. It is case insensitive.|

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object created.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.like("NAME", "%os%")
```

### unlike

unlike(field: string, value: string): DataSharePredicates

Sets a **DataSharePredicates** object to match the data that does not match the specified wildcard expression.

Currently, only the RDB and KVDB (schema) support this **DataSharePredicates** object.

**System API**: This is a system API.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | ---------------------- |
| field  | string | Yes  | Column name in the database table.    |
| value  | string | Yes  | Wildcard expression to match.<br>In the expression, '%' represents zero, one, or more digits or characters, and '_' represents a single digit or character. It is case insensitive.|

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object created.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.unlike("NAME", "%os%")
```

### glob

glob(field: string, value: string): DataSharePredicates

Sets a **DataSharePredicates** object to match the data that matches the specified wildcard expression.

Currently, only the RDB supports this **DataSharePredicates** object.

**System API**: This is a system API.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | ---------------------- |
| field  | string | Yes  | Column name in the database table.    |
| value  | string | Yes  | Wildcard expression to match.<br>In the expression, '*' represents zero, one, or more digits or characters, and '?' represents a single digit or character. It is case sensitive.|

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object created.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.glob("NAME", "?h*g")
```

### between

between(field: string, low: ValueType, high: ValueType): DataSharePredicates

Sets a **DataSharePredicates** object to match the data that is within the specified range, including the start and end values. The data type must be int.

Currently, only the RDB supports this **DataSharePredicates** object.

**System API**: This is a system API.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type                                               | Mandatory| Description                    |
| ------ | --------------------------------------------------- | ---- | ------------------------ |
| field  | string                                              | Yes  | Column name in the database table.      |
| low    | [ValueType](js-apis-data-valuesBucket.md#valuetype) | Yes  | The lowest value of the range.|
| high   | [ValueType](js-apis-data-valuesBucket.md#valuetype) | Yes  | The highest value of the range.|

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object created.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.between("AGE", 10, 50)
```

### notBetween

notBetween(field: string, low: ValueType, high: ValueType): DataSharePredicates

Sets a **DataSharePredicates** object to match the data that is out of the specified range, excluding the start and end values. The data type must be int.

Currently, only the RDB supports this **DataSharePredicates** object.

**System API**: This is a system API.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type                                               | Mandatory| Description                    |
| ------ | --------------------------------------------------- | ---- | ------------------------ |
| field  | string                                              | Yes  | Column name in the database table.      |
| low    | [ValueType](js-apis-data-valuesBucket.md#valuetype) | Yes  | The lowest value of the range.|
| high   | [ValueType](js-apis-data-valuesBucket.md#valuetype) | Yes  | The highest value of the range.|

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object created.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.notBetween("AGE", 10, 50)
```

### greaterThan

greaterThan(field: string, value: ValueType): DataSharePredicates

Sets a **DataSharePredicates** object to match the data that is greater than the specified value.

Currently, only the RDB and KVDB (schema) support this **DataSharePredicates** object.

**System API**: This is a system API.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name | Type     | Mandatory| Description                  |
| ------- | --------- | ---- | ---------------------- |
| field   | string    | Yes  | Column name in the database table.    |
| value | [ValueType](js-apis-data-valuesBucket.md#valuetype) | Yes  | Value to match.|

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object created.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.greaterThan("AGE", 10)
```

### lessThan

lessThan(field: string, value: ValueType): DataSharePredicates

Sets a **DataSharePredicates** object to match the data that is less than the specified value.

Currently, only the RDB and KVDB (schema) support this **DataSharePredicates** object.

**System API**: This is a system API.

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
predicates.lessThan("AGE", 50)
```

### greaterThanOrEqualTo

greaterThanOrEqualTo(field: string, value: ValueType): DataSharePredicates

Sets a **DataSharePredicates** object to match the data that is greater than or equal to the specified value.

Currently, only the RDB and KVDB (schema) support this **DataSharePredicates** object.

**System API**: This is a system API.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name | Type     | Mandatory| Description                  |
| ------- | --------- | ---- | ---------------------- |
| field   | string    | Yes  | Column name in the database table.    |
| value | [ValueType](js-apis-data-valuesBucket.md#valuetype) | Yes  | Value to match.|

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object created.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.greaterThanOrEqualTo("AGE", 10)
```

### lessThanOrEqualTo

lessThanOrEqualTo(field: string, value: ValueType): DataSharePredicates

Sets a **DataSharePredicates** object to match the data that is less than or equal to the specified value.

Currently, only the RDB and KVDB (schema) support this **DataSharePredicates** object.

**System API**: This is a system API.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name | Type     | Mandatory| Description                  |
| ------- | --------- | ---- | ---------------------- |
| field   | string    | Yes  | Column name in the database table.    |
| value | [ValueType](js-apis-data-valuesBucket.md#valuetype) | Yes  | Value to match.|

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object created.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.lessThanOrEqualTo("AGE", 50)
```

### distinct

distinct(): DataSharePredicates

Sets a **DataSharePredicates** object to filter out duplicate data records.

Currently, only the RDB supports this **DataSharePredicates** object.

**System API**: This is a system API.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object created.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.equalTo("NAME", "Rose").distinct()
```

### groupBy

groupBy(fields: Array&lt;string&gt;): DataSharePredicates

Sets a **DataSharePredicates** object group the records according to the specified fields.

Currently, only the RDB supports this **DataSharePredicates** object.

**System API**: This is a system API.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type         | Mandatory| Description                |
| ------ | ------------- | ---- | -------------------- |
| fields | Array&lt;string&gt; | Yes  | Names of the columns by which the records are grouped.|

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object created.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.groupBy(["AGE", "NAME"])
```

### indexedBy

indexedBy(field: string): DataSharePredicates

Sets a **DataSharePredicates** object to list data by the specified index. Before using this API, ensure that the index column exists.

Currently, only the RDB supports this **DataSharePredicates** object.

**System API**: This is a system API.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type  | Mandatory| Description          |
| ------ | ------ | ---- | -------------- |
| field  | string | Yes  | Name of the index column.|

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object created.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.indexedBy("SALARY_INDEX")
```

### notIn

notIn(field: string, value: Array&lt;ValueType&gt;): DataSharePredicates

Sets a **DataSharePredicates** object to match the data that is not in the specified value.

Currently, only the RDB and KVDB (schema) support this **DataSharePredicates** object.

**System API**: This is a system API.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name | Type            | Mandatory| Description                                   |
| ------- | ---------------- | ---- | --------------------------------------- |
| field   | string           | Yes  | Column name in the database table.                     |
| value | Array&lt;[ValueType](js-apis-data-valuesBucket.md#valuetype)&gt; | Yes  | Array of the values to match.|

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object created.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.notIn("NAME", ["Lisa", "Rose"])
```

### prefixKey

prefixKey(prefix: string): DataSharePredicates

Sets a **DataSharePredicates** object to match the data with the specified key prefix.

Currently, only the KVDB supports this **DataSharePredicates** object.

**System API**: This is a system API.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type  | Mandatory| Description          |
| ------ | ------ | ---- | -------------- |
| prefix | string | Yes  | Key prefix to match.|

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object created.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.prefixKey("NAME")
```

### inKeys

inKeys(keys: Array&lt;string&gt;): DataSharePredicates

Sets a **DataSharePredicates** object to match the data whose keys are within the given range.

Currently, only the KVDB supports this **DataSharePredicates** object.

**System API**: This is a system API.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| Name| Type         | Mandatory| Description              |
| ------ | ------------- | ---- | ------------------ |
| keys | Array&lt;string&gt; | Yes  | Array of the keys to match.|

**Return value**

| Type                                       | Description                      |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | **DataSharePredicates** object created.|

**Example**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.inKeys(["Lisa", "Rose"])
```
