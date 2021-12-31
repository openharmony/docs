# Flex布局<a name="ZH-CN_TOPIC_0000001192755122"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>-   从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>-   仅当父组件是Flex组件时生效。

## 权限列表<a name="section781125411508"></a>

无

## 属性<a name="section414916171752"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="16%" id="mcps1.1.5.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="16.66%" id="mcps1.1.5.1.2"><p>参数说明</p>
</th>
<th class="cellrowborder" valign="top" width="13.459999999999999%" id="mcps1.1.5.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="53.879999999999995%" id="mcps1.1.5.1.4"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.1 "><p>flexBasis</p>
</td>
<td class="cellrowborder" valign="top" width="16.66%" headers="mcps1.1.5.1.2 "><p>'auto' | Length</p>
</td>
<td class="cellrowborder" valign="top" width="13.459999999999999%" headers="mcps1.1.5.1.3 "><p>'auto'</p>
</td>
<td class="cellrowborder" valign="top" width="53.879999999999995%" headers="mcps1.1.5.1.4 "><p>此属性所在的组件在Flex容器中主轴方向上基准尺寸。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.1 "><p>flexGrow</p>
</td>
<td class="cellrowborder" valign="top" width="16.66%" headers="mcps1.1.5.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="13.459999999999999%" headers="mcps1.1.5.1.3 "><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="53.879999999999995%" headers="mcps1.1.5.1.4 "><p>Flex容器的剩余空间分配给给此属性所在的组件的比例。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.1 "><p>flexShrink</p>
</td>
<td class="cellrowborder" valign="top" width="16.66%" headers="mcps1.1.5.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="13.459999999999999%" headers="mcps1.1.5.1.3 "><p>1</p>
</td>
<td class="cellrowborder" valign="top" width="53.879999999999995%" headers="mcps1.1.5.1.4 "><p>Flex容器压缩尺寸分配给此属性所在的组件的比例。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.1 "><p>alignSelf</p>
</td>
<td class="cellrowborder" valign="top" width="16.66%" headers="mcps1.1.5.1.2 "><p><a href="ts-appendix-enums.md#section14211428171612">ItemAlign</a></p>
</td>
<td class="cellrowborder" valign="top" width="13.459999999999999%" headers="mcps1.1.5.1.3 "><p>Auto</p>
</td>
<td class="cellrowborder" valign="top" width="53.879999999999995%" headers="mcps1.1.5.1.4 "><p>覆盖Flex布局容器中alignItems默认配置。</p>
</td>
</tr>
</tbody>
</table>

## 示例<a name="section1976245813394"></a>

```
@Entry
@Component
struct FlexExample {
  build() {
    Column({ space: 5 }) {
      Text('flexBasis').fontSize(9).fontColor(0xCCCCCC).width('90%')
      // 基于主轴基准尺寸
      // flexBasis()值可以是'auto'(默认值)元素本来的大小 ,如果是数字则类似于.width()/.height() ,基于主轴
      Flex() {
        Text('flexBasis(100)')
          .flexBasis('100').height(100).lineHeight(70)
          .backgroundColor(0xF5DEB3).textAlign(TextAlign.Center)
        Text('flexBasis("auto")')
          .flexBasis('auto').width('60%').height(100).lineHeight(70)
          .backgroundColor(0xD2B48C).textAlign(TextAlign.Center)
      }.width('90%').height(120).padding(10).backgroundColor(0xAFEEEE)

      Text('flexGrow').fontSize(9).fontColor(0xCCCCCC).width('90%')
      // 剩余空间所占比例
      // flexGrow()剩余空间分配给该元素的比例
      Flex() {
        Text('flexGrow(2)')
          .flexGrow(2).height(100).lineHeight(70)
          .backgroundColor(0xF5DEB3).textAlign(TextAlign.Center)
        Text('flexGrow(1)')
          .flexGrow(1).height(100).lineHeight(70)
          .backgroundColor(0xD2B48C).textAlign(TextAlign.Center)
      }.width('90%').height(120).padding(10).backgroundColor(0xAFEEEE)

      Text('flexShrink').fontSize(9).fontColor(0xCCCCCC).width('90%')
      // flexShrink()此属性所在的组件的比例
      // text1比例是0,其他都是默认值1,放不下时直接等比例缩放后两个,第一个不缩放
      Flex({ direction: FlexDirection.Row }) {
        Text('flexShrink(0)')
          .flexShrink(0).width('50%').height(100).lineHeight(70)
          .backgroundColor(0xF5DEB3).textAlign(TextAlign.Center)
        Text('no flexShrink')
          .width('40%').height(100).lineHeight(70).backgroundColor(0xD2B48C).textAlign(TextAlign.Center)
        Text('flexShrink(2)')
          .flexShrink(2).width('40%').height(100) .lineHeight(70)
          .backgroundColor(0xF5DEB3).textAlign(TextAlign.Center)
      }.width('90%').height(120).padding(10).backgroundColor(0xAFEEEE)

      Text('alignSelf').fontSize(9).fontColor(0xCCCCCC).width('90%')
      // alignSelf()覆盖Flex布局容器中alignItems默认配置
      Flex({ direction: FlexDirection.Row, alignItems: ItemAlign.Center }) {
        Text('no alignSelf,height:80').width('33%').height(80)
          .backgroundColor(0xF5DEB3).textAlign(TextAlign.Center)
        Text('alignSelf stretch')
          .alignSelf(ItemAlign.Stretch).width('33%').height(80).lineHeight(70)
          .backgroundColor(0xD2B48C).textAlign(TextAlign.Center)
        Text('no alignSelf,height:100').width('34%').height(100)
          .backgroundColor(0xF5DEB3).textAlign(TextAlign.Center)
      }.width('90%').height(120).padding(10).backgroundColor(0xAFEEEE)
    }.width('100%').margin({ top: 5 })
  }
}
```

![](figures/flex.png)

