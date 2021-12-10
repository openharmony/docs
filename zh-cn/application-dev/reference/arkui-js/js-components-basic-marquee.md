# marquee<a name="ZH-CN_TOPIC_0000001173324593"></a>

跑马灯组件，用于展示一段单行滚动的文字。

## 权限列表<a name="section11257113618419"></a>

无

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
<tbody><tr id="row4159854131011"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p17480906111"><a name="p17480906111"></a><a name="p17480906111"></a>scrollamount</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p11480105116"><a name="p11480105116"></a><a name="p11480105116"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p9480809115"><a name="p9480809115"></a><a name="p9480809115"></a>6</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p1848070181110"><a name="p1848070181110"></a><a name="p1848070181110"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p164801809111"><a name="p164801809111"></a><a name="p164801809111"></a>跑马灯每次滚动时移动的最大长度。</p>
</td>
</tr>
<tr id="row66871514109"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p84809019113"><a name="p84809019113"></a><a name="p84809019113"></a>loop</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p548000141112"><a name="p548000141112"></a><a name="p548000141112"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p8480208113"><a name="p8480208113"></a><a name="p8480208113"></a>-1</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p1948090161115"><a name="p1948090161115"></a><a name="p1948090161115"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p164801031110"><a name="p164801031110"></a><a name="p164801031110"></a>跑马灯滚动的次数。如果未指定，则默认值为-1，当该值小于等于零时表示marquee将连续滚动。</p>
</td>
</tr>
<tr id="row192934491109"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p44801808116"><a name="p44801808116"></a><a name="p44801808116"></a>direction</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p114809011116"><a name="p114809011116"></a><a name="p114809011116"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p1248015019119"><a name="p1248015019119"></a><a name="p1248015019119"></a>left</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p11480150191112"><a name="p11480150191112"></a><a name="p11480150191112"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p64801707115"><a name="p64801707115"></a><a name="p64801707115"></a>设置跑马灯的文字滚动方向，可选值为left和right。</p>
</td>
</tr>
</tbody>
</table>

## 样式<a name="section14898114221220"></a>

除支持[通用样式](js-components-common-styles.md)外，还支持如下样式：

<a name="table155966253920"></a>
<table><thead align="left"><tr id="row195961025998"><th class="cellrowborder" valign="top" width="20.137986201379864%" id="mcps1.1.6.1.1"><p id="p1759616251194"><a name="p1759616251194"></a><a name="p1759616251194"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="13.968603139686032%" id="mcps1.1.6.1.2"><p id="p759613251897"><a name="p759613251897"></a><a name="p759613251897"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="18.358164183581643%" id="mcps1.1.6.1.3"><p id="p1659619251099"><a name="p1659619251099"></a><a name="p1659619251099"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.519248075192481%" id="mcps1.1.6.1.4"><p id="p45961225998"><a name="p45961225998"></a><a name="p45961225998"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="40.01599840015999%" id="mcps1.1.6.1.5"><p id="p14596142511915"><a name="p14596142511915"></a><a name="p14596142511915"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row16597162517910"><td class="cellrowborder" valign="top" width="20.137986201379864%" headers="mcps1.1.6.1.1 "><p id="p2059717251991"><a name="p2059717251991"></a><a name="p2059717251991"></a>color</p>
</td>
<td class="cellrowborder" valign="top" width="13.968603139686032%" headers="mcps1.1.6.1.2 "><p id="p75977251899"><a name="p75977251899"></a><a name="p75977251899"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="18.358164183581643%" headers="mcps1.1.6.1.3 "><p id="p859714251891"><a name="p859714251891"></a><a name="p859714251891"></a>#e5000000</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p185974256916"><a name="p185974256916"></a><a name="p185974256916"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p15973251294"><a name="p15973251294"></a><a name="p15973251294"></a>设置跑马灯中文字的文本颜色。</p>
</td>
</tr>
<tr id="row6597525594"><td class="cellrowborder" valign="top" width="20.137986201379864%" headers="mcps1.1.6.1.1 "><p id="p359710255920"><a name="p359710255920"></a><a name="p359710255920"></a>font-size</p>
</td>
<td class="cellrowborder" valign="top" width="13.968603139686032%" headers="mcps1.1.6.1.2 "><p id="p11597112510915"><a name="p11597112510915"></a><a name="p11597112510915"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="18.358164183581643%" headers="mcps1.1.6.1.3 "><p id="p45974252096"><a name="p45974252096"></a><a name="p45974252096"></a>37.5</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p359711251697"><a name="p359711251697"></a><a name="p359711251697"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p8597132516911"><a name="p8597132516911"></a><a name="p8597132516911"></a>设置跑马灯中文字的文本尺寸。</p>
</td>
</tr>
<tr id="row1859816259917"><td class="cellrowborder" valign="top" width="20.137986201379864%" headers="mcps1.1.6.1.1 "><p id="p1259882514916"><a name="p1259882514916"></a><a name="p1259882514916"></a>allow-scale</p>
</td>
<td class="cellrowborder" valign="top" width="13.968603139686032%" headers="mcps1.1.6.1.2 "><p id="p17598182515919"><a name="p17598182515919"></a><a name="p17598182515919"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="18.358164183581643%" headers="mcps1.1.6.1.3 "><p id="p145981525999"><a name="p145981525999"></a><a name="p145981525999"></a>true</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p145981252096"><a name="p145981252096"></a><a name="p145981252096"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p7598192511919"><a name="p7598192511919"></a><a name="p7598192511919"></a>设置跑马灯中文字的文本尺寸是否跟随系统设置字体缩放尺寸进行放大缩小。</p>
<div class="note" id="note185981525290"><a name="note185981525290"></a><a name="note185981525290"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="p1259842517919"><a name="p1259842517919"></a><a name="p1259842517919"></a>如果在config描述文件中针对ability配置了fontSize的config-changes标签，则应用不会重启而直接生效。</p>
</div></div>
</td>
</tr>
<tr id="row659811251296"><td class="cellrowborder" valign="top" width="20.137986201379864%" headers="mcps1.1.6.1.1 "><p id="p155983256912"><a name="p155983256912"></a><a name="p155983256912"></a>font-weight</p>
</td>
<td class="cellrowborder" valign="top" width="13.968603139686032%" headers="mcps1.1.6.1.2 "><p id="p155982251699"><a name="p155982251699"></a><a name="p155982251699"></a>number | string</p>
</td>
<td class="cellrowborder" valign="top" width="18.358164183581643%" headers="mcps1.1.6.1.3 "><p id="p16598125093"><a name="p16598125093"></a><a name="p16598125093"></a>normal</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p8598172512913"><a name="p8598172512913"></a><a name="p8598172512913"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p75985251598"><a name="p75985251598"></a><a name="p75985251598"></a>设置跑马灯中文字的字体的粗细，见<a href="js-components-basic-text.md#section5775351116">text组件font-weight的样式属性</a>。</p>
</td>
</tr>
<tr id="row155991725398"><td class="cellrowborder" valign="top" width="20.137986201379864%" headers="mcps1.1.6.1.1 "><p id="p1359915259911"><a name="p1359915259911"></a><a name="p1359915259911"></a>font-family</p>
</td>
<td class="cellrowborder" valign="top" width="13.968603139686032%" headers="mcps1.1.6.1.2 "><p id="p17599112517917"><a name="p17599112517917"></a><a name="p17599112517917"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="18.358164183581643%" headers="mcps1.1.6.1.3 "><p id="p115993251911"><a name="p115993251911"></a><a name="p115993251911"></a>sans-serif</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p145994259915"><a name="p145994259915"></a><a name="p145994259915"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p1459972510914"><a name="p1459972510914"></a><a name="p1459972510914"></a>设置跑马灯中文字的字体列表，用逗号分隔，每个字体用字体名或者字体族名设置。列表中第一个系统中存在的或者通过<a href="js-components-common-customizing-font.md">自定义字体</a>指定的字体，会被选中作为文本的字体。</p>
</td>
</tr>
</tbody>
</table>

