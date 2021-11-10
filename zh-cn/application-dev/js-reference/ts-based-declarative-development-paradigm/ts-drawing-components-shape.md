# Shape<a name="ZH-CN_TOPIC_0000001119927704"></a>

绘制组件的父组件，父组件中会描述所有绘制组件均支持的通用属性。

1、绘制组件使用Shape作为父组件，实现类似SVG的效果。

2、绘制组件单独使用，用于在页面上绘制指定的图形。

## 子组件<a name="section5989144051714"></a>

可以包含子组件。

## 接口<a name="section5143192918416"></a>

Shape\(target?: PixelMap\)

-   参数

    <a name="table193606194544"></a>
    <table><thead align="left"><tr id="row536071910541"><th class="cellrowborder" valign="top" width="15.47%" id="mcps1.1.6.1.1"><p id="p436112199544"><a name="p436112199544"></a><a name="p436112199544"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.6.1.2"><p id="p19361319115410"><a name="p19361319115410"></a><a name="p19361319115410"></a>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.49%" id="mcps1.1.6.1.3"><p id="p9361201975417"><a name="p9361201975417"></a><a name="p9361201975417"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="18.6%" id="mcps1.1.6.1.4"><p id="p43611199542"><a name="p43611199542"></a><a name="p43611199542"></a>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="36.22%" id="mcps1.1.6.1.5"><p id="p1136141975419"><a name="p1136141975419"></a><a name="p1136141975419"></a>参数描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row10361101915545"><td class="cellrowborder" valign="top" width="15.47%" headers="mcps1.1.6.1.1 "><p id="p1361119155417"><a name="p1361119155417"></a><a name="p1361119155417"></a>target</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.6.1.2 "><p id="p8361181913548"><a name="p8361181913548"></a><a name="p8361181913548"></a>PixelMap</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.49%" headers="mcps1.1.6.1.3 "><p id="p153611119195411"><a name="p153611119195411"></a><a name="p153611119195411"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.6%" headers="mcps1.1.6.1.4 "><p id="p1436114193546"><a name="p1436114193546"></a><a name="p1436114193546"></a>null</p>
    </td>
    <td class="cellrowborder" valign="top" width="36.22%" headers="mcps1.1.6.1.5 "><p id="p328155017218"><a name="p328155017218"></a><a name="p328155017218"></a>绘制目标，可将图形绘制在指定的PixelMap对象中，若未设置，则在当前绘制目标中进行绘制。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 属性<a name="section922483920810"></a>

