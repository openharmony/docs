# @ohos.vibrator    
vibrator模块提供控制马达振动启、停的能力。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import vibrator from '@ohos.vibrator'    
```  
    
## vibrate<sup>(deprecated)</sup>    
按照指定持续时间触发马达振动。  
 **调用形式：**     
- vibrate(duration: number, callback?: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: vibrator#startVibration。  
 **系统能力:**  SystemCapability.Sensors.MiscDevice  
 **需要权限：** ohos.permission.VIBRATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| duration<sup>(deprecated)</sup> | number | true | 马达振动时长, 单位ms。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | false | 回调函数，当马达振动成功，err为undefined，否则为错误对象。 |  
    
 **示例代码：**   
```ts    
import vibrator from '@ohos.vibrator';  
import { BusinessError } from '@ohos.base';  
  
vibrator.vibrate(1000, (error: BusinessError) => {  
  if (error) {  
    console.error(`Failed to vibrate. Code: ${error.code}, message: ${error.message}`);  
  } else {  
    console.info('Succeed in vibrating');  
  }  
})  
    
```    
  
    
## vibrate<sup>(deprecated)</sup>    
按照指定持续时间触发马达振动。  
 **调用形式：**     
- vibrate(duration: number): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: vibrator#startVibration。  
 **系统能力:**  SystemCapability.Sensors.MiscDevice  
 **需要权限：** ohos.permission.VIBRATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| duration<sup>(deprecated)</sup> | number | true | 马达振动时长, 单位ms。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | Promise对象。 |  
    
 **示例代码：**   
```ts    
import vibrator from '@ohos.vibrator';  
import { BusinessError } from '@ohos.base';  
  
vibrator.vibrate(1000).then(() => {  
  console.info('Succeed in vibrating');  
}, (error: BusinessError) => {  
  console.error(`Failed to vibrate. Code: ${error.code}, message: ${error.message}`);  
});  
    
```    
  
    
## vibrate<sup>(deprecated)</sup>    
按照预置振动效果触发马达振动。  
 **调用形式：**     
- vibrate(effectId: EffectId): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: vibrator#startVibration。  
 **系统能力:**  SystemCapability.Sensors.MiscDevice  
 **需要权限：** ohos.permission.VIBRATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| effectId<sup>(deprecated)</sup> | EffectId | true | 预置的振动效果ID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | Promise对象。 |  
    
 **示例代码：**   
```ts    
import vibrator from '@ohos.vibrator';  
import { BusinessError } from '@ohos.base';  
  
vibrator.vibrate(vibrator.EffectId.EFFECT_CLOCK_TIMER).then(() => {  
  console.info('Succeed in vibrating');  
}, (error: BusinessError) => {  
  console.error(`Failed to vibrate. Code: ${error.code}, message: ${error.message}`);  
});  
    
```    
  
    
## vibrate<sup>(deprecated)</sup>    
按照指定振动效果触发马达振动。  
 **调用形式：**     
- vibrate(effectId: EffectId, callback?: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: vibrator#startVibration。  
 **系统能力:**  SystemCapability.Sensors.MiscDevice  
 **需要权限：** ohos.permission.VIBRATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| effectId<sup>(deprecated)</sup> | EffectId | true | 预置的振动效果ID。  |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | false | 回调函数，当马达振动成功，err为undefined，否则为错误对象。 |  
    
 **示例代码：**   
```ts    
import vibrator from '@ohos.vibrator';  
import { BusinessError } from '@ohos.base';  
  
vibrator.vibrate(vibrator.EffectId.EFFECT_CLOCK_TIMER, (error: BusinessError) => {  
  if (error) {  
    console.error(`Failed to vibrate. Code: ${error.code}, message: ${error.message}`);  
  } else {  
    console.info('Succeed in vibrating');  
  }  
})  
    
