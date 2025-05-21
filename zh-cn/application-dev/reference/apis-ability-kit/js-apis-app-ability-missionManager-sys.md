# @ohos.app.ability.missionManager (missionManager)(系统接口)

missionManager模块提供系统任务管理能力，包括对系统任务执行锁定、解锁、清理、切换到前台等操作。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口均为系统接口，三方应用不支持调用。

## 导入模块

```ts
import { missionManager } from '@kit.AbilityKit';
```

## 权限列表

ohos.permission.MANAGE_MISSIONS

## missionManager.on('mission')

on(type:'mission', listener: MissionListener): number

注册系统任务状态监听器。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统接口**：此接口为系统接口。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type     | string   | 是       | 监听的任务名称。固定值：'mission'，表示系统任务状态监听器。 |
  | listener | [MissionListener](js-apis-inner-application-missionListener-sys.md) | 是 | 系统任务监听器。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | number | 监听器的index值，由系统创建，在注册系统任务状态监听时分配，和监听器一一对应&nbsp;。 |

**示例：**

```ts
import { missionManager, UIAbility, AbilityConstant, common, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';
import { image } from '@kit.ImageKit';

let listener: missionManager.MissionListener = {
  onMissionCreated: (mission: number) => {console.log('--------onMissionCreated-------');},
  onMissionDestroyed: (mission: number) => {console.log('--------onMissionDestroyed-------');},
  onMissionSnapshotChanged: (mission: number) => {console.log('--------onMissionSnapshotChanged-------');},
  onMissionMovedToFront: (mission: number) => {console.log('--------onMissionMovedToFront-------');},
  onMissionIconUpdated: (mission: number, icon: image.PixelMap) => {console.log('--------onMissionIconUpdated-------');},
  onMissionClosed: (mission: number) => {console.log('--------onMissionClosed-------');},
  onMissionLabelUpdated: (mission: number) => {console.log('--------onMissionLabelUpdated-------');}
};

let listenerId = -1;
let abilityWant: Want;
let context: common.UIAbilityContext;

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    console.log('[Demo] EntryAbility onCreate');
    abilityWant = want;
    context = this.context;
  }

  onDestroy() {
    try {
      if (listenerId !== -1) {
        missionManager.off('mission', listenerId).catch((err: BusinessError) => {
          console.log(JSON.stringify(err));
        });
      }
    } catch (paramError) {
      let code = (paramError as BusinessError).code;
      let message = (paramError as BusinessError).message;
      console.error(`error: ${code}, ${message} `);
    }
    console.log('[Demo] EntryAbility onDestroy');
  }

  onWindowStageCreate(windowStage: window.WindowStage) {
    // Main window is created, set main page for this ability
    console.log('[Demo] EntryAbility onWindowStageCreate');
    try {
      listenerId = missionManager.on('mission', listener);
    } catch (paramError) {
      let code = (paramError as BusinessError).code;
      let message = (paramError as BusinessError).message;
      console.error(`error: ${code}, ${message} `);
    }

    windowStage.loadContent('pages/index', (err, data) => {
      if (err.code) {
        console.error(`Failed to load the content. Cause: ${JSON.stringify(err)}`);
        return;
      }
      console.info(`Succeeded in loading the content. Data: ${JSON.stringify(data)}`);
    });
  }
}
```


## missionManager.off('mission')

off(type: 'mission', listenerId: number, callback: AsyncCallback&lt;void&gt;): void

解注册任务状态监听器。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统接口**：此接口为系统接口。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type     | string   | 是       | 取消监听的任务名称。固定值：'mission'，表示系统任务状态监听器。 |
  | listenerId | number | 是 | 系统任务状态监器法的index值，和监听器一一对应，由on方法返回。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | 执行结果回调函数。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16300002 | The specified mission listener does not exist. |

**示例：**

