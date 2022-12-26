# @ohos.ability.featureAbility (FeatureAbility模块)

FeatureAbility模块提供与用户进行交互的Ability的能力，包括启动新的Ability、停止Ability、获取dataAbilityHelper对象、获取当前Ability对应的窗口，连接断连Service等。

> **说明：**
> 
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  
> 本模块接口仅可在FA模型下使用。

## 使用限制

FeatureAbility模块的接口只能在Page类型的Ability中调用

## 导入模块

```ts
import featureAbility from '@ohos.ability.featureAbility';
```

## featureAbility.startAbility

startAbility(parameter: StartAbilityParameter, callback: AsyncCallback\<number>): void

启动新的Ability（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 参数名        | 类型                                       | 必填   | 说明             |
| --------- | ---------------------------------------- | ---- | -------------- |
| parameter | [StartAbilityParameter](js-apis-inner-ability-startAbilityParameter.md) | 是    | 表示被启动的Ability。 |
| callback  | AsyncCallback\<number>                   | 是    | 以callback的形式返回启动Ability的结果。      |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
import wantConstant from '@ohos.ability.wantConstant';
featureAbility.startAbility(
    {
        want:
        {
            action: "",
            entities: [""],
            type: "",
            flags: wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION,
            deviceId: "",
            bundleName: "com.example.myapplication",
            /* FA模型中abilityName由package + Ability name组成 */
            abilityName: "com.example.entry.secondAbility",
            uri: ""
        },
    },
    (err, data) => {
        console.info("startAbility err: " + JSON.stringify(err) + "data: " + JSON.stringify(data));
    }
);
```



## featureAbility.startAbility

startAbility(parameter: StartAbilityParameter): Promise\<number>

启动新的Ability（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 参数名        | 类型                                       | 必填   | 说明             |
| --------- | ---------------------------------------- | ---- | -------------- |
| parameter | [StartAbilityParameter](js-apis-inner-ability-startAbilityParameter.md) | 是    | 表示被启动的Ability。 |

**返回值：**

| 类型                                       | 说明      |
| ---------------------------------------- | ------- |
| Promise\<number> | Promise形式返回启动Ability结果。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
import wantConstant from '@ohos.ability.wantConstant';
featureAbility.startAbility(
    {
        want:
        {
            action: "action.system.home",
            entities: ["entity.system.home"],
            type: "MIMETYPE",
            flags: wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION,
            deviceId: "",
            bundleName: "com.example.myapplication",
            /* FA模型中abilityName由package + Ability name组成 */
            abilityName: "com.example.entry.secondAbility",
            uri: ""
        },
    }
).then((data) => {
    console.info("startAbility data: " + JSON.stringify(data));
});
```

## featureAbility.acquireDataAbilityHelper<sup>7+</sup>

acquireDataAbilityHelper(uri: string): DataAbilityHelper

获取dataAbilityHelper对象。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 参数名   | 类型     | 必填   | 说明           |
| ---- | ------ | ---- | ------------ |
| uri  | string | 是    | 表示要打开的文件的路径。 |

**返回值：**

