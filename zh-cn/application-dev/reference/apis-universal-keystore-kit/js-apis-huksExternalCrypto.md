# @ohos.security.huksExternalCrypto (外部密钥管理)

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->

模块提供外部密钥管理扩展功能的注册与注销，PIN码认证与认证状态获取等能力。

> **说明**
>
> 本模块首批接口从API version 22开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { huksExternalCrypto } from '@kit.UniversalKeystoreKit';
```

## HuksExternalCryptoTagType

表示外部加密数据类型的枚举。

**系统能力：** SystemCapability.Security.Huks.CryptoExtension

| 名称  | 值   | 说明    |
| ----- | ---- | -------- |
| HUKS_EXT_CRYPTO_TAG_TYPE_INT | 1 << 28   | 表示TAG的值为整数类型。 |
| HUKS_EXT_CRYPTO_TAG_TYPE_BYTES | 5 << 28  | 表示TAG的值为字节数组。 |

## HuksExternalCryptoTag

表示调用参数的Tag。

**系统能力：** SystemCapability.Security.Huks.CryptoExtension

| 名称    | 值   | 说明   |
| ------- | ---- | -------- |
| HUKS_EXT_CRYPTO_TAG_UKEY_PIN | HuksExternalCryptoTagType.HUKS_EXT_CRYPTO_TAG_TYPE_BYTES \| 200001    | 表示PIN码的Tag。 |
| HUKS_EXT_CRYPTO_TAG_ABILITY_NAME | HuksExternalCryptoTagType.HUKS_EXT_CRYPTO_TAG_TYPE_BYTES \| 200002    | 表示[CryptoExtensionAbility](js-apis-CryptoExtensionAbility.md)的名称。 |
| HUKS_EXT_CRYPTO_TAG_EXTRA_DATA | HuksExternalCryptoTagType.HUKS_EXT_CRYPTO_TAG_TYPE_BYTES \| 200003    | 外部数据，在通用查询场景，表示返回的数据。 |
| HUKS_EXT_CRYPTO_TAG_UID | HuksExternalCryptoTagType.HUKS_EXT_CRYPTO_TAG_TYPE_INT \| 200004    | 表示调用方的uid。 |
| HUKS_EXT_CRYPTO_TAG_PURPOSE | HuksExternalCryptoTagType.HUKS_EXT_CRYPTO_TAG_TYPE_INT \| 200005    | 表示证书链对应密钥的使用类型，具体类型详见[CertificatePurpose](../apis-device-certificate-kit/js-apis-certManager.md#certificatepurpose22)。 |
| HUKS_EXT_CRYPTO_TAG_RESOURCE_INFO | HuksExternalCryptoTagType.HUKS_EXT_CRYPTO_TAG_TYPE_BYTES \| 200007    | 表示获取资源ID所需的信息，格式和内容由厂商自定义。<br>**起始版本：** 26.0.0<br>**模型约束**：此接口仅可在Stage模型下使用。 |
| HUKS_EXT_CRYPTO_TAG_ABILITY_INFO | HuksExternalCryptoTagType.HUKS_EXT_CRYPTO_TAG_TYPE_BYTES \| 200008    | 表示密钥管理扩展自定义PIN码弹窗相关Ability列表信息，在注册密钥管理扩展时，同步注册，详见[provider注册示例](../../security/UniversalKeystoreKit/huks-extension-registration-and-unregistration-arkts.md)。注册了自定义弹窗，则在PIN码认证时允许拉起自定义弹窗，进行PIN码认证等操作。<br>HUKS_EXT_CRYPTO_TAG_ABILITY_INFO<br> 1.abilityName：长度范围为1~128字节。<br> 2.index：其值为resourceId，最大长度为512字节。该字段不允许重复，允许单个CryptoExtension下该字段为空，为空时传输空字符串。在搜索时优先匹配index对应的UIAbility，当不存在时返回index为空的UIAbility。<br>**起始版本：** 26.0.0<br>**模型约束**：此接口仅可在Stage模型下使用。 |
| HUKS_EXT_CRYPTO_TAG_BUNDLE_NAME | HuksExternalCryptoTagType.HUKS_EXT_CRYPTO_TAG_TYPE_BYTES \| 200009    | 表示CryptoExtensionAbility所属的HAP Bundle名称。<br>**起始版本：** 26.0.0<br>**模型约束**：此接口仅可在Stage模型下使用。 |

## HuksExternalCryptoParam

表示调用接口使用的param数组的类型。

**系统能力：** SystemCapability.Security.Huks.CryptoExtension

| 名称 | 类型        | 只读 | 可选 | 说明         |
| ------ | ----------------------------------- | ---- | ---- | ------------ |
| tag    | [HuksExternalCryptoTag](#huksexternalcryptotag)  | 否   | 否   | 参数标签，用于区分参数。 |
| value  | boolean \| number \| bigint \| Uint8Array | 否   | 否   | 标签对应值。 |

## HuksExternalErrorInfo

表示外部密钥操作时，密钥管理扩展返回的详细错误信息。

**起始版本：** 26.0.0

**模型约束：** 此结构体仅可在Stage模型下使用。

**系统能力：** SystemCapability.Security.Huks.CryptoExtension

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| errno | number | 否 | 否 | 密钥管理扩展返回的错误码。<br>- 非0值：密钥管理扩展返回了详细错误信息，errno为具体错误码。<br>- 0值：密钥管理扩展未返回详细错误信息，errno为默认值0，开发者应通过接口异常的错误码判断错误原因。 |
| errorDesc | string | 否 | 否 | 密钥管理扩展返回的错误描述，长度为0~256字节。该字段的值与errno关联：<br>- errno非0时：密钥管理扩展返回的描述，可能为空字符串（由扩展决定）。<br>- errno为0时：空字符串。 |

## HuksExternalPinAuthState

表示UKey PIN码管理的状态值的枚举。

**系统能力：** SystemCapability.Security.Huks.CryptoExtension

| 名称    | 值   | 说明   |
| ------- | ---- | -------- |
| HUKS_EXT_CRYPTO_PIN_NO_AUTH | 0 | UKey PIN未认证。 |
| HUKS_EXT_CRYPTO_PIN_AUTH_SUCCEEDED | 1 | UKey PIN认证成功。 |
| HUKS_EXT_CRYPTO_PIN_LOCKED  | 2 | UKey PIN已锁定。 |

## huksExternalCrypto.registerProvider

registerProvider(providerName: string, params: Array\<HuksExternalCryptoParam>): Promise\<void>

注册指定的外部provider。使用Promise异步回调。

若需使用自定义PIN码弹窗，在注册provider时需要同步注册UIAbility，注意事项如下：

1. 自定义弹窗通过UIAbility扩展实现。

2. 注册的UIAbility可以通过证书管理kit提供的[openUKeyAuthDialog](../apis-device-certificate-kit/js-apis-certManagerDialog.md#certificatemanagerdialogopenukeyauthdialog22)接口统一拉起。

3. 系统拉起自定义弹窗时会通过want接口向开发者传递以下参数：

    - Action：string参数类型，在拉起自定义弹窗时want传输的Action为"UkeyPINAuth"。
    - appUid：number参数类型，通过want.parameters传输。"appUid"字段为应用id，开发者可以通过该字段完成应用隔离。
    - keyUri：string参数类型，其值为resourceId，通过want.parameters传输，表示UKey证书的索引。
  
4. 开发者实现UIAbility时，应用需根据指定场景返回对应的错误码：

    - 用户取消操作时，返回[ERROR_OPERATION_CANCELED](../apis-device-certificate-kit/js-apis-certManagerDialog.md#certificatedialogerrorcode)。
    - keyUri指定的证书/密钥不存在时，返回[ERROR_OPERATION_FAILED](../apis-device-certificate-kit/js-apis-certManagerDialog.md#certificatedialogerrorcode)。
    - 参数格式错误时，返回[ERROR_PARAMETER_VALIDATION_FAILED](../apis-device-certificate-kit/js-apis-certManagerDialog.md#certificatedialogerrorcode)。
    - 其余失败场景返回错误码[ERROR_GENERIC](../apis-device-certificate-kit/js-apis-certManagerDialog.md#certificatedialogerrorcode)，成功时返回0。

**需要权限：** ohos.permission.CRYPTO_EXTENSION_REGISTER

**系统能力：** SystemCapability.Security.Huks.CryptoExtension

**参数：**

| 参数名   | 类型  | 必填 | 说明  |
| -------- | ------- | ---- | -------|
| providerName | string | 是   | provider名称，最大长度为128字节。建议包含厂商信息，全局唯一，不要包含个人联系方式等敏感数据。<br>最多支持注册10个provider。 |
| params  | Array<[HuksExternalCryptoParam](#huksexternalcryptoparam)> | 是  | 操作时需传入的参数，必选TAG：[HUKS_EXT_CRYPTO_TAG_ABILITY_NAME](#huksexternalcryptotag)，表示ability的名字，根据业务自己内部定义按照实际填写。<br>从API版本26.0.0开始，可选TAG：[HUKS_EXT_CRYPTO_TAG_ABILITY_INFO](#huksexternalcryptotag)，以JSON列表的形式传入PIN码认证自定义弹窗UIAbility的名字以及包名。 |

**返回值：**

| 类型  | 说明  |
| ------------- | --------|
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[HUKS错误码](errorcode-huks.md)。

| 错误码ID | 错误信息      |
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

**示例：**

```ts
import { huksExternalCrypto } from '@kit.UniversalKeystoreKit';