```ts
import { missionManager, UIAbility, AbilityConstant, common, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';
import { image } from '@kit.ImageKit';

let listener: missionManager.MissionListener = {
  onMissionCreated: (mission: number) => {console.log('--------onMissionCreated-------');},
  onMissionDestroyed: (mission: number) => {console.log('--------onMissionDestroyed-------');},
  onMissionSnapshotChanged: (mission: number) => {console.log('--------onMissionSnapshotChanged-------');},
  onMissionMovedToFront: (mission: number) => {console.log('--------onMissionMovedToFront-------');},
  onMissionIconUpdated: (mission: number, icon: image.PixelMap) => {console.log('--------onMissionIconUpdated-------');},
  onMissionClosed: (mission: number) => {console.log('--------onMissionClosed-------');},
  onMissionLabelUpdated: (mission: number) => {console.log('--------onMissionLabelUpdated-------');}
};

let listenerId = -1;
let abilityWant: Want;
let context: common.UIAbilityContext;

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    console.log('[Demo] EntryAbility onCreate');
    abilityWant = want;
    context = this.context;
  }

  onDestroy() {
    try {
      if (listenerId !== -1) {
        missionManager.off('mission', listenerId, (err: BusinessError) => {
          console.log(`${err.code}`);
        });
      }
    } catch (paramError) {
      let code = (paramError as BusinessError).code;
      let message = (paramError as BusinessError).message;
      console.error(`error: ${code}, ${message} `);
    }
    console.log('[Demo] EntryAbility onDestroy');
  }

  onWindowStageCreate(windowStage: window.WindowStage) {
    // Main window is created, set main page for this ability
    console.log('[Demo] EntryAbility onWindowStageCreate');
    try {
      listenerId = missionManager.on('mission', listener);
    } catch (paramError) {
      let code = (paramError as BusinessError).code;
      let message = (paramError as BusinessError).message;
      console.error(`error: ${code}, ${message} `);
    }

    windowStage.loadContent('pages/index', (err: BusinessError, data) => {
      if (err.code) {
        console.error(`Failed to load the content. Cause: ${JSON.stringify(err)}`);
        return;
      }
      console.info(`Succeeded in loading the content. Data: ${JSON.stringify(data)}`);
    });
  }
}
```


## missionManager.off('mission')

off(type: 'mission', listenerId: number): Promise&lt;void&gt;

解注册任务状态监听，以promise方式返回执行结果。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统接口**：此接口为系统接口。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type     | string   | 是       | 取消监听的任务名称。固定值：'mission'，表示系统任务状态监听器。 |
  | listenerId | number | 是 | 系统任务状态监听器的index值，和监听器一一对应，由on方法返回。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;void&gt; | promise方式返回执行结果。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16300002 | The specified mission listener does not exist. |

**示例：**

```ts
import { missionManager, UIAbility, AbilityConstant, common, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';
import { image } from '@kit.ImageKit';

let listener: missionManager.MissionListener = {
  onMissionCreated: (mission: number) => {console.log('--------onMissionCreated-------');},
  onMissionDestroyed: (mission: number) => {console.log('--------onMissionDestroyed-------');},
  onMissionSnapshotChanged: (mission: number) => {console.log('--------onMissionSnapshotChanged-------');},
  onMissionMovedToFront: (mission: number) => {console.log('--------onMissionMovedToFront-------');},
  onMissionIconUpdated: (mission: number, icon: image.PixelMap) => {console.log('--------onMissionIconUpdated-------');},
  onMissionClosed: (mission: number) => {console.log('--------onMissionClosed-------');},
  onMissionLabelUpdated: (mission: number) => {console.log('--------onMissionLabelUpdated-------');}
};

let listenerId = -1;
let abilityWant: Want;
let context: common.UIAbilityContext;

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    console.log('[Demo] EntryAbility onCreate');
    abilityWant = want;
    context = this.context;
  }

  onDestroy() {
    try {
      if (listenerId !== -1) {
        missionManager.off('mission', listenerId).catch((err: BusinessError) => {
          console.log(`${err.code}`);
        });
      }
    } catch (paramError) {
      let code = (paramError as BusinessError).code;
      let message = (paramError as BusinessError).message;
      console.error(`error: ${code}, ${message} `);
    }
    console.log('[Demo] EntryAbility onDestroy');
  }

  onWindowStageCreate(windowStage: window.WindowStage) {
    // Main window is created, set main page for this ability
    console.log('[Demo] EntryAbility onWindowStageCreate');
    try {
      listenerId = missionManager.on('mission', listener);
    } catch (paramError) {
      let code = (paramError as BusinessError).code;
      let message = (paramError as BusinessError).message;
      console.error(`error: ${code}, ${message} `);
    }

    windowStage.loadContent('pages/index', (err: BusinessError, data) => {
      if (err.code) {
        console.error(`Failed to load the content. Cause: ${JSON.stringify(err)}`);
        return;
      }
      console.info(`Succeeded in loading the content. Data: ${JSON.stringify(data)}`);
    });
  }
}
```

