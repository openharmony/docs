# @ohos.ability.featureAbility (FeatureAbility)

The module provides APIs that enable user interaction. You can use the APIs to start or terminate an ability, obtain a dataAbilityHelper object, obtain the window corresponding to the current ability, and connect to or disconnect from a ServiceAbility.

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the FA model.

## Constraints

The APIs of the FeatureAbility module can be called only by PageAbilities.

## Modules to Import

```ts
import { featureAbility } from '@kit.AbilityKit';
```

## featureAbility.startAbility

startAbility(parameter: StartAbilityParameter, callback: AsyncCallback\<number>): void

Starts an ability. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> For details about the startup rules for the components in the FA model, see [Component Startup Rules (FA Model)](../../application-models/component-startup-rules-fa.md).

**Model restriction**: This API can be used only in the FA model.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| parameter | [StartAbilityParameter](js-apis-inner-ability-startAbilityParameter.md) | Yes   | Ability to start.|
| callback  | AsyncCallback\<number>                   | Yes   | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is **0**; otherwise, **err** is a non-zero value.     |

**Example**

<!--code_no_check_fa-->
```ts
import { featureAbility, wantConstant } from '@kit.AbilityKit';

featureAbility.startAbility(
  {
    want:
    {
      action: '',
      entities: [''],
      type: '',
      flags: wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION,
      deviceId: '',
      bundleName: 'com.example.myapplication',
      /* In the FA model, abilityName consists of package and ability names. */
      abilityName: 'com.example.myapplication.secondAbility',
      uri: ''
    },
  },
  (error, data) => {
    if (error && error.code !== 0) {
      console.error(`startAbility fail, error: ${JSON.stringify(error)}`);
    } else {
      console.log(`startAbility success, data: ${JSON.stringify(data)}`);
    }
  }
);
```



## featureAbility.startAbility

startAbility(parameter: StartAbilityParameter): Promise\<number>

Starts an ability. This API uses a promise to return the result.

