# @ohos.app.ability.missionManager (missionManager)

The **missionManager** module provides APIs to lock, unlock, and clear missions, and switch a mission to the foreground.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import missionManager from '@ohos.app.ability.missionManager';
```

## Required Permissions

ohos.permission.MANAGE_MISSIONS

## missionManager.on

on(type:'mission', listener: MissionListener): number;

Registers a listener to observe the mission status.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | listener | [MissionListener](js-apis-inner-application-missionListener.md) | Yes| Mission status listener to register.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | number | Index of the mission status listener, which is created by the system and allocated when the listener is registered.|

**Example**

```ts
import missionManager from '@ohos.app.ability.missionManager';
import UIAbility from '@ohos.app.ability.UIAbility';
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
import common from '@ohos.app.ability.common';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';
import window from '@ohos.window';

let listener: missionManager.MissionListener = {
    onMissionCreated: (mission) => {console.log('--------onMissionCreated-------');},
    onMissionDestroyed: (mission) => {console.log('--------onMissionDestroyed-------');},
    onMissionSnapshotChanged: (mission) => {console.log('--------onMissionSnapshotChanged-------');},
    onMissionMovedToFront: (mission) => {console.log('--------onMissionMovedToFront-------');},
    onMissionIconUpdated: (mission, icon) => {console.log('--------onMissionIconUpdated-------');},
    onMissionClosed: (mission) => {console.log('--------onMissionClosed-------');},
    onMissionLabelUpdated: (mission) => {console.log('--------onMissionLabelUpdated-------');}
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
                    console.log(err);
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
        // The main window is created. Set a main page for this ability.
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
};
```


## missionManager.off

off(type: 'mission', listenerId: number, callback: AsyncCallback&lt;void&gt;): void;

Deregisters a mission status listener.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | listenerId | number | Yes| Index of the mission status listener to deregister. It is returned by **on()**.|
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------- |
| 16300002 | Input error. The specified mission listener does not exist. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import missionManager from '@ohos.app.ability.missionManager';
import UIAbility from '@ohos.app.ability.UIAbility';
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
import common from '@ohos.app.ability.common';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';
import window from '@ohos.window';

let listener: missionManager.MissionListener = {
    onMissionCreated: (mission) => {console.log('--------onMissionCreated-------');},
    onMissionDestroyed: (mission) => {console.log('--------onMissionDestroyed-------');},
    onMissionSnapshotChanged: (mission) => {console.log('--------onMissionSnapshotChanged-------');},
    onMissionMovedToFront: (mission) => {console.log('--------onMissionMovedToFront-------');},
    onMissionIconUpdated: (mission, icon) => {console.log('--------onMissionIconUpdated-------');},
    onMissionClosed: (mission) => {console.log('--------onMissionClosed-------');},
    onMissionLabelUpdated: (mission) => {console.log('--------onMissionLabelUpdated-------');}
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
                missionManager.off('mission', listenerId, (err) => {
                    console.log('$(err.code)');
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
        // The main window is created. Set a main page for this ability.
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
};
```


## missionManager.off

off(type: 'mission', listenerId: number): Promise&lt;void&gt;;

Deregisters a mission status listener. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | listenerId | number | Yes| Index of the mission status listener to deregister. It is returned by **on()**.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------- |
| 16300002 | Input error. The specified mission listener does not exist. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import missionManager from '@ohos.app.ability.missionManager';
import UIAbility from '@ohos.app.ability.UIAbility';
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
import common from '@ohos.app.ability.common';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';
import window from '@ohos.window';

