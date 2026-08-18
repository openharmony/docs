# Offline Anonymous Key Attestation (ArkTS)

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=0746b42c9dbf01beee6196ddda305df16bf5b28b translatedAt=2026-08-13T08:24:34.085Z pushedAt=2026-08-13T10:20:24.714Z -->

Starting from API version 26.0.0, HUKS supports offline anonymous key attestation. This API is used to attest the validity of a key in a network-free environment. Compared with online anonymous key attestation, it does not require a network connection within the validity period of the offline certificate, so offline anonymous key attestation is recommended. The offline certificate is issued by a third-level CA in this process and is valid for one month.

> **NOTE**
>
> - Offline anonymous key attestation depends on the network. You need to periodically connect to the network to use this API to update the offline certificate.
> - Offline anonymous key attestation requires the local time to be accurate. Otherwise, the peer may fail to verify the certificate due to expiration.

## Development Procedure

1. Set a key alias. For details about the naming rules, see [Key Generation Overview and Algorithm Specifications](huks-key-generation-overview.md).

2. Initialize a parameter set.

   The `HuksParam` field in [HuksParam[]](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksparam) must contain the [HUKS_TAG_ATTESTATION_CHALLENGE](../../reference/apis-universal-keystore-kit/js-apis-huks.md#hukstag) attribute. The optional attributes include [HUKS_TAG_ATTESTATION_ID_VERSION_INFO](../../reference/apis-universal-keystore-kit/js-apis-huks.md#hukstag) and [HUKS_TAG_ATTESTATION_ID_ALIAS](../../reference/apis-universal-keystore-kit/js-apis-huks.md#hukstag).

3. Generate an asymmetric key. For details, see [Key Generation](huks-key-generation-overview.md).

4. Use [anonAttestKeyItemOffline](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksanonattestkeyitemoffline) with the key alias and parameter set to perform offline anonymous key attestation.

## Development Cases

``` TypeScript
import { huks } from "@kit.UniversalKeystoreKit";
import { BusinessError } from "@kit.BasicServicesKit";

function StringToUint8Array(str: string) {
  let arr: number[] = new Array();
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let g_challenge: Uint8Array = StringToUint8Array("hi_challenge_data");
let g_keyAlias: Uint8Array = StringToUint8Array("testKey");

let gCommonParam: Array<huks.HuksParam> = [
  { tag: huks.HuksTag.HUKS_TAG_ATTESTATION_CHALLENGE, value: g_challenge },
  { tag: huks.HuksTag.HUKS_TAG_ATTESTATION_ID_ALIAS, value: g_keyAlias },
];

let gKeyParam: Array<huks.HuksParam> = [
  {
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_ECC
  },
  {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_ECC_KEY_SIZE_256
  },
  {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_SIGN | huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_VERIFY
  },
  {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_NONE
  },
  {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256
  }
]

let gKeyOption: huks.HuksOptions = { properties: gKeyParam };

async function AnonAttestKeyOfflineTest() {
  let testKeyAlias: string = "testKey";
  await huks.generateKeyItem(testKeyAlias, gKeyOption);

  await huks.anonAttestKeyItemOffline(testKeyAlias, gCommonParam).then((data) => {
    console.info("anonAttestKeyItemOffline success")
  }).catch((error: BusinessError) =>
    console.error(`anonAttestKeyItemOffline error ${JSON.stringify(error)}`))
}
```