# Security Subsystem ChangeLog

## cl.security.1 setSeed API Change of Random from Asynchronous to Synchronous

**Change Impacts**

Behavior of released JavaScript APIs will be changed.
The application needs to adapt these APIs so that it can be properly compiled in the SDK environment of the new version.

**Key API/Component Changes**

API prototype before change:

- setSeed(seed : DataBlob, callback : AsyncCallback\<void>) : void;
- setSeed(seed : DataBlob) : Promise\<void>;

API prototype after change:

setSeed(seed : DataBlob) : void;

**Adaptation Guide**

See the API adaptation guide of **setSeed** in the API reference: [Crypto Framework - API Reference](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis/js-apis-cryptoFramework.md)


## cl.security.2 Migration of interface DataArray from @ohos.security.cryptoFramework.d.ts to @ohos.security.cert.d.ts
**Change Impacts**

Behavior of released JavaScript APIs will be changed.

The application needs to adapt these APIs so that it can be properly compiled in the SDK environment of the new version.

**Key API/Component Changes**

Migrated **interface DataArray** from **@ohos.security.cryptoFramework.d.ts** to **@ohos.security.cert.d.ts**.

**Adaptation Guide**

Import and use the new .d.ts file:

import cryptoCert from '@ohos.security.cert';

See the corresponding API adaptation guide in the API reference: [Certificate - API Reference](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis/js-apis-cert.md)


## cl.security.3 Migration of interface EncodingFormat from @ohos.security.cryptoFramework.d.ts to @ohos.security.cert.d.ts
**Change Impacts**

Behavior of released JavaScript APIs will be changed.

The application needs to adapt these APIs so that it can be properly compiled in the SDK environment of the new version.

**Key API/Component Changes**

Migrated **interface EncodingFormat** from **@ohos.security.cryptoFramework.d.ts** to **@ohos.security.cert.d.ts**.

**Adaptation Guide**

Import and use the new .d.ts file:

import cryptoCert from '@ohos.security.cert';

See the corresponding API adaptation guide in the API reference: [Certificate - API Reference](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis/js-apis-cert.md)


## cl.security.4 Migration of interface EncodingBlob from @ohos.security.cryptoFramework.d.ts to @ohos.security.cert.d.ts
**Change Impacts**

Behavior of released JavaScript APIs will be changed.

The application needs to adapt these APIs so that it can be properly compiled in the SDK environment of the new version.

**Key API/Component Changes**

Migrated **interface EncodingBlob** from **@ohos.security.cryptoFramework.d.ts** to **@ohos.security.cert.d.ts**.

**Adaptation Guide**

Import and use the new .d.ts file:

import cryptoCert from '@ohos.security.cert';

See the corresponding API adaptation guide in the API reference: [Certificate - API Reference](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis/js-apis-cert.md)


## cl.security.5 Migration of interface CertChainData from @ohos.security.cryptoFramework.d.ts to @ohos.security.cert.d.ts
**Change Impacts**

Behavior of released JavaScript APIs will be changed.

The application needs to adapt these APIs so that it can be properly compiled in the SDK environment of the new version.

**Key API/Component Changes**

Migrated **interface CertChainData** from **@ohos.security.cryptoFramework.d.ts** to **@ohos.security.cert.d.ts**.

**Adaptation Guide**

Import and use the new .d.ts file:

import cryptoCert from '@ohos.security.cert';

See the corresponding API adaptation guide in the API reference: [Certificate - API Reference](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis/js-apis-cert.md)


## cl.security.6 Migration of interface X509Cert from @ohos.security.cryptoFramework.d.ts to @ohos.security.cert.d.ts
**Change Impacts**

Behavior of released JavaScript APIs will be changed.

The application needs to adapt these APIs so that it can be properly compiled in the SDK environment of the new version.

**Key API/Component Changes**

Migrated **interface X509Cert** from **@ohos.security.cryptoFramework.d.ts** to **@ohos.security.cert.d.ts**.

**Adaptation Guide**

Import and use the new .d.ts file:

import cryptoCert from '@ohos.security.cert';

See the corresponding API adaptation guide in the API reference: [Certificate - API Reference](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis/js-apis-cert.md)


## cl.security.7 Migration of function createX509Cert from @ohos.security.cryptoFramework.d.ts to @ohos.security.cert.d.ts
**Change Impacts**

Behavior of released JavaScript APIs will be changed.

The application needs to adapt these APIs so that it can be properly compiled in the SDK environment of the new version.

**Key API/Component Changes**

Migrated **function createX509Cert** from **@ohos.security.cryptoFramework.d.ts** to **@ohos.security.cert.d.ts**.

