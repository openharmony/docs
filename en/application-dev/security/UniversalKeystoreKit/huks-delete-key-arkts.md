# Deleting a Key (ArkTS)

To ensure data security, delete the key that is no longer required.

## How to Develop

For example, delete a 256-bit HKDF key.

1. Set the key alias (**keyAlias**), which cannot exceed 128 bytes.

2. Initialize the key property set to specify the properties of the key to delete, for example, delete all keys or a single key. To delete a single key, leave **properties** empty.

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

function deleteKeyItem(keyAlias: string, huksOptions: huks.HuksOptions, throwObject: throwObject) {
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

/* 3. Delete the key. */
async function publicDeleteKeyFunc(keyAlias: string, huksOptions: huks.HuksOptions) {
  console.info(`enter promise deleteKeyItem`);
  let throwObject: throwObject = { isThrow: false };
  try {
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
  } catch (error) {
    console.error(`promise: deleteKeyItem input arg invalid, ${JSON.stringify(error)}`);
  }
}

async function testDerive() {
  await publicDeleteKeyFunc(keyAlias, huksOptions);
}
```
