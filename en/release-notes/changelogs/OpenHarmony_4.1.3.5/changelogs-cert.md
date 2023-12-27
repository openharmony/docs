# Certificate Changelog

##  cl.cert.1 Change of X509Crl Interfaces

**Access Level**

Open API

**Reason for Change**

- Changed **X509crl** interfaces to **X509CRL** interfaces to comply with the CRL description defined in specifications.
- Changed the type of **serialNumber** in **getRevokedCert** from number to bigint to comply with the certificate serial number defined in specifications.


**Change Impact**

This change is a non-compatible change. Since API version 11, use **X509CRL** interfaces instead of **X509Crl** interfaces. The interface functionality remains unchanged.

**Change Since**

OpenHarmony SDK 4.1.3.5

**Key API/Component Changes**

Before change:

 ```js
interface X509Crl {
    ...
    getRevokedCert(serialNumber: number): X509CrlEntry;
    getRevokedCertWithCert(cert: X509Cert): X509CrlEntry;
    getRevokedCerts(callback: AsyncCallback<Array<X509CrlEntry>>): void;
    getRevokedCerts(): Promise<Array<X509CrlEntry>>;
    getTbsInfo(): DataBlob;    
    ...
};
function createX509Crl(inStream: EncodingBlob, callback: AsyncCallback<X509Crl>): void;
function createX509Crl(inStream: EncodingBlob): Promise<X509Crl>;
 ```

After change:

 ```js
interface X509CRL {
    ...
    getRevokedCert(serialNumber: bigint): X509CRLEntry;
    getRevokedCertWithCert(cert: X509Cert): X509CRLEntry;
    getRevokedCerts(callback: AsyncCallback<Array<X509CRLEntry>>): void;
    getRevokedCerts(): Promise<Array<X509CRLEntry>>;
    getTBSInfo(): DataBlob;    
    ...
};
function createX509CRL(inStream: EncodingBlob, callback: AsyncCallback<X509CRL>): void;
function createX509CRL(inStream: EncodingBlob): Promise<X509CRL>;
 ```

**Adaptation Guide**

See [Certificate Development Guide](../../../application-dev/security/cert-guidelines.md) and [Certificate APIs](../../../application-dev/reference/apis/js-apis-cert.md).

##  cl.cert.2 X509CrlEntry Interface Change

**Access Level**

Open API

**Reason for Change**

- Changed the **X509CrlEntry** interfaces to **X509CRLEntry** interfaces to comply with the CRL description defined in specifications.

- Changed the type of the return value of **getSerialNumber** from number to bigint to comply with the certificate serial number defined in specifications.

**Change Impact**

This change is a non-compatible change. Since API version 11, use the **X509CRLEntry** interfaces instead of the **X509CrlEntry** interfaces.

**Change Since**

OpenHarmony SDK 4.1.3.5

**Key API/Component Changes**

Before change:

 ```js
interface X509CrlEntry {
  ...
  getSerialNumber(): number;
  ...
}
 ```

After change:

 ```js
interface X509CRLEntry {
  ...
  getSerialNumber(): bigint;
  ...
}
 ```

**Adaptation Guide**

See [Certificate Development Guide](../../../application-dev/security/cert-guidelines.md) and [Certificate APIs](../../../application-dev/reference/apis/js-apis-cert.md).
