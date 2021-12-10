# progress<a name="ZH-CN_TOPIC_0000001173324665"></a>

进度条，用于显示内容加载或操作处理进度。

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
<tbody><tr id="row6863121675218"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p1751189523"><a name="p1751189523"></a><a name="p1751189523"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p17591819528"><a name="p17591819528"></a><a name="p17591819528"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p125151855212"><a name="p125151855212"></a><a name="p125151855212"></a>horizontal</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p14512188523"><a name="p14512188523"></a><a name="p14512188523"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p1510182522"><a name="p1510182522"></a><a name="p1510182522"></a>设置进度条的类型，该属性不支持动态修改，可选值为：</p>
<a name="ul11541820527"></a><a name="ul11541820527"></a><ul id="ul11541820527"><li>horizontal：线性进度条；</li><li>circular：loading样式进度条；</li><li>ring：圆环形进度条；</li><li>scale-ring：带刻度圆环形进度条</li><li>arc：弧形进度条。</li><li>eclipse<sup id="sup790255053720"><a name="sup790255053720"></a><a name="sup790255053720"></a>5+</sup>：圆形进度条，展现类似月圆月缺的进度展示效果。</li></ul>
</td>
</tr>
</tbody>
</table>

不同类型的进度条还支持不同的属性：

-   类型为horizontal、ring、scale-ring时，支持如下属性：

    <a name="table2074230113515"></a>
    <table><thead align="left"><tr id="row1474313083519"><th class="cellrowborder" valign="top" width="23.52%" id="mcps1.1.6.1.1"><p id="p107434016350"><a name="p107434016350"></a><a name="p107434016350"></a>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.76%" id="mcps1.1.6.1.2"><p id="p37433017350"><a name="p37433017350"></a><a name="p37433017350"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.72%" id="mcps1.1.6.1.3"><p id="p1274316043517"><a name="p1274316043517"></a><a name="p1274316043517"></a>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="8%" id="mcps1.1.6.1.4"><p id="p37437033519"><a name="p37437033519"></a><a name="p37437033519"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="45%" id="mcps1.1.6.1.5"><p id="p174314073517"><a name="p174314073517"></a><a name="p174314073517"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row974313023514"><td class="cellrowborder" valign="top" width="23.52%" headers="mcps1.1.6.1.1 "><p id="p674313053511"><a name="p674313053511"></a><a name="p674313053511"></a>percent</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.76%" headers="mcps1.1.6.1.2 "><p id="p16743708352"><a name="p16743708352"></a><a name="p16743708352"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.72%" headers="mcps1.1.6.1.3 "><p id="p157435053511"><a name="p157435053511"></a><a name="p157435053511"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="8%" headers="mcps1.1.6.1.4 "><p id="p1374370133511"><a name="p1374370133511"></a><a name="p1374370133511"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="45%" headers="mcps1.1.6.1.5 "><p id="p5743704359"><a name="p5743704359"></a><a name="p5743704359"></a>当前进度。取值范围为0-100。</p>
    </td>
    </tr>
    <tr id="row16743104352"><td class="cellrowborder" valign="top" width="23.52%" headers="mcps1.1.6.1.1 "><p id="p1874313063517"><a name="p1874313063517"></a><a name="p1874313063517"></a>secondarypercent</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.76%" headers="mcps1.1.6.1.2 "><p id="p127431015355"><a name="p127431015355"></a><a name="p127431015355"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.72%" headers="mcps1.1.6.1.3 "><p id="p1374317016354"><a name="p1374317016354"></a><a name="p1374317016354"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="8%" headers="mcps1.1.6.1.4 "><p id="p774320103519"><a name="p774320103519"></a><a name="p774320103519"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="45%" headers="mcps1.1.6.1.5 "><p id="p1974310173512"><a name="p1974310173512"></a><a name="p1974310173512"></a>次级进度。取值范围为0-100。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   类型为ring、scale-ring时，支持如下属性：

    <a name="table2311759143520"></a>
    <table><thead align="left"><tr id="row13121059163511"><th class="cellrowborder" valign="top" width="11%" id="mcps1.1.6.1.1"><p id="p6312155919354"><a name="p6312155919354"></a><a name="p6312155919354"></a>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="23%" id="mcps1.1.6.1.2"><p id="p73121259183512"><a name="p73121259183512"></a><a name="p73121259183512"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="13%" id="mcps1.1.6.1.3"><p id="p1312359103512"><a name="p1312359103512"></a><a name="p1312359103512"></a>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="8%" id="mcps1.1.6.1.4"><p id="p20312175983514"><a name="p20312175983514"></a><a name="p20312175983514"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="45%" id="mcps1.1.6.1.5"><p id="p123121159113515"><a name="p123121159113515"></a><a name="p123121159113515"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row0312195911351"><td class="cellrowborder" valign="top" width="11%" headers="mcps1.1.6.1.1 "><p id="p43126599354"><a name="p43126599354"></a><a name="p43126599354"></a>clockwise</p>
    </td>
    <td class="cellrowborder" valign="top" width="23%" headers="mcps1.1.6.1.2 "><p id="p11312659113520"><a name="p11312659113520"></a><a name="p11312659113520"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="13%" headers="mcps1.1.6.1.3 "><p id="p6312359133511"><a name="p6312359133511"></a><a name="p6312359133511"></a>true</p>
    </td>
    <td class="cellrowborder" valign="top" width="8%" headers="mcps1.1.6.1.4 "><p id="p131218599350"><a name="p131218599350"></a><a name="p131218599350"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="45%" headers="mcps1.1.6.1.5 "><p id="p12312175919356"><a name="p12312175919356"></a><a name="p12312175919356"></a>圆环形进度条是否采用顺时针。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   类型为arc、eclipse<sup>5+</sup>时，支持如下属性：

    <a name="table7731318123620"></a>
    <table><thead align="left"><tr id="row107321518113612"><th class="cellrowborder" valign="top" width="23.52%" id="mcps1.1.6.1.1"><p id="p9732118103619"><a name="p9732118103619"></a><a name="p9732118103619"></a>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.76%" id="mcps1.1.6.1.2"><p id="p107321618103616"><a name="p107321618103616"></a><a name="p107321618103616"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.72%" id="mcps1.1.6.1.3"><p id="p127321718173617"><a name="p127321718173617"></a><a name="p127321718173617"></a>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="8%" id="mcps1.1.6.1.4"><p id="p17321418153617"><a name="p17321418153617"></a><a name="p17321418153617"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="45%" id="mcps1.1.6.1.5"><p id="p573281814364"><a name="p573281814364"></a><a name="p573281814364"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1773251817366"><td class="cellrowborder" valign="top" width="23.52%" headers="mcps1.1.6.1.1 "><p id="p27322018143612"><a name="p27322018143612"></a><a name="p27322018143612"></a>percent</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.76%" headers="mcps1.1.6.1.2 "><p id="p37321718113612"><a name="p37321718113612"></a><a name="p37321718113612"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.72%" headers="mcps1.1.6.1.3 "><p id="p12732171817366"><a name="p12732171817366"></a><a name="p12732171817366"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="8%" headers="mcps1.1.6.1.4 "><p id="p8732101843613"><a name="p8732101843613"></a><a name="p8732101843613"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="45%" headers="mcps1.1.6.1.5 "><p id="p14732318113613"><a name="p14732318113613"></a><a name="p14732318113613"></a>当前进度。取值范围为0-100。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 样式<a name="section5775351116"></a>