<a name="table63801556917"></a>
<table><thead align="left"><tr id="row123801259914"><th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.1"><p id="p143801852920"><a name="p143801852920"></a><a name="p143801852920"></a>参数名称</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.2"><p id="p538011511920"><a name="p538011511920"></a><a name="p538011511920"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.3"><p id="p138015518918"><a name="p138015518918"></a><a name="p138015518918"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.4"><p id="p1138018518911"><a name="p1138018518911"></a><a name="p1138018518911"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.5"><p id="p10380751296"><a name="p10380751296"></a><a name="p10380751296"></a>参数描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1638018512912"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p4380255916"><a name="p4380255916"></a><a name="p4380255916"></a>viewPort</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p111521037174418"><a name="p111521037174418"></a><a name="p111521037174418"></a>{</p>
<p id="p896417384445"><a name="p896417384445"></a><a name="p896417384445"></a>x: Length,</p>
<p id="p473118409447"><a name="p473118409447"></a><a name="p473118409447"></a>y: Length,</p>
<p id="p105591743144417"><a name="p105591743144417"></a><a name="p105591743144417"></a>width: Length,</p>
<p id="p5565104619447"><a name="p5565104619447"></a><a name="p5565104619447"></a>height: Length</p>
<p id="p63801850913"><a name="p63801850913"></a><a name="p63801850913"></a>}</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p238011519919"><a name="p238011519919"></a><a name="p238011519919"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p143801051392"><a name="p143801051392"></a><a name="p143801051392"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p73801159911"><a name="p73801159911"></a><a name="p73801159911"></a>形状的视口。</p>
</td>
</tr>
<tr id="row93801051192"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p11380258918"><a name="p11380258918"></a><a name="p11380258918"></a>fill</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p638019510914"><a name="p638019510914"></a><a name="p638019510914"></a>Color</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p238015517910"><a name="p238015517910"></a><a name="p238015517910"></a>Black</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p1380758914"><a name="p1380758914"></a><a name="p1380758914"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p1638014517919"><a name="p1638014517919"></a><a name="p1638014517919"></a>填充颜色。</p>
</td>
</tr>
<tr id="row838085692"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p53802051393"><a name="p53802051393"></a><a name="p53802051393"></a>stroke</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p2380351918"><a name="p2380351918"></a><a name="p2380351918"></a>Color</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p938114512919"><a name="p938114512919"></a><a name="p938114512919"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p13816516916"><a name="p13816516916"></a><a name="p13816516916"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p8381115194"><a name="p8381115194"></a><a name="p8381115194"></a>边框颜色。</p>
</td>
</tr>
<tr id="row17381158910"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p538125294"><a name="p538125294"></a><a name="p538125294"></a>strokeDashArray</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p7381195594"><a name="p7381195594"></a><a name="p7381195594"></a>Array<span>&lt;</span><span>Length</span><span>&gt;</span></p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p19381125790"><a name="p19381125790"></a><a name="p19381125790"></a>[]</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p2381115892"><a name="p2381115892"></a><a name="p2381115892"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p83811851592"><a name="p83811851592"></a><a name="p83811851592"></a>设置边框的间隙。</p>
</td>
</tr>
<tr id="row12381851197"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p1938114510911"><a name="p1938114510911"></a><a name="p1938114510911"></a>strokeDashOffset</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p6381653920"><a name="p6381653920"></a><a name="p6381653920"></a>Length</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p2381151893"><a name="p2381151893"></a><a name="p2381151893"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p93819515912"><a name="p93819515912"></a><a name="p93819515912"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p5381651191"><a name="p5381651191"></a><a name="p5381651191"></a>边框绘制起点的偏移量。</p>
</td>
</tr>
<tr id="row1338105290"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p13381251295"><a name="p13381251295"></a><a name="p13381251295"></a>strokeLineCap</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p19381851495"><a name="p19381851495"></a><a name="p19381851495"></a><a href="ts-appendix-enums.md#section549694781614">LineCapStyle</a></p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p103811855916"><a name="p103811855916"></a><a name="p103811855916"></a>Butt</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p33811151597"><a name="p33811151597"></a><a name="p33811151597"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p538112518918"><a name="p538112518918"></a><a name="p538112518918"></a>路径端点绘制样式。</p>
</td>
</tr>
<tr id="row173811751092"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p138175791"><a name="p138175791"></a><a name="p138175791"></a>strokeLineJoin</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p19381105390"><a name="p19381105390"></a><a name="p19381105390"></a><a href="#li0434521283">LineJoinStyle</a></p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p153811351792"><a name="p153811351792"></a><a name="p153811351792"></a>Miter</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p9381150915"><a name="p9381150915"></a><a name="p9381150915"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p143811755916"><a name="p143811755916"></a><a name="p143811755916"></a>边框拐角绘制样式。</p>
</td>
</tr>
<tr id="row14381125798"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p838112515920"><a name="p838112515920"></a><a name="p838112515920"></a>strokeMiterLimit</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p03816516912"><a name="p03816516912"></a><a name="p03816516912"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p33811451898"><a name="p33811451898"></a><a name="p33811451898"></a>4</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p138275092"><a name="p138275092"></a><a name="p138275092"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p93821959918"><a name="p93821959918"></a><a name="p93821959918"></a>锐角绘制成斜角的极限值。</p>
</td>
</tr>
<tr id="row33821156911"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p11382151194"><a name="p11382151194"></a><a name="p11382151194"></a>strokeOpacity</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p4382951910"><a name="p4382951910"></a><a name="p4382951910"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p14382051919"><a name="p14382051919"></a><a name="p14382051919"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p15382105196"><a name="p15382105196"></a><a name="p15382105196"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p538214519913"><a name="p538214519913"></a><a name="p538214519913"></a>设置边框的不透明度。</p>
</td>
</tr>
<tr id="row103821651294"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p63821151916"><a name="p63821151916"></a><a name="p63821151916"></a>strokeWidth</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p5382851599"><a name="p5382851599"></a><a name="p5382851599"></a>Length</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p138225393"><a name="p138225393"></a><a name="p138225393"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p93821451199"><a name="p93821451199"></a><a name="p93821451199"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p1738215510917"><a name="p1738215510917"></a><a name="p1738215510917"></a>设置边框的宽度。</p>
</td>
</tr>
<tr id="row0382105693"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p11382854912"><a name="p11382854912"></a><a name="p11382854912"></a>antiAlias</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p1538225494"><a name="p1538225494"></a><a name="p1538225494"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p193825513911"><a name="p193825513911"></a><a name="p193825513911"></a>true</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p9382757911"><a name="p9382757911"></a><a name="p9382757911"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p638215590"><a name="p638215590"></a><a name="p638215590"></a>是否开启抗锯齿。</p>
</td>
</tr>
</tbody>
</table>

-   <a name="li0434521283"></a>LineJoinStyle枚举说明

    <a name="table12144170154116"></a>
    <table><thead align="left"><tr id="row1314430184118"><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p id="p1614414014416"><a name="p1614414014416"></a><a name="p1614414014416"></a>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p id="p1314415074113"><a name="p1314415074113"></a><a name="p1314415074113"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row61441505417"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p191443034117"><a name="p191443034117"></a><a name="p191443034117"></a>Bevel</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p1173613315118"><a name="p1173613315118"></a><a name="p1173613315118"></a>使用斜角连接路径段。</p>
    </td>
    </tr>
    <tr id="row20144801418"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p17145110194110"><a name="p17145110194110"></a><a name="p17145110194110"></a>Miter</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p171454015415"><a name="p171454015415"></a><a name="p171454015415"></a>使用尖角连接路径段。</p>
    </td>
    </tr>
    <tr id="row914570194112"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p714511012418"><a name="p714511012418"></a><a name="p714511012418"></a>Round</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p101451704415"><a name="p101451704415"></a><a name="p101451704415"></a>使用圆角连接路径段。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 示例<a name="section4459736105512"></a>

