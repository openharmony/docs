# @ohos.enterprise.wifiManager (Wi-Fi Management)

The **wifiManager** module provides APIs for Wi-Fi management of enterprise devices.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs of this module can be used only in the stage model.
>
> - The APIs provided by this module can be called only by a [device administrator application](enterpriseDeviceManagement-overview.md#basic-concepts) that is [enabled](js-apis-enterprise-adminManager.md#adminmanagerenableadmin).

## Modules to Import

```ts
import wifiManager from '@ohos.enterprise.wifiManager';
```

## wifiManager.isWifiActive

isWifiActive(admin: Want, callback: AsyncCallback&lt;boolean&gt;): void

Checks whether Wi-Fi is active through the specified device administrator application. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_SET_WIFI

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)     | Yes   | Device administrator application.                 |
| callback | AsyncCallback&lt;boolean&gt;            | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is a Boolean value (**true** indicates that Wi-Fi is active; and **false** indicates that Wi-Fi is inactive). If the operation fails, **err** is an error object.      |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**Example**

```ts
import Want from '@ohos.app.ability.Want';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

wifiManager.isWifiActive(wantTemp, (err, result) => {
  if (err) {
    console.error(`Failed to query is wifi active or not. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info(`Succeeded in query is wifi active or not, result : ${result}`);
});
```

## wifiManager.isWifiActive

isWifiActive(admin: Want): Promise&lt;boolean&gt;

Checks whether Wi-Fi is active through the specified device administrator application. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_SET_WIFI

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | Yes   | Device administrator application.|

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** indicates that Wi-Fi is active, and the value **false** indicates that Wi-Fi is inactive. |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**Example**

```ts
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

