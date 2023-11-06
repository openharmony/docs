# @ohos.animator (动画)

本模块提供组件动画效果，包括定义动画、启动动画和以相反的顺序播放动画等。

> **说明：**
>
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块从API version 9开始支持在ArkTS中使用。
>
> 该模块不支持在[UIAbility](./js-apis-app-ability-uiAbility.md)的文件声明处使用，即不能在UIAbility的生命周期中调用，需要在创建组件实例后使用。
>
> 本模块功能依赖UI的执行上下文，不可在UI上下文不明确的地方使用，参见[UIContext](./js-apis-arkui-UIContext.md#uicontext)说明。
>
> 从API version 10开始，可以通过使用[UIContext](./js-apis-arkui-UIContext.md#uicontext)中的[createAnimator](./js-apis-arkui-UIContext.md#createanimator)来明确UI的执行上下文。

## 导入模块

```ts
import animator, { AnimatorOptions,AnimatorResult } from '@ohos.animator';
```
## create<sup>9+</sup>

create(options: AnimatorOptions): AnimatorResult

定义Animator类。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名     | 类型                                  | 必填   | 说明      |
| ------- | ----------------------------------- | ---- | ------- |
| options | [AnimatorOptions](#animatoroptions) | 是    | 定义动画选项。 |

**返回值：** 

| 类型                                | 说明            |
| --------------------------------- | ------------- |
| [AnimatorResult](#animatorresult) | Animator结果接口。 |

**示例：** 

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

## AnimatorResult

定义Animator结果接口。

### reset<sup>9+</sup>

reset(options: AnimatorOptions): void

更新当前动画器。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名     | 类型                                  | 必填   | 说明      |
| ------- | ----------------------------------- | ---- | ------- |
| options | [AnimatorOptions](#animatoroptions) | 是    | 定义动画选项。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.animator(动画)](../errorcodes/errorcode-animator.md)错误码。

| 错误码ID   | 错误信息 |
| --------- | ------- |
| 100001    | if no page is found for pageId or fail to get object property list. |


**示例：**

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
try {
  animator.reset(options);
} catch(error) {
  let message = (error as BusinessError).message
  let code = (error as BusinessError).code
  console.error(`Animator reset failed, error code: ${code}, message: ${message}.`);
}
```

### play

play(): void

启动动画。动画会保留上一次的播放状态，比如播放状态设置reverse后，再次播放会保留reverse的播放状态。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**示例：**

```ts
animator.play();
```

### finish

finish(): void

结束动画。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**示例：**

```ts
animator.finish();
```

### pause

pause(): void

暂停动画。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**示例：**

```ts
animator.pause();
```

### cancel

cancel(): void

删除动画。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**示例：**

```ts
animator.cancel();
```

### reverse

reverse(): void

以相反的顺序播放动画。使用interpolating-spring曲线时此接口无效。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**示例：**

```ts
animator.reverse();
```

### onframe

onframe: (progress: number) => void

接收到帧时回调。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名      | 类型     | 必填   | 说明       |
| -------- | ------ | ---- | -------- |
| progress | number | 是    | 动画的当前进度。 |

**示例：**

```ts
import animator, { AnimatorResult } from '@ohos.animator';
let animatorResult:AnimatorResult|undefined = animator.create(options)
animatorResult.onframe = (value)=> {
  console.info("onframe callback")
}
```

### onfinish

onfinish: () => void

动画完成时回调。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**示例：**

```ts
import animator, { AnimatorResult } from '@ohos.animator';
let animatorResult:AnimatorResult|undefined = animator.create(options)
animatorResult.onfinish = ()=> {
  console.info("onfinish callback")
}
```

### oncancel

oncancel: () => void

动画被取消时回调。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**示例：**

```ts
import animator, { AnimatorResult } from '@ohos.animator';
let animatorResult:AnimatorResult|undefined = animator.create(options)
animatorResult.oncancel = ()=> {
  console.info("oncancel callback")
}
```

### onrepeat

onrepeat: () => void

动画重复时回调。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**示例：**

```ts
import animator, { AnimatorResult } from '@ohos.animator';
let animatorResult:AnimatorResult|undefined = animator.create(options)
animatorResult.onrepeat = ()=> {
  console.info("onrepeat callback")
}
```



## AnimatorOptions

定义动画选项。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称       | 类型                                                        | 必填 | 说明                                                         |
| ---------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| duration   | number                                                      | 是   | 动画播放的时长，单位毫秒。                                   |
| easing     | string                                                      | 是   | 动画插值曲线，仅支持以下可选值：<br/>"linear"：动画线性变化。<br/>"ease"：动画开始和结束时的速度较慢，cubic-bezier(0.25、0.1、0.25、1.0)。<br/>"ease-in"：动画播放速度先慢后快，cubic-bezier(0.42, 0.0, 1.0, 1.0)。<br/>"ease-out"：动画播放速度先快后慢，cubic-bezier(0.0, 0.0, 0.58, 1.0)。<br/>"ease-in-out"：动画播放速度先加速后减速，cubic-bezier(0.42, 0.0, 0.58, 1.0)。<br/>"fast-out-slow-in"：标准曲线，cubic-bezier(0.4，0.0，0.2，1.0)。<br/>"linear-out-slow-in"：减速曲线，cubic-bezier(0.0，0.0，0.2，1.0)。<br/>"friction"：阻尼曲线，cubic-bezier(0.2, 0.0, 0.2, 1.0)。<br/>"extreme-deceleration"：急缓曲线，cubic-bezier(0.0, 0.0, 0.0, 1.0)。<br/>"rhythm"：节奏曲线，cubic-bezier(0.7, 0.0, 0.2, 1.0)。<br/>"sharp"：锐利曲线，cubic-bezier(0.33, 0.0, 0.67, 1.0)。<br/>"smooth"：平滑曲线，cubic-bezier(0.4, 0.0, 0.4, 1.0)。<br/>"cubic-bezier(x1,y1,x2,y2)"：三次贝塞尔曲线，x1、x2的值必须处于0-1之间。例如"cubic-bezier(0.42,0.0,0.58,1.0)"。<br/>"steps(number,step-position)"：阶梯曲线，number必须设置，为正整数，step-position参数可选，支持设置start或end，默认值为end。例如"steps(3,start)"。<br/>"interpolating-spring(velocity,mass,stiffness,damping)"：插值弹簧曲线，从API version 11开始支持且仅在ArkTS中支持使用。velocity、mass、stiffness、damping都是数值类型，且mass、stiffness、damping参数均应该大于0，具体参数含义参考[插值弹簧曲线](./js-apis-curve.md#curvesinterpolatingspring10)。使用interpolating-spring时，duration不生效，由弹簧参数决定；fill、direction、iterations设置无效，fill固定设置为"forwards"，direction固定设置为"normal"，iterations固定设置为1，且对animator的[reverse](#reverse)函数调用无效。即animator使用interpolating-spring时只能正向播放1次。 |
| delay      | number                                                      | 是   | 动画延时播放时长，单位毫秒，设置为0时，表示不延时。          |
| fill       | "none" \| "forwards" \| "backwards" \| "both"               | 是   | 动画执行后是否恢复到初始状态，动画执行后，动画结束时的状态（在最后一个关键帧中定义）将保留。<br/>"none"：在动画执行之前和之后都不会应用任何样式到目标上。<br/>"forwards"：在动画结束后，目标将保留动画结束时的状态（在最后一个关键帧中定义）。<br/>"backwards"：动画将在animation-delay期间应用第一个关键帧中定义的值。当animation-direction为"normal"或"alternate"时应用from关键帧中的值，当animation-direction为"reverse"或"alternate-reverse"时应用to关键帧中的值。<br/>"both"：动画将遵循forwards和backwards的规则，从而在两个方向上扩展动画属性。 |
| direction  | "normal" \| "reverse" \| "alternate" \| "alternate-reverse" | 是   | 动画播放模式。<br/>"normal"： 动画正向循环播放。<br/>"reverse"： 动画反向循环播放。<br/>"alternate"：动画交替循环播放，奇数次正向播放，偶数次反向播放。<br/>"alternate-reverse"：动画反向交替循环播放，奇数次反向播放，偶数次正向播放。 |
| iterations | number                                                      | 是   | 动画播放次数。设置为0时不播放，设置为-1时无限次播放。<br/>**说明:** 设置为除-1外其他负数视为无效取值，无效取值动画默认播放1次。 |
| begin      | number                                                      | 是   | 动画插值起点。                                               |
| end        | number                                                      | 是   | 动画插值终点。                                               |


## 完整示例
### 基于JS扩展的类Web开发范式

```html
<!-- hml -->
<div class="container">
  <div class="Animation" style="height: {{divHeight}}px; width: {{divWidth}}px; background-color: red;" onclick="Show">
  </div>
</div>
```

```ts
import animator, { AnimatorOptions,AnimatorResult } from '@ohos.animator';
import { BusinessError } from '@ohos.base';
let DataTmp:Record<string,animator> = {
  'divWidth': 200,
  'divHeight': 200,
  'animator': animator
}
class Tmp{
  data:animator = DataTmp
  onInit:Function = ()=>{}
  Show:Function = ()=>{}
}
class DateT{
  divWidth:number = 0
  divHeight:number = 0
  animator:AnimatorResult | null = null
}
(Fn:(v:Tmp) => void) => {Fn({
  data: DataTmp,
  onInit() {
    let options:AnimatorOptions = {
      duration: 1500,
      easing: "friction",
      delay: 0,
      fill: "forwards",
      direction: "normal",
      iterations: 2,
      begin: 200.0,
      end: 400.0
    };
    let DataTmp:DateT = {
      divWidth: 200,
      divHeight: 200,
      animator: null
    }
    DataTmp.animator = animator.create(options);
  },
  Show() {
    let options1:AnimatorOptions = {
      duration: 1500,
      easing: "friction",
      delay: 0,
      fill: "forwards",
      direction: "normal",
      iterations: 2,
      begin: 0,
      end: 400.0,
    };
    let DataTmp:DateT = {
      divWidth: 200,
      divHeight: 200,
      animator: null
    }
    try {
      DataTmp.animator = animator.create(options1);
      DataTmp.animator.reset(options1);
    } catch(error) {
      let message = (error as BusinessError).message
      let code = (error as BusinessError).code
      console.error(`Animator reset failed, error code: ${code}, message: ${message}.`);
    }
    let _this = DataTmp;
    if(DataTmp.animator){
      DataTmp.animator.onframe = (value:number)=> {
        _this.divWidth = value;
        _this.divHeight = value;
      };
      DataTmp.animator.play();
    }
  }
})}
```

  ![zh-cn_image_00007](figures/zh-cn_image_00007.gif)

### 基于ArkTS扩展的声明式开发范式

```ts
import animator, { AnimatorResult } from '@ohos.animator';

@Entry
@Component
struct AnimatorTest {
  private TAG: string = '[AnimatorTest]'
  private backAnimator: AnimatorResult | undefined = undefined
  private flag: boolean = false
  @State wid: number = 100
  @State hei: number = 100

  create() {
    let _this = this
    this.backAnimator = animator.create({
      duration: 2000,
      easing: "ease",
      delay: 0,
      fill: "forwards",
      direction: "normal",
      iterations: 1,
      begin: 100,
      end: 200
    })
    this.backAnimator.onfinish = ()=> {
      _this.flag = true
      console.info(_this.TAG, 'backAnimator onfinish')
    }
    this.backAnimator.onrepeat = ()=> {
      console.info(_this.TAG, 'backAnimator repeat')
    }
    this.backAnimator.oncancel = ()=> {
      console.info(_this.TAG, 'backAnimator cancel')
    }
    this.backAnimator.onframe = (value:number)=> {
      _this.wid = value
      _this.hei = value
    }
  }

  aboutToDisappear() {
    // 由于backAnimator在onframe中引用了this, this中保存了backAnimator，
    // 在自定义组件消失时应该将保存在组件中的backAnimator置空，避免内存泄漏
    this.backAnimator = undefined;
  }

  build() {
    Column() {
      Column() {
        Column()
          .width(this.wid)
          .height(this.hei)
          .backgroundColor(Color.Red)
      }
      .width('100%')
      .height(300)

      Column() {
        Row() {
          Button('create')
            .fontSize(30)
            .fontColor(Color.Black)
            .onClick(() => {
              this.create()
            })
        }
        .padding(10)

        Row() {
          Button('play')
            .fontSize(30)
            .fontColor(Color.Black)
            .onClick(() => {
              this.flag = false
              if(this.backAnimator){
                this.backAnimator.play()
              }
            })
        }
        .padding(10)

        Row() {
          Button('pause')
            .fontSize(30)
            .fontColor(Color.Black)
            .onClick(() => {
              if(this.backAnimator){
                this.backAnimator.pause()
              }
            })
        }
        .padding(10)

        Row() {
          Button('finish')
            .fontSize(30)
            .fontColor(Color.Black)
            .onClick(() => {
              this.flag = true
              if(this.backAnimator){
                this.backAnimator.finish()
              }
            })
        }
        .padding(10)

        Row() {
          Button('reverse')
            .fontSize(30)
            .fontColor(Color.Black)
            .onClick(() => {
              this.flag = false
              if(this.backAnimator){
                this.backAnimator.reverse()
              }
            })
        }
        .padding(10)

        Row() {
          Button('cancel')
            .fontSize(30)
            .fontColor(Color.Black)
            .onClick(() => {
              if(this.backAnimator){
                this.backAnimator.cancel()
              }
            })
        }
        .padding(10)

        Row() {
          Button('reset')
            .fontSize(30)
            .fontColor(Color.Black)
            .onClick(() => {
              if (this.flag) {
                this.flag = false
                if(this.backAnimator){
                  this.backAnimator.reset({
                    duration: 3000,
                    easing: "ease-in",
                    delay: 0,
                    fill: "forwards",
                    direction: "alternate",
                    iterations: 3,
                    begin: 100,
                    end: 300
                  })
                }
              } else {
                console.info(this.TAG, 'Animation not ended')
              }
            })
        }
        .padding(10)
      }
    }
  }
}
```

## update<sup>(deprecated)</sup>

update(options: AnimatorOptions): void

更新当前动画器。

从API version9开始不再维护，建议使用[reset<sup>9+</sup>](#reset9)

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名     | 类型                                  | 必填   | 说明      |
| ------- | ----------------------------------- | ---- | ------- |
| options | [AnimatorOptions](#animatoroptions) | 是    | 定义动画选项。 |

**示例：**

```ts
animator.update(options);
```

## createAnimator<sup>(deprecated)</sup>

createAnimator(options: AnimatorOptions): AnimatorResult

定义Animator类。

从API version9开始不再维护，建议使用[create<sup>9+</sup>](#create9)

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名     | 类型                                  | 必填   | 说明      |
| ------- | ----------------------------------- | ---- | ------- |
| options | [AnimatorOptions](#animatoroptions) | 是    | 定义动画选项。 |

**返回值：** 

| 类型                                | 说明            |
| --------------------------------- | ------------- |
| [AnimatorResult](#animatorresult) | Animator结果接口。 |

**示例：** 

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