| 类型                | 说明                              |
| ----------------- | ------------------------------- |
| [DataAbilityHelper](js-apis-inner-ability-dataAbilityHelper.md) | 用来协助其他Ability访问DataAbility的工具类。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var dataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
```

## featureAbility.startAbilityForResult<sup>7+</sup>

startAbilityForResult(parameter: StartAbilityParameter, callback: AsyncCallback\<AbilityResult>): void

启动一个Ability。Ability被启动后，正常情况下可通过调用[terminateSelfWithResult](#featureabilityterminateselfwithresult7)接口使之终止并且返回结果给调用者。异常情况下比如杀死Ability会返回异常信息给调用者（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 参数名        | 类型                                       | 必填   | 说明             |
| --------- | ---------------------------------------- | ---- | -------------- |
| parameter | [StartAbilityParameter](js-apis-inner-ability-startAbilityParameter.md) | 是    | 表示被启动的Ability。 |
| callback  | AsyncCallback\<[AbilityResult](js-apis-inner-ability-abilityResult.md)> | 是    | 以callback的形式返回启动Ability结果。      |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
import wantConstant from '@ohos.ability.wantConstant';
featureAbility.startAbilityForResult(
   {
        want:
        {
            action: "action.system.home",
            entities: ["entity.system.home"],
            type: "MIMETYPE",
            flags: wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION,
            deviceId: "",
            bundleName: "com.example.myapplication",
            /* FA模型中abilityName由package + Ability name组成 */
            abilityName: "com.example.entry.secondAbility",
            uri:""
        },
    },
    (err, data) => {
        console.info("startAbilityForResult err: " + JSON.stringify(err) + "data: " + JSON.stringify(data));
    }
);
```

## featureAbility.startAbilityForResult<sup>7+</sup>

startAbilityForResult(parameter: StartAbilityParameter): Promise\<AbilityResult>

