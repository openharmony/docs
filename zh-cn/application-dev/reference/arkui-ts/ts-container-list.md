# List<a name="ZH-CN_TOPIC_0000001158141283"></a>

列表包含一系列相同宽度的列表项。适合连续、多行呈现同类数据，例如图片和文本。

## 权限列表<a name="section0178213104516"></a>

无

## 子组件<a name="section872315253456"></a>

包含[ListItem](ts-container-listitem.md)子组件。

## 接口<a name="section297911264713"></a>

List\(options?: \{ space?: number, initialIndex?: number \}\)

-   参数

    <a name="table1392916196212"></a>
    <table><thead align="left"><tr id="row19306191218"><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.1.6.1.1"><p id="p199307193217"><a name="p199307193217"></a><a name="p199307193217"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="15.959999999999999%" id="mcps1.1.6.1.2"><p id="p119302191128"><a name="p119302191128"></a><a name="p119302191128"></a>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.04%" id="mcps1.1.6.1.3"><p id="p7930141911211"><a name="p7930141911211"></a><a name="p7930141911211"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.88%" id="mcps1.1.6.1.4"><p id="p1393020194219"><a name="p1393020194219"></a><a name="p1393020194219"></a>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="40.01%" id="mcps1.1.6.1.5"><p id="p693061912210"><a name="p693061912210"></a><a name="p693061912210"></a>参数描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1093021911217"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p119307198218"><a name="p119307198218"></a><a name="p119307198218"></a>space</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.959999999999999%" headers="mcps1.1.6.1.2 "><p id="p129301719828"><a name="p129301719828"></a><a name="p129301719828"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.04%" headers="mcps1.1.6.1.3 "><p id="p893091913213"><a name="p893091913213"></a><a name="p893091913213"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.88%" headers="mcps1.1.6.1.4 "><p id="p029607124312"><a name="p029607124312"></a><a name="p029607124312"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.01%" headers="mcps1.1.6.1.5 "><p id="p693016198212"><a name="p693016198212"></a><a name="p693016198212"></a>列表项间距。</p>
    </td>
    </tr>
    <tr id="row1924045711917"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p72401857201915"><a name="p72401857201915"></a><a name="p72401857201915"></a>initialIndex</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.959999999999999%" headers="mcps1.1.6.1.2 "><p id="p14240957171918"><a name="p14240957171918"></a><a name="p14240957171918"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.04%" headers="mcps1.1.6.1.3 "><p id="p62402572196"><a name="p62402572196"></a><a name="p62402572196"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.88%" headers="mcps1.1.6.1.4 "><p id="p4240957101912"><a name="p4240957101912"></a><a name="p4240957101912"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.01%" headers="mcps1.1.6.1.5 "><p id="p4240145781913"><a name="p4240145781913"></a><a name="p4240145781913"></a>设置当前List初次加载时视口起始位置显示的item，即显示第一个item，如设置的序号超过了最后一个item的序号，则设置不生效。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 属性<a name="section10148192384712"></a>

