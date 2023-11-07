# Network Subsystem Changelog

## cl.net.1 vpn.createVpnConnection Changed from Public API to System API

**Change Impact**

Before the change, VPN functions are available only for system applications and related APIs are defined as system APIs. **vpn.createVpnConnection** is a public API, but the returned **VpnConnection** is a system API. This inconsistency results in unavailable VPN functions.

After the change, **vpn.createVpnConnection** is changed to a system API. All VPN-specific APIs are system APIs.

**Key API/Component Changes**

**vpn.createVpnConnection** is changed to a system API.

**Adaptation Guide**

To use VPN functions, use the full-SDK and change the value of **app-feature** in the **HarmonyAppProvision** file to **hos_system_app** (system application).
