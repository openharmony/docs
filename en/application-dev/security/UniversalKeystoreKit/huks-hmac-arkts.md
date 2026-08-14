# HMAC (ArkTS)

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=3278ee705378631554cefba415ca42904851087c translatedAt=2026-08-13T08:21:59.769Z pushedAt=2026-08-13T10:20:24.682Z -->

Hash-based Message Authentication Code (HMAC) is a specific type of message authentication code (MAC) involving a cryptographic hash function and a secret cryptographic key. For details about the scenarios and supported algorithm specifications, see [HMAC Overview and Algorithm Specifications](huks-hmac-overview.md).

## How to Develop

**Key Generation**

1. Specify the key alias. For details about the naming rules, see [Key Generation Overview and Algorithm Specifications](huks-key-generation-overview.md).

2. Initialize the key property set.

3. Use [generateKeyItem](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksgeneratekeyitem9) to generate a key. For details about the HMAC specifications supported, see [Supported Algorithms](huks-key-generation-overview.md#supported-algorithms).

You can also import a key. For details about the supported algorithms, see [Supported Algorithms](huks-key-import-overview.md#supported-algorithms).

**HMAC Generation**

1. Obtain the key alias.

2. Obtain the data to be calculated.

3. Use [initSession](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksinitsession9) to initialize a key session. The session handle is returned after the initialization.

4. Use [finishSession](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksfinishsession9) to finish the session and obtain the hashed data.

<!-- @[hmac_to](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/UniversalKeystoreKit/KeyUsage/HMAC/entry/src/main/ets/pages/HMAC.ets) -->

``` TypeScript
/*
 * Perform HMAC calculation using promise-based APIs.
 */
import { huks } from '@kit.UniversalKeystoreKit';

let hmacKeyAlias = 'test_HMAC';
let handle: number;
let plainText = '123456';
let hashData: Uint8Array;

function stringToUint8Array(str: String) {
  let arr: number[] = [];
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

function uint8ArrayToString(fileData: Uint8Array) {
  let dataString = '';
  for (let i = 0; i < fileData.length; i++) {
    dataString += String.fromCharCode(fileData[i]);
  }
  return dataString;
}

function getHMACProperties() {
  const properties: huks.HuksParam[] = [{
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

/* 1. Generate an HMAC key. */
async function generateHMACKey() {
  let options: huks.HuksOptions = {
    properties: getHMACProperties()
  };

  await huks.generateKeyItem(hmacKeyAlias, options)
    .then((data) => {
      console.info(`promise: generate HMAC Key success`);
    }).catch((error: Error) => {
      console.error(`promise: generate HMAC Key failed, ${JSON.stringify(error)}`);
      throw (error as Error);
    })
}
/* 2. Perform HMAC calculation. */
async function hMACData() {
  let options: huks.HuksOptions = {
    properties: getHMACProperties(),
    inData: stringToUint8Array(plainText)
  }

  await huks.initSession(hmacKeyAlias, options)
    .then((data) => {
      handle = data.handle;
    }).catch((error: Error) => {
      console.error(`promise: init session failed, ${JSON.stringify(error)}`);
      throw (error as Error);
    })

  await huks.finishSession(handle, options)
    .then((data) => {
      console.info(`promise: HMAC data success, data is ` + uint8ArrayToString(data.outData as Uint8Array));
      hashData = data.outData as Uint8Array;
    }).catch((error: Error) => {
      console.error(`promise: HMAC data failed, ${JSON.stringify(error)}`);
      throw (error as Error);
    })
}

async function executeHMAC() {
  await generateHMACKey();
  await hMACData();
}
```