let listener: missionManager.MissionListener = {
    onMissionCreated: (mission) => {console.log('--------onMissionCreated-------');},
    onMissionDestroyed: (mission) => {console.log('--------onMissionDestroyed-------');},
    onMissionSnapshotChanged: (mission) => {console.log('--------onMissionSnapshotChanged-------');},
    onMissionMovedToFront: (mission) => {console.log('--------onMissionMovedToFront-------');},
    onMissionIconUpdated: (mission, icon) => {console.log('--------onMissionIconUpdated-------');},
    onMissionClosed: (mission) => {console.log('--------onMissionClosed-------');},
    onMissionLabelUpdated: (mission) => {console.log('--------onMissionLabelUpdated-------');}
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
                    console.log('$(err.code)');
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
        // The main window is created. Set a main page for this ability.
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
};
```

## missionManager.getMissionInfo

getMissionInfo(deviceId: string, missionId: number, callback: AsyncCallback&lt;MissionInfo&gt;): void;

Obtains the information about a given mission. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | deviceId | string | Yes| Device ID. It is a null string by default for the local device.|
  | missionId | number | Yes| Mission ID.|
  | callback | AsyncCallback&lt;[MissionInfo](./js-apis-inner-application-missionInfo.md)&gt; | Yes| Callback used to return the mission information obtained.|

**Example**

  ```ts
    import missionManager from '@ohos.app.ability.missionManager';
    import { BusinessError } from '@ohos.base';

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
            let code = (paramError as BusinessError).code;
            let message = (paramError as BusinessError).message;
            console.error(`error: ${code}, ${message} `);
        }
    })
    .catch((err: BusinessError) => {console.log('$(err.code)');});
  ```

## missionManager.getMissionInfo

getMissionInfo(deviceId: string, missionId: number): Promise&lt;MissionInfo&gt;;

Obtains the information about a given mission. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | deviceId | string | Yes| Device ID. It is a null string by default for the local device.|
  | missionId | number | Yes| Mission ID.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;[MissionInfo](./js-apis-inner-application-missionInfo.md)&gt; | Promise used to return the mission information obtained.|

**Example**

```ts
import missionManager from '@ohos.app.ability.missionManager';
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

getMissionInfos(deviceId: string, numMax: number, callback: AsyncCallback&lt;Array&lt;MissionInfo&gt;&gt;): void;

Obtains information about all missions. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | deviceId | string | Yes| Device ID. It is a null string by default for the local device.|
  | numMax | number | Yes| Maximum number of missions whose information can be obtained.|
  | callback | AsyncCallback&lt;Array&lt;[MissionInfo](./js-apis-inner-application-missionInfo.md)&gt;&gt; | Yes| Callback used to return the array of mission information obtained.|

**Example**

  ```ts
  import missionManager from '@ohos.app.ability.missionManager';
  import { BusinessError } from '@ohos.base';

  try {
    missionManager.getMissionInfos('', 10, (error, missions) => {
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

getMissionInfos(deviceId: string, numMax: number): Promise&lt;Array&lt;MissionInfo&gt;&gt;;

Obtains information about all missions. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | deviceId | string | Yes| Device ID. It is a null string by default for the local device.|
  | numMax | number | Yes| Maximum number of missions whose information can be obtained.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;Array&lt;[MissionInfo](./js-apis-inner-application-missionInfo.md)&gt;&gt; | Promise used to return the array of mission information obtained.|

**Example**

```ts
import missionManager from '@ohos.app.ability.missionManager';
import { BusinessError } from '@ohos.base';

try {
    missionManager.getMissionInfos('', 10).then((data) => {
        console.info('getMissionInfos successfully. Data: ${JSON.stringify(data)}');
    }).catch((error: BusinessError) => {
        console.error('getMissionInfos failed. Cause: ${error.message}');
    });
} catch (error) {
    console.error('getMissionInfos failed. Cause: ${error.message}');
}
```

## missionManager.getMissionSnapShot

getMissionSnapShot(deviceId: string, missionId: number, callback: AsyncCallback&lt;MissionSnapshot&gt;): void;

Obtains the snapshot of a given mission. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | deviceId | string | Yes| Device ID. It is a null string by default for the local device.|
  | missionId | number | Yes| Mission ID.|
  | callback | AsyncCallback&lt;[MissionSnapshot](js-apis-inner-application-missionSnapshot.md)&gt; | Yes| Callback used to return the snapshot information obtained.|

**Example**
```ts
import missionManager from '@ohos.app.ability.missionManager';

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

