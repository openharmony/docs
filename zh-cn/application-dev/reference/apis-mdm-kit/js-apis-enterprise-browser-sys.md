# @ohos.enterprise.browser（浏览器管理）(系统接口)

本模块提供浏览器管理能力，包括设置/取消浏览器策略、获取浏览器策略等。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 本模块接口仅对[设备管理应用](../../mdm/mdm-kit-guide.md#功能介绍)开放，需将[设备管理应用激活](js-apis-enterprise-adminManager-sys.md#adminmanagerenableadmin)后调用，实现相应功能。
> 
> 当前页面仅包含本模块的系统接口，其他公开接口参见。其他公开接口参见[@ohos.enterprise.browser](js-apis-enterprise-browser.md)。

## 导入模块

```ts
import { browser } from '@kit.MDMKit';
```

## browser.setPolicies

setPolicies(admin: Want, appId: string, policies: string, callback: AsyncCallback&lt;void&gt;): void

为指定的浏览器设置浏览策略，使用callback异步回调。

**需要权限：** ohos.permission.ENTERPRISE_SET_BROWSER_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager


**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | 是    | 企业设备管理扩展组件。            |
| appId    | string              | 是    | 应用ID，用于指定浏览器。                  |
| policies    | string              | 是    | 浏览器策略，当参数policies为空字符串时，表示取消指定浏览器的策略。                  |
| callback | AsyncCallback&lt;void&gt;            | 是    | 回调函数。当接口调用成功，err为null，否则为错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                       |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                  |
| 9200002 | The administrator application does not have permission to manage the device.                                          |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
// 此处参数appId的赋值应替换为开发者自己指定的浏览器的应用ID
let appId: string = 'com.example.******_******/******5t5CoBM=';
let policies: string = '{"InsecurePrivateNetworkRequestsAllowed":{"level":"mandatory","scope":"machine","source":"platform","value":true},"LegacySameSiteCookieBehaviorEnabledForDomainList":{"level":"mandatory","scope":"machine","source":"platform","value":["[*.]"]}}';
browser.setPolicies(wantTemp, appId, policies, (err) => {
  if (err) {
    console.error(`Failed to set browser policies. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in setting browser policies.');
});
```

## browser.setPolicies

setPolicies(admin: Want, appId: string, policies: string): Promise&lt;void&gt;

为指定的浏览器设置浏览策略，使用promise异步回调。

**需要权限：** ohos.permission.ENTERPRISE_SET_BROWSER_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager


**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | 是    | 企业设备管理扩展组件。            |
| appId    | string              | 是    | 应用ID，用于指定浏览器。                  |
| policies    | string                | 是    | 浏览器策略，当参数policies为空字符串时，表示取消指定浏览器的策略。                  |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。当设置浏览器策略失败时，会抛出错误对象。  |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                  |
| 9200002 | The administrator application does not have permission to manage the device.                                          |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
// 此处参数appId的赋值应替换为开发者自己指定的浏览器的应用ID
let appId: string = 'com.example.******_******/******5t5CoBM=';
let policies: string = '{"InsecurePrivateNetworkRequestsAllowed":{"level":"mandatory","scope":"machine","source":"platform","value":true},"LegacySameSiteCookieBehaviorEnabledForDomainList":{"level":"mandatory","scope":"machine","source":"platform","value":["[*.]"]}}';
browser.setPolicies(wantTemp, appId, policies).then(() => {
  console.info('Succeeded in setting browser policies.');
}).catch((err: BusinessError) => {
  console.error(`Failed to set browser policies. Code is ${err.code}, message is ${err.message}`);
});
```

## browser.getPolicies

getPolicies(admin: Want, appId: string, callback: AsyncCallback&lt;string&gt;): void

获取指定浏览器的策略，使用callback异步回调。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager


**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | 是    | 企业设备管理扩展组件。            |
| appId    | string              | 是    | 应用ID，用于指定浏览器。                  |
| callback | AsyncCallback&lt;string&gt;       | 是    | 回调函数，当接口调用成功，err为null，否则为错误对象。       |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                       |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                  |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
// 此处参数appId的赋值应替换为开发者自己指定的浏览器的应用ID
let appId: string = 'com.example.******_******/******5t5CoBM=';
browser.getPolicies(wantTemp, appId, (err, result) => {
  if (err) {
    console.error(`Failed to get browser policies. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in getting  browser policies, result : ${JSON.stringify(result)}`);
});
```

## browser.getPolicies

getPolicies(admin: Want, appId: string): Promise&lt;string&gt;

获取指定浏览器的策略，使用promise异步回调。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager


**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是    | 企业设备管理扩展组件。 |
| appId    | string              | 是    | 应用ID，用于指定浏览器。                  |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;string&gt; | Promise对象，返回浏览器策略。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                  |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
// 此处参数appId的赋值应替换为开发者自己指定的浏览器的应用ID
let appId: string = 'com.example.******_******/******5t5CoBM=';
browser.getPolicies(wantTemp, appId).then((result) => {
  console.info(`Succeeded in getting browser policies, result : ${JSON.stringify(result)}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to get browser policies. Code is ${err.code}, message is ${err.message}`);
});
```
