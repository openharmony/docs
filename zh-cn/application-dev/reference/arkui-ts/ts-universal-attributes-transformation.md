# 图形变换<a name="ZH-CN_TOPIC_0000001119769150"></a>

<a name="table2999mcpsimp"></a>
<table><thead align="left"><tr id="row3007mcpsimp"><th class="cellrowborder" valign="top" width="13.87%" id="mcps1.1.5.1.1"><p id="p3009mcpsimp"><a name="p3009mcpsimp"></a><a name="p3009mcpsimp"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="32.28%" id="mcps1.1.5.1.2"><p id="p3011mcpsimp"><a name="p3011mcpsimp"></a><a name="p3011mcpsimp"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="28.449999999999996%" id="mcps1.1.5.1.3"><p id="p3013mcpsimp"><a name="p3013mcpsimp"></a><a name="p3013mcpsimp"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="25.4%" id="mcps1.1.5.1.4"><p id="p3017mcpsimp"><a name="p3017mcpsimp"></a><a name="p3017mcpsimp"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row3018mcpsimp"><td class="cellrowborder" valign="top" width="13.87%" headers="mcps1.1.5.1.1 "><p id="p3020mcpsimp"><a name="p3020mcpsimp"></a><a name="p3020mcpsimp"></a>rotate</p>
</td>
<td class="cellrowborder" valign="top" width="32.28%" headers="mcps1.1.5.1.2 "><p id="p12827142241112"><a name="p12827142241112"></a><a name="p12827142241112"></a>{</p>
<p id="p5541155661115"><a name="p5541155661115"></a><a name="p5541155661115"></a>x?: number,</p>
<p id="p14131160161217"><a name="p14131160161217"></a><a name="p14131160161217"></a>y?: number,</p>
<p id="p2698910171214"><a name="p2698910171214"></a><a name="p2698910171214"></a>z?: number,</p>
<p id="p17777413101214"><a name="p17777413101214"></a><a name="p17777413101214"></a>angle?: Angle,</p>
<p id="p14233426141215"><a name="p14233426141215"></a><a name="p14233426141215"></a>centerX?: Length,</p>
<p id="p9376295120"><a name="p9376295120"></a><a name="p9376295120"></a>centerY?: Length</p>
<p id="p3022mcpsimp"><a name="p3022mcpsimp"></a><a name="p3022mcpsimp"></a>}</p>
</td>
<td class="cellrowborder" valign="top" width="28.449999999999996%" headers="mcps1.1.5.1.3 "><p id="p1239258101317"><a name="p1239258101317"></a><a name="p1239258101317"></a>{</p>
<p id="p38045598131"><a name="p38045598131"></a><a name="p38045598131"></a>x: 0,</p>
<p id="p15451101181418"><a name="p15451101181418"></a><a name="p15451101181418"></a>y: 0,</p>
<p id="p16990897148"><a name="p16990897148"></a><a name="p16990897148"></a>z: 0,</p>
<p id="p118341975147"><a name="p118341975147"></a><a name="p118341975147"></a>angle: 0,</p>
<p id="p1917210410510"><a name="p1917210410510"></a><a name="p1917210410510"></a>centerX: '50%',</p>
<p id="p3492022141418"><a name="p3492022141418"></a><a name="p3492022141418"></a>centerY: '50%'</p>
<p id="p3024mcpsimp"><a name="p3024mcpsimp"></a><a name="p3024mcpsimp"></a>}</p>
</td>
<td class="cellrowborder" valign="top" width="25.4%" headers="mcps1.1.5.1.4 "><p id="p3028mcpsimp"><a name="p3028mcpsimp"></a><a name="p3028mcpsimp"></a>(x, y, z)指定一个矢量，表示旋转轴，正角度为顺时针转动，负角度为逆时针转动，默认值为0，同时可以通过centerX和centerY设置旋转的中心点。</p>
</td>
</tr>
<tr id="row3029mcpsimp"><td class="cellrowborder" valign="top" width="13.87%" headers="mcps1.1.5.1.1 "><p id="p3031mcpsimp"><a name="p3031mcpsimp"></a><a name="p3031mcpsimp"></a>translate</p>
</td>
<td class="cellrowborder" valign="top" width="32.28%" headers="mcps1.1.5.1.2 "><p id="p144161243161214"><a name="p144161243161214"></a><a name="p144161243161214"></a>{</p>
<p id="p13762144521216"><a name="p13762144521216"></a><a name="p13762144521216"></a>x?: Length,</p>
<p id="p1870614710120"><a name="p1870614710120"></a><a name="p1870614710120"></a>y?: Length,</p>
<p id="p7152175031215"><a name="p7152175031215"></a><a name="p7152175031215"></a>z? : Length</p>
<p id="p3033mcpsimp"><a name="p3033mcpsimp"></a><a name="p3033mcpsimp"></a>}</p>
</td>
<td class="cellrowborder" valign="top" width="28.449999999999996%" headers="mcps1.1.5.1.3 "><p id="p102121847131418"><a name="p102121847131418"></a><a name="p102121847131418"></a>{</p>
<p id="p15804174814143"><a name="p15804174814143"></a><a name="p15804174814143"></a>x: 0,</p>
<p id="p2540145020146"><a name="p2540145020146"></a><a name="p2540145020146"></a>y: 0,</p>
<p id="p18808152101419"><a name="p18808152101419"></a><a name="p18808152101419"></a>z: 0</p>
<p id="p3035mcpsimp"><a name="p3035mcpsimp"></a><a name="p3035mcpsimp"></a>}</p>
</td>
<td class="cellrowborder" valign="top" width="25.4%" headers="mcps1.1.5.1.4 "><p id="p3039mcpsimp"><a name="p3039mcpsimp"></a><a name="p3039mcpsimp"></a>可以分别设置X轴、Y轴、Z轴的平移距离，距离的正负控制平移的方向，默认值为0。</p>
</td>
</tr>
<tr id="row3040mcpsimp"><td class="cellrowborder" valign="top" width="13.87%" headers="mcps1.1.5.1.1 "><p id="p3042mcpsimp"><a name="p3042mcpsimp"></a><a name="p3042mcpsimp"></a>scale</p>
</td>
<td class="cellrowborder" valign="top" width="32.28%" headers="mcps1.1.5.1.2 "><p id="p192253213139"><a name="p192253213139"></a><a name="p192253213139"></a>{</p>
<p id="p1582354201319"><a name="p1582354201319"></a><a name="p1582354201319"></a>x?: number,</p>
<p id="p61961877139"><a name="p61961877139"></a><a name="p61961877139"></a>y?: number,</p>
<p id="p187761917136"><a name="p187761917136"></a><a name="p187761917136"></a>z?: number,</p>
<p id="p148699403133"><a name="p148699403133"></a><a name="p148699403133"></a>centerX?: Length,</p>
<p id="p93415382132"><a name="p93415382132"></a><a name="p93415382132"></a>centerY?: Length</p>
<p id="p3044mcpsimp"><a name="p3044mcpsimp"></a><a name="p3044mcpsimp"></a>}</p>
</td>
<td class="cellrowborder" valign="top" width="28.449999999999996%" headers="mcps1.1.5.1.3 "><p id="p234156191410"><a name="p234156191410"></a><a name="p234156191410"></a>{</p>
<p id="p9677165717148"><a name="p9677165717148"></a><a name="p9677165717148"></a>x: 1,</p>
<p id="p102386051519"><a name="p102386051519"></a><a name="p102386051519"></a>y: 1,</p>
<p id="p16318123191510"><a name="p16318123191510"></a><a name="p16318123191510"></a>z: 1,</p>
<p id="p10695631520"><a name="p10695631520"></a><a name="p10695631520"></a>centerX:'50%',</p>
<p id="p12661131519"><a name="p12661131519"></a><a name="p12661131519"></a>centerY:'50%'</p>
<p id="p3046mcpsimp"><a name="p3046mcpsimp"></a><a name="p3046mcpsimp"></a>}</p>
</td>
<td class="cellrowborder" valign="top" width="25.4%" headers="mcps1.1.5.1.4 "><p id="p3050mcpsimp"><a name="p3050mcpsimp"></a><a name="p3050mcpsimp"></a>可以分别设置X轴、Y轴、Z轴的缩放比例，默认值为1，同时可以通过centerX和centerY设置缩放的中心点。</p>
</td>
</tr>
<tr id="row3051mcpsimp"><td class="cellrowborder" valign="top" width="13.87%" headers="mcps1.1.5.1.1 "><p id="p3053mcpsimp"><a name="p3053mcpsimp"></a><a name="p3053mcpsimp"></a>transform</p>
</td>
<td class="cellrowborder" valign="top" width="32.28%" headers="mcps1.1.5.1.2 "><p id="p3055mcpsimp"><a name="p3055mcpsimp"></a><a name="p3055mcpsimp"></a>matrix: Matrix4</p>
</td>
<td class="cellrowborder" valign="top" width="28.449999999999996%" headers="mcps1.1.5.1.3 "><p id="p3057mcpsimp"><a name="p3057mcpsimp"></a><a name="p3057mcpsimp"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="25.4%" headers="mcps1.1.5.1.4 "><p id="p3060mcpsimp"><a name="p3060mcpsimp"></a><a name="p3060mcpsimp"></a>设置当前组件的变换矩阵。</p>
</td>
</tr>
</tbody>
</table>

