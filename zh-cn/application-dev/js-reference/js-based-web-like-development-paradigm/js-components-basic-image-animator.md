# image-animator<a name="ZH-CN_TOPIC_0000001173324625"></a>

图片帧动画播放器。

## 子组件<a name="section393521619565"></a>

不支持。

## 属性<a name="section1342212415618"></a>

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
<tbody><tr id="row6678114174919"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p425710265496"><a name="p425710265496"></a><a name="p425710265496"></a>images</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p1257142694916"><a name="p1257142694916"></a><a name="p1257142694916"></a>Array&lt;ImageFrame&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p1725752654912"><a name="p1725752654912"></a><a name="p1725752654912"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p1025752610497"><a name="p1025752610497"></a><a name="p1025752610497"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p1225732612491"><a name="p1225732612491"></a><a name="p1225732612491"></a>设置图片帧信息集合。每一帧的帧信息包含图片路径、图片大小和图片位置信息。目前支持以下图片格式：png、jpg。ImageFrame的详细说明请见<a href="#table67453165913">表1</a>。</p>
<div class="note" id="note1925732612497"><a name="note1925732612497"></a><a name="note1925732612497"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="p3257226184915"><a name="p3257226184915"></a><a name="p3257226184915"></a>使用时需要使用数据绑定的方式，如images = {{images}}，js中声明相应变量：images: [{src: "/common/heart-rate01.png"}, {src: "/common/heart-rate02.png"}]。</p>
<p id="p205711340134919"><a name="p205711340134919"></a><a name="p205711340134919"></a>js中声明相应变量：images: [{src: "/common/heart-rate01.png", duration: "100"}, {src: "/common/heart-rate02.png", duration: "200"}]。支持配置每一帧图片的时长，单位毫秒。<sup id="sup1083881410267"><a name="sup1083881410267"></a><a name="sup1083881410267"></a><span>6+</span></sup></p>
</div></div>
</td>
</tr>
<tr id="row2926174817528"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p1292784811523"><a name="p1292784811523"></a><a name="p1292784811523"></a>predecode<sup id="sup31371043122616"><a name="sup31371043122616"></a><a name="sup31371043122616"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p292713488521"><a name="p292713488521"></a><a name="p292713488521"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p9927134812527"><a name="p9927134812527"></a><a name="p9927134812527"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p14927134818521"><a name="p14927134818521"></a><a name="p14927134818521"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p792704825216"><a name="p792704825216"></a><a name="p792704825216"></a>是否启用预解码，默认值为0，即不启用预解码，如该值设为2，则播放当前页时会提前加载后面两张图片至缓存以提升性能。</p>
</td>
</tr>
<tr id="row739819164910"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p16257626134912"><a name="p16257626134912"></a><a name="p16257626134912"></a>iteration</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p18257112611492"><a name="p18257112611492"></a><a name="p18257112611492"></a>number | string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p22571126184915"><a name="p22571126184915"></a><a name="p22571126184915"></a>infinite</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p14257202694917"><a name="p14257202694917"></a><a name="p14257202694917"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p22571326114916"><a name="p22571326114916"></a><a name="p22571326114916"></a>设置帧动画播放次数。number表示固定次数，infinite枚举表示无限次数播放。</p>
</td>
</tr>
<tr id="row163991791492"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p12576265493"><a name="p12576265493"></a><a name="p12576265493"></a>reverse</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p15257826194918"><a name="p15257826194918"></a><a name="p15257826194918"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p122573263499"><a name="p122573263499"></a><a name="p122573263499"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p12571626134910"><a name="p12571626134910"></a><a name="p12571626134910"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p925816262499"><a name="p925816262499"></a><a name="p925816262499"></a>设置播放顺序。false表示从第1张图片播放到最后1张图片； true表示从最后1张图片播放到第1张图片。</p>
</td>
</tr>
<tr id="row320318310493"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p425862611491"><a name="p425862611491"></a><a name="p425862611491"></a>fixedsize</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p3258182604914"><a name="p3258182604914"></a><a name="p3258182604914"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p1425852684910"><a name="p1425852684910"></a><a name="p1425852684910"></a>true</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p625862612497"><a name="p625862612497"></a><a name="p625862612497"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p7258626174910"><a name="p7258626174910"></a><a name="p7258626174910"></a>设置图片大小是否固定为组件大小。 true表示图片大小与组件大小一致，此时设置图片的width 、height 、top 和left属性是无效的。false表示每一张图片的 width 、height 、top和left属性都要单独设置。</p>
</td>
</tr>
<tr id="row168157599487"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p15258152613494"><a name="p15258152613494"></a><a name="p15258152613494"></a>duration</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p8258102610496"><a name="p8258102610496"></a><a name="p8258102610496"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p9258112654910"><a name="p9258112654910"></a><a name="p9258112654910"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p1225814262495"><a name="p1225814262495"></a><a name="p1225814262495"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p9258102684910"><a name="p9258102684910"></a><a name="p9258102684910"></a>设置单次播放时长。单位支持[s(秒)|ms(毫秒)]，默认单位为ms。 duration为0时，不播放图片。 值改变只会在下一次循环开始时生效，当images中设置了单独的duration后，该属性设置无效。</p>
</td>
</tr>
<tr id="row15460155375910"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p204611353105915"><a name="p204611353105915"></a><a name="p204611353105915"></a>fillmode<sup id="sup4224194014312"><a name="sup4224194014312"></a><a name="sup4224194014312"></a><span>5+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p1461125318597"><a name="p1461125318597"></a><a name="p1461125318597"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p11461155311592"><a name="p11461155311592"></a><a name="p11461155311592"></a>forwards</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p3461135316592"><a name="p3461135316592"></a><a name="p3461135316592"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p48661353174"><a name="p48661353174"></a><a name="p48661353174"></a>指定帧动画执行结束后的状态。可选项有：</p>
<a name="ul183656592213"></a><a name="ul183656592213"></a><ul id="ul183656592213"><li>none：恢复初始状态。</li><li>forwards：保持帧动画结束时的状态（在最后一个关键帧中定义）。</li></ul>
</td>
</tr>
</tbody>
</table>

