# net_trafficfilter.h

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=1c24ee8d9bd74d10677c7515e63aa2dee42b5515 translatedAt=2026-08-14T10:24:09.957Z pushedAt=2026-08-17T08:57:35.005Z -->

## Overview

Declares the C APIs for network traffic filtering and redirection. This header file provides APIs for creating and destroying a packet controller, registering packet callbacks, adding and clearing filter rules, as well as creating and destroying a traffic redirector and adding and clearing redirection rules.<br> It applies to scenarios where network packets need to be intercepted, filtered, and redirected at the system level.

**File to include:** <network/netmanager_ext/net_trafficfilter.h>

**Library:** libnet_trafficfilter.so

**System capability:** SystemCapability.Communication.NetManager.NetFirewall

**Since:** 26.0.0

**Related module:** [TrafficFilter](capi-trafficfilter.md)

## Summary

### Functions

| Name | Description |
| -- | -- |
| [int32_t OH_TrafficFilter_CreateRedirector(uint32_t group_id, uint32_t priority, OH_TrafficFilter_Redirector** redirector)](#oh_trafficfilter_createredirector) | Creates a traffic redirection instance to redirect TCP traffic to a proxy server. Resource management: You must call [OH_TrafficFilter_DestroyRedirector](capi-net-trafficfilter-h.md#oh_trafficfilter_destroyredirector) to release resources. If this function fails, no valid redirector is returned. |
| [int32_t OH_TrafficFilter_DestroyRedirector(OH_TrafficFilter_Redirector* redirector)](#oh_trafficfilter_destroyredirector) | Destroys the redirection instance and releases related resources (including rules). After the call, the handle becomes invalid. |
| [int32_t OH_TrafficFilter_AddRedirectRule(OH_TrafficFilter_Redirector* redirector, const OH_TrafficFilter_RedirectRule* rule)](#oh_trafficfilter_addredirectrule) | Adds a TCP traffic redirection rule to redirect matching traffic to the specified proxy server. To clear the redirection rules, call [OH_TrafficFilter_ClearRedirectRule](capi-net-trafficfilter-h.md#oh_trafficfilter_clearredirectrule). |
| [int32_t OH_TrafficFilter_ClearRedirectRule(OH_TrafficFilter_Redirector* redirector)](#oh_trafficfilter_clearredirectrule) | Clears all redirection rules. |
| [int32_t OH_TrafficFilter_QueryProcess(const OH_TrafficFilter_ConnectionInfo* connection_info, OH_TrafficFilter_ProcessInfo* process_info)](#oh_trafficfilter_queryprocess) | Queries the corresponding process information based on the network connection information. Queries the process that initiates a connection based on the five-tuple connection information consisting of the source IP address, destination IP address, source port, destination port, and protocol type. |

## Function Description

### OH_TrafficFilter_CreateRedirector()

```c
int32_t OH_TrafficFilter_CreateRedirector(uint32_t group_id, uint32_t priority, OH_TrafficFilter_Redirector** redirector)
```

**Description**

Creates a traffic redirection instance for redirecting TCP traffic to a proxy server. Resource management: You must call [OH_TrafficFilter_DestroyRedirector](capi-net-trafficfilter-h.md#oh_trafficfilter_destroyredirector) to release the resources. If this function fails, no valid redirector is returned.

**Required permissions:** ohos.permission.kernel.TRAFFIC_FILTER

**Since:** 26.0.0

**Parameters**

| Parameter | Description |
| -- | -- |
| uint32_t group_id | Redirection chain identifier. This is a logical group ID within an app. Multiple redirectors in the same app can use different **group_id** values. The same **group_id** in different apps is automatically isolated. The valid range is [[OH_TRAFFICFILTER_MIN_GROUP_ID](capi-net-trafficfilter-type-h.md#macros), [OH_TRAFFICFILTER_MAX_GROUP_ID](capi-net-trafficfilter-type-h.md#macros)], inclusive of both boundaries. If **group_id** is out of this range, the function returns [OH_TRAFFICFILTER_ERROR_INVALID_PARAM](capi-net-trafficfilter-type-h.md#oh_trafficfilter_errcode). |
| uint32_t priority | Priority. Determines the execution order among chains with different **group_id** values. A smaller value indicates earlier execution. Note: The redirector priority is higher than the packet filter priority. The valid range is [[OH_TRAFFICFILTER_MIN_PRIORITY](capi-net-trafficfilter-type-h.md#macros), [OH_TRAFFICFILTER_MAX_PRIORITY](capi-net-trafficfilter-type-h.md#macros)], inclusive of both boundaries. If priority is out of this range, the function returns [OH_TRAFFICFILTER_ERROR_INVALID_PARAM](capi-net-trafficfilter-type-h.md#oh_trafficfilter_errcode). |
| redirector | Output parameter. Redirection handle on success. |

**Return**

| Type | Description |
| -- | -- |
| int32_t | [OH_TRAFFICFILTER_OK](capi-net-trafficfilter-type-h.md#oh_trafficfilter_errcode) - Success.<br>     [OH_TRAFFICFILTER_ERROR_PERMISSION_DENIED](capi-net-trafficfilter-type-h.md#oh_trafficfilter_errcode) - Permission denied.<br>     [OH_TRAFFICFILTER_ERROR_GROUP_ID_IN_USE](capi-net-trafficfilter-type-h.md#oh_trafficfilter_errcode) - **group_id** already exists.<br>     [OH_TRAFFICFILTER_ERROR_INVALID_PARAM](capi-net-trafficfilter-type-h.md#oh_trafficfilter_errcode) - Invalid parameter. |

### OH_TrafficFilter_DestroyRedirector()

```c
int32_t OH_TrafficFilter_DestroyRedirector(OH_TrafficFilter_Redirector* redirector)
```

**Description**

Destroys a redirection instance and releases related resources (including rules). After this API is called, the handle becomes invalid.

**Required permissions:** ohos.permission.kernel.TRAFFIC_FILTER

**Since:** 26.0.0

**Parameters**

| Parameter | Description |
| -- | -- |
| [OH_TrafficFilter_Redirector](capi-trafficfilter-oh-trafficfilter-redirector.md)* redirector | Handle to the **OH_TrafficFilter_Redirector**. |

**Return**

| Type | Description |
| -- | -- |
| int32_t | [OH_TRAFFICFILTER_OK](capi-net-trafficfilter-type-h.md#oh_trafficfilter_errcode) - Success.<br>     [OH_TRAFFICFILTER_ERROR_PERMISSION_DENIED](capi-net-trafficfilter-type-h.md#oh_trafficfilter_errcode) - Permission denied.<br>     [OH_TRAFFICFILTER_ERROR_INVALID_PARAM](capi-net-trafficfilter-type-h.md#oh_trafficfilter_errcode) - **redirector** is NULL.<br>     [OH_TRAFFICFILTER_ERROR_NOT_FOUND](capi-net-trafficfilter-type-h.md#oh_trafficfilter_errcode) - The specified redirector handle is not found. |

### OH_TrafficFilter_AddRedirectRule()

```c
int32_t OH_TrafficFilter_AddRedirectRule(OH_TrafficFilter_Redirector* redirector, const OH_TrafficFilter_RedirectRule* rule)
```

**Description**

Adds a TCP traffic redirection rule to redirect matching traffic to the specified proxy server. To clear the redirection rule, call [OH_TrafficFilter_ClearRedirectRule](capi-net-trafficfilter-h.md#oh_trafficfilter_clearredirectrule).

**Required permissions:** ohos.permission.kernel.TRAFFIC_FILTER

**Since:** 26.0.0

**Parameters**

| Parameter | Description |
| -- | -- |
| [OH_TrafficFilter_Redirector](capi-trafficfilter-oh-trafficfilter-redirector.md)* redirector | Handle to the **OH_TrafficFilter_Redirector**. |
| rule | Redirection rule, which cannot be NULL. |

**Return**

| Type | Description |
| -- | -- |
| int32_t | [OH_TRAFFICFILTER_OK](capi-net-trafficfilter-type-h.md#oh_trafficfilter_errcode) - Success.<br>     [OH_TRAFFICFILTER_ERROR_PERMISSION_DENIED](capi-net-trafficfilter-type-h.md#oh_trafficfilter_errcode) - Permission denied.<br>     [OH_TRAFFICFILTER_ERROR_INVALID_PARAM](capi-net-trafficfilter-type-h.md#oh_trafficfilter_errcode) - **redirector** or **rule** is NULL.<br>     [OH_TRAFFICFILTER_ERROR_TOO_MANY_RULES](capi-net-trafficfilter-type-h.md#oh_trafficfilter_errcode) - Too many rules are added. |

### OH_TrafficFilter_ClearRedirectRule()

```c
int32_t OH_TrafficFilter_ClearRedirectRule(OH_TrafficFilter_Redirector* redirector)
```

**Description**

Clears all redirection rules.

**Required permissions:** ohos.permission.kernel.TRAFFIC_FILTER

**Since:** 26.0.0

**Parameters**

| Parameter | Description |
| -- | -- |
| [OH_TrafficFilter_Redirector](capi-trafficfilter-oh-trafficfilter-redirector.md)* redirector | Handle to **OH_TrafficFilter_Redirector**. |

**Return**

| Type | Description |
| -- | -- |
| int32_t | [OH_TRAFFICFILTER_OK](capi-net-trafficfilter-type-h.md#oh_trafficfilter_errcode) - Success.<br>     [OH_TRAFFICFILTER_ERROR_PERMISSION_DENIED](capi-net-trafficfilter-type-h.md#oh_trafficfilter_errcode) - Permission denied.<br>     [OH_TRAFFICFILTER_ERROR_INVALID_PARAM](capi-net-trafficfilter-type-h.md#oh_trafficfilter_errcode) - **redirector** is NULL. |

### OH_TrafficFilter_QueryProcess()

```c
int32_t OH_TrafficFilter_QueryProcess(const OH_TrafficFilter_ConnectionInfo* connection_info, OH_TrafficFilter_ProcessInfo* process_info)
```

**Description**

Queries the process information corresponding to the network connection information. Queries the process that initiates a connection based on the five-tuple connection information consisting of the source IP address, destination IP address, source port, destination port, and protocol type.

**Required permissions:** ohos.permission.kernel.TRAFFIC_FILTER

**Since:** 26.0.0

**Parameters**

| Parameter | Description |
| -- | -- |
| [const OH_TrafficFilter_ConnectionInfo](capi-trafficfilter-oh-trafficfilter-connectioninfo.md)* connection_info | Input connection information. |
| process_info | Output process information. |

**Return**

| Type | Description |
| -- | -- |
| int32_t | [OH_TRAFFICFILTER_OK](capi-net-trafficfilter-type-h.md#oh_trafficfilter_errcode) - Success.<br>     [OH_TRAFFICFILTER_ERROR_PERMISSION_DENIED](capi-net-trafficfilter-type-h.md#oh_trafficfilter_errcode) - Permission denied.<br>     [OH_TRAFFICFILTER_ERROR_INVALID_PARAM](capi-net-trafficfilter-type-h.md#oh_trafficfilter_errcode) - Invalid input parameter.<br>     [OH_TRAFFICFILTER_ERROR_NOT_FOUND](capi-net-trafficfilter-type-h.md#oh_trafficfilter_errcode) - Process not found. |