# @ohos.ability.particleAbility (ParticleAbility模块)

particleAbility模块提供了操作Data和Service类型的Ability的能力，包括启动、停止指定的particleAbility，获取dataAbilityHelper，连接、断连指定的ServiceAbility等。

> **说明：**
> 
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  
> 本模块接口仅可在FA模型下使用。

## 使用限制

particleAbility模块用来对Data和Service类型的Ability进行操作。

## 导入模块

```ts
import particleAbility from '@ohos.ability.particleAbility';
```

## particleAbility.startAbility

startAbility(parameter: StartAbilityParameter, callback: AsyncCallback\<void>): void

启动指定的particleAbility（callback形式）。

使用规则：
 - 调用方应用位于后台时，使用该接口启动Ability需申请`ohos.permission.START_ABILITIES_FROM_BACKGROUND`权限
 - 跨应用场景下，目标Ability的visible属性若配置为false，调用方应用需申请`ohos.permission.START_INVISIBLE_ABILITY`权限
 - 组件启动规则详见：[组件启动规则（FA模型）](../../application-models/component-startup-rules-fa.md)

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 参数名      | 类型                                            | 必填 | 说明              |
| --------- | ----------------------------------------------- | ---- | ----------------- |
| parameter | [StartAbilityParameter](js-apis-inner-ability-startAbilityParameter.md) | 是   | 表示启动的ability |
| callback  | AsyncCallback\<void>                            | 是   | 以callback的形式返回启动Ability的结果  |

**示例：**

```ts
import particleAbility from '@ohos.ability.particleAbility';
import wantConstant from '@ohos.app.ability.wantConstant';

particleAbility.startAbility(
    {
        want:
        {
            action: 'ohos.want.action.home',
            entities: ['entity.system.home'],
            type: 'MIMETYPE',
            flags: wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION,
            deviceId: '',
            bundleName: 'com.example.Data',
            abilityName: 'com.example.Data.EntryAbility',
            uri: ''
        },
    },
    (error, data) => {
        if (error && error.code !== 0) {
            console.error(`startAbility fail, error: ${JSON.stringify(error)}`);
        } else {
            console.log(`startAbility success, data: ${JSON.stringify(data)}`);
        }
    },
);
```

## particleAbility.startAbility

startAbility(parameter: StartAbilityParameter): Promise\<void>

启动指定的particleAbility（Promise形式）。

使用规则：
 - 调用方应用位于后台时，使用该接口启动Ability需申请`ohos.permission.START_ABILITIES_FROM_BACKGROUND`权限
 - 跨应用场景下，目标Ability的visible属性若配置为false，调用方应用需申请`ohos.permission.START_INVISIBLE_ABILITY`权限
 - 组件启动规则详见：[组件启动规则（FA模型）](../../application-models/component-startup-rules-fa.md)

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 参数名      | 类型                                            | 必填 | 说明              |
| --------- | ----------------------------------------------- | ---- | ----------------- |
| parameter | [StartAbilityParameter](js-apis-inner-ability-startAbilityParameter.md) | 是   | 表示启动的ability |

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**示例：**

```ts
import particleAbility from '@ohos.ability.particleAbility';
import wantConstant from '@ohos.app.ability.wantConstant';

particleAbility.startAbility(
    {
        want:
        {
            action: 'ohos.want.action.home',
            entities: ['entity.system.home'],
            type: 'MIMETYPE',
            flags: wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION,
            deviceId: '',
            bundleName: 'com.example.Data',
            abilityName: 'com.example.Data.EntryAbility',
            uri: ''
        },
    },
).then(() => {
    console.info('particleAbility startAbility');
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
import particleAbility from '@ohos.ability.particleAbility';

particleAbility.terminateSelf(
    (error) => {
        if (error && error.code !== 0) {
            console.error(`terminateSelf fail, error: ${JSON.stringify(error)}`);
        }
    }
);
```

## particleAbility.terminateSelf

terminateSelf(): Promise\<void>

销毁当前particleAbility（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**示例：**

```ts
import particleAbility from '@ohos.ability.particleAbility';

particleAbility.terminateSelf().then(() => {
	console.info('particleAbility terminateSelf');
});
```



## particleAbility.acquireDataAbilityHelper

acquireDataAbilityHelper(uri: string): DataAbilityHelper

获取dataAbilityHelper对象。

使用规则：
 - 跨应用访问dataAbility，对端应用需配置关联启动
 - 调用方应用位于后台时，使用该接口访问dataAbility需申请`ohos.permission.START_ABILITIES_FROM_BACKGROUND`权限（基于API 8或更早版本SDK开发的应用在启动DataAbility组件时不受此限制的约束）
 - 跨应用场景下，目标dataAbility的visible属性若配置为false，调用方应用需申请`ohos.permission.START_INVISIBLE_ABILITY`权限
 - 组件启动规则详见：[组件启动规则（FA模型）](../../application-models/component-startup-rules-fa.md)

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
import particleAbility from '@ohos.ability.particleAbility';