除支持[通用样式](js-components-common-styles.md)外，还支持如下样式：

type=horizontal

<a name="t3c94bfbdec6f4ef08febb9d98feb69de"></a>
<table><thead align="left"><tr id="r53b2a254c9d645feb7260feb7770ab81"><th class="cellrowborder" valign="top" width="15.841584158415841%" id="mcps1.1.6.1.1"><p id="a5d8aa9ff3111452b8d0de276c88b44b5"><a name="a5d8aa9ff3111452b8d0de276c88b44b5"></a><a name="a5d8aa9ff3111452b8d0de276c88b44b5"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="11.941194119411943%" id="mcps1.1.6.1.2"><p id="afca70efa86e8438ebc402dcba820a465"><a name="afca70efa86e8438ebc402dcba820a465"></a><a name="afca70efa86e8438ebc402dcba820a465"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="26.672667266726673%" id="mcps1.1.6.1.3"><p id="ae063aedcf344463b9e0c5b2363d9441a"><a name="ae063aedcf344463b9e0c5b2363d9441a"></a><a name="ae063aedcf344463b9e0c5b2363d9441a"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="6.9306930693069315%" id="mcps1.1.6.1.4"><p id="aba5cfe9b5b3c47ca890b6fca516a68d2"><a name="aba5cfe9b5b3c47ca890b6fca516a68d2"></a><a name="aba5cfe9b5b3c47ca890b6fca516a68d2"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="38.613861386138616%" id="mcps1.1.6.1.5"><p id="a91770a169ad44da99a22c882ce41bf86"><a name="a91770a169ad44da99a22c882ce41bf86"></a><a name="a91770a169ad44da99a22c882ce41bf86"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="r8d7d69585da2411897bd21e25bdf945b"><td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.6.1.1 "><p id="a76c0c59c9ef342648d24b3def45827d8"><a name="a76c0c59c9ef342648d24b3def45827d8"></a><a name="a76c0c59c9ef342648d24b3def45827d8"></a>color</p>
</td>
<td class="cellrowborder" valign="top" width="11.941194119411943%" headers="mcps1.1.6.1.2 "><p id="a7e7fc8b3939f4d8c8da8246c80ae85b8"><a name="a7e7fc8b3939f4d8c8da8246c80ae85b8"></a><a name="a7e7fc8b3939f4d8c8da8246c80ae85b8"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="26.672667266726673%" headers="mcps1.1.6.1.3 "><p id="p57261722152113"><a name="p57261722152113"></a><a name="p57261722152113"></a>#ff007dff</p>
</td>
<td class="cellrowborder" valign="top" width="6.9306930693069315%" headers="mcps1.1.6.1.4 "><p id="a45701b1485b44c0f97505e521710d4de"><a name="a45701b1485b44c0f97505e521710d4de"></a><a name="a45701b1485b44c0f97505e521710d4de"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="38.613861386138616%" headers="mcps1.1.6.1.5 "><p id="a5e442a4aedc84f0c95aa140a6ec8713c"><a name="a5e442a4aedc84f0c95aa140a6ec8713c"></a><a name="a5e442a4aedc84f0c95aa140a6ec8713c"></a>设置进度条的颜色。</p>
</td>
</tr>
<tr id="rfadd2e86d5a547398a318b82fe88ddcd"><td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.6.1.1 "><p id="ae2d0777495164c409e85313fdf1c6a78"><a name="ae2d0777495164c409e85313fdf1c6a78"></a><a name="ae2d0777495164c409e85313fdf1c6a78"></a>stroke-width</p>
</td>
<td class="cellrowborder" valign="top" width="11.941194119411943%" headers="mcps1.1.6.1.2 "><p id="ab0e2ad53dc6545fab26a0dcaedafadcf"><a name="ab0e2ad53dc6545fab26a0dcaedafadcf"></a><a name="ab0e2ad53dc6545fab26a0dcaedafadcf"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="26.672667266726673%" headers="mcps1.1.6.1.3 "><p id="p163627544235"><a name="p163627544235"></a><a name="p163627544235"></a>4px</p>
<p id="p149261166381"><a name="p149261166381"></a><a name="p149261166381"></a></p>
</td>
<td class="cellrowborder" valign="top" width="6.9306930693069315%" headers="mcps1.1.6.1.4 "><p id="a33f30b29f52e4f899dc0086815e1474c"><a name="a33f30b29f52e4f899dc0086815e1474c"></a><a name="a33f30b29f52e4f899dc0086815e1474c"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="38.613861386138616%" headers="mcps1.1.6.1.5 "><p id="acd7ffaee82cb4bfcb75c4b4c87dc512b"><a name="acd7ffaee82cb4bfcb75c4b4c87dc512b"></a><a name="acd7ffaee82cb4bfcb75c4b4c87dc512b"></a>设置进度条的宽度。</p>
</td>
</tr>
<tr id="row21738425241"><td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.6.1.1 "><p id="p02571753202620"><a name="p02571753202620"></a><a name="p02571753202620"></a>background-color</p>
</td>
<td class="cellrowborder" valign="top" width="11.941194119411943%" headers="mcps1.1.6.1.2 "><p id="p8257155332614"><a name="p8257155332614"></a><a name="p8257155332614"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="26.672667266726673%" headers="mcps1.1.6.1.3 "><p id="p1989061072811"><a name="p1989061072811"></a><a name="p1989061072811"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="6.9306930693069315%" headers="mcps1.1.6.1.4 "><p id="p82571153192611"><a name="p82571153192611"></a><a name="p82571153192611"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="38.613861386138616%" headers="mcps1.1.6.1.5 "><p id="p106571314275"><a name="p106571314275"></a><a name="p106571314275"></a>设置进度条的背景色。</p>
</td>
</tr>
<tr id="row517332532717"><td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.6.1.1 "><p id="p51731025172713"><a name="p51731025172713"></a><a name="p51731025172713"></a>secondary-color</p>
</td>
<td class="cellrowborder" valign="top" width="11.941194119411943%" headers="mcps1.1.6.1.2 "><p id="p1617322572712"><a name="p1617322572712"></a><a name="p1617322572712"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="26.672667266726673%" headers="mcps1.1.6.1.3 "><p id="p117332552710"><a name="p117332552710"></a><a name="p117332552710"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="6.9306930693069315%" headers="mcps1.1.6.1.4 "><p id="p1917315255277"><a name="p1917315255277"></a><a name="p1917315255277"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="38.613861386138616%" headers="mcps1.1.6.1.5 "><p id="p2174122512271"><a name="p2174122512271"></a><a name="p2174122512271"></a>设置次级进度条的颜色。</p>
</td>
</tr>
</tbody>
</table>

