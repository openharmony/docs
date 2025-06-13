# MDNS管理

## 简介

MDNS即多播DNS（Multicast DNS），提供局域网内的本地服务添加、移除、发现、解析等能力。
- 本地服务：局域网内服务的提供方，比如打印机、扫描器等。

MDNS管理的典型场景有：

- 管理本地服务，通过对本地服务的创建，删除和解析等管理本地服务。
- 发现本地服务，通过DiscoveryService对象，对指定类型的本地服务状态变化进行监听。

> **说明：**
> 为了保证应用的运行效率，大部分API调用都是异步的，对于异步调用的API均提供了callback和Promise两种方式，以下示例均采用promise函数，更多方式可以查阅[MDNS管理-API参考](../reference/apis-network-kit/js-apis-net-mdns.md)。

以下分别介绍具体开发方式。

## 接口说明

完整的JS API说明以及实例代码请参考：[MDNS管理-API参考](../reference/apis-network-kit/js-apis-net-mdns.md)。

| 接口名                  | 描述 |
| ----------------------- | ---- |
| addLocalService(context: Context, serviceInfo: LocalServiceInfo, callback: AsyncCallback\<LocalServiceInfo>): void | 添加一个MDNS服务，使用callback方式作为异步方法。 |
| removeLocalService(context: Context, serviceInfo: LocalServiceInfo, callback: AsyncCallback\<LocalServiceInfo>): void | 移除一个MDNS服务，使用callback方式作为异步方法。 |
| createDiscoveryService(context: Context, serviceType: string): DiscoveryService | 返回一个DiscoveryService对象，该对象用于发现指定服务类型的MDNS服务。 |
| resolveLocalService(context: Context, serviceInfo: LocalServiceInfo, callback: AsyncCallback\<LocalServiceInfo>): void | 解析一个MDNS服务，使用callback方式作为异步方法。|
| startSearchingMDNS(): void | 开始搜索局域网内的MDNS服务。 |
| stopSearchingMDNS(): void | 停止搜索局域网内的MDNS服务。 |
| on(type: 'discoveryStart', callback: Callback<{serviceInfo: LocalServiceInfo, errorCode?: MdnsError}>): void | 订阅开启监听MDNS服务的通知。 |
| off(type: 'discoveryStart', callback?: Callback<{ serviceInfo: LocalServiceInfo, errorCode?: MdnsError }>): void | 取消开启监听MDNS服务的通知。 |
| on(type: 'discoveryStop', callback: Callback<{serviceInfo: LocalServiceInfo, errorCode?: MdnsError}>): void | 订阅停止监听MDNS服务的通知。 |
| off(type: 'discoveryStop', callback?: Callback<{ serviceInfo: LocalServiceInfo, errorCode?: MdnsError }>): void | 取消停止监听MDNS服务的通知。 |
| on(type: 'serviceFound', callback: Callback\<LocalServiceInfo>): void | 订阅发现MDNS服务的通知。 |
| off(type: 'serviceFound', callback?: Callback\<LocalServiceInfo>): void | 取消发现MDNS服务的通知。 |
| on(type: 'serviceLost', callback: Callback\<LocalServiceInfo>): void | 订阅移除MDNS服务的通知。 |
| off(type: 'serviceLost', callback?: Callback\<LocalServiceInfo>): void | 取消移除MDNS服务的通知。 |

## 管理本地服务

1. 设备连接WiFi。
2. 从@kit.NetworkKit里导入mdns的命名空间。
3. 调用addLocalService方法，添加本地服务。
4. 通过resolveLocalService方法，解析本地网络的IP地址（非必要，根据需求使用）。
5. 通过removeLocalService方法，移除本地服务。

