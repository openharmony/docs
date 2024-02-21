# @ohos.application.missionManager (missionManager)(系统接口)

missionManager模块提供系统任务管理能力，包括对系统任务执行锁定、解锁、清理、切换到前台等操作。

> **说明：**
> 
> 本模块首批接口从API version 8开始支持，从API version 9废弃，替换模块为[@ohos.app.ability.missionManager](js-apis-app-ability-missionManager-sys.md)。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口均为系统接口，三方应用不支持调用。

## 导入模块

```ts
import missionManager from '@ohos.application.missionManager';
```

## 权限列表

ohos.permission.MANAGE_MISSIONS

## missionManager.registerMissionListener

registerMissionListener(listener: MissionListener): number

注册系统任务状态监听器。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统接口**: 此接口为系统接口。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | listener | [MissionListener](js-apis-inner-application-missionListener-sys.md) | 是 | 系统任务监听器。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | number | 监听器的index值，由系统创建，在注册系统任务状态监听器时分配，和监听器一一对应&nbsp;。 |

**示例：**

```ts
import missionManager from '@ohos.application.missionManager';

console.log('registerMissionListener');
let listenerid = missionManager.registerMissionListener({
  onMissionCreated: (mission) => {console.log('--------onMissionCreated-------');},
  onMissionDestroyed: (mission) => {console.log('--------onMissionDestroyed-------');},
  onMissionSnapshotChanged: (mission) => {console.log('--------onMissionSnapshotChanged-------');},
  onMissionMovedToFront: (mission) => {console.log('--------onMissionMovedToFront-------');},
  onMissionIconUpdated: (mission, icon) => {console.log('--------onMissionIconUpdated-------');},
  onMissionClosed: (mission) => {console.log('--------onMissionClosed-------');},
  onMissionLabelUpdated: (mission) => {console.log('--------onMissionLabelUpdated-------');}
});
```


## missionManager.unregisterMissionListener

unregisterMissionListener(listenerId: number, callback: AsyncCallback&lt;void&gt;): void

解注册任务状态监听器。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统接口**: 此接口为系统接口。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | listenerId | number | 是 | 系统任务状态监听器的index值，和监听器一一对应，由registerMissionListener方法返回。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | 执行结果回调函数。 |

**示例：**

```ts
  import missionManager from '@ohos.application.missionManager';

  console.log('registerMissionListener');
  let listenerid = missionManager.registerMissionListener({
    onMissionCreated: (mission) => {console.log('--------onMissionCreated-------');},
    onMissionDestroyed: (mission) => {console.log('--------onMissionDestroyed-------');},
    onMissionSnapshotChanged: (mission) => {console.log('--------onMissionSnapshotChanged-------');},
    onMissionMovedToFront: (mission) => {console.log('--------onMissionMovedToFront-------');},
    onMissionIconUpdated: (mission, icon) => {console.log('--------onMissionIconUpdated-------');},
    onMissionClosed: (mission) => {console.log('--------onMissionClosed-------');},
    onMissionLabelUpdated: (mission) => {console.log('--------onMissionLabelUpdated-------');}
  });

  missionManager.unregisterMissionListener(listenerid, (error) => {
      console.error('unregisterMissionListener fail, error: ${error}');
  });
```


## missionManager.unregisterMissionListener

unregisterMissionListener(listenerId: number): Promise&lt;void&gt;

反注册任务状态监听器。使用Promise异步回调。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统接口**: 此接口为系统接口。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | listenerId | number | 是 | 系统任务状态监听器的index值，和监听器一一对应，由registerMissionListener方法返回。 |

**返回值：**

  | 类型 | 说明 | 
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 | 

**示例：**

