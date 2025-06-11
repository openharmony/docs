# @ohos.data.dataSharePredicates (数据共享谓词)(系统接口)

**谓词(DataSharePredicates)** 是开发者通过DataShare查询数据库中的数据所使用的筛选条件，经常被应用在更新数据([update](js-apis-data-dataShare-sys.md#update))、删除数据([delete](js-apis-data-dataShare-sys.md#delete))和查询数据([query](js-apis-data-dataShare-sys.md#query))中。

谓词的接口函数与数据库的筛选条件一一对应，开发者在使用前需了解数据库相关知识。

谓词(DataSharePredicates)的使用场景如下：

- 用于调用[关系型数据库](js-apis-data-relationalStore-sys.md)和[键值型数据库](js-apis-distributedKVStore-sys.md)系统接口时的检索条件使用。此种场景下，开发者根据使用的数据库类型参考对应的谓词使用方法。

> **说明：** 
>
> - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本模块接口仅可在Stage模型下使用。
>
> - 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.data.dataSharePredicates (数据共享谓词)](js-apis-data-dataSharePredicates.md)。



## 导入模块

```ts
import { dataSharePredicates } from '@kit.ArkData';
```

## DataSharePredicates
提供用于不同实现不同查询方法的数据共享谓词。该类型不是多线程安全的，如果应用中存在多线程同时操作该类派生出的实例，注意加锁保护。

### notEqualTo

notEqualTo(field: string, value: ValueType): DataSharePredicates

该接口用于配置谓词以匹配值不等于指定值的字段。

目前仅关系型数据库及键值型数据库支持该谓词。

**系统接口：**  此接口为系统接口。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**参数：**

| 参数名 | 类型                                                | 必填 | 说明                   |
| ------ | --------------------------------------------------- | ---- | ---------------------- |
| field  | string                                              | 是   | 数据库表中的列名。     |
| value  | [ValueType](js-apis-data-valuesBucket.md#valuetype) | 是   | 指示要与谓词匹配的值。 |

**返回值：**

| 类型                                        | 说明                       |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```ts
let predicates = new dataSharePredicates.DataSharePredicates();
predicates.notEqualTo("NAME", "Rose");
```

### beginWrap

beginWrap(): DataSharePredicates

该接口用于向谓词添加左括号，相当于sql语句的“(”，必须和右括号一起使用。

目前仅关系型数据库支持该谓词。

**系统接口：**  此接口为系统接口。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**返回值：**

| 类型                                        | 说明                   |
| ------------------------------------------- | ---------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回带有左括号的谓词。 |

**示例：**

```ts
let predicates = new dataSharePredicates.DataSharePredicates();
predicates.equalTo("NAME", "lisi")
    .beginWrap()
    .equalTo("AGE", 18)
    .or()
    .equalTo("SALARY", 200.5)
    .endWrap();
```

### endWrap

endWrap(): DataSharePredicates

该接口用于向谓词添加右括号。

目前仅关系型数据库支持该谓词。

**系统接口：**  此接口为系统接口。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**返回值：**

| 类型                                        | 说明                   |
| ------------------------------------------- | ---------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回带有右括号的谓词。 |

**示例：**

```ts
let predicates = new dataSharePredicates.DataSharePredicates();
predicates.equalTo("NAME", "lisi")
    .beginWrap()
    .equalTo("AGE", 18)
    .or()
    .equalTo("SALARY", 200.5)
    .endWrap();
```

### or

or(): DataSharePredicates

该接口用于将或条件添加到谓词中。

目前仅关系型数据库及键值型数据库支持该谓词。

**系统接口：**  此接口为系统接口。

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
    .equalTo("NAME", "Rose");
```

### contains

contains(field: string, value: string): DataSharePredicates

该接口用于配置谓词以匹配值包含指定字段的字段。

目前仅关系型数据库支持该谓词。

**系统接口：**  此接口为系统接口。

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
let predicates = new dataSharePredicates.DataSharePredicates();
predicates.contains("NAME", "os");
```

### beginsWith

beginsWith(field: string, value: string): DataSharePredicates

该接口用于配置谓词以匹配值以指定字符串起始的字段。

目前仅关系型数据库支持该谓词。

**系统接口：**  此接口为系统接口。

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
let predicates = new dataSharePredicates.DataSharePredicates();
predicates.beginsWith("NAME", "os");
```

### endsWith

endsWith(field: string, value: string): DataSharePredicates

该接口用于配置谓词以匹配值以指定字符串结尾的字段。

目前仅关系型数据库支持该谓词。

**系统接口：**  此接口为系统接口。

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
let predicates = new dataSharePredicates.DataSharePredicates();
predicates.endsWith("NAME", "os");
```

### isNull

isNull(field: string): DataSharePredicates

该接口用于配置谓词以匹配值为null的字段。

目前仅关系型数据库及键值型数据库支持该谓词。

**系统接口：**  此接口为系统接口。

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
let predicates = new dataSharePredicates.DataSharePredicates();
predicates.isNull("NAME");
```

### isNotNull

isNotNull(field: string): DataSharePredicates

该接口用于配置谓词以匹配值不为null的字段。

目前仅关系型数据库及键值型数据库支持该谓词。

**系统接口：**  此接口为系统接口。

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
let predicates = new dataSharePredicates.DataSharePredicates();
predicates.isNotNull("NAME");
```

### like

like(field: string, value: string): DataSharePredicates

该接口用于配置谓词以匹配指定通配符表达式的字段。

目前仅关系型数据库及键值型数据库支持该谓词。

**系统接口：**  此接口为系统接口。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                   |
| ------ | ------ | ---- | ---------------------- |
| field  | string | 是   | 数据库表中的列名。     |
| value  | string | 是   | 指示要与谓词匹配的通配符表达式。 <br>表达式中'%'代表零个、一个或多个数字或字符，'_'代表一个单一的数字或字符，不区分大小写。|

**返回值：**

| 类型                                        | 说明                       |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```ts
let predicates = new dataSharePredicates.DataSharePredicates();
predicates.like("NAME", "%os%");
```

### unlike

unlike(field: string, value: string): DataSharePredicates

该接口用于配置谓词以匹配不类似指定通配符表达式的字段。

目前仅关系型数据库及键值型数据库支持该谓词。

**系统接口：**  此接口为系统接口。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                   |
| ------ | ------ | ---- | ---------------------- |
| field  | string | 是   | 数据库表中的列名。     |
| value  | string | 是   | 指示要与谓词匹配的通配符表达式。<br>表达式中'%'代表零个、一个或多个数字或字符，'_'代表一个单一的数字或字符，不区分大小写。 |

**返回值：**

| 类型                                        | 说明                       |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```ts
let predicates = new dataSharePredicates.DataSharePredicates();
predicates.unlike("NAME", "%os%");
```

### glob

glob(field: string, value: string): DataSharePredicates

该接口用于配置谓词以匹配指定通配符表达式的字段。

目前仅关系型数据库支持该谓词。

**系统接口：**  此接口为系统接口。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                   |
| ------ | ------ | ---- | ---------------------- |
| field  | string | 是   | 数据库表中的列名。     |
| value  | string | 是   | 指示要与谓词匹配的通配符表达式。<br>表达式中'*'代表零个、一个或多个数字或字符，'?'代表一个单一的数字或字符，区分大小写。|

**返回值：**

| 类型                                        | 说明                       |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```ts
let predicates = new dataSharePredicates.DataSharePredicates();
predicates.glob("NAME", "?h*g");
```

### between

between(field: string, low: ValueType, high: ValueType): DataSharePredicates

该接口用于配置谓词以匹配值在指定范围内的字段。包含两端边界值，为左闭右闭区间，该字段的数据类型必须为int类型。

目前仅关系型数据库支持该谓词。

**系统接口：**  此接口为系统接口。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**参数：**

| 参数名 | 类型                                                | 必填 | 说明                     |
| ------ | --------------------------------------------------- | ---- | ------------------------ |
| field  | string                                              | 是   | 数据库表中的列名。       |
| low    | [ValueType](js-apis-data-valuesBucket.md#valuetype) | 是   | 指示与谓词匹配的最小值。 |
| high   | [ValueType](js-apis-data-valuesBucket.md#valuetype) | 是   | 指示与谓词匹配的最大值。 |

**返回值：**

| 类型                                        | 说明                       |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```ts
let predicates = new dataSharePredicates.DataSharePredicates();
predicates.between("AGE", 10, 50);
```

### notBetween

notBetween(field: string, low: ValueType, high: ValueType): DataSharePredicates

该接口用于配置谓词以匹配值超出指定范围的字段。不包含两端边界值，为左开右开区间，该字段的数据类型必须为int类型。

目前仅关系型数据库支持该谓词。

**系统接口：**  此接口为系统接口。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**参数：**

| 参数名 | 类型                                                | 必填 | 说明                     |
| ------ | --------------------------------------------------- | ---- | ------------------------ |
| field  | string                                              | 是   | 数据库表中的列名。       |
| low    | [ValueType](js-apis-data-valuesBucket.md#valuetype) | 是   | 指示与谓词匹配的最小值。 |
| high   | [ValueType](js-apis-data-valuesBucket.md#valuetype) | 是   | 指示与谓词匹配的最大值。 |

**返回值：**

| 类型                                        | 说明                       |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```ts
let predicates = new dataSharePredicates.DataSharePredicates();
predicates.notBetween("AGE", 10, 50);
```

### greaterThan

greaterThan(field: string, value: ValueType): DataSharePredicates

该接口用于配置谓词以匹配值大于指定值的字段。

目前仅关系型数据库及键值型数据库支持该谓词。

**系统接口：**  此接口为系统接口。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**参数：**

| 参数名  | 类型      | 必填 | 说明                   |
| ------- | --------- | ---- | ---------------------- |
| field   | string    | 是   | 数据库表中的列名。     |
| value | [ValueType](js-apis-data-valuesBucket.md#valuetype) | 是   | 指示要与谓词匹配的值。 |

**返回值：**

| 类型                                        | 说明                       |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```ts
let predicates = new dataSharePredicates.DataSharePredicates();
predicates.greaterThan("AGE", 10);
```

### lessThan

lessThan(field: string, value: ValueType): DataSharePredicates

该接口用于配置谓词以匹配值小于指定值的字段。

目前仅关系型数据库及键值型数据库支持该谓词。

**系统接口：**  此接口为系统接口。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**参数：**

| 参数名 | 类型                                                | 必填 | 说明                   |
| ------ | --------------------------------------------------- | ---- | ---------------------- |
| field  | string                                              | 是   | 数据库表中的列名。     |
| value  | [ValueType](js-apis-data-valuesBucket.md#valuetype) | 是   | 指示要与谓词匹配的值。 |

**返回值：**

| 类型                                        | 说明                       |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```ts
let predicates = new dataSharePredicates.DataSharePredicates();
predicates.lessThan("AGE", 50);
```

### greaterThanOrEqualTo

greaterThanOrEqualTo(field: string, value: ValueType): DataSharePredicates

该接口用于配置谓词以匹配值大于或等于指定值的字段。

目前仅关系型数据库及键值型数据库支持该谓词。

**系统接口：**  此接口为系统接口。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**参数：**

| 参数名  | 类型      | 必填 | 说明                   |
| ------- | --------- | ---- | ---------------------- |
| field   | string    | 是   | 数据库表中的列名。     |
| value | [ValueType](js-apis-data-valuesBucket.md#valuetype) | 是   | 指示要与谓词匹配的值。 |

**返回值：**

| 类型                                        | 说明                       |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```ts
let predicates = new dataSharePredicates.DataSharePredicates();
predicates.greaterThanOrEqualTo("AGE", 10);
```

### lessThanOrEqualTo

lessThanOrEqualTo(field: string, value: ValueType): DataSharePredicates

该接口用于配置谓词以匹配值小于或等于指定值的字段。

目前仅关系型数据库及键值型数据库支持该谓词。

**系统接口：**  此接口为系统接口。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**参数：**

| 参数名  | 类型      | 必填 | 说明                   |
| ------- | --------- | ---- | ---------------------- |
| field   | string    | 是   | 数据库表中的列名。     |
| value | [ValueType](js-apis-data-valuesBucket.md#valuetype) | 是   | 指示要与谓词匹配的值。 |

**返回值：**

| 类型                                        | 说明                       |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```ts
let predicates = new dataSharePredicates.DataSharePredicates();
predicates.lessThanOrEqualTo("AGE", 50);
```

### distinct

distinct(): DataSharePredicates

该接口用于配置谓词以过滤重复记录并仅保留其中一个。

目前仅关系型数据库支持该谓词。

**系统接口：**  此接口为系统接口。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**返回值：**

| 类型                                        | 说明                       |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```ts
let predicates = new dataSharePredicates.DataSharePredicates();
predicates.equalTo("NAME", "Rose").distinct();
```

### groupBy

groupBy(fields: Array&lt;string&gt;): DataSharePredicates

该接口用于配置谓词按指定列分组查询结果。

目前仅关系型数据库支持该谓词。

**系统接口：**  此接口为系统接口。

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
let predicates = new dataSharePredicates.DataSharePredicates();
predicates.groupBy(["AGE", "NAME"]);
```

### indexedBy

indexedBy(field: string): DataSharePredicates

该接口用于配置谓词按指定索引列查询结果。使用该方法前，需要设置索引列。

目前仅关系型数据库支持该谓词。

**系统接口：**  此接口为系统接口。

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
let predicates = new dataSharePredicates.DataSharePredicates();
predicates.indexedBy("SALARY_INDEX");
```

### notIn

notIn(field: string, value: Array&lt;ValueType&gt;): DataSharePredicates

该接口用于配置谓词以匹配值不在指定范围内的字段。

目前仅关系型数据库及键值型数据库支持该谓词。

**系统接口：**  此接口为系统接口。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**参数：**

| 参数名  | 类型             | 必填 | 说明                                    |
| ------- | ---------------- | ---- | --------------------------------------- |
| field   | string           | 是   | 数据库表中的列名。                      |
| value | Array&lt;[ValueType](js-apis-data-valuesBucket.md#valuetype)&gt; | 是   | 以ValueType型数组形式指定的要匹配的值。 |

**返回值：**

| 类型                                        | 说明                       |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```ts
let predicates = new dataSharePredicates.DataSharePredicates();
predicates.notIn("NAME", ["Lisa", "Rose"]);
```

### prefixKey

prefixKey(prefix: string): DataSharePredicates

该接口用于配置谓词以匹配键前缀的指定字段。

目前仅KVDB支持该谓词。

**系统接口：**  此接口为系统接口。

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
let predicates = new dataSharePredicates.DataSharePredicates();
predicates.prefixKey("NAME");
```

### inKeys

inKeys(keys: Array&lt;string&gt;): DataSharePredicates

该接口用于配置谓词以匹配键在指定范围内的字段。

目前仅KVDB支持该谓词。

**系统接口：**  此接口为系统接口。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**参数：**

| 参数名 | 类型          | 必填 | 说明               |
| ------ | ------------- | ---- | ------------------ |
| keys | Array&lt;string&gt; | 是   | 指定范围的键数组。 |

**返回值：**

| 类型                                        | 说明                       |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```ts
let predicates = new dataSharePredicates.DataSharePredicates();
predicates.inKeys(["Lisa", "Rose"]);
```