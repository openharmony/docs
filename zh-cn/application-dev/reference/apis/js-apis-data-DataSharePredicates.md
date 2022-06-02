# DataSharePredicates

**谓词(DataSharePredicates)** 是用户通过DataShare查询数据库中的数据所使用的限制条件，经常被应用在更新数据(Update)和查询数据(Query)中。

>**说明：** 
>
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```ts
import DataSharePredicates from '@ohos.data.DataSharePredicates';
```


## equalTo

equalTo(field: string, value: ValueType): DataSharePredicates;

该接口用于配置谓词以匹配数据类型为ValueType且值等于指定值的字段。

目前仅RDB及KVDB(schema)支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core。

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
let dataSharePredicates = new DataSharePredicates()
dataSharePredicates.equalTo("NAME", "Rose")
```

## notEqualTo

notEqualTo(field: string, value: ValueType): DataSharePredicates;

该接口用于配置谓词以匹配数据类型为ValueType且值不等于指定值的字段。

目前仅RDB及KVDB(schema)支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core。

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
let dataSharePredicates = new DataSharePredicates()
dataSharePredicates.notEqualTo("NAME", "Rose")
```

## beginWrap

beginWrap(): DataSharePredicates;

该接口用于向谓词添加左括号。目前仅RDB支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core。

**返回值：**

| 类型                                        | 说明                   |
| ------------------------------------------- | ---------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回带有左括号的谓词。 |

**示例：**

```ts
let dataSharePredicates = new DataSharePredicates()
dataSharePredicates.equalTo("NAME", "lisi")
    .beginWrap()
    .equalTo("AGE", 18)
    .or()
    .equalTo("SALARY", 200.5)
    .endWrap()
```

## endWrap

endWrap(): DataSharePredicates;

该接口用于向谓词添加右括号。目前仅RDB支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core。

**返回值：**

| 类型                                        | 说明                   |
| ------------------------------------------- | ---------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回带有右括号的谓词。 |

**示例：**

```ts
let dataSharePredicates = new DataSharePredicates()
dataSharePredicates.equalTo("NAME", "lisi")
    .beginWrap()
    .equalTo("AGE", 18)
    .or()
    .equalTo("SALARY", 200.5)
    .endWrap()
```

## or

or(): DataSharePredicates;

该接口用于将或条件添加到谓词中。

目前仅RDB及KVDB(schema)支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core。

**返回值：**

| 类型                                        | 说明                   |
| ------------------------------------------- | ---------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回带有或条件的谓词。 |

**示例：**

```ts
let dataSharePredicates = new DataSharePredicates()
dataSharePredicates.equalTo("NAME", "lisi")
    .or()
    .equalTo("NAME", "Rose")
```

## and

and(): DataSharePredicates;

该接口用于将和条件添加到谓词中。

目前仅RDB及KVDB(schema)支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core。

**返回值：**

| 类型                                        | 说明                   |
| ------------------------------------------- | ---------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回带有和条件的谓词。 |

**示例：**

```ts
let dataSharePredicates = new DataSharePredicates()
dataSharePredicates.equalTo("NAME", "lisi")
    .and()
    .equalTo("SALARY", 200.5)
```

## contains

contains(field: string, value: string): DataSharePredicates;

该接口用于配置谓词以匹配数据类型为String且value包含指定值的字段。目前仅RDB支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core。

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
let dataSharePredicates = new DataSharePredicates()
dataSharePredicates.contains("NAME", "os")
```

## beginsWith

beginsWith(field: string, value: string): DataSharePredicates;

该接口用于配置谓词以匹配数据类型为String且值以指定字符串开头的字段。目前仅RDB支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core。

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
let dataSharePredicates = new DataSharePredicates()
dataSharePredicates.beginsWith("NAME", "os")
```

## endsWith

endsWith(field: string, value: string): DataSharePredicates;

