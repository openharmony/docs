# net_trafficfilter_type.h

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=f5856b06cdc9b56d1c56ad7c6b2cf512309f3b8e translatedAt=2026-08-14T10:24:12.231Z pushedAt=2026-08-17T08:57:35.004Z -->

## Overview

Declares the common types and error codes required for network traffic filtering and redirection. This header file defines the match condition structs for IP addresses, ports, and interfaces used in traffic filtering and redirection, the configuration structs for packet filtering rules and redirection rules, and the error codes returned by operations.<br> It is used to construct parameters and parse return values when calling APIs such as [OH_TrafficFilter_CreateRedirector](capi-net-trafficfilter-h.md#oh_trafficfilter_createredirector).

**File to include:** <network/netmanager_ext/net_trafficfilter_type.h>

**Library:** libnet_trafficfilter.so

**System capability:** SystemCapability.Communication.NetManager.NetFirewall

**Since:** 26.0.0

**Related module:** [TrafficFilter](capi-trafficfilter.md)

## Summary

### Structs

| Name | typedef Keyword | Description |
| -- | -- | -- |
| [OH_TrafficFilter_IPAddress](capi-trafficfilter-oh-trafficfilter-ipaddress.md) | OH_TrafficFilter_IPAddress | IP address in binary form, supporting both IPv4 and IPv6. |
| [OH_TrafficFilter_IPCidr](capi-trafficfilter-oh-trafficfilter-ipcidr.md) | OH_TrafficFilter_IPCidr | IP match value for Classless Inter-Domain Routing (CIDR) matching. |
| [OH_TrafficFilter_IPRange](capi-trafficfilter-oh-trafficfilter-iprange.md) | OH_TrafficFilter_IPRange | IP match value for range matching. |
| [OH_TrafficFilter_IPMulti](capi-trafficfilter-oh-trafficfilter-ipmulti.md) | OH_TrafficFilter_IPMulti | IP match value for multi-IP matching. |
| [OH_TrafficFilter_IPMatch](capi-trafficfilter-oh-trafficfilter-ipmatch.md) | OH_TrafficFilter_IPMatch | IP matching condition. |
| [OH_TrafficFilter_InterfaceMatch](capi-trafficfilter-oh-trafficfilter-interfacematch.md) | OH_TrafficFilter_InterfaceMatch | Interface matching condition. |
| [OH_TrafficFilter_PortRange](capi-trafficfilter-oh-trafficfilter-portrange.md) | OH_TrafficFilter_PortRange | Port match value for range matching. |
| [OH_TrafficFilter_PortMulti](capi-trafficfilter-oh-trafficfilter-portmulti.md) | OH_TrafficFilter_PortMulti | Port match value for multi-port matching. |
| [OH_TrafficFilter_PortMatch](capi-trafficfilter-oh-trafficfilter-portmatch.md) | OH_TrafficFilter_PortMatch | Port matching condition. |
| [OH_TrafficFilter_ConnectionInfo](capi-trafficfilter-oh-trafficfilter-connectioninfo.md) | OH_TrafficFilter_ConnectionInfo | Connection information struct. Describes the 5-tuple information of a network connection (source IP, destination IP, source port, destination port, and protocol type), used to query the process that initiated the connection. Initialization rule: before calling [OH_TrafficFilter_QueryProcess](capi-net-trafficfilter-h.md#oh_trafficfilter_queryprocess), the caller must zero the struct (for example, using **memset**), and then set [size](capi-trafficfilter-oh-trafficfilter-connectioninfo.md#member-variables) to the actual size of the caller-allocated struct, usually **sizeof(OH_TrafficFilter_ConnectionInfo)**. Binary compatibility rule (ABI, that is, application binary interface, to ensure code compiled with old and new versions can recognize each other's struct layout): the system uses [size](capi-trafficfilter-oh-trafficfilter-connectioninfo.md#member-variables) to determine which fields can be safely read. If [size](capi-trafficfilter-oh-trafficfilter-connectioninfo.md#member-variables) is smaller than the minimum size required by the current interface, the interface returns [OH_TRAFFICFILTER_ERROR_INVALID_PARAM](capi-net-trafficfilter-type-h.md#oh_trafficfilter_errcode). If [size](capi-trafficfilter-oh-trafficfilter-connectioninfo.md#member-variables) is larger than the size known to the system, extra fields will be ignored. |
| [OH_TrafficFilter_ProcessInfo](capi-trafficfilter-oh-trafficfilter-processinfo.md) | OH_TrafficFilter_ProcessInfo | Process information struct. Stores the process information returned by [OH_TrafficFilter_QueryProcess](capi-net-trafficfilter-h.md#oh_trafficfilter_queryprocess). Initialization rule: before calling [OH_TrafficFilter_QueryProcess](capi-net-trafficfilter-h.md#oh_trafficfilter_queryprocess), the caller must zero the struct (for example, using **memset**), and then set [size](capi-trafficfilter-oh-trafficfilter-processinfo.md#member-variables) to the actual size of the caller-allocated struct, usually **sizeof(OH_TrafficFilter_ProcessInfo)**. Binary compatibility rule (ABI, that is, application binary interface, to ensure code compiled with old and new versions can recognize each other's struct layout): the system uses [size](capi-trafficfilter-oh-trafficfilter-processinfo.md#member-variables) to determine which output fields can be safely written. Only fields fully covered by [size](capi-trafficfilter-oh-trafficfilter-processinfo.md#member-variables) will be written by the system. If [size](capi-trafficfilter-oh-trafficfilter-processinfo.md#member-variables) is smaller than the minimum size required to read the [size](capi-trafficfilter-oh-trafficfilter-processinfo.md#member-variables) field itself, the interface returns [OH_TRAFFICFILTER_ERROR_INVALID_PARAM](capi-net-trafficfilter-type-h.md#oh_trafficfilter_errcode). If [size](capi-trafficfilter-oh-trafficfilter-processinfo.md#member-variable) is larger than the size known to the system, extra fields will be ignored. Output validity rule: when [OH_TrafficFilter_QueryProcess](capi-net-trafficfilter-h.md#oh_trafficfilter_queryprocess) returns [OH_TRAFFICFILTER_OK](capi-net-trafficfilter-type-h.md#oh_trafficfilter_errcode), the fields covered by [size](capi-trafficfilter-oh-trafficfilter-processinfo.md#member-variables) contain valid output values. When the interface returns an error, the caller should not rely on the values of output fields other than [size](capi-trafficfilter-oh-trafficfilter-processinfo.md#member-variables). |
| [OH_TrafficFilter_RedirectRule](capi-trafficfilter-oh-trafficfilter-redirectrule.md) | OH_TrafficFilter_RedirectRule | Traffic redirection rule. Defines a TCP traffic redirection rule that redirects matching traffic to a specified proxy server. Initialization rule: before calling [OH_TrafficFilter_AddRedirectRule](capi-net-trafficfilter-h.md#oh_trafficfilter_addredirectrule), the caller must zero the struct (for example, using memset), and then set [size](capi-trafficfilter-oh-trafficfilter-redirectrule.md#member-variable) to the actual size of the caller-allocated struct, usually **sizeof(OH_TrafficFilter_RedirectRule)**. Binary compatibility rule (ABI, that is, application binary interface, to ensure code compiled with old and new versions can recognize each other's struct layout): the system uses [size](capi-trafficfilter-oh-trafficfilter-redirectrule.md#member-variables) to determine which fields can be safely read. If [size](capi-trafficfilter-oh-trafficfilter-redirectrule.md#member-variables) is smaller than the minimum size required by the current interface, the interface returns [OH_TRAFFICFILTER_ERROR_INVALID_PARAM](capi-net-trafficfilter-type-h.md#oh_trafficfilter_errcode). If [size](capi-trafficfilter-oh-trafficfilter-redirectrule.md#member-variables) is larger than the size known to the system, extra fields will be ignored. Failure rule: if [OH_TrafficFilter_AddRedirectRule](capi-net-trafficfilter-h.md#oh_trafficfilter_addredirectrule) returns an error, it is not guaranteed that the rule has been added or taken effect. The caller should check the return value before assuming the rule is in effect. |
| [OH_TrafficFilter_Redirector](capi-trafficfilter-oh-trafficfilter-redirector.md) | OH_TrafficFilter_Redirector | Traffic redirector. |

### Enums

| Name | typedef Keyword | Description |
| -- | -- | -- |
| [OH_TrafficFilter_ErrCode](#oh_trafficfilter_errcode) | OH_TrafficFilter_ErrCode | Enumerates the error codes of traffic filtering and redirection. |
| [OH_TrafficFilter_IPMatchType](#oh_trafficfilter_ipmatchtype) | OH_TrafficFilter_IPMatchType | Enumerates the IP match types. |
| [OH_TrafficFilter_IPFamily](#oh_trafficfilter_ipfamily) | OH_TrafficFilter_IPFamily | Enumerates the IP address families. |
| [OH_TrafficFilter_PortMatchType](#oh_trafficfilter_portmatchtype) | OH_TrafficFilter_PortMatchType | Enumerates the port match types. |
| [OH_TrafficFilter_HookPoint](#oh_trafficfilter_hookpoint) | OH_TrafficFilter_HookPoint | Enumerates the hook point types, which specify where rules take effect in the network protocol stack. When packets pass through the kernel network protocol stack, hook points are triggered at different stages, and rules intercept packets at the corresponding hook points. For example, the INPUT chain processes packets entering the local device, and the OUTPUT chain processes packets sent from the local device. |

### Macros

| Name | Description |
| -- | -- |
| OH_TRAFFICFILTER_IP_ADDRLEN       16 | Maximum length of the IP address byte array (compatible with IPv4 and IPv6).<br>**Since:** 26.0.0 |
| OH_TRAFFICFILTER_MAX_MULTI_IP_COUNT  16 | Maximum number of IP addresses supported for multi-IP matching.<br>**Since:** 26.0.0 |
| OH_TRAFFICFILTER_MAX_MULTI_PORT_COUNT 64 | Maximum number of ports supported for multi-port matching.<br>**Since:** 26.0.0 |
| OH_TRAFFICFILTER_NFQUEUE_COPY_META   0 | NFQueue packet copy mode: copies only metadata.<br>**Since:** 26.0.0 |
| OH_TRAFFICFILTER_NFQUEUE_COPY_PACKET 0xFFFF | NFQueue packet copy mode: copies the entire packet.<br>**Since:** 26.0.0 |
| OH_TRAFFICFILTER_DEFAULT_COPY_LEN    0xFFFF | Default NFQueue packet copy length (in bytes). Set to 0xFFFF to copy the entire packet; a smaller value (for example, 128) copies only the packet header.<br>**Since:** 26.0.0 |
| OH_TRAFFICFILTER_DEFAULT_QUEUE_MAXLEN  1024 | Default maximum NFQueue queue length (number of packets).<br>**Since:** 26.0.0 |
| OH_TRAFFICFILTER_NFQUEUE_FLAG_FAIL_OPEN  0x1 | NFQueue queue flag: FAIL-OPEN mode. When the user-space process crashes, the kernel automatically passes packets to avoid network interruption.<br>**Since:** 26.0.0 |
| OH_TRAFFICFILTER_MIN_PRIORITY        1 | Minimum priority value.<br>**Since:** 26.0.0 |
| OH_TRAFFICFILTER_MAX_PRIORITY        10000 | Maximum priority value.<br>**Since:** 26.0.0 |
| OH_TRAFFICFILTER_MIN_GROUP_ID        1 | Minimum group ID value.<br>**Since:** 26.0.0 |
| OH_TRAFFICFILTER_MAX_GROUP_ID        65535 | Maximum group ID value.<br>**Since:** 26.0.0 |
| OH_TRAFFICFILTER_IFNAMSIZ            32 | Maximum length of the network interface name.<br>**Since:** 26.0.0 |
| OH_TRAFFICFILTER_PROTO_ANY           0 | Protocol type constant: any protocol.<br>**Since:** 26.0.0 |
| OH_TRAFFICFILTER_PROTO_TCP           6 | Protocol type constant: TCP.<br>**Since:** 26.0.0 |
| OH_TRAFFICFILTER_PROTO_UDP           17 | Protocol type constant: UDP.<br>**Since:** 26.0.0 |
| OH_TRAFFICFILTER_PROTO_ICMP          1 | Protocol type constant: ICMP.<br>**Since:** 26.0.0 |
| OH_TRAFFICFILTER_PROTO_ICMPV6        58 | Protocol type constant: ICMPv6.<br>**Since:** 26.0.0 |

## Enum Description

### OH_TrafficFilter_ErrCode

```c
enum OH_TrafficFilter_ErrCode
```

**Description**

Enumerates the error codes for traffic filtering and redirection.

**Since:** 26.0.0

| Value | Description |
| -- | -- |
| OH_TRAFFICFILTER_OK = 0 | Operation succeeded.<br>**Since:** 26.0.0 |
| OH_TRAFFICFILTER_E_BASE = 29410000 | Base value of the error codes.<br>**Since:** 26.0.0 |
| OH_TRAFFICFILTER_ERROR_PERMISSION_DENIED = 201 | Permission missing.<br>**Since:** 26.0.0 |
| OH_TRAFFICFILTER_ERROR_INVALID_PARAM = (OH_TRAFFICFILTER_E_BASE + 101) | Invalid parameter (invalid priority, IP address, port, or group ID).<br>**Since:** 26.0.0 |
| OH_TRAFFICFILTER_ERROR_NOT_FOUND = (OH_TRAFFICFILTER_E_BASE + 102) | Resource not found (rule, target, process, or group ID not found).<br>**Since:** 26.0.0 |
| OH_TRAFFICFILTER_ERROR_TOO_MANY_RULES = (OH_TRAFFICFILTER_E_BASE + 103) | Too many rules.<br>**Since:** 26.0.0 |
| OH_TRAFFICFILTER_ERROR_GROUP_ID_IN_USE = (OH_TRAFFICFILTER_E_BASE + 104) | Group ID already in use.<br>**Since:** 26.0.0 |
| OH_TRAFFICFILTER_ERROR_NFQUEUE_ERROR = (OH_TRAFFICFILTER_E_BASE + 105) | NFQueue error (initialization failed or no available queue).<br>**Since:** 26.0.0 |

### OH_TrafficFilter_IPMatchType

```c
enum OH_TrafficFilter_IPMatchType
```

**Description**

Enumerates the IP match types.

**Since:** 26.0.0

| Value | Description |
| -- | -- |
| OH_TRAFFICFILTER_IP_MATCH_ANY = 0 | Any IP.<br>**Since:** 26.0.0 |
| OH_TRAFFICFILTER_IP_MATCH_SINGLE = 1 | Single IP.<br>**Since:** 26.0.0 |
| OH_TRAFFICFILTER_IP_MATCH_CIDR = 2 | CIDR format (for example, 192.168.1.0/24, which matches all IPs in the subnet).<br>**Since:** 26.0.0 |
| OH_TRAFFICFILTER_IP_MATCH_RANGE = 3 | IP range.<br>**Since:** 26.0.0 |
| OH_TRAFFICFILTER_IP_MATCH_MULTI = 4 | Multiple IPs.<br>**Since:** 26.0.0 |

### OH_TrafficFilter_IPFamily

```c
enum OH_TrafficFilter_IPFamily
```

**Description**

Enumerates the IP address families.

**Since:** 26.0.0

| Value | Description |
| -- | -- |
| OH_TRAFFICFILTER_IP_FAMILY_UNSPEC = 0 | Unspecified IP address family.<br>**Since:** 26.0.0 |
| OH_TRAFFICFILTER_IP_FAMILY_V4 = 1 | IPv4 address family.<br>**Since:** 26.0.0 |
| OH_TRAFFICFILTER_IP_FAMILY_V6 = 2 | IPv6 address family.<br>**Since:** 26.0.0 |

### OH_TrafficFilter_PortMatchType

```c
enum OH_TrafficFilter_PortMatchType
```

**Description**

Enumerates the port matching types.

**Since:** 26.0.0

| Value | Description |
| -- | -- |
| OH_TRAFFICFILTER_PORT_MATCH_ANY = 0 | Any port.<br>**Since:** 26.0.0 |
| OH_TRAFFICFILTER_PORT_MATCH_SINGLE = 1 | Single port.<br>**Since:** 26.0.0 |
| OH_TRAFFICFILTER_PORT_MATCH_RANGE = 2 | Port range.<br>**Since:** 26.0.0 |
| OH_TRAFFICFILTER_PORT_MATCH_MULTI = 3 | Multiple ports.<br>**Since:** 26.0.0 |

### OH_TrafficFilter_HookPoint

```c
enum OH_TrafficFilter_HookPoint
```

**Description**

Enumerates the hook point types, which specify where a rule takes effect in the network protocol stack. When a packet passes through the kernel network protocol stack, hook points are triggered at different stages, and rules intercept the packet at the corresponding hook point. For example, the INPUT chain processes packets destined for the local host, and the OUTPUT chain processes packets sent by the local host.

**Since:** 26.0.0

| Value | Description |
| -- | -- |
| OH_TRAFFICFILTER_HOOK_INPUT = 0 | INPUT chain, which processes packets destined for the local host.<br>**Since:** 26.0.0 |
| OH_TRAFFICFILTER_HOOK_OUTPUT = 1 | OUTPUT chain, which processes packets sent by the local host.<br>**Since:** 26.0.0 |
| OH_TRAFFICFILTER_HOOK_FORWARD = 2 | FORWARD chain, which processes packets forwarded by the local host.<br>**Since:** 26.0.0 |
| OH_TRAFFICFILTER_HOOK_PREROUTING = 3 | PREROUTING chain, which processes packets that have just arrived at the NIC and have not been routed yet.<br>**Since:** 26.0.0 |
| OH_TRAFFICFILTER_HOOK_POSTROUTING = 4 | POSTROUTING chain, which processes packets about to be sent from the NIC.<br>**Since:** 26.0.0 |