**表 1**  ImageFrame说明

<a name="table67453165913"></a>
<table><thead align="left"><tr id="row127451816696"><th class="cellrowborder" valign="top" width="11.330000000000002%" id="mcps1.2.6.1.1"><p id="p20745516799"><a name="p20745516799"></a><a name="p20745516799"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="9.860000000000001%" id="mcps1.2.6.1.2"><p id="p6745181616919"><a name="p6745181616919"></a><a name="p6745181616919"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.810000000000002%" id="mcps1.2.6.1.3"><p id="p27452161915"><a name="p27452161915"></a><a name="p27452161915"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="10.000000000000002%" id="mcps1.2.6.1.4"><p id="p187461164918"><a name="p187461164918"></a><a name="p187461164918"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="58.00000000000001%" id="mcps1.2.6.1.5"><p id="p174651611917"><a name="p174651611917"></a><a name="p174651611917"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row974611615915"><td class="cellrowborder" valign="top" width="11.330000000000002%" headers="mcps1.2.6.1.1 "><p id="p27461616392"><a name="p27461616392"></a><a name="p27461616392"></a>src</p>
</td>
<td class="cellrowborder" valign="top" width="9.860000000000001%" headers="mcps1.2.6.1.2 "><p id="p1874612161194"><a name="p1874612161194"></a><a name="p1874612161194"></a>&lt;uri&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.2.6.1.3 "><p id="p167462161197"><a name="p167462161197"></a><a name="p167462161197"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="10.000000000000002%" headers="mcps1.2.6.1.4 "><p id="p674612161914"><a name="p674612161914"></a><a name="p674612161914"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="58.00000000000001%" headers="mcps1.2.6.1.5 "><p id="p87460161592"><a name="p87460161592"></a><a name="p87460161592"></a>图片路径<span id="ph5230045184011"><a name="ph5230045184011"></a><a name="ph5230045184011"></a>，图片格式为svg，png和jpg</span>。</p>
</td>
</tr>
<tr id="row1574611161790"><td class="cellrowborder" valign="top" width="11.330000000000002%" headers="mcps1.2.6.1.1 "><p id="p1674621619911"><a name="p1674621619911"></a><a name="p1674621619911"></a>width</p>
</td>
<td class="cellrowborder" valign="top" width="9.860000000000001%" headers="mcps1.2.6.1.2 "><p id="p4746516691"><a name="p4746516691"></a><a name="p4746516691"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.2.6.1.3 "><p id="p1874661618915"><a name="p1874661618915"></a><a name="p1874661618915"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="10.000000000000002%" headers="mcps1.2.6.1.4 "><p id="p13746161615914"><a name="p13746161615914"></a><a name="p13746161615914"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="58.00000000000001%" headers="mcps1.2.6.1.5 "><p id="p57461162915"><a name="p57461162915"></a><a name="p57461162915"></a>图片宽度。</p>
</td>
</tr>
<tr id="row1746131615914"><td class="cellrowborder" valign="top" width="11.330000000000002%" headers="mcps1.2.6.1.1 "><p id="p137467160910"><a name="p137467160910"></a><a name="p137467160910"></a>height</p>
</td>
<td class="cellrowborder" valign="top" width="9.860000000000001%" headers="mcps1.2.6.1.2 "><p id="p12285145181014"><a name="p12285145181014"></a><a name="p12285145181014"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.2.6.1.3 "><p id="p3285144571012"><a name="p3285144571012"></a><a name="p3285144571012"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="10.000000000000002%" headers="mcps1.2.6.1.4 "><p id="p728514520106"><a name="p728514520106"></a><a name="p728514520106"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="58.00000000000001%" headers="mcps1.2.6.1.5 "><p id="p1174619161998"><a name="p1174619161998"></a><a name="p1174619161998"></a>图片高度。</p>
</td>
</tr>
<tr id="row157461216990"><td class="cellrowborder" valign="top" width="11.330000000000002%" headers="mcps1.2.6.1.1 "><p id="p157461916297"><a name="p157461916297"></a><a name="p157461916297"></a>top</p>
</td>
<td class="cellrowborder" valign="top" width="9.860000000000001%" headers="mcps1.2.6.1.2 "><p id="p172301247131019"><a name="p172301247131019"></a><a name="p172301247131019"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.2.6.1.3 "><p id="p152301647141015"><a name="p152301647141015"></a><a name="p152301647141015"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="10.000000000000002%" headers="mcps1.2.6.1.4 "><p id="p15230164731016"><a name="p15230164731016"></a><a name="p15230164731016"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="58.00000000000001%" headers="mcps1.2.6.1.5 "><p id="p11863511151119"><a name="p11863511151119"></a><a name="p11863511151119"></a>图片相对于组件左上角的纵向坐标。</p>
</td>
</tr>
<tr id="row107477161396"><td class="cellrowborder" valign="top" width="11.330000000000002%" headers="mcps1.2.6.1.1 "><p id="p57474161995"><a name="p57474161995"></a><a name="p57474161995"></a>left</p>
</td>
<td class="cellrowborder" valign="top" width="9.860000000000001%" headers="mcps1.2.6.1.2 "><p id="p317644961019"><a name="p317644961019"></a><a name="p317644961019"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.2.6.1.3 "><p id="p19176154951014"><a name="p19176154951014"></a><a name="p19176154951014"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="10.000000000000002%" headers="mcps1.2.6.1.4 "><p id="p1176049201020"><a name="p1176049201020"></a><a name="p1176049201020"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="58.00000000000001%" headers="mcps1.2.6.1.5 "><p id="p191151321151111"><a name="p191151321151111"></a><a name="p191151321151111"></a>图片相对于组件左上角的横向坐标。</p>
</td>
</tr>
<tr id="row243510340595"><td class="cellrowborder" valign="top" width="11.330000000000002%" headers="mcps1.2.6.1.1 "><p id="p1643633417593"><a name="p1643633417593"></a><a name="p1643633417593"></a>duration<sup id="sup10707409460"><a name="sup10707409460"></a><a name="sup10707409460"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="9.860000000000001%" headers="mcps1.2.6.1.2 "><p id="p1643620340595"><a name="p1643620340595"></a><a name="p1643620340595"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.2.6.1.3 "><p id="p14436133455910"><a name="p14436133455910"></a><a name="p14436133455910"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="10.000000000000002%" headers="mcps1.2.6.1.4 "><p id="p5436134145916"><a name="p5436134145916"></a><a name="p5436134145916"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="58.00000000000001%" headers="mcps1.2.6.1.5 "><p id="p743613347596"><a name="p743613347596"></a><a name="p743613347596"></a>每一帧图片的播放时长，单位毫秒。</p>
</td>
</tr>
</tbody>
</table>

