# image<a name="ZH-CN_TOPIC_0000001173164699"></a>

图片组件，用来渲染展示图片。

## 子组件<a name="section9288143101012"></a>

不支持。

## 属性<a name="section2907183951110"></a>

除支持[通用属性](js-components-common-attributes.md)外，还支持如下属性：

<a name="table20633101642315"></a>
<table><thead align="left"><tr id="row663331618238"><th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.1"><p id="aa872998ac2d84843a3c5161889afffef"><a name="aa872998ac2d84843a3c5161889afffef"></a><a name="aa872998ac2d84843a3c5161889afffef"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.2"><p id="ab2111648ee0e4f6d881be8954e7acaab"><a name="ab2111648ee0e4f6d881be8954e7acaab"></a><a name="ab2111648ee0e4f6d881be8954e7acaab"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.48%" id="mcps1.1.6.1.3"><p id="ab377d1c90900478ea4ecab51e9a058af"><a name="ab377d1c90900478ea4ecab51e9a058af"></a><a name="ab377d1c90900478ea4ecab51e9a058af"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.6.1.4"><p id="p824610360217"><a name="p824610360217"></a><a name="p824610360217"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="35.76%" id="mcps1.1.6.1.5"><p id="a1d574a0044ed42ec8a2603bc82734232"><a name="a1d574a0044ed42ec8a2603bc82734232"></a><a name="a1d574a0044ed42ec8a2603bc82734232"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row10711153415392"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p13851942163912"><a name="p13851942163912"></a><a name="p13851942163912"></a>src</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p53851422390"><a name="p53851422390"></a><a name="p53851422390"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p193856420395"><a name="p193856420395"></a><a name="p193856420395"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p23851942103915"><a name="p23851942103915"></a><a name="p23851942103915"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p4386542163913"><a name="p4386542163913"></a><a name="p4386542163913"></a><span id="ph1386114233917"><a name="ph1386114233917"></a><a name="ph1386114233917"></a>图片的路径，支持本地路径，图片格式包括png、jpg、bmp、svg和gif。</span></p>
<p id="p2020265093811"><a name="p2020265093811"></a><a name="p2020265093811"></a>支持Base64字符串<sup id="sup792414482411"><a name="sup792414482411"></a><a name="sup792414482411"></a><span>6+</span></sup>。格式为data:image/[png | jpeg | bmp | webp];base64, [base64 data], 其中[base64 data]为Base64字符串数据。</p>
<p id="p158689315419"><a name="p158689315419"></a><a name="p158689315419"></a>支持dataability://的路径前缀，用于访问通过data ability提供的图片路径<sup id="sup1214217419478"><a name="sup1214217419478"></a><a name="sup1214217419478"></a><span>6+</span></sup>。</p>
</td>
</tr>
<tr id="row871123253917"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p11386134218396"><a name="p11386134218396"></a><a name="p11386134218396"></a>alt</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p338613422396"><a name="p338613422396"></a><a name="p338613422396"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p9386142203914"><a name="p9386142203914"></a><a name="p9386142203914"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p18386124213913"><a name="p18386124213913"></a><a name="p18386124213913"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p8386194283917"><a name="p8386194283917"></a><a name="p8386194283917"></a>占位图，当指定图片在加载中时显示。</p>
</td>
</tr>
</tbody>
</table>

## 样式<a name="section45171131134215"></a>

除支持[通用样式](js-components-common-styles.md)外，还支持如下属性：

