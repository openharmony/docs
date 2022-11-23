# ServiceAbility开发指导

## 场景介绍
基于Service模板的Ability（以下简称“Service”）主要用于后台运行任务（如执行音乐播放、文件下载等），但不提供用户交互界面。Service可由其他应用或Ability启动。即使用户切换到其他应用，Service仍将在后台继续运行。

## 接口说明

**表1** Service中相关生命周期API功能介绍
|接口名|描述|
|:------|:------|
|onStart?(): void|该方法在创建Service的时候调用，用于Service的初始化。在Service的整个生命周期只会调用一次，调用时传入的Want应为空。|
|onCommand?(want: Want, startId: number): void|在Service创建完成之后调用，该方法在客户端每次启动该Service时都会调用，开发者可以在该方法中做一些调用统计、初始化类的操作。|
|onConnect?(want: Want): rpc.RemoteObject|在Ability和Service连接时调用。|
|onDisconnect?(want: Want): void|在Ability与绑定的Service断开连接时调用。|
|onStop?(): void|在Service销毁时调用。开发者应通过实现此方法来清理资源，如关闭线程、注册的侦听器等。|

## 开发步骤

### 创建注册Service

1. 重写Service的生命周期方法，来添加其他Ability请求与Service Ability交互时的处理方法。
   
   创建Service的代码示例如下：
   
   ```javascript
   export default {
       onStart() {
           console.log('ServiceAbility onStart');
       },
       onCommand(want, startId) {
           console.log('ServiceAbility onCommand');
       },
       onConnect(want) {
           console.log('ServiceAbility OnConnect');
           return new FirstServiceAbilityStub('test');
       },
       onDisconnect(want) {
           console.log('ServiceAbility OnDisConnect');
       },
       onStop() {
           console.log('ServiceAbility onStop');
       },
   }
   ```

