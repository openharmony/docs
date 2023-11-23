# @ohos.data.relationalStore    
关系型数据库（Relational Database，RDB）是一种基于关系模型来管理数据的数据库。关系型数据库基于SQLite组件提供了一套完整的对本地数据库进行管理的机制，对外提供了一系列的增、删、改、查等接口，也可以直接运行用户输入的SQL语句来满足复场景需要。不支持Worker线程。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import relationalStore from '@ohos.data.relationalStore'    
```  
    
## AssetStatus<sup>(10+)</sup>    
描述资产附件的状态枚举。请使用枚举名称而非枚举值。    
    
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| ASSET_NORMAL | 0 | 表示资产状态正常。 |  
| ASSET_INSERT | 1 | 表示资产需要插入到云端。 |  
| ASSET_UPDATE | 2 | 表示资产需要更新到云端。 |  
| ASSET_DELETE | 3 | 表示资产需要在云端删除。 |  
| ASSET_ABNORMAL | 4 | 表示资产状态异常。 |  
| ASSET_DOWNLOADING | 5 | 表示资产正在下载到本地设备。 |  
    
## Asset<sup>(10+)</sup>    
记录资产附件（文件、图片、视频等类型文件）的相关信息。资产类型的相关接口暂不支持Datashare。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
### 属性    
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| name<sup>(10+)</sup> | string | false | true | 资产的名称。 |  
| uri<sup>(10+)</sup> | string | false | true | 资产的uri，在系统里的绝对路径。 |  
| path<sup>(10+)</sup> | string | false | true | 资产在应用沙箱里的路径。 |  
| createTime<sup>(10+)</sup> | string | false | true | 资产被创建出来的时间。 |  
| modifyTime<sup>(10+)</sup> | string | false | true | 资产最后一次被修改的时间。 |  
| size<sup>(10+)</sup> | string | false | true | 资产占用空间的大小。 |  
| status<sup>(10+)</sup> | AssetStatus | false | false | 资产的状态，默认值为ASSET_NORMAL。 |  
    
## Assets<sup>(10+)</sup>    
表示[Asset](#asset10)类型的数组。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
## ValueType    
用于表示允许的数据字段类型。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
    
| 取值范围 | 说明 |  
| --------| --------|  
|  | 表示值类型为空。 |  
| number | 表示值类型为数字。 |  
| string | 表示值类型为字符。 |  
| boolean | 表示值类型为布尔值。 |  
| Uint8Array | 表示值类型为Uint8类型的数组。 |  
| Asset | 表示值类型为附件Asset |  
| Assets | 表示值类型为附件数组Assets |  
    
## ValuesBucket    
用于存储键值对的类型。该类型不是多线程安全的，如果应用中存在多线程同时操作该类派生出的实例，注意加锁保护。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
## PRIKeyType<sup>(10+)</sup>    
用于表示数据库表某一行主键的数据类型。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
    
| 取值范围 | 说明 |  
| --------| --------|  
| number | 主键的类型可以是number。 |  
| string | 主键的类型可以是string。 |  
    
## StoreConfig    
管理关系数据库配置。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
### 属性    
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| name | string | false | true | 数据库文件名。 |  
| securityLevel | SecurityLevel | false | true | 设置数据库安全级别 |  
| encrypt | boolean | false | false | 指定数据库是否加密，默认不加密。<br/> true:加密。<br/> false:非加密。 |  
| dataGroupId<sup>(10+)</sup> | string | false | false | 模型约束：本模块接口仅可在Stage模型下使用。<br>应用组ID，需要向应用市场获取。<br/>**模型约束：** 此属性仅在Stage模型下可用。<br/>从API version 10开始，支持此可选参数。指定在此dataGroupId对应的沙箱路径下创建RdbStore实例，当此参数不填时，默认在本应用沙箱目录下创建RdbStore实例。| |  
    
## Progress<sup>(10+)</sup>    
描述端云同步过程的枚举。请使用枚举名称而非枚举值。    
    
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| SYNC_BEGIN | 0 | 表示端云同步过程开始。 |  
| SYNC_IN_PROGRESS | 1 | 表示正在端云同步过程中。 |  
| SYNC_FINISH | 2 | 表示端云同步过程已完成。 |  
    
## Statistic<sup>(10+)</sup>    
描述数据库表的端云同步过程的统计信息。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
### 属性    
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| total<sup>(10+)</sup> | number | false | true | 表示数据库表中需要端云同步的总行数。 |  
| successful<sup>(10+)</sup> | number | false | true | 表示数据库表中端云同步成功的行数。 |  
| failed<sup>(10+)</sup> | number | false | true | 表示数据库表中端云同步失败的行数。 |  
| remained<sup>(10+)</sup> | number | false | true | 表示数据库表中端云同步剩余未执行的行数。 |  
    
## TableDetails<sup>(10+)</sup>    
描述数据库表执行端云同步任务上传和下载的统计信息。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
### 属性    
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| upload<sup>(10+)</sup> | Statistic | false | true | 表示数据库表中端云同步上传过程的统计信息。 |  
| download<sup>(10+)</sup> | Statistic | false | true | 表示数据库表中端云同步下载过程的统计信息。 |  
    
## ProgressCode<sup>(10+)</sup>    
表示端云同步过程的状态。请使用枚举名称而非枚举值。    
    
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| SUCCESS | 0 | 表示端云同步过程成功。 |  
| UNKNOWN_ERROR | 1 | 表示端云同步过程遇到未知错误。 |  
| NETWORK_ERROR | 2 | 表示端云同步过程遇到网络错误。 |  
| CLOUD_DISABLED | 3 | 表示云端不可用。 |  
| LOCKED_BY_OTHERS | 4 | 表示有其他设备正在端云同步，本设备无法进行端云同步。<br>请确保无其他设备占用云端资源后，再使用本设备进行端云同步任务。 |  
| RECORD_LIMIT_EXCEEDED | 5 | 表示本次端云同步需要同步的条目或大小超出最大值。由云端配置最大值。 |  
| NO_SPACE_FOR_ASSET | 6 | 表示云空间剩余空间小于待同步的资产大小。 |  
    
## ProgressDetails<sup>(10+)</sup>    
描述数据库整体执行端云同步任务上传和下载的统计信息。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
### 属性    
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| schedule<sup>(10+)</sup> | Progress | false | true | 表示端云同步过程。 |  
| code<sup>(10+)</sup> | ProgressCode | false | true | 表示端云同步过程的状态。 |  
| details<sup>(10+)</sup> | {       [table: string]: TableDetails;     } | false | true | 表示端云同步各表的统计信息。<br>键表示表名，值表示该表的端云同步过程统计信息。 |  
    
## SecurityLevel    
数据库的安全级别枚举。    
    
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| S1 | 1 | 表示数据库的安全级别为低级别，当数据泄露时会产生较低影响。例如，包含壁纸等系统数据的数据库。 |  
| S2 | 2 | 表示数据库的安全级别为中级别，当数据泄露时会产生较大影响。例如，包含录音、视频等用户生成数据或通话记录等信息的数据库。 |  
| S3 | 3 | 表示数据库的安全级别为高级别，当数据泄露时会产生重大影响。例如，包含用户运动、健康、位置等信息的数据库。 |  
| S4 | 4 | 表示数据库的安全级别为关键级别，当数据泄露时会产生严重影响。例如，包含认证凭据、财务数据等信息的数据库。 |  
    
## SyncMode    
指数据库同步模式。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| SYNC_MODE_PUSH | 0 | 系统能力：SystemCapability.DistributedDataManager.RelationalStore.Core<br>表示数据从本地设备推送到远程设备。<br>**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core |  
| SYNC_MODE_PULL | 1 | 系统能力：SystemCapability.DistributedDataManager.RelationalStore.Core<br>表示数据从远程设备拉至本地设备。<br>**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core |  
| SYNC_MODE_TIME_FIRST<sup>(10+)</sup> | 2 | 系统能力：SystemCapability.DistributedDataManager.CloudSync.Client<br>表示数据从修改时间较近的一端同步到修改时间较远的一端。请使用枚举名称而非枚举值。<br>**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Client |  
| SYNC_MODE_NATIVE_FIRST<sup>(10+)</sup> | 3 | 系统能力：SystemCapability.DistributedDataManager.CloudSync.Client<br>表示数据从本地设备同步到云端。请使用枚举名称而非枚举值。<br>**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Client |  
| SYNC_MODE_CLOUD_FIRST<sup>(10+)</sup> | 4 | 系统能力：SystemCapability.DistributedDataManager.CloudSync.Client<br>表示数据从云端同步到本地设备。请使用枚举名称而非枚举值。<br>**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Client |  
    
## SubscribeType    
描述订阅类型。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| SUBSCRIBE_TYPE_REMOTE | 0 | 系统能力：SystemCapability.DistributedDataManager.RelationalStore.Core<br>订阅远程数据更改。<br>**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core |  
| SUBSCRIBE_TYPE_CLOUD<sup>(10+)</sup> | 1 | 系统能力：SystemCapability.DistributedDataManager.CloudSync.Client<br>订阅云端数据更改。请使用枚举名称而非枚举值。<br>**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Client |  
| SUBSCRIBE_TYPE_CLOUD_DETAILS<sup>(10+)</sup> | 2 | 系统能力：SystemCapability.DistributedDataManager.CloudSync.Client<br>订阅云端数据更改详情。请使用枚举名称而非枚举值。<br>**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Client |  
    
## ChangeType<sup>(10+)</sup>    
描述数据变更类型的枚举。请使用枚举名称而非枚举值。    
    
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| DATA_CHANGE | 0 | 表示是数据发生变更。 |  
| ASSET_CHANGE | 1 | 表示是资产附件发生了变更。 |  
    
## ChangeInfo<sup>(10+)</sup>    
记录端云同步过程详情。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
### 属性    
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| table<sup>(10+)</sup> | string | false | true | 表示发生变化的表的名称。 |  
| type<sup>(10+)</sup> | ChangeType | false | true | 表示发生变化的数据的类型，数据或者资产附件发生变化。 |  
| inserted<sup>(10+)</sup> | Array<string> \| Array<number> | false | true | 记录插入数据的位置，如果该表的主键是string类型，该值是主键的值，否则该值表示插入数据的行号。 |  
| updated<sup>(10+)</sup> | Array<string> \| Array<number> | false | true | 记录更新数据的位置，如果该表的主键是string类型，该值是主键的值，否则该值表示更新数据的行号。 |  
| deleted<sup>(10+)</sup> | Array<string> \| Array<number> | false | true | 记录删除数据的位置，如果该表的主键是string类型，该值是主键的值，否则该值表示删除数据的行号。 |  
    
## DistributedType<sup>(10+)</sup>    
描述表的分布式类型的枚举。请使用枚举名称而非枚举值。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| DISTRIBUTED_DEVICE | 0 | 系统能力：SystemCapability.DistributedDataManager.RelationalStore.Core<br>表示在不同设备之间分布式的数据库表。<br>**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core |  
| DISTRIBUTED_CLOUD | 1 | 系统能力：SystemCapability.DistributedDataManager.CloudSync.Client<br>表示在设备和云端之间分布式的数据库表。<br>**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Client |  
    
## DistributedConfig<sup>(10+)</sup>    
记录表的分布式配置信息。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
### 属性    
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| autoSync<sup>(10+)</sup> | boolean | false | true | 该值为true时，表示该表支持自动同步和手动同步；该值为false时，表示该表只支持手动同步，不支持自动同步。 |  
    
## ConflictResolution<sup>(10+)</sup>    
插入和修改接口的冲突解决方式。    
    
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| ON_CONFLICT_NONE | 0 | 表示当冲突发生时，不做任何处理。 |  
| ON_CONFLICT_ROLLBACK | 1 | 表示当冲突发生时，中止SQL语句并回滚当前事务。 |  
| ON_CONFLICT_ABORT | 2 | 表示当冲突发生时，中止当前SQL语句，并撤销当前 SQL 语句所做的任何更改，但是由同一事务中先前的 SQL 语句引起的更改被保留并且事务保持活动状态。 |  
| ON_CONFLICT_FAIL | 3 | 表示当冲突发生时，中止当前 SQL 语句。但它不会撤销失败的 SQL 语句的先前更改，也不会结束事务。 |  
| ON_CONFLICT_IGNORE | 4 | 表示当冲突发生时，跳过包含违反约束的行并继续处理 SQL 语句的后续行。 |  
| ON_CONFLICT_REPLACE | 5 | 表示当冲突发生时，在插入或更新当前行之前删除导致约束违例的预先存在的行，并且命令会继续正常执行。 |  
    
## RdbPredicates    
表示关系型数据库（RDB）的谓词。该类确定RDB中条件表达式的值是true还是false。该类型不是多线程安全的，如果应用中存在多线程同时操作该类派生出的实例，注意加锁保护。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
### inDevices    
同步分布式数据库时连接到组网内指定的远程设备。  
 **调用形式：**     
- inDevices(devices: Array\<string>): RdbPredicates  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| devices | Array<string> | true | 指定的组网内的远程设备ID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回与指定字段匹配的谓词。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import deviceManager from '@ohos.distributedDeviceManager';  
  
let dmInstance: deviceManager.DeviceManager;  
let deviceIds: Array<string> = [];  
  
try {  
  dmInstance = deviceManager.createDeviceManager("com.example.appdatamgrverify");  
  let devices: Array<deviceManager.DeviceBasicInfo> = dmInstance.getAvailableDeviceListSync();  
  for (let i = 0; i < devices.length; i++) {  
    deviceIds[i] = devices[i].networkId!;  
  }  
} catch (err) {  
  let code = (err as BusinessError).code;  
  let message = (err as BusinessError).message  
  console.error("createDeviceManager errCode:" + code + ",errMessage:" + message);  
}  
  
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");  
predicates.inDevices(deviceIds);  
  
if(store != undefined) {  
  // 设置数据库版本  
  (store as relationalStore.RdbStore).version = 3;  
  // 获取数据库版本  
  console.info(`RdbStore version is ${(store as relationalStore.RdbStore).version}`);  
}  
    
```    
  
    
### inAllDevices    
同步分布式数据库时连接到组网内所有的远程设备。  
 **调用形式：**     
