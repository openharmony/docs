# Obtaining Error Information (ArkTS)

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=084bf627297e60b1f406ce34f5b473174466f7b3 translatedAt=2026-07-15T02:46:14.323Z pushedAt=2026-07-16T06:32:28.174Z -->

Starting from API version 26.0.0, huksExternalCrypto provides the **getErrorInfo** API for obtaining detailed error information about the most recent external key operation. This error information is returned by the key management extension ([CryptoExtensionAbility](../../reference/apis-universal-keystore-kit/js-apis-CryptoExtensionAbility.md)) and can be used to help locate issues.

## How to Develop

1. Call an external key operation API (such as **authUkeyPin** and **getProperty**).

2. After the operation fails, call [getErrorInfo](../../reference/apis-universal-keystore-kit/js-apis-huksExternalCrypto.md#huksexternalcryptogeterrorinfo) to obtain the error information from the Extension.

## Development Example

### Extension Returning an Error

```ts
import { huksExternalCrypto } from '@kit.UniversalKeystoreKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function testExtensionError(): Promise<void> {
  /* 1. Assume the opened resources are as follows. */
  const testResourceId = JSON.stringify({
    providerName: "testProviderName",
    bundleName: "com.example.cryptoapplication",
    abilityName: "CryptoExtension",
    index: "testKey"
  });

  /* 2. Construct parameters. */
  const pin = "123456";
  const params: Array<huksExternalCrypto.HuksExternalCryptoParam> = [
    {
      tag: huksExternalCrypto.HuksExternalCryptoTag.HUKS_EXT_CRYPTO_TAG_UKEY_PIN,
      value: StringToUint8Array(pin)
    }
  ];
  
  /* 3. Obtain error information after PIN verification fails. */
  try {
    await huksExternalCrypto.authUkeyPin(testResourceId, params);
  } catch (error) {
    const errorInfo = huksExternalCrypto.getErrorInfo();
    if (errorInfo.errno !== 0) {
      console.info(`Extension error code: ${errorInfo.errno}`);
      console.info(`Extension error desc: ${errorInfo.errorDesc}`);
    }
  }
}
```

## Error Information Update Rules

| Scenario | errno | errorDesc |
| ---- | ----- | --------- |
| The key management extension returns error information | Specific error code (non-zero) | Description returned by the extension (may be empty) |
| The key management extension does not return error information | Default value 0 or keep the previous value | Default empty string or keep the previous value |

## Precaution

1. This API returns only the detailed error information of the key management extension. HUKS internal errors are thrown through API exceptions.

2. When the key management extension does not return detailed error information (errno is **0**), **errorDesc** is an empty string. In this case, you should determine the error cause based on the error code from the API exception.

3. It is recommended to call **getErrorInfo** immediately after an operation fails to obtain detailed error information. When **errno** is not **0**, the extension has returned error information, and you should prioritize using **errno** to locate the issue.

4. Error information coverage: APIs such as **authUkeyPin**, **getUkeyPinAuthState**, **getProperty**, **setProperty**, **openResource**, **closeResource**, **clearUkeyPinAuthState**, and **getResourceId**.