function stringToUint8Array(str: string) {
  let arr: number[] = [];
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

const providerName = 'testProviderName';
const extProperties: Array<huksExternalCrypto.HuksExternalCryptoParam> = [
  {
    tag: huksExternalCrypto.HuksExternalCryptoTag.HUKS_EXT_CRYPTO_TAG_ABILITY_NAME,
    value: stringToUint8Array('CryptoExtension')
  }
];
huksExternalCrypto.registerProvider(providerName, extProperties)
    .then(() => {
        console.info('promise: registerProvider success.');
    });
```

## huksExternalCrypto.unregisterProvider

unregisterProvider(providerName: string, params?: Array\<HuksExternalCryptoParam>): Promise\<void>

注销指定的外部provider。使用Promise异步回调。

**需要权限：** ohos.permission.CRYPTO_EXTENSION_REGISTER

**系统能力：** SystemCapability.Security.Huks.CryptoExtension

**参数：**

| 参数名   | 类型 | 必填 | 说明  |
| -------- | ------| ---- | -----|
| providerName | string | 是   | provider名称，最大长度为128字节。建议包含厂商信息，全局唯一，不要包含个人联系方式等敏感数据。如果provider注册了多个扩展能力，则该provider下的扩展能力都会被注销。 |
| params  | Array\<[HuksExternalCryptoParam](#huksexternalcryptoparam)> | 否 | 操作时需传入的参数。<br>可以在param参数中指定[HUKS_EXT_CRYPTO_TAG_ABILITY_NAME](#huksexternalcryptotag)，将根据“包名 + providerName + abilityName”注销对应的cryptoExtensionAbility。<br>如果未在params参数中指定[HUKS_EXT_CRYPTO_TAG_ABILITY_NAME](#huksexternalcryptotag)，或者未传入params参数，则注销对应的providerName下的所有Provider。|

**返回值：**

| 类型   | 说明   |
| -------| ------ |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[HUKS错误码](errorcode-huks.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 201 | check permission failed. |
| 801 | api is not supported. |
| 12000005 | IPC communication failed. |
| 12000011 | the provider is not found. |
| 12000012 | Device environment or input parameter is abnormal. This may happen for several reasons, such as the model already being unloaded. |
| 12000014 | memory is insufficient. |
| 12000018 | the input parameter is invalid. |

**示例：**

```ts
import { huksExternalCrypto } from '@kit.UniversalKeystoreKit';

function stringToUint8Array(str: string) {
  let arr: number[] = [];
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

const providerName = 'testProviderName';
const extProperties: Array<huksExternalCrypto.HuksExternalCryptoParam> = [
  {
    tag: huksExternalCrypto.HuksExternalCryptoTag.HUKS_EXT_CRYPTO_TAG_ABILITY_NAME,
    value: stringToUint8Array('CryptoExtension')
  }
];
huksExternalCrypto.unregisterProvider(providerName, extProperties)
    .then(() => {
        console.info('promise: unregisterProvider success.');
    });
```

## huksExternalCrypto.getUkeyPinAuthState

getUkeyPinAuthState(resourceId: string, params?: Array\<HuksExternalCryptoParam>): Promise\<HuksExternalPinAuthState>

获取PIN码认证状态。使用Promise异步回调。

**系统能力：** SystemCapability.Security.Huks.CryptoExtension

**参数：**

| 参数名   | 类型  | 必填 | 说明  |
| -------- | ------- | ---- | ----------|
| resourceId | string | 是   | 资源ID，可通过[openAuthorizeDialog](../apis-device-certificate-kit/js-apis-certManagerDialog.md#certificatemanagerdialogopenauthorizedialog22)获取，其结果中附带资源ID。 |
| params  | Array\<[HuksExternalCryptoParam](#huksexternalcryptoparam)> | 否   | 操作的属性。不传入时，不向Extension Ability传递额外参数。非系统应用传入[HUKS_EXT_CRYPTO_TAG_UID](#huksexternalcryptotag)是非法参数。 |

**返回值：**

| 类型   | 说明   |
| -------- | ------- |
| Promise\<[HuksExternalPinAuthState](#huksexternalpinauthstate)> | Promise对象，返回认证结果。<br>HUKS_EXT_CRYPTO_PIN_NO_AUTH 表示未认证；HUKS_EXT_CRYPTO_PIN_AUTH_SUCCEEDED 表示认证成功；HUKS_EXT_CRYPTO_PIN_LOCKED 表示PIN被锁定。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[HUKS错误码](errorcode-huks.md)。

| 错误码ID | 错误信息      |
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

**示例：**

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
const extProperties: Array<huksExternalCrypto.HuksExternalCryptoParam> = [];
huksExternalCrypto.getUkeyPinAuthState(testResourceId, extProperties)
    .then((data) => {
      console.info(`promise: getUkeyPinAuthState success, data: ${data}`);
    });
```

## huksExternalCrypto.getProperty

getProperty(resourceId: string, propertyId: string, params?: Array\<HuksExternalCryptoParam>): Promise\<Array\<HuksExternalCryptoParam>>

调用此接口获取属性值并返回结果。使用Promise异步回调。

propertyId表示查询属性的ID信息，推荐使用GMT 0016-2023中定义的SKF接口名作为属性ID，支持的ID包括如下：

- SKF_EnumDev 
- SKF_GetDevInfo 
- SKF_EnumApplication 
- SKF_EnumContainer

从API版本26.0.0开始，属性ID放开限制，支持自定义属性ID，由[CryptoExtensionAbility](js-apis-CryptoExtensionAbility.md)实现方提供。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Security.Huks.CryptoExtension

**参数：**

| 参数名   | 类型  | 必填 | 说明  |
| -------- | ------- | ---- | ----------|
| resourceId | string | 是   | 资源ID，可通过[openAuthorizeDialog](../apis-device-certificate-kit/js-apis-certManagerDialog.md#certificatemanagerdialogopenauthorizedialog22)获取，该接口的返回结果中附带resourceId。 |
| propertyId | string | 是   | 查找操作的属性名称，是GMT 0016-2023中定义的SKF接口名，应用开发者需要针对接口名进行适配。 |
| params  | Array\<[HuksExternalCryptoParam](#huksexternalcryptoparam)> | 否   | 需要传递给[CryptoExtensionAbility](js-apis-CryptoExtensionAbility.md)的输入参数。不传入时，不向Extension Ability传递额外参数。非系统应用传入[HUKS_EXT_CRYPTO_TAG_UID](#huksexternalcryptotag)是非法参数。 |

**返回值：**

| 类型   | 说明   |
| -------- | ------- |
| Promise\<Array\<[HuksExternalCryptoParam](#huksexternalcryptoparam)>> | Promise对象，返回调用接口的结果。当调用成功时，返回结果为HuksExternalCryptoParam类型的数组，包含要查询的属性。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[HUKS错误码](errorcode-huks.md)。

| 错误码ID | 错误信息      |
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

**示例：**

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

let propertyId = 'SKF_EnumDev';
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

清除指定资源ID的PIN码认证状态，清除后PIN认证状态变为HUKS_EXT_CRYPTO_PIN_NO_AUTH（未认证）。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Security.Huks.CryptoExtension

**参数：**

| 参数名   | 类型  | 必填 | 说明  |
| -------- | ------- | ---- | ----------|
| resourceId | string | 是   | 资源ID，可通过[openAuthorizeDialog](../apis-device-certificate-kit/js-apis-certManagerDialog.md#certificatemanagerdialogopenauthorizedialog22)获取，其结果中附带资源ID。 |

**返回值：**

| 类型   | 说明   |
| -------- | ------- |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[HUKS错误码](errorcode-huks.md)。

| 错误码ID | 错误信息      |
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

**示例：**

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

获取密钥扩展能力的资源ID。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Security.Huks.CryptoExtension

**参数：**

| 参数名   | 类型  | 必填 | 说明  |
| -------- | ------- | ---- | ----------|
| providerName | string | 是   | 提供者名称，建议包含厂商信息，全局唯一，长度最大为128字节。 |
| params | [HuksExternalCryptoParam](#huksexternalcryptoparam)[] | 是   | 获取资源ID所需的属性参数。必选TAG包括：[HUKS_EXT_CRYPTO_TAG_ABILITY_NAME](#huksexternalcryptotag)、[HUKS_EXT_CRYPTO_TAG_BUNDLE_NAME](#huksexternalcryptotag)、[HUKS_EXT_CRYPTO_TAG_RESOURCE_INFO](#huksexternalcryptotag)。非系统应用传入[HUKS_EXT_CRYPTO_TAG_UID](#huksexternalcryptotag)是非法参数。 |

**返回值：**

| 类型   | 说明   |
| -------- | ------- |
| Promise\<string> | Promise对象，返回资源ID。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[HUKS错误码](errorcode-huks.md)。

| 错误码ID | 错误信息      |
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

**示例：**

```ts
import { huksExternalCrypto } from '@kit.UniversalKeystoreKit';

function stringToUint8Array(str: string) {
  let arr: number[] = [];
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

const providerName = 'testProviderName';
const abilityName = 'CryptoExtension';
const bundleName = 'com.example.cryptoapplication';
// 资源信息，格式和内容由厂商自定义
const resourceInfo = 'vendor_defined_resource_info';

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

打开指定资源ID的资源。使用Promise异步回调。

> **说明：**
>
> 打开的资源必须使用[closeResource](#huksexternalcryptocloseresource)关闭。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Security.Huks.CryptoExtension

**参数：**

| 参数名   | 类型  | 必填 | 说明  |
| -------- | ------- | ---- | ----------|
| resourceId | string | 是   | 资源ID。可通过[openAuthorizeDialog](../apis-device-certificate-kit/js-apis-certManagerDialog.md#certificatemanagerdialogopenauthorizedialog22)获取keyUri作为resourceId，或通过[getResourceId](#huksexternalcryptogetresourceid)获取外部密钥管理扩展的资源ID。 |
| params | [HuksExternalCryptoParam](#huksexternalcryptoparam)[] | 否   | 需要传递给[CryptoExtensionAbility](js-apis-CryptoExtensionAbility.md)的输入参数。不传入时，不向Extension Ability传递额外参数。 |

**返回值：**

| 类型   | 说明   |
| -------- | ------- |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[HUKS错误码](errorcode-huks.md)。

| 错误码ID | 错误信息      |
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

**示例：**

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

关闭指定资源ID的资源。使用Promise异步回调。

该接口会回调[onClearUkeyPinAuthState](js-apis-CryptoExtensionAbility.md#onclearukeypinauthstate)清理该资源关联的PIN认证状态，以及会回调[onFinishSession](js-apis-CryptoExtensionAbility.md#onfinishsession)清理该资源关联的会话handle。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Security.Huks.CryptoExtension

**参数：**

| 参数名   | 类型  | 必填 | 说明  |
| -------- | ------- | ---- | ----------|
| resourceId | string | 是   | 资源ID。可通过[openAuthorizeDialog](../apis-device-certificate-kit/js-apis-certManagerDialog.md#certificatemanagerdialogopenauthorizedialog22)获取keyUri作为resourceId，或通过[getResourceId](#huksexternalcryptogetresourceid)获取外部密钥管理扩展的资源ID。 |
| params | [HuksExternalCryptoParam](#huksexternalcryptoparam)[] | 否   | 需要传递给[CryptoExtensionAbility](js-apis-CryptoExtensionAbility.md)的输入参数。不传入时，不向Extension Ability传递额外参数。 |

**返回值：**

| 类型   | 说明   |
| -------- | ------- |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[HUKS错误码](errorcode-huks.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 801 | API is not supported. |
| 12000005 | IPC communication failed. |
| 12000006 | Failed to call the UKey driver interface. Please check the UKey connection and driver status. |
| 12000012 | Device environment or input parameters are abnormal. This error may occur if the process function is not found, or due to other issues. |
| 12000014 | The memory is insufficient. |
| 12000018 | Input parameters are invalid. Possible causes: 1. The resourceId length is invalid. 2. The parameters contain invalid tags or invalid value types. |
| 12000020 | The provider operation failed. This means an error occurred in the crypto extension before calling the UKey driver interface. |
| 12000024 | The provider or UKey is busy. |

**示例：**

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

调用此接口设置由resourceId标识的UKey资源的属性值。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Security.Huks.CryptoExtension

**参数：**

| 参数名   | 类型  | 必填 | 说明  |
| -------- | ------- | ---- | ----------|
| resourceId | string | 是   | 资源ID。可通过[openAuthorizeDialog](../apis-device-certificate-kit/js-apis-certManagerDialog.md#certificatemanagerdialogopenauthorizedialog22)获取keyUri作为resourceId，或通过[getResourceId](#huksexternalcryptogetresourceid)获取外部密钥管理扩展的资源ID。 |
| propertyId | string | 是   | 设置操作的属性名称。由[CryptoExtensionAbility](js-apis-CryptoExtensionAbility.md)实现方提供，推荐使用GMT 0016-2023中定义的SKF接口名作为属性ID。 |
| params  | [HuksExternalCryptoParam](#huksexternalcryptoparam)[] | 否   | 需要传递给[CryptoExtensionAbility](js-apis-CryptoExtensionAbility.md)的输入参数，包含与propertyId相关的操作参数。不传入时，不向Extension Ability传递额外参数。 |

**返回值：**

| 类型   | 说明   |
| -------- | ------- |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[HUKS错误码](errorcode-huks.md)。

| 错误码ID | 错误信息      |
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

**示例：**

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

const propertyId = 'SKF_SetDevInfo';
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

以同步方式获取最近一次外部密钥操作的详细错误信息，该错误信息由密钥管理扩展返回。

> **说明：**
>
> 1. 此接口返回密钥管理扩展的详细错误信息（errno和errorDesc），HUKS内部错误通过接口异常抛出。
> 2. 当密钥管理扩展未返回详细错误信息时（errno为0），errorDesc为空字符串，开发者应通过接口异常的错误码判断错误原因。
> 3. 建议在操作失败后立即调用此接口获取详细错误信息。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Security.Huks.CryptoExtension

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| [HuksExternalErrorInfo](#huksexternalerrorinfo) | 返回最近一次操作的错误信息。 |

**示例：**

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
  index: {
    key: "testKey"
  } as ESObject
});
const pin = '123456'; // 此处为示例，实际业务中应替换为真实的用户PIN码
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
    console.error(`errno: ${errorInfo.errno}`);
    console.error(`errorDesc: ${errorInfo.errorDesc}`);
  }
}
```
