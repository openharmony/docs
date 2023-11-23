# @ohos.data.distributedData    
分布式数据管理为应用程序提供不同设备间数据库的分布式协同能力。通过调用分布式数据各个接口，应用程序可将数据保存到分布式数据库中，并可对分布式数据库中的数据进行增加、删除、修改、查询、同步等操作。  
  
该模块提供以下分布式数据管理相关的常用功能：  
  
- [KVManager](#kvmanager)：数据管理实例，用于获取KVStore的相关信息。  
- [KvStoreResultSet<sup>8+</sup>](#kvstoreresultset8)：提供获取KVStore数据库结果集的相关方法，包括查询和移动数据读取位置等。  
- [Query<sup>8+</sup>](#query8)：使用谓词表示数据库查询，提供创建Query实例、查询数据库中的数据和添加谓词的方法。  
- [KVStore](#kvstore)：KVStore数据库实例，提供增加数据、删除数据和订阅数据变更、订阅数据同步完成的方法。  
- [SingleKVStore](#singlekvstore)：单版本分布式数据库，继承自[KVStore](#kvstore)，不对数据所属设备进行区分，提供查询数据和同步数据的方法。  
- [DeviceKVStore<sup>8+</sup>](#devicekvstore8)：设备协同数据库，继承自[KVStore](#kvstore)，以设备维度对数据进行区分，提供查询数据和同步数据的方法。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import distributedData from '@ohos.data.distributedData'    
```  
    
## KVManagerConfig<sup>(deprecated)</sup>    
提供KVManager实例的配置信息，包括调用方的Bundle名称和用户信息。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.KVManagerConfig替代。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
### 属性    
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| userInfo<sup>(deprecated)</sup> | UserInfo | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>调用方的用户信息。  |  
| bundleName<sup>(deprecated)</sup> | string | false | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.KVManagerConfig#bundleName替代。<br>调用方的Bundle名称。  |  
    
## UserInfo<sup>(deprecated)</sup>    
用户信息。    
从API version 7 开始支持，从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
### 属性    
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| userId<sup>(deprecated)</sup> | string | false | false | 从API version 7 开始支持，从API version 9 开始废弃。<br>指示要设置的用户ID，默认为'0'。  |  
| userType<sup>(deprecated)</sup> | UserType | false | false | 从API version 7 开始支持，从API version 9 开始废弃。<br>指示要设置的用户类型，默认为0。  |  
    
## UserType<sup>(deprecated)</sup>    
用户类型枚举。    
从API version 7 开始支持，从API version 9 开始废弃。    
    
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| SAME_USER_ID<sup>(deprecated)</sup> | 0 | 从API version 7 开始支持，从API version 9 开始废弃。<br>使用同一帐户登录不同设备的用户。  |  
    
 **常量：**     
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
| 名称 | 类型 | 值 | 说明 |  
| --------| --------| --------| --------|  
| MAX_KEY_LENGTH<sup>(deprecated)</sup> | number | 1024 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.Constants#MAX_KEY_LENGTH替代。<br>数据库中Key允许的最大长度，单位字节。   |  
| MAX_VALUE_LENGTH<sup>(deprecated)</sup> | number | 4194303 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.Constants#MAX_VALUE_LENGTH替代。<br>数据库中Value允许的最大长度，单位字节。   |  
| MAX_KEY_LENGTH_DEVICE<sup>(deprecated)</sup> | number | 896 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.Constants#MAX_KEY_LENGTH_DEVICEs替代。<br>最大设备密钥长度，单位字节。  |  
| MAX_STORE_ID_LENGTH<sup>(deprecated)</sup> | number | 128 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.Constants#MAX_STORE_ID_LENGTH替代。<br>数据库标识符允许的最大长度，单位字节。   |  
| MAX_QUERY_LENGTH<sup>(deprecated)</sup> | number | 512000 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.Constants#MAX_QUERY_LENGTH替代。<br>最大查询长度，单位字节。  |  
| MAX_BATCH_SIZE<sup>(deprecated)</sup> | number | 128 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.Constants#MAX_BATCH_SIZE替代。<br>最大批处理操作数量。  |  
    
## ValueType<sup>(deprecated)</sup>    
数据类型枚举。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.ValueType替代。    
    
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| STRING<sup>(deprecated)</sup> | 0 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.ValueType#STRING替代。<br>表示值类型为字符串。   |  
| INTEGER<sup>(deprecated)</sup> | 1 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.ValueType#INTEGER替代。<br>表示值类型为整数。   |  
| FLOAT<sup>(deprecated)</sup> | 2 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.ValueType#FLOAT替代。<br>表示值类型为浮点数。   |  
| BYTE_ARRAY<sup>(deprecated)</sup> | 3 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.ValueType#BYTE_ARRAY替代。<br>表示值类型为字节数组。   |  
| BOOLEAN<sup>(deprecated)</sup> | 4 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.ValueType#BOOLEAN替代。<br>表示值类型为布尔值。   |  
| DOUBLE<sup>(deprecated)</sup> | 5 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.ValueType#DOUBLE替代。<br>表示值类型为双浮点数。   |  
    
## Value<sup>(deprecated)</sup>    
存储在数据库中的值对象。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.Value替代。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
### 属性    
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | number | false | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.Value#type替代。<br>值类型。    |  
| value<sup>(deprecated)</sup> | Uint8Array \| string \| number \| boolean | false | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.Value#value替代。<br>值。    |  
    
## Entry<sup>(deprecated)</sup>    
存储在数据库中的键值对。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.Entry替代。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
### 属性    
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| key<sup>(deprecated)</sup> | string | false | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.Entry#key替代。<br>键值。    |  
| value<sup>(deprecated)</sup> | Value | false | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.Entry#value替代。<br>值对象。    |  
    
## ChangeNotification<sup>(deprecated)</sup>    
数据变更时通知的对象，包括数据插入的数据、更新的数据、删除的数据和设备ID。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.ChangeNotification替代。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
### 属性    
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| insertEntries<sup>(deprecated)</sup> | Entry[] | false | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.ChangeNotification#insertEntries替代。<br>数据添加记录。    |  
| updateEntries<sup>(deprecated)</sup> | Entry[] | false | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.ChangeNotification#updateEntries替代。<br>数据更新记录。    |  
| deleteEntries<sup>(deprecated)</sup> | Entry[] | false | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.ChangeNotification#deleteEntries替代。<br>数据删除记录。    |  
| deviceId<sup>(deprecated)</sup> | string | false | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.ChangeNotification#deviceId替代。<br>设备ID，此处为设备UUID。   |  
    
## SyncMode<sup>(deprecated)</sup>    
同步模式枚举。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.SyncMode替代。    
    
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| PULL_ONLY<sup>(deprecated)</sup> | 0 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.SyncMode#PULL_ONLY替代。<br>表示只能从远端拉取数据到本端。 。 |  
| PUSH_ONLY<sup>(deprecated)</sup> | 1 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.SyncMode#PUSH_ONLY替代。<br>表示只能从本端推送数据到远端。 |  
| PUSH_PULL<sup>(deprecated)</sup> | 2 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.SyncMode#PUSH_PULL替代。<br>表示从本端推送数据到远端，然后从远端拉取数据到本端。  |  
    
## SubscribeType<sup>(deprecated)</sup>    
订阅类型枚举。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.SubscribeType替代。    
    
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| SUBSCRIBE_TYPE_LOCAL<sup>(deprecated)</sup> | 0 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.SubscribeType#SUBSCRIBE_TYPE_LOCAL替代。<br>表示订阅本地数据变更。   |  
| SUBSCRIBE_TYPE_REMOTE<sup>(deprecated)</sup> | 1 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.SubscribeType#SUBSCRIBE_TYPE_REMOTE替代。<br>表示订阅远端数据变更。  |  
| SUBSCRIBE_TYPE_ALL<sup>(deprecated)</sup> | 2 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.SubscribeType#SUBSCRIBE_TYPE_ALL替代。<br>表示订阅远端和本地数据变更。   |  
    
## KVStoreType<sup>(deprecated)</sup>    
KVStore数据库类型枚举。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.KVStoreType替代。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| DEVICE_COLLABORATION<sup>(deprecated)</sup> | 0 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.KVStoreType#DEVICE_COLLABORATION替代。系统能力：SystemCapability.DistributedDataManager.KVStore.DistributedKVStore<br>表示多设备协同数据库。<br> **数据库特点：** 数据以设备的维度管理，不存在冲突；支持按照设备的维度查询数据。<br>**系统能力：** SystemCapability.DistributedDataManager.KVStore.DistributedKVStore    |  
| SINGLE_VERSION<sup>(deprecated)</sup> | 1 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.KVStoreType#SINGLE_VERSION替代。系统能力：SystemCapability.DistributedDataManager.KVStore.Core<br>表示单版本数据库。<br> **数据库特点：** 数据不分设备，设备之间修改相同的key会覆盖。 <br>**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core  |  
| MULTI_VERSION<sup>(deprecated)</sup> | 2 | 从API version 7 开始支持，从API version 9 开始废弃。系统能力：SystemCapability.DistributedDataManager.KVStore.DistributedKVStore<br>表示多版本数据库。当前暂不支持使用此接口。 <br>**系统能力：** SystemCapability.DistributedDataManager.KVStore.DistributedKVStore  |  
    
## SecurityLevel<sup>(deprecated)</sup>    
数据库的安全级别枚举。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.SecurityLevel替代。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| NO_LEVEL<sup>(deprecated)</sup> | 0 | 从API version 7 开始支持，从API version 9 开始废弃。系统能力：SystemCapability.DistributedDataManager.KVStore.DistributedKVStore<br>表示数据库不设置安全级别(已废弃)。<br>**系统能力：** SystemCapability.DistributedDataManager.KVStore.DistributedKVStore    |  
| S0<sup>(deprecated)</sup> | 1 | 从API version 7 开始支持，从API version 9 开始废弃。系统能力：SystemCapability.DistributedDataManager.KVStore.Core<br>表示数据库的安全级别为公共级别(已废弃)。<br>**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core     |  
| S1<sup>(deprecated)</sup> | 2 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.SecurityLevel#S1替代。系统能力：SystemCapability.DistributedDataManager.KVStore.Core<br>表示数据库的安全级别为低级别，当数据泄露时会产生较低影响。例如，包含壁纸等系统数据的数据库。<br>**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core     |  
| S2<sup>(deprecated)</sup> | 3 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.SecurityLevel#S2替代。系统能力：SystemCapability.DistributedDataManager.KVStore.Core<br>表示数据库的安全级别为中级别，当数据泄露时会产生较大影响。例如，包含录音、视频等用户生成数据或通话记录等信息的数据库。<br>**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core     |  
| S3<sup>(deprecated)</sup> | 5 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.SecurityLevel#S3替代。系统能力：SystemCapability.DistributedDataManager.KVStore.Core<br>表示数据库的安全级别为高级别，当数据泄露时会产生重大影响。例如，包含用户运动、健康、位置等信息的数据库。<br>**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core     |  
| S4<sup>(deprecated)</sup> | 6 | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.SecurityLevel#S4替代。系统能力：SystemCapability.DistributedDataManager.KVStore.Core<br>表示数据库的安全级别为关键级别，当数据泄露时会产生严重影响。例如，包含认证凭据、财务数据等信息的数据库。<br>**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core     |  
    
## Options<sup>(deprecated)</sup>    
用于提供创建数据库的配置信息。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.Options替代。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
### 属性    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| createIfMissing<sup>(deprecated)</sup> | boolean | false | false | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.Options#createIfMissing替代。系统能力：SystemCapability.DistributedDataManager.KVStore.Core<br>当数据库文件不存在时是否创建数据库，默认为true，即创建。 <br>**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core     |  
| encrypt<sup>(deprecated)</sup> | boolean | false | false | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.Options#encrypt替代。系统能力：SystemCapability.DistributedDataManager.KVStore.Core<br>设置数据库文件是否加密，默认为false, 即不加密。<br>**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core      |  
| backup<sup>(deprecated)</sup> | boolean | false | false | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.Options#backup替代。系统能力：SystemCapability.DistributedDataManager.KVStore.Core<br>设置数据库文件是否备份，默认为true，即备份。 <br>**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core     |  
| autoSync<sup>(deprecated)</sup> | boolean | false | false | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.Options#autoSync替代。需要权限：ohos.permission.DISTRIBUTED_DATASYNC系统能力：SystemCapability.DistributedDataManager.KVStore.Core<br>设置数据库文件是否自动同步。默认为false，即手动同步。<br>**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core<br>**需要权限**： ohos.permission.DISTRIBUTED_DATASYNC      |  
| kvStoreType<sup>(deprecated)</sup> | KVStoreType | false | false | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.Options#kvStoreType替代。系统能力：SystemCapability.DistributedDataManager.KVStore.Core<br>设置要创建的数据库类型，默认为DEVICE_COLLABORATION，即多设备协同数据库。<br>**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core  |  
| securityLevel<sup>(deprecated)</sup> | SecurityLevel | false | false | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.Options#securityLevel替代。系统能力：SystemCapability.DistributedDataManager.KVStore.Core<br>设置数据库安全级别(S1-S4)。<br>**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core   |  
| schema<sup>(deprecated)</sup> | Schema | false | false | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.Options#schema替代。系统能力：SystemCapability.DistributedDataManager.KVStore.DistributedKVStore<br>设置定义存储在数据库中的值，默认为undefined, 即不使用schema。<br>**系统能力：** SystemCapability.DistributedDataManager.KVStore.DistributedKVStore  |  
    
## Schema<sup>(deprecated)</sup>    
表示数据库模式，可以在创建或打开数据库时创建Schema对象并将它们放入[Options](#options)中。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.Schema替代。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.DistributedKVStore    
### 属性    
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.DistributedKVStore    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| root<sup>(deprecated)</sup> | FieldNode | false | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.Schema#root替代。<br>表示json根对象。  |  
| indexes<sup>(deprecated)</sup> | Array<string> | false | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.Schema#indexes替代。<br>表示json类型的字符串数组。  |  
| mode<sup>(deprecated)</sup> | number | false | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.Schema#mode替代。<br>表示Schema的模式。   |  
| skip<sup>(deprecated)</sup> | number | false | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.Schema#skip替代。<br>Schema的跳跃大小。   |  
    
## FieldNode<sup>(deprecated)</sup>    
表示 Schema 实例的节点，提供定义存储在数据库中的值的方法。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.FieldNode替代。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.DistributedKVStore    
### 属性    
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.DistributedKVStore    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| default<sup>(deprecated)</sup> | string | false | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.FieldNode#default替代。<br>表示Fieldnode的默认值。  |  
| nullable<sup>(deprecated)</sup> | boolean | false | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.FieldNode#nullable替代。<br>表示数据库字段是否可以为空。    |  
| type<sup>(deprecated)</sup> | number | false | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.FieldNode#type替代。<br>表示指定节点对应数据类型的值。  |  
    
### appendChild<sup>(deprecated)</sup>    
在当前 FieldNode 中添加一个子节点。  
 **调用形式：**     
- appendChild(child: FieldNode): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.FieldNode#appendChild。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.DistributedKVStore    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| child<sup>(deprecated)</sup> | FieldNode | true | 要附加的域节点。    |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true表示子节点成功添加到FieldNode；返回false则表示操作失败。 |  
    
 **示例代码：**   
示例：  
```ts    
import ddm from '@ohos.data.distributedData';  
try {  
    let node = new ddm.FieldNode("root");  
    let child1 = new ddm.FieldNode("child1");  
    let child2 = new ddm.FieldNode("child2");  
    let child3 = new ddm.FieldNode("child3");  
    node.appendChild(child1);  
    node.appendChild(child2);  
    node.appendChild(child3);  
    console.log("appendNode " + JSON.stringify(node));  
    child1 = null;  
    child2 = null;  
    child3 = null;  
    node = null;  
} catch (e) {  
    console.log("AppendChild " + e);  
}  
    
```    
  
    
## KvStoreResultSet<sup>(deprecated)</sup>    
提供获取KVStore数据库结果集的相关方法，包括查询和移动数据读取位置等。  
  
在调用KvStoreResultSet的方法前，需要先通过[getKVStore](#getkvstore)构建一个KVStore实例。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.KVStoreResultSet替代。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
### getCount<sup>(deprecated)</sup>    
获取结果集中的总行数。  
 **调用形式：**     
- getCount(): number  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.KVStoreResultSet#getCount。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回数据的总行数。 |  
    
 **示例代码：**   
示例：  
```ts    
let kvStore;  
try {  
    let resultSet;  
    kvStore.getResultSet('batch_test_string_key').then((result) => {  
        console.log('getResultSet succeed.');  
        resultSet = result;  
    }).catch((err) => {  
        console.log('getResultSet failed: ' + err);  
    });  
    const count = resultSet.getCount();  
    console.log("getCount succeed:" + count);  
} catch (e) {  
    console.log("getCount failed: " + e);  
}  
    
```    
  
    
### getPosition<sup>(deprecated)</sup>    
获取结果集中当前的读取位置。  
 **调用形式：**     
- getPosition(): number  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.KVStoreResultSet#getPosition。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回当前读取位置。 |  
    
 **示例代码：**   
示例：  
```ts    
let kvStore;  
try {  
    let resultSet;  
    kvStore.getResultSet('batch_test_string_key').then((result) => {  
        console.log('getResultSet succeeded.');  
        resultSet = result;  
    }).catch((err) => {  
        console.log('getResultSet failed: ' + err);  
    });  
    const position = resultSet.getPosition();  
    console.log("getPosition succeed:" + position);  
} catch (e) {  
    console.log("getPosition failed: " + e);  
}  
    
```    
  
    
### moveToFirst<sup>(deprecated)</sup>    
将读取位置移动到第一行。如果结果集为空，则返回false。  
 **调用形式：**     
- moveToFirst(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.KVStoreResultSet#moveToFirst。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true表示操作成功；返回false则表示操作失败。 |  
    
 **示例代码：**   
示例：  
```ts    
let kvStore;  
try {  
    let resultSet;  
    kvStore.getResultSet('batch_test_string_key').then((result) => {  
        console.log('getResultSet succeed.');  
        resultSet = result;  
    }).catch((err) => {  
        console.log('getResultSet failed: ' + err);  
    });  
    const moved1 = resultSet.moveToFirst();  
    console.log("moveToFirst succeed: " + moved1);  
} catch (e) {  
    console.log("moveToFirst failed " + e);  
}  
    
```    
  
    
### moveToLast<sup>(deprecated)</sup>    
将读取位置移动到最后一行。如果结果集为空，则返回false。  
 **调用形式：**     
- moveToLast(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.KVStoreResultSet#moveToLast。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true表示操作成功；返回false则表示操作失败。 |  
    
 **示例代码：**   
示例：  
```ts    
let kvStore;  
try {  
    let resultSet;  
    kvStore.getResultSet('batch_test_string_key').then((result) => {  
        console.log('getResultSet succeed.');  
        resultSet = result;  
    }).catch((err) => {  
        console.log('getResultSet failed: ' + err);  
    });  
    const moved2 = resultSet.moveToLast();  
    console.log("moveToLast succeed:" + moved2);  
} catch (e) {  
    console.log("moveToLast failed: " + e);  
}  
    
```    
  
    
### moveToNext<sup>(deprecated)</sup>    
将读取位置移动到下一行。如果结果集为空，则返回false。  
 **调用形式：**     
- moveToNext(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.KVStoreResultSet#moveToNext。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true表示操作成功；返回false则表示操作失败。 |  
    
 **示例代码：**   
示例：  
```ts    
let kvStore;  
try {  
    let resultSet;  
    kvStore.getResultSet('batch_test_string_key').then((result) => {  
        console.log('getResultSet succeed.');  
        resultSet = result;  
    }).catch((err) => {  
        console.log('getResultSet failed: ' + err);  
    });  
    const moved3 = resultSet.moveToNext();  
    console.log("moveToNext succeed: " + moved3);  
} catch (e) {  
    console.log("moveToNext failed: " + e);  
}  
    
```    
  
    
### moveToPrevious<sup>(deprecated)</sup>    
将读取位置移动到上一行。如果结果集为空，则返回false。  
 **调用形式：**     
- moveToPrevious(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.KVStoreResultSet#moveToPrevious。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true表示操作成功；返回false则表示操作失败。 |  
    
 **示例代码：**   
示例：  
```ts    
let kvStore;  
try {  
    let resultSet;  
    kvStore.getResultSet('batch_test_string_key').then((result) => {  
        console.log('getResultSet succeed.');  
        resultSet = result;  
    }).catch((err) => {  
        console.log('getResultSet failed: ' + err);  
    });  
    const moved4 = resultSet.moveToPrevious();  
    console.log("moveToPrevious succeed:" + moved4);  
} catch (e) {  
    console.log("moveToPrevious failed: " + e);  
}  
    
```    
  
    
### move<sup>(deprecated)</sup>    
将读取位置移动到当前位置的相对偏移量。  
 **调用形式：**     
- move(offset: number): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.KVStoreResultSet#move。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| offset<sup>(deprecated)</sup> | number | true | 表示与当前位置的相对偏移量，负偏移表示向后移动，正偏移表示向前移动。    |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true表示操作成功；返回false则表示操作失败。 |  
    
 **示例代码：**   
示例：  
```ts    
let kvStore;  
try {  
    let resultSet;  
    kvStore.getResultSet('batch_test_string_key').then((result) => {  
        console.log('getResultSet succeed.');  
        resultSet = result;  
    }).catch((err) => {  
        console.log('getResultSet failed: ' + err);  
    });  
    const moved5 = resultSet.move(1);  
    console.log("move succeed:" + moved5);  
} catch (e) {  
    console.log("move failed: " + e);  
}  
    
```    
  
    
### moveToPosition<sup>(deprecated)</sup>    
将读取位置从 0 移动到绝对位置。  
 **调用形式：**     
- moveToPosition(position: number): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.KVStoreResultSet#moveToPosition。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| position<sup>(deprecated)</sup> | number | true | 表示绝对位置。           |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true表示操作成功；返回false则表示操作失败。 |  
    
 **示例代码：**   
示例：  
```ts    
let kvStore;  
try {  
    let resultSet;  
    kvStore.getResultSet('batch_test_string_key').then((result) => {  
        console.log('getResultSet succeed.');  
        resultSet = result;  
    }).catch((err) => {  
        console.log('getResultSet failed: ' + err);  
    });  
    const moved6 = resultSet.moveToPosition(1);  
    console.log("moveToPosition succeed: " + moved6);  
} catch (e) {  
    console.log("moveToPosition failed: " + e);  
}  
    
```    
  
    
### isFirst<sup>(deprecated)</sup>    
检查读取位置是否为第一行。  
 **调用形式：**     
- isFirst(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.KVStoreResultSet#isFirst。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true表示读取位置为第一行；返回false表示读取位置不是第一行。 |  
    
 **示例代码：**   
示例：  
```ts    
let kvStore;  
try {  
    let resultSet;  
    kvStore.getResultSet('batch_test_string_key').then((result) => {  
        console.log('getResultSet succeed.');  
        resultSet = result;  
    }).catch((err) => {  
        console.log('getResultSet failed: ' + err);  
    });  
    const isfirst = resultSet.isFirst();  
    console.log("Check isFirst succeed:" + isfirst);  
} catch (e) {  
    console.log("Check isFirst failed: " + e);  
}  
    
```    
  
    
### isLast<sup>(deprecated)</sup>    
检查读取位置是否为最后一行。  
 **调用形式：**     
- isLast(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.KVStoreResultSet#isLast。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true表示读取位置为最后一行；返回false表示读取位置不是最后一行。 |  
    
 **示例代码：**   
示例：  
```ts    
let kvStore;  
try {  
    let resultSet;  
    kvStore.getResultSet('batch_test_string_key').then((result) => {  
        console.log('getResultSet succeed.');  
        resultSet = result;  
    }).catch((err) => {  
        console.log('getResultSet failed: ' + err);  
    });  
    const islast = resultSet.isLast();  
    console.log("Check isLast succeed: " + islast);  
} catch (e) {  
    console.log("Check isLast failed: " + e);  
}  
    
```    
  
    
### isBeforeFirst<sup>(deprecated)</sup>    
检查读取位置是否在第一行之前。  
 **调用形式：**     
- isBeforeFirst(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.KVStoreResultSet#isBeforeFirst。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true表示读取位置在第一行之前；返回false表示读取位置不在第一行之前。 |  
    
 **示例代码：**   
示例：  
```null    
let kvStore;  
try {  
    let resultSet;  
    kvStore.getResultSet('batch_test_string_key').then((result) => {  
        console.log('getResultSet succeed.');  
        resultSet = result;  
    }).catch((err) => {  
        console.log('getResultSet failed: ' + err);  
    });  
    const isbeforefirst = resultSet.isBeforeFirst();  
    console.log("Check isBeforeFirst succeed: " + isbeforefirst);  
} catch (e) {  
    console.log("Check isBeforeFirst failed: " + e);  
}  
    
```    
  
    
### isAfterLast<sup>(deprecated)</sup>    
检查读取位置是否在最后一行之后。  
 **调用形式：**     
- isAfterLast(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.KVStoreResultSet#isAfterLast。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true表示读取位置在最后一行之后；返回false表示读取位置不在最后一行之后。 |  
    
 **示例代码：**   
示例：  
```ts    
let kvStore;  
try {  
    let resultSet;  
    kvStore.getResultSet('batch_test_string_key').then((result) => {  
        console.log('getResultSet succeed.');  
        resultSet = result;  
    }).catch((err) => {  
        console.log('getResultSet failed: ' + err);  
    });  
    const isafterlast = resultSet.isAfterLast();  
    console.log("Check isAfterLast succeed:" + isafterlast);  
} catch (e) {  
    console.log("Check isAfterLast failed: " + e);  
}  
    
```    
  
    
### getEntry<sup>(deprecated)</sup>    
从当前位置获取对应的键值对。  
 **调用形式：**     
- getEntry(): Entry  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.KVStoreResultSet#getEntry。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Entry | 返回键值对。 |  
    
 **示例代码：**   
示例：  
```ts    
let kvStore;  
try {  
    let resultSet;  
    kvStore.getResultSet('batch_test_string_key').then((result) => {  
        console.log('getResultSet succeed.');  
        resultSet = result;  
    }).catch((err) => {  
        console.log('getResultSet failed: ' + err);  
    });  
    const entry  = resultSet.getEntry();  
    console.log("getEntry succeed:" + JSON.stringify(entry));  
} catch (e) {  
    console.log("getEntry failed: " + e);  
}  
    
```    
  
    
## Query<sup>(deprecated)</sup>    
使用谓词表示数据库查询，提供创建Query实例、查询数据库中的数据和添加谓词的方法。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.Query替代。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
### reset<sup>(deprecated)</sup>    
重置Query对象。  
 **调用形式：**     
- reset(): Query  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.Query#reset。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Query | 返回重置的Query对象。 |  
    
 **示例代码：**   
示例：  
```ts    
try {  
    let query = new distributedData.Query();  
    query.equalTo("key", "value");  
    console.log("query is " + query.getSqlLike());  
    query.reset();  
    console.log("query is " + query.getSqlLike());  
    query = null;  
} catch (e) {  
    console.log("simply calls should be ok :" + e);  
}  
    
```    
  
    
### equalTo<sup>(deprecated)</sup>    
构造一个Query对象来查询具有指定字段的条目，其值等于指定的值。  
 **调用形式：**     
- equalTo(field: string, value: number | string | boolean): Query  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.Query#equalTo。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field<sup>(deprecated)</sup> | string | true | 表示指定字段，不能包含' ^ '。   |  
| value<sup>(deprecated)</sup> | string | true | 表示指定的值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Query | 返回Query对象。 |  
    
 **示例代码：**   
示例：  
```ts    
try {  
    let query = new distributedData.Query();  
    query.equalTo("field", "value");  
    console.log("query is " + query.getSqlLike());  
    query = null;  
} catch (e) {  
    console.log("duplicated calls should be ok :" + e);  
}  
    
```    
  
    
### notEqualTo<sup>(deprecated)</sup>    
构造一个Query对象以查询具有指定字段且值不等于指定值的条目。  
 **调用形式：**     
- notEqualTo(field: string, value: number | string | boolean): Query  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.Query#notEqualTo。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field<sup>(deprecated)</sup> | string | true | 表示指定字段，不能包含' ^ '。  。 |  
| value<sup>(deprecated)</sup> | string | true | 表示指定的值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Query | 返回Query对象。 |  
    
 **示例代码：**   
示例：  
```ts    
try {  
    let query = new distributedData.Query();  
    query.notEqualTo("field", "value");  
    console.log("query is " + query.getSqlLike());  
    query = null;  
} catch (e) {  
    console.log("duplicated calls should be ok :" + e);  
}  
    
```    
  
    
### greaterThan<sup>(deprecated)</sup>    
构造一个Query对象以查询具有大于指定值的指定字段的条目。  
 **调用形式：**     
- greaterThan(field: string, value: number | string | boolean): Query  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.Query#greaterThan。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field<sup>(deprecated)</sup> | string | true | 表示指定字段，不能包含' ^ '。   |  
| value<sup>(deprecated)</sup> | string | true | 表示指定的值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Query | 返回Query对象。 |  
    
 **示例代码：**   
示例：  
```ts    
try {  
    let query = new distributedData.Query();  
    query.greaterThan("field", "value");  
    console.log("query is " + query.getSqlLike());  
    query = null;  
} catch (e) {  
    console.log("duplicated calls should be ok :" + e);  
}  
    
```    
  
    
### lessThan<sup>(deprecated)</sup>    
构造一个Query对象以查询具有小于指定值的指定字段的条目。  
 **调用形式：**     
- lessThan(field: string, value: number | string): Query  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.Query#lessThan。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field<sup>(deprecated)</sup> | string | true | 表示指定字段，不能包含' ^ '。   |  
| value<sup>(deprecated)</sup> | string | true | 表示指定的值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Query | 返回Query对象。 |  
    
 **示例代码：**   
示例：  
```ts    
try {  
    let query = new distributedData.Query();  
    query.lessThan("field", "value");  
    console.log("query is " + query.getSqlLike());  
    query = null;  
} catch (e) {  
    console.log("duplicated calls should be ok :" + e);  
}  
    
```    
  
    
### greaterThanOrEqualTo<sup>(deprecated)</sup>    
构造一个Query对象以查询具有指定字段且值大于或等于指定值的条目。  
 **调用形式：**     
- greaterThanOrEqualTo(field: string, value: number | string): Query  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.Query#greaterThanOrEqualTo。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field<sup>(deprecated)</sup> | string | true | 表示指定字段，不能包含' ^ '。   |  
| value<sup>(deprecated)</sup> | string | true | 表示指定的值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Query | 返回Query对象。 |  
    
 **示例代码：**   
示例：  
```ts    
try {  
    let query = new distributedData.Query();  
    query.greaterThanOrEqualTo("field", "value");  
    console.log("query is " + query.getSqlLike());  
    query = null;  
} catch (e) {  
    console.log("duplicated calls should be ok :" + e);  
}  
    
```    
  
    
### lessThanOrEqualTo<sup>(deprecated)</sup>    
构造一个Query对象以查询具有指定字段且值小于或等于指定值的条目。  
 **调用形式：**     
- lessThanOrEqualTo(field: string, value: number | string): Query  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.Query#lessThanOrEqualTo。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field<sup>(deprecated)</sup> | string | true | 表示指定字段，不能包含' ^ '。   |  
| value<sup>(deprecated)</sup> | string | true | 表示指定的值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Query | 返回Query对象。 |  
    
 **示例代码：**   
示例：  
```ts    
try {  
    let query = new distributedData.Query();  
    query.lessThanOrEqualTo("field", "value");  
    console.log("query is " + query.getSqlLike());  
    query = null;  
} catch (e) {  
    console.log("duplicated calls should be ok :" + e);  
}  
    
```    
  
    
### isNull<sup>(deprecated)</sup>    
构造一个Query对象以查询具有值为null的指定字段的条目。  
 **调用形式：**     
- isNull(field: string): Query  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.Query#isNull。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field<sup>(deprecated)</sup> | string | true | 表示指定字段，不能包含' ^ '。   |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Query | 返回Query对象。 |  
    
 **示例代码：**   
示例：  
```ts    
try {  
    let query = new distributedData.Query();  
    query.isNull("field");  
    console.log("query is " + query.getSqlLike());  
    query = null;  
} catch (e) {  
    console.log("duplicated calls should be ok :" + e);  
}  
    
```    
  
    
### inNumber<sup>(deprecated)</sup>    
构造一个Query对象以查询具有指定字段的条目，其值在指定的值列表中。  
 **调用形式：**     
- inNumber(field: string, valueList: number[]): Query  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.Query#inNumber。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field<sup>(deprecated)</sup> | string | true | 表示指定字段，不能包含' ^ '。   |  
| valueList<sup>(deprecated)</sup> | number[] | true | 表示指定的值列表。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Query | 返回Query对象。 |  
    
 **示例代码：**   
示例：  
```ts    
try {  
    let query = new distributedData.Query();  
    query.inNumber("field", [0, 1]);  
    console.log("query is " + query.getSqlLike());  
    query = null;  
} catch (e) {  
    console.log("duplicated calls should be ok :" + e);  
}  
    
```    
  
    
### inString<sup>(deprecated)</sup>    
构造一个Query对象以查询具有指定字段的条目，其值在指定的字符串值列表中。  
 **调用形式：**     
- inString(field: string, valueList: string[]): Query  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.Query#inString。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field<sup>(deprecated)</sup> | string | true | 表示指定字段，不能包含' ^ '。   |  
| valueList<sup>(deprecated)</sup> | string[] | true | 表示指定的字符串值列表。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Query | 返回Query对象。 |  
    
 **示例代码：**   
示例：  
```ts    
try {  
    let query = new distributedData.Query();  
    query.inString("field", ['test1', 'test2']);  
    console.log("query is " + query.getSqlLike());  
    query = null;  
} catch (e) {  
    console.log("duplicated calls should be ok :" + e);  
}  
    
```    
  
    
### notInNumber<sup>(deprecated)</sup>    
构造一个Query对象以查询具有指定字段的条目，该字段的值不在指定的值列表中。  
 **调用形式：**     
- notInNumber(field: string, valueList: number[]): Query  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.Query#notInNumber。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field<sup>(deprecated)</sup> | string | true | 表示指定字段，不能包含' ^ '。   |  
| valueList<sup>(deprecated)</sup> | number[] | true | 表示指定的值列表。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Query | 返回Query对象。 |  
    
 **示例代码：**   
示例：  
```ts    
try {  
    let query = new distributedData.Query();  
    query.notInNumber("field", [0, 1]);  
    console.log("query is " + query.getSqlLike());  
    query = null;  
} catch (e) {  
    console.log("duplicated calls should be ok :" + e);  
}  
    
```    
  
    
### notInString<sup>(deprecated)</sup>    
构造一个Query对象以查询具有指定字段且值不在指定字符串值列表中的条目。  
 **调用形式：**     
- notInString(field: string, valueList: string[]): Query  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.Query#notInString。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field<sup>(deprecated)</sup> | string | true | 表示指定字段，不能包含' ^ '。   |  
| valueList<sup>(deprecated)</sup> | string[] | true | 表示指定的字符串值列表。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Query | 返回Query对象。 |  
    
 **示例代码：**   
示例：  
```ts    
try {  
    let query = new distributedData.Query();  
    query.notInString("field", ['test1', 'test2']);  
    console.log("query is " + query.getSqlLike());  
    query = null;  
} catch (e) {  
    console.log("duplicated calls should be ok :" + e);  
}  
    
```    
  
    
### like<sup>(deprecated)</sup>    
构造一个Query对象以查询具有与指定字符串值相似的指定字段的条目。  
 **调用形式：**     
- like(field: string, value: string): Query  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.Query#like。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field<sup>(deprecated)</sup> | string | true | 表示指定字段，不能包含' ^ '。   |  
| value<sup>(deprecated)</sup> | string | true | 表示指定的字符串值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Query | 返回Query对象。 |  
    
 **示例代码：**   
示例：  
```ts    
try {  
    let query = new distributedData.Query();  
    query.like("field", "value");  
    console.log("query is " + query.getSqlLike());  
    query = null;  
} catch (e) {  
    console.log("duplicated calls should be ok :" + e);  
}  
    
```    
  
    
### unlike<sup>(deprecated)</sup>    
构造一个Query对象以查询具有与指定字符串值不相似的指定字段的条目。  
 **调用形式：**     
- unlike(field: string, value: string): Query  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.Query#unlike。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field<sup>(deprecated)</sup> | string | true | 表示指定字段，不能包含' ^ '。   |  
| value<sup>(deprecated)</sup> | string | true | 表示指定的字符串值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Query | 返回Query对象。 |  
    
 **示例代码：**   
示例：  
```ts    
try {  
    let query = new distributedData.Query();  
    query.unlike("field", "value");  
    console.log("query is " + query.getSqlLike());  
    query = null;  
} catch (e) {  
    console.log("duplicated calls should be ok :" + e);  
}  
    
```    
  
    
### and<sup>(deprecated)</sup>    
构造一个带有与条件的查询对象。  
 **调用形式：**     
- and(): Query  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.Query#and。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Query | 返回查询对象。 |  
    
 **示例代码：**   
示例：  
```ts    
try {  
    let query = new distributedData.Query();  
    query.notEqualTo("field", "value1");  
    query.and();  
    query.notEqualTo("field", "value2");  
    console.log("query is " + query.getSqlLike());  
    query = null;  
} catch (e) {  
    console.log("duplicated calls should be ok :" + e);  
}  
    
```    
  
    
### or<sup>(deprecated)</sup>    
构造一个带有或条件的Query对象。  
 **调用形式：**     
- or(): Query  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.Query#or。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Query | 返回查询对象。 |  
    
 **示例代码：**   
示例：  
```ts    
try {  
    let query = new distributedData.Query();  
    query.notEqualTo("field", "value1");  
    query.or();  
    query.notEqualTo("field", "value2");  
    console.log("query is " + query.getSqlLike());  
    query = null;  
} catch (e) {  
    console.log("duplicated calls should be ok :" + e);  
}  
    
```    
  
    
### orderByAsc<sup>(deprecated)</sup>    
构造一个Query对象，将查询结果按升序排序。  
 **调用形式：**     
- orderByAsc(field: string): Query  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.Query#orderByAsc。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field<sup>(deprecated)</sup> | string | true | 表示指定字段，不能包含' ^ '。   |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Query | 返回Query对象。 |  
    
 **示例代码：**   
示例：  
```ts    
try {  
    let query = new distributedData.Query();  
    query.notEqualTo("field", "value");  
    query.orderByAsc("field");  
    console.log("query is " + query.getSqlLike());  
    query = null;  
} catch (e) {  
    console.log("duplicated calls should be ok :" + e);  
}  
    
```    
  
    
### orderByDesc<sup>(deprecated)</sup>    
构造一个Query对象，将查询结果按降序排序。  
 **调用形式：**     
- orderByDesc(field: string): Query  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.Query#orderByDesc。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field<sup>(deprecated)</sup> | string | true | 表示指定字段，不能包含' ^ '。   |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Query | 返回Query对象。 |  
    
 **示例代码：**   
示例：  
```ts    
try {  
    let query = new distributedData.Query();  
    query.notEqualTo("field", "value");  
    query.orderByDesc("field");  
    console.log("query is " + query.getSqlLike());  
    query = null;  
} catch (e) {  
    console.log("duplicated calls should be ok :" + e);  
}  
    
```    
  
    
### limit<sup>(deprecated)</sup>    
构造一个Query对象来指定结果的数量和开始位置。  
 **调用形式：**     
- limit(total: number, offset: number): Query  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.Query#limit。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| total<sup>(deprecated)</sup> | number | true | 表示指定的结果数。   |  
| offset<sup>(deprecated)</sup> | number | true | 表示起始位置。   |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Query | 返回Query对象。 |  
    
 **示例代码：**   
示例：  
```ts    
let total = 10;  
let offset = 1;  
try {  
    let query = new distributedData.Query();  
    query.notEqualTo("field", "value");  
    query.limit(total, offset);  
    console.log("query is " + query.getSqlLike());  
    query = null;  
} catch (e) {  
    console.log("duplicated calls should be ok :" + e);  
}  
    
```    
  
    
### isNotNull<sup>(deprecated)</sup>    
构造一个Query对象以查询具有值不为null的指定字段的条目。  
 **调用形式：**     
- isNotNull(field: string): Query  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.Query#isNotNull。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field<sup>(deprecated)</sup> | string | true | 表示指定字段，不能包含' ^ '。       |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Query | 返回Query对象。 |  
    
 **示例代码：**   
示例：  
```ts    
try {  
    let query = new distributedData.Query();  
    query.isNotNull("field");  
    console.log("query is " + query.getSqlLike());  
    query = null;  
} catch (e) {  
    console.log("duplicated calls should be ok :" + e);  
}  
    
```    
  
    
### beginGroup<sup>(deprecated)</sup>    
创建一个带有左括号的查询条件组。  
 **调用形式：**     
- beginGroup(): Query  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.Query#beginGroup。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Query | 返回Query对象。 |  
    
 **示例代码：**   
示例：  
```ts    
try {  
    let query = new distributedData.Query();  
    query.beginGroup();  
    query.isNotNull("field");  
    query.endGroup();  
    console.log("query is " + query.getSqlLike());  
    query = null;  
} catch (e) {  
    console.log("duplicated calls should be ok :" + e);  
}  
    
```    
  
    
### endGroup<sup>(deprecated)</sup>    
创建一个带有右括号的查询条件组。  
 **调用形式：**     
- endGroup(): Query  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.Query#endGroup。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Query | 返回Query对象。 |  
    
 **示例代码：**   
示例：  
```ts    
try {  
    let query = new distributedData.Query();  
    query.beginGroup();  
    query.isNotNull("field");  
    query.endGroup();  
    console.log("query is " + query.getSqlLike());  
    query = null;  
} catch (e) {  
    console.log("duplicated calls should be ok :" + e);  
}  
    
```    
  
    
### prefixKey<sup>(deprecated)</sup>    
创建具有指定键前缀的查询条件。  
 **调用形式：**     
- prefixKey(prefix: string): Query  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.Query#prefixKey。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| prefix<sup>(deprecated)</sup> | string | true | 表示指定的键前缀。      |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Query | 返回Query对象。 |  
    
 **示例代码：**   
示例：  
```ts    
try {  
    let query = new distributedData.Query();  
    query.prefixKey("$.name");  
    query.prefixKey("0");  
    console.log("query is " + query.getSqlLike());  
    query = null;  
} catch (e) {  
    console.log("duplicated calls should be ok :" + e);  
}  
    
```    
  
    
### setSuggestIndex<sup>(deprecated)</sup>    
设置一个指定的索引，将优先用于查询。  
 **调用形式：**     
- setSuggestIndex(index: string): Query  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.Query#setSuggestIndex。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| index<sup>(deprecated)</sup> | string | true | 指示要设置的索引。    |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Query | 返回Query对象。 |  
    
 **示例代码：**   
示例：  
```ts    
try {  
    let query = new distributedData.Query();  
    query.setSuggestIndex("$.name");  
    query.setSuggestIndex("0");  
    console.log("query is " + query.getSqlLike());  
    query = null;  
} catch (e) {  
   console.log("duplicated calls should be ok :" + e);  
}  
    
```    
  
    
### deviceId<sup>(deprecated)</sup>    
添加设备ID作为key的前缀。  
 **调用形式：**     
- deviceId(deviceId: string): Query  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.Query#deviceId。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId<sup>(deprecated)</sup> | string | true | 指示查询的设备ID。    |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Query | 返回Query对象。 |  
    
 **示例代码：**   
示例：  
```ts    
try {  
    let query = new distributedData.Query();  
    query.deviceId("deviceId");  
    console.log("query is " + query.getSqlLike());  
} catch (e) {  
    console.log("should be ok on Method Chaining : " + e);  
}  
    
```    
  
    
### getSqlLike<sup>(deprecated)</sup>    
获取Query对象的查询语句。  
 **调用形式：**     
- getSqlLike(): string  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.Query#getSqlLike。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回一个字段列中包含对应子串的结果。 |  
    
 **示例代码：**   
示例：  
```ts    
try {  
    let query = new distributedData.Query();  
    let sql1 = query.getSqlLike();  
    console.log("GetSqlLike sql=" + sql1);  
} catch (e) {  
    console.log("duplicated calls should be ok : " + e);  
}  
    
```    
  
    
## KVStore<sup>(deprecated)</sup>    
KVStore数据库实例，提供增加数据、删除数据和订阅数据变更、订阅数据同步完成的方法。  
  
在调用KVStore的方法前，需要先通过[getKVStore](#getkvstore)构建一个KVStore实例。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.SingleKVStore替代。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
### put<sup>(deprecated)</sup>    
添加指定类型键值对到数据库，使用callback异步回调。  
 **调用形式：**     
- put(key: string, value: Uint8Array | string | number | boolean, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.SingleKVStore#put。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key<sup>(deprecated)</sup> | string | true | 要添加数据的key，不能为空且长度不大于[MAX_KEY_LENGTH](#constants)。    |  
| value<sup>(deprecated)</sup> | string | true | 要添加数据的value，支持Uint8Array、number 、 string 、boolean，Uint8Array、string 的长度不大于[MAX_VALUE_LENGTH](#constants)。    |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。    |  
    
 **示例代码：**   
示例：  
```ts    
let kvStore;  
const KEY_TEST_STRING_ELEMENT = 'key_test_string';  
const VALUE_TEST_STRING_ELEMENT = 'value-test-string';  
try {  
    kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT, function (err,data) {  
        if (err != undefined) {  
            console.log("put err: " + JSON.stringify(err));  
            return;  
        }  
        console.log("put success");  
    });  
}catch (e) {  
    console.log("An unexpected error occurred. Error:" + e);  
}  
    
```    
  
    
### put    
添加指定类型键值对到数据库  
 **调用形式：**     
    
- put(key: string, value: Uint8Array | string | number | boolean): Promise\<void>    
起始版本： 7  
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key | string | true | 要添加数据的key，不能为空且长度不大于[MAX_KEY_LENGTH](#constants)。    |  
| value | string | true | 要添加数据的value，支持Uint8Array、number 、 string 、boolean，Uint8Array、string 的长度不大于[MAX_VALUE_LENGTH](#constants)。    |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
let kvStore;  
const KEY_TEST_STRING_ELEMENT = 'key_test_string';  
const VALUE_TEST_STRING_ELEMENT = 'value-test-string';  
try {  
    kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT, function (err,data) {  
        if (err != undefined) {  
            console.log("put err: " + JSON.stringify(err));  
            return;  
        }  
        console.log("put success");  
    });  
}catch (e) {  
    console.log("An unexpected error occurred. Error:" + e);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
let kvStore;  
const KEY_TEST_STRING_ELEMENT = 'key_test_string';  
const VALUE_TEST_STRING_ELEMENT = 'value-test-string';  
try {  
    kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT).then((data) => {  
        console.log("put success: " + JSON.stringify(data));  
    }).catch((err) => {  
        console.log("put err: " + JSON.stringify(err));  
    });  
}catch (e) {  
    console.log("An unexpected error occurred. Error:" + e);  
}  
    
```    
  
    
### delete<sup>(deprecated)</sup>    
从数据库中删除指定键值的数据。  
 **调用形式：**     
- delete(key: string, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.SingleKVStore#delete。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key<sup>(deprecated)</sup> | string | true | 要删除数据的key，不能为空且长度不大于[MAX_KEY_LENGTH](#constants)。    |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。    |  
    
 **示例代码：**   
示例：  
```ts    
let kvStore;  
const KEY_TEST_STRING_ELEMENT = 'key_test_string';  
const VALUE_TEST_STRING_ELEMENT = 'value-test-string';  
try {  
    kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT, function (err,data) {  
        if (err != undefined) {  
            console.log("put err: " + JSON.stringify(err));  
            return;  
        }  
        console.log("put success");  
        kvStore.delete(KEY_TEST_STRING_ELEMENT, function (err,data) {  
            if (err != undefined) {  
                console.log("delete err: " + JSON.stringify(err));  
                return;  
            }  
            console.log("delete success");  
        });  
    });  
}catch (e) {  
    console.log("An unexpected error occurred. Error:" + e);  
}  
    
```    
  
    
### delete    
从数据库中删除指定键值的数据，使用Promise异步回调。  
 **调用形式：**     
    
- delete(key: string): Promise\<void>    
起始版本： 7  
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key | string | true | 要删除数据的key，不能为空且长度不大于[MAX_KEY_LENGTH](#constants)。    |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
let kvStore;  
const KEY_TEST_STRING_ELEMENT = 'key_test_string';  
const VALUE_TEST_STRING_ELEMENT = 'value-test-string';  
try {  
    kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT, function (err,data) {  
        if (err != undefined) {  
            console.log("put err: " + JSON.stringify(err));  
            return;  
        }  
        console.log("put success");  
        kvStore.delete(KEY_TEST_STRING_ELEMENT, function (err,data) {  
            if (err != undefined) {  
                console.log("delete err: " + JSON.stringify(err));  
                return;  
            }  
            console.log("delete success");  
        });  
    });  
}catch (e) {  
    console.log("An unexpected error occurred. Error:" + e);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
let kvStore;  
const KEY_TEST_STRING_ELEMENT = 'key_test_string';  
const VALUE_TEST_STRING_ELEMENT = 'value-test-string';  
try {  
    kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT).then((data) => {  
        console.log("put success: " + JSON.stringify(data));  
        kvStore.delete(KEY_TEST_STRING_ELEMENT).then((data) => {  
            console.log("delete success");  
        }).catch((err) => {  
            console.log("delete err: " + JSON.stringify(err));  
        });  
    }).catch((err) => {  
        console.log("put err: " + JSON.stringify(err));  
    });  
}catch (e) {  
    console.log("An unexpected error occurred. Error:" + e);  
}  
    
```    
  
    
### on('dataChange')<sup>(deprecated)</sup>    
订阅指定类型的数据变更通知。  
 **调用形式：**     
- on(event: 'dataChange', type: SubscribeType, listener: Callback\<ChangeNotification>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.SingleKVStore#on。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event<sup>(deprecated)</sup> | string | true | 订阅的事件名，固定为'dataChange'，表示数据变更事件。  |  
| type<sup>(deprecated)</sup> | SubscribeType | true | 表示订阅的类型。                                      |  
| listener<sup>(deprecated)</sup> | Callback<ChangeNotification> | true | 回调函数。                                            |  
    
 **示例代码：**   
示例：  
```ts    
let kvStore;  
kvStore.on('dataChange', distributedData.SubscribeType.SUBSCRIBE_TYPE_LOCAL, function (data) {  
    console.log("dataChange callback call data: " + JSON.stringify(data));  
});    
```    
  
    
### on('syncComplete')<sup>(deprecated)</sup>    
订阅同步完成事件回调通知。  
 **调用形式：**     
- on(event: 'syncComplete', syncCallback: Callback\<Array\<[string, number]>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.SingleKVStore#on。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event<sup>(deprecated)</sup> | string | true | 订阅的事件名，固定为'syncComplete'，表示同步完成事件。  |  
| syncCallback<sup>(deprecated)</sup> | Callback<Array<[string, number]>> | true | 回调函数。用于向调用方发送同步结果的回调。              |  
    
 **示例代码：**   
示例：  
```ts    
let kvStore;  
kvStore.on('syncComplete', function (data) {  
    console.log("callback call data: " + data);  
});    
```    
  
    
### off('dataChange')<sup>(deprecated)</sup>    
取消订阅数据变更通知。  
 **调用形式：**     
- off(event: 'dataChange', listener?: Callback\<ChangeNotification>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.SingleKVStore#off。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event<sup>(deprecated)</sup> | string | true | 取消订阅的事件名，固定为'dataChange'，表示数据变更事件。  |  
| listener<sup>(deprecated)</sup> | Callback<ChangeNotification> | false | 取消订阅的函数。如不设置callback，则取消所有订阅的函数。  |  
    
 **示例代码：**   
示例：  
```ts    
let kvStore;  
class KvstoreModel {  
    call(data) {  
        console.log("dataChange: " + data);  
    }  
    subscribeDataChange() {  
        if (kvStore != null) {  
            kvStore.on('dataChange', distributedData.SubscribeType.SUBSCRIBE_TYPE_REMOTE, this.call);  
        }  
    }  
    unsubscribeDataChange() {  
        if (kvStore != null) {  
            kvStore.off('dataChange', this.call);  
        }  
    }  
}  
    
```    
  
    
### off('syncComplete')<sup>(deprecated)</sup>    
取消订阅同步完成事件回调通知。  
 **调用形式：**     
- off(event: 'syncComplete', syncCallback?: Callback\<Array\<[string, number]>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.SingleKVStore#off。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event<sup>(deprecated)</sup> | string | true | 取消订阅的事件名，固定为'syncComplete'，表示同步完成事件。 |  
| syncCallback<sup>(deprecated)</sup> | Callback<Array<[string, number]>> | false | 取消订阅的函数。如不设置callback，则取消所有订阅的函数。 |  
    
 **示例代码：**   
示例：  
```ts    
let kvStore;  
class KvstoreModel {  
    call(data) {  
        console.log("syncComplete: " + data);  
    }  
    subscribeSyncComplete() {  
        if (kvStore != null) {  
            kvStore.on('syncComplete', this.call);  
        }  
    }  
    unsubscribeSyncComplete() {  
        if (kvStore != null) {  
            kvStore.off('syncComplete', this.call);  
        }  
    }  
}  
    
```    
  
    
### putBatch<sup>(deprecated)</sup>    
批量插入键值对到KVStore数据库中，使用callback异步回调。  
 **调用形式：**     
- putBatch(entries: Entry[], callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.SingleKVStore#putBatch。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| entries<sup>(deprecated)</sup> | Entry[] | true | 表示要批量插入的键值对。   |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。  |  
    
 **示例代码：**   
示例：  
```ts    
let kvStore;  
try {  
    let entries = [];  
    for (var i = 0; i < 10; i++) {  
        var key = 'batch_test_string_key';  
        var entry = {  
            key : key + i,  
            value : {  
                type : distributedData.ValueType.STRING,  
                value : 'batch_test_string_value'  
            }  
        }  
        entries.push(entry);  
    }  
    console.log('entries: ' + JSON.stringify(entries));  
    kvStore.putBatch(entries, async function (err,data) {  
        console.log('putBatch success');  
        kvStore.getEntries('batch_test_string_key', function (err,entries) {  
            console.log('getEntries success');  
            console.log('entries.length: ' + entries.length);  
            console.log('entries[0]: ' + JSON.stringify(entries[0]));  
        });  
    });  
}catch(e) {  
    console.log('PutBatch e ' + JSON.stringify(e));  
}  
    
```    
  
    
### putBatch    
批量插入键值对到KVStore数据库中  
 **调用形式：**     
    
- putBatch(entries: Entry[]): Promise\<void>    
起始版本： 7  
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| entries | Entry[] | true | 表示要批量插入的键值对。   |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
let kvStore;  
try {  
    let entries = [];  
    for (var i = 0; i < 10; i++) {  
        var key = 'batch_test_string_key';  
        var entry = {  
            key : key + i,  
            value : {  
                type : distributedData.ValueType.STRING,  
                value : 'batch_test_string_value'  
            }  
        }  
        entries.push(entry);  
    }  
    console.log('entries: ' + JSON.stringify(entries));  
    kvStore.putBatch(entries, async function (err,data) {  
        console.log('putBatch success');  
        kvStore.getEntries('batch_test_string_key', function (err,entries) {  
            console.log('getEntries success');  
            console.log('entries.length: ' + entries.length);  
            console.log('entries[0]: ' + JSON.stringify(entries[0]));  
        });  
    });  
}catch(e) {  
    console.log('PutBatch e ' + JSON.stringify(e));  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
let kvStore;  
try {  
    let entries = [];  
    for (var i = 0; i < 10; i++) {  
        var key = 'batch_test_string_key';  
        var entry = {  
            key : key + i,  
            value : {  
                type : distributedData.ValueType.STRING,  
                value : 'batch_test_string_value'  
            }  
        }  
        entries.push(entry);  
    }  
    console.log('entries: ' + JSON.stringify(entries));  
    kvStore.putBatch(entries).then(async (err) => {  
        console.log('putBatch success');  
        kvStore.getEntries('batch_test_string_key').then((entries) => {  
            console.log('getEntries success');  
            console.log('PutBatch ' + JSON.stringify(entries));  
        }).catch((err) => {  
            console.log('getEntries fail ' + JSON.stringify(err));  
        });  
    }).catch((err) => {  
        console.log('putBatch fail ' + JSON.stringify(err));  
    });  
}catch(e) {  
    console.log('PutBatch e ' + JSON.stringify(e));  
}  
    
```    
  
    
### deleteBatch<sup>(deprecated)</sup>    
批量删除KVStore数据库中的键值对，使用callback异步回调。  
 **调用形式：**     
- deleteBatch(keys: string[], callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.SingleKVStore#deleteBatch。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| keys<sup>(deprecated)</sup> | string[] | true | 表示要批量删除的键值对。   |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。   |  
    
 **示例代码：**   
示例：  
```ts    
let kvStore;  
try {  
    let entries = [];  
    let keys = [];  
    for (var i = 0; i < 5; i++) {  
        var key = 'batch_test_string_key';  
        var entry = {  
            key : key + i,  
            value : {  
                type : distributedData.ValueType.STRING,  
                value : 'batch_test_string_value'  
            }  
        }  
        entries.push(entry);  
        keys.push(key + i);  
    }  
    console.log('entries: ' + JSON.stringify(entries));  
    kvStore.putBatch(entries, async function (err,data) {  
        console.log('putBatch success');  
        kvStore.deleteBatch(keys, async function (err,data) {  
            console.log('deleteBatch success');  
        });  
    });  
}catch(e) {  
    console.log('DeleteBatch e ' + e);  
}  
    
```    
  
    
### deleteBatch    
批量删除KVStore数据库中的键值对  
 **调用形式：**     
    
- deleteBatch(keys: string[]): Promise\<void>    
起始版本： 7  
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| keys | string[] | true | 表示要批量删除的键值对。   |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
let kvStore;  
try {  
    let entries = [];  
    let keys = [];  
    for (var i = 0; i < 5; i++) {  
        var key = 'batch_test_string_key';  
        var entry = {  
            key : key + i,  
            value : {  
                type : distributedData.ValueType.STRING,  
                value : 'batch_test_string_value'  
            }  
        }  
        entries.push(entry);  
        keys.push(key + i);  
    }  
    console.log('entries: ' + JSON.stringify(entries));  
    kvStore.putBatch(entries, async function (err,data) {  
        console.log('putBatch success');  
        kvStore.deleteBatch(keys, async function (err,data) {  
            console.log('deleteBatch success');  
        });  
    });  
}catch(e) {  
    console.log('DeleteBatch e ' + e);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
let kvStore;  
try {  
    let entries = [];  
    let keys = [];  
    for (var i = 0; i < 5; i++) {  
        var key = 'batch_test_string_key';  
        var entry = {  
            key : key + i,  
            value : {  
                type : distributedData.ValueType.STRING,  
                value : 'batch_test_string_value'  
            }  
        }  
        entries.push(entry);  
        keys.push(key + i);  
    }  
    console.log('entries: ' + JSON.stringify(entries));  
    kvStore.putBatch(entries).then(async (err) => {  
        console.log('putBatch success');  
        kvStore.deleteBatch(keys).then((err) => {  
            console.log('deleteBatch success');  
        }).catch((err) => {  
            console.log('deleteBatch fail ' + JSON.stringify(err));  
        });  
    }).catch((err) => {  
        console.log('putBatch fail ' + JSON.stringify(err));  
    });  
}catch(e) {  
    console.log('DeleteBatch e ' + e);  
}  
    
```    
  
    
### startTransaction<sup>(deprecated)</sup>    
启动KVStore数据库中的事务，使用callback异步回调。  
 **调用形式：**     
- startTransaction(callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.SingleKVStore#startTransaction。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。   |  
    
 **示例代码：**   
示例：  
```ts    
let kvStore;  
function putBatchString(len, prefix) {  
    let entries = [];  
    for (var i = 0; i < len; i++) {  
        var entry = {  
            key : prefix + i,  
            value : {  
                type : distributedData.ValueType.STRING,  
                value : 'batch_test_string_value'  
            }  
        }  
        entries.push(entry);  
    }  
    return entries;  
}  
try {  
    var count = 0;  
    kvStore.on('dataChange', 0, function (data) {  
        console.log('startTransaction 0' + data)  
        count++;  
    });  
    kvStore.startTransaction(async function (err,data) {  
        console.log('startTransaction success');  
        let entries = putBatchString(10, 'batch_test_string_key');  
        console.log('entries: ' + JSON.stringify(entries));  
        kvStore.putBatch(entries, async function (err,data) {  
            console.log('putBatch success');  
        });  
    });  
}catch(e) {  
    console.log('startTransaction e ' + e);  
}  
    
```    
  
    
### startTransaction    
启动KVStore数据库中的事务  
 **调用形式：**     
    
- startTransaction(): Promise\<void>    
起始版本： 7  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
let kvStore;  
function putBatchString(len, prefix) {  
    let entries = [];  
    for (var i = 0; i < len; i++) {  
        var entry = {  
            key : prefix + i,  
            value : {  
                type : distributedData.ValueType.STRING,  
                value : 'batch_test_string_value'  
            }  
        }  
        entries.push(entry);  
    }  
    return entries;  
}  
try {  
    var count = 0;  
    kvStore.on('dataChange', 0, function (data) {  
        console.log('startTransaction 0' + data)  
        count++;  
    });  
    kvStore.startTransaction(async function (err,data) {  
        console.log('startTransaction success');  
        let entries = putBatchString(10, 'batch_test_string_key');  
        console.log('entries: ' + JSON.stringify(entries));  
        kvStore.putBatch(entries, async function (err,data) {  
            console.log('putBatch success');  
        });  
    });  
}catch(e) {  
    console.log('startTransaction e ' + e);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
let kvStore;  
try {  
    var count = 0;  
    kvStore.on('dataChange', distributedData.SubscribeType.SUBSCRIBE_TYPE_ALL, function (data) {  
        console.log('startTransaction ' + JSON.stringify(data));  
        count++;  
    });  
    kvStore.startTransaction().then(async (err) => {  
        console.log('startTransaction success');  
    }).catch((err) => {  
        console.log('startTransaction fail ' + JSON.stringify(err));  
    });  
}catch(e) {  
    console.log('startTransaction e ' + e);  
}  
    
```    
  
    
### commit<sup>(deprecated)</sup>    
提交KVStore数据库中的事务，使用callback异步回调。  
 **调用形式：**     
- commit(callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.SingleKVStore#commit。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。   |  
    
 **示例代码：**   
示例：  
```ts    
let kvStore;  
try {  
    kvStore.commit(function (err,data) {  
        if (err == undefined) {  
            console.log('commit success');  
        } else {  
            console.log('commit fail');  
        }  
    });  
}catch(e) {  
    console.log('Commit e ' + e);  
}  
    
```    
  
    
### commit    
提交KVStore数据库中的事务  
 **调用形式：**     
    
- commit(): Promise\<void>    
起始版本： 7  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码1：**   
示例（callback<span style="letter-spacing: 0px;">）：</span>  
```ts    
let kvStore;  
try {  
    kvStore.commit(function (err,data) {  
        if (err == undefined) {  
            console.log('commit success');  
        } else {  
            console.log('commit fail');  
        }  
    });  
}catch(e) {  
    console.log('Commit e ' + e);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
let kvStore;  
try {  
    kvStore.commit().then(async (err) => {  
        console.log('commit success');  
    }).catch((err) => {  
        console.log('commit fail ' + JSON.stringify(err));  
    });  
}catch(e) {  
    console.log('Commit e ' + e);  
}  
    
```    
  
    
### rollback<sup>(deprecated)</sup>    
在KVStore数据库中回滚事务，使用callback异步回调。  
 **调用形式：**     
- rollback(callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.SingleKVStore#rollback。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。   |  
    
 **示例代码：**   
示例：  
```ts    
let kvStore;  
try {  
    kvStore.rollback(function (err,data) {  
        if (err == undefined) {  
            console.log('commit success');  
        } else {  
            console.log('commit fail');  
        }  
    });  
}catch(e) {  
    console.log('Rollback e ' + e);  
}  
    
```    
  
    
### rollback    
在KVStore数据库中回滚事务  
 **调用形式：**     
    
- rollback(): Promise\<void>    
起始版本： 7  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
let kvStore;  
try {  
    kvStore.rollback(function (err,data) {  
        if (err == undefined) {  
            console.log('commit success');  
        } else {  
            console.log('commit fail');  
        }  
    });  
}catch(e) {  
    console.log('Rollback e ' + e);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
let kvStore;  
try {  
    kvStore.rollback().then(async (err) => {  
        console.log('rollback success');  
    }).catch((err) => {  
        console.log('rollback fail ' + JSON.stringify(err));  
    });  
}catch(e) {  
    console.log('Rollback e ' + e);  
}  
    
```    
  
    
### enableSync<sup>(deprecated)</sup>    
设定是否开启同步，使用callback异步回调。  
 **调用形式：**     
- enableSync(enabled: boolean, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.SingleKVStore#enableSync。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| enabled<sup>(deprecated)</sup> | boolean | true | 设定是否开启同步，true表示开启同步，false表示不启用同步。   |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。   |  
    
 **示例代码：**   
示例：  
```ts    
let kvStore;  
try {  
    kvStore.enableSync(true, function (err,data) {  
        if (err == undefined) {  
            console.log('enableSync success');  
        } else {  
            console.log('enableSync fail');  
        }  
    });  
}catch(e) {  
    console.log('EnableSync e ' + e);  
}  
    
```    
  
    
### enableSync    
设定是否开启同步  
 **调用形式：**     
    
- enableSync(enabled: boolean): Promise\<void>    
起始版本： 7  
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| enabled | boolean | true | 设定是否开启同步，true表示开启同步，false表示不启用同步。   |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
let kvStore;  
try {  
    kvStore.enableSync(true, function (err,data) {  
        if (err == undefined) {  
            console.log('enableSync success');  
        } else {  
            console.log('enableSync fail');  
        }  
    });  
}catch(e) {  
    console.log('EnableSync e ' + e);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
let kvStore;  
try {  
    kvStore.enableSync(true).then((err) => {  
        console.log('enableSync success');  
    }).catch((err) => {  
        console.log('enableSync fail ' + JSON.stringify(err));  
    });  
}catch(e) {  
    console.log('EnableSync e ' + e);  
}  
    
```    
  
    
### setSyncRange<sup>(deprecated)</sup>    
设置同步范围标签，使用callback异步回调。  
 **调用形式：**     
- setSyncRange(localLabels: string[], remoteSupportLabels: string[], callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.SingleKVStore#setSyncRange。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| localLabels<sup>(deprecated)</sup> | string[] | true | 表示本地设备的同步标签。   |  
| remoteSupportLabels<sup>(deprecated)</sup> | string[] | true | 表示要同步数据的设备的同步标签。   |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。   |  
    
 **示例代码：**   
示例：  
```ts    
let kvStore;  
try {  
    const localLabels = ['A', 'B'];  
    const remoteSupportLabels = ['C', 'D'];  
    kvStore.setSyncRange(localLabels, remoteSupportLabels, function (err,data) {  
        console.log('SetSyncRange put success');  
    });  
}catch(e) {  
    console.log('SetSyncRange e ' + e);  
}  
    
```    
  
    
### setSyncRange    
设置同步范围标签，使用Promise异步回调。  
 **调用形式：**     
    
- setSyncRange(localLabels: string[], remoteSupportLabels: string[]): Promise\<void>    
起始版本： 7  
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| localLabels | string[] | true | 表示本地设备的同步标签。   |  
| remoteSupportLabels | string[] | true | 表示要同步数据的设备的同步标签。   |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
let kvStore;  
try {  
    const localLabels = ['A', 'B'];  
    const remoteSupportLabels = ['C', 'D'];  
    kvStore.setSyncRange(localLabels, remoteSupportLabels, function (err,data) {  
        console.log('SetSyncRange put success');  
    });  
}catch(e) {  
    console.log('SetSyncRange e ' + e);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
let kvStore;  
try {  
    const localLabels = ['A', 'B'];  
    const remoteSupportLabels = ['C', 'D'];  
    kvStore.setSyncRange(localLabels, remoteSupportLabels).then((err) => {  
        console.log('setSyncRange success');  
    }).catch((err) => {  
        console.log('delete fail ' + err);  
    });  
}catch(e) {  
    console.log('SetSyncRange e ' + e);  
}  
    
```    
  
    
## SingleKVStore<sup>(deprecated)</sup>    
单版本数据库，继承自[KVStore](#kvstore)数据库，提供查询数据和同步数据的方法。  
  
单版本数据库，不对数据所属设备进行区分，不同设备使用相同键写入数据会互相覆盖。比如，可以使用单版本数据库实现个人日历、联系人数据在不同设备间的数据同步。  
  
在调用SingleKVStore的方法前，需要先通过[getKVStore](#getkvstore)构建一个SingleKVStore实例。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.SingleKVStore替代。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
### get<sup>(deprecated)</sup>    
获取指定键的值，使用callback异步回调。  
 **调用形式：**     
- get(key: string, callback: AsyncCallback\<Uint8Array | string | boolean | number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.SingleKVStore#get。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key<sup>(deprecated)</sup> | string | true | 要查询数据的key，不能为空且长度不大于[MAX_KEY_LENGTH](#constants)。   |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Uint8Array \| string \| boolean \| number> | true | 回调函数。返回获取查询的值。   |  
    
 **示例代码：**   
示例：  
```ts    
let kvStore;  
const KEY_TEST_STRING_ELEMENT = 'key_test_string';  
const VALUE_TEST_STRING_ELEMENT = 'value-test-string';  
try {  
    kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT, function (err,data) {  
        if (err != undefined) {  
            console.log("put err: " + JSON.stringify(err));  
            return;  
        }  
        console.log("put success");  
        kvStore.get(KEY_TEST_STRING_ELEMENT, function (err,data) {  
            console.log("get success data: " + data);  
        });  
    });  
}catch (e) {  
    console.log("An unexpected error occurred. Error:" + e);  
}  
    
```    
  
    
### get    
获取指定键的值，使用Promise异步回调。  
 **调用形式：**     
    
- get(key: string): Promise\<Uint8Array | string | boolean | number>    
起始版本： 7  
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key | string | true | 要查询数据的key，不能为空且长度不大于[MAX_KEY_LENGTH](#constants)。   |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回获取查询的值。 |  
| Promise<Uint8Array | string | boolean | number> | Promise对象。返回获取查询的值。 |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
let kvStore;  
const KEY_TEST_STRING_ELEMENT = 'key_test_string';  
const VALUE_TEST_STRING_ELEMENT = 'value-test-string';  
try {  
    kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT, function (err,data) {  
        if (err != undefined) {  
            console.log("put err: " + JSON.stringify(err));  
            return;  
        }  
        console.log("put success");  
        kvStore.get(KEY_TEST_STRING_ELEMENT, function (err,data) {  
            console.log("get success data: " + data);  
        });  
    });  
}catch (e) {  
    console.log("An unexpected error occurred. Error:" + e);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
  
```ts    
let kvStore;  
const KEY_TEST_STRING_ELEMENT = 'key_test_string';  
const VALUE_TEST_STRING_ELEMENT = 'value-test-string';  
try {  
    kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT).then((data) => {  
        console.log("put success: " + JSON.stringify(data));  
        kvStore.get(KEY_TEST_STRING_ELEMENT).then((data) => {  
            console.log("get success data: " + data);  
        }).catch((err) => {  
            console.log("get err: " + JSON.stringify(err));  
        });  
    }).catch((err) => {  
        console.log("put err: " + JSON.stringify(err));  
    });  
}catch (e) {  
    console.log("An unexpected error occurred. Error:" + e);  
}  
    
```    
  
    
### getEntries<sup>(deprecated)</sup>    
获取匹配指定键前缀的所有键值对，使用callback异步回调。  
 **调用形式：**     
- getEntries(keyPrefix: string, callback: AsyncCallback\<Entry[]>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.SingleKVStore#getEntries。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| keyPrefix<sup>(deprecated)</sup> | string | true | 表示要匹配的键前缀。   |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Entry[]> | true | 回调函数。返回匹配指定前缀的键值对列表。   |  
    
 **示例代码：**   
示例：  
```ts    
let kvStore;  
try {  
    let entries = [];  
    for (var i = 0; i < 10; i++) {  
        var key = 'batch_test_number_key';  
        var entry = {  
            key : key + i,  
            value : {  
                type : distributedData.ValueType.INTEGER,  
                value : 222  
            }  
        }  
        entries.push(entry);  
    }  
    kvStore.putBatch(entries, async function (err,data) {  
        console.log('putBatch success');  
        kvStore.getEntries('batch_test_number_key', function (err,entries) {  
            console.log('getEntries success');  
            console.log('entries.length: ' + entries.length);  
            console.log('entries[0]: ' + JSON.stringify(entries[0]));  
        });  
    });  
}catch(e) {  
    console.log('PutBatch e ' + e);  
}  
    
```    
  
    
### getEntries    
获取匹配指定键前缀的所有键值对  
 **调用形式：**     
    
- getEntries(keyPrefix: string): Promise\<Entry[]>    
起始版本： 7    
- getEntries(query: Query): Promise\<Entry[]>    
起始版本： 7  
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| keyPrefix | string | true | 表示要匹配的键前缀。   |  
| query | Query | true | 表示要匹配的键前缀。  。表示查询对象。   |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回匹配指定前缀的键值对列表。 |  
| Promise<Entry[]> | Promise对象。返回匹配指定前缀的键值对列表。 |  
    
 **示例代码1：**   
示例（callback）：参数为：keyPrefix  
```ts    
let kvStore;  
try {  
    let entries = [];  
    for (var i = 0; i < 10; i++) {  
        var key = 'batch_test_number_key';  
        var entry = {  
            key : key + i,  
            value : {  
                type : distributedData.ValueType.INTEGER,  
                value : 222  
            }  
        }  
        entries.push(entry);  
    }  
    kvStore.putBatch(entries, async function (err,data) {  
        console.log('putBatch success');  
        kvStore.getEntries('batch_test_number_key', function (err,entries) {  
            console.log('getEntries success');  
            console.log('entries.length: ' + entries.length);  
            console.log('entries[0]: ' + JSON.stringify(entries[0]));  
        });  
    });  
}catch(e) {  
    console.log('PutBatch e ' + e);  
}  
    
```    
  
    
 **示例代码2：**   
示例（callback）：参数为：query  
  
```ts    
let kvStore;  
try {  
    var arr = new Uint8Array([21,31]);  
    let entries = [];  
    for (var i = 0; i < 10; i++) {  
        var key = 'batch_test_bool_key';  
        var entry = {  
            key : key + i,  
            value : {  
                type : distributedData.ValueType.BYTE_ARRAY,  
                value : arr  
            }  
        }  
        entries.push(entry);  
    }  
    console.log('entries: ' + JSON.stringify(entries));  
    kvStore.putBatch(entries, async function (err,data) {  
        console.log('putBatch success');  
        const query = new distributedData.Query();  
        query.prefixKey("batch_test");  
        kvStore.getEntries(query, function (err,entries) {  
            console.log('getEntries success');  
            console.log('entries.length: ' + entries.length);  
            console.log('entries[0]: ' + JSON.stringify(entries[0]));  
        });  
    });  
    console.log('GetEntries success');  
}catch(e) {  
    console.log('GetEntries e ' + e);  
}  
    
```    
  
    
 **示例代码3：**   
示例（Promise）：参数为：keyPrefix  
  
```ts    
let kvStore;  
try {  
    let entries = [];  
    for (var i = 0; i < 10; i++) {  
        var key = 'batch_test_string_key';  
        var entry = {  
            key : key + i,  
            value : {  
                type : distributedData.ValueType.STRING,  
                value : 'batch_test_string_value'  
            }  
        }  
        entries.push(entry);  
    }  
    console.log('entries: ' + entries);  
    kvStore.putBatch(entries).then(async (err) => {  
        console.log('putBatch success');  
        kvStore.getEntries('batch_test_string_key').then((entries) => {  
            console.log('getEntries success');  
            console.log('entries.length: ' + entries.length);  
            console.log('entries[0]: ' + JSON.stringify(entries[0]));  
            console.log('entries[0].value: ' + JSON.stringify(entries[0].value));  
            console.log('entries[0].value.value: ' + entries[0].value.value);  
        }).catch((err) => {  
            console.log('getEntries fail ' + JSON.stringify(err));  
        });  
    }).catch((err) => {  
        console.log('putBatch fail ' + JSON.stringify(err));  
    });  
}catch(e) {  
    console.log('PutBatch e ' + e);  
}  
    
```    
  
    
 **示例代码4：**   
示例（Promise）：参数为：query  
  
```ts    
let kvStore;  
try {  
    var arr = new Uint8Array([21,31]);  
    let entries = [];  
    for (var i = 0; i < 10; i++) {  
        var key = 'batch_test_bool_key';  
        var entry = {  
            key : key + i,  
            value : {  
                type : distributedData.ValueType.BYTE_ARRAY,  
                value : arr  
            }  
        }  
        entries.push(entry);  
    }  
    console.log('entries: ' + JSON.stringify(entries));  
    kvStore.putBatch(entries).then(async (err) => {  
        console.log('putBatch success');  
        const query = new distributedData.Query();  
        query.prefixKey("batch_test");  
        kvStore.getEntries(query).then((entries) => {  
            console.log('getEntries success');  
        }).catch((err) => {  
            console.log('getEntries fail ' + JSON.stringify(err));  
        });  
    }).catch((err) => {  
        console.log('GetEntries putBatch fail ' + JSON.stringify(err))  
    });  
    console.log('GetEntries success');  
}catch(e) {  
    console.log('GetEntries e ' + e);  
}  
    
```    
  
    
### getEntries<sup>(deprecated)</sup>    
获取与指定Query对象匹配的键值对列表，使用callback异步回调。  
 **调用形式：**     
- getEntries(query: Query, callback: AsyncCallback\<Entry[]>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.SingleKVStore#getEntries。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| query<sup>(deprecated)</sup> | Query | true | 表示要匹配的键前缀。  。表示查询对象。   |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Entry[]> | true | 回调函数。返回与指定Query对象匹配的键值对列表。   |  
    
 **示例代码：**   
示例：  
```ts    
let kvStore;  
try {  
    var arr = new Uint8Array([21,31]);  
    let entries = [];  
    for (var i = 0; i < 10; i++) {  
        var key = 'batch_test_bool_key';  
        var entry = {  
            key : key + i,  
            value : {  
                type : distributedData.ValueType.BYTE_ARRAY,  
                value : arr  
            }  
        }  
        entries.push(entry);  
    }  
    console.log('entries: ' + JSON.stringify(entries));  
    kvStore.putBatch(entries, async function (err,data) {  
        console.log('putBatch success');  
        const query = new distributedData.Query();  
        query.prefixKey("batch_test");  
        kvStore.getEntries(query, function (err,entries) {  
            console.log('getEntries success');  
            console.log('entries.length: ' + entries.length);  
            console.log('entries[0]: ' + JSON.stringify(entries[0]));  
        });  
    });  
    console.log('GetEntries success');  
}catch(e) {  
    console.log('GetEntries e ' + e);  
}  
    
```    
  
    
### getResultSet<sup>(deprecated)</sup>    
从KvStore数据库中获取具有指定前缀的结果集。  
 **调用形式：**     
- getResultSet(keyPrefix: string, callback: AsyncCallback\<KvStoreResultSet>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.SingleKVStore#getResultSet。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| keyPrefix<sup>(deprecated)</sup> | string | true | 表示要匹配的键前缀。  |  
| callback<sup>(deprecated)</sup> | AsyncCallback<KvStoreResultSet> | true | 回调函数。返回具有指定前缀的结果集。  |  
    
 **示例代码：**   
示例：  
```ts    
let kvStore;  
try {  
    let resultSet;  
    let entries = [];  
    for (var i = 0; i < 10; i++) {  
        var key = 'batch_test_string_key';  
        var entry = {  
            key : key + i,  
            value : {  
                type : distributedData.ValueType.STRING,  
                value : 'batch_test_string_value'  
            }  
        }  
        entries.push(entry);  
    }  
    kvStore.putBatch(entries, async function (err, data) {  
        console.log('GetResultSet putBatch success');  
        kvStore.getResultSet('batch_test_string_key', async function (err, result) {  
            console.log('GetResultSet getResultSet succeed.');  
            resultSet = result;  
            kvStore.closeResultSet(resultSet, function (err, data) {  
                console.log('GetResultSet closeResultSet success');  
            })  
        });  
    });  
}catch(e) {  
    console.log('GetResultSet e ' + e);  
}  
    
```    
  
    
### getResultSet    
从KVStore数据库中获取具有指定前缀的结果集  
 **调用形式：**     
    
- getResultSet(keyPrefix: string): Promise\<KvStoreResultSet>    
起始版本： 7    
- getResultSet(query: Query): Promise\<KvStoreResultSet>    
起始版本： 7  
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| keyPrefix | string | true | 表示要匹配的键前缀。 |  
| query | Query | true | 表示查询对象。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，获取与指定Query对象匹配的KvStoreResultSet对象。 |  
| Promise<KvStoreResultSet> | Promise对象。返回具有指定前缀的结果集。 |  
    
 **示例代码1：**   
示例（callback）：参数为：keyPrefix  
```ts    
let kvStore;  
try {  
    let resultSet;  
    let entries = [];  
    for (var i = 0; i < 10; i++) {  
        var key = 'batch_test_string_key';  
        var entry = {  
            key : key + i,  
            value : {  
                type : distributedData.ValueType.STRING,  
                value : 'batch_test_string_value'  
            }  
        }  
        entries.push(entry);  
    }  
    kvStore.putBatch(entries, async function (err, data) {  
        console.log('GetResultSet putBatch success');  
        kvStore.getResultSet('batch_test_string_key', async function (err, result) {  
            console.log('GetResultSet getResultSet succeed.');  
            resultSet = result;  
            kvStore.closeResultSet(resultSet, function (err, data) {  
                console.log('GetResultSet closeResultSet success');  
            })  
        });  
    });  
}catch(e) {  
    console.log('GetResultSet e ' + e);  
}  
    
```    
  
    
 **示例代码2：**   
示例（callback）：参数为：query  
  
```ts    
let kvStore;  
try {  
    let resultSet;  
    let entries = [];  
    for (var i = 0; i < 10; i++) {  
        var key = 'batch_test_string_key';  
        var entry = {  
            key : key + i,  
            value : {  
                type : distributedData.ValueType.STRING,  
                value : 'batch_test_string_value'  
            }  
        }  
        entries.push(entry);  
    }  
    kvStore.putBatch(entries, async function (err, data) {  
        console.log('putBatch success');  
        const query = new distributedData.Query();  
        query.prefixKey("batch_test");  
        kvStore.getResultSet(query, async function (err, result) {  
            console.log('getResultSet succeed.');  
            resultSet = result;  
        });  
    });  
} catch(e) {  
    console.log('GetResultSet e ' + e);  
}  
    
```    
  
    
 **示例代码3：**   
示例（Promise）：参数为：keyPrefix  
  
```ts    
let kvStore;  
try {  
    let resultSet;  
    let entries = [];  
    for (var i = 0; i < 10; i++) {  
        var key = 'batch_test_string_key';  
        var entry = {  
            key : key + i,  
            value : {  
                type : distributedData.ValueType.STRING,  
                value : 'batch_test_string_value'  
            }  
        }  
        entries.push(entry);  
    }  
    kvStore.putBatch(entries).then(async (err) => {  
        console.log('putBatch success');  
    }).catch((err) => {  
        console.log('PutBatch putBatch fail ' + JSON.stringify(err));  
    });  
    kvStore.getResultSet('batch_test_string_key').then((result) => {  
        console.log('GetResult getResultSet succeed.');  
        resultSet = result;  
    }).catch((err) => {  
        console.log('getResultSet failed: ' + JSON.stringify(err));  
    });  
    kvStore.closeResultSet(resultSet).then((err) => {  
        console.log('GetResult closeResultSet success');  
    }).catch((err) => {  
        console.log('closeResultSet fail ' + JSON.stringify(err));  
    });  
}catch(e) {  
    console.log('GetResult e ' + e);  
}  
    
```    
  
    
 **示例代码4：**   
示例（Promise）：参数为：query  
  
```ts    
let kvStore;  
try {  
    let resultSet;  
    let entries = [];  
    for (var i = 0; i < 10; i++) {  
        var key = 'batch_test_string_key';  
        var entry = {  
            key : key + i,  
            value : {  
                type : distributedData.ValueType.STRING,  
                value : 'batch_test_string_value'  
            }  
        }  
        entries.push(entry);  
    }  
    kvStore.putBatch(entries).then(async (err) => {  
        console.log('putBatch success');  
    }).catch((err) => {  
        console.log('putBatch fail ' + JSON.stringify(err));  
    });  
    const query = new distributedData.Query();  
    query.prefixKey("batch_test");  
    kvStore.getResultSet(query).then((result) => {  
        console.log(' getResultSet succeed.');  
        resultSet = result;  
    }).catch((err) => {  
        console.log('getResultSet failed: ' + JSON.stringify(err));  
    });  
}catch(e) {  
    console.log('GetResultSet e ' + e);  
}  
    
```    
  
    
### getResultSet<sup>(deprecated)</sup>    
获取与指定Query对象匹配的KvStoreResultSet对象，使用callback异步回调。  
 **调用形式：**     
- getResultSet(query: Query, callback: AsyncCallback\<KvStoreResultSet>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.SingleKVStore#getResultSet。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| query<sup>(deprecated)</sup> | Query | true | 表示查询对象。              |  
| callback<sup>(deprecated)</sup> | AsyncCallback<KvStoreResultSet> | true | 回调函数，获取与指定Query对象匹配的KvStoreResultSet对象。 。 |  
    
 **示例代码：**   
示例：  
```ts    
let kvStore;  
try {  
    let resultSet;  
    let entries = [];  
    for (var i = 0; i < 10; i++) {  
        var key = 'batch_test_string_key';  
        var entry = {  
            key : key + i,  
            value : {  
                type : distributedData.ValueType.STRING,  
                value : 'batch_test_string_value'  
            }  
        }  
        entries.push(entry);  
    }  
    kvStore.putBatch(entries, async function (err, data) {  
        console.log('putBatch success');  
        const query = new distributedData.Query();  
        query.prefixKey("batch_test");  
        kvStore.getResultSet(query, async function (err, result) {  
            console.log('getResultSet succeed.');  
            resultSet = result;  
        });  
    });  
} catch(e) {  
    console.log('GetResultSet e ' + e);  
}  
    
```    
  
    
### closeResultSet<sup>(deprecated)</sup>    
关闭由[SingleKvStore.getResultSet](#singlekvstore_getresultset)返回的KvStoreResultSet对象，使用callback异步回调。  
 **调用形式：**     
- closeResultSet(resultSet: KvStoreResultSet, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.SingleKVStore#closeResultSet。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| resultSet<sup>(deprecated)</sup> | KvStoreResultSet | true | 表示要关闭的KvStoreResultSet对象。              |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。              |  
    
 **示例代码：**   
示例：  
```ts    
let kvStore;  
try {  
    let resultSet = null;  
    kvStore.closeResultSet(resultSet, function (err, data) {  
        if (err == undefined) {  
            console.log('closeResultSet success');  
        } else {  
            console.log('closeResultSet fail');  
        }  
    });  
}catch(e) {  
    console.log('CloseResultSet e ' + e);  
}  
    
```    
  
    
### closeResultSet    
关闭由[SingleKvStore.getResultSet](#singlekvstore_getresultset)返回的KvStoreResultSet对象  
 **调用形式：**     
    
- closeResultSet(resultSet: KvStoreResultSet): Promise\<void>    
起始版本： 7  
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| resultSet | KvStoreResultSet | true | 表示要关闭的KvStoreResultSet对象。              |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
let kvStore;  
try {  
    let resultSet = null;  
    kvStore.closeResultSet(resultSet, function (err, data) {  
        if (err == undefined) {  
            console.log('closeResultSet success');  
        } else {  
            console.log('closeResultSet fail');  
        }  
    });  
}catch(e) {  
    console.log('CloseResultSet e ' + e);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
let kvStore;  
try {  
    let resultSet = null;  
    kvStore.closeResultSet(resultSet).then(() => {  
        console.log('closeResultSet success');  
    }).catch((err) => {  
        console.log('closeResultSet fail ' + JSON.stringify(err));  
    });  
}catch(e) {  
    console.log('CloseResultSet e ' + e);  
}  
    
```    
  
    
### getResultSize<sup>(deprecated)</sup>    
获取与指定Query对象匹配的结果数，使用callback异步回调。  
 **调用形式：**     
- getResultSize(query: Query, callback: AsyncCallback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.SingleKVStore#getResultSize。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| query<sup>(deprecated)</sup> | Query | true | 表示查询对象。          |  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true | 回调函数。返回与指定Query对象匹配的结果数。          |  
    
 **示例代码：**   
示例：  
```ts    
let kvStore;  
try {  
    let entries = [];  
    for (var i = 0; i < 10; i++) {  
        var key = 'batch_test_string_key';  
        var entry = {  
            key : key + i,  
            value : {  
                type : distributedData.ValueType.STRING,  
                value : 'batch_test_string_value'  
            }  
        }  
        entries.push(entry);  
    }  
    kvStore.putBatch(entries, async function (err, data) {  
        console.log('putBatch success');  
        const query = new distributedData.Query();  
        query.prefixKey("batch_test");  
        kvStore.getResultSize(query, async function (err, resultSize) {  
            console.log('getResultSet succeed.');  
        });  
    });  
} catch(e) {  
    console.log('GetResultSize e ' + e);  
}  
    
```    
  
    
### getResultSize    
获取与指定Query对象匹配的结果数，使用Promise异步回调。  
 **调用形式：**     
    
- getResultSize(query: Query): Promise\<number>    
起始版本： 7  
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| query | Query | true | 表示查询对象。          |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回与指定Query对象匹配的结果数。 |  
| Promise<number> | Promise对象。获取与指定Query对象匹配的结果数。 |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
let kvStore;  
try {  
    let entries = [];  
    for (var i = 0; i < 10; i++) {  
        var key = 'batch_test_string_key';  
        var entry = {  
            key : key + i,  
            value : {  
                type : distributedData.ValueType.STRING,  
                value : 'batch_test_string_value'  
            }  
        }  
        entries.push(entry);  
    }  
    kvStore.putBatch(entries, async function (err, data) {  
        console.log('putBatch success');  
        const query = new distributedData.Query();  
        query.prefixKey("batch_test");  
        kvStore.getResultSize(query, async function (err, resultSize) {  
            console.log('getResultSet succeed.');  
        });  
    });  
} catch(e) {  
    console.log('GetResultSize e ' + e);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
let kvStore;  
try {  
    let entries = [];  
    for (var i = 0; i < 10; i++) {  
        var key = 'batch_test_string_key';  
        var entry = {  
            key : key + i,  
            value : {  
                type : distributedData.ValueType.STRING,  
                value : 'batch_test_string_value'  
            }  
        }  
        entries.push(entry);  
    }  
    kvStore.putBatch(entries).then(async (err) => {  
        console.log('putBatch success');  
    }).catch((err) => {  
        console.log('putBatch fail ' + JSON.stringify(err));  
    });  
    const query = new distributedData.Query();  
    query.prefixKey("batch_test");  
    kvStore.getResultSize(query).then((resultSize) => {  
        console.log('getResultSet succeed.');  
    }).catch((err) => {  
        console.log('getResultSet failed: ' + JSON.stringify(err));  
    });  
}catch(e) {  
    console.log('GetResultSize e ' + e);  
}  
    
```    
  
    
### removeDeviceData<sup>(deprecated)</sup>    
删除指定设备的数据，使用callback异步回调。  
 **调用形式：**     
- removeDeviceData(deviceId: string, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.SingleKVStore#removeDeviceData。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId<sup>(deprecated)</sup> | string | true | 表示要删除设备的名称。        |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。       |  
    
 **示例代码：**   
示例：  
```ts    
let kvStore;  
const KEY_TEST_STRING_ELEMENT = 'key_test_string_2';  
const VALUE_TEST_STRING_ELEMENT = 'value-string-002';  
try {  
    kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT, async function (err,data) {  
        console.log('put success');  
        const deviceid = 'no_exist_device_id';  
        kvStore.removeDeviceData(deviceid, async function (err,data) {  
            if (err == undefined) {  
                console.log('removeDeviceData success');  
            } else {  
                console.log('removeDeviceData fail');  
                kvStore.get(KEY_TEST_STRING_ELEMENT, async function (err,data) {  
                    console.log('RemoveDeviceData get success');  
                });  
            }  
        });  
    });  
}catch(e) {  
    console.log('RemoveDeviceData e ' + e);  
}  
    
```    
  
    
### removeDeviceData    
删除指定设备的数据  
 **调用形式：**     
    
- removeDeviceData(deviceId: string): Promise\<void>    
起始版本： 7  
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId | string | true | 表示要删除设备的名称。        |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
let kvStore;  
const KEY_TEST_STRING_ELEMENT = 'key_test_string_2';  
const VALUE_TEST_STRING_ELEMENT = 'value-string-002';  
try {  
    kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT, async function (err,data) {  
        console.log('put success');  
        const deviceid = 'no_exist_device_id';  
        kvStore.removeDeviceData(deviceid, async function (err,data) {  
            if (err == undefined) {  
                console.log('removeDeviceData success');  
            } else {  
                console.log('removeDeviceData fail');  
                kvStore.get(KEY_TEST_STRING_ELEMENT, async function (err,data) {  
                    console.log('RemoveDeviceData get success');  
                });  
            }  
        });  
    });  
}catch(e) {  
    console.log('RemoveDeviceData e ' + e);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
let kvStore;  
const KEY_TEST_STRING_ELEMENT = 'key_test_string_2';  
const VALUE_TEST_STRING_ELEMENT = 'value-string-001';  
try {  
    kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT).then((err) => {  
        console.log('removeDeviceData put success');  
    }).catch((err) => {  
        console.log('put fail ' + JSON.stringify(err));  
    });  
    const deviceid = 'no_exist_device_id';  
    kvStore.removeDeviceData(deviceid).then((err) => {  
        console.log('removeDeviceData success');  
    }).catch((err) => {  
        console.log('removeDeviceData fail ' + JSON.stringify(err));  
    });  
    kvStore.get(KEY_TEST_STRING_ELEMENT).then((data) => {  
        console.log('get success data:' + data);  
    }).catch((err) => {  
        console.log('RemoveDeviceData get fail ' + JSON.stringify(err));  
    });  
}catch(e) {  
    console.log('RemoveDeviceData e ' + e);  
}  
    
```    
  
    
### sync<sup>(deprecated)</sup>    
在手动同步方式下，触发数据库同步。  
 **调用形式：**     
- sync(deviceIds: string[], mode: SyncMode, delayMs?: number): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.SingleKVStore#sync。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core  
 **需要权限：** ohos.permission.DISTRIBUTED_DATASYNC    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceIds<sup>(deprecated)</sup> | string[] | true | 同一组网环境下，需要同步的设备的networkId列表。  |  
| mode<sup>(deprecated)</sup> | SyncMode | true | 同步模式。                                      |  
| delayMs<sup>(deprecated)</sup> | number | false | 可选参数，允许延时时间，单位：ms（毫秒），默认为0。      |  
    
 **示例代码：**   
示例：  
```ts    
import deviceManager from '@ohos.distributedHardware.deviceManager';  
  
let devManager;  
let kvStore;  
const KEY_TEST_SYNC_ELEMENT = 'key_test_sync';  
const VALUE_TEST_SYNC_ELEMENT = 'value-string-001';  
// create deviceManager  
deviceManager.createDeviceManager('bundleName', (err, value) => {  
  if (!err) {  
    devManager = value;  
    let deviceIds = [];  
    if (devManager != null) {  
      var devices = devManager.getTrustedDeviceListSync();  
      for (var i = 0; i < devices.length; i++) {  
        deviceIds[i] = devices[i].networkId;  
      }  
    }  
    try {  
      kvStore.on('syncComplete', function (data) {  
        console.log('Sync dataChange');  
      });  
      kvStore.put(KEY_TEST_SYNC_ELEMENT + 'testSync101', VALUE_TEST_SYNC_ELEMENT, function (err, data) {  
        if (err != undefined) {  
          console.log("put err: " + JSON.stringify(err));  
          return;  
        }  
        console.log('Succeeded in putting data');  
        const mode = distributedData.SyncMode.PULL_ONLY;  
        kvStore.sync(deviceIds, mode, 1000);  
      });  
    } catch (e) {  
      console.log('Sync e' + e);  
    }  
  }  
});  
    
```    
  
    
### on('dataChange')<sup>(deprecated)</sup>    
订阅指定类型的数据变更通知。  
 **调用形式：**     
- on(event: 'dataChange', type: SubscribeType, listener: Callback\<ChangeNotification>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.SingleKVStore#on。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event<sup>(deprecated)</sup> | string | true | 订阅的事件名，固定为'dataChange'，表示数据变更事件。  |  
| type<sup>(deprecated)</sup> | SubscribeType | true | 表示订阅的类型。                                      |  
| listener<sup>(deprecated)</sup> | Callback<ChangeNotification> | true | 回调函数。                                            |  
    
 **示例代码：**   
示例：  
```ts    
let kvStore;  
kvStore.on('dataChange', distributedData.SubscribeType.SUBSCRIBE_TYPE_LOCAL, function (data) {  
    console.log("dataChange callback call data: " + JSON.stringify(data));  
});    
```    
  
    
### on('syncComplete')<sup>(deprecated)</sup>    
订阅同步完成事件回调通知。  
 **调用形式：**     
- on(event: 'syncComplete', syncCallback: Callback\<Array\<[string, number]>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.SingleKVStore#on。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event<sup>(deprecated)</sup> | string | true | 订阅的事件名，固定为'syncComplete'，表示同步完成事件。 |  
| syncCallback<sup>(deprecated)</sup> | Callback<Array<[string, number]>> | true | 回调函数。用于向调用方发送同步结果的回调。              |  
    
 **示例代码：**   
示例：  
```ts    
let kvStore;  
const KEY_TEST_FLOAT_ELEMENT = 'key_test_float';  
const VALUE_TEST_FLOAT_ELEMENT = 321.12;  
try {  
    kvStore.on('syncComplete', function (data) {  
        console.log('syncComplete ' + data)  
    });  
    kvStore.put(KEY_TEST_FLOAT_ELEMENT, VALUE_TEST_FLOAT_ELEMENT).then((data) => {  
        console.log('syncComplete put success');  
    }).catch((error) => {  
        console.log('syncComplete put fail ' + error);  
    });  
}catch(e) {  
    console.log('syncComplete put e ' + e);  
}  
    
```    
  
    
### off('dataChange')<sup>(deprecated)</sup>    
取消订阅数据变更通知。  
 **调用形式：**     
- off(event: 'dataChange', listener?: Callback\<ChangeNotification>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.SingleKVStore#off。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event<sup>(deprecated)</sup> | string | true | 取消订阅的事件名，固定为'dataChange'，表示数据变更事件。  |  
| listener<sup>(deprecated)</sup> | Callback<ChangeNotification> | false | 取消订阅的函数。如不设置callback，则取消所有订阅的函数。  |  
    
 **示例代码：**   
示例：  
```ts    
let kvStore;  
class KvstoreModel {  
    call(data) {  
        console.log("dataChange: " + data);  
    }  
    subscribeDataChange() {  
        if (kvStore != null) {  
            kvStore.on('dataChange', distributedData.SubscribeType.SUBSCRIBE_TYPE_REMOTE, this.call);  
        }  
    }  
    unsubscribeDataChange() {  
        if (kvStore != null) {  
            kvStore.off('dataChange', this.call);  
        }  
    }  
}  
    
```    
  
    
### off('syncComplete')<sup>(deprecated)</sup>    
取消订阅同步完成事件回调通知。  
 **调用形式：**     
- off(event: 'syncComplete', syncCallback?: Callback\<Array\<[string, number]>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.SingleKVStore#off。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event<sup>(deprecated)</sup> | string | true | 取消订阅的事件名，固定为'syncComplete'，表示同步完成事件。 |  
| syncCallback<sup>(deprecated)</sup> | Callback<Array<[string, number]>> | false | 取消订阅的函数。如不设置callback，则取消所有订阅的函数。 |  
    
 **示例代码：**   
示例：  
```ts    
let kvStore;  
class KvstoreModel {  
    call(data) {  
        console.log("syncComplete: " + data);  
    }  
    subscribeSyncComplete() {  
        if (kvStore != null) {  
            kvStore.on('syncComplete', this.call);  
        }  
    }  
    unsubscribeSyncComplete() {  
        if (kvStore != null) {  
            kvStore.off('syncComplete', this.call);  
        }  
    }  
}  
    
```    
  
    
### setSyncParam<sup>(deprecated)</sup>    
设置数据库同步允许的默认延迟，使用callback异步回调。  
 **调用形式：**     
- setSyncParam(defaultAllowedDelayMs: number, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.SingleKVStore#setSyncParam。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| defaultAllowedDelayMs<sup>(deprecated)</sup> | number | true | 表示数据库同步允许的默认延迟，以毫秒为单位。     |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。    |  
    
 **示例代码：**   
示例：  
```ts    
let kvStore;  
try {  
    const defaultAllowedDelayMs = 500;  
    kvStore.setSyncParam(defaultAllowedDelayMs, function (err,data) {  
        console.log('SetSyncParam put success');  
    });  
}catch(e) {  
    console.log('testSingleKvStoreSetSyncParam e ' + e);  
}  
    
```    
  
    
### setSyncParam    
设置数据库同步允许的默认延迟  
 **调用形式：**     
    
- setSyncParam(defaultAllowedDelayMs: number): Promise\<void>    
起始版本： 7  
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| defaultAllowedDelayMs | number | true | 表示数据库同步允许的默认延迟，以毫秒为单位。     |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
let kvStore;  
try {  
    const defaultAllowedDelayMs = 500;  
    kvStore.setSyncParam(defaultAllowedDelayMs, function (err,data) {  
        console.log('SetSyncParam put success');  
    });  
}catch(e) {  
    console.log('testSingleKvStoreSetSyncParam e ' + e);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
let kvStore;  
try {  
    const defaultAllowedDelayMs = 500;  
    kvStore.setSyncParam(defaultAllowedDelayMs).then((err) => {  
        console.log('SetSyncParam put success');  
    }).catch((err) => {  
        console.log('SetSyncParam put fail ' + JSON.stringify(err));  
    });  
}catch(e) {  
    console.log('SetSyncParam e ' + e);  
}  
    
```    
  
    
### getSecurityLevel<sup>(deprecated)</sup>    
获取数据库的安全级别，使用callback异步回调。  
 **调用形式：**     
- getSecurityLevel(callback: AsyncCallback\<SecurityLevel>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.SingleKVStore#getSecurityLevel。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<SecurityLevel> | true | 回调函数。返回数据库的安全级别。     |  
    
 **示例代码：**   
示例：  
```ts    
let kvStore;  
try {  
    kvStore.getSecurityLevel(function (err,data) {  
        console.log('getSecurityLevel success');  
    });  
}catch(e) {  
    console.log('GetSecurityLevel e ' + e);  
}  
    
```    
  
    
### getSecurityLevel    
获取数据库的安全级别，使用Promise异步回调。  
 **调用形式：**     
    
- getSecurityLevel(): Promise\<SecurityLevel>    
起始版本： 7  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回数据库的安全级别。 |  
| Promise<SecurityLevel> | Promise对象。返回数据库的安全级别。 |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
let kvStore;  
try {  
    kvStore.getSecurityLevel(function (err,data) {  
        console.log('getSecurityLevel success');  
    });  
}catch(e) {  
    console.log('GetSecurityLevel e ' + e);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
let kvStore;  
try {  
    kvStore.getSecurityLevel().then((data) => {  
        console.log(' getSecurityLevel success');  
    }).catch((err) => {  
        console.log('getSecurityLevel fail ' + JSON.stringify(err));  
    });  
}catch(e) {  
    console.log('GetSecurityLevel e ' + e);  
}  
    
```    
  
    
## DeviceKVStore<sup>(deprecated)</sup>    
设备协同数据库，继承自KVStore，提供查询数据和同步数据的方法。  
  
设备协同数据库，以设备维度对数据进行区分，每台设备仅能写入和修改本设备的数据，其它设备的数据对其是只读的，无法修改其它设备的数据。  
  
比如，可以使用设备协同数据库实现设备间的图片分享，可以查看其他设备的图片，但无法修改和删除其他设备的图片。  
  
在调用DeviceKVStore的方法前，需要先通过[getKVStore](#getkvstore)构建一个DeviceKVStore实例。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.DeviceKVStore替代。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.DistributedKVStore    
### get<sup>(deprecated)</sup>    
获取与指定设备ID和key匹配的string值，使用callback异步回调。  
 **调用形式：**     
- get(deviceId: string, key: string, callback: AsyncCallback\<boolean | string | number | Uint8Array>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.DeviceKVStore#get。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.DistributedKVStore    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId<sup>(deprecated)</sup> | string | true | 标识要查询其数据的设备。     |  
| key<sup>(deprecated)</sup> | string | true | 表示要查询key值的键。     |  
| callback<sup>(deprecated)</sup> | AsyncCallback<boolean \| string \| number \| Uint8Array> | true | 回调函数，返回匹配给定条件的字符串值。     |  
    
 **示例代码：**   
示例：  
```ts    
let kvStore;  
const KEY_TEST_STRING_ELEMENT = 'key_test_string_2';  
const VALUE_TEST_STRING_ELEMENT = 'value-string-002';  
try{  
    kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT, async function (err,data) {  
        console.log('put success');  
        kvStore.get('localDeviceId', KEY_TEST_STRING_ELEMENT, function (err,data) {  
            console.log('get success');  
        });  
    })  
}catch(e) {  
    console.log('get e' + e);  
}    
```    
  
    
### get    
获取与指定设备ID和key匹配的string值  
 **调用形式：**     
    
- get(deviceId: string, key: string): Promise\<boolean | string | number | Uint8Array>    
起始版本： 7  
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId | string | true | 标识要查询其数据的设备。     |  
| key | string | true | 表示要查询key值的键。     |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回匹配给定条件的字符串值。 |  
| Promise<boolean | string | number | Uint8Array> | Promise对象。返回匹配给定条件的字符串值。 |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
let kvStore;  
const KEY_TEST_STRING_ELEMENT = 'key_test_string_2';  
const VALUE_TEST_STRING_ELEMENT = 'value-string-002';  
try{  
    kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT, async function (err,data) {  
        console.log('put success');  
        kvStore.get('localDeviceId', KEY_TEST_STRING_ELEMENT, function (err,data) {  
            console.log('get success');  
        });  
    })  
}catch(e) {  
    console.log('get e' + e);  
}    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
let kvStore;  
const KEY_TEST_STRING_ELEMENT = 'key_test_string_2';  
const VALUE_TEST_STRING_ELEMENT = 'value-string-002';  
try {  
    kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT).then(async (data) => {  
        console.log(' put success');  
        kvStore.get('localDeviceId', KEY_TEST_STRING_ELEMENT).then((data) => {  
            console.log('get success');  
        }).catch((err) => {  
            console.log('get fail ' + JSON.stringify(err));  
        });  
    }).catch((error) => {  
        console.log('put error' + error);  
    });  
} catch (e) {  
    console.log('Get e ' + e);  
}  
    
```    
  
    
### getEntries<sup>(deprecated)</sup>    
获取与指定设备ID和key前缀匹配的所有键值对，使用callback异步回调。  
 **调用形式：**     
- getEntries(deviceId: string, keyPrefix: string, callback: AsyncCallback\<Entry[]>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.DeviceKVStore#getEntries。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.DistributedKVStore    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId<sup>(deprecated)</sup> | string | true | 标识要查询其数据的设备。     |  
| keyPrefix<sup>(deprecated)</sup> | string | true | 表示要匹配的键前缀。     |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Entry[]> | true | 回调函数，返回满足给定条件的所有键值对的列表。     |  
    
 **示例代码：**   
示例：  
```ts    
let kvStore;  
try {  
    let entries = [];  
    for (var i = 0; i < 10; i++) {  
        var key = 'batch_test_string_key';  
        var entry = {  
            key : key + i,  
            value : {  
                type : distributedData.ValueType.STRING,  
                value : 'batch_test_string_value'  
            }  
        }  
        entries.push(entry);  
    }  
    console.log('entries: ' + entries);  
    kvStore.putBatch(entries, async function (err,data) {  
        console.log('putBatch success');  
        kvStore.getEntries('localDeviceId', 'batch_test_string_key', function (err,entries) {  
            console.log('getEntries success');  
            console.log('entries.length: ' + entries.length);  
            console.log('entries[0]: ' + JSON.stringify(entries[0]));  
        });  
    });  
}catch(e) {  
    console.log('PutBatch e ' + e);  
}  
    
```    
  
    
### getEntries    
获取与指定设备ID和key前缀匹配的所有键值对  
 **调用形式：**     
    
- getEntries(deviceId: string, keyPrefix: string): Promise\<Entry[]>    
起始版本： 7    
- getEntries(query: Query): Promise\<Entry[]>    
起始版本： 7    
- getEntries(deviceId: string, query: Query): Promise\<Entry[]>    
起始版本： 7  
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId | string | true | 标识要查询其数据的设备。     |  
| keyPrefix | string | true | 表示要匹配的键前缀。     |  
| query | Query | true | 表示查询对象。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回满足给定条件的所有键值对的列表。 |  
| Promise<Entry[]> | Promise对象。返回匹配给定条件的所有键值对的列表。 |  
    
 **示例代码1：**   
示例（callback）：参数为：deviceId、keyPrefix  
```ts    
let kvStore;  
try {  
    let entries = [];  
    for (var i = 0; i < 10; i++) {  
        var key = 'batch_test_string_key';  
        var entry = {  
            key : key + i,  
            value : {  
                type : distributedData.ValueType.STRING,  
                value : 'batch_test_string_value'  
            }  
        }  
        entries.push(entry);  
    }  
    console.log('entries: ' + entries);  
    kvStore.putBatch(entries, async function (err,data) {  
        console.log('putBatch success');  
        kvStore.getEntries('localDeviceId', 'batch_test_string_key', function (err,entries) {  
            console.log('getEntries success');  
            console.log('entries.length: ' + entries.length);  
            console.log('entries[0]: ' + JSON.stringify(entries[0]));  
        });  
    });  
}catch(e) {  
    console.log('PutBatch e ' + e);  
}  
    
```    
  
    
 **示例代码2：**   
示例（callback）：参数为：query  
  
```ts    
let kvStore;  
try {  
    var arr = new Uint8Array([21,31]);  
    let entries = [];  
    for (var i = 0; i < 10; i++) {  
        var key = 'batch_test_bool_key';  
        var entry = {  
            key : key + i,  
            value : {  
                type : distributedData.ValueType.BYTE_ARRAY,  
                value : arr  
            }  
        }  
        entries.push(entry);  
    }  
    console.log('entries: ' + JSON.stringify(entries));  
    kvStore.putBatch(entries, async function (err,data) {  
        console.log('putBatch success');  
        const query = new distributedData.Query();  
        query.prefixKey("batch_test");  
        query.deviceId('localDeviceId');  
        kvStore.getEntries(query, function (err,entries) {  
            console.log('getEntries success');  
            console.log('entries.length: ' + entries.length);  
            console.log('entries[0]: ' + JSON.stringify(entries[0]));  
        });  
    });  
    console.log('GetEntries success');  
}catch(e) {  
    console.log('GetEntries e ' + e);  
}  
    
```    
  
    
 **示例代码3：**   
示例（callback）：参数为：deviceId、query  
  
```ts    
let kvStore;  
try {  
    var arr = new Uint8Array([21,31]);  
    let entries = [];  
    for (var i = 0; i < 10; i++) {  
        var key = 'batch_test_bool_key';  
        var entry = {  
            key : key + i,  
            value : {  
                type : distributedData.ValueType.BYTE_ARRAY,  
                value : arr  
            }  
        }  
        entries.push(entry);  
    }  
    console.log('entries: ' + JSON.stringify(entries));  
    kvStore.putBatch(entries, async function (err,data) {  
        console.log('putBatch success');  
        var query = new distributedData.Query();  
        query.deviceId('localDeviceId');  
        query.prefixKey("batch_test");  
        kvStore.getEntries('localDeviceId', query, function (err,entries) {  
            console.log('getEntries success');  
            console.log('entries.length: ' + entries.length);  
            console.log('entries[0]: ' + JSON.stringify(entries[0]));  
        })  
    });  
    console.log('GetEntries success');  
}catch(e) {  
    console.log('GetEntries e ' + e);  
}  
    
```    
  
    
 **示例代码4：**   
示例（Promise）：参数为：deviceId、keyPrefix  
  
```ts    
let kvStore;  
try {  
    let entries = [];  
    for (var i = 0; i < 10; i++) {  
        var key = 'batch_test_string_key';  
        var entry = {  
            key : key + i,  
            value : {  
                type : distributedData.ValueType.STRING,  
                value : 'batch_test_string_value'  
            }  
        }  
        entries.push(entry);  
    }  
    console.log('entries: ' + entries);  
    kvStore.putBatch(entries).then(async (err) => {  
        console.log('putBatch success');  
        kvStore.getEntries('localDeviceId', 'batch_test_string_key').then((entries) => {  
            console.log('getEntries success');  
            console.log('entries.length: ' + entries.length);  
            console.log('entries[0]: ' + JSON.stringify(entries[0]));  
            console.log('entries[0].value: ' + JSON.stringify(entries[0].value));  
            console.log('entries[0].value.value: ' + entries[0].value.value);  
        }).catch((err) => {  
            console.log('getEntries fail ' + JSON.stringify(err));  
        });  
    }).catch((err) => {  
        console.log('putBatch fail ' + JSON.stringify(err));  
    });  
}catch(e) {  
    console.log('PutBatch e ' + e);  
}  
    
```    
  
    
 **示例代码5：**   
示例（Promise）：参数为：query  
  
```ts    
let kvStore;  
try {  
    var arr = new Uint8Array([21,31]);  
    let entries = [];  
    for (var i = 0; i < 10; i++) {  
        var key = 'batch_test_bool_key';  
        var entry = {  
            key : key + i,  
            value : {  
                type : distributedData.ValueType.BYTE_ARRAY,  
                value : arr  
            }  
        }  
        entries.push(entry);  
    }  
    console.log('entries: ' + JSON.stringify(entries));  
    kvStore.putBatch(entries).then(async (err) => {  
        console.log('putBatch success');  
        const query = new distributedData.Query();  
        query.prefixKey("batch_test");  
        kvStore.getEntries(query).then((entries) => {  
            console.log('getEntries success');  
        }).catch((err) => {  
            console.log('getEntries fail ' + JSON.stringify(err));  
        });  
    }).catch((err) => {  
        console.log('GetEntries putBatch fail ' + JSON.stringify(err))  
    });  
    console.log('GetEntries success');  
}catch(e) {  
    console.log('GetEntries e ' + e);  
}  
    
```    
  
    
 **示例代码6：**   
示例（Promise）：参数为：deviceId、query  
  
```ts    
let kvStore;  
try {  
    var arr = new Uint8Array([21,31]);  
    let entries = [];  
    for (var i = 0; i < 10; i++) {  
        var key = 'batch_test_bool_key';  
        var entry = {  
            key : key + i,  
            value : {  
                type : distributedData.ValueType.BYTE_ARRAY,  
                value : arr  
            }  
        }  
        entries.push(entry);  
    }  
    console.log('entries: ' + JSON.stringify(entries));  
    kvStore.putBatch(entries).then(async (err) => {  
        console.log('putBatch success');  
        var query = new distributedData.Query();  
        query.deviceId('localDeviceId');  
        query.prefixKey("batch_test");  
        kvStore.getEntries('localDeviceId', query).then((entries) => {  
            console.log('getEntries success');  
        }).catch((err) => {  
            console.log('getEntries fail ' + JSON.stringify(err));  
        });  
    }).catch((err) => {  
        console.log('putBatch fail ' + JSON.stringify(err));  
    });  
    console.log('GetEntries success');  
}catch(e) {  
    console.log('GetEntries e ' + e);  
}  
    
```    
  
    
### getEntries<sup>(deprecated)</sup>    
获取与指定Query对象匹配的键值对列表，使用callback异步回调。  
 **调用形式：**     
- getEntries(query: Query, callback: AsyncCallback\<Entry[]>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.DeviceKVStore#getEntries。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.DistributedKVStore    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| query<sup>(deprecated)</sup> | Query | true | 表示查询对象。     |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Entry[]> | true | 回调函数，返回与指定Query对象匹配的键值对列表。     |  
    
 **示例代码：**   
示例：  
```ts    
let kvStore;  
try {  
    var arr = new Uint8Array([21,31]);  
    let entries = [];  
    for (var i = 0; i < 10; i++) {  
        var key = 'batch_test_bool_key';  
        var entry = {  
            key : key + i,  
            value : {  
                type : distributedData.ValueType.BYTE_ARRAY,  
                value : arr  
            }  
        }  
        entries.push(entry);  
    }  
    console.log('entries: ' + JSON.stringify(entries));  
    kvStore.putBatch(entries, async function (err,data) {  
        console.log('putBatch success');  
        const query = new distributedData.Query();  
        query.prefixKey("batch_test");  
        query.deviceId('localDeviceId');  
        kvStore.getEntries(query, function (err,entries) {  
            console.log('getEntries success');  
            console.log('entries.length: ' + entries.length);  
            console.log('entries[0]: ' + JSON.stringify(entries[0]));  
        });  
    });  
    console.log('GetEntries success');  
}catch(e) {  
    console.log('GetEntries e ' + e);  
}  
    
```    
  
    
### getEntries<sup>(deprecated)</sup>    
获取与指定设备ID和Query对象匹配的键值对列表，使用callback异步回调。  
 **调用形式：**     
- getEntries(deviceId: string, query: Query, callback: AsyncCallback\<Entry[]>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.DeviceKVStore#getEntries。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.DistributedKVStore    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId<sup>(deprecated)</sup> | string | true | 键值对所属的设备ID。     |  
| query<sup>(deprecated)</sup> | Query | true | 表示查询对象。     |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Entry[]> | true | 回调函数。返回与指定设备ID和Query对象匹配的键值对列表。     |  
    
 **示例代码：**   
示例：  
```ts    
let kvStore;  
try {  
    var arr = new Uint8Array([21,31]);  
    let entries = [];  
    for (var i = 0; i < 10; i++) {  
        var key = 'batch_test_bool_key';  
        var entry = {  
            key : key + i,  
            value : {  
                type : distributedData.ValueType.BYTE_ARRAY,  
                value : arr  
            }  
        }  
        entries.push(entry);  
    }  
    console.log('entries: ' + JSON.stringify(entries));  
    kvStore.putBatch(entries, async function (err,data) {  
        console.log('putBatch success');  
        var query = new distributedData.Query();  
        query.deviceId('localDeviceId');  
        query.prefixKey("batch_test");  
        kvStore.getEntries('localDeviceId', query, function (err,entries) {  
            console.log('getEntries success');  
            console.log('entries.length: ' + entries.length);  
            console.log('entries[0]: ' + JSON.stringify(entries[0]));  
        })  
    });  
    console.log('GetEntries success');  
}catch(e) {  
    console.log('GetEntries e ' + e);  
}  
    
```    
  
    
### getResultSet<sup>(deprecated)</sup>    
获取与指定设备ID和key前缀匹配的KvStoreResultSet对象，使用callback异步回调。  
 **调用形式：**     
- getResultSet(deviceId: string, keyPrefix: string, callback: AsyncCallback\<KvStoreResultSet>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.DeviceKVStore#getResultSet。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.DistributedKVStore    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId<sup>(deprecated)</sup> | string | true | 标识要查询其数据的设备。     |  
| keyPrefix<sup>(deprecated)</sup> | string | true | 表示要匹配的键前缀。     |  
| callback<sup>(deprecated)</sup> | AsyncCallback<KvStoreResultSet> | true | 回调函数。返回与指定设备ID和key前缀匹配的KvStoreResultSet对象。     |  
    
 **示例代码：**   
示例：  
```ts    
let kvStore;  
try {  
    let resultSet;  
    kvStore.getResultSet('localDeviceId', 'batch_test_string_key', async function (err, result) {  
        console.log('getResultSet succeed.');  
        resultSet = result;  
        kvStore.closeResultSet(resultSet, function (err, data) {  
            console.log('closeResultSet success');  
        })  
    });  
}catch(e) {  
    console.log('GetResultSet e ' + e);  
}  
    
```    
  
    
### getResultSet    
获取与指定设备ID和key前缀匹配的KvStoreResultSet对象  
 **调用形式：**     
    
- getResultSet(deviceId: string, keyPrefix: string): Promise\<KvStoreResultSet>    
起始版本： 7    
- getResultSet(query: Query): Promise\<KvStoreResultSet>    
起始版本： 7    
- getResultSet(deviceId: string, query: Query): Promise\<KvStoreResultSet>    
起始版本： 7  
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId | string | true | 标识要查询其数据的设备。     |  
| keyPrefix | string | true | 表示要匹配的键前缀。     |  
| query | Query | true | 表示查询对象。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回与指定设备ID和Query对象匹配的KvStoreResultSet对象。 |  
| Promise<KvStoreResultSet> | Promise对象。返回与指定设备ID和key前缀匹配的KvStoreResultSet对象。 |  
    
 **示例代码1：**   
示例（callback）：参数为：deviceId、keyPrefix  
```ts    
let kvStore;  
try {  
    let resultSet;  
    kvStore.getResultSet('localDeviceId', 'batch_test_string_key', async function (err, result) {  
        console.log('getResultSet succeed.');  
        resultSet = result;  
        kvStore.closeResultSet(resultSet, function (err, data) {  
            console.log('closeResultSet success');  
        })  
    });  
}catch(e) {  
    console.log('GetResultSet e ' + e);  
}  
    
```    
  
    
 **示例代码2：**   
示例（callback）：参数为：query  
  
```ts    
let kvStore;  
try {  
    let resultSet;  
    let entries = [];  
    for (var i = 0; i < 10; i++) {  
        var key = 'batch_test_string_key';  
        var entry = {  
            key : key + i,  
            value : {  
                type : distributedData.ValueType.STRING,  
                value : 'batch_test_string_value'  
            }  
        }  
        entries.push(entry);  
    }  
    kvStore.putBatch(entries, async function (err, data) {  
        console.log('putBatch success');  
        const query = new distributedData.Query();  
        query.prefixKey("batch_test");  
        query.deviceId('localDeviceId');  
        kvStore.getResultSet(query, async function (err, result) {  
            console.log('getResultSet succeed.');  
            resultSet = result;  
            kvStore.closeResultSet(resultSet, function (err, data) {  
                console.log('closeResultSet success');  
            })  
        });  
    });  
} catch(e) {  
    console.log('GetResultSet e ' + e);  
}  
    
```    
  
    
 **示例代码3：**   
示例（callback）：参数为：deviceId、query  
  
```ts    
let kvStore;  
try {  
    let resultSet;  
    let entries = [];  
    for (var i = 0; i < 10; i++) {  
        var key = 'batch_test_string_key';  
        var entry = {  
            key : key + i,  
            value : {  
                type : distributedData.ValueType.STRING,  
                value : 'batch_test_string_value'  
            }  
        }  
        entries.push(entry);  
    }  
    kvStore.putBatch(entries, async function (err, data) {  
        console.log('putBatch success');  
        const query = new distributedData.Query();  
        query.prefixKey("batch_test");  
        kvStore.getResultSet('localDeviceId', query, async function (err, result) {  
            console.log('getResultSet succeed.');  
            resultSet = result;  
            kvStore.closeResultSet(resultSet, function (err, data) {  
                console.log('closeResultSet success');  
            })  
        });  
    });  
} catch(e) {  
    console.log('GetResultSet e ' + e);  
}  
    
```    
  
    
 **示例代码4：**   
示例（Promise）：参数为：deviceId、keyPrefix  
  
```ts    
let kvStore;  
try {  
    let resultSet;  
    kvStore.getResultSet('localDeviceId', 'batch_test_string_key').then((result) => {  
        console.log('getResultSet succeed.');  
        resultSet = result;  
    }).catch((err) => {  
        console.log('getResultSet failed: ' + JSON.stringify(err));  
    });  
    kvStore.closeResultSet(resultSet).then((err) => {  
        console.log('closeResultSet success');  
    }).catch((err) => {  
        console.log('closeResultSet fail ' + JSON.stringify(err));  
    });  
}catch(e) {  
    console.log('GetResultSet e ' + e);  
}  
    
```    
  
    
 **示例代码5：**   
示例（Promise）：参数为：query  
  
```ts    
let kvStore;  
try {  
    let resultSet;  
    let entries = [];  
    for (var i = 0; i < 10; i++) {  
        var key = 'batch_test_string_key';  
        var entry = {  
            key : key + i,  
            value : {  
                type : distributedData.ValueType.STRING,  
                value : 'batch_test_string_value'  
            }  
        }  
        entries.push(entry);  
    }  
    kvStore.putBatch(entries).then(async (err) => {  
        console.log('putBatch success');  
    }).catch((err) => {  
        console.log('putBatch fail ' + err);  
    });  
    const query = new distributedData.Query();  
    query.deviceId('localDeviceId');  
    query.prefixKey("batch_test");  
    console.log("GetResultSet " + query.getSqlLike());  
    kvStore.getResultSet(query).then((result) => {  
        console.log('getResultSet succeed.');  
        resultSet = result;  
    }).catch((err) => {  
        console.log('getResultSet failed: ' + JSON.stringify(err));  
    });  
    kvStore.closeResultSet(resultSet).then((err) => {  
        console.log('closeResultSet success');  
    }).catch((err) => {  
        console.log('closeResultSet fail ' + JSON.stringify(err));  
    });  
}catch(e) {  
    console.log('GetResultSet e ' + e);  
}  
    
```    
  
    
 **示例代码6：**   
示例（Promise）：参数为：deviceId、query  
  
```ts    
let kvStore;  
try {  
    let resultSet;  
    let entries = [];  
    for (var i = 0; i < 10; i++) {  
        var key = 'batch_test_string_key';  
        var entry = {  
            key : key + i,  
            value : {  
                type : distributedData.ValueType.STRING,  
                value : 'batch_test_string_value'  
            }  
        }  
        entries.push(entry);  
    }  
    kvStore.putBatch(entries).then(async (err) => {  
        console.log('GetResultSet putBatch success');  
    }).catch((err) => {  
        console.log('PutBatch putBatch fail ' + JSON.stringify(err));  
    });  
    const query = new distributedData.Query();  
    query.prefixKey("batch_test");  
    kvStore.getResultSet('localDeviceId', query).then((result) => {  
        console.log('GetResultSet getResultSet succeed.');  
        resultSet = result;  
    }).catch((err) => {  
        console.log('GetResultSet getResultSet failed: ' + JSON.stringify(err));  
    });  
    query.deviceId('localDeviceId');  
    console.log("GetResultSet " + query.getSqlLike());  
    kvStore.closeResultSet(resultSet).then((err) => {  
        console.log('GetResultSet closeResultSet success');  
    }).catch((err) => {  
        console.log('GetResultSet closeResultSet fail ' + JSON.stringify(err));  
    });  
  
}catch(e) {  
    console.log('GetResultSet e ' + e);  
}  
    
```    
  
    
### getResultSet<sup>(deprecated)</sup>    
获取与指定Query对象匹配的KvStoreResultSet对象，使用callback异步回调。  
 **调用形式：**     
- getResultSet(query: Query, callback: AsyncCallback\<KvStoreResultSet>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.DeviceKVStore#getResultSet。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.DistributedKVStore    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| query<sup>(deprecated)</sup> | Query | true | 表示查询对象。     |  
| callback<sup>(deprecated)</sup> | AsyncCallback<KvStoreResultSet> | true | 回调函数，返回与指定Query对象匹配的KvStoreResultSet对象。     |  
    
 **示例代码：**   
示例：  
```ts    
let kvStore;  
try {  
    let resultSet;  
    let entries = [];  
    for (var i = 0; i < 10; i++) {  
        var key = 'batch_test_string_key';  
        var entry = {  
            key : key + i,  
            value : {  
                type : distributedData.ValueType.STRING,  
                value : 'batch_test_string_value'  
            }  
        }  
        entries.push(entry);  
    }  
    kvStore.putBatch(entries, async function (err, data) {  
        console.log('putBatch success');  
        const query = new distributedData.Query();  
        query.prefixKey("batch_test");  
        query.deviceId('localDeviceId');  
        kvStore.getResultSet(query, async function (err, result) {  
            console.log('getResultSet succeed.');  
            resultSet = result;  
            kvStore.closeResultSet(resultSet, function (err, data) {  
                console.log('closeResultSet success');  
            })  
        });  
    });  
} catch(e) {  
    console.log('GetResultSet e ' + e);  
}  
    
```    
  
    
### getResultSet<sup>(deprecated)</sup>    
获取与指定设备ID和Query对象匹配的KvStoreResultSet对象，使用callback异步回调。  
 **调用形式：**     
- getResultSet(deviceId: string, query: Query, callback: AsyncCallback\<KvStoreResultSet>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.DeviceKVStore#getResultSet。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.DistributedKVStore    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId<sup>(deprecated)</sup> | string | true | KvStoreResultSet对象所属的设备ID。     |  
| query<sup>(deprecated)</sup> | Query | true | 表示查询对象。     |  
| callback<sup>(deprecated)</sup> | AsyncCallback<KvStoreResultSet> | true | 回调函数。返回与指定设备ID和Query对象匹配的KvStoreResultSet对象。     |  
    
 **示例代码：**   
示例：  
```ts    
let kvStore;  
try {  
    let resultSet;  
    let entries = [];  
    for (var i = 0; i < 10; i++) {  
        var key = 'batch_test_string_key';  
        var entry = {  
            key : key + i,  
            value : {  
                type : distributedData.ValueType.STRING,  
                value : 'batch_test_string_value'  
            }  
        }  
        entries.push(entry);  
    }  
    kvStore.putBatch(entries, async function (err, data) {  
        console.log('putBatch success');  
        const query = new distributedData.Query();  
        query.prefixKey("batch_test");  
        kvStore.getResultSet('localDeviceId', query, async function (err, result) {  
            console.log('getResultSet succeed.');  
            resultSet = result;  
            kvStore.closeResultSet(resultSet, function (err, data) {  
                console.log('closeResultSet success');  
            })  
        });  
    });  
} catch(e) {  
    console.log('GetResultSet e ' + e);  
}  
    
```    
  
    
### closeResultSet<sup>(deprecated)</sup>    
关闭由[DeviceKVStore.getResultSet](#devicekvstore_getresultset)返回的KvStoreResultSet对象，使用callback异步回调。  
 **调用形式：**     
- closeResultSet(resultSet: KvStoreResultSet, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.DeviceKVStore#closeResultSet。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.DistributedKVStore    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| resultSet<sup>(deprecated)</sup> | KvStoreResultSet | true | 指示要关闭的KvStoreResultSet对象。    |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。     |  
    
 **示例代码：**   
示例：  
```ts    
let kvStore;  
try {  
    console.log('CloseResultSet success');  
    let resultSet = null;  
    kvStore.closeResultSet(resultSet, function (err, data) {  
        if (err == undefined) {  
            console.log('closeResultSet success');  
        } else {  
            console.log('closeResultSet fail');  
        }  
    });  
}catch(e) {  
    console.log('CloseResultSet e ' + e);  
}  
    
```    
  
    
### closeResultSet    
关闭由[DeviceKVStore.getResultSet](#devicekvstore_getresultset)返回的KvStoreResultSet对象  
 **调用形式：**     
    
- closeResultSet(resultSet: KvStoreResultSet): Promise\<void>    
起始版本： 7  
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| resultSet | KvStoreResultSet | true | 指示要关闭的KvStoreResultSet对象。    |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
let kvStore;  
try {  
    let resultSet;  
    kvStore.getResultSet('localDeviceId', 'batch_test_string_key', async function (err, result) {  
        console.log('getResultSet succeed.');  
        resultSet = result;  
        kvStore.closeResultSet(resultSet, function (err, data) {  
            console.log('closeResultSet success');  
        })  
    });  
}catch(e) {  
    console.log('GetResultSet e ' + e);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
let kvStore;  
try {  
    console.log('CloseResultSet success');  
    let resultSet = null;  
    kvStore.closeResultSet(resultSet).then(() => {  
        console.log('closeResultSet success');  
    }).catch((err) => {  
        console.log('closeResultSet fail ' + JSON.stringify(err));  
    });  
}catch(e) {  
    console.log('CloseResultSet e ' + e);  
}  
    
```    
  
    
### getResultSize<sup>(deprecated)</sup>    
获取与指定Query对象匹配的结果数，使用callback异步回调。  
 **调用形式：**     
- getResultSize(query: Query, callback: AsyncCallback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.DeviceKVStore#getResultSize。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.DistributedKVStore    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| query<sup>(deprecated)</sup> | Query | true | 表示查询对象。     |  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true | 回调函数，返回与指定Query对象匹配的结果数。     |  
    
 **示例代码：**   
示例：  
```ts    
let kvStore;  
try {  
    let entries = [];  
    for (var i = 0; i < 10; i++) {  
        var key = 'batch_test_string_key';  
        var entry = {  
            key : key + i,  
            value : {  
                type : distributedData.ValueType.STRING,  
                value : 'batch_test_string_value'  
            }  
        }  
        entries.push(entry);  
    }  
    kvStore.putBatch(entries, async function (err, data) {  
        console.log('putBatch success');  
        const query = new distributedData.Query();  
        query.prefixKey("batch_test");  
        query.deviceId('localDeviceId');  
        kvStore.getResultSize(query, async function (err, resultSize) {  
            console.log('getResultSet succeed.');  
        });  
    });  
} catch(e) {  
    console.log('GetResultSize e ' + e);  
}  
    
```    
  
    
### getResultSize    
获取与指定设备ID和Query对象匹配的结果数  
 **调用形式：**     
    
- getResultSize(query: Query): Promise\<number>    
起始版本： 7    
- getResultSize(deviceId: string, query: Query): Promise\<number>    
起始版本： 7  
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| query | Query | true | 表示查询对象。     |  
| deviceId | string | true | KvStoreResultSet对象所属的设备ID。     |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回与指定设备ID和Query对象匹配的结果数。 |  
| Promise<number> | Promise对象。返回与指定Query对象匹配的结果数。 |  
    
 **示例代码1：**   
示例（callback）：参数为：query  
```ts    
let kvStore;  
try {  
    let entries = [];  
    for (var i = 0; i < 10; i++) {  
        var key = 'batch_test_string_key';  
        var entry = {  
            key : key + i,  
            value : {  
                type : distributedData.ValueType.STRING,  
                value : 'batch_test_string_value'  
            }  
        }  
        entries.push(entry);  
    }  
    kvStore.putBatch(entries, async function (err, data) {  
        console.log('putBatch success');  
        const query = new distributedData.Query();  
        query.prefixKey("batch_test");  
        query.deviceId('localDeviceId');  
        kvStore.getResultSize(query, async function (err, resultSize) {  
            console.log('getResultSet succeed.');  
        });  
    });  
} catch(e) {  
    console.log('GetResultSize e ' + e);  
}  
    
```    
  
    
 **示例代码2：**   
示例（callback）：参数为：deviceId、query  
  
```ts    
let kvStore;  
try {  
    let entries = [];  
    for (var i = 0; i < 10; i++) {  
        var key = 'batch_test_string_key';  
        var entry = {  
            key : key + i,  
            value : {  
                type : distributedData.ValueType.STRING,  
                value : 'batch_test_string_value'  
            }  
        }  
        entries.push(entry);  
    }  
    kvStore.putBatch(entries, async function (err, data) {  
        console.log('putBatch success');  
        const query = new distributedData.Query();  
        query.prefixKey("batch_test");  
        kvStore.getResultSize('localDeviceId', query, async function (err, resultSize) {  
            console.log('getResultSet succeed.');  
        });  
    });  
} catch(e) {  
    console.log('GetResultSize e ' + e);  
}  
    
```    
  
    
 **示例代码3：**   
示例（Promise）：参数为：query  
  
```ts    
let kvStore;  
try {  
    let entries = [];  
    for (var i = 0; i < 10; i++) {  
        var key = 'batch_test_string_key';  
        var entry = {  
            key : key + i,  
            value : {  
                type : distributedData.ValueType.STRING,  
                value : 'batch_test_string_value'  
            }  
        }  
        entries.push(entry);  
    }  
    kvStore.putBatch(entries).then(async (err) => {  
        console.log('putBatch success');  
    }).catch((err) => {  
        console.log('putBatch fail ' + JSON.stringify(err));  
    });  
    const query = new distributedData.Query();  
    query.prefixKey("batch_test");  
    query.deviceId('localDeviceId');  
    kvStore.getResultSize(query).then((resultSize) => {  
        console.log('getResultSet succeed.');  
    }).catch((err) => {  
        console.log('getResultSet failed: ' + JSON.stringify(err));  
    });  
}catch(e) {  
    console.log('GetResultSize e ' + e);  
}  
    
```    
  
    
 **示例代码4：**   
示例（Promise）：参数为：deviceId、query  
  
```null    
let kvStore;  
try {  
    let entries = [];  
    for (var i = 0; i < 10; i++) {  
        var key = 'batch_test_string_key';  
        var entry = {  
            key : key + i,  
            value : {  
                type : distributedData.ValueType.STRING,  
                value : 'batch_test_string_value'  
            }  
        }  
        entries.push(entry);  
    }  
    kvStore.putBatch(entries).then(async (err) => {  
        console.log('putBatch success');  
    }).catch((err) => {  
        console.log('putBatch fail ' + JSON.stringify(err));  
    });  
    var query = new distributedData.Query();  
    query.prefixKey("batch_test");  
    kvStore.getResultSize('localDeviceId', query).then((resultSize) => {  
        console.log('getResultSet succeed.');  
    }).catch((err) => {  
        console.log('getResultSet failed: ' + JSON.stringify(err));  
    });  
}catch(e) {  
    console.log('GetResultSize e ' + e);  
}  
    
```    
  
    
### getResultSize<sup>(deprecated)</sup>    
获取与指定设备ID和Query对象匹配的结果数，使用callback异步回调。  
 **调用形式：**     
- getResultSize(deviceId: string, query: Query, callback: AsyncCallback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.DeviceKVStore#getResultSize。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.DistributedKVStore    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId<sup>(deprecated)</sup> | string | true | KvStoreResultSet对象所属的设备ID。     |  
| query<sup>(deprecated)</sup> | Query | true | 表示查询对象。     |  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true | 回调函数。返回与指定设备ID和Query对象匹配的结果数。     |  
    
 **示例代码：**   
示例：  
```ts    
let kvStore;  
try {  
    let entries = [];  
    for (var i = 0; i < 10; i++) {  
        var key = 'batch_test_string_key';  
        var entry = {  
            key : key + i,  
            value : {  
                type : distributedData.ValueType.STRING,  
                value : 'batch_test_string_value'  
            }  
        }  
        entries.push(entry);  
    }  
    kvStore.putBatch(entries, async function (err, data) {  
        console.log('putBatch success');  
        const query = new distributedData.Query();  
        query.prefixKey("batch_test");  
        kvStore.getResultSize('localDeviceId', query, async function (err, resultSize) {  
            console.log('getResultSet succeed.');  
        });  
    });  
} catch(e) {  
    console.log('GetResultSize e ' + e);  
}  
    
```    
  
    
### removeDeviceData<sup>(deprecated)</sup>    
从当前数据库中删除指定设备的数据，使用callback异步回调。  
 **调用形式：**     
- removeDeviceData(deviceId: string, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.DeviceKVStore#removeDeviceData。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.DistributedKVStore    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId<sup>(deprecated)</sup> | string | true | 标识要删除其数据的设备。   |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。     |  
    
 **示例代码：**   
示例：  
```ts    
let kvStore;  
const KEY_TEST_STRING_ELEMENT = 'key_test_string';  
const VALUE_TEST_STRING_ELEMENT = 'value-string-001';  
try {  
    kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT, async function (err,data) {  
        console.log('RemoveDeviceData  put success');  
        const deviceid = 'no_exist_device_id';  
        kvStore.removeDeviceData(deviceid, async function (err,data) {  
            if (err == undefined) {  
                console.log('removeDeviceData success');  
            } else {  
                console.log('removeDeviceData fail');  
                kvStore.get('localDeviceId', KEY_TEST_STRING_ELEMENT, async function (err,data) {  
                    console.log('RemoveDeviceData get success');  
                });  
            }  
        });  
    });  
}catch(e) {  
    console.log('RemoveDeviceData e ' + e);  
}  
    
```    
  
    
### removeDeviceData    
从当前数据库中删除指定设备的数据，使用Promise异步回调。  
 **调用形式：**     
    
- removeDeviceData(deviceId: string): Promise\<void>    
起始版本： 7  
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId | string | true | 标识要删除其数据的设备。   |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
let kvStore;  
const KEY_TEST_STRING_ELEMENT = 'key_test_string';  
const VALUE_TEST_STRING_ELEMENT = 'value-string-001';  
try {  
    kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT, async function (err,data) {  
        console.log('RemoveDeviceData  put success');  
        const deviceid = 'no_exist_device_id';  
        kvStore.removeDeviceData(deviceid, async function (err,data) {  
            if (err == undefined) {  
                console.log('removeDeviceData success');  
            } else {  
                console.log('removeDeviceData fail');  
                kvStore.get('localDeviceId', KEY_TEST_STRING_ELEMENT, async function (err,data) {  
                    console.log('RemoveDeviceData get success');  
                });  
            }  
        });  
    });  
}catch(e) {  
    console.log('RemoveDeviceData e ' + e);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
let kvStore;  
const KEY_TEST_STRING_ELEMENT = 'key_test_string';  
const VALUE_TEST_STRING_ELEMENT = 'value-string-001';  
try {  
    kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT).then((err) => {  
        console.log('RemoveDeviceData put success');  
    }).catch((err) => {  
        console.log('RemoveDeviceData put fail ' + JSON.stringify(err));  
    });  
    const deviceid = 'no_exist_device_id';  
    kvStore.removeDeviceData(deviceid).then((err) => {  
        console.log('removeDeviceData success');  
    }).catch((err) => {  
        console.log('removeDeviceData fail ' + JSON.stringify(err));  
    });  
    kvStore.get('localDeviceId', KEY_TEST_STRING_ELEMENT).then((data) => {  
        console.log('RemoveDeviceData get success data:' + data);  
    }).catch((err) => {  
        console.log('RemoveDeviceData get fail ' + JSON.stringify(err));  
    });  
}catch(e) {  
    console.log('RemoveDeviceData e ' + e);  
}  
    
```    
  
    
### sync<sup>(deprecated)</sup>    
在手动同步方式下，触发数据库同步。  
 **调用形式：**     
- sync(deviceIds: string[], mode: SyncMode, delayMs?: number): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.DeviceKVStore#sync。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core  
 **需要权限：** ohos.permission.DISTRIBUTED_DATASYNC    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceIds<sup>(deprecated)</sup> | string[] | true | 需要同步DeviceKvStore数据库的设备networkId列表。  |  
| mode<sup>(deprecated)</sup> | SyncMode | true | 同步模式。   |  
| delayMs<sup>(deprecated)</sup> | number | false | 可选参数，允许延时时间，单位：ms（毫秒），默认为0。   |  
    
 **示例代码：**   
示例：  
```ts    
import deviceManager from '@ohos.distributedHardware.deviceManager';  
  
let devManager;  
let kvStore;  
const KEY_TEST_SYNC_ELEMENT = 'key_test_sync';  
const VALUE_TEST_SYNC_ELEMENT = 'value-string-001';  
// create deviceManager  
deviceManager.createDeviceManager('bundleName', (err, value) => {  
  if (!err) {  
    devManager = value;  
    let deviceIds = [];  
    if (devManager != null) {  
      var devices = devManager.getTrustedDeviceListSync();  
      for (var i = 0; i < devices.length; i++) {  
        deviceIds[i] = devices[i].networkId;  
      }  
    }  
    try {  
      kvStore.on('syncComplete', function (data) {  
        console.log('Sync dataChange');  
      });  
      kvStore.put(KEY_TEST_SYNC_ELEMENT + 'testSync101', VALUE_TEST_SYNC_ELEMENT, function (err, data) {  
        if (err != undefined) {  
          console.log("put err: " + JSON.stringify(err));  
          return;  
        }  
        console.log('Succeeded in putting data');  
        const mode = distributedData.SyncMode.PULL_ONLY;  
        kvStore.sync(deviceIds, mode, 1000);  
      });  
    } catch (e) {  
      console.log('Sync e' + e);  
    }  
  }  
});  
    
```    
  
    
### on('dataChange')<sup>(deprecated)</sup>    
订阅指定类型的数据变更通知。  
 **调用形式：**     
- on(event: 'dataChange', type: SubscribeType, listener: Callback\<ChangeNotification>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.DeviceKVStore#on。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event<sup>(deprecated)</sup> | string | true | 订阅的事件名，固定为'dataChange'，表示数据变更事件。  |  
| type<sup>(deprecated)</sup> | SubscribeType | true | 表示订阅的类型。                                      |  
| listener<sup>(deprecated)</sup> | Callback<ChangeNotification> | true | 回调函数。                                            |  
    
 **示例代码：**   
示例：  
```ts    
let kvStore;  
kvStore.on('dataChange', distributedData.SubscribeType.SUBSCRIBE_TYPE_LOCAL, function (data) {  
    console.log("dataChange callback call data: " + JSON.stringify(data));  
});    
```    
  
    
### on('syncComplete')<sup>(deprecated)</sup>    
订阅同步完成事件回调通知。  
 **调用形式：**     
- on(event: 'syncComplete', syncCallback: Callback\<Array\<[string, number]>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.DeviceKVStore#on。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event<sup>(deprecated)</sup> | string | true | 订阅的事件名，固定为'syncComplete'，表示同步完成事件。  |  
| syncCallback<sup>(deprecated)</sup> | Callback<Array<[string, number]>> | true | 回调函数。用于向调用方发送同步结果的回调。              |  
    
 **示例代码：**   
示例：  
```ts    
let kvStore;  
const KEY_TEST_FLOAT_ELEMENT = 'key_test_float';  
const VALUE_TEST_FLOAT_ELEMENT = 321.12;  
try {  
    kvStore.on('syncComplete', function (data) {  
        console.log('syncComplete ' + data)  
    });  
    kvStore.put(KEY_TEST_FLOAT_ELEMENT, VALUE_TEST_FLOAT_ELEMENT).then((data) => {  
        console.log('syncComplete put success');  
    }).catch((error) => {  
        console.log('syncComplete put fail ' + error);  
    });  
}catch(e) {  
    console.log('syncComplete put e ' + e);  
}  
    
```    
  
    
### off('dataChange')<sup>(deprecated)</sup>    
取消订阅数据变更通知。  
 **调用形式：**     
- off(event: 'dataChange', listener?: Callback\<ChangeNotification>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.DeviceKVStore#off。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event<sup>(deprecated)</sup> | string | true | 取消订阅的事件名，固定为'dataChange'，表示数据变更事件。  |  
| listener<sup>(deprecated)</sup> | Callback<ChangeNotification> | false | 取消订阅的函数。如不设置callback，则取消所有订阅的函数。  |  
    
 **示例代码：**   
示例：  
```ts    
let kvStore;  
class KvstoreModel {  
    call(data) {  
        console.log("dataChange: " + data);  
    }  
    subscribeDataChange() {  
        if (kvStore != null) {  
            kvStore.on('dataChange', distributedData.SubscribeType.SUBSCRIBE_TYPE_REMOTE, this.call);  
        }  
    }  
    unsubscribeDataChange() {  
        if (kvStore != null) {  
            kvStore.off('dataChange', this.call);  
        }  
    }  
}  
    
```    
  
    
### off('syncComplete')<sup>(deprecated)</sup>    
取消订阅同步完成事件回调通知。  
 **调用形式：**     
- off(event: 'syncComplete', syncCallback?: Callback\<Array\<[string, number]>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.DeviceKVStore#off。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event<sup>(deprecated)</sup> | string | true | 取消订阅的事件名，固定为'syncComplete'，表示同步完成事件。  |  
| syncCallback<sup>(deprecated)</sup> | Callback<Array<[string, number]>> | false | 取消订阅的函数。如不设置callback，则取消所有订阅的函数。   |  
    
 **示例代码：**   
示例：  
```ts    
let kvStore;  
class KvstoreModel {  
    call(data) {  
        console.log("syncComplete: " + data);  
    }  
    subscribeSyncComplete() {  
        if (kvStore != null) {  
            kvStore.on('syncComplete', this.call);  
        }  
    }  
    unsubscribeSyncComplete() {  
        if (kvStore != null) {  
            kvStore.off('syncComplete', this.call);  
        }  
    }  
}  
    
```    
  
    
## createKVManager<sup>(deprecated)</sup>    
创建一个KVManager对象实例，用于管理数据库对象，使用callback异步回调。  
 **调用形式：**     
- createKVManager(config: KVManagerConfig, callback: AsyncCallback\<KVManager>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore#createKVManager。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| config<sup>(deprecated)</sup> | KVManagerConfig | true | 提供KVManager实例的配置信息，包括调用方的Bundle名称和用户信息。  |  
| callback<sup>(deprecated)</sup> | AsyncCallback<KVManager> | true | 回调函数。返回创建的KVManager对象实例。  |  
    
 **示例代码：**   
示例：  
```ts    
let kvManager;  
try {  
    const kvManagerConfig = {  
        bundleName : 'com.example.datamanagertest',  
        userInfo : {  
            userId : '0',  
            userType : distributedData.UserType.SAME_USER_ID  
        }  
    }  
    distributedData.createKVManager(kvManagerConfig, function (err, manager) {  
        if (err) {  
            console.log("Failed to create KVManager: "  + JSON.stringify(err));  
            return;  
        }  
        console.log("Succeeded in creating KVManager");  
        kvManager = manager;  
    });  
} catch (e) {  
    console.log("An unexpected error occurred. Error:" + e);  
}  
    
```    
  
    
## createKVManager    
创建一个KVManager对象实例，用于管理数据库对象，使用Promise异步回调。  
 **调用形式：**     
    
- createKVManager(config: KVManagerConfig): Promise\<KVManager>    
起始版本： 7  
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| config | KVManagerConfig | true | 提供KVManager实例的配置信息，包括调用方的包名和用户信息。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回创建的KVManager对象实例。 |  
| Promise<KVManager> | Promise对象。返回创建的KVManager对象实例。 |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
let kvManager;  
try {  
    const kvManagerConfig = {  
        bundleName : 'com.example.datamanagertest',  
        userInfo : {  
            userId : '0',  
            userType : distributedData.UserType.SAME_USER_ID  
        }  
    }  
    distributedData.createKVManager(kvManagerConfig, function (err, manager) {  
        if (err) {  
            console.log("Failed to create KVManager: "  + JSON.stringify(err));  
            return;  
        }  
        console.log("Succeeded in creating KVManager");  
        kvManager = manager;  
    });  
} catch (e) {  
    console.log("An unexpected error occurred. Error:" + e);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
  
try {  
  const kvManagerConfig = {  
    bundleName: 'com.example.datamanagertest',  
    userInfo: {  
      userId: '0',  
      userType: distributedData.UserType.SAME_USER_ID  
    }  
  }  
  distributedData.createKVManager(kvManagerConfig).then((manager) => {  
    console.log("Succeeded in creating KVManager");  
    kvManager = manager;  
  }).catch((err) => {  
    console.error("Failed to create KVManager: " + JSON.stringify(err));  
  });  
} catch (e) {  
  console.log("An unexpected error occurred. Error:" + e);  
}  
    
```    
  
    
## KVManager<sup>(deprecated)</sup>    
数据管理实例，用于获取KVStore的相关信息。在调用KVManager的方法前，需要先通过[createKVManager](#distributeddatacreatekvmanager)构建一个KVManager实例。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.distributedKVStore.KVManager替代。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
### getKVStore<sup>(deprecated)</sup>    
通过指定Options和storeId，创建并获取KVStore数据库，使用Promise异步回调。  
 **调用形式：**     
- getKVStore\<T extends KVStore>(storeId: string, options: Options): Promise\<T>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.KVManager#getKVStore。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| storeId<sup>(deprecated)</sup> | string | true | 数据库唯一标识符，长度不大于[MAX_STORE_ID_LENGTH](#constants)。  |  
| options<sup>(deprecated)</sup> | Options | true | 创建KVStore实例的配置信息。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<T> | Promise对象。返回创建的KVStore数据库实例。 |  
    
 **示例代码：**   
示例：  
```ts    
let kvStore;  
let kvManager;  
try {  
    const options = {  
        createIfMissing : true,  
        encrypt : false,  
        backup : false,  
        autoSync : true,  
        kvStoreType : distributedData.KVStoreType.SINGLE_VERSION,  
        securityLevel : distributedData.SecurityLevel.S2,  
    };  
    kvManager.getKVStore('storeId', options).then((store) => {  
        console.log("getKVStore success");  
        kvStore = store;  
    }).catch((err) => {  
        console.log("getKVStore err: "  + JSON.stringify(err));  
    });  
} catch (e) {  
    console.log("An unexpected error occurred. Error:" + e);  
}  
    
```    
  
    
### getKVStore    
通过指定Options和storeId，创建并获取KVStore数据库，使用callback异步回调。  
 **调用形式：**     
    
- getKVStore\<T extends KVStore>(storeId: string, options: Options, callback: AsyncCallback\<T>): void    
起始版本： 7  
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| storeId | string | true | 数据库唯一标识符，长度不大于[MAX_STORE_ID_LENGTH](#constants)。  |  
| options | Options | true | 创建KVStore实例的配置信息。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回创建的KVStore数据库实例。 |  
    
 **示例代码：**   
示例：  
```ts    
let kvStore;  
let kvManager;  
try {  
    const options = {  
        createIfMissing : true,  
        encrypt : false,  
        backup : false,  
        autoSync : true,  
        kvStoreType : distributedData.KVStoreType.SINGLE_VERSION,  
        securityLevel : distributedData.SecurityLevel.S2,  
    };  
    kvManager.getKVStore('storeId', options, function (err, store) {  
        if (err) {  
            console.log("getKVStore err: "  + JSON.stringify(err));  
            return;  
        }  
        console.log("getKVStore success");  
        kvStore = store;  
    });  
} catch (e) {  
    console.log("An unexpected error occurred. Error:" + e);  
}  
    
```    
  
    
### closeKVStore<sup>(deprecated)</sup>    
通过storeId的值关闭指定的KVStore数据库，使用callback异步回调。  
 **调用形式：**     
- closeKVStore(appId: string, storeId: string, kvStore: KVStore, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.KVManager#closeKVStore。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| appId<sup>(deprecated)</sup> | string | true | 所调用数据库方的包名。          |  
| storeId<sup>(deprecated)</sup> | string | true | 要关闭的数据库唯一标识符，长度不大于[MAX_STORE_ID_LENGTH](#constants)。  |  
| kvStore<sup>(deprecated)</sup> | KVStore | true | 要关闭的KVStore数据库。      |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。  |  
    
 **示例代码：**   
示例：  
```ts    
let kvStore;  
let kvManager;  
const options = {  
    createIfMissing: true,  
    encrypt: false,  
    backup: false,  
    autoSync: true,  
    kvStoreType: distributedData.KVStoreType.SINGLE_VERSION,  
    schema: undefined,  
    securityLevel: distributedData.SecurityLevel.S2,  
}  
try {  
    kvManager.getKVStore('storeId', options, async function (err, store) {  
        console.log('getKVStore success');  
        kvStore = store;  
        kvManager.closeKVStore('appId', 'storeId', kvStore, function (err, data) {  
            console.log('closeKVStore success');  
        });  
    });  
} catch (e) {  
    console.log('closeKVStore e ' + e);  
}  
    
```    
  
    
### closeKVStore    
通过storeId的值关闭指定的KVStore数据库  
 **调用形式：**     
    
- closeKVStore(appId: string, storeId: string, kvStore: KVStore): Promise\<void>    
起始版本： 7  
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| appId | string | true | 所调用数据库方的包名。             |  
| storeId | string | true | 要关闭的数据库唯一标识符，长度不大于[MAX_STORE_ID_LENGTH](#constants)。  |  
| kvStore | KVStore | true | 要关闭的KVStore数据库。         |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | let kvManager; let kvStore; const options = {     createIfMissing: true,     encrypt: false,     backup: false,     autoSync: true,     kvStoreType: distributedData.KVStoreType.SINGLE_VERSION,     schema: undefined,     securityLevel: distributedData.SecurityLevel.S2, } try {     kvManager.getKVStore('storeId', options).then(async (store) => {         console.log('getKVStore success');         kvStore = store;         kvManager.closeKVStore('appId', 'storeId', kvStore).then(() => {             console.log('closeKVStore success');         }).catch((err) => {             console.log('closeKVStore err ' + JSON.stringify(err));         });     }).catch((err) => {         console.log('CloseKVStore getKVStore err ' + JSON.stringify(err));     }); } catch (e) {     console.log('closeKVStore e ' + e); } |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
let kvStore;  
let kvManager;  
const options = {  
    createIfMissing: true,  
    encrypt: false,  
    backup: false,  
    autoSync: true,  
    kvStoreType: distributedData.KVStoreType.SINGLE_VERSION,  
    schema: undefined,  
    securityLevel: distributedData.SecurityLevel.S2,  
}  
try {  
    kvManager.getKVStore('storeId', options, async function (err, store) {  
        console.log('getKVStore success');  
        kvStore = store;  
        kvManager.closeKVStore('appId', 'storeId', kvStore, function (err, data) {  
            console.log('closeKVStore success');  
        });  
    });  
} catch (e) {  
    console.log('closeKVStore e ' + e);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
let kvManager;  
let kvStore;  
const options = {  
    createIfMissing: true,  
    encrypt: false,  
    backup: false,  
    autoSync: true,  
    kvStoreType: distributedData.KVStoreType.SINGLE_VERSION,  
    schema: undefined,  
    securityLevel: distributedData.SecurityLevel.S2,  
}  
try {  
    kvManager.getKVStore('storeId', options).then(async (store) => {  
        console.log('getKVStore success');  
        kvStore = store;  
        kvManager.closeKVStore('appId', 'storeId', kvStore).then(() => {  
            console.log('closeKVStore success');  
        }).catch((err) => {  
            console.log('closeKVStore err ' + JSON.stringify(err));  
        });  
    }).catch((err) => {  
        console.log('CloseKVStore getKVStore err ' + JSON.stringify(err));  
    });  
} catch (e) {  
    console.log('closeKVStore e ' + e);  
}  
    
```    
  
    
### deleteKVStore<sup>(deprecated)</sup>    
通过storeId的值删除指定的KVStore数据库，使用callback异步回调。  
 **调用形式：**     
- deleteKVStore(appId: string, storeId: string, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.KVManager#deleteKVStore。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| appId<sup>(deprecated)</sup> | string | true | 所调用数据库方的包名。      |  
| storeId<sup>(deprecated)</sup> | string | true | 要删除的数据库唯一标识符，长度不大于[MAX_STORE_ID_LENGTH](#constants)。  |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。  |  
    
 **示例代码：**   
示例：  
```ts    
let kvManager;  
let kvStore;  
const options = {  
    createIfMissing : true,  
    encrypt : false,  
    backup : false,  
    autoSync : true,  
    kvStoreType : distributedData.KVStoreType.SINGLE_VERSION,  
    schema : undefined,  
    securityLevel : distributedData.SecurityLevel.S2,  
}  
try {  
    kvManager.getKVStore('store', options, async function (err, store) {  
        console.log('getKVStore success');  
        kvStore = store;  
        kvManager.deleteKVStore('appId', 'storeId', function (err, data) {  
            console.log('deleteKVStore success');  
        });  
    });  
} catch (e) {  
    console.log('DeleteKVStore e ' + e);  
}  
    
```    
  
    
### deleteKVStore    
通过storeId的值删除指定的KVStore数据库  
 **调用形式：**     
    
- deleteKVStore(appId: string, storeId: string): Promise\<void>    
起始版本： 7  
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| appId | string | true | 所调用数据库方的包名。      |  
| storeId | string | true | 要删除的数据库唯一标识符，长度不大于[MAX_STORE_ID_LENGTH](#constants)。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
let kvManager;  
let kvStore;  
const options = {  
    createIfMissing : true,  
    encrypt : false,  
    backup : false,  
    autoSync : true,  
    kvStoreType : distributedData.KVStoreType.SINGLE_VERSION,  
    schema : undefined,  
    securityLevel : distributedData.SecurityLevel.S2,  
}  
try {  
    kvManager.getKVStore('store', options, async function (err, store) {  
        console.log('getKVStore success');  
        kvStore = store;  
        kvManager.deleteKVStore('appId', 'storeId', function (err, data) {  
            console.log('deleteKVStore success');  
        });  
    });  
} catch (e) {  
    console.log('DeleteKVStore e ' + e);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
let kvManager;  
let kvStore;  
const options = {  
    createIfMissing : true,  
    encrypt : false,  
    backup : false,  
    autoSync : true,  
    kvStoreType : distributedData.KVStoreType.SINGLE_VERSION,  
    schema : undefined,  
    securityLevel : distributedData.SecurityLevel.S2,  
}  
try {  
    kvManager.getKVStore('storeId', options).then(async (store) => {  
        console.log('getKVStore success');  
        kvStore = store;  
        kvManager.deleteKVStore('appId', 'storeId').then(() => {  
            console.log('deleteKVStore success');  
        }).catch((err) => {  
            console.log('deleteKVStore err ' + JSON.stringify(err));  
        });  
    }).catch((err) => {  
        console.log('getKVStore err ' + JSON.stringify(err));  
    });  
} catch (e) {  
    console.log('deleteKVStore e ' + e);  
}  
    
```    
  
    
### getAllKVStoreId<sup>(deprecated)</sup>    
获取所有通过[getKVStore](#getkvstore)方法创建的且没有调用[deleteKVStore](#deletekvstore8)方法删除的KVStore数据库的storeId，使用callback异步回调。  
 **调用形式：**     
- getAllKVStoreId(appId: string, callback: AsyncCallback\<string[]>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.KVManager#getAllKVStoreId。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| appId<sup>(deprecated)</sup> | string | true | 所调用数据库方的包名。      |  
| callback<sup>(deprecated)</sup> | AsyncCallback<string[]> | true | 回调函数。返回所有创建的KvStore数据库的storeId。  |  
    
 **示例代码：**   
示例：  
```ts    
let kvManager;  
try {  
    kvManager.getAllKVStoreId('appId', function (err, data) {  
        console.log('GetAllKVStoreId success');  
        console.log('GetAllKVStoreId size = ' + data.length);  
    });  
} catch (e) {  
    console.log('GetAllKVStoreId e ' + e);  
}  
    
```    
  
    
### getAllKVStoreId    
获取所有通过[getKVStore](#getkvstore)方法创建的且没有调用[deleteKVStore](#deletekvstore8)方法删除的KVStore数据库的storeId  
 **调用形式：**     
    
- getAllKVStoreId(appId: string): Promise\<string[]>    
起始版本： 7  
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| appId | string | true | 所调用数据库方的包名。      |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回所有创建的KvStore数据库的storeId。 |  
| Promise<string[]> | Promise对象。返回所有创建的KvStore数据库的storeId。 |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
let kvManager;  
try {  
    kvManager.getAllKVStoreId('appId', function (err, data) {  
        console.log('GetAllKVStoreId success');  
        console.log('GetAllKVStoreId size = ' + data.length);  
    });  
} catch (e) {  
    console.log('GetAllKVStoreId e ' + e);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
let kvManager;  
try {  
    console.log('GetAllKVStoreId');  
    kvManager.getAllKVStoreId('appId').then((data) => {  
        console.log('getAllKVStoreId success');  
        console.log('size = ' + data.length);  
    }).catch((err) => {  
        console.log('getAllKVStoreId err ' + JSON.stringify(err));  
    });  
} catch(e) {  
    console.log('getAllKVStoreId e ' + e);  
}  
    
```    
  
    
### on('distributedDataServiceDie')<sup>(deprecated)</sup>    
订阅服务状态变更通知。  
 **调用形式：**     
- on(event: 'distributedDataServiceDie', deathCallback: Callback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.KVManager#on。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.DistributedKVStore    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event<sup>(deprecated)</sup> | string | true | 订阅的事件名，固定为'distributedDataServiceDie'，即服务状态变更事件。  |  
| deathCallback<sup>(deprecated)</sup> | Callback<void> | true | 回调函数。  |  
    
 **示例代码：**   
示例：  
```ts    
let kvManager;  
try {  
    console.log('KVManagerOn');  
    const deathCallback = function () {  
        console.log('death callback call');  
    }  
    kvManager.on('distributedDataServiceDie', deathCallback);  
} catch (e) {  
    console.log("An unexpected error occurred. Error:" + e);  
}  
    
```    
  
    
### off('distributedDataServiceDie')<sup>(deprecated)</sup>    
取消订阅服务状态变更通知。  
 **调用形式：**     
- off(event: 'distributedDataServiceDie', deathCallback?: Callback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.distributedKVStore.KVManager#off。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.DistributedKVStore    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event<sup>(deprecated)</sup> | string | true | 取消订阅的事件名，固定为'distributedDataServiceDie'，即服务状态变更事件。  |  
| deathCallback<sup>(deprecated)</sup> | Callback<void> | false | 取消订阅的函数。如不设置callback，则取消所有已订阅的函数。 。 |  
    
 **示例代码：**   
示例：  
```ts    
let kvManager;  
try {  
    console.log('KVManagerOff');  
    const deathCallback = function () {  
        console.log('death callback call');  
    }  
    kvManager.off('distributedDataServiceDie', deathCallback);  
} catch (e) {  
    console.log("An unexpected error occurred. Error:" + e);  
}  
    
```    
  
