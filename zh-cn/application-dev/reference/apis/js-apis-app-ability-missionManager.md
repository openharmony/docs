# @ohos.app.ability.missionManager (missionManager)

missionManager模块提供系统任务管理能力，包括对系统任务执行锁定、解锁、清理、切换到前台等操作。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import missionManager from '@ohos.app.ability.missionManager';
```

## 权限列表

ohos.permission.MANAGE_MISSIONS

## missionManager.on

on(type:'mission', listener: MissionListener): number;

注册系统任务状态监听器。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | listener | [MissionListener](js-apis-inner-application-missionListener.md) | 是 | 系统任务监听器。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | number | 监听器的index值，由系统创建，在注册系统任务状态监听时分配，和监听器一一对应&nbsp;。 |

**示例：**

```ts
import missionManager from '@ohos.app.ability.missionManager';
import UIAbility from '@ohos.app.ability.UIAbility';

let listener = {
    onMissionCreated: function (mission) {console.log('--------onMissionCreated-------');},
    onMissionDestroyed: function (mission) {console.log('--------onMissionDestroyed-------');},
    onMissionSnapshotChanged: function (mission) {console.log('--------onMissionSnapshotChanged-------');},
    onMissionMovedToFront: function (mission) {console.log('--------onMissionMovedToFront-------');},
    onMissionIconUpdated: function (mission, icon) {console.log('--------onMissionIconUpdated-------');},
    onMissionClosed: function (mission) {console.log('--------onMissionClosed-------');},
    onMissionLabelUpdated: function (mission) {console.log('--------onMissionLabelUpdated-------');}
};

let listenerId = -1;

export default class EntryAbility extends UIAbility {
    onCreate(want, launchParam) {
        console.log('[Demo] EntryAbility onCreate');
        globalThis.abilityWant = want;
        globalThis.context = this.context;
    }

    onDestroy() {
        try {
            if (listenerId !== -1) {
                missionManager.off('mission', listenerId).catch(function (err) {
                    console.log(err);
                });
            }
        } catch (paramError) {
            console.error('error: ${paramError.code}, ${paramError.message}');
        }
        console.log('[Demo] EntryAbility onDestroy');
    }

    onWindowStageCreate(windowStage) {
        // Main window is created, set main page for this ability
        console.log('[Demo] EntryAbility onWindowStageCreate');
        try {
            listenerId = missionManager.on('mission', listener);
        } catch (paramError) {
            console.error('error: ${paramError.code}, ${paramError.message}');
        }

        windowStage.loadContent('pages/index', (err, data) => {
            if (err.code) {
                console.error('Failed to load the content. Cause: ${JSON.stringify(err)}');
                return;
            }
            console.info('Succeeded in loading the content. Data: ${JSON.stringify(data)}');
        });

        if (globalThis.flag) {
            return;
        }
    }
};
```


## missionManager.off

off(type: 'mission', listenerId: number, callback: AsyncCallback&lt;void&gt;): void;

解注册任务状态监听器。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | listenerId | number | 是 | 系统任务状态监器法的index值，和监听器一一对应，由on方法返回。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | 执行结果回调函数。 |

**错误码**：

| 错误码ID | 错误信息 |
| ------- | -------- |
| 16300002 | Input error. The specified mission listener does not exist. |

以上错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)。

**示例：**

```ts
import missionManager from '@ohos.app.ability.missionManager';
import UIAbility from '@ohos.app.ability.UIAbility';

let listener = {
    onMissionCreated: function (mission) {console.log('--------onMissionCreated-------');},
    onMissionDestroyed: function (mission) {console.log('--------onMissionDestroyed-------');},
    onMissionSnapshotChanged: function (mission) {console.log('--------onMissionSnapshotChanged-------');},
    onMissionMovedToFront: function (mission) {console.log('--------onMissionMovedToFront-------');},
    onMissionIconUpdated: function (mission, icon) {console.log('--------onMissionIconUpdated-------');},
    onMissionClosed: function (mission) {console.log('--------onMissionClosed-------');},
    onMissionLabelUpdated: function (mission) {console.log('--------onMissionLabelUpdated-------');}
};

let listenerId = -1;

