# JS API Changes of the Network Management Subsystem

The table below lists the APIs changes of the network management subsystem in OpenHarmony 3.1 Release over OpenHarmony 3.0 LTS.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.net.webSocket | WebSocket | off(type: 'error', callback?: ErrorCallback): void; | Added|
| ohos.net.webSocket | WebSocket | on(type: 'error', callback: ErrorCallback): void; | Added|
| ohos.net.webSocket | WebSocket | off(type: 'close', callback?: AsyncCallback\<{ code: number, reason: string }>): void; | Added|
| ohos.net.webSocket | WebSocket | on(type: 'close', callback: AsyncCallback\<{ code: number, reason: string }>): void; | Added|
| ohos.net.webSocket | WebSocket | off(type: 'message', callback?: AsyncCallback\<string \| ArrayBuffer>): void; | Added|
| ohos.net.webSocket | WebSocket | on(type: 'message', callback: AsyncCallback\<string \| ArrayBuffer>): void; | Added|
| ohos.net.webSocket | WebSocket | off(type: 'open', callback?: AsyncCallback\<Object>): void; | Added|
| ohos.net.webSocket | WebSocket | on(type: 'open', callback: AsyncCallback\<Object>): void; | Added|
| ohos.net.webSocket | WebSocket | close(callback: AsyncCallback\<boolean>): void;<br>close(options: WebSocketCloseOptions, callback: AsyncCallback\<boolean>): void;<br>close(options?: WebSocketCloseOptions): Promise\<boolean>; | Added|
| ohos.net.webSocket | WebSocket | send(data: string \| ArrayBuffer, callback: AsyncCallback\<boolean>): void;<br>send(data: string \| ArrayBuffer): Promise\<boolean>; | Added|
| ohos.net.webSocket | WebSocket | connect(url: string, callback: AsyncCallback\<boolean>): void;<br>connect(url: string, options: WebSocketRequestOptions, callback: AsyncCallback\<boolean>): void;<br>connect(url: string, options?: WebSocketRequestOptions): Promise\<boolean>; | Added|
| ohos.net.webSocket | WebSocketCloseOptions | reason?: string; | Added|
| ohos.net.webSocket | WebSocketCloseOptions | code?: number; | Added|
| ohos.net.webSocket | WebSocketRequestOptions | header?: Object; | Added|
| ohos.net.webSocket | webSocket | createWebSocket(): WebSocket; | Added|
| ohos.net.socket | TCPSocket | off(type: 'error', callback?: ErrorCallback): void; | Added|
| ohos.net.socket | TCPSocket | on(type: 'error', callback: ErrorCallback): void; | Added|
| ohos.net.socket | TCPSocket | off(type: 'connect' \| 'close', callback?: Callback\<void>): void; | Added|
| ohos.net.socket | TCPSocket | off(type: 'connect' \| 'close', callback?: Callback\<void>): void; | Added|
| ohos.net.socket | TCPSocket | on(type: 'connect' \| 'close', callback: Callback\<void>): void; | Added|
| ohos.net.socket | TCPSocket | on(type: 'connect' \| 'close', callback: Callback\<void>): void; | Added|
| ohos.net.socket | TCPSocket | off(type: 'message', callback?: Callback\<{message: ArrayBuffer, remoteInfo: SocketRemoteInfo}>): void; | Added|
| ohos.net.socket | TCPSocket | on(type: 'message', callback: Callback\<{message: ArrayBuffer, remoteInfo: SocketRemoteInfo}>): void; | Added|
| ohos.net.socket | TCPSocket | setExtraOptions(options: TCPExtraOptions, callback: AsyncCallback\<void>): void;<br>setExtraOptions(options: TCPExtraOptions): Promise\<void>; | Added|
| ohos.net.socket | TCPSocket | getState(callback: AsyncCallback\<SocketStateBase>): void;<br>getState(): Promise\<SocketStateBase>; | Added|
| ohos.net.socket | TCPSocket | getRemoteAddress(callback: AsyncCallback\<NetAddress>): void;<br>getRemoteAddress(): Promise\<NetAddress>; | Added|
| ohos.net.socket | TCPSocket | close(callback: AsyncCallback\<void>): void;<br>close(): Promise\<void>; | Added|
| ohos.net.socket | TCPSocket | send(options: TCPSendOptions, callback: AsyncCallback\<void>): void;<br>send(options: TCPSendOptions): Promise\<void>; | Added|
| ohos.net.socket | TCPSocket | connect(options: TCPConnectOptions, callback: AsyncCallback\<void>): void;<br>connect(options: TCPConnectOptions): Promise\<void>; | Added|
| ohos.net.socket | TCPSocket | bind(address: NetAddress, callback: AsyncCallback\<void>): void;<br>bind(address: NetAddress): Promise\<void>; | Added|
| ohos.net.socket | TCPExtraOptions | socketLinger: {on: boolean, linger: number}; | Added|
| ohos.net.socket | TCPExtraOptions | TCPNoDelay?: boolean; | Added|
| ohos.net.socket | TCPExtraOptions | OOBInline?: boolean; | Added|
| ohos.net.socket | TCPExtraOptions | keepAlive?: boolean; | Added|
| ohos.net.socket | TCPSendOptions | encoding?: string; | Added|
| ohos.net.socket | TCPSendOptions | data: string \| ArrayBuffer; | Added|
| ohos.net.socket | TCPConnectOptions | timeout?: number; | Added|
| ohos.net.socket | TCPConnectOptions | address: NetAddress; | Added|
| ohos.net.socket | UDPSocket | off(type: 'error', callback?: ErrorCallback): void; | Added|
| ohos.net.socket | UDPSocket | on(type: 'error', callback: ErrorCallback): void; | Added|
| ohos.net.socket | UDPSocket | off(type: 'listening' \| 'close', callback?: Callback\<void>): void; | Added|
| ohos.net.socket | UDPSocket | off(type: 'listening' \| 'close', callback?: Callback\<void>): void; | Added|
| ohos.net.socket | UDPSocket | on(type: 'listening' \| 'close', callback: Callback\<void>): void; | Added|
| ohos.net.socket | UDPSocket | on(type: 'listening' \| 'close', callback: Callback\<void>): void; | Added|
| ohos.net.socket | UDPSocket | off(type: 'message', callback?: Callback\<{message: ArrayBuffer, remoteInfo: SocketRemoteInfo}>): void; | Added|
| ohos.net.socket | UDPSocket | on(type: 'message', callback: Callback\<{message: ArrayBuffer, remoteInfo: SocketRemoteInfo}>): void; | Added|
| ohos.net.socket | UDPSocket | setExtraOptions(options: UDPExtraOptions, callback: AsyncCallback\<void>): void;<br>setExtraOptions(options: UDPExtraOptions): Promise\<void>; | Added|
| ohos.net.socket | UDPSocket | getState(callback: AsyncCallback\<SocketStateBase>): void;<br>getState(): Promise\<SocketStateBase>; | Added|
| ohos.net.socket | UDPSocket | close(callback: AsyncCallback\<void>): void;<br>close(): Promise\<void>; | Added|
| ohos.net.socket | UDPSocket | send(options: UDPSendOptions, callback: AsyncCallback\<void>): void;<br>send(options: UDPSendOptions): Promise\<void>; | Added|
| ohos.net.socket | UDPSocket | bind(address: NetAddress, callback: AsyncCallback\<void>): void;<br>bind(address: NetAddress): Promise\<void>; | Added|
| ohos.net.socket | SocketRemoteInfo | size: number; | Added|
| ohos.net.socket | SocketRemoteInfo | port: number; | Added|
| ohos.net.socket | SocketRemoteInfo | family: 'IPv4' \| 'IPv6'; | Added|
| ohos.net.socket | SocketRemoteInfo | address: string; | Added|
| ohos.net.socket | SocketStateBase | isConnected: boolean; | Added|
| ohos.net.socket | SocketStateBase | isClose: boolean; | Added|
| ohos.net.socket | SocketStateBase | isBound: boolean; | Added|
| ohos.net.socket | UDPExtraOptions | broadcast?: boolean; | Added|
| ohos.net.socket | ExtraOptionsBase | socketTimeout?: number; | Added|
| ohos.net.socket | ExtraOptionsBase | reuseAddress?: boolean; | Added|
| ohos.net.socket | ExtraOptionsBase | sendBufferSize?: number; | Added|
| ohos.net.socket | ExtraOptionsBase | receiveBufferSize?: number; | Added|
| ohos.net.socket | UDPSendOptions | address: NetAddress; | Added|
| ohos.net.socket | UDPSendOptions | data: string \| ArrayBuffer; | Added|
| ohos.net.socket | socket | constructTCPSocketInstance(): TCPSocket; | Added|
| ohos.net.socket | socket | constructUDPSocketInstance(): UDPSocket; | Added|
| ohos.net.socket | socket | import NetAddress = connection.NetAddress; | Added|
| ohos.net.http | HttpResponse | cookies: string; | Added|
| ohos.net.http | HttpResponse | header: Object; | Added|
| ohos.net.http | HttpResponse | responseCode: ResponseCode \| number; | Added|
| ohos.net.http | HttpResponse | result: string \| Object \| ArrayBuffer; | Added|
| ohos.net.http | ResponseCode | VERSION | Added|
| ohos.net.http | ResponseCode | GATEWAY_TIMEOUT | Added|
| ohos.net.http | ResponseCode | UNAVAILABLE | Added|
| ohos.net.http | ResponseCode | BAD_GATEWAY | Added|
| ohos.net.http | ResponseCode | NOT_IMPLEMENTED | Added|
| ohos.net.http | ResponseCode | INTERNAL_ERROR = 500 | Added|
| ohos.net.http | ResponseCode | UNSUPPORTED_TYPE | Added|
| ohos.net.http | ResponseCode | REQ_TOO_LONG | Added|
| ohos.net.http | ResponseCode | ENTITY_TOO_LARGE | Added|
| ohos.net.http | ResponseCode | PRECON_FAILED | Added|
| ohos.net.http | ResponseCode | LENGTH_REQUIRED | Added|
| ohos.net.http | ResponseCode | GONE | Added|
| ohos.net.http | ResponseCode | CONFLICT | Added|
| ohos.net.http | ResponseCode | CLIENT_TIMEOUT | Added|
| ohos.net.http | ResponseCode | PROXY_AUTH | Added|
| ohos.net.http | ResponseCode | NOT_ACCEPTABLE | Added|
| ohos.net.http | ResponseCode | BAD_METHOD | Added|
| ohos.net.http | ResponseCode | NOT_FOUND | Added|
| ohos.net.http | ResponseCode | FORBIDDEN | Added|
| ohos.net.http | ResponseCode | PAYMENT_REQUIRED | Added|
| ohos.net.http | ResponseCode | UNAUTHORIZED | Added|
| ohos.net.http | ResponseCode | BAD_REQUEST = 400 | Added|
| ohos.net.http | ResponseCode | USE_PROXY | Added|
| ohos.net.http | ResponseCode | NOT_MODIFIED | Added|
| ohos.net.http | ResponseCode | SEE_OTHER | Added|
| ohos.net.http | ResponseCode | MOVED_TEMP | Added|
| ohos.net.http | ResponseCode | MOVED_PERM | Added|
| ohos.net.http | ResponseCode | MULT_CHOICE = 300 | Added|
| ohos.net.http | ResponseCode | PARTIAL | Added|
| ohos.net.http | ResponseCode | RESET | Added|
| ohos.net.http | ResponseCode | NO_CONTENT | Added|
| ohos.net.http | ResponseCode | NOT_AUTHORITATIVE | Added|
| ohos.net.http | ResponseCode | ACCEPTED | Added|
| ohos.net.http | ResponseCode | CREATED | Added|
| ohos.net.http | ResponseCode | OK = 200 | Added|
| ohos.net.http | RequestMethod | CONNECT = "CONNECT" | Added|
| ohos.net.http | RequestMethod | TRACE = "TRACE" | Added|
| ohos.net.http | RequestMethod | DELETE = "DELETE" | Added|
| ohos.net.http | RequestMethod | PUT = "PUT" | Added|
| ohos.net.http | RequestMethod | POST = "POST" | Added|
| ohos.net.http | RequestMethod | HEAD = "HEAD" | Added|
| ohos.net.http | RequestMethod | GET = "GET" | Added|
| ohos.net.http | RequestMethod | OPTIONS = "OPTIONS" | Added|
| ohos.net.http | HttpRequest | once(type: "headersReceive", callback: Callback\<Object>): void; | Added|
| ohos.net.http | HttpRequest | off(type: "headersReceive", callback?: Callback\<Object>): void; | Added|
| ohos.net.http | HttpRequest | on(type: "headersReceive", callback: Callback\<Object>): void; | Added|
| ohos.net.http | HttpRequest | off(type: "headerReceive", callback?: AsyncCallback\<Object>): void; | Added|
| ohos.net.http | HttpRequest | on(type: "headerReceive", callback: AsyncCallback\<Object>): void; | Added|
| ohos.net.http | HttpRequest | destroy(): void; | Added|
| ohos.net.http | HttpRequest | request(url: string, callback: AsyncCallback\<HttpResponse>): void;<br>request(url: string, options: HttpRequestOptions, callback: AsyncCallback\<HttpResponse>): void;<br>request(url: string, options?: HttpRequestOptions): Promise\<HttpResponse>; | Added|
| ohos.net.http | HttpRequestOptions | connectTimeout?: number; | Added|
| ohos.net.http | HttpRequestOptions | readTimeout?: number; | Added|
| ohos.net.http | HttpRequestOptions | header?: Object; | Added|
| ohos.net.http | HttpRequestOptions | extraData?: string \| Object \| ArrayBuffer; | Added|
| ohos.net.http | HttpRequestOptions | method?: RequestMethod; | Added|
| ohos.net.http | http | createHttp(): HttpRequest; | Added|
| ohos.net.connection | NetAddress | port?: number; | Added|
| ohos.net.connection | NetAddress | family?: number; | Added|
| ohos.net.connection | NetAddress | address: string; | Added|
| ohos.net.connection | LinkAddress | prefixLength: number; | Added|
| ohos.net.connection | LinkAddress | address: NetAddress; | Added|
| ohos.net.connection | RouteInfo | isDefaultRoute: boolean; | Added|
| ohos.net.connection | RouteInfo | hasGateway: boolean; | Added|
| ohos.net.connection | RouteInfo | gateway: NetAddress; | Added|
| ohos.net.connection | RouteInfo | destination: LinkAddress; | Added|
| ohos.net.connection | RouteInfo | interface: string; | Added|
| ohos.net.connection | ConnectionProperties | mtu: number; | Added|
| ohos.net.connection | ConnectionProperties | routes: Array\<RouteInfo>; | Added|
| ohos.net.connection | ConnectionProperties | dnses: Array\<NetAddress>; | Added|
| ohos.net.connection | ConnectionProperties | linkAddresses: Array\<LinkAddress>; | Added|
| ohos.net.connection | ConnectionProperties | domains: string; | Added|
| ohos.net.connection | ConnectionProperties | interfaceName: string; | Added|
| ohos.net.connection | NetBearType | BEARER_ETHERNET = 3 | Added|
| ohos.net.connection | NetBearType | BEARER_WIFI = 1 | Added|
| ohos.net.connection | NetBearType | BEARER_CELLULAR = 0 | Added|
| ohos.net.connection | NetCap | NET_CAPABILITY_VALIDATED = 16 | Added|
| ohos.net.connection | NetCap | NET_CAPABILITY_NOT_VPN = 15 | Added|
| ohos.net.connection | NetCap | NET_CAPABILITY_INTERNET = 12 | Added|
| ohos.net.connection | NetCap | NET_CAPABILITY_NOT_METERED = 11 | Added|
| ohos.net.connection | NetCap | NET_CAPABILITY_MMS = 0 | Added|
| ohos.net.connection | NetCapabilities | bearerTypes: Array\<NetBearType>; | Added|
| ohos.net.connection | NetCapabilities | networkCap?: Array\<NetCap>; | Added|
| ohos.net.connection | NetCapabilities | linkDownBandwidthKbps?: number; | Added|
| ohos.net.connection | NetCapabilities | linkUpBandwidthKbps?: number; | Added|
| ohos.net.connection | NetHandle | getAddressByName(host: string, callback: AsyncCallback\<NetAddress>): void;<br>getAddressByName(host: string): Promise\<NetAddress>; | Added|
| ohos.net.connection | NetHandle | getAddressesByName(host: string, callback: AsyncCallback\<Array\<NetAddress>>): void;<br>getAddressesByName(host: string): Promise\<Array\<NetAddress>>; | Added|
| ohos.net.connection | NetHandle | netId: number; | Added|
| ohos.net.connection | NetSpecifier | bearerPrivateIdentifier?: string; | Added|
| ohos.net.connection | NetSpecifier | netCapabilities: NetCapabilities; | Added|
| ohos.net.connection | NetConnection | unregister(callback: AsyncCallback\<void>): void; | Added|
| ohos.net.connection | NetConnection | register(callback: AsyncCallback\<void>): void; | Added|
| ohos.net.connection | NetConnection | on(type: 'netUnavailable', callback: Callback\<void>): void; | Added|
| ohos.net.connection | NetConnection | on(type: 'netLost', callback: Callback\<NetHandle>): void; | Added|
| ohos.net.connection | NetConnection | on(type: 'netConnectionPropertiesChange', callback: Callback\<{ netHandle: NetHandle, connectionProperties: ConnectionProperties }>): void; | Added|
| ohos.net.connection | NetConnection | on(type: 'netCapabilitiesChange', callback: Callback\<{ netHandle: NetHandle, netCap: NetCapabilities }>): void; | Added|
| ohos.net.connection | NetConnection | on(type: 'netBlockStatusChange', callback: Callback\<{ netHandle: NetHandle, blocked: boolean }>): void; | Added|
| ohos.net.connection | NetConnection | on(type: 'netAvailable', callback: Callback\<NetHandle>): void; | Added|
| ohos.net.connection | connection | getAddressesByName(host: string, callback: AsyncCallback\<Array\<NetAddress>>): void;<br>getAddressesByName(host: string): Promise\<Array\<NetAddress>>; | Added|
| ohos.net.connection | connection | reportNetDisconnected(netHandle: NetHandle, callback: AsyncCallback\<void>): void;<br>reportNetDisconnected(netHandle: NetHandle): Promise\<void>; | Added|
| ohos.net.connection | connection | reportNetConnected(netHandle: NetHandle, callback: AsyncCallback\<void>): void;<br>reportNetConnected(netHandle: NetHandle): Promise\<void>; | Added|
| ohos.net.connection | connection | hasDefaultNet(callback: AsyncCallback\<boolean>): void;<br>hasDefaultNet(): Promise\<boolean>; | Added|
| ohos.net.connection | connection | getNetCapabilities(netHandle: NetHandle, callback: AsyncCallback\<NetCapabilities>): void;<br>getNetCapabilities(netHandle: NetHandle): Promise\<NetCapabilities>; | Added|
| ohos.net.connection | connection | getConnectionProperties(netHandle: NetHandle, callback: AsyncCallback\<ConnectionProperties>): void;<br>getConnectionProperties(netHandle: NetHandle): Promise\<ConnectionProperties>; | Added|
| ohos.net.connection | connection | getAllNets(callback: AsyncCallback\<Array\<NetHandle>>): void;<br>getAllNets(): Promise\<Array\<NetHandle>>; | Added|
| ohos.net.connection | connection | getDefaultNet(callback: AsyncCallback\<NetHandle>): void;<br>getDefaultNet(): Promise\<NetHandle>; | Added|
| ohos.net.connection | connection | createNetConnection(netSpecifier?: NetSpecifier, timeout?: number): NetConnection; | Added|
