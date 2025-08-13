# 获取密钥属性(ArkTS)

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--SE: @HighLowWorld-->
<!--TSE: @wxy1234564846-->

HUKS提供了接口供业务获取指定密钥的相关属性。在获取指定密钥属性前，需要确保已在HUKS中生成或导入持久化存储的密钥。
>**说明：**
> 轻量级设备不支持获取密钥属性功能。

## 开发步骤

1. 指定待查询的密钥别名keyAlias，密钥别名最大长度为128字节。

2. 调用接口[getKeyItemProperties](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksgetkeyitemproperties9)，传入参数keyAlias和options。options为预留参数，当前可传入空。

3. 返回值为[HuksReturnResult](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksreturnresult9)类型对象，获取的属性集在properties字段中。

```ts
import { huks } from '@kit.UniversalKeystoreKit';
/* 1. 设置密钥别名 */
let keyAlias = 'keyAlias';
/* 2. 设置密钥属性 */
let emptyOptions: huks.HuksOptions = {
  properties: []
};
let properties1: huks.HuksParam[] = [
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
let huksOptions: huks.HuksOptions = {
  properties: properties1,
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
    console.error(`promise: generateKeyItem input arg invalid, ${JSON.stringify(error)}`);
    return 'Failed';
  }
}
async function testGenKey(): Promise<string> {
  let ret = await publicGenKeyFunc(keyAlias, huksOptions);
  return ret;
}
/* 获取密钥属性 */
function getKeyItemProperties(keyAlias: string, emptyOptions: huks.HuksOptions) {
  return new Promise<huks.HuksReturnResult>((resolve, reject) => {
    try {
      huks.getKeyItemProperties(keyAlias, emptyOptions, (error, data) => {
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
async function check(): Promise<string> {
  try {
    /* 1. 生成密钥 */
    let genResult = await testGenKey();
    /* 2. 获取密钥属性 */
    if (genResult === 'Success') {
      let data = await getKeyItemProperties(keyAlias, emptyOptions);
      console.info(`callback: getKeyItemProperties success, data = ${JSON.stringify(data)}`);
    } else {
      console.error('Key generation failed, skipping get properties');
      return 'Failed';
    }
    return 'Success';
  } catch (error) {
    console.error(`callback: getKeyItemProperties input arg invalid, ${JSON.stringify(error)}`);
    return 'Failed';
  }
}
```
