# PanGesture<a name="ZH-CN_TOPIC_0000001159378779"></a>

## 接口<a name="section710011405537"></a>

PanGesture\(options?: \{ fingers?: number, direction?: PanDirection, distance?: number \} |  [PanGestureOption](#section14214195212149)\)

-   <a name="li118312377710"></a>参数

    <a name="table10575153161116"></a>
    <table><thead align="left"><tr id="row1333463916149"><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.1.6.1.1"><p id="p14576115371112"><a name="p14576115371112"></a><a name="p14576115371112"></a>参数名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="15.959999999999999%" id="mcps1.1.6.1.2"><p id="p205771253151118"><a name="p205771253151118"></a><a name="p205771253151118"></a>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.04%" id="mcps1.1.6.1.3"><p id="p18577053171114"><a name="p18577053171114"></a><a name="p18577053171114"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.72%" id="mcps1.1.6.1.4"><p id="p657719534113"><a name="p657719534113"></a><a name="p657719534113"></a>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="46.17%" id="mcps1.1.6.1.5"><p id="p135781953191120"><a name="p135781953191120"></a><a name="p135781953191120"></a>参数描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1433516398146"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p165784532117"><a name="p165784532117"></a><a name="p165784532117"></a>fingers</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.959999999999999%" headers="mcps1.1.6.1.2 "><p id="p145782535119"><a name="p145782535119"></a><a name="p145782535119"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.04%" headers="mcps1.1.6.1.3 "><p id="p10578165318114"><a name="p10578165318114"></a><a name="p10578165318114"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.72%" headers="mcps1.1.6.1.4 "><p id="p5579165371112"><a name="p5579165371112"></a><a name="p5579165371112"></a>1</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.17%" headers="mcps1.1.6.1.5 "><p id="p205796538113"><a name="p205796538113"></a><a name="p205796538113"></a>触发滑动的最少手指数，最小为1指， 最大取值为10指。</p>
    </td>
    </tr>
    <tr id="row633543919148"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p757911530111"><a name="p757911530111"></a><a name="p757911530111"></a>direction</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.959999999999999%" headers="mcps1.1.6.1.2 "><p id="p9579153101115"><a name="p9579153101115"></a><a name="p9579153101115"></a><a href="#li204761598810">PanDirection</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="11.04%" headers="mcps1.1.6.1.3 "><p id="p7580125381120"><a name="p7580125381120"></a><a name="p7580125381120"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.72%" headers="mcps1.1.6.1.4 "><p id="p7580253131119"><a name="p7580253131119"></a><a name="p7580253131119"></a>All</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.17%" headers="mcps1.1.6.1.5 "><p id="p17580253111111"><a name="p17580253111111"></a><a name="p17580253111111"></a>设置滑动方向，此枚举值支持逻辑与(&amp;)和逻辑或（|）运算。</p>
    </td>
    </tr>
    <tr id="row8335239171414"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p5581653121118"><a name="p5581653121118"></a><a name="p5581653121118"></a>distance</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.959999999999999%" headers="mcps1.1.6.1.2 "><p id="p1158185321113"><a name="p1158185321113"></a><a name="p1158185321113"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.04%" headers="mcps1.1.6.1.3 "><p id="p145815537119"><a name="p145815537119"></a><a name="p145815537119"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.72%" headers="mcps1.1.6.1.4 "><p id="p125817535116"><a name="p125817535116"></a><a name="p125817535116"></a>5.0</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.17%" headers="mcps1.1.6.1.5 "><p id="p958285381110"><a name="p958285381110"></a><a name="p958285381110"></a>最小滑动识别距离，单位为vp。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   <a name="li204761598810"></a>PanDirection枚举说明

    <a name="table1883711211687"></a>
    <table><thead align="left"><tr id="row15837521586"><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p id="p78372213817"><a name="p78372213817"></a><a name="p78372213817"></a>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p id="p1383712211589"><a name="p1383712211589"></a><a name="p1383712211589"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row98375213817"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p188371221788"><a name="p188371221788"></a><a name="p188371221788"></a>All</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p683722111815"><a name="p683722111815"></a><a name="p683722111815"></a>所有方向可滑动。</p>
    </td>
    </tr>
    <tr id="row138371521585"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p18837162116811"><a name="p18837162116811"></a><a name="p18837162116811"></a>Horizontal</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p168372211186"><a name="p168372211186"></a><a name="p168372211186"></a>水平方向可滑动。</p>
    </td>
    </tr>
    <tr id="row6837102111810"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p283762118812"><a name="p283762118812"></a><a name="p283762118812"></a>Vertical</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p1983710219819"><a name="p1983710219819"></a><a name="p1983710219819"></a>竖直方向可滑动。</p>
    </td>
    </tr>
    <tr id="row1783772113813"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p8837521883"><a name="p8837521883"></a><a name="p8837521883"></a>Left</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p083717212811"><a name="p083717212811"></a><a name="p083717212811"></a>向左滑动。</p>
    </td>
    </tr>
    <tr id="row1283711211785"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p483710211789"><a name="p483710211789"></a><a name="p483710211789"></a>Right</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p1783711211887"><a name="p1783711211887"></a><a name="p1783711211887"></a>向右滑动。</p>
    </td>
    </tr>
    <tr id="row38371021980"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p188370211881"><a name="p188370211881"></a><a name="p188370211881"></a>Up</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p11837721381"><a name="p11837721381"></a><a name="p11837721381"></a>向上滑动。</p>
    </td>
    </tr>
    <tr id="row183710212086"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p1683752115812"><a name="p1683752115812"></a><a name="p1683752115812"></a>Down</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p58375211985"><a name="p58375211985"></a><a name="p58375211985"></a>向下滑动。</p>
    </td>
    </tr>
    <tr id="row5837421689"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p683711211081"><a name="p683711211081"></a><a name="p683711211081"></a>None</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p188371221782"><a name="p188371221782"></a><a name="p188371221782"></a>任何方向都不可滑动。</p>
    </td>
    </tr>
    </tbody>
    </table>


### PanGestureOption<a name="section14214195212149"></a>

通过PanGestureOption对象接口可以动态修改滑动手势识别器的属性，从而避免通过状态变量修改属性（状态变量修改会导致UI刷新）。

PanGestureOption\(options?: \{ fingers?: number, direction?: PanDirection, distance?: number \}\)

-   参数

    同[PanGesture](#li118312377710)参数说明。


-   接口

    <a name="table168621941175"></a>
    <table><thead align="left"><tr id="row1786219416718"><th class="cellrowborder" valign="top" width="34.31%" id="mcps1.1.3.1.1"><p id="p5862948717"><a name="p5862948717"></a><a name="p5862948717"></a>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="65.69%" id="mcps1.1.3.1.2"><p id="p486214416714"><a name="p486214416714"></a><a name="p486214416714"></a>功能描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1862134077"><td class="cellrowborder" valign="top" width="34.31%" headers="mcps1.1.3.1.1 "><p id="p118152361974"><a name="p118152361974"></a><a name="p118152361974"></a>setDirection(value: PanDirection)</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.69%" headers="mcps1.1.3.1.2 "><p id="p163641244113119"><a name="p163641244113119"></a><a name="p163641244113119"></a>设置direction属性。</p>
    </td>
    </tr>
    <tr id="row0427191513714"><td class="cellrowborder" valign="top" width="34.31%" headers="mcps1.1.3.1.1 "><p id="p54287151573"><a name="p54287151573"></a><a name="p54287151573"></a>setDistance(value: number)</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.69%" headers="mcps1.1.3.1.2 "><p id="p24283151578"><a name="p24283151578"></a><a name="p24283151578"></a>设置distance属性。</p>
    </td>
    </tr>
    <tr id="row145452115718"><td class="cellrowborder" valign="top" width="34.31%" headers="mcps1.1.3.1.1 "><p id="p204545213715"><a name="p204545213715"></a><a name="p204545213715"></a>setFingers(value: number)</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.69%" headers="mcps1.1.3.1.2 "><p id="p68029515817"><a name="p68029515817"></a><a name="p68029515817"></a>设置fingers属性。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 事件<a name="section1410875314552"></a>

<a name="table23971548825"></a>
<table><thead align="left"><tr id="row17397194810210"><th class="cellrowborder" colspan="2" valign="top" id="mcps1.1.4.1.1"><p id="p139710488218"><a name="p139710488218"></a><a name="p139710488218"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.4.1.2"><p id="p139714814218"><a name="p139714814218"></a><a name="p139714814218"></a>功能描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1239716482219"><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p id="p939715481627"><a name="p939715481627"></a><a name="p939715481627"></a>onActionStart((event?: <a href="ts-gesture-settings.md#table290mcpsimp">GestureEvent</a>) =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p19397248426"><a name="p19397248426"></a><a name="p19397248426"></a>Pan手势识别成功回调。</p>
</td>
</tr>
<tr id="row1839712484218"><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p id="p1839715484210"><a name="p1839715484210"></a><a name="p1839715484210"></a>onActionUpdate((event?: <a href="ts-gesture-settings.md#table290mcpsimp">GestureEvent</a>) =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p1939717489216"><a name="p1939717489216"></a><a name="p1939717489216"></a>Pan手势移动过程中回调。</p>
</td>
</tr>
<tr id="row73976481829"><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p id="p12397134811215"><a name="p12397134811215"></a><a name="p12397134811215"></a>onActionEnd((event?: <a href="ts-gesture-settings.md#table290mcpsimp">GestureEvent</a>) =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p10398148327"><a name="p10398148327"></a><a name="p10398148327"></a>Pan手势识别成功，手指抬起后触发回调。</p>
</td>
</tr>
<tr id="row639834815211"><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p id="p4398154814218"><a name="p4398154814218"></a><a name="p4398154814218"></a>onActionCancel(event: () =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p33985481128"><a name="p33985481128"></a><a name="p33985481128"></a>Pan手势识别成功，接收到触摸取消事件触发回调。</p>
</td>
</tr>
</tbody>
</table>

## 示例<a name="section16900453182718"></a>

```
@Entry
@Component
struct PanGestureExample {
  @State offsetX: number = 0
  @State offsetY: number = 0

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.SpaceBetween }) {
      Text('PanGesture offset:\nX: ' + this.offsetX + '\n' + 'Y: ' + this.offsetY)
    }
    .height(100).width(200).padding(20).border({ width: 1 }).margin(80)
    .translate({ x: this.offsetX, y: this.offsetY, z: 5 })
    .gesture(
      PanGesture({})
        .onActionStart((event: GestureEvent) => {
          console.info('Pan start')
        })
        .onActionUpdate((event: GestureEvent) => {
          this.offsetX = event.offsetX
          this.offsetY = event.offsetY
        })
        .onActionEnd(() => {
          console.info('Pan end')
        })
    )
  }
}
```

![](figures/PanGesture.gif)

