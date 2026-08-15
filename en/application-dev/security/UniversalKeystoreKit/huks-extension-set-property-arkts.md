# Setting Properties (ArkTS)

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=084bf627297e60b1f406ce34f5b473174466f7b3 translatedAt=2026-07-15T02:45:31.705Z pushedAt=2026-07-15T11:05:06.052Z -->

Starting from API version 26.0.0, **huksExternalCrypto** provides functional APIs for setting properties. An app can set the property value of a specified resource through the **setProperty** API, which is provided by the [CryptoExtensionAbility](../../reference/apis-universal-keystore-kit/js-apis-CryptoExtensionAbility.md) implementer. It is recommended to use the SKF API names defined in GMT 0016-2023 as property IDs. For specific scenario descriptions and specifications, see [General Query Overview and Specifications](huks-ukey-general-query-overview.md).

## How to Develop

1. Obtain the resource ID. You can obtain **keyUri** as **resourceId** through [openAuthorizeDialog](../../reference/apis-device-certificate-kit/js-apis-certManagerDialog.md#certificatemanagerdialogopenauthorizedialog22), or obtain the resource ID of the external key management extension through [getResourceId](../../reference/apis-universal-keystore-kit/js-apis-huksExternalCrypto.md#huksexternalcryptogetresourceid).

2. Call [setProperty](../../reference/apis-universal-keystore-kit/js-apis-huksExternalCrypto.md#huksexternalcryptosetproperty) to set the property value.

## Development Example

```ts
import { huksExternalCrypto } from '@kit.UniversalKeystoreKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function setProperty(resourceId: string, propertyId: string): Promise<void> {
  try {
    await huksExternalCrypto.setProperty(resourceId, propertyId)
      .then(() => {
        console.info('promise: setProperty success.');
      }).catch((error: BusinessError) => {
        console.error(`promise: setProperty failed, errCode : ${error.code}, errMsg : ${error.message}`);
      });
  } catch (error) {
    console.error('promise: setProperty input arg invalid.');
  }
}
```