> **NOTE**
>
> For details about the startup rules for the components in the FA model, see [Component Startup Rules (FA Model)](../../application-models/component-startup-rules-fa.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Model restriction**: This API can be used only in the FA model.

**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| parameter | [StartAbilityParameter](js-apis-inner-ability-startAbilityParameter.md) | Yes   | Ability to start.|

**Return value**

| Type                                      | Description     |
| ---------------------------------------- | ------- |
| Promise\<number> | Promise used to return the result. If the operation is successful, **0** is returned; otherwise, a non-zero value is returned.|

**Example**

<!--code_no_check_fa-->
```ts
import { featureAbility, wantConstant } from '@kit.AbilityKit';

featureAbility.startAbility(
  {
    want:
    {
      action: 'ohos.want.action.home',
      entities: ['entity.system.home'],
      type: 'MIMETYPE',
      flags: wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION,
      deviceId: '',
      bundleName: 'com.example.myapplication',
      /* In the FA model, abilityName consists of package and ability names. */
      abilityName: 'com.example.myapplication.secondAbility',
      uri: ''
    },
  }
).then((data) => {
  console.info(`startAbility data: ${JSON.stringify(data)}`);
});
```

## featureAbility.acquireDataAbilityHelper<sup>7+</sup>

acquireDataAbilityHelper(uri: string): DataAbilityHelper

Obtains a dataAbilityHelper object.

> **NOTE**
>
> For details about the startup rules for the components in the FA model, see [Component Startup Rules (FA Model)](../../application-models/component-startup-rules-fa.md).
>
> To access a DataAbility of another application, the target application must be configured with associated startup (**AssociateWakeUp** set to **true**).

**Model restriction**: This API can be used only in the FA model.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name  | Type    | Mandatory  | Description          |
| ---- | ------ | ---- | ------------ |
| uri  | string | Yes   | URI of the file to open.|

**Return value**

| Type               | Description                             |
| ----------------- | ------------------------------- |
| [DataAbilityHelper](js-apis-inner-ability-dataAbilityHelper.md) | A utility class used to help other abilities access the Data ability.|

**Example**

<!--code_no_check_fa-->
```ts
import { featureAbility } from '@kit.AbilityKit';

let dataAbilityHelper = featureAbility.acquireDataAbilityHelper(
  'dataability:///com.example.DataAbility'
);
```

## featureAbility.startAbilityForResult<sup>7+</sup>

startAbilityForResult(parameter: StartAbilityParameter, callback: AsyncCallback\<AbilityResult>): void

Starts an ability. This API uses an asynchronous callback to return the result. The following situations may be possible for a started ability:
 - Normally, you can call [terminateSelfWithResult](#featureabilityterminateselfwithresult7) to terminate the ability. The result is returned to the caller.
 - If an exception occurs, for example, the ability is killed, an exception message, in which **resultCode** is **-1**, is returned to the caller.
 - If different applications call this API to start an ability that uses the singleton mode and then call [terminateSelfWithResult](#featureabilityterminateselfwithresult7) to terminate the ability, the normal result is returned to the last caller, and an exception message, in which **resultCode** is **-1**, is returned to others.

> **NOTE**
>
> For details about the startup rules for the components in the FA model, see [Component Startup Rules (FA Model)](../../application-models/component-startup-rules-fa.md).

**Model restriction**: This API can be used only in the FA model.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| parameter | [StartAbilityParameter](js-apis-inner-ability-startAbilityParameter.md) | Yes   | Ability to start.|
| callback  | AsyncCallback\<[AbilityResult](js-apis-inner-ability-abilityResult.md)> | Yes   | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is an AbilityResult object; otherwise, err is an error object.     |

**Example**

<!--code_no_check_fa-->
```ts
import { featureAbility, wantConstant } from '@kit.AbilityKit';

featureAbility.startAbilityForResult(
  {
    want:
    {
      action: 'ohos.want.action.home',
      entities: ['entity.system.home'],
      type: 'MIMETYPE',
      flags: wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION,
      deviceId: '',
      bundleName: 'com.example.myapplication',
      /* In the FA model, abilityName consists of package and ability names. */
      abilityName: 'com.example.myapplication.secondAbility',
      uri: ''
    },
  },
  (error, data) => {
    if (error && error.code !== 0) {
      console.error(`startAbilityForResult fail, error: ${JSON.stringify(error)}`);
    } else {
      console.log(`startAbilityForResult success, data: ${JSON.stringify(data)}`);
    }
  }
);
```

## featureAbility.startAbilityForResult<sup>7+</sup>

startAbilityForResult(parameter: StartAbilityParameter): Promise\<AbilityResult>

Starts an ability. This API uses a promise to return the result. The following situations may be possible for a started ability:
 - Normally, you can call [terminateSelfWithResult](#featureabilityterminateselfwithresult7) to terminate the ability. The result is returned to the caller.
 - If an exception occurs, for example, the ability is killed, an exception message, in which **resultCode** is **-1**, is returned to the caller.
 - If different applications call this API to start an ability that uses the singleton mode and then call [terminateSelfWithResult](#featureabilityterminateselfwithresult7) to terminate the ability, the normal result is returned to the last caller, and an exception message, in which **resultCode** is **-1**, is returned to others.

> **NOTE**
>
> For details about the startup rules for the components in the FA model, see [Component Startup Rules (FA Model)](../../application-models/component-startup-rules-fa.md).

**Model restriction**: This API can be used only in the FA model.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name       | Type                                      | Mandatory  | Description           |
| --------- | ---------------------------------------- | ---- | ------------- |
| parameter | [StartAbilityParameter](js-apis-inner-ability-startAbilityParameter.md) | Yes   | Ability to start.|

**Return value**

| Type                                      | Description     |
| ---------------------------------------- | ------- |
| Promise\<[AbilityResult](js-apis-inner-ability-abilityResult.md)> | Promise used to return the result.|

**Example**

<!--code_no_check_fa-->
```ts
import { featureAbility, wantConstant } from '@kit.AbilityKit';

featureAbility.startAbilityForResult(
  {
    want:
    {
      action: 'ohos.want.action.home',
      entities: ['entity.system.home'],
      type: 'MIMETYPE',
      flags: wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION,
      deviceId: '',
      bundleName: 'com.example.myapplication',
      /* In the FA model, abilityName consists of package and ability names. */
      abilityName: 'com.example.myapplication.secondAbility',
      uri: '',
      parameters:
      {
        mykey0: 1111,
        mykey1: [1, 2, 3],
        mykey2: '[1, 2, 3]',
        mykey3: 'xxxxxxxxxxxxxxxxxxxxxx',
        mykey4: [1, 15],
        mykey5: [false, true, false],
        mykey6: ['aaaaaa', 'bbbbb', 'ccccccccccc'],
        mykey7: true,
      },
    },
  },
).then((data) => {
  console.info(`startAbilityForResult data: ${JSON.stringify(data)}`);
});
```

## featureAbility.terminateSelfWithResult<sup>7+</sup>

terminateSelfWithResult(parameter: AbilityResult, callback: AsyncCallback\<void>): void

Terminates this ability. This API uses an asynchronous callback to return the result. If the ability is started by calling [startAbilityForResult](#featureabilitystartabilityforresult7), the result is returned to the caller when **terminateSelfWithResult** is called. Otherwise, no result is returned to the caller when **terminateSelfWithResult** is called.

**Model restriction**: This API can be used only in the FA model.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name       | Type                             | Mandatory  | Description            |
| --------- | ------------------------------- | ---- | -------------- |
| parameter | [AbilityResult](js-apis-inner-ability-abilityResult.md) | Yes   | Result returned after the ability is terminated.|
| callback  | AsyncCallback\<void>            | Yes   | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.     |

**Example**

<!--code_no_check_fa-->
```ts
import { featureAbility, wantConstant } from '@kit.AbilityKit';

featureAbility.terminateSelfWithResult(
  {
    resultCode: 1,
    want:
    {
      action: 'ohos.want.action.home',
      entities: ['entity.system.home'],
      type: 'MIMETYPE',
      flags: wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION,
      deviceId: '',
      bundleName: 'com.example.myapplication',
      /* In the FA model, abilityName consists of package and ability names. */
      abilityName: 'com.example.myapplication.secondAbility',
      uri: '',
      parameters: {
        mykey0: 2222,
        mykey1: [1, 2, 3],
        mykey2: '[1, 2, 3]',
        mykey3: 'ssssssssssssssssssssssssss',
        mykey4: [1, 15],
        mykey5: [false, true, false],
        mykey6: ['qqqqq', 'wwwwww', 'aaaaaaaaaaaaaaaaa'],
        mykey7: true,
      }
    },
  },
  (error) => {
    console.error(`error: ${JSON.stringify(error)}`);
  }
);
```

## featureAbility.terminateSelfWithResult<sup>7+</sup>

terminateSelfWithResult(parameter: AbilityResult): Promise\<void>

Terminates this ability. This API uses a promise to return the result. If the ability is started by calling [startAbilityForResult](#featureabilitystartabilityforresult7), the result is returned to the caller when **terminateSelfWithResult** is called. Otherwise, no result is returned to the caller when **terminateSelfWithResult** is called.

**Model restriction**: This API can be used only in the FA model.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name       | Type                             | Mandatory  | Description           |
| --------- | ------------------------------- | ---- | ------------- |
| parameter | [AbilityResult](js-apis-inner-ability-abilityResult.md) | Yes   | Result returned after the ability is terminated.|

**Return value**

| Type            | Description             |
| -------------- | --------------- |
| Promise\<void> | Promise that returns no value.|

**Example**

<!--code_no_check_fa-->
```ts
import { featureAbility, wantConstant } from '@kit.AbilityKit';

featureAbility.terminateSelfWithResult(
  {
    resultCode: 1,
    want:
    {
      action: 'ohos.want.action.home',
      entities: ['entity.system.home'],
      type: 'MIMETYPE',
      flags: wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION,
      deviceId: '',
      bundleName: 'com.example.myapplication',
      /* In the FA model, abilityName consists of package and ability names. */
      abilityName: 'com.example.myapplication.secondAbility',
      uri:'',
      parameters: {
        mykey0: 2222,
        mykey1: [1, 2, 3],
        mykey2: '[1, 2, 3]',
        mykey3: 'ssssssssssssssssssssssssss',
        mykey4: [1, 15],
        mykey5: [false, true, false],
        mykey6: ['qqqqq', 'wwwwww', 'aaaaaaaaaaaaaaaaa'],
        mykey7: true,
      }
    },
  }
).then(() => {
  console.info('==========================>terminateSelfWithResult=======================>');
});
```

## featureAbility.hasWindowFocus<sup>7+<sup>

hasWindowFocus(callback: AsyncCallback\<boolean>): void

Checks whether the main window of this ability has the focus. This API uses an asynchronous callback to return the result.

**Model restriction**: This API can be used only in the FA model.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name      | Type                     | Mandatory  | Description                                      |
| -------- | ----------------------- | ---- | ---------------------------------------- |
| callback | AsyncCallback\<boolean> | Yes   |Callback used to return the result.<br>If the main window has the focus, **true** is returned. Otherwise, **false** is returned.|

**Example**

<!--code_no_check_fa-->
```ts
import { featureAbility } from '@kit.AbilityKit';

featureAbility.hasWindowFocus((error, data) => {
  if (error && error.code !== 0) {
    console.error(`hasWindowFocus fail, error: ${JSON.stringify(error)}`);
  } else {
    console.log(`hasWindowFocus success, data: ${JSON.stringify(data)}`);
  }
});
```

## featureAbility.hasWindowFocus<sup>7+<sup>

hasWindowFocus(): Promise\<boolean>

Checks whether the main window of this ability has the focus. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the FA model.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Return value**

| Type               | Description                                   |
| ----------------- | ------------------------------------- |
| Promise\<boolean> | Promise used to return the result. If the main window has the focus, **true** is returned. Otherwise, **false** is returned.|

**Example**

<!--code_no_check_fa-->
```ts
import { featureAbility } from '@kit.AbilityKit';

featureAbility.hasWindowFocus().then((data) => {
  console.info(`hasWindowFocus data: ${JSON.stringify(data)}`);
});
```

## featureAbility.getWant

getWant(callback: AsyncCallback\<Want>): void

Obtains the Want corresponding to the ability to start. This API uses an asynchronous callback to return the result.

**Model restriction**: This API can be used only in the FA model.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name      | Type                           | Mandatory  | Description       |
| -------- | ----------------------------- | ---- | --------- |
| callback | AsyncCallback\<[Want](js-apis-application-want.md)> | Yes   | Callback used to return the Want.|

**Example**

<!--code_no_check_fa-->
```ts
import { featureAbility } from '@kit.AbilityKit';

featureAbility.getWant((error, data) => {
  if (error && error.code !== 0) {
    console.error(`getWant fail, error: ${JSON.stringify(error)}`);
  } else {
    console.log(`getWant success, data: ${JSON.stringify(data)}`);
  }
});
```

## featureAbility.getWant

getWant(): Promise\<Want>

Obtains the Want corresponding to the ability to start. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the FA model.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Return value**

| Type                     | Description              |
| ----------------------- | ---------------- |
| Promise\<[Want](js-apis-application-want.md)> | Promise used to return the Want.|

**Example**

<!--code_no_check_fa-->
```ts
import { featureAbility } from '@kit.AbilityKit';

featureAbility.getWant().then((data) => {
  console.info(`getWant data: ${JSON.stringify(data)}`);
});
```

## featureAbility.getContext

getContext(): Context

Obtains the application context.

**Model restriction**: This API can be used only in the FA model.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Return value**

| Type     | Description        |
| ------- | ---------- |
| Context | Application context.|

**Example**

<!--code_no_check_fa-->
```ts
import { featureAbility } from '@kit.AbilityKit';

let context = featureAbility.getContext();
context.getBundleName((error, data) => {
  if (error && error.code !== 0) {
    console.error(`getBundleName fail, error: ${JSON.stringify(error)}`);
  } else {
    console.log(`getBundleName success, data: ${JSON.stringify(data)}`);
  }
});
```

## featureAbility.terminateSelf<sup>7+</sup>

terminateSelf(callback: AsyncCallback\<void>): void

Terminates this ability. This API uses an asynchronous callback to return the result.

**Model restriction**: This API can be used only in the FA model.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name      | Type                  | Mandatory  | Description      |
| -------- | -------------------- | ---- | -------- |
| callback | AsyncCallback\<void> | Yes   | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

<!--code_no_check_fa-->
```ts
import { featureAbility } from '@kit.AbilityKit';

featureAbility.terminateSelf(
  (error) => {
    console.error(`error: ${JSON.stringify(error)}`);
  }
)
```

## featureAbility.terminateSelf<sup>7+</sup>

terminateSelf(): Promise\<void>

Terminates this ability. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the FA model.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Return value**

| Type            | Description              |
| -------------- | ---------------- |
| Promise\<void> | Promise that returns no value.|

**Example**

<!--code_no_check_fa-->
```ts
import { featureAbility } from '@kit.AbilityKit';

featureAbility.terminateSelf().then(() => {
  console.info('==========================>terminateSelf=======================>');
});
```

## featureAbility.connectAbility<sup>7+</sup>

connectAbility(request: Want, options:ConnectOptions): number

Connects this ability to a ServiceAbility.

> **NOTE**
>
> For details about the startup rules for the components in the FA model, see [Component Startup Rules (FA Model)](../../application-models/component-startup-rules-fa.md).
> To connect to a ServiceAbility of another application, the target application must be configured with associated startup (**AssociateWakeUp** set to **true**).

**Model restriction**: This API can be used only in the FA model.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name     | Type            | Mandatory  | Description                   |
| ------- | -------------- | ---- | --------------------- |
| request | [Want](js-apis-application-want.md)  | Yes   | ServiceAbility to connect.|
| options | [ConnectOptions](js-apis-inner-ability-connectOptions.md) | Yes   | Connection options.            |

**Return value**

| Type    | Description                  |
| ------ | -------------------- |
| number | ID of the connected ServiceAbility. The ID starts from 0 and is incremented by 1 each time a connection is set up.|

**Example**

<!--code_no_check_fa-->
```ts
import { featureAbility } from '@kit.AbilityKit';
import { rpc } from '@kit.IPCKit';

let connectId = featureAbility.connectAbility(
  {
    deviceId: '',
    bundleName: 'com.ix.ServiceAbility',
    abilityName: 'com.ix.ServiceAbility.ServiceAbilityA',
  },
  {
    onConnect: (element, remote) => {
      console.log(`ConnectAbility onConnect remote is proxy: ${(remote instanceof rpc.RemoteProxy)}`);
    },
    onDisconnect: (element) => {
      console.log(`ConnectAbility onDisconnect element.deviceId : ${element.deviceId}`);
    },
    onFailed: (code) => {
      console.error(`featureAbilityTest ConnectAbility onFailed errCode : ${code}`);
    },
  },
);
```

## featureAbility.disconnectAbility<sup>7+</sup>

disconnectAbility(connection: number, callback:AsyncCallback\<void>): void

Disconnects this ability from a specific ServiceAbility. This API uses an asynchronous callback to return the result.

**Model restriction**: This API can be used only in the FA model.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name        | Type                  | Mandatory  | Description                     |
| ---------- | -------------------- | ---- | ----------------------- |
| connection | number               | Yes   | ID of the ServiceAbility to disconnect.|
| callback   | AsyncCallback\<void> | Yes   | Callback used to return the result. If the disconnection is successful, **err** is **undefined**. Otherwise, **err** is an error object.     |

**Example**

<!--code_no_check_fa-->
```ts
import { featureAbility } from '@kit.AbilityKit';
import { rpc } from '@kit.IPCKit';

let connectId = featureAbility.connectAbility(
  {
    bundleName: 'com.ix.ServiceAbility',
    abilityName: 'com.ix.ServiceAbility.ServiceAbilityA',
  },
  {
    onConnect: (element, remote) => {
      console.log(`ConnectAbility onConnect remote is proxy: ${(remote instanceof rpc.RemoteProxy)}`);
    },
    onDisconnect: (element) => {
      console.log(`ConnectAbility onDisconnect element.deviceId : ${element.deviceId}`);
    },
    onFailed: (code) => {
      console.error(`featureAbilityTest ConnectAbility onFailed errCode : ${code}`);
    },
  },
);

featureAbility.disconnectAbility(connectId, (error) => {
  if (error && error.code !== 0) {
    console.error(`disconnectAbility fail, connectId: ${connectId}, error: ${JSON.stringify(error)}`);
  } else {
    console.log(`disconnectAbility success, connectId: ${connectId}`);
  }
});
```

## featureAbility.disconnectAbility<sup>7+</sup>

disconnectAbility(connection: number): Promise\<void>

Disconnects this ability from a specific ServiceAbility. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the FA model.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name        | Type    | Mandatory  | Description                     |
| ---------- | ------ | ---- | ----------------------- |
| connection | number | Yes   | ID of the ServiceAbility to disconnect.|

**Return value**

| Type            | Description             |
| -------------- | --------------- |
| Promise\<void> | Promise that returns no value.|

**Example**

<!--code_no_check_fa-->
```ts
import { featureAbility } from '@kit.AbilityKit';
import { rpc } from '@kit.IPCKit';
import { BusinessError } from '@kit.BasicServicesKit';

let connectId = featureAbility.connectAbility(
  {
    bundleName: 'com.ix.ServiceAbility',
    abilityName: 'com.ix.ServiceAbility.ServiceAbilityA',
  },
  {
    onConnect: (element, remote) => {
      console.log(`ConnectAbility onConnect remote is proxy: ${(remote instanceof rpc.RemoteProxy)}`);
    },
    onDisconnect: (element) => {
      console.log(`ConnectAbility onDisconnect element.deviceId : ${element.deviceId}`);
    },
    onFailed: (code) => {
      console.error(`featureAbilityTest ConnectAbility onFailed errCode : ${code}`);
    },
  },
);

featureAbility.disconnectAbility(connectId).then(() => {
  console.log('disconnectAbility success');
}).catch((error: BusinessError)=>{
  console.error(`featureAbilityTest result errCode : ${error.code}`);
});
```


## featureAbility.getWindow<sup>7+</sup>

getWindow(callback: AsyncCallback\<window.Window>): void

Obtains the window corresponding to this ability. This API uses an asynchronous callback to return the result.

**Model restriction**: This API can be used only in the FA model.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name    | Type                         | Mandatory| Description                         |
| -------- | ----------------------------- | ---- | ----------------------------- |
| callback | AsyncCallback\<[window.Window](../apis-arkui/arkts-apis-window-Window.md)> | Yes  | Callback used to return the window.|

**Example**

<!--code_no_check_fa-->
```ts
import { featureAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

featureAbility.getWindow((error: BusinessError, data: window.Window) => {
  if (error && error.code !== 0) {
    console.error(`getWindow fail, error: ${JSON.stringify(error)}`);
  } else {
    console.log(`getWindow success, data: ${typeof(data)}`);
  }
});
```

## featureAbility.getWindow<sup>7+</sup>

getWindow(): Promise\<window.Window>

Obtains the window corresponding to this ability. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the FA model.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Return value**

| Type                   | Description                         |
| ----------------------- | ----------------------------- |
| Promise\<[window.Window](../apis-arkui/arkts-apis-window-Window.md)> | Promise used to return the window.|

**Example**

<!--code_no_check_fa-->
```ts
import { featureAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

featureAbility.getWindow().then((data: window.Window) => {
  console.log(`getWindow success, data: ${typeof(data)}`);
}).catch((error: BusinessError)=>{
  console.error(`getWindow fail, error: ${JSON.stringify(error)}`);
});
```

## AbilityWindowConfiguration<sup>7+</sup>

Defines the window configuration corresponding to this ability. The configuration is obtained through **featureAbility.AbilityWindowConfiguration**.

**Model restriction**: This API can be used only in the FA model.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

| Name                                    | Value  | Description                                      |
| ---------------------------------------- | ---- | ---------------------------------------- |
| WINDOW_MODE_UNDEFINED       | 0    | The PageAbility is in an undefined window display mode.|
| WINDOW_MODE_FULLSCREEN      | 1    | The PageAbility is in full screen mode.   |
| WINDOW_MODE_SPLIT_PRIMARY   | 100  | The left screen in horizontal direction or the upper screen in vertical direction is the primary window.|
| WINDOW_MODE_SPLIT_SECONDARY | 101  | The right screen in horizontal direction or the lower screen in vertical direction is the secondary window.|
| WINDOW_MODE_FLOATING        | 102  | The PageAbility is displayed in floating window mode.|

**Example**

<!--code_no_check_fa-->
```ts
import { featureAbility } from '@kit.AbilityKit';

featureAbility.AbilityWindowConfiguration.WINDOW_MODE_UNDEFINED
```

## AbilityStartSetting<sup>7+</sup>

Defines the window property corresponding to this ability. The **abilityStartSetting** property is an object defined in the format of [**key: string]: any**, where **key** is an enumerated value of **AbilityStartSetting** and **value** is an enumerated value of **AbilityWindowConfiguration**.

The value is obtained through **featureAbility.AbilityStartSetting**.

**Model restriction**: This API can be used only in the FA model.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

| Name                          | Value             | Description                                      |
| ---------------------------- | --------------- | ---------------------------------------- |
| BOUNDS_KEY      | 'abilityBounds' | Ability window size.|
| WINDOW_MODE_KEY | 'windowMode'    | Ability window display mode.|
| DISPLAY_ID_KEY  | 'displayId'     | Display device ID.|

**Example**

<!--code_no_check_fa-->
```ts
import { featureAbility } from '@kit.AbilityKit';

featureAbility.AbilityStartSetting.BOUNDS_KEY
```

## ErrorCode<sup>7+</sup>

Enumerates the error codes that may be returned when an ability is started.

**Model restriction**: This API can be used only in the FA model.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

| Name                            | Value   | Description                                      |
| ------------------------------ | ---- | ---------------------------------------- |
| NO_ERROR         | 0    | No error.  |
| INVALID_PARAMETER | -1   | Invalid parameter.|
| ABILITY_NOT_FOUND | -2   | The ability is not found.|
| PERMISSION_DENY   | -3   | Permission denied.  |

## DataAbilityOperationType<sup>7+</sup>

Enumerates the operation types of a DataAbility. The DataAbility can use an enumerated value to specify the operation type when operating data in batches.

**Model restriction**: This API can be used only in the FA model.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

| Name                      | Value   | Description                                      |
| ------------------------ | ---- | ---------------------------------------- |
| TYPE_INSERT | 1    | Insert operation.|
| TYPE_UPDATE | 2    | Update operation.|
| TYPE_DELETE | 3    | Deletion operation.|
| TYPE_ASSERT | 4    | Assert operation.|

## Context<sup>9+</sup>

type Context = _Context

Defines the Context module.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Model restriction**: This API can be used only in the FA model.

| Type| Description|
| --- | --- |
| [_Context](js-apis-inner-app-context.md) | Context module.|

## AppVersionInfo<sup>9+</sup>

type AppVersionInfo = _AppVersionInfo

Defines an AppVersionInfo object.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Model restriction**: This API can be used only in the FA model.

| Type| Description|
| --- | --- |
| [_AppVersionInfo](js-apis-inner-app-appVersionInfo.md) | AppVersionInfo object.|

## ProcessInfo<sup>9+</sup>

type ProcessInfo = _ProcessInfo

Defines a ProcessInfo object.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Model restriction**: This API can be used only in the FA model.

| Type| Description|
| --- | --- |
| [_ProcessInfo](js-apis-inner-app-processInfo.md) | ProcessInfo object.|