```ts
  import missionManager from '@ohos.application.missionManager';
  import { BusinessError } from '@ohos.base';

  console.log('registerMissionListener');
  let listenerid = missionManager.registerMissionListener({
    onMissionCreated: (mission) => {console.log('--------onMissionCreated-------');},
    onMissionDestroyed: (mission) => {console.log('--------onMissionDestroyed-------');},
    onMissionSnapshotChanged: (mission) => {console.log('--------onMissionSnapshotChanged-------');},
    onMissionMovedToFront: (mission) => {console.log('--------onMissionMovedToFront-------');},
    onMissionIconUpdated: (mission, icon) => {console.log('--------onMissionIconUpdated-------');},
    onMissionClosed: (mission) => {console.log('--------onMissionClosed-------');},
    onMissionLabelUpdated: (mission) => {console.log('--------onMissionLabelUpdated-------');}
  });

  missionManager.unregisterMissionListener(listenerid).catch((error: BusinessError) => {
      console.error('unregisterMissionListener fail, error: ${error}');
  });
```


## missionManager.getMissionInfo

getMissionInfo(deviceId: string, missionId: number, callback: AsyncCallback&lt;MissionInfo&gt;): void

获取单个任务信息。使用callback异步回调。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统接口**: 此接口为系统接口。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | deviceId | string | 是 | 设备ID，本机默认为空字符串。 |
  | missionId | number | 是 | 任务ID。 |
  | callback | AsyncCallback&lt;[MissionInfo](js-apis-inner-application-missionInfo-sys.md)&gt; | 是 | 回调函数，返回任务信息。 |

**示例：**

  ```ts
  import missionManager from '@ohos.application.missionManager';

  let missionId: number = 0;

  missionManager.getMissionInfo('', missionId, (error, mission) => {
    if (error.code) {
      console.error(`getMissionInfo failed, error.code: ${error.code}, error.message: ${error.message}`);
      return;
    }

    console.log(`mission.missionId = ${mission.missionId}`);
    console.log(`mission.runningState = ${mission.runningState}`);
    console.log(`mission.lockedState = ${mission.lockedState}`);
    console.log(`mission.timestamp = ${mission.timestamp}`);
    console.log(`mission.label = ${mission.label}`);
    console.log(`mission.iconPath = ${mission.iconPath}`);
  });
  ```


## missionManager.getMissionInfo

getMissionInfo(deviceId: string, missionId: number): Promise&lt;MissionInfo&gt;

获取单个任务信息。使用Promise异步回调。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统接口**: 此接口为系统接口。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | deviceId | string | 是 | 设备ID，本机默认为空字符串。 |
  | missionId | number | 是 | 任务ID。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;[MissionInfo](js-apis-inner-application-missionInfo-sys.md)&gt; | Promise对象，返回任务信息。 |

**示例：**

  ```ts
  import missionManager from '@ohos.application.missionManager';
  import { BusinessError } from '@ohos.base';

  let testMissionId = 1;
try {
    missionManager.getMissionInfo('', testMissionId).then((data) => {
        console.info(`getMissionInfo successfully. Data: ${JSON.stringify(data)}`);
    }).catch((error: BusinessError) => {
        console.error(`getMissionInfo failed. Cause: ${error.message}`);
    });
} catch (error) {
    console.error(`getMissionInfo failed. Cause: ${error.message}`);
}
  ```


## missionManager.getMissionInfos

getMissionInfos(deviceId: string, numMax: number, callback: AsyncCallback&lt;Array&lt;MissionInfo&gt;&gt;): void

获取所有任务信息。使用callback异步回调。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统接口**: 此接口为系统接口。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | deviceId | string | 是 | 设备ID，本机默认为空字符串。 |
  | numMax | number | 是 | 任务信息数量上限。 |
  | callback | AsyncCallback&lt;Array&lt;[MissionInfo](js-apis-inner-application-missionInfo-sys.md)&gt;&gt; | 是 | 回调函数，返回任务信息数组。 |

**示例：**

  ```ts
  import missionManager from '@ohos.application.missionManager';

  missionManager.getMissionInfos('', 10, (error, missions) => {
      if (error.code) {
          console.error(`getMissionInfos failed, error.code: ${error.code}, error.message: ${error.message}`);
          return;
      }
      console.log(`size = ${missions.length}`);
      console.log(`missions = ${JSON.stringify(missions)}`);
  });
  ```


## missionManager.getMissionInfos

getMissionInfos(deviceId: string, numMax: number): Promise&lt;Array&lt;MissionInfo&gt;&gt;

