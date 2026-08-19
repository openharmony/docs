# @ohos.security.huksExternalCrypto (External Key Management)

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=ec7d2479b6b3839e76a32c0d9bfdf31f7c8310c8 translatedAt=2026-08-17T10:25:51.197Z pushedAt=2026-08-17T11:53:10.236Z -->

This module provides capabilities such as registration and unregistration of external key management extensions, PIN authentication, and authentication status retrieval.

> **Description**
>
> The initial APIs of this module are supported since API version 22. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { huksExternalCrypto } from '@kit.UniversalKeystoreKit';
```

## HuksExternalCryptoTagType

Enumerates the external encrypted data types.

**System capability**: SystemCapability.Security.Huks.CryptoExtension

| Name | Value  | Description   |
| ----- | ---- | -------- |
| HUKS_EXT_CRYPTO_TAG_TYPE_INT | 1 << 28   | The tag value is an integer.|
| HUKS_EXT_CRYPTO_TAG_TYPE_BYTES | 5 << 28  | The tag value is a byte array.|

## HuksExternalCryptoTag

Enumerates the tags used to invoke parameters.

**System capability**: SystemCapability.Security.Huks.CryptoExtension

| Name   | Value  | Description  |
| ------- | ---- | -------- |
| HUKS_EXT_CRYPTO_TAG_UKEY_PIN | HuksExternalCryptoTagType.HUKS_EXT_CRYPTO_TAG_TYPE_BYTES \| 200001    | PIN.|
| HUKS_EXT_CRYPTO_TAG_ABILITY_NAME | HuksExternalCryptoTagType.HUKS_EXT_CRYPTO_TAG_TYPE_BYTES \| 200002    | Name of [CryptoExtensionAbility](js-apis-CryptoExtensionAbility.md).|
| HUKS_EXT_CRYPTO_TAG_EXTRA_DATA | HuksExternalCryptoTagType.HUKS_EXT_CRYPTO_TAG_TYPE_BYTES \| 200003    | External data, which indicates the return data in the common query scenario.|
| HUKS_EXT_CRYPTO_TAG_UID | HuksExternalCryptoTagType.HUKS_EXT_CRYPTO_TAG_TYPE_INT \| 200004    | UID of the caller.|
| HUKS_EXT_CRYPTO_TAG_PURPOSE | HuksExternalCryptoTagType.HUKS_EXT_CRYPTO_TAG_TYPE_INT \| 200005    | Usage type of the key corresponding to the certificate chain. For details, see [CertificatePurpose](../apis-device-certificate-kit/js-apis-certManager.md#certificatepurpose22).|
| HUKS_EXT_CRYPTO_TAG_RESOURCE_INFO | HuksExternalCryptoTagType.HUKS_EXT_CRYPTO_TAG_TYPE_BYTES \| 200007    | Information required for obtaining the resource ID. The format and content are defined by the vendor.<br>**Since**: 26.0.0<br>**Model restriction:** This API can be used only in the stage model.|
| HUKS_EXT_CRYPTO_TAG_ABILITY_INFO | HuksExternalCryptoTagType.HUKS_EXT_CRYPTO_TAG_TYPE_BYTES \| 200008    | Indicates the Ability list information related to the custom PIN dialog box of the key management extension. It is registered synchronously when the key management extension is registered. For details, see [provider registration example](../../security/UniversalKeystoreKit/huks-extension-registration-and-unregistration-arkts.md). If a custom dialog box is registered, the custom dialog box can be launched during PIN authentication to perform PIN authentication and other operations.<br>HUKS_EXT_CRYPTO_TAG_ABILITY_INFO<br> 1.abilityName: The length ranges from 1 to 128 bytes.<br> 2.index: Its value is resourceId, and the maximum length is 512 bytes. This field must be unique. It can be empty under a single CryptoExtension. When it is empty, an empty string is transmitted. During search, the UIAbility corresponding to index is matched first. If it does not exist, the UIAbility with an empty index is returned.<br>**Since:** 26.0.0<br>**Model restriction:** This API can be used only in the stage model. |
| HUKS_EXT_CRYPTO_TAG_BUNDLE_NAME | HuksExternalCryptoTagType.HUKS_EXT_CRYPTO_TAG_TYPE_BYTES \| 200009    | Name of the HAP bundle to which the **CryptoExtensionAbility** belongs.<br>**Since**: 26.0.0<br>**Model restriction:** This API can be used only in the stage model.|

## HuksExternalCryptoParam

Defines the type of the param array used for calling the API.

**System capability**: SystemCapability.Security.Huks.CryptoExtension

| Name| Type       | Read-Only| Optional| Description        |
| ------ | ----------------------------------- | ---- | ---- | ------------ |
| tag    | [HuksExternalCryptoTag](#huksexternalcryptotag)  | No  | No  | Parameter tag, which is used to distinguish parameters.|
| value  | boolean\|number\|bigint\|Uint8Array | No  | No  | Value of the tag.|

## HuksExternalErrorInfo

Defines the detailed error information returned by the key management extension when an external key operation is performed.

**Since**: 26.0.0

**Model restriction**: This struct can be used only in the stage model.

**System capability**: SystemCapability.Security.Huks.CryptoExtension

| Name| Type| Read-Only| Optional| Description|
| ---- | ---- | ---- | ---- | ---- |
| errno | number | No| No| Error code returned by the key management extension.<br>- Non-zero value: The key management extension returns detailed error information, and **errno** is the specific error code.<br>- **0**: The key management extension does not return detailed error information, and **errno** is the default value **0**. You need to determine the error cause based on the API error code.|
| errorDesc | string | No| No| Error description returned by the key management extension. The value of this field is associated with **errno**.<br>- If **errno** is not **0**, the description returned by the key management extension may be an empty string (determined by the extension).<br>- If **errno** is **0**, the value is an empty string.|

## HuksExternalPinAuthState

Enumerates the status values of UKey PIN management.

**System capability**: SystemCapability.Security.Huks.CryptoExtension

| Name   | Value  | Description  |
| ------- | ---- | -------- |
| HUKS_EXT_CRYPTO_PIN_NO_AUTH | 0 | The UKey PIN is not authenticated. |
| HUKS_EXT_CRYPTO_PIN_AUTH_SUCCEEDED | 1 | The UKey PIN is authenticated. |
| HUKS_EXT_CRYPTO_PIN_LOCKED  | 2 | The UKey PIN is locked. |

## huksExternalCrypto.registerProvider

registerProvider(providerName: string, params: Array\<HuksExternalCryptoParam>): Promise\<void>

Registers a specified external provider. This API uses a promise to return the result.

To use a custom PIN dialog box, you need to register the **UIAbility** when registering the provider. The precautions are as follows:

1. The custom dialog box is implemented through the **UIAbility** extension.

2. The registered **UIAbility** can be started through the [openUKeyAuthDialog](../apis-device-certificate-kit/js-apis-certManagerDialog.md#certificatemanagerdialogopenukeyauthdialog22) API provided by the certificate management kit.

3. When the system starts the custom dialog box, it passes the following parameters to you through the **want** API:

    - **Action**: string type. When the custom dialog box is started, the **Action** transferred by the **want** API is **"UkeyPINAuth"**.

    - **appUid**: number type, transferred through **want.parameters**. The **appUid** field indicates the application ID. You can use this field to isolate applications.

    - keyUri: string type. Its value is resourceId, transferred through want.parameters. Indicates the index of the UKey certificate.

4. When implementing **UIAbility**, your application needs to return the corresponding error code based on the specified scenario.

    - If the user cancels the operation, [ERROR_OPERATION_CANCELED](../apis-device-certificate-kit/js-apis-certManagerDialog.md#certificatedialogerrorcode) is returned.

    - If the certificate or key specified by **keyUri** does not exist, [ERROR_OPERATION_FAILED](../apis-device-certificate-kit/js-apis-certManagerDialog.md#certificatedialogerrorcode) is returned.

    - If the parameter format is incorrect, [ERROR_PARAMETER_VALIDATION_FAILED](../apis-device-certificate-kit/js-apis-certManagerDialog.md#certificatedialogerrorcode) is returned.

    - In other failure scenarios, the error code [ERROR_GENERIC](../apis-device-certificate-kit/js-apis-certManagerDialog.md#certificatedialogerrorcode) is returned. If the operation is successful, **0** is returned.

**Required permissions**: ohos.permission.CRYPTO_EXTENSION_REGISTER

**System capability**: SystemCapability.Security.Huks.CryptoExtension

**Parameters**

| Name  | Type | Mandatory| Description |
| -------- | ------- | ---- | -------|
| providerName | string | Yes  | Provider name. The value contains a maximum of 128 bytes. It is recommended that the value contain the vendor information, be globally unique, and not contain sensitive data such as personal contact information.<br>A maximum of 10 providers can be registered.|
| params  | Array<[HuksExternalCryptoParam](#huksexternalcryptoparam)> | Yes | Parameters to be passed during the operation. The mandatory tag is [HUKS_EXT_CRYPTO_TAG_ABILITY_NAME](#huksexternalcryptotag), indicating the ability name. Set this parameter based on the actual service requirements.<br>Since API version 26.0.0, the [HUKS_EXT_CRYPTO_TAG_ABILITY_INFO](#huksexternalcryptotag) tag is optional, which is used to transfer the UIAbility name and package name of the custom PIN authentication dialog box in a JSON list.|

**Return value**

| Type | Description |
| ------------- | --------|
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [HUKS Error Codes](errorcode-huks.md).

| ID| Error Message     |
| -------- | ------------- |
| 201 | check permission failed. |
| 801 | api is not supported. |
| 12000002 | the ability name param is missing. |
| 12000005 | IPC communication failed. |
| 12000014 | memory is insufficient. |
| 12000018 | the input parameter is invalid. |
| 12000019 | the provider is already registered. |
| 12000020 | an error occurred in the dependent module. |
| 12000025 | the number of providers exceeds the limit. |

**Example**

```ts
import { huksExternalCrypto } from '@kit.UniversalKeystoreKit';

