# @ohos.data.dataAbility    
DataAbility 谓词用于构造关系型数据库的谓词，提供用于实现不同查询方法的谓词。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import dataAbility from '@ohos.data.dataAbility'    
```  
    
## createRdbPredicates    
从DataAbilityPredicates对象创建RdbPredicates对象。  
 **调用形式：**     
- createRdbPredicates(name: string, dataAbilityPredicates: DataAbilityPredicates): rdb.RdbPredicates  
  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name | string | true | 数据库表中的表名。  |  
| dataAbilityPredicates | DataAbilityPredicates | true | DataAbility谓词。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| rdb.RdbPredicates | 返回RdbPredicates对象。 |  
    
 **示例代码：**   
```js    
let dataAbilityPredicates = new dataAbility.DataAbilityPredicates()  dataAbilityPredicates.equalTo("NAME", "Rose")  // EMPLOYEE是使用关系型数据库创建的表。  let predicates = dataAbility.createRdbPredicates("EMPLOYEE", dataAbilityPredicates)    
```    
  
    
## DataAbilityPredicates    
提供用于实现不同查询方法的谓词。  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Core    
### equalTo    
配置谓词以匹配数据类型为ValueType且值等于指定值的字段。  
 **调用形式：**     
- equalTo(field: string, value: ValueType): DataAbilityPredicates  
  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 数据库表中的列名。  |  
| value | ValueType | true | 指示要与谓词匹配的值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DataAbilityPredicates | 返回与指定字段匹配的谓词。 |  
    
 **示例代码：**   
```js    
dataAbilityPredicates.equalTo("NAME", "lisi")    
```    
  
    
### notEqualTo    
配置谓词以匹配数据类型为ValueType且值不等于指定值的字段。  
 **调用形式：**     
- notEqualTo(field: string, value: ValueType): DataAbilityPredicates  
  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 数据库表中的列名。 |  
| value | ValueType | true | 指示要与谓词匹配的值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DataAbilityPredicates | 返回与指定字段匹配的谓词。 |  
    
 **示例代码：**   
```js    
 dataAbilityPredicates.notEqualTo("NAME", "lisi")    
```    
  
    
### beginWrap    
向谓词添加左括号。  
 **调用形式：**     
- beginWrap(): DataAbilityPredicates  
  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DataAbilityPredicates | 返回带有左括号的DataAbility谓词。 |  
    
 **示例代码：**   
```js    
dataAbilityPredicates.equalTo("NAME", "lisi")      .beginWrap()      .equalTo("AGE", 18)      .or()      .equalTo("SALARY", 200.5)      .endWrap()    
```    
  
    
### endWrap    
向谓词添加右括号。  
 **调用形式：**     
- endWrap(): DataAbilityPredicates  
  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DataAbilityPredicates | 返回带有右括号的DataAbility谓词。 |  
    
 **示例代码：**   
```js    
dataAbilityPredicates.equalTo("NAME", "lisi")      .beginWrap()      .equalTo("AGE", 18)      .or()      .equalTo("SALARY", 200.5)      .endWrap()    
```    
  
    
### or    
将或条件添加到谓词中。  
 **调用形式：**     
- or(): DataAbilityPredicates  
  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DataAbilityPredicates | 返回带有或条件的DataAbility谓词。 |  
    
 **示例代码：**   
```js    
dataAbilityPredicates.equalTo("NAME", "Lisa")      .or()      .equalTo("NAME", "Rose")    
```    
  
    
### and    
将和条件添加到谓词中。  
 **调用形式：**     
- and(): DataAbilityPredicates  
  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DataAbilityPredicates | 返回带有和条件的DataAbility谓词。 |  
    
 **示例代码：**   
```js    
dataAbilityPredicates.equalTo("NAME", "Lisa")      .and()      .equalTo("SALARY", 200.5)    
```    
  
    
### contains    
配置谓词以匹配数据类型为string且value包含指定值的字段。  
。  
 **调用形式：**     
- contains(field: string, value: string): DataAbilityPredicates  
  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 数据库表中的列名。 |  
| value | string | true | 指示要与谓词匹配的值。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DataAbilityPredicates | 返回与指定字段匹配的谓词。 |  
    
 **示例代码：**   
```js    
dataAbilityPredicates.contains("NAME", "os")    
```    
  
    
### beginsWith    
配置谓词以匹配数据类型为string且值以指定字符串开头的字段。  
 **调用形式：**     
- beginsWith(field: string, value: string): DataAbilityPredicates  
  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 数据库表中的列名。  |  
| value | string | true | 指示要与谓词匹配的值。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DataAbilityPredicates | 返回与指定字段匹配的谓词。 |  
    
 **示例代码：**   
```js    
dataAbilityPredicates.beginsWith("NAME", "os")    
```    
  
    
### endsWith    
配置谓词以匹配数据类型为string且值以指定字符串结尾的字段。  
 **调用形式：**     
- endsWith(field: string, value: string): DataAbilityPredicates  
  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 数据库表中的列名。  |  
| value | string | true | 指示要与谓词匹配的值。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DataAbilityPredicates | 返回与指定字段匹配的谓词。 |  
    
 **示例代码：**   
```js    
dataAbilityPredicates.endsWith("NAME", "se")    
```    
  
    
### isNull    
配置谓词以匹配值为null的字段。  
 **调用形式：**     
- isNull(field: string): DataAbilityPredicates  
  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 数据库表中的列名。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DataAbilityPredicates | 返回与指定字段匹配的谓词。 |  
    
 **示例代码：**   
```js    
 dataAbilityPredicates.isNull("NAME")    
