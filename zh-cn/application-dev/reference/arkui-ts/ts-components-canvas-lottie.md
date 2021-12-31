# Lottie<a name="ZH-CN_TOPIC_0000001193075114"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从 API Version 8 开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

Lottie为三方开源库，依赖Canvas与RenderingContext。

## 权限列表<a name="section53281531154915"></a>

无

## 导入模块<a name="section1368314480509"></a>

```
import lottie from 'lottie-web'
```

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>'lottie-web' 名字以实际生态发布后的命名为准。

## lottie.loadAnimation<a name="section11378112123018"></a>

loadAnimation\(

path: string, container: object, render: string, loop: boolean, autoplay: boolean, name: string \): AnimationItem

加载动画，须提前声明Animator\('\_\_lottie\_ets'\)对象，并在Canvas完成布局后调用。可配合Canvas组件生命周期接口使用，比如onAppear\(\)与onPageShow\(\)。

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="14.399999999999999%" id="mcps1.1.5.1.1"><p>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.32%" id="mcps1.1.5.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.059999999999999%" id="mcps1.1.5.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.22%" id="mcps1.1.5.1.4"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="14.399999999999999%" headers="mcps1.1.5.1.1 "><p>path</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.32%" headers="mcps1.1.5.1.2 "><p>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.059999999999999%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.22%" headers="mcps1.1.5.1.4 "><p>hap包内动画资源文件路径，仅支持json格式。示例：path: "common/lottie/data.json"</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="14.399999999999999%" headers="mcps1.1.5.1.1 "><p>container</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.32%" headers="mcps1.1.5.1.2 "><p>object</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.059999999999999%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.22%" headers="mcps1.1.5.1.4 "><p>canvas绘图上下文，声明范式需提前声明CanvasRenderingContext2D。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="14.399999999999999%" headers="mcps1.1.5.1.1 "><p>render</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.32%" headers="mcps1.1.5.1.2 "><p>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.059999999999999%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.22%" headers="mcps1.1.5.1.4 "><p>渲染类型，仅支持“canvas”。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="14.399999999999999%" headers="mcps1.1.5.1.1 "><p>loop</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.32%" headers="mcps1.1.5.1.2 "><p>boolean | number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.059999999999999%" headers="mcps1.1.5.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.22%" headers="mcps1.1.5.1.4 "><p>动画播放结束后，是否循环播放，默认值true。值类型为number，且大于等于1时为设置的重复播放的次数。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="14.399999999999999%" headers="mcps1.1.5.1.1 "><p>autoplay</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.32%" headers="mcps1.1.5.1.2 "><p>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.059999999999999%" headers="mcps1.1.5.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.22%" headers="mcps1.1.5.1.4 "><p>是否自动播放动画，默认值true。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="14.399999999999999%" headers="mcps1.1.5.1.1 "><p>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.32%" headers="mcps1.1.5.1.2 "><p>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.059999999999999%" headers="mcps1.1.5.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.22%" headers="mcps1.1.5.1.4 "><p>开发者自定义的动画名称，后续支持通过该名称引用控制动画，默认为空。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="14.399999999999999%" headers="mcps1.1.5.1.1 "><p>initialSegment</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.32%" headers="mcps1.1.5.1.2 "><p>[number, number]</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.059999999999999%" headers="mcps1.1.5.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.22%" headers="mcps1.1.5.1.4 "><p>指定动画播放的起始帧号，指定动画播放的结束帧号。</p>
    </td>
    </tr>
    </tbody>
    </table>


## lottie.destroy<a name="section0927174125215"></a>

destroy\(name: string\): void

