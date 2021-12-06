# grid-container<a name="ZH-CN_TOPIC_0000001209210717"></a>

栅格布局容器根节点，使用grid-row与gird-col进行栅格布局。

## 权限列表<a name="zh-cn_topic_0000001173324617_section11257113618419"></a>

无

## 子组件<a name="zh-cn_topic_0000001173324617_section9288143101012"></a>

仅支持<grid-row\>。

## 属性<a name="zh-cn_topic_0000001173324617_section5248929161316"></a>

除支持[通用属性](js-components-common-attributes.md)外，还支持如下属性：

<a name="zh-cn_topic_0000001173324617_table20633101642315"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001173324617_row663331618238"><th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001173324617_a45273e2103004ff3bdd3375013e96a2a"><a name="zh-cn_topic_0000001173324617_a45273e2103004ff3bdd3375013e96a2a"></a><a name="zh-cn_topic_0000001173324617_a45273e2103004ff3bdd3375013e96a2a"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001173324617_ad5b10d4a60e44bb4a8bbb3b4416d7b27"><a name="zh-cn_topic_0000001173324617_ad5b10d4a60e44bb4a8bbb3b4416d7b27"></a><a name="zh-cn_topic_0000001173324617_ad5b10d4a60e44bb4a8bbb3b4416d7b27"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.48%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001173324617_ab2ae3d9f60d6475ab95ba095851a9d07"><a name="zh-cn_topic_0000001173324617_ab2ae3d9f60d6475ab95ba095851a9d07"></a><a name="zh-cn_topic_0000001173324617_ab2ae3d9f60d6475ab95ba095851a9d07"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001173324617_p824610360217"><a name="zh-cn_topic_0000001173324617_p824610360217"></a><a name="zh-cn_topic_0000001173324617_p824610360217"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="35.76%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001173324617_af5c3b773ed0a42e589819a6c8d257ca1"><a name="zh-cn_topic_0000001173324617_af5c3b773ed0a42e589819a6c8d257ca1"></a><a name="zh-cn_topic_0000001173324617_af5c3b773ed0a42e589819a6c8d257ca1"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001173324617_row18693825133018"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324617_p6247162723015"><a name="zh-cn_topic_0000001173324617_p6247162723015"></a><a name="zh-cn_topic_0000001173324617_p6247162723015"></a>columns</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324617_p824742753016"><a name="zh-cn_topic_0000001173324617_p824742753016"></a><a name="zh-cn_topic_0000001173324617_p824742753016"></a>string | number</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324617_p102474272303"><a name="zh-cn_topic_0000001173324617_p102474272303"></a><a name="zh-cn_topic_0000001173324617_p102474272303"></a>auto</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324617_p0247112733012"><a name="zh-cn_topic_0000001173324617_p0247112733012"></a><a name="zh-cn_topic_0000001173324617_p0247112733012"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324617_p224762773015"><a name="zh-cn_topic_0000001173324617_p224762773015"></a><a name="zh-cn_topic_0000001173324617_p224762773015"></a>设置当前布局总列数，使用string类型时仅支持auto，配置为auto时按照当前的sizetype决定总列数：</p>
<a name="zh-cn_topic_0000001173324617_ul9387744161011"></a><a name="zh-cn_topic_0000001173324617_ul9387744161011"></a><ul id="zh-cn_topic_0000001173324617_ul9387744161011"><li>xs：2列</li><li>sm：4列</li><li>md：8列</li><li>lg：12列</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324617_row2866142283019"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324617_p52471927173014"><a name="zh-cn_topic_0000001173324617_p52471927173014"></a><a name="zh-cn_topic_0000001173324617_p52471927173014"></a>sizetype</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324617_p92470270304"><a name="zh-cn_topic_0000001173324617_p92470270304"></a><a name="zh-cn_topic_0000001173324617_p92470270304"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324617_p5247172773018"><a name="zh-cn_topic_0000001173324617_p5247172773018"></a><a name="zh-cn_topic_0000001173324617_p5247172773018"></a>auto</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324617_p124772703014"><a name="zh-cn_topic_0000001173324617_p124772703014"></a><a name="zh-cn_topic_0000001173324617_p124772703014"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324617_p7247627163020"><a name="zh-cn_topic_0000001173324617_p7247627163020"></a><a name="zh-cn_topic_0000001173324617_p7247627163020"></a>设置当前栅格使用的响应尺寸类型，支持xs, sm, md, lg类型，使用auto时按照当前容器大小自动选择xs, sm, md, lg类型。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324617_row275616196304"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324617_p9247122719308"><a name="zh-cn_topic_0000001173324617_p9247122719308"></a><a name="zh-cn_topic_0000001173324617_p9247122719308"></a>gutter</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324617_p1424718278304"><a name="zh-cn_topic_0000001173324617_p1424718278304"></a><a name="zh-cn_topic_0000001173324617_p1424718278304"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324617_p92471627133011"><a name="zh-cn_topic_0000001173324617_p92471627133011"></a><a name="zh-cn_topic_0000001173324617_p92471627133011"></a>24px</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324617_p15247202713010"><a name="zh-cn_topic_0000001173324617_p15247202713010"></a><a name="zh-cn_topic_0000001173324617_p15247202713010"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324617_p16247192714308"><a name="zh-cn_topic_0000001173324617_p16247192714308"></a><a name="zh-cn_topic_0000001173324617_p16247192714308"></a>设置Gutter宽度</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324617_row164131050102817"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324617_p1941415503284"><a name="zh-cn_topic_0000001173324617_p1941415503284"></a><a name="zh-cn_topic_0000001173324617_p1941415503284"></a>gridtemplate<sup id="zh-cn_topic_0000001173324617_sup105523732920"><a name="zh-cn_topic_0000001173324617_sup105523732920"></a><a name="zh-cn_topic_0000001173324617_sup105523732920"></a><span>6+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324617_p94141850142816"><a name="zh-cn_topic_0000001173324617_p94141850142816"></a><a name="zh-cn_topic_0000001173324617_p94141850142816"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324617_p34141950172810"><a name="zh-cn_topic_0000001173324617_p34141950172810"></a><a name="zh-cn_topic_0000001173324617_p34141950172810"></a>default</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324617_p104141550172811"><a name="zh-cn_topic_0000001173324617_p104141550172811"></a><a name="zh-cn_topic_0000001173324617_p104141550172811"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324617_p5414150172819"><a name="zh-cn_topic_0000001173324617_p5414150172819"></a><a name="zh-cn_topic_0000001173324617_p5414150172819"></a>当设置了columns和sizetype属性为auto时，可以设置栅格容器的布局模板，通过布局模块设置不同响应尺寸下的Columns、Gutters和Margins，详见<a href="#zh-cn_topic_0000001173324617_table135645386317">可选值说明</a>。</p>
</td>
</tr>
</tbody>
</table>

