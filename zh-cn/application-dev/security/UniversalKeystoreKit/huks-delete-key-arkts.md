# 密钥删除(ArkTS)

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--SE: @HighLowWorld-->
<!--TSE: @wxy1234564846-->

为保证数据安全性，当不需要使用该密钥时，应该删除密钥。

## 开发步骤

以删除HKDF256密钥为例。

1. 确定密钥别名keyAlias，密钥别名最大长度为128字节。

2. 初始化密钥属性集。用于删除时指定[密钥的属性TAG](../../reference/apis-universal-keystore-kit/capi-native-huks-type-h.md#oh_huks_tag)，当删除单个时，TAG字段可传空。

3. 调用接口[deleteKeyItem](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksdeletekeyitem9)，删除密钥。

```ts
/*
 * 以下以HKDF256密钥的Promise操作使用为例
 */
import { huks } from '@kit.UniversalKeystoreKit';
/* 1.确定密钥别名 */
let keyAlias = 'test_Key';
/* 2.初始化密钥属性集 */
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
    console.error(`promise: generateKeyItem input arg invalid, ${JSON.stringify(error)}`);
    return 'Failed';
  }
}
async function testGenKey(): Promise<string> {
  let ret = await publicGenKeyFunc(keyAlias, generateHuksOptions);
  return ret;
}
let deleteHuksOptions: huks.HuksOptions = {
  properties: []
}
class ThrowObject {
  public isThrow = false;
}
/* 4.删除密钥 */
function deleteKeyItem(keyAlias: string, huksOptions: huks.HuksOptions, throwObject: ThrowObject) {
  return new Promise<void>((resolve, reject) => {
    try {
      huks.deleteKeyItem(keyAlias, huksOptions, (error, data) => {
        if (error) {
          reject(error);
        } else {
          resolve(data);
        }
      });
    } catch (error) {
      throwObject.isThrow = true;
      throw (error as Error);
    }
  });
}
async function publicDeleteKeyFunc(keyAlias: string, huksOptions: huks.HuksOptions): Promise<string> {
  console.info(`enter promise deleteKeyItem`);
  let throwObject: ThrowObject = { isThrow: false };
  try {
    await testGenKey();
    await deleteKeyItem(keyAlias, huksOptions, throwObject)
      .then((data) => {
        console.info(`promise: deleteKeyItem key success, data = ${JSON.stringify(data)}`);
      })
      .catch((error: Error) => {
        if (throwObject.isThrow) {
          throw (error as Error);
        } else {
          console.error(`promise: deleteKeyItem failed, ${JSON.stringify(error)}`);
        }
      });
    return 'Success';
  } catch (error) {
    console.error(`promise: deleteKeyItem input arg invalid, ${JSON.stringify(error)}`);
    return 'Failed';
  }
}
async function testDerive(): Promise<string> {
  let ret = await publicDeleteKeyFunc(keyAlias, deleteHuksOptions);
  return ret;
}
```
