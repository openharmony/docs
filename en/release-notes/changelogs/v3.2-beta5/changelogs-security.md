# Security Subsystem Changelog

## cl.security.1 Change of setSeed() from Asynchronous to Synchronous

**Change Impact**

Behavior of released JavaScript APIs will be changed.
The application needs to adapt these APIs so that it can be properly compiled in the SDK environment of the new version.

**Key API/Component Changes**
API before the change:
setSeed(seed : DataBlob, callback : AsyncCallback\<void>) : void;
setSeed(seed : DataBlob) : Promise\<void>;
API after the change:
setSeed(seed : DataBlob) : void;

**Adaptation Guide**
See **setSeed()** in the following:
[Crypto Framework](../../../application-dev/reference/apis/js-apis-cryptoFramework.md)


## cl.security.2 Move of DataArray from @ohos.security.cryptoFramework.d.ts to @ohos.security.cert.d.ts
**Change Impact**

Behavior of released JavaScript APIs will be changed.
The application needs to adapt these APIs so that it can be properly compiled in the SDK environment of the new version.

**Key API/Component Changes**
Moved **DataArray** from **@ohos.security.cryptoFramework.d.ts** to **@ohos.security.cert.d.ts**.

**Adaptation Guide**
Import and use the new .d.ts file:
import cryptoCert from '@ohos.security.cert';
See the following API reference:
[Certificate](../../../application-dev/reference/apis/js-apis-cert.md)


## cl.security.3 Move of EncodingFormat from @ohos.security.cryptoFramework.d.ts to @ohos.security.cert.d.ts
**Change Impact**

Behavior of released JavaScript APIs will be changed.
The application needs to adapt these APIs so that it can be properly compiled in the SDK environment of the new version.

**Key API/Component Changes**
Moved **EncodingFormat** from **@ohos.security.cryptoFramework.d.ts** to **@ohos.security.cert.d.ts**.

**Adaptation Guide**
Import and use the new .d.ts file:
import cryptoCert from '@ohos.security.cert';
See the following API reference:
[Certificate](../../../application-dev/reference/apis/js-apis-cert.md)


## cl.security.4 Move of EncodingBlob from @ohos.security.cryptoFramework.d.ts to @ohos.security.cert.d.ts
**Change Impact**

Behavior of released JavaScript APIs will be changed.
The application needs to adapt these APIs so that it can be properly compiled in the SDK environment of the new version.

**Key API/Component Changes**
Moved **EncodingBlob** from **@ohos.security.cryptoFramework.d.ts** to **@ohos.security.cert.d.ts**.

**Adaptation Guide**
Import and use the new .d.ts file:
import cryptoCert from '@ohos.security.cert';
See the following API reference:
[Certificate](../../../application-dev/reference/apis/js-apis-cert.md)


## cl.security.5 Move of CertChainData from @ohos.security.cryptoFramework.d.ts to @ohos.security.cert.d.ts
**Change Impact**

Behavior of released JavaScript APIs will be changed.
The application needs to adapt these APIs so that it can be properly compiled in the SDK environment of the new version.

**Key API/Component Changes**
Moved **interface CertChainData** from **@ohos.security.cryptoFramework.d.ts** to **@ohos.security.cert.d.ts**.

**Adaptation Guide**
Import and use the new .d.ts file:
import cryptoCert from '@ohos.security.cert';
See the following API reference:
[Certificate](../../../application-dev/reference/apis/js-apis-cert.md)


## cl.security.6 Move of X509Cert from @ohos.security.cryptoFramework.d.ts to @ohos.security.cert.d.ts
**Change Impact**

Behavior of released JavaScript APIs will be changed.
The application needs to adapt these APIs so that it can be properly compiled in the SDK environment of the new version.

**Key API/Component Changes**
Moved **X509Cert** from **@ohos.security.cryptoFramework.d.ts** to **@ohos.security.cert.d.ts**.

**Adaptation Guide**
Import and use the new .d.ts file:
import cryptoCert from '@ohos.security.cert';
See the following API reference:
[Certificate](../../../application-dev/reference/apis/js-apis-cert.md)


## cl.security.7 Move of createX509Cert from @ohos.security.cryptoFramework.d.ts to @ohos.security.cert.d.ts
**Change Impact**

Behavior of released JavaScript APIs will be changed.
The application needs to adapt these APIs so that it can be properly compiled in the SDK environment of the new version.