```    
  
    
### isNotNull    
配置谓词以匹配值不为null的指定字段。  
 **调用形式：**     
- isNotNull(field: string): DataAbilityPredicates  
  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 数据库表中的列名。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DataAbilityPredicates | 返回与指定字段匹配的谓词。 |  
    
 **示例代码：**   
```js    
 dataAbilityPredicates.isNotNull("NAME")    
```    
  
    
### like    
配置谓词以匹配数据类型为string且值类似于指定字符串的字段。  
 **调用形式：**     
- like(field: string, value: string): DataAbilityPredicates  
  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 数据库表中的列名。  |  
| value | string | true | 指示要与谓词匹配的值。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DataAbilityPredicates | 返回与指定字段匹配的谓词。 |  
    
 **示例代码：**   
```js    
 dataAbilityPredicates.like("NAME", "%os%")    
```    
  
    
### glob    
配置谓词以匹配数据类型为string的指定字段。  
 **调用形式：**     
- glob(field: string, value: string): DataAbilityPredicates  
  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 数据库表中的列名。  |  
| value | string | true | 指示要与谓词匹配的值。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DataAbilityPredicates | 返回与指定字段匹配的谓词。 |  
    
 **示例代码：**   
```js    
dataAbilityPredicates.glob("NAME", "?h*g")  
  // 仅可匹配到"name"字段值为“Lisa”   dataAbilityPredicates.glob("NAME", "Lisa")  
  // 仅可以匹配到"name"字段值为“lisa”   dataAbilityPredicates.glob("NAME", "lisa")    
```    
  
    
### between    
配置谓词以匹配数据类型为ValueType且value在指定范围内的指定字段。  
 **调用形式：**     
- between(field: string, low: ValueType, high: ValueType): DataAbilityPredicates  
  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 数据库表中的列名。  |  
| low | ValueType | true | 指示与谓词匹配的最小值。  |  
| high | ValueType | true | 指示与谓词匹配的最大值。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DataAbilityPredicates | 返回与指定字段匹配的谓词。 |  
    
 **示例代码：**   
```js    
dataAbilityPredicates.between("AGE", 10, 50)    
```    
  
    
### notBetween    
配置谓词以匹配数据类型为ValueType且value超出给定范围的指定字段。  
 **调用形式：**     
- notBetween(field: string, low: ValueType, high: ValueType): DataAbilityPredicates  
  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 数据库表中的列名。  |  
| low | ValueType | true | 指示与谓词匹配的最小值。  |  
| high | ValueType | true | 指示与谓词匹配的最大值。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DataAbilityPredicates | 返回与指定字段匹配的谓词。 |  
    
 **示例代码：**   
```js    
dataAbilityPredicates.notBetween("AGE", 10, 50)    
```    
  
    
### greaterThan    
配置谓词以匹配数据类型为ValueType且值大于指定值的字段。  
 **调用形式：**     
- greaterThan(field: string, value: ValueType): DataAbilityPredicates  
  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 数据库表中的列名。  |  
| value | ValueType | true | 指示要与谓词匹配的值。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DataAbilityPredicates | 返回与指定字段匹配的谓词。 |  
    
 **示例代码：**   
```js    
 dataAbilityPredicates.greaterThan("AGE", 18)    
