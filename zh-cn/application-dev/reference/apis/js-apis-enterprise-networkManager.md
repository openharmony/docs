# @ohos.enterprise.networkManager（网络管理）

本模块提供设备网络管理能力，包括查询设备IP地址、MAC地址信息等。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 本模块接口仅对[设备管理应用](enterpriseDeviceManagement-overview.md#基本概念)开放，需将[设备管理应用激活](js-apis-enterprise-adminManager.md#adminmanagerenableadmin)后调用，实现相应功能。

## 导入模块

```ts
import networkManager from '@ohos.enterprise.networkManager';
```

## networkManager.getAllNetworkInterfaces

getAllNetworkInterfaces(admin: Want, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

指定设备管理应用获取所有激活的网络接口。使用callback异步回调。

**需要权限：** ohos.permission.ENTERPRISE_GET_NETWORK_INFO

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)     | 是    | 设备管理应用。                  |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;            | 是    | 回调函数。当接口调用成功，err为null，data为网络接口名称数组，否则err为错误对象。     |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                       |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

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

指定设备管理应用获取所有激活的网络接口。使用Promise异步回调。

**需要权限：** ohos.permission.ENTERPRISE_GET_NETWORK_INFO

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | 是    | 设备管理应用。 |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise结果，返回网络接口名称数组。  |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                     |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

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

指定设备管理应用根据网络接口获取设备IP地址。使用callback异步回调。

**需要权限：** ohos.permission.ENTERPRISE_GET_NETWORK_INFO

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)     | 是    | 设备管理应用。                  |
| networkInterface    | string     | 是    | 指定网络接口。                  |
| callback | AsyncCallback&lt;string&gt;            | 是    | 回调函数。当接口调用成功，err为null，data为IP地址，否则err为错误对象。       |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                       |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

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

指定设备管理应用根据网络接口获取设备IP地址。使用Promise异步回调。

**需要权限：** ohos.permission.ENTERPRISE_GET_NETWORK_INFO

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | 是    | 设备管理应用。 |
| networkInterface    | string     | 是    | 指定网络接口。                  |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;string&gt; | Promise结果，返回设备IP地址。  |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                     |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

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

指定设备管理应用根据网络接口获取设备MAC地址。使用callback异步回调。

**需要权限：** ohos.permission.ENTERPRISE_GET_NETWORK_INFO

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)      | 是    | 设备管理应用。                  |
| networkInterface    | string     | 是    | 指定网络接口。                  |
| callback | AsyncCallback&lt;string&gt;            | 是    | 回调函数。当接口调用成功，err为null，data为设备MAC地址，否则err为错误对象。       |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                       |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

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

getMac(admin: Want, networkInterface: string): Promise\<string>;

指定设备管理应用根据网络接口获取设备MAC地址。使用Promise异步回调。

**需要权限：** ohos.permission.ENTERPRISE_GET_NETWORK_INFO

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | 是    | 设备管理应用。 |
| networkInterface    | string     | 是    | 指定网络接口。                  |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;string&gt; | Promise结果，返回设备MAC地址。  |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                     |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

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

指定设备管理应用查询指定网络接口是否被禁用。使用callback异步回调。

**需要权限：** ohos.permission.ENTERPRISE_GET_NETWORK_INFO

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)      | 是    | 设备管理应用。                  |
| networkInterface    | string     | 是    | 指定网络接口。                  |
| callback | AsyncCallback&lt;boolean&gt;            | 是    | 回调函数。当接口调用成功，err为null，data为指定网络接口是否被禁用，true表示该网络接口被禁用，false表示该网络接口未被禁用，否则err为错误对象。       |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                       |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

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

指定设备管理应用查询指定网络接口是否被禁用。使用Promise异步回调。

**需要权限：** ohos.permission.ENTERPRISE_GET_NETWORK_INFO

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | 是    | 设备管理应用。 |
| networkInterface    | string     | 是    | 指定网络接口。                  |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;boolean&gt; | Promise结果，返回指定网络接口是否被禁用，true表示该网络接口被禁用，false表示该网络接口未被禁用。  |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                     |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

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

指定设备管理应用禁止设备使用指定网络。使用callback异步回调。

**需要权限：** ohos.permission.ENTERPRISE_SET_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)      | 是    | 设备管理应用。                  |
| networkInterface    | string     | 是    | 指定网络接口。                  |
| isDisabled    | boolean     | 是    | true表示禁用该网络接口，false表示开启该网络接口。                  |
| callback | AsyncCallback&lt;void&gt;            | 是    | 回调函数。当接口调用成功，err为null，否则err为错误对象。       |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                       |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

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