export default class EntryAbility extends UIAbility {
    onCreate(want, launchParam) {
        console.log('[Demo] EntryAbility onCreate');
        globalThis.abilityWant = want;
        globalThis.context = this.context;
    }

    onDestroy() {
        try {
            if (listenerId !== -1) {
                missionManager.off('mission', listenerId, (err) => {
                    console.log(err);
                });
            }
        } catch (paramError) {
            console.error('error: ${paramError.code}, ${paramError.message}');
        }
        console.log('[Demo] EntryAbility onDestroy');
    }

    onWindowStageCreate(windowStage) {
        // Main window is created, set main page for this ability
        console.log('[Demo] EntryAbility onWindowStageCreate');
        try {
            listenerId = missionManager.on('mission', listener);
        } catch (paramError) {
            console.error('error: ${paramError.code}, ${paramError.message}');
        }

        windowStage.loadContent('pages/index', (err, data) => {
            if (err.code) {
                console.error('Failed to load the content. Cause: ${JSON.stringify(err)}');
                return;
            }
            console.info('Succeeded in loading the content. Data: ${JSON.stringify(data)}');
        });

        if (globalThis.flag) {
            return;
        }
    }
};
```


## missionManager.off

off(type: 'mission', listenerId: number): Promise&lt;void&gt;;

解注册任务状态监听，以promise方式返回执行结果。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | listenerId | number | 是 | 系统任务状态监听器的index值，和监听器一一对应，由on方法返回。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;void&gt; | promise方式返回执行结果。 |

**错误码**：

| 错误码ID | 错误信息 |
| ------- | -------- |
| 16300002 | Input error. The specified mission listener does not exist. |

以上错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)。

**示例：**

```ts
import missionManager from '@ohos.app.ability.missionManager';
import UIAbility from '@ohos.app.ability.UIAbility';

let listener = {
    onMissionCreated: function (mission) {console.log('--------onMissionCreated-------');},
    onMissionDestroyed: function (mission) {console.log('--------onMissionDestroyed-------');},
    onMissionSnapshotChanged: function (mission) {console.log('--------onMissionSnapshotChanged-------');},
    onMissionMovedToFront: function (mission) {console.log('--------onMissionMovedToFront-------');},
    onMissionIconUpdated: function (mission, icon) {console.log('--------onMissionIconUpdated-------');},
    onMissionClosed: function (mission) {console.log('--------onMissionClosed-------');},
    onMissionLabelUpdated: function (mission) {console.log('--------onMissionLabelUpdated-------');}
};

let listenerId = -1;

export default class EntryAbility extends UIAbility {
    onCreate(want, launchParam) {
        console.log('[Demo] EntryAbility onCreate');
        globalThis.abilityWant = want;
        globalThis.context = this.context;
    }

    onDestroy() {
        try {
            if (listenerId !== -1) {
                missionManager.off('mission', listenerId).catch(function (err) {
                    console.log(err);
                });
            }
        } catch (paramError) {
            console.error('error: ${paramError.code}, ${paramError.message}');
        }
        console.log('[Demo] EntryAbility onDestroy');
    }

