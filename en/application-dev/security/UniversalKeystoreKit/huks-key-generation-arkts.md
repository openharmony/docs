# Generating a Key (ArkTS)

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->

This topic walks you through on how to randomly generate a key with the DH algorithm. For details about the scenarios and supported algorithms, see [Supported Algorithms](huks-key-generation-overview.md#supported-algorithms).

> **NOTE**
> Key aliases must not contain sensitive information, such as personal data.

## How to Develop

1. Set the alias (**keyAlias**) of the key to generate.
   - The key alias can contain a maximum of 128 bytes and cannot contain sensitive information, such as personal data.
   - For the keys generated for different services, HUKS isolates the storage paths based on the service identity information to prevent conflicts caused by the same key alias.

2. Initialize the key property set.
   - Encapsulate key properties in [HuksParam](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksparam) and use a **HuksParam** array to assign values to the **properties** field of [HuksOptions](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksoptions).
   - The key property set must contain [HuksKeyAlg](../../reference/apis-universal-keystore-kit/js-apis-huks.md#hukskeyalg), [HuksKeySize](../../reference/apis-universal-keystore-kit/js-apis-huks.md#hukskeysize), and [HuksKeyPurpose](../../reference/apis-universal-keystore-kit/js-apis-huks.md#hukskeypurpose). That is, **TAG**, **HUKS_TAG_ALGORITHM**, **HUKS_TAG_PURPOSE**, and **HUKS_TAG_KEY_SIZE** are mandatory.
   
   > **NOTE**
   >
   > A key can have only one purpose, and the purpose specified during key generation must match the key purpose during usage. Otherwise, an exception occurs.

3. Use [generateKeyItem](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksgeneratekeyitem9) to generate a key based on the key alias and key properties specified.

> **NOTE**
> If the service uses the same key alias to call the HUKS API to generate a key again, HUKS will generate a new key and overwrite the historical key file.

```ts
/* Generate a DH key. */
import { huks } from '@kit.UniversalKeystoreKit';

/* 1. Set the key alias. */
let keyAlias = 'dh_key';
/* 2. Initialize the key property set. */
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