**Adaptation Guide**

Import and use the new .d.ts file:

import cryptoCert from '@ohos.security.cert';

See the corresponding API adaptation guide in the API reference: [Certificate - API Reference](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis/js-apis-cert.md)


## cl.security.8 Migration of interface X509CrlEntry from @ohos.security.cryptoFramework.d.ts to @ohos.security.cert.d.ts.
**Change Impacts**

Behavior of released JavaScript APIs will be changed.

The application needs to adapt these APIs so that it can be properly compiled in the SDK environment of the new version.

**Key API/Component Changes**

Migrated **interface X509CrlEntry** from **@ohos.security.cryptoFramework.d.ts** to **@ohos.security.cert.d.ts**.

**Adaptation Guide**

Import and use the new .d.ts file:

import cryptoCert from '@ohos.security.cert';

See the corresponding API adaptation guide in the API reference: [Certificate - API Reference](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis/js-apis-cert.md)


## cl.security.9 Migration of interface X509Crl from @ohos.security.cryptoFramework.d.ts to @ohos.security.cert.d.ts
**Change Impacts**

Behavior of released JavaScript APIs will be changed.

The application needs to adapt these APIs so that it can be properly compiled in the SDK environment of the new version.

**Key API/Component Changes**

Migrated **interface X509Crl** from **@ohos.security.cryptoFramework.d.ts** to **@ohos.security.cert.d.ts**.

**Adaptation Guide**

Import and use the new .d.ts file:

import cryptoCert from '@ohos.security.cert';

See the corresponding API adaptation guide in the API reference: [Certificate - API Reference](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis/js-apis-cert.md)


## cl.security.10 Migration of function createX509Crl from @ohos.security.cryptoFramework.d.ts to @ohos.security.cert.d.ts
**Change Impacts**

Behavior of released JavaScript APIs will be changed.

The application needs to adapt these APIs so that it can be properly compiled in the SDK environment of the new version.

**Key API/Component Changes**

Migrated **function createX509Crl** from **@ohos.security.cryptoFramework.d.ts** to **@ohos.security.cert.d.ts**.

**Adaptation Guide**

Import and use the new .d.ts file:

import cryptoCert from '@ohos.security.cert';

See the corresponding API adaptation guide in the API reference: [Certificate - API Reference](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis/js-apis-cert.md)


## cl.security.11 Migration of interface CertChainValidator from @ohos.security.cryptoFramework.d.ts to @ohos.security.cert.d.ts
**Change Impacts**

Behavior of released JavaScript APIs will be changed.

The application needs to adapt these APIs so that it can be properly compiled in the SDK environment of the new version.

**Key API/Component Changes**

Migrated **interface CertChainValidator** from **@ohos.security.cryptoFramework.d.ts** to **@ohos.security.cert.d.ts**.

**Adaptation Guide**

Import and use the new .d.ts file:

import cryptoCert from '@ohos.security.cert';

See the corresponding API adaptation guide in the API reference: [Certificate - API Reference](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis/js-apis-cert.md)


## cl.security.12 Migration of function createCertChainValidator from @ohos.security.cryptoFramework.d.ts to @ohos.security.cert.d.ts
**Change Impacts**

Behavior of released JavaScript APIs will be changed.

The application needs to adapt these APIs so that it can be properly compiled in the SDK environment of the new version.

**Key API/Component Changes**

Migrated **function createCertChainValidator** from **@ohos.security.cryptoFramework.d.ts** to **@ohos.security.cert.d.ts**.

**Adaptation Guide**

Import and use the new .d.ts file:

import cryptoCert from '@ohos.security.cert';

See the corresponding API adaptation guide in the API reference: [Certificate - API Reference](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis/js-apis-cert.md)


## cl.security.13 getPublicKey API Change of X509Cert from Asynchronous to Synchronous
**Change Impacts**

Behavior of released JavaScript APIs will be changed.

The application needs to adapt these APIs so that it can be properly compiled in the SDK environment of the new version.

**Key API/Component Changes**

API prototype before change:

- getPublicKey(callback : AsyncCallback\<PubKey>) : void;
- getPublicKey() : Promise\<PubKey>;

API prototype after change:

getPublicKey() : cryptoFramework.PubKey;

**Adaptation Guide**

See the corresponding API adaptation guide in the API reference: [Certificate - API Reference](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis/js-apis-cert.md)


## cl.security.14 checkValidityWithDate API Change of X509Cert from Asynchronous to Synchronous
**Change Impacts**

Behavior of released JavaScript APIs will be changed.

