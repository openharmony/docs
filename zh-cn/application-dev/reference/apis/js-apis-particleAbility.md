# particleAbility模块

## 使用限制

particleAbility模块用来对Data和Service类型的Ability进行操作。

## 导入模块

```js
import particleAbility from '@ohos.ability.particleAbility'
```

## particleAbility.startAbility

startAbility(parameter: StartAbilityParameter, callback: AsyncCallback\<void>: void

使用此方法启动指定的particleAbility（callback形式）。

**参数：**


| 名称      | 类型                                            | 必填 | 描述              |
| --------- | ----------------------------------------------- | ---- | ----------------- |
| parameter | [StartAbilityParameter](#startabilityparameter) | 是   | 指示启动的ability |
| callback  | AsyncCallback\<void>                            | 是   | 被指定的回调方法  |

**示例：**

```js
import particleAbility from '@ohos.ability.particleAbility'
particleAbility.startAbility(
	{
        want:
        {
            action: "action.system.home",
            entities: ["entity.system.home"],
            type: "MIMETYPE",
            flags: FLAG_AUTH_READ_URI_PERMISSION;
            deviceId: "",
            bundleName: "com.example.Data",
            abilityName: "com.example.Data.MainAbility",
            uri:""
        },
    },
    (error, result) => {
		console.log('particleAbility startAbility errCode:' + error + 'result:' + result)
    },
)
```



## particleAbility.startAbility

startAbility(parameter: StartAbilityParameter): Promise\<number>
使用此方法启动指定的particleAbility（Promise形式）。

**参数：**


| 名称      | 类型                                            | 必填 | 描述              |
| --------- | ----------------------------------------------- | ---- | ----------------- |
| parameter | [StartAbilityParameter](#startabilityparameter) | 是   | 指示启动的ability |
**返回值：**
| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | 使用Promise形式返回结果。 |

**示例：**

```js
import particleAbility from '@ohos.ability.particleAbility'
particleAbility.startAbility(
	{
        want:
        {
            action: "action.system.home",
            entities: ["entity.system.home"],
            type: "MIMETYPE",
            flags: FLAG_AUTH_READ_URI_PERMISSION;
            deviceId: "",
            bundleName: "com.example.Data",
            abilityName: "com.example.Data.MainAbility",
            uri:""
        },
    },
).then((void) => {
    console.info("particleAbility startAbility");
});
```



## particleAbility.terminateSelf

terminateSelf(callback: AsyncCallback\<void>): void

终止particleAbility（callback形式）。

**参数：**

| 名称     | 类型                 | 必填 | 描述                 |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void> | 是   | 表示被指定的回调方法 |

**示例：**

```js
import particleAbility from '@ohos.ability.particleAbility'
particleAbility.terminateSelf(
    (error, result) => {
		console.log('particleAbility terminateSelf errCode:' + error + 'result:' + result)
    }
)
```



## particleAbility.terminateSelf

terminateSelf(): Promise\<void>

终止particleAbility（Promise形式）。

**返回值：**
| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | 使用Promise形式返回结果。 |

**示例：**

```js
import particleAbility from '@ohos.ability.particleAbility'
particleAbility.terminateSelf().then((void) => {
	console.info("particleAbility terminateSelf");
});
```



## particleAbility.acquireDataAbilityHelper

acquireDataAbilityHelper(uri: string): DataAbilityHelper

获取dataAbilityHelper。

**参数：**

| 名称 | 类型   | 必填 | 描述                     |
| :--- | ------ | ---- | ------------------------ |
| uri  | string | 是   | 指示要打开的文件的路径。 |

**返回值：**

| 类型              | 说明                                         |
| ----------------- | -------------------------------------------- |
| DataAbilityHelper | 用来协助其他Ability访问DataAbility的工具类。 |

**示例：**

```js
import particleAbility from '@ohos.ability.particleAbility'     
var uri = "";
particleAbility.acquireDataAbilityHelper(uri)
```

## particleAbility.connectAbility

connectAbility(request: Want, options:ConnectOptions): number

将当前ability连接到指定ServiceAbility（callback形式）。

**参数：**

| 名称    | 类型           | 必填 | 描述                       |
| ------- | -------------- | ---- | -------------------------- |
| request | [Want](#want)           | 是   | 表示被连接的ServiceAbility |
| options | ConnectOptions | 是   | 被指定的回调方法           |

**ConnectOptions类型说明：**

| 名称         | 读写属性 | 类型     | 必填 | 描述                               |
| ------------ | -------- | -------- | ---- | ---------------------------------- |
| onConnect    | 只读     | function | 是   | 连接成功时的回调函数               |
| onDisconnect | 只读     | function | 是   | 断开连接时的回调函数               |
| onFailed     | 只读     | function | 是   | ConnectAbility调用失败时的回调函数 |

**返回值：**
| 类型   | 说明                       |
| ------ | -------------------------- |
| number | 标识客户端与服务端的连接。 |

**示例：**

```javascript
import particleAbility from '@ohos.ability.particleAbility'
function onConnectCallback(element, remote){
    console.log('ConnectAbility onConnect remote is proxy:' + (remote instanceof rpc.RemoteProxy));
}
function onDisconnectCallback(element){
    console.log('ConnectAbility onDisconnect element.deviceId : ' + element.deviceId)
}
function onFailedCallback(code){
    console.log('particleAbilityTest ConnectAbility onFailed errCode : ' + code)
}
var connId = particleAbility.connectAbility(
    {
        bundleName: "com.ix.ServiceAbility",
        abilityName: "com.ix.ServiceAbility.ServiceAbilityA",
    },
    {
        onConnect: onConnectCallback,
        onDisconnect: onDisconnectCallback,
        onFailed: onFailedCallback,
    },
);
```

## particleAbility.disconnectAbility

disconnectAbility(connection: number, callback:AsyncCallback\<void>): void

断开与指定ServiceAbility的连接（callback形式）。

**参数：**

| 名称       | 类型          | 必填 | 描述                           |
| ---------- | ------------- | ---- | ------------------------------ |
| connection | number        | 是   | 指定断开连接的ServiceAbilityID |
| callback   | AsyncCallback\<void> | 是   | 被指定的回调方法               |

**示例：**

```javascript
import particleAbility from '@ohos.ability.particleAbility'
function onConnectCallback(element, remote){
    console.log('ConnectAbility onConnect remote is proxy:' + (remote instanceof rpc.RemoteProxy));
}
function onDisconnectCallback(element){
    console.log('ConnectAbility onDisconnect element.deviceId : ' + element.deviceId)
}
function onFailedCallback(code){
    console.log('particleAbilityTest ConnectAbility onFailed errCode : ' + code)
}
var connId = particleAbility.connectAbility(
    {
        bundleName: "com.ix.ServiceAbility",
        abilityName: "com.ix.ServiceAbility.ServiceAbilityA",
    },
    {
        onConnect: onConnectCallback,
        onDisconnect: onDisconnectCallback,
        onFailed: onFailedCallback,
    },
);
var result = particleAbility.disconnectAbility(connId,
    (error,data) => {
        console.log('particleAbilityTest DisConnectAbility result errCode : ' + error.code + " data: " + data)
    },
);
```

## particleAbility.disconnectAbility

disconnectAbility(connection: number): Promise\<void>

断开与指定ServiceAbility的连接（Promise形式）。

**参数：**

| 名称       | 类型   | 必填 | 描述                           |
| ---------- | ------ | ---- | ------------------------------ |
| connection | number | 是   | 指定断开连接的ServiceAbilityID |

**返回值：**
| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | 使用Promise形式返回结果。 |

**示例：**

```javascript
import particleAbility from '@ohos.ability.particleAbility'
function onConnectCallback(element, remote){
    console.log('ConnectAbility onConnect remote is proxy:' + (remote instanceof rpc.RemoteProxy));
}
function onDisconnectCallback(element){
    console.log('ConnectAbility onDisconnect element.deviceId : ' + element.deviceId)
}
function onFailedCallback(code){
    console.log('particleAbilityTest ConnectAbility onFailed errCode : ' + code)
}
var connId = particleAbility.connectAbility(
    {
        bundleName: "com.ix.ServiceAbility",
        abilityName: "com.ix.ServiceAbility.ServiceAbilityA",
    },
    {
        onConnect: onConnectCallback,
        onDisconnect: onDisconnectCallback,
        onFailed: onFailedCallback,
    },
);
var result = particleAbility.disconnectAbility(connId).then((void) => {
	console.info("particleAbilityTest disconnectAbility");
});
```

## StartAbilityParameter

| 名称                | 读写属性 | 类型                  | 必填 | 描述                                                         |
| ------------------- | -------- | --------------------- | ---- | ------------------------------------------------------------ |
| want                | 只读     | [Want](#want) | 是   | 表示需要包含有关目标启动能力的信息。                         |
| abilityStartSetting | 只读     | {[key: string]: any}  | 否   | 表示能力的特殊属性，当开发者启动能力时，该属性可以作为调用中的输入参数传递。 |

## Want

| 名称        | 读写属性 | 类型                 | 必填 | 描述                                                         |
| ----------- | -------- | -------------------- | ---- | ------------------------------------------------------------ |
| deviceId    | 只读     | string               | 否   | 表示运行指定Ability的设备ID。                                |
| bundleName  | 只读     | string               | 否   | 表示包描述。如果在Want中同时指定了BundleName和AbilityName，则Want可以直接匹配到指定的Ability。 |
| abilityName | 只读     | string               | 否   | 表示待启动的Ability名称。如果在Want中同时指定了BundleName和AbilityName，则Want可以直接匹配到指定的Ability。 |
| uri         | 只读     | string               | 否   | 表示Uri描述。如果在Want中指定了Uri，则Want将匹配指定的Uri信息，包括scheme, schemeSpecificPart, authority和path信息。 |
| type        | 只读     | string               | 否   | 表示MIME type类型描述，比如："text/plain" 、 "image/*"等。   |
| flags       | 只读     | number               | 否   | 表示处理Want的方式。默认传数字，具体参考：[flags说明](#flags说明)。 |
| action      | 只读     | string               | 否   | 表示action选项描述。                                         |
| parameters  | 只读     | {[key: string]: any} | 否   | 表示WantParams描述。                                         |
| entities    | 只读     | Array\<string>       | 否   | 表示entities相关描述。                                       |

## flags说明

| 名称                                 | 参数       | 描述                                                         |
| ------------------------------------ | ---------- | ------------------------------------------------------------ |
| FLAG_AUTH_READ_URI_PERMISSION        | 0x00000001 | 指示对URI执行读取操作的授权                                  |
| FLAG_AUTH_WRITE_URI_PERMISSION       | 0x00000002 | 指示对URI执行写入操作的授权                                  |
| FLAG_ABILITY_FORWARD_RESULT          | 0x00000004 | 将结果返回给元能力                                           |
| FLAG_ABILITY_CONTINUATION            | 0x00000008 | 确定是否可以将本地设备上的功能迁移到远程设备                 |
| FLAG_NOT_OHOS_COMPONENT              | 0x00000010 | 指定组件是否属于OHOS                                         |
| FLAG_ABILITY_FORM_ENABLED            | 0x00000020 | 指定是否启动某个能力                                         |
| FLAG_AUTH_PERSISTABLE_URI_PERMISSION | 0x00000040 | 指示URI上可能持久化的授权                                    |
| FLAG_AUTH_PREFIX_URI_PERMISSION      | 0x00000080 | 按照前缀匹配的方式验证URI权限                                         |
| FLAG_ABILITYSLICE_MULTI_DEVICE       | 0x00000100 | 支持分布式调度系统中的多设备启动                             |
| FLAG_START_FOREGROUND_ABILITY        | 0x00000200 | 指示无论主机应用程序是否已启动，都将启动使用服务模板的功能   |
| FLAG_ABILITY_CONTINUATION_REVERSIBLE | 0x00000400 | 表示迁移是可拉回的。                                         |
| FLAG_INSTALL_ON_DEMAND               | 0x00000800 | 如果未安装指定的功能，请安装该功能                           |
| FLAG_INSTALL_WITH_BACKGROUND_MODE    | 0x80000000 | 如果未安装，使用后台模式安装该功能。                 |
| FLAG_ABILITY_CLEAR_MISSION           | 0x00008000 | 指示清除其他任务的操作。可以为传递给{@link ohos.app.Context#startAbility}的{@code Want}设置此标志，并且必须与{@link flag_ABILITY_NEW_MISSION}一起使用 |
| FLAG_ABILITY_NEW_MISSION             | 0x10000000 | 指示在历史任务堆栈上创建任务的操作。                         |
| FLAG_ABILITY_MISSION_TOP             | 0x20000000 | 指示如果启动能力的现有实例已位于任务堆栈的顶部，则将重用该实例。否则，将创建一个新的能力实例。 |

## AbilityStartSetting

abilityStartSetting属性是一个定义为[key: string]: any的对象，key对应设定类型为：AbilityStartSetting枚举类型，value对应设定类型为：AbilityWindowConfiguration枚举类型。

使用时通过featureAbility.AbilityStartSetting获取，示例：featureAbility.AbilityStartSetting.BOUNDS_KEY。 

| 名称            | 参数            | 描述                       |
| --------------- | --------------- | -------------------------- |
| BOUNDS_KEY      | "abilityBounds" | 窗口显示大小属性的名称。   |
| WINDOW_MODE_KEY | "windowMode"    | 窗口显示模式属性的名称。   |
| DISPLAY_ID_KEY  | "displayId"     | 窗口显示设备ID属性的名称。 |

## AbilityWindowConfiguration

使用时通过featureAbility.AbilityWindowConfiguration获取，示例：featureAbility.AbilityWindowConfiguration.WINDOW_MODE_UNDEFINED。 

| 名称                        | 参数 | 描述       |
| --------------------------- | ---- | ---------- |
| WINDOW_MODE_UNDEFINED       | 0    | 未定义。   |
| WINDOW_MODE_FULLSCREEN      | 1    | 全屏。     |
| WINDOW_MODE_SPLIT_PRIMARY   | 100  | 分屏主屏。 |
| WINDOW_MODE_SPLIT_SECONDARY | 101  | 分屏次屏。 |
| WINDOW_MODE_FLOATING        | 102  | 悬浮窗。   |