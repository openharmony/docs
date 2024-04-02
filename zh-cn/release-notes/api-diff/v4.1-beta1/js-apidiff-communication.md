| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|权限变更|文件名：api\@ohos.wifiManager.d.ts；<br>类名：wifiManager；<br>API声明：function getP2pLocalDevice(): Promise\<WifiP2pDevice>;<br>差异内容：ohos.permission.GET_WIFI_INFO and ohos.permission.GET_WIFI_CONFIG|文件名：api\@ohos.wifiManager.d.ts；<br>类名：wifiManager；<br>API声明：function getP2pLocalDevice(): Promise\<WifiP2pDevice>;<br>差异内容：ohos.permission.GET_WIFI_INFO|api\@ohos.wifiManager.d.ts|
|权限变更|文件名：api\@ohos.wifiManager.d.ts；<br>类名：wifiManager；<br>API声明：function getP2pLocalDevice(callback: AsyncCallback\<WifiP2pDevice>): void;<br>差异内容：ohos.permission.GET_WIFI_INFO and ohos.permission.GET_WIFI_CONFIG|文件名：api\@ohos.wifiManager.d.ts；<br>类名：wifiManager；<br>API声明：function getP2pLocalDevice(callback: AsyncCallback\<WifiP2pDevice>): void;<br>差异内容：ohos.permission.GET_WIFI_INFO|api\@ohos.wifiManager.d.ts|
|新增API|NA|文件名：api\@ohos.net.http.d.ts；<br>类名：HttpRequestOptions；<br>API声明：resumeFrom?: number;<br>差异内容：resumeFrom?: number;|api\@ohos.net.http.d.ts|
|新增API|NA|文件名：api\@ohos.net.http.d.ts；<br>类名：HttpRequestOptions；<br>API声明：resumeTo?: number;<br>差异内容：resumeTo?: number;|api\@ohos.net.http.d.ts|
|新增API|NA|文件名：api\@ohos.net.http.d.ts；<br>类名：HttpRequestOptions；<br>API声明：clientCert?: ClientCert;<br>差异内容：clientCert?: ClientCert;|api\@ohos.net.http.d.ts|
|新增API|NA|文件名：api\@ohos.net.http.d.ts；<br>类名：HttpRequestOptions；<br>API声明：dnsOverHttps?: string;<br>差异内容：dnsOverHttps?: string;|api\@ohos.net.http.d.ts|
|新增API|NA|文件名：api\@ohos.net.http.d.ts；<br>类名：HttpRequestOptions；<br>API声明：dnsServers?: Array\<string>;<br>差异内容：dnsServers?: Array\<string>;|api\@ohos.net.http.d.ts|
|新增API|NA|文件名：api\@ohos.net.http.d.ts；<br>类名：HttpRequestOptions；<br>API声明：maxLimit?: number;<br>差异内容：maxLimit?: number;|api\@ohos.net.http.d.ts|
|新增API|NA|文件名：api\@ohos.net.http.d.ts；<br>类名：HttpRequestOptions；<br>API声明：multiFormDataList?: Array\<MultiFormData>;<br>差异内容：multiFormDataList?: Array\<MultiFormData>;|api\@ohos.net.http.d.ts|
|新增API|NA|文件名：api\@ohos.net.http.d.ts；<br>类名：http；<br>API声明： export interface MultiFormData<br>差异内容： export interface MultiFormData|api\@ohos.net.http.d.ts|
|新增API|NA|文件名：api\@ohos.net.http.d.ts；<br>类名：MultiFormData；<br>API声明：name: string;<br>差异内容：name: string;|api\@ohos.net.http.d.ts|
|新增API|NA|文件名：api\@ohos.net.http.d.ts；<br>类名：MultiFormData；<br>API声明：contentType: string;<br>差异内容：contentType: string;|api\@ohos.net.http.d.ts|
|新增API|NA|文件名：api\@ohos.net.http.d.ts；<br>类名：MultiFormData；<br>API声明：remoteFileName?: string;<br>差异内容：remoteFileName?: string;|api\@ohos.net.http.d.ts|
|新增API|NA|文件名：api\@ohos.net.http.d.ts；<br>类名：MultiFormData；<br>API声明：data?: string \| Object \| ArrayBuffer;<br>差异内容：data?: string \| Object \| ArrayBuffer;|api\@ohos.net.http.d.ts|
|新增API|NA|文件名：api\@ohos.net.http.d.ts；<br>类名：MultiFormData；<br>API声明：filePath?: string;<br>差异内容：filePath?: string;|api\@ohos.net.http.d.ts|
|新增API|NA|文件名：api\@ohos.net.http.d.ts；<br>类名：http；<br>API声明： export enum CertType<br>差异内容： export enum CertType|api\@ohos.net.http.d.ts|
|新增API|NA|文件名：api\@ohos.net.http.d.ts；<br>类名：CertType；<br>API声明：PEM = 'PEM'<br>差异内容：PEM = 'PEM'|api\@ohos.net.http.d.ts|
|新增API|NA|文件名：api\@ohos.net.http.d.ts；<br>类名：CertType；<br>API声明：DER = 'DER'<br>差异内容：DER = 'DER'|api\@ohos.net.http.d.ts|
|新增API|NA|文件名：api\@ohos.net.http.d.ts；<br>类名：CertType；<br>API声明：P12 = 'P12'<br>差异内容：P12 = 'P12'|api\@ohos.net.http.d.ts|
|新增API|NA|文件名：api\@ohos.net.http.d.ts；<br>类名：http；<br>API声明： export interface ClientCert<br>差异内容： export interface ClientCert|api\@ohos.net.http.d.ts|
|新增API|NA|文件名：api\@ohos.net.http.d.ts；<br>类名：ClientCert；<br>API声明：certPath: string;<br>差异内容：certPath: string;|api\@ohos.net.http.d.ts|
|新增API|NA|文件名：api\@ohos.net.http.d.ts；<br>类名：ClientCert；<br>API声明：certType?: CertType;<br>差异内容：certType?: CertType;|api\@ohos.net.http.d.ts|
|新增API|NA|文件名：api\@ohos.net.http.d.ts；<br>类名：ClientCert；<br>API声明：keyPath: string;<br>差异内容：keyPath: string;|api\@ohos.net.http.d.ts|
|新增API|NA|文件名：api\@ohos.net.http.d.ts；<br>类名：ClientCert；<br>API声明：keyPassword?: string;<br>差异内容：keyPassword?: string;|api\@ohos.net.http.d.ts|
|新增API|NA|文件名：api\@ohos.net.http.d.ts；<br>类名：HttpRequest；<br>API声明：on(type: 'dataSendProgress', callback: Callback\<{ sendSize: number, totalSize: number }>): void<br>差异内容：on(type: 'dataSendProgress', callback: Callback\<{ sendSize: number, totalSize: number }>): void|api\@ohos.net.http.d.ts|
|新增API|NA|文件名：api\@ohos.net.http.d.ts；<br>类名：HttpRequest；<br>API声明：off(type: 'dataSendProgress', callback?: Callback\<{ sendSize: number, totalSize: number }>): void<br>差异内容：off(type: 'dataSendProgress', callback?: Callback\<{ sendSize: number, totalSize: number }>): void|api\@ohos.net.http.d.ts|
|新增API|NA|文件名：api\@ohos.net.http.d.ts；<br>类名：HttpProtocol；<br>API声明：HTTP3<br>差异内容：HTTP3|api\@ohos.net.http.d.ts|
|新增API|NA|文件名：api\@ohos.net.http.d.ts；<br>类名：HttpResponse；<br>API声明：performanceTiming: PerformanceTiming;<br>差异内容：performanceTiming: PerformanceTiming;|api\@ohos.net.http.d.ts|
|新增API|NA|文件名：api\@ohos.net.http.d.ts；<br>类名：http；<br>API声明： export interface PerformanceTiming<br>差异内容： export interface PerformanceTiming|api\@ohos.net.http.d.ts|
|新增API|NA|文件名：api\@ohos.net.http.d.ts；<br>类名：PerformanceTiming；<br>API声明：dnsTiming: number;<br>差异内容：dnsTiming: number;|api\@ohos.net.http.d.ts|
|新增API|NA|文件名：api\@ohos.net.http.d.ts；<br>类名：PerformanceTiming；<br>API声明：tcpTiming: number;<br>差异内容：tcpTiming: number;|api\@ohos.net.http.d.ts|
|新增API|NA|文件名：api\@ohos.net.http.d.ts；<br>类名：PerformanceTiming；<br>API声明：tlsTiming: number;<br>差异内容：tlsTiming: number;|api\@ohos.net.http.d.ts|
|新增API|NA|文件名：api\@ohos.net.http.d.ts；<br>类名：PerformanceTiming；<br>API声明：firstSendTiming: number;<br>差异内容：firstSendTiming: number;|api\@ohos.net.http.d.ts|
|新增API|NA|文件名：api\@ohos.net.http.d.ts；<br>类名：PerformanceTiming；<br>API声明：firstReceiveTiming: number;<br>差异内容：firstReceiveTiming: number;|api\@ohos.net.http.d.ts|
|新增API|NA|文件名：api\@ohos.net.http.d.ts；<br>类名：PerformanceTiming；<br>API声明：totalFinishTiming: number;<br>差异内容：totalFinishTiming: number;|api\@ohos.net.http.d.ts|
|新增API|NA|文件名：api\@ohos.net.http.d.ts；<br>类名：PerformanceTiming；<br>API声明：redirectTiming: number;<br>差异内容：redirectTiming: number;|api\@ohos.net.http.d.ts|
|新增API|NA|文件名：api\@ohos.net.http.d.ts；<br>类名：PerformanceTiming；<br>API声明：responseHeaderTiming: number;<br>差异内容：responseHeaderTiming: number;|api\@ohos.net.http.d.ts|
|新增API|NA|文件名：api\@ohos.net.http.d.ts；<br>类名：PerformanceTiming；<br>API声明：responseBodyTiming: number;<br>差异内容：responseBodyTiming: number;|api\@ohos.net.http.d.ts|
|新增API|NA|文件名：api\@ohos.net.http.d.ts；<br>类名：PerformanceTiming；<br>API声明：totalTiming: number;<br>差异内容：totalTiming: number;|api\@ohos.net.http.d.ts|
|新增API|NA|文件名：api\@ohos.net.networkSecurity.d.ts；<br>类名：global；<br>API声明： declare namespace networkSecurity<br>差异内容： declare namespace networkSecurity|api\@ohos.net.networkSecurity.d.ts|
|新增API|NA|文件名：api\@ohos.net.networkSecurity.d.ts；<br>类名：networkSecurity；<br>API声明： export enum CertType<br>差异内容： export enum CertType|api\@ohos.net.networkSecurity.d.ts|
|新增API|NA|文件名：api\@ohos.net.networkSecurity.d.ts；<br>类名：CertType；<br>API声明：CERT_TYPE_PEM = 0<br>差异内容：CERT_TYPE_PEM = 0|api\@ohos.net.networkSecurity.d.ts|
|新增API|NA|文件名：api\@ohos.net.networkSecurity.d.ts；<br>类名：CertType；<br>API声明：CERT_TYPE_DER = 1<br>差异内容：CERT_TYPE_DER = 1|api\@ohos.net.networkSecurity.d.ts|
|新增API|NA|文件名：api\@ohos.net.networkSecurity.d.ts；<br>类名：networkSecurity；<br>API声明： export interface CertBlob<br>差异内容： export interface CertBlob|api\@ohos.net.networkSecurity.d.ts|
|新增API|NA|文件名：api\@ohos.net.networkSecurity.d.ts；<br>类名：CertBlob；<br>API声明：type: CertType;<br>差异内容：type: CertType;|api\@ohos.net.networkSecurity.d.ts|
|新增API|NA|文件名：api\@ohos.net.networkSecurity.d.ts；<br>类名：CertBlob；<br>API声明：data: string \| ArrayBuffer;<br>差异内容：data: string \| ArrayBuffer;|api\@ohos.net.networkSecurity.d.ts|
|新增API|NA|文件名：api\@ohos.net.networkSecurity.d.ts；<br>类名：networkSecurity；<br>API声明：export function certVerification(cert: CertBlob, caCert?: CertBlob): Promise\<number>;<br>差异内容：export function certVerification(cert: CertBlob, caCert?: CertBlob): Promise\<number>;|api\@ohos.net.networkSecurity.d.ts|
|新增API|NA|文件名：api\@ohos.net.networkSecurity.d.ts；<br>类名：networkSecurity；<br>API声明：export function certVerificationSync(cert: CertBlob, caCert?: CertBlob): number;<br>差异内容：export function certVerificationSync(cert: CertBlob, caCert?: CertBlob): number;|api\@ohos.net.networkSecurity.d.ts|
|新增API|NA|文件名：api\@ohos.net.socket.d.ts；<br>类名：socket；<br>API声明：function constructMulticastSocketInstance(): MulticastSocket;<br>差异内容：function constructMulticastSocketInstance(): MulticastSocket;|api\@ohos.net.socket.d.ts|
|新增API|NA|文件名：api\@ohos.net.socket.d.ts；<br>类名：socket；<br>API声明： export interface MulticastSocket<br>差异内容： export interface MulticastSocket|api\@ohos.net.socket.d.ts|
|新增API|NA|文件名：api\@ohos.net.socket.d.ts；<br>类名：MulticastSocket；<br>API声明：addMembership(multicastAddress: NetAddress, callback: AsyncCallback\<void>): void;<br>差异内容：addMembership(multicastAddress: NetAddress, callback: AsyncCallback\<void>): void;|api\@ohos.net.socket.d.ts|
|新增API|NA|文件名：api\@ohos.net.socket.d.ts；<br>类名：MulticastSocket；<br>API声明：addMembership(multicastAddress: NetAddress): Promise\<void>;<br>差异内容：addMembership(multicastAddress: NetAddress): Promise\<void>;|api\@ohos.net.socket.d.ts|
|新增API|NA|文件名：api\@ohos.net.socket.d.ts；<br>类名：MulticastSocket；<br>API声明：dropMembership(multicastAddress: NetAddress, callback: AsyncCallback\<void>): void;<br>差异内容：dropMembership(multicastAddress: NetAddress, callback: AsyncCallback\<void>): void;|api\@ohos.net.socket.d.ts|
|新增API|NA|文件名：api\@ohos.net.socket.d.ts；<br>类名：MulticastSocket；<br>API声明：dropMembership(multicastAddress: NetAddress): Promise\<void>;<br>差异内容：dropMembership(multicastAddress: NetAddress): Promise\<void>;|api\@ohos.net.socket.d.ts|
|新增API|NA|文件名：api\@ohos.net.socket.d.ts；<br>类名：MulticastSocket；<br>API声明：setMulticastTTL(ttl: number, callback: AsyncCallback\<void>): void;<br>差异内容：setMulticastTTL(ttl: number, callback: AsyncCallback\<void>): void;|api\@ohos.net.socket.d.ts|
|新增API|NA|文件名：api\@ohos.net.socket.d.ts；<br>类名：MulticastSocket；<br>API声明：setMulticastTTL(ttl: number): Promise\<void>;<br>差异内容：setMulticastTTL(ttl: number): Promise\<void>;|api\@ohos.net.socket.d.ts|
|新增API|NA|文件名：api\@ohos.net.socket.d.ts；<br>类名：MulticastSocket；<br>API声明：getMulticastTTL(callback: AsyncCallback\<number>): void;<br>差异内容：getMulticastTTL(callback: AsyncCallback\<number>): void;|api\@ohos.net.socket.d.ts|
|新增API|NA|文件名：api\@ohos.net.socket.d.ts；<br>类名：MulticastSocket；<br>API声明：getMulticastTTL(): Promise\<number>;<br>差异内容：getMulticastTTL(): Promise\<number>;|api\@ohos.net.socket.d.ts|
|新增API|NA|文件名：api\@ohos.net.socket.d.ts；<br>类名：MulticastSocket；<br>API声明：setLoopbackMode(flag: boolean, callback: AsyncCallback\<void>): void;<br>差异内容：setLoopbackMode(flag: boolean, callback: AsyncCallback\<void>): void;|api\@ohos.net.socket.d.ts|
|新增API|NA|文件名：api\@ohos.net.socket.d.ts；<br>类名：MulticastSocket；<br>API声明：setLoopbackMode(flag: boolean): Promise\<void>;<br>差异内容：setLoopbackMode(flag: boolean): Promise\<void>;|api\@ohos.net.socket.d.ts|
|新增API|NA|文件名：api\@ohos.net.socket.d.ts；<br>类名：MulticastSocket；<br>API声明：getLoopbackMode(callback: AsyncCallback\<boolean>): void;<br>差异内容：getLoopbackMode(callback: AsyncCallback\<boolean>): void;|api\@ohos.net.socket.d.ts|
|新增API|NA|文件名：api\@ohos.net.socket.d.ts；<br>类名：MulticastSocket；<br>API声明：getLoopbackMode(): Promise\<boolean>;<br>差异内容：getLoopbackMode(): Promise\<boolean>;|api\@ohos.net.socket.d.ts|
|新增API|NA|文件名：api\@ohos.net.webSocket.d.ts；<br>类名：WebSocket；<br>API声明：on(type: 'dataEnd', callback: Callback\<void>): void;<br>差异内容：on(type: 'dataEnd', callback: Callback\<void>): void;|api\@ohos.net.webSocket.d.ts|
|新增API|NA|文件名：api\@ohos.net.webSocket.d.ts；<br>类名：WebSocket；<br>API声明：off(type: 'dataEnd', callback?: Callback\<void>): void;<br>差异内容：off(type: 'dataEnd', callback?: Callback\<void>): void;|api\@ohos.net.webSocket.d.ts|
|新增API|NA|文件名：api\@ohos.nfc.cardEmulation.d.ts；<br>类名：cardEmulation；<br>API声明：function getPaymentServices(): AbilityInfo[];<br>差异内容：function getPaymentServices(): AbilityInfo[];|api\@ohos.nfc.cardEmulation.d.ts|
|新增API|NA|文件名：api\@ohos.nfc.tag.d.ts；<br>类名：tag；<br>API声明：function on(type: 'readerMode', elementName: ElementName, discTech: number[], callback: AsyncCallback\<TagInfo>): void;<br>差异内容：function on(type: 'readerMode', elementName: ElementName, discTech: number[], callback: AsyncCallback\<TagInfo>): void;|api\@ohos.nfc.tag.d.ts|
|新增API|NA|文件名：api\@ohos.nfc.tag.d.ts；<br>类名：tag；<br>API声明：function off(type: 'readerMode', elementName: ElementName, callback?: AsyncCallback\<TagInfo>): void;<br>差异内容：function off(type: 'readerMode', elementName: ElementName, callback?: AsyncCallback\<TagInfo>): void;|api\@ohos.nfc.tag.d.ts|
|新增API|NA|文件名：api\@ohos.wifiManager.d.ts；<br>类名：wifiManager；<br>API声明：function startPortalCertification(): void;<br>差异内容：function startPortalCertification(): void;|api\@ohos.wifiManager.d.ts|
|新增API|NA|文件名：api\@ohos.wifiManager.d.ts；<br>类名：wifiManager；<br>API声明：function isMeteredHotspot(): boolean;<br>差异内容：function isMeteredHotspot(): boolean;|api\@ohos.wifiManager.d.ts|
|新增API|NA|文件名：api\@ohos.wifiManager.d.ts；<br>类名：wifiManager；<br>API声明：function factoryReset(): void;<br>差异内容：function factoryReset(): void;|api\@ohos.wifiManager.d.ts|
|新增API|NA|文件名：api\@ohos.wifiManager.d.ts；<br>类名：wifiManager；<br>API声明：function addHotspotBlockList(stationInfo: StationInfo);<br>差异内容：function addHotspotBlockList(stationInfo: StationInfo);|api\@ohos.wifiManager.d.ts|
|新增API|NA|文件名：api\@ohos.wifiManager.d.ts；<br>类名：wifiManager；<br>API声明：function delHotspotBlockList(stationInfo: StationInfo);<br>差异内容：function delHotspotBlockList(stationInfo: StationInfo);|api\@ohos.wifiManager.d.ts|
|新增API|NA|文件名：api\@ohos.wifiManager.d.ts；<br>类名：wifiManager；<br>API声明：function getHotspotBlockList(): Array\<StationInfo>;<br>差异内容：function getHotspotBlockList(): Array\<StationInfo>;|api\@ohos.wifiManager.d.ts|
|起始版本有变化|文件名：api\@system.fetch.d.ts；<br>类名：global；<br>API声明： export interface FetchResponse<br>差异内容：3|文件名：api\@system.fetch.d.ts；<br>类名：global；<br>API声明： export interface FetchResponse<br>差异内容：-1|api\@system.fetch.d.ts|
