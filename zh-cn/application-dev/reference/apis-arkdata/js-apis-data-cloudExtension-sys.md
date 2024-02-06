# @ohos.data.cloudExtension (端云共享Extension)(系统接口)

端云共享Extension，提供三方厂商适配共享云服务的能力。通过实现端云共享Extension提供的接口，对接端侧的数据共享到服务端，实现端云共享的发起、取消或退出，更改共享数据的操作权限、查询共享参与者、根据共享邀请码查询共享参与者、确认或更改共享邀请，并支持返回共享云服务的相关结果。

其中，端云共享资源标识是指：对于应用发起共享的每一条数据记录，该条数据在进行端云同步时会生成唯一的共享资源标识（字符串类型的值），此标识则作为该条数据记录共享时的识别标识。

端云共享参与者是指： 共享发起者根据好友列表选中的参与当前数据共享的所有人员。

端云共享邀请码是指： 共享发起后，在共享的服务端会生成当前共享操作的邀请码，并将该邀请码附加到当前共享邀请中，通过push消息推送到被邀请者的设备端，被邀请者可以通过该邀请码进行邀请的确认。

同步云是指： 端云同步的服务端，是同应用同帐号跨设备的同步。

共享云是指： 端云共享的服务端，是同应用跨帐号跨设备的共享。

> **说明：** 
>
> - 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本模块接口为系统接口。

## 导入模块

```ts
import cloudExtension from '@ohos.data.cloudExtension';
```

## Result&lt;T&gt;

共享结果的返回值。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

| 名称          | 类型                          | 必填  | 说明           |
| ----------- | --------------------------- | --- | ------------ |
| code        | number                      | 是   | 错误码。       |
| description | string                      | 否   | 错误码详细描述，默认为undefined。       |
| value       | T                           | 否   | 返回结果的值，具体类型由参数T指定，默认为undefined。       |

## CloudAsset<sup>11+</sup>

云资产的信息。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

| 名称    | 类型   | 必填 | 说明           |
| ------- | ------ | ---- | -------------- |
| assetId | string | 是   | 资产ID。       |
| hash    | string | 是   | 资产的哈希值。 |

## ServiceInfo<sup>11+</sup>

云服务信息。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

| 名称           | 类型    | 必填 | 说明                                                         |
| -------------- | ------- | ---- | ------------------------------------------------------------ |
| enableCloud    | boolean | 是   | 启用云服务，enableCloud的值为true时是启用云服务，为false时是未启用。 |
| id             | string  | 是   | 使用哈希函数SHA256生成的云账户 ID。                          |
| totalSpace     | number  | 是   | 服务器上账户的总空间（KB）。                                 |
| remainingSpace | number  | 是   | 服务器上账户的可用空间（KB）。                               |
| user           | number  | 是   | 设备的当前用户ID。                                           |

## Flag<sup>11+</sup>

描述数据库上执行操作的枚举。请使用枚举名而非枚举值。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

| 名称   | 值   | 说明       |
| ------ | ---- | ---------- |
| INSERT | 0    | 插入操作。 |
| UPDATE | 1    | 更新操作。 |
| DELETE | 2    | 删除操作。 |

## ExtensionValue<sup>11+</sup>

扩展值定义。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

