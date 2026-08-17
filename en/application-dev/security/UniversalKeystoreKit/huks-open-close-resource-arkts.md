# Opening/Closing a Resource (ArkTS)

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=084bf627297e60b1f406ce34f5b473174466f7b3 translatedAt=2026-07-15T02:46:12.496Z pushedAt=2026-07-16T06:25:18.777Z -->

Starting from API version 26.0.0, huksExternalCrypto provides ArkTS APIs for opening and closing resources.

## Opening a Resource

Before performing key operations (key operations, general operations, PIN authentication, etc.), the app must first call [openResource](../../reference/apis-universal-keystore-kit/js-apis-huksExternalCrypto.md#huksexternalcryptoopenresource) to open the resource specified by **resourceId**, which can be obtained via [openAuthorizeDialog](../../reference/apis-device-certificate-kit/js-apis-certManagerDialog.md#certificatemanagerdialogopenauthorizedialog22) or [getResourceId](../../reference/apis-universal-keystore-kit/js-apis-huksExternalCrypto.md#huksexternalcryptogetresourceid). The latter is used to obtain the extended resource ID for external key management.

### How to Develop

1. Obtain **keyUri** as **resourceId** via [openAuthorizeDialog](../../reference/apis-device-certificate-kit/js-apis-certManagerDialog.md#certificatemanagerdialogopenauthorizedialog22), or obtain the extended resource ID for external key management via [getResourceId](../../reference/apis-universal-keystore-kit/js-apis-huksExternalCrypto.md#huksexternalcryptogetresourceid).

2. Call [openResource](../../reference/apis-universal-keystore-kit/js-apis-huksExternalCrypto.md#huksexternalcryptoopenresource) to open the resource.

### Development Example

```ts
import { huksExternalCrypto } from '@kit.UniversalKeystoreKit';
import { BusinessError } from '@kit.BasicServicesKit';

const resourceId = JSON.stringify({
  providerName: "testProviderName",
  bundleName: "com.example.cryptoapplication",
  abilityName: "CryptoExtension",
  index: {
    key: "testKey"
  } as ESObject
});

const openResourceParams: Array<huksExternalCrypto.HuksExternalCryptoParam> = [];

async function openResource(): Promise<void> {
  try {
    await huksExternalCrypto.openResource(resourceId, openResourceParams)
      .then(() => {
        console.info('promise: openResource success.');
      }).catch((error: BusinessError) => {
        console.error(`promise: openResource failed, errCode : ${error.code}, errMsg : ${error.message}`);
      });
  } catch (error) {
    console.error('promise: openResource input arg invalid.');
  }
}
```

## Closing a Resource

The app invokes the certificate HAP UI to display the certificate list. After the user selects a certificate, the app obtains the corresponding **resourceId**. Closing a resource depends on the corresponding **resourceId**. For specific scenario descriptions and specifications, see [Resource Management Overview and Specifications](huks-resource-management-overview.md).

### How to Develop

1. Obtain **resourceId** via [openAuthorizeDialog](../../reference/apis-device-certificate-kit/js-apis-certManagerDialog.md#certificatemanagerdialogopenauthorizedialog22), or obtain the extended resource ID for external key management via [getResourceId](../../reference/apis-universal-keystore-kit/js-apis-huksExternalCrypto.md#huksexternalcryptogetresourceid).

2. Call [closeResource](../../reference/apis-universal-keystore-kit/js-apis-huksExternalCrypto.md#huksexternalcryptocloseresource) to close the resource.

### Development Example

```ts
import { huksExternalCrypto } from '@kit.UniversalKeystoreKit';
import { BusinessError } from '@kit.BasicServicesKit';

const resourceId = JSON.stringify({
  providerName: "testProviderName",
  bundleName: "com.example.cryptoapplication",
  abilityName: "CryptoExtension",
  index: {
    key: "testKey"
  } as ESObject
});

const closeResourceParams: Array<huksExternalCrypto.HuksExternalCryptoParam> = [];

async function closeResource(): Promise<void> {
  try {
    await huksExternalCrypto.closeResource(resourceId, closeResourceParams)
      .then(() => {
        console.info('promise: closeResource success.');
      }).catch((error: BusinessError) => {
        console.error(`promise: closeResource failed, errCode : ${error.code}, errMsg : ${error.message}`);
      });
  } catch (error) {
    console.error('promise: closeResource input arg invalid.');
  }
}
```