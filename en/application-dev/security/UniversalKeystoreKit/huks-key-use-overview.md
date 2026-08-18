# General Process of Using a Key

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=3780eaa820092ee975c32f64eb288f44d3471751 translatedAt=2026-08-13T08:24:48.865Z pushedAt=2026-08-13T10:20:24.718Z -->

The key generated or imported can be used to perform the following operations to ensure data confidentiality and integrity:

- [Encryption and decryption](huks-encryption-decryption-overview.md)

- [Signing and signature verification](huks-signing-signature-verification-overview.md)

- [Key agreement](huks-key-agreement-overview.md)

- [Key encapsulation](huks-kem-overview.md)

- [Key derivation](huks-key-derivation-overview.md)

This section provides examples of the preceding common key operations. Secondary access control is not configured in the following examples. For details about how to configure key access control, see [HUKS Access Control Overview](huks-identity-authentication-overview.md).

The [Group Key](huks-group-key-overview.md) feature is supported since API version 23.

## General Development Process

HUKS operates data based on a key session. The general process is as follows:

1. (Mandatory) Initialize a key session using [initSession](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksinitsession9).

You need to pass in the key alias and key operation parameters. A session handle will be returned after the initialization. The key operation parameters must contain the parameters required by the corresponding cryptographic algorithm, including the cryptographic algorithm, key size, key purpose, working mode, padding mode, digest mode, IV, NONCE, and AAD.

2. (Optional) Process data by segment using [updateSession](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksupdatesession9).

   Process data by segment as required by the cryptographic algorithm in use or if the data to be processed exceeds 100 KB in size. Otherwise, skip this step.

3. (Mandatory) Finish the key session using [finishSession](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksfinishsession9).

   Process the last data segment and finish the key session.

You can use [abortSession](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksabortsession9) to abort the session if an error occurs in any of the preceding steps or the current key operation data is not required.

> **NOTE**
> - For devices with small memory, you are advised to split data based on the storage capability of the device and cyclically call [initSession](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksinitsession9) and [finishSession](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksfinishsession9).
> - The session duration refers to the interval between the [initSession](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksinitsession9) and [finishSession](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksfinishsession9) calls. When the system memory is low, the system clears the timeout sessions. Therefore, the session duration should not be too long (not more than 1 minute).