<a name="table3635337165618"></a>
<table><thead align="left"><tr id="row163523745618"><th class="cellrowborder" valign="top" width="23.16768323167683%" id="mcps1.1.6.1.1"><p id="p763583711569"><a name="p763583711569"></a><a name="p763583711569"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="20.427957204279572%" id="mcps1.1.6.1.2"><p id="p76351837135618"><a name="p76351837135618"></a><a name="p76351837135618"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.869113088691131%" id="mcps1.1.6.1.3"><p id="p1963543714562"><a name="p1963543714562"></a><a name="p1963543714562"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.519248075192481%" id="mcps1.1.6.1.4"><p id="p163513712567"><a name="p163513712567"></a><a name="p163513712567"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="40.01599840015999%" id="mcps1.1.6.1.5"><p id="p16635113735617"><a name="p16635113735617"></a><a name="p16635113735617"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row13635143745613"><td class="cellrowborder" valign="top" width="23.16768323167683%" headers="mcps1.1.6.1.1 "><p id="p063616375563"><a name="p063616375563"></a><a name="p063616375563"></a>object-fit</p>
</td>
<td class="cellrowborder" valign="top" width="20.427957204279572%" headers="mcps1.1.6.1.2 "><p id="p563673711568"><a name="p563673711568"></a><a name="p563673711568"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="p1763616378564"><a name="p1763616378564"></a><a name="p1763616378564"></a>cover</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p1636537105617"><a name="p1636537105617"></a><a name="p1636537105617"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p186361237165612"><a name="p186361237165612"></a><a name="p186361237165612"></a>设置图片的缩放类型。可选值类型说明请见<a href="#table175851535113711">object-fit 类型说明</a>。（不支持svg格式）</p>
</td>
</tr>
<tr id="row10636173719564"><td class="cellrowborder" valign="top" width="23.16768323167683%" headers="mcps1.1.6.1.1 "><p id="p26361237195610"><a name="p26361237195610"></a><a name="p26361237195610"></a>match-text-direction</p>
</td>
<td class="cellrowborder" valign="top" width="20.427957204279572%" headers="mcps1.1.6.1.2 "><p id="p563653795612"><a name="p563653795612"></a><a name="p563653795612"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="p1636193725615"><a name="p1636193725615"></a><a name="p1636193725615"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p10636203725617"><a name="p10636203725617"></a><a name="p10636203725617"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p176361037175612"><a name="p176361037175612"></a><a name="p176361037175612"></a>图片是否跟随文字方向。（不支持svg格式）</p>
</td>
</tr>
<tr id="row17636037135618"><td class="cellrowborder" valign="top" width="23.16768323167683%" headers="mcps1.1.6.1.1 "><p id="p763614376564"><a name="p763614376564"></a><a name="p763614376564"></a>fit-original-size</p>
</td>
<td class="cellrowborder" valign="top" width="20.427957204279572%" headers="mcps1.1.6.1.2 "><p id="p18636103795617"><a name="p18636103795617"></a><a name="p18636103795617"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="p14636143719565"><a name="p14636143719565"></a><a name="p14636143719565"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p196362371564"><a name="p196362371564"></a><a name="p196362371564"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p166364377563"><a name="p166364377563"></a><a name="p166364377563"></a>image组件在未设置宽高的情况下是否适应图源尺寸（该属性为true时object-fit属性不生效），svg类型图源不支持该属性。</p>
</td>
</tr>
<tr id="row12824651173817"><td class="cellrowborder" valign="top" width="23.16768323167683%" headers="mcps1.1.6.1.1 "><p id="p782418514382"><a name="p782418514382"></a><a name="p782418514382"></a>object-position<sup id="sup2034121882110"><a name="sup2034121882110"></a><a name="sup2034121882110"></a>7+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.427957204279572%" headers="mcps1.1.6.1.2 "><p id="p15824185112385"><a name="p15824185112385"></a><a name="p15824185112385"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="p178241651103815"><a name="p178241651103815"></a><a name="p178241651103815"></a>0px 0px</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p8824165110385"><a name="p8824165110385"></a><a name="p8824165110385"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p1582420513383"><a name="p1582420513383"></a><a name="p1582420513383"></a>设置图片在组件内展示的位置。</p>
<p id="p8751515174019"><a name="p8751515174019"></a><a name="p8751515174019"></a>设置类型有两种：</p>
<p id="p19751111518408"><a name="p19751111518408"></a><a name="p19751111518408"></a>1. 像素，单位px，示例 15px 15px 代表X轴或者Y轴移动的位置</p>
<p id="p119413158218"><a name="p119413158218"></a><a name="p119413158218"></a>2. 字符，可选值：</p>
<a name="ul1815918338215"></a><a name="ul1815918338215"></a><ul id="ul1815918338215"><li>left 图片显示在组件左侧；</li><li>top 图片显示在组件顶部位置；</li><li>right 图片显示在组件右侧位置；</li><li>bottom图片显示在组件底部位置。</li></ul>
</td>
</tr>
</tbody>
</table>

**表 1**  object-fit 类型说明

<a name="table175851535113711"></a>
<table><thead align="left"><tr id="row9585183516376"><th class="cellrowborder" valign="top" width="15.02%" id="mcps1.2.3.1.1"><p id="p25851835163714"><a name="p25851835163714"></a><a name="p25851835163714"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="84.98%" id="mcps1.2.3.1.2"><p id="p1058583583717"><a name="p1058583583717"></a><a name="p1058583583717"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row658523520377"><td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.2.3.1.1 "><p id="p1558553553710"><a name="p1558553553710"></a><a name="p1558553553710"></a>cover</p>
</td>
<td class="cellrowborder" valign="top" width="84.98%" headers="mcps1.2.3.1.2 "><p id="p4585103573718"><a name="p4585103573718"></a><a name="p4585103573718"></a>保持宽高比进行缩小或者放大，使得图片两边都大于或等于显示边界，居中显示。</p>
</td>
</tr>
<tr id="row8585133543716"><td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.2.3.1.1 "><p id="p20585735123718"><a name="p20585735123718"></a><a name="p20585735123718"></a>contain</p>
</td>
<td class="cellrowborder" valign="top" width="84.98%" headers="mcps1.2.3.1.2 "><p id="p5585153523711"><a name="p5585153523711"></a><a name="p5585153523711"></a>保持宽高比进行缩小或者放大，使得图片完全显示在显示边界内，居中显示。</p>
</td>
</tr>
<tr id="row1758511351377"><td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.2.3.1.1 "><p id="p11586163511379"><a name="p11586163511379"></a><a name="p11586163511379"></a>fill</p>
</td>
<td class="cellrowborder" valign="top" width="84.98%" headers="mcps1.2.3.1.2 "><p id="p958611356373"><a name="p958611356373"></a><a name="p958611356373"></a>不保持宽高比进行放大缩小，使得图片填充满显示边界。</p>
</td>
</tr>
<tr id="row15586143520371"><td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.2.3.1.1 "><p id="p195866353376"><a name="p195866353376"></a><a name="p195866353376"></a>none</p>
</td>
<td class="cellrowborder" valign="top" width="84.98%" headers="mcps1.2.3.1.2 "><p id="p2586735113716"><a name="p2586735113716"></a><a name="p2586735113716"></a>保持原有尺寸进行居中显示。</p>
</td>
</tr>
<tr id="row165861035133718"><td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.2.3.1.1 "><p id="p195861435173720"><a name="p195861435173720"></a><a name="p195861435173720"></a>scale-down</p>
</td>
<td class="cellrowborder" valign="top" width="84.98%" headers="mcps1.2.3.1.2 "><p id="p5586835173713"><a name="p5586835173713"></a><a name="p5586835173713"></a>保持宽高比居中显示，图片缩小或者保持不变。</p>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>使用svg图片资源时：
>-   建议设置image组件的长宽，否则在父组件的长或宽为无穷大的场景下，svg资源将不会绘制；
>-   如果svg描述中未指定相应的长宽，则svg将会填满image组件区域；
>-   如果svg描述中指定了相应的长宽，和image组件本身的长宽效果如下：
>1.  如果image组件本身的长宽小于svg中的长宽，svg会被裁切，仅显示左上角部分；
>2.  如果image组件本身的长宽大于svg中的长宽，svg会被放置在image组件的左上角，image组件其他部分显示空白。

