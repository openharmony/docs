# Clearing the UKey PIN Authentication Status (ArkTS)

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=f7243bd9bbc19d6bb1c1a460201c8c6cbf7dc7b6 translatedAt=2026-08-13T08:20:52.676Z pushedAt=2026-08-13T10:20:24.677Z -->

Starting from API version 26.0.0, huksExternalCrypto provides the interface for clearing the UKey PIN authentication state. After a key operation is complete or when the authentication state needs to be reset, an app can call this interface to clear the PIN authentication state of a specified resource. For details about the scenarios and specifications, see [UKey PIN Authentication Introduction and Specifications](huks-ukey-pin-authentication-management-overview.md).

## How to Develop

1. Obtain the resource ID. You can obtain **keyUri** as **resourceId** through [openAuthorizeDialog](../../reference/apis-device-certificate-kit/js-apis-certManagerDialog.md#certificatemanagerdialogopenauthorizedialog22), or obtain the resource ID of the external key management extension through [getResourceId](../../reference/apis-universal-keystore-kit/js-apis-huksExternalCrypto.md#huksexternalcryptogetresourceid).

2. Call [clearUkeyPinAuthState](../../reference/apis-universal-keystore-kit/js-apis-huksExternalCrypto.md#huksexternalcryptoclearukeypinauthstate) to clear the PIN authentication status.

## Development Cases

```ts
import { huksExternalCrypto } from '@kit.UniversalKeystoreKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Clear the PIN authentication status (ArkTS)
async function clearUkeyPinAuthState(resourceId: string): Promise<void> {
  try {
    await huksExternalCrypto.clearUkeyPinAuthState(resourceId)
      .then(() => {
        console.info('promise: clearUkeyPinAuthState success.');
      }).catch((error: BusinessError) => {
        console.error(`promise: clearUkeyPinAuthState failed, errCode : ${error.code}, errMsg : ${error.message}`);
      });
  } catch (error) {
    console.error('promise: clearUkeyPinAuthState input arg invalid.');
  }
}
```