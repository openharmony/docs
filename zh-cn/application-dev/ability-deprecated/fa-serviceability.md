# ServiceAbility开发指导

## 场景介绍
基于Service模板的Ability（以下简称“Service”）主要用于后台运行任务（如执行音乐播放、文件下载等），但不提供用户交互界面。Service可由其他应用或Ability启动。即使用户切换到其他应用，Service仍将在后台继续运行。

## 生命周期

**表1** Service中相关生命周期API功能介绍
|接口名|描述|
|:------|:------|
|onStart?(): void|该方法在创建Service的时候调用，用于Service的初始化，在Service的整个生命周期只会调用一次。|
|onCommand?(want: Want, startId: number): void|在Service创建完成之后调用，该方法在客户端每次启动该Service时都会调用，开发者可以在该方法中做一些调用统计、初始化类的操作。|
|onConnect?(want: Want): rpc.RemoteObject|在Ability和Service连接时调用。|
|onDisconnect?(want: Want): void|在Ability与绑定的Service断开连接时调用。|
|onStop?(): void|在Service销毁时调用。开发者应通过实现此方法来清理资源，如关闭线程、注册的侦听器等。|

onCommand()与onConnect()的区别在于：
 - onCommand()只能被startAbility或startAbilityForResult触发，客户端每次启动Service均会触发该回调
 - onConnect()只能被connectAbility触发，客户端每次与Servcie建立新的连接时会触发该回调

## 开发步骤

### 创建注册Service

1. 重写Service的生命周期方法，来添加其他Ability请求与Service Ability交互时的处理方法。
   
   创建Service的代码示例如下：
   
   ```ts
    export default {
        onStart() {
            console.log('ServiceAbility onStart');
        },
        onCommand(want, startId) {
            console.log('ServiceAbility onCommand');
        },
        onConnect(want) {
            console.log('ServiceAbility OnConnect');
            // ServiceAbilityStub的实现在下文给出
            return new ServiceAbilityStub('test');
        },
        onDisconnect(want) {
            console.log('ServiceAbility OnDisConnect');
        },
        onStop() {
            console.log('ServiceAbility onStop');
        }
    }
   ```

2. 注册Service。

   Service需要在应用配置文件config.json中进行注册，注册类型type需要设置为service。
   
   ```json
    {
      "module": {
        "abilities": [
          {
            "name": ".ServiceAbility",
            "type": "service",
            "visible": true
            ...
          }
        ]
        ...
      }
      ...
    }
   ```



### 启动Service

Ability为开发者提供了startAbility()方法来启动另外一个Ability。因为Service也是Ability的一种，开发者同样可以通过将Want传递给该方法来启动Service。

开发者可以通过构造包含bundleName与abilityName的Want对象来设置目标Service信息。参数的含义如下：

- bundleName：表示对端应用的Bundle名称。
- abilityName：表示待启动的Ability名称。

启动本地设备Service的代码示例如下：

```ts
import featureAbility from '@ohos.ability.featureAbility'

featureAbility.startAbility(
    {
        want:
        {
            bundleName: "com.jstest.service",
            abilityName: "com.jstest.service.ServiceAbility"
        }
    }
).then((err) => {
    console.log("startService success");
}).catch (err => {
    console.log("startService FAILED");
});
```

执行上述代码后，Ability将通过startAbility() 方法来启动Service。
- 如果Service尚未运行，则系统会先初始化Service，然后回调onStart()来启动Service，再回调onCommand()方法。
- 如果Service正在运行，则系统会直接回调Service的onCommand()方法。