```    
  
    
## startVibration<sup>(9+)</sup>    
根据指定的振动效果和振动属性触发马达振动。  
 **调用形式：**     
    
- startVibration(effect: VibrateEffect, attribute: VibrateAttribute, callback: AsyncCallback\<void>): void    
起始版本： 9    
- startVibration(effect: VibrateEffect, attribute: VibrateAttribute): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Sensors.MiscDevice  
 **需要权限：** ohos.permission.VIBRATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| effect | VibrateEffect | true | 马达振动效果，支持三种：<br>1、[VibrateTime](#vibratetime9)：按照指定持续时间触发马达振动；<br>2、[VibratePreset](#vibratepreset9)：按照预置振动效果触发马达振动；<br>3、[VibrateFromFile](#vibratefromfile10)：按照自定义振动配置文件触发马达振动。 |  
| attribute | VibrateAttribute | true | 马达振动属性。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，当马达振动成功，err为undefined，否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 14600101 | Device operation failed. |  
    
 **示例代码1：**   
示例（callback）,<span style="letter-spacing: 0px;">按照指定持续时间触发马达振动：</span>  
```ts    
import vibrator from '@ohos.vibrator';  
import { BusinessError } from '@ohos.base';  
  
try {  
  vibrator.startVibration({  
    type: 'time',  
    duration: 1000,  
  }, {  
    id: 0,  
    usage: 'alarm'  
  }, (error: BusinessError) => {  
    if (error) {  
      console.error(`Failed to start vibration. Code: ${error.code}, message: ${error.message}`);  
      return;  
    }  
    console.info('Succeed in starting vibration');  
  });  
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（callback）,<span style="letter-spacing: 0px;">按照自定义振动配置文件触发马达振动：</span>  
  
```ts    
import vibrator from '@ohos.vibrator';  
import resourceManager from '@ohos.resourceManager';  
import { BusinessError } from '@ohos.base';  
  
const fileName: string = 'xxx.json';  
  
let rawFd: resourceManager.RawFileDescriptor = getContext().resourceManager.getRawFdSync(fileName);  
  
try {  
  vibrator.startVibration({  
    type: "file",  
    hapticFd: { fd: rawFd.fd, offset: rawFd.offset, length: rawFd.length }  
  }, {  
    id: 0,  
    usage: 'alarm'  
  }, (error: BusinessError) => {  
    if (error) {  
      console.error(`Failed to start vibration. Code: ${error.code}, message: ${error.message}`);  
      return;  
    }  
    console.info('Succeed in starting vibration');  
  });  
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);  
}  
  
getContext().resourceManager.closeRawFdSync(fileName);  
    
```    
  
    
 **示例代码3：**   
示例（Promise）,<span style="letter-spacing: 0px;">按照指定持续时间触发马达振动</span><span style="letter-spacing: 0px;">:</span>  
```ts    
import vibrator from '@ohos.vibrator';  
import { BusinessError } from '@ohos.base';  
  
try {  
  vibrator.startVibration({  
    type: 'time',  
    duration: 1000  
  }, {  
    id: 0,  
    usage: 'alarm'  
  }).then(() => {  
    console.info('Succeed in starting vibration');  
  }, (error: BusinessError) => {  
    console.error(`Failed to start vibration. Code: ${error.code}, message: ${error.message}`);  
  });  
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
 **示例代码4：**   
示例（Promise）,<span style="letter-spacing: 0px;">按照预置振动效果触发马达振动：</span>  
  
```ts    
import vibrator from '@ohos.vibrator';  
import { BusinessError } from '@ohos.base';  
  
try {  
  vibrator.startVibration({  
    type: 'preset',  
    effectId: 'haptic.clock.timer',  
    count: 1,  
  }, {  
    id: 0,  
    usage: 'alarm'  
  }).then(() => {  
    console.info('Succeed in starting vibration');  
  }, (error: BusinessError) => {  
    console.error(`Failed to start vibration. Code: ${error.code}, message: ${error.message}`);  
  });  
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
 **示例代码5：**   
示例（Promise）,<span style="letter-spacing: 0px;">按照自定义振动配置文件触发马达振动：</span>  
  
```ts    
import vibrator from '@ohos.vibrator';  
import resourceManager from '@ohos.resourceManager';  
import { BusinessError } from '@ohos.base';  
  
const fileName: string = 'xxx.json';  
  
let rawFd: resourceManager.RawFileDescriptor = getContext().resourceManager.getRawFdSync(fileName);  
  
try {  
  vibrator.startVibration({  
    type: "file",  
    hapticFd: { fd: rawFd.fd, offset: rawFd.offset, length: rawFd.length }  
  }, {  
    id: 0,  
    usage: 'alarm'  
  }).then(() => {  
    console.info('Succeed in starting vibration');  
  }, (error: BusinessError) => {  
    console.error(`Failed to start vibration. Code: ${error.code}, message: ${error.message}`);  
  });  
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);  
}  
  
getContext().resourceManager.closeRawFdSync(fileName);  
    
```    
  
    
## stopVibration<sup>(9+)</sup>    
按照指定模式停止马达振动。  
 **调用形式：**     
    
- stopVibration(stopMode: VibratorStopMode): Promise\<void>    
起始版本： 9    
- stopVibration(stopMode: VibratorStopMode, callback: AsyncCallback\<void>): void    
起始版本： 9    
- stopVibration(callback: AsyncCallback\<void>): void    
起始版本： 10    
- stopVibration(): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Sensors.MiscDevice  
 **需要权限：** ohos.permission.VIBRATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| stopMode | VibratorStopMode | true | 指定的停止振动模式，支持两种：<br>VIBRATOR_STOP_MODE_TIME：停止固定时长振动；<br>VIBRATOR_STOP_MODE_PRESET：停止预置振动。<br>此接口无法停止自定义振动，请使用[vibrator.stopVibration<sup>10+</sup>](#vibratorstopvibration10)。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，当马达停止振动成功，err为undefined，否则为错误对象。 |  
| Promise<void> | Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）,<span style="letter-spacing: 0px;">停止固定时长振动：</span>  
```ts    
import vibrator from '@ohos.vibrator';  
import { BusinessError } from '@ohos.base';  
  
try {  
  // 按照固定时长振动  
  vibrator.startVibration({  
    type: 'time',  
    duration: 1000,  
  }, {  
    id: 0,  
    usage: 'alarm'  
  }, (error: BusinessError) => {  
    if (error) {  
      console.error(`Failed to start vibration. Code: ${error.code}, message: ${error.message}`);  
      return;  
    }  
    console.info('Succeed in starting vibration');  
  });  
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);  
}  
  
try {  
  // 按照VIBRATOR_STOP_MODE_TIME模式停止振动  
  vibrator.stopVibration(vibrator.VibratorStopMode.VIBRATOR_STOP_MODE_TIME, (error: BusinessError) => {  
    if (error) {  
      console.error(`Failed to stop vibration. Code: ${error.code}, message: ${error.message}`);  
      return;  
    }  
    console.info('Succeed in stopping vibration');  
  })  
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（callback）,<span style="letter-spacing: 0px;">停止预置振动：</span>  
  
```ts    
import vibrator from '@ohos.vibrator';  
import { BusinessError } from '@ohos.base';  
  
try {  
  // 按照预置效果振动  
  vibrator.startVibration({  
    type: 'preset',  
    effectId: 'haptic.clock.timer',  
    count: 1,  
  }, {  
    id: 0,  
    usage: 'alarm'  
  }, (error: BusinessError) => {  
    if (error) {  
      console.error(`Failed to start vibration. Code: ${error.code}, message: ${error.message}`);  
      return;  
    }  
    console.info('Succeed in starting vibration');  
  });  
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);  
}  
  
try {  
  // 按照VIBRATOR_STOP_MODE_PRESET模式停止振动  
  vibrator.stopVibration(vibrator.VibratorStopMode.VIBRATOR_STOP_MODE_PRESET, (error: BusinessError) => {  
    if (error) {  
      console.error(`Failed to stop vibration. Code: ${error.code}, message: ${error.message}`);  
      return;  
    }  
    console.info('Succeed in stopping vibration');  
  })  
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
 **示例代码3：**   
示例（Promise）,<span style="letter-spacing: 0px;">停止固定时长振动：</span>  
```ts    
import vibrator from '@ohos.vibrator';  
import { BusinessError } from '@ohos.base';  
  
try {  
  // 按照固定时长振动  
  vibrator.startVibration({  
    type: 'time',  
    duration: 1000,  
  }, {  
    id: 0,  
    usage: 'alarm'  
  }).then(() => {  
    console.info('Succeed in starting vibration');  
  }, (error: BusinessError) => {  
    console.error(`Failed to start vibration. Code: ${error.code}, message: ${error.message}`);  
  });  
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);  
}  
  
try {  
  // 按照VIBRATOR_STOP_MODE_TIME模式停止振动  
  vibrator.stopVibration(vibrator.VibratorStopMode.VIBRATOR_STOP_MODE_TIME).then(() => {  
    console.info('Succeed in stopping vibration');  
  }, (error: BusinessError) => {  
    console.error(`Failed to stop vibration. Code: ${error.code}, message: ${error.message}`);  
  });  
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
 **示例代码4：**   
示例（Promise）,<span style="letter-spacing: 0px;">停止预置振动：</span>  
  
```ts    
import vibrator from '@ohos.vibrator';  
import { BusinessError } from '@ohos.base';  
  
try {  
  // 按照预置效果振动  
  vibrator.startVibration({  
    type: 'preset',  
    effectId: 'haptic.clock.timer',  
    count: 1,  
  }, {  
    id: 0,  
    usage: 'alarm'  
  }).then(() => {  
    console.info('Succeed in starting vibration');  
  }, (error: BusinessError) => {  
    console.error(`Failed to start vibration. Code: ${error.code}, message: ${error.message}`);  
  });  
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);  
}  
  
try {  
  // 按照VIBRATOR_STOP_MODE_PRESET模式停止振动  
  vibrator.stopVibration(vibrator.VibratorStopMode.VIBRATOR_STOP_MODE_PRESET).then(() => {  
    console.info('Succeed in stopping vibration');  
  }, (error: BusinessError) => {  
    console.error(`Failed to stop vibration. Code: ${error.code}, message: ${error.message}`);  
  });  
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## isSupportEffect<sup>(10+)</sup>    
查询是否支持传入参数effectId。  
 **调用形式：**     
    
- isSupportEffect(effectId: string, callback: AsyncCallback\<boolean>): void    
起始版本： 10    
- isSupportEffect(effectId: string): Promise\<boolean>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Sensors.MiscDevice    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| effectId | string | true |  预置的振动效果。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，当返回true则表示支持该effectId，否则不支持。 |  
| Promise<boolean> | Promise对象。当返回true则表示支持该effectId，否则不支持。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import vibrator from '@ohos.vibrator';  
import { BusinessError } from '@ohos.base';  
  
try {  
  // 查询是否支持'haptic.clock.timer'  
  vibrator.isSupportEffect('haptic.clock.timer', (err: BusinessError, state: boolean) => {  
    if (err) {  
      console.error(`Failed to query effect. Code: ${err.code}, message: ${err.message}`);  
      return;  
    }  
    console.info('Succeed in querying effect');  
    if (state) {  
      try {  
        // 使用startVibration需要添加ohos.permission.VIBRATE权限  
        vibrator.startVibration({  
          type: 'preset',  
          effectId: 'haptic.clock.timer',  
          count: 1,  
        }, {  
          usage: 'unknown'  
        }, (error: BusinessError) => {  
          if (error) {  
            console.error(`Failed to start vibration. Code: ${error.code}, message: ${error.message}`);  
          } else {  
            console.info('Succeed in starting vibration');  
          }  
        });  
      } catch (error) {  
        let e: BusinessError = error as BusinessError;  
        console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);  
      }  
    }  
  })  
} catch (error) {  
  let e: BusinessError = error as BusinessError;  
  console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import vibrator from '@ohos.vibrator';  
import { BusinessError } from '@ohos.base';  
  
try {  
  // 查询是否支持'haptic.clock.timer'  
  vibrator.isSupportEffect('haptic.clock.timer').then((state: boolean) => {  
    console.info(`The query result is ${state}`);  
    if (state) {  
      try {  
        vibrator.startVibration({  
          type: 'preset',  
          effectId: 'haptic.clock.timer',  
          count: 1,  
        }, {  
          usage: 'unknown'  
        }).then(() => {  
          console.info('Succeed in starting vibration');  
        }).catch((error: BusinessError) => {  
          console.error(`Failed to start vibration. Code: ${error.code}, message: ${error.message}`);  
        });  
      } catch (error) {  
        let e: BusinessError = error as BusinessError;  
        console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);  
      }  
    }  
  }, (error: BusinessError) => {  
    console.error(`Failed to query effect. Code: ${error.code}, message: ${error.message}`);  
  })  
} catch (error) {  
  let e: BusinessError = error as BusinessError;  
  console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## stop<sup>(deprecated)</sup>    
按照指定模式停止马达的振动。  
 **调用形式：**     
- stop(stopMode: VibratorStopMode): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: vibrator#stopVibration。  
 **系统能力:**  SystemCapability.Sensors.MiscDevice  
 **需要权限：** ohos.permission.VIBRATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| stopMode<sup>(deprecated)</sup> | VibratorStopMode | true | 马达停止指定的振动模式。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | Promise对象。 |  
    
 **示例代码：**   
```ts    
import vibrator from '@ohos.vibrator';  
import { BusinessError } from '@ohos.base';  
  
// 按照effectId类型启动振动  
vibrator.vibrate(vibrator.EffectId.EFFECT_CLOCK_TIMER, (error: BusinessError) => {  
  if (error) {  
    console.error(`Failed to vibrate. Code: ${error.code}, message: ${error.message}`);  
  } else {  
    console.info('Succeed in vibrating');  
  }  
})  
// 使用VIBRATOR_STOP_MODE_PRESET模式停止振动  
vibrator.stop(vibrator.VibratorStopMode.VIBRATOR_STOP_MODE_PRESET).then(() => {  
  console.info('Succeed in stopping');  
}, (error: BusinessError) => {  
  console.error(`Failed to stop. Code: ${error.code}, message: ${error.message}`);  
});  
    
```    
  
    
## stop<sup>(deprecated)</sup>    
按照指定模式停止马达的振动。  
 **调用形式：**     
- stop(stopMode: VibratorStopMode, callback?: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: vibrator#stopVibration。  
 **系统能力:**  SystemCapability.Sensors.MiscDevice  
 **需要权限：** ohos.permission.VIBRATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| stopMode<sup>(deprecated)</sup> | VibratorStopMode | true | 马达停止指定的振动模式。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | false |  回调函数，当马达停止振动成功，err为undefined，否则为错误对象。 |  
    
 **示例代码：**   
```ts    
import vibrator from '@ohos.vibrator';  
import { BusinessError } from '@ohos.base';  
  
// 按照effectId类型启动振动  
vibrator.vibrate(vibrator.EffectId.EFFECT_CLOCK_TIMER, (error: BusinessError) => {  
  if (error) {  
    console.error(`Failed to vibrate. Code: ${error.code}, message: ${error.message}`);  
  } else {  
    console.info('Succeed in vibrating');  
  }  
})  
// 使用VIBRATOR_STOP_MODE_PRESET模式停止振动  
vibrator.stop(vibrator.VibratorStopMode.VIBRATOR_STOP_MODE_PRESET, (error: BusinessError) => {  
  if (error) {  
    console.error(`Failed to stop. Code: ${error.code}, message: ${error.message}`);  
  } else {  
    console.info('Succeed in stopping');  
  }  
})  
    
```    
  
    
## EffectId    
预置的振动效果。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| EFFECT_CLOCK_TIMER | haptic.clock.timer | 描述用户调整计时器时的振动效果。 |  
    
## VibratorStopMode    
停止振动的模式。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| VIBRATOR_STOP_MODE_TIME | time | 停止duration模式的振动。 |  
| VIBRATOR_STOP_MODE_PRESET | preset | 停止预置EffectId的振动。 |  
    
## Usage<sup>(9+)</sup>    
振动使用场景。  
 **系统能力:**  SystemCapability.Sensors.MiscDevice    
    
| 取值范围 | 说明 |  
| --------| --------|  
| unknown | 没有明确使用场景，最低优先级。 |  
| alarm | 用于警报场景。 |  
| ring | 用于铃声场景。 |  
| notification | 用于通知场景。 |  
| communication | 用于通信场景。 |  
| touch | 用于触摸场景。 |  
| media | 用于多媒体场景。 |  
| physicalFeedback | 用于物理反馈场景。 |  
| simulateReality | 用于模拟现实场景。 |  
    
## VibrateAttribute<sup>(9+)</sup>    
马达振动属性。  
 **系统能力:**  SystemCapability.Sensors.MiscDevice    
### 属性    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| id | number | false | false | 振动器id， 默认值为0。 |  
| usage | Usage | false | true | 马达振动的使用场景。  |  
    
## VibrateEffect<sup>(9+)</sup>    
马达振动效果，支持以下三种。  
 **系统能力:**  SystemCapability.Sensors.MiscDevice    
    
| 取值范围 | 说明 |  
| --------| --------|  
| VibrateTime | 按照指定持续时间触发马达振动。 |  
| VibratePreset | 按照预置振动类型触发马达振动。 |  
| VibrateFromFile | 按照自定义振动配置文件触发马达振动。 |  
    
## VibrateTime<sup>(9+)</sup>    
固定时长振动类型。  
 **系统能力:**  SystemCapability.Sensors.MiscDevice    
### 属性    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| type | 'time' | false | true | 值为"time"，按照指定持续时间触发马达振动。 |  
| duration | number | false | true | 马达持续振动时长, 单位ms。 |  
    
## VibratePreset<sup>(9+)</sup>    
预置振动类型。  
 **系统能力:**  SystemCapability.Sensors.MiscDevice    
### 属性    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| type | 'preset' | false | true | 值为"preset"，按照预置振动效果触发马达振动。 |  
| effectId | string | false | true | 预置的振动效果ID。     |  
| count | number | false | true | 重复振动的次数。 |  
    
## VibrateFromFile<sup>(10+)</sup>    
自定义振动类型，仅部分设备支持，当设备不支持此振动类型时，返回[设备不支持错误码](../errorcodes/errorcode-universal.md)。  
 **系统能力:**  SystemCapability.Sensors.MiscDevice    
### 属性    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| type | 'file' | false | true | 值为"file"，按照振动配置文件触发马达振动。 |  
| hapticFd | HapticFileDescriptor | false | true | 振动配置文件的描述符。 |  
    
## HapticFileDescriptor<sup>(10+)</sup>    
自定义振动配置文件的描述符，必须确认资源文件可用，其参数可通过[文件管理API](js-apis-file-fs.md#fsopen)从沙箱路径获取或者通过[资源管理API](js-apis-resource-manager.md#getrawfd9)从HAP资源获取。使用场景：振动序列被存储在一个文件中，需要根据偏移量和长度进行振动，振动序列存储格式，请参考[自定义振动格式](../../device/vibrator-guidelines.md#自定义振动)。  
 **系统能力:**  SystemCapability.Sensors.MiscDevice    
### 属性    
 **系统能力:**  SystemCapability.Sensors.MiscDevice    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| fd<sup>(10+)</sup> | number | false | true |  资源文件描述符。 |  
| offset<sup>(10+)</sup> | number | false | false |  距文件起始位置的偏移量，单位为字节，默认为文件起始位置，不可超出文件有效范围。 |  
| length<sup>(10+)</sup> | number | false | false | 资源长度，单位为字节，默认值为从偏移位置至文件结尾的长度，不可超出文件有效范围。 |  
