# ServiceExtensionAbility开发指导

## 场景介绍
ExtensionAbility，是Stage模型中新增的扩展组件的基类，一般用于处理无界面的任务，生命周期较简单，没有前后台生命周期。ServiceExtensionAbility是ExtensionAbility的扩展类。

开发者可以自定义类继承ServiceExtensionAbility，通过重写基类中相关生命周期方法，来做初始化、连接中、断开连接时相关业务逻辑操作。

## 接口说明

**表1** ServiceExtensionAbility中相关生命周期API功能介绍
|接口名|描述|
|:------|:------|
|onCreate(want: Want): void|首次调用startAbility、connectAbility时触发，开发者可以进行初始化操作。|
|onRequest(want: Want, startId: number): void|每次调用startAbility都会触发，首次调用时startId为1，重复调用startAbility递增。|
|onConnect(want: Want): rpc.RemoteObject|调用connectAbility触发，重复调用不会再次触发，除非调用disconnectAbility解除绑定后再调用；onConnect返回一个进程通信类RemoteObject。|
|onDisconnect(want: Want): void|调用disconnectAbility触发，Extension如果是用connectAbility拉起的，并且已经没有其他应用绑定这个Extension，则会触发onDestroy生命周期销毁组件。|
|onDestroy(): void|调用停止当前ability接口terminateSelf会触发。|


## 约束与限制

OpenHarmony当前不支持三方应用创建ServiceExtensionAbility。


## 开发步骤

1. 需要在应用配置文件module.json5中进行注册，注册类型type需要设置为service。module.json5配置样例如下所示：


   ```json
    "extensionAbilities":[{
        "name": "ServiceExtAbility",
        "icon": "$media:icon",
        "description": "service",
        "type": "service",
        "visible": true,
        "srcEntrance": "./ets/ServiceExtAbility/ServiceExtAbility.ts"
    }]
   ```


2. 开发者在定义Service的目录下创建TS文件，自定义类继承ServiceExtensionAbility，重写基类回调函数，接口生成的默认相对路径：entry\src\main\ets\ServiceExtAbility\ServiceExtAbility.ts，示例如下：

    ```js
    import ServiceExtensionAbility from '@ohos.application.ServiceExtensionAbility'
    import rpc from '@ohos.rpc'

    class StubTest extends rpc.RemoteObject {
        constructor(des) {
            super(des);
        }
        onRemoteRequest(code, data, reply, option) {
        }
    }

    class ServiceExtAbility extends ServiceExtensionAbility {
        onCreate(want) {
            console.log('onCreate, want:' + want.abilityName);
        }
        onRequest(want, startId) {
            console.log('onRequest, want:' + want.abilityName);
        }
        onConnect(want) {
            console.log('onConnect , want:' + want.abilityName);
            return new StubTest("test");
        }
        onDisconnect(want) {
            console.log('onDisconnect, want:' + want.abilityName);
        }
        onDestroy() {
            console.log('onDestroy');
        }
    }
    ```
## 相关实例

针对ServiceExtensionAbility开发，有以下相关实例可供参考：
- [`ServiceExtAbility`：StageExtAbility的创建与使用（ArkTS）（API9）（Full SDK）](https://gitee.com/openharmony/applications_app_samples/tree/master/ability/ServiceExtAbility)
