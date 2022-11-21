# FeatureAbility模块(JS端SDK接口)

FeatureAbility模块提供带有UI设计与用户交互的能力，包括启动新的ability、获取dataAbilityHelper、设置此Page Ability、获取当前Ability对应的窗口，连接服务等。

> **说明：**
> 
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  
> 本模块接口仅可在FA模型下使用。

## 使用限制

FeatureAbility模块的接口只能在Page类型的Ability调用

## 导入模块

```
import featureAbility from '@ohos.ability.featureAbility'
```

## featureAbility.startAbility

startAbility(parameter: StartAbilityParameter, callback: AsyncCallback\<number>): void

启动新的ability（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 名称        | 类型                                       | 必填   | 描述             |
| --------- | ---------------------------------------- | ---- | -------------- |
| parameter | [StartAbilityParameter](#startabilityparameter) | 是    | 表示被启动的Ability。 |
| callback  | AsyncCallback\<number>                   | 是    | 被指定的回调方法。      |

**示例：**

```javascript
import featureAbility from '@ohos.ability.featureAbility'
import wantConstant from '@ohos.ability.wantConstant'
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
        console.info("err: " + JSON.stringify(err) + "data: " + JSON.stringify(data))
    }
);
```



## featureAbility.startAbility

startAbility(parameter: StartAbilityParameter): Promise\<number>

启动新的ability（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 名称        | 类型                                       | 必填   | 描述             |
| --------- | ---------------------------------------- | ---- | -------------- |
| parameter | [StartAbilityParameter](#startabilityparameter) | 是    | 表示被启动的Ability。 |

**示例：**

```javascript
import featureAbility from '@ohos.ability.featureAbility'
import wantConstant from '@ohos.ability.wantConstant'
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
	console.info("==========================>startAbility=======================>");
});
```

## featureAbility.acquireDataAbilityHelper<sup>7+</sup>

acquireDataAbilityHelper(uri: string): DataAbilityHelper

获取dataAbilityHelper。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 名称   | 类型     | 必填   | 描述           |
| ---- | ------ | ---- | ------------ |
| uri  | string | 是    | 指示要打开的文件的路径。 |

**返回值：**

| 类型                | 说明                              |
| ----------------- | ------------------------------- |
| DataAbilityHelper | 用来协助其他Ability访问DataAbility的工具类。 |

**示例：**

```javascript
import featureAbility from '@ohos.ability.featureAbility'
featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
)
```

## featureAbility.startAbilityForResult<sup>7+</sup>

startAbilityForResult(parameter: StartAbilityParameter, callback: AsyncCallback\<AbilityResult>): void

启动一个ability，并在该ability被销毁时返回执行结果（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 名称        | 类型                                       | 必填   | 描述             |
| --------- | ---------------------------------------- | ---- | -------------- |
| parameter | [StartAbilityParameter](#startabilityparameter) | 是    | 表示被启动的Ability。 |
| callback  | AsyncCallback\<[AbilityResult](#abilityresult)> | 是    | 被指定的回调方法。      |

**示例：**

```javascript
import featureAbility from '@ohos.ability.featureAbility';
import wantConstant from '@ohos.ability.wantConstant'
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
        console.info("err: " + JSON.stringify(err) + "data: " + JSON.stringify(data))
    }
)
```

## featureAbility.startAbilityForResult<sup>7+</sup>

startAbilityForResult(parameter: StartAbilityParameter): Promise\<AbilityResult>

启动一个ability，并在该ability被销毁时返回执行结果（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 名称        | 类型                                       | 必填   | 描述            |
| --------- | ---------------------------------------- | ---- | ------------- |
| parameter | [StartAbilityParameter](#startabilityparameter) | 是    | 表示被启动的Ability |

**返回值：**

| 类型                                       | 说明      |
| ---------------------------------------- | ------- |
| Promise\<[AbilityResult](#abilityresult)> | 返回执行结果。 |

**示例：**

```javascript
import featureAbility from '@ohos.ability.featureAbility';
import wantConstant from '@ohos.ability.wantConstant'
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
    console.info("==========================>startAbilityForResult=======================>");
});
```

## featureAbility.terminateSelfWithResult<sup>7+</sup>

terminateSelfWithResult(parameter: AbilityResult, callback: AsyncCallback\<void>): void

设置此Page Ability将返回给调用者的结果代码和数据并破坏此Page Ability（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 名称        | 类型                              | 必填   | 描述             |
| --------- | ------------------------------- | ---- | -------------- |
| parameter | [AbilityResult](#abilityresult) | 是    | 表示被启动的Ability。 |
| callback  | AsyncCallback\<void>            | 是    | 被指定的回调方法。      |

**示例：**

```javascript
import featureAbility from '@ohos.ability.featureAbility'
import wantConstant from '@ohos.ability.wantConstant'
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

设置此Page Ability将返回给调用者的结果代码和数据并破坏此Page Ability（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 名称        | 类型                              | 必填   | 描述            |
| --------- | ------------------------------- | ---- | ------------- |
| parameter | [AbilityResult](#abilityresult) | 是    | 表示被启动的Ability |

**返回值：**

| 类型             | 说明              |
| -------------- | --------------- |
| Promise\<void> | 以Promise形式返回结果。 |

**示例：**

```javascript
import featureAbility from '@ohos.ability.featureAbility';
import wantConstant from '@ohos.ability.wantConstant'
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

| 名称       | 类型                      | 必填   | 描述                                       |
| -------- | ----------------------- | ---- | ---------------------------------------- |
| callback | AsyncCallback\<boolean> | 是    | 被指定的回调方法。<br>如果此Ability当前具有视窗焦点，则返回true；否则返回false。 |

**示例：**

```javascript
import featureAbility from '@ohos.ability.featureAbility';
featureAbility.hasWindowFocus(
    (err, data) => {
        console.info("err: " + JSON.stringify(err) + "data: " + JSON.stringify(data))
    }
)
```

## featureAbility.hasWindowFocus<sup>7+<sup>

hasWindowFocus(): Promise\<boolean>

检查Ability的主窗口是否具有窗口焦点（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**返回值：**

| 类型                | 说明                                    |
| ----------------- | ------------------------------------- |
| Promise\<boolean> | 如果此Ability当前具有视窗焦点，则返回true；否则返回false。 |

**示例：**

```javascript
import featureAbility from '@ohos.ability.featureAbility';
featureAbility.hasWindowFocus().then((data) => {
    console.info("==========================>hasWindowFocus=======================>");
});
```

## featureAbility.getWant

getWant(callback: AsyncCallback\<Want>): void

获取从Ability发送的Want（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 名称       | 类型                            | 必填   | 描述        |
| -------- | ----------------------------- | ---- | --------- |
| callback | AsyncCallback\<[Want](js-apis-application-Want.md)> | 是    | 被指定的回调方法。 |

**示例：**

```javascript
import featureAbility from '@ohos.ability.featureAbility';
featureAbility.getWant(
    (err, data) => {
        console.info("err: " + JSON.stringify(err) + "data: " + JSON.stringify(data))
    }
)
```

## featureAbility.getWant

getWant(): Promise\<Want>

获取从Ability发送的Want（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**返回值：**

| 类型                      | 说明               |
| ----------------------- | ---------------- |
| Promise\<[Want](js-apis-application-Want.md)> | 以Promise的形式返回结果。 |

**示例：**

```javascript
import featureAbility from '@ohos.ability.featureAbility';
featureAbility.getWant().then((data) => {
	console.info("==========================>getWantCallBack=======================>");
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

```javascript
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext()
context.getBundleName()
```

## featureAbility.terminateSelf<sup>7+</sup>

terminateSelf(callback: AsyncCallback\<void>): void

设置Page Ability返回给被调用方的结果代码和数据，并销毁此Page Ability（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 名称       | 类型                   | 必填   | 描述       |
| -------- | -------------------- | ---- | -------- |
| callback | AsyncCallback\<void> | 是    | 被指定的回调方法 |

**示例：**

```javascript
import featureAbility from '@ohos.ability.featureAbility';
featureAbility.terminateSelf(
    (err) => {
        console.info("err: " + JSON.stringify(err))
    }
)
```

## featureAbility.terminateSelf<sup>7+</sup>

terminateSelf(): Promise\<void>

设置Page Ability返回给被调用方的结果代码和数据，并销毁此Page Ability（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**返回值：**

| 类型             | 说明               |
| -------------- | ---------------- |
| Promise\<void> | 以Promise的形式返回结果。 |

**示例：**

```javascript
import featureAbility from '@ohos.ability.featureAbility';
featureAbility.terminateSelf().then((data) => {
    console.info("==========================>terminateSelfCallBack=======================>");
});
```

## featureAbility.connectAbility<sup>7+</sup>

connectAbility(request: Want, options:ConnectOptions): number

将当前ability连接到指定ServiceAbility（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 名称      | 类型             | 必填   | 描述                    |
| ------- | -------------- | ---- | --------------------- |
| request | [Want](js-apis-application-Want.md)  | 是    | 表示被连接的ServiceAbility。 |
| options | [ConnectOptions](#connectoptions) | 是    | 被指定的回调方法。             |

## ConnectOptions

ConnectOptions类型说明

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称           | 读写属性 | 类型       | 必填   | 描述                        |
| ------------ | ---- | -------- | ---- | ------------------------- |
| onConnect<sup>7+</sup>    | 只读   | function | 是    | 连接成功时的回调函数。               |
| onDisconnect<sup>7+</sup> | 只读   | function | 是    | 连接失败时的回调函数。               |
| onFailed<sup>7+</sup>     | 只读   | function | 是    | ConnectAbility调用失败时的回调函数。 |

**返回值：**

| 类型     | 说明                   |
| ------ | -------------------- |
| number | 连接的ServiceAbilityID。 |

**示例：**

```javascript
import rpc from '@ohos.rpc'
import featureAbility from '@ohos.ability.featureAbility'
function onConnectCallback(element, remote){
    console.log('ConnectAbility onConnect remote is proxy:' + (remote instanceof rpc.RemoteProxy));
}
function onDisconnectCallback(element){
    console.log('ConnectAbility onDisconnect element.deviceId : ' + element.deviceId)
}
function onFailedCallback(code){
    console.log('featureAbilityTest ConnectAbility onFailed errCode : ' + code)
}
var connId = featureAbility.connectAbility(
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

| 名称         | 类型                   | 必填   | 描述                      |
| ---------- | -------------------- | ---- | ----------------------- |
| connection | number               | 是    | 指定断开连接的ServiceAbilityID |
| callback   | AsyncCallback\<void> | 是    | 被指定的回调方法                |

**示例：**

```javascript
import rpc from '@ohos.rpc'
import featureAbility from '@ohos.ability.featureAbility'
function onConnectCallback(element, remote){
    console.log('ConnectAbility onConnect remote is proxy:' + (remote instanceof rpc.RemoteProxy));
}
function onDisconnectCallback(element){
    console.log('ConnectAbility onDisconnect element.deviceId : ' + element.deviceId)
}
function onFailedCallback(code){
    console.log('featureAbilityTest ConnectAbility onFailed errCode : ' + code)
}
var connId = featureAbility.connectAbility(
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
var result = featureAbility.disconnectAbility(connId,
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

| 名称         | 类型     | 必填   | 描述                      |
| ---------- | ------ | ---- | ----------------------- |
| connection | number | 是    | 指定断开连接的ServiceAbilityID |

**返回值：**

| 类型             | 说明              |
| -------------- | --------------- |
| Promise\<void> | 以Promise形式返回结果。 |

**示例：**

```javascript
import rpc from '@ohos.rpc'
import featureAbility from '@ohos.ability.featureAbility'
function onConnectCallback(element, remote){
    console.log('ConnectAbility onConnect remote is proxy:' + (remote instanceof rpc.RemoteProxy));
}
function onDisconnectCallback(element){
    console.log('ConnectAbility onDisconnect element.deviceId : ' + element.deviceId)
}
function onFailedCallback(code){
    console.log('featureAbilityTest ConnectAbility onFailed errCode : ' + code)
}
var connId = featureAbility.connectAbility(
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

featureAbility.disconnectAbility(connId).then((data) => {
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

| 名称     | 类型                          | 必填 | 描述                          |
| -------- | ----------------------------- | ---- | ----------------------------- |
| callback | AsyncCallback\<window.Window> | 是   | 返回与当前Ability对应的窗口。 |

**示例：**

```javascript
featureAbility.getWindow(
    (err, data) => {
        console.info("err: " + JSON.stringify(err) + "data: " + JSON.stringify(data))
    }
)
```

## featureAbility.getWindow<sup>7+</sup>

getWindow(): Promise\<window.Window>;

获取当前Ability对应的窗口（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**返回值：**

| 类型                    | 说明                          |
| ----------------------- | ----------------------------- |
| Promise\<window.Window> | 返回与当前Ability对应的窗口。 |

**示例：**

```javascript
featureAbility.getWindow().then((data) => {
  console.info("=============getWindowPromise========== " +  JSON.stringify(data)); 
});
```

## ConnectOptions.onConnect<sup>7+</sup>

onConnect(elementName: ElementName, remote: rpc.IRemoteObject): void;

连接成功时的回调函数。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 名称          | 类型                | 必填   | 描述       |
| ----------- | ----------------- | ---- | -------- |
| elementName | ElementName       | 是    | 元素名。     |
| remote      | rpc.IRemoteObject | 是    | rpc远程对象。 |

**示例：**

```javascript
import rpc from '@ohos.rpc'
import featureAbility from '@ohos.ability.featureAbility'
function onConnectCallback(element, remote){
    console.log('ConnectAbility onConnect remote is proxy:' + (remote instanceof rpc.RemoteProxy));
}
function onDisconnectCallback(element){
    console.log('ConnectAbility onDisconnect element.deviceId : ' + element.deviceId)
}
function onFailedCallback(code){
    console.log('featureAbilityTest ConnectAbility onFailed errCode : ' + code)
}
var connId = featureAbility.connectAbility(
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

## ConnectOptions.onDisconnect<sup>7+</sup>

onDisconnect(elementName: ElementName): void;

连接失败时的回调函数。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 名称          | 类型          | 必填   | 描述   |
| ----------- | ----------- | ---- | ---- |
| elementName | ElementName | 是    | 元素名。 |

**示例：**

```javascript
import rpc from '@ohos.rpc'
import featureAbility from '@ohos.ability.featureAbility'
function onConnectCallback(element, remote){
    console.log('ConnectAbility onConnect remote is proxy:' + (remote instanceof rpc.RemoteProxy));
}
function onDisconnectCallback(element){
    console.log('ConnectAbility onDisconnect element.deviceId : ' + element.deviceId)
}
function onFailedCallback(code){
    console.log('featureAbilityTest ConnectAbility onFailed errCode : ' + code)
}
var connId = featureAbility.connectAbility(
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

## ConnectOptions.onFailed<sup>7+</sup>

onFailed(code: number): void;

ConnectAbility调用失败时的回调函数。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 名称   | 类型     | 必填   | 描述        |
| ---- | ------ | ---- | --------- |
| code | number | 是    | number类型。 |

**示例：**

```javascript
import rpc from '@ohos.rpc'
import featureAbility from '@ohos.ability.featureAbility'
function onConnectCallback(element, remote){
    console.log('ConnectAbility onConnect remote is proxy:' + (remote instanceof rpc.RemoteProxy));
}
function onDisconnectCallback(element){
    console.log('ConnectAbility onDisconnect element.deviceId : ' + element.deviceId)
}
function onFailedCallback(code){
    console.log('featureAbilityTest ConnectAbility onFailed errCode : ' + code)
}
var connId = featureAbility.connectAbility(
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





## AbilityWindowConfiguration

使用时通过featureAbility.AbilityWindowConfiguration获取。

**示例：**

```
featureAbility.AbilityWindowConfiguration.WINDOW_MODE_UNDEFINED
```

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.FAModel

| 名称                                       | 参数   | 描述                                       |
| ---------------------------------------- | ---- | ---------------------------------------- |
| WINDOW_MODE_UNDEFINED<sup>7+</sup>       | 0    | 未定义。 |
| WINDOW_MODE_FULLSCREEN<sup>7+</sup>      | 1    | 全屏。    |
| WINDOW_MODE_SPLIT_PRIMARY<sup>7+</sup>   | 100  | 分屏主屏。 |
| WINDOW_MODE_SPLIT_SECONDARY<sup>7+</sup> | 101  | 分屏次屏。 |
| WINDOW_MODE_FLOATING<sup>7+</sup>        | 102  | 悬浮窗。 |


## AbilityStartSetting

abilityStartSetting属性是一个定义为[key: string]: any的对象，key对应设定类型为：AbilityStartSetting枚举类型，value对应设定类型为：AbilityWindowConfiguration枚举类型。

使用时通过featureAbility.AbilityStartSetting获取。

**示例：**

```
featureAbility.AbilityStartSetting.BOUNDS_KEY
```

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.FAModel

| 名称                           | 参数              | 描述                                       |
| ---------------------------- | --------------- | ---------------------------------------- |
| BOUNDS_KEY<sup>7+</sup>      | "abilityBounds" | 窗口显示大小属性的名称。 |
| WINDOW_MODE_KEY<sup>7+</sup> | "windowMode"    | 窗口显示模式属性的名称。|
| DISPLAY_ID_KEY<sup>7+</sup>  | "displayId"     | 窗口显示设备ID属性的名称。 |

## ErrorCode

获取错误代码。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.FAModel

| 变量                             | 值    | 说明                                       |
| ------------------------------ | ---- | ---------------------------------------- |
| NO_ERROR<sup>7+</sup>          | 0    | 没有错误。 |
| INVALID_PARAMETER<sup>7+</sup> | -1   | 无效的参数。 |
| ABILITY_NOT_FOUND<sup>7+</sup> | -2   | 找不到能力。 |
| PERMISSION_DENY<sup>7+</sup>   | -3   | 拒绝许可。 |


## DataAbilityOperationType

指示数据的操作类型。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.FAModel

| 变量                       | 值    | 说明                                       |
| ------------------------ | ---- | ---------------------------------------- |
| TYPE_INSERT<sup>7+</sup> | 1    | 插入类型。 |
| TYPE_UPDATE<sup>7+</sup> | 2    | 修改类型。 |
| TYPE_DELETE<sup>7+</sup> | 3    | 删除类型。 |
| TYPE_ASSERT<sup>7+</sup> | 4    | 声明类型。 |



## AbilityResult

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityBase

| 名称                      | 读写属性 | 类型            | 必填   | 描述                                    |
| ----------------------- | ---- | ------------- | ---- | ------------------------------------- |
| resultCode<sup>7+</sup> | 只读   | number        | 是    | 指示销毁该能力后返回的结果代码。您可以定义结果代码来识别错误（暂不支持）。 |
| want<sup>7+</sup>       | 只读   | [Want](js-apis-application-Want.md) | 否    | 指示销毁该能力后返回的数据。您可以定义返回的数据。此参数可以为null。  |

## StartAbilityParameter

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.FAModel

| 名称                  | 读写属性 | 类型                   | 必填   | 描述                                     |
| ------------------- | ---- | -------------------- | ---- | -------------------------------------- |
| want                | 只读   | [Want](js-apis-application-Want.md)        | 是    | 表示需要包含有关目标启动能力的信息。                     |
| abilityStartSetting | 只读   | {[key: string]: any} | 否    | 表示能力的特殊属性，当开发者启动能力时，该属性可以作为调用中的输入参数传递。 |

## flags说明

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityBase

| 名称                                   | 参数         | 描述                                       |
| ------------------------------------ | ---------- | ---------------------------------------- |
| FLAG_AUTH_READ_URI_PERMISSION        | 0x00000001 | 指示对URI执行读取操作的授权。                         |
| FLAG_AUTH_WRITE_URI_PERMISSION       | 0x00000002 | 指示对URI执行写入操作的授权。                         |
| FLAG_ABILITY_FORWARD_RESULT          | 0x00000004 | 将结果返回给元能力。                               |
| FLAG_ABILITY_CONTINUATION            | 0x00000008 | 确定是否可以将本地设备上的功能迁移到远程设备。                  |
| FLAG_NOT_OHOS_COMPONENT              | 0x00000010 | 指定组件是否属于OHOS。                            |
| FLAG_ABILITY_FORM_ENABLED            | 0x00000020 | 指定是否启动某个能力。                              |
| FLAG_AUTH_PERSISTABLE_URI_PERMISSION | 0x00000040 | 指示URI上可能持久化的授权。<br>**系统API**: 此接口为系统接口，三方应用不支持调用。                          |
| FLAG_AUTH_PREFIX_URI_PERMISSION      | 0x00000080 | 按照前缀匹配的方式验证URI权限。<br>**系统API**: 此接口为系统接口，三方应用不支持调用。                        |
| FLAG_ABILITYSLICE_MULTI_DEVICE       | 0x00000100 | 支持分布式调度系统中的多设备启动。                        |
| FLAG_START_FOREGROUND_ABILITY        | 0x00000200 | 指示无论主机应用程序是否已启动，都将启动使用服务模板的功能。<br>**系统API**: 此接口为系统接口，三方应用不支持调用。           |
| FLAG_ABILITY_CONTINUATION_REVERSIBLE | 0x00000400 | 表示迁移是可拉回的。                               |
| FLAG_INSTALL_ON_DEMAND               | 0x00000800 | 如果未安装指定的功能，请安装该功能。                       |
| FLAG_INSTALL_WITH_BACKGROUND_MODE    | 0x80000000 | 如果未安装，使用后台模式安装该功能。                       |
| FLAG_ABILITY_CLEAR_MISSION           | 0x00008000 | 指示清除其他任务的操作。可以为传递给 **[ohos.app.Context](js-apis-ability-context.md)** 中**startAbility**方法的**Want**设置此标志，并且必须与**flag_ABILITY_NEW_MISSION**一起使用。 |
| FLAG_ABILITY_NEW_MISSION             | 0x10000000 | 指示在历史任务堆栈上创建任务的操作。                       |
| FLAG_ABILITY_MISSION_TOP             | 0x20000000 | 指示如果启动能力的现有实例已位于任务堆栈的顶部，则将重用该实例。否则，将创建一个新的能力实例。 |

