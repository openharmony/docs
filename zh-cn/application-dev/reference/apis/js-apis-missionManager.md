# missionManager

missionManager模块提供系统任务管理能力，包括对系统任务执行锁定、解锁、清理、切换到前台等操作。

> **说明：**
> 
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```
import missionManager from '@ohos.application.missionManager'
```

## 权限列表

ohos.permission.MANAGE_MISSIONS

## missionManager.registerMissionListener

registerMissionListener(listener: MissionListener): number;

注册系统任务状态监听。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | listener | MissionListener | 是 | 系统任务监听方法。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | number | 监听方法的index值，由系统创建，在注册系统任务状态监听时分配，和监听方法一一对应&nbsp;。 |

**示例：**

```js
  var listener = {
      onMissionCreated: function (mission) {console.log("--------onMissionCreated-------")},
      onMissionDestroyed: function (mission) {console.log("--------onMissionDestroyed-------")},
      onMissionSnapshotChanged: function (mission) {console.log("--------onMissionSnapshotChanged-------")},
      onMissionMovedToFront: function (mission) {console.log("--------onMissionMovedToFront-------")},
      onMissionIconUpdated: function (mission, icon) {console.log("--------onMissionIconUpdated-------")},
      onMissionClosed: function (mission) {console.log("--------onMissionClosed-------")},
      onMissionLabelUpdated: function (mission) {console.log("--------onMissionLabelUpdated-------")}
  };
  console.log("registerMissionListener")
  var listenerid = missionManager.registerMissionListener(listener);
```


## missionManager.unregisterMissionListener

unregisterMissionListener(listenerId: number, callback: AsyncCallback&lt;void&gt;): void;

取消任务状态监听。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | listenerId | number | 是 | 系统任务状态监听方法的index值，和监听方法一一对应，由registerMissionListener方法返回。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | 执行结果回调函数。 |

**示例：**

```js
  var listener = {
      onMissionCreated: function (mission) {console.log("--------onMissionCreated-------")},
      onMissionDestroyed: function (mission) {console.log("--------onMissionDestroyed-------")},
      onMissionSnapshotChanged: function (mission) {console.log("--------onMissionSnapshotChanged-------")},
      onMissionMovedToFront: function (mission) {console.log("--------onMissionMovedToFront-------")},
      onMissionIconUpdated: function (mission, icon) {console.log("--------onMissionIconUpdated-------")},
      onMissionClosed: function (mission) {console.log("--------onMissionClosed-------")},
      onMissionLabelUpdated: function (mission) {console.log("--------onMissionLabelUpdated-------")}
  };
  console.log("registerMissionListener")
  var listenerid = missionManager.registerMissionListener(listener);

  missionManager.unregisterMissionListener(listenerid, (error) => {
      console.log("unregisterMissionListener");
  })
```


## missionManager.unregisterMissionListener

unregisterMissionListener(listenerId: number): Promise&lt;void&gt;;

取消任务状态监听，以promise方式返回执行结果。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | listenerId | number | 是 | 系统任务状态监听方法的index值，和监听方法一一对应，由registerMissionListener方法返回。 |

**返回值：**

  | 类型 | 说明 | 
  | -------- | -------- |
  | Promise&lt;void&gt; | promise方式返回执行结果。 | 

**示例：**

