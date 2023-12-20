# @ohos.enterprise.networkManager (Network Management)

The **networkManager** module provides APIs for network management of enterprise devices, including obtaining the device IP address and MAC address.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs of this module can be used only in the stage model.
>
> - The APIs provided by this module can be called only by a [device administrator application](enterpriseDeviceManagement-overview.md#basic-concepts) that is [enabled](js-apis-enterprise-adminManager.md#adminmanagerenableadmin).

## Modules to Import

```ts
import networkManager from '@ohos.enterprise.networkManager';
```

## networkManager.getAllNetworkInterfaces

getAllNetworkInterfaces(admin: Want, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Obtains all activated network ports through the specified device administrator application. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_GET_NETWORK_INFO

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)     | Yes   | Device administrator application.                 |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;            | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is an array of network ports obtained. If the operation fails, **err** is an error object.    |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                       |
| 9200002 | The administrator application does not have permission to manage the device.|

**Example**

```ts
import Want from '@ohos.app.ability.Want';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

networkManager.getAllNetworkInterfaces(wantTemp, (err, result) => {
  if (err) {
    console.error(`Failed to get all network interfaces. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info(`Succeeded in getting all network interfaces, result : ${JSON.stringify(result)}`);
});
```

## networkManager.getAllNetworkInterfaces

getAllNetworkInterfaces(admin: Want): Promise&lt;Array&lt;string&gt;&gt;

Obtains all activated network ports through the specified device administrator application. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_GET_NETWORK_INFO

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | Yes   | Device administrator application.|

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return an array of network ports obtained. |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                       |
| 9200002 | The administrator application does not have permission to manage the device.|

**Example**

```ts
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

networkManager.getAllNetworkInterfaces(wantTemp).then((result) => {
  console.info(`Succeeded in getting all network interfaces, result : ${JSON.stringify(result)}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to get all network interfaces. Code: ${err.code}, message: ${err.message}`);
});
```

## networkManager.getIpAddress

getIpAddress(admin: Want, networkInterface: string, callback: AsyncCallback&lt;string&gt;): void

Obtains the device IP address based on the network port through the specified device administrator application. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_GET_NETWORK_INFO

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)     | Yes   | Device administrator application.                 |
| networkInterface    | string     | Yes   | Network port.                 |
| callback | AsyncCallback&lt;string&gt;            | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is the IP address obtained. If the operation fails, **err** is an error object.      |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                       |
| 9200002 | The administrator application does not have permission to manage the device.|

**Example**

```ts
import Want from '@ohos.app.ability.Want';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

