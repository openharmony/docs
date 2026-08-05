# 使用MDNS访问局域网服务
<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->

## 简介

MDNS即多播DNS（Multicast DNS），提供局域网内的本地服务添加、移除、发现、解析等能力。
- 本地服务：局域网内服务的提供方，比如打印机、扫描仪等。

MDNS管理的典型场景有：

- 管理本地服务，通过对本地服务的创建，删除和解析等管理本地服务。
- 发现本地服务，通过[DiscoveryService](../reference/apis-network-kit/js-apis-net-mdns.md#discoveryservice)对象，对指定类型的本地服务状态变化进行监听。

> **说明：**
> 为了保证应用的运行效率，大部分API调用都是异步的，对于异步调用的API均提供了callback和Promise两种方式，以下示例均采用Promise函数，更多方式可以查阅[@ohos.net.mdns (MDNS管理)](../reference/apis-network-kit/js-apis-net-mdns.md)。

以下分别介绍具体开发方式。

>**说明：** 
>
>在本文档的示例中，通过this.context来获取UIAbilityContext，其中this代表继承自UIAbility的UIAbility实例。如需在页面中使用UIAbilityContext提供的能力，请参见[获取UIAbility的上下文信息](../application-models/uiability-usage.md#获取uiability的上下文信息)。

## 管理本地服务

1. 设备连接Wi-Fi。
2. 从@kit.NetworkKit里导入mdns、错误码、以及[common](../reference/apis-ability-kit/js-apis-app-ability-common.md)命名空间。

   <!-- @[MDNS_case_module_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/MDNS_case/entry/src/main/ets/pages/Index.ets) -->
   
   ``` TypeScript
   // 从@kit.NetworkKit中导入mdns命名空间。
   import { mdns } from '@kit.NetworkKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { common } from '@kit.AbilityKit';
   import { hilog } from '@kit.PerformanceAnalysisKit';
   ```
3. 调用[addLocalService](../reference/apis-network-kit/js-apis-net-mdns.md#mdnsaddlocalservice-1)方法，添加本地服务。

   <!-- @[MDNS_add_local_service](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/MDNS_case/entry/src/main/ets/pages/Index.ets) -->
   
   ``` TypeScript
   // 建立LocalService对象。
   private localServiceInfo: mdns.LocalServiceInfo = {
     serviceType: '_print._tcp',
     serviceName: 'servicename',
     port: 5555,
     host: {
       address: '127.0.0.1'
     },
     serviceAttribute: [{ key: '111', value: [1] }]
   };
   // ...
     let context: common.UIAbilityContext = this.getUIContext().getHostContext() as common.UIAbilityContext;
     // addLocalService添加本地服务。
     mdns.addLocalService(context, this.localServiceInfo).then((data) => {
       // ...
       hilog.info(0x0000, 'testTag', `Local Service Added: ${JSON.stringify(data)}`);
     })
     // ...
   ```

4. 通过[resolveLocalService](../reference/apis-network-kit/js-apis-net-mdns.md#mdnsresolvelocalservice-1)方法，解析本地网络的IP地址（非必要，根据需求使用）。
   
   <!-- @[MDNS_resolve_local_service](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/MDNS_case/entry/src/main/ets/pages/Index.ets) -->
   
   ``` TypeScript
   // resolveLocalService解析本地服务对象（非必要，根据需求使用）。
   mdns.resolveLocalService(context, this.localServiceInfo).then((data: mdns.LocalServiceInfo) => {
     // ...
     hilog.info(0x0000, 'testTag', `Resolved Local Service: ${JSON.stringify(data)}`);
   })
   ```

5. 通过[removeLocalService](../reference/apis-network-kit/js-apis-net-mdns.md#mdnsremovelocalservice-1)方法，移除本地服务。

   <!-- @[MDNS_remove_local_service](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/MDNS_case/entry/src/main/ets/pages/Index.ets) -->
   
   ``` TypeScript
   // removeLocalService移除本地服务。
   mdns.removeLocalService(context, this.localServiceInfo).then((data: mdns.LocalServiceInfo) => {
     // ...
     hilog.info(0x0000, 'testTag', `Local Service Removed: ${JSON.stringify(data)}`);
   })
   ```

## 发现本地服务

1. 设备连接WiFi。
2. 从@kit.NetworkKit里导入mdns的命名空间。

   <!-- @[MDNS_case_module_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/MDNS_case/entry/src/main/ets/pages/Index.ets) -->
   
   ``` TypeScript
   // 从@kit.NetworkKit中导入mdns命名空间。
   import { mdns } from '@kit.NetworkKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { common } from '@kit.AbilityKit';
   import { hilog } from '@kit.PerformanceAnalysisKit';
   ```
3. 创建[DiscoveryService](../reference/apis-network-kit/js-apis-net-mdns.md#mdnscreatediscoveryservice)对象，用于发现指定服务类型的MDNS服务。

   <!-- @[create_discovery_service_object](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/MDNS_case/entry/src/main/ets/pages/Index.ets) -->
   
   ``` TypeScript
   let context: common.UIAbilityContext = this.getUIContext().getHostContext() as common.UIAbilityContext;
       
   // ...
   // 创建DiscoveryService对象，用于发现指定服务类型的MDNS服务。
   let serviceType = '_print._tcp';
   let discoveryService = mdns.createDiscoveryService(context, serviceType);
   ```
  
4. 订阅MDNS服务发现相关状态变化。

    <!-- @[discovery_service_on_method](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/MDNS_case/entry/src/main/ets/pages/Index.ets) -->
    
    ``` TypeScript
    // 订阅MDNS服务发现相关状态变化。
    discoveryService.on('discoveryStart', (data: mdns.DiscoveryEventInfo) => {
      hilog.info(0x0000, 'testTag', JSON.stringify(data));
    });
    discoveryService.on('discoveryStop', (data: mdns.DiscoveryEventInfo) => {
      hilog.info(0x0000, 'testTag', JSON.stringify(data));
    });
    discoveryService.on('serviceFound', (data: mdns.LocalServiceInfo) => {
      hilog.info(0x0000, 'testTag', JSON.stringify(data));
      // ...
    });
    discoveryService.on('serviceLost', (data: mdns.LocalServiceInfo) => {
      hilog.info(0x0000, 'testTag', JSON.stringify(data));
      // ...
    });
    ```

5. 启动搜索局域网内的MDNS服务。

   <!-- @[start_searching_MDNS_method](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/MDNS_case/entry/src/main/ets/pages/Index.ets) -->
   
   ``` TypeScript
   // 启动搜索局域网内的MDNS服务。
   discoveryService.startSearchingMDNS();
   ```
6. 停止搜索局域网内的MDNS服务。

   <!-- @[stop_searching_MDNS_method](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/MDNS_case/entry/src/main/ets/pages/Index.ets) -->
   
   ``` TypeScript
   // 停止搜索局域网内的MDNS服务。
   discoveryService.stopSearchingMDNS();
   ```
7. 取消订阅的MDNS服务。

   <!-- @[discovery_service_off_method](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/MDNS_case/entry/src/main/ets/pages/Index.ets) -->
   
   ``` TypeScript
   // 取消订阅的MDNS服务。
   discoveryService.off('discoveryStart', (data: mdns.DiscoveryEventInfo) => {
     hilog.info(0x0000, 'testTag', JSON.stringify(data));
   });
   discoveryService.off('discoveryStop', (data: mdns.DiscoveryEventInfo) => {
     hilog.info(0x0000, 'testTag', JSON.stringify(data));
   });
   discoveryService.off('serviceFound', (data: mdns.LocalServiceInfo) => {
     hilog.info(0x0000, 'testTag', JSON.stringify(data));
     // ...
   });
   discoveryService.off('serviceLost', (data: mdns.LocalServiceInfo) => {
     hilog.info(0x0000, 'testTag', JSON.stringify(data));
     // ...
   });
   ```
## 相关实例

针对MDNS管理，有以下相关实例可供参考：

* [MDNS管理](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/MDNS_case)
