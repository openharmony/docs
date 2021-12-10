# Flex布局<a name="ZH-CN_TOPIC_0000001160986263"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>-   仅当父组件是Flex组件时生效。

<a name="table444mcpsimp"></a>
<table><thead align="left"><tr id="row451mcpsimp"><th class="cellrowborder" valign="top" width="16%" id="mcps1.1.5.1.1"><p id="p453mcpsimp"><a name="p453mcpsimp"></a><a name="p453mcpsimp"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="16.66%" id="mcps1.1.5.1.2"><p id="p455mcpsimp"><a name="p455mcpsimp"></a><a name="p455mcpsimp"></a>参数说明</p>
</th>
<th class="cellrowborder" valign="top" width="13.459999999999999%" id="mcps1.1.5.1.3"><p id="p457mcpsimp"><a name="p457mcpsimp"></a><a name="p457mcpsimp"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="53.879999999999995%" id="mcps1.1.5.1.4"><p id="p459mcpsimp"><a name="p459mcpsimp"></a><a name="p459mcpsimp"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row460mcpsimp"><td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.1 "><p id="p462mcpsimp"><a name="p462mcpsimp"></a><a name="p462mcpsimp"></a>flexBasis</p>
</td>
<td class="cellrowborder" valign="top" width="16.66%" headers="mcps1.1.5.1.2 "><p id="p464mcpsimp"><a name="p464mcpsimp"></a><a name="p464mcpsimp"></a>'auto' | Length</p>
</td>
<td class="cellrowborder" valign="top" width="13.459999999999999%" headers="mcps1.1.5.1.3 "><p id="p469mcpsimp"><a name="p469mcpsimp"></a><a name="p469mcpsimp"></a>'auto'</p>
</td>
<td class="cellrowborder" valign="top" width="53.879999999999995%" headers="mcps1.1.5.1.4 "><p id="p471mcpsimp"><a name="p471mcpsimp"></a><a name="p471mcpsimp"></a>此属性所在的组件在Flex容器中主轴方向上基准尺寸。</p>
</td>
</tr>
<tr id="row472mcpsimp"><td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.1 "><p id="p474mcpsimp"><a name="p474mcpsimp"></a><a name="p474mcpsimp"></a>flexGrow</p>
</td>
<td class="cellrowborder" valign="top" width="16.66%" headers="mcps1.1.5.1.2 "><p id="p476mcpsimp"><a name="p476mcpsimp"></a><a name="p476mcpsimp"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="13.459999999999999%" headers="mcps1.1.5.1.3 "><p id="p478mcpsimp"><a name="p478mcpsimp"></a><a name="p478mcpsimp"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="53.879999999999995%" headers="mcps1.1.5.1.4 "><p id="p480mcpsimp"><a name="p480mcpsimp"></a><a name="p480mcpsimp"></a>Flex容器的剩余空间分配给给此属性所在的组件的比例。</p>
</td>
</tr>
<tr id="row481mcpsimp"><td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.1 "><p id="p483mcpsimp"><a name="p483mcpsimp"></a><a name="p483mcpsimp"></a>flexShrink</p>
</td>
<td class="cellrowborder" valign="top" width="16.66%" headers="mcps1.1.5.1.2 "><p id="p485mcpsimp"><a name="p485mcpsimp"></a><a name="p485mcpsimp"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="13.459999999999999%" headers="mcps1.1.5.1.3 "><p id="p487mcpsimp"><a name="p487mcpsimp"></a><a name="p487mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="53.879999999999995%" headers="mcps1.1.5.1.4 "><p id="p489mcpsimp"><a name="p489mcpsimp"></a><a name="p489mcpsimp"></a>Flex容器压缩尺寸分配给此属性所在的组件的比例。</p>
</td>
</tr>
<tr id="row499mcpsimp"><td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.1 "><p id="p501mcpsimp"><a name="p501mcpsimp"></a><a name="p501mcpsimp"></a>alignSelf</p>
</td>
<td class="cellrowborder" valign="top" width="16.66%" headers="mcps1.1.5.1.2 "><p id="p503mcpsimp"><a name="p503mcpsimp"></a><a name="p503mcpsimp"></a><a href="ts-appendix-enums.md#section14211428171612">ItemAlign</a></p>
</td>
<td class="cellrowborder" valign="top" width="13.459999999999999%" headers="mcps1.1.5.1.3 "><p id="p505mcpsimp"><a name="p505mcpsimp"></a><a name="p505mcpsimp"></a>Auto</p>
</td>
<td class="cellrowborder" valign="top" width="53.879999999999995%" headers="mcps1.1.5.1.4 "><p id="p507mcpsimp"><a name="p507mcpsimp"></a><a name="p507mcpsimp"></a>覆盖Flex布局容器中alignItems默认配置。</p>
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