The application needs to adapt these APIs so that it can be properly compiled in the SDK environment of the new version.

**Key API/Component Changes**

API prototype before change:

- checkValidityWithDate(date: string, callback : AsyncCallback\<void>) : void;
- checkValidityWithDate(date: string) : Promise\<void>;

API prototype after change:

checkValidityWithDate(date: string) : void;

**Adaptation Guide**

See the corresponding API adaptation guide in the API reference: [Certificate - API Reference](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis/js-apis-cert.md)


## cl.security.15 getCertIssuer API Change of X509CrlEntry from Asynchronous to Synchronous
**Change Impacts**

Behavior of released JavaScript APIs will be changed.

The application needs to adapt these APIs so that it can be properly compiled in the SDK environment of the new version.

**Key API/Component Changes**

API prototype before change:

- getCertIssuer(callback : AsyncCallback\<DataBlob>) : void;
- getCertIssuer() : Promise\<DataBlob>;

API prototype after change:

getCertIssuer() : DataBlob;

**Adaptation Guide**

See the corresponding API adaptation guide in the API reference: [Certificate - API Reference](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis/js-apis-cert.md)


## cl.security.16 getRevocationDate API Change of X509CrlEntry from Asynchronous to Synchronous
**Change Impacts**

Behavior of released JavaScript APIs will be changed.

The application needs to adapt these APIs so that it can be properly compiled in the SDK environment of the new version.

**Key API/Component Changes**

API prototype before change:

- getRevocationDate(callback : AsyncCallback\<string>) : void;
- getRevocationDate() : Promise\<string>;

API prototype after change:

getRevocationDate() : string;

**Adaptation Guide**

See the corresponding API adaptation guide in the API reference: [Certificate - API Reference](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis/js-apis-cert.md)


## cl.security.17 isRevoked API Change of X509Crl from Asynchronous to Synchronous
**Change Impacts**

Behavior of released JavaScript APIs will be changed.

The application needs to adapt these APIs so that it can be properly compiled in the SDK environment of the new version.

**Key API/Component Changes**

API prototype before change:

- isRevoked(cert : X509Cert, callback : AsyncCallback\<boolean>) : void;
- isRevoked(cert : X509Cert) : Promise\<boolean>;

API prototype after change:

isRevoked(cert : X509Cert) : boolean;

**Adaptation Guide**

See the corresponding API adaptation guide in the API reference: [Certificate - API Reference](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis/js-apis-cert.md)


## cl.security.18 getRevokedCert API Change of X509Crl from Asynchronous to Synchronous
**Change Impacts**

Behavior of released JavaScript APIs will be changed.

The application needs to adapt these APIs so that it can be properly compiled in the SDK environment of the new version.

**Key API/Component Changes**

API prototype before change:

- getRevokedCert(serialNumber : number, callback : AsyncCallback\<X509CrlEntry>) : void;
- getRevokedCert(serialNumber : number) : Promise\<X509CrlEntry>;

API prototype after change:

getRevokedCert(serialNumber : number) : X509CrlEntry;

**Adaptation Guide**

See the corresponding API adaptation guide in the API reference: [Certificate - API Reference](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis/js-apis-cert.md)


## cl.security.19 getRevokedCertWithCert API Change of X509Crl from Asynchronous to Synchronous
**Change Impacts**

Behavior of released JavaScript APIs will be changed.

The application needs to adapt these APIs so that it can be properly compiled in the SDK environment of the new version.

**Key API/Component Changes**

API prototype before change:

- getRevokedCertWithCert(cert : X509Cert, callback : AsyncCallback\<X509CrlEntry>) : void;
- getRevokedCertWithCert(cert : X509Cert) : Promise\<X509CrlEntry>;

API prototype after change:

getRevokedCertWithCert(cert : X509Cert) : X509CrlEntry;

**Adaptation Guide**

See the corresponding API adaptation guide in the API reference: [Certificate - API Reference](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis/js-apis-cert.md)


## cl.security.20 getTbsInfo API Change of X509Crl from Asynchronous to Synchronous
**Change Impacts**

Behavior of released JavaScript APIs will be changed.

The application needs to adapt these APIs so that it can be properly compiled in the SDK environment of the new version.

**Key API/Component Changes**

API prototype before change:

- getTbsInfo(callback : AsyncCallback\<DataBlob>) : void;
- getTbsInfo() : Promise\<DataBlob>;

API prototype after change:

getTbsInfo() : DataBlob;

**Adaptation Guide**

See the corresponding API adaptation guide in the API reference: [Certificate - API Reference](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis/js-apis-cert.md)

 <!--no_check--> 