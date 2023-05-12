# @ohos.data.cloudData (端云协同)

端云协同提供结构化数据（RDB Store)端云同步的能力。即：云作为数据的中心节点，通过与云的数据同步，实现数据云备份、同账号设备间的数据一致性。

该模块提供以下端云协同相关的常用功能：

- [Config](#config)：提供配置端云协同信息的相关方法，包括云同步打开、关闭、清理数据、账号状态变更处理。

> **说明：** 
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import ddm from '@ohos.data.cloudData';
```

##   Action

清除本地数据云信息的行为枚举。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Config

| 名称      | 说明                         |
| --------- | ---------------------------- |
| CLEAR_CLOUD_INFO | 清除仅云相关，保留本地缓存数据，包括：纯云端的元数据、有本地文件云相关数据。 |
| CLEAR_CLOUD_DATA_AND_INFO |清除所有云相关文件数据，已同步云端的文件数据。   |

## Config

提供配置端云协同信息的相关方法，包括云同步打开、关闭、清理数据、账号状态变更处理。

### enableCloud

static enableCloud(accountId: string, switches: {[bundleName: string]: boolean}, callback: AsyncCallback&lt;void&gt;):&lt;void&gt;

打开端云协同，使用callback异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Config

**参数：**

| 参数名    | 类型                            | 必填 | 说明                         |
| --------- | ------------------------------- | ---- | ---------------------------- |
| accountId | string                          | 是   | 具体打开的云信息hash后的ID。 |
| switches  | {[bundleName: string]: boolean} | 是   | 各应用的端云协同开关信息。   |
| callback  | AsyncCallback&lt;void&gt;       | 是   | 回调函数。                   |

**示例：**

```js
let account = "test_id";
let switches = {"test_bundleName1":true, "test_bundleName2":false};
try {
  await ddm.Config.enableCloud(account, function (err, data) {
    if (err == undefined) {
      console.info('Succeeding in enabling cloud');
    } else {
      console.error('Failed to enable' + `, error code is ${err.code}, message is ${err.message}`);
    }
    done();
  });
} catch (e) {
  console.error('An unexpected error occurred.' + `, error code is ${e.code}, message is ${e.message}`);
}
```

### enableCloud

static enableCloud(accountId: string, switches: {[bundleName: string]: boolean}): Promise&lt;void&gt;

打开端云协同，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Config

**参数：**

| 参数名    | 类型                            | 必填 | 说明                         |
| --------- | ------------------------------- | ---- | ---------------------------- |
| accountId | string                          | 是   | 具体打开的云信息hash后的ID。 |
| switches  | {[bundleName: string]: boolean} | 是   | 各应用的端云协同开关信息。   |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```js
let account = "test_id";
let switches = {"test_bundleName1":true, "test_bundleName2":false};
try {
  await  ddm.Config.enableCloud(account).then((data) => {
      console.info('Succeeding in enabling cloud');
  }).catch((error) => {
      console.error('Failed to enable' + `, error code is ${error.code}, message is ${error.message}`);
  });
} catch (e) {
  console.error('An unexpected error occurred.' + `, error code is ${e.code}, message is ${e.message}`);
}
```

### disableCloud

static disableCloud(accountId: string, callback: AsyncCallback&lt;void&gt;):&lt;void&gt;

关闭端云协同，使用callback异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Config

**参数：**

| 参数名    | 类型                      | 必填 | 说明                         |
| --------- | ------------------------- | ---- | ---------------------------- |
| accountId | string                    | 是   | 具体打开的云信息hash后的ID。 |
| callback  | AsyncCallback&lt;void&gt; | 是   | 回调函数。                   |

**示例：**

```js
let account = "test_id";
try {
  await ddm.Config.disableCloud(account, function (err, data) {
    if (err == undefined) {
      console.info('Succeeding in disabling cloud');
    } else {
      console.error('Failed to disableCloud' + `, error code is ${err.code}, message is ${err.message}`);
    }
    done();
  });
} catch (e) {
  console.error('An unexpected error occurred.' + `, error code is ${e.code}, message is ${e.message}`);
}
```

### disableCloud

static disableCloud(accountId: string): Promise&lt;void&gt;

关闭端云协同，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Config

**参数：**

| 参数名    | 类型   | 必填 | 说明                         |
| --------- | ------ | ---- | ---------------------------- |
| accountId | string | 是   | 具体打开的云信息hash后的ID。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```js
let account = "test_id";
let switches = {"test_bundleName1":true, "test_bundleName2":false};
try {
  await  ddm.Config.disableCloud(account).then((data) => {
      console.info('Succeeding in disabling cloud');
  }).catch((error) => {
      console.error('Failed to disableCloud' + `, error code is ${error.code}, message is ${error.message}`);
  });
} catch (e) {
  console.error('An unexpected error occurred.' + `, error code is ${e.code}, message is ${e.message}`);
}
```

### changeAppCloudSwitch

static changeAppCloudSwitch(accountId: string,bundleName:string,status:boolean, callback: AsyncCallback&lt;void&gt;):&lt;void&gt;

修改单个应用端云协同开关，使用callback异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Config

**参数：**

| 参数名    | 类型                            | 必填 | 说明                         |
| --------- | ------------------------------- | ---- | ---------------------------- |
| accountId | string                          | 是   | 具体打开的云信息hash后的ID。 |
| bundleName| string                         | 是   | 应用名 |
| status    | boolean                        | 是   | 应用的端云协同开关状态信息。 |
| callback  | AsyncCallback&lt;void&gt;       | 是   | 回调函数。                   |

**示例：**

```js
let account = "test_id";
let bundleName = "test_bundleName";
try {
  await ddm.Config.changeAppCloudSwitch(account, bundleName, true, function (err, data) {
    if (err == undefined) {
      console.info('Succeeding in changing App cloud switch');
    } else {
      console.error('Failed to change App cloud switch' + `, error code is ${err.code}, message is ${err.message}`);
    }
    done();
  });
} catch (e) {
  console.error('An unexpected error occurred.' + `, error code is ${e.code}, message is ${e.message}`);
}
```

### changeAppCloudSwitch

static changeAppCloudSwitch(accountId: string,bundleName:string,status:boolean): Promise&lt;void&gt;

修改单个应用端云协同开关，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Config

**参数：**

| 参数名    | 类型                            | 必填 | 说明                         |
| --------- | ------------------------------- | ---- | ---------------------------- |
| accountId | string                          | 是   | 具体打开的云信息hash后的ID。 |
| bundleName| string                         | 是   | 应用名 |
| status    | boolean                        | 是   | 应用的端云协同开关状态信息。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```js
let account = "test_id";
let bundleName = "test_bundleName";
try {
  await  ddm.Config.changeAppCloudSwitch(account, bundleName, true).then((data) => {
      console.info('Succeeding in changing App cloud switch');
  }).catch((error) => {
      console.error('Failed to change App cloud switch' + `, error code is ${error.code}, message is ${error.message}`);
  });
} catch (e) {
  console.error('An unexpected error occurred.' + `, error code is ${e.code}, message is ${e.message}`);
}
```

### clean

static clean(accountId: string, appActions: {[bundleName: string]: Action}, callback: AsyncCallback&lt;void&gt;):&lt;void&gt;

清除本地数据中云信息，使用callback异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Config

**参数：**

| 参数名     | 类型                                      | 必填 | 说明                         |
| ---------- | ----------------------------------------- | ---- | ---------------------------- |
| accountId  | string                                    | 是   | 具体打开的云信息hash后的ID。 |
| appActions | {[bundleName: string]: [Action](#Action)} | 是   | 要清除数据的应用信息         |
| callback   | AsyncCallback&lt;void&gt;                 | 是   | 回调函数。                   |

**示例：**

```js
let account = "test_id";
let appActions = {"test_bundleName1": con.CLEAR_CLOUD_INFO, "test_bundleName2": con.CLEAR_CLOUD_DATA_AND_INFO}
try {
  await ddm.Config.clean(account, appActions, function (err, data) {
    if (err == undefined) {
      console.info('Succeeding in cleaning cloud data');
    } else {
      console.error('Failed to clean' + `, error code is ${err.code}, message is ${err.message}`);
    }
    done();
  });
} catch (e) {
  console.error('An unexpected error occurred.' + `, error code is ${e.code}, message is ${e.message}`);
}
```

### clean

static clean(accountId: string, appActions: {[bundleName: string]: Action}): Promise&lt;void&gt;

清除本地数据中云信息，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Config

**参数：**

| 参数名     | 类型                                      | 必填 | 说明                         |
| ---------- | ----------------------------------------- | ---- | ---------------------------- |
| accountId  | string                                    | 是   | 具体打开的云信息hash后的ID。 |
| appActions | {[bundleName: string]: [Action](#Action)} | 是   | 要清除数据的应用信息         |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```js
let account = "test_id";
let appActions = {"test_bundleName1": con.CLEAR_CLOUD_INFO, "test_bundleName2": con.CLEAR_CLOUD_DATA_AND_INFO}
try {
  await  ddm.Config.clean(account, appActions).then((data) => {
      console.info('Succeeding in cleaning cloud data');
  }).catch((error) => {
      console.error('Failed to clean' + `, error code is ${error.code}, message is ${error.message}`);
  });
} catch (e) {
  console.error('An unexpected error occurred.' + `, error code is ${e.code}, message is ${e.message}`);
}
```

### notifyDataChange

static notifyDataChange(accountId: string,bundleName:string, callback: AsyncCallback&lt;void&gt;):&lt;void&gt;

通知云端的数据变更，使用callback异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Config

**参数：**

| 参数名     | 类型                      | 必填 | 说明                         |
| ---------- | ------------------------- | ---- | ---------------------------- |
| accountId  | string                    | 是   | 具体打开的云信息hash后的ID。 |
| bundleName | string                    | 是   | 应用名                       |
| callback   | AsyncCallback&lt;void&gt; | 是   | 回调函数。                   |

**示例：**

```js
let account = "test_id";
let bundleName = "test_bundleName";
try {
  await ddm.Config.notifyDataChange(account, bundleName, function (err, data) {
    if (err == undefined) {
      console.info('Succeeding in notifying the change of data');
    } else {
      console.error('Failed to notify the change of data' + `, error code is ${err.code}, message is ${err.message}`);
    }
    done();
  });
} catch (e) {
  console.error('An unexpected error occurred.' + `, error code is ${e.code}, message is ${e.message}`);
}
```

### notifyDataChange

static notifyDataChange(accountId: string,bundleName:string): Promise&lt;void&gt;

通知云端的数据变更，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Config

**参数：**

| 参数名     | 类型   | 必填 | 说明                         |
| ---------- | ------ | ---- | ---------------------------- |
| accountId  | string | 是   | 具体打开的云信息hash后的ID。 |
| bundleName | string | 是   | 应用名                       |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```js
let account = "test_id";
let bundleName = "test_bundleName";
try {
  await  ddm.Config.notifyDataChange(account, bundleName).then((data) => {
      console.info('Succeeding in notifying the change of data');
  }).catch((error) => {
      console.error('Failed to notify the change of data' + `, error code is ${error.code}, message is ${error.message}`);
  });
} catch (e) {
  console.error('An unexpected error occurred.' + `, error code is ${e.code}, message is ${e.message}`);
}
```

