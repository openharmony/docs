# 页面间转场<a name="ZH-CN_TOPIC_0000001237715079"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

页面转场通过在全局pageTransition方法内配置页面入场组件和页面退场组件来自定义页面转场动效。

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="22.12%" id="mcps1.1.4.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="17.31%" id="mcps1.1.4.1.2"><p>参数</p>
</th>
<th class="cellrowborder" valign="top" width="60.57%" id="mcps1.1.4.1.3"><p>参数描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="22.12%" headers="mcps1.1.4.1.1 "><p>PageTransitionEnter</p>
</td>
<td class="cellrowborder" valign="top" width="17.31%" headers="mcps1.1.4.1.2 "><p>Object</p>
</td>
<td class="cellrowborder" valign="top" width="60.57%" headers="mcps1.1.4.1.3 "><p>页面入场组件，用于自定义当前页面的入场效果，详见<a href="#li1947672255711">动效参数说明</a>。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="22.12%" headers="mcps1.1.4.1.1 "><p>PageTransitionExit</p>
</td>
<td class="cellrowborder" valign="top" width="17.31%" headers="mcps1.1.4.1.2 "><p>Object</p>
</td>
<td class="cellrowborder" valign="top" width="60.57%" headers="mcps1.1.4.1.3 "><p>页面退场组件，用于自定义当前页面的退场效果，详见<a href="#li1947672255711">动效参数说明</a>。</p>
</td>
</tr>
</tbody>
</table>

-   <a name="li1947672255711"></a>动效参数说明

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="10.67961165048544%" id="mcps1.1.6.1.1"><p>参数名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="17.47572815533981%" id="mcps1.1.6.1.2"><p>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.92233009708738%" id="mcps1.1.6.1.3"><p>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.116504854368934%" id="mcps1.1.6.1.4"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="50.80582524271845%" id="mcps1.1.6.1.5"><p>参数描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="10.67961165048544%" headers="mcps1.1.6.1.1 "><p>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.47572815533981%" headers="mcps1.1.6.1.2 "><p><a href="#li1364031695819">RouteType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="10.92233009708738%" headers="mcps1.1.6.1.3 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.116504854368934%" headers="mcps1.1.6.1.4 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="50.80582524271845%" headers="mcps1.1.6.1.5 "><p>不配置时表明pop为push时效果的逆播。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="10.67961165048544%" headers="mcps1.1.6.1.1 "><p>duration</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.47572815533981%" headers="mcps1.1.6.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.92233009708738%" headers="mcps1.1.6.1.3 "><p>1000</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.116504854368934%" headers="mcps1.1.6.1.4 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="50.80582524271845%" headers="mcps1.1.6.1.5 "><p>动画时长，单位为毫秒。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="10.67961165048544%" headers="mcps1.1.6.1.1 "><p>curve</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.47572815533981%" headers="mcps1.1.6.1.2 "><p>Curve | Curves</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.92233009708738%" headers="mcps1.1.6.1.3 "><p>Linear</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.116504854368934%" headers="mcps1.1.6.1.4 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="50.80582524271845%" headers="mcps1.1.6.1.5 "><p>动画曲线，有效值参见<a href="ts-animatorproperty.md#li16621545614">Curve</a> 说明。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="10.67961165048544%" headers="mcps1.1.6.1.1 "><p>delay</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.47572815533981%" headers="mcps1.1.6.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.92233009708738%" headers="mcps1.1.6.1.3 "><p>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.116504854368934%" headers="mcps1.1.6.1.4 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="50.80582524271845%" headers="mcps1.1.6.1.5 "><p>动画延迟时长，单位为毫秒，默认不延时播放。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   <a name="li1364031695819"></a>RouteType枚举说明

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>Pop</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>PageA跳转到PageB时，PageA为Exit+Push，PageB为Enter+Push。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>Push</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>PageB返回至PageA时，PageA为Enter+Pop，PageB为Exit+Pop。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 属性<a name="section4182144743016"></a>

