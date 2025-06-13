# @ohos.data.dataSharePredicates (数据共享谓词)

**谓词(DataSharePredicates)** 是开发者通过DataShare查询数据库中的数据所使用的筛选条件，经常被应用在更新数据、删除数据和查询数据中。

谓词的接口函数与数据库的筛选条件一一对应，开发者在使用前需了解数据库相关知识。

谓词(DataSharePredicates)的使用场景如下：

- 用于在媒体文件管理服务作为检索条件使用，参考[相册管理模块检索条件](../apis-media-library-kit/js-apis-photoAccessHelper.md#fetchoptions)。此种场景下，开发者无需关注数据库类型。

<!--Del-->
- 用于调用[关系型数据库](js-apis-data-relationalStore-sys.md)和[键值型数据库](js-apis-distributedKVStore-sys.md)系统接口时的检索条件使用。此种场景下，开发者根据使用的数据库类型参考对应的谓词使用方法。
<!--DelEnd-->

> **说明：** 
>
> - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本模块接口仅可在Stage模型下使用。



## 导入模块

```ts
import { dataSharePredicates } from '@kit.ArkData';
```

## DataSharePredicates
提供用于不同实现不同查询方法的数据共享谓词。该类型不是多线程安全的，如果应用中存在多线程同时操作该类派生出的实例，注意加锁保护。

### equalTo<sup>10+</sup>

equalTo(field: string, value: ValueType): DataSharePredicates

该接口用于配置谓词以匹配值等于指定值的字段。

目前仅关系型数据库及键值型数据库支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**原子化服务API：**  从API version 20开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型                                                | 必填 | 说明                   |
| ------ | --------------------------------------------------- | ---- | ---------------------- |
| field  | string                                              | 是   | 数据库表中的列名。</br>field为undefined或者null时，此次调用接口配置的谓词无效。     |
| value  | [ValueType](js-apis-data-valuesBucket.md#valuetype) | 是   | 指示要与谓词匹配的值。</br>value为undefined或者null时，此次调用接口配置的谓词无效。  |

**返回值：**

| 类型                                        | 说明                       |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```ts
let predicates = new dataSharePredicates.DataSharePredicates();
predicates.equalTo("NAME", "Rose");
```


### and<sup>10+</sup>

and(): DataSharePredicates

该接口用于将和条件添加到谓词中。

目前仅关系型数据库及键值型数据库支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**原子化服务API：**  从API version 20开始，该接口支持在原子化服务中使用。

**返回值：**

| 类型                                        | 说明                   |
| ------------------------------------------- | ---------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回带有和条件的谓词。 |

**示例：**

```ts
let predicates = new dataSharePredicates.DataSharePredicates();
predicates.equalTo("NAME", "lisi")
    .and()
    .equalTo("SALARY", 200.5);
```

### orderByAsc<sup>10+</sup>

orderByAsc(field: string): DataSharePredicates

该接口用于配置谓词以匹配其值按升序排序的列。

目前仅关系型数据库及键值型数据库支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**原子化服务API：**  从API version 20开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| field  | string | 是   | 数据库表中的列名。 </br>field为undefined或者null时，此次调用接口配置的谓词无效。 |

**返回值：**

| 类型                                        | 说明                       |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```ts
let predicates = new dataSharePredicates.DataSharePredicates();
predicates.orderByAsc("AGE");
```

### orderByDesc<sup>10+</sup>

orderByDesc(field: string): DataSharePredicates

该接口用于配置谓词以匹配其值按降序排序的列。

目前仅关系型数据库及键值型数据库支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**原子化服务API：**  从API version 20开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| field  | string | 是   | 数据库表中的列名。</br>field为undefined或者null时，此次调用接口配置的谓词无效。  |

**返回值：**

| 类型                                        | 说明                       |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```ts
let predicates = new dataSharePredicates.DataSharePredicates();
predicates.orderByDesc("AGE");
```

### limit<sup>10+</sup>

limit(total: number, offset: number): DataSharePredicates

该接口用于配置谓词以指定结果数和起始位置。

目前仅关系型数据库及键值型数据库支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**原子化服务API：**  从API version 20开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名   | 类型   | 必填 | 说明           |
| -------- | ------ | ---- | -------------- |
| total    | number | 是   | 最大数据记录数。</br>当使用键值型数据库且total为undefined或null时，会限制最大记录数为0。</br>当使用关系型数据库且total为undefined或null时，不会限制最大记录数。</br>当使用键值型数据库时，取值范围参考[键值型数据库limit接口](./js-apis-distributedKVStore.md#limit)中的total参数说明。</br>当使用关系型数据库时，取值范围参考[关系型数据库limitAs接口](arkts-apis-data-relationalStore-RdbPredicates.md#limitas)中的value参数说明。|
| offset | number | 是   | 指定查询结果的起始位置。</br>当offset为undefined或null时，起始位置为结果集的最前端。</br>当使用键值型数据库时，取值范围参考[键值型数据库limit接口](./js-apis-distributedKVStore.md#limit)中的offset参数说明。</br>当使用关系型数据库时，取值范围参考[关系型数据库offsetAs接口](arkts-apis-data-relationalStore-RdbPredicates.md#offsetas)中的rowOffset参数说明。|

**返回值：**

| 类型                                        | 说明                       |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```ts
let predicates = new dataSharePredicates.DataSharePredicates();
predicates.equalTo("NAME", "Rose").limit(10, 3);
```

### in<sup>10+</sup>

in(field: string, value: Array&lt;ValueType&gt;): DataSharePredicates

该接口用于配置谓词以匹配值在指定范围内的字段。

目前仅关系型数据库及键值型数据库支持该谓词。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**原子化服务API：**  从API version 20开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名  | 类型             | 必填 | 说明                                    |
| ------- | ---------------- | ---- | --------------------------------------- |
| field   | string           | 是 | 数据库表中的列名。</br>field为undefined或者null时，此次调用接口配置的谓词无效。                   |
| value | Array&lt;[ValueType](js-apis-data-valuesBucket.md#valuetype)&gt; | 是   | 以ValueType型数组形式指定的要匹配的值。 |

**返回值：**

| 类型                                        | 说明                       |
| ------------------------------------------- | -------------------------- |
| [DataSharePredicates](#datasharepredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```ts
let predicates = new dataSharePredicates.DataSharePredicates();
predicates.in("AGE", [18, 20]);
```