**表 1**  gridtemplate可选值说明<sup>6+</sup>

<a name="zh-cn_topic_0000001173324617_table135645386317"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001173324617_row256563853117"><th class="cellrowborder" valign="top" width="11.52769446110778%" id="mcps1.2.7.1.1">&nbsp;&nbsp;</th>
<th class="cellrowborder" valign="top" width="14.487102579484104%" id="mcps1.2.7.1.2"><p id="zh-cn_topic_0000001173324617_p65657386312"><a name="zh-cn_topic_0000001173324617_p65657386312"></a><a name="zh-cn_topic_0000001173324617_p65657386312"></a>模板值</p>
</th>
<th class="cellrowborder" valign="top" width="18.49630073985203%" id="mcps1.2.7.1.3"><p id="zh-cn_topic_0000001173324617_p1956553833119"><a name="zh-cn_topic_0000001173324617_p1956553833119"></a><a name="zh-cn_topic_0000001173324617_p1956553833119"></a>可响应的<strong id="zh-cn_topic_0000001173324617_b458420313814"><a name="zh-cn_topic_0000001173324617_b458420313814"></a><a name="zh-cn_topic_0000001173324617_b458420313814"></a>栅格断点系统</strong></p>
</th>
<th class="cellrowborder" valign="top" width="18.49630073985203%" id="mcps1.2.7.1.4"><p id="zh-cn_topic_0000001173324617_p3565103873115"><a name="zh-cn_topic_0000001173324617_p3565103873115"></a><a name="zh-cn_topic_0000001173324617_p3565103873115"></a>Columns</p>
</th>
<th class="cellrowborder" valign="top" width="18.49630073985203%" id="mcps1.2.7.1.5"><p id="zh-cn_topic_0000001173324617_p3565438123118"><a name="zh-cn_topic_0000001173324617_p3565438123118"></a><a name="zh-cn_topic_0000001173324617_p3565438123118"></a>Margins(px)</p>
</th>
<th class="cellrowborder" valign="top" width="18.49630073985203%" id="mcps1.2.7.1.6"><p id="zh-cn_topic_0000001173324617_p8565193843119"><a name="zh-cn_topic_0000001173324617_p8565193843119"></a><a name="zh-cn_topic_0000001173324617_p8565193843119"></a>Gutters(px)</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001173324617_row35651438163116"><td class="cellrowborder" rowspan="4" valign="top" width="11.52769446110778%" headers="mcps1.2.7.1.1 "><p id="zh-cn_topic_0000001173324617_p1070922164816"><a name="zh-cn_topic_0000001173324617_p1070922164816"></a><a name="zh-cn_topic_0000001173324617_p1070922164816"></a>默认栅格</p>
</td>
<td class="cellrowborder" rowspan="4" valign="top" width="14.487102579484104%" headers="mcps1.2.7.1.2 "><p id="zh-cn_topic_0000001173324617_p165657381311"><a name="zh-cn_topic_0000001173324617_p165657381311"></a><a name="zh-cn_topic_0000001173324617_p165657381311"></a>default</p>
</td>
<td class="cellrowborder" valign="top" width="18.49630073985203%" headers="mcps1.2.7.1.3 "><p id="zh-cn_topic_0000001173324617_p1956518386313"><a name="zh-cn_topic_0000001173324617_p1956518386313"></a><a name="zh-cn_topic_0000001173324617_p1956518386313"></a>xs</p>
</td>
<td class="cellrowborder" valign="top" width="18.49630073985203%" headers="mcps1.2.7.1.4 "><p id="zh-cn_topic_0000001173324617_p1156683863116"><a name="zh-cn_topic_0000001173324617_p1156683863116"></a><a name="zh-cn_topic_0000001173324617_p1156683863116"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="18.49630073985203%" headers="mcps1.2.7.1.5 "><p id="zh-cn_topic_0000001173324617_p1156603833110"><a name="zh-cn_topic_0000001173324617_p1156603833110"></a><a name="zh-cn_topic_0000001173324617_p1156603833110"></a>12</p>
</td>
<td class="cellrowborder" valign="top" width="18.49630073985203%" headers="mcps1.2.7.1.6 "><p id="zh-cn_topic_0000001173324617_p0566203818310"><a name="zh-cn_topic_0000001173324617_p0566203818310"></a><a name="zh-cn_topic_0000001173324617_p0566203818310"></a>12</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324617_row7566133843118"><td class="cellrowborder" valign="top" headers="mcps1.2.7.1.1 "><p id="zh-cn_topic_0000001173324617_p456615380314"><a name="zh-cn_topic_0000001173324617_p456615380314"></a><a name="zh-cn_topic_0000001173324617_p456615380314"></a>sm</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.2 "><p id="zh-cn_topic_0000001173324617_p2566103818314"><a name="zh-cn_topic_0000001173324617_p2566103818314"></a><a name="zh-cn_topic_0000001173324617_p2566103818314"></a>4</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.3 "><p id="zh-cn_topic_0000001173324617_p18566123833111"><a name="zh-cn_topic_0000001173324617_p18566123833111"></a><a name="zh-cn_topic_0000001173324617_p18566123833111"></a>24</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.4 "><p id="zh-cn_topic_0000001173324617_p115661438173119"><a name="zh-cn_topic_0000001173324617_p115661438173119"></a><a name="zh-cn_topic_0000001173324617_p115661438173119"></a>24</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324617_row1456616389317"><td class="cellrowborder" valign="top" headers="mcps1.2.7.1.1 "><p id="zh-cn_topic_0000001173324617_p35661138173117"><a name="zh-cn_topic_0000001173324617_p35661138173117"></a><a name="zh-cn_topic_0000001173324617_p35661138173117"></a>md</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.2 "><p id="zh-cn_topic_0000001173324617_p13566203812311"><a name="zh-cn_topic_0000001173324617_p13566203812311"></a><a name="zh-cn_topic_0000001173324617_p13566203812311"></a>8</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.3 "><p id="zh-cn_topic_0000001173324617_p17566103819319"><a name="zh-cn_topic_0000001173324617_p17566103819319"></a><a name="zh-cn_topic_0000001173324617_p17566103819319"></a>32</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.4 "><p id="zh-cn_topic_0000001173324617_p11566173814316"><a name="zh-cn_topic_0000001173324617_p11566173814316"></a><a name="zh-cn_topic_0000001173324617_p11566173814316"></a>24</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324617_row135873533313"><td class="cellrowborder" valign="top" headers="mcps1.2.7.1.1 "><p id="zh-cn_topic_0000001173324617_p1558711543319"><a name="zh-cn_topic_0000001173324617_p1558711543319"></a><a name="zh-cn_topic_0000001173324617_p1558711543319"></a>lg</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.2 "><p id="zh-cn_topic_0000001173324617_p185889523318"><a name="zh-cn_topic_0000001173324617_p185889523318"></a><a name="zh-cn_topic_0000001173324617_p185889523318"></a>12</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.3 "><p id="zh-cn_topic_0000001173324617_p1658815513315"><a name="zh-cn_topic_0000001173324617_p1658815513315"></a><a name="zh-cn_topic_0000001173324617_p1658815513315"></a>48</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.4 "><p id="zh-cn_topic_0000001173324617_p145882517336"><a name="zh-cn_topic_0000001173324617_p145882517336"></a><a name="zh-cn_topic_0000001173324617_p145882517336"></a>24</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324617_row375535115395"><td class="cellrowborder" rowspan="3" valign="top" width="11.52769446110778%" headers="mcps1.2.7.1.1 "><p id="zh-cn_topic_0000001173324617_p84201325134819"><a name="zh-cn_topic_0000001173324617_p84201325134819"></a><a name="zh-cn_topic_0000001173324617_p84201325134819"></a>宫格布局栅格</p>
</td>
<td class="cellrowborder" rowspan="3" valign="top" width="14.487102579484104%" headers="mcps1.2.7.1.2 "><p id="zh-cn_topic_0000001173324617_p147956315402"><a name="zh-cn_topic_0000001173324617_p147956315402"></a><a name="zh-cn_topic_0000001173324617_p147956315402"></a>grid</p>
</td>
<td class="cellrowborder" valign="top" width="18.49630073985203%" headers="mcps1.2.7.1.3 "><p id="zh-cn_topic_0000001173324617_p675625173915"><a name="zh-cn_topic_0000001173324617_p675625173915"></a><a name="zh-cn_topic_0000001173324617_p675625173915"></a>sm(0&lt;设备水平分辨率&lt;600px)</p>
</td>
<td class="cellrowborder" valign="top" width="18.49630073985203%" headers="mcps1.2.7.1.4 "><p id="zh-cn_topic_0000001173324617_p10756851163916"><a name="zh-cn_topic_0000001173324617_p10756851163916"></a><a name="zh-cn_topic_0000001173324617_p10756851163916"></a>4</p>
</td>
<td class="cellrowborder" valign="top" width="18.49630073985203%" headers="mcps1.2.7.1.5 "><p id="zh-cn_topic_0000001173324617_p67561651123914"><a name="zh-cn_topic_0000001173324617_p67561651123914"></a><a name="zh-cn_topic_0000001173324617_p67561651123914"></a>24</p>
</td>
<td class="cellrowborder" valign="top" width="18.49630073985203%" headers="mcps1.2.7.1.6 "><p id="zh-cn_topic_0000001173324617_p4756125119398"><a name="zh-cn_topic_0000001173324617_p4756125119398"></a><a name="zh-cn_topic_0000001173324617_p4756125119398"></a>12</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324617_row1796215541391"><td class="cellrowborder" valign="top" headers="mcps1.2.7.1.1 "><p id="zh-cn_topic_0000001173324617_p1996235416399"><a name="zh-cn_topic_0000001173324617_p1996235416399"></a><a name="zh-cn_topic_0000001173324617_p1996235416399"></a>md</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.2 "><p id="zh-cn_topic_0000001173324617_p1896285411394"><a name="zh-cn_topic_0000001173324617_p1896285411394"></a><a name="zh-cn_topic_0000001173324617_p1896285411394"></a>8</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.3 "><p id="zh-cn_topic_0000001173324617_p9962185416391"><a name="zh-cn_topic_0000001173324617_p9962185416391"></a><a name="zh-cn_topic_0000001173324617_p9962185416391"></a>32</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.4 "><p id="zh-cn_topic_0000001173324617_p696235412394"><a name="zh-cn_topic_0000001173324617_p696235412394"></a><a name="zh-cn_topic_0000001173324617_p696235412394"></a>12</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324617_row12335758203911"><td class="cellrowborder" valign="top" headers="mcps1.2.7.1.1 "><p id="zh-cn_topic_0000001173324617_p03359587398"><a name="zh-cn_topic_0000001173324617_p03359587398"></a><a name="zh-cn_topic_0000001173324617_p03359587398"></a>lg</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.2 "><p id="zh-cn_topic_0000001173324617_p2033514589392"><a name="zh-cn_topic_0000001173324617_p2033514589392"></a><a name="zh-cn_topic_0000001173324617_p2033514589392"></a>12</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.3 "><p id="zh-cn_topic_0000001173324617_p23354588392"><a name="zh-cn_topic_0000001173324617_p23354588392"></a><a name="zh-cn_topic_0000001173324617_p23354588392"></a>48</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.4 "><p id="zh-cn_topic_0000001173324617_p15335358123917"><a name="zh-cn_topic_0000001173324617_p15335358123917"></a><a name="zh-cn_topic_0000001173324617_p15335358123917"></a>12</p>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>本章中px单位是在js标签中配置了autoDesignWidth为true。<sup>6+</sup>

