# @ohos.enterprise.wifiManager (Wi-Fi Management)
<!--Kit: MDM Kit-->
<!--Subsystem: Customization-->
<!--Owner: @huanleima; @weizai16-->
<!--Designer: @hp_guo-->
<!--Tester: @lpw_work-->
<!--Adviser: @zhang_yixin13-->

This module provides Wi-Fi management capabilities for enterprise devices, including querying the Wi-Fi enabling status, configuring Wi-Fi connections, and managing the Wi-Fi list.

**Use cases:**
- Configuring Wi-Fi connections for enterprise devices in batches, simplifying the device initialization process
- Controlling the Wi-Fi networks that devices can connect to, implementing network access compliance management
- Managing the Wi-Fi switch of enterprise devices and unifying network policies

**Benefits:**
- Improve enterprise network management efficiency and reduces IT O&M costs.
- Ensure that devices connect only to secure Wi-Fi networks, reducing security risks.
- Implement unified management and control of network policies to meet enterprise compliance requirements.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.
>
> The APIs of this module can be called only by a device administrator application that is enabled. For details, see [MDM Kit Development](../../mdm/mdm-kit-guide.md).
>
> The global restriction policies are provided by **restrictions**. To disable Wi-Fi globally, see [@ohos.enterprise.restrictions](js-apis-enterprise-restrictions.md).

## Modules to Import

```ts
import { wifiManager } from '@kit.MDMKit';
```

## wifiManager.isWifiActiveSync

isWifiActiveSync(admin: Want): boolean

Queries the Wi-Fi status of the current device.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_WIFI

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.


**Parameters**

| Name| Type                                                   | Mandatory| Description                  |
| ------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|

**Return value**

| Type   | Description                                                      |
| ------- | ---------------------------------------------------------- |
| boolean | Returns the Wi-Fi status. The value **true** means Wi-Fi is enabled, and the value **false** means the opposite.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { wifiManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility',
};

try {
  let result: boolean = wifiManager.isWifiActiveSync(wantTemp);
  console.info(`Succeeded in querying whether the Wi-Fi is active or not, result : ${result}`);
} catch (err) {
  console.error(`Failed to query whether the Wi-Fi is active or not. Code: ${err.code}, message: ${err.message}`);
}
```

## wifiManager.setWifiProfileSync

setWifiProfileSync(admin: Want, profile: WifiProfile): void

Configures Wi-Fi for the current device to connect to a specified network.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_WIFI

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Latest configuration precedence](../../mdm/mdm-kit-multi-mdm.md#rule-3-latest-configuration-precedence).

**Parameters**

| Name | Type                                                   | Mandatory| Description                  |
| ------- | ------------------------------------------------------- | ---- | ---------------------- |
| admin   | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|
| profile | [WifiProfile](#wifiprofile)                             | Yes  | Wi-Fi configuration information, which is used to specify the configuration parameters of the Wi-Fi network to be connected, including the SSID, BSSID, key, and security type.        |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

***Scenario 1: public Wi-Fi development***
```ts
import { wifiManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility',
};

let profile: wifiManager.WifiProfile = {
  // Replace with actual values.
  'ssid': 'guest-Wi-Fi',
  'preSharedKey': '',
  'securityType': wifiManager.WifiSecurityType.WIFI_SEC_TYPE_OPEN
};

try {
  wifiManager.setWifiProfileSync(wantTemp, profile);
  console.info(`Succeeded in setting Wi-Fi profile.`);
} catch (err) {
  console.error(`Failed to set Wi-Fi profile. Code: ${err.code}, message: ${err.message}`);
}
```

***Scenario 2: Multiple Wi-Fi networks with the same name but different BSSIDs***
```ts
import { wifiManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility',
};

let profile: wifiManager.WifiProfile = {
  // Replace with actual values.
  'ssid': 'guest-Wi-Fi',
  'bssid': 'AA:BB:CC:DD:EE:FF',
  'preSharedKey': '',
  'securityType': wifiManager.WifiSecurityType.WIFI_SEC_TYPE_OPEN
};

try {
  wifiManager.setWifiProfileSync(wantTemp, profile);
  console.info(`Succeeded in setting Wi-Fi profile.`);
} catch (err) {
  console.error(`Failed to set Wi-Fi profile. Code: ${err.code}, message: ${err.message}`);
}
```

***Scenario 3: old industrial devices with low security***
```ts
import { wifiManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility',
};

