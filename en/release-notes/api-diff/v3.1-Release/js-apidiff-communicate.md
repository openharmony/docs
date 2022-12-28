# JS API Changes of the Communication Subsystem

The table below lists the APIs changes of the communication subsystem in OpenHarmony 3.1 Release over OpenHarmony 3.0 LTS.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| tagSession | TagSession | getMaxSendLength(): number; | Added|
| tagSession | TagSession | sendData(data: number[]): Promise\<number[]>;<br>sendData(data: number[], callback: AsyncCallback\<number[]>): void; | Added|
| tagSession | TagSession | getSendDataTimeout(): number; | Added|
| tagSession | TagSession | setSendDataTimeout(timeout: number): boolean; | Added|
| tagSession | TagSession | isTagConnected(): boolean; | Added|
| tagSession | TagSession | reset(): void; | Added|
| tagSession | TagSession | connectTag(): boolean; | Added|
| tagSession | TagSession | getTagInfo(): tag.TagInfo; | Added|
| nfctech | NfcVTag | getDsfId(): number; | Added|
| nfctech | NfcVTag | getResponseFlags(): number; | Added|
| nfctech | NfcFTag | getPmm(): number[]; | Added|
| nfctech | NfcFTag | getSystemCode(): number[]; | Added|
| nfctech | NfcBTag | getRespProtocol(): number[]; | Added|
| nfctech | NfcBTag | getRespAppData(): number[]; | Added|
| nfctech | NfcATag | getAtqa(): number[]; | Added|
| nfctech | NfcATag | getSak(): number; | Added|
| ohos.wifiext | PowerModel | THROUGH_WALL = 2 | Added|
| ohos.wifiext | PowerModel | GENERAL = 1 | Added|
| ohos.wifiext | PowerModel | SLEEPING = 0 | Added|
| ohos.wifiext | wifiext | setPowerModel(model: PowerModel) : boolean | Added|
| ohos.wifiext | wifiext | getPowerModel (): Promise\<PowerModel>;<br>getPowerModel (callback: AsyncCallback\<PowerModel>): void; | Added|
| ohos.wifiext | wifiext | getSupportedPowerModel(): Promise\<Array\<PowerModel>>;<br>getSupportedPowerModel(callback: AsyncCallback\<Array\<PowerModel>>): void; | Added|
| ohos.wifiext | wifiext | disableHotspot(): boolean; | Added|
| ohos.wifiext | wifiext | enableHotspot(): boolean; | Added|
| ohos.wifi | GroupOwnerBand | GO_BAND_5GHZ = 2 | Added|
| ohos.wifi | GroupOwnerBand | GO_BAND_2GHZ = 1 | Added|
| ohos.wifi | GroupOwnerBand | GO_BAND_AUTO = 0 | Added|
| ohos.wifi | P2pDeviceStatus | UNAVAILABLE = 4 | Added|
| ohos.wifi | P2pDeviceStatus | AVAILABLE = 3 | Added|
| ohos.wifi | P2pDeviceStatus | FAILED = 2 | Added|
| ohos.wifi | P2pDeviceStatus | INVITED = 1 | Added|
| ohos.wifi | P2pDeviceStatus | CONNECTED = 0 | Added|
| ohos.wifi | WifiP2pLinkedInfo | groupOwnerAddr: string; | Added|
| ohos.wifi | WifiP2pLinkedInfo | isGroupOwner: boolean; | Added|
| ohos.wifi | WifiP2pLinkedInfo | connectState: P2pConnectState; | Added|
| ohos.wifi | P2pConnectState | CONNECTED = 1 | Added|
| ohos.wifi | P2pConnectState | DISCONNECTED = 0 | Added|
| ohos.wifi | WifiP2pGroupInfo | goIpAddress: string; | Added|
| ohos.wifi | WifiP2pGroupInfo | clientDevices: WifiP2pDevice[]; | Added|
| ohos.wifi | WifiP2pGroupInfo | frequency: number; | Added|
| ohos.wifi | WifiP2pGroupInfo | networkId: number; | Added|
| ohos.wifi | WifiP2pGroupInfo | groupName: string; | Added|
| ohos.wifi | WifiP2pGroupInfo | interface: string; | Added|
| ohos.wifi | WifiP2pGroupInfo | passphrase: string; | Added|
| ohos.wifi | WifiP2pGroupInfo | ownerInfo: WifiP2pDevice; | Added|
| ohos.wifi | WifiP2pGroupInfo | isP2pGo: boolean; | Added|
| ohos.wifi | WifiP2PConfig | goBand: GroupOwnerBand; | Added|
| ohos.wifi | WifiP2PConfig | groupName: string; | Added|
| ohos.wifi | WifiP2PConfig | passphrase: string; | Added|
| ohos.wifi | WifiP2PConfig | netId: number; | Added|
| ohos.wifi | WifiP2PConfig | deviceAddress: string; | Added|
| ohos.wifi | WifiP2pDevice | groupCapabilitys: number; | Added|
| ohos.wifi | WifiP2pDevice | deviceStatus: P2pDeviceStatus; | Added|
| ohos.wifi | WifiP2pDevice | primaryDeviceType: string; | Added|
| ohos.wifi | WifiP2pDevice | deviceAddress: string; | Added|
| ohos.wifi | WifiP2pDevice | deviceName: string; | Added|
| ohos.wifi | ConnState | UNKNOWN | Added|
| ohos.wifi | ConnState | DISCONNECTED | Added|
| ohos.wifi | ConnState | DISCONNECTING | Added|
| ohos.wifi | ConnState | CONNECTED | Added|
| ohos.wifi | ConnState | OBTAINING_IPADDR | Added|
| ohos.wifi | ConnState | AUTHENTICATING | Added|
| ohos.wifi | ConnState | CONNECTING | Added|
| ohos.wifi | ConnState | SCANNING | Added|
| ohos.wifi | IpInfo | leaseDuration: number; | Added|
| ohos.wifi | IpInfo | serverIp: number; | Added|
| ohos.wifi | IpInfo | secondDns: number; | Added|
| ohos.wifi | IpInfo | primaryDns: number; | Added|
| ohos.wifi | IpInfo | netmask: number; | Added|
| ohos.wifi | IpInfo | gateway: number; | Added|
| ohos.wifi | IpInfo | ipAddress: number; | Added|
| ohos.wifi | WifiLinkedInfo | connState: ConnState; | Added|
| ohos.wifi | WifiLinkedInfo | ipAddress: number; | Added|
| ohos.wifi | WifiLinkedInfo | macAddress: string; | Added|
| ohos.wifi | WifiLinkedInfo | isRestricted: boolean; | Added|
| ohos.wifi | WifiLinkedInfo | isHidden: boolean; | Added|
| ohos.wifi | WifiLinkedInfo | frequency: number; | Added|
| ohos.wifi | WifiLinkedInfo | linkSpeed: number; | Added|
| ohos.wifi | WifiLinkedInfo | band: number; | Added|
| ohos.wifi | WifiLinkedInfo | rssi: number; | Added|
| ohos.wifi | WifiLinkedInfo | bssid: string; | Added|
| ohos.wifi | WifiLinkedInfo | ssid: string; | Added|
| ohos.wifi | WifiScanInfo | channelWidth: number; | Added|
| ohos.wifi | WifiScanInfo | capabilities: string; | Added|
| ohos.wifi | wifi | off(type: "p2pDiscoveryChange", callback?: Callback\<number>): void; | Added|
| ohos.wifi | wifi | on(type: "p2pDiscoveryChange", callback: Callback\<number>): void; | Added|
| ohos.wifi | wifi | off(type: "p2pPersistentGroupChange", callback?: Callback\<void>): void; | Added|
| ohos.wifi | wifi | on(type: "p2pPersistentGroupChange", callback: Callback\<void>): void; | Added|
| ohos.wifi | wifi | off(type: "p2pPeerDeviceChange", callback?: Callback\<WifiP2pDevice[]>): void; | Added|
| ohos.wifi | wifi | on(type: "p2pPeerDeviceChange", callback: Callback\<WifiP2pDevice[]>): void; | Added|
| ohos.wifi | wifi | off(type: "p2pDeviceChange", callback?: Callback\<WifiP2pDevice>): void; | Added|
| ohos.wifi | wifi | on(type: "p2pDeviceChange", callback: Callback\<WifiP2pDevice>): void; | Added|
| ohos.wifi | wifi | off(type: "p2pConnectionChange", callback?: Callback\<WifiP2pLinkedInfo>): void; | Added|
| ohos.wifi | wifi | on(type: "p2pConnectionChange", callback: Callback\<WifiP2pLinkedInfo>): void; | Added|
| ohos.wifi | wifi | off(type: "p2pStateChange", callback?: Callback\<number>): void; | Added|
| ohos.wifi | wifi | on(type: "p2pStateChange", callback: Callback\<number>): void; | Added|
| ohos.wifi | wifi | off(type: "hotspotStateChange", callback?: Callback\<number>): void; | Added|
| ohos.wifi | wifi | on(type: "hotspotStateChange", callback: Callback\<number>): void; | Added|
| ohos.wifi | wifi | off(type: "wifiRssiChange", callback?: Callback\<number>): void; | Added|
| ohos.wifi | wifi | on(type: "wifiRssiChange", callback: Callback\<number>): void; | Added|
| ohos.wifi | wifi | off(type: "wifiScanStateChange", callback?: Callback\<number>): void; | Added|
| ohos.wifi | wifi | on(type: "wifiScanStateChange", callback: Callback\<number>): void; | Added|
| ohos.wifi | wifi | off(type: "wifiConnectionChange", callback?: Callback\<number>): void; | Added|
| ohos.wifi | wifi | on(type: "wifiConnectionChange", callback: Callback\<number>): void; | Added|
| ohos.wifi | wifi | off(type: "wifiStateChange", callback?: Callback\<number>): void; | Added|
| ohos.wifi | wifi | on(type: "wifiStateChange", callback: Callback\<number>): void; | Added|
| ohos.wifi | wifi | stopDiscoverDevices(): boolean; | Added|
| ohos.wifi | wifi | startDiscoverDevices(): boolean; | Added|
| ohos.wifi | wifi | p2pCancelConnect(): boolean; | Added|
| ohos.wifi | wifi | p2pConnect(config: WifiP2PConfig): boolean; | Added|
| ohos.wifi | wifi | removeGroup(): boolean; | Added|
| ohos.wifi | wifi | createGroup(config: WifiP2PConfig): boolean; | Added|
| ohos.wifi | wifi | getP2pPeerDevices(): Promise\<WifiP2pDevice[]>;<br>getP2pPeerDevices(callback: AsyncCallback\<WifiP2pDevice[]>): void; | Added|
| ohos.wifi | wifi | getCurrentGroup(): Promise\<WifiP2pGroupInfo>;<br>getCurrentGroup(callback: AsyncCallback\<WifiP2pGroupInfo>): void; | Added|
| ohos.wifi | wifi | getP2pLinkedInfo(): Promise\<WifiP2pLinkedInfo>;<br>getP2pLinkedInfo(callback: AsyncCallback\<WifiP2pLinkedInfo>): void; | Added|
| ohos.wifi | wifi | getCountryCode(): string; | Added|
| ohos.wifi | wifi | getIpInfo(): IpInfo; | Added|
| ohos.wifi | wifi | isFeatureSupported(featureId: number): boolean; | Added|
| ohos.wifi | wifi | isConnected(): boolean; | Added|
| ohos.wifi | wifi | getLinkedInfo(): Promise\<WifiLinkedInfo>;<br>getLinkedInfo(callback: AsyncCallback\<WifiLinkedInfo>): void; | Added|
| ohos.wifi | wifi | removeUntrustedConfig(config: WifiDeviceConfig): Promise\<boolean>;<br>removeUntrustedConfig(config: WifiDeviceConfig, callback: AsyncCallback\<boolean>): void; | Added|
| ohos.wifi | wifi | addUntrustedConfig(config: WifiDeviceConfig): Promise\<boolean>;<br>addUntrustedConfig(config: WifiDeviceConfig, callback: AsyncCallback\<boolean>): void; | Added|
| ohos.nfc.tag | TagInfo | supportedProfiles: number[]; | Added|
| ohos.nfc.tag | tag | getNfcVTag(tagInfo: TagInfo): NfcVTag | Added|
| ohos.nfc.tag | tag | getNfcFTag(tagInfo: TagInfo): NfcFTag | Added|
| ohos.nfc.tag | tag | getNfcBTag(tagInfo: TagInfo): NfcBTag | Added|
| ohos.nfc.tag | tag | getNfcATag(tagInfo: TagInfo): NfcATag | Added|
| ohos.nfc.tag | tag | const MIFARE_ULTRALIGHT = 9; | Added|
| ohos.nfc.tag | tag | const MIFARE_CLASSIC = 8; | Added|
| ohos.nfc.tag | tag | const NDEF = 6; | Added|
| ohos.nfc.tag | tag | const NFC_V = 5; | Added|
| ohos.nfc.tag | tag | const NFC_F = 4; | Added|
| ohos.nfc.tag | tag | const ISO_DEP = 3; | Added|
| ohos.nfc.tag | tag | const NFC_B = 2; | Added|
| ohos.nfc.tag | tag | const NFC_A = 1; | Added|
| ohos.nfc.controller | nfcController | getNfcState(): NfcState | Added|
| ohos.nfc.controller | nfcController | isNfcOpen(): boolean | Added|
| ohos.nfc.controller | nfcController | closeNfc(): boolean | Added|
| ohos.nfc.controller | nfcController | openNfc(): boolean | Added|
| ohos.nfc.controller | nfcController | off(type: "nfcStateChange", callback?: Callback\<NfcState>): void | Added|
| ohos.nfc.controller | nfcController | on(type: "nfcStateChange", callback: Callback\<NfcState>): void | Added|
| ohos.nfc.controller | nfcController | isNfcAvailable(): boolean | Added|
| ohos.nfc.controller | NfcState | STATE_TURNING_OFF = 4 | Added|
| ohos.nfc.controller | NfcState | STATE_ON = 3 | Added|
| ohos.nfc.controller | NfcState | STATE_TURNING_ON = 2 | Added|
| ohos.nfc.controller | NfcState | STATE_OFF = 1 | Added|
| ohos.nfc.cardEmulation | HceService | sendResponse(responseApdu: number[]): void; | Added|
| ohos.nfc.cardEmulation | HceService | on(type: "hceCmd", callback: AsyncCallback\<number[]>): void; | Added|
| ohos.nfc.cardEmulation | HceService | stopHCE(): boolean; | Added|
| ohos.nfc.cardEmulation | HceService | startHCE(aidList: string[]): boolean; | Added|
| ohos.nfc.cardEmulation | cardEmulation | isSupported(feature: number): boolean; | Added|
| ohos.nfc.cardEmulation | FeatureType | ESE = 2 | Added|
| ohos.nfc.cardEmulation | FeatureType | UICC = 1 | Added|
| ohos.nfc.cardEmulation | FeatureType | HCE = 0 | Added|
| ohos.connectedTag | NfcRfType | NFC_RF_ENTER = 1 | Added|
| ohos.connectedTag | NfcRfType | NFC_RF_LEAVE = 0 | Added|
| ohos.connectedTag | connectedTag | off(type: "notify", callback?:Callback\<number>): void; | Added|
| ohos.connectedTag | connectedTag | on(type: "notify", callback: Callback\<number>): void; | Added|
| ohos.connectedTag | connectedTag | writeNdefTag(data: string): Promise\<void>;<br>writeNdefTag(data: string, callback: AsyncCallback\<void>): void; | Added|
| ohos.connectedTag | connectedTag | readNdefTag(): Promise\<string>;<br>readNdefTag(callback: AsyncCallback\<string>): void; | Added|
| ohos.connectedTag | connectedTag | uninit(): boolean; | Added|
| ohos.connectedTag | connectedTag | init(): boolean; | Added|
| ohos.bluetooth | ProfileId | PROFILE_HANDS_FREE_AUDIO_GATEWAY = 4 | Added|
| ohos.bluetooth | ProfileId | PROFILE_A2DP_SOURCE = 1 | Added|
| ohos.bluetooth | PlayingState | STATE_PLAYING | Added|
| ohos.bluetooth | PlayingState | STATE_NOT_PLAYING | Added|
| ohos.bluetooth | StateChangeParam | state: ProfileConnectionState; | Added|
| ohos.bluetooth | StateChangeParam | deviceId: string; | Added|
| ohos.bluetooth | MajorMinorClass | HEALTH_PERSONAL_MOBILITY_DEVICE = 0x093C | Added|
| ohos.bluetooth | MajorMinorClass | HEALTH_GENERIC_HEALTH_MANAGER = 0x0938 | Added|
| ohos.bluetooth | MajorMinorClass | HEALTH_ANKLE_PROSTHESIS = 0x0934 | Added|
| ohos.bluetooth | MajorMinorClass | HEALTH_KNEE_PROSTHESIS = 0x0930 | Added|
| ohos.bluetooth | MajorMinorClass | HEALTH_MEDICATION_MONITOR = 0x092C | Added|
| ohos.bluetooth | MajorMinorClass | HEALTH_PEAK_FLOW_MOITOR = 0x0928 | Added|
| ohos.bluetooth | MajorMinorClass | HEALTH_BODY_COMPOSITION_ANALYZER = 0x0924 | Added|
| ohos.bluetooth | MajorMinorClass | HEALTH_STEP_COUNTER = 0x0920 | Added|
| ohos.bluetooth | MajorMinorClass | HEALTH_DATA_DISPLAY = 0x091C | Added|
| ohos.bluetooth | MajorMinorClass | HEALTH_PULSE_RATE = 0x0918 | Added|
| ohos.bluetooth | MajorMinorClass | HEALTH_PULSE_OXIMETER = 0x0914 | Added|
| ohos.bluetooth | MajorMinorClass | HEALTH_GLUCOSE = 0x0910 | Added|
| ohos.bluetooth | MajorMinorClass | HEALTH_WEIGHING = 0x090C | Added|
| ohos.bluetooth | MajorMinorClass | HEALTH_THERMOMETER = 0x0908 | Added|
| ohos.bluetooth | MajorMinorClass | HEALTH_BLOOD_PRESSURE = 0x0904 | Added|
| ohos.bluetooth | MajorMinorClass | HEALTH_UNCATEGORIZED = 0x0900 | Added|
| ohos.bluetooth | MajorMinorClass | TOY_GAME = 0x0814 | Added|
| ohos.bluetooth | MajorMinorClass | TOY_CONTROLLER = 0x0810 | Added|
| ohos.bluetooth | MajorMinorClass | TOY_DOLL_ACTION_FIGURE = 0x080C | Added|
| ohos.bluetooth | MajorMinorClass | TOY_VEHICLE = 0x0808 | Added|
| ohos.bluetooth | MajorMinorClass | TOY_ROBOT = 0x0804 | Added|
| ohos.bluetooth | MajorMinorClass | TOY_UNCATEGORIZED = 0x0800 | Added|
| ohos.bluetooth | MajorMinorClass | WEARABLE_GLASSES = 0x0714 | Added|
| ohos.bluetooth | MajorMinorClass | WEARABLE_HELMET = 0x0710 | Added|
| ohos.bluetooth | MajorMinorClass | WEARABLE_JACKET = 0x070C | Added|
| ohos.bluetooth | MajorMinorClass | WEARABLE_PAGER = 0x0708 | Added|
| ohos.bluetooth | MajorMinorClass | WEARABLE_WRIST_WATCH = 0x0704 | Added|
| ohos.bluetooth | MajorMinorClass | WEARABLE_UNCATEGORIZED = 0x0700 | Added|
| ohos.bluetooth | MajorMinorClass | IMAGING_PRINTER = 0x0680 | Added|
| ohos.bluetooth | MajorMinorClass | IMAGING_SCANNER = 0x0640 | Added|
| ohos.bluetooth | MajorMinorClass | IMAGING_CAMERA = 0x0620 | Added|
| ohos.bluetooth | MajorMinorClass | IMAGING_DISPLAY = 0x0610 | Added|
| ohos.bluetooth | MajorMinorClass | IMAGING_UNCATEGORIZED = 0x0600 | Added|
| ohos.bluetooth | MajorMinorClass | PERIPHERAL_GESTURAL_INPUT = 0x0522 | Added|
| ohos.bluetooth | MajorMinorClass | PERIPHERAL_SCANNER_RFID = 0x0520 | Added|
| ohos.bluetooth | MajorMinorClass | PERIPHERAL_DIGITAL_PEN = 0x051C | Added|
| ohos.bluetooth | MajorMinorClass | PERIPHERAL_CARD_READER = 0x0518 | Added|
| ohos.bluetooth | MajorMinorClass | PERIPHERAL_DIGITIZER_TABLET = 0x0514 | Added|
| ohos.bluetooth | MajorMinorClass | PERIPHERAL_SENSING_DEVICE = 0x0510 | Added|
| ohos.bluetooth | MajorMinorClass | PERIPHERAL_REMOTE_CONTROL = 0x05C0 | Added|
| ohos.bluetooth | MajorMinorClass | PERIPHERAL_GAMEPAD = 0x0508 | Added|
| ohos.bluetooth | MajorMinorClass | PERIPHERAL_JOYSTICK = 0x0504 | Added|
| ohos.bluetooth | MajorMinorClass | PERIPHERAL_UNCATEGORIZED = 0x0500 | Added|
| ohos.bluetooth | MajorMinorClass | PERIPHERAL_KEYBOARD_POINTING = 0x05C0 | Added|
| ohos.bluetooth | MajorMinorClass | PERIPHERAL_POINTING_DEVICE = 0x0580 | Added|
| ohos.bluetooth | MajorMinorClass | PERIPHERAL_KEYBOARD = 0x0540 | Added|
| ohos.bluetooth | MajorMinorClass | PERIPHERAL_NON_KEYBOARD_NON_POINTING = 0x0500 | Added|
| ohos.bluetooth | MajorMinorClass | AUDIO_VIDEO_VIDEO_GAMING_TOY = 0x0448 | Added|
| ohos.bluetooth | MajorMinorClass | AUDIO_VIDEO_VIDEO_CONFERENCING = 0x0440 | Added|
| ohos.bluetooth | MajorMinorClass | AUDIO_VIDEO_VIDEO_DISPLAY_AND_LOUDSPEAKER = 0x043C | Added|
| ohos.bluetooth | MajorMinorClass | AUDIO_VIDEO_VIDEO_MONITOR = 0x0438 | Added|
| ohos.bluetooth | MajorMinorClass | AUDIO_VIDEO_CAMCORDER = 0x0434 | Added|
| ohos.bluetooth | MajorMinorClass | AUDIO_VIDEO_VIDEO_CAMERA = 0x0430 | Added|
| ohos.bluetooth | MajorMinorClass | AUDIO_VIDEO_VCR = 0x042C | Added|
| ohos.bluetooth | MajorMinorClass | AUDIO_VIDEO_HIFI_AUDIO = 0x0428 | Added|
| ohos.bluetooth | MajorMinorClass | AUDIO_VIDEO_SET_TOP_BOX = 0x0424 | Added|
| ohos.bluetooth | MajorMinorClass | AUDIO_VIDEO_CAR_AUDIO = 0x0420 | Added|
| ohos.bluetooth | MajorMinorClass | AUDIO_VIDEO_PORTABLE_AUDIO = 0x041C | Added|
| ohos.bluetooth | MajorMinorClass | AUDIO_VIDEO_HEADPHONES = 0x0418 | Added|
| ohos.bluetooth | MajorMinorClass | AUDIO_VIDEO_LOUDSPEAKER = 0x0414 | Added|
| ohos.bluetooth | MajorMinorClass | AUDIO_VIDEO_MICROPHONE = 0x0410 | Added|
| ohos.bluetooth | MajorMinorClass | AUDIO_VIDEO_HANDSFREE = 0x0408 | Added|
| ohos.bluetooth | MajorMinorClass | AUDIO_VIDEO_WEARABLE_HEADSET = 0x0404 | Added|
| ohos.bluetooth | MajorMinorClass | AUDIO_VIDEO_UNCATEGORIZED = 0x0400 | Added|
| ohos.bluetooth | MajorMinorClass | NETWORK_NO_SERVICE = 0x03E0 | Added|
| ohos.bluetooth | MajorMinorClass | NETWORK_83_TO_99_UTILIZED = 0x03C0 | Added|
| ohos.bluetooth | MajorMinorClass | NETWORK_67_TO_83_UTILIZED = 0x03A0 | Added|
| ohos.bluetooth | MajorMinorClass | NETWORK_60_TO_67_UTILIZED = 0x0380 | Added|
| ohos.bluetooth | MajorMinorClass | NETWORK_33_TO_50_UTILIZED = 0x0360 | Added|
| ohos.bluetooth | MajorMinorClass | NETWORK_17_TO_33_UTILIZED = 0x0340 | Added|
| ohos.bluetooth | MajorMinorClass | NETWORK_1_TO_17_UTILIZED = 0x0320 | Added|
| ohos.bluetooth | MajorMinorClass | NETWORK_FULLY_AVAILABLE = 0x0300 | Added|
| ohos.bluetooth | MajorMinorClass | PHONE_ISDN = 0x0214 | Added|
| ohos.bluetooth | MajorMinorClass | PHONE_MODEM_OR_GATEWAY = 0x0210 | Added|
| ohos.bluetooth | MajorMinorClass | PHONE_SMART = 0x020C | Added|
| ohos.bluetooth | MajorMinorClass | PHONE_CORDLESS = 0x0208 | Added|
| ohos.bluetooth | MajorMinorClass | PHONE_CELLULAR = 0x0204 | Added|
| ohos.bluetooth | MajorMinorClass | PHONE_UNCATEGORIZED = 0x0200 | Added|
| ohos.bluetooth | MajorMinorClass | COMPUTER_TABLET = 0x011C | Added|
| ohos.bluetooth | MajorMinorClass | COMPUTER_WEARABLE = 0x0118 | Added|
| ohos.bluetooth | MajorMinorClass | COMPUTER_PALM_SIZE_PC_PDA = 0x0114 | Added|
| ohos.bluetooth | MajorMinorClass | COMPUTER_HANDHELD_PC_PDA = 0x0110 | Added|
| ohos.bluetooth | MajorMinorClass | COMPUTER_LAPTOP = 0x010C | Added|
| ohos.bluetooth | MajorMinorClass | COMPUTER_SERVER = 0x0108 | Added|
| ohos.bluetooth | MajorMinorClass | COMPUTER_DESKTOP = 0x0104 | Added|
| ohos.bluetooth | MajorMinorClass | COMPUTER_UNCATEGORIZED = 0x0100 | Added|
| ohos.bluetooth | MajorClass | MAJOR_UNCATEGORIZED = 0x1F00 | Added|
| ohos.bluetooth | MajorClass | MAJOR_HEALTH = 0x0900 | Added|
| ohos.bluetooth | MajorClass | MAJOR_TOY = 0x0800 | Added|
| ohos.bluetooth | MajorClass | MAJOR_WEARABLE = 0x0700 | Added|
| ohos.bluetooth | MajorClass | MAJOR_IMAGING = 0x0600 | Added|
| ohos.bluetooth | MajorClass | MAJOR_PERIPHERAL = 0x0500 | Added|
| ohos.bluetooth | MajorClass | MAJOR_AUDIO_VIDEO = 0x0400 | Added|
| ohos.bluetooth | MajorClass | MAJOR_NETWORKING = 0x0300 | Added|
| ohos.bluetooth | MajorClass | MAJOR_PHONE = 0x0200 | Added|
| ohos.bluetooth | MajorClass | MAJOR_COMPUTER = 0x0100 | Added|
| ohos.bluetooth | MajorClass | MAJOR_MISC = 0x0000 | Added|
| ohos.bluetooth | BondState | BOND_STATE_BONDED = 2 | Added|
| ohos.bluetooth | BondState | BOND_STATE_BONDING = 1 | Added|
| ohos.bluetooth | BondState | BOND_STATE_INVALID = 0 | Added|
| ohos.bluetooth | ScanMode | SCAN_MODE_CONNECTABLE_LIMITED_DISCOVERABLE = 5 | Added|
| ohos.bluetooth | ScanMode | SCAN_MODE_CONNECTABLE_GENERAL_DISCOVERABLE = 4 | Added|
| ohos.bluetooth | ScanMode | SCAN_MODE_LIMITED_DISCOVERABLE = 3 | Added|
| ohos.bluetooth | ScanMode | SCAN_MODE_GENERAL_DISCOVERABLE = 2 | Added|
| ohos.bluetooth | ScanMode | SCAN_MODE_CONNECTABLE = 1 | Added|
| ohos.bluetooth | ScanMode | SCAN_MODE_NONE = 0 | Added|
| ohos.bluetooth | SppType | SPP_RFCOMM | Added|
| ohos.bluetooth | BluetoothState | STATE_BLE_TURNING_OFF = 6 | Added|
| ohos.bluetooth | BluetoothState | STATE_BLE_ON = 5 | Added|
| ohos.bluetooth | BluetoothState | STATE_BLE_TURNING_ON = 4 | Added|
| ohos.bluetooth | BluetoothState | STATE_TURNING_OFF = 3 | Added|
| ohos.bluetooth | BluetoothState | STATE_ON = 2 | Added|
| ohos.bluetooth | BluetoothState | STATE_TURNING_ON = 1 | Added|
| ohos.bluetooth | BluetoothState | STATE_OFF = 0 | Added|
| ohos.bluetooth | ProfileConnectionState | STATE_DISCONNECTING = 3 | Added|
| ohos.bluetooth | ProfileConnectionState | STATE_CONNECTED = 2 | Added|
| ohos.bluetooth | ProfileConnectionState | STATE_CONNECTING = 1 | Added|
| ohos.bluetooth | ProfileConnectionState | STATE_DISCONNECTED = 0 | Added|
| ohos.bluetooth | MatchMode | MATCH_MODE_STICKY = 2 | Added|
| ohos.bluetooth | MatchMode | MATCH_MODE_AGGRESSIVE = 1 | Added|
| ohos.bluetooth | ScanDuty | SCAN_MODE_LOW_LATENCY = 2 | Added|
| ohos.bluetooth | ScanDuty | SCAN_MODE_BALANCED = 1 | Added|
| ohos.bluetooth | ScanDuty | SCAN_MODE_LOW_POWER = 0 | Added|
| ohos.bluetooth | BondStateParam | state: BondState; | Added|
| ohos.bluetooth | BondStateParam | deviceId: string; | Added|
| ohos.bluetooth | DeviceClass | classOfDevice: number; | Added|
| ohos.bluetooth | DeviceClass | majorMinorClass: MajorMinorClass; | Added|
| ohos.bluetooth | DeviceClass | majorClass: MajorClass; | Added|
| ohos.bluetooth | PinRequiredParam | pinCode: string; | Added|
| ohos.bluetooth | PinRequiredParam | deviceId: string; | Added|
| ohos.bluetooth | SppOption | type: SppType; | Added|
| ohos.bluetooth | SppOption | secure: boolean; | Added|
| ohos.bluetooth | SppOption | uuid: string; | Added|
| ohos.bluetooth | ScanOptions | matchMode?: MatchMode; | Added|
| ohos.bluetooth | ScanOptions | dutyMode?: ScanDuty; | Added|
| ohos.bluetooth | ScanOptions | interval?: number; | Added|
| ohos.bluetooth | ScanFilter | serviceUuid?: string; | Added|
| ohos.bluetooth | ScanFilter | name?: string; | Added|
| ohos.bluetooth | ScanFilter | deviceId?: string; | Added|
| ohos.bluetooth | ServiceData | serviceValue: ArrayBuffer; | Added|
| ohos.bluetooth | ServiceData | serviceUuid: string; | Added|
| ohos.bluetooth | ManufactureData | manufactureValue: ArrayBuffer; | Added|
| ohos.bluetooth | ManufactureData | manufactureId: number; | Added|
| ohos.bluetooth | AdvertiseData | serviceData: Array\<ServiceData>; | Added|
| ohos.bluetooth | AdvertiseData | manufactureData: Array\<ManufactureData>; | Added|
| ohos.bluetooth | AdvertiseData | serviceUuids: Array\<string>; | Added|
| ohos.bluetooth | AdvertiseSetting | connectable?: boolean; | Added|
| ohos.bluetooth | AdvertiseSetting | txPower?: number; | Added|
| ohos.bluetooth | AdvertiseSetting | interval?: number; | Added|
| ohos.bluetooth | ScanResult | data: ArrayBuffer; | Added|
| ohos.bluetooth | ScanResult | rssi: number; | Added|
| ohos.bluetooth | ScanResult | deviceId: string; | Added|
| ohos.bluetooth | BLEConnectChangedState | state: ProfileConnectionState; | Added|
| ohos.bluetooth | BLEConnectChangedState | deviceId: string; | Added|
| ohos.bluetooth | ServerResponse | value: ArrayBuffer; | Added|
| ohos.bluetooth | ServerResponse | offset: number; | Added|
| ohos.bluetooth | ServerResponse | status: number; | Added|
| ohos.bluetooth | ServerResponse | transId: number; | Added|
| ohos.bluetooth | ServerResponse | deviceId: string; | Added|
| ohos.bluetooth | DescriptorWriteReq | serviceUuid: string; | Added|
| ohos.bluetooth | DescriptorWriteReq | characteristicUuid: string; | Added|
| ohos.bluetooth | DescriptorWriteReq | descriptorUuid: string; | Added|
| ohos.bluetooth | DescriptorWriteReq | value: ArrayBuffer; | Added|
| ohos.bluetooth | DescriptorWriteReq | needRsp: boolean; | Added|
| ohos.bluetooth | DescriptorWriteReq | isPrep: boolean; | Added|
| ohos.bluetooth | DescriptorWriteReq | offset: number; | Added|
| ohos.bluetooth | DescriptorWriteReq | transId: number; | Added|
| ohos.bluetooth | DescriptorWriteReq | deviceId: string; | Added|
| ohos.bluetooth | DescriptorReadReq | serviceUuid: string; | Added|
| ohos.bluetooth | DescriptorReadReq | characteristicUuid: string; | Added|
| ohos.bluetooth | DescriptorReadReq | descriptorUuid: string; | Added|
| ohos.bluetooth | DescriptorReadReq | offset: number; | Added|
| ohos.bluetooth | DescriptorReadReq | transId: number; | Added|
| ohos.bluetooth | DescriptorReadReq | deviceId: string; | Added|
| ohos.bluetooth | CharacteristicWriteReq | serviceUuid: string; | Added|
| ohos.bluetooth | CharacteristicWriteReq | characteristicUuid: string; | Added|
| ohos.bluetooth | CharacteristicWriteReq | value: ArrayBuffer; | Added|
| ohos.bluetooth | CharacteristicWriteReq | needRsp: boolean; | Added|
| ohos.bluetooth | CharacteristicWriteReq | isPrep: boolean; | Added|
| ohos.bluetooth | CharacteristicWriteReq | offset: number; | Added|
| ohos.bluetooth | CharacteristicWriteReq | transId: number; | Added|
| ohos.bluetooth | CharacteristicWriteReq | deviceId: string; | Added|
| ohos.bluetooth | CharacteristicReadReq | serviceUuid: string; | Added|
| ohos.bluetooth | CharacteristicReadReq | characteristicUuid: string; | Added|
| ohos.bluetooth | CharacteristicReadReq | offset: number; | Added|
| ohos.bluetooth | CharacteristicReadReq | transId: number; | Added|
| ohos.bluetooth | CharacteristicReadReq | deviceId: string; | Added|
| ohos.bluetooth | NotifyCharacteristic | confirm: boolean; | Added|
| ohos.bluetooth | NotifyCharacteristic | characteristicValue: ArrayBuffer; | Added|
| ohos.bluetooth | NotifyCharacteristic | characteristicUuid: string; | Added|
| ohos.bluetooth | NotifyCharacteristic | serviceUuid: string; | Added|
| ohos.bluetooth | BLEDescriptor | descriptorValue: ArrayBuffer; | Added|
| ohos.bluetooth | BLEDescriptor | descriptorUuid: string; | Added|
| ohos.bluetooth | BLEDescriptor | characteristicUuid: string; | Added|
| ohos.bluetooth | BLEDescriptor | serviceUuid: string; | Added|
| ohos.bluetooth | BLECharacteristic | descriptors: Array\<BLEDescriptor>; | Added|
| ohos.bluetooth | BLECharacteristic | characteristicValue: ArrayBuffer; | Added|
| ohos.bluetooth | BLECharacteristic | characteristicUuid: string; | Added|
| ohos.bluetooth | BLECharacteristic | serviceUuid: string; | Added|
| ohos.bluetooth | GattService | includeServices?: Array\<GattService>; | Added|
| ohos.bluetooth | GattService | characteristics: Array\<BLECharacteristic>; | Added|
| ohos.bluetooth | GattService | isPrimary: boolean; | Added|
| ohos.bluetooth | GattService | serviceUuid: string; | Added|
| ohos.bluetooth | GattClientDevice | off(type: "BLEConnectionStateChange", callback?: Callback\<BLEConnectChangedState>): void; | Added|
| ohos.bluetooth | GattClientDevice | on(type: "BLEConnectionStateChange", callback: Callback\<BLEConnectChangedState>): void; | Added|
| ohos.bluetooth | GattClientDevice | off(type: "BLECharacteristicChange", callback?: Callback\<BLECharacteristic>): void; | Added|
| ohos.bluetooth | GattClientDevice | on(type: "BLECharacteristicChange", callback: Callback\<BLECharacteristic>): void; | Added|
| ohos.bluetooth | GattClientDevice | setNotifyCharacteristicChanged(characteristic: BLECharacteristic, enable: boolean): boolean; | Added|
| ohos.bluetooth | GattClientDevice | setBLEMtuSize(mtu: number): boolean; | Added|
| ohos.bluetooth | GattClientDevice | getRssiValue(callback: AsyncCallback\<number>): void;<br>getRssiValue(): Promise\<number>; | Added|
| ohos.bluetooth | GattClientDevice | writeDescriptorValue(descriptor: BLEDescriptor): boolean; | Added|
| ohos.bluetooth | GattClientDevice | writeCharacteristicValue(characteristic: BLECharacteristic): boolean; | Added|
| ohos.bluetooth | GattClientDevice | readDescriptorValue(descriptor: BLEDescriptor, callback: AsyncCallback\<BLEDescriptor>): void;<br>readDescriptorValue(descriptor: BLEDescriptor): Promise\<BLEDescriptor>; | Added|
| ohos.bluetooth | GattClientDevice | readCharacteristicValue(characteristic: BLECharacteristic, callback: AsyncCallback\<BLECharacteristic>): void;<br>readCharacteristicValue(characteristic: BLECharacteristic): Promise\<BLECharacteristic>; | Added|
| ohos.bluetooth | GattClientDevice | getServices(callback: AsyncCallback\<Array\<GattService>>): void;<br>getServices(): Promise\<Array\<GattService>>; | Added|
| ohos.bluetooth | GattClientDevice | getDeviceName(callback: AsyncCallback\<string>): void;<br>getDeviceName(): Promise\<string>; | Added|
| ohos.bluetooth | GattClientDevice | close(): boolean; | Added|
| ohos.bluetooth | GattClientDevice | disconnect(): boolean; | Added|
| ohos.bluetooth | GattClientDevice | connect(): boolean; | Added|
| ohos.bluetooth | GattServer | off(type: "connectStateChange", callback?: Callback\<BLEConnectChangedState>): void; | Added|
| ohos.bluetooth | GattServer | on(type: "connectStateChange", callback: Callback\<BLEConnectChangedState>): void; | Added|
| ohos.bluetooth | GattServer | off(type: "descriptorWrite", callback?: Callback\<DescriptorWriteReq>): void; | Added|
| ohos.bluetooth | GattServer | on(type: "descriptorWrite", callback: Callback\<DescriptorWriteReq>): void; | Added|
| ohos.bluetooth | GattServer | off(type: "descriptorRead", callback?: Callback\<DescriptorReadReq>): void; | Added|
| ohos.bluetooth | GattServer | on(type: "descriptorRead", callback: Callback\<DescriptorReadReq>): void; | Added|
| ohos.bluetooth | GattServer | off(type: "characteristicWrite", callback?: Callback\<CharacteristicWriteReq>): void; | Added|
| ohos.bluetooth | GattServer | on(type: "characteristicWrite", callback: Callback\<CharacteristicWriteReq>): void; | Added|
| ohos.bluetooth | GattServer | off(type: "characteristicRead", callback?: Callback\<CharacteristicReadReq>): void; | Added|
| ohos.bluetooth | GattServer | on(type: "characteristicRead", callback: Callback\<CharacteristicReadReq>): void; | Added|
| ohos.bluetooth | GattServer | sendResponse(serverResponse: ServerResponse): boolean; | Added|
| ohos.bluetooth | GattServer | notifyCharacteristicChanged(deviceId: string, notifyCharacteristic: NotifyCharacteristic): boolean; | Added|
| ohos.bluetooth | GattServer | close(): void; | Added|
| ohos.bluetooth | GattServer | removeService(serviceUuid: string): boolean; | Added|
| ohos.bluetooth | GattServer | addService(service: GattService): boolean; | Added|
| ohos.bluetooth | GattServer | stopAdvertising(): void; | Added|
| ohos.bluetooth | GattServer | startAdvertising(setting: AdvertiseSetting, advData: AdvertiseData, advResponse?: AdvertiseData): void; | Added|
| ohos.bluetooth | BLE | off(type: "BLEDeviceFind", callback?: Callback\<Array\<ScanResult>>): void; | Added|
| ohos.bluetooth | BLE | on(type: "BLEDeviceFind", callback: Callback\<Array\<ScanResult>>): void; | Added|
| ohos.bluetooth | BLE | stopBLEScan(): void; | Added|
| ohos.bluetooth | BLE | startBLEScan(filters: Array\<ScanFilter>, options?: ScanOptions): void; | Added|
| ohos.bluetooth | BLE | getConnectedBLEDevices(): Array\<string>; | Added|
| ohos.bluetooth | BLE | createGattClientDevice(deviceId: string): GattClientDevice; | Added|
| ohos.bluetooth | BLE | createGattServer(): GattServer; | Added|
| ohos.bluetooth | HandsFreeAudioGatewayProfile | off(type: "connectionStateChange", callback?: Callback\<StateChangeParam>): void; | Added|
| ohos.bluetooth | HandsFreeAudioGatewayProfile | on(type: "connectionStateChange", callback: Callback\<StateChangeParam>): void; | Added|
| ohos.bluetooth | HandsFreeAudioGatewayProfile | disconnect(device: string): boolean; | Added|
| ohos.bluetooth | HandsFreeAudioGatewayProfile | connect(device: string): boolean; | Added|
| ohos.bluetooth | A2dpSourceProfile | getPlayingState(device: string): PlayingState; | Added|
| ohos.bluetooth | A2dpSourceProfile | off(type: "connectionStateChange", callback?: Callback\<StateChangeParam>): void; | Added|
| ohos.bluetooth | A2dpSourceProfile | on(type: "connectionStateChange", callback: Callback\<StateChangeParam>): void; | Added|
| ohos.bluetooth | A2dpSourceProfile | disconnect(device: string): boolean; | Added|
| ohos.bluetooth | A2dpSourceProfile | connect(device: string): boolean; | Added|
| ohos.bluetooth | BaseProfile | getDeviceState(device: string): ProfileConnectionState; | Added|
| ohos.bluetooth | BaseProfile | getConnectionDevices(): Array\<string>; | Added|
| ohos.bluetooth | bluetooth | getProfile(profileId: ProfileId): A2dpSourceProfile \| HandsFreeAudioGatewayProfile; | Added|
| ohos.bluetooth | bluetooth | off(type: "sppRead", clientSocket: number, callback?: Callback\<ArrayBuffer>): void; | Added|
| ohos.bluetooth | bluetooth | on(type: "sppRead", clientSocket: number, callback: Callback\<ArrayBuffer>): void; | Added|
| ohos.bluetooth | bluetooth | sppWrite(clientSocket: number, data: ArrayBuffer): boolean; | Added|
| ohos.bluetooth | bluetooth | sppCloseClientSocket(socket: number): void; | Added|
| ohos.bluetooth | bluetooth | sppCloseServerSocket(socket: number): void; | Added|
| ohos.bluetooth | bluetooth | sppConnect(device: string, option: SppOption, callback: AsyncCallback\<number>): void; | Added|
| ohos.bluetooth | bluetooth | sppAccept(serverSocket: number, callback: AsyncCallback\<number>): void; | Added|
| ohos.bluetooth | bluetooth | sppListen(name: string, option: SppOption, callback: AsyncCallback\<number>): void; | Added|
| ohos.bluetooth | bluetooth | off(type: "stateChange", callback?: Callback\<BluetoothState>): void; | Added|
| ohos.bluetooth | bluetooth | on(type: "stateChange", callback: Callback\<BluetoothState>): void; | Added|
| ohos.bluetooth | bluetooth | off(type: "pinRequired", callback?: Callback\<PinRequiredParam>): void; | Added|
| ohos.bluetooth | bluetooth | on(type: "pinRequired", callback: Callback\<PinRequiredParam>): void; | Added|
| ohos.bluetooth | bluetooth | off(type: "bondStateChange", callback?: Callback\<BondStateParam>): void; | Added|
| ohos.bluetooth | bluetooth | on(type: "bondStateChange", callback: Callback\<BondStateParam>): void; | Added|
| ohos.bluetooth | bluetooth | off(type: "bluetoothDeviceFind", callback?: Callback\<Array\<string>>): void; | Added|
| ohos.bluetooth | bluetooth | on(type: "bluetoothDeviceFind", callback: Callback\<Array\<string>>): void; | Added|
| ohos.bluetooth | bluetooth | stopBluetoothDiscovery(): boolean; | Added|
| ohos.bluetooth | bluetooth | startBluetoothDiscovery(): boolean; | Added|
| ohos.bluetooth | bluetooth | getBluetoothScanMode(): ScanMode; | Added|
| ohos.bluetooth | bluetooth | setBluetoothScanMode(mode: ScanMode, duration: number): boolean; | Added|
| ohos.bluetooth | bluetooth | setLocalName(name: string): boolean; | Added|
| ohos.bluetooth | bluetooth | setDevicePairingConfirmation(device: string, accept: boolean): boolean; | Added|
| ohos.bluetooth | bluetooth | getProfileConnState(profileId: ProfileId): ProfileConnectionState; | Added|
| ohos.bluetooth | bluetooth | getPairedDevices(): Array\<string>; | Added|
| ohos.bluetooth | bluetooth | getLocalName(): string; | Added|
| ohos.bluetooth | bluetooth | disableBluetooth(): boolean; | Added|
| ohos.bluetooth | bluetooth | enableBluetooth(): boolean; | Added|
| ohos.bluetooth | bluetooth | getRemoteDeviceClass(deviceId: string): DeviceClass; | Added|
| ohos.bluetooth | bluetooth | getRemoteDeviceName(deviceId: string): string; | Added|
| ohos.bluetooth | bluetooth | pairDevice(deviceId: string): boolean; | Added|
| ohos.bluetooth | bluetooth | getBtConnectionState(): ProfileConnectionState; | Added|
| ohos.bluetooth | bluetooth | getState(): BluetoothState; | Added|
