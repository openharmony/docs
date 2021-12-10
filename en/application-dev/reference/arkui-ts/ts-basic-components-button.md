# Button<a name="EN-US_TOPIC_0000001158141265"></a>

Provides the button component.

## Required Permissions<a name="section173151571452"></a>

None

## Child Component<a name="section13412913174619"></a>

This component can contain child components.

## APIs<a name="section124082310463"></a>

-   Button\(options?: \{type?: ButtonType, stateEffect?: boolean\}\)

    **Table  1** **options**  parameters

    <a name="table712610266288"></a>
    <table><thead align="left"><tr id="row14126132602813"><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.2.6.1.1"><p id="p12126162672817"><a name="p12126162672817"></a><a name="p12126162672817"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="15.47%" id="mcps1.2.6.1.2"><p id="p612662615285"><a name="p612662615285"></a><a name="p612662615285"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.03%" id="mcps1.2.6.1.3"><p id="p171261526112810"><a name="p171261526112810"></a><a name="p171261526112810"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.18%" id="mcps1.2.6.1.4"><p id="p16126122652819"><a name="p16126122652819"></a><a name="p16126122652819"></a>Default Value</p>
    </th>
    <th class="cellrowborder" valign="top" width="42.21%" id="mcps1.2.6.1.5"><p id="p1612622618286"><a name="p1612622618286"></a><a name="p1612622618286"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1512619268285"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.2.6.1.1 "><p id="p912612612814"><a name="p912612612814"></a><a name="p912612612814"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.47%" headers="mcps1.2.6.1.2 "><p id="p5126926132817"><a name="p5126926132817"></a><a name="p5126926132817"></a>ButtonType</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.03%" headers="mcps1.2.6.1.3 "><p id="p91262026102811"><a name="p91262026102811"></a><a name="p91262026102811"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.18%" headers="mcps1.2.6.1.4 "><p id="p912616260283"><a name="p912616260283"></a><a name="p912616260283"></a>Capsule</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.21%" headers="mcps1.2.6.1.5 "><p id="p5126192617281"><a name="p5126192617281"></a><a name="p5126192617281"></a>Button type.</p>
    </td>
    </tr>
    <tr id="row1412632622819"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.2.6.1.1 "><p id="p0126202632815"><a name="p0126202632815"></a><a name="p0126202632815"></a>stateEffect</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.47%" headers="mcps1.2.6.1.2 "><p id="p11126142615280"><a name="p11126142615280"></a><a name="p11126142615280"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.03%" headers="mcps1.2.6.1.3 "><p id="p5126326122820"><a name="p5126326122820"></a><a name="p5126326122820"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.18%" headers="mcps1.2.6.1.4 "><p id="p71264261281"><a name="p71264261281"></a><a name="p71264261281"></a>true</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.21%" headers="mcps1.2.6.1.5 "><p id="p5126162618289"><a name="p5126162618289"></a><a name="p5126162618289"></a>Whether to enable the state switchover effect when a button is pressed. When the state is set to <strong id="b18920321715"><a name="b18920321715"></a><a name="b18920321715"></a>false</strong>, the state switchover effect is disabled.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Button\(label?: string, options?: \{ type?: ButtonType, stateEffect?: boolean \}\)

    Creates a button component based on text content. In this case, the  **<Button\>**  component cannot contain subcomponents.

    **Table  2** **value**  parameters

    <a name="table244753515284"></a>
    <table><thead align="left"><tr id="row3447113522811"><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.2.6.1.1"><p id="p1144753517284"><a name="p1144753517284"></a><a name="p1144753517284"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.01%" id="mcps1.2.6.1.2"><p id="p54471535192817"><a name="p54471535192817"></a><a name="p54471535192817"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.49%" id="mcps1.2.6.1.3"><p id="p4447173516281"><a name="p4447173516281"></a><a name="p4447173516281"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.18%" id="mcps1.2.6.1.4"><p id="p18447835162816"><a name="p18447835162816"></a><a name="p18447835162816"></a>Default Value</p>
    </th>
    <th class="cellrowborder" valign="top" width="42.21%" id="mcps1.2.6.1.5"><p id="p744723519280"><a name="p744723519280"></a><a name="p744723519280"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row134475355286"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.2.6.1.1 "><p id="p104487359288"><a name="p104487359288"></a><a name="p104487359288"></a>label</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.01%" headers="mcps1.2.6.1.2 "><p id="p94480357284"><a name="p94480357284"></a><a name="p94480357284"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.49%" headers="mcps1.2.6.1.3 "><p id="p10448935142819"><a name="p10448935142819"></a><a name="p10448935142819"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.18%" headers="mcps1.2.6.1.4 "><p id="p15448123542819"><a name="p15448123542819"></a><a name="p15448123542819"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.21%" headers="mcps1.2.6.1.5 "><p id="p10448835182820"><a name="p10448835182820"></a><a name="p10448835182820"></a>Button text.</p>
    </td>
    </tr>
    <tr id="row18448133582812"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.2.6.1.1 "><p id="p044823519281"><a name="p044823519281"></a><a name="p044823519281"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.01%" headers="mcps1.2.6.1.2 "><p id="p044873511289"><a name="p044873511289"></a><a name="p044873511289"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.49%" headers="mcps1.2.6.1.3 "><p id="p4448153510281"><a name="p4448153510281"></a><a name="p4448153510281"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.18%" headers="mcps1.2.6.1.4 "><p id="p1444820359284"><a name="p1444820359284"></a><a name="p1444820359284"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.21%" headers="mcps1.2.6.1.5 "><p id="p16448163513282"><a name="p16448163513282"></a><a name="p16448163513282"></a>For details, see the <a href="#table712610266288">options parameters</a>.</p>
    </td>
    </tr>
    </tbody>
    </table>