## 事件<a name="section3892191911214"></a>

除支持[通用事件](js-components-common-events.md)外，还支持如下事件：

<a name="table84827284164"></a>
<table><thead align="left"><tr id="row8483172891613"><th class="cellrowborder" valign="top" width="24.852485248524854%" id="mcps1.1.4.1.1"><p id="a426b8903842d48fa8012a24ff3c997eb"><a name="a426b8903842d48fa8012a24ff3c997eb"></a><a name="a426b8903842d48fa8012a24ff3c997eb"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="29.552955295529554%" id="mcps1.1.4.1.2"><p id="a53448ba47e5e4ae9bf7774c90820e970"><a name="a53448ba47e5e4ae9bf7774c90820e970"></a><a name="a53448ba47e5e4ae9bf7774c90820e970"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="45.5945594559456%" id="mcps1.1.4.1.3"><p id="add489ff50c444f24b759162c7f4bad9a"><a name="add489ff50c444f24b759162c7f4bad9a"></a><a name="add489ff50c444f24b759162c7f4bad9a"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row16168174591613"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p2558953141613"><a name="p2558953141613"></a><a name="p2558953141613"></a>bounce(Rich)</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p10558253161617"><a name="p10558253161617"></a><a name="p10558253161617"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p65581539160"><a name="p65581539160"></a><a name="p65581539160"></a>当文本滚动到末尾时触发该事件。</p>
</td>
</tr>
<tr id="row101671442171616"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p15585534167"><a name="p15585534167"></a><a name="p15585534167"></a>finish(Rich)</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p145584535165"><a name="p145584535165"></a><a name="p145584535165"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p18558125361620"><a name="p18558125361620"></a><a name="p18558125361620"></a>当完成滚动次数时触发该事件。需要在 loop 属性值大于 0 时触发。</p>
</td>
</tr>
<tr id="row9227173721610"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p35585536166"><a name="p35585536166"></a><a name="p35585536166"></a>start(Rich)</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p5558115318166"><a name="p5558115318166"></a><a name="p5558115318166"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p1955817532168"><a name="p1955817532168"></a><a name="p1955817532168"></a>当文本滚动开始时触发该事件。</p>
</td>
</tr>
</tbody>
</table>

