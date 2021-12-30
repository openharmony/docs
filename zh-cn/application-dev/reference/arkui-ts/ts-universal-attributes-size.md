# 尺寸设置<a name="ZH-CN_TOPIC_0000001192915116"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 权限列表<a name="section781125411508"></a>

无

## 属性<a name="section17707164916113"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="14.49%" id="mcps1.1.5.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="29.720000000000002%" id="mcps1.1.5.1.2"><p>参数说明</p>
</th>
<th class="cellrowborder" valign="top" width="18.98%" id="mcps1.1.5.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="36.809999999999995%" id="mcps1.1.5.1.4"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="14.49%" headers="mcps1.1.5.1.1 "><p>width</p>
</td>
<td class="cellrowborder" valign="top" width="29.720000000000002%" headers="mcps1.1.5.1.2 "><p>Length</p>
</td>
<td class="cellrowborder" valign="top" width="18.98%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="36.809999999999995%" headers="mcps1.1.5.1.4 "><p>设置组件自身的宽度，缺省时使用元素自身内容需要的宽度。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="14.49%" headers="mcps1.1.5.1.1 "><p>height</p>
</td>
<td class="cellrowborder" valign="top" width="29.720000000000002%" headers="mcps1.1.5.1.2 "><p>Length</p>
</td>
<td class="cellrowborder" valign="top" width="18.98%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="36.809999999999995%" headers="mcps1.1.5.1.4 "><p>设置组件自身的高度，缺省时使用元素自身内容需要的高度。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="14.49%" headers="mcps1.1.5.1.1 "><p>size</p>
</td>
<td class="cellrowborder" valign="top" width="29.720000000000002%" headers="mcps1.1.5.1.2 "><p>{</p>
<p>width?: Length,</p>
<p>height?: Length</p>
<p>}</p>
</td>
<td class="cellrowborder" valign="top" width="18.98%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="36.809999999999995%" headers="mcps1.1.5.1.4 "><p>设置高宽尺寸。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="14.49%" headers="mcps1.1.5.1.1 "><p>padding</p>
</td>
<td class="cellrowborder" valign="top" width="29.720000000000002%" headers="mcps1.1.5.1.2 "><p>{</p>
<p>top?: Length,</p>
<p>right?: Length,</p>
<p>bottom?: Length,</p>
<p>left?: Length</p>
<p>} | Length</p>
</td>
<td class="cellrowborder" valign="top" width="18.98%" headers="mcps1.1.5.1.3 "><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="36.809999999999995%" headers="mcps1.1.5.1.4 "><p>设置内边距属性。</p>
<p>参数为Length类型时，四个方向内边距同时生效。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="14.49%" headers="mcps1.1.5.1.1 "><p>margin</p>
</td>
<td class="cellrowborder" valign="top" width="29.720000000000002%" headers="mcps1.1.5.1.2 "><p>{</p>
<p>top?: Length,</p>
<p>right?: Length,</p>
<p>bottom?: Length,</p>
<p>left?: Length</p>
<p>}</p>
<p>| Length</p>
</td>
<td class="cellrowborder" valign="top" width="18.98%" headers="mcps1.1.5.1.3 "><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="36.809999999999995%" headers="mcps1.1.5.1.4 "><p>设置外边距属性。</p>
<p>参数为Length类型时，四个方向外边距同时生效。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="14.49%" headers="mcps1.1.5.1.1 "><p>constraintSize</p>
</td>
<td class="cellrowborder" valign="top" width="29.720000000000002%" headers="mcps1.1.5.1.2 "><p>{</p>
<p>minWidth?: Length,</p>
<p>maxWidth?: Length,</p>
<p>minHeight?: Length,</p>
<p>maxHeight?: Lenght</p>
<p>}</p>
</td>
<td class="cellrowborder" valign="top" width="18.98%" headers="mcps1.1.5.1.3 "><p>{</p>
<p>minWidth: 0,</p>
<p>maxWidth: Infinity,</p>
<p>minHeight: 0,</p>
<p>maxHeight: Infinity</p>
<p>}</p>
</td>
<td class="cellrowborder" valign="top" width="36.809999999999995%" headers="mcps1.1.5.1.4 "><p>设置约束尺寸，组件布局时，进行尺寸范围限制。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="14.49%" headers="mcps1.1.5.1.1 "><p>layoutWeight</p>
</td>
<td class="cellrowborder" valign="top" width="29.720000000000002%" headers="mcps1.1.5.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="18.98%" headers="mcps1.1.5.1.3 "><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="36.809999999999995%" headers="mcps1.1.5.1.4 "><p>容器尺寸确定时，元素与兄弟节点主轴布局尺寸按照权重进行分配，忽略本身尺寸设置。</p>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>仅在Row/Column/Flex布局中生效。</p>
</div></div>
</td>
</tr>
</tbody>
</table>

## 示例<a name="section19690013134020"></a>

```
@Entry
@Component
struct SizeExample {
  build() {
    Column({ space: 10 }) {
      Text('margin and padding:').fontSize(12).fontColor(0xCCCCCC).width('90%')
      // 宽度80 ,高度80 ,内外边距20
      Row() {
        Row() {
          Row().size({ width: '100%', height: '100%' }).backgroundColor(0xAFEEEE)
        }.width(80).height(80).padding(20).margin(20).backgroundColor(0xFDF5E6)
      }.backgroundColor(0xFFA500)

      Text('layoutWeight').fontSize(12).fontColor(0xCCCCCC).width('90%')
      // 容器尺寸确定时，元素与兄弟节点主轴布局尺寸按照权重进行分配，忽略本身尺寸设置。
      Row() {
        // 权重1
        Text('layoutWeight(1)')
          .size({ width: '30%', height: 110 }).backgroundColor(0xFFEFD5).textAlign(TextAlign.Center)
          .layoutWeight(1)
        // 权重0
        Text('layoutWeight(2)')
          .size({ width: '30%', height: 110 }).backgroundColor(0xF5DEB3).textAlign(TextAlign.Center)
          .layoutWeight(2)
        // 权重默认0
        Text('no layoutWeight')
          .size({ width: '30%', height: 110 }).backgroundColor(0xD2B48C).textAlign(TextAlign.Center)
      }.size({ width: '90%', height: 140 }).backgroundColor(0xAFEEEE)
    }.width('100%').margin({ top: 5 })
  }
}
```

![](figures/size.gif)

