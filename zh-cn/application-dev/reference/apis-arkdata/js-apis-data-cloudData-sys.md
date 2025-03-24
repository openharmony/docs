# @ohos.data.cloudData (端云服务)(系统接口)

端云服务提供端云协同、端云共享和端云策略。

端云协同提供结构化数据（RDB Store）端云同步的能力。即：云作为数据的中心节点，通过与云的数据同步，实现数据云备份、同账号设备间的数据一致性。

端云共享是在端云协同能力基础上，实现跨账号的数据共享。其中，端云共享资源标识是指：对于应用发起共享的每一条数据记录，该条数据在进行端云同步时会生成唯一的共享资源标识（字符串类型的值），此标识则作为该条数据记录共享时的识别标识。

端云共享参与者是指： 共享发起者根据好友列表选中的参与当前数据共享的所有人员。

端云共享邀请码是指： 共享发起后，在共享的服务端会生成当前共享操作的邀请码，并将该邀请码附加到当前共享邀请中，通过push消息推送到被邀请者的设备端，被邀请者可以通过该邀请码进行邀请的确认。

该模块提供以下端云服务相关的常用功能：

- [Config](#config)：提供配置端云协同的方法，包括云同步打开、关闭、清理数据、数据变化通知。
- [sharing](#sharing11)：提供端云共享的方法，包括发起共享、取消共享、退出共享、更改共享数据权限、查找共享参与者、确认邀请、更改已确认的邀请、查找共享资源。

> **说明：** 
>
> - 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.data.cloudData (端云服务)](js-apis-data-cloudData.md)。
>
> - 使用本模块需要实现云服务功能。

## 导入模块

```ts
import { cloudData } from '@kit.ArkData';
```

## ClearAction

清除本地下载的云端数据的行为枚举。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Config

| 名称      | 说明                         |
| --------- | ---------------------------- |
| CLEAR_CLOUD_INFO | 清除从云端下载的数据的云标识，相关数据作为本地数据保存。 |
| CLEAR_CLOUD_DATA_AND_INFO |清除从云端下载的数据，不包括本地已修改的云端数据。   |

## ExtraData<sup>11+</sup>

透传数据，携带通知数据变更所需要的信息。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Config

| 名称      | 类型   | 必填 | 说明                                                         |
| --------- | ------ | ---- | ------------------------------------------------------------ |
| eventId   | string | 是   | 如果传值为"cloud_data_change"，表示云数据变更。              |
| extraData | string | 是   | 透传数据，extraData是json结构的字符串，其中必须包括"data"字段，"data"中是通知变更所需要的信息，包含账号、应用名、数据库名、数据库类型和数据库表名，所有字段均不能为空。

**示例：**

```ts
// accountId:用户打开的云账号ID
// bundleName:应用包名
// containerName:云上数据库名称
// databaseScopes:云上数据库类型
// recordTypes:云上数据库表名

interface ExtraData {
  eventId: "cloud_data_change",
  extraData: '{
    "data": "{
     "accountId": "aaa",
     "bundleName": "com.bbb.xxx",
     "containerName": "alias",
     "databaseScopes": ["private", "shared"],
     "recordTypes": ["xxx", "yyy", "zzz"]
    }"
  }'
}

```

## StatisticInfo<sup>12+</sup>

返回数据，携带端云同步统计信息所需要的信息。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Config

| 名称      | 类型   | 必填 | 说明                                                  |
| --------- | ------ | ---- |-----------------------------------------------------|
| table   | string | 是   | 查询的表名。如返回值为"cloud_notes"，表示查询结果是表名为"cloud_notes"的同步信息。 |
| inserted   | number | 是   | 本地新增且云端还未同步数据的条数，如返回值为2，表示本地新增2条数据且云端还未同步。          |
| updated   | number | 是   | 云端同步之后本地或云端修改还未同步的条数，如返回值为2，表示本地或云端修改还有2条数据未同步。     |
| normal | number | 是   | 端云一致的数据。如返回值为2，表示本地与云端一致的数据为2条。                     |

## SyncStatus<sup>18+</sup>

端云同步任务的状态。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Config

| 名称      | 值   | 说明              |
| -------- |-----|-----------------|
| RUNNING | 0  | 表示端云同步任务处于运行状态。 |
| FINISHED | 1   | 表示端云同步任务处于完成状态。 |

## SyncInfo<sup>12+</sup>

返回数据，最近一次端云同步所需要的信息。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Config

| 名称       | 类型                                                         | 必填 | 说明                       |
| ---------- | ------------------------------------------------------------ | ---- | -------------------------- |
| startTime  | Date                                                         | 是   | 最近一次端云同步的开始时间。 |
| finishTime | Date                                                         | 是   | 最近一次端云同步的结束时间。 |
| code       | [relationalStore.ProgressCode](js-apis-data-relationalStore.md#progresscode10) | 是   | 最近一次端云同步的结果。 |
| syncStatus<sup>18+</sup> | [SyncStatus](#syncstatus18) | 否 | 最近一次端云同步的状态，默认值cloudData.SyncStatus.RUNNING。 |

## Config

提供配置端云协同的方法，包括云同步打开、关闭、清理数据、数据变化通知。

### enableCloud

static enableCloud(accountId: string, switches: Record<string, boolean>, callback: AsyncCallback&lt;void&gt;): void

打开端云协同，使用callback异步回调。

**需要权限**：ohos.permission.CLOUDDATA_CONFIG

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Config

**参数：**

| 参数名    | 类型                            | 必填 | 说明                                                         |
| --------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| accountId | string                          | 是   | 具体打开的云账号ID。                                         |
| switches  | Record<string, boolean>         | 是   | 各应用的端云协同开关信息。true为打开该应用端云开关，false为关闭该应用端云开关。 |
| callback  | AsyncCallback&lt;void&gt;       | 是   | 回调函数。                                                   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                             |
| -------- | ---------------------------------------------------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.|
| 202      | Permission verification failed, application which is not a system application uses system API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|
| 801      | Capability not supported.|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let account: string = 'test_id';
let switches: Record<string, boolean> = { 'test_bundleName1': true, 'test_bundleName2': false };
try {
  cloudData.Config.enableCloud(account, switches, (err: BusinessError) => {
    if (err === undefined) {
      console.info('Succeeded in enabling cloud');
    } else {
      console.error(`Failed to enable.Code: ${err.code}, message: ${err.message}`);
    }
  });
} catch (e) {
  let error = e as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### enableCloud

static enableCloud(accountId: string, switches: Record<string, boolean>): Promise&lt;void&gt;

打开端云协同，使用Promise异步回调。

**需要权限**：ohos.permission.CLOUDDATA_CONFIG

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Config

**参数：**

| 参数名    | 类型                            | 必填 | 说明                                                         |
| --------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| accountId | string                          | 是   | 具体打开的云账号ID。                                         |
| switches  | Record<string, boolean>         | 是   | 各应用的端云协同开关信息。true为打开该应用端云开关，false为关闭该应用端云开关。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                             |
| -------- | ---------------------------------------------------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.|
| 202      | Permission verification failed, application which is not a system application uses system API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|
| 801      | Capability not supported.|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let account: string = 'test_id';
let switches: Record<string, boolean> = { 'test_bundleName1': true, 'test_bundleName2': false };
try {
  cloudData.Config.enableCloud(account, switches).then(() => {
    console.info('Succeeded in enabling cloud');
  }).catch((err: BusinessError) => {
    console.error(`Failed to enable.Code: ${err.code}, message: ${err.message}`);
  });
} catch (e) {
  let error = e as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### disableCloud

static disableCloud(accountId: string, callback: AsyncCallback&lt;void&gt;): void

关闭端云协同，使用callback异步回调。

**需要权限**：ohos.permission.CLOUDDATA_CONFIG

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Config

**参数：**

| 参数名    | 类型                      | 必填 | 说明                 |
| --------- | ------------------------- | ---- | -------------------- |
| accountId | string                    | 是   | 具体打开的云账号ID。 |
| callback  | AsyncCallback&lt;void&gt; | 是   | 回调函数。           |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                             |
| -------- | ---------------------------------------------------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.|
| 202      | Permission verification failed, application which is not a system application uses system API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|
| 801      | Capability not supported.|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let account: string = 'test_id';
try {
  cloudData.Config.disableCloud(account, (err: BusinessError) => {
    if (err === undefined) {
      console.info('Succeeded in disabling cloud');
    } else {
      console.error(`Failed to disableCloud. Code: ${err.code}, message: ${err.message}`);
    }
  });
} catch (e) {
  let error = e as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### disableCloud

static disableCloud(accountId: string): Promise&lt;void&gt;

关闭端云协同，使用Promise异步回调。

**需要权限**：ohos.permission.CLOUDDATA_CONFIG

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Config

**参数：**

| 参数名    | 类型   | 必填 | 说明                 |
| --------- | ------ | ---- | -------------------- |
| accountId | string | 是   | 具体打开的云账号ID。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                             |
| -------- | ---------------------------------------------------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.|
| 202      | Permission verification failed, application which is not a system application uses system API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|
| 801      | Capability not supported.|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let account: string = 'test_id';
try {
  cloudData.Config.disableCloud(account).then(() => {
    console.info('Succeeded in disabling cloud');
  }).catch((err: BusinessError) => {
    console.error(`Failed to disableCloud. Code: ${err.code}, message: ${err.message}`);
  });
} catch (e) {
  let error = e as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### changeAppCloudSwitch

static changeAppCloudSwitch(accountId: string, bundleName: string, status: boolean, callback: AsyncCallback&lt;void&gt;): void

修改单个应用端云协同开关，使用callback异步回调。

**需要权限**：ohos.permission.CLOUDDATA_CONFIG

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Config

**参数：**

| 参数名    | 类型                            | 必填 | 说明                         |
| --------- | ------------------------------- | ---- | ---------------------------- |
| accountId | string                          | 是   | 具体打开的云账号ID。 |
| bundleName| string                         | 是   | 应用名。 |
| status    | boolean                        | 是   | 应用的端云协同开关信息。true为打开该应用端云开关，false为关闭该应用端云开关。 |
| callback  | AsyncCallback&lt;void&gt;       | 是   | 回调函数。                   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                             |
| -------- | ---------------------------------------------------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.|
| 202      | Permission verification failed, application which is not a system application uses system API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|
| 801      | Capability not supported.|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let account: string = 'test_id';
let bundleName: string = 'test_bundleName';
try {
  cloudData.Config.changeAppCloudSwitch(account, bundleName, true, (err: BusinessError) => {
    if (err === undefined) {
      console.info('Succeeded in changing App cloud switch');
    } else {
      console.error(`Failed to change App cloud switch. Code: ${err.code}, message: ${err.message}`);
    }
  });
} catch (e) {
  let error = e as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### changeAppCloudSwitch

static changeAppCloudSwitch(accountId: string, bundleName: string, status: boolean): Promise&lt;void&gt;

修改单个应用端云协同开关，使用Promise异步回调。

**需要权限**：ohos.permission.CLOUDDATA_CONFIG

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Config

**参数：**

| 参数名    | 类型                            | 必填 | 说明                         |
| --------- | ------------------------------- | ---- | ---------------------------- |
| accountId | string                          | 是   | 具体打开的云账号ID。 |
| bundleName| string                         | 是   | 应用名。 |
| status    | boolean                        | 是   | 应用的端云协同开关信息。true为打开该应用端云开关，false为关闭该应用端云开关。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                             |
| -------- | ---------------------------------------------------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.|
| 202      | Permission verification failed, application which is not a system application uses system API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|
| 801      | Capability not supported.|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let account: string = 'test_id';
let bundleName: string = 'test_bundleName';
try {
  cloudData.Config.changeAppCloudSwitch(account, bundleName, true).then(() => {
    console.info('Succeeded in changing App cloud switch');
  }).catch((err: BusinessError) => {
    console.error(`Failed to change App cloud switch. Code is ${err.code}, message is ${err.message}`);
  });
} catch (e) {
  let error = e as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### notifyDataChange

static notifyDataChange(accountId: string, bundleName: string, callback: AsyncCallback&lt;void&gt;): void

通知云端的数据变更，使用callback异步回调。

**需要权限**：ohos.permission.CLOUDDATA_CONFIG

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名     | 类型                      | 必填 | 说明                 |
| ---------- | ------------------------- | ---- | -------------------- |
| accountId  | string                    | 是   | 具体打开的云账号ID。 |
| bundleName | string                    | 是   | 应用名。             |
| callback   | AsyncCallback&lt;void&gt; | 是   | 回调函数。           |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                             |
| -------- | ---------------------------------------------------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.|
| 202      | Permission verification failed, application which is not a system application uses system API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|
| 801      | Capability not supported.|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let account: string = 'test_id';
let bundleName: string = 'test_bundleName';
try {
  cloudData.Config.notifyDataChange(account, bundleName, (err: BusinessError) => {
    if (err === undefined) {
      console.info('Succeeded in notifying the change of data');
    } else {
      console.error(`Failed to notify the change of data. Code: ${err.code}, message: ${err.message}`);
    }
  });
} catch (e) {
  let error = e as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### notifyDataChange

static notifyDataChange(accountId: string,bundleName: string): Promise&lt;void&gt;

通知云端的数据变更，使用Promise异步回调。

**需要权限**：ohos.permission.CLOUDDATA_CONFIG

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名     | 类型   | 必填 | 说明                 |
| ---------- | ------ | ---- | -------------------- |
| accountId  | string | 是   | 具体打开的云账号ID。 |
| bundleName | string | 是   | 应用名。             |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                             |
| -------- | ---------------------------------------------------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.|
| 202      | Permission verification failed, application which is not a system application uses system API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|
| 801      | Capability not supported.|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let account: string = 'test_id';
let bundleName: string = 'test_bundleName';
try {
  cloudData.Config.notifyDataChange(account, bundleName).then(() => {
    console.info('Succeeded in notifying the change of data');
  }).catch((err: BusinessError) => {
    console.error(`Failed to notify the change of data. Code: ${err.code}, message: ${err.message}`);
  });
} catch (e) {
  let error = e as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### notifyDataChange<sup>11+</sup>

 static notifyDataChange(extInfo: ExtraData, callback: AsyncCallback&lt;void&gt;):void

通知云端的数据变更，可以通过extInfo中的extraData字段指定变更的数据库名和表名，使用callback异步回调。

**需要权限**：ohos.permission.CLOUDDATA_CONFIG

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Config

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                    |
| -------- | ------------------------- | ---- | --------------------------------------- |
| extInfo  | [ExtraData](#extradata11)   | 是   | 透传数据，包含通知数据变更后的应用信息。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。当数据变更通知成功，err为undefined，否则为错误对象。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                             |
| -------- | ---------------------------------------------------- |
| 201      | Permission verification failed, which is usually returned by VerifyAccessToken.|
| 202      | Permission verification failed, application which is not a system application uses system API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|
| 801      | Capability not supported.|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let eventId: string = "cloud_data_change";
let extraData: string = '{"data":"{"accountId":"aaa","bundleName":"com.bbb.xxx","containerName":"alias", "databaseScopes": ["private", "shared"],"recordTypes":"["xxx","yyy","zzz"]"}"}';
try {
  cloudData.Config.notifyDataChange({
    eventId: eventId, extraData: extraData
  }, (err: BusinessError) => {
    if (err === undefined) {
      console.info('Succeeded in notifying the change of data');
    } else {
      console.error(`Failed to notify the change of data. Code: ${err.code}, message: ${err.message}`);
    }
  });
} catch (e) {
  let error = e as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### notifyDataChange<sup>11+</sup>

static notifyDataChange(extInfo: ExtraData, userId: number,callback: AsyncCallback&lt;void&gt;):void

通知云端的数据变更，可以通过extInfo中的extraData字段指定变更的数据库名和表名，可通过userId指定用户ID，使用callback异步回调。

**需要权限**：ohos.permission.CLOUDDATA_CONFIG

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Config

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                            |
| -------- | ------------------------- | ---- | ----------------------------------------------- |
| extInfo  | [ExtraData](#extradata11)   | 是   | 透传数据，包含通知数据变更后的应用信息。        |
| userId   | number                    | 是   | 用户ID。对应为系统中现有的用户ID。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。当数据变更通知成功，err为undefined，否则为错误对象。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                             |
| -------- | ---------------------------------------------------- |
| 201      | Permission verification failed, which is usually returned by VerifyAccessToken.|
| 202      | Permission verification failed, application which is not a system application uses system API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|
| 801      | Capability not supported.|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let eventId: string = "cloud_data_change";
let extraData: string = '{"data":"{"accountId":"aaa","bundleName":"com.bbb.xxx","containerName":"alias", "databaseScopes": ["private", "shared"],"recordTypes":"["xxx","yyy","zzz"]"}"}';
let userId: number = 100;
try {
  cloudData.Config.notifyDataChange({
    eventId: eventId, extraData: extraData
  }, userId, (err: BusinessError) => {
    if (err === undefined) {
      console.info('Succeeded in notifying the change of data');
    } else {
      console.error(`Failed to notify the change of data. Code: ${err.code}, message: ${err.message}`);
    }
  });
} catch (e) {
  let error = e as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### notifyDataChange<sup>11+</sup>

static notifyDataChange(extInfo: ExtraData, userId?: number): Promise&lt;void&gt;

通知云端的数据变更，可以通过extInfo中的extraData字段指定变更的数据库名和表名，可通过userId指定用户ID，使用Promise异步回调。

**需要权限**：ohos.permission.CLOUDDATA_CONFIG

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Config

**参数：**

| 参数名  | 类型                    | 必填 | 说明                                            |
| ------- | ----------------------- | ---- | ----------------------------------------------- |
| extInfo | [ExtraData](#extradata11) | 是   | 透传数据 包含通知数据变更后的应用信息。         |
| userId  | number                  | 否   | 表示用户ID。此参数是可选的，默认值是当前用户ID，如果指定了此参数，则该值必须是系统中现有的用户ID。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                             |
| -------- | ---------------------------------------------------- |
| 201      | Permission verification failed, which is usually returned by VerifyAccessToken.|
| 202      | Permission verification failed, application which is not a system application uses system API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|
| 801      | Capability not supported.|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let eventId: string = "cloud_data_change";
let extraData: string = '{"data":"{"accountId":"aaa","bundleName":"com.bbb.xxx","containerName":"alias", "databaseScopes": ["private", "shared"],"recordTypes":"["xxx","yyy","zzz"]"}"}';
let userId: number = 100;
try {
  cloudData.Config.notifyDataChange({
    eventId: eventId, extraData: extraData
  }, userId).then(() => {
    console.info('Succeeded in notifying the change of data');
  }).catch((err: BusinessError) => {
    console.error(`Failed to notify the change of data. Code: ${err.code}, message: ${err.message}`);
  });
} catch (e) {
  let error = e as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### queryStatistics<sup>12+</sup>

static queryStatistics(accountId: string, bundleName: string, storeId?: string): Promise&lt;Record&lt;string, Array&lt;StatisticInfo&gt;&gt;&gt;

查询端云统计信息，返回未同步、已同步且端云信息一致和已同步且端云信息不一致的统计信息，使用Promise异步回调。

**需要权限**：ohos.permission.CLOUDDATA_CONFIG

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Config

**参数：**

| 参数名  | 类型      | 必填 | 说明                                |
| ------- |---------| ---- |-----------------------------------|
| accountId | string  | 是   | 具体打开的云账号ID。                       |
| bundleName | string  | 是   | 应用包名。                             |
| storeId  | string  | 否   | 数据库名称。默认值为空字符串，此时将查询当前应用所有的本地数据库。 |

**返回值：**

| 类型                                                                                   | 说明                     |
|--------------------------------------------------------------------------------------| ------------------------ |
| Promise&lt;Record&lt;string, Array&lt;[StatisticInfo](#statisticinfo12)&gt;&gt;&gt; | 返回表名以及统计信息结果集。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                             |
| -------- | ---------------------------------------------------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.|
| 202      | Permission verification failed, application which is not a system application uses system API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|
| 801      | Capability not supported.|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const accountId:string = "accountId";
const bundleName:string = "bundleName";
const storeId:string = "storeId";

cloudData.Config.queryStatistics(accountId, bundleName, storeId).then((result) => {
    console.info(`Succeeded in querying statistics. Info is ${JSON.stringify(result)}`);
}).catch((err: BusinessError) => {
    console.error(`Failed to query statistics. Error code is ${err.code}, message is ${err.message}`);
});
```

### queryLastSyncInfo<sup>12+</sup>

static queryLastSyncInfo(accountId: string, bundleName: string, storeId?: string): Promise&lt;Record<string, SyncInfo>>

查询上一次端云同步信息，使用Promise异步回调。

**需要权限**：ohos.permission.CLOUDDATA_CONFIG

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Config

**参数：**

| 参数名     | 类型   | 必填 | 说明                                                         |
| ---------- | ------ | ---- | ------------------------------------------------------------ |
| accountId  | string | 是   | 具体打开的云账号ID。                                         |
| bundleName | string | 是   | 应用包名。                                                   |
| storeId    | string | 否   | 数据库名称。默认值为空字符串，此时查询当前应用下所有数据库上一次端云同步信息。 |

**返回值：**

| 类型                                                         | 说明                                         |
| ------------------------------------------------------------ | -------------------------------------------- |
| Promise&lt;Record&lt;string, [SyncInfo](#syncinfo12)&gt;&gt; | 返回数据库名以及上一次端云同步的信息结果集。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                             |
| -------- | ---------------------------------------------------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.|
| 202      | Permission verification failed, application which is not a system application uses system API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|
| 801      | Capability not supported.|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const accountId:string = "accountId";
const bundleName:string = "bundleName";
const storeId:string = "storeId";
try {
    cloudData.Config.queryLastSyncInfo(accountId, bundleName, storeId).then((result) => {
    	console.info(`Succeeded in querying last syncinfo. Info is ${JSON.stringify(result)}`);
	}).catch((err: BusinessError) => {
    	console.error(`Failed to query last syncinfo. Error code is ${err.code}, message is ${err.message}`);
	});
} catch(e) {
    let error = e as BusinessError;
  	console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### setGlobalCloudStrategy<sup>12+</sup>

static setGlobalCloudStrategy(strategy: StrategyType, param?: Array&lt;commonType.ValueType&gt;): Promise&lt;void&gt;

设置全局云同步策略，使用Promise异步回调。

**需要权限**：ohos.permission.CLOUDDATA_CONFIG

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Config

**参数：**

| 参数名     | 类型                                                                     | 必填 | 说明                |
| ---------- |------------------------------------------------------------------------| ---- |-------------------|
| strategy  | [StrategyType](js-apis-data-cloudData.md#strategytype)    | 是   | 配置的策略类型。          |
| param | Array&lt;[commonType.ValueType](js-apis-data-commonType.md#valuetype)&gt; | 否   | 策略参数。不填写默认为空，默认取消所有配置。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                             |
| -------- | ---------------------------------------------------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.|
| 202      | Permission verification failed, application which is not a system application uses system API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|
| 801      | Capability not supported.|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

cloudData.Config.setGlobalCloudStrategy(cloudData.StrategyType.NETWORK, [cloudData.NetWorkStrategy.WIFI]).then(() => {
    console.info('Succeeded in setting the global cloud strategy');
}).catch((err: BusinessError) => {
    console.error(`Failed to set global cloud strategy. Code: ${err.code}, message: ${err.message}`);
});
```

###  clear

static clear(accountId: string, appActions: Record<string, ClearAction>,  callback: AsyncCallback&lt;void&gt;): void

清除本地下载的云端数据，使用callback异步回调。

**需要权限**：ohos.permission.CLOUDDATA_CONFIG

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Config

**参数：**

| 参数名     | 类型                                                | 必填 | 说明                             |
| ---------- | --------------------------------------------------- | ---- | -------------------------------- |
| accountId  | string                                              | 是   | 具体打开的云账号ID。             |
| appActions | Record<string, [ClearAction](#clearaction)>         | 是   | 要清除数据的应用信息及清除规则。 |
| callback   | AsyncCallback&lt;void&gt;                           | 是   | 回调函数。                       |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                             |
| -------- | ---------------------------------------------------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.|
| 202      | Permission verification failed, application which is not a system application uses system API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|
| 801      | Capability not supported.|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let account: string = "test_id";
type dataType = Record<string, cloudData.ClearAction>
let appActions: dataType = {
  'test_bundleName1': cloudData.ClearAction.CLEAR_CLOUD_INFO,
  'test_bundleName2': cloudData.ClearAction.CLEAR_CLOUD_DATA_AND_INFO
};
try {
  cloudData.Config.clear(account, appActions, (err: BusinessError) => {
    if (err === undefined) {
      console.info('Succeeding in clearing cloud data');
    } else {
      console.error(`Failed to clear cloud data. Code: ${err.code}, message: ${err.message}`);
    }
  });
} catch (e) {
  let error = e as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### clear

static clear(accountId: string, appActions: Record<string, ClearAction>): Promise&lt;void&gt;

清除本地下载的云端数据，使用Promise异步回调。

**需要权限**：ohos.permission.CLOUDDATA_CONFIG

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Config

**参数：**

| 参数名     | 类型                                                | 必填 | 说明                             |
| ---------- | --------------------------------------------------- | ---- | -------------------------------- |
| accountId  | string                                              | 是   | 具体打开的云账号ID。             |
| appActions | Record<string, [ClearAction](#clearaction)>         | 是   | 要清除数据的应用信息及清除规则。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                             |
| -------- | ---------------------------------------------------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.|
| 202      | Permission verification failed, application which is not a system application uses system API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|
| 801      | Capability not supported.|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let account: string = "test_id";
type dataType = Record<string, cloudData.ClearAction>;
let appActions: dataType = {
  'test_bundleName1': cloudData.ClearAction.CLEAR_CLOUD_INFO,
  'test_bundleName2': cloudData.ClearAction.CLEAR_CLOUD_DATA_AND_INFO
};
try {
  cloudData.Config.clear(account, appActions).then(() => {
    console.info('Succeeding in clearing cloud data');
  }).catch((err: BusinessError) => {
    console.error(`Failed to clear cloud data. Code: ${err.code}, message: ${err.message}`);
  });
} catch (e) {
  let error = e as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

## sharing<sup>11+</sup>

提供端云共享的方法，包括发起共享、取消共享、退出共享、更改共享数据权限、查找共享参与者、确认邀请、更改已确认的邀请、查找共享资源。

### Role<sup>11+</sup>

端云共享参与者的角色。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Client

| 名称           | 值   | 说明                               |
| --------------| ---- | ---------------------------------- |
| ROLE_INVITER  | 0    | 端云共享邀请者。请使用枚举名称而非枚举值。 |
| ROLE_INVITEE  | 1    | 端云共享被邀请者。请使用枚举名称而非枚举值。 |

### State<sup>11+</sup>

端云共享状态。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Client

| 名称           | 值   | 说明                               |
| --------------| ---- | ---------------------------------- |
| STATE_UNKNOWN    | 0    | 未知状态。请使用枚举名称而非枚举值。   |
| STATE_ACCEPTED   | 1    | 端云共享已接受。请使用枚举名称而非枚举值。 |
| STATE_REJECTED   | 2    | 端云共享被拒绝。请使用枚举名称而非枚举值。 |
| STATE_SUSPENDED  | 3    | 端云共享被暂时挂起，未作处理。请使用枚举名称而非枚举值。 |
| STATE_UNAVAILABLE<sup>12+</sup>   | 4    | 端云共享不可用。请使用枚举名称而非枚举值。 |

### SharingCode<sup>11+</sup>

端云共享错误码。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Client

| 名称           | 值   | 说明                               |
| --------------| ---- | ---------------------------------- |
| SUCCESS                 | 0    | 成功。请使用枚举名称而非枚举值。   |
| REPEATED_REQUEST        | 1    | 重复邀请，表示当前参与者已被邀请。请使用枚举名称而非枚举值。 |
| NOT_INVITER             | 2    | 非端云共享的邀请者，表示当前参与者不是端云共享的邀请者。请使用枚举名称而非枚举值。 |
| NOT_INVITER_OR_INVITEE  | 3    | 非法参与者，表示当前参与者既不是共享的邀请者，也不是共享的被邀请者。请使用枚举名称而非枚举值。 |
| OVER_QUOTA              | 4    | 端云共享次数达到上限，表示当前账号可共享的次数达到上限。请使用枚举名称而非枚举值。   |
| TOO_MANY_PARTICIPANTS   | 5    | 端云共享参与者数量达到上限。请使用枚举名称而非枚举值。 |
| INVALID_ARGS            | 6    | 无效的参数。请使用枚举名称而非枚举值。 |
| NETWORK_ERROR           | 7    | 网络错误。请使用枚举名称而非枚举值。 |
| CLOUD_DISABLED          | 8    | 云开关未打开。请使用枚举名称而非枚举值。   |
| SERVER_ERROR            | 9    | 服务端发生错误。请使用枚举名称而非枚举值。 |
| INNER_ERROR             | 10   | 系统发生内部错误。请使用枚举名称而非枚举值。 |
| INVALID_INVITATION      | 11   | 无效的邀请，表示当前邀请已失效或不存在。请使用枚举名称而非枚举值。 |
| RATE_LIMIT              | 12   | 速率限制，表示单次同步的数据量达到上限。请使用枚举名称而非枚举值。   |
| CUSTOM_ERROR            | 1000 | 定制错误，小于该枚举值的错误码用于定义系统内部的标准错误码，大于该枚举值的错误码用于使用者自定义错误码。请使用枚举名称而非枚举值。 |

### Result&lt;T&gt;<sup>11+</sup>

端云共享结果的返回值。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Client

| 名称          | 类型                          | 必填  | 说明           |
| ----------- | --------------------------- | --- | ------------ |
| code        | number                      | 是   | 错误码。       |
| description | string                      | 否   | 错误码详细描述，默认为undefined。       |
| value       | T                           | 否   | 返回结果的值，具体类型由参数T指定，默认为undefined。 |

### Privilege<sup>11+</sup>

指定的端云共享数据的权限。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Client

| 名称          | 类型                          | 必填  | 说明           |
| ----------- | --------------------------- | --- | ------------ |
| writable    | boolean              | 否   | 被共享者是否可修改共享的数据。true表示可修改，false表示不可修改，默认不可修改。   |
| readable    | boolean              | 否   | 被共享者是否可读取共享的数据。true表示可读取，false表示不可读取，默认不可读取。   |
| creatable   | boolean              | 否   | 被共享者是否可创建新的共享数据。true表示可创建，false表示不可创建，默认不可创建。  |
| deletable   | boolean              | 否   | 被共享者是否可删除共享的数据。true表示可删除，false表示不可删除，默认不可删除。  |
| shareable   | boolean              | 否   | 被共享者是否可将共享的数据再次共享给其他参与者。true表示可再次共享，false表示不可再次共享，默认不可再次共享。  |

### Participant<sup>11+</sup>

端云共享的参与者。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Client

| 名称          | 类型                          | 必填  | 说明           |
| ----------- | --------------------------- | --- | ------------ |
| identity    | string                  | 是   | 参与者的ID。              |
| role        | [Role](#role11)           | 否   | 参与者的角色，为邀请者或被邀请者。默认为undefined。  |
| state       | [State](#state11)         | 否   | 共享的状态。默认为undefined。 |
| privilege   | [Privilege](#privilege11) | 否   | 指定的共享数据权限。默认为[Privilege](#privilege11)的默认值。 |
| attachInfo  | string                  | 否   | 附加信息，用于拓展额外的参与者信息。如用于参与者身份校验的校验码等，默认为空字符串。 |

### allocResourceAndShare<sup>11+</sup>

allocResourceAndShare(storeId: string, predicates: relationalStore.RdbPredicates, participants: Array&lt;Participant&gt;, columns?: Array&lt;string&gt;): Promise&lt;relationalStore.ResultSet&gt;

根据谓词条件匹配的数据申请共享资源标识并发起共享，返回已共享资源的结果集。如果指定了列字段，则返回的结果集中同时包含对应列的字段值，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Client

**参数：**

| 参数名    | 类型                            | 必填 | 说明                         |
| --------- | ------------------------------- | ---- | ---------------------------- |
| storeId      | string                        | 是   | 数据库名称。 |
| predicates   | [relationalStore.RdbPredicates](js-apis-data-relationalStore.md#rdbpredicates) | 是   | 表示查找共享资源标识的数据的谓词条件。 |
| participants | Array&lt;[Participant](#participant11)&gt; | 是   | 端云共享的参与者。 |
| columns      | Array&lt;string&gt;           | 否   | 表示要查找的列字段名。默认为undefined，不返回列字段。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;[relationalStore.ResultSet](js-apis-data-relationalStore.md#resultset)&gt; | Promise对象，返回查询并共享的共享资源标识结果集。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                             |
| -------- | ---------------------------------------------------- |
| 202      | Permission verification failed, application which is not a system application uses system API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|
| 801      | Capability not supported.|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { relationalStore } from '@kit.ArkData';

let participants = new Array<cloudData.sharing.Participant>();
participants.push({
  identity: '000000000',
  role: cloudData.sharing.Role.ROLE_INVITER,
  state: cloudData.sharing.State.STATE_UNKNOWN,
  privilege: {
    writable: true,
    readable: true,
    creatable: false,
    deletable: false,
    shareable: false
  },
  attachInfo: ''
})
let sharingResource: string;
let predicates = new relationalStore.RdbPredicates('test_table');
predicates.equalTo('data', 'data_test');
cloudData.sharing.allocResourceAndShare('storeName', predicates, participants, ['uuid', 'data']).then((resultSet) => {
  if (!resultSet.goToFirstRow()) {
    console.error(`row error`);
    return;
  }
  const res = resultSet.getString(resultSet.getColumnIndex(relationalStore.Field.SHARING_RESOURCE_FIELD));
  console.info(`sharing resource: ${res}`);
  sharingResource = res;
}).catch((err: BusinessError) => {
  console.error(`alloc resource and share failed, code is ${err.code},message is ${err.message}`);
})

```

### allocResourceAndShare<sup>11+</sup>

allocResourceAndShare(storeId: string, predicates: relationalStore.RdbPredicates, participants: Array&lt;Participant&gt;, columns: Array&lt;string&gt;, callback: AsyncCallback&lt;relationalStore.ResultSet&gt;): void

根据谓词条件匹配的数据申请共享资源标识并发起共享，返回已共享资源的结果集。并根据指定的列字段，返回的结果集中同时包含对应列的字段值，使用callback异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Client

**参数：**

| 参数名    | 类型                            | 必填 | 说明                         |
| --------- | ------------------------------- | ---- | ---------------------------- |
| storeId      | string                        | 是   | 数据库名称。 |
| predicates   | [relationalStore.RdbPredicates](js-apis-data-relationalStore.md#rdbpredicates) | 是   | 表示查找共享资源标识的数据的谓词条件。 |
| participants | Array&lt;[Participant](#participant11)&gt; | 是   | 端云共享的参与者。 |
| columns      | Array&lt;string&gt;           | 是   | 表示要查找的列字段名。 |
| callback     | AsyncCallback&lt;[relationalStore.ResultSet](js-apis-data-relationalStore.md#resultset)&gt;  | 是  | 回调函数。 返回查询并共享的共享资源标识结果集。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                             |
| -------- | ---------------------------------------------------- |
| 202      | Permission verification failed, application which is not a system application uses system API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|
| 801      | Capability not supported.|

**示例：**

```ts
import { relationalStore } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

let participants = new Array<cloudData.sharing.Participant>();
participants.push({
  identity: '000000000',
  role: cloudData.sharing.Role.ROLE_INVITER,
  state: cloudData.sharing.State.STATE_UNKNOWN,
  privilege: {
    writable: true,
    readable: true,
    creatable: false,
    deletable: false,
    shareable: false
  },
  attachInfo: ''
})
let sharingResource: string;
let predicates = new relationalStore.RdbPredicates('test_table');
predicates.equalTo('data', 'data_test');
cloudData.sharing.allocResourceAndShare('storeName', predicates, participants, ['uuid', 'data'], (err: BusinessError, resultSet) => {
  if (err) {
    console.error(`alloc resource and share failed, code is ${err.code},message is ${err.message}`);
    return;
  }
  if (!resultSet.goToFirstRow()) {
    console.error(`row error`);
    return;
  }
  const res = resultSet.getString(resultSet.getColumnIndex(relationalStore.Field.SHARING_RESOURCE_FIELD));
  console.info(`sharing resource: ${res}`);
  sharingResource = res;
})

```

### allocResourceAndShare<sup>11+</sup>

allocResourceAndShare(storeId: string, predicates: relationalStore.RdbPredicates, participants: Array&lt;Participant&gt;, callback: AsyncCallback&lt;relationalStore.ResultSet&gt;): void

根据谓词条件匹配的数据申请共享资源标识并发起共享，返回已共享资源的结果集，使用callback异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Client

**参数：**

| 参数名    | 类型                            | 必填 | 说明                         |
| --------- | ------------------------------- | ---- | ---------------------------- |
| storeId      | string                        | 是   | 数据库名称。 |
| predicates   | [relationalStore.RdbPredicates](js-apis-data-relationalStore.md#rdbpredicates) | 是   | 表示查找共享资源标识的数据的谓词条件。 |
| participants | Array&lt;[Participant](#participant11)&gt; | 是   | 端云共享的参与者。 |
| callback     | AsyncCallback&lt;[relationalStore.ResultSet](js-apis-data-relationalStore.md#resultset)&gt;  | 是   | 回调函数。返回查询并共享的共享资源标识结果集。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                             |
| -------- | ---------------------------------------------------- |
| 202      | Permission verification failed, application which is not a system application uses system API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|
| 801      | Capability not supported.|

**示例：**

```ts
import { relationalStore } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

let participants = new Array<cloudData.sharing.Participant>();
participants.push({
  identity: '000000000',
  role: cloudData.sharing.Role.ROLE_INVITER,
  state: cloudData.sharing.State.STATE_UNKNOWN,
  privilege: {
    writable: true,
    readable: true,
    creatable: false,
    deletable: false,
    shareable: false
  },
  attachInfo: ''
})
let sharingResource: string;
let predicates = new relationalStore.RdbPredicates('test_table');
predicates.equalTo('data', 'data_test');
cloudData.sharing.allocResourceAndShare('storeName', predicates, participants, (err: BusinessError, resultSet) => {
  if (err) {
    console.error(`alloc resource and share failed, code is ${err.code},message is ${err.message}`);
    return;
  }
  if (!resultSet.goToFirstRow()) {
    console.error(`row error`);
    return;
  }
  const res = resultSet.getString(resultSet.getColumnIndex(relationalStore.Field.SHARING_RESOURCE_FIELD));
  console.info(`sharing resource: ${res}`);
  sharingResource = res;
})

```

### share<sup>11+</sup>

share(sharingResource: string, participants: Array&lt;Participant&gt;): Promise&lt;Result&lt;Array&lt;Result&lt;Participant&gt;&gt;&gt;&gt;

根据指定的共享资源标识和共享参与者发起共享邀请，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Client

**参数：**

| 参数名    | 类型                            | 必填 | 说明                         |
| --------- | ------------------------------- | ---- | ---------------------------- |
| sharingResource   | string                                     | 是   | 端云共享数据的资源标识。 |
| participants      | Array&lt;[Participant](#participant11)&gt;   | 是   | 端云共享的参与者。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;[Result](#resultt11)&lt;Array&lt;[Result](#resultt11)&lt;[Participant](#participant11)&gt;&gt;&gt;&gt; | Promise对象，返回端云共享的结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                             |
| -------- | ---------------------------------------------------- |
| 202      | Permission verification failed, application which is not a system application uses system API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|
| 801      | Capability not supported.|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let participants = new Array<cloudData.sharing.Participant>();
participants.push({
  identity: '000000000',
  role: cloudData.sharing.Role.ROLE_INVITER,
  state: cloudData.sharing.State.STATE_UNKNOWN,
  privilege: {
    writable: true,
    readable: true,
    creatable: false,
    deletable: false,
    shareable: false
  },
  attachInfo: ''
})
cloudData.sharing.share('sharing_resource_test', participants).then((result) => {
  console.info(`share success, result: ${result}`);
}).catch((err: BusinessError) => {
  console.error(`share failed, code is ${err.code},message is ${err.message}`);
})

```

### share<sup>11+</sup>

share(sharingResource: string, participants: Array&lt;Participant&gt;, callback: AsyncCallback&lt;Result&lt;Array&lt;Result&lt;Participant&gt;&gt;&gt;&gt;): void

根据指定的共享资源标识和共享参与者发起共享邀请，使用callback异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Client

**参数：**

| 参数名    | 类型                            | 必填 | 说明                         |
| --------- | ------------------------------- | ---- | ---------------------------- |
| sharingResource  | string                                     | 是   | 端云共享数据的资源标识。 |
| participants     | Array&lt;[Participant](#participant11)&gt; | 是   | 端云共享的参与者。 |
| callback         | AsyncCallback&lt;[Result](#resultt11)&lt;Array&lt;[Result](#resultt11)&lt;[Participant](#participant11)&gt;&gt;&gt;&gt;  | 是   | 回调函数。返回端云共享的结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                             |
| -------- | ---------------------------------------------------- |
| 202      | Permission verification failed, application which is not a system application uses system API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|
| 801      | Capability not supported.|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let participants = new Array<cloudData.sharing.Participant>();
participants.push({
  identity: '000000000',
  role: cloudData.sharing.Role.ROLE_INVITER,
  state: cloudData.sharing.State.STATE_UNKNOWN,
  privilege: {
    writable: true,
    readable: true,
    creatable: false,
    deletable: false,
    shareable: false
  },
  attachInfo: ''
})
cloudData.sharing.share('sharing_resource_test', participants, ((err: BusinessError, result) => {
  if (err) {
    console.error(`share failed, code is ${err.code},message is ${err.message}`);
    return;
  }
  console.info(`share succeeded, result: ${result}`);
}))

```

### unshare<sup>11+</sup>

unshare(sharingResource: string, participants: Array&lt;Participant&gt;): Promise&lt;Result&lt;Array&lt;Result&lt;Participant&gt;&gt;&gt;&gt;

根据指定的共享资源标识和共享参与者取消共享，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Client

**参数：**

| 参数名    | 类型                            | 必填 | 说明                         |
| --------- | ------------------------------- | ---- | ---------------------------- |
| sharingResource   | string                                     | 是   | 端云共享数据的资源标识。 |
| participants      | Array&lt;[Participant](#participant11)&gt; | 是   | 端云共享的参与者。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;[Result](#resultt11)&lt;Array&lt;[Result](#resultt11)&lt;[Participant](#participant11)&gt;&gt;&gt;&gt; | Promise对象，返回取消共享的结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                             |
| -------- | ---------------------------------------------------- |
| 202      | Permission verification failed, application which is not a system application uses system API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|
| 801      | Capability not supported.|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let participants = new Array<cloudData.sharing.Participant>();
participants.push({
  identity: '000000000',
  role: cloudData.sharing.Role.ROLE_INVITER,
  state: cloudData.sharing.State.STATE_UNKNOWN,
  privilege: {
    writable: true,
    readable: true,
    creatable: false,
    deletable: false,
    shareable: false
  },
  attachInfo: ''
})
cloudData.sharing.unshare('sharing_resource_test', participants).then((result) => {
  console.info(`unshare succeeded, result: ${result}`);
}).catch((err: BusinessError) => {
  console.error(`unshare failed, code is ${err.code},message is ${err.message}`);
})

```

### unshare<sup>11+</sup>

unshare(sharingResource: string, participants: Array&lt;Participant&gt;, callback: AsyncCallback&lt;Result&lt;Array&lt;Result&lt;Participant&gt;&gt;&gt;&gt;): void

根据指定的共享资源标识和共享参与者取消共享，使用callback异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Client

**参数：**

| 参数名    | 类型                            | 必填 | 说明                         |
| --------- | ------------------------------- | ---- | ---------------------------- |
| sharingResource  | string                                     | 是   | 共享数据的资源标志。 |
| participants     | Array&lt;[Participant](#participant11)&gt; | 是   | 共享参与者。 |
| callback         | AsyncCallback&lt;[Result](#resultt11)&lt;Array&lt;[Result](#resultt11)&lt;[Participant](#participant11)&gt;&gt;&gt;&gt;  | 是   | 回调函数。返回取消共享的结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                             |
| -------- | ---------------------------------------------------- |
| 202      | Permission verification failed, application which is not a system application uses system API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|
| 801      | Capability not supported.|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let participants = new Array<cloudData.sharing.Participant>();
participants.push({
  identity: '000000000',
  role: cloudData.sharing.Role.ROLE_INVITER,
  state: cloudData.sharing.State.STATE_UNKNOWN,
  privilege: {
    writable: true,
    readable: true,
    creatable: false,
    deletable: false,
    shareable: false
  },
  attachInfo: ''
})
cloudData.sharing.unshare('sharing_resource_test', participants, ((err: BusinessError, result) => {
  if (err) {
    console.error(`unshare failed, code is ${err.code},message is ${err.message}`);
    return;
  }
  console.info(`unshare succeeded, result: ${result}`);
}))

```

### exit<sup>11+</sup>

exit(sharingResource: string): Promise&lt;Result&lt;void&gt;&gt;

根据指定的共享资源标识退出共享，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Client

**参数：**

| 参数名    | 类型                            | 必填 | 说明                         |
| --------- | ------------------------------- | ---- | ---------------------------- |
| sharingResource   | string       | 是   | 端云共享数据的资源标识。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;[Result](#resultt11)&lt;void&gt;&gt; | Promise对象，返回退出端云共享的结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                             |
| -------- | ---------------------------------------------------- |
| 202      | Permission verification failed, application which is not a system application uses system API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|
| 801      | Capability not supported.|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

cloudData.sharing.exit('sharing_resource_test').then((result) => {
  console.info(`exit share success, result: ${result}`);
}).catch((err: BusinessError) => {
  console.error(`exit share failed, code is ${err.code},message is ${err.message}`);
})

```

### exit<sup>11+</sup>

exit(sharingResource: string, callback: AsyncCallback&lt;Result&lt;void&gt;&gt;): void

根据指定的共享资源标识退出共享，使用callback异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Client

**参数：**

| 参数名    | 类型                            | 必填 | 说明                         |
| --------- | ------------------------------- | ---- | ---------------------------- |
| sharingResource  | string                | 是   | 端云共享数据的资源标识。 |
| callback         | AsyncCallback&lt;[Result](#resultt11)&lt;void&gt;&gt;  | 是   | 回调函数。返回退出共享的结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                             |
| -------- | ---------------------------------------------------- |
| 202      | Permission verification failed, application which is not a system application uses system API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|
| 801      | Capability not supported.|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

cloudData.sharing.exit('sharing_resource_test', ((err: BusinessError, result) => {
  if (err) {
    console.error(`exit share failed, code is ${err.code},message is ${err.message}`);
    return;
  }
  console.info(`exit share succeeded, result: ${result}`);
}))

```

### changePrivilege<sup>11+</sup>

changePrivilege(sharingResource: string, participants: Array&lt;Participant&gt;): Promise&lt;Result&lt;Array&lt;Result&lt;Participant&gt;&gt;&gt;&gt;

根据指定的共享资源标识更改共享参与者对共享数据的操作权限，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Client

**参数：**

| 参数名    | 类型                            | 必填 | 说明                         |
| --------- | ------------------------------- | ---- | ---------------------------- |
| sharingResource   | string                                    | 是   | 端云共享数据的资源标识。 |
| participants      | Array&lt;[Participant](#participant11)&gt;  | 是   | 端云共享的参与者。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;[Result](#resultt11)&lt;Array&lt;[Result](#resultt11)&lt;[Participant](#participant11)&gt;&gt;&gt;&gt; | Promise对象，返回更改共享参与者权限的结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                             |
| -------- | ---------------------------------------------------- |
| 202      | Permission verification failed, application which is not a system application uses system API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|
| 801      | Capability not supported.|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let participants = new Array<cloudData.sharing.Participant>();
participants.push({
  identity: '000000000',
  role: cloudData.sharing.Role.ROLE_INVITER,
  state: cloudData.sharing.State.STATE_UNKNOWN,
  privilege: {
    writable: true,
    readable: true,
    creatable: false,
    deletable: false,
    shareable: false
  },
  attachInfo: ''
})

cloudData.sharing.changePrivilege('sharing_resource_test', participants).then((result) => {
  console.info(`change privilege succeeded, result: ${result}`);
}).catch((err: BusinessError) => {
  console.error(`change privilege failed, code is ${err.code},message is ${err.message}`);
})

```

### changePrivilege<sup>11+</sup>

changePrivilege(sharingResource: string, participants: Array&lt;Participant&gt;, callback: AsyncCallback&lt;Result&lt;Array&lt;Result&lt;Participant&gt;&gt;&gt;&gt;): void

根据指定的共享资源标识更改共享参与者对共享数据的操作权限，使用callback异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Client

**参数：**

| 参数名    | 类型                            | 必填 | 说明                         |
| --------- | ------------------------------- | ---- | ---------------------------- |
| sharingResource  | string                | 是   | 端云共享数据的资源标识。 |
| participants     | Array&lt;[Participant](#participant11)&gt;  | 是   | 端云共享的参与者。 |
| callback         | callback: AsyncCallback&lt;[Result](#resultt11)&lt;Array&lt;[Result](#resultt11)&lt;[Participant](#participant11)&gt;&gt;&gt;&gt;  | 是   | 回调函数。返回更改权限的结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                             |
| -------- | ---------------------------------------------------- |
| 202      | Permission verification failed, application which is not a system application uses system API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|
| 801      | Capability not supported.|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let participants = new Array<cloudData.sharing.Participant>();
participants.push({
  identity: '000000000',
  role: cloudData.sharing.Role.ROLE_INVITER,
  state: cloudData.sharing.State.STATE_UNKNOWN,
  privilege: {
    writable: true,
    readable: true,
    creatable: false,
    deletable: false,
    shareable: false
  },
  attachInfo: ''
})

cloudData.sharing.changePrivilege('sharing_resource_test', participants, ((err: BusinessError, result) => {
  if (err) {
    console.error(`change privilege failed, code is ${err.code},message is ${err.message}`);
    return;
  }
  console.info(`change privilege succeeded, result: ${result}`);
}))

```

### queryParticipants<sup>11+</sup>

queryParticipants(sharingResource: string): Promise&lt;Result&lt;Array&lt;Participant&gt;&gt;&gt;

根据指定的共享资源标识查询当前共享的参与者，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Client

**参数：**

| 参数名    | 类型                            | 必填 | 说明                         |
| --------- | ------------------------------- | ---- | ---------------------------- |
| sharingResource   | string                 | 是   | 端云共享数据的资源标识。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;[Result](#resultt11)&lt;Array&lt;[Participant](#participant11)&gt;&gt;&gt; | Promise对象，返回查询共享参与者的结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                             |
| -------- | ---------------------------------------------------- |
| 202      | Permission verification failed, application which is not a system application uses system API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|
| 801      | Capability not supported.|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

cloudData.sharing.queryParticipants('sharing_resource_test').then((result) => {
  console.info(`query participants succeeded, result: ${result}`);
}).catch((err: BusinessError) => {
  console.error(`query participants failed, code is ${err.code},message is ${err.message}`);
})

```

### queryParticipants<sup>11+</sup>

queryParticipants(sharingResource: string, callback: AsyncCallback&lt;Result&lt;Array&lt;Participant&gt;&gt;&gt;): void

根据指定的共享资源标识查询当前共享的参与者，使用callback异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Client

**参数：**

| 参数名    | 类型                            | 必填 | 说明                         |
| --------- | ------------------------------- | ---- | ---------------------------- |
| sharingResource  | string                | 是   | 端云共享数据的资源标识。 |
| callback         | AsyncCallback&lt;[Result](#resultt11)&lt;Array&lt;[Participant](#participant11)&gt;&gt;&gt;  | 是   | 回调函数。返回查找共享参与者的结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                             |
| -------- | ---------------------------------------------------- |
| 202      | Permission verification failed, application which is not a system application uses system API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|
| 801      | Capability not supported.|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

cloudData.sharing.queryParticipants('sharing_resource_test', ((err: BusinessError, result) => {
  if (err) {
    console.error(`query participants failed, code is ${err.code},message is ${err.message}`);
    return;
  }
  console.info(`query participants succeeded, result: ${result}`);
}))

```

### queryParticipantsByInvitation<sup>11+</sup>

queryParticipantsByInvitation(invitationCode: string): Promise&lt;Result&lt;Array&lt;Participant&gt;&gt;&gt;

根据指定的共享邀请码查询当前共享的参与者，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Client

**参数：**

| 参数名    | 类型                            | 必填 | 说明                         |
| --------- | ------------------------------- | ---- | ---------------------------- |
| invitationCode   | string                 | 是   | 端云共享的邀请码。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;[Result](#resultt11)&lt;Array&lt;[Participant](#participant11)&gt;&gt;&gt; | Promise对象，返回查找共享参与者的结果。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                             |
| -------- | ---------------------------------------------------- |
| 202      | Permission verification failed, application which is not a system application uses system API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|
| 801      | Capability not supported.|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

cloudData.sharing.queryParticipantsByInvitation('sharing_invitation_code_test').then((result) => {
  console.info(`query participants by invitation succeeded, result: ${result}`);
}).catch((err: BusinessError) => {
  console.error(`query participants by invitation failed, code is ${err.code},message is ${err.message}`);
})

```

### queryParticipantsByInvitation<sup>11+</sup>

queryParticipantsByInvitation(invitationCode: string, callback: AsyncCallback&lt;Result&lt;Array&lt;Participant&gt;&gt;&gt;): void

根据指定的共享邀请码查询当前共享的参与者，使用callback异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Client

**参数：**

| 参数名    | 类型                            | 必填 | 说明                         |
| --------- | ------------------------------- | ---- | ---------------------------- |
| invitationCode  | string                | 是   | 端云共享的邀请码。 |
| callback        | AsyncCallback&lt;[Result](#resultt11)&lt;Array&lt;[Participant](#participant11)&gt;&gt;&gt; | 是   | 回调函数。返回查找共享参与者的结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                             |
| -------- | ---------------------------------------------------- |
| 202      | Permission verification failed, application which is not a system application uses system API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|
| 801      | Capability not supported.|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

cloudData.sharing.queryParticipantsByInvitation('sharing_invitation_code_test', ((err: BusinessError, result) => {
  if (err) {
    console.error(`query participants by invitation failed, code is ${err.code},message is ${err.message}`);
    return;
  }
  console.info(`query participants by invitation succeeded, result: ${result}`);
}))

```

### confirmInvitation<sup>11+</sup>

confirmInvitation(invitationCode: string, state: State): Promise&lt;Result&lt;string&gt;&gt;

被邀请者根据共享邀请码确认当前邀请，并获取当前邀请的共享资源标识，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Client

**参数：**

| 参数名    | 类型                            | 必填 | 说明                         |
| --------- | ------------------------------- | ---- | ---------------------------- |
| invitationCode   | string                 | 是   | 端云共享的邀请码。 |
| state            | [State](#state11)        | 是   | 确认邀请的状态。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;[Result](#resultt11)&lt;string&gt;&gt; | Promise对象，返回确认共享邀请的结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                             |
| -------- | ---------------------------------------------------- |
| 202      | Permission verification failed, application which is not a system application uses system API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|
| 801      | Capability not supported.|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let shareResource: string | undefined;
cloudData.sharing.confirmInvitation('sharing_invitation_code_test', cloudData.sharing.State.STATE_ACCEPTED).then((result: cloudData.sharing.Result<string>) => {
  console.info(`confirm invitation succeeded, result: ${result}`);
  shareResource = result.value;
}).catch((err: BusinessError) => {
  console.error(`confirm invitation failed, code is ${err.code},message is ${err.message}`);
})

```

### confirmInvitation<sup>11+</sup>

confirmInvitation(invitationCode: string, state: State, callback: AsyncCallback&lt;Result&lt;string&gt;&gt;): void

被邀请者根据共享邀请码确认当前邀请，并获取当前邀请的共享资源标识，使用callback异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Client

**参数：**

| 参数名    | 类型                            | 必填 | 说明                         |
| --------- | ------------------------------- | ---- | ---------------------------- |
| invitationCode  | string                | 是   | 端云共享的邀请码。 |
| state           | [State](#state11)       | 是   | 确认邀请的状态。 |
| callback        | AsyncCallback&lt;[Result](#resultt11)&lt;string&gt;&gt; | 是   | 回调函数。返回确认邀请的结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                             |
| -------- | ---------------------------------------------------- |
| 202      | Permission verification failed, application which is not a system application uses system API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|
| 801      | Capability not supported.|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let shareResource: string;
cloudData.sharing.confirmInvitation('sharing_invitation_code_test', cloudData.sharing.State.STATE_ACCEPTED, ((err: BusinessError, result) => {
  if (err) {
    console.error(`confirm invitation failed, code is ${err.code},message is ${err.message}`);
    return;
  }
  console.info(`confirm invitation succeeded, result: ${result}`);
  shareResource = result.value;
}))

```

### changeConfirmation<sup>11+</sup>

changeConfirmation(sharingResource: string, state: State): Promise&lt;Result&lt;void&gt;&gt;

根据共享资源标识更改共享邀请的状态，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Client

**参数：**

| 参数名    | 类型                            | 必填 | 说明                         |
| --------- | ------------------------------- | ---- | ---------------------------- |
| sharingResource   | string                 | 是   | 端云共享数据的资源标识。 |
| state             | [State](#state11)        | 是   | 更改邀请的状态。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;[Result](#resultt11)&lt;void&gt;&gt; |  Promise对象，返回更改共享邀请状态的结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                             |
| -------- | ---------------------------------------------------- |
| 202      | Permission verification failed, application which is not a system application uses system API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|
| 801      | Capability not supported.|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

cloudData.sharing.changeConfirmation('sharing_resource_test', cloudData.sharing.State.STATE_REJECTED).then((result) => {
  console.info(`change confirmation succeeded, result: ${result}`);
}).catch((err: BusinessError) => {
  console.error(`change confirmation failed, code is ${err.code},message is ${err.message}`);
})

```

### changeConfirmation<sup>11+</sup>

changeConfirmation(sharingResource: string, state: State, callback: AsyncCallback&lt;Result&lt;void&gt;&gt;): void;

根据共享资源标识更改共享邀请的状态，使用callback异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Client

**参数：**

| 参数名    | 类型                            | 必填 | 说明                         |
| --------- | ------------------------------- | ---- | ---------------------------- |
| sharingResource   | string                 | 是   | 端云共享数据的资源标识。 |
| state             | [State](#state11)        | 是   | 更改邀请的状态。 |
| callback          | AsyncCallback&lt;[Result](#resultt11)&lt;void&gt;&gt; | 是   | 回调函数。返回更改邀请状态的结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                             |
| -------- | ---------------------------------------------------- |
| 202      | Permission verification failed, application which is not a system application uses system API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|
| 801      | Capability not supported.|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

cloudData.sharing.changeConfirmation('sharing_resource_test', cloudData.sharing.State.STATE_REJECTED, ((err: BusinessError, result) => {
  if (err) {
    console.error(`change confirmation failed, code is ${err.code},message is ${err.message}`);
    return;
  }
  console.info(`change confirmation succeeded, result: ${result}`);
}))

```
<!--no_check-->
