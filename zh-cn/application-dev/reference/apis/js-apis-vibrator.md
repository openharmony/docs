# 振动

vibrator模块提供控制马达振动的能力，如通过接口控制马达启动马达振动，停止马达振动等。

> **说明：**
>
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```js
import vibrator from '@ohos.vibrator';
```

## vibrator.vibrate

vibrate(duration: number): Promise&lt;void&gt;

按照指定持续时间触发马达振动。

**需要权限**：ohos.permission.VIBRATE，该权限为系统权限

**系统能力**：SystemCapability.Sensors.MiscDevice

**参数：** 

| 参数名   | 类型   | 必填 | 说明                   |
| -------- | ------ | ---- | ---------------------- |
| duration | number | 是   | 马达振动时长, 单位ms。 |

**返回值：** 

| 类型                | 说明                                   |
| ------------------- | -------------------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**示例：** 

  ```js
  vibrator.vibrate(1000).then(()=>{
      console.log("Promise returned to indicate a successful vibration.");
  }, (error)=>{
      console.log("error.code"+error.code+"error.message"+error.message);
  });
  ```

## vibrator.vibrate<sup>9+</sup>

vibrate(effect: VibrateEffect, attribute: VibrateAttribute): Promise&lt;void&gt;

按照指定振动效果和振动属性触发马达振动。

**需要权限**：ohos.permission.VIBRATE，该权限为系统权限

**系统能力**：SystemCapability.Sensors.MiscDevice

**参数：** 

