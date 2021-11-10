# QRCode<a name="ZH-CN_TOPIC_0000001111842032"></a>

显示二维码信息。

## 权限类别<a name="section435712372238"></a>

无

## 子组件<a name="section13981154442315"></a>

无

## 接口<a name="section18806175252314"></a>

QRCode\(value: string\)

-   参数

    <a name="table1392916196212"></a>
    <table><thead align="left"><tr id="row19306191218"><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.1.6.1.1"><p id="p199307193217"><a name="p199307193217"></a><a name="p199307193217"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.01%" id="mcps1.1.6.1.2"><p id="p119302191128"><a name="p119302191128"></a><a name="p119302191128"></a>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="13%" id="mcps1.1.6.1.3"><p id="p7930141911211"><a name="p7930141911211"></a><a name="p7930141911211"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.869999999999997%" id="mcps1.1.6.1.4"><p id="p1393020194219"><a name="p1393020194219"></a><a name="p1393020194219"></a>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="40.01%" id="mcps1.1.6.1.5"><p id="p693061912210"><a name="p693061912210"></a><a name="p693061912210"></a>参数描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1093021911217"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p119307198218"><a name="p119307198218"></a><a name="p119307198218"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.01%" headers="mcps1.1.6.1.2 "><p id="p129301719828"><a name="p129301719828"></a><a name="p129301719828"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="13%" headers="mcps1.1.6.1.3 "><p id="p893091913213"><a name="p893091913213"></a><a name="p893091913213"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.869999999999997%" headers="mcps1.1.6.1.4 "><p id="p421641117507"><a name="p421641117507"></a><a name="p421641117507"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.01%" headers="mcps1.1.6.1.5 "><p id="p693016198212"><a name="p693016198212"></a><a name="p693016198212"></a>二维码内容字符串。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 属性<a name="section12170272251"></a>

<a name="table1848913413256"></a>
<table><thead align="left"><tr id="row248924182514"><th class="cellrowborder" valign="top" width="20.64%" id="mcps1.1.5.1.1"><p id="p14901241192512"><a name="p14901241192512"></a><a name="p14901241192512"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="19.97%" id="mcps1.1.5.1.2"><p id="p19490541192514"><a name="p19490541192514"></a><a name="p19490541192514"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="20.05%" id="mcps1.1.5.1.3"><p id="p1349064115259"><a name="p1349064115259"></a><a name="p1349064115259"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="39.34%" id="mcps1.1.5.1.4"><p id="p049016417259"><a name="p049016417259"></a><a name="p049016417259"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row204906412251"><td class="cellrowborder" valign="top" width="20.64%" headers="mcps1.1.5.1.1 "><p id="p9490134122512"><a name="p9490134122512"></a><a name="p9490134122512"></a>color</p>
</td>
<td class="cellrowborder" valign="top" width="19.97%" headers="mcps1.1.5.1.2 "><p id="p1490194172513"><a name="p1490194172513"></a><a name="p1490194172513"></a>Color</p>
</td>
<td class="cellrowborder" valign="top" width="20.05%" headers="mcps1.1.5.1.3 "><p id="p114909415254"><a name="p114909415254"></a><a name="p114909415254"></a>Black</p>
</td>
<td class="cellrowborder" valign="top" width="39.34%" headers="mcps1.1.5.1.4 "><p id="p17490204115252"><a name="p17490204115252"></a><a name="p17490204115252"></a>设置二维码颜色。</p>
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

