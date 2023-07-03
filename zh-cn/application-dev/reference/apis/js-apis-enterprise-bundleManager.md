# @ohos.enterprise.bundleManager（包管理）

本模块提供包管理能力，包括添加包安装白名单、获取包安装白名单、移除包安装白名单等。仅企业设备管理员应用才能调用。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口需激活为[设备管理员应用](js-apis-enterprise-adminManager.md#adminmanagerenableadmin)后才能调用，实现相应功能。

## 导入模块

```js
import bundleManager from '@ohos.enterprise.bundleManager';
```

## bundleManager.addAllowedInstallBundles

addAllowedInstallBundles(admin: Want, appIds: Array\<string>, callback: AsyncCallback&lt;void&gt;): void;

指定设备管理员应用添加包安装白名单接口，添加至白名单的应用允许在当前用户下安装，否则不允许安装，使用callback形式返回是否添加成功。

**需要权限：** ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)     | 是    | 设备管理员应用。                  |
| appIds    | Array&lt;string&gt;                | 是    | 应用ID数组。                  |
| callback | AsyncCallback&lt;void&gt;            | 是    | 回调函数。当接口调用成功，err为null，否则为错误对象。 |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                       |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                              |
| 9200002 | the administrator application does not have permission to manage the device.                                          |

**示例：**

```js
let wantTemp = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let appIds = ['com.example.myapplication'];

bundleManager.addAllowedInstallBundles(wantTemp, appIds, (err) => {
  if (err) {
    console.error(`Failed to add allowed install bundles. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in adding allowed install bundles');
});
```

## bundleManager.addAllowedInstallBundles

addAllowedInstallBundles(admin: Want, appIds: Array\<string>, userId: number, callback: AsyncCallback&lt;void&gt;): void;

指定设备管理员应用添加包安装白名单接口，添加至白名单的应用允许在指定用户（通过userId指定）下安装，否则不允许安装，使用callback形式返回是否添加成功。

**需要权限：** ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin    | [Want](js-apis-app-ability-want.md)     | 是    | 设备管理员应用。                  |
| appIds    | Array&lt;string&gt;                | 是    | 应用ID数组。                  |
| userId     | number                             | 是    | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。 |
| callback | AsyncCallback&lt;void&gt;            | 是    | 回调函数，当接口调用成功，err为null，否则为错误对象。 |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                     |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                              |
| 9200002 | the administrator application does not have permission to manage the device.                                          |

**示例：**

```js
let wantTemp = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let appIds = ['com.example.myapplication'];