    onWindowStageCreate(windowStage) {
        // Main window is created, set main page for this ability
        console.log('[Demo] EntryAbility onWindowStageCreate');
        try {
            listenerId = missionManager.on('mission', listener);
        } catch (paramError) {
            console.error('error: ${paramError.code}, ${paramError.message}');
        }

        windowStage.loadContent('pages/index', (err, data) => {
            if (err.code) {
                console.error('Failed to load the content. Cause: ${JSON.stringify(err)}');
                return;
            }
            console.info('Succeeded in loading the content. Data: ${JSON.stringify(data)}');
        });

        if (globalThis.flag) {
            return;
        }
    }
};
```


## missionManager.getMissionInfo

getMissionInfo(deviceId: string, missionId: number, callback: AsyncCallback&lt;MissionInfo&gt;): void;

获取任务信息，以异步回调的方式返回任务信息。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | deviceId | string | 是 | 设备ID，本机默认为空字符串。 |
  | missionId | number | 是 | 任务ID。 |
  | callback | AsyncCallback&lt;[MissionInfo](./js-apis-inner-application-missionInfo.md)&gt; | 是 | 执行结果回调函数，返回任务信息。 |

**示例：**

  ```ts
    import missionManager from '@ohos.app.ability.missionManager';

    let testMissionId = 1;

    missionManager.getMissionInfos('',10)
    .then((allMissions) => {
        try {
        if (allMissions && allMissions.length > 0) {
            testMissionId = allMissions[0].missionId;
        }

        missionManager.getMissionInfo('', testMissionId, (error, mission) => {
            if (error) {
            console.error('getMissionInfo failed, error.code: ${error.code}, error.message: ${error.message}');
            } else {
            console.log('mission.missionId = ${mission.missionId}');
            console.log('mission.runningState = ${mission.runningState}');
            console.log('mission.lockedState = ${mission.lockedState}');
            console.log('mission.timestamp = ${mission.timestamp}');
            console.log('mission.label = ${mission.label}');
            console.log('mission.iconPath = ${mission.iconPath}');
            }
        });
        } catch (paramError) {
        console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');
        }
    })
    .catch(function(err){console.log(err);});
  ```

## missionManager.getMissionInfo

getMissionInfo(deviceId: string, missionId: number): Promise&lt;MissionInfo&gt;;

获取任务信息，以promise方式返回任务信息。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | deviceId | string | 是 | 设备ID，本机默认为空字符串。 |
  | missionId | number | 是 | 任务ID。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;[MissionInfo](./js-apis-inner-application-missionInfo.md)&gt; | 任务信息。 |

**示例：**

```ts
import missionManager from '@ohos.app.ability.missionManager';

let testMissionId = 1;
try {
    missionManager.getMissionInfo('', testMissionId).then((data) => {
        console.info('getMissionInfo successfully. Data: ${JSON.stringify(data)}');
    }).catch(error => {
        console.error('getMissionInfo failed. Cause: ${error.message}');
    });
} catch (error) {
    console.error('getMissionInfo failed. Cause: ${error.message}');
}
```

## missionManager.getMissionInfos

getMissionInfos(deviceId: string, numMax: number, callback: AsyncCallback&lt;Array&lt;MissionInfo&gt;&gt;): void;

获取所有任务信息，以回调函数的方式返回任务信息数组。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | deviceId | string | 是 | 设备ID，本机默认为空字符串。 |
  | numMax | number | 是 | 任务信息数量上限。 |
  | callback | AsyncCallback&lt;Array&lt;[MissionInfo](./js-apis-inner-application-missionInfo.md)&gt;&gt; | 是 | 执行结果回调函数，返回任务信息数组。 |

**示例：**

  ```ts
  import missionManager from '@ohos.app.ability.missionManager';

  try {
    missionManager.getMissionInfos('', 10, (error, missions) => {
      if (error) {
          console.error('getMissionInfos failed, error.code: ${error.code}, error.message: ${error.message}');
      } else {
        console.log('size = ${missions.length}');
        console.log('missions = ${JSON.stringify(missions)}');
      }
    });
  } catch (paramError) {
    console.error('error: ${paramError.code}, ${paramError.message}');
  }
  ```


## missionManager.getMissionInfos

getMissionInfos(deviceId: string, numMax: number): Promise&lt;Array&lt;MissionInfo&gt;&gt;;

获取所有任务信息，以promise的方式返回任务信息数组。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | deviceId | string | 是 | 设备ID，本机默认为空字符串。 |
  | numMax | number | 是 | 任务信息数量上限。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;Array&lt;[MissionInfo](./js-apis-inner-application-missionInfo.md)&gt;&gt; | 任务信息数组。 |

**示例：**

```ts
import missionManager from '@ohos.app.ability.missionManager';

try {
    missionManager.getMissionInfos('', 10).then((data) => {
        console.info('getMissionInfos successfully. Data: ${JSON.stringify(data)}');
    }).catch(error => {
        console.error('getMissionInfos failed. Cause: ${error.message}');
    });
} catch (error) {
    console.error('getMissionInfos failed. Cause: ${error.message}');
}
```

## missionManager.getMissionSnapShot

getMissionSnapShot(deviceId: string, missionId: number, callback: AsyncCallback&lt;MissionSnapshot&gt;): void;

获取任务快照，以回调函数的方式返回快照内容。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | deviceId | string | 是 | 设备ID，本机默认为空字符串。 |
  | missionId | number | 是 | 任务ID。 |
  | callback | AsyncCallback&lt;[MissionSnapshot](js-apis-inner-application-missionSnapshot.md)&gt; | 是 | 执行结果回调函数，返回任务快照信息。 |

**示例：**
```ts
import missionManager from '@ohos.app.ability.missionManager';

