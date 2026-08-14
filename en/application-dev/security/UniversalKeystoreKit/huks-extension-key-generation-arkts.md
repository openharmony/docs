# Generating a Key (ArkTS)

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=084bf627297e60b1f406ce34f5b473174466f7b3 translatedAt=2026-07-15T02:45:35.000Z pushedAt=2026-07-15T10:58:39.742Z -->

Starting from API version 26.0.0, in external key management extension scenarios, HUKS supports key pair generation within the extension device. After parameters such as the key purpose are passed to the extension, the extension implementer processes them based on the service scenario, and HUKS does not perform additional verification.

For a detailed scenario introduction, see [Key Generation and Import/Export Overview](huks-extension-key-generation-import-overview.md).

## How to Develop

1. Obtain **keyUri** as **resourceId** through [openAuthorizeDialog](../../reference/apis-device-certificate-kit/js-apis-certManagerDialog.md#certificatemanagerdialogopenauthorizedialog22), or obtain the resource ID for external key management extension through [getResourceId](../../reference/apis-universal-keystore-kit/js-apis-huksExternalCrypto.md#huksexternalcryptogetresourceid).

2. Call [openResource](../../reference/apis-universal-keystore-kit/js-apis-huksExternalCrypto.md#huksexternalcryptoopenresource) to open the resource.

3. Call [generateKeyItem](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksgeneratekeyitem9) to generate a key pair. In the key parameters, [HUKS_TAG_KEY_CLASS](../../reference/apis-universal-keystore-kit/js-apis-huks.md#hukstag) must be set to [HUKS_KEY_CLASS_EXTENSION](../../reference/apis-universal-keystore-kit/js-apis-huks.md#hukskeyclasstype22), indicating that the key is managed by the external key management extension.

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

async function generateKeyItem(keyAlias: string, huksOptions: huks.HuksOptions): Promise<void> {
  try {
    await huks.generateKeyItem(keyAlias, huksOptions)
      .then(() => {
        console.info('promise: generateKeyItem success.');
      }).catch((error: BusinessError) => {
        console.error(`promise: generateKeyItem failed, errCode : ${error.code}, errMsg : ${error.message}`);
      });
  } catch (error) {
    console.error('promise: generateKeyItem input arg invalid.');
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

async function extensionKeyGeneration(): Promise<void> {
  /*1. Prepare the resource ID (keyAlias uses resourceId).*/
  const resourceId = JSON.stringify({
    providerName: "testProviderName",
    bundleName: "com.example.cryptoapplication",
    abilityName: "CryptoExtension",
    index: {
      key: "testKey"
    } as ESObject
  });
  const keyAlias = resourceId;

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
      value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_SIGN
    }
  ];
  const huksOptions: huks.HuksOptions = {
    properties: properties,
    inData: new Uint8Array([])
  };

  try {
    /*2. Open the resource.*/
    await openResource(resourceId);
    
    /*3. Generate the key.*/
    await generateKeyItem(keyAlias, huksOptions);
    
    /*4. Close the resource.*/
    await closeResource(resourceId);
    
    console.info('promise: extensionKeyGeneration completed successfully.');
  } catch (error) {
    console.error('promise: extensionKeyGeneration input arg invalid.');
  }
}
```