## missionManager.getMissionInfo

getMissionInfo(deviceId: string, missionId: number, callback: AsyncCallback&lt;MissionInfo&gt;): void

获取任务信息，以异步回调的方式返回任务信息。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统接口**：此接口为系统接口。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | deviceId | string | 是 | 设备ID，本机默认为空字符串。 |
  | missionId | number | 是 | 任务ID。 |
  | callback | AsyncCallback&lt;[MissionInfo](js-apis-inner-application-missionInfo-sys.md)&gt; | 是 | 执行结果回调函数，返回任务信息。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { missionManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let testMissionId = 1;

missionManager.getMissionInfos('',10)
  .then((allMissions: Array<missionManager.MissionInfo>) => {
    try {
      if (allMissions && allMissions.length > 0) {
        testMissionId = allMissions[0].missionId;
      }

      missionManager.getMissionInfo('', testMissionId, (error: BusinessError, mission: missionManager.MissionInfo) => {
        if (error) {
          console.error(`getMissionInfo failed, error.code: ${error.code}, error.message: ${error.message}`);
        } else {
          console.log(`mission.missionId = ${mission.missionId}`);
          console.log(`mission.runningState = ${mission.runningState}`);
          console.log(`mission.lockedState = ${mission.lockedState}`);
          console.log(`mission.timestamp = ${mission.timestamp}`);
          console.log(`mission.label = ${mission.label}`);
          console.log(`mission.iconPath = ${mission.iconPath}`);
        }
      });
    } catch (paramError) {
      let code = (paramError as BusinessError).code;
      let message = (paramError as BusinessError).message;
      console.error(`error: ${code}, ${message} `);
    }
  })
  .catch((err: BusinessError) => {console.log(`${err.code}`);});
```

## missionManager.getMissionInfo

getMissionInfo(deviceId: string, missionId: number): Promise&lt;MissionInfo&gt;

获取任务信息，以promise方式返回任务信息。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统接口**：此接口为系统接口。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | deviceId | string | 是 | 设备ID，本机默认为空字符串。 |
  | missionId | number | 是 | 任务ID。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;[MissionInfo](js-apis-inner-application-missionInfo-sys.md)&gt; | 任务信息。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { missionManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let testMissionId = 1;

try {
  missionManager.getMissionInfo('', testMissionId).then((data: missionManager.MissionInfo) => {
    console.info(`getMissionInfo successfully. Data: ${JSON.stringify(data)}`);
  }).catch((error: BusinessError) => {
    console.error(`getMissionInfo failed. Cause: ${error.message}`);
  });
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`getMissionInfo failed. Cause: ${err.message}`);
}
```

## missionManager.getMissionInfos

getMissionInfos(deviceId: string, numMax: number, callback: AsyncCallback&lt;Array&lt;MissionInfo&gt;&gt;): void

获取所有任务信息，以回调函数的方式返回任务信息数组。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统接口**：此接口为系统接口。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | deviceId | string | 是 | 设备ID，本机默认为空字符串。 |
  | numMax | number | 是 | 任务信息数量上限。 |
  | callback | AsyncCallback&lt;Array&lt;[MissionInfo](js-apis-inner-application-missionInfo-sys.md)&gt;&gt; | 是 | 执行结果回调函数，返回任务信息数组。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { missionManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  missionManager.getMissionInfos('', 10, (error: BusinessError, missions: Array<missionManager.MissionInfo>) => {
    if (error) {
      console.error(`getMissionInfos failed, error.code: ${error.code}, error.message: ${error.message}`);
    } else {
      console.log(`size = ${missions.length}`);
      console.log(`missions = ${JSON.stringify(missions)}`);
    }
  });
} catch (paramError) {
  let code = (paramError as BusinessError).code;
  let message = (paramError as BusinessError).message;
  console.error(`error: ${code}, ${message} `);
}
```


## missionManager.getMissionInfos

getMissionInfos(deviceId: string, numMax: number): Promise&lt;Array&lt;MissionInfo&gt;&gt;

获取所有任务信息，以promise的方式返回任务信息数组。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统接口**：此接口为系统接口。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | deviceId | string | 是 | 设备ID，本机默认为空字符串。 |
  | numMax | number | 是 | 任务信息数量上限。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;Array&lt;[MissionInfo](js-apis-inner-application-missionInfo-sys.md)&gt;&gt; | 任务信息数组。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { missionManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  missionManager.getMissionInfos('', 10).then((data: Array<missionManager.MissionInfo>) => {
    console.info(`getMissionInfos successfully. Data: ${JSON.stringify(data)}`);
  }).catch((error: BusinessError) => {
    console.error(`getMissionInfos failed. Cause: ${error.message}`);
  });
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`getMissionInfos failed. Cause: ${err.message}`);
}
```

## missionManager.getMissionSnapShot

getMissionSnapShot(deviceId: string, missionId: number, callback: AsyncCallback&lt;MissionSnapshot&gt;): void

获取任务快照，以回调函数的方式返回快照内容。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统接口**：此接口为系统接口。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | deviceId | string | 是 | 设备ID，本机默认为空字符串。 |
  | missionId | number | 是 | 任务ID。 |
  | callback | AsyncCallback&lt;[MissionSnapshot](js-apis-inner-application-missionSnapshot-sys.md)&gt; | 是 | 执行结果回调函数，返回任务快照信息。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**
```ts
import { missionManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let testMissionId = 2;

try {
  missionManager.getMissionSnapShot('', testMissionId, (err: BusinessError, data: missionManager.MissionSnapshot ) => {
    if (err) {
      console.error(`getMissionSnapShot failed: ${err.message}`);
    } else {
      console.info(`getMissionSnapShot successfully: ${JSON.stringify(data)}`);
    }
  });
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`getMissionSnapShot failed: ${err.message}`);
}
```

## missionManager.getMissionSnapShot

getMissionSnapShot(deviceId: string, missionId: number): Promise&lt;MissionSnapshot&gt;

获取任务快照，以promise的方式返回快照内容。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统接口**：此接口为系统接口。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | deviceId | string | 是 | 设备ID，本机默认为空字符串。 |
  | missionId | number | 是 | 任务ID。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;[MissionSnapshot](js-apis-inner-application-missionSnapshot-sys.md)&gt; | 任务快照信息。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**
```ts
import { missionManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let testMissionId = 2;

try {
  missionManager.getMissionSnapShot('', testMissionId).then((data: missionManager.MissionSnapshot) => {
    console.info(`getMissionSnapShot successfully. Data: ${JSON.stringify(data)}`);
  }).catch((error: BusinessError) => {
    console.error(`getMissionSnapShot failed. Cause: ${error.message}`);
  });
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`getMissionSnapShot failed. Cause: ${err.message}`);
}
```

## missionManager.getLowResolutionMissionSnapShot

getLowResolutionMissionSnapShot(deviceId: string, missionId: number, callback: AsyncCallback\<MissionSnapshot>): void

获取任务低分辨率快照。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统接口**：此接口为系统接口。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | deviceId | string | 是 | 设备ID，本机默认为空字符串。 |
  | missionId | number | 是 | 任务ID。 |
  | callback | AsyncCallback&lt;[MissionSnapshot](js-apis-inner-application-missionSnapshot-sys.md)&gt; | 是 | 执行结果回调函数，返回任务快照信息。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**
```ts
import { missionManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let testMissionId = 2;

try {
  missionManager.getLowResolutionMissionSnapShot('', testMissionId, (err: BusinessError, data: missionManager.MissionSnapshot) => {
    if (err) {
      console.error(`getLowResolutionMissionSnapShot failed: ${err.message}`);
    } else {
      console.info(`getLowResolutionMissionSnapShot successfully: ${JSON.stringify(data)}`);
    }
  });
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`getLowResolutionMissionSnapShot failed: ${err.message}`);
}
```

## missionManager.getLowResolutionMissionSnapShot

getLowResolutionMissionSnapShot(deviceId: string, missionId: number): Promise\<MissionSnapshot>

获取任务低分辨率快照。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统接口**：此接口为系统接口。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | deviceId | string | 是 | 设备ID，本机默认为空字符串。 |
  | missionId | number | 是 | 任务ID。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;[MissionSnapshot](js-apis-inner-application-missionSnapshot-sys.md)&gt; | 任务快照信息。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { missionManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let testMissionId = 2;

try {
  missionManager.getLowResolutionMissionSnapShot('', testMissionId).then((data: missionManager.MissionSnapshot) => {
    console.info(`getLowResolutionMissionSnapShot successfully. Data: ${JSON.stringify(data)}`);
  }).catch((error: BusinessError) => {
    console.error(`getLowResolutionMissionSnapShot failed. Cause: ${error.message}`);
  });
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`getLowResolutionMissionSnapShot failed. Cause: ${err.message}`);
}
```


## missionManager.lockMission

lockMission(missionId: number, callback: AsyncCallback&lt;void&gt;): void

锁定指定任务id的任务，以回调函数的方式返回。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统接口**：此接口为系统接口。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | missionId | number | 是 | 任务ID。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | 执行结果回调函数。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16300001 | Mission not found. |

**示例：**

```ts
import { missionManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let testMissionId = 2;

try {
  missionManager.lockMission(testMissionId, (err: BusinessError, data: void) => {
    if (err) {
      console.error(`lockMission failed: ${err.message}`);
    } else {
      console.info(`lockMission successfully: ${JSON.stringify(data)}`);
    }
  });
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`lockMission failed: ${err.message}`);
}
```

## missionManager.lockMission

lockMission(missionId: number): Promise&lt;void&gt;

锁定指定任务id的任务，以promise方式返回。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统接口**：此接口为系统接口。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | missionId | number | 是 | 任务ID。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;void&gt; | promise方式返回执行结果。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16300001 | Mission not found. |

**示例：**
```ts
import { missionManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let testMissionId = 2;

try {
  missionManager.lockMission(testMissionId).then((data: void) => {
    console.info(`lockMission successfully. Data: ${JSON.stringify(data)}`);
  }).catch((error: BusinessError) => {
    console.error(`lockMission failed. Cause: ${error.message}`);
  });
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`lockMission failed. Cause: ${err.message}`);
}
```

## missionManager.unlockMission

unlockMission(missionId: number, callback: AsyncCallback&lt;void&gt;): void

解锁指定任务id的任务，以回调函数的方式返回。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| missionId | number | 是 | 任务ID。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 执行结果回调函数。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16300001 | Mission not found. |

**示例：**
```ts
import { missionManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let testMissionId = 2;

try {
  missionManager.unlockMission(testMissionId, (err: BusinessError, data: void) => {
    if (err) {
      console.error(`unlockMission failed: ${err.message}`);
    } else {
      console.info(`unlockMission successfully: ${JSON.stringify(data)}`);
    }
  });
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`unlockMission failed: ${err.message}`);
}
```

## missionManager.unlockMission

unlockMission(missionId: number): Promise&lt;void&gt;

解锁指定任务id的任务，以promise的方式返回。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统接口**：此接口为系统接口。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | missionId | number | 是 | 任务ID。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;void&gt; | promise方式返回执行结果。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16300001 | Mission not found. |

**示例：**

```ts
import { missionManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let testMissionId = 2;

try {
  missionManager.unlockMission(testMissionId).then((data: void) => {
    console.info(`unlockMission successfully. Data: ${JSON.stringify(data)}`);
  }).catch((error: BusinessError) => {
    console.error(`unlockMission failed. Cause: ${error.message}`);
  });
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`unlockMission failed. Cause: ${err.message}`);
}
```

## missionManager.clearMission

clearMission(missionId: number, callback: AsyncCallback&lt;void&gt;): void

清理指定任务id的任务，无论该任务是否被锁定，以回调函数的方式返回。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统接口**：此接口为系统接口。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | missionId | number | 是 | 任务ID。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | 执行结果回调函数。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { missionManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let testMissionId = 2;

try {
  missionManager.clearMission(testMissionId, (err: BusinessError, data: void) => {
    if (err) {
      console.error(`clearMission failed: ${err.message}`);
    } else {
      console.info(`clearMission successfully: ${JSON.stringify(data)}`);
    }
  });
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`clearMission failed: ${err.message}`);
}
```


## missionManager.clearMission

clearMission(missionId: number): Promise&lt;void&gt;

清理指定任务id的任务，无论该任务是否被锁定，以promise的方式返回。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统接口**：此接口为系统接口。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | missionId | number | 是 | 任务ID。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;void&gt; | promise方式返回执行结果。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { missionManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let testMissionId = 2;

try {
  missionManager.clearMission(testMissionId).then((data: void) => {
    console.info(`clearMission successfully. Data: ${JSON.stringify(data)}`);
  }).catch((error: BusinessError) => {
    console.error(`clearMission failed. Cause: ${error.message}`);
  });
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`clearMission failed. Cause: ${err.message}`);
}
```

## missionManager.clearAllMissions

clearAllMissions(callback: AsyncCallback&lt;void&gt;): void

清理所有未锁定的任务，以回调函数的方式返回。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统接口**：此接口为系统接口。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;void&gt; | 是 | 执行结果回调函数。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { missionManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  missionManager.clearAllMissions((err: BusinessError) => {
    if (err) {
      console.error(`clearAllMissions failed: ${err.message}`);
    } else {
      console.info('clearAllMissions successfully.');
    }
  });
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`clearAllMissions failed: ${err.message}`);
}
```

## missionManager.clearAllMissions

clearAllMissions(): Promise&lt;void&gt;

清理所有未锁定的任务，以promise的方式返回。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统接口**：此接口为系统接口。

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;void&gt; | promise方式返回执行结果。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |

**示例：**

```ts
import { missionManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  missionManager.clearAllMissions().then((data: void) => {
    console.info(`clearAllMissions successfully. Data: ${JSON.stringify(data)}`);
  }).catch((err: BusinessError) => {
    console.error(`clearAllMissions failed: ${err.message}`);
  });
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`clearAllMissions failed: ${err.message}`);
}
```

## missionManager.moveMissionToFront

moveMissionToFront(missionId: number, callback: AsyncCallback&lt;void&gt;): void

把指定任务id的任务切到前台，以回调函数的方式返回。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统接口**：此接口为系统接口。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | missionId | number | 是 | 任务ID。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | 执行结果回调函数。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |

**示例：**

```ts
import { missionManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let testMissionId = 2;

try {
  missionManager.moveMissionToFront(testMissionId, (err: BusinessError, data: void) => {
    if (err) {
      console.error(`moveMissionToFront failed: ${err.message}`);
    } else {
      console.info(`moveMissionToFront successfully: ${JSON.stringify(data)}`);
    }
  });
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`moveMissionToFront failed: ${err.message}`);
}
```

## missionManager.moveMissionToFront

moveMissionToFront(missionId: number, options: StartOptions, callback: AsyncCallback&lt;void&gt;): void

把指定任务id的任务切到前台，同时指定任务切换到前台时的启动参数，例如窗口模式、设备ID等，以回调函数的方式返回。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统接口**：此接口为系统接口。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | missionId | number | 是 | 任务ID。 |
  | options | [StartOptions](js-apis-app-ability-startOptions.md) | 是 | 启动参数选项，用于指定任务切到前台时的窗口模式，设备ID等。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | 执行结果回调函数。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |

**示例：**

```ts
import { missionManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let testMissionId = 2;

try {
  missionManager.moveMissionToFront(testMissionId, {windowMode : 101}, (err: BusinessError, data: void) => {
    if (err) {
      console.error(`moveMissionToFront failed: ${err.message}`);
    } else {
      console.info(`moveMissionToFront successfully: ${JSON.stringify(data)}`);
    }
  });
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`moveMissionToFront failed: ${err.message}`);
}
```

## missionManager.moveMissionToFront

moveMissionToFront(missionId: number, options?: StartOptions): Promise&lt;void&gt;

把指定任务id的任务切到前台，同时指定任务切换到前台时的启动参数，例如窗口模式、设备ID等，以promise的方式返回。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统接口**：此接口为系统接口。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | missionId | number | 是 | 任务ID。 |
  | options | [StartOptions](js-apis-app-ability-startOptions.md) | 否 | 启动参数选项，用于指定任务切到前台时的窗口模式，设备ID等。默认为空，表示按照默认启动参数。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;void&gt; | promise方式返回执行结果。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |

**示例：**

```ts
import { missionManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let testMissionId = 2;

try {
  missionManager.moveMissionToFront(testMissionId).then((data: void) => {
    console.info(`moveMissionToFront successfully. Data: ${JSON.stringify(data)}`);
  }).catch((error: BusinessError) => {
    console.error(`moveMissionToFront failed. Cause: ${error.message}`);
  });
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`moveMissionToFront failed. Cause: ${err.message}`);
}
```

## missionManager.moveMissionsToForeground<sup>10+</sup>

moveMissionsToForeground(missionIds: Array&lt;number&gt;, callback: AsyncCallback&lt;void&gt;): void

将指定任务批量切到前台，以回调函数的方式返回。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统接口**：此接口为系统接口。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | missionIds | Array&lt;number&gt; | 是 | 任务ID数组。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | 执行结果回调函数。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**示例：**

```ts
import { abilityManager, missionManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  missionManager.getMissionInfos("", 10, (error: BusinessError, missionInfos: Array<missionManager.MissionInfo>) => {
    if (error.code) {
      console.error(`getMissionInfos failed, error code: ${error.code}, error msg: ${error.message}.`);
      return;
    }
    if (missionInfos.length < 1) {
      return;
    }

    let toShows = new Array<number>();
    for (let missionInfo of missionInfos) {
      if (missionInfo.abilityState == abilityManager.AbilityState.BACKGROUND) {
        toShows.push(missionInfo.missionId);
      }
    }
    missionManager.moveMissionsToForeground(toShows, (err: BusinessError, data: void) => {
      if (err) {
        console.error(`moveMissionsToForeground failed: ${err.message}`);
      } else {
        console.info(`moveMissionsToForeground successfully: ${JSON.stringify(data)}`);
      }
    });
  });
} catch (paramError) {
  let code = (paramError as BusinessError).code;
  let message = (paramError as BusinessError).message;
  console.error(`error: ${code}, ${message} `);
}
```

## missionManager.moveMissionsToForeground<sup>10+</sup>

moveMissionsToForeground(missionIds: Array&lt;number&gt;, topMission: number, callback: AsyncCallback&lt;void&gt;): void

将指定任务批量切换到前台，并将任务ID等于topMission的任务移动到最顶层，以回调函数的方式返回。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统接口**：此接口为系统接口。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | missionIds | Array&lt;number&gt; | 是 | 任务ID数组。 |
  | topMission | number | 是 | 待移动到最顶层的任务ID |
  | callback | AsyncCallback&lt;void&gt; | 是 | 执行结果回调函数。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**示例：**

```ts
import { abilityManager, missionManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  missionManager.getMissionInfos("", 10, (error: BusinessError, missionInfos: Array<missionManager.MissionInfo>) => {
    if (error.code) {
      console.error(`getMissionInfos failed, error code: ${error.code}, error msg: ${error.message}.`);
      return;
    }
    if (missionInfos.length < 1) {
      return;
    }

    let toShows = new Array<number>();
    for (let missionInfo of missionInfos) {
      if (missionInfo.abilityState == abilityManager.AbilityState.BACKGROUND) {
        toShows.push(missionInfo.missionId);
      }
    }
    missionManager.moveMissionsToForeground(toShows, toShows[0], (err: BusinessError, data: void) => {
      if (err) {
        console.error(`moveMissionsToForeground failed: ${err.message}`);
      } else {
        console.info(`moveMissionsToForeground successfully: ${JSON.stringify(data)}`);
      }
    });
  });
} catch (paramError) {
  let code = (paramError as BusinessError).code;
  let message = (paramError as BusinessError).message;
  console.error(`error: ${code}, ${message} `);
}
```

## missionManager.moveMissionsToForeground<sup>10+</sup>

moveMissionsToForeground(missionIds: Array&lt;number&gt;, topMission?: number): Promise&lt;void&gt;

将指定任务批量切到前台，并将任务ID等于topMission的任务移动到最顶层，以promise的方式返回。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统接口**：此接口为系统接口。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | missionIds | Array&lt;number&gt; | 是 | 任务ID数组。 |
  | topMission | number | 否 | 待移动到最顶层的任务ID。默认值为-1，表示将默认任务移动到最顶层。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;void&gt; | promise方式返回执行结果。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**示例：**

```ts
import { abilityManager, missionManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  missionManager.getMissionInfos("", 10, (error: BusinessError, missionInfos: Array<missionManager.MissionInfo>) => {
    if (error.code) {
      console.error(`getMissionInfos failed, error code: ${error.code}, error msg: ${error.message}`);
      return;
    }
    if (missionInfos.length < 1) {
      return;
    }

    let toShows = new Array<number>();
    for (let missionInfo of missionInfos) {
      if (missionInfo.abilityState == abilityManager.AbilityState.BACKGROUND) {
        toShows.push(missionInfo.missionId);
      }
    }
    missionManager.moveMissionsToForeground(toShows, toShows[0]).then(() => {
      console.log(`moveMissionsToForeground is called`);
    });
  });
} catch (paramError) {
  let code = (paramError as BusinessError).code;
  let message = (paramError as BusinessError).message;
  console.error(`error: ${code}, ${message} `);
}
```

## missionManager.moveMissionsToBackground<sup>10+</sup>

moveMissionsToBackground(missionIds: Array&lt;number&gt;, callback: AsyncCallback&lt;Array&lt;number&gt;&gt;): void

将指定任务批量切到后台，以回调函数的方式返回，返回的结果任务ID按被隐藏时的任务层级排序。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统接口**：此接口为系统接口。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | missionIds | Array&lt;number&gt; | 是 | 任务ID数组。 |
  | callback | AsyncCallback&lt;Array&lt;number&gt;&gt; | 是 | 执行结果回调函数。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**示例：**

```ts
import { abilityManager, missionManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  missionManager.getMissionInfos("", 10, (error: BusinessError, missionInfos: Array<missionManager.MissionInfo>) => {
    if (error.code) {
      console.error(`getMissionInfos failed, error code: ${error.code}, error msg: ${error.message}`);
      return;
    }

    let toHides = new Array<number>();
    for (let missionInfo of missionInfos) {
      if (missionInfo.abilityState ==  abilityManager.AbilityState.FOREGROUND) {
        toHides.push(missionInfo.missionId);
      }
    }
    missionManager.moveMissionsToBackground(toHides, (err: BusinessError, data: Array<number>) => {
      if (err) {
        console.error(`moveMissionsToBackground failed: ${err.message}`);
      } else {
        console.info(`moveMissionsToBackground successfully: ${JSON.stringify(data)}`);
      }
    });
  });
} catch (paramError) {
  let code = (paramError as BusinessError).code;
  let message = (paramError as BusinessError).message;
  console.error(`error: ${code}, ${message} `);
}
```

## missionManager.moveMissionsToBackground<sup>10+</sup>

moveMissionsToBackground(missionIds : Array&lt;number&gt;): Promise&lt;Array&lt;number&gt;&gt;

将指定任务批量切到后台，以promise的方式返回，返回的结果按被隐藏时的任务层级排序。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统接口**：此接口为系统接口。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | missionIds | Array&lt;number&gt; | 是 | 任务ID数组。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;Array&lt;number&gt;&gt; | promise方式返回执行结果。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**示例：**

```ts
import { abilityManager, missionManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  missionManager.getMissionInfos("", 10, (error: BusinessError, missionInfos: Array<missionManager.MissionInfo>) => {
    if (error.code) {
      console.error(`getMissionInfos failed, error code: ${error.code}, error msg: ${error.message}`);
      return;
    }

    let toHides = new Array<number>();
    for (let missionInfo of missionInfos) {
      if (missionInfo.abilityState ==  abilityManager.AbilityState.FOREGROUND) {
        toHides.push(missionInfo.missionId);
      }
    }
    missionManager.moveMissionsToBackground(toHides).then((hideRes: Array<number>) => {
      console.log(`moveMissionsToBackground is called, res: ${JSON.stringify(hideRes)}`);
    });
  });
} catch (paramError) {
  let code = (paramError as BusinessError).code;
  let message = (paramError as BusinessError).message;
  console.error(`error: ${code}, ${message} `);
}
```