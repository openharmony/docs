# GridContainer<a name="EN-US_TOPIC_0000001128072986"></a>

The  **<GridContainer\>**  component lays out components vertically. It is used only in the grid layout.

## Child Components<a name="section5989144051714"></a>

This component can contain child components.

## APIs<a name="section1643325819470"></a>

GridContainer\(options? :\{ columns?: number | 'auto', sizeType?: SizeType, gutter?: Length, margin?: Length \}\)

-   Parameter

    <a name="table69661135912"></a>
    <table><thead align="left"><tr id="row149668318915"><th class="cellrowborder" valign="top" width="13.71%" id="mcps1.1.6.1.1"><p id="p7966738914"><a name="p7966738914"></a><a name="p7966738914"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.62%" id="mcps1.1.6.1.2"><p id="p296713699"><a name="p296713699"></a><a name="p296713699"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.469999999999999%" id="mcps1.1.6.1.3"><p id="p196718315911"><a name="p196718315911"></a><a name="p196718315911"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="23.380000000000003%" id="mcps1.1.6.1.4"><p id="p215210313820"><a name="p215210313820"></a><a name="p215210313820"></a>Default Value</p>
    </th>
    <th class="cellrowborder" valign="top" width="40.82%" id="mcps1.1.6.1.5"><p id="p9967231197"><a name="p9967231197"></a><a name="p9967231197"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row99671533914"><td class="cellrowborder" valign="top" width="13.71%" headers="mcps1.1.6.1.1 "><p id="p79671633910"><a name="p79671633910"></a><a name="p79671633910"></a>columns</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.62%" headers="mcps1.1.6.1.2 "><p id="p11967433914"><a name="p11967433914"></a><a name="p11967433914"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.469999999999999%" headers="mcps1.1.6.1.3 "><p id="p19671336916"><a name="p19671336916"></a><a name="p19671336916"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="23.380000000000003%" headers="mcps1.1.6.1.4 "><p id="p164621417916"><a name="p164621417916"></a><a name="p164621417916"></a>'auto'</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.82%" headers="mcps1.1.6.1.5 "><p id="p69671631796"><a name="p69671631796"></a><a name="p69671631796"></a>Total number of columns in the current layout.</p>
    </td>
    </tr>
    <tr id="row18967831393"><td class="cellrowborder" valign="top" width="13.71%" headers="mcps1.1.6.1.1 "><p id="p39671131590"><a name="p39671131590"></a><a name="p39671131590"></a>sizeType</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.62%" headers="mcps1.1.6.1.2 "><p id="p126051952172518"><a name="p126051952172518"></a><a name="p126051952172518"></a><a href="#li126518511237">SizeType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="8.469999999999999%" headers="mcps1.1.6.1.3 "><p id="p149671932919"><a name="p149671932919"></a><a name="p149671932919"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="23.380000000000003%" headers="mcps1.1.6.1.4 "><p id="p576418295321"><a name="p576418295321"></a><a name="p576418295321"></a>Auto</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.82%" headers="mcps1.1.6.1.5 "><p id="p19675312911"><a name="p19675312911"></a><a name="p19675312911"></a>Device size type.</p>
    </td>
    </tr>
    <tr id="row115021152652"><td class="cellrowborder" valign="top" width="13.71%" headers="mcps1.1.6.1.1 "><p id="p150318521156"><a name="p150318521156"></a><a name="p150318521156"></a>gutter</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.62%" headers="mcps1.1.6.1.2 "><p id="p135031752159"><a name="p135031752159"></a><a name="p135031752159"></a>Length</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.469999999999999%" headers="mcps1.1.6.1.3 "><p id="p850315521454"><a name="p850315521454"></a><a name="p850315521454"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="23.380000000000003%" headers="mcps1.1.6.1.4 "><p id="p476414293326"><a name="p476414293326"></a><a name="p476414293326"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.82%" headers="mcps1.1.6.1.5 "><p id="p450325216517"><a name="p450325216517"></a><a name="p450325216517"></a>Gutter of the grid layout.</p>
    </td>
    </tr>
    <tr id="row09618565518"><td class="cellrowborder" valign="top" width="13.71%" headers="mcps1.1.6.1.1 "><p id="p209617561156"><a name="p209617561156"></a><a name="p209617561156"></a>margin</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.62%" headers="mcps1.1.6.1.2 "><p id="p29695617520"><a name="p29695617520"></a><a name="p29695617520"></a>Length</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.469999999999999%" headers="mcps1.1.6.1.3 "><p id="p29685615512"><a name="p29685615512"></a><a name="p29685615512"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="23.380000000000003%" headers="mcps1.1.6.1.4 "><p id="p16764192913326"><a name="p16764192913326"></a><a name="p16764192913326"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.82%" headers="mcps1.1.6.1.5 "><p id="p396175611518"><a name="p396175611518"></a><a name="p396175611518"></a>Margin of the grid layout.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   <a name="li126518511237"></a>SizeType enums

    <a name="table3452114216394"></a>
    <table><thead align="left"><tr id="row245219426397"><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p id="p545244283914"><a name="p545244283914"></a><a name="p545244283914"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p id="p2452114203917"><a name="p2452114203917"></a><a name="p2452114203917"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row6452144218390"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p34529427398"><a name="p34529427398"></a><a name="p34529427398"></a>XS</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p1245211421393"><a name="p1245211421393"></a><a name="p1245211421393"></a>Device of the minimum size.</p>
    </td>
    </tr>
    <tr id="row12452184217398"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p54523425398"><a name="p54523425398"></a><a name="p54523425398"></a>SM</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p745215426391"><a name="p745215426391"></a><a name="p745215426391"></a>Small-sized device.</p>
    </td>
    </tr>
    <tr id="row9452134213392"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p510719111403"><a name="p510719111403"></a><a name="p510719111403"></a>MD</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p154533425394"><a name="p154533425394"></a><a name="p154533425394"></a>Medium-sized device.</p>
    </td>
    </tr>
    <tr id="row1345313424399"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p1766215124010"><a name="p1766215124010"></a><a name="p1766215124010"></a>LG</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p1245319426394"><a name="p1245319426394"></a><a name="p1245319426394"></a>Large-sized device.</p>
    </td>
    </tr>
    <tr id="row17691110192119"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p36991082112"><a name="p36991082112"></a><a name="p36991082112"></a>Auto</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p569111062118"><a name="p569111062118"></a><a name="p569111062118"></a>Auto. The size type is selected based on the device type.</p>
    </td>
    </tr>
    </tbody>
    </table>


