# 元能力子系统JS API变更Changelog

## cl.ability.1 AreaMode接口变更
AreaMode接口有多个重复，删除掉重复的AreaMode。

**变更影响**

影响API9版本的JS接口，应用需要进行适配才可以在新版本SDK环境正常实现功能。

**关键的接口/组件变更**

| 模块名                    | 类名                | 方法/属性/枚举/常量                                          | 变更类型 |
| ------------------------- | ------------------- | ------------------------------------------------------------ | -------- |
| @ohos.app.ability.common.d.ts | common.AreaMode |  | 删除     |
| application/Context.d.ts | AreaMode |  | 删除     |


**适配指导**

使用@ohos.app.ability.contextConstant.d.ts中的AreaMode

```ts
import contextConstant from '@ohos.app.ability.contextConstant';
let area: contextConstant.AreaMode = contextConstant.AreaMode.EL1;
```



## cl.ability.2 killProcessesBySelf接口变更

killProcessesBySelf接口命名不合理，修改为killAllProcesses。

**变更影响**

影响API9版本的JS接口，应用需要进行适配才可以在新版本SDK环境正常实现功能。

**关键接口/组件变更**

| 模块名                         | 类名               | 方法/属性/枚举/常量                                   | 变更类型 |
| ------------------------------ | ------------------ | ----------------------------------------------------- | -------- |
| application/ApplicationContext | ApplicationContext | killProcessesBySelf(): Promise\<void\>;               | 删除     |
| application/ApplicationContext | ApplicationContext | killProcessesBySelf(callback: AsyncCallback\<void\>); | 删除     |
| application/ApplicationContext | ApplicationContext | killAllProcesses(): Promise\<void\>;                  | 新增     |
| application/ApplicationContext | ApplicationContext | killAllProcesses(callback: AsyncCallback\<void\>);    | 新增     |


**适配指导**

应用中调用killProcessesBySelf可参考下列代码

变更前代码：

```ts
let context: common.UIAbilityContext = globalThis.abilityContext;
let appContext = context.getApplicationContext();
appContext.killProcessesBySelf()
```

变更后代码：

```ts
let context: common.UIAbilityContext = globalThis.abilityContext;
let appContext = context.getApplicationContext();
appContext.killAllProcesses()
```



## cl.ability.3 getProcessRunningInformation接口变更

getProcessRunningInformation接口命名不合理，修改为getRunningProcessInformation。

**变更影响**

影响API9版本的JS接口，应用需要进行适配才可以在新版本SDK环境正常实现功能。

**关键接口/组件变更**

| 模块名                              | 类名               | 方法/属性/枚举/常量                                          | 变更类型 |
| ----------------------------------- | ------------------ | ------------------------------------------------------------ | -------- |
| @ohos.app.ability.appManager.d.ts   | appManager         | function getProcessRunningInformation(): Promise\<Array\<ProcessRunningInformation\>\>; | 删除     |
| @ohos.app.ability.appManager.d.ts   | appManager         | function getProcessRunningInformation(callback: AsyncCallback\<Array\<ProcessRunningInformation\>\>): void; | 删除     |
| @ohos.app.ability.appManager.d.ts   | appManager         | function getRunningProcessInformation(): Promise\<Array\<ProcessInformation\>\>; | 新增     |
| @ohos.app.ability.appManager.d.ts   | appManager         | function getRunningProcessInformation(callback: AsyncCallback\<Array\<ProcessInformation\>\>): void; | 新增     |
| application/ApplicationContext.d.ts | ApplicationContext | getProcessRunningInformation(): Promise\<Array\<ProcessRunningInformation\>\>; | 删除     |
| application/ApplicationContext.d.ts | ApplicationContext | getProcessRunningInformation(callback: AsyncCallback\<Array\<ProcessRunningInformation\>\>): void; | 删除     |
| application/ApplicationContext.d.ts | ApplicationContext | getRunningProcessInformation(): Promise\<Array\<ProcessInformation\>\>; | 新增     |
| application/ApplicationContext.d.ts | ApplicationContext | getRunningProcessInformation(callback: AsyncCallback\<Array\<ProcessInformation\>\>): void; | 新增     |

**适配指导**

应用中调用getProcessRunningInformation可参考下列代码

变更前代码：

```ts
let context: common.UIAbilityContext = globalThis.abilityContext;
let appContext = context.getApplicationContext();
appContext.getProcessRunningInformation()
```

变更后代码：

```ts
let context: common.UIAbilityContext = globalThis.abilityContext;
let appContext = context.getApplicationContext();
appContext.getRunningProcessInformation()
```