wifiManager.isWifiActive(wantTemp).then((result) => {
  console.info(`Succeeded in query is wifi active or not, result : ${result}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to query is wifi active or not. Code: ${err.code}, message: ${err.message}`);
});
```

## wifiManager.setWifiProfile

setWifiProfile(admin: Want, profile: WifiProfile, callback: AsyncCallback&lt;void&gt;): void

Sets Wi-Fi profile through the specified device administrator application to enable the device to connect to the specified network. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_SET_WIFI

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)     | Yes   | Device administrator application.                 |
| profile    | [WifiProfile](#wifiprofile)     | Yes   | Wi-Fi profile information.                 |
| callback | AsyncCallback&lt;void&gt;            | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.     |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**Example**

```ts
import Want from '@ohos.app.ability.Want';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let profile: wifiManager.WifiProfile = {
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

## wifiManager.setWifiProfile

setWifiProfile(admin: Want, profile: WifiProfile): Promise&lt;void&gt;

Sets Wi-Fi profile through the specified device administrator application to enable the device to connect to the specified network. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_SET_WIFI

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | Yes   | Device administrator application.|
| profile    | [WifiProfile](#wifiprofile)     | Yes   | Wi-Fi profile information.                 |

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value. If the operation fails, an error object will be thrown.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**Example**

```ts
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let profile: wifiManager.WifiProfile = {
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

## WifiProfile

Represents the Wi-Fi profile information.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

| Name        | Type    | Mandatory|    Description                           |
| ----------- | --------| ---- |  ------------------------------- |
| ssid | string | Yes| Service set identifier (SSID) of the hotspot, in UTF-8 format.|
| bssid | string | No| Basic service set identifier (BSSID) of the hotspot.|
| preSharedKey | string | Yes| Pre-shared key (PSK) of the hotspot.|
| isHiddenSsid | boolean | No| Whether the network is hidden.|
| securityType | [WifiSecurityType](#wifisecuritytype) | Yes| Security type.|
| creatorUid | number | No|ID of the creator.|
| disableReason | number | No| Reason for disabling Wi-Fi.|
| netId | number | No|Network ID allocated.|
| randomMacType | number | No| Type of the random MAC.|
| randomMacAddr | string | No|Random MAC address.|
| ipType | [IpType](#iptype) | No|  IP address type.|
| staticIp | [IpProfile](#ipprofile) | No|  Static IP address information.|
| eapProfile | [WifiEapProfile](#wifieapprofile) | No|Extensible Authentication Protocol (EAP) configuration.|

## WifiSecurityType

Enumerates the Wi-Fi security types.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

| Name| Value| Description|
| -------- | -------- | -------- |
| WIFI_SEC_TYPE_INVALID | 0 | Invalid security type.|
| WIFI_SEC_TYPE_OPEN | 1 | Open security type.|
| WIFI_SEC_TYPE_WEP | 2 | Wired Equivalent Privacy (WEP).|
| WIFI_SEC_TYPE_PSK | 3 | PSK.|
| WIFI_SEC_TYPE_SAE | 4 | Simultaneous Authentication of Equals (SAE).|
| WIFI_SEC_TYPE_EAP | 5 | EAP.|
| WIFI_SEC_TYPE_EAP_SUITE_B | 6 | Suite B 192-bit encryption.|
| WIFI_SEC_TYPE_OWE | 7 | Opportunistic Wireless Encryption (OWE).|
| WIFI_SEC_TYPE_WAPI_CERT | 8 | WLAN Authentication and Privacy Infrastructure (WAPI) in certificate-based mode (WAPI-CERT).|
| WIFI_SEC_TYPE_WAPI_PSK | 9 | WAPI-PSK.|

## IpType

Enumerates the IP address types.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

| Name| Value| Description|
| -------- | -------- | -------- |
| STATIC | 0 | Static IP address.|
| DHCP | 1 | IP address allocated by DHCP.|
| UNKNOWN | 2 | Not specified.|

## IpProfile

Represents IP configuration information.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- |-------- |
| ipAddress | number | Yes| IP address.|
| gateway | number | Yes|Gateway.|
| prefixLength | number | Yes| Subnet mask.|
| dnsServers | number[] | Yes| Domain name server (DNS) information.|
| domains | Array&lt;string&gt; | Yes|Domain information.|

## WifiEapProfile

Represents EAP profile (configuration) information.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| eapMethod | [EapMethod](#eapmethod) | Yes|EAP authentication method.|
| phase2Method | [Phase2Method](#phase2method) | Yes| Phase 2 authentication method.|
| identity | string | Yes| Identity Information.|
| anonymousIdentity | string | Yes|  Anonymous identity.|
| password | string | Yes|  Password (string type).|
| caCertAliases | string | Yes| CA certificate alias.|
| caPath | string | Yes| CA certificate path.|
| clientCertAliases | string | Yes| Client certificate alias.|
| certEntry | Uint8Array | Yes| CA certificate content.|
| certPassword | string | Yes|CA certificate password.|
| altSubjectMatch | string | Yes| A string to match the alternate subject.|
| domainSuffixMatch | string | Yes|A string to match the domain suffix.|
| realm | string | Yes| Realm for the passpoint credential.|
| plmn | string | Yes| Public land mobile network (PLMN) of the passpoint credential provider.|
| eapSubId | number | Yes| Sub-ID of the SIM card.|

## EapMethod

Enumerates the EAP authentication methods.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

| Name| Value| Description|
| -------- | -------- | -------- |
| EAP_NONE | 0 | Not specified.|
| EAP_PEAP | 1 | PEAP.|
| EAP_TLS | 2 | TLS.|
| EAP_TTLS | 3 | TTLS.|
| EAP_PWD | 4 | Password.|
| EAP_SIM | 5 | SIM.|
| EAP_AKA | 6 | AKA.|
| EAP_AKA_PRIME | 7 | AKA Prime.|
| EAP_UNAUTH_TLS | 8 | UNAUTH TLS.|


## Phase2Method

Enumerates the Phase 2 authentication methods.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

| Name| Value| Description|
| -------- | -------- | -------- |
| PHASE2_NONE | 0 | Not specified.|
| PHASE2_PAP | 1 | PAP.|
| PHASE2_MSCHAP | 2 | MS-CHAP.|
| PHASE2_MSCHAPV2 | 3 | MS-CHAPv2.|
| PHASE2_GTC | 4 | GTC .|
| PHASE2_SIM | 5 | SIM.|
| PHASE2_AKA | 6 | AKA.|
| PHASE2_AKA_PRIME | 7 | AKA Prime.|
