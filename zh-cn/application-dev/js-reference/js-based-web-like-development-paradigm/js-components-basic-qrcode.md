# qrcode<a name="ZH-CN_TOPIC_0000001127284846"></a>

生成并显示二维码。

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从API Version 5 开始支持。

## 权限列表<a name="section11257113618419"></a>

无

## 子组件<a name="section352513155564"></a>

不支持。

## 属性<a name="section5347151165210"></a>

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
<tbody><tr id="row126185265127"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p024862891210"><a name="p024862891210"></a><a name="p024862891210"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p12248142813120"><a name="p12248142813120"></a><a name="p12248142813120"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p124815283126"><a name="p124815283126"></a><a name="p124815283126"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p1248102811127"><a name="p1248102811127"></a><a name="p1248102811127"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p3248828131212"><a name="p3248828131212"></a><a name="p3248828131212"></a>用来生成二维码的内容。</p>
</td>
</tr>
<tr id="row15957823161214"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p1248142816121"><a name="p1248142816121"></a><a name="p1248142816121"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p4248528121210"><a name="p4248528121210"></a><a name="p4248528121210"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p924814288126"><a name="p924814288126"></a><a name="p924814288126"></a>rect</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p162481828101210"><a name="p162481828101210"></a><a name="p162481828101210"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p2248182810126"><a name="p2248182810126"></a><a name="p2248182810126"></a>二维码类型。可能选项有：</p>
<a name="ul19772143474918"></a><a name="ul19772143474918"></a><ul id="ul19772143474918"><li>rect：矩形二维码。</li><li>circle：圆形二维码。</li></ul>
</td>
</tr>
</tbody>
</table>

## 样式<a name="section439317598552"></a>

除支持[通用样式](js-components-common-styles.md)外，还支持如下样式：

<a name="table417918285463"></a>
<table><thead align="left"><tr id="row318012811464"><th class="cellrowborder" valign="top" width="23.11768823117688%" id="mcps1.1.6.1.1"><p id="p1918014281467"><a name="p1918014281467"></a><a name="p1918014281467"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="20.477952204779523%" id="mcps1.1.6.1.2"><p id="p14180172824614"><a name="p14180172824614"></a><a name="p14180172824614"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.869113088691131%" id="mcps1.1.6.1.3"><p id="p618052814461"><a name="p618052814461"></a><a name="p618052814461"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.519248075192481%" id="mcps1.1.6.1.4"><p id="p518016281467"><a name="p518016281467"></a><a name="p518016281467"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="40.01599840015999%" id="mcps1.1.6.1.5"><p id="p10180152834613"><a name="p10180152834613"></a><a name="p10180152834613"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row718014289468"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p141800287465"><a name="p141800287465"></a><a name="p141800287465"></a>color</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p20180182824617"><a name="p20180182824617"></a><a name="p20180182824617"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="p14180162804617"><a name="p14180162804617"></a><a name="p14180162804617"></a>#000000</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p17180028144615"><a name="p17180028144615"></a><a name="p17180028144615"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p31809283467"><a name="p31809283467"></a><a name="p31809283467"></a>二维码颜色。</p>
</td>
</tr>
<tr id="row1918072894618"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p1418012818468"><a name="p1418012818468"></a><a name="p1418012818468"></a>background-color</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p181807285461"><a name="p181807285461"></a><a name="p181807285461"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="p5180162818469"><a name="p5180162818469"></a><a name="p5180162818469"></a>#ffffff</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p118022824620"><a name="p118022824620"></a><a name="p118022824620"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p11180182834614"><a name="p11180182834614"></a><a name="p11180182834614"></a>二维码背景颜色。</p>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>-   width和height不一致时，取二者较小值作为二维码的边长。且最终生成的二维码居中显示。
>-   width和height只设置一个时，取设置的值作为二维码的边长。都不设置时，使用200px作为默认边长。

## 事件<a name="section1948820711216"></a>

支持[通用事件](js-components-common-events.md)。

## 方法<a name="section2279124532420"></a>

支持[通用方法](js-components-common-methods.md)。

## 示例<a name="section81001951259"></a>

```
<!-- xxx.hml -->
<div class="container">
  <qrcode value="{{qr_value}}" type="{{qr_type}}"
  style="color: {{qr_col}};background-color: {{qr_bcol}};width: {{qr_size}};height: {{qr_size}};margin-bottom: 70px;"></qrcode>
  <text class="txt">Type</text>
  <switch showtext="true" checked="true" texton="rect" textoff="circle" onchange="settype"></switch>
  <text class="txt">Color</text>
  <select onchange="setcol">
    <option for="{{col_list}}" value="{{$item}}">{{$item}}</option>
  </select>
  <text class="txt">Background Color</text>
  <select onchange="setbcol">
    <option for="{{bcol_list}}" value="{{$item}}">{{$item}}</option>
  </select>
</div>
```

```
/* xxx.css */
.container {
  width: 100%;
  height: 100%;
  flex-direction: column;
  justify-content: center;
  align-items: center;
}
.txt {
  margin: 30px;
  color: orangered;
}
select{
  margin-top: 40px;
  margin-bottom: 40px;
}
```

```
/* index.js */
export default {
  data: {
    qr_type: 'rect',
    qr_size: '300px',
    qr_col: '#87ceeb',
    col_list: ['#87ceeb','#fa8072','#da70d6','#80ff00ff','#00ff00ff'],
    qr_bcol: '#f0ffff',
    bcol_list: ['#f0ffff','#ffffe0','#d8bfd8']
  },
  settype(e) {
    if (e.checked) {
      this.qr_type = 'rect'
    } else {
      this.qr_type = 'circle'
    }
  },
  setvalue(e) {
    this.qr_value = e.newValue
  },
  setcol(e) {
    this.qr_col = e.newValue
  },
  setbcol(e) {
    this.qr_bcol = e.newValue
  }
}
```

![](figures/12.gif)

