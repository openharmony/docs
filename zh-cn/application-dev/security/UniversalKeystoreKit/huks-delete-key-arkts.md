# 密钥删除(ArkTS)

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->

为保证数据安全性，当不需要使用该密钥时，应该删除密钥。

## 开发步骤

以删除HKDF256密钥为例。

1. 指定密钥别名，密钥别名命名规范参考[密钥生成介绍及算法规格](huks-key-generation-overview.md)。

2. 初始化密钥属性集。用于删除时指定[密钥的属性TAG](../../reference/apis-universal-keystore-kit/js-apis-huks.md#hukstag)，当删除单个时，TAG字段可传空。

3. 调用接口[deleteKeyItem](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksdeletekeyitem9)，删除密钥。

```ts
/*
 * 以下以HKDF256密钥的Promise操作使用为例
 */
import { huks } from '@kit.UniversalKeystoreKit';
import { BusinessError } from "@kit.BasicServicesKit";

/* 1.确定密钥别名 */
let keyAlias = 'test_Key';
/* 2.初始化密钥属性集 */
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
let deleteHuksOptions: huks.HuksOptions = {
  properties: []
}

/* 3.生成密钥 */
async function generateKeyItem(keyAlias: string, huksOptions: huks.HuksOptions): Promise<boolean> {
  console.info(`enter promise generateKeyItem`);
  let ret: boolean = false;
  try {
    await huks.generateKeyItem(keyAlias, huksOptions)
      .then(() => {
        console.info(`promise: generateKeyItem success`);
        ret = true;
      }).catch((error: BusinessError) => {
        console.error(`promise: generateKeyItem failed, errCode : ${error.code}, errMag : ${error.message}`);
      });
  } catch (error) {
    console.error(`promise: generateKeyItem input arg invalid`);
  }
  return ret;
}

/* 4.删除密钥 */
async function deleteKeyItem(keyAlias: string, huksOptions: huks.HuksOptions): Promise<boolean> {
  console.info(`enter promise deleteKeyItem`);
  let ret: boolean = false;
  try {
    await huks.deleteKeyItem(keyAlias, huksOptions)
      .then(() => {
        console.info(`promise: deleteKeyItem success`);
        ret = true;
      }).catch((error: BusinessError) => {
        console.error(`promise: deleteKeyItem failed, errCode : ${error.code}, errMag : ${error.message}`);
      })
  } catch (error) {
    console.error(`promise: deleteKeyItem input arg invalid`);
  }
  return ret;
}

async function testDelete() {
  let retGen = await generateKeyItem(keyAlias, generateHuksOptions);
  if (retGen == false) {
    console.error(`generateKeyItem failed`);
    return;
  }

  let retDel = await deleteKeyItem(keyAlias, deleteHuksOptions);
  if (retDel == false) {
    console.error(`deleteKeyItem failed`);
    return;
  }

  console.info(`deleteKeyItem test success`);
}
```