- inAllDevices(): RdbPredicates  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回与指定字段匹配的谓词。 |  
    
 **示例代码：**   
```ts    
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");  
predicates.equalTo("NAME", "lisi");    
```    
  
    
### equalTo    
配置谓词以匹配数据字段为ValueType且值等于指定值的字段。  
 **调用形式：**     
- equalTo(field: string, value: ValueType): RdbPredicates  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 数据库表中的列名。 |  
| value | ValueType | true | 指示要与谓词匹配的值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回与指定字段匹配的谓词。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");  
predicates.notEqualTo("NAME", "lisi");    
```    
  
    
### notEqualTo    
配置谓词以匹配数据字段为ValueType且值不等于指定值的字段。  
 **调用形式：**     
- notEqualTo(field: string, value: ValueType): RdbPredicates  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 数据库表中的列名。 |  
| value | ValueType | true | 指示要与谓词匹配的值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回与指定字段匹配的谓词。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");  
predicates.notEqualTo("NAME", "lisi");    
```    
  
    
### beginWrap    
beginWrap。  
 **调用形式：**     
- beginWrap(): RdbPredicates  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回带有左括号的Rdb谓词。 |  
    
 **示例代码：**   
```ts    
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");  
predicates.equalTo("NAME", "lisi")  
    .beginWrap()  
    .equalTo("AGE", 18)  
    .or()  
    .equalTo("SALARY", 200.5)  
    .endWrap()    
```    
  
    
### endWrap    
向谓词添加右括号。  
 **调用形式：**     
- endWrap(): RdbPredicates  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回带有右括号的Rdb谓词。 |  
    
 **示例代码：**   
```ts    
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");  
predicates.equalTo("NAME", "lisi")  
    .beginWrap()  
    .equalTo("AGE", 18)  
    .or()  
    .equalTo("SALARY", 200.5)  
    .endWrap()    
```    
  
    
### or    
将或条件添加到谓词中。  
 **调用形式：**     
- or(): RdbPredicates  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回带有或条件的Rdb谓词。 |  
    
 **示例代码：**   
```ts    
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");  
predicates.equalTo("NAME", "Lisa")  
    .or()  
    .equalTo("NAME", "Rose")    
```    
  
    
### and    
向谓词添加和条件。  
 **调用形式：**     
- and(): RdbPredicates  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回带有和条件的Rdb谓词。 |  
    
 **示例代码：**   
```ts    
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");  
predicates.equalTo("NAME", "Lisa")  
    .or()  
    .equalTo("NAME", "Rose")    
```    
  
    
### contains    
配置谓词以匹配数据字段为string且value包含指定值的字段。  
 **调用形式：**     
- contains(field: string, value: string): RdbPredicates  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 数据库表中的列名。 |  
| value | string | true | 指示要与谓词匹配的值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回与指定字段匹配的谓词。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");  
predicates.contains("NAME", "os");    
```    
  
    
### beginsWith    
配置谓词以匹配数据字段为string且值以指定字符串开头的字段。  
 **调用形式：**     
- beginsWith(field: string, value: string): RdbPredicates  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 数据库表中的列名。 |  
| value | string | true | 指示要与谓词匹配的值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回与指定字段匹配的谓词。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");  
predicates.beginsWith("NAME", "os");    
```    
  
    
### endsWith    
配置谓词以匹配数据字段为string且值以指定字符串结尾的字段。  
 **调用形式：**     
- endsWith(field: string, value: string): RdbPredicates  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 数据库表中的列名。 |  
| value | string | true | 指示要与谓词匹配的值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回与指定字段匹配的谓词。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");  
predicates.endsWith("NAME", "se");    
```    
  
    
### isNull    
配置谓词以匹配值为null的字段。  
 **调用形式：**     
- isNull(field: string): RdbPredicates  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 数据库表中的列名。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回与指定字段匹配的谓词。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");  
predicates.isNull("NAME");    
```    
  
    
### isNotNull    
配置谓词以匹配值不为null的指定字段。  
 **调用形式：**     
- isNotNull(field: string): RdbPredicates  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 数据库表中的列名。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回与指定字段匹配的谓词。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");  
predicates.isNotNull("NAME");    
```    
  
    
### like    
配置谓词以匹配数据字段为string且值类似于指定字符串的字段。  
 **调用形式：**     
- like(field: string, value: string): RdbPredicates  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 数据库表中的列名。 |  
| value | string | true | 指示要与谓词匹配的值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回与指定字段匹配的谓词。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");  
predicates.like("NAME", "%os%");    
```    
  
    
### glob    
配置RdbPredicates匹配数据字段为string的指定字段。  
 **调用形式：**     
- glob(field: string, value: string): RdbPredicates  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 数据库表中的列名。 |  
| value | string | true | 指示要与谓词匹配的值。<br>支持通配符，*表示0个、1个或多个数字或字符，?表示1个数字或字符。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回与指定字段匹配的谓词。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");  
predicates.glob("NAME", "?h*g");    
```    
  
    
### between    
将谓词配置为匹配数据字段为ValueType且value在给定范围内的指定字段。  
 **调用形式：**     
- between(field: string, low: ValueType, high: ValueType): RdbPredicates  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 数据库表中的列名。 |  
| low | ValueType | true | 指示与谓词匹配的最小值。 |  
| high | ValueType | true | 指示要与谓词匹配的最大值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回与指定字段匹配的谓词。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");  
predicates.between("AGE", 10, 50);    
```    
  
    
### notBetween    
配置RdbPredicates以匹配数据字段为ValueType且value超出给定范围的指定字段。  
 **调用形式：**     
- notBetween(field: string, low: ValueType, high: ValueType): RdbPredicates  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 数据库表中的列名。 |  
| low | ValueType | true | 指示与谓词匹配的最小值。 |  
| high | ValueType | true | 指示要与谓词匹配的最大值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回与指定字段匹配的谓词。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");  
predicates.notBetween("AGE", 10, 50);    
```    
  
    
### greaterThan    
配置谓词以匹配数据字段为ValueType且值大于指定值的字段。  
 **调用形式：**     
- greaterThan(field: string, value: ValueType): RdbPredicates  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 数据库表中的列名。 |  
| value | ValueType | true | 指示要与谓词匹配的值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回与指定字段匹配的谓词。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");  
predicates.greaterThan("AGE", 18);    
```    
  
    
### lessThan    
配置谓词以匹配数据字段为valueType且value小于指定值的字段。  
 **调用形式：**     
- lessThan(field: string, value: ValueType): RdbPredicates  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 数据库表中的列名。 |  
| value | ValueType | true | 指示要与谓词匹配的值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回与指定字段匹配的谓词。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");  
predicates.lessThan("AGE", 20);    
```    
  
    
### greaterThanOrEqualTo    
配置谓词以匹配数据字段为ValueType且value大于或等于指定值的字段。  
 **调用形式：**     
- greaterThanOrEqualTo(field: string, value: ValueType): RdbPredicates  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 数据库表中的列名。 |  
| value | ValueType | true | 指示要与谓词匹配的值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回与指定字段匹配的谓词。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");  
predicates.greaterThanOrEqualTo("AGE", 18);    
```    
  
    
### lessThanOrEqualTo    
配置谓词以匹配数据字段为ValueType且value小于或等于指定值的字段。  
 **调用形式：**     
- lessThanOrEqualTo(field: string, value: ValueType): RdbPredicates  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 数据库表中的列名。 |  
| value | ValueType | true | 指示要与谓词匹配的值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回与指定字段匹配的谓词。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");  
predicates.lessThanOrEqualTo("AGE", 20);    
```    
  
    
### orderByAsc    
配置谓词以匹配其值按升序排序的列。  
 **调用形式：**     
- orderByAsc(field: string): RdbPredicates  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 数据库表中的列名。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回与指定字段匹配的谓词。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");  
predicates.orderByAsc("NAME");    
```    
  
    
### orderByDesc    
配置谓词以匹配其值按降序排序的列。  
 **调用形式：**     
- orderByDesc(field: string): RdbPredicates  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 数据库表中的列名。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回与指定字段匹配的谓词。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");  
predicates.orderByDesc("AGE");    
```    
  
    
### distinct    
配置谓词以过滤重复记录并仅保留其中一个。  
 **调用形式：**     
- distinct(): RdbPredicates  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回可用于过滤重复记录的谓词。 |  
    
 **示例代码：**   
```ts    
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");  
predicates.equalTo("NAME", "Rose").distinct();    
```    
  
    
### limitAs    
设置最大数据记录数的谓词。  
 **调用形式：**     
- limitAs(value: number): RdbPredicates  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | number | true | 最大数据记录数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回可用于设置最大数据记录数的谓词。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");  
predicates.equalTo("NAME", "Rose").limitAs(3);    
```    
  
    
### offsetAs    
配置RdbPredicates以指定返回结果的起始位置。  
 **调用形式：**     
- offsetAs(rowOffset: number): RdbPredicates  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| rowOffset | number | true | 返回结果的起始位置，取值为正整数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回具有指定返回结果起始位置的谓词。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");  
predicates.equalTo("NAME", "Rose").offsetAs(3);    
```    
  
    
### groupBy    
配置RdbPredicates按指定列分组查询结果。  
 **调用形式：**     
- groupBy(fields: Array\<string>): RdbPredicates  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fields | Array<string> | true | 指定分组依赖的列名。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回分组查询列的谓词。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");  
predicates.groupBy(["AGE", "NAME"]);    
```    
  
    
### indexedBy    
配置RdbPredicates以指定索引列。  
 **调用形式：**     
