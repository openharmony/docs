# text<a name="ZH-CN_TOPIC_0000001164577156"></a>

文本，用于呈现一段信息。

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>-   从API Version 7 开始支持。
>-   文本的展示内容需要写在元素标签内，可嵌套tspan子元素标签分段，可嵌套textPath子元素标签按指定路径绘制。
>-   只支持被父元素标签svg嵌套。
>-   只支持默认字体sans-serif

## 权限列表<a name="zh-cn_topic_0000001173164689_section11257113618419"></a>

无

## 子组件<a name="zh-cn_topic_0000001173164689_section9288143101012"></a>

支持tspan、textpath、animate、animateTransform。

## 属性<a name="zh-cn_topic_0000001173164689_section2907183951110"></a>

支持以下表格中的属性。

<a name="zh-cn_topic_0000001173164689_table20633101642315"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001173164689_row663331618238"><th class="cellrowborder" valign="top" width="16.84%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001173164689_aaf1247770b244944bbcc9f28d9a6f00b"><a name="zh-cn_topic_0000001173164689_aaf1247770b244944bbcc9f28d9a6f00b"></a><a name="zh-cn_topic_0000001173164689_aaf1247770b244944bbcc9f28d9a6f00b"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="29.4%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001173164689_a6efc3502761f4faf9630e484280f75b6"><a name="zh-cn_topic_0000001173164689_a6efc3502761f4faf9630e484280f75b6"></a><a name="zh-cn_topic_0000001173164689_a6efc3502761f4faf9630e484280f75b6"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.4%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001173164689_a27a37273d9ad47569ddbcb8db985d302"><a name="zh-cn_topic_0000001173164689_a27a37273d9ad47569ddbcb8db985d302"></a><a name="zh-cn_topic_0000001173164689_a27a37273d9ad47569ddbcb8db985d302"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.6%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001173164689_p824610360217"><a name="zh-cn_topic_0000001173164689_p824610360217"></a><a name="zh-cn_topic_0000001173164689_p824610360217"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="35.76%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001173164689_a2ff3361bfd3b420ba4967452d2ddd098"><a name="zh-cn_topic_0000001173164689_a2ff3361bfd3b420ba4967452d2ddd098"></a><a name="zh-cn_topic_0000001173164689_a2ff3361bfd3b420ba4967452d2ddd098"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001173164689_row36332165231"><td class="cellrowborder" valign="top" width="16.84%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164689_a83b6dd280109466fb015e64de1ef4df3"><a name="zh-cn_topic_0000001173164689_a83b6dd280109466fb015e64de1ef4df3"></a><a name="zh-cn_topic_0000001173164689_a83b6dd280109466fb015e64de1ef4df3"></a>id</p>
</td>
<td class="cellrowborder" valign="top" width="29.4%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164689_abc38fa2b85854bc687af75eb17a00a4d"><a name="zh-cn_topic_0000001173164689_abc38fa2b85854bc687af75eb17a00a4d"></a><a name="zh-cn_topic_0000001173164689_abc38fa2b85854bc687af75eb17a00a4d"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.4%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164689_a8d12e4af905d4743a5ec9cd6018d2972"><a name="zh-cn_topic_0000001173164689_a8d12e4af905d4743a5ec9cd6018d2972"></a><a name="zh-cn_topic_0000001173164689_a8d12e4af905d4743a5ec9cd6018d2972"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.6%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164689_p42461736102118"><a name="zh-cn_topic_0000001173164689_p42461736102118"></a><a name="zh-cn_topic_0000001173164689_p42461736102118"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164689_a1a1731af05554f119fa365748f276bb2"><a name="zh-cn_topic_0000001173164689_a1a1731af05554f119fa365748f276bb2"></a><a name="zh-cn_topic_0000001173164689_a1a1731af05554f119fa365748f276bb2"></a>组件的唯一标识。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164689_row1634171618236"><td class="cellrowborder" valign="top" width="16.84%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164689_a3cf785e2a2a043268d168f58d59207c8"><a name="zh-cn_topic_0000001173164689_a3cf785e2a2a043268d168f58d59207c8"></a><a name="zh-cn_topic_0000001173164689_a3cf785e2a2a043268d168f58d59207c8"></a>x</p>
</td>
<td class="cellrowborder" valign="top" width="29.4%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164689_aa9b258d23e1e425dbc2ffe8edbc91a42"><a name="zh-cn_topic_0000001173164689_aa9b258d23e1e425dbc2ffe8edbc91a42"></a><a name="zh-cn_topic_0000001173164689_aa9b258d23e1e425dbc2ffe8edbc91a42"></a>&lt;length&gt;|&lt;percentage&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.4%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164689_ac312df4f14444c98955ed055456848a7"><a name="zh-cn_topic_0000001173164689_ac312df4f14444c98955ed055456848a7"></a><a name="zh-cn_topic_0000001173164689_ac312df4f14444c98955ed055456848a7"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.6%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164689_p1624612362219"><a name="zh-cn_topic_0000001173164689_p1624612362219"></a><a name="zh-cn_topic_0000001173164689_p1624612362219"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164689_p62121758111517"><a name="zh-cn_topic_0000001173164689_p62121758111517"></a><a name="zh-cn_topic_0000001173164689_p62121758111517"></a>设置组件左上角x轴坐标</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164689_row1259531661611"><td class="cellrowborder" valign="top" width="16.84%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164689_p1359601671613"><a name="zh-cn_topic_0000001173164689_p1359601671613"></a><a name="zh-cn_topic_0000001173164689_p1359601671613"></a>y</p>
</td>
<td class="cellrowborder" valign="top" width="29.4%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164689_p65967163165"><a name="zh-cn_topic_0000001173164689_p65967163165"></a><a name="zh-cn_topic_0000001173164689_p65967163165"></a>&lt;length&gt;|&lt;percentage&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.4%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164689_p10596151671610"><a name="zh-cn_topic_0000001173164689_p10596151671610"></a><a name="zh-cn_topic_0000001173164689_p10596151671610"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.6%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164689_p1059610169169"><a name="zh-cn_topic_0000001173164689_p1059610169169"></a><a name="zh-cn_topic_0000001173164689_p1059610169169"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164689_p125961416161611"><a name="zh-cn_topic_0000001173164689_p125961416161611"></a><a name="zh-cn_topic_0000001173164689_p125961416161611"></a>设置组件左上角y轴坐标</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164689_row11404114510176"><td class="cellrowborder" valign="top" width="16.84%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164689_p11404124541714"><a name="zh-cn_topic_0000001173164689_p11404124541714"></a><a name="zh-cn_topic_0000001173164689_p11404124541714"></a>dx</p>
</td>
<td class="cellrowborder" valign="top" width="29.4%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164689_p108919015549"><a name="zh-cn_topic_0000001173164689_p108919015549"></a><a name="zh-cn_topic_0000001173164689_p108919015549"></a>&lt;length&gt;|&lt;percentage&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.4%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164689_p20892019541"><a name="zh-cn_topic_0000001173164689_p20892019541"></a><a name="zh-cn_topic_0000001173164689_p20892019541"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.6%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164689_p7893010540"><a name="zh-cn_topic_0000001173164689_p7893010540"></a><a name="zh-cn_topic_0000001173164689_p7893010540"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164689_p78950185420"><a name="zh-cn_topic_0000001173164689_p78950185420"></a><a name="zh-cn_topic_0000001173164689_p78950185420"></a>设置文本x轴偏移</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164689_row75241175410"><td class="cellrowborder" valign="top" width="16.84%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164689_p117241850155416"><a name="zh-cn_topic_0000001173164689_p117241850155416"></a><a name="zh-cn_topic_0000001173164689_p117241850155416"></a>dy</p>
</td>
<td class="cellrowborder" valign="top" width="29.4%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164689_p4724125035416"><a name="zh-cn_topic_0000001173164689_p4724125035416"></a><a name="zh-cn_topic_0000001173164689_p4724125035416"></a>&lt;length&gt;|&lt;percentage&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.4%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164689_p117241350155416"><a name="zh-cn_topic_0000001173164689_p117241350155416"></a><a name="zh-cn_topic_0000001173164689_p117241350155416"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.6%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164689_p4724145065420"><a name="zh-cn_topic_0000001173164689_p4724145065420"></a><a name="zh-cn_topic_0000001173164689_p4724145065420"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164689_p107241750205414"><a name="zh-cn_topic_0000001173164689_p107241750205414"></a><a name="zh-cn_topic_0000001173164689_p107241750205414"></a>设置文本y轴偏移</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164689_row346915743314"><td class="cellrowborder" valign="top" width="16.84%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164689_p1546917783314"><a name="zh-cn_topic_0000001173164689_p1546917783314"></a><a name="zh-cn_topic_0000001173164689_p1546917783314"></a>rotate</p>
</td>
<td class="cellrowborder" valign="top" width="29.4%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164689_p846910713319"><a name="zh-cn_topic_0000001173164689_p846910713319"></a><a name="zh-cn_topic_0000001173164689_p846910713319"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.4%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164689_p14469271337"><a name="zh-cn_topic_0000001173164689_p14469271337"></a><a name="zh-cn_topic_0000001173164689_p14469271337"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.6%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164689_p79541222103311"><a name="zh-cn_topic_0000001173164689_p79541222103311"></a><a name="zh-cn_topic_0000001173164689_p79541222103311"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164689_p34692079335"><a name="zh-cn_topic_0000001173164689_p34692079335"></a><a name="zh-cn_topic_0000001173164689_p34692079335"></a>字体以左下角为圆心旋转角度，正数顺时针，负数逆时针</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164689_row19322182910543"><td class="cellrowborder" valign="top" width="16.84%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164689_p150223885411"><a name="zh-cn_topic_0000001173164689_p150223885411"></a><a name="zh-cn_topic_0000001173164689_p150223885411"></a>font-size</p>
</td>
<td class="cellrowborder" valign="top" width="29.4%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164689_p3502113811542"><a name="zh-cn_topic_0000001173164689_p3502113811542"></a><a name="zh-cn_topic_0000001173164689_p3502113811542"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.4%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164689_p16502238125414"><a name="zh-cn_topic_0000001173164689_p16502238125414"></a><a name="zh-cn_topic_0000001173164689_p16502238125414"></a>30px</p>
</td>
<td class="cellrowborder" valign="top" width="7.6%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164689_p1250273816549"><a name="zh-cn_topic_0000001173164689_p1250273816549"></a><a name="zh-cn_topic_0000001173164689_p1250273816549"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164689_p10502203815413"><a name="zh-cn_topic_0000001173164689_p10502203815413"></a><a name="zh-cn_topic_0000001173164689_p10502203815413"></a>设置文本的尺寸。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164689_row19645239145513"><td class="cellrowborder" valign="top" width="16.84%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164689_p1254235895511"><a name="zh-cn_topic_0000001173164689_p1254235895511"></a><a name="zh-cn_topic_0000001173164689_p1254235895511"></a>fill</p>
</td>
<td class="cellrowborder" valign="top" width="29.4%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164689_p17542115815553"><a name="zh-cn_topic_0000001173164689_p17542115815553"></a><a name="zh-cn_topic_0000001173164689_p17542115815553"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.4%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164689_p5542135835517"><a name="zh-cn_topic_0000001173164689_p5542135835517"></a><a name="zh-cn_topic_0000001173164689_p5542135835517"></a>black</p>
</td>
<td class="cellrowborder" valign="top" width="7.6%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164689_p65421458105510"><a name="zh-cn_topic_0000001173164689_p65421458105510"></a><a name="zh-cn_topic_0000001173164689_p65421458105510"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164689_p354275835511"><a name="zh-cn_topic_0000001173164689_p354275835511"></a><a name="zh-cn_topic_0000001173164689_p354275835511"></a>字体填充颜色</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164689_row94649463555"><td class="cellrowborder" valign="top" width="16.84%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164689_p1254217581557"><a name="zh-cn_topic_0000001173164689_p1254217581557"></a><a name="zh-cn_topic_0000001173164689_p1254217581557"></a>fill-opacity</p>
</td>
<td class="cellrowborder" valign="top" width="29.4%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164689_p1754215875514"><a name="zh-cn_topic_0000001173164689_p1754215875514"></a><a name="zh-cn_topic_0000001173164689_p1754215875514"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.4%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164689_p15542115814558"><a name="zh-cn_topic_0000001173164689_p15542115814558"></a><a name="zh-cn_topic_0000001173164689_p15542115814558"></a>1.0</p>
</td>
<td class="cellrowborder" valign="top" width="7.6%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164689_p115433589554"><a name="zh-cn_topic_0000001173164689_p115433589554"></a><a name="zh-cn_topic_0000001173164689_p115433589554"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164689_p19543058195511"><a name="zh-cn_topic_0000001173164689_p19543058195511"></a><a name="zh-cn_topic_0000001173164689_p19543058195511"></a>字体填充透明度</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164689_row14858838113210"><td class="cellrowborder" valign="top" width="16.84%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164689_a4a0bae0e1bb946d6bc7bf30e0a535343"><a name="zh-cn_topic_0000001173164689_a4a0bae0e1bb946d6bc7bf30e0a535343"></a><a name="zh-cn_topic_0000001173164689_a4a0bae0e1bb946d6bc7bf30e0a535343"></a>opacity</p>
</td>
<td class="cellrowborder" valign="top" width="29.4%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164689_a2679e4565dbc4370b40d1be831a6148d"><a name="zh-cn_topic_0000001173164689_a2679e4565dbc4370b40d1be831a6148d"></a><a name="zh-cn_topic_0000001173164689_a2679e4565dbc4370b40d1be831a6148d"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.4%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164689_a0b0d56a245e14779a5561f99cd1ce9f6"><a name="zh-cn_topic_0000001173164689_a0b0d56a245e14779a5561f99cd1ce9f6"></a><a name="zh-cn_topic_0000001173164689_a0b0d56a245e14779a5561f99cd1ce9f6"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="7.6%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164689_p324614367213"><a name="zh-cn_topic_0000001173164689_p324614367213"></a><a name="zh-cn_topic_0000001173164689_p324614367213"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164689_aa0471c31e05e465aa9c42312b9ab9f6f"><a name="zh-cn_topic_0000001173164689_aa0471c31e05e465aa9c42312b9ab9f6f"></a><a name="zh-cn_topic_0000001173164689_aa0471c31e05e465aa9c42312b9ab9f6f"></a>元素的透明度，取值范围为0到1，1表示为不透明，0表示为完全透明。支持属性动画。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164689_row55924498556"><td class="cellrowborder" valign="top" width="16.84%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164689_p17543185895520"><a name="zh-cn_topic_0000001173164689_p17543185895520"></a><a name="zh-cn_topic_0000001173164689_p17543185895520"></a>stroke</p>
</td>
<td class="cellrowborder" valign="top" width="29.4%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164689_p195431258175515"><a name="zh-cn_topic_0000001173164689_p195431258175515"></a><a name="zh-cn_topic_0000001173164689_p195431258175515"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.4%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164689_p18543658205512"><a name="zh-cn_topic_0000001173164689_p18543658205512"></a><a name="zh-cn_topic_0000001173164689_p18543658205512"></a>black</p>
</td>
<td class="cellrowborder" valign="top" width="7.6%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164689_p16543165855517"><a name="zh-cn_topic_0000001173164689_p16543165855517"></a><a name="zh-cn_topic_0000001173164689_p16543165855517"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164689_p1543145845514"><a name="zh-cn_topic_0000001173164689_p1543145845514"></a><a name="zh-cn_topic_0000001173164689_p1543145845514"></a>绘制字体边框并指定颜色</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164689_row175295385512"><td class="cellrowborder" valign="top" width="16.84%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164689_p16543115835516"><a name="zh-cn_topic_0000001173164689_p16543115835516"></a><a name="zh-cn_topic_0000001173164689_p16543115835516"></a>stroke-width</p>
</td>
<td class="cellrowborder" valign="top" width="29.4%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164689_p15543958165515"><a name="zh-cn_topic_0000001173164689_p15543958165515"></a><a name="zh-cn_topic_0000001173164689_p15543958165515"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.4%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164689_p654416580553"><a name="zh-cn_topic_0000001173164689_p654416580553"></a><a name="zh-cn_topic_0000001173164689_p654416580553"></a>1px</p>
</td>
<td class="cellrowborder" valign="top" width="7.6%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164689_p25440586552"><a name="zh-cn_topic_0000001173164689_p25440586552"></a><a name="zh-cn_topic_0000001173164689_p25440586552"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164689_p1954415895512"><a name="zh-cn_topic_0000001173164689_p1954415895512"></a><a name="zh-cn_topic_0000001173164689_p1954415895512"></a>字体边框宽度</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164689_row192241431553"><td class="cellrowborder" valign="top" width="16.84%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164689_p454412587553"><a name="zh-cn_topic_0000001173164689_p454412587553"></a><a name="zh-cn_topic_0000001173164689_p454412587553"></a>stroke-opacity</p>
</td>
<td class="cellrowborder" valign="top" width="29.4%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164689_p3544358195516"><a name="zh-cn_topic_0000001173164689_p3544358195516"></a><a name="zh-cn_topic_0000001173164689_p3544358195516"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.4%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164689_p7544165855514"><a name="zh-cn_topic_0000001173164689_p7544165855514"></a><a name="zh-cn_topic_0000001173164689_p7544165855514"></a>1.0</p>
</td>
<td class="cellrowborder" valign="top" width="7.6%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164689_p13544258195517"><a name="zh-cn_topic_0000001173164689_p13544258195517"></a><a name="zh-cn_topic_0000001173164689_p13544258195517"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164689_p14544185816559"><a name="zh-cn_topic_0000001173164689_p14544185816559"></a><a name="zh-cn_topic_0000001173164689_p14544185816559"></a>字体边框透明度</p>
</td>
</tr>
</tbody>
</table>

