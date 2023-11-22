# page_transition    
当路由进行切换时，可以通过在pageTransition函数中自定义页面入场和页面退场的转场动效。详细指导请参考[页面转场动画](../../ui/arkts-page-transition-animation.md)。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## RouteType    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| None | 0 | 重定向指定页面。从PageB回退到之前的页面PageA。对于PageB，指定RouteType为None或者Pop的PageTransitionExit组件样式生效，对于PageA，指定RouteType为None或者Pop的PageTransitionEnter组件样式生效。 |  
| Push | 1 | 跳转到下一页面。PageA跳转到下一个新的界面PageB。对于PageA，指定RouteType为None或者Push的PageTransitionExit组件样式生效，对于PageB，指定RouteType为None或者Push的PageTransitionEnter组件样式生效。 |  
| Pop | 2 | 页面未重定向。如Push和Pop描述中RouteType为None的情形，即页面进场时PageTransitionEnter的转场效果生效；退场时PageTransitionExit的转场效果生效。 |  
    
## SlideEffect    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Left | 0 | 设置到入场时表示从左边滑入，出场时表示滑出到左边。 |  
| Right | 1 | 设置到入场时表示从右边滑入，出场时表示滑出到右边。 |  
| Top | 2 | 设置到入场时表示从上边滑入，出场时表示滑出到上边。 |  
| Bottom | 3 | 设置到入场时表示从下边滑入，出场时表示滑出到下边。 |  
    
## CommonTransition  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### slide    
设置页面转场时的滑入滑出效果。  
 **调用形式：**     
- slide(value: SlideEffect): T  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | SlideEffect | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| T |  |  
    
### translate    
设置页面转场时的平移效果，为入场时起点和退场时终点的值，和slide同时设置时默认生效slide。  
  
 **调用形式：**     
- translate(value: { x?: number | string; y?: number | string; z?: number | string }): T  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| x | number \| string | false | 横向的平移距离。<br/> |  
| y | number \| string | false | 纵向的平移距离。<br/> |  
| z | number \| string | false | 竖向的平移距离。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| T |  |  
    
### scale    
设置页面转场时的缩放效果，为入场时起点和退场时终点的值。  
  
 **调用形式：**     
- scale(value: { x?: number; y?: number; z?: number; centerX?: number | string; centerY?: number | string }): T  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| x | number | false | 横向放大倍数（或缩小比例）。<br/> |  
| y | number | false | 纵向放大倍数（或缩小比例）。<br/> |  
| z | number | false | 竖向放大倍数（或缩小比例）。<br/> |  
| centerX | number \| string | false | 缩放中心点<br/> |  
| centerY | number \| string | false | 缩放中心点<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| T |  |  
    
### opacity    
设置入场的起点透明度值或者退场的终点透明度值。  
 **调用形式：**     
- opacity(value: number): T  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | number | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| T |  |  
    
## PageTransitionOptions  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| type | RouteType | false | false |  |  
| duration | number | false | false |  |  
| curve | Curve \| string \| ICurve | false | false |  |  
| delay | number | false | false |  |  
    
## 接口  
  
  
<p>回调入参为当前入场动画的归一化进度[0&amp;nbsp;-&amp;nbsp;1]。&lt;br/&gt;-&amp;nbsp;type：跳转方法。&lt;br/&gt;-&amp;nbsp;progress：当前进度。&lt;br/&gt;触发该事件的条件：&lt;br/&gt;逐帧回调，直到入场动画结束，progress从0变化到1。&nbsp;</p>  
    
 **调用形式**     
    
- PageTransitionEnteronEnter(event: (type: RouteType, progress: number) => void): PageTransitionEnterInterface    
起始版本： 7    
    
- PageTransitionEnter(value: PageTransitionOptions): PageTransitionEnterInterface    
起始版本： 7    
## 接口  
  
  
<p>回调入参为当前退场动画的归一化进度[0&amp;nbsp;-&amp;nbsp;1]。&lt;br/&gt;-&amp;nbsp;type：跳转方法。&lt;br/&gt;-&amp;nbsp;progress：当前进度。&lt;br/&gt;触发该事件的条件：&lt;br/&gt;逐帧回调，直到退场动画结束，progress从0变化到1。</p>  
    
 **调用形式**     
    
- PageTransitionExit(value: PageTransitionOptions): PageTransitionExitInterface    
起始版本： 7    
    
- PageTransitionExitonExit(event: (type: RouteType, progress: number) => void): PageTransitionExitInterface    
起始版本： 7    
 **示例代码1：**   
