# Ability Framework Changelog

## cl.ability.1 AreaMode APIs Changed

Duplicate **AreaMode** APIs are deleted.

**Change Impact**

JS APIs in API version 9 are affected. Your application needs to adapt these APIs so that it can properly implement features in the SDK environment of the new version.

**Key API/Component Changes**

| Module                   | Class               | Method/Attribute/Enum/Constant                                         | Change Type|
| ------------------------- | ------------------- | ------------------------------------------------------------ | -------- |
| @ohos.app.ability.common.d.ts | common.AreaMode |  | Deleted    |
| application/Context.d.ts | AreaMode |  | Deleted    |


**Adaptation Guide**

Use **AreaMode** in **@ohos.app.ability.contextConstant.d.ts**.

```ts
import contextConstant from '@ohos.app.ability.contextConstant';
let area: contextConstant.AreaMode = contextConstant.AreaMode.EL1;
```

## cl.ability.2 killProcessesBySelf Renamed

The **killProcessesBySelf** API is renamed **killAllProcesses**.

**Change Impact**

JS APIs in API version 9 are affected. Your application needs to adapt these APIs so that it can properly implement features in the SDK environment of the new version.

**Key API/Component Changes**

| Module                        | Class              | Method/Attribute/Enum/Constant                                  | Change Type|
| ------------------------------ | ------------------ | ----------------------------------------------------- | -------- |
| application/ApplicationContext | ApplicationContext | killProcessesBySelf(): Promise\<void\>;               | Deleted    |
| application/ApplicationContext | ApplicationContext | killProcessesBySelf(callback: AsyncCallback\<void\>); | Deleted    |
| application/ApplicationContext | ApplicationContext | killAllProcesses(): Promise\<void\>;                  | Added    |
| application/ApplicationContext | ApplicationContext | killAllProcesses(callback: AsyncCallback\<void\>);    | Added    |


**Adaptation Guide**

The following code snippet shows how to call **killProcessesBySelf** in an application.

Code before the change:

```ts
let context: common.UIAbilityContext = globalThis.abilityContext;
let appContext = context.getApplicationContext();
appContext.killProcessesBySelf()
```

Code after the change:

```ts
let context: common.UIAbilityContext = globalThis.abilityContext;
let appContext = context.getApplicationContext();
appContext.killAllProcesses()
```

## cl.ability.3 getProcessRunningInformation Renamed

The **getProcessRunningInformation** API is renamed **getRunningProcessInformation**.

**Change Impact**

JS APIs in API version 9 are affected. Your application needs to adapt these APIs so that it can properly implement features in the SDK environment of the new version.

**Key API/Component Changes**

| Module                             | Class              | Method/Attribute/Enum/Constant                                         | Change Type|
| ----------------------------------- | ------------------ | ------------------------------------------------------------ | -------- |
| @ohos.app.ability.appManager.d.ts   | appManager         | function getProcessRunningInformation(): Promise\<Array\<ProcessRunningInformation\>\>; | Deleted    |
| @ohos.app.ability.appManager.d.ts   | appManager         | function getProcessRunningInformation(callback: AsyncCallback\<Array\<ProcessRunningInformation\>\>): void; | Deleted    |
| @ohos.app.ability.appManager.d.ts   | appManager         | function getRunningProcessInformation(): Promise\<Array\<ProcessInformation\>\>; | Added    |
| @ohos.app.ability.appManager.d.ts   | appManager         | function getRunningProcessInformation(callback: AsyncCallback\<Array\<ProcessInformation\>\>): void; | Added    |
| application/ApplicationContext.d.ts | ApplicationContext | getProcessRunningInformation(): Promise\<Array\<ProcessRunningInformation\>\>; | Deleted    |
| application/ApplicationContext.d.ts | ApplicationContext | getProcessRunningInformation(callback: AsyncCallback\<Array\<ProcessRunningInformation\>\>): void; | Deleted    |
| application/ApplicationContext.d.ts | ApplicationContext | getRunningProcessInformation(): Promise\<Array\<ProcessInformation\>\>; | Added    |
| application/ApplicationContext.d.ts | ApplicationContext | getRunningProcessInformation(callback: AsyncCallback\<Array\<ProcessInformation\>\>): void; | Added    |

**Adaptation Guide**

The following code snippet shows how to call **getProcessRunningInformation** in an application.

Code before the change:

```ts
let context: common.UIAbilityContext = globalThis.abilityContext;
let appContext = context.getApplicationContext();
appContext.getProcessRunningInformation()
```

Code after the change:

```ts
let context: common.UIAbilityContext = globalThis.abilityContext;
let appContext = context.getApplicationContext();
appContext.getRunningProcessInformation()
```

## cl.ability.4 WantConstant.Flags API Changed

**WantConstant.Flags** has multiple invalid flag definitions. These invalid flags are deleted.

**Change Impact**

JS APIs in API version 9 are affected. Your application needs to adapt these APIs so that it can properly implement features in the SDK environment of the new version.

**Key API/Component Changes**