networkManager.getIpAddress(wantTemp, 'eth0', (err, result) => {
  if (err) {
    console.error(`Failed to get ip address. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info(`Succeeded in getting ip address, result : ${result}`);
});
```

## networkManager.getIpAddress

getIpAddress(admin: Want, networkInterface: string): Promise&lt;string&gt;

Obtains the device IP address based on the network port through the specified device administrator application. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_GET_NETWORK_INFO

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | Yes   | Device administrator application.|
| networkInterface    | string     | Yes   | Network port.                 |

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;string&gt; | Promise used to return the device IP address obtained. |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                       |
| 9200002 | The administrator application does not have permission to manage the device.|

**Example**

```ts
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

networkManager.getIpAddress(wantTemp, 'eth0').then((result) => {
  console.info(`Succeeded in getting ip address, result : ${result}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to get ip address. Code: ${err.code}, message: ${err.message}`);
});
```

## networkManager.getMac

getMac(admin: Want, networkInterface: string, callback: AsyncCallback&lt;string&gt;): void

Obtains the device MAC address based on the network port through the specified device administrator application. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_GET_NETWORK_INFO

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)      | Yes   | Device administrator application.                 |
| networkInterface    | string     | Yes   | Network port.                 |
| callback | AsyncCallback&lt;string&gt;            | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is the MAC address obtained. If the operation fails, **err** is an error object.      |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                       |
| 9200002 | The administrator application does not have permission to manage the device.|

**Example**

```ts
import Want from '@ohos.app.ability.Want';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

networkManager.getMac(wantTemp, 'eth0', (err, result) => {
  if (err) {
    console.error(`Failed to get mac. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info(`Succeeded in getting mac, result : ${result}`);
});
```

## networkManager.getMac

getMac(admin: Want, networkInterface: string): Promise\<string>

Obtains the device MAC address based on the network port through the specified device administrator application. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_GET_NETWORK_INFO

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | Yes   | Device administrator application.|
| networkInterface    | string     | Yes   | Network port.                 |

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;string&gt; | Promise used to return the device MAC address obtained. |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                       |
| 9200002 | The administrator application does not have permission to manage the device.|

**Example**

```ts
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

networkManager.getMac(wantTemp, 'eth0').then((result) => {
  console.info(`Succeeded in getting mac, result : ${result}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to get mac. Code: ${err.code}, message: ${err.message}`);
});
```

## networkManager.isNetworkInterfaceDisabled

isNetworkInterfaceDisabled(admin: Want, networkInterface: string, callback: AsyncCallback&lt;boolean&gt;): void

Checks whether a network port is disabled through the specified device administrator application. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_GET_NETWORK_INFO

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)      | Yes   | Device administrator application.                 |
| networkInterface    | string     | Yes   | Network port.                 |
| callback | AsyncCallback&lt;boolean&gt;            | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**, and **data** indicates whether the network port is disabled. The value **true** means the network port is disabled; and **false** means the opposite. If the operation fails, **err** is an error object.      |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                       |
| 9200002 | The administrator application does not have permission to manage the device.|

**Example**

```ts
import Want from '@ohos.app.ability.Want';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

networkManager.isNetworkInterfaceDisabled(wantTemp, 'eth0', (err, result) => {
  if (err) {
    console.error(`Failed to query network interface is disabled or not. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info(`Succeeded in querying network interface is disabled or not, result : ${result}`);
});
```

## networkManager.isNetworkInterfaceDisabled

isNetworkInterfaceDisabled(admin: Want, networkInterface: string): Promise&lt;boolean&gt;

Checks whether a network port is disabled through the specified device administrator application. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_GET_NETWORK_INFO

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | Yes   | Device administrator application.|
| networkInterface    | string     | Yes   | Network port.                 |

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means the network port is disabled, and the value **false** means the opposite. |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                       |
| 9200002 | The administrator application does not have permission to manage the device.|

**Example**

```ts
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

networkManager.isNetworkInterfaceDisabled(wantTemp, 'eth0').then((result) => {
  console.info(`Succeeded in querying network interface is disabled or not, result : ${result}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to query network interface is disabled or not. Code: ${err.code}, message: ${err.message}`);
});
```

## networkManager.setNetworkInterfaceDisabled

setNetworkInterfaceDisabled(admin: Want, networkInterface: string, isDisabled: boolean, callback: AsyncCallback&lt;void&gt;): void

Disables a network port through the specified device administrator application. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_SET_NETWORK

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)      | Yes   | Device administrator application.                 |
| networkInterface    | string     | Yes   | Network port.                 |
| isDisabled    | boolean     | Yes   | Network port status to set. The value **true** means to disable the network port, and **false** means to enable the network port.                 |
| callback | AsyncCallback&lt;void&gt;            | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.      |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                      |
| 9200002 | The administrator application does not have permission to manage the device.|

**Example**

```ts
import Want from '@ohos.app.ability.Want';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

networkManager.setNetworkInterfaceDisabled(wantTemp, 'eth0', true, (err) => {
  if (err) {
    console.error(`Failed to set network interface disabled. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info(`Succeeded in setting network interface disabled`);
});
```

## networkManager.setNetworkInterfaceDisabled

setNetworkInterfaceDisabled(admin: Want, networkInterface: string, isDisabled: boolean): Promise&lt;void&gt;

Disables a network port through the specified device administrator application. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_SET_NETWORK

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | Yes   | Device administrator application.|
| networkInterface    | string     | Yes   | Network port.                 |
| isDisabled    | boolean     | Yes   | Network port status to set. The value **true** means to disable the network port, and **false** means to enable the network port.                 |

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value. An error object is thrown if the network port fails to be disabled. |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                      |
| 9200002 | The administrator application does not have permission to manage the device.|

**Example**

```ts
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

networkManager.setNetworkInterfaceDisabled(wantTemp, 'eth0', true).then(() => {
  console.info(`Succeeded in setting network interface disabled`);
}).catch((err: BusinessError) => {
  console.error(`Failed to set network interface disabled. Code: ${err.code}, message: ${err.message}`);
});
```

## networkManager.setGlobalProxy

setGlobalProxy(admin: Want, httpProxy: connection.HttpProxy, callback: AsyncCallback\<void>): void

Sets the global network proxy through the specified device administrator application. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_NETWORK

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)      | Yes   | Device administrator application.                 |
| httpProxy    | [connection.HttpProxy](js-apis-net-connection.md#httpproxy10)     | Yes   | Global HTTP proxy to set.                 |
| callback | AsyncCallback&lt;void&gt;            | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.      |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                      |
| 9200002 | The administrator application does not have permission to manage the device.|

**Example**

```ts
import Want from '@ohos.app.ability.Want';
import connection from '@ohos.net.connection';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let exclusionStr: string = "192.168,baidu.com"
let exclusionArray: Array<string> = exclusionStr.split(',');
let httpProxy: connection.HttpProxy = {
  host: "192.168.xx.xxx",
  port: 8080,
  exclusionList: exclusionArray
};

networkManager.setGlobalProxy(wantTemp, httpProxy, (err) => {
  if (err) {
    console.error(`Failed to set network global proxy. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info(`Succeeded in setting network global proxy`);
});
```

## networkManager.setGlobalProxy

setGlobalProxy(admin: Want, httpProxy: connection.HttpProxy): Promise\<void>

Sets the global network proxy through the specified device administrator application. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_NETWORK

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | Yes   | Device administrator application.|
| httpProxy    | [connection.HttpProxy](js-apis-net-connection.md#httpproxy10)     | Yes   | Global HTTP proxy to set.                 |

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value. An error object will be thrown if the operation fails. |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                      |
| 9200002 | The administrator application does not have permission to manage the device.|

**Example**

```ts
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';
import connection from '@ohos.net.connection';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let exclusionStr: string = "192.168,baidu.com"
let exclusionArray: Array<string> = exclusionStr.split(',');
let httpProxy: connection.HttpProxy = {
  host: "192.168.xx.xxx",
  port: 8080,
  exclusionList: exclusionArray
};

networkManager.setGlobalProxy(wantTemp, httpProxy).then(() => {
  console.info(`Succeeded in setting network global proxy`);
}).catch((err: BusinessError) => {
  console.error(`Failed to set network global proxy. Code: ${err.code}, message: ${err.message}`);
});
```

## networkManager.getGlobalProxy

getGlobalProxy(admin: Want, callback: AsyncCallback\<connection.HttpProxy>): void

Obtains the global network proxy through the specified device administrator application. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_NETWORK

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)      | Yes   | Device administrator application.                 |
| callback | AsyncCallback&lt;[connection.HttpProxy](js-apis-net-connection.md#httpproxy10)&gt;            | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.      |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                      |
| 9200002 | The administrator application does not have permission to manage the device.|

**Example**

```ts
import Want from '@ohos.app.ability.Want';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

networkManager.getGlobalProxy(wantTemp, (err, result) => {
  if (err) {
    console.error(`Failed to get network global proxy. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info(`Succeeded in getting network global proxy, result : ${JSON.stringify(result)}`);
});
```

## networkManager.getGlobalProxy

getGlobalProxy(admin: Want): Promise\<connection.HttpProxy>

Obtains the global network proxy through the specified device administrator application. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_NETWORK

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | Yes   | Device administrator application.|

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;[connection.HttpProxy](js-apis-net-connection.md#httpproxy10)&gt; | Promise used to return the global HTTP proxy information obtained. |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                      |
| 9200002 | The administrator application does not have permission to manage the device.|

**Example**

```ts
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

networkManager.getGlobalProxy(wantTemp).then(() => {
  console.info(`Succeeded in getting network global proxy`);
}).catch((err: BusinessError) => {
  console.error(`Failed to get network global proxy. Code: ${err.code}, message: ${err.message}`);
});
```

## networkManager.addIptablesFilterRule

addIptablesFilterRule(admin: Want, filterRule: AddFilterRule, callback: AsyncCallback\<void>): void

Adds a network packet filtering rule through the specified device administrator application. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_NETWORK

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)      | Yes   | Device administrator application.                 |
| filterRule    | [AddFilterRule](#addfilterrule)     | Yes   | Network packet filtering rule to add.                 |
| callback | AsyncCallback&lt;void&gt;            | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.      |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                      |
| 9200002 | The administrator application does not have permission to manage the device.|

**Example**

```ts
import Want from '@ohos.app.ability.Want';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let filterRule: networkManager.AddFilterRule = {
  "ruleNo": 1,
  "srcAddr": "192.168.1.1-192.168.255.255",
  "destAddr": "10.1.1.1",
  "srcPort": "8080",
  "destPort": "8080",
  "uid": "9696",
  "method": networkManager.AddMethod.APPEND,
  "direction": networkManager.Direction.OUTPUT,
  "action": networkManager.Action.DENY,
  "protocol": networkManager.Protocol.UDP,
}

networkManager.addIptablesFilterRule(wantTemp, filterRule, (err) => {
  if (err) {
    console.error(`Failed to set iptables filter rule. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info(`Succeeded in setting iptables filter rule`);
});
```

## networkManager.addIptablesFilterRule

addIptablesFilterRule(admin: Want, filterRule: AddFilterRule): Promise\<void>

Adds a network packet filtering rule through the specified device administrator application. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_NETWORK

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | Yes   | Device administrator application.|
| filterRule    | [AddFilterRule](#addfilterrule)     | Yes   | Network packet filtering rule to add.                 |

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value. If the operation fails, an error object will be thrown. |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                      |
| 9200002 | The administrator application does not have permission to manage the device.|

**Example**

```ts
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let filterRule: networkManager.AddFilterRule = {
  "ruleNo": 1,
  "srcAddr": "192.168.1.1-192.168.255.255",
  "destAddr": "10.1.1.1",
  "srcPort": "8080",
  "destPort": "8080",
  "uid": "9696",
  "method": networkManager.AddMethod.APPEND,
  "direction": networkManager.Direction.OUTPUT,
  "action": networkManager.Action.DENY,
  "protocol": networkManager.Protocol.UDP,
}

networkManager.addIptablesFilterRule(wantTemp, filterRule).then(() => {
  console.info(`Succeeded in setting iptables filter rule`);
}).catch((err: BusinessError) => {
  console.error(`Failed to set iptables filter rule. Code: ${err.code}, message: ${err.message}`);
});
```

## networkManager.removeIptablesFilterRule

removeIptablesFilterRule(admin: Want, filterRule: RemoveFilterRule, callback: AsyncCallback\<void>): void

Removes a network packet filtering rule through the specified device administrator application. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_NETWORK

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)      | Yes   | Device administrator application.                 |
| filterRule    | [RemoveFilterRule](#removefilterrule)     | Yes   | Network packet filtering rule to remove.                 |
| callback | AsyncCallback&lt;void&gt;            | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.      |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                      |
| 9200002 | The administrator application does not have permission to manage the device.|

**Example**

```ts
import Want from '@ohos.app.ability.Want';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let filterRule: networkManager.RemoveFilterRule = {
  "srcAddr": "192.168.1.1-192.168.255.255",
  "destAddr": "10.1.1.1",
  "srcPort": "8080",
  "destPort": "8080",
  "uid": "9696",
  "direction": networkManager.Direction.OUTPUT,
  "action": networkManager.Action.DENY,
  "protocol": networkManager.Protocol.UDP,
}

networkManager.removeIptablesFilterRule(wantTemp, filterRule, (err) => {
  if (err) {
    console.error(`Failed to remove iptables filter rule. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info(`Succeeded in removing iptables filter rule`);
});
```

## networkManager.removeIptablesFilterRule

removeIptablesFilterRule(admin: Want, filterRule: RemoveFilterRule): Promise\<void>

Removes a network packet filtering rule through the specified device administrator application. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_NETWORK

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | Yes   | Device administrator application.|
| filterRule    | [RemoveFilterRule](#removefilterrule)     | Yes   | Network packet filtering rule to remove.                 |

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value. If the operation fails, an error object will be thrown. |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                      |
| 9200002 | The administrator application does not have permission to manage the device.|

**Example**

```ts
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let filterRule: networkManager.RemoveFilterRule = {
  "srcAddr": "192.168.1.1-192.168.255.255",
  "destAddr": "10.1.1.1",
  "srcPort": "8080",
  "destPort": "8080",
  "uid": "9696",
  "direction": networkManager.Direction.OUTPUT,
  "action": networkManager.Action.DENY,
  "protocol": networkManager.Protocol.UDP,
}

networkManager.removeIptablesFilterRule(wantTemp, filterRule).then(() => {
  console.info(`Succeeded in removing iptables filter rule`);
}).catch((err: BusinessError) => {
  console.error(`Failed to remove iptables filter rule. Code: ${err.code}, message: ${err.message}`);
});
```

## networkManager.listIptablesFilterRules

listIptablesFilterRules(admin: Want, callback: AsyncCallback\<string>): void

Obtains network packet filtering rules through the specified device administrator application. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_NETWORK

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)      | Yes   | Device administrator application.                 |
| callback | AsyncCallback&lt;string&gt;            | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.      |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                      |
| 9200002 | The administrator application does not have permission to manage the device.|

**Example**

```ts
import Want from '@ohos.app.ability.Want';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

networkManager.listIptablesFilterRules(wantTemp, (err, result) => {
  if (err) {
    console.error(`Failed to get iptables filter rule. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info(`Succeeded in getting iptables filter rule, result : ${result}`);
});
```

## networkManager.listIptablesFilterRules

listIptablesFilterRules(admin: Want): Promise\<string>

Obtains network packet filtering rules through the specified device administrator application. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_NETWORK

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | Yes   | Device administrator application.|

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;string&gt; | Promise used to return the network packet filtering rules obtained. |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                      |
| 9200002 | The administrator application does not have permission to manage the device.|

**Example**

```ts
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

networkManager.listIptablesFilterRules(wantTemp).then((result) => {
  console.info(`Succeeded in getting iptables filter rule, result: ${result}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to remove iptables filter rule. Code: ${err.code}, message: ${err.message}`);
});
```

## networkManager.addFirewallRule<sup>11+</sup>

addFirewallRule(admin: Want, firewallRule: FirewallRule): void

Adds a firewall rule for devices through the specified device administrator application.<br>
After a rule with [Action](#action) set to **ALLOW** is added, a rule with **Action** set to **DENY** is added by default to discard or intercept all network data packets that do not meet the **ALLOW** rule.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_NETWORK

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name         | Type                                 | Mandatory  | Description        |
|--------------|-------------------------------------| ---- |------------|
| admin        | [Want](js-apis-app-ability-want.md) | Yes   | Device administrator application.   |
| firewallRule | [FirewallRule](#firewallrule11)       | Yes   | Firewall rule to add.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                      |
| 9200002 | The administrator application does not have permission to manage the device.|

**Example**

```ts
import Want from '@ohos.app.ability.Want';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let firewallRule: networkManager.FirewallRule = {
  "srcAddr": "192.168.1.1-192.188.22.66",
  "destAddr": "10.1.1.1",
  "srcPort": "8080",
  "destPort": "8080",
  "appUid": "9696",
  "direction": networkManager.Direction.OUTPUT,
  "action": networkManager.Action.DENY,
  "protocol": networkManager.Protocol.UDP,
}

networkManager.addFirewallRule(wantTemp, firewallRule);
```

## networkManager.removeFirewallRule<sup>11+</sup>

removeFirewallRule(admin: Want, firewallRule?: FirewallRule): void

Removes a firewall rule for devices through the specified device administrator application.<br>
If there is no rule with [Action](#action) being **ALLOW** after the rule is removed, the **DENY** rules that are added by default with [addFirewallRule](#networkmanageraddfirewallrule11) will be removed.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_NETWORK

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name         | Type                                 | Mandatory| Description                         |
|--------------|-------------------------------------|----|-----------------------------|
| admin        | [Want](js-apis-app-ability-want.md) | Yes | Device administrator application.                    |
| firewallRule | [FirewallRule](#firewallrule11)       | No | Firewall rule to remove. If the value is empty, all firewall rules will be removed.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                      |
| 9200002 | The administrator application does not have permission to manage the device.|

**Example**

```ts
import Want from '@ohos.app.ability.Want';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
// Remove the specified firewall rule.
let firewallRule: networkManager.FirewallRule = {
  "srcAddr": "192.168.1.1-192.188.22.66",
  "destAddr": "10.1.1.1",
  "srcPort": "8080",
  "destPort": "8080",
  "appUid": "9696",
  "direction": networkManager.Direction.OUTPUT,
  "action": networkManager.Action.DENY,
  "protocol": networkManager.Protocol.UDP,
}
networkManager.removeFirewallRule(wantTemp, firewallRule);

// Remove all firewall rules.
networkManager.removeFirewallRule(wantTemp);
```

## networkManager.getFirewallRules<sup>11+</sup>

getFirewallRules(admin: Want): Array\<FirewallRule>

Obtains firewall rules through the specified device administrator application.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_NETWORK

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name         | Type                                 | Mandatory| Description                         |
|--------------|-------------------------------------|----|-----------------------------|
| admin        | [Want](js-apis-app-ability-want.md) | Yes | Device administrator application.                    |

**Return value**

| Type                                   | Description                               |
|---------------------------------------|-----------------------------------|
| Array\<[FirewallRule](#firewallrule11)> | A list of firewall rules configured for the device is returned. If the operation fails, an exception will be thrown.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                      |
| 9200002 | The administrator application does not have permission to manage the device.|

**Example**

```ts
import Want from '@ohos.app.ability.Want';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let firewallRule: Array<networkManager.FirewallRule>;
firewallRule = networkManager.getFirewallRules(wantTemp);
```

## networkManager.addDomainFilterRule<sup>11+</sup>

addDomainFilterRule(admin: Want, domainFilterRule: DomainFilterRule): void

Adds a domain name filtering rule for the device through the specified device administrator application.<br>
After a rule with [Action](#action) set to **ALLOW** is added, a rule with **Action** set to **DENY** is added by default to discard or intercept all packets for domain name resolution that do not meet the **ALLOW** rule.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_NETWORK

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name         | Type                                   | Mandatory  | Description        |
|--------------|---------------------------------------| ---- |------------|
| admin        | [Want](js-apis-app-ability-want.md)   | Yes   | Device administrator application.   |
| domainFilterRule | [DomainFilterRule](#domainfilterrule11) | Yes   | Domain name filtering rule to add.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                      |
| 9200002 | The administrator application does not have permission to manage the device.|

**Example**

```ts
import Want from '@ohos.app.ability.Want';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let domainFilterRule: networkManager.DomainFilterRule = {
  "domainName": "www.example.com",
  "appUid": "9696",
  "action": networkManager.Action.DENY,
}

networkManager.addDomainFilterRule(wantTemp, domainFilterRule);
```

## networkManager.removeDomainFilterRule<sup>11+</sup>

removeDomainFilterRule(admin: Want, domainFilterRule?: DomainFilterRule): void

Removes a domain name filtering rule through the specified device administrator application.<br>
If there is no rule with [Action](#action) being **ALLOW** after the rule is removed, the **DENY** rules that are added by default with [addDomainFilterRule](#networkmanageradddomainfilterrule11) will be removed.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_NETWORK

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name         | Type                                   | Mandatory| Description                      |
|--------------|---------------------------------------|----|--------------------------|
| admin        | [Want](js-apis-app-ability-want.md)   | Yes | Device administrator application.                 |
| domainFilterRule | [DomainFilterRule](#domainfilterrule11) | No | Domain name filtering rule to remove. If the value is empty, all domain name filtering rules will be removed.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                      |
| 9200002 | The administrator application does not have permission to manage the device.|

**Example**

```ts
import Want from '@ohos.app.ability.Want';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
// Remove the specified domain name filtering rule.
let domainFilterRule: networkManager.DomainFilterRule = {
  "domainName": "www.example.com",
  "appUid": "9696",
  "action": networkManager.Action.DENY,
}
networkManager.removeDomainFilterRule(wantTemp, domainFilterRule);

// Remove all domain name filtering rules.
networkManager.removeDomainFilterRule(wantTemp);
```

## networkManager.getDomainFilterRules<sup>11+</sup>

getDomainFilterRules(admin: Want): Array\<DomainFilterRule>

Obtains domain name filtering rules through the specified device administrator application.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_NETWORK

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name         | Type                                 | Mandatory| Description                         |
|--------------|-------------------------------------|----|-----------------------------|
| admin        | [Want](js-apis-app-ability-want.md) | Yes | Device administrator application.                    |

**Return value**

| Type                                           | Description                              |
|-----------------------------------------------|----------------------------------|
| Array\<[DomainFilterRule](#domainfilterrule11)> | A list of domain name filtering rules configured for the device is returned. If the operation fails, an exception will be thrown.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                      |
| 9200002 | The administrator application does not have permission to manage the device.|

**Example**

```ts
import Want from '@ohos.app.ability.Want';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let domainFilterRule: Array<networkManager.DomainFilterRule>;
domainFilterRule = networkManager.getDomainFilterRules(wantTemp);
```

## AddFilterRule

Defines the network packet filtering rule to add.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

| Name        | Type    | Mandatory| Description                           |
| ----------- | --------| ---- | ------------------------------- |
| ruleNo        | number    | No  | Sequence number of the rule.|
| srcAddr | string   | No  | Source IP address.|
| destAddr        | string    | No  | Destination IP address.|
| srcPort | string   | No  | Port of the source IP address.|
| destPort        | string    | No  | Port of the destination IP address.|
| uid | string   | No  | UID of the application.|
| method        | [AddMethod](#addmethod)    | Yes  | Method used to add the data packets.|
| direction | [Direction](#direction)    | Yes  | Direction chains to which the rule applies.|
| action        | [Action](#action)    | Yes  | Action to take, that is, receive or discard the data packets.|
| protocol | [Protocol](#protocol)   | No  | Network protocol.|

## RemoveFilterRule

Defines the network packet filtering rule to remove.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

| Name        | Type    | Mandatory| Description                           |
| ----------- | --------| ---- | ------------------------------- |
| srcAddr | string   | No  | Source IP address.|
| destAddr        | string    | No  | Destination IP address.|
| srcPort | string   | No  | Port of the source IP address.|
| destPort        | string    | No   | Port of the destination IP address.|
| uid | string   | No   | UID of the application.|
| direction | [Direction](#direction)    | Yes   | Direction chains to which the rule applies.|
| action        | [Action](#action)    | No   | Action to take, that is, receive or discard the data packets.|
| protocol | [Protocol](#protocol)   | No   | Network protocol.|

## AddMethod

Enumerates the methods used to add the network packets.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

| Name| Value| Description|
| -------- | -------- | -------- |
| APPEND | 0 | Append the packet.|
| INSERT | 1 | Insert the packet.|

## Direction

Enumerates the direction chains to which the rule applies.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

| Name| Value| Description|
| -------- | -------- | -------- |
| INPUT | 0 | Input chain.|
| OUTPUT | 1 | Output chain.|

## Action

Enumerates the actions that can be taken for the data packets.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

| Name| Value| Description|
| -------- | -------- | -------- |
| ALLOW | 0 | Receive the data packets.|
| DENY | 1 | Discard the data packets.|

## Protocol

Enumerates the network protocols supported.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

| Name| Value| Description|
| -------- | -------- | -------- |
| ALL | 0 | All network protocols.|
| TCP | 1 | TCP.|
| UDP | 2 | UDP.|
| ICMP | 3 | ICMP.|

## FirewallRule<sup>11+</sup>

Represents a firewall rule.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

| Name       | Type                     | Mandatory| Description                                                                                                                   |
|-----------|-------------------------|----|-----------------------------------------------------------------------------------------------------------------------|
| srcAddr   | string                  | No | Source IP address. Source IP address segment supported, for example, **192.168.0.0/22** or **192.168.1.100-192.168.1.200**.                                                           |
| destAddr  | string                  | No | Destination IP address. Destination IP address segment supported, for example, **192.168.0.0/22** or **192.168.1.100-192.168.1.200**.                                                          |
| srcPort   | string                  | No | Source port.                                                                                                                 |
| destPort  | string                  | No | Destination port.                                                                                                                |
| appUid    | string                  | No | UID of the application.                                                                                                               |
| direction | [Direction](#direction) | No | Direction chains to which the rule applies.<br>This parameter is mandatory when you add a firewall rule. If it is not specified when you remove a firewall rule, all [direction](#direction) chains will be removed.<br>If this parameter is empty, **srcAddr**, **destAddr**, **srcPort**, **destPort**, and **appUid** must also be empty.     |
| action    | [Action](#action)       | No | Action to take, that is, receive or discard the data packets.<br>This parameter is mandatory when you add a firewall rule. If it is not specified when you remove a firewall rule, all chains that match the [Action](#action) rule will be removed.<br>If this parameter is empty, **srcAddr**, **destAddr**, **srcPort**, **destPort**, and **appUid** must also be empty.|
| protocol  | [Protocol](#protocol)   | No | Network protocol. If this parameter is set to **ALL** or **ICMP**, **srcPort** and **destPort** cannot be set.                                                                            |

## DomainFilterRule<sup>11+</sup>

Represents a domain name filtering rule.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

| Name        | Type               | Mandatory| Description                                                                                               |
|------------|-------------------|----|---------------------------------------------------------------------------------------------------|
| domainName | string            | No | Domain name. This parameter is mandatory when you add a domain name filtering rule.                                                                                  |
| appUid     | string            | No | UID of the application.                                                                                           |
| action     | [Action](#action) | No | Action to take, that is, receive or discard the data packets.<br>This parameter is mandatory when you add a domain name filtering rule. If it is not specified when you remove a domain name filtering rule, all chains that match the [Action](#action) rule will be removed.<br>If this parameter is empty, **domainName** and **appUid** must also be empty.|
