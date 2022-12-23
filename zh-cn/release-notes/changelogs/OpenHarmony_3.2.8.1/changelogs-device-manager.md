# 设备管理changeLog

## cl.device_manager.1 API错误信息返回方式变更

设备管理接口使用业务逻辑返回值表示错误信息，不符合OpenHarmony接口错误码规范。从API9开始作以下变更：

异步接口：通过AsyncCallback或Promise的error对象返回错误信息。

同步接口：通过抛出异常的方式返回错误信息。

**变更影响**

基于此前版本开发的应用，需适配接口的错误信息返回方式，否则会影响原有业务逻辑。

**关键接口/组件变更**

在以下接口增加错误码处理：
  - createDeviceManager(bundleName: string, callback: AsyncCallback&lt;DeviceManager&gt;): void;
  - release(): void;
  - getTrustedDeviceListSync(): Array&lt;DeviceInfo&gt;
  - getTrustedDeviceList(callback:AsyncCallback&lt;Array&lt;DeviceInfo&gt;&gt;): void;
  - getTrustedDeviceList(): Promise&lt;Array&lt;DeviceInfo&gt;&gt;
  - getLocalDeviceInfoSync(): DeviceInfo;
  - getLocalDeviceInfo(callback:AsyncCallback&lt;DeviceInfo&gt;): void;
  - getLocalDeviceInfo(): Promise&lt;DeviceInfo&gt;
  - startDeviceDiscovery(subscribeInfo: SubscribeInfo): void;
  - startDeviceDiscovery(subscribeInfo: SubscribeInfo, filterOptions?: string): void;
  - stopDeviceDiscovery(subscribeId: number): void;
  - publishDeviceDiscovery(publishInfo: PublishInfo): void;
  - unPublishDeviceDiscovery(publishId: number): void;
  - authenticateDevice(deviceInfo: DeviceInfo, authParam: AuthParam, callback: AsyncCallback&lt;{deviceId: string, pinToken ?: number}&gt;): void;
  - unAuthenticateDevice(deviceInfo: DeviceInfo): void;
  - verifyAuthInfo(authInfo: AuthInfo, callback: AsyncCallback&lt;{deviceId: string, level: number}&gt;): void;
  - setUserOperation(operateAction: number, params: string): void;
  - on(type: 'uiStateChange', callback: Callback&lt;{ param: string}&gt;): void;
  - off(type: 'uiStateChange', callback?: Callback&lt;{ param: string}&gt;): void;
  - on(type: 'deviceStateChange',  callback: Callback&lt;{ action: DeviceStateChangeAction, device: DeviceInfo }&gt;): void;
  - off(type: 'deviceStateChange', callback?: Callback&lt;{ action: DeviceStateChangeAction, device: DeviceInfo }&gt;): void;
  - on(type: 'deviceFound', callback: Callback&lt;{ subscribeId: number, device: DeviceInfo }&gt;): void;
  - off(type: 'deviceFound', callback?: Callback&lt;{ subscribeId: number, device: DeviceInfo }&gt;): void;
  - on(type: 'discoverFail', callback: Callback&lt;{ subscribeId: number, reason: number }&gt;): void;
  - off(type: 'discoverFail', callback?: Callback&lt;{ subscribeId: number, reason: number }&gt;): void;
  - on(type: 'publishSuccess', callback: Callback&lt;{ publishId: number }&gt;): void;
  - off(type: 'publishSuccess', callback?: Callback&lt;{ publishId: number }&gt;): void;
  - on(type: 'publishFail', callback: Callback&lt;{ publishId: number, reason: number }&gt;): void;
  - off(type: 'publishFail', callback?: Callback&lt;{ publishId: number, reason: number }&gt;): void;
  - on(type: 'serviceDie', callback: () =&gt; void): void;
  - off(type: 'serviceDie', callback?: () =&gt; void): void;

**适配指导**

异步接口以getTrustedDeviceList为例，示例代码如下：

```ts
import account_osAccount from "@ohos.distributedHardware.deviceManager"
dmInstance.getTrustedDeviceList((err, data) => {
    console.log("getTrustedDeviceList err: " + JSON.stringify(err));
    console.log('get trusted device info: ' + JSON.stringify(data));
});

try {
  dmInstance.getTrustedDeviceList((err, data) => {
    if (err) {
      console.error("getTrustedDeviceList errCode:" + err.code + ",errMessage:" + err.message);
      return;
    }
    console.log('get trusted device info: ' + JSON.stringify(data));
  });
} catch (err) {
  console.error("getTrustedDeviceList errCode:" + err.code + ",errMessage:" + err.message);
}
```

同步接口以startDeviceDiscovery为例，示例代码如下：

```ts
// 生成发现标识，随机数确保每次调用发现接口的标识不一致
var subscribeId = Math.floor(Math.random() * 10000 + 1000);
var subscribeInfo = {
    "subscribeId": subscribeId,
    "mode": 0xAA, // 主动模式
    "medium": 0,  // 自动发现类型，同时支持多种发现类型
    "freq": 2,    // 高频率
    "isSameAccount": false,
    "isWakeRemote": false,
    "capability": 1
};
dmInstance.startDeviceDiscovery(subscribeInfo); // 当有设备发现时，通过deviceFound回调通知给应用程序

// 生成发现标识，随机数确保每次调用发现接口的标识不一致
var subscribeId = Math.floor(Math.random() * 10000 + 1000);
var subscribeInfo = {
    "subscribeId": subscribeId,
    "mode": 0xAA, // 主动模式
    "medium": 0,  // 自动发现类型，同时支持多种发现类型
    "freq": 2,    // 高频率
    "isSameAccount": false,
    "isWakeRemote": false,
    "capability": 1
};
try {
  dmInstance.startDeviceDiscovery(subscribeInfo); // 当有设备发现时，通过deviceFound回调通知给应用程序
} catch (err) {
  console.error("startDeviceDiscovery errCode:" + err.code + ",errMessage:" + err.message);
}
```
