# @ohos.ability.particleAbility (ParticleAbility模块)

particleAbility模块提供了操作Service类型的Ability的能力，包括启动、停止指定的particleAbility，获取dataAbilityHelper，连接、断连指定的ServiceAbility等。

> **说明：**
> 
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  
> 本模块接口仅可在FA模型下使用。

## 使用限制

particleAbility模块用来对Data和Service类型的Ability进行操作。

## 导入模块

```ts
import particleAbility from '@ohos.ability.particleAbility'
```

## particleAbility.startAbility

startAbility(parameter: StartAbilityParameter, callback: AsyncCallback\<void>): void

启动指定的particleAbility（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 参数名      | 类型                                            | 必填 | 说明              |
| --------- | ----------------------------------------------- | ---- | ----------------- |
| parameter | [StartAbilityParameter](js-apis-inner-ability-startAbilityParameter.md) | 是   | 表示启动的ability |
| callback  | AsyncCallback\<void>                            | 是   | 以callback的形式返回启动Ability的结果  |

**示例：**

```ts
import particleAbility from '@ohos.ability.particleAbility'
import wantConstant from '@ohos.ability.wantConstant'

particleAbility.startAbility(
    {
        want:
        {
            action: "action.system.home",
            entities: ["entity.system.home"],
            type: "MIMETYPE",
            flags: wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION,
            deviceId: "",
            bundleName: "com.example.Data",
            abilityName: "com.example.Data.MainAbility",
            uri: ""
        },
    },
    (error, result) => {
        console.log('particleAbility startAbility errCode:' + error + 'result:' + result)
    },
)
```

## particleAbility.startAbility

startAbility(parameter: StartAbilityParameter): Promise\<void>;

启动指定的particleAbility（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 参数名      | 类型                                            | 必填 | 说明              |
| --------- | ----------------------------------------------- | ---- | ----------------- |
| parameter | [StartAbilityParameter](js-apis-inner-ability-startAbilityParameter.md) | 是   | 表示启动的ability |

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | Promise形式返回启动Ability的结果。 |

**示例：**

```ts
import particleAbility from '@ohos.ability.particleAbility'
import wantConstant from '@ohos.ability.wantConstant'

particleAbility.startAbility(
    {
        want:
        {
            action: "action.system.home",
            entities: ["entity.system.home"],
            type: "MIMETYPE",
            flags: wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION,
            deviceId: "",
            bundleName: "com.example.Data",
            abilityName: "com.example. Data.MainAbility",
            uri: ""
        },
    },
).then((data) => {
    console.info("particleAbility startAbility");
});
```

## particleAbility.terminateSelf

terminateSelf(callback: AsyncCallback\<void>): void

销毁当前particleAbility（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 参数名     | 类型                 | 必填 | 说明                 |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void> | 是   | 以callback的形式返回停止当前Ability结果 |

**示例：**

```ts
import particleAbility from '@ohos.ability.particleAbility'

particleAbility.terminateSelf(
    (error, result) => {
        console.log('particleAbility terminateSelf errCode:' + error + 'result:' + result)
    }
)
```

## particleAbility.terminateSelf

terminateSelf(): Promise\<void>

销毁当前particleAbility（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | 使用Promise形式返回停止当前Ability结果。 |

**示例：**

```ts
import particleAbility from '@ohos.ability.particleAbility'

particleAbility.terminateSelf().then((data) => {
	console.info("particleAbility terminateSelf");
});
```



## particleAbility.acquireDataAbilityHelper

acquireDataAbilityHelper(uri: string): DataAbilityHelper

获取dataAbilityHelper对象。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 参数名 | 类型   | 必填 | 说明                     |
| :--- | ------ | ---- | ------------------------ |
| uri  | string | 是   | 表示要打开的文件的路径。 |

**返回值：**

| 类型              | 说明                                         |
| ----------------- | -------------------------------------------- |
| [DataAbilityHelper](js-apis-inner-ability-dataAbilityHelper.md) | 用来协助其他Ability访问DataAbility的工具类。 |

