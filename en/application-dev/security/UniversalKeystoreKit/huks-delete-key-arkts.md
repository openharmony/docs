# Deleting a Key (ArkTS)

To ensure data security, delete the key that is no longer required.

## How to Develop

For example, delete a 256-bit HKDF key.

1. Specify the key alias. For details about the naming rules, see [Key Generation Overview and Algorithm Specifications](huks-key-generation-overview.md).

2. Initialize the key property set to specify [the property tags of keys](../../reference/apis-universal-keystore-kit/_huks_type_api.md#oh_huks_tag). When a single key is to be deleted, **TAG** can be empty.

3. Use [deleteKeyItem](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksdeletekeyitem9) to delete the key.

```ts
/*
 * Delete a 256-bit HKDF key. This example uses promise-based APIs.
 */
import { huks } from '@kit.UniversalKeystoreKit';

/* 1. Set the key alias. */
let keyAlias = "test_Key";
/* 2. Construct an empty object. */
let huksOptions: huks.HuksOptions = {
  properties: []
}

class throwObject {
  isThrow = false;
}

function deleteKeyItem(keyAlias: string, huksOptions: huks.HuksOptions, throwObj: throwObject) {
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
      throwObj.isThrow = true;
      throw (error as Error);
    }
  });
}

/* 3. Delete the key. */
async function publicDeleteKeyFunc(keyAlias: string, huksOptions: huks.HuksOptions) {
  console.info(`enter promise deleteKeyItem`);
  let throwObj: throwObject = { isThrow: false };
  try {
    await deleteKeyItem(keyAlias, huksOptions, throwObj)
      .then((data) => {
        console.info(`promise: deleteKeyItem key success, data = ${JSON.stringify(data)}`);
      })
      .catch((error: Error) => {
        if (throwObj.isThrow) {
          throw (error as Error);
        } else {
          console.error(`promise: deleteKeyItem failed, ${JSON.stringify(error)}`);
        }
      });
  } catch (error) {
    console.error(`promise: deleteKeyItem input arg invalid, ${JSON.stringify(error)}`);
  }
}
async function testDelete(): Promise<string> {
  let ret = await publicDeleteKeyFunc(keyAlias, deleteHuksOptions);
  return ret;
}
```