## 示例<a name="zh-cn_topic_0000001173164689_section360556124815"></a>

```
<!-- xxx.css-->
.container {    
    flex-direction: row;
    justify-content: flex-start;
    align-items: flex-start;
    height: 1000px;
    width: 1080px;
}
```

```
<!-- xxx.hml -->
<div class="container">
  <svg>
    <text x="20px" y="0px" font-size="30" fill="blue">test x|y</text>
    <text x="150" y="15" font-size="30" fill="blue">test x|y</text>
    <text x="300" y="30" font-size="30" fill="blue" opacity="0.1">test opacity</text>
    <text dx="20" y="30" dy="50" fill="blue" font-size="30">test dx|dy|fill|font-size</text>
    <text x="20" y="150" fill="blue" font-size="30" fill-opacity="0.2">test fill-opacity</text>
    <text x="20" y="200" fill="red" font-size="40">test 0123456789</text>
    <text x="20" y="250" fill="red" font-size="40" fill-opacity="0.2">test 中文</text>
    <text x="20" y="300" rotate="30" fill="red" font-size="40">test rotate</text>
    <text x="20" y="350" fill="blue" font-size="40" stroke="red" stroke-width="2">test stroke</text>
    <text x="20" y="400" fill="white" font-size="40" stroke="red" stroke-width="2" stroke-opacity="0.5">test stroke-opacity</text>
  </svg>
</div>
```

