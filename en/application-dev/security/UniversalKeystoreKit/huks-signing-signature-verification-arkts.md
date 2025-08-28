# Signing and Signature Verification (ArkTS)

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->

This topic provides signing and signature verification development cases with the following algorithms:

- [Key algorithm ECC256 and digest algorithm SHA-256](#ecc256sha256)
- [Key algorithm SM2 and digest algorithm SM3](#sm2sm3)
- [Key algorithm RSA, digest algorithm SHA-256, and padding mode PSS](#rsasha256pss)
- [Key algorithm RSA, digest algorithm SHA-256, and padding mode PKCS #1 v1.5](#rsasha256pkcs1_v1_5)
<!--RP1--><!--RP1End-->

For details about the scenarios and supported algorithms, see [Supported Algorithms](huks-signing-signature-verification-overview.md#supported-algorithms).

## How to Develop

**Key Generation**

1. Specify the key alias. For details about the naming rules, see [Key Generation Overview and Algorithm Specifications](huks-key-generation-overview.md).

2. Initialize the key property set.

3. Use [generateKeyItem](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksgeneratekeyitem9) to generate a key. For details, see [Key Generation](huks-key-generation-overview.md).

Alternatively, you can [import a key](huks-key-import-overview.md).

**Signing**

1. Obtain the key alias.

2. Obtain the plaintext to be signed.

3. Obtain the property parameter [HuksOptions](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksoptions), which contains the **properties** and **inData** fields. Pass in the plaintext to be signed in **inData**, and [algorithm parameters](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksparam) in **properties**.

4. Use [initSession](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksinitsession9) to initialize a key session. The session handle is returned after the initialization.

5. Use [finishSession](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksfinishsession9) to generate a signature.

**Signature Verification**

1. Obtain the key alias.

2. Obtain the signature to be verified.

3. Obtain the property parameter [HuksOptions](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksoptions), which contains the **properties** and **inData** fields. Pass in the signature in **inData**, and [algorithm parameters](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksparam) in **properties**.

4. Use [initSession](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksinitsession9) to initialize a key session. The session handle is returned after the initialization.

5. Use [updateSession](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksupdatesession9) to process data.

6. Use [finishSession](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksfinishsession9) to finish signature verification.

**Key Deletion**

Use [deleteKeyItem](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksdeletekeyitem9) to delete the key that is not required. For details, see [Deleting a Key](huks-delete-key-arkts.md).
## Development Cases

### ECC256/SHA256
```ts
/*
 * Key algorithm ECC256 and digest algorithm SHA-256 are used.
 */
import { huks } from '@kit.UniversalKeystoreKit';

let keyAlias = 'test_eccKeyAlias';
let handle: number;
let plaintext = '123456';
let signature: Uint8Array;

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

function GetEccGenerateProperties() {
  let properties: Array<huks.HuksParam> = [{
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_ECC
  }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_ECC_KEY_SIZE_256
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
    value: huks.HuksKeySize.HUKS_ECC_KEY_SIZE_256
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
    value: huks.HuksKeySize.HUKS_ECC_KEY_SIZE_256
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
 * The key algorithm SM2 and digest algorithm SM3 are used.
 */
import { huks } from '@kit.UniversalKeystoreKit';

let keyAlias = 'test_sm2KeyAlias';
let handle: number;
let plaintext = '123456';
let signature: Uint8Array;


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


function GetSm2GenerateProperties() {
  let properties: Array<huks.HuksParam> = [{
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_SM2
  }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_SM2_KEY_SIZE_256
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
    value: huks.HuksKeySize.HUKS_SM2_KEY_SIZE_256
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
    value: huks.HuksKeySize.HUKS_SM2_KEY_SIZE_256
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
 * The key algorithm RSA, digest algorithm SHA-256, and padding mode PSS are used.
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
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_RSA_KEY_SIZE_2048
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
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_RSA_KEY_SIZE_2048
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
 * The key algorithm RSA, digest algorithm SHA-256, and padding mode PKCS #1 v1.5 are used.
 */
import { huks } from '@kit.UniversalKeystoreKit';

let keyAlias = 'test_rsaKeyAlias';
let handle: number;
let plaintext = '123456';
let signature: Uint8Array;

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

<!--RP2--><!--RP2End-->