- indexedBy(field: string): RdbPredicates  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 索引列的名称。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回具有指定索引列的RdbPredicates。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");  
predicates.indexedBy("SALARY_INDEX");    
```    
  
    
### in    
配置RdbPredicates以匹配数据字段为ValueType数组且值在给定范围内的指定字段。  
 **调用形式：**     
- in(field: string, value: Array\<ValueType>): RdbPredicates  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 数据库表中的列名。 |  
| value | Array<ValueType> | true | 以ValueType型数组形式指定的要匹配的值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回与指定字段匹配的谓词。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");  
predicates.in("AGE", [18, 20]);    
```    
  
    
### notIn    
将RdbPredicates配置为匹配数据字段为ValueType且值超出给定范围的指定字段。  
 **调用形式：**     
- notIn(field: string, value: Array\<ValueType>): RdbPredicates  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field | string | true | 数据库表中的列名。 |  
| value | Array<ValueType> | true | 以ValueType数组形式指定的要匹配的值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回与指定字段匹配的谓词。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");  
predicates.notIn("NAME", ["Lisa", "Rose"]);    
```    
  
    
## ResultSet    
提供通过查询数据库生成的数据库结果集的访问方法。结果集是指用户调用关系型数据库查询接口之后返回的结果集合，提供了多种灵活的数据访问方式，以便用户获取各项数据。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
### 属性    
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| columnNames | Array<string> | false | true | 获取结果集中所有列的名称。 |  
| columnCount | number | false | true | 获取结果集中的列数。 |  
| rowCount | number | false | true | 获取结果集中的行数。 |  
| rowIndex | number | false | true | 获取结果集当前行的索引。 |  
| isAtFirstRow | boolean | false | true | 检查结果集是否位于第一行。 |  
| isAtLastRow | boolean | false | true | 检查结果集是否位于最后一行。 |  
| isEnded | boolean | false | true | 检查结果集是否位于最后一行之后。 |  
| isStarted | boolean | false | true | 检查指针是否移动过。 |  
| isClosed | boolean | false | true | 检查当前结果集是否关闭。 |  
    
### getColumnIndex    
根据指定的列名获取列索引。  
 **调用形式：**     
- getColumnIndex(columnName: string): number  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| columnName | string | true | 表示结果集中指定列的名称。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回指定列的索引。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 14800013 | The column value is null or the column type is incompatible. |  
| 401 |  |  
    
 **示例代码：**   
```ts    
if(resultSet != undefined) {  
  const id = (resultSet as relationalStore.ResultSet).getLong((resultSet as relationalStore.ResultSet).getColumnIndex("ID"));  
  const name = (resultSet as relationalStore.ResultSet).getString((resultSet as relationalStore.ResultSet).getColumnIndex("NAME"));  
  const age = (resultSet as relationalStore.ResultSet).getLong((resultSet as relationalStore.ResultSet).getColumnIndex("AGE"));  
  const salary = (resultSet as relationalStore.ResultSet).getDouble((resultSet as relationalStore.ResultSet).getColumnIndex("SALARY"));  
}    
```    
  
    
### getColumnName    
根据指定的列索引获取列名。  
 **调用形式：**     
- getColumnName(columnIndex: number): string  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| columnIndex | number | true | 表示结果集中指定列的索引。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回指定列的名称。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 14800013 | The column value is null or the column type is incompatible. |  
| 401 |  |  
    
 **示例代码：**   
```ts    
if(resultSet != undefined) {  
const id = (resultSet as relationalStore.ResultSet).getColumnName(0);  
const name = (resultSet as relationalStore.ResultSet).getColumnName(1);  
const age = (resultSet as relationalStore.ResultSet).getColumnName(2);  
}    
```    
  
    
### goTo    
向前或向后转至结果集的指定行，相对于其当前位置偏移。  
 **调用形式：**     
- goTo(offset: number): boolean  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| offset | number | true | 表示相对于当前位置的偏移量。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 如果成功移动结果集，则为true；否则返回false。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 14800012 | The result set is empty or the specified location is invalid. |  
| 401 |  |  
    
 **示例代码：**   
```ts    
if(resultSet != undefined) {  
(resultSet as relationalStore.ResultSet).goTo(1);  
}    
```    
  
    
### goToRow    
转到结果集的指定行。  
 **调用形式：**     
- goToRow(position: number): boolean  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| position | number | true | 表示要移动到的指定位置。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 如果成功移动结果集，则为true；否则返回false。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 14800012 | The result set is empty or the specified location is invalid. |  
| 401 |  |  
    
 **示例代码：**   
```ts    
if(resultSet != undefined) {  
(resultSet as relationalStore.ResultSet).goToRow(5);  
}    
```    
  
    
### goToFirstRow    
转到结果集的第一行。  
 **调用形式：**     
- goToFirstRow(): boolean  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 如果成功移动结果集，则为true；否则返回false。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 14800012 | The result set is empty or the specified location is invalid. |  
    
 **示例代码：**   
```ts    
if(resultSet != undefined) {  
(resultSet as relationalStore.ResultSet).goToFirstRow();  
}    
```    
  
    
### goToLastRow    
转到结果集的最后一行。  
 **调用形式：**     
- goToLastRow(): boolean  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 如果成功移动结果集，则为true；否则返回false。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 14800012 | The result set is empty or the specified location is invalid. |  
    
 **示例代码：**   
```ts    
if(resultSet != undefined) {  
(resultSet as relationalStore.ResultSet).goToLastRow();  
}    
```    
  
    
### goToNextRow    
转到结果集的下一行。  
 **调用形式：**     
- goToNextRow(): boolean  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 如果成功移动结果集，则为true；否则返回false。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 14800012 | The result set is empty or the specified location is invalid. |  
    
 **示例代码：**   
```ts    
if(resultSet != undefined) {  
(resultSet as relationalStore.ResultSet).goToNextRow();  
}    
```    
  
    
### goToPreviousRow    
转到结果集的上一行。  
 **调用形式：**     
- goToPreviousRow(): boolean  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 如果成功移动结果集，则为true；否则返回false。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 14800012 | The result set is empty or the specified location is invalid. |  
    
 **示例代码：**   
```ts    
if(resultSet != undefined) {  
(resultSet as relationalStore.ResultSet).goToPreviousRow();  
}    
```    
  
    
### getBlob    
以字节数组的形式获取当前行中指定列的值。  
 **调用形式：**     
- getBlob(columnIndex: number): Uint8Array  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| columnIndex | number | true | 指定的列索引，从0开始。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Uint8Array | 以字节数组的形式返回指定列的值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 14800013 | The column value is null or the column type is incompatible. |  
| 401 |  |  
    
 **示例代码：**   
```ts    
if(resultSet != undefined) {  
const codes = (resultSet as relationalStore.ResultSet).getBlob((resultSet as relationalStore.ResultSet).getColumnIndex("CODES"));  
}    
```    
  
    
### getString    
以字符串形式获取当前行中指定列的值。  
 **调用形式：**     
- getString(columnIndex: number): string  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| columnIndex | number | true | 指定的列索引，从0开始。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 以字符串形式返回指定列的值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 14800013 | The column value is null or the column type is incompatible. |  
| 401 |  |  
    
 **示例代码：**   
```ts    
if(resultSet != undefined) {  
const name = (resultSet as relationalStore.ResultSet).getString((resultSet as relationalStore.ResultSet).getColumnIndex("NAME"));  
}    
```    
  
    
### getLong    
以Long形式获取当前行中指定列的值。  
 **调用形式：**     
- getLong(columnIndex: number): number  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| columnIndex | number | true | 指定的列索引，从0开始。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 以Long形式返回指定列的值。<br>该接口支持的数据范围是：Number.MIN_SAFE_INTEGER ~ Number.MAX_SAFE_INTEGER，若超出该范围，建议使用[getDouble](#getdouble)。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 14800013 | The column value is null or the column type is incompatible. |  
| 401 |  |  
    
 **示例代码：**   
```ts    
if(resultSet != undefined) {  
const age = (resultSet as relationalStore.ResultSet).getLong((resultSet as relationalStore.ResultSet).getColumnIndex("AGE"));  
 }    
```    
  
    
### getDouble    
以double形式获取当前行中指定列的值。  
 **调用形式：**     
- getDouble(columnIndex: number): number  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| columnIndex | number | true | 指定的列索引，从0开始。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 以double形式返回指定列的值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 14800013 | The column value is null or the column type is incompatible. |  
| 401 |  |  
    
 **示例代码：**   
```ts    
if(resultSet != undefined) {  
const salary = (resultSet as relationalStore.ResultSet).getDouble((resultSet as relationalStore.ResultSet).getColumnIndex("SALARY"));  
}    
```    
  
    
### getAsset<sup>(10+)</sup>    
以[Asset](#asset10)形式获取当前行中指定列的值。  
 **调用形式：**     
- getAsset(columnIndex: number): Asset  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| columnIndex | number | true | 指定的列索引，从0开始。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Asset | 以Asset形式返回指定列的值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 14800013 | The column value is null or the column type is incompatible. |  
| 401 |  |  
    
 **示例代码：**   
```ts    
if(resultSet != undefined) {  
const doc = (resultSet as relationalStore.ResultSet).getAsset((resultSet as relationalStore.ResultSet).getColumnIndex("DOC"));  
}    
```    
  
    
### getAssets<sup>(10+)</sup>    
以[Assets](#assets10)形式获取当前行中指定列的值。  
 **调用形式：**     
- getAssets(columnIndex: number): Assets  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| columnIndex | number | true | 指定的列索引，从0开始。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Assets | 以Assets形式返回指定列的值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 14800013 | The column value is null or the column type is incompatible. |  
| 401 |  |  
    
 **示例代码：**   
```ts    
if(resultSet != undefined) {  
const id = (resultSet as relationalStore.ResultSet).getColumnName(0);  
const name = (resultSet as relationalStore.ResultSet).getColumnName(1);  
const age = (resultSet as relationalStore.ResultSet).getColumnName(2);  
}    
```    
  
    
### isColumnNull    
检查当前行中指定列的值是否为null。  
 **调用形式：**     
- isColumnNull(columnIndex: number): boolean  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| columnIndex | number | true | 指定的列索引，从0开始。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 如果当前行中指定列的值为null，则返回true，否则返回false。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 14800013 | The column value is null or the column type is incompatible. |  
| 401 |  |  
    
 **示例代码：**   
```ts    
if(resultSet != undefined) {  
const isColumnNull = (resultSet as relationalStore.ResultSet).isColumnNull((resultSet as relationalStore.ResultSet).getColumnIndex("CODES"));  
}    
```    
  
    
### close    
关闭结果集。  
 **调用形式：**     
- close(): void  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 14800012 | The result set is empty or the specified location is invalid. |  
    
 **示例代码：**   
```ts    
if(resultSet != undefined) {  
(resultSet as relationalStore.ResultSet).close();  
}    
```    
  
    
 **示例代码：**   
```ts    
let resultSet: relationalStore.ResultSet | undefined = undefined;  
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");  
predicates.equalTo("AGE", 18);  
if(store != undefined) {  
  (store as relationalStore.RdbStore).query(predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"]).then((result: relationalStore.ResultSet) => {  
    resultSet = result;  
    console.info(`resultSet columnNames: ${resultSet.columnNames}`);  
    console.info(`resultSet columnCount: ${resultSet.columnCount}`);  
  });  
}    
```    
  
    
## RdbStore    
提供管理关系数据库(RDB)方法的接口。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
### 属性    
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| version<sup>(10+)</sup> | number | false | true | 设置和获取数据库版本，值为大于0的正整数。 |  
    
### insert    
向目标表中插入一行数据，使用callback异步回调。  
 **调用形式：**     
    
- insert(table: string, values: ValuesBucket, callback: AsyncCallback\<number>): void    
起始版本： 9    
- insert(table: string, values: ValuesBucket, callback: AsyncCallback\<number>): void    
起始版本： 10    
- insert(table: string, values: ValuesBucket, conflict: ConflictResolution, callback: AsyncCallback\<number>): void    
起始版本： 10    
- insert(table: string, values: ValuesBucket): Promise\<number>    
起始版本： 9    
- insert(table: string, values: ValuesBucket): Promise\<number>    
起始版本： 10    
- insert(table: string, values: ValuesBucket, conflict: ConflictResolution): Promise\<number>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| table | string | true | 指定的目标表名。 |  
| values | ValuesBucket | true | 表示要插入到表中的数据行。 |  
| conflict<sup>(10+)</sup> | ConflictResolution | true | 指定冲突解决方式。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 指定callback回调函数。如果操作成功，返回行ID；否则返回 |  
| Promise<number> | Promise对象。如果操作成功，返回行ID；否则返回-1。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 14800000 | Inner error. |  
| 14800047 | The WAL file size exceeds the default limit. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import { ValuesBucket } from '@ohos.data.ValuesBucket';  
  
let key1 = "NAME";  
let key2 = "AGE";  
let key3 = "SALARY";  
let key4 = "CODES";  
let value1 = "Lisa";  
let value2 = 18;  
let value3 = 100.5;  
let value4 = new Uint8Array([1, 2, 3, 4, 5]);  
const valueBucket: ValuesBucket = {  
  key1: value1,  
  key2: value2,  
  key3: value3,  
  key4: value4,  
};  
if(store != undefined) {  
  (store as relationalStore.RdbStore).insert("EMPLOYEE", valueBucket, relationalStore.ConflictResolution.ON_CONFLICT_REPLACE,  
    (err: BusinessError, rowId: number) => {  
      if (err) {  
        console.error(`Insert is failed, code is ${err.code},message is ${err.message}`);  
        return;  
      }  
      console.info(`Insert is successful, rowId = ${rowId}`);  
  })  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { ValuesBucket } from '@ohos.data.ValuesBucket';  
import { BusinessError } from "@ohos.base";  
  
let key1 = "NAME";  
let key2 = "AGE";  
let key3 = "SALARY";  
let key4 = "CODES";  
let value1 = "Lisa";  
let value2 = 18;  
let value3 = 100.5;  
let value4 = new Uint8Array([1, 2, 3, 4, 5]);  
const valueBucket: ValuesBucket = {  
  key1: value1,  
  key2: value2,  
  key3: value3,  
  key4: value4,  
};  
if(store != undefined) {  
  (store as relationalStore.RdbStore).insert("EMPLOYEE", valueBucket, relationalStore.ConflictResolution.ON_CONFLICT_REPLACE).then((rowId: number) => {  
    console.info(`Insert is successful, rowId = ${rowId}`);  
  }).catch((err: BusinessError) => {  
    console.error(`Insert is failed, code is ${err.code},message is ${err.message}`);  
  })  
}  
    
```    
  
    
### batchInsert    
向目标表中插入一组数据，使用callback异步回调。  
 **调用形式：**     
    
