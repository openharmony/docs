# 基础通信子系统 WIFI Changelog

## cl.arkui.1 getLinkedInfo行为变更

**访问级别**

公开接口

**变更原因**

修改安全问题，该接口仅需要GET_WIFI_INFO权限即可获取到用户当前连接热点的BSSID，从而能够推断当前用户所在的位置，存在安全风险。

**变更影响**

该变更为不兼容变更。

变更前：应用通过获取GET_WIFI_INFO权限即可获取到用户当前连接热点的BSSID。

变更后：应用需要获取GET_WIFI_INFO权限，并且需要申请GET_WIFI_PEERS_MAC权限，才能获取到当前连接热点的BSSID；如果没有申请GET_WIFI_PEERS_MAC权限，那么返回的BSSID为空。

**起始API Level**

API 12

**变更发生版本**

从OpenHarmony 5.0.0.37 版本开始。

**变更的接口/组件**

getLinkedInfo/wifi组件

**适配指导**

默认行为变更，无需适配，但应注意变更后的行为是否对整体应用逻辑产生影响。
