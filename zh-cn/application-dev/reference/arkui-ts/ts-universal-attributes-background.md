# 背景设置<a name="ZH-CN_TOPIC_0000001111421392"></a>

设置组件的背景色。

<a name="table548mcpsimp"></a>
<table><thead align="left"><tr id="row555mcpsimp"><th class="cellrowborder" valign="top" width="18.279999999999998%" id="mcps1.1.5.1.1"><p id="p557mcpsimp"><a name="p557mcpsimp"></a><a name="p557mcpsimp"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="22.439999999999998%" id="mcps1.1.5.1.2"><p id="p559mcpsimp"><a name="p559mcpsimp"></a><a name="p559mcpsimp"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.85%" id="mcps1.1.5.1.3"><p id="p561mcpsimp"><a name="p561mcpsimp"></a><a name="p561mcpsimp"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="48.43%" id="mcps1.1.5.1.4"><p id="p563mcpsimp"><a name="p563mcpsimp"></a><a name="p563mcpsimp"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row564mcpsimp"><td class="cellrowborder" valign="top" width="18.279999999999998%" headers="mcps1.1.5.1.1 "><p id="p566mcpsimp"><a name="p566mcpsimp"></a><a name="p566mcpsimp"></a>backgroundColor</p>
</td>
<td class="cellrowborder" valign="top" width="22.439999999999998%" headers="mcps1.1.5.1.2 "><p id="p568mcpsimp"><a name="p568mcpsimp"></a><a name="p568mcpsimp"></a>Color</p>
</td>
<td class="cellrowborder" valign="top" width="10.85%" headers="mcps1.1.5.1.3 "><p id="p570mcpsimp"><a name="p570mcpsimp"></a><a name="p570mcpsimp"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="48.43%" headers="mcps1.1.5.1.4 "><p id="p572mcpsimp"><a name="p572mcpsimp"></a><a name="p572mcpsimp"></a>设置组件的背景色。</p>
</td>
</tr>
<tr id="row1993142420457"><td class="cellrowborder" valign="top" width="18.279999999999998%" headers="mcps1.1.5.1.1 "><p id="p1493242415452"><a name="p1493242415452"></a><a name="p1493242415452"></a>backgroundImage</p>
</td>
<td class="cellrowborder" valign="top" width="22.439999999999998%" headers="mcps1.1.5.1.2 "><p id="p3215443104520"><a name="p3215443104520"></a><a name="p3215443104520"></a>src: string,</p>
<p id="p1393262494519"><a name="p1393262494519"></a><a name="p1393262494519"></a>repeat?: <a href="ts-appendix-enums.md#section5656191941718">ImageRepeat</a></p>
</td>
<td class="cellrowborder" valign="top" width="10.85%" headers="mcps1.1.5.1.3 "><p id="p1093220249451"><a name="p1093220249451"></a><a name="p1093220249451"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="48.43%" headers="mcps1.1.5.1.4 "><p id="p539239184613"><a name="p539239184613"></a><a name="p539239184613"></a>src参数：图片地址，支持网络图片资源和本地图片资源地址(不支持svg类型的图片)。</p>
<p id="p59321124124510"><a name="p59321124124510"></a><a name="p59321124124510"></a>repeat参数：设置背景图片的重复样式，默认不重复。</p>
</td>
</tr>
<tr id="row865252718459"><td class="cellrowborder" valign="top" width="18.279999999999998%" headers="mcps1.1.5.1.1 "><p id="p116521927114520"><a name="p116521927114520"></a><a name="p116521927114520"></a>backgroundImageSize</p>
</td>
<td class="cellrowborder" valign="top" width="22.439999999999998%" headers="mcps1.1.5.1.2 "><p id="p11618630194614"><a name="p11618630194614"></a><a name="p11618630194614"></a>{</p>
<p id="p466233524614"><a name="p466233524614"></a><a name="p466233524614"></a>width?: Length,</p>
<p id="p208462032787"><a name="p208462032787"></a><a name="p208462032787"></a>height?: Length</p>
<p id="p20652192724512"><a name="p20652192724512"></a><a name="p20652192724512"></a>} | <a href="#li937882865915">ImageSize</a></p>
</td>
<td class="cellrowborder" valign="top" width="10.85%" headers="mcps1.1.5.1.3 "><p id="p6652202734515"><a name="p6652202734515"></a><a name="p6652202734515"></a>Auto</p>
</td>
<td class="cellrowborder" valign="top" width="48.43%" headers="mcps1.1.5.1.4 "><p id="p196521327134511"><a name="p196521327134511"></a><a name="p196521327134511"></a>设置背景图像的高度和宽度。当输入为{width: Length, height: Length}对象时，如果只设置一个属性，则第二个属性保持图片原始宽高比进行调整。默认保持原图的比例不变。</p>
</td>
</tr>
<tr id="row561293054512"><td class="cellrowborder" valign="top" width="18.279999999999998%" headers="mcps1.1.5.1.1 "><p id="p16612193094518"><a name="p16612193094518"></a><a name="p16612193094518"></a>backgroundImagePosition</p>
</td>
<td class="cellrowborder" valign="top" width="22.439999999999998%" headers="mcps1.1.5.1.2 "><p id="p159911535182"><a name="p159911535182"></a><a name="p159911535182"></a>{</p>
<p id="p11265191513910"><a name="p11265191513910"></a><a name="p11265191513910"></a>x?: Length,</p>
<p id="p33314129919"><a name="p33314129919"></a><a name="p33314129919"></a>y?: Length</p>
<p id="p86122302456"><a name="p86122302456"></a><a name="p86122302456"></a>} | <a href="ts-appendix-enums.md#section1145418513159">Alignment</a></p>
</td>
<td class="cellrowborder" valign="top" width="10.85%" headers="mcps1.1.5.1.3 "><p id="p768611265914"><a name="p768611265914"></a><a name="p768611265914"></a>{</p>
<p id="p182481283917"><a name="p182481283917"></a><a name="p182481283917"></a>x: 0,</p>
<p id="p48380293912"><a name="p48380293912"></a><a name="p48380293912"></a>y: 0</p>
<p id="p1261283014510"><a name="p1261283014510"></a><a name="p1261283014510"></a>}</p>
</td>
<td class="cellrowborder" valign="top" width="48.43%" headers="mcps1.1.5.1.4 "><p id="p261293004518"><a name="p261293004518"></a><a name="p261293004518"></a>设置背景图在组件中显示位置。</p>
</td>
</tr>
</tbody>
</table>

