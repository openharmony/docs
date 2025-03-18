# 签名/验签(ArkTS)

当前指导共提供四种示例，供开发者参考完成签名、验签开发：

- [密钥算法为ECC256、摘要算法为SHA256](#ecc256sha256)
- [密钥算法为SM2、摘要算法为SM3](#sm2sm3)
- [密钥算法为RSA、摘要算法为SHA256、填充模式为PSS](#rsasha256pss)
- [密钥算法为RSA、摘要算法为SHA256、填充模式为PKCS1_V1_5](#rsasha256pkcs1_v1_5)

具体的场景介绍及支持的算法规格，请参考[签名/验签支持的算法](huks-signing-signature-verification-overview.md#支持的算法)。

## 开发步骤

**生成密钥**

1. 指定密钥别名。

2. 初始化密钥属性集。

3. 调用[generateKeyItem](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksgeneratekeyitem9)生成密钥，具体请参考[密钥生成](huks-key-generation-overview.md)。

除此之外，开发者也可以参考[密钥导入](huks-key-import-overview.md)，导入已有的密钥。

**签名**

1. 获取密钥别名。

2. 指定待签名的明文数据。

3. 获取属性参数HuksOptions，包括两个字段properties和inData。
   inData传入明文数据，properties传入[算法参数配置](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksparam)。

4. 调用[initSession](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksinitsession9)初始化密钥会话，并获取会话的句柄handle。

5. 调用[finishSession](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksfinishsession9)结束密钥会话，获取签名signature。

**验签**

1. 获取密钥别名。

2. 获取待验证的签名signature。

3. 获取属性参数HuksOptions，包括两个字段properties和inData。
   inData传入签名signature，properties传入[算法参数配置](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksparam)。

4. 调用[initSession](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksinitsession9)初始化密钥会话，并获取会话的句柄handle。

5. 调用[updateSession](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksupdatesession9)更新密钥会话。

6. 调用[finishSession](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksfinishsession9)结束密钥会话，验证签名。

**删除密钥**

当密钥废弃不用时，需要调用[deleteKeyItem](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksdeletekeyitem9)删除密钥，具体请参考[密钥删除](huks-delete-key-arkts.md)。
## 开发案例

### ECC256/SHA256
```ts
/*
 * 密钥算法为ECC256、摘要算法为SHA256
 */
import { huks } from '@kit.UniversalKeystoreKit';

let keyAlias = 'test_eccKeyAlias';
let handle: number;
let plaintext = '123456';
let signature: Uint8Array;

function StringToUint8Array(str: String) {
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

function GetEccGenerateProperties() {
  let properties: Array<huks.HuksParam> = [{
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_ECC
  }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_256
  }, {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_SIGN |
    huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_VERIFY
  }, {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256
  }];
  return properties;
}

function GetEccSignProperties() {
  let properties: Array<huks.HuksParam> = [{
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_ECC
  }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_256
  }, {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_SIGN
  }, {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256
  }];
  return properties;
}

function GetEccVerifyProperties() {
  let properties: Array<huks.HuksParam> = [{
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_ECC
  }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_256
  }, {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_VERIFY
  }, {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256
  }];
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
    }).catch((err: Error) => {
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
    }).catch((err: Error) => {
      console.error(`promise: init sign failed, error: ` + JSON.stringify(err));
    })
  await huks.finishSession(handle, options)
    .then((data) => {
      console.info(`promise: sign success, data is ` + Uint8ArrayToString(data.outData as Uint8Array));
      signature = data.outData as Uint8Array;
    }).catch((err: Error) => {
      console.error(`promise: sign failed, error: ` + JSON.stringify(err));
    })
}

async function Verify(keyAlias: string, plaintext: string, signature: Uint8Array) {
  let verifyProperties = GetEccVerifyProperties()
  let options: huks.HuksOptions = {
    properties: verifyProperties,
    inData: StringToUint8Array(plaintext)
  }
  await huks.initSession(keyAlias, options)
    .then((data) => {
      handle = data.handle;
    }).catch((err: Error) => {
      console.error(`promise: init verify failed, error: ` + JSON.stringify(err));
    })
  await huks.updateSession(handle, options)
    .then((data) => {
      console.info(`promise: update verify success, data is ` + Uint8ArrayToString(data.outData as Uint8Array));
    }).catch((err: Error) => {
      console.error(`promise: update verify failed, error: ` + JSON.stringify(err));
    })
  options.inData = signature;
  await huks.finishSession(handle, options)
    .then((data) => {
      console.info(`promise: verify success, data is ` + Uint8ArrayToString(data.outData as Uint8Array));
    }).catch((err: Error) => {
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
    }).catch((err: Error) => {
      console.error(`promise: delete data failed`);
    })
}

async function testSignVerify() {
  await GenerateEccKey(keyAlias);
  await Sign(keyAlias, plaintext);
  await Verify(keyAlias, plaintext, signature);
  await DeleteEccKey(keyAlias);
}
```
### SM2/SM3
```ts
/*
 * 密钥算法为SM2、摘要算法为SM3
 */
import { huks } from '@kit.UniversalKeystoreKit';

let keyAlias = 'test_sm2KeyAlias';
let handle: number;
let plaintext = '123456';
let signature: Uint8Array;


function StringToUint8Array(str: String) {
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


function GetSm2GenerateProperties() {
  let properties: Array<huks.HuksParam> = [{
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_SM2
  }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_256
  }, {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_SIGN |
    huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_VERIFY
  }, {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_SM3
  }];
  return properties;
}

function GetSm2SignProperties() {
  let properties: Array<huks.HuksParam> = [{
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_SM2
  }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_256
  }, {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_SIGN
  }, {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_SM3
  }];
  return properties;
}

function GetSm2VerifyProperties() {
  let properties: Array<huks.HuksParam> = [{
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_SM2
  }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_256
  }, {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_VERIFY
  }, {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_SM3
  }];
  return properties;
}

async function GenerateSm2Key(keyAlias: string) {
  let genProperties = GetSm2GenerateProperties();
  let options: huks.HuksOptions = {
    properties: genProperties
  }
  await huks.generateKeyItem(keyAlias, options)
    .then((data) => {
      console.info(`promise: generate Sm2 Key success, data = ${JSON.stringify(data)}`);
    }).catch((err: Error) => {
      console.error(`promise: generate Sm2 Key failed, error: ` + JSON.stringify(err));
    })
}

async function Sign(keyAlias: string, plaintext: string) {
  let signProperties = GetSm2SignProperties();
  let options: huks.HuksOptions = {
    properties: signProperties,
    inData: StringToUint8Array(plaintext)
  }
  await huks.initSession(keyAlias, options)
    .then((data) => {
      handle = data.handle;
    }).catch((err: Error) => {
      console.error(`promise: init sign failed, error: ` + JSON.stringify(err));
    })
  await huks.finishSession(handle, options)
    .then((data) => {
      console.info(`promise: sign success, data is ` + Uint8ArrayToString(data.outData as Uint8Array));
      signature = data.outData as Uint8Array;
    }).catch((err: Error) => {
      console.error(`promise: sign failed, error: ` + JSON.stringify(err));
    })
}

async function Verify(keyAlias: string, plaintext: string, signature: Uint8Array) {
  let verifyProperties = GetSm2VerifyProperties()
  let options: huks.HuksOptions = {
    properties: verifyProperties,
    inData: StringToUint8Array(plaintext)
  }
  await huks.initSession(keyAlias, options)
    .then((data) => {
      handle = data.handle;
    }).catch((err: Error) => {
      console.error(`promise: init verify failed, error: ` + JSON.stringify(err));
    })
  await huks.updateSession(handle, options)
    .then((data) => {
      console.info(`promise: update verify success, data is ` + Uint8ArrayToString(data.outData as Uint8Array));
    }).catch((err: Error) => {
      console.error(`promise: update verify failed, error: ` + JSON.stringify(err));
    })
  options.inData = signature;
  await huks.finishSession(handle, options)
    .then((data) => {
      console.info(`promise: verify success, data is ` + Uint8ArrayToString(data.outData as Uint8Array));
    }).catch((err: Error) => {
      console.error(`promise: verify failed, error: ` + JSON.stringify(err));
    })
}

async function DeleteSm2Key(keyAlias: string) {
  let emptyOptions: huks.HuksOptions = {
    properties: []
  }
  await huks.deleteKeyItem(keyAlias, emptyOptions)
    .then((data) => {
      console.info(`promise: delete data success`);
    }).catch((err: Error) => {
      console.error(`promise: delete data failed`);
    })
}

export async function testSignVerify() {
  await GenerateSm2Key(keyAlias);
  await Sign(keyAlias, plaintext);
  await Verify(keyAlias, plaintext, signature);
  await DeleteSm2Key(keyAlias);
}
```
### RSA/SHA256/PSS
```ts
/*
 * 密钥算法为RSA，摘要算法为SHA256，填充模式为PSS
 */
import { huks } from '@kit.UniversalKeystoreKit';

let keyAlias = 'test_rsaKeyAlias';
let handle: number;
let plaintext = '123456';
let signature: Uint8Array;

function StringToUint8Array(str: string) {
  let arr: number[] = [];
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

function GetRsaGenerateProperties() {
  let properties: Array<huks.HuksParam> = [{
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_RSA
  }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_RSA_KEY_SIZE_2048
  }, {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_SIGN |
    huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_VERIFY
  }, {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_PSS
  }, {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256
  }];
  return properties;
}

function GetRsaSignProperties() {
  let properties: Array<huks.HuksParam> = [{
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_RSA
  }, {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_PSS
  }, {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256
  }, {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_SIGN
  }];
  return properties;
}

function GetRsaVerifyProperties() {
  let properties: Array<huks.HuksParam> = [{
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_RSA
  }, {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_PSS
  }, {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256
  }, {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_VERIFY
  }];
  return properties;
}

async function GenerateRsaKey(keyAlias: string) {
  let genProperties = GetRsaGenerateProperties();
  let options: huks.HuksOptions = {
    properties: genProperties
  };
  await huks.generateKeyItem(keyAlias, options)
    .then((data) => {
      console.info(`promise: generate RSA Key success, data = ${JSON.stringify(data)}`);
    }).catch((err: Error) => {
      console.error(`promise: generate RSA Key failed, error: ` + JSON.stringify(err));
    });
}

async function Sign(keyAlias: string, plaintext: string) {
  let signProperties = GetRsaSignProperties();
  let options: huks.HuksOptions = {
    properties: signProperties,
    inData: StringToUint8Array(plaintext)
  }
  await huks.initSession(keyAlias, options)
    .then((data) => {
      handle = data.handle;
    }).catch((err: Error) => {
      console.error(`promise: init sign failed, error: ` + JSON.stringify(err));
      return;
    });

  if (handle !== undefined) {
    await huks.finishSession(handle, options)
      .then((data) => {
        console.info(`promise: sign success, data is ` + Uint8ArrayToString(data.outData as Uint8Array));
        signature = data.outData as Uint8Array;
      }).catch((err: Error) => {
        console.error(`promise: sign failed, error: ` + JSON.stringify(err));
      });
  }
}

async function Verify(keyAlias: string, plaintext: string, signature: Uint8Array) {
  let verifyProperties = GetRsaVerifyProperties();
  let options: huks.HuksOptions = {
    properties: verifyProperties,
    inData: StringToUint8Array(plaintext)
  }
  await huks.initSession(keyAlias, options)
    .then((data) => {
      handle = data.handle;
    }).catch((err: Error) => {
      console.error(`promise: init verify failed, error: ` + JSON.stringify(err));
      return;
    });

  if (handle !== undefined) {
    await huks.updateSession(handle, options)
      .then((data) => {
        console.info(`promise: update verify success, data is ` + Uint8ArrayToString(data.outData as Uint8Array));
      }).catch((err: Error) => {
        console.error(`promise: update verify failed, error: ` + JSON.stringify(err));
      });

    options.inData = signature;
    await huks.finishSession(handle, options)
      .then((data) => {
        console.info(`promise: verify success, data is ` + Uint8ArrayToString(data.outData as Uint8Array));
      }).catch((err: Error) => {
        console.error(`promise: verify failed, error: ` + JSON.stringify(err));
      });
  }
}

async function DeleteRsaKey(keyAlias: string) {
  let emptyOptions: huks.HuksOptions = {
    properties: []
  }
  await huks.deleteKeyItem(keyAlias, emptyOptions)
    .then((data) => {
      console.info(`promise: delete data success`);
    }).catch((err: Error) => {
      console.error(`promise: delete data failed`);
    });
}

export async function testSignVerify() {
  await GenerateRsaKey(keyAlias);
  await Sign(keyAlias, plaintext);
  await Verify(keyAlias, plaintext, signature);
  await DeleteRsaKey(keyAlias);
}
```
### RSA/SHA256/PKCS1_V1_5
```ts
/*
 * 密钥算法为RSA，摘要算法为SHA256，填充模式为PKCS1_V1_5
 */
import { huks } from '@kit.UniversalKeystoreKit';

let keyAlias = 'test_rsaKeyAlias';
let handle: number;
let plaintext = '123456';
let signature: Uint8Array;

function StringToUint8Array(str: String) {
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

function GetRsaGenerateProperties() {
  let properties: Array<huks.HuksParam> = [
    { tag: huks.HuksTag.HUKS_TAG_ALGORITHM, value: huks.HuksKeyAlg.HUKS_ALG_RSA },
    { tag: huks.HuksTag.HUKS_TAG_KEY_SIZE, value: huks.HuksKeySize.HUKS_RSA_KEY_SIZE_2048 },
    {
      tag: huks.HuksTag.HUKS_TAG_PURPOSE,
      value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_SIGN | huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_VERIFY
    },
    { tag: huks.HuksTag.HUKS_TAG_PADDING, value: huks.HuksKeyPadding.HUKS_PADDING_PKCS1_V1_5 },
    { tag: huks.HuksTag.HUKS_TAG_DIGEST, value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256 }
  ];
  return properties;
}

function GetRsaSignProperties() {
  let properties: Array<huks.HuksParam> = [{
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_RSA
  }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_RSA_KEY_SIZE_2048
  }, {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_SIGN
  }, {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_PKCS1_V1_5
  }, {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256
  }];
  return properties;
}

function GetRsaVerifyProperties() {
  let properties: Array<huks.HuksParam> = [{
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_RSA
  }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_RSA_KEY_SIZE_2048
  }, {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_VERIFY
  }, {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_PKCS1_V1_5
  }, {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256
  }];
  return properties;
}

async function GenerateRsaKey(keyAlias: string) {
  let genProperties = GetRsaGenerateProperties();
  let options: huks.HuksOptions = {
    properties: genProperties
  }
  await huks.generateKeyItem(keyAlias, options)
    .then((data) => {
      console.info(`promise: generate RSA Key success, data = ${JSON.stringify(data)}`);
    }).catch((err: Error) => {
      console.error(`promise: generate RSA Key failed, error: ` + JSON.stringify(err));
    })
}

async function Sign(keyAlias: string, plaintext: string) {
  let signProperties = GetRsaSignProperties();
  let options: huks.HuksOptions = {
    properties: signProperties,
    inData: StringToUint8Array(plaintext)
  }
  await huks.initSession(keyAlias, options)
    .then((data) => {
      handle = data.handle;
    }).catch((err: Error) => {
      console.error(`promise: init sign failed, error: ` + JSON.stringify(err));
    })
  await huks.finishSession(handle, options)
    .then((data) => {
      console.info(`promise: sign success, data is ` + Uint8ArrayToString(data.outData as Uint8Array));
      signature = data.outData as Uint8Array;
    }).catch((err: Error) => {
      console.error(`promise: sign failed, error: ` + JSON.stringify(err));
    })
}

async function Verify(keyAlias: string, plaintext: string, signature: Uint8Array) {
  let verifyProperties = GetRsaVerifyProperties()
  let options: huks.HuksOptions = {
    properties: verifyProperties,
    inData: StringToUint8Array(plaintext)
  }
  await huks.initSession(keyAlias, options)
    .then((data) => {
      handle = data.handle;
    }).catch((err: Error) => {
      console.error(`promise: init verify failed, error: ` + JSON.stringify(err));
    })
  await huks.updateSession(handle, options)
    .then((data) => {
      console.info(`promise: update verify success, data is ` + Uint8ArrayToString(data.outData as Uint8Array));
    }).catch((err: Error) => {
      console.error(`promise: update verify failed, error: ` + JSON.stringify(err));
    })
  options.inData = signature;
  await huks.finishSession(handle, options)
    .then((data) => {
      console.info(`promise: verify success, data is ` + Uint8ArrayToString(data.outData as Uint8Array));
    }).catch((err: Error) => {
      console.error(`promise: verify failed, error: ` + JSON.stringify(err));
    })
}

async function DeleteRsaKey(keyAlias: string) {
  let emptyOptions: huks.HuksOptions = {
    properties: []
  }
  await huks.deleteKeyItem(keyAlias, emptyOptions)
    .then((data) => {
      console.info(`promise: delete data success`);
    }).catch((err: Error) => {
      console.error(`promise: delete data failed`);
    })
}

export async function testSignVerify() {
  await GenerateRsaKey(keyAlias);
  await Sign(keyAlias, plaintext);
  await Verify(keyAlias, plaintext, signature);
  await DeleteRsaKey(keyAlias);
}
```