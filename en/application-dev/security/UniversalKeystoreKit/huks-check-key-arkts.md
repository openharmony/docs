# Checking a Key (ArkTS)

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->

Check whether a key exists.

## How to Develop

1. Specify the key alias. For details about the naming rules, see [Key Generation Overview and Algorithm Specifications](huks-key-generation-overview.md).

2. Initialize the key property set to specify [the property tags of keys](../../reference/apis-universal-keystore-kit/js-apis-huks.md#hukstag). When a single key is queried, **TAG** can be empty.

3. Use [hasKeyItem](../../reference/apis-universal-keystore-kit/js-apis-huks.md#hukshaskeyitem11) to check whether the key exists.

```ts
import { huks } from '@kit.UniversalKeystoreKit';
/* 1. Set the key alias. */
let keyAlias = 'test_key';
let isKeyExist: Boolean;
/* 2. Construct an empty object. */
let huksOptions: huks.HuksOptions = {
  properties: []
}
/* 3. Initialize the key property set. */
let generateProperties: huks.HuksParam[] = [
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
let generateHuksOptions: huks.HuksOptions = {
  properties: generateProperties,
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
  console.info(`enter promise generateKeyItem`);
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
    console.error(`promise: generateKeyItem input arg invalid, ` + JSON.stringify(error));
    return 'Failed';
  }
}
async function testGenKey(): Promise<string> {
  let ret = await publicGenKeyFunc(keyAlias, generateHuksOptions);
  return ret;
}
/* Check whether the key exists. */
function hasKeyItem(keyAlias: string, huksOptions: huks.HuksOptions) {
  return new Promise<boolean>((resolve, reject) => {
    try {
      huks.hasKeyItem(keyAlias, huksOptions, (error, data) => {
        if (error) {
          reject(error);
        } else {
          if (data !== null && data.valueOf() !== null) {
            resolve(data.valueOf());
          } else {
            resolve(false);
          }
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
    /* 2. Check whether the key exists. */
    if (genResult === 'Success') {
      isKeyExist = await hasKeyItem(keyAlias, huksOptions);
      console.info(`callback: hasKeyItem success, isKeyExist = ${isKeyExist}`);
    } else {
      console.error('Key generation failed, skipping query');
      return 'Failed';
    }
    return 'Success';
  } catch (error) {
    console.error(`callback: hasKeyItem input arg invalid, ` + JSON.stringify(error));
    return 'Failed';
  }
}
```
