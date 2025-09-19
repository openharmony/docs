# 查询密钥是否存在(ArkTS)

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->

HUKS提供了接口供应用查询指定密钥是否存在。

## 开发步骤

1. 指定密钥别名，密钥别名命名规范参考[密钥生成介绍及算法规格](huks-key-generation-overview.md)。

2. 初始化密钥属性集。用于查询时指定[密钥的属性TAG](../../reference/apis-universal-keystore-kit/js-apis-huks.md#hukstag)，当查询单个密钥时，TAG字段可传空。

3. 调用接口[hasKeyItem](../../reference/apis-universal-keystore-kit/js-apis-huks.md#hukshaskeyitem11)，查询密钥是否存在。

```ts
import { huks } from '@kit.UniversalKeystoreKit';
import { BusinessError } from "@kit.BasicServicesKit";

/* 1.确定密钥别名 */
let keyAlias = 'test_key';
let isKeyExist: boolean;
/* 2.构造空对象 */
let huksOptions: huks.HuksOptions = {
  properties: []
}
/* 3.初始化密钥属性集 */
let generateProperties: huks.HuksParam[] = [{
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_DH
  }, {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_AGREE
  }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_DH_KEY_SIZE_2048
  }
];
let generateHuksOptions: huks.HuksOptions = {
  properties: generateProperties,
  inData: new Uint8Array([])
}

/* 4.生成密钥 */
async function publicGenKeyFunc(keyAlias: string, huksOptions: huks.HuksOptions): Promise<boolean> {
  console.info(`enter promise generateKeyItem`);
  let ret: boolean = false;
  try {
    await huks.generateKeyItem(keyAlias, huksOptions)
      .then(() => {
        console.info(`promise: generateKeyItem success`);
        ret = true;
      }).catch((error: BusinessError) => {
        console.error(`promise: generateKeyItem failed, errCode : ${error.code}, errMsg : ${error.message}`);
      });
  } catch (error) {
    console.error(`promise: generateKeyItem input arg invalid`);
  }
  return ret;
}

/* 5.查询密钥是否存在 */
async function hasKeyItem(keyAlias: string, huksOptions: huks.HuksOptions): Promise<boolean> {
  console.info(`enter promise hasKeyItem`);
  let ret: boolean = false;
  try {
    await huks.hasKeyItem(keyAlias, huksOptions)
      .then((data) => {
        console.info(`promise: hasKeyItem success, data = ${data}`);
        ret = true;
      }).catch((error: BusinessError) => {
        console.error(`promise: hasKeyItem failed, errCode : ${error.code}, errMsg : ${error.message}`);
      });
    return ret;
  } catch (error) {
    console.error(`promise: hasKeyItem input arg invalid, errCode : ${error.code}, errMsg : ${error.message}`);
  }

  return ret;
}

async function testKeyExist() {
  /* 1.生成密钥 */
  let genResult = await publicGenKeyFunc(keyAlias, generateHuksOptions);
  /* 2.判断密钥是否存在 */
  if (genResult == true) {
    isKeyExist = await hasKeyItem(keyAlias, huksOptions);
    console.info(`hasKeyItem success, isKeyExist = ${isKeyExist}`);
  } else {
    console.error('Key generation failed, skipping query');
  }
}
```