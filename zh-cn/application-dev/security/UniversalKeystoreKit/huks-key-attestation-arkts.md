# 非匿名密钥证明(ArkTS)

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->

在使用本功能前，需申请权限：[ohos.permission.ATTEST_KEY](../AccessToken/permissions-for-system-apps.md#ohospermissionattest_key)。请开发者根据应用的APL等级，参考具体的操作路径[权限申请](../AccessToken/determine-application-mode.md)。

## 开发步骤

1. 指定密钥别名，密钥别名命名规范参考[密钥生成介绍及算法规格](huks-key-generation-overview.md)。

2. 初始化参数集。[HuksOptions](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksoptions)中的properties字段中的参数必须包含[HUKS_TAG_ATTESTATION_CHALLENGE](../../reference/apis-universal-keystore-kit/js-apis-huks.md#hukstag)属性，可选参数包含[HUKS_TAG_ATTESTATION_ID_VERSION_INFO](../../reference/apis-universal-keystore-kit/js-apis-huks.md#hukstag)，[HUKS_TAG_ATTESTATION_ID_ALIAS](../../reference/apis-universal-keystore-kit/js-apis-huks.md#hukstag)属性。

3. 生成非对称密钥，具体请参考[密钥生成](huks-key-generation-overview.md)。

4. 将密钥别名与参数集作为参数传入[attestKeyItem](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksattestkeyitem9)方法中，即可证明密钥。

```ts
/*
 * 以下以attestKey的Promise接口操作验证为例
 */
import { huks } from '@kit.UniversalKeystoreKit';
import { BusinessError } from "@kit.BasicServicesKit";

function StringToUint8Array(str: string) {
  let arr: number[] = [];
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

/* 1.确定密钥别名 */
let keyAliasString = "key attest";
let aliasString = keyAliasString;
let aliasUint8 = StringToUint8Array(keyAliasString);
let securityLevel = StringToUint8Array('sec_level');
let challenge = StringToUint8Array('challenge_data');
let versionInfo = StringToUint8Array('version_info');
let attestCertChain: Array<string>;

/* 封装生成时的密钥参数集 */
let genKeyProperties: Array<huks.HuksParam> = [{
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_RSA
  }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_RSA_KEY_SIZE_2048
  }, {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_VERIFY
  }, {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256
  }, {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_PSS
  }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_GENERATE_TYPE,
    value: huks.HuksKeyGenerateType.HUKS_KEY_GENERATE_TYPE_DEFAULT
  }, {
    tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
    value: huks.HuksCipherMode.HUKS_MODE_ECB
  }
]
let genOptions: huks.HuksOptions = {
  properties: genKeyProperties
};

/* 2.封装证明密钥的参数集 */
let attestKeyProperties: Array<huks.HuksParam> = [{
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
    value: aliasUint8
  }
]
let huksOptions: huks.HuksOptions = {
  properties: attestKeyProperties
};

/* 3.生成密钥 */
async function generateKeyItem(keyAlias: string, huksOptions: huks.HuksOptions) {
  console.info(`promise: enter generateKeyItem`);
  try {
    await huks.generateKeyItem(keyAlias, huksOptions)
      .then(() => {
        console.info(`promise: generateKeyItem success`);
      }).catch((error: BusinessError) => {
        console.error(`promise: generateKeyItem failed, errCode : ${error.code}, errMsg : ${error.message}`);
      })
  } catch (error) {
    console.error(`promise: generateKeyItem input arg invalid`);
  }
}

/* 4.证明密钥 */
async function attestKeyItem(keyAlias: string, huksOptions: huks.HuksOptions) {
  console.info(`promise: enter attestKeyItem`);
  try {
    await huks.attestKeyItem(keyAlias, huksOptions)
      .then((data) => {
        if (data !== null && data.certChains !== null) {
          attestCertChain = data.certChains as string[];
        }
        console.info(`promise: attestKeyItem success, attestCertChain = ${attestCertChain}`);
      }).catch((error: BusinessError) => {
        console.error(`promise: attestKeyItem failed, errCode : ${error.code}, errMsg : ${error.message}`);
      })
  } catch (error) {
    console.error(`promise: attestKeyItem input arg invalid`);
  }
}

async function AttestKeyTest() {
  await generateKeyItem(aliasString, genOptions);
  await attestKeyItem(aliasString, huksOptions);
  console.info('attest certChain data: ' + attestCertChain)
}
```