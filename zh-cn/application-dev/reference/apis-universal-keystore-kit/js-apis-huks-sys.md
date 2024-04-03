# @ohos.security.huks (通用密钥库系统)(系统接口)

向应用提供密钥库能力，应用可调用接口，指定用户身份操作密钥。

> **说明：**
> - 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.security.huks (通用密钥库系统)](js-apis-huks.md)。

## 导入模块

```ts
import huks from '@ohos.security.huks'
```

## huks.generateKeyItemAsUser<sup>12+</sup>

generateKeyItemAsUser(userId: number, keyAlias: string, options: HuksOptions) : Promise\<void>

指定用户身份生成密钥，使用Promise方式异步返回结果。基于密钥不出TEE原则，通过promise不会返回密钥材料内容，只用于表示此次调用是否成功。

**需要权限** ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力**：SystemCapability.Security.Huks.Extension

**参数：**

| 参数名   | 类型                        | 必填 | 说明                     |
| -------- | --------------------------- | ---- | ------------------------ |
| userId   | number                      | 是   | 用户ID。                 |
| keyAlias | string                      | 是   | 密钥别名。               |
| options  | [HuksOptions](js-apis-huks.md#huksoptions) | 是   | 用于存放生成key所需TAG。其中密钥使用的算法、密钥用途、密钥长度为必选参数。 |

**错误码：**

以下错误码的详细介绍请参见[HUKS错误码](errorcode-huks.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
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

**示例：**

- 以下代码示例接口调用的前置条件：
  
  在设备中，依次打开系统“设置 > 用户和账户 > 当前登录 > 添加用户”，输入用户名并点击“添加”，待添加成功后点击“切换”按钮切换到新用户，进入桌面。

   此时通过`hdc shell acm dump -a`命令可以查看到刚刚创建的新用户的用户id为101，下文中代码示例均指定userId为101，存储等级为CE。

   > **说明：**
   > CE区会在对应用户开机第一次解锁后解锁，若重启后直接进入主用户空间，尚未切换过用户，101号用户空间为锁定状态，此时通过huks使用密钥会访问失败。需要切换到该用户解锁进入桌面后即可使用。

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
      message: "成功生成了一个别名为：" + keyAlias + " 的密钥",
      duration: 2500,
    })
  }).catch((err: BusinessError) => {
    promptAction.showToast({
      message: "密钥生成失败，错误码是： " + err.code + " 错误吗信息： " + err.message,
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

指定用户身份删除密钥，使用Promise方式异步返回结果。

**需要权限** ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力**：SystemCapability.Security.Huks.Extension

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                |
| -------- | --------------------------- | ---- | ----------------------------------- |
| userId   | number                      | 是   | 用户ID。                 |
| keyAlias | string                      | 是   | 密钥别名，应为生成key时传入的别名。 |
| options  | [HuksOptions](js-apis-huks.md#huksoptions) | 是   | 用于删除时指定密钥的属性TAG，如使用[HuksAuthStorageLevel](js-apis-huks.md#huksauthstoragelevel11)指定需删除密钥的安全级别，可传空，传空时默认DE。            |

**错误码：**

以下错误码的详细介绍请参见[HUKS错误码](errorcode-huks.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 401 | argument is invalid. |
| 801 | api is not supported. |
| 12000004 | operating file failed. |
| 12000005 | IPC communication failed. |
| 12000011 | queried entity does not exist. |
| 12000012 | external error. |
| 12000014 | memory is insufficient. |

**示例：**

- 以下代码示例接口调用的前置条件同上文[generateKeyItemAsUser](#huksgeneratekeyitemasuser12)的前置条件

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
      message: "密钥生成失败，错误码是： " + err.code + " 错误吗信息： " + err.message,
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
      message: "别名为: " + keyAlias + " 密钥删除成功！",
      duration: 6500,
    })
  }).catch((err: BusinessError) => {
    promptAction.showToast({
      message: "密钥删除失败，错误码是： " + err.code + " 错误吗信息： " + err.message,
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

指定用户身份导入明文密钥，使用Promise方式异步返回结果。

**需要权限** ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力**：SystemCapability.Security.Huks.Extension

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                |
| -------- | --------------------------- | ---- | ----------------------------------- |
| userId   | number                      | 是   | 用户ID。                 |
| keyAlias | string                      | 是   | 密钥别名。                          |
| options  | [HuksOptions](js-apis-huks.md#huksoptions) | 是   | 用于导入时所需TAG和需要导入的密钥。其中密钥使用的算法、密钥用途、密钥长度为必选参数。 |

**错误码：**

以下错误码的详细介绍请参见[HUKS错误码](errorcode-huks.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
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

**示例：**

- 以下代码示例接口调用的前置条件同上文[generateKeyItemAsUser](#huksgeneratekeyitemasuser12)的前置条件

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
      message: "成功导入了一个别名为：" + keyAlias + " 的密钥",
      duration: 2500,
    })
  }).catch((err: BusinessError) => {
    promptAction.showToast({
      message: "密钥导入失败，错误码是： " + err.code + " 错误吗信息： " + err.message,
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

指定用户身份获取密钥证书，使用Promise方式异步返回结果 。

**需要权限**：ohos.permission.ATTEST_KEY, ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS 必须同时拥有两个权限。

**系统能力**：SystemCapability.Security.Huks.Extension

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                 |
| -------- | --------------------------- | ---- | ------------------------------------ |
| userId   | number                      | 是   | 用户ID。                 |
| keyAlias | string                      | 是   | 密钥别名，存放待获取证书密钥的别名。 |
| options  | [HuksOptions](js-apis-huks.md#huksoptions) | 是   | 用于获取证书时指定所需参数与数据。   |

**返回值：**

| 类型                                           | 说明                                          |
| ---------------------------------------------- | --------------------------------------------- |
| Promise<[HuksReturnResult](js-apis-huks.md#huksreturnresult9)> | Promise对象。不返回err值时表示接口使用成功，其他时为错误。 |

**错误码：**

以下错误码的详细介绍请参见[HUKS错误码](errorcode-huks.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 201 | check permission failed. |
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

**示例：**

- 以下代码示例接口调用的前置条件同上文[generateKeyItemAsUser](#huksgeneratekeyitemasuser12)的前置条件

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
      message: "成功生成了一个别名为：" + keyAlias + " 的密钥",
      duration: 2500,
    })
  }).catch((err: BusinessError) => {
    promptAction.showToast({
      message: "密钥生成失败，错误码是： " + err.code + " 错误吗信息： " + err.message,
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
  console.log('开始attest')
  await huks.attestKeyItemAsUser(userId, keyAlias, attestOptions).then((data) => {
    console.log('attestation ok!')
    console.log(`拿到的证书链是${JSON.stringify(data)}`)
    for (let i = 0; data?.certChains?.length && i < data?.certChains?.length; ++i) {
      console.log(`证书${i}是${data.certChains[i]}`)
    }
    promptAction.showToast({
      message: "attest 成功",
      duration: 3000,
    })
  }).catch((err: BusinessError) => {
    promptAction.showToast({
      message: "attest 失败，错误码是： " + err.code + " 错误吗信息： " + err.message,
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

指定用户身份获取匿名化密钥证书，使用Promise方式异步返回结果。

该操作需要联网进行，且耗时较长。

**需要权限** ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力**：SystemCapability.Security.Huks.Extension

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                 |
| -------- | --------------------------- | ---- | ------------------------------------ |
| userId   | number                      | 是   | 用户ID。                 |
| keyAlias | string                      | 是   | 密钥别名，存放待获取证书密钥的别名。 |
| options  | [HuksOptions](js-apis-huks.md#huksoptions) | 是   | 用于获取证书时指定所需参数与数据。   |

**返回值：**

| 类型                                           | 说明                                          |
| ---------------------------------------------- | --------------------------------------------- |
| Promise<[HuksReturnResult](js-apis-huks.md#huksreturnresult9)> | Promise对象。不返回err值时表示接口使用成功，其他时为错误。 |

**错误码：**

以下错误码的详细介绍请参见[HUKS错误码](errorcode-huks.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
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

**示例：**

- 以下代码示例接口调用的前置条件同上文[generateKeyItemAsUser](#huksgeneratekeyitemasuser12)的前置条件

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
      message: "成功生成了一个别名为：" + keyAlias + " 的密钥",
      duration: 2500,
    })
  }).catch((err: BusinessError) => {
    promptAction.showToast({
      message: "密钥生成失败，错误码是： " + err.code + " 错误吗信息： " + err.message,
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
  console.log('开始匿名attest')
  await huks.anonAttestKeyItemAsUser(userId, keyAlias, attestOptions).then((data) => {
    console.log('匿名attestation ok!')
    console.log(`拿到的证书链是${JSON.stringify(data)}`)
    for (let i = 0; data?.certChains?.length && i < data?.certChains?.length; ++i) {
      console.log(`证书${i}是${data.certChains[i]}`)
    }
    promptAction.showToast({
      message: "匿名 attest 成功",
      duration: 3000,
    })
  }).catch((err: BusinessError) => {
    promptAction.showToast({
      message: "匿名 attest 失败，错误码是： " + err.code + " 错误吗信息： " + err.message,
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

指定用户身份导入加密密钥，使用Promise方式异步返回结果。

**需要权限** ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力**：SystemCapability.Security.Huks.Extension

**参数：**

| 参数名           | 类型                        | 必填 | 说明                                          |
| ---------------- | --------------------------- | ---- | --------------------------------------------- |
| userId   | number                      | 是   | 用户ID。                 |
| keyAlias         | string                      | 是   | 密钥别名，存放待导入密钥的别名。              |
| wrappingKeyAlias | string                      | 是   | 密钥别名，对应密钥用于解密加密的密钥数据。    |
| options          | [HuksOptions](js-apis-huks.md#huksoptions) | 是   | 用于导入时所需TAG和需要导入的加密的密钥数据。其中密钥使用的算法、密钥用途、密钥长度为必选参数。 |

**错误码：**

以下错误码的详细介绍请参见[HUKS错误码](errorcode-huks.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
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

**示例：**

- 以下代码示例接口调用的前置条件同上文[generateKeyItemAsUser](#huksgeneratekeyitemasuser12)的前置条件
- 注意：下文包括但不限于IV、AAD、NONCE、importedAes192PlainKey等变量的赋值，均为样例代码所用，不能直接使用于密码学相关生产环境，用户需自行查阅密码学相关知识使用合适的初始化方式。相关变量的内容长度和样例所使用的密码学算法相关，如需更改初始化值的内容长度时，请注意需配套修改样例代码后续使用的密码学算法。

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
          message: `importWrappedKeyItemAsUser 成功 data = ${JSON.stringify(data)}`,
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

指定用户身份导出密钥，使用Promise方式回调异步返回的结果。

**需要权限** ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力**：SystemCapability.Security.Huks.Extension

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                         |
| -------- | --------------------------- | ---- | -------------------------------------------- |
| userId   | number                      | 是   | 用户ID。                 |
| keyAlias | string                      | 是   | 密钥别名，应与所用密钥生成时使用的别名相同。 |
| options  | [HuksOptions](js-apis-huks.md#huksoptions) | 是   | 空对象（此处传空即可）。                     |

**返回值：**

| 类型                                           | 说明                                                         |
| ---------------------------------------------- | ------------------------------------------------------------ |
| Promise<[HuksReturnResult](js-apis-huks.md#huksreturnresult9)> | Promise对象。不返回err值时表示接口使用成功，其他时为错误。outData：返回从密钥中导出的公钥。 |

**错误码：**

以下错误码的详细介绍请参见[HUKS错误码](errorcode-huks.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
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

**示例：**

- 以下代码示例接口调用的前置条件同上文[generateKeyItemAsUser](#huksgeneratekeyitemasuser12)的前置条件

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
      message: "成功生成了一个别名为：" + keyAlias + " 的密钥",
      duration: 2500,
    })
  }).catch((err: BusinessError) => {
    promptAction.showToast({
      message: "密钥生成失败，错误码是： " + err.code + " 错误吗信息： " + err.message,
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
      message: "成功将别名为：" + keyAlias + " 的公钥导出, data 的长度为" + data?.outData?.length,
      duration: 2500,
    })
  }).catch((err: BusinessError) => {
    promptAction.showToast({
      message: "密钥导出失败，错误码是： " + err.code + " 错误吗信息： " + err.message,
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

指定用户身份获取密钥属性，使用Promise回调异步返回结果。

**需要权限** ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力**：SystemCapability.Security.Huks.Extension

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                         |
| -------- | --------------------------- | ---- | -------------------------------------------- |
| userId   | number                      | 是   | 用户ID。                 |
| keyAlias | string                      | 是   | 密钥别名，应与所用密钥生成时使用的别名相同。 |
| options  | [HuksOptions](js-apis-huks.md#huksoptions) | 是   | 空对象（此处传空即可）。                     |

**返回值：**

| 类型                                            | 说明                                                         |
| ----------------------------------------------- | ------------------------------------------------------------ |
| Promise\<[HuksReturnResult](js-apis-huks.md#huksreturnresult9)> | Promise对象。不返回err值时表示接口使用成功，其他时为错误。properties：返回值为生成密钥时所需参数。 |

**错误码：**

以下错误码的详细介绍请参见[HUKS错误码](errorcode-huks.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
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

**示例：**

- 以下代码示例接口调用的前置条件同上文[generateKeyItemAsUser](#huksgeneratekeyitemasuser12)的前置条件

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
      message: "成功生成了一个别名为：" + keyAlias + " 的密钥",
      duration: 2500,
    })
  }).catch((err: BusinessError) => {
    promptAction.showToast({
      message: "密钥生成失败，错误码是： " + err.code + " 错误吗信息： " + err.message,
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
      message: "获取密钥属性成功！属性为: " + JSON.stringify(data),
      duration: 6500,
    })
  }).catch((err: BusinessError) => {
    promptAction.showToast({
      message: "获取密钥属性失败，错误码是： " + err.code + " 错误吗信息： " + err.message,
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

指定用户身份判断密钥是否存在，使用Promise回调异步返回结果 。

**需要权限** ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力**：SystemCapability.Security.Huks.Extension

**参数：**

| 参数名   | 类型                        | 必填 | 说明                     |
| -------- | --------------------------- | ---- | ------------------------ |
| userId   | number                      | 是   | 用户ID。                 |
| keyAlias | string                      | 是   | 所需查找的密钥的别名。   |
| options  | [HuksOptions](js-apis-huks.md#huksoptions) | 是   | 用于查询时指定密钥的属性TAG，如使用[HuksAuthStorageLevel](js-apis-huks.md#huksauthstoragelevel11)指定需查询密钥的安全级别，可传空，传空时默认DE。     |

**返回值：**

| 类型              | 说明                                    |
| ----------------- | --------------------------------------- |
| Promise\<boolean> | Promise对象。若密钥存在，返回值为true，若密钥不存在，返回值为false。 |

**错误码：**

以下错误码的详细介绍请参见[HUKS错误码](errorcode-huks.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 401 | argument is invalid. |
| 801 | api is not supported. |
| 12000002 | algorithm param is missing. |
| 12000003 | algorithm param is invalid. |
| 12000004 | operating file failed. |
| 12000005 | IPC communication failed. |
| 12000006 | error occured in crypto engine. |
| 12000012 | external error. |
| 12000014 | memory is insufficient. |

**示例：**

- 以下代码示例接口调用的前置条件同上文[generateKeyItemAsUser](#huksgeneratekeyitemasuser12)的前置条件

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
      message: "成功生成了一个别名为：" + keyAlias + " 的密钥",
      duration: 2500,
    })
  }).catch((err: BusinessError) => {
    promptAction.showToast({
      message: "密钥生成失败，错误码是： " + err.code + " 错误吗信息： " + err.message,
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
    console.log("别名为: " + keyAlias + "的密钥查询存在结果" + JSON.stringify(data))
  }).catch((err: BusinessError) => {
    promptAction.showToast({
      message: "密钥删除失败，错误码是： " + err.code + " 错误吗信息： " + err.message,
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

指定用户身份操作密钥接口，使用Promise方式异步返回结果。huks.initSessionAsUser, huks.updateSession, huks.finishSession为三段式接口，需要一起使用。

**需要权限** ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力**：SystemCapability.Security.Huks.Extension

**参数：**

| 参数名   | 类型                                              | 必填 | 说明                                             |
| -------- | ------------------------------------------------- | ---- | ------------------------------------------------ |
| userId   | number                                            | 是   | 用户ID。                 |
| keyAlias | string                                            | 是   | initSessionAsUser操作密钥的别名。                             |
| options  | [HuksOptions](js-apis-huks.md#huksoptions)        | 是   | initSessionAsUser参数集合。                                   |

**返回值**：

| 类型                                | 说明                                               |
| ----------------------------------- | -------------------------------------------------- |
| Promise\<[HuksSessionHandle](js-apis-huks.md#hukssessionhandle9)> | Promise对象。将initSessionAsUser操作返回的handle添加到密钥管理系统的回调。 |

**错误码：**

以下错误码的详细介绍请参见[HUKS错误码](errorcode-huks.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
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

**示例：**

- 以下代码示例接口调用的前置条件同上文[generateKeyItemAsUser](#huksgeneratekeyitemasuser12)的前置条件
- 注意：下文包括但不限于IV等变量的赋值，均为样例代码所用，不能直接使用于密码学相关生产环境，用户需自行查阅密码学相关知识使用合适的初始化方式。相关变量的内容长度和样例所使用的密码学算法相关，如需更改初始化值的内容长度时，请注意需配套修改样例代码后续使用的密码学算法。

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
      message: "成功生成了一个别名为：" + keyAlias + " 的密钥",
      duration: 2500,
    })
  }).catch((err: BusinessError) => {
    promptAction.showToast({
      message: "密钥生成失败，错误码是： " + err.code + " 错误吗信息： " + err.message,
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
      message: "密钥初始化失败，错误码是： " + err.code + " 错误吗信息： " + err.message,
      duration: 6500,
    })
  })
  await huks.finishSession(handle, options).then((data) => {
    promptAction.showToast({
      message: "加密数据成功， 密文是： " + Uint8ArrayToString(data.outData),
      duration: 1500,
    })
    if (data.outData != undefined) {
      cipherData = data.outData
    }
    console.log("running time result success!")
  }).catch((err: BusinessError) => {
    promptAction.showToast({
      message: "加密流程捕获了异常，错误码是： " + err.code + " 错误码信息： " + err.message,
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
      message: "密钥初始化失败，错误码是： " + err.code + " 错误吗信息： " + err.message,
      duration: 6500,
    })
  })
  await huks.finishSession(handle, options).then((data) => {
    promptAction.showToast({
      message: "解密成功， 解密的明文是： " + Uint8ArrayToString(data.outData),
      duration: 6500,
    })
  }).catch((err: BusinessError) => {
    promptAction.showToast({
      message: "解密流程捕获了异常，错误码是： " + err.code + " 错误码信息： " + err.message,
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
