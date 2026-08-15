# Group Key Overview

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=3278ee705378631554cefba415ca42904851087c translatedAt=2026-08-13T08:22:05.549Z pushedAt=2026-08-13T10:20:24.683Z -->

From API version 23, HUKS supports the group key function, which is used to share keys across HAP applications developed by the same developer.

When a group ID is specified for multiple HAP applications in the configuration, the applications can share the same group of key resources. This implements secure reuse of keys in the application ecosystem of a developer, eliminating the need to repeatedly generate or manually transfer keys and simplifying the key management process in cross-application encryption scenarios.

> **NOTE**
>
> - The group key function is supported only on <!--RP1-->standard devices<!--RP1End-->
> - A group key is strictly limited to the HAP applications in the same group of the same developer. The group containing different developers or different groups that the same developer belongs to cannot access each other's group key, ensuring key isolation and security.

## **Specifications**

| Local Key Operation Supported| API Version| Description|
| ---- | ---- | ---- |
| [Key Generation](huks-key-generation-overview.md) | 23+ | Supports generating group keys. |
| [Key Import](huks-key-import-overview.md) | 23+ | Supports importing group keys. |
| [Encryption and decryption](huks-encryption-decryption-overview.md)| 23+ | A group key can be used for encryption and decryption.|
| [Signing and signature verification](huks-signing-signature-verification-overview.md)| 23+ | A group key can be used for signing and signature verification.|
| [Key agreement](huks-key-agreement-overview.md)| 23+ | A group key can be used for key agreement.|
| [Key derivation](huks-key-derivation-overview.md)| 23+ | A group key can be used for key derivation.|
| [Access control](huks-identity-authentication-overview.md)| 23+ | A group key can be used for secondary access control.|
| [HMAC](huks-hmac-overview.md) | 23+ | A group key can be used for HMAC.|
| [Key deletion](huks-delete-key-arkts.md)| 23+ | A group key can be deleted.|
| [Key attestation](huks-key-attestation-overview.md)| 23+ | The validity of a group key can be attested.|
| [Checking whether a key exists](huks-check-key-arkts.md)| 23+ | You can check whether a group key exists.|
| [Key property obtaining](huks-obtain-key-properties-arkts.md)| 23+ | You can query the properties of a group key. You can obtain **DeveloperID** and **GroupID**.|
| [Key export](huks-export-key-arkts.md)| 23+ | A group key can be exported.|
| [Querying key aliases](huks-list-aliases-arkts.md)| 23+ | The alias set of a group key can be queried.|