getMissionSnapShot(deviceId: string, missionId: number): Promise&lt;MissionSnapshot&gt;;

Obtains the snapshot of a given mission. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | deviceId | string | Yes| Device ID. It is a null string by default for the local device.|
  | missionId | number | Yes| Mission ID.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;[MissionSnapshot](js-apis-inner-application-missionSnapshot.md)&gt; | Promise used to return the snapshot information obtained.|

**Example**
```ts
import missionManager from '@ohos.app.ability.missionManager';
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

## missionManager.getLowResolutionMissionSnapShot

getLowResolutionMissionSnapShot(deviceId: string, missionId: number, callback: AsyncCallback\<MissionSnapshot>): void;

Obtains the low-resolution snapshot of a given mission. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | deviceId | string | Yes| Device ID. It is a null string by default for the local device.|
  | missionId | number | Yes| Mission ID.|
  | callback | AsyncCallback&lt;[MissionSnapshot](js-apis-inner-application-missionSnapshot.md)&gt; | Yes| Callback used to return the snapshot information obtained.|

**Example**
```ts
import missionManager from '@ohos.app.ability.missionManager';

let testMissionId = 2;
try {
    missionManager.getLowResolutionMissionSnapShot('', testMissionId, (err, data) => {
        if (err) {
            console.error(`getLowResolutionMissionSnapShot failed: ${err.message}`);
        } else {
            console.info(`getLowResolutionMissionSnapShot successfully: ${JSON.stringify(data)}`);
        }
    });
} catch (err) {
    console.error(`getLowResolutionMissionSnapShot failed: ${err.message}`);
}
```

## missionManager.getLowResolutionMissionSnapShot

getLowResolutionMissionSnapShot(deviceId: string, missionId: number): Promise\<MissionSnapshot>;

Obtains the low-resolution snapshot of a given mission. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | deviceId | string | Yes| Device ID. It is a null string by default for the local device.|
  | missionId | number | Yes| Mission ID.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;[MissionSnapshot](js-apis-inner-application-missionSnapshot.md)&gt; | Promise used to return the snapshot information obtained.|

**Example**

```ts
import missionManager from '@ohos.app.ability.missionManager';
import { BusinessError } from '@ohos.base';

let testMissionId = 2;
try {
    missionManager.getLowResolutionMissionSnapShot('', testMissionId).then((data) => {
        console.info(`getLowResolutionMissionSnapShot successfully. Data: ${JSON.stringify(data)}`);
    }).catch((error: BusinessError) => {
        console.error(`getLowResolutionMissionSnapShot failed. Cause: ${error.message}`);
    });
} catch (error) {
    console.error(`getLowResolutionMissionSnapShot failed. Cause: ${error.message}`);
}
```


## missionManager.lockMission

lockMission(missionId: number, callback: AsyncCallback&lt;void&gt;): void;

Locks a given mission. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | missionId | number | Yes| Mission ID.|
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------- |
| 16300001 | Mission not found. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import missionManager from '@ohos.app.ability.missionManager';

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

lockMission(missionId: number): Promise&lt;void&gt;;

Locks a given mission. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | missionId | number | Yes| Mission ID.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------- |
| 16300001 | Mission not found. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**
```ts
import missionManager from '@ohos.app.ability.missionManager';
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

unlockMission(missionId: number, callback: AsyncCallback&lt;void&gt;): void;

Unlocks a given mission. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| missionId | number | Yes| Mission ID.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------- |
| 16300001 | Mission not found. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**
```ts
import missionManager from '@ohos.app.ability.missionManager';

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

unlockMission(missionId: number): Promise&lt;void&gt;;

Unlocks a given mission. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | missionId | number | Yes| Mission ID.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------- |
| 16300001 | Mission not found. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import missionManager from '@ohos.app.ability.missionManager';
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

clearMission(missionId: number, callback: AsyncCallback&lt;void&gt;): void;

Clears a given mission, regardless of whether it is locked. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | missionId | number | Yes| Mission ID.|
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Example**

```ts
import missionManager from '@ohos.app.ability.missionManager';

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