| 名称       | 类型            | 必填 | 说明                                       |
| ---------- | --------------- | ---- | ------------------------------------------ |
| id         | string          | 是   | 执行插入操作时生成，只读数据不可手动更改。 |
| createTime | number          | 是   | 创建行数据的时间。只读数据不可手动更改。   |
| modifyTime | number          | 是   | 修改行数据的时间。只读数据不可手动更改。   |
| operation  | [Flag](#flag11) | 是   | 行数据所作的操作。                         |

## CloudType<sup>11+</sup>

云类型。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

| 类型                        | 说明                                         |
| --------------------------- | -------------------------------------------- |
| null                        | 表示为空。                                   |
| number                      | 表示数字类型。                               |
| string                      | 表示字符串类型。                             |
| boolean                     | 表示布尔类型。                               |
| Uint8Array                  | 表示 8 位无符号整型数组。                    |
| [CloudAsset](#cloudasset11) | 表示云资产类型。                             |
| CloudAssets                 | 表示Array&lt;[CloudAsset](#cloudasset11)&gt;类型。 |

## CloudInfo<sup>11+</sup>

云信息。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

| 名称      | 类型                                                  | 必填 | 说明           |
| --------- | ----------------------------------------------------- | ---- | -------------- |
| cloudInfo | [ServiceInfo](#serviceinfo11)                         | 是   | 云信息。       |
| apps      | Record&lt;string, [AppBriefInfo](#appbriefinfo11)&gt; | 是   | 简要应用信息。 |

## CloudData<sup>11+</sup>

云数据。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

| 名称       | 类型                                                         | 必填 | 说明                                                         |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| nextCursor | string                                                       | 是   | 查询游标。                                                   |
| hasMore    | boolean                                                      | 是   | 服务器是否存在更多数据可供查询。                             |
| values     | Array&lt;Record&lt;string, [CloudType](#cloudtype11)&gt;&gt; | 是   | 需要查询数据的数组，包括data value（数据值）和[ExtensionValue](#extensionvalue11)（扩展值)。CloudType的类型可以为null、number、string、boolean、Uint8、Array、[CloudAsset](#cloudasset11)或Array&lt;[CloudAsset](#cloudasset11)&gt;。 |

## AppBriefInfo<sup>11+</sup>

简要应用信息。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

| 名称        | 类型    | 必填 | 说明                               |
| ----------- | ------- | ---- | ---------------------------------- |
| appId       | string  | 是   | 应用程序 ID。                      |
| bundleName  | string  | 是   | 应用包名。                         |
| cloudSwitch | boolean | 是   | 云开关，表示应用程序是否启用了云。 |
| instanceId  | number  | 是   | 应用分身 ID。                      |

## FieldType<sup>11+</sup>

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

## Field<sup>11+</sup>

数据库中的字段结构。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

| 名称     | 类型                      | 必填 | 说明                   |
| -------- | ------------------------- | ---- | ---------------------- |
| alias    | string                    | 是   | 服务器上字段名。       |
| colName  | string                    | 是   | 列名。                 |
| type     | [FieldType](#fieldtype11) | 是   | 字段类型。             |
| primary  | boolean                   | 是   | 表示当前列是否是主键。 |
| nullable | boolean                   | 是   | 当前列是否为空值       |

## Table<sup>11+</sup>

表结构信息。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

| 名称   | 类型                           | 必填 | 说明             |
| ------ | ------------------------------ | ---- | ---------------- |
| alias  | string                         | 是   | 服务器上的表名。 |
| name   | string                         | 是   | 表名。           |
| fields | Array&lt;[Field](#field11)&gt; | 是   | 表格中的字段。   |

## Database<sup>11+</sup>

数据库结构信息。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

| 名称   | 类型                           | 必填 | 说明                             |
| ------ | ------------------------------ | ---- | -------------------------------- |
| name   | string                         | 是   | 数据库名称。                     |
| alias  | string                         | 是   | 服务器上数据库的名称。           |
| tables | Array&lt;[Table](#table11)&gt; | 是   | 数据库中的表，包含数据详细信息。 |

## AppSchema<sup>11+</sup>

应用数据库模式。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

| 名称       | 类型                                 | 必填 | 说明               |
| ---------- | ------------------------------------ | ---- | ------------------ |
| bundleName | string                               | 是   | 应用包名。         |
| version    | number                               | 是   | 数据库模式的版本。 |
| databases  | Array&lt;[Database](#database11)&gt; | 是   | 应用的数据库信息。 |

## SubscribeId<sup>11+</sup>

订阅 ID。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

| 名称          | 类型   | 必填 | 说明                   |
| ------------- | ------ | ---- | ---------------------- |
| databaseAlias | string | 是   | 服务器上数据库的名称。 |
| id            | string | 是   | 订阅 ID。              |

## SubscribeInfo<sup>11+</sup>

订阅信息。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

| 名称           | 类型                                                         | 必填 | 说明               |
| -------------- | ------------------------------------------------------------ | ---- | ------------------ |
| expirationTime | number                                                       | 是   | 订阅过期时间(ms)。 |
| subscribe      | Record&lt;string, Array&lt;[SubscribeId](#subscribeid11)&gt;&gt; | 是   | 订阅信息。         |

## LockInfo<sup>11+</sup>

云数据库锁信息，单位：秒（s）。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

| 名称     | 类型   | 必填 | 说明                         |
| -------- | ------ | ---- | ---------------------------- |
| interval | number | 是   | 云数据库锁的持续时间（秒）。 |
| lockId   | number | 是   | 锁ID。                       |

## ErrorCode<sup>11+</sup>

表示端云共享过程的状态。请使用枚举名而非枚举值。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

| 名称                  | 值   | 说明                                                         |
| --------------------- | ---- | ------------------------------------------------------------ |
| SUCCESS               | 0    | 表示端云同步过程成功。                                       |
| UNKNOWN_ERROR         | 1    | 表示端云同步过程中遇到未知错误。                             |
| NETWORK_ERROR         | 2    | 表示端云同步过程中遇到网络错误                               |
| CLOUD_DISABLED        | 3    | 表示云端不可用。                                             |
| LOCKED_BY_OTHERS      | 4    | 表示有其他设备正在进行端云同步，本设备无法进行端云同步。请确保无其他设备占用端云资源后，在使用本设备进行端云同步任务。 |
| RECORD_LIMIT_EXCEEDED | 5    | 表示本次端云同步需要同步的条目或大小超出最大值。由云端配置最大值。 |
| NO_SPACE_FOR_ASSET    | 6    | 表示云空间剩余空间小于待同步的资产大小。                     |

## cloudExtension.createCloudServiceStub

createCloudServiceStub(instance: CloudService): Promise&lt;rpc.RemoteObject&gt;

根据[CloudService](#cloudservice)类的实例创建对应的[RemoteObject](../apis/js-apis-rpc.md#remoteobject)对象，系统内部通过该对象调用[CloudService](#cloudservice)的实现接口，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名    | 类型                            | 必填 | 说明                                                         |
| --------- | ------------------------------- | ---- | -------------------------------- |
| instance  | [CloudService](#cloudservice)   | 是    | [CloudService](#cloudservice)类的实例。   |

**返回值：**

| 类型                | 说明                      |
| -------------------             | ------------------------- |
| Promise&lt;[rpc.RemoteObject](../apis/js-apis-rpc.md#remoteobject)&gt; | Promise对象，返回[CloudService](#cloudservice)的[RemoteObject](../apis/js-apis-rpc.md#remoteobject)对象。 |

**示例：**

```ts
import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';
import Want from '@ohos.app.ability.Want';
import rpc from '@ohos.rpc';

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

根据[ShareCenter](#sharecenter)类的实例创建对应的[RemoteObject](../apis/js-apis-rpc.md#remoteobject)对象，系统内部通过该对象调用[ShareCenter](#sharecenter)的实现接口，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名    | 类型                            | 必填 | 说明                                                         |
| --------- | ------------------------------- | ---- | -------------------------------- |
| instance  | [ShareCenter](#sharecenter)   | 是    | [ShareCenter](#sharecenter)类的实例。                   |

**返回值：**

| 类型                | 说明                      |
| -------------------             | ------------------------- |
| Promise&lt;[rpc.RemoteObject](../apis/js-apis-rpc.md#remoteobject)&gt; | Promise对象，返回[ShareCenter](#sharecenter)的[RemoteObject](../apis/js-apis-rpc.md#remoteobject)对象。 |

**示例：**

```ts
import rpc from '@ohos.rpc';

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

## cloudExtension.createCloudDBStub<sup>11+</sup>

createCloudDBStub(instance: CloudDB): Promise&lt;rpc.RemoteObject&gt;

根据[CloudDB](#clouddb11)类的实例创建对应的[RemoteObject]((../apis/js-apis-rpc.md#remoteobject))对象，系统内部通过该对象调用[CloudDB](#clouddb11)的实现接口，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名   | 类型                  | 必填 | 说明                            |
| -------- | --------------------- | ---- | ------------------------------- |
| instance | [CloudDB](#clouddb11) | 是   | [CloudDB](#clouddb11)类的实例。 |

**返回值：**

| 类型                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| Promise&lt;[rpc.RemoteObject](../apis/js-apis-rpc.md#remoteobject)&gt; | Promise对象，返回[CloudDB](#clouddb11)的[rpc.RemoteObject](../apis/js-apis-rpc.md#remoteobject)]对象。 |

```ts
import rpc from '@ohos.rpc';

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

## cloudExtension.createAssetLoaderStub<sup>11+</sup>

createAssetLoaderStub(instance: AssetLoader): Promise&lt;rpc.RemoteObject&gt;

根据[CloudDB](#clouddb11)类的实例创建对应的[RemoteObject](../apis/js-apis-rpc.md#remoteobject)对象，系统内部通过该对象调用[CloudDB](#clouddb11)的实现接口，使用Promise异步回调。

**参数：**

| 参数名   | 类型                          | 必填 | 说明                                              |
| -------- | ----------------------------- | ---- | ------------------------------------------------- |
| instance | [AssetLoader](#assetloader11) | 是   | 表示一个[AssetLoader](#assetloader11)类型的实例。 |

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**返回值：**

| 类型                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| Promise&lt;[rpc.RemoteObject](../apis/js-apis-rpc.md#remoteobject)&gt; | Promise对象，返回[AssetLoader](#assetloader11)的[rpc.RemoteObject](../apis/js-apis-rpc.md#remoteobject)对象。 |

**示例：**

```ts
import rpc from '@ohos.rpc';

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



## CloudDB<sup>11+</sup>

提供云数据库的操作接口的类。

### generateId<sup>11+</sup>

generateId(count: number): Promise&lt;Result&lt;Array&lt;string&gt;&gt;&gt;

通过该接口生成要插入云数据行的 ID。 表中的每个ID都是唯一的。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名 | 类型   | 必填 | 说明                 |
| ------ | ------ | ---- | -------------------- |
| count  | number | 是   | 表示要生成ID的数量。 |

**返回值：**

| 类型                                               | 说明                        |
| -------------------------------------------------- | --------------------------- |
| Promise&lt;[Result](#resultt)&gt;Array&lt;string&gt;&gt; | Promise对象，返回生成的ID。 |

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

### update<sup>11+</sup>

update(table: string, values: Array&lt;Record&lt;string, CloudType>>, extensions: Array&lt;Record&lt;string, CloudType>> ): Promise&lt;Array&lt;Result&lt;Record&lt;string, CloudType>>>>

通过该接口更新云上的数据。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                   |
| ---------- | ------------------------------------------------------------ | ---- | ---------------------- |
| table      | string                                                       | 是   | 表示要生成 ID的 数量。 |
| values     | Array&lt;Record&lt;string, [CloudType](#cloudtype11)&gt;&gt; | 是   | 表示要插入的数据。     |
| extensions | Array&lt;Record&lt;string, [CloudType](#cloudtype11)&gt;&gt; | 是   | 表示扩展值。           |

**返回值：**

| 类型                                                         | 说明                        |
| ------------------------------------------------------------ | --------------------------- |
| Promise&lt;Array&lt;[Result](#resultt)&lt;Record&lt;string,  [CloudType](#cloudtype11)&gt;&gt;&gt;&gt; | Promise对象，返回更新结果。 |

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

### insert<sup>11+</sup>

insert(table: string, values: Array<Record<string, CloudType>>, extensions: Array<Record<string, CloudType>>): Promise<Array<Result<Record<string, CloudType&gt;&gt;&gt;&gt;

通过该接口将数据插入云数据库表中。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名     | 类型                                                      | 必填 | 说明               |
| ---------- | --------------------------------------------------------- | ---- | ------------------ |
| table      | string                                                    | 是   | 表名。             |
| values     | Array&lt;Record&lt;string, [CloudType](#cloudtype11)&gt;&gt; | 是   | 表示要插入的数据。 |
| extensions | Array&lt;Record&lt;string, [CloudType](#cloudtype11)&gt;&gt; | 是   | 表示扩展值。       |

**返回值：**

| 类型                                                         | 说明                        |
| ------------------------------------------------------------ | --------------------------- |
| Promise&lt;Array&lt;[Result](#resultt)&lt;Record&lt;string, [CloudType](#cloudtype11)&gt;&gt;&gt;&gt; | Promise对象，返回插入结果。 |

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

### delete<sup>11+</sup>

delete(table: string, extensions: Array&lt;Record&lt;string, CloudType>> ): Promise&lt;Array&lt;Result&lt;Record&lt;string, CloudType&gt;&gt;&gt;&gt;

调用该接口删除数据。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名     | 类型                                            | 必填 | 说明         |
| ---------- | ----------------------------------------------- | ---- | ------------ |
| table      | string                                          | 是   | 表名。       |
| extensions | Array&lt;Record&lt;string,[CloudType](#cloudtype11)&gt;&gt; | 是   | 表示扩展值。 |

**返回值：**

| 类型                                                         | 说明                        |
| ------------------------------------------------------------ | --------------------------- |
| Promise&lt;Array&lt;[Result](#resultt)&lt;Record&lt;string, [CloudType](#cloudtype11)&gt;&gt;&gt;&gt; | Promise对象，返回删除结果。 |

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

### query<sup>11+</sup>

query(table: string, fields: Array&lt;string&gt;, queryCount: number, queryCursor: string): Promise&lt;Result&lt;CloudData&gt;&gt;

调用该接口查询数据。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名      | 类型          | 必填 | 说明                     |
| ----------- | ------------- | ---- | ------------------------ |
| table       | string        | 是   | 表名。                   |
| fields      | Array&lt;string&gt; | 是   | 表示扩展值。             |
| queryCount  | number        | 是   | 表示要查询的数据记录数。 |
| queryCursor | string        | 是   | 表示要查询的游标。       |

**返回值：**

| 类型                                          | 说明                        |
| --------------------------------------------- | --------------------------- |
| Promise&lt;Result&lt;[CloudData](#clouddata11)&gt;&gt; | Promise对象，返回查询结果。 |

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

###  lock<sup>11+</sup>

 lock(): Promise&lt;Result&lt;LockInfo&gt;&gt;

调用该接口为云数据库加锁。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**返回值：**

| 类型                                                 | 说明                          |
| ---------------------------------------------------- | ----------------------------- |
| Promise&lt;Result&lt;[LockInfo](#lockinfo11)&gt;&gt; | Promise对象，返回加锁的信息。 |

7**示例：**

```ts
export default class MyCloudDB implements cloudExtension.CloudDB {
  let  test_time = 10;
  let  test_lockId = 1;
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

### heartbeat<sup>11+</sup>

heartbeat(lockId: number): Promise&lt;Result&lt;LockInfo&gt;&gt;

调用该接口延长数据库的加锁时效。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名 | 类型   | 必填 | 说明                  |
| ------ | ------ | ---- | --------------------- |
| lockId | number | 是   | 表示需要延时的锁 ID。 |

**返回值：**

| 类型                                                 | 说明                        |
| ---------------------------------------------------- | --------------------------- |
| Promise&lt;Result&lt;[LockInfo](#lockinfo11)&gt;&gt; | Promise对象，返回锁的信息。 |

**示例：**

```ts
export default class MyCloudDB implements cloudExtension.CloudDB {
  let  test_lockId = 1;
  let  test_time = 10;
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

### unlock<sup>11+</sup>

unlock(lockId: number): Promise&lt;Result&lt;boolean&gt;&gt;;

调用该接口为云数据库解锁。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名 | 类型   | 必填 | 说明          |
| ------ | ------ | ---- | ------------- |
| lockId | number | 是   | 表示锁的 ID。 |

**返回值：**

| 类型                                 | 说明                        |
| ------------------------------------ | --------------------------- |
| Promise&lt;Result&lt;boolean&gt;&gt; | Promise对象，返回解锁结果。 |

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

提供对接同步云服务的类。开发者需要继承此类并实现类的接口，系统内部通过该类的接口联接并使用同步云服务。

### getServiceInfo<sup>11+</sup>

getServiceInfo(): Promise<ServiceInfo&gt;

系统内部通过该接口获取服务器上的信息。使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**返回值：**

| 类型                                         | 说明                                |
| -------------------------------------------- | ----------------------------------- |
| Promise&lt;[ServiceInfo](#serviceinfo11)&gt; | Promise对象，返回获取的服务器信息。 |

**示例：**

```ts
import rpc from '@ohos.rpc';

let test_Space = 100;
let test_userId = 1;

export default class MyCloudService implements cloudExtension.CloudService {
  constructor() {}
  // ...
  async getServiceInfo(): Promise<cloudExtension.ServiceInfo> {
    console.info(`get service info`);
    // ...
    return {
      enableCloud: true,
      id: "test_id",
      totalSpace: test_Space,
      remainingSpace: test_Space,
      user: test_userId,
    };
  }
}
```

### getAppBriefInfo<sup>11+</sup>

getAppBriefInfo(): Promise<Record<string, AppBriefInfo>>

系统内部通过该接口获取简要应用信息。使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**返回值：**

| 类型                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| Promise&lt;[Record](#resultt)&lt;string, [AppBriefInfo](#AppBriefInfo11)&gt;&gt;&gt; | Promise对象，返回与bundle和 [AppBriefInfo](#AppBriefInfo11)相对应的键值对。 |

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

### getAppSchema<sup>11+</sup>

 getAppSchema(bundleName: string): Promise&lt;Result&lt;AppSchema&gt;&gt;

系统内部通过该接口获取应用Schema（数据库模式）信息。使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名     | 类型   | 必填 | 说明       |
| ---------- | ------ | ---- | ---------- |
| bundleName | string | 是   | 应用包名。 |

**返回值：**

| 类型                                                         | 说明                                  |
| ------------------------------------------------------------ | ------------------------------------- |
| Promise&lt;[Result](#resultt)&lt;[AppSchema](#appschema11)&gt;&gt; | Promise对象，返回数据库的schema信息。 |

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

### subscribe<sup>11+</sup>

subscribe(subInfo: Record&lt;string, Array&lt;Database&gt;&gt;, expirationTime: number): Promise&lt;Result&lt;SubscribeInfo&gt;&gt;

系统内部通过该接口发起订阅，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名         | 类型                                                       | 必填 | 说明                                                   |
| -------------- | ---------------------------------------------------------- | ---- | ------------------------------------------------------ |
| subInfo        | Record&lt;string, Array&lt;[Database](#database11)&gt;&gt; | 是   | 需要订阅的数据，由应用包名称和数据库信息组成的键值对。 |
| expirationTime | number                                                     | 是   | 表示订阅到期时间。                                     |

**返回值：**

| 类型                                                         | 说明                          |
| ------------------------------------------------------------ | ----------------------------- |
| Promise&lt;Result&lt;[SubscribeInfo](#subscribeinfo11)&gt;&gt; | Promise对象，返回订阅的结果。 |

**示例：**

```ts
let test_time = 10;
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



### unsubscribe<sup>11+</sup>

unsubscribe(unsubscribeInfo: Record&lt;string, Array&lt;string&gt;&gt;): Promise&lt;number&gt;

通过该接口取消订阅云中的数据变更。使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名          | 类型                                   | 必填 | 说明                                                         |
| --------------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| unsubscribeInfo | Record&lt;string, Array<string&gt;&gt; | 是   | 需要取消订阅的数据信息，由应用包名和数据库结构组成的键值对。 |

**返回值：**

| 类型                   | 说明                            |
| ---------------------- | ------------------------------- |
| Promise<&lt;number&gt; | Promise对象，返回反订阅的结果。 |

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

### connectDB<sup>11+</sup>

 connectDB(bundleName: string, database: Database): Promise&lt;rpc.RemoteObject&gt;

通过该接口连接数据库。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名     | 类型                    | 必填 | 说明               |
| ---------- | ----------------------- | ---- | ------------------ |
| bundleName | string                  | 是   | 应用包名。         |
| database   | [Database](#database11) | 是   | 需要连接的数据库。 |

**返回值：**

| 类型                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| Promise&lt;[rpc.RemoteObject](js-apis-rpc.md#remoteobject)&gt; | Promise对象，返回[ShareCenter](#sharecenter)的[RemoteObject](js-apis-rpc.md#remoteobject)对象。 |

```ts
import rpc from '@ohos.rpc';

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

### connectAssetLoader<sup>11+</sup>

connectAssetLoader(bundleName: string, database: Database): Promise&lt;rpc.RemoteObject&gt;

通过该接口连接资产加载器。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名     | 类型                    | 必填 | 说明               |
| ---------- | ----------------------- | ---- | ------------------ |
| bundleName | string                  | 是   | 应用包名。         |
| database   | [Database](#database11) | 是   | 需要连接的数据库。 |

**返回值：**

| 类型                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| Promise&lt;[rpc.RemoteObject](js-apis-rpc.md#remoteobject)&gt; | Promise对象，返回[ShareCenter](#sharecenter)的[RemoteObject](js-apis-rpc.md#remoteobject)对象。 |

```ts
import rpc from '@ohos.rpc';

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

系统内部通过该接口获取[ShareCenter](#sharecenter)的[RemoteObject](../apis/js-apis-rpc.md#remoteobject)对象，可以通过[createShareServiceStub](#cloudextensioncreateshareservicestub)接口进行创建，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名  | 类型                    | 必填 | 说明                                            |
| ------- | ----------------------- | ---- | ----------------------------------------------- |
| userId      | number  | 是   | 表示用户ID。         |
| bundleName  | string  | 是   | 应用包名。   |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;[rpc.RemoteObject](../apis/js-apis-rpc.md#remoteobject)&gt; | Promise对象，返回[ShareCenter](#sharecenter)的[RemoteObject](../apis/js-apis-rpc.md#remoteobject)对象。 |

**示例：**

```ts
import rpc from '@ohos.rpc';

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

## AssetLoader<sup>11+</sup>

提供资产的上传下载接口的类。实现资产的上传和下载能力。

### download<sup>11+</sup>

download(table: string, gid: string, prefix: string, assets: Array&lt;CloudAsset&gt;): Promise&lt;Array&lt;Result&lt;CloudAsset&gt;&gt;&gt;

通过该接口实现资产的下载。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名 | 类型                                     | 必填 | 说明                                 |
| ------ | ---------------------------------------- | ---- | ------------------------------------ |
| table  | string                                   | 是   | 表名。                               |
| gid    | string                                   | 是   | 表示 GID。数据上云后生成的唯一标记。 |
| prefix | string                                   | 是   | 表示前缀信息。                       |
| assets | Array&lt;[CloudAsset](#cloudasset11)&gt; | 是   | 表示需要下载的资产。                 |

**返回值：**

| 类型                                                         | 说明                          |
| ------------------------------------------------------------ | ----------------------------- |
| Promise&lt;Array&lt;[Result](resultt)&lt;[CloudAsset](#cloudasset11)&gt;&gt;&gt; | Promise对象，返回资产下载结果 |

**示例：**

```ts
export default class MyAssetLoader implements cloudExtension.AssetLoader {
  async download(table: string, gid: string, prefix: string, assets: Array<cloudExtension.CloudAsset>): Promise<Array<cloudExtension.Result<cloudExtension.CloudAsset>>> {
    console.info(`download asset loader, table: ${table}, gid: ${gid}, prefix: ${prefix}`);
    let downloadres = Array<cloudExtension.Result<cloudExtension.CloudAsset>>();
    // ...
    return downloadres;
  }
}
```

### upload<sup>11+</sup>

upload(table: string, gid: string, assets: Array&lt;CloudAsset&gt;): Promise&lt;Array&lt;Result&lt;CloudAsset&gt;&gt;&gt;

通过该接口实现资产的下载。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名 | 类型                                     | 必填 | 说明                                 |
| ------ | ---------------------------------------- | ---- | ------------------------------------ |
| table  | string                                   | 是   | 表名。                               |
| gid    | string                                   | 是   | 表示 GID，数据上云后生成的唯一标记。 |
| assets | Array&lt;[CloudAsset](#cloudasset11)&gt; | 是   | 表示需要上传的资产。                 |

**返回值：**

| 类型                                                         | 说明                              |
| ------------------------------------------------------------ | --------------------------------- |
| Promise&lt;Array&lt;[Result](#resultt)&lt;[CloudAsset](#cloudasset11)&gt;&gt;&gt; | Promise对象，返回发起共享的结果。 |

**示例：**

```ts
export default class MyAssetLoader implements cloudExtension.AssetLoader {
  async upload(table: string, gid: string, assets: Array<cloudExtension.CloudAsset>): Promise<Array<cloudExtension.Result<cloudExtension.CloudAsset>>> {
    console.info(`upload asset loader, table: ${table}, gid: ${gid}`);
    let uploadres = Array<cloudExtension.Result<cloudExtension.CloudAsset>>();
    // ...
    return uploadres;
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
| participants    | Array&lt;[cloudData.sharing.Participant](js-apis-data-cloudData.md#participant11)&gt;  | 是   | 端云共享参与者。   |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;[Result](#resultt)&lt;Array&lt;[Result](#resultt)&lt;[cloudData.sharing.Participant](js-apis-data-cloudData.md#participant11)&gt;&gt;&gt;&gt; | Promise对象，返回发起共享的结果。 |

**示例：**

```ts
import cloudData from '@ohos.data.cloudData';

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
| participants    | Array&lt;[cloudData.sharing.Participant](js-apis-data-cloudData.md#participant11)&gt;  | 是   | 端云共享参与者。   |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;[Result](#resultt)&lt;Array&lt;[Result](#resultt)&lt;[cloudData.sharing.Participant](js-apis-data-cloudData.md#participant11)&gt;&gt;&gt;&gt; | Promise对象，返回取消共享的结果。 |

**示例：**

```ts
import cloudData from '@ohos.data.cloudData';

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
import cloudData from '@ohos.data.cloudData';

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
| participants    | Array&lt;[cloudData.sharing.Participant](js-apis-data-cloudData.md#participant11)&gt;  | 是   | 端云共享参与者。   |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;[Result](#resultt)&lt;Array&lt;[Result](#resultt)&lt;[cloudData.sharing.Participant](js-apis-data-cloudData.md#participant11)&gt;&gt;&gt;&gt; | Promise对象，返回更改权限的结果。 |

**示例：**

```ts
import cloudData from '@ohos.data.cloudData';

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
| Promise&lt;[Result](#resultt)&lt;Array&lt;[cloudData.sharing.Participant](js-apis-data-cloudData.md#participant11)&gt;&gt;&gt; | Promise对象，返回查询共享参与者的结果。 |

**示例：**

```ts
import cloudData from '@ohos.data.cloudData';

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
| Promise&lt;[Result](#resultt)&lt;Array&lt;[cloudData.sharing.Participant](js-apis-data-cloudData.md#participant11)&gt;&gt;&gt; | Promise对象，返回根据邀请码查询共享参与者的结果。 |

**示例：**

```ts
import cloudData from '@ohos.data.cloudData';

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
| state           | [cloudData.sharing.State](js-apis-data-cloudData.md#state11)  | 是   | 共享邀请的确认状态。   |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;[Result](#resultt)&lt;string&gt;&gt; | Promise对象，返回确认端云共享邀请数据的共享资源标识。 |

**示例：**

```ts
import cloudData from '@ohos.data.cloudData';

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
| state           | [cloudData.sharing.State](js-apis-data-cloudData.md#state11)  | 是   | 共享邀请的更改状态。   |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;[Result](#resultt)&lt;void&gt;&gt; | Promise对象，返回更改共享邀请的结果。 |

**示例：**

```ts
import cloudData from '@ohos.data.cloudData';

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
import cloudExtension from '@ohos.data.cloudExtension';
import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';
import Want from '@ohos.app.ability.Want';
import rpc from '@ohos.rpc';
import cloudData from '@ohos.data.cloudData';

type Participant = cloudData.sharing.Participant;
let test_lockId = 1;
let test_time = 10;
let test_Space = 100;
let test_userId = 1;

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
    let downloadres = Array<cloudExtension.Result<cloudExtension.CloudAsset>>();
    // ...
    return downloadres;
  }

  async upload(table: string, gid: string, assets: Array<cloudExtension.CloudAsset>): Promise<Array<cloudExtension.Result<cloudExtension.CloudAsset>>> {
    console.info(`upload asset loader, table: ${table}, gid: ${gid}`);
    let uploadres = Array<cloudExtension.Result<cloudExtension.CloudAsset>>();
    // ...
    return uploadres;
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
      totalSpace: test_Space,
      remainingSpace: test_Space,
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
