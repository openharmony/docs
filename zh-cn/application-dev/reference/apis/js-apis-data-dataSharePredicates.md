# 数据共享谓词

**谓词(DataSharePredicates)** 是用户通过DataShare查询数据库中的数据所使用的筛选条件，经常被应用在更新数据([update](js-apis-data-dataShare.md#update))、删除数据([delete](js-apis-data-dataShare.md#delete))和查询数据([query](js-apis-data-dataShare.md#query))中。

>**说明：** 
>
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';
```

## equalTo

equalTo(field: string, value: ValueType): DataSharePredicates

该接口用于配置谓词以匹配数据类型为ValueType且值等于指定值的字段。

目前仅RDB及KVDB(schema)支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**参数：**

| 参数名 | 类型                                                | 必填 | 说明                   |
| ------ | --------------------------------------------------- | ---- | ---------------------- |
| field  | string                                              | 是   | 数据库表中的列名。     |
| value  | [ValueType](js-apis-data-ValuesBucket.md#valuetype) | 是   | 指示要与谓词匹配的值。 |

**返回值：**

| 类型                                        | 说明                       |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.equalTo("NAME", "Rose")
```

## notEqualTo

notEqualTo(field: string, value: ValueType): DataSharePredicates

该接口用于配置谓词以匹配数据类型为ValueType且值不等于指定值的字段。

目前仅RDB及KVDB(schema)支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**参数：**

| 参数名 | 类型                                                | 必填 | 说明                   |
| ------ | --------------------------------------------------- | ---- | ---------------------- |
| field  | string                                              | 是   | 数据库表中的列名。     |
| value  | [ValueType](js-apis-data-ValuesBucket.md#valuetype) | 是   | 指示要与谓词匹配的值。 |

**返回值：**

| 类型                                        | 说明                       |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.notEqualTo("NAME", "Rose")
```

## beginWrap

beginWrap(): DataSharePredicates

该接口用于向谓词添加左括号。目前仅RDB支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**返回值：**

| 类型                                        | 说明                   |
| ------------------------------------------- | ---------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回带有左括号的谓词。 |

**示例：**

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

该接口用于向谓词添加右括号。目前仅RDB支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**返回值：**

| 类型                                        | 说明                   |
| ------------------------------------------- | ---------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回带有右括号的谓词。 |

**示例：**

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

该接口用于将或条件添加到谓词中。

目前仅RDB及KVDB(schema)支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**返回值：**

| 类型                                        | 说明                   |
| ------------------------------------------- | ---------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回带有或条件的谓词。 |

**示例：**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.equalTo("NAME", "lisi")
    .or()
    .equalTo("NAME", "Rose")
```

## and

and(): DataSharePredicates

该接口用于将和条件添加到谓词中。

目前仅RDB及KVDB(schema)支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**返回值：**

| 类型                                        | 说明                   |
| ------------------------------------------- | ---------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回带有和条件的谓词。 |

**示例：**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.equalTo("NAME", "lisi")
    .and()
    .equalTo("SALARY", 200.5)
```

## contains

contains(field: string, value: string): DataSharePredicates

该接口用于配置谓词以匹配数据类型为string且值包含指定的字段。目前仅RDB支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                 |
| ------ | ------ | ---- | -------------------- |
| field  | string | 是   | 数据库表中的列名。   |
| value  | string | 是   | 指示值中包含该字段。 |

**返回值：**

| 类型                                        | 说明                       |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.contains("NAME", "os")
```

## beginsWith

beginsWith(field: string, value: string): DataSharePredicates

该接口用于配置谓词以匹配数据类型为string且值以指定字符串起始的字段。目前仅RDB支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                   |
| ------ | ------ | ---- | ---------------------- |
| field  | string | 是   | 数据库表中的列名。     |
| value  | string | 是   | 指示值以该字符串起始。 |

**返回值：**

| 类型                                        | 说明                       |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.beginsWith("NAME", "os")
```

## endsWith

endsWith(field: string, value: string): DataSharePredicates

该接口用于配置谓词以匹配数据类型为string且值以指定字符串结尾的字段。目前仅RDB支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                   |
| ------ | ------ | ---- | ---------------------- |
| field  | string | 是   | 数据库表中的列名。     |
| value  | string | 是   | 指示值以该字符串结尾。 |

**返回值：**

| 类型                                        | 说明                       |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.endsWith("NAME", "os")
```

## isNull

isNull(field: string): DataSharePredicates

该接口用于配置谓词以匹配值为null的字段。

目前仅RDB及KVDB(schema)支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| field  | string | 是   | 数据库表中的列名。 |

**返回值：**

| 类型                                        | 说明                       |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.isNull("NAME")
```

## isNotNull

isNotNull(field: string): DataSharePredicates

该接口用于配置谓词以匹配值不为null的指定字段。

目前仅RDB及KVDB(schema)支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| field  | string | 是   | 数据库表中的列名。 |

**返回值：**

| 类型                                        | 说明                       |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.isNotNull("NAME")
```

## like

like(field: string, value: string): DataSharePredicates

该接口用于配置谓词以匹配数据类型为string且值类似于指定字符串的字段。

目前仅RDB及KVDB(schema)支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                   |
| ------ | ------ | ---- | ---------------------- |
| field  | string | 是   | 数据库表中的列名。     |
| value  | string | 是   | 指示要与谓词匹配的值。 |

**返回值：**

| 类型                                        | 说明                       |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.like("NAME", "%os%")
```

## unlike

unlike(field: string, value: string): DataSharePredicates

该接口用于配置谓词以匹配数据类型为string且值不类似于指定字符串的字段。

目前仅RDB及KVDB(schema)支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                   |
| ------ | ------ | ---- | ---------------------- |
| field  | string | 是   | 数据库表中的列名。     |
| value  | string | 是   | 指示要与谓词匹配的值。 |

**返回值：**

| 类型                                        | 说明                       |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.unlike("NAME", "%os%")
```

## glob

glob(field: string, value: string): DataSharePredicates

该接口用于配置谓词匹配数据类型为string的指定字段。目前仅RDB支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                   |
| ------ | ------ | ---- | ---------------------- |
| field  | string | 是   | 数据库表中的列名。     |
| value  | string | 是   | 指示要与谓词匹配的值。 |

**返回值：**

| 类型                                        | 说明                       |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.glob("NAME", "?h*g")
```

## between

between(field: string, low: ValueType, high: ValueType): DataSharePredicates

该接口用于将谓词配置为匹配数据类型为ValueType且值在指定范围内的指定字段。目前仅RDB支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**参数：**

| 参数名 | 类型                                                | 必填 | 说明                     |
| ------ | --------------------------------------------------- | ---- | ------------------------ |
| field  | string                                              | 是   | 数据库表中的列名。       |
| low    | [ValueType](js-apis-data-ValuesBucket.md#valuetype) | 是   | 指示与谓词匹配的最小值。 |
| high   | [ValueType](js-apis-data-ValuesBucket.md#valuetype) | 是   | 指示与谓词匹配的最大值。 |

**返回值：**

| 类型                                        | 说明                       |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.between("AGE", 10, 50)
```

## notBetween

notBetween(field: string, low: ValueType, high: ValueType): DataSharePredicates

该接口用于配置谓词以匹配数据类型为ValueType且值超出给定范围的指定字段。目前仅RDB支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**参数：**

| 参数名 | 类型                                                | 必填 | 说明                     |
| ------ | --------------------------------------------------- | ---- | ------------------------ |
| field  | string                                              | 是   | 数据库表中的列名。       |
| low    | [ValueType](js-apis-data-ValuesBucket.md#valuetype) | 是   | 指示与谓词匹配的最小值。 |
| high   | [ValueType](js-apis-data-ValuesBucket.md#valuetype) | 是   | 指示与谓词匹配的最大值。 |

**返回值：**

| 类型                                        | 说明                       |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.notBetween("AGE", 10, 50)
```

## greaterThan

greaterThan(field: string, value: ValueType): DataSharePredicates

该接口用于配置谓词以匹配数据类型为ValueType且值大于指定值的字段。

目前仅RDB及KVDB(schema)支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**参数：**

| 参数名  | 类型      | 必填 | 说明                   |
| ------- | --------- | ---- | ---------------------- |
| field   | string    | 是   | 数据库表中的列名。     |
| value | [ValueType](js-apis-data-ValuesBucket.md#valuetype) | 是   | 指示要与谓词匹配的值。 |

**返回值：**

| 类型                                        | 说明                       |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.greaterThan("AGE", 10)
```

## lessThan

lessThan(field: string, value: ValueType): DataSharePredicates

该接口用于配置谓词以匹配数据类型为ValueType且值小于指定值的字段。

目前仅RDB及KVDB(schema)支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**参数：**

| 参数名 | 类型                                                | 必填 | 说明                   |
| ------ | --------------------------------------------------- | ---- | ---------------------- |
| field  | string                                              | 是   | 数据库表中的列名。     |
| value  | [ValueType](js-apis-data-ValuesBucket.md#valuetype) | 是   | 指示要与谓词匹配的值。 |

**返回值：**

| 类型                                        | 说明                       |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.lessThan("AGE", 50)
```

## greaterThanOrEqualTo

greaterThanOrEqualTo(field: string, value: ValueType): DataSharePredicates

该接口用于配置谓词以匹配数据类型为ValueType且值大于或等于指定值的字段。

目前仅RDB及KVDB(schema)支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**参数：**

| 参数名  | 类型      | 必填 | 说明                   |
| ------- | --------- | ---- | ---------------------- |
| field   | string    | 是   | 数据库表中的列名。     |
| value | [ValueType](js-apis-data-ValuesBucket.md#valuetype) | 是   | 指示要与谓词匹配的值。 |

**返回值：**

| 类型                                        | 说明                       |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.greaterThanOrEqualTo("AGE", 10)
```

## lessThanOrEqualTo

lessThanOrEqualTo(field: string, value: ValueType): DataSharePredicates

该接口用于配置谓词以匹配数据类型为ValueType且值小于或等于指定值的字段。

目前仅RDB及KVDB(schema)支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**参数：**

| 参数名  | 类型      | 必填 | 说明                   |
| ------- | --------- | ---- | ---------------------- |
| field   | string    | 是   | 数据库表中的列名。     |
| value | [ValueType](js-apis-data-ValuesBucket.md#valuetype) | 是   | 指示要与谓词匹配的值。 |

**返回值：**

| 类型                                        | 说明                       |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.lessThanOrEqualTo("AGE", 50)
```

## orderByAsc

orderByAsc(field: string): DataSharePredicates

该接口用于配置谓词以匹配其值按升序排序的列。

目前仅RDB及KVDB(schema)支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| field  | string | 是   | 数据库表中的列名。 |

**返回值：**

| 类型                                        | 说明                       |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.orderByAsc("AGE")
```

## orderByDesc

orderByDesc(field: string): DataSharePredicates

该接口用于配置谓词以匹配其值按降序排序的列。

目前仅RDB及KVDB(schema)支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| field  | string | 是   | 数据库表中的列名。 |

**返回值：**

| 类型                                        | 说明                       |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.orderByDesc("AGE")
```

## distinct

distinct(): DataSharePredicates

该接口用于配置谓词以过滤重复记录并仅保留其中一个。目前仅RDB支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**返回值：**

| 类型                                        | 说明                       |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.equalTo("NAME", "Rose").distinct("NAME")
```

## limit

limit(total: number, offset: number): DataSharePredicates

该接口用于配置谓词以指定结果数和起始位置。

目前仅RDB及KVDB(schema)支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**参数：**

| 参数名   | 类型   | 必填 | 说明           |
| -------- | ------ | ---- | -------------- |
| total    | number | 是   | 指定结果数。   |
| offset | number | 是   | 指示起始位置。 |

**返回值：**

| 类型                                        | 说明                       |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.equalTo("NAME", "Rose").limit(10, 3)
```

## groupBy

groupBy(fields: Array&lt;string&gt;): DataSharePredicates

该接口用于配置谓词按指定列分组查询结果。目前仅RDB支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**参数：**

| 参数名 | 类型          | 必填 | 说明                 |
| ------ | ------------- | ---- | -------------------- |
| fields | Array&lt;string&gt; | 是   | 指定分组依赖的列名。 |

**返回值：**

| 类型                                        | 说明                       |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.groupBy(["AGE", "NAME"])
```

## indexedBy

indexedBy(field: string): DataSharePredicates

该接口用于配置谓词按指定索引列查询结果。目前仅RDB支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明           |
| ------ | ------ | ---- | -------------- |
| field  | string | 是   | 索引列的名称。 |

**返回值：**

| 类型                                        | 说明                       |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.indexedBy("SALARY_INDEX")
```

## in

in(field: string, value: Array&lt;ValueType&gt;): DataSharePredicates

该接口用于配置谓词以匹配数据类型为ValueType数组且值在给定范围内的指定字段。

目前仅RDB及KVDB(schema)支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**参数：**

| 参数名  | 类型             | 必填 | 说明                                    |
| ------- | ---------------- | ---- | --------------------------------------- |
| field   | string           | 是 | 数据库表中的列名。                      |
| value | Array&lt;[ValueType](js-apis-data-ValuesBucket.md#valuetype)&gt; | 是   | 以ValueType型数组形式指定的要匹配的值。 |

**返回值：**

| 类型                                        | 说明                       |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.in("AGE", [18, 20])
```

## notIn

notIn(field: string, value: Array&lt;ValueType&gt;): DataSharePredicates

该接口用于配置谓词以匹配数据类型为ValueType数组且值不在给定范围内的指定字段。

目前仅RDB及KVDB(schema)支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**参数：**

| 参数名  | 类型             | 必填 | 说明                                    |
| ------- | ---------------- | ---- | --------------------------------------- |
| field   | string           | 是   | 数据库表中的列名。                      |
| value | Array&lt;[ValueType](js-apis-data-ValuesBucket.md#valuetype)&gt; | 是   | 以ValueType型数组形式指定的要匹配的值。 |

**返回值：**

| 类型                                        | 说明                       |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.notIn("NAME", ["Lisa", "Rose"])
```

## prefixKey

prefixKey(prefix: string): DataSharePredicates

该接口用于配置谓词以匹配键前缀的指定字段。目前仅KVDB支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明           |
| ------ | ------ | ---- | -------------- |
| prefix | string | 是   | 指定的键前缀。 |

**返回值：**

| 类型                                        | 说明                       |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.prefixKey("NAME")
```

## inKeys

inKeys(keys: Array&lt;string&gt;): DataSharePredicates

该接口用于配置谓词以匹配键在给定范围内的指定字段。目前仅KVDB支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**参数：**

| 参数名 | 类型          | 必填 | 说明               |
| ------ | ------------- | ---- | ------------------ |
| inKeys | Array&lt;string&gt; | 是   | 给定范围的键数组。 |

**返回值：**

| 类型                                        | 说明                       |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```ts
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.inKeys(["Lisa", "Rose"])
```
