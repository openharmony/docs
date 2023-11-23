# @ohos.accessibility.config    
本模块提供系统辅助功能的配置，包括辅助扩展的启用与关闭、高对比度文字显示、鼠标键、无障碍字幕配置等。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import config from '@ohos.accessibility.config'    
```  
    
## 属性    
 **系统能力:**  SystemCapability.BarrierFree.Accessibility.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| highContrastText | Config<boolean> | false | true | 表示高对比度文字功能启用状态。 |  
| invertColor | Config<boolean> | false | true | 表示颜色反转功能启用状态。 |  
| daltonizationColorFilter | Config<DaltonizationColorFilter> | false | true | 表示颜色滤镜功能配置。 |  
| contentTimeout | Config<number> | false | true | 表示内容显示建议时长配置。取值 0~5000，单位为毫秒。 |  
| animationOff | Config<boolean> | false | true | 表示关闭动画功能启用状态。 |  
| brightnessDiscount | Config<number> | false | true | 表示亮度折扣系统配置。取值 0~1.0。 |  
| mouseKey | Config<boolean> | false | true | 表示鼠标键功能启用状态。 |  
| mouseAutoClick | Config<number> | false | true | 表示鼠标自动点击功能启用状态。取值 0~5000，单位为毫秒。 |  
| shortkey | Config<boolean> | false | true | 表示辅助扩展快捷键功能启用状态。 |  
| shortkeyTarget | Config<string> | false | true | 表示辅助扩展快捷键的目标配置。取值为辅助应用的名称，格式为：'bundleName/abilityName'。 |  
| captions | Config<boolean> | false | true | 表示辅助字幕功能启用状态。 |  
| captionsStyle | Config<accessibility.CaptionsStyle> | false | true |  表示辅助字幕的配置。 |  
    
 **常量：**     
 **系统能力:**  SystemCapability.BarrierFree.Accessibility.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 值 | 说明 |  
| --------| --------| --------| --------|  
| daltonizationState<sup>(11+)</sup> | Config<boolean> |  | 表示颜色滤镜功能启动状态。 |  
| audioMono<sup>(10+)</sup> | Config<boolean> |  | 表示音频单声道的配置。True表示打开单声道，False表示关闭单声道。 。 |  
| audioBalance<sup>(10+)</sup> | Config<number> |  | 表示左右声道音量平衡的配置。取值 -1.0~1.0。 |  
    
## enableAbility    
启用辅助扩展，使用Promise异步回调。  
 **调用形式：**     
    
- enableAbility(name: string, capability: Array\<accessibility.Capability>): Promise\<void>    
起始版本： 9    
- enableAbility(     name: string,     capability: Array\<accessibility.Capability>,     callback: AsyncCallback\<void>   ): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BarrierFree.Accessibility.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name | string | true | 辅助应用的名称，格式为：'bundleName/abilityName'。  |  
| capability | Array<accessibility.Capability> | true | 辅助应用的能力属性。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 9300001 | Invalid bundle name or ability name. |  
| 9300002 | Target ability already enabled. |  
    
 **示例代码：**   
```ts    
import accessibility from '@ohos.accessibility';  
import config from '@ohos.accessibility.config';  
  
let name: string = 'com.ohos.example/axExtension';  
let capability : accessibility.Capability[] = ['retrieve'];  
try {  
    config.enableAbility(name, capability).then(() => {  
      console.info('enable ability succeed');  
    }).catch((err: object) => {  
      console.error('failed to enable ability, because ' + JSON.stringify(err));  
    });  
} catch (exception) {  
    console.error('failed to enable ability, because ' + JSON.stringify(exception));  
};  
    
```    
  
    
## disableAbility    
关闭辅助扩展，使用Promise异步回调。  
 **调用形式：**     
    
- disableAbility(name: string): Promise\<void>    
起始版本： 9    
- disableAbility(name: string, callback: AsyncCallback\<void>): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BarrierFree.Accessibility.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name | string | true | 辅助应用的名称，格式为：'bundleName/abilityName'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 9300001 | Invalid bundle name or ability name. |  
    
 **示例代码：**   
```ts    
import accessibility from '@ohos.accessibility';  
import config from '@ohos.accessibility.config';  
  
let name: string = 'com.ohos.example/axExtension';  
try {  
    config.disableAbility(name).then(() => {  
      console.info('disable ability succeed');  
    }).catch((err: object) => {  
      console.error('failed to disable ability, because ' + JSON.stringify(err));  
    });  
} catch (exception) {  
    console.error('failed to disable ability, because ' + JSON.stringify(exception));  
};  
    
```    
  
    
## on('enabledAccessibilityExtensionListChange')    
添加启用的辅助扩展的列表变化监听，使用callback异步回调。  
 **调用形式：**     
    
- on(type: 'enabledAccessibilityExtensionListChange', callback: Callback\<void>): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BarrierFree.Accessibility.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 参数固定为enabledAccessibilityExtensionListChange，监听启用的辅助扩展的列表变化。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，在启用的辅助扩展的列表变化时通过此函数进行通知。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
    
 **示例代码：**   
```ts    
import config from '@ohos.accessibility.config';  
  
