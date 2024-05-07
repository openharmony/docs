# @ohos.security.huks (HUKS) (System API)

The **huks** module provides keystore capabilities with the user who performs the key operation specified.

> **NOTE**
> - The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - This topic describes only the system APIs provided by the module. For details about its public APIs, see [@ohos.security.huks](js-apis-huks.md).

## Modules to Import

```ts
import huks from '@ohos.security.huks'
```

## huks.generateKeyItemAsUser<sup>12+</sup>

generateKeyItemAsUser(userId: number, keyAlias: string, options: HuksOptions) : Promise\<void>

Generates a key for the specified user. This API uses a promise to return the result. Because the key is always protected in a trusted environment (such as a TEE), the promise does not return the key content. It returns only the information indicating whether the API is successfully called.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Security.Huks.Extension

**Parameters**

| Name  | Type                       | Mandatory| Description                    |
| -------- | --------------------------- | ---- | ------------------------ |
| userId   | number                      | Yes  | User ID.                |
| keyAlias | string                      | Yes  | Alias of the key to generate.              |
| options  | [HuksOptions](js-apis-huks.md#huksoptions) | Yes  | Tags required for generating the key. The algorithm, key purpose, and key length are mandatory.|

**Error codes**

For details about the error codes, see [HUKS Error Codes](errorcode-huks.md).

| ID| Error Message     |
| -------- | ------------- |
| 201 | the application permission is not sufficient, which may be caused by lack of acrossing-account permission, or the system has not been unlocked by user, or the user does not exist. |
| 202 | non-system applications are not allowed to use system APIs. |
| 401 | argument is invalid. |
| 801 | api is not supported. |
| 12000001 | algorithm mode is not supported. |
| 12000002 | algorithm param is missing. |
| 12000003 | algorithm param is invalid. |
| 12000004 | operating file failed. |
| 12000005 | IPC communication failed. |
| 12000006 | error occured in crypto engine. |
| 12000012 | external error. |
| 12000013 | queried credential does not exist. |
| 12000014 | memory is insufficient. |
| 12000015 | call service failed. |

**Example**

- Before calling the API in the sample code, ensure that the target user (user whose ID is to set) has signed in to the device. To sign in as the target user, do as follows:
  
  On the device, choose **Settings** > **Users & accounts** > **Signed in as** > **Add User**, enter the user name, and click **Add**. After the user is added, click **Switch** to switch to the new user and sign in as the user.

   Run the **hdc shell acm dump -a** command. The ID of the newly added user is **101**. In the following example, the user ID is **101** and the storage security level is **HUKS_AUTH_STORAGE_LEVEL_CE**.

   > **NOTE**<br>
   > **HUKS_AUTH_STORAGE_LEVEL_CE** allows the key to be accessed only after the first unlock of the device. If no user is switched, the user space 101 is locked. In this case, assessing the key using **huks** APIs will fail. You need to switch to the user and sign in as the user.

```ts
import promptAction from '@ohos.promptAction';
import huks from '@ohos.security.huks';
import { BusinessError } from 'basic';

const aesKeyAlias = 'test_aesKeyAlias';
const userId = 101;
const userIdStorageLevel = huks.HuksAuthStorageLevel.HUKS_AUTH_STORAGE_LEVEL_CE;

function GetAesGenerateProperties(): Array<huks.HuksParam> {
  return [{
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_AES
  }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_128
  }, {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT |
    huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT
  }, {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_PKCS7
  }, {
    tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
    value: huks.HuksCipherMode.HUKS_MODE_CBC
  }, {
    tag: huks.HuksTag.HUKS_TAG_AUTH_STORAGE_LEVEL,
    value: userIdStorageLevel,
  }]
}

async function GenerateKey(keyAlias: string, genProperties: Array<huks.HuksParam>) {
  const options: huks.HuksOptions = {
    properties: genProperties
  }
  await huks.generateKeyItemAsUser(userId, keyAlias, options).then((data) => {
    promptAction.showToast({
      message: "A key with the alias of "+ keyAlias +" is generated.",
      duration: 2500,
    })
  }).catch((err: BusinessError) => {
    promptAction.showToast({
      message: "Failed to generate the key. Error code: "+ err.code +" Error message: "+ err.message,
      duration: 6500,
    })
  })
}


export default function DocTest() {
  console.log('huks doc test')
  GenerateKey(aesKeyAlias, GetAesGenerateProperties())
}
```

## huks.deleteKeyItemAsUser<sup>12+</sup>

deleteKeyItemAsUser(userId: number, keyAlias: string, options: HuksOptions) : Promise\<void>

Deletes a key for the specified user. This API uses a promise to return the result.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Security.Huks.Extension

**Parameters**

| Name  | Type                       | Mandatory| Description                               |
| -------- | --------------------------- | ---- | ----------------------------------- |
| userId   | number                      | Yes  | User ID.                |
| keyAlias | string                      | Yes  | Alias of the key to delete. It must be the key alias passed in when the key was generated.|
| options  | [HuksOptions](js-apis-huks.md#huksoptions) | Yes  | Options for deleting the key. For example, you can pass in [HuksAuthStorageLevel](js-apis-huks.md#huksauthstoragelevel11) to specify the storage security level of the key to delete. If **HuksAuthStorageLevel** is left empty, **HUKS_AUTH_STORAGE_LEVEL_DE** is used by default.           |

**Error codes**

For details about the error codes, see [HUKS Error Codes](errorcode-huks.md).

| ID| Error Message     |
| -------- | ------------- |
| 201 | the application permission is not sufficient, which may be caused by lack of acrossing-account permission, or the system has not been unlocked by user, or the user does not exist. |
| 202 | non-system applications are not allowed to use system APIs. |
| 401 | argument is invalid. |
| 801 | api is not supported. |
| 12000004 | operating file failed. |
| 12000005 | IPC communication failed. |
| 12000011 | queried entity does not exist. |
| 12000012 | external error. |
| 12000014 | memory is insufficient. |

**Example**

- Before calling the API in the sample code, ensure that the target user (user whose ID is to set) has signed in to the device. For details, see **Example** in [generateKeyItemAsUser](#huksgeneratekeyitemasuser12).

```ts
import promptAction from '@ohos.promptAction';
import huks from '@ohos.security.huks';
import { BusinessError } from 'basic';


const aesKeyAlias = 'test_aesKeyAlias';
const userId = 101;
const userIdStorageLevel = huks.HuksAuthStorageLevel.HUKS_AUTH_STORAGE_LEVEL_CE;

function GetAesGenerateProperties(): Array<huks.HuksParam> {
  return [{
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_AES
  }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_128
  }, {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT |
    huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT
  }, {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_PKCS7
  }, {
    tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
    value: huks.HuksCipherMode.HUKS_MODE_CBC
  }, {
    tag: huks.HuksTag.HUKS_TAG_AUTH_STORAGE_LEVEL,
    value: userIdStorageLevel,
  }]
}

async function GenerateKey(keyAlias: string, genProperties: Array<huks.HuksParam>) {
  const options: huks.HuksOptions = {
    properties: genProperties
  }
  await huks.generateKeyItemAsUser(userId, keyAlias, options).then((data) => {
  }).catch((err: BusinessError) => {
    promptAction.showToast({
      message: "Failed to generate the key. Error code: "+ err.code +" Error message: "+ err.message,
      duration: 6500,
    })
  })
}

async function DeleteKey(keyAlias: string) {
  const options: huks.HuksOptions = {
    properties: [{
      tag: huks.HuksTag.HUKS_TAG_AUTH_STORAGE_LEVEL,
      value: userIdStorageLevel,
    }]
  }
  await huks.deleteKeyItemAsUser(userId, keyAlias, options).then((data) => {
    promptAction.showToast({
      message: "Key with the alias of "+ keyAlias +" is deleted.",
      duration: 6500,
    })
  }).catch((err: BusinessError) => {
    promptAction.showToast({
      message: "Failed to delete the key. Error code: "+ err.code +" Error message: "+ err.message,
      duration: 6500,
    })
  })
}

async function TestHuksDelete() {
  await GenerateKey(aesKeyAlias, GetAesGenerateProperties())
  await  DeleteKey(aesKeyAlias)
}

export default function DocTest() {
  console.log('huks doc test')
  TestHuksDelete()
}
```

## huks.importKeyItemAsUser<sup>12+</sup>

importKeyItemAsUser(userId: number, keyAlias: string, options: HuksOptions) : Promise\<void>

Imports a plaintext key for the specified user. This API uses a promise to return the result.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Security.Huks.Extension

**Parameters**

| Name  | Type                       | Mandatory| Description                               |
| -------- | --------------------------- | ---- | ----------------------------------- |
| userId   | number                      | Yes  | User ID.                |
| keyAlias | string                      | Yes  | Alias of the key to import.                         |
| options  | [HuksOptions](js-apis-huks.md#huksoptions) | Yes  | Options for importing the key. The algorithm, key purpose, and key length are mandatory.|

**Error codes**

For details about the error codes, see [HUKS Error Codes](errorcode-huks.md).

| ID| Error Message     |
| -------- | ------------- |
| 201 | the application permission is not sufficient, which may be caused by lack of acrossing-account permission, or the system has not been unlocked by user, or the user does not exist. |
| 202 | non-system applications are not allowed to use system APIs. |
| 401 | argument is invalid. |
| 801 | api is not supported. |
| 12000001 | algorithm mode is not supported. |
| 12000002 | algorithm param is missing. |
| 12000003 | algorithm param is invalid. |
| 12000004 | operating file failed. |
| 12000005 | IPC communication failed. |
| 12000006 | error occured in crypto engine. |
| 12000011 | queried entity does not exist. |
| 12000012 | external error. |
| 12000013 | queried credential does not exist. |
| 12000014 | memory is insufficient. |
| 12000015 | call service failed. |

**Example**

- Before calling the API in the sample code, ensure that the target user (user whose ID is to set) has signed in to the device. For details, see **Example** in [generateKeyItemAsUser](#huksgeneratekeyitemasuser12).

```ts
import promptAction from '@ohos.promptAction';
import huks from '@ohos.security.huks';
import { BusinessError } from 'basic';


const aesKeyAlias = 'test_aesKeyAlias';
const userId = 101;
const userIdStorageLevel = huks.HuksAuthStorageLevel.HUKS_AUTH_STORAGE_LEVEL_CE;
const plainAesKey128 = new Uint8Array([
  0xfb, 0x8b, 0x9f, 0x12, 0xa0, 0x83, 0x19, 0xbe, 0x6a, 0x6f, 0x63, 0x2a, 0x7c, 0x86, 0xba, 0xca
]);

function GetAesGenerateProperties(): Array<huks.HuksParam> {
  return [{
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_AES
  }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_128
  }, {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT |
    huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT
  }, {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_PKCS7
  }, {
    tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
    value: huks.HuksCipherMode.HUKS_MODE_CBC
  }, {
    tag: huks.HuksTag.HUKS_TAG_AUTH_STORAGE_LEVEL,
    value: userIdStorageLevel,
  }]
}

async function ImportPlainKey(keyAlias: string, importProperties: Array<huks.HuksParam>, plainKey: Uint8Array) {
  const options: huks.HuksOptions = {
    properties: importProperties,
    inData: plainKey
  }
  await huks.importKeyItemAsUser(userId, keyAlias, options).then((data) => {
    promptAction.showToast({
      message: "A key with the alias of "+ keyAlias +" is imported.",
      duration: 2500,
    })
  }).catch((err: BusinessError) => {
    promptAction.showToast({
      message: "Failed to import the key. Error code: "+ err.code +" Error message: "+ err.message,
      duration: 6500,
    })
    return
  })
}

export default function DocTest() {
  console.log('huks doc test')
  ImportPlainKey(aesKeyAlias, GetAesGenerateProperties(), plainAesKey128)
}
```


## huks.attestKeyItemAsUser<sup>12+</sup>

attestKeyItemAsUser(userId: number, keyAlias: string, options: HuksOptions) : Promise\<HuksReturnResult>

Attests a key for the specified user. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ATTEST_KEY and  ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Security.Huks.Extension

**Parameters**

| Name  | Type                       | Mandatory| Description                                |
| -------- | --------------------------- | ---- | ------------------------------------ |
| userId   | number                      | Yes  | User ID.                |
| keyAlias | string                      | Yes  | Alias of the key. The certificate to be obtained stores the key.|
| options  | [HuksOptions](js-apis-huks.md#huksoptions) | Yes  | Options for attesting the key.  |

**Return value**

| Type                                          | Description                                         |
| ---------------------------------------------- | --------------------------------------------- |
| Promise<[HuksReturnResult](js-apis-huks.md#huksreturnresult9)> | Promise used to return the result. If the operation is successful, **certChains** in **HuksReturnResult** is the certificate chain obtained.|

**Error codes**

For details about the error codes, see [HUKS Error Codes](errorcode-huks.md).

| ID| Error Message     |
| -------- | ------------- |
| 201 | the application permission is not sufficient, which may be caused by lack of acrossing-account permission, or the system has not been unlocked by user, or the user does not exist. |
| 202 | non-system applications are not allowed to use system APIs. |
| 401 | argument is invalid. |
| 801 | api is not supported. |
| 12000001 | algorithm mode is not supported. |
| 12000002 | algorithm param is missing. |
| 12000003 | algorithm param is invalid. |
| 12000004 | operating file failed. |
| 12000005 | IPC communication failed. |
| 12000006 | error occured in crypto engine. |
| 12000011 | queried entity does not exist. |
| 12000012 | external error. |
| 12000014 | memory is insufficient. |

**Example**

- Before calling the API in the sample code, ensure that the target user (user whose ID is to set) has signed in to the device. For details, see **Example** in [generateKeyItemAsUser](#huksgeneratekeyitemasuser12).

```ts
import promptAction from '@ohos.promptAction';
import huks from '@ohos.security.huks';
import { BusinessError } from 'basic';


function StringToUint8Array(str: string) {
  let arr: number[] = [];
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

const rsaKeyAlias = 'test_rsaKeyAlias';
const userId = 101;
const userIdStorageLevel = huks.HuksAuthStorageLevel.HUKS_AUTH_STORAGE_LEVEL_CE;

let securityLevel = StringToUint8Array('sec_level');
let challenge = StringToUint8Array('challenge_data');
let versionInfo = StringToUint8Array('version_info');

function GetRSA4096GenerateProperties(): Array<huks.HuksParam> {
  return [{
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_RSA
  }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_RSA_KEY_SIZE_4096
  }, {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT |
    huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT
  }, {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256
  }, {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_PKCS1_V1_5
  }, {
    tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
    value: huks.HuksCipherMode.HUKS_MODE_ECB
  }, {
    tag: huks.HuksTag.HUKS_TAG_AUTH_STORAGE_LEVEL,
    value: userIdStorageLevel,
  }]
}

async function GenerateKey(keyAlias: string, genProperties: Array<huks.HuksParam>) {
  const options: huks.HuksOptions = {
    properties: genProperties
  }
  await huks.generateKeyItemAsUser(userId, keyAlias, options).then((data) => {
    promptAction.showToast({
      message: "A key with the alias of "+ keyAlias +" is generated.",
      duration: 2500,
    })
  }).catch((err: BusinessError) => {
    promptAction.showToast({
      message: "Failed to generate the key. Error code: "+ err.code +" Error message: "+ err.message,
      duration: 6500,
    })
  })
}

function GetAttestKeyProperties(keyAlias: string): Array<huks.HuksParam> {
  return new Array<huks.HuksParam>({
    tag: huks.HuksTag.HUKS_TAG_ATTESTATION_ID_SEC_LEVEL_INFO,
    value: securityLevel
  }, {
    tag: huks.HuksTag.HUKS_TAG_ATTESTATION_CHALLENGE,
    value: challenge
  }, {
    tag: huks.HuksTag.HUKS_TAG_ATTESTATION_ID_VERSION_INFO,
    value: versionInfo
  }, {
    tag: huks.HuksTag.HUKS_TAG_ATTESTATION_ID_ALIAS,
    value: StringToUint8Array(keyAlias)
  }, {
    tag: huks.HuksTag.HUKS_TAG_AUTH_STORAGE_LEVEL,
    value: userIdStorageLevel,
  })
}

async function LetKeyAttest(keyAlias: string, keyOptions: Array<huks.HuksParam>) {
  let attestOptions: huks.HuksOptions = {
    properties: keyOptions,
  }
  console.log ('start attestation')
  await huks.attestKeyItemAsUser(userId, keyAlias, attestOptions).then((data) => {
    console.log('attestation ok!')
    console.log(`The obtained certificate chain is ${JSON.stringify(data)}`)
    for (let i = 0; data?.certChains?.length && i < data?.certChains?.length; ++i) {
      console.log (`Certificate ${i} is ${data.certChains[i]}`)
    }
    promptAction.showToast({
      message: "Attestation is successful.",
      duration: 3000,
    })
  }).catch((err: BusinessError) => {
    promptAction.showToast({
      message: "Attestation failed. Error code: "+ err.code +" Error code: "+ err.message,
      duration: 6500,
    })
  })
}

async function TestHuksAttest() {
  await GenerateKey(rsaKeyAlias, GetRSA4096GenerateProperties())
  await LetKeyAttest(rsaKeyAlias, GetAttestKeyProperties(rsaKeyAlias))
}

export default function DocTest() {
  console.log('huks doc test')
  TestHuksAttest()
}
```

## huks.anonAttestKeyItemAsUser<sup>12+</sup>

anonAttestKeyItemAsUser(userId: number, keyAlias: string, options: HuksOptions) : Promise\<HuksReturnResult>

Performs anonymous key attestation. This API uses a promise to return the result.

This operation requires Internet access and takes time.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Security.Huks.Extension

**Parameters**

| Name  | Type                       | Mandatory| Description                                |
| -------- | --------------------------- | ---- | ------------------------------------ |
| userId   | number                      | Yes  | User ID.                |
| keyAlias | string                      | Yes  | Alias of the key. The certificate to be obtained stores the key.|
| options  | [HuksOptions](js-apis-huks.md#huksoptions) | Yes  | Options for attesting the key.  |

**Return value**

| Type                                          | Description                                         |
| ---------------------------------------------- | --------------------------------------------- |
| Promise<[HuksReturnResult](js-apis-huks.md#huksreturnresult9)> | Promise used to return the result. If the operation is successful, **certChains** in **HuksReturnResult** is the certificate chain obtained.|

**Error codes**

For details about the error codes, see [HUKS Error Codes](errorcode-huks.md).

| ID| Error Message     |
| -------- | ------------- |
| 201 | the application permission is not sufficient, which may be caused by lack of acrossing-account permission, or the system has not been unlocked by user, or the user does not exist. |
| 202 | non-system applications are not allowed to use system APIs. |
| 401 | argument is invalid. |
| 801 | api is not supported. |
| 12000001 | algorithm mode is not supported. |
| 12000002 | algorithm param is missing. |
| 12000003 | algorithm param is invalid. |
| 12000004 | operating file failed. |
| 12000005 | IPC communication failed. |
| 12000006 | error occured in crypto engine. |
| 12000011 | queried entity does not exist. |
| 12000012 | external error. |
| 12000014 | memory is insufficient. |

**Example**

- Before calling the API in the sample code, ensure that the target user (user whose ID is to set) has signed in to the device. For details, see **Example** in [generateKeyItemAsUser](#huksgeneratekeyitemasuser12).

```ts
import promptAction from '@ohos.promptAction';
import huks from '@ohos.security.huks';
import { BusinessError } from 'basic';


function StringToUint8Array(str: string) {
  let arr: number[] = [];
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

const rsaKeyAlias = 'test_rsaKeyAlias';
const userId = 101;
const userIdStorageLevel = huks.HuksAuthStorageLevel.HUKS_AUTH_STORAGE_LEVEL_CE;

let securityLevel = StringToUint8Array('sec_level');
let challenge = StringToUint8Array('challenge_data');
let versionInfo = StringToUint8Array('version_info');

function GetRSA4096GenerateProperties(): Array<huks.HuksParam> {
  return [{
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_RSA
  }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_RSA_KEY_SIZE_4096
  }, {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT |
    huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT
  }, {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256
  }, {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_PKCS1_V1_5
  }, {
    tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
    value: huks.HuksCipherMode.HUKS_MODE_ECB
  }, {
    tag: huks.HuksTag.HUKS_TAG_AUTH_STORAGE_LEVEL,
    value: userIdStorageLevel,
  }]
}

async function GenerateKey(keyAlias: string, genProperties: Array<huks.HuksParam>) {
  const options: huks.HuksOptions = {
    properties: genProperties
  }
  await huks.generateKeyItemAsUser(userId, keyAlias, options).then((data) => {
    promptAction.showToast({
      message: "A key with the alias of "+ keyAlias +" is generated.",
      duration: 2500,
    })
  }).catch((err: BusinessError) => {
    promptAction.showToast({
      message: "Failed to generate the key. Error code: "+ err.code +" Error message: "+ err.message,
      duration: 6500,
    })
  })
}

function GetAttestKeyProperties(keyAlias: string): Array<huks.HuksParam> {
  return new Array<huks.HuksParam>({
    tag: huks.HuksTag.HUKS_TAG_ATTESTATION_ID_SEC_LEVEL_INFO,
    value: securityLevel
  }, {
    tag: huks.HuksTag.HUKS_TAG_ATTESTATION_CHALLENGE,
    value: challenge
  }, {
    tag: huks.HuksTag.HUKS_TAG_ATTESTATION_ID_VERSION_INFO,
    value: versionInfo
  }, {
    tag: huks.HuksTag.HUKS_TAG_ATTESTATION_ID_ALIAS,
    value: StringToUint8Array(keyAlias)
  }, {
    tag: huks.HuksTag.HUKS_TAG_AUTH_STORAGE_LEVEL,
    value: userIdStorageLevel,
  })
}

async function LetKeyAnonAttest(keyAlias: string, keyOptions: Array<huks.HuksParam>) {
  let attestOptions: huks.HuksOptions = {
    properties: keyOptions,
  }
  console.log ('Start anonymous attestation')
  await huks.anonAttestKeyItemAsUser(userId, keyAlias, attestOptions).then((data) => {
    console.log ('Anonymous attestation ok!')
    console.log(`The obtained certificate chain is ${JSON.stringify(data)}`)
    for (let i = 0; data?.certChains?.length && i < data?.certChains?.length; ++i) {
      console.log (`Certificate ${i} is ${data.certChains[i]}`)
    }
    promptAction.showToast({
      message: "Anonymous attestation is successful.",
      duration: 3000,
    })
  }).catch((err: BusinessError) => {
    promptAction.showToast({
      message: "Anonymous attestation failed. Error code: "+ err.code +" Error message: "+ err.message,
      duration: 6500,
    })
  })
}


async function TestHuksAnonAttest() {
  await  GenerateKey(rsaKeyAlias, GetRSA4096GenerateProperties())
  await LetKeyAnonAttest(rsaKeyAlias, GetAttestKeyProperties(rsaKeyAlias))
}

export default function DocTest() {
  console.log('huks doc test')
  TestHuksAnonAttest()
}
```

## huks.importWrappedKeyItemAsUser<sup>12+</sup>

importWrappedKeyItemAsUser(userId: number, keyAlias: string, wrappingKeyAlias: string, options: HuksOptions) : Promise\<void>

Imports a wrapped (encrypted) key for the specified user. This API uses a promise to return the result.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Security.Huks.Extension

**Parameters**

| Name          | Type                       | Mandatory| Description                                         |
| ---------------- | --------------------------- | ---- | --------------------------------------------- |
| userId   | number                      | Yes  | User ID.                |
| keyAlias         | string                      | Yes  | Alias of the wrapped key to import.             |
| wrappingKeyAlias | string                      | Yes  | Alias of the key used to decrypt the wrapped key.   |
| options          | [HuksOptions](js-apis-huks.md#huksoptions) | Yes  | Options for importing the wrapped key. The algorithm, key purpose, and key length are mandatory.|

**Error codes**

For details about the error codes, see [HUKS Error Codes](errorcode-huks.md).

| ID| Error Message     |
| -------- | ------------- |
| 201 | the application permission is not sufficient, which may be caused by lack of acrossing-account permission, or the system has not been unlocked by user, or the user does not exist. |
| 202 | non-system applications are not allowed to use system APIs. |
| 401 | argument is invalid. |
| 801 | api is not supported. |
| 12000001 | algorithm mode is not supported. |
| 12000002 | algorithm param is missing. |
| 12000003 | algorithm param is invalid. |
| 12000004 | operating file failed. |
| 12000005 | IPC communication failed. |
| 12000006 | error occured in crypto engine. |
| 12000011 | queried entity does not exist. |
| 12000012 | external error. |
| 12000013 | queried credential does not exist. |
| 12000014 | memory is insufficient. |
| 12000015 | call service failed. |

**Example**

- Before calling the API in the sample code, ensure that the target user (user whose ID is to set) has signed in to the device. For details, see **Example** in [generateKeyItemAsUser](#huksgeneratekeyitemasuser12).
- The values of variables, including but not limited to **IV**, **AAD**, **NONCE**, and **importedAes192PlainKey**, are examples only and cannot be directly used. You need to assign values to your APIs based on actual situation. The length of the variables varies depending on the cryptographic algorithm used. If you need to change the length of the initial values, also change the cryptographic algorithm.

```ts
import promptAction from '@ohos.promptAction';
import huks from '@ohos.security.huks';
import { BusinessError } from 'basic';

const userIdStorageLevel = huks.HuksAuthStorageLevel.HUKS_AUTH_STORAGE_LEVEL_CE;
let IV = '0000000000000000';
let AAD = "abababababababab";
let NONCE = "hahahahahaha";
let TAG_SIZE = 16;
let FILED_LENGTH = 4;
let importedAes192PlainKey = "The aes192 key to import";
let callerAes256Kek = "The is kek to encrypt aes192 key";

let callerKeyAlias = "test_caller_key_ecdh_aes192";
let callerKekAliasAes256 = "test_caller_kek_ecdh_aes256";
let callerAgreeKeyAliasAes256 = "test_caller_agree_key_ecdh_aes256";
let importedKeyAliasAes192 = "test_import_key_ecdh_aes192";

let huksPubKey: Uint8Array;
let callerSelfPublicKey: Uint8Array;
let outSharedKey: Uint8Array;
let outPlainKeyEncData: Uint8Array;
let outKekEncData: Uint8Array;
let outKekEncTag: Uint8Array;
let outAgreeKeyEncTag: Uint8Array;

let mask = [0x000000FF, 0x0000FF00, 0x00FF0000, 0xFF000000];


function StringToUint8Array(str: string) {
  let arr: number[] = [];
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

function subUint8ArrayOf(arrayBuf: Uint8Array, start: number, end: number) {
  let arr: Array<number> = [];
  for (let i = start; i < end && i < arrayBuf.length; ++i) {
    arr.push(arrayBuf[i]);
  }
  return new Uint8Array(arr);
}

function assignLength(length: number, arrayBuf: Uint8Array, startIndex: number) {
  let index = startIndex;
  for (let i = 0; i < 4; i++) {
    arrayBuf[index++] = (length & mask[i]) >> (i * 8);
  }
  return 4;
}

function assignData(data: Uint8Array, arrayBuf: Uint8Array, startIndex: number) {
  let index = startIndex;
  for (let i = 0; i < data.length; i++) {
    arrayBuf[index++] = data[i];
  }
  return data.length;
}

let genWrappingKeyParams: huks.HuksOptions = {
  properties: [
    {
      tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
      value: huks.HuksKeyAlg.HUKS_ALG_ECC
    },
    {
      tag: huks.HuksTag.HUKS_TAG_PURPOSE,
      value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_UNWRAP
    },
    {
      tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
      value: huks.HuksKeySize.HUKS_CURVE25519_KEY_SIZE_256
    },
    {
      tag: huks.HuksTag.HUKS_TAG_PADDING,
      value: huks.HuksKeyPadding.HUKS_PADDING_NONE
    },
    {
      tag: huks.HuksTag.HUKS_TAG_AUTH_STORAGE_LEVEL,
      value: userIdStorageLevel,
    }
  ]
}

let genCallerEcdhParams: huks.HuksOptions = {
  properties: [
    {
      tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
      value: huks.HuksKeyAlg.HUKS_ALG_ECC
    },
    {
      tag: huks.HuksTag.HUKS_TAG_PURPOSE,
      value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_AGREE
    },
    {
      tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
      value: huks.HuksKeySize.HUKS_CURVE25519_KEY_SIZE_256
    },
    {
      tag: huks.HuksTag.HUKS_TAG_AUTH_STORAGE_LEVEL,
      value: userIdStorageLevel,
    }
  ]
}

let importParamsCallerKek: huks.HuksOptions = {
  properties: [
    {
      tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
      value: huks.HuksKeyAlg.HUKS_ALG_AES
    },
    {
      tag: huks.HuksTag.HUKS_TAG_PURPOSE,
      value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT
    },
    {
      tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
      value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_256
    },
    {
      tag: huks.HuksTag.HUKS_TAG_PADDING,
      value: huks.HuksKeyPadding.HUKS_PADDING_NONE
    },
    {
      tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
      value: huks.HuksCipherMode.HUKS_MODE_GCM
    },
    {
      tag: huks.HuksTag.HUKS_TAG_DIGEST,
      value: huks.HuksKeyDigest.HUKS_DIGEST_NONE
    },
    {
      tag: huks.HuksTag.HUKS_TAG_IV,
      value: StringToUint8Array(IV)
    },
    {
      tag: huks.HuksTag.HUKS_TAG_AUTH_STORAGE_LEVEL,
      value: userIdStorageLevel,
    }
  ],
  inData: StringToUint8Array(callerAes256Kek)
}

let importParamsAgreeKey: huks.HuksOptions = {
  properties: [
    {
      tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
      value: huks.HuksKeyAlg.HUKS_ALG_AES
    },
    {
      tag: huks.HuksTag.HUKS_TAG_PURPOSE,
      value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT
    },
    {
      tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
      value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_256
    },
    {
      tag: huks.HuksTag.HUKS_TAG_PADDING,
      value: huks.HuksKeyPadding.HUKS_PADDING_NONE
    },
    {
      tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
      value: huks.HuksCipherMode.HUKS_MODE_GCM
    },
    {
      tag: huks.HuksTag.HUKS_TAG_DIGEST,
      value: huks.HuksKeyDigest.HUKS_DIGEST_NONE
    },
    {
      tag: huks.HuksTag.HUKS_TAG_IV,
      value: StringToUint8Array(IV)
    },
    {
      tag: huks.HuksTag.HUKS_TAG_AUTH_STORAGE_LEVEL,
      value: userIdStorageLevel,
    }
  ]
}

let callerAgreeParams: huks.HuksOptions = {
  properties: [
    {
      tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
      value: huks.HuksKeyAlg.HUKS_ALG_ECDH
    },
    {
      tag: huks.HuksTag.HUKS_TAG_PURPOSE,
      value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_AGREE
    },
    {
      tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
      value: huks.HuksKeySize.HUKS_CURVE25519_KEY_SIZE_256
    },
    {
      tag: huks.HuksTag.HUKS_TAG_AUTH_STORAGE_LEVEL,
      value: userIdStorageLevel,
    }
  ]
}

let encryptKeyCommonParams: huks.HuksOptions = {
  properties: [
    {
      tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
      value: huks.HuksKeyAlg.HUKS_ALG_AES
    },
    {
      tag: huks.HuksTag.HUKS_TAG_PURPOSE,
      value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT
    },
    {
      tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
      value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_256
    },
    {
      tag: huks.HuksTag.HUKS_TAG_PADDING,
      value: huks.HuksKeyPadding.HUKS_PADDING_NONE
    },
    {
      tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
      value: huks.HuksCipherMode.HUKS_MODE_GCM
    },
    {
      tag: huks.HuksTag.HUKS_TAG_NONCE,
      value: StringToUint8Array(NONCE)
    },
    {
      tag: huks.HuksTag.HUKS_TAG_ASSOCIATED_DATA,
      value: StringToUint8Array(AAD)
    },
    {
      tag: huks.HuksTag.HUKS_TAG_AUTH_STORAGE_LEVEL,
      value: userIdStorageLevel,
    }
  ]
}

let importWrappedAes192Params: huks.HuksOptions = {
  properties: [
    {
      tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
      value: huks.HuksKeyAlg.HUKS_ALG_AES
    },
    {
      tag: huks.HuksTag.HUKS_TAG_PURPOSE,
      value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT |
      huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT
    },
    {
      tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
      value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_192
    },
    {
      tag: huks.HuksTag.HUKS_TAG_PADDING,
      value: huks.HuksKeyPadding.HUKS_PADDING_NONE
    },
    {
      tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
      value: huks.HuksCipherMode.HUKS_MODE_CBC
    },
    {
      tag: huks.HuksTag.HUKS_TAG_DIGEST,
      value: huks.HuksKeyDigest.HUKS_DIGEST_NONE
    },
    {
      tag: huks.HuksTag.HUKS_TAG_UNWRAP_ALGORITHM_SUITE,
      value: huks.HuksUnwrapSuite.HUKS_UNWRAP_SUITE_ECDH_AES_256_GCM_NOPADDING
    },
    {
      tag: huks.HuksTag.HUKS_TAG_IV,
      value: StringToUint8Array(IV)
    },
    {
      tag: huks.HuksTag.HUKS_TAG_AUTH_STORAGE_LEVEL,
      value: userIdStorageLevel,
    }
  ]
}

async function publicGenerateItemFunc(
    userId: number,
    keyAlias: string, huksOptions: huks.HuksOptions) {
  console.info(`enter promise generateKeyItemAsUser`);
  try {
    await huks.generateKeyItemAsUser(userId, keyAlias, huksOptions)
      .then(data => {
        console.info(`promise: generateKeyItemAsUser success, data = ${JSON.stringify(data)}`);
      })
      .catch((err: BusinessError) => {
        console.error(`callback: generateKeyItemAsUser failed, code: ${err.code}, msg: ${err.message}`);
      })
  } catch (err) {
    console.error(`callback: generateKeyItemAsUser invalid, code: ${err.code}, msg: ${err.message}`);
  }
}

async function publicImportKeyItemFunc(
    userId: number,
    keyAlias: string, huksOptions: huks.HuksOptions) {
  console.info(`enter promise importKeyItemAsUser`);
  try {
    await huks.importKeyItemAsUser(userId, keyAlias, huksOptions)
      .then(data => {
        console.info(`promise: importKeyItemAsUser success, data = ${JSON.stringify(data)}`);
      }).catch((err: BusinessError) => {
        console.error(`promise: importKeyItemAsUser failed, code: ${err.code}, msg: ${err.message}`);
      })
  } catch (err) {
    console.error(`promise: importKeyItemAsUser input arg invalid, code: ${err.code}, msg: ${err.message}`);
  }
}

async function publicDeleteKeyItemFunc(
    userId: number,
    keyAlias: string, huksOptions: huks.HuksOptions) {
  console.info(`enter promise deleteKeyItemAsUser`);
  try {
    await huks.deleteKeyItemAsUser(userId, keyAlias, huksOptions)
      .then(data => {
        console.info(`promise: deleteKeyItemAsUser key success, data = ${JSON.stringify(data)}`);
      })
      .catch((err: BusinessError) => {
        console.error(`promise: deleteKeyItemAsUser failed, code: ${err.code}, msg: ${err.message}`);
      })
  } catch (err) {
    console.error(`promise: deleteKeyItemAsUser input arg invalid, code: ${err.code}, msg: ${err.message}`);
  }
}

async function publicImportWrappedKeyFunc(
    userId: number,
    keyAlias: string, wrappingKeyAlias: string, huksOptions: huks.HuksOptions) {
  console.info(`enter callback importWrappedKeyItemAsUser`);
  console.error(`publicImportWrappedKeyFunc huksOptions = ${JSON.stringify(huksOptions)}`);
  try {
    await huks.importWrappedKeyItemAsUser(userId, keyAlias, wrappingKeyAlias, huksOptions)
      .then((data) => {
        console.info(`callback: importWrappedKeyItemAsUser success, data = ${JSON.stringify(data)}`);
        promptAction.showToast({
          message: `importWrappedKeyItemAsUser successful. data = ${JSON.stringify(data)}`,
          duration: 3000,
        })
      })
      .catch((err: BusinessError) => {
        console.error(`callback: importWrappedKeyItemAsUser failed, code: ${err.code}, msg: ${err.message}`);
      });
  } catch (error) {
    console.error(`callback: importWrappedKeyItemAsUser input arg invalid, code: ${error.code}, msg: ${error.message}`);
  }
}

async function publicInitFunc(
    userId: number,
    srcKeyAlias: string, huksOptions: huks.HuksOptions) {
  let handle: number = 0;
  console.info(`enter promise doInit`);
  try {
    await huks.initSessionAsUser(userId, srcKeyAlias, huksOptions)
      .then((data) => {
        console.info(`promise: initSessionAsUser success, data = ${JSON.stringify(data)}`);
        handle = data.handle;
      })
      .catch((err: BusinessError) => {
        console.error(`promise: initSessionAsUser key failed, code: ${err.code}, msg: ${err.message}`);
      });
  } catch (error) {
    console.error(`promise: doInit input arg invalid, code: ${error.code}, msg: ${error.message}`);
  }
  return handle;
}

async function publicUpdateSessionFunction(handle: number, huksOptions: huks.HuksOptions) {
  if (huksOptions?.inData?.length == undefined) {
    return [];
  }
  const maxUpdateSize = 64;
  const inData = huksOptions.inData;
  const lastInDataPosition = inData.length - 1;
  let inDataSegSize = maxUpdateSize;
  let inDataSegPosition = 0;
  let isFinished = false;
  let outData: Array<number> = [];

  while (inDataSegPosition <= lastInDataPosition) {
    if (inDataSegPosition + maxUpdateSize > lastInDataPosition) {
      isFinished = true;
      inDataSegSize = lastInDataPosition - inDataSegPosition + 1;
      console.error(`enter promise doUpdate`);
      break;
    }
    huksOptions.inData = new Uint8Array(
      Array.from(inData).slice(inDataSegPosition, inDataSegPosition + inDataSegSize)
    );
    console.error(`enter promise doUpdate`);
    try {
      await huks.updateSession(handle, huksOptions)
        .then((data) => {
          console.error(`promise: doUpdate success, data = ${JSON.stringify(data)}`);
          if (data.outData == undefined) {
            console.error('data.outData is undefined');
            return;
          }
          outData = outData.concat(Array.from(data.outData));
        })
        .catch((err: BusinessError) => {
          console.error(`promise: doUpdate failed, code: ${err.code}, msg: ${err.message}`);
        });
    } catch (error) {
      console.error(`promise: doUpdate input arg invalid, code: ${error.code}, msg: ${error.message}`);
    }
    if ((!isFinished) && (inDataSegPosition + maxUpdateSize > lastInDataPosition)) {
      console.log(`update size invalid isFinished = ${isFinished}`);
      console.log(`inDataSegPosition = ${inDataSegPosition}`);
      console.log(`lastInDataPosition = ${lastInDataPosition}`);
      return [];
    }
    inDataSegPosition += maxUpdateSize;
  }
  return outData;
}

async function publicFinishSession(handle: number, huksOptions: huks.HuksOptions, inData: Array<number>) {
  let outData: Array<number> = [];
  console.info(`enter promise doFinish`);
  try {
    await huks.finishSession(handle, huksOptions)
      .then((data) => {
        console.info(`promise: doFinish success, data = ${JSON.stringify(data)}`);
        if (data.outData == undefined) {
          console.error('data.outData is undefined');
          return;
        }
        outData = inData.concat(Array.from(data.outData));
      })
      .catch((err: BusinessError) => {
        console.error(`promise: doFinish key failed, code: ${err.code}, msg: ${err.message}`);
      });
  } catch (error) {
    console.error(`promise: doFinish input arg invalid, code: ${error.code}, msg: ${error.message}`);
  }
  return new Uint8Array(outData);
}

async function cipherFunction(
    userId: number,
    keyAlias: string, huksOptions: huks.HuksOptions) {
  let handle = await publicInitFunc(userId, keyAlias, huksOptions);
  let tmpData = await publicUpdateSessionFunction(handle, huksOptions);
  let outData = await publicFinishSession(handle, huksOptions, tmpData);
  return outData;
}

async function agreeFunction(
    userId: number,
    keyAlias: string, huksOptions: huks.HuksOptions, huksPublicKey: Uint8Array) {
  let handle = await publicInitFunc(userId, keyAlias, huksOptions);
  let outSharedKey: Uint8Array = new Uint8Array;
  huksOptions.inData = huksPublicKey;
  console.error(`enter promise doUpdate`);
  try {
    await huks.updateSession(handle, huksOptions)
      .then((data) => {
        console.error(`promise: doUpdate success, data = ${JSON.stringify(data)}`);
      })
      .catch((err: BusinessError) => {
        console.error(`promise: doUpdate failed, code: ${err.code}, msg: ${err.message}`);
      });
  } catch (error) {
    console.error(`promise: doUpdate input arg invalid, code: ${error.code}, msg: ${error.message}`);
  }
  console.info(`enter promise doInit`);
  try {
    await huks.finishSession(handle, huksOptions)
      .then((data) => {
        console.info(`promise: doInit success, data = ${JSON.stringify(data)}`);
        if (data.outData == undefined) {
          console.error('data.outData is undefined');
          return;
        }
        outSharedKey = data.outData;
      })
      .catch((err: BusinessError) => {
        console.error(`promise: doInit key failed, code: ${err.code}, msg: ${err.message}`);
      });
  } catch (error) {
    console.error(`promise: doInit input arg invalid, code: ${error.code}, msg: ${error.message}`);
  }
  return outSharedKey;
}

async function ImportKekAndAgreeSharedSecret(
    userId: number,
    callerKekAlias: string, importKekParams: huks.HuksOptions, callerKeyAlias: string, huksPublicKey: Uint8Array, agreeParams: huks.HuksOptions) {
  await publicImportKeyItemFunc(userId, callerKekAlias, importKekParams);
  outSharedKey = await agreeFunction(userId, callerKeyAlias, agreeParams, huksPublicKey);

  importParamsAgreeKey.inData = outSharedKey;
  await publicImportKeyItemFunc(userId, callerAgreeKeyAliasAes256, importParamsAgreeKey);
}

async function generateAndExportPublicKey(
    userId: number,
    keyAlias: string, huksOptions: huks.HuksOptions, caller: boolean) {
  await publicGenerateItemFunc(userId, keyAlias, huksOptions);
  try {
    await huks.exportKeyItemAsUser(userId, keyAlias, huksOptions)
      .then((data) => {
        console.info(`promise: exportKeyItemAsUser success, data = ${JSON.stringify(data)}`);
        if (data.outData == undefined) {
          console.error('data.outData is undefined');
          return;
        }
        if (caller) {
          callerSelfPublicKey = data.outData;
        } else {
          huksPubKey = data.outData;
        }
      })
      .catch((err: BusinessError) => {
        console.error(`promise: exportKeyItemAsUser failed, code: ${err.code}, msg: ${err.message}`);
      });
  } catch (e) {
    console.error(`promise: generate pubKey failed, code: ${e.code}, msg: ${e.message}`);
  }
}

async function EncryptImportedPlainKeyAndKek(
    userId: number,
    keyAlias: string) {
  encryptKeyCommonParams.inData = StringToUint8Array(keyAlias)
  let plainKeyEncData = await cipherFunction(userId, callerKekAliasAes256, encryptKeyCommonParams);
  outKekEncTag = subUint8ArrayOf(plainKeyEncData, plainKeyEncData.length - TAG_SIZE, plainKeyEncData.length)
  outPlainKeyEncData = subUint8ArrayOf(plainKeyEncData, 0, plainKeyEncData.length - TAG_SIZE)

  encryptKeyCommonParams.inData = StringToUint8Array(callerAes256Kek)
  let kekEncData = await cipherFunction(userId, callerAgreeKeyAliasAes256, encryptKeyCommonParams)
  outAgreeKeyEncTag = subUint8ArrayOf(kekEncData, kekEncData.length - TAG_SIZE, kekEncData.length)
  outKekEncData = subUint8ArrayOf(kekEncData, 0, kekEncData.length - TAG_SIZE)
}

async function BuildWrappedDataAndImportWrappedKey(plainKey: string) {
  let plainKeySizeBuff = new Uint8Array(4);
  assignLength(plainKey.length, plainKeySizeBuff, 0);

  let wrappedData = new Uint8Array(
    FILED_LENGTH + huksPubKey.length +
    FILED_LENGTH + AAD.length +
    FILED_LENGTH + NONCE.length +
    FILED_LENGTH + TAG_SIZE +
    FILED_LENGTH + outKekEncData.length +
    FILED_LENGTH + AAD.length +
    FILED_LENGTH + NONCE.length +
    FILED_LENGTH + TAG_SIZE +
    FILED_LENGTH + plainKeySizeBuff.length +
    FILED_LENGTH + outPlainKeyEncData.length
  );
  let index = 0;
  let AADUint8Array = StringToUint8Array(AAD);
  let NonceArray = StringToUint8Array(NONCE);

  index += assignLength(callerSelfPublicKey.length, wrappedData, index); // 4
  index += assignData(callerSelfPublicKey, wrappedData, index); // 91
  index += assignLength(AADUint8Array.length, wrappedData, index); // 4
  index += assignData(AADUint8Array, wrappedData, index); // 16
  index += assignLength(NonceArray.length, wrappedData, index); // 4
  index += assignData(NonceArray, wrappedData, index); // 12
  index += assignLength(outAgreeKeyEncTag.length, wrappedData, index); // 4
  index += assignData(outAgreeKeyEncTag, wrappedData, index); // 16
  index += assignLength(outKekEncData.length, wrappedData, index); // 4
  index += assignData(outKekEncData, wrappedData, index); // 32
  index += assignLength(AADUint8Array.length, wrappedData, index); // 4
  index += assignData(AADUint8Array, wrappedData, index); // 16
  index += assignLength(NonceArray.length, wrappedData, index); // 4
  index += assignData(NonceArray, wrappedData, index); // 12
  index += assignLength(outKekEncTag.length, wrappedData, index); // 4
  index += assignData(outKekEncTag, wrappedData, index); // 16
  index += assignLength(plainKeySizeBuff.length, wrappedData, index); // 4
  index += assignData(plainKeySizeBuff, wrappedData, index); // 4
  index += assignLength(outPlainKeyEncData.length, wrappedData, index); // 4
  index += assignData(outPlainKeyEncData, wrappedData, index); // 24

  return wrappedData;
}

export async function HuksSecurityImportTest(userId: number) {
  const srcKeyAliesWrap = 'HUKS_Basic_Capability_Import_0200';
  await generateAndExportPublicKey(userId, srcKeyAliesWrap, genWrappingKeyParams, false);
  await generateAndExportPublicKey(userId, callerKeyAlias, genCallerEcdhParams, true);

  await ImportKekAndAgreeSharedSecret(
    userId,
    callerKekAliasAes256, importParamsCallerKek, callerKeyAlias, huksPubKey, callerAgreeParams);
  await EncryptImportedPlainKeyAndKek(userId, importedAes192PlainKey);
  let wrappedData = await BuildWrappedDataAndImportWrappedKey(importedAes192PlainKey);
  importWrappedAes192Params.inData = wrappedData;
  await publicImportWrappedKeyFunc(userId,
    importedKeyAliasAes192, srcKeyAliesWrap, importWrappedAes192Params);
  await publicDeleteKeyItemFunc(userId, srcKeyAliesWrap, genWrappingKeyParams);
  await publicDeleteKeyItemFunc(userId, callerKeyAlias, genCallerEcdhParams);
  await publicDeleteKeyItemFunc(userId, importedKeyAliasAes192, importWrappedAes192Params);
  await publicDeleteKeyItemFunc(userId, callerKekAliasAes256, callerAgreeParams);
}

export default function DocTest() {
  console.log('huks doc test')

  const userId = 101;
  HuksSecurityImportTest(userId)
}
```

## huks.exportKeyItemAsUser<sup>12+</sup>

exportKeyItemAsUser(userId: number, keyAlias: string, options: HuksOptions) : Promise\<HuksReturnResult>

Exports the public key for the specified user. This API uses a promise to return the result.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Security.Huks.Extension

**Parameters**

| Name  | Type                       | Mandatory| Description                                        |
| -------- | --------------------------- | ---- | -------------------------------------------- |
| userId   | number                      | Yes  | User ID.                |
| keyAlias | string                      | Yes  | Key alias, which must be the same as the alias used when the key was generated.|
| options  | [HuksOptions](js-apis-huks.md#huksoptions) | Yes  | Empty object (leave this parameter empty).                    |

**Return value**

| Type                                          | Description                                                        |
| ---------------------------------------------- | ------------------------------------------------------------ |
| Promise<[HuksReturnResult](js-apis-huks.md#huksreturnresult9)> | Promise used to return the result. If the operation is successful, **outData** in **HuksReturnResult** is the public key exported.|

**Error codes**

For details about the error codes, see [HUKS Error Codes](errorcode-huks.md).

| ID| Error Message     |
| -------- | ------------- |
| 201 | the application permission is not sufficient, which may be caused by lack of acrossing-account permission, or the system has not been unlocked by user, or the user does not exist. |
| 202 | non-system applications are not allowed to use system APIs. |
| 401 | argument is invalid. |
| 801 | api is not supported. |
| 12000001 | algorithm mode is not supported. |
| 12000002 | algorithm param is missing. |
| 12000003 | algorithm param is invalid. |
| 12000004 | operating file failed. |
| 12000005 | IPC communication failed. |
| 12000006 | error occured in crypto engine. |
| 12000011 | queried entity does not exist. |
| 12000012 | external error. |
| 12000014 | memory is insufficient. |

**Example**

- Before calling the API in the sample code, ensure that the target user (user whose ID is to set) has signed in to the device. For details, see **Example** in [generateKeyItemAsUser](#huksgeneratekeyitemasuser12).

```ts
import promptAction from '@ohos.promptAction';
import huks from '@ohos.security.huks';
import { BusinessError } from 'basic';


const rsaKeyAlias = 'test_rsaKeyAlias';
const userId = 101;
const userIdStorageLevel = huks.HuksAuthStorageLevel.HUKS_AUTH_STORAGE_LEVEL_CE;

function GetRSA4096GenerateProperties(): Array<huks.HuksParam> {
  return [{
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_RSA
  }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_RSA_KEY_SIZE_4096
  }, {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT |
    huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT
  }, {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256
  }, {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_PKCS1_V1_5
  }, {
    tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
    value: huks.HuksCipherMode.HUKS_MODE_ECB
  }, {
    tag: huks.HuksTag.HUKS_TAG_AUTH_STORAGE_LEVEL,
    value: userIdStorageLevel,
  }]
}

async function GenerateKey(keyAlias: string, genProperties: Array<huks.HuksParam>) {
  const options: huks.HuksOptions = {
    properties: genProperties
  }
  await huks.generateKeyItemAsUser(userId, keyAlias, options).then((data) => {
    promptAction.showToast({
      message: "A key with the alias of "+ keyAlias +" is generated.",
      duration: 2500,
    })
  }).catch((err: BusinessError) => {
    promptAction.showToast({
      message: "Failed to generate the key. Error code: "+ err.code +" Error message: "+ err.message,
      duration: 6500,
    })
  })
}

async function ExportPublicKey(keyAlias: string) {
  const options: huks.HuksOptions = {
    properties: [{
      tag: huks.HuksTag.HUKS_TAG_AUTH_STORAGE_LEVEL,
      value: userIdStorageLevel,
    }]
  }
  await huks.exportKeyItemAsUser(userId, keyAlias, options).then((data) => {
    promptAction.showToast({
      message: "The public key with the alias of " + keyAlias +" is exported. The length of data is "+ data?.outData?.length,
      duration: 2500,
    })
  }).catch((err: BusinessError) => {
    promptAction.showToast({
      message: "Failed to export the key. Error code: "+ err.code +" Error message: "+ err.message,
      duration: 6500,
    })
  })
}

async function ExportHuksTest() {
  await GenerateKey(rsaKeyAlias, GetRSA4096GenerateProperties())
  await ExportPublicKey(rsaKeyAlias)
}

export default function DocTest() {
  console.log('huks doc test')
  ExportHuksTest()
}
```

## huks.getKeyItemPropertiesAsUser<sup>12+</sup>

getKeyItemPropertiesAsUser(userId: number, keyAlias: string, options: HuksOptions) : Promise\<HuksReturnResult>

Obtains key properties for the specified user. This API uses a promise to return the result.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Security.Huks.Extension

**Parameters**

| Name  | Type                       | Mandatory| Description                                        |
| -------- | --------------------------- | ---- | -------------------------------------------- |
| userId   | number                      | Yes  | User ID.                |
| keyAlias | string                      | Yes  | Key alias, which must be the same as the alias used when the key was generated.|
| options  | [HuksOptions](js-apis-huks.md#huksoptions) | Yes  | Empty object (leave this parameter empty).                    |

**Return value**

| Type                                           | Description                                                        |
| ----------------------------------------------- | ------------------------------------------------------------ |
| Promise\<[HuksReturnResult](js-apis-huks.md#huksreturnresult9)> | Promise used to return the result. If the operation is successful, **properties** in **HuksReturnResult** holds the parameters required for generating the key.

**Error codes**

For details about the error codes, see [HUKS Error Codes](errorcode-huks.md).

| ID| Error Message     |
| -------- | ------------- |
| 201 | the application permission is not sufficient, which may be caused by lack of acrossing-account permission, or the system has not been unlocked by user, or the user does not exist. |
| 202 | non-system applications are not allowed to use system APIs. |
| 401 | argument is invalid. |
| 801 | api is not supported. |
| 12000001 | algorithm mode is not supported. |
| 12000002 | algorithm param is missing. |
| 12000003 | algorithm param is invalid. |
| 12000004 | operating file failed. |
| 12000005 | IPC communication failed. |
| 12000006 | error occured in crypto engine. |
| 12000011 | queried entity does not exist. |
| 12000012 | external error. |
| 12000014 | memory is insufficient. |

**Example**

- Before calling the API in the sample code, ensure that the target user (user whose ID is to set) has signed in to the device. For details, see **Example** in [generateKeyItemAsUser](#huksgeneratekeyitemasuser12).

```ts
import promptAction from '@ohos.promptAction';
import huks from '@ohos.security.huks';
import { BusinessError } from 'basic';


const aesKeyAlias = 'test_aesKeyAlias';
const userId = 101;
const userIdStorageLevel = huks.HuksAuthStorageLevel.HUKS_AUTH_STORAGE_LEVEL_CE;

function GetAesGenerateProperties(): Array<huks.HuksParam> {
  return [{
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_AES
  }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_128
  }, {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT |
    huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT
  }, {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_PKCS7
  }, {
    tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
    value: huks.HuksCipherMode.HUKS_MODE_CBC
  }, {
    tag: huks.HuksTag.HUKS_TAG_AUTH_STORAGE_LEVEL,
    value: userIdStorageLevel,
  }]
}

async function GenerateKey(keyAlias: string, genProperties: Array<huks.HuksParam>) {
  const options: huks.HuksOptions = {
    properties: genProperties
  }
  await huks.generateKeyItemAsUser(userId, keyAlias, options).then((data) => {
    promptAction.showToast({
      message: "A key with the alias of "+ keyAlias +" is generated.",
      duration: 2500,
    })
  }).catch((err: BusinessError) => {
    promptAction.showToast({
      message: "Failed to generate the key. Error code: "+ err.code +" Error message: "+ err.message,
      duration: 6500,
    })
  })
}

async function GetKeyProperties(keyAlias: string) {
  const options: huks.HuksOptions = {
    properties: [{
      tag: huks.HuksTag.HUKS_TAG_AUTH_STORAGE_LEVEL,
      value: userIdStorageLevel,
    }]
  }
  await huks.getKeyItemPropertiesAsUser(userId, keyAlias, options).then((data) => {
    promptAction.showToast({
      message: "Obtained key properties: " + JSON.stringify (data),
      duration: 6500,
    })
  }).catch((err: BusinessError) => {
    promptAction.showToast({
      message: "Failed to obtain key properties. Error code: "+ err.code +" Error code: "+ err.message,
      duration: 6500,
    })
  })
}

async function TestHuksGet() {
  await GenerateKey(aesKeyAlias, GetAesGenerateProperties())
  await GetKeyProperties(aesKeyAlias)
}

export default function DocTest() {
  console.log('huks doc test')
  TestHuksGet()
}
```

## huks.hasKeyItemAsUser<sup>12+</sup>

hasKeyItemAsUser(userId: number, keyAlias: string, options: HuksOptions) : Promise\<boolean>

Checks whether a key exists for the specified user. This API uses a promise to return the result.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Security.Huks.Extension

**Parameters**

| Name  | Type                       | Mandatory| Description                    |
| -------- | --------------------------- | ---- | ------------------------ |
| userId   | number                      | Yes  | User ID.                |
| keyAlias | string                      | Yes  | Alias of the key to check.  |
| options  | [HuksOptions](js-apis-huks.md#huksoptions) | Yes  | Options for checking the key. For example, you can pass in [HuksAuthStorageLevel](js-apis-huks.md#huksauthstoragelevel11) to specify the storage security level of the key to check. If **HuksAuthStorageLevel** is left empty, **HUKS_AUTH_STORAGE_LEVEL_DE** is used by default.    |

**Return value**

| Type             | Description                                   |
| ----------------- | --------------------------------------- |
| Promise\<boolean> | Promise used to return the result. If the key exists, **true** is returned. Otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [HUKS Error Codes](errorcode-huks.md).

| ID| Error Message     |
| -------- | ------------- |
| 201 | the application permission is not sufficient, which may be caused by lack of acrossing-account permission, or the system has not been unlocked by user, or the user does not exist. |
| 202 | non-system applications are not allowed to use system APIs. |
| 401 | argument is invalid. |
| 801 | api is not supported. |
| 12000002 | algorithm param is missing. |
| 12000003 | algorithm param is invalid. |
| 12000004 | operating file failed. |
| 12000005 | IPC communication failed. |
| 12000006 | error occured in crypto engine. |
| 12000012 | external error. |
| 12000014 | memory is insufficient. |

**Example**

- Before calling the API in the sample code, ensure that the target user (user whose ID is to set) has signed in to the device. For details, see **Example** in [generateKeyItemAsUser](#huksgeneratekeyitemasuser12).

```ts
import promptAction from '@ohos.promptAction';
import huks from '@ohos.security.huks';
import { BusinessError } from 'basic';

const aesKeyAlias = 'test_aesKeyAlias';
const userId = 101;
const userIdStorageLevel = huks.HuksAuthStorageLevel.HUKS_AUTH_STORAGE_LEVEL_CE;

function GetAesGenerateProperties(): Array<huks.HuksParam> {
  return [{
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_AES
  }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_128
  }, {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT |
    huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT
  }, {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_PKCS7
  }, {
    tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
    value: huks.HuksCipherMode.HUKS_MODE_CBC
  }, {
    tag: huks.HuksTag.HUKS_TAG_AUTH_STORAGE_LEVEL,
    value: userIdStorageLevel,
  }]
}

async function GenerateKey(keyAlias: string, genProperties: Array<huks.HuksParam>) {
  const options: huks.HuksOptions = {
    properties: genProperties
  }
  await huks.generateKeyItemAsUser(userId, keyAlias, options).then((data) => {
    promptAction.showToast({
      message: "A key with the alias of "+ keyAlias +" is generated.",
      duration: 2500,
    })
  }).catch((err: BusinessError) => {
    promptAction.showToast({
      message: "Failed to generate the key. Error code: "+ err.code +" Error message: "+ err.message,
      duration: 6500,
    })
  })
}

async function HasKey(keyAlias: string) {
  const options: huks.HuksOptions = {
    properties: [{
      tag: huks.HuksTag.HUKS_TAG_AUTH_STORAGE_LEVEL,
      value: userIdStorageLevel,
    }]
  }
  await huks.hasKeyItemAsUser(userId, keyAlias, options).then((data) => {
    console.log ("Check result of the key with the alias of "+ keyAlias +" " + JSON.stringify(data))
  }).catch((err: BusinessError) => {
    promptAction.showToast({
      message: "Failed to delete the key. Error code: "+ err.code +" Error message: "+ err.message,
      duration: 6500,
    })
  })
}

async function TestHuksHasKey() {
  await GenerateKey(aesKeyAlias, GetAesGenerateProperties())
  await HasKey(aesKeyAlias)
}

export default function DocTest() {
  console.log('huks doc test')
  TestHuksHasKey()
}
```

## huks.initSessionAsUser<sup>12+</sup>

initSessionAsUser(userId: number, keyAlias: string, options: HuksOptions) : Promise\<HuksSessionHandle>

Initialize a key session for the specified user. This API uses a promise to return the result. **huks.initSessionAsUser**, **huks.updateSession**, and **huks.finishSession** must be used together.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Security.Huks.Extension

**Parameters**

| Name  | Type                                             | Mandatory| Description                                            |
| -------- | ------------------------------------------------- | ---- | ------------------------------------------------ |
| userId   | number                                            | Yes  | User ID.                |
| keyAlias | string                                            | Yes  | Alias of the key for the **initSessionAsUser** operation.                            |
| options  | [HuksOptions](js-apis-huks.md#huksoptions)        | Yes  | Parameters for **initSessionAsUser**.                                  |

**Return value**

| Type                               | Description                                              |
| ----------------------------------- | -------------------------------------------------- |
| Promise\<[HuksSessionHandle](js-apis-huks.md#hukssessionhandle9)> | Promise used to return a session handle for subsequent operations.|

**Error codes**

For details about the error codes, see [HUKS Error Codes](errorcode-huks.md).

| ID| Error Message     |
| -------- | ------------- |
| 201 | the application permission is not sufficient, which may be caused by lack of acrossing-account permission, or the system has not been unlocked by user, or the user does not exist. |
| 202 | non-system applications are not allowed to use system APIs. |
| 401 | argument is invalid. |
| 801 | api is not supported. |
| 12000001 | algorithm mode is not supported. |
| 12000002 | algorithm param is missing. |
| 12000003 | algorithm param is invalid. |
| 12000004 | operating file failed. |
| 12000005 | IPC communication failed. |
| 12000006 | error occured in crypto engine. |
| 12000010 | the number of sessions has reached limit. |
| 12000011 | queried entity does not exist. |
| 12000012 | external error. |
| 12000014 | memory is insufficient. |

**Example**

- Before calling the API in the sample code, ensure that the target user (user whose ID is to set) has signed in to the device. For details, see **Example** in [generateKeyItemAsUser](#huksgeneratekeyitemasuser12).
- The values of variables, including but not limited to **IV**, are examples only and cannot be directly used. You need to assign values to your APIs based on actual situation. The length of the variables varies depending on the cryptographic algorithm used. If you need to change the length of the initial values, also change the cryptographic algorithm.

```ts
import promptAction from '@ohos.promptAction';
import huks from '@ohos.security.huks';
import { BusinessError } from 'basic';


const aesKeyAlias = 'test_aesKeyAlias';
const userId = 101;
const userIdStorageLevel = huks.HuksAuthStorageLevel.HUKS_AUTH_STORAGE_LEVEL_CE;
let IV = '001122334455';
let plainText = '123456789';
let cipherData: Uint8Array;

function StringToUint8Array(str: string) {
  let arr: number[] = [];
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

function Uint8ArrayToString(fileData: Uint8Array) {
  let dataString = '';
  for (let i = 0; i < fileData.length; i++) {
    dataString += String.fromCharCode(fileData[i]);
  }
  return dataString;
}

function GetAesGenerateProperties(): Array<huks.HuksParam> {
  return [{
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_AES
  }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_128
  }, {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT |
    huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT
  }, {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_PKCS7
  }, {
    tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
    value: huks.HuksCipherMode.HUKS_MODE_CBC
  }, {
    tag: huks.HuksTag.HUKS_TAG_AUTH_STORAGE_LEVEL,
    value: userIdStorageLevel,
  }]
}

function GetAesEncryptProperties(): Array<huks.HuksParam> {
  return [{
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_AES
  }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_128
  }, {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT
  }, {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_PKCS7
  }, {
    tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
    value: huks.HuksCipherMode.HUKS_MODE_CBC
  }, {
    tag: huks.HuksTag.HUKS_TAG_IV,
    value: StringToUint8Array(IV)
  }, {
    tag: huks.HuksTag.HUKS_TAG_AUTH_STORAGE_LEVEL,
    value: userIdStorageLevel,
  }]
}

function GetAesDecryptProperties(): Array<huks.HuksParam> {
  return [{
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_AES
  }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_256
  }, {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT
  }, {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_PKCS7
  }, {
    tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
    value: huks.HuksCipherMode.HUKS_MODE_CBC
  }, {
    tag: huks.HuksTag.HUKS_TAG_IV,
    value: StringToUint8Array(IV)
  }, {
    tag: huks.HuksTag.HUKS_TAG_AUTH_STORAGE_LEVEL,
    value: userIdStorageLevel,
  }]
}

async function GenerateKey(keyAlias: string, genProperties: Array<huks.HuksParam>) {
  const options: huks.HuksOptions = {
    properties: genProperties
  }
  await huks.generateKeyItemAsUser(userId, keyAlias, options).then((data) => {
    promptAction.showToast({
      message: "A key with the alias of "+ keyAlias +" is generated.",
      duration: 2500,
    })
  }).catch((err: BusinessError) => {
    promptAction.showToast({
      message: "Failed to generate the key. Error code: "+ err.code +" Error message: "+ err.message,
      duration: 6500,
    })
  })
}

async function EncryptData(keyAlias: string, encryptProperties: Array<huks.HuksParam>) {
  let ret = -1
  const options: huks.HuksOptions = {
    properties: encryptProperties,
    inData: StringToUint8Array(plainText)
  }
  let handle: number = 0;
  await huks.initSessionAsUser(userId, keyAlias, options).then((data) => {
    handle = data.handle;
  }).catch((err: BusinessError) => {
    promptAction.showToast({
      message: "Failed to initialize the key session. Error code: "+ err.code +" Error message: "+ err.message,
      duration: 6500,
    })
  })
  await huks.finishSession(handle, options).then((data) => {
    promptAction.showToast({
      message: "Data encrypted successfully. Ciphertext: " + Uint8ArrayToString(data.outData),
      duration: 1500,
    })
    if (data.outData != undefined) {
      cipherData = data.outData
    }
    console.log("running time result success!")
  }).catch((err: BusinessError) => {
    promptAction.showToast({
      message: "An exception is captured in the encryption process. Error code: " + err.code +" Error message: "+ err.message,
      duration: 6500,

    })
  })
  return ret
}

async function DecryptData(keyAlias: string, decryptProperties: Array<huks.HuksParam>) {
  const options: huks.HuksOptions = {
    properties: decryptProperties,
    inData: cipherData
  }
  let handle: number = 0;
  await huks.initSessionAsUser(userId, keyAlias, options).then((data) => {
    handle = data.handle;
  }).catch((err: BusinessError) => {
    promptAction.showToast({
      message: "Failed to initialize the key session. Error code: "+ err.code +" Error message: "+ err.message,
      duration: 6500,
    })
  })
  await huks.finishSession(handle, options).then((data) => {
    promptAction.showToast({
      message: "Data is decrypted. Plaintext: " + Uint8ArrayToString(data.outData),
      duration: 6500,
    })
  }).catch((err: BusinessError) => {
    promptAction.showToast({
      message: "An exception is captured in the decryption process. Error code: " + err.code +" Error message: "+ err.message,
      duration: 6500,
    })
  })
}

async function TestHuksInit() {
  await GenerateKey(aesKeyAlias, GetAesGenerateProperties())
  await EncryptData(aesKeyAlias, GetAesEncryptProperties())
  await DecryptData(aesKeyAlias, GetAesDecryptProperties())
}

export default function DocTest() {
  console.log('huks doc test')
  TestHuksInit()
}
```