启动远端设备Service的代码示例如下，详见[连接远程Service](fa-serviceability.md#连接远程service当前仅对系统应用开放)：

```ts
import featureAbility from '@ohos.ability.featureAbility'

featureAbility.startAbility(
    {
        want:
        {
            deviceId: remoteDeviceId,    // 远端设备Id
            bundleName: "com.jstest.service",
            abilityName: "com.jstest.service.ServiceAbility"
        }
    }
).then((err) => {
    console.log("startService success");
}).catch (err => {
    console.log("startService FAILED");
});
```


### 停止Service

  常规情况下，Service可以将自己停止，或者被系统停止，具体场景如下：
   - Service调用particleAbility.terminateSelf()方法将自己停止。
   - Service所在的应用进程退出，Service将随着进程被回收。
   - 若Service仅仅是通过connectAbility()方法被访问的（从未执行过onCommand()回调）,那么当最后一个连接被断开后，系统会将Service停止。

### 连接本地Service

如果Service需要与Page Ability或其他应用的Service Ability进行交互，则须创建用于连接的Connection。Service支持其他Ability通过connectAbility()方法与其进行连接。


开发者可使用如下两种方式实现连接Service。

1. 使用IDL自动生成代码

    使用OpenHarmony IDL（OpenHarmony Interface Definition Language）来自动生成对应客户端服务端及IRemoteObject代码，具体示例代码和说明请参考：

   - [`OpenHarmony IDL`：TS开发步骤](../IDL/idl-guidelines.md#ts)

2. 在对应文件编写代码

    在使用connectAbility()时，需要传入目标Service的Want与ConnectOptions的实例，其中ConnectOptions封装了三个回调，分别对应不同情况，开发者需自行实现：
     - onConnect()：用来处理连接Service成功的回调。
     - onDisconnect()：用来处理Service断连或异常死亡的回调。
     - onFailed()：用来处理连接Service失败的回调。

    创建连接本地Service回调实例的代码示例如下：

    ```ts
    import prompt from '@system.prompt'
    
    var option = {
        onConnect: function onConnectCallback(element, proxy) {
            console.log(`onConnectLocalService onConnectDone`);
            if (proxy === null) {
                prompt.showToast({
                    message: "Connect service failed"
                });
                return;
            }
            // 得到Service的proxy对象后便可以与其进行通信
            let data = rpc.MessageParcel.create();
            let reply = rpc.MessageParcel.create();
            let option = new rpc.MessageOption();
            data.writeString("InuptString");
            proxy.sendRequest(0, data, reply, option);
            prompt.showToast({
                message: "Connect service success"
            });
        },
        onDisconnect: function onDisconnectCallback(element) {
            console.log(`onConnectLocalService onDisconnectDone element:${element}`);
            prompt.showToast({
                message: "Disconnect service success"
            });
        },
        onFailed: function onFailedCallback(code) {
            console.log(`onConnectLocalService onFailed errCode:${code}`);
            prompt.showToast({
                message: "Connect local service onFailed"
            });
        }
    };
    ```

    连接本地Service的代码示例如下：

    ```ts
    import featureAbility from '@ohos.ability.featureAbility'
    
    let want = {
        bundleName: "com.jstest.service",
        abilityName: "com.jstest.service.ServiceAbility"
    };
    let connectId = featureAbility.connectAbility(want, option);
    ```

    同时，Service侧也需要在onConnect()时返回IRemoteObject，从而定义与Service进行通信的接口。onConnect()需要返回一个IRemoteObject对象。OpenHarmony提供了IRemoteObject的默认实现，开发者可以通过继承rpc.RemoteObject来创建自定义的实现类，从而实现与Service的通信。具体使用方法可参考[ohos.rpc API文档](..\reference\apis\js-apis-rpc.md)。

    Service侧把自身的实例返回给调用侧的代码示例如下：

    ```ts
    import rpc from "@ohos.rpc"
    
    class ServiceAbilityStub extends rpc.RemoteObject {
        constructor(des: any) {
            if (typeof des === 'string') {
                super(des);
            } else {
                console.log("Error, the input param is not string");
                return;
            }
        }
    
        onRemoteRequest(code: number, data: any, reply: any, option: any) {
            console.log("onRemoteRequest called");
            // 可根据code执行不同的业务逻辑
            if (code === 1) {
                // 将传入的字符串进行排序
                let string = data.readString();
                console.log(`Input string = ${string}`);
                let result = Array.from(string).sort().join('');
                console.log(`Output result = ${result}`);
                reply.writeString(result);
            } else {
                console.log(`Unknown request code`);
            }
            return true;
        }
    }
    
    export default {
        onStart() {
            console.log('ServiceAbility onStart');
        },
        onCommand(want, startId) {
            console.log('ServiceAbility onCommand');
        },
        onConnect(want) {
            console.log('ServiceAbility OnConnect');
            return new ServiceAbilityStub('ServiceAbilityRemoteObject');
        },
        onDisconnect(want) {
            console.log('ServiceAbility OnDisConnect');
        },
        onStop() {
            console.log('ServiceAbility onStop');
        }
    }
    ```

### 连接远程Service（当前仅对系统应用开放）

连接远程Service，构造ConnectOptions的方法与连接本地Serivce相同，区别在于：
 - 应用需要向用户申请数据同步权限
 - 目标Service的Want需要包含对端设备的deviceId

> 说明：
> (1) 由于DeviceManager的getTrustedDeviceList等接口仅对系统应用开放，当前仅系统应用支持连接远程Service。
> (2) API定义可见：[deviceManager模块](..\reference\apis\js-apis-device-manager.md)
> (3) 参考Demo可见：[分布式Demo](https://gitee.com/openharmony/applications_app_samples/tree/master/ability/DMS)

在跨设备场景下，需要向用户申请数据同步的权限，首先在config.json里配置权限：

```json
{
  ...
  "module": {
    ...
    "reqPermissions": [{
      "name": "ohos.permission.DISTRIBUTED_DATASYNC"
    }]
  }
}
```

DISTRIBUTED_DATASYNC权限需要用户授予，在应用启动时需要向用户弹框请求授予权限，示例代码如下：

```ts
import abilityAccessCtrl from "@ohos.abilityAccessCtrl"
import bundle from '@ohos.bundle'

async function RequestPermission() {
    console.info('RequestPermission begin');
    let array: Array<string> = ["ohos.permission.DISTRIBUTED_DATASYNC"];
    let bundleFlag = 0;
    let tokenID = undefined;
    let userID = 100;
    let appInfo = await bundle.getApplicationInfo('ohos.samples.etsDemo', bundleFlag, userID);
    tokenID = appInfo.accessTokenId;
    let atManager = abilityAccessCtrl.createAtManager();
    let requestPermissions: Array<string> = [];
    for (let i = 0;i < array.length; i++) {
        let result = await atManager.verifyAccessToken(tokenID, array[i]);
        console.info("verifyAccessToken result:" + JSON.stringify(result));
        if (result != abilityAccessCtrl.GrantStatus.PERMISSION_GRANTED) {
            requestPermissions.push(array[i]);
        }
    }
    console.info("requestPermissions:" + JSON.stringify(requestPermissions));
    if (requestPermissions.length == 0 || requestPermissions == []) {
        return;
    }
    let context = featureAbility.getContext();
    context.requestPermissionsFromUser(requestPermissions, 1, (data)=>{
        console.info("data:" + JSON.stringify(data));
    });
    console.info('RequestPermission end');
}
```

获取deviceId需要导入`@ohos.distributedHardware.deviceManager`模块，其中提供了getTrustedDeviceList等接口用于获取远端设备的deviceId。
 - 接口使用可参考[deviceManager模块](..\reference\apis\js-apis-device-manager.md)
 - 具体实现可参考[分布式Demo](https://gitee.com/openharmony/applications_app_samples/tree/master/ability/DMS)

连接远程Service，只需要在want内定义deviceId即可，示例代码如下：

```ts
import featureAbility from '@ohos.ability.featureAbility'

let want = {
    deviceId: remoteDeviceId,
    bundleName: "com.jstest.service",
    abilityName: "com.jstest.service.ServiceAbility"
};
let connectId = featureAbility.connectAbility(want, option);
```

其余实现均与本地连接Service相同，参考[连接本地Service](fa-serviceability.md#连接本地service)的示例代码即可。

## 相关实例

针对ServiceAbility开发，有以下相关实例可供参考：
- [`ServiceAbility`：ServiceAbility的创建与使用（ArkTS）（API8）](https://gitee.com/openharmony/applications_app_samples/tree/master/ability/ServiceAbility)
- [`DMS`：分布式Demo（ArkTS）（API8）（Full SDK）](https://gitee.com/openharmony/applications_app_samples/tree/master/ability/DMS)
