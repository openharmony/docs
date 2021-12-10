# TapGesture<a name="ZH-CN_TOPIC_0000001159258799"></a>

## 接口<a name="section11129153920518"></a>

TapGesture\(options?: \{ count?: number, fingers?: number \}\)

-   参数

    <a name="table1392916196212"></a>
    <table><thead align="left"><tr id="row19306191218"><th class="cellrowborder" valign="top" width="14.330000000000002%" id="mcps1.1.6.1.1"><p id="p199307193217"><a name="p199307193217"></a><a name="p199307193217"></a>参数名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.799999999999999%" id="mcps1.1.6.1.2"><p id="p119302191128"><a name="p119302191128"></a><a name="p119302191128"></a>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.58%" id="mcps1.1.6.1.3"><p id="p7930141911211"><a name="p7930141911211"></a><a name="p7930141911211"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.219999999999999%" id="mcps1.1.6.1.4"><p id="p1393020194219"><a name="p1393020194219"></a><a name="p1393020194219"></a>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="51.07000000000001%" id="mcps1.1.6.1.5"><p id="p693061912210"><a name="p693061912210"></a><a name="p693061912210"></a>参数描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1238121310306"><td class="cellrowborder" valign="top" width="14.330000000000002%" headers="mcps1.1.6.1.1 "><p id="p938113193017"><a name="p938113193017"></a><a name="p938113193017"></a>count</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.799999999999999%" headers="mcps1.1.6.1.2 "><p id="p23861373017"><a name="p23861373017"></a><a name="p23861373017"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.58%" headers="mcps1.1.6.1.3 "><p id="p183814131307"><a name="p183814131307"></a><a name="p183814131307"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.219999999999999%" headers="mcps1.1.6.1.4 "><p id="p163831312306"><a name="p163831312306"></a><a name="p163831312306"></a>1</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.07000000000001%" headers="mcps1.1.6.1.5 "><p id="p103814137301"><a name="p103814137301"></a><a name="p103814137301"></a>识别的连续点击次数。如果设置小于1，会被转化为默认值。</p>
    <div class="note" id="note1962422343316"><a name="note1962422343316"></a><a name="note1962422343316"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="p1262452373311"><a name="p1262452373311"></a><a name="p1262452373311"></a>如配置多击，上一次抬起和下一次按下的超时时间为300毫秒（ms）。</p>
    </div></div>
    </td>
    </tr>
    <tr id="row1093021911217"><td class="cellrowborder" valign="top" width="14.330000000000002%" headers="mcps1.1.6.1.1 "><p id="p119307198218"><a name="p119307198218"></a><a name="p119307198218"></a>fingers</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.799999999999999%" headers="mcps1.1.6.1.2 "><p id="p129301719828"><a name="p129301719828"></a><a name="p129301719828"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.58%" headers="mcps1.1.6.1.3 "><p id="p893091913213"><a name="p893091913213"></a><a name="p893091913213"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.219999999999999%" headers="mcps1.1.6.1.4 "><p id="p421641117507"><a name="p421641117507"></a><a name="p421641117507"></a>1</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.07000000000001%" headers="mcps1.1.6.1.5 "><p id="p1791619538303"><a name="p1791619538303"></a><a name="p1791619538303"></a>触发点击的最少手指数，最小为1指， 最大为10指。</p>
    <div class="note" id="note439342719312"><a name="note439342719312"></a><a name="note439342719312"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="p116781255143118"><a name="p116781255143118"></a><a name="p116781255143118"></a>1. 当配置多指时，第一根手指按下后300毫秒（ms）内未有足够的手指数按下，手势识别失败。</p>
    <p id="p939311275319"><a name="p939311275319"></a><a name="p939311275319"></a>2. 实际点击手指数超过配置值，手势识别失败。</p>
    </div></div>
    </td>
    </tr>
    </tbody>
    </table>


## 事件<a name="section23760590517"></a>

<a name="table135406579437"></a>
<table><thead align="left"><tr id="row1154015719436"><th class="cellrowborder" colspan="2" valign="top" id="mcps1.1.4.1.1"><p id="p85411457184316"><a name="p85411457184316"></a><a name="p85411457184316"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.4.1.2"><p id="p5541457194319"><a name="p5541457194319"></a><a name="p5541457194319"></a>功能描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row4541257114319"><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p id="p5541357194313"><a name="p5541357194313"></a><a name="p5541357194313"></a>onAction((event?: <a href="ts-gesture-settings.md#table290mcpsimp">GestureEvent</a>) =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p11541155710434"><a name="p11541155710434"></a><a name="p11541155710434"></a>Tap手势识别成功回调。</p>
</td>
</tr>
</tbody>
</table>

## 示例<a name="section16900453182718"></a>

```
@Entry
@Component
struct TapGestureExample {
  @State value: string = ''

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.SpaceBetween }) {
      Text('Click twice')
      Text(this.value)
    }
    .height(200).width(300).padding(60).border({ width: 1 }).margin(30)
    .gesture(
      TapGesture({ count: 2 })
        .onAction(() => {
          this.value = 'TapGesture onAction'
        })
    )
  }
}
```

![](figures/TapGesture.gif)

