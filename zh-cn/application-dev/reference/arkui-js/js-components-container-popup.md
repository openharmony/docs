# popup<a name="ZH-CN_TOPIC_0000001127284822"></a>

气泡指示。在点击绑定的控件后会弹出相应的气泡提示来引导用户进行操作。

## 权限列表<a name="section11257113618419"></a>

无

## 子组件<a name="s726c642d8f514b0cb5ef8854fe6ac02c"></a>

支持单个子组件节点<sup>5+</sup>。

## 属性<a name="s7ff9da9346504b11aca7015dc689dc67"></a>

除支持[通用属性](js-components-common-attributes.md)外，还支持如下属性：↵

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
<tbody><tr id="row679154543116"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p15904153153119"><a name="p15904153153119"></a><a name="p15904153153119"></a>target</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p6904205312310"><a name="p6904205312310"></a><a name="p6904205312310"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p79041853123118"><a name="p79041853123118"></a><a name="p79041853123118"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p4904153173110"><a name="p4904153173110"></a><a name="p4904153173110"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p9904155363115"><a name="p9904155363115"></a><a name="p9904155363115"></a>目标元素的id属性值，不支持动态切换。</p>
</td>
</tr>
<tr id="row17485184243110"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p11904175316315"><a name="p11904175316315"></a><a name="p11904175316315"></a>placement</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p1390413531314"><a name="p1390413531314"></a><a name="p1390413531314"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p390465317319"><a name="p390465317319"></a><a name="p390465317319"></a>bottom</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p1990415317319"><a name="p1990415317319"></a><a name="p1990415317319"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p1990410531316"><a name="p1990410531316"></a><a name="p1990410531316"></a>弹出窗口位置。可选值为：</p>
<a name="ul1190565393119"></a><a name="ul1190565393119"></a><ul id="ul1190565393119"><li>left：位于目标元素左边；</li><li>right：位于目标元素右边；</li><li>top：位于目标元素上边；</li><li>bottom：位于目标元素下边；</li><li>topLeft：位于目标元素左上角；</li><li>topRight：位于目标元素右上角；</li><li>bottomLeft：位于目标元素左下角；</li><li>bottomRight：位于目标元素右下角。</li></ul>
</td>
</tr>
<tr id="row5684114975"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p156851846718"><a name="p156851846718"></a><a name="p156851846718"></a>keepalive<sup id="sup7289771114"><a name="sup7289771114"></a><a name="sup7289771114"></a><span>5+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p13685642077"><a name="p13685642077"></a><a name="p13685642077"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p16685164777"><a name="p16685164777"></a><a name="p16685164777"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p1068513410710"><a name="p1068513410710"></a><a name="p1068513410710"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p10685144771"><a name="p10685144771"></a><a name="p10685144771"></a>设置当前popup是否需要保留。设置为true时，点击屏幕区域或者页面切换气泡不会消失，需调用气泡组件的hide方法才可让气泡消失；设置为false时，点击屏幕区域或者页面切换气泡会自动消失。</p>
</td>
</tr>
<tr id="row99782190913"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p397971910920"><a name="p397971910920"></a><a name="p397971910920"></a>clickable<sup id="sup143370106114"><a name="sup143370106114"></a><a name="sup143370106114"></a><span>5+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p149793191095"><a name="p149793191095"></a><a name="p149793191095"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p197981917920"><a name="p197981917920"></a><a name="p197981917920"></a>true</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p1197914193916"><a name="p1197914193916"></a><a name="p1197914193916"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p39792192095"><a name="p39792192095"></a><a name="p39792192095"></a>popup是否使用点击弹窗，当设置为false时，只支持方法调用显示。</p>
</td>
</tr>
<tr id="row94796310119"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p174804313111"><a name="p174804313111"></a><a name="p174804313111"></a>arrowoffset<sup id="sup1520573571311"><a name="sup1520573571311"></a><a name="sup1520573571311"></a><span>5+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p1948053131110"><a name="p1948053131110"></a><a name="p1948053131110"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p6480831191117"><a name="p6480831191117"></a><a name="p6480831191117"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p8480153151112"><a name="p8480153151112"></a><a name="p8480153151112"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p548093131119"><a name="p548093131119"></a><a name="p548093131119"></a>popup箭头在弹窗处的偏移，默认居中，正值按照语言方向进行偏移，负值相反。</p>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>-   不支持focusable属性。

## 样式<a name="s472a5052130e49bca059adfe7bb6b96d"></a>

除支持[通用样式](js-components-common-styles.md)外，还支持如下样式：

