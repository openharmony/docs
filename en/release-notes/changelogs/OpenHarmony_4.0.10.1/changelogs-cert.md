# Security Subsystem Changelog

##  cl.cert.1 X509Cert.getSerialNumber Deprecated

Deprecated **X509Cert.getSerialNumber()** and replaced it with **X509Cert.getCertSerialNumber()**.

**Change Impact**

**X509Cert.getSerialNumber()** is deprecated since API version 10. **X509Cert.getCertSerialNumber()** should be used to replace **X509Cert.getSerialNumber()** in application development. The API function remains unchanged.

**Key API/Component Changes**

API before change:

 ```js
interface X509Cert {
  ...
  getSerialNumber(): number;
  ...
}
 ```

API after change:

 ```js
interface X509Cert {
  ...
  getCertSerialNumber(): bigint;
  ...
}
 ```

**Adaptation Guide**

See [Certificate Development Guide](../../../application-dev/security/cert-guidelines.md) and [Certificate](../../../application-dev/reference/apis/js-apis-cert.md).
