| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|删除|类名：wifiManager;<br>方法or属性：function getScanInfoList(): Array\<WifiScanInfo>;|NA|@ohos.wifiManager.d.ts|
|删除|类名：wifiManager;<br>方法or属性：function updateDeviceConfig(config: WifiDeviceConfig): number;|NA|@ohos.wifiManager.d.ts|
|删除|类名：wifiManager;<br>方法or属性：function disableDeviceConfig(networkId: number): void;|NA|@ohos.wifiManager.d.ts|
|删除|类名：wifiManager;<br>方法or属性：function removeAllDeviceConfigs(): void;|NA|@ohos.wifiManager.d.ts|
|删除|类名：wifiManager;<br>方法or属性：function removeDeviceConfig(networkId: number): void;|NA|@ohos.wifiManager.d.ts|
|删除|类名：wifiManager;<br>方法or属性：function getHotspotStations(): Array\<StationInfo>;|NA|@ohos.wifiManager.d.ts|
|删除|类名：wifiManager;<br>方法or属性：function createP2pGroup(config: WifiP2PConfig): void;|NA|@ohos.wifiManager.d.ts|
|删除|类名：wifiManager;<br>方法or属性：function removeP2pGroup(): void;|NA|@ohos.wifiManager.d.ts|
|删除|类名：wifiManager;<br>方法or属性：function startDiscoverP2pDevices(): void;|NA|@ohos.wifiManager.d.ts|
|删除|类名：wifiManager;<br>方法or属性：function stopDiscoverP2pDevices(): void;|NA|@ohos.wifiManager.d.ts|
|删除|类名：wifiManager;<br>方法or属性：function deletePersistentP2pGroup(netId: number): void;|NA|@ohos.wifiManager.d.ts|
|删除|类名：wifiManager;<br>方法or属性：function setP2pDeviceName(devName: string): void;|NA|@ohos.wifiManager.d.ts|
|新增|NA|类名：TCPSocketConnection;<br>方法or属性：close(): Promise\<void>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketConnection;<br>方法or属性：close(): Promise\<void>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TCPSocketServer;<br>方法or属性：getState(): Promise\<SocketStateBase>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketServer;<br>方法or属性：getState(): Promise\<SocketStateBase>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TCPSocketConnection;<br>方法or属性：send(options: TCPSendOptions): Promise\<void>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TCPSocketConnection;<br>方法or属性：getRemoteAddress(): Promise\<NetAddress>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketConnection;<br>方法or属性：getRemoteAddress(): Promise\<NetAddress>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TCPSocketServer;<br>方法or属性：setExtraOptions(options: TCPExtraOptions): Promise\<void>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketServer;<br>方法or属性：setExtraOptions(options: TCPExtraOptions): Promise\<void>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketServer;<br>方法or属性：getCertificate(): Promise\<X509CertRawData>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketConnection;<br>方法or属性：getRemoteCertificate(): Promise\<X509CertRawData>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketServer;<br>方法or属性：getProtocol(): Promise\<string>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketConnection;<br>方法or属性：getCipherSuite(): Promise\<Array\<string>>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketConnection;<br>方法or属性：getSignatureAlgorithms(): Promise\<Array\<string>>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketConnection;<br>方法or属性：send(data: string): Promise\<void>;|@ohos.net.socket.d.ts|
|新增|NA|类名：bluetoothManager;<br>方法or属性：function pairCredibleDevice(deviceId: string, transport: BluetoothTransport, callback: AsyncCallback\<void>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：bluetoothManager;<br>方法or属性：function pairCredibleDevice(deviceId: string, transport: BluetoothTransport): Promise\<void>;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：bluetoothManager;<br>方法or属性：function getRemoteProfileUuids(device: string, callback: AsyncCallback\<Array\<ProfileUuids>>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：bluetoothManager;<br>方法or属性：function getRemoteProfileUuids(device: string): Promise\<Array\<ProfileUuids>>;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：bluetoothManager;<br>方法or属性：function getLocalProfileUuids(callback: AsyncCallback\<Array\<ProfileUuids>>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：bluetoothManager;<br>方法or属性：function getLocalProfileUuids(): Promise\<Array\<ProfileUuids>>;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：BaseProfile;<br>方法or属性：setConnectionStrategy(device: string, strategy: ConnectionStrategy, callback: AsyncCallback\<void>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：BaseProfile;<br>方法or属性：setConnectionStrategy(device: string, strategy: ConnectionStrategy): Promise\<void>;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：BaseProfile;<br>方法or属性：getConnectionStrategy(device: string, callback: AsyncCallback\<ConnectionStrategy>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：BaseProfile;<br>方法or属性：getConnectionStrategy(device: string): Promise\<ConnectionStrategy>;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：AdvertiseData;<br>方法or属性：includeDeviceName?: boolean;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：BluetoothTransport;<br>方法or属性：TRANSPORT_BR_EDR = 0|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：BluetoothTransport;<br>方法or属性：TRANSPORT_LE = 1|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：ConnectionStrategy;<br>方法or属性：CONNECT_STRATEGY_UNSUPPORTED = 0|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：ConnectionStrategy;<br>方法or属性：CONNECT_STRATEGY_ALLOWED = 1|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：ConnectionStrategy;<br>方法or属性：CONNECT_STRATEGY_FORBIDDEN = 2|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：ProfileUuids;<br>方法or属性：PROFILE_UUID_HFP_AG = '0000111F-0000-1000-8000-00805F9B34FB'|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：ProfileUuids;<br>方法or属性：PROFILE_UUID_HFP_HF = '0000111E-0000-1000-8000-00805F9B34FB'|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：ProfileUuids;<br>方法or属性：PROFILE_UUID_HSP_AG = '00001112-0000-1000-8000-00805F9B34FB'|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：ProfileUuids;<br>方法or属性：PROFILE_UUID_HSP_HS = '00001108-0000-1000-8000-00805F9B34FB'|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：ProfileUuids;<br>方法or属性：PROFILE_UUID_A2DP_SRC = '0000110A-0000-1000-8000-00805F9B34FB'|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：ProfileUuids;<br>方法or属性：PROFILE_UUID_A2DP_SINK = '0000110B-0000-1000-8000-00805F9B34FB'|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：ProfileUuids;<br>方法or属性：PROFILE_UUID_AVRCP_CT = '0000110E-0000-1000-8000-00805F9B34FB'|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：ProfileUuids;<br>方法or属性：PROFILE_UUID_AVRCP_TG = '0000110C-0000-1000-8000-00805F9B34FB'|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：ProfileUuids;<br>方法or属性：PROFILE_UUID_HID = '00001124-0000-1000-8000-00805F9B34FB'|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：ProfileUuids;<br>方法or属性：PROFILE_UUID_HOGP = '00001812-0000-1000-8000-00805F9B34FB'|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：connection;<br>方法or属性：function getDefaultHttpProxy(callback: AsyncCallback\<HttpProxy>): void;|@ohos.net.connection.d.ts|
|新增|NA|类名：connection;<br>方法or属性：function getDefaultHttpProxy(): Promise\<HttpProxy>;|@ohos.net.connection.d.ts|
|新增|NA|类名：ethernet;<br>方法or属性：type HttpProxy = connection.HttpProxy;|@ohos.net.ethernet.d.ts|
|新增|NA|类名：InterfaceConfiguration;<br>方法or属性：httpProxy?: HttpProxy;|@ohos.net.ethernet.d.ts|
|新增|NA|类名：DiscoveryService;<br>方法or属性：off(type: 'discoveryStart', callback?: Callback\<{ serviceInfo: LocalServiceInfo, errorCode?: MdnsError }>): void;|@ohos.net.mdns.d.ts|
|新增|NA|类名：DiscoveryService;<br>方法or属性：off(type: 'discoveryStop', callback?: Callback\<{ serviceInfo: LocalServiceInfo, errorCode?: MdnsError }>): void;|@ohos.net.mdns.d.ts|
|新增|NA|类名：DiscoveryService;<br>方法or属性：off(type: 'serviceFound', callback?: Callback\<LocalServiceInfo>): void;|@ohos.net.mdns.d.ts|
|新增|NA|类名：DiscoveryService;<br>方法or属性：off(type: 'serviceLost', callback?: Callback\<LocalServiceInfo>): void;|@ohos.net.mdns.d.ts|
|新增|NA|类名：policy;<br>方法or属性：type NetBearType = connection.NetBearType;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function setBackgroundAllowed(isAllowed: boolean, callback: AsyncCallback\<void>): void;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function setBackgroundAllowed(isAllowed: boolean): Promise\<void>;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function isBackgroundAllowed(callback: AsyncCallback\<boolean>): void;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function isBackgroundAllowed(): Promise\<boolean>;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function getBackgroundPolicyByUid(uid: number, callback: AsyncCallback\<NetBackgroundPolicy>): void;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function getBackgroundPolicyByUid(uid: number): Promise\<NetBackgroundPolicy>;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function setPolicyByUid(uid: number, policy: NetUidPolicy, callback: AsyncCallback\<void>): void;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function setPolicyByUid(uid: number, policy: NetUidPolicy): Promise\<void>;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function getPolicyByUid(uid: number, callback: AsyncCallback\<NetUidPolicy>): void;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function getPolicyByUid(uid: number): Promise\<NetUidPolicy>;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function getUidsByPolicy(policy: NetUidPolicy, callback: AsyncCallback\<Array\<number>>): void;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function getUidsByPolicy(policy: NetUidPolicy): Promise\<Array\<number>>;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function isUidNetAllowed(uid: number, isMetered: boolean, callback: AsyncCallback\<boolean>): void;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function isUidNetAllowed(uid: number, isMetered: boolean): Promise\<boolean>;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function isUidNetAllowed(uid: number, iface: string, callback: AsyncCallback\<boolean>): void;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function isUidNetAllowed(uid: number, iface: string): Promise\<boolean>;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function setNetQuotaPolicies(quotaPolicies: Array\<NetQuotaPolicy>, callback: AsyncCallback\<void>): void;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function setNetQuotaPolicies(quotaPolicies: Array\<NetQuotaPolicy>): Promise\<void>;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function getNetQuotaPolicies(callback: AsyncCallback\<Array\<NetQuotaPolicy>>): void;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function getNetQuotaPolicies(): Promise\<Array\<NetQuotaPolicy>>;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function updateRemindPolicy(netType: NetBearType, simId: string, remindType: RemindType, callback: AsyncCallback\<void>): void;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function updateRemindPolicy(netType: NetBearType, simId: string, remindType: RemindType): Promise\<void>;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function setDeviceIdleTrustlist(uids: Array\<number>, isAllowed: boolean, callback: AsyncCallback\<void>): void;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function setDeviceIdleTrustlist(uids: Array\<number>, isAllowed: boolean): Promise\<void>;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function getDeviceIdleTrustlist(callback: AsyncCallback\<Array\<number>>): void;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function getDeviceIdleTrustlist(): Promise\<Array\<number>>;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function setPowerSaveTrustlist(uids: Array\<number>, isAllowed: boolean, callback: AsyncCallback\<void>): void;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function setPowerSaveTrustlist(uids: Array\<number>, isAllowed: boolean): Promise\<void>;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function getPowerSaveTrustlist(callback: AsyncCallback\<Array\<number>>): void;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function getPowerSaveTrustlist(): Promise\<Array\<number>>;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function resetPolicies(simId: string, callback: AsyncCallback\<void>): void;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function resetPolicies(simId: string): Promise\<void>;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function on(type: 'netUidPolicyChange', callback: Callback\<{ uid: number, policy: NetUidPolicy }>): void;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function on(type: 'netUidRuleChange', callback: Callback\<{ uid: number, rule: NetUidRule }>): void;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function on(type: 'netMeteredIfacesChange', callback: Callback\<Array\<string>>): void;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function on(type: 'netQuotaPolicyChange', callback: Callback\<Array\<NetQuotaPolicy>>): void;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function on(type: 'netBackgroundPolicyChange', callback: Callback\<boolean>): void;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function off(type: 'netUidPolicyChange', callback?: Callback\<{ uid: number, policy: NetUidPolicy }>): void;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function off(type: 'netUidRuleChange', callback?: Callback\<{ uid: number, rule: NetUidRule }>): void;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function off(type: 'netMeteredIfacesChange', callback?: Callback\<Array\<string>>): void;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function off(type: 'netQuotaPolicyChange', callback?: Callback\<Array\<NetQuotaPolicy>>): void;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function off(type: 'netBackgroundPolicyChange', callback?: Callback\<boolean>): void;|@ohos.net.policy.d.ts|
|新增|NA|类名：NetBackgroundPolicy;<br>方法or属性：NET_BACKGROUND_POLICY_NONE = 0|@ohos.net.policy.d.ts|
|新增|NA|类名：NetBackgroundPolicy;<br>方法or属性：NET_BACKGROUND_POLICY_ENABLE = 1|@ohos.net.policy.d.ts|
|新增|NA|类名：NetBackgroundPolicy;<br>方法or属性：NET_BACKGROUND_POLICY_DISABLE = 2|@ohos.net.policy.d.ts|
|新增|NA|类名：NetBackgroundPolicy;<br>方法or属性：NET_BACKGROUND_POLICY_TRUSTLIST = 3|@ohos.net.policy.d.ts|
|新增|NA|类名：NetQuotaPolicy;<br>方法or属性：networkMatchRule: NetworkMatchRule;|@ohos.net.policy.d.ts|
|新增|NA|类名：NetQuotaPolicy;<br>方法or属性：quotaPolicy: QuotaPolicy;|@ohos.net.policy.d.ts|
|新增|NA|类名：QuotaPolicy;<br>方法or属性：periodDuration: string;|@ohos.net.policy.d.ts|
|新增|NA|类名：QuotaPolicy;<br>方法or属性：warningBytes: number;|@ohos.net.policy.d.ts|
|新增|NA|类名：QuotaPolicy;<br>方法or属性：limitBytes: number;|@ohos.net.policy.d.ts|
|新增|NA|类名：QuotaPolicy;<br>方法or属性：metered: boolean;|@ohos.net.policy.d.ts|
|新增|NA|类名：QuotaPolicy;<br>方法or属性：limitAction: LimitAction;|@ohos.net.policy.d.ts|
|新增|NA|类名：QuotaPolicy;<br>方法or属性：lastWarningRemind?: number;|@ohos.net.policy.d.ts|
|新增|NA|类名：QuotaPolicy;<br>方法or属性：lastLimitRemind?: number;|@ohos.net.policy.d.ts|
|新增|NA|类名：NetworkMatchRule;<br>方法or属性：netType: NetBearType;|@ohos.net.policy.d.ts|
|新增|NA|类名：NetworkMatchRule;<br>方法or属性：identity: string;|@ohos.net.policy.d.ts|
|新增|NA|类名：NetworkMatchRule;<br>方法or属性：simId: string;|@ohos.net.policy.d.ts|
|新增|NA|类名：LimitAction;<br>方法or属性：LIMIT_ACTION_NONE = -1|@ohos.net.policy.d.ts|
|新增|NA|类名：LimitAction;<br>方法or属性：LIMIT_ACTION_ACCESS_DISABLED = 0|@ohos.net.policy.d.ts|
|新增|NA|类名：LimitAction;<br>方法or属性：LIMIT_ACTION_ALERT_ONLY = 1|@ohos.net.policy.d.ts|
|新增|NA|类名：NetUidRule;<br>方法or属性：NET_RULE_NONE = 0|@ohos.net.policy.d.ts|
|新增|NA|类名：NetUidRule;<br>方法or属性：NET_RULE_ALLOW_METERED_FOREGROUND = 1 \<\< 0|@ohos.net.policy.d.ts|
|新增|NA|类名：NetUidRule;<br>方法or属性：NET_RULE_ALLOW_METERED = 1 \<\< 1|@ohos.net.policy.d.ts|
|新增|NA|类名：NetUidRule;<br>方法or属性：NET_RULE_REJECT_METERED = 1 \<\< 2|@ohos.net.policy.d.ts|
|新增|NA|类名：NetUidRule;<br>方法or属性：NET_RULE_ALLOW_ALL = 1 \<\< 5|@ohos.net.policy.d.ts|
|新增|NA|类名：NetUidRule;<br>方法or属性：NET_RULE_REJECT_ALL = 1 \<\< 6|@ohos.net.policy.d.ts|
|新增|NA|类名：RemindType;<br>方法or属性：REMIND_TYPE_WARNING = 1|@ohos.net.policy.d.ts|
|新增|NA|类名：RemindType;<br>方法or属性：REMIND_TYPE_LIMIT = 2|@ohos.net.policy.d.ts|
|新增|NA|类名：NetUidPolicy;<br>方法or属性：NET_POLICY_NONE = 0|@ohos.net.policy.d.ts|
|新增|NA|类名：NetUidPolicy;<br>方法or属性：NET_POLICY_ALLOW_METERED_BACKGROUND = 1 \<\< 0|@ohos.net.policy.d.ts|
|新增|NA|类名：NetUidPolicy;<br>方法or属性：NET_POLICY_REJECT_METERED_BACKGROUND = 1 \<\< 1|@ohos.net.policy.d.ts|
|新增|NA|类名：socket;<br>方法or属性：function constructTCPSocketServerInstance(): TCPSocketServer;|@ohos.net.socket.d.ts|
|新增|NA|类名：socket;<br>方法or属性：function constructTLSSocketServerInstance(): TLSSocketServer;|@ohos.net.socket.d.ts|
|新增|NA|类名：TCPSocket;<br>方法or属性：getSocketFd(callback: AsyncCallback\<number>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TCPSocket;<br>方法or属性：getSocketFd(): Promise\<number>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TCPSocketConnection;<br>方法or属性：clientId: number;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketConnection;<br>方法or属性：clientId: number;|@ohos.net.socket.d.ts|
|新增|NA|类名：TCPSocketConnection;<br>方法or属性：send(options: TCPSendOptions, callback: AsyncCallback\<void>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TCPSocketConnection;<br>方法or属性：close(callback: AsyncCallback\<void>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketConnection;<br>方法or属性：close(callback: AsyncCallback\<void>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TCPSocketConnection;<br>方法or属性：getRemoteAddress(callback: AsyncCallback\<NetAddress>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketConnection;<br>方法or属性：getRemoteAddress(callback: AsyncCallback\<NetAddress>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TCPSocketConnection;<br>方法or属性：on(type: 'message', callback: Callback\<{ message: ArrayBuffer, remoteInfo: SocketRemoteInfo }>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketConnection;<br>方法or属性：on(type: 'message', callback: Callback\<{ message: ArrayBuffer, remoteInfo: SocketRemoteInfo }>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TCPSocketConnection;<br>方法or属性：on(type: 'close', callback: Callback\<void>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketConnection;<br>方法or属性：on(type: 'close', callback: Callback\<void>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TCPSocketConnection;<br>方法or属性：on(type: 'error', callback: ErrorCallback): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TCPSocketServer;<br>方法or属性：on(type: 'error', callback: ErrorCallback): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketConnection;<br>方法or属性：on(type: 'error', callback: ErrorCallback): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketServer;<br>方法or属性：on(type: 'error', callback: ErrorCallback): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TCPSocketConnection;<br>方法or属性：off(type: 'message', callback?: Callback\<{ message: ArrayBuffer, remoteInfo: SocketRemoteInfo }>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketConnection;<br>方法or属性：off(type: 'message', callback?: Callback\<{ message: ArrayBuffer, remoteInfo: SocketRemoteInfo }>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TCPSocketConnection;<br>方法or属性：off(type: 'close', callback?: Callback\<void>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketConnection;<br>方法or属性：off(type: 'close', callback?: Callback\<void>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TCPSocketConnection;<br>方法or属性：off(type: 'error', callback?: ErrorCallback): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TCPSocketServer;<br>方法or属性：off(type: 'error', callback?: ErrorCallback): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketConnection;<br>方法or属性：off(type: 'error', callback?: ErrorCallback): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketServer;<br>方法or属性：off(type: 'error', callback?: ErrorCallback): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TCPSocketServer;<br>方法or属性：listen(address: NetAddress, callback: AsyncCallback\<void>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TCPSocketServer;<br>方法or属性：listen(address: NetAddress): Promise\<void>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TCPSocketServer;<br>方法or属性：getState(callback: AsyncCallback\<SocketStateBase>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketServer;<br>方法or属性：getState(callback: AsyncCallback\<SocketStateBase>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TCPSocketServer;<br>方法or属性：setExtraOptions(options: TCPExtraOptions, callback: AsyncCallback\<void>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketServer;<br>方法or属性：setExtraOptions(options: TCPExtraOptions, callback: AsyncCallback\<void>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TCPSocketServer;<br>方法or属性：on(type: 'connect', callback: Callback\<TCPSocketConnection>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TCPSocketServer;<br>方法or属性：off(type: 'connect', callback?: Callback\<TCPSocketConnection>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketConnection;<br>方法or属性：send(data: string, callback: AsyncCallback\<void>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketConnection;<br>方法or属性：getRemoteCertificate(callback: AsyncCallback\<X509CertRawData>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketConnection;<br>方法or属性：getCipherSuite(callback: AsyncCallback\<Array\<string>>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketConnection;<br>方法or属性：getSignatureAlgorithms(callback: AsyncCallback\<Array\<string>>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketServer;<br>方法or属性：listen(options: TLSConnectOptions, callback: AsyncCallback\<void>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketServer;<br>方法or属性：listen(options: TLSConnectOptions): Promise\<void>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketServer;<br>方法or属性：getCertificate(callback: AsyncCallback\<X509CertRawData>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketServer;<br>方法or属性：getProtocol(callback: AsyncCallback\<string>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketServer;<br>方法or属性：on(type: 'connect', callback: Callback\<TLSSocketConnection>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketServer;<br>方法or属性：off(type: 'connect', callback?: Callback\<TLSSocketConnection>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：statistics;<br>方法or属性：function getIfaceRxBytes(nic: string, callback: AsyncCallback\<number>): void;|@ohos.net.statistics.d.ts|
|新增|NA|类名：statistics;<br>方法or属性：function getIfaceRxBytes(nic: string): Promise\<number>;|@ohos.net.statistics.d.ts|
|新增|NA|类名：statistics;<br>方法or属性：function getIfaceTxBytes(nic: string, callback: AsyncCallback\<number>): void;|@ohos.net.statistics.d.ts|
|新增|NA|类名：statistics;<br>方法or属性：function getIfaceTxBytes(nic: string): Promise\<number>;|@ohos.net.statistics.d.ts|
|新增|NA|类名：statistics;<br>方法or属性：function getCellularRxBytes(callback: AsyncCallback\<number>): void;|@ohos.net.statistics.d.ts|
|新增|NA|类名：statistics;<br>方法or属性：function getCellularRxBytes(): Promise\<number>;|@ohos.net.statistics.d.ts|
|新增|NA|类名：statistics;<br>方法or属性：function getCellularTxBytes(callback: AsyncCallback\<number>): void;|@ohos.net.statistics.d.ts|
|新增|NA|类名：statistics;<br>方法or属性：function getCellularTxBytes(): Promise\<number>;|@ohos.net.statistics.d.ts|
|新增|NA|类名：statistics;<br>方法or属性：function getAllRxBytes(callback: AsyncCallback\<number>): void;|@ohos.net.statistics.d.ts|
|新增|NA|类名：statistics;<br>方法or属性：function getAllRxBytes(): Promise\<number>;|@ohos.net.statistics.d.ts|
|新增|NA|类名：statistics;<br>方法or属性：function getAllTxBytes(callback: AsyncCallback\<number>): void;|@ohos.net.statistics.d.ts|
|新增|NA|类名：statistics;<br>方法or属性：function getAllTxBytes(): Promise\<number>;|@ohos.net.statistics.d.ts|
|新增|NA|类名：statistics;<br>方法or属性：function getUidRxBytes(uid: number, callback: AsyncCallback\<number>): void;|@ohos.net.statistics.d.ts|
|新增|NA|类名：statistics;<br>方法or属性：function getUidRxBytes(uid: number): Promise\<number>;|@ohos.net.statistics.d.ts|
|新增|NA|类名：statistics;<br>方法or属性：function getUidTxBytes(uid: number, callback: AsyncCallback\<number>): void;|@ohos.net.statistics.d.ts|
|新增|NA|类名：statistics;<br>方法or属性：function getUidTxBytes(uid: number): Promise\<number>;|@ohos.net.statistics.d.ts|
|新增|NA|类名：statistics;<br>方法or属性：function on(type: 'netStatsChange', callback: Callback\<{ iface: string, uid?: number }>): void;|@ohos.net.statistics.d.ts|
|新增|NA|类名：statistics;<br>方法or属性：function off(type: 'netStatsChange', callback?: Callback\<{ iface: string, uid?: number }>): void;|@ohos.net.statistics.d.ts|
|新增|NA|类名：statistics;<br>方法or属性：function getTrafficStatsByIface(ifaceInfo: IfaceInfo, callback: AsyncCallback\<NetStatsInfo>): void;|@ohos.net.statistics.d.ts|
|新增|NA|类名：statistics;<br>方法or属性：function getTrafficStatsByIface(ifaceInfo: IfaceInfo): Promise\<NetStatsInfo>;|@ohos.net.statistics.d.ts|
|新增|NA|类名：statistics;<br>方法or属性：function getTrafficStatsByUid(uidInfo: UidInfo, callback: AsyncCallback\<NetStatsInfo>): void;|@ohos.net.statistics.d.ts|
|新增|NA|类名：statistics;<br>方法or属性：function getTrafficStatsByUid(uidInfo: UidInfo): Promise\<NetStatsInfo>;|@ohos.net.statistics.d.ts|
|新增|NA|类名：IfaceInfo;<br>方法or属性：iface: string;|@ohos.net.statistics.d.ts|
|新增|NA|类名：IfaceInfo;<br>方法or属性：startTime: number;|@ohos.net.statistics.d.ts|
|新增|NA|类名：IfaceInfo;<br>方法or属性：endTime: number;|@ohos.net.statistics.d.ts|
|新增|NA|类名：UidInfo;<br>方法or属性：ifaceInfo: IfaceInfo;|@ohos.net.statistics.d.ts|
|新增|NA|类名：UidInfo;<br>方法or属性：uid: number;|@ohos.net.statistics.d.ts|
|新增|NA|类名：NetStatsInfo;<br>方法or属性：rxBytes: number;|@ohos.net.statistics.d.ts|
|新增|NA|类名：NetStatsInfo;<br>方法or属性：txBytes: number;|@ohos.net.statistics.d.ts|
|新增|NA|类名：NetStatsInfo;<br>方法or属性：rxPackets: number;|@ohos.net.statistics.d.ts|
|新增|NA|类名：NetStatsInfo;<br>方法or属性：txPackets: number;|@ohos.net.statistics.d.ts|
|新增|NA|类名：vpn;<br>方法or属性：export type LinkAddress = connection.LinkAddress;|@ohos.net.vpn.d.ts|
|新增|NA|类名：vpn;<br>方法or属性：export type RouteInfo = connection.RouteInfo;|@ohos.net.vpn.d.ts|
|新增|NA|类名：vpn;<br>方法or属性：function createVpnConnection(context: AbilityContext): VpnConnection;|@ohos.net.vpn.d.ts|
|新增|NA|类名：VpnConnection;<br>方法or属性：setUp(config: VpnConfig, callback: AsyncCallback\<number>): void;|@ohos.net.vpn.d.ts|
|新增|NA|类名：VpnConnection;<br>方法or属性：setUp(config: VpnConfig): Promise\<number>;|@ohos.net.vpn.d.ts|
|新增|NA|类名：VpnConnection;<br>方法or属性：protect(socketFd: number, callback: AsyncCallback\<void>): void;|@ohos.net.vpn.d.ts|
|新增|NA|类名：VpnConnection;<br>方法or属性：protect(socketFd: number): Promise\<void>;|@ohos.net.vpn.d.ts|
|新增|NA|类名：VpnConnection;<br>方法or属性：destroy(callback: AsyncCallback\<void>): void;|@ohos.net.vpn.d.ts|
|新增|NA|类名：VpnConnection;<br>方法or属性：destroy(): Promise\<void>;|@ohos.net.vpn.d.ts|
|新增|NA|类名：VpnConfig;<br>方法or属性：addresses: Array\<LinkAddress>;|@ohos.net.vpn.d.ts|
|新增|NA|类名：VpnConfig;<br>方法or属性：routes?: Array\<RouteInfo>;|@ohos.net.vpn.d.ts|
|新增|NA|类名：VpnConfig;<br>方法or属性：dnsAddresses?: Array\<string>;|@ohos.net.vpn.d.ts|
|新增|NA|类名：VpnConfig;<br>方法or属性：searchDomains?: Array\<string>;|@ohos.net.vpn.d.ts|
|新增|NA|类名：VpnConfig;<br>方法or属性：mtu?: number;|@ohos.net.vpn.d.ts|
|新增|NA|类名：VpnConfig;<br>方法or属性：isIPv4Accepted?: boolean;|@ohos.net.vpn.d.ts|
|新增|NA|类名：VpnConfig;<br>方法or属性：isIPv6Accepted?: boolean;|@ohos.net.vpn.d.ts|
|新增|NA|类名：VpnConfig;<br>方法or属性：isLegacy?: boolean;|@ohos.net.vpn.d.ts|
|新增|NA|类名：VpnConfig;<br>方法or属性：isBlocking?: boolean;|@ohos.net.vpn.d.ts|
|新增|NA|类名：VpnConfig;<br>方法or属性：trustedApplications?: Array\<string>;|@ohos.net.vpn.d.ts|
|新增|NA|类名：VpnConfig;<br>方法or属性：blockedApplications?: Array\<string>;|@ohos.net.vpn.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function getScanResults(): Promise\<Array\<WifiScanInfo>>;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function getScanResults(callback: AsyncCallback\<Array\<WifiScanInfo>>): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function getScanResultsSync(): Array\<WifiScanInfo>;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function setScanAlwaysAllowed(isScanAlwaysAllowed: boolean): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function getScanAlwaysAllowed(): boolean;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function updateNetwork(config: WifiDeviceConfig): number;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function disableNetwork(netId: number): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function removeAllNetwork(): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function removeDevice(id: number): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function getDisconnectedReason(): DisconnectedReason;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function getStations(): Array\<StationInfo>;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function createGroup(config: WifiP2PConfig): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function removeGroup(): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function startDiscoverDevices(): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function stopDiscoverDevices(): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function deletePersistentGroup(netId: number): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function setDeviceName(devName: string): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：DisconnectedReason;<br>方法or属性：DISC_REASON_DEFAULT = 0|@ohos.wifiManager.d.ts|
|新增|NA|类名：DisconnectedReason;<br>方法or属性：DISC_REASON_WRONG_PWD = 1|@ohos.wifiManager.d.ts|
|新增|NA|类名：DisconnectedReason;<br>方法or属性：DISC_REASON_CONNECTION_FULL = 2|@ohos.wifiManager.d.ts|
|新增|NA|类名：ProxyMethod;<br>方法or属性：METHOD_NONE = 0|@ohos.wifiManager.d.ts|
|新增|NA|类名：ProxyMethod;<br>方法or属性：METHOD_AUTO = 1|@ohos.wifiManager.d.ts|
|新增|NA|类名：ProxyMethod;<br>方法or属性：METHOD_MANUAL = 2|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiProxyConfig;<br>方法or属性：proxyMethod?: ProxyMethod;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiProxyConfig;<br>方法or属性：pacWebAddress?: string;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiProxyConfig;<br>方法or属性：serverHostName?: string;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiProxyConfig;<br>方法or属性：serverPort?: number;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiProxyConfig;<br>方法or属性：exclusionObjects?: string;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiDeviceConfig;<br>方法or属性：proxyConfig?: WifiProxyConfig;|@ohos.wifiManager.d.ts|
|新增|NA|类名：HotspotConfig;<br>方法or属性：ipAddress?: string;|@ohos.wifiManager.d.ts|
|新增(错误码)|类名：GattClientDevice;<br>方法or属性：getDeviceName(): Promise\<string>;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：getDeviceName(): Promise\<string>;<br>新版本信息：201,401,801,2900001,2900099|@ohos.bluetoothManager.d.ts|
|新增(错误码)|类名：GattClientDevice;<br>方法or属性：getServices(): Promise\<Array\<GattService>>;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：getServices(): Promise\<Array\<GattService>>;<br>新版本信息：201,401,801,2900001,2900099|@ohos.bluetoothManager.d.ts|
|新增(错误码)|类名：GattClientDevice;<br>方法or属性：readCharacteristicValue(characteristic: BLECharacteristic): Promise\<BLECharacteristic>;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：readCharacteristicValue(characteristic: BLECharacteristic): Promise\<BLECharacteristic>;<br>新版本信息：201,401,801,2900001,2901000,2900099|@ohos.bluetoothManager.d.ts|
|新增(错误码)|类名：GattClientDevice;<br>方法or属性：readDescriptorValue(descriptor: BLEDescriptor): Promise\<BLEDescriptor>;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：readDescriptorValue(descriptor: BLEDescriptor): Promise\<BLEDescriptor>;<br>新版本信息：201,401,801,2900001,2901000,2900099|@ohos.bluetoothManager.d.ts|
|新增(错误码)|类名：GattClientDevice;<br>方法or属性：getRssiValue(): Promise\<number>;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：getRssiValue(): Promise\<number>;<br>新版本信息：201,401,801,2900099|@ohos.bluetoothManager.d.ts|
|新增(错误码)|类名：connection;<br>方法or属性：function getDefaultNet(): Promise\<NetHandle>;<br>旧版本信息：|类名：connection;<br>方法or属性：function getDefaultNet(): Promise\<NetHandle>;<br>新版本信息：201,401,2100002,2100003|@ohos.net.connection.d.ts|
|新增(错误码)|类名：connection;<br>方法or属性：function getAllNets(): Promise\<Array\<NetHandle>>;<br>旧版本信息：|类名：connection;<br>方法or属性：function getAllNets(): Promise\<Array\<NetHandle>>;<br>新版本信息：201,401,2100002,2100003|@ohos.net.connection.d.ts|
|新增(错误码)|类名：connection;<br>方法or属性：function getConnectionProperties(netHandle: NetHandle): Promise\<ConnectionProperties>;<br>旧版本信息：|类名：connection;<br>方法or属性：function getConnectionProperties(netHandle: NetHandle): Promise\<ConnectionProperties>;<br>新版本信息：201,401,2100001,2100002,2100003|@ohos.net.connection.d.ts|
|新增(错误码)|类名：connection;<br>方法or属性：function getNetCapabilities(netHandle: NetHandle): Promise\<NetCapabilities>;<br>旧版本信息：|类名：connection;<br>方法or属性：function getNetCapabilities(netHandle: NetHandle): Promise\<NetCapabilities>;<br>新版本信息：201,401,2100001,2100002,2100003|@ohos.net.connection.d.ts|
|新增(错误码)|类名：connection;<br>方法or属性：function isDefaultNetMetered(): Promise\<boolean>;<br>旧版本信息：|类名：connection;<br>方法or属性：function isDefaultNetMetered(): Promise\<boolean>;<br>新版本信息：201,401,2100002,2100003|@ohos.net.connection.d.ts|
|新增(错误码)|类名：connection;<br>方法or属性：function hasDefaultNet(): Promise\<boolean>;<br>旧版本信息：|类名：connection;<br>方法or属性：function hasDefaultNet(): Promise\<boolean>;<br>新版本信息：201,401,2100002,2100003|@ohos.net.connection.d.ts|
|新增(错误码)|类名：connection;<br>方法or属性：function enableAirplaneMode(): Promise\<void>;<br>旧版本信息：|类名：connection;<br>方法or属性：function enableAirplaneMode(): Promise\<void>;<br>新版本信息：201,202,401,2100002,2100003|@ohos.net.connection.d.ts|
|新增(错误码)|类名：connection;<br>方法or属性：function disableAirplaneMode(): Promise\<void>;<br>旧版本信息：|类名：connection;<br>方法or属性：function disableAirplaneMode(): Promise\<void>;<br>新版本信息：201,202,401,2100002,2100003|@ohos.net.connection.d.ts|
|新增(错误码)|类名：connection;<br>方法or属性：function reportNetConnected(netHandle: NetHandle): Promise\<void>;<br>旧版本信息：|类名：connection;<br>方法or属性：function reportNetConnected(netHandle: NetHandle): Promise\<void>;<br>新版本信息：201,401,2100001,2100002,2100003|@ohos.net.connection.d.ts|
|新增(错误码)|类名：connection;<br>方法or属性：function reportNetDisconnected(netHandle: NetHandle): Promise\<void>;<br>旧版本信息：|类名：connection;<br>方法or属性：function reportNetDisconnected(netHandle: NetHandle): Promise\<void>;<br>新版本信息：201,401,2100001,2100002,2100003|@ohos.net.connection.d.ts|
|新增(错误码)|类名：connection;<br>方法or属性：function getAddressesByName(host: string): Promise\<Array\<NetAddress>>;<br>旧版本信息：|类名：connection;<br>方法or属性：function getAddressesByName(host: string): Promise\<Array\<NetAddress>>;<br>新版本信息：201,401,2100001,2100002,2100003|@ohos.net.connection.d.ts|
|新增(错误码)|类名：NetHandle;<br>方法or属性：bindSocket(socketParam: TCPSocket \| UDPSocket): Promise\<void>;<br>旧版本信息：|类名：NetHandle;<br>方法or属性：bindSocket(socketParam: TCPSocket \| UDPSocket): Promise\<void>;<br>新版本信息：401,2100001,2100002,2100003|@ohos.net.connection.d.ts|
|新增(错误码)|类名：NetHandle;<br>方法or属性：getAddressesByName(host: string): Promise\<Array\<NetAddress>>;<br>旧版本信息：|类名：NetHandle;<br>方法or属性：getAddressesByName(host: string): Promise\<Array\<NetAddress>>;<br>新版本信息：201,401,2100001,2100002,2100003|@ohos.net.connection.d.ts|
|新增(错误码)|类名：NetHandle;<br>方法or属性：getAddressByName(host: string): Promise\<NetAddress>;<br>旧版本信息：|类名：NetHandle;<br>方法or属性：getAddressByName(host: string): Promise\<NetAddress>;<br>新版本信息：201,401,2100001,2100002,2100003|@ohos.net.connection.d.ts|
|新增(错误码)|类名：ethernet;<br>方法or属性：function getIfaceConfig(iface: string): Promise\<InterfaceConfiguration>;<br>旧版本信息：|类名：ethernet;<br>方法or属性：function getIfaceConfig(iface: string): Promise\<InterfaceConfiguration>;<br>新版本信息：201,202,401,2200001,2200002,2200003,2201005|@ohos.net.ethernet.d.ts|
|新增(错误码)|类名：ethernet;<br>方法or属性：function setIfaceConfig(iface: string, ic: InterfaceConfiguration): Promise\<void>;<br>旧版本信息：|类名：ethernet;<br>方法or属性：function setIfaceConfig(iface: string, ic: InterfaceConfiguration): Promise\<void>;<br>新版本信息：201,202,401,2200001,2200002,2200003,2201004,2201005,2201006,2201007|@ohos.net.ethernet.d.ts|
|新增(错误码)|类名：ethernet;<br>方法or属性：function isIfaceActive(iface: string): Promise\<number>;<br>旧版本信息：|类名：ethernet;<br>方法or属性：function isIfaceActive(iface: string): Promise\<number>;<br>新版本信息：201,202,401,2200001,2200002,2200003,2201005|@ohos.net.ethernet.d.ts|
|新增(错误码)|类名：ethernet;<br>方法or属性：function getAllActiveIfaces(): Promise\<Array\<string>>;<br>旧版本信息：|类名：ethernet;<br>方法or属性：function getAllActiveIfaces(): Promise\<Array\<string>>;<br>新版本信息：201,202,2200002,2200003|@ohos.net.ethernet.d.ts|
|新增(错误码)|类名：HttpRequest;<br>方法or属性：request(url: string, options: HttpRequestOptions, callback: AsyncCallback\<HttpResponse>): void;<br>旧版本信息：|类名：HttpRequest;<br>方法or属性：request(url: string, options: HttpRequestOptions, callback: AsyncCallback\<HttpResponse>): void;<br>新版本信息：401,201,2300001,2300003,2300005,2300006,2300007,2300008,2300009,2300016,2300018,2300023,2300025,2300026,2300027,2300028,2300047,2300052,2300055,2300056,2300058,2300059,2300060,2300061,2300063,2300070,2300073,2300077,2300078,2300094,2300999|@ohos.net.http.d.ts|
|新增(错误码)|类名：HttpRequest;<br>方法or属性：request(url: string, options?: HttpRequestOptions): Promise\<HttpResponse>;<br>旧版本信息：|类名：HttpRequest;<br>方法or属性：request(url: string, options?: HttpRequestOptions): Promise\<HttpResponse>;<br>新版本信息：401,201,2300001,2300003,2300005,2300006,2300007,2300008,2300009,2300016,2300018,2300023,2300025,2300026,2300027,2300028,2300047,2300052,2300055,2300056,2300058,2300059,2300060,2300061,2300063,2300070,2300073,2300077,2300078,2300094,2300999|@ohos.net.http.d.ts|
|新增(错误码)|类名：sharing;<br>方法or属性：function isSharingSupported(): Promise\<boolean>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function isSharingSupported(): Promise\<boolean>;<br>新版本信息：201,202,2200002,2200003,2202011|@ohos.net.sharing.d.ts|
|新增(错误码)|类名：sharing;<br>方法or属性：function isSharing(): Promise\<boolean>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function isSharing(): Promise\<boolean>;<br>新版本信息：201,202,2200002,2200003,2202011|@ohos.net.sharing.d.ts|
|新增(错误码)|类名：sharing;<br>方法or属性：function startSharing(type: SharingIfaceType): Promise\<void>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function startSharing(type: SharingIfaceType): Promise\<void>;<br>新版本信息：201,202,401,2200001,2200002,2200003,2202004,2202005,2202006,2202009,2202011|@ohos.net.sharing.d.ts|
|新增(错误码)|类名：sharing;<br>方法or属性：function stopSharing(type: SharingIfaceType): Promise\<void>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function stopSharing(type: SharingIfaceType): Promise\<void>;<br>新版本信息：201,202,401,2200001,2200002,2200003,2202004,2202005,2202006,2202011|@ohos.net.sharing.d.ts|
|新增(错误码)|类名：sharing;<br>方法or属性：function getStatsRxBytes(): Promise\<number>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function getStatsRxBytes(): Promise\<number>;<br>新版本信息：201,202,401,2200002,2200003|@ohos.net.sharing.d.ts|
|新增(错误码)|类名：sharing;<br>方法or属性：function getStatsTxBytes(): Promise\<number>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function getStatsTxBytes(): Promise\<number>;<br>新版本信息：201,202,401,2200002,2200003|@ohos.net.sharing.d.ts|
|新增(错误码)|类名：sharing;<br>方法or属性：function getStatsTotalBytes(): Promise\<number>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function getStatsTotalBytes(): Promise\<number>;<br>新版本信息：201,202,401,2200002,2200003|@ohos.net.sharing.d.ts|
|新增(错误码)|类名：sharing;<br>方法or属性：function getSharingIfaces(state: SharingIfaceState): Promise\<Array\<string>>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function getSharingIfaces(state: SharingIfaceState): Promise\<Array\<string>>;<br>新版本信息：201,202,401,2200001,2200002,2200003|@ohos.net.sharing.d.ts|
|新增(错误码)|类名：sharing;<br>方法or属性：function getSharingState(type: SharingIfaceType): Promise\<SharingIfaceState>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function getSharingState(type: SharingIfaceType): Promise\<SharingIfaceState>;<br>新版本信息：201,202,401,2200001,2200002,2200003|@ohos.net.sharing.d.ts|
|新增(错误码)|类名：sharing;<br>方法or属性：function getSharableRegexes(type: SharingIfaceType): Promise\<Array\<string>>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function getSharableRegexes(type: SharingIfaceType): Promise\<Array\<string>>;<br>新版本信息：201,202,401,2200001,2200002,2200003|@ohos.net.sharing.d.ts|
|新增(错误码)|类名：UDPSocket;<br>方法or属性：bind(address: NetAddress): Promise\<void>;<br>旧版本信息：|类名：UDPSocket;<br>方法or属性：bind(address: NetAddress): Promise\<void>;<br>新版本信息：401,201|@ohos.net.socket.d.ts|
|新增(错误码)|类名：TCPSocket;<br>方法or属性：bind(address: NetAddress): Promise\<void>;<br>旧版本信息：|类名：TCPSocket;<br>方法or属性：bind(address: NetAddress): Promise\<void>;<br>新版本信息：401,201|@ohos.net.socket.d.ts|
|新增(错误码)|类名：TLSSocket;<br>方法or属性：bind(address: NetAddress): Promise\<void>;<br>旧版本信息：|类名：TLSSocket;<br>方法or属性：bind(address: NetAddress): Promise\<void>;<br>新版本信息：401,201,2303198,2300002|@ohos.net.socket.d.ts|
|新增(错误码)|类名：UDPSocket;<br>方法or属性：send(options: UDPSendOptions): Promise\<void>;<br>旧版本信息：|类名：UDPSocket;<br>方法or属性：send(options: UDPSendOptions): Promise\<void>;<br>新版本信息：401,201|@ohos.net.socket.d.ts|
|新增(错误码)|类名：UDPSocket;<br>方法or属性：close(): Promise\<void>;<br>旧版本信息：|类名：UDPSocket;<br>方法or属性：close(): Promise\<void>;<br>新版本信息：201|@ohos.net.socket.d.ts|
|新增(错误码)|类名：TCPSocket;<br>方法or属性：close(): Promise\<void>;<br>旧版本信息：|类名：TCPSocket;<br>方法or属性：close(): Promise\<void>;<br>新版本信息：201|@ohos.net.socket.d.ts|
|新增(错误码)|类名：TLSSocket;<br>方法or属性：close(): Promise\<void>;<br>旧版本信息：|类名：TLSSocket;<br>方法or属性：close(): Promise\<void>;<br>新版本信息：401,2303501,2303505,2303506,2300002|@ohos.net.socket.d.ts|
|新增(错误码)|类名：UDPSocket;<br>方法or属性：getState(): Promise\<SocketStateBase>;<br>旧版本信息：|类名：UDPSocket;<br>方法or属性：getState(): Promise\<SocketStateBase>;<br>新版本信息：201|@ohos.net.socket.d.ts|
|新增(错误码)|类名：TCPSocket;<br>方法or属性：getState(): Promise\<SocketStateBase>;<br>旧版本信息：|类名：TCPSocket;<br>方法or属性：getState(): Promise\<SocketStateBase>;<br>新版本信息：201|@ohos.net.socket.d.ts|
|新增(错误码)|类名：TLSSocket;<br>方法or属性：getState(): Promise\<SocketStateBase>;<br>旧版本信息：|类名：TLSSocket;<br>方法or属性：getState(): Promise\<SocketStateBase>;<br>新版本信息：2303188,2300002|@ohos.net.socket.d.ts|
|新增(错误码)|类名：UDPSocket;<br>方法or属性：setExtraOptions(options: UDPExtraOptions): Promise\<void>;<br>旧版本信息：|类名：UDPSocket;<br>方法or属性：setExtraOptions(options: UDPExtraOptions): Promise\<void>;<br>新版本信息：401,201|@ohos.net.socket.d.ts|
|新增(错误码)|类名：TCPSocket;<br>方法or属性：connect(options: TCPConnectOptions): Promise\<void>;<br>旧版本信息：|类名：TCPSocket;<br>方法or属性：connect(options: TCPConnectOptions): Promise\<void>;<br>新版本信息：401,201|@ohos.net.socket.d.ts|
|新增(错误码)|类名：TCPSocket;<br>方法or属性：send(options: TCPSendOptions): Promise\<void>;<br>旧版本信息：|类名：TCPSocket;<br>方法or属性：send(options: TCPSendOptions): Promise\<void>;<br>新版本信息：401,201|@ohos.net.socket.d.ts|
|新增(错误码)|类名：TCPSocket;<br>方法or属性：getRemoteAddress(): Promise\<NetAddress>;<br>旧版本信息：|类名：TCPSocket;<br>方法or属性：getRemoteAddress(): Promise\<NetAddress>;<br>新版本信息：201|@ohos.net.socket.d.ts|
|新增(错误码)|类名：TLSSocket;<br>方法or属性：getRemoteAddress(): Promise\<NetAddress>;<br>旧版本信息：|类名：TLSSocket;<br>方法or属性：getRemoteAddress(): Promise\<NetAddress>;<br>新版本信息：2303188,2300002|@ohos.net.socket.d.ts|
|新增(错误码)|类名：TCPSocket;<br>方法or属性：setExtraOptions(options: TCPExtraOptions): Promise\<void>;<br>旧版本信息：|类名：TCPSocket;<br>方法or属性：setExtraOptions(options: TCPExtraOptions): Promise\<void>;<br>新版本信息：401,201|@ohos.net.socket.d.ts|
|新增(错误码)|类名：TLSSocket;<br>方法or属性：setExtraOptions(options: TCPExtraOptions): Promise\<void>;<br>旧版本信息：|类名：TLSSocket;<br>方法or属性：setExtraOptions(options: TCPExtraOptions): Promise\<void>;<br>新版本信息：401,2303188,2300002|@ohos.net.socket.d.ts|
|新增(错误码)|类名：TLSSocket;<br>方法or属性：getCertificate(): Promise\<X509CertRawData>;<br>旧版本信息：|类名：TLSSocket;<br>方法or属性：getCertificate(): Promise\<X509CertRawData>;<br>新版本信息：2303501,2303504,2300002|@ohos.net.socket.d.ts|
|新增(错误码)|类名：TLSSocket;<br>方法or属性：getRemoteCertificate(): Promise\<X509CertRawData>;<br>旧版本信息：|类名：TLSSocket;<br>方法or属性：getRemoteCertificate(): Promise\<X509CertRawData>;<br>新版本信息：2303501,2300002|@ohos.net.socket.d.ts|
|新增(错误码)|类名：TLSSocket;<br>方法or属性：getProtocol(): Promise\<string>;<br>旧版本信息：|类名：TLSSocket;<br>方法or属性：getProtocol(): Promise\<string>;<br>新版本信息：2303501,2303505,2300002|@ohos.net.socket.d.ts|
|新增(错误码)|类名：TLSSocket;<br>方法or属性：getCipherSuite(): Promise\<Array\<string>>;<br>旧版本信息：|类名：TLSSocket;<br>方法or属性：getCipherSuite(): Promise\<Array\<string>>;<br>新版本信息：2303501,2303502,2303505,2300002|@ohos.net.socket.d.ts|
|新增(错误码)|类名：TLSSocket;<br>方法or属性：getSignatureAlgorithms(): Promise\<Array\<string>>;<br>旧版本信息：|类名：TLSSocket;<br>方法or属性：getSignatureAlgorithms(): Promise\<Array\<string>>;<br>新版本信息：2303501,2300002|@ohos.net.socket.d.ts|
|新增(错误码)|类名：TLSSocket;<br>方法or属性：connect(options: TLSConnectOptions): Promise\<void>;<br>旧版本信息：|类名：TLSSocket;<br>方法or属性：connect(options: TLSConnectOptions): Promise\<void>;<br>新版本信息：401,2303104,2303109,2303111,2303188,2303191,2303198,2303199,2303210,2303501,2303502,2303503,2303505,2303506,2300002|@ohos.net.socket.d.ts|
|新增(错误码)|类名：TLSSocket;<br>方法or属性：send(data: string): Promise\<void>;<br>旧版本信息：|类名：TLSSocket;<br>方法or属性：send(data: string): Promise\<void>;<br>新版本信息：401,2303501,2303503,2303505,2303506,2300002|@ohos.net.socket.d.ts|
|新增(错误码)|类名：WebSocket;<br>方法or属性：connect(url: string, options: WebSocketRequestOptions, callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：WebSocket;<br>方法or属性：connect(url: string, options: WebSocketRequestOptions, callback: AsyncCallback\<boolean>): void;<br>新版本信息：401,201|@ohos.net.webSocket.d.ts|
|新增(错误码)|类名：WebSocket;<br>方法or属性：connect(url: string, options?: WebSocketRequestOptions): Promise\<boolean>;<br>旧版本信息：|类名：WebSocket;<br>方法or属性：connect(url: string, options?: WebSocketRequestOptions): Promise\<boolean>;<br>新版本信息：401,201|@ohos.net.webSocket.d.ts|
|新增(错误码)|类名：WebSocket;<br>方法or属性：send(data: string \| ArrayBuffer): Promise\<boolean>;<br>旧版本信息：|类名：WebSocket;<br>方法or属性：send(data: string \| ArrayBuffer): Promise\<boolean>;<br>新版本信息：401,201|@ohos.net.webSocket.d.ts|
|新增(错误码)|类名：WebSocket;<br>方法or属性：close(options: WebSocketCloseOptions, callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：WebSocket;<br>方法or属性：close(options: WebSocketCloseOptions, callback: AsyncCallback\<boolean>): void;<br>新版本信息：401,201|@ohos.net.webSocket.d.ts|
|新增(错误码)|类名：WebSocket;<br>方法or属性：close(options?: WebSocketCloseOptions): Promise\<boolean>;<br>旧版本信息：|类名：WebSocket;<br>方法or属性：close(options?: WebSocketCloseOptions): Promise\<boolean>;<br>新版本信息：401,201|@ohos.net.webSocket.d.ts|
|新增(错误码)|类名：wifiManager;<br>方法or属性：function addDeviceConfig(config: WifiDeviceConfig, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：wifiManager;<br>方法or属性：function addDeviceConfig(config: WifiDeviceConfig, callback: AsyncCallback\<number>): void;<br>新版本信息：201,202,401,801,2501000|@ohos.wifiManager.d.ts|
|新增(错误码)|类名：wifiManager;<br>方法or属性：function addCandidateConfig(config: WifiDeviceConfig, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：wifiManager;<br>方法or属性：function addCandidateConfig(config: WifiDeviceConfig, callback: AsyncCallback\<number>): void;<br>新版本信息：201,401,801,2501000|@ohos.wifiManager.d.ts|
|新增(错误码)|类名：wifiManager;<br>方法or属性：function removeCandidateConfig(networkId: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：wifiManager;<br>方法or属性：function removeCandidateConfig(networkId: number, callback: AsyncCallback\<void>): void;<br>新版本信息：201,401,801,2501000|@ohos.wifiManager.d.ts|
|新增(错误码)|类名：wifiManager;<br>方法or属性：function getLinkedInfo(callback: AsyncCallback\<WifiLinkedInfo>): void;<br>旧版本信息：|类名：wifiManager;<br>方法or属性：function getLinkedInfo(callback: AsyncCallback\<WifiLinkedInfo>): void;<br>新版本信息：201,202,801,2501000,2501001|@ohos.wifiManager.d.ts|
|新增(错误码)|类名：wifiManager;<br>方法or属性：function getP2pLinkedInfo(callback: AsyncCallback\<WifiP2pLinkedInfo>): void;<br>旧版本信息：|类名：wifiManager;<br>方法or属性：function getP2pLinkedInfo(callback: AsyncCallback\<WifiP2pLinkedInfo>): void;<br>新版本信息：201,801,2801000|@ohos.wifiManager.d.ts|
|新增(错误码)|类名：wifiManager;<br>方法or属性：function getCurrentP2pGroup(callback: AsyncCallback\<WifiP2pGroupInfo>): void;<br>旧版本信息：|类名：wifiManager;<br>方法or属性：function getCurrentP2pGroup(callback: AsyncCallback\<WifiP2pGroupInfo>): void;<br>新版本信息：201,801,2801000|@ohos.wifiManager.d.ts|
|新增(错误码)|类名：wifiManager;<br>方法or属性：function getP2pPeerDevices(callback: AsyncCallback\<WifiP2pDevice[]>): void;<br>旧版本信息：|类名：wifiManager;<br>方法or属性：function getP2pPeerDevices(callback: AsyncCallback\<WifiP2pDevice[]>): void;<br>新版本信息：201,801,2801000|@ohos.wifiManager.d.ts|
|新增(错误码)|类名：wifiManager;<br>方法or属性：function getP2pLocalDevice(callback: AsyncCallback\<WifiP2pDevice>): void;<br>旧版本信息：|类名：wifiManager;<br>方法or属性：function getP2pLocalDevice(callback: AsyncCallback\<WifiP2pDevice>): void;<br>新版本信息：201,801,2801000|@ohos.wifiManager.d.ts|
|新增(错误码)|类名：wifiManager;<br>方法or属性：function getP2pGroups(callback: AsyncCallback\<Array\<WifiP2pGroupInfo>>): void;<br>旧版本信息：|类名：wifiManager;<br>方法or属性：function getP2pGroups(callback: AsyncCallback\<Array\<WifiP2pGroupInfo>>): void;<br>新版本信息：201,202,801,2801000|@ohos.wifiManager.d.ts|
|错误码有变化|类名：connection;<br>方法or属性：function getDefaultNet(callback: AsyncCallback\<NetHandle>): void;<br>旧版本信息：201,2100002,2100003|类名：connection;<br>方法or属性：function getDefaultNet(callback: AsyncCallback\<NetHandle>): void;<br>新版本信息：201,401,2100002,2100003|@ohos.net.connection.d.ts|
|错误码有变化|类名：connection;<br>方法or属性：function getDefaultNetSync(): NetHandle;<br>旧版本信息：201,2100002,2100003|类名：connection;<br>方法or属性：function getDefaultNetSync(): NetHandle;<br>新版本信息：201,401,2100002,2100003|@ohos.net.connection.d.ts|
|错误码有变化|类名：connection;<br>方法or属性：function getAllNets(callback: AsyncCallback\<Array\<NetHandle>>): void;<br>旧版本信息：201,2100002,2100003|类名：connection;<br>方法or属性：function getAllNets(callback: AsyncCallback\<Array\<NetHandle>>): void;<br>新版本信息：201,401,2100002,2100003|@ohos.net.connection.d.ts|
|错误码有变化|类名：connection;<br>方法or属性：function isDefaultNetMetered(callback: AsyncCallback\<boolean>): void;<br>旧版本信息：201,2100002,2100003|类名：connection;<br>方法or属性：function isDefaultNetMetered(callback: AsyncCallback\<boolean>): void;<br>新版本信息：201,401,2100002,2100003|@ohos.net.connection.d.ts|
|错误码有变化|类名：connection;<br>方法or属性：function hasDefaultNet(callback: AsyncCallback\<boolean>): void;<br>旧版本信息：201,2100002,2100003|类名：connection;<br>方法or属性：function hasDefaultNet(callback: AsyncCallback\<boolean>): void;<br>新版本信息：201,401,2100002,2100003|@ohos.net.connection.d.ts|
|错误码有变化|类名：connection;<br>方法or属性：function enableAirplaneMode(callback: AsyncCallback\<void>): void;<br>旧版本信息：201,2100002,2100003|类名：connection;<br>方法or属性：function enableAirplaneMode(callback: AsyncCallback\<void>): void;<br>新版本信息：201,202,401,2100002,2100003|@ohos.net.connection.d.ts|
|错误码有变化|类名：connection;<br>方法or属性：function disableAirplaneMode(callback: AsyncCallback\<void>): void;<br>旧版本信息：201,2100002,2100003|类名：connection;<br>方法or属性：function disableAirplaneMode(callback: AsyncCallback\<void>): void;<br>新版本信息：201,202,401,2100002,2100003|@ohos.net.connection.d.ts|
|错误码有变化|类名：connection;<br>方法or属性：function getAppNet(callback: AsyncCallback\<NetHandle>): void;<br>旧版本信息：2100002,2100003|类名：connection;<br>方法or属性：function getAppNet(callback: AsyncCallback\<NetHandle>): void;<br>新版本信息：401,2100002,2100003|@ohos.net.connection.d.ts|
|错误码有变化|类名：connection;<br>方法or属性：function getAppNet(): Promise\<NetHandle>;<br>旧版本信息：2100002,2100003|类名：connection;<br>方法or属性：function getAppNet(): Promise\<NetHandle>;<br>新版本信息：401,2100002,2100003|@ohos.net.connection.d.ts|
|错误码有变化|类名：connection;<br>方法or属性：function getGlobalHttpProxy(callback: AsyncCallback\<HttpProxy>): void;<br>旧版本信息：2100002,2100003|类名：connection;<br>方法or属性：function getGlobalHttpProxy(callback: AsyncCallback\<HttpProxy>): void;<br>新版本信息：401,202,2100002,2100003|@ohos.net.connection.d.ts|
|错误码有变化|类名：connection;<br>方法or属性：function getGlobalHttpProxy(): Promise\<HttpProxy>;<br>旧版本信息：2100002,2100003|类名：connection;<br>方法or属性：function getGlobalHttpProxy(): Promise\<HttpProxy>;<br>新版本信息：401,202,2100002,2100003|@ohos.net.connection.d.ts|
|错误码有变化|类名：connection;<br>方法or属性：function setGlobalHttpProxy(httpProxy: HttpProxy, callback: AsyncCallback\<void>): void;<br>旧版本信息：201,401,2100001,2100002,2100003|类名：connection;<br>方法or属性：function setGlobalHttpProxy(httpProxy: HttpProxy, callback: AsyncCallback\<void>): void;<br>新版本信息：201,401,202,2100001,2100002,2100003|@ohos.net.connection.d.ts|
|错误码有变化|类名：connection;<br>方法or属性：function setGlobalHttpProxy(httpProxy: HttpProxy): Promise\<void>;<br>旧版本信息：201,401,2100001,2100002,2100003|类名：connection;<br>方法or属性：function setGlobalHttpProxy(httpProxy: HttpProxy): Promise\<void>;<br>新版本信息：201,401,202,2100001,2100002,2100003|@ohos.net.connection.d.ts|
|错误码有变化|类名：NetConnection;<br>方法or属性：register(callback: AsyncCallback\<void>): void;<br>旧版本信息：201,2100002,2100003,2101008,2101022|类名：NetConnection;<br>方法or属性：register(callback: AsyncCallback\<void>): void;<br>新版本信息：201,401,2100002,2100003,2101008,2101022|@ohos.net.connection.d.ts|
|错误码有变化|类名：NetConnection;<br>方法or属性：unregister(callback: AsyncCallback\<void>): void;<br>旧版本信息：2100002,2100003,2101007|类名：NetConnection;<br>方法or属性：unregister(callback: AsyncCallback\<void>): void;<br>新版本信息：201,401,2100002,2100003,2101007|@ohos.net.connection.d.ts|
|错误码有变化|类名：ethernet;<br>方法or属性：function getIfaceConfig(iface: string, callback: AsyncCallback\<InterfaceConfiguration>): void;<br>旧版本信息：201,401,2200001,2200002,2200003,2201005|类名：ethernet;<br>方法or属性：function getIfaceConfig(iface: string, callback: AsyncCallback\<InterfaceConfiguration>): void;<br>新版本信息：201,202,401,2200001,2200002,2200003,2201005|@ohos.net.ethernet.d.ts|
|错误码有变化|类名：ethernet;<br>方法or属性：function setIfaceConfig(iface: string, ic: InterfaceConfiguration, callback: AsyncCallback\<void>): void;<br>旧版本信息：201,401,2200001,2200002,2200003,2201004,2201005,2201006,2201007|类名：ethernet;<br>方法or属性：function setIfaceConfig(iface: string, ic: InterfaceConfiguration, callback: AsyncCallback\<void>): void;<br>新版本信息：201,202,401,2200001,2200002,2200003,2201004,2201005,2201006,2201007|@ohos.net.ethernet.d.ts|
|错误码有变化|类名：ethernet;<br>方法or属性：function isIfaceActive(iface: string, callback: AsyncCallback\<number>): void;<br>旧版本信息：201,401,2200001,2200002,2200003,2201005|类名：ethernet;<br>方法or属性：function isIfaceActive(iface: string, callback: AsyncCallback\<number>): void;<br>新版本信息：201,202,401,2200001,2200002,2200003,2201005|@ohos.net.ethernet.d.ts|
|错误码有变化|类名：ethernet;<br>方法or属性：function getAllActiveIfaces(callback: AsyncCallback\<Array\<string>>): void;<br>旧版本信息：201,2200002,2200003|类名：ethernet;<br>方法or属性：function getAllActiveIfaces(callback: AsyncCallback\<Array\<string>>): void;<br>新版本信息：201,202,2200002,2200003|@ohos.net.ethernet.d.ts|
|错误码有变化|类名：sharing;<br>方法or属性：function isSharingSupported(callback: AsyncCallback\<boolean>): void;<br>旧版本信息：201,2200002,2200003,2202011|类名：sharing;<br>方法or属性：function isSharingSupported(callback: AsyncCallback\<boolean>): void;<br>新版本信息：201,202,2200002,2200003,2202011|@ohos.net.sharing.d.ts|
|错误码有变化|类名：sharing;<br>方法or属性：function isSharing(callback: AsyncCallback\<boolean>): void;<br>旧版本信息：201,2200002,2200003,2202011|类名：sharing;<br>方法or属性：function isSharing(callback: AsyncCallback\<boolean>): void;<br>新版本信息：201,202,2200002,2200003,2202011|@ohos.net.sharing.d.ts|
|错误码有变化|类名：sharing;<br>方法or属性：function startSharing(type: SharingIfaceType, callback: AsyncCallback\<void>): void;<br>旧版本信息：201,401,2200001,2200002,2200003,2202004,2202005,2202006,2202009,2202011|类名：sharing;<br>方法or属性：function startSharing(type: SharingIfaceType, callback: AsyncCallback\<void>): void;<br>新版本信息：201,202,401,2200001,2200002,2200003,2202004,2202005,2202006,2202009,2202011|@ohos.net.sharing.d.ts|
|错误码有变化|类名：sharing;<br>方法or属性：function stopSharing(type: SharingIfaceType, callback: AsyncCallback\<void>): void;<br>旧版本信息：201,401,2200001,2200002,2200003,2202004,2202005,2202006,2202011|类名：sharing;<br>方法or属性：function stopSharing(type: SharingIfaceType, callback: AsyncCallback\<void>): void;<br>新版本信息：201,202,401,2200001,2200002,2200003,2202004,2202005,2202006,2202011|@ohos.net.sharing.d.ts|
|错误码有变化|类名：sharing;<br>方法or属性：function getStatsRxBytes(callback: AsyncCallback\<number>): void;<br>旧版本信息：201,2200002,2200003|类名：sharing;<br>方法or属性：function getStatsRxBytes(callback: AsyncCallback\<number>): void;<br>新版本信息：201,202,401,2200002,2200003|@ohos.net.sharing.d.ts|
|错误码有变化|类名：sharing;<br>方法or属性：function getStatsTxBytes(callback: AsyncCallback\<number>): void;<br>旧版本信息：201,2200002,2200003|类名：sharing;<br>方法or属性：function getStatsTxBytes(callback: AsyncCallback\<number>): void;<br>新版本信息：201,202,401,2200002,2200003|@ohos.net.sharing.d.ts|
|错误码有变化|类名：sharing;<br>方法or属性：function getStatsTotalBytes(callback: AsyncCallback\<number>): void;<br>旧版本信息：201,2200002,2200003|类名：sharing;<br>方法or属性：function getStatsTotalBytes(callback: AsyncCallback\<number>): void;<br>新版本信息：201,202,401,2200002,2200003|@ohos.net.sharing.d.ts|
|错误码有变化|类名：sharing;<br>方法or属性：function getSharingIfaces(state: SharingIfaceState, callback: AsyncCallback\<Array\<string>>): void;<br>旧版本信息：201,401,2200001,2200002,2200003|类名：sharing;<br>方法or属性：function getSharingIfaces(state: SharingIfaceState, callback: AsyncCallback\<Array\<string>>): void;<br>新版本信息：201,202,401,2200001,2200002,2200003|@ohos.net.sharing.d.ts|
|错误码有变化|类名：sharing;<br>方法or属性：function getSharingState(type: SharingIfaceType, callback: AsyncCallback\<SharingIfaceState>): void;<br>旧版本信息：201,401,2200001,2200002,2200003|类名：sharing;<br>方法or属性：function getSharingState(type: SharingIfaceType, callback: AsyncCallback\<SharingIfaceState>): void;<br>新版本信息：201,202,401,2200001,2200002,2200003|@ohos.net.sharing.d.ts|
|错误码有变化|类名：sharing;<br>方法or属性：function getSharableRegexes(type: SharingIfaceType, callback: AsyncCallback\<Array\<string>>): void;<br>旧版本信息：201,401,2200001,2200002,2200003|类名：sharing;<br>方法or属性：function getSharableRegexes(type: SharingIfaceType, callback: AsyncCallback\<Array\<string>>): void;<br>新版本信息：201,202,401,2200001,2200002,2200003|@ohos.net.sharing.d.ts|
|错误码有变化|类名：sharing;<br>方法or属性：function on(type: 'sharingStateChange', callback: Callback\<boolean>): void;<br>旧版本信息：201,401|类名：sharing;<br>方法or属性：function on(type: 'sharingStateChange', callback: Callback\<boolean>): void;<br>新版本信息：201,202,401|@ohos.net.sharing.d.ts|
|错误码有变化|类名：sharing;<br>方法or属性：function on(type: 'interfaceSharingStateChange', callback: Callback\<{ type: SharingIfaceType, iface: string, state: SharingIfaceState }>): void;<br>旧版本信息：201,401|类名：sharing;<br>方法or属性：function on(type: 'interfaceSharingStateChange', callback: Callback\<{ type: SharingIfaceType, iface: string, state: SharingIfaceState }>): void;<br>新版本信息：201,202,401|@ohos.net.sharing.d.ts|
|错误码有变化|类名：sharing;<br>方法or属性：function on(type: 'sharingUpstreamChange', callback: Callback\<NetHandle>): void;<br>旧版本信息：201,401|类名：sharing;<br>方法or属性：function on(type: 'sharingUpstreamChange', callback: Callback\<NetHandle>): void;<br>新版本信息：201,202,401|@ohos.net.sharing.d.ts|
|错误码有变化|类名：sharing;<br>方法or属性：function off(type: 'sharingStateChange', callback?: Callback\<boolean>): void;<br>旧版本信息：201,401|类名：sharing;<br>方法or属性：function off(type: 'sharingStateChange', callback?: Callback\<boolean>): void;<br>新版本信息：201,202,401|@ohos.net.sharing.d.ts|
|错误码有变化|类名：sharing;<br>方法or属性：function off(type: 'interfaceSharingStateChange', callback?: Callback\<{ type: SharingIfaceType, iface: string, state: SharingIfaceState }>): void;<br>旧版本信息：201,401|类名：sharing;<br>方法or属性：function off(type: 'interfaceSharingStateChange', callback?: Callback\<{ type: SharingIfaceType, iface: string, state: SharingIfaceState }>): void;<br>新版本信息：201,202,401|@ohos.net.sharing.d.ts|
|错误码有变化|类名：sharing;<br>方法or属性：function off(type: 'sharingUpstreamChange', callback?: Callback\<NetHandle>): void;<br>旧版本信息：201,401|类名：sharing;<br>方法or属性：function off(type: 'sharingUpstreamChange', callback?: Callback\<NetHandle>): void;<br>新版本信息：201,202,401|@ohos.net.sharing.d.ts|
|访问级别有变化|类名：connection;<br>方法or属性：function enableAirplaneMode(): Promise\<void>;<br>旧版本信息：|类名：connection;<br>方法or属性：function enableAirplaneMode(): Promise\<void>;<br>新版本信息：systemapi|@ohos.net.connection.d.ts|
|访问级别有变化|类名：connection;<br>方法or属性：function disableAirplaneMode(): Promise\<void>;<br>旧版本信息：|类名：connection;<br>方法or属性：function disableAirplaneMode(): Promise\<void>;<br>新版本信息：systemapi|@ohos.net.connection.d.ts|
|访问级别有变化|类名：ethernet;<br>方法or属性：function getIfaceConfig(iface: string): Promise\<InterfaceConfiguration>;<br>旧版本信息：|类名：ethernet;<br>方法or属性：function getIfaceConfig(iface: string): Promise\<InterfaceConfiguration>;<br>新版本信息：systemapi|@ohos.net.ethernet.d.ts|
|访问级别有变化|类名：ethernet;<br>方法or属性：function setIfaceConfig(iface: string, ic: InterfaceConfiguration): Promise\<void>;<br>旧版本信息：|类名：ethernet;<br>方法or属性：function setIfaceConfig(iface: string, ic: InterfaceConfiguration): Promise\<void>;<br>新版本信息：systemapi|@ohos.net.ethernet.d.ts|
|访问级别有变化|类名：ethernet;<br>方法or属性：function isIfaceActive(iface: string): Promise\<number>;<br>旧版本信息：|类名：ethernet;<br>方法or属性：function isIfaceActive(iface: string): Promise\<number>;<br>新版本信息：systemapi|@ohos.net.ethernet.d.ts|
|访问级别有变化|类名：ethernet;<br>方法or属性：function getAllActiveIfaces(): Promise\<Array\<string>>;<br>旧版本信息：|类名：ethernet;<br>方法or属性：function getAllActiveIfaces(): Promise\<Array\<string>>;<br>新版本信息：systemapi|@ohos.net.ethernet.d.ts|
|访问级别有变化|类名：InterfaceConfiguration;<br>方法or属性：mode: IPSetMode;<br>旧版本信息：|类名：InterfaceConfiguration;<br>方法or属性：mode: IPSetMode;<br>新版本信息：systemapi|@ohos.net.ethernet.d.ts|
|访问级别有变化|类名：InterfaceConfiguration;<br>方法or属性：ipAddr: string;<br>旧版本信息：|类名：InterfaceConfiguration;<br>方法or属性：ipAddr: string;<br>新版本信息：systemapi|@ohos.net.ethernet.d.ts|
|访问级别有变化|类名：InterfaceConfiguration;<br>方法or属性：route: string;<br>旧版本信息：|类名：InterfaceConfiguration;<br>方法or属性：route: string;<br>新版本信息：systemapi|@ohos.net.ethernet.d.ts|
|访问级别有变化|类名：InterfaceConfiguration;<br>方法or属性：gateway: string;<br>旧版本信息：|类名：InterfaceConfiguration;<br>方法or属性：gateway: string;<br>新版本信息：systemapi|@ohos.net.ethernet.d.ts|
|访问级别有变化|类名：InterfaceConfiguration;<br>方法or属性：netMask: string;<br>旧版本信息：|类名：InterfaceConfiguration;<br>方法or属性：netMask: string;<br>新版本信息：systemapi|@ohos.net.ethernet.d.ts|
|访问级别有变化|类名：InterfaceConfiguration;<br>方法or属性：dnsServers: string;<br>旧版本信息：|类名：InterfaceConfiguration;<br>方法or属性：dnsServers: string;<br>新版本信息：systemapi|@ohos.net.ethernet.d.ts|
|访问级别有变化|类名：IPSetMode;<br>方法or属性：STATIC = 0<br>旧版本信息：|类名：IPSetMode;<br>方法or属性：STATIC = 0<br>新版本信息：systemapi|@ohos.net.ethernet.d.ts|
|访问级别有变化|类名：IPSetMode;<br>方法or属性：DHCP = 1<br>旧版本信息：|类名：IPSetMode;<br>方法or属性：DHCP = 1<br>新版本信息：systemapi|@ohos.net.ethernet.d.ts|
|访问级别有变化|类名：sharing;<br>方法or属性：function isSharingSupported(): Promise\<boolean>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function isSharingSupported(): Promise\<boolean>;<br>新版本信息：systemapi|@ohos.net.sharing.d.ts|
|访问级别有变化|类名：sharing;<br>方法or属性：function isSharing(): Promise\<boolean>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function isSharing(): Promise\<boolean>;<br>新版本信息：systemapi|@ohos.net.sharing.d.ts|
|访问级别有变化|类名：sharing;<br>方法or属性：function startSharing(type: SharingIfaceType): Promise\<void>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function startSharing(type: SharingIfaceType): Promise\<void>;<br>新版本信息：systemapi|@ohos.net.sharing.d.ts|
|访问级别有变化|类名：sharing;<br>方法or属性：function stopSharing(type: SharingIfaceType): Promise\<void>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function stopSharing(type: SharingIfaceType): Promise\<void>;<br>新版本信息：systemapi|@ohos.net.sharing.d.ts|
|访问级别有变化|类名：sharing;<br>方法or属性：function getStatsRxBytes(): Promise\<number>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function getStatsRxBytes(): Promise\<number>;<br>新版本信息：systemapi|@ohos.net.sharing.d.ts|
|访问级别有变化|类名：sharing;<br>方法or属性：function getStatsTxBytes(): Promise\<number>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function getStatsTxBytes(): Promise\<number>;<br>新版本信息：systemapi|@ohos.net.sharing.d.ts|
|访问级别有变化|类名：sharing;<br>方法or属性：function getStatsTotalBytes(): Promise\<number>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function getStatsTotalBytes(): Promise\<number>;<br>新版本信息：systemapi|@ohos.net.sharing.d.ts|
|访问级别有变化|类名：sharing;<br>方法or属性：function getSharingIfaces(state: SharingIfaceState): Promise\<Array\<string>>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function getSharingIfaces(state: SharingIfaceState): Promise\<Array\<string>>;<br>新版本信息：systemapi|@ohos.net.sharing.d.ts|
|访问级别有变化|类名：sharing;<br>方法or属性：function getSharingState(type: SharingIfaceType): Promise\<SharingIfaceState>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function getSharingState(type: SharingIfaceType): Promise\<SharingIfaceState>;<br>新版本信息：systemapi|@ohos.net.sharing.d.ts|
|访问级别有变化|类名：sharing;<br>方法or属性：function getSharableRegexes(type: SharingIfaceType): Promise\<Array\<string>>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function getSharableRegexes(type: SharingIfaceType): Promise\<Array\<string>>;<br>新版本信息：systemapi|@ohos.net.sharing.d.ts|
|访问级别有变化|类名：SharingIfaceState;<br>方法or属性：SHARING_NIC_SERVING = 1<br>旧版本信息：|类名：SharingIfaceState;<br>方法or属性：SHARING_NIC_SERVING = 1<br>新版本信息：systemapi|@ohos.net.sharing.d.ts|
|访问级别有变化|类名：SharingIfaceState;<br>方法or属性：SHARING_NIC_CAN_SERVER = 2<br>旧版本信息：|类名：SharingIfaceState;<br>方法or属性：SHARING_NIC_CAN_SERVER = 2<br>新版本信息：systemapi|@ohos.net.sharing.d.ts|
|访问级别有变化|类名：SharingIfaceState;<br>方法or属性：SHARING_NIC_ERROR = 3<br>旧版本信息：|类名：SharingIfaceState;<br>方法or属性：SHARING_NIC_ERROR = 3<br>新版本信息：systemapi|@ohos.net.sharing.d.ts|
|访问级别有变化|类名：SharingIfaceType;<br>方法or属性：SHARING_WIFI = 0<br>旧版本信息：|类名：SharingIfaceType;<br>方法or属性：SHARING_WIFI = 0<br>新版本信息：systemapi|@ohos.net.sharing.d.ts|
|访问级别有变化|类名：SharingIfaceType;<br>方法or属性：SHARING_USB = 1<br>旧版本信息：|类名：SharingIfaceType;<br>方法or属性：SHARING_USB = 1<br>新版本信息：systemapi|@ohos.net.sharing.d.ts|
|访问级别有变化|类名：SharingIfaceType;<br>方法or属性：SHARING_BLUETOOTH = 2<br>旧版本信息：|类名：SharingIfaceType;<br>方法or属性：SHARING_BLUETOOTH = 2<br>新版本信息：systemapi|@ohos.net.sharing.d.ts|
|访问级别有变化|类名：wifiManager;<br>方法or属性：function addDeviceConfig(config: WifiDeviceConfig, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：wifiManager;<br>方法or属性：function addDeviceConfig(config: WifiDeviceConfig, callback: AsyncCallback\<number>): void;<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：wifiManager;<br>方法or属性：function getP2pGroups(callback: AsyncCallback\<Array\<WifiP2pGroupInfo>>): void;<br>旧版本信息：|类名：wifiManager;<br>方法or属性：function getP2pGroups(callback: AsyncCallback\<Array\<WifiP2pGroupInfo>>): void;<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：EapMethod;<br>方法or属性：enum EapMethod<br>旧版本信息：systemapi|类名：EapMethod;<br>方法or属性：enum EapMethod<br>新版本信息：|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：Phase2Method;<br>方法or属性：enum Phase2Method<br>旧版本信息：systemapi|类名：Phase2Method;<br>方法or属性：enum Phase2Method<br>新版本信息：|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：WifiEapConfig;<br>方法or属性：interface WifiEapConfig<br>旧版本信息：systemapi|类名：WifiEapConfig;<br>方法or属性：interface WifiEapConfig<br>新版本信息：|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：WifiDeviceConfig;<br>方法or属性：creatorUid?: number;<br>旧版本信息：|类名：WifiDeviceConfig;<br>方法or属性：creatorUid?: number;<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：WifiDeviceConfig;<br>方法or属性：disableReason?: number;<br>旧版本信息：|类名：WifiDeviceConfig;<br>方法or属性：disableReason?: number;<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：WifiDeviceConfig;<br>方法or属性：netId?: number;<br>旧版本信息：|类名：WifiDeviceConfig;<br>方法or属性：netId?: number;<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：WifiDeviceConfig;<br>方法or属性：randomMacType?: number;<br>旧版本信息：|类名：WifiDeviceConfig;<br>方法or属性：randomMacType?: number;<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：WifiDeviceConfig;<br>方法or属性：randomMacAddr?: string;<br>旧版本信息：|类名：WifiDeviceConfig;<br>方法or属性：randomMacAddr?: string;<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：WifiDeviceConfig;<br>方法or属性：ipType?: IpType;<br>旧版本信息：|类名：WifiDeviceConfig;<br>方法or属性：ipType?: IpType;<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：WifiDeviceConfig;<br>方法or属性：staticIp?: IpConfig;<br>旧版本信息：|类名：WifiDeviceConfig;<br>方法or属性：staticIp?: IpConfig;<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：WifiDeviceConfig;<br>方法or属性：eapConfig?: WifiEapConfig;<br>旧版本信息：systemapi|类名：WifiDeviceConfig;<br>方法or属性：eapConfig?: WifiEapConfig;<br>新版本信息：|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：IpConfig;<br>方法or属性：ipAddress: number;<br>旧版本信息：|类名：IpConfig;<br>方法or属性：ipAddress: number;<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：IpConfig;<br>方法or属性：gateway: number;<br>旧版本信息：|类名：IpConfig;<br>方法or属性：gateway: number;<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：IpConfig;<br>方法or属性：prefixLength: number;<br>旧版本信息：|类名：IpConfig;<br>方法or属性：prefixLength: number;<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：IpConfig;<br>方法or属性：dnsServers: number[];<br>旧版本信息：|类名：IpConfig;<br>方法or属性：dnsServers: number[];<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：IpConfig;<br>方法or属性：domains: Array\<string>;<br>旧版本信息：|类名：IpConfig;<br>方法or属性：domains: Array\<string>;<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：WifiLinkedInfo;<br>方法or属性：networkId: number;<br>旧版本信息：|类名：WifiLinkedInfo;<br>方法or属性：networkId: number;<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：WifiLinkedInfo;<br>方法or属性：chload: number;<br>旧版本信息：|类名：WifiLinkedInfo;<br>方法or属性：chload: number;<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：WifiLinkedInfo;<br>方法or属性：snr: number;<br>旧版本信息：|类名：WifiLinkedInfo;<br>方法or属性：snr: number;<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：WifiLinkedInfo;<br>方法or属性：suppState: SuppState;<br>旧版本信息：|类名：WifiLinkedInfo;<br>方法or属性：suppState: SuppState;<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：HotspotConfig;<br>方法or属性：ssid: string;<br>旧版本信息：|类名：HotspotConfig;<br>方法or属性：ssid: string;<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：HotspotConfig;<br>方法or属性：securityType: WifiSecurityType;<br>旧版本信息：|类名：HotspotConfig;<br>方法or属性：securityType: WifiSecurityType;<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：HotspotConfig;<br>方法or属性：band: number;<br>旧版本信息：|类名：HotspotConfig;<br>方法or属性：band: number;<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：HotspotConfig;<br>方法or属性：channel?: number;<br>旧版本信息：|类名：HotspotConfig;<br>方法or属性：channel?: number;<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：HotspotConfig;<br>方法or属性：preSharedKey: string;<br>旧版本信息：|类名：HotspotConfig;<br>方法or属性：preSharedKey: string;<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：HotspotConfig;<br>方法or属性：maxConn: number;<br>旧版本信息：|类名：HotspotConfig;<br>方法or属性：maxConn: number;<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：StationInfo;<br>方法or属性：name: string;<br>旧版本信息：|类名：StationInfo;<br>方法or属性：name: string;<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：StationInfo;<br>方法or属性：macAddress: string;<br>旧版本信息：|类名：StationInfo;<br>方法or属性：macAddress: string;<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：StationInfo;<br>方法or属性：ipAddress: string;<br>旧版本信息：|类名：StationInfo;<br>方法or属性：ipAddress: string;<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：IpType;<br>方法or属性：STATIC<br>旧版本信息：|类名：IpType;<br>方法or属性：STATIC<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：IpType;<br>方法or属性：DHCP<br>旧版本信息：|类名：IpType;<br>方法or属性：DHCP<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：IpType;<br>方法or属性：UNKNOWN<br>旧版本信息：|类名：IpType;<br>方法or属性：UNKNOWN<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：SuppState;<br>方法or属性：DISCONNECTED<br>旧版本信息：|类名：SuppState;<br>方法or属性：DISCONNECTED<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：SuppState;<br>方法or属性：INTERFACE_DISABLED<br>旧版本信息：|类名：SuppState;<br>方法or属性：INTERFACE_DISABLED<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：SuppState;<br>方法or属性：INACTIVE<br>旧版本信息：|类名：SuppState;<br>方法or属性：INACTIVE<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：SuppState;<br>方法or属性：SCANNING<br>旧版本信息：|类名：SuppState;<br>方法or属性：SCANNING<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：SuppState;<br>方法or属性：AUTHENTICATING<br>旧版本信息：|类名：SuppState;<br>方法or属性：AUTHENTICATING<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：SuppState;<br>方法or属性：ASSOCIATING<br>旧版本信息：|类名：SuppState;<br>方法or属性：ASSOCIATING<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：SuppState;<br>方法or属性：ASSOCIATED<br>旧版本信息：|类名：SuppState;<br>方法or属性：ASSOCIATED<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：SuppState;<br>方法or属性：FOUR_WAY_HANDSHAKE<br>旧版本信息：|类名：SuppState;<br>方法or属性：FOUR_WAY_HANDSHAKE<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：SuppState;<br>方法or属性：GROUP_HANDSHAKE<br>旧版本信息：|类名：SuppState;<br>方法or属性：GROUP_HANDSHAKE<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：SuppState;<br>方法or属性：COMPLETED<br>旧版本信息：|类名：SuppState;<br>方法or属性：COMPLETED<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：SuppState;<br>方法or属性：UNINITIALIZED<br>旧版本信息：|类名：SuppState;<br>方法or属性：UNINITIALIZED<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：SuppState;<br>方法or属性：INVALID<br>旧版本信息：|类名：SuppState;<br>方法or属性：INVALID<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|权限有变化|类名：GattClientDevice;<br>方法or属性：getDeviceName(): Promise\<string>;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：getDeviceName(): Promise\<string>;<br>新版本信息：ohos.permission.USE_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：GattClientDevice;<br>方法or属性：getServices(): Promise\<Array\<GattService>>;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：getServices(): Promise\<Array\<GattService>>;<br>新版本信息：ohos.permission.USE_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：GattClientDevice;<br>方法or属性：readCharacteristicValue(characteristic: BLECharacteristic): Promise\<BLECharacteristic>;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：readCharacteristicValue(characteristic: BLECharacteristic): Promise\<BLECharacteristic>;<br>新版本信息：ohos.permission.USE_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：GattClientDevice;<br>方法or属性：readDescriptorValue(descriptor: BLEDescriptor): Promise\<BLEDescriptor>;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：readDescriptorValue(descriptor: BLEDescriptor): Promise\<BLEDescriptor>;<br>新版本信息：ohos.permission.USE_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：GattClientDevice;<br>方法or属性：getRssiValue(): Promise\<number>;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：getRssiValue(): Promise\<number>;<br>新版本信息：ohos.permission.USE_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：connection;<br>方法or属性：function getDefaultNet(): Promise\<NetHandle>;<br>旧版本信息：|类名：connection;<br>方法or属性：function getDefaultNet(): Promise\<NetHandle>;<br>新版本信息：ohos.permission.GET_NETWORK_INFO|@ohos.net.connection.d.ts|
|权限有变化|类名：connection;<br>方法or属性：function getAllNets(): Promise\<Array\<NetHandle>>;<br>旧版本信息：|类名：connection;<br>方法or属性：function getAllNets(): Promise\<Array\<NetHandle>>;<br>新版本信息：ohos.permission.GET_NETWORK_INFO|@ohos.net.connection.d.ts|
|权限有变化|类名：connection;<br>方法or属性：function getConnectionProperties(netHandle: NetHandle): Promise\<ConnectionProperties>;<br>旧版本信息：|类名：connection;<br>方法or属性：function getConnectionProperties(netHandle: NetHandle): Promise\<ConnectionProperties>;<br>新版本信息：ohos.permission.GET_NETWORK_INFO|@ohos.net.connection.d.ts|
|权限有变化|类名：connection;<br>方法or属性：function getNetCapabilities(netHandle: NetHandle): Promise\<NetCapabilities>;<br>旧版本信息：|类名：connection;<br>方法or属性：function getNetCapabilities(netHandle: NetHandle): Promise\<NetCapabilities>;<br>新版本信息：ohos.permission.GET_NETWORK_INFO|@ohos.net.connection.d.ts|
|权限有变化|类名：connection;<br>方法or属性：function isDefaultNetMetered(): Promise\<boolean>;<br>旧版本信息：|类名：connection;<br>方法or属性：function isDefaultNetMetered(): Promise\<boolean>;<br>新版本信息：ohos.permission.GET_NETWORK_INFO|@ohos.net.connection.d.ts|
|权限有变化|类名：connection;<br>方法or属性：function hasDefaultNet(): Promise\<boolean>;<br>旧版本信息：|类名：connection;<br>方法or属性：function hasDefaultNet(): Promise\<boolean>;<br>新版本信息：ohos.permission.GET_NETWORK_INFO|@ohos.net.connection.d.ts|
|权限有变化|类名：connection;<br>方法or属性：function enableAirplaneMode(): Promise\<void>;<br>旧版本信息：|类名：connection;<br>方法or属性：function enableAirplaneMode(): Promise\<void>;<br>新版本信息：ohos.permission.CONNECTIVITY_INTERNAL|@ohos.net.connection.d.ts|
|权限有变化|类名：connection;<br>方法or属性：function disableAirplaneMode(): Promise\<void>;<br>旧版本信息：|类名：connection;<br>方法or属性：function disableAirplaneMode(): Promise\<void>;<br>新版本信息：ohos.permission.CONNECTIVITY_INTERNAL|@ohos.net.connection.d.ts|
|权限有变化|类名：connection;<br>方法or属性：function reportNetConnected(netHandle: NetHandle): Promise\<void>;<br>旧版本信息：|类名：connection;<br>方法or属性：function reportNetConnected(netHandle: NetHandle): Promise\<void>;<br>新版本信息：ohos.permission.GET_NETWORK_INFO,ohos.permission.INTERNET|@ohos.net.connection.d.ts|
|权限有变化|类名：connection;<br>方法or属性：function reportNetDisconnected(netHandle: NetHandle): Promise\<void>;<br>旧版本信息：|类名：connection;<br>方法or属性：function reportNetDisconnected(netHandle: NetHandle): Promise\<void>;<br>新版本信息：ohos.permission.GET_NETWORK_INFO,ohos.permission.INTERNET|@ohos.net.connection.d.ts|
|权限有变化|类名：connection;<br>方法or属性：function getAddressesByName(host: string): Promise\<Array\<NetAddress>>;<br>旧版本信息：|类名：connection;<br>方法or属性：function getAddressesByName(host: string): Promise\<Array\<NetAddress>>;<br>新版本信息：ohos.permission.INTERNET|@ohos.net.connection.d.ts|
|权限有变化|类名：NetHandle;<br>方法or属性：getAddressesByName(host: string): Promise\<Array\<NetAddress>>;<br>旧版本信息：|类名：NetHandle;<br>方法or属性：getAddressesByName(host: string): Promise\<Array\<NetAddress>>;<br>新版本信息：ohos.permission.INTERNET|@ohos.net.connection.d.ts|
|权限有变化|类名：NetHandle;<br>方法or属性：getAddressByName(host: string): Promise\<NetAddress>;<br>旧版本信息：|类名：NetHandle;<br>方法or属性：getAddressByName(host: string): Promise\<NetAddress>;<br>新版本信息：ohos.permission.INTERNET|@ohos.net.connection.d.ts|
|权限有变化|类名：ethernet;<br>方法or属性：function getIfaceConfig(iface: string): Promise\<InterfaceConfiguration>;<br>旧版本信息：|类名：ethernet;<br>方法or属性：function getIfaceConfig(iface: string): Promise\<InterfaceConfiguration>;<br>新版本信息：ohos.permission.GET_NETWORK_INFO|@ohos.net.ethernet.d.ts|
|权限有变化|类名：ethernet;<br>方法or属性：function setIfaceConfig(iface: string, ic: InterfaceConfiguration): Promise\<void>;<br>旧版本信息：|类名：ethernet;<br>方法or属性：function setIfaceConfig(iface: string, ic: InterfaceConfiguration): Promise\<void>;<br>新版本信息：ohos.permission.CONNECTIVITY_INTERNAL|@ohos.net.ethernet.d.ts|
|权限有变化|类名：ethernet;<br>方法or属性：function isIfaceActive(iface: string): Promise\<number>;<br>旧版本信息：|类名：ethernet;<br>方法or属性：function isIfaceActive(iface: string): Promise\<number>;<br>新版本信息：ohos.permission.GET_NETWORK_INFO|@ohos.net.ethernet.d.ts|
|权限有变化|类名：ethernet;<br>方法or属性：function getAllActiveIfaces(): Promise\<Array\<string>>;<br>旧版本信息：|类名：ethernet;<br>方法or属性：function getAllActiveIfaces(): Promise\<Array\<string>>;<br>新版本信息：ohos.permission.GET_NETWORK_INFO|@ohos.net.ethernet.d.ts|
|权限有变化|类名：HttpRequest;<br>方法or属性：request(url: string, options: HttpRequestOptions, callback: AsyncCallback\<HttpResponse>): void;<br>旧版本信息：|类名：HttpRequest;<br>方法or属性：request(url: string, options: HttpRequestOptions, callback: AsyncCallback\<HttpResponse>): void;<br>新版本信息：ohos.permission.INTERNET|@ohos.net.http.d.ts|
|权限有变化|类名：HttpRequest;<br>方法or属性：request(url: string, options?: HttpRequestOptions): Promise\<HttpResponse>;<br>旧版本信息：|类名：HttpRequest;<br>方法or属性：request(url: string, options?: HttpRequestOptions): Promise\<HttpResponse>;<br>新版本信息：ohos.permission.INTERNET|@ohos.net.http.d.ts|
|权限有变化|类名：sharing;<br>方法or属性：function isSharingSupported(): Promise\<boolean>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function isSharingSupported(): Promise\<boolean>;<br>新版本信息：ohos.permission.CONNECTIVITY_INTERNAL|@ohos.net.sharing.d.ts|
|权限有变化|类名：sharing;<br>方法or属性：function isSharing(): Promise\<boolean>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function isSharing(): Promise\<boolean>;<br>新版本信息：ohos.permission.CONNECTIVITY_INTERNAL|@ohos.net.sharing.d.ts|
|权限有变化|类名：sharing;<br>方法or属性：function startSharing(type: SharingIfaceType): Promise\<void>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function startSharing(type: SharingIfaceType): Promise\<void>;<br>新版本信息：ohos.permission.CONNECTIVITY_INTERNAL|@ohos.net.sharing.d.ts|
|权限有变化|类名：sharing;<br>方法or属性：function stopSharing(type: SharingIfaceType): Promise\<void>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function stopSharing(type: SharingIfaceType): Promise\<void>;<br>新版本信息：ohos.permission.CONNECTIVITY_INTERNAL|@ohos.net.sharing.d.ts|
|权限有变化|类名：sharing;<br>方法or属性：function getStatsRxBytes(): Promise\<number>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function getStatsRxBytes(): Promise\<number>;<br>新版本信息：ohos.permission.CONNECTIVITY_INTERNAL|@ohos.net.sharing.d.ts|
|权限有变化|类名：sharing;<br>方法or属性：function getStatsTxBytes(): Promise\<number>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function getStatsTxBytes(): Promise\<number>;<br>新版本信息：ohos.permission.CONNECTIVITY_INTERNAL|@ohos.net.sharing.d.ts|
|权限有变化|类名：sharing;<br>方法or属性：function getStatsTotalBytes(): Promise\<number>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function getStatsTotalBytes(): Promise\<number>;<br>新版本信息：ohos.permission.CONNECTIVITY_INTERNAL|@ohos.net.sharing.d.ts|
|权限有变化|类名：sharing;<br>方法or属性：function getSharingIfaces(state: SharingIfaceState): Promise\<Array\<string>>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function getSharingIfaces(state: SharingIfaceState): Promise\<Array\<string>>;<br>新版本信息：ohos.permission.CONNECTIVITY_INTERNAL|@ohos.net.sharing.d.ts|
|权限有变化|类名：sharing;<br>方法or属性：function getSharingState(type: SharingIfaceType): Promise\<SharingIfaceState>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function getSharingState(type: SharingIfaceType): Promise\<SharingIfaceState>;<br>新版本信息：ohos.permission.CONNECTIVITY_INTERNAL|@ohos.net.sharing.d.ts|
|权限有变化|类名：sharing;<br>方法or属性：function getSharableRegexes(type: SharingIfaceType): Promise\<Array\<string>>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function getSharableRegexes(type: SharingIfaceType): Promise\<Array\<string>>;<br>新版本信息：ohos.permission.CONNECTIVITY_INTERNAL|@ohos.net.sharing.d.ts|
|权限有变化|类名：UDPSocket;<br>方法or属性：bind(address: NetAddress): Promise\<void>;<br>旧版本信息：|类名：UDPSocket;<br>方法or属性：bind(address: NetAddress): Promise\<void>;<br>新版本信息：ohos.permission.INTERNET|@ohos.net.socket.d.ts|
|权限有变化|类名：TCPSocket;<br>方法or属性：bind(address: NetAddress): Promise\<void>;<br>旧版本信息：|类名：TCPSocket;<br>方法or属性：bind(address: NetAddress): Promise\<void>;<br>新版本信息：ohos.permission.INTERNET|@ohos.net.socket.d.ts|
|权限有变化|类名：TLSSocket;<br>方法or属性：bind(address: NetAddress): Promise\<void>;<br>旧版本信息：|类名：TLSSocket;<br>方法or属性：bind(address: NetAddress): Promise\<void>;<br>新版本信息：ohos.permission.INTERNET|@ohos.net.socket.d.ts|
|权限有变化|类名：UDPSocket;<br>方法or属性：send(options: UDPSendOptions): Promise\<void>;<br>旧版本信息：|类名：UDPSocket;<br>方法or属性：send(options: UDPSendOptions): Promise\<void>;<br>新版本信息：ohos.permission.INTERNET|@ohos.net.socket.d.ts|
|权限有变化|类名：UDPSocket;<br>方法or属性：close(): Promise\<void>;<br>旧版本信息：|类名：UDPSocket;<br>方法or属性：close(): Promise\<void>;<br>新版本信息：ohos.permission.INTERNET|@ohos.net.socket.d.ts|
|权限有变化|类名：TCPSocket;<br>方法or属性：close(): Promise\<void>;<br>旧版本信息：|类名：TCPSocket;<br>方法or属性：close(): Promise\<void>;<br>新版本信息：ohos.permission.INTERNET|@ohos.net.socket.d.ts|
|权限有变化|类名：UDPSocket;<br>方法or属性：getState(): Promise\<SocketStateBase>;<br>旧版本信息：|类名：UDPSocket;<br>方法or属性：getState(): Promise\<SocketStateBase>;<br>新版本信息：ohos.permission.INTERNET|@ohos.net.socket.d.ts|
|权限有变化|类名：TCPSocket;<br>方法or属性：getState(): Promise\<SocketStateBase>;<br>旧版本信息：|类名：TCPSocket;<br>方法or属性：getState(): Promise\<SocketStateBase>;<br>新版本信息：ohos.permission.INTERNET|@ohos.net.socket.d.ts|
|权限有变化|类名：UDPSocket;<br>方法or属性：setExtraOptions(options: UDPExtraOptions): Promise\<void>;<br>旧版本信息：|类名：UDPSocket;<br>方法or属性：setExtraOptions(options: UDPExtraOptions): Promise\<void>;<br>新版本信息：ohos.permission.INTERNET|@ohos.net.socket.d.ts|
|权限有变化|类名：TCPSocket;<br>方法or属性：connect(options: TCPConnectOptions): Promise\<void>;<br>旧版本信息：|类名：TCPSocket;<br>方法or属性：connect(options: TCPConnectOptions): Promise\<void>;<br>新版本信息：ohos.permission.INTERNET|@ohos.net.socket.d.ts|
|权限有变化|类名：TCPSocket;<br>方法or属性：send(options: TCPSendOptions): Promise\<void>;<br>旧版本信息：|类名：TCPSocket;<br>方法or属性：send(options: TCPSendOptions): Promise\<void>;<br>新版本信息：ohos.permission.INTERNET|@ohos.net.socket.d.ts|
|权限有变化|类名：TCPSocket;<br>方法or属性：getRemoteAddress(): Promise\<NetAddress>;<br>旧版本信息：|类名：TCPSocket;<br>方法or属性：getRemoteAddress(): Promise\<NetAddress>;<br>新版本信息：ohos.permission.INTERNET|@ohos.net.socket.d.ts|
|权限有变化|类名：TCPSocket;<br>方法or属性：setExtraOptions(options: TCPExtraOptions): Promise\<void>;<br>旧版本信息：|类名：TCPSocket;<br>方法or属性：setExtraOptions(options: TCPExtraOptions): Promise\<void>;<br>新版本信息：ohos.permission.INTERNET|@ohos.net.socket.d.ts|
|权限有变化|类名：WebSocket;<br>方法or属性：connect(url: string, options: WebSocketRequestOptions, callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：WebSocket;<br>方法or属性：connect(url: string, options: WebSocketRequestOptions, callback: AsyncCallback\<boolean>): void;<br>新版本信息：ohos.permission.INTERNET|@ohos.net.webSocket.d.ts|
|权限有变化|类名：WebSocket;<br>方法or属性：connect(url: string, options?: WebSocketRequestOptions): Promise\<boolean>;<br>旧版本信息：|类名：WebSocket;<br>方法or属性：connect(url: string, options?: WebSocketRequestOptions): Promise\<boolean>;<br>新版本信息：ohos.permission.INTERNET|@ohos.net.webSocket.d.ts|
|权限有变化|类名：WebSocket;<br>方法or属性：send(data: string \| ArrayBuffer): Promise\<boolean>;<br>旧版本信息：|类名：WebSocket;<br>方法or属性：send(data: string \| ArrayBuffer): Promise\<boolean>;<br>新版本信息：ohos.permission.INTERNET|@ohos.net.webSocket.d.ts|
|权限有变化|类名：WebSocket;<br>方法or属性：close(options: WebSocketCloseOptions, callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：WebSocket;<br>方法or属性：close(options: WebSocketCloseOptions, callback: AsyncCallback\<boolean>): void;<br>新版本信息：ohos.permission.INTERNET|@ohos.net.webSocket.d.ts|
|权限有变化|类名：WebSocket;<br>方法or属性：close(options?: WebSocketCloseOptions): Promise\<boolean>;<br>旧版本信息：|类名：WebSocket;<br>方法or属性：close(options?: WebSocketCloseOptions): Promise\<boolean>;<br>新版本信息：ohos.permission.INTERNET|@ohos.net.webSocket.d.ts|
|权限有变化|类名：wifiManager;<br>方法or属性：function addDeviceConfig(config: WifiDeviceConfig, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：wifiManager;<br>方法or属性：function addDeviceConfig(config: WifiDeviceConfig, callback: AsyncCallback\<number>): void;<br>新版本信息：ohos.permission.SET_WIFI_INFO,ohos.permission.SET_WIFI_CONFIG|@ohos.wifiManager.d.ts|
|权限有变化|类名：wifiManager;<br>方法or属性：function addCandidateConfig(config: WifiDeviceConfig, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：wifiManager;<br>方法or属性：function addCandidateConfig(config: WifiDeviceConfig, callback: AsyncCallback\<number>): void;<br>新版本信息：ohos.permission.SET_WIFI_INFO|@ohos.wifiManager.d.ts|
|权限有变化|类名：wifiManager;<br>方法or属性：function removeCandidateConfig(networkId: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：wifiManager;<br>方法or属性：function removeCandidateConfig(networkId: number, callback: AsyncCallback\<void>): void;<br>新版本信息：ohos.permission.SET_WIFI_INFO|@ohos.wifiManager.d.ts|
|权限有变化|类名：wifiManager;<br>方法or属性：function getLinkedInfo(callback: AsyncCallback\<WifiLinkedInfo>): void;<br>旧版本信息：|类名：wifiManager;<br>方法or属性：function getLinkedInfo(callback: AsyncCallback\<WifiLinkedInfo>): void;<br>新版本信息：ohos.permission.GET_WIFI_INFO|@ohos.wifiManager.d.ts|
|权限有变化|类名：wifiManager;<br>方法or属性：function getP2pLinkedInfo(callback: AsyncCallback\<WifiP2pLinkedInfo>): void;<br>旧版本信息：|类名：wifiManager;<br>方法or属性：function getP2pLinkedInfo(callback: AsyncCallback\<WifiP2pLinkedInfo>): void;<br>新版本信息：ohos.permission.GET_WIFI_INFO|@ohos.wifiManager.d.ts|
|权限有变化|类名：wifiManager;<br>方法or属性：function getCurrentP2pGroup(callback: AsyncCallback\<WifiP2pGroupInfo>): void;<br>旧版本信息：|类名：wifiManager;<br>方法or属性：function getCurrentP2pGroup(callback: AsyncCallback\<WifiP2pGroupInfo>): void;<br>新版本信息：ohos.permission.GET_WIFI_INFO,ohos.permission.LOCATION,ohos.permission.APPROXIMATELY_LOCATION|@ohos.wifiManager.d.ts|
|权限有变化|类名：wifiManager;<br>方法or属性：function getP2pPeerDevices(callback: AsyncCallback\<WifiP2pDevice[]>): void;<br>旧版本信息：|类名：wifiManager;<br>方法or属性：function getP2pPeerDevices(callback: AsyncCallback\<WifiP2pDevice[]>): void;<br>新版本信息：ohos.permission.GET_WIFI_INFO,ohos.permission.LOCATION,ohos.permission.APPROXIMATELY_LOCATION|@ohos.wifiManager.d.ts|
|权限有变化|类名：wifiManager;<br>方法or属性：function getP2pLocalDevice(callback: AsyncCallback\<WifiP2pDevice>): void;<br>旧版本信息：|类名：wifiManager;<br>方法or属性：function getP2pLocalDevice(callback: AsyncCallback\<WifiP2pDevice>): void;<br>新版本信息：ohos.permission.GET_WIFI_INFO,ohos.permission.GET_WIFI_CONFIG|@ohos.wifiManager.d.ts|
|权限有变化|类名：wifiManager;<br>方法or属性：function getP2pGroups(callback: AsyncCallback\<Array\<WifiP2pGroupInfo>>): void;<br>旧版本信息：|类名：wifiManager;<br>方法or属性：function getP2pGroups(callback: AsyncCallback\<Array\<WifiP2pGroupInfo>>): void;<br>新版本信息：ohos.permission.GET_WIFI_INFO,ohos.permission.LOCATION,ohos.permission.APPROXIMATELY_LOCATION|@ohos.wifiManager.d.ts|
|type有变化|类名：NetSpecifier;<br>方法or属性：netCapabilities: NetCapabilities;<br>旧版本信息：|类名：NetSpecifier;<br>方法or属性：netCapabilities: NetCapabilities;<br>新版本信息：NetCapabilities|@ohos.net.connection.d.ts|
|type有变化|类名：NetSpecifier;<br>方法or属性：bearerPrivateIdentifier?: string;<br>旧版本信息：|类名：NetSpecifier;<br>方法or属性：bearerPrivateIdentifier?: string;<br>新版本信息：?string|@ohos.net.connection.d.ts|
|type有变化|类名：NetHandle;<br>方法or属性：netId: number;<br>旧版本信息：|类名：NetHandle;<br>方法or属性：netId: number;<br>新版本信息：number|@ohos.net.connection.d.ts|
|type有变化|类名：NetCapabilities;<br>方法or属性：linkUpBandwidthKbps?: number;<br>旧版本信息：|类名：NetCapabilities;<br>方法or属性：linkUpBandwidthKbps?: number;<br>新版本信息：?number|@ohos.net.connection.d.ts|
|type有变化|类名：NetCapabilities;<br>方法or属性：linkDownBandwidthKbps?: number;<br>旧版本信息：|类名：NetCapabilities;<br>方法or属性：linkDownBandwidthKbps?: number;<br>新版本信息：?number|@ohos.net.connection.d.ts|
|type有变化|类名：NetCapabilities;<br>方法or属性：networkCap?: Array\<NetCap>;<br>旧版本信息：|类名：NetCapabilities;<br>方法or属性：networkCap?: Array\<NetCap>;<br>新版本信息：?Array\<NetCap>|@ohos.net.connection.d.ts|
|type有变化|类名：NetCapabilities;<br>方法or属性：bearerTypes: Array\<NetBearType>;<br>旧版本信息：|类名：NetCapabilities;<br>方法or属性：bearerTypes: Array\<NetBearType>;<br>新版本信息：Array\<NetBearType>|@ohos.net.connection.d.ts|
|type有变化|类名：ConnectionProperties;<br>方法or属性：interfaceName: string;<br>旧版本信息：|类名：ConnectionProperties;<br>方法or属性：interfaceName: string;<br>新版本信息：string|@ohos.net.connection.d.ts|
|type有变化|类名：ConnectionProperties;<br>方法or属性：domains: string;<br>旧版本信息：|类名：ConnectionProperties;<br>方法or属性：domains: string;<br>新版本信息：string|@ohos.net.connection.d.ts|
|type有变化|类名：ConnectionProperties;<br>方法or属性：linkAddresses: Array\<LinkAddress>;<br>旧版本信息：|类名：ConnectionProperties;<br>方法or属性：linkAddresses: Array\<LinkAddress>;<br>新版本信息：Array\<LinkAddress>|@ohos.net.connection.d.ts|
|type有变化|类名：ConnectionProperties;<br>方法or属性：dnses: Array\<NetAddress>;<br>旧版本信息：|类名：ConnectionProperties;<br>方法or属性：dnses: Array\<NetAddress>;<br>新版本信息：Array\<NetAddress>|@ohos.net.connection.d.ts|
|type有变化|类名：ConnectionProperties;<br>方法or属性：routes: Array\<RouteInfo>;<br>旧版本信息：|类名：ConnectionProperties;<br>方法or属性：routes: Array\<RouteInfo>;<br>新版本信息：Array\<RouteInfo>|@ohos.net.connection.d.ts|
|type有变化|类名：ConnectionProperties;<br>方法or属性：mtu: number;<br>旧版本信息：|类名：ConnectionProperties;<br>方法or属性：mtu: number;<br>新版本信息：number|@ohos.net.connection.d.ts|
|type有变化|类名：RouteInfo;<br>方法or属性：interface: string;<br>旧版本信息：|类名：RouteInfo;<br>方法or属性：interface: string;<br>新版本信息：string|@ohos.net.connection.d.ts|
|type有变化|类名：RouteInfo;<br>方法or属性：destination: LinkAddress;<br>旧版本信息：|类名：RouteInfo;<br>方法or属性：destination: LinkAddress;<br>新版本信息：LinkAddress|@ohos.net.connection.d.ts|
|type有变化|类名：RouteInfo;<br>方法or属性：gateway: NetAddress;<br>旧版本信息：|类名：RouteInfo;<br>方法or属性：gateway: NetAddress;<br>新版本信息：NetAddress|@ohos.net.connection.d.ts|
|type有变化|类名：RouteInfo;<br>方法or属性：hasGateway: boolean;<br>旧版本信息：|类名：RouteInfo;<br>方法or属性：hasGateway: boolean;<br>新版本信息：boolean|@ohos.net.connection.d.ts|
|type有变化|类名：RouteInfo;<br>方法or属性：isDefaultRoute: boolean;<br>旧版本信息：|类名：RouteInfo;<br>方法or属性：isDefaultRoute: boolean;<br>新版本信息：boolean|@ohos.net.connection.d.ts|
|type有变化|类名：LinkAddress;<br>方法or属性：address: NetAddress;<br>旧版本信息：|类名：LinkAddress;<br>方法or属性：address: NetAddress;<br>新版本信息：NetAddress|@ohos.net.connection.d.ts|
|type有变化|类名：LinkAddress;<br>方法or属性：prefixLength: number;<br>旧版本信息：|类名：LinkAddress;<br>方法or属性：prefixLength: number;<br>新版本信息：number|@ohos.net.connection.d.ts|
|type有变化|类名：NetAddress;<br>方法or属性：address: string;<br>旧版本信息：|类名：NetAddress;<br>方法or属性：address: string;<br>新版本信息：string|@ohos.net.connection.d.ts|
|type有变化|类名：NetAddress;<br>方法or属性：family?: number;<br>旧版本信息：|类名：NetAddress;<br>方法or属性：family?: number;<br>新版本信息：?number|@ohos.net.connection.d.ts|
|type有变化|类名：NetAddress;<br>方法or属性：port?: number;<br>旧版本信息：|类名：NetAddress;<br>方法or属性：port?: number;<br>新版本信息：?number|@ohos.net.connection.d.ts|
|type有变化|类名：HttpProxy;<br>方法or属性：host: string;<br>旧版本信息：|类名：HttpProxy;<br>方法or属性：host: string;<br>新版本信息：string|@ohos.net.connection.d.ts|
|type有变化|类名：HttpProxy;<br>方法or属性：port: number;<br>旧版本信息：|类名：HttpProxy;<br>方法or属性：port: number;<br>新版本信息：number|@ohos.net.connection.d.ts|
|type有变化|类名：HttpProxy;<br>方法or属性：exclusionList: Array\<string>;<br>旧版本信息：|类名：HttpProxy;<br>方法or属性：exclusionList: Array\<string>;<br>新版本信息：Array\<string>|@ohos.net.connection.d.ts|
|type有变化|类名：InterfaceConfiguration;<br>方法or属性：mode: IPSetMode;<br>旧版本信息：|类名：InterfaceConfiguration;<br>方法or属性：mode: IPSetMode;<br>新版本信息：IPSetMode|@ohos.net.ethernet.d.ts|
|type有变化|类名：InterfaceConfiguration;<br>方法or属性：ipAddr: string;<br>旧版本信息：|类名：InterfaceConfiguration;<br>方法or属性：ipAddr: string;<br>新版本信息：string|@ohos.net.ethernet.d.ts|
|type有变化|类名：InterfaceConfiguration;<br>方法or属性：route: string;<br>旧版本信息：|类名：InterfaceConfiguration;<br>方法or属性：route: string;<br>新版本信息：string|@ohos.net.ethernet.d.ts|
|type有变化|类名：InterfaceConfiguration;<br>方法or属性：gateway: string;<br>旧版本信息：|类名：InterfaceConfiguration;<br>方法or属性：gateway: string;<br>新版本信息：string|@ohos.net.ethernet.d.ts|
|type有变化|类名：InterfaceConfiguration;<br>方法or属性：netMask: string;<br>旧版本信息：|类名：InterfaceConfiguration;<br>方法or属性：netMask: string;<br>新版本信息：string|@ohos.net.ethernet.d.ts|
|type有变化|类名：InterfaceConfiguration;<br>方法or属性：dnsServers: string;<br>旧版本信息：|类名：InterfaceConfiguration;<br>方法or属性：dnsServers: string;<br>新版本信息：string|@ohos.net.ethernet.d.ts|
|type有变化|类名：HttpRequestOptions;<br>方法or属性：method?: RequestMethod;<br>旧版本信息：|类名：HttpRequestOptions;<br>方法or属性：method?: RequestMethod;<br>新版本信息：?RequestMethod|@ohos.net.http.d.ts|
|type有变化|类名：HttpRequestOptions;<br>方法or属性：extraData?: string \| Object \| ArrayBuffer;<br>旧版本信息：|类名：HttpRequestOptions;<br>方法or属性：extraData?: string \| Object \| ArrayBuffer;<br>新版本信息：?string \| Object \| ArrayBuffer|@ohos.net.http.d.ts|
|type有变化|类名：HttpRequestOptions;<br>方法or属性：expectDataType?: HttpDataType;<br>旧版本信息：|类名：HttpRequestOptions;<br>方法or属性：expectDataType?: HttpDataType;<br>新版本信息：?HttpDataType|@ohos.net.http.d.ts|
|type有变化|类名：HttpRequestOptions;<br>方法or属性：usingCache?: boolean;<br>旧版本信息：|类名：HttpRequestOptions;<br>方法or属性：usingCache?: boolean;<br>新版本信息：?boolean|@ohos.net.http.d.ts|
|type有变化|类名：HttpRequestOptions;<br>方法or属性：priority?: number;<br>旧版本信息：|类名：HttpRequestOptions;<br>方法or属性：priority?: number;<br>新版本信息：?number|@ohos.net.http.d.ts|
|type有变化|类名：HttpRequestOptions;<br>方法or属性：header?: Object;<br>旧版本信息：|类名：HttpRequestOptions;<br>方法or属性：header?: Object;<br>新版本信息：?Object|@ohos.net.http.d.ts|
|type有变化|类名：HttpRequestOptions;<br>方法or属性：readTimeout?: number;<br>旧版本信息：|类名：HttpRequestOptions;<br>方法or属性：readTimeout?: number;<br>新版本信息：?number|@ohos.net.http.d.ts|
|type有变化|类名：HttpRequestOptions;<br>方法or属性：connectTimeout?: number;<br>旧版本信息：|类名：HttpRequestOptions;<br>方法or属性：connectTimeout?: number;<br>新版本信息：?number|@ohos.net.http.d.ts|
|type有变化|类名：HttpRequestOptions;<br>方法or属性：usingProtocol?: HttpProtocol;<br>旧版本信息：|类名：HttpRequestOptions;<br>方法or属性：usingProtocol?: HttpProtocol;<br>新版本信息：?HttpProtocol|@ohos.net.http.d.ts|
|type有变化|类名：HttpRequestOptions;<br>方法or属性：usingProxy?: boolean \| HttpProxy;<br>旧版本信息：|类名：HttpRequestOptions;<br>方法or属性：usingProxy?: boolean \| HttpProxy;<br>新版本信息：?boolean \| HttpProxy|@ohos.net.http.d.ts|
|type有变化|类名：HttpRequestOptions;<br>方法or属性：caPath?: string;<br>旧版本信息：|类名：HttpRequestOptions;<br>方法or属性：caPath?: string;<br>新版本信息：?string|@ohos.net.http.d.ts|
|type有变化|类名：HttpResponse;<br>方法or属性：result: string \| Object \| ArrayBuffer;<br>旧版本信息：|类名：HttpResponse;<br>方法or属性：result: string \| Object \| ArrayBuffer;<br>新版本信息：string \| Object \| ArrayBuffer|@ohos.net.http.d.ts|
|type有变化|类名：HttpResponse;<br>方法or属性：resultType: HttpDataType;<br>旧版本信息：|类名：HttpResponse;<br>方法or属性：resultType: HttpDataType;<br>新版本信息：HttpDataType|@ohos.net.http.d.ts|
|type有变化|类名：HttpResponse;<br>方法or属性：responseCode: ResponseCode \| number;<br>旧版本信息：|类名：HttpResponse;<br>方法or属性：responseCode: ResponseCode \| number;<br>新版本信息：ResponseCode \| number|@ohos.net.http.d.ts|
|type有变化|类名：HttpResponse;<br>方法or属性：header: Object;<br>旧版本信息：|类名：HttpResponse;<br>方法or属性：header: Object;<br>新版本信息：Object|@ohos.net.http.d.ts|
|type有变化|类名：HttpResponse;<br>方法or属性：cookies: string;<br>旧版本信息：|类名：HttpResponse;<br>方法or属性：cookies: string;<br>新版本信息：string|@ohos.net.http.d.ts|
|type有变化|类名：LocalServiceInfo;<br>方法or属性：serviceType: string;<br>旧版本信息：|类名：LocalServiceInfo;<br>方法or属性：serviceType: string;<br>新版本信息：string|@ohos.net.mdns.d.ts|
|type有变化|类名：LocalServiceInfo;<br>方法or属性：serviceName: string;<br>旧版本信息：|类名：LocalServiceInfo;<br>方法or属性：serviceName: string;<br>新版本信息：string|@ohos.net.mdns.d.ts|
|type有变化|类名：LocalServiceInfo;<br>方法or属性：port?: number;<br>旧版本信息：|类名：LocalServiceInfo;<br>方法or属性：port?: number;<br>新版本信息：?number|@ohos.net.mdns.d.ts|
|type有变化|类名：LocalServiceInfo;<br>方法or属性：host?: NetAddress;<br>旧版本信息：|类名：LocalServiceInfo;<br>方法or属性：host?: NetAddress;<br>新版本信息：?NetAddress|@ohos.net.mdns.d.ts|
|type有变化|类名：LocalServiceInfo;<br>方法or属性：serviceAttribute?: Array\<ServiceAttribute>;<br>旧版本信息：|类名：LocalServiceInfo;<br>方法or属性：serviceAttribute?: Array\<ServiceAttribute>;<br>新版本信息：?Array\<ServiceAttribute>|@ohos.net.mdns.d.ts|
|type有变化|类名：ServiceAttribute;<br>方法or属性：key: string;<br>旧版本信息：|类名：ServiceAttribute;<br>方法or属性：key: string;<br>新版本信息：string|@ohos.net.mdns.d.ts|
|type有变化|类名：ServiceAttribute;<br>方法or属性：value: Array\<number>;<br>旧版本信息：|类名：ServiceAttribute;<br>方法or属性：value: Array\<number>;<br>新版本信息：Array\<number>|@ohos.net.mdns.d.ts|
|type有变化|类名：UDPSendOptions;<br>方法or属性：data: string \| ArrayBuffer;<br>旧版本信息：|类名：UDPSendOptions;<br>方法or属性：data: string \| ArrayBuffer;<br>新版本信息：string \| ArrayBuffer|@ohos.net.socket.d.ts|
|type有变化|类名：TCPSendOptions;<br>方法or属性：data: string \| ArrayBuffer;<br>旧版本信息：|类名：TCPSendOptions;<br>方法or属性：data: string \| ArrayBuffer;<br>新版本信息：string \| ArrayBuffer|@ohos.net.socket.d.ts|
|type有变化|类名：UDPSendOptions;<br>方法or属性：address: NetAddress;<br>旧版本信息：|类名：UDPSendOptions;<br>方法or属性：address: NetAddress;<br>新版本信息：NetAddress|@ohos.net.socket.d.ts|
|type有变化|类名：TCPConnectOptions;<br>方法or属性：address: NetAddress;<br>旧版本信息：|类名：TCPConnectOptions;<br>方法or属性：address: NetAddress;<br>新版本信息：NetAddress|@ohos.net.socket.d.ts|
|type有变化|类名：TLSConnectOptions;<br>方法or属性：address: NetAddress;<br>旧版本信息：|类名：TLSConnectOptions;<br>方法or属性：address: NetAddress;<br>新版本信息：NetAddress|@ohos.net.socket.d.ts|
|type有变化|类名：ExtraOptionsBase;<br>方法or属性：receiveBufferSize?: number;<br>旧版本信息：|类名：ExtraOptionsBase;<br>方法or属性：receiveBufferSize?: number;<br>新版本信息：?number|@ohos.net.socket.d.ts|
|type有变化|类名：ExtraOptionsBase;<br>方法or属性：sendBufferSize?: number;<br>旧版本信息：|类名：ExtraOptionsBase;<br>方法or属性：sendBufferSize?: number;<br>新版本信息：?number|@ohos.net.socket.d.ts|
|type有变化|类名：ExtraOptionsBase;<br>方法or属性：reuseAddress?: boolean;<br>旧版本信息：|类名：ExtraOptionsBase;<br>方法or属性：reuseAddress?: boolean;<br>新版本信息：?boolean|@ohos.net.socket.d.ts|
|type有变化|类名：ExtraOptionsBase;<br>方法or属性：socketTimeout?: number;<br>旧版本信息：|类名：ExtraOptionsBase;<br>方法or属性：socketTimeout?: number;<br>新版本信息：?number|@ohos.net.socket.d.ts|
|type有变化|类名：UDPExtraOptions;<br>方法or属性：broadcast?: boolean;<br>旧版本信息：|类名：UDPExtraOptions;<br>方法or属性：broadcast?: boolean;<br>新版本信息：?boolean|@ohos.net.socket.d.ts|
|type有变化|类名：SocketStateBase;<br>方法or属性：isBound: boolean;<br>旧版本信息：|类名：SocketStateBase;<br>方法or属性：isBound: boolean;<br>新版本信息：boolean|@ohos.net.socket.d.ts|
|type有变化|类名：SocketStateBase;<br>方法or属性：isClose: boolean;<br>旧版本信息：|类名：SocketStateBase;<br>方法or属性：isClose: boolean;<br>新版本信息：boolean|@ohos.net.socket.d.ts|
|type有变化|类名：SocketStateBase;<br>方法or属性：isConnected: boolean;<br>旧版本信息：|类名：SocketStateBase;<br>方法or属性：isConnected: boolean;<br>新版本信息：boolean|@ohos.net.socket.d.ts|
|type有变化|类名：SocketRemoteInfo;<br>方法or属性：address: string;<br>旧版本信息：|类名：SocketRemoteInfo;<br>方法or属性：address: string;<br>新版本信息：string|@ohos.net.socket.d.ts|
|type有变化|类名：SocketRemoteInfo;<br>方法or属性：family: 'IPv4' \| 'IPv6';<br>旧版本信息：|类名：SocketRemoteInfo;<br>方法or属性：family: 'IPv4' \| 'IPv6';<br>新版本信息：'IPv4' \| 'IPv6'|@ohos.net.socket.d.ts|
|type有变化|类名：SocketRemoteInfo;<br>方法or属性：port: number;<br>旧版本信息：|类名：SocketRemoteInfo;<br>方法or属性：port: number;<br>新版本信息：number|@ohos.net.socket.d.ts|
|type有变化|类名：SocketRemoteInfo;<br>方法or属性：size: number;<br>旧版本信息：|类名：SocketRemoteInfo;<br>方法or属性：size: number;<br>新版本信息：number|@ohos.net.socket.d.ts|
|type有变化|类名：TCPConnectOptions;<br>方法or属性：timeout?: number;<br>旧版本信息：|类名：TCPConnectOptions;<br>方法or属性：timeout?: number;<br>新版本信息：?number|@ohos.net.socket.d.ts|
|type有变化|类名：TCPSendOptions;<br>方法or属性：encoding?: string;<br>旧版本信息：|类名：TCPSendOptions;<br>方法or属性：encoding?: string;<br>新版本信息：?string|@ohos.net.socket.d.ts|
|type有变化|类名：TCPExtraOptions;<br>方法or属性：keepAlive?: boolean;<br>旧版本信息：|类名：TCPExtraOptions;<br>方法or属性：keepAlive?: boolean;<br>新版本信息：?boolean|@ohos.net.socket.d.ts|
|type有变化|类名：TCPExtraOptions;<br>方法or属性：OOBInline?: boolean;<br>旧版本信息：|类名：TCPExtraOptions;<br>方法or属性：OOBInline?: boolean;<br>新版本信息：?boolean|@ohos.net.socket.d.ts|
|type有变化|类名：TCPExtraOptions;<br>方法or属性：TCPNoDelay?: boolean;<br>旧版本信息：|类名：TCPExtraOptions;<br>方法or属性：TCPNoDelay?: boolean;<br>新版本信息：?boolean|@ohos.net.socket.d.ts|
|type有变化|类名：TCPExtraOptions;<br>方法or属性：socketLinger?: { on: boolean, linger: number };<br>旧版本信息：|类名：TCPExtraOptions;<br>方法or属性：socketLinger?: { on: boolean, linger: number };<br>新版本信息：?object|@ohos.net.socket.d.ts|
|type有变化|类名：TLSSecureOptions;<br>方法or属性：ca: string \| Array\<string>;<br>旧版本信息：|类名：TLSSecureOptions;<br>方法or属性：ca: string \| Array\<string>;<br>新版本信息：string \| Array\<string>|@ohos.net.socket.d.ts|
|type有变化|类名：TLSSecureOptions;<br>方法or属性：cert?: string;<br>旧版本信息：|类名：TLSSecureOptions;<br>方法or属性：cert?: string;<br>新版本信息：?string|@ohos.net.socket.d.ts|
|type有变化|类名：TLSSecureOptions;<br>方法or属性：key?: string;<br>旧版本信息：|类名：TLSSecureOptions;<br>方法or属性：key?: string;<br>新版本信息：?string|@ohos.net.socket.d.ts|
|type有变化|类名：TLSSecureOptions;<br>方法or属性：password?: string;<br>旧版本信息：|类名：TLSSecureOptions;<br>方法or属性：password?: string;<br>新版本信息：?string|@ohos.net.socket.d.ts|
|type有变化|类名：TLSSecureOptions;<br>方法or属性：protocols?: Protocol \| Array\<Protocol>;<br>旧版本信息：|类名：TLSSecureOptions;<br>方法or属性：protocols?: Protocol \| Array\<Protocol>;<br>新版本信息：?Protocol \| Array\<Protocol>|@ohos.net.socket.d.ts|
|type有变化|类名：TLSSecureOptions;<br>方法or属性：useRemoteCipherPrefer?: boolean;<br>旧版本信息：|类名：TLSSecureOptions;<br>方法or属性：useRemoteCipherPrefer?: boolean;<br>新版本信息：?boolean|@ohos.net.socket.d.ts|
|type有变化|类名：TLSSecureOptions;<br>方法or属性：signatureAlgorithms?: string;<br>旧版本信息：|类名：TLSSecureOptions;<br>方法or属性：signatureAlgorithms?: string;<br>新版本信息：?string|@ohos.net.socket.d.ts|
|type有变化|类名：TLSSecureOptions;<br>方法or属性：cipherSuite?: string;<br>旧版本信息：|类名：TLSSecureOptions;<br>方法or属性：cipherSuite?: string;<br>新版本信息：?string|@ohos.net.socket.d.ts|
|type有变化|类名：TLSConnectOptions;<br>方法or属性：secureOptions: TLSSecureOptions;<br>旧版本信息：|类名：TLSConnectOptions;<br>方法or属性：secureOptions: TLSSecureOptions;<br>新版本信息：TLSSecureOptions|@ohos.net.socket.d.ts|
|type有变化|类名：TLSConnectOptions;<br>方法or属性：ALPNProtocols?: Array\<string>;<br>旧版本信息：|类名：TLSConnectOptions;<br>方法or属性：ALPNProtocols?: Array\<string>;<br>新版本信息：?Array\<string>|@ohos.net.socket.d.ts|
|type有变化|类名：WebSocketRequestOptions;<br>方法or属性：header?: Object;<br>旧版本信息：|类名：WebSocketRequestOptions;<br>方法or属性：header?: Object;<br>新版本信息：?Object|@ohos.net.webSocket.d.ts|
|type有变化|类名：WebSocketCloseOptions;<br>方法or属性：code?: number;<br>旧版本信息：|类名：WebSocketCloseOptions;<br>方法or属性：code?: number;<br>新版本信息：?number|@ohos.net.webSocket.d.ts|
|type有变化|类名：WebSocketCloseOptions;<br>方法or属性：reason?: string;<br>旧版本信息：|类名：WebSocketCloseOptions;<br>方法or属性：reason?: string;<br>新版本信息：?string|@ohos.net.webSocket.d.ts|
|type有变化|类名：WifiEapConfig;<br>方法or属性：caCertAliases: string;<br>旧版本信息：|类名：WifiEapConfig;<br>方法or属性：caCertAliases: string;<br>新版本信息：string|@ohos.wifiManager.d.ts|
|type有变化|类名：WifiEapConfig;<br>方法or属性：clientCertAliases: string;<br>旧版本信息：|类名：WifiEapConfig;<br>方法or属性：clientCertAliases: string;<br>新版本信息：string|@ohos.wifiManager.d.ts|
|type有变化|类名：WifiEapConfig;<br>方法or属性：eapSubId: number;<br>旧版本信息：|类名：WifiEapConfig;<br>方法or属性：eapSubId: number;<br>新版本信息：number|@ohos.wifiManager.d.ts|
|type有变化|类名：WifiDeviceConfig;<br>方法or属性：eapConfig?: WifiEapConfig;<br>旧版本信息：|类名：WifiDeviceConfig;<br>方法or属性：eapConfig?: WifiEapConfig;<br>新版本信息：?WifiEapConfig|@ohos.wifiManager.d.ts|
|type有变化|类名：NetworkResponse;<br>方法or属性：type: string;<br>旧版本信息：|类名：NetworkResponse;<br>方法or属性：type: string;<br>新版本信息：string|@system.network.d.ts|
|type有变化|类名：NetworkResponse;<br>方法or属性：metered: boolean;<br>旧版本信息：|类名：NetworkResponse;<br>方法or属性：metered: boolean;<br>新版本信息：boolean|@system.network.d.ts|
|函数有变化|类名：HotspotConfig;<br>方法or属性：channel: number;|类名：HotspotConfig;<br>方法or属性：channel?: number;|@ohos.wifiManager.d.ts|
