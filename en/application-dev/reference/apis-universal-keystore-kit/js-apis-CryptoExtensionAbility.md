# @ohos.security.CryptoExtensionAbility (Key Extension Ability)

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=9152c268f46614a686fc0194817d9148fb47574b translatedAt=2026-08-14T09:00:13.365Z pushedAt=2026-08-15T09:11:15.653Z -->

Provides the external key extension abilities, including resource management, PIN authentication management, cryptographic operations, and common operations.

Functions and restrictions of **ExtensionAbility**:

1. Device management: A single **ExtensionAbility** implementation supports a maximum of 10 UKey connections.

2. Handle management: Application-based handle resource management is supported for the same UKey resource (for example, the keys in a container).

   - Multiple OpenHarmony applications can open the same UKey key resource. For example, after OpenHarmony application 1 opens container A, OpenHarmony application 2 can also open container A.

   - Multiple OpenHarmony applications can operate the same UKey key resource. For example, after OpenHarmony application 1 performs private key signing on container A, OpenHarmony application 2 can also perform private key signing on container A after verifying the PIN. The two applications do not affect each other.

3. Key session management: Three-segment key management is supported. Signature verification for a single signature requires the [onInitSession](#oninitsession)/[onUpdateSession](#onupdatesession)/[onFinishSession](#onfinishsession) functions to be used together in three steps. In addition, session management and key session status caching are supported.

   - **init**: Initializes the key session and returns the session handle information.

   - **update**: Passes group data, performs cryptographic operations on the group data, updates the key session information, and returns the intermediate data (if any).

   - **finish**: Passes the last group of data, returns the key, ends the key session, and returns the final result.

4. Authentication state management: Application-based authentication state management is supported. After OpenHarmony application 1 verifies the PIN of UKey application A, if OpenHarmony application 2 needs to access UKey application A, PIN authentication is also required.

5. Certificate query: Enumeration of all certificates and query of certificates in a single container based on certificate type are supported.

> **Description**
>
> The initial APIs of this module are supported since API version 22. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Constraints

As a key management extension capability, **CryptoExtensionAbility** is subject to system control over capabilities such as network, Bluetooth, and location to reduce the security attack surface and ensure proper implementation. References to some modules are not supported. For details, see [Appendix](#appendix).

## Modules to Import

```ts
import { huks, huksExternalCrypto, CryptoExtensionAbility } from '@kit.UniversalKeystoreKit';
```

## HuksCryptoExtensionResultCode

Enumerates the values of **resultCode** in [HuksCryptoExtensionResult](#hukscryptoextensionresult).

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Security.Huks.CryptoExtension

| Name| Value| Description|
| ------ | ---- | ------ |
| HUKS_CRYPTO_EXTENSION_ERR_EXTENSION_FAIL | 34800000 | Key extension error. Possible causes:<br>1. Invalid input parameters.<br>2. An unrecoverable error state occurs in the key extension.|
| HUKS_CRYPTO_EXTENSION_ERR_UKEY_NOT_EXIST | 34800001 | The UKey does not exist. Possible causes:<br>1. The UKey has been removed.<br>2. The key extension is in an incorrect UKey state.|
| HUKS_CRYPTO_EXTENSION_ERR_UKEY_DRIVER_FAIL | 34800002 | An unknown error occurs in the UKey driver.|
| HUKS_CRYPTO_EXTENSION_ERR_PIN_NO_AUTH | 34800003 | The UKey PIN is not authenticated. Authenticate the UKey PIN first by calling [onAuthUkeyPin](#onauthukeypin).|
| HUKS_CRYPTO_EXTENSION_ERR_HANDLE_NOT_EXIST | 34800004 | The handle does not exist. Possible causes:<br>1. Invalid handle.<br>2. The HUKS service and key extension states are inconsistent. The handle held by the HUKS service fails to be released due to an exception.|
| HUKS_CRYPTO_EXTENSION_ERR_HANDLE_UNAVAILABLE | 34800005 | The handle is unavailable. Possible causes:<br>The key extension and UKey states are inconsistent.|
| HUKS_CRYPTO_EXTENSION_ERR_PIN_INCORRECT | 34800006 | Incorrect UKey PIN. Check the entered PIN.|
| HUKS_CRYPTO_EXTENSION_ERR_PIN_LOCKED | 34800007 | The UKey PIN is locked. Possible cause: <br>The PIN has been entered incorrectly too many times. |

## HuksCryptoExtensionCertInfo

Defines the elements in the **certs** array of [HuksCryptoExtensionResult](#hukscryptoextensionresult).

**System capability**: SystemCapability.Security.Huks.CryptoExtension

| Name| Type   | Read-Only| Optional| Description |
| ------ | --------- | ---- | ---- | ------ |
| purpose    | [certificateManager.CertificatePurpose](../apis-device-certificate-kit/js-apis-certManager.md#certificatepurpose22)  | No  | No  | Purpose of the key corresponding to the certificate chain.|
| resourceId  | string | No  | No  | Resource ID, in JSON format, which can be mapped to a resource in the UKey.|
| cert  | Uint8Array | No  | No  | Certificate.|

## HuksCryptoExtensionResult

Defines the common return value types of APIs.

**System capability**: SystemCapability.Security.Huks.CryptoExtension

| Name| Type | Read-Only| Optional| Description|
| ------ | ------ | ---- | ---- | ------ |
| resultCode  | number | No  | No  | Error code.|
| handle  | string | No  | Yes  | Resource handle.|
| authState  | number | No  | Yes  | Authentication state.|
| retryCount  | number | No  | Yes  | Number of remaining PIN authentication attempts. If the value is **0**, there are no remaining attempts.|
| certs  | Array<[HuksCryptoExtensionCertInfo](#hukscryptoextensioncertinfo)> | No  | Yes  | Certificate.|
| property  | Array<[huksExternalCrypto.HuksExternalCryptoParam](js-apis-huksExternalCrypto.md#huksexternalcryptoparam)> | No  | Yes  | Property.|
| outData  | Uint8Array | No  | Yes  | Returned data.|
| resourceId | string | No| Yes| Returned resource ID. The default value is empty.<br>**Since**: 26.0.0<br>**Model restriction**: This API can be used only in the stage model.|
| errInfo | [huksExternalCrypto.HuksExternalErrorInfo](js-apis-huksExternalCrypto.md#huksexternalerrorinfo) | No | Yes | Detailed error information returned. The default value is **{0,""}**.<br>**Since:** 26.0.0<br>**Model restriction:** This API can be used only in the stage model. |

## HuksCryptoExtensionParam

Defines the key extension operation parameter, which is used to specify the attribute tag and corresponding value of the operation.

**Since:** 26.0.0

**System capability:** SystemCapability.Security.Huks.CryptoExtension

**Model restriction:** This API can be used only in the stage model.

| Name | Type  | Read-Only | Optional | Description |
| ------ | ------ | ---- | ---- | ------ |
| tag  | [huksExternalCrypto.HuksExternalCryptoTag](js-apis-huksExternalCrypto.md#huksexternalcryptotag) \| [huks.HuksTag](js-apis-huks.md#hukstag) \| number | No   | No   | Tag. |
| value  | boolean \| number \| bigint \| Uint8Array | No   | No   | Value corresponding to the tag. |

## HuksCryptoExtensionParams

Defines the key extension operation parameter set, which is used to pass the attributes and input data required for the operation.

**Since:** 26.0.0

**System capability:** SystemCapability.Security.Huks.CryptoExtension

**Model restriction:** This API can be used only in the stage model.

| Name | Type                                | Read-Only | Optional | Description         |
| ------ | ----------------------------------- | ---- | ---- | ------------ |
| properties | [HuksCryptoExtensionParam](#hukscryptoextensionparam)[] | No   | No   | Properties, used to store an array of **HuksCryptoExtensionParam**. The default value is **undefined**. |
| inData     | Uint8Array        | No   | Yes   | Input data. The default value is **undefined**. |

## CryptoExtensionAbility

Provides the key extension capabilities, including API description required for external key management extension, such as enabling/disabling resources, PIN authentication management, key session operations, certificate management, key generation and import, and common operations. The driver vendor needs to inherit **CryptoExtensionAbility** and implement related APIs. After the capabilities are registered using [registerProvider](js-apis-huksExternalCrypto.md#huksexternalcryptoregisterprovider), HUKS and certificate management open the corresponding key management extension capabilities to applications.

**CryptoExtensionAbility** can isolate the implementation differences of different UKey driver vendors.

**System capability**: SystemCapability.Security.Huks.CryptoExtension

### onOpenResource

onOpenResource(resourceId: string, params: Array\<huksExternalCrypto.HuksExternalCryptoParam> | HuksCryptoExtensionParam[]): Promise\<HuksCryptoExtensionResult>

Opens the UKey key resource based on the **resourceId** parameter. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.Huks.CryptoExtension

**Parameters**

| Name  | Type| Mandatory| Description|
| -------- | --------- | ---- | -------- |
| resourceId | string | Yes  | Resource ID.|
| params  | Array\<[huksExternalCrypto.HuksExternalCryptoParam](js-apis-huksExternalCrypto.md#huksexternalcryptoparam)> \| [HuksCryptoExtensionParam](#hukscryptoextensionparam)[] | Yes   | Passed parameter. The application identity is carried by the [HUKS_EXT_CRYPTO_TAG_UID](js-apis-huksExternalCrypto.md#huksexternalcryptotag) parameter. |

**Return value**

| Type| Description|
| ---------- | ----------- |
| Promise\<[HuksCryptoExtensionResult](#hukscryptoextensionresult)> | Promise used to return the result. If the call is successful, **resultCode** is **0** and handle contains the resource handle information. If the call fails, **resultCode** contains the error code.<br>Possible error code values:<br>**34800000**: Key extension error.<br>**34800001**: The UKey does not exist.<br>**34800002**: UKey driver error.<br>**34800004**: The handle does not exist.<br>For details, see [HuksCryptoExtensionResultCode](#hukscryptoextensionresultcode).|

**Example**

```ts
import { huksExternalCrypto, HuksCryptoExtensionParam, CryptoExtensionAbility, HuksCryptoExtensionResult } from '@kit.UniversalKeystoreKit';

export default class CryptoExtension extends CryptoExtensionAbility {
  onOpenResource(resourceId: string, params: Array<huksExternalCrypto.HuksExternalCryptoParam> | HuksCryptoExtensionParam[]): Promise<HuksCryptoExtensionResult> {
    // Parse resourceId, open the underlying handle, and map it to a new handle for return.
    let result: HuksCryptoExtensionResult = {
      resultCode: 0,
      handle: "test handle"
    };

    // ...
    return Promise.resolve(result);
  }
}
```

### onCloseResource

onCloseResource(handle: string, params: Array\<huksExternalCrypto.HuksExternalCryptoParam> | HuksCryptoExtensionParam[]): Promise\<HuksCryptoExtensionResult>

Closes the key resource of a UKey based on the **handle** parameter. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.Huks.CryptoExtension

**Parameters**

| Name  | Type| Mandatory| Description |
| -------- | ------ | ---- | ------ |
| handle | string | Yes  | Session handle. |
| params  | Array\<[huksExternalCrypto.HuksExternalCryptoParam](js-apis-huksExternalCrypto.md#huksexternalcryptoparam)> \| [HuksCryptoExtensionParam](#hukscryptoextensionparam)[] | Yes | Passed parameter. The application identity is carried by the [HUKS_EXT_CRYPTO_TAG_UID](js-apis-huksExternalCrypto.md#huksexternalcryptotag) parameter. |

**Return value**

| Type| Description|
| ----------- | ------------- |
| Promise\<[HuksCryptoExtensionResult](#hukscryptoextensionresult)> | Promise used to return the result. If the call is successful, **resultCode** is **0**, indicating that the resource is closed successfully. If the call fails, **resultCode** contains the error code.<br>Possible error code values:<br>34800000 Key extension error.<br>34800002 UKey driver error.<br>34800004 Handle does not exist.<br>34800005 The handle is unavailable.<br>For details, see [HuksCryptoExtensionResultCode](#hukscryptoextensionresultcode).|

**Example**

```ts
import { huksExternalCrypto, HuksCryptoExtensionParam, CryptoExtensionAbility, HuksCryptoExtensionResult } from '@kit.UniversalKeystoreKit';

export default class CryptoExtension extends CryptoExtensionAbility {
  onCloseResource(handle: string, params: Array<huksExternalCrypto.HuksExternalCryptoParam> | HuksCryptoExtensionParam[]): Promise<HuksCryptoExtensionResult> {
    // Close the handle. If the underlying handle needs to be closed, close it.
    const result: HuksCryptoExtensionResult = {
        resultCode: 0,
    };

    // ...
    return Promise.resolve(result);
  }
}
```

### onGetProperty

onGetProperty(handle: string, propertyId: string, params: Array\<huksExternalCrypto.HuksExternalCryptoParam> | HuksCryptoExtensionParam[]): Promise\<HuksCryptoExtensionResult>

Obtains the property based on the **handle** and **propertyId** parameters. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.Huks.CryptoExtension

**Parameters**

| Name  | Type | Mandatory| Description |
| -------- | ----- | ---- | ------|
| handle | string | Yes  | Resource handle.|
| propertyId | string | Yes  | Property name for the search operation, which is the SKF API name defined in GMT 0016-2023. The service needs to be adapted to the API name.|
| params  | Array\<[huksExternalCrypto.HuksExternalCryptoParam](js-apis-huksExternalCrypto.md#huksexternalcryptoparam)> \| [HuksCryptoExtensionParam](#hukscryptoextensionparam)[] | Yes | Passed parameter. The application identity is carried by the [HUKS_EXT_CRYPTO_TAG_UID](js-apis-huksExternalCrypto.md#huksexternalcryptotag) parameter. |

**Return value**

| Type   | Description  |
| -------- | -----------|
| Promise\<[HuksCryptoExtensionResult](#hukscryptoextensionresult)> | Promise used to return the result. When the call succeeds, **resultCode** is **0**, and the **property** member of **HuksCryptoExtensionResult** is non-empty, including the obtained attribute carried by the [HUKS_EXT_CRYPTO_TAG_EXTRA_DATA](js-apis-huksExternalCrypto.md#huksexternalcryptotag) parameter. On call failure, **resultCode** carries error code information.<br>Possible error codes:<br>34800000 key extension error.<br>34800002 UKey driver error.<br>34800003 UKey PIN unauthenticated.<br>34800004 handle does not exist.<br>34800005 handle unavailable.<br>34800007 UKey PIN locked.<br>For the specific meaning, see [HuksCryptoExtensionResultCode](#hukscryptoextensionresultcode). |

**Example**

```ts
import { huksExternalCrypto, HuksCryptoExtensionParam, CryptoExtensionAbility, HuksCryptoExtensionResult } from '@kit.UniversalKeystoreKit';

export default class CryptoExtension extends CryptoExtensionAbility {
  onGetProperty(handle: string, propertyId: string, params: Array<huksExternalCrypto.HuksExternalCryptoParam> | HuksCryptoExtensionParam[]): Promise<HuksCryptoExtensionResult> {
    // Execute the related function based on propertyId. The function parameters are obtained from params. The output data is encapsulated in the property field of the return value and carried by HUKS_EXT_CRYPTO_TAG_EXTRA_DATA.
    const emptyArray: Array<huksExternalCrypto.HuksExternalCryptoParam> = [];
    const result: HuksCryptoExtensionResult = {
      resultCode: 0,
      property: emptyArray
    };

    // ...
    return Promise.resolve(result);
  }
}
```

### onSetProperty

onSetProperty(handle: string, propertyId: string, params: HuksCryptoExtensionParam[]): Promise\<HuksCryptoExtensionResult>

Sets the property based on the **handle** and **propertyId** parameters. This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Security.Huks.CryptoExtension

**Parameters**

| Name  | Type | Mandatory| Description |
| -------- | ----- | ---- | ------|
| handle | string | Yes  | Resource handle.|
| propertyId | string | Yes  | Property name for the setting operation. You are advised to use the name of the corresponding SKF API defined in GMT 0016-2023 as the property ID.|
| params  | [HuksCryptoExtensionParam](#hukscryptoextensionparam)[] | Yes | Passed parameter, which includes the operation parameters related to **propertyId**. The application identity is carried by the [HUKS_EXT_CRYPTO_TAG_UID](js-apis-huksExternalCrypto.md#huksextensioncryptotaguid) parameter. |

**Return value**

| Type   | Description  |
| -------- | -----------|
| Promise\<[HuksCryptoExtensionResult](#hukscryptoextensionresult)> | Promise object. When the call succeeds, **resultCode** is 0, indicating that the attribute is set successfully. When the call fails, **resultCode** carries error code information.<br>Possible error codes:<br>34800000 Key extension error. Possible cause:<br>1. Invalid input parameter.<br>2. The key extension encounters an unresolvable error state.<br>34800002 UKey driver error.<br>34800003 The UKey PIN is unauthenticated. Authenticate the UKey PIN first.<br>34800004 The handle does not exist. Possible cause:<br>1. Invalid handle.<br>2. The states of the HUKS service and the key extension are inconsistent. Due to an exception, the handle held by the HUKS service is not released.<br>34800005 The handle is unavailable. Possible cause:<br>The states of the key extension and the UKey are inconsistent.<br>34800007 The UKey PIN is locked. Possible cause:<br>The PIN is entered incorrectly too many times.<br>For the specific meaning, see [HuksCryptoExtensionResultCode](#hukscryptoextensionresultcode). |

**Example**

```ts
import { HuksCryptoExtensionParam, CryptoExtensionAbility, HuksCryptoExtensionResult } from '@kit.UniversalKeystoreKit';

export default class CryptoExtension extends CryptoExtensionAbility {
  onSetProperty(handle: string, propertyId: string, params: HuksCryptoExtensionParam[]): Promise<HuksCryptoExtensionResult> {
    // Perform related setting operations based on propertyId. The operation parameters are obtained from params.
    const result: HuksCryptoExtensionResult = {
      resultCode: 0
    };

    // ...
    return Promise.resolve(result);
  }
}
```

### onAuthUkeyPin

onAuthUkeyPin(handle: string, params: Array\<huksExternalCrypto.HuksExternalCryptoParam> | HuksCryptoExtensionParam[]): Promise\<HuksCryptoExtensionResult>

Requests the UKey PIN authentication. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.Huks.CryptoExtension

**Parameters**

| Name  | Type  | Mandatory| Description  |
| ------ | ------ | ---- | ------- |
| handle | string  | Yes  | Resource handle.  |
| params  | Array\<[huksExternalCrypto.HuksExternalCryptoParam](js-apis-huksExternalCrypto.md#huksexternalcryptoparam)> \| [HuksCryptoExtensionParam](#hukscryptoextensionparam)[] | Yes   | Passed parameter. The application identity is carried by the [HUKS_EXT_CRYPTO_TAG_UID](js-apis-huksExternalCrypto.md#huksexternalcryptotag) parameter. |

**Return value**

| Type| Description|
| -------- | --------|
| Promise\<[HuksCryptoExtensionResult](#hukscryptoextensionresult)> | Promise object. When the call succeeds, **resultCode** is **0** and **authState** is not **0**, indicating that the authentication request succeeds. When the call fails, **resultCode** carries the error code information.<br>Possible error codes:<br>34800000 key extension error.<br>34800002 UKey driver error.<br>34800004 Handle does not exist.<br>34800005 Handle unavailable.<br>34800006 UKey PIN code error.<br>34800007 UKey PIN code locked.<br>For the specific meaning, see [HuksCryptoExtensionResultCode](#hukscryptoextensionresultcode). |

**Example**

```ts
import { huksExternalCrypto, HuksCryptoExtensionParam, CryptoExtensionAbility, HuksCryptoExtensionResult } from '@kit.UniversalKeystoreKit';

export default class CryptoExtension extends CryptoExtensionAbility {
  onAuthUkeyPin(handle: string, params: Array<huksExternalCrypto.HuksExternalCryptoParam> | HuksCryptoExtensionParam[]): Promise<HuksCryptoExtensionResult> {
    // Perform PIN authentication and maintain the PIN authentication state of the application.
    const result: HuksCryptoExtensionResult = {
      resultCode: 0,
      authState: 1
    };

    // ...
    return Promise.resolve(result);
  }
}
```

### onGetUkeyPinAuthState

onGetUkeyPinAuthState(handle: string, params: Array\<huksExternalCrypto.HuksExternalCryptoParam> | HuksCryptoExtensionParam[]): Promise\<HuksCryptoExtensionResult>

Obtains the PIN authentication state of a UKey. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.Huks.CryptoExtension

**Parameters**

| Name  | Type | Mandatory| Description  |
| -------- | ------- | ---- | -------|
| handle | string | Yes  | Resource handle.|
| params  | Array\<[huksExternalCrypto.HuksExternalCryptoParam](js-apis-huksExternalCrypto.md#huksexternalcryptoparam)> \| [HuksCryptoExtensionParam](#hukscryptoextensionparam)[] | Yes   | Passed parameter. The application identity is carried by the [HUKS_EXT_CRYPTO_TAG_UID](js-apis-huksExternalCrypto.md#huksexternalcryptotag) parameter. |

**Return value**

| Type  | Description |
| -------- | ------- |
| Promise\<[HuksCryptoExtensionResult](#hukscryptoextensionresult)> | Promise used to return the result. If the call is successful, **resultCode** is **0**, and the **authState** of **HuksCryptoExtensionResult** contains the obtained PIN authentication state. If the call fails, **resultCode** contains the error code.<br>Possible error code values:<br>34800000 Key extension error.<br>34800002 UKey driver error.<br>34800004 Handle does not exist.<br>34800005 The handle is unavailable.<br>For details, see [HuksCryptoExtensionResultCode](#hukscryptoextensionresultcode).|

**Example**

```ts
import { huksExternalCrypto, HuksCryptoExtensionParam, CryptoExtensionAbility, HuksCryptoExtensionResult } from '@kit.UniversalKeystoreKit';

export default class CryptoExtension extends CryptoExtensionAbility {
  onGetUkeyPinAuthState(handle: string, params: Array<huksExternalCrypto.HuksExternalCryptoParam> | HuksCryptoExtensionParam[]): Promise<HuksCryptoExtensionResult> {
    // Query the PIN authentication state.
    const result: HuksCryptoExtensionResult = {
      resultCode: 0,
      authState: 1
    };

    // ...
    return Promise.resolve(result);
  }
}
```

### onClearUkeyPinAuthState

onClearUkeyPinAuthState(handle: string, params: Array\<huksExternalCrypto.HuksExternalCryptoParam> | HuksCryptoExtensionParam[]): Promise\<HuksCryptoExtensionResult>

Clears the PIN authentication state of the application. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.Huks.CryptoExtension

**Parameters**

| Name  | Type  | Mandatory| Description|
| -------- | ----- | ---- | ------|
| handle  | string | Yes  | Session handle.|
| params  | Array\<[huksExternalCrypto.HuksExternalCryptoParam](js-apis-huksExternalCrypto.md#huksexternalcryptoparam)> \| [HuksCryptoExtensionParam](#hukscryptoextensionparam)[] | Yes   | Passed parameter. The application identity is carried by the [HUKS_EXT_CRYPTO_TAG_UID](js-apis-huksExternalCrypto.md#huksexternalcryptotag) parameter. |

**Return value**

| Type| Description|
| ------------ | ---------|
| Promise\<[HuksCryptoExtensionResult](#hukscryptoextensionresult)> | Promise used to return the result. If the call is successful, **resultCode** is **0**, indicating that the PIN authentication state is cleared successfully. If the call fails, **resultCode** contains the error code.<br>Possible error code values:<br>34800000 Key extension error.<br>34800002 UKey driver error.<br>34800004 Handle does not exist.<br>34800005 The handle is unavailable.<br>For details, see [HuksCryptoExtensionResultCode](#hukscryptoextensionresultcode).|

**Example**

```ts
import { huksExternalCrypto, HuksCryptoExtensionParam, CryptoExtensionAbility, HuksCryptoExtensionResult } from '@kit.UniversalKeystoreKit';

export default class CryptoExtension extends CryptoExtensionAbility {
  onClearUkeyPinAuthState(handle: string, params: Array<huksExternalCrypto.HuksExternalCryptoParam> | HuksCryptoExtensionParam[]): Promise<HuksCryptoExtensionResult> {
    const result: HuksCryptoExtensionResult = {
      resultCode: 0
    };

    // ...
    return Promise.resolve(result);
  }
}
```

### onInitSession

onInitSession(handle: string, params: huks.HuksOptions | HuksCryptoExtensionParams): Promise\<HuksCryptoExtensionResult>

Initializes a key session. (The first operation of the Init-Update-Finish process.) This API uses a promise to return the result.

**System capability**: SystemCapability.Security.Huks.CryptoExtension

**Parameters**

| Name  | Type| Mandatory| Description|
| -------- | ----- | ---- | ------- |
| handle | string                      | Yes  | Resource handle.|
| params  | [huks.HuksOptions](js-apis-huks.md#huksoptions) \| [HuksCryptoExtensionParams](#hukscryptoextensionparams)  | Yes   | Passed parameter. The application identity is carried by the [HUKS_EXT_CRYPTO_TAG_UID](js-apis-huksExternalCrypto.md#huksexternalcryptotag) parameter. |

**Return value**

| Type| Description|
| --------- | ---------|
| Promise\<[HuksCryptoExtensionResult](#hukscryptoextensionresult)> | Promise used to return the result. When the call succeeds, **resultCode** is **0** and **handle** is a non-empty member. When the call fails, **resultCode** carries error code information.<br>Possible error codes:<br>34800000 key extension error.<br>34800002 UKey driver error.<br>34800003 UKey PIN unauthenticated.<br>34800004 Handle does not exist.<br>34800005 Handle unavailable.<br>34800007 UKey PIN code locked.<br>For the specific meaning, see [HuksCryptoExtensionResultCode](#hukscryptoextensionresultcode). |

**Example**

```ts
import { huks, HuksCryptoExtensionParams, CryptoExtensionAbility, HuksCryptoExtensionResult } from '@kit.UniversalKeystoreKit';

export default class CryptoExtension extends CryptoExtensionAbility {
  onInitSession(handle: string, params: huks.HuksOptions | HuksCryptoExtensionParams): Promise<HuksCryptoExtensionResult> {
    const result: HuksCryptoExtensionResult = {
      resultCode: 0,
      handle: "test handle"
    };

    // ...
    return Promise.resolve(result);
  }
}
```

### onUpdateSession

onUpdateSession(initHandle: string, params: huks.HuksOptions | HuksCryptoExtensionParams): Promise\<HuksCryptoExtensionResult>

Updates a key session. (The second operation of the Init-Update-Finish process.) This API uses a promise to return the result.

**System capability**: SystemCapability.Security.Huks.CryptoExtension

**Parameters**

| Name  | Type | Mandatory| Description|
| -------- | ----- | ---- | ------|
| initHandle | string | Yes  | Resource handle.  |
| params  | [huks.HuksOptions](js-apis-huks.md#huksoptions) \| [HuksCryptoExtensionParams](#hukscryptoextensionparams)  | Yes   | Passed parameter. The application identity is carried by the [HUKS_EXT_CRYPTO_TAG_UID](js-apis-huksExternalCrypto.md#huksexternalcryptotag) parameter. |

**Return value**

| Type| Description|
| --------- | ---------|
| Promise\<[HuksCryptoExtensionResult](#hukscryptoextensionresult)> | Promise used to return the result. When the call succeeds, **resultCode** is **0**. When the call fails, **resultCode** carries error code information.<br>Possible error codes:<br>34800000 Key extension error.<br>34800002 UKey driver error.<br>34800003 UKey PIN unauthenticated.<br>34800004 Handle does not exist.<br>34800005 Handle unavailable.<br>34800007 UKey PIN code locked.<br>For the specific meaning, see [HuksCryptoExtensionResultCode](#hukscryptoextensionresultcode). |

**Example**

```ts
import { huks, HuksCryptoExtensionParams, CryptoExtensionAbility, HuksCryptoExtensionResult } from '@kit.UniversalKeystoreKit';

export default class CryptoExtension extends CryptoExtensionAbility {
  onUpdateSession(initHandle: string, params: huks.HuksOptions | HuksCryptoExtensionParams): Promise<HuksCryptoExtensionResult> {
    let outBuffer: Uint8Array = new Uint8Array(1024);
    const result: HuksCryptoExtensionResult = {
      resultCode: 0,
      outData: outBuffer
    };

    // ...
    return Promise.resolve(result);
  }
}
```

### onFinishSession

onFinishSession(initHandle: string, params: huks.HuksOptions | HuksCryptoExtensionParams): Promise\<HuksCryptoExtensionResult>

Ends a key session. (The last operation of the Init-Update-Finish process.) This API uses a promise to return the result.

**System capability**: SystemCapability.Security.Huks.CryptoExtension

**Parameters**

| Name  | Type| Mandatory| Description |
| -------- | -------- | ---- | --------- |
| initHandle | string  | Yes  | Resource handle.|
| params  | [huks.HuksOptions](js-apis-huks.md#huksoptions) \| [HuksCryptoExtensionParams](#hukscryptoextensionparams)  | Yes   | Passed parameter. The application identity can be carried by the [HUKS_EXT_CRYPTO_TAG_UID](js-apis-huksExternalCrypto.md#huksexternalcryptotag) parameter. It also includes algorithm parameters (algorithm type, padding mode, etc.). |

**Return value**

| Type| Description|
| ------- | ---------- |
| Promise\<[HuksCryptoExtensionResult](#hukscryptoextensionresult)> | Promise used to return the result. When the call succeeds, **resultCode** is **0**. When the call fails, **resultCode** carries error code information.<br>Possible error codes:<br>34800000 Key extension error.<br>34800002 UKey driver error.<br>34800003 UKey PIN code unauthenticated.<br>34800004 Handle does not exist.<br>34800005 Handle unavailable.<br>34800007 UKey PIN code locked.<br>For the specific meaning, see [HuksCryptoExtensionResultCode](#hukscryptoextensionresultcode). |

**Example**

```ts
import { huks, HuksCryptoExtensionParams, CryptoExtensionAbility, HuksCryptoExtensionResult } from '@kit.UniversalKeystoreKit';

export default class CryptoExtension extends CryptoExtensionAbility {
  onFinishSession(initHandle: string, params: huks.HuksOptions | HuksCryptoExtensionParams): Promise<HuksCryptoExtensionResult> {
    let outBuffer: Uint8Array = new Uint8Array(1024);
    const result: HuksCryptoExtensionResult = {
      resultCode: 0,
      outData: outBuffer
    };

    // ...
    return Promise.resolve(result);
  }
}
```

### onExportCertificate

onExportCertificate(resourceId: string, params?: Array\<huksExternalCrypto.HuksExternalCryptoParam> | HuksCryptoExtensionParam[]): Promise\<HuksCryptoExtensionResult>

Queries the certificate of a specified resource ID. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.Huks.CryptoExtension

**Parameters**

| Name  | Type | Mandatory| Description|
| -------- | ---------- | ---- | --------- |
| resourceId | string | Yes  | Resource ID. It is attached to [HuksCryptoExtensionCertInfo](#hukscryptoextensioncertinfo).|
| params  | Array\<[huksExternalCrypto.HuksExternalCryptoParam](js-apis-huksExternalCrypto.md#huksexternalcryptoparam)> \| [HuksCryptoExtensionParam](#hukscryptoextensionparam)[]  | No   | Operation attribute. By default, a certificate of the signature type is obtained. You can also use the parameter [HUKS_EXT_CRYPTO_TAG_PURPOSE](js-apis-huksExternalCrypto.md#huksexternalcryptotag) to specify the certificate type. Supported types include signature verification, encryption and decryption, and so on. |

**Return value**

| Type | Description |
| ---------- | --------- |
| Promise\<[HuksCryptoExtensionResult](#hukscryptoextensionresult)> | Promise used to return the result. If the call is successful, **certs** contains the single certificate obtained. If the call fails, **resultCode** contains the error code.<br>Possible error code values:<br>34800000 Key extension error.<br>34800001 The UKey does not exist.<br>34800002 UKey driver error.<br>34800004 Handle does not exist.<br>For details, see [HuksCryptoExtensionResultCode](#hukscryptoextensionresultcode).|

**Example**

```ts
import { huksExternalCrypto, CryptoExtensionAbility, HuksCryptoExtensionResult,
  HuksCryptoExtensionCertInfo } from '@kit.UniversalKeystoreKit';

export default class CryptoExtension extends CryptoExtensionAbility {
  onExportCertificate(resourceId: string, params?: Array<huksExternalCrypto.HuksExternalCryptoParam> | HuksCryptoExtensionParam[]): Promise<HuksCryptoExtensionResult> {
    const certInfoSetArray: Array<HuksCryptoExtensionCertInfo> = []
    const result: HuksCryptoExtensionResult = {
      resultCode: 0,
      certs: certInfoSetArray
    };

    // ...
    return Promise.resolve(result);
  }
}
```

### onEnumCertificates

onEnumCertificates(params?: Array\<huksExternalCrypto.HuksExternalCryptoParam> | HuksCryptoExtensionParam[]): Promise\<HuksCryptoExtensionResult>

Obtains the certificate information of all UKey devices under an extension. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.Huks.CryptoExtension

**Parameters**

| Name  | Type| Mandatory| Description  |
| -------- | -----| ---- | ---------- |
| params  | Array\<[huksExternalCrypto.HuksExternalCryptoParam](js-apis-huksExternalCrypto.md#huksexternalcryptoparam)> \| [HuksCryptoExtensionParam](#hukscryptoextensionparam)[]  | No   | Operation attribute. By default, a [certificate](../../security/DeviceCertificateKit/certManager-overview.md) of the signing type is obtained. You can also use the parameter [HUKS_EXT_CRYPTO_TAG_PURPOSE](js-apis-huksExternalCrypto.md#huksexternalcryptotag) to specify the certificate type. Supported types include signing and signature verification, encryption and decryption, and so on. |

**Return value**

| Type| Description|
| ---------- | ---------|
| Promise\<[HuksCryptoExtensionResult](#hukscryptoextensionresult)> | Promise used to return the result. If the call is successful, **certs** contains all the obtained certificates. If the call fails, **resultCode** contains the error code.<br>Possible error code values:<br>34800000 Key extension error.<br>34800001 The UKey does not exist.<br>34800002 UKey driver error.<br>For details, see [HuksCryptoExtensionResultCode](#hukscryptoextensionresultcode).|

**Example**

```ts
import { huksExternalCrypto, HuksCryptoExtensionParam, CryptoExtensionAbility, HuksCryptoExtensionResult, HuksCryptoExtensionCertInfo } from '@kit.UniversalKeystoreKit';

export default class CryptoExtension extends CryptoExtensionAbility {
  onEnumCertificates(params?: Array<huksExternalCrypto.HuksExternalCryptoParam> | HuksCryptoExtensionParam[]): Promise<HuksCryptoExtensionResult> {
    const certInfoSetArray: Array<HuksCryptoExtensionCertInfo> = []
    const result: HuksCryptoExtensionResult = {
      resultCode: 0,
      certs: certInfoSetArray
    };

    // ...
    return Promise.resolve(result);
  }
}
```

### onGetResourceId

onGetResourceId(params: HuksCryptoExtensionParam[]):Promise&lt;HuksCryptoExtensionResult&gt;

Obtains the resource ID of an external extension device. This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Security.Huks.CryptoExtension

**Parameters**

| Name  | Type| Mandatory| Description|
| -------- | --------- | ---- | -------- |
| params  | [HuksCryptoExtensionParam](#hukscryptoextensionparam)[] | Yes   | Attribute parameters required for obtaining the resource ID. The mandatory tags include [HUKS_EXT_CRYPTO_TAG_RESOURCE_INFO](js-apis-huksExternalCrypto.md#huksexternalcryptotag) (vendor-defined resource information) and [HUKS_EXT_CRYPTO_TAG_UID](js-apis-huksExternalCrypto.md#huksexternalcryptotag) (caller identity). |

**Return value**

| Type| Description|
| ---------- | ----------- |
| Promise\<[HuksCryptoExtensionResult](#hukscryptoextensionresult)> | Promise used to return the result. If the call is successful, **resultCode** is **0** and **resourceId** contains the resource ID. If the call fails, **resultCode** contains the error code.<br>Possible error code values:<br>34800000 Key extension error.<br>For details, see [HuksCryptoExtensionResultCode](#hukscryptoextensionresultcode).|

**Example**

```ts
import { HuksCryptoExtensionParam, CryptoExtensionAbility, HuksCryptoExtensionResult } from '@kit.UniversalKeystoreKit';

export default class CryptoExtension extends CryptoExtensionAbility {
  onGetResourceId(params: HuksCryptoExtensionParam[]): Promise<HuksCryptoExtensionResult> {
    const result: HuksCryptoExtensionResult = {
      resultCode: 0,
      resourceId: "test resourceId"
    };

    // ...
    return Promise.resolve(result);
  }
}
```

### onImportCertificate

onImportCertificate(handle: string, params: HuksCryptoExtensionParam[], certInfo: HuksCryptoExtensionCertInfo): Promise&lt;HuksCryptoExtensionResult&gt;

Imports the certificate of a specified resource handle. This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Security.Huks.CryptoExtension

**Parameters**

| Name  | Type | Mandatory| Description |
| -------- | ----- | ---- | ------|
| handle | string | Yes  | Resource handle of the certificate to be imported.|
| params  | [HuksCryptoExtensionParam](#hukscryptoextensionparam)[] | Yes | Attribute parameters required for importing the certificate. |
| certInfo | [HuksCryptoExtensionCertInfo](#hukscryptoextensioncertinfo) | Yes  | Information about the certificate to be imported. The certificate type (**purpose**) must be specified.|

**Return value**

| Type   | Description  |
| -------- | -----------|
| Promise\<[HuksCryptoExtensionResult](#hukscryptoextensionresult)> | Promise used to return the result. If the call is successful, the value of **resultCode** is **0**, indicating that the certificate is imported successfully. If the call fails, **resultCode** contains the error code information, and **errInfo** contains the detailed error information.<br>Possible error code values:<br>34800000 Key extension error.<br>34800001 The UKey does not exist.<br>34800002 UKey driver error.<br>34800004 Handle does not exist.<br>34800005 The handle is unavailable.<br>For details, see [HuksCryptoExtensionResultCode](#hukscryptoextensionresultcode).|

**Example**

```ts
import { CryptoExtensionAbility, HuksCryptoExtensionParam, HuksCryptoExtensionResult,
  HuksCryptoExtensionCertInfo } from '@kit.UniversalKeystoreKit';

export default class CryptoExtension extends CryptoExtensionAbility {
  onImportCertificate(handle: string, params: HuksCryptoExtensionParam[],
      certInfo: HuksCryptoExtensionCertInfo): Promise<HuksCryptoExtensionResult> {
    const result: HuksCryptoExtensionResult = {
      resultCode: 0
    };

    // ...
    return Promise.resolve(result);
  }
}
```

### onGenerateKeyItem

onGenerateKeyItem(handle: string, params: HuksCryptoExtensionParam[]): Promise&lt;HuksCryptoExtensionResult&gt;

Generates a key pair in the extension device. This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Security.Huks.CryptoExtension

**Parameters**

| Name  | Type | Mandatory| Description |
| -------- | ----- | ---- | ------|
| handle | string | Yes  | Resource handle of the key to be generated.|
| params  | [HuksCryptoExtensionParam](#hukscryptoextensionparam)[] | Yes | Attribute parameters of the key generation operation. Mandatory TAG: [HUKS_EXT_CRYPTO_TAG_UID](js-apis-huksExternalCrypto.md#huksexternalcryptotag) (caller identity). |

**Return value**

| Type   | Description  |
| -------- | -----------|
| Promise\<[HuksCryptoExtensionResult](#hukscryptoextensionresult)> | Promise used to return the result. When the call succeeds, **resultCode** is **0**, indicating that the key is generated successfully. On call failure, **resultCode** carries the error code information.<br>Possible error codes:<br>34800000 Key extension error.<br>34800002 UKey driver error.<br>34800004 Handle does not exist.<br>34800005 Handle unavailable.<br>For the specific meaning, see [HuksCryptoExtensionResultCode](#hukscryptoextensionresultcode). |

**Example**

```ts
import { huks, CryptoExtensionAbility, HuksCryptoExtensionResult, HuksCryptoExtensionParam } from '@kit.UniversalKeystoreKit';

export default class CryptoExtension extends CryptoExtensionAbility {
  onGenerateKeyItem(handle: string, params: HuksCryptoExtensionParam[]): Promise<HuksCryptoExtensionResult> {
    // Parse optional parameters.
    let algorithm: huks.HuksKeyAlg | undefined = params.find(
      param => param.tag === huks.HuksTag.HUKS_TAG_ALGORITHM)?.value as huks.HuksKeyAlg;
    let keySize: huks.HuksKeySize | undefined = params.find(
      param => param.tag === huks.HuksTag.HUKS_TAG_KEY_SIZE)?.value as huks.HuksKeySize;
    let purpose: huks.HuksKeyPurpose | undefined = params.find(
      param => param.tag === huks.HuksTag.HUKS_TAG_PURPOSE)?.value as huks.HuksKeyPurpose;

    // If there is no input parameter, set the default value.
    if (algorithm === undefined) {
      algorithm = huks.HuksKeyAlg.HUKS_ALG_RSA; // RSA is used by default.
    }
    if (keySize === undefined) {
      keySize = huks.HuksKeySize.HUKS_RSA_KEY_SIZE_2048; // The default value is 2048 bits.
    }
    if (purpose === undefined) {
      purpose = huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_SIGN; // The default purpose is signing.
    }

    const result: HuksCryptoExtensionResult = {
      resultCode: 0
    };

    // ...
    return Promise.resolve(result);
  }
}
```

### onExportKeyItem

onExportKeyItem(handle: string, params: HuksCryptoExtensionParam[]): Promise&lt;HuksCryptoExtensionResult&gt;

Exports the public key of a specified key. This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Security.Huks.CryptoExtension

**Parameters**

| Name  | Type | Mandatory| Description |
| -------- | ----- | ---- | ------|
| handle | string | Yes  | Resource handle of the public key to be exported.|
| params  | [HuksCryptoExtensionParam](#hukscryptoextensionparam)[] | Yes | Attribute parameters of the public key export operation. Mandatory TAG: [HUKS_EXT_CRYPTO_TAG_UID](js-apis-huksExternalCrypto.md#huksexternalcryptotag) (caller identity). |

**Return value**

| Type   | Description  |
| -------- | -----------|
| Promise\<[HuksCryptoExtensionResult](#hukscryptoextensionresult)> | Promise used to return the result. When the call succeeds, **resultCode** is **0** and **outData** carries the exported public key data. When the call fails, **resultCode** carries the error code and **errInfo** carries detailed error information.<br>Possible error codes:<br>34800000 Key extension error.<br>34800002 UKey driver error.<br>34800004 Handle does not exist.<br>34800005 Handle unavailable.<br>For the specific meaning, see [HuksCryptoExtensionResultCode](#hukscryptoextensionresultcode). |

**Example**

```ts
import { huks, CryptoExtensionAbility, HuksCryptoExtensionResult, HuksCryptoExtensionParam } from '@kit.UniversalKeystoreKit';

export default class CryptoExtension extends CryptoExtensionAbility {
  onExportKeyItem(handle: string, params: HuksCryptoExtensionParam[]): Promise<HuksCryptoExtensionResult> {
    // Parse the optional parameters. It is recommended that the key purpose be passed.
    let purpose: huks.HuksKeyPurpose | undefined = params.find(
      param => param.tag === huks.HuksTag.HUKS_TAG_PURPOSE)?.value as huks.HuksKeyPurpose;

    // If the purpose parameter is not passed, set the default value. (The default signing purpose is recommended.)
    if (purpose === undefined) {
      purpose = huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_SIGN;
    }

    let pubKey: Uint8Array = new Uint8Array(1024);
    const result: HuksCryptoExtensionResult = {
      resultCode: 0,
      outData: pubKey
    };

    // ...
    return Promise.resolve(result);
  }
}
```

### onImportWrappedKeyItem

onImportWrappedKeyItem(handle: string, wrappingHandle: string, params: HuksCryptoExtensionParam[], wrappedKey: Uint8Array): Promise&lt;HuksCryptoExtensionResult&gt;

Imports the encrypted and encapsulated key pair. This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Security.Huks.CryptoExtension

**Parameters**

| Name  | Type | Mandatory| Description |
| -------- | ----- | ---- | ------|
| handle | string | Yes  | Handle to the resource whose key is to be imported.|
| wrappingHandle | string | Yes | Key resource handle used to unwrap the imported key. |
| params | [HuksCryptoExtensionParam](#hukscryptoextensionparam)[] | Yes | Attribute parameters for the wrapped key import operation. Mandatory TAG: [HUKS_EXT_CRYPTO_TAG_UID](js-apis-huksExternalCrypto.md#huksextcryptotag) (caller identity). |
| wrappedKey | Uint8Array | Yes  | wrapped key data. The format is defined by key extension.|

**Return value**

| Type   | Description  |
| -------- | -----------|
| Promise\<[HuksCryptoExtensionResult](#hukscryptoextensionresult)> | Promise used to return the result. When the call succeeds, **resultCode** is **0**, indicating that the key is imported successfully. On call failure, **resultCode** carries the error code, and **errInfo** carries detailed error information.<br>Possible error codes:<br>34800000 Key extension error.<br>34800002 UKey driver error.<br>34800004 Handle does not exist.<br>34800005 Handle unavailable.<br>For the specific meaning, see [HuksCryptoExtensionResultCode](#hukscryptoextensionresultcode). |

**Example**

```ts
import { huks, CryptoExtensionAbility, HuksCryptoExtensionResult, HuksCryptoExtensionParam } from '@kit.UniversalKeystoreKit';
export default class CryptoExtension extends CryptoExtensionAbility {
  onImportWrappedKeyItem(handle: string, wrappingHandle: string, params: HuksCryptoExtensionParam[], wrappedKey: Uint8Array): Promise<HuksCryptoExtensionResult> {
    // Parse optional parameters.
    let algorithm: huks.HuksKeyAlg | undefined = params.find(
      param => param.tag === huks.HuksTag.HUKS_TAG_ALGORITHM)?.value as huks.HuksKeyAlg;
    let keySize: huks.HuksKeySize | undefined = params.find(
      param => param.tag === huks.HuksTag.HUKS_TAG_KEY_SIZE)?.value as huks.HuksKeySize;
    let purpose: huks.HuksKeyPurpose | undefined = params.find(
      param => param.tag === huks.HuksTag.HUKS_TAG_PURPOSE)?.value as huks.HuksKeyPurpose;

    // If there is no input parameter, set the default value.
    if (algorithm === undefined) {
      algorithm = huks.HuksKeyAlg.HUKS_ALG_RSA;
    }
    if (keySize === undefined) {
      keySize = huks.HuksKeySize.HUKS_RSA_KEY_SIZE_2048;
    }
    if (purpose === undefined) {
      purpose = huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT;
    }

    const result: HuksCryptoExtensionResult = {
      resultCode: 0
    };

    // ...
    return Promise.resolve(result);
  }
}
```

## Appendix

**CryptoExtensionAbility** does not support references to the following modules.

<!--RP1-->

| Kit | Module |
| ------ | ------ |
| Ability Kit | [@ohos.distributedBundle (Distributed Bundle Management) (System API)](../../reference/apis-ability-kit/js-apis-Bundle-distributedBundle-sys.md) |
| Ability Kit | [@ohos.distributedMissionManager (Distributed Mission Management) (System API)](../../reference/apis-ability-kit/js-apis-distributedMissionManager-sys.md) |
| Ability Kit | [@ohos.wantAgent (WantAgent Module)](../../reference/apis-ability-kit/js-apis-wantAgent.md) |
| Ads Kit | [@ohos.advertising.AdComponent (Ad Component)](../../reference/apis-ads-kit/js-apis-adcomponent.md) |
| Ads Kit | [@ohos.advertising.AdsServiceExtensionAbility (ExtensionAbility for Ads)](../../reference/apis-ads-kit/js-apis-adsserviceextensionability.md) |
| Ads Kit | [@ohos.advertising.AutoAdComponent (Carousel Ad Component)](../../reference/apis-ads-kit/js-apis-autoadcomponent.md) |
| Ads Kit | [@ohos.advertising (Ads Service Framework)](../../reference/apis-ads-kit/js-apis-advertising.md) |
| ArkUI | [@ohos.atomicservice.AtomicServiceNavigation (AtomicServiceNavigation)](../../reference/apis-arkui/arkui-ts/ohos-atomicservice-AtomicServiceNavigation.md) |
| ArkUI | [@ohos.atomicservice.AtomicServiceSearch (AtomicServiceSearch)](../../reference/apis-arkui/arkui-ts/ohos-atomicservice-AtomicServiceSearch.md) |
| ArkUI | [@ohos.atomicservice.AtomicServiceTabs (AtomicServiceTabs)](../../reference/apis-arkui/arkui-ts/ohos-atomicservice-AtomicServiceTabs.md) |
| ArkUI | [@ohos.atomicservice.AtomicServiceWeb (AtomicServiceWeb)](../../reference/apis-arkui/arkui-ts/ohos-atomicservice-AtomicServiceWeb.md) |
| ArkUI | [@ohos.atomicservice.HalfScreenLaunchComponent (HalfScreenLaunchComponent)](../../reference/apis-arkui/arkui-ts/ohos-atomicservice-HalfScreenLaunchComponent.md) |
| ArkUI | [@ohos.atomicservice.InterstitialDialogAction (InterstitialDialogAction)](../../reference/apis-arkui/arkui-ts/ohos-atomicservice-InterstitialDialogAction.md) |
| ArkUI | [@ohos.atomicservice.NavPushPathHelper (NavPushPathHelper)](../../reference/apis-arkui/arkui-ts/ohos-atomicservice-NavPushPathHelper.md) |
| ArkUI | [@ohos.mediaquery (Media Query)](../../reference/apis-arkui/js-apis-mediaquery.md) |
| ArkUI | [@ohos.PiPWindow (PiP Window)](../../reference/apis-arkui/js-apis-pipWindow.md) |
| ArkUI | [@ohos.screenshot (Screenshot)](../../reference/apis-arkui/js-apis-screenshot.md) |
| ArkWeb | [@ohos.web.netErrorList (The List of ArkWeb Network Protocol Stack Errors)](../../reference/apis-arkweb/arkts-apis-netErrorList.md) |
| ArkWeb | [@ohos.web.WebNativeMessagingExtensionAbility (Web Native Messaging Extension Ability)](../../reference/apis-arkweb/arkts-apis-web-webNativeMessagingExtensionAbility.md) |
| ArkWeb | [@ohos.web.WebNativeMessagingExtensionContext (Web Native Messaging Extension Context)](../../reference/apis-arkweb/arkts-apis-web-webNativeMessagingExtensionContext.md) |
| ArkWeb | [@ohos.web.webNativeMessagingExtensionManager (Web Native Messaging Extension Manager)](../../reference/apis-arkweb/arkts-apis-web-webNativeMessagingExtensionManager.md) |
| ArkWeb | [@ohos.web.webview](../../reference/apis-arkweb/arkts-apis-webview.md) |
| Audio Kit | [@ohos.multimedia.audio (Audio Management) (System API)](../../reference/apis-audio-kit/js-apis-audio-sys.md) |
| Audio Kit | [@ohos.multimedia.audioHaptic (Audio-Haptic)](../../reference/apis-audio-kit/js-apis-audioHaptic.md) |
| Audio Kit | [@ohos.multimedia.avVolumePanel (Volume Panel)](../../reference/apis-audio-kit/ohos-multimedia-avvolumepanel.md) |
| Audio Kit | [@ohos.multimedia.systemSoundManager (System Sound Management)](../../reference/apis-audio-kit/js-apis-systemSoundManager.md) |
| AVSession Kit | [@ohos.multimedia.avCastPicker (AVCastPicker)](../../reference/apis-avsession-kit/ohos-multimedia-avcastpicker.md) |
| AVSession Kit | [@ohos.multimedia.avCastPickerParam (AVCastPicker Parameters)](../../reference/apis-avsession-kit/js-apis-avCastPickerParam.md) |
| AVSession Kit | [@ohos.multimedia.avInputCastPicker (AVInputCastPicker)](../../reference/apis-avsession-kit/ohos-multimedia-avinputcastpicker.md) |
| AVSession Kit | [@ohos.multimedia.avsession (AVSession Management) (System API)](../../reference/apis-avsession-kit/js-apis-avsession-sys.md) |
| Basic Service Kit | [@ohos.ai.intelligentVoice (Intelligent Voice) (System API)](../../reference/apis-basic-services-kit/js-apis-intelligentVoice-sys.md) |
| Basic Service Kit | [@ohos.pasteboard (Pasteboard)](../../reference/apis-basic-services-kit/js-apis-pasteboard.md) |
| Basic Service Kit | [@ohos.scan (Scan)](../../reference/apis-basic-services-kit/js-apis-scan.md) |
| Basic Service Kit | [@ohos.screenLock (Screen Lock)](../../reference/apis-basic-services-kit/js-apis-screen-lock.md) |
| Basic Service Kit | [@ohos.settings (Data Item Settings)](../../reference/apis-basic-services-kit/js-apis-settings.md) |
| Basic Service Kit | [@ohos.wallpaper (Wallpaper)](../../reference/apis-basic-services-kit/js-apis-wallpaper.md) |
| Basic Service Kit | [@ohos.WallpaperExtensionAbility (WallpaperExtensionAbility) (System API)](../../reference/apis-basic-services-kit/js-apis-WallpaperExtensionAbility-sys.md) |
| Calendar Kit | [@ohos.calendarManager (Calendar Manager)](../../reference/apis-calendar-kit/js-apis-calendarManager.md) |
| Camera Kit | [@ohos.multimedia.camera (Camera Management) (System API)](../../reference/apis-camera-kit/js-apis-camera-sys.md) |
| Camera Kit | [@ohos.multimedia.cameraPicker (Camera Picker)](../../reference/apis-camera-kit/js-apis-cameraPicker.md) |
| Connectivity Kit | [@ohos.bluetooth.a2dp (Bluetooth A2DP Module)](../../reference/apis-connectivity-kit/js-apis-bluetooth-a2dp.md) |
| Connectivity Kit | [@ohos.bluetooth.access (Bluetooth Access Module)](../../reference/apis-connectivity-kit/js-apis-bluetooth-access.md) |
| Connectivity Kit | [@ohos.bluetooth.baseProfile (Bluetooth baseProfile Module)](../../reference/apis-connectivity-kit/js-apis-bluetooth-baseProfile.md) |
| Connectivity Kit | [@ohos.bluetooth.ble (Bluetooth BLE Module)](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md) |
| Connectivity Kit | [@ohos.bluetooth.common (Bluetooth Common Module)](../../reference/apis-connectivity-kit/js-apis-bluetooth-common.md) |
| Connectivity Kit | [@ohos.bluetooth.connection (Bluetooth Connection Module)](../../reference/apis-connectivity-kit/js-apis-bluetooth-connection.md) |
| Connectivity Kit | [@ohos.bluetooth.constant (Bluetooth constant Module)](../../reference/apis-connectivity-kit/js-apis-bluetooth-constant.md) |
| Connectivity Kit | [@ohos.bluetooth (Bluetooth)](../../reference/apis-connectivity-kit/js-apis-bluetooth.md) |
| Connectivity Kit | [@ohos.bluetooth.hfp (Bluetooth HFP Module)](../../reference/apis-connectivity-kit/js-apis-bluetooth-hfp.md) |
| Connectivity Kit | [@ohos.bluetooth.hid (Bluetooth HID Module)](../../reference/apis-connectivity-kit/js-apis-bluetooth-hid.md) |
| Connectivity Kit | [@ohos.bluetoothManager (Bluetooth)](../../reference/apis-connectivity-kit/js-apis-bluetoothManager.md) |
| Connectivity Kit | [@ohos.bluetooth.map (Bluetooth MAP Module)](../../reference/apis-connectivity-kit/js-apis-bluetooth-map.md) |
| Connectivity Kit | [@ohos.bluetooth.opp (Bluetooth OPP Module) (System API)](../../reference/apis-connectivity-kit/js-apis-bluetooth-opp-sys.md) |
| Connectivity Kit | [@ohos.bluetooth.pan (Bluetooth PAN Module)](../../reference/apis-connectivity-kit/js-apis-bluetooth-pan.md) |
| Connectivity Kit | [@ohos.bluetooth.pbap (Bluetooth PBAP Module)](../../reference/apis-connectivity-kit/js-apis-bluetooth-pbap.md) |
| Connectivity Kit | [@ohos.bluetooth.socket (Bluetooth Socket Module)](../../reference/apis-connectivity-kit/js-apis-bluetooth-socket.md) |
| Connectivity Kit | [@ohos.bluetooth.wearDetection(Bluetooth Wear Detection Module) (System API)](../../reference/apis-connectivity-kit/js-apis-bluetooth-wearDetection-sys.md) |
| Connectivity Kit | [@ohos.connectedTag (Active Tags)](../../reference/apis-connectivity-kit/js-apis-connectedTag.md) |
| Connectivity Kit | [@ohos.nfc.cardEmulation (Standard NFC Card Emulation)](../../reference/apis-connectivity-kit/js-apis-cardEmulation.md) |
| Connectivity Kit | [@ohos.nfc.controller (standard NFC)](../../reference/apis-connectivity-kit/js-apis-nfcController.md) |
| Connectivity Kit | [@ohos.nfc.tag (Standard NFC-Tag)](../../reference/apis-connectivity-kit/js-apis-nfcTag.md) |
| Connectivity Kit | [@ohos.wifi (WLAN)](../../reference/apis-connectivity-kit/js-apis-wifi.md) |
| Connectivity Kit | [@ohos.wifiext (WLAN Extension)](../../reference/apis-connectivity-kit/js-apis-wifiext.md) |
| Connectivity Kit | [@ohos.wifiManager (WLAN)](../../reference/apis-connectivity-kit/js-apis-wifiManager.md) |
| Connectivity Kit | [@ohos.wifiManagerExt (WLAN Extension)](../../reference/apis-connectivity-kit/js-apis-wifiManagerExt.md) |
| Contacts Kit | [@ohos.contact (Contact)](../../reference/apis-contacts-kit/js-apis-contact.md) |
| Data Protection Kit | [@ohos.dlpPermission (DLP)](../../reference/apis-data-protection-kit/js-apis-dlppermission.md) |
| Distributed Service Kit | [@ohos.distributedDeviceManager (Device Management)](../../reference/apis-distributedservice-kit/js-apis-distributedDeviceManager.md) |
| Distributed Service Kit | [@ohos.distributedHardware.deviceManager (Device Management) (System API)](../../reference/apis-distributedservice-kit/js-apis-device-manager-sys.md) |
| Distributed Service Kit | [@ohos.distributedHardware.hardwareManager (Distributed Hardware Management) (System API)](../../reference/apis-distributedservice-kit/js-apis-distributedHardwareManager-sys.md) |
| Distributed Service Kit | [@ohos.distributedsched.abilityConnectionManager (Cross-Device Connection Management)](../../reference/apis-distributedservice-kit/js-apis-distributed-abilityConnectionManager.md) |
| Distributed Service Kit | [@ohos.distributedsched.linkEnhance (Enhanced Connection)](../../reference/apis-distributedservice-kit/js-apis-link-enhance.md) |
| Distributed Service Kit | [@ohos.distributedsched.proxyChannelManager (Proxy Channel Management)](../../reference/apis-distributedservice-kit/js-apis-proxyChannelManager.md) |
| DRM Kit | [@ohos.multimedia.drm](../../reference/apis-drm-kit/arkts-apis-drm.md) |
| Form Kit | [@ohos.app.form.formAgent (FormAgent) (System API)](../../reference/apis-form-kit/js-apis-app-form-formAgent-sys.md) |
| Form Kit | [@ohos.app.form.formBindingData (formBindingData)](../../reference/apis-form-kit/js-apis-app-form-formBindingData.md) |
| Form Kit | [@ohos.app.form.FormEditExtensionAbility (FormEditExtensionAbility)](../../reference/apis-form-kit/js-apis-app-form-formEditExtensionAbility.md) |
| Form Kit | [@ohos.app.form.FormExtensionAbility (FormExtensionAbility)](../../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md) |
| Form Kit | [@ohos.app.form.formHost (formHost) (System API)](../../reference/apis-form-kit/js-apis-app-form-formHost-sys.md) |
| Form Kit | [@ohos.app.form.formInfo (formInfo)](../../reference/apis-form-kit/js-apis-app-form-formInfo.md) |
| Form Kit | [@ohos.app.form.formObserver (formObserver) (System API)](../../reference/apis-form-kit/js-apis-app-form-formObserver-sys.md) |
| Form Kit | [@ohos.app.form.formProvider (formProvider)](../../reference/apis-form-kit/js-apis-app-form-formProvider.md) |
| Form Kit | [@ohos.app.form.LiveFormExtensionAbility (LiveFormExtensionAbility)](../../reference/apis-form-kit/js-apis-app-form-LiveFormExtensionAbility.md) |
| Image Kit | [@ohos.multimedia.image (Image Processing) (System API)](../../reference/apis-image-kit/js-apis-image-sys.md) |
| Image Kit | [@ohos.multimedia.sendableImage (Image Processing Based on Sendable Objects)](../../reference/apis-image-kit/js-apis-sendableImage.md) |
| Image Kit | [@ohos.multimedia.videoProcessingEngine (Video Processing Engine)](../../reference/apis-image-kit/js-apis-videoProcessingEngine.md) |
| Location Kit | [@ohos.geolocation (Geolocation)](../../reference/apis-location-kit/js-apis-geolocation.md) |
| Location Kit | [@ohos.geoLocationManager (Geolocation)](../../reference/apis-location-kit/js-apis-geoLocationManager.md) |
| MDM Kit | [@ohos.enterprise.accountManager (Account Management)](../../reference/apis-mdm-kit/js-apis-enterprise-accountManager.md) |
| MDM Kit | [@ohos.enterprise.adminManager (Administrator Permission Management)](../../reference/apis-mdm-kit/js-apis-enterprise-adminManager.md) |
| MDM Kit | [@ohos.enterprise.applicationManager (Application Management)](../../reference/apis-mdm-kit/js-apis-enterprise-applicationManager.md) |
| MDM Kit | [@ohos.enterprise.bluetoothManager (Bluetooth Management)](../../reference/apis-mdm-kit/js-apis-enterprise-bluetoothManager.md) |
| MDM Kit | [@ohos.enterprise.browser (Browser Management)](../../reference/apis-mdm-kit/js-apis-enterprise-browser.md) |
| MDM Kit | [@ohos.enterprise.bundleManager (Bundle Management)](../../reference/apis-mdm-kit/js-apis-enterprise-bundleManager.md) |
| MDM Kit | [@ohos.enterprise.common (Common Module)](../../reference/apis-mdm-kit/js-apis-enterprise-common.md) |
| MDM Kit | [@ohos.enterprise.dateTimeManager (System Time Management) (System API)](../../reference/apis-mdm-kit/js-apis-enterprise-dateTimeManager-sys.md) |
| MDM Kit | [@ohos.enterprise.deviceControl (Device Control Management)](../../reference/apis-mdm-kit/js-apis-enterprise-deviceControl.md) |
| MDM Kit | [@ohos.enterprise.deviceInfo (Device Information Management)](../../reference/apis-mdm-kit/js-apis-enterprise-deviceInfo.md) |
| MDM Kit | [@ohos.enterprise.deviceSettings (Device Settings Management)](../../reference/apis-mdm-kit/js-apis-enterprise-deviceSettings.md) |
| MDM Kit | [@ohos.enterprise.EnterpriseAdminExtensionAbility (EnterpriseAdminExtensionAbility)](../../reference/apis-mdm-kit/js-apis-EnterpriseAdminExtensionAbility.md) |
| MDM Kit | [@ohos.enterprise.locationManager (Location Service Management)](../../reference/apis-mdm-kit/js-apis-enterprise-locationManager.md) |
| MDM Kit | [@ohos.enterprise.networkManager (Network Management)](../../reference/apis-mdm-kit/js-apis-enterprise-networkManager.md) |
| MDM Kit | [@ohos.enterprise.restrictions (Restrictions)](../../reference/apis-mdm-kit/js-apis-enterprise-restrictions.md) |
| MDM Kit | [@ohos.enterprise.securityManager (Security Management)](../../reference/apis-mdm-kit/js-apis-enterprise-securityManager.md) |
| MDM Kit | [@ohos.enterprise.systemManager (System Management)](../../reference/apis-mdm-kit/js-apis-enterprise-systemManager.md) |
| MDM Kit | [@ohos.enterprise.telephonyManager (Telephony Management)](../../reference/apis-mdm-kit/js-apis-enterprise-telephonyManager.md) |
| MDM Kit | [@ohos.enterprise.usbManager (USB Management)](../../reference/apis-mdm-kit/js-apis-enterprise-usbManager.md) |
| MDM Kit | [@ohos.enterprise.wifiManager (Wi-Fi Management)](../../reference/apis-mdm-kit/js-apis-enterprise-wifiManager.md) |
| Mechanic Kit | [@ohos.distributedHardware.mechanicManager (Mechanic Manager)](../../reference/apis-mechanic-kit/js-apis-mechanicManager.md) |
| Media Kit | [@ohos.multimedia.media (Media) (System API)](../../reference/apis-media-kit/js-apis-media-sys.md) |
| Media Library Kit | [@ohos.multimedia.movingphotoview (MovingPhotoView)](../../reference/apis-media-library-kit/ohos-multimedia-movingphotoview.md) |
| MindSpore Lite Kit | [@ohos.ai.mindSporeLite (On-device AI Framework)](../../reference/apis-mindspore-lite-kit/js-apis-mindSporeLite.md) |
| Network Kit | [@ohos.net.connection (Network Connection Management)](../../reference/apis-network-kit/js-apis-net-connection.md) |
| Network Kit | [@ohos.net.eap (Extensible Authentication)](../../reference/apis-network-kit/js-apis-net-eap.md) |
| Network Kit | [@ohos.net.ethernet (Ethernet Connection Management)](../../reference/apis-network-kit/js-apis-net-ethernet.md) |
| Network Kit | [@ohos.net.http (Data Request)](../../reference/apis-network-kit/js-apis-http.md) |
| Network Kit | [@ohos.net.mdns (mDNS Management)](../../reference/apis-network-kit/js-apis-net-mdns.md) |
| Network Kit | [@ohos.net.netFirewall (Network Firewall)](../../reference/apis-network-kit/js-apis-net-netfirewall.md) |
| Network Kit | [@ohos.net.networkSecurity (Network Security)](../../reference/apis-network-kit/js-apis-networkSecurity.md) |
| Network Kit | [@ohos.net.policy (Network Policy Management)](../../reference/apis-network-kit/js-apis-net-policy.md) |
| Network Kit | [@ohos.net.sharing (Network Sharing Management)](../../reference/apis-network-kit/js-apis-net-sharing.md) |
| Network Kit | [@ohos.net.socket (Socket Connection)](../../reference/apis-network-kit/js-apis-socket.md) |
| Network Kit | [@ohos.net.statistics (Traffic Management)](../../reference/apis-network-kit/js-apis-net-statistics.md) |
| Network Kit | [@ohos.net.vpn (VPN Management)](../../reference/apis-network-kit/js-apis-net-vpn.md) |
| Network Kit | [@ohos.net.vpnExtension (Enhanced VPN Management)](../../reference/apis-network-kit/js-apis-net-vpnExtension.md) |
| Network Kit | [@ohos.net.webSocket (WebSocket Connection)](../../reference/apis-network-kit/js-apis-webSocket.md) |
| Telephony Kit | [@ohos.telephony.call (Call)](../../reference/apis-telephony-kit/js-apis-call.md) |
| Telephony Kit | [@ohos.telephony.data (Cellular Data)](../../reference/apis-telephony-kit/js-apis-telephony-data.md) |
| Telephony Kit | [@ohos.telephony.esim (eSIM Management)](../../reference/apis-telephony-kit/js-apis-esim.md) |
| Telephony Kit | [@ohos.telephony.observer (Telephony Status Observer)](../../reference/apis-telephony-kit/js-apis-observer.md) |
| Telephony Kit | [@ohos.telephony.radio (Network Search)](../../reference/apis-telephony-kit/js-apis-radio.md) |
| Telephony Kit | [@ohos.telephony.sim (SIM Management)](../../reference/apis-telephony-kit/js-apis-sim.md) |
| Telephony Kit | [@ohos.telephony.sms (SMS)](../../reference/apis-telephony-kit/js-apis-sms.md) |
| Telephony Kit | [@ohos.telephony.vcard (VCard)](../../reference/apis-telephony-kit/js-apis-vcard.md) |

<!--RP1End-->
<!--no_check-->