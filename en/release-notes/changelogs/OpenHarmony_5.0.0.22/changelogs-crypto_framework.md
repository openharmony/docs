# Crypto Framework Changelog

## cl.crypto_architecture.1 Change of Sign.update and Verify.update

**Access Level**

Public

**Reason for Change**

When DSA algorithm is used for signing or signature verification with the digest algorithm set to **NoHash**, **update()** is not supported. However, **update()** returns a success message.

**Change Impact**

This change is a non-compatible change.

Before the change:<br>When DSA is used for signing with the digest algorithm set to **NoHash**, calling **update()** returns a success message, but the signature generated is incorrect.

After the change:<br>When DSA is used for signing with the digest algorithm set to **NoHash**, calling **update()** returns ERR_CRYPTO_OPERATION.

Before the change:<br>When DSA is used to verify the signature data with the digest algorithm set to **NoHash**, calling **update()** returns a success message, but the signature verification fails.

After the change:<br>When DSA is used to verify the signature data with the digest algorithm set to **NoHash**, calling **update()** returns ERR_CRYPTO_OPERATION.

**Start API Level**

10

**Change Since**

OpenHarmony SDK 5.0.0.22

**Key API/Component Changes**

**Sign.update** and **Verify.update** in @ohos.security.cryptoFramework.d.ts

**Adaptation Guide**

When DSA is used for signing or signature verification and the digest algorithm is set to **NoHash**, do not use **update()**. If **Sign.init** and **Sign.sign** are called in signing, use **Verify.init** and **Verify.verify** or the sync APIs in signature verification.