## 事件<a name="section3892191911214"></a>

除支持[通用事件](js-components-common-events.md)外，还支持如下事件：

<a name="table341925115454"></a>
<table><thead align="left"><tr id="row94208515453"><th class="cellrowborder" valign="top" width="24.91249124912491%" id="mcps1.1.4.1.1"><p id="a426b8903842d48fa8012a24ff3c997eb"><a name="a426b8903842d48fa8012a24ff3c997eb"></a><a name="a426b8903842d48fa8012a24ff3c997eb"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="29.492949294929495%" id="mcps1.1.4.1.2"><p id="a53448ba47e5e4ae9bf7774c90820e970"><a name="a53448ba47e5e4ae9bf7774c90820e970"></a><a name="a53448ba47e5e4ae9bf7774c90820e970"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="45.5945594559456%" id="mcps1.1.4.1.3"><p id="add489ff50c444f24b759162c7f4bad9a"><a name="add489ff50c444f24b759162c7f4bad9a"></a><a name="add489ff50c444f24b759162c7f4bad9a"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row370317364612"><td class="cellrowborder" valign="top" width="24.91249124912491%" headers="mcps1.1.4.1.1 "><p id="p1177515914469"><a name="p1177515914469"></a><a name="p1177515914469"></a>complete(Rich)</p>
</td>
<td class="cellrowborder" valign="top" width="29.492949294929495%" headers="mcps1.1.4.1.2 "><p id="p4775139144612"><a name="p4775139144612"></a><a name="p4775139144612"></a>{ width：width， height：height }</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p1577514934614"><a name="p1577514934614"></a><a name="p1577514934614"></a>图片成功加载时触发该回调，返回成功加载的图源尺寸。</p>
</td>
</tr>
<tr id="row8120201134610"><td class="cellrowborder" valign="top" width="24.91249124912491%" headers="mcps1.1.4.1.1 "><p id="p8775992468"><a name="p8775992468"></a><a name="p8775992468"></a>error(Rich)</p>
</td>
<td class="cellrowborder" valign="top" width="29.492949294929495%" headers="mcps1.1.4.1.2 "><p id="p107755934612"><a name="p107755934612"></a><a name="p107755934612"></a>{ width：width， height：height }</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p277510954617"><a name="p277510954617"></a><a name="p277510954617"></a>图片加载出现异常时触发该回调，异常时长宽为零。</p>
</td>
</tr>
</tbody>
</table>

## 方法<a name="section2279124532420"></a>

支持[通用方法](js-components-common-methods.md)。

## 示例<a name="section321147145519"></a>

```
<!-- xxx.hml -->
<div class="container">
  <image src="common/hw_rights.JPG" style="width: 300px; height: 300px; object-fit:{{fit}}; object-position: 0px 0px; border: 1px solid red;">
  </image>
  <select class="selects" onchange="change_fit">
    <option for="{{fits}}" value="{{$item}}">{{$item}}</option>
  </select>
</div>
```

```
/* xxx.css */
.container {
  justify-content: center;
  align-items: center;
  flex-direction: column;
}
.selects{
  margin-top: 20px;
  width:300px;
  border:1px solid #808080;
  border-radius: 10px;
}
```

```
// xxx.js
export default {
  data: {
    fit:"cover",
    fits: ["cover", "contain", "fill", "none", "scale-down"],
  },
  change_fit(e) {
    this.fit = e.newValue;
  },
}
```

![](figures/GIF.gif)

