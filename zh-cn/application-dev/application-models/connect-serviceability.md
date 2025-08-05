# 连接ServiceAbility
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @xialiangwei-->
<!--SE: @jsjzju-->
<!--TSE: @lixueqing513-->
<!--deprecated_code_no_check-->

如果ServiceAbility需要与PageAbility或其他应用的ServiceAbility进行交互，则须创建用于连接的Connection。ServiceAbility支持其他Ability通过[connectAbility()](../reference/apis-ability-kit/js-apis-ability-featureAbility.md#featureabilityconnectability7)方法与其进行连接。PageAbility的connectAbility()方法定义在[featureAbility](../reference/apis-ability-kit/js-apis-ability-featureAbility.md)中，ServiceAbility的connectAbility()方法定义在[particleAbility](../reference/apis-ability-kit/js-apis-ability-particleAbility.md)中。连接ServiceAbility的规则详见[组件启动规则](component-startup-rules-fa.md)章节。在使用connectAbility()处理回调时，需要传入目标Service的[Want](../reference/apis-ability-kit/js-apis-app-ability-want.md)与[IAbilityConnection](../reference/apis-ability-kit/js-apis-inner-ability-connectOptions.md)的实例。[IAbilityConnection](../reference/apis-ability-kit/js-apis-inner-ability-connectOptions.md)提供了以下方法供开发者实现。


  **表1** IAbilityConnection接口说明

| 接口名 | 描述 |
| -------- | -------- |
| onConnect() | 用于处理连接Service成功的回调。 |
| onDisconnect() | 用来处理Service异常死亡的回调。 |
| onFailed() | 用来处理连接Service失败的回调。 |


PageAbility创建连接本地ServiceAbility回调实例的代码以及连接本地ServiceAbility的示例代码如下：

```ts
import featureAbility from '@ohos.ability.featureAbility';
import common from '@ohos.app.ability.common';
import Want from '@ohos.app.ability.Want';
import promptAction from '@ohos.promptAction';
import rpc from '@ohos.rpc';
import hilog from '@ohos.hilog';
```
```ts
const TAG: string = 'PageServiceAbility';
const domain: number = 0xFF00;

@Entry
@Component
struct PageServiceAbility {
  //...
  build() {
    Column() {
      //...
      List({ initialIndex: 0 }) {
        ListItem() {
          Row() {
            //...
          }
          .onClick(() => {
            let option: common.ConnectOptions = {
              onConnect: (element, proxy) => {
                hilog.info(domain, TAG, `onConnectLocalService onConnectDone element:` + JSON.stringify(element));
                if (proxy === null) {
                  promptAction.showToast({
                    message: 'connect_service_failed_toast'
                  });
                  return;
                }
                let data = rpc.MessageParcel.create();
                let reply = rpc.MessageParcel.create();
                let option = new rpc.MessageOption();
                data.writeInterfaceToken('connect.test.token');
                proxy.sendRequest(0, data, reply, option);
                promptAction.showToast({
                  message: 'connect_service_success_toast'
                });
              },
              onDisconnect: (element) => {
                hilog.info(domain, TAG, `onConnectLocalService onDisconnectDone element:${element}`);
                promptAction.showToast({
                  message: 'disconnect_service_success_toast'
                });
              },
              onFailed: (code) => {
                hilog.info(domain, TAG, `onConnectLocalService onFailed errCode:${code}`);
                promptAction.showToast({
                  message: 'connect_service_failed_toast'
                });
              }
            };

            let request: Want = {
              bundleName: 'com.samples.famodelabilitydevelop',
              abilityName: 'com.samples.famodelabilitydevelop.ServiceAbility',
            };
            let connId = featureAbility.connectAbility(request, option);
            hilog.info(domain, TAG, `onConnectLocalService onFailed errCode:${connId}`);
          })
        }
        //...
      }
      //...
    }
    //...
  }
}
```


同时，Service侧也需要在[onConnect()](../reference/apis-ability-kit/js-apis-inner-ability-connectOptions.md#onconnect)时返回[IRemoteObject](../reference/apis-ipc-kit/js-apis-rpc.md#iremoteobject)，从而定义与Service进行通信的接口。onConnect()需要返回一个IRemoteObject对象。系统提供了IRemoteObject的默认实现，开发者可以通过继承[rpc.RemoteObject](../reference/apis-ipc-kit/js-apis-rpc.md#remoteobject)来创建自定义的实现类。


Service侧把自身的实例返回给调用侧的示例代码如下：

```ts
import type Want from '@ohos.app.ability.Want';
import rpc from '@ohos.rpc';
import hilog from '@ohos.hilog';

const TAG: string = '[Sample_FAModelAbilityDevelop]';
const domain: number = 0xFF00;

class FirstServiceAbilityStub extends rpc.RemoteObject {
  constructor(des: Object) {
    if (typeof des === 'string') {
      super(des);
    } else {
      return;
    }
  }

  onRemoteRequest(code: number, data: rpc.MessageParcel, reply: rpc.MessageParcel, option: rpc.MessageOption): boolean {
    hilog.info(domain, TAG, 'ServiceAbility onRemoteRequest called');
    if (code === 1) {
      let string = data.readString();
      hilog.info(domain, TAG, `ServiceAbility string=${string}`);
      let result = Array.from(string).sort().join('');
      hilog.info(domain, TAG, `ServiceAbility result=${result}`);
      reply.writeString(result);
    } else {
      hilog.info(domain, TAG, 'ServiceAbility unknown request code');
    }
    return true;
  }
}
//...
```
