# 网络管理子系统JS API变更

OpenHarmony 3.1 Release版本相较于OpenHarmony 3.0 LTS版本，网络管理子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.net.webSocket | WebSocket | off(type: 'error', callback?: ErrorCallback): void; | 新增 |
| ohos.net.webSocket | WebSocket | on(type: 'error', callback: ErrorCallback): void; | 新增 |
| ohos.net.webSocket | WebSocket | off(type: 'close', callback?: AsyncCallback\<{ code: number, reason: string }>): void; | 新增 |
| ohos.net.webSocket | WebSocket | on(type: 'close', callback: AsyncCallback\<{ code: number, reason: string }>): void; | 新增 |
| ohos.net.webSocket | WebSocket | off(type: 'message', callback?: AsyncCallback\<string \| ArrayBuffer>): void; | 新增 |
| ohos.net.webSocket | WebSocket | on(type: 'message', callback: AsyncCallback\<string \| ArrayBuffer>): void; | 新增 |
| ohos.net.webSocket | WebSocket | off(type: 'open', callback?: AsyncCallback\<Object>): void; | 新增 |
| ohos.net.webSocket | WebSocket | on(type: 'open', callback: AsyncCallback\<Object>): void; | 新增 |
| ohos.net.webSocket | WebSocket | close(callback: AsyncCallback\<boolean>): void;<br>close(options: WebSocketCloseOptions, callback: AsyncCallback\<boolean>): void;<br>close(options?: WebSocketCloseOptions): Promise\<boolean>; | 新增 |
| ohos.net.webSocket | WebSocket | send(data: string \| ArrayBuffer, callback: AsyncCallback\<boolean>): void;<br>send(data: string \| ArrayBuffer): Promise\<boolean>; | 新增 |
| ohos.net.webSocket | WebSocket | connect(url: string, callback: AsyncCallback\<boolean>): void;<br>connect(url: string, options: WebSocketRequestOptions, callback: AsyncCallback\<boolean>): void;<br>connect(url: string, options?: WebSocketRequestOptions): Promise\<boolean>; | 新增 |
| ohos.net.webSocket | WebSocketCloseOptions | reason?: string; | 新增 |
| ohos.net.webSocket | WebSocketCloseOptions | code?: number; | 新增 |
| ohos.net.webSocket | WebSocketRequestOptions | header?: Object; | 新增 |
| ohos.net.webSocket | webSocket | createWebSocket(): WebSocket; | 新增 |
| ohos.net.socket | TCPSocket | off(type: 'error', callback?: ErrorCallback): void; | 新增 |
| ohos.net.socket | TCPSocket | on(type: 'error', callback: ErrorCallback): void; | 新增 |
| ohos.net.socket | TCPSocket | off(type: 'connect' \| 'close', callback?: Callback\<void>): void; | 新增 |
| ohos.net.socket | TCPSocket | off(type: 'connect' \| 'close', callback?: Callback\<void>): void; | 新增 |
| ohos.net.socket | TCPSocket | on(type: 'connect' \| 'close', callback: Callback\<void>): void; | 新增 |
| ohos.net.socket | TCPSocket | on(type: 'connect' \| 'close', callback: Callback\<void>): void; | 新增 |
| ohos.net.socket | TCPSocket | off(type: 'message', callback?: Callback\<{message: ArrayBuffer, remoteInfo: SocketRemoteInfo}>): void; | 新增 |
| ohos.net.socket | TCPSocket | on(type: 'message', callback: Callback\<{message: ArrayBuffer, remoteInfo: SocketRemoteInfo}>): void; | 新增 |
| ohos.net.socket | TCPSocket | setExtraOptions(options: TCPExtraOptions, callback: AsyncCallback\<void>): void;<br>setExtraOptions(options: TCPExtraOptions): Promise\<void>; | 新增 |
| ohos.net.socket | TCPSocket | getState(callback: AsyncCallback\<SocketStateBase>): void;<br>getState(): Promise\<SocketStateBase>; | 新增 |
| ohos.net.socket | TCPSocket | getRemoteAddress(callback: AsyncCallback\<NetAddress>): void;<br>getRemoteAddress(): Promise\<NetAddress>; | 新增 |
| ohos.net.socket | TCPSocket | close(callback: AsyncCallback\<void>): void;<br>close(): Promise\<void>; | 新增 |
| ohos.net.socket | TCPSocket | send(options: TCPSendOptions, callback: AsyncCallback\<void>): void;<br>send(options: TCPSendOptions): Promise\<void>; | 新增 |
| ohos.net.socket | TCPSocket | connect(options: TCPConnectOptions, callback: AsyncCallback\<void>): void;<br>connect(options: TCPConnectOptions): Promise\<void>; | 新增 |
| ohos.net.socket | TCPSocket | bind(address: NetAddress, callback: AsyncCallback\<void>): void;<br>bind(address: NetAddress): Promise\<void>; | 新增 |
| ohos.net.socket | TCPExtraOptions | socketLinger: {on: boolean, linger: number}; | 新增 |
| ohos.net.socket | TCPExtraOptions | TCPNoDelay?: boolean; | 新增 |
| ohos.net.socket | TCPExtraOptions | OOBInline?: boolean; | 新增 |
| ohos.net.socket | TCPExtraOptions | keepAlive?: boolean; | 新增 |
| ohos.net.socket | TCPSendOptions | encoding?: string; | 新增 |
| ohos.net.socket | TCPSendOptions | data: string \| ArrayBuffer; | 新增 |
| ohos.net.socket | TCPConnectOptions | timeout?: number; | 新增 |
| ohos.net.socket | TCPConnectOptions | address: NetAddress; | 新增 |
| ohos.net.socket | UDPSocket | off(type: 'error', callback?: ErrorCallback): void; | 新增 |
| ohos.net.socket | UDPSocket | on(type: 'error', callback: ErrorCallback): void; | 新增 |
| ohos.net.socket | UDPSocket | off(type: 'listening' \| 'close', callback?: Callback\<void>): void; | 新增 |
| ohos.net.socket | UDPSocket | off(type: 'listening' \| 'close', callback?: Callback\<void>): void; | 新增 |
| ohos.net.socket | UDPSocket | on(type: 'listening' \| 'close', callback: Callback\<void>): void; | 新增 |
| ohos.net.socket | UDPSocket | on(type: 'listening' \| 'close', callback: Callback\<void>): void; | 新增 |
| ohos.net.socket | UDPSocket | off(type: 'message', callback?: Callback\<{message: ArrayBuffer, remoteInfo: SocketRemoteInfo}>): void; | 新增 |
| ohos.net.socket | UDPSocket | on(type: 'message', callback: Callback\<{message: ArrayBuffer, remoteInfo: SocketRemoteInfo}>): void; | 新增 |
| ohos.net.socket | UDPSocket | setExtraOptions(options: UDPExtraOptions, callback: AsyncCallback\<void>): void;<br>setExtraOptions(options: UDPExtraOptions): Promise\<void>; | 新增 |
| ohos.net.socket | UDPSocket | getState(callback: AsyncCallback\<SocketStateBase>): void;<br>getState(): Promise\<SocketStateBase>; | 新增 |
| ohos.net.socket | UDPSocket | close(callback: AsyncCallback\<void>): void;<br>close(): Promise\<void>; | 新增 |
| ohos.net.socket | UDPSocket | send(options: UDPSendOptions, callback: AsyncCallback\<void>): void;<br>send(options: UDPSendOptions): Promise\<void>; | 新增 |
| ohos.net.socket | UDPSocket | bind(address: NetAddress, callback: AsyncCallback\<void>): void;<br>bind(address: NetAddress): Promise\<void>; | 新增 |
| ohos.net.socket | SocketRemoteInfo | size: number; | 新增 |
| ohos.net.socket | SocketRemoteInfo | port: number; | 新增 |
| ohos.net.socket | SocketRemoteInfo | family: 'IPv4' \| 'IPv6'; | 新增 |
| ohos.net.socket | SocketRemoteInfo | address: string; | 新增 |
| ohos.net.socket | SocketStateBase | isConnected: boolean; | 新增 |
| ohos.net.socket | SocketStateBase | isClose: boolean; | 新增 |
| ohos.net.socket | SocketStateBase | isBound: boolean; | 新增 |
| ohos.net.socket | UDPExtraOptions | broadcast?: boolean; | 新增 |
| ohos.net.socket | ExtraOptionsBase | socketTimeout?: number; | 新增 |
| ohos.net.socket | ExtraOptionsBase | reuseAddress?: boolean; | 新增 |
| ohos.net.socket | ExtraOptionsBase | sendBufferSize?: number; | 新增 |
| ohos.net.socket | ExtraOptionsBase | receiveBufferSize?: number; | 新增 |
| ohos.net.socket | UDPSendOptions | address: NetAddress; | 新增 |
| ohos.net.socket | UDPSendOptions | data: string \| ArrayBuffer; | 新增 |
| ohos.net.socket | socket | constructTCPSocketInstance(): TCPSocket; | 新增 |
| ohos.net.socket | socket | constructUDPSocketInstance(): UDPSocket; | 新增 |
| ohos.net.socket | socket | import NetAddress = connection.NetAddress; | 新增 |
| ohos.net.http | HttpResponse | cookies: string; | 新增 |
| ohos.net.http | HttpResponse | header: Object; | 新增 |
| ohos.net.http | HttpResponse | responseCode: ResponseCode \| number; | 新增 |
| ohos.net.http | HttpResponse | result: string \| Object \| ArrayBuffer; | 新增 |
| ohos.net.http | ResponseCode | VERSION | 新增 |
| ohos.net.http | ResponseCode | GATEWAY_TIMEOUT | 新增 |
| ohos.net.http | ResponseCode | UNAVAILABLE | 新增 |
| ohos.net.http | ResponseCode | BAD_GATEWAY | 新增 |
| ohos.net.http | ResponseCode | NOT_IMPLEMENTED | 新增 |
| ohos.net.http | ResponseCode | INTERNAL_ERROR = 500 | 新增 |
| ohos.net.http | ResponseCode | UNSUPPORTED_TYPE | 新增 |
| ohos.net.http | ResponseCode | REQ_TOO_LONG | 新增 |
| ohos.net.http | ResponseCode | ENTITY_TOO_LARGE | 新增 |
| ohos.net.http | ResponseCode | PRECON_FAILED | 新增 |
| ohos.net.http | ResponseCode | LENGTH_REQUIRED | 新增 |
| ohos.net.http | ResponseCode | GONE | 新增 |
| ohos.net.http | ResponseCode | CONFLICT | 新增 |
| ohos.net.http | ResponseCode | CLIENT_TIMEOUT | 新增 |
| ohos.net.http | ResponseCode | PROXY_AUTH | 新增 |
| ohos.net.http | ResponseCode | NOT_ACCEPTABLE | 新增 |
| ohos.net.http | ResponseCode | BAD_METHOD | 新增 |
| ohos.net.http | ResponseCode | NOT_FOUND | 新增 |
| ohos.net.http | ResponseCode | FORBIDDEN | 新增 |
| ohos.net.http | ResponseCode | PAYMENT_REQUIRED | 新增 |
| ohos.net.http | ResponseCode | UNAUTHORIZED | 新增 |
| ohos.net.http | ResponseCode | BAD_REQUEST = 400 | 新增 |
| ohos.net.http | ResponseCode | USE_PROXY | 新增 |
| ohos.net.http | ResponseCode | NOT_MODIFIED | 新增 |
| ohos.net.http | ResponseCode | SEE_OTHER | 新增 |
| ohos.net.http | ResponseCode | MOVED_TEMP | 新增 |
| ohos.net.http | ResponseCode | MOVED_PERM | 新增 |
| ohos.net.http | ResponseCode | MULT_CHOICE = 300 | 新增 |
| ohos.net.http | ResponseCode | PARTIAL | 新增 |
| ohos.net.http | ResponseCode | RESET | 新增 |
| ohos.net.http | ResponseCode | NO_CONTENT | 新增 |
| ohos.net.http | ResponseCode | NOT_AUTHORITATIVE | 新增 |
| ohos.net.http | ResponseCode | ACCEPTED | 新增 |
| ohos.net.http | ResponseCode | CREATED | 新增 |
| ohos.net.http | ResponseCode | OK = 200 | 新增 |
| ohos.net.http | RequestMethod | CONNECT = "CONNECT" | 新增 |
| ohos.net.http | RequestMethod | TRACE = "TRACE" | 新增 |
| ohos.net.http | RequestMethod | DELETE = "DELETE" | 新增 |
| ohos.net.http | RequestMethod | PUT = "PUT" | 新增 |
| ohos.net.http | RequestMethod | POST = "POST" | 新增 |
| ohos.net.http | RequestMethod | HEAD = "HEAD" | 新增 |
| ohos.net.http | RequestMethod | GET = "GET" | 新增 |
| ohos.net.http | RequestMethod | OPTIONS = "OPTIONS" | 新增 |
| ohos.net.http | HttpRequest | once(type: "headersReceive", callback: Callback\<Object>): void; | 新增 |
| ohos.net.http | HttpRequest | off(type: "headersReceive", callback?: Callback\<Object>): void; | 新增 |
| ohos.net.http | HttpRequest | on(type: "headersReceive", callback: Callback\<Object>): void; | 新增 |
| ohos.net.http | HttpRequest | off(type: "headerReceive", callback?: AsyncCallback\<Object>): void; | 新增 |
| ohos.net.http | HttpRequest | on(type: "headerReceive", callback: AsyncCallback\<Object>): void; | 新增 |
| ohos.net.http | HttpRequest | destroy(): void; | 新增 |
| ohos.net.http | HttpRequest | request(url: string, callback: AsyncCallback\<HttpResponse>): void;<br>request(url: string, options: HttpRequestOptions, callback: AsyncCallback\<HttpResponse>): void;<br>request(url: string, options?: HttpRequestOptions): Promise\<HttpResponse>; | 新增 |
| ohos.net.http | HttpRequestOptions | connectTimeout?: number; | 新增 |
| ohos.net.http | HttpRequestOptions | readTimeout?: number; | 新增 |
| ohos.net.http | HttpRequestOptions | header?: Object; | 新增 |
| ohos.net.http | HttpRequestOptions | extraData?: string \| Object \| ArrayBuffer; | 新增 |
| ohos.net.http | HttpRequestOptions | method?: RequestMethod; | 新增 |
| ohos.net.http | http | createHttp(): HttpRequest; | 新增 |
| ohos.net.connection | NetAddress | port?: number; | 新增 |
| ohos.net.connection | NetAddress | family?: number; | 新增 |
| ohos.net.connection | NetAddress | address: string; | 新增 |
| ohos.net.connection | LinkAddress | prefixLength: number; | 新增 |
| ohos.net.connection | LinkAddress | address: NetAddress; | 新增 |
| ohos.net.connection | RouteInfo | isDefaultRoute: boolean; | 新增 |
| ohos.net.connection | RouteInfo | hasGateway: boolean; | 新增 |
| ohos.net.connection | RouteInfo | gateway: NetAddress; | 新增 |
| ohos.net.connection | RouteInfo | destination: LinkAddress; | 新增 |
| ohos.net.connection | RouteInfo | interface: string; | 新增 |
| ohos.net.connection | ConnectionProperties | mtu: number; | 新增 |
| ohos.net.connection | ConnectionProperties | routes: Array\<RouteInfo>; | 新增 |
| ohos.net.connection | ConnectionProperties | dnses: Array\<NetAddress>; | 新增 |
| ohos.net.connection | ConnectionProperties | linkAddresses: Array\<LinkAddress>; | 新增 |
| ohos.net.connection | ConnectionProperties | domains: string; | 新增 |
| ohos.net.connection | ConnectionProperties | interfaceName: string; | 新增 |
| ohos.net.connection | NetBearType | BEARER_ETHERNET = 3 | 新增 |
| ohos.net.connection | NetBearType | BEARER_WIFI = 1 | 新增 |
| ohos.net.connection | NetBearType | BEARER_CELLULAR = 0 | 新增 |
| ohos.net.connection | NetCap | NET_CAPABILITY_VALIDATED = 16 | 新增 |
| ohos.net.connection | NetCap | NET_CAPABILITY_NOT_VPN = 15 | 新增 |
| ohos.net.connection | NetCap | NET_CAPABILITY_INTERNET = 12 | 新增 |
| ohos.net.connection | NetCap | NET_CAPABILITY_NOT_METERED = 11 | 新增 |
| ohos.net.connection | NetCap | NET_CAPABILITY_MMS = 0 | 新增 |
| ohos.net.connection | NetCapabilities | bearerTypes: Array\<NetBearType>; | 新增 |
| ohos.net.connection | NetCapabilities | networkCap?: Array\<NetCap>; | 新增 |
| ohos.net.connection | NetCapabilities | linkDownBandwidthKbps?: number; | 新增 |
| ohos.net.connection | NetCapabilities | linkUpBandwidthKbps?: number; | 新增 |
| ohos.net.connection | NetHandle | getAddressByName(host: string, callback: AsyncCallback\<NetAddress>): void;<br>getAddressByName(host: string): Promise\<NetAddress>; | 新增 |
| ohos.net.connection | NetHandle | getAddressesByName(host: string, callback: AsyncCallback\<Array\<NetAddress>>): void;<br>getAddressesByName(host: string): Promise\<Array\<NetAddress>>; | 新增 |
| ohos.net.connection | NetHandle | netId: number; | 新增 |
| ohos.net.connection | NetSpecifier | bearerPrivateIdentifier?: string; | 新增 |
| ohos.net.connection | NetSpecifier | netCapabilities: NetCapabilities; | 新增 |
| ohos.net.connection | NetConnection | unregister(callback: AsyncCallback\<void>): void; | 新增 |
| ohos.net.connection | NetConnection | register(callback: AsyncCallback\<void>): void; | 新增 |
| ohos.net.connection | NetConnection | on(type: 'netUnavailable', callback: Callback\<void>): void; | 新增 |
| ohos.net.connection | NetConnection | on(type: 'netLost', callback: Callback\<NetHandle>): void; | 新增 |
| ohos.net.connection | NetConnection | on(type: 'netConnectionPropertiesChange', callback: Callback\<{ netHandle: NetHandle, connectionProperties: ConnectionProperties }>): void; | 新增 |
| ohos.net.connection | NetConnection | on(type: 'netCapabilitiesChange', callback: Callback\<{ netHandle: NetHandle, netCap: NetCapabilities }>): void; | 新增 |
| ohos.net.connection | NetConnection | on(type: 'netBlockStatusChange', callback: Callback\<{ netHandle: NetHandle, blocked: boolean }>): void; | 新增 |
| ohos.net.connection | NetConnection | on(type: 'netAvailable', callback: Callback\<NetHandle>): void; | 新增 |
| ohos.net.connection | connection | getAddressesByName(host: string, callback: AsyncCallback\<Array\<NetAddress>>): void;<br>getAddressesByName(host: string): Promise\<Array\<NetAddress>>; | 新增 |
| ohos.net.connection | connection | reportNetDisconnected(netHandle: NetHandle, callback: AsyncCallback\<void>): void;<br>reportNetDisconnected(netHandle: NetHandle): Promise\<void>; | 新增 |
| ohos.net.connection | connection | reportNetConnected(netHandle: NetHandle, callback: AsyncCallback\<void>): void;<br>reportNetConnected(netHandle: NetHandle): Promise\<void>; | 新增 |
| ohos.net.connection | connection | hasDefaultNet(callback: AsyncCallback\<boolean>): void;<br>hasDefaultNet(): Promise\<boolean>; | 新增 |
| ohos.net.connection | connection | getNetCapabilities(netHandle: NetHandle, callback: AsyncCallback\<NetCapabilities>): void;<br>getNetCapabilities(netHandle: NetHandle): Promise\<NetCapabilities>; | 新增 |
| ohos.net.connection | connection | getConnectionProperties(netHandle: NetHandle, callback: AsyncCallback\<ConnectionProperties>): void;<br>getConnectionProperties(netHandle: NetHandle): Promise\<ConnectionProperties>; | 新增 |
| ohos.net.connection | connection | getAllNets(callback: AsyncCallback\<Array\<NetHandle>>): void;<br>getAllNets(): Promise\<Array\<NetHandle>>; | 新增 |
| ohos.net.connection | connection | getDefaultNet(callback: AsyncCallback\<NetHandle>): void;<br>getDefaultNet(): Promise\<NetHandle>; | 新增 |
| ohos.net.connection | connection | createNetConnection(netSpecifier?: NetSpecifier, timeout?: number): NetConnection; | 新增 |
