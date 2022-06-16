# Vibrator

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```js
import vibrator from '@ohos.vibrator';
```


## vibrator.vibrate

vibrate(duration: number): Promise&lt;void&gt;

Triggers vibration with a specific duration. This API uses a promise to return the execution result.

**Required permissions**: ohos.permission.VIBRATE (a system permission)

**System capability**: SystemCapability.Sensors.MiscDevice


**Parameters**
| Name    | Type   | Mandatory | Description         |
| -------- | ------ | ---- | ------------ |
| duration | number | Yes  | Vibration duration. |

**Return value**
| Type                | Description        |
| ------------------- | ----------- |
| Promise&lt;void&gt; | Promise used to indicate whether the vibration is triggered successfully. |


**Example**
  ```js
  vibrator.vibrate(1000).then(()=>{
      console.log("Promise returned to indicate a successful vibration.");
  }, (error)=>{
      console.log("error.code"+error.code+"error.message"+error.message);
  });
  ```


## vibrator.vibrate

vibrate(duration: number, callback?: AsyncCallback&lt;void&gt;): void

Triggers vibration with a specific duration. This API uses an asynchronous callback to return the execution result.

**Required permissions**: ohos.permission.VIBRATE (a system permission)

**System capability**: SystemCapability.Sensors.MiscDevice

**Parameters**
| Name    | Type                      | Mandatory | Description                    |
| -------- | ------------------------- | ---- | ----------------------- |
| duration | number                   | Yes  | Vibration duration.          |
| callback | AsyncCallback&lt;void&gt; | No  | Callback used to indicate whether the vibration is triggered successfully. |

**Example**
  ```js
  vibrator.vibrate(1000,function(error){
      if(error){
          console.log("error.code"+error.code+"error.message"+error.message);
      }else{
          console.log("Callback returned to indicate a successful vibration.");
      }
  })
  ```


## vibrator.vibrate

vibrate(effectId: EffectId): Promise&lt;void&gt;

Triggers vibration with a specific effect. This API uses a promise to return the execution result.

**Required permissions**: ohos.permission.VIBRATE (a system permission)

**System capability**: SystemCapability.Sensors.MiscDevice

**Parameters**
| Name    | Type                  | Mandatory | Description          |
| -------- | --------------------- | ---- | ------------- |
| effectId | [EffectId](#effectid) | Yes  | String that indicates the vibration effect. |

**Return value**
| Type                | Description        |
| ------------------- | ----------- |
| Promise&lt;void&gt; | Promise used to indicate whether the vibration is triggered successfully. |

**Example**
  ```js
  vibrator.vibrate(vibrator.EffectId.EFFECT_CLOCK_TIMER).then(()=>{
      console.log("Promise returned to indicate a successful vibration.");
  }, (error)=>{
      console.log("error.code"+error.code+"error.message"+error.message);
  });
  ```


## vibrator.vibrate

vibrate(effectId: EffectId, callback?: AsyncCallback&lt;void&gt;): void

Triggers vibration with a specific effect. This API uses an asynchronous callback to return the execution result.

**Required permissions**: ohos.permission.VIBRATE (a system permission)

**System capability**: SystemCapability.Sensors.MiscDevice

**Parameters**
| Name    | Type                      | Mandatory | Description                    |
| -------- | ------------------------- | ---- | ----------------------- |
| effectId | [EffectId](#effectid)    | Yes  | String that indicates the vibration effect.         |
| callback | AsyncCallback&lt;void&gt; | No  | Callback used to indicate whether the vibration is triggered successfully. |

**Example**
  ```js
  vibrator.vibrate(vibrator.EffectId.EFFECT_CLOCK_TIMER, function(error){
      if(error){
          console.log("error.code"+error.code+"error.message"+error.message);
      }else{
          console.log("Callback returned to indicate a successful vibration.");
      }
  })
  ```


## vibrator.stop

stop(stopMode: VibratorStopMode): Promise&lt;void&gt;

Stops the vibration based on the specified **stopMode**. This API uses a promise to return the execution result. If the specified **stopMode** is different from the mode used to trigger the vibration, this API fails to be called.

**Required permissions**: ohos.permission.VIBRATE (a system permission)

**System capability**: SystemCapability.Sensors.MiscDevice

**Parameters**
| Name     | Type                                  | Mandatory | Description |
| -------- | ------------------------------------- | ---- | --------------- |
| stopMode | [VibratorStopMode](#vibratorstopmode) | Yes  | Vibration mode to stop. |

**Return value**
| Type                | Description |
| ------------------- | ----------- |
| Promise&lt;void&gt; | Promise used to indicate whether the vibration is stopped successfully. |

**Example**
  ```js
  vibrator.stop(vibrator.VibratorStopMode.VIBRATOR_STOP_MODE_PRESET).then(()=>{
      console.log("Promise returned to indicate a successful vibration.");
  }, (error)=>{
      console.log("error.code"+error.code+"error.message"+error.message);
  });
  ```


## vibrator.stop

stop(stopMode: VibratorStopMode, callback?: AsyncCallback&lt;void&gt;): void;

Stops the vibration based on the specified **stopMode**. This API uses an asynchronous callback to return the execution result. If the specified **stopMode** is different from the mode used to trigger the vibration, this API fails to be called.

**Required permissions**: ohos.permission.VIBRATE (a system permission)

**System capability**: SystemCapability.Sensors.MiscDevice

**Parameters**
| Name | Type | Mandatory | Description |
| -------- | ------------------------------------- | ---- | ----------------------- |
| stopMode | [VibratorStopMode](#vibratorstopmode) | Yes | Vibration mode to stop. |
| callback | AsyncCallback&lt;void&gt; | No | Callback used to indicate whether the vibration is stopped successfully. |

**Example**
  ```js
  vibrator.stop(vibrator.VibratorStopMode.VIBRATOR_STOP_MODE_PRESET, function(error){
      if(error){
          console.log("error.code"+error.code+"error.message"+error.message);
      }else{
          console.log("Callback returned to indicate successful.");
      }
  })
  ```


## EffectId

Describes the vibration effect.

**System capability**: SystemCapability.Sensors.MiscDevice

| Name               | Default Value        | Description                                                     |
| ------------------ | -------------------- | --------------------------------------------------------------- |
| EFFECT_CLOCK_TIMER | "haptic.clock.timer" | Vibration effect of the vibrator when a user adjusts the timer. |


## VibratorStopMode

Describes the vibration mode to stop.

**System capability**: SystemCapability.Sensors.MiscDevice

| Name | Default Value | Description |
| ------------------------- | -------- | ---------------------------------------- |
| VIBRATOR_STOP_MODE_TIME  | "time"  | The vibration to stop is in **duration** mode. This vibration is triggered with the parameter **duration** of the **number** type. |
| VIBRATOR_STOP_MODE_PRESET | "preset" | The vibration to stop is in **EffectId** mode. This vibration is triggered with the parameter **effectId** of the **EffectId** type. |
