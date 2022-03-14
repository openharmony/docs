# ServiceAbility开发指导

## 创建Service<a name="section17436202895812"></a>

1. Service也是一种Ability，Ability为Service提供了以下生命周期方法，开发者可以重写这些方法，来添加其他Ability请求与Service Ability交互时的处理方法。

   - onStart()

     该方法在创建Service的时候调用，用于Service的初始化。在Service的整个生命周期只会调用一次，调用时传入的Want应为空。

   - onCommand()

     在Service创建完成之后调用，该方法在客户端每次启动该Service时都会调用，开发者可以在该方法中做一些调用统计、初始化类的操作。

   - onConnect()

     在Ability和Service连接时调用，该方法返回IRemoteObject对象，开发者可以在该回调函数中生成对应Service的IPC通信通道，以便Ability与Service交互。Ability可以多次连接同一个Service，系统会缓存该Service的IPC通信对象，只有第一个客户端连接Service时，系统才会调用Service的onConnect方法来生成IRemoteObject对象，而后系统会将同一个IRemoteObject对象传递至其他连接同一个Service的所有客户端，而无需再次调用onConnect方法。

   - onDisconnect()

     在Ability与绑定的Service断开连接时调用。

   - onStop()

     在Service销毁时调用。Service应通过实现此方法来清理任何资源，如关闭线程、注册的侦听器等。

   创建Service的代码示例如下：

   ```javascript
   export default {
       onStart(want) {
           console.log('ServiceAbility onStart');
       },
       onCommand(want, restart, startId) {
           console.log('ServiceAbility onCommand');
       },
       onConnect(want) {
           console.log('ServiceAbility OnConnect');
       },
       onDisconnect() {
           console.log('ServiceAbility OnDisConnect');
       },
       onStop() {
           console.log('ServiceAbility onStop');
       },
   }
   ```

2.  注册Service。

    Service也需要在应用配置文件config.json中进行注册，注册类型type需要设置为service。

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

    


## 启动Service<a name="section944219415599"></a>

Ability为开发者提供了startAbility()方法来启动另外一个Ability。因为Service也是Ability的一种，开发者同样可以通过将Want传递给该方法来启动Service。

开发者可以通过构造包含BundleName与AbilityName的Want对象来设置目标Service信息。参数的含义如下：

- BundleName：表示包名称。
- AbilityName：表示待启动的Ability名称。

启动本地设备Service的代码示例如下：

```javascript
import featureAbility from '@ohos.ability.featureability';
var promise = await featureAbility.startAbility(
    {
        want:
        {
            bundleName: "com.jstest.serviceability",
            abilityName: "com.jstest.serviceability.MainAbility",
        },
    }
); 
```

- 执行上述代码后，Ability将通过startAbility() 方法来启动Service。
  - 如果Service尚未运行，则系统会先调用onStart()来初始化Service，再回调Service的onCommand()方法来启动Service。
  - 如果Service正在运行，则系统会直接回调Service的onCommand()方法来启动Service。

- 停止Service

  Service一旦创建就会一直保持在后台运行，除非必须回收内存资源，否则系统不会停止或销毁Service。开发者可以在Service中通过terminateAbility()停止本Service或在其他Ability调用stopAbility()来停止Service。

  

## 连接本地Service<a name="section126857614018"></a>

如果Service需要与Page Ability或其他应用的Service Ability进行交互，则须创建用于连接的Connection。Service支持其他Ability通过connectAbility()方法与其进行连接。

在使用connectAbility()处理回调时，需要传入目标Service的Want与IAbilityConnection的实例。IAbilityConnection提供了以下方法供开发者实现：onConnect()是用来处理连接Service成功的回调，onDisconnect()是用来处理Service异常死亡的回调，onFailed()是用来处理连接Service失败的回调。

创建连接本地Service回调实例的代码示例如下：

```javascript
var mRemote;
function onConnectCallback(element, remote){
    console.log('ConnectAbility onConnect Callback')
    mRemote = remote;
}

function onDisconnectCallback(element){
    console.log('ConnectAbility onDisconnect Callback')
}

function onFailedCallback(code){
    console.log('ConnectAbility onFailed Callback')
}
```