let profile: wifiManager.WifiProfile = {
  // Replace with actual values.
  'ssid': 'Legacy-Office-Wi-Fi',
  'bssid': 'AA:BB:CC:DD:EE:FF',
  'preSharedKey': '',
  'securityType': wifiManager.WifiSecurityType.WIFI_SEC_TYPE_WEP
};

try {
  wifiManager.setWifiProfileSync(wantTemp, profile);
  console.info(`Succeeded in setting Wi-Fi profile.`);
} catch (err) {
  console.error(`Failed to set Wi-Fi profile. Code: ${err.code}, message: ${err.message}`);
}
```

***Scenario 4: home networks, small offices, and consumer routers***
```ts
import { wifiManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility',
};

let profile: wifiManager.WifiProfile = {
  // Replace with actual values.
  'ssid': 'home_Wi-Fi',
  'preSharedKey': 'passwd',
  'securityType': wifiManager.WifiSecurityType.WIFI_SEC_TYPE_PSK
};

try {
  wifiManager.setWifiProfileSync(wantTemp, profile);
  console.info(`Succeeded in setting Wi-Fi profile.`);
} catch (err) {
  console.error(`Failed to set Wi-Fi profile. Code: ${err.code}, message: ${err.message}`);
}
```

***Scenario 5: modern IoT device networks***
```ts
import { wifiManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility',
};

let profile: wifiManager.WifiProfile = {
  // Replace with actual values.
  'ssid': 'iot_Wi-Fi',
  'preSharedKey': 'passwd',
  'securityType': wifiManager.WifiSecurityType.WIFI_SEC_TYPE_SAE
};

try {
  wifiManager.setWifiProfileSync(wantTemp, profile);
  console.info(`Succeeded in setting Wi-Fi profile.`);
} catch (err) {
  console.error(`Failed to set Wi-Fi profile. Code: ${err.code}, message: ${err.message}`);
}
```

***Scenario 6: company networks and university campus networks***
```ts
import { wifiManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility',
};

// EAP-PEAP configuration example
let profile: wifiManager.WifiProfile = {
  // Replace with actual values.
  'ssid': 'company_Wi-Fi',
  'preSharedKey': '',
  'securityType': wifiManager.WifiSecurityType.WIFI_SEC_TYPE_EAP,
  'eapProfile': {
    eapMethod: wifiManager.EapMethod.EAP_PEAP,
    phase2Method: wifiManager.Phase2Method.PHASE2_MSCHAPV2,
    identity: 'zhangsan@company.com',
    password: 'passwd',
    anonymousIdentity: '',
    caPath: '/system/etc/security/caCerts/company-ca.pem',
    caCertAliases:  '',
    clientCertAliases: '',
    certEntry: new Uint8Array(),
    certPassword: '',
    altSubjectMatch: 'CN=radius.company.com,OU=IT Department,O=Company Inc.,C=US',
    domainSuffixMatch: 'company.com',
    realm: '',
    eapSubId: 0,
    plmn: ''
  }
};

try {
  wifiManager.setWifiProfileSync(wantTemp, profile);
  console.info(`Succeeded in setting Wi-Fi profile.`);
} catch (err) {
  console.error(`Failed to set Wi-Fi profile. Code: ${err.code}, message: ${err.message}`);
}
```

```ts
import { wifiManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility',
};

// EAP-TLS configuration example
let profile: wifiManager.WifiProfile = {
  // Replace with actual values.
  'ssid': 'tls_Wi-Fi',
  'preSharedKey': '',
  'securityType': wifiManager.WifiSecurityType.WIFI_SEC_TYPE_EAP,
  'eapProfile': {
    eapMethod: wifiManager.EapMethod.EAP_TLS,
    phase2Method: wifiManager.Phase2Method.PHASE2_NONE,
    identity: 'zhangsan@company.com',
    password: '',
    anonymousIdentity: '',
    caPath: '/system/etc/security/caCerts/company-ca.pem',
    caCertAliases: '',
    clientCertAliases: 'zhangsan-auth-cert',
    certEntry: new Uint8Array(),
    certPassword: '',
    altSubjectMatch: 'CN=radius.company.com,OU=IT Department,O=Company Inc.,C=US',
    domainSuffixMatch: 'company.com',
    realm: '',
    eapSubId: 0,
    plmn: ''
  }
};

try {
  wifiManager.setWifiProfileSync(wantTemp, profile);
  console.info(`Succeeded in setting Wi-Fi profile.`);
} catch (err) {
  console.error(`Failed to set Wi-Fi profile. Code: ${err.code}, message: ${err.message}`);
}
```

```ts
import { wifiManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility',
};