<a name="table1474mcpsimp"></a>
<table><thead align="left"><tr id="row1481mcpsimp"><th class="cellrowborder" valign="top" width="14.08%" id="mcps1.1.5.1.1"><p id="p1483mcpsimp"><a name="p1483mcpsimp"></a><a name="p1483mcpsimp"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="25.46%" id="mcps1.1.5.1.2"><p id="p1485mcpsimp"><a name="p1485mcpsimp"></a><a name="p1485mcpsimp"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="15.790000000000001%" id="mcps1.1.5.1.3"><p id="p1487mcpsimp"><a name="p1487mcpsimp"></a><a name="p1487mcpsimp"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="44.67%" id="mcps1.1.5.1.4"><p id="p1489mcpsimp"><a name="p1489mcpsimp"></a><a name="p1489mcpsimp"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1490mcpsimp"><td class="cellrowborder" valign="top" width="14.08%" headers="mcps1.1.5.1.1 "><p id="p1492mcpsimp"><a name="p1492mcpsimp"></a><a name="p1492mcpsimp"></a>listDirection</p>
</td>
<td class="cellrowborder" valign="top" width="25.46%" headers="mcps1.1.5.1.2 "><p id="p1494mcpsimp"><a name="p1494mcpsimp"></a><a name="p1494mcpsimp"></a><a href="#li7849892417">Axis</a></p>
</td>
<td class="cellrowborder" valign="top" width="15.790000000000001%" headers="mcps1.1.5.1.3 "><p id="p1496mcpsimp"><a name="p1496mcpsimp"></a><a name="p1496mcpsimp"></a>Vertical</p>
</td>
<td class="cellrowborder" valign="top" width="44.67%" headers="mcps1.1.5.1.4 "><p id="p17471191815396"><a name="p17471191815396"></a><a name="p17471191815396"></a>设置List组件排列方向参照<a href="#li7849892417">Axis</a>枚举说明。</p>
</td>
</tr>
<tr id="row1501mcpsimp"><td class="cellrowborder" valign="top" width="14.08%" headers="mcps1.1.5.1.1 "><p id="p1503mcpsimp"><a name="p1503mcpsimp"></a><a name="p1503mcpsimp"></a>divider</p>
</td>
<td class="cellrowborder" valign="top" width="25.46%" headers="mcps1.1.5.1.2 "><p id="p12218118141515"><a name="p12218118141515"></a><a name="p12218118141515"></a>{</p>
<p id="p255942119159"><a name="p255942119159"></a><a name="p255942119159"></a>strokeWidth: Length,</p>
<p id="p43412027131515"><a name="p43412027131515"></a><a name="p43412027131515"></a>color?:Color,</p>
<p id="p815211349155"><a name="p815211349155"></a><a name="p815211349155"></a>startMargin?: Length,</p>
<p id="p148515412150"><a name="p148515412150"></a><a name="p148515412150"></a>endMargin?: Length</p>
<p id="p1184352016391"><a name="p1184352016391"></a><a name="p1184352016391"></a>}</p>
</td>
<td class="cellrowborder" valign="top" width="15.790000000000001%" headers="mcps1.1.5.1.3 "><p id="p1507mcpsimp"><a name="p1507mcpsimp"></a><a name="p1507mcpsimp"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="44.67%" headers="mcps1.1.5.1.4 "><p id="p1509mcpsimp"><a name="p1509mcpsimp"></a><a name="p1509mcpsimp"></a>用于设置ListItem分割线样式，默认无分割线。</p>
<p id="p6920226101412"><a name="p6920226101412"></a><a name="p6920226101412"></a>strokeWidth: 分割线的线宽。</p>
<p id="p131957614154"><a name="p131957614154"></a><a name="p131957614154"></a>color: 分割线的颜色。</p>
<p id="p119577207152"><a name="p119577207152"></a><a name="p119577207152"></a>startMargin： 分割线距离列表侧边起始端的距离。</p>
<p id="p1923017271175"><a name="p1923017271175"></a><a name="p1923017271175"></a>endMargin: 分割线距离列表侧边结束端的距离。</p>
</td>
</tr>
<tr id="row1513mcpsimp"><td class="cellrowborder" valign="top" width="14.08%" headers="mcps1.1.5.1.1 "><p id="p1515mcpsimp"><a name="p1515mcpsimp"></a><a name="p1515mcpsimp"></a>editMode</p>
</td>
<td class="cellrowborder" valign="top" width="25.46%" headers="mcps1.1.5.1.2 "><p id="p1517mcpsimp"><a name="p1517mcpsimp"></a><a name="p1517mcpsimp"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="15.790000000000001%" headers="mcps1.1.5.1.3 "><p id="p20134833915"><a name="p20134833915"></a><a name="p20134833915"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="44.67%" headers="mcps1.1.5.1.4 "><p id="p1521mcpsimp"><a name="p1521mcpsimp"></a><a name="p1521mcpsimp"></a>声明当前List组件是否处于可编辑模式。</p>
</td>
</tr>
<tr id="row331042411123"><td class="cellrowborder" valign="top" width="14.08%" headers="mcps1.1.5.1.1 "><p id="p1275832125813"><a name="p1275832125813"></a><a name="p1275832125813"></a>edgeEffect</p>
</td>
<td class="cellrowborder" valign="top" width="25.46%" headers="mcps1.1.5.1.2 "><p id="p5311324191218"><a name="p5311324191218"></a><a name="p5311324191218"></a><a href="#li13407161352416">EdgeEffect</a></p>
</td>
<td class="cellrowborder" valign="top" width="15.790000000000001%" headers="mcps1.1.5.1.3 "><p id="p13275232125815"><a name="p13275232125815"></a><a name="p13275232125815"></a>Spring</p>
</td>
<td class="cellrowborder" valign="top" width="44.67%" headers="mcps1.1.5.1.4 "><p id="p1827516324585"><a name="p1827516324585"></a><a name="p1827516324585"></a>滑动效果，目前支持的滑动效果参见<a href="#li13407161352416">EdgeEffect</a>的枚举说明。</p>
</td>
</tr>
<tr id="row18775128141213"><td class="cellrowborder" valign="top" width="14.08%" headers="mcps1.1.5.1.1 "><p id="p8775122831218"><a name="p8775122831218"></a><a name="p8775122831218"></a>chainAnimation</p>
</td>
<td class="cellrowborder" valign="top" width="25.46%" headers="mcps1.1.5.1.2 "><p id="p67751028161210"><a name="p67751028161210"></a><a name="p67751028161210"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="15.790000000000001%" headers="mcps1.1.5.1.3 "><p id="p888305574219"><a name="p888305574219"></a><a name="p888305574219"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="44.67%" headers="mcps1.1.5.1.4 "><p id="p78841255154210"><a name="p78841255154210"></a><a name="p78841255154210"></a>用于设置当前list是否启用链式联动动效，开启后列表滑动以及顶部和底部拖拽时会有链式联动的效果。链式联动效果：list内的list-item间隔一定距离，在基本的滑动交互行为下，主动对象驱动从动对象进行联动，驱动效果遵循弹簧物理动效。</p>
<a name="ul1490293714519"></a><a name="ul1490293714519"></a><ul id="ul1490293714519"><li>false：不启用链式联动。</li><li>true：启用链式联动。</li></ul>
</td>
</tr>
</tbody>
</table>