销毁动画，页面退出时，必须调用。可配合Canvas组件生命周期接口使用，比如onDisappear\(\)与onPageHide\(\)。

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="14.38%" id="mcps1.1.5.1.1"><p>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.35%" id="mcps1.1.5.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.059999999999999%" id="mcps1.1.5.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.21%" id="mcps1.1.5.1.4"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="14.38%" headers="mcps1.1.5.1.1 "><p>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.35%" headers="mcps1.1.5.1.2 "><p>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.059999999999999%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.21%" headers="mcps1.1.5.1.4 "><p>被指定的动画名，同loadAnimation接口参数name, 缺省时销毁所有动画。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    import lottie from 'lottie-web'
    
    @Entry
    @Component
    struct Index {
      private controller: CanvasRenderingContext2D = new CanvasRenderingContext2D()
      private animateName: string = "animate"
      private animatePath: string = "common/lottie/data.json"
      private animateItem: any = null
    
      private onPageHide(): void {
        console.log('onPageHide')
        lottie.destroy()
      }
    
      build() {
        Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
          Canvas(this.controller)
          .width('30%')
          .height('20%')
          .backgroundColor('#0D9FFB')
          .onAppear(() => {
            console.log('canvas onAppear');
            this.animateItem = lottie.loadAnimation({
              container: this.controller,
              renderer: 'canvas',
              loop: true,
              autoplay: true,
              name: this.animateName,
              path: this.animatePath,
            })
          })
    
          Animator('__lottie_ets') // declare Animator('__lottie_ets') when use lottie
          Button('load animation')
            .onClick(() => {
            if (this.animateItem != null) {
              this.animateItem.destroy()
              this.animateItem = null
            }
            this.animateItem = lottie.loadAnimation({
              container: this.controller,
              renderer: 'canvas',
              loop: true,
              autoplay: true,
              name: this.animateName,
              path: this.animatePath,
              initialSegment: [10, 50],
            })
          })
    
          Button('destroy animation')
            .onClick(() => {
              lottie.destroy(this.animateName)
              this.animateItem = null
            })
        }
        .width('100%')
        .height('100%')
      }
    }
    ```

    ![](figures/lottie-ark-2-0-canvas-ui-animate.gif)


## lottie.play<a name="section175031744244"></a>

play\(name: string\): void

播放指定动画。

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="15.6%" id="mcps1.1.5.1.1"><p>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.13%" id="mcps1.1.5.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.059999999999999%" id="mcps1.1.5.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.21%" id="mcps1.1.5.1.4"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="15.6%" headers="mcps1.1.5.1.1 "><p>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.13%" headers="mcps1.1.5.1.2 "><p>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.059999999999999%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.21%" headers="mcps1.1.5.1.4 "><p>被指定的动画名, 同loadAnimation接口参数name，缺省时播放所有动画。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    lottie.play(this.animateName)
    ```


## lottie.pause<a name="section13965204292811"></a>

pause\(name: string\): void

暂停指定动画，下次调用lottie.play\(\)从当前帧开始。

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="15.6%" id="mcps1.1.5.1.1"><p>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.13%" id="mcps1.1.5.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.059999999999999%" id="mcps1.1.5.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.21%" id="mcps1.1.5.1.4"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="15.6%" headers="mcps1.1.5.1.1 "><p>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.13%" headers="mcps1.1.5.1.2 "><p>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.059999999999999%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.21%" headers="mcps1.1.5.1.4 "><p>被指定的动画名，同loadAnimation接口入参name，缺省时暂停所有动画。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    lottie.pause(this.animateName)
    ```


## lottie.togglePause<a name="section1633164714304"></a>

togglePause\(name: string\): void

暂停或播放指定动画，等效于lottie.play\(\)与lottie.pause\(\)切换调用。

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="15.740000000000002%" id="mcps1.1.5.1.1"><p>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.989999999999998%" id="mcps1.1.5.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.059999999999999%" id="mcps1.1.5.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.21%" id="mcps1.1.5.1.4"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="15.740000000000002%" headers="mcps1.1.5.1.1 "><p>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.989999999999998%" headers="mcps1.1.5.1.2 "><p>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.059999999999999%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.21%" headers="mcps1.1.5.1.4 "><p>被指定的动画名，同loadAnimation接口参数name，缺省时停止所有动画。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    lottie.togglePause(this.animateName)
    ```


## lottie.stop<a name="section57246132289"></a>

stop\(name: string\): void

