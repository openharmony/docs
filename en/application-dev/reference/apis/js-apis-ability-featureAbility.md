# @ohos.ability.featureAbility (FeatureAbility)

The **FeatureAbility** module provides APIs that enable user interaction. You can use the APIs to start or terminate an ability, obtain a **dataAbilityHelper** object, obtain the window corresponding to the current ability, and connect to or disconnect from a ServiceAbility.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version. 
> The APIs of this module can be used only in the FA model.

## Constraints

The APIs of the **FeatureAbility** module can be called only by PageAbilities.

## Modules to Import

```ts
import featureAbility from '@ohos.ability.featureAbility';
```

## featureAbility.startAbility

startAbility(parameter: StartAbilityParameter, callback: AsyncCallback\<number>): void

Starts an ability. This API uses an asynchronous callback to return the result.

Observe the following when using this API:
 - If an application running in the background needs to call this API to start an ability, it must have the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission.
 - If **visible** of the target ability is **false**, the caller must have the **ohos.permission.START_INVISIBLE_ABILITY** permission.
 - For details about the startup rules for the components in the FA model, see [Component Startup Rules (FA Model)](../../application-models/component-startup-rules-fa.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| parameter | [StartAbilityParameter](js-apis-inner-ability-startAbilityParameter.md) | Yes   | Ability to start.|
| callback  | AsyncCallback\<number>                   | Yes   | Callback used to return the result.     |

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
import wantConstant from '@ohos.app.ability.wantConstant';
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
    (err, data) => {
        console.info('startAbility err: ' + JSON.stringify(err) + 'data: ' + JSON.stringify(data));
    }
);
```



## featureAbility.startAbility

startAbility(parameter: StartAbilityParameter): Promise\<number>

Starts an ability. This API uses a promise to return the result.

Observe the following when using this API:
 - If an application running in the background needs to call this API to start an ability, it must have the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission.
 - If **visible** of the target ability is **false**, the caller must have the **ohos.permission.START_INVISIBLE_ABILITY** permission.
 - For details about the startup rules for the components in the FA model, see [Component Startup Rules (FA Model)](../../application-models/component-startup-rules-fa.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| parameter | [StartAbilityParameter](js-apis-inner-ability-startAbilityParameter.md) | Yes   | Ability to start.|

**Return value**

| Type                                      | Description     |
| ---------------------------------------- | ------- |
| Promise\<number> | Promise used to return the result.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
import wantConstant from '@ohos.app.ability.wantConstant';
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
    console.info('startAbility data: ' + JSON.stringify(data));
});
```

## featureAbility.acquireDataAbilityHelper<sup>7+</sup>

acquireDataAbilityHelper(uri: string): DataAbilityHelper

Obtains a **dataAbilityHelper** object.

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

```ts
import featureAbility from '@ohos.ability.featureAbility';
let dataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.DataAbility'
);
```

## featureAbility.startAbilityForResult<sup>7+</sup>

startAbilityForResult(parameter: StartAbilityParameter, callback: AsyncCallback\<AbilityResult>): void

