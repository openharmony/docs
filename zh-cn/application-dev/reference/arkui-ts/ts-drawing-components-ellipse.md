# Ellipse<a name="ZH-CN_TOPIC_0000001193075096"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

椭圆绘制组件。

## 权限列表<a name="section53281531154915"></a>

无

## 子组件<a name="section121862320423"></a>

无

## 接口<a name="section1870194144317"></a>

ellipse\(options?: \{width: Lenght, height: Length\}\)

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
    <td class="cellrowborder" valign="top" width="36.22%" headers="mcps1.1.6.1.5 "><p>见<a href="#li155660864616">options参数说明</a>。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   <a name="li155660864616"></a>options参数说明

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


## 属性<a name="section177298713218"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="19.999999999999996%" id="mcps1.1.6.1.1"><p>参数名称</p>
</th>
<th class="cellrowborder" valign="top" width="19.999999999999996%" id="mcps1.1.6.1.2"><p>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="19.999999999999996%" id="mcps1.1.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="16.799999999999997%" id="mcps1.1.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="23.199999999999996%" id="mcps1.1.6.1.5"><p>参数描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="19.999999999999996%" headers="mcps1.1.6.1.1 "><p>width</p>
</td>
<td class="cellrowborder" valign="top" width="19.999999999999996%" headers="mcps1.1.6.1.2 "><p>Length</p>
</td>
<td class="cellrowborder" valign="top" width="19.999999999999996%" headers="mcps1.1.6.1.3 "><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="16.799999999999997%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="23.199999999999996%" headers="mcps1.1.6.1.5 "><p>椭圆所在矩形的宽度。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="19.999999999999996%" headers="mcps1.1.6.1.1 "><p>height</p>
</td>
<td class="cellrowborder" valign="top" width="19.999999999999996%" headers="mcps1.1.6.1.2 "><p>Length</p>
</td>
<td class="cellrowborder" valign="top" width="19.999999999999996%" headers="mcps1.1.6.1.3 "><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="16.799999999999997%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="23.199999999999996%" headers="mcps1.1.6.1.5 "><p>椭圆所在矩形的高度。</p>
</td>
</tr>
</tbody>
</table>

## 示例<a name="section4459736105512"></a>

```
@Entry
@Component
struct EllipseExample {
  build() {
    Flex({ justifyContent: FlexAlign.SpaceAround }) {
      // 在一个 150 * 70 的矩形框中绘制一个椭圆
      Ellipse({ width: 150, height: 80 })
      // 在一个 150 * 70 的矩形框中绘制一个椭圆
      Ellipse().width(150).height(80)
    }.width('100%').margin({ top: 5 })
  }
}
```

![](figures/ellipse.png)

