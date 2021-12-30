# PinchGesture<a name="ZH-CN_TOPIC_0000001237715101"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 权限列表<a name="section781125411508"></a>

无

## 接口<a name="section46581530142116"></a>

PinchGesture\(options?: \{ fingers?: number, distance?: number \}\)

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.1.6.1.1"><p>参数名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="15.959999999999999%" id="mcps1.1.6.1.2"><p>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.04%" id="mcps1.1.6.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.709999999999999%" id="mcps1.1.6.1.4"><p>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="45.18%" id="mcps1.1.6.1.5"><p>参数描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p>fingers</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.959999999999999%" headers="mcps1.1.6.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.04%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.709999999999999%" headers="mcps1.1.6.1.4 "><p>2</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.18%" headers="mcps1.1.6.1.5 "><p>触发捏合的最少手指数, 最小为2指，最大为5指。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p>distance</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.959999999999999%" headers="mcps1.1.6.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.04%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.709999999999999%" headers="mcps1.1.6.1.4 "><p>3.0</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.18%" headers="mcps1.1.6.1.5 "><p>最小识别距离，单位为vp。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 事件<a name="section1121514205616"></a>

<table><thead align="left"><tr><th class="cellrowborder" colspan="2" valign="top" id="mcps1.1.4.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.4.1.2"><p>功能描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p>onActionStart((event?: <a href="#li21621335144710">PinchGestureEvent</a>) =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p>Pinch手势识别成功回调。</p>
</td>
</tr>
<tr><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p>onActionUpdate((event?: <a href="#li21621335144710">PinchGestureEvent</a>) =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p>Pinch手势移动过程中回调。</p>
</td>
</tr>
<tr><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p>onActionEnd((event?: <a href="#li21621335144710">PinchGestureEvent</a>) =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p>Pinch手势识别成功，手指抬起后触发回调。</p>
</td>
</tr>
<tr><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p>onActionCancel(event: () =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p>Pinch手势识别成功，接收到触摸取消事件触发回调。</p>
</td>
</tr>
</tbody>
</table>

-   <a name="li21621335144710"></a>PinchGestureEvent类型说明<sup>8+</sup>

    继承自[GestureEvent](ts-gesture-settings.md#table290mcpsimp)类型。

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="20.09%" id="mcps1.1.4.1.1"><p>属性名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="18.41%" id="mcps1.1.4.1.2"><p>属性类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.5%" id="mcps1.1.4.1.3"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="20.09%" headers="mcps1.1.4.1.1 "><p>scale</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.41%" headers="mcps1.1.4.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.5%" headers="mcps1.1.4.1.3 "><p>缩放比例，用于PinchGesture手势触发场景。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="20.09%" headers="mcps1.1.4.1.1 "><p>pinchCenterX</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.41%" headers="mcps1.1.4.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.5%" headers="mcps1.1.4.1.3 "><p>捏合手势中心点X轴坐标，单位为px。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="20.09%" headers="mcps1.1.4.1.1 "><p>pinchCenterY</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.41%" headers="mcps1.1.4.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.5%" headers="mcps1.1.4.1.3 "><p>捏合手势中心点Y轴坐标，单位为px。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 示例<a name="section16900453182718"></a>

```
@Entry
@Component
struct PinchGestureExample {
  @State scale: number = 1

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.SpaceBetween }) {
      Text('PinchGesture scale:' + this.scale)
    }
    .height(100).width(200).padding(20).border({ width: 1 }).margin(80)
    .scale({ x: this.scale, y: this.scale, z: this.scale })
    .gesture(
      PinchGesture()
        .onActionStart((event: PinchGestureEvent) => {
          console.info('Pinch start')
        })
        .onActionUpdate((event: PinchGestureEvent) => {
          this.scale = event.scale
        })
        .onActionEnd(() => {
          console.info('Pinch end')
        })
    )
  }
}
```

![](figures/PinchGesture.gif)

