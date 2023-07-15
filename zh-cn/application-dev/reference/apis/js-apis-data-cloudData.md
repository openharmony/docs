# @ohos.data.cloudData (端云协同)

端云协同提供结构化数据（RDB Store）端云同步的能力。即：云作为数据的中心节点，通过与云的数据同步，实现数据云备份、同帐号设备间的数据一致性。

该模块提供以下端云协同相关的常用功能：

- [Config](#config)：提供配置端云协同的方法，包括云同步打开、关闭、清理数据、数据变化通知。

> **说明：** 
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import cloudData from '@ohos.data.cloudData';
```

##   Action

清除本地下载的云端数据的行为枚举。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Config

| 名称      | 说明                         |
| --------- | ---------------------------- |
| CLEAR_CLOUD_INFO | 清除从云端下载的数据的云标识，相关数据作为本地数据保存。 |
| CLEAR_CLOUD_DATA_AND_INFO |清除从云端下载的数据，不包括本地已修改的云端数据。   |

## Config

提供配置端云协同的方法，包括云同步打开、关闭、清理数据、数据变化通知。

### enableCloud

static enableCloud(accountId: string, switches: {[bundleName: string]: boolean}, callback: AsyncCallback&lt;void&gt;):void

打开端云协同，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.CLOUDDATA_CONFIG

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Config

**参数：**

| 参数名    | 类型                            | 必填 | 说明                                                         |
| --------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| accountId | string                          | 是   | 具体打开的云帐号ID。                                         |
| switches  | {[bundleName: string]: boolean} | 是   | 各应用的端云协同开关信息，true为打开该应用端云开关，false为关闭该应用端云开关。 |
| callback  | AsyncCallback&lt;void&gt;       | 是   | 回调函数。                                                   |

**示例：**

```js
let account = 'test_id';
let switches = { 'test_bundleName1': true, 'test_bundleName2': false };
try {
    cloudData.Config.enableCloud(account, switches, function (err) {
        if (err === undefined) {
            console.info('Succeeded in enabling cloud');
        } else {
            console.error(`Failed to enable.Code: ${err.code}, message: ${err.message}`);
        }
    });
} catch (error) {
    console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### enableCloud

static enableCloud(accountId: string, switches: {[bundleName: string]: boolean}): Promise&lt;void&gt;

打开端云协同，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

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

```js
let account = 'test_id';
let switches = { 'test_bundleName1': true, 'test_bundleName2': false };
try {
    cloudData.Config.enableCloud(account, switches).then(() => {
        console.info('Succeeded in enabling cloud');
    }).catch((err) => {
        console.error(`Failed to enable.Code: ${err.code}, message: ${err.message}`);
    });
} catch (error) {
    console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### disableCloud

static disableCloud(accountId: string, callback: AsyncCallback&lt;void&gt;):void

关闭端云协同，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.CLOUDDATA_CONFIG

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Config

**参数：**

| 参数名    | 类型                      | 必填 | 说明                 |
| --------- | ------------------------- | ---- | -------------------- |
| accountId | string                    | 是   | 具体打开的云帐号ID。 |
| callback  | AsyncCallback&lt;void&gt; | 是   | 回调函数。           |

**示例：**

```js
let account = 'test_id';
try {
    cloudData.Config.disableCloud(account, function (err) {
        if (err === undefined) {
            console.info('Succeeded in disabling cloud');
        } else {
            console.error(`Failed to disableCloud. Code: ${err.code}, message: ${err.message}`);
        }
    });
} catch (error) {
    console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### disableCloud

static disableCloud(accountId: string): Promise&lt;void&gt;

关闭端云协同，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

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

```js
let account = 'test_id';
try {
    cloudData.Config.disableCloud(account).then(() => {
        console.info('Succeeded in disabling cloud');
    }).catch((err) => {
        console.error(`Failed to disableCloud. Code: ${err.code}, message: ${err.message}`);
    });
} catch (error) {
    console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### changeAppCloudSwitch

static changeAppCloudSwitch(accountId: string,bundleName:string,status:boolean, callback: AsyncCallback&lt;void&gt;):void

修改单个应用端云协同开关，使用callback异步回调。

**系统接口：** 此接口为系统接口。

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

```js
let account = 'test_id';
let bundleName = 'test_bundleName';
try {
    cloudData.Config.changeAppCloudSwitch(account, bundleName, true, function (err) {
        if (err === undefined) {
            console.info('Succeeded in changing App cloud switch');
        } else {
            console.error(`Failed to change App cloud switch. Code: ${err.code}, message: ${err.message}`);
        }
    });
} catch (error) {
    console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### changeAppCloudSwitch

static changeAppCloudSwitch(accountId: string,bundleName:string,status:boolean): Promise&lt;void&gt;

修改单个应用端云协同开关，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

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

```js
let account = 'test_id';
let bundleName = 'test_bundleName';
try {
    cloudData.Config.changeAppCloudSwitch(account, bundleName, true).then(() => {
        console.info('Succeeded in changing App cloud switch');
    }).catch((err) => {
        console.error(`Failed to change App cloud switch. Code is ${err.code}, message is ${err.message}`);
    });
} catch (error) {
    console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### notifyDataChange

static notifyDataChange(accountId: string,bundleName:string, callback: AsyncCallback&lt;void&gt;):void

通知云端的数据变更，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.CLOUDDATA_CONFIG

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Server

**参数：**

| 参数名     | 类型                      | 必填 | 说明                 |
| ---------- | ------------------------- | ---- | -------------------- |
| accountId  | string                    | 是   | 具体打开的云帐号ID。 |
| bundleName | string                    | 是   | 应用名。             |
| callback   | AsyncCallback&lt;void&gt; | 是   | 回调函数。           |

**示例：**

```js
let account = 'test_id';
let bundleName = 'test_bundleName';
try {
    cloudData.Config.notifyDataChange(account, bundleName, function (err) {
        if (err === undefined) {
            console.info('Succeeded in notifying the change of data');
        } else {
            console.error(`Failed to notify the change of data. Code: ${err.code}, message: ${err.message}`);
        }
    });
} catch (error) {
    console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### notifyDataChange

static notifyDataChange(accountId: string,bundleName:string): Promise&lt;void&gt;

通知云端的数据变更，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

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

```js
let account = 'test_id';
let bundleName = 'test_bundleName';
try {
    cloudData.Config.notifyDataChange(account, bundleName).then(() => {
        console.info('Succeeded in notifying the change of data');
    }).catch((err) => {
        console.error(`Failed to notify the change of data. Code: ${err.code}, message: ${err.message}`);
    });
} catch (error) {
    console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

###  clean

static clean(accountId: string, appActions: {[bundleName: string]: Action},  callback: AsyncCallback&lt;void&gt;):void

清除本地下载的云端数据，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.CLOUDDATA_CONFIG

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Config

**参数：**

| 参数名     | 类型                                      | 必填 | 说明                             |
| ---------- | ----------------------------------------- | ---- | -------------------------------- |
| accountId  | string                                    | 是   | 具体打开的云帐号ID。             |
| appActions | {[bundleName: string]: [Action](#action)} | 是   | 要清除数据的应用信息及清除规则。 |
| callback   | AsyncCallback&lt;void&gt;                 | 是   | 回调函数。                       |

**示例：**

```js
let action = cloudData.Action;
let account = "test_id";
let bundleName1 = "test_bundleName1";
let bundleName2 = "test_bundleName2";
let appActions = { [bundleName1]: action.CLEAR_CLOUD_INFO, [bundleName2]: action.CLEAR_CLOUD_DATA_AND_INFO };
try {
  cloudData.Config.clean(account, appActions, function (err) {
    if (err === undefined) {
      console.info('Succeeding in cleaning cloud data');
    } else {
      console.error(`Failed to clean cloud data. Code: ${err.code}, message: ${err.message}`);
    }
  });
} catch (error) {
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

### clean

static clean(accountId: string, appActions: {[bundleName: string]: Action}): Promise&lt;void&gt;

清除本地下载的云端数据，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.CLOUDDATA_CONFIG

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Config

**参数：**

| 参数名     | 类型                                      | 必填 | 说明                             |
| ---------- | ----------------------------------------- | ---- | -------------------------------- |
| accountId  | string                                    | 是   | 具体打开的云帐号ID。             |
| appActions | {[bundleName: string]: [Action](#action)} | 是   | 要清除数据的应用信息及清除规则。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```js
let action = cloudData.Action;
let account = "test_id";
let bundleName1 = "test_bundleName1";
let bundleName2 = "test_bundleName2";
let appActions = { [bundleName1]: action.CLEAR_CLOUD_INFO, [bundleName2]: action.CLEAR_CLOUD_DATA_AND_INFO };
try {
  cloudData.Config.clean(account, appActions).then(() => {
    console.info('Succeeding in cleaning cloud data');
  }).catch((err) => {
    console.error(`Failed to clean cloud data. Code: ${err.code}, message: ${err.message}`);
  });
} catch (error) {
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```
