# Provider Management Overview and Specifications

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=f7243bd9bbc19d6bb1c1a460201c8c6cbf7dc7b6 translatedAt=2026-08-13T08:25:04.518Z pushedAt=2026-08-13T10:20:24.719Z -->

HUKS provides the registration and deregistration APIs for the external key management extension capability (UKey Extension for short). When a third-party driver HAP detects that a UKey is present, it calls the Provider registration API to register the external key management capability provided by the driver HAP app with the system. When it detects that all UKeys are removed, it calls the Provider deregistration API to deregister the external key management capability it provides from the system.

> **NOTE**
> 1. It is recommended that a Provider name contain the vendor information and be globally unique.
> 2. A Provider name can contain a maximum of 128 bytes.
> 3. The registration and deregistration of a Provider are under permission control. You need to apply for the [ohos.permission.CRYPTO_EXTENSION_REGISTER](../AccessToken/restricted-permissions.md#ohospermissioncrypto_extension_register) permission.
> 4. A Provider can be associated with multiple Abilities. Generally, a Provider is the name of a vendor driver, and an Ability is the name of the extended capability customized by the vendor for each service. The vendor can also determine the names of the Provider and Ability.

**Supported function specifications**

| Function| Description| API Version|
| -------- | -------- | -------- |
| Provider registration| Registers an external key management extension provider to the system.| 22+ |
| Provider unregistration| Unregisters an external key management extension provider from the system.| 22+ |