# TrafficFilter

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=e4860fc95c8d8b95b77255afd3be962b586518ba translatedAt=2026-08-14T10:25:53.025Z pushedAt=2026-08-17T08:57:35.027Z -->

## Overview

This module implements network traffic filtering and redirection. Traffic filtering intercepts network data packets in the kernel network protocol stack of the system and allows or discards packets based on preset rules. It applies to scenarios such as firewalls, parental controls, and application traffic management.<br> Traffic redirection forwards TCP traffic that matches rules to a specified proxy server. It applies to scenarios such as enterprise network auditing, content filtering proxies, and VPN transparent proxies.<br> To use this module, first create a controller or redirector instance, then add filtering or redirection rules to manage network traffic. After use, call the corresponding destroy API to release resources.

**Since:** 26.0.0

## File Summary

| Name | Description |
| -- | -- |
| [net_trafficfilter.h](capi-net-trafficfilter-h.md) | Declares the C APIs for network traffic filtering and redirection. This header file provides the APIs for creating and destroying a packet controller, registering packet callbacks, adding and clearing filtering rules, as well as creating and destroying a traffic redirector, and adding and clearing redirection rules.<br> It applies to scenarios where network packets need to be intercepted, filtered, and redirected at the system level. |
| [net_trafficfilter_type.h](capi-net-trafficfilter-type-h.md) | Declares the common types and error codes required for network traffic filtering and redirection. This header file defines the matching condition structs such as IP addresses, ports, and interfaces used in traffic filtering and redirection, the configuration structs such as packet filtering rules and redirection rules, and the error codes returned by operations.<br> It applies to constructing parameters and parsing return values when calling APIs such as [OH_TrafficFilter_CreateRedirector](capi-net-trafficfilter-h.md#oh_trafficfilter_createredirector). |