// EAP-TTLS configuration example
let profile: wifiManager.WifiProfile = {
  // Replace with actual values.
  'ssid': 'ttls_Wi-Fi',
  'preSharedKey': '',
  'securityType': wifiManager.WifiSecurityType.WIFI_SEC_TYPE_EAP,
  'eapProfile': {
    eapMethod: wifiManager.EapMethod.EAP_TTLS,
    phase2Method: wifiManager.Phase2Method.PHASE2_GTC,
    identity: 'zhangsan@company.com',
    password: '123456', // Dynamic password generated based on the token.
    anonymousIdentity: '',
    caPath: '',
    caCertAliases: 'company-ca',
    clientCertAliases: '',
    certEntry: new Uint8Array(),
    certPassword: '',
    altSubjectMatch: 'CN=radius.company.com,OU=IT Department,O=Company Inc.,C=US',
    domainSuffixMatch: 'company.com',
    realm: 'company.com',
    plmn: '',
    eapSubId: 0,
  }
};

try {
  wifiManager.setWifiProfileSync(wantTemp, profile);
  console.info(`Succeeded in setting Wi-Fi profile.`);
} catch (err) {
  console.error(`Failed to set Wi-Fi profile. Code: ${err.code}, message: ${err.message}`);
}
```

```ts
import { wifiManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility',
};

// EAP-SIM configuration example
let profile: wifiManager.WifiProfile = {
  // Replace with actual values.
  'ssid': 'eap_sim_Wi-Fi',
  'preSharedKey': '',
  'securityType': wifiManager.WifiSecurityType.WIFI_SEC_TYPE_EAP,
  'eapProfile': {
    eapMethod: wifiManager.EapMethod.EAP_SIM,
    phase2Method: wifiManager.Phase2Method.PHASE2_NONE,
    identity: '',
    password:'',
    anonymousIdentity: '',
    caPath: '',
    caCertAliases:  'carrier-root-ca',
    clientCertAliases: '',
    certEntry: new Uint8Array(),
    certPassword: '',
    altSubjectMatch: 'CN=radius.company.com,OU=IT Department,O=Company Inc.,C=US',
    domainSuffixMatch: 'company.com',
    realm: 'waln.mnc000.mcc460.3gppnetwork.org',
    eapSubId: 0,
    plmn: '46000'
  }
};

try {
  wifiManager.setWifiProfileSync(wantTemp, profile);
  console.info(`Succeeded in setting Wi-Fi profile.`);
} catch (err) {
  console.error(`Failed to set Wi-Fi profile. Code: ${err.code}, message: ${err.message}`);
}
```

***Scenario 7: fixed IP address for client access***
```ts
import { wifiManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility',
};

let profile: wifiManager.WifiProfile = {
  // Replace with actual values.
  'ssid': 'static_ip_Wi-Fi',
  'preSharedKey': 'passwd',
  'securityType': wifiManager.WifiSecurityType.WIFI_SEC_TYPE_PSK,
  'ipType': wifiManager.IpType.STATIC,
  'staticIp': {
    ipAddress: 3232235778, // 192.168.1.2
    gateway: 3232235777, // 192.168.1.1
    prefixLength: 24,
    dnsServers: [3232235777, 3232235777],
    domains: []
  }
};

try {
  wifiManager.setWifiProfileSync(wantTemp, profile);
  console.info(`Succeeded in setting Wi-Fi profile.`);
} catch (err) {
  console.error(`Failed to set Wi-Fi profile. Code: ${err.code}, message: ${err.message}`);
}
```

## wifiManager.addAllowedWifiList<sup>19+</sup>

addAllowedWifiList(admin: Want, list: Array&lt;WifiAccessInfo&gt;): void

Adds allowed Wi-Fi networks. The current device can only connect to the allowed Wi-Fi networks. This API is applicable to enterprise security management scenarios, for example, restricting employees' devices to connect only to Wi-Fi networks authorized by the enterprise, preventing connection to insecure external Wi-Fi networks and ensuring enterprise network and data security.

A policy conflict is reported when this API is called in the following scenarios:

1. The device Wi-Fi capability has been disabled via [setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicydeprecated). You can resolve the conflict by enabling Wi-Fi via [setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicydeprecated).
2. Disallowed Wi-Fi networks have been added by calling [addDisallowedWifiList](#wifimanageradddisallowedwifilist19). You can resolve the conflict by removing the disallowed Wi-Fi networks through [removeDisallowedWifiList](#wifimanagerremovedisallowedwifilist19).

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_WIFI

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Policy merging](../../mdm/mdm-kit-multi-mdm.md#rule-4-policy-merging).

**Parameters**

| Name      | Type                                                      | Mandatory| Description                                                        |
| ------------ | -------------------------------------------------------    | ---- | ------------------------------------------------------------ |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md)    | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                      |
| list         | Array&lt;[WifiAccessInfo](#wifiaccessinfo19)&gt;                   | Yes  | Array of allowed Wi-Fi networks. The maximum length of the array is 200. For example, if there are already 100 Wi-Fi networks, a maximum of 100 more can be added.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200010  | A conflict policy has been configured.                       |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { wifiManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.edmtest',
  abilityName: 'com.example.edmtest.EnterpriseAdminAbility'
};
try {
  let wifiIds: Array<wifiManager.WifiAccessInfo> = [{
    // Replace with actual values.
    ssid: "wifi_name",
    bssid: "68:77:24:77:A6:D8"
  }];
  wifiManager.addAllowedWifiList(wantTemp, wifiIds);
  console.info(`Succeeded in adding allowed Wi-Fi list.`);
} catch (err) {
  console.error(`Failed to add allowed Wi-Fi list. Code: ${err.code}, message: ${err.message}`);
}
```