## Attributes<a name="section94181084473"></a>

<a name="table1088mcpsimp"></a>
<table><thead align="left"><tr id="row1095mcpsimp"><th class="cellrowborder" valign="top" width="13.389999999999999%" id="mcps1.1.5.1.1"><p id="p1097mcpsimp"><a name="p1097mcpsimp"></a><a name="p1097mcpsimp"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="14.430000000000001%" id="mcps1.1.5.1.2"><p id="p1099mcpsimp"><a name="p1099mcpsimp"></a><a name="p1099mcpsimp"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="11.87%" id="mcps1.1.5.1.3"><p id="p1101mcpsimp"><a name="p1101mcpsimp"></a><a name="p1101mcpsimp"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="60.309999999999995%" id="mcps1.1.5.1.4"><p id="p1103mcpsimp"><a name="p1103mcpsimp"></a><a name="p1103mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1104mcpsimp"><td class="cellrowborder" valign="top" width="13.389999999999999%" headers="mcps1.1.5.1.1 "><p id="p1106mcpsimp"><a name="p1106mcpsimp"></a><a name="p1106mcpsimp"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="14.430000000000001%" headers="mcps1.1.5.1.2 "><p id="p1108mcpsimp"><a name="p1108mcpsimp"></a><a name="p1108mcpsimp"></a><a href="#li93236107910">ButtonType</a></p>
</td>
<td class="cellrowborder" valign="top" width="11.87%" headers="mcps1.1.5.1.3 "><p id="p1110mcpsimp"><a name="p1110mcpsimp"></a><a name="p1110mcpsimp"></a>Capsule</p>
</td>
<td class="cellrowborder" valign="top" width="60.309999999999995%" headers="mcps1.1.5.1.4 "><p id="p1112mcpsimp"><a name="p1112mcpsimp"></a><a name="p1112mcpsimp"></a>Button type.</p>
</td>
</tr>
<tr id="row1561916101034"><td class="cellrowborder" valign="top" width="13.389999999999999%" headers="mcps1.1.5.1.1 "><p id="p1161918103312"><a name="p1161918103312"></a><a name="p1161918103312"></a>stateEffect</p>
</td>
<td class="cellrowborder" valign="top" width="14.430000000000001%" headers="mcps1.1.5.1.2 "><p id="p961941017310"><a name="p961941017310"></a><a name="p961941017310"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="11.87%" headers="mcps1.1.5.1.3 "><p id="p2619610432"><a name="p2619610432"></a><a name="p2619610432"></a>true</p>
</td>
<td class="cellrowborder" valign="top" width="60.309999999999995%" headers="mcps1.1.5.1.4 "><p id="p186192101435"><a name="p186192101435"></a><a name="p186192101435"></a>Whether to enable the state switchover effect. When the state is set to <strong id="b1327661382120"><a name="b1327661382120"></a><a name="b1327661382120"></a>false</strong>, the state switchover effect is disabled.</p>
</td>
</tr>
</tbody>
</table>

