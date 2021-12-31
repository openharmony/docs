# RotationGesture<a name="ZH-CN_TOPIC_0000001192595172"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 权限列表<a name="section781125411508"></a>

无

## 接口<a name="section46581530142116"></a>

RotationGesture\(options?: \{ fingers?: number, angle?: number \}\)

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="13.639999999999999%" id="mcps1.1.6.1.1"><p>参数名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.11%" id="mcps1.1.6.1.2"><p>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.27%" id="mcps1.1.6.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.64%" id="mcps1.1.6.1.4"><p>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="53.339999999999996%" id="mcps1.1.6.1.5"><p>参数描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="13.639999999999999%" headers="mcps1.1.6.1.1 "><p>fingers</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.11%" headers="mcps1.1.6.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.27%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.64%" headers="mcps1.1.6.1.4 "><p>2</p>
    </td>
    <td class="cellrowborder" valign="top" width="53.339999999999996%" headers="mcps1.1.6.1.5 "><p>触发旋转的最少手指数, 最小为2指，最大为5指。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="13.639999999999999%" headers="mcps1.1.6.1.1 "><p>angle</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.11%" headers="mcps1.1.6.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.27%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.64%" headers="mcps1.1.6.1.4 "><p>1.0</p>
    </td>
    <td class="cellrowborder" valign="top" width="53.339999999999996%" headers="mcps1.1.6.1.5 "><p>触发旋转手势的最小改变度数，单位为度数。</p>
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
<tbody><tr><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p>onActionStart((event?: <a href="#li21621335144710">RotationGestureEvent</a>) =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p>Rotation手势识别成功回调。</p>
</td>
</tr>
<tr><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p>onActionUpdate((event?: <a href="#li21621335144710">RotationGestureEvent</a>) =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p>Rotation手势移动过程中回调。</p>
</td>
</tr>
<tr><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p>onActionEnd((event?: <a href="#li21621335144710">RotationGestureEvent</a>) =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p>Rotation手势识别成功，手指抬起后触发回调。</p>
</td>
</tr>
<tr><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p>onActionCancel(event: () =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p>Rotation手势识别成功，接收到触摸取消事件触发回调。</p>
</td>
</tr>
</tbody>
</table>

-   <a name="li21621335144710"></a>RotationGestureEvent类型说明<sup>8+</sup>

    继承自[GestureEvent](ts-gesture-settings.md#table290mcpsimp)类型。

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="20.09%" id="mcps1.1.4.1.1"><p>属性名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="18.41%" id="mcps1.1.4.1.2"><p>属性类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.5%" id="mcps1.1.4.1.3"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="20.09%" headers="mcps1.1.4.1.1 "><p>angle</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.41%" headers="mcps1.1.4.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.5%" headers="mcps1.1.4.1.3 "><p>旋转角度。</p>
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
struct RotationGestureExample {
  @State angle: number = 0

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.SpaceBetween }) {
      Text('RotationGesture angle:' + this.angle)
    }
    .height(100).width(200).padding(20).border({ width:1 })
    .margin(80).rotate({ x:1, y:2, z:3, angle: this.angle })
    .gesture(
      RotationGesture()
        .onActionStart((event: RotationGestureEvent) => {
          console.log('Rotation start')
        })
        .onActionUpdate((event: RotationGestureEvent) => {
          this.angle = event.angle
        })
        .onActionEnd(() => {
          console.log('Rotation end')
        })
    )
  }
}
```

![](figures/RotationGesture.gif)

