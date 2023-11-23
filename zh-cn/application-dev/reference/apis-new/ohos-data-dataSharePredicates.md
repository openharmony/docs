# @ohos.data.dataSharePredicates    
**谓词(DataSharePredicates)** 是开发者通过DataShare查询数据库中的数据所使用的筛选条件，经常被应用在更新数据([update](js-apis-data-dataShare.md#update))、删除数据([delete](js-apis-data-dataShare.md#delete))和查询数据([query](js-apis-data-dataShare.md#query))中。  
  
谓词的接口函数与数据库的筛选条件一一对应，开发者在使用前需了解数据库相关知识。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import dataSharePredicates from '@ohos.data.dataSharePredicates'    
```  
    
## DataSharePredicates    
提供用于不同实现不同查询方法的数据共享谓词。该类型不是多线程安全的，如果应用中存在多线程同时操作该类派生出的实例，注意加锁保护。  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Core    
### equalTo    
该接口用于配置谓词以匹配值等于指定值的字段。  
  
目前仅RDB及KVDB(schema)支持该谓词。  
 **调用形式：**     
- equalTo(field: string, value: ValueType): DataSharePredicates  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 数据库表中的列名。 |  
| value | ValueType | true | 指示要与谓词匹配的值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DataSharePredicates | 返回与指定字段匹配的谓词。 |  
    
 **示例代码：**   
示例：  
```ts    
let predicates = new dataSharePredicates.DataSharePredicates()  
predicates.equalTo("NAME", "Rose")    
```    
  
    
### and    
该接口用于将和条件添加到谓词中。  
  
目前仅RDB及KVDB(schema)支持该谓词。  
 **调用形式：**     
- and(): DataSharePredicates  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DataSharePredicates | 返回带有和条件的谓词。 |  
    
 **示例代码：**   
示例：  
```ts    
let predicates = new dataSharePredicates.DataSharePredicates()  
predicates.equalTo("NAME", "lisi")  
    .and()  
    .equalTo("SALARY", 200.5)    
```    
  
    
### orderByAsc    
该接口用于配置谓词以匹配其值按升序排序的列。  
  
目前仅RDB及KVDB(schema)支持该谓词。  
 **调用形式：**     
- orderByAsc(field: string): DataSharePredicates  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 数据库表中的列名。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DataSharePredicates | 返回与指定字段匹配的谓词。 |  
    
 **示例代码：**   
示例：  
```ts    
let predicates = new dataSharePredicates.DataSharePredicates()  
predicates.orderByAsc("AGE")    
```    
  
    
### orderByDesc    
该接口用于配置谓词以匹配其值按降序排序的列。  
  
目前仅RDB及KVDB(schema)支持该谓词。  
 **调用形式：**     
- orderByDesc(field: string): DataSharePredicates  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 数据库表中的列名。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DataSharePredicates | 返回与指定字段匹配的谓词。 |  
    
 **示例代码：**   
示例：  
```ts    
let predicates = new dataSharePredicates.DataSharePredicates()  
predicates.orderByDesc("AGE")    
```    
  
    
### limit    
该接口用于配置谓词以指定结果数和起始位置。  
  
目前仅RDB及KVDB(schema)支持该谓词。  
 **调用形式：**     
- limit(total: number, offset: number): DataSharePredicates  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| total | number | true | 指定结果数。 |  
| offset | number | true | 指示起始位置。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DataSharePredicates | 返回与指定字段匹配的谓词。 |  
    
 **示例代码：**   
示例：  
```ts    
let predicates = new dataSharePredicates.DataSharePredicates()  
predicates.equalTo("NAME", "Rose").limit(10, 3)    
```    
  
    
### in    
该接口用于配置谓词以匹配值在指范围内的字段。  
  
目前仅RDB及KVDB(schema)支持该谓词。  
 **调用形式：**     
- in(field: string, value: Array\<ValueType>): DataSharePredicates  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 数据库表中的列名。 |  
| value | Array<ValueType> | true | 以ValueType型数组形式指定的要匹配的值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DataSharePredicates | 返回与指定字段匹配的谓词。 |  
    
 **示例代码：**   
示例：  
```ts    
let predicates = new dataSharePredicates.DataSharePredicates()  
predicates.in("AGE", [18, 20])    
```    
  