该接口用于配置谓词以匹配数据类型为String且值以指定字符串结尾的字段。目前仅RDB支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core。

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
let dataSharePredicates = new DataSharePredicates()
dataSharePredicates.endsWith("NAME", "os")
```

## isNull

isNull(field: string): DataSharePredicates;

该接口用于配置谓词以匹配值为null的字段。

目前仅RDB及KVDB(schema)支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core。

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
let dataSharePredicates = new DataSharePredicates()
dataSharePredicates.isNull("NAME")
```

## isNotNull

isNotNull(field: string): DataSharePredicates;

该接口用于配置谓词以匹配值不为null的指定字段。

目前仅RDB及KVDB(schema)支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core。

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
let dataSharePredicates = new DataSharePredicates()
dataSharePredicates.isNotNull("NAME")
```

## like

like(field: string, value: string): DataSharePredicates;

该接口用于配置谓词以匹配数据类型为string且值类似于指定字符串的字段。

目前仅RDB及KVDB(schema)支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core。

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
let dataSharePredicates = new DataSharePredicates()
dataSharePredicates.like("NAME", "%os%")
```

## unlike

unlike(field: string, value: string): DataSharePredicates;

该接口用于配置谓词以匹配数据类型为string且值不类似于指定字符串的字段。

目前仅RDB及KVDB(schema)支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core。

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
let dataSharePredicates = new DataSharePredicates()
dataSharePredicates.unlike("NAME", "%os%")
```

## glob

glob(field: string, value: string): DataSharePredicates;

该接口用于配置谓词匹配数据类型为string的指定字段。目前仅RDB支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core。

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
let dataSharePredicates = new DataSharePredicates()
dataSharePredicates.glob("NAME", "?h*g")
```

## between

between(field: string, low: ValueType, high: ValueType): DataSharePredicates;

该接口用于将谓词配置为匹配数据类型为ValueType且value在指定范围内的指定字段。目前仅RDB支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core。

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
let dataSharePredicates = new DataSharePredicates()
dataSharePredicates.between("AGE", 10, 50)
```

## notBetween

notBetween(field: string, low: ValueType, high: ValueType): DataSharePredicates;

该接口用于配置谓词以匹配数据类型为ValueType且value超出给定范围的指定字段。目前仅RDB支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core。

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
let dataSharePredicates = new DataSharePredicates()
dataSharePredicates.notBetween("AGE", 10, 50)
```

## greaterThan

greaterThan(field: string, value: ValueType): DataSharePredicates;

该接口用于配置谓词以匹配数据类型为ValueType且值大于指定值的字段。

目前仅RDB及KVDB(schema)支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core。

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
let dataSharePredicates = new DataSharePredicates()
dataSharePredicates.greaterThan("AGE", 10)
```

## lessThan

lessThan(field: string, value: ValueType): DataSharePredicates;

该接口用于配置谓词以匹配数据类型为valueType且value小于指定值的字段。

目前仅RDB及KVDB(schema)支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core。

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
let dataSharePredicates = new DataSharePredicates()
dataSharePredicates.lessThan("AGE", 50)
```

## greaterThanOrEqualTo

greaterThanOrEqualTo(field: string, value: ValueType): DataSharePredicates;

该接口用于配置谓词以匹配数据类型为ValueType且value大于或等于指定值的字段。

目前仅RDB及KVDB(schema)支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core。

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
let dataSharePredicates = new DataSharePredicates()
dataSharePredicates.greaterThanOrEqualTo("AGE", 10)
```

## lessThanOrEqualTo

lessThanOrEqualTo(field: string, value: ValueType): DataSharePredicates;

该接口用于配置谓词以匹配数据类型为ValueType且value小于或等于指定值的字段。

目前仅RDB及KVDB(schema)支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core。

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
let dataSharePredicates = new DataSharePredicates()
dataSharePredicates.lessThanOrEqualTo("AGE", 50)
```

## orderByAsc

orderByAsc(field: *string*): DataSharePredicates;

该接口用于配置谓词以匹配其值按升序排序的列。

目前仅RDB及KVDB(schema)支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core。

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
let dataSharePredicates = new DataSharePredicates()
dataSharePredicates.orderByAsc("AGE")
```

## orderByDesc

orderByDesc(field: *string*): DataSharePredicates;

该接口用于配置谓词以匹配其值按降序排序的列。

目前仅RDB及KVDB(schema)支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core。

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
let dataSharePredicates = new DataSharePredicates()
dataSharePredicates.orderByDesc("AGE")
```

