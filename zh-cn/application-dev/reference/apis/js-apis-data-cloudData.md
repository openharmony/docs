# @ohos.data.cloudData (端云协同)

端云协同提供结构化数据（RDB Store）端云同步的能力。即：云作为数据的中心节点，通过与云的数据同步，实现数据云备份、同帐号设备间的数据一致性。

该模块提供以下端云协同相关的常用功能：

- [Config](#config)：提供配置端云协同的方法，包括云同步打开、关闭、清理数据、数据变化通知。

> **说明：** 
>
> - 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本模块接口为系统接口。

## 导入模块

```ts
import cloudData from '@ohos.data.cloudData';
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
| eventId   | string | 是   | 如果传值为"cloud_data_change"，表示云数据变更。                                             |
| extraData | string | 是   | 由push服务透传过来，"header"中是云侧校验应用所需的信息，"data"中是通知变更所需要的信息，包含账号，应用名，数据库名和数据库表名，其中accountId和bundleName不能为空串 |

**示例：**

```mandatory
ExtraData {
    eventId:"cloud_data_change",
    extraData:"{
        "header":{ 
            "token":"bbbbbb"  //用于校验应用信息
        }
        "data":{
            "accountId": "aaa",  //用户打开的云帐号ID。
            "bundleName": "com.bbb.xxx",  //应用名。
            "containerName": "alias",  //云上的数据库名称
            "recordTypes":  [ //数据库表名
                "xxx", 
                "yyy", 
                "zzz",
            ]
        }
    }"
}
```

## Config

提供配置端云协同的方法，包括云同步打开、关闭、清理数据、数据变化通知。

### enableCloud

static enableCloud(accountId: string, switches: { [bundleName: string]: boolean }, callback: AsyncCallback&lt;void&gt;): void

打开端云协同，使用callback异步回调。

**需要权限**：ohos.permission.CLOUDDATA_CONFIG

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Config

**参数：**

| 参数名    | 类型                            | 必填 | 说明                                                         |
| --------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| accountId | string                          | 是   | 具体打开的云帐号ID。                                         |
| switches  | {[bundleName: string]: boolean} | 是   | 各应用的端云协同开关信息，true为打开该应用端云开关，false为关闭该应用端云开关。 |
| callback  | AsyncCallback&lt;void&gt;       | 是   | 回调函数。                                                   |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let account = 'test_id';
let switches: Record<string, boolean> = { 'test_bundleName1': true, 'test_bundleName2': false };
try {
  cloudData.Config.enableCloud(account, switches, (err) => {
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

static enableCloud(accountId: string, switches: { [bundleName: string]: boolean }): Promise&lt;void&gt;

打开端云协同，使用Promise异步回调。

**需要权限**：ohos.permission.CLOUDDATA_CONFIG

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Config

**参数：**

| 参数名    | 类型                            | 必填 | 说明                                                         |
| --------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| accountId | string                          | 是   | 具体打开的云帐号ID。                                         |
| switches  | {[bundleName: string]: boolean} | 是   | 各应用的端云协同开关信息，true为打开该应用端云开关，false为关闭该应用端云开关。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let account = 'test_id';
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
| accountId | string                    | 是   | 具体打开的云帐号ID。 |
| callback  | AsyncCallback&lt;void&gt; | 是   | 回调函数。           |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let account = 'test_id';
try {
  cloudData.Config.disableCloud(account, (err) => {
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
| accountId | string | 是   | 具体打开的云帐号ID。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let account = 'test_id';
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
| accountId | string                          | 是   | 具体打开的云帐号ID。 |
| bundleName| string                         | 是   | 应用名。 |
| status    | boolean                        | 是   | 应用的端云协同开关信息，true为打开该应用端云开关，false为关闭该应用端云开关。 |
| callback  | AsyncCallback&lt;void&gt;       | 是   | 回调函数。                   |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let account = 'test_id';
let bundleName = 'test_bundleName';
try {
  cloudData.Config.changeAppCloudSwitch(account, bundleName, true, (err) => {
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
| accountId | string                          | 是   | 具体打开的云帐号ID。 |
| bundleName| string                         | 是   | 应用名。 |
| status    | boolean                        | 是   | 应用的端云协同开关信息，true为打开该应用端云开关，false为关闭该应用端云开关。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let account = 'test_id';
let bundleName = 'test_bundleName';
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
| accountId  | string                    | 是   | 具体打开的云帐号ID。 |
| bundleName | string                    | 是   | 应用名。             |
| callback   | AsyncCallback&lt;void&gt; | 是   | 回调函数。           |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let account = 'test_id';
let bundleName = 'test_bundleName';
try {
  cloudData.Config.notifyDataChange(account, bundleName, (err) => {
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
| accountId  | string | 是   | 具体打开的云帐号ID。 |
| bundleName | string | 是   | 应用名。             |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let account = 'test_id';
let bundleName = 'test_bundleName';
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

 **static** notifyDataChange(extInfo: ExtraData, callback: AsyncCallback&lt;void&gt;):void

通知云端的数据变更，由push服务直接调用，使用callback异步回调。

**需要权限**：ohos.permission.CLOUDDATA_CONFIG

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Config

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                    |
| -------- | ------------------------- | ---- | --------------------------------------- |
| extInfo  | [ExtraData](#extradata11)   | 是   | 透传数据，包含通知数据变更后的应用信息。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。                              |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let eventId = "cloud_data_change";
let extraData= {"header ":"aaaa","data ":"{\"accountId\":\"2850086000356238647\",\"bundleName\":\"com.huawei.hmos.notepad\",\"containerName\":\"alias\",\"recordTypes\":\"[\\\"xxx\\\",\\\"yyy\\\"]\"}"}
let extraData = header+data;
try {
  cloudData.Config.notifyDataChange({ eventId:eventId ,extraData:extraData}, (err) => {
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

通知云端的数据变更，由push服务直接调用，使用callback异步回调。

**需要权限**：ohos.permission.CLOUDDATA_CONFIG

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Config

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                            |
| -------- | ------------------------- | ---- | ----------------------------------------------- |
| extInfo  | [ExtraData](#extradata11)   | 是   | 透传数据 包含通知数据变更后的应用信息。         |
| userId   | number                    | 否   | 表示用户ID。此参数是可选的。取值范围是100-102。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。                                      |

```ts
import { BusinessError } from '@ohos.base';

