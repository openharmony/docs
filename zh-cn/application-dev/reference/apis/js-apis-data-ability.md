# @ohos.data.dataAbility (DataAbility谓词)

DataAbility 谓词用于构造关系型数据库的谓词，提供用于实现不同查询方法的谓词。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```js
import dataAbility from '@ohos.data.dataAbility';
```

## dataAbility.createRdbPredicates

createRdbPredicates(name: string, dataAbilityPredicates: DataAbilityPredicates): rdb.RdbPredicates

通过表名和DataAbility谓词对象创建Rdb谓词对象。

**系统能力：** SystemCapability.DistributedDataManager.DataShare.Core。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| name | string | 是 | 数据库表中的表名。 |
| dataAbilityPredicates | [DataAbilityPredicates](#dataabilitypredicates) | 是 | DataAbility谓词。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| rdb.[RdbPredicates](js-apis-data-rdb.md#rdbpredicates) | 返回RdbPredicates对象。 |

**示例：**

  ```js
  let dataAbilityPredicates = new dataAbility.DataAbilityPredicates()
  dataAbilityPredicates.equalTo("NAME", "Rose")
  // EMPLOYEE是使用关系型数据库创建的表。
  let predicates = dataAbility.createRdbPredicates("EMPLOYEE", dataAbilityPredicates)
  ```

## DataAbilityPredicates

提供用于实现不同查询方法的谓词。

**初始化：**

  ```js
  let dataAbilityPredicates = new dataAbility.DataAbilityPredicates()
  ```
  
### equalTo

equalTo(field: string, value: ValueType): DataAbilityPredicates

配置谓词以匹配数据，数据的指定字段数据类型为ValueType且值等于指定值。

此方法类似于SQL语句的“=”。

**系统能力：** SystemCapability.DistributedDataManager.DataShare.Core。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| field | string | 是 | 数据库表中的列名。 |
| value | [ValueType](#valuetype) | 是 | 指示要与谓词匹配的值。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

  ```js
  dataAbilityPredicates.equalTo("NAME", "lisi")
  ```

### notEqualTo

notEqualTo(field: string, value: ValueType): DataAbilityPredicates

配置谓词以匹配数据，数据的指定字段数据类型为ValueType且不等于指定值。

此方法类似于SQL语句的“!=”。

**系统能力：** SystemCapability.DistributedDataManager.DataShare.Core。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| field | string | 是 | 数据库表中的列名。 |
| value | [ValueType](#valuetype) | 是 | 指示要与谓词匹配的值。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

  ```js
  dataAbilityPredicates.notEqualTo("NAME", "lisi")
  ```

### beginWrap

beginWrap(): DataAbilityPredicates

在谓词中添加左括号。此方法类似于SQL语句的“(”，需要与endWrap一起使用。

**系统能力：** SystemCapability.DistributedDataManager.DataShare.Core。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | 返回带有左括号的DataAbility谓词。 |

**示例：**

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

在谓词中添加右括号。此方法类似于SQL语句的“)”，需要和beginWrap一起使用。

**系统能力：** SystemCapability.DistributedDataManager.DataShare.Core。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | 返回带有右括号的DataAbility谓词。 |

**示例：**

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

将或条件添加到谓词中。

此方法类似于SQL语句“or”。

**系统能力：** SystemCapability.DistributedDataManager.DataShare.Core。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | 返回带有或条件的DataAbility谓词。 |

**示例：**

  ```js
  dataAbilityPredicates.equalTo("NAME", "Lisa")
      .or()
      .equalTo("NAME", "Rose")
  ```

### and

and(): DataAbilityPredicates

将和条件添加到谓词中。

**系统能力：** SystemCapability.DistributedDataManager.DataShare.Core。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | 返回带有和条件的DataAbility谓词。 |

**示例：**

  ```js
  dataAbilityPredicates.equalTo("NAME", "Lisa")
      .and()
      .equalTo("SALARY", 200.5)
  ```

### contains

contains(field: string, value: string): DataAbilityPredicates

配置谓词以匹配数据类型为string且value包含指定值的字段。

**系统能力：** SystemCapability.DistributedDataManager.DataShare.Core。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| field | string | 是 | 数据库表中的列名。 |
| value | string | 是 | 指示要与谓词匹配的值。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

  ```js
  dataAbilityPredicates.contains("NAME", "os")
  ```

### beginsWith

beginsWith(field: string, value: string): DataAbilityPredicates

配置谓词以匹配数据类型为string且值以指定字符串开头的字段。

此方法类似于SQL语句的“%”。

**系统能力：** SystemCapability.DistributedDataManager.DataShare.Core。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| field | string | 是 | 数据库表中的列名。 |
| value | string | 是 | 指示要与谓词匹配的值。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

  ```js
  dataAbilityPredicates.beginsWith("NAME", "os")
  ```

### endsWith

endsWith(field: string, value: string): DataAbilityPredicates

配置谓词以匹配数据类型为string且值以指定字符串结尾的字段。

此方法类似于SQL语句的“%”。

**系统能力：** SystemCapability.DistributedDataManager.DataShare.Core。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| field | string | 是 | 数据库表中的列名。 |
| value | string | 是 | 指示要与谓词匹配的值。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

  ```
  dataAbilityPredicates.endsWith("NAME", "se")
  ```

### isNull

isNull(field: string): DataAbilityPredicates

配置谓词以匹配值为null的字段。

**系统能力：** SystemCapability.DistributedDataManager.DataShare.Core。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| field | string | 是 | 数据库表中的列名。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

  ```js
  dataAbilityPredicates.isNull("NAME")
  ```

### isNotNull

isNotNull(field: string): DataAbilityPredicates

配置谓词以匹配值不为null的指定字段。

**系统能力：** SystemCapability.DistributedDataManager.DataShare.Core。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| field | string | 是 | 数据库表中的列名。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

  ```js
  dataAbilityPredicates.isNotNull("NAME")
  ```

### like

like(field: string, value: string): DataAbilityPredicates

配置谓词以匹配数据类型为string且值类似于指定字符串的字段。

此方法类似于SQL语句“like”。

**系统能力：** SystemCapability.DistributedDataManager.DataShare.Core。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| field | string | 是 | 数据库表中的列名。 |
| value | string | 是 | 指示要与谓词匹配的值。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

  ```js
  dataAbilityPredicates.like("NAME", "%os%")
  ```

### glob

glob(field: string, value: string): DataAbilityPredicates

配置谓词以匹配数据类型为string的指定字段。与like方法不同，该方法的输入参数区分大小写。

**系统能力：** SystemCapability.DistributedDataManager.DataShare.Core。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| field | string | 是 | 数据库表中的列名。 |
| value | string | 是 | 指示要与谓词匹配的值。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

  ```js
  dataAbilityPredicates.glob("NAME", "?h*g")

  // 仅可匹配到"name"字段值为“Lisa” 
  dataAbilityPredicates.glob("NAME", "Lisa")

  // 仅可以匹配到"name"字段值为“lisa” 
  dataAbilityPredicates.glob("NAME", "lisa")
  ```

### between

between(field: string, low: ValueType, high: ValueType): DataAbilityPredicates

配置谓词以匹配数据类型为ValueType且value在指定范围内的指定字段。

**系统能力：** SystemCapability.DistributedDataManager.DataShare.Core。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| field | string | 是 | 数据库表中的列名。 |
| low | [ValueType](#valuetype) | 是 | 指示与谓词匹配的最小值。 |
| high | [ValueType](#valuetype) | 是 | 指示与谓词匹配的最大值。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

  ```js
  dataAbilityPredicates.between("AGE", 10, 50)
  ```

### notBetween

notBetween(field: string, low: ValueType, high: ValueType): DataAbilityPredicates

配置谓词以匹配数据类型为ValueType且value超出给定范围的指定字段。

**系统能力：** SystemCapability.DistributedDataManager.DataShare.Core。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| field | string | 是 | 数据库表中的列名。 |
| low | [ValueType](#valuetype) | 是 | 指示与谓词匹配的最小值。 |
| high | [ValueType](#valuetype) | 是 | 指示与谓词匹配的最大值。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

  ```js
  dataAbilityPredicates.notBetween("AGE", 10, 50)
  ```

### greaterThan

greaterThan(field: string, value: ValueType): DataAbilityPredicates

配置谓词以匹配数据类型为ValueType且值大于指定值的字段。

**系统能力：** SystemCapability.DistributedDataManager.DataShare.Core。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| field | string | 是 | 数据库表中的列名。 |
| value | [ValueType](#valuetype) | 是 | 指示要与谓词匹配的值。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

  ```js
  dataAbilityPredicates.greaterThan("AGE", 18)
  ```

### lessThan

lessThan(field: string, value: ValueType): DataAbilityPredicates

配置谓词以匹配数据类型为valueType且value小于指定值的字段。

**系统能力：** SystemCapability.DistributedDataManager.DataShare.Core。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| field | string | 是 | 数据库表中的列名。 |
| value | [ValueType](#valuetype) | 是 | 指示要与谓词匹配的值。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

  ```js
  dataAbilityPredicates.lessThan("AGE", 20)
  ```

### greaterThanOrEqualTo

greaterThanOrEqualTo(field: string, value: ValueType): DataAbilityPredicates

配置谓词以匹配数据类型为ValueType且value大于或等于指定值的字段。

**系统能力：** SystemCapability.DistributedDataManager.DataShare.Core。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| field | string | 是 | 数据库表中的列名。 |
| value | [ValueType](#valuetype) | 是 | 指示要与谓词匹配的值。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

  ```js
  dataAbilityPredicates.greaterThanOrEqualTo("AGE", 18)
  ```

### lessThanOrEqualTo

lessThanOrEqualTo(field: string, value: ValueType): DataAbilityPredicates

配置谓词以匹配数据类型为ValueType且value小于或等于指定值的字段。

**系统能力：** SystemCapability.DistributedDataManager.DataShare.Core。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| field | string | 是 | 数据库表中的列名。 |
| value | [ValueType](#valuetype) | 是 | 指示要与谓词匹配的值。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

  ```js
  dataAbilityPredicates.lessThanOrEqualTo("AGE", 20)
  ```

### orderByAsc

orderByAsc(field: string): DataAbilityPredicates

配置谓词以匹配其值按升序排序的列。当有多个orderByAsc使用时，最先使用的具有最高优先级。

**系统能力：** SystemCapability.DistributedDataManager.DataShare.Core。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| field | string | 是 | 数据库表中的列名。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

  ```js
  // 先按“name”字段排序，相同时按“AGE”字段排序，其次按“SALARY”排序
  dataAbilityPredicates.orderByAsc("NAME").orderByAsc("AGE").orderByAsc("SALARY")
  ```

### orderByDesc

orderByDesc(field: string): DataAbilityPredicates

配置谓词以匹配其值按降序排序的列。当有多个orderByDesc使用时，最先使用的具有最高优先级。

**系统能力：** SystemCapability.DistributedDataManager.DataShare.Core。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| field | string | 是 | 数据库表中的列名。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

  ```js
  // 优先按“AGE”排序，相同时按“SALARY”排序
  dataAbilityPredicates.orderByDesc("AGE").orderByDesc("SALARY")
  ```

### distinct

distinct(): DataAbilityPredicates

配置谓词以过滤重复记录并仅保留其中一个。

**系统能力：** SystemCapability.DistributedDataManager.DataShare.Core。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | 返回可用于过滤重复记录的谓词。 |

**示例：**

  ```js
  dataAbilityPredicates.equalTo("NAME", "Rose").distinct()
  ```

### limitAs

limitAs(value: number): DataAbilityPredicates

设置最大数据记录数的谓词。

**系统能力：** SystemCapability.DistributedDataManager.DataShare.Core。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 是 | 最大数据记录数。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | 返回可用于设置最大数据记录数的谓词。 |

**示例：**

  ```js
  dataAbilityPredicates.equalTo("NAME", "Rose").limitAs(3)
  ```

### offsetAs

offsetAs(rowOffset: number): DataAbilityPredicates

配置谓词以指定返回结果的起始位置。将此方法必须与limitAs一起使用。

**系统能力：** SystemCapability.DistributedDataManager.DataShare.Core。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| rowOffset | number | 是 | 返回结果的起始位置，取值为正整数。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | 返回具有指定返回结果起始位置的谓词。 |

**示例：**

  ```js
  // 跳过前三条数据，显示后续三条数据
  dataAbilityPredicates.equalTo("NAME", "Rose").offsetAs(3).limitAs(3)
  ```


### groupBy

groupBy(fields: Array&lt;string&gt;): DataAbilityPredicates

配置谓词按指定列分组查询结果。

**系统能力：** SystemCapability.DistributedDataManager.DataShare.Core。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| fields | Array&lt;string&gt; | 是 | 指定分组依赖的列名。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | 返回分组查询列的谓词。 |

**示例：**

  ```js
  dataAbilityPredicates.groupBy(["AGE", "NAME"])
  ```

### indexedBy

indexedBy(field: string): DataAbilityPredicates

配置谓词以指定索引列。在使用此方法之前，您需要创建一个索引列。

**系统能力：** SystemCapability.DistributedDataManager.DataShare.Core。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| indexName | string | 是 | 索引列的名称。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | 返回具有指定索引列的谓词。 |

**示例：**

  ```js
  import relationalStore from '@ohos.data.rdb'; // 导入模块
  import featureAbility from '@ohos.ability.featureAbility';


  let context = getContext(this);

  const STORE_CONFIG :relationalStore.StoreConfig= {
    name: 'RdbTest.db', // 数据库文件名
    encrypt: false, // 可选参数，指定数据库是否加密，默认不加密
    dataGroupId: 'dataGroupID', // 可选参数，仅可在Stage模型下使用，表示为应用组ID，需要向应用市场获取。指定在此Id对应的沙箱路径下创建实例，当此参数不填时，默认在本应用沙箱目录下创建。
    customDir: 'customDir/subCustomDir' // 可选参数，数据库自定义路径。数据库将在如下的目录结构中被创建：context.databaseDir + '/rdb/' + customDir，其中context.databaseDir是应用沙箱对应的路径，'/rdb/'表示创建的是关系型数据库，customDir表示自定义的路径。当此参数不填时，默认在本应用沙箱目录下创建RdbStore实例。
  };

  // 表结构：EMPLOYEE (NAME, AGE, SALARY, CODES)
  const SQL_CREATE_TABLE = 'CREATE TABLE IF NOT EXISTS EMPLOYEE (ID INTEGER PRIMARY KEY AUTOINCREMENT, NAME TEXT NOT NULL, AGE INTEGER, SALARY REAL, CODES BLOB)'; // 建表Sql语句
  relationalStore.getRdbStore(this.context, STORE_CONFIG, 3, async (err, store) => {
    if (err) {
      console.error(`Failed to get RdbStore. Code:${err.code}, message:${err.message}`);
      return;
    }
    console.info('Succeeded in getting RdbStore.');


    await store.executeSql(SQL_CREATE_TABLE); // 创建数据表


    // 创建索引
    const SQL_CREATE_INDEX = 'CREATE INDEX SALARY_INDEX ON EMPLOYEE(SALARY)'
    await store.executeSql(SQL_CREATE_INDEX);
    // ...

    let dataAbilityPredicates = new dataAbility.DataAbilityPredicates()
    dataAbilityPredicates.indexedBy("SALARY_INDEX")

    //  ...
  })
  ```

### in

in(field: string, value: Array&lt;ValueType&gt;): DataAbilityPredicates

配置谓词以匹配数据类型为ValueType数组且值在给定范围内的指定字段。

**系统能力：** SystemCapability.DistributedDataManager.DataShare.Core。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| field | string | 是 | 数据库表中的列名。 |
| value | Array&lt;[ValueType](#valuetype)&gt; | 是 | 以ValueType类型数组形式指定的要匹配的值。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

  ```js
  dataAbilityPredicates.in("AGE", [18, 20])
  ```

### notIn

notIn(field: string, value: Array&lt;ValueType&gt;): DataAbilityPredicates

配置谓词以匹配数据类型为ValueType数组且值不在给定范围内的指定字段。

**系统能力：** SystemCapability.DistributedDataManager.DataShare.Core。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| field | string | 是 | 数据库表中的列名。 |
| value | Array&lt;[ValueType](#valuetype)&gt; | 是 | 以ValueType类型数组形式指定的要匹配的值。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [DataAbilityPredicates](#dataabilitypredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

  ```js
  dataAbilityPredicates.notIn("NAME", ["Lisa", "Rose"])
  ```

## ValueType

用于表示允许的数据字段类型。

**系统能力：** SystemCapability.DistributedDataManager.DataShare.Core。

| 类型    | 说明                 |
| ------- | -------------------- |
| number  | 表示值类型为数字。   |
| string  | 表示值类型为字符。   |
| boolean | 表示值类型为布尔值。 |
