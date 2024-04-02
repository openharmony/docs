# 分布式设备管理子系统变更说明

## c1.device_manager.1 设备管理模块接口废弃

**访问级别**

系统接口

**废弃原因**

应应用方要求对北向开放接口，新开放的接口包含旧的系统级接口完整功能，接口更加标准并且原子化，符合社区API规范。

**废弃影响**

非兼容性变更，需要开发者进行适配。

**废弃发生版本**

从OpenHarmony SDK 4.1.2.3开始。

**废弃的接口**

| 接口声明 | 废弃说明 | 替代接口 |
| -- | -- | -- |
| function createDeviceManager(bundleName: string, callback: AsyncCallback&lt;DeviceManager&gt;): void | 使用[deviceManager.createDeviceManager](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-distributedDeviceManager.md#devicemanagercreatedevicemanager)接口创建一个设备管理实例 | function createDeviceManager(bundleName: string): DeviceManager; |
| function release(): void | 使用[deviceManager.releaseDeviceManager](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-distributedDeviceManager.md#devicemanagerreleasedevicemanager)释放DeviceManager实例 | function releaseDeviceManager(deviceManager: DeviceManager): void; |
| function getTrustedDeviceListSync(): Array&lt;DeviceInfo&gt; | 使用[getAvailableDeviceListSync](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-distributedDeviceManager.md#getavailabledevicelistsync)同步获取所有可信设备列表 | function getAvailableDeviceListSync(): Array&lt;DeviceBasicInfo&gt;; |
| function getTrustedDeviceListSync(isRefresh: boolean): Array&lt;DeviceInfo&gt;; | 废弃 | 无替代接口 |
| function getTrustedDeviceList(callback:AsyncCallback&lt;Array&lt;DeviceInfo&gt;&gt;): void | 使用[getAvailableDeviceList](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-distributedDeviceManager.md#getavailabledevicelist)获取所有可信设备列表 | function getAvailableDeviceList(callback:AsyncCallback&lt;Array&lt;DeviceBasicInfo&gt;&gt;): void; |
| function getTrustedDeviceList(): Promise&lt;Array&lt;DeviceInfo&gt;&gt; | 使用[getAvailableDeviceList](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-distributedDeviceManager.md#getavailabledevicelist-1)获取所有可信设备列表 | function getAvailableDeviceList(): Promise&lt;Array&lt;DeviceBasicInfo&gt;&gt;; |
| function getLocalDeviceInfoSync(): DeviceInfo | 使用[getLocalDeviceNetworkId](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-distributedDeviceManager.md#getlocaldevicenetworkid)获取本地设备网络标识，<br> 使用[getLocalDeviceName](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-distributedDeviceManager.md#getlocaldevicename)获取本地设备名称，<br> 使用[getLocalDeviceType](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-distributedDeviceManager.md#getlocaldevicetype)获取本地设备类型，<br> 使用[getLocalDeviceId](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-distributedDeviceManager.md#getlocaldeviceid)获取本地设备id | function getLocalDeviceNetworkId(): string; <br> function getLocalDeviceName(): string; <br> function getLocalDeviceType(): number; <br> function getLocalDeviceId(): string; |
| function getLocalDeviceInfo(callback:AsyncCallback&lt;DeviceInfo&gt;): void | 使用[getLocalDeviceNetworkId](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-distributedDeviceManager.md#getlocaldevicenetworkid)获取本地设备网络标识，<br> 使用[getLocalDeviceName](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-distributedDeviceManager.md#getlocaldevicename)获取本地设备名称，<br> 使用[getLocalDeviceType](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-distributedDeviceManager.md#getlocaldevicetype)获取本地设备类型，<br> 使用[getLocalDeviceId](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-distributedDeviceManager.md#getlocaldeviceid)获取本地设备id | function getLocalDeviceNetworkId(): string; <br> function getLocalDeviceName(): string; <br> function getLocalDeviceType(): number; <br> function getLocalDeviceId(): string; |
| function getLocalDeviceInfo(): Promise&lt;DeviceInfo&gt; | 使用[getLocalDeviceNetworkId](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-distributedDeviceManager.md#getlocaldevicenetworkid)获取本地设备网络标识，<br> 使用[getLocalDeviceName](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-distributedDeviceManager.md#getlocaldevicename)获取本地设备名称，<br> 使用[getLocalDeviceType](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-distributedDeviceManager.md#getlocaldevicetype)获取本地设备类型，<br> 使用[getLocalDeviceId](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-distributedDeviceManager.md#getlocaldeviceid)获取本地设备id | function getLocalDeviceNetworkId(): string; <br> function getLocalDeviceName(): string; <br> function getLocalDeviceType(): number; <br> function getLocalDeviceId(): string; |
| function getDeviceInfo(networkId: string, callback:AsyncCallback&lt;DeviceInfo&gt;): void | 使用[getDeviceName](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-distributedDeviceManager.md#getdevicename)通过指定设备的网络标识获取该设备名称，<br> 使用[getDeviceType](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-distributedDeviceManager.md#getdevicetype)通过指定设备的网络标识获取该设备类型 | function getDeviceName(networkId: string): string; <br> function getDeviceType(networkId: string): number; |
| function getDeviceInfo(networkId: string): Promise&lt;DeviceInfo&gt; | 使用[getDeviceName](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-distributedDeviceManager.md#getdevicename)通过指定设备的网络标识获取该设备名称，<br> 使用[getDeviceType](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-distributedDeviceManager.md#getdevicetype)通过指定设备的网络标识获取该设备类型 | function getDeviceName(networkId: string): string; <br> function getDeviceType(networkId: string): number; |
| function startDeviceDiscovery(subscribeInfo: SubscribeInfo): void | 使用[startDiscovering](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-distributedDeviceManager.md#startdiscovering)发现周边设备 | function startDiscovering(discoverParam: {[key:&nbsp;string]:&nbsp;Object} , filterOptions?: {[key:&nbsp;string]:&nbsp;Object} ): void; |
| function startDeviceDiscovery(subscribeInfo: SubscribeInfo, filterOptions?: string): void | 使用[startDiscovering](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-distributedDeviceManager.md#startdiscovering)发现周边设备 | function startDiscovering(discoverParam: {[key:&nbsp;string]:&nbsp;Object} , filterOptions?: {[key:&nbsp;string]:&nbsp;Object} ): void; |
| function stopDeviceDiscovery(subscribeId: number): void | 使用[stopDiscovering](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-distributedDeviceManager.md#stopdiscovering)停止发现周边设备 | function stopDiscovering(): void; |
| function publishDeviceDiscovery(publishInfo: PublishInfo): void | 废弃 | 无替代接口 |
| function unPublishDeviceDiscovery(publishId: number): void | 废弃 | 无替代接口 |
| function authenticateDevice(deviceInfo: DeviceInfo, authParam: AuthParam, callback: AsyncCallback&lt;{deviceId: string, pinToken ?: number}&gt;): void | 使用[bindTarget](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-distributedDeviceManager.md#bindtarget)认证设备 | function bindTarget(deviceId: string, bindParam: {[key:&nbsp;string]:&nbsp;Object} , callback: AsyncCallback&lt;{deviceId: string}>): void; |
| function unAuthenticateDevice(deviceInfo: DeviceInfo): void | 使用[unbindTarget](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-distributedDeviceManager.md#unbindtarget)解除认证设备 | function unbindTarget(deviceId: string): void; |
| function verifyAuthInfo(authInfo: AuthInfo, callback: AsyncCallback&lt;{deviceId: string, level: number}&gt;): void | 废弃 | 无替代接口 |
| function setUserOperation(operateAction: number, params: string): void | 使用[replyUiAction](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-distributedDeviceManager.md#replyuiaction)回复用户ui操作行为 | function replyUiAction(action: number, actionResult: string): void; |
| function requestCredentialRegisterInfo(requestInfo: string, callback: AsyncCallback&lt;{registerInfo: string}&gt;): void; | 废弃 | 无替代接口 |
| function importCredential(credentialInfo: string, callback: AsyncCallback&lt;{resultInfo: string}&gt;): void; | 废弃 | 无替代接口 |
| function deleteCredential(queryInfo: string, callback: AsyncCallback&lt;{resultInfo: string}&gt;): void; | 废弃 | 无替代接口 |
| function on(type: 'uiStateChange', callback: Callback&lt;{ param: string}&gt;): void; | 使用[on('replyResult')](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-distributedDeviceManager.md#onreplyresult)回复UI操作结果回调 | function on(type: 'replyResult', callback: Callback&lt;{ param: string}&gt;): void; |
| function off(type: 'uiStateChange', callback?: Callback&lt;{ param: string}&gt;): void; | 使用[off('replyResult')](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-distributedDeviceManager.md#offreplyresult)取消回复UI操作结果回调 | function off(type: 'replyResult', callback?: Callback&lt;{ param: string}&gt;): void; |
| function on(type: 'deviceStateChange',  callback: Callback&lt;{ action: DeviceStateChangeAction, device: DeviceInfo }&gt;): void | 使用[on('deviceStateChange')](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-distributedDeviceManager.md#ondevicestatechange)注册设备状态回调 | function on(type: 'deviceStateChange', callback: Callback&lt;{ action: DeviceStateChange, device: DeviceBasicInfo }&gt;): void; |
| function off(type: 'deviceStateChange', callback?: Callback&lt;{ action: DeviceStateChangeAction, device: DeviceInfo }&gt;): void | 使用[off('deviceStateChange')](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-distributedDeviceManager.md#offdevicestatechange)取消注册设备状态回调 | function off(type: 'deviceStateChange', callback?: Callback&lt;{ action: DeviceStateChange, device: DeviceBasicInfo }&gt;): void; |
| function on(type: 'deviceFound', callback: Callback&lt;{ subscribeId: number, device: DeviceInfo }&gt;): void | 使用[on('discoverSuccess')](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-distributedDeviceManager.md#ondiscoversuccess)注册发现设备成功回调监听 | function on(type: 'discoverSuccess', callback: Callback&lt;{ device: DeviceBasicInfo }&gt;): void; |
| function off(type: 'deviceFound', callback?: Callback&lt;{ subscribeId: number, device: DeviceInfo }&gt;): void | 使用[off('discoverSuccess')](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-distributedDeviceManager.md#offdiscoversuccess)取消注册设备发现成功回调 | function off(type: 'discoverSuccess', callback?: Callback&lt;{ device: DeviceBasicInfo }&gt;): void; |
| function on(type: 'discoverFail', callback: Callback&lt;{ subscribeId: number, reason: number }&gt;): void | 使用[on('discoverFailure')](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-distributedDeviceManager.md#ondiscoverfailure)注册设备发现失败回调监听 | function on(type: 'discoverFailure', callback: Callback&lt;{ reason: number }&gt;): void; |
| function off(type: 'discoverFail', callback?: Callback&lt;{ subscribeId: number, reason: number }&gt;): void | 使用[off('discoverFailure')](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-distributedDeviceManager.md#offdiscoverfailure)取消注册设备发现失败回调 | function off(type: 'discoverFailure', callback?: Callback&lt;{ reason: number }&gt;): void; |
| function on(type: 'publishSuccess', callback: Callback&lt;{ publishId: number }&gt;): void |  废弃 | 无替代接口 |
| function off(type: 'publishSuccess', callback?: Callback&lt;{ publishId: number }&gt;): void |  废弃 | 无替代接口 |
| function on(type: 'publishFail', callback: Callback&lt;{ publishId: number, reason: number }&gt;): void |  废弃 | 无替代接口 |
| function off(type: 'publishFail', callback?: Callback&lt;{ publishId: number, reason: number }&gt;): void |  废弃 | 无替代接口 |
| function on(type: 'serviceDie', callback: () =&gt; void): void | 使用[on('serviceDie')](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-distributedDeviceManager.md#onservicedie)注册设备管理服务死亡监听 | function on(type: 'serviceDie', callback?: Callback&lt;{}&gt;): void; |
| function off(type: 'serviceDie', callback?: () =&gt; void): void | 使用[off('serviceDie')](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-distributedDeviceManager.md#offservicedie)取消注册设备管理服务死亡监听 | function off(type: 'serviceDie', callback?: Callback&lt;{}&gt;): void; |
| interface DeviceInfo | 使用[DeviceBasicInfo](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-distributedDeviceManager.md#devicebasicinfo)表示分布式设备基本信息 | interface DeviceBasicInfo |
| interface SubscribeInfo | 废弃 | 无替代接口 |
| interface AuthParam | 废弃 | 无替代接口 |
| interface AuthInfo | 废弃 | 无替代接口 |
| interface PublishInfo | 废弃 | 无替代接口 |
| enum DeviceType | 废弃 | 无替代接口 |
| enum AuthForm | 废弃 | 无替代接口 |
| enum DeviceStateChangeAction | 使用[DeviceStateChange](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-distributedDeviceManager.md#devicestatechange)表示设备状态 | enum DeviceStateChange |
| enum DiscoverMode | 废弃 | 无替代接口 |
| enum ExchangeMedium | 废弃 | 无替代接口 |
| enum ExchangeFreq | 废弃 | 无替代接口 |
| enum SubscribeCap | 废弃 | 无替代接口 |

**适配指导**

建议使用新模块的接口进行开发，参见[@ohos.distributedDeviceManager](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-distributedDeviceManager.md)。
