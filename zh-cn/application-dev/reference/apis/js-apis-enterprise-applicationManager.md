# @ohos.enterprise.applicationManager（应用管理）

本模块提供应用管理能力，包括添加应用运行黑名单、获取应用运行黑名单、移除应用运行黑名单等。仅企业设备管理员应用才能调用。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import applicationManager from '@ohos.enterprise.applicationManager';
```

## applicationManager.addDisallowedRunningBundles

addDisallowedRunningBundles(admin: Want, appIds: Array\<string>, callback: AsyncCallback&lt;void&gt;): void;

指定设备管理员应用添加应用运行黑名单接口，使用callback形式返回是否添加成功。添加至黑名单的应用不允许在管理员用户下运行，否则允许运行。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_SET_APP_RUNNING_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)     | 是    | 设备管理员应用。                  |
| appIds    | Array&lt;string&gt;                | 是    | 应用运行的黑名单。                  |
| callback | AsyncCallback&lt;void&gt;            | 是    | 回调函数。当接口调用成功，err为null，否则为错误对象。 |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                       |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |


**示例：**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "EntryAbility",
};
let appIds = {"com.example.myapplication"};

applicationManager.addDisallowedRunningBundles(wantTemp, appIds, (error) => {
    if (error != null) {
        console.log("error code:" + error.code + " error message:" + error.message);
    }
});
```

## applicationManager.addDisallowedRunningBundles

addDisallowedRunningBundles(admin: Want, appIds: Array\<string>, userId: number, callback: AsyncCallback&lt;void&gt;): void;

指定设备管理员应用添加应用运行黑名单接口，使用callback形式返回是否添加成功。添加至黑名单的应用不允许在指定用户（通过userId指定）下运行，否则允许运行。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_SET_APP_RUNNING_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin    | [Want](js-apis-app-ability-want.md)     | 是    | 设备管理员应用。                  |
| appIds    | Array&lt;string&gt;                | 是    | 应用运行的黑名单。                  |
| userId     | number                             | 是    | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。 |
| callback | AsyncCallback&lt;void&gt;            | 是    | 回调函数，当接口调用成功，err为null，否则为错误对象。 |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                     |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "EntryAbility",
};
let appIds = {"com.example.myapplication"};

applicationManager.addDisallowedRunningBundles(wantTemp, appIds, 100, (error) => {
    if (error != null) {
        console.log("error code:" + error.code + " error message:" + error.message);
    }
});
```

## applicationManager.addDisallowedRunningBundles

addDisallowedRunningBundles(admin: Want, appIds: Array\<string>, userId?: number): Promise&lt;void&gt;;

指定设备管理员应用添加应用运行黑名单接口，使用promise形式返回是否添加成功。如果调用接口时传入了可选参数userId，则添加至黑名单的应用不允许在指定用户下运行，如果调用接口时没有传入参数userId，则添加至黑名单的应用不允许在当前用户下运行。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_SET_APP_RUNNING_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin    | [Want](js-apis-app-ability-want.md)     | 是    | 设备管理员应用。                  |
| appIds    | Array&lt;string&gt;                | 是    | 应用运行的黑名单。                  |
| userId     | number                             | 否    | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。 |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。当指定设备管理员应用添加应用运行黑名单失败时会抛出错误对象。  |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                     |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "EntryAbility",
};
let appIds = {"com.example.myapplication"};

applicationManager.addDisallowedRunningBundles(wantTemp, appIds, 100).then(() => {
    console.log("success");
}).catch(error => {
    console.log("error code:" + error.code + " error message:" + error.message);
});
```

## applicationManager.removeDisallowedRunningBundles

removeDisallowedRunningBundles(admin: Want, appIds: Array\<string>, callback: AsyncCallback&lt;void&gt;): void;

指定设备管理员应用移除应用运行黑名单接口，使用callback形式返回移除结果。在黑名单存在的情况下，在应用运行黑名单中的应用不允许在当前用户下运行。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_SET_APP_RUNNING_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)     | 是    | 设备管理员应用。                  |
| appIds    | Array&lt;string&gt;                | 是    | 应用运行的黑名单。                  |
| callback | AsyncCallback&lt;void&gt;            | 是    | 回调函数。当接口调用成功，err为null，否则为错误对象。 |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                       |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "EntryAbility",
};
let appIds = {"com.example.myapplication"};

