# 密钥导出(ArkTS)

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->

业务需要获取持久化存储的非对称密钥的公钥时使用，当前支持ECC/RSA/ED25519/X25519/SM2的公钥导出。
>**说明：**
> <!--RP1-->轻量级设备<!--RP1End-->仅支持RSA公钥导出。

## 开发步骤

1. 指定密钥别名，密钥别名命名规范参考[密钥生成介绍及算法规格](huks-key-generation-overview.md)。

2. 调用接口[exportKeyItem](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksexportkeyitem9)，传入参数keyAlias和options。options为预留参数，当前可传入空。

3. 返回值为[HuksReturnResult](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksreturnresult9)类型对象，获取的公钥明文在outData字段中，以标准的X.509规范的DER格式封装，具体请参考[公钥材料格式](huks-concepts.md#公钥材料格式)。

```ts
import { huks } from '@kit.UniversalKeystoreKit';
import { BusinessError } from "@kit.BasicServicesKit";

/* 1. 设置密钥别名 */
let keyAlias = 'keyAlias';
/* option对象传空 */
let emptyOptions: huks.HuksOptions = {
  properties: []
};
/* 2. 设置密钥属性 */
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
async function generateKeyItem(keyAlias: string, huksOptions: huks.HuksOptions): Promise<string> {
  console.info(`enter promise generateKeyItem`);
  let ret: string = 'Success';
  try {
    await huks.generateKeyItem(keyAlias, huksOptions)
      .then(() => {
        console.info(`promise: generateKeyItem success`);
      }).catch((error: BusinessError) => {
        console.error(`promise: generateKeyItem failed, errCode : ${error.code}, errMag : ${error.message}`);
        ret = 'Failed';
      });
  } catch (error) {
    console.error(`promise: generateKeyItem input arg invalid`);
    ret = 'Failed';
  }
  return ret;
}

/* 4.导出密钥 */
async function exportKeyItem(keyAlias: string, emptyOptions: huks.HuksOptions) {
  console.info(`enter promise exportKeyItem`);
  let ret: string = 'Success';
  try {
    await huks.exportKeyItem(keyAlias, emptyOptions)
      .then((data) => {
        console.info(`promise: exportKeyItem success, data = ${data}`);
      }).catch((error: BusinessError) => {
        console.error(`promise: exportKeyItem failed, errCode : ${error.code}, errMag : ${error.message}`);
        ret = 'Failed';
      });
  } catch (error) {
    console.error(`promise: exportKeyItem input arg invalid`);
    ret = 'Failed';
  }
  return ret;
}

async function testExportKeyItem() {
  let retGen = await generateKeyItem(keyAlias, huksOptions);
  if (retGen == 'Failed') {
    console.error(`generateKeyItem failed`);
    return;
  }

  let retExp = await exportKeyItem(keyAlias, emptyOptions);
  if (retExp == 'Failed') {
    console.error(`exportKeyItem failed`);
    return;
  }

  console.info(`testExportKeyItem success`);
}
```