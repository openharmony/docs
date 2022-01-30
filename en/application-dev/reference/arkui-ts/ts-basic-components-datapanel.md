# DataPanel<a name="EN-US_TOPIC_0000001237355069"></a>

The  **<DataPanel\>**  component displays proportions in a chart.

## Required Permissions<a name="section781125411508"></a>

None

## Child Components<a name="section53281531154915"></a>

None

## APIs<a name="section1989913519718"></a>

DataPanel\(value:\{values: number\[\], max?: number, type?: DataPanelType\}\)

-   Parameters

    <a name="table1392916196212"></a>
    <table><thead align="left"><tr id="row19306191218"><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.1.6.1.1"><p id="p199307193217"><a name="p199307193217"></a><a name="p199307193217"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.01%" id="mcps1.1.6.1.2"><p id="p119302191128"><a name="p119302191128"></a><a name="p119302191128"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="5.82%" id="mcps1.1.6.1.3"><p id="p7930141911211"><a name="p7930141911211"></a><a name="p7930141911211"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="17.78%" id="mcps1.1.6.1.4"><p id="p1393020194219"><a name="p1393020194219"></a><a name="p1393020194219"></a>Default Value</p>
    </th>
    <th class="cellrowborder" valign="top" width="46.28%" id="mcps1.1.6.1.5"><p id="p693061912210"><a name="p693061912210"></a><a name="p693061912210"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1093021911217"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p119307198218"><a name="p119307198218"></a><a name="p119307198218"></a>values</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.01%" headers="mcps1.1.6.1.2 "><p id="p129301719828"><a name="p129301719828"></a><a name="p129301719828"></a>number[]</p>
    </td>
    <td class="cellrowborder" valign="top" width="5.82%" headers="mcps1.1.6.1.3 "><p id="p893091913213"><a name="p893091913213"></a><a name="p893091913213"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.78%" headers="mcps1.1.6.1.4 "><p id="p421641117507"><a name="p421641117507"></a><a name="p421641117507"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.28%" headers="mcps1.1.6.1.5 "><p id="p693016198212"><a name="p693016198212"></a><a name="p693016198212"></a>Value list. A maximum of nine values are supported.</p>
    </td>
    </tr>
    <tr id="row199301191726"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p0930419923"><a name="p0930419923"></a><a name="p0930419923"></a>max</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.01%" headers="mcps1.1.6.1.2 "><p id="p1993071918217"><a name="p1993071918217"></a><a name="p1993071918217"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="5.82%" headers="mcps1.1.6.1.3 "><p id="p29309191029"><a name="p29309191029"></a><a name="p29309191029"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.78%" headers="mcps1.1.6.1.4 "><p id="p393019193220"><a name="p393019193220"></a><a name="p393019193220"></a>100</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.28%" headers="mcps1.1.6.1.5 "><p id="p2299847712"><a name="p2299847712"></a><a name="p2299847712"></a>1. When set to a value greater than 0, this parameter indicates the maximum value in the <strong id="b476723173313"><a name="b476723173313"></a><a name="b476723173313"></a>values</strong> list.</p>
    <p id="p793001918220"><a name="p793001918220"></a><a name="p793001918220"></a>2. When set to a value equal to or smaller than 0, this parameter indicates the sum of values in the <strong id="b215814566332"><a name="b215814566332"></a><a name="b215814566332"></a>values</strong> list. The values are displayed in proportion.</p>
    </td>
    </tr>
    <tr id="row8532922203314"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p145324221335"><a name="p145324221335"></a><a name="p145324221335"></a>type<sup id="sup1585891816340"><a name="sup1585891816340"></a><a name="sup1585891816340"></a>8+</sup></p>
    </td>
    <td class="cellrowborder" valign="top" width="14.01%" headers="mcps1.1.6.1.2 "><p id="p1253215221335"><a name="p1253215221335"></a><a name="p1253215221335"></a><a href="#li1012319404371">DataPanelType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="5.82%" headers="mcps1.1.6.1.3 "><p id="p205321122193316"><a name="p205321122193316"></a><a name="p205321122193316"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.78%" headers="mcps1.1.6.1.4 "><p id="p15532152253317"><a name="p15532152253317"></a><a name="p15532152253317"></a>DataPanelType.Circle</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.28%" headers="mcps1.1.6.1.5 "><p id="p175322022153312"><a name="p175322022153312"></a><a name="p175322022153312"></a>Type of the data panel.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   <a name="li1012319404371"></a>DataPanelType enums

    <a name="table160095963710"></a>
    <table><thead align="left"><tr id="row1860019590371"><th class="cellrowborder" valign="top" width="23.990000000000002%" id="mcps1.1.3.1.1"><p id="p845614410388"><a name="p845614410388"></a><a name="p845614410388"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="76.01%" id="mcps1.1.3.1.2"><p id="p1860165923719"><a name="p1860165923719"></a><a name="p1860165923719"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row5601145912377"><td class="cellrowborder" valign="top" width="23.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p1760119592377"><a name="p1760119592377"></a><a name="p1760119592377"></a>Line</p>
    </td>
    <td class="cellrowborder" valign="top" width="76.01%" headers="mcps1.1.3.1.2 "><p id="p156012599374"><a name="p156012599374"></a><a name="p156012599374"></a>Line data panel.</p>
    </td>
    </tr>
    <tr id="row1560113598379"><td class="cellrowborder" valign="top" width="23.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p1127435012409"><a name="p1127435012409"></a><a name="p1127435012409"></a>Circle</p>
    </td>
    <td class="cellrowborder" valign="top" width="76.01%" headers="mcps1.1.3.1.2 "><p id="p106011559113711"><a name="p106011559113711"></a><a name="p106011559113711"></a>Circle data panel.</p>
    </td>
    </tr>
    </tbody>
    </table>


## Example<a name="section13800193662114"></a>

```
@Entry
@Component
struct DataPanelExample {
  public values1: number[] = [10, 10, 10, 10, 10, 10, 10, 10, 10]

  build() {
    Column({ space: 5 }) {
      Text('Circle').fontSize(9).fontColor(0xCCCCCC).margin({ top: 20, right: '80%' })
      DataPanel({ values: this.values1, max: 100, type: DataPanelType.Circle }).width(200).height(200)

      Text('Line').fontSize(9).fontColor(0xCCCCCC).margin({ bottom: 20, right: '80%' })
      DataPanel({ values: this.values1, max: 100, type: DataPanelType.Line }).width(300).height(10)
    }.width('100%').margin({ top: 5 })
  }
}
```

![](figures/datapanel.jpg)

