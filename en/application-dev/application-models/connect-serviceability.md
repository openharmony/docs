# Connecting to a ServiceAbility


If a ServiceAbility wants to interact with a PageAbility or a ServiceAbility in another application, you must first create a connection by calling **connectAbility()**. This method is defined in the **featureAbility** class for the PageAbility and in the **particleAbility** class for the ServiceAbility. For details about the connection rules, see [Component Startup Rules](component-startup-rules.md). When calling **connectAbility()**, you should pass in a **Want** object containing information about the target ServiceAbility and an **IAbilityConnection** object. **IAbilityConnection** provides the following APIs that you need to implement.

**Table 1** IAbilityConnection APIs

| API| Description|
| -------- | -------- |
| onConnect() | Callback invoked when the ServiceAbility is connected.|
| onDisconnect() | Callback invoked when the ServiceAbility is disconnected.|
| onFailed() | Callback invoked when the connection to the ServiceAbility fails.|


The following sample code enables the PageAbility to create connection callback instances and connect to the local ServiceAbility:

```ts
import rpc from "@ohos.rpc"
import prompt from '@system.prompt'
import featureAbility from '@ohos.ability.featureAbility'

let option = {
  onConnect: function onConnectCallback(element, proxy) {
    console.info(`onConnectLocalService onConnectDone`)
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
    console.info(`onConnectLocalService onDisconnectDone element:${element}`)
    prompt.showToast({
      message: "Disconnect service success"
    })
  },
  onFailed: function onFailedCallback(code) {
    console.info(`onConnectLocalService onFailed errCode:${code}`)
    prompt.showToast({
      message: "Connect local service onFailed"
    })
  }
}

let request = {
  bundleName: "com.example.myapplication",
  abilityName: "com.example.myapplication.ServiceAbility",
}
let connId = featureAbility.connectAbility(request, option)
```


When the ServiceAbility is connected, the **onConnect()** callback is invoked and returns an **IRemoteObject** defining the proxy used for communicating with the ServiceAbility. OpenHarmony provides a default implementation of **IRemoteObject**. You can extend **rpc.RemoteObject** to implement your own class of **IRemoteObject**.


The following sample code shows how the ServiceAbility returns itself to the caller:

```ts
import rpc from "@ohos.rpc"

class FirstServiceAbilityStub extends rpc.RemoteObject {
  constructor(des: any) {
    if (typeof des === 'string') {
      super(des)
    } else {
      return
    }
  }

  onRemoteRequest(code: number, data: any, reply: any, option: any) {
    console.info(`onRemoteRequest called`)
    if (code === 1) {
      let string = data.readString()
      console.info(`string=${string}`)
      let result = Array.from(string).sort().join('')
      console.info(`result=${result}`)
      reply.writeString(result)
    } else {
      console.info(`unknown request code`)
    }
    return true
  }
}
```
