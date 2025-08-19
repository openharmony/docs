# @ohos.enterprise.wifiManager (Wi-Fi Management)

The **wifiManager** module provides Wi-Fi management capabilities for enterprise devices, including obtaining the Wi-Fi status.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs of this module can be used only in the stage model.
>
> - The APIs of this module can be called only by a device administrator application that is enabled. For details, see [MDM Kit Development](../../mdm/mdm-kit-guide.md).
>
> - The global restriction policies are provided by **restrictions**. To disable Wi-Fi globally, see [@ohos.enterprise.restrictions](js-apis-enterprise-restrictions.md).

## Modules to Import

```ts
import { wifiManager } from '@kit.MDMKit';
```

## wifiManager.isWifiActiveSync

isWifiActiveSync(admin: Want): boolean

Queries the Wi-Fi status of the current device.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_WIFI

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Parameters**

| Name| Type                                                   | Mandatory| Description                  |
| ------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.|

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
import { Want } from '@kit.AbilityKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

try {
  let result: boolean = wifiManager.isWifiActiveSync(wantTemp);
  console.info(`Succeeded in query is wifi active or not, result : ${result}`);
} catch (err) {
  console.error(`Failed to query is wifi active or not. Code: ${err.code}, message: ${err.message}`);
}
```

## wifiManager.setWifiProfileSync

setWifiProfileSync(admin: Want, profile: WifiProfile): void

Configures Wi-Fi for the current device to connect to a specified network.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_WIFI

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Parameters**

| Name | Type                                                   | Mandatory| Description                  |
| ------- | ------------------------------------------------------- | ---- | ---------------------- |
| admin   | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.|
| profile | [WifiProfile](#wifiprofile)                             | Yes  | Wi-Fi configuration information.        |

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
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let profile: wifiManager.WifiProfile = {
  'ssid': 'name',
  'preSharedKey': 'passwd',
  'securityType': wifiManager.WifiSecurityType.WIFI_SEC_TYPE_PSK
};

try {
  wifiManager.setWifiProfileSync(wantTemp, profile);
  console.info('Succeeded in setting wifi profile.');
} catch (err) {
  console.error(`Failed to set wifi profile. Code: ${err.code}, message: ${err.message}`);
}
```

## wifiManager.addAllowedWifiList<sup>19+</sup>

addAllowedWifiList(admin: Want, list: Array&lt;WifiAccessInfo&gt;): void

Adds allowed Wi-Fi networks. The current device can only connect to the allowed Wi-Fi networks.

A policy conflict is reported when this API is called in the following scenarios:

1. Wi-Fi networks have been disabled by calling [setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicy). You can resolve the conflict by enabling the Wi-Fi networks through [setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicy).
2. Disallowed Wi-Fi networks have been added by calling [addDisallowedWifiList](#wifimanageradddisallowedwifilist19). You can resolve the conflict by removing the disallowed Wi-Fi networks through [removeDisallowedWifiList](#wifimanagerremovedisallowedwifilist19).

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_WIFI

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Parameters**

| Name      | Type                                                      | Mandatory| Description                                                        |
| ------------ | -------------------------------------------------------    | ---- | ------------------------------------------------------------ |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md)    | Yes  | EnterpriseAdminExtensionAbility.                                      |
| list         | Array&lt;[WifiAccessInfo](#wifiaccessinfo19)&gt;                   | Yes  | A list of allowed Wi-Fi networks. The maximum length of the array is 200. For example, if there are already 100 Wi-Fi networks, a maximum of 100 more can be added.|

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
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.edmtest',
  abilityName: 'com.example.edmtest.EnterpriseAdminAbility'
};
try {
  let wifiIds: Array<wifiManager.WifiAccessInfo> = [{
    // Replace it as required.
    ssid: "wifi_name",
    bssid: "68:77:24:77:A6:D8"
  }];
  wifiManager.addAllowedWifiList(wantTemp, wifiIds);
  console.info(`Succeeded in adding allowed wifi list.`);
} catch (err) {
  console.error(`Failed to add allowed wifi list. Code: ${err.code}, message: ${err.message}`);
}
```

## wifiManager.removeAllowedWifiList<sup>19+</sup>

removeAllowedWifiList(admin: Want, list: Array&lt;WifiAccessInfo&gt;): void

Removes allowed Wi-Fi networks. If some Wi-Fi networks are removed from the allowed list, the current device can only connect to the remaining ones; if all Wi-Fi networks are removed from the allowed list, the current device can connect to any Wi-Fi network.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_WIFI

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Parameters**

| Name      | Type                                                   | Mandatory| Description                                                        |
| ------------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.                                      |
| list         | Array&lt;[WifiAccessInfo](#wifiaccessinfo19)&gt;                | Yes  | List of allowed Wi-Fi networks to remove. The maximum length of the array is 200.                                           |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.edmtest',
  abilityName: 'com.example.edmtest.EnterpriseAdminAbility'
};
try {
  let wifiIds: Array<wifiManager.WifiAccessInfo> = [{
    // Replace it as required.
    ssid: "wifi_name",
    bssid: "68:77:24:77:A6:D8"
  }];
  wifiManager.removeAllowedWifiList(wantTemp, wifiIds);
  console.info(`Succeeded in removing allowed wifi list.`);
} catch (err) {
  console.error(`Failed to remove allowed wifi list. Code: ${err.code}, message: ${err.message}`);
}
```

