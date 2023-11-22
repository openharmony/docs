# resultSet    
结果集是指用户调用关系型数据库查询接口之后返回的结果集合，提供了多种灵活的数据访问方式，以便用户获取各项数据。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## ResultSet<sup>(deprecated)</sup>    
提供通过查询数据库生成的数据库结果集的访问方法。  
    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.relationalStore.ResultSet替代。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
### 属性    
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| columnNames<sup>(deprecated)</sup> | Array<string> | false | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.relationalStore.ResultSet.columnNames替代。<br>获取结果集中所有列的名称。<br/> |  
| columnCount<sup>(deprecated)</sup> | number | false | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.relationalStore.ResultSet.columnCount替代。<br>获取结果集中的列数。<br/> |  
| rowCount<sup>(deprecated)</sup> | number | false | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.relationalStore.ResultSet.rowCount替代。<br>获取结果集中的行数。<br/> |  
| rowIndex<sup>(deprecated)</sup> | number | false | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.relationalStore.ResultSet.rowIndex替代。<br>获取结果集当前行的索引。<br/> |  
| isAtFirstRow<sup>(deprecated)</sup> | boolean | false | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.relationalStore.ResultSet.isAtFirstRow替代。<br>检查结果集是否位于第一行。<br/> |  
| isAtLastRow<sup>(deprecated)</sup> | boolean | false | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.relationalStore.ResultSet.isAtLastRow替代。<br>检查结果集是否位于最后一行。<br/> |  
| isEnded<sup>(deprecated)</sup> | boolean | false | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.relationalStore.ResultSet.isEnded替代。<br>检查结果集是否位于最后一行之后。<br/> |  
| isStarted<sup>(deprecated)</sup> | boolean | false | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.relationalStore.ResultSet.isStarted替代。<br>检查指针是否移动过。<br/> |  
| isClosed<sup>(deprecated)</sup> | boolean | false | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.relationalStore.ResultSet.isClosed替代。<br>检查当前结果集是否关闭。<br/> |  
    
### getColumnIndex<sup>(deprecated)</sup>    
根据指定的列名获取列索引。  
 **调用形式：**     
- getColumnIndex(columnName: string): number  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.ResultSet.getColumnIndex。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| columnName<sup>(deprecated)</sup> | string | true | 表示结果集中指定列的名称。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回指定列的索引。 |  
    
 **示例代码：**   
```ts    
resultSet.goToFirstRow();  
const id = resultSet.getLong(resultSet.getColumnIndex("ID"));  
const name = resultSet.getString(resultSet.getColumnIndex("NAME"));  
const age = resultSet.getLong(resultSet.getColumnIndex("AGE"));  
const salary = resultSet.getDouble(resultSet.getColumnIndex("SALARY"));    
```    
  
    
### getColumnName<sup>(deprecated)</sup>    
根据指定的列索引获取列名。  
 **调用形式：**     
- getColumnName(columnIndex: number): string  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.ResultSet.getColumnName。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| columnIndex<sup>(deprecated)</sup> | number | true | 表示结果集中指定列的索引。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回指定列的名称。 |  
    
 **示例代码：**   
```ts    
const id = resultSet.getColumnName(0);  
const name = resultSet.getColumnName(1);  
const age = resultSet.getColumnName(2);    
```    
  
    
### goTo<sup>(deprecated)</sup>    
向前或向后转至结果集的指定行，相对于其当前位置偏移。  
 **调用形式：**     
- goTo(offset: number): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.ResultSet.goTo。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| offset<sup>(deprecated)</sup> | number | true | 表示相对于当前位置的偏移量。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 如果成功移动结果集，则为true；否则返回false。 |  
    
 **示例代码：**   
```ts    
let predicatesgoto = new dataRdb.RdbPredicates("EMPLOYEE");  
let promisequerygoto = rdbStore.query(predicatesgoto, ["ID", "NAME", "AGE", "SALARY", "CODES"]);  
promisequerygoto.then((resultSet) => {  
    resultSet.goTo(1);  
    resultSet.close();  
}).catch((err) => {  
    console.log('query failed');  
});    
```    
  
    
### goToRow<sup>(deprecated)</sup>    
转到结果集的指定行。  
 **调用形式：**     
- goToRow(position: number): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.ResultSet.goToRow。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| position<sup>(deprecated)</sup> | number | true | 表示要移动到的指定位置。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 如果成功移动结果集，则为true；否则返回false。 |  
    
 **示例代码：**   
```ts    
let predicatesgotorow = new dataRdb.RdbPredicates("EMPLOYEE");  
let promisequerygotorow = rdbStore.query(predicatesgotorow, ["ID", "NAME", "AGE", "SALARY", "CODES"]);  
promisequerygotorow.then((resultSet) => {  
    resultSet.goToRow(5);  
    resultSet.close();  
}).catch((err) => {  
    console.log('query failed');  
});    
```    
  
    
### goToFirstRow<sup>(deprecated)</sup>    
转到结果集的第一行。  
 **调用形式：**     
