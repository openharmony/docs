# @ohos.enterprise.deviceSettings (Device Settings) (System API)

The **deviceSettings** module provides APIs for setting enterprise devices, including obtaining the screen-off time of a device.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.
>
> The APIs of this module can be called only by a [device administrator application](../../mdm/mdm-kit-guide.md#introduction) that is [enabled](js-apis-enterprise-adminManager-sys.md#adminmanagerenableadmin).
> 
> This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.enterprise.deviceSettings](js-apis-enterprise-deviceSettings.md).

## Modules to Import

```ts
import { deviceSettings } from '@kit.MDMKit';
```

## deviceSettings.setScreenOffTime<sup>11+</sup>

setScreenOffTime(admin: Want, time: number): void

Sets the device screen-off time through the specified device administrator application. This API returns the result synchronously. If the operation is successful, **null** is returned. If the operation fails, an exception will be thrown.

**Required permissions**: ohos.permission.ENTERPRISE_SET_SCREENOFF_TIME

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | Yes   | Device administrator application.                 |
| time | number            | Yes   | Screen-off time to set, in milliseconds. You are advised to set this parameter to the device's optional screen-off time.      |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.            |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
try {
  deviceSettings.setScreenOffTime(wantTemp, 30000);
  console.info(`Succeeded in setting screen off time`);
} catch(err) {
  console.error(`Failed to set screen off time. Code: ${err.code}, message: ${err.message}`);
}
```

## deviceSettings.getScreenOffTime

getScreenOffTime(admin: Want, callback: AsyncCallback&lt;number&gt;): void

Obtains the device screen-off time through the specified device administrator application. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_GET_SETTINGS

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | Yes   | Device administrator application.                 |
| callback | AsyncCallback&lt;number&gt;            | Yes   | Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the screen-off time in ms. If the operation fails, **err** is an error object.      |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.            |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

deviceSettings.getScreenOffTime(wantTemp, (err, result) => {
  if (err) {
    console.error(`Failed to get screen off time. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info(`Succeeded in getting screen off time, result : ${result}`);
});
```

## deviceSettings.getScreenOffTime

getScreenOffTime(admin: Want): Promise&lt;number&gt;

Obtains the device screen-off time through the specified device administrator application. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_GET_SETTINGS

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes   | Device administrator application.|

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;number&gt; | Promise used to return the screen-off time, in ms. |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.            |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

deviceSettings.getScreenOffTime(wantTemp).then((result) => {
  console.info(`Succeeded in getting screen off time, result : ${result}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to get screen off time. Code: ${err.code}, message: ${err.message}`);
});
```

## deviceSettings.installUserCertificate

installUserCertificate(admin: Want, certificate: CertBlob, callback: AsyncCallback&lt;string&gt;): void

