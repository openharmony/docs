# Deleting a Key (ArkTS)

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->

To ensure data security, delete the key that is no longer required.

## How to Develop

For example, delete a 256-bit HKDF key.

1. Specify the key alias. For details about the naming rules, see [Key Generation Overview and Algorithm Specifications](huks-key-generation-overview.md).

2. Initialize the key property set to specify [the property tags of keys](../../reference/apis-universal-keystore-kit/js-apis-huks.md#hukstag). When a single key is to be deleted, **TAG** can be empty.

3. Use [deleteKeyItem](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksdeletekeyitem9) to delete the key.

```ts
/*
 * Delete a 256-bit HKDF key. This example uses promise-based APIs.
 */
import { huks } from '@kit.UniversalKeystoreKit';
/* 1. Set the key alias. */
let keyAlias = 'test_Key';
/* 2. Initialize the key property set. */
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
    console.error(`promise: generateKeyItem input arg invalid, ${JSON.stringify(error)}`);
    return 'Failed';
  }
}
async function testGenKey(): Promise<string> {
  let ret = await publicGenKeyFunc(keyAlias, generateHuksOptions);
  return ret;
}
let deleteHuksOptions: huks.HuksOptions = {
  properties: []
}
class ThrowObject {
  public isThrow = false;
}
/*4. Delete a key.*/
function deleteKeyItem(keyAlias: string, huksOptions: huks.HuksOptions, throwObject: ThrowObject) {
  return new Promise<void>((resolve, reject) => {
    try {
      huks.deleteKeyItem(keyAlias, huksOptions, (error, data) => {
        if (error) {
          reject(error);
        } else {
          resolve(data);
        }
      });
    } catch (error) {
      throwObject.isThrow = true;
      throw (error as Error);
    }
  });
}
async function publicDeleteKeyFunc(keyAlias: string, huksOptions: huks.HuksOptions): Promise<string> {
  console.info(`enter promise deleteKeyItem`);
  let throwObject: ThrowObject = { isThrow: false };
  try {
    await testGenKey();
    await deleteKeyItem(keyAlias, huksOptions, throwObject)
      .then((data) => {
        console.info(`promise: deleteKeyItem key success, data = ${JSON.stringify(data)}`);
      })
      .catch((error: Error) => {
        if (throwObject.isThrow) {
          throw (error as Error);
        } else {
          console.error(`promise: deleteKeyItem failed, ${JSON.stringify(error)}`);
        }
      });
    return 'Success';
  } catch (error) {
    console.error(`promise: deleteKeyItem input arg invalid, ${JSON.stringify(error)}`);
    return 'Failed';
  }
}
async function testDelete(): Promise<string> {
  let ret = await publicDeleteKeyFunc(keyAlias, deleteHuksOptions);
  return ret;
}
```