**Key API/Component Changes**
Moved **createX509Cert** from **@ohos.security.cryptoFramework.d.ts** to **@ohos.security.cert.d.ts**.

**Adaptation Guide**
Import and use the new .d.ts file:
import cryptoCert from '@ohos.security.cert';
See the following API reference:
[Certificate](../../../application-dev/reference/apis/js-apis-cert.md)


## cl.security.8 Move of X509CrlEntry from @ohos.security.cryptoFramework.d.ts to @ohos.security.cert.d.ts.
**Change Impact**

Behavior of released JavaScript APIs will be changed.
The application needs to adapt these APIs so that it can be properly compiled in the SDK environment of the new version.

**Key API/Component Changes**
Moved **X509CrlEntry** from **@ohos.security.cryptoFramework.d.ts** to **@ohos.security.cert.d.ts**.

**Adaptation Guide**
Import and use the new .d.ts file:
import cryptoCert from '@ohos.security.cert';
See the following API reference:
[Certificate](../../../application-dev/reference/apis/js-apis-cert.md)


## cl.security.9 Move of X509Crl from @ohos.security.cryptoFramework.d.ts to @ohos.security.cert.d.ts
**Change Impact**

Behavior of released JavaScript APIs will be changed.
The application needs to adapt these APIs so that it can be properly compiled in the SDK environment of the new version.

**Key API/Component Changes**
Moved **X509Crl** from **@ohos.security.cryptoFramework.d.ts** to **@ohos.security.cert.d.ts**.

**Adaptation Guide**
Import and use the new .d.ts file:
import cryptoCert from '@ohos.security.cert';
See the following API reference:
[Certificate](../../../application-dev/reference/apis/js-apis-cert.md)


## cl.security.10 Move of createX509Crl from @ohos.security.cryptoFramework.d.ts to @ohos.security.cert.d.ts
**Change Impact**

Behavior of released JavaScript APIs will be changed.
The application needs to adapt these APIs so that it can be properly compiled in the SDK environment of the new version.

**Key API/Component Changes**
Moved **createX509Crl** from **@ohos.security.cryptoFramework.d.ts** to **@ohos.security.cert.d.ts**.

**Adaptation Guide**
Import and use the new .d.ts file:
import cryptoCert from '@ohos.security.cert';
See the following API reference:
[Certificate](../../../application-dev/reference/apis/js-apis-cert.md)


## cl.security.11 Move of CertChainValidator from @ohos.security.cryptoFramework.d.ts to @ohos.security.cert.d.ts
**Change Impact**

Behavior of released JavaScript APIs will be changed.
The application needs to adapt these APIs so that it can be properly compiled in the SDK environment of the new version.

**Key API/Component Changes**
Moved **CertChainValidator** from **@ohos.security.cryptoFramework.d.ts** to **@ohos.security.cert.d.ts**.

**Adaptation Guide**
Import and use the new .d.ts file:
import cryptoCert from '@ohos.security.cert';
See the following API reference:
[Certificate](../../../application-dev/reference/apis/js-apis-cert.md)


## cl.security.12 Move of createCertChainValidator from @ohos.security.cryptoFramework.d.ts to @ohos.security.cert.d.ts
**Change Impact**

Behavior of released JavaScript APIs will be changed.
The application needs to adapt these APIs so that it can be properly compiled in the SDK environment of the new version.

**Key API/Component Changes**
Moved **createCertChainValidator** from **@ohos.security.cryptoFramework.d.ts** to **@ohos.security.cert.d.ts**.

**Adaptation Guide**
Import and use the new .d.ts file:
import cryptoCert from '@ohos.security.cert';
See the following API reference:
[Certificate](../../../application-dev/reference/apis/js-apis-cert.md)


## cl.security.13 Change of getPublicKey() of X509Cert from Asynchronous to Synchronous
**Change Impact**

Behavior of released JavaScript APIs will be changed.
The application needs to adapt these APIs so that it can be properly compiled in the SDK environment of the new version.

**Key API/Component Changes**
API before the change:
getPublicKey(callback : AsyncCallback\<PubKey>) : void;
getPublicKey() : Promise\<PubKey>;
API after the change:
getPublicKey() : cryptoFramework.PubKey;

**Adaptation Guide**
See the following API reference:
[Certificate](../../../application-dev/reference/apis/js-apis-cert.md)


## cl.security.14 Change of checkValidityWithDate of X509Cert from Asynchronous to Synchronous
**Change Impact**