Installs a user certificate through the specified device administrator application. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_CERTIFICATE

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | Yes   | Device administrator application.                 |
| certificate    | [CertBlob](#certblob)     | Yes   | Information about the certificate to install.                 |
| callback | AsyncCallback&lt;string&gt;            | Yes   | Callback used to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.     |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.            |
| 9200002 | The administrator application does not have permission to manage the device. |
| 9201001 | Failed to manage the certificate. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let certFileArray: Uint8Array = new Uint8Array();
// The variable context needs to be initialized in MainAbility's onCreate callback function
// test.cer needs to be placed in the rawfile directory
getContext().resourceManager.getRawFileContent("test.cer").then((value) => {
  certFileArray = value;
  deviceSettings.installUserCertificate(wantTemp, { inData: certFileArray, alias: "cert_alias_xts" }, (err, result) => {
    if (err) {
      console.error(`Failed to install user certificate. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in installing user certificate, result : ${JSON.stringify(result)}`);
    }
  });
}).catch((error: BusinessError) => {
  console.error(`Failed to get row file content. message: ${error.message}`);
  return
});
```

## deviceSettings.installUserCertificate

installUserCertificate(admin: Want, certificate: CertBlob): Promise&lt;string&gt;

Installs a user certificate through the specified device administrator application. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_CERTIFICATE

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes   | Device administrator application.|
| certificate    | [CertBlob](#certblob)     | Yes   | Information about the certificate to install.                 |

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;string&gt; | Promise used to return the URI of the installed certificate. This URI can be used to uninstall the certificate.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.            |
| 9200002 | The administrator application does not have permission to manage the device. |
| 9201001 | Failed to manage the certificate. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let certFileArray: Uint8Array = new Uint8Array();
// The variable context needs to be initialized in MainAbility's onCreate callback function
// test.cer needs to be placed in the rawfile directory
getContext().resourceManager.getRawFileContent("test.cer").then((value) => {
  certFileArray = value
  deviceSettings.installUserCertificate(wantTemp, { inData: certFileArray, alias: "cert_alias_xts" })
    .then((result) => {
      console.info(`Succeeded in installing user certificate, result : ${JSON.stringify(result)}`);
    }).catch((err: BusinessError) => {
    console.error(`Failed to install user certificate. Code: ${err.code}, message: ${err.message}`);
  })
}).catch((error: BusinessError) => {
  console.error(`Failed to get row file content. message: ${error.message}`);
  return
});
```

## CertBlob

Represents the certificate information.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

| Name        | Type    | Mandatory| Description                           |
| ----------- | --------| ----- | ------------------------------- |
| inData | Uint8Array | Yes| Binary content of the certificate.|
| alias | string | Yes| Certificate alias.|

## deviceSettings.uninstallUserCertificate

uninstallUserCertificate(admin: Want, certUri: string, callback: AsyncCallback&lt;void&gt;): void

Uninstalls a user certificate through the specified device administrator application. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_CERTIFICATE

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | Yes   | Device administrator application.                 |
| certUri    | string    | Yes   | Certificate URI, which is returned by **installUserCertificate()**.                 |
| callback | AsyncCallback&lt;void&gt;            | Yes   | Callback used to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.     |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.            |
| 9200002 | The administrator application does not have permission to manage the device. |
| 9201001 | Failed to manage the certificate. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let aliasStr = "certName"
deviceSettings.uninstallUserCertificate(wantTemp, aliasStr, (err) => {
  if (err) {
    console.error(`Failed to uninstall user certificate. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info(`Succeeded in uninstalling user certificate`);
});
```

## deviceSettings.uninstallUserCertificate

uninstallUserCertificate(admin: Want, certUri: string): Promise&lt;void&gt;

Uninstalls a user certificate through the specified device administrator application. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_CERTIFICATE

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes   | Device administrator application.|
| certUri    | string     | Yes   | Certificate URI, which is returned by **installUserCertificate()**.                 |

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value. An error object will be thrown if the operation fails.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.            |
| 9200002 | The administrator application does not have permission to manage the device. |
| 9201001 | Failed to manage the certificate. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let aliasStr = "certName"
deviceSettings.uninstallUserCertificate(wantTemp, aliasStr).then(() => {
  console.info(`Succeeded in uninstalling user certificate`);
}).catch((err: BusinessError) => {
  console.error(`Failed to uninstall user certificate. Code is ${err.code}, message is ${err.message}`);
});
```

## deviceSettings.setPowerPolicy<sup>11+</sup>

setPowerPolicy(admin: Want, powerScene: PowerScene, powerPolicy: PowerPolicy): void

Sets the device power policy through the specified device administrator application. This API returns the result synchronously. If the operation is successful, **null** is returned. If the operation fails, an exception will be thrown.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_SETTINGS

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | Yes   | Device administrator application.                 |
| powerScene | [PowerScene](#powerscene11) | Yes   | Scenario to which the power policy applies. Currently, only the timeout scenario is supported.      |
| powerPolicy | [PowerPolicy](#powerpolicy11) | Yes   | Power policy to set.      |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.            |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
try {
  let delayTime = 0;
  let powerScene: deviceSettings.PowerScene = deviceSettings.PowerScene.TIME_OUT;
  let powerPolicyAction: deviceSettings.PowerPolicyAction = deviceSettings.PowerPolicyAction.AUTO_SUSPEND;
  let powerPolicy: deviceSettings.PowerPolicy = {powerPolicyAction, delayTime};
  deviceSettings.setPowerPolicy(wantTemp, powerScene, powerPolicy);
  console.info(`Succeeded in setting power polilcy`);
} catch (err) {
  console.error(`Failed to set power policy. Code: ${err.code}, message: ${err.message}`);
}
```

## deviceSettings.getPowerPolicy<sup>11+</sup>

getPowerPolicy(admin: Want, powerScene: PowerScene): PowerPolicy

Obtains the device power policy through the specified device administrator application. This API returns the result synchronously. If the operation is successful, the power policy obtained is returned. If the operation fails, an exception will be thrown.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_SETTINGS

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | Yes   | Device administrator application.                 |
| powerScene | [PowerScene](#powerscene11) | Yes   | Scenario to which the power policy applies. Currently, only the timeout scenario is supported.      |

**Return value**

| Type  | Description                                 | Description                      |
| ----- | ----------------------------------- |------------------------------- |
| PowerPolicy | [PowerPolicy](#powerpolicy11) |   Power policy obtained.      |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.            |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
try {
  let powerScene: deviceSettings.PowerScene = deviceSettings.PowerScene.TIME_OUT;
  let powerPolicy: deviceSettings.PowerPolicy = deviceSettings.getPowerPolicy(wantTemp, powerScene);
  console.info(`Succeeded in getting power polilcy ${JSON.stringify(powerPolicy)}`);
} catch (err) {
  console.error(`Failed to get power policy. Code: ${err.code}, message: ${err.message}`);
}
```

## PowerPolicy<sup>11+</sup>

Represents the power policy.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

| Name        | Type    | Mandatory| Description                           |
| ----------- | --------| ----- | ------------------------------- |
| powerPolicyAction | [PowerPolicyAction](#powerpolicyaction11) | Yes| Action to apply the power policy.|
| delayTime | number | Yes| Delay time allowed.|

## PowerScene<sup>11+</sup>

Defines the scenario to which the power policy applies.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

| Name| Value| Description|
| -------- | -------- | -------- |
| TIME_OUT | 0 | Timeout scenario.|

## PowerPolicyAction<sup>11+</sup>

Enumerates the actions that can be performed to apply the power policy.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

| Name| Value| Description|
| -------- | -------- | -------- |
| NONE | 0 | No action is performed.|
| AUTO_SUSPEND | 1 | Automatically enter the sleep mode.|
| FORCE_SUSPEND | 2 | Forcibly enter the sleep mode.|
| HIBERNATE | 3 | Enter the hibernation state. Currently, the power subsystem does not support this action.|
| SHUTDOWN | 4 | Shut down the system.|
