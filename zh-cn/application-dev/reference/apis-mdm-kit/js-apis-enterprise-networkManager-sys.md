# @ohos.enterprise.networkManager（网络管理）(系统接口)
<!--Kit: MDM Kit-->
<!--Subsystem: Customization-->
<!--Owner: @huanleima-->
<!--Designer: @liuzuming-->
<!--Tester: @lpw_work-->
<!--Adviser: @Brilliantry_Rui-->

本模块提供设备网络管理能力，包括查询设备IP地址、MAC地址信息等。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 本模块接口仅对[设备管理应用](../../mdm/mdm-kit-term.md#mdm应用设备管理应用)开放，需将[设备管理应用激活](js-apis-enterprise-adminManager-sys.md#adminmanagerenableadmin-2)后调用。
> 
> 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.enterprise.networkManager](js-apis-enterprise-networkManager.md)。

## 导入模块

```ts
import { networkManager } from '@kit.MDMKit';
```

## networkManager.getAllNetworkInterfaces

getAllNetworkInterfaces(admin: Want, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

获取所有激活的有线网络接口。使用callback异步回调。

**需要权限：** ohos.permission.ENTERPRISE_GET_NETWORK_INFO

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | 是    | 企业设备管理扩展组件。            |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;            | 是    | 回调函数。当接口调用成功，err为null，data为网络接口名称数组，否则err为错误对象。     |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                       |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.            |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { networkManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
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

获取所有激活的有线网络接口。使用Promise异步回调。

**需要权限：** ohos.permission.ENTERPRISE_GET_NETWORK_INFO

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名 | 类型                                                    | 必填 | 说明                   |
| ------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。 |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise结果，返回所有激活的有线网络接口名称数组。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.            |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { networkManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};

networkManager.getAllNetworkInterfaces(wantTemp).then((result) => {
  console.info(`Succeeded in getting all network interfaces, result : ${JSON.stringify(result)}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to get all network interfaces. Code: ${err.code}, message: ${err.message}`);
});
```

## networkManager.getIpAddress

getIpAddress(admin: Want, networkInterface: string, callback: AsyncCallback&lt;string&gt;): void

根据网络接口获取设备IP地址。使用callback异步回调。

**需要权限：** ohos.permission.ENTERPRISE_GET_NETWORK_INFO

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | 是    | 企业设备管理扩展组件。            |
| networkInterface    | string     | 是    | 指定网络接口。                  |
| callback | AsyncCallback&lt;string&gt;            | 是    | 回调函数。当接口调用成功，err为null，data为IP地址，否则err为错误对象。       |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                       |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.            |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { networkManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};

// 参数需根据实际情况进行替换
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

根据网络接口获取设备IP地址。使用Promise异步回调。

**需要权限：** ohos.permission.ENTERPRISE_GET_NETWORK_INFO

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是    | 企业设备管理扩展组件。 |
| networkInterface    | string     | 是    | 指定网络接口。                  |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;string&gt; | Promise结果，返回设备IP地址。  |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.            |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { networkManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};

// 参数需根据实际情况进行替换
networkManager.getIpAddress(wantTemp, 'eth0').then((result) => {
  console.info(`Succeeded in getting ip address, result : ${result}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to get ip address. Code: ${err.code}, message: ${err.message}`);
});
```

## networkManager.getMac

getMac(admin: Want, networkInterface: string, callback: AsyncCallback&lt;string&gt;): void

根据网络接口获取设备MAC地址。使用callback异步回调。

**需要权限：** ohos.permission.ENTERPRISE_GET_NETWORK_INFO

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)      | 是    | 企业设备管理扩展组件。            |
| networkInterface    | string     | 是    | 指定网络接口。                  |
| callback | AsyncCallback&lt;string&gt;            | 是    | 回调函数。当接口调用成功，err为null，data为设备MAC地址，否则err为错误对象。       |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                       |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.            |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { networkManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};

// 参数需根据实际情况进行替换
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

根据网络接口获取设备MAC地址。使用Promise异步回调。

**需要权限：** ohos.permission.ENTERPRISE_GET_NETWORK_INFO

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是    | 企业设备管理扩展组件。 |
| networkInterface    | string     | 是    | 指定网络接口。                  |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;string&gt; | Promise结果，返回设备MAC地址。  |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.            |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { networkManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};

// 参数需根据实际情况进行替换
networkManager.getMac(wantTemp, 'eth0').then((result) => {
  console.info(`Succeeded in getting mac, result : ${result}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to get mac. Code: ${err.code}, message: ${err.message}`);
});
```

## networkManager.isNetworkInterfaceDisabled

isNetworkInterfaceDisabled(admin: Want, networkInterface: string, callback: AsyncCallback&lt;boolean&gt;): void

查询指定网络接口是否被禁用。使用callback异步回调。

**需要权限：** ohos.permission.ENTERPRISE_GET_NETWORK_INFO

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)      | 是    | 企业设备管理扩展组件。            |
| networkInterface    | string     | 是    | 指定网络接口。                  |
| callback | AsyncCallback&lt;boolean&gt;            | 是    | 回调函数。当接口调用成功，err为null，data为指定网络接口是否被禁用，true表示该网络接口被禁用，false表示该网络接口未被禁用，否则err为错误对象。       |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                       |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.            |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { networkManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};

// 参数需根据实际情况进行替换
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

查询指定网络接口是否被禁用。使用Promise异步回调。

**需要权限：** ohos.permission.ENTERPRISE_GET_NETWORK_INFO

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是    | 企业设备管理扩展组件。 |
| networkInterface    | string     | 是    | 指定网络接口。                  |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;boolean&gt; | Promise结果，返回指定网络接口是否被禁用，true表示该网络接口被禁用，false表示该网络接口未被禁用。  |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.            |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { networkManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};

// 参数需根据实际情况进行替换
networkManager.isNetworkInterfaceDisabled(wantTemp, 'eth0').then((result) => {
  console.info(`Succeeded in querying network interface is disabled or not, result : ${result}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to query network interface is disabled or not. Code: ${err.code}, message: ${err.message}`);
});
```

## networkManager.setNetworkInterfaceDisabled

setNetworkInterfaceDisabled(admin: Want, networkInterface: string, isDisabled: boolean, callback: AsyncCallback&lt;void&gt;): void

禁止设备使用指定网络。使用callback异步回调。

**需要权限：** ohos.permission.ENTERPRISE_SET_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)      | 是    | 企业设备管理扩展组件。            |
| networkInterface    | string     | 是    | 指定网络接口。                  |
| isDisabled    | boolean     | 是    | true表示禁用该网络接口，false表示开启该网络接口。                  |
| callback | AsyncCallback&lt;void&gt;            | 是    | 回调函数。当接口调用成功，err为null，否则err为错误对象。       |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.           |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { networkManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};