停止指定动画，下次调用lottie.play\(\)从第一帧开始。

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="15.72%" id="mcps1.1.5.1.1"><p>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.01%" id="mcps1.1.5.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.059999999999999%" id="mcps1.1.5.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.21%" id="mcps1.1.5.1.4"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="15.72%" headers="mcps1.1.5.1.1 "><p>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.01%" headers="mcps1.1.5.1.2 "><p>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.059999999999999%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.21%" headers="mcps1.1.5.1.4 "><p>被指定的动画名，同loadAnimation接口参数name，缺省时停止所有动画。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    lottie.stop(this.animateName)
    ```


## lottie.setSpeed<a name="section755319433508"></a>

setSpeed\(speed: number, name: string\): void

设置指定动画播放速度。

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="15.72%" id="mcps1.1.5.1.1"><p>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.01%" id="mcps1.1.5.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.059999999999999%" id="mcps1.1.5.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.21%" id="mcps1.1.5.1.4"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="15.72%" headers="mcps1.1.5.1.1 "><p>speed</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.01%" headers="mcps1.1.5.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.059999999999999%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.21%" headers="mcps1.1.5.1.4 "><p>值为浮点类型, speed&gt;0正向播放, speed&lt;0反向播放, speed=0暂停播放, speed=1.0/-1.0正常速度播放。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="15.72%" headers="mcps1.1.5.1.1 "><p>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.01%" headers="mcps1.1.5.1.2 "><p>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.059999999999999%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.21%" headers="mcps1.1.5.1.4 "><p>被指定的动画，同loadAnimation接口参数name，缺省时停止所有动画。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    lottie.setSpeed(5, this.animateName)
    ```


## lottie.setDirection<a name="section2055464318504"></a>

setDirection\(direction: AnimationDirection, name: string\): void

设置指定动画播放顺序。

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="15.939999999999998%" id="mcps1.1.5.1.1"><p>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.790000000000001%" id="mcps1.1.5.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.059999999999999%" id="mcps1.1.5.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.21%" id="mcps1.1.5.1.4"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="15.939999999999998%" headers="mcps1.1.5.1.1 "><p>direction</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.790000000000001%" headers="mcps1.1.5.1.2 "><p>AnimationDirection</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.059999999999999%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.21%" headers="mcps1.1.5.1.4 "><p>1为正向，-1为反向; 当设置为反向时，从当前播放进度开始回播直到首帧，loop值为true时可无限倒放；speed&lt;0叠加时也是倒放。</p>
    <p>AnimationDirection：1 | -1</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="15.939999999999998%" headers="mcps1.1.5.1.1 "><p>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.790000000000001%" headers="mcps1.1.5.1.2 "><p>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.059999999999999%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.21%" headers="mcps1.1.5.1.4 "><p>被指定的动画名，同loadAnimation接口参数name，缺省时设置所有动画方向。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例

    ```
    lottie.setDirection(-1, this.controlName)
    ```


## AnimationItem<a name="section038875381812"></a>