clearMission(missionId: number): Promise&lt;void&gt;;

Clears a given mission, regardless of whether it is locked. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | missionId | number | Yes| Mission ID.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise used to return the result.|

**Example**

```ts
import missionManager from '@ohos.app.ability.missionManager';
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

clearAllMissions(callback: AsyncCallback&lt;void&gt;): void;

Clears all unlocked missions. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**System API**: This is a system API and cannot be called by third-party applications.

**Example**

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

Clears all unlocked missions. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**System API**: This is a system API and cannot be called by third-party applications.

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise used to return the result.|

**Example**

```ts
import missionManager from '@ohos.app.ability.missionManager';
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

moveMissionToFront(missionId: number, callback: AsyncCallback&lt;void&gt;): void;

Switches a given mission to the foreground. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | missionId | number | Yes| Mission ID.|
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------- |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import missionManager from '@ohos.app.ability.missionManager';

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

moveMissionToFront(missionId: number, options: StartOptions, callback: AsyncCallback&lt;void&gt;): void;

Switches a given mission to the foreground, with the startup parameters for the switching specified. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | missionId | number | Yes| Mission ID.|
  | options | [StartOptions](js-apis-app-ability-startOptions.md) | Yes| Startup parameters, which are used to specify the window mode and device ID for switching the mission to the foreground.|
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------- |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import missionManager from '@ohos.app.ability.missionManager';

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

moveMissionToFront(missionId: number, options?: StartOptions): Promise&lt;void&gt;;

Switches a given mission to the foreground, with the startup parameters for the switching specified. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | missionId | number | Yes| Mission ID.|
  | options | [StartOptions](js-apis-app-ability-startOptions.md) | No| Startup parameters, which are used to specify the window mode and device ID for switching the mission to the foreground. By default, no value is passed in, indicating that the default startup parameters are used.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------- |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import missionManager from '@ohos.app.ability.missionManager';
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

## missionManager.moveMissionsToForeground<sup>10+</sup>

moveMissionsToForeground(missionIds: Array&lt;number&gt;, callback: AsyncCallback&lt;void&gt;): void;

Switches a batch of missions to the foreground. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**System API**: This is a system API.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | missionIds | Array&lt;number&gt; | Yes| Array holding the mission IDs.|
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

| ID| Error Message|
| ------- | -------- |
| 16000050 | Internal error. |

**Example**

```ts
import abilityManager from '@ohos.app.ability.abilityManager';
import missionManager from '@ohos.app.ability.missionManager';
import { BusinessError } from '@ohos.base';

try {
    missionManager.getMissionInfos("", 10, (error, missionInfos) => {
        if (error.code) {
            console.log("getMissionInfos failed, error.code:" + JSON.stringify(error.code));
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
        missionManager.moveMissionsToForeground(toShows, (err, data) => {
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

moveMissionsToForeground(missionIds: Array&lt;number&gt;, topMission: number, callback: AsyncCallback&lt;void&gt;): void;

Switches a batch of missions to the foreground, and moves the mission with the specified ID to the top. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**System API**: This is a system API.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | missionIds | Array&lt;number&gt; | Yes| Array holding the mission IDs.|
  | topMission | number | Yes| ID of the mission to be moved to the top.|
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

| ID| Error Message|
| ------- | -------- |
| 16000050 | Internal error. |

**Example**

```ts
import abilityManager from '@ohos.app.ability.abilityManager';
import missionManager from '@ohos.app.ability.missionManager';
import { BusinessError } from '@ohos.base';

