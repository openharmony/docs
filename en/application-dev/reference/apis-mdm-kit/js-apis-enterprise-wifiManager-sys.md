# @ohos.enterprise.wifiManager (Wi-Fi Management) (System API)
<!--Kit: MDM Kit-->
<!--Subsystem: Customization-->
<!--Owner: @huanleima; @weizai16-->
<!--Designer: @hp_guo-->
<!--Tester: @lpw_work-->
<!--Adviser: @zhang_yixin13-->

The **wifiManager** module provides Wi-Fi management capabilities for enterprise devices, including obtaining the Wi-Fi status.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.
>
> The APIs of this module are available only to [MDM applications](../../mdm/mdm-kit-term.md#mdm-application-device-administrator-application), and can be called only after the device administrator application is activated via [enableAdmin](js-apis-enterprise-adminManager-sys.md#adminmanagerenableadmin-2).
>
> This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.enterprise.wifiManager](js-apis-enterprise-wifiManager.md).

## Modules to Import

```ts
import { wifiManager } from '@kit.MDMKit';
```

## wifiManager.isWifiActive<sup>(deprecated)</sup>

isWifiActive(admin: Want, callback: AsyncCallback&lt;boolean&gt;): void

Queries the Wi-Fi status of the current device. This API uses an asynchronous callback to return the result.

**Deprecated since:** 26.0.0

**Substitutes:** [isWifiActiveSync](./js-apis-enterprise-wifiManager.md#wifimanageriswifiactivesync)

**Required permissions**: ohos.permission.ENTERPRISE_SET_WIFI

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | Yes   | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                 |
| callback | AsyncCallback&lt;boolean&gt;            | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is a Boolean value (**true** means that Wi-Fi is enabled; and **false** means the opposite). If the operation fails, **err** is an error object.      |

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
import { wifiManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

wifiManager.isWifiActive(wantTemp, (err, result) => {
  if (err) {
    console.error(`Failed to query whether the wifi is active or not. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info(`Succeeded in querying whether the wifi is active or not, result : ${result}`);
});
```

## wifiManager.isWifiActive<sup>(deprecated)</sup>

isWifiActive(admin: Want): Promise&lt;boolean&gt;

Queries the Wi-Fi status of the current device. This API uses a promise to return the result.

**Deprecated since:** 26.0.0

**Substitutes:** [isWifiActiveSync](./js-apis-enterprise-wifiManager.md#wifimanageriswifiactivesync)

**Required permissions**: ohos.permission.ENTERPRISE_SET_WIFI

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes   | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the Wi-Fi status.<br>The value **true** means that Wi-Fi is enabled; the value **false** means the opposite. |

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
import { wifiManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

wifiManager.isWifiActive(wantTemp).then((result) => {
  console.info(`Succeeded in querying whether the wifi is active or not, result : ${result}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to query whether the wifi is active or not. Code: ${err.code}, message: ${err.message}`);
});
```

## wifiManager.setWifiProfile<sup>(deprecated)</sup>

setWifiProfile(admin: Want, profile: WifiProfile, callback: AsyncCallback&lt;void&gt;): void

Configures Wi-Fi for the current device to connect to a specified network. This API uses an asynchronous callback to return the result.

**Deprecated since:** 26.0.0

**Substitutes:** [setWifiProfileSync](./js-apis-enterprise-wifiManager.md#wifimanagersetwifiprofilesync)

**Required permissions**: ohos.permission.ENTERPRISE_SET_WIFI

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | Yes   | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                 |
| profile    | [WifiProfile](js-apis-enterprise-wifiManager.md#wifiprofile) | Yes   | Wi-Fi configuration information.                 |
| callback | AsyncCallback&lt;void&gt;            | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.     |

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
import { wifiManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
let profile: wifiManager.WifiProfile = {
  // Replace with actual values.
  'ssid': 'name',
  'preSharedKey': 'passwd',
  'securityType': wifiManager.WifiSecurityType.WIFI_SEC_TYPE_PSK
};

wifiManager.setWifiProfile(wantTemp, profile, (err) => {
  if (err) {
    console.error(`Failed to set wifi profile. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in setting wifi profile');
});
```

## wifiManager.setWifiProfile<sup>(deprecated)</sup>

setWifiProfile(admin: Want, profile: WifiProfile): Promise&lt;void&gt;

Configures Wi-Fi for the current device to connect to a specified network. This API uses a promise to return the result.

**Deprecated since:** 26.0.0

**Substitutes:** [setWifiProfileSync](./js-apis-enterprise-wifiManager.md#wifimanagersetwifiprofilesync)

**Required permissions**: ohos.permission.ENTERPRISE_SET_WIFI

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes   | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|
| profile    | [WifiProfile](js-apis-enterprise-wifiManager.md#wifiprofile) | Yes   | Wi-Fi configuration information.                 |

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value. An error object is thrown if the Wi-Fi fails to be configured.|

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
import { wifiManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
let profile: wifiManager.WifiProfile = {
  // Replace with actual values.
  'ssid': 'name',
  'preSharedKey': 'passwd',
  'securityType': wifiManager.WifiSecurityType.WIFI_SEC_TYPE_PSK
};

wifiManager.setWifiProfile(wantTemp, profile).then(() => {
  console.info('Succeeded in setting wifi profile');
}).catch((err: BusinessError) => {
  console.error(`Failed to set wifi profile. Code: ${err.code}, message: ${err.message}`);
});
```

## wifiManager.isWifiDisabled<sup>(deprecated)</sup>

isWifiDisabled(admin: Want): boolean

Queries whether Wi-Fi is disabled on the current device.

**Deprecated since:** 26.0.0

**Substitutes:** [getDisallowedPolicy](./js-apis-enterprise-restrictions.md#restrictionsgetdisallowedpolicy24)

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_WIFI

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes   | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| boolean | Wi-Fi disabling status. The value **true** indicates that Wi-Fi is disabled, and false indicates the opposite.|

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
import { wifiManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  let result: boolean = wifiManager.isWifiDisabled(wantTemp);
  console.info(`Succeeded in querying whether the wifi is disabled or not, result : ${result}`);
} catch (err) {
  console.error(`Failed to query the wifi is disabled or not. Code: ${err.code}, message: ${err.message}`);
};
```

## wifiManager.setWifiDisabled<sup>(deprecated)</sup>

setWifiDisabled(admin: Want, disabled: boolean): void

Sets the Wi-Fi disabling policy.

**Deprecated since:** 26.0.0

**Substitutes:** [setDisallowedPolicy](./js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicy24)

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_WIFI

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name    | Type                               | Mandatory| Description                                     |
| ---------- | ----------------------------------- | ---- | ----------------------------------------- |
| admin      | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                           |
| disabled   | boolean                             | Yes  | The value **true** indicates that Wi-Fi is disabled, and the value **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 202      | Permission verification failed. A non-system application calls a system API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { wifiManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  wifiManager.setWifiDisabled(wantTemp, true);
  console.info('Succeeded in setting the wifi disabled');
} catch (err) {
  console.error(`Failed to set the wifi disabled. Code: ${err.code}, message: ${err.message}`);
};
```
