# 网络子系统ChangeLog

## cl.net.1 vpn.createVpnConnection接口开放范围变更

**变更影响**

变更前：由于Vpn相关能力仅支持系统应用使用，定义为system API。虽然vpn.createVpnConnection为public API，但返回的VpnConnection为system API，导致功能不可用。

变更后：为了保持功能开放的一致性，vpn.createVpnConnection变更为system API。vpn所有的接口，目前均为system API。

**关键的接口/组件变更**

vpn.createVpnConnection变更为systemapi。

**适配指导**

如果需要使用vpn相关能力，需使用full-SDK；并修改HarmonyAppProvision配置文件中的app-feature字段为hos_system_app（系统应用）。
