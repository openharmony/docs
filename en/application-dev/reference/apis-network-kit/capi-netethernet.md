# NetEthernet

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=bc57903453bfcd5989e08de14dd6cda8d78f3b5d translatedAt=2026-08-14T10:24:37.981Z pushedAt=2026-08-17T08:57:35.010Z -->

## Overview

This module is mainly used to obtain the MAC address list and IP address list of all Ethernet NICs on a device. It applies to scenarios where wired network connection information needs to be obtained.<br> An Ethernet NIC is a wired network interface on a device. Each Ethernet NIC has a unique MAC address (physical address) and a possibly configured IP address. The MAC address is used to uniquely identify a network device on the network, and the IP address is used for network communication.<br> Usage: Call **OH_Ethernet_GetMacAddress** to obtain the MAC address list of Ethernet NICs, and call **OH_Ethernet_GetNetAddress** to obtain the IP address list of Ethernet NICs. The returned data structure contains the interface name and the corresponding address information.<br>

**Since:** 26.0.0

## Summary

| Name | Description |
| -- | -- |
| [net_ethernet.h](capi-net-ethernet-h.md) | Provides C APIs for the Ethernet NIC module. |
| [net_ethernet_type.h](capi-net-ethernet-type-h.md) | Defines data structures for the C APIs of the Ethernet NIC module. |