// 参数需根据实际情况进行替换
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

禁止设备使用指定网络。使用Promise异步回调。

**需要权限：** ohos.permission.ENTERPRISE_SET_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是    | 企业设备管理扩展组件。 |
| networkInterface    | string     | 是    | 指定网络接口。                  |
| isDisabled    | boolean     | 是    | true表示禁用该网络接口，false表示开启该网络接口。                  |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。当禁用网络接口失败时抛出错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.           |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { networkManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};

// 参数需根据实际情况进行替换
networkManager.setNetworkInterfaceDisabled(wantTemp, 'eth0', true).then(() => {
  console.info(`Succeeded in setting network interface disabled`);
}).catch((err: BusinessError) => {
  console.error(`Failed to set network interface disabled. Code: ${err.code}, message: ${err.message}`);
});
```

## networkManager.setGlobalProxy

setGlobalProxy(admin: Want, httpProxy: connection.HttpProxy, callback: AsyncCallback\<void>): void

设置网络全局代理，使用callback异步回调。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)      | 是    | 企业设备管理扩展组件。            |
| httpProxy    | [connection.HttpProxy](../apis-network-kit/js-apis-net-connection.md#httpproxy10)     | 是    | 网络全局Http代理配置信息。                  |
| callback | AsyncCallback&lt;void&gt;            | 是    | 回调函数。当接口调用成功，err为null，否则err为错误对象。       |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.           |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { networkManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';
import { connection } from '@kit.NetworkKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};

// 参数需根据实际情况进行替换
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

设置网络全局代理，使用Promise异步回调。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是    | 企业设备管理扩展组件。 |
| httpProxy    | [connection.HttpProxy](../apis-network-kit/js-apis-net-connection.md#httpproxy10)     | 是    | 网络全局Http代理配置信息。                  |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。当设置网络全局代理失败时抛出错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.           |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { networkManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { connection } from '@kit.NetworkKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};

// 需根据实际情况进行替换
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

获取网络全局代理，使用callback异步回调。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)      | 是    | 企业设备管理扩展组件。            |
| callback | AsyncCallback&lt;[connection.HttpProxy](../apis-network-kit/js-apis-net-connection.md#httpproxy10)&gt;            | 是    | 回调函数。当接口调用成功，err为null，否则err为错误对象。       |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.           |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { networkManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
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

获取网络全局代理，使用Promise异步回调。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名 | 类型                                                    | 必填 | 说明                   |
| ------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。 |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;[connection.HttpProxy](../apis-network-kit/js-apis-net-connection.md#httpproxy10)&gt; | Promise对象，返回网络全局Http代理配置信息。  |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.           |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { networkManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};

networkManager.getGlobalProxy(wantTemp).then(() => {
  console.info(`Succeeded in getting network global proxy`);
}).catch((err: BusinessError) => {
  console.error(`Failed to get network global proxy. Code: ${err.code}, message: ${err.message}`);
});
```

