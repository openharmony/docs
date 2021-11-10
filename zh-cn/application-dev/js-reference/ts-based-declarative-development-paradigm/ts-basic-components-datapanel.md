# DataPanel<a name="ZH-CN_TOPIC_0000001150706126"></a>

数据面板组件，用于将多个数据占比情况使用环形占比图进行展示。

## 子组件<a name="section53281531154915"></a>

无

## 接口<a name="section1989913519718"></a>

DataPanel\(value:\{values: number\[\], max?: number\}\)

-   参数

    <a name="table1392916196212"></a>
    <table><thead align="left"><tr id="row19306191218"><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.1.6.1.1"><p id="p199307193217"><a name="p199307193217"></a><a name="p199307193217"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.01%" id="mcps1.1.6.1.2"><p id="p119302191128"><a name="p119302191128"></a><a name="p119302191128"></a>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="13%" id="mcps1.1.6.1.3"><p id="p7930141911211"><a name="p7930141911211"></a><a name="p7930141911211"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.17%" id="mcps1.1.6.1.4"><p id="p1393020194219"><a name="p1393020194219"></a><a name="p1393020194219"></a>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="47.71%" id="mcps1.1.6.1.5"><p id="p693061912210"><a name="p693061912210"></a><a name="p693061912210"></a>参数描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1093021911217"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p119307198218"><a name="p119307198218"></a><a name="p119307198218"></a>values</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.01%" headers="mcps1.1.6.1.2 "><p id="p129301719828"><a name="p129301719828"></a><a name="p129301719828"></a>number[]</p>
    </td>
    <td class="cellrowborder" valign="top" width="13%" headers="mcps1.1.6.1.3 "><p id="p893091913213"><a name="p893091913213"></a><a name="p893091913213"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.17%" headers="mcps1.1.6.1.4 "><p id="p421641117507"><a name="p421641117507"></a><a name="p421641117507"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="47.71%" headers="mcps1.1.6.1.5 "><p id="p693016198212"><a name="p693016198212"></a><a name="p693016198212"></a>数据值列表，最大支持9个数据。</p>
    </td>
    </tr>
    <tr id="row199301191726"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p0930419923"><a name="p0930419923"></a><a name="p0930419923"></a>max</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.01%" headers="mcps1.1.6.1.2 "><p id="p1993071918217"><a name="p1993071918217"></a><a name="p1993071918217"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="13%" headers="mcps1.1.6.1.3 "><p id="p29309191029"><a name="p29309191029"></a><a name="p29309191029"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.17%" headers="mcps1.1.6.1.4 "><p id="p393019193220"><a name="p393019193220"></a><a name="p393019193220"></a>100</p>
    </td>
    <td class="cellrowborder" valign="top" width="47.71%" headers="mcps1.1.6.1.5 "><p id="p793001918220"><a name="p793001918220"></a><a name="p793001918220"></a>数据的最大值。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 示例<a name="section13800193662114"></a>

```
@Entry
@Component
struct DataPanelExample {
  public values1: number[] = [40, 20, 20, 10, 10]

  build() {
    Column({ space: 5 }) {
      DataPanel({ values: this.values1, max: 100 })
        .width(150)
        .height(150)
    }.width('100%').margin({ top: 5 })
  }
}
```

![](figures/datapanel.png)