- goToFirstRow(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.ResultSet.goToFirstRow。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 如果成功移动结果集，则为true；否则返回false。 |  
    
 **示例代码：**   
```ts    
let predicatesgoFirst = new dataRdb.RdbPredicates("EMPLOYEE");  
let promisequerygoFirst = rdbStore.query(predicatesgoFirst, ["ID", "NAME", "AGE", "SALARY", "CODES"]);  
promisequerygoFirst.then((resultSet) => {  
    resultSet.goToFirstRow();  
    resultSet.close();  
}).catch((err) => {  
    console.log('query failed');  
});    
```    
  
    
### goToLastRow<sup>(deprecated)</sup>    
转到结果集的最后一行。  
 **调用形式：**     
- goToLastRow(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.ResultSet.goToLastRow。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 如果成功移动结果集，则为true；否则返回false。 |  
    
 **示例代码：**   
```ts    
let predicatesgoLast = new dataRdb.RdbPredicates("EMPLOYEE");  
let promisequerygoLast = rdbStore.query(predicatesgoLast, ["ID", "NAME", "AGE", "SALARY", "CODES"]);  
promisequerygoLast.then((resultSet) => {  
    resultSet.goToLastRow();  
    resultSet.close();  
}).catch((err) => {  
    console.log('query failed');  
});    
```    
  
    
### goToNextRow<sup>(deprecated)</sup>    
转到结果集的下一行。  
 **调用形式：**     
- goToNextRow(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.ResultSet.goToNextRow。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 如果成功移动结果集，则为true；否则返回false。 |  
    
 **示例代码：**   
```ts    
let predicatesgoNext = new dataRdb.RdbPredicates("EMPLOYEE");  
let promisequerygoNext = rdbStore.query(predicatesgoNext, ["ID", "NAME", "AGE", "SALARY", "CODES"]);  
promisequerygoNext.then((resultSet) => {  
    resultSet.goToNextRow();  
    resultSet.close();  
}).catch((err) => {  
    console.log('query failed');  
});    
```    
  
    
### goToPreviousRow<sup>(deprecated)</sup>    
转到结果集的上一行。  
 **调用形式：**     
- goToPreviousRow(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.ResultSet.goToPreviousRow。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 如果成功移动结果集，则为true；否则返回false。 |  
    
 **示例代码：**   
```ts    
let predicatesgoPrev = new dataRdb.RdbPredicates("EMPLOYEE");  
let promisequerygoPrev = rdbStore.query(predicatesgoPrev, ["ID", "NAME", "AGE", "SALARY", "CODES"]);  
promisequerygoPrev.then((resultSet) => {  
    resultSet.goToPreviousRow();  
    resultSet.close();  
}).catch((err) => {  
    console.log('query failed');  
});    
```    
  
    
### getBlob<sup>(deprecated)</sup>    
以字节数组的形式获取当前行中指定列的值。  
 **调用形式：**     
- getBlob(columnIndex: number): Uint8Array  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.ResultSet.getBlob。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| columnIndex<sup>(deprecated)</sup> | number | true | 指定的列索引，从0开始。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Uint8Array | 以字节数组的形式返回指定列的值。 |  
    
 **示例代码：**   
```ts    
const codes = resultSet.getBlob(resultSet.getColumnIndex("CODES"));    
```    
  
    
### getString<sup>(deprecated)</sup>    
以字符串形式获取当前行中指定列的值。  
 **调用形式：**     
- getString(columnIndex: number): string  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.ResultSet.getString。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| columnIndex<sup>(deprecated)</sup> | number | true | 指定的列索引，从0开始。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 以字符串形式返回指定列的值。 |  
    
 **示例代码：**   
```ts    
const name = resultSet.getString(resultSet.getColumnIndex("NAME"));    
```    
  
    
### getLong<sup>(deprecated)</sup>    
以Long形式获取当前行中指定列的值。  
 **调用形式：**     
- getLong(columnIndex: number): number  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.ResultSet.getLong。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| columnIndex<sup>(deprecated)</sup> | number | true | 指定的列索引，从0开始。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 以Long形式返回指定列的值。 该接口支持的数据范围是：Number.MIN_SAFE_INTEGER ~ Number.MAX_SAFE_INTEGER，若超出该范围，建议使用getDouble。 |  
    
 **示例代码：**   
```ts    
const age = resultSet.getLong(resultSet.getColumnIndex("AGE"));    
```    
  
    
### getDouble<sup>(deprecated)</sup>    
以double形式获取当前行中指定列的值。  
 **调用形式：**     
- getDouble(columnIndex: number): number  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.ResultSet.getDouble。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| columnIndex<sup>(deprecated)</sup> | number | true | 指定的列索引，从0开始。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 以double形式返回指定列的值。 |  
    
 **示例代码：**   
```ts    
const salary = resultSet.getDouble(resultSet.getColumnIndex("SALARY"));    
```    
  
    
### isColumnNull<sup>(deprecated)</sup>    
检查当前行中指定列的值是否为null。  
 **调用形式：**     
- isColumnNull(columnIndex: number): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.ResultSet.isColumnNull。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| columnIndex<sup>(deprecated)</sup> | number | true | 指定的列索引，从0开始。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 如果当前行中指定列的值为null，则返回true，否则返回false。 |  
    
 **示例代码：**   
```ts    
const isColumnNull = resultSet.isColumnNull(resultSet.getColumnIndex("CODES"));    
```    
  
    
### close<sup>(deprecated)</sup>    
关闭结果集。  
 **调用形式：**     
- close(): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.ResultSet.close。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **示例代码：**   
```ts    
let predicatesClose = new dataRdb.RdbPredicates("EMPLOYEE");  
let promiseClose = rdbStore.query(predicatesClose, ["ID", "NAME", "AGE", "SALARY", "CODES"]);  
promiseClose.then((resultSet) => {  
    resultSet.close();  
}).catch((err) => {  
    console.log('resultset close failed');  
});    
```    
  
