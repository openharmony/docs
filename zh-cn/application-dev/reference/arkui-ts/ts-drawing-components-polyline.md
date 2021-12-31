# Polyline<a name="ZH-CN_TOPIC_0000001192595150"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

折线绘制组件。

## 权限列表<a name="section53281531154915"></a>

无

## 子组件<a name="section29916914716"></a>

无

## 接口<a name="section19864224475"></a>

Polyline\(options?: \{width: Lenght, height: Length\}\)

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="15.47%" id="mcps1.1.6.1.1"><p>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.6.1.2"><p>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.49%" id="mcps1.1.6.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="18.6%" id="mcps1.1.6.1.4"><p>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="36.22%" id="mcps1.1.6.1.5"><p>参数描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="15.47%" headers="mcps1.1.6.1.1 "><p>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.6.1.2 "><p>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.49%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.6%" headers="mcps1.1.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="36.22%" headers="mcps1.1.6.1.5 "><p>见<a href="#li67915428493">options参数说明</a>。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   <a name="li67915428493"></a>options参数说明

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.1.6.1.1"><p>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.01%" id="mcps1.1.6.1.2"><p>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.499999999999998%" id="mcps1.1.6.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.170000000000002%" id="mcps1.1.6.1.4"><p>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="42.21%" id="mcps1.1.6.1.5"><p>参数描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p>width</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.01%" headers="mcps1.1.6.1.2 "><p>Length</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.499999999999998%" headers="mcps1.1.6.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.170000000000002%" headers="mcps1.1.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.21%" headers="mcps1.1.6.1.5 "><p>宽度。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p>height</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.01%" headers="mcps1.1.6.1.2 "><p>Length</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.499999999999998%" headers="mcps1.1.6.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.170000000000002%" headers="mcps1.1.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.21%" headers="mcps1.1.6.1.5 "><p>高度。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 属性<a name="section1181110508478"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.1"><p>参数名称</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.2"><p>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="16.12%" id="mcps1.1.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="23.880000000000003%" id="mcps1.1.6.1.5"><p>参数描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p>width</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p>Length</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="16.12%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="23.880000000000003%" headers="mcps1.1.6.1.5 "><p>折线所在矩形的宽度。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p>height</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p>Length</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="16.12%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="23.880000000000003%" headers="mcps1.1.6.1.5 "><p>折线所在矩形的高度。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p>points</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p>Array<span>&lt;</span><span>Point</span><span>&gt;</span></p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="16.12%" headers="mcps1.1.6.1.4 "><p>是</p>
</td>
<td class="cellrowborder" valign="top" width="23.880000000000003%" headers="mcps1.1.6.1.5 "><p>折线经过坐标点列表。</p>
</td>
</tr>
</tbody>
</table>

## 示例<a name="section4459736105512"></a>

```
@Entry
@Component
struct PolylineExample {
  build() {
    Column({ space: 5 }) {
      Flex({ justifyContent: FlexAlign.SpaceAround }) {
        // 在 100 * 100 的矩形框中绘制一段折线，起点(0, 0)，经过(20,60)，到达终点(100, 100)
        Polyline({ width: 100, height: 100 }).points([[0, 0], [20, 60], [100, 100]])
        // 在 100 * 100 的矩形框中绘制一段折线，起点(0, 0)，经过(0,100)，到达终点(100, 100)
        Polyline().width(100).height(100).points([[0, 0], [0, 100], [100, 100]])
      }.width('100%')
    }.margin({ top: 5 })
  }
}
```

![](figures/polyline.gif)

