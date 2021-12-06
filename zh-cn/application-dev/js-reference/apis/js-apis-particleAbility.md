# ParticleAbility模块(JS端SDK接口)

#### 支持设备

| API                                                          | 手机 | 平板 | 智慧屏 | 智能穿戴 | 轻量级智能穿戴 | 智慧视觉设备 |
| ------------------------------------------------------------ | ---- | ---- | ------ | -------- | -------------- | ------------ |
| ParticleAbility.startAbility(parameter: StartAbilityParameter, callback: AsyncCallback\<void> | 支持 | 支持 | 支持   | 支持     | 不支持         | 不支持       |
| ParticleAbility.startAbility(parameter: StartAbilityParameter) | 支持 | 支持 | 支持   | 支持     | 不支持         | 不支持       |
| ParticleAbility.terminateSelf(callback: AsyncCallback\<void>) | 支持 | 支持 | 支持   | 支持     | 不支持         | 不支持       |
| ParticleAbility.terminateSelf()                              | 支持 | 支持 | 支持   | 支持     | 不支持         | 不支持       |
| ParticleAbility.acquireDataAbilityHelper(uri: string)        | 支持 | 支持 | 支持   | 支持     | 不支持         | 不支持       |

#### 权限列表

ohos.permission.RUNNING_LOCK permission

#### 使用限制

ParticleAbility模块的接口只能在Ability为Data和Service类型的时候进行调用

#### 导入模块

```
import featureAbility from '@ohos.ability.featureAbility'
```

#### ParticleAbility.startAbility(parameter: StartAbilityParameter, callback: AsyncCallback\<void>

- 接口说明

  服务ability使用此方法启动特定ability(callback形式)

- startAbility参数描述


| 名称      | 读写属性 | 类型                  | 必填 | 描述              |
| --------- | -------- | --------------------- | ---- | ----------------- |
| parameter | 只读     | StartAbilityParameter | 是   | 指示启动的ability |
| callback  | 只读     | AsyncCallback\<void>  | 是   | 被指定的回调方法  |

- StartAbilityParameter类型说明

| 名称                | 读写属性 | 类型   | 必填 | 描述                               |
| ------------------- | -------- | ------ | ---- | ---------------------------------- |
| want                | 只读     | want   | 是   | 表示需要包含有关目标启动能力的信息 |
| abilityStartSetting | 只读     | string | 否   | 指示启动能力中使用的特殊启动设置   |

- want类型说明

| 名称        | 读写属性 | 类型   | 必填 | 描述                       |
| ----------- | -------- | ------ | ---- | -------------------------- |
| deviceId    | 只读     | string | 否   | 设备id                     |
| bundleName  | 只读     | string | 否   | 捆绑包名称                 |
| abilityName | 只读     | string | 否   | ability 名字               |
| uri         | 只读     | string | 否   | 请求中URI的描述            |
| type        | 只读     | string | 否   | 此文件中类型的说明         |
| flags       | 只读     | number | 否   | 此文件中标志的选项是必需的 |
| action      | 只读     | string | 否   | 需求中对操作的描述         |
| parameters  | 只读     | string | 否   | Want中WantParams对象的描述 |
| entities    | 只读     | string | 否   | 对象中实体的描述           |

- flags类型说明

  | 名称                                 | 参数       | 描述                                                         |
  | ------------------------------------ | ---------- | ------------------------------------------------------------ |
  | FLAG_AUTH_READ_URI_PERMISSION        | 0x00000001 | 指示对URI执行读取操作的授权                                  |
  | FLAG_AUTH_WRITE_URI_PERMISSION       | 0x00000002 | 指示对URI执行写入操作的授权                                  |
  | FLAG_ABILITY_FORWARD_RESULT          | 0x00000004 | 将结果返回给源异能                                           |
  | FLAG_ABILITY_CONTINUATION            | 0x00000008 | 确定是否可以将本地设备上的功能迁移到远程设备                 |
  | FLAG_NOT_OHOS_COMPONENT              | 0x00000010 | 指定组件是否不属于OHOS                                       |
  | FLAG_ABILITY_FORM_ENABLED            | 0x00000020 | 指定是否启动某个能力                                         |
  | FLAG_AUTH_PERSISTABLE_URI_PERMISSION | 0x00000040 | 指示URI上可能持久化的授权                                    |
  | FLAG_AUTH_PREFIX_URI_PERMISSION      | 0x00000080 | 将结果返回到源能力片                                         |
  | FLAG_ABILITYSLICE_MULTI_DEVICE       | 0x00000100 | 支持分布式调度系统中的多设备启动                             |
  | FLAG_START_FOREGROUND_ABILITY        | 0x00000200 | 指示无论主机应用程序是否已启动，都将启动使用服务模板的功能   |
  | FLAG_ABILITY_CONTINUATION_REVERSIBLE | 0x00000400 | 表示延续是可逆的。                                           |
  | FLAG_INSTALL_ON_DEMAND               | 0x00000800 | 如果未安装指定的功能，请安装该功能                           |
  | FLAG_INSTALL_WITH_BACKGROUND_MODE    | 0x80000000 | 如果未安装，请使用后台模式安装指定的DI功能。                 |
  | FLAG_ABILITY_CLEAR_MISSION           | 0x00008000 | 指示清除其他任务的操作。可以为传递给{@link ohos.app.Context#startAbility}的{@code Intent}设置此标志，并且必须与{@link flag_ABILITY_NEW_MISSION}一起使用 |
  | FLAG_ABILITY_NEW_MISSION             | 0x10000000 | 指示在历史任务堆栈上创建任务的操作。                         |
  | FLAG_ABILITY_MISSION_TOP             | 0x20000000 | 指示如果启动能力的现有实例已位于任务堆栈的顶部，则将重用该实例。否则，将创建一个新的能力实例。 |

- 返回值

  void

- 示例

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
            abilityName: "com.jstest.startabilitytest5.MainAbility",
            uri:""
        },
    },
)
```



#### ParticleAbility.startAbility(parameter: StartAbilityParameter)  

- 接口说明
服务ability使用此方法启动特定ability((Promise形式)
- startAbility参数描述


| 名称      | 读写属性 | 类型                  | 必填 | 描述              |
| --------- | -------- | --------------------- | ---- | ----------------- |
| parameter | 只读     | StartAbilityParameter | 是   | 指示启动的ability |
- StartAbilityParameter类型说明

| 名称                | 读写属性 | 类型   | 必填 | 描述                               |
| ------------------- | -------- | ------ | ---- | ---------------------------------- |
| want                | 只读     | want   | 是   | 表示需要包含有关目标启动能力的信息 |
| abilityStartSetting | 只读     | string | 否   | 指示启动能力中使用的特殊启动设置   |

- want类型说明

| 名称        | 读写属性 | 类型   | 必填 | 描述                       |
| ----------- | -------- | ------ | ---- | -------------------------- |
| deviceId    | 只读     | string | 否   | 设备id                     |
| bundleName  | 只读     | string | 否   | 捆绑包名称                 |
| abilityName | 只读     | string | 否   | ability 名字               |
| uri         | 只读     | string | 否   | 请求中URI的描述            |
| type        | 只读     | string | 否   | 此文件中类型的说明         |
| flags       | 只读     | number | 否   | 此文件中标志的选项是必需的 |
| action      | 只读     | string | 否   | 需求中对操作的描述         |
| parameters  | 只读     | string | 否   | Want中WantParams对象的描述 |
| entities    | 只读     | string | 否   | 对象中实体的描述           |

- flags类型说明

  | 名称                                 | 参数       | 描述                                                         |
  | ------------------------------------ | ---------- | ------------------------------------------------------------ |
  | FLAG_AUTH_READ_URI_PERMISSION        | 0x00000001 | 指示对URI执行读取操作的授权                                  |
  | FLAG_AUTH_WRITE_URI_PERMISSION       | 0x00000002 | 指示对URI执行写入操作的授权                                  |
  | FLAG_ABILITY_FORWARD_RESULT          | 0x00000004 | 将结果返回给源异能                                           |
  | FLAG_ABILITY_CONTINUATION            | 0x00000008 | 确定是否可以将本地设备上的功能迁移到远程设备                 |
  | FLAG_NOT_OHOS_COMPONENT              | 0x00000010 | 指定组件是否不属于OHOS                                       |
  | FLAG_ABILITY_FORM_ENABLED            | 0x00000020 | 指定是否启动某个能力                                         |
  | FLAG_AUTH_PERSISTABLE_URI_PERMISSION | 0x00000040 | 指示URI上可能持久化的授权                                    |
  | FLAG_AUTH_PREFIX_URI_PERMISSION      | 0x00000080 | 将结果返回到源能力片                                         |
  | FLAG_ABILITYSLICE_MULTI_DEVICE       | 0x00000100 | 支持分布式调度系统中的多设备启动                             |
  | FLAG_START_FOREGROUND_ABILITY        | 0x00000200 | 指示无论主机应用程序是否已启动，都将启动使用服务模板的功能   |
  | FLAG_ABILITY_CONTINUATION_REVERSIBLE | 0x00000400 | 表示延续是可逆的。                                           |
  | FLAG_INSTALL_ON_DEMAND               | 0x00000800 | 如果未安装指定的功能，请安装该功能                           |
  | FLAG_INSTALL_WITH_BACKGROUND_MODE    | 0x80000000 | 如果未安装，请使用后台模式安装指定的DI功能。                 |
  | FLAG_ABILITY_CLEAR_MISSION           | 0x00008000 | 指示清除其他任务的操作。可以为传递给{@link ohos.app.Context#startAbility}的{@code Intent}设置此标志，并且必须与{@link flag_ABILITY_NEW_MISSION}一起使用 |
  | FLAG_ABILITY_NEW_MISSION             | 0x10000000 | 指示在历史任务堆栈上创建任务的操作。                         |
  | FLAG_ABILITY_MISSION_TOP             | 0x20000000 | 指示如果启动能力的现有实例已位于任务堆栈的顶部，则将重用该实例。否则，将创建一个新的能力实例。 |

- 返回值

  void

- 示例

```js
import featureAbility from '@ohos.ability.featureAbility'
import particleAbility from '@ohos.ability.particleAbility'
var windowMode = featureAbility.AbilityStartSetting.WINDOW_MODE_KEY;
particleAbility.startAbility(
      want:
       {
            bundleName: "com.jstest.featureabilitytest",
            abilityName: "com.jstest.startabilitytest1.MainAbility",
            },
            abilityStartSetting:
        {
            windowMode: featureAbility.AbilityWindowConfiguration.WINDOW_MODE_FLOATING,
        },
       }

		).then((void) => {
		console.info("==========================>startAbilityCallback=======================>");
});
```



#### ParticleAbility.terminateSelf(callback: AsyncCallback\<void>)  

- 接口说明

  摧毁服务ability(callback形式)

- terminateSelf参数描述

  | 名称     | 读写属性 | 类型                 | 必填 | 描述                 |
  | -------- | -------- | -------------------- | ---- | -------------------- |
  | callback | 只读     | AsyncCallback\<void> | 是   | 表示被指定的回调方法 |

- 返回值

  void

- 示例

```js
import particleAbility from '@ohos.ability.particleAbility'
ParticleAbility.terminateSelf()
```



#### ParticleAbility.terminateSelf()

- 接口说明

  摧毁服务ability(Promise形式)

- 返回值

  void

- 示例

```js
import particleAbility from '@ohos.ability.particleAbility'
particleAbility.terminateSelf().then((void) => {
		console.info("==========================>terminateSelfCallback=======================>");
});
```



#### ParticleAbility.acquireDataAbilityHelper(uri: string)  

- 接口说明

  获取dataAbilityHelper

- acquireDataAbilityHelper参数描述

  | 名称 | 读写属性 | 类型   | 必填 | 描述                   |
  | :--- | -------- | ------ | ---- | ---------------------- |
  | uri  | 只读     | string | 是   | 指示要打开的文件的路径 |

- 返回值

  返回dataAbilityHelper

- 示例

```js
import particleAbility from '@ohos.ability.particleAbility'     
var uri = "";
ParticleAbility.acquireDataAbilityHelper(uri)
```

#### ParticleAbility.connectAbility(*request*: Want, *options*:ConnectOptions): number

* 接口说明

  将当前ability连接到指定ServiceAbility(callback形式)

* connectAbility参数描述

| 名称    | 读写属性 | 类型           | 必填 | 描述                       |
| ------- | -------- | -------------- | ---- | -------------------------- |
| request | 只读     | Want           | 是   | 表示被连接的ServiceAbility |
| options | 只读     | ConnectOptions | 是   | 被指定的回调方法           |

- ConnectOptions类型说明

| 名称         | 读写属性 | 类型     | 必填 | 描述                               |
| ------------ | -------- | -------- | ---- | ---------------------------------- |
| onConnect    | 只读     | function | 是   | 连接成功时的回调函数               |
| onDisconnect | 只读     | function | 是   | 连接失败时的回调函数               |
| onFailed     | 只读     | function | 是   | ConnectAbility调用失败时的回调函数 |

* 返回值

  连接的ServiceAbilityID。

* 示例

```javascript
import particleAbility from '@ohos.ability.particleAbility'
var mRemote;
var connId;
function onConnectCallback(element, remote){
    mRemote = remote;
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
        abilityName: "ServiceAbilityA",
    },
    {
        onConnect: onConnectCallback,
        onDisconnect: onDisconnectCallback,
        onFailed: onFailedCallback,
    },
);
```

#### ParticleAbility.disconnectAbility(connection: number, callback:AsyncCallback<void>): void

* 接口说明

  断开与指定ServiceAbility的连接(callback形式)

* disconnectAbility参数描述

| 名称       | 读写属性 | 类型          | 必填 | 描述                           |
| ---------- | -------- | ------------- | ---- | ------------------------------ |
| connection | 只读     | number        | 是   | 指定断开连接的ServiceAbilityID |
| callback   | 只读     | AsyncCallback | 是   | 被指定的回调方法               |

* 返回值

  无

* 示例

```javascript
import particleAbility from '@ohos.ability.particleAbility'
var mRemote;
var connId;
function onConnectCallback(element, remote){
    mRemote = remote;
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
        abilityName: "ServiceAbilityA",
    },
    {
        onConnect: onConnectCallback,
        onDisconnect: onDisconnectCallback,
        onFailed: onFailedCallback,
    },
);
var result = particleAbility.disconnectAbility(connId,
    (error,data) => {
    console.log('particleAbilityTest DisConnectJsSameBundleName result errCode : ' + error.code + " data: " + data)
    },
);
```

#### ParticleAbility.disconnectAbility(connection: number): Promise<void>;

* 接口说明

  断开与指定ServiceAbility的连接(promise形式)

* disconnectAbility参数描述

| 名称       | 读写属性 | 类型   | 必填 | 描述                           |
| ---------- | -------- | ------ | ---- | ------------------------------ |
| connection | 只读     | number | 是   | 指定断开连接的ServiceAbilityID |

* 返回值

  无

* 示例

```javascript
import particleAbility from '@ohos.ability.particleAbility'
var mRemote;
var connId;
function onConnectCallback(element, remote){
    mRemote = remote;
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
        abilityName: "ServiceAbilityA",
    },
    {
        onConnect: onConnectCallback,
        onDisconnect: onDisconnectCallback,
        onFailed: onFailedCallback,
    },
);
var result = await particleAbility.disconnectAbility(connId);
```