loadAnimation接口的返回对象，具有属性与接口。属性描述如下：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="33.300000000000004%" id="mcps1.1.4.1.1"><p>参数名称</p>
</th>
<th class="cellrowborder" valign="top" width="33.36%" id="mcps1.1.4.1.2"><p>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="33.339999999999996%" id="mcps1.1.4.1.3"><p>参数描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="33.300000000000004%" headers="mcps1.1.4.1.1 "><p>name</p>
</td>
<td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="33.339999999999996%" headers="mcps1.1.4.1.3 "><p>动画名称。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="33.300000000000004%" headers="mcps1.1.4.1.1 "><p>isLoaded</p>
</td>
<td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="33.339999999999996%" headers="mcps1.1.4.1.3 "><p>动画是否已加载。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="33.300000000000004%" headers="mcps1.1.4.1.1 "><p>currentFrame</p>
</td>
<td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="33.339999999999996%" headers="mcps1.1.4.1.3 "><p>当前播放的帧号, 默认精度为&gt;=0.0的浮点数, 调用setSubframe(false)后精度为去小数点后的正整数。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="33.300000000000004%" headers="mcps1.1.4.1.1 "><p>currentRawFrame</p>
</td>
<td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="33.339999999999996%" headers="mcps1.1.4.1.3 "><p>当前播放帧数, 精度为&gt;=0.0的浮点数。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="33.300000000000004%" headers="mcps1.1.4.1.1 "><p>firstFrame</p>
</td>
<td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="33.339999999999996%" headers="mcps1.1.4.1.3 "><p>当前播放片段的第一帧帧号。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="33.300000000000004%" headers="mcps1.1.4.1.1 "><p>totalFrames</p>
</td>
<td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="33.339999999999996%" headers="mcps1.1.4.1.3 "><p>当前播放片段的总帧数。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="33.300000000000004%" headers="mcps1.1.4.1.1 "><p>frameRate</p>
</td>
<td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="33.339999999999996%" headers="mcps1.1.4.1.3 "><p>帧率 (frame/s)。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="33.300000000000004%" headers="mcps1.1.4.1.1 "><p>frameMult</p>
</td>
<td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="33.339999999999996%" headers="mcps1.1.4.1.3 "><p>帧率 (frame/ms)。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="33.300000000000004%" headers="mcps1.1.4.1.1 "><p>playSpeed</p>
</td>
<td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="33.339999999999996%" headers="mcps1.1.4.1.3 "><p>值为浮点类型, speed&gt;0正向播放, speed&lt;0反向播放, speed=0暂停播放, speed=1.0 | -1.0正常速度播放。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="33.300000000000004%" headers="mcps1.1.4.1.1 "><p>playDirection</p>
</td>
<td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="33.339999999999996%" headers="mcps1.1.4.1.3 "><p>播放方向, 1为正放, -1为倒放。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="33.300000000000004%" headers="mcps1.1.4.1.1 "><p>playCount</p>
</td>
<td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="33.339999999999996%" headers="mcps1.1.4.1.3 "><p>动画完成播放的次数。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="33.300000000000004%" headers="mcps1.1.4.1.1 "><p>isPaused</p>
</td>
<td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="33.339999999999996%" headers="mcps1.1.4.1.3 "><p>当前动画是否已暂停, 值为true动画已暂停。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="33.300000000000004%" headers="mcps1.1.4.1.1 "><p>autoplay</p>
</td>
<td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="33.339999999999996%" headers="mcps1.1.4.1.3 "><p>加载动画后是否自动播放, 若值为false需要再调用play()接口开始播放。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="33.300000000000004%" headers="mcps1.1.4.1.1 "><p>loop</p>
</td>
<td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.2 "><p>boolean | number</p>
</td>
<td class="cellrowborder" valign="top" width="33.339999999999996%" headers="mcps1.1.4.1.3 "><p>类型为boolean时是否循环播放, 类型为number时播放次数。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="33.300000000000004%" headers="mcps1.1.4.1.1 "><p>renderer</p>
</td>
<td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.2 "><p>any</p>
</td>
<td class="cellrowborder" valign="top" width="33.339999999999996%" headers="mcps1.1.4.1.3 "><p>动画渲染对象, 根据渲染类型而定。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="33.300000000000004%" headers="mcps1.1.4.1.1 "><p>animationID</p>
</td>
<td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="33.339999999999996%" headers="mcps1.1.4.1.3 "><p>动画ID。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="33.300000000000004%" headers="mcps1.1.4.1.1 "><p>timeCompleted</p>
</td>
<td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="33.339999999999996%" headers="mcps1.1.4.1.3 "><p>当前动画片段完成单次播放的帧数, 受AnimationSegment设置影响, 与totalFrames属性值相同。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="33.300000000000004%" headers="mcps1.1.4.1.1 "><p>segmentPos</p>
</td>
<td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="33.339999999999996%" headers="mcps1.1.4.1.3 "><p>当前动画片段序号, 值为&gt;=0的正整数。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="33.300000000000004%" headers="mcps1.1.4.1.1 "><p>isSubframeEnabled</p>
</td>
<td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="33.339999999999996%" headers="mcps1.1.4.1.3 "><p>关联了currentFrame的精度是否为浮点数。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="33.300000000000004%" headers="mcps1.1.4.1.1 "><p>segments</p>
</td>
<td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.2 "><p>AnimationSegment | AnimationSegment[]</p>
</td>
<td class="cellrowborder" valign="top" width="33.339999999999996%" headers="mcps1.1.4.1.3 "><p>当前动画的播放片段。</p>
</td>
</tr>
</tbody>
</table>