## 方法<a name="section47669296127"></a>

除支持[通用方法](js-components-common-methods.md)外，还支持如下方法：

<a name="ta27ae6832ab647a880ab27801368ec17"></a>
<table><thead align="left"><tr id="r00746cc3f4244fd7bf405d1640b42842"><th class="cellrowborder" valign="top" width="16.689999999999998%" id="mcps1.1.4.1.1"><p id="a6853bf471a534d9185a46033e5301a3c"><a name="a6853bf471a534d9185a46033e5301a3c"></a><a name="a6853bf471a534d9185a46033e5301a3c"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="6.5600000000000005%" id="mcps1.1.4.1.2"><p id="a2f6b46265ccd412b8be977c934e2e06e"><a name="a2f6b46265ccd412b8be977c934e2e06e"></a><a name="a2f6b46265ccd412b8be977c934e2e06e"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="76.75%" id="mcps1.1.4.1.3"><p id="ab97e815e4f734c4290f4f7cb608e45d4"><a name="ab97e815e4f734c4290f4f7cb608e45d4"></a><a name="ab97e815e4f734c4290f4f7cb608e45d4"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="rfd984b5dab4c419fb56fb95b53614076"><td class="cellrowborder" valign="top" width="16.689999999999998%" headers="mcps1.1.4.1.1 "><p id="a650170fd03b64d42894295d360ad74dd"><a name="a650170fd03b64d42894295d360ad74dd"></a><a name="a650170fd03b64d42894295d360ad74dd"></a>start</p>
</td>
<td class="cellrowborder" valign="top" width="6.5600000000000005%" headers="mcps1.1.4.1.2 "><p id="a634a82d9b27a449891db2c1e04622259"><a name="a634a82d9b27a449891db2c1e04622259"></a><a name="a634a82d9b27a449891db2c1e04622259"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="76.75%" headers="mcps1.1.4.1.3 "><p id="a8ab976e5b8344f9b9849843a5b30128a"><a name="a8ab976e5b8344f9b9849843a5b30128a"></a><a name="a8ab976e5b8344f9b9849843a5b30128a"></a>开始滚动。</p>
</td>
</tr>
<tr id="r15b7a1086fd047ea984b9cb4955dd98c"><td class="cellrowborder" valign="top" width="16.689999999999998%" headers="mcps1.1.4.1.1 "><p id="aab35a49bf5d440958734b6b30ae5c129"><a name="aab35a49bf5d440958734b6b30ae5c129"></a><a name="aab35a49bf5d440958734b6b30ae5c129"></a>stop</p>
</td>
<td class="cellrowborder" valign="top" width="6.5600000000000005%" headers="mcps1.1.4.1.2 "><p id="aaf270b3435ba4d1ba5c038066d3d08a8"><a name="aaf270b3435ba4d1ba5c038066d3d08a8"></a><a name="aaf270b3435ba4d1ba5c038066d3d08a8"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="76.75%" headers="mcps1.1.4.1.3 "><p id="a4ea339c3428f474696fe3491579ac922"><a name="a4ea339c3428f474696fe3491579ac922"></a><a name="a4ea339c3428f474696fe3491579ac922"></a>停止滚动。</p>
</td>
</tr>
</tbody>
</table>

## 示例<a name="section198211501414"></a>

```
<!-- xxx.hml -->
<div class="container">
  <marquee id="customMarquee" class="customMarquee" scrollamount="{{scrollAmount}}" loop="{{loop}}"direction="{{marqueeDir}}"
    onbounce="onMarqueeBounce" onstart="onMarqueeStart" onfinish="onMarqueeFinish">{{marqueeCustomData}}</marquee>
  <div class="content">
    <button class="controlButton" onclick="onStartClick">Start</button>
    <button class="controlButton" onclick="onStopClick">Stop</button>
  </div>
</div>
```

```
/* xxx.css */
.container {
  flex-direction: column;
  justify-content: center;
  align-items: center;
  background-color: #ffffff;
}
.customMarquee {
  width: 100%;
  height: 80px;
  padding: 10px;
  margin: 20px;
  border: 4px solid #ff8888;
  border-radius: 20px;
  font-size: 40px;
  color: #ff8888;
  font-weight: bolder;
  font-family: serif;
  background-color: #ffdddd;
}
.content {
  flex-direction: row;
}
.controlButton {
  flex-grow: 1;
  background-color: #F2F2F2;
  text-color: #0D81F2;
}
```

```
// xxx.js
export default {
  data: {
    scrollAmount: 30,
    loop: 3,
    marqueeDir: 'left',
    marqueeCustomData: 'Custom marquee',
  },
  onMarqueeBounce: function() {
    console.log("onMarqueeBounce");
  },
  onMarqueeStart: function() {
    console.log("onMarqueeStart");
  },
  onMarqueeFinish: function() {
    console.log("onMarqueeFinish");
  },
  onStartClick (evt) {
    this.$element('customMarquee').start();
  },
  onStopClick (evt) {
    this.$element('customMarquee').stop();
  }
}
```

![](figures/sample1.gif)

