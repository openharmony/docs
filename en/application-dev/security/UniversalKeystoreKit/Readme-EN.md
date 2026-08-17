# Universal Keystore Kit (Key Management Service)

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=d952bbd31d41cf1a9f05cfda257478eb0904ac62 translatedAt=2026-08-13T08:27:49.945Z pushedAt=2026-08-13T10:20:24.798Z -->

- [About This Kit](huks-overview.md)

- Local Key Management<!--huks-local-key-management-->

  - [Basic Concepts of Local Key Management](huks-concepts.md)

  - Key Generation and Import<!--huks-key-generation-import-->

    - Key Generation<!--huks-key-generation-->

      - [Key Generation Overview and Algorithm Specifications](huks-key-generation-overview.md)

      - [Generating a Key (ArkTS)](huks-key-generation-arkts.md)

      - [Generating a Key (C/C++)](huks-key-generation-ndk.md)

    - Key Import<!--huks-key-import-->

      - [Key Import Overview and Algorithm Specifications](huks-key-import-overview.md)

      - [Importing a Key in Plaintext (ArkTS)](huks-import-key-in-plaintext-arkts.md)

      - [Importing a Key in Plaintext (C/C++)](huks-import-key-in-plaintext-ndk.md)

      - [Importing Keys in Secure Mode (ArkTS)](huks-import-wrapped-key-arkts.md)

      - [Importing a Key in Secure Mode (C/C++)](huks-import-wrapped-key-ndk.md)

      - [Importing a Key Using a Digital Envelope (ArkTS)](huks-import-envelop-key-arkts.md)

      - [Importing a Key Using a Digital Envelope (C/C++)](huks-import-envelop-key-ndk.md)

  - Key Use<!--huks-key-use-->

    - [General Process of Using a Key](huks-key-use-overview.md)

    - Encryption and Decryption<!--huks-encryption-decryption-->

      - [Encryption and Decryption Overview and Algorithm Specifications](huks-encryption-decryption-overview.md)

      - [Encryption and Decryption (ArkTS)](huks-encryption-decryption-arkts.md)

      - [Encryption and Decryption (C/C++)](huks-encryption-decryption-ndk.md)

    - Signing and Signature Verification<!--huks-signing-signature-verification-->

      - [Signing and Signature Verification Overview and Algorithm Specifications](huks-signing-signature-verification-overview.md)

      - [Signing and Signature Verification (ArkTS)](huks-signing-signature-verification-arkts.md)

      - [Signing and Signature Verification (C/C++)](huks-signing-signature-verification-ndk.md)

    - Key Agreement<!--huks-key-agreement-->

      - [Key Agreement Overview and Algorithm Specifications](huks-key-agreement-overview.md)

      - [Key Agreement (ArkTS)](huks-key-agreement-arkts.md)

      - [Key Agreement (C/C++)](huks-key-agreement-ndk.md)

    - Key Encapsulation<!--huks-kem-->

      - [Key Encapsulation Mechanism and Algorithm Specifications](huks-kem-overview.md)

      - [Key Encapsulation (ArkTS)](huks-kem-arkts.md)

    - Key Derivation<!--huks-key-derivation-->

      - [Key Derivation Overview and Algorithm Specifications](huks-key-derivation-overview.md)

      - [Key Derivation (ArkTS)](huks-key-derivation-arkts.md)

      - [Key Derivation (C/C++)](huks-key-derivation-ndk.md)

    - Access Control <!--huks-identity-authentication-->

      - [HUKS Access Control Overview](huks-identity-authentication-overview.md)

      - [HUKS Access Control Development](huks-user-identity-authentication.md)

      - [Refined Access Control Development](huks-refined-user-identity-authentication.md)

    - HMAC<!--huks-hmac-->

      - [HMAC Overview and Algorithm Specifications](huks-hmac-overview.md)

      - [HMAC (ArkTS)](huks-hmac-arkts.md)

      - [HMAC (C/C++)](huks-hmac-ndk.md)<!--RP1--><!--RP1End-->

  - Key Deletion <!--huks-delete-key-->

    - [Deleting a Key (ArkTS)](huks-delete-key-arkts.md)

    - [Deleting a Key (C/C++)](huks-delete-key-ndk.md)

  - Key Attestation<!--huks-key-attestation-->

    - [Key Attestation Overview and Algorithm Specifications](huks-key-attestation-overview.md)

    - [Anonymous Key Attestation (ArkTS)](huks-key-anon-attestation-arkts.md)

    - [Anonymous Key Attestation (C/C++)](huks-key-anon-attestation-ndk.md)

    - [Offline Anonymous Key Attestation (ArkTS)](huks-offline-anon-attestation-arkts.md)<!--RP3--><!--RP3End-->

    <!--Del-->

    - [Non-anonymous Key Attestation (for System Applications Only) (ArkTS)](huks-key-attestation-arkts-sys.md)

    - [Non-anonymous Key Attestation (for System Applications Only) (C/C++)](huks-key-attestation-ndk-sys.md)

    <!--DelEnd-->

  - Other Operations<!--huks-other-operations-->

    - Checking Key Existence<!--huks-check-key-->

      - [Checking a Key (ArkTS)](huks-check-key-arkts.md)

      - [Checking a Key (C/C++)](huks-check-key-ndk.md)

    - Obtaining Key Properties<!--huks-obtain-key-properties-->

      - [Obtaining Key Properties (ArkTS)](huks-obtain-key-properties-arkts.md)

      - [Obtaining Key Properties (C/C++)](huks-obtain-key-properties-ndk.md)

    - Exporting a Key<!--huks-export-key-->

      - [Exporting a Key (ArkTS)](huks-export-key-arkts.md)

      - [Exporting a Key (C/C++)](huks-export-key-ndk.md)

    - Querying Key Aliases<!--huks-list-aliases-->

      - [Querying Key Aliases (ArkTS)](huks-list-aliases-arkts.md)

      - [Querying Key Aliases (C/C++)](huks-list-aliases-ndk.md)<!--RP2--><!--RP2End-->

    - Group Key<!--huks-group-key-->

      - [Group Key Overview](huks-group-key-overview.md)

      - [Group Key (ArkTS)](huks-group-key-arkts.md)

      - [Group Key (C/C++)](huks-group-key-ndk.md)

    <!--Del-->

    - [Specifying the User for Key Operations (for System Applications Only)](huks-as-user-sys.md)

    <!--DelEnd-->

