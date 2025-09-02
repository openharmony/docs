# HMAC(ArkTS)

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->

HMAC是密钥相关的哈希运算消息认证码（Hash-based Message Authentication Code）。具体的场景介绍及支持的算法规格，请参考[HMAC介绍及算法规格](huks-hmac-overview.md)。

## 开发步骤

**生成密钥**

1. 指定密钥别名，密钥别名命名规范参考[密钥生成介绍及算法规格](huks-key-generation-overview.md)。

2. 初始化密钥属性集。

3. 调用[generateKeyItem](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksgeneratekeyitem9)生成密钥，HMAC支持的规格请参考[密钥生成支持的算法](huks-key-generation-overview.md#支持的算法)。

除此之外，开发者也可以参考[密钥导入](huks-key-import-overview.md#支持的算法)的规格介绍，导入已有的密钥。

**执行HMAC**

1. 获取密钥别名。

2. 获取待运算的数据。

3. 调用[initSession](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksinitsession9)初始化密钥会话，并获取会话的句柄handle。

4. 调用[finishSession](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksfinishsession9)结束密钥会话，获取哈希后的数据。

```ts
/*
 * 以下以HMAC密钥的Promise操作使用为例
 */
import { huks } from '@kit.UniversalKeystoreKit';

let keyAlias = 'test_HMAC';
let handle: number;
let plainText = '123456';
let hashData: Uint8Array;

function StringToUint8Array(str: string) {
  let arr: number[] = new Array();
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

function GetHMACProperties() {
  const properties: Array<huks.HuksParam> = [{
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_HMAC
  }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_256
  }, {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_MAC
  }, {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_SHA384,
  }];
  return properties;
}

async function GenerateHMACKey() {
  /*
  * 模拟生成密钥场景
  * 1. 确定密钥别名
  */
  /*
  * 2. 获取生成密钥算法参数配置
  */
  let genProperties = GetHMACProperties();
  let options: huks.HuksOptions = {
    properties: genProperties
  }
  /*
  * 3. 调用generateKeyItem
  */
  await huks.generateKeyItem(keyAlias, options)
    .then((data) => {
      console.info(`promise: generate HMAC Key success`);
    }).catch((error: Error) => {
      console.error(`promise: generate HMAC Key failed, ${JSON.stringify(error)}`);
    })
}

async function HMACData() {
  /*
  * 模拟HMAC场景
  * 1. 获取密钥别名
  */
  /*
  * 2. 获取待哈希的数据
  */
  /*
  * 3. 获取HMAC算法参数配置
  */
  let hmacProperties = GetHMACProperties();
  let options: huks.HuksOptions = {
    properties: hmacProperties,
    inData: StringToUint8Array(plainText)
  }
  /*
  * 4. 调用initSession获取handle
  */
  await huks.initSession(keyAlias, options)
    .then((data) => {
      handle = data.handle;
    }).catch((error: Error) => {
      console.error(`promise: init EncryptData failed, ${JSON.stringify(error)}`);
    })
  /*
  * 5. 调用finishSession获取HMAC的结果
  */
  await huks.finishSession(handle, options)
    .then((data) => {
      console.info(`promise: HMAC data success, data is ` + Uint8ArrayToString(data.outData as Uint8Array));
      hashData = data.outData as Uint8Array;
    }).catch((error: Error) => {
      console.error(`promise: HMAC data failed, ${JSON.stringify(error)}`);
    })
}
```