Behavior of released JavaScript APIs will be changed.
The application needs to adapt these APIs so that it can be properly compiled in the SDK environment of the new version.

**Key API/Component Changes**
API before the change:
checkValidityWithDate(date: string, callback : AsyncCallback\<void>) : void;
checkValidityWithDate(date: string) : Promise\<void>;
API after the change:
checkValidityWithDate(date: string) : void;

**Adaptation Guide**
See the following API reference:
[Certificate](../../../application-dev/reference/apis/js-apis-cert.md)


## cl.security.15 Change of getCertIssuer of X509CrlEntry from Asynchronous to Synchronous
**Change Impact**

Behavior of released JavaScript APIs will be changed.
The application needs to adapt these APIs so that it can be properly compiled in the SDK environment of the new version.

**Key API/Component Changes**
API before the change:
getCertIssuer(callback : AsyncCallback\<DataBlob>) : void;
getCertIssuer() : Promise\<DataBlob>;

API after the change:
getCertIssuer() : DataBlob;

**Adaptation Guide**
See the following API reference:
[Certificate](../../../application-dev/reference/apis/js-apis-cert.md)


## cl.security.16 Change of getRevocationDate of X509CrlEntry from Asynchronous to Synchronous
**Change Impact**

Behavior of released JavaScript APIs will be changed.
The application needs to adapt these APIs so that it can be properly compiled in the SDK environment of the new version.

**Key API/Component Changes**
API before the change:
getRevocationDate(callback : AsyncCallback\<string>) : void;
getRevocationDate() : Promise\<string>;

API after the change:
getRevocationDate() : string;

**Adaptation Guide**
See the following API reference:
[Certificate](../../../application-dev/reference/apis/js-apis-cert.md)


## cl.security.17 Change of isRevoked of X509Crl from Asynchronous to Synchronous
**Change Impact**

Behavior of released JavaScript APIs will be changed.
The application needs to adapt these APIs so that it can be properly compiled in the SDK environment of the new version.

**Key API/Component Changes**
API before the change:
isRevoked(cert : X509Cert, callback : AsyncCallback\<boolean>) : void;
isRevoked(cert : X509Cert) : Promise\<boolean>;

API after the change:
isRevoked(cert : X509Cert) : boolean;

**Adaptation Guide**
See the following API reference:
[Certificate](../../../application-dev/reference/apis/js-apis-cert.md)


## cl.security.18 Change of getRevokedCert of X509Crl from Asynchronous to Synchronous
**Change Impact**

Behavior of released JavaScript APIs will be changed.
The application needs to adapt these APIs so that it can be properly compiled in the SDK environment of the new version.

**Key API/Component Changes**
API before the change:
getRevokedCert(serialNumber : number, callback : AsyncCallback\<X509CrlEntry>) : void;
getRevokedCert(serialNumber : number) : Promise\<X509CrlEntry>;

API after the change:
getRevokedCert(serialNumber : number) : X509CrlEntry;

**Adaptation Guide**
See the following API reference:
[Certificate](../../../application-dev/reference/apis/js-apis-cert.md)


## cl.security.19 Change of getRevokedCertWithCert of X509Crl from Asynchronous to Synchronous
**Change Impact**

Behavior of released JavaScript APIs will be changed.
The application needs to adapt these APIs so that it can be properly compiled in the SDK environment of the new version.

**Key API/Component Changes**
API before the change:
getRevokedCertWithCert(cert : X509Cert, callback : AsyncCallback\<X509CrlEntry>) : void;
getRevokedCertWithCert(cert : X509Cert) : Promise\<X509CrlEntry>;

API after the change:
getRevokedCertWithCert(cert : X509Cert) : X509CrlEntry;

**Adaptation Guide**
See the following API reference:
[Certificate](../../../application-dev/reference/apis/js-apis-cert.md)


## cl.security.20 Change of getTbsInfo of X509Crl from Asynchronous to Synchronous
**Change Impact**

Behavior of released JavaScript APIs will be changed.
The application needs to adapt these APIs so that it can be properly compiled in the SDK environment of the new version.

**Key API/Component Changes**
API before the change:
getTbsInfo(callback : AsyncCallback\<DataBlob>) : void;
getTbsInfo() : Promise\<DataBlob>;

API after the change:
getTbsInfo() : DataBlob;