## 样式<a name="section1774719169253"></a>

支持[通用样式](js-components-common-styles.md)。

## 事件<a name="section17969351566"></a>

除支持[通用事件](js-components-common-events.md)外，还支持如下事件：

<a name="table836435619510"></a>
<table><thead align="left"><tr id="row153658563517"><th class="cellrowborder" valign="top" width="24.852485248524854%" id="mcps1.1.4.1.1"><p id="a426b8903842d48fa8012a24ff3c997eb"><a name="a426b8903842d48fa8012a24ff3c997eb"></a><a name="a426b8903842d48fa8012a24ff3c997eb"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="29.552955295529554%" id="mcps1.1.4.1.2"><p id="a53448ba47e5e4ae9bf7774c90820e970"><a name="a53448ba47e5e4ae9bf7774c90820e970"></a><a name="a53448ba47e5e4ae9bf7774c90820e970"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="45.5945594559456%" id="mcps1.1.4.1.3"><p id="add489ff50c444f24b759162c7f4bad9a"><a name="add489ff50c444f24b759162c7f4bad9a"></a><a name="add489ff50c444f24b759162c7f4bad9a"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row287217513517"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p2602207165111"><a name="p2602207165111"></a><a name="p2602207165111"></a>start</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p19602157185119"><a name="p19602157185119"></a><a name="p19602157185119"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p146021079518"><a name="p146021079518"></a><a name="p146021079518"></a>帧动画启动时触发。</p>
</td>
</tr>
<tr id="row0878102155118"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p1760237135118"><a name="p1760237135118"></a><a name="p1760237135118"></a>pause</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p160214745113"><a name="p160214745113"></a><a name="p160214745113"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p26027715112"><a name="p26027715112"></a><a name="p26027715112"></a>帧动画暂停时触发。</p>
</td>
</tr>
<tr id="row151519594509"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p86027735118"><a name="p86027735118"></a><a name="p86027735118"></a>stop</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p196024715513"><a name="p196024715513"></a><a name="p196024715513"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p760216735110"><a name="p760216735110"></a><a name="p760216735110"></a>帧动画结束时触发。</p>
</td>
</tr>
<tr id="row189025517507"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p4602147175120"><a name="p4602147175120"></a><a name="p4602147175120"></a>resume</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p12602137155110"><a name="p12602137155110"></a><a name="p12602137155110"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p160267105114"><a name="p160267105114"></a><a name="p160267105114"></a>帧动画恢复时触发。</p>
</td>
</tr>
</tbody>
</table>

