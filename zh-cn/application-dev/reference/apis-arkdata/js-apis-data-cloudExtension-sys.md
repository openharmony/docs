# @ohos.data.cloudExtension (端云共享Extension)(系统接口)

端云共享Extension，提供三方厂商适配共享云服务的能力。通过实现端云共享Extension提供的接口，对接端侧的数据共享到服务端，实现端云共享的发起、取消或退出，更改共享数据的操作权限、查询共享参与者、根据共享邀请码查询共享参与者、确认或更改共享邀请，并支持返回共享云服务的相关结果。

其中，端云共享资源标识是指：对于应用发起共享的每一条数据记录，该条数据在进行端云同步时会生成唯一的共享资源标识（字符串类型的值），此标识则作为该条数据记录共享时的识别标识。

端云共享参与者是指： 共享发起者根据好友列表选中的参与当前数据共享的所有人员。

端云共享邀请码是指： 共享发起后，在共享的服务端会生成当前共享操作的邀请码，并将该邀请码附加到当前共享邀请中，通过push消息推送到被邀请者的设备端，被邀请者可以通过该邀请码进行邀请的确认。

同步云是指： 端云同步的服务端，是同应用同账号跨设备的同步。

共享云是指： 端云共享的服务端，是同应用跨账号跨设备的共享。

> **说明：** 
>
> - 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本模块接口为系统接口。

## 导入模块

```ts
import { cloudExtension } from '@kit.ArkData';
```

## Result&lt;T&gt;

共享结果的返回值。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

| 名称          | 类型                          | 必填  | 说明           |
| ----------- | --------------------------- | --- | ------------ |
| code        | number                      | 是   | 错误码。       |
| description | string                      | 否   | 错误码详细描述，默认为undefined。       |
| value       | T                           | 否   | 返回结果的值，具体类型由参数T指定，默认为undefined。       |

## CloudAsset

云资产的信息。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

| 名称    | 类型   | 必填 | 说明                                 |
| ------- | ------ | ---- | ------------------------------------ |
| assetId | string | 是   | 资产ID。                             |
| hash    | string | 是   | 资产的修改时间和大小转化成的哈希值。 |

## CloudAssets

