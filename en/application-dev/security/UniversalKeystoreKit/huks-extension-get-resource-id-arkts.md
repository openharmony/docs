# Getting Resource ID (ArkTS)

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=084bf627297e60b1f406ce34f5b473174466f7b3 translatedAt=2026-07-15T02:44:24.101Z pushedAt=2026-07-15T10:37:44.420Z -->

In external key management extension scenarios, a resource ID is used to identify specific resources of the external key management extension (such as UKey devices, containers, and keys). Starting from API version 26.0.0, an app can obtain a resource ID through getResourceId and use it to perform subsequent operations such as key generation, import and export, general query, PIN authentication, and clearing the PIN authentication status.

## How to Develop

1. Prepare the provider name (**providerName**), which is recommended to include vendor information and be globally unique. The maximum length is 128 bytes.

2. Construct the mandatory parameters:

   - Pass the **CryptoExtensionAbility** name through [HUKS_EXT_CRYPTO_TAG_ABILITY_NAME](../../reference/apis-universal-keystore-kit/js-apis-huksExternalCrypto.md#huksexternalcryptotag).

   - Pass the bundle name through [HUKS_EXT_CRYPTO_TAG_BUNDLE_NAME](../../reference/apis-universal-keystore-kit/js-apis-huksExternalCrypto.md#huksexternalcryptotag).

   - Pass vendor-defined resource information through [HUKS_EXT_CRYPTO_TAG_RESOURCE_INFO](../../reference/apis-universal-keystore-kit/js-apis-huksExternalCrypto.md#huksexternalcryptotag).

3. Call [getResourceId](../../reference/apis-universal-keystore-kit/js-apis-huksExternalCrypto.md#huksexternalcryptogetresourceid) to get the resource ID.

## Development Example

```ts
import { huksExternalCrypto } from '@kit.UniversalKeystoreKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Provider name. It is recommended to include vendor information. It must be globally unique and can contain a maximum of 128 bytes.
let providerName: string = 'testProviderName';
// Ability name.
let abilityName: string = 'CryptoExtension';
// Bundle name.
let bundleName: string = 'com.example.cryptoapplication';
// Resource information. The format and content are defined by the vendor.
let resourceInfo: string = 'vendor_defined_resource_info';

function StringToUint8Array(str: string) {
  let arr: number[] = [];
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

async function getResourceId(): Promise<string> {
  try {
    /*1. Construct the mandatory parameters.*/
    const extProperties: Array<huksExternalCrypto.HuksExternalCryptoParam> = [
      {
        tag: huksExternalCrypto.HuksExternalCryptoTag.HUKS_EXT_CRYPTO_TAG_ABILITY_NAME,
        value: StringToUint8Array(abilityName)
      },
      {
        tag: huksExternalCrypto.HuksExternalCryptoTag.HUKS_EXT_CRYPTO_TAG_BUNDLE_NAME,
        value: StringToUint8Array(bundleName)
      },
      {
        tag: huksExternalCrypto.HuksExternalCryptoTag.HUKS_EXT_CRYPTO_TAG_RESOURCE_INFO,
        value: StringToUint8Array(resourceInfo)
      }
    ];

    /*2. Call getResourceId.*/
    await huksExternalCrypto.getResourceId(providerName, extProperties)
      .then((resourceId) => {
        console.info(`promise: getResourceId success, resourceId: ${resourceId}`);
      }).catch((error: BusinessError) => {
        console.error(`promise: getResourceId failed, errCode : ${error.code}, errMsg : ${error.message}`);
      });
  } catch (error) {
    console.error('promise: getResourceId input arg invalid.');
  }
}
```