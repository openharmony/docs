# Image<a name="ZH-CN_TOPIC_0000001111581276"></a>

图片组件，用来渲染展示图片。

## 权限列表<a name="section1662116135572"></a>

ohos.permission.INTERNET（使用网络图片）

## 子组件<a name="section057112518574"></a>

无

## 接口<a name="section15735153218576"></a>

Image\(src: string | PixelMap\)

-   参数

    <a name="table1887813614528"></a>
    <table><thead align="left"><tr id="row587936175218"><th class="cellrowborder" valign="top" width="12.7%" id="mcps1.1.6.1.1"><p id="p0879369522"><a name="p0879369522"></a><a name="p0879369522"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="19.46%" id="mcps1.1.6.1.2"><p id="p1987911618521"><a name="p1987911618521"></a><a name="p1987911618521"></a>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.96%" id="mcps1.1.6.1.3"><p id="p587919613525"><a name="p587919613525"></a><a name="p587919613525"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.86%" id="mcps1.1.6.1.4"><p id="p68798645219"><a name="p68798645219"></a><a name="p68798645219"></a>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="47.02%" id="mcps1.1.6.1.5"><p id="p16879176155216"><a name="p16879176155216"></a><a name="p16879176155216"></a>参数描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row4879761529"><td class="cellrowborder" valign="top" width="12.7%" headers="mcps1.1.6.1.1 "><p id="p1187919675215"><a name="p1187919675215"></a><a name="p1187919675215"></a>src</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.46%" headers="mcps1.1.6.1.2 "><p id="p1387910665219"><a name="p1387910665219"></a><a name="p1387910665219"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.96%" headers="mcps1.1.6.1.3 "><p id="p4879126205218"><a name="p4879126205218"></a><a name="p4879126205218"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.86%" headers="mcps1.1.6.1.4 "><p id="p5879126155211"><a name="p5879126155211"></a><a name="p5879126155211"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="47.02%" headers="mcps1.1.6.1.5 "><p id="p148791165528"><a name="p148791165528"></a><a name="p148791165528"></a>图片的URI，支持本地图片和网络路径。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 属性<a name="section1749314421802"></a>

