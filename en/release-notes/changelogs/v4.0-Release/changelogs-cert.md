# Security Changelog

##  cl.cert.1 X509Cert.getSerialNumber Deprecated

Deprecated **X509Cert.getSerialNumber()** and replaced it with **X509Cert.getCertSerialNumber()**.

**Change Impact**

**X509Cert.getSerialNumber()** is deprecated since API version 10. From API versin 10, use **X509Cert.getCertSerialNumber()** instead of **X509Cert.getSerialNumber()** in application development. The API function remains unchanged.

**Key API/Component Changes**

Before change:

 ```js
interface X509Cert {
  ...
  getSerialNumber(): number;
  ...
}
 ```

After change:

 ```js
interface X509Cert {
  ...
  getCertSerialNumber(): bigint;
  ...
}
 ```

**Adaptation Guide**

See [Certificate Development Guide](../../../application-dev/security/cert-guidelines.md) and [Certificate APIs](../../../application-dev/reference/apis/js-apis-cert.md).