## AnimationItem.play<a name="section035751020599"></a>

play\(name?: string\): void

播放动画。

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="15.740000000000002%" id="mcps1.1.5.1.1"><p>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.989999999999998%" id="mcps1.1.5.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.059999999999999%" id="mcps1.1.5.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.21%" id="mcps1.1.5.1.4"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="15.740000000000002%" headers="mcps1.1.5.1.1 "><p>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.989999999999998%" headers="mcps1.1.5.1.2 "><p>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.059999999999999%" headers="mcps1.1.5.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.21%" headers="mcps1.1.5.1.4 "><p>被指定的动画名，缺省默认为空。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    this.anim.play()
    ```


## AnimationItem.destroy<a name="section1335522233318"></a>

destroy\(name?: string\): void

销毁动画。

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="15.740000000000002%" id="mcps1.1.5.1.1"><p>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.989999999999998%" id="mcps1.1.5.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.059999999999999%" id="mcps1.1.5.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.21%" id="mcps1.1.5.1.4"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="15.740000000000002%" headers="mcps1.1.5.1.1 "><p>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.989999999999998%" headers="mcps1.1.5.1.2 "><p>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.059999999999999%" headers="mcps1.1.5.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.21%" headers="mcps1.1.5.1.4 "><p>被指定的动画名，缺省默认为空。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    this.anim.destroy()
    ```


## AnimationItem.pause<a name="section1535821016594"></a>

pause\(name?: string\): void

暂停动画，下次调用play接口从当前帧开始播放。

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="15.740000000000002%" id="mcps1.1.5.1.1"><p>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.97%" id="mcps1.1.5.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.07%" id="mcps1.1.5.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.22%" id="mcps1.1.5.1.4"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="15.740000000000002%" headers="mcps1.1.5.1.1 "><p>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.97%" headers="mcps1.1.5.1.2 "><p>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.07%" headers="mcps1.1.5.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.22%" headers="mcps1.1.5.1.4 "><p>被指定的动画名，缺省默认为空。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    this.anim.pause()
    ```


## AnimationItem.togglePause<a name="section16359210115914"></a>

togglePause\(name?: string\): void

暂停或播放动画，等效于play接口与pause接口之间轮换调用。

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="15.740000000000002%" id="mcps1.1.5.1.1"><p>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.97%" id="mcps1.1.5.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.07%" id="mcps1.1.5.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.22%" id="mcps1.1.5.1.4"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="15.740000000000002%" headers="mcps1.1.5.1.1 "><p>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.97%" headers="mcps1.1.5.1.2 "><p>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.07%" headers="mcps1.1.5.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.22%" headers="mcps1.1.5.1.4 "><p>被指定的动画名，缺省默认为空。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    this.anim.togglePause()
    ```


## AnimationItem.stop<a name="section163601107598"></a>

stop\(name?: string\): void

停止动画，下次调用play接口从第一帧开始播放。

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="15.740000000000002%" id="mcps1.1.5.1.1"><p>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.97%" id="mcps1.1.5.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.07%" id="mcps1.1.5.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.22%" id="mcps1.1.5.1.4"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="15.740000000000002%" headers="mcps1.1.5.1.1 "><p>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.97%" headers="mcps1.1.5.1.2 "><p>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.07%" headers="mcps1.1.5.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.22%" headers="mcps1.1.5.1.4 "><p>被指定的动画名，缺省默认为空。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    this.anim.stop()
    ```


## AnimationItem.setSpeed<a name="section3824104013716"></a>

setSpeed\(speed: number\): void

设置动画播放速度。

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="15.740000000000002%" id="mcps1.1.5.1.1"><p>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.989999999999998%" id="mcps1.1.5.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.059999999999999%" id="mcps1.1.5.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.21%" id="mcps1.1.5.1.4"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="15.740000000000002%" headers="mcps1.1.5.1.1 "><p>speed</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.989999999999998%" headers="mcps1.1.5.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.059999999999999%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.21%" headers="mcps1.1.5.1.4 "><p>值为浮点类型, speed&gt;0正向播放, speed&lt;0反向播放, speed=0暂停播放, speed=1.0 | -1.0正常速度播放。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    this.anim.setSpeed(5);
    ```