let testMissionId = 2;
try {
    missionManager.getMissionSnapShot('', testMissionId, (err, data) => {
        if (err) {
            console.error('getMissionSnapShot failed: ${err.message}');
        } else {
            console.info('getMissionSnapShot successfully: ${JSON.stringify(data)}');
        }
    });
} catch (err) {
    console.error('getMissionSnapShot failed: ${err.message}');
}
```

## missionManager.getMissionSnapShot

getMissionSnapShot(deviceId: string, missionId: number): Promise&lt;MissionSnapshot&gt;;

获取任务快照，以promise的方式返回快照内容。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | deviceId | string | 是 | 设备ID，本机默认为空字符串。 |
  | missionId | number | 是 | 任务ID。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;[MissionSnapshot](js-apis-inner-application-missionSnapshot.md)&gt; | 任务快照信息。 |

**示例：**
```ts
import missionManager from '@ohos.app.ability.missionManager';

let testMissionId = 2;
try {
    missionManager.getMissionSnapShot('', testMissionId).then((data) => {
        console.info('getMissionSnapShot successfully. Data: ${JSON.stringify(data)}');
    }).catch(error => {
        console.error('getMissionSnapShot failed. Cause: ${error.message}');
    });
} catch (error) {
    console.error('getMissionSnapShot failed. Cause: ${error.message}');
}
```

## missionManager.getLowResolutionMissionSnapShot

getLowResolutionMissionSnapShot(deviceId: string, missionId: number, callback: AsyncCallback\<MissionSnapshot>): void;

获取任务低分辨率快照。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | deviceId | string | 是 | 设备ID，本机默认为空字符串。 |
  | missionId | number | 是 | 任务ID。 |
  | callback | AsyncCallback&lt;[MissionSnapshot](js-apis-inner-application-missionSnapshot.md)&gt; | 是 | 执行结果回调函数，返回任务快照信息。 |

**示例：**
```ts
import missionManager from '@ohos.app.ability.missionManager';

let testMissionId = 2;
try {
    missionManager.getLowResolutionMissionSnapShot('', testMissionId, (err, data) => {
        if (err) {
            console.error('getLowResolutionMissionSnapShot failed: ${err.message}');
        } else {
            console.info('getLowResolutionMissionSnapShot successfully: ${JSON.stringify(data)}');
        }
    });
} catch (err) {
    console.error('getLowResolutionMissionSnapShot failed: ${err.message}');
}
```

## missionManager.getLowResolutionMissionSnapShot

getLowResolutionMissionSnapShot(deviceId: string, missionId: number): Promise\<MissionSnapshot>;

获取任务低分辨率快照。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | deviceId | string | 是 | 设备ID，本机默认为空字符串。 |
  | missionId | number | 是 | 任务ID。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;[MissionSnapshot](js-apis-inner-application-missionSnapshot.md)&gt; | 任务快照信息。 |

**示例：**

```ts
import missionManager from '@ohos.app.ability.missionManager';

let testMissionId = 2;
try {
    missionManager.getLowResolutionMissionSnapShot('', testMissionId).then((data) => {
        console.info('getLowResolutionMissionSnapShot successfully. Data: ${JSON.stringify(data)}');
    }).catch(error => {
        console.error('getLowResolutionMissionSnapShot failed. Cause: ${error.message}');
    });
} catch (error) {
    console.error('getLowResolutionMissionSnapShot failed. Cause: ${error.message}');
}
```


## missionManager.lockMission

lockMission(missionId: number, callback: AsyncCallback&lt;void&gt;): void;

锁定指定任务id的任务，以回调函数的方式返回。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | missionId | number | 是 | 任务ID。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | 执行结果回调函数。 |

**错误码**：

| 错误码ID | 错误信息 |
| ------- | -------- |
| 16300001 | Mission not found. |

以上错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)。

**示例：**

```ts
import missionManager from '@ohos.app.ability.missionManager';