2. 注册Service。

   Service需要在应用配置文件config.json中进行注册，注册类型type需要设置为service。
   
   ```javascript
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

- bundleName：表示包名称。
- abilityName：表示待启动的Ability名称。

启动本地设备Service的代码示例如下：

```javascript
import featureAbility from '@ohos.ability.featureAbility';
let promise = featureAbility.startAbility(
    {
        want:
        {
            bundleName: "com.jstest.service",
            abilityName: "com.jstest.service.ServiceAbility",
        },
    }
); 
```

执行上述代码后，Ability将通过startAbility() 方法来启动Service。
- 如果Service尚未运行，则系统会先调用onStart()来初始化Service，再回调Service的onCommand()方法来启动Service。
- 如果Service正在运行，则系统会直接回调Service的onCommand()方法来启动Service。

启动远端设备Service的代码示例如下，getRemoteDeviceId()方法详见[连接远程Service](#连接远程service当前仅对系统应用开放)：

```javascript
import featureAbility from '@ohos.ability.featureAbility';
let promise = featureAbility.startAbility(
    {
        want:
        {
            deviceId: getRemoteDeviceId(),    //远端设备Id
            bundleName: "com.jstest.service",
            abilityName: "com.jstest.service.ServiceAbility",
        },
    }
); 
```


### 停止Service

  Service一旦创建就会一直保持在后台运行，除非必须回收内存资源，否则系统不会停止或销毁Service。

  

### 连接本地Service

如果Service需要与Page Ability或其他应用的Service Ability进行交互，则须创建用于连接的Connection。Service支持其他Ability通过connectAbility()方法与其进行连接。


开发者可使用如下两种方式实现连接Service。

1. 使用IDL自动生成代码

    使用OpenHarmony IDL（OpenHarmony Interface Definition Language）来自动生成对应客户端服务端及IRemoteObject代码，具体示例代码和说明请参考：

   - [`OpenHarmony IDL`：TS开发步骤](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/IDL/idl-guidelines.md#ts%E5%BC%80%E5%8F%91%E6%AD%A5%E9%AA%A4)

2. 在对应文件编写代码

    在使用connectAbility()处理回调时，需要传入目标Service的Want与IAbilityConnection的实例。IAbilityConnection提供了以下方法供开发者实现：onConnect()是用来处理连接Service成功的回调，onDisconnect()是用来处理Service异常死亡的回调，onFailed()是用来处理连接Service失败的回调。

    创建连接本地Service回调实例的代码示例如下：

    ```javascript
    import prompt from '@system.prompt'

    var option = {
        onConnect: function onConnectCallback(element, proxy) {
            console.log(`onConnectLocalService onConnectDone`)
            if (proxy === null) {
                prompt.showToast({
                    message: "Connect service failed"
                })
                return
            }
            let data = rpc.MessageParcel.create()
            let reply = rpc.MessageParcel.create()
            let option = new rpc.MessageOption()
            data.writeInterfaceToken("connect.test.token")
            proxy.sendRequest(0, data, reply, option)
            prompt.showToast({
                message: "Connect service success"
            })
        },
        onDisconnect: function onDisconnectCallback(element) {
            console.log(`onConnectLocalService onDisconnectDone element:${element}`)
            prompt.showToast({
                message: "Disconnect service success"
            })
        },
        onFailed: function onFailedCallback(code) {
            console.log(`onConnectLocalService onFailed errCode:${code}`)
            prompt.showToast({
                message: "Connect local service onFailed"
            })
        }
    }
    ```

    连接本地Service的代码示例如下：

    ```javascript
    import featureAbility from '@ohos.ability.featureAbility';
    let connectId = featureAbility.connectAbility(
        {
            bundleName: "com.jstest.service",
            abilityName: "com.jstest.service.ServiceAbility",
        },
        {
            onConnect: onConnectCallback,
            onDisconnect: onDisconnectCallback,
            onFailed: onFailedCallback,
        },
    );
    ```

    同时，Service侧也需要在onConnect()时返回IRemoteObject，从而定义与Service进行通信的接口。onConnect()需要返回一个IRemoteObject对象。OpenHarmony提供了IRemoteObject的默认实现，开发者可以通过继承rpc.RemoteObject来创建自定义的实现类。

    Service侧把自身的实例返回给调用侧的代码示例如下：

    ```javascript
    import rpc from "@ohos.rpc";

    class FirstServiceAbilityStub extends rpc.RemoteObject {
    constructor(des: any) {
        if (typeof des === 'string') {
            super(des)
        } else {
            return
        }
    }

    onRemoteRequest(code: number, data: any, reply: any, option: any) {
        console.log(printLog + ` onRemoteRequest called`)
        if (code === 1) {
            let string = data.readString()
            console.log(printLog + ` string=${string}`)
            let result = Array.from(string).sort().join('')
            console.log(printLog + ` result=${result}`)
            reply.writeString(result)
        } else {
            console.log(printLog + ` unknown request code`)
        }
        return true;
    }
    ```

### 连接远程Service（当前仅对系统应用开放）

>说明：由于DeviceManager的getTrustedDeviceListSync接口仅对系统应用开放，当前连接远程Service仅支持系统应用。

如果Service需要与Page Ability或其他应用的Service Ability进行跨设备交互，则须创建用于连接的Connection。Service支持其他Ability通过connectAbility()方法与其进行跨设备连接。

在使用connectAbility()处理回调时，需要传入目标Service的Want与IAbilityConnection的实例。IAbilityConnection提供了以下方法供开发者实现：onConnect()是用来处理连接Service成功的回调，onDisconnect()是用来处理Service异常死亡的回调，onFailed()是用来处理连接Service失败的回调。

创建连接远程Service回调实例的代码示例如下：

```ts
import prompt from '@system.prompt'

var option = {
    onConnect: function onConnectCallback(element, proxy) {
        console.log(`onConnectRemoteService onConnectDone`)
        if (proxy === null) {
            prompt.showToast({
                message: "Connect service failed"
            })
            return
        }
        let data = rpc.MessageParcel.create()
        let reply = rpc.MessageParcel.create()
        let option = new rpc.MessageOption()
        data.writeInterfaceToken("connect.test.token")
        proxy.sendRequest(0, data, reply, option)
        prompt.showToast({
            message: "Connect service success"
        })
    },
    onDisconnect: function onDisconnectCallback(element) {
        console.log(`onConnectRemoteService onDisconnectDone element:${element}`)
        prompt.showToast({
            message: "Disconnect service success"
        })
    },
    onFailed: function onFailedCallback(code) {
        console.log(`onConnectRemoteService onFailed errCode:${code}`)
        prompt.showToast({
            message: "Connect local service onFailed"
        })
    }
}
```

目标Service的Want需要包含远程deviceId，该远程deviceId可通过deviceManager获取,具体示例代码如下：

```ts
import deviceManager from '@ohos.distributedHardware.deviceManager';

//dmClass具体实现请参考：相关实例 分布式Demo 章节中的实现
let dmClass;

function getRemoteDeviceId() {
    if (typeof dmClass === 'object' && dmClass != null) {
        let list = dmClass.getTrustedDeviceListSync();
        if (typeof (list) == 'undefined' || typeof (list.length) == 'undefined') {
            console.log("MainAbility onButtonClick getRemoteDeviceId err: list is null");
            return;
        }
        console.log("MainAbility onButtonClick getRemoteDeviceId success:" + list[0].deviceId);
        return list[0].deviceId;
    } else {
        console.log("MainAbility onButtonClick getRemoteDeviceId err: dmClass is null");
    }
}
```

连接远程Service的代码示例如下：

```ts
import featureAbility from '@ohos.ability.featureAbility';
let connectId = featureAbility.connectAbility(
    {
        deviceId: getRemoteDeviceId(),
        bundleName: "ohos.samples.etsDemo",
        abilityName: "ohos.samples.etsDemo.ServiceAbility",
    },
    {
        onConnect: onConnectCallback,
        onDisconnect: onDisconnectCallback,
        onFailed: onFailedCallback,
    },
);
```
在跨设备场景下，需要向用户申请数据同步的权限。具体示例代码如下：

```ts
import abilityAccessCtrl from "@ohos.abilityAccessCtrl";
import bundle from '@ohos.bundle';
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
    if (result == abilityAccessCtrl.GrantStatus.PERMISSION_GRANTED) {
    } else {
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

同时，Service侧也需要在onConnect()时返回IRemoteObject，从而定义与Service进行通信的接口。onConnect()需要返回一个IRemoteObject对象。OpenHarmony提供了IRemoteObject的默认实现，开发者可以通过继承rpc.RemoteObject来创建自定义的实现类。

Service侧把自身的实例返回给调用侧的代码示例如下：

```ts
import rpc from "@ohos.rpc";

class FirstServiceAbilityStub extends rpc.RemoteObject {
    constructor(des: any) {
        if (typeof des === 'string') {
            super(des)
        } else {
            return
        }
    }

    onRemoteRequest(code: number, data: any, reply: any, option: any) {
        console.log(printLog + ` onRemoteRequest called`)
        if (code === 1) {
            let string = data.readString()
            console.log(printLog + ` string=${string}`)
            let result = Array.from(string).sort().join('')
            console.log(printLog + ` result=${result}`)
            reply.writeString(result)
        } else {
            console.log(printLog + ` unknown request code`)
        }
        return true;
    }
}

export default {
    onStart() {
        console.info('ServiceAbility onStart');
    },
    onStop() {
        console.info('ServiceAbility onStop');
    },
    onConnect(want) {
        console.log("ServiceAbility onConnect");
        try {
            let value = JSON.stringify(want);
            console.log("ServiceAbility want:" + value);
        } catch(error) {
            console.log("ServiceAbility error:" + error);
        }
        return new FirstServiceAbilityStub("first ts service stub");
    },
    onDisconnect(want) {
        console.log("ServiceAbility onDisconnect");
        let value = JSON.stringify(want);
        console.log("ServiceAbility want:" + value);
    },
    onCommand(want, startId) {
        console.info('ServiceAbility onCommand');
        let value = JSON.stringify(want);
        console.log("ServiceAbility want:" + value);
        console.log("ServiceAbility startId:" + startId);
    }
};
```

## 相关实例

针对ServiceAbility开发，有以下相关实例可供参考：
- [`ServiceAbility`：ServiceAbility的创建与使用（ArkTS）（API8）](https://gitee.com/openharmony/applications_app_samples/tree/master/ability/ServiceAbility)
- [`DMS`：分布式Demo（ArkTS）（API8）（Full SDK）](https://gitee.com/openharmony/applications_app_samples/tree/master/ability/DMS)