```    
  
    
### lessThan    
配置谓词以匹配数据类型为valueType且value小于指定值的字段。  
 **调用形式：**     
- lessThan(field: string, value: ValueType): DataAbilityPredicates  
  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 数据库表中的列名。  |  
| value | ValueType | true | 指示要与谓词匹配的值。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DataAbilityPredicates | 返回与指定字段匹配的谓词。 |  
    
 **示例代码：**   
```js    
dataAbilityPredicates.lessThan("AGE", 20)    
```    
  
    
### greaterThanOrEqualTo    
配置谓词以匹配数据类型为ValueType且value大于或等于指定值的字段。  
 **调用形式：**     
- greaterThanOrEqualTo(field: string, value: ValueType): DataAbilityPredicates  
  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 数据库表中的列名。  |  
| value | ValueType | true | 指示要与谓词匹配的值。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DataAbilityPredicates | 返回与指定字段匹配的谓词。 |  
    
 **示例代码：**   
```js    
dataAbilityPredicates.greaterThanOrEqualTo("AGE", 18)    
```    
  
    
### lessThanOrEqualTo    
配置谓词以匹配数据类型为ValueType且value小于或等于指定值的字段。  
 **调用形式：**     
- lessThanOrEqualTo(field: string, value: ValueType): DataAbilityPredicates  
  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 数据库表中的列名。  |  
| value | ValueType | true | 指示要与谓词匹配的值。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DataAbilityPredicates | 返回与指定字段匹配的谓词。 |  
    
 **示例代码：**   
```js    
dataAbilityPredicates.lessThanOrEqualTo("AGE", 20)    
```    
  
    
### orderByAsc    
配置谓词以匹配其值按升序排序的列。  
 **调用形式：**     
- orderByAsc(field: string): DataAbilityPredicates  
  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 数据库表中的列名。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DataAbilityPredicates | 返回与指定字段匹配的谓词。 |  
    
 **示例代码：**   
```js    
 // 先按“name”字段排序，相同时按“AGE”字段排序，其次按“SALARY”排序  dataAbilityPredicates.orderByAsc("NAME").orderByAsc("AGE").orderByAsc("SALARY")    
```    
  
    
### orderByDesc    
配置谓词以匹配其值按降序排序的列。  
 **调用形式：**     
- orderByDesc(field: string): DataAbilityPredicates  
  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 数据库表中的列名。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DataAbilityPredicates | 返回与指定字段匹配的谓词。 |  
    
 **示例代码：**   
```js    
 // 优先按“AGE”排序，相同时按“SALARY”排序  dataAbilityPredicates.orderByDesc("AGE").orderByDesc("SALARY")    
```    
  
    
### distinct    
配置谓词以过滤重复记录并仅保留其中一个。  
 **调用形式：**     
- distinct(): DataAbilityPredicates  
  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DataAbilityPredicates | 返回可用于过滤重复记录的谓词。 |  
    
 **示例代码：**   
```js    
dataAbilityPredicates.equalTo("NAME", "Rose").distinct()    
```    
  
    
### limitAs    
设置最大数据记录数的谓词。  
 **调用形式：**     
- limitAs(value: number): DataAbilityPredicates  
  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | number | true | 最大数据记录数。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DataAbilityPredicates | 返回可用于设置最大数据记录数的谓词。 |  
    
 **示例代码：**   
```js    
dataAbilityPredicates.equalTo("NAME", "Rose").limitAs(3)    
```    
  
    
### offsetAs    
配置谓词以指定返回结果的起始位置。  
 **调用形式：**     
- offsetAs(rowOffset: number): DataAbilityPredicates  
  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| rowOffset | number | true | 返回结果的起始位置，取值为正整数。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DataAbilityPredicates | 返回具有指定返回结果起始位置的谓词。 |  
    
 **示例代码：**   
```js    
 // 跳过前三条数据，显示后续三条数据  dataAbilityPredicates.equalTo("NAME", "Rose").offsetAs(3).limitAs(3)    