## AnimationItem.setDirection<a name="section1782514083712"></a>

setDirection\(direction: AnimationDirection\): void

设置动画播放顺序。

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="15.939999999999998%" id="mcps1.1.5.1.1"><p>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.790000000000001%" id="mcps1.1.5.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.059999999999999%" id="mcps1.1.5.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.21%" id="mcps1.1.5.1.4"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="15.939999999999998%" headers="mcps1.1.5.1.1 "><p>direction</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.790000000000001%" headers="mcps1.1.5.1.2 "><p>AnimationDirection</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.059999999999999%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.21%" headers="mcps1.1.5.1.4 "><p>1为正向，-1为反向; 当设置为反向时，从当前播放进度开始回播直到首帧，loop值为true时可无限倒放；speed&lt;0叠加时也是倒放。</p>
    <p>AnimationDirection：1 | -1。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例

    ```
    this.anim.setDirection(-1)
    ```


## AnimationItem.goToAndStop<a name="section45151420204219"></a>

goToAndStop\(value: number, isFrame: boolean\): void

设置动画停止在指定帧或时间进度。

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="15.540000000000001%" id="mcps1.1.5.1.1"><p>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.170000000000002%" id="mcps1.1.5.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.08%" id="mcps1.1.5.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.21%" id="mcps1.1.5.1.4"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="15.540000000000001%" headers="mcps1.1.5.1.1 "><p>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.170000000000002%" headers="mcps1.1.5.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.08%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.21%" headers="mcps1.1.5.1.4 "><p>帧号(值大于等于0)或时间进度(ms)。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="15.540000000000001%" headers="mcps1.1.5.1.1 "><p>isFrame</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.170000000000002%" headers="mcps1.1.5.1.2 "><p>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.08%" headers="mcps1.1.5.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.21%" headers="mcps1.1.5.1.4 "><p>true: 按指定帧控制，false:按指定时间控制，缺省默认false。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="15.540000000000001%" headers="mcps1.1.5.1.1 "><p>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.170000000000002%" headers="mcps1.1.5.1.2 "><p>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.08%" headers="mcps1.1.5.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.21%" headers="mcps1.1.5.1.4 "><p>被指定的动画名，缺省默认为空。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例

    ```
    // 按帧号控制
    this.anim.goToAndStop(25, true)
    // 按时间进度控制
    this.anim.goToAndStop(300, false, this.animateName)
    ```


## AnimationItem.goToAndPlay<a name="section2998182654614"></a>

goToAndPlay\(value: number, isFrame: boolean\): void

设置动画从指定帧或时间进度开始播放。

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="15.540000000000001%" id="mcps1.1.5.1.1"><p>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.19%" id="mcps1.1.5.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.059999999999999%" id="mcps1.1.5.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.21%" id="mcps1.1.5.1.4"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="15.540000000000001%" headers="mcps1.1.5.1.1 "><p>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.19%" headers="mcps1.1.5.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.059999999999999%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.21%" headers="mcps1.1.5.1.4 "><p>帧号(值大于等于0)或时间进度(ms)</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="15.540000000000001%" headers="mcps1.1.5.1.1 "><p>isFrame</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.19%" headers="mcps1.1.5.1.2 "><p>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.059999999999999%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.21%" headers="mcps1.1.5.1.4 "><p>true：按指定帧控制， false：按指定时间控制，缺省默认false。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="15.540000000000001%" headers="mcps1.1.5.1.1 "><p>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.19%" headers="mcps1.1.5.1.2 "><p>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.059999999999999%" headers="mcps1.1.5.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.21%" headers="mcps1.1.5.1.4 "><p>被指定的动画名，缺省默认为空。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例

    ```
    // 按帧号控制
    this.anim.goToAndPlay(25, true)
    // 按时间进度控制
    this.anim.goToAndPlay(300, false, this.animateName)
    ```


## AnimationItem.playSegments<a name="section935124765113"></a>

