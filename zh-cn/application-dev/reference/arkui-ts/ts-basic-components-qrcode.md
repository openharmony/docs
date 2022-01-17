# QRCode<a name="ZH-CN_TOPIC_0000001237475049"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

显示二维码信息。

## 权限列表<a name="section435712372238"></a>

无

## 子组件<a name="section13981154442315"></a>

无

## 接口<a name="section18806175252314"></a>

QRCode\(value: string\)

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.1.6.1.1"><p>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.01%" id="mcps1.1.6.1.2"><p>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="13%" id="mcps1.1.6.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.869999999999997%" id="mcps1.1.6.1.4"><p>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="40.01%" id="mcps1.1.6.1.5"><p>参数描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.01%" headers="mcps1.1.6.1.2 "><p>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="13%" headers="mcps1.1.6.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.869999999999997%" headers="mcps1.1.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.01%" headers="mcps1.1.6.1.5 "><p>二维码内容字符串。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 属性<a name="section12170272251"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="20.64%" id="mcps1.1.5.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="19.97%" id="mcps1.1.5.1.2"><p>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="20.05%" id="mcps1.1.5.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="39.34%" id="mcps1.1.5.1.4"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="20.64%" headers="mcps1.1.5.1.1 "><p>color</p>
</td>
<td class="cellrowborder" valign="top" width="19.97%" headers="mcps1.1.5.1.2 "><p>Color</p>
</td>
<td class="cellrowborder" valign="top" width="20.05%" headers="mcps1.1.5.1.3 "><p>Black</p>
</td>
<td class="cellrowborder" valign="top" width="39.34%" headers="mcps1.1.5.1.4 "><p>设置二维码颜色。</p>
</td>
</tr>
</tbody>
</table>

## 事件<a name="section9578105714273"></a>

通用事件仅支持点击事件。

## 示例<a name="section158692046152618"></a>

```
@Entry
@Component
struct QRCodeExample {
  private value: string = 'hello world'

  build() {
    Column({ space: 5 }) {
      Text('normal').fontSize(9).width('90%').fontColor(0xCCCCCC)
      QRCode(this.value).width(200).height(200)

      Text('color').fontSize(9).width('90%').fontColor(0xCCCCCC)
      QRCode(this.value).color(0xF7CE00).width(200).height(200)
    }.width('100%').margin({ top: 5 })
  }
}
```

![](figures/qrcode.png)