```    
  
    
### groupBy    
配置谓词按指定列分组查询结果。  
 **调用形式：**     
- groupBy(fields: Array\<string>): DataAbilityPredicates  
  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fields | Array<string> | true | 指定分组依赖的列名。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DataAbilityPredicates | 返回分组查询列的谓词。 |  
    
 **示例代码：**   
```js    
dataAbilityPredicates.groupBy(["AGE", "NAME"])    
```    
  
    
### indexedBy    
配置谓词以指定索引列。  
 **调用形式：**     
- indexedBy(field: string): DataAbilityPredicates  
  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 索引列的名称。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DataAbilityPredicates | 返回具有指定索引列的谓词。 |  
    
 **示例代码：**   
```js    
import rdb from '@ohos.data.rdb'; // 导入模块  import featureAbility from '@ohos.ability.featureAbility';  import dataAbility from '@ohos.data.dataAbility';  
  let context = getContext(this);  
  const STORE_CONFIG : rdb.StoreConfig= {      name: 'RdbTest.db', // 数据库文件名  };  // 表结构：EMPLOYEE (NAME, AGE, SALARY, CODES)  const SQL_CREATE_TABLE = 'CREATE TABLE IF NOT EXISTS EMPLOYEE (ID INTEGER PRIMARY KEY AUTOINCREMENT, NAME TEXT NOT NULL, AGE INTEGER, SALARY REAL, CODES BLOB)'; // 建表Sql语句  rdb.getRdbStore(this.context, STORE_CONFIG, 3, async (err, store) => {    if (err) {      console.error(`Failed to get RdbStore. Code:${err.code}, message:${err.message}`);      return;    }    console.info('Succeeded in getting RdbStore.');  
  
    await store.executeSql(SQL_CREATE_TABLE); // 创建数据表  
  
    // 创建索引    const SQL_CREATE_INDEX = 'CREATE INDEX SALARY_INDEX ON EMPLOYEE(SALARY)'    await store.executeSql(SQL_CREATE_INDEX);    // ...  
    let dataAbilityPredicates = new dataAbility.DataAbilityPredicates()    dataAbilityPredicates.indexedBy("SALARY_INDEX")  
    //  ...  })    
```    
  
    
### in    
配置谓词以匹配数据类型为ValueType数组且值在给定范围内的指定字段。  
 **调用形式：**     
- in(field: string, value: Array\<ValueType>): DataAbilityPredicates  
  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 数据库表中的列名。  |  
| value | Array<ValueType> | true | 以ValueType类型数组形式指定的要匹配的值。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DataAbilityPredicates | 返回与指定字段匹配的谓词。 |  
    
 **示例代码：**   
```js    
dataAbilityPredicates.in("AGE", [18, 20])    
```    
  
    
### notIn    
配置谓词以匹配数据类型为ValueType数组且值不在给定范围内的指定字段。  
 **调用形式：**     
- notIn(field: string, value: Array\<ValueType>): DataAbilityPredicates  
  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 数据库表中的列名。  |  
| value | Array<ValueType> | true | 以ValueType类型数组形式指定的要匹配的值。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DataAbilityPredicates | 返回与指定字段匹配的谓词。 |  
    
 **示例代码：**   
```js    
dataAbilityPredicates.notIn("NAME", ["Lisa", "Rose"])    
```    
  
    
## ValueType    
用于表示允许的数据字段类型。  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Core    
    
| 取值范围 | 说明 |  
| --------| --------|  
| number | 表示值类型为数字。 |  
| string | 表示值类型为字符。 |  
| boolean | 表示值类型为布尔值。 |  
