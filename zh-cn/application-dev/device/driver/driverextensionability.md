# 外设扩展驱动开发指导

## 场景介绍

[DriverExtensionAbility](../../reference/apis-driverdevelopment-kit/js-apis-app-ability-driverExtensionAbility.md)是Driver类型的ExtensionAbility组件，提供驱动相关扩展框架能力。对于部分设备，支持插入外接的硬件模块来扩展设备能力， 此时可以以应用方式安装该硬件模块的驱动程序。通过DriverExtensionAbility可实现此类应用的开发。


[DriverExtensionAbility](../../reference/apis-driverdevelopment-kit/js-apis-app-ability-driverExtensionAbility.md)可以通过DriverExtensionManager被应用绑定，并根据应用的请求信息在后台处理相关事务。
每个类型的ExtensionAbility都有自己的Context，DriverExtensionAbility通过[DriverExtensionContext](../../reference/apis-driverdevelopment-kit/js-apis-inner-application-driverExtensionContext.md)提供相关能力。

## 环境搭建

请参考[外设扩展驱动客户端开发指导](externaldevice-guidelines.md)中的环境搭建。

其中SDK版本配置的要求如下：

| NDK接口 | SDK版本 |
|---------|--------|
| USB DDK | API10及以上 |
| HID DDK | API11及以上 |

## 开发步骤

开发者在实现一个驱动时，需要在DevEco Studio工程中手动新建一个DriverExtensionAbility，具体步骤如下：

1. 在工程Module对应的ets目录下，右键选择“New &gt; Directory”，新建一个目录并命名为driverextability。

2. 在driverextability目录，右键选择“New &gt; ArkTS File”，新建一个文件并命名为DriverExtAbility.ets。

3. 在文件中导入相关Kit，并定义请求Code。

    ```ts
    import { DriverExtensionAbility } from '@kit.DriverDevelopmentKit';
    import { Want } from '@kit.AbilityKit';
    import { rpc } from '@kit.IPCKit';

    const REQUEST_CODE = 99; // 与扩展外设客户端约定请求码
    ```

4. 打开DriverExtAbility.ets文件，导入[RPC通信模块](../../reference/apis-ipc-kit/js-apis-rpc.md)，重载onRemoteMessageRequest()方法，接收应用传递过来的消息，并将处理的结果返回给应用。REQUEST_VALUE用于校验应用发送的服务请求码。

    ```ts
    class StubTest extends rpc.RemoteObject {
      // 接收应用传递过来的消息处理，以及将处理的结果返回给客户端
      onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence,
        option: rpc.MessageOption) {
        if (code === REQUEST_CODE) {
          // 接收应用传递过来的数据
          // 应用使用多次调用data.writeString()写入多个数据时，驱动可以通过多次调用data.readString()方法接收对应的数据
          let optFir: string = data.readString();
          // 驱动将数据的处理结果返回给应用
          // 示例中为接收了"Hello"，并将"Hello World"返回给应用
          reply.writeString(optFir + ` World`);
        }
        return true;
      }
    }
    ```

5. 在DriverExtAbility.ets文件中，增加导入[DriverExtensionAbility](../../reference/apis-driverdevelopment-kit/js-apis-app-ability-driverExtensionAbility.md)的依赖包，该包提供了onInit()、onRelease()、onConnect()和onDisconnect()生命周期回调，自定义类继承[DriverExtensionAbility](../../reference/apis-driverdevelopment-kit/js-apis-app-ability-driverExtensionAbility.md)并根据需要重写需要的生命周期回调。

    ```ts
    export default class DriverExtAbility extends DriverExtensionAbility {
      onInit(want: Want) {
        console.info('testTag', `onInit, want: ${want.abilityName}`);
      }

      onRelease() {
        console.info('testTag', `onRelease`);
      }

      onConnect(want: Want) {
        console.info('testTag', `onConnect, want: ${want.abilityName}`);
        return new StubTest("test");
      }

      onDisconnect(want: Want) {
        console.info('testTag', `onDisconnect, want: ${want.abilityName}`);
      }

      onDump(params: Array<string>) {
        console.info('testTag', `onDump, params:` + JSON.stringify(params));
        return ['params'];
      }
    }
    ```

6. 在工程Module对应的[module.json5配置文件](../../quick-start/module-configuration-file.md)中注册DriverExtensionAbility，type标签需要设置为“driver”，srcEntry标签表示当前ExtensionAbility组件所对应的代码路径。

    ```json
    {
      "module": {
        "name": "entry",
        "type": "entry",
        "description": "$string:module_desc",
        "mainElement": "EntryAbility",
        "deviceTypes": [
          "default",
          "tablet"
        ],
        "requestPermissions": [
          {
            "name": "ohos.permission.ACCESS_EXTENSIONAL_DEVICE_DRIVER" // 此处为扩展外设相关权限，必须配置
          }
        ],
        "deliveryWithInstall": true,
        "installationFree": false,
        "pages": "$profile:main_pages",
        "abilities": [
          {
            "name": "EntryAbility",
            "srcEntry": "./ets/entryability/EntryAbility.ets",
            "description": "$string:EntryAbility_desc",
            "icon": "$media:startIcon",
            "label": "$string:EntryAbility_label",
            "startWindowIcon": "$media:startIcon",
            "startWindowBackground": "$color:start_window_background",
            "exported": true,
            "skills": [
              {
                "entities": [
                  "entity.system.home"
                ],
                "actions": [
                  "action.system.home"
                ]
              }
            ]
          }
        ],
        "extensionAbilities": [
          {
            "name": "DriverExtAbility",
            "icon": "$media:startIcon",
            "description": "driver",
            "type": "driver",
            "exported": true,
            "srcEntry": "./ets/driverextability/DriverExtAbility.ets",
            "metadata": [
              {
                "name": "bus", // 必填项，所属总线
                "value": "USB"
              },
              {
                "name": "desc", // 选填项，必要的驱动描述
                "value": "the sample of driverExtensionAbility"
              },
              {
                "name": "vendor", // 选填项，驱动厂商名称
                "value": "string"
              },
              {
                "name": "vid", // 支持 USB vendor id 列表，填写16进制，此处为4817的16进制
                "value": "0x12D1"
              },
              {
                "name": "pid", // 支持的 USB product id 列表，填写16进制，此处为4258的16进制
                "value": "0x10A2"
              }
            ]
          }
        ]
      }
    }
    ```

7. 完成客户端和驱动示例代码开发后，请参考[使用本地真机运行应用/服务](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V5/ide-run-device-V5)，将Hap导入设备中，并点击hap中的Hello，查看是否会转变为Hello world，即实现ipc通信功能。

## 扩展设备能力

扩展外设管理提供了HID DDK和USB DDK两种能力，用于驱动开发；

具体使用方法，请参考：

* [HID DDK开发指导](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/napi/hid-ddk-guidelines.md)
* [USB DDK开发指导](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/napi/usb-ddk-guidelines.md)

## 应用签名

应用需要配置签名文件才能在设备上运行，并且扩展外设管理客户端开发，需要配置扩展外设的权限：ohos.permission.ACCESS_EXTENSIONAL_DEVICE_DRIVER。

如果使用HID/USB DDK请添加对应权限，具体权限请查看上方开发指导。

自动签名方法： 请参考[自动签名](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V5/ide-signing-V5#section18815157237)。

权限配置方法： 请参考[使用ACL的签名配置指导](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V5/ide-signing-V5#section157591551175916)。