<a name="table801mcpsimp"></a>
<table><thead align="left"><tr id="row808mcpsimp"><th class="cellrowborder" valign="top" width="14.899999999999999%" id="mcps1.1.5.1.1"><p id="p810mcpsimp"><a name="p810mcpsimp"></a><a name="p810mcpsimp"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="17.62%" id="mcps1.1.5.1.2"><p id="p812mcpsimp"><a name="p812mcpsimp"></a><a name="p812mcpsimp"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="17.46%" id="mcps1.1.5.1.3"><p id="p814mcpsimp"><a name="p814mcpsimp"></a><a name="p814mcpsimp"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="50.019999999999996%" id="mcps1.1.5.1.4"><p id="p816mcpsimp"><a name="p816mcpsimp"></a><a name="p816mcpsimp"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row817mcpsimp"><td class="cellrowborder" valign="top" width="14.899999999999999%" headers="mcps1.1.5.1.1 "><p id="p819mcpsimp"><a name="p819mcpsimp"></a><a name="p819mcpsimp"></a>alt</p>
</td>
<td class="cellrowborder" valign="top" width="17.62%" headers="mcps1.1.5.1.2 "><p id="p821mcpsimp"><a name="p821mcpsimp"></a><a name="p821mcpsimp"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="17.46%" headers="mcps1.1.5.1.3 "><p id="p823mcpsimp"><a name="p823mcpsimp"></a><a name="p823mcpsimp"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="50.019999999999996%" headers="mcps1.1.5.1.4 "><p id="p825mcpsimp"><a name="p825mcpsimp"></a><a name="p825mcpsimp"></a>加载时显示的占位图。支持本地图片和网络路径。</p>
</td>
</tr>
<tr id="row826mcpsimp"><td class="cellrowborder" valign="top" width="14.899999999999999%" headers="mcps1.1.5.1.1 "><p id="p828mcpsimp"><a name="p828mcpsimp"></a><a name="p828mcpsimp"></a>objectFit</p>
</td>
<td class="cellrowborder" valign="top" width="17.62%" headers="mcps1.1.5.1.2 "><p id="p830mcpsimp"><a name="p830mcpsimp"></a><a name="p830mcpsimp"></a><a href="#li2939204152619">ImageFit</a></p>
</td>
<td class="cellrowborder" valign="top" width="17.46%" headers="mcps1.1.5.1.3 "><p id="p832mcpsimp"><a name="p832mcpsimp"></a><a name="p832mcpsimp"></a>Cover</p>
</td>
<td class="cellrowborder" valign="top" width="50.019999999999996%" headers="mcps1.1.5.1.4 "><p id="p834mcpsimp"><a name="p834mcpsimp"></a><a name="p834mcpsimp"></a>设置图片的缩放类型。</p>
</td>
</tr>
<tr id="row93570531925"><td class="cellrowborder" valign="top" width="14.899999999999999%" headers="mcps1.1.5.1.1 "><p id="p183571853522"><a name="p183571853522"></a><a name="p183571853522"></a>objectRepeat</p>
</td>
<td class="cellrowborder" valign="top" width="17.62%" headers="mcps1.1.5.1.2 "><p id="p2035720532211"><a name="p2035720532211"></a><a name="p2035720532211"></a><a href="ts-appendix-enums.md#section5656191941718">ImageRepeat</a></p>
</td>
<td class="cellrowborder" valign="top" width="17.46%" headers="mcps1.1.5.1.3 "><p id="p103571153928"><a name="p103571153928"></a><a name="p103571153928"></a>NoRepeat</p>
</td>
<td class="cellrowborder" valign="top" width="50.019999999999996%" headers="mcps1.1.5.1.4 "><p id="p8811191510314"><a name="p8811191510314"></a><a name="p8811191510314"></a>设置图片的重复样式。</p>
<div class="note" id="note023191635"><a name="note023191635"></a><a name="note023191635"></a><span class="notetitle"> 说明： </span><div class="notebody"><a name="ul1567102713310"></a><a name="ul1567102713310"></a><ul id="ul1567102713310"><li>SVG类型图源不支持该属性。</li></ul>
</div></div>
</td>
</tr>
<tr id="row8918174518319"><td class="cellrowborder" valign="top" width="14.899999999999999%" headers="mcps1.1.5.1.1 "><p id="p1691918451033"><a name="p1691918451033"></a><a name="p1691918451033"></a>interpolation</p>
</td>
<td class="cellrowborder" valign="top" width="17.62%" headers="mcps1.1.5.1.2 "><p id="p0919184514310"><a name="p0919184514310"></a><a name="p0919184514310"></a><a href="#li3882486263">ImageInterpolation</a></p>
</td>
<td class="cellrowborder" valign="top" width="17.46%" headers="mcps1.1.5.1.3 "><p id="p149191945735"><a name="p149191945735"></a><a name="p149191945735"></a>None</p>
</td>
<td class="cellrowborder" valign="top" width="50.019999999999996%" headers="mcps1.1.5.1.4 "><p id="p4919204517316"><a name="p4919204517316"></a><a name="p4919204517316"></a>设置图片的插值效果，仅针对图片放大插值。</p>
<div class="note" id="note172111343148"><a name="note172111343148"></a><a name="note172111343148"></a><span class="notetitle"> 说明： </span><div class="notebody"><a name="ul16158175015412"></a><a name="ul16158175015412"></a><ul id="ul16158175015412"><li>SVG类型图源不支持该属性。</li><li>PixelMap资源不支持该属性。</li></ul>
</div></div>
</td>
</tr>
<tr id="row882594557"><td class="cellrowborder" valign="top" width="14.899999999999999%" headers="mcps1.1.5.1.1 "><p id="p28251847517"><a name="p28251847517"></a><a name="p28251847517"></a>renderMode</p>
</td>
<td class="cellrowborder" valign="top" width="17.62%" headers="mcps1.1.5.1.2 "><p id="p18250416511"><a name="p18250416511"></a><a name="p18250416511"></a><a href="#li174151754162611">ImageRenderMode</a></p>
</td>
<td class="cellrowborder" valign="top" width="17.46%" headers="mcps1.1.5.1.3 "><p id="p482534252"><a name="p482534252"></a><a name="p482534252"></a>Original</p>
</td>
<td class="cellrowborder" valign="top" width="50.019999999999996%" headers="mcps1.1.5.1.4 "><p id="p882564056"><a name="p882564056"></a><a name="p882564056"></a>设置图片渲染的模式。</p>
<div class="note" id="note86719241255"><a name="note86719241255"></a><a name="note86719241255"></a><span class="notetitle"> 说明： </span><div class="notebody"><a name="ul161481435653"></a><a name="ul161481435653"></a><ul id="ul161481435653"><li>SVG类型图源不支持该属性。</li></ul>
</div></div>
</td>
</tr>
<tr id="row133724010510"><td class="cellrowborder" valign="top" width="14.899999999999999%" headers="mcps1.1.5.1.1 "><p id="p333724020515"><a name="p333724020515"></a><a name="p333724020515"></a>sourceSize</p>
</td>
<td class="cellrowborder" valign="top" width="17.62%" headers="mcps1.1.5.1.2 "><p id="p518714164588"><a name="p518714164588"></a><a name="p518714164588"></a>{</p>
<p id="p9341323185811"><a name="p9341323185811"></a><a name="p9341323185811"></a>width: number,</p>
<p id="p147301427185813"><a name="p147301427185813"></a><a name="p147301427185813"></a>height: number</p>
<p id="p133373401516"><a name="p133373401516"></a><a name="p133373401516"></a>}</p>
</td>
<td class="cellrowborder" valign="top" width="17.46%" headers="mcps1.1.5.1.3 "><p id="p193378403511"><a name="p193378403511"></a><a name="p193378403511"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="50.019999999999996%" headers="mcps1.1.5.1.4 "><p id="p183371140553"><a name="p183371140553"></a><a name="p183371140553"></a>设置图片解码尺寸，将原始图片解码成指定尺寸的图片，number类型单位为px。</p>
<div class="note" id="note374810206156"><a name="note374810206156"></a><a name="note374810206156"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="p2748162014159"><a name="p2748162014159"></a><a name="p2748162014159"></a>PixelMap资源不支持该属性。</p>
</div></div>
</td>
</tr>
</tbody>
</table>