type=circular

<a name="table1155720932812"></a>
<table><thead align="left"><tr id="row1655719918284"><th class="cellrowborder" valign="top" width="15.841584158415841%" id="mcps1.1.6.1.1"><p id="p95572913285"><a name="p95572913285"></a><a name="p95572913285"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="11.881188118811883%" id="mcps1.1.6.1.2"><p id="p75579962816"><a name="p75579962816"></a><a name="p75579962816"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="26.732673267326728%" id="mcps1.1.6.1.3"><p id="p4557896289"><a name="p4557896289"></a><a name="p4557896289"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="6.9306930693069315%" id="mcps1.1.6.1.4"><p id="p75576914287"><a name="p75576914287"></a><a name="p75576914287"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="38.613861386138616%" id="mcps1.1.6.1.5"><p id="p1055711952815"><a name="p1055711952815"></a><a name="p1055711952815"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row755710910285"><td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.6.1.1 "><p id="p1055818912284"><a name="p1055818912284"></a><a name="p1055818912284"></a>color</p>
</td>
<td class="cellrowborder" valign="top" width="11.881188118811883%" headers="mcps1.1.6.1.2 "><p id="p115587942811"><a name="p115587942811"></a><a name="p115587942811"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="26.732673267326728%" headers="mcps1.1.6.1.3 "><p id="p14706141316531"><a name="p14706141316531"></a><a name="p14706141316531"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="6.9306930693069315%" headers="mcps1.1.6.1.4 "><p id="p05583932819"><a name="p05583932819"></a><a name="p05583932819"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="38.613861386138616%" headers="mcps1.1.6.1.5 "><p id="p1955818992820"><a name="p1955818992820"></a><a name="p1955818992820"></a>loading进度条上的圆点颜色。</p>
</td>
</tr>
</tbody>
</table>