let uri = '';
particleAbility.acquireDataAbilityHelper(uri);
```


## particleAbility.startBackgroundRunning<sup>(deprecated)</sup>

startBackgroundRunning(id: number, request: NotificationRequest, callback: AsyncCallback&lt;void&gt;): void

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
import notification from '@ohos.notificationManager';
import particleAbility from '@ohos.ability.particleAbility';
import wantAgent from '@ohos.app.ability.wantAgent';
import { BusinessError } from '@ohos.base';

function callback(error: BusinessError, data: void) {
    if (error && error.code !== 0) {
        console.error(`Operation failed error: ${JSON.stringify(error)}`);
    } else {
        console.info(`Operation succeeded, data: ${data}`);
    }
}

let wantAgentInfo: wantAgent.WantAgentInfo = {
    wants: [
        {
            bundleName: 'com.example.myapplication',
            abilityName: 'EntryAbility'
        }
    ],
    operationType: wantAgent.OperationType.START_ABILITY,
    requestCode: 0,
    wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
};

wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj) => {
    let id = 1;
    particleAbility.startBackgroundRunning(id, {
        content:
        {
            contentType: notification.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT,
            normal:
            {
                title: 'title',
                text: 'text'
            }
        },
        wantAgent: wantAgentObj
    }, callback);
});

```

## particleAbility.startBackgroundRunning<sup>(deprecated)</sup>

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
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**示例**：

```ts
import notification from '@ohos.notificationManager';
import particleAbility from '@ohos.ability.particleAbility';
import wantAgent from '@ohos.app.ability.wantAgent';
import { BusinessError } from '@ohos.base';

let wantAgentInfo: wantAgent.WantAgentInfo = {
    wants: [
        {
            bundleName: 'com.example.myapplication',
            abilityName: 'EntryAbility'
        }
    ],
    operationType: wantAgent.OperationType.START_ABILITY,
    requestCode: 0,
    wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
};

wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj) => {
    let id = 1;
    particleAbility.startBackgroundRunning(id, {
        content:
        {
            contentType: notification.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT,
            normal:
            {
                title: 'title',
                text: 'text'
            }
        },
        wantAgent: wantAgentObj
    }).then(() => {
        console.info('Operation succeeded');
    }).catch((err: BusinessError) => {
        console.error(`Operation failed cause: ${JSON.stringify(err)}`);
    });
});

```

## particleAbility.cancelBackgroundRunning<sup>(deprecated)</sup>

cancelBackgroundRunning(callback: AsyncCallback&lt;void&gt;): void