## 示例<a name="section4278134412416"></a>

```
import Matrix4 from '@ohos.matrix4'

@Entry
@Component
struct TransformExample {
  build() {
    Column() {
      Text('rotate').width('90%').fontColor(0xCCCCCC).padding(15).fontSize(30)
      Row()
        .rotate({
          x: 1,
          y: 1,
          z: 1,
          centerX: '50%',
          centerY: '50%',
          angle: 300
        }) // 组件以(1,1,1)为旋转轴，中心点顺时针旋转 300度
        .width(100).height(100).backgroundColor(0xAFEEEE)

      Text('translate').width('90%').fontColor(0xCCCCCC).padding(10).fontSize(30)
      Row()
        .translate({ x: 100, y: 5 }) // x轴平移100，y轴平移5
        .width(100).height(100).backgroundColor(0xAFEEEE).margin({bottom:10})

      Text('scale').width('90%').fontColor(0xCCCCCC).padding(15).fontSize(30)
      Row()
        .scale({ x: 2, y: 0.5 }) // 高度缩小一倍，宽度放大一倍，z轴在2D下无效果
        .width(100).height(100).backgroundColor(0xAFEEEE)

      Text('Matrix4').width('90%').fontColor(0xCCCCCC).padding(15).fontSize(30)
      Row()
        .width(100).height(100).backgroundColor(0xAFEEEE)
        .transform(Matrix4.identity().translate({ x: 100, y: 100, z: 30 }))
    }.width('100%').margin({ top: 5 })
  }
}
```

![](figures/1111.png)

