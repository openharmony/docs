# NetStack_CertBlob

## Overview

Defines the certificate data structure.

**Since**: 11

**Related module**: [netstack](capi-netstack.md)

**Header file**: [net_ssl_c_type.h](capi-net-ssl-c-type-h.md)

## Summary

### Member Variables

| Name                                                                       | Description|
|---------------------------------------------------------------------------| -- |
| enum [NetStack_CertType](capi-net-ssl-c-type-h.md#netstack_certtype) type | Certificate type.|
| uint32_t size                                                             | Certificate content length.|
| uint8_t *data                                                             | Certificate data.|