获取所有任务信息。使用Promise异步回调。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统接口**: 此接口为系统接口。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | deviceId | string | 是 | 设备ID，本机默认为空字符串。 |
  | numMax | number | 是 | 任务信息数量上限。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;Array&lt;[MissionInfo](js-apis-inner-application-missionInfo-sys.md)&gt;&gt; | Promise对象，返回任务信息数组。 |

**示例：**

  ```ts
  import missionManager from '@ohos.application.missionManager';
  import { BusinessError } from '@ohos.base';

  try {
    missionManager.getMissionInfos('', 10).then((data) => {
        console.info(`getMissionInfos successfully. Data: ${JSON.stringify(data)}`);
    }).catch((error: BusinessError) => {
        console.error(`getMissionInfos failed. Cause: ${error.message}`);
    });
} catch (error) {
    console.error(`getMissionInfos failed. Cause: ${error.message}`);
}
  ```


## missionManager.getMissionSnapShot

getMissionSnapShot(deviceId: string, missionId: number, callback: AsyncCallback&lt;MissionSnapshot&gt;): void

获取任务快照。使用callback异步回调。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统接口**: 此接口为系统接口。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | deviceId | string | 是 | 设备ID，本机默认为空字符串。 |
  | missionId | number | 是 | 任务ID。 |
  | callback | AsyncCallback&lt;[MissionSnapshot](js-apis-inner-application-missionSnapshot-sys.md)&gt; | 是 | 回调函数，返回任务快照信息。 |

**示例：**

  ```ts
  import missionManager from '@ohos.application.missionManager';

  let testMissionId = 2;
try {
    missionManager.getMissionSnapShot('', testMissionId, (err, data) => {
        if (err) {
            console.error(`getMissionSnapShot failed: ${err.message}`);
        } else {
            console.info(`getMissionSnapShot successfully: ${JSON.stringify(data)}`);
        }
    });
} catch (err) {
    console.error(`getMissionSnapShot failed: ${err.message}`);
}
  ```


## missionManager.getMissionSnapShot

getMissionSnapShot(deviceId: string, missionId: number): Promise&lt;MissionSnapshot&gt;

获取任务快照。使用Promise异步回调。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统接口**: 此接口为系统接口。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | deviceId | string | 是 | 设备ID，本机默认为空字符串。 |
  | missionId | number | 是 | 任务ID。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;[MissionSnapshot](js-apis-inner-application-missionSnapshot-sys.md)&gt; | Promise对象，返回任务快照信息。 |

**示例：**

  ```ts
  import missionManager from '@ohos.application.missionManager';
  import { BusinessError } from '@ohos.base';

  let testMissionId = 2;
try {
    missionManager.getMissionSnapShot('', testMissionId).then((data) => {
        console.info(`getMissionSnapShot successfully. Data: ${JSON.stringify(data)}`);
    }).catch((error: BusinessError) => {
        console.error(`getMissionSnapShot failed. Cause: ${error.message}`);
    });
} catch (error) {
    console.error(`getMissionSnapShot failed. Cause: ${error.message}`);
}
  ```

## missionManager.lockMission

lockMission(missionId: number, callback: AsyncCallback&lt;void&gt;): void

锁定指定任务id的任务。使用callback异步回调。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统接口**: 此接口为系统接口。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | missionId | number | 是 | 任务ID。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，当锁定指定任务id的任务成功，err为undefined，否则为错误对象。 |

**示例：**

  ```ts
  import missionManager from '@ohos.application.missionManager';

  let testMissionId = 2;
try {
    missionManager.lockMission(testMissionId, (err, data) => {
        if (err) {
            console.error(`lockMission failed: ${err.message}`);
        } else {
            console.info(`lockMission successfully: ${JSON.stringify(data)}`);
        }
    });
} catch (err) {
    console.error(`lockMission failed: ${err.message}`);
}
  ```


## missionManager.lockMission

lockMission(missionId: number): Promise&lt;void&gt;

锁定指定任务id的任务。使用Promise异步回调。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统接口**: 此接口为系统接口。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | missionId | number | 是 | 任务ID。 |

**返回值：**

  | 类型 | 说明 | 
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 | 