## wifiManager.getAllowedWifiList<sup>19+</sup>

getAllowedWifiList(admin: Want): Array&lt;WifiAccessInfo&gt;

Obtains the allowed Wi-Fi networks.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_WIFI

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Parameters**

| Name| Type                                                   | Mandatory| Description                                  |
| ------ | ------------------------------------------------------- | ---- | -------------------------------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.|

**Return value**

| Type                              | Description                     |
| ---------------------------------- | ------------------------- |
| Array&lt;[WifiAccessInfo](#wifiaccessinfo19)&gt; | Allowed Wi-Fi networks.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.edmtest',
  abilityName: 'com.example.edmtest.EnterpriseAdminAbility'
};
try {
  let result: Array<wifiManager.WifiAccessInfo> = wifiManager.getAllowedWifiList(wantTemp);
  console.info(`Succeeded in getting allowed wifi list. Result: ${JSON.stringify(result)}`);
} catch (err) {
  console.error(`Failed to get allowed wifi list. Code: ${err.code}, message: ${err.message}`);
}
```

## wifiManager.addDisallowedWifiList<sup>19+</sup>

addDisallowedWifiList(admin: Want, list: Array&lt;WifiAccessInfo&gt;): void

Adds disallowed Wi-Fi networks. The current device cannot connect to the disallowed Wi-Fi networks.

A policy conflict is reported when this API is called in the following scenarios:

1. Wi-Fi networks have been disabled by calling [setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicy). You can resolve the conflict by enabling the Wi-Fi networks through [setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicy).
2. Allowed Wi-Fi networks have been added by calling [addAllowedWifiList](#wifimanageraddallowedwifilist19). You can resolve the conflict by removing the allowed Wi-Fi networks through [removeAllowedWifiList](#wifimanagerremoveallowedwifilist19).

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_WIFI

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Parameters**

| Name      | Type                                                   | Mandatory| Description                                                        |
| ------------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.                                      |
| list         | Array&lt;[WifiAccessInfo](#wifiaccessinfo19)&gt;                | Yes  | A list of disallowed Wi-Fi networks. The maximum length of the array is 200. For example, if there are already 100 Wi-Fi networks, a maximum of 100 more can be added.|

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
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.edmtest',
  abilityName: 'com.example.edmtest.EnterpriseAdminAbility'
};
try {
  let wifiIds: Array<wifiManager.WifiAccessInfo> = [{
    // Replace it as required.
    ssid: "wifi_name",
    bssid: "68:77:24:77:A6:D8"
  }];
  wifiManager.addDisallowedWifiList(wantTemp, wifiIds);
  console.info(`Succeeded in adding disallowed wifi list.`);
} catch (err) {
  console.error(`Failed to add disallowed wifi list. Code: ${err.code}, message: ${err.message}`);
}
```

## wifiManager.removeDisallowedWifiList<sup>19+</sup>

removeDisallowedWifiList(admin: Want, list: Array&lt;WifiAccessInfo&gt;): void

Removes disallowed Wi-Fi networks. If some Wi-Fi networks are removed from the disallowed list, the current device cannot connect to the remaining ones; if all Wi-Fi networks are removed from the disallowed list, the current device can connect to any Wi-Fi network.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_WIFI

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Parameters**

