# TapGesture<a name="ZH-CN_TOPIC_0000001237475081"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 权限列表<a name="section781125411508"></a>

无

## 接口<a name="section11129153920518"></a>

TapGesture\(options?: \{ count?: number, fingers?: number \}\)

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="14.330000000000002%" id="mcps1.1.6.1.1"><p>参数名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.799999999999999%" id="mcps1.1.6.1.2"><p>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.58%" id="mcps1.1.6.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.219999999999999%" id="mcps1.1.6.1.4"><p>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="51.07000000000001%" id="mcps1.1.6.1.5"><p>参数描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="14.330000000000002%" headers="mcps1.1.6.1.1 "><p>count</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.799999999999999%" headers="mcps1.1.6.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.58%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.219999999999999%" headers="mcps1.1.6.1.4 "><p>1</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.07000000000001%" headers="mcps1.1.6.1.5 "><p>识别的连续点击次数。如果设置小于1，会被转化为默认值。</p>
    <div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>如配置多击，上一次抬起和下一次按下的超时时间为300毫秒（ms）。</p>
    </div></div>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="14.330000000000002%" headers="mcps1.1.6.1.1 "><p>fingers</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.799999999999999%" headers="mcps1.1.6.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.58%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.219999999999999%" headers="mcps1.1.6.1.4 "><p>1</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.07000000000001%" headers="mcps1.1.6.1.5 "><p>触发点击的最少手指数，最小为1指， 最大为10指。</p>
    <div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>1. 当配置多指时，第一根手指按下后300毫秒（ms）内未有足够的手指数按下，手势识别失败。</p>
    <p>2. 实际点击手指数超过配置值，手势识别失败。</p>
    </div></div>
    </td>
    </tr>
    </tbody>
    </table>


## 事件<a name="section23760590517"></a>

<table><thead align="left"><tr><th class="cellrowborder" colspan="2" valign="top" id="mcps1.1.4.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.4.1.2"><p>功能描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p>onAction((event?: <a href="#li21621335144710">TapGestureEvent</a>) =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p>Tap手势识别成功回调。</p>
</td>
</tr>
</tbody>
</table>

-   <a name="li21621335144710"></a>TapGestureEvent类型说明<sup>8+</sup>

    继承自[GestureEvent](ts-gesture-settings.md#table290mcpsimp)类型。


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

