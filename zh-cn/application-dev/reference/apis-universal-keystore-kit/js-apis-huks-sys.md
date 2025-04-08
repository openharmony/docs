# @ohos.security.huks (通用密钥库系统)(系统接口)

向应用提供密钥库能力，应用可调用接口，指定用户身份操作密钥。

> **说明：**
> - 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.security.huks (通用密钥库系统)](js-apis-huks.md)。

## 导入模块

```ts
import { huks } from '@kit.UniversalKeystoreKit';
```

## huks.generateKeyItemAsUser

generateKeyItemAsUser(userId: number, keyAlias: string, huksOptions: HuksOptions) : Promise\<void>

指定用户身份生成密钥，使用Promise方式异步返回结果。基于密钥不出TEE原则，通过promise不会返回密钥材料内容，只用于表示此次调用是否成功。

**需要权限**：ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力**：SystemCapability.Security.Huks.Extension

**参数：**

| 参数名   | 类型                        | 必填 | 说明                     |
| -------- | --------------------------- | ---- | ------------------------ |
| userId   | number                      | 是   | 用户ID。                 |
| keyAlias | string                      | 是   | 密钥别名。密钥别名的最大长度为128字节，建议不包含个人信息等敏感词汇。               |
| options  | [HuksOptions](js-apis-huks.md#huksoptions) | 是   | 用于存放生成key所需的[属性标签](native__huks__type_8h.md#枚举)。其中密钥使用的算法、密钥用途、密钥长度为必选参数。 |

**错误码：**

以下错误码的详细介绍请参见[HUKS错误码](errorcode-huks.md)。

| 错误码ID | 错误信息      |
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

**示例：**

- 以下代码示例接口调用的前置条件：

  调用方必须是运行在User0~99（包含0和99）用户身份下的系统应用，同时需要申请ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS权限。允许应用安装到User0的配置指导，请参考[singleton|bool|false|是否允许应用安装到单用户下(U0)](../../../../zh-cn/device-dev/subsystems/subsys-app-privilege-config-guide.md#可由设备厂商配置的特权)

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
    console.info("成功生成了一个别名为：" + keyAlias + " 的密钥")
  }).catch((err: Error) => {
    console.error("密钥生成失败，错误:" + JSON.stringify(err))
  })
}


export default function HuksAsUserTest() {
  console.info('begin huks as user test')
  GenerateKey(aesKeyAlias, GetAesGenerateProperties())
}
```

## huks.deleteKeyItemAsUser

deleteKeyItemAsUser(userId: number, keyAlias: string, huksOptions: HuksOptions) : Promise\<void>

指定用户身份删除密钥，使用Promise方式异步返回结果。

**需要权限**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

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
| 201 | the application permission is not sufficient, which may be caused by lack of cross-account permission, or the system has not been unlocked by user, or the user does not exist. |
| 202 | non-system applications are not allowed to use system APIs. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |
| 801 | api is not supported. |
| 12000004 | operating file failed. |
| 12000005 | IPC communication failed. |
| 12000011 | queried entity does not exist. |
| 12000012 | external error. |
| 12000014 | memory is insufficient. |

**示例：**

- 以下代码示例接口调用的前置条件同上文[generateKeyItemAsUser](#huksgeneratekeyitemasuser)的前置条件

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
    console.error("密钥生成失败，错误码是： " + err.code + " 错误码信息： " + err.message)
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
    console.info("别名为: " + keyAlias + " 密钥删除成功！")
  }).catch((err: BusinessError) => {
    console.error("密钥删除失败，错误码是： " + err.code + " 错误码信息： " + err.message)
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

指定用户身份导入明文密钥，使用Promise方式异步返回结果。

**需要权限**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力**：SystemCapability.Security.Huks.Extension

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                |
| -------- | --------------------------- | ---- | ----------------------------------- |
| userId   | number                      | 是   | 用户ID。                 |
| keyAlias | string                      | 是   | 密钥别名。密钥别名的最大长度为128字节，建议不包含个人信息等敏感词汇。                          |
| options  | [HuksOptions](js-apis-huks.md#huksoptions) | 是   | 用于导入时所需TAG和需要导入的密钥。其中密钥使用的算法、密钥用途、密钥长度为必选参数。 |

**错误码：**

以下错误码的详细介绍请参见[HUKS错误码](errorcode-huks.md)。

| 错误码ID | 错误信息      |
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

**示例：**

- 以下代码示例接口调用的前置条件同上文[generateKeyItemAsUser](#huksgeneratekeyitemasuser)的前置条件

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
    console.info("成功导入了一个别名为：" + keyAlias + " 的密钥")
  }).catch((err: BusinessError) => {
    console.error("密钥导入失败，错误码是： " + err.code + " 错误码信息： " + err.message)
  })
}

export default function HuksAsUserTest() {
  console.info('begin huks as user test')
  ImportPlainKey(aesKeyAlias, GetAesGenerateProperties(), plainAesKey128)
}
```


