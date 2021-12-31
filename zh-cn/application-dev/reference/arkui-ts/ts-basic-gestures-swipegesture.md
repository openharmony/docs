# SwipeGesture<a name="ZH-CN_TOPIC_0000001237475077"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 权限列表<a name="section781125411508"></a>

无

## 接口<a name="section46581530142116"></a>

SwipeGesture\(value?: \{ fingers?: number; direction?: SwipeDirection; speed?: number \}\)

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="13.62%" id="mcps1.1.6.1.1"><p>参数名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="17.16%" id="mcps1.1.6.1.2"><p>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.239999999999999%" id="mcps1.1.6.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="20.4%" id="mcps1.1.6.1.4"><p>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="42.58%" id="mcps1.1.6.1.5"><p>参数描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="13.62%" headers="mcps1.1.6.1.1 "><p>fingers</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.16%" headers="mcps1.1.6.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.239999999999999%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.4%" headers="mcps1.1.6.1.4 "><p>1</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.58%" headers="mcps1.1.6.1.5 "><p>触发滑动的最少手指数，默认为1，最小为1指，最大为10指。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="13.62%" headers="mcps1.1.6.1.1 "><p>direction</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.16%" headers="mcps1.1.6.1.2 "><p><a href="#li1176517215161">SwipeDirection</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="6.239999999999999%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.4%" headers="mcps1.1.6.1.4 "><p>SwipeDirection.All</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.58%" headers="mcps1.1.6.1.5 "><p>滑动方向。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="13.62%" headers="mcps1.1.6.1.1 "><p>speed</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.16%" headers="mcps1.1.6.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.239999999999999%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.4%" headers="mcps1.1.6.1.4 "><p>100</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.58%" headers="mcps1.1.6.1.5 "><p>识别滑动的最小速度（100VP/秒）。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   <a name="li1176517215161"></a>SwipeDirection枚举说明

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>All</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>所有方向。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>Horizontal</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>水平方向。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>Vertical</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>竖直方向。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 事件<a name="section171844635610"></a>

<table><thead align="left"><tr><th class="cellrowborder" colspan="2" valign="top" id="mcps1.1.4.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.4.1.2"><p>功能描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p>onAction(callback:(event?: <a href="#li497431115208">SwipeGestureEvent</a>) =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p>滑动手势识别成功回调。</p>
</td>
</tr>
</tbody>
</table>

-   <a name="li497431115208"></a>SwipeGestureEvent类型说明

    继承自[GestureEvent](ts-gesture-settings.md#table290mcpsimp)类型。

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.1"><p>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.3"><p>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p>angle</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p>滑动手势的角度。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p>speed</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p>滑动手势的速度。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 示例<a name="section16900453182718"></a>

```
@Entry
@Component
struct SwipeGestureExample {
  @State rotateAngle : number = 0
  @State speed : number = 1

  build() {
    Column() {
      Text("SwipGesture speed ： " + this.speed)
      Text("SwipGesture angle ： " + this.rotateAngle)
    }
    .position({x: 80, y: 200})
    .border({width:2})
    .width(260).height(260)
    .rotate({x: 0, y: 0, z: 1, angle: this.rotateAngle})
    .gesture(
      SwipeGesture({fingers: 1, direction:SwipeDirection.Vertical})
        .onAction((event: SwipeGestureEvent) => {
          this.speed = event.speed
          this.rotateAngle = event.angle
      })
    )
  }
}
```

![](figures/GIF-0.gif)

