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
/* 1.确定密钥别名 */
let keyAlias = 'test_key';
let isKeyExist: Boolean;
/* 2.构造空对象 */
let huksOptions: huks.HuksOptions = {
  properties: []
}
/* 3.初始化密钥属性集 */
let generateProperties: huks.HuksParam[] = [
  {
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_DH
  },
  {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_AGREE
  },
  {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_DH_KEY_SIZE_2048
  }
];
let generateHuksOptions: huks.HuksOptions = {
  properties: generateProperties,
  inData: new Uint8Array([])
}
/* 3.生成密钥 */
function generateKeyItem(keyAlias: string, huksOptions: huks.HuksOptions) {
  return new Promise<void>((resolve, reject) => {
    try {
      huks.generateKeyItem(keyAlias, huksOptions, (error, data) => {
        if (error) {
          reject(error);
        } else {
          resolve(data);
        }
      });
    } catch (error) {
      throw (error as Error);
    }
  });
}
async function publicGenKeyFunc(keyAlias: string, huksOptions: huks.HuksOptions): Promise<string> {
  console.info(`enter promise generateKeyItem`);
  try {
    await generateKeyItem(keyAlias, huksOptions)
      .then((data) => {
        console.info(`promise: generateKeyItem success, data = ${JSON.stringify(data)}`);
      })
      .catch((error: Error) => {
        console.error(`promise: generateKeyItem failed, ${JSON.stringify(error)}`);
      });
    return 'Success';
  } catch (error) {
    console.error(`promise: generateKeyItem input arg invalid, ` + JSON.stringify(error));
    return 'Failed';
  }
}
async function testGenKey(): Promise<string> {
  let ret = await publicGenKeyFunc(keyAlias, generateHuksOptions);
  return ret;
}
/* 查询密钥是否存在 */
function hasKeyItem(keyAlias: string, huksOptions: huks.HuksOptions) {
  return new Promise<boolean>((resolve, reject) => {
    try {
      huks.hasKeyItem(keyAlias, huksOptions, (error, data) => {
        if (error) {
          reject(error);
        } else {
          if (data !== null && data.valueOf() !== null) {
            resolve(data.valueOf());
          } else {
            resolve(false);
          }
        }
      });
    } catch (error) {
      throw (error as Error);
    }
  });
}
async function check(): Promise<string> {
  try {
    /* 1.生成密钥 */
    let genResult = await testGenKey();
    /* 2.判断密钥是否存在 */
    if (genResult === 'Success') {
      isKeyExist = await hasKeyItem(keyAlias, huksOptions);
      console.info(`callback: hasKeyItem success, isKeyExist = ${isKeyExist}`);
    } else {
      console.error('Key generation failed, skipping query');
      return 'Failed';
    }
    return 'Success';
  } catch (error) {
    console.error(`callback: hasKeyItem input arg invalid, ` + JSON.stringify(error));
    return 'Failed';
  }
}
```