**示例：**

  ```ts
  import missionManager from '@ohos.application.missionManager';
  import { BusinessError } from '@ohos.base';

  let testMissionId = 2;
try {
    missionManager.lockMission(testMissionId).then((data) => {
        console.info(`lockMission successfully. Data: ${JSON.stringify(data)}`);
    }).catch((error: BusinessError) => {
        console.error(`lockMission failed. Cause: ${error.message}`);
    });
} catch (error) {
    console.error(`lockMission failed. Cause: ${error.message}`);
}
  ```


## missionManager.unlockMission

unlockMission(missionId: number, callback: AsyncCallback&lt;void&gt;): void

解锁指定任务id的任务。使用callback异步回调。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| missionId | number | 是 | 任务ID。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，当解锁指定任务id的任务成功，err为undefined，否则为错误对象。 |

**示例：**

  ```ts
  import missionManager from '@ohos.application.missionManager';

  let testMissionId = 2;
try {
    missionManager.unlockMission(testMissionId, (err, data) => {
        if (err) {
            console.error(`unlockMission failed: ${err.message}`);
        } else {
            console.info(`unlockMission successfully: ${JSON.stringify(data)}`);
        }
    });
} catch (err) {
    console.error(`unlockMission failed: ${err.message}`);
}
  ```


## missionManager.unlockMission

unlockMission(missionId: number): Promise&lt;void&gt;

解锁指定任务id的任务。使用Promise异步回调。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统接口**: 此接口为系统接口。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | missionId | number | 是 | 任务ID。 |

**返回值：**

  | 类型 | 说明 | 
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 | 

**示例：**

  ```ts
  import missionManager from '@ohos.application.missionManager';
  import { BusinessError } from '@ohos.base';

  let testMissionId = 2;
try {
    missionManager.unlockMission(testMissionId).then((data) => {
        console.info(`unlockMission successfully. Data: ${JSON.stringify(data)}`);
    }).catch((error: BusinessError) => {
        console.error(`unlockMission failed. Cause: ${error.message}`);
    });
} catch (error) {
    console.error(`unlockMission failed. Cause: ${error.message}`);
}
  ```


## missionManager.clearMission

clearMission(missionId: number, callback: AsyncCallback&lt;void&gt;): void

清理指定任务id的任务，无论该任务是否被锁定。使用callback异步回调。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统接口**: 此接口为系统接口。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | missionId | number | 是 | 任务ID。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，当清理指定任务id的任务成功，err为undefined，否则为错误对象。 |

**示例：**

  ```ts
  import missionManager from '@ohos.application.missionManager';

  let testMissionId = 2;
try {
    missionManager.clearMission(testMissionId, (err, data) => {
        if (err) {
            console.error(`clearMission failed: ${err.message}`);
        } else {
            console.info(`clearMission successfully: ${JSON.stringify(data)}`);
        }
    });
} catch (err) {
    console.error(`clearMission failed: ${err.message}`);
}
  ```


## missionManager.clearMission

clearMission(missionId: number): Promise&lt;void&gt;

清理指定任务id的任务，无论该任务是否被锁定。使用Promise异步回调。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统接口**: 此接口为系统接口。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | missionId | number | 是 | 任务ID。 |

**返回值：**

  | 类型 | 说明 | 
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 | 

**示例：**

  ```ts
  import missionManager from '@ohos.application.missionManager';
  import { BusinessError } from '@ohos.base';

  let testMissionId = 2;
try {
    missionManager.clearMission(testMissionId).then((data) => {
        console.info(`clearMission successfully. Data: ${JSON.stringify(data)}`);
    }).catch((error: BusinessError) => {
        console.error(`clearMission failed. Cause: ${error.message}`);
    });
} catch (error) {
    console.error(`clearMission failed. Cause: ${error.message}`);
}
  ```


## missionManager.clearAllMissions

clearAllMissions(callback: AsyncCallback&lt;void&gt;): void

清理所有未锁定的任务，使用callback异步回调。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统接口**: 此接口为系统接口。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，当清理所有未锁定的任务成功，err为undefined，否则为错误对象。 |