>**说明：** 
>
>在本文档的示例中，通过this.context来获取UIAbilityContext，其中this代表继承自UIAbility的UIAbility实例。如需在页面中使用UIAbilityContext提供的能力，请参见[获取UIAbility的上下文信息](../application-models/uiability-usage.md#获取uiability的上下文信息)。

<!--code_no_check-->
```ts
// 从@kit.NetworkKit中导入mdns命名空间
import { mdns } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { featureAbility, common } from '@kit.AbilityKit';

let context: common.UIAbilityContext = this.getUIContext().getHostContext() as common.UIAbilityContext;

class ServiceAttribute {
  key: string = "111"
  value: Array<number> = [1]
}

// 建立LocalService对象
let localServiceInfo: mdns.LocalServiceInfo = {
  serviceType: "_print._tcp",
  serviceName: "servicename",
  port: 5555,
  host: {
    address: "10.14.**.***"
  },
  serviceAttribute: [{key: "111", value: [1]}]
}

// addLocalService添加本地服务
mdns.addLocalService(context, localServiceInfo).then((data: mdns.LocalServiceInfo) => {
  console.log(JSON.stringify(data));
});

// resolveLocalService解析本地服务对象（非必要，根据需求使用）
mdns.resolveLocalService(context, localServiceInfo).then((data: mdns.LocalServiceInfo) => {
  console.log(JSON.stringify(data));
});

// removeLocalService移除本地服务
mdns.removeLocalService(context, localServiceInfo).then((data: mdns.LocalServiceInfo) => {
  console.log(JSON.stringify(data));
});
```

## 发现本地服务

1. 设备连接WiFi。
2. 从@kit.NetworkKit里导入mdns的命名空间。
3. 创建DiscoveryService对象，用于发现指定服务类型的MDNS服务。
4. 订阅MDNS服务发现相关状态变化。
5. 启动搜索局域网内的MDNS服务。
6. 停止搜索局域网内的MDNS服务。
7. 取消订阅的MDNS服务。

```ts
// 从@kit.NetworkKit中导入mdns命名空间
import { common, featureAbility, UIAbility } from '@kit.AbilityKit';
import { mdns } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

// 构造单例对象
export class GlobalContext {
  private constructor() {}
  private static instance: GlobalContext;
  private _objects = new Map<string, Object>();

  public static getContext(): GlobalContext {
    if (!GlobalContext.instance) {
      GlobalContext.instance = new GlobalContext();
    }
    return GlobalContext.instance;
  }

  getObject(value: string): Object | undefined {
    return this._objects.get(value);
  }

  setObject(key: string, objectClass: Object): void {
    this._objects.set(key, objectClass);
  }
}

// Stage模型获取context
class EntryAbility extends UIAbility {
  value:number = 0;
  onWindowStageCreate(windowStage: window.WindowStage): void{
    GlobalContext.getContext().setObject("value", this.value);
  }
}

let context = GlobalContext.getContext().getObject("value") as common.UIAbilityContext;

// 创建DiscoveryService对象，用于发现指定服务类型的MDNS服务
let serviceType = "_print._tcp";
let discoveryService = mdns.createDiscoveryService(context, serviceType);

// 订阅MDNS服务发现相关状态变化
discoveryService.on('discoveryStart', (data: mdns.DiscoveryEventInfo) => {
  console.log(JSON.stringify(data));
});
discoveryService.on('discoveryStop', (data: mdns.DiscoveryEventInfo) => {
  console.log(JSON.stringify(data));
});
discoveryService.on('serviceFound', (data: mdns.LocalServiceInfo) => {
  console.log(JSON.stringify(data));
});
discoveryService.on('serviceLost', (data: mdns.LocalServiceInfo) => {
  console.log(JSON.stringify(data));
});

// 启动搜索局域网内的MDNS服务
discoveryService.startSearchingMDNS();

// 停止搜索局域网内的MDNS服务
discoveryService.stopSearchingMDNS();

// 取消订阅的MDNS服务
discoveryService.off('discoveryStart', (data: mdns.DiscoveryEventInfo) => {
  console.log(JSON.stringify(data));
});
discoveryService.off('discoveryStop', (data: mdns.DiscoveryEventInfo) => {
  console.log(JSON.stringify(data));
});
discoveryService.off('serviceFound', (data: mdns.LocalServiceInfo) => {
  console.log(JSON.stringify(data));
});
discoveryService.off('serviceLost', (data: mdns.LocalServiceInfo) => {
  console.log(JSON.stringify(data));
});
```
