# @ohos.enterprise.deviceControl（设备控制管理）(系统接口)
<!--Kit: MDM Kit-->
<!--Subsystem: Customization-->
<!--Owner: @huanleima-->
<!--Designer: @liuzuming-->
<!--Tester: @lpw_work-->
<!--Adviser: @Brilliantry_Rui-->

本模块提供设备控制能力。

> **说明**：
> 
> 本模块首批接口从API version 10 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 本模块接口仅对[设备管理应用](../../mdm/mdm-kit-term.md#mdm应用设备管理应用)开放，需将[设备管理应用激活](js-apis-enterprise-adminManager-sys.md#adminmanagerenableadmin-2)后调用。
> 
> 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.enterprise.deviceControl](js-apis-enterprise-deviceControl.md)。

## 导入模块

```ts
import { deviceControl } from '@kit.MDMKit';
```

## deviceControl.resetFactory

resetFactory(admin: Want, callback: AsyncCallback\<void>): void

使设备恢复出厂设置。使用callback异步回调。

**需要权限：** ohos.permission.ENTERPRISE_RESET_DEVICE

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是    | 企业设备管理扩展组件。 |
| callback | AsyncCallback\<void> | 是 | 回调函数。当接口调用成功，err为null，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.           |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { deviceControl } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};

deviceControl.resetFactory(wantTemp, (err) => {
  if (err) {
    console.error(`Failed to reset factory. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.log('Succeeded in resetting factory');
})
```

## deviceControl.resetFactory

resetFactory(admin: Want): Promise\<void>

使设备恢复出厂设置。使用Promise异步回调。

**需要权限：** ohos.permission.ENTERPRISE_RESET_DEVICE

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是    | 企业设备管理扩展组件。 |

**返回值：**

| 类型   | 说明                                  |
| ----- | ----------------------------------- |
| Promise\<void> | 无返回结果的Promise对象。当恢复出厂设置失败时抛出错误对象。|

**错误码：**

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.            |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { deviceControl } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};

deviceControl.resetFactory(wantTemp).then(() => {
}).catch((err: BusinessError) => {
  console.error(`Failed to reset factory. Code is ${err.code}, message is ${err.message}`);
})
```

## deviceControl.shutdown<sup>11+</sup>

shutdown(admin: Want): void

使设备关机。

**需要权限：** ohos.permission.ENTERPRISE_REBOOT

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是    | 企业设备管理扩展组件。 |

**错误码：**

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.            |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { deviceControl } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};

try {
  deviceControl.shutdown(wantTemp);
} catch (err) {
  console.error(`Failed to shutdown device. Code is ${err.code}, message is ${err.message}`);
}
```

## deviceControl.reboot<sup>11+</sup>

reboot(admin: Want): void

使设备重启。

**需要权限：** ohos.permission.ENTERPRISE_REBOOT

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是    | 企业设备管理扩展组件。 |

**错误码：**

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.            |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { deviceControl } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};

try {
  deviceControl.reboot(wantTemp);
} catch (err) {
  console.error(`Failed to reboot device. Code is ${err.code}, message is ${err.message}`);
}
```

## deviceControl.lockScreen<sup>11+</sup>

lockScreen(admin: Want): void

使设备屏幕锁定。设置之后设备立即锁屏。

**需要权限：** ohos.permission.ENTERPRISE_LOCK_DEVICE

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是    | 企业设备管理扩展组件。 |

**错误码：**

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.            |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { deviceControl } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};

try {
  deviceControl.lockScreen(wantTemp);
} catch (err) {
  console.error(`Failed to lock screen. Code is ${err.code}, message is ${err.message}`);
}
```