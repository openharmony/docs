# net_ssl_c_type.h


## Overview

Defines data structures for the C APIs of the SSL/TLS certificate chain verification module.

**Library**: libnet_ssl.so

**System capability**: SystemCapability.Communication.NetStack

**Since**: 11

**Related module**: [Netstack](netstack.md)


## Summary


### Structs

| Name| Description|
| -------- | -------- |
| [NetStack_CertBlob](_net_stack___cert_blob.md) | Certificate data structure.|
| [NetStack_CertificatePinning](_net_stack___certificate_pinning.md) | Data structure of the certificate lock information.|
| [NetStack_Certificates](_net_stack___certificates.md) | Data structure of the certificate information.|


### Enums

| Name| Description|
| -------- | -------- |
| [NetStack_CertType](netstack.md#netstack_certtype) { <br>NetStack_CERT_TYPE_PEM = 0, <br>NetStack_CERT_TYPE_DER = 1,<br> NetStack_CERT_TYPE_INVALID <br>} | Certificate type enums.|
| [NetStack_CertificatePinningKind](netstack.md#netstack_certificatepinningkind) {<br>PUBLIC_KEY,<br>} | Certificate lock type.|
| [NetStack_HashAlgorithm](netstack.md#netstack_hashalgorithm) {<br>SHA_256,<br>} | Hash algorithm type.|
