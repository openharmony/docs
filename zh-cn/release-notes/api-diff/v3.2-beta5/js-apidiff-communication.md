| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：connectedTag<br>方法or属性：function initialize(): void;|@ohos.connectedTag.d.ts|
|新增|NA|类名：connectedTag<br>方法or属性：function uninitialize(): void;|@ohos.connectedTag.d.ts|
|新增|NA|类名：connectedTag<br>方法or属性：function read(): Promise<number[]>;|@ohos.connectedTag.d.ts|
|新增|NA|类名：connectedTag<br>方法or属性：function read(callback: AsyncCallback<number[]>): void;|@ohos.connectedTag.d.ts|
|新增|NA|类名：connectedTag<br>方法or属性：function write(data: number[]): Promise<void>;|@ohos.connectedTag.d.ts|
|新增|NA|类名：connectedTag<br>方法or属性：function write(data: number[], callback: AsyncCallback<void>): void;|@ohos.connectedTag.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: sharing|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: sharing<br>方法 or 属性: function isSharingSupported(callback: AsyncCallback<boolean>): void;|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: sharing<br>方法 or 属性: function isSharingSupported(): Promise<boolean>;|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: sharing<br>方法 or 属性: function isSharing(callback: AsyncCallback<boolean>): void;|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: sharing<br>方法 or 属性: function isSharing(): Promise<boolean>;|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: sharing<br>方法 or 属性: function startSharing(type: SharingIfaceType, callback: AsyncCallback<void>): void;|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: sharing<br>方法 or 属性: function startSharing(type: SharingIfaceType): Promise<void>;|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: sharing<br>方法 or 属性: function stopSharing(type: SharingIfaceType, callback: AsyncCallback<void>): void;|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: sharing<br>方法 or 属性: function stopSharing(type: SharingIfaceType): Promise<void>;|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: sharing<br>方法 or 属性: function getStatsRxBytes(callback: AsyncCallback<number>): void;|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: sharing<br>方法 or 属性: function getStatsRxBytes(): Promise<number>;|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: sharing<br>方法 or 属性: function getStatsTxBytes(callback: AsyncCallback<number>): void;|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: sharing<br>方法 or 属性: function getStatsTxBytes(): Promise<number>;|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: sharing<br>方法 or 属性: function getStatsTotalBytes(callback: AsyncCallback<number>): void;|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: sharing<br>方法 or 属性: function getStatsTotalBytes(): Promise<number>;|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: sharing<br>方法 or 属性: function getSharingIfaces(state: SharingIfaceState, callback: AsyncCallback<Array<string>>): void;|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: sharing<br>方法 or 属性: function getSharingIfaces(state: SharingIfaceState): Promise<Array<string>>;|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: sharing<br>方法 or 属性: function getSharingState(type: SharingIfaceType, callback: AsyncCallback<SharingIfaceState>): void;|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: sharing<br>方法 or 属性: function getSharingState(type: SharingIfaceType): Promise<SharingIfaceState>;|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: sharing<br>方法 or 属性: function getSharableRegexes(type: SharingIfaceType, callback: AsyncCallback<Array<string>>): void;|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: sharing<br>方法 or 属性: function getSharableRegexes(type: SharingIfaceType): Promise<Array<string>>;|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: sharing<br>方法 or 属性: function on(type: 'sharingStateChange', callback: Callback<boolean>): void;|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: sharing<br>方法 or 属性: function off(type: 'sharingStateChange', callback?: Callback<boolean>): void;|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: sharing<br>方法 or 属性: function on(type: 'interfaceSharingStateChange', callback: Callback<{ type: SharingIfaceType, iface: string, state: SharingIfaceState }>): void;|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: sharing<br>方法 or 属性: function off(type: 'interfaceSharingStateChange', callback?: Callback<{ type: SharingIfaceType, iface: string, state: SharingIfaceState }>): void;|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: sharing<br>方法 or 属性: function on(type: 'sharingUpstreamChange', callback: Callback<NetHandle>): void;|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: sharing<br>方法 or 属性: function off(type: 'sharingUpstreamChange', callback?: Callback<NetHandle>): void;|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: SharingIfaceState|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: SharingIfaceState<br>方法 or 属性: SHARING_NIC_SERVING = 1|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: SharingIfaceState<br>方法 or 属性: SHARING_NIC_CAN_SERVER = 2|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: SharingIfaceState<br>方法 or 属性: SHARING_NIC_ERROR = 3|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: SharingIfaceType|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: SharingIfaceType<br>方法 or 属性: SHARING_WIFI = 0|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: SharingIfaceType<br>方法 or 属性: SHARING_USB = 1|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: SharingIfaceType<br>方法 or 属性: SHARING_BLUETOOTH = 2|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.nfc.cardEmulation<br>类名: CardType|@ohos.nfc.cardEmulation.d.ts|
|新增|NA|类名：CardType<br>方法or属性：|@ohos.nfc.cardEmulation.d.ts|
|新增|NA|模块名: ohos.nfc.cardEmulation<br>类名: CardType<br>方法 or 属性：PAYMENT = "payment"|@ohos.nfc.cardEmulation.d.ts|
|新增|NA|类名：CardType<br>方法or属性：PAYMENT = "payment"|@ohos.nfc.cardEmulation.d.ts|
|新增|NA|模块名: ohos.nfc.cardEmulation<br>类名: CardType<br>方法 or 属性：OTHER = "other"|@ohos.nfc.cardEmulation.d.ts|
|新增|NA|类名：CardType<br>方法or属性：OTHER = "other"|@ohos.nfc.cardEmulation.d.ts|
|新增|NA|类名：cardEmulation<br>方法or属性：function hasHceCapability(): boolean;|@ohos.nfc.cardEmulation.d.ts|
|新增|NA|类名：cardEmulation<br>方法or属性：function isDefaultService(elementName: ElementName, type: CardType): boolean;|@ohos.nfc.cardEmulation.d.ts|
|新增|NA|类名：HceService<br>方法or属性：start(elementName: ElementName, aidList: string[]): void|@ohos.nfc.cardEmulation.d.ts|
|新增|NA|类名：HceService<br>方法or属性：stop(elementName: ElementName): void|@ohos.nfc.cardEmulation.d.ts|
|新增|NA|类名：HceService<br>方法or属性：transmit(response: number[]): Promise<void>;|@ohos.nfc.cardEmulation.d.ts|
|新增|NA|类名：HceService<br>方法or属性：transmit(response: number[], callback: AsyncCallback<void>): void;|@ohos.nfc.cardEmulation.d.ts|
|新增|NA|类名：nfcController<br>方法or属性：function enableNfc(): void|@ohos.nfc.controller.d.ts|
|新增|NA|类名：nfcController<br>方法or属性：function disableNfc(): void|@ohos.nfc.controller.d.ts|
|新增|NA|类名：tag<br>方法or属性：function getNfcA(tagInfo: TagInfo): NfcATag|@ohos.nfc.tag.d.ts|
|新增|NA|类名：tag<br>方法or属性：function getNfcB(tagInfo: TagInfo): NfcBTag|@ohos.nfc.tag.d.ts|
|新增|NA|类名：tag<br>方法or属性：function getNfcF(tagInfo: TagInfo): NfcFTag|@ohos.nfc.tag.d.ts|
|新增|NA|类名：tag<br>方法or属性：function getNfcV(tagInfo: TagInfo): NfcVTag|@ohos.nfc.tag.d.ts|
|新增|NA|类名：wifiManager<br>方法or属性：function p2pCancelConnect(): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：TagSession<br>方法or属性：connect(): void;|tagSession.d.ts|
|新增|NA|类名：TagSession<br>方法or属性：resetConnection(): void;|tagSession.d.ts|
|新增|NA|类名：TagSession<br>方法or属性：isConnected(): boolean;|tagSession.d.ts|
|新增|NA|类名：TagSession<br>方法or属性：setTimeout(timeout: number): void;|tagSession.d.ts|
|新增|NA|类名：TagSession<br>方法or属性：getTimeout(): number;|tagSession.d.ts|
|新增|NA|类名：TagSession<br>方法or属性：transmit(data: number[]): Promise<number[]>;|tagSession.d.ts|
|新增|NA|类名：TagSession<br>方法or属性：transmit(data: number[], callback: AsyncCallback<number[]>): void;|tagSession.d.ts|
|新增|NA|类名：TagSession<br>方法or属性：getMaxTransmitSize(): number;|tagSession.d.ts|
|删除|模块名：ohos.wifiManager<br>类名:wifiManager<br>方法 or 属性:function p2pDisconnect(): void;|NA|@ohos.wifiManager.d.ts|
|废弃版本有变化|类名：connectedTag<br>方法 or 属性：function init(): boolean;<br>废弃版本：N/A|类名：connectedTag<br>方法 or 属性：function init(): boolean;<br>废弃版本：9<br>代替接口：ohos.connectedTag/connectedTag|@ohos.connectedTag.d.ts|
|废弃版本有变化|类名：connectedTag<br>方法 or 属性：function uninit(): boolean;<br>废弃版本：N/A|类名：connectedTag<br>方法 or 属性：function uninit(): boolean;<br>废弃版本：9<br>代替接口：ohos.connectedTag/connectedTag|@ohos.connectedTag.d.ts|
|废弃版本有变化|类名：connectedTag<br>方法 or 属性：function readNdefTag(): Promise<string>;<br>废弃版本：N/A|类名：connectedTag<br>方法 or 属性：function readNdefTag(): Promise<string>;<br>废弃版本：9<br>代替接口：ohos.connectedTag/connectedTag|@ohos.connectedTag.d.ts|
|废弃版本有变化|类名：connectedTag<br>方法 or 属性：function readNdefTag(callback: AsyncCallback<string>): void;<br>废弃版本：N/A|类名：connectedTag<br>方法 or 属性：function readNdefTag(callback: AsyncCallback<string>): void;<br>废弃版本：9|@ohos.connectedTag.d.ts|
|废弃版本有变化|类名：connectedTag<br>方法 or 属性：function writeNdefTag(data: string): Promise<void>;<br>废弃版本：N/A|类名：connectedTag<br>方法 or 属性：function writeNdefTag(data: string): Promise<void>;<br>废弃版本：9<br>代替接口：ohos.connectedTag/connectedTag|@ohos.connectedTag.d.ts|
|废弃版本有变化|类名：connectedTag<br>方法 or 属性：function writeNdefTag(data: string, callback: AsyncCallback<void>): void;<br>废弃版本：N/A|类名：connectedTag<br>方法 or 属性：function writeNdefTag(data: string, callback: AsyncCallback<void>): void;<br>废弃版本：9|@ohos.connectedTag.d.ts|
|废弃版本有变化|类名：FeatureType<br>废弃版本：N/A|类名：FeatureType<br>废弃版本：9<br>代替接口：ohos.nfc.cardEmulation/cardEmulation|@ohos.nfc.cardEmulation.d.ts|
|废弃版本有变化|类名：cardEmulation<br>方法 or 属性：function isSupported(feature: number): boolean;<br>废弃版本：N/A|类名：cardEmulation<br>方法 or 属性：function isSupported(feature: number): boolean;<br>废弃版本：9<br>代替接口：ohos.nfc.cardEmulation/cardEmulation|@ohos.nfc.cardEmulation.d.ts|
|废弃版本有变化|类名：HceService<br>方法 or 属性：startHCE(aidList: string[]): boolean;<br>废弃版本：N/A|类名：HceService<br>方法 or 属性：startHCE(aidList: string[]): boolean;<br>废弃版本：9<br>代替接口：ohos.nfc.cardEmulation/cardEmulation.HceService|@ohos.nfc.cardEmulation.d.ts|
|废弃版本有变化|类名：HceService<br>方法 or 属性：stopHCE(): boolean;<br>废弃版本：N/A|类名：HceService<br>方法 or 属性：stopHCE(): boolean;<br>废弃版本：9<br>代替接口：ohos.nfc.cardEmulation/cardEmulation.HceService|@ohos.nfc.cardEmulation.d.ts|
|废弃版本有变化|类名：HceService<br>方法 or 属性：sendResponse(responseApdu: number[]): void;<br>废弃版本：N/A|类名：HceService<br>方法 or 属性：sendResponse(responseApdu: number[]): void;<br>废弃版本：9<br>代替接口：ohos.nfc.cardEmulation/cardEmulation.HceService|@ohos.nfc.cardEmulation.d.ts|
|废弃版本有变化|类名：nfcController<br>方法 or 属性：function isNfcAvailable(): boolean<br>废弃版本：N/A|类名：nfcController<br>方法 or 属性：function isNfcAvailable(): boolean<br>废弃版本：9<br>代替接口：global|@ohos.nfc.controller.d.ts|
|废弃版本有变化|类名：nfcController<br>方法 or 属性：function openNfc(): boolean<br>废弃版本：N/A|类名：nfcController<br>方法 or 属性：function openNfc(): boolean<br>废弃版本：9<br>代替接口：@ohos.nfc.controller.nfcController|@ohos.nfc.controller.d.ts|
|废弃版本有变化|类名：nfcController<br>方法 or 属性：function closeNfc(): boolean<br>废弃版本：N/A|类名：nfcController<br>方法 or 属性：function closeNfc(): boolean<br>废弃版本：9<br>代替接口：@ohos.nfc.controller.nfcController|@ohos.nfc.controller.d.ts|
|废弃版本有变化|类名：tag<br>方法 or 属性：function getNfcATag(tagInfo: TagInfo): NfcATag<br>废弃版本：N/A|类名：tag<br>方法 or 属性：function getNfcATag(tagInfo: TagInfo): NfcATag<br>废弃版本：9<br>代替接口：ohos.nfc.tag/tag|@ohos.nfc.tag.d.ts|
|废弃版本有变化|类名：tag<br>方法 or 属性：function getNfcBTag(tagInfo: TagInfo): NfcBTag<br>废弃版本：N/A|类名：tag<br>方法 or 属性：function getNfcBTag(tagInfo: TagInfo): NfcBTag<br>废弃版本：9<br>代替接口：ohos.nfc.tag/tag|@ohos.nfc.tag.d.ts|
|废弃版本有变化|类名：tag<br>方法 or 属性：function getNfcFTag(tagInfo: TagInfo): NfcFTag<br>废弃版本：N/A|类名：tag<br>方法 or 属性：function getNfcFTag(tagInfo: TagInfo): NfcFTag<br>废弃版本：9<br>代替接口：ohos.nfc.tag/tag|@ohos.nfc.tag.d.ts|
|废弃版本有变化|类名：tag<br>方法 or 属性：function getNfcVTag(tagInfo: TagInfo): NfcVTag<br>废弃版本：N/A|类名：tag<br>方法 or 属性：function getNfcVTag(tagInfo: TagInfo): NfcVTag<br>废弃版本：9<br>代替接口：ohos.nfc.tag/tag|@ohos.nfc.tag.d.ts|
|废弃版本有变化|类名：TagSession<br>方法 or 属性：getTagInfo(): tag.TagInfo;<br>废弃版本：N/A|类名：TagSession<br>方法 or 属性：getTagInfo(): tag.TagInfo;<br>废弃版本：9<br>代替接口：ohos.nfc.tag/tag|tagSession.d.ts|
|废弃版本有变化|类名：TagSession<br>方法 or 属性：connectTag(): boolean;<br>废弃版本：N/A|类名：TagSession<br>方法 or 属性：connectTag(): boolean;<br>废弃版本：9<br>代替接口：tagSession.TagSession|tagSession.d.ts|
|废弃版本有变化|类名：TagSession<br>方法 or 属性：reset(): void;<br>废弃版本：N/A|类名：TagSession<br>方法 or 属性：reset(): void;<br>废弃版本：9<br>代替接口：tagSession.TagSession|tagSession.d.ts|
|废弃版本有变化|类名：TagSession<br>方法 or 属性：isTagConnected(): boolean;<br>废弃版本：N/A|类名：TagSession<br>方法 or 属性：isTagConnected(): boolean;<br>废弃版本：9<br>代替接口：tagSession.TagSession|tagSession.d.ts|
|废弃版本有变化|类名：TagSession<br>方法 or 属性：setSendDataTimeout(timeout: number): boolean;<br>废弃版本：N/A|类名：TagSession<br>方法 or 属性：setSendDataTimeout(timeout: number): boolean;<br>废弃版本：9<br>代替接口：tagSession.TagSession|tagSession.d.ts|
|废弃版本有变化|类名：TagSession<br>方法 or 属性：getSendDataTimeout(): number;<br>废弃版本：N/A|类名：TagSession<br>方法 or 属性：getSendDataTimeout(): number;<br>废弃版本：9<br>代替接口：tagSession.TagSession|tagSession.d.ts|
|废弃版本有变化|类名：TagSession<br>方法 or 属性：sendData(data: number[]): Promise<number[]>;<br>废弃版本：N/A|类名：TagSession<br>方法 or 属性：sendData(data: number[]): Promise<number[]>;<br>废弃版本：9<br>代替接口：tagSession.TagSession|tagSession.d.ts|
|废弃版本有变化|类名：TagSession<br>方法 or 属性：sendData(data: number[], callback: AsyncCallback<number[]>): void;<br>废弃版本：N/A|类名：TagSession<br>方法 or 属性：sendData(data: number[], callback: AsyncCallback<number[]>): void;<br>废弃版本：9|tagSession.d.ts|
|废弃版本有变化|类名：TagSession<br>方法 or 属性：getMaxSendLength(): number;<br>废弃版本：N/A|类名：TagSession<br>方法 or 属性：getMaxSendLength(): number;<br>废弃版本：9<br>代替接口：tagSession.TagSession|tagSession.d.ts|
|起始版本有变化|类名：FeatureType<br>起始版本：N/A|类名：FeatureType<br>起始版本：6|@ohos.nfc.cardEmulation.d.ts|
|权限有变化|类名：A2dpSourceProfile<br>方法 or 属性：connect(device: string): boolean;<br>权限:permission ohos.permission.DISCOVER_BLUETOOTH|类名：A2dpSourceProfile<br>方法 or 属性：connect(device: string): boolean;<br>权限:ohos.permission.DISCOVER_BLUETOOTH|@ohos.bluetooth.d.ts|
|权限有变化|类名：A2dpSourceProfile<br>方法 or 属性：disconnect(device: string): boolean;<br>权限:permission ohos.permission.DISCOVER_BLUETOOTH|类名：A2dpSourceProfile<br>方法 or 属性：disconnect(device: string): boolean;<br>权限:ohos.permission.DISCOVER_BLUETOOTH|@ohos.bluetooth.d.ts|
|权限有变化|类名：HandsFreeAudioGatewayProfile<br>方法 or 属性：connect(device: string): boolean;<br>权限:permission ohos.permission.DISCOVER_BLUETOOTH|类名：HandsFreeAudioGatewayProfile<br>方法 or 属性：connect(device: string): boolean;<br>权限:ohos.permission.DISCOVER_BLUETOOTH|@ohos.bluetooth.d.ts|
|权限有变化|类名：HandsFreeAudioGatewayProfile<br>方法 or 属性：disconnect(device: string): boolean;<br>权限:permission ohos.permission.DISCOVER_BLUETOOTH|类名：HandsFreeAudioGatewayProfile<br>方法 or 属性：disconnect(device: string): boolean;<br>权限:ohos.permission.DISCOVER_BLUETOOTH|@ohos.bluetooth.d.ts|
|权限有变化|类名：HidHostProfile<br>方法 or 属性：connect(device: string): boolean;<br>权限:permission ohos.permission.DISCOVER_BLUETOOTH|类名：HidHostProfile<br>方法 or 属性：connect(device: string): boolean;<br>权限:ohos.permission.DISCOVER_BLUETOOTH|@ohos.bluetooth.d.ts|
|权限有变化|类名：HidHostProfile<br>方法 or 属性：disconnect(device: string): boolean;<br>权限:permission ohos.permission.DISCOVER_BLUETOOTH|类名：HidHostProfile<br>方法 or 属性：disconnect(device: string): boolean;<br>权限:ohos.permission.DISCOVER_BLUETOOTH|@ohos.bluetooth.d.ts|
|权限有变化|类名：PanProfile<br>方法 or 属性：disconnect(device: string): boolean;<br>权限:permission ohos.permission.USE_BLUETOOTH|类名：PanProfile<br>方法 or 属性：disconnect(device: string): boolean;<br>权限:ohos.permission.USE_BLUETOOTH|@ohos.bluetooth.d.ts|
|权限有变化|类名：PanProfile<br>方法 or 属性：setTethering(enable: boolean): void;<br>权限:permission ohos.permission.DISCOVER_BLUETOOTH|类名：PanProfile<br>方法 or 属性：setTethering(enable: boolean): void;<br>权限:ohos.permission.DISCOVER_BLUETOOTH|@ohos.bluetooth.d.ts|
|权限有变化|类名：connectedTag<br>方法 or 属性：function init(): boolean;<br>权限:s ohos.permission.NFC_TAG|类名：connectedTag<br>方法 or 属性：function init(): boolean;<br>权限:ohos.permission.NFC_TAG|@ohos.connectedTag.d.ts|
|权限有变化|类名：connectedTag<br>方法 or 属性：function uninit(): boolean;<br>权限:s ohos.permission.NFC_TAG|类名：connectedTag<br>方法 or 属性：function uninit(): boolean;<br>权限:ohos.permission.NFC_TAG|@ohos.connectedTag.d.ts|
|权限有变化|类名：connectedTag<br>方法 or 属性：function readNdefTag(): Promise<string>;<br>权限:s ohos.permission.NFC_TAG|类名：connectedTag<br>方法 or 属性：function readNdefTag(): Promise<string>;<br>权限:ohos.permission.NFC_TAG|@ohos.connectedTag.d.ts|
|权限有变化|类名：connectedTag<br>方法 or 属性：function readNdefTag(callback: AsyncCallback<string>): void;<br>权限:s ohos.permission.NFC_TAG|类名：connectedTag<br>方法 or 属性：function readNdefTag(callback: AsyncCallback<string>): void;<br>权限:ohos.permission.NFC_TAG|@ohos.connectedTag.d.ts|
|权限有变化|类名：connectedTag<br>方法 or 属性：function writeNdefTag(data: string): Promise<void>;<br>权限:s ohos.permission.NFC_TAG|类名：connectedTag<br>方法 or 属性：function writeNdefTag(data: string): Promise<void>;<br>权限:ohos.permission.NFC_TAG|@ohos.connectedTag.d.ts|
|权限有变化|类名：connectedTag<br>方法 or 属性：function writeNdefTag(data: string, callback: AsyncCallback<void>): void;<br>权限:s ohos.permission.NFC_TAG|类名：connectedTag<br>方法 or 属性：function writeNdefTag(data: string, callback: AsyncCallback<void>): void;<br>权限:ohos.permission.NFC_TAG|@ohos.connectedTag.d.ts|
|权限有变化|类名：connectedTag<br>方法 or 属性：function on(type: "notify", callback: Callback<number>): void;<br>权限:s ohos.permission.NFC_TAG|类名：connectedTag<br>方法 or 属性：function on(type: "notify", callback: Callback<number>): void;<br>权限:ohos.permission.NFC_TAG|@ohos.connectedTag.d.ts|
|权限有变化|类名：connectedTag<br>方法 or 属性：function off(type: "notify", callback?:Callback<number>): void;<br>权限:s ohos.permission.NFC_TAG|类名：connectedTag<br>方法 or 属性：function off(type: "notify", callback?:Callback<number>): void;<br>权限:ohos.permission.NFC_TAG|@ohos.connectedTag.d.ts|
|删除(权限)|类名：tag<br>方法 or 属性：function getNfcATag(tagInfo: TagInfo): NfcATag<br>权限:ohos.permission.NFC_TAG|类名：tag<br>方法 or 属性：function getNfcATag(tagInfo: TagInfo): NfcATag<br>权限:N/A|@ohos.nfc.tag.d.ts|
|删除(权限)|类名：tag<br>方法 or 属性：function getNfcBTag(tagInfo: TagInfo): NfcBTag<br>权限:ohos.permission.NFC_TAG|类名：tag<br>方法 or 属性：function getNfcBTag(tagInfo: TagInfo): NfcBTag<br>权限:N/A|@ohos.nfc.tag.d.ts|
|删除(权限)|类名：tag<br>方法 or 属性：function getNfcFTag(tagInfo: TagInfo): NfcFTag<br>权限:ohos.permission.NFC_TAG|类名：tag<br>方法 or 属性：function getNfcFTag(tagInfo: TagInfo): NfcFTag<br>权限:N/A|@ohos.nfc.tag.d.ts|
|删除(权限)|类名：tag<br>方法 or 属性：function getNfcVTag(tagInfo: TagInfo): NfcVTag<br>权限:ohos.permission.NFC_TAG|类名：tag<br>方法 or 属性：function getNfcVTag(tagInfo: TagInfo): NfcVTag<br>权限:N/A|@ohos.nfc.tag.d.ts|
|删除(权限)|类名：NfcATag<br>方法 or 属性：getSak(): number;<br>权限:ohos.permission.NFC_TAG|类名：NfcATag<br>方法 or 属性：getSak(): number;<br>权限:N/A|nfctech.d.ts|
|删除(权限)|类名：NfcATag<br>方法 or 属性：getAtqa(): number[];<br>权限:ohos.permission.NFC_TAG|类名：NfcATag<br>方法 or 属性：getAtqa(): number[];<br>权限:N/A|nfctech.d.ts|
|删除(权限)|类名：NfcBTag<br>方法 or 属性：getRespAppData(): number[];<br>权限:ohos.permission.NFC_TAG|类名：NfcBTag<br>方法 or 属性：getRespAppData(): number[];<br>权限:N/A|nfctech.d.ts|
|删除(权限)|类名：NfcBTag<br>方法 or 属性：getRespProtocol(): number[];<br>权限:ohos.permission.NFC_TAG|类名：NfcBTag<br>方法 or 属性：getRespProtocol(): number[];<br>权限:N/A|nfctech.d.ts|
|删除(权限)|类名：NfcFTag<br>方法 or 属性：getSystemCode(): number[];<br>权限:ohos.permission.NFC_TAG|类名：NfcFTag<br>方法 or 属性：getSystemCode(): number[];<br>权限:N/A|nfctech.d.ts|
|删除(权限)|类名：NfcFTag<br>方法 or 属性：getPmm(): number[];<br>权限:ohos.permission.NFC_TAG|类名：NfcFTag<br>方法 or 属性：getPmm(): number[];<br>权限:N/A|nfctech.d.ts|
|删除(权限)|类名：NfcVTag<br>方法 or 属性：getResponseFlags(): number;<br>权限:ohos.permission.NFC_TAG|类名：NfcVTag<br>方法 or 属性：getResponseFlags(): number;<br>权限:N/A|nfctech.d.ts|
|删除(权限)|类名：NfcVTag<br>方法 or 属性：getDsfId(): number;<br>权限:ohos.permission.NFC_TAG|类名：NfcVTag<br>方法 or 属性：getDsfId(): number;<br>权限:N/A|nfctech.d.ts|
|删除(权限)|类名：TagSession<br>方法 or 属性：isTagConnected(): boolean;<br>权限:ohos.permission.NFC_TAG|类名：TagSession<br>方法 or 属性：isTagConnected(): boolean;<br>权限:N/A|tagSession.d.ts|
|新增(权限)|类名：connection<br>方法 or 属性：function hasDefaultNet(callback: AsyncCallback<boolean>): void;<br>权限:N/A|类名：connection<br>方法 or 属性：function hasDefaultNet(callback: AsyncCallback<boolean>): void;<br>权限:ohos.permission.GET_NETWORK_INFO|@ohos.net.connection.d.ts|
|新增(权限)|类名：connection<br>方法 or 属性：function hasDefaultNet(): Promise<boolean>;<br>权限:N/A|类名：connection<br>方法 or 属性：function hasDefaultNet(): Promise<boolean>;<br>权限:ohos.permission.GET_NETWORK_INFO|@ohos.net.connection.d.ts|
|函数有变化|类名：wifiManager<br>方法 or 属性：function disconnect(): boolean;<br>|类名：wifiManager<br>方法 or 属性：function disconnect(): void;<br>|@ohos.wifiManager.d.ts|
