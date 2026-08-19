# Authentication Status Query (ArkTS)

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=f7243bd9bbc19d6bb1c1a460201c8c6cbf7dc7b6 translatedAt=2026-08-13T08:25:13.341Z pushedAt=2026-08-13T10:20:24.723Z -->

Starting from API 22, huksExternalCrypto provides an API for querying the PIN authentication status. An app can use this API to query whether PIN authentication has passed. For details about the scenarios and specifications, see [UKey PIN Authentication Introduction and Specifications](huks-ukey-pin-authentication-management-overview.md).

## How to Develop

1. Call [openAuthorizeDialog](../../reference/apis-device-certificate-kit/js-apis-certManagerDialog.md#certificatemanagerdialogopenauthorizedialog22) provided by the certificate management system to obtain [keyUri](../../reference/apis-device-certificate-kit/js-apis-certManagerDialog.md#certreference22), and use it as resourceId.

2. Call [getUkeyPinAuthState](../../reference/apis-universal-keystore-kit/js-apis-huksExternalCrypto.md#huksexternalcryptogetukeypinauthstate) to verify the PIN.

## Development Cases

```ts
import { huksExternalCrypto } from '@kit.UniversalKeystoreKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function getUkeyPinAuthState(): Promise<huksExternalCrypto.HuksExternalPinAuthState> {
  let ret: huksExternalCrypto.HuksExternalPinAuthState = huksExternalCrypto.HuksExternalPinAuthState.HUKS_EXT_CRYPTO_PIN_NO_AUTH;
  try {
    /* 1. Construct parameters for querying the PIN status.*/
    const testResourceId = JSON.stringify({
      providerName: "testProviderName",
      bundleName: "com.example.cryptoapplication",
      abilityName: "CryptoExtension",
      index: {
        key: "testKey"
      } as ESObject
    });
    const extProperties: Array<huksExternalCrypto.HuksExternalCryptoParam> = [];

    /* 2. Call getUkeyPinAuthState. */
    await huksExternalCrypto.getUkeyPinAuthState(testResourceId, extProperties)
      .then((data) => {
        console.info(`promise: getUkeyPinAuthState success , data : ${data}`);
      }).catch((error: BusinessError) => {
        console.error(`promise: getUkeyPinAuthState failed, errCode : ${error.code}, errMsg : ${error.message}`);
      });
  } catch (error) {
    console.error('promise: getUkeyPinAuthState input arg invalid.');
  }
  return ret;
}

async function testGetUkeyPinAuthState() {
  let ret: huksExternalCrypto.HuksExternalPinAuthState = await getUkeyPinAuthState();
  if (ret != huksExternalCrypto.HuksExternalPinAuthState.HUKS_EXT_CRYPTO_PIN_AUTH_SUCCEEDED) {
    console.error('getUkeyPinAuthState failed.');
    return;
  }

  console.info('getUkeyPinAuthState success.');
}
```