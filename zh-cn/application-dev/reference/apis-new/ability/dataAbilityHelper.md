# dataAbilityHelper    
可以通过[acquireDataAbilityHelper](js-apis-ability-featureAbility.md#featureabilityacquiredataabilityhelper7)接口获取DataAbilityHelper对象。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## DataAbilityHelper  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.FAModel    
### openFile    
打开指定uri对应的文件，返回文件描述符。  
 **调用形式：**     
    
- openFile(uri: string, mode: string, callback: AsyncCallback\<number>): void    
起始版本： 7    
- openFile(uri: string, mode: string): Promise\<number>    
起始版本： 7  
  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.FAModel    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uri | string | true | 表示待打开文件的uri。 |  
| mode | string | true | 表示文件打开模式，可以设置为‘r’表示只读访问，‘w’表示只写访问，‘rw’表示读写访问等。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 表示文件打开的回调方法，返回文件描述符。 |  
| Promise<number> | 返回文件说明符。 |  
    
 **示例代码1：**   
示例（callback）  
  
```ts    
import ability from '@ohos.ability.ability';  
import featureAbility from '@ohos.ability.featureAbility';  
  
let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(  
    'dataability:///com.example.DataAbility'  
);  
let mode = 'rw';  
DAHelper.openFile('dataability:///com.example.DataAbility', mode, (error, data) => {  
    if (error  error.code !== 0) {  
        console.error(`openFile fail, error: ${JSON.stringify(error)}`);  
    } else {  
        console.log(`openFile success, data: ${JSON.stringify(data)}`);  
    }  
});  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import ability from '@ohos.ability.ability';  
import featureAbility from '@ohos.ability.featureAbility';  
  
let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(  
    'dataability:///com.example.DataAbility'  
);  
let mode = 'rw';  
DAHelper.openFile('dataability:///com.example.DataAbility', mode).then((data) => {  
    console.info(`openFile data: ${JSON.stringify(data)}`);  
});    
```    
  
    
### on('dataChange')    
注册观察者以监听uri指定数据的数据变化通知。  
 **调用形式：**     
    
- on(type: 'dataChange', uri: string, callback: AsyncCallback\<void>): void    
起始版本： 7  
  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.FAModel    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 表示监听操作类型，'dataChange'表示数据变化操作。  |  
| uri | string | true | 表示待监听数据变化的uri。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 表示数据变化时的回调方法。 |  
    
 **示例代码：**   
```ts    
import ability from '@ohos.ability.ability';  
import featureAbility from '@ohos.ability.featureAbility';  
  
let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(  
    'dataability:///com.example.DataAbility'  
);  
function onChangeNotify() {  
    console.info('onChangeNotify call back');  
};  
DAHelper.on(  
    'dataChange',  
    'dataability:///com.example.DataAbility',  
    onChangeNotify  
);    
```    
  
    
### off('dataChange')    
注消观察者以停止监听uri指定数据的数据变化通知。  
 **调用形式：**     
    
- off(type: 'dataChange', uri: string, callback?: AsyncCallback\<void>): void    
起始版本： 7  
  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.FAModel    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 表示监听操作类型，'dataChange'表示数据变化操作。 |  
| uri | string | true | 表示待取消监听数据变化的uri。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 表示已注册的数据变化回调方法。如果设置数据变化回调为空，将会取消所有数据变化监听。 |  
    
 **示例代码：**   
```ts    
import ability from '@ohos.ability.ability';  
import featureAbility from '@ohos.ability.featureAbility';  
  
let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(  
    'dataability:///com.example.DataAbility'  
);  
function onChangeNotify() {  
    console.info('onChangeNotify call back');  
};  
DAHelper.off(  
    'dataChange',  
    'dataability:///com.example.DataAbility',  
    onChangeNotify  
);  
DAHelper.off(  
    'dataChange',  
    'dataability:///com.example.DataAbility',  
);    
```    
  
    
### getType    
获取给定uri指向数据的媒体资源类型。  
 **调用形式：**     
    
- getType(uri: string, callback: AsyncCallback\<string>): void    
起始版本： 7    
- getType(uri: string): Promise\<string>    
起始版本： 7  
  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.FAModel    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uri | string | true | 表示待获取数据的uri。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 表示获取媒体资源类型的回调方法，返回与uri指向数据匹配的媒体资源类型。 |  
| Promise<string> | 返回与uri指向数据匹配的媒体资源类型。 |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import ability from '@ohos.ability.ability';  
import featureAbility from '@ohos.ability.featureAbility';  
  
let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(  
    'dataability:///com.example.DataAbility'  
);  
DAHelper.getType('dataability:///com.example.DataAbility', (error, data) => {  
    if (error  error.code !== 0) {  
        console.error(`getType fail, error: ${JSON.stringify(error)}`);  
    } else {  
        console.log(`getType success, data: ${JSON.stringify(data)}`);  
    }  
});  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import ability from '@ohos.ability.ability';  
import featureAbility from '@ohos.ability.featureAbility';  
  
let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(  
    'dataability:///com.example.DataAbility'  
);  
DAHelper.getType('dataability:///com.example.DataAbility').then((data) => {  
    console.info(`getType data: ${JSON.stringify(data)}`);  
});    
```    
  
    
### getFileTypes    
获取支持的文件媒体资源类型  
 **调用形式：**     
    
- getFileTypes(uri: string, mimeTypeFilter: string, callback: AsyncCallback\<Array\<string>>): void    
起始版本： 7    
- getFileTypes(uri: string, mimeTypeFilter: string): Promise\<Array\<string>>    
起始版本： 7  
  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.FAModel    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uri | string | true | 表示待获取文件的uri。 |  
| mimeTypeFilter | string | true | 表示待获取文件的媒体资源类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 表示获取媒体资源类型的回调方法，返回匹配的媒体资源类型数组。 |  
| Promise<Array<string>> | 返回匹配的媒体资源类型数组。 |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import ability from '@ohos.ability.ability';  
import featureAbility from '@ohos.ability.featureAbility';  
  
let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(  
    'dataability:///com.example.DataAbility'  
);  
DAHelper.getFileTypes( 'dataability:///com.example.DataAbility', 'image/*', (error, data) => {  
    if (error  error.code !== 0) {  
        console.error(`getFileTypes fail, error: ${JSON.stringify(error)}`);  
    } else {  
        console.log(`getFileTypes success, data: ${JSON.stringify(data)}`);  
    }  
});  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import ability from '@ohos.ability.ability';  
import featureAbility from '@ohos.ability.featureAbility';  
  
let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(  
    'dataability:///com.example.DataAbility'  
);  
DAHelper.getFileTypes('dataability:///com.example.DataAbility', 'image/*').then((data) => {  
    console.info(`getFileTypes data: ${JSON.stringify(data)}`);  
});    
```    
  
    
### normalizeUri    
将引用数据功能的给定uri转换为规范化uri  
 **调用形式：**     
    
- normalizeUri(uri: string, callback: AsyncCallback\<string>): void    
起始版本： 7    
- normalizeUri(uri: string): Promise\<string>    
起始版本： 7  
  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.FAModel    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uri | string | true | 表示要规范化的uri对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 表示uri规范化的回调方法。如果数据功能支持uri规范化，则返回规范化uri对象；否则返回null。 |  
| Promise<string> | 如果数据功能支持uri规范化，则返回规范化uri对象；否则返回null。 |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import ability from '@ohos.ability.ability';  
import featureAbility from '@ohos.ability.featureAbility';  
  
let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(  
    'dataability:///com.example.DataAbility'  
);  
DAHelper.normalizeUri('dataability:///com.example.DataAbility', (error, data) => {  
    if (error  error.code !== 0) {  
        console.error(`normalizeUri fail, error: ${JSON.stringify(error)}`);  
    } else {  
        console.log(`normalizeUri success, data: ${JSON.stringify(data)}`);  
    }  
});  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import ability from '@ohos.ability.ability';  
import featureAbility from '@ohos.ability.featureAbility';  
  
let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(  
    'dataability:///com.example.DataAbility'  
);  
DAHelper.normalizeUri('dataability:///com.example.DataAbility',).then((data) => {  
    console.info(`normalizeUri data: ${JSON.stringify(data)}`);  
});    
```    
  
    
### denormalizeUri    
将由normalizeUri（uri）生成的给定规范化uri转换为非规范化uri  
 **调用形式：**     
    
- denormalizeUri(uri: string, callback: AsyncCallback\<string>): void    
起始版本： 7    
- denormalizeUri(uri: string): Promise\<string>    
起始版本： 7  
  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.FAModel    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uri | string | true | 表示要反规范化的uri对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 表示反规范化uri的回调方法。如果反规范化成功，则返回反规范化uri对象。 |  
| Promise<string> | 如果反规范化成功，则返回反规范化uri对象。 |  
    
 **示例代码1：**   
示例（callbak）  
```ts    
import ability from '@ohos.ability.ability';  
import featureAbility from '@ohos.ability.featureAbility';  
  
let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(  
    'dataability:///com.example.DataAbility'  
);  
DAHelper.denormalizeUri('dataability:///com.example.DataAbility', (error, data) => {  
    if (error  error.code !== 0) {  
        console.error(`denormalizeUri fail, error: ${JSON.stringify(error)}`);  
    } else {  
        console.log(`denormalizeUri success, data: ${JSON.stringify(data)}`);  
    }  
});  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import ability from '@ohos.ability.ability';  
import featureAbility from '@ohos.ability.featureAbility';  
  
let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(  
    'dataability:///com.example.DataAbility'  
);  
DAHelper.denormalizeUri('dataability:///com.example.DataAbility',).then((data) => {  
    console.info(`denormalizeUri data: ${JSON.stringify(data)}`);  
});    
```    
  
    
### notifyChange    
通知注册的观察者，uri指定数据的数据变化  
 **调用形式：**     
    
- notifyChange(uri: string, callback: AsyncCallback\<void>): void    
起始版本： 7    
- notifyChange(uri: string): Promise\<void>    
起始版本： 7  
  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.FAModel    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uri | string | true | 表示数据变化的uri。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调方法。 |  
| Promise<void> | 返回值为Promise对象。 |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import ability from '@ohos.ability.ability';  
import featureAbility from '@ohos.ability.featureAbility';  
  
let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(  
    'dataability:///com.example.DataAbility'  
);  
DAHelper.notifyChange('dataability:///com.example.DataAbility', (error) => {  
    if (error  error.code !== 0) {  
        console.error(`notifyChange fail, error: ${JSON.stringify(error)}`);  
    } else {  
        console.log('notifyChange success');  
    }  
});  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import ability from '@ohos.ability.ability';  
import featureAbility from '@ohos.ability.featureAbility';  
  
let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(  
    'dataability:///com.example.DataAbility'  
);  
DAHelper.notifyChange('dataability:///com.example.DataAbility').then(() => {  
    console.info('================>notifyChangeCallback================>');  
});    
```    
  
    
### insert    
将单个数据记录插入数据库  
 **调用形式：**     
    
- insert(uri: string, valuesBucket: rdb.ValuesBucket, callback: AsyncCallback\<number>): void    
起始版本： 7    
- insert(uri: string, valuesBucket: rdb.ValuesBucket): Promise\<number>    
起始版本： 7  
  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.FAModel    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uri | string | true | 表示要插入数据的uri。 |  
| valuesBucket | rdb.ValuesBucket | true | 表示要插入的数据记录。如果此参数为空，将插入一个空行。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 表示数据插入的回调方法，返回插入数据记录的索引。 |  
| Promise<number> | 返回插入数据记录的索引。 |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import ability from '@ohos.ability.ability';  
import featureAbility from '@ohos.ability.featureAbility';  
import rdb from '@ohos.data.rdb';  
  
let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(  
    'dataability:///com.example.DataAbility'  
);  
const valueBucket: rdb.ValuesBucket = {  
    'name': 'rose',  
    'age': 22,  
    'salary': 200.5,  
    'blobType': 'u8',  
};  
DAHelper.insert('dataability:///com.example.DataAbility', valueBucket, (error, data) => {  
    if (error  error.code !== 0) {  
        console.error(`insert fail, error: ${JSON.stringify(error)}`);  
    } else {  
        console.log(`insert success, data: ${JSON.stringify(data)}`);  
    }  
});  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import ability from '@ohos.ability.ability';  
import featureAbility from '@ohos.ability.featureAbility';  
import rdb from '@ohos.data.rdb';  
  
let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(  
    'dataability:///com.example.DataAbility'  
);  
const valueBucket: rdb.ValuesBucket = {  
    'name': 'rose1',  
    'age': 221,  
    'salary': 20.5,  
    'blobType': 'u8',  
};  
DAHelper.insert('dataability:///com.example.DataAbility', valueBucket).then((data) => {  
    console.info(`insert data: ${JSON.stringify(data)}`);  
});    
```    
  
    
### batchInsert    
将多个数据记录插入数据库  
 **调用形式：**     
    
- batchInsert(uri: string, valuesBuckets: Array\<rdb.ValuesBucket>, callback: AsyncCallback\<number>): void    
起始版本： 7    
- batchInsert(uri: string, valuesBuckets: Array\<rdb.ValuesBucket>): Promise\<number>    
起始版本： 7  
  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.FAModel    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uri | string | true | 表示要插入数据的uri。 |  
| valuesBuckets | Array<rdb.ValuesBucket> | true | 表示要插入的数据记录数组。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 表示批量数据插入的回调方法。返回插入的数据记录数。 |  
| Promise<number> | 返回插入的数据记录数。 |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import ability from '@ohos.ability.ability';  
import featureAbility from '@ohos.ability.featureAbility';  
import rdb from '@ohos.data.rdb';  
  
let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(  
    'dataability:///com.example.DataAbility'  
);  
let cars = new Array({'name': 'roe11', 'age': 21, 'salary': 20.5, 'blobType': 'u8',} as rdb.ValuesBucket,  
                     {'name': 'roe12', 'age': 21, 'salary': 20.5, 'blobType': 'u8',} as rdb.ValuesBucket,  
                     {'name': 'roe13', 'age': 21, 'salary': 20.5, 'blobType': 'u8',} as rdb.ValuesBucket);  
DAHelper.batchInsert('dataability:///com.example.DataAbility', cars, (error, data) => {  
    if (error  error.code !== 0) {  
        console.error(`batchInsert fail, error: ${JSON.stringify(error)}`);  
    } else {  
        console.log(`batchInsert success, data: ${JSON.stringify(data)}`);  
    }  
});  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import ability from '@ohos.ability.ability';  
import featureAbility from '@ohos.ability.featureAbility';  
import rdb from '@ohos.data.rdb';  
  
let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(  
    'dataability:///com.example.DataAbility'  
);  
let cars = new Array({'name': 'roe11', 'age': 21, 'salary': 20.5, 'blobType': 'u8',} as rdb.ValuesBucket,  
                     {'name': 'roe12', 'age': 21, 'salary': 20.5, 'blobType': 'u8',} as rdb.ValuesBucket,  
                     {'name': 'roe13', 'age': 21, 'salary': 20.5, 'blobType': 'u8',} as rdb.ValuesBucket);  
DAHelper.batchInsert('dataability:///com.example.DataAbility', cars).then((data) => {  
    console.info(`batchInsert data: ${JSON.stringify(data)}`);  
});    
```    
  
    
### delete    
从数据库中删除一个或多个数据记录  
 **调用形式：**     
    
- delete(uri: string, predicates: dataAbility.DataAbilityPredicates, callback: AsyncCallback\<number>): void    
起始版本： 7    
- delete(uri: string, predicates?: dataAbility.DataAbilityPredicates): Promise\<number>    
起始版本： 7    
- delete(uri: string, callback: AsyncCallback\<number>): void    
起始版本： 7  
  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.FAModel    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uri | string | true | 表示要删除数据的uri。 |  
| predicates | dataAbility.DataAbilityPredicates | true | 表示筛选条件。当此参数为null时，应定义处理逻辑。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 表示数据删除的回调方法。返回已删除的数据记录数。 |  
| Promise<number> | 表示筛选条件。当此参数为null时，应定义处理逻辑。 |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import ability from '@ohos.ability.ability';  
import featureAbility from '@ohos.ability.featureAbility';  
import ohos_data_ability from '@ohos.data.dataAbility';  
  
let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(  
    'dataability:///com.example.DataAbility'  
);  
let da = new ohos_data_ability.DataAbilityPredicates();  
DAHelper.delete('dataability:///com.example.DataAbility', da, (error, data) => {  
    if (error  error.code !== 0) {  
        console.error(`delete fail, error: ${JSON.stringify(error)}`);  
    } else {  
        console.log(`delete success, data: ${JSON.stringify(data)}`);  
    }  
});  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import ability from '@ohos.ability.ability';  
import featureAbility from '@ohos.ability.featureAbility';  
import ohos_data_ability from '@ohos.data.dataAbility';  
  
let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(  
    'dataability:///com.example.DataAbility'  
);  
let da = new ohos_data_ability.DataAbilityPredicates();  
DAHelper.delete('dataability:///com.example.DataAbility', da).then((data) => {  
    console.info(`delete data: ${JSON.stringify(data)}`);  
});    
```    
  
    
### update    
更新数据库中的数据记录  
 **调用形式：**     
    
- update(     uri: string,     valuesBucket: rdb.ValuesBucket,     predicates: dataAbility.DataAbilityPredicates,     callback: AsyncCallback\<number>   ): void    
起始版本： 7    
- update(uri: string, valuesBucket: rdb.ValuesBucket, predicates?: dataAbility.DataAbilityPredicates): Promise\<number>    
起始版本： 7    
- update(uri: string, valuesBucket: rdb.ValuesBucket, callback: AsyncCallback\<number>): void    
起始版本： 7  
  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.FAModel    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uri | string | true | 表示要更新数据的uri。 |  
| valuesBucket | rdb.ValuesBucket | true | 表示要更新的数据。 |  
| predicates | dataAbility.DataAbilityPredicates | true | 表示筛选条件。当此参数为null时，应定义处理逻辑。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 表示数据更新的回调方法，返回更新的数据记录数。 |  
| Promise<number> | Promise中包含更新的数据记录数。 |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import ability from '@ohos.ability.ability';  
import featureAbility from '@ohos.ability.featureAbility';  
import ohos_data_ability from '@ohos.data.dataAbility';  
import rdb from '@ohos.data.rdb';  
  
let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(  
    'dataability:///com.example.DataAbility'  
);  
const va: rdb.ValuesBucket = {  
    'name': 'roe1',  
    'age': 21,  
    'salary': 20.5,  
    'blobType': 'u8',  
};  
let da = new ohos_data_ability.DataAbilityPredicates();  
DAHelper.update('dataability:///com.example.DataAbility', va, da, (error, data) => {  
    if (error  error.code !== 0) {  
        console.error(`update fail, error: ${JSON.stringify(error)}`);  
    } else {  
        console.log(`update success, data: ${JSON.stringify(data)}`);  
    }  
});  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import ability from '@ohos.ability.ability';  
import featureAbility from '@ohos.ability.featureAbility';  
import ohos_data_ability from '@ohos.data.dataAbility';  
import rdb from '@ohos.data.rdb';  
  
let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(  
    'dataability:///com.example.DataAbility'  
);  
const va: rdb.ValuesBucket = {  
    'name': 'roe1',  
    'age': 21,  
    'salary': 20.5,  
    'blobType': 'u8',  
};  
let da = new ohos_data_ability.DataAbilityPredicates();  
DAHelper.update('dataability:///com.example.DataAbility', va, da).then((data) => {  
    console.info(`update data: ${JSON.stringify(data)}`);  
});    
```    
  
    
### query    
查询数据库中的数据  
 **调用形式：**     
    
- query(     uri: string,     columns: Array\<string>,     predicates: dataAbility.DataAbilityPredicates,     callback: AsyncCallback\<ResultSet>   ): void    
起始版本： 7    
- query(uri: string, callback: AsyncCallback\<ResultSet>): void    
起始版本： 7    
- query(uri: string, columns: Array\<string>, callback: AsyncCallback\<ResultSet>): void    
起始版本： 7    
- query(uri: string, predicates: dataAbility.DataAbilityPredicates, callback: AsyncCallback\<ResultSet>): void    
起始版本： 7    
- query(uri: string, columns?: Array\<string>, predicates?: dataAbility.DataAbilityPredicates): Promise\<ResultSet>    
起始版本： 7  
  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.FAModel    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uri | string | true | 表示要查询数据的uri。 |  
| columns | Array<string> | true | 表示要查询的列。如果此参数为空，则查询所有列。 |  
| predicates | dataAbility.DataAbilityPredicates | true | 表示筛选条件。当此参数为null时，应定义处理逻辑。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 表示数据查询的回调方法，返回查询结果。 |  
| Promise<ResultSet> |  |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import ability from '@ohos.ability.ability';  
import featureAbility from '@ohos.ability.featureAbility';  
import ohos_data_ability from '@ohos.data.dataAbility';  
  
let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(  
    'dataability:///com.example.DataAbility'  
);  
let cars=new Array('value1', 'value2', 'value3', 'value4');  
let da = new ohos_data_ability.DataAbilityPredicates();  
DAHelper.query('dataability:///com.example.DataAbility', cars, da, (error, data) => {  
    if (error  error.code !== 0) {  
        console.error(`query fail, error: ${JSON.stringify(error)}`);  
    } else {  
        console.log(`query success, data: ${JSON.stringify(data)}`);  
    }  
});  
    
```    
  
    
 **示例代码2：**   
参数：columns  
```ts    
import ability from '@ohos.ability.ability';  
import featureAbility from '@ohos.ability.featureAbility';  
  
let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(  
    'dataability:///com.example.DataAbility'  
);  
let cars = new Array('value1', 'value2', 'value3', 'value4');  
DAHelper.query('dataability:///com.example.DataAbility', cars, (error, data) => {  
    if (error  error.code !== 0) {  
        console.error(`query fail, error: ${JSON.stringify(error)}`);  
    } else {  
        console.log(`query success, data: ${JSON.stringify(data)}`);  
    }  
});  
    
```    
  
    
 **示例代码3：**   
参数：predicates  
```ts    
import ability from '@ohos.ability.ability';  
import featureAbility from '@ohos.ability.featureAbility';  
import ohos_data_ability from '@ohos.data.dataAbility';  
  
let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(  
    'dataability:///com.example.DataAbility'  
);  
let da = new ohos_data_ability.DataAbilityPredicates();  
DAHelper.query('dataability:///com.example.DataAbility', da, (error, data) => {  
    if (error  error.code !== 0) {  
        console.error(`query fail, error: ${JSON.stringify(error)}`);  
    } else {  
        console.log(`query success, data: ${JSON.stringify(data)}`);  
    }  
});<i></i>  
    
```    
  
    
 **示例代码4：**   
示例（promise）  
```ts    
import ability from '@ohos.ability.ability';  
import featureAbility from '@ohos.ability.featureAbility';  
import ohos_data_ability from '@ohos.data.dataAbility';  
  
let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(  
    'dataability:///com.example.DataAbility'  
);  
let cars = new Array('value1', 'value2', 'value3', 'value4');  
let da = new ohos_data_ability.DataAbilityPredicates();  
DAHelper.query('dataability:///com.example.DataAbility', cars, da).then((data) => {  
    console.info(`query data: ${JSON.stringify(data)}`);  
});    
```    
  
    
### call    
调用DataAbility的扩展接口  
 **调用形式：**     
    
- call(uri: string, method: string, arg: string, extras: PacMap, callback: AsyncCallback\<PacMap>): void    
起始版本： 7    
- call(uri: string, method: string, arg: string, extras: PacMap): Promise\<PacMap>    
起始版本： 7  
  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.FAModel    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uri | string | true | 表示待处理的DataAbility。例：'dataability:///com.example.xxx.xxxx' |  
| method | string | true | 表示被调用的方法名。 |  
| arg | string | true | 表示需传入的参数。 |  
| extras | PacMap | true | 表示扩展的键值对参数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 表示数据操作的回调方法，返回操作结果。 |  
| Promise<PacMap> | 返回操作结果。 |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import ability from '@ohos.ability.ability';  
import featureAbility from '@ohos.ability.featureAbility';  
  
let dataAbilityHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(  
    'dataability:///com.example.jsapidemo.UserDataAbility'  
);  
dataAbilityHelper.call('dataability:///com.example.jsapidemo.UserDataAbility',  
    'method', 'arg', {'key1':'value1'}, (error, data) => {  
    if (error  error.code !== 0) {  
        console.error(`call fail, error: ${JSON.stringify(error)}`);  
    } else {  
        console.log(`call success, data: ${JSON.stringify(data)}`);  
    }  
});  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import ability from '@ohos.ability.ability';  
import featureAbility from '@ohos.ability.featureAbility';  
import { BusinessError } from '@ohos.base';  
  
let dataAbilityHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(  
    'dataability:///com.example.jsapidemo.UserDataAbility'  
);  
dataAbilityHelper.call('dataability:///com.example.jsapidemo.UserDataAbility',  
    'method', 'arg', {'key1':'value1'}).then((data) => {  
    console.info('call success, data: ${data}');  
}).catch((error: BusinessError) => {  
    console.error('call failed, error: ${error}');  
});  
    
```    
  
    
### executeBatch    
批量操作数据库中的数据。  
 **调用形式：**     
    
- executeBatch(     uri: string,     operations: Array\<DataAbilityOperation>,     callback: AsyncCallback\<Array\<DataAbilityResult>>   ): void    
起始版本： 7    
- executeBatch(uri: string, operations: Array\<DataAbilityOperation>): Promise\<Array\<DataAbilityResult>>    
起始版本： 7  
  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.FAModel    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uri | string | true | 表示待处理的DataAbility。例：'dataability:///com.example.xxx.xxxx'。 |  
| operations | Array<DataAbilityOperation> | true | 表示数据操作数组，其中可以包含对数据库的多个不同操作。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 表示批量操作的回调方法，在DataAbilityResult数组中返回每个操作的结果。 |  
| Promise<Array<DataAbilityResult>> | 在DataAbilityResult数组中返回每个操作的结果。 |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import ability from '@ohos.ability.ability';  
import featureAbility from '@ohos.ability.featureAbility';  
  
// 根据DataAbilityOperation列表选择要对数据库做的操作  
let op: Array<ability.DataAbilityOperation> = new Array();  
let dataAbilityHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(  
    'dataability:///com.example.jsapidemo.UserDataAbility'  
);  
dataAbilityHelper.executeBatch('dataability:///com.example.jsapidemo.UserDataAbility', op, (error, data) => {  
    if (error  error.code !== 0) {  
        console.error(`executeBatch fail, error: ${JSON.stringify(error)}`);  
    } else {  
        console.log(`executeBatch success, data: ${JSON.stringify(data)}`);  
    }  
});  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import ability from '@ohos.ability.ability';  
import featureAbility from '@ohos.ability.featureAbility';  
import { BusinessError } from '@ohos.base';  
  
// 根据DataAbilityOperation列表选择要对数据库做的操作  
let op: Array<ability.DataAbilityOperation> = new Array();  
let dataAbilityHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(  
    'dataability:///com.example.jsapidemo.UserDataAbility'  
);  
dataAbilityHelper.executeBatch('dataability:///com.example.jsapidemo.UserDataAbility', op).then((data) => {  
    console.info('executeBatch success, data: ${data}');  
}).catch((error: BusinessError) => {  
    console.error('executeBatch failed, error: ${error}');  
});  
    
```    
  
    
## PacMap  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.FAModel  