Starts an ability. This API uses an asynchronous callback to return the result when the ability is terminated. The following situations may be possible for a started ability:
 - Normally, you can call [terminateSelfWithResult](#featureabilityterminateselfwithresult7) to terminate the ability. The result is returned to the caller.
 - If an exception occurs, for example, the ability is killed, an exception message, in which **resultCode** is **-1**, is returned to the caller.
 - If different applications call this API to start an ability that uses the sington mode and then call [terminateSelfWithResult](#featureabilityterminateselfwithresult7) to terminate the ability, the normal result is returned to the last caller, and an exception message, in which **resultCode** is **-1**, is returned to others.

Observe the following when using this API:
 - If an application running in the background needs to call this API to start an ability, it must have the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission.
 - If **visible** of the target ability is **false**, the caller must have the **ohos.permission.START_INVISIBLE_ABILITY** permission.
 - For details about the startup rules for the components in the FA model, see [Component Startup Rules (FA Model)](../../application-models/component-startup-rules-fa.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| parameter | [StartAbilityParameter](js-apis-inner-ability-startAbilityParameter.md) | Yes   | Ability to start.|
| callback  | AsyncCallback\<[AbilityResult](js-apis-inner-ability-abilityResult.md)> | Yes   | Callback used to return the result.     |

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
import wantConstant from '@ohos.app.ability.wantConstant';
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
            uri:''
        },
    },
    (err, data) => {
        console.info('startAbilityForResult err: ' + JSON.stringify(err) + 'data: ' + JSON.stringify(data));
    }
);
```

## featureAbility.startAbilityForResult<sup>7+</sup>

startAbilityForResult(parameter: StartAbilityParameter): Promise\<AbilityResult>

Starts an ability. This API uses a promise to return the result when the ability is terminated. The following situations may be possible to an ability after it is started:
 - Normally, you can call [terminateSelfWithResult](#featureabilityterminateselfwithresult7) to terminate the ability. The result is returned to the caller.
 - If an exception occurs, for example, the ability is killed, an exception message, in which **resultCode** is **-1**, is returned to the caller.
 - If different applications call this API to start an ability that uses the sington mode and then call [terminateSelfWithResult](#featureabilityterminateselfwithresult7) to terminate the ability, the normal result is returned to the last caller, and an exception message, in which **resultCode** is **-1**, is returned to others.

Observe the following when using this API:
 - If an application running in the background needs to call this API to start an ability, it must have the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission.
 - If **visible** of the target ability is **false**, the caller must have the **ohos.permission.START_INVISIBLE_ABILITY** permission.
 - For details about the startup rules for the components in the FA model, see [Component Startup Rules (FA Model)](../../application-models/component-startup-rules-fa.md).

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

```ts
import featureAbility from '@ohos.ability.featureAbility';
import wantConstant from '@ohos.app.ability.wantConstant';
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
            uri:'',
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
    console.info('startAbilityForResult data: ' + JSON.stringify(data));
});
```

## featureAbility.terminateSelfWithResult<sup>7+</sup>

terminateSelfWithResult(parameter: AbilityResult, callback: AsyncCallback\<void>): void

Terminates this ability. If the ability is started by calling [startAbilityForResult](#featureabilitystartabilityforresult7), the result is returned to the caller in the form of a callback when **terminateSelfWithResult** is called. Otherwise, no result is returned to the caller when **terminateSelfWithResult** is called.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name       | Type                             | Mandatory  | Description            |
| --------- | ------------------------------- | ---- | -------------- |
| parameter | [AbilityResult](js-apis-inner-ability-abilityResult.md) | Yes   | Result returned after the ability is terminated.|
| callback  | AsyncCallback\<void>            | Yes   | Callback used to return the result.     |

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
import wantConstant from '@ohos.app.ability.wantConstant';
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
    },
    (err) => {
        console.error('err: ' + JSON.stringify(err));
    }
);
```

## featureAbility.terminateSelfWithResult<sup>7+</sup>

terminateSelfWithResult(parameter: AbilityResult): Promise\<void>

Terminates this ability. If the ability is started by calling [startAbilityForResult](#featureabilitystartabilityforresult7), the result is returned to the caller in the form of a promise when **terminateSelfWithResult** is called. Otherwise, no result is returned to the caller when **terminateSelfWithResult** is called.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name       | Type                             | Mandatory  | Description           |
| --------- | ------------------------------- | ---- | ------------- |
| parameter | [AbilityResult](js-apis-inner-ability-abilityResult.md) | Yes   | Result returned after the ability is terminated.|

**Return value**

| Type            | Description             |
| -------------- | --------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
import wantConstant from '@ohos.app.ability.wantConstant';
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
).then((data) => {
    console.info('==========================>terminateSelfWithResult=======================>');
});
```

## featureAbility.hasWindowFocus<sup>7+</sup>

hasWindowFocus(callback: AsyncCallback\<boolean>): void

Checks whether the main window of this ability has the focus. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name      | Type                     | Mandatory  | Description                                      |
| -------- | ----------------------- | ---- | ---------------------------------------- |
| callback | AsyncCallback\<boolean> | Yes   | Callback used to return the result.<br>If the main window has the focus, **true** is returned. Otherwise, **false** is returned.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
featureAbility.hasWindowFocus((err, data) => {
    console.info('hasWindowFocus err: ' + JSON.stringify(err) + 'data: ' + JSON.stringify(data));
});
```

## featureAbility.hasWindowFocus<sup>7+</sup>

hasWindowFocus(): Promise\<boolean>

Checks whether the main window of this ability has the focus. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Return value**

