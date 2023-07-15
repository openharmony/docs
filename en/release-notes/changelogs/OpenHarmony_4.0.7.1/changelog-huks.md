# HUKS Changelog

## cl.huks.1 HUKS Supports RsaPssSaltLengthType

Before the change, the HUKS uses **RSA_PSS_SALT_LEN_MAX** for signing or signature verification by default.

After the change, the type defined by **HuksRsaPssSaltLenType** is passed in for signature or signature verification. If **HuksRsaPssSaltLenType** is not passed in, **RSA_PSS_SALT_LEN_MAX** is used by default.

**Change Impact**

Behaviors of released JavaScript APIs have been changed.

**Key API/Component Changes**

Released JavaScript APIs remain unchanged, but the parameter set passed to the APIs are changed.

**Adaptation Guide**

The following uses RSA signing as an example.

```js
import huks from '@ohos.security.huks';

let keyAlias = 'rsa_Key';
let inData = new Uint8Array(
    0x4B, 0x1E, 0x22, 0x64, 0xA9, 0x89, 0x60, 0x1D, 0xEC, 0x78, 0xC0, 0x5D, 0xBE, 0x46, 0xAD, 0xCF,
    0x1C, 0x35, 0x16, 0x11, 0x34, 0x01, 0x4E, 0x9B, 0x7C, 0x00, 0x66, 0x0E, 0xCA, 0x09, 0xC0, 0xF3,
);
/* Parameters for signing */
let signProperties = new Array();
signProperties[0] = {
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_RSA,
}
signProperties[1] = {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value:
    huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_SIGN
}
signProperties[2] = {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_RSA_KEY_SIZE_2048,
}
signProperties[3] = {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_PSS,
}
signProperties[4] = {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_SHA1,
}
signProperties[5] = {
    tag: huks.HuksTag.HUKS_TAG_RSA_PSS_SALT_LEN_TYPE,
    value: huks.HuksRsaPssSaltLenType.HUKS_RSA_PSS_SALT_LEN_MAX,
}
let signOptions = {
    properties: signProperties,
    inData: inData
}

huks.initSession(keyAlias, signOptions);
```

For more information, see [HUKS Development](../../../application-dev/security/huks-guidelines.md) and [HUKS](../../../application-dev/reference/apis/js-apis-huks.md).

## cl.huks.2 Resolved the Issues in Storage or Export of Derived or Agreed Keys

Before the change, the HUKS supports storage and export of derived keys and agreed keys, which poses security risks.

After the change, the application needs to pass in **HuksKeyStorageType** for key derivation or key agreement. Only storage or export is allowed at a time. If this parameter is not passed in, both storage and export are supported by default, which poses security risks and is not recommended.

**Change Impact**

Behaviors of released JavaScript APIs have been changed.

**Key API/Component Changes**

Released JavaScript APIs remain unchanged, but the parameter set passed to the APIs are changed.

**Adaptation Guide**

For more information, see [HUKS Development](../../../application-dev/security/huks-guidelines.md) and [HUKS](../../../application-dev/reference/apis/js-apis-huks.md).

## cl.huks.3 Adding Tags for Fine-grained User Identity Access Control

Added **HUKS_TAG_KEY_AUTH_PURPOSE** to **HuksTag** for fine-grained user identity access control. This tag specifies the user identity authentication used for specific algorithm. 

**Change Impact**

The new HuksTag does not affect existing APIs.

**Key API/Component Changes**

**HuksTag** is added with **HUKS_TAG_KEY_AUTH_PURPOSE** to support fine-grained user identity access control.

**Adaptation Guide**

For more information, see [Fine-grained User Identity Authentication](../../../application-dev/security/huks-guidelines.md#fine-grained-user-identity-authentication) and [HuksTag](../../../application-dev/reference/apis/js-apis-huks.md#hukstag).