-   <a name="li937882865915"></a>ImageSize枚举说明

    <a name="table61607433471"></a>
    <table><thead align="left"><tr id="row13210194394717"><th class="cellrowborder" valign="top" width="30.459999999999997%" id="mcps1.1.3.1.1"><p id="p7211134394716"><a name="p7211134394716"></a><a name="p7211134394716"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.54%" id="mcps1.1.3.1.2"><p id="p6211204384714"><a name="p6211204384714"></a><a name="p6211204384714"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1121164334710"><td class="cellrowborder" valign="top" width="30.459999999999997%" headers="mcps1.1.3.1.1 "><p id="p8211144317475"><a name="p8211144317475"></a><a name="p8211144317475"></a>Cover</p>
    </td>
    <td class="cellrowborder" valign="top" width="69.54%" headers="mcps1.1.3.1.2 "><p id="p162119432471"><a name="p162119432471"></a><a name="p162119432471"></a>默认值，保持宽高比进行缩小或者放大，使得图片两边都大于或等于显示边界。</p>
    </td>
    </tr>
    <tr id="row192118430476"><td class="cellrowborder" valign="top" width="30.459999999999997%" headers="mcps1.1.3.1.1 "><p id="p20211543164713"><a name="p20211543164713"></a><a name="p20211543164713"></a>Contain</p>
    </td>
    <td class="cellrowborder" valign="top" width="69.54%" headers="mcps1.1.3.1.2 "><p id="p162111943104711"><a name="p162111943104711"></a><a name="p162111943104711"></a>保持宽高比进行缩小或者放大，使得图片完全显示在显示边界内。</p>
    </td>
    </tr>
    <tr id="row16211843204712"><td class="cellrowborder" valign="top" width="30.459999999999997%" headers="mcps1.1.3.1.1 "><p id="p7211134334715"><a name="p7211134334715"></a><a name="p7211134334715"></a>Auto</p>
    </td>
    <td class="cellrowborder" valign="top" width="69.54%" headers="mcps1.1.3.1.2 "><p id="p121118431474"><a name="p121118431474"></a><a name="p121118431474"></a>保持原图的比例不变。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 示例<a name="section88491836154010"></a>

```
@Entry
@Component
struct BackgroundExample {
  build() {
    Column({ space: 5 }) {
      Text('background color').fontSize(9).width('90%').fontColor(0xCCCCCC)
      Row().width('90%').height(50).backgroundColor(0xE5E5E5).border({ width: 1 })

      Text('background image repeat along X').fontSize(9).width('90%').fontColor(0xCCCCCC)
      Row()
        .backgroundImage('/comment/bg.jpg', ImageRepeat.X)
        .backgroundImageSize({ width: '250px', height: '140px' })
        .width('90%')
        .height(70)
        .border({ width: 1 })

      Text('background image repeat along Y').fontSize(9).width('90%').fontColor(0xCCCCCC)
      Row()
        .backgroundImage('/comment/bg.jpg', ImageRepeat.Y)
        .backgroundImageSize({ width: '500px', height: '120px' })
        .width('90%')
        .height(100)
        .border({ width: 1 })

      Text('background image size').fontSize(9).width('90%').fontColor(0xCCCCCC)
      Row()
        .width('90%').height(150)
        .backgroundImage('/comment/bg.jpg', ImageRepeat.NoRepeat)
        .backgroundImageSize({ width: 1000, height: 500 })
        .border({ width: 1 })

      Text('background fill the box(Cover)').fontSize(9).width('90%').fontColor(0xCCCCCC)
      // 不保准图片完整的情况下占满盒子
      Row()
        .width(200)
        .height(50)
        .backgroundImage('/comment/bg.jpg', ImageRepeat.NoRepeat)
        .backgroundImageSize(ImageSize.Cover)
        .border({ width: 1 })

      Text('background fill the box(Contain)').fontSize(9).width('90%').fontColor(0xCCCCCC)
      // 保准图片完整的情况下放到最大
      Row()
        .width(200)
        .height(50)
        .backgroundImage('/comment/bg.jpg', ImageRepeat.NoRepeat)
        .backgroundImageSize(ImageSize.Contain)
        .border({ width: 1 })

      Text('background image position').fontSize(9).width('90%').fontColor(0xCCCCCC)
      Row()
        .width(100)
        .height(50)
        .backgroundImage('/comment/bg.jpg', ImageRepeat.NoRepeat)
        .backgroundImageSize({ width: 1000, height: 560 })
        .backgroundImagePosition({ x: -500, y: -300 })
        .border({ width: 1 })
    }
    .width('100%').height('100%').padding({ top: 5 })
  }
}
```

![](figures/back.png)