| Type               | Description                                   |
| ----------------- | ------------------------------------- |
| Promise\<boolean> | Promise used to return the result. If the main window has the focus, **true** is returned. Otherwise, **false** is returned.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
featureAbility.hasWindowFocus().then((data) => {
    console.info('hasWindowFocus data: ' + JSON.stringify(data));
});
```

## featureAbility.getWant

getWant(callback: AsyncCallback\<Want>): void

Obtains the Want corresponding to the ability to start. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name      | Type                           | Mandatory  | Description       |
| -------- | ----------------------------- | ---- | --------- |
| callback | AsyncCallback\<[Want](js-apis-application-want.md)> | Yes   | Callback used to return the Want.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
featureAbility.getWant((err, data) => {
    console.info('getWant err: ' + JSON.stringify(err) + 'data: ' + JSON.stringify(data));
});
```

## featureAbility.getWant

getWant(): Promise\<Want>

Obtains the Want corresponding to the ability to start. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Return value**

| Type                     | Description              |
| ----------------------- | ---------------- |
| Promise\<[Want](js-apis-application-want.md)> | Promise used to return the Want.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
featureAbility.getWant().then((data) => {
    console.info('getWant data: ' + JSON.stringify(data));
});
```

## featureAbility.getContext

getContext(): Context

Obtains the application context.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Return value**

| Type     | Description        |
| ------- | ---------- |
| Context | Application context.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
let context = featureAbility.getContext();
context.getBundleName((err, data) => {
    console.info('getBundleName err: ' + JSON.stringify(err) + 'data: ' + JSON.stringify(data));
});
```

## featureAbility.terminateSelf<sup>7+</sup>

terminateSelf(callback: AsyncCallback\<void>): void

Terminates this ability. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name      | Type                  | Mandatory  | Description      |
| -------- | -------------------- | ---- | -------- |
| callback | AsyncCallback\<void> | Yes   | Callback used to return the result.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
featureAbility.terminateSelf(
    (err) => {
        console.error('err: ' + JSON.stringify(err));
    }
)
```

## featureAbility.terminateSelf<sup>7+</sup>

terminateSelf(): Promise\<void>

Terminates this ability. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Return value**

| Type            | Description              |
| -------------- | ---------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
featureAbility.terminateSelf().then((data) => {
    console.info('==========================>terminateSelf=======================>');
});
```

## featureAbility.connectAbility<sup>7+</sup>

connectAbility(request: Want, options:ConnectOptions): number

Connects this ability to a ServiceAbility.

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

```ts
import rpc from '@ohos.rpc';
import featureAbility from '@ohos.ability.featureAbility';
function onConnectCallback(element, remote){
    console.log('ConnectAbility onConnect remote is proxy:' + (remote instanceof rpc.RemoteProxy));
}
function onDisconnectCallback(element){
    console.log('ConnectAbility onDisconnect element.deviceId : ' + element.deviceId)
}
function onFailedCallback(code){
    console.log('featureAbilityTest ConnectAbility onFailed errCode : ' + code)
}
let connectId = featureAbility.connectAbility(
    {
        deviceId: '',
        bundleName: 'com.ix.ServiceAbility',
        abilityName: 'com.ix.ServiceAbility.ServiceAbilityA',
    },
    {
        onConnect: onConnectCallback,
        onDisconnect: onDisconnectCallback,
        onFailed: onFailedCallback,
    },
);
```

## featureAbility.disconnectAbility<sup>7+</sup>

disconnectAbility(connection: number, callback:AsyncCallback\<void>): void

Disconnects this ability from a specific ServiceAbility. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name        | Type                  | Mandatory  | Description                     |
| ---------- | -------------------- | ---- | ----------------------- |
| connection | number               | Yes   | ID of the ServiceAbility to disconnect.|
| callback   | AsyncCallback\<void> | Yes   | Callback used to return the result.               |

**Example**

```ts
import rpc from '@ohos.rpc';
import featureAbility from '@ohos.ability.featureAbility';
function onConnectCallback(element, remote){
    console.log('ConnectAbility onConnect remote is proxy:' + (remote instanceof rpc.RemoteProxy));
}
function onDisconnectCallback(element){
    console.log('ConnectAbility onDisconnect element.deviceId : ' + element.deviceId);
}
function onFailedCallback(code){
    console.log('featureAbilityTest ConnectAbility onFailed errCode : ' + code);
}
let connectId = featureAbility.connectAbility(
    {
        bundleName: 'com.ix.ServiceAbility',
        abilityName: 'com.ix.ServiceAbility.ServiceAbilityA',
    },
    {
        onConnect: onConnectCallback,
        onDisconnect: onDisconnectCallback,
        onFailed: onFailedCallback,
    },
);

featureAbility.disconnectAbility(connectId, (err) => {
    console.error('featureAbilityTest disconnectAbility err====>'
    + ('json err=') + JSON.stringify(err));
});
```