- batchInsert(table: string, values: Array\<ValuesBucket>, callback: AsyncCallback\<number>): void    
起始版本： 9    
- batchInsert(table: string, values: Array\<ValuesBucket>, callback: AsyncCallback\<number>): void    
起始版本： 10    
- batchInsert(table: string, values: Array\<ValuesBucket>): Promise\<number>    
起始版本： 9    
- batchInsert(table: string, values: Array\<ValuesBucket>): Promise\<number>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| table | string | true | 指定的目标表名。 |  
| values | Array<ValuesBucket> | true | 表示要插入到表中的一组数据。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 指定callback回调函数。如果操作成功，返回插入的数据个数，否则返回-1。 |  
| Promise<number> | Promise对象。如果操作成功，返回插入的数据个数，否则返回-1。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 14800000 | Inner error. |  
| 14800047 | The WAL file size exceeds the default limit. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import { ValuesBucket } from '@ohos.data.ValuesBucket';  
  
let key1 = "NAME";  
let key2 = "AGE";  
let key3 = "SALARY";  
let key4 = "CODES";  
let value1 = "Lisa";  
let value2 = 18;  
let value3 = 100.5;  
let value4 = new Uint8Array([1, 2, 3, 4, 5]);  
let value5 = "Jack";  
let value6 = 19;  
let value7 = 101.5;  
let value8 = new Uint8Array([6, 7, 8, 9, 10]);  
let value9 = "Tom";  
let value10 = 20;  
let value11 = 102.5;  
let value12 = new Uint8Array([11, 12, 13, 14, 15]);  
const valueBucket1: ValuesBucket = {  
  key1: value1,  
  key2: value2,  
  key3: value3,  
  key4: value4,  
};  
const valueBucket2: ValuesBucket = {  
  key1: value5,  
  key2: value6,  
  key3: value7,  
  key4: value8,  
};  
const valueBucket3: ValuesBucket = {  
  key1: value9,  
  key2: value10,  
  key3: value11,  
  key4: value12,  
};  
  
