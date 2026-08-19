# Encapsulating a Key (ArkTS)

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=3780eaa820092ee975c32f64eb288f44d3471751 translatedAt=2026-08-13T08:23:21.275Z pushedAt=2026-08-13T10:20:24.702Z -->

Starting from API version 26.0.0, post-quantum encapsulation and decapsulation algorithms are supported. Taking ML-KEM-768 and ML-KEM-1024 as examples, key encapsulation and decapsulation are performed when keys are managed by HUKS. For specific scenario descriptions and supported algorithm specifications, see [Algorithms Supported for Key Encapsulation](huks-kem-overview.md#supported-algorithms).

## Available APIs

You can refer to the API reference for details of the key encapsulation APIs: [huks.encapsulate](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksencapsulate) and [huks.decapsulate](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksdecapsulate).

### Encapsulation API Parameters

During key encapsulation, the API parameters are shown in the following table:

**Encapsulation API parameters:**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| keyAlias | string | Yes | Alias of the ML-KEM public key. The key must be generated in advance through **generateKeyItem** and stored in HUKS. |
| params | [HuksParam[]](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksparam) | Yes | Parameter set for the key encapsulation operation. For details, see the **params** parameter set below. |
| sharedKeyAlias | string | No | Alias for storing the shared key. When empty, the shared key is not stored and is returned to the caller; when non-empty, the shared key is stored to HUKS. |
| sharedKeyParams | [HuksParam[]](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksparam) | No (required when sharedKeyAlias is non-empty) | Attribute parameter set of the shared key. For details, see the **sharedKeyParams** parameter set below. |

**params parameter set:**

| Property Name (Tag) | Property Value (Value) | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| HUKS_TAG_ALGORITHM | **HUKS_ALG_ML_KEM** in the enum [HuksKeyAlg](../../reference/apis-universal-keystore-kit/js-apis-huks.md#hukskeyalg). | Yes | Key Encapsulation Algorithm. |
| HUKS_TAG_AUTH_STORAGE_LEVEL | Enum [HuksAuthStorageLevel](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksauthstoragelevel11). Values: **HUKS_AUTH_STORAGE_LEVEL_DE** (accessible after device boot), **HUKS_AUTH_STORAGE_LEVEL_CE** (accessible after first unlock), **HUKS_AUTH_STORAGE_LEVEL_ECE** (accessible when unlocked). | No | Key security level. |

**sharedKeyParams parameter set (required when sharedKeyAlias is non-empty):**

| Property Name (Tag) | Property Value (Value) | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| HUKS_TAG_ALGORITHM | Enum [HuksKeyAlg](../../reference/apis-universal-keystore-kit/js-apis-huks.md#hukskeyalg), such as HUKS_ALG_AES. | Yes | Shared key algorithm. |
| HUKS_TAG_KEY_SIZE | Enum [HuksKeySize](../../reference/apis-universal-keystore-kit/js-apis-huks.md#hukskeysize), such as HUKS_AES_KEY_SIZE_256. | Yes | Shared key size. |
| HUKS_TAG_PURPOSE | Enum [HuksKeyPurpose](../../reference/apis-universal-keystore-kit/js-apis-huks.md#hukskeypurpose), such as **HUKS_KEY_PURPOSE_ENCRYPT** \| **HUKS_KEY_PURPOSE_DECRYPT**. | Yes | Shared key purpose. |
| HUKS_TAG_KEY_OVERRIDE | Type: boolean. | No | Whether to overwrite a key with the same alias. The default value is **false**. |
| HUKS_TAG_IS_DEVICE_PASSWORD_SET | Type: boolean. | No | Whether the shared key is accessible only when a lock screen password has been set. When set to **true**, the shared key is accessible only when the user has set a lock screen password. When set to **false**, the shared key is accessible regardless of whether the user has set a lock screen password. The default value is **false**. |
| HUKS_TAG_USER_AUTH_TYPE | Enum [HuksUserAuthType](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksuserauthtype9). Values: **HUKS_USER_AUTH_TYPE_FINGERPRINT**, **HUKS_USER_AUTH_TYPE_FACE**, **HUKS_USER_AUTH_TYPE_PIN**, etc. Multiple values can be selected. | No | User authentication type for the shared key. |
| HUKS_TAG_KEY_AUTH_ACCESS_TYPE | Enum [HuksAuthAccessType](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksauthaccesstype9). Values: **HUKS_AUTH_ACCESS_INVALID_CLEAR_PASSWORD**, **HUKS_AUTH_ACCESS_INVALID_NEW_BIO_ENROLL**, **HUKS_AUTH_ACCESS_ALWAYS_VALID** | No | Authentication access type for the shared key. |
| HUKS_TAG_CHALLENGE_TYPE | Enum [HuksChallengeType](../../reference/apis-universal-keystore-kit/js-apis-huks.md#hukschallengetype9). Values: **HUKS_CHALLENGE_TYPE_NORMAL**, **HUKS_CHALLENGE_TYPE_CUSTOM**, **HUKS_CHALLENGE_TYPE_NONE** | No | Challenge type. |
| HUKS_TAG_AUTH_TIMEOUT | Type: number, in seconds. | No | Validity period of a single auth token. |

### Decapsulation API Parameters

During key decapsulation, the API parameters are shown in the following table.

**Decapsulation API Parameter List:**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| keyAlias | string | Yes | ML-KEM private key alias. The key must be generated in advance via generateKeyItem and stored in HUKS. |
| params | [HuksParam[]](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksparam) | Yes | Parameter set for the key decapsulation operation. For details, see the params parameter set below. |
| encapData | Uint8Array | Yes | Encapsulated ciphertext data, provided by the outData field in the encapsulation API return result [HuksReturnResult](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksreturnresult9). |
| sharedKeyAlias | string | No | Shared key storage alias. If empty, the shared key is not stored and is returned to the caller. If non-empty, the shared key is stored to HUKS. |
| sharedKeyParams | [HuksParam[]](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksparam) | No (Required when non-empty) | Attribute parameter set of the shared key. The parameters are the same as the **sharedKeyParams** parameter set of the encapsulation API. |

**params parameter set:**

| Property Name (Tag) | Property Value | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| HUKS_TAG_ALGORITHM | Enumerated value HUKS_ALG_ML_KEM in [HuksKeyAlg](../../reference/apis-universal-keystore-kit/js-apis-huks.md#hukskeyalg). | Yes | Key Decapsulation Algorithm. |
| HUKS_TAG_AUTH_STORAGE_LEVEL | Enumerated values in [HuksAuthStorageLevel](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksauthstoragelevel11): **HUKS_AUTH_STORAGE_LEVEL_DE** (accessible after device boot), **HUKS_AUTH_STORAGE_LEVEL_CE** (accessible after first unlock), and **HUKS_AUTH_STORAGE_LEVEL_ECE** (accessible when unlocked). | No | Key security level. |

### Encapsulation Return Result

The encapsulation API returns [HuksReturnResult](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksreturnresult9), whose fields are listed in the table below.

| Field Name | Type | Description |
| -------- | -------- | -------- |
| outData | Uint8Array | Encapsulated ciphertext data. ML-KEM-768 corresponds to 784 bytes of ciphertext, and ML-KEM-1024 corresponds to 912 bytes of ciphertext. |
| sharedSecret | Uint8Array | Shared key, with a length of 32 bytes. If **sharedKeyAlias** is non-empty (the shared key is stored to HUKS), this field is empty. |

## Constraints

- The key purpose used for key encapsulation and decapsulation must be [HUKS_KEY_PURPOSE_WRAP](../../reference/apis-universal-keystore-kit/js-apis-huks.md#hukskeypurpose) (encapsulation, public key operation) and [HUKS_KEY_PURPOSE_UNWRAP](../../reference/apis-universal-keystore-kit/js-apis-huks.md#hukskeypurpose) (decapsulation, private key operation), respectively.

- The shared key generated by ML-KEM has a fixed length of 32 bytes.

- When **sharedKeyAlias** is non-empty, **sharedKeyParams** must be provided and must include the necessary attributes of the shared key (algorithm, key size, and purpose).

- When **sharedKeyAlias** is non-empty, if a key with the same alias already exists and **HUKS_TAG_KEY_OVERRIDE** is not set to **true**, an error will be returned.

- Using an existing shared key alias as the encapsulation result key alias will overwrite the existing key.

## How to Develop

**Generating a Key**

Device A and device B each generate an ML-KEM key. For details, see [Generating a Key](huks-key-generation-arkts.md) or [Importing a Key](huks-key-import-overview.md).

During key generation, the key purpose must be set to **HUKS_KEY_PURPOSE_WRAP** | **HUKS_KEY_PURPOSE_UNWRAP**, the algorithm to **HUKS_ALG_ML_KEM**, and the key size to **768** or **1024**.

**Exporting a Public Key**

Device B exports the public key of the ML-KEM key. For details, see [Exporting a Key](huks-export-key-arkts.md). The exported public key is in X.509 DER format.

**Encapsulating a Key**

Device A uses device B's public key to perform key encapsulation, generating ciphertext and a shared key. During encapsulation, the shared key can be stored to HUKS (when **sharedKeyAlias** is not empty) or returned to the caller (when **sharedKeyAlias** is empty).

**Decapsulating a Key**

Device B uses the private key to decapsulate the ciphertext and recover the shared key. During decapsulation, the shared key can be stored to HUKS (when **sharedKeyAlias** is not empty) or returned to the caller (when **sharedKeyAlias** is empty).

**Deleting the Key**

When a key is no longer needed, both device A and device B must delete the key. For details, see [Deleting a Key](huks-delete-key-arkts.md).

## Samples

Before performing key encapsulation, ensure that ML-KEM keys are available. Refer to [Generating a Key](huks-key-generation-arkts.md) to generate keys, [Exporting a Key](huks-export-key-arkts.md) to export public keys, and [Importing Keys in Plaintext](huks-import-key-in-plaintext-arkts.md) to import the peer's public key.

### Shared Key Not Stored in HUKS

Taking ML-KEM-768 as an example, when encapsulation is performed without passing **sharedKeyAlias** and **sharedKeyParams**, the shared key is obtained from the **sharedSecret** field of the returned result.

``` ts
import { huks } from '@kit.UniversalKeystoreKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function encapsulateAndDecapsulate() {
  let encapParams: huks.HuksParam[] = [{
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_ML_KEM,
  }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_ML_KEM_KEY_PARAM_SET_768,
  }, {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_WRAP,
  }];

  let decapParams: huks.HuksParam[] = [{
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_ML_KEM,
  }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_ML_KEM_KEY_PARAM_SET_768,
  }, {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_UNWRAP,
  }];

  let encapsulatedData = new Uint8Array(0);
  let sharedSecret = new Uint8Array(0);

  /*Device A: Perform encapsulation using the peer public key alias without passing sharedKeyAlias and sharedKeyParams.*/
  try {
    let encapResult = await huks.encapsulate('ml_kem_pub_key_b', encapParams);
    encapsulatedData = encapResult.outData as Uint8Array;
    sharedSecret = encapResult.sharedSecret as Uint8Array;
    console.info(`encapsulate success, encapsulatedData length: ${encapsulatedData.length}`);
  } catch (error) {
    console.error(`encapsulate failed, errCode : ${(error as BusinessError).code}, errMsg : ${(error as BusinessError).message}`);
  }

  /*Device B: Perform decapsulation using the private key alias without passing sharedKeyAlias and sharedKeyParams.*/
  try {
    let decapResult = await huks.decapsulate('ml_kem_key_b', decapParams, encapsulatedData);
    sharedSecret = decapResult.sharedSecret as Uint8Array;
    console.info(`decapsulate success, sharedSecret length: ${sharedSecret.length}`);
  } catch (error) {
    console.error(`decapsulate failed, errCode : ${(error as BusinessError).code}, errMsg : ${(error as BusinessError).message}`);
  }
}
```

### Example: Storing Shared Keys to HUKS

Taking ML-KEM-768 as an example, when <code v-pre>sharedKeyAlias</code> and <code v-pre>sharedKeyParams</code> are specified during encapsulation and decapsulation, the shared key is stored under HUKS management, and <code v-pre>sharedSecret</code> in the encapsulation result is empty.

``` ts
import { huks } from '@kit.UniversalKeystoreKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function encapsulateAndDecapsulateWithSharedKey() {
  let sharedKeyAliasA = 'ml_kem_shared_key_a';
  let sharedKeyAliasB = 'ml_kem_shared_key_b';

  let sharedKeyProperties: huks.HuksParam[] = [{
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_AES,
  }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_256,
  }, {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT |
      huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT,
  }, {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_NONE,
  }, {
    tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
    value: huks.HuksCipherMode.HUKS_MODE_CBC,
  }];

  let encapParams: huks.HuksParam[] = [{
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_ML_KEM,
  }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_ML_KEM_KEY_PARAM_SET_768,
  }, {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_WRAP,
  }];

  let decapParams: huks.HuksParam[] = [{
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_ML_KEM,
  }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_ML_KEM_KEY_PARAM_SET_768,
  }, {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_UNWRAP,
  }];

  let encapsulatedData = new Uint8Array(0);

  /*Device A: Encapsulate and store the shared key to HUKS.*/
  try {
    let encapResult = await huks.encapsulate('ml_kem_pub_key_b', encapParams, sharedKeyAliasA, sharedKeyProperties);
    encapsulatedData = encapResult.outData as Uint8Array;
    console.info(`encapsulate success, encapsulatedData length: ${encapsulatedData.length}`);
  } catch (error) {
    console.error(`encapsulate failed, errCode : ${(error as BusinessError).code}, errMsg : ${(error as BusinessError).message}`);
  }

  /*Device B: Decapsulate and store the shared key to HUKS.*/
  try {
    await huks.decapsulate('ml_kem_key_b', decapParams, encapsulatedData, sharedKeyAliasB, sharedKeyProperties);
    console.info(`decapsulate success`);
  } catch (error) {
    console.error(`decapsulate failed, errCode : ${(error as BusinessError).code}, errMsg : ${(error as BusinessError).message}`);
  }
}
```

<!--no_check-->