-   <a name="li2939204152619"></a>ImageFit枚举说明

    <a name="table3635183673819"></a>
    <table><thead align="left"><tr id="row26364363382"><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p id="p1963653633810"><a name="p1963653633810"></a><a name="p1963653633810"></a>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p id="p166366362387"><a name="p166366362387"></a><a name="p166366362387"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row11636193673815"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p13636193653819"><a name="p13636193653819"></a><a name="p13636193653819"></a>Cover</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p7636103615383"><a name="p7636103615383"></a><a name="p7636103615383"></a>保持宽高比进行缩小或者放大，使得图片两边都大于或等于显示边界。</p>
    </td>
    </tr>
    <tr id="row1163613615385"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p4636183653810"><a name="p4636183653810"></a><a name="p4636183653810"></a>Contain</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p10636123618385"><a name="p10636123618385"></a><a name="p10636123618385"></a>保持宽高比进行缩小或者放大，使得图片完全显示在显示边界内。</p>
    </td>
    </tr>
    <tr id="row363613613816"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p263693683810"><a name="p263693683810"></a><a name="p263693683810"></a>Fill</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p2636153673812"><a name="p2636153673812"></a><a name="p2636153673812"></a>不保持宽高比进行放大缩小，使得图片填充满显示边界。</p>
    </td>
    </tr>
    <tr id="row146361036123817"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p1636436173817"><a name="p1636436173817"></a><a name="p1636436173817"></a>None</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p163603611385"><a name="p163603611385"></a><a name="p163603611385"></a>保持原有尺寸显示。通常配合objectRepeat属性一起使用。</p>
    </td>
    </tr>
    <tr id="row263683611380"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p12636236143812"><a name="p12636236143812"></a><a name="p12636236143812"></a>ScaleDown</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p1463619364382"><a name="p1463619364382"></a><a name="p1463619364382"></a>保持宽高比显示，图片缩小或者保持不变。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   <a name="li3882486263"></a>ImageInterpolation枚举说明

    <a name="table83091251143820"></a>
    <table><thead align="left"><tr id="row1731016514381"><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p id="p163102513385"><a name="p163102513385"></a><a name="p163102513385"></a>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p id="p3310651133812"><a name="p3310651133812"></a><a name="p3310651133812"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row17310165193813"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p163101951123820"><a name="p163101951123820"></a><a name="p163101951123820"></a>None</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p03108513383"><a name="p03108513383"></a><a name="p03108513383"></a>不使用插值图片数据。</p>
    </td>
    </tr>
    <tr id="row14310175113810"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p2031065117389"><a name="p2031065117389"></a><a name="p2031065117389"></a>High</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p15310115111387"><a name="p15310115111387"></a><a name="p15310115111387"></a>高度使用插值图片数据，可能会影响图片渲染的速度。</p>
    </td>
    </tr>
    <tr id="row163101851163819"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p83101151203811"><a name="p83101151203811"></a><a name="p83101151203811"></a>Medium</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p123101251123817"><a name="p123101251123817"></a><a name="p123101251123817"></a>中度使用插值图片数据。</p>
    </td>
    </tr>
    <tr id="row20310205123811"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p11310751173812"><a name="p11310751173812"></a><a name="p11310751173812"></a>Low</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p63101451153820"><a name="p63101451153820"></a><a name="p63101451153820"></a>低度使用插值图片数据。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   <a name="li174151754162611"></a>ImageRenderMode枚举说明

    <a name="table194261554384"></a>
    <table><thead align="left"><tr id="row174260551387"><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p id="p204261755173813"><a name="p204261755173813"></a><a name="p204261755173813"></a>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p id="p1442665593817"><a name="p1442665593817"></a><a name="p1442665593817"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row15426115543812"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p34269556383"><a name="p34269556383"></a><a name="p34269556383"></a>Original</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p442625511387"><a name="p442625511387"></a><a name="p442625511387"></a>按照原图进行渲染，包括颜色。</p>
    </td>
    </tr>
    <tr id="row134261455143818"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p154265557384"><a name="p154265557384"></a><a name="p154265557384"></a>Template</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p7426355163815"><a name="p7426355163815"></a><a name="p7426355163815"></a>将图像渲染为模板图像，忽略图片的颜色信息。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 事件<a name="section68973361117"></a>

