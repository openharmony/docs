# FeatureAbility模块(JS端SDK接口)

## 使用限制

FeatureAbility模块的接口只能在Page类型的Ability调用

## 导入模块

```
import featureAbility from '@ohos.ability.featureAbility'
```

## featureAbility.startAbility

startAbility(parameter: StartAbilityParameter, callback: AsyncCallback\<number>): void

启动新的ability（callback形式）。

**系统能力:**

SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 名称      | 类型                  | 必填 | 描述                |
| --------- | --------------------- | ---- | ------------------- |
| parameter | [StartAbilityParameter](#startabilityparameter) | 是   | 表示被启动的Ability。 |
| callback  | AsyncCallback\<number>         | 是   | 被指定的回调方法。   |

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
            bundleName: "com.example.startability",
            abilityName: "com.example.startability.MainAbility",
            uri: ""
        },
    },
);
```



## featureAbility.startAbility

startAbility(parameter: StartAbilityParameter): Promise\<number>

启动新的ability（Promise形式）。

**系统能力:**

SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 名称      | 类型                                            | 必填 | 描述                  |
| --------- | ----------------------------------------------- | ---- | --------------------- |
| parameter | [StartAbilityParameter](#startabilityparameter) | 是   | 表示被启动的Ability。 |

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
            bundleName: "com.example.startability",
            abilityName: "com.example.startability.MainAbility",
            uri: ""
        },
    }
   ).then((data) => {
	console.info("==========================>startAbility=======================>");
});
```

## featureAbility.acquireDataAbilityHelper

acquireDataAbilityHelper(uri: string): DataAbilityHelper

获取dataAbilityHelper。

**系统能力:**

SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 名称 | 类型   | 必填 | 描述                     |
| ---- | ------ | ---- | ------------------------ |
| uri  | string | 是   | 指示要打开的文件的路径。 |

**返回值：**

| 类型              | 说明                                         |
| ----------------- | -------------------------------------------- |
| DataAbilityHelper | 用来协助其他Ability访问DataAbility的工具类。 |

**示例：**

```javascript
import featureAbility from '@ohos.ability.featureAbility'
featureAbility.acquireDataAbilityHelper(
    "dataability:///com.exmaple.DataAbility"
)
```

## featureAbility.startAbilityForResult

startAbilityForResult(parameter: StartAbilityParameter, callback: AsyncCallback\<AbilityResult>): void

启动一个ability，并在该ability被销毁时返回执行结果（callback形式）。

**系统能力:**

SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 名称      | 类型                                            | 必填 | 描述                  |
| --------- | ----------------------------------------------- | ---- | --------------------- |
| parameter | [StartAbilityParameter](#startabilityparameter) | 是   | 表示被启动的Ability。 |
| callback  | AsyncCallback\<[AbilityResult](#abilityresult)> | 是   | 被指定的回调方法。    |

**示例：**

```javascript
import featureAbility from '@ohos.ability.featureability';
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
            bundleName: "com.example.featureabilitytest",
            abilityName: "com.example.featureabilitytest.MainAbility",
            uri:""
        },
    },
)
```

## featureAbility.startAbilityForResult

startAbilityForResult(parameter: StartAbilityParameter): Promise\<AbilityResult>

启动一个ability，并在该ability被销毁时返回执行结果（Promise形式）。

**系统能力:**

SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 名称      | 类型                                            | 必填 | 描述                |
| --------- | ----------------------------------------------- | ---- | ------------------- |
| parameter | [StartAbilityParameter](#startabilityparameter) | 是   | 表示被启动的Ability |

**返回值：**
| 类型                                      | 说明           |
| ----------------------------------------- | -------------- |
| Promise\<[AbilityResult](#abilityresult)> | 返回执行结果。 |

**示例：**

```javascript
import featureAbility from '@ohos.ability.featureability';
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
            bundleName: "com.example.featureabilitytest",
            abilityName: "com.example.featureabilitytest.MainAbility",
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
        requestCode: 2,
    },
).then((data) => {
    console.info("==========================>startAbilityForResult=======================>");
});
```

## featureAbility.terminateSelfWithResult

terminateSelfWithResult(parameter: AbilityResult, callback: AsyncCallback\<void>): void

设置此Page Ability将返回给调用者的结果代码和数据并破坏此Page Ability（callback形式）。

**系统能力:**

SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 名称      | 类型          | 必填 | 描述                |
| --------- | ------------- | ---- | ------------------- |
| parameter | [AbilityResult](#abilityresult) | 是   | 表示被启动的Ability。 |
| callback  | AsyncCallback\<void> | 是   | 被指定的回调方法。  |

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
            bundleName: "com.example.featureabilitytest",
            abilityName: "com.example.featureabilitytest.MainAbility",
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
);
```

## featureAbility.terminateSelfWithResult

terminateSelfWithResult(parameter: AbilityResult): Promise\<void>

设置此Page Ability将返回给调用者的结果代码和数据并破坏此Page Ability（Promise形式）。

**系统能力:**

SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 名称      | 类型                            | 必填 | 描述                |
| --------- | ------------------------------- | ---- | ------------------- |
| parameter | [AbilityResult](#abilityresult) | 是   | 表示被启动的Ability |

**返回值：**
| 类型           | 说明                    |
| -------------- | ----------------------- |
| Promise\<void> | 以Promise形式返回结果。 |

**示例：**

```javascript
import featureAbility from '@ohos.ability.featureability';
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
            bundleName: "com.example.featureabilitytest",
            abilityName: "com.example.featureabilitytest.MainAbility",
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



## featureAbility.hasWindowFocus

hasWindowFocus(callback: AsyncCallback\<boolean>): void

检查Ability的主窗口是否具有窗口焦点（callback形式）。

**系统能力:**

SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 名称     | 类型                    | 必填 | 描述                                                         |
| -------- | ----------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<boolean> | 是   | 被指定的回调方法。<br>如果此Ability当前具有视窗焦点，则返回true；否则返回false。 |

**示例：**

```javascript
import featureAbility from '@ohos.ability.featureability';
featureAbility.hasWindowFocus()
```



## featureAbility.hasWindowFocus

hasWindowFocus(): Promise\<boolean>

检查Ability的主窗口是否具有窗口焦点（Promise形式）。

**系统能力:**

SystemCapability.Ability.AbilityRuntime.FAModel

**返回值：**

| 类型              | 说明                                                       |
| ----------------- | ---------------------------------------------------------- |
| Promise\<boolean> | 如果此Ability当前具有视窗焦点，则返回true；否则返回false。 |

**示例：**

```javascript
import featureAbility from '@ohos.ability.featureability';
featureAbility.hasWindowFocus().then((data) => {
    console.info("==========================>hasWindowFocus=======================>");
});
```



## featureAbility.getWant

getWant(callback: AsyncCallback\<Want>): void

获取从Ability发送的Want（callback形式）。

**系统能力:**

SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 名称     | 类型                          | 必填 | 描述               |
| -------- | ----------------------------- | ---- | ------------------ |
| callback | AsyncCallback\<[Want](#want)> | 是   | 被指定的回调方法。 |

**示例：**

```javascript
import featureAbility from '@ohos.ability.featureability';
featureAbility.getWant()
```



## featureAbility.getWant

getWant(): Promise\<Want>

获取从Ability发送的Want（Promise形式）。

**系统能力:**

SystemCapability.Ability.AbilityRuntime.FAModel

**返回值：**
| 类型                    | 说明                      |
| ----------------------- | ------------------------- |
| Promise\<[Want](#want)> | 以Promise的形式返回结果。 |

**示例：**

```javascript
import featureAbility from '@ohos.ability.featureability';
featureAbility.getWant().then((data) => {
		console.info("==========================>getWantCallBack=======================>");
});
```

## featureAbility.getContext

getContext(): Context

获取应用上下文。

**系统能力:**

SystemCapability.Ability.AbilityRuntime.FAModel

**返回值：**
| 类型    | 说明                 |
| ------- | -------------------- |
| Context | 返回应用程序上下文。 |

**示例：**

```javascript
import featureAbility from '@ohos.ability.featureability';
var context = featureAbility.getContext()
context.getBundleName()
```



## featureAbility.terminateSelf

terminateSelf(callback: AsyncCallback\<void>): void

设置Page Ability返回给被调用方的结果代码和数据，并销毁此Page Ability（callback形式）。

**系统能力:**

SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 名称     | 类型                 | 必填 | 描述             |
| -------- | -------------------- | ---- | ---------------- |
| callback | AsyncCallback\<void> | 是   | 被指定的回调方法 |

**示例：**

```javascript
import featureAbility from '@ohos.ability.featureability';
featureAbility.terminateSelf()
```



## featureAbility.terminateSelf

terminateSelf(): Promise\<void>

设置Page Ability返回给被调用方的结果代码和数据，并销毁此Page Ability（Promise形式）。

**系统能力:**

SystemCapability.Ability.AbilityRuntime.FAModel

**返回值：**
| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | 以Promise的形式返回结果。 |

**示例：**

```javascript
import featureAbility from '@ohos.ability.featureability';
featureAbility.terminateSelf().then((data) => {		    console.info("==========================>terminateSelfCallBack=======================>");
});
```

## featureAbility.connectAbility

connectAbility(request: Want, options:ConnectOptions): number

将当前ability连接到指定ServiceAbility（callback形式）。

**系统能力:**

SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 名称    | 类型           | 必填 | 描述                         |
| ------- | -------------- | ---- | ---------------------------- |
| request | [Want](#want)           | 是   | 表示被连接的ServiceAbility。 |
| options | ConnectOptions | 是   | 被指定的回调方法。           |

**Want类型说明：**

| 名称         | 读写属性  | 类型     | 必填 | 描述                                                              |
| ------------ | -------- | -------- | ---- | ----------------------------------                               |
| deviceId     | 只读     | string   | 否   | 表示被连接的ServiceAbility的设备id，缺省表示连接本地的ServiceAbility<br><b>系统能力：</b>SystemCapability.Ability.AbilityBase |
| bundleName   | 只读     | string   | 是   | 表示被连接的ServiceAbility的包名<br><b>系统能力：</b>SystemCapability.Ability.AbilityBase                                   |
| abilityName  | 只读     | string   | 是   | 表示被连接的ServiceAbility的类名<br><b>系统能力：</b>SystemCapability.Ability.AbilityBase                                   |

**ConnectOptions类型说明：**

| 名称         | 读写属性 | 类型     | 必填 | 描述                               |
| ------------ | -------- | -------- | ---- | ---------------------------------- |
| onConnect    | 只读     | function | 是   | 连接成功时的回调函数<br><b>系统能力：</b>SystemCapability.Ability.AbilityRuntime.Core               |
| onDisconnect | 只读     | function | 是   | 连接失败时的回调函数<br><b>系统能力：</b>SystemCapability.Ability.AbilityRuntime.Core               |
| onFailed     | 只读     | function | 是   | ConnectAbility调用失败时的回调函数<br><b>系统能力：</b>SystemCapability.Ability.AbilityRuntime.Core |

**返回值：**
| 类型   | 说明                     |
| ------ | ------------------------ |
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

## featureAbility.disconnectAbility

disconnectAbility(connection: number, callback:AsyncCallback\<void>): void

断开与指定ServiceAbility的连接（callback形式）。

**系统能力:**

SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 名称       | 类型          | 必填 | 描述                           |
| ---------- | ------------- | ---- | ------------------------------ |
| connection | number        | 是   | 指定断开连接的ServiceAbilityID |
| callback   | AsyncCallback\<void> | 是   | 被指定的回调方法               |

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
    (error,data) => {
    console.log('featureAbilityTest DisConnectJsSameBundleName result errCode : ' + error.code + " data: " + data)
    },
);
```

## featureAbility.disconnectAbility

disconnectAbility(connection: number): Promise\<void>

断开与指定ServiceAbility的连接（Promise形式）。

**系统能力:**

SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 名称       | 类型   | 必填 | 描述                           |
| ---------- | ------ | ---- | ------------------------------ |
| connection | number | 是   | 指定断开连接的ServiceAbilityID |

**返回值：**
| 类型           | 说明                    |
| -------------- | ----------------------- |
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
var result = await featureAbility.disconnectAbility(connId);
```

## AbilityResult

| 名称       | 读写属性 | 类型                  | 必填 | 描述                                                         |
| ---------- | -------- | --------------------- | ---- | ------------------------------------------------------------ |
| resultCode | 只读     | number                | 是   | 指示销毁该能力后返回的结果代码。您可以定义结果代码来识别错误（暂不支持）<br><b>系统能力：</b>SystemCapability.Ability.AbilityBase |
| want       | 只读     | [Want](#want) | 否   | 指示销毁该能力后返回的数据。您可以定义返回的数据。此参数可以为null。<br><b>系统能力：</b>SystemCapability.Ability.AbilityBase  |

## StartAbilityParameter

| 名称                | 读写属性 | 类型                 | 必填 | 描述                                                         |
| ------------------- | -------- | -------------------- | ---- | ------------------------------------------------------------ |
| want                | 只读     | [Want](#want)        | 是   | 表示需要包含有关目标启动能力的信息。<br><b>系统能力：</b>SystemCapability.Ability.AbilityRuntime.FAModel                       |
| abilityStartSetting | 只读     | {[key: string]: any} | 否   | 表示能力的特殊属性，当开发者启动能力时，该属性可以作为调用中的输入参数传递。<br><b>系统能力：</b>SystemCapability.Ability.AbilityRuntime.FAModel |

## Want

| 名称        | 读写属性 | 类型                 | 必填 | 描述                                                         |
| ----------- | -------- | -------------------- | ---- | ------------------------------------------------------------ |
| deviceId    | 只读     | string               | 否   | 表示运行指定Ability的设备ID。<br><b>系统能力：</b>SystemCapability.Ability.AbilityBase                                |
| bundleName  | 只读     | string               | 否   | 表示包描述。如果在Want中同时指定了BundleName和AbilityName，则Want可以直接匹配到指定的Ability。<br><b>系统能力：</b>SystemCapability.Ability.AbilityBase |
| abilityName | 只读     | string               | 否   | 表示待启动的Ability名称。如果在Want中同时指定了BundleName和AbilityName，则Want可以直接匹配到指定的Ability。<br><b>系统能力：</b>SystemCapability.Ability.AbilityBase |
| uri         | 只读     | string               | 否   | 表示Uri描述。如果在Want中指定了Uri，则Want将匹配指定的Uri信息，包括scheme, schemeSpecificPart, authority和path信息。<br><b>系统能力：</b>SystemCapability.Ability.AbilityBase |
| type        | 只读     | string               | 否   | 表示MIME type类型描述，比如："text/plain" 、 "image/*"等。<br><b>系统能力：</b>SystemCapability.Ability.AbilityBase   |
| flags       | 只读     | number               | 否   | 表示处理Want的方式。默认传数字，具体参考：[flags说明](#flags说明)。<br><b>系统能力：</b>SystemCapability.Ability.AbilityBase |
| action      | 只读     | string               | 否   | 表示action选项描述。<br><b>系统能力：</b>SystemCapability.Ability.AbilityBase                           |
| parameters  | 只读     | {[key: string]: any} | 否   | 表示WantParams描述。<br><b>系统能力：</b>SystemCapability.Ability.AbilityBase                                       |
| entities    | 只读     | Array\<string>       | 否   | 表示entities相关描述。<br><b>系统能力：</b>SystemCapability.Ability.AbilityBase                                    |

## flags说明

| 名称                                 | 参数       | 描述                                                         |
| ------------------------------------ | ---------- | ------------------------------------------------------------ |
| FLAG_AUTH_READ_URI_PERMISSION        | 0x00000001 | 指示对URI执行读取操作的授权<br><b>系统能力：</b>SystemCapability.Ability.AbilityBase                                  |
| FLAG_AUTH_WRITE_URI_PERMISSION       | 0x00000002 | 指示对URI执行写入操作的授权<br><b>系统能力：</b>SystemCapability.Ability.AbilityBase                                  |
| FLAG_ABILITY_FORWARD_RESULT          | 0x00000004 | 将结果返回给元能力<br><b>系统能力：</b>SystemCapability.Ability.AbilityBase                                           |
| FLAG_ABILITY_CONTINUATION            | 0x00000008 | 确定是否可以将本地设备上的功能迁移到远程设备<br><b>系统能力：</b>SystemCapability.Ability.AbilityBase                 |
| FLAG_NOT_OHOS_COMPONENT              | 0x00000010 | 指定组件是否属于OHOS<br><b>系统能力：</b>SystemCapability.Ability.AbilityBase                                         |
| FLAG_ABILITY_FORM_ENABLED            | 0x00000020 | 指定是否启动某个能力<br><b>系统能力：</b>SystemCapability.Ability.AbilityBase                                         |
| FLAG_AUTH_PERSISTABLE_URI_PERMISSION | 0x00000040 | 指示URI上可能持久化的授权<br><b>系统能力：</b>SystemCapability.Ability.AbilityBase                                    |
| FLAG_AUTH_PREFIX_URI_PERMISSION      | 0x00000080 | 按照前缀匹配的方式验证URI权限<br><b>系统能力：</b>SystemCapability.Ability.AbilityBase                                           |
| FLAG_ABILITYSLICE_MULTI_DEVICE       | 0x00000100 | 支持分布式调度系统中的多设备启动<br><b>系统能力：</b>SystemCapability.Ability.AbilityBase                             |
| FLAG_START_FOREGROUND_ABILITY        | 0x00000200 | 指示无论主机应用程序是否已启动，都将启动使用服务模板的功能<br><b>系统能力：</b>SystemCapability.Ability.AbilityBase   |
| FLAG_ABILITY_CONTINUATION_REVERSIBLE | 0x00000400 | 表示迁移是可拉回的。<br><b>系统能力：</b>SystemCapability.Ability.AbilityBase                                         |
| FLAG_INSTALL_ON_DEMAND               | 0x00000800 | 如果未安装指定的功能，请安装该功能 <br><b>系统能力：</b>SystemCapability.Ability.AbilityBase                          |
| FLAG_INSTALL_WITH_BACKGROUND_MODE    | 0x80000000 | 如果未安装，使用后台模式安装该功能。<br><b>系统能力：</b>SystemCapability.Ability.AbilityBase                         |
| FLAG_ABILITY_CLEAR_MISSION           | 0x00008000 | 指示清除其他任务的操作。可以为传递给**ohos.app.Context#startAbility**的**Want**设置此标志，并且必须与**flag_ABILITY_NEW_MISSION**一起使用<br><b>系统能力：</b>SystemCapability.Ability.AbilityBase |
| FLAG_ABILITY_NEW_MISSION             | 0x10000000 | 指示在历史任务堆栈上创建任务的操作。<br><b>系统能力：</b>SystemCapability.Ability.AbilityBase                         |
| FLAG_ABILITY_MISSION_TOP             | 0x20000000 | 指示如果启动能力的现有实例已位于任务堆栈的顶部，则将重用该实例。否则，将创建一个新的能力实例。<br><b>系统能力：</b>SystemCapability.Ability.AbilityBase |

