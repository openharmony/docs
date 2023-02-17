# Changelog
##### Key API/Component Changes
## IPC Subsystem
#### cl.rpc.1 sendRequest Return Value Type Change

##### Change Impact

The **sendRequest** method in the JS modules **RemoteProxy** and **RemoteObject** is changed to an asynchronous interface. The new version uses a **Promise** object to return a **SendRequestResult** instance. Existing applications need to be adapted.

##### Key API/Component Changes

```
Module: ohos.rpc.IRemoteObject, ohos.rpc.RemoteProxy and ohos.rpc.RemoteObject
Old method: sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): boolean

New method:
sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): Promise<SendRequestResult>
```

**Adaptation Guidelines**

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