let valueBuckets = new Array(valueBucket1, valueBucket2, valueBucket3);  
if(store != undefined) {  
  (store as relationalStore.RdbStore).batchInsert("EMPLOYEE", valueBuckets, (err, insertNum) => {  
    if (err) {  
      console.error(`batchInsert is failed, code is ${err.code},message is ${err.message}`);  
      return;  
    }  
    console.info(`batchInsert is successful, the number of values that were inserted = ${insertNum}`);  
  })  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { ValuesBucket } from '@ohos.data.ValuesBucket';  
import { BusinessError } from "@ohos.base";  
  
let key1 = "NAME";  
let key2 = "AGE";  
let key3 = "SALARY";  
let key4 = "CODES";  
let value1 = "Lisa";  
let value2 = 18;  
let value3 = 100.5;  
let value4 = new Uint8Array([1, 2, 3, 4, 5]);  
let value5 = "Jack";  
let value6 = 19;  
let value7 = 101.5;  
let value8 = new Uint8Array([6, 7, 8, 9, 10]);  
let value9 = "Tom";  
let value10 = 20;  
let value11 = 102.5;  
let value12 = new Uint8Array([11, 12, 13, 14, 15]);  
const valueBucket1: ValuesBucket = {  
  key1: value1,  
  key2: value2,  
  key3: value3,  
  key4: value4,  
};  
const valueBucket2: ValuesBucket = {  
  key1: value5,  
  key2: value6,  
  key3: value7,  
  key4: value8,  
};  
const valueBucket3: ValuesBucket = {  
  key1: value9,  
  key2: value10,  
  key3: value11,  
  key4: value12,  
};  
  
let valueBuckets = new Array(valueBucket1, valueBucket2, valueBucket3);  
if(store != undefined) {  
  (store as relationalStore.RdbStore).batchInsert("EMPLOYEE", valueBuckets).then((insertNum: number) => {  
    console.info(`batchInsert is successful, the number of values that were inserted = ${insertNum}`);  
  }).catch((err: BusinessError) => {  
    console.error(`batchInsert is failed, code is ${err.code},message is ${err.message}`);  
  })  
}  
    
```    
  
    
### update    
根据DataSharePredicates的指定实例对象更新数据库中的数据，使用callback异步回调。  
 **调用形式：**     
    
- update(values: ValuesBucket, predicates: RdbPredicates, callback: AsyncCallback\<number>): void    
起始版本： 9    
- update(values: ValuesBucket, predicates: RdbPredicates, callback: AsyncCallback\<number>): void    
起始版本： 10    
- update(       values: ValuesBucket,       predicates: RdbPredicates,       conflict: ConflictResolution,       callback: AsyncCallback\<number>     ): void    
起始版本： 10    
- update(values: ValuesBucket, predicates: RdbPredicates): Promise\<number>    
起始版本： 9    
- update(values: ValuesBucket, predicates: RdbPredicates): Promise\<number>    
起始版本： 10    
- update(values: ValuesBucket, predicates: RdbPredicates, conflict: ConflictResolution): Promise\<number>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| values | ValuesBucket | true | values指示数据库中要更新的数据行。键值对与数据库表的列名相关联。 |  
| predicates | RdbPredicates | true | DataSharePredicates的实例对象指定的更新条件。 |  
| conflict<sup>(10+)</sup> | ConflictResolution | true | 指定冲突解决方式。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 指定的callback回调方法。返回受影响的行数。 |  
| Promise<number> | 指定的Promise回调方法。返回受影响的行数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 14800000 | Inner error. |  
| 14800047 | The WAL file size exceeds the default limit. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates'  
import { ValuesBucket } from '@ohos.data.ValuesBucket';  
  
let key1 = "NAME";  
let key2 = "AGE";  
let key3 = "SALARY";  
let key4 = "CODES";  
let value1 = "Rose";  
let value2 = 22;  
let value3 = 200.5;  
let value4 = new Uint8Array([1, 2, 3, 4, 5]);  
const valueBucket: ValuesBucket = {  
  key1: value1,  
  key2: value2,  
  key3: value3,  
  key4: value4,  
};  
let predicates = new dataSharePredicates.DataSharePredicates();  
predicates.equalTo("NAME", "Lisa");  
if(store != undefined) {  
  (store as relationalStore.RdbStore).update("EMPLOYEE", valueBucket, predicates, (err, rows) => {  
    if (err) {  
      console.error(`Updated failed, code is ${err.code},message is ${err.message}`);  
      return;  
    }  
    console.info(`Updated row count: ${rows}`);  
  })  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
import { ValuesBucket } from '@ohos.data.ValuesBucket';  
import { BusinessError } from "@ohos.base";  
  
let key1 = "NAME";  
let key2 = "AGE";  
let key3 = "SALARY";  
let key4 = "CODES";  
let value1 = "Rose";  
let value2 = 22;  
let value3 = 200.5;  
let value4 = new Uint8Array([1, 2, 3, 4, 5]);  
const valueBucket: ValuesBucket = {  
  key1: value1,  
  key2: value2,  
  key3: value3,  
  key4: value4,  
};  
let predicates = new dataSharePredicates.DataSharePredicates();  
predicates.equalTo("NAME", "Lisa");  
if(store != undefined) {  
  (store as relationalStore.RdbStore).update("EMPLOYEE", valueBucket, predicates).then(async (rows: Number) => {  
    console.info(`Updated row count: ${rows}`);  
  }).catch((err: BusinessError) => {  
    console.error(`Updated failed, code is ${err.code},message is ${err.message}`);  
  })  
}  
    
```    
  
    
### delete    
根据DataSharePredicates的指定实例对象从数据库中删除数据，使用callback异步回调。  
 **调用形式：**     
    
- delete(predicates: RdbPredicates, callback: AsyncCallback\<number>): void    
起始版本： 9    
- delete(predicates: RdbPredicates, callback: AsyncCallback\<number>): void    
起始版本： 10    
- delete(predicates: RdbPredicates): Promise\<number>    
起始版本： 9    
- delete(predicates: RdbPredicates): Promise\<number>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| predicates | RdbPredicates | true | DataSharePredicates的实例对象指定的删除条件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 指定callback回调函数。返回受影响的行数。 |  
| Promise<number> | Promise对象。返回受影响的行数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 14800000 | Inner error. |  
| 14800047 | The WAL file size exceeds the default limit. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
let predicates = new dataSharePredicates.DataSharePredicates();  
predicates.equalTo("NAME", "Lisa");  
if(store != undefined) {  
  (store as relationalStore.RdbStore).delete("EMPLOYEE", predicates, (err, rows) => {  
    if (err) {  
      console.error(`Delete failed, code is ${err.code},message is ${err.message}`);  
      return;  
    }  
    console.info(`Delete rows: ${rows}`);  
  })  
}    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
import { BusinessError } from "@ohos.base";  
  
let predicates = new dataSharePredicates.DataSharePredicates();  
predicates.equalTo("NAME", "Lisa");  
if(store != undefined) {  
  (store as relationalStore.RdbStore).delete("EMPLOYEE", predicates).then((rows: Number) => {  
    console.info(`Delete rows: ${rows}`);  
  }).catch((err: BusinessError) => {  
    console.error(`Delete failed, code is ${err.code},message is ${err.message}`);  
  })  
}  
    
```    
  
    
### query<sup>(10+)</sup>    
根据指定条件查询数据库中的数据，使用callback异步回调。  
 **调用形式：**     
    
- query(predicates: RdbPredicates, callback: AsyncCallback\<ResultSet>): void    
起始版本： 10    
- query(predicates: RdbPredicates, columns: Array\<string>, callback: AsyncCallback\<ResultSet>): void    
起始版本： 9    
- query(predicates: RdbPredicates, columns?: Array\<string>): Promise\<ResultSet>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| predicates | RdbPredicates | true | DataSharePredicates的实例对象指定的查询条件。 |  
| columns<sup>(9+)</sup> | Array<string> | true | 表示要查询的列。如果值为空，则查询应用于所有列。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 指定callback回调函数。如果操作成功，则返回ResultSet对象。 |  
| Promise<ResultSet> | Promise对象。如果操作成功，则返回ResultSet对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 14800000 | Inner error. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
let predicates = new dataSharePredicates.DataSharePredicates();  
predicates.equalTo("NAME", "Rose");  
if(store != undefined) {  
  (store as relationalStore.RdbStore).query("EMPLOYEE", predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"], (err, resultSet) => {  
    if (err) {  
      console.error(`Query failed, code is ${err.code},message is ${err.message}`);  
      return;  
    }  
    console.info(`ResultSet column names: ${resultSet.columnNames}, column count: ${resultSet.columnCount}`);  
    // resultSet是一个数据集合的游标，默认指向第-1个记录，有效的数据从0开始。  
    while (resultSet.goToNextRow()) {  
      const id = resultSet.getLong(resultSet.getColumnIndex("ID"));  
      const name = resultSet.getString(resultSet.getColumnIndex("NAME"));  
      const age = resultSet.getLong(resultSet.getColumnIndex("AGE"));  
      const salary = resultSet.getDouble(resultSet.getColumnIndex("SALARY"));  
      console.info(`id=${id}, name=${name}, age=${age}, salary=${salary}`);  
    }  
    // 释放数据集的内存  
    resultSet.close();  
  })  
}    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
import { BusinessError } from "@ohos.base";  
  
let predicates = new dataSharePredicates.DataSharePredicates();  
predicates.equalTo("NAME", "Rose");  
if(store != undefined) {  
  (store as relationalStore.RdbStore).query("EMPLOYEE", predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"]).then((resultSet: relationalStore.ResultSet) => {  
    console.info(`ResultSet column names: ${resultSet.columnNames}, column count: ${resultSet.columnCount}`);  
    // resultSet是一个数据集合的游标，默认指向第-1个记录，有效的数据从0开始。  
    while (resultSet.goToNextRow()) {  
      const id = resultSet.getLong(resultSet.getColumnIndex("ID"));  
      const name = resultSet.getString(resultSet.getColumnIndex("NAME"));  
      const age = resultSet.getLong(resultSet.getColumnIndex("AGE"));  
      const salary = resultSet.getDouble(resultSet.getColumnIndex("SALARY"));  
      console.info(`id=${id}, name=${name}, age=${age}, salary=${salary}`);  
    }  
    // 释放数据集的内存  
    resultSet.close();  
  }).catch((err: BusinessError) => {  
    console.error(`Query failed, code is ${err.code},message is ${err.message}`);  
  })  
}  
    
```    
  
    
### querySql<sup>(10+)</sup>    
根据指定SQL语句查询数据库中的数据，使用callback异步回调。  
 **调用形式：**     
    
- querySql(sql: string, callback: AsyncCallback\<ResultSet>): void    
起始版本： 10    
- querySql(sql: string, bindArgs: Array\<ValueType>, callback: AsyncCallback\<ResultSet>): void    
起始版本： 9    
- querySql(sql: string, bindArgs?: Array\<ValueType>): Promise\<ResultSet>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| sql | string | true | 指定要执行的SQL语句。 |  
| bindArgs<sup>(9+)</sup> | Array<ValueType> | true | SQL语句中参数的值。该值与sql参数语句中的占位符相对应。当sql参数语句完整时，该参数需为空数组。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 指定callback回调函数。如果操作成功，则返回ResultSet对象。 |  
| Promise<ResultSet> | Promise对象。如果操作成功，则返回ResultSet对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | 指定callback回调函数。如果操作成功，则返回ResultSet对象。 |  
| 14800000 | Inner error. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
if(store != undefined) {  
  (store as relationalStore.RdbStore).querySql("SELECT * FROM EMPLOYEE CROSS JOIN BOOK WHERE BOOK.NAME = ?", ['sanguo'], (err, resultSet) => {  
    if (err) {  
      console.error(`Query failed, code is ${err.code},message is ${err.message}`);  
      return;  
    }  
    console.info(`ResultSet column names: ${resultSet.columnNames}, column count: ${resultSet.columnCount}`);  
    // resultSet是一个数据集合的游标，默认指向第-1个记录，有效的数据从0开始。  
    while (resultSet.goToNextRow()) {  
      const id = resultSet.getLong(resultSet.getColumnIndex("ID"));  
      const name = resultSet.getString(resultSet.getColumnIndex("NAME"));  
      const age = resultSet.getLong(resultSet.getColumnIndex("AGE"));  
      const salary = resultSet.getDouble(resultSet.getColumnIndex("SALARY"));  
      console.info(`id=${id}, name=${name}, age=${age}, salary=${salary}`);  
    }  
    // 释放数据集的内存  
    resultSet.close();  
  })  
}    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from "@ohos.base";  
  
if(store != undefined) {  
  (store as relationalStore.RdbStore).querySql("SELECT * FROM EMPLOYEE CROSS JOIN BOOK WHERE BOOK.NAME = 'sanguo'").then((resultSet: relationalStore.ResultSet) => {  
    console.info(`ResultSet column names: ${resultSet.columnNames}, column count: ${resultSet.columnCount}`);  
    // resultSet是一个数据集合的游标，默认指向第-1个记录，有效的数据从0开始。  
    while (resultSet.goToNextRow()) {  
      const id = resultSet.getLong(resultSet.getColumnIndex("ID"));  
      const name = resultSet.getString(resultSet.getColumnIndex("NAME"));  
      const age = resultSet.getLong(resultSet.getColumnIndex("AGE"));  
      const salary = resultSet.getDouble(resultSet.getColumnIndex("SALARY"));  
      console.info(`id=${id}, name=${name}, age=${age}, salary=${salary}`);  
    }  
    // 释放数据集的内存  
    resultSet.close();  
  }).catch((err: BusinessError) => {  
    console.error(`Query failed, code is ${err.code},message is ${err.message}`);  
  })  
}  
    
```    
  
    
### getModifyTime<sup>(10+)</sup>    
获取数据库表中数据的最后修改时间，使用callback异步回调。  
 **调用形式：**     
    
- getModifyTime(table: string, columnName: string, primaryKeys: PRIKeyType[]): Promise\<ModifyTime>    
起始版本： 10    
- getModifyTime(       table: string,       columnName: string,       primaryKeys: PRIKeyType[],       callback: AsyncCallback\<ModifyTime>     ): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| table | string | true | 指定要查询的数据库表的表名。 |  
| columnName | string | true | 指定要查询的数据库表的列名。 |  
| primaryKeys | PRIKeyType[] | true | 指定要查询的行的主键。<br>如果数据库表无主键，参数columnName需传入"rowid"，此时primaryKeys为要查询的数据库表的行号。<br>如果数据库表无主键，参数columnName传入不为"rowid"，返回对应的错误码。| |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 指定callback回调函数。如果操作成功，则返回ModifyTime对象，表示数据的最后修改时间。 |  
| Promise<ModifyTime> | 返回ModifyTime类型的Promise对象，表示数据最后的修改时间。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 801 |  |  
| 14800000 | Inner error. |  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
let PRIKey = [1, 4, 2, 3];  
if(store != undefined) {  
  (store as relationalStore.RdbStore).getModifyTime("cloud_tasks", "uuid", PRIKey, (err, modifyTime: relationalStore.ModifyTime) => {  
    if (err) {  
      console.error(`getModifyTime failed, code is ${err.code},message is ${err.message}`);  
      return;  
    }  
    let size = modifyTime.size;  
  });  
}    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from "@ohos.base";  
  
let PRIKey = [1, 2, 3];  
if(store != undefined) {  
  (store as relationalStore.RdbStore).getModifyTime("cloud_tasks", "uuid", PRIKey)  
    .then((modifyTime: relationalStore.ModifyTime) => {  
      let size = modifyTime.size;  
    })  
    .catch((err: BusinessError) => {  
      console.error(`getModifyTime failed, code is ${err.code},message is ${err.message}`);  
    });  
}  
    
```    
  
    
### executeSql<sup>(10+)</sup>    
执行包含指定参数但不返回值的SQL语句，使用callback异步回调。  
 **调用形式：**     
    
- executeSql(sql: string, callback: AsyncCallback\<void>): void    
起始版本： 10    
- executeSql(sql: string, bindArgs: Array\<ValueType>, callback: AsyncCallback\<void>): void    
起始版本： 9    
- executeSql(sql: string, bindArgs: Array\<ValueType>, callback: AsyncCallback\<void>): void    
起始版本： 10    
- executeSql(sql: string, bindArgs?: Array\<ValueType>): Promise\<void>    
起始版本： 9    
- executeSql(sql: string, bindArgs?: Array\<ValueType>): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| sql | string | true | 指定要执行的SQL语句。 |  
| bindArgs<sup>(9+)</sup> | Array<ValueType> | true | SQL语句中参数的值。该值与sql参数语句中的占位符相对应。当sql参数语句完整时，该参数需为空数组。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 指定callback回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 14800047 | The WAL file size exceeds the default limit. |  
| 401 |  |  
| 14800000 | Inner error. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
const SQL_DELETE_TABLE = "DELETE FROM test WHERE name = ?"  
if(store != undefined) {  
  (store as relationalStore.RdbStore).executeSql(SQL_DELETE_TABLE, ['zhangsan'], (err) => {  
    if (err) {  
      console.error(`ExecuteSql failed, code is ${err.code},message is ${err.message}`);  
      return;  
    }  
    console.info(`Delete table done.`);  
  })  
}    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from "@ohos.base";  
  
const SQL_DELETE_TABLE = "DELETE FROM test WHERE name = 'zhangsan'"  
if(store != undefined) {  
  (store as relationalStore.RdbStore).executeSql(SQL_DELETE_TABLE).then(() => {  
    console.info(`Delete table done.`);  
  }).catch((err: BusinessError) => {  
    console.error(`ExecuteSql failed, code is ${err.code},message is ${err.message}`);  
  })  
}  
    
```    
  
    
### beginTransaction    
在开始执行SQL语句之前，开始事务。  
 **调用形式：**     
- beginTransaction(): void  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 14800000 | Inner error. |  
    
 **示例代码：**   
```ts    
import featureAbility from '@ohos.ability.featureAbility'  
import { ValuesBucket } from '@ohos.data.ValuesBucket';  
  
let context = getContext(this);  
  
let key1 = "name";  
let key2 = "age";  
let key3 = "SALARY";  
let key4 = "blobType";  
let value1 = "Lisi";  
let value2 = 18;  
let value3 = 100.5;  
let value4 = new Uint8Array([1, 2, 3]);  
const STORE_CONFIG: relationalStore.StoreConfig = {  
  name: "RdbTest.db",  
  securityLevel: relationalStore.SecurityLevel.S1  
};  
relationalStore.getRdbStore(context, STORE_CONFIG, async (err, store) => {  
  if (err) {  
    console.error(`GetRdbStore failed, code is ${err.code},message is ${err.message}`);  
    return;  
  }  
  store.beginTransaction();  
  const valueBucket: ValuesBucket = {  
    key1: value1,  
    key2: value2,  
    key3: value3,  
    key4: value4,  
  };  
  await store.insert("test", valueBucket);  
  store.commit();  
})  
    
```    
  
    
### beginTransaction<sup>(10+)</sup>  
 **调用形式：**     
- beginTransaction(): void  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 14800047 |  |  
| 401 |  |  
| 14800000 |  |  
    
 **示例代码：**   
```ts    
import featureAbility from '@ohos.ability.featureAbility'  
import { ValuesBucket } from '@ohos.data.ValuesBucket';  
  
let context = getContext(this);  
  
let key1 = "name";  
let key2 = "age";  
let key3 = "SALARY";  
let key4 = "blobType";  
let value1 = "Lisi";  
let value2 = 18;  
let value3 = 100.5;  
let value4 = new Uint8Array([1, 2, 3]);  
const STORE_CONFIG: relationalStore.StoreConfig = {  
  name: "RdbTest.db",  
  securityLevel: relationalStore.SecurityLevel.S1  
};  
relationalStore.getRdbStore(context, STORE_CONFIG, async (err, store) => {  
  if (err) {  
    console.error(`GetRdbStore failed, code is ${err.code},message is ${err.message}`);  
    return;  
  }  
  store.beginTransaction();  
  const valueBucket: ValuesBucket = {  
    key1: value1,  
    key2: value2,  
    key3: value3,  
    key4: value4,  
  };  
  await store.insert("test", valueBucket);  
  store.commit();  
})  
    
```    
  
    
### commit    
提交已执行的SQL语句。  
 **调用形式：**     
- commit(): void  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import { ValuesBucket } from '@ohos.data.ValuesBucket';  
  
let context = getContext(this);  
  
let key1 = "name";  
let key2 = "age";  
let key3 = "SALARY";  
let key4 = "blobType";  
let value1 = "Lisi";  
let value2 = 18;  
let value3 = 100.5;  
let value4 = new Uint8Array([1, 2, 3]);  
const STORE_CONFIG: relationalStore.StoreConfig = {  
  name: "RdbTest.db",  
  securityLevel: relationalStore.SecurityLevel.S1  
};  
relationalStore.getRdbStore(context, STORE_CONFIG, async (err, store) => {  
  if (err) {  
    console.error(`GetRdbStore failed, code is ${err.code},message is ${err.message}`);  
    return;  
  }  
  store.beginTransaction();  
  const valueBucket: ValuesBucket = {  
    key1: value1,  
    key2: value2,  
    key3: value3,  
    key4: value4,  
  };  
  await store.insert("test", valueBucket);  
  store.commit();  
})  
    
```    
  
    
### rollBack    
回滚已经执行的SQL语句。  
 **调用形式：**     
- rollBack(): void  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import { ValuesBucket } from '@ohos.data.ValuesBucket';  
  
let context = getContext(this);  
  
let key1 = "name";  
let key2 = "age";  
let key3 = "SALARY";  
let key4 = "blobType";  
let value1 = "Lisi";  
let value2 = 18;  
let value3 = 100.5;  
let value4 = new Uint8Array([1, 2, 3]);  
const STORE_CONFIG: relationalStore.StoreConfig = {  
  name: "RdbTest.db",  
  securityLevel: relationalStore.SecurityLevel.S1  
};  
relationalStore.getRdbStore(context, STORE_CONFIG, async (err, store) => {  
  if (err) {  
    console.error(`GetRdbStore failed, code is ${err.code},message is ${err.message}`);  
    return;  
  }  
  try {  
    store.beginTransaction()  
    const valueBucket: ValuesBucket = {  
      key1: value1,  
      key2: value2,  
      key3: value3,  
      key4: value4,  
    };  
    await store.insert("test", valueBucket);  
    store.commit();  
  } catch (err) {  
    let code = (err as BusinessError).code;  
    let message = (err as BusinessError).message  
    console.error(`Transaction failed, code is ${code},message is ${message}`);  
    store.rollBack();  
  }  
})  
    
```    
  
    
### backup    
以指定名称备份数据库，使用callback异步回调。  
 **调用形式：**     
    
- backup(destName: string, callback: AsyncCallback\<void>): void    
起始版本： 9    
- backup(destName: string): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| destName | string | true | 指定数据库的备份文件名。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 指定callback回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 14800000 | Inner error. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
if(store != undefined) {  
  (store as relationalStore.RdbStore).backup("dbBackup.db", (err) => {  
    if (err) {  
      console.error(`Backup failed, code is ${err.code},message is ${err.message}`);  
      return;  
    }  
    console.info(`Backup success.`);  
  })  
}    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from "@ohos.base";  
  
if(store != undefined) {  
  let promiseBackup = (store as relationalStore.RdbStore).backup("dbBackup.db");  
  promiseBackup.then(() => {  
    console.info(`Backup success.`);  
  }).catch((err: BusinessError) => {  
    console.error(`Backup failed, code is ${err.code},message is ${err.message}`);  
  })  
}  
    
```    
  
    
### restore    
从指定的数据库备份文件恢复数据库，使用callback异步回调。  
 **调用形式：**     
    
- restore(srcName: string, callback: AsyncCallback\<void>): void    
起始版本： 9    
- restore(srcName: string): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| srcName | string | true | 指定数据库的备份文件名。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 指定callback回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 14800000 | Inner error. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
if(store != undefined) {  
  (store as relationalStore.RdbStore).restore("dbBackup.db", (err) => {  
    if (err) {  
      console.error(`Restore failed, code is ${err.code},message is ${err.message}`);  
      return;  
    }  
    console.info(`Restore success.`);  
  })  
}    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from "@ohos.base";  
  
if(store != undefined) {  
  let promiseRestore = (store as relationalStore.RdbStore).restore("dbBackup.db");  
  promiseRestore.then(() => {  
    console.info(`Restore success.`);  
  }).catch((err: BusinessError) => {  
    console.error(`Restore failed, code is ${err.code},message is ${err.message}`);  
  })  
}  
    
```    
  
    
### setDistributedTables    
设置分布式数据库表，使用callback异步回调。  
 **调用形式：**     
    
- setDistributedTables(tables: Array\<string>, callback: AsyncCallback\<void>): void    
起始版本： 9    
- setDistributedTables(tables: Array\<string>): Promise\<void>    
起始版本： 9    
- setDistributedTables(tables: Array\<string>, type: DistributedType, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setDistributedTables(       tables: Array\<string>,       type: DistributedType,       config: DistributedConfig,       callback: AsyncCallback\<void>     ): void    
起始版本： 10    
- setDistributedTables(tables: Array\<string>, type?: DistributedType, config?: DistributedConfig): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core  
 **需要权限：** ohos.permission.DISTRIBUTED_DATASYNC    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| tables | Array<string> | true | 要设置的分布式数据库表表名。 |  
| type<sup>(10+)</sup> | DistributedType | true | 表的分布式类型。 |  
| config<sup>(10+)</sup> | DistributedConfig | true | 表的分布式配置信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 指定callback回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 14800000 | Inner error. |  
| 801 |  |  
| 14800051 | The type of the distributed table does not match. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
if(store != undefined) {  
  (store as relationalStore.RdbStore).setDistributedTables(["EMPLOYEE"], relationalStore.DistributedType.DISTRIBUTED_CLOUD, {  
    autoSync: true  
  }, (err) => {  
    if (err) {  
      console.error(`SetDistributedTables failed, code is ${err.code},message is ${err.message}`);  
      return;  
    }  
    console.info(`SetDistributedTables successfully.`);  
  })  
}    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from "@ohos.base";  
  
if(store != undefined) {  
  (store as relationalStore.RdbStore).setDistributedTables(["EMPLOYEE"], relationalStore.DistributedType.DISTRIBUTED_CLOUD, {  
    autoSync: true  
  }).then(() => {  
    console.info(`SetDistributedTables successfully.`);  
  }).catch((err: BusinessError) => {  
    console.error(`SetDistributedTables failed, code is ${err.code},message is ${err.message}`);  
  })  
}  
    
```    
  
    
### obtainDistributedTableName    
根据远程设备的本地表名获取指定远程设备的分布式表名。在查询远程设备数据库时，需要使用分布式表名, 使用callback异步回调。  
 **调用形式：**     
    
- obtainDistributedTableName(device: string, table: string, callback: AsyncCallback\<string>): void    
起始版本： 9    
- obtainDistributedTableName(device: string, table: string): Promise\<string>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core  
 **需要权限：** ohos.permission.DISTRIBUTED_DATASYNC    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| device | string | true | 远程设备ID。 |  
| table | string | true | 远程设备的本地表名。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 指定的callback回调函数。如果操作成功，返回远程设备的分布式表名。 |  
| Promise<string> | Promise对象。如果操作成功，返回远程设备的分布式表名。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 14800000 | Inner error. |  
| 801 |  |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import deviceManager from '@ohos.distributedDeviceManager';  
  
let dmInstance: deviceManager.DeviceManager;  
let deviceId: string | undefined = undefined;  
  
try {  
  dmInstance = deviceManager.createDeviceManager("com.example.appdatamgrverify");  
  let devices = dmInstance.getAvailableDeviceListSync();  
  deviceId = devices[0].networkId;  
} catch (err) {  
  let code = (err as BusinessError).code;  
  let message = (err as BusinessError).message  
  console.error("createDeviceManager errCode:" + code + ",errMessage:" + message);  
}  
  
if(store != undefined  deviceId != undefined) {  
  (store as relationalStore.RdbStore).obtainDistributedTableName(deviceId, "EMPLOYEE", (err, tableName) => {  
    if (err) {  
      console.error(`ObtainDistributedTableName failed, code is ${err.code},message is ${err.message}`);  
      return;  
    }  
    console.info(`ObtainDistributedTableName successfully, tableName= ${tableName}`);  
  })  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import deviceManager from '@ohos.distributedDeviceManager';  
import { BusinessError } from "@ohos.base";  
  
let dmInstance: deviceManager.DeviceManager;  
let deviceId: string | undefined = undefined;  
  
try {  
  dmInstance = deviceManager.createDeviceManager("com.example.appdatamgrverify");  
  let devices = dmInstance.getAvailableDeviceListSync();  
  deviceId = devices[0].networkId;  
} catch (err) {  
  let code = (err as BusinessError).code;  
  let message = (err as BusinessError).message  
  console.error("createDeviceManager errCode:" + code + ",errMessage:" + message);  
}  
  
if(store != undefined  deviceId != undefined) {  
  (store as relationalStore.RdbStore).obtainDistributedTableName(deviceId, "EMPLOYEE").then((tableName: string) => {  
    console.info(`ObtainDistributedTableName successfully, tableName= ${tableName}`);  
  }).catch((err: BusinessError) => {  
    console.error(`ObtainDistributedTableName failed, code is ${err.code},message is ${err.message}`);  
  })  
}  
    
```    
  
    
### sync    
在设备之间同步数据,使用callback异步回调。  
 **调用形式：**     
    
- sync(mode: SyncMode, predicates: RdbPredicates, callback: AsyncCallback\<Array\<[string, number]>>): void    
起始版本： 9    
- sync(mode: SyncMode, predicates: RdbPredicates): Promise\<Array\<[string, number]>>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core  
 **需要权限：** ohos.permission.DISTRIBUTED_DATASYNC    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| mode | SyncMode | true | 指同步模式。该值可以是relationalStore.SyncMode.SYNC_MODE_PUSH、relationalStore.SyncMode.SYNC_MODE_PULL。 |  
| predicates | RdbPredicates | true | 约束同步数据和设备。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 指定的callback回调函数，用于向调用者发送同步结果。string：设备ID；number：每个设备同步状态，0表示成功，其他值表示失败。 |  
| Promise<Array<[string, number]>> | Promise对象，用于向调用者发送同步结果。string：设备ID；number：每个设备同步状态，0表示成功，其他值表示失败。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 14800000 | Inner error. |  
| 801 |  |  
    
 **示例代码1：**   
  
示例（callback）：  
```ts    
import deviceManager from '@ohos.distributedDeviceManager';  
  
let dmInstance: deviceManager.DeviceManager;  
let deviceIds: Array<string> = [];  
  
try {  
  dmInstance = deviceManager.createDeviceManager("com.example.appdatamgrverify");  
  let devices: Array<deviceManager.DeviceBasicInfo> = dmInstance.getAvailableDeviceListSync();  
  for (let i = 0; i < devices.length; i++) {  
    deviceIds[i] = devices[i].networkId!;  
  }  
} catch (err) {  
  let code = (err as BusinessError).code;  
  let message = (err as BusinessError).message  
  console.error("createDeviceManager errCode:" + code + ",errMessage:" + message);  
}  
  
let predicates = new relationalStore.RdbPredicates('EMPLOYEE');  
predicates.inDevices(deviceIds);  
if(store != undefined) {  
  (store as relationalStore.RdbStore).sync(relationalStore.SyncMode.SYNC_MODE_PUSH, predicates, (err, result) => {  
    if (err) {  
      console.error(`Sync failed, code is ${err.code},message is ${err.message}`);  
      return;  
    }  
    console.info(`Sync done.`);  
    for (let i = 0; i < result.length; i++) {  
      console.info(`device= ${result[i][0]}, status= ${result[i][1]}`);  
    }  
  })  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import deviceManager from '@ohos.distributedDeviceManager';  
import { BusinessError } from "@ohos.base";  
  
let dmInstance: deviceManager.DeviceManager;  
let deviceIds: Array<string> = [];  
  
try {  
  dmInstance = deviceManager.createDeviceManager("com.example.appdatamgrverify");  
  let devices: Array<deviceManager.DeviceBasicInfo> = dmInstance.getAvailableDeviceListSync();  
  for (let i = 0; i < devices.length; i++) {  
    deviceIds[i] = devices[i].networkId!;  
  }  
} catch (err) {  
  let code = (err as BusinessError).code;  
  let message = (err as BusinessError).message  
  console.error("createDeviceManager errCode:" + code + ",errMessage:" + message);  
}  
  
let predicates = new relationalStore.RdbPredicates('EMPLOYEE');  
predicates.inDevices(deviceIds);  
if(store != undefined) {  
  (store as relationalStore.RdbStore).sync(relationalStore.SyncMode.SYNC_MODE_PUSH, predicates).then((result: Object[][]) => {  
    console.info(`Sync done.`);  
    for (let i = 0; i < result.length; i++) {  
      console.info(`device= ${result[i][0]}, status= ${result[i][1]}`);  
    }  
  }).catch((err: BusinessError) => {  
    console.error(`Sync failed, code is ${err.code},message is ${err.message}`);  
  })  
}  
    
```    
  
    
### cloudSync<sup>(10+)</sup>    
手动执行对指定表的端云同步，使用callback异步回调。使用该接口需要实现云服务功能。  
 **调用形式：**     
    
- cloudSync(mode: SyncMode, progress: Callback\<ProgressDetails>, callback: AsyncCallback\<void>): void    
起始版本： 10    
- cloudSync(mode: SyncMode, progress: Callback\<ProgressDetails>): Promise\<void>    
起始版本： 10    
- cloudSync(       mode: SyncMode,       tables: string[],       progress: Callback\<ProgressDetails>,       callback: AsyncCallback\<void>     ): void    
起始版本： 10    
- cloudSync(mode: SyncMode, tables: string[], progress: Callback\<ProgressDetails>): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.DistributedDataManager.CloudSync.Client  
 **需要权限：** ohos.permission.DISTRIBUTED_DATASYNC    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| mode | SyncMode | true | 表示数据库的同步模式。 |  
| progress | Callback<ProgressDetails> | true | 用来处理数据库同步详细信息的回调函数。 |  
| tables | string[] | true | 指定同步的表名。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 指定的callback回调函数，用于向调用者发送同步结果。 |  
| Promise<void> | Promise对象，用于向调用者发送同步结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 202 |  |  
| 801 |  |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
if(store != undefined) {  
  (store as relationalStore.RdbStore).cloudSync(relationalStore.SyncMode.SYNC_MODE_CLOUD_FIRST, (progressDetails) => {  
    console.info(`Progess: ${progressDetails}`);  
  }, (err) => {  
    if (err) {  
      console.error(`Cloud sync failed, code is ${err.code},message is ${err.message}`);  
      return;  
    }  
    console.info('Cloud sync succeeded');  
  });  
}    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
const tables = ["table1", "table2"];  
  
if(store != undefined) {  
  (store as relationalStore.RdbStore).cloudSync(relationalStore.SyncMode.SYNC_MODE_CLOUD_FIRST, tables, (progressDetail: relationalStore.ProgressDetails) => {  
    console.info(`Progess: ${progressDetail}`);  
  }, (err) => {  
    if (err) {  
      console.error(`Cloud sync failed, code is ${err.code},message is ${err.message}`);  
      return;  
    }  
    console.info('Cloud sync succeeded');  
  });  
};    
```    
  
    
### remoteQuery    
根据指定条件查询远程设备数据库中的数据。使用callback异步回调。  
 **调用形式：**     
    
- remoteQuery(       device: string,       table: string,       predicates: RdbPredicates,       columns: Array\<string>,       callback: AsyncCallback\<ResultSet>     ): void    
起始版本： 9    
- remoteQuery(device: string, table: string, predicates: RdbPredicates, columns: Array\<string>): Promise\<ResultSet>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| device | string | true | 指定的远程设备ID。 |  
| table | string | true | 指定的目标表名。 |  
| predicates | RdbPredicates | true | RdbPredicates的实例对象，指定查询的条件。 |  
| columns | Array<string> | true | 表示要查询的列。如果值为空，则查询应用于所有列。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 指定callback回调函数。如果操作成功，则返回ResultSet对象。 |  
| Promise<ResultSet> | Promise对象。如果操作成功，则返回ResultSet对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 14800000 | Inner error. |  
| 801 |  |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import deviceManager from '@ohos.distributedDeviceManager';  
import { BusinessError } from "@ohos.base";  
  
let dmInstance: deviceManager.DeviceManager;  
let deviceId: string | undefined = undefined;  
  
try {  
  dmInstance = deviceManager.createDeviceManager("com.example.appdatamgrverify");  
  let devices = dmInstance.getAvailableDeviceListSync();  
  if(deviceId != undefined) {  
    deviceId = devices[0].networkId;  
  }  
} catch (err) {  
  let code = (err as BusinessError).code;  
  let message = (err as BusinessError).message;  
  console.error("createDeviceManager errCode:" + code + ",errMessage:" + message);  
}  
  
let predicates = new relationalStore.RdbPredicates('EMPLOYEE');  
predicates.greaterThan("id", 0);  
if(store != undefined  deviceId != undefined) {  
  (store as relationalStore.RdbStore).remoteQuery(deviceId, "EMPLOYEE", predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"]).then((resultSet: relationalStore.ResultSet) => {  
    console.info(`ResultSet column names: ${resultSet.columnNames}, column count: ${resultSet.columnCount}`);  
    // resultSet是一个数据集合的游标，默认指向第-1个记录，有效的数据从0开始。  
    while (resultSet.goToNextRow()) {  
      const id = resultSet.getLong(resultSet.getColumnIndex("ID"));  
      const name = resultSet.getString(resultSet.getColumnIndex("NAME"));  
      const age = resultSet.getLong(resultSet.getColumnIndex("AGE"));  
      const salary = resultSet.getDouble(resultSet.getColumnIndex("SALARY"));  
      console.info(`id=${id}, name=${name}, age=${age}, salary=${salary}`);  
    }  
    // 释放数据集的内存  
    resultSet.close();  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to remoteQuery, code is ${err.code},message is ${err.message}`);  
  })  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import deviceManager from '@ohos.distributedDeviceManager';  
import { BusinessError } from "@ohos.base";  
  
let dmInstance: deviceManager.DeviceManager;  
let deviceId: string | undefined = undefined;  
  
try {  
  dmInstance = deviceManager.createDeviceManager("com.example.appdatamgrverify");  
  let devices: Array<deviceManager.DeviceBasicInfo> = dmInstance.getAvailableDeviceListSync();  
  if(devices != undefined) {  
    deviceId = devices[0].networkId;  
  }  
} catch (err) {  
  let code = (err as BusinessError).code;  
  let message = (err as BusinessError).message;  
  console.error("createDeviceManager errCode:" + code + ",errMessage:" + message);  
}  
  
let predicates = new relationalStore.RdbPredicates('EMPLOYEE');  
predicates.greaterThan("id", 0);  
if(store != undefined  deviceId != undefined) {  
  (store as relationalStore.RdbStore).remoteQuery(deviceId, "EMPLOYEE", predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"]).then((resultSet: relationalStore.ResultSet) => {  
    console.info(`ResultSet column names: ${resultSet.columnNames}, column count: ${resultSet.columnCount}`);  
    // resultSet是一个数据集合的游标，默认指向第-1个记录，有效的数据从0开始。  
    while (resultSet.goToNextRow()) {  
      const id = resultSet.getLong(resultSet.getColumnIndex("ID"));  
      const name = resultSet.getString(resultSet.getColumnIndex("NAME"));  
      const age = resultSet.getLong(resultSet.getColumnIndex("AGE"));  
      const salary = resultSet.getDouble(resultSet.getColumnIndex("SALARY"));  
      console.info(`id=${id}, name=${name}, age=${age}, salary=${salary}`);  
    }  
    // 释放数据集的内存  
    resultSet.close();  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to remoteQuery, code is ${err.code},message is ${err.message}`);  
  })  
}  
    
```    
  
    
### on('dataChange')    
注册数据库的数据变更的事件监听。当分布式数据库中的数据发生更改时，将调用回调。  
 **调用形式：**     
- on(event: 'dataChange', type: SubscribeType, observer: Callback\<Array\<string>>): void  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event | string | true | 取值为'dataChange'，表示数据更改。 |  
| type | SubscribeType | true | 订阅类型。 |  
| observer | Callback<Array<string>> | true | 指分布式数据库中数据更改事件的观察者。Arraylt;stringgt;为数据库中的数据发生改变的对端设备ID。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
    
 **示例代码：**   
```ts    
import deviceManager from '@ohos.distributedHardware.deviceManager';  
  
let devices: string | undefined = undefined;  
  
try {  
  if (store != undefined) {  
    (store as relationalStore.RdbStore).on('dataChange', relationalStore.SubscribeType.SUBSCRIBE_TYPE_REMOTE, (storeObserver) => {  
      if (devices != undefined) {  
        for (let i = 0; i < devices.length; i++) {  
          console.info(`device= ${devices[i]} data changed`);  
        }  
      }  
    })  
  }  
} catch (err) {  
    let code = (err as BusinessError).code;  
    let message = (err as BusinessError).message  
    console.error(`Register observer failed, code is ${code},message is ${message}`);  
}  
    
```    
  
    
### on('dataChange')<sup>(10+)</sup>  
 **调用形式：**     
- on(event: 'dataChange', type: SubscribeType, observer: Callback\<Array\<string>> | Callback\<Array\<ChangeInfo>>): void  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event | string | true |  |  
| type | SubscribeType | true |  |  
| observer | string | true |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 202 |  |  
| 801 |  |  
    
 **示例代码：**   
```ts    
import deviceManager from '@ohos.distributedHardware.deviceManager';  
  
let devices: string | undefined = undefined;  
  
try {  
  if(store != undefined) {  
    (store as relationalStore.RdbStore).on('dataChange', relationalStore.SubscribeType.SUBSCRIBE_TYPE_REMOTE, storeObserver => {  
      if (devices != undefined) {  
        for (let i = 0; i < devices.length; i++) {  
          console.info(`device= ${devices[i]} data changed`);  
        }  
      }  
    });  
  }  
} catch (err) {  
  let code = (err as BusinessError).code;  
  let message = (err as BusinessError).message  
  console.error(`Register observer failed, code is ${code},message is ${message}`);  
}  
    
```    
  
    
### on<sup>(10+)</sup>    
注册数据库的进程内或者进程间事件监听。当调用[emit](#emit10)接口时，将调用回调。  
 **调用形式：**     
- on(event: string, interProcess: boolean, observer: Callback\<void>): void  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event | string | true | 订阅事件名称。 |  
| interProcess | boolean | true | 指定是进程间还是本进程订阅。<br/> true：进程间。<br/> false：本进程。 |  
| observer | Callback<void> | true | 回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
| 14800050 | Failed to obtain subscription service. |  
| 14800000 | Inner error. |  
    
 **示例代码：**   
```ts    
try {  
  if(store != undefined) {  
    (store as relationalStore.RdbStore).on('storeObserver', false, (storeObserver) => {  
      console.info(`storeObserver`);  
    });  
  }  
} catch (err) {  
  let code = (err as BusinessError).code;  
  let message = (err as BusinessError).message  
  console.error(`Register observer failed, code is ${code},message is ${message}`);  
}  
    
```    
  
    
### off('dataChange')    
取消数据变更的事件监听。  
 **调用形式：**     
- off(event: 'dataChange', type: SubscribeType, observer: Callback\<Array\<string>>): void  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event | string | true | 取值为'dataChange'，表示数据更改。 |  
| type | SubscribeType | true | 订阅类型。 |  
| observer | Callback<Array<string>> | true | 指已注册的数据更改观察者。Arraylt;stringgt;为数据库中的数据发生改变的对端设备ID。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
    
 **示例代码：**   
```ts    
let devices: string | undefined = undefined;  
  
try {  
  if(store != undefined) {  
    (store as relationalStore.RdbStore).off('dataChange', relationalStore.SubscribeType.SUBSCRIBE_TYPE_REMOTE, (storeObserver) => {  
      if (devices != undefined){  
        for (let i = 0; i < devices.length; i++) {  
          console.info(`device= ${devices[i]} data changed`);  
        }  
      }  
    });  
  }  
} catch (err) {  
  let code = (err as BusinessError).code;  
  let message = (err as BusinessError).message  
  console.error(`Unregister observer failed, code is ${code},message is ${message}`);  
}  
    
```    
  
    
### off('dataChange')<sup>(10+)</sup>  
 **调用形式：**     
- off(       event: 'dataChange',       type: SubscribeType,       observer?: Callback\<Array\<string>> | Callback\<Array\<ChangeInfo>>     ): void  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event | string | true |  |  
| type | SubscribeType | true |  |  
| observer | string | false |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 202 |  |  
| 801 |  |  
    
 **示例代码：**   
```ts    
import deviceManager from '@ohos.distributedHardware.deviceManager';  
  
let devices: string | undefined = undefined;  
  
try {  
  if(store != undefined) {  
    (store as relationalStore.RdbStore).off('dataChange', relationalStore.SubscribeType.SUBSCRIBE_TYPE_REMOTE, (storeObserver) => {  
      if (devices !=  undefined) {  
        for (let i = 0; i < devices.length; i++) {  
          console.info(`device= ${devices[i]} data changed`);  
        }  
      }  
    });  
  }  
} catch (err) {  
  let code = (err as BusinessError).code;  
  let message = (err as BusinessError).message  
  console.error(`Unregister observer failed, code is ${code},message is ${message}`);  
}  
    
```    
  
    
### off<sup>(10+)</sup>    
取消数据变更的事件监听。  
 **调用形式：**     
- off(event: string, interProcess: boolean, observer?: Callback\<void>): void  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event | string | true | 取消订阅事件名称。 |  
| interProcess | boolean | true | 指定是进程间还是本进程取消订阅。<br/> true：进程间。<br/> false：本进程。 |  
| observer | Callback<void> | false | 该参数存在，则取消指定Callback监听回调，否则取消该event事件的所有监听回调。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
| 14800050 | Failed to obtain subscription service. |  
| 14800000 | Inner error. |  
    
 **示例代码：**   
```ts    
try {  
  if(store != undefined) {  
    (store as relationalStore.RdbStore).off('storeObserver', false, (storeObserver) => {  
      console.info(`storeObserver`);  
    });  
  }  
} catch (err) {  
  let code = (err as BusinessError).code;  
  let message = (err as BusinessError).message  
  console.error(`Unregister observer failed, code is ${code},message is ${message}`);  
}  
    
```    
  
    
### emit<sup>(10+)</sup>    
通知通过[on](#on10)注册的进程间或者进程内监听事件。  
 **调用形式：**     
- emit(event: string): void  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event | string | true | 通知订阅事件的名称。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
| 14800050 | Failed to obtain subscription service. |  
| 14800000 | Inner error. |  
    
 **示例代码：**   
```ts    
if(store != undefined) {  
  (store as relationalStore.RdbStore).emit('storeObserver');  
}    
```    
  
    
 **示例代码：**   
```ts    
// 设置数据库版本  
if(store != undefined) {  
  (store as relationalStore.RdbStore).version = 3;  
  // 获取数据库版本  
  console.info(`RdbStore version is ${store.version}`);  
}    
```    
  
    
## getRdbStore    
获得一个相关的RdbStore，操作关系型数据库，用户可以根据自己的需求配置RdbStore的参数，然后通过RdbStore调用相关接口可以执行相关的数据操作，使用callback异步回调。  
 **调用形式：**     
    
- getRdbStore(context: Context, config: StoreConfig, callback: AsyncCallback\<RdbStore>): void    
起始版本： 9    
- getRdbStore(context: Context, config: StoreConfig, callback: AsyncCallback\<RdbStore>): void    
起始版本： 10    
- getRdbStore(context: Context, config: StoreConfig): Promise\<RdbStore>    
起始版本： 9    
- getRdbStore(context: Context, config: StoreConfig): Promise\<RdbStore>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| context | Context | true | 应用的上下文。 <br>FA模型的应用Context定义见[Context](js-apis-inner-app-context.md)。<br>Stage模型的应用Context定义见[Context](js-apis-inner-application-uiAbilityContext.md)。| |  
| config | StoreConfig | true | 与此RDB存储相关的数据库配置。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 指定callback回调函数，返回RdbStore对象。 |  
| Promise<RdbStore> | Promise对象。返回RdbStore对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 14800000 | Inner error. |  
| 14800010 | Failed to open or delete database by invalid database path. |  
| 14800011 | Failed to open database by database corrupted. |  
| 14801001 | Only supported in stage mode. |  
| 14801002 | The data group id is not valid. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import featureAbility from '@ohos.ability.featureAbility';  
import { BusinessError } from "@ohos.base";  
  
let store: relationalStore.RdbStore | undefined = undefined;  
let context = getContext(this);  
  
const STORE_CONFIG: relationalStore.StoreConfig = {  
  name: "RdbTest.db",  
  securityLevel: relationalStore.SecurityLevel.S1  
};  
  
relationalStore.getRdbStore(context, STORE_CONFIG, (err: BusinessError, rdbStore: relationalStore.RdbStore) => {  
  store = rdbStore;  
  if (err) {  
    console.error(`Get RdbStore failed, code is ${err.code},message is ${err.message}`);  
    return;  
  }  
  console.info(`Get RdbStore successfully.`);  
})  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import featureAbility from '@ohos.ability.featureAbility';  
import { BusinessError } from "@ohos.base";  
  
let store: relationalStore.RdbStore | undefined = undefined;  
let context = getContext(this);  
  
const STORE_CONFIG: relationalStore.StoreConfig = {  
  name: "RdbTest.db",  
  securityLevel: relationalStore.SecurityLevel.S1  
};  
  
relationalStore.getRdbStore(context, STORE_CONFIG).then(async (rdbStore: relationalStore.RdbStore) => {  
  store = rdbStore;  
  console.info(`Get RdbStore successfully.`)  
}).catch((err: BusinessError) => {  
  console.error(`Get RdbStore failed, code is ${err.code},message is ${err.message}`);  
})  
    
```    
  
    
## deleteRdbStore    
删除数据库文件，使用callback异步回调。  
 **调用形式：**     
    
- deleteRdbStore(context: Context, name: string, callback: AsyncCallback\<void>): void    
起始版本： 9    
- deleteRdbStore(context: Context, config: StoreConfig, callback: AsyncCallback\<void>): void    
起始版本： 10    
- deleteRdbStore(context: Context, name: string): Promise\<void>    
起始版本： 9    
- deleteRdbStore(context: Context, config: StoreConfig): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| context | Context | true | 应用的上下文。 <br>FA模型的应用Context定义见[Context](js-apis-inner-app-context.md)。<br>Stage模型的应用Context定义见[Context](js-apis-inner-application-uiAbilityContext.md)。| |  
| name | string | true | 数据库名称。 |  
| config<sup>(10+)</sup> | StoreConfig | true | 与此RDB存储相关的数据库配置。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 指定callback回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 14800000 | Inner error. |  
| 14800010 | Failed to open or delete database by invalid database path. |  
| 14801001 | Only supported in stage mode. |  
| 14801002 | The data group id is not valid. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
import window from '@ohos.window';  
import { BusinessError } from "@ohos.base";  
  
let store: relationalStore.RdbStore | undefined = undefined;  
  
class EntryAbility extends UIAbility {  
  onWindowStageCreate(windowStage: window.WindowStage){  
    const STORE_CONFIG: relationalStore.StoreConfig = {  
      name: "RdbTest.db",  
      securityLevel: relationalStore.SecurityLevel.S1  
    };  
    relationalStore.deleteRdbStore(this.context, STORE_CONFIG, (err: BusinessError) => {  
      if (err) {  
        console.error(`Delete RdbStore failed, code is ${err.code},message is ${err.message}`);  
        return;  
      }  
      store = undefined;  
      console.info(`Delete RdbStore successfully.`);  
    })  
  }  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
import window from '@ohos.window';  
import { BusinessError } from "@ohos.base";  
  
let store: relationalStore.RdbStore | undefined = undefined;  
  
class EntryAbility extends UIAbility {  
  onWindowStageCreate(windowStage: window.WindowStage){  
    const STORE_CONFIG: relationalStore.StoreConfig = {  
      name: "RdbTest.db",  
      securityLevel: relationalStore.SecurityLevel.S1  
    };  
    relationalStore.deleteRdbStore(this.context, STORE_CONFIG).then(()=>{  
      store = undefined;  
      console.info(`Delete RdbStore successfully.`);  
    }).catch((err: BusinessError) => {  
      console.error(`Delete RdbStore failed, code is ${err.code},message is ${err.message}`);  
    })  
  }  
}  
    
```    
  
