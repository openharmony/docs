# LifecycleService接口切换
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @xialiangwei-->
<!--SE: @jsjzju-->
<!--TSE: @lixueqing513-->


  | FA模型接口 | Stage模型接口对应d.ts文件 | Stage模型对应接口 | 
| -------- | -------- | -------- |
| onStart?():&nbsp;void; | \@ohos.app.ability.ServiceExtensionAbility.d.ts | [onCreate(want:&nbsp;Want):&nbsp;void;](../reference/apis-ability-kit/js-apis-app-ability-serviceExtensionAbility-sys.md#oncreate) |
| onCommand?(want:&nbsp;Want,&nbsp;startId:&nbsp;number):&nbsp;void; | \@ohos.app.ability.ServiceExtensionAbility.d.ts | [onRequest(want:&nbsp;Want,&nbsp;startId:&nbsp;number):&nbsp;void;](../reference/apis-ability-kit/js-apis-app-ability-serviceExtensionAbility-sys.md#onrequest) |  |
| onStop?():&nbsp;void; | \@ohos.app.ability.ServiceExtensionAbility.d.ts | [onDestroy():&nbsp;void;](../reference/apis-ability-kit/js-apis-app-ability-serviceExtensionAbility-sys.md#ondestroy) |  |
| onConnect?(want:&nbsp;Want):&nbsp;rpc.RemoteObject; | \@ohos.app.ability.ServiceExtensionAbility.d.ts | [onConnect(want:&nbsp;Want):&nbsp;rpc.RemoteObject;](../reference/apis-ability-kit/js-apis-app-ability-serviceExtensionAbility-sys.md#onconnect) |  |
| onDisconnect?(want:&nbsp;Want):&nbsp;void; | \@ohos.app.ability.ServiceExtensionAbility.d.ts | [onDisconnect(want:&nbsp;Want):&nbsp;void;](../reference/apis-ability-kit/js-apis-app-ability-serviceExtensionAbility-sys.md#ondisconnect) |  |
| onReconnect?(want:&nbsp;Want):&nbsp;void; | \@ohos.app.ability.ServiceExtensionAbility.d.ts | [onReconnect(want:&nbsp;Want):&nbsp;void;](../reference/apis-ability-kit/js-apis-app-ability-serviceExtensionAbility-sys.md#onreconnect) |  |