**示例：**

  ```ts
  import missionManager from '@ohos.application.missionManager'

  try {
    missionManager.clearAllMissions(err => {
        if (err) {
            console.error('clearAllMissions failed: ${err.message}');
        } else {
            console.info('clearAllMissions successfully.');
        }
    });
} catch (err) {
    console.error('clearAllMissions failed: ${err.message}');
}
  ```


## missionManager.clearAllMissions

clearAllMissions(): Promise&lt;void&gt;

清理所有未锁定的任务。使用Promise异步回调。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统接口**: 此接口为系统接口。

**返回值：**

  | 类型 | 说明 | 
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 | 

**示例：**

  ```ts
  import missionManager from '@ohos.application.missionManager';
  import { BusinessError } from '@ohos.base';

  try {
    missionManager.clearAllMissions().then((data) => {
        console.info(`clearAllMissions successfully. Data: ${JSON.stringify(data)}`);
    }).catch((err: BusinessError) => {
        console.error(`clearAllMissions failed: ${err.message}`);
    });
} catch (err) {
    console.error(`clearAllMissions failed: ${err.message}`);
}
  ```


## missionManager.moveMissionToFront

moveMissionToFront(missionId: number, callback: AsyncCallback&lt;void&gt;): void

把指定任务id的任务切到前台。使用callback异步回调。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统接口**: 此接口为系统接口。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | missionId | number | 是 | 任务ID。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，当把指定任务id的任务切到前台成功，err为undefined，否则为错误对象。 |

**示例：**

  ```ts
  import missionManager from '@ohos.application.missionManager';

  let testMissionId = 2;
try {
    missionManager.moveMissionToFront(testMissionId, (err, data) => {
        if (err) {
            console.error(`moveMissionToFront failed: ${err.message}`);
        } else {
            console.info(`moveMissionToFront successfully: ${JSON.stringify(data)}`);
        }
    });
} catch (err) {
    console.error(`moveMissionToFront failed: ${err.message}`);
}
  ```


## missionManager.moveMissionToFront

moveMissionToFront(missionId: number, options: StartOptions, callback: AsyncCallback&lt;void&gt;): void

把指定任务id的任务切到前台，同时指定任务切换到前台时的启动参数，例如窗口模式、设备ID等。使用callback异步回调。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统接口**: 此接口为系统接口。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | missionId | number | 是 | 任务ID。 |
  | options | [StartOptions](js-apis-app-ability-startOptions.md) | 是 | 启动参数选项，用于指定任务切到前台时的窗口模式，设备ID等。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，当把指定任务id的任务切到前台成功，err为undefined，否则为错误对象。 |

**示例：**

  ```ts
  import missionManager from '@ohos.application.missionManager';

  let testMissionId = 2;
try {
    missionManager.moveMissionToFront(testMissionId, {windowMode : 101}, (err, data) => {
        if (err) {
            console.error(`moveMissionToFront failed: ${err.message}`);
        } else {
            console.info(`moveMissionToFront successfully: ${JSON.stringify(data)}`);
        }
    });
} catch (err) {
    console.error(`moveMissionToFront failed: ${err.message}`);
}
  ```


## missionManager.moveMissionToFront

moveMissionToFront(missionId: number, options?: StartOptions): Promise&lt;void&gt;

把指定任务id的任务切到前台，同时指定任务切换到前台时的启动参数，例如窗口模式、设备ID等。使用Promise异步回调。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统接口**: 此接口为系统接口。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | missionId | number | 是 | 任务ID。 |
  | options | [StartOptions](js-apis-app-ability-startOptions.md) | 否 | 启动参数选项，用于指定任务切到前台时的窗口模式，设备ID等。 |

**返回值：**

  | 类型 | 说明 | 
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 | 

**示例：**

  ```ts
  import missionManager from '@ohos.application.missionManager';
  import { BusinessError } from '@ohos.base';

  let testMissionId = 2;
try {
    missionManager.moveMissionToFront(testMissionId).then((data) => {
        console.info(`moveMissionToFront successfully. Data: ${JSON.stringify(data)}`);
    }).catch((error: BusinessError) => {
        console.error(`moveMissionToFront failed. Cause: ${error.message}`);
    });
} catch (error) {
    console.error(`moveMissionToFront failed. Cause: ${error.message}`);
}
  ```