applicationManager.removeDisallowedRunningBundles(wantTemp, appIds, (error) => {
    if (error != null) {
        console.log("error code:" + error.code + " error message:" + error.message);
    }
});
```

## applicationManager.removeDisallowedRunningBundles

removeDisallowedRunningBundles(admin: Want, appIds: Array\<string>, userId: number, callback: AsyncCallback&lt;void&gt;): void;

指定设备管理员应用移除应用运行黑名单接口，使用callback形式返回移除结果。在黑名单存在的情况下，在应用运行黑名单中的应用不允许在指定用户（通过userId指定）下运行。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_SET_APP_RUNNING_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin    | [Want](js-apis-app-ability-want.md)     | 是    | 设备管理员应用。                  |
| appIds    | Array&lt;string&gt;                | 是    | 应用运行的黑名单。                  |
| userId     | number                             | 是    | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。 |
| callback | AsyncCallback&lt;void&gt;            | 是    | 回调函数。当接口调用成功，err为null，否则为错误对象。 |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                     |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "EntryAbility",
};
let appIds = {"com.example.myapplication"};

applicationManager.removeDisallowedRunningBundles(wantTemp, appIds, 100, (error) => {
    if (error != null) {
        console.log("error code:" + error.code + " error message:" + error.message);
    }
});
```

## applicationManager.removeDisallowedRunningBundles

removeDisallowedRunningBundles(admin: Want, appIds: Array\<string>, userId?: number): Promise&lt;void&gt;;

指定设备管理员应用移除应用运行黑名单接口，使用promise形式返回移除结果。在黑名单存在的情况下，如果调用接口时传入参数userId，则在应用运行黑名单中的应用不允许在指定用户下运行，如果调用接口时没有传入参数userId，则在应用运行黑名单中的应用不允许在当前用户下运行。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_SET_APP_RUNNING_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin    | [Want](js-apis-app-ability-want.md)     | 是    | 设备管理员应用。                  |
| appIds    | Array&lt;string&gt;                | 是    | 应用运行的黑名单。                  |
| userId     | number                             | 否    | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。 |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。当指定设备管理员应用移除应用运行黑名单失败时会抛出错误对象。  |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                     |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "EntryAbility",
};
let appIds = {"com.example.myapplication"};

applicationManager.removeDisallowedRunningBundles(wantTemp, appIds, 100).then(() => {
    console.log("success");
}).catch(error => {
    console.log("error code:" + error.code + " error message:" + error.message);
});
```

## applicationManager.getDisallowedRunningBundles

getDisallowedRunningBundles(admin: Want, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void;

指定管理员应用获取管理员用户下的应用运行黑名单接口，使用callback形式返回获取应用运行黑名单。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_SET_APP_RUNNING_POLICY

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
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "EntryAbility",
};

applicationManager.getDisallowedRunningBundles(wantTemp, (error) => {
    if (error != null) {
        console.log("error code:" + error.code + " error message:" + error.message);
    }
});
```

## applicationManager.getDisallowedRunningBundles

getDisallowedRunningBundles(admin: Want, userId: number, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void;

指定管理员应用获取指定用户（通过userId指定）下的应用运行黑名单接口，使用callback形式返回获取应用运行黑名单。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_SET_APP_RUNNING_POLICY

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
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "EntryAbility",
};

applicationManager.getDisallowedRunningBundles(wantTemp, 100, (error) => {
    if (error != null) {
        console.log("error code:" + error.code + " error message:" + error.message);
    }
});
```

## applicationManager.getDisallowedRunningBundles

getDisallowedRunningBundles(admin: Want, userId?: number): Promise&lt;Array&lt;string&gt;&gt;;

如果调用接口时传入参数userId，指定管理员应用获取指定用户下应用运行黑名单接口，如果调用接口时没有传入参数userId，指定管理员应用获取当前用户下应用运行黑名单接口，使用promise形式返回获取应用运行黑名单。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_SET_APP_RUNNING_POLICY

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
| Promise&lt;Array&lt;string&gt;&gt; | Promise对象，返回管理员用户下的应用运行黑名单。 |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                     |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "EntryAbility",
};
applicationManager.getDisallowedRunningBundles(wantTemp, 100).then(() => {
    console.log("success");
}).catch(error => {
    console.log("error code:" + error.code + " error message:" + error.message);
});
```
