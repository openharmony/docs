# Signing and Signature Verification Overview and Algorithm Specifications

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=3780eaa820092ee975c32f64eb288f44d3471751 translatedAt=2026-08-13T08:26:14.284Z pushedAt=2026-08-13T10:20:24.758Z -->

After UKey PIN authentication, an app can operate the corresponding key through `resourceId` to perform signing. This capability is implemented through the three-phase API provided by HUKS. The app only needs to specify the corresponding algorithm parameters (including the algorithm type, purpose, padding, and digest).

> **NOTE**
>
> 1. [HUKS_TAG_KEY_CLASS](../../reference/apis-universal-keystore-kit/js-apis-huks.md#hukstag) is used to specify the key managed by the external key management extension.
> 2. During the signing phase in the three-segment operations, **keyAlias** must be set to the value of **resourceId**.
> 3. The finish phase in the three-segment operations releases resources. If an exception occurs during the operation, **abort** is used to release the resources.

## Specifications

The specifications are related to the implementation of the external hardware key management extension, which vary according to vendors.