## cl.ability.4 WantConstant.Flags接口变更
WantConstant.Flags接口有多个无效Flag定义，删除掉无效的Flag。

**变更影响**

影响API9版本的JS接口，应用需要进行适配才可以在新版本SDK环境正常实现功能。

**关键的接口/组件变更**

| 模块名                    | 类名                | 方法/属性/枚举/常量                                          | 变更类型 |
| ------------------------- | ------------------- | ------------------------------------------------------------ | -------- |
| @ohos.app.ability.wantConstant.d.ts | wantConstant.Flags  | FLAG_ABILITY_FORWARD_RESULT | 删除     |
| @ohos.app.ability.wantConstant.d.ts | wantConstant.Flags  | FLAG_ABILITY_CONTINUATION | 删除     |
| @ohos.app.ability.wantConstant.d.ts | wantConstant.Flags  | FLAG_NOT_OHOS_COMPONENT | 删除     |
| @ohos.app.ability.wantConstant.d.ts | wantConstant.Flags  | FLAG_ABILITY_FORM_ENABLED | 删除     |
| @ohos.app.ability.wantConstant.d.ts | wantConstant.Flags  | FLAG_AUTH_PERSISTABLE_URI_PERMISSION | 删除     |
| @ohos.app.ability.wantConstant.d.ts | wantConstant.Flags  | FLAG_AUTH_PREFIX_URI_PERMISSION | 删除     |
| @ohos.app.ability.wantConstant.d.ts | wantConstant.Flags  | FLAG_ABILITYSLICE_MULTI_DEVICE | 删除     |
| @ohos.app.ability.wantConstant.d.ts | wantConstant.Flags  | FLAG_START_FOREGROUND_ABILITY | 删除     |
| @ohos.app.ability.wantConstant.d.ts | wantConstant.Flags  | FLAG_ABILITY_CONTINUATION_REVERSIBLE | 删除     |
| @ohos.app.ability.wantConstant.d.ts | wantConstant.Flags  | FLAG_INSTALL_WITH_BACKGROUND_MODE | 删除     |
| @ohos.app.ability.wantConstant.d.ts | wantConstant.Flags  | FLAG_ABILITY_CLEAR_MISSION | 删除     |
| @ohos.app.ability.wantConstant.d.ts | wantConstant.Flags  | FLAG_ABILITY_NEW_MISSION | 删除     |
| @ohos.app.ability.wantConstant.d.ts | wantConstant.Flags  | FLAG_ABILITY_MISSION_TOP | 删除     |



## cl.ability.5 WantConstant.Action接口变更
WantConstant.Action接口有多个无效Action定义，删除掉无效的Action。

**变更影响**

影响API9版本的JS接口，应用需要进行适配才可以在新版本SDK环境正常实现功能。

**关键的接口/组件变更**

| 模块名                    | 类名                | 方法/属性/枚举/常量                                          | 变更类型 |
| ------------------------- | ------------------- | ------------------------------------------------------------ | -------- |
| @ohos.app.ability.wantConstant.d.ts | wantConstant.Action  | ACTION_APP_ACCOUNT_AUTH | 删除     |
| @ohos.app.ability.wantConstant.d.ts | wantConstant.Action  | ACTION_MARKET_DOWNLOAD | 删除     |
| @ohos.app.ability.wantConstant.d.ts | wantConstant.Action  | ACTION_MARKET_CROWDTEST | 删除     |
| @ohos.app.ability.wantConstant.d.ts | wantConstant.Action  | DLP_PARAMS_SANDBOX | 删除     |
| @ohos.app.ability.wantConstant.d.ts | wantConstant.Action  | DLP_PARAMS_BUNDLE_NAME | 删除     |
| @ohos.app.ability.wantConstant.d.ts | wantConstant.Action  | DLP_PARAMS_MODULE_NAME | 删除     |
| @ohos.app.ability.wantConstant.d.ts | wantConstant.Action  | DLP_PARAMS_ABILITY_NAME | 删除     |



## cl.ability.6 Caller相关接口变更
Caller相关接口使用RPC废弃的Sequenceable和MessageParcel对象，使用RPC在API9提供的Parcelable和MessageSequence对象替代。

**变更影响**

影响API9版本的JS接口，应用需要进行适配才可以在新版本SDK环境正常实现功能。

**关键的接口/组件变更**

