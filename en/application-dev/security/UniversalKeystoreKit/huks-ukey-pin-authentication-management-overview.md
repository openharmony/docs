# UKey PIN Authentication Overview and Specifications

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=f7243bd9bbc19d6bb1c1a460201c8c6cbf7dc7b6 translatedAt=2026-08-13T08:26:57.847Z pushedAt=2026-08-13T10:20:24.762Z -->

A Personal Identification Number (PIN) is a security access credential for a UKey device, which adopts the two-factor authentication mode of "hardware device + PIN". To access the key material in the device, you must have both the physical UKey device and the correct PIN.

The PIN provides the following functions:

1. Anti-brute force cracking: If the number of consecutive incorrect PINs reaches a certain value (related to the external key management extension capability implemented by the driver application), the device is automatically locked.

2. Hardware-level security: PIN verification is performed in the UKey device, so that sensitive information is not leaked out of the device.

A UKey device uses **resourceId** to identify its resources. After an ecosystem app opens a resource, if the app needs to perform a signing operation on the private key corresponding to the resourceId, it must verify the PIN first.

## PIN Authentication Status Management

HUKS provides the following PIN authentication status management capabilities:

- **Querying the authentication status**: Call [getUkeyPinAuthState](../../reference/apis-universal-keystore-kit/js-apis-huksExternalCrypto.md#huksexternalcryptogetukeypinauthstate) to query the current PIN authentication status.

- **Clearing the authentication status**: Since API version 26.0.0, you can use [clearUkeyPinAuthState](../../reference/apis-universal-keystore-kit/js-apis-huksExternalCrypto.md#huksexternalcryptoclearukeypinauthstate) to clear the PIN authentication status of a specified resource.

### Scenarios for Clearing the Authentication Status

The PIN authentication status may need to be cleared in the following scenarios:

- After a key operation is complete, the authentication status is proactively cleared to avoid residual authentication status.

- Clear the authentication status when the application exits or the user is switched.

- Reset the authentication status when it is abnormal.

For a specific development example, see [Clearing UKey PIN Authentication State (ArkTS)](huks-clear-pin-auth-state-arkts.md).

> **NOTE**
>
> HUKS provides the PIN authentication and authentication status query capabilities. Before the PIN authentication, you can query its authentication status. If PIN authentication is required, the [certificate management for applications](../DeviceCertificateKit/certManager-overview.md) needs to be started.