function stringToUint8Array(str: string) {
  let arr: number[] = [];
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

const providerName = "testProviderName";
const extProperties: Array<huksExternalCrypto.HuksExternalCryptoParam> = [
  {
    tag: huksExternalCrypto.HuksExternalCryptoTag.HUKS_EXT_CRYPTO_TAG_ABILITY_NAME,
    value: stringToUint8Array("CryptoExtension")
  }
];
huksExternalCrypto.registerProvider(providerName, extProperties)
    .then(() => {
        console.info('promise: registerProvider success.');
    });
```

## huksExternalCrypto.unregisterProvider

unregisterProvider(providerName: string, params?: Array\<HuksExternalCryptoParam>): Promise\<void>

Unregisters a specified external Provider. This API uses a promise to return the result.

**Required permissions**: ohos.permission.CRYPTO_EXTENSION_REGISTER

**System capability**: SystemCapability.Security.Huks.CryptoExtension

**Parameters**

| Name  | Type| Mandatory| Description |
| -------- | ------| ---- | -----|
| providerName | string | Yes  | Provider name. The value contains a maximum of 128 bytes. It is recommended that the value contain the vendor information, be globally unique, and not contain sensitive data such as personal contact information. If a provider has registered multiple extension capabilities, all the extension capabilities of the provider will be unregistered.|
| params  | Array\<[HuksExternalCryptoParam](#huksexternalcryptoparam)> | No| Parameters to be passed during the operation.<br>You can specify [HUKS_EXT_CRYPTO_TAG_ABILITY_NAME](#huksexternalcryptotag) in the **params** parameter to unregister the corresponding **cryptoExtensionAbility** based on the bundle name, **providerName**, and **abilityName**.<br>If [HUKS_EXT_CRYPTO_TAG_ABILITY_NAME](#huksexternalcryptotag) is not specified in the **params** parameter or the **params** parameter is not passed, all providers under the corresponding **providerName** are unregistered.|

**Return value**

| Type  | Description  |
| -------| ------ |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [HUKS Error Codes](errorcode-huks.md).

| ID| Error Message     |
| -------- | ------------- |
| 201 | check permission failed. |
| 801 | api is not supported. |
| 12000005 | IPC communication failed. |
| 12000011 | the provider is not found. |
| 12000012 | Device environment or input parameter is abnormal. This may happen for several reasons, such as the model already being unloaded. |
| 12000014 | memory is insufficient. |
| 12000018 | the input parameter is invalid. |

**Example**

```ts
import { huksExternalCrypto } from '@kit.UniversalKeystoreKit';

function stringToUint8Array(str: string) {
  let arr: number[] = [];
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

const providerName = "testProviderName";
const extProperties: Array<huksExternalCrypto.HuksExternalCryptoParam> = [
  {
    tag: huksExternalCrypto.HuksExternalCryptoTag.HUKS_EXT_CRYPTO_TAG_ABILITY_NAME,
    value: stringToUint8Array("CryptoExtension")
  }
];
huksExternalCrypto.unregisterProvider(providerName, extProperties)
    .then(() => {
        console.info('promise: unregisterProvider success.');
    });
```

## huksExternalCrypto.getUkeyPinAuthState

getUkeyPinAuthState(resourceId: string, params?: Array\<HuksExternalCryptoParam>): Promise\<HuksExternalPinAuthState>

Obtains the PIN authentication state. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.Huks.CryptoExtension

**Parameters**

| Name  | Type | Mandatory| Description |
| -------- | ------- | ---- | ----------|
| resourceId | string | Yes  | Resource ID, which can be obtained through [openAuthorizeDialog](../apis-device-certificate-kit/js-apis-certManagerDialog.md#certificatemanagerdialogopenauthorizedialog22). The result contains the resource ID.|
| params  | Array\<[HuksExternalCryptoParam](#huksexternalcryptoparam)> | No  | Operation parameters. If this parameter is not passed, no additional parameters are passed to the Extension Ability. If a non-system application passes [HUKS_EXT_CRYPTO_TAG_UID](#huksexternalcryptotag), the parameter is invalid.|

**Return value**

| Type  | Description  |
| -------- | ------- |
| Promise\<[HuksExternalPinAuthState](#huksexternalpinauthstate)> | Promise used to return the authentication result.<br>**HUKS_EXT_CRYPTO_PIN_NO_AUTH**: The PIN authentication fails. **HUKS_EXT_CRYPTO_PIN_AUTH_SUCCEEDED**: The PIN authentication is successful. **HUKS_EXT_CRYPTO_PIN_LOCKED**: The PIN is locked.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [HUKS Error Codes](errorcode-huks.md).

| ID| Error Message     |
| -------- | ------------- |
| 801 | api is not supported. |
| 12000005 | IPC communication failed. |
| 12000006 | the UKey driver operation failed. |
| 12000011 | queried entity does not exist. This may happen because the resource ID has not been opened. |
| 12000012 | Device environment or input parameter is abnormal. This error may occur if the process function is not found, or due to other issues. |
| 12000014 | memory is insufficient. |
| 12000018 | the input parameter is invalid. |
| 12000020 | the provider operation failed. |
| 12000024 | the provider or UKey is busy. |

**Example**

```ts
import { huksExternalCrypto } from '@kit.UniversalKeystoreKit';

const testResourceId = "{\"providerName\":\"testProviderName\", \"bundleName\":\"com.example.cryptoapplication\", \"abilityName\":\"CryptoExtension\",\"index\":{\"key\":\"testKey\"}}";
const extProperties: Array<huksExternalCrypto.HuksExternalCryptoParam> = [];
huksExternalCrypto.getUkeyPinAuthState(testResourceId, extProperties)
    .then((data) => {
      console.info(`promise: getUkeyPinAuthState success, data: ${data}`);
    });
```

## huksExternalCrypto.getProperty

getProperty(resourceId: string, propertyId: string, params?: Array\<HuksExternalCryptoParam>): Promise\<Array\<HuksExternalCryptoParam>>

Obtains a property value. This API uses a promise to return the result.

The **propertyId** parameter indicates the ID of the property to be queried. You are advised to use SKF API names defined in GMT 0016-2023 as property IDs. The supported IDs are as follows:

- SKF_EnumDev 

- SKF_GetDevInfo 

- SKF_EnumApplication 

- SKF_EnumContainer

Since API version 26.0.0, property IDs can be customized, which is provided by the [CryptoExtensionAbility](js-apis-CryptoExtensionAbility.md) implementation party.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Security.Huks.CryptoExtension

**Parameters**

| Name  | Type | Mandatory| Description |
| -------- | ------- | ---- | ----------|
| resourceId | string | Yes  | Resource ID, which can be obtained through [openAuthorizeDialog](../apis-device-certificate-kit/js-apis-certManagerDialog.md#certificatemanagerdialogopenauthorizedialog22). The result returned by this API contains the resource ID.|
| propertyId | string | Yes  | Property name for the search operation, which is the SKF API name defined in GMT 0016-2023. You need to make adaptation based on the API name.|
| params  | Array\<[HuksExternalCryptoParam](#huksexternalcryptoparam)> | No  | Parameters to be passed to [CryptoExtensionAbility](js-apis-CryptoExtensionAbility.md). If this parameter is not passed, no additional parameters are passed to the Extension Ability. If a non-system application passes [HUKS_EXT_CRYPTO_TAG_UID](#huksexternalcryptotag), the parameter is invalid.|

**Return value**

| Type  | Description  |
| -------- | ------- |
| Promise\<Array\<[HuksExternalCryptoParam](#huksexternalcryptoparam)>> | Promise that returns the operation result. If the call is successful, an array of the **HuksExternalCryptoParam** type is returned, containing the properties to be queried.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [HUKS Error Codes](errorcode-huks.md).

| ID| Error Message     |
| -------- | ------------- |
| 801 | API is not supported. |
| 12000005 | IPC communication failed. |
| 12000006 | If the UKey driver operation failed. Possible causes: 1. Error reported when the provider accesses the SKF interface of UKey. |
| 12000011 | If the cached resource ID is not found. |
| 12000012 | Device environment or input parameter is abnormal. This error may occur if the process function is not found, or due to other issues. |
| 12000014 | If the memory is insufficient. |
| 12000018 | Input parameter is invalid. Possible causes: 1. The resourceId or propertyId length is invalid. 2. The params contains invalid tags or invalid value types. |
| 12000020 | If the provider operation failed. Possible causes: 1. The provider experienced an internal processing error. |
| 12000021 | The UKey PIN is locked. |
| 12000023 | The UKey PIN is not authenticated. |
| 12000024 | If the provider or UKey is busy. |

**Example**

```ts
import { huksExternalCrypto } from '@kit.UniversalKeystoreKit';

const testResourceId = JSON.stringify({
  providerName: "testProviderName",
  bundleName: "com.example.cryptoapplication",
  abilityName: "CryptoExtension",
  index: {
    key: "testKey"
  } as ESObject
});

let propertyId = "SKF_EnumDev";
const extProperties: Array<huksExternalCrypto.HuksExternalCryptoParam> = [];

console.info('promise: await huksExternalCrypto getProperty.');
async function testFunction() : Promise<void>
{
  try {
    await huksExternalCrypto.getProperty(testResourceId, propertyId, extProperties)
      .then((data) => {
        console.info(`promise: getProperty success, data: ` + JSON.stringify(data));
      });
  } catch (error) {
    console.error(`promise: getProperty failed, errCode : ${error.code}, errMsg : ${error.message}`);
  }
}
```

## huksExternalCrypto.clearUkeyPinAuthState

clearUkeyPinAuthState(resourceId: string): Promise&lt;void&gt;

Clears the PIN authentication status of a specified resource ID. After the status is cleared, the PIN authentication status changes to **HUKS_EXT_CRYPTO_PIN_NO_AUTH** (unauthenticated). This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Security.Huks.CryptoExtension

**Parameters**

| Name  | Type | Mandatory| Description |
| -------- | ------- | ---- | ----------|
| resourceId | string | Yes  | Resource ID, which can be obtained through [openAuthorizeDialog](../apis-device-certificate-kit/js-apis-certManagerDialog.md#certificatemanagerdialogopenauthorizedialog22). The result contains the resource ID.|

**Return value**

| Type  | Description  |
| -------- | ------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [HUKS Error Codes](errorcode-huks.md).

| ID| Error Message     |
| -------- | ------------- |
| 801 | API is not supported. |
| 12000005 | IPC communication failed. |
| 12000006 | Failed to call the UKey driver interface. Please check the UKey connection and driver status. |
| 12000011 | The cached resource ID not found. |
| 12000012 | Device environment or input parameters are abnormal. This may occur if the process function is null, or due to other issues. |
| 12000014 | The memory is insufficient. |
| 12000018 | The input parameters are invalid. Possible causes: 1. The resourceId length is invalid. |
| 12000020 | The provider operation failed. This means an error occurred in the crypto extension before calling the UKey driver interface. |
| 12000024 | The provider or UKey is busy. |

**Example**

```ts
import { huksExternalCrypto } from '@kit.UniversalKeystoreKit';

const testResourceId = JSON.stringify({
  providerName: "testProviderName",
  bundleName: "com.example.cryptoapplication",
  abilityName: "CryptoExtension",
  index: {
    key: "testKey"
  } as ESObject
});

huksExternalCrypto.clearUkeyPinAuthState(testResourceId)
    .then(() => {
      console.info('promise: clearUkeyPinAuthState success.');
    });
```

## huksExternalCrypto.getResourceId

getResourceId(providerName: string, params: HuksExternalCryptoParam[]): Promise&lt;string&gt;

Obtains the resource ID of the key extension capability. This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Security.Huks.CryptoExtension

**Parameters**

| Name  | Type | Mandatory| Description |
| -------- | ------- | ---- | ----------|
| providerName | string | Yes  | Provider name, which is recommended to contain the vendor information and must be globally unique. The maximum length is 128 bytes.|
| params | [HuksExternalCryptoParam](#huksexternalcryptoparam)[] | Yes  | Property parameters required for obtaining the resource ID. Mandatory tags include [HUKS_EXT_CRYPTO_TAG_ABILITY_NAME](#huksexternalcryptotag), [HUKS_EXT_CRYPTO_TAG_BUNDLE_NAME](#huksexternalcryptotag) and [HUKS_EXT_CRYPTO_TAG_RESOURCE_INFO](#huksexternalcryptotag). If a non-system application passes [HUKS_EXT_CRYPTO_TAG_UID](#huksexternalcryptotag), the parameter is invalid.|

**Return value**

| Type  | Description  |
| -------- | ------- |
| Promise\<string> | Promise used to return the resource ID.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [HUKS Error Codes](errorcode-huks.md).

| ID| Error Message     |
| -------- | ------------- |
| 801 | API is not supported. |
| 12000002 | The ability name, bundle name parameter or resource information is missing. |
| 12000005 | IPC communication failed. |
| 12000011 | The provider is not found. |
| 12000012 | Device environment or input parameters are abnormal. This error may occur if the process function is not found, or due to other issues. |
| 12000014 | The memory is insufficient. |
| 12000018 | Input parameters are invalid. Possible causes: 1. The providerName length is invalid. 2. The parameters contain invalid tags or invalid value types. |
| 12000020 | The provider operation failed. This means an error occurred in the crypto extension before calling the UKey driver interface. |
| 12000024 | The provider or UKey is busy. |

**Example**

```ts
import { huksExternalCrypto } from '@kit.UniversalKeystoreKit';

function stringToUint8Array(str: string) {
  let arr: number[] = [];
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

const providerName = "testProviderName";
const abilityName = "CryptoExtension";
const bundleName = "com.example.cryptoapplication";
// Resource information. The format and content are defined by the vendor.
const resourceInfo = "vendor_defined_resource_info";

const extProperties: Array<huksExternalCrypto.HuksExternalCryptoParam> = [
  {
    tag: huksExternalCrypto.HuksExternalCryptoTag.HUKS_EXT_CRYPTO_TAG_ABILITY_NAME,
    value: stringToUint8Array(abilityName)
  },
  {
    tag: huksExternalCrypto.HuksExternalCryptoTag.HUKS_EXT_CRYPTO_TAG_BUNDLE_NAME,
    value: stringToUint8Array(bundleName)
  },
  {
    tag: huksExternalCrypto.HuksExternalCryptoTag.HUKS_EXT_CRYPTO_TAG_RESOURCE_INFO,
    value: stringToUint8Array(resourceInfo)
  }
];

huksExternalCrypto.getResourceId(providerName, extProperties)
    .then((resourceId) => {
      console.info(`promise: getResourceId success, resourceId: ${resourceId}`);
    });
```

## huksExternalCrypto.openResource

openResource(resourceId: string, params?: HuksExternalCryptoParam[]): Promise&lt;void&gt;

Opens a resource with a specified resource ID. This API uses a promise to return the result.

> **NOTE**
>
> The opened resource must be closed using [closeResource](#huksexternalcryptocloseresource).

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Security.Huks.CryptoExtension

**Parameters**

| Name  | Type | Mandatory| Description |
| -------- | ------- | ---- | ----------|
| resourceId | string | Yes  | Resource ID. You can obtain the key URI as the resource ID from [openAuthorizeDialog](../apis-device-certificate-kit/js-apis-certManagerDialog.md#certificatemanagerdialogopenauthorizedialog22) or obtain the resource ID of the external key management extension through [getResourceId](#huksexternalcryptogetresourceid).|
| params | [HuksExternalCryptoParam](#huksexternalcryptoparam)[] | No  | Parameters to be passed to [CryptoExtensionAbility](js-apis-CryptoExtensionAbility.md). If this parameter is not passed, no additional parameters are passed to the Extension Ability.|

**Return value**

| Type  | Description  |
| -------- | ------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [HUKS Error Codes](errorcode-huks.md).

| ID| Error Message     |
| -------- | ------------- |
| 801 | API is not supported. |
| 12000005 | IPC communication failed. |
| 12000006 | Failed to call the UKey driver interface. Please check the UKey connection and driver status. |
| 12000011 | The cached resource ID is not found. This may happen because the resource ID has not been opened. |
| 12000012 | Device environment or input parameters are abnormal. This error may occur if the process function is not found, or due to other issues. |
| 12000014 | The memory is insufficient. |
| 12000017 | The resource with the resource ID is already open. |
| 12000018 | Input parameters are invalid. Possible causes: 1. The resourceId length is invalid. 2. The parameters contain invalid tags or invalid value types. |
| 12000020 | The provider operation failed. This means an error occurred in the crypto extension before calling the UKey driver interface. |
| 12000024 | The provider or UKey is busy. |
| 12000025 | The opened resources exceed the limit. |

**Example**

```ts
import { huksExternalCrypto } from '@kit.UniversalKeystoreKit';

const testResourceId = JSON.stringify({
  providerName: "testProviderName",
  bundleName: "com.example.cryptoapplication",
  abilityName: "CryptoExtension",
  index: {
    key: "testKey"
  } as ESObject
});

huksExternalCrypto.openResource(testResourceId)
    .then(() => {
      console.info('promise: openResource success.');
    });
```

## huksExternalCrypto.closeResource

closeResource(resourceId: string, params?: HuksExternalCryptoParam[]): Promise&lt;void&gt;

Closes a resource with a specified resource ID. This API uses a promise to return the result.

This API calls [onClearUkeyPinAuthState](js-apis-CryptoExtensionAbility.md#onclearukeypinauthstate) to clear the PIN authentication status associated with the resource, and calls [onFinishSession](js-apis-CryptoExtensionAbility.md#onfinishsession) to clear the session handle associated with the resource.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Security.Huks.CryptoExtension

**Parameters**

| Name  | Type | Mandatory| Description |
| -------- | ------- | ---- | ----------|
| resourceId | string | Yes  | Resource ID. You can obtain the key URI as the resource ID from [openAuthorizeDialog](../apis-device-certificate-kit/js-apis-certManagerDialog.md#certificatemanagerdialogopenauthorizedialog22) or obtain the resource ID of the external key management extension through [getResourceId](#huksexternalcryptogetresourceid).|
| params | [HuksExternalCryptoParam](#huksexternalcryptoparam)[] | No  | Parameters to be passed to [CryptoExtensionAbility](js-apis-CryptoExtensionAbility.md). If this parameter is not passed, no additional parameters are passed to the Extension Ability.|

**Return value**

| Type  | Description  |
| -------- | ------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [HUKS Error Codes](errorcode-huks.md).

| ID| Error Message     |
| -------- | ------------- |
| 801 | API is not supported. |
| 12000005 | IPC communication failed. |
| 12000006 | Failed to call the UKey driver interface. Please check the UKey connection and driver status. |
| 12000012 | Device environment or input parameters are abnormal. This error may occur if the process function is not found, or due to other issues. |
| 12000014 | The memory is insufficient. |
| 12000018 | Input parameters are invalid. Possible causes: 1. The resourceId length is invalid. 2. The parameters contain invalid tags or invalid value types. |
| 12000020 | The provider operation failed. This means an error occurred in the crypto extension before calling the UKey driver interface. |
| 12000024 | The provider or UKey is busy. |

**Example**

```ts
import { huksExternalCrypto } from '@kit.UniversalKeystoreKit';

const testResourceId = JSON.stringify({
  providerName: "testProviderName",
  bundleName: "com.example.cryptoapplication",
  abilityName: "CryptoExtension",
  index: {
    key: "testKey"
  } as ESObject
});

huksExternalCrypto.closeResource(testResourceId)
    .then(() => {
      console.info('promise: closeResource success.');
    });
```

## huksExternalCrypto.setProperty

setProperty(resourceId: string, propertyId: string, params?: HuksExternalCryptoParam[]): Promise&lt;void&gt;

Sets the property value of the UKey resource identified by **resourceId**. This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Security.Huks.CryptoExtension

**Parameters**

| Name  | Type | Mandatory| Description |
| -------- | ------- | ---- | ----------|
| resourceId | string | Yes  | Resource ID. You can obtain the key URI as the resource ID from [openAuthorizeDialog](../apis-device-certificate-kit/js-apis-certManagerDialog.md#certificatemanagerdialogopenauthorizedialog22) or obtain the resource ID of the external key management extension through [getResourceId](#huksexternalcryptogetresourceid).|
| propertyId | string | Yes  | Property name of the setting operation. The value is provided by the [CryptoExtensionAbility](js-apis-CryptoExtensionAbility.md) implementation. You are advised to use the SKF API names defined in GMT 0016-2023 as property IDs.|
| params  | [HuksExternalCryptoParam](#huksexternalcryptoparam)[] | No  | Parameters to be passed to the [CryptoExtensionAbility](js-apis-CryptoExtensionAbility.md), including operation parameters related to the property ID. If this parameter is not passed, no additional parameters are passed to the ExtensionAbility.|

**Return value**

| Type  | Description  |
| -------- | ------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [HUKS Error Codes](errorcode-huks.md).

| ID| Error Message     |
| -------- | ------------- |
| 801 | API is not supported. |
| 12000005 | IPC communication failed. |
| 12000006 | Failed to call the UKey driver interface. Please check the UKey connection and driver status. |
| 12000011 | The cached resource ID not found. |
| 12000012 | Device environment or input parameters are abnormal. This may occur if the process function is null, or due to other issues. |
| 12000014 | The memory is insufficient. |
| 12000018 | The input parameters are invalid. Possible causes: 1. The resourceId or propertyId length is invalid. 2. The parameters contain invalid tags or invalid value types. |
| 12000020 | The provider operation failed. This means an error occurred in the crypto extension before calling the UKey driver interface. |
| 12000021 | The UKey PIN is locked. |
| 12000023 | The UKey PIN is not authenticated. |
| 12000024 | The provider or UKey is busy. |

**Example**

```ts
import { huksExternalCrypto } from '@kit.UniversalKeystoreKit';

const testResourceId = JSON.stringify({
  providerName: "testProviderName",
  bundleName: "com.example.cryptoapplication",
  abilityName: "CryptoExtension",
  index: {
    key: "testKey"
  } as ESObject
});

const propertyId = "SKF_SetDevInfo";
const extProperties: Array<huksExternalCrypto.HuksExternalCryptoParam> = [];

async function testFunction() : Promise<void>
{
  try {
    await huksExternalCrypto.setProperty(testResourceId, propertyId, extProperties)
      .then(() => {
        console.info('promise: setProperty success.');
      });
  } catch (error) {
    console.error(`promise: setProperty failed, errCode : ${error.code}, errMsg : ${error.message}`);
  }
}
```

## huksExternalCrypto.getErrorInfo

getErrorInfo(): HuksExternalErrorInfo

Obtains the detailed error information about the latest external key operation in synchronous mode. The error information is returned by the key management extension.

> **NOTE**
>
> 1. This API returns the detailed error information (**errno** and **errorDesc**) of the key management extension. HUKS internal errors are thrown through API exceptions.
> 2. If the key management extension does not return detailed error information (the value of **errno** is **0**), the value of **errorDesc** is an empty string. In this case, you need to determine the error cause based on the API error code.
> 3. You are advised to call this API immediately after an operation fails to obtain detailed error information.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Security.Huks.CryptoExtension

**Return value**

| Type| Description|
| ---- | ---- |
| [HuksExternalErrorInfo](#huksexternalerrorinfo) | Error information about the latest operation.|

**Example**

```ts
import { huksExternalCrypto } from '@kit.UniversalKeystoreKit';

function stringToUint8Array(str: string) {
  let arr: number[] = [];
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

const resourceId = JSON.stringify({
  providerName: "testProviderName",
  bundleName: "com.example.cryptoapplication",
  abilityName: "CryptoExtension",
  index: "testKey"
});
const pin = "123456"; // This is an example. Replace it with the actual user PIN in real services.
const params: Array<huksExternalCrypto.HuksExternalCryptoParam> = [
  {
    tag: huksExternalCrypto.HuksExternalCryptoTag.HUKS_EXT_CRYPTO_TAG_UKEY_PIN,
    value: stringToUint8Array(pin)
  }
];

async function testFunction() : Promise<void>
{
  try {
    await huksExternalCrypto.authUkeyPin(resourceId, params);
  } catch (error) {
    const errorInfo = huksExternalCrypto.getErrorInfo();
    console.info(`errno: ${errorInfo.errno}`);
    console.info(`errorDesc: ${errorInfo.errorDesc}`);
  }
}
```