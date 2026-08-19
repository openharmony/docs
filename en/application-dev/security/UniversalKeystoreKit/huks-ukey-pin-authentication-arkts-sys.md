# UKey PIN Authentication (ArkTS)

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=f7243bd9bbc19d6bb1c1a460201c8c6cbf7dc7b6 translatedAt=2026-08-13T08:25:54.063Z pushedAt=2026-08-13T10:20:24.756Z -->

Starting from API 22, huksExternalCrypto provides PIN authentication APIs. An ecosystem app calls the certificate HAP API to display the certificate list. After the user selects a certificate, the browser obtains the **resourceId** based on the selected certificate, [opens the resource](huks-open-close-resource-ndk.md), and then proceeds to PIN authentication. For details about the scenarios, see [UKey PIN Authentication Introduction and Specifications](huks-ukey-pin-authentication-management-overview.md).

## How to Develop

1. [Open the resource](huks-open-close-resource-ndk.md).

2. Construct parameters, among which [HUKS_EXT_CRYPTO_TAG_UID](../../reference/apis-universal-keystore-kit/js-apis-huksExternalCrypto.md#huksexternalcryptotag) and [HUKS_EXT_CRYPTO_TAG_UKEY_PIN](../../reference/apis-universal-keystore-kit/js-apis-huksExternalCrypto.md#huksexternalcryptotag) are mandatory.

3. Call [authUkeyPin](../../reference/apis-universal-keystore-kit/js-apis-huksExternalCrypto-sys.md#huksexternalcryptoauthukeypin) to verify the PIN.

## Development Cases

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { huksExternalCrypto } from '@kit.UniversalKeystoreKit';

function StringToUint8Array(str: string) {
  let arr: number[] = [];
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// The UID is obtained by the caller.
let uid: number = 3511;

async function authUkeyPin(): Promise<void> {
  try {
    /* 1. Assume that the opened resources are as follows: */
    const testResourceId = JSON.stringify({
    providerName: "testProviderName",
    bundleName: "com.example.cryptoapplication",
    abilityName: "CryptoExtension",
    index: {
      key: "testKey"
    } as ESObject
  });

    /* 2. Construct parameters. */
    const pin = "123456";
    const extProperties: Array<huksExternalCrypto.HuksExternalCryptoParam> = [
      {
        tag: huksExternalCrypto.HuksExternalCryptoTag.HUKS_EXT_CRYPTO_TAG_UID,
        value: uid
      }, {
        tag: huksExternalCrypto.HuksExternalCryptoTag.HUKS_EXT_CRYPTO_TAG_UKEY_PIN,
        value: StringToUint8Array(pin)
      }
    ];

    /* 3. Verify the PIN. */
    await huksExternalCrypto.authUkeyPin(testResourceId, extProperties)
      .then(() => {
        console.info('promise: getUkeyPinAuthState success.');
      }).catch((error: BusinessError) => {
        console.error(`promise: getUkeyPinAuthState failed, errCode : ${error.code}, errMsg : ${error.message}`);
      });
  } catch (error) {
    console.error('promise: getUkeyPinAuthState input arg invalid.');
  }
}

async function TestAuthUkeyPin() {
  await authUkeyPin();
}
```