启动一个Ability。Ability被启动后，正常情况下可通过调用[terminateSelfWithResult](#featureabilityterminateselfwithresult7)接口使之终止并且返回结果给调用者。异常情况下比如杀死Ability会返回异常信息给调用者（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 参数名        | 类型                                       | 必填   | 说明            |
| --------- | ---------------------------------------- | ---- | ------------- |
| parameter | [StartAbilityParameter](js-apis-inner-ability-startAbilityParameter.md) | 是    | 表示被启动的Ability |

**返回值：**

| 类型                                       | 说明      |
| ---------------------------------------- | ------- |
| Promise\<[AbilityResult](js-apis-inner-ability-abilityResult.md)> | Promise形式返回启动Ability结果。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
import wantConstant from '@ohos.ability.wantConstant';
featureAbility.startAbilityForResult(
    {
        want:
        {
            action: "action.system.home",
            entities: ["entity.system.home"],
            type: "MIMETYPE",
            flags: wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION,
            deviceId: "",
            bundleName: "com.example.myapplication",
            /* FA模型中abilityName由package + Ability name组成 */
            abilityName: "com.example.entry.secondAbility",
            uri:"",
            parameters:
            {
                mykey0: 1111,
                mykey1: [1, 2, 3],
                mykey2: "[1, 2, 3]",
                mykey3: "xxxxxxxxxxxxxxxxxxxxxx",
                mykey4: [1, 15],
                mykey5: [false, true, false],
                mykey6: ["aaaaaa", "bbbbb", "ccccccccccc"],
                mykey7: true,
            },
        },
    },
).then((data) => {
    console.info("startAbilityForResult data: " + JSON.stringify(data));
});
```

## featureAbility.terminateSelfWithResult<sup>7+</sup>

terminateSelfWithResult(parameter: AbilityResult, callback: AsyncCallback\<void>): void

停止当前的Ability。如果该Ability是通过调用[startAbilityForResult](#featureabilitystartabilityforresult7)接口被拉起的，调用terminateSelfWithResult接口时会将结果返回给调用者，如果该Ability不是通过调用[startAbilityForResult](#featureabilitystartabilityforresult7)接口被拉起的，调用terminateSelfWithResult接口时不会有结果返回给调用者（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 参数名        | 类型                              | 必填   | 说明             |
| --------- | ------------------------------- | ---- | -------------- |
| parameter | [AbilityResult](js-apis-inner-ability-abilityResult.md) | 是    | 表示停止Ability之后返回的结果。 |
| callback  | AsyncCallback\<void>            | 是    | 以callback的形式返回停止Ability结果。      |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
import wantConstant from '@ohos.ability.wantConstant';
featureAbility.terminateSelfWithResult(
    {
        resultCode: 1,
        want:
        {
            action: "action.system.home",
            entities: ["entity.system.home"],
            type: "MIMETYPE",
            flags: wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION,
            deviceId: "",
            bundleName: "com.example.myapplication",
            /* FA模型中abilityName由package + Ability name组成 */
            abilityName: "com.example.entry.secondAbility",
            uri:"",
            parameters: {
                mykey0: 2222,
                mykey1: [1, 2, 3],
                mykey2: "[1, 2, 3]",
                mykey3: "ssssssssssssssssssssssssss",
                mykey4: [1, 15],
                mykey5: [false, true, false],
                mykey6: ["qqqqq", "wwwwww", "aaaaaaaaaaaaaaaaa"],
                mykey7: true,
            }
        },
    },
    (err) => {
        console.info("err: " + JSON.stringify(err))
    }
);
```

## featureAbility.terminateSelfWithResult<sup>7+</sup>

terminateSelfWithResult(parameter: AbilityResult): Promise\<void>

停止当前的Ability。如果该Ability是通过调用[startAbilityForResult](#featureabilitystartabilityforresult7)接口被拉起的，调用terminateSelfWithResult接口时会将结果返回给调用者，如果该Ability不是通过调用[startAbilityForResult](#featureabilitystartabilityforresult7)接口被拉起的，调用terminateSelfWithResult接口时不会有结果返回给调用者（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 参数名        | 类型                              | 必填   | 说明            |
| --------- | ------------------------------- | ---- | ------------- |
| parameter | [AbilityResult](js-apis-inner-ability-abilityResult.md) | 是    | 表示停止Ability之后返回的结果 |

**返回值：**

| 类型             | 说明              |
| -------------- | --------------- |
| Promise\<void> | 以Promise形式返回停止当前Ability结果。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
import wantConstant from '@ohos.ability.wantConstant';
featureAbility.terminateSelfWithResult(
    {
        resultCode: 1,
        want:
        {
            action: "action.system.home",
            entities: ["entity.system.home"],
            type: "MIMETYPE",
            flags: wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION,
            deviceId: "",
            bundleName: "com.example.myapplication",
            /* FA模型中abilityName由package + Ability name组成 */
            abilityName: "com.example.entry.secondAbility",
            uri:"",
            parameters: {
                mykey0: 2222,
                mykey1: [1, 2, 3],
                mykey2: "[1, 2, 3]",
                mykey3: "ssssssssssssssssssssssssss",
                mykey4: [1, 15],
                mykey5: [false, true, false],
                mykey6: ["qqqqq", "wwwwww", "aaaaaaaaaaaaaaaaa"],
                mykey7: true,
            }
        },
    }
).then((data) => {
    console.info("==========================>terminateSelfWithResult=======================>");
});
```

## featureAbility.hasWindowFocus<sup>7+<sup>

hasWindowFocus(callback: AsyncCallback\<boolean>): void

检查Ability的主窗口是否具有窗口焦点（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 参数名       | 类型                      | 必填   | 说明                                       |
| -------- | ----------------------- | ---- | ---------------------------------------- |
| callback | AsyncCallback\<boolean> | 是    | 以callback的形式返回结果。<br>如果此Ability当前具有视窗焦点，则返回true；否则返回false。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
featureAbility.hasWindowFocus((err, data) => {
    console.info("hasWindowFocus err: " + JSON.stringify(err) + "data: " + JSON.stringify(data));
});
```

## featureAbility.hasWindowFocus<sup>7+<sup>

hasWindowFocus(): Promise\<boolean>

检查Ability的主窗口是否具有窗口焦点（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**返回值：**

| 类型                | 说明                                    |
| ----------------- | ------------------------------------- |
| Promise\<boolean> | Promise形式返回结果，如果此Ability当前具有视窗焦点，则返回true；否则返回false。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
featureAbility.hasWindowFocus().then((data) => {
    console.info("hasWindowFocus data: " + JSON.stringify(data));
});
```

## featureAbility.getWant

getWant(callback: AsyncCallback\<Want>): void

获取要拉起的Ability对应的Want（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 参数名       | 类型                            | 必填   | 说明        |
| -------- | ----------------------------- | ---- | --------- |
| callback | AsyncCallback\<[Want](js-apis-application-want.md)> | 是    | 以callback的形式返回want。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
featureAbility.getWant((err, data) => {
    console.info("getWant err: " + JSON.stringify(err) + "data: " + JSON.stringify(data));
});
```

## featureAbility.getWant

getWant(): Promise\<Want>

获取要拉起的Ability对应的Want（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**返回值：**

| 类型                      | 说明               |
| ----------------------- | ---------------- |
| Promise\<[Want](js-apis-application-want.md)> | 以Promise的形式返回want。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
featureAbility.getWant().then((data) => {
    console.info("getWant data: " + JSON.stringify(data));
});
```

## featureAbility.getContext

getContext(): Context

获取应用上下文。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**返回值：**

| 类型      | 说明         |
| ------- | ---------- |
| Context | 返回应用程序上下文。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext()
context.getBundleName((err, data) => {
    console.info("getBundleName err: " + JSON.stringify(err) + "data: " + JSON.stringify(data));
});
```

## featureAbility.terminateSelf<sup>7+</sup>

terminateSelf(callback: AsyncCallback\<void>): void

停止当前的Ability（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 参数名       | 类型                   | 必填   | 说明       |
| -------- | -------------------- | ---- | -------- |
| callback | AsyncCallback\<void> | 是    | 以callback的形式返回停止当前Ability结果 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
featureAbility.terminateSelf(
    (err) => {
        console.info("err: " + JSON.stringify(err))
    }
)
```

## featureAbility.terminateSelf<sup>7+</sup>

terminateSelf(): Promise\<void>

停止当前的Ability（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**返回值：**

| 类型             | 说明               |
| -------------- | ---------------- |
| Promise\<void> | 以Promise的形式返回停止当前Ability结果。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
featureAbility.terminateSelf().then((data) => {
    console.info("==========================>terminateSelf=======================>");
});
```

## featureAbility.connectAbility<sup>7+</sup>

connectAbility(request: Want, options:ConnectOptions): number

将当前Ability与指定的ServiceAbility进行连接。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 参数名      | 类型             | 必填   | 说明                    |
| ------- | -------------- | ---- | --------------------- |
| request | [Want](js-apis-application-want.md)  | 是    | 表示被连接的ServiceAbility。 |
| options | [ConnectOptions](js-apis-inner-ability-connectOptions.md) | 是    | 表示连接回调函数。             |

**返回值：**

| 类型     | 说明                   |
| ------ | -------------------- |
| number | 连接的ServiceAbility的ID。 |

**示例：**

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
var connectId = featureAbility.connectAbility(
    {
        deviceId: "",
        bundleName: "com.ix.ServiceAbility",
        abilityName: "ServiceAbilityA",
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

断开与指定ServiceAbility的连接（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 参数名         | 类型                   | 必填   | 说明                      |
| ---------- | -------------------- | ---- | ----------------------- |
| connection | number               | 是    | 表示断开连接的ServiceAbility的ID |
| callback   | AsyncCallback\<void> | 是    | 以callback的形式返回断开连接结果                |

**示例：**

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
var connectId = featureAbility.connectAbility(
    {
        bundleName: "com.ix.ServiceAbility",
        abilityName: "ServiceAbilityA",
    },
    {
        onConnect: onConnectCallback,
        onDisconnect: onDisconnectCallback,
        onFailed: onFailedCallback,
    },
);
var result = featureAbility.disconnectAbility(connectId,
    (error) => {
        console.log('featureAbilityTest DisConnectJsSameBundleName result errCode : ' + error.code)
    },
);
```

## featureAbility.disconnectAbility<sup>7+</sup>

disconnectAbility(connection: number): Promise\<void>

断开与指定ServiceAbility的连接（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 参数名         | 类型     | 必填   | 说明                      |
| ---------- | ------ | ---- | ----------------------- |
| connection | number | 是    | 表示断开连接的ServiceAbility的ID |

**返回值：**

| 类型             | 说明              |
| -------------- | --------------- |
| Promise\<void> | 以Promise形式返回断开连接结果。 |

**示例：**

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
var connectId = featureAbility.connectAbility(
    {
        bundleName: "com.ix.ServiceAbility",
        abilityName: "ServiceAbilityA",
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
    console.log('featureAbilityTest result errCode : ' + error.code);
});
```


## featureAbility.getWindow<sup>7+</sup>

getWindow(callback: AsyncCallback\<window.Window>): void

获取当前Ability对应的窗口（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 参数名     | 类型                          | 必填 | 说明                          |
| -------- | ----------------------------- | ---- | ----------------------------- |
| callback | AsyncCallback\<[window.Window](js-apis-window.md#window)> | 是   | callback形式返回当前Ability对应的窗口。 |

**示例：**

```ts
featureAbility.getWindow((err, data) => {
    console.info("getWindow err: " + JSON.stringify(err) + "data: " + typeof(data));
});
```

## featureAbility.getWindow<sup>7+</sup>

getWindow(): Promise\<window.Window>;

获取当前Ability对应的窗口（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**返回值：**

| 类型                    | 说明                          |
| ----------------------- | ----------------------------- |
| Promise\<[window.Window](js-apis-window.md#window)> | Promise形式返回当前Ability对应的窗口。 |

**示例：**

```ts
featureAbility.getWindow().then((data) => {
    console.info("getWindow data: " + typeof(data));
});
```

## AbilityWindowConfiguration

表示当前Ability对应的窗口配置项，使用时通过featureAbility.AbilityWindowConfiguration获取。

**示例：**

```
featureAbility.AbilityWindowConfiguration.WINDOW_MODE_UNDEFINED
```

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.FAModel

| 名称                                     | 值   | 说明                                       |
| ---------------------------------------- | ---- | ---------------------------------------- |
| WINDOW_MODE_UNDEFINED<sup>7+</sup>       | 0    | 未定义。 |
| WINDOW_MODE_FULLSCREEN<sup>7+</sup>      | 1    | 全屏。    |
| WINDOW_MODE_SPLIT_PRIMARY<sup>7+</sup>   | 100  | 分屏主屏。 |
| WINDOW_MODE_SPLIT_SECONDARY<sup>7+</sup> | 101  | 分屏次屏。 |
| WINDOW_MODE_FLOATING<sup>7+</sup>        | 102  | 悬浮窗。 |


## AbilityStartSetting

表示当前Ability对应的窗口属性，abilityStartSetting属性是一个定义为[key: string]: any的对象，key对应设定类型为：AbilityStartSetting枚举类型，value对应设定类型为：AbilityWindowConfiguration枚举类型。

使用时通过featureAbility.AbilityStartSetting获取。

**示例：**

```
featureAbility.AbilityStartSetting.BOUNDS_KEY
```

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.FAModel

| 名称                           | 值              | 说明                                       |
| ---------------------------- | --------------- | ---------------------------------------- |
| BOUNDS_KEY<sup>7+</sup>      | "abilityBounds" | 窗口显示大小属性的参数名。 |
| WINDOW_MODE_KEY<sup>7+</sup> | "windowMode"    | 窗口显示模式属性的参数名。|
| DISPLAY_ID_KEY<sup>7+</sup>  | "displayId"     | 窗口显示设备ID属性的参数名。 |

## ErrorCode

表示错误码。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.FAModel

| 名称                             | 值    | 说明                                       |
| ------------------------------ | ---- | ---------------------------------------- |
| NO_ERROR<sup>7+</sup>          | 0    | 没有错误。 |
| INVALID_PARAMETER<sup>7+</sup> | -1   | 无效的参数。 |
| ABILITY_NOT_FOUND<sup>7+</sup> | -2   | 找不到ABILITY。 |
| PERMISSION_DENY<sup>7+</sup>   | -3   | 权限拒绝。 |


## DataAbilityOperationType

表示数据的操作类型。DataAbility批量操作数据时可以通过该枚举值指定操作类型

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.FAModel

| 名称                       | 值    | 说明                                       |
| ------------------------ | ---- | ---------------------------------------- |
| TYPE_INSERT<sup>7+</sup> | 1    | 插入类型。 |
| TYPE_UPDATE<sup>7+</sup> | 2    | 修改类型。 |
| TYPE_DELETE<sup>7+</sup> | 3    | 删除类型。 |
| TYPE_ASSERT<sup>7+</sup> | 4    | 声明类型。 |

## flags说明

表示处理Want的方式。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityBase

| 名称                                   | 值         | 说明                                       |
| ------------------------------------ | ---------- | ---------------------------------------- |
| FLAG_AUTH_READ_URI_PERMISSION        | 0x00000001 | 表示对URI执行读取操作的授权。                         |
| FLAG_AUTH_WRITE_URI_PERMISSION       | 0x00000002 | 表示对URI执行写入操作的授权。                         |
| FLAG_ABILITY_FORWARD_RESULT          | 0x00000004 | 表示将结果返回给源Ability。                               |
| FLAG_ABILITY_CONTINUATION            | 0x00000008 | 表示是否可以将本地设备上的Ability迁移到远端设备。                  |
| FLAG_NOT_OHOS_COMPONENT              | 0x00000010 | 表示组件是否不属于OHOS。                            |
| FLAG_ABILITY_FORM_ENABLED            | 0x00000020 | 表示某个Ability是否已经启动。                              |
| FLAG_AUTH_PERSISTABLE_URI_PERMISSION | 0x00000040 | 表示URI上可能持久化的授权。<br>**系统API**: 此接口为系统接口，三方应用不支持调用。                          |
| FLAG_AUTH_PREFIX_URI_PERMISSION      | 0x00000080 | 表示按照前缀匹配的方式验证URI权限。<br>**系统API**: 此接口为系统接口，三方应用不支持调用。                        |
| FLAG_ABILITYSLICE_MULTI_DEVICE       | 0x00000100 | 表示支持分布式调度系统中的多设备启动。                        |
| FLAG_START_FOREGROUND_ABILITY        | 0x00000200 | 表示无论宿主应用是否已启动，都将使用前台模式启动Ability。<br>**系统API**: 此接口为系统接口，三方应用不支持调用。           |
| FLAG_ABILITY_CONTINUATION_REVERSIBLE | 0x00000400 | 表示迁移是否是可反向的。                               |
| FLAG_INSTALL_ON_DEMAND               | 0x00000800 | 表示如果未安装指定的Ability，将安装该Ability。                       |
| FLAG_INSTALL_WITH_BACKGROUND_MODE    | 0x80000000 | 表示如果未安装指定的Ability，将在后台安装该Ability。                       |
| FLAG_ABILITY_CLEAR_MISSION           | 0x00008000 | 表示清除其他任务的操作。可以为传递给 **[ohos.app.Context](js-apis-ability-context.md)** 中**startAbility**方法的**Want**设置此标志，并且必须与**flag_ABILITY_NEW_MISSION**一起使用。 |
| FLAG_ABILITY_NEW_MISSION             | 0x10000000 | 表示在已有的任务栈上创建任务的操作。                       |
| FLAG_ABILITY_MISSION_TOP             | 0x20000000 | 表示如果启动的Ability的现有实例已位于任务栈顶，则将重用该实例。否则，将创建一个新的Ability实例。 |

