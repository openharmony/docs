# net_ethernet_type.h

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=6994127fda5fa94233d6d71d8b1f4bb64832a6a8 translatedAt=2026-08-14T10:23:48.757Z pushedAt=2026-08-17T08:57:34.999Z -->

## Overview

Defines the data structures for the C APIs of the Ethernet NIC module.

**File to include:** <network/net_ethernet/net_ethernet_type.h>

**Library:** libnet_ethernet.so

**System capability:** SystemCapability.Communication.NetManager.Ethernet

**Since:** 26.0.0

**Related module:** [NetEthernet](capi-netethernet.md)

## Summary

### Structs

| Name | typedef Keyword | Description |
| -- | -- | -- |
| [Ethernet_MacAddressInfo](capi-netethernet-ethernet-macaddressinfo.md) | Ethernet_MacAddressInfo | Defines the MAC address information of an Ethernet NIC. |
| [Ethernet_MacAddrInfoList](capi-netethernet-ethernet-macaddrinfolist.md) | Ethernet_MacAddrInfoList | Defines a list of MAC address information of Ethernet NICs. |
| [Ethernet_NetAddr](capi-netethernet-ethernet-netaddr.md) | Ethernet_NetAddr | Defines a network address. |
| [Ethernet_NetAddrInfo](capi-netethernet-ethernet-netaddrinfo.md) | Ethernet_NetAddrInfo | Defines the network address information of an Ethernet NIC, including the NIC name and network address information. |
| [Ethernet_NetAddrList](capi-netethernet-ethernet-netaddrlist.md) | Ethernet_NetAddrList | Defines a list of network addresses of Ethernet NICs. |

### Macros

| Name | Description |
| -- | -- |
| ETHERNET_MAX_NET_SIZE 32 | Maximum number of Ethernet NIC connections.<br>**Since:** 26.0.0 |
| ETHERNET_MAX_STR_LEN 256 | Maximum length of the MAC address and IP address of an Ethernet NIC.<br>**Since:** 26.0.0 |