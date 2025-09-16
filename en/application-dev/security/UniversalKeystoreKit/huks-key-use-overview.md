# General Process of Using a Key

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->

The key generated or imported can be used to perform the following operations to ensure data confidentiality and integrity:

- [Encryption and decryption](huks-encryption-decryption-overview.md)

- [Signing and signature verification](huks-signing-signature-verification-overview.md)

- [Key agreement](huks-key-agreement-overview.md)

- [Key derivation](huks-key-derivation-overview.md)

The common operations provided do not include the secondary identity authentication for key access control. For details, see [HUKS Key Access Control](huks-identity-authentication-overview.md).

## General Development Process

HUKS operates data based on a key session. The general process is as follows:

1. (Mandatory) Initialize a key session using [initSession](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksinitsession9).
   You need to pass in the key alias and key operation parameters. A session handle will be returned after the initialization. The key operation parameters must contain the parameters required by the cipher algorithm, including the cipher algorithm, key size, key purpose, working mode, padding mode, hash mode, IV, nonce, and AAD.

2. (Optional) Process data by segment using [updateSession](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksupdatesession9).
   Process data by segment as required by the cryptographic algorithm in use or if the data to be processed exceeds 100 KB in size. Otherwise, skip this step.

3. (Mandatory) Finish the key session using [finishSession](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksfinishsession9).
   If the data is processes by segment, [huks.finishSession()] processes the last data segment and finishes the key session.

You can use [abortSession](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksabortsession9) to abort the session if an error occurs in any of the preceding steps or the current key operation data is not required.

> **NOTE**
> - For devices with small memory, you are advised to split data based on the storage capability of the device and cyclically call [initSession](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksinitsession9) and [finishSession](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksfinishsession9).
> - The session duration refers to the interval between the [initSession](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksinitsession9) and [finishSession](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksfinishsession9) calls. When the system memory is low, the system clears the timeout sessions. Therefore, the session duration should not be too long (not more than 1 minute).
