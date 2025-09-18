# Http_ClientCert
<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->
## Overview

Defines the client certificate sent to a remote server, which will be used by the server to verify the identity of the client.

**Since**: 20

**Related module**: [netstack](capi-netstack.md)

**Header file**: [net_http_type.h](capi-net-http-type-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| char *certPath | Path of the certificate file.|
| [Http_CertType](capi-net-http-type-h.md#http_certtype) type | Certificate type. The default value is **PEM**. For details, see [Http_CertType](capi-net-http-type-h.md#http_certtype).|
| char *keyPath | Path of the certificate key file.|
| char *keyPassword | Password of the certificate key file.|
