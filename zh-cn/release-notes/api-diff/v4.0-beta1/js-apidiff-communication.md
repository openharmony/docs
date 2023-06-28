| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|模块名: ohos.bluetoothManager<br>类名: bluetoothManager<br>方法 or 属性: function setDevicePinCode(device: string, code: string, callback: AsyncCallback\<void>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: bluetoothManager<br>方法 or 属性: function setDevicePinCode(device: string, code: string): Promise\<void>;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: BLECharacteristic<br>方法 or 属性: properties?: GattProperties;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: ScanResult<br>方法 or 属性: deviceName: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: PinRequiredParam<br>方法 or 属性: pinType: PinType;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: GattProperties|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: GattProperties<br>方法 or 属性: write?: boolean;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: GattProperties<br>方法 or 属性: writeNoResponse?: boolean;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: GattProperties<br>方法 or 属性: read?: boolean;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: GattProperties<br>方法 or 属性: notify?: boolean;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: GattProperties<br>方法 or 属性: indicate?: boolean;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: PinType|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: PinType<br>方法 or 属性: PIN_TYPE_ENTER_PIN_CODE = 0|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: PinType<br>方法 or 属性: PIN_TYPE_ENTER_PASSKEY = 1|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: PinType<br>方法 or 属性: PIN_TYPE_CONFIRM_PASSKEY = 2|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: PinType<br>方法 or 属性: PIN_TYPE_NO_PASSKEY_CONSENT = 3|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: PinType<br>方法 or 属性: PIN_TYPE_NOTIFY_PASSKEY = 4|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: PinType<br>方法 or 属性: PIN_TYPE_DISPLAY_PIN_CODE = 5|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: PinType<br>方法 or 属性: PIN_TYPE_OOB_CONSENT = 6|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: PinType<br>方法 or 属性: PIN_TYPE_PIN_16_DIGITS = 7|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.net.connection<br>类名: connection<br>方法 or 属性: function getGlobalHttpProxy(callback: AsyncCallback\<HttpProxy>): void;|@ohos.net.connection.d.ts|
|新增|NA|模块名: ohos.net.connection<br>类名: connection<br>方法 or 属性: function getGlobalHttpProxy(): Promise\<HttpProxy>;|@ohos.net.connection.d.ts|
|新增|NA|模块名: ohos.net.connection<br>类名: connection<br>方法 or 属性: function setGlobalHttpProxy(httpProxy: HttpProxy, callback: AsyncCallback\<void>): void;|@ohos.net.connection.d.ts|
|新增|NA|模块名: ohos.net.connection<br>类名: connection<br>方法 or 属性: function setGlobalHttpProxy(httpProxy: HttpProxy): Promise\<void>;|@ohos.net.connection.d.ts|
|新增|NA|模块名: ohos.net.connection<br>类名: HttpProxy|@ohos.net.connection.d.ts|
|新增|NA|模块名: ohos.net.connection<br>类名: HttpProxy<br>方法 or 属性: host: string;|@ohos.net.connection.d.ts|
|新增|NA|模块名: ohos.net.connection<br>类名: HttpProxy<br>方法 or 属性: port: number;|@ohos.net.connection.d.ts|
|新增|NA|模块名: ohos.net.connection<br>类名: HttpProxy<br>方法 or 属性: exclusionList: Array\<string>;|@ohos.net.connection.d.ts|
|新增|NA|模块名: ohos.net.ethernet<br>类名: ethernet<br>方法 or 属性: function on(type: 'interfaceStateChange', callback: Callback\<{ iface: string, active: boolean }>): void;|@ohos.net.ethernet.d.ts|
|新增|NA|模块名: ohos.net.ethernet<br>类名: ethernet<br>方法 or 属性: function off(type: 'interfaceStateChange', callback?: Callback\<{ iface: string, active: boolean }>): void;|@ohos.net.ethernet.d.ts|
|新增|NA|模块名: ohos.net.http<br>类名: HttpRequestOptions<br>方法 or 属性: usingProxy?: boolean \| HttpProxy;|@ohos.net.http.d.ts|
|新增|NA|模块名: ohos.net.http<br>类名: HttpRequestOptions<br>方法 or 属性: caPath?: string;|@ohos.net.http.d.ts|
|新增|NA|模块名: ohos.net.http<br>类名: HttpRequest<br>方法 or 属性: request2(url: string, callback: AsyncCallback\<number>): void;|@ohos.net.http.d.ts|
|新增|NA|模块名: ohos.net.http<br>类名: HttpRequest<br>方法 or 属性: request2(url: string, options: HttpRequestOptions, callback: AsyncCallback\<number>): void;|@ohos.net.http.d.ts|
|新增|NA|模块名: ohos.net.http<br>类名: HttpRequest<br>方法 or 属性: request2(url: string, options?: HttpRequestOptions): Promise\<number>;|@ohos.net.http.d.ts|
|新增|NA|模块名: ohos.net.http<br>类名: HttpRequest<br>方法 or 属性: on(type: "dataReceive", callback: Callback\<ArrayBuffer>): void;|@ohos.net.http.d.ts|
|新增|NA|模块名: ohos.net.http<br>类名: HttpRequest<br>方法 or 属性: off(type: "dataReceive", callback?: Callback\<ArrayBuffer>): void;|@ohos.net.http.d.ts|
|新增|NA|模块名: ohos.net.http<br>类名: HttpRequest<br>方法 or 属性: on(type: "dataEnd", callback: Callback\<void>): void;|@ohos.net.http.d.ts|
|新增|NA|模块名: ohos.net.http<br>类名: HttpRequest<br>方法 or 属性: off(type: "dataEnd", callback?: Callback\<void>): void;|@ohos.net.http.d.ts|
|新增|NA|模块名: ohos.net.http<br>类名: HttpRequest<br>方法 or 属性: on(type: "dataProgress", callback: Callback\<{ receiveSize: number, totalSize: number }>): void;|@ohos.net.http.d.ts|
|新增|NA|模块名: ohos.net.http<br>类名: HttpRequest<br>方法 or 属性: off(type: "dataProgress", callback?: Callback\<{ receiveSize: number, totalSize: number }>): void;|@ohos.net.http.d.ts|
|新增|NA|模块名: ohos.net.mdns<br>类名: mdns|@ohos.net.mdns.d.ts|
|新增|NA|模块名: ohos.net.mdns<br>类名: mdns<br>方法 or 属性: function addLocalService(context: Context, serviceInfo: LocalServiceInfo,<br>    callback: AsyncCallback\<LocalServiceInfo>): void;|@ohos.net.mdns.d.ts|
|新增|NA|模块名: ohos.net.mdns<br>类名: mdns<br>方法 or 属性: function addLocalService(context: Context, serviceInfo: LocalServiceInfo): Promise\<LocalServiceInfo>;|@ohos.net.mdns.d.ts|
|新增|NA|模块名: ohos.net.mdns<br>类名: mdns<br>方法 or 属性: function removeLocalService(context: Context, serviceInfo: LocalServiceInfo,<br>    callback: AsyncCallback\<LocalServiceInfo>): void;|@ohos.net.mdns.d.ts|
|新增|NA|模块名: ohos.net.mdns<br>类名: mdns<br>方法 or 属性: function removeLocalService(context: Context, serviceInfo: LocalServiceInfo): Promise\<LocalServiceInfo>;|@ohos.net.mdns.d.ts|
|新增|NA|模块名: ohos.net.mdns<br>类名: mdns<br>方法 or 属性: function createDiscoveryService(context: Context, serviceType: string): DiscoveryService;|@ohos.net.mdns.d.ts|
|新增|NA|模块名: ohos.net.mdns<br>类名: mdns<br>方法 or 属性: function resolveLocalService(context: Context, serviceInfo: LocalServiceInfo,<br>    callback: AsyncCallback\<LocalServiceInfo>): void;|@ohos.net.mdns.d.ts|
|新增|NA|模块名: ohos.net.mdns<br>类名: mdns<br>方法 or 属性: function resolveLocalService(context: Context, serviceInfo: LocalServiceInfo): Promise\<LocalServiceInfo>;|@ohos.net.mdns.d.ts|
|新增|NA|模块名: ohos.net.mdns<br>类名: DiscoveryService|@ohos.net.mdns.d.ts|
|新增|NA|模块名: ohos.net.mdns<br>类名: DiscoveryService<br>方法 or 属性: on(type: 'discoveryStart',<br>      callback: Callback\<{ serviceInfo: LocalServiceInfo, errorCode?: MdnsError }>): void;|@ohos.net.mdns.d.ts|
|新增|NA|模块名: ohos.net.mdns<br>类名: DiscoveryService<br>方法 or 属性: on(type: 'discoveryStop',<br>      callback: Callback\<{ serviceInfo: LocalServiceInfo, errorCode?: MdnsError }>): void;|@ohos.net.mdns.d.ts|
|新增|NA|模块名: ohos.net.mdns<br>类名: DiscoveryService<br>方法 or 属性: on(type: 'serviceFound', callback: Callback\<LocalServiceInfo>): void;|@ohos.net.mdns.d.ts|
|新增|NA|模块名: ohos.net.mdns<br>类名: DiscoveryService<br>方法 or 属性: on(type: 'serviceLost', callback: Callback\<LocalServiceInfo>): void;|@ohos.net.mdns.d.ts|
|新增|NA|模块名: ohos.net.mdns<br>类名: DiscoveryService<br>方法 or 属性: startSearchingMDNS(): void;|@ohos.net.mdns.d.ts|
|新增|NA|模块名: ohos.net.mdns<br>类名: DiscoveryService<br>方法 or 属性: stopSearchingMDNS(): void;|@ohos.net.mdns.d.ts|
|新增|NA|模块名: ohos.net.mdns<br>类名: LocalServiceInfo|@ohos.net.mdns.d.ts|
|新增|NA|模块名: ohos.net.mdns<br>类名: LocalServiceInfo<br>方法 or 属性: serviceType: string;|@ohos.net.mdns.d.ts|
|新增|NA|模块名: ohos.net.mdns<br>类名: LocalServiceInfo<br>方法 or 属性: serviceName: string;|@ohos.net.mdns.d.ts|
|新增|NA|模块名: ohos.net.mdns<br>类名: LocalServiceInfo<br>方法 or 属性: port?: number;|@ohos.net.mdns.d.ts|
|新增|NA|模块名: ohos.net.mdns<br>类名: LocalServiceInfo<br>方法 or 属性: host?: NetAddress;|@ohos.net.mdns.d.ts|
|新增|NA|模块名: ohos.net.mdns<br>类名: LocalServiceInfo<br>方法 or 属性: serviceAttribute?: Array\<ServiceAttribute>;|@ohos.net.mdns.d.ts|
|新增|NA|模块名: ohos.net.mdns<br>类名: ServiceAttribute|@ohos.net.mdns.d.ts|
|新增|NA|模块名: ohos.net.mdns<br>类名: ServiceAttribute<br>方法 or 属性: key: string;|@ohos.net.mdns.d.ts|
|新增|NA|模块名: ohos.net.mdns<br>类名: ServiceAttribute<br>方法 or 属性: value: Array\<number>;|@ohos.net.mdns.d.ts|
|新增|NA|模块名: ohos.net.mdns<br>类名: MdnsError|@ohos.net.mdns.d.ts|
|新增|NA|模块名: ohos.net.mdns<br>类名: MdnsError<br>方法 or 属性: INTERNAL_ERROR = 0|@ohos.net.mdns.d.ts|
|新增|NA|模块名: ohos.net.mdns<br>类名: MdnsError<br>方法 or 属性: ALREADY_ACTIVE = 1|@ohos.net.mdns.d.ts|
|新增|NA|模块名: ohos.net.mdns<br>类名: MdnsError<br>方法 or 属性: MAX_LIMIT = 2|@ohos.net.mdns.d.ts|
|新增|NA|类名：tag<br>方法or属性：function registerForegroundDispatch(elementName: ElementName, discTech: number[], callback: AsyncCallback\<TagInfo>): void;|@ohos.nfc.tag.d.ts|
|新增|NA|类名：tag<br>方法or属性：function unregisterForegroundDispatch(elementName: ElementName): void;|@ohos.nfc.tag.d.ts|
|新增|NA|模块名: ohos.secureElement<br>类名: omapi|@ohos.secureElement.d.ts|
|新增|NA|模块名: ohos.secureElement<br>类名: omapi<br>方法 or 属性: function newSEService(type: 'serviceState', callback: Callback\<ServiceState>): SEService;|@ohos.secureElement.d.ts|
|新增|NA|模块名: ohos.secureElement<br>类名: SEService|@ohos.secureElement.d.ts|
|新增|NA|模块名: ohos.secureElement<br>类名: SEService<br>方法 or 属性: getReaders(): Reader[];|@ohos.secureElement.d.ts|
|新增|NA|模块名: ohos.secureElement<br>类名: SEService<br>方法 or 属性: isConnected(): boolean;|@ohos.secureElement.d.ts|
|新增|NA|模块名: ohos.secureElement<br>类名: SEService<br>方法 or 属性: shutdown(): void;|@ohos.secureElement.d.ts|
|新增|NA|模块名: ohos.secureElement<br>类名: SEService<br>方法 or 属性: getVersion(): string;|@ohos.secureElement.d.ts|
|新增|NA|模块名: ohos.secureElement<br>类名: Reader|@ohos.secureElement.d.ts|
|新增|NA|模块名: ohos.secureElement<br>类名: Reader<br>方法 or 属性: getName(): string;|@ohos.secureElement.d.ts|
|新增|NA|模块名: ohos.secureElement<br>类名: Reader<br>方法 or 属性: isSecureElementPresent(): boolean;|@ohos.secureElement.d.ts|
|新增|NA|模块名: ohos.secureElement<br>类名: Reader<br>方法 or 属性: openSession(): Session;|@ohos.secureElement.d.ts|
|新增|NA|模块名: ohos.secureElement<br>类名: Reader<br>方法 or 属性: closeSessions(): void;|@ohos.secureElement.d.ts|
|新增|NA|模块名: ohos.secureElement<br>类名: Session|@ohos.secureElement.d.ts|
|新增|NA|模块名: ohos.secureElement<br>类名: Session<br>方法 or 属性: getReader(): Reader;|@ohos.secureElement.d.ts|
|新增|NA|模块名: ohos.secureElement<br>类名: Session<br>方法 or 属性: getATR(): number[];|@ohos.secureElement.d.ts|
|新增|NA|模块名: ohos.secureElement<br>类名: Session<br>方法 or 属性: close(): void;|@ohos.secureElement.d.ts|
|新增|NA|模块名: ohos.secureElement<br>类名: Session<br>方法 or 属性: isClosed(): boolean;|@ohos.secureElement.d.ts|
|新增|NA|模块名: ohos.secureElement<br>类名: Session<br>方法 or 属性: closeChannels(): void;|@ohos.secureElement.d.ts|
|新增|NA|模块名: ohos.secureElement<br>类名: Session<br>方法 or 属性: openBasicChannel(aid: number[]): Promise\<Channel>;|@ohos.secureElement.d.ts|
|新增|NA|模块名: ohos.secureElement<br>类名: Session<br>方法 or 属性: openBasicChannel(aid: number[], callback: AsyncCallback\<Channel>): void;|@ohos.secureElement.d.ts|
|新增|NA|模块名: ohos.secureElement<br>类名: Session<br>方法 or 属性: openBasicChannel(aid: number[], p2: number): Promise\<Channel>;|@ohos.secureElement.d.ts|
|新增|NA|模块名: ohos.secureElement<br>类名: Session<br>方法 or 属性: openBasicChannel(aid: number[], p2: number, callback: AsyncCallback\<Channel>): void;|@ohos.secureElement.d.ts|
|新增|NA|模块名: ohos.secureElement<br>类名: Session<br>方法 or 属性: openLogicalChannel(aid: number[]): Promise\<Channel>;|@ohos.secureElement.d.ts|
|新增|NA|模块名: ohos.secureElement<br>类名: Session<br>方法 or 属性: openLogicalChannel(aid: number[], callback: AsyncCallback\<Channel>): void;|@ohos.secureElement.d.ts|
|新增|NA|模块名: ohos.secureElement<br>类名: Session<br>方法 or 属性: openLogicalChannel(aid: number[], p2: number): Promise\<Channel>;|@ohos.secureElement.d.ts|
|新增|NA|模块名: ohos.secureElement<br>类名: Session<br>方法 or 属性: openLogicalChannel(aid: number[], p2: number, callback: AsyncCallback\<Channel>): void;|@ohos.secureElement.d.ts|
|新增|NA|模块名: ohos.secureElement<br>类名: Channel|@ohos.secureElement.d.ts|
|新增|NA|模块名: ohos.secureElement<br>类名: Channel<br>方法 or 属性: getSession(): Session;|@ohos.secureElement.d.ts|
|新增|NA|模块名: ohos.secureElement<br>类名: Channel<br>方法 or 属性: close(): void;|@ohos.secureElement.d.ts|
|新增|NA|模块名: ohos.secureElement<br>类名: Channel<br>方法 or 属性: isBasicChannel(): boolean;|@ohos.secureElement.d.ts|
|新增|NA|模块名: ohos.secureElement<br>类名: Channel<br>方法 or 属性: isClosed(): boolean;|@ohos.secureElement.d.ts|
|新增|NA|模块名: ohos.secureElement<br>类名: Channel<br>方法 or 属性: getSelectResponse(): number[];|@ohos.secureElement.d.ts|
|新增|NA|模块名: ohos.secureElement<br>类名: Channel<br>方法 or 属性: transmit(command: number[]): Promise\<number[]>;|@ohos.secureElement.d.ts|
|新增|NA|模块名: ohos.secureElement<br>类名: Channel<br>方法 or 属性: transmit(command: number[], callback: AsyncCallback\<number[]>): void;|@ohos.secureElement.d.ts|
|新增|NA|模块名: ohos.secureElement<br>类名: ServiceState|@ohos.secureElement.d.ts|
|新增|NA|模块名: ohos.secureElement<br>类名: ServiceState<br>方法 or 属性: DISCONNECTED = 0|@ohos.secureElement.d.ts|
|新增|NA|模块名: ohos.secureElement<br>类名: ServiceState<br>方法 or 属性: CONNECTED = 1|@ohos.secureElement.d.ts|
|新增|NA|类名：wifiManager<br>方法or属性：function getScanInfoList(): Array\<WifiScanInfo>;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager<br>方法or属性：function updateDeviceConfig(config: WifiDeviceConfig): number;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager<br>方法or属性：function disableDeviceConfig(networkId: number): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager<br>方法or属性：function removeAllDeviceConfigs(): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager<br>方法or属性：function removeDeviceConfig(networkId: number): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager<br>方法or属性：function isBandTypeSupported(bandType: WifiBandType): boolean;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager<br>方法or属性：function get5GChannelList(): Array\<number>;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager<br>方法or属性：function getHotspotStations(): Array\<StationInfo>;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager<br>方法or属性：function getCurrentP2pGroup(): Promise\<WifiP2pGroupInfo>;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager<br>方法or属性：function getCurrentP2pGroup(callback: AsyncCallback\<WifiP2pGroupInfo>): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager<br>方法or属性：function createP2pGroup(config: WifiP2PConfig): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager<br>方法or属性：function removeP2pGroup(): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager<br>方法or属性：function startDiscoverP2pDevices(): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager<br>方法or属性：function stopDiscoverP2pDevices(): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager<br>方法or属性：function deletePersistentP2pGroup(netId: number): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager<br>方法or属性：function setP2pDeviceName(devName: string): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiBandType|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiBandType<br>方法 or 属性：WIFI_BAND_NONE|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiBandType<br>方法 or 属性：WIFI_BAND_2G|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiBandType<br>方法 or 属性：WIFI_BAND_5G|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiBandType<br>方法 or 属性：WIFI_BAND_6G|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiBandType<br>方法 or 属性：WIFI_BAND_60G|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiStandard|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiStandard<br>方法 or 属性：WIFI_STANDARD_UNDEFINED|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiStandard<br>方法 or 属性：WIFI_STANDARD_11A|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiStandard<br>方法 or 属性：WIFI_STANDARD_11B|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiStandard<br>方法 or 属性：WIFI_STANDARD_11G|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiStandard<br>方法 or 属性：WIFI_STANDARD_11N|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiStandard<br>方法 or 属性：WIFI_STANDARD_11AC|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiStandard<br>方法 or 属性：WIFI_STANDARD_11AX|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiStandard<br>方法 or 属性：WIFI_STANDARD_11AD|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiLinkedInfo<br>方法 or 属性：rxLinkSpeed: number;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiLinkedInfo<br>方法 or 属性：maxSupportedTxLinkSpeed: number;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiLinkedInfo<br>方法 or 属性：maxSupportedRxLinkSpeed: number;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiLinkedInfo<br>方法 or 属性：channelWidth: WifiChannelWidth;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiLinkedInfo<br>方法 or 属性：wifiStandard: WifiStandard;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: HotspotConfig<br>方法 or 属性：channel: number;|@ohos.wifiManager.d.ts|
|删除|模块名：ohos.wifiManager<br>类名:wifiManager<br>方法 or 属性:function getScanResults(): Promise\<Array\<WifiScanInfo>>;|NA|@ohos.wifiManager.d.ts|
|删除|模块名：ohos.wifiManager<br>类名:wifiManager<br>方法 or 属性:function getScanResults(callback: AsyncCallback\<Array\<WifiScanInfo>>): void;|NA|@ohos.wifiManager.d.ts|
|删除|模块名：ohos.wifiManager<br>类名:wifiManager<br>方法 or 属性:function getScanResultsSync(): Array\<WifiScanInfo>;|NA|@ohos.wifiManager.d.ts|
|删除|模块名：ohos.wifiManager<br>类名:wifiManager<br>方法 or 属性:function updateNetwork(config: WifiDeviceConfig): number;|NA|@ohos.wifiManager.d.ts|
|删除|模块名：ohos.wifiManager<br>类名:wifiManager<br>方法 or 属性:function disableNetwork(netId: number): void;|NA|@ohos.wifiManager.d.ts|
|删除|模块名：ohos.wifiManager<br>类名:wifiManager<br>方法 or 属性:function removeAllNetwork(): void;|NA|@ohos.wifiManager.d.ts|
|删除|模块名：ohos.wifiManager<br>类名:wifiManager<br>方法 or 属性:function removeDevice(id: number): void;|NA|@ohos.wifiManager.d.ts|
|删除|模块名：ohos.wifiManager<br>类名:wifiManager<br>方法 or 属性:function getStations(): Array\<StationInfo>;|NA|@ohos.wifiManager.d.ts|
|删除|模块名：ohos.wifiManager<br>类名:wifiManager<br>方法 or 属性:function getCurrentGroup(): Promise\<WifiP2pGroupInfo>;|NA|@ohos.wifiManager.d.ts|
|删除|模块名：ohos.wifiManager<br>类名:wifiManager<br>方法 or 属性:function getCurrentGroup(callback: AsyncCallback\<WifiP2pGroupInfo>): void;|NA|@ohos.wifiManager.d.ts|
|删除|模块名：ohos.wifiManager<br>类名:wifiManager<br>方法 or 属性:function createGroup(config: WifiP2PConfig): void;|NA|@ohos.wifiManager.d.ts|
|删除|模块名：ohos.wifiManager<br>类名:wifiManager<br>方法 or 属性:function removeGroup(): void;|NA|@ohos.wifiManager.d.ts|
|删除|模块名：ohos.wifiManager<br>类名:wifiManager<br>方法 or 属性:function startDiscoverDevices(): void;|NA|@ohos.wifiManager.d.ts|
|删除|模块名：ohos.wifiManager<br>类名:wifiManager<br>方法 or 属性:function stopDiscoverDevices(): void;|NA|@ohos.wifiManager.d.ts|
|删除|模块名：ohos.wifiManager<br>类名:wifiManager<br>方法 or 属性:function deletePersistentGroup(netId: number): void;|NA|@ohos.wifiManager.d.ts|
|删除|模块名：ohos.wifiManager<br>类名:wifiManager<br>方法 or 属性:function setDeviceName(devName: string): void;|NA|@ohos.wifiManager.d.ts|
|权限有变化|类名：wifiManager<br>方法 or 属性：function scan(): void;<br>权限:ohos.permission.SET_WIFI_INFO and ohos.permission.LOCATION|类名：wifiManager<br>方法 or 属性：function scan(): void;<br>权限:ohos.permission.SET_WIFI_INFO and ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION|@ohos.wifiManager.d.ts|
|权限有变化|类名：wifiManager<br>方法 or 属性：function getCandidateConfigs(): Array\<WifiDeviceConfig>;<br>权限:ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION|类名：wifiManager<br>方法 or 属性：function getCandidateConfigs(): Array\<WifiDeviceConfig>;<br>权限:ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION|@ohos.wifiManager.d.ts|
|权限有变化|类名：wifiManager<br>方法 or 属性：function getDeviceConfigs(): Array\<WifiDeviceConfig>;<br>权限:ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION and ohos.permission.GET_WIFI_CONFIG|类名：wifiManager<br>方法 or 属性：function getDeviceConfigs(): Array\<WifiDeviceConfig>;<br>权限:ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION and ohos.permission.GET_WIFI_CONFIG|@ohos.wifiManager.d.ts|
|权限有变化|类名：wifiManager<br>方法 or 属性：function getP2pPeerDevices(): Promise\<WifiP2pDevice[]>;<br>权限:ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION|类名：wifiManager<br>方法 or 属性：function getP2pPeerDevices(): Promise\<WifiP2pDevice[]>;<br>权限:ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION|@ohos.wifiManager.d.ts|
|权限有变化|类名：wifiManager<br>方法 or 属性：function getP2pPeerDevices(callback: AsyncCallback\<WifiP2pDevice[]>): void;<br>权限:ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION|类名：wifiManager<br>方法 or 属性：function getP2pPeerDevices(callback: AsyncCallback\<WifiP2pDevice[]>): void;<br>权限:ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION|@ohos.wifiManager.d.ts|
|权限有变化|类名：wifiManager<br>方法 or 属性：function p2pConnect(config: WifiP2PConfig): void;<br>权限:ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION|类名：wifiManager<br>方法 or 属性：function p2pConnect(config: WifiP2PConfig): void;<br>权限:ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION|@ohos.wifiManager.d.ts|
|权限有变化|类名：wifiManager<br>方法 or 属性：function getP2pGroups(): Promise\<Array\<WifiP2pGroupInfo>>;<br>权限:ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION|类名：wifiManager<br>方法 or 属性：function getP2pGroups(): Promise\<Array\<WifiP2pGroupInfo>>;<br>权限:ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION|@ohos.wifiManager.d.ts|
|权限有变化|类名：wifiManager<br>方法 or 属性：function getP2pGroups(callback: AsyncCallback\<Array\<WifiP2pGroupInfo>>): void;<br>权限:ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION|类名：wifiManager<br>方法 or 属性：function getP2pGroups(callback: AsyncCallback\<Array\<WifiP2pGroupInfo>>): void;<br>权限:ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION|@ohos.wifiManager.d.ts|
|权限有变化|类名：wifiManager<br>方法 or 属性：function on(type: "p2pDeviceChange", callback: Callback\<WifiP2pDevice>): void;<br>权限:ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION|类名：wifiManager<br>方法 or 属性：function on(type: "p2pDeviceChange", callback: Callback\<WifiP2pDevice>): void;<br>权限:ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION|@ohos.wifiManager.d.ts|
|权限有变化|类名：wifiManager<br>方法 or 属性：function off(type: "p2pDeviceChange", callback?: Callback\<WifiP2pDevice>): void;<br>权限:ohos.permission.LOCATION|类名：wifiManager<br>方法 or 属性：function off(type: "p2pDeviceChange", callback?: Callback\<WifiP2pDevice>): void;<br>权限:ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION|@ohos.wifiManager.d.ts|
|权限有变化|类名：wifiManager<br>方法 or 属性：function on(type: "p2pPeerDeviceChange", callback: Callback\<WifiP2pDevice[]>): void;<br>权限:ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION|类名：wifiManager<br>方法 or 属性：function on(type: "p2pPeerDeviceChange", callback: Callback\<WifiP2pDevice[]>): void;<br>权限:ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION|@ohos.wifiManager.d.ts|
|权限有变化|类名：wifiManager<br>方法 or 属性：function off(type: "p2pPeerDeviceChange", callback?: Callback\<WifiP2pDevice[]>): void;<br>权限:ohos.permission.LOCATION|类名：wifiManager<br>方法 or 属性：function off(type: "p2pPeerDeviceChange", callback?: Callback\<WifiP2pDevice[]>): void;<br>权限:ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION|@ohos.wifiManager.d.ts|
