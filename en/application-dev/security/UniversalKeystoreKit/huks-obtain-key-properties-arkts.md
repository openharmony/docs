# Obtaining Key Properties (ArkTS)

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->

This topic describes how to obtain properties of a key. Before the operation, ensure that the key exists in HUKS.
>**NOTE**<br>
> <!--RP1-->The mini-system devices<!--RP1End--> do not allow for obtaining key properties.

## How to Develop

1. Set the key alias (**keyAlias**), which cannot exceed 128 bytes.

2. Use [getKeyItemProperties](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksgetkeyitemproperties9) to obtain the properties of the key based on **keyAlias** and **options**. **options** is a reserved parameter and is left empty currently.

3. You can find the key properties in the **properties** field in the [HuksReturnResult](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksreturnresult9) object.

```ts
import { huks } from '@kit.UniversalKeystoreKit';
/* 1. Set the key alias. */
let keyAlias = 'keyAlias';
/* 2. Set key properties. */
let emptyOptions: huks.HuksOptions = {
  properties: []
};
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
    console.error(`promise: generateKeyItem input arg invalid, ${JSON.stringify(error)}`);
    return 'Failed';
  }
}
async function testGenKey(): Promise<string> {
  let ret = await publicGenKeyFunc(keyAlias, huksOptions);
  return ret;
}
/* Obtain key properties. */
function getKeyItemProperties(keyAlias: string, emptyOptions: huks.HuksOptions) {
  return new Promise<huks.HuksReturnResult>((resolve, reject) => {
    try {
      huks.getKeyItemProperties(keyAlias, emptyOptions, (error, data) => {
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
    /* 2. Obtain key properties. */
    if (genResult === 'Success') {
      let data = await getKeyItemProperties(keyAlias, emptyOptions);
      console.info(`callback: getKeyItemProperties success, data = ${JSON.stringify(data)}`);
    } else {
      console.error('Key generation failed, skipping get properties');
      return 'Failed';
    }
    return 'Success';
  } catch (error) {
    console.error(`callback: getKeyItemProperties input arg invalid, ${JSON.stringify(error)}`);
    return 'Failed';
  }
}
```
