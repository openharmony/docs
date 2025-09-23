# Http_HeaderValue
<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->
## Overview

Defines the type of a mapped value in a request or response header.

**Since**: 20

**Related module**: [netstack](capi-netstack.md)

**Header file**: [net_http_type.h](capi-net-http-type-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| char *value | Value of a key-value pair in the header.|
| struct [Http_HeaderValue](capi-netstack-http-headervalue.md) *next | Pointer to the next [Http_HeaderValue](capi-netstack-http-headervalue.md) in the data chain.|