## 样式<a name="zh-cn_topic_0000001173324617_section16690243163414"></a>

除支持[通用样式](js-components-common-styles.md)外，还支持如下样式：

<a name="zh-cn_topic_0000001173324617_table1386942213254"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001173324617_row1886913223255"><th class="cellrowborder" valign="top" width="23.11768823117688%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001173324617_p68690228255"><a name="zh-cn_topic_0000001173324617_p68690228255"></a><a name="zh-cn_topic_0000001173324617_p68690228255"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="12.80871912808719%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001173324617_p14869822112518"><a name="zh-cn_topic_0000001173324617_p14869822112518"></a><a name="zh-cn_topic_0000001173324617_p14869822112518"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="13.498650134986503%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001173324617_p15869192217258"><a name="zh-cn_topic_0000001173324617_p15869192217258"></a><a name="zh-cn_topic_0000001173324617_p15869192217258"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.56924307569243%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001173324617_p1486982212516"><a name="zh-cn_topic_0000001173324617_p1486982212516"></a><a name="zh-cn_topic_0000001173324617_p1486982212516"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="43.00569943005699%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001173324617_p10869722192510"><a name="zh-cn_topic_0000001173324617_p10869722192510"></a><a name="zh-cn_topic_0000001173324617_p10869722192510"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001173324617_row7869322142518"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324617_p16869162213256"><a name="zh-cn_topic_0000001173324617_p16869162213256"></a><a name="zh-cn_topic_0000001173324617_p16869162213256"></a>justify-content</p>
</td>
<td class="cellrowborder" valign="top" width="12.80871912808719%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324617_p1386912214258"><a name="zh-cn_topic_0000001173324617_p1386912214258"></a><a name="zh-cn_topic_0000001173324617_p1386912214258"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.498650134986503%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324617_p19869172292512"><a name="zh-cn_topic_0000001173324617_p19869172292512"></a><a name="zh-cn_topic_0000001173324617_p19869172292512"></a>flex-start</p>
</td>
<td class="cellrowborder" valign="top" width="7.56924307569243%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324617_p68702022122511"><a name="zh-cn_topic_0000001173324617_p68702022122511"></a><a name="zh-cn_topic_0000001173324617_p68702022122511"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.00569943005699%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324617_p387092216251"><a name="zh-cn_topic_0000001173324617_p387092216251"></a><a name="zh-cn_topic_0000001173324617_p387092216251"></a>flex容器当前行的主轴对齐格式。可选项有：</p>
<a name="zh-cn_topic_0000001173324617_ul10870182213257"></a><a name="zh-cn_topic_0000001173324617_ul10870182213257"></a><ul id="zh-cn_topic_0000001173324617_ul10870182213257"><li>flex-start：项目位于容器的开头。</li><li>flex-end：项目位于容器的结尾。</li><li>center：项目位于容器的中心。</li><li>space-between：项目位于各行之间留有空白的容器内。</li><li>space-around：项目位于各行之前、之间、之后都留有空白的容器内。</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324617_row15870152282510"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324617_p1687032217257"><a name="zh-cn_topic_0000001173324617_p1687032217257"></a><a name="zh-cn_topic_0000001173324617_p1687032217257"></a>align-items</p>
</td>
<td class="cellrowborder" valign="top" width="12.80871912808719%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324617_p1587032212513"><a name="zh-cn_topic_0000001173324617_p1587032212513"></a><a name="zh-cn_topic_0000001173324617_p1587032212513"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.498650134986503%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324617_p98701322122512"><a name="zh-cn_topic_0000001173324617_p98701322122512"></a><a name="zh-cn_topic_0000001173324617_p98701322122512"></a>stretch</p>
</td>
<td class="cellrowborder" valign="top" width="7.56924307569243%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324617_p48701322192515"><a name="zh-cn_topic_0000001173324617_p48701322192515"></a><a name="zh-cn_topic_0000001173324617_p48701322192515"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.00569943005699%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324617_p68701122112519"><a name="zh-cn_topic_0000001173324617_p68701122112519"></a><a name="zh-cn_topic_0000001173324617_p68701122112519"></a>flex容器当前行的交叉轴对齐格式，可选值为：</p>
<a name="zh-cn_topic_0000001173324617_ul3870122212514"></a><a name="zh-cn_topic_0000001173324617_ul3870122212514"></a><ul id="zh-cn_topic_0000001173324617_ul3870122212514"><li>stretch：弹性元素被在交叉轴方向被拉伸到与容器相同的高度或宽度。</li><li>flex-start：元素向交叉轴起点对齐。</li><li>flex-end：元素向交叉轴终点对齐。</li><li>center：元素在交叉轴居中。</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324617_row087015224259"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324617_p1870722182510"><a name="zh-cn_topic_0000001173324617_p1870722182510"></a><a name="zh-cn_topic_0000001173324617_p1870722182510"></a>align-content</p>
</td>
<td class="cellrowborder" valign="top" width="12.80871912808719%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324617_p18870122242511"><a name="zh-cn_topic_0000001173324617_p18870122242511"></a><a name="zh-cn_topic_0000001173324617_p18870122242511"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.498650134986503%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324617_p587016227256"><a name="zh-cn_topic_0000001173324617_p587016227256"></a><a name="zh-cn_topic_0000001173324617_p587016227256"></a>flex-start</p>
</td>
<td class="cellrowborder" valign="top" width="7.56924307569243%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324617_p587117228254"><a name="zh-cn_topic_0000001173324617_p587117228254"></a><a name="zh-cn_topic_0000001173324617_p587117228254"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.00569943005699%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324617_p168715228251"><a name="zh-cn_topic_0000001173324617_p168715228251"></a><a name="zh-cn_topic_0000001173324617_p168715228251"></a>交叉轴中有额外的空间时，多行内容对齐格式，可选值为：</p>
<a name="zh-cn_topic_0000001173324617_ul38718227256"></a><a name="zh-cn_topic_0000001173324617_ul38718227256"></a><ul id="zh-cn_topic_0000001173324617_ul38718227256"><li>flex-start：所有行从交叉轴起点开始填充。第一行的交叉轴起点边和容器的交叉轴起点边对齐。接下来的每一行紧跟前一行。</li><li>flex-end：所有行从交叉轴末尾开始填充。最后一行的交叉轴终点和容器的交叉轴终点对齐。同时所有后续行与前一个对齐。</li><li>center：所有行朝向容器的中心填充。每行互相紧挨，相对于容器居中对齐。容器的交叉轴起点边和第一行的距离相等于容器的交叉轴终点边和最后一行的距离。</li><li>space-between：所有行在容器中平均分布。相邻两行间距相等。容器的交叉轴起点边和终点边分别与第一行和最后一行的边对齐。</li><li>space-around：所有行在容器中平均分布，相邻两行间距相等。容器的交叉轴起点边和终点边分别与第一行和最后一行的距离是相邻两行间距的一半。</li></ul>
</td>
</tr>
</tbody>
</table>

