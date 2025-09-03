# Exporting a Key (ArkTS)

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->

This topic walks you through on how to export the public key of a persistently stored asymmetric key. Currently, HUKS supports export of the ECC, RSA, Ed25519, X25519, and SM2 public keys.
>**NOTE**<br>
> <!--RP1-->Mini-system devices<!--RP1End--> support export of only the RSA public keys.

## How to Develop

1. Specify the key alias. For details about the naming rules, see [Key Generation Overview and Algorithm Specifications](huks-key-generation-overview.md).

2. Use [exportKeyItem](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksexportkeyitem9) to export the key based on the specified **keyAlias** and **options**. **options** is a reserved parameter and is left empty currently.

3. In the [HuksReturnResult](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksreturnresult9) object returned, the public key is in the **outData** field in the DER format defined in X.509. For details about the format, see [Public Key Material Format](huks-concepts.md#public-key-material-format).

```ts
import { huks } from '@kit.UniversalKeystoreKit';
/* 1. Set the key alias. */
let keyAlias = 'keyAlias';
/* Leave options empty. */
let emptyOptions: huks.HuksOptions = {
  properties: []
};
/* 2. Set key properties. */
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
/* 3. Generate a key. */
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
async function publicGenKeyFunc(keyAlias: string, huksOptions: huks.HuksOptions): Promise<string> {
  try {
    await generateKeyItem(keyAlias, huksOptions)
      .then((data) => {
        console.info(`promise: generateKeyItem success, data = ${JSON.stringify(data)}`);
      })
      .catch((error: Error) => {
        console.error(`promise: generateKeyItem failed, ${JSON.stringify(error)}`);
      });
    return 'Success';
  } catch (error) {
    console.error(`promise: generateKeyItem input arg invalid, ${JSON.stringify(error)}`);
    return 'Failed';
  }
}
async function testGenKey(): Promise<string> {
  let ret = await publicGenKeyFunc(keyAlias, huksOptions);
  return ret;
}
/* Export a key. */
function exportKeyItem(keyAlias: string, emptyOptions: huks.HuksOptions) {
  return new Promise<huks.HuksReturnResult>((resolve, reject) => {
    try {
      huks.exportKeyItem(keyAlias, emptyOptions, (error, data) => {
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
async function check(): Promise<string> {
  try {
    /* 1. Generate a key. */
    let genResult = await testGenKey();
    /* 2. Export the key. */
    if (genResult === 'Success') {
      let data = await exportKeyItem(keyAlias, emptyOptions);
      console.info(`callback: exportKeyItem success, data = ${JSON.stringify(data)}`);
    } else {
      console.error('Key generation failed, skipping export');
      return 'Failed';
    }
    return 'Success';
  } catch (error) {
    console.error(`callback: exportKeyItem input arg invalid, ${JSON.stringify(error)}`);
    return 'Failed';
  }
}
```