## wifiManager.removeAllowedWifiList<sup>19+</sup>

removeAllowedWifiList(admin: Want, list: Array&lt;WifiAccessInfo&gt;): void

Removes Wi-Fi networks from the allowed list. If some Wi-Fi networks are removed from the allowed list, the current device can only connect to the remaining ones; if all Wi-Fi networks are removed from the allowed list, the current device can connect to any Wi-Fi network. This API is applicable to enterprise Wi-Fi policy adjustment scenarios, such as removing restrictions on old Wi-Fi networks when the company switches to a new Wi-Fi network, or lifting some Wi-Fi restrictions to allow employees to connect to new office networks.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_WIFI

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Policy merging](../../mdm/mdm-kit-multi-mdm.md#rule-4-policy-merging).

**Parameters**

| Name      | Type                                                   | Mandatory| Description                                                        |
| ------------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                      |
| list         | Array&lt;[WifiAccessInfo](#wifiaccessinfo19)&gt;                | Yes  | Array of Wi-Fi networks to be removed from the allowed list. The maximum length of the array is 200.                                           |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { wifiManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.edmtest',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  let wifiIds: Array<wifiManager.WifiAccessInfo> = [{
    // Replace with actual values.
    ssid: "wifi_name",
    bssid: "68:77:24:77:A6:D8"
  }];
  wifiManager.removeAllowedWifiList(wantTemp, wifiIds);
  console.info(`Succeeded in removing allowed Wi-Fi list.`);
} catch (err) {
  console.error(`Failed to remove allowed Wi-Fi list. Code: ${err.code}, message: ${err.message}`);
}
```

## wifiManager.getAllowedWifiList<sup>19+</sup>

getAllowedWifiList(admin: Want | null): Array&lt;WifiAccessInfo&gt;

Obtains Wi-Fi networks from the allowed list.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_WIFI

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.


**Parameters**

| Name| Type                                                   | Mandatory| Description                                  |
| ------ | ------------------------------------------------------- | ---- | -------------------------------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) \| null | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.<br>When multiple MDM applications exist on the device, passing a **Want** parameter queries the policies set by the corresponding enterprise device administrator application for versions earlier than API version 26.0.0. Since API version 26.0.0, passing null is additionally supported to query the policies that actually take effect.|

**Return value**

| Type                              | Description                     |
| ---------------------------------- | ------------------------- |
| Array&lt;[WifiAccessInfo](#wifiaccessinfo19)&gt; | Array of allowed Wi-Fi networks.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { wifiManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.edmtest',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  let result: Array<wifiManager.WifiAccessInfo> = wifiManager.getAllowedWifiList(wantTemp);
  console.info(`Succeeded in getting allowed Wi-Fi list. Result: ${JSON.stringify(result)}`);
} catch (err) {
  console.error(`Failed to get allowed Wi-Fi list. Code: ${err.code}, message: ${err.message}`);
}
```

## wifiManager.addDisallowedWifiList<sup>19+</sup>

addDisallowedWifiList(admin: Want, list: Array&lt;WifiAccessInfo&gt;): void

Adds disallowed Wi-Fi networks. The current device cannot connect to the disallowed Wi-Fi networks. This API is applicable to enterprise security control and management scenarios, such as preventing devices from connecting to insecure public Wi-Fi networks (for example, those in cafes or airports), and preventing employees from connecting to competitor or malicious networks, thereby safeguarding enterprise data security.