PageTransitionEnter和PageTransitionExit组件支持的属性：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="10.679611650485436%" id="mcps1.1.6.1.1"><p>参数名称</p>
</th>
<th class="cellrowborder" valign="top" width="19.28155339805825%" id="mcps1.1.6.1.2"><p>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="14.24271844660194%" id="mcps1.1.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="9.155339805825243%" id="mcps1.1.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="46.640776699029125%" id="mcps1.1.6.1.5"><p>参数描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="10.679611650485436%" headers="mcps1.1.6.1.1 "><p>slide</p>
</td>
<td class="cellrowborder" valign="top" width="19.28155339805825%" headers="mcps1.1.6.1.2 "><p>SlideEffect</p>
</td>
<td class="cellrowborder" valign="top" width="14.24271844660194%" headers="mcps1.1.6.1.3 "><p>Right</p>
</td>
<td class="cellrowborder" valign="top" width="9.155339805825243%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="46.640776699029125%" headers="mcps1.1.6.1.5 "><p>设置转场的滑入效果，有效值参见<a href="#li81331342185820">SlideEffect</a>说明。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="10.679611650485436%" headers="mcps1.1.6.1.1 "><p>translate</p>
</td>
<td class="cellrowborder" valign="top" width="19.28155339805825%" headers="mcps1.1.6.1.2 "><p>{</p>
<p>x? : number,</p>
<p>y? : number,</p>
<p>z? : number</p>
<p>}</p>
</td>
<td class="cellrowborder" valign="top" width="14.24271844660194%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="9.155339805825243%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="46.640776699029125%" headers="mcps1.1.6.1.5 "><p>设置页面转场时的平移效果，为入场时起点和退场时终点的值，和slide同时设置时默认生效slide。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="10.679611650485436%" headers="mcps1.1.6.1.1 "><p>scale</p>
</td>
<td class="cellrowborder" valign="top" width="19.28155339805825%" headers="mcps1.1.6.1.2 "><p>{</p>
<p>x? : number,</p>
<p>y? : number,</p>
<p>z? : number,</p>
<p>centerX? : number,</p>
<p>centerY? : number</p>
<p>}</p>
</td>
<td class="cellrowborder" valign="top" width="14.24271844660194%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="9.155339805825243%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="46.640776699029125%" headers="mcps1.1.6.1.5 "><p>设置页面转场时的缩放效果，为入场时起点和退场时终点的值。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="10.679611650485436%" headers="mcps1.1.6.1.1 "><p>opacity</p>
</td>
<td class="cellrowborder" valign="top" width="19.28155339805825%" headers="mcps1.1.6.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="14.24271844660194%" headers="mcps1.1.6.1.3 "><p>1</p>
</td>
<td class="cellrowborder" valign="top" width="9.155339805825243%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="46.640776699029125%" headers="mcps1.1.6.1.5 "><p>设置入场的起点透明度值或者退场的终点透明度值。</p>
</td>
</tr>
</tbody>
</table>

-   <a name="li81331342185820"></a>SlideEffect枚举说明

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>Left</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>设置到入场时表示从左边滑入，出场时表示滑出到左边。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>Right</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>设置到入场时表示从右边滑入，出场时表示滑出到右边。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>Top</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>设置到入场时表示从上边滑入，出场时表示滑出到上边。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>Bottom</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>设置到入场时表示从下边滑入，出场时表示滑出到下边。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 事件<a name="section141860153013"></a>

PageTransitionEnter和PageTransitionExit组件支持的事件：

<table><thead align="left"><tr><th class="cellrowborder" colspan="2" valign="top" id="mcps1.1.4.1.1"><p>事件</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.4.1.2"><p>功能描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p>onEnter(type: RouteType, progress: number) =&gt; void</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p>回调入参为当前入场动画的归一化进度[0 - 1]。</p>
</td>
</tr>
<tr><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p>onExit(type: RouteType, progress: number) =&gt; void</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p>回调入参为当前退场动画的归一化进度[0 - 1]。</p>
</td>
</tr>
</tbody>
</table>

## 示例<a name="section675104083920"></a>

自定义方式1：配置了当前页面的入场动画为淡入，退场动画为缩小。

