# Key Generation, Import, and Export

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=084bf627297e60b1f406ce34f5b473174466f7b3 translatedAt=2026-07-15T02:45:24.584Z pushedAt=2026-07-15T10:58:42.717Z -->

Starting from API version 26.0.0, HUKS provides key generation, import, and export capabilities, supporting key pair generation, encrypted key pair import, or public key export within an extension device in external key management extension scenarios.

## Overview

In the external key management extension scenario, the key generation, import, and export capabilities are provided by [CryptoExtensionAbility](../../reference/apis-universal-keystore-kit/js-apis-CryptoExtensionAbility.md). Device vendors need to inherit **CryptoExtensionAbility** and implement the related APIs.

### Key Generation

Key generation refers to generating an asymmetric key pair (such as an RSA or ECC key pair) within an extension device. The generated key is stored in the extension device, the private key never leaves the extension device, and the public key can be obtained through the export API.

An app initiates a key generation request by calling the HUKS [generateKeyItem](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksgeneratekeyitem9) API, and the request is forwarded to the [onGenerateKeyItem](../../reference/apis-universal-keystore-kit/js-apis-CryptoExtensionAbility.md#ongeneratekeyitem) API of **CryptoExtensionAbility** to complete key generation.

### Secure Key Import

Secure key import refers to importing an encrypted and encapsulated key pair into an extension device. The encrypted and encapsulated key pair is typically encrypted using a securely negotiated key to ensure that the key is not leaked during transmission.

An app initiates a key security import request by calling the [importWrappedKeyItem](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksimportwrappedkeyitem9) API of HUKS. The request is then forwarded to the [onImportWrappedKeyItem](../../reference/apis-universal-keystore-kit/js-apis-CryptoExtensionAbility.md#onimportwrappedkeyitem) API of **CryptoExtensionAbility** to complete the key security import.

### Public Key Export

Public key export refers to exporting the public key of a specified key from an extension device. The exported public key can be used in scenarios such as certificate application and key agreement.

An app initiates a public key export request by calling the HUKS [exportKeyItem](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksexportkeyitem9) API, and the request is forwarded to the [onExportKeyItem](../../reference/apis-universal-keystore-kit/js-apis-CryptoExtensionAbility.md#onexportkeyitem) API of **CryptoExtensionAbility** to complete the public key export.

## Specification Differences

The above APIs reuse the original HUKS API definitions. In the external key management extension scenario, the parameters in `params` are optional, and the supported scope is defined by the extension vendor. If the corresponding parameters are not passed in, the vendor must set default behavior.

- **Key generation (generateKeyItem)**: It is recommended to pass in parameters such as the algorithm type (`HUKS_TAG_ALGORITHM`), key size (`HUKS_TAG_KEY_SIZE`), and key purpose (`HUKS_TAG_PURPOSE`). If not passed in, the vendor must set default values. `keyAlias` must be a valid resource ID.

- **Secure key import (importWrappedKeyItem)**: It is recommended to pass in parameters such as the algorithm type, key size, and key purpose. `keyAlias` and `wrappingKeyAlias` must be valid resource IDs. `wrappedKey` is the wrapped key data, and its format is defined by the extension vendor.

- **Public Key Export (exportKeyItem)**: It is recommended to pass in the key purpose (`HUKS_TAG_PURPOSE`) parameter to export the public key for a specific purpose. If not passed in, the vendor must set a default value (signing purpose is recommended by default). `keyAlias` must be a valid resource ID.

> **NOTE**
>
> In the external key management extension scenario, **keyAlias** passes a resource ID (**resourceId**) instead of a traditional key alias. Both **keyAlias** and **wrappingKeyAlias** must be valid resource IDs, that is, resources opened through [openResource](../../reference/apis-universal-keystore-kit/js-apis-huksExternalCrypto.md#huksexternalcryptoopenresource). In addition, the provider name (**providerName**), external extension name (**abilityName**), and app bundle name (**bundleName**) contained in **keyAlias** and **wrappingKeyAlias** must be consistent.