向系统申请取消长时任务，使用callback形式返回结果，建议使用新接口[backgroundTaskManager.stopBackgroundRunning](js-apis-backgroundTaskManager.md#backgroundtaskmanagerstopbackgroundrunning8)。

**系统能力**：SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

 **参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;void&gt; | 是 | callback形式返回取消长时任务的结果 |

 **示例**：

```ts
import particleAbility from '@ohos.ability.particleAbility';
import { BusinessError } from '@ohos.base';

function callback(error: BusinessError, data: void) {
    if (error && error.code !== 0) {
        console.error(`Operation failed error: ${JSON.stringify(error)}`);
    } else {
        console.info(`Operation succeeded, data: ${data}`);
    }
}

particleAbility.cancelBackgroundRunning(callback);

```

## particleAbility.cancelBackgroundRunning<sup>(deprecated)</sup>

cancelBackgroundRunning(): Promise&lt;void&gt;

向系统申请取消长时任务，使用promise形式返回结果，建议使用新接口[backgroundTaskManager.stopBackgroundRunning](js-apis-backgroundTaskManager.md#backgroundtaskmanagerstopbackgroundrunning8-1)。

**系统能力**：SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

 **示例**：

```ts
import particleAbility from '@ohos.ability.particleAbility';
import { BusinessError } from '@ohos.base';

particleAbility.cancelBackgroundRunning().then(() => {
    console.info('Operation succeeded');
}).catch((err: BusinessError) => {
    console.error(`Operation failed cause: ${JSON.stringify(err)}`);
});

```

## particleAbility.connectAbility

connectAbility(request: Want, options:ConnectOptions): number

将当前ability与指定的ServiceAbility进行连接（callback形式）。

使用规则：
 - 跨应用连接serviceAbility，对端应用需配置关联启动
 - 调用方应用位于后台时，使用该接口连接serviceAbility需申请`ohos.permission.START_ABILITIES_FROM_BACKGROUND`权限（基于API 8或更早版本SDK开发的应用在启动ServiceAbility组件时不受此限制的约束）
 - 跨应用场景下，目标serviceAbility的visible属性若配置为false，调用方应用需申请`ohos.permission.START_INVISIBLE_ABILITY`权限
 - 组件启动规则详见：[组件启动规则（FA模型）](../../application-models/component-startup-rules-fa.md)

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 参数名    | 类型           | 必填 | 说明                         |
| ------- | -------------- | ---- | ---------------------------- |
| request | [Want](js-apis-application-want.md)           | 是   | 表示被连接的ServiceAbility。 |
| options | [ConnectOptions](js-apis-inner-ability-connectOptions.md) | 是   | 连接回调方法。           |

**返回值：**

| 类型     | 说明                   |
| ------ | -------------------- |
| number | 连接的ServiceAbility的ID(ID从0开始自增，每连接成功一次ID加1)。 |


**示例**：

```ts
import particleAbility from '@ohos.ability.particleAbility';
import rpc from '@ohos.rpc';
import { BusinessError } from '@ohos.base';

let connId = particleAbility.connectAbility(
    {
        bundleName: 'com.ix.ServiceAbility',
        abilityName: 'ServiceAbilityA',
    },
    {
        onConnect: (element, remote) => {
            console.log(`ConnectAbility onConnect remote is proxy: ${(remote instanceof rpc.RemoteProxy)}`);
        },
        onDisconnect: (element) => {
            console.log(`ConnectAbility onDisconnect element.deviceId: ${element.deviceId}`);
        },
        onFailed: (code) => {
            console.error(`particleAbilityTest ConnectAbility onFailed errCode: ${code}`);
        },
    },
);

particleAbility.disconnectAbility(connId).then((data) => {
    console.log(`data: ${data}`);
}).catch((error: BusinessError) => {
    console.error(`particleAbilityTest result errCode: ${error.code}`);
});
```

## particleAbility.disconnectAbility

disconnectAbility(connection: number, callback:AsyncCallback\<void>): void

断开当前ability与指定ServiceAbility的连接（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | connection | number               | 是    | 表示断开连接的ServiceAbility的ID。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | callback形式返回断开连接的结果 |

**示例**：

```ts
import particleAbility from '@ohos.ability.particleAbility';
import rpc from '@ohos.rpc';

let connId = particleAbility.connectAbility(
    {
        bundleName: 'com.ix.ServiceAbility',
        abilityName: 'ServiceAbilityA',
    },
    {
        onConnect: (element, remote) => {
            console.log(`ConnectAbility onConnect remote is proxy: ${(remote instanceof rpc.RemoteProxy)}`);
        },
        onDisconnect: (element) => {
            console.log(`ConnectAbility onDisconnect element.deviceId: ${element.deviceId}`);
        },
        onFailed: (code) => {
            console.error(`particleAbilityTest ConnectAbility onFailed errCode: ${code}`);
        },
    },
);

particleAbility.disconnectAbility(connId, (err) => {
    console.error(`particleAbilityTest disconnectAbility err: ${JSON.stringify(err)}`);
});
```


## particleAbility.disconnectAbility

disconnectAbility(connection: number): Promise\<void>

断开当前ability与指定ServiceAbility的连接（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| connection | number               | 是    | 表示断开连接的ServiceAbility的ID。 |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**示例**：

```ts
import particleAbility from '@ohos.ability.particleAbility';
import rpc from '@ohos.rpc';
import { BusinessError } from '@ohos.base';

let connId = particleAbility.connectAbility(
    {
        bundleName: 'com.ix.ServiceAbility',
        abilityName: 'ServiceAbilityA',
    },
    {
        onConnect: (element, remote) => {
            console.log(`ConnectAbility onConnect remote is proxy: ${(remote instanceof rpc.RemoteProxy)}`);
        },
        onDisconnect: (element) => {
            console.log(`ConnectAbility onDisconnect element.deviceId: ${element.deviceId}`);
        },
        onFailed: (code) => {
            console.error(`particleAbilityTest ConnectAbility onFailed errCode: ${code}`);
        },
    },
);

particleAbility.disconnectAbility(connId).then(() => {
    console.log('disconnectAbility success');
}).catch((error: BusinessError) => {
    console.error(`particleAbilityTest result errCode : ${error.code}`);
});
```

## ErrorCode

表示错误码。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

| 名称                          | 值   | 说明                                                         |
| ----------------------------- | ---- | ------------------------------------------------------------ |
| INVALID_PARAMETER         | -1    | 无效的参数。 |
