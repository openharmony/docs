# 基础通信子系统JS API变更

OpenHarmony 3.1 Release版本相较于OpenHarmony 3.0 LTS版本，基础通信子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| tagSession | TagSession | getMaxSendLength(): number; | 新增 |
| tagSession | TagSession | sendData(data: number[]): Promise\<number[]>;<br>sendData(data: number[], callback: AsyncCallback\<number[]>): void; | 新增 |
| tagSession | TagSession | getSendDataTimeout(): number; | 新增 |
| tagSession | TagSession | setSendDataTimeout(timeout: number): boolean; | 新增 |
| tagSession | TagSession | isTagConnected(): boolean; | 新增 |
| tagSession | TagSession | reset(): void; | 新增 |
| tagSession | TagSession | connectTag(): boolean; | 新增 |
| tagSession | TagSession | getTagInfo(): tag.TagInfo; | 新增 |
| nfctech | NfcVTag | getDsfId(): number; | 新增 |
| nfctech | NfcVTag | getResponseFlags(): number; | 新增 |
| nfctech | NfcFTag | getPmm(): number[]; | 新增 |
| nfctech | NfcFTag | getSystemCode(): number[]; | 新增 |
| nfctech | NfcBTag | getRespProtocol(): number[]; | 新增 |
| nfctech | NfcBTag | getRespAppData(): number[]; | 新增 |
| nfctech | NfcATag | getAtqa(): number[]; | 新增 |
| nfctech | NfcATag | getSak(): number; | 新增 |
| ohos.wifiext | PowerModel | THROUGH_WALL = 2 | 新增 |
| ohos.wifiext | PowerModel | GENERAL = 1 | 新增 |
| ohos.wifiext | PowerModel | SLEEPING = 0 | 新增 |
| ohos.wifiext | wifiext | setPowerModel(model: PowerModel) : boolean | 新增 |
| ohos.wifiext | wifiext | getPowerModel (): Promise\<PowerModel>;<br>getPowerModel (callback: AsyncCallback\<PowerModel>): void; | 新增 |
| ohos.wifiext | wifiext | getSupportedPowerModel(): Promise\<Array\<PowerModel>>;<br>getSupportedPowerModel(callback: AsyncCallback\<Array\<PowerModel>>): void; | 新增 |
| ohos.wifiext | wifiext | disableHotspot(): boolean; | 新增 |
| ohos.wifiext | wifiext | enableHotspot(): boolean; | 新增 |
| ohos.wifi | GroupOwnerBand | GO_BAND_5GHZ = 2 | 新增 |
| ohos.wifi | GroupOwnerBand | GO_BAND_2GHZ = 1 | 新增 |
| ohos.wifi | GroupOwnerBand | GO_BAND_AUTO = 0 | 新增 |
| ohos.wifi | P2pDeviceStatus | UNAVAILABLE = 4 | 新增 |
| ohos.wifi | P2pDeviceStatus | AVAILABLE = 3 | 新增 |
| ohos.wifi | P2pDeviceStatus | FAILED = 2 | 新增 |
| ohos.wifi | P2pDeviceStatus | INVITED = 1 | 新增 |
| ohos.wifi | P2pDeviceStatus | CONNECTED = 0 | 新增 |
| ohos.wifi | WifiP2pLinkedInfo | groupOwnerAddr: string; | 新增 |
| ohos.wifi | WifiP2pLinkedInfo | isGroupOwner: boolean; | 新增 |
| ohos.wifi | WifiP2pLinkedInfo | connectState: P2pConnectState; | 新增 |
| ohos.wifi | P2pConnectState | CONNECTED = 1 | 新增 |
| ohos.wifi | P2pConnectState | DISCONNECTED = 0 | 新增 |
| ohos.wifi | WifiP2pGroupInfo | goIpAddress: string; | 新增 |
| ohos.wifi | WifiP2pGroupInfo | clientDevices: WifiP2pDevice[]; | 新增 |
| ohos.wifi | WifiP2pGroupInfo | frequency: number; | 新增 |
| ohos.wifi | WifiP2pGroupInfo | networkId: number; | 新增 |
| ohos.wifi | WifiP2pGroupInfo | groupName: string; | 新增 |
| ohos.wifi | WifiP2pGroupInfo | interface: string; | 新增 |
| ohos.wifi | WifiP2pGroupInfo | passphrase: string; | 新增 |
| ohos.wifi | WifiP2pGroupInfo | ownerInfo: WifiP2pDevice; | 新增 |
| ohos.wifi | WifiP2pGroupInfo | isP2pGo: boolean; | 新增 |
| ohos.wifi | WifiP2PConfig | goBand: GroupOwnerBand; | 新增 |
| ohos.wifi | WifiP2PConfig | groupName: string; | 新增 |
| ohos.wifi | WifiP2PConfig | passphrase: string; | 新增 |
| ohos.wifi | WifiP2PConfig | netId: number; | 新增 |
| ohos.wifi | WifiP2PConfig | deviceAddress: string; | 新增 |
| ohos.wifi | WifiP2pDevice | groupCapabilitys: number; | 新增 |
| ohos.wifi | WifiP2pDevice | deviceStatus: P2pDeviceStatus; | 新增 |
| ohos.wifi | WifiP2pDevice | primaryDeviceType: string; | 新增 |
| ohos.wifi | WifiP2pDevice | deviceAddress: string; | 新增 |
| ohos.wifi | WifiP2pDevice | deviceName: string; | 新增 |
| ohos.wifi | ConnState | UNKNOWN | 新增 |
| ohos.wifi | ConnState | DISCONNECTED | 新增 |
| ohos.wifi | ConnState | DISCONNECTING | 新增 |
| ohos.wifi | ConnState | CONNECTED | 新增 |
| ohos.wifi | ConnState | OBTAINING_IPADDR | 新增 |
| ohos.wifi | ConnState | AUTHENTICATING | 新增 |
| ohos.wifi | ConnState | CONNECTING | 新增 |
| ohos.wifi | ConnState | SCANNING | 新增 |
| ohos.wifi | IpInfo | leaseDuration: number; | 新增 |
| ohos.wifi | IpInfo | serverIp: number; | 新增 |
| ohos.wifi | IpInfo | secondDns: number; | 新增 |
| ohos.wifi | IpInfo | primaryDns: number; | 新增 |
| ohos.wifi | IpInfo | netmask: number; | 新增 |
| ohos.wifi | IpInfo | gateway: number; | 新增 |
| ohos.wifi | IpInfo | ipAddress: number; | 新增 |
| ohos.wifi | WifiLinkedInfo | connState: ConnState; | 新增 |
| ohos.wifi | WifiLinkedInfo | ipAddress: number; | 新增 |
| ohos.wifi | WifiLinkedInfo | macAddress: string; | 新增 |
| ohos.wifi | WifiLinkedInfo | isRestricted: boolean; | 新增 |
| ohos.wifi | WifiLinkedInfo | isHidden: boolean; | 新增 |
| ohos.wifi | WifiLinkedInfo | frequency: number; | 新增 |
| ohos.wifi | WifiLinkedInfo | linkSpeed: number; | 新增 |
| ohos.wifi | WifiLinkedInfo | band: number; | 新增 |
| ohos.wifi | WifiLinkedInfo | rssi: number; | 新增 |
| ohos.wifi | WifiLinkedInfo | bssid: string; | 新增 |
| ohos.wifi | WifiLinkedInfo | ssid: string; | 新增 |
| ohos.wifi | WifiScanInfo | channelWidth: number; | 新增 |
| ohos.wifi | WifiScanInfo | capabilities: string; | 新增 |
| ohos.wifi | wifi | off(type: "p2pDiscoveryChange", callback?: Callback\<number>): void; | 新增 |
| ohos.wifi | wifi | on(type: "p2pDiscoveryChange", callback: Callback\<number>): void; | 新增 |
| ohos.wifi | wifi | off(type: "p2pPersistentGroupChange", callback?: Callback\<void>): void; | 新增 |
| ohos.wifi | wifi | on(type: "p2pPersistentGroupChange", callback: Callback\<void>): void; | 新增 |
| ohos.wifi | wifi | off(type: "p2pPeerDeviceChange", callback?: Callback\<WifiP2pDevice[]>): void; | 新增 |
| ohos.wifi | wifi | on(type: "p2pPeerDeviceChange", callback: Callback\<WifiP2pDevice[]>): void; | 新增 |
| ohos.wifi | wifi | off(type: "p2pDeviceChange", callback?: Callback\<WifiP2pDevice>): void; | 新增 |
| ohos.wifi | wifi | on(type: "p2pDeviceChange", callback: Callback\<WifiP2pDevice>): void; | 新增 |
| ohos.wifi | wifi | off(type: "p2pConnectionChange", callback?: Callback\<WifiP2pLinkedInfo>): void; | 新增 |
| ohos.wifi | wifi | on(type: "p2pConnectionChange", callback: Callback\<WifiP2pLinkedInfo>): void; | 新增 |
| ohos.wifi | wifi | off(type: "p2pStateChange", callback?: Callback\<number>): void; | 新增 |
| ohos.wifi | wifi | on(type: "p2pStateChange", callback: Callback\<number>): void; | 新增 |
| ohos.wifi | wifi | off(type: "hotspotStateChange", callback?: Callback\<number>): void; | 新增 |
| ohos.wifi | wifi | on(type: "hotspotStateChange", callback: Callback\<number>): void; | 新增 |
| ohos.wifi | wifi | off(type: "wifiRssiChange", callback?: Callback\<number>): void; | 新增 |
| ohos.wifi | wifi | on(type: "wifiRssiChange", callback: Callback\<number>): void; | 新增 |
| ohos.wifi | wifi | off(type: "wifiScanStateChange", callback?: Callback\<number>): void; | 新增 |
| ohos.wifi | wifi | on(type: "wifiScanStateChange", callback: Callback\<number>): void; | 新增 |
| ohos.wifi | wifi | off(type: "wifiConnectionChange", callback?: Callback\<number>): void; | 新增 |
| ohos.wifi | wifi | on(type: "wifiConnectionChange", callback: Callback\<number>): void; | 新增 |
| ohos.wifi | wifi | off(type: "wifiStateChange", callback?: Callback\<number>): void; | 新增 |
| ohos.wifi | wifi | on(type: "wifiStateChange", callback: Callback\<number>): void; | 新增 |
| ohos.wifi | wifi | stopDiscoverDevices(): boolean; | 新增 |
| ohos.wifi | wifi | startDiscoverDevices(): boolean; | 新增 |
| ohos.wifi | wifi | p2pCancelConnect(): boolean; | 新增 |
| ohos.wifi | wifi | p2pConnect(config: WifiP2PConfig): boolean; | 新增 |
| ohos.wifi | wifi | removeGroup(): boolean; | 新增 |
| ohos.wifi | wifi | createGroup(config: WifiP2PConfig): boolean; | 新增 |
| ohos.wifi | wifi | getP2pPeerDevices(): Promise\<WifiP2pDevice[]>;<br>getP2pPeerDevices(callback: AsyncCallback\<WifiP2pDevice[]>): void; | 新增 |
| ohos.wifi | wifi | getCurrentGroup(): Promise\<WifiP2pGroupInfo>;<br>getCurrentGroup(callback: AsyncCallback\<WifiP2pGroupInfo>): void; | 新增 |
| ohos.wifi | wifi | getP2pLinkedInfo(): Promise\<WifiP2pLinkedInfo>;<br>getP2pLinkedInfo(callback: AsyncCallback\<WifiP2pLinkedInfo>): void; | 新增 |
| ohos.wifi | wifi | getCountryCode(): string; | 新增 |
| ohos.wifi | wifi | getIpInfo(): IpInfo; | 新增 |
| ohos.wifi | wifi | isFeatureSupported(featureId: number): boolean; | 新增 |
| ohos.wifi | wifi | isConnected(): boolean; | 新增 |
| ohos.wifi | wifi | getLinkedInfo(): Promise\<WifiLinkedInfo>;<br>getLinkedInfo(callback: AsyncCallback\<WifiLinkedInfo>): void; | 新增 |
| ohos.wifi | wifi | removeUntrustedConfig(config: WifiDeviceConfig): Promise\<boolean>;<br>removeUntrustedConfig(config: WifiDeviceConfig, callback: AsyncCallback\<boolean>): void; | 新增 |
| ohos.wifi | wifi | addUntrustedConfig(config: WifiDeviceConfig): Promise\<boolean>;<br>addUntrustedConfig(config: WifiDeviceConfig, callback: AsyncCallback\<boolean>): void; | 新增 |
| ohos.nfc.tag | TagInfo | supportedProfiles: number[]; | 新增 |
| ohos.nfc.tag | tag | getNfcVTag(tagInfo: TagInfo): NfcVTag | 新增 |
| ohos.nfc.tag | tag | getNfcFTag(tagInfo: TagInfo): NfcFTag | 新增 |
| ohos.nfc.tag | tag | getNfcBTag(tagInfo: TagInfo): NfcBTag | 新增 |
| ohos.nfc.tag | tag | getNfcATag(tagInfo: TagInfo): NfcATag | 新增 |
| ohos.nfc.tag | tag | const MIFARE_ULTRALIGHT = 9; | 新增 |
| ohos.nfc.tag | tag | const MIFARE_CLASSIC = 8; | 新增 |
| ohos.nfc.tag | tag | const NDEF = 6; | 新增 |
| ohos.nfc.tag | tag | const NFC_V = 5; | 新增 |
| ohos.nfc.tag | tag | const NFC_F = 4; | 新增 |
| ohos.nfc.tag | tag | const ISO_DEP = 3; | 新增 |
| ohos.nfc.tag | tag | const NFC_B = 2; | 新增 |
| ohos.nfc.tag | tag | const NFC_A = 1; | 新增 |
| ohos.nfc.controller | nfcController | getNfcState(): NfcState | 新增 |
| ohos.nfc.controller | nfcController | isNfcOpen(): boolean | 新增 |
| ohos.nfc.controller | nfcController | closeNfc(): boolean | 新增 |
| ohos.nfc.controller | nfcController | openNfc(): boolean | 新增 |
| ohos.nfc.controller | nfcController | off(type: "nfcStateChange", callback?: Callback\<NfcState>): void | 新增 |
| ohos.nfc.controller | nfcController | on(type: "nfcStateChange", callback: Callback\<NfcState>): void | 新增 |
| ohos.nfc.controller | nfcController | isNfcAvailable(): boolean | 新增 |
| ohos.nfc.controller | NfcState | STATE_TURNING_OFF = 4 | 新增 |
| ohos.nfc.controller | NfcState | STATE_ON = 3 | 新增 |
| ohos.nfc.controller | NfcState | STATE_TURNING_ON = 2 | 新增 |
| ohos.nfc.controller | NfcState | STATE_OFF = 1 | 新增 |
| ohos.nfc.cardEmulation | HceService | sendResponse(responseApdu: number[]): void; | 新增 |
| ohos.nfc.cardEmulation | HceService | on(type: "hceCmd", callback: AsyncCallback\<number[]>): void; | 新增 |
| ohos.nfc.cardEmulation | HceService | stopHCE(): boolean; | 新增 |
| ohos.nfc.cardEmulation | HceService | startHCE(aidList: string[]): boolean; | 新增 |
| ohos.nfc.cardEmulation | cardEmulation | isSupported(feature: number): boolean; | 新增 |
| ohos.nfc.cardEmulation | FeatureType | ESE = 2 | 新增 |
| ohos.nfc.cardEmulation | FeatureType | UICC = 1 | 新增 |
| ohos.nfc.cardEmulation | FeatureType | HCE = 0 | 新增 |
| ohos.connectedTag | NfcRfType | NFC_RF_ENTER = 1 | 新增 |
| ohos.connectedTag | NfcRfType | NFC_RF_LEAVE = 0 | 新增 |
| ohos.connectedTag | connectedTag | off(type: "notify", callback?:Callback\<number>): void; | 新增 |
| ohos.connectedTag | connectedTag | on(type: "notify", callback: Callback\<number>): void; | 新增 |
| ohos.connectedTag | connectedTag | writeNdefTag(data: string): Promise\<void>;<br>writeNdefTag(data: string, callback: AsyncCallback\<void>): void; | 新增 |
| ohos.connectedTag | connectedTag | readNdefTag(): Promise\<string>;<br>readNdefTag(callback: AsyncCallback\<string>): void; | 新增 |
| ohos.connectedTag | connectedTag | uninit(): boolean; | 新增 |
| ohos.connectedTag | connectedTag | init(): boolean; | 新增 |
| ohos.bluetooth | ProfileId | PROFILE_HANDS_FREE_AUDIO_GATEWAY = 4 | 新增 |
| ohos.bluetooth | ProfileId | PROFILE_A2DP_SOURCE = 1 | 新增 |
| ohos.bluetooth | PlayingState | STATE_PLAYING | 新增 |
| ohos.bluetooth | PlayingState | STATE_NOT_PLAYING | 新增 |
| ohos.bluetooth | StateChangeParam | state: ProfileConnectionState; | 新增 |
| ohos.bluetooth | StateChangeParam | deviceId: string; | 新增 |
| ohos.bluetooth | MajorMinorClass | HEALTH_PERSONAL_MOBILITY_DEVICE = 0x093C | 新增 |
| ohos.bluetooth | MajorMinorClass | HEALTH_GENERIC_HEALTH_MANAGER = 0x0938 | 新增 |
| ohos.bluetooth | MajorMinorClass | HEALTH_ANKLE_PROSTHESIS = 0x0934 | 新增 |
| ohos.bluetooth | MajorMinorClass | HEALTH_KNEE_PROSTHESIS = 0x0930 | 新增 |
| ohos.bluetooth | MajorMinorClass | HEALTH_MEDICATION_MONITOR = 0x092C | 新增 |
| ohos.bluetooth | MajorMinorClass | HEALTH_PEAK_FLOW_MOITOR = 0x0928 | 新增 |
| ohos.bluetooth | MajorMinorClass | HEALTH_BODY_COMPOSITION_ANALYZER = 0x0924 | 新增 |
| ohos.bluetooth | MajorMinorClass | HEALTH_STEP_COUNTER = 0x0920 | 新增 |
| ohos.bluetooth | MajorMinorClass | HEALTH_DATA_DISPLAY = 0x091C | 新增 |
| ohos.bluetooth | MajorMinorClass | HEALTH_PULSE_RATE = 0x0918 | 新增 |
| ohos.bluetooth | MajorMinorClass | HEALTH_PULSE_OXIMETER = 0x0914 | 新增 |
| ohos.bluetooth | MajorMinorClass | HEALTH_GLUCOSE = 0x0910 | 新增 |
| ohos.bluetooth | MajorMinorClass | HEALTH_WEIGHING = 0x090C | 新增 |
| ohos.bluetooth | MajorMinorClass | HEALTH_THERMOMETER = 0x0908 | 新增 |
| ohos.bluetooth | MajorMinorClass | HEALTH_BLOOD_PRESSURE = 0x0904 | 新增 |
| ohos.bluetooth | MajorMinorClass | HEALTH_UNCATEGORIZED = 0x0900 | 新增 |
| ohos.bluetooth | MajorMinorClass | TOY_GAME = 0x0814 | 新增 |
| ohos.bluetooth | MajorMinorClass | TOY_CONTROLLER = 0x0810 | 新增 |
| ohos.bluetooth | MajorMinorClass | TOY_DOLL_ACTION_FIGURE = 0x080C | 新增 |
| ohos.bluetooth | MajorMinorClass | TOY_VEHICLE = 0x0808 | 新增 |
| ohos.bluetooth | MajorMinorClass | TOY_ROBOT = 0x0804 | 新增 |
| ohos.bluetooth | MajorMinorClass | TOY_UNCATEGORIZED = 0x0800 | 新增 |
| ohos.bluetooth | MajorMinorClass | WEARABLE_GLASSES = 0x0714 | 新增 |
| ohos.bluetooth | MajorMinorClass | WEARABLE_HELMET = 0x0710 | 新增 |
| ohos.bluetooth | MajorMinorClass | WEARABLE_JACKET = 0x070C | 新增 |
| ohos.bluetooth | MajorMinorClass | WEARABLE_PAGER = 0x0708 | 新增 |
| ohos.bluetooth | MajorMinorClass | WEARABLE_WRIST_WATCH = 0x0704 | 新增 |
| ohos.bluetooth | MajorMinorClass | WEARABLE_UNCATEGORIZED = 0x0700 | 新增 |
| ohos.bluetooth | MajorMinorClass | IMAGING_PRINTER = 0x0680 | 新增 |
| ohos.bluetooth | MajorMinorClass | IMAGING_SCANNER = 0x0640 | 新增 |
| ohos.bluetooth | MajorMinorClass | IMAGING_CAMERA = 0x0620 | 新增 |
| ohos.bluetooth | MajorMinorClass | IMAGING_DISPLAY = 0x0610 | 新增 |
| ohos.bluetooth | MajorMinorClass | IMAGING_UNCATEGORIZED = 0x0600 | 新增 |
| ohos.bluetooth | MajorMinorClass | PERIPHERAL_GESTURAL_INPUT = 0x0522 | 新增 |
| ohos.bluetooth | MajorMinorClass | PERIPHERAL_SCANNER_RFID = 0x0520 | 新增 |
| ohos.bluetooth | MajorMinorClass | PERIPHERAL_DIGITAL_PEN = 0x051C | 新增 |
| ohos.bluetooth | MajorMinorClass | PERIPHERAL_CARD_READER = 0x0518 | 新增 |
| ohos.bluetooth | MajorMinorClass | PERIPHERAL_DIGITIZER_TABLET = 0x0514 | 新增 |
| ohos.bluetooth | MajorMinorClass | PERIPHERAL_SENSING_DEVICE = 0x0510 | 新增 |
| ohos.bluetooth | MajorMinorClass | PERIPHERAL_REMOTE_CONTROL = 0x05C0 | 新增 |
| ohos.bluetooth | MajorMinorClass | PERIPHERAL_GAMEPAD = 0x0508 | 新增 |
| ohos.bluetooth | MajorMinorClass | PERIPHERAL_JOYSTICK = 0x0504 | 新增 |
| ohos.bluetooth | MajorMinorClass | PERIPHERAL_UNCATEGORIZED = 0x0500 | 新增 |
| ohos.bluetooth | MajorMinorClass | PERIPHERAL_KEYBOARD_POINTING = 0x05C0 | 新增 |
| ohos.bluetooth | MajorMinorClass | PERIPHERAL_POINTING_DEVICE = 0x0580 | 新增 |
| ohos.bluetooth | MajorMinorClass | PERIPHERAL_KEYBOARD = 0x0540 | 新增 |
| ohos.bluetooth | MajorMinorClass | PERIPHERAL_NON_KEYBOARD_NON_POINTING = 0x0500 | 新增 |
| ohos.bluetooth | MajorMinorClass | AUDIO_VIDEO_VIDEO_GAMING_TOY = 0x0448 | 新增 |
| ohos.bluetooth | MajorMinorClass | AUDIO_VIDEO_VIDEO_CONFERENCING = 0x0440 | 新增 |
| ohos.bluetooth | MajorMinorClass | AUDIO_VIDEO_VIDEO_DISPLAY_AND_LOUDSPEAKER = 0x043C | 新增 |
| ohos.bluetooth | MajorMinorClass | AUDIO_VIDEO_VIDEO_MONITOR = 0x0438 | 新增 |
| ohos.bluetooth | MajorMinorClass | AUDIO_VIDEO_CAMCORDER = 0x0434 | 新增 |
| ohos.bluetooth | MajorMinorClass | AUDIO_VIDEO_VIDEO_CAMERA = 0x0430 | 新增 |
| ohos.bluetooth | MajorMinorClass | AUDIO_VIDEO_VCR = 0x042C | 新增 |
| ohos.bluetooth | MajorMinorClass | AUDIO_VIDEO_HIFI_AUDIO = 0x0428 | 新增 |
| ohos.bluetooth | MajorMinorClass | AUDIO_VIDEO_SET_TOP_BOX = 0x0424 | 新增 |
| ohos.bluetooth | MajorMinorClass | AUDIO_VIDEO_CAR_AUDIO = 0x0420 | 新增 |
| ohos.bluetooth | MajorMinorClass | AUDIO_VIDEO_PORTABLE_AUDIO = 0x041C | 新增 |
| ohos.bluetooth | MajorMinorClass | AUDIO_VIDEO_HEADPHONES = 0x0418 | 新增 |
| ohos.bluetooth | MajorMinorClass | AUDIO_VIDEO_LOUDSPEAKER = 0x0414 | 新增 |
| ohos.bluetooth | MajorMinorClass | AUDIO_VIDEO_MICROPHONE = 0x0410 | 新增 |
| ohos.bluetooth | MajorMinorClass | AUDIO_VIDEO_HANDSFREE = 0x0408 | 新增 |
| ohos.bluetooth | MajorMinorClass | AUDIO_VIDEO_WEARABLE_HEADSET = 0x0404 | 新增 |
| ohos.bluetooth | MajorMinorClass | AUDIO_VIDEO_UNCATEGORIZED = 0x0400 | 新增 |
| ohos.bluetooth | MajorMinorClass | NETWORK_NO_SERVICE = 0x03E0 | 新增 |
| ohos.bluetooth | MajorMinorClass | NETWORK_83_TO_99_UTILIZED = 0x03C0 | 新增 |
| ohos.bluetooth | MajorMinorClass | NETWORK_67_TO_83_UTILIZED = 0x03A0 | 新增 |
| ohos.bluetooth | MajorMinorClass | NETWORK_60_TO_67_UTILIZED = 0x0380 | 新增 |
| ohos.bluetooth | MajorMinorClass | NETWORK_33_TO_50_UTILIZED = 0x0360 | 新增 |
| ohos.bluetooth | MajorMinorClass | NETWORK_17_TO_33_UTILIZED = 0x0340 | 新增 |
| ohos.bluetooth | MajorMinorClass | NETWORK_1_TO_17_UTILIZED = 0x0320 | 新增 |
| ohos.bluetooth | MajorMinorClass | NETWORK_FULLY_AVAILABLE = 0x0300 | 新增 |
| ohos.bluetooth | MajorMinorClass | PHONE_ISDN = 0x0214 | 新增 |
| ohos.bluetooth | MajorMinorClass | PHONE_MODEM_OR_GATEWAY = 0x0210 | 新增 |
| ohos.bluetooth | MajorMinorClass | PHONE_SMART = 0x020C | 新增 |
| ohos.bluetooth | MajorMinorClass | PHONE_CORDLESS = 0x0208 | 新增 |
| ohos.bluetooth | MajorMinorClass | PHONE_CELLULAR = 0x0204 | 新增 |
| ohos.bluetooth | MajorMinorClass | PHONE_UNCATEGORIZED = 0x0200 | 新增 |
| ohos.bluetooth | MajorMinorClass | COMPUTER_TABLET = 0x011C | 新增 |
| ohos.bluetooth | MajorMinorClass | COMPUTER_WEARABLE = 0x0118 | 新增 |
| ohos.bluetooth | MajorMinorClass | COMPUTER_PALM_SIZE_PC_PDA = 0x0114 | 新增 |
| ohos.bluetooth | MajorMinorClass | COMPUTER_HANDHELD_PC_PDA = 0x0110 | 新增 |
| ohos.bluetooth | MajorMinorClass | COMPUTER_LAPTOP = 0x010C | 新增 |
| ohos.bluetooth | MajorMinorClass | COMPUTER_SERVER = 0x0108 | 新增 |
| ohos.bluetooth | MajorMinorClass | COMPUTER_DESKTOP = 0x0104 | 新增 |
| ohos.bluetooth | MajorMinorClass | COMPUTER_UNCATEGORIZED = 0x0100 | 新增 |
| ohos.bluetooth | MajorClass | MAJOR_UNCATEGORIZED = 0x1F00 | 新增 |
| ohos.bluetooth | MajorClass | MAJOR_HEALTH = 0x0900 | 新增 |
| ohos.bluetooth | MajorClass | MAJOR_TOY = 0x0800 | 新增 |
| ohos.bluetooth | MajorClass | MAJOR_WEARABLE = 0x0700 | 新增 |
| ohos.bluetooth | MajorClass | MAJOR_IMAGING = 0x0600 | 新增 |
| ohos.bluetooth | MajorClass | MAJOR_PERIPHERAL = 0x0500 | 新增 |
| ohos.bluetooth | MajorClass | MAJOR_AUDIO_VIDEO = 0x0400 | 新增 |
| ohos.bluetooth | MajorClass | MAJOR_NETWORKING = 0x0300 | 新增 |
| ohos.bluetooth | MajorClass | MAJOR_PHONE = 0x0200 | 新增 |
| ohos.bluetooth | MajorClass | MAJOR_COMPUTER = 0x0100 | 新增 |
| ohos.bluetooth | MajorClass | MAJOR_MISC = 0x0000 | 新增 |
| ohos.bluetooth | BondState | BOND_STATE_BONDED = 2 | 新增 |
| ohos.bluetooth | BondState | BOND_STATE_BONDING = 1 | 新增 |
| ohos.bluetooth | BondState | BOND_STATE_INVALID = 0 | 新增 |
| ohos.bluetooth | ScanMode | SCAN_MODE_CONNECTABLE_LIMITED_DISCOVERABLE = 5 | 新增 |
| ohos.bluetooth | ScanMode | SCAN_MODE_CONNECTABLE_GENERAL_DISCOVERABLE = 4 | 新增 |
| ohos.bluetooth | ScanMode | SCAN_MODE_LIMITED_DISCOVERABLE = 3 | 新增 |
| ohos.bluetooth | ScanMode | SCAN_MODE_GENERAL_DISCOVERABLE = 2 | 新增 |
| ohos.bluetooth | ScanMode | SCAN_MODE_CONNECTABLE = 1 | 新增 |
| ohos.bluetooth | ScanMode | SCAN_MODE_NONE = 0 | 新增 |
| ohos.bluetooth | SppType | SPP_RFCOMM | 新增 |
| ohos.bluetooth | BluetoothState | STATE_BLE_TURNING_OFF = 6 | 新增 |
| ohos.bluetooth | BluetoothState | STATE_BLE_ON = 5 | 新增 |
| ohos.bluetooth | BluetoothState | STATE_BLE_TURNING_ON = 4 | 新增 |
| ohos.bluetooth | BluetoothState | STATE_TURNING_OFF = 3 | 新增 |
| ohos.bluetooth | BluetoothState | STATE_ON = 2 | 新增 |
| ohos.bluetooth | BluetoothState | STATE_TURNING_ON = 1 | 新增 |
| ohos.bluetooth | BluetoothState | STATE_OFF = 0 | 新增 |
| ohos.bluetooth | ProfileConnectionState | STATE_DISCONNECTING = 3 | 新增 |
| ohos.bluetooth | ProfileConnectionState | STATE_CONNECTED = 2 | 新增 |
| ohos.bluetooth | ProfileConnectionState | STATE_CONNECTING = 1 | 新增 |
| ohos.bluetooth | ProfileConnectionState | STATE_DISCONNECTED = 0 | 新增 |
| ohos.bluetooth | MatchMode | MATCH_MODE_STICKY = 2 | 新增 |
| ohos.bluetooth | MatchMode | MATCH_MODE_AGGRESSIVE = 1 | 新增 |
| ohos.bluetooth | ScanDuty | SCAN_MODE_LOW_LATENCY = 2 | 新增 |
| ohos.bluetooth | ScanDuty | SCAN_MODE_BALANCED = 1 | 新增 |
| ohos.bluetooth | ScanDuty | SCAN_MODE_LOW_POWER = 0 | 新增 |
| ohos.bluetooth | BondStateParam | state: BondState; | 新增 |
| ohos.bluetooth | BondStateParam | deviceId: string; | 新增 |
| ohos.bluetooth | DeviceClass | classOfDevice: number; | 新增 |
| ohos.bluetooth | DeviceClass | majorMinorClass: MajorMinorClass; | 新增 |
| ohos.bluetooth | DeviceClass | majorClass: MajorClass; | 新增 |
| ohos.bluetooth | PinRequiredParam | pinCode: string; | 新增 |
| ohos.bluetooth | PinRequiredParam | deviceId: string; | 新增 |
| ohos.bluetooth | SppOption | type: SppType; | 新增 |
| ohos.bluetooth | SppOption | secure: boolean; | 新增 |
| ohos.bluetooth | SppOption | uuid: string; | 新增 |
| ohos.bluetooth | ScanOptions | matchMode?: MatchMode; | 新增 |
| ohos.bluetooth | ScanOptions | dutyMode?: ScanDuty; | 新增 |
| ohos.bluetooth | ScanOptions | interval?: number; | 新增 |
| ohos.bluetooth | ScanFilter | serviceUuid?: string; | 新增 |
| ohos.bluetooth | ScanFilter | name?: string; | 新增 |
| ohos.bluetooth | ScanFilter | deviceId?: string; | 新增 |
| ohos.bluetooth | ServiceData | serviceValue: ArrayBuffer; | 新增 |
| ohos.bluetooth | ServiceData | serviceUuid: string; | 新增 |
| ohos.bluetooth | ManufactureData | manufactureValue: ArrayBuffer; | 新增 |
| ohos.bluetooth | ManufactureData | manufactureId: number; | 新增 |
| ohos.bluetooth | AdvertiseData | serviceData: Array\<ServiceData>; | 新增 |
| ohos.bluetooth | AdvertiseData | manufactureData: Array\<ManufactureData>; | 新增 |
| ohos.bluetooth | AdvertiseData | serviceUuids: Array\<string>; | 新增 |
| ohos.bluetooth | AdvertiseSetting | connectable?: boolean; | 新增 |
| ohos.bluetooth | AdvertiseSetting | txPower?: number; | 新增 |
| ohos.bluetooth | AdvertiseSetting | interval?: number; | 新增 |
| ohos.bluetooth | ScanResult | data: ArrayBuffer; | 新增 |
| ohos.bluetooth | ScanResult | rssi: number; | 新增 |
| ohos.bluetooth | ScanResult | deviceId: string; | 新增 |
| ohos.bluetooth | BLEConnectChangedState | state: ProfileConnectionState; | 新增 |
| ohos.bluetooth | BLEConnectChangedState | deviceId: string; | 新增 |
| ohos.bluetooth | ServerResponse | value: ArrayBuffer; | 新增 |
| ohos.bluetooth | ServerResponse | offset: number; | 新增 |
| ohos.bluetooth | ServerResponse | status: number; | 新增 |
| ohos.bluetooth | ServerResponse | transId: number; | 新增 |
| ohos.bluetooth | ServerResponse | deviceId: string; | 新增 |
| ohos.bluetooth | DescriptorWriteReq | serviceUuid: string; | 新增 |
| ohos.bluetooth | DescriptorWriteReq | characteristicUuid: string; | 新增 |
| ohos.bluetooth | DescriptorWriteReq | descriptorUuid: string; | 新增 |
| ohos.bluetooth | DescriptorWriteReq | value: ArrayBuffer; | 新增 |
| ohos.bluetooth | DescriptorWriteReq | needRsp: boolean; | 新增 |
| ohos.bluetooth | DescriptorWriteReq | isPrep: boolean; | 新增 |
| ohos.bluetooth | DescriptorWriteReq | offset: number; | 新增 |
| ohos.bluetooth | DescriptorWriteReq | transId: number; | 新增 |
| ohos.bluetooth | DescriptorWriteReq | deviceId: string; | 新增 |
| ohos.bluetooth | DescriptorReadReq | serviceUuid: string; | 新增 |
| ohos.bluetooth | DescriptorReadReq | characteristicUuid: string; | 新增 |
| ohos.bluetooth | DescriptorReadReq | descriptorUuid: string; | 新增 |
| ohos.bluetooth | DescriptorReadReq | offset: number; | 新增 |
| ohos.bluetooth | DescriptorReadReq | transId: number; | 新增 |
| ohos.bluetooth | DescriptorReadReq | deviceId: string; | 新增 |
| ohos.bluetooth | CharacteristicWriteReq | serviceUuid: string; | 新增 |
| ohos.bluetooth | CharacteristicWriteReq | characteristicUuid: string; | 新增 |
| ohos.bluetooth | CharacteristicWriteReq | value: ArrayBuffer; | 新增 |
| ohos.bluetooth | CharacteristicWriteReq | needRsp: boolean; | 新增 |
| ohos.bluetooth | CharacteristicWriteReq | isPrep: boolean; | 新增 |
| ohos.bluetooth | CharacteristicWriteReq | offset: number; | 新增 |
| ohos.bluetooth | CharacteristicWriteReq | transId: number; | 新增 |
| ohos.bluetooth | CharacteristicWriteReq | deviceId: string; | 新增 |
| ohos.bluetooth | CharacteristicReadReq | serviceUuid: string; | 新增 |
| ohos.bluetooth | CharacteristicReadReq | characteristicUuid: string; | 新增 |
| ohos.bluetooth | CharacteristicReadReq | offset: number; | 新增 |
| ohos.bluetooth | CharacteristicReadReq | transId: number; | 新增 |
| ohos.bluetooth | CharacteristicReadReq | deviceId: string; | 新增 |
| ohos.bluetooth | NotifyCharacteristic | confirm: boolean; | 新增 |
| ohos.bluetooth | NotifyCharacteristic | characteristicValue: ArrayBuffer; | 新增 |
| ohos.bluetooth | NotifyCharacteristic | characteristicUuid: string; | 新增 |
| ohos.bluetooth | NotifyCharacteristic | serviceUuid: string; | 新增 |
| ohos.bluetooth | BLEDescriptor | descriptorValue: ArrayBuffer; | 新增 |
| ohos.bluetooth | BLEDescriptor | descriptorUuid: string; | 新增 |
| ohos.bluetooth | BLEDescriptor | characteristicUuid: string; | 新增 |
| ohos.bluetooth | BLEDescriptor | serviceUuid: string; | 新增 |
| ohos.bluetooth | BLECharacteristic | descriptors: Array\<BLEDescriptor>; | 新增 |
| ohos.bluetooth | BLECharacteristic | characteristicValue: ArrayBuffer; | 新增 |
| ohos.bluetooth | BLECharacteristic | characteristicUuid: string; | 新增 |
| ohos.bluetooth | BLECharacteristic | serviceUuid: string; | 新增 |
| ohos.bluetooth | GattService | includeServices?: Array\<GattService>; | 新增 |
| ohos.bluetooth | GattService | characteristics: Array\<BLECharacteristic>; | 新增 |
| ohos.bluetooth | GattService | isPrimary: boolean; | 新增 |
| ohos.bluetooth | GattService | serviceUuid: string; | 新增 |
| ohos.bluetooth | GattClientDevice | off(type: "BLEConnectionStateChange", callback?: Callback\<BLEConnectChangedState>): void; | 新增 |
| ohos.bluetooth | GattClientDevice | on(type: "BLEConnectionStateChange", callback: Callback\<BLEConnectChangedState>): void; | 新增 |
| ohos.bluetooth | GattClientDevice | off(type: "BLECharacteristicChange", callback?: Callback\<BLECharacteristic>): void; | 新增 |
| ohos.bluetooth | GattClientDevice | on(type: "BLECharacteristicChange", callback: Callback\<BLECharacteristic>): void; | 新增 |
| ohos.bluetooth | GattClientDevice | setNotifyCharacteristicChanged(characteristic: BLECharacteristic, enable: boolean): boolean; | 新增 |
| ohos.bluetooth | GattClientDevice | setBLEMtuSize(mtu: number): boolean; | 新增 |
| ohos.bluetooth | GattClientDevice | getRssiValue(callback: AsyncCallback\<number>): void;<br>getRssiValue(): Promise\<number>; | 新增 |
| ohos.bluetooth | GattClientDevice | writeDescriptorValue(descriptor: BLEDescriptor): boolean; | 新增 |
| ohos.bluetooth | GattClientDevice | writeCharacteristicValue(characteristic: BLECharacteristic): boolean; | 新增 |
| ohos.bluetooth | GattClientDevice | readDescriptorValue(descriptor: BLEDescriptor, callback: AsyncCallback\<BLEDescriptor>): void;<br>readDescriptorValue(descriptor: BLEDescriptor): Promise\<BLEDescriptor>; | 新增 |
| ohos.bluetooth | GattClientDevice | readCharacteristicValue(characteristic: BLECharacteristic, callback: AsyncCallback\<BLECharacteristic>): void;<br>readCharacteristicValue(characteristic: BLECharacteristic): Promise\<BLECharacteristic>; | 新增 |
| ohos.bluetooth | GattClientDevice | getServices(callback: AsyncCallback\<Array\<GattService>>): void;<br>getServices(): Promise\<Array\<GattService>>; | 新增 |
| ohos.bluetooth | GattClientDevice | getDeviceName(callback: AsyncCallback\<string>): void;<br>getDeviceName(): Promise\<string>; | 新增 |
| ohos.bluetooth | GattClientDevice | close(): boolean; | 新增 |
| ohos.bluetooth | GattClientDevice | disconnect(): boolean; | 新增 |
| ohos.bluetooth | GattClientDevice | connect(): boolean; | 新增 |
| ohos.bluetooth | GattServer | off(type: "connectStateChange", callback?: Callback\<BLEConnectChangedState>): void; | 新增 |
| ohos.bluetooth | GattServer | on(type: "connectStateChange", callback: Callback\<BLEConnectChangedState>): void; | 新增 |
| ohos.bluetooth | GattServer | off(type: "descriptorWrite", callback?: Callback\<DescriptorWriteReq>): void; | 新增 |
| ohos.bluetooth | GattServer | on(type: "descriptorWrite", callback: Callback\<DescriptorWriteReq>): void; | 新增 |
| ohos.bluetooth | GattServer | off(type: "descriptorRead", callback?: Callback\<DescriptorReadReq>): void; | 新增 |
| ohos.bluetooth | GattServer | on(type: "descriptorRead", callback: Callback\<DescriptorReadReq>): void; | 新增 |
| ohos.bluetooth | GattServer | off(type: "characteristicWrite", callback?: Callback\<CharacteristicWriteReq>): void; | 新增 |
| ohos.bluetooth | GattServer | on(type: "characteristicWrite", callback: Callback\<CharacteristicWriteReq>): void; | 新增 |
| ohos.bluetooth | GattServer | off(type: "characteristicRead", callback?: Callback\<CharacteristicReadReq>): void; | 新增 |
| ohos.bluetooth | GattServer | on(type: "characteristicRead", callback: Callback\<CharacteristicReadReq>): void; | 新增 |
| ohos.bluetooth | GattServer | sendResponse(serverResponse: ServerResponse): boolean; | 新增 |
| ohos.bluetooth | GattServer | notifyCharacteristicChanged(deviceId: string, notifyCharacteristic: NotifyCharacteristic): boolean; | 新增 |
| ohos.bluetooth | GattServer | close(): void; | 新增 |
| ohos.bluetooth | GattServer | removeService(serviceUuid: string): boolean; | 新增 |
| ohos.bluetooth | GattServer | addService(service: GattService): boolean; | 新增 |
| ohos.bluetooth | GattServer | stopAdvertising(): void; | 新增 |
| ohos.bluetooth | GattServer | startAdvertising(setting: AdvertiseSetting, advData: AdvertiseData, advResponse?: AdvertiseData): void; | 新增 |
| ohos.bluetooth | BLE | off(type: "BLEDeviceFind", callback?: Callback\<Array\<ScanResult>>): void; | 新增 |
| ohos.bluetooth | BLE | on(type: "BLEDeviceFind", callback: Callback\<Array\<ScanResult>>): void; | 新增 |
| ohos.bluetooth | BLE | stopBLEScan(): void; | 新增 |
| ohos.bluetooth | BLE | startBLEScan(filters: Array\<ScanFilter>, options?: ScanOptions): void; | 新增 |
| ohos.bluetooth | BLE | getConnectedBLEDevices(): Array\<string>; | 新增 |
| ohos.bluetooth | BLE | createGattClientDevice(deviceId: string): GattClientDevice; | 新增 |
| ohos.bluetooth | BLE | createGattServer(): GattServer; | 新增 |
| ohos.bluetooth | HandsFreeAudioGatewayProfile | off(type: "connectionStateChange", callback?: Callback\<StateChangeParam>): void; | 新增 |
| ohos.bluetooth | HandsFreeAudioGatewayProfile | on(type: "connectionStateChange", callback: Callback\<StateChangeParam>): void; | 新增 |
| ohos.bluetooth | HandsFreeAudioGatewayProfile | disconnect(device: string): boolean; | 新增 |
| ohos.bluetooth | HandsFreeAudioGatewayProfile | connect(device: string): boolean; | 新增 |
| ohos.bluetooth | A2dpSourceProfile | getPlayingState(device: string): PlayingState; | 新增 |
| ohos.bluetooth | A2dpSourceProfile | off(type: "connectionStateChange", callback?: Callback\<StateChangeParam>): void; | 新增 |
| ohos.bluetooth | A2dpSourceProfile | on(type: "connectionStateChange", callback: Callback\<StateChangeParam>): void; | 新增 |
| ohos.bluetooth | A2dpSourceProfile | disconnect(device: string): boolean; | 新增 |
| ohos.bluetooth | A2dpSourceProfile | connect(device: string): boolean; | 新增 |
| ohos.bluetooth | BaseProfile | getDeviceState(device: string): ProfileConnectionState; | 新增 |
| ohos.bluetooth | BaseProfile | getConnectionDevices(): Array\<string>; | 新增 |
| ohos.bluetooth | bluetooth | getProfile(profileId: ProfileId): A2dpSourceProfile \| HandsFreeAudioGatewayProfile; | 新增 |
| ohos.bluetooth | bluetooth | off(type: "sppRead", clientSocket: number, callback?: Callback\<ArrayBuffer>): void; | 新增 |
| ohos.bluetooth | bluetooth | on(type: "sppRead", clientSocket: number, callback: Callback\<ArrayBuffer>): void; | 新增 |
| ohos.bluetooth | bluetooth | sppWrite(clientSocket: number, data: ArrayBuffer): boolean; | 新增 |
| ohos.bluetooth | bluetooth | sppCloseClientSocket(socket: number): void; | 新增 |
| ohos.bluetooth | bluetooth | sppCloseServerSocket(socket: number): void; | 新增 |
| ohos.bluetooth | bluetooth | sppConnect(device: string, option: SppOption, callback: AsyncCallback\<number>): void; | 新增 |
| ohos.bluetooth | bluetooth | sppAccept(serverSocket: number, callback: AsyncCallback\<number>): void; | 新增 |
| ohos.bluetooth | bluetooth | sppListen(name: string, option: SppOption, callback: AsyncCallback\<number>): void; | 新增 |
| ohos.bluetooth | bluetooth | off(type: "stateChange", callback?: Callback\<BluetoothState>): void; | 新增 |
| ohos.bluetooth | bluetooth | on(type: "stateChange", callback: Callback\<BluetoothState>): void; | 新增 |
| ohos.bluetooth | bluetooth | off(type: "pinRequired", callback?: Callback\<PinRequiredParam>): void; | 新增 |
| ohos.bluetooth | bluetooth | on(type: "pinRequired", callback: Callback\<PinRequiredParam>): void; | 新增 |
| ohos.bluetooth | bluetooth | off(type: "bondStateChange", callback?: Callback\<BondStateParam>): void; | 新增 |
| ohos.bluetooth | bluetooth | on(type: "bondStateChange", callback: Callback\<BondStateParam>): void; | 新增 |
| ohos.bluetooth | bluetooth | off(type: "bluetoothDeviceFind", callback?: Callback\<Array\<string>>): void; | 新增 |
| ohos.bluetooth | bluetooth | on(type: "bluetoothDeviceFind", callback: Callback\<Array\<string>>): void; | 新增 |
| ohos.bluetooth | bluetooth | stopBluetoothDiscovery(): boolean; | 新增 |
| ohos.bluetooth | bluetooth | startBluetoothDiscovery(): boolean; | 新增 |
| ohos.bluetooth | bluetooth | getBluetoothScanMode(): ScanMode; | 新增 |
| ohos.bluetooth | bluetooth | setBluetoothScanMode(mode: ScanMode, duration: number): boolean; | 新增 |
| ohos.bluetooth | bluetooth | setLocalName(name: string): boolean; | 新增 |
| ohos.bluetooth | bluetooth | setDevicePairingConfirmation(device: string, accept: boolean): boolean; | 新增 |
| ohos.bluetooth | bluetooth | getProfileConnState(profileId: ProfileId): ProfileConnectionState; | 新增 |
| ohos.bluetooth | bluetooth | getPairedDevices(): Array\<string>; | 新增 |
| ohos.bluetooth | bluetooth | getLocalName(): string; | 新增 |
| ohos.bluetooth | bluetooth | disableBluetooth(): boolean; | 新增 |
| ohos.bluetooth | bluetooth | enableBluetooth(): boolean; | 新增 |
| ohos.bluetooth | bluetooth | getRemoteDeviceClass(deviceId: string): DeviceClass; | 新增 |
| ohos.bluetooth | bluetooth | getRemoteDeviceName(deviceId: string): string; | 新增 |
| ohos.bluetooth | bluetooth | pairDevice(deviceId: string): boolean; | 新增 |
| ohos.bluetooth | bluetooth | getBtConnectionState(): ProfileConnectionState; | 新增 |
| ohos.bluetooth | bluetooth | getState(): BluetoothState; | 新增 |
