# net_ssl_c.h


## Overview

Defines C APIs for the SSL/TLS certificate chain verification module.

**Library**: libnet_ssl.so

**System capability**: SystemCapability.Communication.NetStack

**Since**: 11

**Related module**: [Netstack](netstack.md)


## Summary


### Callback

| Name| Description|
| -------- | -------- |
| [OH_NetStack_VerifyCertification](netstack.md#oh_netstack_verifycertification) (const struct [NetStack_CertBlob](_net_stack___cert_blob.md) \*cert, const struct [NetStack_CertBlob](_net_stack___cert_blob.md) \*caCert) | Verifies the certificate chain.|
| [OH_NetStack_GetPinSetForHostName](netstack.md#OH_NetStack_GetPinSetForHostName)(const char \*hostname, [NetStack_CertificatePinning](_net_stack___certificate_pinning.md) \*pin) | Obtains the certificate lock information.|
| [OH_NetStack_GetCertificatesForHostName](netstack.md#OH_NetStack_GetCertificatesForHostName)(const char \*hostname, [NetStack_Certificates](_net_stack___certificates.md) \*certs) | Obtains certificate information.|
| [OH_Netstack_DestroyCertificatesContent](netstack.md#OH_Netstack_DestroyCertificatesContent)([NetStack_Certificates](_net_stack___certificates.md) \*certs) | Releases the certificate content.|