自定义方式1：配置了当前页面的入场动画为淡入，退场动画为缩小。  
```ts    
// index.ets  
@Entry  
@Component  
struct PageTransitionExample1 {  
  @State scale1: number = 1  
  @State opacity1: number = 1  
  
  build() {  
    Column() {  
      Navigator({ target: 'pages/page1', type: NavigationType.Push }) {  
        Image($r('app.media.bg1')).width('100%').height('100%')    // 图片存放在media文件夹下  
      }  
    }.scale({ x: this.scale1 }).opacity(this.opacity1)  
  }  
  // 自定义方式1：完全自定义转场过程的效果  
  pageTransition() {  
    PageTransitionEnter({ duration: 1200, curve: Curve.Linear })  
      .onEnter((type?: RouteType, progress?: number) => {  
        this.scale1 = 1  
        this.opacity1 = progress as number  
      }) // 进场过程中会逐帧触发onEnter回调，入参为动效的归一化进度(0% -- 100%)  
    PageTransitionExit({ duration: 1200, curve: Curve.Ease })  
      .onExit((type?: RouteType, progress?: number) => {  
        this.scale1 = 1 - (progress as number)  
        this.opacity1 = 1  
      }) // 退场过程中会逐帧触发onExit回调，入参为动效的归一化进度(0% -- 100%)  
  }  
}  
```  
  
```ts  
// page1.ets  
@Entry  
@Component  
struct AExample {  
  @State scale2: number = 1  
  @State opacity2: number = 1  
  
  build() {  
    Column() {  
      Navigator({ target: 'pages/index', type: NavigationType.Push }) {  
        Image($r('app.media.bg2')).width('100%').height('100%')   // 图片存放在media文件夹下  
      }  
    }.width('100%').height('100%').scale({ x: this.scale2 }).opacity(this.opacity2)  
  }  
  // 自定义方式1：完全自定义转场过程的效果  
  pageTransition() {  
    PageTransitionEnter({ duration: 1200, curve: Curve.Linear })  
      .onEnter((type?: RouteType, progress?: number) => {  
        this.scale2 = 1  
        this.opacity2 = progress as number  
      }) // 进场过程中会逐帧触发onEnter回调，入参为动效的归一化进度(0% -- 100%)  
    PageTransitionExit({ duration: 1200, curve: Curve.Ease })  
      .onExit((type?: RouteType, progress?: number) => {  
        this.scale2 = 1 - (progress as number)  
        this.opacity2 = 1  
      }) // 退场过程中会逐帧触发onExit回调，入参为动效的归一化进度(0% -- 100%)  
  }  
}  
    
```    
  
![pageTransition1](figures/pageTransition1.gif)  
    
 **示例代码2：**   
自定义方式2：配置了当前页面的入场动画为从左侧滑入，退场为平移加透明度变化。  
```ts    
// index.ets   
@Entry  
@Component  
struct PageTransitionExample {  
  build() {  
    Column() {  
      Navigator({ target: 'pages/page1', type: NavigationType.Push }) {  
        Image($r('app.media.bg1')).width('100%').height('100%')   // 图片存放在media文件夹下  
      }  
    }  
  }  
  
  // 自定义方式2：使用系统提供的多种默认效果(平移、缩放、透明度等)  
  pageTransition() {  
    // 该页面进入动画时长为1200ms，尽量与另一页面的退出动画时长匹配  
    PageTransitionEnter({ duration: 1200 })  
      .slide(SlideEffect.Left)  
    // 该页面退出动画时长为1000ms，尽量与另一页面的进入动画时长匹配  
    PageTransitionExit({ duration: 1000 })  
      .translate({ x: 100.0, y: 100.0 })  
      .opacity(0)  
  }  
}  
    
```    
  
    
 **示例代码3：**   
```ts    
// page1.ets  
@Entry  
@Component  
struct PageTransitionExample1 {  
  build() {  
    Column() {  
      Navigator({ target: 'pages/index', type: NavigationType.Push }) {  
        Image($r('app.media.bg2')).width('100%').height('100%')    // 图片存放在media文件夹下  
      }  
    }  
  }  
  
  // 自定义方式2：使用系统提供的多种默认效果(平移、缩放、透明度等)  
  pageTransition() {  
    // 该页面进入动画时长为1000ms，尽量与另一页面的退出动画时长匹配  
    PageTransitionEnter({ duration: 1000 })  
      .slide(SlideEffect.Left)  
    // 该页面退出动画时长为1200ms，尽量与另一页面的进入动画时长匹配  
    PageTransitionExit({ duration: 1200 })  
      .translate({ x: 100.0, y: 100.0 })  
      .opacity(0)  
  }  
}  
    
```    
  
![pageTransition2](figures/pageTransition2.gif)  