## featureAbility.disconnectAbility<sup>7+</sup>

disconnectAbility(connection: number): Promise\<void>

Disconnects this ability from a specific ServiceAbility. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name        | Type    | Mandatory  | Description                     |
| ---------- | ------ | ---- | ----------------------- |
| connection | number | Yes   | ID of the ServiceAbility to disconnect.|

**Return value**

| Type            | Description             |
| -------------- | --------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```ts
import rpc from '@ohos.rpc';
import featureAbility from '@ohos.ability.featureAbility';
function onConnectCallback(element, remote){
    console.log('ConnectAbility onConnect remote is proxy:' + (remote instanceof rpc.RemoteProxy));
}
function onDisconnectCallback(element){
    console.log('ConnectAbility onDisconnect element.deviceId : ' + element.deviceId);
}
function onFailedCallback(code){
    console.log('featureAbilityTest ConnectAbility onFailed errCode : ' + code);
}
let connectId = featureAbility.connectAbility(
    {
        bundleName: 'com.ix.ServiceAbility',
        abilityName: 'com.ix.ServiceAbility.ServiceAbilityA',
    },
    {
        onConnect: onConnectCallback,
        onDisconnect: onDisconnectCallback,
        onFailed: onFailedCallback,
    },
);

featureAbility.disconnectAbility(connectId).then((data) => {
    console.log('data : '  + data);
}).catch((error)=>{
    console.error('featureAbilityTest result errCode : ' + error.code);
});
```


## featureAbility.getWindow<sup>7+</sup>

getWindow(callback: AsyncCallback\<window.Window>): void

