# Progress<a name="ZH-CN_TOPIC_0000001193075086"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

进度条，用于显示内容加载或操作处理进度。

## 权限列表<a name="section781125411508"></a>

无

## 子组件<a name="section53281531154915"></a>

无

## 接口说明<a name="section1989913519718"></a>

Progress\(value: \{value: number, total?: number, style?: ProgressStyle\}\)

创建指定进度的进度条。

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.1.6.1.1"><p>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.3%" id="mcps1.1.6.1.2"><p>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.71%" id="mcps1.1.6.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.869999999999997%" id="mcps1.1.6.1.4"><p>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="40.01%" id="mcps1.1.6.1.5"><p>参数描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.3%" headers="mcps1.1.6.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.71%" headers="mcps1.1.6.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.869999999999997%" headers="mcps1.1.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.01%" headers="mcps1.1.6.1.5 "><p>指定当前进度值。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p>total</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.3%" headers="mcps1.1.6.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.71%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.869999999999997%" headers="mcps1.1.6.1.4 "><p>100</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.01%" headers="mcps1.1.6.1.5 "><p>指定进度总长。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p>style</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.3%" headers="mcps1.1.6.1.2 "><p><a href="#table12144170154116">ProgressStyle</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="10.71%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.869999999999997%" headers="mcps1.1.6.1.4 "><p>Linear</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.01%" headers="mcps1.1.6.1.5 "><p>指定进度条样式。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   ProgressStyle枚举说明

    <a name="table12144170154116"></a>
    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="24.69%" id="mcps1.1.3.1.1"><p>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="75.31%" id="mcps1.1.3.1.2"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="24.69%" headers="mcps1.1.3.1.1 "><p>Linear</p>
    </td>
    <td class="cellrowborder" valign="top" width="75.31%" headers="mcps1.1.3.1.2 "><p>线性进度条样式。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 属性<a name="section18430105671014"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="16%" id="mcps1.1.5.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="28.51%" id="mcps1.1.5.1.2"><p>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="12.82%" id="mcps1.1.5.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="42.67%" id="mcps1.1.5.1.4"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.1 "><p>value</p>
</td>
<td class="cellrowborder" valign="top" width="28.51%" headers="mcps1.1.5.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="12.82%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="42.67%" headers="mcps1.1.5.1.4 "><p>设置当前进度值。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.1 "><p>color</p>
</td>
<td class="cellrowborder" valign="top" width="28.51%" headers="mcps1.1.5.1.2 "><p>Color</p>
</td>
<td class="cellrowborder" valign="top" width="12.82%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="42.67%" headers="mcps1.1.5.1.4 "><p>设置进度条前景色。</p>
</td>
</tr>
</tbody>
</table>

## 示例<a name="section13800193662114"></a>

```
@Entry
@Component
struct ProgressExample {
  build() {
    Column({ space: 5 }) {
      Text('Linear Progress').fontSize(9).fontColor(0xCCCCCC).width('90%')
      Progress({ value: 10, style: ProgressStyle.Linear }).width(200)

      Text('Linear Progress Color').fontSize(9).fontColor(0xCCCCCC).width('90%')
      Progress({ value: 20, total: 150, style: ProgressStyle.Linear }).color(Color.Red).value(50).width(200)
    }.width('100%').margin({ top: 5 })
  }
}
```

![](figures/progress.png)