## huks.attestKeyItemAsUser

attestKeyItemAsUser(userId: number, keyAlias: string, huksOptions: HuksOptions) : Promise\<HuksReturnResult>

指定用户身份获取密钥证书，使用Promise方式异步返回结果。

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
| Promise<[HuksReturnResult](js-apis-huks.md#huksreturnresult9)> | Promise对象。当调用成功时，HuksReturnResult的certChains成员非空，为获取到的证书链，否则为失败。 |

**错误码：**

以下错误码的详细介绍请参见[HUKS错误码](errorcode-huks.md)。

| 错误码ID | 错误信息      |
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

**示例：**

- 以下代码示例接口调用的前置条件同上文[generateKeyItemAsUser](#huksgeneratekeyitemasuser)的前置条件

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
    console.info("成功生成了一个别名为：" + keyAlias + " 的密钥")
  }).catch((err: BusinessError) => {
    console.error("密钥生成失败，错误码是： " + err.code + " 错误码信息： " + err.message)
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
  console.info('开始attest')
  await huks.attestKeyItemAsUser(userId, keyAlias, attestOptions).then((data) => {
    console.info('attestation ok!')
    console.debug(`拿到的证书链是${JSON.stringify(data)}`) // 这里是调试信息，实际业务功能开发无需打印证书链。
    for (let i = 0; data?.certChains?.length && i < data?.certChains?.length; ++i) {
      console.debug(`证书${i}是${data.certChains[i]}`) // 这里是调试信息，实际业务功能开发无需打印证书链。
    }
    console.info("attest 成功")
  }).catch((err: BusinessError) => {
    console.error("attest 失败，错误码是： " + err.code + " 错误码信息： " + err.message)
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

指定用户身份获取匿名化密钥证书，使用Promise方式异步返回结果。

该操作需要联网进行，且耗时较长。

**需要权限**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

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
| Promise<[HuksReturnResult](js-apis-huks.md#huksreturnresult9)> | Promise对象。当调用成功时，HuksReturnResult的certChains成员非空，为获取到的证书链，否则为失败。 |

**错误码：**

以下错误码的详细介绍请参见[HUKS错误码](errorcode-huks.md)。

| 错误码ID | 错误信息      |
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

**示例：**

- 以下代码示例接口调用的前置条件同上文[generateKeyItemAsUser](#huksgeneratekeyitemasuser)的前置条件

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
    console.info("成功生成了一个别名为：" + keyAlias + " 的密钥")
  }).catch((err: BusinessError) => {
    console.error("密钥生成失败，错误码是： " + err.code + " 错误码信息： " + err.message)
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
  console.info('开始匿名attest')
  await huks.anonAttestKeyItemAsUser(userId, keyAlias, attestOptions).then((data) => {
    console.info('匿名attestation ok!')
    console.debug(`拿到的证书链是${JSON.stringify(data)}`)
    for (let i = 0; data?.certChains?.length && i < data?.certChains?.length; ++i) {
      console.info(`证书${i}是${data.certChains[i]}`)
    }
    console.info("匿名 attest 成功")
  }).catch((err: BusinessError) => {
    console.error("匿名 attest 失败，错误码是： " + err.code + " 错误码信息： " + err.message)
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

指定用户身份导入加密密钥，使用Promise方式异步返回结果。

**需要权限**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

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

**示例：**

- 以下代码示例接口调用的前置条件同上文[generateKeyItemAsUser](#huksgeneratekeyitemasuser)的前置条件
- 注意：下文密码学相关的变量（如initializationVector、associatedData、nonce）赋值，均为参考样例，不能直接适用于业务功能逻辑。开发者需要根据自身场景使用合适的初始值。

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
        console.info(`importWrappedKeyItemAsUser 成功 data = ${JSON.stringify(data)}`)
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

指定用户身份导出密钥，使用Promise方式回调异步返回的结果。

**需要权限**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

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
| Promise<[HuksReturnResult](js-apis-huks.md#huksreturnresult9)> | Promise对象。 当调用成功时，HuksReturnResult的outData成员非空，为从密钥中导出的公钥，否则为失败。 |

**错误码：**

以下错误码的详细介绍请参见[HUKS错误码](errorcode-huks.md)。

| 错误码ID | 错误信息      |
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

**示例：**

- 以下代码示例接口调用的前置条件同上文[generateKeyItemAsUser](#huksgeneratekeyitemasuser)的前置条件

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
    console.info("成功生成了一个别名为：" + keyAlias + " 的密钥")
  }).catch((err: BusinessError) => {
    console.error("密钥生成失败，错误码是： " + err.code + " 错误码信息： " + err.message)
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
    console.info("成功将别名为：" + keyAlias + " 的公钥导出, data 的长度为" + data?.outData?.length)
  }).catch((err: BusinessError) => {
    console.error("密钥导出失败，错误码是： " + err.code + " 错误码信息： " + err.message)
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

指定用户身份获取密钥属性，使用Promise回调异步返回结果。

**需要权限**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

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
| Promise\<[HuksReturnResult](js-apis-huks.md#huksreturnresult9)> | Promise对象。当调用成功时，HuksReturnResult的properties成员非空，为生成密钥时所需参数，否则为失败。

**错误码：**

以下错误码的详细介绍请参见[HUKS错误码](errorcode-huks.md)。

| 错误码ID | 错误信息      |
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

**示例：**

- 以下代码示例接口调用的前置条件同上文[generateKeyItemAsUser](#huksgeneratekeyitemasuser)的前置条件

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
    console.info("成功生成了一个别名为：" + keyAlias + " 的密钥")
  }).catch((err: BusinessError) => {
    console.error("密钥生成失败，错误码是： " + err.code + " 错误码信息： " + err.message)
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
    console.info("获取密钥属性成功！属性为: " + JSON.stringify(data))
  }).catch((err: BusinessError) => {
    console.error("获取密钥属性失败，错误码是： " + err.code + " 错误码信息： " + err.message)
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

指定用户身份判断密钥是否存在，使用Promise回调异步返回结果。

**需要权限**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

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

**示例：**

- 以下代码示例接口调用的前置条件同上文[generateKeyItemAsUser](#huksgeneratekeyitemasuser)的前置条件

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
    console.info("成功生成了一个别名为：" + keyAlias + " 的密钥")
  }).catch((err: BusinessError) => {
    console.error("密钥生成失败，错误码是： " + err.code + " 错误码信息： " + err.message)
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
    console.info("别名为: " + keyAlias + "的密钥查询存在结果" + JSON.stringify(data))
  }).catch((err: BusinessError) => {
    console.error("密钥删除失败，错误码是： " + err.code + " 错误码信息： " + err.message)
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

指定用户身份操作密钥接口，使用Promise方式异步返回结果。huks.initSessionAsUser, huks.updateSession, huks.finishSession为三段式接口，需要一起使用。

**需要权限**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

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

**示例：**

- 以下代码示例接口调用的前置条件同上文[generateKeyItemAsUser](#huksgeneratekeyitemasuser)的前置条件
- 注意：下文密码学相关的变量（如initializationVector）赋值，均为参考样例，不能直接适用于业务功能逻辑。开发者需要根据自身场景使用合适的初始值。

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
    console.info("成功生成了一个别名为：" + keyAlias + " 的密钥")
  }).catch((err: BusinessError) => {
    console.error("密钥生成失败，错误码是： " + err.code + " 错误码信息： " + err.message)
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
    console.error("密钥初始化失败，错误码是： " + err.code + " 错误码信息： " + err.message)
  })
  await huks.finishSession(handle, options).then((data) => {
    console.info("加密数据成功， 密文是： " + Uint8ArrayToString(data.outData))
    if (data.outData != undefined) {
      cipherData = data.outData
    }
    console.info("running time result success!")
  }).catch((err: BusinessError) => {
    console.error("加密流程捕获了异常，错误码是： " + err.code + " 错误码信息： " + err.message)
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
    console.error("密钥初始化失败，错误码是： " + err.code + " 错误码信息： " + err.message)
  })
  await huks.finishSession(handle, options).then((data) => {
    console.info("解密成功， 解密的明文是： " + Uint8ArrayToString(data.outData))
  }).catch((err: BusinessError) => {
    console.error("解密流程捕获了异常，错误码是： " + err.code + " 错误码信息： " + err.message)
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