```js
  var listener = {
      onMissionCreated: function (mission) {console.log("--------onMissionCreated-------")},
      onMissionDestroyed: function (mission) {console.log("--------onMissionDestroyed-------")},
      onMissionSnapshotChanged: function (mission) {console.log("--------onMissionSnapshotChanged-------")},
      onMissionMovedToFront: function (mission) {console.log("--------onMissionMovedToFront-------")},
      onMissionIconUpdated: function (mission, icon) {console.log("--------onMissionIconUpdated-------")},
      onMissionClosed: function (mission) {console.log("--------onMissionClosed-------")},
      onMissionLabelUpdated: function (mission) {console.log("--------onMissionLabelUpdated-------")}
  };
  console.log("registerMissionListener")
  var listenerid = missionManager.registerMissionListener(listener);

  missionManager.unregisterMissionListener(listenerid).catch(function (err) {
      console.log(err);
  });
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
  | callback | AsyncCallback&lt;[MissionInfo](#missioninfo)&gt; | 是 | 执行结果回调函数，返回任务信息。 |

**示例：**

  ```js
  import missionManager from '@ohos.application.missionManager'

  var allMissions=missionManager.getMissionInfos("",10).catch(function(err){console.log(err);});
      missionManager.getMissionInfo("", allMissions[0].missionId, (error, mission) => {
        console.log("getMissionInfo is called, error.code = " + error.code)
        console.log("mission.missionId = " + mission.missionId);
        console.log("mission.runningState = " + mission.runningState);
        console.log("mission.lockedState = " + mission.lockedState);
        console.log("mission.timestamp = " + mission.timestamp);
        console.log("mission.label = " + mission.label);
        console.log("mission.iconPath = " + mission.iconPath);
      });
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
  | Promise&lt;[MissionInfo](#missioninfo)&gt; | 任务信息。 |

**示例：**

  ```js
  import missionManager from '@ohos.application.missionManager'

  var mission = missionManager.getMissionInfo("", 10).catch(function (err){
      console.log(err);
  });
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
  | callback | AsyncCallback&lt;Array&lt;[MissionInfo](#missioninfo)&gt;&gt; | 是 | 执行结果回调函数，返回任务信息数组。 |

**示例：**

  ```js
  import missionManager from '@ohos.application.missionManager'

  missionManager.getMissionInfos("", 10, (error, missions) => {
      console.log("getMissionInfos is called, error.code = " + error.code);
      console.log("size = " + missions.length);
      console.log("missions = " + JSON.stringify(missions));
  })
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
  | Promise&lt;Array&lt;[MissionInfo](#missioninfo)&gt;&gt; | 任务信息数组。 |

**示例：**

  ```js
  import missionManager from '@ohos.application.missionManager'

  var allMissions = missionManager.getMissionInfos("", 10).catch(function (err){
      console.log(err);
  });
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
  | callback | AsyncCallback&lt;[MissionSnapshot](js-apis-application-MissionSnapshot.md)&gt; | 是 | 执行结果回调函数，返回任务快照信息。 |

**示例：**

  ```js
  import missionManager from '@ohos.application.missionManager'

  missionManager.getMissionInfos("", 10, (error, missions) => {
    console.log("getMissionInfos is called, error.code = " + error.code);
    console.log("size = " + missions.length);
    console.log("missions = " + JSON.stringify(missions));
    var id = missions[0].missionId;

    missionManager.getMissionSnapShot("", id, (error, snapshot) => {
  	console.log("getMissionSnapShot is called, error.code = " + error.code);
  	console.log("bundleName = " + snapshot.ability.bundleName);
  })
  })
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
  | Promise&lt;[MissionSnapshot](js-apis-application-MissionSnapshot.md)&gt; | 任务快照信息。 |

**示例：**

  ```js
  import missionManager from '@ohos.application.missionManager'

  var allMissions;
  missionManager.getMissionInfos("",10).then(function(res){
    allMissions=res;
    }).catch(function(err){console.log(err);});
    console.log("size = " + allMissions.length);
    console.log("missions = " + JSON.stringify(allMissions));
    var id = allMissions[0].missionId;

    var snapshot = missionManager.getMissionSnapShot("", id).catch(function (err){
        console.log(err);
    });
  ```

## missionManager.getLowResolutionMissionSnapShot<sup>9+</sup>

getLowResolutionMissionSnapShot(deviceId: string, missionId: number, callback: AsyncCallback\<MissionSnapshot>): void;

使用给定的任务ID获取任务低分辨率快照。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | deviceId | string | 是 | 设备ID，本机默认为空字符串。 |
  | missionId | number | 是 | 任务ID。 |
  | callback | AsyncCallback&lt;[MissionSnapshot](js-apis-application-MissionSnapshot.md)&gt; | 是 | 执行结果回调函数，返回任务快照信息。 |

**示例：**

  ```js
  import missionManager from '@ohos.application.missionManager'

  missionManager.getMissionInfos("", 10, (error, missions) => {
    console.log("getMissionInfos is called, error.code = " + error.code);
    console.log("size = " + missions.length);
    console.log("missions = " + JSON.stringify(missions));
    var id = missions[0].missionId;

    missionManager.getLowResolutionMissionSnapShot("", id, (error, snapshot) => {
  	console.log("getLowResolutionMissionSnapShot is called, error.code = " + error.code);
  	console.log("bundleName = " + snapshot.ability.bundleName);
  })
  })
  ```


## missionManager.getLowResolutionMissionSnapShot<sup>9+</sup>

getLowResolutionMissionSnapShot(deviceId: string, missionId: number): Promise\<MissionSnapshot>;

使用给定的任务ID获取任务低分辨率快照。

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
  | Promise&lt;[MissionSnapshot](js-apis-application-MissionSnapshot.md)&gt; | 任务快照信息。 |

**示例：**

  ```js
  import missionManager from '@ohos.application.missionManager'

  var allMissions;
  missionManager.getMissionInfos("",10).then(function(res){
    allMissions=res;
    }).catch(function(err){console.log(err);});
    console.log("size = " + allMissions.length);
    console.log("missions = " + JSON.stringify(allMissions));
    var id = allMissions[0].missionId;

    var snapshot = missionManager.getLowResolutionMissionSnapShot("", id).catch(function (err){
        console.log(err);
    });
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

**示例：**

  ```js
  import missionManager from '@ohos.application.missionManager'

  missionManager.getMissionInfos("", 10, (error, missions) => {
    console.log("getMissionInfos is called, error.code = " + error.code);
    console.log("size = " + missions.length);
    console.log("missions = " + JSON.stringify(missions));
    var id = missions[0].missionId;

    missionManager.lockMission(id).then(() => {
  	console.log("lockMission is called ");
  });
  });
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

**示例：**

  ```js
  import missionManager from '@ohos.application.missionManager'
  var allMissions;
  missionManager.getMissionInfos("",10).then(function(res){
    allMissions=res;
  }).catch(function(err){console.log(err);});
  console.log("size = " + allMissions.length);
  console.log("missions = " + JSON.stringify(allMissions));
  var id = allMissions[0].missionId;

  missionManager.lockMission(id).catch(function (err){
      console.log(err);
  });
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

**示例：**

  ```js
  import missionManager from '@ohos.application.missionManager'

  missionManager.getMissionInfos("", 10, (error, missions) => {
    console.log("getMissionInfos is called, error.code = " + error.code);
    console.log("size = " + missions.length);
    console.log("missions = " + JSON.stringify(missions));
    var id = missions[0].missionId;

    missionManager.unlockMission(id).then(() => {
  	console.log("unlockMission is called ");
  });
  });
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

**示例：**

  ```js
  import missionManager from '@ohos.application.missionManager'

  var allMissions;
  missionManager.getMissionInfos("",10).then(function(res){
    allMissions=res;
  }).catch(function(err){console.log(err);});
  console.log("size = " + allMissions.length);
  console.log("missions = " + JSON.stringify(allMissions));
  var id = allMissions[0].missionId;

  missionManager.lockMission(id).catch(function (err){
      console.log(err);
  });
  missionManager.unlockMission(id).catch(function (err){
      console.log(err);
  });
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

  ```js
  import missionManager from '@ohos.application.missionManager'

  missionManager.getMissionInfos("", 10, (error, missions) => {
    console.log("getMissionInfos is called, error.code = " + error.code);
    console.log("size = " + missions.length);
    console.log("missions = " + JSON.stringify(missions));
    var id = missions[0].missionId;

    missionManager.clearMission(id).then(() => {
  	console.log("clearMission is called ");
  });
  });
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

  ```js
  import missionManager from '@ohos.application.missionManager'

  var allMissions;
  missionManager.getMissionInfos("",10).then(function(res){
    allMissions=res;
  }).catch(function(err){console.log(err);});
  console.log("size = " + allMissions.length);
  console.log("missions = " + JSON.stringify(allMissions));
  var id = allMissions[0].missionId;

  missionManager.clearMission(id).catch(function (err){
    console.log(err);
  });
  ```


## missionManager.clearAllMissions

clearAllMissions(callback: AsyncCallback&lt;void&gt;): void;

清理所有未锁定的任务，以回调函数的方式返回。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统API**: 此接口为系统接口，三方应用不支持调用。

**示例：**

  ```js
  import missionManager from '@ohos.application.missionManager'

  missionManager.clearAllMissions().then(() => {
    console.log("clearAllMissions is called ");
  });
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

  ```js
  import missionManager from '@ohos.application.missionManager'
  missionManager.clearAllMissions().catch(function (err){
    console.log(err);
  });
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

**示例：**

  ```js
  import missionManager from '@ohos.application.missionManager'

  missionManager.getMissionInfos("", 10, (error, missions) => {
    console.log("getMissionInfos is called, error.code = " + error.code);
    console.log("size = " + missions.length);
    console.log("missions = " + JSON.stringify(missions));
    var id = missions[0].missionId;

    missionManager.moveMissionToFront(id).then(() => {
  	console.log("moveMissionToFront is called ");
  });
  });
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
  | options | [StartOptions](js-apis-application-StartOptions.md) | 是 | 启动参数选项，用于指定任务切到前台时的窗口模式，设备ID等。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | 执行结果回调函数。 |

**示例：**

  ```js
  import missionManager from '@ohos.application.missionManager'

  missionManager.getMissionInfos("", 10, (error, missions) => {
    console.log("getMissionInfos is called, error.code = " + error.code);
    console.log("size = " + missions.length);
    console.log("missions = " + JSON.stringify(missions));
    var id = missions[0].missionId;

    missionManager.moveMissionToFront(id,{windowMode : 101}).then(() => {
  	console.log("moveMissionToFront is called ");
    });
  });
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
  | options | [StartOptions](js-apis-application-StartOptions.md) | 否 | 启动参数选项，用于指定任务切到前台时的窗口模式，设备ID等。 |

**返回值：**

  | 类型 | 说明 | 
  | -------- | -------- |
  | Promise&lt;void&gt; | promise方式返回执行结果。 | 

**示例：**

  ```js
  import missionManager from '@ohos.application.missionManager'

  var allMissions;
  missionManager.getMissionInfos("",10).then(function(res){
    allMissions=res;
  }).catch(function(err){console.log(err);});
  console.log("size = " + allMissions.length);
  console.log("missions = " + JSON.stringify(allMissions));
  var id = allMissions[0].missionId;

  missionManager.moveMissionToFront(id).catch(function (err){
    console.log(err);
  });
  ```

## MissionInfo

表示Ability对应任务信息的枚举。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Mission

**系统API**: 此接口为系统接口，三方应用不支持调用。

| 名称 | 参数类型 | 可读 | 可写 | 说明 | 
| -------- | -------- | -------- | -------- | -------- |
| missionId | number | 是 | 是 | 表示任务ID。| 
| runningState | number | 是 | 是 | 表示运行状态。 | 
| lockedState | boolean | 是 | 是 | 表示锁定状态。 | 
| timestamp | string | 是 | 是 | 表示任务的最近创建或更新时间。 | 
| want | [Want](js-apis-application-Want.md) | 是 | 是 | 表示任务的Want信息。 | 
| label | string | 是 | 是 | 表示任务的标签。 | 
| iconPath | string | 是 | 是 | 表示任务的图标路径。 | 
| continuable | boolean | 是 | 是 | 表示任务是否可以迁移。 | 
