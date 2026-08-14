# Exporting a Public Key (ArkTS)

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutitian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=084bf627297e60b1f406ce34f5b473174466f7b3 translatedAt=2026-07-15T02:44:48.120Z pushedAt=2026-07-15T10:40:11.620Z -->

Starting from API version 26.0.0, in the external key management extension scenario, the public key export capability supports exporting the public key of a specified key from an extension device. The exported public key can be used in scenarios such as certificate application and key agreement.

For a detailed scenario introduction, see [Key Generation, Import, and Export](huks-extension-key-generation-import-overview.md).

## How to Develop

1. Obtain the **keyUri** as the **resourceId** through [openAuthorizeDialog](../../reference/apis-device-certificate-kit/js-apis-certManagerDialog.md#certificatemanagerdialogopenauthorizedialog22), or obtain the resource ID of the external key management extension through [getResourceId](../../reference/apis-universal-keystore-kit/js-apis-huksExternalCrypto.md#huksexternalcryptogetresourceid).

2. Call [openResource](../../reference/apis-universal-keystore-kit/js-apis-huksExternalCrypto.md#huksexternalcryptoopenresource) to open the resource.

3. Call [exportKeyItem](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksexportkeyitem9) to export the public key. In the key parameters, specify [HUKS_TAG_KEY_CLASS](../../reference/apis-universal-keystore-kit/js-apis-huks.md#hukstag) as [HUKS_KEY_CLASS_EXTENSION](../../reference/apis-universal-keystore-kit/js-apis-huks.md#hukskeyclasstype22), indicating that the key is managed by external key management extension.

4. Call [closeResource](../../reference/apis-universal-keystore-kit/js-apis-huksExternalCrypto.md#huksexternalcryptocloseresource) to close the resource.

## Development Example

```ts
import { huks, huksExternalCrypto } from '@kit.UniversalKeystoreKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function openResource(resourceId: string): Promise<void> {
  try {
    await huksExternalCrypto.openResource(resourceId)
      .then(() => {
        console.info('promise: openResource success.');
      }).catch((error: BusinessError) => {
        console.error(`promise: openResource failed, errCode : ${error.code}, errMsg : ${error.message}`);
      });
  } catch (error) {
    console.error('promise: openResource input arg invalid.');
  }
}

async function exportPublicKey(keyAlias: string): Promise<Uint8Array> {
  let publicKey: Uint8Array = new Uint8Array([]);
  try {
    const exportProperties: Array<huks.HuksParam> = [
      {
        tag: huks.HuksTag.HUKS_TAG_KEY_CLASS,
        value: huks.HuksKeyClass.HUKS_KEY_CLASS_EXTENSION
      }
    ];
    const exportOptions: huks.HuksOptions = {
      properties: exportProperties
    };
    await huks.exportKeyItem(keyAlias, exportOptions)
      .then((data) => {
        publicKey = data.outData as Uint8Array;
        console.info('promise: exportKeyItem success.');
      }).catch((error: BusinessError) => {
        console.error(`promise: exportKeyItem failed, errCode : ${error.code}, errMsg : ${error.message}`);
      });
  } catch (error) {
    console.error('promise: exportKeyItem input arg invalid.');
  }
  return publicKey;
}

async function closeResource(resourceId: string): Promise<void> {
  try {
    await huksExternalCrypto.closeResource(resourceId)
      .then(() => {
        console.info('promise: closeResource success.');
      }).catch((error: BusinessError) => {
        console.error(`promise: closeResource failed, errCode : ${error.code}, errMsg : ${error.message}`);
      });
  } catch (error) {
    console.error('promise: closeResource input arg invalid.');
  }
}

async function extensionKeyExport(): Promise<Uint8Array> {
  /* 1. Prepare the resource ID. */
  const resourceId = 'your_resource_id';

  let publicKey: Uint8Array = new Uint8Array([]);
  try {
    /* 2. Open the resource. */
    await openResource(resourceId);
    
    /* 3. Export the public key. */
    publicKey = await exportPublicKey(resourceId);
    console.info(`promise: public key length: ${publicKey.length}`);
    
    /* 4. Close the resource. */
    await closeResource(resourceId);
    
    console.info('promise: extensionKeyExport completed successfully.');
  } catch (error) {
    console.error('promise: extensionKeyExport input arg invalid.');
  }
  return publicKey;
}
```