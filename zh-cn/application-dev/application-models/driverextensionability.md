# DriverExtensionAbility

[DriverExtensionAbility](../reference/apis/js-apis-app-ability-driverExtensionAbility.md)是DRIVER类型的ExtensionAbility组件，提供驱动相关扩展框架。对于部分设备，支持插入外接的硬件模块来扩展设备能力， 此时可以以应用方式安装该硬件模块的驱动程序。通过DriverExtensionAbility可实现此类应用的开发。


[DriverExtensionAbility](../reference/apis/js-apis-app-ability-driverExtensionAbility.md)可以通过DriverExtensionManager被应用绑定，并根据应用的请求信息在后台处理相关事务。
每个类型的ExtensionAbility都有自己的Context，DriverExtensionAbility通过[DriverExtensionContext](../reference/apis/js-apis-inner-application-driverExtensionContext.md)提供相关能力。
         
本章节将从如下场景来介绍DriverExtensionAbility的基本使用。

- [DriverExtensionAbility](#driverextensionability)
  - [开发步骤](#开发步骤)

## 开发步骤

开发者在实现一个驱动时，需要在DevEco Studio工程中手动新建一个DriverExtensionAbility，具体步骤如下。

1. 在工程Module对应的ets目录下，右键选择“New &gt; Directory”，新建一个目录并命名为driverextability。

2. 在driverextability目录，右键选择“New &gt; ArkTS File”，新建一个文件并命名为DriverExtAbility.ets。

3. 打开DriverExtAbility.ets文件，导入[RPC通信模块](../reference/apis/js-apis-rpc.md)，重载onRemoteMessageRequest()方法，接收应用传递过来的消息，并将处理的结果返回给应用。REQUEST_VALUE用于校验应用发送的服务请求码。
   
   ```ts
   import rpc from '@ohos.rpc';
   
   const REQUEST_CODE = 99;
   
   class StubTest extends rpc.RemoteObject {
     constructor(des: string) {
       super(des);
     }
     
     // 接收应用传递过来的消息处理，以及将处理的结果返回给应用
     onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence,
                            option: rpc.MessageOption) {
       if (code === REQUEST_CODE) {
         // 接收应用传递过来的数据
         // 应用使用多次调用data.writeInt()写入多个数据时，驱动可以通过多次调用data.readInt()方法接收对应的数据
         let optFir: number = data.readInt();
         let optSec: number = data.readInt();
         // 驱动将数据的处理结果返回给应用
         // 示例中为接收了两个数据，并将两个数据的求和返回给应用
         reply.writeInt(optFir + optSec);
       }
       return true;
     }
   }
   ```


4. 在DriverExtAbility.ets文件中，增加导入[DriverExtensionAbility](../reference/apis/js-apis-app-ability-driverExtensionAbility.md)的依赖包，该包提供了onInit()、onRelease()、onConnect()和onDisconnect()生命周期回调，自定义类继承[DriverExtensionAbility](../reference/apis/js-apis-app-ability-driverExtensionAbility.md)并根据需要重写需要的生命周期回调。
   
   ```ts
   import DriverExtensionAbility from '@ohos.app.ability.DriverExtensionAbility';
   import Want from '@ohos.app.ability.Want';
   import rpc from '@ohos.rpc';
   
   const TAG: string = '[Example].[Entry].[DriverExtAbility]';
   const REQUEST_CODE = 99;
   
   class StubTest extends rpc.RemoteObject {
     // ...
   }
   
   export default class DriverExtAbility extends DriverExtensionAbility {
     onInit(want: Want) {
       console.info(TAG, `onInit, want: ${want.abilityName}`);
     }
   
     onRelease() {
       console.info(TAG, `onRelease`);
     }
   
     onConnect(want: Want) {
       console.info(TAG, `onConnect, want: ${want.abilityName}`);
       return new StubTest("test");
     }
   
     onDisconnect(want: Want) {
       console.info(TAG, `onDisconnect, want: ${want.abilityName}`);
     }
   
     onDump(params: Array<string>) {
       console.info(TAG, `onDump, params:` + JSON.stringify(params));
       return ['params'];
     }
   }
   ```

5. 在工程Module对应的[module.json5配置文件](../quick-start/module-configuration-file.md)中注册DriverExtensionAbility，type标签需要设置为“driver”，srcEntry标签表示当前ExtensionAbility组件所对应的代码路径。
   
   ```json
   {
     "module": {
       // ...
       "extensionAbilities": [
         {
           "name": "DriverExtAbility",
           "icon": "$media:icon",
           "description": "driver",
           "type": "driver",
           "exported": true,
           "srcEntry": "./ets/driverextability/DriverExtAbility.ets",
           "metadata": [
            {
              "name": "bus", // 必填项，所属总线
              "value": "USB",
            },
            {
              "name": "desc", // 必填项，必要的驱动描述
              "value": "the sample of driverExtensionAbility",
            },
            {
              "name": "vendor", // 必填项，驱动厂商名称
              "value": "string",
            },
            {
              "name": "vid", // 支持 USB vendor id 列表，用逗号分隔，不可为空
              "value": "string, string",
            },
            {
              "name": "pid", // 支持的 USB product id 列表，用逗号分隔，不可为空
              "value": "string, string",
            }
           ]
         }
       ]
     }
   }
   ```