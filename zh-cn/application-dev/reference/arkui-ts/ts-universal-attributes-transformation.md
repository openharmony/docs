# 图形变换<a name="ZH-CN_TOPIC_0000001237355071"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 权限列表<a name="section781125411508"></a>

无

## 属性<a name="section6820191711316"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="13.87%" id="mcps1.1.5.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="32.28%" id="mcps1.1.5.1.2"><p>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="28.449999999999996%" id="mcps1.1.5.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="25.4%" id="mcps1.1.5.1.4"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="13.87%" headers="mcps1.1.5.1.1 "><p>rotate</p>
</td>
<td class="cellrowborder" valign="top" width="32.28%" headers="mcps1.1.5.1.2 "><p>{</p>
<p>x?: number,</p>
<p>y?: number,</p>
<p>z?: number,</p>
<p>angle?: Angle,</p>
<p>centerX?: Length,</p>
<p>centerY?: Length</p>
<p>}</p>
</td>
<td class="cellrowborder" valign="top" width="28.449999999999996%" headers="mcps1.1.5.1.3 "><p>{</p>
<p>x: 0,</p>
<p>y: 0,</p>
<p>z: 0,</p>
<p>angle: 0,</p>
<p>centerX: '50%',</p>
<p>centerY: '50%'</p>
<p>}</p>
</td>
<td class="cellrowborder" valign="top" width="25.4%" headers="mcps1.1.5.1.4 "><p>(x, y, z)指定一个矢量，表示旋转轴，正角度为顺时针转动，负角度为逆时针转动，默认值为0，同时可以通过centerX和centerY设置旋转的中心点。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="13.87%" headers="mcps1.1.5.1.1 "><p>translate</p>
</td>
<td class="cellrowborder" valign="top" width="32.28%" headers="mcps1.1.5.1.2 "><p>{</p>
<p>x?: Length,</p>
<p>y?: Length,</p>
<p>z? : Length</p>
<p>}</p>
</td>
<td class="cellrowborder" valign="top" width="28.449999999999996%" headers="mcps1.1.5.1.3 "><p>{</p>
<p>x: 0,</p>
<p>y: 0,</p>
<p>z: 0</p>
<p>}</p>
</td>
<td class="cellrowborder" valign="top" width="25.4%" headers="mcps1.1.5.1.4 "><p>可以分别设置X轴、Y轴、Z轴的平移距离，距离的正负控制平移的方向，默认值为0。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="13.87%" headers="mcps1.1.5.1.1 "><p>scale</p>
</td>
<td class="cellrowborder" valign="top" width="32.28%" headers="mcps1.1.5.1.2 "><p>{</p>
<p>x?: number,</p>
<p>y?: number,</p>
<p>z?: number,</p>
<p>centerX?: Length,</p>
<p>centerY?: Length</p>
<p>}</p>
</td>
<td class="cellrowborder" valign="top" width="28.449999999999996%" headers="mcps1.1.5.1.3 "><p>{</p>
<p>x: 1,</p>
<p>y: 1,</p>
<p>z: 1,</p>
<p>centerX:'50%',</p>
<p>centerY:'50%'</p>
<p>}</p>
</td>
<td class="cellrowborder" valign="top" width="25.4%" headers="mcps1.1.5.1.4 "><p>可以分别设置X轴、Y轴、Z轴的缩放比例，默认值为1，同时可以通过centerX和centerY设置缩放的中心点。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="13.87%" headers="mcps1.1.5.1.1 "><p>transform</p>
</td>
<td class="cellrowborder" valign="top" width="32.28%" headers="mcps1.1.5.1.2 "><p>matrix: Matrix4</p>
</td>
<td class="cellrowborder" valign="top" width="28.449999999999996%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="25.4%" headers="mcps1.1.5.1.4 "><p>设置当前组件的变换矩阵。</p>
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