A policy conflict is reported when this API is called in the following scenarios:

1. The device Wi-Fi capability has been disabled via [setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicydeprecated). You can resolve the conflict by enabling Wi-Fi via [setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicydeprecated).
2. Allowed Wi-Fi networks have been added by calling [addAllowedWifiList](#wifimanageraddallowedwifilist19). You can resolve the conflict by removing the allowed Wi-Fi networks through [removeAllowedWifiList](#wifimanagerremoveallowedwifilist19).

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_WIFI

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Policy merging](../../mdm/mdm-kit-multi-mdm.md#rule-4-policy-merging).

**Parameters**

| Name      | Type                                                   | Mandatory| Description                                                        |
| ------------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                      |
| list         | Array&lt;[WifiAccessInfo](#wifiaccessinfo19)&gt;                | Yes  | Array of disallowed Wi-Fi networks. The maximum length of the array is 200. For example, if there are already 100 Wi-Fi networks, a maximum of 100 more can be added.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200010  | A conflict policy has been configured.                       |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { wifiManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.edmtest',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  let wifiIds: Array<wifiManager.WifiAccessInfo> = [{
    // Replace with actual values.
    ssid: "wifi_name",
    bssid: "68:77:24:77:A6:D8"
  }];
  wifiManager.addDisallowedWifiList(wantTemp, wifiIds);
  console.info(`Succeeded in adding disallowed Wi-Fi list.`);
} catch (err) {
  console.error(`Failed to add disallowed Wi-Fi list. Code: ${err.code}, message: ${err.message}`);
}
```

## wifiManager.removeDisallowedWifiList<sup>19+</sup>

removeDisallowedWifiList(admin: Want, list: Array&lt;WifiAccessInfo&gt;): void

Removes disallowed Wi-Fi networks. If some Wi-Fi networks are removed from the disallowed list, the current device cannot connect to the remaining ones; if all Wi-Fi networks are removed from the disallowed list, the current device can connect to any Wi-Fi network. This API is applicable to enterprise Wi-Fi policy adjustment scenarios, such as lifting restrictions on a specific Wi-Fi network, allowing employees to connect to newly approved office networks, or completely removing the disabling policy.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_WIFI

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Policy merging](../../mdm/mdm-kit-multi-mdm.md#rule-4-policy-merging).

**Parameters**

| Name      | Type                                                   | Mandatory| Description                                                        |
| ------------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                      |
| list         | Array&lt;[WifiAccessInfo](#wifiaccessinfo19)&gt;                | Yes  | Array of Wi-Fi networks to be removed. The maximum length of the array is 200.                     |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { wifiManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.edmtest',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  let wifiIds: Array<wifiManager.WifiAccessInfo> = [{
    // Replace with actual values.
    ssid: "wifi_name",
    bssid: "68:77:24:77:A6:D8"
  }];
  wifiManager.removeDisallowedWifiList(wantTemp, wifiIds);
  console.info(`Succeeded in removing disallowed Wi-Fi list.`);
} catch (err) {
  console.error(`Failed to remove disallowed Wi-Fi list. Code: ${err.code}, message: ${err.message}`);
}
```

## wifiManager.getDisallowedWifiList<sup>19+</sup>

getDisallowedWifiList(admin: Want | null): Array&lt;WifiAccessInfo&gt;

Obtains disallowed Wi-Fi networks.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_WIFI

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.


**Parameters**

| Name| Type                                                   | Mandatory| Description                                  |
| ------ | ------------------------------------------------------- | ---- | -------------------------------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) \| null | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.<br>When multiple MDM applications exist on the device, passing a **Want** parameter queries the policies set by the corresponding enterprise device administrator application for versions earlier than API version 26.0.0. Since API version 26.0.0, passing null is additionally supported to query the policies that actually take effect.|

**Return value**