## 方法<a name="section1428810433566"></a>

支持[通用方法](js-components-common-methods.md)外，还支持如下方法：

<a name="ta27ae6832ab647a880ab27801368ec17"></a>
<table><thead align="left"><tr id="r00746cc3f4244fd7bf405d1640b42842"><th class="cellrowborder" valign="top" width="10.89%" id="mcps1.1.4.1.1"><p id="a6853bf471a534d9185a46033e5301a3c"><a name="a6853bf471a534d9185a46033e5301a3c"></a><a name="a6853bf471a534d9185a46033e5301a3c"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="10.9%" id="mcps1.1.4.1.2"><p id="a2f6b46265ccd412b8be977c934e2e06e"><a name="a2f6b46265ccd412b8be977c934e2e06e"></a><a name="a2f6b46265ccd412b8be977c934e2e06e"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="78.21000000000001%" id="mcps1.1.4.1.3"><p id="ab97e815e4f734c4290f4f7cb608e45d4"><a name="ab97e815e4f734c4290f4f7cb608e45d4"></a><a name="ab97e815e4f734c4290f4f7cb608e45d4"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="rfd984b5dab4c419fb56fb95b53614076"><td class="cellrowborder" valign="top" width="10.89%" headers="mcps1.1.4.1.1 "><p id="a650170fd03b64d42894295d360ad74dd"><a name="a650170fd03b64d42894295d360ad74dd"></a><a name="a650170fd03b64d42894295d360ad74dd"></a>start</p>
</td>
<td class="cellrowborder" valign="top" width="10.9%" headers="mcps1.1.4.1.2 "><p id="a634a82d9b27a449891db2c1e04622259"><a name="a634a82d9b27a449891db2c1e04622259"></a><a name="a634a82d9b27a449891db2c1e04622259"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="78.21000000000001%" headers="mcps1.1.4.1.3 "><p id="a8ab976e5b8344f9b9849843a5b30128a"><a name="a8ab976e5b8344f9b9849843a5b30128a"></a><a name="a8ab976e5b8344f9b9849843a5b30128a"></a>开始播放图片帧动画。再次调用，重新从第1帧开始播放。</p>
</td>
</tr>
<tr id="r15b7a1086fd047ea984b9cb4955dd98c"><td class="cellrowborder" valign="top" width="10.89%" headers="mcps1.1.4.1.1 "><p id="aab35a49bf5d440958734b6b30ae5c129"><a name="aab35a49bf5d440958734b6b30ae5c129"></a><a name="aab35a49bf5d440958734b6b30ae5c129"></a>pause</p>
</td>
<td class="cellrowborder" valign="top" width="10.9%" headers="mcps1.1.4.1.2 "><p id="aaf270b3435ba4d1ba5c038066d3d08a8"><a name="aaf270b3435ba4d1ba5c038066d3d08a8"></a><a name="aaf270b3435ba4d1ba5c038066d3d08a8"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="78.21000000000001%" headers="mcps1.1.4.1.3 "><p id="a4ea339c3428f474696fe3491579ac922"><a name="a4ea339c3428f474696fe3491579ac922"></a><a name="a4ea339c3428f474696fe3491579ac922"></a>暂停播放图片帧动画。</p>
</td>
</tr>
<tr id="row2389173613484"><td class="cellrowborder" valign="top" width="10.89%" headers="mcps1.1.4.1.1 "><p id="p183906365481"><a name="p183906365481"></a><a name="p183906365481"></a>stop</p>
</td>
<td class="cellrowborder" valign="top" width="10.9%" headers="mcps1.1.4.1.2 "><p id="p18390193624812"><a name="p18390193624812"></a><a name="p18390193624812"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="78.21000000000001%" headers="mcps1.1.4.1.3 "><p id="p18390136184810"><a name="p18390136184810"></a><a name="p18390136184810"></a>停止播放图片帧动画。</p>
</td>
</tr>
<tr id="row2051494718486"><td class="cellrowborder" valign="top" width="10.89%" headers="mcps1.1.4.1.1 "><p id="p16514124764810"><a name="p16514124764810"></a><a name="p16514124764810"></a>resume</p>
</td>
<td class="cellrowborder" valign="top" width="10.9%" headers="mcps1.1.4.1.2 "><p id="p16515144764811"><a name="p16515144764811"></a><a name="p16515144764811"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="78.21000000000001%" headers="mcps1.1.4.1.3 "><p id="p18515847164812"><a name="p18515847164812"></a><a name="p18515847164812"></a>继续播放图片帧。</p>
</td>
</tr>
<tr id="row16356183618265"><td class="cellrowborder" valign="top" width="10.89%" headers="mcps1.1.4.1.1 "><p id="p53572364269"><a name="p53572364269"></a><a name="p53572364269"></a>getState</p>
</td>
<td class="cellrowborder" valign="top" width="10.9%" headers="mcps1.1.4.1.2 "><p id="p835743613261"><a name="p835743613261"></a><a name="p835743613261"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="78.21000000000001%" headers="mcps1.1.4.1.3 "><p id="p5357183632618"><a name="p5357183632618"></a><a name="p5357183632618"></a>获取播放状态。可能值有：</p>
<a name="ul1465819221205"></a><a name="ul1465819221205"></a><ul id="ul1465819221205"><li>playing：播放中</li><li>paused：已暂停</li><li>stopped：已停止。</li></ul>
</td>
</tr>
</tbody>
</table>

