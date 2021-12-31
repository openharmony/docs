# DataPanel<a name="ZH-CN_TOPIC_0000001237355069"></a>

数据面板组件，用于将多个数据占比情况使用占比图进行展示。

## 权限列表<a name="section781125411508"></a>

无

## 子组件<a name="section53281531154915"></a>

无

## 接口<a name="section1989913519718"></a>

DataPanel\(value:\{values: number\[\], max?: number, type?: DataPanelType\}\)

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.1.6.1.1"><p>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.01%" id="mcps1.1.6.1.2"><p>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="5.82%" id="mcps1.1.6.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="17.78%" id="mcps1.1.6.1.4"><p>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="46.28%" id="mcps1.1.6.1.5"><p>参数描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p>values</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.01%" headers="mcps1.1.6.1.2 "><p>number[]</p>
    </td>
    <td class="cellrowborder" valign="top" width="5.82%" headers="mcps1.1.6.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.78%" headers="mcps1.1.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.28%" headers="mcps1.1.6.1.5 "><p>数据值列表，最大支持9个数据。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p>max</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.01%" headers="mcps1.1.6.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="5.82%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.78%" headers="mcps1.1.6.1.4 "><p>100</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.28%" headers="mcps1.1.6.1.5 "><p>1.max大于0，表示数据的最大值。</p>
    <p>2.max小于等于0，max等于value数组各项的和，按比例显示。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p>type<sup><span>8+</span></sup></p>
    </td>
    <td class="cellrowborder" valign="top" width="14.01%" headers="mcps1.1.6.1.2 "><p><a href="#li1012319404371">DataPanelType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="5.82%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.78%" headers="mcps1.1.6.1.4 "><p>DataPanelType.Circle</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.28%" headers="mcps1.1.6.1.5 "><p>数据面板的类型。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   <a name="li1012319404371"></a>DataPanelType枚举说明

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="23.990000000000002%" id="mcps1.1.3.1.1"><p>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="76.01%" id="mcps1.1.3.1.2"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="23.990000000000002%" headers="mcps1.1.3.1.1 "><p>Line</p>
    </td>
    <td class="cellrowborder" valign="top" width="76.01%" headers="mcps1.1.3.1.2 "><p>线型数据面板。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="23.990000000000002%" headers="mcps1.1.3.1.1 "><p>Circle</p>
    </td>
    <td class="cellrowborder" valign="top" width="76.01%" headers="mcps1.1.3.1.2 "><p>环形数据面板。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 示例<a name="section13800193662114"></a>

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

