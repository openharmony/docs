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
import image from '@ohos.multimedia.image';

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

export default class EntryAbility extends UIAbility {
    onCreate(want, launchParam) {
        console.log('[Demo] EntryAbility onCreate');
        globalThis.abilityWant = want;
        globalThis.context = this.context;
    }

    onDestroy() {
        try {
            if (listenerId !== -1) {
                missionManager.off('mission', listenerId).catch((err: BusinessError) => {
                    console.log(JSON.stringify(err));
                });
            }
        } catch (paramError) {
            console.error('error: ${paramError.code}, ${paramError.message}');
        }
        console.log('[Demo] EntryAbility onDestroy');
    }

    onWindowStageCreate(windowStage) {
        // The main window is created. Set a main page for this ability.
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

Deregisters a mission status listener. This API uses an asynchronous callback to return the result.

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
import image from '@ohos.multimedia.image';

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

export default class EntryAbility extends UIAbility {
    onCreate(want, launchParam) {
        console.log('[Demo] EntryAbility onCreate');
        globalThis.abilityWant = want;
        globalThis.context = this.context;
    }

    onDestroy() {
        try {
            if (listenerId !== -1) {
                missionManager.off('mission', listenerId, (err: BusinessError) => {
                    console.log('$(err.code)');
                });
            }
        } catch (paramError) {
            console.error('error: ${paramError.code}, ${paramError.message}');
        }
        console.log('[Demo] EntryAbility onDestroy');
    }

    onWindowStageCreate(windowStage) {
        // The main window is created. Set a main page for this ability.
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
import image from '@ohos.multimedia.image';

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
        // The main window is created. Set a main page for this ability.
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
        console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');
        }
    })
    .catch((err: BusinessError) => {console.log(`$(err.code)`);});
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

  try {
    missionManager.getMissionInfos('', 10, (error: BusinessError, missions: Array<missionManager.MissionInfo>) => {
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
import { BusinessError } from '@ohos.base';

let testMissionId = 2;
try {
    missionManager.getMissionSnapShot('', testMissionId, (err: BusinessError, data: missionManager.MissionSnapshot ) => {
        if (err) {
            console.error('getMissionSnapShot failed: ${err.message}');
        } else {
            console.info('getMissionSnapShot successfully: ${JSON.stringify(data)}');
        }
    });
} catch (error) {
    let err: BusinessError = error as BusinessError;
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

getLowResolutionMissionSnapShot(deviceId: string, missionId: number, callback: AsyncCallback\<MissionSnapshot>): void;

Obtains the low-resolution snapshot of a given mission. This API uses a promise to return the result.

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
import { BusinessError } from '@ohos.base';

let testMissionId = 2;
try {
    missionManager.getLowResolutionMissionSnapShot('', testMissionId, (err: BusinessError, data: missionManager.MissionSnapshot) => {
        if (err) {
            console.error('getLowResolutionMissionSnapShot failed: ${err.message}');
        } else {
            console.info('getLowResolutionMissionSnapShot successfully: ${JSON.stringify(data)}');
        }
    });
} catch (error) {
    let err: BusinessError = error as BusinessError;
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
import { BusinessError } from '@ohos.base';

let testMissionId = 2;
try {
    missionManager.lockMission(testMissionId, (err: BusinessError, data: void) => {
        if (err) {
            console.error('lockMission failed: ${err.message}');
        } else {
            console.info('lockMission successfully: ${JSON.stringify(data)}');
        }
    });
} catch (error) {
    let err: BusinessError = error as BusinessError;
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
import { BusinessError } from '@ohos.base';

let testMissionId = 2;
try {
    missionManager.unlockMission(testMissionId, (err: BusinessError, data: void) => {
        if (err) {
            console.error('unlockMission failed: ${err.message}');
        } else {
            console.info('unlockMission successfully: ${JSON.stringify(data)}');
        }
    });
} catch (error) {
    let err: BusinessError = error as BusinessError;
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
import { BusinessError } from '@ohos.base';

let testMissionId = 2;
try {
    missionManager.clearMission(testMissionId, (err: BusinessError, data: void) => {
        if (err) {
            console.error('clearMission failed: ${err.message}');
        } else {
            console.info('clearMission successfully: ${JSON.stringify(data)}');
        }
    });
} catch (error) {
    let err: BusinessError = error as BusinessError;
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

clearAllMissions(callback: AsyncCallback&lt;void&gt;): void;

Clears all unlocked missions. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**System API**: This is a system API and cannot be called by third-party applications.

**Example**

```ts
import missionManager from '@ohos.app.ability.missionManager';
import { BusinessError } from '@ohos.base';

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
import { BusinessError } from '@ohos.base';

let testMissionId = 2;
try {
    missionManager.moveMissionToFront(testMissionId, (err: BusinessError, data: void) => {
        if (err) {
            console.error('moveMissionToFront failed: ${err.message}');
        } else {
            console.info('moveMissionToFront successfully: ${JSON.stringify(data)}');
        }
    });
} catch (error) {
    let err: BusinessError = error as BusinessError;
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
import { BusinessError } from '@ohos.base';

let testMissionId = 2;
try {
    missionManager.moveMissionToFront(testMissionId, {windowMode : 101}, (err: BusinessError, data: void) => {
        if (err) {
            console.error('moveMissionToFront failed: ${err.message}');
        } else {
            console.info('moveMissionToFront successfully: ${JSON.stringify(data)}');
        }
    });
} catch (error) {
    let err: BusinessError = error as BusinessError;
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
  | options | [StartOptions](js-apis-app-ability-startOptions.md) | No| Startup parameters, which are used to specify the window mode and device ID for switching the mission to the foreground.|

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
