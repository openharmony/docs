# ChangeLog
**关键的接口/组件变更**
## 包管理子系统

### 结构体BundleInfo

#### 变更前：

BundleInfo结构体中包含了abilityInfo和hapModuleInfo这两个属性。

#### 变更后

BundleInfo结构体中将abilityInfo和hapModuleInfo这两个属性修改为abilityInfos和hapModuleInfos。

#### 变更影响

无

#### 关键的接口/组件变更

无

#### 适配指导

如果代码中有使用到上述已删除的属性，需要适配新的结构体。

### 结构体AbilityInfo

#### 变更前：

AbilityInfo结构体中包含了formEntity、minFormHeight、defaultFormHeight、minFormWidth、defaultFormWidth和customizeData属性。

#### 变更后

AbilityInfo结构体中删除了formEntity、minFormHeight、defaultFormHeight、minFormWidth、defaultFormWidth和customizeData属性，其中customizeData修改为metaData。

#### 变更影响

无

#### 关键的接口/组件变更

无

#### 适配指导

如果代码中有使用到上述已删除的属性，需要适配新的结构体。

### 结构体ApplicationInfo

#### 变更前：

ApplicationInfo结构体中包含了customizeData这个属性。

#### 变更后

AbilityInfo结构体中删除了customizeData，修改为metaData。

#### 变更影响

无

#### 关键的接口/组件变更

无

#### 适配指导

如果代码中有使用到上述已删除的属性，需要适配新的结构体。

### 接口getAllShortcutInfo

#### 变更前：

该接口查询快捷信息。

#### 变更后

该接口已废弃，改为系统API，不支持三方应用。

#### 变更影响

使用该接口的代码需要删除。

#### 关键的接口/组件变更

无

#### 适配指导

无

### 接口checkPermission

#### 变更前：

该接口查询权限的授权状态。

#### 变更后

该接口已废弃，包管理子系统不提供该接口。

#### 变更影响

使用该接口的代码需要删除。

#### 关键的接口/组件变更

无

#### 适配指导

调用Context提供的权限查询接口。

```C++
import featureAbility from '@ohos.ability.featureAbility'
import bundle from '@ohos.bundle'
var context = featureAbility.getContext();
bundle.getBundleInfo('com.context.test', 1, (datainfo) =>{
	context.verifyPermission("com.example.permission", datainfo.uid);
});
```



## 软总线子系统

### 结构体MessageOption

#### 变更前：

MessageOption结构体中`TF_WAIT_TIME == 4`。

#### 变更后

MessageOption结构体中`TF_WAIT_TIME == 8`。

#### 变更影响

RPC 同步调用默认等待时间从4秒变为8秒。

#### 关键的接口/组件变更

无

#### 适配指导

涉及RPC通信的代码，可以根据业务情况设置等待时间: `setWaitTime(waitTime: number): void`。



### 接口queryLocalInterface

#### 变更前：

接口返回值为`IRemoteBroker`。

#### 变更后

接口返回值为`IRemoteObject`。

#### 变更影响

使用该接口的代码，接口返回值类型为`IRemoteObject`。

#### 关键的接口/组件变更

无

#### 适配指导

```
import FA from "@ohos.ability.featureAbility";
let proxy;
let connect = {
    onConnect: function(elementName, remoteProxy) {
        console.log("RpcClient: js onConnect called.");
        proxy = remoteProxy;
    },
    onDisconnect: function (elementName) {
        console.log("RpcClient: onDisconnect");
    },
    onFailed: function() {
        console.log("RpcClient: onFailed");
    }
};
let want = {
    "bundleName":"com.ohos.server",
    "abilityName":"com.ohos.server.MainAbility",
};
FA.connectAbility(want, connect);
let broker = proxy.queryLocalInterface("testObject");
console.log("RpcClient: queryLocalInterface is " + broker);
```



### 接口readCharArray

#### 变更前：

`readCharArray(dataIn: boolean[]) : void`: 入参类型为bool数组。

`readCharArray(): boolean[]`: 返回值为bool数组。

#### 变更后

`readCharArray(dataIn: boolean[]) : void`: 入参类型为number数组。

`readCharArray(): boolean[]`: 返回值为number数组。

#### 变更影响

使用该接口的代码入参、返回值类型从`boolean[]`转为`number[]`。

#### 关键的接口/组件变更

无

#### 适配指导

```
let data = rpc.MessageParcel.create();
let result = data.writeCharArray(['a', 'b', 'c']);
console.log("RpcClient: writeCharArray is " + result);
let array = new Array(3);
data.readCharArray(array);
```

```
let data = rpc.MessageParcel.create();
let result = data.writeCharArray(['a', 'b', 'c']);
console.log("RpcClient: writeCharArray is " + result);
let array = data.readCharArray();
console.log("RpcClient: readCharArray is " + array);
```



### 接口sendRequest

#### 变更前：

该接口返回值为`boolean`。

#### 变更后

该接口返回值为`Promise<SendRequestResult>`。

#### 变更影响

使用该接口的代码返回值类型为期约`Promise<SendRequestResult>`。

#### 关键的接口/组件变更

无

#### 适配指导

```
import FA from "@ohos.ability.featureAbility";
let proxy;
let connect = {
    onConnect: function(elementName, remoteProxy) {
        console.log("RpcClient: js onConnect called.");
        proxy = remoteProxy;
    },
    onDisconnect: function(elementName) {
        console.log("RpcClient: onDisconnect");
    },
    onFailed: function() {
        console.log("RpcClient: onFailed");
    }
};
let want = {
    "bundleName": "com.ohos.server",
    "abilityName": "com.ohos.server.MainAbility",
};
FA.connectAbility(want, connect);
let option = new rpc.MessageOption();
let data = rpc.MessageParcel.create();
let reply = rpc.MessageParcel.create();
data.writeInt(1);
data.writeString("hello");
proxy.sendRequest(1, data, reply, option)
    .then(function(result) {
        if (result.errCode === 0) {
            console.log("sendRequest got result");
            result.reply.readException();
            let msg = result.reply.readString();
            console.log("RPCTest: reply msg: " + msg);
        } else {
            console.log("RPCTest: sendRequest failed, errCode: " + result.errCode);
        }
    }).catch(function(e) {
        console.log("RPCTest: sendRequest got exception: " + e.message);
    }).finally (() => {
        console.log("RPCTest: sendRequest ends, reclaim parcel");
        data.reclaim();
        reply.reclaim();
    });
```