## 事件<a name="zh-cn_topic_0000001173324617_section291933813509"></a>

支持[通用事件](js-components-common-events.md)。

## 方法<a name="zh-cn_topic_0000001173324617_section13156101584913"></a>

除支持[通用方法](js-components-common-methods.md)外，还支持如下方法：

<a name="zh-cn_topic_0000001173324617_t26fe2ddff8674cc38a3a1ec490b76e2f"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001173324617_r237544a789f74f4599b0688cdb75239a"><th class="cellrowborder" valign="top" width="23%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173324617_a897dc10a0e4e45bc94f02c558c679435"><a name="zh-cn_topic_0000001173324617_a897dc10a0e4e45bc94f02c558c679435"></a><a name="zh-cn_topic_0000001173324617_a897dc10a0e4e45bc94f02c558c679435"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="32%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173324617_ac86c6eca347b48e9a749143ecf54f38f"><a name="zh-cn_topic_0000001173324617_ac86c6eca347b48e9a749143ecf54f38f"></a><a name="zh-cn_topic_0000001173324617_ac86c6eca347b48e9a749143ecf54f38f"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="45%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173324617_a0050d08b0c5744de88990d92ef35d3b1"><a name="zh-cn_topic_0000001173324617_a0050d08b0c5744de88990d92ef35d3b1"></a><a name="zh-cn_topic_0000001173324617_a0050d08b0c5744de88990d92ef35d3b1"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001173324617_r08b3c58c981c42a390dc730286c9ce95"><td class="cellrowborder" valign="top" width="23%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173324617_p191499655120"><a name="zh-cn_topic_0000001173324617_p191499655120"></a><a name="zh-cn_topic_0000001173324617_p191499655120"></a>getColumns</p>
</td>
<td class="cellrowborder" valign="top" width="32%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173324617_p16149146105111"><a name="zh-cn_topic_0000001173324617_p16149146105111"></a><a name="zh-cn_topic_0000001173324617_p16149146105111"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173324617_p51491967515"><a name="zh-cn_topic_0000001173324617_p51491967515"></a><a name="zh-cn_topic_0000001173324617_p51491967515"></a>返回栅格容器列数</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324617_row89901747115010"><td class="cellrowborder" valign="top" width="23%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173324617_p121491167519"><a name="zh-cn_topic_0000001173324617_p121491167519"></a><a name="zh-cn_topic_0000001173324617_p121491167519"></a>getColumnWidth</p>
</td>
<td class="cellrowborder" valign="top" width="32%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173324617_p514914615113"><a name="zh-cn_topic_0000001173324617_p514914615113"></a><a name="zh-cn_topic_0000001173324617_p514914615113"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173324617_p81491761519"><a name="zh-cn_topic_0000001173324617_p81491761519"></a><a name="zh-cn_topic_0000001173324617_p81491761519"></a>返回栅格容器column宽度</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324617_row440095118508"><td class="cellrowborder" valign="top" width="23%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173324617_p614919617515"><a name="zh-cn_topic_0000001173324617_p614919617515"></a><a name="zh-cn_topic_0000001173324617_p614919617515"></a>getGutterWidth</p>
</td>
<td class="cellrowborder" valign="top" width="32%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173324617_p91498685115"><a name="zh-cn_topic_0000001173324617_p91498685115"></a><a name="zh-cn_topic_0000001173324617_p91498685115"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173324617_p51495615511"><a name="zh-cn_topic_0000001173324617_p51495615511"></a><a name="zh-cn_topic_0000001173324617_p51495615511"></a>返回栅格容器gutter宽度</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324617_row1340723513"><td class="cellrowborder" valign="top" width="23%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173324617_p31495615517"><a name="zh-cn_topic_0000001173324617_p31495615517"></a><a name="zh-cn_topic_0000001173324617_p31495615517"></a>getSizeType</p>
</td>
<td class="cellrowborder" valign="top" width="32%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173324617_p1014956185118"><a name="zh-cn_topic_0000001173324617_p1014956185118"></a><a name="zh-cn_topic_0000001173324617_p1014956185118"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173324617_p1414911617515"><a name="zh-cn_topic_0000001173324617_p1414911617515"></a><a name="zh-cn_topic_0000001173324617_p1414911617515"></a>返回当前容器响应尺寸类型（xs|sm|md|lg）</p>
</td>
</tr>
</tbody>
</table>

## 示例<a name="zh-cn_topic_0000001173324617_section132671420142616"></a>

详见[grid-col示例](js-components-grid-col.md#zh-cn_topic_0000001173164763_section2021865273710)。

