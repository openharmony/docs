# Signing and Signature Verification (ArkTS)


This topic walks you through on how to implement signing and signature verification using the key algorithm ECC256 and MD algorithm SHA256. For details about the scenarios and supported algorithms, see [Supported Algorithms](huks-signing-signature-verification-overview.md#supported-algorithms).


## How to Develop

**Key Generation**

1. Set the key alias.

2. Initialize the key property set.

3. Use [generateKeyItem](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksgeneratekeyitem9) to generate a key. For details, see [Key Generation](huks-key-generation-overview.md).

Alternatively, you can [import a key](huks-key-import-overview.md).

**Signing**

1. Obtain the key alias.

2. Obtain the plaintext to be signed.

3. Obtain **HuksOptions**, which include the **properties** and **inData** fields.
   Pass in the plaintext to be signed in **inData**, and [algorithm parameters](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksparam) in **properties**.

4. Use [initSession](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksinitsession9) to initialize a key session. The session handle is returned after the initialization.

5. Use [finishSession](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksfinishsession9) to generate a signature.

**Signature Verification**

1. Obtain the key alias.

2. Obtain the signature to be verified.

3. Obtain **HuksOptions**, which include the **properties** and **inData** fields.
   Pass in the signature in **inData**, and [algorithm parameters](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksparam) in **properties**.

4. Use [initSession](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksinitsession9) to initialize a key session. The session handle is returned after the initialization.

5. Use [updateSession](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksupdatesession9) to process data.

6. Use [finishSession](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksfinishsession9) to finish signature verification.

**Key Deletion**

Use [deleteKeyItem](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksdeletekeyitem9) to delete the key that is not required. For details, see [Deleting a Key](huks-delete-key-arkts.md).

```ts
/*
 * Implement signing and signature verification using the key algorithm ECC256 and MD algorithm SHA256. This example uses promise-based APIs.
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
async function Verify(keyAlias: string, plaintext: string, signature: Uint8Array) {
  let verifyProperties = GetEccVerifyProperties()
  let options: huks.HuksOptions = {
    properties: verifyProperties,
    inData: StringToUint8Array(plaintext)
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
  options.inData = signature;
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
  await Verify(keyAlias, plaintext, signature);
  await DeleteEccKey(keyAlias);
}
```
