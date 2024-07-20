# @ohos.enterprise.adminManager (企业设备管理)

本模块提供企业设备管理能力，使设备具备企业场景下所需的定制能力。

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅对[设备管理应用](../../mdm/mdm-kit-guide.md#功能介绍)开放，实现相应功能。

## 导入模块

```ts
import { adminManager } from '@kit.MDMKit';
```

## adminManager.disableAdmin

disableAdmin(admin: Want, userId?: number): Promise\<void>

将当前/指定用户下指定的普通管理应用去激活。使用promise异步回调。

**需要权限：** ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**模型约束**: 此接口仅可在Stage模型下使用。

**参数**：

| 参数名 | 类型                                                    | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 普通设备管理应用。                                           |
| userId | number                                                  | 否   | 用户ID， 取值范围：大于等于0。<br> - 调用接口时，若传入userId，表示指定用户。<br> - 调用接口时，若未传入userId，表示当前用户。 |

**返回值：**

| 类型           | 说明                                                         |
| -------------- | ------------------------------------------------------------ |
| Promise\<void> | 无返回结果的Promise对象。当去激活普通管理应用失败时，会抛出错误对象。 |

**错误码**:

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200005  | Failed to deactivate the administrator application of the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例**：

```ts
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
let wantTemp: Want = {
  bundleName: 'bundleName',
  abilityName: 'abilityName',
};

adminManager.disableAdmin(wantTemp, 100).catch((err: BusinessError) => {
  console.error(`Failed to disable admin. Code: ${err.code}, message: ${err.message}`);
});
```

## adminManager.subscribeManagedEventSync

subscribeManagedEventSync(admin: Want, managedEvents: Array\<ManagedEvent>): void

指定的设备管理应用订阅系统管理事件。

**需要权限：** ohos.permission.ENTERPRISE_SUBSCRIBE_MANAGED_EVENT

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**模型约束**: 此接口仅可在Stage模型下使用。

**参数：**

| 参数名        | 类型                                                    | 必填 | 说明           |
| ------------- | ------------------------------------------------------- | ---- | -------------- |
| admin         | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 设备管理应用。 |
| managedEvents | Array\<[ManagedEvent](#managedevent)>                   | 是   | 订阅事件数组。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200008  | The specified system event is invalid.                       |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
let wantTemp: Want = {
  bundleName: 'bundleName',
  abilityName: 'abilityName',
};
let events: Array<adminManager.ManagedEvent> = [adminManager.ManagedEvent.MANAGED_EVENT_BUNDLE_ADDED, adminManager.ManagedEvent.MANAGED_EVENT_BUNDLE_REMOVED];

try {
  adminManager.subscribeManagedEventSync(wantTemp, events);
  console.info('Succeeded in subscribe managed event.');
} catch (err) {
  console.error(`Failed to subscribe managed event. Code: ${err.code}, message: ${err.message}`);
}
```

## adminManager.unsubscribeManagedEventSync

unsubscribeManagedEventSync(admin: Want, managedEvents: Array\<ManagedEvent>): void

指定的设备管理应用取消订阅系统管理事件。

**需要权限：** ohos.permission.ENTERPRISE_SUBSCRIBE_MANAGED_EVENT

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**模型约束**: 此接口仅可在Stage模型下使用。

**参数：**

| 参数名        | 类型                                                    | 必填 | 说明               |
| ------------- | ------------------------------------------------------- | ---- | ------------------ |
| admin         | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 设备管理应用。     |
| managedEvents | Array\<[ManagedEvent](#managedevent)>                   | 是   | 取消订阅事件数组。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200008  | The specified system event is invalid.                       |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
let wantTemp: Want = {
  bundleName: 'bundleName',
  abilityName: 'abilityName',
};
let events: Array<adminManager.ManagedEvent> = [adminManager.ManagedEvent.MANAGED_EVENT_BUNDLE_ADDED, adminManager.ManagedEvent.MANAGED_EVENT_BUNDLE_REMOVED];

try {
  adminManager.unsubscribeManagedEventSync(wantTemp, events);
  console.info('Succeeded in subscribe managed event.');
} catch (err) {
  console.error(`Failed to subscribe managed event. Code: ${err.code}, message: ${err.message}`);
}
```

## ManagedEvent

可订阅的系统管理事件。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



| 名称                         | 值   | 说明           |
| ---------------------------- | ---- | -------------- |
| MANAGED_EVENT_BUNDLE_ADDED   | 0    | 应用安装事件。 |
| MANAGED_EVENT_BUNDLE_REMOVED | 1    | 应用卸载事件。 |
| MANAGED_EVENT_APP_START      | 2    | 应用启动事件。 |
| MANAGED_EVENT_APP_STOP       | 3    | 应用停止事件。 |
| MANAGED_EVENT_SYSTEM_UPDATE  | 4    | 系统更新事件。 |