## 示例<a name="section118221913375"></a>

```
<!-- xxx.hml -->
<div class="container">
  <image-animator class="animator" ref="animator" images="{{frames}}" duration="1s" />
  <div class="btn-box">
    <input class="btn" type="button" value="start" @click="handleStart" />
    <input class="btn" type="button" value="stop" @click="handleStop" />
    <input class="btn" type="button" value="pause" @click="handlePause" />
    <input class="btn" type="button" value="resume" @click="handleResume" />
  </div>
</div>
```

```
/* xxx.css */
.container {
  flex-direction: column;
  justify-content: center;
  align-items: center;
  left: 0px;
  top: 0px;
  width: 454px;
  height: 454px;
}
.animator {
  width: 70px;
  height: 70px;
}
.btn-box {
  width: 264px;
  height: 120px;
  flex-wrap: wrap;
  justify-content: space-around;
  align-items: center;
}
.btn {
  border-radius: 8px;
  width: 120px;
  margin-top: 8px;
}
```

```
//xxx.js
export default {
  data: {
    frames: [
      {
        src: "/common/asserts/heart78.png",
      },
      {
        src: "/common/asserts/heart79.png",
      },
      {
        src: "/common/asserts/heart80.png",
      },
      {
        src: "/common/asserts/heart81.png",
      },
      {
        src: "/common/asserts/heart82.png",
      },
      {
        src: "/common/asserts/heart83.png",
      },
      {
        src: "/common/asserts/heart84.png",
      },
      {
        src: "/common/asserts/heart85.png",
      },
      {
        src: "/common/asserts/heart86.png",
      },
      {
        src: "/common/asserts/heart87.png",
      },
      {
        src: "/common/asserts/heart88.png",
      },
      {
        src: "/common/asserts/heart89.png",
      },
      {
        src: "/common/asserts/heart90.png",
      },
      {
        src: "/common/asserts/heart91.png",
      },
      {
        src: "/common/asserts/heart92.png",
      },
      {
        src: "/common/asserts/heart93.png",
      },
      {
        src: "/common/asserts/heart94.png",
      },
      {
        src: "/common/asserts/heart95.png",
      },
      {
        src: "/common/asserts/heart96.png",
      },
    ],
  },
  handleStart() {
    this.$refs.animator.start();
  },
  handlePause() {
    this.$refs.animator.pause();
  },
  handleResume() {
    this.$refs.animator.resume();
  },
  handleStop() {
    this.$refs.animator.stop();
  },
};
```

![](figures/image-animator.gif)

