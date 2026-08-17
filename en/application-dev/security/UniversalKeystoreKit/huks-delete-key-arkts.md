# Deleting a Key (ArkTS)

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=938751e4702aa9713fca5c6265b7741bd118ef94 translatedAt=2026-08-13T08:20:23.121Z pushedAt=2026-08-13T10:20:24.673Z -->

To ensure data security, delete the key that is no longer required.

The [Group Key](huks-group-key-overview.md) feature is supported since API version 23.

## How to Develop

Take deleting a DH key as an example.

1. Specify the key alias. For details about the naming rules, see [Key Generation Overview and Algorithm Specifications](huks-key-generation-overview.md).

2. Initialize the key property set to specify the properties for deleting the key. If a single key or non-group key is deleted, this set can be left empty.

3. Use [deleteKeyItem](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksdeletekeyitem9) to delete the key.

<!-- @[key_deletions_arkts](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/UniversalKeystoreKit/KeyDeletion/entry/src/main/ets/pages/KeyDeletion.ets) -->

``` TypeScript
/*
 * The following uses the Promise-based operations of DH keys as an example.
 */
import { huks } from '@kit.UniversalKeystoreKit';

let keyAlias = 'test_Key';

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

/* 1. Generate a key. */
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

async function generateKey(keyAlias: string, huksOptions: huks.HuksOptions): Promise<void> {
  console.info(`enter promise generateKeyItem`);
  try {
    await generateKeyItem(keyAlias, huksOptions);
    console.info(`promise: generateKeyItem success`);
  } catch (error) {
    console.error(`promise: generateKeyItem failed, ${JSON.stringify(error)}`);
  }
}

/* 2. Delete the key. */
let deleteHuksOptions: huks.HuksOptions = {
  properties: []
}

function deleteKeyItem(keyAlias: string, huksOptions: huks.HuksOptions) {
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
      throw (error as Error);
    }
  });
}

async function deleteKey(keyAlias: string, huksOptions: huks.HuksOptions): Promise<void> {
  console.info(`enter promise deleteKeyItem`);
  try {
    await deleteKeyItem(keyAlias, huksOptions);
    console.info(`promise: deleteKeyItem success`);
  } catch (error) {
    console.error(`promise: deleteKeyItem failed, ${JSON.stringify(error)}`);
  }
}

async function executeKeyLifecycle(): Promise<string> {
  try {
    /* 1. Generate a key. */
    console.info('start generateKey...');
    await generateKey(keyAlias, generateHuksOptions);
    console.info('end generateKey...');

    /* 2. Delete the key. */
    console.info('start deleteKey...');
    await deleteKey(keyAlias, deleteHuksOptions);
    console.info('end deleteKey...');

    console.info('Key lifecycle completed successfully');
    return 'Success';
  } catch (error) {
    console.error(`Key lifecycle failed: ${JSON.stringify(error)}`);
    return 'Failed';
  }
}
```