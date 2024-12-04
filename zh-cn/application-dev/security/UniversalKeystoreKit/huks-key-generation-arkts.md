# 生成密钥(ArkTS)


以生成DH密钥为例，生成随机密钥。具体的场景介绍及支持的算法规格，请参考[密钥生成支持的算法](huks-key-generation-overview.md#支持的算法)。

> **注意：**
> 密钥别名中禁止包含个人数据等敏感信息。

## 开发步骤

1. 指定待生成的密钥别名keyAlias。
   - 密钥别名的最大长度为128字节。
   - 对于不同业务间生成的密钥，HUKS将基于业务身份信息进行存储路径隔离，不会因为和其他业务密钥同名导致冲突。

2. 初始化密钥属性集。通过[HuksParam](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksparam)封装密钥属性，搭配Array组成密钥属性集，并赋值给[HuksOptions](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksoptions)中的properties字段。
   密钥属性集中必须包含[HuksKeyAlg](../../reference/apis-universal-keystore-kit/js-apis-huks.md#hukskeyalg)、[HuksKeySize](../../reference/apis-universal-keystore-kit/js-apis-huks.md#hukskeysize)、[HuksKeyPurpose](../../reference/apis-universal-keystore-kit/js-apis-huks.md#hukskeypurpose)属性，即必传TAG，HUKS_TAG_ALGORITHM、HUKS_TAG_PURPOSE、HUKS_TAG_KEY_SIZE。

3. 调用[huks.generateKeyItem](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksgeneratekeyitem9)，传入密钥别名和密钥属性集，生成密钥。

> **说明：**
> 如果业务再次使用相同别名调用HUKS生成密钥，HUKS将生成新密钥并直接覆盖历史的密钥文件。


```ts
/* 以下以生成DH密钥为例 */
import { huks } from '@kit.UniversalKeystoreKit';

/* 1.确定密钥别名 */
let keyAlias = 'dh_key';
/* 2.初始化密钥属性集 */
let properties1: Array<huks.HuksParam> = [
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
  inData: new Uint8Array(new Array())
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

async function publicGenKeyFunc(keyAlias: string, huksOptions: huks.HuksOptions) {
  console.info(`enter promise generateKeyItem`);
  try {
    await generateKeyItem(keyAlias, huksOptions)
      .then((data) => {
        console.info(`promise: generateKeyItem success, data = ${JSON.stringify(data)}`);
      })
      .catch((error: Error) => {
        console.error(`promise: generateKeyItem failed, ${JSON.stringify(error)}`);
      });
  } catch (error) {
    console.error(`promise: generateKeyItem input arg invalid, ` + JSON.stringify(error));
  }
}

async function TestGenKey() {
  await publicGenKeyFunc(keyAlias, huksOptions);
}
```