| 模块名                    | 类名                | 方法/属性/枚举/常量                                          | 变更类型 |
| ------------------------- | ------------------- | ------------------------------------------------------------ | -------- |
| api/@ohos.app.ability.UIAbility.d.ts | CalleeCallback | (indata: rpc.MessageParcel): rpc.Sequenceable; | 变更，修改为 (indata: rpc.MessageSequence): rpc.Parcelable;     |
| api/@ohos.app.ability.UIAbility.d.ts | Caller | call(method: string, data: rpc.Sequenceable): Promise<void>; | 变更，修改为 call(method: string, data: rpc.Parcelable): Promise<void>;     |
| api/@ohos.app.ability.UIAbility.d.ts | Caller | callWithResult(method: string, data: rpc.Sequenceable): Promise<rpc.MessageParcel>; | 变更，修改为 callWithResult(method: string, data: rpc.Parcelable): Promise<rpc.MessageSequence>;     |

**适配指导**

应用中调用Caller相关接口可参考下列代码

变更前代码：

```ts
  class MyMessageAble{
      name:""
      str:""
      num: 1
      constructor(name, str) {
        this.name = name;
        this.str = str;
      }
      marshalling(messageParcel) {
          messageParcel.writeInt(this.num);
          messageParcel.writeString(this.str);
          console.log('MyMessageAble marshalling num[' + this.num + '] str[' + this.str + ']');
          return true;
      }
      unmarshalling(messageParcel) {
          this.num = messageParcel.readInt();
          this.str = messageParcel.readString();
          console.log('MyMessageAble unmarshalling num[' + this.num + '] str[' + this.str + ']');
          return true;
      }
  };
  let method = 'call_Function';
  function funcCallBack(pdata) {
      console.log('Callee funcCallBack is called ' + pdata);
      let msg = new MyMessageAble("test", "");
      pdata.readSequenceable(msg);
      return new MyMessageAble("test1", "Callee test");
  }
  export default class MainUIAbility extends UIAbility {
    onCreate(want, launchParam) {
      console.log('Callee onCreate is called');
      try {
        this.callee.on(method, funcCallBack);
      } catch (error) {
        console.log('Callee.on catch error, error.code: ' + error.code +
          ' error.message: ' + error.message);
      }
    }
  }
```

变更后代码：

```ts
  class MyMessageAble{
      name:""
      str:""
      num: 1
      constructor(name, str) {
        this.name = name;
        this.str = str;
      }
      marshalling(messageSequence) {
          messageSequence.writeInt(this.num);
          messageSequence.writeString(this.str);
          console.log('MyMessageAble marshalling num[' + this.num + '] str[' + this.str + ']');
          return true;
      }
      unmarshalling(messageSequence) {
          this.num = messageSequence.readInt();
          this.str = messageSequence.readString();
          console.log('MyMessageAble unmarshalling num[' + this.num + '] str[' + this.str + ']');
          return true;
      }
  };
  let method = 'call_Function';
  function funcCallBack(pdata) {
      console.log('Callee funcCallBack is called ' + pdata);
      let msg = new MyMessageAble("test", "");
      pdata.readParcelable(msg);
      return new MyMessageAble("test1", "Callee test");
  }
  export default class MainUIAbility extends UIAbility {
    onCreate(want, launchParam) {
      console.log('Callee onCreate is called');
      try {
        this.callee.on(method, funcCallBack);
      } catch (error) {
        console.log('Callee.on catch error, error.code: ' + error.code +
          ' error.message: ' + error.message);
      }
    }
  }
```



## cl.ability.7 WantConstant.Flags接口变更

wantConstant接口有两个类似的枚举，合并成一个。

**变更影响**

影响API9版本的JS接口，应用需要进行适配才可以在新版本SDK环境正常实现功能。

**关键的接口/组件变更**

| 模块名                              | 类名                   | 方法/属性/枚举/常量                 | 变更类型 |
| ----------------------------------- | ---------------------- | ----------------------------------- | -------- |
| @ohos.app.ability.wantConstant.d.ts | wantConstant.Parameter | ABILITY_BACK_TO_OTHER_MISSION_STACK | 删除     |
| @ohos.app.ability.wantConstant.d.ts | wantConstant.Params    | ABILITY_BACK_TO_OTHER_MISSION_STACK | 新增     |

**适配指导**

使用@ohos.app.ability.wantConstant.d.ts中的ABILITY_BACK_TO_OTHER_MISSION_STACK

```ts
import wantConstant from '@ohos.app.ability.wantConstant';
let backToOtherMissionStack: wantConstant.Params = wantParam.Params.ABILITY_BACK_TO_OTHER_MISSION_STACK;
```