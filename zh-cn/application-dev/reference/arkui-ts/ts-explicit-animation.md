# 显式动画<a name="ZH-CN_TOPIC_0000001237355059"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

<table><thead align="left"><tr><th class="cellrowborder" colspan="2" valign="top" id="mcps1.1.4.1.1"><p>接口名称</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.4.1.2"><p>功能描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p>animateTo(value: <a href="#section16458591411">AnimationOption</a>, event: ()=&gt; void) : void</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p>提供全局animateTo显式动画接口来指定由于闭包代码导致的状态变化插入过渡动效。</p>
<p>event指定显示动效的闭包函数，在闭包函数中导致的状态变化系统会自动插入过渡动画。</p>
</td>
</tr>
</tbody>
</table>

## AnimationOption对象说明<a name="section16458591411"></a>

-   属性

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="17.681768176817684%" id="mcps1.1.5.1.1"><p>属性名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="20.01200120012001%" id="mcps1.1.5.1.2"><p>属性类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="20.54205420542054%" id="mcps1.1.5.1.3"><p>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="41.76417641764177%" id="mcps1.1.5.1.4"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="17.681768176817684%" headers="mcps1.1.5.1.1 "><p>duration</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.01200120012001%" headers="mcps1.1.5.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.54205420542054%" headers="mcps1.1.5.1.3 "><p>1000</p>
    </td>
    <td class="cellrowborder" valign="top" width="41.76417641764177%" headers="mcps1.1.5.1.4 "><p>动画持续时间，单位为毫秒。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="17.681768176817684%" headers="mcps1.1.5.1.1 "><p>tempo</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.01200120012001%" headers="mcps1.1.5.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.54205420542054%" headers="mcps1.1.5.1.3 "><p>1.0</p>
    </td>
    <td class="cellrowborder" valign="top" width="41.76417641764177%" headers="mcps1.1.5.1.4 "><p>动画的播放速度，值越大动画播放越快，值越小播放越慢，为0时无动画效果。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="17.681768176817684%" headers="mcps1.1.5.1.1 "><p>curve</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.01200120012001%" headers="mcps1.1.5.1.2 "><p>Curve | Curves</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.54205420542054%" headers="mcps1.1.5.1.3 "><p>Linear</p>
    </td>
    <td class="cellrowborder" valign="top" width="41.76417641764177%" headers="mcps1.1.5.1.4 "><p>动画曲线。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="17.681768176817684%" headers="mcps1.1.5.1.1 "><p>delay</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.01200120012001%" headers="mcps1.1.5.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.54205420542054%" headers="mcps1.1.5.1.3 "><p>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="41.76417641764177%" headers="mcps1.1.5.1.4 "><p>单位为ms(毫秒)，默认不延时播放。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="17.681768176817684%" headers="mcps1.1.5.1.1 "><p>iterations</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.01200120012001%" headers="mcps1.1.5.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.54205420542054%" headers="mcps1.1.5.1.3 "><p>1</p>
    </td>
    <td class="cellrowborder" valign="top" width="41.76417641764177%" headers="mcps1.1.5.1.4 "><p>默认播放一次，设置为-1时表示无限次播放。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="17.681768176817684%" headers="mcps1.1.5.1.1 "><p>playMode</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.01200120012001%" headers="mcps1.1.5.1.2 "><p>PlayMode</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.54205420542054%" headers="mcps1.1.5.1.3 "><p>Normal</p>
    </td>
    <td class="cellrowborder" valign="top" width="41.76417641764177%" headers="mcps1.1.5.1.4 "><p>设置动画播放模式，默认播放完成后重头开始播放。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   接口

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="40.6%" id="mcps1.1.3.1.1"><p>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.4%" id="mcps1.1.3.1.2"><p>功能描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="40.6%" headers="mcps1.1.3.1.1 "><p>onFinish() =&gt; void</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.4%" headers="mcps1.1.3.1.2 "><p>动效播放完成回调。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 示例<a name="section1768142514453"></a>

```
@Entry
@Component
struct AnimateToExample {
  @State widthSize: number = 200
  @State heightSize: number = 100
  private flag: boolean = true

  build() {
    Column() {
      Button('click me')
        .width(this.widthSize)
        .height(this.heightSize)
        .backgroundColor(0x317aff)
        .onClick((event: ClickEvent) => {
          // 对Button组件的宽高属性进行动画配置
          if (this.flag) {
            animateTo({
              duration: 1000, // 动画时长
              tempo: 0.5, // 播放速率
              curve: Curve.EaseInOut, // 动画曲线
              delay: 200, // 动画延迟
              iterations: 1, // 播放次数
              playMode: PlayMode.Normal, // 动画模式
              onFinish: () => {
                console.info('play end')
              }
            }, () => {
              this.widthSize = 100
              this.heightSize = 50
            })
          } else {
            animateTo({
              duration: 200, // 动画时长
              curve: Curve.Ease, // 动画曲线
              delay: 200, // 动画延迟
              iterations: 1, // 播放次数
              playMode: PlayMode.Normal, // 动画模式
              onFinish: () => {
                console.info('play end')
              }
            }, () => {
              this.widthSize = 200
              this.heightSize = 100
            })
          }
          this.flag = !this.flag
        })
    }.width('100%').margin({ top: 5 })
  }
}
```

![](figures/AnimateTo.gif)