let eventId = cloudData.DATA_CHANGE_EVENT_ID;
let header = "aaaa";
let data = "{\"accountId\":\"2850086000356238647\",\"bundleName\":\"com.huawei.hmos.notepad\",\"containerName\":\"alias\",\"recordTypes\":\"[\\\"xxx\\\",\\\"yyy\\\"]\"}"
let extraData = header+data;
let userId = 100;
try {
  cloudData.Config.notifyDataChange({ eventId:eventId ,extraData:extraData},userId, (err) => {
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

**static** notifyDataChange(extInfo: ExtraData, userId?: number): Promise&lt;void&gt;

通知云端的数据变更，由push服务直接调用，使用Promise异步回调。

**需要权限**：ohos.permission.CLOUDDATA_CONFIG

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Config

**参数：**

| 参数名  | 类型                    | 必填 | 说明                                            |
| ------- | ----------------------- | ---- | ----------------------------------------------- |
| extInfo | [ExtraData](#extradata11) | 是   | 透传数据 包含通知数据变更后的应用信息。         |
| userId  | number                  | 否   | 表示用户ID。此参数是可选的。取值范围是100-102。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let eventId = cloudData.DATA_CHANGE_EVENT_ID;
let header = "aaaa";
let data = "{\"accountId\":\"2850086000356238647\",\"bundleName\":\"com.huawei.hmos.notepad\",\"containerName\":\"alias\",\"recordTypes\":\"[\\\"xxx\\\",\\\"yyy\\\"]\"}"
let extraData = header+data;
let userId = 100;
try {
  cloudData.Config.notifyDataChange({ eventId:eventId ,extraData:extraData},userId).then(() => {
    console.info('Succeeded in notifying the change of data');
  }).catch((err: BusinessError) => {
    console.error(`Failed to notify the change of data. Code: ${err.code}, message: ${err.message}`);
  });
} catch (e) {
  let error = e as BusinessError;
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

###  clear

static clear(accountId: string, appActions: { [bundleName: string]: ClearAction },  callback: AsyncCallback&lt;void&gt;): void

清除本地下载的云端数据，使用callback异步回调。

**需要权限**：ohos.permission.CLOUDDATA_CONFIG

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Config

**参数：**

| 参数名     | 类型                                                | 必填 | 说明                             |
| ---------- | --------------------------------------------------- | ---- | -------------------------------- |
| accountId  | string                                              | 是   | 具体打开的云帐号ID。             |
| appActions | {[bundleName: string]: [ClearAction](#clearaction)} | 是   | 要清除数据的应用信息及清除规则。 |
| callback   | AsyncCallback&lt;void&gt;                           | 是   | 回调函数。                       |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let account = "test_id";
type dataType = Record<string, cloudData.ClearAction>
let appActions: dataType = {
  'test_bundleName1': cloudData.ClearAction.CLEAR_CLOUD_INFO,
  'test_bundleName2': cloudData.ClearAction.CLEAR_CLOUD_DATA_AND_INFO
};
try {
  cloudData.Config.clear(account, appActions, (err) => {
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

static clear(accountId: string, appActions: { [bundleName: string]: ClearAction }): Promise&lt;void&gt;

清除本地下载的云端数据，使用Promise异步回调。

**需要权限**：ohos.permission.CLOUDDATA_CONFIG

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Config

**参数：**

| 参数名     | 类型                                                | 必填 | 说明                             |
| ---------- | --------------------------------------------------- | ---- | -------------------------------- |
| accountId  | string                                              | 是   | 具体打开的云帐号ID。             |
| appActions | {[bundleName: string]: [ClearAction](#clearaction)} | 是   | 要清除数据的应用信息及清除规则。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let account = "test_id";
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
