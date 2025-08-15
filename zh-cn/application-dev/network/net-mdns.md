# 使用MDNS访问局域网服务
<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->

## 简介

MDNS即多播DNS（Multicast DNS），提供局域网内的本地服务添加、移除、发现、解析等能力。
- 本地服务：局域网内服务的提供方，比如打印机、扫描器等。

MDNS管理的典型场景有：

- 管理本地服务，通过对本地服务的创建，删除和解析等管理本地服务。
- 发现本地服务，通过DiscoveryService对象，对指定类型的本地服务状态变化进行监听。

> **说明：**
> 为了保证应用的运行效率，大部分API调用都是异步的，对于异步调用的API均提供了callback和Promise两种方式，以下示例均采用promise函数，更多方式可以查阅[MDNS管理-API参考](../reference/apis-network-kit/js-apis-net-mdns.md)。

以下分别介绍具体开发方式。

>**说明：** 
>
>在本文档的示例中，通过this.context来获取UIAbilityContext，其中this代表继承自UIAbility的UIAbility实例。如需在页面中使用UIAbilityContext提供的能力，请参见[获取UIAbility的上下文信息](../application-models/uiability-usage.md#获取uiability的上下文信息)。

## 管理本地服务

1. 设备连接WiFi。
2. 从@kit.NetworkKit里导入mdns、错误码、featureAbility以及common命名空间。

    ```ts
    // 从@kit.NetworkKit中导入mdns命名空间。
    import { mdns } from '@kit.NetworkKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    import { featureAbility, common } from '@kit.AbilityKit';
    ```

3. 调用addLocalService方法，添加本地服务。

    <!--code_no_check-->
    ```ts
    let context: common.UIAbilityContext = this.getUIContext().getHostContext() as common.UIAbilityContext;

    class ServiceAttribute {
      key: string = "111"
      value: Array<number> = [1]
    }

    // 建立LocalService对象。
    let localServiceInfo: mdns.LocalServiceInfo = {
      serviceType: "_print._tcp",
      serviceName: "servicename",
      port: 5555,
      host: {
        address: "10.14.**.**"
      },
      serviceAttribute: [{key: "111", value: [1]}]
    }

    // addLocalService添加本地服务。
    mdns.addLocalService(context, localServiceInfo).then((data: mdns.LocalServiceInfo) => {
      console.log(JSON.stringify(data));
    });
    ```

4. 通过resolveLocalService方法，解析本地网络的IP地址（非必要，根据需求使用）。
   
     ```ts
    // resolveLocalService解析本地服务对象（非必要，根据需求使用）。
    mdns.resolveLocalService(context, localServiceInfo).then((data: mdns.LocalServiceInfo) => {
      console.log(JSON.stringify(data));
    });
    ```

5. 通过removeLocalService方法，移除本地服务。
   
    ```ts
    // removeLocalService移除本地服务。
    mdns.removeLocalService(context, localServiceInfo).then((data: mdns.LocalServiceInfo) => {
      console.log(JSON.stringify(data));
    });
    ```

## 发现本地服务

1. 设备连接WiFi。
2. 从@kit.NetworkKit里导入mdns的命名空间。

    ```ts
    // 从@kit.NetworkKit中导入mdns命名空间。
    import { common, featureAbility, UIAbility } from '@kit.AbilityKit';
    import { mdns } from '@kit.NetworkKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    import { window } from '@kit.ArkUI';
    ```

3. 创建DiscoveryService对象，用于发现指定服务类型的MDNS服务。

    <!--code_no_check-->
    ```ts
    // 构造单例对象。
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

    // Stage模型获取context。
    class EntryAbility extends UIAbility {
      value:number = 0;
      onWindowStageCreate(windowStage: window.WindowStage): void{
        GlobalContext.getContext().setObject("value", this.value);
      }
    }

    let context = GlobalContext.getContext().getObject("value") as common.UIAbilityContext;

    // 创建DiscoveryService对象，用于发现指定服务类型的MDNS服务。
    let serviceType = "_print._tcp";
    let discoveryService = mdns.createDiscoveryService(context, serviceType);
    ```
  
4. 订阅MDNS服务发现相关状态变化。

    ```ts
    // 订阅MDNS服务发现相关状态变化。
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
    ```

5. 启动搜索局域网内的MDNS服务。

    ```ts
    // 启动搜索局域网内的MDNS服务。
    discoveryService.startSearchingMDNS();
    ```

6. 停止搜索局域网内的MDNS服务。

    ```ts
    // 停止搜索局域网内的MDNS服务。
    discoveryService.stopSearchingMDNS();
    ```

7. 取消订阅的MDNS服务。

    ```ts
    // 取消订阅的MDNS服务。
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

## 相关实例

针对MDNS管理，有以下相关实例可供参考：

* [MDNS管理](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/MDNS_case)
