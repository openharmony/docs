# @ohos.data.distributedKVStore (分布式键值数据库)
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @ding_dong_dong-->
<!--Designer: @ding_dong_dong-->
<!--Tester: @logic42-->
<!--Adviser: @ge-yafang-->

分布式键值数据库为应用程序提供不同设备间数据库的分布式协同能力。通过调用分布式键值数据库各个接口，应用程序可将数据保存到分布式键值数据库中，并可对分布式键值数据库中的数据进行增加、删除、修改、查询、端端同步等操作。

该模块提供以下常用功能：

- [KVManager](#kvmanager)：分布式键值数据库管理实例，用于获取数据库的相关信息。
- [KVStoreResultSet](#kvstoreresultset)：提供获取数据库结果集的相关方法，包括查询和移动数据读取位置等。
- [Query](#query)：使用谓词表示数据库查询，提供创建Query实例、查询数据库中的数据和添加谓词的方法。
- [SingleKVStore](#singlekvstore)：单版本分布式键值数据库，不对数据所属设备进行区分，提供查询数据和端端同步数据的方法。
- [DeviceKVStore](#devicekvstore)：设备协同数据库，继承自[SingleKVStore](#singlekvstore)，以设备维度对数据进行区分，提供查询数据和端端同步数据的方法。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { distributedKVStore } from '@kit.ArkData';
```

## KVManagerConfig

提供KVManager实例的配置信息，包括调用方的包名和应用的上下文。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

| 名称     | 类型              | 只读 | 可选 | 说明                                                         |
| ---------- | ---------------|----- | ---- | ------------------------------------------------------------ |
| context    | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md)    | 否   | 否   | 应用的上下文。 <br>FA模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-app-context.md)。<br>Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md)。<br>从API version 10开始，context的参数类型为[BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md)。 |
| bundleName | string          | 否   | 否   | 调用方的包名，不可为空且长度范围为1-256字节（Byte）。                                               |

## Constants

分布式键值数据库常量。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

| 名称                  | 类型   | 只读 | 可选 | 说明                                                       |
| --------------------- | ------ | ---- | ---- | ---------------------------------------------------------- |
| MAX_KEY_LENGTH        | number | 是   | 否   | 值为1024，表示数据库中Key允许的最大长度，单位：字节（Byte）。        |
| MAX_VALUE_LENGTH      | number | 是   | 否   | 值为4194303，表示数据库中Value允许的最大长度，单位：字节（Byte）。   |
| MAX_KEY_LENGTH_DEVICE | number | 是   | 否   | 值为896，表示设备协同数据库中Key允许的最大长度，单位：字节（Byte）。 |
| MAX_STORE_ID_LENGTH   | number | 是   | 否   | 值为128，表示数据库标识符允许的最大长度，单位：字节（Byte）。        |
| MAX_QUERY_LENGTH      | number | 是   | 否   | 值为512000，表示最大查询长度，单位：字节（Byte）。                   |
| MAX_BATCH_SIZE        | number | 是   | 否   | 值为128，表示最大批处理操作数量。                          |

## ValueType

数据类型枚举。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

| 名称       | 值 | 说明                 |
| ---------- | - | -------------------- |
| STRING     | 0 | 表示值类型为字符串。   |
| INTEGER    | 1 | 表示值类型为整数。     |
| FLOAT      | 2 | 表示值类型为浮点数。   |
| BYTE_ARRAY | 3 | 表示值类型为字节（Byte）数组。 |
| BOOLEAN    | 4 | 表示值类型为布尔值。   |
| DOUBLE     | 5 | 表示值类型为双浮点数。 |

## Value

存储在数据库中的值对象。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

| 名称  | 类型   | 只读 | 可选 | 说明                                                               |
| ----- | -------|-----|-----|------------------------------------------------------------------|
| type | [ValueType](#valuetype) | 否    | 否   | 值类型。                                                             |
| value | Uint8Array \| string \| number \| boolean| 否    | 否   | 键值对中的值。Uint8Array、string类型的长度范围为0-[MAX_VALUE_LENGTH](#constants)，number和boolean类型的取值范围由其自身类型决定。 |

## Entry

存储在数据库中的键值对。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

| 名称  | 类型        | 只读 | 可选 | 说明     |
| ----- | ---------- |-- | ---- | -------- |
| key   | string          | 否    | 否   | 表示键名。不能为空且长度范围为1-[MAX_KEY_LENGTH](#constants)。   |
| value | [Value](#value) | 否    | 否   | 值对象。 |

## ChangeNotification

数据变更时通知的对象，包括插入的数据、更新的数据、删除的数据和设备ID。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

| 名称          | 类型          | 只读 | 可选       | 说明                     |
| ------------- | ----------------- |---- | ---- | ------------------------ |
| insertEntries | [Entry](#entry)[] | 否    | 否   | 数据添加记录。           |
| updateEntries | [Entry](#entry)[] | 否    | 否   | 数据更新记录。           |
| deleteEntries | [Entry](#entry)[] | 否    | 否    | 数据删除记录。           |
| deviceId      | string            | 否    | 否    | 设备ID，此处为设备UUID。 |

## SyncMode

同步模式枚举。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

| 名称      | 值 | 说明                                           |
| --------- | - | ---------------------------------------------- |
| PULL_ONLY | 0 | 表示只能从远端拉取数据到本端。                    |
| PUSH_ONLY | 1 | 表示只能从本端推送数据到远端。                    |
| PUSH_PULL | 2 | 表示从本端推送数据到远端，然后从远端拉取数据到本端。|

## SubscribeType

订阅类型枚举。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

| 名称                  | 值 | 说明                         |
| --------------------- | - | ---------------------------- |
| SUBSCRIBE_TYPE_LOCAL  | 0 | 表示订阅本地数据变更。         |
| SUBSCRIBE_TYPE_REMOTE | 1 | 表示订阅远端数据变更。         |
| SUBSCRIBE_TYPE_ALL    | 2 | 表示订阅远端和本地数据变更。   |

## KVStoreType

分布式键值数据库类型枚举。

| 名称                 | 值 | 说明                                                         |
| -------------------- | - | ------------------------------------------------------------ |
| DEVICE_COLLABORATION | 0 | 表示多设备协同数据库。<br>**数据库特点：** 数据以设备的维度管理，不存在冲突；支持按照设备的维度查询数据。<br>**系统能力：** SystemCapability.DistributedDataManager.KVStore.DistributedKVStore |
| SINGLE_VERSION       | 1 | 表示单版本数据库。<br>**数据库特点：** 数据不分设备，设备之间修改相同的Key会覆盖。 <br>**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core |

## SecurityLevel

数据库的安全级别枚举。

> **说明：**
>
> 在单设备使用场景下，KV数据库支持修改securityLevel参数进行安全等级升级。升级操作需要注意以下几点：
> * 该操作不支持跨设备同步的数据库。不同安全等级的数据库之间不能进行数据同步。若需升级数据库的安全等级，建议重新创建更高安全等级的数据库。
> * 关闭当前数据库后，修改securityLevel参数以重新设置数据库的安全等级，然后调用[getKVStore](#getkvstore)接口重新打开数据库。
> * 该操作仅支持升级，例如从S2到S3，不支持降级，例如从S3到S2。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

| 名称        | 值 | 说明                                                         |
| --------   | - | ------------------------------------------------------------ |
| S1        | 2 | 表示数据库的安全级别为低级别，数据的泄露、篡改、破坏、销毁可能会给个人或组织导致有限的不利影响。<br>例如，性别、国籍，用户申请记录等。 |
| S2        | 3 | 表示数据库的安全级别为中级别，数据的泄露、篡改、破坏、销毁可能会给个人或组织导致严重的不利影响。<br>例如，个人详细通信地址，姓名昵称等。 |
| S3        | 5 | 表示数据库的安全级别为高级别，数据的泄露、篡改、破坏、销毁可能会给个人或组织导致严峻的不利影响。<br>例如，个人实时精确定位信息、运动轨迹等。 |
| S4        | 6 | 表示数据库的安全级别为关键级别，业界法律法规中定义的特殊数据类型，涉及个人的最私密领域的信息，一旦泄露、篡改、破坏、销毁可能会给个人或组织造成重大的不利影响。<br>例如，政治观点、宗教、哲学信仰、工会成员资格、基因数据、生物信息、健康、性生活状况、性取向、设备认证鉴权或个人的信用卡等财务信息。 |

## Options

用于提供创建数据库的配置信息。

| 名称          | 类型                        | 只读 | 可选 | 说明                                                         |
| --------------- | -------------- | ---- | ----| -------------------------|
| createIfMissing | boolean                         | 否    | 是  | 当数据库文件不存在时是否创建数据库，true为创建，false为不创建，默认为true。<br>**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core |
| encrypt         | boolean                         | 否    | 是   | 设置数据库文件是否加密，true为加密，false为不加密，默认为false。<br>**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core |
| backup          | boolean                         | 否    | 是   | 设置数据库文件是否备份，true为备份，false为不备份，默认为true。 <br>**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core |
| autoSync        | boolean                         | 否    | 是   | 设置数据库是否支持跨设备自动同步。默认为false，即只支持手动同步。配置为true，<!--RP1-->即只支持在[跨设备Call调用实现的多端协同](../../application-models/hop-multi-device-collaboration.md#通过跨设备call调用实现多端协同)中生效，其他场景无法生效。<!--RP1End--><br>**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core<br>**需要权限**： ohos.permission.DISTRIBUTED_DATASYNC |
| kvStoreType     | [KVStoreType](#kvstoretype)     | 否    | 是   | 设置要创建的数据库类型，默认为DEVICE_COLLABORATION，即多设备协同数据库。<br>**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core |
| securityLevel   | [SecurityLevel](#securitylevel) | 否    | 否   | 设置数据库安全级别。<br>**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core |
| schema          | [Schema](#schema)               | 否    | 是   | 设置定义存储在数据库中的值，默认为undefined，即不使用Schema。<br>**系统能力：** SystemCapability.DistributedDataManager.KVStore.DistributedKVStore |
| rootDir<sup>24+</sup> | string                         | 否    | 是  | 设置数据库文件存储路径，不设置即为默认路径（context.databaseDir）。不能设置空字符串，创建数据库和删除数据库时目录必须有访问权限且存在，关闭数据库不校验此参数。<br>**系统能力：** SystemCapability.DistributedDataManager.KVStore.DistributedKVStore |

## BackupConfig<sup>24+</sup>

用于备份数据库的配置信息。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

| 名称          | 类型                        | 只读 | 可选 | 说明                                                         |
| --------------| -------------- | ---- | ----| -------------------------|
| fileName      | string         | 否 | 否 | 备份数据库的名称，无长度限制，不能包含特殊字符'/'。 |
| filePath      | string         | 否 | 否 | 备份数据库的路径，无长度限制。 |

## Schema

表示数据库模式，可以在创建或打开数据库时创建Schema对象并将它们放入[Options](#options)中。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

| 名称    | 类型                    | 只读 | 可选 | 说明                       |
| ------- | ----------------------- | ---- | ---- | -------------------------- |
| root    | [FieldNode](#fieldnode) | 否  | 否  | 存放了Value中所有字段的定义。 |
| indexes | Array\<string>          | 否  | 否  | 索引字段定义，只有通过此字段指定的FieldNode才会创建索引，格式为：`'$.field1'`, `'$.field2'`。|
| mode    | number                  | 否  | 否  | Schema的模式，可以取值0或1，0表示COMPATIBLE模式，1表示STRICT模式。|
| skip    | number                  | 否  | 否  | 支持在检查Value时，跳过skip指定的字节（Byte）数，取值范围为[0, 4 * 1024 * 1024 - 2]字节（Byte）。|

STRICT：STRICT模式要求用户插入的值必须与Schema定义严格匹配，字段数量和格式都不能有差异。如果不匹配，数据库将在插入数据时返回错误。

COMPATIBLE：选择为COMPATIBLE模式时，数据库在检查Value格式时较为宽松，只要Value具有Schema描述的特征即可，允许存在额外字段。例如，定义了id、name字段时，可以插入id、name、age等多个字段。

### constructor

constructor()

用于创建Schema实例的构造函数。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**示例：**

```ts

let child1 = new distributedKVStore.FieldNode('id');
child1.type = distributedKVStore.ValueType.INTEGER;
child1.nullable = false;
child1.default = '1';
let child2 = new distributedKVStore.FieldNode('name');
child2.type = distributedKVStore.ValueType.STRING;
child2.nullable = false;
child2.default = 'zhangsan';

let schema = new distributedKVStore.Schema();
schema.root.appendChild(child1);
schema.root.appendChild(child2);
schema.indexes = ['$.id', '$.name'];
schema.mode = 1;
schema.skip = 0;
```

## FieldNode

表示 Schema 实例的节点，提供定义存储在数据库中的值的方法。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

| 名称     | 类型    | 只读 | 可选 | 说明                                                                                                    |
| -------- | ------- | ---- | ---- |-------------------------------------------------------------------------------------------------------|
| nullable | boolean | 否   | 否   | 表示数据库字段是否可以为空。true表示此节点数据可以为空，false表示此节点数据不能为空。                                                       |
| default  | string  | 否   | 否   | 表示FieldNode的默认值。default需传入type对应类型可解析的字符串字面量，确保内容类型与type字段类型一致。                                       |
| type     | number  | 否   | 否   | 表示指定节点对应的数据类型，取值为[ValueType](#valuetype)对应的枚举值。说明：暂不支持BYTE_ARRAY，使用此类型会导致[getKVStore](#getkvstore)失败。 |

### constructor

constructor(name: string)

用于创建带有string字段FieldNode实例的构造函数。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**参数：**

| 参数名 | 类型 | 必填 | 说明            |
| ------ | -------- | ---- | --------------- |
| name   | string   | 是   | FieldNode的值，不能为空，长度范围为1-64个字符。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                |
| ------------ | ------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Parameter verification failed.  |

### appendChild

appendChild(child: FieldNode): boolean

在当前 FieldNode 中添加一个子节点。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**参数：**

| 参数名 | 类型                | 必填 | 说明       |
| ------ | ----------------------- | ---- |----------|
| child  | [FieldNode](#fieldnode) | 是   | 要附加的子节点。 |

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 返回true表示子节点成功添加到FieldNode；返回false则表示操作失败。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                |
| ------------ | ------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.  |

**示例：**

```ts

try {
  let node: distributedKVStore.FieldNode | null = new distributedKVStore.FieldNode('root');
  let child1: distributedKVStore.FieldNode | null = new distributedKVStore.FieldNode('child1');
  let child2: distributedKVStore.FieldNode | null = new distributedKVStore.FieldNode('child2');
  let child3: distributedKVStore.FieldNode | null = new distributedKVStore.FieldNode('child3');
  node.appendChild(child1);
  node.appendChild(child2);
  node.appendChild(child3);
  console.info('appendNode ' + JSON.stringify(node));
  child1 = null;
  child2 = null;
  child3 = null;
  node = null;
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to append child. Code: ${error.code}, message: ${error.message}`);
}
```

## distributedKVStore.createKVManager

createKVManager(config: KVManagerConfig): KVManager

创建一个KVManager对象实例，用于管理数据库对象。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名 | 类型                      | 必填 | 说明                                                      |
| ------ | ----------------------------- | ---- | --------------------------------------------------------- |
| config | [KVManagerConfig](#kvmanagerconfig) | 是   | 提供KVManager实例的配置信息，包括应用的上下文和调用方的包名（不能为空）。 |

**返回值：**

| 类型                                   | 说明                                       |
| -------------------------------------- | ------------------------------------------ |
| [KVManager](#kvmanager) | 返回创建的KVManager对象实例。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                |
| ------------ | ------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed.  |

**示例：**

Stage模型下的示例：

```ts
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let kvManager: distributedKVStore.KVManager;
let appId: string = 'com.example.datamanagertest';

export default class EntryAbility extends UIAbility {
  onCreate() {
    console.info('MyAbilityStage onCreate');
    let context = this.context;
    const kvManagerConfig: distributedKVStore.KVManagerConfig = {
      context: context,
      bundleName: appId
    }
    try {
      kvManager = distributedKVStore.createKVManager(kvManagerConfig);
      console.info('Succeeded in creating KVManager');
    } catch (err) {
      let error = err as BusinessError;
      console.error(`Failed to create KVManager. Code: ${error.code}, message: ${error.message}`);
    }
    if (kvManager !== undefined) {
      // 进行后续创建数据库等相关操作
      // ...
    }
  }
}
```

FA模型下的示例：

<!--code_no_check_fa-->
```ts
import { featureAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let kvManager: distributedKVStore.KVManager;
let appId: string = 'com.example.datamanagertest';
let context = featureAbility.getContext();
const kvManagerConfig: distributedKVStore.KVManagerConfig = {
  context: context,
  bundleName: appId
}
try {
  kvManager = distributedKVStore.createKVManager(kvManagerConfig);
  console.info('Succeeded in creating KVManager');
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to create KVManager. Code: ${error.code}, message: ${error.message}`);
}
if (kvManager !== undefined) {
  kvManager = kvManager as distributedKVStore.KVManager;
  // 进行后续创建数据库等相关操作
  // ...
}
```

## KVManager

分布式键值数据库管理实例，用于获取分布式键值数据库的相关信息。在调用KVManager的方法前，需要先通过[createKVManager](#distributedkvstorecreatekvmanager)构建一个KVManager实例。

### getKVStore

getKVStore&lt;T&gt;(storeId: string, options: Options, callback: AsyncCallback&lt;T&gt;): void

通过指定options和storeId，创建并获取分布式键值数据库，使用callback异步回调。获取数据库后，在使用完毕时需调用[closeKVStore](#closekvstore)关闭数据库释放资源。

> **注意：**
>
> 在获取已有的分布式键值数据库时，如果数据库文件无法打开（例如文件头损坏），将触发自动重建逻辑，并返回新创建的分布式键值数据库实例。建议对重要且无法重新生成的数据使用备份恢复功能，以防止数据丢失。有关备份恢复的使用方法，请参阅[数据库备份与恢复](../../database/data-backup-and-restore.md)。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名   | 类型               | 必填 | 说明                                                         |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| storeId  | string                 | 是   | 数据库唯一标识符，长度范围为1-[MAX_STORE_ID_LENGTH](#constants)，且只能包含字母数字或下划线_。|
| options  | [Options](#options)    | 是   | 创建分布式键值实例的配置信息。                               |
| callback | AsyncCallback&lt;T&gt; | 是   | 回调函数。返回创建的分布式键值数据库实例（根据kvStoreType的不同，可以创建SingleKVStore实例和DeviceKVStore实例）。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)和[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                |
| ------------ | ------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed.  |
| 15100002     | Open existed database with changed options. |
| 15100003     | Database corrupted.                         |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let kvStore: distributedKVStore.SingleKVStore | null = null;
try {
  const options: distributedKVStore.Options = {
    createIfMissing: true,
    encrypt: false,
    backup: false,
    autoSync: false,
    kvStoreType: distributedKVStore.KVStoreType.SINGLE_VERSION,
    securityLevel: distributedKVStore.SecurityLevel.S3
  };
  kvManager.getKVStore('storeId', options, (err: BusinessError, store: distributedKVStore.SingleKVStore) => {
    if (err) {
      console.error(`Failed to get KVStore. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in getting KVStore');
    kvStore = store;
    if (kvStore !== null) {
       // 进行后续相关数据操作，包括数据的增、删、改、查、订阅数据变化等操作
       // ...
    }
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### getKVStore

getKVStore&lt;T&gt;(storeId: string, options: Options): Promise&lt;T&gt;

指定options和storeId，创建并获取分布式键值数据库，使用Promise回调。获取数据库后，在使用完毕时需调用[closeKVStore](#closekvstore)关闭数据库释放资源。

> **注意：**
>
> 获取已有的分布式键值数据库时，如果数据库文件无法打开（如文件头损坏），将触发自动重建逻辑，并返回新创建的分布式键值数据库实例。建议对重要且无法重新生成的数据使用备份恢复功能，防止数据丢失。备份恢复的使用方法详见[数据库备份与恢复](../../database/data-backup-and-restore.md)。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名  | 类型            | 必填 | 说明                                                         |
| ------- | ------------------- | ---- | ------------------------------------------------------------ |
| storeId | string              | 是   | 数据库唯一标识符，长度范围为1-[MAX_STORE_ID_LENGTH](#constants)，且只能包含字母数字或下划线_。|
| options | [Options](#options) | 是   | 创建分布式键值实例的配置信息。                               |

**返回值：**

| 类型             | 说明                                                         |
| ---------------- | ------------------------------------------------------------ |
| Promise&lt;T&gt; | Promise对象。返回创建的分布式键值数据库实例（根据kvStoreType的不同，可以创建SingleKVStore实例和DeviceKVStore实例）。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)和[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                |
| ------------ | ------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed.|
| 15100002     | Open existed database with changed options. |
| 15100003     | Database corrupted.                         |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let kvStore: distributedKVStore.SingleKVStore | null = null;
try {
  const options: distributedKVStore.Options = {
    createIfMissing: true,
    encrypt: false,
    backup: false,
    autoSync: false,
    kvStoreType: distributedKVStore.KVStoreType.SINGLE_VERSION,
    securityLevel: distributedKVStore.SecurityLevel.S3,
    // 从API version 24开始，可使用rootDir指定数据库存储路径
    rootDir: "/data/storage/el2/database/entry"
  };
  kvManager.getKVStore<distributedKVStore.SingleKVStore>('storeId', options).then((store: distributedKVStore.SingleKVStore) => {
    console.info('Succeeded in getting KVStore');
    kvStore = store;
  }).catch((err: BusinessError) => {
    console.error(`Failed to get KVStore. Code: ${err.code}, message: ${err.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### closeKVStore

closeKVStore(appId: string, storeId: string, callback: AsyncCallback&lt;void&gt;): void

通过storeId的值关闭指定的分布式键值数据库，使用callback异步回调。此方法与getKVStore()方法配对使用，使用完毕的数据库应通过此方法关闭。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名   | 类型                  | 必填 | 说明                                                         |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| appId    | string                    | 是   | 应用的BundleName，不可为空且长度范围为1-256字节（Byte）。                                      |
| storeId  | string                    | 是   | 要关闭的数据库唯一标识符，长度范围为1-[MAX_STORE_ID_LENGTH](#constants)，且只能包含字母数字或下划线_。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。当要关闭的数据库成功关闭，err为undefined，否则为错误对象。     |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                |
| ------------ | ------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Parameter verification failed.|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let kvStore: distributedKVStore.SingleKVStore | null = null;
const options: distributedKVStore.Options = {
  createIfMissing: true,
  encrypt: false,
  backup: false,
  autoSync: false,
  kvStoreType: distributedKVStore.KVStoreType.SINGLE_VERSION,
  schema: undefined,
  securityLevel: distributedKVStore.SecurityLevel.S3
}
try {
  kvManager.getKVStore('storeId', options, async (err: BusinessError, store: distributedKVStore.SingleKVStore | null) => {
    if (err) {
      console.error(`Failed to get KVStore. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in getting KVStore');
    kvStore = store;
    kvStore = null;
    store = null;
    if (kvManager != undefined) {
      // appId为createKVManager中的appId
      kvManager.closeKVStore(appId, 'storeId', (err: BusinessError)=> {
        if (err) {
          console.error(`Failed to close KVStore. Code: ${err.code}, message: ${err.message}`);
          return;
        }
        console.info('Succeeded in closing KVStore');
      });
    }
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### closeKVStore

closeKVStore(appId: string, storeId: string, kvConfig?: Options): Promise&lt;void&gt;

通过storeId的值关闭指定的分布式键值数据库，如果使用kvConfig参数，关闭的是指定路径下的分布式键值数据库，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名  | 类型 | 必填 | 说明                                                         |
| ------- | -------- | ---- | ------------------------------------------------------------ |
| appId   | string   | 是   | 应用的BundleName，不可为空且长度范围为1-256字节（Byte）。                           |
| storeId | string   | 是   | 要关闭的数据库唯一标识符，长度范围为1-[MAX_STORE_ID_LENGTH](#constants)，且只能包含字母数字或下划线_。 |
| kvConfig<sup>24+</sup> | [Options](#options)  | 否   | 要关闭的数据库的配置信息，默认为空。 |

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                |
| ------------ | ------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Parameter verification failed.|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let kvStore: distributedKVStore.SingleKVStore | null = null;

const options: distributedKVStore.Options = {
  createIfMissing: true,
  encrypt: false,
  backup: false,
  autoSync: false,
  kvStoreType: distributedKVStore.KVStoreType.SINGLE_VERSION,
  schema: undefined,
  securityLevel: distributedKVStore.SecurityLevel.S3,
  // 从API version 24开始，可使用rootDir指定数据库存储路径
  rootDir: "/data/storage/el2/database/entry"
}
try {
  kvManager.getKVStore<distributedKVStore.SingleKVStore>('storeId', options).then(async (store: distributedKVStore.SingleKVStore | null) => {
    console.info('Succeeded in getting KVStore');
    kvStore = store;
    kvStore = null;
    store = null;
    if (kvManager != undefined) {
      // appId为createKVManager中的appId, 如果options中没有配置rootDir，closeKVStore不需要options参数
      kvManager.closeKVStore(appId, 'storeId', options).then(() => {
        console.info('Succeeded in closing KVStore');
      }).catch((err: BusinessError) => {
        console.error(`Failed to close KVStore. Code: ${err.code}, message: ${err.message}`);
      });
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to get KVStore. Code: ${err.code}, message: ${err.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to close KVStore. Code: ${error.code}, message: ${error.message}`);
}
```

### deleteKVStore

deleteKVStore(appId: string, storeId: string, callback: AsyncCallback&lt;void&gt;): void

通过storeId的值删除指定的分布式键值数据库，使用callback异步回调。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名   | 类型                  | 必填 | 说明                                                         |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| appId    | string                    | 是   | 应用的BundleName，不可为空且长度范围为1-256字节（Byte）。                                      |
| storeId  | string                    | 是   | 要删除的数据库唯一标识符，长度范围为1-[MAX_STORE_ID_LENGTH](#constants)，且只能包含字母数字或下划线_。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。当要删除的数据库成功删除，err为undefined，否则为错误对象。     |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)和[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息** |
| ------------ | ------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Parameter verification failed.|
| 15100004     | Not found.   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let kvStore: distributedKVStore.SingleKVStore | null = null;

const options: distributedKVStore.Options = {
  createIfMissing: true,
  encrypt: false,
  backup: false,
  autoSync: false,
  kvStoreType: distributedKVStore.KVStoreType.SINGLE_VERSION,
  schema: undefined,
  securityLevel: distributedKVStore.SecurityLevel.S3
}
try {
  kvManager.getKVStore('storeId', options, async (err: BusinessError, store: distributedKVStore.SingleKVStore | null) => {
    if (err) {
      console.error(`Failed to get KVStore. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in getting KVStore');
    kvStore = store;
    kvStore = null;
    store = null;
    if (kvManager != undefined) {
      // appId为createKVManager中的appId
      kvManager.deleteKVStore(appId, 'storeId', (err: BusinessError) => {
        if (err) {
          console.error(`Failed to delete KVStore. Code: ${err.code}, message: ${err.message}`);
          return;
        }
        console.info(`Succeeded in deleting KVStore`);
      });
    }
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to delete KVStore. Code: ${error.code}, message: ${error.message}`);
}
```

### deleteKVStore

deleteKVStore(appId: string, storeId: string, kvConfig?: Options): Promise&lt;void&gt;

通过storeId的值删除指定的分布式键值数据库，如果使用kvConfig参数，删除的是指定路径下的分布式键值数据库，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名  | 类型 | 必填 | 说明                                                         |
| ------- | -------- | ---- | ------------------------------------------------------------ |
| appId   | string   | 是   | 应用的BundleName，不可为空且长度范围为1-256字节（Byte）。                           |
| storeId | string   | 是   | 要删除的数据库唯一标识符，长度范围为1-[MAX_STORE_ID_LENGTH](#constants)，且只能包含字母数字或下划线_。 |
| kvConfig<sup>24+</sup> | [Options](#options)  | 否   | 要删除的数据库的配置信息，默认为空。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)和[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息** |
| ------------ | ------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Parameter verification failed.|
| 15100004     | Not found.   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let kvStore: distributedKVStore.SingleKVStore | null = null;

const options: distributedKVStore.Options = {
  createIfMissing: true,
  encrypt: false,
  backup: false,
  autoSync: false,
  kvStoreType: distributedKVStore.KVStoreType.SINGLE_VERSION,
  schema: undefined,
  securityLevel: distributedKVStore.SecurityLevel.S3,
  // 从API version 24开始，可使用rootDir指定数据库存储路径
  rootDir: "/data/storage/el2/database/entry"
}
try {
  kvManager.getKVStore<distributedKVStore.SingleKVStore>('storeId', options).then(async (store: distributedKVStore.SingleKVStore | null) => {
    console.info('Succeeded in getting KVStore');
    kvStore = store;
    kvStore = null;
    store = null;
    if (kvManager != undefined) {
      // appId为createKVManager中的appId, 如果options中没有配置rootDir，deleteKVStore不需要options参数
      kvManager.deleteKVStore(appId, 'storeId', options).then(() => {
        console.info('Succeeded in deleting KVStore');
      }).catch((err: BusinessError) => {
        console.error(`Failed to delete KVStore. Code: ${err.code}, message: ${err.message}`);
      });
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to get KVStore. Code: ${err.code}, message: ${err.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to delete KVStore. Code: ${error.code}, message: ${error.message}`);
}
```

### getAllKVStoreId

getAllKVStoreId(appId: string, callback: AsyncCallback&lt;string[]&gt;): void

获取所有通过[getKVStore](#getkvstore)方法创建的且没有调用[deleteKVStore](#deletekvstore)方法删除的分布式键值数据库的storeId，使用callback异步回调。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                                |
| -------- | ----------------------------- | ---- | --------------------------------------------------- |
| appId    | string                        | 是   | 应用的BundleName，不可为空且长度范围为1-256字节（Byte）。                              |
| callback | AsyncCallback&lt;string[]&gt; | 是   | 回调函数。返回所有创建的分布式键值数据库的storeId。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息** |
| ------------ | ------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Parameter verification failed.|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  // appId为createKVManager中的appId
  kvManager.getAllKVStoreId(appId, (err: BusinessError, data: string[]) => {
    if (err) {
      console.error(`Failed to get AllKVStoreId. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in getting AllKVStoreId');
    console.info(`GetAllKVStoreId size = ${data.length}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to get AllKVStoreId. Code: ${error.code}, message: ${error.message}`);
}
```

### getAllKVStoreId

getAllKVStoreId(appId: string): Promise&lt;string[]&gt;

获取所有通过[getKVStore](#getkvstore)方法创建的且没有调用[deleteKVStore](#deletekvstore)方法删除的分布式键值数据库的storeId，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明                   |
| ------ | -------- | ---- | ---------------------- |
| appId  | string   | 是   | 应用的BundleName，不可为空且长度范围为1-256字节（Byte）。 |

**返回值：**

| 类型                    | 说明                                                   |
| ----------------------- | ------------------------------------------------------ |
| Promise&lt;string[]&gt; | Promise对象。返回所有创建的分布式键值数据库的storeId。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息** |
| ------------ | ------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Parameter verification failed.|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  // appId为createKVManager中的appId
  console.info('GetAllKVStoreId');
  kvManager.getAllKVStoreId(appId).then((data: string[]) => {
    console.info('Succeeded in getting AllKVStoreId');
    console.info(`GetAllKVStoreId size = ${data.length}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to get AllKVStoreId. Code: ${err.code}, message: ${err.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to get AllKVStoreId. Code: ${error.code}, message: ${error.message}`);
}
```

### on('distributedDataServiceDie')

on(event: 'distributedDataServiceDie', deathCallback: Callback&lt;void&gt;): void

订阅服务终止事件。如果服务终止，需要重新调用[on('dataChange')](#ondatachange)和[on('syncComplete')](#onsynccomplete)注册数据变更通知和端端同步完成事件回调通知，并且端端同步操作会返回失败。调用on订阅后，在不需要监听时必须调用[off('distributedDataServiceDie')](#offdistributeddataservicedie)取消订阅。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**参数：**

| 参数名        | 类型             | 必填 | 说明                                                         |
| ------------- | -------------------- | ---- | ------------------------------------------------------------ |
| event         | string               | 是   | 订阅的事件名，固定为'distributedDataServiceDie'，即服务终止事件。 |
| deathCallback | Callback&lt;void&gt; | 是   | 回调函数。订阅成功，err为undefined，否则为错误对象。     |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息** |
| ------------ | ------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed.|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  console.info('KVManagerOn');
  const deathCallback = () => {
    console.info('death callback call');
  }
  kvManager.on('distributedDataServiceDie', deathCallback);
} catch (err) {
  let error = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### off('distributedDataServiceDie')

off(event: 'distributedDataServiceDie', deathCallback?: Callback&lt;void&gt;): void

取消订阅服务终止事件。必须先调用[on('distributedDataServiceDie')](#ondistributeddataservicedie)订阅后，才能调用off取消订阅。参数中的deathCallback必须是已经订阅过的deathCallback，否则会取消订阅失败。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**参数：**

| 参数名        | 类型             | 必填 | 说明                                                         |
| ------------- | -------------------- | ---- | ------------------------------------------------------------ |
| event         | string               | 是   | 取消订阅的事件名，固定为'distributedDataServiceDie'，即服务终止事件。 |
| deathCallback | Callback&lt;void&gt; | 否   | 回调函数。如果该参数不填，那么会将之前订阅过的所有的deathCallback取消订阅。                                          |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息** |
| ------------ | ------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  console.info('KVManagerOff');
  const deathCallback = () => {
    console.info('death callback call');
  }
  kvManager.off('distributedDataServiceDie', deathCallback);
} catch (err) {
  let error = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

## KVStoreResultSet

提供获取数据库结果集的相关方法，包括查询和移动数据读取位置等。同时允许打开的结果集的最大数量为8个。

KVStoreResultSet实例不会实时刷新。使用结果集后，如果数据库中的数据发生变化（如增删改操作），需要重新查询才能获取到最新的数据。

在调用KVStoreResultSet的方法前，需要先通过[getKVStore](#getkvstore)构建一个SingleKVStore或者DeviceKVStore实例。

> **说明：**
>
> KVStoreResultSet的游标起始位置为-1。

### getCount

getCount(): number

获取结果集中的总行数。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**返回值：**

| 类型   | 说明               |
| ------ | ------------------ |
| number | 返回数据的总行数。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let resultSet: distributedKVStore.KVStoreResultSet;
  let count: number;
  kvStore.getResultSet('batch_test_string_key').then((result: distributedKVStore.KVStoreResultSet) => {
    console.info('getResultSet succeed.');
    resultSet = result;
    count = resultSet.getCount();
    console.info('getCount succeed:' + count);
  }).catch((err: BusinessError) => {
    console.error(`Failed to get resultset. Code: ${err.code}, message: ${err.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to get count. Code: ${error.code}, message: ${error.message}`);
}
```

### getPosition

getPosition(): number

获取结果集中当前的读取位置。读取位置会因[moveToFirst](#movetofirst)、[moveToLast](#movetolast)等操作而发生变化。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**返回值：**

| 类型   | 说明               |
| ------ | ------------------ |
| number | 返回当前读取位置。取值范围>= -1，值为 -1 时表示还未开始读取，值为 0 时表示第一行。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let resultSet: distributedKVStore.KVStoreResultSet;
  let position: number;
  kvStore.getResultSet('batch_test_string_key').then((result: distributedKVStore.KVStoreResultSet) => {
    console.info('getResultSet succeeded.');
    resultSet = result;
    position = resultSet.getPosition();
    console.info('getPosition succeed:' + position);
  }).catch((err: BusinessError) => {
    console.error(`Failed to get resultset. Code: ${err.code}, message: ${err.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to get position. Code: ${error.code}, message: ${error.message}`);
}
```

### moveToFirst

moveToFirst(): boolean

将读取位置移动到第一行。如果结果集为空，则返回false。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**返回值：**

| 类型    | 说明                                            |
| ------- | ----------------------------------------------- |
| boolean | 返回true表示操作成功；返回false则表示操作失败。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let resultSet: distributedKVStore.KVStoreResultSet;
  let moved: boolean;
  kvStore.getResultSet('batch_test_string_key').then((result: distributedKVStore.KVStoreResultSet) => {
    console.info('getResultSet succeed.');
    resultSet = result;
    moved = resultSet.moveToFirst();
    console.info('moveToFirst succeed: ' + moved);
  }).catch((err: BusinessError) => {
    console.error(`Failed to get resultset. Code: ${err.code}, message: ${err.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to move to first. Code: ${error.code}, message: ${error.message}`);
}
```

### moveToLast

moveToLast(): boolean

将读取位置移动到最后一行。如果结果集为空，则返回false。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**返回值：**

| 类型    | 说明                                            |
| ------- | ----------------------------------------------- |
| boolean | 返回true表示操作成功；返回false则表示操作失败。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let resultSet: distributedKVStore.KVStoreResultSet;
  let moved: boolean;
  kvStore.getResultSet('batch_test_string_key').then((result: distributedKVStore.KVStoreResultSet) => {
    console.info('getResultSet succeed.');
    resultSet = result;
    moved = resultSet.moveToLast();
    console.info('moveToLast succeed:' + moved);
  }).catch((err: BusinessError) => {
    console.error(`Failed to get resultset. Code: ${err.code}, message: ${err.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to move to last. Code: ${error.code}, message: ${error.message}`);
}
```

### moveToNext

moveToNext(): boolean

将读取位置移动到下一行。如果结果集为空，则返回false。适用于全量获取数据库结果集的场景。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**返回值：**

| 类型    | 说明                                            |
| ------- | ----------------------------------------------- |
| boolean | 返回true表示操作成功；返回false则表示操作失败。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let resultSet: distributedKVStore.KVStoreResultSet;
  let moved: boolean;
  kvStore.getResultSet('batch_test_string_key').then((result: distributedKVStore.KVStoreResultSet) => {
    console.info('getResultSet succeed.');
    resultSet = result;
    do {
      moved = resultSet.moveToNext();
      console.info('moveToNext succeed: ' + moved);
    } while (moved);
  }).catch((err: BusinessError) => {
    console.error(`Failed to get resultset. Code: ${err.code}, message: ${err.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to move to next. Code: ${error.code}, message: ${error.message}`);
}
```

### moveToPrevious

moveToPrevious(): boolean

将读取位置移动到上一行。如果结果集为空，则返回false。适用于全量获取数据库结果集的场景。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**返回值：**

| 类型    | 说明                                            |
| ------- | ----------------------------------------------- |
| boolean | 返回true表示操作成功；返回false则表示操作失败。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let resultSet: distributedKVStore.KVStoreResultSet;
  let moved: boolean;
  kvStore.getResultSet('batch_test_string_key').then((result: distributedKVStore.KVStoreResultSet) => {
    console.info('getResultSet succeed.');
    resultSet = result;
    moved = resultSet.moveToLast();
    moved = resultSet.moveToPrevious();
    console.info('moveToPrevious succeed:' + moved);
  }).catch((err: BusinessError) => {
    console.error(`Failed to get resultset. Code: ${err.code}, message: ${err.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to move to previous. Code: ${error.code}, message: ${error.message}`);
}
```

### move

move(offset: number): boolean

将读取位置移动到当前位置的相对偏移量。即当前游标位置向下偏移 offset 行。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明                                                         |
| ------ | -------- | ---- | ------------------------------------------------------------ |
| offset | number   | 是   | 表示与当前位置的相对偏移量，正偏移表示向结果集末尾方向移动（行号增大），负偏移表示向结果集起始方向移动（行号减小）。当游标超出结果集最前或者最后的位置时，接口返回false。|

**返回值：**

| 类型    | 说明                                            |
| ------- | ----------------------------------------------- |
| boolean | 返回true表示操作成功；返回false则表示操作失败。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息** |
| ------------ | ------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let resultSet: distributedKVStore.KVStoreResultSet;
  let moved: boolean;
  kvStore.getResultSet('batch_test_string_key').then((result: distributedKVStore.KVStoreResultSet) => {
    console.info('Succeeded in getting resultSet');
    resultSet = result;
    moved = resultSet.move(2); // 若当前位置为0，将读取位置从绝对位置为0的位置移动2行，即移动到绝对位置为2，行数为3的位置
    console.info(`Succeeded in moving.moved = ${moved}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to get resultSet. Code: ${err.code}, message: ${err.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to move. Code: ${error.code}, message: ${error.message}`);
}
```

### moveToPosition

moveToPosition(position: number): boolean

将读取位置从 0 移动到绝对位置。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名   | 类型 | 必填 | 说明           |
| -------- | -------- | ---- | -------------- |
| position | number   | 是   | 表示绝对位置。当绝对位置超出结果集最前或者最后的位置时，接口返回false。|

**返回值：**

| 类型    | 说明                                            |
| ------- | ----------------------------------------------- |
| boolean | 返回true表示操作成功；返回false则表示操作失败。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息** |
| ------------ | ------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let resultSet: distributedKVStore.KVStoreResultSet;
  let moved: boolean;
  kvStore.getResultSet('batch_test_string_key').then((result: distributedKVStore.KVStoreResultSet) => {
    console.info('Succeeded in getting resultSet');
    resultSet = result;
    moved = resultSet.moveToPosition(1);
    console.info(`Succeeded in moving to position.moved=${moved}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to get resultSet. Code: ${err.code}, message: ${err.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to move to position. Code: ${error.code}, message: ${error.message}`);
}
```

### isFirst

isFirst(): boolean

检查读取位置是否为第一行。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 返回true表示读取位置为第一行；返回false表示读取位置不是第一行。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let resultSet: distributedKVStore.KVStoreResultSet;
  let isFirst: boolean;
  kvStore.getResultSet('batch_test_string_key').then((result: distributedKVStore.KVStoreResultSet) => {
    console.info('getResultSet succeed.');
    resultSet = result;
    isFirst = resultSet.isFirst();
    console.info('Check isFirst succeed:' + isFirst);
  }).catch((err: BusinessError) => {
    console.error(`Failed to get resultset. Code: ${err.code}, message: ${err.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to check isFirst. Code: ${error.code}, message: ${error.message}`);
}
```

### isLast

isLast(): boolean

检查读取位置是否为最后一行。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 返回true表示读取位置为最后一行；返回false表示读取位置不是最后一行。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let resultSet: distributedKVStore.KVStoreResultSet;
  let isLast: boolean;
  kvStore.getResultSet('batch_test_string_key').then((result: distributedKVStore.KVStoreResultSet) => {
    console.info('getResultSet succeed.');
    resultSet = result;
    isLast = resultSet.isLast();
    console.info('Check isLast succeed: ' + isLast);
  }).catch((err: BusinessError) => {
    console.error(`Failed to get resultset. Code: ${err.code}, message: ${err.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to check isLast. Code: ${error.code}, message: ${error.message}`);
}
```

### isBeforeFirst

isBeforeFirst(): boolean

检查读取位置是否在第一行之前。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 返回true表示读取位置在第一行之前；返回false表示读取位置不在第一行之前。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let resultSet: distributedKVStore.KVStoreResultSet;
  kvStore.getResultSet('batch_test_string_key').then((result: distributedKVStore.KVStoreResultSet) => {
    console.info('getResultSet succeed.');
    resultSet = result;
    let isBeforeFirst = resultSet.isBeforeFirst();
    console.info('Check isBeforeFirst succeed: ' + isBeforeFirst);
  }).catch((err: BusinessError) => {
    console.error(`Failed to get resultset. Code: ${err.code}, message: ${err.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to check isBeforeFirst. Code: ${error.code}, message: ${error.message}`);
}
```

### isAfterLast

isAfterLast(): boolean

检查读取位置是否在最后一行之后。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 返回true表示读取位置在最后一行之后；返回false表示读取位置不在最后一行之后。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let resultSet: distributedKVStore.KVStoreResultSet;
  kvStore.getResultSet('batch_test_string_key').then((result: distributedKVStore.KVStoreResultSet) => {
    console.info('getResultSet succeed.');
    resultSet = result;
    let isAfterLast = resultSet.isAfterLast();
    console.info('Check isAfterLast succeed:' + isAfterLast);
  }).catch((err: BusinessError) => {
    console.error(`Failed to get resultset. Code: ${err.code}, message: ${err.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to check isAfterLast. Code: ${error.code}, message: ${error.message}`);
}
```

### getEntry

getEntry(): Entry

从当前位置获取对应的键值对。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**返回值：**

| 类型            | 说明         |
| --------------- | ------------ |
| [Entry](#entry) | 返回键值对。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let resultSet: distributedKVStore.KVStoreResultSet;
  kvStore.getResultSet('batch_test_string_key').then((result: distributedKVStore.KVStoreResultSet) => {
    console.info('getResultSet succeed.');
    resultSet = result;
    let entry = resultSet.getEntry();
    console.info('getEntry succeed:' + JSON.stringify(entry));
  }).catch((err: BusinessError) => {
    console.error(`Failed to get resultset. Code: ${err.code}, message: ${err.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to get entry. Code: ${error.code}, message: ${error.message}`);
}
```

## Query

使用谓词表示数据库查询，提供创建Query实例、查询数据库中的数据和添加谓词的方法。Query对象的谓词方法均返回自身，支持链式调用。一个Query对象中谓词数量上限为256个。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

### constructor

constructor()

用于创建Query实例的构造函数。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

### reset

reset(): Query

重置Query对象。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**返回值：**

| 类型           | 说明                  |
| -------------- | --------------------- |
| [Query](#query) | 返回重置后的Query对象，所有已添加的谓词条件被清空，可用于重新构建查询条件。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let query: distributedKVStore.Query | null = new distributedKVStore.Query();
  if (query != null) {
    query.equalTo('key', 'value');
    console.info('query is ' + query.getSqlLike());
    query.reset();
    console.info('query is ' + query.getSqlLike());
  }
  query = null;
} catch (err) {
  let error = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### equalTo

equalTo(field: string, value: number | string | boolean): Query

构造一个Query对象来查询具有指定字段的条目，其值等于指定的值。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

> **说明：**
>
> 使用equalTo时需要结合[Schema](#schema)使用。
>
> 使用Schema创建数据库请参见[通过键值型数据库实现数据持久化](../../database/data-persistence-by-kv-store.md#开发步骤)中使用getKVStore()方法创建并获取键值数据库示例。

**参数：**

| 参数名  | 类型 | 必填  | 说明                    |
| -----  | ------  | ----  | ----------------------- |
| field  | string  | 是    |表示指定字段，不能包含'^'。包含'^'将导致谓词失效，查询结果会返回数据库中的所有数据。 |
| value  | number \| string \| boolean  | 是    | 表示指定字段要匹配的值，值的类型应与Schema中定义的字段类型一致。|

**返回值：**

| 类型           | 说明            |
| -------------- | --------------- |
| [Query](#query) | 返回Query对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息** |
| ------------ | ------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let query: distributedKVStore.Query | null = new distributedKVStore.Query();
  if (query != null) {
    query.equalTo('field', 'value');
    console.info(`query is ${query.getSqlLike()}`);
  }
  query = null;
} catch (err) {
  let error = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### notEqualTo

notEqualTo(field: string, value: number | string | boolean): Query

构造一个Query对象以查询具有指定字段且值不等于指定值的条目。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

> **说明：**
>
> 使用notEqualTo时需要结合[Schema](#schema)使用。
>
> 使用Schema创建数据库请参见[通过键值型数据库实现数据持久化](../../database/data-persistence-by-kv-store.md#开发步骤)中使用getKVStore()方法创建并获取键值数据库示例。

**参数：**

| 参数名  | 类型 | 必填  | 说明                    |
| -----  | ------  | ----  | ----------------------- |
| field  | string  | 是    |表示指定字段，不能包含'^'。包含'^'将导致谓词失效，查询结果会返回数据库中的所有数据。  |
| value  | number \| string \| boolean  | 是    | 表示指定字段要匹配的值，值的类型应与Schema中定义的字段类型一致。|

**返回值：**

| 类型           | 说明            |
| -------------- | --------------- |
| [Query](#query) | 返回Query对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息** |
| ------------ | ------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let query: distributedKVStore.Query | null = new distributedKVStore.Query();
  if (query != null) {
    query.notEqualTo('field', 'value');
    console.info(`query is ${query.getSqlLike()}`);
  }
  query = null;
} catch (err) {
  let error = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### greaterThan

greaterThan(field: string, value: number | string | boolean): Query

构造一个Query对象以查询具有大于指定值的指定字段的条目。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

> **说明：**
>
> 使用greaterThan时需要结合[Schema](#schema)使用。
>
> 使用Schema创建数据库请参见[通过键值型数据库实现数据持久化](../../database/data-persistence-by-kv-store.md#开发步骤)中使用getKVStore()方法创建并获取键值数据库示例。

**参数：**
| 参数名  | 类型 | 必填  | 说明                    |
| -----  | ------  | ----  | ----------------------- |
| field  | string  | 是    |表示指定字段，不能包含'^'。包含'^'将导致谓词失效，查询结果会返回数据库中的所有数据。  |
| value  | number \| string \| boolean  | 是    | 表示指定字段要匹配的值，值的类型应与Schema中定义的字段类型一致。|

**返回值：**

| 类型           | 说明            |
| -------------- | --------------- |
| [Query](#query) | 返回Query对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息** |
| ------------ | ------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
    let query: distributedKVStore.Query | null = new distributedKVStore.Query();
    if (query != null) {
      query.greaterThan('field', 'value');
      console.info(`query is ${query.getSqlLike()}`);
    }
    query = null;
} catch (err) {
    let error = err as BusinessError;
    console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### lessThan

lessThan(field: string, value: number | string): Query

构造一个Query对象以查询具有小于指定值的指定字段的条目。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

> **说明：**
>
> 使用lessThan时需要结合[Schema](#schema)使用。
>
> 使用Schema创建数据库请参见[通过键值型数据库实现数据持久化](../../database/data-persistence-by-kv-store.md#开发步骤)中使用getKVStore()方法创建并获取键值数据库示例。

**参数：**


| 参数名  | 类型 | 必填  | 说明                    |
| -----  | ------  | ----  | ----------------------- |
| field  | string  | 是    |表示指定字段，不能包含'^'。包含'^'将导致谓词失效，查询结果会返回数据库中的所有数据。  |
| value  | number \| string  | 是    | 表示指定字段要匹配的值，值的类型应与Schema中定义的字段类型一致。|

**返回值：**

| 类型           | 说明            |
| -------------- | --------------- |
| [Query](#query) | 返回Query对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息** |
| ------------ | ------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
    let query: distributedKVStore.Query | null = new distributedKVStore.Query();
    if (query != null) {
      query.lessThan('field', 'value');
      console.info(`query is ${query.getSqlLike()}`);
    }
    query = null;
} catch (err) {
    let error = err as BusinessError;
    console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### greaterThanOrEqualTo

greaterThanOrEqualTo(field: string, value: number | string): Query

构造一个Query对象以查询具有指定字段且值大于或等于指定值的条目。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

> **说明：**
>
> 使用greaterThanOrEqualTo时需要结合[Schema](#schema)使用。
>
> 使用Schema创建数据库请参见[通过键值型数据库实现数据持久化](../../database/data-persistence-by-kv-store.md#开发步骤)中使用getKVStore()方法创建并获取键值数据库示例。

**参数：**


| 参数名  | 类型 | 必填  | 说明                    |
| -----  | ------  | ----  | ----------------------- |
| field  | string  | 是    |表示指定字段，不能包含'^'。包含'^'将导致谓词失效，查询结果会返回数据库中的所有数据。  |
| value  | number \| string  | 是    | 表示指定字段要匹配的值，值的类型应与Schema中定义的字段类型一致。|

**返回值：**

| 类型           | 说明            |
| -------------- | --------------- |
| [Query](#query) | 返回Query对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息** |
| ------------ | ------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
    let query: distributedKVStore.Query | null = new distributedKVStore.Query();
    if (query != null) {
      query.greaterThanOrEqualTo('field', 'value');
      console.info(`query is ${query.getSqlLike()}`);
    }
    query = null;
} catch (err) {
    let error = err as BusinessError;
    console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### lessThanOrEqualTo

lessThanOrEqualTo(field: string, value: number | string): Query

构造一个Query对象以查询具有指定字段且值小于或等于指定值的条目。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

> **说明：**
>
> 使用lessThanOrEqualTo时需要结合[Schema](#schema)使用。
>
> 使用Schema创建数据库请参见[通过键值型数据库实现数据持久化](../../database/data-persistence-by-kv-store.md#开发步骤)中使用getKVStore()方法创建并获取键值数据库示例。

**参数：**


| 参数名  | 类型 | 必填  | 说明                    |
| -----  | ------  | ----  | ----------------------- |
| field  | string  | 是    |表示指定字段，不能包含'^'。包含'^'将导致谓词失效，查询结果会返回数据库中的所有数据。  |
| value  | number \| string  | 是    | 表示指定字段要匹配的值，值的类型应与Schema中定义的字段类型一致。|

**返回值：**

| 类型           | 说明            |
| -------------- | --------------- |
| [Query](#query) | 返回Query对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息** |
| ------------ | ------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
    let query: distributedKVStore.Query | null = new distributedKVStore.Query();
    if (query != null) {
      query.lessThanOrEqualTo('field', 'value');
      console.info(`query is ${query.getSqlLike()}`);
    }
    query = null;
} catch (err) {
    let error = err as BusinessError;
    console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### isNull

isNull(field: string): Query

构造一个Query对象以查询具有值为null的指定字段的条目。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

> **说明：**
>
> 使用isNull时需要结合[Schema](#schema)使用。
>
> 使用Schema创建数据库请参见[通过键值型数据库实现数据持久化](../../database/data-persistence-by-kv-store.md#开发步骤)中使用getKVStore()方法创建并获取键值数据库示例。

**参数：**

| 参数名 | 类型 | 必填 | 说明                          |
| ------ | -------- | ---- | ----------------------------- |
| field  | string   | 是   | 表示指定字段，不能包含'^'。包含'^'将导致谓词失效，查询结果会返回数据库中的所有数据。 |

**返回值：**

| 类型           | 说明            |
| -------------- | --------------- |
| [Query](#query) | 返回Query对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息** |
| ------------ | ------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
    let query: distributedKVStore.Query | null = new distributedKVStore.Query();
    if (query != null) {
      query.isNull('field');
      console.info(`query is ${query.getSqlLike()}`);
    }
    query = null;
} catch (err) {
    let error = err as BusinessError;
    console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### inNumber

inNumber(field: string, valueList: number[]): Query

构造一个Query对象以查询具有指定字段的条目，其值在指定的值列表中。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

> **说明：**
>
> 使用inNumber时需要结合[Schema](#schema)使用。
>
> 使用Schema创建数据库请参见[通过键值型数据库实现数据持久化](../../database/data-persistence-by-kv-store.md#开发步骤)中使用getKVStore()方法创建并获取键值数据库示例。

**参数：**

| 参数名    | 类型 | 必填 | 说明                          |
| --------- | -------- | ---- | ----------------------------- |
| field     | string   | 是   | 表示指定字段，不能包含'^'。包含'^'将导致谓词失效，查询结果会返回数据库中的所有数据。 |
| valueList | number[] | 是   | 表示指定的值列表。            |

**返回值：**

| 类型           | 说明            |
| -------------- | --------------- |
| [Query](#query) | 返回Query对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息** |
| ------------ | ------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
    let query: distributedKVStore.Query | null = new distributedKVStore.Query();
    if (query != null) {
      query.inNumber('field', [0, 1]);
      console.info(`query is ${query.getSqlLike()}`);
    }
    query = null;
} catch (err) {
    let error = err as BusinessError;
    console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### inString

inString(field: string, valueList: string[]): Query

构造一个Query对象以查询具有指定字段的条目，其值在指定的字符串值列表中。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

> **说明：**
>
> 使用inString时需要结合[Schema](#schema)使用。
>
> 使用Schema创建数据库请参见[通过键值型数据库实现数据持久化](../../database/data-persistence-by-kv-store.md#开发步骤)中使用getKVStore()方法创建并获取键值数据库示例。

**参数：**

| 参数名    | 类型 | 必填 | 说明                          |
| --------- | -------- | ---- | ----------------------------- |
| field     | string   | 是   | 表示指定字段，不能包含'^'。包含'^'将导致谓词失效，查询结果会返回数据库中的所有数据。 |
| valueList | string[] | 是   | 表示指定的字符串值列表。      |

**返回值：**

| 类型           | 说明            |
| -------------- | --------------- |
| [Query](#query) | 返回Query对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息** |
| ------------ | ------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
    let query: distributedKVStore.Query | null = new distributedKVStore.Query();
    if (query != null) {
      query.inString('field', ['test1', 'test2']);
      console.info(`query is ${query.getSqlLike()}`);
    }
    query = null;
} catch (err) {
    let error = err as BusinessError;
    console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### notInNumber

notInNumber(field: string, valueList: number[]): Query

构造一个Query对象以查询具有指定字段的条目，该字段的值不在指定的值列表中。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

> **说明：**
>
> 使用notInNumber时需要结合[Schema](#schema)使用。
>
> 使用Schema创建数据库请参见[通过键值型数据库实现数据持久化](../../database/data-persistence-by-kv-store.md#开发步骤)中使用getKVStore()方法创建并获取键值数据库示例。

**参数：**

| 参数名    | 类型 | 必填 | 说明                          |
| --------- | -------- | ---- | ----------------------------- |
| field     | string   | 是   | 表示指定字段，不能包含'^'。包含'^'将导致谓词失效，查询结果会返回数据库中的所有数据。 |
| valueList | number[] | 是   | 表示指定的值列表。            |

**返回值：**

| 类型           | 说明            |
| -------------- | --------------- |
| [Query](#query) | 返回Query对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息** |
| ------------ | ------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
    let query: distributedKVStore.Query | null = new distributedKVStore.Query();
    if (query != null) {
      query.notInNumber('field', [0, 1]);
      console.info(`query is ${query.getSqlLike()}`);
    }
    query = null;
} catch (err) {
    let error = err as BusinessError;
    console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### notInString

notInString(field: string, valueList: string[]): Query

构造一个Query对象以查询具有指定字段且值不在指定字符串值列表中的条目。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

> **说明：**
>
> 使用notInString时需要结合[Schema](#schema)使用。
>
> 使用Schema创建数据库请参见[通过键值型数据库实现数据持久化](../../database/data-persistence-by-kv-store.md#开发步骤)中使用getKVStore()方法创建并获取键值数据库示例。

**参数：**

| 参数名    | 类型 | 必填 | 说明                          |
| --------- | -------- | ---- | ----------------------------- |
| field     | string   | 是   | 表示指定字段，不能包含'^'。包含'^'将导致谓词失效，查询结果会返回数据库中的所有数据。 |
| valueList | string[] | 是   | 表示指定的字符串值列表。      |

**返回值：**

| 类型           | 说明            |
| -------------- | --------------- |
| [Query](#query) | 返回Query对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息** |
| ------------ | ------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
    let query: distributedKVStore.Query | null = new distributedKVStore.Query();
    if (query != null) {
      query.notInString('field', ['test1', 'test2']);
      console.info(`query is ${query.getSqlLike()}`);
    }
    query = null;
} catch (err) {
    let error = err as BusinessError;
    console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### like

like(field: string, value: string): Query

构造一个Query对象以查询具有与指定字符串值相似的指定字段的条目。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

> **说明：**
>
> 使用like时需要结合[Schema](#schema)使用。
>
> 使用Schema创建数据库请参见[通过键值型数据库实现数据持久化](../../database/data-persistence-by-kv-store.md#开发步骤)中使用getKVStore()方法创建并获取键值数据库示例。

**参数：**

| 参数名 | 类型 | 必填 | 说明                          |
| ------ | -------- | ---- | ----------------------------- |
| field  | string   | 是   | 表示指定字段，不能包含'^'。包含'^'将导致谓词失效，查询结果会返回数据库中的所有数据。 |
| value  | string   | 是   | 表示指定字段要匹配的字符串值。          |

**返回值：**

| 类型           | 说明            |
| -------------- | --------------- |
| [Query](#query) | 返回Query对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息** |
| ------------ | ------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
    let query: distributedKVStore.Query | null = new distributedKVStore.Query();
    if (query != null) {
      query.like('field', 'value');
      console.info(`query is ${query.getSqlLike()}`);
    }
    query = null;
} catch (err) {
    let error = err as BusinessError;
    console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### unlike

unlike(field: string, value: string): Query

构造一个Query对象以查询具有与指定字符串值不相似的指定字段的条目。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

> **说明：**
>
> 使用unlike时需要结合[Schema](#schema)使用。
>
> 使用Schema创建数据库请参见[通过键值型数据库实现数据持久化](../../database/data-persistence-by-kv-store.md#开发步骤)中使用getKVStore()方法创建并获取键值数据库示例。

**参数：**

| 参数名 | 类型 | 必填 | 说明                          |
| ------ | -------- | ---- | ----------------------------- |
| field  | string   | 是   | 表示指定字段，不能包含'^'。包含'^'将导致谓词失效，查询结果会返回数据库中的所有数据。 |
| value  | string   | 是   | 表示指定字段要不匹配的字符串值。       |

**返回值：**

| 类型           | 说明            |
| -------------- | --------------- |
| [Query](#query) | 返回Query对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息** |
| ------------ | ------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
    let query: distributedKVStore.Query | null = new distributedKVStore.Query();
    if (query != null) {
      query.unlike('field', 'value');
      console.info(`query is ${query.getSqlLike()}`);
    }
    query = null;
} catch (err) {
    let error = err as BusinessError;
    console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### and

and(): Query

构造一个带有与条件的查询对象。需先通过equalTo、notEqualTo等谓词方法添加查询条件后，再调用and()连接多个条件，无前置谓词时调用and()无效。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**返回值：**

| 类型           | 说明           |
| -------------- | -------------- |
| [Query](#query) | 返回查询对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
    let query: distributedKVStore.Query | null = new distributedKVStore.Query();
    if (query != null) {
      query.notEqualTo('field', 'value1');
      query.and();
      query.notEqualTo('field', 'value2');
      console.info('query is ' + query.getSqlLike());
    }
    query = null;
} catch (err) {
    let error = err as BusinessError;
    console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### or

or(): Query

构造一个带有或条件的Query对象。需先通过equalTo、notEqualTo等谓词方法添加查询条件后，再调用or()连接多个条件，无前置谓词时调用or()无效。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**返回值：**

| 类型           | 说明           |
| -------------- | -------------- |
| [Query](#query) | 返回查询对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
    let query: distributedKVStore.Query | null = new distributedKVStore.Query();
    if (query != null) {
      query.notEqualTo('field', 'value1');
      query.or();
      query.notEqualTo('field', 'value2');
      console.info('query is ' + query.getSqlLike());
    }
    query = null;
} catch (err) {
    let error = err as BusinessError;
    console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### orderByAsc

orderByAsc(field: string): Query

构造一个Query对象，将查询结果按升序排序。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

> **说明：**
>
> 使用orderByAsc时需要结合[Schema](#schema)使用。
>
> 使用Schema创建数据库请参见[通过键值型数据库实现数据持久化](../../database/data-persistence-by-kv-store.md#开发步骤)中使用getKVStore()方法创建并获取键值数据库示例。

**参数：**

| 参数名 | 类型 | 必填 | 说明                          |
| ------ | -------- | ---- | ----------------------------- |
| field  | string   | 是   | 表示指定字段，不能包含'^'。包含'^'将导致谓词失效，查询结果会返回数据库中的所有数据。 |

**返回值：**

| 类型           | 说明            |
| -------------- | --------------- |
| [Query](#query) | 返回Query对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息** |
| ------------ | ------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
    let query: distributedKVStore.Query | null = new distributedKVStore.Query();
    if (query != null) {
      query.notEqualTo('field', 'value');
      query.orderByAsc('field');
      console.info(`query is ${query.getSqlLike()}`);
    }
    query = null;
} catch (err) {
    let error = err as BusinessError;
    console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### orderByDesc

orderByDesc(field: string): Query

构造一个Query对象，将查询结果按降序排序。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

> **说明：**
>
> 使用orderByDesc时需要结合[Schema](#schema)使用。
>
> 使用Schema创建数据库请参见[通过键值型数据库实现数据持久化](../../database/data-persistence-by-kv-store.md#开发步骤)中使用getKVStore()方法创建并获取键值数据库示例。

**参数：**

| 参数名 | 类型 | 必填 | 说明                          |
| ------ | -------- | ---- | ----------------------------- |
| field  | string   | 是   | 表示指定字段，不能包含'^'。包含'^'将导致谓词失效，查询结果会返回数据库中的所有数据。 |

**返回值：**

| 类型           | 说明            |
| -------------- | --------------- |
| [Query](#query) | 返回Query对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息** |
| ------------ | ------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
    let query: distributedKVStore.Query | null = new distributedKVStore.Query();
    if (query != null) {
      query.notEqualTo('field', 'value');
      query.orderByDesc('field');
      console.info(`query is ${query.getSqlLike()}`);
    }
    query = null;
} catch (err) {
    let error = err as BusinessError;
    console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### limit

limit(total: number, offset: number): Query

构造一个Query对象来指定结果的数量和开始位置。该接口必须要在Query对象查询和升降序等操作之后调用，调用limit接口后，不可再对Query对象进行查询和升降序等操作。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明               |
| ------ | -------- | ---- |------------------|
| total  | number   | 是   | 表示最大数据记录数。<br/>取值为非负整数时表示指定的最大记录数。<br/>取值为负数时，表示查询整个结果集。|
| offset | number   | 是   | 指定查询结果的起始位置。取值为非负整数时表示指定的起始位置；取值为负数时，表示查询整个结果集。当offset超出结果集最后位置时，查询结果为空。|

**返回值：**

| 类型           | 说明            |
| -------------- | --------------- |
| [Query](#query) | 返回Query对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息** |
| ------------ | ------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let total = 10;
let offset = 1;
try {
  let query: distributedKVStore.Query | null = new distributedKVStore.Query();
  if (query != null) {
    query.notEqualTo('field', 'value');
    query.limit(total, offset);
    console.info(`query is ${query.getSqlLike()}`);
  }
  query = null;
} catch (err) {
  let error = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### isNotNull

isNotNull(field: string): Query

构造一个Query对象以查询具有值不为null的指定字段的条目。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

> **说明：**
>
> 使用isNotNull时需要结合[Schema](#schema)使用。
>
> 使用Schema创建数据库请参见[通过键值型数据库实现数据持久化](../../database/data-persistence-by-kv-store.md#开发步骤)中使用getKVStore()方法创建并获取键值数据库示例。

**参数：**

| 参数名 | 类型 | 必填 | 说明                          |
| ------ | -------- | ---- | ----------------------------- |
| field  | string   | 是   | 表示指定字段，不能包含'^'。包含'^'将导致谓词失效，查询结果会返回数据库中的所有数据。 |

**返回值：**

| 类型           | 说明            |
| -------------- | --------------- |
| [Query](#query) | 返回Query对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息** |
| ------------ | ------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let query: distributedKVStore.Query | null = new distributedKVStore.Query();
  if (query != null) {
    query.isNotNull('field');
    console.info(`query is ${query.getSqlLike()}`);
  }
  query = null;
} catch (err) {
  let error = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### beginGroup

beginGroup(): Query

创建一个带有左括号的查询条件组。必须与[endGroup()](#endgroup)成对使用，以形成完整的查询条件分组。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**返回值：**

| 类型           | 说明            |
| -------------- | --------------- |
| [Query](#query) | 返回Query对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
    let query: distributedKVStore.Query | null = new distributedKVStore.Query();
    if (query != null) {
      query.beginGroup();
      query.isNotNull('field');
      query.endGroup();
      console.info('query is ' + query.getSqlLike());
    }
    query = null;
} catch (err) {
    let error = err as BusinessError;
    console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### endGroup

endGroup(): Query

创建一个带有右括号的查询条件组。必须与[beginGroup()](#begingroup)成对使用，以形成完整的查询条件分组。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**返回值：**

| 类型           | 说明            |
| -------------- | --------------- |
| [Query](#query) | 返回Query对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
    let query: distributedKVStore.Query | null = new distributedKVStore.Query();
    if (query != null) {
      query.beginGroup();
      query.isNotNull('field');
      query.endGroup();
      console.info('query is ' + query.getSqlLike());
    }
    query = null;
} catch (err) {
    let error = err as BusinessError;
    console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### prefixKey

prefixKey(prefix: string): Query

创建具有指定键前缀的查询条件。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明               |
| ------ | -------- | ---- | ------------------ |
| prefix | string   | 是   | 表示指定的键前缀，长度范围为0-[MAX_KEY_LENGTH](#constants)，不能包含'^'。包含'^'将导致谓词失效，查询结果会返回数据库中的所有数据。 |

**返回值：**

| 类型           | 说明            |
| -------------- | --------------- |
| [Query](#query) | 返回Query对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息** |
| ------------ | ------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
    let query: distributedKVStore.Query | null = new distributedKVStore.Query();
    if (query != null) {
      query.prefixKey('$.name');
      query.prefixKey('0');
      console.info(`query is ${query.getSqlLike()}`);
    }
    query = null;
} catch (err) {
    let error = err as BusinessError;
    console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### setSuggestIndex

setSuggestIndex(index: string): Query

设置一个指定的索引，将优先用于查询。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明               |
| ------ | -------- | ---- | ------------------ |
| index  | string   | 是   | 表示要设置的索引，不能包含'^'。包含'^'将导致谓词失效，查询结果会返回数据库中的所有数据。 |

**返回值：**

| 类型           | 说明            |
| -------------- | --------------- |
| [Query](#query) | 返回Query对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息** |
| ------------ | ------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
    let query: distributedKVStore.Query | null = new distributedKVStore.Query();
    if (query != null) {
      query.setSuggestIndex('$.name');
      query.setSuggestIndex('0');
      console.info(`query is ${query.getSqlLike()}`);
    }
    query = null;
} catch (err) {
    let error = err as BusinessError;
    console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### deviceId

deviceId(deviceId:string):Query

添加设备ID作为Key的前缀。
> **说明：**
>
> 其中deviceId为[DeviceBasicInfo](../apis-distributedservice-kit/js-apis-distributedDeviceManager.md#devicebasicinfo)中的networkId，通过调用[deviceManager.getAvailableDeviceListSync](../apis-distributedservice-kit/js-apis-distributedDeviceManager.md#getavailabledevicelistsync)方法得到。
> deviceId具体获取方式请参考[sync接口示例](#sync)。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名   | 类型 | 必填 | 说明               |
| -------- | -------- | ---- | ------------------ |
| deviceId | string   | 是   | 设备的networkId，标识要查询其数据的设备，不能为空。 |

**返回值：**

| 类型           | 说明            |
| -------------- | --------------- |
| [Query](#query) | 返回Query对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息** |
| ------------ | ------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
    let query: distributedKVStore.Query | null = new distributedKVStore.Query();
    if (query != null) {
      query.deviceId('deviceId');
      console.info(`query is ${query.getSqlLike()}`);
    }
} catch (err) {
    let error = err as BusinessError;
    console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### getSqlLike

getSqlLike():string

获取Query对象的查询语句。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**返回值：**

| 类型   | 说明                                 |
| ------ | ------------------------------------ |
| string | 返回Query对象构建的查询语句字符串，可用于查看和调试当前的查询条件。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
    let query: distributedKVStore.Query | null = new distributedKVStore.Query();
    if (query != null) {
      let sql1 = query.getSqlLike();
      console.info(`GetSqlLike sql= ${sql1}`);
    }
} catch (err) {
    let error = err as BusinessError;
    console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

## SingleKVStore

SingleKVStore数据库实例，提供增加数据、删除数据和订阅数据变更、订阅数据端端同步完成的方法。

在调用SingleKVStore的方法前，需要先通过[getKVStore](#getkvstore)构建一个SingleKVStore实例。

### put

put(key: string, value: Uint8Array | string | number | boolean, callback: AsyncCallback&lt;void&gt;): void

添加指定类型键值对到数据库，使用callback异步回调。若Key已存在则更新对应Value；若已订阅数据变更通知，将触发变更通知回调。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名  | 类型 | 必填  | 说明                                                                                                     |
| -----  | ------  | ----  |--------------------------------------------------------------------------------------------------------|
| key    | string  | 是    | 要添加数据的Key，不能为空且长度范围为1-[MAX_KEY_LENGTH](#constants)。                                                     |
| value  | Uint8Array \| string \| number \| boolean | 是    | 要添加数据的value，支持Uint8Array、string、number、boolean，Uint8Array、string的长度范围为0-[MAX_VALUE_LENGTH](#constants)。 |
| callback | AsyncCallback&lt;void&gt; | 是    | 回调函数。数据添加成功，err为undefined，否则为错误对象。                                                                     |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)和[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                             |
| ------------ | ---------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed.  |
| 15100003     | Database corrupted.                      |
| 15100005     | Database or result set already closed.   |

以下错误码的详细介绍请参见[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                 |
| ------------ | -------------------------------------------- |
| 14800047     | The WAL file size exceeds the default limit.<br/>适用版本：10+ |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const KEY_TEST_STRING_ELEMENT = 'key_test_string';
const VALUE_TEST_STRING_ELEMENT = 'value-test-string';
try {
  kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to put. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in putting');
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### put

put(key: string, value: Uint8Array | string | number | boolean): Promise&lt;void&gt;

添加指定类型键值对到数据库，使用Promise异步回调。若Key已存在则更新对应Value；若已订阅数据变更通知，将触发变更通知回调。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名  | 类型 | 必填  | 说明                                                                                                     |
| -----  | ------  | ----  |--------------------------------------------------------------------------------------------------------|
| key    | string  | 是    | 要添加数据的Key，不能为空且长度范围为1-[MAX_KEY_LENGTH](#constants)。                                                     |
| value  | Uint8Array \| string \| number \| boolean | 是    | 要添加数据的value，支持Uint8Array、string、number、boolean，Uint8Array、string的长度范围为0-[MAX_VALUE_LENGTH](#constants)。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)和[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                             |
| ------------ | ---------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed.  |
| 15100003     | Database corrupted.                      |
| 15100005     | Database or result set already closed.   |

以下错误码的详细介绍请参见[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                 |
| ------------ | -------------------------------------------- |
| 14800047     | The WAL file size exceeds the default limit.<br/>适用版本：10+ |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const KEY_TEST_STRING_ELEMENT = 'key_test_string';
const VALUE_TEST_STRING_ELEMENT = 'value-test-string';
try {
  kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT).then(() => {
    console.info(`Succeeded in putting data`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to put. Code: ${err.code}, message: ${err.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### putBatch

putBatch(entries: Entry[], callback: AsyncCallback&lt;void&gt;): void

批量插入键值对到SingleKVStore数据库中，使用callback异步回调。若Key已存在则更新对应Value；若已订阅数据变更通知，将触发变更通知回调。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                     |
| -------- | ------------------------ | ---- | ------------------------ |
| entries  | [Entry](#entry)[]        | 是   | 表示要批量插入的键值对。一个entries对象中允许的最大数据量为512MB。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。数据批量插入成功，err为undefined，否则为错误对象。   |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)和[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                             |
| ------------ | ---------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.|
| 15100003     | Database corrupted.                      |
| 15100005     | Database or result set already closed.   |

以下错误码的详细介绍请参见[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                 |
| ------------ | -------------------------------------------- |
| 14800047     | The WAL file size exceeds the default limit.<br/>适用版本：10+ |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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
  kvStore.putBatch(entries, async (err: BusinessError) => {
    if (err) {
      console.error(`Failed to put Batch. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in putting Batch');
    if (kvStore != null) {
      kvStore.getEntries('batch_test_string_key', (err: BusinessError, entries: distributedKVStore.Entry[]) => {
        if (err) {
          console.error(`Failed to get Entries. Code: ${err.code}, message: ${err.message}`);
          return;
        }
        console.info('Succeeded in getting Entries');
        console.info(`entries.length: ${entries.length}`);
        console.info(`entries[0]: ${entries[0]}`);
      });
    } else {
      console.error('KvStore is null'); // 后续示例代码与此处保持一致
    }
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### putBatch

putBatch(entries: Entry[]): Promise&lt;void&gt;

批量插入键值对到SingleKVStore数据库中，使用Promise异步回调。若Key已存在则更新对应Value；若已订阅数据变更通知，将触发变更通知回调。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名  | 类型          | 必填 | 说明                     |
| ------- | ----------------- | ---- | ------------------------ |
| entries | [Entry](#entry)[] | 是   | 表示要批量插入的键值对。一个entries对象中允许的最大数据量为512MB。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)和[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                             |
| ------------ | ---------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.|
| 15100003     | Database corrupted.                      |
| 15100005     | Database or result set already closed.   |

以下错误码的详细介绍请参见[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                 |
| ------------ | -------------------------------------------- |
| 14800047     | The WAL file size exceeds the default limit.<br/>适用版本：10+ |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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
    if (kvStore != null) {
      kvStore.getEntries('batch_test_string_key').then((entries: distributedKVStore.Entry[]) => {
        console.info('Succeeded in getting Entries');
        console.info(`PutBatch ${entries}`);
      }).catch((err: BusinessError) => {
        console.error(`Failed to get Entries. Code: ${err.code}, message: ${err.message}`);
      });
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to put Batch. Code: ${err.code}, message: ${err.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### delete

delete(key: string, callback: AsyncCallback&lt;void&gt;): void

从数据库中删除指定键值的数据，使用callback异步回调。删除成功后，指定键值对将被永久删除，无法再通过get等方法查询；若已订阅数据变更通知，将触发变更通知回调。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名   | 类型                  | 必填 | 说明                                                         |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| key      | string                    | 是   | 要删除数据的Key，不能为空且长度范围为1-[MAX_KEY_LENGTH](#constants)。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。删除指定的数据成功，err为undefined，否则为错误对象。         |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)和[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed.  |
| 15100003     | Database corrupted.                    |
| 15100005    | Database or result set already closed. |

以下错误码的详细介绍请参见[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                 |
| ------------ | -------------------------------------------- |
| 14800047     | The WAL file size exceeds the default limit.<br/>适用版本：10+ |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const KEY_TEST_STRING_ELEMENT = 'key_test_string';
const VALUE_TEST_STRING_ELEMENT = 'value-test-string';
try {
  kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to put. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in putting');
    if (kvStore != null) {
      kvStore.delete(KEY_TEST_STRING_ELEMENT, (err: BusinessError) => {
        if (err) {
          console.error(`Failed to delete. Code: ${err.code}, message: ${err.message}`);
          return;
        }
        console.info('Succeeded in deleting');
      });
    }
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### delete

delete(key: string): Promise&lt;void&gt;

从数据库中删除指定键值的数据，使用Promise异步回调。删除成功后，指定键值对将被永久删除，无法再通过get等方法查询；若已订阅数据变更通知，将触发变更通知回调。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明                                                         |
| ------ | -------- | ---- | ------------------------------------------------------------ |
| key    | string   | 是   | 要删除数据的Key，不能为空且长度范围为1-[MAX_KEY_LENGTH](#constants)。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)和[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                             |
| ------------ | ---------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed.  |
| 15100003     | Database corrupted.                      |
| 15100005     | Database or result set already closed.   |

以下错误码的详细介绍请参见[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                 |
| ------------ | -------------------------------------------- |
| 14800047     | The WAL file size exceeds the default limit.<br/>适用版本：10+ |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const KEY_TEST_STRING_ELEMENT = 'key_test_string';
const VALUE_TEST_STRING_ELEMENT = 'value-test-string';
try {
  kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT).then(() => {
    console.info(`Succeeded in putting data`);
    if (kvStore != null) {
      kvStore.delete(KEY_TEST_STRING_ELEMENT).then(() => {
        console.info('Succeeded in deleting');
      }).catch((err: BusinessError) => {
        console.error(`Failed to delete. Code: ${err.code}, message: ${err.message}`);
      });
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to put. Code: ${err.code}, message: ${err.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### deleteBatch

deleteBatch(keys: string[], callback: AsyncCallback&lt;void&gt;): void

批量删除SingleKVStore数据库中的键值对，使用callback异步回调。删除成功后，指定键值对将被永久删除，无法再通过get等方法查询；若已订阅数据变更通知，将触发变更通知回调。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名   | 类型                  | 必填 | 说明                     |
| -------- | ------------------------- | ---- | ------------------------ |
| keys     | string[]                  | 是   | 表示要批量删除的键名列表，不能为空，数组中每个元素的长度范围为1-[MAX_KEY_LENGTH](#constants)。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。批量删除指定的数据成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)和[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                             |
| ------------ | ---------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed.  |
| 15100003     | Database corrupted.                      |
| 15100005     | Database or result set already closed.   |

以下错误码的详细介绍请参见[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                           |
| ------------ |----------------------------------------------------|
| 14800047     | The WAL file size exceeds the default limit.<br/>适用版本：10+ |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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
  kvStore.putBatch(entries, async (err: BusinessError) => {
    if (err) {
      console.error(`Failed to put Batch. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in putting Batch');
    if (kvStore != null) {
      kvStore.deleteBatch(keys, async (err: BusinessError) => {
        if (err) {
          console.error(`Failed to delete Batch. Code: ${err.code}, message: ${err.message}`);
          return;
        }
        console.info('Succeeded in deleting Batch');
      });
    }
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### deleteBatch

deleteBatch(keys: string[]): Promise&lt;void&gt;

批量删除SingleKVStore数据库中的键值对，使用Promise异步回调。删除成功后，指定键值对将被永久删除，无法再通过get等方法查询；若已订阅数据变更通知，将触发变更通知回调。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明                     |
| ------ | -------- | ---- | ------------------------ |
| keys   | string[] | 是   | 表示要批量删除的键名列表，不能为空，数组中每个元素的长度范围为1-[MAX_KEY_LENGTH](#constants)。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)和[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                             |
| ------------ | ---------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed.  |
| 15100003     | Database corrupted.                      |
| 15100005     | Database or result set already closed.   |

以下错误码的详细介绍请参见[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                              |
| ------------ |-------------------------------------------------------|
| 14800047     | The WAL file size exceeds the default limit.<br/>适用版本：10+ |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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
    if (kvStore != null) {
      kvStore.deleteBatch(keys).then(() => {
        console.info('Succeeded in deleting Batch');
      }).catch((err: BusinessError) => {
        console.error(`Failed to delete Batch. Code: ${err.code}, message: ${err.message}`);
      });
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to put Batch. Code: ${err.code}, message: ${err.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### removeDeviceData

removeDeviceData(deviceId: string, callback: AsyncCallback&lt;void&gt;): void

删除指定设备的数据，使用callback异步回调。删除成功后，指定设备的所有数据将从本地数据库中永久移除，无法再通过get等方法查询该设备的数据。
> **说明：**
>
> 其中deviceId为[DeviceBasicInfo](../apis-distributedservice-kit/js-apis-distributedDeviceManager.md#devicebasicinfo)中的networkId，通过调用[deviceManager.getAvailableDeviceListSync](../apis-distributedservice-kit/js-apis-distributedDeviceManager.md#getavailabledevicelistsync)方法得到。
> deviceId具体获取方式请参考[sync接口示例](#sync)。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**参数：**

| 参数名   | 类型                  | 必填 | 说明                   |
| -------- | ------------------------- | ---- | ---------------------- |
| deviceId | string                    | 是   | 设备的networkId，标识要删除其数据的设备，不能为空。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。删除指定设备的数据成功，err为undefined，否则为错误对象。    |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)和[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Parameter verification failed.  |
| 15100005     | Database or result set already closed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const KEY_TEST_STRING_ELEMENT = 'key_test_string_2';
const VALUE_TEST_STRING_ELEMENT = 'value-string-002';
try {
  kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT, async (err: BusinessError) => {
    if (err) {
      console.error(`Failed to put device data. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in putting data');
    const deviceId = 'no_exist_device_id';
    if (kvStore) {
      kvStore.removeDeviceData(deviceId, async (err: BusinessError) => {
        if (err) {
          console.error(`Failed to remove device data. Code: ${err.code}, message: ${err.message}`);
        } else {
          console.info('Succeeded in removing device data');
          if (kvStore) {
            kvStore.get(KEY_TEST_STRING_ELEMENT, async (err: BusinessError, data: boolean | string | number | Uint8Array) => {
                if (err) {
                  console.error(`Failed to get data. Code: ${err.code}, message: ${err.message}`);
                  return;
                }
                console.info(`Succeeded in getting data.data=${data}`);
              });
          }
        }
      });
    }
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### removeDeviceData

removeDeviceData(deviceId: string): Promise&lt;void&gt;

删除指定设备的数据，使用Promise异步回调。删除成功后，指定设备的所有数据将从本地数据库中永久移除，无法再通过get等方法查询该设备的数据。
> **说明：**
>
> 其中deviceId为[DeviceBasicInfo](../apis-distributedservice-kit/js-apis-distributedDeviceManager.md#devicebasicinfo)中的networkId，通过调用[deviceManager.getAvailableDeviceListSync](../apis-distributedservice-kit/js-apis-distributedDeviceManager.md#getavailabledevicelistsync)方法得到。
> deviceId具体获取方式请参考[sync接口示例](#sync)。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**参数：**

| 参数名   | 类型 | 必填 | 说明                   |
| -------- | -------- | ---- | ---------------------- |
| deviceId | string   | 是   | 设备的networkId，标识要删除其数据的设备，不能为空。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)和[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Parameter verification failed.  |
| 15100005     | Database or result set already closed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const KEY_TEST_STRING_ELEMENT = 'key_test_string_2';
const VALUE_TEST_STRING_ELEMENT = 'value-string-001';
try {
  kvStore!.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT).then(() => {
    console.info('Succeeded in putting data');
    const deviceId = 'no_exist_device_id';
    kvStore!.removeDeviceData(deviceId).then(() => {
      console.info('succeeded in removing device data');
      kvStore!.get(KEY_TEST_STRING_ELEMENT).then((data: boolean | string | number | Uint8Array) => {
        console.info(`Succeeded in getting data. Data=${data}`);
      }).catch((err: BusinessError) => {
        console.error(`Failed to get data. Code: ${err.code}, message: ${err.message}`);
      });
    }).catch((err: BusinessError) => {
      console.error(`Failed to remove device data. Code: ${err.code}, message: ${err.message}`);
    });
  }).catch((err: BusinessError) => {
    console.error(`Failed to put data. Code: ${err.code}, message: ${err.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### get

get(key: string, callback: AsyncCallback&lt;boolean | string | number | Uint8Array&gt;): void

获取指定键的值，使用callback异步回调。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名  | 类型 | 必填  | 说明                                              |
| -----  | ------  | ----  |-------------------------------------------------|
| key    |string   | 是    | 要查询数据的Key，不能为空且长度范围为1-[MAX_KEY_LENGTH](#constants)。 |
| callback  |AsyncCallback&lt;boolean \| string \| number \| Uint8Array&gt; | 是    | 回调函数。返回获取查询的值，值的类型取决于存储时的数据类型。  |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)和[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed.  |
| 15100003     | Database corrupted.                    |
| 15100004     | Not found.                             |
| 15100005     | Database or result set already closed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';


const KEY_TEST_STRING_ELEMENT = 'key_test_string';
const VALUE_TEST_STRING_ELEMENT = 'value-test-string';
try {
  kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to put. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in putting');
    if (kvStore != null) {
      kvStore.get(KEY_TEST_STRING_ELEMENT, (err: BusinessError, data: boolean | string | number | Uint8Array) => {
        if (err) {
          console.error(`Failed to get. Code: ${err.code}, message: ${err.message}`);
          return;
        }
        console.info(`Succeeded in getting data.data=${data}`);
      });
    }
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to get. Code: ${error.code}, message: ${error.message}`);
}
```

### get

get(key: string): Promise&lt;boolean | string | number | Uint8Array&gt;

获取指定键的值，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明                                                         |
| ------ | -------- | ---- | ------------------------------------------------------------ |
| key    | string   | 是   | 要查询数据的Key，不能为空且长度范围为1-[MAX_KEY_LENGTH](#constants)。 |

**返回值：**

| 类型    | 说明       |
| ------  | -------   |
|Promise&lt;boolean \| string \| number \| Uint8Array&gt; |Promise对象。返回指定键对应的值，值的类型取决于存储时的数据类型。|

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)和[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed.  |
| 15100003     | Database corrupted.                    |
| 15100004     | Not found.                             |
| 15100005     | Database or result set already closed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';


const KEY_TEST_STRING_ELEMENT = 'key_test_string';
const VALUE_TEST_STRING_ELEMENT = 'value-test-string';
try {
  kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT).then(() => {
    console.info(`Succeeded in putting data`);
    if (kvStore != null) {
      kvStore.get(KEY_TEST_STRING_ELEMENT).then((data: boolean | string | number | Uint8Array) => {
        console.info(`Succeeded in getting data.data=${data}`);
      }).catch((err: BusinessError) => {
        console.error(`Failed to get. Code: ${err.code}, message: ${err.message}`);
      });
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to put. Code: ${err.code}, message: ${err.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to get. Code: ${error.code}, message: ${error.message}`);
}
```

### getEntries

getEntries(keyPrefix: string, callback: AsyncCallback&lt;Entry[]&gt;): void

获取匹配指定键前缀的所有键值对，使用callback异步回调。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名    | 类型                               | 必填 | 说明                                                                                  |
| --------- | -------------------------------------- | ---- |-------------------------------------------------------------------------------------|
| keyPrefix | string                                 | 是   | 表示要匹配的键前缀，长度范围为1-[MAX_KEY_LENGTH](#constants)。不能包含'^'，包含'^'将导致谓词失效，查询结果会返回数据库中的所有数据。 |
| callback  | AsyncCallback&lt;[Entry](#entry)[]&gt; | 是   | 回调函数。返回匹配指定前缀的键值对列表。                                                                |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)和[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.|
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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
  kvStore.putBatch(entries, async (err: BusinessError) => {
    if (err) {
      console.error(`Failed to put Batch. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in putting Batch');
    if (kvStore != null) {
      kvStore.getEntries('batch_test_string_key', (err: BusinessError, entries: distributedKVStore.Entry[]) => {
        if (err) {
          console.error(`Failed to get Entries. Code: ${err.code}, message: ${err.message}`);
          return;
        }
        console.info('Succeeded in getting Entries');
        console.info(`entries.length: ${entries.length}`);
        console.info(`entries[0]: ${entries[0]}`);
      });
    }
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### getEntries

getEntries(keyPrefix: string): Promise&lt;Entry[]&gt;

获取匹配指定键前缀的所有键值对，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名    | 类型 | 必填 | 说明                                                                                  |
| --------- | -------- | ---- |-------------------------------------------------------------------------------------|
| keyPrefix | string   | 是   | 表示要匹配的键前缀，长度范围为1-[MAX_KEY_LENGTH](#constants)。不能包含'^'，包含'^'将导致谓词失效，查询结果会返回数据库中的所有数据。 |

**返回值：**

| 类型                             | 说明                                        |
| -------------------------------- | ------------------------------------------- |
| Promise&lt;[Entry](#entry)[]&gt; | Promise对象。返回匹配指定前缀的键值对列表。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)和[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.|
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';


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
    if (kvStore != null) {
      kvStore.getEntries('batch_test_string_key').then((entries: distributedKVStore.Entry[]) => {
        console.info('Succeeded in getting Entries');
        console.info(`PutBatch ${entries}`);
      }).catch((err: BusinessError) => {
        console.error(`Failed to get Entries. Code: ${err.code}, message: ${err.message}`);
      });
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to put Batch. Code: ${err.code}, message: ${err.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### getEntries

getEntries(query: Query, callback: AsyncCallback&lt;Entry[]&gt;): void

获取与指定Query对象匹配的键值对列表，使用callback异步回调。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名   | 类型                               | 必填 | 说明                         |
| -------- | -------------------------------------- | ---- |----------------------------|
| query    | [Query](#query)                         | 是   | 表示要查询的对象。                  |
| callback | AsyncCallback&lt;[Entry](#entry)[]&gt; | 是   | 回调函数。返回与指定Query对象匹配的键值对列表。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)和[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.|
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let arr = new Uint8Array([21, 31]);
  let entries: distributedKVStore.Entry[] = [];
  for (let i = 0; i < 10; i++) {
    let key = 'batch_test_bool_key';
    let entry: distributedKVStore.Entry = {
      key: key + i,
      value: {
        type: distributedKVStore.ValueType.BYTE_ARRAY,
        value: arr
      }
    }
    entries.push(entry);
  }
  console.info(`entries: ${entries}`);
  kvStore.putBatch(entries, async (err: BusinessError) => {
    if (err) {
      console.error(`Failed to put Batch. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in putting Batch');
    const query = new distributedKVStore.Query();
    query.prefixKey('batch_test');
    if (kvStore != null) {
      kvStore.getEntries(query, (err: BusinessError, entries: distributedKVStore.Entry[]) => {
        if (err) {
          console.error(`Failed to get Entries. Code: ${err.code}, message: ${err.message}`);
          return;
        }
        console.info('Succeeded in getting Entries');
        console.info(`entries.length: ${entries.length}`);
        console.info(`entries[0]: ${entries[0]}`);
      });
    }
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to get Entries. Code: ${error.code}, message: ${error.message}`);
}
```

### getEntries

getEntries(query: Query): Promise&lt;Entry[]&gt;

获取与指定Query对象匹配的键值对列表，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名 | 类型       | 必填 | 说明           |
| ------ | -------------- | ---- | -------------- |
| query  | [Query](#query) | 是   | 表示查询对象。 |

**返回值：**

| 类型                             | 说明                                               |
| -------------------------------- | -------------------------------------------------- |
| Promise&lt;[Entry](#entry)[]&gt; | Promise对象。返回与指定Query对象匹配的键值对列表。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)和[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.|
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let arr = new Uint8Array([21, 31]);
  let entries: distributedKVStore.Entry[] = [];
  for (let i = 0; i < 10; i++) {
    let key = 'batch_test_bool_key';
    let entry: distributedKVStore.Entry = {
      key: key + i,
      value: {
        type: distributedKVStore.ValueType.BYTE_ARRAY,
        value: arr
      }
    }
    entries.push(entry);
  }
  console.info(`entries: ${entries}`);
  kvStore.putBatch(entries).then(async () => {
    console.info('Succeeded in putting Batch');
    const query = new distributedKVStore.Query();
    query.prefixKey('batch_test');
    if (kvStore != null) {
      kvStore.getEntries(query).then((entries: distributedKVStore.Entry[]) => {
        console.info('Succeeded in getting Entries');
      }).catch((err: BusinessError) => {
        console.error(`Failed to get Entries. Code: ${err.code}, message: ${err.message}`);
      });
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to get Entries. Code: ${err.code}, message: ${err.message}`);
  });
  console.info('Succeeded in getting Entries');
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to get Entries. Code: ${error.code}, message: ${error.message}`);
}
```

### getResultSet

getResultSet(keyPrefix: string, callback: AsyncCallback&lt;KVStoreResultSet&gt;): void

从SingleKVStore数据库中获取具有指定前缀的结果集，使用callback异步回调。获取结果集后，在使用完毕时需调用[closeResultSet](#closeresultset)关闭结果集释放资源。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名    | 类型                                                   | 必填 | 说明                                                                                  |
| --------- | ---------------------------------------------------------- | ---- |-------------------------------------------------------------------------------------|
| keyPrefix | string                                 | 是   | 表示要匹配的键前缀，长度范围为1-[MAX_KEY_LENGTH](#constants)。不能包含'^'，包含'^'将导致谓词失效，查询结果会返回数据库中的所有数据。 |
| callback  | AsyncCallback&lt;[KVStoreResultSet](#kvstoreresultset)&gt; | 是   | 回调函数。返回具有指定前缀的结果集。                                                                  |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)和[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.  |
| 15100001     | Over max limits.<br/>适用版本：10+                      |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |


**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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
  kvStore.putBatch(entries, async (err: BusinessError) => {
    if (err) {
      console.error(`Failed to put batch. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in putting batch');
    if (kvStore != null) {
      kvStore.getResultSet('batch_test_string_key', async (err: BusinessError, result: distributedKVStore.KVStoreResultSet) => {
        if (err) {
          console.error(`Failed to get resultset. Code: ${err.code}, message: ${err.message}`);
          return;
        }
        console.info('Succeeded in getting result set');
        resultSet = result;
        if (kvStore != null) {
          kvStore.closeResultSet(resultSet, (err :BusinessError) => {
            if (err) {
              console.error(`Failed to close resultset. Code: ${err.code}, message: ${err.message}`);
              return;
            }
            console.info('Succeeded in closing result set');
          });
        }
      });
    }
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### getResultSet

getResultSet(keyPrefix: string): Promise&lt;KVStoreResultSet&gt;

从SingleKVStore数据库中获取具有指定前缀的结果集，使用Promise异步回调。获取结果集后，在使用完毕时需调用[closeResultSet](#closeresultset)关闭结果集释放资源。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名    | 类型 | 必填 | 说明                                                                                  |
| --------- | -------- | ---- |-------------------------------------------------------------------------------------|
| keyPrefix | string   | 是   | 表示要匹配的键前缀，长度范围为1-[MAX_KEY_LENGTH](#constants)。不能包含'^'，包含'^'将导致谓词失效，查询结果会返回数据库中的所有数据。 |

**返回值：**

| 类型                                                 | 说明                                    |
| ---------------------------------------------------- | --------------------------------------- |
| Promise&lt;[KVStoreResultSet](#kvstoreresultset)&gt; | Promise对象。返回具有指定前缀的结果集。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)和[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.|
| 15100001     | Over max limits.<br/>适用版本：10+                      |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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
  kvStore!.putBatch(entries).then(() => {
    console.info('Succeeded in putting batch');
    kvStore!.getResultSet('batch_test_string_key').then((result: distributedKVStore.KVStoreResultSet) => {
      console.info('Succeeded in getting result set');
      resultSet = result;
      if (kvStore != null) {
        kvStore.closeResultSet(resultSet).then(() => {
          console.info('Succeeded in closing result set');
        }).catch((err: BusinessError) => {
          console.error(`Failed to close resultset. Code: ${err.code}, message: ${err.message}`);
        });
      }
    }).catch((err: BusinessError) => {
      console.error(`Failed to get resultset. Code: ${err.code}, message: ${err.message}`);
    });
  }).catch((err: BusinessError) => {
    console.error(`Failed to put batch. Code: ${err.code}, message: ${err.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### getResultSet

getResultSet(query: Query, callback: AsyncCallback&lt;KVStoreResultSet&gt;): void

获取与指定Query对象匹配的KVStoreResultSet对象，使用callback异步回调。获取结果集后，在使用完毕时需调用[closeResultSet](#closeresultset)关闭结果集释放资源。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名   | 类型                                                   | 必填 | 说明                                                      |
| -------- | ---------------------------------------------------------- | ---- | --------------------------------------------------------- |
| query    | [Query](#query)                                                      | 是   | 表示查询对象。                                            |
| callback | AsyncCallback&lt;[KVStoreResultSet](#kvstoreresultset)&gt; | 是   | 回调函数，获取与指定Query对象匹配的KVStoreResultSet对象。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)和[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.|
| 15100001     | Over max limits.<br/>适用版本：10+                      |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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
  kvStore.putBatch(entries, async (err: BusinessError) => {
    if (err) {
      console.error(`Failed to put batch. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in putting batch');
    const query = new distributedKVStore.Query();
    query.prefixKey('batch_test');
    if (kvStore != null) {
      kvStore.getResultSet(query, async (err: BusinessError, result: distributedKVStore.KVStoreResultSet) => {
        if (err) {
          console.error(`Failed to get resultset. Code: ${err.code}, message: ${err.message}`);
          return;
        }
        console.info('Succeeded in getting result set');
      });
    }
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### getResultSet

getResultSet(query: Query): Promise&lt;KVStoreResultSet&gt;

获取与指定Query对象匹配的KVStoreResultSet对象，使用Promise异步回调。获取结果集后，在使用完毕时需调用[closeResultSet](#closeresultset)关闭结果集释放资源。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名 | 类型       | 必填 | 说明           |
| ------ | -------------- | ---- | -------------- |
| query  | [Query](#query) | 是   | 表示查询对象。 |

**返回值：**

| 类型                                                 | 说明                                                         |
| ---------------------------------------------------- | ------------------------------------------------------------ |
| Promise&lt;[KVStoreResultSet](#kvstoreresultset)&gt; | Promise对象。获取与指定Query对象匹配的KVStoreResultSet对象。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)和[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.|
| 15100001     | Over max limits.<br/>适用版本：10+                      |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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
    kvStore!.putBatch(entries).then(() => {
    console.info('Succeeded in putting batch');
    const query = new distributedKVStore.Query();
    query.prefixKey('batch_test');
    kvStore!.getResultSet(query).then((result: distributedKVStore.KVStoreResultSet) => {
      console.info(`Succeeded in getting result set size=${result.getCount()}`);
    }).catch((err: BusinessError) => {
      console.error(`Failed to get resultset. Code: ${err.code}, message: ${err.message}`);
    });
  }).catch((err: BusinessError) => {
    console.error(`Failed to put batch. Code: ${err.code}, message: ${err.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### closeResultSet

closeResultSet(resultSet: KVStoreResultSet, callback: AsyncCallback&lt;void&gt;): void

关闭由[SingleKVStore.getResultSet](#getresultset-1)返回的KVStoreResultSet对象，使用callback异步回调。关闭结果集后，该结果集对象将不可再用，相关数据库资源被释放。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名    | 类型                              | 必填 | 说明                               |
| --------- | ------------------------------------- | ---- | ---------------------------------- |
| resultSet | [KVStoreResultSet](#kvstoreresultset) | 是   | 表示要关闭的KVStoreResultSet对象。 |
| callback  | AsyncCallback&lt;void&gt;             | 是   | 回调函数。关闭KVStoreResultSet对象成功，err为undefined，否则为错误对象。  |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let resultSet: distributedKVStore.KVStoreResultSet;
try {
  kvStore.getResultSet('batch_test_string_key', async (err: BusinessError, result: distributedKVStore.KVStoreResultSet) => {
    if (err) {
      console.error(`Failed to get resultset. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in getting result set');
    resultSet = result;
    if (kvStore != null) {
      kvStore.closeResultSet(resultSet, (err: BusinessError) => {
        if (err) {
          console.error(`Failed to close resultset. Code: ${err.code}, message: ${err.message}`);
          return;
        }
        console.info('Succeeded in closing result set');
      })
    }
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}

```

### closeResultSet

closeResultSet(resultSet: KVStoreResultSet): Promise&lt;void&gt;

关闭由[SingleKVStore.getResultSet](#getresultset-1)返回的KVStoreResultSet对象，使用Promise异步回调。关闭结果集后，该结果集对象将不可再用，相关数据库资源被释放。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名    | 类型                              | 必填 | 说明                               |
| --------- | ------------------------------------- | ---- | ---------------------------------- |
| resultSet | [KVStoreResultSet](#kvstoreresultset) | 是   | 表示要关闭的KVStoreResultSet对象。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let resultSet: distributedKVStore.KVStoreResultSet;
try {
  kvStore.getResultSet('batch_test_string_key').then((result: distributedKVStore.KVStoreResultSet) => {
    console.info('Succeeded in getting result set');
    resultSet = result;
    if (kvStore != null) {
      kvStore.closeResultSet(resultSet).then(() => {
        console.info('Succeeded in closing result set');
      }).catch((err: BusinessError) => {
        console.error(`Failed to close resultset. Code: ${err.code}, message: ${err.message}`);
      });
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to get resultset. Code: ${err.code}, message: ${err.message}`);
  });

} catch (err) {
  let error = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### getResultSize

getResultSize(query: Query, callback: AsyncCallback&lt;number&gt;): void

获取与指定Query对象匹配的结果数，使用callback异步回调。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                        |
| -------- | --------------------------- | ---- | ------------------------------------------- |
| query    | [Query](#query)              | 是   | 表示查询对象。                              |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调函数。返回与指定Query对象匹配的结果数。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)和[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.|
| 15100003     | Database corrupted.                    |
| 15100004     | Not found.                             |
| 15100005     | Database or result set already closed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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
  kvStore.putBatch(entries, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to put batch. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in putting batch');
    const query = new distributedKVStore.Query();
    query.prefixKey('batch_test');
    if (kvStore != null) {
      kvStore.getResultSize(query, (err: BusinessError, resultSize: number) => {
        if (err) {
          console.error(`Failed to get result size. Code: ${err.code}, message: ${err.message}`);
          return;
        }
        console.info('Succeeded in getting result set size');
      });
    }
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### getResultSize

getResultSize(query: Query): Promise&lt;number&gt;

获取与指定Query对象匹配的结果数，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名 | 类型       | 必填 | 说明           |
| ------ | -------------- | ---- | -------------- |
| query  | [Query](#query) | 是   | 表示查询对象。 |

**返回值：**

| 类型                  | 说明                                            |
| --------------------- | ----------------------------------------------- |
| Promise&lt;number&gt; | Promise对象。获取与指定Query对象匹配的结果数。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)和[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.|
| 15100003     | Database corrupted.                    |
| 15100004     | Not found.                             |
| 15100005     | Database or result set already closed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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
    console.error(`Failed to put batch. Code: ${err.code}, message: ${err.message}`);
  });
  const query = new distributedKVStore.Query();
  query.prefixKey('batch_test');
  kvStore.getResultSize(query).then((resultSize: number) => {
    console.info('Succeeded in getting result set size');
  }).catch((err: BusinessError) => {
    console.error(`Failed to get result size. Code: ${err.code}, message: ${err.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### backup

backup(file:string, callback: AsyncCallback&lt;void&gt;):void

以指定名称备份数据库到默认路径（context.databaseDir），使用callback异步回调。如需备份到自定义路径，请使用[backupEx](#backupex24)接口。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名   | 类型                  | 必填 | 说明                                                         |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| file     | string                    | 是   | 备份数据库的指定名称，不能为空，无长度限制，不能包含特殊字符'/'。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。当以指定名称备份数据库成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)和[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Parameter verification failed.  |
| 15100005     | Database or result set already closed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let backupFile = 'BK001';
try {
  kvStore.backup(backupFile, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to backup. Code: ${err.code}, message: ${err.message} `);
    } else {
      console.info(`Succeeded in backupping data`);
    }
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### backup

backup(file:string): Promise&lt;void&gt;

以指定名称备份数据库到默认路径（context.databaseDir），使用Promise异步回调。如需备份到自定义路径，请使用[backupEx](#backupex24)接口。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明                                                         |
| ------ | -------- | ---- | ------------------------------------------------------------ |
| file   | string   | 是   | 备份数据库的指定名称，不能为空，无长度限制，不能包含特殊字符'/'。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)和[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Parameter verification failed.  |
| 15100005     | Database or result set already closed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let backupFile = 'BK001';
try {
  kvStore.backup(backupFile).then(() => {
    console.info(`Succeeded in backupping data`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to backup. Code: ${err.code}, message: ${err.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### backupEx<sup>24+</sup>

backupEx(backupConfig:BackupConfig): Promise&lt;void&gt;

以指定名称和路径备份数据库，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明                                                         |
| ------ | -------- | ---- | ------------------------------------------------------------ |
| backupConfig   | [BackupConfig](#backupconfig24)  | 是   | 备份数据库的信息（名称和路径）。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 15100000     | Input parameters do not meet the API requirements, such as invalid value ranges, length limits, or incorrect formats. |
| 15100005     | Database or result set already closed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const backupConfig: distributedKVStore.BackupConfig = {
  fileName: 'BK001',
  filePath: '/data/storage/el2/database'
};
try {
  kvStore.backupEx(backupConfig).then(() => {
    console.info(`Succeeded in backupping data`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to backup. Code: ${err.code}, message: ${err.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```
### restore

restore(file:string, callback: AsyncCallback&lt;void&gt;):void

从数据库默认路径（context.databaseDir）下指定名称的备份文件恢复数据库，使用callback异步回调。恢复成功后，当前数据库中的数据将被替换为备份文件中的数据，原有的未备份数据将丢失。如需从自定义路径恢复，请使用[restoreEx](#restoreex24)接口。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名   | 类型                  | 必填 | 说明                                                         |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| file     | string                    | 是   | 指定的数据库文件名称，不能为空，无长度限制，不能包含特殊字符'/'。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。当从指定的数据库文件恢复数据库成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)和[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Parameter verification failed.  |
| 15100005     | Database or result set already closed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let backupFile = 'BK001';
try {
  kvStore.restore(backupFile, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to restore. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in restoring data`);
    }
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### restore

restore(file:string): Promise&lt;void&gt;

从数据库默认路径（context.databaseDir）下指定名称的备份文件恢复数据库，使用Promise异步回调。恢复成功后，当前数据库中的数据将被替换为备份文件中的数据，原有的未备份数据将丢失。如需从自定义路径恢复，请使用[restoreEx](#restoreex24)接口。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明                                                         |
| ------ | -------- | ---- | ------------------------------------------------------------ |
| file   | string   | 是   | 指定的数据库文件名称，不能为空，无长度限制，不能包含特殊字符'/'。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)和[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Parameter verification failed.  |
| 15100005     | Database or result set already closed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let backupFile = 'BK001';
try {
  kvStore.restore(backupFile).then(() => {
    console.info(`Succeeded in restoring data`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to restore. Code: ${err.code}, message: ${err.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### restoreEx<sup>24+</sup>

restoreEx(backupConfig:BackupConfig): Promise&lt;void&gt;

从指定路径和名称的备份文件恢复数据库，使用Promise异步回调。恢复成功后，当前数据库中的数据将被替换为备份文件中的数据，原有的未备份数据将丢失。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明                                                         |
| ------ | -------- | ---- | ------------------------------------------------------------ |
| backupConfig   | [BackupConfig](#backupconfig24)  | 是   | 备份数据库的信息（名称和路径）。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 15100000     | Input parameters do not meet the API requirements, such as invalid value ranges, length limits, or incorrect formats. |
| 15100005     | Database or result set already closed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const backupConfig: distributedKVStore.BackupConfig = {
  fileName: 'BK001',
  filePath: '/data/storage/el2/database'
};
try {
  kvStore.restoreEx(backupConfig).then(() => {
    console.info(`Succeeded in restoring data`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to restore. Code: ${err.code}, message: ${err.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### deleteBackup

deleteBackup(files:Array&lt;string&gt;, callback: AsyncCallback&lt;Array&lt;[string, number]&gt;&gt;):void

根据指定名称从默认路径（context.databaseDir）删除备份文件，使用callback异步回调。删除备份文件后，将无法再通过[restore](#restore-1)接口恢复该备份文件中的数据。如需从自定义路径删除备份，请使用[deleteBackupEx](#deletebackupex24)接口。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名   | 类型                                           | 必填 | 说明                                                         |
| -------- | -------------------------------------------------- | ---- | ------------------------------------------------------------ |
| files    | Array&lt;string&gt;                                | 是   | 删除备份文件所指定的名称，不能为空，无长度限制，不能包含特殊字符'/'。 |
| callback | AsyncCallback&lt;Array&lt;[string, number]&gt;&gt; | 是   | 回调函数，返回删除备份的文件名及其处理结果。                 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Parameter verification failed.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let files = ['BK001', 'BK002'];
try {
  kvStore.deleteBackup(files, (err: BusinessError, data: [string, number][]) => {
    if (err) {
      console.error(`Failed to delete Backup. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeed in deleting Backup.data=${data}`);
    }
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### deleteBackup

deleteBackup(files:Array&lt;string&gt;): Promise&lt;Array&lt;[string, number]&gt;&gt;

根据指定名称从默认路径（context.databaseDir）删除备份文件，使用Promise异步回调。删除备份文件后，将无法再通过[restore](#restore)接口恢复该备份文件中的数据。如需从自定义路径删除备份，请使用[deleteBackupEx](#deletebackupex24)接口。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名 | 类型            | 必填 | 说明                                                         |
| ------ | ------------------- | ---- | ------------------------------------------------------------ |
| files  | Array&lt;string&gt; | 是   | 删除备份文件所指定的名称，不能为空，无长度限制，不能包含特殊字符'/'。 |

**返回值：**

| 类型                                         | 说明                                            |
| -------------------------------------------- | ----------------------------------------------- |
| Promise&lt;Array&lt;[string, number]&gt;&gt; | Promise对象，返回删除备份的文件名及其处理结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Parameter verification failed.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let files = ['BK001', 'BK002'];
try {
  kvStore.deleteBackup(files).then((data: [string, number][]) => {
    console.info(`Succeed in deleting Backup.data=${data}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to delete Backup. Code: ${err.code}, message: ${err.message}`);
  })
} catch (err) {
  let error = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### deleteBackupEx<sup>24+</sup>

deleteBackupEx(backupConfig:BackupConfig): Promise&lt;void&gt;

根据指定名称和路径删除备份文件，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名 | 类型            | 必填 | 说明                                                         |
| ------ | ------------------- | ---- | ------------------------------------------------------------ |
| backupConfig   | [BackupConfig](#backupconfig24)  | 是   | 备份数据库的信息（名称和路径）。 |

**返回值：**

| 类型                                         | 说明                                            |
| -------------------------------------------- | ----------------------------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 15100000     | Input parameters do not meet the API requirements, such as invalid value ranges, length limits, or incorrect formats. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const backupConfig: distributedKVStore.BackupConfig = {
  fileName: 'BK001',
  filePath: '/data/storage/el2/database'
};
try {
  kvStore.deleteBackupEx(backupConfig).then(() => {
    console.info(`Succeed in deleting Backup.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to delete Backup. Code: ${err.code}, message: ${err.message}`);
  })
} catch (err) {
  let error = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### startTransaction

startTransaction(callback: AsyncCallback&lt;void&gt;): void

启动SingleKVStore数据库中的事务，使用callback异步回调。启动事务后，后续的数据库操作将纳入此事务范围，直到调用[commit](#commit)提交或[rollback](#rollback)回滚才会结束事务。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名   | 类型                  | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。启动SingleKVStore数据库中的事务成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)。

| **错误码ID** | **错误信息**                             |
| ------------ | ---------------------------------------- |
| 15100005     | Database or result set already closed.   |

以下错误码的详细介绍请参见[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                 |
| ------------ | -------------------------------------------- |
| 14800047     | The WAL file size exceeds the default limit.<br/>适用版本：10+ |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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
} // 自定义函数，放置在作用域最外侧，防止语法检查报错

try {
  let count = 0;
  kvStore.on('dataChange', 0, (data: distributedKVStore.ChangeNotification) => {
    console.info(`startTransaction 0 ${data}`);
    count++;
  });
  kvStore.startTransaction(async (err: BusinessError) => {
    if (err) {
      console.error(`Failed to start Transaction. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in starting Transaction');
    let entries = putBatchString(10, 'batch_test_string_key');
    console.info(`entries: ${entries}`);
    if (kvStore != null) {
      kvStore.putBatch(entries, async (err: BusinessError) => {
        if (err) {
          console.error(`Failed to put batch. Code: ${err.code}, message: ${err.message}`);
          return;
        }
        console.info('Succeeded in putting Batch');
      });
    }
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to start Transaction. Code: ${error.code}, message: ${error.message}`);
}
```

### startTransaction

startTransaction(): Promise&lt;void&gt;

启动SingleKVStore数据库中的事务，使用Promise异步回调。启动事务后，后续的数据库操作将纳入此事务范围，直到调用[commit](#commit)提交或[rollback](#rollback)回滚才会结束事务。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)。

| **错误码ID** | **错误信息**                             |
| ------------ | ---------------------------------------- |
| 15100005     | Database or result set already closed.   |

以下错误码的详细介绍请参见[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                 |
| ------------ | -------------------------------------------- |
| 14800047     | The WAL file size exceeds the default limit.<br/>适用版本：10+ |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  kvStore.on('dataChange', distributedKVStore.SubscribeType.SUBSCRIBE_TYPE_ALL, (data: distributedKVStore.ChangeNotification) => {
    console.info(`startTransaction 0 ${data}`);
  });
  kvStore.startTransaction().then(async () => {
    console.info('Succeeded in starting Transaction');
  }).catch((err: BusinessError) => {
    console.error(`Failed to start Transaction. Code: ${err.code}, message: ${err.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to start Transaction. Code: ${error.code}, message: ${error.message}`);
}
```

### commit

commit(callback: AsyncCallback&lt;void&gt;): void

提交SingleKVStore数据库中的事务，使用callback异步回调。需先调用[startTransaction](#starttransaction)启动事务后再调用本接口提交事务。提交成功后，事务期间的所有数据变更将永久生效并写入数据库。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名   | 类型                  | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。提交SingleKVStore数据库中的事务成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 15100005     | Database or result set already closed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  kvStore.commit((err: BusinessError) => {
    if (err) {
      console.error(`Failed to commit. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info('Succeeded in committing');
    }
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### commit

commit(): Promise&lt;void&gt;

提交SingleKVStore数据库中的事务，使用Promise异步回调。需先调用[startTransaction](#starttransaction)启动事务后再调用本接口提交事务。提交成功后，事务期间的所有数据变更将永久生效并写入数据库。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 15100005     | Database or result set already closed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  kvStore.commit().then(async () => {
    console.info('Succeeded in committing');
  }).catch((err: BusinessError) => {
    console.error(`Failed to commit. Code: ${err.code}, message: ${err.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### rollback

rollback(callback: AsyncCallback&lt;void&gt;): void

在SingleKVStore数据库中回滚事务，使用callback异步回调。需先调用[startTransaction](#starttransaction)启动事务后再调用本接口回滚事务。回滚成功后，事务期间的所有数据变更将被丢弃，不会写入数据库。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名   | 类型                  | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。SingleKVStore数据库中回滚事务成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 15100005     | Database or result set already closed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  kvStore.rollback((err: BusinessError) => {
    if (err) {
      console.error(`Failed to rollback. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info('Succeeded in rolling back');
    }
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### rollback

rollback(): Promise&lt;void&gt;

在SingleKVStore数据库中回滚事务，使用Promise异步回调。需先调用[startTransaction](#starttransaction)启动事务后再调用本接口回滚事务。回滚成功后，事务期间的所有数据变更将被丢弃，不会写入数据库。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 15100005     | Database or result set already closed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  kvStore.rollback().then(async () => {
    console.info('Succeeded in rolling back');
  }).catch((err: BusinessError) => {
    console.error(`Failed to rollback. Code: ${err.code}, message: ${err.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### enableSync

enableSync(enabled: boolean, callback: AsyncCallback&lt;void&gt;): void

设定是否开启端端同步，使用callback异步回调。开启端端同步后，数据库中的数据可在多设备间自动同步；关闭后则不会自动同步，需要手动调用[sync](#sync)接口触发同步。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名   | 类型                  | 必填 | 说明                                                      |
| -------- | ------------------------- | ---- | --------------------------------------------------------- |
| enabled  | boolean                   | 是   | 设定是否开启端端同步，true表示开启端端同步，false表示不启用端端同步。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。设定成功，err为undefined，否则为错误对象。      |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                                                                                       |
| ------------ |----------------------------------------------------------------------------------------------------------------|
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  kvStore.enableSync(true, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to enable sync. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info('Succeeded in enabling sync');
    }
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### enableSync

enableSync(enabled: boolean): Promise&lt;void&gt;

设定是否开启端端同步，使用Promise异步回调。开启端端同步后，数据库中的数据可在多设备间自动同步；关闭后则不会自动同步，需要手动调用[sync](#sync)接口触发同步。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名  | 类型 | 必填 | 说明                                                      |
| ------- | -------- | ---- | --------------------------------------------------------- |
| enabled | boolean  | 是   | 设定是否开启端端同步，true表示开启端端同步，false表示不启用端端同步。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  kvStore.enableSync(true).then(() => {
    console.info('Succeeded in enabling sync');
  }).catch((err: BusinessError) => {
    console.error(`Failed to enable sync. Code: ${err.code}, message: ${err.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### setSyncRange

setSyncRange(localLabels: string[], remoteSupportLabels: string[], callback: AsyncCallback&lt;void&gt;): void

设置同步范围标签，使用callback异步回调。通过设置本地设备和远程设备的同步标签，决定哪些设备间可以进行数据同步。只有当本地设备的标签与远程设备的标签存在交集时，两端才允许同步数据。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名              | 类型                  | 必填 | 说明                             |
| ------------------- | ------------------------- | ---- | -------------------------------- |
| localLabels         | string[]                  | 是   | 表示本地设备的同步标签，用于标识本设备可参与同步的范围。         |
| remoteSupportLabels | string[]                  | 是   | 表示期望同步数据的对端设备的同步标签，用于标识允许同步的对端设备范围。当本端的remoteSupportLabels与对端的localLabels存在交集时，设备间才允许数据同步。 |
| callback            | AsyncCallback&lt;void&gt; | 是   | 回调函数。设置成功，err为undefined，否则为错误对象。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息** |
| ------------ | ------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  const localLabels = ['A', 'B'];
  const remoteSupportLabels = ['C', 'D'];
  kvStore.setSyncRange(localLabels, remoteSupportLabels, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to set syncRange. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in setting syncRange');
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### setSyncRange

setSyncRange(localLabels: string[], remoteSupportLabels: string[]): Promise&lt;void&gt;

设置同步范围标签，使用Promise异步回调。通过设置本地设备和远程设备的同步标签，决定哪些设备间可以进行数据同步。只有当本地设备的标签与远程设备的标签存在交集时，两端才允许同步数据。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名              | 类型 | 必填 | 说明                             |
| ------------------- | -------- | ---- | -------------------------------- |
| localLabels         | string[] | 是   | 表示本地设备的同步标签，用于标识本设备可参与同步的范围。         |
| remoteSupportLabels | string[] | 是   | 表示期望同步数据的对端设备的同步标签，用于标识允许同步的对端设备范围。当本端的remoteSupportLabels与对端的localLabels存在交集时，设备间才允许数据同步。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息** |
| ------------ | ------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  const localLabels = ['A', 'B'];
  const remoteSupportLabels = ['C', 'D'];
  kvStore.setSyncRange(localLabels, remoteSupportLabels).then(() => {
    console.info('Succeeded in setting syncRange');
  }).catch((err: BusinessError) => {
    console.error(`Failed to set syncRange. Code: ${err.code}, message: ${err.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### setSyncParam

setSyncParam(defaultAllowedDelayMs: number, callback: AsyncCallback&lt;void&gt;): void

设置数据库端端同步允许的默认延时，使用callback异步回调。

> **说明：**
>
> 设置默认延时后，调用[sync](#sync)接口不会立即触发端端同步，而是等待指定的延时时间后再执行。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名                | 类型                  | 必填 | 说明                                         |
| --------------------- | ------------------------- | ---- | -------------------------------------------- |
| defaultAllowedDelayMs | number                    | 是   | 表示一个延时时间，单位为毫秒（ms），取值范围为0或[100, 86400000]。|
| callback              | AsyncCallback&lt;void&gt; | 是   | 回调函数。设置成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息** |
| ------------ | ------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  const defaultAllowedDelayMs = 500;
  kvStore.setSyncParam(defaultAllowedDelayMs, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to set syncParam. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in setting syncParam');
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### setSyncParam

setSyncParam(defaultAllowedDelayMs: number): Promise&lt;void&gt;

设置数据库端端同步允许的默认延时，使用Promise异步回调。

> **说明：**
>
> 设置默认延时后，调用[sync](#sync)接口不会立即触发端端同步，而是等待指定的延时时间后再执行。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名                | 类型 | 必填 | 说明                                         |
| --------------------- | -------- | ---- | -------------------------------------------- |
| defaultAllowedDelayMs | number   | 是   | 表示一个延时时间，单位为毫秒（ms），取值范围为0或[100, 86400000]。|

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息** |
| ------------ | ------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  const defaultAllowedDelayMs = 500;
  kvStore.setSyncParam(defaultAllowedDelayMs).then(() => {
    console.info('Succeeded in setting syncParam');
  }).catch((err: BusinessError) => {
    console.error(`Failed to set syncParam. Code: ${err.code}, message: ${err.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### sync

sync(deviceIds: string[], mode: SyncMode, delayMs?: number): void

在手动同步方式下，触发数据库端端同步。同步结果可通过订阅[on('syncComplete')](#onsynccomplete)事件获取。关于键值型数据库的端端同步方式说明，请见[键值型数据库跨设备数据同步](../../database/data-sync-of-kv-store.md)。
> **说明：**
>
> 其中deviceIds为[DeviceBasicInfo](../apis-distributedservice-kit/js-apis-distributedDeviceManager.md#devicebasicinfo)中的networkId, 通过调用[deviceManager.getAvailableDeviceListSync](../apis-distributedservice-kit/js-apis-distributedDeviceManager.md#getavailabledevicelistsync)方法得到。

**需要权限**： ohos.permission.DISTRIBUTED_DATASYNC。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名    | 类型              | 必填 | 说明                                           |
| --------- | --------------------- | ---- | ---------------------------------------------- |
| deviceIds | string[]              | 是   | 同一组网环境下，需要同步的设备的networkId列表。 |
| mode      | [SyncMode](#syncmode) | 是   | 同步模式。                                     |
| delayMs   | number                | 否   | 可选参数，允许延时时间，单位：ms（毫秒），默认为0。设置delayMs后，调用sync接口时延时时间为delayMs。未设置时以[setSyncParam](#setsyncparam)设置的时长为准。|

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)和[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**        |
| ------------ | ------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.|
| 15100003     | Database corrupted. |
| 15100004     | Not found.          |

**示例：**

```ts
import { distributedDeviceManager } from '@kit.DistributedServiceKit';
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let devManager: distributedDeviceManager.DeviceManager;
const KEY_TEST_SYNC_ELEMENT = 'key_test_sync';
const VALUE_TEST_SYNC_ELEMENT = 'value-string-001';
// create deviceManager
export default class EntryAbility extends UIAbility {
  onCreate() {
    let context = this.context;
    try {
      devManager = distributedDeviceManager.createDeviceManager(context.applicationInfo.name);
      let deviceIds: string[] = [];
      if (devManager != null) {
        let devices = devManager.getAvailableDeviceListSync();
        for (let i = 0; i < devices.length; i++) {
          deviceIds[i] = devices[i].networkId as string;
        }
      }
      try {
        if (kvStore != null) {
          kvStore.on('syncComplete', (data: [string, number][]) => {
            console.info('Sync dataChange');
          });
          if (kvStore != null) {
            kvStore.put(KEY_TEST_SYNC_ELEMENT + 'testSync101', VALUE_TEST_SYNC_ELEMENT, (err: BusinessError) => {
              if (err) {
                console.error(`Failed to sync. Code: ${err.code}, message: ${err.message}`);
                return;
              }
              console.info('Succeeded in putting data');
              const mode = distributedKVStore.SyncMode.PULL_ONLY;
              if (kvStore != null) {
                kvStore.sync(deviceIds, mode, 1000);
              }
            });
          }
        }
      } catch (err) {
        let error = err as BusinessError;
        console.error(`Failed to sync. Code: ${error.code}, message: ${error.message}`);
      }

    } catch (err) {
      let error = err as BusinessError;
      console.error(`Failed to create device manager. Code: ${error.code}, message: ${error.message}`);
    }
  }
}
```

### sync

sync(deviceIds: string[], query: Query, mode: SyncMode, delayMs?: number): void

在手动同步方式下，触发数据库端端同步，支持按查询条件过滤同步数据。同步结果可通过订阅[on('syncComplete')](#onsynccomplete)事件获取。关于键值型数据库的端端同步方式说明，请见[键值型数据库跨设备数据同步](../../database/data-sync-of-kv-store.md)。
> **说明：**
>
> 其中deviceIds为[DeviceBasicInfo](../apis-distributedservice-kit/js-apis-distributedDeviceManager.md#devicebasicinfo)中的networkId, 通过调用[deviceManager.getAvailableDeviceListSync](../apis-distributedservice-kit/js-apis-distributedDeviceManager.md#getavailabledevicelistsync)方法得到。

**需要权限**： ohos.permission.DISTRIBUTED_DATASYNC。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名    | 类型              | 必填 | 说明                                           |
| --------- | --------------------- | ---- | ---------------------------------------------- |
| deviceIds | string[]              | 是   | 同一组网环境下，需要同步的设备的networkId列表。 |
| query     | [Query](#query)        | 是   | 表示数据库的查询谓词条件。                      |
| mode      | [SyncMode](#syncmode) | 是   | 同步模式。                                     |
| delayMs   | number                | 否   | 可选参数，允许延时时间，单位：ms（毫秒），默认为0。设置delayMs后，调用sync接口时延时时间为delayMs。未设置时以[setSyncParam](#setsyncparam)设置的时长为准。|

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)和[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**        |
| ------------ | ------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.|
| 15100003     | Database corrupted. |
| 15100004     | Not found.          |

**示例：**

```ts
import { distributedDeviceManager } from '@kit.DistributedServiceKit';
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

const KEY_TEST_SYNC_ELEMENT = 'key_test_sync';
const VALUE_TEST_SYNC_ELEMENT = 'value-string-001';
// create deviceManager
export default class EntryAbility extends UIAbility {
  onCreate() {
    let context = this.context;
    try {
      let devManager = distributedDeviceManager.createDeviceManager(context.applicationInfo.name);
      let deviceIds: string[] = [];
      if (devManager != null) {
        let devices = devManager.getAvailableDeviceListSync();
        for (let i = 0; i < devices.length; i++) {
          deviceIds[i] = devices[i].networkId as string;
        }
      }
      try {
        if (kvStore != null) {
          kvStore.on('syncComplete', (data: [string, number][]) => {
            console.info('Sync dataChange');
          });
          if (kvStore != null) {
            kvStore.put(KEY_TEST_SYNC_ELEMENT + 'testSync101', VALUE_TEST_SYNC_ELEMENT, (err: BusinessError) => {
              if (err) {
                console.error(`Failed to sync. Code: ${err.code}, message: ${err.message}`);
                return;
              }
              console.info('Succeeded in putting data');
              const mode = distributedKVStore.SyncMode.PULL_ONLY;
              const query = new distributedKVStore.Query();
              query.prefixKey('batch_test');
              query.deviceId(devManager.getLocalDeviceNetworkId());
              if (kvStore != null) {
                kvStore.sync(deviceIds, query, mode, 1000);
              }
            });
          }
        }
      } catch (err) {
        let error = err as BusinessError;
        console.error(`Failed to sync. Code: ${error.code}, message: ${error.message}`);
      }

    } catch (err) {
      let error = err as BusinessError;
      console.error(`Failed to create device manager. Code: ${error.code}, message: ${error.message}`);
    }
  }
}
```

### on('dataChange')

on(event: 'dataChange', type: SubscribeType, listener: Callback&lt;ChangeNotification&gt;): void

订阅指定类型的数据变更通知。调用on订阅后，在不需要监听时必须调用[off('dataChange')](#offdatachange)取消订阅。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名   | 类型                                                  | 必填 | 说明                                                 |
| -------- | --------------------------------------------------------- | ---- | ---------------------------------------------------- |
| event    | string                                                    | 是   | 订阅的事件名，固定为'dataChange'，表示数据变更事件。 |
| type     | [SubscribeType](#subscribetype)                           | 是   | 表示订阅的类型。                                     |
| listener | Callback&lt;[ChangeNotification](#changenotification)&gt; | 是   | 回调函数。成功返回数据变更时通知的对象。|

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)和[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.  |
| 15100001     | Over max limits.                      |
| 15100005     | Database or result set already closed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  kvStore.on('dataChange', distributedKVStore.SubscribeType.SUBSCRIBE_TYPE_LOCAL, (data: distributedKVStore.ChangeNotification) => {
    console.info(`dataChange callback call data: ${data}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### on('syncComplete')

on(event: 'syncComplete', syncCallback: Callback&lt;Array&lt;[string, number]&gt;&gt;): void

订阅端端同步完成事件回调通知。调用on订阅后，在不需要监听时必须调用[off('syncComplete')](#offsynccomplete)取消订阅。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名       | 类型                                      | 必填 | 说明                                                   |
| ------------ | --------------------------------------------- | ---- | ------------------------------------------------------ |
| event        | string                                        | 是   | 订阅的事件名，固定为'syncComplete'，表示同步完成事件。 |
| syncCallback | Callback&lt;Array&lt;[string, number]&gt;&gt; | 是   | 回调函数。用于向调用方发送同步结果的回调。             |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';


const KEY_TEST_FLOAT_ELEMENT = 'key_test_float';
const VALUE_TEST_FLOAT_ELEMENT = 321.12;
try {
  kvStore.on('syncComplete', (data: [string, number][]) => {
    console.info(`syncComplete ${data}`);
  });
  kvStore.put(KEY_TEST_FLOAT_ELEMENT, VALUE_TEST_FLOAT_ELEMENT).then(() => {
    console.info('succeeded in putting');
  }).catch((err: BusinessError) => {
    console.error(`Failed to put. Code: ${err.code}, message: ${err.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to subscribe syncComplete. Code: ${error.code}, message: ${error.message}`);
}
```

### off('dataChange')

off(event:'dataChange', listener?: Callback&lt;ChangeNotification&gt;): void

取消订阅数据变更通知。必须先调用[on('dataChange')](#ondatachange)订阅后，才能调用off取消订阅。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名   | 类型                                                  | 必填 | 说明                                                     |
| -------- | --------------------------------------------------------- | ---- | -------------------------------------------------------- |
| event    | string                                                    | 是   | 取消订阅的事件名，固定为'dataChange'，表示数据变更事件。 |
| listener | Callback&lt;[ChangeNotification](#changenotification)&gt; | 否   | 取消订阅的函数。如不设置callback，则取消所有已订阅的函数。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)和[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.  |
| 15100005     | Database or result set already closed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

class KvstoreModel {
  call(data: distributedKVStore.ChangeNotification) {
    console.info(`dataChange : ${data}`);
  }

  subscribeDataChange() {
    try {
      if (kvStore != null) {
        kvStore.on('dataChange', distributedKVStore.SubscribeType.SUBSCRIBE_TYPE_REMOTE, this.call);
      }
    } catch (err) {
      let error = err as BusinessError;
      console.error(`Failed to subscribeDataChange. Code: ${error.code}, message: ${error.message}`);
    }
  }

  unsubscribeDataChange() {
    try {
      if (kvStore != null) {
        kvStore.off('dataChange', this.call);
      }
    } catch (err) {
      let error = err as BusinessError;
      console.error(`Failed to unsubscribeDataChange. Code: ${error.code}, message: ${error.message}`);
    }
  }
}
```

### off('syncComplete')

off(event: 'syncComplete', syncCallback?: Callback&lt;Array&lt;[string, number]&gt;&gt;): void

取消订阅端端同步完成事件回调通知。必须先调用[on('syncComplete')](#onsynccomplete)订阅后，才能调用off取消订阅。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名       | 类型                                      | 必填 | 说明                                                       |
| ------------ | --------------------------------------------- | ---- | ---------------------------------------------------------- |
| event        | string                                        | 是   | 取消订阅的事件名，固定为'syncComplete'，表示同步完成事件。 |
| syncCallback | Callback&lt;Array&lt;[string, number]&gt;&gt; | 否   | 取消订阅的同步完成回调函数。如果该参数不填，则取消所有已订阅的同步完成回调函数。需要注意的是：如果同一个数据库存在多个ArkTS实例（通过[getKVStore](#getkvstore)接口获取），且这些实例分别注册了同步完成事件回调，那么当任意一个实例调用off('syncComplete')且不传入syncCallback参数（即取消该实例的所有回调）时，其他实例已订阅的同步完成回调函数也会被一并取消。  |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

class KvstoreModel {
  call(data: [string, number][]) {
    console.info(`syncComplete : ${data}`);
  }

  subscribeDataChange() {
    try {
      if (kvStore != null) {
        kvStore.on('syncComplete', this.call);
      }
    } catch (err) {
      let error = err as BusinessError;
      console.error(`Failed to subscribeDataChange. Code: ${error.code}, message: ${error.message}`);
    }
  }

  unsubscribeDataChange() {
    try {
      if (kvStore != null) {
        kvStore.off('syncComplete', this.call);
      }
    } catch (err) {
      let error = err as BusinessError;
      console.error(`Failed to unsubscribeDataChange. Code: ${error.code}, message: ${error.message}`);
    }
  } 
}
```

### getSecurityLevel

getSecurityLevel(callback: AsyncCallback&lt;SecurityLevel&gt;): void

获取数据库的安全级别，使用callback异步回调。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名   | 类型                                             | 必填 | 说明                             |
| -------- | ---------------------------------------------------- | ---- | -------------------------------- |
| callback | AsyncCallback&lt;[SecurityLevel](#securitylevel)&gt; | 是   | 回调函数。返回数据库的安全级别。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 15100005     | Database or result set already closed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  kvStore.getSecurityLevel((err: BusinessError, data: distributedKVStore.SecurityLevel) => {
    if (err) {
      console.error(`Failed to get SecurityLevel. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in getting securityLevel');
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### getSecurityLevel

getSecurityLevel(): Promise&lt;SecurityLevel&gt;

获取数据库的安全级别，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**返回值：**

| 类型                                           | 说明                                |
| ---------------------------------------------- | ----------------------------------- |
| Promise&lt;[SecurityLevel](#securitylevel)&gt; | Promise对象。返回数据库的安全级别。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 15100005     | Database or result set already closed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  kvStore.getSecurityLevel().then((data: distributedKVStore.SecurityLevel) => {
    console.info('Succeeded in getting securityLevel');
  }).catch((err: BusinessError) => {
    console.error(`Failed to get SecurityLevel. Code: ${err.code}, message: ${err.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### rekey

rekey(): Promise&lt;void&gt;

更新数据库的加密密钥，使用Promise异步回调。

> **说明：**
>
> rekey仅对创建时已启用加密的数据库有效，即Options中encrypt需设置为true，非加密数据库调用此接口将返回错误。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 15100003     | Database corrupted. |
| 15100005     | Database or result set already closed. |
| 15100006     | Failed to update the key. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  kvStore.rekey().then(() => {
    console.info('Success');
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to rekey. Code: ${error.code}, message: ${error.message}`);
}
```

## DeviceKVStore

设备协同数据库，继承自SingleKVStore，提供查询数据和端端同步数据的方法，可以使用SingleKVStore的方法例如：put、putBatch等。

设备协同数据库，以设备维度对数据进行区分，每台设备仅能写入和修改本设备的数据，其它设备的数据对其是只读的，无法修改其它设备的数据。

比如，可以使用设备协同数据库实现设备间的图片分享，可以查看其他设备的图片，但无法修改和删除其他设备的图片。

在调用DeviceKVStore的方法前，需要先通过[getKVStore](#getkvstore)构建一个DeviceKVStore实例。

### get

get(key: string, callback: AsyncCallback&lt;boolean | string | number | Uint8Array&gt;): void

获取本设备指定键的值，使用callback异步回调。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| key      | string                                                       | 是   | 要查询数据的Key，不能为空且长度范围为1-[MAX_KEY_LENGTH](#constants)。 |
| callback | AsyncCallback&lt;boolean \| string \| number \| Uint8Array&gt; | 是   | 回调函数。返回获取查询的值。                                 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)和[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed.  |
| 15100003     | Database corrupted.                    |
| 15100004     | Not found.                             |
| 15100005     | Database or result set already closed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const KEY_TEST_STRING_ELEMENT = 'key_test_string';
const VALUE_TEST_STRING_ELEMENT = 'value-test-string';
try {
  kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to put. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in putting');
    if (kvStore != null) {
      kvStore.get(KEY_TEST_STRING_ELEMENT, (err: BusinessError, data: boolean | string | number | Uint8Array) => {
        if (err) {
          console.error(`Failed to get. Code: ${err.code}, message: ${err.message}`);
          return;
        }
        console.info(`Succeeded in getting data. Data=${data}`);
      });
    }
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to get. Code: ${error.code}, message: ${error.message}`);
}
```

### get

get(key: string): Promise&lt;boolean | string | number | Uint8Array&gt;

获取本设备指定键的值，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| key    | string | 是   | 要查询数据的Key，不能为空且长度范围为1-[MAX_KEY_LENGTH](#constants)。 |

**返回值：**

| 类型                                                     | 说明                            |
| -------------------------------------------------------- | ------------------------------- |
| Promise&lt;boolean \| string \| number \| Uint8Array&gt; | Promise对象。返回获取查询的值，值的类型取决于存储时的数据类型。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)和[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed.  |
| 15100003     | Database corrupted.                    |
| 15100004     | Not found.                             |
| 15100005     | Database or result set already closed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const KEY_TEST_STRING_ELEMENT = 'key_test_string';
const VALUE_TEST_STRING_ELEMENT = 'value-test-string';
try {
  kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT).then(() => {
    console.info(`Succeeded in putting data`);
    if (kvStore != null) {
      kvStore.get(KEY_TEST_STRING_ELEMENT).then((data: boolean | string | number | Uint8Array) => {
        console.info(`Succeeded in getting data.data=${data}`);
      }).catch((err: BusinessError) => {
        console.error(`Failed to get. Code: ${err.code}, message: ${err.message}`);
      });
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to put. Code: ${err.code}, message: ${err.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to get. Code: ${error.code}, message: ${error.message}`);
}
```

### get

get(deviceId: string, key: string, callback: AsyncCallback&lt;boolean | string | number | Uint8Array&gt;): void

获取与指定设备ID和Key匹配的值，使用callback异步回调。
> **说明：**
>
> 其中deviceId通过调用[deviceManager.getAvailableDeviceListSync](../apis-distributedservice-kit/js-apis-distributedDeviceManager.md#getavailabledevicelistsync)方法得到。
> deviceId具体获取方式请参考[sync接口示例](#sync)。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**参数：**

| 参数名  | 类型 | 必填  | 说明                    |
| -----  | ------   | ----  | ----------------------- |
| deviceId  |string  | 是    |设备的networkId，标识要查询其数据的设备，不能为空。    |
| key       |string  | 是    |要查询数据的键名，不能为空且长度范围为1-[MAX_KEY_LENGTH](#constants)。    |
| callback  |AsyncCallback&lt;boolean \| string \| number \| Uint8Array&gt;  | 是    |回调函数。成功时返回匹配给定条件的值（值的类型取决于存储时的数据类型），失败时返回错误对象。    |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)和[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed.  |
| 15100003     | Database corrupted.                    |
| 15100004     | Not found.                             |
| 15100005     | Database or result set already closed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const KEY_TEST_STRING_ELEMENT = 'key_test_string_2';
const VALUE_TEST_STRING_ELEMENT = 'value-string-002';
try {
  kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT, async (err: BusinessError) => {
    if (err) {
      console.error(`Failed to put. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in putting');
    if (kvStore != null) {
      kvStore.get('localDeviceId', KEY_TEST_STRING_ELEMENT, (err: BusinessError, data: boolean | string | number | Uint8Array) => {
        if (err) {
          console.error(`Failed to get. Code: ${err.code}, message: ${err.message}`);
          return;
        }
        console.info('Succeeded in getting');
      });
    }
  })
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to get. Code: ${error.code}, message: ${error.message}`);
}
```

### get

get(deviceId: string, key: string): Promise&lt;boolean | string | number | Uint8Array&gt;

获取与指定设备ID和Key匹配的值，使用Promise异步回调。
> **说明：**
>
> 其中deviceId通过调用[deviceManager.getAvailableDeviceListSync](../apis-distributedservice-kit/js-apis-distributedDeviceManager.md#getavailabledevicelistsync)方法得到。
> deviceId具体获取方式请参考[sync接口示例](#sync)。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**参数：**

| 参数名   | 类型 | 必填 | 说明                     |
| -------- | -------- | ---- | ------------------------ |
| deviceId | string   | 是   | 设备的networkId，标识要查询其数据的设备，不能为空。 |
| key      | string   | 是   | 表示要查询Key值的键，不能为空且长度范围为1-[MAX_KEY_LENGTH](#constants)。    |

**返回值：**

| 类型    | 说明       |
| ------  | -------   |
|Promise&lt;boolean \| string \| number \| Uint8Array&gt; |Promise对象。返回匹配给定条件的值，值的类型取决于存储时的数据类型。|

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)和[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed.  |
| 15100003     | Database corrupted.                    |
| 15100004     | Not found.                             |
| 15100005     | Database or result set already closed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const KEY_TEST_STRING_ELEMENT = 'key_test_string_2';
const VALUE_TEST_STRING_ELEMENT = 'value-string-002';
try {
  kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT).then(async () => {
    console.info('Succeeded in putting');
    if (kvStore != null) {
      kvStore.get('localDeviceId', KEY_TEST_STRING_ELEMENT).then((data: boolean | string | number | Uint8Array) => {
        console.info('Succeeded in getting');
      }).catch((err: BusinessError) => {
        console.error(`Failed to get. Code: ${err.code}, message: ${err.message}`);
      });
    }
  }).catch((error: BusinessError) => {
    console.error(`Failed to put. Code: ${error.code}, message: ${error.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to get. Code: ${error.code}, message: ${error.message}`);
}
```

### getEntries

getEntries(keyPrefix: string, callback: AsyncCallback&lt;Entry[]&gt;): void

获取匹配本设备指定键前缀的所有键值对，使用callback异步回调。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名    | 类型                                   | 必填 | 说明                                     |
| --------- | -------------------------------------- | ---- | ---------------------------------------- |
| keyPrefix | string                                 | 是   | 表示要匹配的键前缀，长度范围为1-[MAX_KEY_LENGTH](#constants)。不能包含'^'，包含'^'将导致谓词失效，查询结果会返回数据库中的所有数据。 |
| callback  | AsyncCallback&lt;[Entry](#entry)[]&gt; | 是   | 回调函数。返回匹配指定前缀的键值对列表。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)和[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.|
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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
  kvStore.putBatch(entries, async (err: BusinessError) => {
    if (err) {
      console.error(`Failed to put Batch. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in putting Batch');
    if (kvStore != null) {
      kvStore.getEntries('batch_test_string_key', (err: BusinessError, entries: distributedKVStore.Entry[]) => {
        if (err) {
          console.error(`Failed to get Entries. Code: ${err.code}, message: ${err.message}`);
          return;
        }
        console.info('Succeeded in getting Entries');
        console.info(`entries.length: ${entries.length}`);
        console.info(`entries[0]: ${entries[0]}`);
      });
    }
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### getEntries

getEntries(keyPrefix: string): Promise&lt;Entry[]&gt;

获取匹配本设备指定键前缀的所有键值对，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名    | 类型   | 必填 | 说明                 |
| --------- | ------ | ---- | -------------------- |
| keyPrefix | string | 是   | 表示要匹配的键前缀，长度范围为1-[MAX_KEY_LENGTH](#constants)。不能包含'^'，包含'^'将导致谓词失效，查询结果会返回数据库中的所有数据。 |

**返回值：**

| 类型                             | 说明                                        |
| -------------------------------- | ------------------------------------------- |
| Promise&lt;[Entry](#entry)[]&gt; | Promise对象。返回匹配指定前缀的键值对列表。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)和[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.|
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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
    if (kvStore != null) {
      kvStore.getEntries('batch_test_string_key').then((entries: distributedKVStore.Entry[]) => {
        console.info('Succeeded in getting Entries');
        console.info(`PutBatch ${entries}`);
      }).catch((err: BusinessError) => {
        console.error(`Failed to get Entries. Code: ${err.code}, message: ${err.message}`);
      });
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to put Batch. Code: ${err.code}, message: ${err.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### getEntries

getEntries(deviceId: string, keyPrefix: string, callback: AsyncCallback&lt;Entry[]&gt;): void

获取与指定设备ID和Key前缀匹配的所有键值对，使用callback异步回调。
> **说明：**
>
> 其中deviceId通过调用[deviceManager.getAvailableDeviceListSync](../apis-distributedservice-kit/js-apis-distributedDeviceManager.md#getavailabledevicelistsync)方法得到。
> deviceId具体获取方式请参考[sync接口示例](#sync)。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**参数：**

| 参数名    | 类型                               | 必填 | 说明                                           |
| --------- | -------------------------------------- | ---- | ---------------------------------------------- |
| deviceId  | string                                 | 是   | 设备的networkId，标识要查询其数据的设备，不能为空。                       |
| keyPrefix | string                                 | 是   | 表示要匹配的键前缀，长度范围为1-[MAX_KEY_LENGTH](#constants)。不能包含'^'，包含'^'将导致谓词失效，查询结果会返回数据库中的所有数据。 |
| callback  | AsyncCallback&lt;[Entry](#entry)[]&gt; | 是   | 回调函数，返回满足给定条件的所有键值对的列表。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)和[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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
  kvStore.putBatch(entries, async (err: BusinessError) => {
    if (err) {
      console.error(`Failed to put batch. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in putting batch');
    if (kvStore != null) {
      kvStore.getEntries('localDeviceId', 'batch_test_string_key', (err: BusinessError, entries: distributedKVStore.Entry[]) => {
        if (err) {
          console.error(`Failed to get entries. Code: ${err.code}, message: ${err.message}`);
          return;
        }
        console.info('Succeeded in getting entries');
        console.info(`entries.length: ${entries.length}`);
        console.info(`entries[0]: ${entries[0]}`);
      });
    }
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to put batch. Code: ${error.code}, message: ${error.message}`);
}
```

### getEntries

getEntries(deviceId: string, keyPrefix: string): Promise&lt;Entry[]&gt;

获取与指定设备ID和Key前缀匹配的所有键值对，使用Promise异步回调。
> **说明：**
>
> 其中deviceId通过调用[deviceManager.getAvailableDeviceListSync](../apis-distributedservice-kit/js-apis-distributedDeviceManager.md#getavailabledevicelistsync)方法得到。
> deviceId具体获取方式请参考[sync接口示例](#sync)。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**参数：**

| 参数名    | 类型 | 必填 | 说明                     |
| --------- | -------- | ---- | ------------------------ |
| deviceId  | string   | 是   | 设备的networkId，标识要查询其数据的设备，不能为空。 |
| keyPrefix | string   | 是   | 表示要匹配的键前缀，长度范围为1-[MAX_KEY_LENGTH](#constants)。不能包含'^'，包含'^'将导致谓词失效，查询结果会返回数据库中的所有数据。|

**返回值：**

| 类型                             | 说明                                              |
| -------------------------------- | ------------------------------------------------- |
| Promise&lt;[Entry](#entry)[]&gt; | Promise对象。返回匹配给定条件的所有键值对的列表。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)和[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.|
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**示例：**

<!--code_no_check-->
```ts
import { BusinessError } from '@kit.BasicServicesKit';

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
    if (kvStore != null) {
      kvStore.getEntries('localDeviceId', 'batch_test_string_key').then((entries: distributedKVStore.Entry[]) => {
        console.info('Succeeded in getting entries');
        console.info(`entries.length: ${entries.length}`);
        console.info(`entries[0]: ${entries[0]}`);
        console.info(`entries[0].value: ${entries[0].value}`);
        console.info(`entries[0].value.value: ${entries[0].value.value}`);
      }).catch((err: BusinessError) => {
        console.error(`Failed to get entries. Code: ${err.code}, message: ${err.message}`);
      });
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to put batch. Code: ${err.code}, message: ${err.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to put batch. Code: ${error.code}, message: ${error.message}`);
}
```

### getEntries

getEntries(query: Query, callback: AsyncCallback&lt;Entry[]&gt;): void

获取本设备与指定Query对象匹配的键值对列表，使用callback异步回调。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名   | 类型                                   | 必填 | 说明                            |
| -------- | -------------------------------------- | ---- |-------------------------------|
| query    | [Query](#query)                         | 是   | 表示要查询的对象。                     |
| callback | AsyncCallback&lt;[Entry](#entry)[]&gt; | 是   | 回调函数。返回本设备与指定Query对象匹配的键值对列表。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)和[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.|
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let arr = new Uint8Array([21, 31]);
  let entries: distributedKVStore.Entry[] = [];
  for (let i = 0; i < 10; i++) {
    let key = 'batch_test_bool_key';
    let entry: distributedKVStore.Entry = {
      key: key + i,
      value: {
        type: distributedKVStore.ValueType.BYTE_ARRAY,
        value: arr
      }
    }
    entries.push(entry);
  }
  console.info(`entries: ${entries}`);
  kvStore.putBatch(entries, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to put Batch. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in putting Batch');
    const query = new distributedKVStore.Query();
    query.prefixKey('batch_test');
    if (kvStore != null) {
      kvStore.getEntries(query, (err: BusinessError, entries: distributedKVStore.Entry[]) => {
        if (err) {
          console.error(`Failed to get Entries. Code: ${err.code}, message: ${err.message}`);
          return;
        }
        console.info('Succeeded in getting Entries');
        console.info(`entries.length: ${entries.length}`);
        console.info(`entries[0]: ${entries[0]}`);
      });
    }
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to get Entries. Code: ${error.code}, message: ${error.message}`);
}
```

### getEntries

getEntries(query: Query): Promise&lt;Entry[]&gt;

获取本设备与指定Query对象匹配的键值对列表，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名 | 类型           | 必填 | 说明           |
| ------ | -------------- | ---- | -------------- |
| query  | [Query](#query) | 是   | 表示查询对象。 |

**返回值：**

| 类型                             | 说明                                                     |
| -------------------------------- | -------------------------------------------------------- |
| Promise&lt;[Entry](#entry)[]&gt; | Promise对象。返回本设备与指定Query对象匹配的键值对列表。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)和[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.|
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let arr = new Uint8Array([21, 31]);
  let entries: distributedKVStore.Entry[] = [];
  for (let i = 0; i < 10; i++) {
    let key = 'batch_test_bool_key';
    let entry: distributedKVStore.Entry = {
      key: key + i,
      value: {
        type: distributedKVStore.ValueType.BYTE_ARRAY,
        value: arr
      }
    }
    entries.push(entry);
  }
  console.info(`entries: ${entries}`);
  kvStore.putBatch(entries).then(async () => {
    console.info('Succeeded in putting Batch');
    const query = new distributedKVStore.Query();
    query.prefixKey('batch_test');
    if (kvStore != null) {
      kvStore.getEntries(query).then((entries: distributedKVStore.Entry[]) => {
        console.info('Succeeded in getting Entries');
      }).catch((err: BusinessError) => {
        console.error(`Failed to get Entries. Code: ${err.code}, message: ${err.message}`);
      });
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to get Entries. Code: ${err.code}, message: ${err.message}`);
  });
  console.info('Succeeded in getting Entries');
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to get Entries. Code: ${error.code}, message: ${error.message}`);
}
```

### getEntries

getEntries(deviceId: string, query: Query, callback: AsyncCallback&lt;Entry[]&gt;): void

获取与指定设备ID和Query对象匹配的键值对列表，使用callback异步回调。
> **说明：**
>
> 其中deviceId通过调用[deviceManager.getAvailableDeviceListSync](../apis-distributedservice-kit/js-apis-distributedDeviceManager.md#getavailabledevicelistsync)方法得到。
> deviceId具体获取方式请参考[sync接口示例](#sync)。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**参数：**

| 参数名   | 类型                               | 必填 | 说明                                                    |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------- |
| deviceId | string                                 | 是   | 设备的networkId，标识要查询其数据的设备，不能为空。                                    |
| query    | [Query](#query)                         | 是   | 表示查询对象。                                          |
| callback | AsyncCallback&lt;[Entry](#entry)[]&gt; | 是   | 回调函数。返回与指定设备ID和Query对象匹配的键值对列表。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)和[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.|
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let arr = new Uint8Array([21, 31]);
  let entries: distributedKVStore.Entry[] = [];
  for (let i = 0; i < 10; i++) {
    let key = 'batch_test_bool_key';
    let entry: distributedKVStore.Entry = {
      key: key + i,
      value: {
        type: distributedKVStore.ValueType.BYTE_ARRAY,
        value: arr
      }
    }
    entries.push(entry);
  }
  console.info(`entries: ${entries}`);
  kvStore.putBatch(entries, async (err: BusinessError) => {
    if (err) {
      console.error(`Failed to put batch. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in putting batch');
    let query = new distributedKVStore.Query();
    query.deviceId('localDeviceId');
    query.prefixKey('batch_test');
    if (kvStore != null) {
      kvStore.getEntries('localDeviceId', query, (err: BusinessError, entries: distributedKVStore.Entry[]) => {
        if (err) {
          console.error(`Failed to get entries. Code: ${err.code}, message: ${err.message}`);
          return;
        }
        console.info('Succeeded in getting entries');
        console.info(`entries.length: ${entries.length}`);
        console.info(`entries[0]: ${entries[0]}`);
      })
    }
  });
  console.info('Succeeded in getting entries');
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to get entries. Code: ${error.code}, message: ${error.message}`);
}
```

### getEntries

getEntries(deviceId: string, query: Query): Promise&lt;Entry[]&gt;

获取与指定设备ID和Query对象匹配的键值对列表，使用Promise异步回调。
> **说明：**
>
> 其中deviceId通过调用[deviceManager.getAvailableDeviceListSync](../apis-distributedservice-kit/js-apis-distributedDeviceManager.md#getavailabledevicelistsync)方法得到。
> deviceId具体获取方式请参考[sync接口示例](#sync)。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**参数：**

| 参数名   | 类型       | 必填 | 说明                 |
| -------- | -------------- | ---- | -------------------- |
| deviceId | string         | 是   | 设备的networkId，标识要查询其数据的设备，不能为空。 |
| query    | [Query](#query) | 是   | 表示查询对象。       |

**返回值：**

| 类型                             | 说明                                                       |
| -------------------------------- | ---------------------------------------------------------- |
| Promise&lt;[Entry](#entry)[]&gt; | Promise对象。返回与指定设备ID和Query对象匹配的键值对列表。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)和[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.|
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**示例：**

<!--code_no_check-->
```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let arr = new Uint8Array([21, 31]);
  let entries: distributedKVStore.Entry[] = [];
  for (let i = 0; i < 10; i++) {
    let key = 'batch_test_bool_key';
    let entry: distributedKVStore.Entry = {
      key: key + i,
      value: {
        type: distributedKVStore.ValueType.BYTE_ARRAY,
        value: arr
      }
    }
    entries.push(entry);
  }
  console.info(`entries: ${entries}`);
  kvStore.putBatch(entries).then(async () => {
    console.info('Succeeded in putting batch');
    let query = new distributedKVStore.Query();
    query.deviceId('localDeviceId');
    query.prefixKey('batch_test');
    if (kvStore != null) {
      kvStore.getEntries('localDeviceId', query).then((entries: distributedKVStore.Entry[]) => {
        console.info('Succeeded in getting entries');
      }).catch((err: BusinessError) => {
        console.error(`Failed to get entries. Code: ${err.code}, message: ${err.message}`);
      });
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to put batch. Code: ${err.code}, message: ${err.message}`);
  });
  console.info('Succeeded in getting entries');
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to get entries. Code: ${error.code}, message: ${error.message}`);
}
```

### getResultSet

getResultSet(keyPrefix: string, callback: AsyncCallback&lt;KVStoreResultSet&gt;): void

从DeviceKVStore数据库中获取本设备具有指定前缀的结果集，使用callback异步回调。获取结果集后，在使用完毕时需调用[closeResultSet](#closeresultset)关闭结果集释放资源。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名    | 类型                                                       | 必填 | 说明                                                                                 |
| --------- | ---------------------------------------------------------- | ---- |------------------------------------------------------------------------------------|
| keyPrefix | string   | 是   | 表示要匹配的键前缀，长度范围为1-[MAX_KEY_LENGTH](#constants)。不能包含'^'，包含'^'将导致谓词失效，查询结果会返回数据库中的所有数据。 |
| callback  | AsyncCallback&lt;[KVStoreResultSet](#kvstoreresultset)&gt; | 是   | 回调函数。返回具有指定前缀的结果集。                                                                 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)和[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                                                                                     |
| ------------ |--------------------------------------------------------------------------------------------------------------|
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |
| 15100001     | Over max limits.<br/>适用版本：10+                                                                                |
| 15100003     | Database corrupted.                                                                                          |
| 15100005     | Database or result set already closed.                                                                       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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
  kvStore.putBatch(entries, async (err: BusinessError) => {
    if (err) {
      console.error(`Failed to put batch. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in putting batch');
    if (kvStore != null) {
      kvStore.getResultSet('batch_test_string_key', async (err: BusinessError, result: distributedKVStore.KVStoreResultSet) => {
        if (err) {
          console.error(`Failed to get resultset. Code: ${err.code}, message: ${err.message}`);
          return;
        }
        console.info('Succeeded in getting result set');
        resultSet = result;
        if (kvStore != null) {
          kvStore.closeResultSet(resultSet, (err: BusinessError) => {
            if (err) {
              console.error(`Failed to close resultset. Code: ${err.code}, message: ${err.message}`);
              return;
            }
            console.info('Succeeded in closing result set');
          })
        }
      });
    }
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### getResultSet

getResultSet(keyPrefix: string): Promise&lt;KVStoreResultSet&gt;

从DeviceKVStore数据库中获取本设备具有指定前缀的结果集，使用Promise异步回调。获取结果集后，在使用完毕时需调用[closeResultSet](#closeresultset)关闭结果集释放资源。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名    | 类型   | 必填 | 说明                 |
| --------- | ------ | ---- | -------------------- |
| keyPrefix | string | 是   | 表示要匹配的键前缀，长度范围为1-[MAX_KEY_LENGTH](#constants)。不能包含'^'，包含'^'将导致谓词失效，查询结果会返回数据库中的所有数据。 |

**返回值：**

| 类型                                                 | 说明                                    |
| ---------------------------------------------------- | --------------------------------------- |
| Promise&lt;[KVStoreResultSet](#kvstoreresultset)&gt; | Promise对象。返回具有指定前缀的结果集。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)和[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.|
| 15100001     | Over max limits.<br/>适用版本：10+                       |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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
    kvStore.getResultSet('batch_test_string_key').then((result: distributedKVStore.KVStoreResultSet) => {
      console.info('Succeeded in getting result set');
      resultSet = result;
      if (kvStore != null) {
        kvStore.closeResultSet(resultSet).then(() => {
          console.info('Succeeded in closing result set');
        }).catch((err: BusinessError) => {
          console.error(`Failed to close resultset. Code: ${err.code}, message: ${err.message}`);
        });
      }
    }).catch((err: BusinessError) => {
      console.error(`Failed to get resultset. Code: ${err.code}, message: ${err.message}`);
    });
  }).catch((err: BusinessError) => {
    console.error(`Failed to put batch. Code: ${err.code}, message: ${err.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### getResultSet

getResultSet(deviceId: string, keyPrefix: string, callback: AsyncCallback&lt;KVStoreResultSet&gt;): void

获取与指定设备ID和Key前缀匹配的KVStoreResultSet对象，使用callback异步回调。
> **说明：**
>
> 其中deviceId通过调用[deviceManager.getAvailableDeviceListSync](../apis-distributedservice-kit/js-apis-distributedDeviceManager.md#getavailabledevicelistsync)方法得到。
> deviceId具体获取方式请参考[sync接口示例](#sync)。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**参数：**

| 参数名    | 类型                                                     | 必填 | 说明                                                         |
| --------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| deviceId  | string                                                       | 是   | 设备的networkId，标识要查询其数据的设备，不能为空。                                     |
| keyPrefix | string                                                       | 是   | 表示要匹配的键前缀，长度范围为1-[MAX_KEY_LENGTH](#constants)。不能包含'^'，包含'^'将导致谓词失效，查询结果会返回数据库中的所有数据。 |
| callback  | AsyncCallback&lt;[KVStoreResultSet](#kvstoreresultset)&gt; | 是   | 回调函数。返回与指定设备ID和Key前缀匹配的KVStoreResultSet对象。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)和[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.|
| 15100001     | Over max limits.<br/>适用版本：10+                       |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let resultSet: distributedKVStore.KVStoreResultSet;
  kvStore.getResultSet('localDeviceId', 'batch_test_string_key', async (err: BusinessError, result: distributedKVStore.KVStoreResultSet) => {
    if (err) {
      console.error(`Failed to get resultSet. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in getting resultSet');
    resultSet = result;
    if (kvStore != null) {
      kvStore.closeResultSet(resultSet, (err: BusinessError) => {
        if (err) {
          console.error(`Failed to close resultSet. Code: ${err.code}, message: ${err.message}`);
          return;
        }
        console.info('Succeeded in closing resultSet');
      })
    }
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to get resultSet. Code: ${error.code}, message: ${error.message}`);
}
```

### getResultSet

getResultSet(deviceId: string, keyPrefix: string): Promise&lt;KVStoreResultSet&gt;

获取与指定设备ID和Key前缀匹配的KVStoreResultSet对象，使用Promise异步回调。
> **说明：**
>
> 其中deviceId通过调用[deviceManager.getAvailableDeviceListSync](../apis-distributedservice-kit/js-apis-distributedDeviceManager.md#getavailabledevicelistsync)方法得到。
> deviceId具体获取方式请参考[sync接口示例](#sync)。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**参数：**

| 参数名    | 类型 | 必填 | 说明                     |
| --------- | -------- | ---- | ------------------------ |
| deviceId  | string   | 是   | 设备的networkId，标识要查询其数据的设备，不能为空。 |
| keyPrefix | string   | 是   | 表示要匹配的键前缀，长度范围为1-[MAX_KEY_LENGTH](#constants)。不能包含'^'，包含'^'将导致谓词失效，查询结果会返回数据库中的所有数据。 |

**返回值：**

| 类型                                                   | 说明                                                         |
| ------------------------------------------------------ | ------------------------------------------------------------ |
| Promise&lt;[KVStoreResultSet](#kvstoreresultset)&gt; | Promise对象。返回与指定设备ID和Key前缀匹配的KVStoreResultSet对象。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)和[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.|
| 15100001     | Over max limits.<br/>适用版本：10+                       |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**示例：**

<!--code_no_check-->
```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let resultSet: distributedKVStore.KVStoreResultSet;
  kvStore.getResultSet('localDeviceId', 'batch_test_string_key').then((result: distributedKVStore.KVStoreResultSet) => {
    console.info('Succeeded in getting resultSet');
    resultSet = result;
    if (kvStore != null) {
      kvStore.closeResultSet(resultSet).then(() => {
        console.info('Succeeded in closing resultSet');
      }).catch((err: BusinessError) => {
        console.error(`Failed to close resultSet. Code: ${err.code}, message: ${err.message}`);
      });
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to get resultSet. Code: ${err.code}, message: ${err.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to get resultSet. Code: ${error.code}, message: ${error.message}`);
}
```

### getResultSet

getResultSet(deviceId: string, query: Query, callback: AsyncCallback&lt;KVStoreResultSet&gt;): void

获取与指定设备ID和Query对象匹配的KVStoreResultSet对象，使用callback异步回调。获取结果集后，在使用完毕时需调用[closeResultSet](#closeresultset)关闭结果集释放资源。
> **说明：**
>
> 其中deviceId通过调用[deviceManager.getAvailableDeviceListSync](../apis-distributedservice-kit/js-apis-distributedDeviceManager.md#getavailabledevicelistsync)方法得到。
> deviceId具体获取方式请参考[sync接口示例](#sync)。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**参数：**

| 参数名   | 类型                                                     | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| deviceId | string                                                       | 是   | 设备的networkId，标识要查询其数据的设备，不能为空。                    |
| query    | [Query](#query)                                               | 是   | 表示查询对象。                                               |
| callback | AsyncCallback&lt;[KVStoreResultSet](#kvstoreresultset)&gt; | 是   | 回调函数。返回与指定设备ID和Query对象匹配的KVStoreResultSet对象。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)和[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.|
| 15100001     | Over max limits.<br/>适用版本：10+                       |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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
  kvStore.putBatch(entries, async (err: BusinessError) => {
    if (err) {
      console.error(`Failed to put batch. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in putting batch');
    const query = new distributedKVStore.Query();
    query.prefixKey('batch_test');
    if (kvStore != null) {
      kvStore.getResultSet('localDeviceId', query, async (err: BusinessError, result: distributedKVStore.KVStoreResultSet) => {
        if (err) {
          console.error(`Failed to get resultSet. Code: ${err.code}, message: ${err.message}`);
          return;
        }
        console.info('Succeeded in getting resultSet');
        resultSet = result;
        if (kvStore != null) {
          kvStore.closeResultSet(resultSet, (err: BusinessError) => {
            if (err) {
              console.error(`Failed to close resultSet. Code: ${err.code}, message: ${err.message}`);
              return;
            }
            console.info('Succeeded in closing resultSet');
          })
        }
      });
    }
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to get resultSet. Code: ${error.code}, message: ${error.message}`);
}
```

### getResultSet

getResultSet(deviceId: string, query: Query): Promise&lt;KVStoreResultSet&gt;

获取与指定设备ID和Query对象匹配的KVStoreResultSet对象，使用Promise异步回调。获取结果集后，在使用完毕时需调用[closeResultSet](#closeresultset)关闭结果集释放资源。
> **说明：**
>
> 其中deviceId通过调用[deviceManager.getAvailableDeviceListSync](../apis-distributedservice-kit/js-apis-distributedDeviceManager.md#getavailabledevicelistsync)方法得到。
> deviceId具体获取方式请参考[sync接口示例](#sync)。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**参数：**

| 参数名   | 类型       | 必填 | 说明                               |
| -------- | -------------- | ---- | ---------------------------------- |
| deviceId | string         | 是   | 设备的networkId，标识要查询其数据的设备，不能为空。 |
| query    | [Query](#query) | 是   | 表示查询对象。                     |

**返回值：**

| 类型                                                   | 说明                                                         |
| ------------------------------------------------------ | ------------------------------------------------------------ |
| Promise&lt;[KVStoreResultSet](#kvstoreresultset)&gt; | Promise对象。返回与指定设备ID和Query对象匹配的KVStoreResultSet对象。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)和[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.|
| 15100001     | Over max limits.<br/>适用版本：10+                       |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**示例：**

<!--code_no_check-->
```ts
import { BusinessError } from '@kit.BasicServicesKit';

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
    console.error(`Failed to put batch. Code: ${err.code}, message: ${err.message}`);
  });
  const query = new distributedKVStore.Query();
  query.prefixKey('batch_test');
  if (kvStore != null) {
    kvStore.getResultSet('localDeviceId', query).then((result: distributedKVStore.KVStoreResultSet) => {
      console.info('Succeeded in getting resultSet');
      resultSet = result;
      if (kvStore != null) {
        kvStore.closeResultSet(resultSet).then(() => {
          console.info('Succeeded in closing resultSet');
        }).catch((err: BusinessError) => {
          console.error(`Failed to close resultSet. Code: ${err.code}, message: ${err.message}`);
        });
      }
    }).catch((err: BusinessError) => {
      console.error(`Failed to get resultSet. Code: ${err.code}, message: ${err.message}`);
    });
  }
  query.deviceId('localDeviceId');
  console.info('GetResultSet ' + query.getSqlLike());

} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to get resultSet. Code: ${error.code}, message: ${error.message}`);
}
```

### getResultSet

getResultSet(query: Query): Promise&lt;KVStoreResultSet&gt;

获取与本设备指定Query对象匹配的KVStoreResultSet对象，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名 | 类型           | 必填 | 说明           |
| ------ | -------------- | ---- | -------------- |
| query  | [Query](#query) | 是   | 表示查询对象。 |

**返回值：**

| 类型                                                 | 说明                                                         |
| ---------------------------------------------------- | ------------------------------------------------------------ |
| Promise&lt;[KVStoreResultSet](#kvstoreresultset)&gt; | Promise对象。获取与本设备指定Query对象匹配的KVStoreResultSet对象。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)和[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.|
| 15100001     | Over max limits.<br/>适用版本：10+                       |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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
    console.error(`Failed to put batch. Code: ${err.code}, message: ${err.message}`);
  });
  const query = new distributedKVStore.Query();
  query.prefixKey('batch_test');
  kvStore.getResultSet(query).then((result: distributedKVStore.KVStoreResultSet) => {
    console.info('Succeeded in getting result set');
    resultSet = result;
  }).catch((err: BusinessError) => {
    console.error(`Failed to get resultset. Code: ${err.code}, message: ${err.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### getResultSet

getResultSet(query: Query, callback:AsyncCallback&lt;KVStoreResultSet&gt;): void

获取与本设备指定Query对象匹配的KVStoreResultSet对象，使用callback异步回调。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名   | 类型           | 必填 | 说明                               |
| -------- | -------------- | ---- | ---------------------------------- |
| query    | [Query](#query) | 是   | 表示查询对象。                     |
| callback    | AsyncCallback&lt;[KVStoreResultSet](#kvstoreresultset)&gt; | 是   | 回调函数。成功时返回与指定Query对象匹配的KVStoreResultSet对象，失败时返回错误对象。         |


**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)和[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.|
| 15100001     | Over max limits.<br/>适用版本：10+                       |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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
  kvStore.putBatch(entries, async (err: BusinessError) => {
    if (err) {
      console.error(`Failed to put batch. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in putting batch');
    const query = new distributedKVStore.Query();
    query.prefixKey('batch_test');
    if (kvStore != null) {
      kvStore.getResultSet(query, async (err: BusinessError, result: distributedKVStore.KVStoreResultSet) => {
        if (err) {
          console.error(`Failed to get resultSet. Code: ${err.code}, message: ${err.message}`);
          return;
        }
        console.info('Succeeded in getting resultSet');
        resultSet = result;
        if (kvStore != null) {
          kvStore.closeResultSet(resultSet, (err: BusinessError) => {
            if (err) {
              console.error(`Failed to close resultSet. Code: ${err.code}, message: ${err.message}`);
              return;
            }
            console.info('Succeeded in closing resultSet');
          })
        }
      });
    }
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to get resultSet. Code: ${error.code}, message: ${error.message}`);
}
```

### getResultSize

getResultSize(query: Query, callback: AsyncCallback&lt;number&gt;): void

获取与本设备指定Query对象匹配的结果数，使用callback异步回调。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                              |
| -------- | --------------------------- | ---- | ------------------------------------------------- |
| query    | [Query](#query)              | 是   | 表示查询对象。                                    |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调函数。返回与本设备指定Query对象匹配的结果数。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)和[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.  |
| 15100003     | Database corrupted.                    |
| 15100004     | Not found.                             |
| 15100005     | Database or result set already closed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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
  kvStore.putBatch(entries, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to put batch. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in putting batch');
    const query = new distributedKVStore.Query();
    query.prefixKey('batch_test');
    if (kvStore != null) {
      kvStore.getResultSize(query, (err: BusinessError, resultSize: number) => {
        if (err) {
          console.error(`Failed to get result size. Code: ${err.code}, message: ${err.message}`);
          return;
        }
        console.info('Succeeded in getting result set size');
      });
    }
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### getResultSize

getResultSize(query: Query): Promise&lt;number&gt;

获取与本设备指定Query对象匹配的结果数，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名 | 类型           | 必填 | 说明           |
| ------ | -------------- | ---- | -------------- |
| query  | [Query](#query) | 是   | 表示查询对象。 |

**返回值：**

| 类型                  | 说明                                                 |
| --------------------- | ---------------------------------------------------- |
| Promise&lt;number&gt; | Promise对象。获取与本设备指定Query对象匹配的结果数。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)和[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.  |
| 15100003     | Database corrupted.                    |
| 15100004     | Not found.                             |
| 15100005     | Database or result set already closed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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
    console.error(`Failed to put batch. Code: ${err.code}, message: ${err.message}`);
  });
  const query = new distributedKVStore.Query();
  query.prefixKey('batch_test');
  kvStore.getResultSize(query).then((resultSize: number) => {
    console.info('Succeeded in getting result set size');
  }).catch((err: BusinessError) => {
    console.error(`Failed to get result size. Code: ${err.code}, message: ${err.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### getResultSize

getResultSize(deviceId: string, query: Query, callback: AsyncCallback&lt;number&gt;): void

获取与指定设备ID和Query对象匹配的结果数，使用callback异步回调。
> **说明：**
>
> 其中deviceId通过调用[deviceManager.getAvailableDeviceListSync](../apis-distributedservice-kit/js-apis-distributedDeviceManager.md#getavailabledevicelistsync)方法得到。
> deviceId具体获取方式请参考[sync接口示例](#sync)。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                                |
| -------- | --------------------------- | ---- | --------------------------------------------------- |
| deviceId | string                      | 是   | 设备的networkId，标识要查询其数据的设备，不能为空。                  |
| query    | [Query](#query)              | 是   | 表示查询对象。                                      |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调函数。返回与指定设备ID和Query对象匹配的结果数。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)和[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.  |
| 15100003     | Database corrupted.                    |
| 15100004     | Not found.                             |
| 15100005     | Database or result set already closed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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
  kvStore.putBatch(entries, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to put batch. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in putting batch');
    const query = new distributedKVStore.Query();
    query.prefixKey('batch_test');
    if (kvStore != null) {
      kvStore.getResultSize('localDeviceId', query, (err: BusinessError, resultSize: number) => {
        if (err) {
          console.error(`Failed to get resultSize. Code: ${err.code}, message: ${err.message}`);
          return;
        }
        console.info('Succeeded in getting resultSize');
      });
    }
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to get resultSize. Code: ${error.code}, message: ${error.message}`);
}
```

### getResultSize

getResultSize(deviceId: string, query: Query): Promise&lt;number&gt;

获取与指定设备ID和Query对象匹配的结果数，使用Promise异步回调。
> **说明：**
>
> 其中deviceId通过调用[deviceManager.getAvailableDeviceListSync](../apis-distributedservice-kit/js-apis-distributedDeviceManager.md#getavailabledevicelistsync)方法得到。
> deviceId具体获取方式请参考[sync接口示例](#sync)。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**参数：**

| 参数名   | 类型       | 必填 | 说明                               |
| -------- | -------------- | ---- | ---------------------------------- |
| deviceId | string         | 是   | 设备的networkId，标识要查询其数据的设备，不能为空。 |
| query    | [Query](#query) | 是   | 表示查询对象。                     |

**返回值：**

| 类型                  | 说明                                                   |
| --------------------- | ------------------------------------------------------ |
| Promise&lt;number&gt; | Promise对象。返回与指定设备ID和Query对象匹配的结果数。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)和[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.  |
| 15100003     | Database corrupted.                    |
| 15100004     | Not found.                             |
| 15100005     | Database or result set already closed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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
    console.error(`Failed to put batch. Code: ${err.code}, message: ${err.message}`);
  });
  let query = new distributedKVStore.Query();
  query.prefixKey('batch_test');
  kvStore.getResultSize('localDeviceId', query).then((resultSize: number) => {
    console.info('Succeeded in getting resultSize');
  }).catch((err: BusinessError) => {
    console.error(`Failed to get resultSize. Code: ${err.code}, message: ${err.message}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to get resultSize. Code: ${error.code}, message: ${error.message}`);
}
```