<a name="table9160202272017"></a>
<table><thead align="left"><tr id="row15160122212204"><th class="cellrowborder" valign="top" width="12.688731126887312%" id="mcps1.1.6.1.1"><p id="p5160182214208"><a name="p5160182214208"></a><a name="p5160182214208"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="10.47895210478952%" id="mcps1.1.6.1.2"><p id="p0160122232018"><a name="p0160122232018"></a><a name="p0160122232018"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.60913908609139%" id="mcps1.1.6.1.3"><p id="p13160152232015"><a name="p13160152232015"></a><a name="p13160152232015"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="6.28937106289371%" id="mcps1.1.6.1.4"><p id="p101617229209"><a name="p101617229209"></a><a name="p101617229209"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="61.933806619338064%" id="mcps1.1.6.1.5"><p id="p1616162216202"><a name="p1616162216202"></a><a name="p1616162216202"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row191611622172010"><td class="cellrowborder" valign="top" width="12.688731126887312%" headers="mcps1.1.6.1.1 "><p id="p1816142292013"><a name="p1816142292013"></a><a name="p1816142292013"></a>mask-color</p>
</td>
<td class="cellrowborder" valign="top" width="10.47895210478952%" headers="mcps1.1.6.1.2 "><p id="p516152217201"><a name="p516152217201"></a><a name="p516152217201"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.60913908609139%" headers="mcps1.1.6.1.3 "><p id="p11161102218207"><a name="p11161102218207"></a><a name="p11161102218207"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="6.28937106289371%" headers="mcps1.1.6.1.4 "><p id="p8161162282014"><a name="p8161162282014"></a><a name="p8161162282014"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="61.933806619338064%" headers="mcps1.1.6.1.5 "><p id="p1416162202014"><a name="p1416162202014"></a><a name="p1416162202014"></a>遮罩层的颜色，默认值为全透明。</p>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>-   不支持position相关样式。

## 事件<a name="section1295913853210"></a>

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
<tbody><tr id="row84115915325"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p1458817720332"><a name="p1458817720332"></a><a name="p1458817720332"></a>visibilitychange</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p115888783316"><a name="p115888783316"></a><a name="p115888783316"></a>{ visibility: boolean }</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p558817173314"><a name="p558817173314"></a><a name="p558817173314"></a>当气泡弹出和消失时会触发该回调函数。</p>
</td>
</tr>
</tbody>
</table>

## 方法<a name="section1970516568131"></a>

仅支持如下方法：

<a name="table20753173210251"></a>
<table><thead align="left"><tr id="row575363214257"><th class="cellrowborder" valign="top" width="18.459999999999997%" id="mcps1.1.4.1.1"><p id="p157531032112517"><a name="p157531032112517"></a><a name="p157531032112517"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="30.769999999999996%" id="mcps1.1.4.1.2"><p id="p77531632132518"><a name="p77531632132518"></a><a name="p77531632132518"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="50.77%" id="mcps1.1.4.1.3"><p id="p147531232132512"><a name="p147531232132512"></a><a name="p147531232132512"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row15753113210251"><td class="cellrowborder" valign="top" width="18.459999999999997%" headers="mcps1.1.4.1.1 "><p id="p2314135812511"><a name="p2314135812511"></a><a name="p2314135812511"></a>show<sup id="sup969153720142"><a name="sup969153720142"></a><a name="sup969153720142"></a><span>5+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="30.769999999999996%" headers="mcps1.1.4.1.2 "><p id="p7314115819256"><a name="p7314115819256"></a><a name="p7314115819256"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.1.4.1.3 "><p id="p0314958162512"><a name="p0314958162512"></a><a name="p0314958162512"></a>弹出气泡提示。</p>
</td>
</tr>
<tr id="row393410526251"><td class="cellrowborder" valign="top" width="18.459999999999997%" headers="mcps1.1.4.1.1 "><p id="p7314358182512"><a name="p7314358182512"></a><a name="p7314358182512"></a>hide<sup id="sup16463154010141"><a name="sup16463154010141"></a><a name="sup16463154010141"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="30.769999999999996%" headers="mcps1.1.4.1.2 "><p id="p1231455814253"><a name="p1231455814253"></a><a name="p1231455814253"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.1.4.1.3 "><p id="p10314105842512"><a name="p10314105842512"></a><a name="p10314105842512"></a>取消气泡提示。</p>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>1.  popup气泡弹窗属性、样式均不支持动态更新。
>2.  popup气泡弹窗的margin样式是相对于target元素进行生效的，如popup在target元素下方，此时只生效margin-top样式，popup在target元素左上方，此时只生效margin-bottom和margin-right样式。
>3.  popup的border四边样式需一致，若四边设置不一致且圆角为零，则按左、上、右、下的顺序取第一个被设置的样式，否则border不生效。
>4.  popup的target组件的click事件不生效。

## 示例<a name="section29231018162418"></a>

```
<!-- xxx.hml -->
<div class="container">
  <text id="text">Click to show the pop-up</text>
  <!-- popup supports single child of any type5+ -->
  <popup id="popup" class="popup" target="text" placement="top" keepalive="true" clickable="true" 
    arrowoffset="100px" onvisibilitychange="visibilitychange" onclick="hidepopup">
    <text class="text">Text content of the pop-up</text>
  </popup>
  <button class="button" onclick="showpopup">Click to show the pop-up</button>
</div>
```

```
/* xxx.css */
.container {
  flex-direction: column;
  align-items: center;
  padding-top: 200px;
}
.popup {
  mask-color: gray;
}
.text {
  color: white;
}
.button {
  width: 220px;
  height: 70px;
  margin-top: 50px;
}
```

```
// xxx.js
import prompt from '@system.prompt'
export default {
  visibilitychange(e) {
    prompt.showToast({
      message: 'visibility change visibility: ' + e.visibility,
        duration: 3000,
    }); 
  },
  showpopup() {
    this.$element("popup").show();
  },
  hidepopup() {
    this.$element("popup").hide();
  },
}
```

![](figures/zh-cn_image_0000001178886129.png)

