| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|syscap变更|类名：mdns；<br>API声明：type NetAddress = connection.NetAddress;<br>差异内容：NA|类名：mdns；<br>API声明：type NetAddress = connection.NetAddress;<br>差异内容：SystemCapability.Communication.NetManager.Core|api/@ohos.net.mdns.d.ts|
|syscap变更|类名：policy；<br>API声明：type NetBearType = connection.NetBearType;<br>差异内容：NA|类名：policy；<br>API声明：type NetBearType = connection.NetBearType;<br>差异内容：SystemCapability.Communication.NetManager.Core|api/@ohos.net.policy.d.ts|
|syscap变更|类名：sharing；<br>API声明：type NetHandle = connection.NetHandle;<br>差异内容：NA|类名：sharing；<br>API声明：type NetHandle = connection.NetHandle;<br>差异内容：SystemCapability.Communication.NetManager.Core|api/@ohos.net.sharing.d.ts|
|syscap变更|类名：vpn；<br>API声明：export type LinkAddress = connection.LinkAddress;<br>差异内容：NA|类名：vpn；<br>API声明：export type LinkAddress = connection.LinkAddress;<br>差异内容：SystemCapability.Communication.NetManager.Core|api/@ohos.net.vpn.d.ts|
|syscap变更|类名：vpn；<br>API声明：export type RouteInfo = connection.RouteInfo;<br>差异内容：NA|类名：vpn；<br>API声明：export type RouteInfo = connection.RouteInfo;<br>差异内容：SystemCapability.Communication.NetManager.Core|api/@ohos.net.vpn.d.ts|
|函数变更|类名：NetConnection；<br>API声明：on(type: 'netBlockStatusChange', callback: Callback\<{<br>            netHandle: NetHandle;<br>            blocked: boolean;<br>        }>): void;<br>差异内容：callback: Callback\<{<br>            netHandle: NetHandle;<br>            blocked: boolean;<br>        }>|类名：NetConnection；<br>API声明：on(type: 'netBlockStatusChange', callback: Callback\<NetBlockStatusInfo>): void;<br>差异内容：callback: Callback\<NetBlockStatusInfo>|api/@ohos.net.connection.d.ts|
|函数变更|类名：NetConnection；<br>API声明：on(type: 'netConnectionPropertiesChange', callback: Callback\<{<br>            netHandle: NetHandle;<br>            connectionProperties: ConnectionProperties;<br>        }>): void;<br>差异内容：callback: Callback\<{<br>            netHandle: NetHandle;<br>            connectionProperties: ConnectionProperties;<br>        }>|类名：NetConnection；<br>API声明：on(type: 'netConnectionPropertiesChange', callback: Callback\<NetConnectionPropertyInfo>): void;<br>差异内容：callback: Callback\<NetConnectionPropertyInfo>|api/@ohos.net.connection.d.ts|
|函数变更|类名：DiscoveryService；<br>API声明：on(type: 'discoveryStart', callback: Callback\<{<br>            serviceInfo: LocalServiceInfo;<br>            errorCode?: MdnsError;<br>        }>): void;<br>差异内容：callback: Callback\<{<br>            serviceInfo: LocalServiceInfo;<br>            errorCode?: MdnsError;<br>        }>|类名：DiscoveryService；<br>API声明：on(type: 'discoveryStart', callback: Callback\<DiscoveryEventInfo>): void;<br>差异内容：callback: Callback\<DiscoveryEventInfo>|api/@ohos.net.mdns.d.ts|
|函数变更|类名：DiscoveryService；<br>API声明：off(type: 'discoveryStart', callback?: Callback\<{<br>            serviceInfo: LocalServiceInfo;<br>            errorCode?: MdnsError;<br>        }>): void;<br>差异内容：callback?: Callback\<{<br>            serviceInfo: LocalServiceInfo;<br>            errorCode?: MdnsError;<br>        }>|类名：DiscoveryService；<br>API声明：off(type: 'discoveryStart', callback?: Callback\<DiscoveryEventInfo>): void;<br>差异内容：callback?: Callback\<DiscoveryEventInfo>|api/@ohos.net.mdns.d.ts|
|函数变更|类名：DiscoveryService；<br>API声明：on(type: 'discoveryStop', callback: Callback\<{<br>            serviceInfo: LocalServiceInfo;<br>            errorCode?: MdnsError;<br>        }>): void;<br>差异内容：callback: Callback\<{<br>            serviceInfo: LocalServiceInfo;<br>            errorCode?: MdnsError;<br>        }>|类名：DiscoveryService；<br>API声明：on(type: 'discoveryStop', callback: Callback\<DiscoveryEventInfo>): void;<br>差异内容：callback: Callback\<DiscoveryEventInfo>|api/@ohos.net.mdns.d.ts|
|函数变更|类名：DiscoveryService；<br>API声明：off(type: 'discoveryStop', callback?: Callback\<{<br>            serviceInfo: LocalServiceInfo;<br>            errorCode?: MdnsError;<br>        }>): void;<br>差异内容：callback?: Callback\<{<br>            serviceInfo: LocalServiceInfo;<br>            errorCode?: MdnsError;<br>        }>|类名：DiscoveryService；<br>API声明：off(type: 'discoveryStop', callback?: Callback\<DiscoveryEventInfo>): void;<br>差异内容：callback?: Callback\<DiscoveryEventInfo>|api/@ohos.net.mdns.d.ts|
|新增API|NA|类名：connection；<br>API声明：function setAppHttpProxy(httpProxy: HttpProxy): void;<br>差异内容：function setAppHttpProxy(httpProxy: HttpProxy): void;|api/@ohos.net.connection.d.ts|
|新增API|NA|类名：connection；<br>API声明： export interface NetConnectionPropertyInfo<br>差异内容： export interface NetConnectionPropertyInfo|api/@ohos.net.connection.d.ts|
|新增API|NA|类名：NetConnectionPropertyInfo；<br>API声明：netHandle: NetHandle;<br>差异内容：netHandle: NetHandle;|api/@ohos.net.connection.d.ts|
|新增API|NA|类名：NetConnectionPropertyInfo；<br>API声明：connectionProperties: ConnectionProperties;<br>差异内容：connectionProperties: ConnectionProperties;|api/@ohos.net.connection.d.ts|
|新增API|NA|类名：connection；<br>API声明： export interface NetBlockStatusInfo<br>差异内容： export interface NetBlockStatusInfo|api/@ohos.net.connection.d.ts|
|新增API|NA|类名：NetBlockStatusInfo；<br>API声明：netHandle: NetHandle;<br>差异内容：netHandle: NetHandle;|api/@ohos.net.connection.d.ts|
|新增API|NA|类名：NetBlockStatusInfo；<br>API声明：blocked: boolean;<br>差异内容：blocked: boolean;|api/@ohos.net.connection.d.ts|
|新增API|NA|类名：mdns；<br>API声明： export interface DiscoveryEventInfo<br>差异内容： export interface DiscoveryEventInfo|api/@ohos.net.mdns.d.ts|
|新增API|NA|类名：DiscoveryEventInfo；<br>API声明：serviceInfo: LocalServiceInfo;<br>差异内容：serviceInfo: LocalServiceInfo;|api/@ohos.net.mdns.d.ts|
|新增API|NA|类名：DiscoveryEventInfo；<br>API声明：errorCode?: MdnsError;<br>差异内容：errorCode?: MdnsError;|api/@ohos.net.mdns.d.ts|
|新增API|NA|类名：global；<br>API声明： declare namespace vpnExtension<br>差异内容： declare namespace vpnExtension|api/@ohos.net.vpnExtension.d.ts|
|新增API|NA|类名：vpnExtension；<br>API声明：export type LinkAddress = connection.LinkAddress;<br>差异内容：export type LinkAddress = connection.LinkAddress;|api/@ohos.net.vpnExtension.d.ts|
|新增API|NA|类名：vpnExtension；<br>API声明：export type RouteInfo = connection.RouteInfo;<br>差异内容：export type RouteInfo = connection.RouteInfo;|api/@ohos.net.vpnExtension.d.ts|
|新增API|NA|类名：vpnExtension；<br>API声明：function createVpnConnection(context: VpnExtensionContext): VpnConnection;<br>差异内容：function createVpnConnection(context: VpnExtensionContext): VpnConnection;|api/@ohos.net.vpnExtension.d.ts|
|新增API|NA|类名：vpnExtension；<br>API声明： export interface VpnConnection<br>差异内容： export interface VpnConnection|api/@ohos.net.vpnExtension.d.ts|
|新增API|NA|类名：VpnConnection；<br>API声明：create(config: VpnConfig): Promise\<number>;<br>差异内容：create(config: VpnConfig): Promise\<number>;|api/@ohos.net.vpnExtension.d.ts|
|新增API|NA|类名：VpnConnection；<br>API声明：protect(socketFd: number): Promise\<void>;<br>差异内容：protect(socketFd: number): Promise\<void>;|api/@ohos.net.vpnExtension.d.ts|
|新增API|NA|类名：VpnConnection；<br>API声明：destroy(): Promise\<void>;<br>差异内容：destroy(): Promise\<void>;|api/@ohos.net.vpnExtension.d.ts|
|新增API|NA|类名：vpnExtension；<br>API声明： export interface VpnConfig<br>差异内容： export interface VpnConfig|api/@ohos.net.vpnExtension.d.ts|
|新增API|NA|类名：VpnConfig；<br>API声明：addresses: Array\<LinkAddress>;<br>差异内容：addresses: Array\<LinkAddress>;|api/@ohos.net.vpnExtension.d.ts|
|新增API|NA|类名：VpnConfig；<br>API声明：routes?: Array\<RouteInfo>;<br>差异内容：routes?: Array\<RouteInfo>;|api/@ohos.net.vpnExtension.d.ts|
|新增API|NA|类名：VpnConfig；<br>API声明：dnsAddresses?: Array\<string>;<br>差异内容：dnsAddresses?: Array\<string>;|api/@ohos.net.vpnExtension.d.ts|
|新增API|NA|类名：VpnConfig；<br>API声明：searchDomains?: Array\<string>;<br>差异内容：searchDomains?: Array\<string>;|api/@ohos.net.vpnExtension.d.ts|
|新增API|NA|类名：VpnConfig；<br>API声明：mtu?: number;<br>差异内容：mtu?: number;|api/@ohos.net.vpnExtension.d.ts|
|新增API|NA|类名：VpnConfig；<br>API声明：isIPv4Accepted?: boolean;<br>差异内容：isIPv4Accepted?: boolean;|api/@ohos.net.vpnExtension.d.ts|
|新增API|NA|类名：VpnConfig；<br>API声明：isIPv6Accepted?: boolean;<br>差异内容：isIPv6Accepted?: boolean;|api/@ohos.net.vpnExtension.d.ts|
|新增API|NA|类名：VpnConfig；<br>API声明：isInternal?: boolean;<br>差异内容：isInternal?: boolean;|api/@ohos.net.vpnExtension.d.ts|
|新增API|NA|类名：VpnConfig；<br>API声明：isBlocking?: boolean;<br>差异内容：isBlocking?: boolean;|api/@ohos.net.vpnExtension.d.ts|
|新增API|NA|类名：VpnConfig；<br>API声明：trustedApplications?: Array\<string>;<br>差异内容：trustedApplications?: Array\<string>;|api/@ohos.net.vpnExtension.d.ts|
|新增API|NA|类名：VpnConfig；<br>API声明：blockedApplications?: Array\<string>;<br>差异内容：blockedApplications?: Array\<string>;|api/@ohos.net.vpnExtension.d.ts|
|起始版本有变化|类名：mdns；<br>API声明：type NetAddress = connection.NetAddress;<br>差异内容：NA|类名：mdns；<br>API声明：type NetAddress = connection.NetAddress;<br>差异内容：10|api/@ohos.net.mdns.d.ts|
|起始版本有变化|类名：policy；<br>API声明：type NetBearType = connection.NetBearType;<br>差异内容：NA|类名：policy；<br>API声明：type NetBearType = connection.NetBearType;<br>差异内容：10|api/@ohos.net.policy.d.ts|
|起始版本有变化|类名：sharing；<br>API声明：type NetHandle = connection.NetHandle;<br>差异内容：NA|类名：sharing；<br>API声明：type NetHandle = connection.NetHandle;<br>差异内容：9|api/@ohos.net.sharing.d.ts|
|起始版本有变化|类名：vpn；<br>API声明：export type LinkAddress = connection.LinkAddress;<br>差异内容：NA|类名：vpn；<br>API声明：export type LinkAddress = connection.LinkAddress;<br>差异内容：10|api/@ohos.net.vpn.d.ts|
|起始版本有变化|类名：vpn；<br>API声明：export type RouteInfo = connection.RouteInfo;<br>差异内容：NA|类名：vpn；<br>API声明：export type RouteInfo = connection.RouteInfo;<br>差异内容：10|api/@ohos.net.vpn.d.ts|
|kit变更|Network Kit|NetworkKit|api/@ohos.net.connection.d.ts|
|kit变更|Network Kit|NetworkKit|api/@ohos.net.ethernet.d.ts|
|kit变更|Network Kit|NetworkKit|api/@ohos.net.mdns.d.ts|
|kit变更|Network Kit|NetworkKit|api/@ohos.net.policy.d.ts|
|kit变更|Network Kit|NetworkKit|api/@ohos.net.sharing.d.ts|
|kit变更|Network Kit|NetworkKit|api/@ohos.net.statistics.d.ts|
|kit变更|Network Kit|NetworkKit|api/@ohos.net.vpn.d.ts|
|kit变更|Network Kit|NA|api/@system.network.d.ts|