playSegments\(segments: AnimationSegment | AnimationSegment\[\], forceFlag: boolean\): void

设置动画仅播放指定片段。

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="10.6%" id="mcps1.1.5.1.1"><p>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="18.12%" id="mcps1.1.5.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.05%" id="mcps1.1.5.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.23%" id="mcps1.1.5.1.4"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="10.6%" headers="mcps1.1.5.1.1 "><p>segments</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.12%" headers="mcps1.1.5.1.2 "><p>AnimationSegment = [number, number] | AnimationSegment[]</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.05%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.23%" headers="mcps1.1.5.1.4 "><p>片段或片段列表；</p>
    <p>如果片段列表全部播放完毕后，下轮循环播放仅播放最后一个片段</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="10.6%" headers="mcps1.1.5.1.1 "><p>forceFlag</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.12%" headers="mcps1.1.5.1.2 "><p>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.05%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.23%" headers="mcps1.1.5.1.4 "><p>true：即时生效播放，false：延迟到下轮循环播放再生效</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例

    ```
    // 指定播放片段
    this.anim.playSegments([10, 20], false)
    // 指定播放片段列表
    this.anim.playSegments([[0, 5], [20, 30]], true)
    ```


## AnimationItem.resetSegments<a name="section198278408372"></a>

resetSegments\(forceFlag: boolean\): void

重置动画播放片段，播放全帧。

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="15.540000000000001%" id="mcps1.1.5.1.1"><p>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.19%" id="mcps1.1.5.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.040000000000001%" id="mcps1.1.5.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.23%" id="mcps1.1.5.1.4"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="15.540000000000001%" headers="mcps1.1.5.1.1 "><p>forceFlag</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.19%" headers="mcps1.1.5.1.2 "><p>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.040000000000001%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.23%" headers="mcps1.1.5.1.4 "><p>true：即时生效播放，false：延迟到下轮循环播放再生效</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例

    ```
    this.anim.resetSegments(true)
    ```


## AnimationItem.resize<a name="section2672102714417"></a>

resize\(\): void

刷新动画布局。

-   示例

    ```
    this.anim.resize()
    ```


## AnimationItem.setSubframe<a name="section151492219586"></a>

setSubframe\(useSubFrame: boolean\): void

设置属性currentFrame的精度显示浮点数。

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="15.540000000000001%" id="mcps1.1.5.1.1"><p>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.170000000000002%" id="mcps1.1.5.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.059999999999999%" id="mcps1.1.5.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.23%" id="mcps1.1.5.1.4"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="15.540000000000001%" headers="mcps1.1.5.1.1 "><p>useSubFrames</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.170000000000002%" headers="mcps1.1.5.1.2 "><p>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.059999999999999%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.23%" headers="mcps1.1.5.1.4 "><p>currentFrame属性默认显示浮点数，该接口参数将影响currentFrame属性的精度。</p>
    <p>true：属性currentFrame显示浮点。</p>
    <p>false：属性currentFrame去浮点数显示整数。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例

    ```
    this.anim.setSubframe(false)
    ```


## AnimationItem.getDuration<a name="section1621121414110"></a>

getDuration\(inFrames?: boolean\): void

获取动画单次完整播放的时间\(与播放速度无关\)或帧数, 与Lottie.loadAnimation接口入参initialSegment有关。

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="15.540000000000001%" id="mcps1.1.5.1.1"><p>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.19%" id="mcps1.1.5.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.040000000000001%" id="mcps1.1.5.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.23%" id="mcps1.1.5.1.4"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="15.540000000000001%" headers="mcps1.1.5.1.1 "><p>inFrames</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.19%" headers="mcps1.1.5.1.2 "><p>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.040000000000001%" headers="mcps1.1.5.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.23%" headers="mcps1.1.5.1.4 "><p>true：获取帧数， false：获取时间(单位ms)，缺省默认false。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例

    ```
    this.anim.setSubframe(true)
    ```


## AnimationItem.addEventListener<a name="section2025011161294"></a>

addEventListener<T = any\>\(name: AnimationEventName, callback: AnimationEventCallback<T\>\): \(\) =\> void

