# JS API Changes of the Communication Subsystem

The table below lists the APIs changes of the communication subsystem in OpenHarmony 3.2 Beta2 over OpenHarmony 3.2 Beta1.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| nfctech | NdefFormatableTag | formatReadOnly(message: NdefMessage): Promise\<number>;<br>formatReadOnly(message: NdefMessage, callback: AsyncCallback\<number>): void; | Added|
| nfctech | NdefFormatableTag | format(message: NdefMessage): Promise\<number>;<br>format(message: NdefMessage, callback: AsyncCallback\<number>): void; | Added|
| nfctech | MifareUltralightTag | getType(): MifareUltralightType; | Added|
| nfctech | MifareUltralightTag | writeSinglePages(pageIndex: number, data: string): Promise\<number>;<br>writeSinglePages(pageIndex: number, data: string, callback: AsyncCallback\<number>): void; | Added|
| nfctech | MifareUltralightTag | readMultiplePages(pageIndex: number): Promise\<string>;<br>readMultiplePages(pageIndex: number, callback: AsyncCallback\<string>): void; | Added|
| nfctech | MifareUltralightType | TYPE_ULTRALIGHT_C = 2 | Added|
| nfctech | MifareUltralightType | TYPE_ULTRALIGHT = 1 | Added|
| nfctech | MifareUltralightType | TYPE_UNKOWN = -1 | Added|
| nfctech | MifareClassicTag | getSectorIndex(blockIndex: number): number; | Added|
| nfctech | MifareClassicTag | getBlockIndex(sectorIndex: number): number; | Added|
| nfctech | MifareClassicTag | isEmulatedTag(): boolean; | Added|
| nfctech | MifareClassicTag | getTagSize(): number; | Added|
| nfctech | MifareClassicTag | getType(): MifareClassicType; | Added|
| nfctech | MifareClassicTag | getBlockCountInSector(sectorIndex: number): number; | Added|
| nfctech | MifareClassicTag | getSectorCount(): number; | Added|
| nfctech | MifareClassicTag | restoreFromBlock(blockIndex: number): Promise\<number>;<br>restoreFromBlock(blockIndex: number, callback: AsyncCallback\<number>): void; | Added|
| nfctech | MifareClassicTag | transferToBlock(blockIndex: number): Promise\<number>;<br>transferToBlock(blockIndex: number, callback: AsyncCallback\<number>): void; | Added|
| nfctech | MifareClassicTag | decrementBlock(blockIndex: number, value: number): Promise\<number>;<br>decrementBlock(blockIndex: number, value: number, callback: AsyncCallback\<number>): void; | Added|
| nfctech | MifareClassicTag | incrementBlock(blockIndex: number, value: number): Promise\<number>;<br>incrementBlock(blockIndex: number, value: number, callback: AsyncCallback\<number>): void; | Added|
| nfctech | MifareClassicTag | writeSingleBlock(blockIndex: number, data: string): Promise\<number>;<br>writeSingleBlock(blockIndex: number, data: string, callback: AsyncCallback\<number>): void; | Added|
| nfctech | MifareClassicTag | readSingleBlock(blockIndex: number): Promise\<string>;<br>readSingleBlock(blockIndex: number, callback: AsyncCallback\<string>): void; | Added|
| nfctech | MifareClassicTag | authenticateSector(sectorIndex: number, key: number[], isKeyA: boolean): Promise\<boolean>;<br>authenticateSector(sectorIndex: number, key: number[], isKeyA: boolean, callback: AsyncCallback\<boolean>): void; | Added|
| nfctech | MifareTagSize | MC_SIZE_4K = 4096 | Added|
| nfctech | MifareTagSize | MC_SIZE_2K = 2048 | Added|
| nfctech | MifareTagSize | MC_SIZE_1K = 1024 | Added|
| nfctech | MifareTagSize | MC_SIZE_MINI = 320 | Added|
| nfctech | MifareClassicType | TYPE_PRO = 2 | Added|
| nfctech | MifareClassicType | TYPE_PLUS = 1 | Added|
| nfctech | MifareClassicType | TYPE_CLASSIC = 0 | Added|
| nfctech | MifareClassicType | TYPE_UNKNOWN = -1 | Added|
| nfctech | NdefTag | getNdefTagTypeString(type: NfcForumType): string; | Added|
| nfctech | NdefTag | setReadOnly(): Promise\<number>;<br>setReadOnly(callback: AsyncCallback\<number>): void; | Added|
| nfctech | NdefTag | canSetReadOnly(): Promise\<boolean>;<br>canSetReadOnly(callback: AsyncCallback\<boolean>): void; | Added|
| nfctech | NdefTag | writeNdef(msg: NdefMessage): Promise\<number>;<br>writeNdef(msg: NdefMessage, callback: AsyncCallback\<number>): void; | Added|
| nfctech | NdefTag | readNdef(): Promise\<NdefMessage>;<br>readNdef(callback: AsyncCallback\<NdefMessage>): void; | Added|
| nfctech | NdefTag | isNdefWritable(): Promise\<boolean>;<br>isNdefWritable(callback: AsyncCallback\<boolean>): void; | Added|
| nfctech | NdefTag | getNdefMessage(): NdefMessage; | Added|
| nfctech | NdefTag | getNdefTagType(): NfcForumType; | Added|
| nfctech | NdefTag | createNdefMessage(data: string): NdefMessage;<br>createNdefMessage(ndefRecords: NdefRecord[]): NdefMessage; | Added|
| nfctech | NfcForumType | MIFARE_CLASSIC = 101 | Added|
| nfctech | NfcForumType | NFC_FORUM_TYPE_4 = 4 | Added|
| nfctech | NfcForumType | NFC_FORUM_TYPE_3 = 3 | Added|
| nfctech | NfcForumType | NFC_FORUM_TYPE_2 = 2 | Added|
| nfctech | NfcForumType | NFC_FORUM_TYPE_1 = 1 | Added|
| nfctech | NdefMessage | messageToString(ndefMessage: NdefMessage): string; | Added|
| nfctech | NdefMessage | makeExternalRecord(domainName: string, serviceName: string, externalData: string): NdefRecord; | Added|
| nfctech | NdefMessage | makeMimeRecord(mimeType: string, mimeData: string): NdefRecord; | Added|
| nfctech | NdefMessage | makeTextRecord(text: string, locale: string): NdefRecord; | Added|
| nfctech | NdefMessage | makeUriRecord(uri: string): NdefRecord; | Added|
| nfctech | NdefMessage | getNdefRecords(): NdefRecord[]; | Added|
| nfctech | RtdType | RTD_URI: 'U'; | Added|
| nfctech | RtdType | RTD_TEXT: 'T'; | Added|
| nfctech | TnfType | TNF_UNCHANGED = 0x6 | Added|
| nfctech | TnfType | TNF_UNKNOWN = 0x5 | Added|
| nfctech | TnfType | TNF_EXT_APP = 0x4 | Added|
| nfctech | TnfType | TNF_ABSOLUTE_URI = 0x3 | Added|
| nfctech | TnfType | TNF_MEDIA = 0x2 | Added|
| nfctech | TnfType | TNF_WELL_KNOWN = 0x1 | Added|
| nfctech | TnfType | TNF_EMPTY = 0x0 | Added|
| nfctech | NdefRecord | payload: string; | Added|
| nfctech | NdefRecord | id: string; | Added|
| nfctech | NdefRecord | rtdType: string; | Added|
| nfctech | NdefRecord | tnf: number; | Added|
| nfctech | IsoDepTag | isExtendedApduSupported(): Promise\<boolean>;<br>isExtendedApduSupported(callback: AsyncCallback\<boolean>): void; | Added|
| nfctech | IsoDepTag | getHiLayerResponse(): string; | Added|
| nfctech | IsoDepTag | getHistoricalBytes(): string; | Added|
| ohos.bluetooth | ProfileId | PROFILE_PAN_NETWORK = 7 | Added|
| ohos.bluetooth | ScanFilter | manufactureDataMask?: ArrayBuffer; | Added|
| ohos.bluetooth | ScanFilter | manufactureData?: ArrayBuffer; | Added|
| ohos.bluetooth | ScanFilter | manufactureId?: number; | Added|
| ohos.bluetooth | ScanFilter | serviceDataMask?: ArrayBuffer; | Added|
| ohos.bluetooth | ScanFilter | serviceData?: ArrayBuffer; | Added|
| ohos.bluetooth | ScanFilter | serviceSolicitationUuidMask?: string; | Added|
| ohos.bluetooth | ScanFilter | serviceSolicitationUuid?: string; | Added|
| ohos.bluetooth | ScanFilter | serviceUuidMask?: string; | Added|
| ohos.bluetooth | PanProfile | isTetheringOn(): boolean; | Added|
| ohos.bluetooth | PanProfile | setTethering(enable: boolean): void; | Added|
| ohos.bluetooth | PanProfile | off(type: "connectionStateChange", callback?: Callback\<StateChangeParam>): void; | Added|
| ohos.bluetooth | PanProfile | on(type: "connectionStateChange", callback: Callback\<StateChangeParam>): void; | Added|
| ohos.bluetooth | PanProfile | disconnect(device: string): boolean; | Added|
| ohos.bluetooth | bluetooth | getProfileInst(profileId: ProfileId): A2dpSourceProfile \| HandsFreeAudioGatewayProfile \| HidHostProfile \| PanProfile; | Added|
| ohos.nfc.tag | TagInfo | remoteTagService: rpc.RemoteObject; | Added|
| ohos.nfc.tag | TagInfo | tagRfDiscId: number; | Added|
| ohos.nfc.tag | TagInfo | extrasData: PacMap[]; | Added|
| ohos.nfc.tag | TagInfo | technology: number[]; | Added|
| ohos.nfc.tag | TagInfo | uid: string; | Added|
| ohos.nfc.tag | tag | getNdefFormatableTag(tagInfo: TagInfo): NdefFormatableTag | Added|
| ohos.nfc.tag | tag | getMifareUltralightTag(tagInfo: TagInfo): MifareUltralightTag | Added|
| ohos.nfc.tag | tag | getMifareClassicTag(tagInfo: TagInfo): MifareClassicTag | Added|
| ohos.nfc.tag | tag | getNdefTag(tagInfo: TagInfo): NdefTag | Added|
| ohos.nfc.tag | tag | getIsoDepTag(tagInfo: TagInfo): IsoDepTag | Added|
| ohos.nfc.tag | tag | const NDEF_FORMATABLE = 10; | Added|
| ohos.wifi | WifiLinkedInfo | macType: number; | Added|
| ohos.wifi | WifiSecurityType | WIFI_SEC_TYPE_WAPI_PSK = 9 | Added|
| ohos.wifi | WifiSecurityType | WIFI_SEC_TYPE_WAPI_CERT = 8 | Added|
| ohos.wifi | WifiSecurityType | WIFI_SEC_TYPE_OWE = 7 | Added|
| ohos.wifi | WifiSecurityType | WIFI_SEC_TYPE_EAP_SUITE_B = 6 | Added|
| ohos.wifi | WifiSecurityType | WIFI_SEC_TYPE_EAP = 5 | Added|
| ohos.wifi | WifiScanInfo | infoElems: Array\<WifiInfoElem>; | Added|
| ohos.wifi | WifiScanInfo | centerFrequency1: number; | Added|
| ohos.wifi | WifiScanInfo | centerFrequency0: number; | Added|
| ohos.wifi | WifiChannelWidth | WIDTH_INVALID | Added|
| ohos.wifi | WifiChannelWidth | WIDTH_80MHZ_PLUS = 4 | Added|
| ohos.wifi | WifiChannelWidth | WIDTH_160MHZ = 3 | Added|
| ohos.wifi | WifiChannelWidth | WIDTH_80MHZ = 2 | Added|
| ohos.wifi | WifiChannelWidth | WIDTH_40MHZ = 1 | Added|
| ohos.wifi | WifiChannelWidth | WIDTH_20MHZ = 0 | Added|
| ohos.wifi | WifiInfoElem | content: Uint8Array; | Added|
| ohos.wifi | WifiInfoElem | eid: number; | Added|
| ohos.wifi | WifiDeviceConfig | eapConfig: WifiEapConfig; | Added|
| ohos.wifi | WifiEapConfig | eapSubId: number; | Added|
| ohos.wifi | WifiEapConfig | plmn: string; | Added|
| ohos.wifi | WifiEapConfig | realm: string; | Added|
| ohos.wifi | WifiEapConfig | domainSuffixMatch: string; | Added|
| ohos.wifi | WifiEapConfig | altSubjectMatch: string; | Added|
| ohos.wifi | WifiEapConfig | clientCertAliases: string; | Added|
| ohos.wifi | WifiEapConfig | caPath: string; | Added|
| ohos.wifi | WifiEapConfig | caCertAliases: string; | Added|
| ohos.wifi | WifiEapConfig | password: string; | Added|
| ohos.wifi | WifiEapConfig | anonymousIdentity: string; | Added|
| ohos.wifi | WifiEapConfig | identity: string; | Added|
| ohos.wifi | WifiEapConfig | phase2Method: Phase2Method; | Added|
| ohos.wifi | WifiEapConfig | eapMethod: EapMethod; | Added|
| ohos.wifi | Phase2Method | PHASE2_AKA_PRIME | Added|
| ohos.wifi | Phase2Method | PHASE2_AKA | Added|
| ohos.wifi | Phase2Method | PHASE2_SIM | Added|
| ohos.wifi | Phase2Method | PHASE2_GTC | Added|
| ohos.wifi | Phase2Method | PHASE2_MSCHAPV2 | Added|
| ohos.wifi | Phase2Method | PHASE2_MSCHAP | Added|
| ohos.wifi | Phase2Method | PHASE2_PAP | Added|
| ohos.wifi | Phase2Method | PHASE2_NONE | Added|
| ohos.wifi | EapMethod | EAP_UNAUTH_TLS | Added|
| ohos.wifi | EapMethod | EAP_AKA_PRIME | Added|
| ohos.wifi | EapMethod | EAP_AKA | Added|
| ohos.wifi | EapMethod | EAP_SIM | Added|
| ohos.wifi | EapMethod | EAP_PWD | Added|
| ohos.wifi | EapMethod | EAP_TTLS | Added|
| ohos.wifi | EapMethod | EAP_TLS | Added|
| ohos.wifi | EapMethod | EAP_PEAP | Added|
| ohos.wifi | EapMethod | EAP_NONE | Added|
| ohos.wifi | wifi | getP2pGroups(): Promise\<Array\<WifiP2pGroupInfo>>;<br>getP2pGroups(callback: AsyncCallback\<Array\<WifiP2pGroupInfo>>): void; | Added|
| ohos.wifi | wifi | getP2pLocalDevice(): Promise\<WifiP2pDevice>;<br>getP2pLocalDevice(callback: AsyncCallback\<WifiP2pDevice>): void; | Added|
| ohos.wifi | wifi | connectToCandidateConfig(networkId: number): void; | Added|
| ohos.wifi | wifi | getCandidateConfigs(): Array\<WifiDeviceConfig>; | Added|
| ohos.wifi | wifi | removeCandidateConfig(networkId: number): Promise\<void>;<br>removeCandidateConfig(networkId: number, callback: AsyncCallback\<void>): void; | Added|
| ohos.wifi | wifi | addCandidateConfig(config: WifiDeviceConfig): Promise\<number>;<br>addCandidateConfig(config: WifiDeviceConfig, callback: AsyncCallback\<number>): void; | Added|
| ohos.wifi | wifi | getScanInfosSync(): Array\<WifiScanInfo>; | Added|
| ohos.bluetooth | A2dpSourceProfile | getPlayingState(device: string): PlayingState; | Deprecated|
| ohos.nfc.tag | TagInfo | supportedProfiles: number[]; | Deprecated|