| Name      | Type                                                   | Mandatory| Description                                                        |
| ------------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.                                      |
| list         | Array&lt;[WifiAccessInfo](#wifiaccessinfo19)&gt;                | Yes  | List of disallowed Wi-Fi networks to remove. The maximum length of the array is 200.                     |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.edmtest',
  abilityName: 'com.example.edmtest.EnterpriseAdminAbility'
};
try {
  let wifiIds: Array<wifiManager.WifiAccessInfo> = [{
    // Replace it as required.
    ssid: "wifi_name",
    bssid: "68:77:24:77:A6:D8"
  }];
  wifiManager.removeDisallowedWifiList(wantTemp, wifiIds);
  console.info(`Succeeded in removing disallowed wifi list.`);
} catch (err) {
  console.error(`Failed to remove disallowed wifi list. Code: ${err.code}, message: ${err.message}`);
}
```

## wifiManager.getDisallowedWifiList<sup>19+</sup>

getDisallowedWifiList(admin: Want): Array&lt;WifiAccessInfo&gt;

Obtains disallowed Wi-Fi networks.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_WIFI

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Parameters**

| Name| Type                                                   | Mandatory| Description                                  |
| ------ | ------------------------------------------------------- | ---- | -------------------------------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.|

**Return value**

| Type                              | Description                     |
| ---------------------------------- | ------------------------- |
| Array&lt;[WifiAccessInfo](#wifiaccessinfo19)&gt; | Disallowed Wi-Fi networks.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.edmtest',
  abilityName: 'com.example.edmtest.EnterpriseAdminAbility'
};
try {
  let result: Array<wifiManager.WifiAccessInfo> = wifiManager.getDisallowedWifiList(wantTemp);
  console.info(`Succeeded in getting disallowed wifi list. Result: ${JSON.stringify(result)}`);
} catch (err) {
  console.error(`Failed to get disallowed wifi list. Code: ${err.code}, message: ${err.message}`);
}
```

## WifiAccessInfo<sup>19+</sup>

Represents Wi-Fi access information containing Service Set Identifier (SSID) and Basic Service Set Identifier (BSSID).

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