**Adaptation Guide**
See the following API reference:
[Certificate](../../../application-dev/reference/apis/js-apis-cert.md)

## cl.security.21 Support of No-Hash Signing Mode for HUKS

Before the change, the application passes **huks.HuksTag.HUKS_TAG_DIGEST = huks.HuksKeyDigest.HUKS_DIGEST_NONE** and HUKS uses **huks.HuksKeyDigest.HUKS_DIGEST_SHA256** for processing by default. After the change, the application passes **huks.HuksTag.HUKS_TAG_DIGEST = huks.HuksKeyDigest.HUKS_DIGEST_NONE** and HUKS does not generate a digest by default. Instead, the service performs a hash operation on the original data and then passes a hashed digest to HUKS for signing or signature verification.

**Change Impact**

Behavior of released JavaScript APIs will be changed.
The application needs to adapt these APIs so that the signing or signature verification result can be passed before and after the change.

**Key API/Component Changes**

Released JavaScript APIs remain unchanged, but parameter sets passed to the APIs are changed.

The service uses the No-Hash signing mode, and hashes the original data and then passes a hashed digest to the signing or signature verification API of HUKS. In addition, the **huks.HuksTag.HUKS_TAG_DIGEST** parameter is set to **huks.HuksKeyDigest.HUKS_DIGEST_NONE**.

**Adaptation Guide**

The following uses signing as an example.

```js
import huks from '@ohos.security.huks';

let keyAlias = 'rsa_Key';
/* Digest value after SHA-256 encryption */
let inDataAfterSha256 = new Uint8Array(
    0x4B, 0x1E, 0x22, 0x64, 0xA9, 0x89, 0x60, 0x1D, 0xEC, 0x78, 0xC0, 0x5D, 0xBE, 0x46, 0xAD, 0xCF,
    0x1C, 0x35, 0x16, 0x11, 0x34, 0x01, 0x4E, 0x9B, 0x7C, 0x00, 0x66, 0x0E, 0xCA, 0x09, 0xC0, 0xF3,
);
/* Signing parameters */
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
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_NONE, // Set digest-none.
}
let signOptions = {
    properties: signProperties,
    inData: inDataAfterSha256 // Set the value after hashing.
}

huks.initSession(keyAlias, signOptions);
```

For for information about the sample code, see [HUKS Development](../../../application-dev/security/huks-guidelines.md) and [HUKS](../../../application-dev/reference/apis/js-apis-huks.md).

## cl.security.22 Support for Key Calculation Parameter Specifications During Key Usage

Before the change, all parameters for key calculation must be specified when the application generates a key. After the change, only mandatory parameters need to be specified when the application generates a key, and other parameters can be passed in when the key is used. The application can specify key calculation parameters more flexibly.

**Change Impact**

Behavior of released JavaScript APIs will be changed.

The application can specify only mandatory parameters when creating a key and specify other optional parameters when using the key.

**Key API/Component Changes**

Released JavaScript APIs remain unchanged, but parameter sets passed to the APIs are changed and parameters are classified into mandatory parameters and optional parameters. For details, see [HUKS Development](../../../application-dev/security/huks-guidelines.md).

huks.generateKeyItem

huks.importKeyItem

huks.importWrappedKeyItem

huks.initSession

huks.updateSession

huks.finishSession

**Adaptation Guide**

The following uses the key generation process as an example.

```js
let keyAlias = 'keyAlias';
let properties = new Array();
// Mandatory parameter.
properties[0] = {
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_RSA
};
// Mandatory parameter.
properties[1] = {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_RSA_KEY_SIZE_2048
};
// Mandatory parameter.
properties[2] = {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value:
    huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_SIGN |
    huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_VERIFY
};
// Optional parameter. If this parameter is not specified when a key is generated, it must be specified when the key is used.
properties[3] = {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256
};
let options = {
    properties: properties
};
try {
    huks.generateKeyItem(keyAlias, options, function (error, data) {
        if (error) {
            console.error(`callback: generateKeyItem failed, code: ${error.code}, msg: ${error.message}`);
        } else {
            console.info(`callback: generateKeyItem key success`);
        }
    });
} catch (error) {
    console.error(`callback: generateKeyItem input arg invalid, code: ${error.code}, msg: ${error.message}`);
}
```

For for information about the sample code, see [HUKS Development](../../../application-dev/security/huks-guidelines.md) and [HUKS](../../../application-dev/reference/apis/js-apis-huks.md).