let testMissionId = 2;
try {
    missionManager.lockMission(testMissionId, (err, data) => {
        if (err) {
            console.error('lockMission failed: ${err.message}');
        } else {
            console.info('lockMission successfully: ${JSON.stringify(data)}');
        }
    });
} catch (err) {
    console.error('lockMission failed: ${err.message}');
}
```

## missionManager.lockMission

lockMission(missionId: number): Promise&lt;void&gt;;

锁定指定任务id的任务，以promise方式返回。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | missionId | number | 是 | 任务ID。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;void&gt; | promise方式返回执行结果。 |

**错误码**：

| 错误码ID | 错误信息 |
| ------- | -------- |
| 16300001 | Mission not found. |

以上错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)。

**示例：**
```ts
import missionManager from '@ohos.app.ability.missionManager';

let testMissionId = 2;
try {
    missionManager.lockMission(testMissionId).then((data) => {
        console.info('lockMission successfully. Data: ${JSON.stringify(data)}');
    }).catch(error => {
        console.error('lockMission failed. Cause: ${error.message}');
    });
} catch (error) {
    console.error('lockMission failed. Cause: ${error.message}');
}
```

## missionManager.unlockMission

unlockMission(missionId: number, callback: AsyncCallback&lt;void&gt;): void;

解锁指定任务id的任务，以回调函数的方式返回。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| missionId | number | 是 | 任务ID。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 执行结果回调函数。 |

**错误码**：

| 错误码ID | 错误信息 |
| ------- | -------- |
| 16300001 | Mission not found. |

以上错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)。

**示例：**
```ts
import missionManager from '@ohos.app.ability.missionManager';

let testMissionId = 2;
try {
    missionManager.unlockMission(testMissionId, (err, data) => {
        if (err) {
            console.error('unlockMission failed: ${err.message}');
        } else {
            console.info('unlockMission successfully: ${JSON.stringify(data)}');
        }
    });
} catch (err) {
    console.error('unlockMission failed: ${err.message}');
}
```

## missionManager.unlockMission

unlockMission(missionId: number): Promise&lt;void&gt;;

解锁指定任务id的任务，以promise的方式返回。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | missionId | number | 是 | 任务ID。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;void&gt; | promise方式返回执行结果。 |

**错误码**：

| 错误码ID | 错误信息 |
| ------- | -------- |
| 16300001 | Mission not found. |

以上错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)。

**示例：**

```ts
import missionManager from '@ohos.app.ability.missionManager';

let testMissionId = 2;
try {
    missionManager.unlockMission(testMissionId).then((data) => {
        console.info('unlockMission successfully. Data: ${JSON.stringify(data)}');
    }).catch(error => {
        console.error('unlockMission failed. Cause: ${error.message}');
    });
} catch (error) {
    console.error('unlockMission failed. Cause: ${error.message}');
}
```

## missionManager.clearMission

clearMission(missionId: number, callback: AsyncCallback&lt;void&gt;): void;

清理指定任务id的任务，无论该任务是否被锁定，以回调函数的方式返回。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | missionId | number | 是 | 任务ID。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | 执行结果回调函数。 |

**示例：**

```ts
import missionManager from '@ohos.app.ability.missionManager';

let testMissionId = 2;
try {
    missionManager.clearMission(testMissionId, (err, data) => {
        if (err) {
            console.error('clearMission failed: ${err.message}');
        } else {
            console.info('clearMission successfully: ${JSON.stringify(data)}');
        }
    });
} catch (err) {
    console.error('clearMission failed: ${err.message}');
}
```


## missionManager.clearMission

clearMission(missionId: number): Promise&lt;void&gt;;

清理指定任务id的任务，无论该任务是否被锁定，以promise的方式返回。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | missionId | number | 是 | 任务ID。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;void&gt; | promise方式返回执行结果。 |

**示例：**

```ts
import missionManager from '@ohos.app.ability.missionManager';

