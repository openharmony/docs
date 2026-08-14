# General Query (ArkTS)

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=36b64f907faaaf7d23ead95995be1fcb7ed61c89 translatedAt=2026-08-13T08:25:49.163Z pushedAt=2026-08-13T10:20:24.755Z -->

From API version 22, **huksExternalCrypto** provides the general query API. This API can be used to obtain the device ID, application ID, and other general properties from an UKey. For details about the scenarios, see [General Query Overview and Specifications](huks-ukey-general-query-overview.md).

## How to Develop

**Obtaining properties**

1. Obtain the [keyUri](../../reference/apis-device-certificate-kit/js-apis-certManagerDialog.md#certreference22) provided by the certificate management system capability through [openAuthorizeDialog](../../reference/apis-device-certificate-kit/js-apis-certManagerDialog.md#certificatemanagerdialogopenauthorizedialog22) as the `resourceId`, and [open the resource](huks-open-close-resource-ndk.md#opening-resources).

2. Construct the input parameter **propertyId** and optional input parameter [HuksExternalCryptoParam](../../reference/apis-universal-keystore-kit/js-apis-huksExternalCrypto.md#huksexternalcryptoparam).

3. Call [getProperty](../../reference/apis-universal-keystore-kit/js-apis-huksExternalCrypto.md#huksexternalcryptogetproperty) to obtain the property information.

## Development Cases

```ts
import { huksExternalCrypto } from '@kit.UniversalKeystoreKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function getProperty(): Promise<Array<huksExternalCrypto.HuksExternalCryptoParam>> {
  // 1. Obtain resourceId. Assume that resourceId is as follows and the resource has been opened:
  const testResourceId = JSON.stringify({
    providerName: "testProviderName",
    bundleName: "com.example.cryptoapplication",
    abilityName: "CryptoExtension",
    index: {
      key: "testKey"
    } as ESObject
  });

  // 2. Construct the input parameter propertyId and optional parameter HuksExternalCryptoParam.
  let propertyId = "SKF_EnumDev";
  const extProperties: Array<huksExternalCrypto.HuksExternalCryptoParam> = [];

  // 3. Call getProperty to obtain the property information.
  console.info('promise: await huksExternalCrypto getProperty.');
  try {
    await huksExternalCrypto.getProperty(testResourceId, propertyId, extProperties)
      .then((data) => {
        console.info(`promise: getProperty success, data: ` + JSON.stringify(data));
      }).catch((error: BusinessError) => {
        console.error(`promise: getProperty failed, errCode : ${error.code}, errMsg : ${error.message}`);
      })
  } catch (error) {
    console.error(`promise: getProperty failed, errCode : ${error.code}, errMsg : ${error.message}`);
  }
  return extProperties;
}
```