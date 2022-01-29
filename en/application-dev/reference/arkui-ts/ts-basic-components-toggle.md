# Toggle<a name="EN-US_TOPIC_0000001193075090"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.

## Required Permissions<a name="section1562254617330"></a>

None

## Child Components<a name="section53281531154915"></a>

None

## APIs<a name="section1383178131719"></a>

Toggle\(options: \{ type: ToggleType, isOn?: boolean \}\)

-   Parameters

    <a name="table15965125931318"></a>
    <table><thead align="left"><tr id="row396518599132"><th class="cellrowborder" valign="top" width="16.110000000000003%" id="mcps1.1.6.1.1"><p id="p896516598135"><a name="p896516598135"></a><a name="p896516598135"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="15.770000000000003%" id="mcps1.1.6.1.2"><p id="p896535917137"><a name="p896535917137"></a><a name="p896535917137"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.22%" id="mcps1.1.6.1.3"><p id="p1196665918139"><a name="p1196665918139"></a><a name="p1196665918139"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.89%" id="mcps1.1.6.1.4"><p id="p696655912138"><a name="p696655912138"></a><a name="p696655912138"></a>Default Value</p>
    </th>
    <th class="cellrowborder" valign="top" width="40.010000000000005%" id="mcps1.1.6.1.5"><p id="p296685911135"><a name="p296685911135"></a><a name="p296685911135"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row8966135991317"><td class="cellrowborder" valign="top" width="16.110000000000003%" headers="mcps1.1.6.1.1 "><p id="p189664596134"><a name="p189664596134"></a><a name="p189664596134"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.770000000000003%" headers="mcps1.1.6.1.2 "><p id="p89669599135"><a name="p89669599135"></a><a name="p89669599135"></a><a href="#li544003914117">ToggleType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="11.22%" headers="mcps1.1.6.1.3 "><p id="p9966155914130"><a name="p9966155914130"></a><a name="p9966155914130"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.89%" headers="mcps1.1.6.1.4 "><p id="p12966175961319"><a name="p12966175961319"></a><a name="p12966175961319"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.010000000000005%" headers="mcps1.1.6.1.5 "><p id="p16966259141314"><a name="p16966259141314"></a><a name="p16966259141314"></a>Type of the toggle.</p>
    </td>
    </tr>
    <tr id="row189661259161317"><td class="cellrowborder" valign="top" width="16.110000000000003%" headers="mcps1.1.6.1.1 "><p id="p9966105910138"><a name="p9966105910138"></a><a name="p9966105910138"></a>isOn</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.770000000000003%" headers="mcps1.1.6.1.2 "><p id="p20966105911137"><a name="p20966105911137"></a><a name="p20966105911137"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.22%" headers="mcps1.1.6.1.3 "><p id="p8966659111317"><a name="p8966659111317"></a><a name="p8966659111317"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.89%" headers="mcps1.1.6.1.4 "><p id="p8966135913131"><a name="p8966135913131"></a><a name="p8966135913131"></a>false</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.010000000000005%" headers="mcps1.1.6.1.5 "><p id="p1196725917132"><a name="p1196725917132"></a><a name="p1196725917132"></a>Initial state of the toggle.</p>
    <div class="note" id="note163011220111"><a name="note163011220111"></a><a name="note163011220111"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p15301822191119"><a name="p15301822191119"></a><a name="p15301822191119"></a>If <strong id="b26561317548"><a name="b26561317548"></a><a name="b26561317548"></a>isOn</strong> is not set during component creation, the selected state can be retained during component reuse. If <strong id="b14208183615513"><a name="b14208183615513"></a><a name="b14208183615513"></a>isOn</strong> is set, the selected state needs to be retained during component reuse after the selected state is recorded using an event method.</p>
    </div></div>
    </td>
    </tr>
    </tbody>
    </table>


-   <a name="li544003914117"></a>ToggleType enums

    <a name="table896716596134"></a>
    <table><thead align="left"><tr id="row1796715991313"><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p id="p8967359171312"><a name="p8967359171312"></a><a name="p8967359171312"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p id="p18967115912133"><a name="p18967115912133"></a><a name="p18967115912133"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row10967165914136"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p7967125910136"><a name="p7967125910136"></a><a name="p7967125910136"></a>Checkbox</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p14967175919135"><a name="p14967175919135"></a><a name="p14967175919135"></a>A checkbox is provided. The text setting of the child component does not take effect. If the text setting is required, you can place the <strong id="b36321156155017"><a name="b36321156155017"></a><a name="b36321156155017"></a>&lt;Text&gt;</strong> component and the current component in the layout component.</p>
    </td>
    </tr>
    <tr id="row796775951312"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p6967165981311"><a name="p6967165981311"></a><a name="p6967165981311"></a>Button</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p596718591138"><a name="p596718591138"></a><a name="p596718591138"></a>A button is provided. If the text setting is available, the corresponding text content is displayed inside the button.</p>
    </td>
    </tr>
    <tr id="row1967559141319"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p9967115911139"><a name="p9967115911139"></a><a name="p9967115911139"></a>Switch</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p99671759161314"><a name="p99671759161314"></a><a name="p99671759161314"></a>A switch is provided. The text setting of the child component does not take effect. If the text setting is required, you can place the <strong id="b15836205611516"><a name="b15836205611516"></a><a name="b15836205611516"></a>&lt;Text&gt;</strong> component and the current component in the layout component.</p>
    </td>
    </tr>
    </tbody>
    </table>


## Attributes<a name="section1071518220395"></a>

