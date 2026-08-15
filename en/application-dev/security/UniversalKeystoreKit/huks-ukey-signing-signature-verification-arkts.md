# Signing and Signature Verification (ArkTS)

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=36b64f907faaaf7d23ead95995be1fcb7ed61c89 translatedAt=2026-08-13T08:26:20.521Z pushedAt=2026-08-13T10:20:24.759Z -->

This topic provides signing and signature verification development cases with the following algorithms:

- [Key algorithm RSA, digest algorithm SHA-256, and padding mode PSS](#rsasha256pss)

For details about the scenarios and supported algorithm specifications, see [Signature and Signature Verification Overview and Algorithm Specifications](huks-ukey-signing-signature-verification-overview.md).

## How to Develop

**Signing**

1. Obtain [keyUri](../../reference/apis-device-certificate-kit/js-apis-certManagerDialog.md#certreference22) as the resourceId through [openAuthorizeDialog](../../reference/apis-device-certificate-kit/js-apis-certManagerDialog.md#certificatemanagerdialogopenauthorizedialog22) provided by the certificate management system capability, use it as the key alias, and complete PIN authentication after [opening the resource](huks-open-close-resource-ndk.md#opening-resources).

2. Specify the plaintext to be signed.

3. Obtain the property parameter [HuksOptions](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksoptions), which contains the **properties** and **inData** fields. **inData** indicates the plaintext data, and **properties** indicates the algorithm parameter configuration.

4. Call [initSession](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksinitsession9) to initialize a key session and obtain the session handle.

5. Use [finishSession](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksfinishsession9) to finish the key session and obtain a signature.

**Signature verification**

1. Obtain [keyUri](../../reference/apis-device-certificate-kit/js-apis-certManagerDialog.md#certreference22) as the resourceId through [openAuthorizeDialog](../../reference/apis-device-certificate-kit/js-apis-certManagerDialog.md#certificatemanagerdialogopenauthorizedialog22) provided by the certificate management system capability, use it as the key alias, and then [open the resource](huks-open-close-resource-ndk.md#opening-resources).

2. Obtain the signature to be verified.

3. Obtain the property parameter [HuksOptions](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksoptions), which contains the **properties** and **inData** fields. **inData** indicates the signature, and **properties** indicates the algorithm parameter configuration.

4. Call [initSession](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksinitsession9) to initialize a key session and obtain the session handle.

5. Call [updateSession](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksupdatesession9) to update the key session.

6. Call [finishSession](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksfinishsession9) to finish the key session and verify the signature.

## Development Cases

### RSA/SHA256/PSS

```ts
/*
 * The key algorithm RSA, digest algorithm SHA-256, and padding mode PSS are used.
 */
import { huks } from '@kit.UniversalKeystoreKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
  }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_CLASS,
    value: huks.HuksKeyClassType.HUKS_KEY_CLASS_EXTENSION
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
  }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_CLASS,
    value: huks.HuksKeyClassType.HUKS_KEY_CLASS_EXTENSION
  }];
  return properties;
}

async function initSession(keyAlias: string, huksOptions: huks.HuksOptions) {
  console.info('promise: enter initSession.');
  try {
    await huks.initSession(keyAlias, huksOptions)
      .then((data) => {
        handle = data.handle;
        console.info('promise: initSession success.');
      }).catch((error: BusinessError) => {
        console.error(`promise: initSession failed, errCode : ${error.code}, errMsg : ${error.message}`);
      })
  } catch (error) {
    console.error('promise: initSession input arg invalid.');
  }
}

async function updateSession(handle: number, huksOptions: huks.HuksOptions) {
  console.info('promise: enter updateSession.');
  try {
    await huks.updateSession(handle, huksOptions)
      .then((data) => {
        let outData = data.outData as Uint8Array;
        console.info(`promise: updateSession success, data = ${Uint8ArrayToString(outData)}`);
      }).catch((error: BusinessError) => {
        console.error(`promise: updateSession failed, errCode : ${error.code}, errMsg : ${error.message}`);
      })
  } catch (error) {
    console.error('promise: updateSession input arg invalid.');
  }
}

async function finishSession(handle: number, huksOptions: huks.HuksOptions) {
  console.info('promise: enter finishSession.');
  try {
    await huks.finishSession(handle, huksOptions)
      .then((data) => {
        signature = data.outData as Uint8Array;
        console.info(`promise: finishSession success, data = ${Uint8ArrayToString(signature)}`);
      }).catch((error: BusinessError) => {
        console.error(`promise: finishSession failed, errCode : ${error.code}, errMsg : ${error.message}`);
      })
  } catch (error) {
    console.error('promise: finishSession input arg invalid.');
  }
}

async function Sign(keyAlias: string, plaintext: string) {
  console.info('enter Sign.');
  let signProperties = GetRsaSignProperties();
  let options: huks.HuksOptions = {
    properties: signProperties,
  }
  await initSession(keyAlias, options);

  if (handle !== undefined) {
    options.inData = StringToUint8Array(plaintext);
    await finishSession(handle, options);
  }
}

async function Verify(keyAlias: string, plaintext: string, signature: Uint8Array) {
  console.info('enter Verify.');
  let verifyProperties = GetRsaVerifyProperties();
  let options: huks.HuksOptions = {
    properties: verifyProperties,
  }

  await initSession(keyAlias, options);

  if (handle !== undefined) {
    options.inData = StringToUint8Array(plaintext);
    await updateSession(handle, options);
    options.inData = signature;
    await finishSession(handle, options);
  }
}

async function testSignVerify() {
  // Assume that **keyAlias** is the value of **resourceId** obtained.
  let keyAlias = JSON.stringify({
    providerName: "testProviderName",
    bundleName: "com.example.cryptoapplication",
    abilityName: "CryptoExtension",
    index: {
      key: "testKey"
    } as ESObject
  });
  await Sign(keyAlias, plaintext);
  await Verify(keyAlias, plaintext, signature);
}
```