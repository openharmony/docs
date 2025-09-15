# Http_CustomProxy
<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->
## Overview

Defines the custom proxy configuration.

**Since**: 20

**Related module**: [netstack](capi-netstack.md)

**Header file**: [net_http_type.h](capi-net-http-type-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| const char *host | Host name of the proxy server. If no port is explicitly set, the port number is defaulted to **1080**.|
| int32_t port | Host port. The value range is [0, 65535].|
| const char *exclusionLists | List of the names of hosts that do not use the HTTP proxy server. The host name can be a domain name, IP address, or wildcard.|
