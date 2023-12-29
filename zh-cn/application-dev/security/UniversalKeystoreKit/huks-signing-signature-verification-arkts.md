# 签名/验签(ArkTS)


以密钥算法为ECC256、摘要算法为SHA256的密钥为例，完成签名、验签。具体的场景介绍及支持的算法规格，请参考[签名/验签支持的算法](huks-signing-signature-verification-overview.md#支持的算法)。


## 开发步骤

**生成密钥**

1. 指定密钥别名。

2. 初始化密钥属性集。

3. 调用[generateKeyItem](../../reference/apis/js-apis-huks.md#huksgeneratekeyitem9)生成密钥，具体请参考[密钥生成](huks-key-generation-overview.md)。

除此之外，开发者也可以参考[密钥导入](huks-key-import-overview.md)，导入已有的密钥。

**签名**

1. 获取密钥别名。

2. 指定待签名的明文数据。

3. 获取属性参数HuksOptions，包括两个字段properties和inData。
   inData传入明文数据，properties传入[算法参数配置](../../reference/apis/js-apis-huks.md#huksparam)。

4. 调用[initSession](../../reference/apis/js-apis-huks.md#huksinitsession9)初始化密钥会话，并获取会话的句柄handle。

5. 调用[finishSession](../../reference/apis/js-apis-huks.md#huksfinishsession9)结束密钥会话，获取签名signature。

**验签**

1. 获取密钥别名。

2. 获取待验证的签名signature。

3. 获取属性参数HuksOptions，包括两个字段properties和inData。
   inData传入签名signature，properties传入[算法参数配置](../../reference/apis/js-apis-huks.md#huksparam)。

4. 调用[initSession](../../reference/apis/js-apis-huks.md#huksinitsession9)初始化密钥会话，并获取会话的句柄handle。

5. 调用[updateSession](../../reference/apis/js-apis-huks.md#huksupdatesession9)更新密钥会话。

6. 调用[finishSession](../../reference/apis/js-apis-huks.md#huksfinishsession9)结束密钥会话，验证签名。

**删除密钥**

当密钥废弃不用时，需要调用[deleteKeyItem](../../reference/apis/js-apis-huks.md#huksdeletekeyitem9)删除密钥，具体请参考[密钥删除](huks-delete-key-arkts.md)。

```ts
/*
 * 以ECC 256 DIGEST SHA256密钥的Promise操作使用为例
 */
import huks from '@ohos.security.huks';
import { BusinessError } from '@ohos.base';
let keyAlias = 'test_eccKeyAlias';
let handle: number;
let plaintext = '123456';
let signature: Uint8Array;
function StringToUint8Array(str: String) {
  let arr:number[]=new Array();
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
function GetEccGenerateProperties() {
  let properties: Array<huks.HuksParam> = new Array();
  let index = 0;
  properties[index++] = {
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_ECC
  };
  properties[index++] = {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_256
  };
  properties[index++] = {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_SIGN |
    huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_VERIFY
  };
  properties[index++] = {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256
  }
  return properties;
}
function GetEccSignProperties() {
  let properties: Array<huks.HuksParam> = new Array();
  let index = 0;
  properties[index++] = {
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_ECC
  };
  properties[index++] = {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_256
  };
  properties[index++] = {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_SIGN
  };
  properties[index++] = {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256
  }
  return properties;
}
function GetEccVerifyProperties() {
  let properties: Array<huks.HuksParam> = new Array();
  let index = 0;
  properties[index++] = {
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_ECC
  };
  properties[index++] = {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_256
  };
  properties[index++] = {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_VERIFY
  };
  properties[index++] = {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256
  }
  return properties;
}
async function GenerateEccKey(keyAlias: string) {
  let genProperties = GetEccGenerateProperties();
  let options: huks.HuksOptions = {
    properties: genProperties
  }
  await huks.generateKeyItem(keyAlias, options)
    .then((data) => {
      console.info(`promise: generate ECC Key success, data = ${JSON.stringify(data)}`);
    }).catch((err: BusinessError)=>{
      console.error(`promise: generate ECC Key failed, error: ` + JSON.stringify(err));
    })
}
async function Sign(keyAlias: string, plaintext: string) {
  let signProperties = GetEccSignProperties();
  let options: huks.HuksOptions = {
    properties: signProperties,
    inData: StringToUint8Array(plaintext)
  }
  await huks.initSession(keyAlias, options)
    .then((data) => {
      handle = data.handle;
    }).catch((err: BusinessError)=>{
      console.error(`promise: init sign failed, error: ` + JSON.stringify(err));
    })
  await huks.finishSession(handle, options)
    .then((data) => {
      console.info(`promise: sign success, data is `+ Uint8ArrayToString(data.outData as Uint8Array));
      signature = data.outData as Uint8Array;
    }).catch((err: BusinessError)=>{
      console.error(`promise: sign failed, error: ` + JSON.stringify(err));
    })
}
async function Verify(keyAlias: string, signature: Uint8Array) {
  let verifyProperties = GetEccVerifyProperties()
  let options: huks.HuksOptions = {
    properties: verifyProperties,
    inData: signature
  }
  await huks.initSession(keyAlias, options)
    .then((data) => {
      handle = data.handle;
    }).catch((err: BusinessError)=>{
      console.error(`promise: init verify failed, error: ` + JSON.stringify(err));
    })
  await huks.updateSession(handle, options)
    .then((data) => {
      console.info(`promise: update verify success, data is ` + Uint8ArrayToString(data.outData as Uint8Array));
    }).catch((err: BusinessError)=>{
      console.error(`promise: update verify failed, error: ` + JSON.stringify(err));
    })
  await huks.finishSession(handle, options)
    .then((data) => {
      console.info(`promise: verify success, data is ` + Uint8ArrayToString(data.outData as Uint8Array));
    }).catch((err: BusinessError)=>{
      console.error(`promise: verify failed, error: ` + JSON.stringify(err));
    })
}
async function DeleteEccKey(keyAlias: string) {
  let emptyOptions: huks.HuksOptions = {
    properties: []
  }
  await huks.deleteKeyItem(keyAlias, emptyOptions)
    .then((data) => {
      console.info(`promise: delete data success`);
    }).catch((err: BusinessError)=>{
      console.error(`promise: delete data failed`);
    })
}
async function testSignVerify() {
  await GenerateEccKey(keyAlias);
  await Sign(keyAlias, plaintext);
  await Verify(keyAlias, signature);
  await DeleteEccKey(keyAlias);
}
```
