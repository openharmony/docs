# search<a name="ZH-CN_TOPIC_0000001209252171"></a>

-   [子组件](#zh-cn_topic_0000001173164773_section9288143101012)
-   [属性](#zh-cn_topic_0000001173164773_section2907183951110)
-   [样式](#zh-cn_topic_0000001173164773_section5775351116)
-   [事件](#zh-cn_topic_0000001173164773_section17878123517511)
-   [方法](#zh-cn_topic_0000001173164773_section2279124532420)
-   [示例](#zh-cn_topic_0000001173164773_section586520905216)

提供搜索框组件，用于提供用户搜索内容的输入区域。

## 子组件<a name="zh-cn_topic_0000001173164773_section9288143101012"></a>

不支持。

## 属性<a name="zh-cn_topic_0000001173164773_section2907183951110"></a>

除支持[通用属性](js-components-common-attributes.md#ZH-CN_TOPIC_0000001163812208)外，还支持如下属性：

<a name="zh-cn_topic_0000001173164773_table20633101642315"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001173164773_row663331618238"><th class="cellrowborder" valign="top" width="23.169999999999998%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001173164773_aa872998ac2d84843a3c5161889afffef"><a name="zh-cn_topic_0000001173164773_aa872998ac2d84843a3c5161889afffef"></a><a name="zh-cn_topic_0000001173164773_aa872998ac2d84843a3c5161889afffef"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="14.44%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001173164773_ab2111648ee0e4f6d881be8954e7acaab"><a name="zh-cn_topic_0000001173164773_ab2111648ee0e4f6d881be8954e7acaab"></a><a name="zh-cn_topic_0000001173164773_ab2111648ee0e4f6d881be8954e7acaab"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.97%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001173164773_ab377d1c90900478ea4ecab51e9a058af"><a name="zh-cn_topic_0000001173164773_ab377d1c90900478ea4ecab51e9a058af"></a><a name="zh-cn_topic_0000001173164773_ab377d1c90900478ea4ecab51e9a058af"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.68%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001173164773_p824610360217"><a name="zh-cn_topic_0000001173164773_p824610360217"></a><a name="zh-cn_topic_0000001173164773_p824610360217"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="43.74%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001173164773_a1d574a0044ed42ec8a2603bc82734232"><a name="zh-cn_topic_0000001173164773_a1d574a0044ed42ec8a2603bc82734232"></a><a name="zh-cn_topic_0000001173164773_a1d574a0044ed42ec8a2603bc82734232"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001173164773_row16500184513188"><td class="cellrowborder" valign="top" width="23.169999999999998%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164773_p19823174614180"><a name="zh-cn_topic_0000001173164773_p19823174614180"></a><a name="zh-cn_topic_0000001173164773_p19823174614180"></a>icon</p>
</td>
<td class="cellrowborder" valign="top" width="14.44%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164773_p3823184617189"><a name="zh-cn_topic_0000001173164773_p3823184617189"></a><a name="zh-cn_topic_0000001173164773_p3823184617189"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.97%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164773_p9823946181811"><a name="zh-cn_topic_0000001173164773_p9823946181811"></a><a name="zh-cn_topic_0000001173164773_p9823946181811"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.68%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164773_p1782334621813"><a name="zh-cn_topic_0000001173164773_p1782334621813"></a><a name="zh-cn_topic_0000001173164773_p1782334621813"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.74%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164773_p082364616188"><a name="zh-cn_topic_0000001173164773_p082364616188"></a><a name="zh-cn_topic_0000001173164773_p082364616188"></a>搜索图标，默认使用系统搜索图标，图标格式为svg，jpg和png。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164773_row517994310189"><td class="cellrowborder" valign="top" width="23.169999999999998%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164773_p1782314611185"><a name="zh-cn_topic_0000001173164773_p1782314611185"></a><a name="zh-cn_topic_0000001173164773_p1782314611185"></a>hint</p>
</td>
<td class="cellrowborder" valign="top" width="14.44%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164773_p6823164617184"><a name="zh-cn_topic_0000001173164773_p6823164617184"></a><a name="zh-cn_topic_0000001173164773_p6823164617184"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.97%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164773_p282314617188"><a name="zh-cn_topic_0000001173164773_p282314617188"></a><a name="zh-cn_topic_0000001173164773_p282314617188"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.68%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164773_p198231046181817"><a name="zh-cn_topic_0000001173164773_p198231046181817"></a><a name="zh-cn_topic_0000001173164773_p198231046181817"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.74%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164773_p1823846131819"><a name="zh-cn_topic_0000001173164773_p1823846131819"></a><a name="zh-cn_topic_0000001173164773_p1823846131819"></a>搜索提示文字。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164773_row19730640181819"><td class="cellrowborder" valign="top" width="23.169999999999998%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164773_p482374611185"><a name="zh-cn_topic_0000001173164773_p482374611185"></a><a name="zh-cn_topic_0000001173164773_p482374611185"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="14.44%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164773_p1082315461186"><a name="zh-cn_topic_0000001173164773_p1082315461186"></a><a name="zh-cn_topic_0000001173164773_p1082315461186"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.97%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164773_p1282384613182"><a name="zh-cn_topic_0000001173164773_p1282384613182"></a><a name="zh-cn_topic_0000001173164773_p1282384613182"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.68%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164773_p18823154617189"><a name="zh-cn_topic_0000001173164773_p18823154617189"></a><a name="zh-cn_topic_0000001173164773_p18823154617189"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.74%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164773_p208241446121810"><a name="zh-cn_topic_0000001173164773_p208241446121810"></a><a name="zh-cn_topic_0000001173164773_p208241446121810"></a>搜索框搜索文本值。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164773_row83561013112217"><td class="cellrowborder" valign="top" width="23.169999999999998%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164773_p735651316223"><a name="zh-cn_topic_0000001173164773_p735651316223"></a><a name="zh-cn_topic_0000001173164773_p735651316223"></a>searchbutton<sup id="zh-cn_topic_0000001173164773_sup46781354122715"><a name="zh-cn_topic_0000001173164773_sup46781354122715"></a><a name="zh-cn_topic_0000001173164773_sup46781354122715"></a><span>5+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="14.44%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164773_p1356213172219"><a name="zh-cn_topic_0000001173164773_p1356213172219"></a><a name="zh-cn_topic_0000001173164773_p1356213172219"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.97%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164773_p6356713182219"><a name="zh-cn_topic_0000001173164773_p6356713182219"></a><a name="zh-cn_topic_0000001173164773_p6356713182219"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.68%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164773_p13564131227"><a name="zh-cn_topic_0000001173164773_p13564131227"></a><a name="zh-cn_topic_0000001173164773_p13564131227"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.74%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164773_p4356131312222"><a name="zh-cn_topic_0000001173164773_p4356131312222"></a><a name="zh-cn_topic_0000001173164773_p4356131312222"></a>搜索框末尾搜索按钮文本值。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164773_row31984911281"><td class="cellrowborder" valign="top" width="23.169999999999998%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164773_p177221571244"><a name="zh-cn_topic_0000001173164773_p177221571244"></a><a name="zh-cn_topic_0000001173164773_p177221571244"></a>menuoptions<sup id="zh-cn_topic_0000001173164773_sup154944401542"><a name="zh-cn_topic_0000001173164773_sup154944401542"></a><a name="zh-cn_topic_0000001173164773_sup154944401542"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="14.44%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164773_p8722157248"><a name="zh-cn_topic_0000001173164773_p8722157248"></a><a name="zh-cn_topic_0000001173164773_p8722157248"></a>Array&lt;<a href="#zh-cn_topic_0000001173164773_table83621954963">MenuOption</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.97%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164773_p167221878414"><a name="zh-cn_topic_0000001173164773_p167221878414"></a><a name="zh-cn_topic_0000001173164773_p167221878414"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.68%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164773_p197227713411"><a name="zh-cn_topic_0000001173164773_p197227713411"></a><a name="zh-cn_topic_0000001173164773_p197227713411"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.74%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164773_p207221573417"><a name="zh-cn_topic_0000001173164773_p207221573417"></a><a name="zh-cn_topic_0000001173164773_p207221573417"></a>设置文本选择弹框点击更多按钮之后显示的菜单项。</p>
</td>
</tr>
</tbody>
</table>

**表 1**  MenuOption<sup>5+</sup>

<a name="zh-cn_topic_0000001173164773_table83621954963"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001173164773_row536212545619"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="zh-cn_topic_0000001173164773_p143621541967"><a name="zh-cn_topic_0000001173164773_p143621541967"></a><a name="zh-cn_topic_0000001173164773_p143621541967"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="zh-cn_topic_0000001173164773_p936215541620"><a name="zh-cn_topic_0000001173164773_p936215541620"></a><a name="zh-cn_topic_0000001173164773_p936215541620"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="zh-cn_topic_0000001173164773_p23626541665"><a name="zh-cn_topic_0000001173164773_p23626541665"></a><a name="zh-cn_topic_0000001173164773_p23626541665"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001173164773_row5362254461"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001173164773_p33631541265"><a name="zh-cn_topic_0000001173164773_p33631541265"></a><a name="zh-cn_topic_0000001173164773_p33631541265"></a>icon</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001173164773_p536311543619"><a name="zh-cn_topic_0000001173164773_p536311543619"></a><a name="zh-cn_topic_0000001173164773_p536311543619"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001173164773_p73631954762"><a name="zh-cn_topic_0000001173164773_p73631954762"></a><a name="zh-cn_topic_0000001173164773_p73631954762"></a>菜单选项中的图标路径。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164773_row136319547613"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001173164773_p12363654367"><a name="zh-cn_topic_0000001173164773_p12363654367"></a><a name="zh-cn_topic_0000001173164773_p12363654367"></a>content</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001173164773_p1936312549617"><a name="zh-cn_topic_0000001173164773_p1936312549617"></a><a name="zh-cn_topic_0000001173164773_p1936312549617"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001173164773_p1036311548616"><a name="zh-cn_topic_0000001173164773_p1036311548616"></a><a name="zh-cn_topic_0000001173164773_p1036311548616"></a>菜单选项中的文本内容。</p>
</td>
</tr>
</tbody>
</table>

## 样式<a name="zh-cn_topic_0000001173164773_section5775351116"></a>

除支持[通用样式](js-components-common-styles.md#ZH-CN_TOPIC_0000001163932190)外，还支持如下样式：

<a name="zh-cn_topic_0000001173164773_table14588121079"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001173164773_row3588182975"><th class="cellrowborder" valign="top" width="23.11768823117688%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001173164773_p2588112873"><a name="zh-cn_topic_0000001173164773_p2588112873"></a><a name="zh-cn_topic_0000001173164773_p2588112873"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="14.1985801419858%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001173164773_p18588321876"><a name="zh-cn_topic_0000001173164773_p18588321876"></a><a name="zh-cn_topic_0000001173164773_p18588321876"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="20.247975202479754%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001173164773_p1588132673"><a name="zh-cn_topic_0000001173164773_p1588132673"></a><a name="zh-cn_topic_0000001173164773_p1588132673"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="5.23947605239476%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001173164773_p3588192276"><a name="zh-cn_topic_0000001173164773_p3588192276"></a><a name="zh-cn_topic_0000001173164773_p3588192276"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="37.1962803719628%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001173164773_p55881121575"><a name="zh-cn_topic_0000001173164773_p55881121575"></a><a name="zh-cn_topic_0000001173164773_p55881121575"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001173164773_row45881726713"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164773_p1588182874"><a name="zh-cn_topic_0000001173164773_p1588182874"></a><a name="zh-cn_topic_0000001173164773_p1588182874"></a>color</p>
</td>
<td class="cellrowborder" valign="top" width="14.1985801419858%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164773_p8588725714"><a name="zh-cn_topic_0000001173164773_p8588725714"></a><a name="zh-cn_topic_0000001173164773_p8588725714"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="20.247975202479754%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164773_p13588521677"><a name="zh-cn_topic_0000001173164773_p13588521677"></a><a name="zh-cn_topic_0000001173164773_p13588521677"></a>#e6000000</p>
</td>
<td class="cellrowborder" valign="top" width="5.23947605239476%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164773_p11588112272"><a name="zh-cn_topic_0000001173164773_p11588112272"></a><a name="zh-cn_topic_0000001173164773_p11588112272"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="37.1962803719628%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164773_p17588923718"><a name="zh-cn_topic_0000001173164773_p17588923718"></a><a name="zh-cn_topic_0000001173164773_p17588923718"></a>搜索框的文本颜色。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164773_row858822573"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164773_p25881521973"><a name="zh-cn_topic_0000001173164773_p25881521973"></a><a name="zh-cn_topic_0000001173164773_p25881521973"></a>font-size</p>
</td>
<td class="cellrowborder" valign="top" width="14.1985801419858%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164773_p13588629717"><a name="zh-cn_topic_0000001173164773_p13588629717"></a><a name="zh-cn_topic_0000001173164773_p13588629717"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="20.247975202479754%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164773_p15588321719"><a name="zh-cn_topic_0000001173164773_p15588321719"></a><a name="zh-cn_topic_0000001173164773_p15588321719"></a>16px</p>
</td>
<td class="cellrowborder" valign="top" width="5.23947605239476%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164773_p05899216712"><a name="zh-cn_topic_0000001173164773_p05899216712"></a><a name="zh-cn_topic_0000001173164773_p05899216712"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="37.1962803719628%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164773_p175891621973"><a name="zh-cn_topic_0000001173164773_p175891621973"></a><a name="zh-cn_topic_0000001173164773_p175891621973"></a>搜索框的文本尺寸。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164773_row14589724712"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164773_p155891921078"><a name="zh-cn_topic_0000001173164773_p155891921078"></a><a name="zh-cn_topic_0000001173164773_p155891921078"></a>allow-scale</p>
</td>
<td class="cellrowborder" valign="top" width="14.1985801419858%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164773_p658922277"><a name="zh-cn_topic_0000001173164773_p658922277"></a><a name="zh-cn_topic_0000001173164773_p658922277"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="20.247975202479754%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164773_p12589521713"><a name="zh-cn_topic_0000001173164773_p12589521713"></a><a name="zh-cn_topic_0000001173164773_p12589521713"></a>true</p>
</td>
<td class="cellrowborder" valign="top" width="5.23947605239476%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164773_p155891121872"><a name="zh-cn_topic_0000001173164773_p155891121872"></a><a name="zh-cn_topic_0000001173164773_p155891121872"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="37.1962803719628%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164773_p55894219719"><a name="zh-cn_topic_0000001173164773_p55894219719"></a><a name="zh-cn_topic_0000001173164773_p55894219719"></a>搜索框的文本尺寸是否跟随系统设置字体缩放尺寸进行放大缩小。</p>
<div class="note" id="zh-cn_topic_0000001173164773_note13589162372"><a name="zh-cn_topic_0000001173164773_note13589162372"></a><a name="zh-cn_topic_0000001173164773_note13589162372"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001173164773_p12589021175"><a name="zh-cn_topic_0000001173164773_p12589021175"></a><a name="zh-cn_topic_0000001173164773_p12589021175"></a>如果在config描述文件中针对ability配置了fontSize的config-changes标签，则应用不会重启而直接生效。</p>
</div></div>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164773_row3589121375"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164773_p95891321170"><a name="zh-cn_topic_0000001173164773_p95891321170"></a><a name="zh-cn_topic_0000001173164773_p95891321170"></a>placeholder-color</p>
</td>
<td class="cellrowborder" valign="top" width="14.1985801419858%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164773_p1058982376"><a name="zh-cn_topic_0000001173164773_p1058982376"></a><a name="zh-cn_topic_0000001173164773_p1058982376"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="20.247975202479754%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164773_p9589726718"><a name="zh-cn_topic_0000001173164773_p9589726718"></a><a name="zh-cn_topic_0000001173164773_p9589726718"></a>#99000000</p>
</td>
<td class="cellrowborder" valign="top" width="5.23947605239476%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164773_p558914219710"><a name="zh-cn_topic_0000001173164773_p558914219710"></a><a name="zh-cn_topic_0000001173164773_p558914219710"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="37.1962803719628%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164773_p25896215710"><a name="zh-cn_topic_0000001173164773_p25896215710"></a><a name="zh-cn_topic_0000001173164773_p25896215710"></a>搜索框的提示文本颜色。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164773_row1658911216712"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164773_p4589182976"><a name="zh-cn_topic_0000001173164773_p4589182976"></a><a name="zh-cn_topic_0000001173164773_p4589182976"></a>font-weight</p>
</td>
<td class="cellrowborder" valign="top" width="14.1985801419858%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164773_p18589122578"><a name="zh-cn_topic_0000001173164773_p18589122578"></a><a name="zh-cn_topic_0000001173164773_p18589122578"></a>number | string</p>
</td>
<td class="cellrowborder" valign="top" width="20.247975202479754%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164773_p1058982179"><a name="zh-cn_topic_0000001173164773_p1058982179"></a><a name="zh-cn_topic_0000001173164773_p1058982179"></a>normal</p>
</td>
<td class="cellrowborder" valign="top" width="5.23947605239476%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164773_p1058917212710"><a name="zh-cn_topic_0000001173164773_p1058917212710"></a><a name="zh-cn_topic_0000001173164773_p1058917212710"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="37.1962803719628%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164773_p2058912778"><a name="zh-cn_topic_0000001173164773_p2058912778"></a><a name="zh-cn_topic_0000001173164773_p2058912778"></a>搜索框的字体粗细，见<a href="js-components-basic-text.md#zh-cn_topic_0000001127125018_section5775351116">text组件font-weight的样式属性</a>。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164773_row45906217712"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164773_p115907212715"><a name="zh-cn_topic_0000001173164773_p115907212715"></a><a name="zh-cn_topic_0000001173164773_p115907212715"></a>font-family</p>
</td>
<td class="cellrowborder" valign="top" width="14.1985801419858%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164773_p459015215711"><a name="zh-cn_topic_0000001173164773_p459015215711"></a><a name="zh-cn_topic_0000001173164773_p459015215711"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="20.247975202479754%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164773_p4590172674"><a name="zh-cn_topic_0000001173164773_p4590172674"></a><a name="zh-cn_topic_0000001173164773_p4590172674"></a>sans-serif</p>
</td>
<td class="cellrowborder" valign="top" width="5.23947605239476%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164773_p12590828720"><a name="zh-cn_topic_0000001173164773_p12590828720"></a><a name="zh-cn_topic_0000001173164773_p12590828720"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="37.1962803719628%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164773_p17590721579"><a name="zh-cn_topic_0000001173164773_p17590721579"></a><a name="zh-cn_topic_0000001173164773_p17590721579"></a>搜索框的字体列表，用逗号分隔，每个字体用字体名或者字体族名设置。列表中第一个系统中存在的或者通过<a href="js-components-common-customizing-font.md#ZH-CN_TOPIC_0000001163812210">自定义字体</a>指定的字体，会被选中作为文本的字体。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164773_row583415126314"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164773_p153521247133716"><a name="zh-cn_topic_0000001173164773_p153521247133716"></a><a name="zh-cn_topic_0000001173164773_p153521247133716"></a>caret-color<sup id="zh-cn_topic_0000001173164773_sup535294718377"><a name="zh-cn_topic_0000001173164773_sup535294718377"></a><a name="zh-cn_topic_0000001173164773_sup535294718377"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="14.1985801419858%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164773_p53529471377"><a name="zh-cn_topic_0000001173164773_p53529471377"></a><a name="zh-cn_topic_0000001173164773_p53529471377"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="20.247975202479754%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164773_p235244716372"><a name="zh-cn_topic_0000001173164773_p235244716372"></a><a name="zh-cn_topic_0000001173164773_p235244716372"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="5.23947605239476%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164773_p4352174712375"><a name="zh-cn_topic_0000001173164773_p4352174712375"></a><a name="zh-cn_topic_0000001173164773_p4352174712375"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="37.1962803719628%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164773_p1935320474379"><a name="zh-cn_topic_0000001173164773_p1935320474379"></a><a name="zh-cn_topic_0000001173164773_p1935320474379"></a>设置输入光标的颜色。</p>
</td>
</tr>
</tbody>
</table>

## 事件<a name="zh-cn_topic_0000001173164773_section17878123517511"></a>

除支持[通用事件](js-components-common-events.md#ZH-CN_TOPIC_0000001209412119)外，还支持如下事件：

<a name="zh-cn_topic_0000001173164773_table13878203565113"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001173164773_row18789355519"><th class="cellrowborder" valign="top" width="24.852485248524854%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173164773_p08781335165113"><a name="zh-cn_topic_0000001173164773_p08781335165113"></a><a name="zh-cn_topic_0000001173164773_p08781335165113"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="29.552955295529554%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173164773_p6878123595117"><a name="zh-cn_topic_0000001173164773_p6878123595117"></a><a name="zh-cn_topic_0000001173164773_p6878123595117"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="45.5945594559456%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173164773_p28783359518"><a name="zh-cn_topic_0000001173164773_p28783359518"></a><a name="zh-cn_topic_0000001173164773_p28783359518"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001173164773_row2087803565116"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164773_p3878113518516"><a name="zh-cn_topic_0000001173164773_p3878113518516"></a><a name="zh-cn_topic_0000001173164773_p3878113518516"></a>change</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164773_p187813511516"><a name="zh-cn_topic_0000001173164773_p187813511516"></a><a name="zh-cn_topic_0000001173164773_p187813511516"></a>{ text:newText }</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164773_p19878133518518"><a name="zh-cn_topic_0000001173164773_p19878133518518"></a><a name="zh-cn_topic_0000001173164773_p19878133518518"></a>输入内容发生变化时触发。</p>
<div class="note" id="zh-cn_topic_0000001173164773_note887893525112"><a name="zh-cn_topic_0000001173164773_note887893525112"></a><a name="zh-cn_topic_0000001173164773_note887893525112"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001173164773_p19878435115119"><a name="zh-cn_topic_0000001173164773_p19878435115119"></a><a name="zh-cn_topic_0000001173164773_p19878435115119"></a>改变value属性值不会触发该回调。</p>
</div></div>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164773_row28781235145111"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164773_p48781535195110"><a name="zh-cn_topic_0000001173164773_p48781535195110"></a><a name="zh-cn_topic_0000001173164773_p48781535195110"></a>submit</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164773_p19878535135111"><a name="zh-cn_topic_0000001173164773_p19878535135111"></a><a name="zh-cn_topic_0000001173164773_p19878535135111"></a>{ text:submitText }</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164773_p13878335145119"><a name="zh-cn_topic_0000001173164773_p13878335145119"></a><a name="zh-cn_topic_0000001173164773_p13878335145119"></a>点击搜索图标、搜索按钮<sup id="zh-cn_topic_0000001173164773_sup38791035105117"><a name="zh-cn_topic_0000001173164773_sup38791035105117"></a><a name="zh-cn_topic_0000001173164773_sup38791035105117"></a>5+</sup>或者按下软键盘搜索按钮时触发。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164773_row108791535175110"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164773_p118790355519"><a name="zh-cn_topic_0000001173164773_p118790355519"></a><a name="zh-cn_topic_0000001173164773_p118790355519"></a>translate<sup id="zh-cn_topic_0000001173164773_sup18879203525118"><a name="zh-cn_topic_0000001173164773_sup18879203525118"></a><a name="zh-cn_topic_0000001173164773_sup18879203525118"></a><span>5+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164773_p9879113511519"><a name="zh-cn_topic_0000001173164773_p9879113511519"></a><a name="zh-cn_topic_0000001173164773_p9879113511519"></a>{ value: selectedText }</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164773_p08797356513"><a name="zh-cn_topic_0000001173164773_p08797356513"></a><a name="zh-cn_topic_0000001173164773_p08797356513"></a>设置此事件后，进行文本选择操作后文本选择弹窗会出现翻译按钮，点击翻译按钮之后，触发该回调，返回选中的文本内容。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164773_row68791835175117"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164773_p12879135135120"><a name="zh-cn_topic_0000001173164773_p12879135135120"></a><a name="zh-cn_topic_0000001173164773_p12879135135120"></a>share<sup id="zh-cn_topic_0000001173164773_sup3879173513515"><a name="zh-cn_topic_0000001173164773_sup3879173513515"></a><a name="zh-cn_topic_0000001173164773_sup3879173513515"></a><span>5+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164773_p5879153595110"><a name="zh-cn_topic_0000001173164773_p5879153595110"></a><a name="zh-cn_topic_0000001173164773_p5879153595110"></a>{ value: selectedText }</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164773_p15879183520514"><a name="zh-cn_topic_0000001173164773_p15879183520514"></a><a name="zh-cn_topic_0000001173164773_p15879183520514"></a>设置此事件后，进行文本选择操作后文本选择弹窗会出现分享按钮，点击分享按钮之后，触发该回调，返回选中的文本内容。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164773_row1287912352517"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164773_p198791035125112"><a name="zh-cn_topic_0000001173164773_p198791035125112"></a><a name="zh-cn_topic_0000001173164773_p198791035125112"></a>search<sup id="zh-cn_topic_0000001173164773_sup1487914358515"><a name="zh-cn_topic_0000001173164773_sup1487914358515"></a><a name="zh-cn_topic_0000001173164773_sup1487914358515"></a><span>5+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164773_p9879735125114"><a name="zh-cn_topic_0000001173164773_p9879735125114"></a><a name="zh-cn_topic_0000001173164773_p9879735125114"></a>{ value: selectedText }</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164773_p38791935135119"><a name="zh-cn_topic_0000001173164773_p38791935135119"></a><a name="zh-cn_topic_0000001173164773_p38791935135119"></a>设置此事件后，进行文本选择操作后文本选择弹窗会出现搜索按钮，点击搜索按钮之后，触发该回调，返回选中的文本内容。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164773_row14879335145120"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164773_p98790359512"><a name="zh-cn_topic_0000001173164773_p98790359512"></a><a name="zh-cn_topic_0000001173164773_p98790359512"></a>optionselect<sup id="zh-cn_topic_0000001173164773_sup28791635145111"><a name="zh-cn_topic_0000001173164773_sup28791635145111"></a><a name="zh-cn_topic_0000001173164773_sup28791635145111"></a><span>5+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164773_p158791235115114"><a name="zh-cn_topic_0000001173164773_p158791235115114"></a><a name="zh-cn_topic_0000001173164773_p158791235115114"></a>{ index:optionIndex, value: selectedText }</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164773_p1087917353518"><a name="zh-cn_topic_0000001173164773_p1087917353518"></a><a name="zh-cn_topic_0000001173164773_p1087917353518"></a>文本选择弹窗中设置menuoptions属性后，用户在文本选择操作后，点击菜单项后触发该回调，返回点击的菜单项序号和选中的文本内容。</p>
</td>
</tr>
</tbody>
</table>

## 方法<a name="zh-cn_topic_0000001173164773_section2279124532420"></a>

支持[通用方法](js-components-common-methods.md#ZH-CN_TOPIC_0000001209252157)。

## 示例<a name="zh-cn_topic_0000001173164773_section586520905216"></a>

```
<!-- xxx.hml -->
<div class="container">
  <search hint="请输入搜索内容" searchbutton="搜索" @search="search">
  </search>
</div>
```

```
/* xxx.css */
.container {
  display: flex;
  justify-content: center;
  align-items: center;
}
```

![](figures/zh-cn_image_0000001153427082.png)