| Type                              | Description                     |
| ---------------------------------- | ------------------------- |
| Array&lt;[WifiAccessInfo](#wifiaccessinfo19)&gt; | Array of disallowed Wi-Fi networks.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { wifiManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.edmtest',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  let result: Array<wifiManager.WifiAccessInfo> = wifiManager.getDisallowedWifiList(wantTemp);
  console.info(`Succeeded in getting disallowed Wi-Fi list. Result: ${JSON.stringify(result)}`);
} catch (err) {
  console.error(`Failed to get disallowed Wi-Fi list. Code: ${err.code}, message: ${err.message}`);
}
```

## wifiManager.turnOnWifi<sup>20+</sup>

turnOnWifi(admin: Want, isForce: boolean): void

Enables Wi-Fi. This API is applicable to enterprise device remote management scenarios, such as administrators remotely enabling Wi-Fi on employee devices, or ensuring that Wi-Fi is turned on when specific policies are enforced.

In the following scenario, attempting to enable Wi-Fi using this API will fail, and a message indicating that the system function is disabled will be returned:

​Wi-Fi has been disabled via [setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicydeprecated). In this case, you must call [setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicydeprecated) to enable Wi-Fi.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_WIFI

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Conflict rule**: If any MDM app disables Wi-Fi via [setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicydeprecated), Wi-Fi cannot be enabled through this API.

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name | Type                                                   | Mandatory| Description                                                        |
| ------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin   | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                      |
| isForce | boolean                                                 | Yes  | Whether to forcibly enable Wi-Fi.<br>The value **true** means to forcibly enable Wi-Fi. Once enabled, it cannot be disabled manually. You must call [turnOffWifi](#wifimanagerturnoffwifi20) instead. The value **false** means the opposite and the Wi-Fi can be disabled manually.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 203      | This function is prohibited by enterprise management policies. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { wifiManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  wifiManager.turnOnWifi(wantTemp, true);
  console.info(`Succeeded in turning on Wi-Fi.`);
} catch (err) {
  console.error(`Failed to turn on Wi-Fi. Code: ${err.code}, message: ${err.message}`);
}
```

## wifiManager.turnOffWifi<sup>20+</sup>

turnOffWifi(admin: Want): void

Disables Wi-Fi.

In the following scenario, attempting to disable Wi-Fi using this API will fail, and a message indicating that the system function is disabled will be returned:

​Wi-Fi has been disabled via [setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicydeprecated). In this case, you must call [setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicydeprecated) to enable Wi-Fi.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_WIFI

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Conflict rule**: If any MDM app disables Wi-Fi via [setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicydeprecated), Wi-Fi cannot be disabled through this API.

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name| Type                                                   | Mandatory| Description                  |
| ------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 203      | This function is prohibited by enterprise management policies. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { wifiManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  wifiManager.turnOffWifi(wantTemp);
  console.info(`Succeeded in turning off Wi-Fi.`);
} catch (err) {
  console.error(`Failed to turn off Wi-Fi. Code: ${err.code}, message: ${err.message}`);
}
```

## WifiAccessInfo<sup>19+</sup>

Represents Wi-Fi access information containing Service Set Identifier (SSID) and Basic Service Set Identifier (BSSID).

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

<!--Table: 10%; 10%; 10%; 10%; 60%-->
| Name         | Type                            | Read-Only| Optional| Description                                                       |
| ------------- | --------------------------------| ---- | -----| ------------------------------------------------------ |
| ssid          | string                           | No  | No| Name of the Wi-Fi hotspot. The encoding format is UTF-8 and the maximum length is 32 bytes (three bytes for each Chinese character and one byte for each English character).          |
| bssid         | string                           | No  | Yes| MAC address of the Wi-Fi hotspot, for example, **00:11:22:33:44:55**. To obtain the MAC address, enable **Enable Wi-Fi verbose logging** under **Settings** > **System & updates** > **Developer options** first, and then go to the WLAN list to check the MAC address. If a Wi-Fi network has multiple MAC addresses, all of them must be added here.<br>This property is optional when the [addDisallowedWifiList](#wifimanageradddisallowedwifilist19) and [removeDisallowedWifiList](#wifimanagerremovedisallowedwifilist19) APIs are called. The default value is an empty string.<br>This property is optional (available since API version 21) when the [addAllowedWifiList](#wifimanageraddallowedwifilist19) and [removeAllowedWifiList](#wifimanagerremoveallowedwifilist19) APIs are called. The default value is an empty string. However, this property is mandatory in API version 20 and earlier versions.           |

## WifiProfile

Represents the Wi-Fi configuration information.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



| Name         | Type                             | Read-Only| Optional| Description                                                       |
| ------------- | ----------------------------------| ---- | ----| ------------------------------------------------------- |
| ssid          | string                                | No  | No| Wi-Fi hotspot name. The maximum length is 32 bytes, and the encoding format is UTF-8.         |
| bssid         | string                                | No  | Yes| MAC address of the Wi-Fi hotspot, with a length of 6 bytes. For example, **00:11:22:33:44:55**. To obtain the MAC address, enable **Enable Wi-Fi verbose logging** under **Settings** > **System & updates** > **Developer options** first, and then go to the WLAN list to check the MAC address. If a Wi-Fi network has multiple MAC addresses, all of them must be added here.                                         |
| preSharedKey  | string                                | No  | No| Key of the hotspot, which is used for Wi-Fi connection authentication. The maximum length is 64 bytes.                              |
| isHiddenSsid  | boolean                               | No  | Yes| Whether the network is hidden. The value **true** indicates yes, and the value **false** indicates no. The default value is **false**.|
| securityType  | [WifiSecurityType](#wifisecuritytype) | No  | No| Security type.                                                |
| creatorUid    | number                                | No  | Yes| ID of the user who creates the network. The default value is **-1**.                                   |
| disableReason | number                                | No  | Yes| Disabling reason. The default value is **0**.                                        |
| netId         | number                                | No  | Yes| Allocated network ID. The default value is **-1**.                                    |
| randomMacType | number                                | No  | Yes| Random MAC. The value **0** indicates random MAC address, and the value **1** indicates device MAC address. The default value is **0**.        |
| randomMacAddr | string                                | No  | Yes| MAC address. This field is mandatory when **randomMacType** is set to device MAC address.              |
| ipType        | [IpType](#iptype)                     | No  | Yes| IP address type. The default value is **DHCP**.                                        |
| staticIp      | [IpProfile](#ipprofile)               | No  | Yes| Static IP address information. This field is mandatory when **ipType** is set to **STATIC**.               |
| eapProfile    | [WifiEapProfile](#wifieapprofile)     | No  | Yes| Extensible Authentication Protocol (EAP) configuration. This field is mandatory only when **securityType** is set to **WIFI_SEC_TYPE_EAP**.    |

## WifiSecurityType

Enumerates the Wi-Fi security types.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



| Name                     | Value  | Description                                                        |
| ------------------------- | ---- | ------------------------------------------------------------ |
| WIFI_SEC_TYPE_INVALID     | 0    | Invalid security type. For example, airport public Wi-Fi.                             |
| WIFI_SEC_TYPE_OPEN        | 1    | Open security type.                                              |
| WIFI_SEC_TYPE_WEP         | 2    | Wired Equivalent Privacy (WEP).     |
| WIFI_SEC_TYPE_PSK         | 3    | PSK. For example, home and small office Wi-Fi.        |
| WIFI_SEC_TYPE_SAE         | 4    | Simultaneous Authentication of Equals (SAE). For example, smart home and small- and medium-sized enterprise networks.|
| WIFI_SEC_TYPE_EAP         | 5    | EAP. For example, large enterprise authentication and university campus networks.                 |
| WIFI_SEC_TYPE_EAP_SUITE_B | 6    | Suite B 192-bit encryption. After the setting, Wi-Fi will use Suite-B 192-bit high-strength encryption, providing a high level of security authentication. It is suitable for government and high-security institutions.                  |
| WIFI_SEC_TYPE_OWE         | 7    | Opportunistic Wireless Encryption (OWE). For example, public Wi-Fi in a coffee shop, which does not require a password to provide encryption for connections.|
| WIFI_SEC_TYPE_WAPI_CERT   | 8    | WLAN Authentication and Privacy Infrastructure (WAPI) in certificate-based mode (WAPI-CERT). It is China's own wireless security standard.                    |
| WIFI_SEC_TYPE_WAPI_PSK    | 9    | WAPI-PSK.                                          |

## IpType

Enumerates the IP address types.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



| Name   | Value  | Description          |
| ------- | ---- | -------------- |
| STATIC  | 0    | Static IP address, which is used in scenarios where a fixed IP address is required, for example, a fixed IP address of an office printer.      |
| DHCP    | 1    | Dynamic Host Configuration Protocol (DHCP), which is a service that automatically allocates IP addresses and other network configuration information to devices on a network.|
| UNKNOWN | 2    | Not specified.      |

## IpProfile

Represents IP configuration information.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



| Name        | Type               | Read-Only| Optional| Description       |
| ------------ | ------------------- | ---- | ----| ----------- |
| ipAddress    | number              | No  | No | IP address, represented in decimal format. For example, the standard dotted decimal notation **192.168.1.1** corresponds to the decimal value **3232235777**. The address ranges from 0.0.0.0 to 255.255.255.255.   |
| gateway      | number              | No  | No | Default gateway, represented in decimal format, usually the IP address of the router. The address ranges from 0.0.0.0 to 255.255.255.255.     |
| prefixLength | number              | No  | No | Subnet mask. The address ranges from 0.0.0.0 to 255.255.255.255.     |
| dnsServers   | number[]            | No  | No | DNS server. The array can contain a maximum of two addresses: the primary DNS server and the secondary DNS server. The address ranges from 0.0.0.0 to 255.255.255.255.|
| domains      | Array&lt;string&gt; | No  | No | Domain information.   |

## WifiEapProfile

Represents EAP profile (configuration) information.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



| Name             | Type                         | Read-Only| Optional| Description                            |
| ----------------- | ----------------------------- | ---- |----| -------------------------------- |
| eapMethod         | [EapMethod](#eapmethod)       | No  | No| EAP authentication method.                    |
| phase2Method      | [Phase2Method](#phase2method) | No  | No| Phase 2 authentication method. This parameter is mandatory only when **eapMethod** is **EAP_PEAP** or **EAP_TTLS**.              |
| identity          | string                        | No  | No| Identity Information. This parameter cannot be empty when **eapMethod** is **TLS**.                      |
| anonymousIdentity | string                        | No  | No| Anonymous identity.                      |
| password          | string                        | No  | No| Password. When **eapMethod** is **EAP_PEAP** or **EAP_PWD**, this parameter cannot be empty. The value contains a maximum of 128 bytes. |
| caCertAliases     | string                        | No  | No| CA certificate alias.                   |
| caPath            | string                        | No  | No| CA certificate path.                   |
| clientCertAliases | string                        | No  | No| Client certificate alias. When the client certificate content is empty, the client certificate must be installed first via the certificate management API before passing in the alias.            |
| certEntry         | Uint8Array                    | No  | No| Client certificate content. When **eapMethod** is set to **EAP_TLS**, if this field is empty, the client certificate alias cannot be empty.              |
| certPassword      | string                        | No  | No| CA certificate password.                    |
| altSubjectMatch   | string                        | No  | No| A string to match the alternate subject. In addition to checking the primary domain name of the certificate, the system checks whether the alternate subject name of the certificate matches the certificate.      |
| domainSuffixMatch | string                        | No  | No| A string to match the domain suffix.                    |
| realm             | string                        | No  | No| Realm for the passpoint credential.              |
| plmn              | string                        | No  | No| Credential provider.|
| eapSubId          | number                        | No  | No| Sub-ID of the SIM card.                   |

## EapMethod

Enumerates the EAP authentication methods.

> **NOTE**
>
> Currently, only the EAP_PEAP and EAP_TLS authentication methods are supported.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



| Name          | Value  | Description            |
| -------------- | ---- | ---------------- |
| EAP_NONE       | 0    | Not specified.        |
| EAP_PEAP       | 1    | Protected Extensible Authentication Protocol (PEAP). It first establishes a secure TLS tunnel, followed by performing simple authentication within the tunnel.      |
| EAP_TLS        | 2    | Transport Layer Security (TLS). It implements mutual certificate authentication.       |
| EAP_TTLS       | 3    | Tunnel Transport Layer Security (TTLS). It is similar to PEAP, but supports a more diverse set of authentication methods inside the tunnel.      |
| EAP_PWD        | 4    | Password Authentication (PWD). It enables password-based authentication and does not require a server certificate.       |
| EAP_SIM        | 5    | Subscriber Identity Module (SIM). It performs authentication using the keys and algorithms stored in the SIM card of a smartphone.       |
| EAP_AKA        | 6    | Authentication and Key Agreement (AKA). It performs authentication using enhanced keys and algorithms stored in a USIM card (applicable to 3G/4G/5G SIM cards).      |
| EAP_AKA_PRIME  | 7    | AKA Prime. It is an enhanced version of EAP-AKA and binds the network name during key derivation. |
| EAP_UNAUTH_TLS | 8    | Unauthenticated TLS (UNAUTH TLS). It implements one-way authentication (client authentication only) while establishing an encrypted communication channel.|

## Phase2Method

Enumerates the Phase 2 authentication methods.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



| Name            | Value  | Description           |
| ---------------- | ---- | --------------- |
| PHASE2_NONE      | 0    | Not specified.       |
| PHASE2_PAP       | 1    | PAP.      |
| PHASE2_MSCHAP    | 2    | MS-CHAP.   |
| PHASE2_MSCHAPV2  | 3    | MS-CHAPv2. |
| PHASE2_GTC       | 4    | GTC.      |
| PHASE2_SIM       | 5    | SIM.      |
| PHASE2_AKA       | 6    | AKA.      |
| PHASE2_AKA_PRIME | 7    | AKA Prime.|