连接本地Service的代码示例如下：

```javascript
import featureAbility from '@ohos.ability.featureability';
var connId = featureAbility.connectAbility(
    {
        bundleName: "com.jstest.serviceability",
        abilityName: "com.jstest.serviceability.MainAbility",
    },
    {
        onConnect: onConnectCallback,
        onDisconnect: onDisconnectCallback,
        onFailed: onFailedCallback,
    },
);
```

同时，Service侧也需要在onConnect()时返回IRemoteObject，从而定义与Service进行通信的接口。onConnect()需要返回一个IRemoteObject对象，OpenHarmony提供了IRemoteObject的默认实现，用户可以通过继承rpc.RemoteObject来创建自定义的实现类。

Service侧把自身的实例返回给调用侧的代码示例如下：

```javascript
import rpc from "@ohos.rpc";

var mMyStub;
export default {
    onStart(want) {
        class MyStub extends rpc.RemoteObject{
            constructor(des) {
                if (typeof des === 'string') {
                    super(des);
                }
                return null;
            }
            onRemoteRequest(code, message, reply, option) {
            }
        }
        mMyStub = new MyStub("ServiceAbility-test");
    },
    onCommand(want, restart, startId) {
        console.log('ServiceAbility onCommand');
    },
    onConnect(want) {
        console.log('ServiceAbility OnConnect');
        return mMyStub;
    },
    onDisconnect() {
        console.log('ServiceAbility OnDisConnect');
    },
    onStop() {
        console.log('ServiceAbility onStop');
    },
}
```

## 连接远程Service<a name="section126857614019"></a>

如果Service需要与Page Ability或其他应用的Service Ability进行跨设备交互，则须创建用于连接的Connection。Service支持其他Ability通过connectAbility()方法与其进行跨设备连接。

在使用connectAbility()处理回调时，需要传入目标Service的Want与IAbilityConnection的实例。IAbilityConnection提供了以下方法供开发者实现：onConnect()是用来处理连接Service成功的回调，onDisconnect()是用来处理Service异常死亡的回调，onFailed()是用来处理连接Service失败的回调。

创建连接远程Service回调实例的代码示例如下：

```javascript
var mRemote;
function onConnectCallback(element, remote){
    console.log('ConnectRemoteAbility onConnect Callback')
    mRemote = remote;
}

function onDisconnectCallback(element){
    console.log('ConnectRemoteAbility onDisconnect Callback')
}

function onFailedCallback(code){
    console.log('ConnectRemoteAbility onFailed Callback')
}
```

目标Service的Want需要包含远程deviceId，该远程deviceId可通过deviceManager获取。

连接远程Service的代码示例如下：

```javascript
import featureAbility from '@ohos.ability.featureability';
var connId = featureAbility.connectAbility(
    {
        deviceId: deviceId,
        bundleName: "com.jstest.serviceability",
        abilityName: "com.jstest.serviceability.MainAbility",
    },
    {
        onConnect: onConnectCallback,
        onDisconnect: onDisconnectCallback,
        onFailed: onFailedCallback,
    },
);
```

同时，Service侧也需要在onConnect()时返回IRemoteObject，从而定义与Service进行通信的接口。onConnect()需要返回一个IRemoteObject对象，OpenHarmony提供了IRemoteObject的默认实现，用户可以通过继承rpc.RemoteObject来创建自定义的实现类。

Service侧把自身的实例返回给调用侧的代码示例如下：

```javascript
import rpc from "@ohos.rpc";

var mMyStub;
export default {
    onStart(want) {
        class MyStub extends rpc.RemoteObject{
            constructor(des) {
                if (typeof des === 'string') {
                    super(des);
                }
                return null;
            }
            onRemoteRequest(code, message, reply, option) {
            }
        }
        mMyStub = new MyStub("ServiceAbility-test");
    },
    onCommand(want, restart, startId) {
        console.log('ServiceAbility onCommand');
    },
    onConnect(want) {
        console.log('ServiceAbility OnConnect');
        return mMyStub;
    },
    onDisconnect() {
        console.log('ServiceAbility OnDisConnect');
    },
    onStop() {
        console.log('ServiceAbility onStop');
    },
}
```