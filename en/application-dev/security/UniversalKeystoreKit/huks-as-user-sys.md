# Specifying the User for Key Operations (for System Applications Only)

To implement isolation and access control for key data, HUKS provides APIs with the user ID specified for concurrent key operations initiated by multiple users.

## Constraints

- The value range of the user ID is **0** to **99**, including **0** and **99**.
- The APIs are available only for system applications.

# Available APIs

APIs with the **userId** parameter are provided as enhancement to existing APIs. When using these APIs, observe the following:

1. You can also pass in **HUKS_TAG_AUTH_STORAGE_LEVEL** in **options** to specify the security level for key storage.
2. If **HUKS_TAG_AUTH_STORAGE_LEVEL** is not specified in **options**, the key is stored in the directory with the CE level of the user by default, which means **HUKS_AUTH_STORAGE_LEVEL_CE** is used by default.

The algorithm specifications and the usage of the APIs are the same as those of the APIs without **userId**.

| API with userId| Description| API Without userId|
| -------- | -------- | ----------|
| [generateKeyItemAsUser](../../reference/apis-universal-keystore-kit/js-apis-huks-sys.md#huksgeneratekeyitemasuser12)              |   Generates a key.          |  [generateKeyItem](huks-key-generation-arkts.md)             |
| [deleteKeyItemAsUser](../../reference/apis-universal-keystore-kit/js-apis-huks-sys.md#huksdeletekeyitemasuser12)                  |   Deletes a key.          |  [deleteKeyItem](huks-delete-key-arkts.md)               |
| [importKeyItemAsUser](../../reference/apis-universal-keystore-kit/js-apis-huks-sys.md#huksimportkeyitemasuser12)                  |   Imports a key in plaintext.     |  [importKeyItem](huks-import-key-in-plaintext-arkts.md)                |
| [importWrappedKeyItemAsUser](../../reference/apis-universal-keystore-kit/js-apis-huks-sys.md#huksimportwrappedkeyitemasuser12)    |  Imports an encrypted key.       |  [importWrappedKeyItem](huks-import-wrapped-key-arkts.md)             |
| [exportKeyItemAsUser](../../reference/apis-universal-keystore-kit/js-apis-huks-sys.md#huksexportkeyitemasuser12)                  |   Exports a key.       |  [exportKeyItem](huks-export-key-arkts.md)                |
| [getKeyItemPropertiesAsUser](../../reference/apis-universal-keystore-kit/js-apis-huks-sys.md#huksgetkeyitempropertiesasuser12)    |  Obtains key properties.    |  [getKeyItemProperties](huks-obtain-key-properties-arkts.md)             |
| [hasKeyItemAsUser](../../reference/apis-universal-keystore-kit/js-apis-huks-sys.md#hukshaskeyitemasuser12)                        |  Checks whether a key exists.   |  [hasKeyItem](huks-check-key-arkts.md)               |
| [initSessionAsUser](../../reference/apis-universal-keystore-kit/js-apis-huks-sys.md#huksinitsessionasuser12)                      |  Initializes a key session.      |  initSession in [encryption and decryption](huks-encryption-decryption-arkts.md), [signing and signature verification](huks-signing-signature-verification-arkts.md), [key agreement](huks-key-agreement-arkts.md), and [key derivation](huks-key-derivation-arkts.md)          |
| [attestKeyItemAsUser](../../reference/apis-universal-keystore-kit/js-apis-huks-sys.md#huksattestkeyitemasuser12)                  |  Performs non-anonymous key attestation.   |  [attestKeyItem](huks-key-attestation-arkts.md)                |
| [anonAttestKeyItemAsUser](../../reference/apis-universal-keystore-kit/js-apis-huks-sys.md#huksanonattestkeyitemasuser12)          | Performs anonymous key attestation.    |  [anonAttestKeyItem](huks-key-anon-attestation-arkts.md)                |
