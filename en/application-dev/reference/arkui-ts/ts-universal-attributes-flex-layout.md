# Flex Layout<a name="EN-US_TOPIC_0000001192755122"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>-   This attribute is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.
>-   This attribute is valid only when the parent component is a  **Flex**  component.

## Required Permissions<a name="section781125411508"></a>

None

## Attributes<a name="section414916171752"></a>

<a name="table444mcpsimp"></a>
<table><thead align="left"><tr id="row451mcpsimp"><th class="cellrowborder" valign="top" width="16%" id="mcps1.1.5.1.1"><p id="p453mcpsimp"><a name="p453mcpsimp"></a><a name="p453mcpsimp"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="16.66%" id="mcps1.1.5.1.2"><p id="p455mcpsimp"><a name="p455mcpsimp"></a><a name="p455mcpsimp"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="13.459999999999999%" id="mcps1.1.5.1.3"><p id="p457mcpsimp"><a name="p457mcpsimp"></a><a name="p457mcpsimp"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="53.879999999999995%" id="mcps1.1.5.1.4"><p id="p459mcpsimp"><a name="p459mcpsimp"></a><a name="p459mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row460mcpsimp"><td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.1 "><p id="p462mcpsimp"><a name="p462mcpsimp"></a><a name="p462mcpsimp"></a>flexBasis</p>
</td>
<td class="cellrowborder" valign="top" width="16.66%" headers="mcps1.1.5.1.2 "><p id="p464mcpsimp"><a name="p464mcpsimp"></a><a name="p464mcpsimp"></a>'auto' | Length</p>
</td>
<td class="cellrowborder" valign="top" width="13.459999999999999%" headers="mcps1.1.5.1.3 "><p id="p469mcpsimp"><a name="p469mcpsimp"></a><a name="p469mcpsimp"></a>'auto'</p>
</td>
<td class="cellrowborder" valign="top" width="53.879999999999995%" headers="mcps1.1.5.1.4 "><p id="p471mcpsimp"><a name="p471mcpsimp"></a><a name="p471mcpsimp"></a>Base dimension of a component in the main axis of the <strong id="b1686121761316"><a name="b1686121761316"></a><a name="b1686121761316"></a>Flex</strong> layout.</p>
</td>
</tr>
<tr id="row472mcpsimp"><td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.1 "><p id="p474mcpsimp"><a name="p474mcpsimp"></a><a name="p474mcpsimp"></a>flexGrow</p>
</td>
<td class="cellrowborder" valign="top" width="16.66%" headers="mcps1.1.5.1.2 "><p id="p476mcpsimp"><a name="p476mcpsimp"></a><a name="p476mcpsimp"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="13.459999999999999%" headers="mcps1.1.5.1.3 "><p id="p478mcpsimp"><a name="p478mcpsimp"></a><a name="p478mcpsimp"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="53.879999999999995%" headers="mcps1.1.5.1.4 "><p id="p480mcpsimp"><a name="p480mcpsimp"></a><a name="p480mcpsimp"></a>Percentage of the <strong id="b0358174519133"><a name="b0358174519133"></a><a name="b0358174519133"></a>Flex</strong> layout's remaining space that is allocated to the component.</p>
</td>
</tr>
<tr id="row481mcpsimp"><td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.1 "><p id="p483mcpsimp"><a name="p483mcpsimp"></a><a name="p483mcpsimp"></a>flexShrink</p>
</td>
<td class="cellrowborder" valign="top" width="16.66%" headers="mcps1.1.5.1.2 "><p id="p485mcpsimp"><a name="p485mcpsimp"></a><a name="p485mcpsimp"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="13.459999999999999%" headers="mcps1.1.5.1.3 "><p id="p487mcpsimp"><a name="p487mcpsimp"></a><a name="p487mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="53.879999999999995%" headers="mcps1.1.5.1.4 "><p id="p489mcpsimp"><a name="p489mcpsimp"></a><a name="p489mcpsimp"></a>Percentage of the <strong id="b14896356151316"><a name="b14896356151316"></a><a name="b14896356151316"></a>Flex</strong> layout's shrink size that is allocated to the component.</p>
</td>
</tr>
<tr id="row499mcpsimp"><td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.1 "><p id="p501mcpsimp"><a name="p501mcpsimp"></a><a name="p501mcpsimp"></a>alignSelf</p>
</td>
<td class="cellrowborder" valign="top" width="16.66%" headers="mcps1.1.5.1.2 "><p id="p503mcpsimp"><a name="p503mcpsimp"></a><a name="p503mcpsimp"></a><a href="ts-appendix-enums.md#section14211428171612">ItemAlign</a></p>
</td>
<td class="cellrowborder" valign="top" width="13.459999999999999%" headers="mcps1.1.5.1.3 "><p id="p505mcpsimp"><a name="p505mcpsimp"></a><a name="p505mcpsimp"></a>Auto</p>
</td>
<td class="cellrowborder" valign="top" width="53.879999999999995%" headers="mcps1.1.5.1.4 "><p id="p507mcpsimp"><a name="p507mcpsimp"></a><a name="p507mcpsimp"></a>Alighment mode, which overwrites the default <strong id="b20794168174419"><a name="b20794168174419"></a><a name="b20794168174419"></a>alignItems</strong> configuration in the <strong id="b194962528154"><a name="b194962528154"></a><a name="b194962528154"></a>Flex</strong> layout.</p>
</td>
</tr>
</tbody>
</table>

## Example<a name="section1976245813394"></a>

```
@Entry
@Component
struct FlexExample {
  build() {
    Column({ space: 5 }) {
      Text('flexBasis').fontSize(9).fontColor(0xCCCCCC).width('90%')
      // Base dimension in the main axis
      // flexBasis() can be auto (default value), which indicates the original component size. If the value is of the number type, it is similar to .width()/.height(). The value is based on the main axis.
      Flex() {
        Text('flexBasis(100)')
          .flexBasis('100').height(100).lineHeight(70)
          .backgroundColor(0xF5DEB3).textAlign(TextAlign.Center)
        Text('flexBasis("auto")')
          .flexBasis('auto').width('60%').height(100).lineHeight(70)
          .backgroundColor(0xD2B48C).textAlign(TextAlign.Center)
      }.width('90%').height(120).padding(10).backgroundColor(0xAFEEEE)

      Text('flexGrow').fontSize(9).fontColor(0xCCCCCC).width('90%')
      // Percentage of the remaining space
      // flexGrow() specifies the percentage of the remaining space allocated to the component.
      Flex() {
        Text('flexGrow(2)')
          .flexGrow(2).height(100).lineHeight(70)
          .backgroundColor(0xF5DEB3).textAlign(TextAlign.Center)
        Text('flexGrow(1)')
          .flexGrow(1).height(100).lineHeight(70)
          .backgroundColor(0xD2B48C).textAlign(TextAlign.Center)
      }.width('90%').height(120).padding(10).backgroundColor(0xAFEEEE)

      Text('flexShrink').fontSize(9).fontColor(0xCCCCCC).width('90%')
      // flexShrink() specifies the percentage of the shrink size allocated to the component.
      // The ratio of text1 is 0, and the default values of other parameters are 1. If the components cannot be completely displayed, the last two components are shrunk proportionally. The first componented is not shrunk.
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
      // alignSelf() overwrites the default alignItems configuration in the Flex layout.
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