| Module                   | Class               | Method/Attribute/Enum/Constant                                         | Change Type|
| ------------------------- | ------------------- | ------------------------------------------------------------ | -------- |
| @ohos.app.ability.wantConstant.d.ts | wantConstant.Flags  | FLAG_ABILITY_FORWARD_RESULT | Deleted    |
| @ohos.app.ability.wantConstant.d.ts | wantConstant.Flags  | FLAG_ABILITY_CONTINUATION | Deleted    |
| @ohos.app.ability.wantConstant.d.ts | wantConstant.Flags  | FLAG_NOT_OHOS_COMPONENT | Deleted    |
| @ohos.app.ability.wantConstant.d.ts | wantConstant.Flags  | FLAG_ABILITY_FORM_ENABLED | Deleted    |
| @ohos.app.ability.wantConstant.d.ts | wantConstant.Flags  | FLAG_AUTH_PERSISTABLE_URI_PERMISSION | Deleted    |
| @ohos.app.ability.wantConstant.d.ts | wantConstant.Flags  | FLAG_AUTH_PREFIX_URI_PERMISSION | Deleted    |
| @ohos.app.ability.wantConstant.d.ts | wantConstant.Flags  | FLAG_ABILITYSLICE_MULTI_DEVICE | Deleted    |
| @ohos.app.ability.wantConstant.d.ts | wantConstant.Flags  | FLAG_START_FOREGROUND_ABILITY | Deleted    |
| @ohos.app.ability.wantConstant.d.ts | wantConstant.Flags  | FLAG_ABILITY_CONTINUATION_REVERSIBLE | Deleted    |
| @ohos.app.ability.wantConstant.d.ts | wantConstant.Flags  | FLAG_INSTALL_WITH_BACKGROUND_MODE | Deleted    |
| @ohos.app.ability.wantConstant.d.ts | wantConstant.Flags  | FLAG_ABILITY_CLEAR_MISSION | Deleted    |
| @ohos.app.ability.wantConstant.d.ts | wantConstant.Flags  | FLAG_ABILITY_NEW_MISSION | Deleted    |
| @ohos.app.ability.wantConstant.d.ts | wantConstant.Flags  | FLAG_ABILITY_MISSION_TOP | Deleted    |

## cl.ability.5 WantConstant.Action API Changed

**WantConstant.Action** has multiple invalid action definitions. These invalid actions are deleted.

**Change Impact**

JS APIs in API version 9 are affected. Your application needs to adapt these APIs so that it can properly implement features in the SDK environment of the new version.

**Key API/Component Changes**

| Module                   | Class               | Method/Attribute/Enum/Constant                                         | Change Type|
| ------------------------- | ------------------- | ------------------------------------------------------------ | -------- |
| @ohos.app.ability.wantConstant.d.ts | wantConstant.Action  | ACTION_APP_ACCOUNT_AUTH | Deleted    |
| @ohos.app.ability.wantConstant.d.ts | wantConstant.Action  | ACTION_MARKET_DOWNLOAD | Deleted    |
| @ohos.app.ability.wantConstant.d.ts | wantConstant.Action  | ACTION_MARKET_CROWDTEST | Deleted    |
| @ohos.app.ability.wantConstant.d.ts | wantConstant.Action  | DLP_PARAMS_SANDBOX | Deleted    |
| @ohos.app.ability.wantConstant.d.ts | wantConstant.Action  | DLP_PARAMS_BUNDLE_NAME | Deleted    |
| @ohos.app.ability.wantConstant.d.ts | wantConstant.Action  | DLP_PARAMS_MODULE_NAME | Deleted    |
| @ohos.app.ability.wantConstant.d.ts | wantConstant.Action  | DLP_PARAMS_ABILITY_NAME | Deleted    |

## cl.ability.6 Caller APIs Changed

Caller APIs use the **Parcelable** and **MessageSequence** objects provided by RPC in API version 9 to replace the deprecated **Sequenceable** and **MessageParcel** object.

**Change Impact**

JS APIs in API version 9 are affected. Your application needs to adapt these APIs so that it can properly implement features in the SDK environment of the new version.

**Key API/Component Changes**

| Module                   | Class               | Method/Attribute/Enum/Constant                                         | Change Type|
| ------------------------- | ------------------- | ------------------------------------------------------------ | -------- |
| api/@ohos.app.ability.UIAbility.d.ts | CalleeCallback | (indata: rpc.MessageParcel): rpc.Sequenceable; | Changed to **(indata: rpc.MessageSequence): rpc.Parcelable;**.    |
| api/@ohos.app.ability.UIAbility.d.ts | Caller | call(method: string, data: rpc.Sequenceable): Promise<void>; | Changed to **call(method: string, data: rpc.Parcelable): Promise<void>;**.    |
| api/@ohos.app.ability.UIAbility.d.ts | Caller | callWithResult(method: string, data: rpc.Sequenceable): Promise<rpc.MessageParcel>; | Changed to **callWithResult(method: string, data: rpc.Parcelable): Promise<rpc.MessageSequence>;**.    |

**Adaptation Guide**

The following illustrates how to call the caller APIs in your application.

Code before the change:

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

Code after the change:

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

## cl.ability.7 WantConstant.Flags API Changed

The **wantConstant** API had two similar enums. Now the two enums are combined into one.

**Change Impact**

JS APIs in API version 9 are affected. Your application needs to adapt these APIs so that it can properly implement features in the SDK environment of the new version.

**Key API/Component Changes**

| Module                             | Class                  | Method/Attribute/Enum/Constant                | Change Type|
| ----------------------------------- | ---------------------- | ----------------------------------- | -------- |
| @ohos.app.ability.wantConstant.d.ts | wantConstant.Parameter | ABILITY_BACK_TO_OTHER_MISSION_STACK | Deleted    |
| @ohos.app.ability.wantConstant.d.ts | wantConstant.Params    | ABILITY_BACK_TO_OTHER_MISSION_STACK | Added    |

**Adaptation Guide**

Use **ABILITY_BACK_TO_OTHER_MISSION_STACK** in **@ohos.app.ability.wantConstant.d.ts**.

```ts
import wantConstant from '@ohos.app.ability.wantConstant';
let backToOtherMissionStack: wantConstant.Params = wantParam.Params.ABILITY_BACK_TO_OTHER_MISSION_STACK;
```
