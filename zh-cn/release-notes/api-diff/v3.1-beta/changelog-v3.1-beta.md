# ChangeLog
##### 关键的接口/组件变更
## 进程间通信子系统
#### cl.rpc.1 sendRequest返回值类型变更

##### 变更影响

js的RemoteProxy和RemoteObject的sendRequest变更为异步接口，返回Promise，兑现值是SendRequestResult的实例。原有应用需要适配。

##### 关键的接口/组件变更

```
模块：ohos.rpc.IRemoteObject, ohos.rpc.RemoteProxy和ohos.rpc.RemoteObject
接口：sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): boolean

变更后接口：
sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): Promise<SendRequestResult>
```

**适配指导**

```
import rpc from "@ohos.rpc"
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

let option = new rpc.MessageOption()
let data = rpc.MessageParcel.create()
let reply = rpc.MessageParcel.create()
proxy.sendRequest(1, data, reply, option)
	.then(function(result) {  
		console.info("send request done")
		if (result.errCode === 0) {
			// read result from result.reply
		}
	})
	.catch(function(e) {
		console.error("send request failed: " + e)
	})
	.finally(() => {
		data.reclaim()
		reply.reclaim()
	})
```

