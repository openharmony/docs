| Change Type | Old Version | New Version | d.ts File |
| ---- | ------ | ------ | -------- |
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: bluetoothManager<br>Method or attribute name: function setDevicePinCode(device: string, code: string, callback: AsyncCallback\<void>): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: bluetoothManager<br>Method or attribute name: function setDevicePinCode(device: string, code: string): Promise\<void>;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: BLECharacteristic<br>Method or attribute name: properties?: GattProperties;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: ScanResult<br>Method or attribute name: deviceName: string;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: PinRequiredParam<br>Method or attribute name: pinType: PinType;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: GattProperties|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: GattProperties<br>Method or attribute name: write?: boolean;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: GattProperties<br>Method or attribute name: writeNoResponse?: boolean;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: GattProperties<br>Method or attribute name: read?: boolean;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: GattProperties<br>Method or attribute name: notify?: boolean;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: GattProperties<br>Method or attribute name: indicate?: boolean;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: PinType|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: PinType<br>Method or attribute name: PIN_TYPE_ENTER_PIN_CODE = 0|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: PinType<br>Method or attribute name: PIN_TYPE_ENTER_PASSKEY = 1|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: PinType<br>Method or attribute name: PIN_TYPE_CONFIRM_PASSKEY = 2|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: PinType<br>Method or attribute name: PIN_TYPE_NO_PASSKEY_CONSENT = 3|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: PinType<br>Method or attribute name: PIN_TYPE_NOTIFY_PASSKEY = 4|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: PinType<br>Method or attribute name: PIN_TYPE_DISPLAY_PIN_CODE = 5|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: PinType<br>Method or attribute name: PIN_TYPE_OOB_CONSENT = 6|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: PinType<br>Method or attribute name: PIN_TYPE_PIN_16_DIGITS = 7|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.net.connection<br>Class name: connection<br>Method or attribute name: function getGlobalHttpProxy(callback: AsyncCallback\<HttpProxy>): void;|@ohos.net.connection.d.ts|
|Added|NA|Module name: ohos.net.connection<br>Class name: connection<br>Method or attribute name: function getGlobalHttpProxy(): Promise\<HttpProxy>;|@ohos.net.connection.d.ts|
|Added|NA|Module name: ohos.net.connection<br>Class name: connection<br>Method or attribute name: function setGlobalHttpProxy(httpProxy: HttpProxy, callback: AsyncCallback\<void>): void;|@ohos.net.connection.d.ts|
|Added|NA|Module name: ohos.net.connection<br>Class name: connection<br>Method or attribute name: function setGlobalHttpProxy(httpProxy: HttpProxy): Promise\<void>;|@ohos.net.connection.d.ts|
|Added|NA|Module name: ohos.net.connection<br>Class name: HttpProxy|@ohos.net.connection.d.ts|
|Added|NA|Module name: ohos.net.connection<br>Class name: HttpProxy<br>Method or attribute name: host: string;|@ohos.net.connection.d.ts|
|Added|NA|Module name: ohos.net.connection<br>Class name: HttpProxy<br>Method or attribute name: port: number;|@ohos.net.connection.d.ts|
|Added|NA|Module name: ohos.net.connection<br>Class name: HttpProxy<br>Method or attribute name: exclusionList: Array\<string>;|@ohos.net.connection.d.ts|
|Added|NA|Module name: ohos.net.ethernet<br>Class name: ethernet<br>Method or attribute name: function on(type: 'interfaceStateChange', callback: Callback\<{ iface: string, active: boolean }>): void;|@ohos.net.ethernet.d.ts|
|Added|NA|Module name: ohos.net.ethernet<br>Class name: ethernet<br>Method or attribute name: function off(type: 'interfaceStateChange', callback?: Callback\<{ iface: string, active: boolean }>): void;|@ohos.net.ethernet.d.ts|
|Added|NA|Module name: ohos.net.http<br>Class name: HttpRequestOptions<br>Method or attribute name: usingProxy?: boolean \| HttpProxy;|@ohos.net.http.d.ts|
|Added|NA|Module name: ohos.net.http<br>Class name: HttpRequestOptions<br>Method or attribute name: caPath?: string;|@ohos.net.http.d.ts|
|Added|NA|Module name: ohos.net.http<br>Class name: HttpRequest<br>Method or attribute name: request2(url: string, callback: AsyncCallback\<number>): void;|@ohos.net.http.d.ts|
|Added|NA|Module name: ohos.net.http<br>Class name: HttpRequest<br>Method or attribute name: request2(url: string, options: HttpRequestOptions, callback: AsyncCallback\<number>): void;|@ohos.net.http.d.ts|
|Added|NA|Module name: ohos.net.http<br>Class name: HttpRequest<br>Method or attribute name: request2(url: string, options?: HttpRequestOptions): Promise\<number>;|@ohos.net.http.d.ts|
|Added|NA|Module name: ohos.net.http<br>Class name: HttpRequest<br>Method or attribute name: on(type: "dataReceive", callback: Callback\<ArrayBuffer>): void;|@ohos.net.http.d.ts|
|Added|NA|Module name: ohos.net.http<br>Class name: HttpRequest<br>Method or attribute name: off(type: "dataReceive", callback?: Callback\<ArrayBuffer>): void;|@ohos.net.http.d.ts|
|Added|NA|Module name: ohos.net.http<br>Class name: HttpRequest<br>Method or attribute name: on(type: "dataEnd", callback: Callback\<void>): void;|@ohos.net.http.d.ts|
|Added|NA|Module name: ohos.net.http<br>Class name: HttpRequest<br>Method or attribute name: off(type: "dataEnd", callback?: Callback\<void>): void;|@ohos.net.http.d.ts|
|Added|NA|Module name: ohos.net.http<br>Class name: HttpRequest<br>Method or attribute name: on(type: "dataProgress", callback: Callback\<{ receiveSize: number, totalSize: number }>): void;|@ohos.net.http.d.ts|
|Added|NA|Module name: ohos.net.http<br>Class name: HttpRequest<br>Method or attribute name: off(type: "dataProgress", callback?: Callback\<{ receiveSize: number, totalSize: number }>): void;|@ohos.net.http.d.ts|
|Added|NA|Module name: ohos.net.mdns<br>Class name: mdns|@ohos.net.mdns.d.ts|
|Added|NA|Module name: ohos.net.mdns<br>Class name: mdns<br>Method or attribute name: function addLocalService(context: Context, serviceInfo: LocalServiceInfo,<br>    callback: AsyncCallback\<LocalServiceInfo>): void;|@ohos.net.mdns.d.ts|
|Added|NA|Module name: ohos.net.mdns<br>Class name: mdns<br>Method or attribute name: function addLocalService(context: Context, serviceInfo: LocalServiceInfo): Promise\<LocalServiceInfo>;|@ohos.net.mdns.d.ts|
|Added|NA|Module name: ohos.net.mdns<br>Class name: mdns<br>Method or attribute name: function removeLocalService(context: Context, serviceInfo: LocalServiceInfo,<br>    callback: AsyncCallback\<LocalServiceInfo>): void;|@ohos.net.mdns.d.ts|
|Added|NA|Module name: ohos.net.mdns<br>Class name: mdns<br>Method or attribute name: function removeLocalService(context: Context, serviceInfo: LocalServiceInfo): Promise\<LocalServiceInfo>;|@ohos.net.mdns.d.ts|
|Added|NA|Module name: ohos.net.mdns<br>Class name: mdns<br>Method or attribute name: function createDiscoveryService(context: Context, serviceType: string): DiscoveryService;|@ohos.net.mdns.d.ts|
|Added|NA|Module name: ohos.net.mdns<br>Class name: mdns<br>Method or attribute name: function resolveLocalService(context: Context, serviceInfo: LocalServiceInfo,<br>    callback: AsyncCallback\<LocalServiceInfo>): void;|@ohos.net.mdns.d.ts|
|Added|NA|Module name: ohos.net.mdns<br>Class name: mdns<br>Method or attribute name: function resolveLocalService(context: Context, serviceInfo: LocalServiceInfo): Promise\<LocalServiceInfo>;|@ohos.net.mdns.d.ts|
|Added|NA|Module name: ohos.net.mdns<br>Class name: DiscoveryService|@ohos.net.mdns.d.ts|
|Added|NA|Module name: ohos.net.mdns<br>Class name: DiscoveryService<br>Method or attribute name: on(type: 'discoveryStart',<br>      callback: Callback\<{ serviceInfo: LocalServiceInfo, errorCode?: MdnsError }>): void;|@ohos.net.mdns.d.ts|
|Added|NA|Module name: ohos.net.mdns<br>Class name: DiscoveryService<br>Method or attribute name: on(type: 'discoveryStop',<br>      callback: Callback\<{ serviceInfo: LocalServiceInfo, errorCode?: MdnsError }>): void;|@ohos.net.mdns.d.ts|
|Added|NA|Module name: ohos.net.mdns<br>Class name: DiscoveryService<br>Method or attribute name: on(type: 'serviceFound', callback: Callback\<LocalServiceInfo>): void;|@ohos.net.mdns.d.ts|
|Added|NA|Module name: ohos.net.mdns<br>Class name: DiscoveryService<br>Method or attribute name: on(type: 'serviceLost', callback: Callback\<LocalServiceInfo>): void;|@ohos.net.mdns.d.ts|
|Added|NA|Module name: ohos.net.mdns<br>Class name: DiscoveryService<br>Method or attribute name: startSearchingMDNS(): void;|@ohos.net.mdns.d.ts|
|Added|NA|Module name: ohos.net.mdns<br>Class name: DiscoveryService<br>Method or attribute name: stopSearchingMDNS(): void;|@ohos.net.mdns.d.ts|
|Added|NA|Module name: ohos.net.mdns<br>Class name: LocalServiceInfo|@ohos.net.mdns.d.ts|
|Added|NA|Module name: ohos.net.mdns<br>Class name: LocalServiceInfo<br>Method or attribute name: serviceType: string;|@ohos.net.mdns.d.ts|
|Added|NA|Module name: ohos.net.mdns<br>Class name: LocalServiceInfo<br>Method or attribute name: serviceName: string;|@ohos.net.mdns.d.ts|
|Added|NA|Module name: ohos.net.mdns<br>Class name: LocalServiceInfo<br>Method or attribute name: port?: number;|@ohos.net.mdns.d.ts|
|Added|NA|Module name: ohos.net.mdns<br>Class name: LocalServiceInfo<br>Method or attribute name: host?: NetAddress;|@ohos.net.mdns.d.ts|
|Added|NA|Module name: ohos.net.mdns<br>Class name: LocalServiceInfo<br>Method or attribute name: serviceAttribute?: Array\<ServiceAttribute>;|@ohos.net.mdns.d.ts|
|Added|NA|Module name: ohos.net.mdns<br>Class name: ServiceAttribute|@ohos.net.mdns.d.ts|
|Added|NA|Module name: ohos.net.mdns<br>Class name: ServiceAttribute<br>Method or attribute name: key: string;|@ohos.net.mdns.d.ts|
|Added|NA|Module name: ohos.net.mdns<br>Class name: ServiceAttribute<br>Method or attribute name: value: Array\<number>;|@ohos.net.mdns.d.ts|
|Added|NA|Module name: ohos.net.mdns<br>Class name: MdnsError|@ohos.net.mdns.d.ts|
|Added|NA|Module name: ohos.net.mdns<br>Class name: MdnsError<br>Method or attribute name: INTERNAL_ERROR = 0|@ohos.net.mdns.d.ts|
|Added|NA|Module name: ohos.net.mdns<br>Class name: MdnsError<br>Method or attribute name: ALREADY_ACTIVE = 1|@ohos.net.mdns.d.ts|
|Added|NA|Module name: ohos.net.mdns<br>Class name: MdnsError<br>Method or attribute name: MAX_LIMIT = 2|@ohos.net.mdns.d.ts|
|Added|NA|Class name: tag<br>Method or attribute name: function registerForegroundDispatch(elementName: ElementName, discTech: number[], callback: AsyncCallback\<TagInfo>): void;|@ohos.nfc.tag.d.ts|
|Added|NA|Class name: tag<br>Method or attribute name: function unregisterForegroundDispatch(elementName: ElementName): void;|@ohos.nfc.tag.d.ts|
|Added|NA|Module name: ohos.secureElement<br>Class name: omapi|@ohos.secureElement.d.ts|
|Added|NA|Module name: ohos.secureElement<br>Class name: omapi<br>Method or attribute name: function newSEService(type: 'serviceState', callback: Callback\<ServiceState>): SEService;|@ohos.secureElement.d.ts|
|Added|NA|Module name: ohos.secureElement<br>Class name: SEService|@ohos.secureElement.d.ts|
|Added|NA|Module name: ohos.secureElement<br>Class name: SEService<br>Method or attribute name: getReaders(): Reader[];|@ohos.secureElement.d.ts|
|Added|NA|Module name: ohos.secureElement<br>Class name: SEService<br>Method or attribute name: isConnected(): boolean;|@ohos.secureElement.d.ts|
|Added|NA|Module name: ohos.secureElement<br>Class name: SEService<br>Method or attribute name: shutdown(): void;|@ohos.secureElement.d.ts|
|Added|NA|Module name: ohos.secureElement<br>Class name: SEService<br>Method or attribute name: getVersion(): string;|@ohos.secureElement.d.ts|
|Added|NA|Module name: ohos.secureElement<br>Class name: Reader|@ohos.secureElement.d.ts|
|Added|NA|Module name: ohos.secureElement<br>Class name: Reader<br>Method or attribute name: getName(): string;|@ohos.secureElement.d.ts|
|Added|NA|Module name: ohos.secureElement<br>Class name: Reader<br>Method or attribute name: isSecureElementPresent(): boolean;|@ohos.secureElement.d.ts|
|Added|NA|Module name: ohos.secureElement<br>Class name: Reader<br>Method or attribute name: openSession(): Session;|@ohos.secureElement.d.ts|
|Added|NA|Module name: ohos.secureElement<br>Class name: Reader<br>Method or attribute name: closeSessions(): void;|@ohos.secureElement.d.ts|
|Added|NA|Module name: ohos.secureElement<br>Class name: Session|@ohos.secureElement.d.ts|
|Added|NA|Module name: ohos.secureElement<br>Class name: Session<br>Method or attribute name: getReader(): Reader;|@ohos.secureElement.d.ts|
|Added|NA|Module name: ohos.secureElement<br>Class name: Session<br>Method or attribute name: getATR(): number[];|@ohos.secureElement.d.ts|
|Added|NA|Module name: ohos.secureElement<br>Class name: Session<br>Method or attribute name: close(): void;|@ohos.secureElement.d.ts|
|Added|NA|Module name: ohos.secureElement<br>Class name: Session<br>Method or attribute name: isClosed(): boolean;|@ohos.secureElement.d.ts|
|Added|NA|Module name: ohos.secureElement<br>Class name: Session<br>Method or attribute name: closeChannels(): void;|@ohos.secureElement.d.ts|
|Added|NA|Module name: ohos.secureElement<br>Class name: Session<br>Method or attribute name: openBasicChannel(aid: number[]): Promise\<Channel>;|@ohos.secureElement.d.ts|
|Added|NA|Module name: ohos.secureElement<br>Class name: Session<br>Method or attribute name: openBasicChannel(aid: number[], callback: AsyncCallback\<Channel>): void;|@ohos.secureElement.d.ts|
|Added|NA|Module name: ohos.secureElement<br>Class name: Session<br>Method or attribute name: openBasicChannel(aid: number[], p2: number): Promise\<Channel>;|@ohos.secureElement.d.ts|
|Added|NA|Module name: ohos.secureElement<br>Class name: Session<br>Method or attribute name: openBasicChannel(aid: number[], p2: number, callback: AsyncCallback\<Channel>): void;|@ohos.secureElement.d.ts|
|Added|NA|Module name: ohos.secureElement<br>Class name: Session<br>Method or attribute name: openLogicalChannel(aid: number[]): Promise\<Channel>;|@ohos.secureElement.d.ts|
|Added|NA|Module name: ohos.secureElement<br>Class name: Session<br>Method or attribute name: openLogicalChannel(aid: number[], callback: AsyncCallback\<Channel>): void;|@ohos.secureElement.d.ts|
|Added|NA|Module name: ohos.secureElement<br>Class name: Session<br>Method or attribute name: openLogicalChannel(aid: number[], p2: number): Promise\<Channel>;|@ohos.secureElement.d.ts|
|Added|NA|Module name: ohos.secureElement<br>Class name: Session<br>Method or attribute name: openLogicalChannel(aid: number[], p2: number, callback: AsyncCallback\<Channel>): void;|@ohos.secureElement.d.ts|
|Added|NA|Module name: ohos.secureElement<br>Class name: Channel|@ohos.secureElement.d.ts|
|Added|NA|Module name: ohos.secureElement<br>Class name: Channel<br>Method or attribute name: getSession(): Session;|@ohos.secureElement.d.ts|
|Added|NA|Module name: ohos.secureElement<br>Class name: Channel<br>Method or attribute name: close(): void;|@ohos.secureElement.d.ts|
|Added|NA|Module name: ohos.secureElement<br>Class name: Channel<br>Method or attribute name: isBasicChannel(): boolean;|@ohos.secureElement.d.ts|
|Added|NA|Module name: ohos.secureElement<br>Class name: Channel<br>Method or attribute name: isClosed(): boolean;|@ohos.secureElement.d.ts|
|Added|NA|Module name: ohos.secureElement<br>Class name: Channel<br>Method or attribute name: getSelectResponse(): number[];|@ohos.secureElement.d.ts|
|Added|NA|Module name: ohos.secureElement<br>Class name: Channel<br>Method or attribute name: transmit(command: number[]): Promise\<number[]>;|@ohos.secureElement.d.ts|
|Added|NA|Module name: ohos.secureElement<br>Class name: Channel<br>Method or attribute name: transmit(command: number[], callback: AsyncCallback\<number[]>): void;|@ohos.secureElement.d.ts|
|Added|NA|Module name: ohos.secureElement<br>Class name: ServiceState|@ohos.secureElement.d.ts|
|Added|NA|Module name: ohos.secureElement<br>Class name: ServiceState<br>Method or attribute name: DISCONNECTED = 0|@ohos.secureElement.d.ts|
|Added|NA|Module name: ohos.secureElement<br>Class name: ServiceState<br>Method or attribute name: CONNECTED = 1|@ohos.secureElement.d.ts|
|Added|NA|Class name: wifiManager<br>Method or attribute name: function getScanInfoList(): Array\<WifiScanInfo>;|@ohos.wifiManager.d.ts|
|Added|NA|Class name: wifiManager<br>Method or attribute name: function updateDeviceConfig(config: WifiDeviceConfig): number;|@ohos.wifiManager.d.ts|
|Added|NA|Class name: wifiManager<br>Method or attribute name: function disableDeviceConfig(networkId: number): void;|@ohos.wifiManager.d.ts|
|Added|NA|Class name: wifiManager<br>Method or attribute name: function removeAllDeviceConfigs(): void;|@ohos.wifiManager.d.ts|
|Added|NA|Class name: wifiManager<br>Method or attribute name: function removeDeviceConfig(networkId: number): void;|@ohos.wifiManager.d.ts|
|Added|NA|Class name: wifiManager<br>Method or attribute name: function isBandTypeSupported(bandType: WifiBandType): boolean;|@ohos.wifiManager.d.ts|
|Added|NA|Class name: wifiManager<br>Method or attribute name: function get5GChannelList(): Array\<number>;|@ohos.wifiManager.d.ts|
|Added|NA|Class name: wifiManager<br>Method or attribute name: function getHotspotStations(): Array\<StationInfo>;|@ohos.wifiManager.d.ts|
|Added|NA|Class name: wifiManager<br>Method or attribute name: function getCurrentP2pGroup(): Promise\<WifiP2pGroupInfo>;|@ohos.wifiManager.d.ts|
|Added|NA|Class name: wifiManager<br>Method or attribute name: function getCurrentP2pGroup(callback: AsyncCallback\<WifiP2pGroupInfo>): void;|@ohos.wifiManager.d.ts|
|Added|NA|Class name: wifiManager<br>Method or attribute name: function createP2pGroup(config: WifiP2PConfig): void;|@ohos.wifiManager.d.ts|
|Added|NA|Class name: wifiManager<br>Method or attribute name: function removeP2pGroup(): void;|@ohos.wifiManager.d.ts|
|Added|NA|Class name: wifiManager<br>Method or attribute name: function startDiscoverP2pDevices(): void;|@ohos.wifiManager.d.ts|
|Added|NA|Class name: wifiManager<br>Method or attribute name: function stopDiscoverP2pDevices(): void;|@ohos.wifiManager.d.ts|
|Added|NA|Class name: wifiManager<br>Method or attribute name: function deletePersistentP2pGroup(netId: number): void;|@ohos.wifiManager.d.ts|
|Added|NA|Class name: wifiManager<br>Method or attribute name: function setP2pDeviceName(devName: string): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiBandType|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiBandType<br>Method or attribute name: WIFI_BAND_NONE|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiBandType<br>Method or attribute name: WIFI_BAND_2G|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiBandType<br>Method or attribute name: WIFI_BAND_5G|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiBandType<br>Method or attribute name: WIFI_BAND_6G|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiBandType<br>Method or attribute name: WIFI_BAND_60G|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiStandard|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiStandard<br>Method or attribute name: WIFI_STANDARD_UNDEFINED|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiStandard<br>Method or attribute name: WIFI_STANDARD_11A|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiStandard<br>Method or attribute name: WIFI_STANDARD_11B|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiStandard<br>Method or attribute name: WIFI_STANDARD_11G|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiStandard<br>Method or attribute name: WIFI_STANDARD_11N|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiStandard<br>Method or attribute name: WIFI_STANDARD_11AC|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiStandard<br>Method or attribute name: WIFI_STANDARD_11AX|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiStandard<br>Method or attribute name: WIFI_STANDARD_11AD|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiLinkedInfo<br>Method or attribute name: rxLinkSpeed: number;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiLinkedInfo<br>Method or attribute name: maxSupportedTxLinkSpeed: number;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiLinkedInfo<br>Method or attribute name: maxSupportedRxLinkSpeed: number;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiLinkedInfo<br>Method or attribute name: channelWidth: WifiChannelWidth;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiLinkedInfo<br>Method or attribute name: wifiStandard: WifiStandard;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: HotspotConfig<br>Method or attribute name: channel: number;|@ohos.wifiManager.d.ts|
|Deleted|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function getScanResults(): Promise\<Array\<WifiScanInfo>>;|NA|@ohos.wifiManager.d.ts|
|Deleted|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function getScanResults(callback: AsyncCallback\<Array\<WifiScanInfo>>): void;|NA|@ohos.wifiManager.d.ts|
|Deleted|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function getScanResultsSync(): Array\<WifiScanInfo>;|NA|@ohos.wifiManager.d.ts|
|Deleted|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function updateNetwork(config: WifiDeviceConfig): number;|NA|@ohos.wifiManager.d.ts|
|Deleted|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function disableNetwork(netId: number): void;|NA|@ohos.wifiManager.d.ts|
|Deleted|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function removeAllNetwork(): void;|NA|@ohos.wifiManager.d.ts|
|Deleted|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function removeDevice(id: number): void;|NA|@ohos.wifiManager.d.ts|
|Deleted|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function getStations(): Array\<StationInfo>;|NA|@ohos.wifiManager.d.ts|
|Deleted|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function getCurrentGroup(): Promise\<WifiP2pGroupInfo>;|NA|@ohos.wifiManager.d.ts|
|Deleted|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function getCurrentGroup(callback: AsyncCallback\<WifiP2pGroupInfo>): void;|NA|@ohos.wifiManager.d.ts|
|Deleted|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function createGroup(config: WifiP2PConfig): void;|NA|@ohos.wifiManager.d.ts|
|Deleted|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function removeGroup(): void;|NA|@ohos.wifiManager.d.ts|
|Deleted|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function startDiscoverDevices(): void;|NA|@ohos.wifiManager.d.ts|
|Deleted|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function stopDiscoverDevices(): void;|NA|@ohos.wifiManager.d.ts|
|Deleted|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function deletePersistentGroup(netId: number): void;|NA|@ohos.wifiManager.d.ts|
|Deleted|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function setDeviceName(devName: string): void;|NA|@ohos.wifiManager.d.ts|
|Permission changed|Class name: wifiManager<br>Method or attribute name: function scan(): void;<br>Permission: ohos.permission.SET_WIFI_INFO and ohos.permission.LOCATION|Class name: wifiManager<br>Method or attribute name: function scan(): void;<br>Permission: ohos.permission.SET_WIFI_INFO and ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION|@ohos.wifiManager.d.ts|
|Permission changed|Class name: wifiManager<br>Method or attribute name: function getCandidateConfigs(): Array\<WifiDeviceConfig>;<br>Permission: ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION|Class name: wifiManager<br>Method or attribute name: function getCandidateConfigs(): Array\<WifiDeviceConfig>;<br>Permission: ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION|@ohos.wifiManager.d.ts|
|Permission changed|Class name: wifiManager<br>Method or attribute name: function getDeviceConfigs(): Array\<WifiDeviceConfig>;<br>Permission: ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION and ohos.permission.GET_WIFI_CONFIG|Class name: wifiManager<br>Method or attribute name: function getDeviceConfigs(): Array\<WifiDeviceConfig>;<br>Permission: ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION and ohos.permission.GET_WIFI_CONFIG|@ohos.wifiManager.d.ts|
|Permission changed|Class name: wifiManager<br>Method or attribute name: function getP2pPeerDevices(): Promise\<WifiP2pDevice[]>;<br>Permission: ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION|Class name: wifiManager<br>Method or attribute name: function getP2pPeerDevices(): Promise\<WifiP2pDevice[]>;<br>Permission: ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION|@ohos.wifiManager.d.ts|
|Permission changed|Class name: wifiManager<br>Method or attribute name: function getP2pPeerDevices(callback: AsyncCallback\<WifiP2pDevice[]>): void;<br>Permission: ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION|Class name: wifiManager<br>Method or attribute name: function getP2pPeerDevices(callback: AsyncCallback\<WifiP2pDevice[]>): void;<br>Permission: ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION|@ohos.wifiManager.d.ts|
|Permission changed|Class name: wifiManager<br>Method or attribute name: function p2pConnect(config: WifiP2PConfig): void;<br>Permission: ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION|Class name: wifiManager<br>Method or attribute name: function p2pConnect(config: WifiP2PConfig): void;<br>Permission: ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION|@ohos.wifiManager.d.ts|
|Permission changed|Class name: wifiManager<br>Method or attribute name: function getP2pGroups(): Promise\<Array\<WifiP2pGroupInfo>>;<br>Permission: ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION|Class name: wifiManager<br>Method or attribute name: function getP2pGroups(): Promise\<Array\<WifiP2pGroupInfo>>;<br>Permission: ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION|@ohos.wifiManager.d.ts|
|Permission changed|Class name: wifiManager<br>Method or attribute name: function getP2pGroups(callback: AsyncCallback\<Array\<WifiP2pGroupInfo>>): void;<br>Permission: ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION|Class name: wifiManager<br>Method or attribute name: function getP2pGroups(callback: AsyncCallback\<Array\<WifiP2pGroupInfo>>): void;<br>Permission: ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION|@ohos.wifiManager.d.ts|
|Permission changed|Class name: wifiManager<br>Method or attribute name: function on(type: "p2pDeviceChange", callback: Callback\<WifiP2pDevice>): void;<br>Permission: ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION|Class name: wifiManager<br>Method or attribute name: function on(type: "p2pDeviceChange", callback: Callback\<WifiP2pDevice>): void;<br>Permission: ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION|@ohos.wifiManager.d.ts|
|Permission changed|Class name: wifiManager<br>Method or attribute name: function off(type: "p2pDeviceChange", callback?: Callback\<WifiP2pDevice>): void;<br>Permission: ohos.permission.LOCATION|Class name: wifiManager<br>Method or attribute name: function off(type: "p2pDeviceChange", callback?: Callback\<WifiP2pDevice>): void;<br>Permission: ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION|@ohos.wifiManager.d.ts|
|Permission changed|Class name: wifiManager<br>Method or attribute name: function on(type: "p2pPeerDeviceChange", callback: Callback\<WifiP2pDevice[]>): void;<br>Permission: ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION|Class name: wifiManager<br>Method or attribute name: function on(type: "p2pPeerDeviceChange", callback: Callback\<WifiP2pDevice[]>): void;<br>Permission: ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION|@ohos.wifiManager.d.ts|
|Permission changed|Class name: wifiManager<br>Method or attribute name: function off(type: "p2pPeerDeviceChange", callback?: Callback\<WifiP2pDevice[]>): void;<br>Permission: ohos.permission.LOCATION|Class name: wifiManager<br>Method or attribute name: function off(type: "p2pPeerDeviceChange", callback?: Callback\<WifiP2pDevice[]>): void;<br>Permission: ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION|@ohos.wifiManager.d.ts|
