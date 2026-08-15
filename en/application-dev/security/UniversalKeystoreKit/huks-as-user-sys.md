# Specifying the User for Key Operations (for System Applications Only)

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=d3532cdb382de60022a0814eb4efa4eadebea1d6 translatedAt=2026-08-13T08:20:23.011Z pushedAt=2026-08-13T10:20:24.671Z -->

To implement isolation and access control for key data, HUKS provides APIs with the user ID specified for concurrent key operations initiated by multiple users.

>**NOTE**
>
> The mini-system devices do not support the operation described in this topic.

## Constraints

- The range of the caller user ID is **0** to **99**, including **0** and **99**.

- The APIs are available only for system applications.

## Available APIs

APIs with the `userId` parameter are provided as enhancement to existing APIs.

When using these APIs, observe the following:

1. The user can also include the [HUKS_TAG_AUTH_STORAGE_LEVEL](../../reference/apis-universal-keystore-kit/js-apis-huks.md#hukstag) tag in the **options** parameter to specify the DE, CE, or ECE zone of the specified user.

2. If no [HUKS_TAG_AUTH_STORAGE_LEVEL](../../reference/apis-universal-keystore-kit/js-apis-huks.md#hukstag) tag is passed through the **options** parameter, the key in the CE storage area with the specified **userId** is used by default. That is, if the **HUKS_TAG_AUTH_STORAGE_LEVEL** parameter is not passed, it is equivalent to passing this parameter with the value [HUKS_AUTH_STORAGE_LEVEL_CE](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksauthstoragelevel11).

The algorithm specifications and the usage of the APIs are the same as those of the APIs without **userId**.

| API with userId| Description| API Without userId|
| -------- | -------- | ----------| 
| [generateKeyItemAsUser](../../reference/apis-universal-keystore-kit/js-apis-huks-sys.md#huksgeneratekeyitemasuser)              |   Generates a key.          |  [generateKeyItem](huks-key-generation-arkts.md)             |
| [deleteKeyItemAsUser](../../reference/apis-universal-keystore-kit/js-apis-huks-sys.md#huksdeletekeyitemasuser)                  |   Deletes a key.          |  [deleteKeyItem](huks-delete-key-arkts.md)               |
| [importKeyItemAsUser](../../reference/apis-universal-keystore-kit/js-apis-huks-sys.md#huksimportkeyitemasuser)                  |   Imports a key in plaintext.     |  [importKeyItem](huks-import-key-in-plaintext-arkts.md)                |
| [importWrappedKeyItemAsUser](../../reference/apis-universal-keystore-kit/js-apis-huks-sys.md#huksimportwrappedkeyitemasuser)    |  Imports keys in secure mode.       |  [importWrappedKeyItem](huks-import-wrapped-key-arkts.md)             |
| [exportKeyItemAsUser](../../reference/apis-universal-keystore-kit/js-apis-huks-sys.md#huksexportkeyitemasuser)                  |   Exports a key.       |  [exportKeyItem](huks-export-key-arkts.md)                |
| [getKeyItemPropertiesAsUser](../../reference/apis-universal-keystore-kit/js-apis-huks-sys.md#huksgetkeyitempropertiesasuser)    |  Obtains key properties.    |  [getKeyItemProperties](huks-obtain-key-properties-arkts.md)             |
| [hasKeyItemAsUser](../../reference/apis-universal-keystore-kit/js-apis-huks-sys.md#hukshaskeyitemasuser)                        |  Checks whether a key exists.   |  [hasKeyItem](huks-check-key-arkts.md)               |
| [initSessionAsUser](../../reference/apis-universal-keystore-kit/js-apis-huks-sys.md#huksinitsessionasuser)                      |  Initializes a key session.      |  initSession in [encryption and decryption](huks-encryption-decryption-arkts.md), [signing and signature verification](huks-signing-signature-verification-arkts.md), [key agreement](huks-key-agreement-arkts.md), and [key derivation](huks-key-derivation-arkts.md)          |
| [attestKeyItemAsUser](../../reference/apis-universal-keystore-kit/js-apis-huks-sys.md#huksattestkeyitemasuser)                  |  Performs non-anonymous key attestation.   |  [attestKeyItem](huks-key-attestation-arkts-sys.md)                |
| [anonAttestKeyItemAsUser](../../reference/apis-universal-keystore-kit/js-apis-huks-sys.md#huksanonattestkeyitemasuser)          | Performs anonymous key attestation.    |  [anonAttestKeyItem](huks-key-anon-attestation-arkts.md)                |