**图 1** <a name="zh-cn_topic_0000001173164689_fig32245519597"></a>  
![](figures/zh-cn_image_0000001212161527.png "zh-cn_image_0000001212161527")

属性动画示例

```
/* xxx.css  */
.container {
    flex-direction: row;
    justify-content: flex-start;
    align-items: flex-start;
    height: 3000px;
    width: 1080px;
}
```

```
<!-- xxx.hml -->
<div class="container">
  <svg>
    <text y="50" font-size="30" fill="blue">
        text attribute x|opacity|rotate
        <animate attributeName="x" from="100" by="400" dur="3s" repeatCount="indefinite"></animate>
        <animate attributeName="opacity" from="0.01" to="0.99" dur="3s" repeatCount="indefinite"></animate>
        <animate attributeName="rotate" from="0" to="360" dur="3s" repeatCount="indefinite"></animate>
    </text>
  </svg>
</div>
```

![](figures/text-animate-part1.gif)

```
<!-- xxx.hml -->
<div class="container">
  <svg>
    <text x="20" y="200" fill="blue">
        text attribute font-size
        <animate attributeName="font-size" from="10" to="50" dur="3s" repeatCount="indefinite"></animate>
    </text>
  </svg>
</div>
```

![](figures/text-animate-part2.gif)

```
<!-- xxx.hml -->
<div class="container">
  <svg>
    <text x="20" y="250" font-size="25" fill="blue" stroke="red">
        text attribute stroke
        <animate attributeName="stroke" from="red" to="#00FF00" dur="3s" repeatCount="indefinite"></animate>
    </text>
    <text x="300" y="250" font-size="25" fill="white" stroke="red">
        text attribute stroke-width-opacity
        <animate attributeName="stroke-width" from="1" to="5" dur="3s" repeatCount="indefinite"></animate>
        <animate attributeName="stroke-opacity" from="0.01" to="0.99" dur="3s" repeatCount="indefinite"></animate>
    </text>
  </svg>
</div>
```

![](figures/text-animate-part3.gif)

