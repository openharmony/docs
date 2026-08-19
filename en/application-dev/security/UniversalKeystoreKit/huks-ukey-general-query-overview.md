# General Query Overview and Specifications

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=f7243bd9bbc19d6bb1c1a460201c8c6cbf7dc7b6 translatedAt=2026-08-13T08:25:48.181Z pushedAt=2026-08-13T10:20:24.754Z -->

HUKS provides a property query API to support general query operations from external key management, such as UKey device information and PIN information.

> **NOTE**
>
> 1. The **resourceId** of the [OH_Huks_GetProperty](../../reference/apis-universal-keystore-kit/capi-native-huks-external-crypto-api-h.md#oh_huks_getproperty) and [getProperty](../../reference/apis-universal-keystore-kit/js-apis-huksExternalCrypto.md#huksexternalcryptogetproperty) APIs is the resource ID of the provider, which identifies the remote resource to be queried. Its length must be between 1 and 1024 bytes. The property ID of the APIs uses the SKF function names defined in the GMT 0016-2023 standard, and its length must be between 1 and 100 bytes.
> 2. The output parameter is carried by [HUKS_EXT_CRYPTO_TAG_EXTRA_DATA](../../reference/apis-universal-keystore-kit/js-apis-huksExternalCrypto.md#huksexternalcryptotag). The app can extract the queried property data and parse it according to the agreement with the driver app (the provider of the external key management extension capability).

## Supported Property Function Names (Example)

The following are examples of property function names for reference (for more detailed and authoritative function names, see GMT 0016-2023):

| Function Name| Description|
| -------- | -------- |
| SKF_GetDevInfo | Obtains device information.|
| SKF_EnumDev | Enumerates devices.|
| SKF_EnumContainer | Enumerates containers.|
| SKF_EnumApplication | Enumerates applications.|

> **NOTE**
>
> The actual implementation must be consistent with the function names specified in GMT 0016-2023. The parties (the caller and the CryptoExtension implementation) must agree on the set of function names to use and their parameter/return formats.