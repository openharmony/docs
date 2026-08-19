# CryptoExtensionAbility Extension Capability Overview

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=f7243bd9bbc19d6bb1c1a460201c8c6cbf7dc7b6 translatedAt=2026-08-13T08:22:47.224Z pushedAt=2026-08-13T10:20:24.687Z -->

**CryptoExtensionAbility** is a derived class of [ExtensionAbility](../../application-models/extensionability-overview.md) in the stage model.

**CryptoExtensionAbility** provides the API definitions required for external key management extension capabilities for driver vendors, including APIs for resource opening or closing, PIN code authentication, signing and signature verification, and certificate export.

CryptoExtensionAbility can isolate the implementation differences of underlying hardware (UKey driver) vendors.

If a third-party driver HAP needs to define its external key management extension capabilities, the following steps are required:

First, the HAP inherits **CryptoExtensionAbility** and implements the related APIs. Then, the HAP calls [registerProvider](../../reference/apis-universal-keystore-kit/js-apis-huksExternalCrypto.md#huksexternalcryptoregisterprovider) to register a Provider. Finally, HUKS and certificate management open the key management extension capabilities for applications.

## Core Capability Implementation

**CryptoExtensionAbility** provides the following capabilities:

1. Device management: A single **ExtensionAbility** can connect to multiple Ukeys.

   - A single **ExtensionAbility** can connect to a maximum of 10 Ukeys.

   - Device hot swap detection and management mechanism needs to be implemented to ensure that **ExtensionAbility** can be notified promptly upon Ukey insertion or removal.

   - Device-level resource isolation needs to be implemented to ensure that the resources of each Ukey are invisible to other Ukeys.

2. Handle management: For the same Ukey resource (for example, the key under a container), handle resources can be managed based on the application level. You can call [onOpenResource](../../reference/apis-universal-keystore-kit/js-apis-CryptoExtensionAbility.md#onopenresource) to open the resource, and call [onCloseResource](../../reference/apis-universal-keystore-kit/js-apis-CryptoExtensionAbility.md#oncloseresource) to close the resource.

   - A single **ExtensionAbility** can open a maximum of 100 Ukey key resource handles.

   - When opening a resource, you need to open the underlying Ukey handle and map it to a new handle for return to HUKS.

   - When closing a resource, you need to close the underlying Ukey handle and release the cached handle mapping.

   - Multiple OpenHarmony applications can open/close the same Ukey key resource. For example, after OpenHarmony application 1 opens container A, OpenHarmony application 2 can also open container A.

   - Multiple OpenHarmony applications can perform operations on the same Ukey key resource. For example, after OpenHarmony application 1 performs private key signing on container A, OpenHarmony application 2 can also perform private key signing on container A after PIN code verification, without affecting each other.

3. Key session management: Three-segment key management is supported. A single signature verification requires the cooperation of three functions [onInitSession](../../reference/apis-universal-keystore-kit/js-apis-CryptoExtensionAbility.md#oninitsession)/[onUpdateSession](../../reference/apis-universal-keystore-kit/js-apis-CryptoExtensionAbility.md#onupdatesession)/[onFinishSession](../../reference/apis-universal-keystore-kit/js-apis-CryptoExtensionAbility.md#onfinishsession) in three steps. Session management needs to be supported to cache the key session state.

   - **init**: Initializes the key session and returns the session handle information.

   - **update**: Passes group data, performs cryptographic operations on the group data, updates the key session information, and returns the intermediate data (if any).

   - **finish**: Passes the last group of data, returns the key, ends the key session, and returns the final result.

4. Authentication state management: Authentication state management (authentication/query/reset) based on the application level is supported. For application A in the same Ukey, after OpenHarmony application 1 verifies the PIN code of Ukey application A, OpenHarmony application 2 also needs to perform PIN code authentication to access Ukey application A.

5. Certificate query: Enumeration of all certificates and query of certificates in a single container based on certificate type are supported.

6. General query: General query operations are supported, providing upper-layer business applications with query capabilities for Ukey device information, PIN code information, public key information, and so on. The attribute ID of the API uses the SKF function names defined in the GMT 0016-2023 standard, and its length must be between 1 and 100 bytes. The caller and the ExtensionAbility implementation need to agree on the set of function names to use and their parameter/return formats.