<a name="table872mcpsimp"></a>
<table><thead align="left"><tr id="row878mcpsimp"><th class="cellrowborder" colspan="2" valign="top" id="mcps1.1.4.1.1"><p id="p882mcpsimp"><a name="p882mcpsimp"></a><a name="p882mcpsimp"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.4.1.2"><p id="p884mcpsimp"><a name="p884mcpsimp"></a><a name="p884mcpsimp"></a>功能描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row885mcpsimp"><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p id="p6075115471"><a name="p6075115471"></a><a name="p6075115471"></a>onComplete(callback: (event?: { width: number, height: number, componentWidth: number, componentHeight: number, loadingStatus: number }) =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p891mcpsimp"><a name="p891mcpsimp"></a><a name="p891mcpsimp"></a>图片成功加载时触发该回调，返回成功加载的图源尺寸。</p>
</td>
</tr>
<tr id="row892mcpsimp"><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p id="p894mcpsimp"><a name="p894mcpsimp"></a><a name="p894mcpsimp"></a>onError(callback: (event?: { componentWidth: number, componentHeight: number }) =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p898mcpsimp"><a name="p898mcpsimp"></a><a name="p898mcpsimp"></a>图片加载出现异常时触发该回调。</p>
</td>
</tr>
<tr id="row190418159260"><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p id="p1490411519261"><a name="p1490411519261"></a><a name="p1490411519261"></a>onFinish(callback: () =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p190501532618"><a name="p190501532618"></a><a name="p190501532618"></a>当加载的源文件为带动效的svg图片时，当svg动效播放完成时会触发这个回调，如果动效为无限循环动效，则不会触发这个回调。</p>
</td>
</tr>
</tbody>
</table>

## 示例<a name="section6664181981216"></a>

```
// Image1
@Entry
@Component
struct ImageExample1 {
  private on: string = 'http://uxd.rnd.huawei.com/uxIcon/file/2021-08/d2d6e6c6-043f-471e-80e3-57199142201e.svg'
  @State src: string = this.on

  build() {
    Column() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Start }) {
        Text('default').fontSize(16).fontColor(0xcccccc).height(30)
        Row({ space: 5 }) {
          Image($r('app.media.ic_png'))
            .width(110).height(110).border({ width: 1 }).borderStyle(BorderStyle.Dashed)
            .overlay('png', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
          Image($r('app.media.ic_gif'))
            .width(110).height(110).border({ width: 1 }).borderStyle(BorderStyle.Dashed)
            .overlay('gif', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
          Image($r('app.media.ic_svg'))
            .width(110).height(110).border({ width: 1 }).borderStyle(BorderStyle.Dashed)
            .overlay('svg', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
        }
        Row({ space: 5 }) {
          Image($r('app.media.img_example'))
            .width(110).height(110).border({ width: 1 }).borderStyle(BorderStyle.Dashed)
            .overlay('jpg', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
          Image(this.src)
            .width(110).height(110).border({ width: 1 }).borderStyle(BorderStyle.Dashed)
            .overlay('network', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
        }.margin({ top: 25, bottom: 10 })
      }

      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Start }) {
        Text('objectFit').fontSize(16).fontColor(0xcccccc).height(30)
        Row({ space: 5 }) {
          Image($r('app.media.img_example'))
            .border({ width: 1 }).borderStyle(BorderStyle.Dashed)
            .objectFit(ImageFit.None).width(110).height(110)
            .overlay('None', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
          Image($r('app.media.img_example'))
            .border({ width: 1 }).borderStyle(BorderStyle.Dashed)
            .objectFit(ImageFit.Fill).width(110).height(110)
            .overlay('Fill', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
          Image($r('app.media.img_example'))
            .border({ width: 1 }).borderStyle(BorderStyle.Dashed)
            .objectFit(ImageFit.Cover).width(110).height(110)
            .overlay('Cover', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
        }
        Row({ space: 5 }) {
          Image($r('app.media.img_example_w250'))
            .border({ width: 1 }).borderStyle(BorderStyle.Dashed)
            .objectFit(ImageFit.Contain).width(110).height(110)
            .overlay('Contain', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
          Image($r('app.media.img_example_w250'))
            .border({ width: 1 }).borderStyle(BorderStyle.Dashed)
            .objectFit(ImageFit.ScaleDown).width(110).height(110)
            .overlay('ScaleDown', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
        }.margin({ top: 25 })
      }
    }.height(320).width(360).padding({ right: 10, top: 10 })
  }
}
```

![](figures/Image1.gif)

```
// Image2
@Entry
@Component
struct ImageExample2 {
  @State width: number = 100
  @State height: number = 100

  build() {
    Column({ space: 10 }) {
      Text('renderMode').fontSize(12).fontColor(0xcccccc).width('96%').height(30)
      Row({ space: 50 }) {
        Image($r('app.media.img_example'))
          .renderMode(ImageRenderMode.Original).width(100).height(100)
          .border({ width: 1 }).borderStyle(BorderStyle.Dashed)
          .overlay('Original', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
        Image($r('app.media.img_example'))
          .renderMode(ImageRenderMode.Template).width(100).height(100)
          .border({ width: 1 }).borderStyle(BorderStyle.Dashed)
          .overlay('Template', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
      }

      Text('alt').fontSize(12).fontColor(0xcccccc).width('96%').height(30)
      Image('')
        .alt($r('app.media.Image_none'))
        .width(100).height(100).border({ width: 1 }).borderStyle(BorderStyle.Dashed)

      Text('sourceSize').fontSize(12).fontColor(0xcccccc).width('96%')
      Row({ space: 50 }) {
        Image($r('app.media.img_example'))
          .sourceSize({
            width: 150,
            height: 150
          })
          .objectFit(ImageFit.ScaleDown).width('25%').aspectRatio(1)
          .border({ width: 1 }).borderStyle(BorderStyle.Dashed)
          .overlay('w:150 h:150', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
        Image($r('app.media.img_example'))
          .sourceSize({
            width: 200,
            height: 200
          })
          .objectFit(ImageFit.ScaleDown).width('25%').aspectRatio(1)
          .border({ width: 1 }).borderStyle(BorderStyle.Dashed)
          .overlay('w:200 h:200', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
      }

      Text('objectRepeat').fontSize(12).fontColor(0xcccccc).width('96%').height(30)
      Row({ space: 5 }) {
        Image($r('app.media.ic_health_heart'))
          .width(120).height(125).border({ width: 1 }).borderStyle(BorderStyle.Dashed)
          .objectRepeat(ImageRepeat.XY).objectFit(ImageFit.ScaleDown)
          .overlay('ImageRepeat.XY', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
        Image($r('app.media.ic_health_heart'))
          .width(110).height(125).border({ width: 1 }).borderStyle(BorderStyle.Dashed)
          .objectRepeat(ImageRepeat.Y).objectFit(ImageFit.ScaleDown)
          .overlay('ImageRepeat.Y', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
        Image($r('app.media.ic_health_heart'))
          .width(110).height(125).border({ width: 1 }).borderStyle(BorderStyle.Dashed)
          .objectRepeat(ImageRepeat.X).objectFit(ImageFit.ScaleDown)
          .overlay('ImageRepeat.X', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
      }
    }.height(150).width('100%').padding({ right: 10 })
  }
}
```

![](figures/Image2.gif)

```
// Image3
@Entry
@Component
struct ImageExample3 {
  @State width: number = 0
  @State height: number = 0
  private on: Resource = $r('app.media.wifi_on')
  private off: Resource = $r('app.media.wifi_off')
  private on2off: Resource = $r('app.media.wifi_on2off')
  private off2on: Resource = $r('app.media.wifi_off2on')
  @State src: Resource = this.on

  build() {
    Column() {
      Row({ space: 20 }) {
        Column() {
          Image($r('app.media.img_example1'))
            .alt($r('app.media.ic_public_picture'))
            .sourceSize({
              width: 900,
              height: 900
            })
            .objectFit(ImageFit.Cover)
            .height(180).width(180)
            .onComplete((msg: { width: number,height: number }) => {
              this.width = msg.width
              this.height = msg.height
            })
            .onError(() => {
              console.log('load image fail')
            })
            .overlay('\nwidth: ' + String(this.width) + ' height: ' + String(this.height), {
              align: Alignment.Bottom,
              offset: { x: 0, y: 20 }
            })
        }

        Image(this.src)
          .width(120).height(120)
          .onClick(() => {
            if (this.src == this.on || this.src == this.off2on) {
              this.src = this.on2off
            } else {
              this.src = this.off2on
            }
          })
          .onFinish(() => {
            if (this.src == this.off2on) {
              this.src = this.on
            } else {
              this.src = this.off
            }
          })
      }
    }.width('100%')
  }
}
```

![](figures/Image3.gif)