指定设备管理应用禁止设备使用指定网络。使用Promise异步回调。

**需要权限：** ohos.permission.ENTERPRISE_SET_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | 是    | 设备管理应用。 |
| networkInterface    | string     | 是    | 指定网络接口。                  |
| isDisabled    | boolean     | 是    | true表示禁用该网络接口，false表示开启该网络接口。                  |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。当禁用网络接口失败时抛出错误对象  |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                       |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

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

指定设备管理应用设置网络全局代理，使用callback异步回调。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)      | 是    | 设备管理应用。                  |
| httpProxy    | [connection.HttpProxy](js-apis-net-connection.md#httpproxy10)     | 是    | 网络全局Http代理配置信息。                  |
| callback | AsyncCallback&lt;void&gt;            | 是    | 回调函数。当接口调用成功，err为null，否则err为错误对象。       |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                       |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

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

指定设备管理应用设置网络全局代理，使用Promise异步回调。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | 是    | 设备管理应用。 |
| httpProxy    | [connection.HttpProxy](js-apis-net-connection.md#httpproxy10)     | 是    | 网络全局Http代理配置信息。                  |
| isDisabled    | boolean     | 是    | true表示禁用该网络接口，false表示开启该网络接口。                  |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。当设置网络全局代理失败时抛出错误对象  |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                       |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

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

指定设备管理应用获取网络全局代理，使用callback异步回调。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)      | 是    | 设备管理应用。                  |
| callback | AsyncCallback&lt;[connection.HttpProxy](js-apis-net-connection.md#httpproxy10)&gt;            | 是    | 回调函数。当接口调用成功，err为null，否则err为错误对象。       |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                       |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

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

指定设备管理应用获取网络全局代理，使用Promise异步回调。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | 是    | 设备管理应用。 |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;[connection.HttpProxy](js-apis-net-connection.md#httpproxy10)&gt; | Promise对象，返回网络全局Http代理配置信息。  |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                       |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

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

指定设备管理应用为设备添加网络包过滤规则。使用callback异步回调。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)      | 是    | 设备管理应用。                  |
| filterRule    | [AddFilterRule](#addfilterrule)     | 是    | 添加网络包过滤规则。                  |
| callback | AsyncCallback&lt;void&gt;            | 是    | 回调函数。当接口调用成功，err为null，否则err为错误对象。       |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                       |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

```ts
import Want from '@ohos.app.ability.Want';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let filterRule: networkManager.AddFilterRule = {
  "ruleNo": 1,
  "srcAddr": "192.168.1.1-192.188.22.66",
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

指定设备管理应用为设备添加网络包过滤规则。使用Promise异步回调。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | 是    | 设备管理应用。 |
| filterRule    | [AddFilterRule](#addfilterrule)     | 是    | 添加网络包过滤规则。                  |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。当添加网络包过滤规则失败时抛出错误对象。  |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                       |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

```ts
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let filterRule: networkManager.AddFilterRule = {
  "ruleNo": 1,
  "srcAddr": "192.168.1.1-192.188.22.66",
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

指定设备管理应用移除网络包过滤规则。使用callback异步回调。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)      | 是    | 设备管理应用。                  |
| filterRule    | [RemoveFilterRule](#removefilterrule)     | 是    | 移除网络包过滤规则。                  |
| callback | AsyncCallback&lt;void&gt;            | 是    | 回调函数。当接口调用成功，err为null，否则err为错误对象。       |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                       |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

```ts
import Want from '@ohos.app.ability.Want';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let filterRule: networkManager.RemoveFilterRule = {
  "srcAddr": "192.168.1.1-192.188.22.66",
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

指定设备管理应用移除网络包过滤规则。使用Promise异步回调。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | 是    | 设备管理应用。 |
| filterRule    | [RemoveFilterRule](#removefilterrule)     | 是    | 移除网络包过滤规则。                  |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。当移除网络包过滤规则失败时抛出错误对象。  |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                       |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

```ts
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let filterRule: networkManager.RemoveFilterRule = {
  "srcAddr": "192.168.1.1-192.188.22.66",
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

指定设备管理应用获取网络包过滤规则。使用callback异步回调。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)      | 是    | 设备管理应用。                  |
| callback | AsyncCallback&lt;string&gt;            | 是    | 回调函数。当接口调用成功，err为null，否则err为错误对象。       |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                       |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

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

指定设备管理应用获取网络包过滤规则。使用Promise异步回调。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | 是    | 设备管理应用。 |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;string&gt; | Promise对象,返回网络包过滤规则。  |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                       |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

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

## networkManager.addFirewallRule

addFirewallRule(admin: Want, firewallRule: Firewall): void

指定设备管理应用为设备添加防火墙过滤规则。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名          | 类型                                  | 必填   | 说明         |
|--------------|-------------------------------------| ---- |------------|
| admin        | [Want](js-apis-app-ability-want.md) | 是    | 设备管理应用。    |
| firewallRule | [FirewallRule](#firewallRule)       | 是    | 添加防火墙过滤规则。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                       |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

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

## networkManager.removeFirewallRule

removeFirewallRule(admin: Want, firewallRule?: Firewall): void

指定设备管理应用移除设备防火墙过滤规则。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名          | 类型                                  | 必填 | 说明                          |
|--------------|-------------------------------------|----|-----------------------------|
| admin        | [Want](js-apis-app-ability-want.md) | 是  | 设备管理应用。                     |
| firewallRule | [FirewallRule](#firewallRule)       | 否  | 移除防火墙过滤规则。值为空时，清空所有的防火墙规则。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                       |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

```ts
import Want from '@ohos.app.ability.Want';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
// 移除指定的规则
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

// 清空所有规则
networkManager.removeFirewallRule(wantTemp);
```

## networkManager.getFirewallRule

getFirewallRule(admin: Want): Array\<FirewallRule>

指定设备管理应用查询防火墙过滤规则。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名          | 类型                                  | 必填 | 说明                          |
|--------------|-------------------------------------|----|-----------------------------|
| admin        | [Want](js-apis-app-ability-want.md) | 是  | 设备管理应用。                     |

**返回值：**

| 类型       | 说明                                |
|----------|-----------------------------------|
| Array<[FirewallRule](#firewallRule)> | 返回当前设备配置的防火墙过滤规则列表，当方法调用错误时会抛出异常。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                       |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

```ts
import Want from '@ohos.app.ability.Want';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let firewallRule: Array<networkManager.FirewallRule>;
firewallRule = networkManager.getFirewallRules(wantTemp);
```

## networkManager.addDomainFilterRule

addDomainFilterRule(admin: Want, domainFilterRule: DomainFilterRule): void

指定设备管理应用为设备添加域名过滤规则。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名          | 类型                                  | 必填   | 说明         |
|--------------|-------------------------------------| ---- |------------|
| admin        | [Want](js-apis-app-ability-want.md) | 是    | 设备管理应用。    |
| domainFilterRule | [DomainFilterRule](#domainFilterRule)       | 是    | 添加域名过滤规则。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                       |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

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

## networkManager.removeDomainFilterRule

removeDomainFilterRule(admin: Want, domainFilterRule?: DomainFilterRule): void

指定设备管理应用移除设备域名过滤规则。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名          | 类型                                  | 必填 | 说明                       |
|--------------|-------------------------------------|----|--------------------------|
| admin        | [Want](js-apis-app-ability-want.md) | 是  | 设备管理应用。                  |
| domainFilterRule | [DomainFilterRule](#domainFilterRule)       | 否  | 移除域名过滤规则。值为空时，清空所有的域名规则。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                       |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

```ts
import Want from '@ohos.app.ability.Want';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
// 移除指定的规则
let domainFilterRule: networkManager.DomainFilterRule = {
  "domainName": "www.example.com",
  "appUid": "9696",
  "action": networkManager.Action.DENY,
}
networkManager.removeDomainFilterRule(wantTemp, domainFilterRule);

// 清空所有规则
networkManager.removeDomainFilterRule(wantTemp);
```

## networkManager.getDomainFilterRules

getDomainFilterRules(admin: Want): Array\<DomainFilterRule>

指定设备管理应用查询域名过滤规则。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名          | 类型                                  | 必填 | 说明                          |
|--------------|-------------------------------------|----|-----------------------------|
| admin        | [Want](js-apis-app-ability-want.md) | 是  | 设备管理应用。                     |

**返回值：**

| 类型                                           | 说明                               |
|----------------------------------------------|----------------------------------|
| Array<[DomainFilterRule](#domainFilterRule)> | 返回当前设备配置的域名过滤规则列表，当方法调用错误时会抛出异常。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                       |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

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

添加网络包过滤规则

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

| 名称         | 类型     | 必填 | 说明                            |
| ----------- | --------| ---- | ------------------------------- |
| ruleNo        | number    | 否   | 规则序号。 |
| srcAddr | string   | 否   | ip源地址。 |
| destAddr        | string    | 否   | ip目标地址。 |
| srcPort | string   | 否   | ip源端口。 |
| destPort        | string    | 否   | ip目标端口。 |
| uid | string   | 否   | 应用uid。 |
| method        | [AddMethod](#addmethod)    | 是   | 添加策略。 |
| direction | [Direction](#direction)    | 是   | 规则链。 |
| action        | [Action](#action)    | 是   | 接收或者丢弃数据包。 |
| protocol | [Protocol](#protocol)   | 否   | 网络协议。 |

## RemoveFilterRule

移除网络包过滤规则

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

| 名称         | 类型     | 必填 | 说明                            |
| ----------- | --------| ---- | ------------------------------- |
| srcAddr | string   | 否   | ip源地址。 |
| destAddr        | string    | 否   | ip目标地址。 |
| srcPort | string   | 否   | ip源端口。 |
| destPort        | string    | 否    | ip目标端口。 |
| uid | string   | 否    | 应用uid。 |
| direction | [Direction](#direction)    | 是    | 规则链。 |
| action        | [Action](#action)    | 否    | 接收或者丢弃数据包。 |
| protocol | [Protocol](#protocol)   | 否    | 网络协议。 |

## AddMethod

添加网络包方法。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| APPEND | 0 | 追加。 |
| INSERT | 1 | 插入。 |

## Direction

规则链。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| INPUT | 0 | 输入链。 |
| OUTPUT | 1 | 输出链。 |

## Action

数据包的行为。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| ALLOW | 0 | 接收数据包。 |
| DENY | 1 | 丢弃数据包。 |

## Protocol

网络协议。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| ALL | 0 | 全部网络协议。 |
| TCP | 1 | 网络协议TCP。 |
| UDP | 2 | 网络协议UDP。 |
| ICMP | 3 | 网络协议ICMP。 |

## FirewallRule

防火墙过滤规则。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

| 名称        | 类型                      | 必填 | 说明                                                                                                                    |
|-----------|-------------------------|----|-----------------------------------------------------------------------------------------------------------------------|
| srcAddr   | string                  | 否  | ip源地址。支持IP段，例如：192.168.0.0/22或者192.168.1.100-192.168.1.200                                                            |
| destAddr  | string                  | 否  | ip目标地址。支持IP段，例如：192.168.0.0/22或者192.168.1.100-192.168.1.200                                                           |
| srcPort   | string                  | 否  | 源端口。                                                                                                                  |
| destPort  | string                  | 否  | 目标端口。                                                                                                                 |
| appUid    | string                  | 否  | 应用uid。                                                                                                                |
| direction | [Direction](#direction) | 否  | 规则链。<br/>添加防护墙过滤规则时必填；移除防火墙时非必填，表示清空所有的[Direction](#direction)链。<br/>当值为空时srcAddr，destAddr，srcPort，destPort，appUid也必须传入空值。      |
| action    | [Action](#action)       | 否  | 接收或者丢弃数据包。<br/>添加防护墙过滤规则时必填；移除防火墙时非必填，表示清空所有的匹配[Action](#action)规则的链。<br/>当值为空时srcAddr，destAddr，srcPort，destPort，appUid也必须传入空值。 |
| protocol  | [Protocol](#protocol)   | 否  | 网络协议。当值为ALL或者ICMP时，不允许设置srcPort与destPort。                                                                             |

## DomainFilterRule

域名过滤规则。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

| 名称         | 类型                | 必填 | 说明                                                                                                |
|------------|-------------------|----|---------------------------------------------------------------------------------------------------|
| domainName | string            | 否  | 域名。添加域名过滤规则时必填。                                                                                   |
| appUid     | string            | 否  | 应用uid。                                                                                            |
| action     | [Action](#action) | 否  | 接收或者丢弃数据包。<br/>添加域名过滤规则时必填；移除域名过滤规则时非必填，表示清空所有的匹配[Action](#action)规则的链。<br/>当值为空时，domainName，appUid也必须传入空值。 |