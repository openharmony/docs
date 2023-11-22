# @ohos.animator    
本模块提供组件动画效果，包括定义动画、启动动画和以相反的顺序播放动画等。  
> **说明**   
>本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## AnimatorOptions  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| duration | number | false | true | 动画播放的时长，单位毫秒。   |  
| easing | string | false | true | 动画插值曲线，仅支持以下可选值：<br/>"linear"：动画线性变化。<br/>"ease"：动画开始和结束时的速度较慢，cubic-bezier(0.25、0.1、0.25、1.0)。<br/>"ease-in"：动画播放速度先慢后快，cubic-bezier(0.42, 0.0, 1.0, 1.0)。<br/>"ease-out"：动画播放速度先快后慢，cubic-bezier(0.0, 0.0, 0.58, 1.0)。<br/>"ease-in-out"：动画播放速度先加速后减速，cubic-bezier(0.42, 0.0, 0.58, 1.0)。<br/>"fast-out-slow-in"：标准曲线，cubic-bezier(0.4，0.0，0.2，1.0)。<br/>"linear-out-slow-in"：减速曲线，cubic-bezier(0.0，0.0，0.2，1.0)。<br/>"friction"：阻尼曲线，cubic-bezier(0.2, 0.0, 0.2, 1.0)。<br/>"extreme-deceleration"：急缓曲线，cubic-bezier(0.0, 0.0, 0.0, 1.0)。<br/>"rhythm"：节奏曲线，cubic-bezier(0.7, 0.0, 0.2, 1.0)。<br/>"sharp"：锐利曲线，cubic-bezier(0.33, 0.0, 0.67, 1.0)。<br/>"smooth"：平滑曲线，cubic-bezier(0.4, 0.0, 0.4, 1.0)。<br/>"cubic-bezier(x1,y1,x2,y2)"：三次贝塞尔曲线，x1、x2的值必须处于0-1之间。例如"cubic-bezier(0.42,0.0,0.58,1.0)"。<br/>"steps(number,step-position)"：阶梯曲线，number必须设置，为正整数，step-position参数可选，支持设置start或end，默认值为end。例如"steps(3,start)"。<br/>"interpolating-spring(velocity,mass,stiffness,damping)"：插值弹簧曲线，从API version 11开始支持且仅在ArkTS中支持使用。velocity、mass、stiffness、damping都是数值类型，且mass、stiffness、damping参数均应该大于0，具体参数含义参考[插值弹簧曲线](./js-apis-curve.md#curvesinterpolatingspring10)。使用interpolating-spring时，duration不生效，由弹簧参数决定；fill、direction、iterations设置无效，fill固定设置为"forwards"，direction固定设置为"normal"，iterations固定设置为1，且对animator的[reverse](#reverse)函数调用无效。即animator使用interpolating-spring时只能正向播放1次。 |  
| delay | number | false | true | 动画延时播放时长，单位毫秒，设置为0时，表示不延时。          。 |  
| fill | string | false | true | 动画执行后是否恢复到初始状态，动画执行后，动画结束时的状态（在最后一个关键帧中定义）将保留。<br/>"none"：在动画执行之前和之后都不会应用任何样式到目标上。<br/>"forwards"：在动画结束后，目标将保留动画结束时的状态（在最后一个关键帧中定义）。<br/>"backwards"：动画将在animation-delay期间应用第一个关键帧中定义的值。当animation-direction为"normal"或"alternate"时应用from关键帧中的值，当animation-direction为"reverse"或"alternate-reverse"时应用to关键帧中的值。<br/>"both"：动画将遵循forwards和backwards的规则，从而在两个方向上扩展动画属性。 |  
| direction | string | false | true | 动画播放模式。<br/>"normal"： 动画正向循环播放。<br/>"reverse"： 动画反向循环播放。<br/>"alternate"：动画交替循环播放，奇数次正向播放，偶数次反向播放。<br/>"alternate-reverse"：动画反向交替循环播放，奇数次反向播放，偶数次正向播放。 |  
| iterations | number | false | true | 动画播放次数。设置为0时不播放，设置为-1时无限次播放。<br/>**说明:** 设置为除-1外其他负数视为无效取值，无效取值动画默认播放1次。 |  
| begin | number | false | true | 动画插值起点。  |  
| end | number | false | true |  动画插值终点。   |  
    
## AnimatorResult    
定义Animator结果接口。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| onframe | (progress: number) => void | false | true | 接收到帧时回调。 |  
| onfinish | () => void | false | true | 动画完成时回调。 |  
| oncancel | () => void | false | true | 动画被取消时回调。 |  
| onrepeat | () => void | false | true | 动画重复时回调。 |  
    
### update<sup>(deprecated)</sup>    
更新当前动画器。  
 **调用形式：**     
- update(options: AnimatorOptions): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.animator.reset。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | AnimatorOptions | true | 定义动画选项。  |  
    
### reset<sup>(9+)</sup>    
更新当前动画器。  
 **调用形式：**     
- reset(options: AnimatorOptions): void  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | AnimatorOptions | true | 定义动画选项。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 100001 | if no page is found for pageId or fail to get object property list. |  
    
 **示例代码：**   
```ts    
import animator, { AnimatorOptions,AnimatorResult } from '@ohos.animator';  
import { BusinessError } from '@ohos.base';  
let options: AnimatorOptions = {  
  duration: 1500,  
  easing: "friction",  
  delay: 0,  
  fill: "forwards",  
  direction: "normal",  
  iterations: 3,  
  begin: 200.0,  
  end: 400.0  
};  
let optionsNew: AnimatorOptions = {  
  duration: 1500,  
  easing: "friction",  
  delay: 0,  
  fill: "forwards",  
  direction: "normal",  
  iterations: 5,  
  begin: 200.0,  
  end: 400.0  
};  
try {  
  let animatorResult:AnimatorResult|undefined = animator.create(options)  
  animatorResult.reset(options);  
} catch(error) {  
  let message = (error as BusinessError).message  
  let code = (error as BusinessError).code  
  console.error(`Animator reset failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
### play    
启动动画。动画会保留上一次的播放状态，比如播放状态设置reverse后，再次播放会保留reverse的播放状态。  
 **调用形式：**     
- play(): void  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **示例代码：**   
```ts    
animator.play();    
```    
  
    
### finish    
结束动画。  
 **调用形式：**     
- finish(): void  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **示例代码：**   
```ts    
animator.finish();    
```    
  
    
### pause    
暂停动画。  
 **调用形式：**     
- pause(): void  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **示例代码：**   
```ts    
animator.pause();    
```    
  
    
### cancel    
删除动画。  
 **调用形式：**     
- cancel(): void  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **示例代码：**   
```ts    
animator.cancel();    
```    
  
    
### reverse    
以相反的顺序播放动画。使用interpolating-spring曲线时此接口无效。  
 **调用形式：**     
- reverse(): void  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **示例代码：**   
```ts    
animator.reverse();    
```    
  
    
## Animator    
本模块提供组件动画效果，包括定义动画、启动动画和以相反的顺序播放动画等。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### createAnimator<sup>(deprecated)</sup>    
定义Animator类。  
 **调用形式：**     
- static createAnimator(options: AnimatorOptions): AnimatorResult  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.animator.create。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | AnimatorOptions | true | 定义动画选项。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| AnimatorResult | Animator结果接口。 |  
    
 **示例代码：**   
```ts    
import animator, { AnimatorOptions,AnimatorResult } from '@ohos.animator';  
let options: AnimatorOptions = { // xxx.js文件中不需要强调显式类型AnimatorOptions  
  duration: 1500,  
  easing: "friction",  
  delay: 0,  
  fill: "forwards",  
  direction: "normal",  
  iterations: 3,  
  begin: 200.0,  
  end: 400.0,  
};  
this.animator = animator.createAnimator(options);    
```    
  
    
### create<sup>(9+)</sup>    
定义Animator类。  
 **调用形式：**     
- static create(options: AnimatorOptions): AnimatorResult  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | AnimatorOptions | true | 定义动画选项。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| AnimatorResult | Animator结果接口。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import animator, { AnimatorOptions,AnimatorResult } from '@ohos.animator';  
let options: AnimatorOptions = {  
duration: 1500,  
easing: "friction",  
delay: 0,  
fill: "forwards",  
direction: "normal",  
iterations: 3,  
begin: 200.0,  
end: 400.0  
};  
animator.create(options);    
```    
  