try {
    missionManager.getMissionInfos("", 10, (error, missionInfos) => {
        if (error.code) {
            console.log("getMissionInfos failed, error.code:" + JSON.stringify(error.code));
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
        missionManager.moveMissionsToForeground(toShows, toShows[0], (err, data) => {
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

moveMissionsToForeground(missionIds: Array&lt;number&gt;, topMission?: number): Promise&lt;void&gt; ;

Switches a batch of missions to the foreground, and moves the mission with the specified ID to the top. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**System API**: This is a system API.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | missionIds | Array&lt;number&gt; | Yes| Array holding the mission IDs.|
  | topMission | number | No| ID of the mission to be moved to the top. The default value is **-1**, indicating that the default mission is moved to the top.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

| ID| Error Message|
| ------- | -------- |
| 16000050 | Internal error. |

**Example**

```ts
import abilityManager from '@ohos.app.ability.abilityManager';
import missionManager from '@ohos.app.ability.missionManager';
import { BusinessError } from '@ohos.base';

try {
    missionManager.getMissionInfos("", 10, (error, missionInfos) => {
        if (error.code) {
            console.log("getMissionInfos failed, error.code:" + JSON.stringify(error.code));
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
            console.log("moveMissionsToForeground is called" );
        });
    });
} catch (paramError) {
    let code = (paramError as BusinessError).code;
    let message = (paramError as BusinessError).message;
    console.error(`error: ${code}, ${message} `);
}

```

## missionManager.moveMissionsToBackground<sup>10+</sup>

moveMissionsToBackground(missionIds: Array&lt;number&gt;, callback: AsyncCallback&lt;Array&lt;number&gt;&gt;): void;

Switches a batch of missions to the background. This API uses an asynchronous callback to return the result. The mission IDs in the callback are sorted by mission level when the missions are switched.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**System API**: This is a system API.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | missionIds | Array&lt;number&gt; | Yes| Array holding the mission IDs.|
  | callback | AsyncCallback&lt;Array&lt;number&gt;&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

| ID| Error Message|
| ------- | -------- |
| 16000050 | Internal error. |

**Example**

```ts
import abilityManager from '@ohos.app.ability.abilityManager';
import missionManager from '@ohos.app.ability.missionManager';
import { BusinessError } from '@ohos.base';

try {
    missionManager.getMissionInfos("", 10, (error, missionInfos) => {
        if (error.code) {
            console.log("getMissionInfos failed, error.code:" + JSON.stringify(error.code));
            return;
        }

        let toHides = new Array<number>();
        for (let missionInfo of missionInfos) {
            if (missionInfo.abilityState ==  abilityManager.AbilityState.FOREGROUND) {
            toHides.push(missionInfo.missionId);
            }
        }
        missionManager.moveMissionsToBackground(toHides, (err, data) => {
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

moveMissionsToBackground(missionIds : Array&lt;number&gt;): Promise&lt;Array&lt;number&gt;&gt;;

Switches a batch of missions to the background. This API uses a promise to return the result. The mission IDs in the promise are sorted by mission level when the missions are switched.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**System API**: This is a system API.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | missionIds | Array&lt;number&gt; | Yes| Array holding the mission IDs.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;Array&lt;number&gt;&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

| ID| Error Message|
| ------- | -------- |
| 16000050 | Internal error. |

**Example**

```ts
import abilityManager from '@ohos.app.ability.abilityManager';
import missionManager from '@ohos.app.ability.missionManager';
import { BusinessError } from '@ohos.base';

try {
    missionManager.getMissionInfos("", 10, (error, missionInfos) => {
        if (error.code) {
            console.log("getMissionInfos failed, error.code:" + JSON.stringify(error.code));
            return;
        }

        let toHides = new Array<number>();
        for (let missionInfo of missionInfos) {
            if (missionInfo.abilityState ==  abilityManager.AbilityState.FOREGROUND) {
            toHides.push(missionInfo.missionId);
            }
        }
        missionManager.moveMissionsToBackground(toHides).then((hideRes) => {
            console.log("moveMissionsToBackground is called, res: "+ JSON.stringify(hideRes));
        });
    });
} catch (paramError) {
    let code = (paramError as BusinessError).code;
    let message = (paramError as BusinessError).message;
    console.error(`error: ${code}, ${message} `);
}

```