bundleManager.addAllowedInstallBundles(wantTemp, appIds, 100, (err) => {
  if (err) {
    console.error(`Failed to add allowed install bundles. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in adding allowed install bundles');
});
```

## bundleManager.addAllowedInstallBundles

addAllowedInstallBundles(admin: Want, appIds: Array\<string>, userId?: number): Promise&lt;void&gt;;

指定设备管理员应用添加包安装白名单接口，如果调用接口时传入了可选参数userId，则添加至白名单的应用允许在指定用户下安装，如果调用接口时没有传入参数userId，则添加至白名单的应用允许在当前用户下安装，使用promise形式返回是否添加成功。

**需要权限：** ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin    | [Want](js-apis-app-ability-want.md)     | 是    | 设备管理员应用。                  |
| appIds    | Array&lt;string&gt;                | 是    | 应用ID数组。                  |
| userId     | number                             | 否    | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。 |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。当指定设备管理员应用添加包安装白名单失败时会抛出错误对象。  |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                     |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                              |
| 9200002 | the administrator application does not have permission to manage the device.                                          |

**示例：**

```js
let wantTemp = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let appIds = ['com.example.myapplication'];

bundleManager.addAllowedInstallBundles(wantTemp, appIds, 100).then(() => {
  console.info('Succeeded in adding allowed install bundles');
}).catch((err) => {
  console.error(`Failed to add allowed install bundles. Code is ${err.code}, message is ${err.message}`);
});
```

## bundleManager.removeAllowedInstallBundles

removeAllowedInstallBundles(admin: Want, appIds: Array\<string>, callback: AsyncCallback&lt;void&gt;): void;

指定设备管理员应用移除包安装白名单接口，在白名单存在的情况下，不在包安装白名单中的应用不允许在当前用户下安装，使用callback形式返回移除结果。

**需要权限：** ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)     | 是    | 设备管理员应用。                  |
| appIds    | Array&lt;string&gt;                | 是    | 应用ID数组。                  |
| callback | AsyncCallback&lt;void&gt;            | 是    | 回调函数。当接口调用成功，err为null，否则为错误对象。 |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                       |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                              |
| 9200002 | the administrator application does not have permission to manage the device.                                          |

**示例：**

```js
let wantTemp = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let appIds = ['com.example.myapplication'];

bundleManager.removeAllowedInstallBundles(wantTemp, appIds, (err) => {
  if (err) {
    console.error(`Failed to remove allowed install bundles. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in removing allowed install bundles');
});
```

## bundleManager.removeAllowedInstallBundles

removeAllowedInstallBundles(admin: Want, appIds: Array\<string>, userId: number, callback: AsyncCallback&lt;void&gt;): void;

指定设备管理员应用移除包安装白名单接口，在白名单存在的情况下，不在包安装白名单中的应用不允许在指定用户（通过userId指定）下安装，使用callback形式返回移除结果。

**需要权限：** ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin    | [Want](js-apis-app-ability-want.md)     | 是    | 设备管理员应用。                  |
| appIds    | Array&lt;string&gt;                | 是    | 应用ID数组。                  |
| userId     | number                             | 是    | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。 |
| callback | AsyncCallback&lt;void&gt;            | 是    | 回调函数。当接口调用成功，err为null，否则为错误对象。 |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                     |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                              |
| 9200002 | the administrator application does not have permission to manage the device.                                          |

**示例：**

```js
let wantTemp = {
    bundleName: 'com.example.myapplication',
    abilityName: 'EntryAbility',
};
let appIds = ['com.example.myapplication'];

bundleManager.removeAllowedInstallBundles(wantTemp, appIds, 100, (err) => {
  if (err) {
    console.error(`Failed to remove allowed install bundles. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in removing allowed install bundles');
});
```

## bundleManager.removeAllowedInstallBundles

removeAllowedInstallBundles(admin: Want, appIds: Array\<string>, userId?: number): Promise&lt;void&gt;;

指定设备管理员应用移除包安装白名单接口，在白名单存在的情况下，如果调用接口时传入参数userId，则不在包安装白名单中的应用不允许在指定用户下安装，如果调用接口时没有传入参数userId，则不在包安装白名单中的应用不允许在当前用户下安装，使用promise形式返回移除结果。

**需要权限：** ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin    | [Want](js-apis-app-ability-want.md)     | 是    | 设备管理员应用。                  |
| appIds    | Array\&lt;string&gt;                | 是    | 应用ID数组。                  |
| userId     | number                             | 否    | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。 |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。当指定设备管理员应用移除包安装白名单失败时会抛出错误对象。  |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                     |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                              |
| 9200002 | the administrator application does not have permission to manage the device.                                          |

**示例：**

```js
let wantTemp = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let appIds = ['com.example.myapplication'];

bundleManager.removeAllowedInstallBundles(wantTemp, appIds, 100).then(() => {
  console.info('Succeeded in removing allowed install bundles');
}).catch((err) => {
  console.error(`Failed to remove allowed install bundles. Code is ${err.code}, message is ${err.message}`);
});
```

## bundleManager.getAllowedInstallBundles

getAllowedInstallBundles(admin: Want, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void;

指定管理员应用获取当前用户下的包安装白名单接口，使用callback形式返回获取包安装白名单。

**需要权限：** ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)     | 是    | 设备管理员应用。                  |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;       | 是    | 回调函数，当接口调用成功，err为null，否则为错误对象。       |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                       |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                              |
| 9200002 | the administrator application does not have permission to manage the device.                                          |

**示例：**

```js
let wantTemp = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

bundleManager.getAllowedInstallBundles(wantTemp, (err, result) => {
  if (err) {
    console.error(`Failed to get allowed install bundles. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in getting allowed install bundles, result : ${JSON.stringify(result)}`);
});
```

## bundleManager.getAllowedInstallBundles

getAllowedInstallBundles(admin: Want, userId: number, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void;

指定管理员应用获取指定用户（通过userId指定）下的包安装白名单接口，使用callback形式返回获取包安装白名单。

**需要权限：** ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)     | 是    | 设备管理员应用。                  |
| userId     | number                             | 是    | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。 |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;       | 是    | 回调函数，当接口调用成功，err为null，否则为错误对象。       |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                       |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                              |
| 9200002 | the administrator application does not have permission to manage the device.                                          |

**示例：**

```js
let wantTemp = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

bundleManager.getAllowedInstallBundles(wantTemp, 100, (err, result) => {
  if (err) {
    console.error(`Failed to get allowed install bundles. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in getting allowed install bundles, result : ${JSON.stringify(result)}`);
});
```

## bundleManager.getAllowedInstallBundles

getAllowedInstallBundles(admin: Want, userId?: number): Promise&lt;Array&lt;string&gt;&gt;;

指定管理员应用获取指定用户或当前用户下包安装白名单接口，使用promise形式返回获取包安装白名单。如果调用接口时传入参数userId，表示获取指定用户下包安装白名单，如果调用接口没有传入参数userId，表示获取当前用户下包安装白名单。

**需要权限：** ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | 是    | 设备管理员应用。 |
| userId     | number                             | 否    | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。 |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise对象，返回当前用户下的包安装白名单。 |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                     |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                              |
| 9200002 | the administrator application does not have permission to manage the device.                                          |

**示例：**

```js
let wantTemp = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

bundleManager.getAllowedInstallBundles(wantTemp, 100).then((result) => {
  console.info(`Succeeded in getting allowed install bundles, result : ${JSON.stringify(result)}`);
}).catch((err) => {
  console.error(`Failed to get allowed install bundles. Code is ${err.code}, message is ${err.message}`);
});
```

## bundleManager.addDisallowedInstallBundles

addDisallowedInstallBundles(admin: Want, appIds: Array\<string>, callback: AsyncCallback&lt;void&gt;): void;

指定设备管理员应用添加包安装黑名单接口，添加至黑名单的应用不允许在当前用户下安装，使用callback形式返回是否添加成功。

**需要权限：** ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)     | 是    | 设备管理员应用。                  |
| appIds    | Array&lt;string&gt;                | 是    | 应用ID数组。                  |
| callback | AsyncCallback&lt;void&gt;            | 是    | 回调函数。当接口调用成功，err为null，否则为错误对象。 |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                       |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                              |
| 9200002 | the administrator application does not have permission to manage the device.                                          |

**示例：**

```js
let wantTemp = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let appIds = ['com.example.myapplication'];

bundleManager.addDisallowedInstallBundles(wantTemp, appIds, (err) => {
  if (err) {
    console.error(`Failed to add disallowed install bundles. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in adding disallowed install bundles');
});
```

## bundleManager.addDisallowedInstallBundles

addDisallowedInstallBundles(admin: Want, appIds: Array\<string>, userId: number, callback: AsyncCallback&lt;void&gt;): void;

指定设备管理员应用添加包安装黑名单接口，添加至黑名单的应用不允许在指定用户（通过userId指定）下安装，使用callback形式返回是否添加成功。

**需要权限：** ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin    | [Want](js-apis-app-ability-want.md)     | 是    | 设备管理员应用。                  |
| appIds    | Array&lt;string&gt;                | 是    | 应用ID数组。                  |
| userId     | number                             | 是    | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。 |
| callback | AsyncCallback&lt;void&gt;            | 是    | 回调函数，当接口调用成功，err为null，否则为错误对象。 |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                     |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                              |
| 9200002 | the administrator application does not have permission to manage the device.                                          |

**示例：**

```js
let wantTemp = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let appIds = ['com.example.myapplication'];

bundleManager.addDisallowedInstallBundles(wantTemp, appIds, 100, (err) => {
  if (err) {
    console.error(`Failed to add disallowed install bundles. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in adding disallowed install bundles');
});
```

## bundleManager.addDisallowedInstallBundles

addDisallowedInstallBundles(admin: Want, appIds: Array\<string>, userId?: number): Promise&lt;void&gt;;

指定设备管理员应用添加包安装黑名单接口。如果调用接口时传入了可选参数userId，则添加至黑名单的应用不允许在指定用户下安装；如果调用接口时没有传入参数userId，则添加至黑名单的应用不允许在当前用户下安装，使用promise形式返回是否添加成功。

**需要权限：** ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin    | [Want](js-apis-app-ability-want.md)     | 是    | 设备管理员应用。                  |
| appIds    | Array&lt;string&gt;                | 是    | 应用ID数组。                  |
| userId     | number                             | 否    | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。 |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。当指定设备管理员应用添加包安装黑名单失败时会抛出错误对象。  |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                     |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                              |
| 9200002 | the administrator application does not have permission to manage the device.                                          |

**示例：**

```js
let wantTemp = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let appIds = ['com.example.myapplication'];

bundleManager.addDisallowedInstallBundles(wantTemp, appIds, 100).then(() => {
  console.info('Succeeded in adding disallowed install bundles');
}).catch((err) => {
  console.error(`Failed to add disallowed install bundles. Code is ${err.code}, message is ${err.message}`);
});
```

## bundleManager.removeDisallowedInstallBundles

removeDisallowedInstallBundles(admin: Want, appIds: Array\<string>, callback: AsyncCallback&lt;void&gt;): void;

指定设备管理员应用移除包安装黑名单接口，在黑名单存在的情况下，在包安装黑名单中的应用不允许在当前用户下安装，使用callback形式返回移除结果。

**需要权限：** ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)     | 是    | 设备管理员应用。                  |
| appIds    | Array&lt;string&gt;                | 是    | 应用ID数组。                  |
| callback | AsyncCallback&lt;void&gt;            | 是    | 回调函数。当接口调用成功，err为null，否则为错误对象。 |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                       |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                              |
| 9200002 | the administrator application does not have permission to manage the device.                                          |

**示例：**

```js
let wantTemp = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let appIds = ['com.example.myapplication'];

bundleManager.removeDisallowedInstallBundles(wantTemp, appIds, (err) => {
  if (err) {
    console.error(`Failed to remove disallowed install bundles. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in removing disallowed install bundles');
});
```

## bundleManager.removeDisallowedInstallBundles

removeAllowedInstallBundles(admin: Want, appIds: Array\<string>, userId: number, callback: AsyncCallback&lt;void&gt;): void;

指定设备管理员应用移除包安装黑名单接口，在黑名单存在的情况下，在包安装黑名单中的应用不允许在指定用户（通过userId指定）下安装，使用callback形式返回移除结果。

**需要权限：** ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin    | [Want](js-apis-app-ability-want.md)     | 是    | 设备管理员应用。                  |
| appIds    | Array&lt;string&gt;                | 是    | 应用ID数组。                  |
| userId     | number                             | 是    | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。 |
| callback | AsyncCallback&lt;void&gt;            | 是    | 回调函数。当接口调用成功，err为null，否则为错误对象。 |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                     |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                              |
| 9200002 | the administrator application does not have permission to manage the device.                                          |

**示例：**

```js
let wantTemp = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let appIds = ['com.example.myapplication'];

bundleManager.removeDisallowedInstallBundles(wantTemp, appIds, 100, (err) => {
  if (err) {
    console.error(`Failed to remove disallowed install bundles. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in removing disallowed install bundles');
});
```

## bundleManager.removeDisallowedInstallBundles

removeDisallowedInstallBundles(admin: Want, appIds: Array\<string>, userId?: number): Promise&lt;void&gt;;

指定设备管理员应用移除包安装黑名单接口。在黑名单存在的情况下，如果调用接口时传入参数userId，则在包安装黑名单中的应用不允许在指定用户下安装；如果调用接口时没有传入参数userId，则在包安装黑名单中的应用不允许在当前用户下安装，使用promise形式返回移除结果。

**需要权限：** ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin    | [Want](js-apis-app-ability-want.md)     | 是    | 设备管理员应用。                  |
| appIds    | Array\&lt;string&gt;                | 是    | 应用ID数组。                  |
| userId     | number                             | 否    | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。 |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。当指定设备管理员应用移除包安装黑名单失败时会抛出错误对象。  |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                     |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                              |
| 9200002 | the administrator application does not have permission to manage the device.                                          |

**示例：**

```js
let wantTemp = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let appIds = ['com.example.myapplication'];

bundleManager.removeDisallowedInstallBundles(wantTemp, appIds, 100).then(() => {
  console.info('Succeeded in removing disallowed install bundles');
}).catch((err) => {
  console.error(`Failed to remove disallowed install bundles. Code is ${err.code}, message is ${err.message}`);
});
```

## bundleManager.getDisallowedInstallBundles

getDisallowedInstallBundles(admin: Want, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void;

指定管理员应用获取当前用户下的包安装黑名单接口，使用callback形式返回获取包安装黑名单。

**需要权限：** ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)     | 是    | 设备管理员应用。                  |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;       | 是    | 回调函数，当接口调用成功，err为null，否则为错误对象。       |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                       |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                              |
| 9200002 | the administrator application does not have permission to manage the device.                                          |

**示例：**

```js
let wantTemp = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

bundleManager.getDisallowedInstallBundles(wantTemp, (err, result) => {
  if (err) {
    console.error(`Failed to get disallowed install bundles. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in getting disallowed install bundles, result : ${JSON.stringify(result)}`);
});
```

## bundleManager.getDisallowedInstallBundles

getDisallowedInstallBundles(admin: Want, userId: number, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void;

指定管理员应用获取指定用户（通过userId指定）下的包安装黑名单接口，使用callback形式返回获取包安装黑名单。

**需要权限：** ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)     | 是    | 设备管理员应用。                  |
| userId     | number                             | 是    | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。 |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;       | 是    | 回调函数，当接口调用成功，err为null，否则为错误对象。       |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                       |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                              |
| 9200002 | the administrator application does not have permission to manage the device.                                          |

**示例：**

```js
let wantTemp = {
    bundleName: 'com.example.myapplication',
    abilityName: 'EntryAbility',
};

bundleManager.getDisallowedInstallBundles(wantTemp, 100, (err, result) => {
  if (err) {
    console.error(`Failed to get disallowed install bundles. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in getting disallowed install bundles, result : ${JSON.stringify(result)}`);
});
```

## bundleManager.getDisallowedInstallBundles

getDisallowedInstallBundles(admin: Want, userId?: number): Promise&lt;Array&lt;string&gt;&gt;;

指定管理员应用获取指定用户或当前用户下包安装黑名单接口，使用promise形式返回获取包安装黑名单。如果调用接口时传入参数userId，表示获取指定用户下包安装黑名单，如果调用接口没有传入参数userId，表示获取当前用户下包安装黑名单。

**需要权限：** ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | 是    | 设备管理员应用。 |
| userId     | number                             | 否    | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。 |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise对象，返回当前用户下的包安装白名单。 |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                     |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                              |
| 9200002 | the administrator application does not have permission to manage the device.                                          |

**示例：**

```js
let wantTemp = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

bundleManager.getDisallowedInstallBundles(wantTemp, 100).then((result) => {
  console.info(`Succeeded in getting disallowed install bundles, result : ${JSON.stringify(result)}`);
}).catch((err) => {
  console.error(`Failed to get disallowed install bundles. Code is ${err.code}, message is ${err.message}`);
});
```

## bundleManager.addDisallowedUninstallBundles

addDisallowedUninstallBundles(admin: Want, appIds: Array\<string>, callback: AsyncCallback&lt;void&gt;): void

指定设备管理员应用添加包卸载黑名单接口，添加至黑名单的应用不允许在当前用户下卸载，使用callback形式返回是否添加成功。

**需要权限：** ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)     | 是    | 设备管理员应用。                  |
| appIds    | Array&lt;string&gt;                | 是    | 应用ID数组。                  |
| callback | AsyncCallback&lt;void&gt;            | 是    | 回调函数。当接口调用成功，err为null，否则为错误对象。 |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                       |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                              |
| 9200002 | the administrator application does not have permission to manage the device.                                          |

**示例：**

```js
let wantTemp = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let appIds = ['com.example.myapplication'];

bundleManager.addDisallowedUninstallBundles(wantTemp, appIds, (err) => {
  if (err) {
    console.error(`Failed to add disallowed uninstall bundles. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in adding disallowed uninstall bundles');
});
```

## bundleManager.addDisallowedUninstallBundles

addDisallowedUninstallBundles(admin: Want, appIds: Array\<string>, userId: number, callback: AsyncCallback&lt;void&gt;): void

指定设备管理员应用添加包卸载黑名单接口，添加至黑名单的应用不允许在指定用户（通过userId指定）下卸载，使用callback形式返回是否添加成功。

**需要权限：** ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin    | [Want](js-apis-app-ability-want.md)     | 是    | 设备管理员应用。                  |
| appIds    | Array&lt;string&gt;                | 是    | 应用ID数组。                  |
| userId     | number                             | 是    | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。 |
| callback | AsyncCallback&lt;void&gt;            | 是    | 回调函数，当接口调用成功，err为null，否则为错误对象。 |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                     |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                              |
| 9200002 | the administrator application does not have permission to manage the device.                                          |

**示例：**

```js
let wantTemp = {
    bundleName: 'com.example.myapplication',
    abilityName: 'EntryAbility',
};
let appIds = ['com.example.myapplication'];

bundleManager.addDisallowedUninstallBundles(wantTemp, appIds, 100, (err) => {
  if (err) {
    console.error(`Failed to add disallowed uninstall bundles. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in adding disallowed uninstall bundles');
});
```

## bundleManager.addDisallowedUninstallBundles

addDisallowedUninstallBundles(admin: Want, appIds: Array\<string>, userId?: number): Promise&lt;void&gt;

指定设备管理员应用添加包卸载黑名单接口。如果调用接口时传入了可选参数userId，则添加至黑名单的应用不允许在指定用户下卸载；如果调用接口时没有传入参数userId，则添加至黑名单的应用不允许在当前用户下卸载，使用promise形式返回是否添加成功。

**需要权限：** ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin    | [Want](js-apis-app-ability-want.md)     | 是    | 设备管理员应用。                  |
| appIds    | Array&lt;string&gt;                | 是    | 应用ID数组。                  |
| userId     | number                             | 否    | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。 |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。当指定设备管理员应用添加包卸载黑名单失败时会抛出错误对象。  |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                     |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                              |
| 9200002 | the administrator application does not have permission to manage the device.                                          |

**示例：**

```js
let wantTemp = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let appIds = ['com.example.myapplication'];

bundleManager.addDisallowedUninstallBundles(wantTemp, appIds, 100).then(() => {
  console.info('Succeeded in adding disallowed uninstall bundles');
}).catch((err) => {
  console.error(`Failed to add disallowed uninstall bundles. Code is ${err.code}, message is ${err.message}`);
});
```

## bundleManager.removeDisallowedUninstallBundles

removeDisallowedUninstallBundles(admin: Want, appIds: Array\<string>, callback: AsyncCallback&lt;void&gt;): void

指定设备管理员应用移除包卸载黑名单接口，在黑名单存在的情况下，在包卸载黑名单中的应用不允许在当前用户下卸载，使用callback形式返回移除结果。

**需要权限：** ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)     | 是    | 设备管理员应用。                  |
| appIds    | Array&lt;string&gt;                | 是    | 应用ID数组。                  |
| callback | AsyncCallback&lt;void&gt;            | 是    | 回调函数。当接口调用成功，err为null，否则为错误对象。 |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                       |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                              |
| 9200002 | the administrator application does not have permission to manage the device.                                          |

**示例：**

```js
let wantTemp = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let appIds = ['com.example.myapplication'];

bundleManager.removeDisallowedUninstallBundles(wantTemp, appIds, (err) => {
  if (err) {
    console.error(`Failed to remove disallowed uninstall bundles. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in removing disallowed uninstall bundles');
});
```

## bundleManager.removeDisallowedUninstallBundles

removeDisallowedUninstallBundles(admin: Want, appIds: Array\<string>, userId: number, callback: AsyncCallback&lt;void&gt;): void

指定设备管理员应用移除包卸载黑名单接口，在黑名单存在的情况下，在包卸载黑名单中的应用不允许在指定用户（通过userId指定）下卸载，使用callback形式返回移除结果。

**需要权限：** ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin    | [Want](js-apis-app-ability-want.md)     | 是    | 设备管理员应用。                  |
| appIds    | Array&lt;string&gt;                | 是    | 应用ID数组。                  |
| userId     | number                             | 是    | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。 |
| callback | AsyncCallback&lt;void&gt;            | 是    | 回调函数。当接口调用成功，err为null，否则为错误对象。 |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                     |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                              |
| 9200002 | the administrator application does not have permission to manage the device.                                          |

**示例：**

```js
let wantTemp = {
    bundleName: 'com.example.myapplication',
    abilityName: 'EntryAbility',
};
let appIds = ['com.example.myapplication'];

bundleManager.removeDisallowedUninstallBundles(wantTemp, appIds, 100, (err) => {
  if (err) {
    console.error(`Failed to remove disallowed uninstall bundles. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in removing disallowed uninstall bundles');
});
```

## bundleManager.removeDisallowedUninstallBundles

removeDisallowedUninstallBundles(admin: Want, appIds: Array\<string>, userId?: number): Promise&lt;void&gt;

指定设备管理员应用移除包卸载黑名单接口。在黑名单存在的情况下，如果调用接口时传入参数userId，则在包卸载黑名单中的应用不允许在指定用户下卸载；如果调用接口时没有传入参数userId，则在包卸载黑名单中的应用不允许在当前用户下卸载，使用promise形式返回移除结果。

**需要权限：** ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin    | [Want](js-apis-app-ability-want.md)     | 是    | 设备管理员应用。                  |
| appIds    | Array\&lt;string&gt;                | 是    | 应用ID数组。                  |
| userId     | number                             | 否    | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。 |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。当指定设备管理员应用移除包卸载黑名单失败时会抛出错误对象。  |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                     |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                              |
| 9200002 | the administrator application does not have permission to manage the device.                                          |

**示例：**

```js
let wantTemp = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let appIds = ['com.example.myapplication'];

bundleManager.removeDisallowedUninstallBundles(wantTemp, appIds, 100).then(() => {
  console.info('Succeeded in removing disallowed uninstall bundles');
}).catch((err) => {
  console.error(`Failed to remove disallowed uninstall bundles. Code is ${err.code}, message is ${err.message}`);
});
```

## bundleManager.getDisallowedUninstallBundles

getDisallowedUninstallBundles(admin: Want, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

指定管理员应用获取当前用户下的包卸载黑名单接口，使用callback形式返回获取包卸载黑名单。

**需要权限：** ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)     | 是    | 设备管理员应用。                  |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;       | 是    | 回调函数，当接口调用成功，err为null，否则为错误对象。       |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                       |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                              |
| 9200002 | the administrator application does not have permission to manage the device.                                          |

**示例：**

```js
let wantTemp = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

bundleManager.getDisallowedUninstallBundles(wantTemp, (err, result) => {
  if (err) {
    console.error(`Failed to get disallowed uninstall bundles. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in getting disallowed uninstall bundles, result : ${JSON.stringify(result)}`);
});
```

## bundleManager.getDisallowedUninstallBundles

getDisallowedUninstallBundles(admin: Want, userId: number, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

指定管理员应用获取指定用户（通过userId指定）下的包卸载黑名单接口，使用callback形式返回获取包卸载黑名单。

**需要权限：** ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)     | 是    | 设备管理员应用。                  |
| userId     | number                             | 是    | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。 |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;       | 是    | 回调函数，当接口调用成功，err为null，否则为错误对象。       |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                       |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                              |
| 9200002 | the administrator application does not have permission to manage the device.                                          |

**示例：**

```js
let wantTemp = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

bundleManager.getDisallowedUninstallBundles(wantTemp, 100, (err, result) => {
  if (err) {
    console.error(`Failed to get disallowed uninstall bundles. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in getting disallowed uninstall bundles, result : ${JSON.stringify(result)}`);
});
```

## bundleManager.getDisallowedUninstallBundles

getDisallowedUninstallBundles(admin: Want, userId?: number): Promise&lt;Array&lt;string&gt;&gt;

指定管理员应用获取指定用户或当前用户下包卸载黑名单接口，使用promise形式返回获取包卸载黑名单。如果调用接口时传入参数userId，表示获取指定用户下包卸载黑名单，如果调用接口没有传入参数userId，表示获取当前用户下包卸载黑名单。

**需要权限：** ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | 是    | 设备管理员应用。 |
| userId     | number                             | 否    | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。 |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise对象，返回当前用户下的包卸载白名单。 |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                     |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                              |
| 9200002 | the administrator application does not have permission to manage the device.                                          |

**示例：**

```js
let wantTemp = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

bundleManager.getDisallowedUninstallBundles(wantTemp, 100).then((result) => {
  console.info(`Succeeded in getting disallowed uninstall bundles, result : ${JSON.stringify(result)}`);
}).catch((err) => {
  console.error(`Failed to get disallowed uninstall bundles. Code is ${err.code}, message is ${err.message}`);
});
```

## bundleManager.uninstall

uninstall(admin: Want, bundleName: string, callback: AsyncCallback&lt;void&gt;): void

指定管理员应用卸载当前用户下的指定包接口，且不保留包数据，使用callback异步回调。

**需要权限：** ohos.permission.ENTERPRISE_INSTALL_BUNDLE

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)     | 是    | 设备管理员应用。                  |
| bundleName     | string                             | 是    | 包名。 |
| callback | AsyncCallback&lt;void&gt;       | 是    | 回调函数，当接口调用成功，err为null，否则为错误对象。       |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                       |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                              |
| 9200002 | the administrator application does not have permission to manage the device.                                          |

**示例：**

```js
let wantTemp = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

bundleManager.uninstall(wantTemp, 'bundleName', (err) => {
  if (err) {
    console.error(`Failed to uninstall bundles. Code is ${err.code}, message is ${err.message}`);
  }
  console.info('Succeeded in uninstalling bundles');
});
```

## bundleManager.uninstall

uninstall(admin: Want, bundleName: string, userId: number, callback: AsyncCallback&lt;void&gt;): void

指定管理员应用卸载指定用户下（由参数userId指定）的指定包接口，且不保留包数据，使用callback异步回调。

**需要权限：** ohos.permission.ENTERPRISE_INSTALL_BUNDLE

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)     | 是    | 设备管理员应用。                  |
| bundleName     | string                             | 是    | 包名。 |
| userId     | number                             | 是    | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。 |
| callback | AsyncCallback&lt;void&gt;       | 是    | 回调函数，当接口调用成功，err为null，否则为错误对象。       |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                       |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                              |
| 9200002 | the administrator application does not have permission to manage the device.                                          |

**示例：**

```js
let wantTemp = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

bundleManager.uninstall(wantTemp, 'bundleName', 100, (err) => {
  if (err) {
    console.error(`Failed to uninstall bundles. Code is ${err.code}, message is ${err.message}`);
  }
  console.info('Succeeded in uninstalling bundles');
});
```

## bundleManager.uninstall

uninstall(admin: Want, bundleName: string, isKeepData: boolean, callback: AsyncCallback&lt;void&gt;): void

指定管理员应用卸载当前用户下的指定包接口，使用callback异步回调。若isKeepData为false时，表示不保留包数据，若isKeepData为true，则表示保留包数据。

**需要权限：** ohos.permission.ENTERPRISE_INSTALL_BUNDLE

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)     | 是    | 设备管理员应用。                  |
| bundleName     | string                             | 是    | 包名。 |
| isKeepData     | boolean                             | 是    | 是否保留包数据，true表示保留，false表示不保留。 |
| callback | AsyncCallback&lt;void&gt;       | 是    | 回调函数，当接口调用成功，err为null，否则为错误对象。       |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                       |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                              |
| 9200002 | the administrator application does not have permission to manage the device.                                          |

**示例：**

```js
let wantTemp = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

bundleManager.uninstall(wantTemp, 'bundleName', true, (err) => {
  if (err) {
    console.error(`Failed to uninstall bundles. Code is ${err.code}, message is ${err.message}`);
  }
  console.info('Succeeded in uninstalling bundles');
});
```

## bundleManager.uninstall

uninstall(admin: Want, bundleName: string, userId: number, isKeepData: boolean, callback: AsyncCallback&lt;void&gt;): void

指定管理员应用卸载指定用户下（由参数userId指定）的指定包接口，使用callback异步回调。若isKeepData为false时，表示不保留包数据，若isKeepData为true，则表示保留包数据。

**需要权限：** ohos.permission.ENTERPRISE_INSTALL_BUNDLE

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)     | 是    | 设备管理员应用。                  |
| bundleName     | string                             | 是    | 包名。 |
| userId     | number                             | 是    | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。 |
| isKeepData     | boolean                             | 是    | 是否保留包数据，true表示保留，false表示不保留。 |
| callback | AsyncCallback&lt;void&gt;       | 是    | 回调函数，当接口调用成功，err为null，否则为错误对象。       |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                       |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                              |
| 9200002 | the administrator application does not have permission to manage the device.                                          |

**示例：**

```js
let wantTemp = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

bundleManager.uninstall(wantTemp, 'bundleName', 100, true, (err) => {
  if (err) {
    console.error(`Failed to uninstall bundles. Code is ${err.code}, message is ${err.message}`);
  }
  console.info('Succeeded in uninstalling bundles');
});
```

## bundleManager.uninstall

uninstall(admin: Want, bundleName: string, userId?: number, isKeepData?: boolean): Promise&lt;void&gt;

指定管理员应用卸载指定用户下的指定包接口，使用promise异步回调。若调用接口时填写参数userId，则表示卸载该指定用户下的包，若未填写参数userId，表示卸载当前用户下的包。若isKeepData为false时，表示不保留包数据，若isKeepData为true，则表示保留包数据；不填写该参数则默认isKeepData为false，即默认不保留包数据。

**需要权限：** ohos.permission.ENTERPRISE_INSTALL_BUNDLE

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | 是    | 设备管理员应用。 |
| bundleName     | string                             | 是    | 包名。 |
| userId     | number                             | 否    | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。 |
| isKeepData     | boolean                             | 否    | 是否保留包数据，true表示保留，false表示不保留。 |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。当包卸载失败时抛出错误对象。 |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                     |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                              |
| 9200002 | the administrator application does not have permission to manage the device.                                          |

**示例：**

```js
let wantTemp = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

bundleManager.uninstall(wantTemp, 'bundleName', 100, true).then(() => {
  console.info('Succeeded in uninstalling bundles');
}).catch((err) => {
  console.error(`Failed to uninstall bundles. Code is ${err.code}, message is ${err.message}`);
});
```