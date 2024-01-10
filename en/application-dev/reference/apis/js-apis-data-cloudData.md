# @ohos.data.cloudData (Device-Cloud Synergy)

The **cloudData** module provides the capability of synchronizing the structured data (in RDB stores) between the device and cloud. The cloud serves as the central node of data. The devices synchronize data with the data in the cloud to implement cloud data backup and data consistency between the devices with the same account.

This module provides the following common functions:

- [Config](#config): provides APIs for configuring device-cloud synergy, including enabling and disabling cloud synchronization, clearing data, and notifying data changes.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs provided by this module are system APIs.

## Modules to Import

```ts
import cloudData from '@ohos.data.cloudData';
```

##   ClearAction

Enumerates the actions to take to clear the downloaded cloud data locally.

**System capability**: SystemCapability.DistributedDataManager.CloudSync.Config

| Name     | Description                        |
| --------- | ---------------------------- |
| CLEAR_CLOUD_INFO | Clear only the cloud identifier of the data downloaded from the cloud. The related data is still stored as local data.|
| CLEAR_CLOUD_DATA_AND_INFO |Clear the data downloaded from the cloud, excluding the cloud data that has been modified locally.  |

## Config

Provides APIs for implementing device-cloud synergy, including enabling and disabling device-cloud synchronization, clearing data, and notifying data changes.

### enableCloud

static enableCloud(accountId: string, switches: { [bundleName: string]: boolean }, callback: AsyncCallback&lt;void&gt;): void

Enables device-cloud synergy. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.CLOUDDATA_CONFIG

**System capability**: SystemCapability.DistributedDataManager.CloudSync.Config

**Parameters**

| Name   | Type                           | Mandatory| Description                                                        |
| --------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| accountId | string                          | Yes  | ID of the cloud account.                                        |
| switches  | {[bundleName: string]: boolean} | Yes  | Device-cloud synergy switches for applications. The value **true** means to enable the device-cloud synergy; the value **false** means the opposite.|
| callback  | AsyncCallback&lt;void&gt;       | Yes  | Callback invoked to return the result.                                                  |

**Example**

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

Enables device-cloud synergy. This API uses a promise to return the result.

**Required permissions**: ohos.permission.CLOUDDATA_CONFIG

**System capability**: SystemCapability.DistributedDataManager.CloudSync.Config

**Parameters**

| Name   | Type                           | Mandatory| Description                                                        |
| --------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| accountId | string                          | Yes  | ID of the cloud account.                                        |
| switches  | {[bundleName: string]: boolean} | Yes  | Device-cloud synergy switches for applications. The value **true** means to enable the device-cloud synergy; the value **false** means the opposite.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

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

Disables device-cloud synergy. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.CLOUDDATA_CONFIG

**System capability**: SystemCapability.DistributedDataManager.CloudSync.Config

**Parameters**

| Name   | Type                     | Mandatory| Description                |
| --------- | ------------------------- | ---- | -------------------- |
| accountId | string                    | Yes  | ID of the cloud account.|
| callback  | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result.          |

**Example**

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

Disables device-cloud synergy. This API uses a promise to return the result.

**Required permissions**: ohos.permission.CLOUDDATA_CONFIG

**System capability**: SystemCapability.DistributedDataManager.CloudSync.Config

**Parameters**

| Name   | Type  | Mandatory| Description                |
| --------- | ------ | ---- | -------------------- |
| accountId | string | Yes  | ID of the cloud account.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

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

Changes the device-cloud synergy switch for an application. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.CLOUDDATA_CONFIG

**System capability**: SystemCapability.DistributedDataManager.CloudSync.Config

**Parameters**

| Name   | Type                           | Mandatory| Description                        |
| --------- | ------------------------------- | ---- | ---------------------------- |
| accountId | string                          | Yes  | ID of the cloud account.|
| bundleName| string                         | Yes  | Bundle name of the application.|
| status    | boolean                        | Yes  | Setting of the device-cloud synergy switch for the application. The value **true** means to enable the device-cloud synergy; the value **false** means the opposite.|
| callback  | AsyncCallback&lt;void&gt;       | Yes  | Callback invoked to return the result.                  |

**Example**

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

Changes the device-cloud synergy switch for an application. This API uses a promise to return the result.

**Required permissions**: ohos.permission.CLOUDDATA_CONFIG

**System capability**: SystemCapability.DistributedDataManager.CloudSync.Config

**Parameters**

| Name   | Type                           | Mandatory| Description                        |
| --------- | ------------------------------- | ---- | ---------------------------- |
| accountId | string                          | Yes  | ID of the cloud account.|
| bundleName| string                         | Yes  | Bundle name of the application.|
| status    | boolean                        | Yes  | Setting of the device-cloud synergy switch for the application. The value **true** means to enable the device-cloud synergy; the value **false** means the opposite.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

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

Notifies the data changes in the cloud. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.CLOUDDATA_CONFIG

**System capability**: SystemCapability.DistributedDataManager.CloudSync.Server

**Parameters**

| Name    | Type                     | Mandatory| Description                |
| ---------- | ------------------------- | ---- | -------------------- |
| accountId  | string                    | Yes  | ID of the cloud account.|
| bundleName | string                    | Yes  | Bundle name of the application.            |
| callback   | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result.          |

**Example**

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

Notifies the data changes in the cloud. This API uses a promise to return the result.

**Required permissions**: ohos.permission.CLOUDDATA_CONFIG

**System capability**: SystemCapability.DistributedDataManager.CloudSync.Server

**Parameters**

| Name    | Type  | Mandatory| Description                |
| ---------- | ------ | ---- | -------------------- |
| accountId  | string | Yes  | ID of the cloud account.|
| bundleName | string | Yes  | Bundle name of the application.            |

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

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

###  clear

static clear(accountId: string, appActions: { [bundleName: string]: ClearAction },  callback: AsyncCallback&lt;void&gt;): void

Clears the cloud data locally. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.CLOUDDATA_CONFIG

**System capability**: SystemCapability.DistributedDataManager.CloudSync.Config

**Parameters**

| Name    | Type                                               | Mandatory| Description                            |
| ---------- | --------------------------------------------------- | ---- | -------------------------------- |
| accountId  | string                                              | Yes  | ID of the cloud account.            |
| appActions | {[bundleName: string]: [ClearAction](#clearaction)} | Yes  | Information about the application whose data is to be cleared and the action to take.|
| callback   | AsyncCallback&lt;void&gt;                           | Yes  | Callback invoked to return the result.                      |

**Example**

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

Clears the cloud data locally. This API uses a promise to return the result.

**Required permissions**: ohos.permission.CLOUDDATA_CONFIG

**System capability**: SystemCapability.DistributedDataManager.CloudSync.Config

**Parameters**

| Name    | Type                                               | Mandatory| Description                            |
| ---------- | --------------------------------------------------- | ---- | -------------------------------- |
| accountId  | string                                              | Yes  | ID of the cloud account.            |
| appActions | {[bundleName: string]: [ClearAction](#clearaction)} | Yes  | Information about the application whose data is to be cleared and the action to take.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

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
