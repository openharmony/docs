# MDNS管理

## 简介

MDNS即多播DNS（Multicast DNS），提供局域网内的本地服务添加、移除、发现、解析等能力。
- 本地服务：局域网内服务的提供方，比如打印机、扫描器等。

MDNS管理的典型场景有：

- 管理本地服务，通过对本地服务的创建，删除和解析等，管理本地服务。
- 发现本地服务，通过DiscoveryService对象，对指定类型的本地服务状态变化进行监听。

> **说明：**
> 为了保证应用的运行效率，大部分API调用都是异步的，对于异步调用的API均提供了callback和Promise两种方式，以下示例均采用callback函数，更多方式可以查阅[API参考](../reference/apis/js-apis-net-mdns.md)。

以下分别介绍具体开发方式。

## 接口说明

完整的JS API说明以及实例代码请参考：[mDNS链接](../reference/apis/js-apis-net-mdns.md)。

| 类型 | 接口 | 功能说明 |
| ---- | ---- | ---- |
| ohos.net.mdns | addLocalService(context: Context, serviceInfo: LocalServiceInfo, callback: AsyncCallback\<LocalServiceInfo>): void | 添加一个mDNS服务，使用callback方式作为异步方法。 |
| ohos.net.mdns | removeLocalService(context: Context, serviceInfo: LocalServiceInfo, callback: AsyncCallback\<LocalServiceInfo>): void | 移除一个mDNS服务，使用callback方式作为异步方法。 |
| ohos.net.mdns | createDiscoveryService(context: Context, serviceType: string): DiscoveryService | 返回一个DiscoveryService对象，该对象用于发现指定服务类型的mDNS服务。 |
| ohos.net.mdns | resolveLocalService(context: Context, serviceInfo: LocalServiceInfo, callback: AsyncCallback\<LocalServiceInfo>): void | 解析一个mDNS服务，使用callback方式作为异步方法。 |
| ohos.net.mdns.DiscoveryService | startSearchingMDNS(): void | 开始搜索局域网内的mDNS服务。 |
| ohos.net.mdns.DiscoveryService | stopSearchingMDNS(): void | 停止搜索局域网内的mDNS服务。 |
| ohos.net.mdns.DiscoveryService | on(type: 'discoveryStart', callback: Callback<{serviceInfo: LocalServiceInfo, errorCode?: MdnsError}>): void | 订阅开启监听mDNS服务的通知。 |
| ohos.net.mdns.DiscoveryService | on(type: 'discoveryStop', callback: Callback<{serviceInfo: LocalServiceInfo, errorCode?: MdnsError}>): void | 订阅停止监听mDNS服务的通知。 |
| ohos.net.mdns.DiscoveryService | on(type: 'serviceFound', callback: Callback\<LocalServiceInfo>): void | 订阅发现mDNS服务的通知。 |
| ohos.net.mdns.DiscoveryService | on(type: 'serviceLost', callback: Callback\<LocalServiceInfo>): void | 订阅移除mDNS服务的通知。 |

## 管理本地服务

1. 设备连接WiFi。
2. 从@ohos.net.mdns里导入mdns的命名空间。
3. 调用addLocalService方法，添加本地服务。
4. 通过resolveLocalService方法，解析本地网络的IP地址（非必要，根据需求使用）。
5. 通过removeLocalService方法，移除本地服务。

```js
// 从@ohos.net.mdns中导入mdns命名空间
import mdns from '@ohos.net.mdns'

// FA模型获取context
import featureAbility from '@ohos.ability.featureAbility';
let context = featureAbility.getContext();

// Stage模型获取context
import UIAbility from '@ohos.app.ability.UIAbility';
class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage){
    globalThis.context = this.context;
  }
}
let context = globalThis.context;

// 建立LocalService对象
let localServiceInfo = {
  serviceType: "_print._tcp",
  serviceName: "servicename",
  port: 5555,
  host: {
    address: "10.14.**.***",
  },
  serviceAttribute: [{
    key: "111",
    value: [1]
  }]
}

// addLocalService添加本地服务
mdns.addLocalService(context, localServiceInfo, function (error, data) {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(data));
});

// resolveLocalService解析本地服务对象（非必要，根据需求使用）
mdns.resolveLocalService(context, localServiceInfo, function (error, data) {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(data));
});

// removeLocalService移除本地服务
mdns.removeLocalService(context, localServiceInfo, function (error, data) {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(data));
});
```

## 发现本地服务

1. 设备连接WiFi。
2. 从@ohos.net.mdns里导入mdns的命名空间。
3. 创建DiscoveryService对象，用于发现指定服务类型的mDNS服务。
4. 订阅mDNS服务发现相关状态变化。
5. 启动搜索局域网内的mDNS服务。
6. 停止搜索局域网内的mDNS服务。

```js
// 从@ohos.net.mdns中导入mdns命名空间
import mdns from '@ohos.net.mdns'

// FA模型获取context
import featureAbility from '@ohos.ability.featureAbility';
let context = featureAbility.getContext();

// Stage模型获取context
import UIAbility from '@ohos.app.ability.UIAbility';
class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage){
    globalThis.context = this.context;
  }
}
let context = globalThis.context;

// 创建DiscoveryService对象，用于发现指定服务类型的mDNS服务
let serviceType = "_print._tcp";
let discoveryService = mdns.createDiscoveryService(context, serviceType);

// 订阅mDNS服务发现相关状态变化
discoveryService.on('discoveryStart', (data) => {
  console.log(JSON.stringify(data));
});
discoveryService.on('discoveryStop', (data) => {
  console.log(JSON.stringify(data));
});
discoveryService.on('serviceFound', (data) => {
  console.log(JSON.stringify(data));
});
discoveryService.on('serviceLost', (data) => {
  console.log(JSON.stringify(data));
});

// 启动搜索局域网内的mDNS服务
discoveryService.startSearchingMDNS();

// 停止搜索局域网内的mDNS服务
discoveryService.stopSearchingMDNS();
```