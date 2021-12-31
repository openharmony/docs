# 属性动画<a name="ZH-CN_TOPIC_0000001192915094"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

组件的通用属性发生变化时，可以创建属性动画进行渐变，提升用户体验。

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="16.21%" id="mcps1.1.5.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="15.980000000000002%" id="mcps1.1.5.1.2"><p>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="13.630000000000003%" id="mcps1.1.5.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="54.18000000000001%" id="mcps1.1.5.1.4"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="16.21%" headers="mcps1.1.5.1.1 "><p>duration</p>
</td>
<td class="cellrowborder" valign="top" width="15.980000000000002%" headers="mcps1.1.5.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="13.630000000000003%" headers="mcps1.1.5.1.3 "><p>1000</p>
</td>
<td class="cellrowborder" valign="top" width="54.18000000000001%" headers="mcps1.1.5.1.4 "><p>单位为毫秒，默认动画时长为1000毫秒。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16.21%" headers="mcps1.1.5.1.1 "><p>curve</p>
</td>
<td class="cellrowborder" valign="top" width="15.980000000000002%" headers="mcps1.1.5.1.2 "><p><a href="#li16621545614">Curve</a></p>
</td>
<td class="cellrowborder" valign="top" width="13.630000000000003%" headers="mcps1.1.5.1.3 "><p>Linear</p>
</td>
<td class="cellrowborder" valign="top" width="54.18000000000001%" headers="mcps1.1.5.1.4 "><p>默认曲线为线性，有效值参见<a href="#table12144170154116">Curve</a>说明。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16.21%" headers="mcps1.1.5.1.1 "><p>delay</p>
</td>
<td class="cellrowborder" valign="top" width="15.980000000000002%" headers="mcps1.1.5.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="13.630000000000003%" headers="mcps1.1.5.1.3 "><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="54.18000000000001%" headers="mcps1.1.5.1.4 "><p>单位为毫秒，默认不延时播放。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16.21%" headers="mcps1.1.5.1.1 "><p>iterations</p>
</td>
<td class="cellrowborder" valign="top" width="15.980000000000002%" headers="mcps1.1.5.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="13.630000000000003%" headers="mcps1.1.5.1.3 "><p>1</p>
</td>
<td class="cellrowborder" valign="top" width="54.18000000000001%" headers="mcps1.1.5.1.4 "><p>默认播放一次，设置为-1时表示无限次播放。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16.21%" headers="mcps1.1.5.1.1 "><p>playMode</p>
</td>
<td class="cellrowborder" valign="top" width="15.980000000000002%" headers="mcps1.1.5.1.2 "><p><a href="ts-appendix-enums.md#section2780178121714">PlayMode</a></p>
</td>
<td class="cellrowborder" valign="top" width="13.630000000000003%" headers="mcps1.1.5.1.3 "><p>Normal</p>
</td>
<td class="cellrowborder" valign="top" width="54.18000000000001%" headers="mcps1.1.5.1.4 "><p>设置动画播放模式，默认播放完成后重头开始播放。</p>
</td>
</tr>
</tbody>
</table>

-   <a name="li16621545614"></a>Curve枚举说明

    <a name="table12144170154116"></a>
    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="22.48%" id="mcps1.1.3.1.1"><p>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="77.52%" id="mcps1.1.3.1.2"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="22.48%" headers="mcps1.1.3.1.1 "><p>Linear</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.52%" headers="mcps1.1.3.1.2 "><p>表示动画从头到尾的速度都是相同的。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="22.48%" headers="mcps1.1.3.1.1 "><p>Ease</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.52%" headers="mcps1.1.3.1.2 "><p>表示动画以低速开始，然后加快，在结束前变慢，CubicBezier(0.25, 0.1, 0.25, 1.0)。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="22.48%" headers="mcps1.1.3.1.1 "><p>EaseIn</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.52%" headers="mcps1.1.3.1.2 "><p>表示动画以低速开始，CubicBezier(0.42, 0.0, 1.0, 1.0)。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="22.48%" headers="mcps1.1.3.1.1 "><p>EaseOut</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.52%" headers="mcps1.1.3.1.2 "><p>表示动画以低速结束，CubicBezier(0.0, 0.0, 0.58, 1.0)。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="22.48%" headers="mcps1.1.3.1.1 "><p>EaseInOut</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.52%" headers="mcps1.1.3.1.2 "><p>表示动画以低速开始和结束，CubicBezier(0.42, 0.0, 0.58, 1.0)。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="22.48%" headers="mcps1.1.3.1.1 "><p>FastOutSlowIn</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.52%" headers="mcps1.1.3.1.2 "><p>标准曲线，cubic-bezier(0.4, 0.0, 0.2, 1.0)。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="22.48%" headers="mcps1.1.3.1.1 "><p>LinearOutSlowIn</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.52%" headers="mcps1.1.3.1.2 "><p>减速曲线，cubic-bezier(0.0, 0.0, 0.2, 1.0)。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="22.48%" headers="mcps1.1.3.1.1 "><p>FastOutLinearIn</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.52%" headers="mcps1.1.3.1.2 "><p>加速曲线，cubic-bezier(0.4, 0.0, 1.0, 1.0)。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="22.48%" headers="mcps1.1.3.1.1 "><p>ExtremeDeceleration</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.52%" headers="mcps1.1.3.1.2 "><p>急缓曲线，cubic-bezier(0.0, 0.0, 0.0, 1.0)。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="22.48%" headers="mcps1.1.3.1.1 "><p>Sharp</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.52%" headers="mcps1.1.3.1.2 "><p>锐利曲线，cubic-bezier(0.33, 0.0, 0.67, 1.0)。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="22.48%" headers="mcps1.1.3.1.1 "><p>Rhythm</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.52%" headers="mcps1.1.3.1.2 "><p>节奏曲线，cubic-bezier(0.7, 0.0, 0.2, 1.0)。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="22.48%" headers="mcps1.1.3.1.1 "><p>Smooth</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.52%" headers="mcps1.1.3.1.2 "><p>平滑曲线，cubic-bezier(0.4, 0.0, 0.4, 1.0)。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="22.48%" headers="mcps1.1.3.1.1 "><p>Friction</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.52%" headers="mcps1.1.3.1.2 "><p>阻尼曲线，CubicBezier(0.2, 0.0, 0.2, 1.0)。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 示例<a name="section137791934201313"></a>

```
@Entry
@Component
struct AttrAnimationExample {
  @State widthSize: number = 200
  @State heightSize: number = 100
  @State flag: boolean = true

  build() {
    Column() {
      Button('click me')
        .onClick((event: ClickEvent) => {
          if (this.flag) {
            this.widthSize = 100
            this.heightSize = 50
          } else {
            this.widthSize = 200
            this.heightSize = 100
          }
          this.flag = !this.flag
        })
        .width(this.widthSize).height(this.heightSize).backgroundColor(0x317aff)
        .animation({
          duration: 2000, // 动画时长
          curve: Curve.EaseOut, // 动画曲线
          delay: 500, // 动画延迟
          iterations: 1, // 播放次数
          playMode: PlayMode.Normal // 动画模式
        }) // 对Button组件的宽高属性进行动画配置
    }.width('100%').margin({ top: 5 })
  }
}
```

![](figures/AttrAnimation.gif)