| 参数名    | 类型                                               | 必填 | 说明           |
| --------- | -------------------------------------------------- | ---- | :------------- |
| effect    | [VibrateEffect](#vibrateeffect<sup>9+</sup>)       | 是   | 马达振动效果。 |
| attribute | [VibrateAttribute](#vibrateattribute<sup>9+</sup>) | 是   | 马达振动属性。 |

**返回值：** 

| 类型                | 说明                                   |
| ------------------- | -------------------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**示例：** 

```js
vibrator.vibrate({
    type: 'time',
    duration: 1000
}, {
   	id: 0,
    usage: 'alarm'
}).then((result)=>{
    console.log("Promise returned to indicate a successful vibration");
}).catch((error)=>{
    console.log("error.code"+error.code+"error.message"+error.message);
})
```

## vibrator.vibrate

vibrate(duration: number, callback?: AsyncCallback&lt;void&gt;): void

按照指定持续时间触发马达振动。

**需要权限**：ohos.permission.VIBRATE，该权限为系统权限

**系统能力**：SystemCapability.Sensors.MiscDevice

**参数：** 
| 参数名   | 类型                      | 必填 | 说明                                                       |
| -------- | ------------------------- | ---- | ---------------------------------------------------------- |
| duration | number                    | 是   | 马达振动时长, 单位ms。                                     |
| callback | AsyncCallback&lt;void&gt; | 否   | 回调函数。当马达振动成功，err为undefined，否则为错误对象。 |

**示例：** 

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

按照预置振动效果触发马达振动。

**需要权限**：ohos.permission.VIBRATE，该权限为系统权限

**系统能力**：SystemCapability.Sensors.MiscDevice

**参数：** 
| 参数名   | 类型                  | 必填 | 说明               |
| -------- | --------------------- | ---- | ------------------ |
| effectId | [EffectId](#effectid) | 是   | 预置的振动效果ID。 |

**返回值：** 
| 类型                | 说明                                   |
| ------------------- | -------------------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**示例：** 
  ```js
  vibrator.vibrate(vibrator.EffectId.EFFECT_CLOCK_TIMER).then(()=>{
      console.log("Promise returned to indicate a successful vibration.");
  }, (error)=>{
      console.log("error.code"+error.code+"error.message"+error.message);
  });
  ```


## vibrator.vibrate

vibrate(effectId: EffectId, callback?: AsyncCallback&lt;void&gt;): void

按照指定振动效果触发马达振动。

**需要权限**：ohos.permission.VIBRATE，该权限为系统权限

**系统能力**：SystemCapability.Sensors.MiscDevice

**参数：** 
| 参数名   | 类型                      | 必填 | 说明                                                       |
| -------- | ------------------------- | ---- | ---------------------------------------------------------- |
| effectId | [EffectId](#effectid)     | 是   | 预置的振动效果ID。                                         |
| callback | AsyncCallback&lt;void&gt; | 否   | 回调函数。当马达振动成功，err为undefined，否则为错误对象。 |

**示例：** 

  ```js
  vibrator.vibrate(vibrator.EffectId.EFFECT_CLOCK_TIMER, function(error){
      if(error){
          console.log("error.code"+error.code+"error.message"+error.message);
      }else{
          console.log("Callback returned to indicate a successful vibration.");
      }
  })
  ```

## vibrator.vibrate<sup>9+</sup>

vibrate(effect: VibrateEffect, attribute: VibrateAttribute, callback: AsyncCallback&lt;void&gt;): void

按照指定振动效果和振动属性触发马达振动。

**需要权限**：ohos.permission.VIBRATE，该权限为系统权限

**系统能力**：SystemCapability.Sensors.MiscDevice

**参数：** 

| 参数名    | 类型                                               | 必填 | 说明                                                       |
| --------- | -------------------------------------------------- | ---- | :--------------------------------------------------------- |
| effect    | [VibrateEffect](#VibrateEffect<sup>9+</sup>)       | 是   | 马达振动效果。                                             |
| attribute | [VibrateAttribute](#vibrateattribute<sup>9+</sup>) | 是   | 马达振动属性。                                             |
| callback  | AsyncCallback&lt;void&gt;                          | 是   | 回调函数。当马达振动成功，err为undefined，否则为错误对象。 |

示例：

```js
vibrator.vibrate({
    type:'time',
    duration:1000,
},{
    id:0,
    usage: 'alarm'
}, (error)=>{
    if(error){
        console.log(TAG + " fail, error.code:"+error.code+",error.message:"+error.message);
    }else{
        console.log("Callback returned to indicate a successful vibration.");
    }
});
```

## vibrator.stop

stop(stopMode: VibratorStopMode): Promise&lt;void&gt;

按照要停止指定的振动模式来停止马达的振动。如果要停止的振动模式与触发马达振动时的模式不相同，则调用本接口会失败。

**需要权限**：ohos.permission.VIBRATE，该权限为系统权限

**系统能力**：SystemCapability.Sensors.MiscDevice

**参数：** 
| 参数名   | 类型                                  | 必填 | 说明                     |
| -------- | ------------------------------------- | ---- | ------------------------ |
| stopMode | [VibratorStopMode](#vibratorstopmode) | 是   | 马达停止指定的振动模式。 |

**返回值：** 

| 类型                | 说明                                   |
| ------------------- | -------------------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**示例：** 

  ```js
  vibrator.stop(vibrator.VibratorStopMode.VIBRATOR_STOP_MODE_PRESET).then(()=>{
      console.log("Promise returned to indicate a successful vibration.");
  }, (error)=>{
      console.log("error.code"+error.code+"error.message"+error.message);
  });
  ```


## vibrator.stop

stop(stopMode: VibratorStopMode, callback?: AsyncCallback&lt;void&gt;): void;

按照要停止指定的振动模式来停止马达的振动。如果要停止的振动模式与触发马达振动时的模式不相同，则调用本接口会失败。

**需要权限**：ohos.permission.VIBRATE，该权限为系统权限

**系统能力**：SystemCapability.Sensors.MiscDevice

**参数：** 
| 参数名   | 类型                                  | 必填 | 说明                                                         |
| -------- | ------------------------------------- | ---- | ------------------------------------------------------------ |
| stopMode | [VibratorStopMode](#vibratorstopmode) | 是   | 马达停止指定的振动模式。                                     |
| callback | AsyncCallback&lt;void&gt;             | 否   | 回调函数。当马达停止振动成功，err为undefined，否则为错误对象。 |

**示例：** 

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

马达振动效果的字符串。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Sensors.MiscDevice

| 名称               | 默认值               | 说明               |
| ------------------ | -------------------- | ------------------ |
| EFFECT_CLOCK_TIMER | "haptic.clock.timer" | 预置的振动效果ID。 |


## VibratorStopMode

马达要停止指定的振动模式。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Sensors.MiscDevice

| 名称                      | 默认值   | 说明                                                         |
| ------------------------- | -------- | ------------------------------------------------------------ |
| VIBRATOR_STOP_MODE_TIME   | "time"   | 停止模式为duration模式的振动。即触发振动时参数类型为number，参数本身为振动持续时间的触发方式。 |
| VIBRATOR_STOP_MODE_PRESET | "preset" | 停止模式为预置EffectId的振动。即触发振动时参数类型为EffectId，参数本身为马达振动效果的字符串的触发方式。 |

## VibrateEffect<sup>9+</sup>

| 类型                                         | 说明                           |
| -------------------------------------------- | ------------------------------ |
| [VibrateTime](#vibratetime<sup>9+</sup>)     | 按照指定持续时间触发马达振动。 |
| [VibratePreset](#vibratepreset<sup>9+</sup>) | 按照预置振动类型触发马达振动。 |

## VibrateTime<sup>9+</sup>

马达振动时长。

| 名称     | 默认值 | 说明                           |
| -------- | ------ | ------------------------------ |
| type     | "time" | 按照指定持续时间触发马达振动。 |
| duration | -      | 马达振动时长, 单位ms。         |

## VibratePreset<sup>9+</sup>

马达预置振动类型。

| 名称     | 默认值   | 说明                           |
| -------- | -------- | ------------------------------ |
| type     | "preset" | 按照预置振动效果触发马达振动。 |
| effectId | -        | 预置的振动效果ID。             |
| count    | -        | 重复振动的次数。               |

## VibrateAttribute<sup>9+</sup>

马达振动属性。

| 名称  | 默认值 | 说明           |
| ----- | ------ | -------------- |
| id    | 0      | 振动器id。     |
| usage | -      | 马达振动场景。 |

## Usage<sup>9+</sup>

振动使用场景。

| 名称             | 类型   | 说明                           |
| ---------------- | ------ | ------------------------------ |
| unknown          | string | 没有明确使用场景，最低优先级。 |
| alarm            | string | 用于警报振动的场景。           |
| ring             | string | 用于铃声振动的场景。           |
| notification     | string | 用于通知振动的场景。           |
| communication    | string | 用于通信振动的场景。           |
| touch            | string | 用于触摸振动的场景。           |
| media            | string | 用于多媒体振动的场景。         |
| physicalFeedback | string | 用于物理反馈振动的场景。       |
| simulateReality  | string | 用于模拟现实振动的场景。       |

