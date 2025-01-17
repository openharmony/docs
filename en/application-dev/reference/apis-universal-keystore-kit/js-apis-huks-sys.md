# @ohos.security.huks (HUKS) (System API)

The **huks** module provides keystore capabilities with the user who performs the key operation specified.

> **NOTE**
> - The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - This topic describes only the system APIs provided by the module. For details about its public APIs, see [@ohos.security.huks](js-apis-huks.md).

## Modules to Import

```ts
import { huks } from '@kit.UniversalKeystoreKit'
```

## huks.generateKeyItemAsUser

generateKeyItemAsUser(userId: number, keyAlias: string, huksOptions: HuksOptions) : Promise\<void>

Generates a key for the specified user. This API uses a promise to return the result. Because the key is always protected in a trusted environment (such as a TEE), the promise does not return the key content. It returns only the information indicating whether the API is successfully called.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Security.Huks.Extension

**Parameters**

| Name  | Type                       | Mandatory| Description                    |
| -------- | --------------------------- | ---- | ------------------------ |
| userId   | number                      | Yes  | User ID.                |
| keyAlias | string                      | Yes  | Alias of the key to generate.              |
| options  | [HuksOptions](js-apis-huks.md#huksoptions) | Yes  | [Property tags](native__huks__type_8h.md#enums) of the key to generate. The algorithm, key purpose, and key length are mandatory.|

**Error codes**

For details about the error codes, see [HUKS Error Codes](errorcode-huks.md).

| ID| Error Message     |
| -------- | ------------- |
| 201 | the application permission is not sufficient, which may be caused by lack of cross-account permission, or the system has not been unlocked by user, or the user does not exist. |
| 202 | non-system applications are not allowed to use system APIs. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |
| 801 | api is not supported. |
| 12000001 | algorithm mode is not supported. |
| 12000002 | algorithm param is missing. |
| 12000003 | algorithm param is invalid. |
| 12000004 | operating file failed. |
| 12000005 | IPC communication failed. |
| 12000006 | error occurred in crypto engine. |
| 12000012 | external error. |
| 12000013 | queried credential does not exist. |
| 12000014 | memory is insufficient. |
| 12000015 | call service failed. |

**Example**

- Prerequisites:

  The caller must be a system application running under user 0 to user 99 (inclusive) and must have the ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS permission. For details, see [singleton](../../../device-dev/subsystems/subsys-app-privilege-config-guide.md#device-specific-application-privileges).

```ts
import { huks } from '@kit.UniversalKeystoreKit';

const aesKeyAlias = 'test_aesKeyAlias';
const userId = 100;
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
    console.info("Generated a key with alias of: " + keyAlias + "")
  }).catch((err: Error) => {
    console.error("Failed to generate the key. Error: "+ JSON.stringify(err))
  })
}


export default function HuksAsUserTest() {
  console.info('begin huks as user test')
  GenerateKey(aesKeyAlias, GetAesGenerateProperties())
}
```

## huks.deleteKeyItemAsUser

deleteKeyItemAsUser(userId: number, keyAlias: string, huksOptions: HuksOptions) : Promise\<void>

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
| 201 | the application permission is not sufficient, which may be caused by lack of cross-account permission, or the system has not been unlocked by user, or the user does not exist. |
| 202 | non-system applications are not allowed to use system APIs. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |
| 801 | api is not supported. |
| 12000004 | operating file failed. |
| 12000005 | IPC communication failed. |
| 12000011 | queried entity does not exist. |
| 12000012 | external error. |
| 12000014 | memory is insufficient. |

**Example**

- Prerequisites: see **Example** of [generateKeyItemAsUser](#huksgeneratekeyitemasuser).

```ts
import { huks } from '@kit.UniversalKeystoreKit';
import { BusinessError } from "@kit.BasicServicesKit"

const aesKeyAlias = 'test_aesKeyAlias';
const userId = 100;
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
    console.error("Failed to generate the key. Error code: " + err.code + " Error message: " + err.message)
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
    console.info("Deleted the key with alias of: " + keyAlias + ".")
  }).catch((err: BusinessError) => {
    console.error("Failed to delete the key. Error code: " + err.code + " Error message: " + err.message)
  })
}

async function TestHuksDelete() {
  await GenerateKey(aesKeyAlias, GetAesGenerateProperties())
  await DeleteKey(aesKeyAlias)
}

export default function HuksAsUserTest() {
  console.info('begin huks as user test')
  TestHuksDelete()
}
```

## huks.importKeyItemAsUser

importKeyItemAsUser(userId: number, keyAlias: string, huksOptions: HuksOptions) : Promise\<void>

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
| 201 | the application permission is not sufficient, which may be caused by lack of cross-account permission, or the system has not been unlocked by user, or the user does not exist. |
| 202 | non-system applications are not allowed to use system APIs. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |
| 801 | api is not supported. |
| 12000001 | algorithm mode is not supported. |
| 12000002 | algorithm param is missing. |
| 12000003 | algorithm param is invalid. |
| 12000004 | operating file failed. |
| 12000005 | IPC communication failed. |
| 12000006 | error occurred in crypto engine. |
| 12000011 | queried entity does not exist. |
| 12000012 | external error. |
| 12000013 | queried credential does not exist. |
| 12000014 | memory is insufficient. |
| 12000015 | call service failed. |

**Example**

- Prerequisites: see **Example** of [generateKeyItemAsUser](#huksgeneratekeyitemasuser).

```ts
import { huks } from '@kit.UniversalKeystoreKit';
import { BusinessError } from "@kit.BasicServicesKit"

const aesKeyAlias = 'test_aesKeyAlias';
const userId = 100;
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
    console.info("Imported the key with the alias of: " + keyAlias + ".")
  }).catch((err: BusinessError) => {
    console.error("Failed to import the key. Error code: " + err.code + " Error message: " + err.message)
  })
}

export default function HuksAsUserTest() {
  console.info('begin huks as user test')
  ImportPlainKey(aesKeyAlias, GetAesGenerateProperties(), plainAesKey128)
}
```


## huks.attestKeyItemAsUser

attestKeyItemAsUser(userId: number, keyAlias: string, huksOptions: HuksOptions) : Promise\<HuksReturnResult>

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
| 201 | the application permission is not sufficient, which may be caused by lack of cross-account permission, or the system has not been unlocked by user, or the user does not exist. |
| 202 | non-system applications are not allowed to use system APIs. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |
| 801 | api is not supported. |
| 12000001 | algorithm mode is not supported. |
| 12000002 | algorithm param is missing. |
| 12000003 | algorithm param is invalid. |
| 12000004 | operating file failed. |
| 12000005 | IPC communication failed. |
| 12000006 | error occurred in crypto engine. |
| 12000011 | queried entity does not exist. |
| 12000012 | external error. |
| 12000014 | memory is insufficient. |

**Example**

- Prerequisites: see **Example** of [generateKeyItemAsUser](#huksgeneratekeyitemasuser).

```ts
import { huks } from '@kit.UniversalKeystoreKit';
import { BusinessError } from "@kit.BasicServicesKit"

function StringToUint8Array(str: string) {
  let arr: number[] = [];
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

const rsaKeyAlias = 'test_rsaKeyAlias';
const userId = 100;
const userIdStorageLevel = huks.HuksAuthStorageLevel.HUKS_AUTH_STORAGE_LEVEL_CE;

const securityLevel = StringToUint8Array('sec_level');
const challenge = StringToUint8Array('challenge_data');
const versionInfo = StringToUint8Array('version_info');

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
    console.info("Generated a key with alias of: " + keyAlias + "")
  }).catch((err: BusinessError) => {
    console.error("Failed to generate the key. Error code: " + err.code + " Error message: " + err.message)
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
  console.info ('start attestation')
  await huks.attestKeyItemAsUser(userId, keyAlias, attestOptions).then((data) => {
    console.info('attestation ok!')
    console.debug(`The obtained certificate chain is ${JSON.stringify(data)}`) // Debugging information. The certificate chain does not need to be printed during the service function development.
    for (let i = 0; data?.certChains?.length && i < data?.certChains?.length; ++i) {
      console.debug(`Certificate ${i} is ${data.certChains[i]}`) // Debugging information. The certificate chain does not need to be printed during the service function development.
    }
    console.info ("attest successful")
  }).catch((err: BusinessError) => {
    console.error("Attestation failed. Error code: " + err.code +" Error message: "+ err.message)
  })
}

async function TestHuksAttest() {
  await GenerateKey(rsaKeyAlias, GetRSA4096GenerateProperties())
  await LetKeyAttest(rsaKeyAlias, GetAttestKeyProperties(rsaKeyAlias))
}

export default function HuksAsUserTest() {
  console.info('begin huks as user test')
  TestHuksAttest()
}
```

## huks.anonAttestKeyItemAsUser

anonAttestKeyItemAsUser(userId: number, keyAlias: string, huksOptions: HuksOptions) : Promise\<HuksReturnResult>

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
| 201 | the application permission is not sufficient, which may be caused by lack of cross-account permission, or the system has not been unlocked by user, or the user does not exist. |
| 202 | non-system applications are not allowed to use system APIs. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |
| 801 | api is not supported. |
| 12000001 | algorithm mode is not supported. |
| 12000002 | algorithm param is missing. |
| 12000003 | algorithm param is invalid. |
| 12000004 | operating file failed. |
| 12000005 | IPC communication failed. |
| 12000006 | error occurred in crypto engine. |
| 12000011 | queried entity does not exist. |
| 12000012 | external error. |
| 12000014 | memory is insufficient. |

**Example**

- Prerequisites: see **Example** of [generateKeyItemAsUser](#huksgeneratekeyitemasuser).

```ts
import { huks } from '@kit.UniversalKeystoreKit';
import { BusinessError } from "@kit.BasicServicesKit"

function StringToUint8Array(str: string) {
  let arr: number[] = [];
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

const rsaKeyAlias = 'test_rsaKeyAlias';
const userId = 100;
const userIdStorageLevel = huks.HuksAuthStorageLevel.HUKS_AUTH_STORAGE_LEVEL_CE;

const securityLevel = StringToUint8Array('sec_level');
const challenge = StringToUint8Array('challenge_data');
const versionInfo = StringToUint8Array('version_info');

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
    console.info("Generated a key with alias of: " + keyAlias + "")
  }).catch((err: BusinessError) => {
    console.error("Failed to generate the key. Error code: " + err.code + " Error message: " + err.message)
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
  console.info('Start anonymous attestation')
  await huks.anonAttestKeyItemAsUser(userId, keyAlias, attestOptions).then((data) => {
    console.info('Anonymous attestation ok!')
    console.debug(`The obtained certificate chain is ${JSON.stringify(data)}`)
    for (let i = 0; data?.certChains?.length && i < data?.certChains?.length; ++i) {
      console.info(`Certificate ${i} is ${data.certChains[i]}`)
    }
    console.info ("Anonymous attest successful")
  }).catch((err: BusinessError) => {
    console.error("Anonymous attestation failed. Error code: "+ err.code +" Error message: "+ err.message)
  })
}


async function TestHuksAnonAttest() {
  await GenerateKey(rsaKeyAlias, GetRSA4096GenerateProperties())
  await LetKeyAnonAttest(rsaKeyAlias, GetAttestKeyProperties(rsaKeyAlias))
}

export default function HuksAsUserTest() {
  console.info('begin huks as user test')
  TestHuksAnonAttest()
}
```

## huks.importWrappedKeyItemAsUser

importWrappedKeyItemAsUser(userId: number, keyAlias: string, wrappingKeyAlias: string, huksOptions: HuksOptions) : Promise\<void>

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
| 201 | the application permission is not sufficient, which may be caused by lack of cross-account permission, or the system has not been unlocked by user, or the user does not exist. |
| 202 | non-system applications are not allowed to use system APIs. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |
| 801 | api is not supported. |
| 12000001 | algorithm mode is not supported. |
| 12000002 | algorithm param is missing. |
| 12000003 | algorithm param is invalid. |
| 12000004 | operating file failed. |
| 12000005 | IPC communication failed. |
| 12000006 | error occurred in crypto engine. |
| 12000011 | queried entity does not exist. |
| 12000012 | external error. |
| 12000013 | queried credential does not exist. |
| 12000014 | memory is insufficient. |
| 12000015 | call service failed. |

**Example**

- Prerequisites: see **Example** of [generateKeyItemAsUser](#huksgeneratekeyitemasuser).
- The values of the following cryptography-related variables (such as **initializationVector**, **associatedData**, and **nonce**) are for reference only and cannot be directly used in the service logic. You need to set them based on actual situation.

```ts
import { huks } from '@kit.UniversalKeystoreKit';
import { BusinessError } from "@kit.BasicServicesKit"

const userIdStorageLevel = huks.HuksAuthStorageLevel.HUKS_AUTH_STORAGE_LEVEL_CE;
const initializationVector = '0000000000000000';
const associatedData = "abababababababab";
const nonce = "hahahahahaha";
const tagSize = 16;
const unsignedInt32Bytes = 4;
const importedAes192PlainKey = "The aes192 key to import";
const callerAes256Kek = "The is kek to encrypt aes192 key";
const callerKeyAlias = "test_caller_key_ecdh_aes192";
const callerKekAliasAes256 = "test_caller_kek_ecdh_aes256";
const callerAgreeKeyAliasAes256 = "test_caller_agree_key_ecdh_aes256";
const importedKeyAliasAes192 = "test_import_key_ecdh_aes192";
const mask = [0x000000FF, 0x0000FF00, 0x00FF0000, 0xFF000000];


function StringToUint8Array(str: string) {
  let arr: number[] = [];
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

function SubUint8ArrayOf(arrayBuf: Uint8Array, start: number, end: number) {
  let arr: Array<number> = [];
  for (let i = start; i < end && i < arrayBuf.length; ++i) {
    arr.push(arrayBuf[i]);
  }
  return new Uint8Array(arr);
}

function AssignLength(length: number, arrayBuf: Uint8Array, startIndex: number) {
  let index = startIndex;
  for (let i = 0; i < 4; i++) {
    arrayBuf[index++] = (length & mask[i]) >> (i * 8);
  }
  return 4;
}

function AssignData(data: Uint8Array, arrayBuf: Uint8Array, startIndex: number) {
  let index = startIndex;
  for (let i = 0; i < data.length; i++) {
    arrayBuf[index++] = data[i];
  }
  return data.length;
}

const genWrappingKeyParams: huks.HuksOptions = {
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

const genCallerEcdhParams: huks.HuksOptions = {
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

const importParamsCallerKek: huks.HuksOptions = {
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
      value: StringToUint8Array(initializationVector)
    },
    {
      tag: huks.HuksTag.HUKS_TAG_AUTH_STORAGE_LEVEL,
      value: userIdStorageLevel,
    }
  ],
  inData: StringToUint8Array(callerAes256Kek)
}

const importParamsAgreeKey: huks.HuksOptions = {
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
      value: StringToUint8Array(initializationVector)
    },
    {
      tag: huks.HuksTag.HUKS_TAG_AUTH_STORAGE_LEVEL,
      value: userIdStorageLevel,
    }
  ]
}

const callerAgreeParams: huks.HuksOptions = {
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

const encryptKeyCommonParams: huks.HuksOptions = {
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
      value: StringToUint8Array(nonce)
    },
    {
      tag: huks.HuksTag.HUKS_TAG_ASSOCIATED_DATA,
      value: StringToUint8Array(associatedData)
    },
    {
      tag: huks.HuksTag.HUKS_TAG_AUTH_STORAGE_LEVEL,
      value: userIdStorageLevel,
    }
  ]
}

const importWrappedAes192Params: huks.HuksOptions = {
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
      value: StringToUint8Array(initializationVector)
    },
    {
      tag: huks.HuksTag.HUKS_TAG_AUTH_STORAGE_LEVEL,
      value: userIdStorageLevel,
    }
  ]
}

async function PublicImportKeyItemFunc(
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

async function PublicDeleteKeyItemFunc(
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

async function PublicImportWrappedKeyFunc(
  userId: number,
  keyAlias: string, wrappingKeyAlias: string, huksOptions: huks.HuksOptions) {
  console.info(`enter callback importWrappedKeyItemAsUser`);
  console.info(`publicImportWrappedKeyFunc huksOptions = ${JSON.stringify(huksOptions)}`);
  try {
    await huks.importWrappedKeyItemAsUser(userId, keyAlias, wrappingKeyAlias, huksOptions)
      .then((data) => {
        console.info(`callback: importWrappedKeyItemAsUser success, data = ${JSON.stringify(data)}`);
        console.info (`importWrappedKeyItemAsUser successful. data = ${JSON.stringify(data)}`)
      })
      .catch((err: BusinessError) => {
        console.error(`callback: importWrappedKeyItemAsUser failed, code: ${err.code}, msg: ${err.message}`);
      });
  } catch (error) {
    console.error(`callback: importWrappedKeyItemAsUser input arg invalid, code: ${error.code}, msg: ${error.message}`);
  }
}

async function PublicInitFunc(
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

async function PublicUpdateSessionFunction(handle: number, huksOptions: huks.HuksOptions) {
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
      console.info(`enter promise doUpdate`);
      break;
    }
    huksOptions.inData = new Uint8Array(
      Array.from(inData).slice(inDataSegPosition, inDataSegPosition + inDataSegSize)
    );
    console.info(`enter promise doUpdate`);
    try {
      await huks.updateSession(handle, huksOptions)
        .then((data) => {
          console.info(`promise: doUpdate success, data = ${JSON.stringify(data)}`);
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
      console.error(`update size invalid isFinished = ${isFinished}`);
      console.error(`inDataSegPosition = ${inDataSegPosition}`);
      console.error(`lastInDataPosition = ${lastInDataPosition}`);
      return [];
    }
    inDataSegPosition += maxUpdateSize;
  }
  return outData;
}

async function PublicFinishSession(handle: number, huksOptions: huks.HuksOptions, inData: Array<number>) {
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

async function CipherFunction(
  userId: number,
  keyAlias: string, huksOptions: huks.HuksOptions) {
  const handle = await PublicInitFunc(userId, keyAlias, huksOptions);
  const tmpData = await PublicUpdateSessionFunction(handle, huksOptions);
  const outData = await PublicFinishSession(handle, huksOptions, tmpData);
  return outData;
}

async function AgreeFunction(
  userId: number,
  keyAlias: string, huksOptions: huks.HuksOptions, huksPublicKey: Uint8Array) {
  const handle = await PublicInitFunc(userId, keyAlias, huksOptions);
  let outSharedKey: Uint8Array = new Uint8Array;
  huksOptions.inData = huksPublicKey;
  console.info(`enter promise doUpdate`);
  try {
    await huks.updateSession(handle, huksOptions)
      .then((data) => {
        console.info(`promise: doUpdate success, data = ${JSON.stringify(data)}`);
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
  callerKekAlias: string, importKekParams: huks.HuksOptions,
  callerKeyAlias: string, huksPublicKey: Uint8Array, agreeParams: huks.HuksOptions) {
  await PublicImportKeyItemFunc(userId, callerKekAlias, importKekParams);

  importParamsAgreeKey.inData = await AgreeFunction(userId, callerKeyAlias, agreeParams, huksPublicKey);

  await PublicImportKeyItemFunc(userId, callerAgreeKeyAliasAes256, importParamsAgreeKey);
}

async function GenerateAndExportPublicKey(
  userId: number,
  keyAlias: string, huksOptions: huks.HuksOptions): Promise<Uint8Array> {
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


  let result = new Uint8Array([])
  try {
    await huks.exportKeyItemAsUser(userId, keyAlias, huksOptions)
      .then((data) => {
        console.info(`promise: exportKeyItemAsUser success, data = ${JSON.stringify(data)}`);
        if (data.outData == undefined) {
          console.error('data.outData is undefined');
          return;
        }
        result = data.outData;
      })
      .catch((err: BusinessError) => {
        console.error(`promise: exportKeyItemAsUser failed, code: ${err.code}, msg: ${err.message}`);
      });
  } catch (e) {
    console.error(`promise: generate pubKey failed, code: ${e.code}, msg: ${e.message}`);
  }
  return result
}

interface KeyEncAndKekEnc {
  outPlainKeyEncData: Uint8Array,
  outKekEncData: Uint8Array,
  outKekEncTag: Uint8Array,
  outAgreeKeyEncTag: Uint8Array,
}

async function EncryptImportedPlainKeyAndKek(
  userId: number,
  keyAlias: string): Promise<KeyEncAndKekEnc> {
  encryptKeyCommonParams.inData = StringToUint8Array(keyAlias)
  const plainKeyEncData = await CipherFunction(userId, callerKekAliasAes256, encryptKeyCommonParams);
  const result: KeyEncAndKekEnc = {
    outPlainKeyEncData: new Uint8Array([]),
    outKekEncData: new Uint8Array([]),
    outKekEncTag: new Uint8Array([]),
    outAgreeKeyEncTag: new Uint8Array([]),
  }
  result.outKekEncTag = SubUint8ArrayOf(plainKeyEncData, plainKeyEncData.length - tagSize, plainKeyEncData.length)
  result.outPlainKeyEncData = SubUint8ArrayOf(plainKeyEncData, 0, plainKeyEncData.length - tagSize)

  encryptKeyCommonParams.inData = StringToUint8Array(callerAes256Kek)
  const kekEncData = await CipherFunction(userId, callerAgreeKeyAliasAes256, encryptKeyCommonParams)
  result.outAgreeKeyEncTag = SubUint8ArrayOf(kekEncData, kekEncData.length - tagSize, kekEncData.length)
  result.outKekEncData = SubUint8ArrayOf(kekEncData, 0, kekEncData.length - tagSize)

  return result
}

async function BuildWrappedDataAndImportWrappedKey(plainKey: string, huksPubKey: Uint8Array, callerSelfPublicKey: Uint8Array, encData: KeyEncAndKekEnc) {
  const plainKeySizeBuff = new Uint8Array(4);
  AssignLength(plainKey.length, plainKeySizeBuff, 0);

  const wrappedData = new Uint8Array(
    unsignedInt32Bytes + huksPubKey.length +
      unsignedInt32Bytes + associatedData.length +
      unsignedInt32Bytes + nonce.length +
      unsignedInt32Bytes + tagSize +
      unsignedInt32Bytes + encData.outKekEncData.length +
      unsignedInt32Bytes + associatedData.length +
      unsignedInt32Bytes + nonce.length +
      unsignedInt32Bytes + tagSize +
      unsignedInt32Bytes + plainKeySizeBuff.length +
      unsignedInt32Bytes + encData.outPlainKeyEncData.length
  );
  let index = 0;
  const associatedDataArray = StringToUint8Array(associatedData);
  const nonceArray = StringToUint8Array(nonce);

  index += AssignLength(callerSelfPublicKey.length, wrappedData, index); // 4
  index += AssignData(callerSelfPublicKey, wrappedData, index); // 91
  index += AssignLength(associatedDataArray.length, wrappedData, index); // 4
  index += AssignData(associatedDataArray, wrappedData, index); // 16
  index += AssignLength(nonceArray.length, wrappedData, index); // 4
  index += AssignData(nonceArray, wrappedData, index); // 12
  index += AssignLength(encData.outAgreeKeyEncTag.length, wrappedData, index); // 4
  index += AssignData(encData.outAgreeKeyEncTag, wrappedData, index); // 16
  index += AssignLength(encData.outKekEncData.length, wrappedData, index); // 4
  index += AssignData(encData.outKekEncData, wrappedData, index); // 32
  index += AssignLength(associatedDataArray.length, wrappedData, index); // 4
  index += AssignData(associatedDataArray, wrappedData, index); // 16
  index += AssignLength(nonceArray.length, wrappedData, index); // 4
  index += AssignData(nonceArray, wrappedData, index); // 12
  index += AssignLength(encData.outKekEncTag.length, wrappedData, index); // 4
  index += AssignData(encData.outKekEncTag, wrappedData, index); // 16
  index += AssignLength(plainKeySizeBuff.length, wrappedData, index); // 4
  index += AssignData(plainKeySizeBuff, wrappedData, index); // 4
  index += AssignLength(encData.outPlainKeyEncData.length, wrappedData, index); // 4
  index += AssignData(encData.outPlainKeyEncData, wrappedData, index); // 24

  return wrappedData;
}

export async function HuksSecurityImportTest(userId: number) {
  const srcKeyAliasWrap = 'HUKS_Basic_Capability_Import_0200';
  const huksPubKey: Uint8Array = await GenerateAndExportPublicKey(userId, srcKeyAliasWrap, genWrappingKeyParams);
  const callerSelfPublicKey: Uint8Array = await GenerateAndExportPublicKey(userId, callerKeyAlias, genCallerEcdhParams);

  await ImportKekAndAgreeSharedSecret(
    userId,
    callerKekAliasAes256, importParamsCallerKek, callerKeyAlias, huksPubKey, callerAgreeParams);
  const encData: KeyEncAndKekEnc = await EncryptImportedPlainKeyAndKek(userId, importedAes192PlainKey);
  const wrappedData = await BuildWrappedDataAndImportWrappedKey(importedAes192PlainKey, huksPubKey, callerSelfPublicKey, encData);
  importWrappedAes192Params.inData = wrappedData;
  await PublicImportWrappedKeyFunc(userId,
    importedKeyAliasAes192, srcKeyAliasWrap, importWrappedAes192Params);
  await PublicDeleteKeyItemFunc(userId, srcKeyAliasWrap, genWrappingKeyParams);
  await PublicDeleteKeyItemFunc(userId, callerKeyAlias, genCallerEcdhParams);
  await PublicDeleteKeyItemFunc(userId, importedKeyAliasAes192, importWrappedAes192Params);
  await PublicDeleteKeyItemFunc(userId, callerKekAliasAes256, callerAgreeParams);
}

export default function HuksAsUserTest() {
  console.info('begin huks as user test')

  const userId = 100;
  HuksSecurityImportTest(userId)
}
```

## huks.exportKeyItemAsUser

exportKeyItemAsUser(userId: number, keyAlias: string, huksOptions: HuksOptions) : Promise\<HuksReturnResult>

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
| 201 | the application permission is not sufficient, which may be caused by lack of cross-account permission, or the system has not been unlocked by user, or the user does not exist. |
| 202 | non-system applications are not allowed to use system APIs. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |
| 801 | api is not supported. |
| 12000001 | algorithm mode is not supported. |
| 12000002 | algorithm param is missing. |
| 12000003 | algorithm param is invalid. |
| 12000004 | operating file failed. |
| 12000005 | IPC communication failed. |
| 12000006 | error occurred in crypto engine. |
| 12000011 | queried entity does not exist. |
| 12000012 | external error. |
| 12000014 | memory is insufficient. |

**Example**

- Prerequisites: see **Example** of [generateKeyItemAsUser](#huksgeneratekeyitemasuser).

```ts
import { huks } from '@kit.UniversalKeystoreKit';
import { BusinessError } from "@kit.BasicServicesKit"

const rsaKeyAlias = 'test_rsaKeyAlias';
const userId = 100;
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
    console.info("Generated a key with alias of: " + keyAlias + "")
  }).catch((err: BusinessError) => {
    console.error("Failed to generate the key. Error code: " + err.code + " Error message: " + err.message)
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
    console.info("Exported the public key with the alias of: " + keyAlias + ". The data length is" + data?.outData?.length)
  }).catch((err: BusinessError) => {
    console.error("Failed to export the key. Error code: " + err.code + " Error message: " + err.message)
  })
}

async function ExportHuksTest() {
  await GenerateKey(rsaKeyAlias, GetRSA4096GenerateProperties())
  await ExportPublicKey(rsaKeyAlias)
}

export default function HuksAsUserTest() {
  console.info('begin huks as user test')
  ExportHuksTest()
}
```

## huks.getKeyItemPropertiesAsUser

getKeyItemPropertiesAsUser(userId: number, keyAlias: string, huksOptions: HuksOptions) : Promise\<HuksReturnResult>

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
| 201 | the application permission is not sufficient, which may be caused by lack of cross-account permission, or the system has not been unlocked by user, or the user does not exist. |
| 202 | non-system applications are not allowed to use system APIs. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |
| 801 | api is not supported. |
| 12000001 | algorithm mode is not supported. |
| 12000002 | algorithm param is missing. |
| 12000003 | algorithm param is invalid. |
| 12000004 | operating file failed. |
| 12000005 | IPC communication failed. |
| 12000006 | error occurred in crypto engine. |
| 12000011 | queried entity does not exist. |
| 12000012 | external error. |
| 12000014 | memory is insufficient. |

**Example**

- Prerequisites: see **Example** of [generateKeyItemAsUser](#huksgeneratekeyitemasuser).

```ts
import { huks } from '@kit.UniversalKeystoreKit';
import { BusinessError } from "@kit.BasicServicesKit"

const aesKeyAlias = 'test_aesKeyAlias';
const userId = 100;
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
    console.info("Generated a key with alias of: " + keyAlias + "")
  }).catch((err: BusinessError) => {
    console.error("Failed to generate the key. Error code: " + err.code + " Error message: " + err.message)
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
    console.info("Obtained key properties: " + JSON.stringify(data))
  }).catch((err: BusinessError) => {
    console.error("Failed to obtain key properties. Error code: " + err.code + " Error message: " + err.message)
  })
}

async function TestHuksGet() {
  await GenerateKey(aesKeyAlias, GetAesGenerateProperties())
  await GetKeyProperties(aesKeyAlias)
}

export default function HuksAsUserTest() {
  console.info('begin huks as user test')
  TestHuksGet()
}
```

## huks.hasKeyItemAsUser

hasKeyItemAsUser(userId: number, keyAlias: string, huksOptions: HuksOptions) : Promise\<boolean>

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
| 201 | the application permission is not sufficient, which may be caused by lack of cross-account permission, or the system has not been unlocked by user, or the user does not exist. |
| 202 | non-system applications are not allowed to use system APIs. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |
| 801 | api is not supported. |
| 12000002 | algorithm param is missing. |
| 12000003 | algorithm param is invalid. |
| 12000004 | operating file failed. |
| 12000005 | IPC communication failed. |
| 12000006 | error occurred in crypto engine. |
| 12000012 | external error. |
| 12000014 | memory is insufficient. |

**Example**

- Prerequisites: see **Example** of [generateKeyItemAsUser](#huksgeneratekeyitemasuser).

```ts
import { huks } from '@kit.UniversalKeystoreKit';
import { BusinessError } from "@kit.BasicServicesKit"
const aesKeyAlias = 'test_aesKeyAlias';
const userId = 100;
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
    console.info("Generated a key with alias of: " + keyAlias + "")
  }).catch((err: BusinessError) => {
    console.error("Failed to generate the key. Error code: " + err.code + " Error message: " + err.message)
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
    console.info("Check result of the key with the alias of "+ keyAlias +" " + JSON.stringify(data))
  }).catch((err: BusinessError) => {
    console.error("Failed to delete the key. Error code: " + err.code + " Error message: " + err.message)
  })
}

async function TestHuksHasKey() {
  await GenerateKey(aesKeyAlias, GetAesGenerateProperties())
  await HasKey(aesKeyAlias)
}

export default function HuksAsUserTest() {
  console.info('begin huks as user test')
  TestHuksHasKey()
}
```

## huks.initSessionAsUser

initSessionAsUser(userId: number, keyAlias: string, huksOptions: HuksOptions) : Promise\<HuksSessionHandle>

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
| 201 | the application permission is not sufficient, which may be caused by lack of cross-account permission, or the system has not been unlocked by user, or the user does not exist. |
| 202 | non-system applications are not allowed to use system APIs. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |
| 801 | api is not supported. |
| 12000001 | algorithm mode is not supported. |
| 12000002 | algorithm param is missing. |
| 12000003 | algorithm param is invalid. |
| 12000004 | operating file failed. |
| 12000005 | IPC communication failed. |
| 12000006 | error occurred in crypto engine. |
| 12000010 | the number of sessions has reached limit. |
| 12000011 | queried entity does not exist. |
| 12000012 | external error. |
| 12000014 | memory is insufficient. |

**Example**

- Prerequisites: see **Example** of [generateKeyItemAsUser](#huksgeneratekeyitemasuser).
- The values of the following cryptography-related variables (such as **initializationVector**) are for reference only and cannot be directly used in the service logic. You need to set them based on actual situation.

```ts
import { huks } from '@kit.UniversalKeystoreKit';
import { BusinessError } from "@kit.BasicServicesKit"

const aesKeyAlias = 'test_aesKeyAlias';
const userId = 100;
const userIdStorageLevel = huks.HuksAuthStorageLevel.HUKS_AUTH_STORAGE_LEVEL_CE;
const initializationVector = '001122334455';
const plainText = '123456789';

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
    value: StringToUint8Array(initializationVector)
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
    value: StringToUint8Array(initializationVector)
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
    console.info("Generated a key with alias of: " + keyAlias + "")
  }).catch((err: BusinessError) => {
    console.error("Failed to generate the key. Error code: " + err.code + " Error message: " + err.message)
  })
}

async function EncryptData(keyAlias: string, encryptProperties: Array<huks.HuksParam>): Promise<Uint8Array> {
  const options: huks.HuksOptions = {
    properties: encryptProperties,
    inData: StringToUint8Array(plainText)
  }
  let handle: number = 0;
  let cipherData: Uint8Array = new Uint8Array([]);
  await huks.initSessionAsUser(userId, keyAlias, options).then((data) => {
    handle = data.handle;
  }).catch((err: BusinessError) => {
    console.error("Failed to initialize the key session. Error code: "+ err.code +" Error message: "+ err.message)
  })
  await huks.finishSession(handle, options).then((data) => {
    console.info("Data is encrypted. Ciphertext: " + Uint8ArrayToString(data.outData))
    if (data.outData != undefined) {
      cipherData = data.outData
    }
    console.info("running time result success!")
  }).catch((err: BusinessError) => {
    console.error("An exception is captured in the encryption process. Error code: " + err.code +" Error message: "+ err.message)
  })
  return cipherData
}

async function DecryptData(keyAlias: string, decryptProperties: Array<huks.HuksParam>, cipherData: Uint8Array) {
  const options: huks.HuksOptions = {
    properties: decryptProperties,
    inData: cipherData
  }
  let handle: number = 0;
  await huks.initSessionAsUser(userId, keyAlias, options).then((data) => {
    handle = data.handle;
  }).catch((err: BusinessError) => {
    console.error("Failed to initialize the key session. Error code: "+ err.code +" Error message: "+ err.message)
  })
  await huks.finishSession(handle, options).then((data) => {
    console.info("Data is decrypted. Plaintext: " + Uint8ArrayToString(data.outData))
  }).catch((err: BusinessError) => {
    console.error("An exception is captured in the decryption process. Error code: " + err.code +" Error message: "+ err.message)
  })
}

async function TestHuksInit() {
  await GenerateKey(aesKeyAlias, GetAesGenerateProperties())
  let cipherData: Uint8Array = await EncryptData(aesKeyAlias, GetAesEncryptProperties())
  await DecryptData(aesKeyAlias, GetAesDecryptProperties(), cipherData)
}

export default function HuksAsUserTest() {
  console.info('begin huks as user test')
  TestHuksInit()
}
```