try {  
    config.on('enabledAccessibilityExtensionListChange', () => {  
        console.info('subscribe enabled accessibility extension list change state success');  
    });  
} catch (exception) {  
    console.error('failed to subscribe enabled accessibility extension list change state, because ' +  
    JSON.stringify(exception));  
};  
    
```    
  
    
## off('enabledAccessibilityExtensionListChange')    
取消启用的辅助扩展的列表变化监听，使用callback异步回调。  
 **调用形式：**     
    
- off(type: 'enabledAccessibilityExtensionListChange', callback?: Callback\<void>): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BarrierFree.Accessibility.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 参数固定为enabledAccessibilityExtensionListChange，监听启用的辅助扩展的列表变化。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 取消指定callback对象的事件响应。需与on('enabledAccessibilityExtensionListChange')的callback一致。缺省时，表示注销所有已注册事件。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
    
 **示例代码：**   
```ts    
import config from '@ohos.accessibility.config';  
  
try {  
    config.off('enabledAccessibilityExtensionListChange', () => {  
        console.info('Unsubscribe enabled accessibility extension list change state success');  
    });  
} catch (exception) {  
    console.error('failed to Unsubscribe enabled accessibility extension list change state, because ' +  
    JSON.stringify(exception));  
};  
    
```    
  
    
## Config    
用于属性的设置、获取与监听。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BarrierFree.Accessibility.Core    
### set    
设置属性，使用Promise异步回调。  
 **调用形式：**     
    
- set(value: T): Promise\<void>    
起始版本： 9    
- set(value: T, callback: AsyncCallback\<void>): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BarrierFree.Accessibility.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | T | true | 设置的属性值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
    
 **示例代码：**   
```ts    
import config from '@ohos.accessibility.config';  
  
let value: boolean = true;  
try {  
    config.highContrastText.set(value).then(() => {  
        console.info('set highContrastText succeed');  
    }).catch((err: object) => {  
        console.error('failed to set highContrastText, because ' + JSON.stringify(err));  
    });  
} catch (exception) {  
    console.error('failed to set config, because ' + JSON.stringify(exception));  
};  
    
```    
  
    
### get    
获取属性，使用Promise异步回调。  
 **调用形式：**     
    
- get(): Promise\<T>    
起始版本： 9    
- get(callback: AsyncCallback\<T>): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BarrierFree.Accessibility.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回属性值。 |  
| Promise<T> | Promise对象，返回对应属性值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
    
 **示例代码：**   
```ts    
import config from '@ohos.accessibility.config';  
import { BusinessError } from '@ohos.base';  
  
let value: boolean;  
config.highContrastText.get().then((data: boolean) => {  
    value = data;  
    console.info('get highContrastText success');  
}).catch((err: object) => {  
    console.error('failed to get highContrastText, because ' + JSON.stringify(err));  
});  
    
```    
  
    
### on    
添加属性变化监听，使用callback异步回调。  
 **调用形式：**     
    
- on(callback: Callback\<T>): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BarrierFree.Accessibility.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，在属性变化时通过此函数进行通知。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
    
 **示例代码：**   
```ts    
import config from '@ohos.accessibility.config';  
  
try {  
    config.highContrastText.on((data: boolean) => {  
        console.info('subscribe highContrastText success, result: ' + JSON.stringify(data));  
    });  
} catch (exception) {  
    console.error('failed subscribe highContrastText, because ' + JSON.stringify(exception));  
}  
    
```    
  
    
### off    
取消属性变化监听，使用callback异步回调。  
 **调用形式：**     
    
- off(callback?: Callback\<T>): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BarrierFree.Accessibility.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 取消指定callback对象的事件响应。需与on()的callback一致。缺省时，表示注销所有已注册事件。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
    
 **示例代码：**   
```ts    
import config from '@ohos.accessibility.config';  
  
config.highContrastText.off((data: boolean) => {  
    console.info('Unsubscribe highContrastText success, result: ' + JSON.stringify(data));  
});    
```    
  
    
## DaltonizationColorFilter    
用于不同弱视类型的校正颜色滤镜。    
颜色滤镜功能开启时（daltonizationState设置为true)，将无障碍保存的DaltonizationColorFilter的值设置进系统；颜色滤镜功能关闭时（daltonizationState设置为false)，显示为正常类型<sup>11+</sup>。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BarrierFree.Accessibility.Core    
    
| 取值范围 | 说明 |  
| --------| --------|  
| Normal | 表示正常类型。 |  
| Protanomaly | 表示红色弱视类型。 |  
| Deuteranomaly | 表示绿色弱视类型 |  
| Tritanomaly | 表示蓝色弱视类型。 |  