## networkManager.addIptablesFilterRule

addIptablesFilterRule(admin: Want, filterRule: AddFilterRule, callback: AsyncCallback\<void>): void

为设备添加网络包过滤规则，仅支持IPv4。使用callback异步回调。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)      | 是    | 企业设备管理扩展组件。            |
| filterRule    | [AddFilterRule](#addfilterrule)     | 是    | 添加网络包过滤规则。                  |
| callback | AsyncCallback&lt;void&gt;            | 是    | 回调函数。当接口调用成功，err为null，否则err为错误对象。       |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.           |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { networkManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
let filterRule: networkManager.AddFilterRule = {
  // 需根据实际情况进行替换
  "ruleNo": 1,
  "srcAddr": "192.168.1.1-192.168.255.255",
  "destAddr": "10.1.1.1",
  "srcPort": "8080",
  "destPort": "8080",
  "uid": "9696",
  "method": networkManager.AddMethod.APPEND,
  "direction": networkManager.Direction.OUTPUT,
  "action": networkManager.Action.DENY,
  "protocol": networkManager.Protocol.UDP
};

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

为设备添加网络包过滤规则，仅支持IPv4。使用Promise异步回调。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是    | 企业设备管理扩展组件。 |
| filterRule    | [AddFilterRule](#addfilterrule)     | 是    | 添加网络包过滤规则。                  |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。当添加网络包过滤规则失败时抛出错误对象。  |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.           |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { networkManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
let filterRule: networkManager.AddFilterRule = {
  // 需根据实际情况进行替换
  "ruleNo": 1,
  "srcAddr": "192.168.1.1-192.168.255.255",
  "destAddr": "10.1.1.1",
  "srcPort": "8080",
  "destPort": "8080",
  "uid": "9696",
  "method": networkManager.AddMethod.APPEND,
  "direction": networkManager.Direction.OUTPUT,
  "action": networkManager.Action.DENY,
  "protocol": networkManager.Protocol.UDP
};

networkManager.addIptablesFilterRule(wantTemp, filterRule).then(() => {
  console.info(`Succeeded in setting iptables filter rule`);
}).catch((err: BusinessError) => {
  console.error(`Failed to set iptables filter rule. Code: ${err.code}, message: ${err.message}`);
});
```

## networkManager.removeIptablesFilterRule

removeIptablesFilterRule(admin: Want, filterRule: RemoveFilterRule, callback: AsyncCallback\<void>): void

移除网络包过滤规则，仅支持IPv4。使用callback异步回调。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)      | 是    | 企业设备管理扩展组件。            |
| filterRule    | [RemoveFilterRule](#removefilterrule)     | 是    | 移除网络包过滤规则。                  |
| callback | AsyncCallback&lt;void&gt;            | 是    | 回调函数。当接口调用成功，err为null，否则err为错误对象。       |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.           |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { networkManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
let filterRule: networkManager.RemoveFilterRule = {
  // 需根据实际情况进行替换
  "srcAddr": "192.168.1.1-192.168.255.255",
  "destAddr": "10.1.1.1",
  "srcPort": "8080",
  "destPort": "8080",
  "uid": "9696",
  "direction": networkManager.Direction.OUTPUT,
  "action": networkManager.Action.DENY,
  "protocol": networkManager.Protocol.UDP
};

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

移除网络包过滤规则，仅支持IPv4。使用Promise异步回调。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是    | 企业设备管理扩展组件。 |
| filterRule    | [RemoveFilterRule](#removefilterrule)     | 是    | 移除网络包过滤规则。                  |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。当移除网络包过滤规则失败时抛出错误对象。  |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.           |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { networkManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
let filterRule: networkManager.RemoveFilterRule = {
  // 需根据实际情况进行替换
  "srcAddr": "192.168.1.1-192.168.255.255",
  "destAddr": "10.1.1.1",
  "srcPort": "8080",
  "destPort": "8080",
  "uid": "9696",
  "direction": networkManager.Direction.OUTPUT,
  "action": networkManager.Action.DENY,
  "protocol": networkManager.Protocol.UDP
};

networkManager.removeIptablesFilterRule(wantTemp, filterRule).then(() => {
  console.info(`Succeeded in removing iptables filter rule`);
}).catch((err: BusinessError) => {
  console.error(`Failed to remove iptables filter rule. Code: ${err.code}, message: ${err.message}`);
});
```

## networkManager.listIptablesFilterRules

listIptablesFilterRules(admin: Want, callback: AsyncCallback\<string>): void

获取网络包过滤规则，仅支持IPv4。使用callback异步回调。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)      | 是    | 企业设备管理扩展组件。            |
| callback | AsyncCallback&lt;string&gt;            | 是    | 回调函数。当接口调用成功，err为null，否则err为错误对象。       |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.           |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { networkManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
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

获取网络包过滤规则，仅支持IPv4。使用Promise异步回调。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名 | 类型                                                    | 必填 | 说明                   |
| ------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。 |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;string&gt; | Promise对象，返回网络包过滤规则。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.           |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { networkManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};

networkManager.listIptablesFilterRules(wantTemp).then((result) => {
  console.info(`Succeeded in getting iptables filter rule, result: ${result}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to remove iptables filter rule. Code: ${err.code}, message: ${err.message}`);
});
```

## AddFilterRule

添加网络包过滤规则。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统接口：** 此接口为系统接口。

| 名称         | 类型     | 只读 | 可选 | 说明                            |
| ----------- | --------| ---- | ---- | ------------------------------- |
| ruleNo        | number    | 否   | 是 | 规则序号。 |
| srcAddr | string   | 否   | 是 | ip源地址。 |
| destAddr        | string    | 否   | 是 | ip目标地址。 |
| srcPort | string   | 否   | 是 | ip源端口。 |
| destPort        | string    | 否   | 是 | ip目标端口。 |
| uid | string   | 否   | 是 | 应用uid。 |
| method        | [AddMethod](#addmethod)    | 否   | 否 | 添加策略。 |
| direction | [Direction](js-apis-enterprise-networkManager.md#direction) | 否   | 否 | 规则链。 |
| action        | [Action](js-apis-enterprise-networkManager.md#action) | 否   | 否 | 接收或者丢弃数据包。 |
| protocol | [Protocol](js-apis-enterprise-networkManager.md#protocol) | 否   | 是 |网络协议。 |

## RemoveFilterRule

移除网络包过滤规则。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统接口：** 此接口为系统接口。

| 名称         | 类型     | 只读 | 可选 | 说明                            |
| ----------- | --------| ---- | ---- | ------------------------------ |
| srcAddr | string   | 否   | 是 | ip源地址。 |
| destAddr        | string    | 否   | 是 | ip目标地址。 |
| srcPort | string   | 否   | 是 | ip源端口。 |
| destPort        | string    | 否    | 是 | ip目标端口。 |
| uid | string   | 否    | 是 | 应用uid。 |
| direction | [Direction](js-apis-enterprise-networkManager.md#direction) | 否    | 否 | 规则链。 |
| action        | [Action](js-apis-enterprise-networkManager.md#action) | 否    | 是 | 接收或者丢弃数据包。 |
| protocol | [Protocol](js-apis-enterprise-networkManager.md#protocol) | 否    | 是 | 网络协议。 |

## AddMethod

添加网络包方法。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统接口：** 此接口为系统接口。

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| APPEND | 0 | 追加。 |
| INSERT | 1 | 插入。 |