| Name         | Type                            | Read-Only| Optional| Description                                                       |
| ------------- | --------------------------------| ---- | -----| ------------------------------------------------------ |
| ssid          | string                           | No  | No| Name of the Wi-Fi hotspot. The encoding format is UTF-8 and the maximum length is 32 bytes (three bytes for each Chinese character and one byte for each English character).          |
| bssid         | string                           | No  | Yes| MAC address of the Wi-Fi hotspot, for example, **00:11:22:33:44:55**.<br>This field is mandatory when [addAllowedWifiList](#wifimanageraddallowedwifilist19) and [removeAllowedWifiList](#wifimanagerremoveallowedwifilist19) are called.<br>This field is optional (the default value is an empty string) when [addDisallowedWifiList](#wifimanageradddisallowedwifilist19) and [removeDisallowedWifiList](#wifimanagerremovedisallowedwifilist19) are called.           |

## WifiProfile

Represents the Wi-Fi configuration information.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



| Name         | Type                             | Read-Only| Optional| Description                                                       |
| ------------- | ----------------------------------| ---- | ----| ------------------------------------------------------- |
| ssid          | string                                | No  | No| SSID of the hotspot, in UTF-8 format.                              |
| bssid         | string                                | No  | Yes| Basic service set identifier (BSSID) of the hotspot.                                              |
| preSharedKey  | string                                | No  | No| Pre-shared key (PSK) of the hotspot.                                               |
| isHiddenSsid  | boolean                               | No  | Yes| Whether the network is hidden. The value **true** indicates that the network is hidden; the value **false** indicates the opposite.|
| securityType  | [WifiSecurityType](#wifisecuritytype) | No  | No| Security type.                                                 |
| creatorUid    | number                                | No  | Yes| ID of the creator.                                             |
| disableReason | number                                | No  | Yes| Reason for disabling Wi-Fi.                                                 |
| netId         | number                                | No  | Yes| Network ID allocated.                                             |
| randomMacType | number                                | No  | Yes| Random MAC.                                              |
| randomMacAddr | string                                | No  | Yes| Random MAC address.                                              |
| ipType        | [IpType](#iptype)                     | No  | Yes| IP address type.                                               |
| staticIp      | [IpProfile](#ipprofile)               | No  | Yes| Static IP address information.                                           |
| eapProfile    | [WifiEapProfile](#wifieapprofile)     | No  | Yes| Extensible Authentication Protocol (EAP) configuration.                                   |

## WifiSecurityType

Enumerates the Wi-Fi security types.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



| Name                     | Value  | Description                                                        |
| ------------------------- | ---- | ------------------------------------------------------------ |
| WIFI_SEC_TYPE_INVALID     | 0    | Invalid security type.                                              |
| WIFI_SEC_TYPE_OPEN        | 1    | Open security type.                                              |
| WIFI_SEC_TYPE_WEP         | 2    | Wired Equivalent Privacy (WEP).     |
| WIFI_SEC_TYPE_PSK         | 3    | PSK.                    |
| WIFI_SEC_TYPE_SAE         | 4    | Simultaneous Authentication of Equals (SAE).|
| WIFI_SEC_TYPE_EAP         | 5    | EAP.                                               |
| WIFI_SEC_TYPE_EAP_SUITE_B | 6    | Suite B 192-bit encryption.                                     |
| WIFI_SEC_TYPE_OWE         | 7    | Opportunistic Wireless Encryption (OWE).                                        |
| WIFI_SEC_TYPE_WAPI_CERT   | 8    | WLAN Authentication and Privacy Infrastructure (WAPI) in certificate-based mode (WAPI-CERT).                                         |
| WIFI_SEC_TYPE_WAPI_PSK    | 9    | WAPI-PSK.                                          |

## IpType

Enumerates the IP address types.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



| Name   | Value  | Description          |
| ------- | ---- | -------------- |
| STATIC  | 0    | Static IP address.      |
| DHCP    | 1    | IP address allocated by DHCP.|
| UNKNOWN | 2    | Not specified.      |

## IpProfile

Represents IP configuration information.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



| Name        | Type               | Mandatory| Description       |
| ------------ | ------------------- | ---- | ----------- |
| ipAddress    | number              | Yes  | IP address.   |
| gateway      | number              | Yes  | Gateway.     |
| prefixLength | number              | Yes  | Subnet mask.     |
| dnsServers   | number[]            | Yes  | Domain name server (DNS) information.|
| domains      | Array&lt;string&gt; | Yes  | Domain information.   |

## WifiEapProfile

Represents EAP profile (configuration) information.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



| Name             | Type                         | Read-Only| Optional| Description                            |
| ----------------- | ----------------------------- | ---- |----| -------------------------------- |
| eapMethod         | [EapMethod](#eapmethod)       | No  | No| EAP authentication method.                    |
| phase2Method      | [Phase2Method](#phase2method) | No  | No| Phase 2 authentication method.              |
| identity          | string                        | No  | No| Identity Information.                      |
| anonymousIdentity | string                        | No  | No| Anonymous identity.                      |
| password          | string                        | No  | No| Password.                          |
| caCertAliases     | string                        | No  | No| CA certificate alias.                   |
| caPath            | string                        | No  | No| CA certificate path.                   |
| clientCertAliases | string                        | No  | No| Client certificate alias.                |
| certEntry         | Uint8Array                    | No  | No| CA certificate content.                   |
| certPassword      | string                        | No  | No| CA certificate password.                    |
| altSubjectMatch   | string                        | No  | No| A string to match the alternate subject.                  |
| domainSuffixMatch | string                        | No  | No| A string to match the domain suffix.                    |
| realm             | string                        | No  | No| Realm for the passpoint credential.              |
| plmn              | string                        | No  | No| Public land mobile network (PLMN) of the passpoint credential provider.|
| eapSubId          | number                        | No  | No| Sub-ID of the SIM card.                   |

## EapMethod

Enumerates the EAP authentication methods.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



| Name          | Value  | Description            |
| -------------- | ---- | ---------------- |
| EAP_NONE       | 0    | Not specified.        |
| EAP_PEAP       | 1    | PEAP.      |
| EAP_TLS        | 2    | TLS.       |
| EAP_TTLS       | 3    | TTLS.      |
| EAP_PWD        | 4    | Password.       |
| EAP_SIM        | 5    | SIM.       |
| EAP_AKA        | 6    | AKA.       |
| EAP_AKA_PRIME  | 7    | AKA Prime. |
| EAP_UNAUTH_TLS | 8    | UNAUTH TLS.|

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

## wifiManager.turnOnWifi<sup>20+</sup>

turnOnWifi(admin: Want, isForce: boolean): void

Enables Wi-Fi.

Wi-Fi cannot be enabled using this API in the following scenario:

​	Wi-Fi has been disabled using the [setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicy) API. You must call [setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicy) to enable it.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_WIFI

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Parameters**

| Name | Type                                                   | Mandatory| Description                                                        |
| ------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin   | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.                                      |
| isForce | boolean                                                 | Yes  | Whether to forcibly enable Wi-Fi.<br>The value **true** means to forcibly Wi-Fi. Once enabled, it cannot be disabled manually. You must call [turnOffWifi](#wifimanagerturnoffwifi20) instead. The value **false** means the opposite and the Wi-Fi can be disabled manually.|

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
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

try {
  wifiManager.turnOnWifi(wantTemp, true);
  console.info(`Succeeded in turning on wifi.`);
} catch (err) {
  console.error(`Failed to turn on wifi. Code: ${err.code}, message: ${err.message}`);
}
```

## wifiManager.turnOffWifi<sup>20+</sup>

turnOffWifi(admin: Want): void

Disables Wi-Fi.

Wi-Fi cannot be disabled using this API in the following scenario:

​	Wi-Fi has been disabled using the [setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicy) API. You must call [setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicy) to enable it.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_WIFI

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Parameters**

| Name| Type                                                   | Mandatory| Description                  |
| ------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.|

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
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

try {
  wifiManager.turnOffWifi(wantTemp);
  console.info(`Succeeded in turning off wifi.`);
} catch (err) {
  console.error(`Failed to turn off wifi. Code: ${err.code}, message: ${err.message}`);
}
```