let testMissionId = 2;
try {
    missionManager.clearMission(testMissionId).then((data) => {
        console.info('clearMission successfully. Data: ${JSON.stringify(data)}');
    }).catch(error => {
        console.error('clearMission failed. Cause: ${error.message}');
    });
} catch (error) {
    console.error('clearMission failed. Cause: ${error.message}');
}
```

## missionManager.clearAllMissions

clearAllMissions(callback: AsyncCallback&lt;void&gt;): void;

清理所有未锁定的任务，以回调函数的方式返回。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统API**: 此接口为系统接口，三方应用不支持调用。

**示例：**

```ts
import missionManager from '@ohos.app.ability.missionManager';

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

clearAllMissions(): Promise&lt;void&gt;;

清理所有未锁定的任务，以promise的方式返回。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统API**: 此接口为系统接口，三方应用不支持调用。

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;void&gt; | promise方式返回执行结果。 |

**示例：**

```ts
import missionManager from '@ohos.app.ability.missionManager';

try {
    missionManager.clearAllMissions(bundleName).then((data) => {
        console.info('clearAllMissions successfully. Data: ${JSON.stringify(data)}');
    }).catch(err => {
        console.error('clearAllMissions failed: ${err.message}');
    });
} catch (err) {
    console.error('clearAllMissions failed: ${err.message}');
}
```

## missionManager.moveMissionToFront

moveMissionToFront(missionId: number, callback: AsyncCallback&lt;void&gt;): void;

把指定任务id的任务切到前台，以回调函数的方式返回。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | missionId | number | 是 | 任务ID。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | 执行结果回调函数。 |

**错误码**：

| 错误码ID | 错误信息 |
| ------- | -------- |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |

以上错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)。

**示例：**

```ts
import missionManager from '@ohos.app.ability.missionManager';

let testMissionId = 2;
try {
    missionManager.moveMissionToFront(testMissionId, (err, data) => {
        if (err) {
            console.error('moveMissionToFront failed: ${err.message}');
        } else {
            console.info('moveMissionToFront successfully: ${JSON.stringify(data)}');
        }
    });
} catch (err) {
    console.error('moveMissionToFront failed: ${err.message}');
}
```

## missionManager.moveMissionToFront

moveMissionToFront(missionId: number, options: StartOptions, callback: AsyncCallback&lt;void&gt;): void;

把指定任务id的任务切到前台，同时指定任务切换到前台时的启动参数，例如窗口模式、设备ID等，以回调函数的方式返回。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | missionId | number | 是 | 任务ID。 |
  | options | [StartOptions](js-apis-app-ability-startOptions.md) | 是 | 启动参数选项，用于指定任务切到前台时的窗口模式，设备ID等。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | 执行结果回调函数。 |

**错误码**：

| 错误码ID | 错误信息 |
| ------- | -------- |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |

以上错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)。

**示例：**

```ts
import missionManager from '@ohos.app.ability.missionManager';

let testMissionId = 2;
try {
    missionManager.moveMissionToFront(testMissionId, {windowMode : 101}, (err, data) => {
        if (err) {
            console.error('moveMissionToFront failed: ${err.message}');
        } else {
            console.info('moveMissionToFront successfully: ${JSON.stringify(data)}');
        }
    });
} catch (err) {
    console.error('moveMissionToFront failed: ${err.message}');
}
```

## missionManager.moveMissionToFront

moveMissionToFront(missionId: number, options?: StartOptions): Promise&lt;void&gt;;

把指定任务id的任务切到前台，同时指定任务切换到前台时的启动参数，例如窗口模式、设备ID等，以promise的方式返回。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | missionId | number | 是 | 任务ID。 |
  | options | [StartOptions](js-apis-app-ability-startOptions.md) | 否 | 启动参数选项，用于指定任务切到前台时的窗口模式，设备ID等。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;void&gt; | promise方式返回执行结果。 |

**错误码**：

| 错误码ID | 错误信息 |
| ------- | -------- |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |

以上错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)。

**示例：**

```ts
import missionManager from '@ohos.app.ability.missionManager';

let testMissionId = 2;
try {
    missionManager.moveMissionToFront(testMissionId).then((data) => {
        console.info('moveMissionToFront successfully. Data: ${JSON.stringify(data)}');
    }).catch(error => {
        console.error('moveMissionToFront failed. Cause: ${error.message}');
    });
} catch (error) {
    console.error('moveMissionToFront failed. Cause: ${error.message}');
}
```