```
@Entry
@Component
struct ShapeExample {
  build() {
    Column({ space: 5 }) {
      Text('basic').fontSize(9).fontColor(0xCCCCCC).width(320)
      // 在Shape的(-2, -2)点绘制一个 300 * 50 带边框的矩形,颜色0x317Af7,边框颜色黑色,边框宽度4,边框间隙20,向左偏移10,尖端样式圆角,拐角样式圆角,抗锯齿(默认开启)
      // 在Shape的(-2, 58)点绘制一个 300 * 50 带边框的椭圆,颜色0x317Af7,边框颜色黑色,边框宽度4,边框间隙20,向左偏移10,尖端样式圆角,拐角样式圆角,抗锯齿(默认开启)
      // 在Shape的(-2, 118)点绘制一个 300 * 10 线段,颜色0x317Af7,边框颜色黑色,宽度4,间隙20,向左偏移10,尖端样式圆角,拐角样式圆角,抗锯齿(默认开启)
      Shape() {
        Rect().width(300).height(50)
        Ellipse().width(300).height(50).offset({ x: 0, y: 60 })
        Path().width(300).height(10).commands('M0 0 L900 0').offset({ x: 0, y: 120 })
      }
      .viewPort({ x: -2, y: -2, width: 304, height: 124 })
      .fill(0x317Af7).stroke(Color.Black).strokeWidth(4)
      .strokeDashArray([20]).strokeDashOffset(10).strokeLineCap(LineCapStyle.Round)
      .strokeLineJoin(LineJoinStyle.Round).antiAlias(true)
      // 在Shape的(-1, -1)点绘制一个 300 * 50 带边框的矩形,颜色0x317Af7,边框颜色黑色,边框宽度2
      Shape() {
        Rect().width(300).height(50)
      }.viewPort({ x: -1, y: -1, width: 302, height: 52 }).fill(0x317Af7).stroke(Color.Black).strokeWidth(2)

      Text('border').fontSize(9).fontColor(0xCCCCCC).width(320)
      // 在Shape的(0, -5)点绘制一个 300 * 10 直线,颜色0xEE8443,边框宽度10,边框间隙20
      Shape() {
        Path().width(300).height(10).commands('M0 0 L900 0')
      }.viewPort({ x: 0, y: -5, width: 300, height: 10 }).stroke(0xEE8443).strokeWidth(10).strokeDashArray([20])
      // 在Shape的(0, -5)点绘制一个 300 * 10 直线,颜色0xEE8443,边框宽度10,边框间隙20,向左偏移10
      Shape() {
        Path().width(300).height(10).commands('M0 0 L900 0')
      }
      .viewPort({ x: 0, y: -5, width: 300, height: 10 })
      .stroke(0xEE8443).strokeWidth(10).strokeDashArray([20]).strokeDashOffset(10)
      // 在Shape的(0, -5)点绘制一个 300 * 10 直线,颜色0xEE8443,边框宽度10,透明度0.5
      Shape() {
        Path().width(300).height(10).commands('M0 0 L900 0')
      }.viewPort({ x: 0, y: -5, width: 300, height: 10 }).stroke(0xEE8443).strokeWidth(10).strokeOpacity(0.5)
      // 在Shape的(0, -5)点绘制一个 300 * 10 直线,颜色0xEE8443,边框宽度10,边框间隙20,向左偏移10,尖端样式圆角
      Shape() {
        Path().width(300).height(10).commands('M0 0 L900 0')
      }
      .viewPort({ x: 0, y: -5, width: 300, height: 10 })
      .stroke(0xEE8443).strokeWidth(10).strokeDashArray([20]).strokeLineCap(LineCapStyle.Round)
      // 在Shape的(-5, -5)点绘制一个 300 * 50 带边框的矩形,颜色0x317Af7,边框宽度10,边框颜色0xEE8443,拐角样式圆角
      Shape() {
        Rect().width(300).height(50)
      }
      .viewPort({ x: -5, y: -5, width: 310, height: 60 })
      .fill(0x317Af7).stroke(0xEE8443).strokeWidth(10).strokeLineJoin(LineJoinStyle.Round)
      Shape() {
        Path().width(300).height(60).commands('M0 0 L400 0 L400 200 Z')
      }
      .viewPort({ x: -80, y: -5, width: 310, height: 100 })
      .fill(0x317Af7).stroke(0xEE8443).strokeWidth(10)
      .strokeLineJoin(LineJoinStyle.Miter).strokeMiterLimit(5)
    }.width('100%').margin({ top: 15 })
  }
}
```

![](figures/shape.gif)