type=ring, scale-ring

<a name="table1537513464181"></a>
<table><thead align="left"><tr id="row1237554618186"><th class="cellrowborder" valign="top" width="15.841584158415841%" id="mcps1.1.6.1.1"><p id="p637584661816"><a name="p637584661816"></a><a name="p637584661816"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="24.152415241524153%" id="mcps1.1.6.1.2"><p id="p53751346191816"><a name="p53751346191816"></a><a name="p53751346191816"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="14.461446144614461%" id="mcps1.1.6.1.3"><p id="p183751046171811"><a name="p183751046171811"></a><a name="p183751046171811"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="6.9306930693069315%" id="mcps1.1.6.1.4"><p id="p173752046131812"><a name="p173752046131812"></a><a name="p173752046131812"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="38.613861386138616%" id="mcps1.1.6.1.5"><p id="p19375154617185"><a name="p19375154617185"></a><a name="p19375154617185"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1837534691818"><td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.6.1.1 "><p id="p3849195472110"><a name="p3849195472110"></a><a name="p3849195472110"></a>color</p>
</td>
<td class="cellrowborder" valign="top" width="24.152415241524153%" headers="mcps1.1.6.1.2 "><p id="p14849205417213"><a name="p14849205417213"></a><a name="p14849205417213"></a>&lt;color&gt; | &lt;linear-gradient&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="14.461446144614461%" headers="mcps1.1.6.1.3 "><p id="p48495548218"><a name="p48495548218"></a><a name="p48495548218"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="6.9306930693069315%" headers="mcps1.1.6.1.4 "><p id="p284914543213"><a name="p284914543213"></a><a name="p284914543213"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="38.613861386138616%" headers="mcps1.1.6.1.5 "><p id="p151721122192918"><a name="p151721122192918"></a><a name="p151721122192918"></a>环形进度条的颜色，ring类型支持线性渐变色设置。</p>
<div class="note" id="note11079430164"><a name="note11079430164"></a><a name="note11079430164"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="p1010744361610"><a name="p1010744361610"></a><a name="p1010744361610"></a>线性渐变色仅支持两个颜色参数设置格式，如color = linear-gradient(#ff0000, #00ff00)。</p>
</div></div>
</td>
</tr>
<tr id="row14416102211213"><td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.6.1.1 "><p id="p7850135412217"><a name="p7850135412217"></a><a name="p7850135412217"></a>background-color</p>
</td>
<td class="cellrowborder" valign="top" width="24.152415241524153%" headers="mcps1.1.6.1.2 "><p id="p188504547217"><a name="p188504547217"></a><a name="p188504547217"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="14.461446144614461%" headers="mcps1.1.6.1.3 "><p id="p128500549213"><a name="p128500549213"></a><a name="p128500549213"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="6.9306930693069315%" headers="mcps1.1.6.1.4 "><p id="p985015547217"><a name="p985015547217"></a><a name="p985015547217"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="38.613861386138616%" headers="mcps1.1.6.1.5 "><p id="p1585014540215"><a name="p1585014540215"></a><a name="p1585014540215"></a>环形进度条的背景色。</p>
</td>
</tr>
<tr id="row1556129122116"><td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.6.1.1 "><p id="p178506545218"><a name="p178506545218"></a><a name="p178506545218"></a>secondary-color</p>
</td>
<td class="cellrowborder" valign="top" width="24.152415241524153%" headers="mcps1.1.6.1.2 "><p id="p14850185442115"><a name="p14850185442115"></a><a name="p14850185442115"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="14.461446144614461%" headers="mcps1.1.6.1.3 "><p id="p1285012546213"><a name="p1285012546213"></a><a name="p1285012546213"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="6.9306930693069315%" headers="mcps1.1.6.1.4 "><p id="p6850654172116"><a name="p6850654172116"></a><a name="p6850654172116"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="38.613861386138616%" headers="mcps1.1.6.1.5 "><p id="p16850115482113"><a name="p16850115482113"></a><a name="p16850115482113"></a>环形次级进度条的颜色。</p>
</td>
</tr>
<tr id="row109611629172118"><td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.6.1.1 "><p id="p639523362212"><a name="p639523362212"></a><a name="p639523362212"></a>stroke-width</p>
</td>
<td class="cellrowborder" valign="top" width="24.152415241524153%" headers="mcps1.1.6.1.2 "><p id="p1239520334229"><a name="p1239520334229"></a><a name="p1239520334229"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="14.461446144614461%" headers="mcps1.1.6.1.3 "><p id="p1798517818391"><a name="p1798517818391"></a><a name="p1798517818391"></a>10px</p>
</td>
<td class="cellrowborder" valign="top" width="6.9306930693069315%" headers="mcps1.1.6.1.4 "><p id="p839517333229"><a name="p839517333229"></a><a name="p839517333229"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="38.613861386138616%" headers="mcps1.1.6.1.5 "><p id="p113951633172217"><a name="p113951633172217"></a><a name="p113951633172217"></a>环形进度条的宽度。</p>
</td>
</tr>
<tr id="row6895103153610"><td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.6.1.1 "><p id="p2087515118365"><a name="p2087515118365"></a><a name="p2087515118365"></a>scale-width</p>
</td>
<td class="cellrowborder" valign="top" width="24.152415241524153%" headers="mcps1.1.6.1.2 "><p id="p14875181119368"><a name="p14875181119368"></a><a name="p14875181119368"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="14.461446144614461%" headers="mcps1.1.6.1.3 "><p id="p7875141183616"><a name="p7875141183616"></a><a name="p7875141183616"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="6.9306930693069315%" headers="mcps1.1.6.1.4 "><p id="p68751411153613"><a name="p68751411153613"></a><a name="p68751411153613"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="38.613861386138616%" headers="mcps1.1.6.1.5 "><p id="p5875211113612"><a name="p5875211113612"></a><a name="p5875211113612"></a>带刻度的环形进度条的刻度粗细，类型为scale-ring生效。</p>
</td>
</tr>
<tr id="row167446753610"><td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.6.1.1 "><p id="p1687516115364"><a name="p1687516115364"></a><a name="p1687516115364"></a>scale-number</p>
</td>
<td class="cellrowborder" valign="top" width="24.152415241524153%" headers="mcps1.1.6.1.2 "><p id="p08765113363"><a name="p08765113363"></a><a name="p08765113363"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="14.461446144614461%" headers="mcps1.1.6.1.3 "><p id="p7876131133618"><a name="p7876131133618"></a><a name="p7876131133618"></a>120</p>
</td>
<td class="cellrowborder" valign="top" width="6.9306930693069315%" headers="mcps1.1.6.1.4 "><p id="p7876711133618"><a name="p7876711133618"></a><a name="p7876711133618"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="38.613861386138616%" headers="mcps1.1.6.1.5 "><p id="p1687671117364"><a name="p1687671117364"></a><a name="p1687671117364"></a>带刻度的环形进度条的刻度数量，类型为scale-ring生效。</p>
</td>
</tr>
</tbody>
</table>

type=arc

<a name="table146111227294"></a>
<table><thead align="left"><tr id="row961102182918"><th class="cellrowborder" valign="top" width="20.842084208420843%" id="mcps1.1.6.1.1"><p id="p1561114219295"><a name="p1561114219295"></a><a name="p1561114219295"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="12.221222122212222%" id="mcps1.1.6.1.2"><p id="p1661116214291"><a name="p1661116214291"></a><a name="p1661116214291"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="13.851385138513853%" id="mcps1.1.6.1.3"><p id="p86111628290"><a name="p86111628290"></a><a name="p86111628290"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="11.08110811081108%" id="mcps1.1.6.1.4"><p id="p126111820294"><a name="p126111820294"></a><a name="p126111820294"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="42.004200420042004%" id="mcps1.1.6.1.5"><p id="p16611172162919"><a name="p16611172162919"></a><a name="p16611172162919"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row161172152916"><td class="cellrowborder" valign="top" width="20.842084208420843%" headers="mcps1.1.6.1.1 "><p id="p1732210516366"><a name="p1732210516366"></a><a name="p1732210516366"></a>color</p>
</td>
<td class="cellrowborder" valign="top" width="12.221222122212222%" headers="mcps1.1.6.1.2 "><p id="p18322145153610"><a name="p18322145153610"></a><a name="p18322145153610"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.851385138513853%" headers="mcps1.1.6.1.3 "><p id="p1389016133339"><a name="p1389016133339"></a><a name="p1389016133339"></a>-</p>
<p id="p23221751143616"><a name="p23221751143616"></a><a name="p23221751143616"></a></p>
</td>
<td class="cellrowborder" valign="top" width="11.08110811081108%" headers="mcps1.1.6.1.4 "><p id="p432255116368"><a name="p432255116368"></a><a name="p432255116368"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="42.004200420042004%" headers="mcps1.1.6.1.5 "><p id="p2322051193614"><a name="p2322051193614"></a><a name="p2322051193614"></a>弧形进度条的颜色。</p>
</td>
</tr>
<tr id="row615084732920"><td class="cellrowborder" valign="top" width="20.842084208420843%" headers="mcps1.1.6.1.1 "><p id="p19233161103811"><a name="p19233161103811"></a><a name="p19233161103811"></a>background-color</p>
</td>
<td class="cellrowborder" valign="top" width="12.221222122212222%" headers="mcps1.1.6.1.2 "><p id="p1223319112386"><a name="p1223319112386"></a><a name="p1223319112386"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.851385138513853%" headers="mcps1.1.6.1.3 "><p id="p137148216342"><a name="p137148216342"></a><a name="p137148216342"></a>-</p>
<p id="p7233111133814"><a name="p7233111133814"></a><a name="p7233111133814"></a></p>
</td>
<td class="cellrowborder" valign="top" width="11.08110811081108%" headers="mcps1.1.6.1.4 "><p id="p1723371143810"><a name="p1723371143810"></a><a name="p1723371143810"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="42.004200420042004%" headers="mcps1.1.6.1.5 "><p id="p6233511381"><a name="p6233511381"></a><a name="p6233511381"></a>弧形进度条的背景色。</p>
</td>
</tr>
<tr id="row142659209408"><td class="cellrowborder" valign="top" width="20.842084208420843%" headers="mcps1.1.6.1.1 "><p id="p98738424715"><a name="p98738424715"></a><a name="p98738424715"></a>stroke-width</p>
</td>
<td class="cellrowborder" valign="top" width="12.221222122212222%" headers="mcps1.1.6.1.2 "><p id="p1687319424713"><a name="p1687319424713"></a><a name="p1687319424713"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.851385138513853%" headers="mcps1.1.6.1.3 "><p id="p10840175014427"><a name="p10840175014427"></a><a name="p10840175014427"></a>4px</p>
</td>
<td class="cellrowborder" valign="top" width="11.08110811081108%" headers="mcps1.1.6.1.4 "><p id="p1873342671"><a name="p1873342671"></a><a name="p1873342671"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="42.004200420042004%" headers="mcps1.1.6.1.5 "><p id="p188730421175"><a name="p188730421175"></a><a name="p188730421175"></a>弧形进度条的宽度。</p>
<div class="note" id="note1436241013318"><a name="note1436241013318"></a><a name="note1436241013318"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="p43626101533"><a name="p43626101533"></a><a name="p43626101533"></a>进度条宽度越大，进度条越靠近圆心，进度条始终在半径区域内。</p>
</div></div>
</td>
</tr>
<tr id="row1280652394013"><td class="cellrowborder" valign="top" width="20.842084208420843%" headers="mcps1.1.6.1.1 "><p id="p1192581376"><a name="p1192581376"></a><a name="p1192581376"></a>start-angle</p>
</td>
<td class="cellrowborder" valign="top" width="12.221222122212222%" headers="mcps1.1.6.1.2 "><p id="p1719258277"><a name="p1719258277"></a><a name="p1719258277"></a>&lt;deg&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.851385138513853%" headers="mcps1.1.6.1.3 "><p id="p320958271"><a name="p320958271"></a><a name="p320958271"></a>240</p>
</td>
<td class="cellrowborder" valign="top" width="11.08110811081108%" headers="mcps1.1.6.1.4 "><p id="p16203581878"><a name="p16203581878"></a><a name="p16203581878"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="42.004200420042004%" headers="mcps1.1.6.1.5 "><p id="p112012582717"><a name="p112012582717"></a><a name="p112012582717"></a>弧形进度条起始角度，以时钟0点为基线，取值范围为0到360（顺时针）。</p>
</td>
</tr>
<tr id="row16108193116405"><td class="cellrowborder" valign="top" width="20.842084208420843%" headers="mcps1.1.6.1.1 "><p id="p204511458375"><a name="p204511458375"></a><a name="p204511458375"></a>total-angle</p>
</td>
<td class="cellrowborder" valign="top" width="12.221222122212222%" headers="mcps1.1.6.1.2 "><p id="p154521558371"><a name="p154521558371"></a><a name="p154521558371"></a>&lt;deg&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.851385138513853%" headers="mcps1.1.6.1.3 "><p id="p74521558678"><a name="p74521558678"></a><a name="p74521558678"></a>240</p>
</td>
<td class="cellrowborder" valign="top" width="11.08110811081108%" headers="mcps1.1.6.1.4 "><p id="p14521158774"><a name="p14521158774"></a><a name="p14521158774"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="42.004200420042004%" headers="mcps1.1.6.1.5 "><p id="p745211583716"><a name="p745211583716"></a><a name="p745211583716"></a>弧形进度条总长度，范围为-360到360，负数标识起点到终点为逆时针。</p>
</td>
</tr>
<tr id="row132153110406"><td class="cellrowborder" valign="top" width="20.842084208420843%" headers="mcps1.1.6.1.1 "><p id="p2489145710819"><a name="p2489145710819"></a><a name="p2489145710819"></a>center-x</p>
</td>
<td class="cellrowborder" valign="top" width="12.221222122212222%" headers="mcps1.1.6.1.2 "><p id="p1378435564714"><a name="p1378435564714"></a><a name="p1378435564714"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.851385138513853%" headers="mcps1.1.6.1.3 "><p id="p548911574817"><a name="p548911574817"></a><a name="p548911574817"></a>弧形进度条宽度的一半</p>
</td>
<td class="cellrowborder" valign="top" width="11.08110811081108%" headers="mcps1.1.6.1.4 "><p id="p144897571081"><a name="p144897571081"></a><a name="p144897571081"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="42.004200420042004%" headers="mcps1.1.6.1.5 "><p id="p154894570813"><a name="p154894570813"></a><a name="p154894570813"></a>弧形进度条中心位置，（坐标原点为组件左上角顶点）。该样式需要和center-y和radius一起使用。</p>
</td>
</tr>
<tr id="row1488143111409"><td class="cellrowborder" valign="top" width="20.842084208420843%" headers="mcps1.1.6.1.1 "><p id="p1898218571884"><a name="p1898218571884"></a><a name="p1898218571884"></a>center-y</p>
</td>
<td class="cellrowborder" valign="top" width="12.221222122212222%" headers="mcps1.1.6.1.2 "><p id="p76431057204714"><a name="p76431057204714"></a><a name="p76431057204714"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.851385138513853%" headers="mcps1.1.6.1.3 "><p id="p4982557182"><a name="p4982557182"></a><a name="p4982557182"></a>弧形进度条高度的一半</p>
</td>
<td class="cellrowborder" valign="top" width="11.08110811081108%" headers="mcps1.1.6.1.4 "><p id="p1982165710812"><a name="p1982165710812"></a><a name="p1982165710812"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="42.004200420042004%" headers="mcps1.1.6.1.5 "><p id="p09827579819"><a name="p09827579819"></a><a name="p09827579819"></a>弧形进度条中心位置，（坐标原点为组件左上角顶点）。该样式需要和center-x和radius一起使用。</p>
</td>
</tr>
<tr id="row294916317406"><td class="cellrowborder" valign="top" width="20.842084208420843%" headers="mcps1.1.6.1.1 "><p id="p1073135912815"><a name="p1073135912815"></a><a name="p1073135912815"></a>radius</p>
</td>
<td class="cellrowborder" valign="top" width="12.221222122212222%" headers="mcps1.1.6.1.2 "><p id="p6732759386"><a name="p6732759386"></a><a name="p6732759386"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.851385138513853%" headers="mcps1.1.6.1.3 "><p id="p127321959086"><a name="p127321959086"></a><a name="p127321959086"></a>弧形进度条宽高最小值的一半</p>
</td>
<td class="cellrowborder" valign="top" width="11.08110811081108%" headers="mcps1.1.6.1.4 "><p id="p197325591783"><a name="p197325591783"></a><a name="p197325591783"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="42.004200420042004%" headers="mcps1.1.6.1.5 "><p id="p2732759982"><a name="p2732759982"></a><a name="p2732759982"></a>弧形进度条半径，该样式需要和center-x和center-y一起使用。</p>
</td>
</tr>
</tbody>
</table>

type=eclipse<sup>5+</sup>

<a name="table5191155852510"></a>
<table><thead align="left"><tr id="row119205815258"><th class="cellrowborder" valign="top" width="20.842084208420843%" id="mcps1.1.6.1.1"><p id="p1719211587252"><a name="p1719211587252"></a><a name="p1719211587252"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="12.221222122212222%" id="mcps1.1.6.1.2"><p id="p15192185817259"><a name="p15192185817259"></a><a name="p15192185817259"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="13.851385138513853%" id="mcps1.1.6.1.3"><p id="p11192125852514"><a name="p11192125852514"></a><a name="p11192125852514"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="11.08110811081108%" id="mcps1.1.6.1.4"><p id="p16192155813256"><a name="p16192155813256"></a><a name="p16192155813256"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="42.004200420042004%" id="mcps1.1.6.1.5"><p id="p91921583256"><a name="p91921583256"></a><a name="p91921583256"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1819265882513"><td class="cellrowborder" valign="top" width="20.842084208420843%" headers="mcps1.1.6.1.1 "><p id="p181923589254"><a name="p181923589254"></a><a name="p181923589254"></a>color</p>
</td>
<td class="cellrowborder" valign="top" width="12.221222122212222%" headers="mcps1.1.6.1.2 "><p id="p11192258182515"><a name="p11192258182515"></a><a name="p11192258182515"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.851385138513853%" headers="mcps1.1.6.1.3 "><p id="p519235819253"><a name="p519235819253"></a><a name="p519235819253"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="11.08110811081108%" headers="mcps1.1.6.1.4 "><p id="p19192115802515"><a name="p19192115802515"></a><a name="p19192115802515"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="42.004200420042004%" headers="mcps1.1.6.1.5 "><p id="p1019225811258"><a name="p1019225811258"></a><a name="p1019225811258"></a>圆形进度条的颜色。</p>
</td>
</tr>
<tr id="row11920586256"><td class="cellrowborder" valign="top" width="20.842084208420843%" headers="mcps1.1.6.1.1 "><p id="p719210585259"><a name="p719210585259"></a><a name="p719210585259"></a>background-color</p>
</td>
<td class="cellrowborder" valign="top" width="12.221222122212222%" headers="mcps1.1.6.1.2 "><p id="p121920588253"><a name="p121920588253"></a><a name="p121920588253"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.851385138513853%" headers="mcps1.1.6.1.3 "><p id="p16193125814250"><a name="p16193125814250"></a><a name="p16193125814250"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="11.08110811081108%" headers="mcps1.1.6.1.4 "><p id="p4193115813254"><a name="p4193115813254"></a><a name="p4193115813254"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="42.004200420042004%" headers="mcps1.1.6.1.5 "><p id="p1319395813257"><a name="p1319395813257"></a><a name="p1319395813257"></a>弧形进度条的背景色。</p>
</td>
</tr>
</tbody>
</table>

## 事件<a name="section16580153964314"></a>

支持[通用事件](js-components-common-events.md)。

## 方法<a name="section2279124532420"></a>

支持[通用方法](js-components-common-methods.md)。

## 示例<a name="section493033510346"></a>

```
<!--xxx.hml -->
<div class="container">
  <progress class="min-progress" type="scale-ring"  percent= "10" secondarypercent="50"></progress>
  <progress class="min-progress" type="horizontal" percent= "10" secondarypercent="50"></progress>
  <progress class="min-progress" type="arc" percent= "10"></progress>
  <progress class="min-progress" type="ring" percent= "10" secondarypercent="50"></progress>
</div>
```

```
/* xxx.css */
.container {
  flex-direction: column;
  height: 100%;
  width: 100%;
  align-items: center;
}
.min-progress {
  width: 300px;
  height: 300px;
}
```

![](figures/progress.png)

