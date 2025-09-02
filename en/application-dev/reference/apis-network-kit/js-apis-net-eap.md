# @ohos.net.eap (Extensible Authentication)

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @foredward-->
<!--Designer: @h00918518-->
<!--Tester: @WIFIroam-test-->
<!--Adviser: @zhang_yixin13-->

The **eap** module provides the extensible authentication mechanism to enable third-party clients to participate in custom 802.1X (a port-based network access control protocol) authentication, such as Extensible Authentication Protocol (EAP) authentication.

> **NOTE**
>
> The initial APIs of this module are supported since API version 20. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Module to Import

```js
import {eap} from '@kit.NetworkKit';
```

## eap.regCustomEapHandler

regCustomEapHandler(netType: number, eapCode: number, eapType: number, callback: Callback\<EapData\>): void

Registers a custom handler of Extensible Authentication Protocol (EAP) packets for extensible authentication. This API returns the result asynchronously through a callback.

The system will encapsulate the eligible EAP packets into the callback function for enterprise applications to retrieve.

**Required permissions**: ohos.permission.MANAGE_ENTERPRISE_WIFI_CONNECTION

**System capability**: SystemCapability.Communication.NetManager.Eap

**Parameters**

| Name                             | Type|Mandatory|Description|
| ----------------------------- | ---------- |---------- |---------- |
| netType| number|Yes|Network type. The value can be **1** or **2**.<br>The value **1** indicates WLAN, and the value **2** indicates Ethernet.|
| eapCode|number |Yes|EAP code. The value can be any of the following:<br>code=1 Request, code=2 Response, code=3 Success, code=4 Failure.|
| eapType| number |Yes|EAP method. The value range is [0, 255].<br>Common values include the following: eapType=1 Identity, eapType=2 Notification, eapType=3 NAK, eapType=4 MD5-Challenge, eapType=5 OTP (One-Time Password), eapType=6 GTC (Generic Token Card), eapType=13 EAP-TLS, eapType=21 EAP-TTLS, eapType=25 EAP-PEAP, eapType=254 Expanded Types, and eapType=255 Experimental use.|
| callback| Callback\<[EapData](#eapdata)\> |Yes|Callback used to process EAP packets with the specified code and type.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Extensible Authentication Error Codes](errorcode-net-eap.md).

| Error Code| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.          |
|33200006 | Invalid net type.          |
|33200007 | Invalid eap code.          |
|33200008 | Invalid eap type.          |
|33200009 | netmanager stop.          |
|33200099 | internal error.          |

**Example**

```js
import {eap} from '@kit.NetworkKit';
let netType = 1;
let eapCode = 1;
let eapType = 25;
let  eapData = (eapData:eap.EapData):void => {
  console.info("rsp result",JSON.stringify(eapData))
}
    
try {
  eap.regCustomEapHandler(netType, eapCode, eapType, eapData);
  console.info('regCustomEapHandler success');
} catch (err) {
  console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
}
```

## eap.unregCustomEapHandler

unregCustomEapHandler(netType:number, eapCode: number, eapType: number, callback: Callback\<EapData\>): void

Unregisters the custom handler of EAP packets for extensible authentication. This API returns the result asynchronously through a callback.

**Required permissions**: ohos.permission.MANAGE_ENTERPRISE_WIFI_CONNECTION

**System capability**: SystemCapability.Communication.NetManager.Eap

**Parameters**

| Name                           | Type|Mandatory|Description|
| ----------------------------- | ---------- |---------- |---------- |
| netType| number|Yes|Network type. The value can be **1** or **2**.<br>The value **1** indicates WLAN, and the value **2** indicates Ethernet.|
| eapCode|number |Yes|EAP code. The value can be any of the following:<br>code=1 Request, code=2 Response, code=3 Success, code=4 Failure.|
| eapType| number |Yes|EAP method. The value range is [0, 255].<br>Common values include the following: eapType=1 Identity, eapType=2 Notification, eapType=3 NAK, eapType=4 MD5-Challenge, eapType=5 OTP (One-Time Password), eapType=6 GTC (Generic Token Card), eapType=13 EAP-TLS, eapType=21 EAP-TTLS, eapType=25 EAP-PEAP, eapType=254 Expanded Types, and eapType=255 Experimental use.|
| callback| Callback\<[EapData](#eapdata)\> |Yes|Callback used to process EAP packets with the specified code and type.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Extensible Authentication Error Codes](errorcode-net-eap.md).

| Error Code| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.          |
|33200006 | Invalid net type.          |
|33200007 | Invalid eap code.          |
|33200008 | Invalid eap type.          |
|33200009 | netmanager stop.          |
|33200099 | internal error.          |

**Example**

```js
import {eap} from '@kit.NetworkKit';
let netType = 1;
let eapCode = 1;
let eapType = 25;
let  eapData = (eapData:eap.EapData):void => {
  console.info("rsp result",JSON.stringify(eapData))
}
    
try {
  eap.unregCustomEapHandler(netType, eapCode, eapType, eapData);
  console.info('unregCustomEapHandler success');
} catch (err) {
  console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
}
```

## eap.replyCustomEapData

replyCustomEapData(result: CustomResult, data: EapData): void

Notifies the system of the extensible authentication result.

 > **NOTE**
 >
 >- If this callback is used to process received EAP data packets, the customized portion added by the server must be removed from the EAP data transmitted to the system.
 >- If this callback is used to process sent EAP data packets, the EAP data transmitted to the system is the EAP data with the customized portion added by the server.

**Required permissions**: ohos.permission.MANAGE_ENTERPRISE_WIFI_CONNECTION

**System capability**: SystemCapability.Communication.NetManager.Eap

**Parameters**

| Name                           | Type|Mandatory|Description|
| ----------------------------- | ---------- |---------- |---------- |
| result | [CustomResult](#customresult)|Yes|Extensible authentication result.|
| data | [EapData](#eapdata) |Yes|EAP data.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Extensible Authentication Error Codes](errorcode-net-eap.md).

| Error Code| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.          |
|33200004 | Invalid result.          |
|33200005 | Invalid size of eap data.          |
|33200009 | netmanager stop.          |
|33200099 | internal error.          |

```js
import {eap} from '@kit.NetworkKit';
let eapData:eap.EapData= {
  msgId: 1,
  eapBuffer: new Uint8Array([1, 2, 3, 4, 5]),
  bufferLen: 5,
};
let result = 1;

try {
  eap.replyCustomEapData(result, eapData);
  console.info('replyCustomEapData success');
} catch (err) {
  console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
}
```

## eap.startEthEap

startEthEap(netId: number, profile: EthEapProfile): void

Starts EAP authentication on an Ethernet NIC.

**Required permissions**: ohos.permission.MANAGE_ENTERPRISE_WIFI_CONNECTION

**System capability**: SystemCapability.Communication.NetManager.Eap

**Parameters**

| Name                           | Type|Mandatory|Description|
| ----------------------------- | ---------- |---------- |---------- |
| netId| number|Yes|ID of the Ethernet NIC.|
| profile|[EthEapProfile](#etheapprofile) |Yes|EAP profile.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Extensible Authentication Error Codes](errorcode-net-eap.md).

| Error Code| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.          |
|33200001 | Invalid netId.          |
|33200003 | Invalid profile.          |
|33200009 | netmanager stop.          |
|33200010 | invalid eth state.          |
|33200099 | internal error.          |

**Example**

```js
import {eap} from '@kit.NetworkKit';
let netId = 100;
let profile: eap.EthEapProfile = {
  eapMethod: eap.EapMethod.EAP_TTLS,
  phase2Method: eap.Phase2Method.PHASE2_AKA_PRIME,
  identity: "identity",
  anonymousIdentity: "anonymousIdentity",
  password: "password",
  caCertAliases: "caCertAliases",
  caPath: "caPath",
  clientCertAliases: "clientCertAliases",
  certEntry: new Uint8Array([5,6,7,8,9,10]),
  certPassword: "certPassword",
  altSubjectMatch: "altSubjectMatch",
  domainSuffixMatch: "domainSuffixMatch",
  realm: "realm",
  plmn: "plmn",
  eapSubId: 1
};
    
try {
  eap.startEthEap(netId, profile);
  console.info('startEthEap success');
} catch (err) {
  console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
}
```

## eap.logOffEthEap

logOffEthEap(netId: number): void

Revokes the EAP-authenticated state of an Ethernet NIC.

**Required permissions**: ohos.permission.MANAGE_ENTERPRISE_WIFI_CONNECTION

**System capability**: SystemCapability.Communication.NetManager.Eap

**Parameters**

| Name                           | Type|Mandatory|Description|
| ----------------------------- | ---------- |---------- |---------- |
| netId | number|Yes|ID of the Ethernet NIC.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Extensible Authentication Error Codes](errorcode-net-eap.md).

| Error Code| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.          |
|33200001 | Invalid netId.          |
|33200002 | Log off fail.          |
|33200009 | netmanager stop.          |
|33200010 | invalid eth state.          |
|33200099 | internal error.          |

**Example**

```js
import {eap} from '@kit.NetworkKit';
let netId = 100;    
try{
  eap.logOffEthEap(netId);
  console.info("logOffEthEap succes");
} catch (err) {
  console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
}
```

## EapData

Defines the EAP data.

​**System capability**: SystemCapability.Communication.NetManager.Eap

| **Name**| **Type**| **Read-Only**| **Optional**| **Description**|
| -------- | -------- | -------- | -------- | -------- |
| msgId | number | No| No| Pseudo random number used to associate the EAP data before and after processing.|
| eapBuffer | Uint8Array | No| No| Raw EAP data starting from the EAP header, which is not encrypted.|
| bufferLen| number | No| No| Data length.|

## CustomResult

Enumerates the EAP authentication results.

​**System capability**: SystemCapability.Communication.NetManager.Eap

| **Name**| **Value**| **Description**|
| -------- | -------- | -------- |
| RESULT_FAIL | 0 | The authentication process ends with a failed result.|
| RESULT_NEXT | 1 | The authentication is successful, and the process proceeds to the next step.|
| RESULT_FINISH | 2 | The authentication process ends with a successful result.|

## EapMethod

Enumerates the EAP authentication methods.

**System capability**: SystemCapability.Communication.NetManager.Eap

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

**System capability**: SystemCapability.Communication.NetManager.Eap

| Name| Value| Description|
| -------- | -------- | -------- |
| PHASE2_NONE | 0 | Not specified.|
| PHASE2_PAP | 1 | PAP.|
| PHASE2_MSCHAP | 2 | MS-CHAP.|
| PHASE2_MSCHAPV2 | 3 | MS-CHAPv2.|
| PHASE2_GTC | 4 | GTC.|
| PHASE2_SIM | 5 | SIM.|
| PHASE2_AKA | 6 | AKA.|
| PHASE2_AKA_PRIME | 7 | AKA Prime.|

## EthEapProfile

Represents the EAP profile information.

**System capability**: SystemCapability.Communication.NetManager.Eap

| Name             | Type                         | Read-Only| Optional| Description                            |
| ----------------- | ----------------------------- | ---- |----| -------------------------------- |
| eapMethod         | [EapMethod](#eapmethod)      | No  | No| EAP authentication method.                    |
| phase2Method      | [Phase2Method](#phase2method)| No  | No| Phase 2 authentication method.              |
| identity          | string                        | No  | No| Identity information.                      |
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