```
// index.ets
@Entry
@Component
struct PageTransitionExample1 {
  @State scale: number = 1
  @State opacity: number = 1
  @State active: boolean = false
  build() {
  Column() {
      Navigator({ target: 'pages/page1', type: NavigationType.Push }) {
        Image($r('app.media.bg1')).width("100%").height("100%")
      }
      .onClick(() => {
        this.active = true
      })
    }.scale({ x: this.scale }).opacity(this.opacity)
  }
// 自定义方式1：完全自定义转场过程的效果
  pageTransition() {
    PageTransitionEnter({ duration: 1200, curve: Curve.Linear })
      .onEnter((type: RouteType, progress: number) => {
        this.scale = 1
        this.opacity = progress
      }) // 进场过程中会逐帧触发onEnter回调，入参为动效的归一化进度(0% -- 100%)
    PageTransitionExit({ duration: 1500, curve: Curve.Ease })
      .onExit((type: RouteType, progress: number) => {
        this.scale = 1 - progress
        this.opacity = 1
      }) // 退场过程中会逐帧触发onExit回调，入参为动效的归一化进度(0% -- 100%)
  }
}
```

```
// page1.ets
@Entry
@Component
struct AExample {
  @State scale: number = 1
  @State opacity: number = 1
  @State active: boolean = false
  build() {
    Column() {
      Navigator({ target: 'pages/index' ,type: NavigationType.Push}) {
        Image($r('app.media.bg2')).width("100%").height("100%")
      }
    }.height("100%").width("100%").scale({ x: this.scale }).opacity(this.opacity)
  }
// 自定义方式1：完全自定义转场过程的效果
  pageTransition() {
    PageTransitionEnter({ duration: 1200, curve: Curve.Linear })
      .onEnter((type: RouteType, progress: number) => {
        this.scale = 1
        this.opacity = progress
      }) // 进场过程中会逐帧触发onEnter回调，入参为动效的归一化进度(0% -- 100%)
    PageTransitionExit({ duration: 1500, curve: Curve.Ease })
      .onExit((type: RouteType, progress: number) => {
        this.scale = 1 - progress
        this.opacity = 1
      }) // 退场过程中会逐帧触发onExit回调，入参为动效的归一化进度(0% -- 100%)
  }
}
```

![](figures/PageTransition1.gif)

自定义方式2：配置了当前页面的入场动画为从左侧滑入，退场为缩小加透明度变化。

```
// index.ets 
@Entry
@Component
struct PageTransitionExample {
  @State scale: number = 1
  @State opacity: number = 1
  @State active: boolean = false

  build() {
    Column() {
      Navigator({ target: 'pages/page1', type: NavigationType.Push }) {
        Image($r('app.media.bg1')).width("100%").height("100%")
      }
      .onClick(() => {
        this.active = true
      })
    }.scale({ x: this.scale }).opacity(this.opacity)
  }

// 自定义方式2：使用系统提供的多种默认效果(平移、缩放、透明度等)
  pageTransition() {
    PageTransitionEnter({ duration: 1200 })
      .slide(SlideEffect.Left)
    PageTransitionExit({ delay: 100 })
      .translate({ x: 100.0, y: 100.0 })
      .opacity(0)
  }
}
```

```
// page1.ets
@Entry
@Component
struct PageTransitionExample1 {
  @State scale: number = 1
  @State opacity: number = 1
  @State active: boolean = false

  build() {
    Column() {
      Navigator({ target: 'pages/index', type: NavigationType.Push }) {
        Image($r('app.media.bg2')).width  ("100%").height("100%")
      }
      .onClick(() => {
        this.active = true
      })
    }.scale({ x: this.scale }).opacity(this.opacity)
  }

// 自定义方式2：使用系统提供的多种默认效果(平移、缩放、透明度等)
  pageTransition() {
    PageTransitionEnter({ duration: 1200 })
      .slide(SlideEffect.Left)
    PageTransitionExit({ delay: 100 })
      .translate({ x: 100.0, y: 100.0 })
      .opacity(0)
  }
}
```

![](figures/PageTransition2.gif)