-   <a name="li7849892417"></a>Axis枚举说明

    <a name="table12144170154116"></a>
    <table><thead align="left"><tr id="row1314430184118"><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p id="p1614414014416"><a name="p1614414014416"></a><a name="p1614414014416"></a>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p id="p1314415074113"><a name="p1314415074113"></a><a name="p1314415074113"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row61441505417"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p191443034117"><a name="p191443034117"></a><a name="p191443034117"></a>Vertical</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p121447017412"><a name="p121447017412"></a><a name="p121447017412"></a>纵向排列。</p>
    </td>
    </tr>
    <tr id="row20144801418"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p17145110194110"><a name="p17145110194110"></a><a name="p17145110194110"></a>Horizontal</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p171454015415"><a name="p171454015415"></a><a name="p171454015415"></a>横向排列。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   <a name="li13407161352416"></a>EdgeEffect枚举说明

    <a name="table13368194184518"></a>
    <table><thead align="left"><tr id="row163686417455"><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p id="p153688444519"><a name="p153688444519"></a><a name="p153688444519"></a>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p id="p136815414459"><a name="p136815414459"></a><a name="p136815414459"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row536834164511"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p3368164134520"><a name="p3368164134520"></a><a name="p3368164134520"></a>Spring</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p33688411457"><a name="p33688411457"></a><a name="p33688411457"></a>弹性物理动效，滑动到边缘后可以根据初始速度或通过触摸事件继续滑动一段距离，松手后回弹。</p>
    </td>
    </tr>
    <tr id="row8368154174512"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p63689444519"><a name="p63689444519"></a><a name="p63689444519"></a>None</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p1927035264510"><a name="p1927035264510"></a><a name="p1927035264510"></a>滑动到边缘后无效果。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 事件<a name="section5672149135016"></a>