添加侦听事件, 事件完成后会触发指定回调函数。返回可删除该侦听事件的函数对象。

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="15.540000000000001%" id="mcps1.1.5.1.1"><p>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.03%" id="mcps1.1.5.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.199999999999999%" id="mcps1.1.5.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.23%" id="mcps1.1.5.1.4"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="15.540000000000001%" headers="mcps1.1.5.1.1 "><p>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.03%" headers="mcps1.1.5.1.2 "><p>AnimationEventName</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.199999999999999%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.23%" headers="mcps1.1.5.1.4 "><p>指定动画事件类型，Lottie内置动画事件类型AnimationEventName：</p>
    <p>'enterFrame'、'loopComplete'、'complete'、'segmentStart'、'destroy'、'config_ready'、'data_ready'、'DOMLoaded'、'error'、'data_failed'、'loaded_images'</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="15.540000000000001%" headers="mcps1.1.5.1.1 "><p>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.03%" headers="mcps1.1.5.1.2 "><p>AnimationEventCallback&lt;T&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.199999999999999%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.23%" headers="mcps1.1.5.1.4 "><p>用户自定义回调函数</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例

    ```
    private callbackItem: any = function() {
        console.log("grunt loopComplete")
    }
    let delFunction = this.animateItem.addEventListener('loopComplete', this.callbackItem)
    
    // 删除侦听
    delFunction()
    ```


## AnimationItem.removeEventListener<a name="section10518181695"></a>

removeEventListener<T = any\>\(name: AnimationEventName, callback?: AnimationEventCallback<T\>\): void

删除侦听事件。

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="15.540000000000001%" id="mcps1.1.5.1.1"><p>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.03%" id="mcps1.1.5.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.199999999999999%" id="mcps1.1.5.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.23%" id="mcps1.1.5.1.4"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="15.540000000000001%" headers="mcps1.1.5.1.1 "><p>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.03%" headers="mcps1.1.5.1.2 "><p>AnimationEventName</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.199999999999999%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.23%" headers="mcps1.1.5.1.4 "><p>指定动画事件类型，Lottie内置动画事件类型AnimationEventName：</p>
    <p>'enterFrame'、'loopComplete'、'complete'、'segmentStart'、'destroy'、'config_ready'、'data_ready'、'DOMLoaded'、'error'、'data_failed'、'loaded_images'</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="15.540000000000001%" headers="mcps1.1.5.1.1 "><p>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.03%" headers="mcps1.1.5.1.2 "><p>AnimationEventCallback&lt;T&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.199999999999999%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.23%" headers="mcps1.1.5.1.4 "><p>用户自定义回调函数；缺省为空时, 删除此事件的所有回调函数。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例

    ```
    this.animateItem.removeEventListener('loopComplete', this.callbackItem)
    ```


## AnimationItem.triggerEvent<a name="section15091813747"></a>

triggerEvent<T = any\>\(name: AnimationEventName, args: T\): void

直接触发指定事件的所有已设置的回调函数。

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="15.540000000000001%" id="mcps1.1.5.1.1"><p>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.03%" id="mcps1.1.5.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.199999999999999%" id="mcps1.1.5.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.23%" id="mcps1.1.5.1.4"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="15.540000000000001%" headers="mcps1.1.5.1.1 "><p>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.03%" headers="mcps1.1.5.1.2 "><p>AnimationEventName</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.199999999999999%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.23%" headers="mcps1.1.5.1.4 "><p>指定动画事件类型</p>
    <p></p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="15.540000000000001%" headers="mcps1.1.5.1.1 "><p>args</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.03%" headers="mcps1.1.5.1.2 "><p>any</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.199999999999999%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.23%" headers="mcps1.1.5.1.4 "><p>用户自定义回调参数</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例

    ```
    private triggerCallBack: any = function(item) {
        console.log("trigger loopComplete, name:" + item.name)
    }
    
    this.animateItem.addEventListener('loopComplete', this.triggerCallBack)
    this.animateItem.triggerEvent('loopComplete', this.animateItem)
    this.animateItem.removeEventListener('loopComplete', this.triggerCallBack)
    ```


