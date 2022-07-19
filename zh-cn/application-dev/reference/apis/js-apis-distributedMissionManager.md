# distributedMissionManager

distributedMissionManager模块提供跨设备系统任务管理能力，包括注册系统任务状态监听、取消系统任务状态监听、开始同步远端任务列表、停止同步远端任务列表操作。

> **说明：**
> 
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```
import distributedMissionManager from '@ohos.distributedMissionManager'
```

## 权限列表

ohos.permission.MANAGE_MISSIONS

## distributedMissionManager.registerMissionListener

registerMissionListener(parameter: MissionDeviceInfo, options: MissionCallback, callback: AsyncCallback&lt;void&gt;): void;

注册系统任务状态监听，以回调函数的方式返回。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | parameter | <a href="#missiondeviceinfo">MissionDeviceInfo</a> | 是 | 注册监听设备信息。 |
  | options | <a href="#missioncallback">MissionCallback</a> | 是 | 注册的回调方法。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | 执行结果回调函数。 |

**示例：**

  ```ts
  function NotifyMissionsChanged(deviceId) {
      console.log('NotifyMissionsChanged deviceId ' + JSON.stringify(deviceId));
  }
  function NotifySnapshot(deviceId, missionId) {
      console.log('NotifySnapshot deviceId ' + JSON.stringify(deviceId));
      console.log('NotifySnapshot missionId ' + JSON.stringify(missionId));
  }
  function NotifyNetDisconnect(deviceId, state) {
      console.log('NotifyNetDisconnect deviceId ' + JSON.stringify(deviceId));
      console.log('NotifyNetDisconnect state ' + JSON.stringify(state));
  }
  var parameter =  {
  	deviceId: remoteDeviceId
  };
  var options = {
      notifyMissionsChanged: NotifyMissionsChanged,
      notifySnapshot: NotifySnapshot,
      notifyNetDisconnect: NotifyNetDisconnect
  }
  distributedMissionManager.registerMissionListener(parameter, options, (error) => {
      console.log("error.code = " + error.code)
  })
  ```
## distributedMissionManager.registerMissionListener

registerMissionListener(parameter: MissionDeviceInfo, options: MissionCallback): Promise&lt;void&gt;

注册系统任务状态监听，以promise的方式返回。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | parameter | <a href="#missiondeviceinfo">MissionDeviceInfo</a> | 是 | 设备信息。 |
  | options | <a href="#missioncallback">MissionCallback</a> | 是 | 注册的回调方法。 |

**返回值：**

  | 类型 | 说明 | 
  | -------- | -------- |
  | Promise&lt;void&gt; | promise方式返回执行结果。 | 

**示例：**

  ```ts
  function NotifyMissionsChanged(deviceId) {
      console.log('NotifyMissionsChanged deviceId ' + JSON.stringify(deviceId));
  }
  function NotifySnapshot(deviceId, missionId) {
      console.log('NotifySnapshot deviceId ' + JSON.stringify(deviceId));
      console.log('NotifySnapshot missionId ' + JSON.stringify(missionId));
  }
  function NotifyNetDisconnect(deviceId, state) {
      console.log('NotifyNetDisconnect deviceId ' + JSON.stringify(deviceId));
      console.log('NotifyNetDisconnect state ' + JSON.stringify(state));
  }
  var parameter =  {
  	deviceId: remoteDeviceId
  };
  var options = {
      notifyMissionsChanged: NotifyMissionsChanged,
      notifySnapshot: NotifySnapshot,
      notifyNetDisconnect: NotifyNetDisconnect
  }
  distributedMissionManager.registerMissionListener(parameter, options)
  .then(data => {
      console.info('success data is ' + data);
  }).catch(error => {
      console.info('error error is ' + error);
  })
  ```


## distributedMissionManager.unregisterMissionListener

unregisterMissionListener(parameter: MissionDeviceInfo, callback: AsyncCallback&lt;void&gt;): void;

取消任务状态监听, 以回调函数的方式返回。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | listenerId | number | 是 | 系统任务状态监听方法的index值，和监听方法一一对应，由registerMissionListener方法返回。 |
  | parameter | <a href="#missiondeviceinfo">MissionDeviceInfo</a> | 是 | 设备信息。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | 执行结果回调函数。 |

**示例：**

  ```ts
  var parameter =  {
  	deviceId: remoteDeviceId
  };
  distributedMissionManager.unregisterMissionListener(parameter, (error) => {
      console.log("error.code = " + error.code)
  })
  ```


## distributedMissionManager.unregisterMissionListener

unregisterMissionListener(parameter: MissionDeviceInfo): Promise&lt;void&gt;

取消任务状态监听，以promise方式返回执行结果。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | parameter | <a href="#missiondeviceinfo">MissionDeviceInfo</a> | 是 | 设备信息。 |

**返回值：**

  | 类型 | 说明 | 
  | -------- | -------- |
  | Promise&lt;void&gt; | promise方式返回执行结果。 | 