<a name="table18914191724710"></a>
<table><thead align="left"><tr id="row199155176474"><th class="cellrowborder" valign="top" width="20.669999999999998%" id="mcps1.1.5.1.1"><p id="p291581754712"><a name="p291581754712"></a><a name="p291581754712"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="16.009999999999998%" id="mcps1.1.5.1.2"><p id="p4915817114714"><a name="p4915817114714"></a><a name="p4915817114714"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="13.61%" id="mcps1.1.5.1.3"><p id="p19152177470"><a name="p19152177470"></a><a name="p19152177470"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="49.71%" id="mcps1.1.5.1.4"><p id="p891514174477"><a name="p891514174477"></a><a name="p891514174477"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1591511764720"><td class="cellrowborder" valign="top" width="20.669999999999998%" headers="mcps1.1.5.1.1 "><p id="p11135191144819"><a name="p11135191144819"></a><a name="p11135191144819"></a>selectedColor</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.2 "><p id="p1391581714712"><a name="p1391581714712"></a><a name="p1391581714712"></a>Color</p>
</td>
<td class="cellrowborder" valign="top" width="13.61%" headers="mcps1.1.5.1.3 "><p id="p991581712473"><a name="p991581712473"></a><a name="p991581712473"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="49.71%" headers="mcps1.1.5.1.4 "><p id="p129151175476"><a name="p129151175476"></a><a name="p129151175476"></a>Background color of the toggle when it is enabled.</p>
</td>
</tr>
<tr id="row49151817194712"><td class="cellrowborder" valign="top" width="20.669999999999998%" headers="mcps1.1.5.1.1 "><p id="p165591275487"><a name="p165591275487"></a><a name="p165591275487"></a>switchPointColor</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.2 "><p id="p69154175478"><a name="p69154175478"></a><a name="p69154175478"></a>Color</p>
</td>
<td class="cellrowborder" valign="top" width="13.61%" headers="mcps1.1.5.1.3 "><p id="p13915017114713"><a name="p13915017114713"></a><a name="p13915017114713"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="49.71%" headers="mcps1.1.5.1.4 "><p id="p5915141719475"><a name="p5915141719475"></a><a name="p5915141719475"></a>Color of the circular slider of the <strong id="b22191229125211"><a name="b22191229125211"></a><a name="b22191229125211"></a>Switch</strong> type.</p>
<div class="note" id="note1974233484713"><a name="note1974233484713"></a><a name="note1974233484713"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p8447163864712"><a name="p8447163864712"></a><a name="p8447163864712"></a>This attribute is valid only when type is set to <strong id="b14623916161413"><a name="b14623916161413"></a><a name="b14623916161413"></a>ToggleType.Switch</strong>.</p>
</div></div>
</td>
</tr>
</tbody>
</table>

## Events<a name="section449664852016"></a>

<a name="table952mcpsimp"></a>
<table><thead align="left"><tr id="row959mcpsimp"><th class="cellrowborder" colspan="2" valign="top" id="mcps1.1.4.1.1"><p id="p963mcpsimp"><a name="p963mcpsimp"></a><a name="p963mcpsimp"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.4.1.2"><p id="p967mcpsimp"><a name="p967mcpsimp"></a><a name="p967mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row163041291058"><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p id="p63041596511"><a name="p63041596511"></a><a name="p63041596511"></a>onChange(callback: (isOn: boolean) =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p18583122017217"><a name="p18583122017217"></a><a name="p18583122017217"></a>Triggered when the switch status changes.</p>
</td>
</tr>
</tbody>
</table>

## Example<a name="section215304717201"></a>

```
@Entry
@Component
struct ToggleExample {
  build() {
    Column({ space: 10 }) {
      Text('type: Switch').fontSize(12).fontColor(0xcccccc).width('90%')
      Flex({ justifyContent: FlexAlign.SpaceEvenly, alignItems: ItemAlign.Center }) {
        Toggle({ type: ToggleType.Switch, isOn: false })
          .selectedColor(0xed6f21)
          .switchPointColor(0xe5ffffff)
          .onChange((isOn: boolean) => {
            console.info('Component status:' + isOn)
          })

        Toggle({ type: ToggleType.Switch, isOn: true })
          .selectedColor(0x39a2db)
          .switchPointColor(0xe5ffffff)
          .onChange((isOn: boolean) => {
            console.info('Component status:' + isOn)
          })
      }

      Text('type: Checkbox').fontSize(12).fontColor(0xcccccc).width('90%')
      Flex({ justifyContent: FlexAlign.SpaceEvenly, alignItems: ItemAlign.Center }) {
        Toggle({ type: ToggleType.Checkbox, isOn: false })
          .size({ width: 28, height: 28 })
          .selectedColor(0xed6f21)
          .onChange((isOn: boolean) => {
            console.info('Component status:' + isOn)
          })

        Toggle({ type: ToggleType.Checkbox, isOn: true })
          .size({ width: 28, height: 28 })
          .selectedColor(0x39a2db)
          .onChange((isOn: boolean) => {
            console.info('Component status:' + isOn)
          })
      }

      Text('type: Button').fontSize(12).fontColor(0xcccccc).width('90%')
      Flex({ justifyContent: FlexAlign.SpaceEvenly, alignItems: ItemAlign.Center }) {
        Toggle({ type: ToggleType.Button, isOn: false }) {
          Text('status button').padding({ left: 12, right: 12 })
        }
        .selectedColor(0xed6f21)
        .onChange((isOn: boolean) => {
          console.info('Component status:' + isOn)
        })

        Toggle({ type: ToggleType.Button, isOn: true }) {
          Text('status button').padding({ left: 12, right: 12 })
        }
        .selectedColor(0x39a2db)
        .onChange((isOn: boolean) => {
          console.info('Component status:' + isOn)
        })
      }
    }.width('100%').padding(24)
  }
}
```

![](figures/toggle.gif)

