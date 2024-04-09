# @ohos.application.missionManager (missionManager) (System API)

The **missionManager** module provides APIs to lock, unlock, and clear missions, and switch a mission to the foreground.

> **NOTE**
> 
> The APIs of this module are supported since API version 8 and deprecated since API version 9. You are advised to use [@ohos.app.ability.missionManager](js-apis-app-ability-missionManager-sys.md) instead. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module are system APIs and cannot be called by third-party applications.

## Modules to Import

```ts
import missionManager from '@ohos.application.missionManager';
```

## Required Permissions

ohos.permission.MANAGE_MISSIONS

## missionManager.registerMissionListener

registerMissionListener(listener: MissionListener): number

Registers a listener to observe the mission status.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**System API**: This is a system API.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | listener | [MissionListener](js-apis-inner-application-missionListener-sys.md) | Yes| Mission status listener to register.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | number | Index of the mission status listener, which is created by the system and allocated when the listener is registered.|

**Example**

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

Deregisters a mission status listener. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**System API**: This is a system API.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | listenerId | number | Yes| Index of the mission status listener to deregister. It is returned by **registerMissionListener()**.|
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Example**

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

Unregisters a mission status listener. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**System API**: This is a system API.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | listenerId | number | Yes| Index of the mission status listener to deregister. It is returned by **registerMissionListener()**.|

**Return value**

  | Type| Description| 
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise that returns no value.| 

**Example**

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

Obtains the information about a given mission. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**System API**: This is a system API.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | deviceId | string | Yes| Device ID. It is a null string by default for the local device.|
  | missionId | number | Yes| Mission ID.|
  | callback | AsyncCallback&lt;[MissionInfo](js-apis-inner-application-missionInfo-sys.md)&gt; | Yes| Callback used to return the mission information obtained.|

**Example**

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

Obtains the information about a given mission. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**System API**: This is a system API.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | deviceId | string | Yes| Device ID. It is a null string by default for the local device.|
  | missionId | number | Yes| Mission ID.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;[MissionInfo](js-apis-inner-application-missionInfo-sys.md)&gt; | Promise used to return the mission information obtained.|

**Example**

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

Obtains information about all missions. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**System API**: This is a system API.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | deviceId | string | Yes| Device ID. It is a null string by default for the local device.|
  | numMax | number | Yes| Maximum number of missions whose information can be obtained.|
  | callback | AsyncCallback&lt;Array&lt;[MissionInfo](js-apis-inner-application-missionInfo-sys.md)&gt;&gt; | Yes| Callback used to return the array of mission information obtained.|

**Example**

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

Obtains information about all missions. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**System API**: This is a system API.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | deviceId | string | Yes| Device ID. It is a null string by default for the local device.|
  | numMax | number | Yes| Maximum number of missions whose information can be obtained.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;Array&lt;[MissionInfo](js-apis-inner-application-missionInfo-sys.md)&gt;&gt; | Promise used to return the array of mission information obtained.|

**Example**

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

Obtains the snapshot of a given mission. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**System API**: This is a system API.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | deviceId | string | Yes| Device ID. It is a null string by default for the local device.|
  | missionId | number | Yes| Mission ID.|
  | callback | AsyncCallback&lt;[MissionSnapshot](js-apis-inner-application-missionSnapshot-sys.md)&gt; | Yes| Callback used to return the snapshot information obtained.|

**Example**

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

Obtains the snapshot of a given mission. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**System API**: This is a system API.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | deviceId | string | Yes| Device ID. It is a null string by default for the local device.|
  | missionId | number | Yes| Mission ID.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;[MissionSnapshot](js-apis-inner-application-missionSnapshot-sys.md)&gt; | Promise used to return the snapshot information obtained.|

**Example**

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

Locks a given mission. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**System API**: This is a system API.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | missionId | number | Yes| Mission ID.|
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the mission is locked, **err** is **undefined**. Otherwise, **err** is an error object.|

**Example**

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

Locks a given mission. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**System API**: This is a system API.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | missionId | number | Yes| Mission ID.|

**Return value**

  | Type| Description| 
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise that returns no value.| 

**Example**

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

Unlocks a given mission. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| missionId | number | Yes| Mission ID.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the mission is unlocked, **err** is **undefined**. Otherwise, **err** is an error object.|

**Example**

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

Unlocks a given mission. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**System API**: This is a system API.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | missionId | number | Yes| Mission ID.|

**Return value**

  | Type| Description| 
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise that returns no value.| 

**Example**

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

Clears a given mission, regardless of whether it is locked. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**System API**: This is a system API.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | missionId | number | Yes| Mission ID.|
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the mission is cleared, **err** is **undefined**. Otherwise, **err** is an error object.|

**Example**

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

Clears a given mission, regardless of whether it is locked. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**System API**: This is a system API.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | missionId | number | Yes| Mission ID.|

**Return value**

  | Type| Description| 
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise that returns no value.| 

**Example**

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

Clears all unlocked missions. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**System API**: This is a system API.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If all the unlocked missions are cleared, **err** is **undefined**. Otherwise, **err** is an error object.|

**Example**

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

Clears all unlocked missions. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**System API**: This is a system API.

**Return value**

  | Type| Description| 
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise that returns no value.| 

**Example**

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

Switches a given mission to the foreground. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**System API**: This is a system API.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | missionId | number | Yes| Mission ID.|
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the mission is switched to the foreground, **err** is **undefined**. Otherwise, **err** is an error object.|

**Example**

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

Switches a given mission to the foreground, with the startup parameters for the switching specified. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**System API**: This is a system API.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | missionId | number | Yes| Mission ID.|
  | options | [StartOptions](js-apis-app-ability-startOptions.md) | Yes| Startup parameters, which are used to specify the window mode and device ID for switching the mission to the foreground.|
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the mission is switched to the foreground, **err** is **undefined**. Otherwise, **err** is an error object.|

**Example**

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

Switches a given mission to the foreground, with the startup parameters for the switching specified. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**System API**: This is a system API.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | missionId | number | Yes| Mission ID.|
  | options | [StartOptions](js-apis-app-ability-startOptions.md) | No| Startup parameters, which are used to specify the window mode and device ID for switching the mission to the foreground.|

**Return value**

  | Type| Description| 
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise that returns no value.| 

**Example**

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
