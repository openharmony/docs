# Importing a Key (ArkTS)

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutitian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=084bf627297e60b1f406ce34f5b473174466f7b3 translatedAt=2026-07-15T02:46:30.318Z pushedAt=2026-07-15T11:03:24.664Z -->

Starting from API version 26.0.0, in the external key management extension scenario, the key import capability supports importing an encrypted and wrapped key pair into an extension device. After parameters such as key purpose are passed to the Extension, they are processed by the Extension implementer based on the service scenario, and HUKS does not perform additional verification.

For a detailed scenario description, see [Key Generation, Import, and Export](huks-extension-key-generation-import-overview.md).

## How to Develop

1. Obtain **keyUri** as **resourceId** through [openAuthorizeDialog](../../reference/apis-device-certificate-kit/js-apis-certManagerDialog.md#certificatemanagerdialogopenauthorizedialog22), or obtain the resource ID of the external key management extension through [getResourceId](../../reference/apis-universal-keystore-kit/js-apis-huksExternalCrypto.md#huksexternalcryptogetresourceid).

2. Call [openResource](../../reference/apis-universal-keystore-kit/js-apis-huksExternalCrypto.md#huksexternalcryptoopenresource) to open the resource.

3. Call [importWrappedKeyItem](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksimportwrappedkeyitem9) to import the encrypted wrapped key pair. In the key parameters, set [HUKS_TAG_KEY_CLASS](../../reference/apis-universal-keystore-kit/js-apis-huks.md#hukstag) to [HUKS_KEY_CLASS_EXTENSION](../../reference/apis-universal-keystore-kit/js-apis-huks.md#hukskeyclasstype22), indicating that the key is managed by the external key management extension.

4. Close the resource.

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

async function importWrappedKeyItem(
  keyAlias: string,
  wrappingKeyAlias: string,
  huksOptions: huks.HuksOptions
): Promise<void> {
  try {
    await huks.importWrappedKeyItem(keyAlias, wrappingKeyAlias, huksOptions)
      .then(() => {
        console.info('promise: importWrappedKeyItem success.');
      }).catch((error: BusinessError) => {
        console.error(`promise: importWrappedKeyItem failed, errCode : ${error.code}, errMsg : ${error.message}`);
      });
  } catch (error) {
    console.error('promise: importWrappedKeyItem input arg invalid.');
  }
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

async function extensionKeyImport(): Promise<void> {
  /*1. Prepare the resource ID (keyAlias and wrappingKeyAlias use resourceId).*/
  const resourceId = JSON.stringify({
    providerName: "testProviderName",
    bundleName: "com.example.cryptoapplication",
    abilityName: "CryptoExtension",
    index: {
      key: "testKey"
    } as ESObject
  });
  const keyAlias = resourceId;
  const wrappingKeyAlias = resourceId;

  const properties: Array<huks.HuksParam> = [
    {
      tag: huks.HuksTag.HUKS_TAG_KEY_CLASS,
      value: huks.HuksKeyClass.HUKS_KEY_CLASS_EXTENSION
    },
    {
      tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
      value: huks.HuksKeyAlg.HUKS_ALG_RSA
    },
    {
      tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
      value: huks.HuksKeySize.HUKS_RSA_KEY_SIZE_2048
    },
    {
      tag: huks.HuksTag.HUKS_TAG_PURPOSE,
      value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT
    }
  ];
  // Encrypted wrapped key data (format defined by the Extension implementer).
  const wrappedKeyData: Uint8Array = new Uint8Array([/*Encapsulate the key data.*/]);
  const huksOptions: huks.HuksOptions = {
    properties: properties,
    inData: wrappedKeyData
  };

  try {
    /*2. Open the resource.*/
    await openResource(resourceId);
    
    /*3. Import the encrypted and encapsulated key.*/
    await importWrappedKeyItem(keyAlias, wrappingKeyAlias, huksOptions);
    
    /*4. Close the resource.*/
    await closeResource(resourceId);
    
    console.info('promise: extensionKeyImport completed successfully.');
  } catch (error) {
    console.error('promise: extensionKeyImport input arg invalid.');
  }
}
```