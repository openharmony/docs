# 背景设置<a name="ZH-CN_TOPIC_0000001237555119"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

设置组件的背景色。

## 权限列表<a name="section781125411508"></a>

无

## 属性<a name="section6820191711316"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="18.279999999999998%" id="mcps1.1.5.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="22.439999999999998%" id="mcps1.1.5.1.2"><p>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.85%" id="mcps1.1.5.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="48.43%" id="mcps1.1.5.1.4"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="18.279999999999998%" headers="mcps1.1.5.1.1 "><p>backgroundColor</p>
</td>
<td class="cellrowborder" valign="top" width="22.439999999999998%" headers="mcps1.1.5.1.2 "><p>Color</p>
</td>
<td class="cellrowborder" valign="top" width="10.85%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="48.43%" headers="mcps1.1.5.1.4 "><p>设置组件的背景色。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="18.279999999999998%" headers="mcps1.1.5.1.1 "><p>backgroundImage</p>
</td>
<td class="cellrowborder" valign="top" width="22.439999999999998%" headers="mcps1.1.5.1.2 "><p>src: string,</p>
<p>repeat?: <a href="ts-appendix-enums.md#section5656191941718">ImageRepeat</a></p>
</td>
<td class="cellrowborder" valign="top" width="10.85%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="48.43%" headers="mcps1.1.5.1.4 "><p>src参数：图片地址，支持网络图片资源和本地图片资源地址(不支持svg类型的图片)。</p>
<p>repeat参数：设置背景图片的重复样式，默认不重复。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="18.279999999999998%" headers="mcps1.1.5.1.1 "><p>backgroundImageSize</p>
</td>
<td class="cellrowborder" valign="top" width="22.439999999999998%" headers="mcps1.1.5.1.2 "><p>{</p>
<p>width?: Length,</p>
<p>height?: Length</p>
<p>} | <a href="#li937882865915">ImageSize</a></p>
</td>
<td class="cellrowborder" valign="top" width="10.85%" headers="mcps1.1.5.1.3 "><p>Auto</p>
</td>
<td class="cellrowborder" valign="top" width="48.43%" headers="mcps1.1.5.1.4 "><p>设置背景图像的高度和宽度。当输入为{width: Length, height: Length}对象时，如果只设置一个属性，则第二个属性保持图片原始宽高比进行调整。默认保持原图的比例不变。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="18.279999999999998%" headers="mcps1.1.5.1.1 "><p>backgroundImagePosition</p>
</td>
<td class="cellrowborder" valign="top" width="22.439999999999998%" headers="mcps1.1.5.1.2 "><p>{</p>
<p>x?: Length,</p>
<p>y?: Length</p>
<p>} | <a href="ts-appendix-enums.md#section1145418513159">Alignment</a></p>
</td>
<td class="cellrowborder" valign="top" width="10.85%" headers="mcps1.1.5.1.3 "><p>{</p>
<p>x: 0,</p>
<p>y: 0</p>
<p>}</p>
</td>
<td class="cellrowborder" valign="top" width="48.43%" headers="mcps1.1.5.1.4 "><p>设置背景图在组件中显示位置。</p>
</td>
</tr>
</tbody>
</table>

-   <a name="li937882865915"></a>ImageSize枚举说明

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="30.459999999999997%" id="mcps1.1.3.1.1"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.54%" id="mcps1.1.3.1.2"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="30.459999999999997%" headers="mcps1.1.3.1.1 "><p>Cover</p>
    </td>
    <td class="cellrowborder" valign="top" width="69.54%" headers="mcps1.1.3.1.2 "><p>默认值，保持宽高比进行缩小或者放大，使得图片两边都大于或等于显示边界。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="30.459999999999997%" headers="mcps1.1.3.1.1 "><p>Contain</p>
    </td>
    <td class="cellrowborder" valign="top" width="69.54%" headers="mcps1.1.3.1.2 "><p>保持宽高比进行缩小或者放大，使得图片完全显示在显示边界内。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="30.459999999999997%" headers="mcps1.1.3.1.1 "><p>Auto</p>
    </td>
    <td class="cellrowborder" valign="top" width="69.54%" headers="mcps1.1.3.1.2 "><p>保持原图的比例不变。</p>
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