表示[CloudAsset](#cloudasset)类型的数组。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

| 类型                             | 说明                                      |
| -------------------------------- | ----------------------------------------- |
| Array<[CloudAsset](#cloudasset)> | 表示[CloudAsset](#cloudasset)类型的数组。 |

## ServiceInfo

云服务信息。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

| 名称           | 类型    | 必填 | 说明                                                         |
| -------------- | ------- | ---- | ------------------------------------------------------------ |
| enableCloud    | boolean | 是   | 表示是否启用了云服务。为true时是启用云服务，为false时是未启用。 |
| id             | string  | 是   | 使用哈希函数SHA256生成的云账号ID。                           |
| totalSpace     | number  | 是   | 服务器上账号的总空间（KB）。                                 |
| remainingSpace | number  | 是   | 服务器上账号的可用空间（KB）。                               |
| user           | number  | 是   | 设备的当前用户ID。                                           |

## Flag

描述数据库上执行操作的枚举。请使用枚举名而非枚举值。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

| 名称   | 值   | 说明       |
| ------ | ---- | ---------- |
| INSERT | 0    | 插入操作。 |
| UPDATE | 1    | 更新操作。 |
| DELETE | 2    | 删除操作。 |

## ExtensionValue

当前数据记录的扩展信息。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

| 名称       | 类型            | 只读 | 可选 | 说明                 |
| ---------- | --------------- | ---- | ---- | ------------------ |
| id         | string          | 是   | 否   | 执行插入操作时生成。 |
| createTime | number          | 是   | 否   | 创建行数据的时间。   |
| modifyTime | number          | 是   | 否   | 修改行数据的时间。   |
| operation  | [Flag](#flag)   | 是   | 否   | 对行数据所作的操作。 |

## CloudType

表示允许出现的云数据字段类型，接口参数具体类型根据其功能而定。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

| 类型                      | 说明                            |
| ------------------------- | ------------------------------- |
| null                      | 表示值的类型为空。              |
| number                    | 表示值的类型为数字类型。         |
| string                    | 表示值的类型为字符串类型。       |
| boolean                   | 表示值的类型为布尔类型。         |
| Uint8Array                | 表示值的类型为Uint8类型的数组。 |
| [CloudAsset](#cloudasset) | 表示值的类型为云资产类型。      |
| [CloudAssets](#cloudassets)            | 表示值的类型为云资产数组类型。   |

## CloudInfo

云信息。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

| 名称      | 类型                                                | 必填 | 说明           |
| --------- | --------------------------------------------------- | ---- | -------------- |
| cloudInfo | [ServiceInfo](#serviceinfo)                         | 是   | 云服务信息。   |
| apps      | Record&lt;string, [AppBriefInfo](#appbriefinfo)&gt; | 是   | 简要应用信息。 |

## CloudData

云数据。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

| 名称       | 类型                                                       | 必填 | 说明                                                         |
| ---------- | ---------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| nextCursor | string                                                     | 是   | 查询游标。                                                   |
| hasMore    | boolean                                                    | 是   | 服务器是否存在更多数据可供查询。true表示服务器上还有数据等待查询，false表示服务器上不存在可查询的数据。 |
| values     | Array&lt;Record&lt;string, [CloudType](#cloudtype)&gt;&gt; | 是   | 需要查询数据的数组，包括data value（数据值）和[ExtensionValue](#extensionvalue)（扩展值)。 |

## AppBriefInfo

简要应用信息。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

| 名称        | 类型    | 必填 | 说明                               |
| ----------- | ------- | ---- | ---------------------------------- |
| appId       | string  | 是   | 应用程序ID。                      |
| bundleName  | string  | 是   | 应用包名。                         |
| cloudSwitch | boolean | 是   | 云开关，表示应用程序是否启用云。true表示启用云，false表示不启用云。 |
| instanceId  | number  | 是   | 应用分身ID，0表示应用本身，分身ID依次递增。 |

## FieldType

描述数据库表中字段类型的枚举。请使用枚举名而非枚举值。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

| 名称                                               | 值   | 说明                                   |
| -------------------------------------------------- | ---- | -------------------------------------- |
| NULL                                               | 0    | 类型为空。                             |
| NUMBER                                             | 1    | 数值类型。                             |
| REAL                                               | 2    | 双精度浮点类型。                       |
| TEXT                                               | 3    | 文本类型。                             |
| BOOL                                               | 4    | 布尔类型。                             |
| BLOB                                               | 5    | 二进制大对象类型，可以存储二进制文件。 |
| [ASSET](js-apis-data-relationalStore.md#asset10)   | 6    | 资产类型。                             |
| [ASSETS](js-apis-data-relationalStore.md#assets10) | 7    | 资产列表类型。                         |

## Field

数据库中的字段结构。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

| 名称     | 类型                      | 必填 | 说明                   |
| -------- | ------------------------- | ---- | ---------------------- |
| alias    | string                    | 是   | 该字段在服务器表中的别名。 |
| colName  | string                    | 是   | 列名。                 |
| type     | [FieldType](#fieldtype) | 是   | 字段类型。             |
| primary  | boolean                   | 是   | 表示当前列是否是主键。true表示当前列为主键，false表示当前列不为主键。 |
| nullable | boolean                   | 是   | 当前列是否为空值，true表示当前列为空，false表示当前列不为空。      |

## Table

表结构信息。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

| 名称   | 类型                         | 必填 | 说明                         |
| ------ | ---------------------------- | ---- | ---------------------------- |
| alias  | string                       | 是   | 该表在服务器数据库中的别名。 |
| name   | string                       | 是   | 表名。                       |
| fields | Array&lt;[Field](#field)&gt; | 是   | 数据库表中的字段结构信息。   |

## Database

数据库结构信息。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

| 名称   | 类型                         | 必填 | 说明                             |
| ------ | ---------------------------- | ---- | -------------------------------- |
| name   | string                       | 是   | 数据库名称。                     |
| alias  | string                       | 是   | 该数据库在服务器中的别名。       |
| tables | Array&lt;[Table](#table)&gt; | 是   | 数据库中的表，包含数据详细信息。 |

## AppSchema

应用数据库模式。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

| 名称       | 类型                                 | 必填 | 说明               |
| ---------- | ------------------------------------ | ---- | ------------------ |
| bundleName | string                               | 是   | 应用包名。         |
| version    | number                               | 是   | 数据库模式的版本。 |
| databases  | Array&lt;[Database](#database)&gt; | 是   | 应用的数据库信息。 |

## SubscribeId

订阅ID。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

| 名称          | 类型   | 必填 | 说明                   |
| ------------- | ------ | ---- | ---------------------- |
| databaseAlias | string | 是   | 服务器上数据库的名称。 |
| id            | string | 是   | 订阅ID。              |

## SubscribeInfo

订阅信息。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

| 名称           | 类型                                                         | 必填 | 说明                 |
| -------------- | ------------------------------------------------------------ | ---- | -------------------- |
| expirationTime | number                                                       | 是   | 订阅过期时间（ms）。 |
| subscribe      | Record&lt;string, Array&lt;[SubscribeId](#subscribeid)&gt;&gt; | 是   | 订阅信息。           |

## LockInfo

云数据库锁信息。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

| 名称     | 类型   | 必填 | 说明                            |
| -------- | ------ | ---- | ------------------------------- |
| interval | number | 是   | 云数据库锁的持续时间，单位为s。 |
| lockId   | number | 是   | 锁ID。                          |

## ErrorCode

表示端云共享过程的状态。请使用枚举名而非枚举值。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

| 名称                  | 值   | 说明                                                         |
| --------------------- | ---- | ------------------------------------------------------------ |
| SUCCESS               | 0    | 表示端云同步过程成功。                                       |
| UNKNOWN_ERROR         | 1    | 表示端云同步过程中遇到未知错误。                             |
| NETWORK_ERROR         | 2    | 表示端云同步过程中遇到网络错误。                             |
| CLOUD_DISABLED        | 3    | 表示云同步开关未开启，请检查云空间同步开关状态。             |
| LOCKED_BY_OTHERS      | 4    | 表示有其他设备正在进行端云同步，本设备无法进行端云同步。请确保无其他设备占用端云资源后，在使用本设备进行端云同步任务。 |
| RECORD_LIMIT_EXCEEDED | 5    | 表示本次端云同步需要同步的条目或大小超出最大值。由云端配置最大值。 |
| NO_SPACE_FOR_ASSET    | 6    | 表示云空间剩余空间小于待同步的资产大小。                     |

## cloudExtension.createCloudServiceStub

createCloudServiceStub(instance: CloudService): Promise&lt;rpc.RemoteObject&gt;

根据[CloudService](#cloudservice)类的实例创建对应的[RemoteObject](../apis-ipc-kit/js-apis-rpc.md#remoteobject)对象，系统内部通过该对象调用[CloudService](#cloudservice)的实现接口，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名    | 类型                            | 必填 | 说明                                                         |
| --------- | ------------------------------- | ---- | -------------------------------- |
| instance  | [CloudService](#cloudservice)   | 是    | [CloudService](#cloudservice)类的实例。   |

**返回值：**

| 类型                | 说明                      |
| -------------------             | ------------------------- |
| Promise&lt;[rpc.RemoteObject](../apis-ipc-kit/js-apis-rpc.md#remoteobject)&gt; | Promise对象，返回[CloudService](#cloudservice)的[RemoteObject](../apis-ipc-kit/js-apis-rpc.md#remoteobject)对象。 |

**示例：**

```ts
import { Want, ServiceExtensionAbility } from '@kit.AbilityKit';
import { rpc } from '@kit.IPCKit';

export default class MyCloudService implements cloudExtension.CloudService {
  constructor() {}
  async connectShareCenter(userId: number, bundleName: string): Promise<rpc.RemoteObject> {
    // ...
  }
}

export default class MyServiceExtension extends ServiceExtensionAbility {
  onCreate(want: Want) {
    console.info(`onCreate: ${want}`);
  }
  onRequest(want: Want, startId: number) {
    console.info(`onRequest: ${want} ${startId}`);
  }
  onConnect(want: Want): rpc.RemoteObject | Promise<rpc.RemoteObject> {
    console.info(`onConnect: ${want}`);
    return cloudExtension.createCloudServiceStub(new MyCloudService());
  }
  onDisconnect(want: Want) {
    console.info(`onDisconnect: ${want}`);
  }
  onDestroy() {
    console.info('onDestroy');
  }
}
```

## cloudExtension.createShareServiceStub

createShareServiceStub(instance: ShareCenter): Promise&lt;rpc.RemoteObject&gt;

根据[ShareCenter](#sharecenter)类的实例创建对应的[RemoteObject](../apis-ipc-kit/js-apis-rpc.md#remoteobject)对象，系统内部通过该对象调用[ShareCenter](#sharecenter)的实现接口，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名    | 类型                            | 必填 | 说明                                                         |
| --------- | ------------------------------- | ---- | -------------------------------- |
| instance  | [ShareCenter](#sharecenter)   | 是    | [ShareCenter](#sharecenter)类的实例。                   |

**返回值：**

| 类型                | 说明                      |
| -------------------             | ------------------------- |
| Promise&lt;[rpc.RemoteObject](../apis-ipc-kit/js-apis-rpc.md#remoteobject)&gt; | Promise对象，返回[ShareCenter](#sharecenter)的[RemoteObject](../apis-ipc-kit/js-apis-rpc.md#remoteobject)对象。 |

**示例：**

```ts
import { rpc } from '@kit.IPCKit';

export default class MyShareCenter implements cloudExtension.ShareCenter {
  constructor() {}
  // ...
}

export default class MyCloudService implements cloudExtension.CloudService {
  constructor() {}
  async connectShareCenter(userId: number, bundleName: string): Promise<rpc.RemoteObject> {
    console.info(`connect share center, bundle: ${bundleName}`);
    return cloudExtension.createShareServiceStub(new MyShareCenter());
  }
}
```

## cloudExtension.createCloudDBStub

createCloudDBStub(instance: CloudDB): Promise&lt;rpc.RemoteObject&gt;

根据[CloudDB](#clouddb)类的实例创建对应的[RemoteObject](../apis-ipc-kit/js-apis-rpc.md#remoteobject)对象，系统内部通过该对象调用[CloudDB](#clouddb)的实现接口，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名   | 类型                  | 必填 | 说明                            |
| -------- | --------------------- | ---- | ------------------------------- |
| instance | [CloudDB](#clouddb) | 是   | [CloudDB](#clouddb)类的实例。 |

**返回值：**

| 类型                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| Promise&lt;[rpc.RemoteObject](../apis-ipc-kit/js-apis-rpc.md#remoteobject)&gt; | Promise对象，返回[CloudDB](#clouddb)的[rpc.RemoteObject](../apis-ipc-kit/js-apis-rpc.md#remoteobject)对象。 |

```ts
import { rpc } from '@kit.IPCKit';

export default class MyCloudDB implements cloudExtension.CloudDB {
  // ...
}

export default class MyCloudService implements cloudExtension.CloudService {
  constructor() {}
  // ...
  async connectDB(bundleName: string, database: cloudExtension.Database): Promise<rpc.RemoteObject> {
    console.info(`connect DB, bundleName: ${bundleName}`);
    return cloudExtension.createCloudDBStub(new MyCloudDB());
  }
}
```

## cloudExtension.createAssetLoaderStub

createAssetLoaderStub(instance: AssetLoader): Promise&lt;rpc.RemoteObject&gt;

根据[AssetLoader](#assetloader)类的实例创建对应的[RemoteObject](../apis-ipc-kit/js-apis-rpc.md#remoteobject)对象，系统内部通过该对象调用[AssetLoader](#assetloader)的实现接口，使用Promise异步回调。

**参数：**

| 参数名   | 类型                          | 必填 | 说明                                              |
| -------- | ----------------------------- | ---- | ------------------------------------------------- |
| instance | [AssetLoader](#assetloader) | 是   | 表示一个[AssetLoader](#assetloader)类型的实例。 |

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**返回值：**

| 类型                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| Promise&lt;[rpc.RemoteObject](../apis-ipc-kit/js-apis-rpc.md#remoteobject)&gt; | Promise对象，返回[AssetLoader](#assetloader)的[rpc.RemoteObject](../apis-ipc-kit/js-apis-rpc.md#remoteobject)对象。 |

**示例：**

```ts
import { rpc } from '@kit.IPCKit';

export default class MyAssetLoader implements cloudExtension.AssetLoader {
  // ...
}

export default class MyCloudService implements cloudExtension.CloudService {
  constructor() {}
  // ...   
  async connectAssetLoader(bundleName: string, database: cloudExtension.Database): Promise<rpc.RemoteObject> {
    console.info(`connect asset loader, bundle: ${bundleName}`);
    return cloudExtension.createAssetLoaderStub(new MyAssetLoader());
  }
}
```



## CloudDB

提供云数据库的操作接口的类。

### generateId

generateId(count: number): Promise&lt;Result&lt;Array&lt;string&gt;&gt;&gt;

为插入的云数据生成ID。生成的ID具有唯一性。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名 | 类型   | 必填 | 说明                 |
| ------ | ------ | ---- | -------------------- |
| count  | number | 是   | 表示要生成ID的数量。 |

**返回值：**

| 类型                                                     | 说明                                                         |
| -------------------------------------------------------- | ------------------------------------------------------------ |
| Promise&lt;[Result](#resultt)&lt;Array&lt;string&gt;&gt; | Promise对象，以[Result](#resultt)结构将生成的ID以数组形式返回。 |

**示例：**

```ts
export default class MyCloudDB implements cloudExtension.CloudDB {
  async generateId(count: number): Promise<cloudExtension.Result<Array<string>>> {
    console.info(`generate id, count: ${count}`);
    let result = new Array<string>();
    // ...
    return {
      code: cloudExtension.ErrorCode.SUCCESS,
      description: 'generateId succeeded',
      value: result
    };
  }
  // ...
}
```

### update

update(table: string, values: Array&lt;Record&lt;string, CloudType>>, extensions: Array&lt;Record&lt;string, CloudType>> ): Promise&lt;Array&lt;Result&lt;Record&lt;string, CloudType>>>>

通过该接口更新云上的数据。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                   |
| ---------- | ------------------------------------------------------------ | ---- | ---------------------- |
| table      | string                                                       | 是   | 表名。 |
| values     | Array&lt;Record&lt;string, [CloudType](#cloudtype)&gt;&gt; | 是   | 表示要插入的数据。     |
| extensions | Array&lt;Record&lt;string, [CloudType](#cloudtype)&gt;&gt; | 是   | 表示当前数据的扩展信息。 |

**返回值：**

| 类型                                                         | 说明                                    |
| ------------------------------------------------------------ | --------------------------------------- |
| Promise&lt;Array&lt;[Result](#resultt)&lt;Record&lt;string,  [CloudType](#cloudtype)&gt;&gt;&gt;&gt; | Promise对象，返回更新的数据和更新结果。 |

**示例：**

```ts
export default class MyCloudDB implements cloudExtension.CloudDB {
  // ...
  async update(table: string, values: Array<Record<string, cloudExtension.CloudType>>, extensions: Array<Record<string, cloudExtension.CloudType>>): Promise<Array<cloudExtension.Result<Record<string, cloudExtension.CloudType>>>> {
    console.info(`update, table: ${table}`);
    let updateRes: Array<cloudExtension.Result<Record<string, cloudExtension.CloudType>>> = [];
    // ...
    // 返回更新数据的结果
    return updateRes;
  }
  // ...
}
```

### insert

insert(table: string, values: Array<Record<string, CloudType>>, extensions: Array<Record<string, CloudType>>): Promise<Array<Result<Record<string, CloudType&gt;&gt;&gt;&gt;

将数据插入云数据库表中。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名     | 类型                                                       | 必填 | 说明                     |
| ---------- | ---------------------------------------------------------- | ---- | ------------------------ |
| table      | string                                                     | 是   | 表名。                   |
| values     | Array&lt;Record&lt;string, [CloudType](#cloudtype)&gt;&gt; | 是   | 表示要插入的数据。       |
| extensions | Array&lt;Record&lt;string, [CloudType](#cloudtype)&gt;&gt; | 是   | 表示当前数据的扩展信息。 |

**返回值：**

| 类型                                                         | 说明                                  |
| ------------------------------------------------------------ | ------------------------------------- |
| Promise&lt;Array&lt;[Result](#resultt)&lt;Record&lt;string, [CloudType](#cloudtype)&gt;&gt;&gt;&gt; | Promise对象，返回插入数据和插入结果。 |

**示例：**

```ts
export default class MyCloudDB implements cloudExtension.CloudDB {
  // ...
  async insert(table: string, values: Array<Record<string, cloudExtension.CloudType>>, extensions: Array<Record<string, cloudExtension.CloudType>>): Promise<Array<cloudExtension.Result<Record<string, cloudExtension.CloudType>>>> {
    console.info(`insert, table: ${table}`);
    let insertRes: Array<cloudExtension.Result<Record<string, cloudExtension.CloudType>>> = [];
    // ...
    // 返回插入数据的结果
    return insertRes;
  }
  // ...
}
```

### delete

delete(table: string, extensions: Array&lt;Record&lt;string, CloudType>> ): Promise&lt;Array&lt;Result&lt;Record&lt;string, CloudType&gt;&gt;&gt;&gt;

删除云数据库表中的指定数据。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名     | 类型                                                      | 必填 | 说明                     |
| ---------- | --------------------------------------------------------- | ---- | ------------------------ |
| table      | string                                                    | 是   | 表名。                   |
| extensions | Array&lt;Record&lt;string,[CloudType](#cloudtype)&gt;&gt; | 是   | 表示当前数据的扩展信息。 |

**返回值：**

| 类型                                                         | 说明                                      |
| ------------------------------------------------------------ | ----------------------------------------- |
| Promise&lt;Array&lt;[Result](#resultt)&lt;Record&lt;string, [CloudType](#cloudtype)&gt;&gt;&gt;&gt; | Promise对象，返回被删除的数据和删除结果。 |

**示例：**

```ts
export default class MyCloudDB implements cloudExtension.CloudDB {
  // ...
  async delete(table: string, extensions: Array<Record<string, cloudExtension.CloudType>>): Promise<Array<cloudExtension.Result<Record<string, cloudExtension.CloudType>>>> {
    console.info(`delete, table: ${table}`);
    let deleteRes: Array<cloudExtension.Result<Record<string, cloudExtension.CloudType>>> = [];
    // ...
    // 返回插入数据的结果
    return deleteRes;
  }
  // ...
}
```

### query

query(table: string, fields: Array&lt;string&gt;, queryCount: number, queryCursor: string): Promise&lt;Result&lt;CloudData&gt;&gt;

在云数据库表中查询数据。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名      | 类型          | 必填 | 说明                     |
| ----------- | ------------- | ---- | ------------------------ |
| table       | string        | 是   | 表名。                   |
| fields      | Array&lt;string&gt; | 是   | 表示字段名。          |
| queryCount  | number        | 是   | 表示要查询的数据记录数。 |
| queryCursor | string        | 是   | 表示要查询的游标。       |

**返回值：**

| 类型                                                         | 说明                                    |
| ------------------------------------------------------------ | --------------------------------------- |
| Promise&lt;[Result](#resultt)&lt;[CloudData](#clouddata)&gt;&gt; | Promise对象，返回被查询数据和查询结果。 |

**示例：**

```ts
export default class MyCloudDB implements cloudExtension.CloudDB {
  // ...
  async query(table: string, fields: Array<string>, queryCount: number, queryCursor: string): Promise<cloudExtension.Result<cloudExtension.CloudData>> {
    console.info(`query, table: ${table}`);
    // ...
    // 返回插入数据的结果
    return {
      code: cloudExtension.ErrorCode.SUCCESS,
      description: 'query succeeded',
      value: {
        nextCursor: "test_nextCursor",
        hasMore: true,
        values: []
      }
    };
  }
  // ...
}
```

###  lock

lock(): Promise&lt;Result&lt;LockInfo&gt;&gt;

为云数据库加锁。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**返回值：**

| 类型                                                         | 说明                                                |
| ------------------------------------------------------------ | --------------------------------------------------- |
| Promise&lt;[Result](#resultt)&lt;[LockInfo](#lockinfo)&gt;&gt; | Promise对象，返回加锁的信息，包含加锁时长和锁的ID。 |

**示例：**

```ts
let test_time: number = 10;
let test_lockId: number = 1;
export default class MyCloudDB implements cloudExtension.CloudDB {
  // ...
  async lock(): Promise<cloudExtension.Result<cloudExtension.LockInfo>> {
    console.info(`DB lock`);
    // ...
    // 返回插入数据的结果
    return {
      code: cloudExtension.ErrorCode.SUCCESS,
      description: 'lock succeeded',
      value: {
        interval: test_time,
        lockId: test_lockId
      }
    };
  }
  // ...
}
```

### heartbeat

heartbeat(lockId: number): Promise&lt;Result&lt;LockInfo&gt;&gt;

延长数据库的加锁时效。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名 | 类型   | 必填 | 说明                  |
| ------ | ------ | ---- | --------------------- |
| lockId | number | 是   | 表示需要延时的锁ID。 |

**返回值：**

| 类型                                                         | 说明                                              |
| ------------------------------------------------------------ | ------------------------------------------------- |
| Promise&lt;[Result](#resultt)&lt;[LockInfo](#lockinfo)&gt;&gt; | Promise对象，返回锁的信息，包含加锁时长和锁的ID。 |

**示例：**

```ts
let test_lockId: number = 1;
let test_time: number = 10;
export default class MyCloudDB implements cloudExtension.CloudDB {
  // ...
  async heartbeat(lockId: number): Promise<cloudExtension.Result<cloudExtension.LockInfo>> {
    console.info(`heartbeat lock`);
    // ...
    // 返回插入数据的结果
    return {
      code: cloudExtension.ErrorCode.SUCCESS,
      description: 'heartbeat succeeded',
      value: {
        interval: test_time,
        lockId: test_lockId
      }
    };
  }
  // ...
}
```

### unlock

unlock(lockId: number): Promise&lt;Result&lt;boolean&gt;&gt;

为云数据库解锁。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名 | 类型   | 必填 | 说明          |
| ------ | ------ | ---- | ------------- |
| lockId | number | 是   | 表示锁的ID。 |

**返回值：**

| 类型                                             | 说明                                                         |
| ------------------------------------------------ | ------------------------------------------------------------ |
| Promise&lt;[Result](#resultt)&lt;boolean&gt;&gt; | Promise对象，返回解锁结果，true表示解锁成功，false表示解锁失败。 |

**示例：**

```ts
export default class MyCloudDB implements cloudExtension.CloudDB {
    // ...
  async unlock(lockId: number): Promise<cloudExtension.Result<boolean>> {
    console.info(`unlock`);
    // ...
    // 返回插入数据的结果
    return {
      code: cloudExtension.ErrorCode.SUCCESS,
      description: 'unlock succeeded',
      value: false
    };
  }
  // ...
}
```

## CloudService

提供对接同步云服务的类。开发者需要继承此类并实现类的接口，系统内部通过该类的接口连接并使用同步云服务。

### getServiceInfo

getServiceInfo(): Promise<ServiceInfo&gt;

获取服务器上的信息。使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**返回值：**

| 类型                                         | 说明                                |
| -------------------------------------------- | ----------------------------------- |
| Promise&lt;[ServiceInfo](#serviceinfo)&gt; | Promise对象，返回获取的服务器信息。 |

**示例：**

```ts
import { rpc } from '@kit.IPCKit';

let test_space: number = 100;
let test_userId: number = 1;

export default class MyCloudService implements cloudExtension.CloudService {
  constructor() {}
  // ...
  async getServiceInfo(): Promise<cloudExtension.ServiceInfo> {
    console.info(`get service info`);
    // ...
    return {
      enableCloud: true,
      id: "test_id",
      totalSpace: test_space,
      remainingSpace: test_space,
      user: test_userId,
    };
  }
}
```

### getAppBriefInfo

getAppBriefInfo(): Promise<Record<string, AppBriefInfo>>

获取简要应用信息。使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**返回值：**

| 类型                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| Promise&lt;Record&lt;string, [AppBriefInfo](#appbriefinfo)&gt;&gt;&gt; | Promise对象，返回与bundleName和 [AppBriefInfo](#appbriefinfo)相对应的键值对。 |

**示例：**

```ts
export default class MyCloudService implements cloudExtension.CloudService {
  constructor() {}
  // ...
  async getAppBriefInfo(): Promise<Record<string, cloudExtension.AppBriefInfo>> {
    console.info(`get app brief info`);
    // ...
    return {
      "test_bundle":
      {
        appId: "test_appID",
        bundleName: "test_bundlename",
        cloudSwitch: true,
        instanceId: 0,
      }
    };
  }
}
```

### getAppSchema

 getAppSchema(bundleName: string): Promise&lt;Result&lt;AppSchema&gt;&gt;

获取应用Schema（数据库模式）信息。使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名     | 类型   | 必填 | 说明       |
| ---------- | ------ | ---- | ---------- |
| bundleName | string | 是   | 应用包名。 |

**返回值：**

| 类型                                                         | 说明                                  |
| ------------------------------------------------------------ | ------------------------------------- |
| Promise&lt;[Result](#resultt)&lt;[AppSchema](#appschema)&gt;&gt; | Promise对象，返回数据库的schema信息。 |

**示例：**

```ts
export default class MyCloudService implements cloudExtension.CloudService {
  constructor() {
  }
  // ...
  async getAppSchema(bundleName: string): Promise<cloudExtension.Result<cloudExtension.AppSchema>> {
    console.info(`get app schema, bundleName:${bundleName}`);
    // ...
    return {
      code: cloudExtension.ErrorCode.SUCCESS,
      description: "get app schema success",
      value: {
        bundleName: "test_bundleName",
        version: 1,
        databases: []
      }
    };
  }
}
```

### subscribe

subscribe(subInfo: Record&lt;string, Array&lt;Database&gt;&gt;, expirationTime: number): Promise&lt;Result&lt;SubscribeInfo&gt;&gt;

发起订阅，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名         | 类型                                                       | 必填 | 说明                                                   |
| -------------- | ---------------------------------------------------------- | ---- | ------------------------------------------------------ |
| subInfo        | Record&lt;string, Array&lt;[Database](#database)&gt;&gt; | 是   | 需要订阅的数据，由应用包名称和数据库信息组成的键值对。 |
| expirationTime | number                                                     | 是   | 表示订阅到期时间。                                     |

**返回值：**

| 类型                                                         | 说明                                                        |
| ------------------------------------------------------------ | ----------------------------------------------------------- |
| Promise&lt;[Result](#resultt)&lt;[SubscribeInfo](#subscribeinfo)&gt;&gt; | Promise对象，返回订阅的结果，包含订阅的过期时间和订阅信息。 |

**示例：**

```ts
let test_time: number = 10;
export default class MyCloudService implements cloudExtension.CloudService {
  constructor() {
  }
  // ...
  async subscribe(subInfo: Record<string, Array<cloudExtension.Database>>, expirationTime: number): Promise<cloudExtension.Result<cloudExtension.SubscribeInfo>> {
    console.info
    (`subscribe expirationTime: ${expirationTime}`);
    // ...
    return {
      code: cloudExtension.ErrorCode.SUCCESS,
      description: "subscribe success",
      value: {
        expirationTime: test_time,
        subscribe: {}
      }
    };
  }
}
```



### unsubscribe

unsubscribe(unsubscribeInfo: Record&lt;string, Array&lt;string&gt;&gt;): Promise&lt;number&gt;

取消订阅云中的数据变更。使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名          | 类型                                   | 必填 | 说明                                                         |
| --------------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| unsubscribeInfo | Record&lt;string, Array<string&gt;&gt; | 是   | 需要取消订阅的数据信息，由应用包名和数据库结构组成的键值对。 |

**返回值：**

| 类型                  | 说明                                    |
| --------------------- | --------------------------------------- |
| Promise&lt;number&gt; | Promise对象，返回取消订阅结果的错误码。 |

```ts
export default class MyCloudService implements cloudExtension.CloudService {
  constructor() {
  }
  // ...
  async unsubscribe(unsubscribeInfo: Record<string, Array<string>>): Promise<number> {
    console.info(`unsubscribe`);
    // ...
    return cloudExtension.ErrorCode.SUCCESS;
  }
}
```

### connectDB

 connectDB(bundleName: string, database: Database): Promise&lt;rpc.RemoteObject&gt;

系统内部通过该接口获取[CloudDB](#clouddb)的[RemoteObject](../apis-ipc-kit/js-apis-rpc.md#remoteobject)对象，可以通过[createCloudDBStub](#cloudextensioncreateclouddbstub)接口进行创建，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名     | 类型                    | 必填 | 说明               |
| ---------- | ----------------------- | ---- | ------------------ |
| bundleName | string                  | 是   | 应用包名。         |
| database   | [Database](#database) | 是   | 需要连接的数据库。 |

**返回值：**

| 类型                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| Promise&lt;[rpc.RemoteObject](../apis-ipc-kit/js-apis-rpc.md#remoteobject)&gt; | Promise对象，返回[CloudDB](#clouddb)的[RemoteObject](../apis-ipc-kit/js-apis-rpc.md#remoteobject)对象。 |

```ts
import { rpc } from '@kit.IPCKit';

export default class MyCloudDB implements cloudExtension.CloudDB {
  // ...
}

export default class MyCloudService implements cloudExtension.CloudService {
  constructor() {}
    // ...
  async connectDB(bundleName: string, database: cloudExtension.Database): Promise<rpc.RemoteObject> {
    console.info(`connect DB, bundleName: ${bundleName}`);
    return cloudExtension.createCloudDBStub(new MyCloudDB());
  }
}
```

### connectAssetLoader

connectAssetLoader(bundleName: string, database: Database): Promise&lt;rpc.RemoteObject&gt;

系统内部通过该接口获取[AssetLoader](#assetloader)的[RemoteObject](../apis-ipc-kit/js-apis-rpc.md#remoteobject)对象，可以通过[createAssetLoaderStub](#cloudextensioncreateassetloaderstub)接口进行创建，使用Promise异步回调。

连接进行资产上传和下载的对象。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名     | 类型                    | 必填 | 说明               |
| ---------- | ----------------------- | ---- | ------------------ |
| bundleName | string                  | 是   | 应用包名。         |
| database   | [Database](#database) | 是   | 需要连接的数据库。 |

**返回值：**

| 类型                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| Promise&lt;[rpc.RemoteObject](../apis-ipc-kit/js-apis-rpc.md#remoteobject)&gt; | Promise对象，返回[AssetLoader](#assetloader)的[RemoteObject](../apis-ipc-kit/js-apis-rpc.md#remoteobject)对象。 |

```ts
import { rpc } from '@kit.IPCKit';

export default class MyAssetLoader implements cloudExtension.AssetLoader {
  // ...
}

export default class MyCloudService implements cloudExtension.CloudService {
  constructor() {}
  async connectAssetLoader(bundleName: string, database: cloudExtension.Database): Promise<rpc.RemoteObject> {
      // ...
    console.info(`connect asset loader, bundle: ${bundleName}`);
    return cloudExtension.createAssetLoaderStub(new MyAssetLoader());
  }
}
```

### connectShareCenter

connectShareCenter(userId: number, bundleName: string): Promise&lt;rpc.RemoteObject&gt;

系统内部通过该接口获取[ShareCenter](#sharecenter)的[RemoteObject](../apis-ipc-kit/js-apis-rpc.md#remoteobject)对象，可以通过[createShareServiceStub](#cloudextensioncreateshareservicestub)接口进行创建，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名  | 类型                    | 必填 | 说明                                            |
| ------- | ----------------------- | ---- | ----------------------------------------------- |
| userId      | number  | 是   | 表示用户ID。         |
| bundleName  | string  | 是   | 应用包名。   |

**返回值：**

| 类型                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| Promise&lt;[rpc.RemoteObject](../apis-ipc-kit/js-apis-rpc.md#remoteobject)&gt; | Promise对象，返回[ShareCenter](#sharecenter)的[RemoteObject](../apis-ipc-kit/js-apis-rpc.md#remoteobject)对象。 |

**示例：**

```ts
import { rpc } from '@kit.IPCKit';

export default class MyShareCenter implements cloudExtension.ShareCenter {
  constructor() {}
  // ...
}

export default class MyCloudService implements cloudExtension.CloudService {
  constructor() {}
  async connectShareCenter(userId: number, bundleName: string): Promise<rpc.RemoteObject> {
    console.info(`connect share center, bundle: ${bundleName}`);
    return cloudExtension.createShareServiceStub(new MyShareCenter());
  }
}
```

## AssetLoader

提供资产的上传下载接口的类。

### download

download(table: string, gid: string, prefix: string, assets: Array&lt;CloudAsset&gt;): Promise&lt;Array&lt;Result&lt;CloudAsset&gt;&gt;&gt;

通过该接口实现资产的下载。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名 | 类型                                   | 必填 | 说明                       |
| ------ | -------------------------------------- | ---- | -------------------------- |
| table  | string                                 | 是   | 表名。                     |
| gid    | string                                 | 是   | 数据上云后生成的唯一标记。 |
| prefix | string                                 | 是   | 表示前缀信息。             |
| assets | Array&lt;[CloudAsset](#cloudasset)&gt; | 是   | 表示需要下载的资产。       |

**返回值：**

| 类型                                                         | 说明                                                    |
| ------------------------------------------------------------ | ------------------------------------------------------- |
| Promise&lt;Array&lt;[Result](resultt)&lt;[CloudAsset](#cloudasset)&gt;&gt;&gt; | Promise对象，返回资产下载结果，包含资产ID和资产哈希值。 |

**示例：**

```ts
export default class MyAssetLoader implements cloudExtension.AssetLoader {
  async download(table: string, gid: string, prefix: string, assets: Array<cloudExtension.CloudAsset>): Promise<Array<cloudExtension.Result<cloudExtension.CloudAsset>>> {
    console.info(`download asset loader, table: ${table}, gid: ${gid}, prefix: ${prefix}`);
    let downloadRes = Array<cloudExtension.Result<cloudExtension.CloudAsset>>();
    // ...
    return downloadRes;
  }
}
```

### upload

upload(table: string, gid: string, assets: Array&lt;CloudAsset&gt;): Promise&lt;Array&lt;Result&lt;CloudAsset&gt;&gt;&gt;

通过该接口实现资产的上传。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名 | 类型                                     | 必填 | 说明                                 |
| ------ | ---------------------------------------- | ---- | ------------------------------------ |
| table  | string                                   | 是   | 表名。                               |
| gid    | string                                   | 是   | 表示 GID，数据上云后生成的唯一标记。 |
| assets | Array&lt;[CloudAsset](#cloudasset)&gt; | 是   | 表示需要上传的资产。                 |

**返回值：**

| 类型                                                         | 说明                                                      |
| ------------------------------------------------------------ | --------------------------------------------------------- |
| Promise&lt;Array&lt;[Result](#resultt)&lt;[CloudAsset](#cloudasset)&gt;&gt;&gt; | Promise对象，返回资产上云的结果，包含资产ID和资产哈希值。 |

**示例：**

```ts
export default class MyAssetLoader implements cloudExtension.AssetLoader {
  async upload(table: string, gid: string, assets: Array<cloudExtension.CloudAsset>): Promise<Array<cloudExtension.Result<cloudExtension.CloudAsset>>> {
    console.info(`upload asset loader, table: ${table}, gid: ${gid}`);
    let uploadRes = Array<cloudExtension.Result<cloudExtension.CloudAsset>>();
    // ...
    return uploadRes;
  }
    // ...
}
```

## ShareCenter

提供对接共享云服务的类。开发者需要继承此类并实现类的接口，系统内部通过该类的接口联接并使用共享云服务，实现端云共享的发起、取消或退出等能力。

### share

share(userId: number, bundleName: string, sharingResource: string, participants: Array&lt;cloudData.sharing.Participant&gt;): Promise&lt;Result&lt;Array&lt;Result&lt;cloudData.sharing.Participant&gt;&gt;&gt;&gt;

发起端云共享邀请。共享邀请时，会指定当前发起共享的应用、共享数据的资源标识和共享参与者，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名  | 类型                    | 必填 | 说明                                            |
| ------- | ----------------------- | ---- | ----------------------------------------------- |
| userId          | number  | 是   | 表示用户ID。  |
| bundleName      | string  | 是   | 应用包名。    |
| sharingResource | string  | 是   | 端云共享资源的标识。   |
| participants    | Array&lt;[cloudData.sharing.Participant](js-apis-data-cloudData-sys.md#participant11)&gt;  | 是   | 端云共享参与者。   |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;[Result](#resultt)&lt;Array&lt;[Result](#resultt)&lt;[cloudData.sharing.Participant](js-apis-data-cloudData-sys.md#participant11)&gt;&gt;&gt;&gt; | Promise对象，返回发起共享的结果。 |

**示例：**

```ts
import { cloudData } from '@kit.ArkData';

type Participant = cloudData.sharing.Participant;

export default class MyShareCenter implements cloudExtension.ShareCenter {
  constructor() {}
  async share(userId: number, bundleName: string, sharingResource: string, participants: Array<Participant>):
    Promise<cloudExtension.Result<Array<cloudExtension.Result<Participant>>>> {
    console.info(`share, bundle: ${bundleName}`);
    // 对接云共享服务端，并获得共享的返回值
    // ...
    // 返回服务端发起共享的返回结果
    let result: Array<cloudExtension.Result<Participant>> = [];
    participants.forEach((item => {
      result.push({
        code: cloudData.sharing.SharingCode.SUCCESS,
        description: 'share succeeded'    
      })
    }))
    return {
      code: cloudData.sharing.SharingCode.SUCCESS,
      description: 'share succeeded',
      value: result
    }
  }
  // ...
}
```

### unshare

unshare(userId: number, bundleName: string, sharingResource: string, participants: Array&lt;cloudData.sharing.Participant&gt;): Promise&lt;Result&lt;Array&lt;Result&lt;cloudData.sharing.Participant&gt;&gt;&gt;&gt;

取消端云共享。取消共享时，会指定当前取消共享的应用、取消共享数据的资源标识和取消共享的参与者，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名  | 类型                    | 必填 | 说明                                            |
| ------- | ----------------------- | ---- | ----------------------------------------------- |
| userId          | number  | 是   | 表示用户ID。  |
| bundleName      | string  | 是   | 应用包名。    |
| sharingResource | string  | 是   | 端云共享资源标识。   |
| participants    | Array&lt;[cloudData.sharing.Participant](js-apis-data-cloudData-sys.md#participant11)&gt;  | 是   | 端云共享参与者。   |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;[Result](#resultt)&lt;Array&lt;[Result](#resultt)&lt;[cloudData.sharing.Participant](js-apis-data-cloudData-sys.md#participant11)&gt;&gt;&gt;&gt; | Promise对象，返回取消共享的结果。 |

**示例：**

```ts
import { cloudData } from '@kit.ArkData';

type Participant = cloudData.sharing.Participant;

export default class MyShareCenter implements cloudExtension.ShareCenter {
  constructor() {}
  async unshare(userId: number, bundleName: string, sharingResource: string, participants: Array<Participant>):
    Promise<cloudExtension.Result<Array<cloudExtension.Result<Participant>>>> {
    console.info(`unshare, bundle: ${bundleName}`);
    // 对接云共享服务端，并获得取消共享的返回值
    // ...
    // 返回服务端取消共享的返回结果
    let result: Array<cloudExtension.Result<Participant>> = [];
    participants.forEach((item => {
      result.push({
        code: cloudData.sharing.SharingCode.SUCCESS,
        description: 'unshare succeeded'    
      })
    }))
    return {
      code: cloudData.sharing.SharingCode.SUCCESS,
      description: 'unshare succeeded',
      value: result
    }
  }
  // ...
}
```

### exit

exit(userId: number, bundleName: string, sharingResource: string): Promise&lt;Result&lt;void&gt;&gt;

退出端云共享。退出共享时，会指定当前退出共享的应用以及退出共享数据的资源标识，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名  | 类型                    | 必填 | 说明                                            |
| ------- | ----------------------- | ---- | ----------------------------------------------- |
| userId          | number  | 是   | 表示用户ID。  |
| bundleName      | string  | 是   | 应用包名。    |
| sharingResource | string  | 是   | 端云共享资源标识。   |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;[Result](#resultt)&lt;void&gt;&gt; | Promise对象，返回退出共享的结果。 |

**示例：**

```ts
import { cloudData } from '@kit.ArkData';

export default class MyShareCenter implements cloudExtension.ShareCenter {
  constructor() {}
  async exit(userId: number, bundleName: string, sharingResource: string):
    Promise<cloudExtension.Result<void>> {
    console.info(`exit share, bundle: ${bundleName}`);
    // 对接云共享服务端，并获得退出共享的返回值
    // ...
    // 返回服务端退出共享的返回结果
    return {
      code: cloudData.sharing.SharingCode.SUCCESS,
      description: 'exit share succeeded'
    }
  }
  // ...
}
```

### changePrivilege

changePrivilege(userId: number, bundleName: string, sharingResource: string, participants: Array&lt;cloudData.sharing.Participant&gt;): Promise&lt;Result&lt;Array&lt;Result&lt;cloudData.sharing.Participant&gt;&gt;&gt;&gt;

更改已共享数据的操作权限。更改权限时，会指定当前更改权限的应用、更改权限数据的资源标识和更改权限的参与者，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名  | 类型                    | 必填 | 说明                                            |
| ------- | ----------------------- | ---- | ----------------------------------------------- |
| userId          | number  | 是   | 表示用户ID。  |
| bundleName      | string  | 是   | 应用包名。    |
| sharingResource | string  | 是   | 端云共享资源标识。   |
| participants    | Array&lt;[cloudData.sharing.Participant](js-apis-data-cloudData-sys.md#participant11)&gt;  | 是   | 端云共享参与者。   |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;[Result](#resultt)&lt;Array&lt;[Result](#resultt)&lt;[cloudData.sharing.Participant](js-apis-data-cloudData-sys.md#participant11)&gt;&gt;&gt;&gt; | Promise对象，返回更改权限的结果。 |

**示例：**

```ts
import { cloudData } from '@kit.ArkData';

type Participant = cloudData.sharing.Participant;

export default class MyShareCenter implements cloudExtension.ShareCenter {
  constructor() {}
  async changePrivilege(userId: number, bundleName: string, sharingResource: string, participants: Array<Participant>):
    Promise<cloudExtension.Result<Array<cloudExtension.Result<Participant>>>> {
    console.info(`change privilege, bundle: ${bundleName}`);
    // 对接云共享服务端，并获得更改权限的返回值
    // ...
    // 返回服务端更改权限的返回结果
    let result: Array<cloudExtension.Result<Participant>> = [];
    participants.forEach((item => {
      result.push({
        code: cloudData.sharing.SharingCode.SUCCESS,
        description: 'change privilege succeeded'    
      })
    }))
    return {
      code: cloudData.sharing.SharingCode.SUCCESS,
      description: 'change privilege succeeded',
      value: result
    }
  }
  // ...
}
```

### queryParticipants

queryParticipants(userId: number, bundleName: string, sharingResource: string): Promise&lt;Result&lt;Array&lt;cloudData.sharing.Participant&gt;&gt;&gt;

查询当前端云共享的参与者。查询时，会指定当前查询参与者的应用、查询参与者数据的资源标识，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名  | 类型                    | 必填 | 说明                                            |
| ------- | ----------------------- | ---- | ----------------------------------------------- |
| userId          | number  | 是   | 表示用户ID。  |
| bundleName      | string  | 是   | 应用包名。    |
| sharingResource | string  | 是   | 端云共享资源标识。   |

**返回值：**

| 类型                                                         | 说明                                    |
| ------------------------------------------------------------ | --------------------------------------- |
| Promise&lt;[Result](#resultt)&lt;Array&lt;[cloudData.sharing.Participant](js-apis-data-cloudData-sys.md#participant11)&gt;&gt;&gt; | Promise对象，返回查询共享参与者的结果。 |

**示例：**

```ts
import { cloudData } from '@kit.ArkData';

type Participant = cloudData.sharing.Participant;

export default class MyShareCenter implements cloudExtension.ShareCenter {
  constructor() {}
  async queryParticipants(userId: number, bundleName: string, sharingResource: string):
    Promise<cloudExtension.Result<Array<Participant>>> {
    console.info(`query participants, bundle: ${bundleName}`);
    // 对接云共享服务端，并获得查询参与者的返回值
    // ...
    // 返回服务端查询参与者的返回结果
    let participants = new Array<cloudData.sharing.Participant>();
    participants.push({
      identity: '000000000',
      role: cloudData.sharing.Role.ROLE_INVITEE,
      state: cloudData.sharing.State.STATE_ACCEPTED,
      privilege: {
        writable: false,
        readable: true,
        creatable: false,
        deletable: false,
        shareable: false
      },
      attachInfo: ''
    })
    participants.push({
      identity: '111111111',
      role: cloudData.sharing.Role.ROLE_INVITEE,
      state: cloudData.sharing.State.STATE_ACCEPTED,
      privilege: {
        writable: false,
        readable: true,
        creatable: false,
        deletable: false,
        shareable: false
      },
      attachInfo: ''
    })
    return {
      code: cloudData.sharing.SharingCode.SUCCESS,
      description: 'query participants succeeded',
      value: participants
    }
  }
  // ...
}
```

### queryParticipantsByInvitation

queryParticipantsByInvitation(userId: number, bundleName: string, invitationCode: string): Promise&lt;Result&lt;Array&lt;cloudData.sharing.Participant&gt;&gt;&gt;

根据邀请码查询当前端云共享的参与者。查询时，会指定当前查询参与者的应用、共享数据的邀请码，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名  | 类型                    | 必填 | 说明                                            |
| ------- | ----------------------- | ---- | ----------------------------------------------- |
| userId          | number  | 是   | 表示用户ID。  |
| bundleName      | string  | 是   | 应用包名。    |
| invitationCode  | string  | 是   | 端云共享邀请码。   |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;[Result](#resultt)&lt;Array&lt;[cloudData.sharing.Participant](js-apis-data-cloudData-sys.md#participant11)&gt;&gt;&gt; | Promise对象，返回根据邀请码查询共享参与者的结果。 |

**示例：**

```ts
import { cloudData } from '@kit.ArkData';

type Participant = cloudData.sharing.Participant;

export default class MyShareCenter implements cloudExtension.ShareCenter {
  constructor() {}
  async queryParticipantsByInvitation(userId: number, bundleName: string, invitationCode: string):
    Promise<cloudExtension.Result<Array<Participant>>> {
    console.info(`query participants by invitation, bundle: ${bundleName}`);
    // 对接云共享服务端，并获得查询参与者的返回值
    // ...
    // 返回服务端查询参与者的返回结果
    let participants = new Array<cloudData.sharing.Participant>();
    participants.push({
      identity: '000000000',
      role: cloudData.sharing.Role.ROLE_INVITEE,
      state: cloudData.sharing.State.STATE_ACCEPTED,
      privilege: {
        writable: false,
        readable: true,
        creatable: false,
        deletable: false,
        shareable: false
      },
      attachInfo: ''
    })
    participants.push({
      identity: '111111111',
      role: cloudData.sharing.Role.ROLE_INVITEE,
      state: cloudData.sharing.State.STATE_ACCEPTED,
      privilege: {
        writable: false,
        readable: true,
        creatable: false,
        deletable: false,
        shareable: false
      },
      attachInfo: ''
    })
    return {
      code: cloudData.sharing.SharingCode.SUCCESS,
      description: 'query participants by invitation succeeded',
      value: participants
    }
  }
  // ...
}
```

### confirmInvitation

confirmInvitation(userId: number, bundleName: string, invitationCode: string, state: cloudData.sharing.State): Promise&lt;Result&lt;string&gt;&gt;

被邀请者确认端云共享邀请。确认时，会指定当前确认邀请的应用、共享数据的邀请码以及确认状态，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名  | 类型                    | 必填 | 说明                                            |
| ------- | ----------------------- | ---- | ----------------------------------------------- |
| userId          | number  | 是   | 表示用户ID。  |
| bundleName      | string  | 是   | 应用包名。    |
| invitationCode  | string  | 是   | 端云共享邀请码。   |
| state           | [cloudData.sharing.State](js-apis-data-cloudData-sys.md#state11)  | 是   | 共享邀请的确认状态。   |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;[Result](#resultt)&lt;string&gt;&gt; | Promise对象，返回确认端云共享邀请数据的共享资源标识。 |

**示例：**

```ts
import { cloudData } from '@kit.ArkData';

export default class MyShareCenter implements cloudExtension.ShareCenter {
  constructor() {}
  async confirmInvitation(userId: number, bundleName: string, invitationCode: string, state: cloudData.sharing.State):
    Promise<cloudExtension.Result<string>> {
    console.info(`confirm invitation, bundle: ${bundleName}`);
    // 对接云共享服务端，并获得确认共享邀请的返回值
    // ...
    // 返回服务端确认共享邀请的返回结果
    return {
      code: cloudData.sharing.SharingCode.SUCCESS,
      description: 'confirm invitation succeeded',
      value: 'sharing_resource_test'
    }
  }
  // ...
}
```

### changeConfirmation

changeConfirmation(userId: number, bundleName: string, sharingResource: string, state: cloudData.sharing.State): Promise&lt;Result&lt;void&gt;&gt;

更改端云共享邀请。更改共享邀请时，会指定当前更改共享邀请的应用、共享数据的的共享资源标识以及更改的状态,使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名  | 类型                    | 必填 | 说明                                            |
| ------- | ----------------------- | ---- | ----------------------------------------------- |
| userId          | number  | 是   | 表示用户ID。  |
| bundleName      | string  | 是   | 应用包名。    |
| sharingResource | string  | 是   | 端云共享资源标识。   |
| state           | [cloudData.sharing.State](js-apis-data-cloudData-sys.md#state11)  | 是   | 共享邀请的更改状态。   |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;[Result](#resultt)&lt;void&gt;&gt; | Promise对象，返回更改共享邀请的结果。 |

**示例：**

```ts
import { cloudData } from '@kit.ArkData';

export default class MyShareCenter implements cloudExtension.ShareCenter {
  constructor() {}
  async changeConfirmation(userId: number, bundleName: string, sharingResource: string, state: cloudData.sharing.State):
    Promise<cloudExtension.Result<void>> {
    console.info(`change confirm, bundle: ${bundleName}`);
    // 对接云共享服务端，并获得更改共享邀请的返回值
    // ...
    // 返回服务端更改共享邀请的返回结果
    return {
      code: cloudData.sharing.SharingCode.SUCCESS,
      description: 'change confirm succeeded'
    }
  }
  // ...
}
```
## 完整示例

以上示例中的类均采用implements实现，示例代码不能单独编译，需要实现父类中的所有方法才能使用，提供完整示例以作参考。

```ts
import { Want, ServiceExtensionAbility } from '@kit.AbilityKit';
import { rpc } from '@kit.IPCKit';
import { cloudData, cloudExtension } from '@kit.ArkData';

type Participant = cloudData.sharing.Participant;
let test_lockId: number = 1;
let test_time: number = 10;
let test_space: number = 100;
let test_userId: number = 1;

class MyCloudDB implements cloudExtension.CloudDB {
  async generateId(count: number): Promise<cloudExtension.Result<Array<string>>> {
    console.info(`generate id, count: ${count}`);
    let result = new Array<string>();
    // ...
    // 返回创建Id的结果
    return {
      code: cloudExtension.ErrorCode.SUCCESS,
      description: 'generateId succeeded',
      value: result
    };
  }

  async update(table: string, values: Array<Record<string, cloudExtension.CloudType>>, extensions: Array<Record<string, cloudExtension.CloudType>>): Promise<Array<cloudExtension.Result<Record<string, cloudExtension.CloudType>>>> {
    console.info(`update, table: ${table}`);
    let updateRes: Array<cloudExtension.Result<Record<string, cloudExtension.CloudType>>> = [];
    // ...
    // 返回更新数据的结果
    return updateRes;
  }

  async insert(table: string, values: Array<Record<string, cloudExtension.CloudType>>, extensions: Array<Record<string, cloudExtension.CloudType>>): Promise<Array<cloudExtension.Result<Record<string, cloudExtension.CloudType>>>> {
    console.info(`insert, table: ${table}`);
    let insertRes: Array<cloudExtension.Result<Record<string, cloudExtension.CloudType>>> = [];
    // ...
    // 返回插入数据的结果
    return insertRes;
  }

  async delete(table: string, extensions: Array<Record<string, cloudExtension.CloudType>>): Promise<Array<cloudExtension.Result<Record<string, cloudExtension.CloudType>>>> {
    console.info(`delete, table: ${table}`);
    let deleteRes: Array<cloudExtension.Result<Record<string, cloudExtension.CloudType>>> = [];
    // ...
    // 返回插入数据的结果
    return deleteRes;
  }

  async query(table: string, fields: Array<string>, queryCount: number, queryCursor: string): Promise<cloudExtension.Result<cloudExtension.CloudData>> {
    console.info(`query, table: ${table}`);
    // ...
    // 返回插入数据的结果
    return {
      code: cloudExtension.ErrorCode.SUCCESS,
      description: 'query succeeded',
      value: {
        nextCursor: "test_nextCursor",
        hasMore: true,
        values: []
      }
    };
  }

  async lock(): Promise<cloudExtension.Result<cloudExtension.LockInfo>> {
    console.info(`DB lock`);
    // ...
    // 返回插入数据的结果
    return {
      code: cloudExtension.ErrorCode.SUCCESS,
      description: 'lock succeeded',
      value: {
        interval: test_time,
        lockId: test_lockId
      }
    };
  }

  async heartbeat(lockId: number): Promise<cloudExtension.Result<cloudExtension.LockInfo>> {
    console.info(`heartbeat lock`);
    // ...
    // 返回插入数据的结果
    return {
      code: cloudExtension.ErrorCode.SUCCESS,
      description: 'heartbeat succeeded',
      value: {
        interval: test_time,
        lockId: test_lockId
      }
    };
  }

  async unlock(lockId: number): Promise<cloudExtension.Result<boolean>> {
    console.info(`unlock`);
    // ...
    // 返回插入数据的结果
    return {
      code: cloudExtension.ErrorCode.SUCCESS,
      description: 'unlock succeeded',
      value: false
    };
  }
}

class MyAssetLoader implements cloudExtension.AssetLoader {
  async download(table: string, gid: string, prefix: string, assets: Array<cloudExtension.CloudAsset>): Promise<Array<cloudExtension.Result<cloudExtension.CloudAsset>>> {
    console.info(`download asset loader, table: ${table}, gid: ${gid}, prefix: ${prefix}`);
    let downloadRes = Array<cloudExtension.Result<cloudExtension.CloudAsset>>();
    // ...
    return downloadRes;
  }

  async upload(table: string, gid: string, assets: Array<cloudExtension.CloudAsset>): Promise<Array<cloudExtension.Result<cloudExtension.CloudAsset>>> {
    console.info(`upload asset loader, table: ${table}, gid: ${gid}`);
    let uploadRes = Array<cloudExtension.Result<cloudExtension.CloudAsset>>();
    // ...
    return uploadRes;
  }
}

class MyShareCenter implements cloudExtension.ShareCenter {
  constructor() {
  }

  async share(userId: number, bundleName: string, sharingResource: string, participants: Array<Participant>):
    Promise<cloudExtension.Result<Array<cloudExtension.Result<Participant>>>> {
    console.info(`share, bundle: ${bundleName}`);
    // 对接云共享服务端，并获得共享的返回值
    // ...
    // 返回服务端发起共享的返回结果
    let result: Array<cloudExtension.Result<Participant>> = [];
    participants.forEach((item => {
      result.push({
        code: cloudData.sharing.SharingCode.SUCCESS,
        description: 'share succeeded'
      })
    }))
    return {
      code: cloudData.sharing.SharingCode.SUCCESS,
      description: 'share succeeded',
      value: result
    }
  }

  async unshare(userId: number, bundleName: string, sharingResource: string, participants: Array<Participant>):
    Promise<cloudExtension.Result<Array<cloudExtension.Result<Participant>>>> {
    console.info(`unshare, bundle: ${bundleName}`);
    // 对接云共享服务端，并获得取消共享的返回值
    // ...
    // 返回服务端取消共享的返回结果
    let result: Array<cloudExtension.Result<Participant>> = [];
    participants.forEach((item => {
      result.push({
        code: cloudData.sharing.SharingCode.SUCCESS,
        description: 'unshare succeeded'
      })
    }))
    return {
      code: cloudData.sharing.SharingCode.SUCCESS,
      description: 'unshare succeeded',
      value: result
    }
  }

  async exit(userId: number, bundleName: string, sharingResource: string):
    Promise<cloudExtension.Result<void>> {
    console.info(`exit share, bundle: ${bundleName}`);
    // 对接云共享服务端，并获得退出共享的返回值
    // ...
    // 返回服务端退出共享的返回结果
    return {
      code: cloudData.sharing.SharingCode.SUCCESS,
      description: 'exit share succeeded'
    }
  }

  async changePrivilege(userId: number, bundleName: string, sharingResource: string, participants: Array<Participant>):
    Promise<cloudExtension.Result<Array<cloudExtension.Result<Participant>>>> {
    console.info(`change privilege, bundle: ${bundleName}`);
    // 对接云共享服务端，并获得更改权限的返回值
    // ...
    // 返回服务端更改权限的返回结果
    let result: Array<cloudExtension.Result<Participant>> = [];
    participants.forEach((item => {
      result.push({
        code: cloudData.sharing.SharingCode.SUCCESS,
        description: 'change privilege succeeded'
      })
    }))
    return {
      code: cloudData.sharing.SharingCode.SUCCESS,
      description: 'change privilege succeeded',
      value: result
    }
  }

  async queryParticipants(userId: number, bundleName: string, sharingResource: string):
    Promise<cloudExtension.Result<Array<Participant>>> {
    console.info(`query participants, bundle: ${bundleName}`);
    // 对接云共享服务端，并获得查询参与者的返回值
    // ...
    // 返回服务端查询参与者的返回结果
    let participants = new Array<cloudData.sharing.Participant>();
    participants.push({
      identity: '000000000',
      role: cloudData.sharing.Role.ROLE_INVITEE,
      state: cloudData.sharing.State.STATE_ACCEPTED,
      privilege: {
        writable: false,
        readable: true,
        creatable: false,
        deletable: false,
        shareable: false
      },
      attachInfo: ''
    })
    participants.push({
      identity: '111111111',
      role: cloudData.sharing.Role.ROLE_INVITEE,
      state: cloudData.sharing.State.STATE_ACCEPTED,
      privilege: {
        writable: false,
        readable: true,
        creatable: false,
        deletable: false,
        shareable: false
      },
      attachInfo: ''
    })
    return {
      code: cloudData.sharing.SharingCode.SUCCESS,
      description: 'query participants succeeded',
      value: participants
    }
  }

  async queryParticipantsByInvitation(userId: number, bundleName: string, invitationCode: string):
    Promise<cloudExtension.Result<Array<Participant>>> {
    console.info(`query participants by invitation, bundle: ${bundleName}`);
    // 对接云共享服务端，并获得查询参与者的返回值
    // ...
    // 返回服务端查询参与者的返回结果
    let participants = new Array<cloudData.sharing.Participant>();
    participants.push({
      identity: '000000000',
      role: cloudData.sharing.Role.ROLE_INVITEE,
      state: cloudData.sharing.State.STATE_ACCEPTED,
      privilege: {
        writable: false,
        readable: true,
        creatable: false,
        deletable: false,
        shareable: false
      },
      attachInfo: ''
    })
    participants.push({
      identity: '111111111',
      role: cloudData.sharing.Role.ROLE_INVITEE,
      state: cloudData.sharing.State.STATE_ACCEPTED,
      privilege: {
        writable: false,
        readable: true,
        creatable: false,
        deletable: false,
        shareable: false
      },
      attachInfo: ''
    })
    return {
      code: cloudData.sharing.SharingCode.SUCCESS,
      description: 'query participants by invitation succeeded',
      value: participants
    }
  }

  async confirmInvitation(userId: number, bundleName: string, invitationCode: string, state: cloudData.sharing.State):
    Promise<cloudExtension.Result<string>> {
    console.info(`confirm invitation, bundle: ${bundleName}`);
    // 对接云共享服务端，并获得确认共享邀请的返回值
    // ...
    // 返回服务端确认共享邀请的返回结果
    return {
      code: cloudData.sharing.SharingCode.SUCCESS,
      description: 'confirm invitation succeeded',
      value: 'sharing_resource_test'
    }
  }

  async changeConfirmation(userId: number, bundleName: string, sharingResource: string, state: cloudData.sharing.State):
    Promise<cloudExtension.Result<void>> {
    console.info(`change confirm, bundle: ${bundleName}`);
    // 对接云共享服务端，并获得更改共享邀请的返回值
    // ...
    // 返回服务端更改共享邀请的返回结果
    return {
      code: cloudData.sharing.SharingCode.SUCCESS,
      description: 'change confirm succeeded'
    }
  }
}

class MyCloudService implements cloudExtension.CloudService {
  constructor() {
  }

  async getServiceInfo(): Promise<cloudExtension.ServiceInfo> {
    console.info(`get service info`);
    // ...
    return {
      enableCloud: true,
      id: "test_id",
      totalSpace: test_space,
      remainingSpace: test_space,
      user: test_userId,
    };
  }

  async getAppBriefInfo(): Promise<Record<string, cloudExtension.AppBriefInfo>> {
    console.info(`get app brief info`);
    // ...
    return {
      "test_bundle":
      {
        appId: "test_appID",
        bundleName: "test_bundlename",
        cloudSwitch: true,
        instanceId: 0,
      }
    };
  }

  async getAppSchema(bundleName: string): Promise<cloudExtension.Result<cloudExtension.AppSchema>> {
    console.info(`get app schema, bundleName:${bundleName}`);
    // ...
    return {
      code: cloudExtension.ErrorCode.SUCCESS,
      description: "get app schema success",
      value: {
        bundleName: "test_bundleName",
        version: 1,
        databases: []
      }
    };
  }

  async subscribe(subInfo: Record<string, Array<cloudExtension.Database>>, expirationTime: number): Promise<cloudExtension.Result<cloudExtension.SubscribeInfo>> {
    console.info
    (`subscribe expirationTime: ${expirationTime}`);
    // ...
    return {
      code: cloudExtension.ErrorCode.SUCCESS,
      description: "subscribe success",
      value: {
        expirationTime: test_time,
        subscribe: {}
      }
    };
  }

  async unsubscribe(unsubscribeInfo: Record<string, Array<string>>): Promise<number> {
    console.info(`unsubscribe`);
    // ...
    return cloudExtension.ErrorCode.SUCCESS;
  }

  async connectDB(bundleName: string, database: cloudExtension.Database): Promise<rpc.RemoteObject> {
    console.info(`connect DB, bundleName: ${bundleName}`);
    return cloudExtension.createCloudDBStub(new MyCloudDB());
  }

  async connectAssetLoader(bundleName: string, database: cloudExtension.Database): Promise<rpc.RemoteObject> {
    console.info(`connect asset loader, bundle: ${bundleName}`);
    return cloudExtension.createAssetLoaderStub(new MyAssetLoader());
  }

  async connectShareCenter(userId: number, bundleName: string): Promise<rpc.RemoteObject> {
    console.info(`connect share center, bundle: ${bundleName}`);
    // ...
    return cloudExtension.createShareServiceStub(new MyShareCenter());
  }
}

export default class MyServiceExtension extends ServiceExtensionAbility {
  onCreate(want: Want) {
    console.info(`onCreate: ${want}`);
  }

  onRequest(want: Want, startId: number) {
    console.info(`onRequest: ${want} ${startId}`);
  }

  onConnect(want: Want): rpc.RemoteObject | Promise<rpc.RemoteObject> {
    console.info(`onConnect: ${want}`);
    return cloudExtension.createCloudServiceStub(new MyCloudService());
  }

  onDisconnect(want: Want) {
    console.info(`onDisconnect: ${want}`);
  }

  onDestroy() {
    console.info('onDestroy');
  }
}
```
<!--no_check-->