## Attributes<a name="section1131219513263"></a>

Universal attributes and  [attributes](ts-container-column.md#section358284262918)  of the  **<Column\>**  component are supported.

## Events<a name="section6359753182615"></a>

Universal events are supported.

## Example<a name="section1078035104913"></a>

```
@Entry
@Component
struct GridContainerExample {
  @State sizeType: SizeType = SizeType.XS

  build() {
    Column({ space: 5 }) {
      GridContainer({ columns: 12, sizeType: this.sizeType, gutter: 10, margin: 20 }) {
        Row() {
          Text('1')
            .useSizeType({
              xs: { span: 6, offset: 0 },
              sm: { span: 2, offset: 0 },
              md: { span: 2, offset: 0 },
              lg: { span: 2, offset: 0 }
            })
            .height(50).backgroundColor(0x4682B4).textAlign(TextAlign.Center)
          Text('2')
            .useSizeType({
              xs: { span: 2, offset: 6 },
              sm: { span: 6, offset: 2 },
              md: { span: 2, offset: 2 },
              lg: { span: 2, offset: 2 }
            })
            .height(50).backgroundColor(0x00BFFF).textAlign(TextAlign.Center)
          Text('3')
            .useSizeType({
              xs: { span: 2, offset: 8 },
              sm: { span: 2, offset: 8 },
              md: { span: 6, offset: 4 },
              lg: { span: 2, offset: 4 }
            })
            .height(50).backgroundColor(0x4682B4).textAlign(TextAlign.Center)
          Text('4')
            .useSizeType({
              xs: { span: 2, offset: 10 },
              sm: { span: 2, offset: 10 },
              md: { span: 2, offset: 10 },
              lg: { span: 6, offset: 6 }
            })
            .height(50).backgroundColor(0x00BFFF).textAlign(TextAlign.Center)
        }
      }.width('90%')

      Text('Click Simulate to change the device width').fontSize(9).width('90%').fontColor(0xCCCCCC)
      Row() {
        Button('XS')
          .onClick(() => {
            this.sizeType = SizeType.XS
          }).backgroundColor(0x317aff)
        Button('SM')
          .onClick(() => {
            this.sizeType = SizeType.SM
          }).backgroundColor(0x317aff)
        Button('MD')
          .onClick(() => {
            this.sizeType = SizeType.MD
          }).backgroundColor(0x317aff)
        Button('LG')
          .onClick(() => {
            this.sizeType = SizeType.LG
          }).backgroundColor(0x317aff)
      }
    }.width('100%').margin({ top: 5 })
  }
}
```

![](figures/grid.gif)

