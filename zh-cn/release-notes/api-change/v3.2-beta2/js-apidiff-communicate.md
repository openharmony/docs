# 基础通信子系统JS API变更

OpenHarmony 3.2 Beta2版本相较于OpenHarmony 3.2 Beta1版本，基础通信子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| nfctech | NdefFormatableTag | formatReadOnly(message: NdefMessage): Promise\<number>;<br>formatReadOnly(message: NdefMessage, callback: AsyncCallback\<number>): void; | 新增 |
| nfctech | NdefFormatableTag | format(message: NdefMessage): Promise\<number>;<br>format(message: NdefMessage, callback: AsyncCallback\<number>): void; | 新增 |
| nfctech | MifareUltralightTag | getType(): MifareUltralightType; | 新增 |
| nfctech | MifareUltralightTag | writeSinglePages(pageIndex: number, data: string): Promise\<number>;<br>writeSinglePages(pageIndex: number, data: string, callback: AsyncCallback\<number>): void; | 新增 |
| nfctech | MifareUltralightTag | readMultiplePages(pageIndex: number): Promise\<string>;<br>readMultiplePages(pageIndex: number, callback: AsyncCallback\<string>): void; | 新增 |
| nfctech | MifareUltralightType | TYPE_ULTRALIGHT_C = 2 | 新增 |
| nfctech | MifareUltralightType | TYPE_ULTRALIGHT = 1 | 新增 |
| nfctech | MifareUltralightType | TYPE_UNKOWN = -1 | 新增 |
| nfctech | MifareClassicTag | getSectorIndex(blockIndex: number): number; | 新增 |
| nfctech | MifareClassicTag | getBlockIndex(sectorIndex: number): number; | 新增 |
| nfctech | MifareClassicTag | isEmulatedTag(): boolean; | 新增 |
| nfctech | MifareClassicTag | getTagSize(): number; | 新增 |
| nfctech | MifareClassicTag | getType(): MifareClassicType; | 新增 |
| nfctech | MifareClassicTag | getBlockCountInSector(sectorIndex: number): number; | 新增 |
| nfctech | MifareClassicTag | getSectorCount(): number; | 新增 |
| nfctech | MifareClassicTag | restoreFromBlock(blockIndex: number): Promise\<number>;<br>restoreFromBlock(blockIndex: number, callback: AsyncCallback\<number>): void; | 新增 |
| nfctech | MifareClassicTag | transferToBlock(blockIndex: number): Promise\<number>;<br>transferToBlock(blockIndex: number, callback: AsyncCallback\<number>): void; | 新增 |
| nfctech | MifareClassicTag | decrementBlock(blockIndex: number, value: number): Promise\<number>;<br>decrementBlock(blockIndex: number, value: number, callback: AsyncCallback\<number>): void; | 新增 |
| nfctech | MifareClassicTag | incrementBlock(blockIndex: number, value: number): Promise\<number>;<br>incrementBlock(blockIndex: number, value: number, callback: AsyncCallback\<number>): void; | 新增 |
| nfctech | MifareClassicTag | writeSingleBlock(blockIndex: number, data: string): Promise\<number>;<br>writeSingleBlock(blockIndex: number, data: string, callback: AsyncCallback\<number>): void; | 新增 |
| nfctech | MifareClassicTag | readSingleBlock(blockIndex: number): Promise\<string>;<br>readSingleBlock(blockIndex: number, callback: AsyncCallback\<string>): void; | 新增 |
| nfctech | MifareClassicTag | authenticateSector(sectorIndex: number, key: number[], isKeyA: boolean): Promise\<boolean>;<br>authenticateSector(sectorIndex: number, key: number[], isKeyA: boolean, callback: AsyncCallback\<boolean>): void; | 新增 |
| nfctech | MifareTagSize | MC_SIZE_4K = 4096 | 新增 |
| nfctech | MifareTagSize | MC_SIZE_2K = 2048 | 新增 |
| nfctech | MifareTagSize | MC_SIZE_1K = 1024 | 新增 |
| nfctech | MifareTagSize | MC_SIZE_MINI = 320 | 新增 |
| nfctech | MifareClassicType | TYPE_PRO = 2 | 新增 |
| nfctech | MifareClassicType | TYPE_PLUS = 1 | 新增 |
| nfctech | MifareClassicType | TYPE_CLASSIC = 0 | 新增 |
| nfctech | MifareClassicType | TYPE_UNKNOWN = -1 | 新增 |
| nfctech | NdefTag | getNdefTagTypeString(type: NfcForumType): string; | 新增 |
| nfctech | NdefTag | setReadOnly(): Promise\<number>;<br>setReadOnly(callback: AsyncCallback\<number>): void; | 新增 |
| nfctech | NdefTag | canSetReadOnly(): Promise\<boolean>;<br>canSetReadOnly(callback: AsyncCallback\<boolean>): void; | 新增 |
| nfctech | NdefTag | writeNdef(msg: NdefMessage): Promise\<number>;<br>writeNdef(msg: NdefMessage, callback: AsyncCallback\<number>): void; | 新增 |
| nfctech | NdefTag | readNdef(): Promise\<NdefMessage>;<br>readNdef(callback: AsyncCallback\<NdefMessage>): void; | 新增 |
| nfctech | NdefTag | isNdefWritable(): Promise\<boolean>;<br>isNdefWritable(callback: AsyncCallback\<boolean>): void; | 新增 |
| nfctech | NdefTag | getNdefMessage(): NdefMessage; | 新增 |
| nfctech | NdefTag | getNdefTagType(): NfcForumType; | 新增 |
| nfctech | NdefTag | createNdefMessage(data: string): NdefMessage;<br>createNdefMessage(ndefRecords: NdefRecord[]): NdefMessage; | 新增 |
| nfctech | NfcForumType | MIFARE_CLASSIC = 101 | 新增 |
| nfctech | NfcForumType | NFC_FORUM_TYPE_4 = 4 | 新增 |
| nfctech | NfcForumType | NFC_FORUM_TYPE_3 = 3 | 新增 |
| nfctech | NfcForumType | NFC_FORUM_TYPE_2 = 2 | 新增 |
| nfctech | NfcForumType | NFC_FORUM_TYPE_1 = 1 | 新增 |
| nfctech | NdefMessage | messageToString(ndefMessage: NdefMessage): string; | 新增 |
| nfctech | NdefMessage | makeExternalRecord(domainName: string, serviceName: string, externalData: string): NdefRecord; | 新增 |
| nfctech | NdefMessage | makeMimeRecord(mimeType: string, mimeData: string): NdefRecord; | 新增 |
| nfctech | NdefMessage | makeTextRecord(text: string, locale: string): NdefRecord; | 新增 |
| nfctech | NdefMessage | makeUriRecord(uri: string): NdefRecord; | 新增 |
| nfctech | NdefMessage | getNdefRecords(): NdefRecord[]; | 新增 |
| nfctech | RtdType | RTD_URI: 'U'; | 新增 |
| nfctech | RtdType | RTD_TEXT: 'T'; | 新增 |
| nfctech | TnfType | TNF_UNCHANGED = 0x6 | 新增 |
| nfctech | TnfType | TNF_UNKNOWN = 0x5 | 新增 |
| nfctech | TnfType | TNF_EXT_APP = 0x4 | 新增 |
| nfctech | TnfType | TNF_ABSOLUTE_URI = 0x3 | 新增 |
| nfctech | TnfType | TNF_MEDIA = 0x2 | 新增 |
| nfctech | TnfType | TNF_WELL_KNOWN = 0x1 | 新增 |
| nfctech | TnfType | TNF_EMPTY = 0x0 | 新增 |
| nfctech | NdefRecord | payload: string; | 新增 |
| nfctech | NdefRecord | id: string; | 新增 |
| nfctech | NdefRecord | rtdType: string; | 新增 |
| nfctech | NdefRecord | tnf: number; | 新增 |
| nfctech | IsoDepTag | isExtendedApduSupported(): Promise\<boolean>;<br>isExtendedApduSupported(callback: AsyncCallback\<boolean>): void; | 新增 |
| nfctech | IsoDepTag | getHiLayerResponse(): string; | 新增 |
| nfctech | IsoDepTag | getHistoricalBytes(): string; | 新增 |
| ohos.bluetooth | ProfileId | PROFILE_PAN_NETWORK = 7 | 新增 |
| ohos.bluetooth | ScanFilter | manufactureDataMask?: ArrayBuffer; | 新增 |
| ohos.bluetooth | ScanFilter | manufactureData?: ArrayBuffer; | 新增 |
| ohos.bluetooth | ScanFilter | manufactureId?: number; | 新增 |
| ohos.bluetooth | ScanFilter | serviceDataMask?: ArrayBuffer; | 新增 |
| ohos.bluetooth | ScanFilter | serviceData?: ArrayBuffer; | 新增 |
| ohos.bluetooth | ScanFilter | serviceSolicitationUuidMask?: string; | 新增 |
| ohos.bluetooth | ScanFilter | serviceSolicitationUuid?: string; | 新增 |
| ohos.bluetooth | ScanFilter | serviceUuidMask?: string; | 新增 |
| ohos.bluetooth | PanProfile | isTetheringOn(): boolean; | 新增 |
| ohos.bluetooth | PanProfile | setTethering(enable: boolean): void; | 新增 |
| ohos.bluetooth | PanProfile | off(type: "connectionStateChange", callback?: Callback\<StateChangeParam>): void; | 新增 |
| ohos.bluetooth | PanProfile | on(type: "connectionStateChange", callback: Callback\<StateChangeParam>): void; | 新增 |
| ohos.bluetooth | PanProfile | disconnect(device: string): boolean; | 新增 |
| ohos.bluetooth | bluetooth | getProfileInst(profileId: ProfileId): A2dpSourceProfile \| HandsFreeAudioGatewayProfile \| HidHostProfile \| PanProfile; | 新增 |
| ohos.nfc.tag | TagInfo | remoteTagService: rpc.RemoteObject; | 新增 |
| ohos.nfc.tag | TagInfo | tagRfDiscId: number; | 新增 |
| ohos.nfc.tag | TagInfo | extrasData: PacMap[]; | 新增 |
| ohos.nfc.tag | TagInfo | technology: number[]; | 新增 |
| ohos.nfc.tag | TagInfo | uid: string; | 新增 |
| ohos.nfc.tag | tag | getNdefFormatableTag(tagInfo: TagInfo): NdefFormatableTag | 新增 |
| ohos.nfc.tag | tag | getMifareUltralightTag(tagInfo: TagInfo): MifareUltralightTag | 新增 |
| ohos.nfc.tag | tag | getMifareClassicTag(tagInfo: TagInfo): MifareClassicTag | 新增 |
| ohos.nfc.tag | tag | getNdefTag(tagInfo: TagInfo): NdefTag | 新增 |
| ohos.nfc.tag | tag | getIsoDepTag(tagInfo: TagInfo): IsoDepTag | 新增 |
| ohos.nfc.tag | tag | const NDEF_FORMATABLE = 10; | 新增 |
| ohos.wifi | WifiLinkedInfo | macType: number; | 新增 |
| ohos.wifi | WifiSecurityType | WIFI_SEC_TYPE_WAPI_PSK = 9 | 新增 |
| ohos.wifi | WifiSecurityType | WIFI_SEC_TYPE_WAPI_CERT = 8 | 新增 |
| ohos.wifi | WifiSecurityType | WIFI_SEC_TYPE_OWE = 7 | 新增 |
| ohos.wifi | WifiSecurityType | WIFI_SEC_TYPE_EAP_SUITE_B = 6 | 新增 |
| ohos.wifi | WifiSecurityType | WIFI_SEC_TYPE_EAP = 5 | 新增 |
| ohos.wifi | WifiScanInfo | infoElems: Array\<WifiInfoElem>; | 新增 |
| ohos.wifi | WifiScanInfo | centerFrequency1: number; | 新增 |
| ohos.wifi | WifiScanInfo | centerFrequency0: number; | 新增 |
| ohos.wifi | WifiChannelWidth | WIDTH_INVALID | 新增 |
| ohos.wifi | WifiChannelWidth | WIDTH_80MHZ_PLUS = 4 | 新增 |
| ohos.wifi | WifiChannelWidth | WIDTH_160MHZ = 3 | 新增 |
| ohos.wifi | WifiChannelWidth | WIDTH_80MHZ = 2 | 新增 |
| ohos.wifi | WifiChannelWidth | WIDTH_40MHZ = 1 | 新增 |
| ohos.wifi | WifiChannelWidth | WIDTH_20MHZ = 0 | 新增 |
| ohos.wifi | WifiInfoElem | content: Uint8Array; | 新增 |
| ohos.wifi | WifiInfoElem | eid: number; | 新增 |
| ohos.wifi | WifiDeviceConfig | eapConfig: WifiEapConfig; | 新增 |
| ohos.wifi | WifiEapConfig | eapSubId: number; | 新增 |
| ohos.wifi | WifiEapConfig | plmn: string; | 新增 |
| ohos.wifi | WifiEapConfig | realm: string; | 新增 |
| ohos.wifi | WifiEapConfig | domainSuffixMatch: string; | 新增 |
| ohos.wifi | WifiEapConfig | altSubjectMatch: string; | 新增 |
| ohos.wifi | WifiEapConfig | clientCertAliases: string; | 新增 |
| ohos.wifi | WifiEapConfig | caPath: string; | 新增 |
| ohos.wifi | WifiEapConfig | caCertAliases: string; | 新增 |
| ohos.wifi | WifiEapConfig | password: string; | 新增 |
| ohos.wifi | WifiEapConfig | anonymousIdentity: string; | 新增 |
| ohos.wifi | WifiEapConfig | identity: string; | 新增 |
| ohos.wifi | WifiEapConfig | phase2Method: Phase2Method; | 新增 |
| ohos.wifi | WifiEapConfig | eapMethod: EapMethod; | 新增 |
| ohos.wifi | Phase2Method | PHASE2_AKA_PRIME | 新增 |
| ohos.wifi | Phase2Method | PHASE2_AKA | 新增 |
| ohos.wifi | Phase2Method | PHASE2_SIM | 新增 |
| ohos.wifi | Phase2Method | PHASE2_GTC | 新增 |
| ohos.wifi | Phase2Method | PHASE2_MSCHAPV2 | 新增 |
| ohos.wifi | Phase2Method | PHASE2_MSCHAP | 新增 |
| ohos.wifi | Phase2Method | PHASE2_PAP | 新增 |
| ohos.wifi | Phase2Method | PHASE2_NONE | 新增 |
| ohos.wifi | EapMethod | EAP_UNAUTH_TLS | 新增 |
| ohos.wifi | EapMethod | EAP_AKA_PRIME | 新增 |
| ohos.wifi | EapMethod | EAP_AKA | 新增 |
| ohos.wifi | EapMethod | EAP_SIM | 新增 |
| ohos.wifi | EapMethod | EAP_PWD | 新增 |
| ohos.wifi | EapMethod | EAP_TTLS | 新增 |
| ohos.wifi | EapMethod | EAP_TLS | 新增 |
| ohos.wifi | EapMethod | EAP_PEAP | 新增 |
| ohos.wifi | EapMethod | EAP_NONE | 新增 |
| ohos.wifi | wifi | getP2pGroups(): Promise\<Array\<WifiP2pGroupInfo>>;<br>getP2pGroups(callback: AsyncCallback\<Array\<WifiP2pGroupInfo>>): void; | 新增 |
| ohos.wifi | wifi | getP2pLocalDevice(): Promise\<WifiP2pDevice>;<br>getP2pLocalDevice(callback: AsyncCallback\<WifiP2pDevice>): void; | 新增 |
| ohos.wifi | wifi | connectToCandidateConfig(networkId: number): void; | 新增 |
| ohos.wifi | wifi | getCandidateConfigs(): Array\<WifiDeviceConfig>; | 新增 |
| ohos.wifi | wifi | removeCandidateConfig(networkId: number): Promise\<void>;<br>removeCandidateConfig(networkId: number, callback: AsyncCallback\<void>): void; | 新增 |
| ohos.wifi | wifi | addCandidateConfig(config: WifiDeviceConfig): Promise\<number>;<br>addCandidateConfig(config: WifiDeviceConfig, callback: AsyncCallback\<number>): void; | 新增 |
| ohos.wifi | wifi | getScanInfosSync(): Array\<WifiScanInfo>; | 新增 |
| ohos.bluetooth | A2dpSourceProfile | getPlayingState(device: string): PlayingState; | 废弃 |
| ohos.nfc.tag | TagInfo | supportedProfiles: number[]; | 废弃 |

