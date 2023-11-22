# @ohos.data.distributedKVStore    
分布式键值数据库为应用程序提供不同设备间数据库的分布式协同能力。通过调用分布式键值数据库各个接口，应用程序可将数据保存到分布式键值数据库中，并可对分布式键值数据库中的数据进行增加、删除、修改、查询、同步等操作。  
  
该模块提供以下分布式键值数据库相关的常用功能：  
  
- [KVManager](#kvmanager)：分布式键值数据库管理实例，用于获取数据库的相关信息。  
- [KVStoreResultSet](#kvstoreresultset)：提供获取数据库结果集的相关方法，包括查询和移动数据读取位置等。  
- [Query](#query)：使用谓词表示数据库查询，提供创建Query实例、查询数据库中的数据和添加谓词的方法。  
- [SingleKVStore](#singlekvstore)：单版本分布式键值数据库，不对数据所属设备进行区分，提供查询数据和同步数据的方法。  
- [DeviceKVStore](#devicekvstore)：设备协同数据库，继承自[SingleKVStore](#singlekvstore)，以设备维度对数据进行区分，提供查询数据和同步数据的方法。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import distributedKVStore from '@ohos.data.distributedKVStore'    
```  
    
## KVManagerConfig    
提供KVManager实例的配置信息，包括调用方的包名和应用的上下文。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
### 属性    
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| bundleName | string | false | true | 调用方的包名。                                                |  
| context | BaseContext | false | true | 应用的上下文。 <br>FA模型的应用Context定义见[Context](js-apis-inner-app-context.md)。<br>Stage模型的应用Context定义见[Context](js-apis-inner-application-uiAbilityContext.md)。<br>从API version 10开始，context的参数类型为[BaseContext](js-apis-inner-application-baseContext.md)。  |  
    
## Constants    
分布式键值数据库常量。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
### 属性    
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| MAX_KEY_LENGTH | number | true | true | 数据库中Key允许的最大长度，单位字节。    |  
| MAX_VALUE_LENGTH | number | true | true | 数据库中Value允许的最大长度，单位字节。  |  
| MAX_KEY_LENGTH_DEVICE | number | true | true | 设备协同数据库中key允许的最大长度，单位字节。  |  
| MAX_STORE_ID_LENGTH | number | true | true | 数据库标识符允许的最大长度，单位字节。   |  
| MAX_QUERY_LENGTH | number | true | true | 最大查询长度，单位字节。                 |  
| MAX_BATCH_SIZE | number | true | true | 最大批处理操作数量。                     |  
    
## ValueType    
数据类型枚举。    
    
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| STRING | 0 | 表示值类型为字符串。    |  
| INTEGER | 1 | 表示值类型为整数。      |  
| FLOAT | 2 | 表示值类型为浮点数。    |  
| BYTE_ARRAY | 3 | 表示值类型为字节数组。  |  
| BOOLEAN | 4 | 表示值类型为布尔值。    |  
| DOUBLE | 5 | 表示值类型为双浮点数。  |  
    
## Value    
存储在数据库中的值对象。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
### 属性    
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| type | ValueType | false | true | 值类型。    |  
| value | Uint8Array \| string \| number \| boolean | false | true | 值。    |  
    
## Entry    
存储在数据库中的键值对。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
### 属性    
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| key | string | false | true | 键值。    |  
| value | Value | false | true | 值对象。  |  
    
## ChangeNotification    
数据变更时通知的对象，包括数据插入的数据、更新的数据、删除的数据和设备ID。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
### 属性    
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| insertEntries | Entry[] | false | true | 数据添加记录。 |  
| updateEntries | Entry[] | false | true | 数据更新记录。 |  
| deleteEntries | Entry[] | false | true | 数据删除记录。 |  
| deviceId | string | false | true | 设备ID，此处为设备UUID。 |  
    
## SyncMode    
同步模式枚举。    
    
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| PULL_ONLY | 0 | 表示只能从远端拉取数据到本端。 |  
| PUSH_ONLY | 1 | 表示只能从本端推送数据到远端。 |  
| PUSH_PULL | 2 | 表示从本端推送数据到远端，然后从远端拉取数据到本端。 |  
    
## SubscribeType    
订阅类型枚举。    
    
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| SUBSCRIBE_TYPE_LOCAL | 0 | 表示订阅本地数据变更。 |  
| SUBSCRIBE_TYPE_REMOTE | 1 | 表示订阅远端数据变更。 |  
| SUBSCRIBE_TYPE_ALL | 2 | 表示订阅远端和本地数据变更。 |  
    
## KVStoreType    
分布式键值数据库类型枚举。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| DEVICE_COLLABORATION | 0 | 系统能力：SystemCapability.DistributedDataManager.KVStore.DistributedKVStore<br>表示多设备协同数据库。<br> **数据库特点：** 数据以设备的维度管理，不存在冲突；支持按照设备的维度查询数据。<br>**系统能力：** SystemCapability.DistributedDataManager.KVStore.DistributedKVStore |  
| SINGLE_VERSION | 1 | 系统能力：SystemCapability.DistributedDataManager.KVStore.Core<br>表示单版本数据库。<br> **数据库特点：** 数据不分设备，设备之间修改相同的key会覆盖。 <br>**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core |  
    
## SecurityLevel    
数据库的安全级别枚举。    
    
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| S1 | 0 | 表示数据库的安全级别为低级别，数据的泄露、篡改、破坏、销毁可能会给个人或组织导致有限的不利影响。<br>例如，性别、国籍，用户申请记录等。 |  
| S2 | 1 | 表示数据库的安全级别为中级别，数据的泄露、篡改、破坏、销毁可能会给个人或组织导致严重的不利影响。<br>例如，个人详细通信地址，姓名昵称等。 |  
| S3 | 2 | 表示数据库的安全级别为高级别，数据的泄露、篡改、破坏、销毁可能会给个人或组织导致严峻的不利影响。<br>例如，个人实时精确定位信息、运动轨迹等。 |  
| S4 | 3 | 表示数据库的安全级别为关键级别，业界法律法规中定义的特殊数据类型，涉及个人的最私密领域的信息或者一旦泄露、篡改、破坏、销毁可能会给个人或组织造成重大的不利影响数据。<br>例如，政治观点、宗教、和哲学信仰、工会成员资格、基因数据、生物信息、健康和性生活状况、性取向等或设备认证鉴权、个人的信用卡等财务信息。 |  
    
## Options    
用于提供创建数据库的配置信息。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
### 属性    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| createIfMissing | boolean | false | false | 系统能力：SystemCapability.DistributedDataManager.KVStore.Core<br>当数据库文件不存在时是否创建数据库，默认为true，即创建。<br>**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core |  
| encrypt | boolean | false | false | 系统能力：SystemCapability.DistributedDataManager.KVStore.Core<br>设置数据库文件是否加密，默认为false，即不加密。<br>**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core |  
| backup | boolean | false | false | 系统能力：SystemCapability.DistributedDataManager.KVStore.Core<br>设置数据库文件是否备份，默认为true，即备份。 <br>**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core |  
| autoSync | boolean | false | false | 需要权限：ohos.permission.DISTRIBUTED_DATASYNC系统能力：SystemCapability.DistributedDataManager.KVStore.Core<br>设置数据库文件是否自动同步。默认为false，即手动同步。<br>**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core<br>**需要权限**： ohos.permission.DISTRIBUTED_DATASYNC。 |  
| kvStoreType | KVStoreType | false | false | 系统能力：SystemCapability.DistributedDataManager.KVStore.Core<br>设置要创建的数据库类型，默认为DEVICE_COLLABORATION，即多设备协同数据库。<br>**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core |  
| securityLevel | SecurityLevel | false | true | 系统能力：SystemCapability.DistributedDataManager.KVStore.Core<br>设置数据库安全级别。<br>**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core |  
| schema | Schema | false | false | 系统能力：SystemCapability.DistributedDataManager.KVStore.DistributedKVStore<br>设置定义存储在数据库中的值，默认为undefined，即不使用Schema。<br>**系统能力：** SystemCapability.DistributedDataManager.KVStore.DistributedKVStore |  
    
## Schema    
表示数据库模式，可以在创建或打开数据库时创建Schema对象并将它们放入  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.DistributedKVStore    
### 属性    
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.DistributedKVStore    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| root | FieldNode | false | true | 表示json根对象。 |  
| indexes | Array<string> | false | true | 表示json类型的字符串数组。 |  
| mode | number | false | true | 表示Schema的模式。 |  
| skip | number | false | true | Schema的跳跃大小。 |  
    
## FieldNode    
表示 Schema 实例的节点，提供定义存储在数据库中的值的方法。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.DistributedKVStore    
### 属性    
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.DistributedKVStore    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| default | string | false | true | 表示Fieldnode的默认值。 |  
| nullable | boolean | false | true | 表示数据库字段是否可以为空。 |  
| type | number | false | true | 表示指定节点对应数据类型的值。 |  
    
### appendChild    
在当前 FieldNode 中添加一个子节点。  
 **调用形式：**     
- appendChild(child: FieldNode): boolean  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.DistributedKVStore    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| child | FieldNode | true | 要附加的域节点。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
try {  
  let node: distributedKVStore.FieldNode | null = new distributedKVStore.FieldNode("root");  
  let child1: distributedKVStore.FieldNode | null = new distributedKVStore.FieldNode("child1");  
  let child2: distributedKVStore.FieldNode | null = new distributedKVStore.FieldNode("child2");  
  let child3: distributedKVStore.FieldNode | null = new distributedKVStore.FieldNode("child3");  
  node.appendChild(child1);  
  node.appendChild(child2);  
  node.appendChild(child3);  
  console.info("appendNode " + JSON.stringify(node));  
  child1 = null;  
  child2 = null;  
  child3 = null;  
  node = null;  
} catch (e) {  
  console.error("AppendChild " + e);  
}  
    
```    
  
    
## KVStoreResultSet    
提供获取数据库结果集的相关方法，包括查询和移动数据读取位置等。同时允许打开的结果集的最大数量为8个。  
在调用KVStoreResultSet的方法前，需要先通过[getKVStore](#getkvstore)构建一个SingleKVStore或者DeviceKVStore实例。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
### getCount    
获取结果集中的总行数。  
 **调用形式：**     
- getCount(): number  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回数据的总行数。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let resultSet: distributedKVStore.KVStoreResultSet;  
  let count: number;  
  kvStore.getResultSet('batch_test_string_key').then((result) => {  
    console.info('getResultSet succeed.');  
    resultSet = result;  
    count = resultSet.getCount();  
    console.info("getCount succeed:" + count);  
  }).catch((err: BusinessError) => {  
    console.error('getResultSet failed: ' + err);  
  });  
} catch (e) {  
  console.error("getCount failed: " + e);  
}  
    
```    
  
    
### getPosition    
获取结果集中当前的读取位置。读取位置会因[moveToFirst](#movetofirst)、[moveToLast](#movetolast)等操作而发生变化。  
 **调用形式：**     
- getPosition(): number  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回当前读取位置。取值范围>= -1，值为 -1 时表示还未开始读取，值为 0 时表示第一行。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let resultSet: distributedKVStore.KVStoreResultSet;  
  let position: number;  
  kvStore.getResultSet('batch_test_string_key').then((result) => {  
    console.info('getResultSet succeeded.');  
    resultSet = result;  
    position = resultSet.getPosition();  
    console.info("getPosition succeed:" + position);  
  }).catch((err: BusinessError) => {  
    console.error('getResultSet failed: ' + err);  
  });  
} catch (e) {  
  console.error("getPosition failed: " + e);  
}  
    
```    
  
    
### moveToFirst    
将读取位置移动到第一行。如果结果集为空，则返回false。  
 **调用形式：**     
- moveToFirst(): boolean  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true表示操作成功；返回false则表示操作失败。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let resultSet: distributedKVStore.KVStoreResultSet;  
  let moved: boolean;  
  kvStore.getResultSet('batch_test_string_key').then((result) => {  
    console.info('getResultSet succeed.');  
    resultSet = result;  
    moved = resultSet.moveToFirst();  
    console.info("moveToFirst succeed: " + moved);  
  }).catch((err: BusinessError) => {  
    console.error('getResultSet failed: ' + err);  
  });  
} catch (e) {  
  console.error("moveToFirst failed " + e);  
}  
    
```    
  
    
### moveToLast    
将读取位置移动到最后一行。如果结果集为空，则返回false。  
 **调用形式：**     
- moveToLast(): boolean  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true表示操作成功；返回false则表示操作失败。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let resultSet: distributedKVStore.KVStoreResultSet;  
  let moved: boolean;  
  kvStore.getResultSet('batch_test_string_key').then((result) => {  
    console.info('getResultSet succeed.');  
    resultSet = result;  
    moved = resultSet.moveToLast();  
    console.info("moveToLast succeed:" + moved);  
  }).catch((err: BusinessError) => {  
    console.error('getResultSet failed: ' + err);  
  });  
} catch (e) {  
  console.error("moveToLast failed: " + e);  
}  
    
```    
  
    
### moveToNext    
将读取位置移动到下一行。如果结果集为空，则返回false。适用于全量获取数据库结果集的场景。  
 **调用形式：**     
- moveToNext(): boolean  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true表示操作成功；返回false则表示操作失败。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let resultSet: distributedKVStore.KVStoreResultSet;  
  let moved: boolean;  
  kvStore.getResultSet('batch_test_string_key').then((result) => {  
    console.info('getResultSet succeed.');  
    resultSet = result;  
    do {  
      moved = resultSet.moveToNext();  
      const entry = resultSet.getEntry();  
      console.info("moveToNext succeed: " + moved);  
    } while (moved)  
  }).catch((err: BusinessError) => {  
    console.error('getResultSet failed: ' + err);  
  });  
} catch (e) {  
  console.error("moveToNext failed: " + e);  
}  
    
```    
  
    
### moveToPrevious    
将读取位置移动到上一行。如果结果集为空，则返回false。适用于全量获取数据库结果集的场景。  
 **调用形式：**     
- moveToPrevious(): boolean  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true表示操作成功；返回false则表示操作失败。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let resultSet: distributedKVStore.KVStoreResultSet;  
  let moved: boolean;  
  kvStore.getResultSet('batch_test_string_key').then((result) => {  
    console.info('getResultSet succeed.');  
    resultSet = result;  
    moved = resultSet.moveToLast();  
    moved = resultSet.moveToPrevious();  
    console.info("moveToPrevious succeed:" + moved);  
  }).catch((err: BusinessError) => {  
    console.error('getResultSet failed: ' + err);  
  });  
} catch (e) {  
  console.error("moveToPrevious failed: " + e);  
}  
    
```    
  
    
### move    
将读取位置移动到当前位置的相对偏移量。即当前游标位置向下偏移 offset 行。  
 **调用形式：**     
- move(offset: number): boolean  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| offset | number | true | 表示与当前位置的相对偏移量，负偏移表示向后移动，正偏移表示向前移动。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true表示操作成功；返回false则表示操作失败。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let resultSet: distributedKVStore.KVStoreResultSet;  
  let moved: boolean;  
  kvStore.getResultSet('batch_test_string_key').then((result) => {  
    console.info('Succeeded in getting resultSet');  
    resultSet = result;  
    moved = resultSet.move(2); //若当前位置为0，将读取位置从绝对位置为0的位置移动2行，即移动到绝对位置为2，行数为3的位置  
    console.info(`Succeeded in moving.moved = ${moved}`);  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to get resultSet.code is ${err.code},message is ${err.message}`);  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`Failed to move.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
### moveToPosition    
将读取位置从 0 移动到绝对位置。  
 **调用形式：**     
- moveToPosition(position: number): boolean  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| position | number | true | 表示绝对位置。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true表示操作成功；返回false则表示操作失败。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let resultSet: distributedKVStore.KVStoreResultSet;  
  let moved: boolean;  
  kvStore.getResultSet('batch_test_string_key').then((result) => {  
    console.info('Succeeded in getting resultSet');  
    resultSet = result;  
    moved = resultSet.moveToPosition(1);  
    console.info(`Succeeded in moving to position.moved=${moved}`);  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to get resultSet.code is ${err.code},message is ${err.message}`);  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`Failed to move to position.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
### isFirst    
检查读取位置是否为第一行。  
 **调用形式：**     
- isFirst(): boolean  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true表示读取位置为第一行；返回false表示读取位置不是第一行。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let resultSet: distributedKVStore.KVStoreResultSet;  
  let isfirst: boolean;  
  kvStore.getResultSet('batch_test_string_key').then((result) => {  
    console.info('getResultSet succeed.');  
    resultSet = result;  
    isfirst = resultSet.isFirst();  
    console.info("Check isFirst succeed:" + isfirst);  
  }).catch((err: BusinessError) => {  
    console.error('getResultSet failed: ' + err);  
  });  
} catch (e) {  
  console.error("Check isFirst failed: " + e);  
}  
    
```    
  
    
### isLast    
检查读取位置是否为最后一行。  
 **调用形式：**     
- isLast(): boolean  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true表示读取位置为最后一行；返回false表示读取位置不是最后一行。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let resultSet: distributedKVStore.KVStoreResultSet;  
  let islast: boolean;  
  kvStore.getResultSet('batch_test_string_key').then((result) => {  
    console.info('getResultSet succeed.');  
    resultSet = result;  
    islast = resultSet.isLast();  
    console.info("Check isLast succeed: " + islast);  
  }).catch((err: BusinessError) => {  
    console.error('getResultSet failed: ' + err);  
  });  
} catch (e) {  
  console.error("Check isLast failed: " + e);  
}  
    
```    
  
    
### isBeforeFirst    
检查读取位置是否在第一行之前。  
 **调用形式：**     
- isBeforeFirst(): boolean  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true表示读取位置在第一行之前；返回false表示读取位置不在第一行之前。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let resultSet: distributedKVStore.KVStoreResultSet;  
  kvStore.getResultSet('batch_test_string_key').then((result) => {  
    console.info('getResultSet succeed.');  
    resultSet = result;  
    const isbeforefirst = resultSet.isBeforeFirst();  
    console.info("Check isBeforeFirst succeed: " + isbeforefirst);  
  }).catch((err: BusinessError) => {  
    console.error('getResultSet failed: ' + err);  
  });  
} catch (e) {  
  console.error("Check isBeforeFirst failed: " + e);  
}  
    
```    
  
    
### isAfterLast    
检查读取位置是否在最后一行之后。  
 **调用形式：**     
- isAfterLast(): boolean  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true表示读取位置在最后一行之后；返回false表示读取位置不在最后一行之后 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let resultSet: distributedKVStore.KVStoreResultSet;  
  kvStore.getResultSet('batch_test_string_key').then((result) => {  
    console.info('getResultSet succeed.');  
    resultSet = result;  
    const isafterlast = resultSet.isAfterLast();  
    console.info("Check isAfterLast succeed:" + isafterlast);  
  }).catch((err: BusinessError) => {  
    console.error('getResultSet failed: ' + err);  
  });  
} catch (e) {  
  console.error("Check isAfterLast failed: " + e);  
}  
    
```    
  
    
### getEntry    
从当前位置获取对应的键值对。  
 **调用形式：**     
- getEntry(): Entry  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Entry | 返回键值对。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let resultSet: distributedKVStore.KVStoreResultSet;  
  kvStore.getResultSet('batch_test_string_key').then((result) => {  
    console.info('getResultSet succeed.');  
    resultSet = result;  
    const entry = resultSet.getEntry();  
    console.info("getEntry succeed:" + JSON.stringify(entry));  
  }).catch((err: BusinessError) => {  
    console.error('getResultSet failed: ' + err);  
  });  
} catch (e) {  
  console.error("getEntry failed: " + e);  
}  
    
```    
  
    
## Query    
使用谓词表示数据库查询，提供创建Query实例、查询数据库中的数据和添加谓词的方法。一个Query对象中谓词数量上限为256个。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
### reset    
重置Query对象。  
 **调用形式：**     
- reset(): Query  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Query | 返回重置的Query对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let query: distributedKVStore.Query | null = new distributedKVStore.Query();  
  query.equalTo("key", "value");  
  console.info("query is " + query.getSqlLike());  
  query.reset();  
  console.info("query is " + query.getSqlLike());  
  query = null;  
} catch (e) {  
  console.error("simply calls should be ok :" + e);  
}  
    
```    
  
    
### equalTo    
构造一个Query对象来查询具有指定字段的条目，其值等于指定的值。  
 **调用形式：**     
- equalTo(field: string, value: number | string | boolean): Query  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 表示指定字段，不能包含' ^ '。 |  
| value | string | true | 表示指定的值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Query | 返回Query对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let query: distributedKVStore.Query | null = new distributedKVStore.Query();  
  query.equalTo("field", "value");  
  console.info(`query is ${query.getSqlLike()}`);  
  query = null;  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`duplicated calls should be ok.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
### notEqualTo    
构造一个Query对象以查询具有指定字段且值不等于指定值的条目。  
 **调用形式：**     
- notEqualTo(field: string, value: number | string | boolean): Query  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 表示指定字段，不能包含' ^ '。 |  
| value | string | true | 表示指定的值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Query | 返回Query对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let query: distributedKVStore.Query | null = new distributedKVStore.Query();  
  query.notEqualTo("field", "value");  
  console.info(`query is ${query.getSqlLike()}`);  
  query = null;  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`duplicated calls should be ok.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
### greaterThan    
构造一个Query对象以查询具有大于指定值的指定字段的条目。  
 **调用形式：**     
- greaterThan(field: string, value: number | string | boolean): Query  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 表示指定字段，不能包含' ^ '。 |  
| value | string | true | 表示指定的值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Query | 返回Query对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
    let query: distributedKVStore.Query | null = new distributedKVStore.Query();  
    query.greaterThan("field", "value");  
    console.info(`query is ${query.getSqlLike()}`);  
    query = null;  
} catch (e) {  
    let error = e as BusinessError;  
    console.error(`duplicated calls should be ok.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
### lessThan    
构造一个Query对象以查询具有小于指定值的指定字段的条目。  
 **调用形式：**     
- lessThan(field: string, value: number | string): Query  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 表示指定字段，不能包含' ^ '。 |  
| value | string | true | 表示指定的值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Query | 返回Query对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
    let query: distributedKVStore.Query | null = new distributedKVStore.Query();  
    query.lessThan("field", "value");  
    console.info(`query is ${query.getSqlLike()}`);  
    query = null;  
} catch (e) {  
    let error = e as BusinessError;  
    console.error(`duplicated calls should be ok.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
### greaterThanOrEqualTo    
构造一个Query对象以查询具有指定字段且值大于或等于指定值的条目。  
 **调用形式：**     
- greaterThanOrEqualTo(field: string, value: number | string): Query  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 表示指定字段，不能包含' ^ '。 |  
| value | string | true | 表示指定的值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Query | 返回Query对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
    let query: distributedKVStore.Query | null = new distributedKVStore.Query();  
    query.greaterThanOrEqualTo("field", "value");  
    console.info(`query is ${query.getSqlLike()}`);  
    query = null;  
} catch (e) {  
    let error = e as BusinessError;  
    console.error(`duplicated calls should be ok.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
### lessThanOrEqualTo    
构造一个Query对象以查询具有指定字段且值小于或等于指定值的条目。  
 **调用形式：**     
- lessThanOrEqualTo(field: string, value: number | string): Query  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 表示指定字段，不能包含' ^ '。 |  
| value | string | true | 表示指定的值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Query | 返回Query对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
    let query: distributedKVStore.Query | null = new distributedKVStore.Query();  
    query.lessThanOrEqualTo("field", "value");  
    console.info(`query is ${query.getSqlLike()}`);  
    query = null;  
} catch (e) {  
    let error = e as BusinessError;  
    console.error(`duplicated calls should be ok.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
### isNull    
构造一个Query对象以查询具有值为null的指定字段的条目。  
 **调用形式：**     
- isNull(field: string): Query  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 表示指定字段，不能包含' ^ '。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Query | 返回Query对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
    let query: distributedKVStore.Query | null = new distributedKVStore.Query();  
    query.isNull("field");  
    console.info(`query is ${query.getSqlLike()}`);  
    query = null;  
} catch (e) {  
    let error = e as BusinessError;  
    console.error(`duplicated calls should be ok.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
### inNumber    
构造一个Query对象以查询具有指定字段的条目，其值在指定的值列表中。  
 **调用形式：**     
- inNumber(field: string, valueList: number[]): Query  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 表示指定字段，不能包含' ^ '。 |  
| valueList | number[] | true | 表示指定的值列表。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Query |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
    let query: distributedKVStore.Query | null = new distributedKVStore.Query();  
    query.inNumber("field", [0, 1]);  
    console.info(`query is ${query.getSqlLike()}`);  
    query = null;  
} catch (e) {  
    let error = e as BusinessError;  
    console.error(`duplicated calls should be ok.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
### inString    
构造一个Query对象以查询具有指定字段的条目，其值在指定的字符串值列表中。  
 **调用形式：**     
- inString(field: string, valueList: string[]): Query  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 表示指定字段，不能包含' ^ '。 |  
| valueList | string[] | true | 表示指定的字符串值列表。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Query | 返回Query对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
    let query: distributedKVStore.Query | null = new distributedKVStore.Query();  
    query.inString("field", ['test1', 'test2']);  
    console.info(`query is ${query.getSqlLike()}`);  
    query = null;  
} catch (e) {  
    let error = e as BusinessError;  
    console.error(`duplicated calls should be ok.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
### notInNumber    
构造一个Query对象以查询具有指定字段的条目，该字段的值不在指定的值列表中。  
 **调用形式：**     
- notInNumber(field: string, valueList: number[]): Query  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 表示指定字段，不能包含' ^ '。 |  
| valueList | number[] | true | 表示指定的值列表。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Query | 返回Query对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
    let query: distributedKVStore.Query | null = new distributedKVStore.Query();  
    query.notInNumber("field", [0, 1]);  
    console.info(`query is ${query.getSqlLike()}`);  
    query = null;  
} catch (e) {  
    let error = e as BusinessError;  
    console.error(`duplicated calls should be ok.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
### notInString    
构造一个Query对象以查询具有指定字段且值不在指定字符串值列表中的条目。  
 **调用形式：**     
- notInString(field: string, valueList: string[]): Query  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 表示指定字段，不能包含' ^ '。 |  
| valueList | string[] | true | 表示指定的字符串值列表。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Query |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
    let query: distributedKVStore.Query | null = new distributedKVStore.Query();  
    query.notInString("field", ['test1', 'test2']);  
    console.info(`query is ${query.getSqlLike()}`);  
    query = null;  
} catch (e) {  
    let error = e as BusinessError;  
    console.error(`duplicated calls should be ok.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
### like    
构造一个Query对象以查询具有与指定字符串值相似的指定字段的条目。  
 **调用形式：**     
- like(field: string, value: string): Query  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 表示指定字段，不能包含' ^ '。 |  
| value | string | true | 表示指定的字符串值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Query | 返回Query对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
    let query: distributedKVStore.Query | null = new distributedKVStore.Query();  
    query.like("field", "value");  
    console.info(`query is ${query.getSqlLike()}`);  
    query = null;  
} catch (e) {  
    let error = e as BusinessError;  
    console.error(`duplicated calls should be ok.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
### unlike    
构造一个Query对象以查询具有与指定字符串值不相似的指定字段的条目。  
 **调用形式：**     
- unlike(field: string, value: string): Query  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 表示指定字段，不能包含' ^ '。 |  
| value | string | true | 表示指定的字符串值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Query | 返回Query对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
    let query: distributedKVStore.Query | null = new distributedKVStore.Query();  
    query.unlike("field", "value");  
    console.info(`query is ${query.getSqlLike()}`);  
    query = null;  
} catch (e) {  
    let error = e as BusinessError;  
    console.error(`duplicated calls should be ok.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
### and    
构造一个带有与条件的查询对象。  
 **调用形式：**     
- and(): Query  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Query | 返回查询对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
    let query: distributedKVStore.Query | null = new distributedKVStore.Query();  
    query.notEqualTo("field", "value1");  
    query.and();  
    query.notEqualTo("field", "value2");  
    console.info("query is " + query.getSqlLike());  
    query = null;  
} catch (e) {  
    console.error("duplicated calls should be ok :" + e);  
}  
    
```    
  
    
### or    
构造一个带有或条件的Query对象。  
 **调用形式：**     
- or(): Query  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Query | 返回查询对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
    let query: distributedKVStore.Query | null = new distributedKVStore.Query();  
    query.notEqualTo("field", "value1");  
    query.or();  
    query.notEqualTo("field", "value2");  
    console.info("query is " + query.getSqlLike());  
    query = null;  
} catch (e) {  
    console.error("duplicated calls should be ok :" + e);  
}  
    
```    
  
    
### orderByAsc    
构造一个Query对象，将查询结果按升序排序。  
 **调用形式：**     
- orderByAsc(field: string): Query  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 表示指定字段，不能包含' ^ '。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Query | 返回Query对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
    let query: distributedKVStore.Query | null = new distributedKVStore.Query();  
    query.notEqualTo("field", "value");  
    query.orderByAsc("field");  
    console.info(`query is ${query.getSqlLike()}`);  
    query = null;  
} catch (e) {  
    let error = e as BusinessError;  
    console.error(`duplicated calls should be ok.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
### orderByDesc    
构造一个Query对象，将查询结果按降序排序。  
 **调用形式：**     
- orderByDesc(field: string): Query  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 表示指定字段，不能包含' ^ '。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Query | 返回Query对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
    let query: distributedKVStore.Query | null = new distributedKVStore.Query();  
    query.notEqualTo("field", "value");  
    query.orderByDesc("field");  
    console.info(`query is ${query.getSqlLike()}`);  
    query = null;  
} catch (e) {  
    let error = e as BusinessError;  
    console.error(`duplicated calls should be ok.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
### limit    
构造一个Query对象来指定结果的数量和开始位置。该接口必须要在Query对象查询和升降序等操作之后调用，调用limit接口后，不可再对Query对象进行查询和升降序等操作。  
 **调用形式：**     
- limit(total: number, offset: number): Query  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| total | number | true | 表示指定的结果数。 |  
| offset | number | true | 表示起始位置。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Query | 返回Query对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
let total = 10;  
let offset = 1;  
try {  
  let query: distributedKVStore.Query | null = new distributedKVStore.Query();  
  query.notEqualTo("field", "value");  
  query.limit(total, offset);  
  console.info(`query is ${query.getSqlLike()}`);  
  query = null;  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`duplicated calls should be ok.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
### isNotNull    
构造一个Query对象以查询具有值不为null的指定字段的条目。  
 **调用形式：**     
- isNotNull(field: string): Query  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 表示指定字段，不能包含' ^ '。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Query | 返回Query对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let query: distributedKVStore.Query | null = new distributedKVStore.Query();  
  query.isNotNull("field");  
  console.info(`query is ${query.getSqlLike()}`);  
  query = null;  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`duplicated calls should be ok.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
### beginGroup    
创建一个带有左括号的查询条件组。  
 **调用形式：**     
- beginGroup(): Query  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Query | 返回Query对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
    let query: distributedKVStore.Query | null = new distributedKVStore.Query();  
    query.beginGroup();  
    query.isNotNull("field");  
    query.endGroup();  
    console.info("query is " + query.getSqlLike());  
    query = null;  
} catch (e) {  
    console.error("duplicated calls should be ok :" + e);  
}  
    
```    
  
    
### endGroup    
创建一个带有右括号的查询条件组。  
 **调用形式：**     
- endGroup(): Query  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Query | 返回Query对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
    let query: distributedKVStore.Query | null = new distributedKVStore.Query();  
    query.beginGroup();  
    query.isNotNull("field");  
    query.endGroup();  
    console.info("query is " + query.getSqlLike());  
    query = null;  
} catch (e) {  
    console.error("duplicated calls should be ok :" + e);  
}  
    
```    
  
    
### prefixKey    
创建具有指定键前缀的查询条件。  
 **调用形式：**     
- prefixKey(prefix: string): Query  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| prefix | string | true | 表示指定的键前缀。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Query | 返回Query对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
    let query: distributedKVStore.Query | null = new distributedKVStore.Query();  
    query.prefixKey("$.name");  
    query.prefixKey("0");  
    console.info(`query is ${query.getSqlLike()}`);  
    query = null;  
} catch (e) {  
    let error = e as BusinessError;  
    console.error(`duplicated calls should be ok.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
### setSuggestIndex    
设置一个指定的索引，将优先用于查询。  
 **调用形式：**     
- setSuggestIndex(index: string): Query  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| index | string | true | 指示要设置的索引。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Query | 返回Query对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
    let query: distributedKVStore.Query | null = new distributedKVStore.Query();  
    query.setSuggestIndex("$.name");  
    query.setSuggestIndex("0");  
    console.info(`query is ${query.getSqlLike()}`);  
    query = null;  
} catch (e) {  
    let error = e as BusinessError;  
    console.error(`duplicated calls should be ok.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
### deviceId    
添加设备ID作为key的前缀。  
 **调用形式：**     
- deviceId(deviceId: string): Query  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId | string | true | 指示查询的设备ID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Query | 返回Query对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
    let query: distributedKVStore.Query | null = new distributedKVStore.Query();  
    query.deviceId("deviceId");  
    console.info(`query is ${query.getSqlLike()}`);  
} catch (e) {  
    let error = e as BusinessError;  
    console.error(`duplicated calls should be ok.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
### getSqlLike    
获取Query对象的查询语句。  
 **调用形式：**     
- getSqlLike(): string  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回一个字段列中包含对应子串的结果。 |  
    
 **示例代码：**   
```ts    
mport { BusinessError } from '@ohos.base';  
  
try {  
    let query: distributedKVStore.Query | null = new distributedKVStore.Query();  
    let sql1 = query.getSqlLike();  
    console.info(`GetSqlLike sql= ${sql1}`);  
} catch (e) {  
    console.error("duplicated calls should be ok : " + e);  
}  
    
```    
  
    
## SingleKVStore    
SingleKVStore数据库实例，提供增加数据、删除数据和订阅数据变更、订阅数据同步完成的方法。在调用SingleKVStore的方法前，需要先通过[getKVStore](#getkvstore)构建一个SingleKVStore实例。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
### put    
添加指定类型键值对到数据库，使用Promise异步回调。  
 **调用形式：**     
    
- put(key: string, value: Uint8Array | string | number | boolean, callback: AsyncCallback\<void>): void    
起始版本： 9    
- put(key: string, value: Uint8Array | string | number | boolean, callback: AsyncCallback\<void>): void    
起始版本： 10    
- put(key: string, value: Uint8Array | string | number | boolean): Promise\<void>    
起始版本： 9    
- put(key: string, value: Uint8Array | string | number | boolean): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key | string | true | 要添加数据的key，不能为空且长度不大于[MAX_KEY_LENGTH](#constants)。 |  
| value | string | true | 要添加数据的value，支持Uint8Array、number 、 string 、boolean，Uint8Array、string 的长度不大于[MAX_VALUE_LENGTH](#constants)。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 15100003 | Database corrupted. |  
| 15100005 | Database or result set already closed. |  
| 14800047 | The WAL file size exceeds the default limit. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
const KEY_TEST_STRING_ELEMENT = 'key_test_string';  
const VALUE_TEST_STRING_ELEMENT = 'value-test-string';  
try {  
  kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT, (err) => {  
    if (err != undefined) {  
      console.error(`Failed to put.code is ${err.code},message is ${err.message}`);  
      return;  
    }  
    console.info("Succeeded in putting");  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
const KEY_TEST_STRING_ELEMENT = 'key_test_string';  
const VALUE_TEST_STRING_ELEMENT = 'value-test-string';  
try {  
  kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT).then(() => {  
    console.info(`Succeeded in putting data`);  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to put.code is ${err.code},message is ${err.message}`);  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
### putBatch    
将valuesbucket类型的值写入SingleKVStore数据库，使用Promise异步回调。  
 **调用形式：**     
    
- putBatch(entries: Entry[], callback: AsyncCallback\<void>): void    
起始版本： 9    
- putBatch(entries: Entry[], callback: AsyncCallback\<void>): void    
起始版本： 10    
- putBatch(entries: Entry[]): Promise\<void>    
起始版本： 9    
- putBatch(entries: Entry[]): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| entries | Entry[] | true | 表示要批量插入的键值对。一个entries对象中允许的最大条目个数为128个。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 15100003 | Database corrupted. |  
| 15100005 | Database or result set already closed. |  
| 14800047 | The WAL file size exceeds the default limit. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let v8Arr: distributedKVStore.Entry[] = [];  
  let arr = new Uint8Array([4, 5, 6, 7]);  
  let vb1: distributedKVStore.Entry = { key: "name_1", value: 32 }  
  let vb2: distributedKVStore.Entry = { key: "name_2", value: arr };  
  let vb3: distributedKVStore.Entry = { key: "name_3", value: "lisi" };  
  
  v8Arr.push(vb1);  
  v8Arr.push(vb2);  
  v8Arr.push(vb3);  
  kvStore.putBatch(v8Arr, async (err) => {  
    if (err != undefined) {  
      console.error(`Failed to put batch.code is ${err.code},message is ${err.message}`);  
      return;  
    }  
    console.info('Succeeded in putting batch');  
  })  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`Failed to put batch.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let v8Arr: distributedKVStore.Entry[] = [];  
  let arr = new Uint8Array([4, 5, 6, 7]);  
  let vb1: distributedKVStore.Entry = { key: "name_1", value: 32 }  
  let vb2: distributedKVStore.Entry = { key: "name_2", value: arr };  
  let vb3: distributedKVStore.Entry = { key: "name_3", value: "lisi" };  
  
  v8Arr.push(vb1);  
  v8Arr.push(vb2);  
  v8Arr.push(vb3);  
  kvStore.putBatch(v8Arr).then(async () => {  
    console.info(`Succeeded in putting patch`);  
  }).catch((err: BusinessError) => {  
    console.error(`putBatch fail.code is ${err.code},message is ${err.message}`);  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`putBatch fail.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
### delete    
从数据库中删除符合predicates条件的键值对，使用Promise异步回调。  
 **调用形式：**     
    
- delete(key: string, callback: AsyncCallback\<void>): void    
起始版本： 9    
- delete(key: string, callback: AsyncCallback\<void>): void    
起始版本： 10    
- delete(key: string): Promise\<void>    
起始版本： 9    
- delete(key: string): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key | string | true | 要删除数据的key，不能为空且长度不大于[MAX_KEY_LENGTH](#constants)。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 15100003 | Database corrupted. |  
| 15100005 | Database or result set already closed. |  
| 14800047 | The WAL file size exceeds the default limit. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
import { BusinessError } from '@ohos.base';  
  
try {  
  let predicates = new dataSharePredicates.DataSharePredicates();  
  let arr = ["name"];  
  predicates.inKeys(arr);  
  kvStore.put("name", "bob", (err) => {  
    if (err != undefined) {  
      console.error(`Failed to put.code is ${err.code},message is ${err.message}`);  
      return;  
    }  
    console.info("Succeeded in putting");  
    kvStore.delete(predicates, (err) => {  
      if (err == undefined) {  
        console.info('Succeeded in deleting');  
      } else {  
        console.error(`Failed to delete.code is ${err.code},message is ${err.message}`);  
      }  
    });  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
import { BusinessError } from '@ohos.base';  
  
try {  
  let predicates = new dataSharePredicates.DataSharePredicates();  
  let arr = ["name"];  
  predicates.inKeys(arr);  
  kvStore.put("name", "bob").then(() => {  
    console.info(`Succeeded in putting data`);  
    kvStore.delete(predicates).then(() => {  
      console.info('Succeeded in deleting');  
    }).catch((err: BusinessError) => {  
      console.error(`Failed to delete.code is ${err.code},message is ${err.message}`);  
    });  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to put.code is ${err.code},message is ${err.message}`);  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
### deleteBatch    
批量删除SingleKVStore数据库中的键值对，使用Promise异步回调。  
 **调用形式：**     
    
- deleteBatch(keys: string[], callback: AsyncCallback\<void>): void    
起始版本： 9    
- deleteBatch(keys: string[], callback: AsyncCallback\<void>): void    
起始版本： 10    
- deleteBatch(keys: string[]): Promise\<void>    
起始版本： 9    
- deleteBatch(keys: string[]): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| keys | string[] | true | 表示要批量删除的键值对。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 15100003 | Database corrupted. |  
| 15100005 | Database or result set already closed. |  
| 14800047 | The WAL file size exceeds the default limit. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let entries: distributedKVStore.Entry[] = [];  
  let keys: string[] = [];  
  for (let i = 0; i < 5; i++) {  
    let key = 'batch_test_string_key';  
    let entry: distributedKVStore.Entry = {  
      key: key + i,  
      value: {  
        type: distributedKVStore.ValueType.STRING,  
        value: 'batch_test_string_value'  
      }  
    }  
    entries.push(entry);  
    keys.push(key + i);  
  }  
  console.info(`entries: ${entries}`);  
  kvStore.putBatch(entries, async (err) => {  
    if (err != undefined) {  
      console.error(`Failed to put Batch.code is ${err.code},message is ${err.message}`);  
      return;  
    }  
    console.info('Succeeded in putting Batch');  
    kvStore.deleteBatch(keys, async (err) => {  
      if (err != undefined) {  
        console.error(`Failed to delete Batch.code is ${err.code},message is ${err.message}`);  
        return;  
      }  
      console.info('Succeeded in deleting Batch');  
    });  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let entries: distributedKVStore.Entry[] = [];  
  let keys: string[] = [];  
  for (let i = 0; i < 5; i++) {  
    let key = 'batch_test_string_key';  
    let entry: distributedKVStore.Entry = {  
      key: key + i,  
      value: {  
        type: distributedKVStore.ValueType.STRING,  
        value: 'batch_test_string_value'  
      }  
    }  
    entries.push(entry);  
    keys.push(key + i);  
  }  
  console.info(`entries: ${entries}`);  
  kvStore.putBatch(entries).then(async () => {  
    console.info('Succeeded in putting Batch');  
    kvStore.deleteBatch(keys).then(() => {  
      console.info('Succeeded in deleting Batch');  
    }).catch((err: BusinessError) => {  
      console.error(`Failed to delete Batch.code is ${err.code},message is ${err.message}`);  
    });  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to put Batch.code is ${err.code},message is ${err.message}`);  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
### removeDeviceData    
删除指定设备的数据，使用Promise异步回调。  
 **调用形式：**     
    
- removeDeviceData(deviceId: string, callback: AsyncCallback\<void>): void    
起始版本： 9    
- removeDeviceData(deviceId: string): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.DistributedKVStore    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId | string | true | 表示要删除设备的名称。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 15100005 | Database or result set already closed. |  
    
 **示例代码1：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
const KEY_TEST_STRING_ELEMENT = 'key_test_string_2';  
const VALUE_TEST_STRING_ELEMENT = 'value-string-001';  
try {  
  kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT).then(() => {  
    console.info('Succeeded in putting data');  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to put data.code is ${err.code},message is ${err.message} `);  
  });  
  const deviceid = 'no_exist_device_id';  
  kvStore.removeDeviceData(deviceid).then(() => {  
    console.info('succeeded in removing device data');  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to remove device data.code is ${err.code},message is ${err.message} `);  
  });  
  kvStore.get(KEY_TEST_STRING_ELEMENT).then((data) => {  
    console.info('Succeeded in getting data');  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to get data.code is ${err.code},message is ${err.message} `);  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.message}`)  
}  
    
```    
  
    
 **示例代码2：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
const KEY_TEST_STRING_ELEMENT = 'key_test_string_2';  
const VALUE_TEST_STRING_ELEMENT = 'value-string-002';  
try {  
  kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT, async (err) => {  
    console.info('Succeeded in putting data');  
    const deviceid = 'no_exist_device_id';  
    kvStore.removeDeviceData(deviceid, async (err) => {  
      if (err == undefined) {  
        console.info('succeeded in removing device data');  
      } else {  
        console.error(`Failed to remove device data.code is ${err.code},message is ${err.message} `);  
        kvStore.get(KEY_TEST_STRING_ELEMENT, async (err, data) => {  
          console.info('Succeeded in getting data');  
        });  
      }  
    });  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.message}`)  
}  
    
```    
  
    
### get    
获取指定键的值，使用Promise异步回调。  
 **调用形式：**     
    
- get(key: string, callback: AsyncCallback\<boolean | string | number | Uint8Array>): void    
起始版本： 9    
- get(key: string): Promise\<boolean | string | number | Uint8Array>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key | string | true | 要查询数据的key，不能为空且长度不大于[MAX_KEY_LENGTH](#constants)。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回获取查询的值。 |  
| Promise<boolean | string | number | Uint8Array> | Promise对象。返回获取查询的值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 15100003 | Database corrupted. |  
| 15100004 | Not found. |  
| 15100005 | Database or result set already closed. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
  
const KEY_TEST_STRING_ELEMENT = 'key_test_string';  
const VALUE_TEST_STRING_ELEMENT = 'value-test-string';  
try {  
  kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT, (err) => {  
    if (err != undefined) {  
      console.error(`Failed to put.code is ${err.code},message is ${err.message}`);  
      return;  
    }  
    console.info("Succeeded in putting");  
    kvStore.get(KEY_TEST_STRING_ELEMENT, (err, data) => {  
      if (err != undefined) {  
        console.error(`Failed to get.code is ${err.code},message is ${err.message}`);  
        return;  
      }  
      console.info(`Succeeded in getting data.data=${data}`);  
    });  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`Failed to get.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
  
const KEY_TEST_STRING_ELEMENT = 'key_test_string';  
const VALUE_TEST_STRING_ELEMENT = 'value-test-string';  
try {  
  kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT).then(() => {  
    console.info(`Succeeded in putting data`);  
    kvStore.get(KEY_TEST_STRING_ELEMENT).then((data) => {  
      console.info(`Succeeded in getting data.data=${data}`);  
    }).catch((err: BusinessError) => {  
      console.error(`Failed to get.code is ${err.code},message is ${err.message}`);  
    });  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to put.code is ${err.code},message is ${err.message}`);  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`Failed to get.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
### getEntries    
获取匹配指定键前缀的所有键值对，使用Promise异步回调。  
 **调用形式：**     
    
- getEntries(keyPrefix: string, callback: AsyncCallback\<Entry[]>): void    
起始版本： 9    
- getEntries(keyPrefix: string): Promise\<Entry[]>    
起始版本： 9    
- getEntries(query: Query, callback: AsyncCallback\<Entry[]>): void    
起始版本： 9    
- getEntries(query: Query): Promise\<Entry[]>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| keyPrefix | string | true | 表示要匹配的键前缀。 |  
| query | Query | true | 回调函数。返回与指定Query对象匹配的键值对列表。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回匹配指定前缀的键值对列表。 |  
| Promise<Entry[]> | Promise对象。返回匹配指定前缀的键值对列表。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 15100003 | Database corrupted. |  
| 15100005 | Database or result set already closed. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let entries: distributedKVStore.Entry[] = [];  
  for (let i = 0; i < 10; i++) {  
    let key = 'batch_test_string_key';  
    let entry: distributedKVStore.Entry = {  
      key: key + i,  
      value: {  
        type: distributedKVStore.ValueType.STRING,  
        value: 'batch_test_string_value'  
      }  
    }  
    entries.push(entry);  
  }  
  console.info(`entries: ${entries}`);  
  kvStore.putBatch(entries, async (err) => {  
    if (err != undefined) {  
      console.error(`Failed to put Batch.code is ${err.code},message is ${err.message}`);  
      return;  
    }  
    console.info('Succeeded in putting Batch');  
    kvStore.getEntries('batch_test_string_key', (err, entries) => {  
      if (err != undefined) {  
        console.error(`Failed to get Entries.code is ${err.code},message is ${err.message}`);  
        return;  
      }  
      console.info('Succeeded in getting Entries');  
      console.info(`entries.length: ${entries.length}`);  
      console.info(`entries[0]: ${entries[0]}`);  
    });  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.message} `);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
  
try {  
  let entries: distributedKVStore.Entry[] = [];  
  for (let i = 0; i < 10; i++) {  
    let key = 'batch_test_string_key';  
    let entry: distributedKVStore.Entry = {  
      key: key + i,  
      value: {  
        type: distributedKVStore.ValueType.STRING,  
        value: 'batch_test_string_value'  
      }  
    }  
    entries.push(entry);  
  }  
  console.info(`entries: ${entries}`);  
  kvStore.putBatch(entries).then(async () => {  
    console.info('Succeeded in putting Batch');  
    kvStore.getEntries('batch_test_string_key').then((entries) => {  
      console.info('Succeeded in getting Entries');  
      console.info(`PutBatch ${entries}`);  
    }).catch((err: BusinessError) => {  
      console.error(`Failed to get Entries.code is ${err.code},message is ${err.message}`);  
    });  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to put Batch.code is ${err.code},message is ${err.message}`);  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.message} `);  
}  
    
```    
  
    
### getResultSet    
获取与指定Predicate对象匹配的KVStoreResultSet对象，使用Promise异步回调。  
 **调用形式：**     
    
- getResultSet(keyPrefix: string, callback: AsyncCallback\<KVStoreResultSet>): void    
起始版本： 9    
- getResultSet(keyPrefix: string, callback: AsyncCallback\<KVStoreResultSet>): void    
起始版本： 10    
- getResultSet(keyPrefix: string): Promise\<KVStoreResultSet>    
起始版本： 9    
- getResultSet(keyPrefix: string): Promise\<KVStoreResultSet>    
起始版本： 10    
- getResultSet(query: Query, callback: AsyncCallback\<KVStoreResultSet>): void    
起始版本： 9    
- getResultSet(query: Query, callback: AsyncCallback\<KVStoreResultSet>): void    
起始版本： 10    
- getResultSet(query: Query): Promise\<KVStoreResultSet>    
起始版本： 9    
- getResultSet(query: Query): Promise\<KVStoreResultSet>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| keyPrefix | string | true | 表示要匹配的键前缀。 |  
| query | Query | true | 表示查询对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，获取与指定Predicates对象匹配的KVStoreResultSet对象。 |  
| Promise<KVStoreResultSet> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 15100003 | Over max  limits. |  
| 15100005 | Database corrupted. |  
| 15100001 | Database or result set already closed. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let resultSet: distributedKVStore.KVStoreResultSet;  
  let entries: distributedKVStore.Entry[] = [];  
  for (let i = 0; i < 10; i++) {  
    let key = 'batch_test_string_key';  
    let entry: distributedKVStore.Entry = {  
      key: key + i,  
      value: {  
        type: distributedKVStore.ValueType.STRING,  
        value: 'batch_test_string_value'  
      }  
    }  
    entries.push(entry);  
  }  
  kvStore.putBatch(entries, async (err) => {  
    if (err != undefined) {  
      console.error(`Failed to put batch.code is ${err.code},message is ${err.message}`);  
      return;  
    }  
    console.info('Succeeded in putting batch');  
    const query = new distributedKVStore.Query();  
    query.prefixKey("batch_test");  
    kvStore.getResultSet(query, async (err, result) => {  
      if (err != undefined) {  
        console.error(`Failed to get resultset.code is ${err.code},message is ${err.message}`);  
        return;  
      }  
      console.info('Succeeded in getting result set');  
    });  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let resultSet: distributedKVStore.KVStoreResultSet;  
  let entries: distributedKVStore.Entry[] = [];  
  for (let i = 0; i < 10; i++) {  
    let key = 'batch_test_string_key';  
    let entry: distributedKVStore.Entry = {  
      key: key + i,  
      value: {  
        type: distributedKVStore.ValueType.STRING,  
        value: 'batch_test_string_value'  
      }  
    }  
    entries.push(entry);  
  }  
  kvStore.putBatch(entries).then(async () => {  
    console.info('Succeeded in putting batch');  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to put batch.code is ${err.code},message is ${err.message}`);  
  });  
  const query = new distributedKVStore.Query();  
  query.prefixKey("batch_test");  
  kvStore.getResultSet(query).then((result) => {  
    console.info('Succeeded in getting result set');  
    resultSet = result;  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to get resultset.code is ${err.code},message is ${err.message}`);  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.code}`);  
}  
    
```    
  
    
### closeResultSet    
关闭由[SingleKvStore.getResultSet](#getresultset-1)返回的KVStoreResultSet对象，使用Promise异步回调。  
 **调用形式：**     
    
- closeResultSet(resultSet: KVStoreResultSet, callback: AsyncCallback\<void>): void    
起始版本： 9    
- closeResultSet(resultSet: KVStoreResultSet): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| resultSet | KVStoreResultSet | true | 表示要关闭的KVStoreResultSet对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let resultSet: distributedKVStore.KVStoreResultSet;  
try {  
  kvStore.getResultSet('batch_test_string_key', async (err, result) => {  
    if (err != undefined) {  
      console.error(`Failed to get resultset.code is ${err.code},message is ${err.message}`);  
      return;  
    }  
    console.info('Succeeded in getting result set');  
    resultSet = result;  
    kvStore.closeResultSet(resultSet, (err) => {  
      if (err != undefined) {  
        console.error(`Failed to close resultset.code is ${err.code},message is ${err.message}`);  
        return;  
      }  
      console.info('Succeeded in closing result set');  
    })  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.code}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let resultSet: distributedKVStore.KVStoreResultSet;  
try {  
  kvStore.getResultSet('batch_test_string_key').then((result) => {  
    console.info('Succeeded in getting result set');  
    resultSet = result;  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to get resultset.code is ${err.code},message is ${err.message}`);  
  });  
  kvStore.closeResultSet(resultSet).then(() => {  
    console.info('Succeeded in closing result set');  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to close resultset.code is ${err.code},message is ${err.message}`);  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.code}`);  
}  
    
```    
  
    
### getResultSize    
获取与指定Query对象匹配的结果数，使用Promise异步回调。  
 **调用形式：**     
    
- getResultSize(query: Query, callback: AsyncCallback\<number>): void    
起始版本： 9    
- getResultSize(query: Query): Promise\<number>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| query | Query | true | 表示查询对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回与指定Query对象匹配的结果数。 |  
| Promise<number> | Promise对象。获取与指定QuerV9对象匹配的结果数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 15100003 | Database corrupted. |  
| 15100005 | Database or result set already closed. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let entries: distributedKVStore.Entry[] = [];  
  for (let i = 0; i < 10; i++) {  
    let key = 'batch_test_string_key';  
    let entry: distributedKVStore.Entry = {  
      key: key + i,  
      value: {  
        type: distributedKVStore.ValueType.STRING,  
        value: 'batch_test_string_value'  
      }  
    }  
    entries.push(entry);  
  }  
  kvStore.putBatch(entries, async (err) => {  
    console.info('Succeeded in putting batch');  
    const query = new distributedKVStore.Query();  
    query.prefixKey("batch_test");  
    kvStore.getResultSize(query, async (err, resultSize) => {  
      if (err != undefined) {  
        console.error(`Failed to get result size.code is ${err.code},message is ${err.message}`);  
        return;  
      }  
      console.info('Succeeded in getting result set size');  
    });  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.code}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let entries: distributedKVStore.Entry[] = [];  
  for (let i = 0; i < 10; i++) {  
    let key = 'batch_test_string_key';  
    let entry: distributedKVStore.Entry = {  
      key: key + i,  
      value: {  
        type: distributedKVStore.ValueType.STRING,  
        value: 'batch_test_string_value'  
      }  
    }  
    entries.push(entry);  
  }  
  kvStore.putBatch(entries).then(async () => {  
    console.info('Succeeded in putting batch');  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to put batch.code is ${err.code},message is ${err.message}`);  
  });  
  const query = new distributedKVStore.Query();  
  query.prefixKey("batch_test");  
  kvStore.getResultSize(query).then((resultSize) => {  
    console.info('Succeeded in getting result set size');  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to get result size.code is ${err.code},message is ${err.message}`);  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.code}`);  
}  
    
```    
  
    
### backup    
以指定名称备份数据库，使用Promise异步回调。  
 **调用形式：**     
    
- backup(file: string, callback: AsyncCallback\<void>): void    
起始版本： 9    
- backup(file: string): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| file | string | true | 备份数据库的指定名称，不能为空且长度不大于[MAX_KEY_LENGTH](#constants)。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当以指定名称备份数据库成功，err为undefined，否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 15100005 | Database or result set already closed. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let file = "BK001";  
try {  
  kvStore.backup(file, (err) => {  
    if (err) {  
      console.error(`Failed to backup.code is ${err.code},message is ${err.message} `);  
    } else {  
      console.info(`Succeeded in backupping data`);  
    }  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let file = "BK001";  
try {  
  kvStore.backup(file).then(() => {  
    console.info(`Succeeded in backupping data`);  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to backup.code is ${err.code},message is ${err.message}`);  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
### restore    
从指定的数据库文件恢复数据库，使用Promise异步回调。  
 **调用形式：**     
    
- restore(file: string, callback: AsyncCallback\<void>): void    
起始版本： 9    
- restore(file: string): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| file | string | true | 指定的数据库文件名称，不能为空且长度不大于[MAX_KEY_LENGTH](#constants)。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当从指定的数据库文件恢复数据库成功，err为undefined，否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 15100005 | Database or result set already closed. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let file = "BK001";  
try {  
  kvStore.restore(file, (err) => {  
    if (err) {  
      console.error(`Failed to restore.code is ${err.code},message is ${err.message}`);  
    } else {  
      console.info(`Succeeded in restoring data`);  
    }  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let file = "BK001";  
try {  
  kvStore.restore(file).then(() => {  
    console.info(`Succeeded in restoring data`);  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to restore.code is ${err.code},message is ${err.message}`);  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
### deleteBackup    
根据指定名称删除备份文件，使用Promise异步回调。  
 **调用形式：**     
    
- deleteBackup(files: Array\<string>, callback: AsyncCallback\<Array\<[string, number]>>): void    
起始版本： 9    
- deleteBackup(files: Array\<string>): Promise\<Array\<[string, number]>>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| files | Array<string> | true | 删除备份文件所指定的名称，不能为空且长度不大于[MAX_KEY_LENGTH](#constants)。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回删除备份的文件名及其处理结果。 |  
| Promise<Array<[string, number]>> | Promise对象，返回删除备份的文件名及其处理结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let files = ["BK001", "BK002"];  
try {  
  kvStore.deleteBackup(files, (err, data) => {  
    if (err) {  
      console.error(`Failed to delete Backup.code is ${err.code},message is ${err.message}`);  
    } else {  
      console.info(`Succeed in deleting Backup.data=${data}`);  
    }  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let files = ["BK001", "BK002"];  
try {  
  kvStore.deleteBackup(files).then((data) => {  
    console.info(`Succeed in deleting Backup.data=${data}`);  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to delete Backup.code is ${err.code},message is ${err.message}`);  
  })  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
### startTransaction    
启动SingleKVStore数据库中的事务，使用Promise异步回调。  
 **调用形式：**     
    
- startTransaction(callback: AsyncCallback\<void>): void    
起始版本： 9    
- startTransaction(callback: AsyncCallback\<void>): void    
起始版本： 10    
- startTransaction(): Promise\<void>    
起始版本： 9    
- startTransaction(): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 15100005 | Database or result set already closed. |  
| 14800047 | The WAL file size exceeds the default limit. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
function putBatchString(len: number, prefix: string) {  
  let entries: distributedKVStore.Entry[] = [];  
  for (let i = 0; i < len; i++) {  
    let entry: distributedKVStore.Entry = {  
      key: prefix + i,  
      value: {  
        type: distributedKVStore.ValueType.STRING,  
        value: 'batch_test_string_value'  
      }  
    }  
    entries.push(entry);  
  }  
  return entries;  
}  
  
try {  
  let count = 0;  
  kvStore.on('dataChange', 0, (data) => {  
    console.info(`startTransaction 0 ${data}`);  
    count++;  
  });  
  kvStore.startTransaction(async (err) => {  
    if (err != undefined) {  
      console.error(`Failed to start Transaction.code is ${err.code},message is ${err.message}`);  
      return;  
    }  
    console.info('Succeeded in starting Transaction');  
    let entries = putBatchString(10, 'batch_test_string_key');  
    console.info(`entries: ${entries}`);  
    kvStore.putBatch(entries, async (err) => {  
      if (err != undefined) {  
        console.error(`Failed to put batch.code is ${err.code},message is ${err.message}`);  
        return;  
      }  
      console.info('Succeeded in putting Batch');  
    });  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`Failed to start Transaction.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let count = 0;  
  kvStore.on('dataChange', distributedKVStore.SubscribeType.SUBSCRIBE_TYPE_ALL, (data) => {  
    console.info(`startTransaction 0 ${data}`);  
    count++;  
  });  
  kvStore.startTransaction().then(async () => {  
    console.info('Succeeded in starting Transaction');  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to start Transaction.code is ${err.code},message is ${err.message}`);  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`Failed to start Transaction.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
### commit    
提交SingleKVStore数据库中的事务，使用Promise异步回调。  
 **调用形式：**     
    
- commit(callback: AsyncCallback\<void>): void    
起始版本： 9    
- commit(): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 15100005 | Database or result set already closed. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  kvStore.commit((err) => {  
    if (err == undefined) {  
      console.info('Succeeded in committing');  
    } else {  
      console.error(`Failed to commit.code is ${err.code},message is ${err.message}`);  
    }  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  kvStore.commit().then(async () => {  
    console.info('Succeeded in committing');  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to commit.code is ${err.code},message is ${err.message}`);  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
### rollback    
在SingleKVStore数据库中回滚事务，使用Promise异步回调。  
 **调用形式：**     
    
- rollback(callback: AsyncCallback\<void>): void    
起始版本： 9    
- rollback(): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 15100005 | Database or result set already closed. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  kvStore.rollback((err) => {  
    if (err == undefined) {  
      console.info('Succeeded in rolling back');  
    } else {  
      console.error(`Failed to rollback.code is ${err.code},message is ${err.message}`);  
    }  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  kvStore.rollback().then(async () => {  
    console.info('Succeeded in rolling back');  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to rollback.code is ${err.code},message is ${err.message}`);  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
### enableSync    
设定是否开启同步，使用Promise异步回调。  
 **调用形式：**     
    
- enableSync(enabled: boolean, callback: AsyncCallback\<void>): void    
起始版本： 9    
- enableSync(enabled: boolean): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| enabled | boolean | true | 设定是否开启同步，true表示开启同步，false表示不启用同步。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  kvStore.enableSync(true, (err) => {  
    if (err == undefined) {  
      console.info('Succeeded in enabling sync');  
    } else {  
      console.error(`Failed to enable sync.code is ${err.code},message is ${err.message}`);  
    }  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  kvStore.enableSync(true).then(() => {  
    console.info('Succeeded in enabling sync');  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to enable sync.code is ${err.code},message is ${err.message}`);  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
### setSyncRange    
设置同步范围标签，使用Promise异步回调。  
 **调用形式：**     
    
- setSyncRange(localLabels: string[], remoteSupportLabels: string[], callback: AsyncCallback\<void>): void    
起始版本： 9    
- setSyncRange(localLabels: string[], remoteSupportLabels: string[]): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| localLabels | string[] | true | 表示本地设备的同步标签。 |  
| remoteSupportLabels | string[] | true | 表示要同步数据的设备的同步标签。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  const localLabels = ['A', 'B'];  
  const remoteSupportLabels = ['C', 'D'];  
  kvStore.setSyncRange(localLabels, remoteSupportLabels, (err) => {  
    if (err != undefined) {  
      console.error(`Failed to set syncRange.code is ${err.code},message is ${err.message}`);  
      return;  
    }  
    console.info('Succeeded in setting syncRange');  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  const localLabels = ['A', 'B'];  
  const remoteSupportLabels = ['C', 'D'];  
  kvStore.setSyncRange(localLabels, remoteSupportLabels).then(() => {  
    console.info('Succeeded in setting syncRange');  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to set syncRange.code is ${err.code},message is ${err.message}`);  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
### setSyncParam    
设置数据库同步允许的默认延迟，使用Promise异步回调。  
 **调用形式：**     
    
- setSyncParam(defaultAllowedDelayMs: number, callback: AsyncCallback\<void>): void    
起始版本： 9    
- setSyncParam(defaultAllowedDelayMs: number): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| defaultAllowedDelayMs | number | true | 表示数据库同步允许的默认延迟，以毫秒为单位。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  const defaultAllowedDelayMs = 500;  
  kvStore.setSyncParam(defaultAllowedDelayMs, (err) => {  
    if (err != undefined) {  
      console.error(`Failed to set syncParam.code is ${err.code},message is ${err.message}`);  
      return;  
    }  
    console.info('Succeeded in setting syncParam');  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  const defaultAllowedDelayMs = 500;  
  kvStore.setSyncParam(defaultAllowedDelayMs).then(() => {  
    console.info('Succeeded in setting syncParam');  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to set syncParam.code is ${err.code},message is ${err.message}`);  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
### sync    
在手动同步方式下，触发数据库同步。关于键值型数据库的同步方式说明，请见[键值型数据库跨设备数据同步](../../database/data-sync-of-kv-store.md)。  
 **调用形式：**     
- sync(deviceIds: string[], mode: SyncMode, delayMs?: number): void  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core  
 **需要权限：** ohos.permission.DISTRIBUTED_DATASYNC    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceIds | string[] | true | 同一组网环境下，需要同步的设备的networkId列表。 |  
| mode | SyncMode | true | 同步模式。 |  
| delayMs | number | false | 可选参数，允许延时时间，单位：ms（毫秒），默认为0。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 15100003 | Database corrupted. |  
| 15100004 | Not found. |  
    
 **示例代码：**   
```ts    
import deviceManager from '@ohos.distributedDeviceManager';  
import UIAbility from '@ohos.app.ability.UIAbility';  
import { BusinessError } from '@ohos.base';  
  
let devManager: deviceManager.DeviceManager;  
const KEY_TEST_SYNC_ELEMENT = 'key_test_sync';  
const VALUE_TEST_SYNC_ELEMENT = 'value-string-001';  
// create deviceManager  
export default class EntryAbility extends UIAbility {  
  onCreate() {  
    let context = this.context;  
    try {  
      devManager = deviceManager.createDeviceManager(context.applicationInfo.name);  
      let deviceIds: string[] = [];  
      if (devManager != null) {  
        let devices = devManager.getAvailableDeviceListSync();  
        for (let i = 0; i < devices.length; i++) {  
          deviceIds[i] = devices[i].networkId as string;  
        }  
      }  
      try {  
        kvStore.on('syncComplete', (data) => {  
          console.info('Sync dataChange');  
        });  
        kvStore.put(KEY_TEST_SYNC_ELEMENT + 'testSync101', VALUE_TEST_SYNC_ELEMENT, (err) => {  
          if (err != undefined) {  
            console.error(`Failed to sync.code is ${err.code},message is ${err.message}`);  
            return;  
          }  
          console.info('Succeeded in putting data');  
          const mode = distributedKVStore.SyncMode.PULL_ONLY;  
          kvStore.sync(deviceIds, mode, 1000);  
        });  
      } catch (e) {  
        let error = e as BusinessError;  
        console.error(`Failed to sync.code is ${error.code},message is ${error.message}`);  
      }  
  
    } catch (err) {  
      let error = err as BusinessError;  
      console.error("createDeviceManager errCode:" + error.code + ",errMessage:" + error.message);  
    }  
  }  
}  
    
```    
  
    
### sync    
在手动同步方式下，触发数据库同步，此方法为同步方法。关于键值型数据库的同步方式说明，请见[键值型数据库跨设备数据同步](../../database/data-sync-of-kv-store.md)。  
 **调用形式：**     
- sync(deviceIds: string[], query: Query, mode: SyncMode, delayMs?: number): void  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core  
 **需要权限：** ohos.permission.DISTRIBUTED_DATASYNC    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceIds | string[] | true | 同一组网环境下，需要同步的设备的networkId列表。 |  
| query | Query | true | 表示数据库的查询谓词条件 |  
| mode | SyncMode | true | 同步模式。 |  
| delayMs | number | false | 可选参数，允许延时时间，单位：ms（毫秒），默认为0。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 15100003 | Database corrupted. |  
| 15100004 | Not found. |  
    
 **示例代码：**   
```ts    
import deviceManager from '@ohos.distributedDeviceManager';  
import UIAbility from '@ohos.app.ability.UIAbility';  
import { BusinessError } from '@ohos.base';  
  
let devManager: deviceManager.DeviceManager;  
const KEY_TEST_SYNC_ELEMENT = 'key_test_sync';  
const VALUE_TEST_SYNC_ELEMENT = 'value-string-001';  
// create deviceManager  
export default class EntryAbility extends UIAbility {  
  onCreate() {  
    let context = this.context;  
    try {  
      let devManager = deviceManager.createDeviceManager(context.applicationInfo.name);  
      let deviceIds: string[] = [];  
      if (devManager != null) {  
        let devices = devManager.getAvailableDeviceListSync();  
        for (let i = 0; i < devices.length; i++) {  
          deviceIds[i] = devices[i].networkId as string;  
        }  
      }  
      try {  
        kvStore.on('syncComplete', (data) => {  
          console.info('Sync dataChange');  
        });  
        kvStore.put(KEY_TEST_SYNC_ELEMENT + 'testSync101', VALUE_TEST_SYNC_ELEMENT, (err) => {  
          if (err != undefined) {  
            console.error(`Failed to sync.code is ${err.code},message is ${err.message}`);  
            return;  
          }  
          console.info('Succeeded in putting data');  
          const mode = distributedKVStore.SyncMode.PULL_ONLY;  
          const query = new distributedKVStore.Query();  
          query.prefixKey("batch_test");  
          query.deviceId(devManager.getLocalDeviceNetworkId());  
          kvStore.sync(deviceIds, query, mode, 1000);  
        });  
      } catch (e) {  
        let error = e as BusinessError;  
        console.error(`Failed to sync.code is ${error.code},message is ${error.message}`);  
      }  
  
    } catch (err) {  
      let error = err as BusinessError;  
      console.error("createDeviceManager errCode:" + error.code + ",errMessage:" + error.message);  
    }  
  }  
}  
    
```    
  
    
### on('dataChange')    
订阅指定类型的数据变更通知。  
 **调用形式：**     
- on(event: 'dataChange', type: SubscribeType, listener: Callback\<ChangeNotification>): void  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event | string | true | 订阅的事件名，固定为'dataChange'，表示数据变更事件。 |  
| type | SubscribeType | true | 表示订阅的类型。 |  
| listener | Callback<ChangeNotification> | true | 回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 15100001 | Over max  limits. |  
| 15100005 | Over max  limits. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  kvStore.on('dataChange', distributedKVStore.SubscribeType.SUBSCRIBE_TYPE_LOCAL, (data) => {  
    console.info(`dataChange callback call data: ${data}`);  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
### on('syncComplete')    
订阅同步完成事件回调通知。  
 **调用形式：**     
- on(event: 'syncComplete', syncCallback: Callback\<Array\<[string, number]>>): void  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event | string | true | 订阅的事件名，固定为'syncComplete'，表示同步完成事件。 |  
| syncCallback | Callback<Array<[string, number]>> | true | 回调函数。用于向调用方发送同步结果的回调。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
  
const KEY_TEST_FLOAT_ELEMENT = 'key_test_float';  
const VALUE_TEST_FLOAT_ELEMENT = 321.12;  
try {  
  kvStore.on('syncComplete', (data) => {  
    console.info(`syncComplete ${data}`);  
  });  
  kvStore.put(KEY_TEST_FLOAT_ELEMENT, VALUE_TEST_FLOAT_ELEMENT).then(() => {  
    console.info('succeeded in putting');  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to put.code is ${err.code},message is ${err.message}`);  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`Failed to subscribe syncComplete.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
### off('dataChange')    
取消订阅数据变更通知。  
 **调用形式：**     
- off(event: 'dataChange', listener?: Callback\<ChangeNotification>): void  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event | string | true | 取消订阅的事件名，固定为'dataChange'，表示数据变更事件。 |  
| listener | Callback<ChangeNotification> | false | 取消订阅的函数。如不设置callback，则取消所有已订阅的函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 15100005 | Database or result set already closed. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
class KvstoreModel {  
  call(data: string) {  
    console.info(`dataChange : ${data}`);  
  }  
  
  subscribeDataChange() {  
    try {  
      if (kvStore != null) {  
        kvStore.on('dataChange', distributedKVStore.SubscribeType.SUBSCRIBE_TYPE_REMOTE, this.call);  
      }  
    } catch (err) {  
      let error = err as BusinessError;  
      console.error(`Failed to subscribeDataChange.code is ${error.code},message is ${error.message}`);  
    }  
  }  
  
  unsubscribeDataChange() {  
    try {  
      if (kvStore != null) {  
        kvStore.off('dataChange', this.call);  
      }  
    } catch (err) {  
      let error = err as BusinessError;  
      console.error(`Failed to unsubscribeDataChange.code is ${error.code},message is ${error.message}`);  
    }  
  }  
}  
    
```    
  
    
### off('syncComplete')    
取消订阅同步完成事件回调通知。  
 **调用形式：**     
- off(event: 'syncComplete', syncCallback?: Callback\<Array\<[string, number]>>): void  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event | string | true | 取消订阅的事件名，固定为'syncComplete'，表示同步完成事件。 |  
| syncCallback | Callback<Array<[string, number]>> | false | 取消订阅的函数。如不设置callback，则取消所有已订阅的函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
class KvstoreModel {  
  call(data: string) {  
    console.info(`syncComplete : ${data}`);  
  }  
  
  subscribeDataChange() {  
    try {  
      if (kvStore != null) {  
        kvStore.on('syncComplete', distributedKVStore.SubscribeType.SUBSCRIBE_TYPE_REMOTE, this.call);  
      }  
    } catch (err) {  
      let error = err as BusinessError;  
      console.error(`Failed to subscribeDataChange.code is ${error.code},message is ${error.message}`);  
    }  
  }  
  
  unsubscribeDataChange() {  
    try {  
      if (kvStore != null) {  
        kvStore.off('dsyncComplete', this.call);  
      }  
    } catch (err) {  
      let error = err as BusinessError;  
      console.error(`Failed to unsubscribeDataChange.code is ${error.code},message is ${error.message}`);  
    }  
  }  
}  
    
```    
  
    
### getSecurityLevel    
获取数据库的安全级别，使用Promise异步回调。  
 **调用形式：**     
    
- getSecurityLevel(callback: AsyncCallback\<SecurityLevel>): void    
起始版本： 9    
- getSecurityLevel(): Promise\<SecurityLevel>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回数据库的安全级别。 |  
| Promise<SecurityLevel> | Promise对象。返回数据库的安全级别。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 15100005 | Database or result set already closed. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  kvStore.getSecurityLevel((err, data) => {  
    if (err != undefined) {  
      console.error(`Failed to get SecurityLevel.code is ${err.code},message is ${err.message}`);  
      return;  
    }  
    console.info('Succeeded in getting securityLevel');  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  kvStore.getSecurityLevel().then((data) => {  
    console.info('Succeeded in getting securityLevel');  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to get SecurityLevel.code is ${err.code},message is ${err.message}`);  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
## DeviceKVStore    
设备协同数据库，继承自SingleKVStore，提供查询数据和同步数据的方法。  
设备协同数据库，以设备维度对数据进行区分，每台设备仅能写入和修改本设备的数据，其它设备的数据对其是只读的，无法修改其它设备的数据。  
比如，可以使用设备协同数据库实现设备间的图片分享，可以查看其他设备的图片，但无法修改和删除其他设备的图片。在调用DeviceKVStore的方法前，需要先通过[getKVStore](#getkvstore)构建一个DeviceKVStore实例。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.DistributedKVStore    
### get    
获取本设备指定键的值，使用Promise异步回调。  
 **调用形式：**     
    
- get(key: string, callback: AsyncCallback\<boolean | string | number | Uint8Array>): void    
起始版本： 9    
- get(key: string): Promise\<boolean | string | number | Uint8Array>    
起始版本： 9    
- get(deviceId: string, key: string, callback: AsyncCallback\<boolean | string | number | Uint8Array>): void    
起始版本： 9    
- get(deviceId: string, key: string): Promise\<boolean | string | number | Uint8Array>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key | string | true | 要查询数据的key，不能为空且长度不大于[MAX_KEY_LENGTH](#constants)。 |  
| deviceId | string | true | 表示要查询key值的键。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回获取查询的值。 |  
| Promise<boolean | string | number | Uint8Array> | Promise对象。返回匹配给定条件的字符串值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 15100003 | Database corrupted. |  
| 15100004 | Not found. |  
| 15100005 | Database or result set already closed. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
const KEY_TEST_STRING_ELEMENT = 'key_test_string';  
const VALUE_TEST_STRING_ELEMENT = 'value-test-string';  
try {  
  kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT, (err) => {  
    if (err != undefined) {  
      console.error(`Failed to put.code is ${err.code},message is ${err.message}`);  
      return;  
    }  
    console.info("Succeeded in putting");  
    kvStore.get(KEY_TEST_STRING_ELEMENT, (err, data) => {  
      if (err != undefined) {  
        console.error(`Failed to get.code is ${err.code},message is ${err.message}`);  
        return;  
      }  
      console.info(`Succeeded in getting data.data=${data}`);  
    });  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`Failed to get.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
const KEY_TEST_STRING_ELEMENT = 'key_test_string';  
const VALUE_TEST_STRING_ELEMENT = 'value-test-string';  
try {  
  kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT).then(() => {  
    console.info(`Succeeded in putting data`);  
    kvStore.get(KEY_TEST_STRING_ELEMENT).then((data) => {  
      console.info(`Succeeded in getting data.data=${data}`);  
    }).catch((err: BusinessError) => {  
      console.error(`Failed to get.code is ${err.code},message is ${err.message}`);  
    });  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to put.code is ${err.code},message is ${err.message}`);  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`Failed to get.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
### getEntries    
获取匹配本设备指定键前缀的所有键值对，使用Promise异步回调。  
 **调用形式：**     
    
- getEntries(keyPrefix: string, callback: AsyncCallback\<Entry[]>): void    
起始版本： 9    
- getEntries(keyPrefix: string): Promise\<Entry[]>    
起始版本： 9    
- getEntries(deviceId: string, keyPrefix: string, callback: AsyncCallback\<Entry[]>): void    
起始版本： 9    
- getEntries(deviceId: string, keyPrefix: string): Promise\<Entry[]>    
起始版本： 9    
- getEntries(query: Query, callback: AsyncCallback\<Entry[]>): void    
起始版本： 9    
- getEntries(query: Query): Promise\<Entry[]>    
起始版本： 9    
- getEntries(deviceId: string, query: Query, callback: AsyncCallback\<Entry[]>): void    
起始版本： 9    
- getEntries(deviceId: string, query: Query): Promise\<Entry[]>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| keyPrefix | string | true | 表示要匹配的键前缀。 |  
| deviceId | string | true | 标识要查询其数据的设备。 |  
| query | Query | true | 表示查询对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回匹配指定前缀的键值对列表。 |  
| Promise<Entry[]> | Promise对象。返回本设备与指定Query对象匹配的键值对列表。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 15100003 | Database corrupted. |  
| 15100005 | Database or result set already closed. |  
    
 **示例代码1：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let entries: distributedKVStore.Entry[] = [];  
  for (let i = 0; i < 10; i++) {  
    let key = 'batch_test_string_key';  
    let entry: distributedKVStore.Entry = {  
      key: key + i,  
      value: {  
        type: distributedKVStore.ValueType.STRING,  
        value: 'batch_test_string_value'  
      }  
    }  
    entries.push(entry);  
  }  
  console.info(`entries: ${entries}`);  
  kvStore.putBatch(entries).then(async () => {  
    console.info('Succeeded in putting batch');  
    kvStore.getEntries('localDeviceId', 'batch_test_string_key').then((entries) => {  
      console.info('Succeeded in getting entries');  
      console.info(`entries.length: ${entries.length}`);  
      console.info(`entries[0]: ${entries[0]}`);  
      console.info(`entries[0].value: ${entries[0].value}`);  
      console.info(`entries[0].value.value: ${entries[0].value.value}`);  
    }).catch((err: BusinessError) => {  
      console.error(`Failed to get entries.code is ${err.code},message is ${err.message}`);  
    });  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to put batch.code is ${err.code},message is ${err.message}`);  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`Failed to put batch.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let entries: distributedKVStore.Entry[] = [];  
  for (let i = 0; i < 10; i++) {  
    let key = 'batch_test_string_key';  
    let entry: distributedKVStore.Entry = {  
      key: key + i,  
      value: {  
        type: distributedKVStore.ValueType.STRING,  
        value: 'batch_test_string_value'  
      }  
    }  
    entries.push(entry);  
  }  
  console.info(`entries : ${entries}`);  
  kvStore.putBatch(entries, async (err) => {  
    if (err != undefined) {  
      console.error(`Failed to put batch.code is ${err.code},message is ${err.message}`);  
      return;  
    }  
    console.info('Succeeded in putting batch');  
    kvStore.getEntries('localDeviceId', 'batch_test_string_key', (err, entries) => {  
      if (err != undefined) {  
        console.error(`Failed to get entries.code is ${err.code},message is ${err.message}`);  
        return;  
      }  
      console.info('Succeeded in getting entries');  
      console.info(`entries.length: ${entries.length}`);  
      console.info(`entries[0]: ${entries[0]}`);  
    });  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`Failed to put batch.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
### getResultSet    
获取与本设备指定Predicate对象匹配的KVStoreResultSet对象，使用Promise异步回调。  
 **调用形式：**     
    
- getResultSet(keyPrefix: string, callback: AsyncCallback\<KVStoreResultSet>): void    
起始版本： 9    
- getResultSet(keyPrefix: string, callback: AsyncCallback\<KVStoreResultSet>): void    
起始版本： 10    
- getResultSet(keyPrefix: string): Promise\<KVStoreResultSet>    
起始版本： 9    
- getResultSet(keyPrefix: string): Promise\<KVStoreResultSet>    
起始版本： 10    
- getResultSet(deviceId: string, keyPrefix: string, callback: AsyncCallback\<KVStoreResultSet>): void    
起始版本： 9    
- getResultSet(deviceId: string, keyPrefix: string, callback: AsyncCallback\<KVStoreResultSet>): void    
起始版本： 10    
- getResultSet(deviceId: string, keyPrefix: string): Promise\<KVStoreResultSet>    
起始版本： 9    
- getResultSet(deviceId: string, keyPrefix: string): Promise\<KVStoreResultSet>    
起始版本： 10    
- getResultSet(query: Query, callback: AsyncCallback\<KVStoreResultSet>): void    
起始版本： 9    
- getResultSet(query: Query, callback: AsyncCallback\<KVStoreResultSet>): void    
起始版本： 10    
- getResultSet(query: Query): Promise\<KVStoreResultSet>    
起始版本： 9    
- getResultSet(query: Query): Promise\<KVStoreResultSet>    
起始版本： 10    
- getResultSet(deviceId: string, query: Query, callback: AsyncCallback\<KVStoreResultSet>): void    
起始版本： 9    
- getResultSet(deviceId: string, query: Query, callback: AsyncCallback\<KVStoreResultSet>): void    
起始版本： 10    
- getResultSet(deviceId: string, query: Query): Promise\<KVStoreResultSet>    
起始版本： 9    
- getResultSet(deviceId: string, query: Query): Promise\<KVStoreResultSet>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| keyPrefix | string | true | 表示要匹配的键前缀。 |  
| deviceId | string | true | 标识要查询其数据的设备。 |  
| query | Query | true | 表示查询对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，获取与指定Predicates对象匹配的KVStoreResultSet对象。 |  
| Promise<KVStoreResultSet> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 15100003 | Over max  limits. |  
| 15100005 | Database corrupted. |  
| 15100001 | Database or result set already closed. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
  
try {  
  let resultSet: distributedKVStore.KVStoreResultSet;  
  let entries: distributedKVStore.Entry[] = [];  
  for (let i = 0; i < 10; i++) {  
    let key = 'batch_test_string_key';  
    let entry: distributedKVStore.Entry = {  
      key: key + i,  
      value: {  
        type: distributedKVStore.ValueType.STRING,  
        value: 'batch_test_string_value'  
      }  
    }  
    entries.push(entry);  
  }  
  kvStore.putBatch(entries, async (err) => {  
    if (err != undefined) {  
      console.error(`Failed to put batch.code is ${err.code},message is ${err.message}`);  
      return;  
    }  
    console.info('Succeeded in putting batch');  
    const query = new distributedKVStore.Query();  
    query.prefixKey("batch_test");  
    kvStore.getResultSet(query, async (err, result) => {  
      if (err != undefined) {  
        console.error(`Failed to get resultSet.code is ${err.code},message is ${err.message}`);  
        return;  
      }  
      console.info('Succeeded in getting resultSet');  
      resultSet = result;  
      kvStore.closeResultSet(resultSet, (err) => {  
        if (err != undefined) {  
          console.error(`Failed to close resultSet.code is ${err.code},message is ${err.message}`);  
          return;  
        }  
        console.info('Succeeded in closing resultSet');  
      })  
    });  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`Failed to get resultSet.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
import { BusinessError } from '@ohos.base';  
  
try {  
  let resultSet: distributedKVStore.KVStoreResultSet;  
  let predicates = new dataSharePredicates.DataSharePredicates();  
  predicates.prefixKey("batch_test_string_key");  
  kvStore.getResultSet('localDeviceId', predicates).then((result) => {  
    console.info('Succeeded in getting result set');  
    resultSet = result;  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to get resultset.code is ${err.code},message is ${err.message}`);  
  });  
  kvStore.closeResultSet(resultSet).then(() => {  
    console.info('Succeeded in closing result set');  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to close resultset.code is ${err.code},message is ${err.message}`);  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.code}`);  
}  
    
```    
  
    
### getResultSize    
获取与本设备指定Query对象匹配的结果数，使用Promise异步回调。  
 **调用形式：**     
    
- getResultSize(query: Query, callback: AsyncCallback\<number>): void    
起始版本： 9    
- getResultSize(query: Query): Promise\<number>    
起始版本： 9    
- getResultSize(deviceId: string, query: Query, callback: AsyncCallback\<number>): void    
起始版本： 9    
- getResultSize(deviceId: string, query: Query): Promise\<number>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| query | Query | true | 表示查询对象。 |  
| deviceId | string | true | 表示查询对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回与本设备指定Query对象匹配的结果数。 |  
| Promise<number> | Promise对象。返回与指定设备ID和Query对象匹配的结果数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 15100003 | Database corrupted. |  
| 15100005 | Database or result set already closed. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let entries: distributedKVStore.Entry[] = [];  
  for (let i = 0; i < 10; i++) {  
    let key = 'batch_test_string_key';  
    let entry: distributedKVStore.Entry = {  
      key: key + i,  
      value: {  
        type: distributedKVStore.ValueType.STRING,  
        value: 'batch_test_string_value'  
      }  
    }  
    entries.push(entry);  
  }  
  kvStore.putBatch(entries, async (err) => {  
    if (err != undefined) {  
      console.error(`Failed to put batch.code is ${err.code},message is ${err.message}`);  
      return;  
    }  
    console.info('Succeeded in putting batch');  
    const query = new distributedKVStore.Query();  
    query.prefixKey("batch_test");  
    kvStore.getResultSize('localDeviceId', query, async (err, resultSize) => {  
      if (err != undefined) {  
        console.error(`Failed to get resultSize.code is ${err.code},message is ${err.message}`);  
        return;  
      }  
      console.info('Succeeded in getting resultSize');  
    });  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`Failed to get resultSize.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let entries: distributedKVStore.Entry[] = [];  
  for (let i = 0; i < 10; i++) {  
    let key = 'batch_test_string_key';  
    let entry: distributedKVStore.Entry = {  
      key: key + i,  
      value: {  
        type: distributedKVStore.ValueType.STRING,  
        value: 'batch_test_string_value'  
      }  
    }  
    entries.push(entry);  
  }  
  kvStore.putBatch(entries).then(async () => {  
    console.info('Succeeded in putting batch');  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to put batch.code is ${err.code},message is ${err.message}`);  
  });  
  let query = new distributedKVStore.Query();  
  query.prefixKey("batch_test");  
  kvStore.getResultSize('localDeviceId', query).then((resultSize) => {  
    console.info('Succeeded in getting resultSize');  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to get resultSize.code is ${err.code},message is ${err.message}`);  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`Failed to get resultSize.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
## createKVManager    
创建一个KVManager对象实例，用于管理数据库对象。  
 **调用形式：**     
- createKVManager(config: KVManagerConfig): KVManager  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| config | KVManagerConfig | true | 提供KVManager实例的配置信息，包括调用方的包名和用户信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| KVManager | 返回创建的KVManager对象实例。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
## KVManager    
分布式键值数据库管理实例，用于获取分布式键值数据库的相关信息。在调用KVManager的方法前，需要先通过[createKVManager](#distributedkvstorecreatekvmanager)构建一个KVManager实例。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
### getKVStore    
通过指定Options和storeId，创建并获取分布式键值数据库，使用Promise异步回调。  
 **调用形式：**     
    
- getKVStore\<T>(storeId: string, options: Options, callback: AsyncCallback\<T>): void    
起始版本： 9    
- getKVStore\<T>(storeId: string, options: Options): Promise\<T>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| storeId | string | true | 数据库唯一标识符，长度不大于[MAX_STORE_ID_LENGTH](#constants)。 |  
| options | Options | true | 创建分布式键值实例的配置信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回创建的分布式键值数据库实例（根据kvStoreType的不同，可以创建SingleKVStore实例和DeviceKVStore实例）。 |  
| Promise<T> | Promise对象。返回创建的分布式键值数据库实例（根据kvStoreType的不同，可以创建SingleKVStore实例和DeviceKVStore实例。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 15100002 | Open existed database with changed options. |  
| 15100003 | Database corrupted. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let kvStore: distributedKVStore.SingleKVStore | null;  
try {  
  const options: distributedKVStore.Options = {  
    createIfMissing: true,  
    encrypt: false,  
    backup: false,  
    autoSync: true,  
    kvStoreType: distributedKVStore.KVStoreType.SINGLE_VERSION,  
    securityLevel: distributedKVStore.SecurityLevel.S2,  
  };  
  kvManager.getKVStore('storeId', options, (err, store: distributedKVStore.SingleKVStore) => {  
    if (err) {  
      console.error(`Failed to get KVStore.code is ${err.code},message is ${err.message}`);  
      return;  
    }  
    console.info("Succeeded in getting KVStore");  
    kvStore = store;  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let kvStore: distributedKVStore.SingleKVStore | null;  
try {  
  const options: distributedKVStore.Options = {  
    createIfMissing: true,  
    encrypt: false,  
    backup: false,  
    autoSync: true,  
    kvStoreType: distributedKVStore.KVStoreType.SINGLE_VERSION,  
    securityLevel: distributedKVStore.SecurityLevel.S2,  
  };  
  kvManager.getKVStore<distributedKVStore.SingleKVStore>('storeId', options).then((store: distributedKVStore.SingleKVStore) => {  
    console.info("Succeeded in getting KVStore");  
    kvStore = store;  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to get KVStore.code is ${err.code},message is ${err.message}`);  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
### closeKVStore    
通过storeId的值关闭指定的分布式键值数据库，使用Promise异步回调。  
 **调用形式：**     
    
- closeKVStore(appId: string, storeId: string, callback: AsyncCallback\<void>): void    
起始版本： 9    
- closeKVStore(appId: string, storeId: string): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| appId | string | true | 所调用数据库方的包名。 |  
| storeId | string | true | 要关闭的数据库唯一标识符，长度不大于[MAX_STORE_ID_LENGTH](#constants)。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let kvStore: distributedKVStore.SingleKVStore | null;  
const options: distributedKVStore.Options = {  
  createIfMissing: true,  
  encrypt: false,  
  backup: false,  
  autoSync: true,  
  kvStoreType: distributedKVStore.KVStoreType.SINGLE_VERSION,  
  schema: undefined,  
  securityLevel: distributedKVStore.SecurityLevel.S2,  
}  
try {  
  kvManager.getKVStore('storeId', options, async (err, store: distributedKVStore.SingleKVStore | null) => {  
    if (err != undefined) {  
      console.error(`Failed to get KVStore.code is ${err.code},message is ${err.message}`);  
      return;  
    }  
    console.info('Succeeded in getting KVStore');  
    kvStore = store;  
    kvStore = null;  
    store = null;  
    kvManager.closeKVStore('appId', 'storeId', (err)=> {  
      if (err != undefined) {  
        console.error(`Failed to close KVStore.code is ${err.code},message is ${err.message}`);  
        return;  
      }  
      console.info('Succeeded in closing KVStore');  
    });  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let kvStore: distributedKVStore.SingleKVStore | null;  
  
const options: distributedKVStore.Options = {  
  createIfMissing: true,  
  encrypt: false,  
  backup: false,  
  autoSync: true,  
  kvStoreType: distributedKVStore.KVStoreType.SINGLE_VERSION,  
  schema: undefined,  
  securityLevel: distributedKVStore.SecurityLevel.S2,  
}  
try {  
  kvManager.getKVStore<distributedKVStore.SingleKVStore>('storeId', options).then(async (store: distributedKVStore.SingleKVStore | null) => {  
    console.info('Succeeded in getting KVStore');  
    kvStore = store;  
    kvStore = null;  
    store = null;  
    kvManager.closeKVStore('appId', 'storeId').then(() => {  
      console.info('Succeeded in closing KVStore');  
    }).catch((err: BusinessError) => {  
      console.error(`Failed to close KVStore.code is ${err.code},message is ${err.message}`);  
    });  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to get KVStore.code is ${err.code},message is ${err.message}`);  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`Failed to close KVStore.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
### deleteKVStore    
通过storeId的值删除指定的分布式键值数据库，使用Promise异步回调。  
 **调用形式：**     
    
- deleteKVStore(appId: string, storeId: string, callback: AsyncCallback\<void>): void    
起始版本： 9    
- deleteKVStore(appId: string, storeId: string): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| appId | string | true | 所调用数据库方的包名。 |  
| storeId | string | true | 要删除的数据库唯一标识符，长度不大于[MAX_STORE_ID_LENGTH](#constants)。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 15100004 | Not found. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let kvStore: distributedKVStore.SingleKVStore | null;  
  
const options: distributedKVStore.Options = {  
  createIfMissing: true,  
  encrypt: false,  
  backup: false,  
  autoSync: true,  
  kvStoreType: distributedKVStore.KVStoreType.SINGLE_VERSION,  
  schema: undefined,  
  securityLevel: distributedKVStore.SecurityLevel.S2,  
}  
try {  
  kvManager.getKVStore('store', options, async (err, store: distributedKVStore.SingleKVStore | null) => {  
    if (err != undefined) {  
      console.error(`Failed to get KVStore.code is ${err.code},message is ${err.message}`);  
      return;  
    }  
    console.info('Succeeded in getting KVStore');  
    kvStore = store;  
    kvStore = null;  
    store = null;  
    kvManager.deleteKVStore('appId', 'storeId', (err) => {  
      if (err != undefined) {  
        console.error(`Failed to delete KVStore.code is ${err.code},message is ${err.message}`);  
        return;  
      }  
      console.info(`Succeeded in deleting KVStore`);  
    });  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`Failed to delete KVStore.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let kvStore: distributedKVStore.SingleKVStore | null;  
  
const options: distributedKVStore.Options = {  
  createIfMissing: true,  
  encrypt: false,  
  backup: false,  
  autoSync: true,  
  kvStoreType: distributedKVStore.KVStoreType.SINGLE_VERSION,  
  schema: undefined,  
  securityLevel: distributedKVStore.SecurityLevel.S2,  
}  
try {  
  kvManager.getKVStore<distributedKVStore.SingleKVStore>('storeId', options).then(async (store: distributedKVStore.SingleKVStore | null) => {  
    console.info('Succeeded in getting KVStore');  
    kvStore = store;  
    kvStore = null;  
    store = null;  
    kvManager.deleteKVStore('appId', 'storeId').then(() => {  
      console.info('Succeeded in deleting KVStore');  
    }).catch((err: BusinessError) => {  
      console.error(`Failed to delete KVStore.code is ${err.code},message is ${err.message}`);  
    });  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to get KVStore.code is ${err.code},message is ${err.message}`);  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`Failed to delete KVStore.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
### getAllKVStoreId    
获取所有通过[getKVStore](#getkvstore)方法创建的且没有调用[deleteKVStore](#deletekvstore)方法删除的分布式键值数据库的storeId，使用Promise异步回调。  
 **调用形式：**     
    
- getAllKVStoreId(appId: string, callback: AsyncCallback\<string[]>): void    
起始版本： 9    
- getAllKVStoreId(appId: string): Promise\<string[]>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| appId | string | true | 所调用数据库方的包名。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回所有创建的分布式键值数据库的storeId。 |  
| Promise<string[]> | Promise对象。返回所有创建的分布式键值数据库的storeId。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  kvManager.getAllKVStoreId('appId', (err, data) => {  
    if (err != undefined) {  
      console.error(`Failed to get AllKVStoreId.code is ${err.code},message is ${err.message}`);  
      return;  
    }  
    console.info('Succeeded in getting AllKVStoreId');  
    console.info(`GetAllKVStoreId size = ${data.length}`);  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`Failed to get AllKVStoreId.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  console.info('GetAllKVStoreId');  
  kvManager.getAllKVStoreId('appId').then((data: string[]) => {  
    console.info('Succeeded in getting AllKVStoreId');  
    console.info(`GetAllKVStoreId size = ${data.length}`);  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to get AllKVStoreId.code is ${err.code},message is ${err.message}`);  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`Failed to get AllKVStoreId.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
### on('distributedDataServiceDie')    
订阅服务状态变更通知。如果服务终止，需要重新注册数据变更通知和同步完成事件回调通知，并且同步操作会返回失败。  
 **调用形式：**     
- on(event: 'distributedDataServiceDie', deathCallback: Callback\<void>): void  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.DistributedKVStore    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event | string | true | 订阅的事件名，固定为'distributedDataServiceDie'，即服务状态变更事件。 |  
| deathCallback | Callback<void> | true | 回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  console.info('KVManagerOn');  
  const deathCallback = () => {  
    console.info('death callback call');  
  }  
  kvManager.on('distributedDataServiceDie', deathCallback);  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
### off('distributedDataServiceDie')    
取消订阅服务状态变更通知。参数中的deathCallback必须是已经订阅过的deathCallback，否则会取消订阅失败。  
 **调用形式：**     
- off(event: 'distributedDataServiceDie', deathCallback?: Callback\<void>): void  
  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.DistributedKVStore    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event | string | true | 取消订阅的事件名，固定为'distributedDataServiceDie'，即服务状态变更事件。 |  
| deathCallback | Callback<void> | false | 回调函数。如果该参数不填，那么会将之前订阅过的所有的deathCallback取消订阅。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  console.info('KVManagerOff');  
  const deathCallback = () => {  
    console.info('death callback call');  
  }  
  kvManager.off('distributedDataServiceDie', deathCallback);  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