**示例：**

  ```ts
  var parameter =  {
  	deviceId: remoteDeviceId
  };
  distributedMissionManager.unregisterMissionListener(parameter)
  .then(data => {
      console.info('success data is ' + data);
  }).catch(error => {
      console.info('error error is ' + error);
  })
  ```

## distributedMissionManager.startSyncRemoteMissions

startSyncRemoteMissions(parameter: MissionParameter, callback: AsyncCallback&lt;void&gt;): void;

开始同步远端任务列表, 以回调函数的方式返回。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | listenerId | number | 是 | 系统任务状态监听方法的index值，和监听方法一一对应，由registerMissionListener方法返回。 |
  | parameter | <a href="#missionparameter">MissionParameter</a> | 是 | 同步信息。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | 执行结果回调函数。 |

**示例：**

  ```ts
  var parameter =  {
  	deviceId: remoteDeviceId,
      fixConflict: false, 
      tag: 0
  };
  distributedMissionManager.startSyncRemoteMissions(parameter, (error) => {
      console.log("error.code = " + error.code)
  })
  ```

## distributedMissionManager.startSyncRemoteMissions

startSyncRemoteMissions(parameter: MissionParameter): Promise&lt;void&gt;

开始同步远端任务列表，以promise方式返回执行结果。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | parameter | <a href="#missionparameter">MissionParameter</a> | 是 | 同步信息。 |

**返回值：**

  | 类型 | 说明 | 
  | -------- | -------- |
  | Promise&lt;void&gt; | promise方式返回执行结果。 | 

**示例：**

  ```ts
  var parameter =  {
  	deviceId: remoteDeviceId,
      fixConflict: false, 
      tag: 0
  };
  distributedMissionManager.startSyncRemoteMissions(parameter)
  .then(data => {
      console.info('success data is ' + data);
  }).catch(error => {
      console.info('error error is ' + error);
  })
  ```

## distributedMissionManager.stopSyncRemoteMissions

stopSyncRemoteMissions(parameter: MissionDeviceInfo, callback: AsyncCallback&lt;void&gt;): void;

停止同步远端任务列表, 以回调函数的方式返回。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | listenerId | number | 是 | 系统任务状态监听方法的index值，和监听方法一一对应，由registerMissionListener方法返回。 |
  | parameter | <a href="#missiondeviceinfo">MissionDeviceInfo</a> | 是 | 同步信息。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | 执行结果回调函数。 |

**示例：**

  ```ts
  var parameter =  {
  	deviceId: remoteDeviceId
  };
  distributedMissionManager.stopSyncRemoteMissions(parameter, (error) => {
      console.log("error.code = " + error.code)
  })
  ```

## distributedMissionManager.stopSyncRemoteMissions

stopSyncRemoteMissions(parameter: MissionDeviceInfo): Promise&lt;void&gt;

停止同步远端任务列表，以promise方式返回执行结果。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | parameter | <a href="#missiondeviceinfo">MissionDeviceInfo</a> | 是 | 同步信息。 |

**返回值：**

  | 类型 | 说明 | 
  | -------- | -------- |
  | Promise&lt;void&gt; | promise方式返回执行结果。 | 

**示例：**

  ```ts
  var parameter =  {
  	deviceId: remoteDeviceId
  };
  distributedMissionManager.stopSyncRemoteMissions(parameter)
  .then(data => {
      console.info('success data is ' + data);
  }).catch(error => {
      console.info('error error is ' + error);
  })
  ```

## <a id ="missioncallback">MissionCallback</a>

表示开始同步后，建立的回调函数。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Mission

**系统API**: 此接口为系统接口，三方应用不支持调用。

| 名称 | 类型 | 可读 | 可写 | 说明 | 
| -------- | -------- | -------- | -------- | -------- |
| notifyMissionsChanged | function | 是 | 否 | 通知任务变化，返回设备ID。| 
| notifySnapshot | function | 是 | 否 | 通知快照变化，返回设备ID，任务ID | 
| notifyNetDisconnect | function | 是 | 否 | 通知断开连接，返回设备ID，网络状态 | 

## <a id ="missionparameter">MissionParameter</a>

表示同步时所需参数的枚举。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Mission

**系统API**: 此接口为系统接口，三方应用不支持调用。

| 名称 | 参数类型 | 可读 | 可写 | 说明 | 
| -------- | -------- | -------- | -------- | -------- |
| deviceId | string | 是 | 是 | 表示设备ID。| 
| fixConflict | boolean | 是 | 是 | 表示是否存在版本冲突。 | 
| tag | number | 是 | 是 | 表示特定的标签。 | 

## <a id ="missiondeviceinfo">MissionDeviceInfo</a>

表示注册监听时所需参数的枚举。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Mission

**系统API**: 此接口为系统接口，三方应用不支持调用。

| 名称 | 参数类型 | 可读 | 可写 | 说明 | 
| -------- | -------- | -------- | -------- | -------- |
| deviceId | string | 是 | 是 | 表示设备ID。| 