**示例：**

```ts
import particleAbility from '@ohos.ability.particleAbility'

var uri = "";
particleAbility.acquireDataAbilityHelper(uri)
```


## particleAbility.startBackgroundRunning

startBackgroundRunning(id: number, request: NotificationRequest, callback: AsyncCallback&lt;void&gt;): void;

向系统申请长时任务，使用callback形式返回结果，建议使用新接口[backgroundTaskManager.startBackgroundRunning](js-apis-backgroundTaskManager.md#backgroundtaskmanagerstartbackgroundrunning8)。

**需要权限:** ohos.permission.KEEP_BACKGROUND_RUNNING

**系统能力**：SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | id | number | 是 | 长时任务通知id号 |
  | request | [NotificationRequest](js-apis-notification.md#notificationrequest) | 是 | 通知参数，用于显示通知栏的信息 |
  | callback | AsyncCallback&lt;void&gt; | 是 | callback形式返回启动长时任务的结果 |

 **示例**：

```ts
import notification from '@ohos.notification';
import particleAbility from '@ohos.ability.particleAbility';
import wantAgent from '@ohos.wantAgent';

function callback(err, data) {
    if (err) {
        console.error("Operation failed cause: " + JSON.stringify(err));
    } else {
        console.info("Operation succeeded");
    }
}

let wantAgentInfo = {
    wants: [
        {
            bundleName: "com.example.myapplication",
            abilityName: "com.example.myapplication.MainAbility"
        }
    ],
    operationType: wantAgent.OperationType.START_ABILITY,
    requestCode: 0,
    wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
};

wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj) => {
    let basicContent = {
        title: "title",
        text: "text"
    };
    let notificationContent = {
        contentType: notification.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT,
        normal: basicContent
    };
    let request = {
        content: notificationContent,
        wantAgent: wantAgentObj
    };
    let id = 1;
    particleAbility.startBackgroundRunning(id, request, callback);
});

```

## particleAbility.startBackgroundRunning

startBackgroundRunning(id: number, request: NotificationRequest): Promise&lt;void&gt;

**需要权限:** ohos.permission.KEEP_BACKGROUND_RUNNING

**系统能力**：SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

向系统申请长时任务，使用promise形式返回结果，建议使用新接口[backgroundTaskManager.startBackgroundRunning](js-apis-backgroundTaskManager.md#backgroundtaskmanagerstartbackgroundrunning8-1)。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| id | number | 是 | 长时任务通知id号 |
| request | [NotificationRequest](js-apis-notification.md#notificationrequest) | 是 | 通知参数，用于显示通知栏的信息 |

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | 使用Promise形式返回启动长时任务的结果。 |

**示例**：

```ts
import notification from '@ohos.notification';
import particleAbility from '@ohos.ability.particleAbility';
import wantAgent from '@ohos.wantAgent';

let wantAgentInfo = {
    wants: [
        {
            bundleName: "com.example.myapplication",
            abilityName: "com.example.myapplication.MainAbility"
        }
    ],
    operationType: wantAgent.OperationType.START_ABILITY,
    requestCode: 0,
    wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
};

wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj) => {
    let basicContent = {
        title: "title",
        text: "text"
    };
    let notificationContent = {
        contentType: notification.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT,
        normal: basicContent
    };
    let request = {
        content: notificationContent,
        wantAgent: wantAgentObj
    };
    let id = 1;
    particleAbility.startBackgroundRunning(id, request).then(() => {
        console.info("Operation succeeded");
    }).catch((err) => {
        console.error("Operation failed cause: " + JSON.stringify(err));
    });
});

```

## particleAbility.cancelBackgroundRunning

cancelBackgroundRunning(callback: AsyncCallback&lt;void&gt;): void;

向系统申请取消长时任务，使用callback形式返回结果，建议使用新接口[backgroundTaskManager.stopBackgroundRunning](js-apis-backgroundTaskManager.md#backgroundtaskmanagerstopbackgroundrunning8)。

**系统能力**：SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

 **参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;void&gt; | 是 | callback形式返回取消长时任务的结果 |

 **示例**：

```ts
import particleAbility from '@ohos.ability.particleAbility';

function callback(err, data) {
    if (err) {
        console.error("Operation failed cause: " + JSON.stringify(err));
    } else {
        console.info("Operation succeeded");
    }
}

particleAbility.cancelBackgroundRunning(callback);

```

## particleAbility.cancelBackgroundRunning

cancelBackgroundRunning(): Promise&lt;void&gt;;

向系统申请取消长时任务，使用promise形式返回结果，建议使用新接口[backgroundTaskManager.stopBackgroundRunning](js-apis-backgroundTaskManager.md#backgroundtaskmanagerstopbackgroundrunning8-1)。

**系统能力**：SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | 使用Promise形式返回取消长时任务的结果。 |

 **示例**：

```ts
import particleAbility from '@ohos.ability.particleAbility';

particleAbility.cancelBackgroundRunning().then(() => {
    console.info("Operation succeeded");
}).catch((err) => {
    console.error("Operation failed cause: " + JSON.stringify(err));
});

```

## particleAbility.connectAbility

connectAbility(request: Want, options:ConnectOptions): number

将当前ability与指定的ServiceAbility进行连接（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 参数名    | 类型           | 必填 | 说明                         |
| ------- | -------------- | ---- | ---------------------------- |
| request | [Want](js-apis-application-want.md)           | 是   | 表示被连接的ServiceAbility。 |
| options | [ConnectOptions](js-apis-inner-ability-connectOptions.md) | 是   | 连接回调方法。           |


**示例**：

```ts
import rpc from '@ohos.rpc'

function onConnectCallback(element, remote) {
    console.log('ConnectAbility onConnect remote is proxy:' + (remote instanceof rpc.RemoteProxy));
}

function onDisconnectCallback(element) {
    console.log('ConnectAbility onDisconnect element.deviceId : ' + element.deviceId)
}

function onFailedCallback(code) {
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

particleAbility.disconnectAbility(connId).then((data) => {
    console.log(" data: " + data);
}).catch((error) => {
    console.log('particleAbilityTest result errCode : ' + error.code)
});
    
```

## particleAbility.disconnectAbility

disconnectAbility(connection: number, callback:AsyncCallback\<void>): void;

断开当前ability与指定ServiceAbility的连接（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;void&gt; | 是 | callback形式返回断开连接的结果 |

**示例**：

```ts
import rpc from '@ohos.rpc'

function onConnectCallback(element, remote) {
    console.log('ConnectAbility onConnect remote is proxy:' + (remote instanceof rpc.RemoteProxy));
}

function onDisconnectCallback(element) {
    console.log('ConnectAbility onDisconnect element.deviceId : ' + element.deviceId)
}

function onFailedCallback(code) {
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
var result = particleAbility.disconnectAbility(connId).then((data) => {
    console.log(" data: " + data);
}).catch((error) => {
    console.log('particleAbilityTest result errCode : ' + error.code)
});
```


## particleAbility.disconnectAbility

disconnectAbility(connection: number): Promise\<void>;

断开当前ability与指定ServiceAbility的连接（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | 使用Promise形式返回结果。 |

**示例**：

```ts
import rpc from '@ohos.rpc'

function onConnectCallback(element, remote) {
    console.log('ConnectAbility onConnect remote is proxy:' + (remote instanceof rpc.RemoteProxy));
}

function onDisconnectCallback(element) {
    console.log('ConnectAbility onDisconnect element.deviceId : ' + element.deviceId)
}

function onFailedCallback(code) {
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

particleAbility.disconnectAbility(connId).then((data) => {
    console.log(" data: " + data);
}).catch((error) => {
    console.log('particleAbilityTest result errCode : ' + error.code)
});

```

## ErrorCode

表示错误码。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

| 名称                          | 值   | 说明                                                         |
| ----------------------------- | ---- | ------------------------------------------------------------ |
| INVALID_PARAMETER         | -1    | 无效的参数。 |