## distinct

distinct(): DataSharePredicates;

该接口用于配置谓词以过滤重复记录并仅保留其中一个。目前仅RDB支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core。

**返回值：**

| 类型                                        | 说明                       |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```ts
let dataSharePredicates = new DataSharePredicates()
dataSharePredicates.equalTo("NAME", "Rose").distinct("NAME")
```

## limit

limit(total: number, offset: number): DataSharePredicates;

该接口用于配置谓词以指定结果数和起始位置。

目前仅RDB及KVDB(schema)支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core。

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
let dataSharePredicates = new DataSharePredicates()
dataSharePredicates.equalTo("NAME", "Rose").limit(10, 3)
```

## groupBy

groupBy(fields: Array<string>): DataSharePredicates;

该接口用于配置谓词按指定列分组查询结果。目前仅RDB支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core。

**参数：**

| 参数名 | 类型          | 必填 | 说明                 |
| ------ | ------------- | ---- | -------------------- |
| fields | Array<string> | 是   | 指定分组依赖的列名。 |

**返回值：**

| 类型                                        | 说明                       |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```ts
let dataSharePredicates = new DataSharePredicates()
dataSharePredicates.groupBy(["AGE", "NAME"])
```

## indexedBy

indexedBy(field: string): DataSharePredicates;

该接口用于配置谓词以指定索引列。目前仅RDB支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core。

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
let dataSharePredicates = new DataSharePredicates()
dataSharePredicates.indexedBy("SALARY_INDEX")
```

## in

in(field: string, value: Array<ValueType>): DataSharePredicates;

该接口用于配置谓词以匹配数据类型为ValueType数组且值在给定范围内的指定字段。

目前仅RDB及KVDB(schema)支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core。

**参数：**

| 参数名  | 类型             | 必填 | 说明                                    |
| ------- | ---------------- | ---- | --------------------------------------- |
| field   | string           | 是 | 数据库表中的列名。                      |
| value | Array<[ValueType](js-apis-data-ValuesBucket.md#valuetype)> | 是   | 以ValueType型数组形式指定的要匹配的值。 |

**返回值：**

| 类型                                        | 说明                       |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```ts
let dataSharePredicates = new DataSharePredicates()
dataSharePredicates.in("AGE", [18, 20])
```

## notIn

notIn(field: string, value: Array<ValueType>): DataSharePredicates;

该接口用于配置谓词以匹配数据类型为ValueType数组且值不在给定范围内的指定字段。

目前仅RDB及KVDB(schema)支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core。

**参数：**

| 参数名  | 类型             | 必填 | 说明                                    |
| ------- | ---------------- | ---- | --------------------------------------- |
| field   | string           | 是   | 数据库表中的列名。                      |
| value | Array<[ValueType](js-apis-data-ValuesBucket.md#valuetype)> | 是   | 以ValueType型数组形式指定的要匹配的值。 |

**返回值：**

| 类型                                        | 说明                       |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```ts
let dataSharePredicates = new DataSharePredicates()
dataSharePredicates.notIn("NAME", ["Lisa", "Rose"])
```

## prefixKey

prefixKey(prefix: string): DataSharePredicates;

该接口用于配置谓词以匹配键前缀的指定字段。目前仅KVDB支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core。

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
let dataSharePredicates = new DataSharePredicates()
dataSharePredicates.prefixKey("NAME")
```

## inKeys

inKeys(keys: Array<string>): DataSharePredicates;

该接口用于配置谓词以匹配键在给定范围内的指定字段。目前仅KVDB支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core。

**参数：**

| 参数名 | 类型          | 必填 | 说明               |
| ------ | ------------- | ---- | ------------------ |
| inKeys | Array<string> | 是   | 给定范围的键数组。 |

**返回值：**

| 类型                                        | 说明                       |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```ts
let dataSharePredicates = new DataSharePredicates()
dataSharePredicates.inKeys(["Lisa", "Rose"])
```