Obtains the window corresponding to this ability. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name    | Type                         | Mandatory| Description                         |
| -------- | ----------------------------- | ---- | ----------------------------- |
| callback | AsyncCallback\<[window.Window](js-apis-window.md#window)> | Yes  | Callback used to return the window.|

**Example**

```ts
featureAbility.getWindow((err, data) => {
    console.info('getWindow err: ' + JSON.stringify(err) + 'data: ' + typeof(data));
});
```

## featureAbility.getWindow<sup>7+</sup>

getWindow(): Promise\<window.Window>;

Obtains the window corresponding to this ability. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Return value**

| Type                   | Description                         |
| ----------------------- | ----------------------------- |
| Promise\<[window.Window](js-apis-window.md#window)> | Promise used to return the window.|

**Example**

```ts
featureAbility.getWindow().then((data) => {
    console.info('getWindow data: ' + typeof(data));
});
```

## AbilityWindowConfiguration

Defines the window configuration corresponding to this ability. The configuration is obtained through **featureAbility.AbilityWindowConfiguration**.

**Example**

```
featureAbility.AbilityWindowConfiguration.WINDOW_MODE_UNDEFINED
```

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

| Name                                    | Value  | Description                                      |
| ---------------------------------------- | ---- | ---------------------------------------- |
| WINDOW_MODE_UNDEFINED<sup>7+</sup>       | 0    | The PageAbility is in an undefined window display mode.|
| WINDOW_MODE_FULLSCREEN<sup>7+</sup>      | 1    | The PageAbility is in full screen mode.   |
| WINDOW_MODE_SPLIT_PRIMARY<sup>7+</sup>   | 100  | The left screen in horizontal direction or the upper screen in vertical direction is the primary window.|
| WINDOW_MODE_SPLIT_SECONDARY<sup>7+</sup> | 101  | The right screen in horizontal direction or the lower screen in vertical direction is the secondary window.|
| WINDOW_MODE_FLOATING<sup>7+</sup>        | 102  | The PageAbility is displayed in floating window mode.|


## AbilityStartSetting

Defines the window attribute corresponding to this ability. The **abilityStartSetting** attribute is an object defined in the format of [**key: string]: any**, where **key** is an enumerated value of **AbilityStartSetting** and **value** is an enumerated value of **AbilityWindowConfiguration**.

The value is obtained through **featureAbility.AbilityStartSetting**.

**Example**

```
featureAbility.AbilityStartSetting.BOUNDS_KEY
```

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

| Name                          | Value             | Description                                      |
| ---------------------------- | --------------- | ---------------------------------------- |
| BOUNDS_KEY<sup>7+</sup>      | 'abilityBounds' | Ability window size.|
| WINDOW_MODE_KEY<sup>7+</sup> | 'windowMode'    | Ability window display mode.|
| DISPLAY_ID_KEY<sup>7+</sup>  | 'displayId'     | Display device ID.|

## ErrorCode

Enumerates the error codes.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

| Name                            | Value   | Description                                      |
| ------------------------------ | ---- | ---------------------------------------- |
| NO_ERROR<sup>7+</sup>          | 0    | No error occurs.|
| INVALID_PARAMETER<sup>7+</sup> | -1   | Invalid parameter.|
| ABILITY_NOT_FOUND<sup>7+</sup> | -2   | The ability is not found.|
| PERMISSION_DENY<sup>7+</sup>   | -3   | Permission denied.|


## DataAbilityOperationType

Enumerates the operation types of a DataAbility. The DataAbility can use an enumerated value to specify the operation type when operating data in batches.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

| Name                      | Value   | Description                                      |
| ------------------------ | ---- | ---------------------------------------- |
| TYPE_INSERT<sup>7+</sup> | 1    | Insert operation.|
| TYPE_UPDATE<sup>7+</sup> | 2    | Update operation.|
| TYPE_DELETE<sup>7+</sup> | 3    | Deletion operation.|
| TYPE_ASSERT<sup>7+</sup> | 4    | Assert operation.|

## flags

Enumerates the flags that specify how the Want will be handled.

**System capability**: SystemCapability.Ability.AbilityBase

| Name                                  | Value        | Description                                      |
| ------------------------------------ | ---------- | ---------------------------------------- |
| FLAG_AUTH_READ_URI_PERMISSION        | 0x00000001 | Grants the permission to read the URI.                        |
| FLAG_AUTH_WRITE_URI_PERMISSION       | 0x00000002 | Grants the permission to write data to the URI.                        |
| FLAG_ABILITY_FORWARD_RESULT          | 0x00000004 | Returns the result to the ability.                              |
| FLAG_ABILITY_CONTINUATION            | 0x00000008 | Continues the ability on a remote device.                 |
| FLAG_NOT_OHOS_COMPONENT              | 0x00000010 | Indicates that a component does not belong to OHOS.                           |
| FLAG_ABILITY_FORM_ENABLED            | 0x00000020 | Indicates whether the FormAbility is enabled.                             |
| FLAG_AUTH_PERSISTABLE_URI_PERMISSION | 0x00000040 | Grants the permission to make the URI persistent.<br>**System API**: This is a system API and cannot be called by third-party applications.                         |
| FLAG_AUTH_PREFIX_URI_PERMISSION      | 0x00000080 | Grants the permission to verify URIs by prefix matching.<br>**System API**: This is a system API and cannot be called by third-party applications.                       |
| FLAG_ABILITYSLICE_MULTI_DEVICE       | 0x00000100 | Indicates the support for cross-device startup in the distributed scheduler.                       |
| FLAG_START_FOREGROUND_ABILITY        | 0x00000200 | Indicates that the ability is started in the foreground regardless of whether the host application is started.<br>**System API**: This is a system API and cannot be called by third-party applications.          |
| FLAG_ABILITY_CONTINUATION_REVERSIBLE | 0x00000400 | Indicates that the migration is reversible.                              |
| FLAG_INSTALL_ON_DEMAND               | 0x00000800 | Indicates that the specific ability will be installed if it has not been installed.                      |
| FLAG_INSTALL_WITH_BACKGROUND_MODE    | 0x80000000 | Indicates that the specific ability will be installed in the background if it has not been installed.                      |
| FLAG_ABILITY_CLEAR_MISSION           | 0x00008000 | Clears other operation missions. This flag can be set for the [Want](js-apis-application-want.md) object under [parameter](js-apis-inner-ability-startAbilityParameter.md) in the [startAbility](#featureabilitystartability) API passed to the **FeatureAbility** module and must be used together with **flag_ABILITY_NEW_MISSION**.|
| FLAG_ABILITY_NEW_MISSION             | 0x10000000 | Creates a mission on an existing mission stack.                      |
| FLAG_ABILITY_MISSION_TOP             | 0x20000000 | Reuses an ability instance if it is on the top of an existing mission stack; creates an ability instance otherwise.|