<a name="table268mcpsimp"></a>
<table><thead align="left"><tr id="row274mcpsimp"><th class="cellrowborder" valign="top" width="54.11%" id="mcps1.1.3.1.1"><p id="p276mcpsimp"><a name="p276mcpsimp"></a><a name="p276mcpsimp"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="45.89%" id="mcps1.1.3.1.2"><p id="p280mcpsimp"><a name="p280mcpsimp"></a><a name="p280mcpsimp"></a>功能描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row281mcpsimp"><td class="cellrowborder" valign="top" width="54.11%" headers="mcps1.1.3.1.1 "><p id="p283mcpsimp"><a name="p283mcpsimp"></a><a name="p283mcpsimp"></a>onItemDelete(index: number) =&gt; boolean</p>
</td>
<td class="cellrowborder" valign="top" width="45.89%" headers="mcps1.1.3.1.2 "><p id="p19272193554015"><a name="p19272193554015"></a><a name="p19272193554015"></a>列表项删除时触发。</p>
</td>
</tr>
<tr id="row14368347144014"><td class="cellrowborder" valign="top" width="54.11%" headers="mcps1.1.3.1.1 "><p id="p44468559402"><a name="p44468559402"></a><a name="p44468559402"></a>onScrollIndex(firstIndex: number, lastIndex: number) =&gt; void</p>
</td>
<td class="cellrowborder" valign="top" width="45.89%" headers="mcps1.1.3.1.2 "><p id="p6369104717402"><a name="p6369104717402"></a><a name="p6369104717402"></a>当前列表显示的起始位置和终止位置发生变化时触发。</p>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>List使能可编辑模式需配合事件方法onItemDelete和ListItem的editable属性，即可编辑模式实现删除列表项功能，需满足下列三个条件：
>-   配置editMode\(true\)；
>-   绑定onItemDelete回调，回调中return true；
>-   ListItem属性editable\(true\)。

## 示例<a name="section02653368513"></a>

```
@Entry
@Component
struct ListExample {
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
  @State editFlag: boolean = false

  build() {
    Stack({ alignContent: Alignment.TopStart }) {
      Column() {
        List({ space: 20, initialIndex: 0 }) {
          ForEach(this.arr, (item) => {
            ListItem() {
              Text('' + item)
                .width('100%').height(100).fontSize(16)
                .textAlign(TextAlign.Center).borderRadius(10).backgroundColor(0xFFFFFF)
            }.editable(true)
          }, item => item)
        }
        .listDirection(Axis.Vertical) // 排列方向
        .divider({ strokeWidth: 2, color: 0xFFFFFF, startMargin: 20, endMargin: 20 }) // 每行之间的分界线
        .edgeEffect(EdgeEffect.None) // 滑动到边缘无效果
        .chainAnimation(false) // 联动特效关闭
        .onScrollIndex((firstIndex: number, lastIndex: number) => {
          console.info('first' + firstIndex)
          console.info('last' + lastIndex)
        })
        .editMode(this.editFlag)
        .onItemDelete((index: number) => {
          console.info(this.arr[index] + 'Delete')
          this.arr.splice(index, 1)
          console.info(JSON.stringify(this.arr))
          this.editFlag = false
          return true
        }).width('90%')
      }.width('100%')

      Button('edit list')
        .onClick(() => {
          this.editFlag = !this.editFlag
        }).margin({ top: 5, left: 20 })
    }.width('100%').height('100%').backgroundColor(0xDCDCDC).padding({ top: 5 })
  }
}
```

![](figures/list.gif)