-   <a name="li93236107910"></a>ButtonType enums

    <a name="table18600037183510"></a>
    <table><thead align="left"><tr id="row196013379350"><th class="cellrowborder" valign="top" width="25.3%" id="mcps1.1.3.1.1"><p id="p2601837143511"><a name="p2601837143511"></a><a name="p2601837143511"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.7%" id="mcps1.1.3.1.2"><p id="p16601203719358"><a name="p16601203719358"></a><a name="p16601203719358"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row176011137123513"><td class="cellrowborder" valign="top" width="25.3%" headers="mcps1.1.3.1.1 "><p id="p1760153713511"><a name="p1760153713511"></a><a name="p1760153713511"></a>Capsule</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.7%" headers="mcps1.1.3.1.2 "><p id="p1601133783516"><a name="p1601133783516"></a><a name="p1601133783516"></a>Capsule-type button (the round corner is half of the height by default).</p>
    </td>
    </tr>
    <tr id="row5601133715357"><td class="cellrowborder" valign="top" width="25.3%" headers="mcps1.1.3.1.1 "><p id="p156011037133513"><a name="p156011037133513"></a><a name="p156011037133513"></a>Circle</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.7%" headers="mcps1.1.3.1.2 "><p id="p1360123717359"><a name="p1360123717359"></a><a name="p1360123717359"></a>Circle button.</p>
    </td>
    </tr>
    <tr id="row8601103713511"><td class="cellrowborder" valign="top" width="25.3%" headers="mcps1.1.3.1.1 "><p id="p1360133716358"><a name="p1360133716358"></a><a name="p1360133716358"></a>Normal</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.7%" headers="mcps1.1.3.1.2 "><p id="p5601837143516"><a name="p5601837143516"></a><a name="p5601837143516"></a>Normal button (without rounded corners by default).</p>
    </td>
    </tr>
    </tbody>
    </table>


>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>-   The rounded corner of a button is set by using  [**borderRadius**](ts-universal-attributes-border.md). \(The rounded corner cannot be set by using a border API.\)
>-   The button text is set using the  [common text style](ts-universal-attributes-text-style.md).

## Example<a name="section449999124812"></a>

```
@Entry
@Component
struct ButtonExample {
  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Start, justifyContent: FlexAlign.SpaceBetween }) {
      Text('Common button').fontSize(9).fontColor(0xCCCCCC)
      Flex({ alignItems: ItemAlign.Center, justifyContent: FlexAlign.SpaceBetween }) {
        Button('Ok', { type: ButtonType.Normal, stateEffect: true }).borderRadius(8).backgroundColor(0x317aff).width(90)
        Button({ type: ButtonType.Normal, stateEffect: true }) {
          Row() {
            Image($r('app.media.loading')).width(20).height(20).margin({ left: 12 })
            Text('loading').fontSize(12).fontColor(0xffffff).margin({ left: 5, right: 12 })
          }.alignItems(VerticalAlign.Center)
        }.borderRadius(8).backgroundColor(0x317aff).width(90)
        Button('Disable', { type: ButtonType.Normal, stateEffect: false }).opacity(0.5)
          .borderRadius(8).backgroundColor(0x317aff).width(90)
      }

      Text('Capsule button').fontSize(9).fontColor(0xCCCCCC)
      Flex({ alignItems: ItemAlign.Center, justifyContent: FlexAlign.SpaceBetween }) {
        Button('Ok', { type: ButtonType.Capsule, stateEffect: true }).backgroundColor(0x317aff).width(90)
        Button({ type: ButtonType.Capsule, stateEffect: true }) {
          Row() {
            Image($r('app.media.loading')).width(20).height(20).margin({ left: 12 })
            Text('loading').fontSize(12).fontColor(0xffffff).margin({ left: 5, right: 12 })
          }.alignItems(VerticalAlign.Center).width(90)
        }.backgroundColor(0x317aff)
        .onClick((event: ClickEvent) => {
          AlertDialog.show({ message: 'The login is successful' })
        })
        Button('Disable', { type: ButtonType.Capsule, stateEffect: false }).opacity(0.5)
          .backgroundColor(0x317aff).width(90)
      }

      Text('Circle button').fontSize(9).fontColor(0xCCCCCC)
      Flex({ alignItems: ItemAlign.Center, wrap: FlexWrap.Wrap }) {
        Button({ type: ButtonType.Circle, stateEffect: true }) {
          Image($r('app.media.ic_public_app_filled')).width(20).height(20)
        }.width(55).height(55).backgroundColor(0x317aff)
        Button({ type: ButtonType.Circle, stateEffect: true }) {
          Image($r('app.media.ic_public_delete_filled')).width(30).height(30)
        }.width(55).height(55).margin({ left: 20 }).backgroundColor(0xF55A42)
      }
    }.height(400).padding({ left: 35, right: 35, top: 35 })
  }
}
```

![](figures/button.gif)