- External Key Management Extension<!--huks-external-key-management-->

  - [External Key Management Extension Overview](huks-external-hardware-key-management-overview.md)

  - Provider Management<!--huks-provider-management-->

    - [Provider Management Overview and Specifications](huks-provider-management-overview.md)

    - [Registering and Unregistering a Provider (ArkTS)](huks-extension-registration-and-unregistration-arkts.md)

    - [Registering and Unregistering a Provider (C/C++)](huks-extension-registration-and-unregistration-ndk.md)

  - Resource Management<!--huks-resource-management-->

    - [Resource Management Overview and Specifications](huks-resource-management-overview.md)

    - [Obtaining a Resource ID (ArkTS)](huks-extension-get-resource-id-arkts.md)

    - [Opening/Closing a Resource (ArkTS)](huks-open-close-resource-arkts.md)

    - [Opening and Closing Resources (C/C++)](huks-open-close-resource-ndk.md)

  - Key Management<!--huks-extension-key-management-->

    - [Key Generation, Import, and Export](huks-extension-key-generation-import-overview.md)

    - [Generating a Key (ArkTS)](huks-extension-key-generation-arkts.md)

    - [Importing a Key (ArkTS)](huks-extension-key-import-arkts.md)

    - [Exporting a Public Key (ArkTS)](huks-extension-key-export-arkts.md)

  - UKey PIN Authentication Management<!--huks-ukey-pin-authentication-management-->

    - [UKey PIN Authentication Overview and Specifications](huks-ukey-pin-authentication-management-overview.md)

    <!--Del-->

    - [UKey PIN Authentication (ArkTS)](huks-ukey-pin-authentication-arkts-sys.md)

    <!--DelEnd-->

    - [Authentication Status Query (ArkTS)](huks-query-authentication-status-arkts.md)

    - [Authentication Status Query (C/C++)](huks-query-authentication-status-ndk.md)

    - [Clearing the UKey PIN Authentication Status (ArkTS)](huks-clear-pin-auth-state-arkts.md)

  - Signing and Signature Verification<!--huks-ukey-signing-signature-verification-->

    - [Signing and Signature Verification Overview and Algorithm Specifications](huks-ukey-signing-signature-verification-overview.md)

    - [Signing and Signature Verification (ArkTS)](huks-ukey-signing-signature-verification-arkts.md)

    - [Signing and Signature Verification (C/C++)](huks-ukey-signing-signature-verification-ndk.md)

  - General Operations<!--huks-ukey-general-operation-->

    - [General Query Overview and Specifications](huks-ukey-general-query-overview.md)

    - [General Query (ArkTS)](huks-ukey-general-query-arkts.md)

    - [General Query (C/C++)](huks-ukey-general-query-ndk.md)

    - [Setting Properties (ArkTS)](huks-extension-set-property-arkts.md)

    - [Obtaining Error Information (ArkTS)](huks-ukey-get-error-info-arkts.md)

  - [UKey Process Example](huks-ukey-best-dev.md)

  - Driver HAP ExtensionAbility Adaptation Guide<!--huks-extension-ability-support-->

    - [CryptoExtensionAbility Extension Capability Overview](huks-extension-ability-support-overview.md)

    - [CryptoExtensionAbility Adaptation Development](huks-extension-ability-support-dev.md)<!--RP4--><!--RP4End-->

- [Glossary](universal-keystore-glossary.md)