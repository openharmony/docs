# Dialog类型控件配置说明<a name="ZH-CN_TOPIC_0000001158604277"></a>

-   [概述](#section177145394383)
-   [枚举类型Dialog](#section7797619153917)
-   [单选类型Dialog](#section149204321448)
-   [展示类型Dialog](#section22496134515)
-   [时间选择器类型Dialog](#section13596193716458)
-   [日期选择器类型Dialog](#section11825192184617)
-   [日期时间选择器类型Dialog](#section69732312462)
-   [文本选择器类型Dialog](#section1179325213461)
-   [多文本选择器类型Dialog](#section10946422184712)

## 概述<a name="section177145394383"></a>

Dialog类型控件一共有七个，分别是枚举类型Dialog、单选类型Dialog、展示类型Dialog、时间选择器类型Dialog、日期选择器类型Dialog、日期时间选择器类型Dialog、多列文本选择器类型Dialog。

## 枚举类型Dialog<a name="section7797619153917"></a>

枚举类型Dialog用于在Dialog中类型的选择，可以显示一到八个内容区域。每个区域均可以点击，点击后将根据设置切换为对应的图片，表示状态已更改，每次只有一个区域内容处于激活的状态。

示例图：

![](figures/enum-dialog.png)

对应样例：

```
{
      "name": "饮功能选择",
      "id": "drinkKind",
      "path": "drinkKind",
      "dialogType": "ENUM",
      "controlItems": [
        {
          "name": "取消",
          "type": "cancel"
        },
        {
          "name": "下一步",
          "type": "submit"
        }
      ],
      "command": [
        {
          "name": "五谷",
          "icon": {
            "value": {
              "defaultTarget": "/ic_grains_nor.png",
              "target": "/ic_grains_on.png"
            },
            "valueNight": {
              "defaultTarget": "/ic_grains_nor.png",
              "target": "/ic_grains_on.png"
            }
          },
          "dialogList": ["duration", "temperature", "capacity", "speed"],
          "value": 1
        },
        {
          "name": "豆浆",
          "icon": {
            "value": {
              "defaultTarget": "/ic_soy_milk_nor.png",
              "target": "/ic_soy_milk_on.png"
            },
            "valueNight": {
              "defaultTarget": "/ic_soy_milk_nor.png",
              "target": "/ic_soy_milk_on.png"
            }
          },
          "dialogList": ["duration", "temperature", "capacity", "speed"],
          "value": 2
        }
      ]
    }
```

相关的参数，定义如下：

<a name="table15753253172413"></a>
<table><thead align="left"><tr id="row675313538243"><th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.1"><p id="p107531538246"><a name="p107531538246"></a><a name="p107531538246"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.2"><p id="p147531053122419"><a name="p147531053122419"></a><a name="p147531053122419"></a>可选/必选</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.3"><p id="p1775465311249"><a name="p1775465311249"></a><a name="p1775465311249"></a>字段类型</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.4"><p id="p13754053162412"><a name="p13754053162412"></a><a name="p13754053162412"></a>字段描述</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.5"><p id="p6754115372419"><a name="p6754115372419"></a><a name="p6754115372419"></a>备注</p>
</th>
</tr>
</thead>
<tbody><tr id="row3754205362419"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p29893016259"><a name="p29893016259"></a><a name="p29893016259"></a>name</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p159891709257"><a name="p159891709257"></a><a name="p159891709257"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p898912020254"><a name="p898912020254"></a><a name="p898912020254"></a>String（1-128）</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p1299020112515"><a name="p1299020112515"></a><a name="p1299020112515"></a>当前弹框显示名称</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p119909052510"><a name="p119909052510"></a><a name="p119909052510"></a>例如：“饮功能选择”。</p>
</td>
</tr>
<tr id="row57552539247"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p1990130182512"><a name="p1990130182512"></a><a name="p1990130182512"></a>id</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p799017013259"><a name="p799017013259"></a><a name="p799017013259"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p59909062511"><a name="p59909062511"></a><a name="p59909062511"></a>String（1-128）</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p999017014258"><a name="p999017014258"></a><a name="p999017014258"></a>弹框唯一标识</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p14990190202512"><a name="p14990190202512"></a><a name="p14990190202512"></a>例如：“drinkKind”。</p>
</td>
</tr>
<tr id="row10755953112415"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p7990170132518"><a name="p7990170132518"></a><a name="p7990170132518"></a>path</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p14991120172519"><a name="p14991120172519"></a><a name="p14991120172519"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p1699180152517"><a name="p1699180152517"></a><a name="p1699180152517"></a>String（1-128）</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p39918017255"><a name="p39918017255"></a><a name="p39918017255"></a>动态内容条件值</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p5991707251"><a name="p5991707251"></a><a name="p5991707251"></a>例如：“drinkKind”。</p>
</td>
</tr>
<tr id="row3756155320241"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p1399118013259"><a name="p1399118013259"></a><a name="p1399118013259"></a>dialogType</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p499115012253"><a name="p499115012253"></a><a name="p499115012253"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p499119042518"><a name="p499119042518"></a><a name="p499119042518"></a>String（1-128）</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p1099230142517"><a name="p1099230142517"></a><a name="p1099230142517"></a>弹框类型</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p1199215010258"><a name="p1199215010258"></a><a name="p1199215010258"></a>弹框类型为：“RADIO”，“ENUM”，“PICKER”，“INFO”。</p>
</td>
</tr>
<tr id="row1875615534241"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p169927052511"><a name="p169927052511"></a><a name="p169927052511"></a>controlItems</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p139921909256"><a name="p139921909256"></a><a name="p139921909256"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p14992190192513"><a name="p14992190192513"></a><a name="p14992190192513"></a>ControlItems[]</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p899270122510"><a name="p899270122510"></a><a name="p899270122510"></a>弹框底部控制项</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p18992170192516"><a name="p18992170192516"></a><a name="p18992170192516"></a>-</p>
</td>
</tr>
<tr id="row18757165342417"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p2992160102515"><a name="p2992160102515"></a><a name="p2992160102515"></a>command</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p18993170122517"><a name="p18993170122517"></a><a name="p18993170122517"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p1599390112510"><a name="p1599390112510"></a><a name="p1599390112510"></a>Command[]</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p19935016255"><a name="p19935016255"></a><a name="p19935016255"></a>弹框对应的动作数组</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p89931701252"><a name="p89931701252"></a><a name="p89931701252"></a>-</p>
</td>
</tr>
</tbody>
</table>

ControlItems

<a name="table53758122615"></a>
<table><thead align="left"><tr id="row737512115263"><th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.1"><p id="p203761112265"><a name="p203761112265"></a><a name="p203761112265"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.2"><p id="p737619122614"><a name="p737619122614"></a><a name="p737619122614"></a>可选/必选</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.3"><p id="p53765152613"><a name="p53765152613"></a><a name="p53765152613"></a>字段类型</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.4"><p id="p1437691182612"><a name="p1437691182612"></a><a name="p1437691182612"></a>字段描述</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.5"><p id="p183761618265"><a name="p183761618265"></a><a name="p183761618265"></a>备注</p>
</th>
</tr>
</thead>
<tbody><tr id="row13760122613"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p691027172617"><a name="p691027172617"></a><a name="p691027172617"></a>name</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p149102792615"><a name="p149102792615"></a><a name="p149102792615"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p491019715268"><a name="p491019715268"></a><a name="p491019715268"></a>String（1-128）</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p10910674263"><a name="p10910674263"></a><a name="p10910674263"></a>控制项显示名称</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p15910372265"><a name="p15910372265"></a><a name="p15910372265"></a>例如：“取消”。</p>
</td>
</tr>
<tr id="row203770118267"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p159105772615"><a name="p159105772615"></a><a name="p159105772615"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p1991097132620"><a name="p1991097132620"></a><a name="p1991097132620"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p18911137112616"><a name="p18911137112616"></a><a name="p18911137112616"></a>String（1-128）</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p18911671264"><a name="p18911671264"></a><a name="p18911671264"></a>控制项类型</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p1911107182611"><a name="p1911107182611"></a><a name="p1911107182611"></a>控制项类型为：“submit”，“cancel”。</p>
</td>
</tr>
</tbody>
</table>

Command

<a name="table1658413156278"></a>
<table><thead align="left"><tr id="row4584191510273"><th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.1"><p id="p145844158275"><a name="p145844158275"></a><a name="p145844158275"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.2"><p id="p185842154276"><a name="p185842154276"></a><a name="p185842154276"></a>可选/必选</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.3"><p id="p1158515159271"><a name="p1158515159271"></a><a name="p1158515159271"></a>字段类型</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.4"><p id="p158517155279"><a name="p158517155279"></a><a name="p158517155279"></a>字段描述</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.5"><p id="p14585181582717"><a name="p14585181582717"></a><a name="p14585181582717"></a>备注</p>
</th>
</tr>
</thead>
<tbody><tr id="row558511512710"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p1416713343278"><a name="p1416713343278"></a><a name="p1416713343278"></a>name</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p1168133413275"><a name="p1168133413275"></a><a name="p1168133413275"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p7168134102711"><a name="p7168134102711"></a><a name="p7168134102711"></a>String（1-128）</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p13168434132715"><a name="p13168434132715"></a><a name="p13168434132715"></a>显示名称</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p1516853462711"><a name="p1516853462711"></a><a name="p1516853462711"></a>例如：“五谷”。</p>
</td>
</tr>
<tr id="row15586151592714"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p9168834162710"><a name="p9168834162710"></a><a name="p9168834162710"></a>icon.value.defaultTarget</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p71689341274"><a name="p71689341274"></a><a name="p71689341274"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p116819343279"><a name="p116819343279"></a><a name="p116819343279"></a>String（1-128）</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p1416823410275"><a name="p1416823410275"></a><a name="p1416823410275"></a>默认图标url</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p10169133422712"><a name="p10169133422712"></a><a name="p10169133422712"></a>例如：“/ic_soymilk_nor.png”。</p>
</td>
</tr>
<tr id="row185861315112719"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p1716953419272"><a name="p1716953419272"></a><a name="p1716953419272"></a>icon.value.target</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p816943413276"><a name="p816943413276"></a><a name="p816943413276"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p31691534112720"><a name="p31691534112720"></a><a name="p31691534112720"></a>String（1-128）</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p6169634152715"><a name="p6169634152715"></a><a name="p6169634152715"></a>点击状态图标url</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p12169934132710"><a name="p12169934132710"></a><a name="p12169934132710"></a>例如：“/ic_soymilk_on.png”。</p>
</td>
</tr>
<tr id="row858851512713"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p1016943432716"><a name="p1016943432716"></a><a name="p1016943432716"></a>icon.valueNight.defaultTarget</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p171701134202710"><a name="p171701134202710"></a><a name="p171701134202710"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p111701334192712"><a name="p111701334192712"></a><a name="p111701334192712"></a>String（1-128）</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p81701634152714"><a name="p81701634152714"></a><a name="p81701634152714"></a>深色模式默认图标url</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p5170183412718"><a name="p5170183412718"></a><a name="p5170183412718"></a>例如：“/ic_soymilk_nor.png”。</p>
</td>
</tr>
<tr id="row1658981516276"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p2170234132717"><a name="p2170234132717"></a><a name="p2170234132717"></a>icon.valueNight.target</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p1117063411272"><a name="p1117063411272"></a><a name="p1117063411272"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p11170163415272"><a name="p11170163415272"></a><a name="p11170163415272"></a>String（1-128）</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p11711834112715"><a name="p11711834112715"></a><a name="p11711834112715"></a>深色模式点击状态图标url</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p11171193452715"><a name="p11171193452715"></a><a name="p11171193452715"></a>例如：“/ic_soymilk_on.png”。</p>
</td>
</tr>
<tr id="row4884219192713"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p6171934172715"><a name="p6171934172715"></a><a name="p6171934172715"></a>dialogList</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p12171134192713"><a name="p12171134192713"></a><a name="p12171134192713"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p1917114344275"><a name="p1917114344275"></a><a name="p1917114344275"></a>Array</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p12171103462718"><a name="p12171103462718"></a><a name="p12171103462718"></a>继续显示的弹框列表</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p191711834162716"><a name="p191711834162716"></a><a name="p191711834162716"></a>-</p>
</td>
</tr>
<tr id="row6590515172714"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p17172123492719"><a name="p17172123492719"></a><a name="p17172123492719"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p1172034102718"><a name="p1172034102718"></a><a name="p1172034102718"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p7172934172715"><a name="p7172934172715"></a><a name="p7172934172715"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p817263417275"><a name="p817263417275"></a><a name="p817263417275"></a>命令下发对应的属性值</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p18172634152717"><a name="p18172634152717"></a><a name="p18172634152717"></a>例如：1，表示点了第一个按钮。</p>
</td>
</tr>
</tbody>
</table>

## 单选类型Dialog<a name="section149204321448"></a>

单选类型Dialog用于在Dialog中进行唯一选择，下方以时间设置为例进行说明。

示例图：

![](figures/radio-dialog.png)

对应样例：

```
{
"name": "时间设置",
    "id": "drinkTime1",
    "path": "drinkTime1",
    "dialogType": "RADIO",
    "controlItems": [
	{
	    "name": "取消",
	    "type": "cancel"
	},
	{
	    "name": "下一步",
	    "type": "submit"
        }
    ],
    "range": ["1分钟", "3分钟", "5分钟", "10分钟"],
    "value": [1, 3, 5, 10]
    }
```

相关的参数，定义如下：

<a name="table3791017103018"></a>
<table><thead align="left"><tr id="row979111743020"><th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.1"><p id="p87910175305"><a name="p87910175305"></a><a name="p87910175305"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.2"><p id="p9791117173010"><a name="p9791117173010"></a><a name="p9791117173010"></a>可选/必选</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.3"><p id="p20801517173016"><a name="p20801517173016"></a><a name="p20801517173016"></a>字段类型</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.4"><p id="p680141716306"><a name="p680141716306"></a><a name="p680141716306"></a>字段描述</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.5"><p id="p5801117133012"><a name="p5801117133012"></a><a name="p5801117133012"></a>备注</p>
</th>
</tr>
</thead>
<tbody><tr id="row080191713017"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p3926112713309"><a name="p3926112713309"></a><a name="p3926112713309"></a>name</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p139279277303"><a name="p139279277303"></a><a name="p139279277303"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p492762710307"><a name="p492762710307"></a><a name="p492762710307"></a>String（1-128）</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p1392716274303"><a name="p1392716274303"></a><a name="p1392716274303"></a>当前弹框显示名称</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p892719272308"><a name="p892719272308"></a><a name="p892719272308"></a>例如：“时长设置”。</p>
</td>
</tr>
<tr id="row481317103017"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p179271727143010"><a name="p179271727143010"></a><a name="p179271727143010"></a>id</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p59271527193017"><a name="p59271527193017"></a><a name="p59271527193017"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p1892722783013"><a name="p1892722783013"></a><a name="p1892722783013"></a>String（1-128）</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p8928132717301"><a name="p8928132717301"></a><a name="p8928132717301"></a>弹框唯一标识</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p17928202718301"><a name="p17928202718301"></a><a name="p17928202718301"></a>例如：“duration”。</p>
</td>
</tr>
<tr id="row781181783016"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p1092822714309"><a name="p1092822714309"></a><a name="p1092822714309"></a>path</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p592811277305"><a name="p592811277305"></a><a name="p592811277305"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p79281127113014"><a name="p79281127113014"></a><a name="p79281127113014"></a>String（1-128）</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p10928142718307"><a name="p10928142718307"></a><a name="p10928142718307"></a>动态内容条件值</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p15928152783018"><a name="p15928152783018"></a><a name="p15928152783018"></a>例如：“duration”。</p>
</td>
</tr>
<tr id="row1582181713020"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p992902712308"><a name="p992902712308"></a><a name="p992902712308"></a>dialogType</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p1292912743015"><a name="p1292912743015"></a><a name="p1292912743015"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p15929142710305"><a name="p15929142710305"></a><a name="p15929142710305"></a>String（1-128）</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p792952712304"><a name="p792952712304"></a><a name="p792952712304"></a>弹框类型</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p109292278304"><a name="p109292278304"></a><a name="p109292278304"></a>弹框类型为：“RADIO”，“ENUM”，“PICKER”，“INFO”。</p>
</td>
</tr>
<tr id="row12831317113014"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p492911278306"><a name="p492911278306"></a><a name="p492911278306"></a>controlItems</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p992914277308"><a name="p992914277308"></a><a name="p992914277308"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p1293082743015"><a name="p1293082743015"></a><a name="p1293082743015"></a>ControlItems[]</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p199309275302"><a name="p199309275302"></a><a name="p199309275302"></a>弹框底部控制项</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p1293017274302"><a name="p1293017274302"></a><a name="p1293017274302"></a>-</p>
</td>
</tr>
<tr id="row483517133017"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p5930142773013"><a name="p5930142773013"></a><a name="p5930142773013"></a>range</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p39301927193015"><a name="p39301927193015"></a><a name="p39301927193015"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p10930142773013"><a name="p10930142773013"></a><a name="p10930142773013"></a>Array</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p4931827153015"><a name="p4931827153015"></a><a name="p4931827153015"></a>单选项的数组</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p16931727173010"><a name="p16931727173010"></a><a name="p16931727173010"></a>例如：["1分钟", "3分钟", "5分钟", "10分钟"]。</p>
</td>
</tr>
<tr id="row9841817203012"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p493122773012"><a name="p493122773012"></a><a name="p493122773012"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p17931192711305"><a name="p17931192711305"></a><a name="p17931192711305"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p11931162715302"><a name="p11931162715302"></a><a name="p11931162715302"></a>Array</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p1193142715306"><a name="p1193142715306"></a><a name="p1193142715306"></a>单选项对应值的数组</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p093282710302"><a name="p093282710302"></a><a name="p093282710302"></a>例如：[1, 3, 5, 10]。</p>
</td>
</tr>
</tbody>
</table>

## 展示类型Dialog<a name="section22496134515"></a>

展示类型Dialog用于显示需要展示的图片和描述文字。

示例图：

![](figures/info-dialog.png)

对应样例：

```
{
  "name": "手磨咖啡功能",
  "id": "handGrindingCoffee",
  "dialogType": "INFO",
  "controlItems": [
    {
      "name": "取消",
      "type": "cancel"
    },
    {
      "name": "确认",
      "type": "submit"
    }
  ],
  "icon": "/ic_grand_coffee.png",
  "headline": "温馨提示",
  "desc": "请将干磨杯内的咖啡粉装到咖啡滤网中，再点击开始进行冲泡。"
    }
```

相关的参数，定义如下：

<a name="table15709103663518"></a>
<table><thead align="left"><tr id="row15709736143517"><th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.1"><p id="p77091936193513"><a name="p77091936193513"></a><a name="p77091936193513"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.2"><p id="p1370963653518"><a name="p1370963653518"></a><a name="p1370963653518"></a>可选/必选</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.3"><p id="p1971063611359"><a name="p1971063611359"></a><a name="p1971063611359"></a>字段类型</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.4"><p id="p071011362354"><a name="p071011362354"></a><a name="p071011362354"></a>字段描述</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.5"><p id="p15710836173510"><a name="p15710836173510"></a><a name="p15710836173510"></a>备注</p>
</th>
</tr>
</thead>
<tbody><tr id="row0710203623519"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p85560323717"><a name="p85560323717"></a><a name="p85560323717"></a>name</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p115561938373"><a name="p115561938373"></a><a name="p115561938373"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p15561137375"><a name="p15561137375"></a><a name="p15561137375"></a>String（1-128）</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p855614312371"><a name="p855614312371"></a><a name="p855614312371"></a>当前弹框显示名称</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p1855610333716"><a name="p1855610333716"></a><a name="p1855610333716"></a>例如：“手磨咖啡功能”。</p>
</td>
</tr>
<tr id="row157118363358"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p1555612383720"><a name="p1555612383720"></a><a name="p1555612383720"></a>id</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p1155715315377"><a name="p1155715315377"></a><a name="p1155715315377"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p135572311373"><a name="p135572311373"></a><a name="p135572311373"></a>String（1-128）</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p145571315371"><a name="p145571315371"></a><a name="p145571315371"></a>弹框唯一标识</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p2055713193713"><a name="p2055713193713"></a><a name="p2055713193713"></a>例如：“handGrindingCoffee”。</p>
</td>
</tr>
<tr id="row1471173617357"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p3557133113716"><a name="p3557133113716"></a><a name="p3557133113716"></a>dialogType</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p1355720318377"><a name="p1355720318377"></a><a name="p1355720318377"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p12557836374"><a name="p12557836374"></a><a name="p12557836374"></a>String（1-128）</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p155583373720"><a name="p155583373720"></a><a name="p155583373720"></a>弹框类型</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p05586393717"><a name="p05586393717"></a><a name="p05586393717"></a>弹框类型为：“RADIO”，“ENUM”，“PICKER”，“INFO”。</p>
</td>
</tr>
<tr id="row157121036123517"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p1655803183720"><a name="p1655803183720"></a><a name="p1655803183720"></a>controlItems</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p35586333711"><a name="p35586333711"></a><a name="p35586333711"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p65588373713"><a name="p65588373713"></a><a name="p65588373713"></a>ControlItems[]</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p4558133153715"><a name="p4558133153715"></a><a name="p4558133153715"></a>弹框底部控制项</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p175583373720"><a name="p175583373720"></a><a name="p175583373720"></a>-</p>
</td>
</tr>
<tr id="row1071314362352"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p255993183718"><a name="p255993183718"></a><a name="p255993183718"></a>icon</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p15559203113710"><a name="p15559203113710"></a><a name="p15559203113710"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p95591437370"><a name="p95591437370"></a><a name="p95591437370"></a>String（1-128）</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p755933173719"><a name="p755933173719"></a><a name="p755933173719"></a>展示图片url</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p17559331371"><a name="p17559331371"></a><a name="p17559331371"></a>例如：“/ic_handGrindingCoffee.png”。</p>
</td>
</tr>
<tr id="row671417368354"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p13559153193710"><a name="p13559153193710"></a><a name="p13559153193710"></a>headline</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p1455913173712"><a name="p1455913173712"></a><a name="p1455913173712"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p356020311374"><a name="p356020311374"></a><a name="p356020311374"></a>String（1-128）</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p856093133717"><a name="p856093133717"></a><a name="p856093133717"></a>标题</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p1560636370"><a name="p1560636370"></a><a name="p1560636370"></a>例如：“温馨提示”。</p>
</td>
</tr>
<tr id="row271513368354"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p1156033103710"><a name="p1156033103710"></a><a name="p1156033103710"></a>desc</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p2560113163720"><a name="p2560113163720"></a><a name="p2560113163720"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p165602343714"><a name="p165602343714"></a><a name="p165602343714"></a>String（1-128）</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p175601336377"><a name="p175601336377"></a><a name="p175601336377"></a>描述</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p15612313718"><a name="p15612313718"></a><a name="p15612313718"></a>例如：“请将干磨杯内的咖啡粉装到咖啡滤网中，再点击开始进行冲泡。”</p>
</td>
</tr>
</tbody>
</table>

## 时间选择器类型Dialog<a name="section13596193716458"></a>

时间选择器类型Dialog用于在Dialog中选择时间，可以通过设置 "hours"参数，将时间显示为12小时制或者24小时制。

示例图：

![](figures/time-picker.png)

对应样例：

```
{
  "name": "时间设置",
  "id": "time",
  "path": "time",
  "dialogType": "PICKER",
  "controlItems": [
    {
      "name": "取消",
      "type": "cancel"
    },
    {
      "name": "确认",
      "type": "submit"
    }
  ],
  "pickerType": "time",
  "containSecond": true,
  "hours": 24
    }
```

相关的参数，定义如下：

<a name="table38811018204014"></a>
<table><thead align="left"><tr id="row8881121874010"><th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.1"><p id="p198810185408"><a name="p198810185408"></a><a name="p198810185408"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.2"><p id="p488281810403"><a name="p488281810403"></a><a name="p488281810403"></a>可选/必选</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.3"><p id="p388241834013"><a name="p388241834013"></a><a name="p388241834013"></a>字段类型</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.4"><p id="p108825188409"><a name="p108825188409"></a><a name="p108825188409"></a>字段描述</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.5"><p id="p1882191811404"><a name="p1882191811404"></a><a name="p1882191811404"></a>备注</p>
</th>
</tr>
</thead>
<tbody><tr id="row13912181194215"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p98781124217"><a name="p98781124217"></a><a name="p98781124217"></a>name</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p88781111423"><a name="p88781111423"></a><a name="p88781111423"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p2878191114218"><a name="p2878191114218"></a><a name="p2878191114218"></a>String（1-128）</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p11878151174220"><a name="p11878151174220"></a><a name="p11878151174220"></a>当前弹框显示名称</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p20878181164218"><a name="p20878181164218"></a><a name="p20878181164218"></a>例如：“时间设置”。</p>
</td>
</tr>
<tr id="row091116117428"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p987813154211"><a name="p987813154211"></a><a name="p987813154211"></a>id</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p1687815120429"><a name="p1687815120429"></a><a name="p1687815120429"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p1587813184219"><a name="p1587813184219"></a><a name="p1587813184219"></a>String（1-128）</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p188781119420"><a name="p188781119420"></a><a name="p188781119420"></a>弹框唯一标识</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p10878171164216"><a name="p10878171164216"></a><a name="p10878171164216"></a>例如：“time”。</p>
</td>
</tr>
<tr id="row5911141104213"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p1087871184214"><a name="p1087871184214"></a><a name="p1087871184214"></a>path</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p58781116425"><a name="p58781116425"></a><a name="p58781116425"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p19878161114219"><a name="p19878161114219"></a><a name="p19878161114219"></a>String（1-128）</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p687851204212"><a name="p687851204212"></a><a name="p687851204212"></a>动态内容条件值</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p18781316421"><a name="p18781316421"></a><a name="p18781316421"></a>例如：“time”。</p>
</td>
</tr>
<tr id="row1791071144215"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p487831164213"><a name="p487831164213"></a><a name="p487831164213"></a>dialogType</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p1887821164214"><a name="p1887821164214"></a><a name="p1887821164214"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p158781134212"><a name="p158781134212"></a><a name="p158781134212"></a>String（1-128）</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p38788112428"><a name="p38788112428"></a><a name="p38788112428"></a>弹框类型</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p78781110422"><a name="p78781110422"></a><a name="p78781110422"></a>弹框类型为：“RADIO”，“ENUM”，“PICKER”，“INFO”。</p>
</td>
</tr>
<tr id="row79108117427"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p38783117427"><a name="p38783117427"></a><a name="p38783117427"></a>controlItems</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p387891194216"><a name="p387891194216"></a><a name="p387891194216"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p887816144212"><a name="p887816144212"></a><a name="p887816144212"></a>ControlItems[]</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p987813119425"><a name="p987813119425"></a><a name="p987813119425"></a>弹框底部控制项</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p118781719425"><a name="p118781719425"></a><a name="p118781719425"></a>-</p>
</td>
</tr>
<tr id="row8909171184210"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p128799124220"><a name="p128799124220"></a><a name="p128799124220"></a>pickerType</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p3879111154214"><a name="p3879111154214"></a><a name="p3879111154214"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p387914194214"><a name="p387914194214"></a><a name="p387914194214"></a>String（1-128）</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p178791518421"><a name="p178791518421"></a><a name="p178791518421"></a>选择器类型</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p887920184211"><a name="p887920184211"></a><a name="p887920184211"></a>选择器类型为：“text”，“time”，“date”，“datetime”，“multi-text”。</p>
</td>
</tr>
<tr id="row790915114211"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p2879101164212"><a name="p2879101164212"></a><a name="p2879101164212"></a>containSecond</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p087981114218"><a name="p087981114218"></a><a name="p087981114218"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p1879913425"><a name="p1879913425"></a><a name="p1879913425"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p148797113423"><a name="p148797113423"></a><a name="p148797113423"></a>时间选择器是否包含秒</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p48791111429"><a name="p48791111429"></a><a name="p48791111429"></a>例如：true。</p>
</td>
</tr>
<tr id="row1490812174213"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p18879912426"><a name="p18879912426"></a><a name="p18879912426"></a>hours</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p18879151134211"><a name="p18879151134211"></a><a name="p18879151134211"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p5879718429"><a name="p5879718429"></a><a name="p5879718429"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p178793110429"><a name="p178793110429"></a><a name="p178793110429"></a>时间选择器采用的时间格式</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p587913114212"><a name="p587913114212"></a><a name="p587913114212"></a>可选值：12：按照12小时制显示，用上午和下午进行区分；24：按照24小时制显示。</p>
</td>
</tr>
</tbody>
</table>

## 日期选择器类型Dialog<a name="section11825192184617"></a>

日期选择器类型Dialog用于在Dialog中选择日期，可以通过设置"lunar"的值，显示为农历时间或者公历时间。

示例图：

![](figures/date-picker.png)

对应样例：

```
{
"name": "设置日期",
  "id": "date",
  "path": "date",
  "dialogType": "PICKER",
  "controlItems": [
    {
      "name": "取消",
      "type": "cancel"
    },
    {
      "name": "确认",
      "type": "submit"
    }
  ],
  "pickerType": "date",
  "start": "1970-1-1",
  "end": "2100-12-31",
  "lunar": false
    }
```

相关的参数，定义如下：

<a name="table20291837114316"></a>
<table><thead align="left"><tr id="row122911377435"><th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.1"><p id="p1292123711437"><a name="p1292123711437"></a><a name="p1292123711437"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.2"><p id="p329283794316"><a name="p329283794316"></a><a name="p329283794316"></a>可选/必选</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.3"><p id="p2292173764316"><a name="p2292173764316"></a><a name="p2292173764316"></a>字段类型</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.4"><p id="p52927379436"><a name="p52927379436"></a><a name="p52927379436"></a>字段描述</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.5"><p id="p10292143712434"><a name="p10292143712434"></a><a name="p10292143712434"></a>备注</p>
</th>
</tr>
</thead>
<tbody><tr id="row99212624412"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p587336124415"><a name="p587336124415"></a><a name="p587336124415"></a>name</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p1987312604417"><a name="p1987312604417"></a><a name="p1987312604417"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p1987314619445"><a name="p1987314619445"></a><a name="p1987314619445"></a>String（1-128）</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p18731667440"><a name="p18731667440"></a><a name="p18731667440"></a>当前弹框显示名称</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p158731562445"><a name="p158731562445"></a><a name="p158731562445"></a>例如：“设置日期”。</p>
</td>
</tr>
<tr id="row1792086194419"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p1387346184418"><a name="p1387346184418"></a><a name="p1387346184418"></a>id</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p787316194411"><a name="p787316194411"></a><a name="p787316194411"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p987406154414"><a name="p987406154414"></a><a name="p987406154414"></a>String（1-128）</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p1487415634410"><a name="p1487415634410"></a><a name="p1487415634410"></a>弹框唯一标识</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p15874667446"><a name="p15874667446"></a><a name="p15874667446"></a>例如：“date”。</p>
</td>
</tr>
<tr id="row29206634415"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p198748654414"><a name="p198748654414"></a><a name="p198748654414"></a>path</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p128747615443"><a name="p128747615443"></a><a name="p128747615443"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p1587419634410"><a name="p1587419634410"></a><a name="p1587419634410"></a>String（1-128）</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p188743614418"><a name="p188743614418"></a><a name="p188743614418"></a>动态内容条件值</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p138741769448"><a name="p138741769448"></a><a name="p138741769448"></a>例如：“date”。</p>
</td>
</tr>
<tr id="row139181263446"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p1487410614444"><a name="p1487410614444"></a><a name="p1487410614444"></a>dialogType</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p108741660442"><a name="p108741660442"></a><a name="p108741660442"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p13874068441"><a name="p13874068441"></a><a name="p13874068441"></a>String（1-128）</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p108745618440"><a name="p108745618440"></a><a name="p108745618440"></a>弹框类型</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p20874969440"><a name="p20874969440"></a><a name="p20874969440"></a>弹框类型为：“RADIO”，“ENUM”，“PICKER”，“INFO”。</p>
</td>
</tr>
<tr id="row8917106114419"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p1987410674412"><a name="p1987410674412"></a><a name="p1987410674412"></a>controlItems</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p78742616445"><a name="p78742616445"></a><a name="p78742616445"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p8874161448"><a name="p8874161448"></a><a name="p8874161448"></a>ControlItems[]</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p148741369441"><a name="p148741369441"></a><a name="p148741369441"></a>弹框底部控制项</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p587456174417"><a name="p587456174417"></a><a name="p587456174417"></a>-</p>
</td>
</tr>
<tr id="row149171164448"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p18874166184413"><a name="p18874166184413"></a><a name="p18874166184413"></a>pickerType</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p78742615448"><a name="p78742615448"></a><a name="p78742615448"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p38749617441"><a name="p38749617441"></a><a name="p38749617441"></a>String（1-128）</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p387420611443"><a name="p387420611443"></a><a name="p387420611443"></a>选择器类型</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p1874461449"><a name="p1874461449"></a><a name="p1874461449"></a>选择器类型为：“text”，“time”，“date”，“datetime”，“multi-text”。</p>
</td>
</tr>
<tr id="row9916469445"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p8874126134412"><a name="p8874126134412"></a><a name="p8874126134412"></a>start</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p1087466164420"><a name="p1087466164420"></a><a name="p1087466164420"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p1387416114413"><a name="p1387416114413"></a><a name="p1387416114413"></a>time</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p3874364447"><a name="p3874364447"></a><a name="p3874364447"></a>日期选择器的起始时间</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p6874186114416"><a name="p6874186114416"></a><a name="p6874186114416"></a>格式为 YYYY-MM-DD。</p>
</td>
</tr>
<tr id="row17916186154413"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p188754617448"><a name="p188754617448"></a><a name="p188754617448"></a>end</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p887511617444"><a name="p887511617444"></a><a name="p887511617444"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p19875136194418"><a name="p19875136194418"></a><a name="p19875136194418"></a>time</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p1187516144412"><a name="p1187516144412"></a><a name="p1187516144412"></a>日期选择器的结束时间</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p20875069442"><a name="p20875069442"></a><a name="p20875069442"></a>格式为 YYYY-MM-DD。</p>
</td>
</tr>
<tr id="row199157614419"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p1787512604414"><a name="p1787512604414"></a><a name="p1787512604414"></a>lunar</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p2875176164413"><a name="p2875176164413"></a><a name="p2875176164413"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p168752634419"><a name="p168752634419"></a><a name="p168752634419"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p98755616441"><a name="p98755616441"></a><a name="p98755616441"></a>日期选择器是否为农历展示</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p78751265441"><a name="p78751265441"></a><a name="p78751265441"></a>例如：false。</p>
</td>
</tr>
</tbody>
</table>

## 日期时间选择器类型Dialog<a name="section69732312462"></a>

日期时间选择器类型Dialog用于在Dialog中选择日期和时间，可以通过设置 "hours"参数，将时间显示为12小时制或者24小时制。可以通过设置"lunar"的值，显示为农历时间或者公历时间。

示例图：

![](figures/date-and-time-picker.png)

对应样例：

```
{
  "name": "日期时间设置",
  "id": "datetime",
  "path": "datetime",
  "dialogType": "PICKER",
  "controlItems": [
    {
      "name": "取消",
      "type": "cancel"
    },
    {
      "name": "确认",
      "type": "submit"
    }
  ],
  "pickerType": "datetime",
  "lunar": false,
  "hours": 24
    }
```

相关的参数，定义如下：

<a name="table18376477454"></a>
<table><thead align="left"><tr id="row1537619718459"><th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.1"><p id="p153761871456"><a name="p153761871456"></a><a name="p153761871456"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.2"><p id="p1737616719453"><a name="p1737616719453"></a><a name="p1737616719453"></a>可选/必选</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.3"><p id="p2037712744514"><a name="p2037712744514"></a><a name="p2037712744514"></a>字段类型</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.4"><p id="p8377117124512"><a name="p8377117124512"></a><a name="p8377117124512"></a>字段描述</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.5"><p id="p43772718458"><a name="p43772718458"></a><a name="p43772718458"></a>备注</p>
</th>
</tr>
</thead>
<tbody><tr id="row031576194713"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p172861617478"><a name="p172861617478"></a><a name="p172861617478"></a>name</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p828617616474"><a name="p828617616474"></a><a name="p828617616474"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p102861062477"><a name="p102861062477"></a><a name="p102861062477"></a>String（1-128）</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p132862664715"><a name="p132862664715"></a><a name="p132862664715"></a>当前弹框显示名称</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p22868614478"><a name="p22868614478"></a><a name="p22868614478"></a>例如：“日期时间设置”。</p>
</td>
</tr>
<tr id="row1031414613474"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p182866694710"><a name="p182866694710"></a><a name="p182866694710"></a>id</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p132862613478"><a name="p132862613478"></a><a name="p132862613478"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p172864604713"><a name="p172864604713"></a><a name="p172864604713"></a>String（1-128）</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p528618617476"><a name="p528618617476"></a><a name="p528618617476"></a>弹框唯一标识</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p1328619604719"><a name="p1328619604719"></a><a name="p1328619604719"></a>例如：“datetime”。</p>
</td>
</tr>
<tr id="row173141668472"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p12868617474"><a name="p12868617474"></a><a name="p12868617474"></a>path</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p1428616124714"><a name="p1428616124714"></a><a name="p1428616124714"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p15286136164719"><a name="p15286136164719"></a><a name="p15286136164719"></a>String（1-128）</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p1028696184714"><a name="p1028696184714"></a><a name="p1028696184714"></a>动态内容条件值</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p3286116114711"><a name="p3286116114711"></a><a name="p3286116114711"></a>例如：“datetime”。</p>
</td>
</tr>
<tr id="row331436104719"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p6286766479"><a name="p6286766479"></a><a name="p6286766479"></a>dialogType</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p192866616477"><a name="p192866616477"></a><a name="p192866616477"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p92869617476"><a name="p92869617476"></a><a name="p92869617476"></a>String（1-128）</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p22866619471"><a name="p22866619471"></a><a name="p22866619471"></a>弹框类型</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p62861965479"><a name="p62861965479"></a><a name="p62861965479"></a>弹框类型为：“RADIO”，“ENUM”，“PICKER”，“INFO”。</p>
</td>
</tr>
<tr id="row731415684711"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p02875654711"><a name="p02875654711"></a><a name="p02875654711"></a>controlItems</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p112871562471"><a name="p112871562471"></a><a name="p112871562471"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p728766134716"><a name="p728766134716"></a><a name="p728766134716"></a>ControlItems[]</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p2028712674711"><a name="p2028712674711"></a><a name="p2028712674711"></a>弹框底部控制项</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p328796154711"><a name="p328796154711"></a><a name="p328796154711"></a>-</p>
</td>
</tr>
<tr id="row103131363477"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p6287469477"><a name="p6287469477"></a><a name="p6287469477"></a>pickerType</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p202871568475"><a name="p202871568475"></a><a name="p202871568475"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p1028718612475"><a name="p1028718612475"></a><a name="p1028718612475"></a>String（1-128）</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p10287116164715"><a name="p10287116164715"></a><a name="p10287116164715"></a>选择器类型</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p132871066474"><a name="p132871066474"></a><a name="p132871066474"></a>选择器类型为：“text”，“time”，“date”，“datetime”，“multi-text”。</p>
</td>
</tr>
<tr id="row3313562479"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p15287206144716"><a name="p15287206144716"></a><a name="p15287206144716"></a>lunar</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p528715644715"><a name="p528715644715"></a><a name="p528715644715"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p6287468470"><a name="p6287468470"></a><a name="p6287468470"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p1828717654718"><a name="p1828717654718"></a><a name="p1828717654718"></a>日期时间选择器是否为农历显示</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p1228711624710"><a name="p1228711624710"></a><a name="p1228711624710"></a>例如：false。</p>
</td>
</tr>
<tr id="row133139624716"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p192871674710"><a name="p192871674710"></a><a name="p192871674710"></a>hours</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p228713619476"><a name="p228713619476"></a><a name="p228713619476"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p182872684719"><a name="p182872684719"></a><a name="p182872684719"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p728776164712"><a name="p728776164712"></a><a name="p728776164712"></a>时间选择器采用的时间格式</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p42872615476"><a name="p42872615476"></a><a name="p42872615476"></a>可选值：12：按照12小时制显示，用上午和下午进行区分；24：按照24小时制显示。</p>
</td>
</tr>
</tbody>
</table>

## 文本选择器类型Dialog<a name="section1179325213461"></a>

文本选择器类型Dialog用于在Dialog中选择文本，文本内容可通过配置指定。

示例图：

![](figures/text-picker.png)

对应样例：

```
{
  "name": "水温设置",
  "id": "temperature",
  "path": "temperature",
  "dialogType": "PICKER",
  "controlItems": [
    {
      "name": "取消",
      "type": "cancel"
    },
    {
      "name": "下一步",
      "type": "submit"
    }
  ],
  "pickerType": "text",
  "range": ["40", "50", "60", "70", "80", "90", "100"],
  "value": [40, 50, 60, 70, 80, 90, 100],
  "postField": "℃"
}
```

相关的参数，定义如下：

<a name="table154381529476"></a>
<table><thead align="left"><tr id="row194421752194720"><th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.1"><p id="p1861246485"><a name="p1861246485"></a><a name="p1861246485"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.2"><p id="p12632420484"><a name="p12632420484"></a><a name="p12632420484"></a>可选/必选</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.3"><p id="p161124154817"><a name="p161124154817"></a><a name="p161124154817"></a>字段类型</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.4"><p id="p176152444816"><a name="p176152444816"></a><a name="p176152444816"></a>字段描述</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.5"><p id="p1961124104810"><a name="p1961124104810"></a><a name="p1961124104810"></a>备注</p>
</th>
</tr>
</thead>
<tbody><tr id="row174431752164710"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p156202474818"><a name="p156202474818"></a><a name="p156202474818"></a>name</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p116724184810"><a name="p116724184810"></a><a name="p116724184810"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p3616241482"><a name="p3616241482"></a><a name="p3616241482"></a>String（1-128）</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p186192454816"><a name="p186192454816"></a><a name="p186192454816"></a>当前弹框显示名称</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p56024174815"><a name="p56024174815"></a><a name="p56024174815"></a>例如：“水温设置”。</p>
</td>
</tr>
<tr id="row444385204718"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p1561524184816"><a name="p1561524184816"></a><a name="p1561524184816"></a>id</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p6611240484"><a name="p6611240484"></a><a name="p6611240484"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p26152444818"><a name="p26152444818"></a><a name="p26152444818"></a>String（1-128）</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p9612416489"><a name="p9612416489"></a><a name="p9612416489"></a>弹框唯一标识</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p1961424184820"><a name="p1961424184820"></a><a name="p1961424184820"></a>例如：“temperature”。</p>
</td>
</tr>
<tr id="row1744335244710"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p186182494815"><a name="p186182494815"></a><a name="p186182494815"></a>path</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p4652414820"><a name="p4652414820"></a><a name="p4652414820"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p2612240484"><a name="p2612240484"></a><a name="p2612240484"></a>String（1-128）</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p16102414486"><a name="p16102414486"></a><a name="p16102414486"></a>动态内容条件值</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p1161924114816"><a name="p1161924114816"></a><a name="p1161924114816"></a>例如：“temperature”。</p>
</td>
</tr>
<tr id="row9443115215476"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p561124164815"><a name="p561124164815"></a><a name="p561124164815"></a>dialogType</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p3610242480"><a name="p3610242480"></a><a name="p3610242480"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p1564245487"><a name="p1564245487"></a><a name="p1564245487"></a>String（1-128）</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p267243488"><a name="p267243488"></a><a name="p267243488"></a>弹框类型</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p176124154811"><a name="p176124154811"></a><a name="p176124154811"></a>弹框类型为：“RADIO”，“ENUM”，“PICKER”，“INFO”。</p>
</td>
</tr>
<tr id="row6443252104718"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p861024104814"><a name="p861024104814"></a><a name="p861024104814"></a>controlItems</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p661324124820"><a name="p661324124820"></a><a name="p661324124820"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p20672410489"><a name="p20672410489"></a><a name="p20672410489"></a>ControlItems[]</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p96202424817"><a name="p96202424817"></a><a name="p96202424817"></a>弹框底部控制项</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p1661624204810"><a name="p1661624204810"></a><a name="p1661624204810"></a>-</p>
</td>
</tr>
<tr id="row124431852154710"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p7672454815"><a name="p7672454815"></a><a name="p7672454815"></a>pickerType</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p369246487"><a name="p369246487"></a><a name="p369246487"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p061024174818"><a name="p061024174818"></a><a name="p061024174818"></a>String（1-128）</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p8617247484"><a name="p8617247484"></a><a name="p8617247484"></a>选择器类型</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p2672412489"><a name="p2672412489"></a><a name="p2672412489"></a>选择器类型为：“text”，“time”，“date”，“datetime”，“multi-text”。</p>
</td>
</tr>
<tr id="row14444652164713"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p2762414818"><a name="p2762414818"></a><a name="p2762414818"></a>range</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p571244483"><a name="p571244483"></a><a name="p571244483"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p177122413486"><a name="p177122413486"></a><a name="p177122413486"></a>Array</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p6715245484"><a name="p6715245484"></a><a name="p6715245484"></a>文本选择器的取值范围</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p107172415486"><a name="p107172415486"></a><a name="p107172415486"></a>例如：["40", "50", "60", "70", "80", "90", "100"]。</p>
</td>
</tr>
<tr id="row196431607483"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p1671324124818"><a name="p1671324124818"></a><a name="p1671324124818"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p12722417487"><a name="p12722417487"></a><a name="p12722417487"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p37152418484"><a name="p37152418484"></a><a name="p37152418484"></a>Array</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p672245482"><a name="p672245482"></a><a name="p672245482"></a>文本选择器对应的值的范围</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p127124154815"><a name="p127124154815"></a><a name="p127124154815"></a>例如：[40, 50, 60, 70, 80, 90, 100]。</p>
</td>
</tr>
<tr id="row2051816594820"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p1871424144816"><a name="p1871424144816"></a><a name="p1871424144816"></a>preField</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p071524174814"><a name="p071524174814"></a><a name="p071524174814"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p117162494810"><a name="p117162494810"></a><a name="p117162494810"></a>String（1-128）</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p271324184812"><a name="p271324184812"></a><a name="p271324184812"></a>文本选择器选定值增加的前缀字段</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p19702404819"><a name="p19702404819"></a><a name="p19702404819"></a>例如：“1”。</p>
</td>
</tr>
<tr id="row24887713481"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p27524184818"><a name="p27524184818"></a><a name="p27524184818"></a>postField</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p7702474815"><a name="p7702474815"></a><a name="p7702474815"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p3720246489"><a name="p3720246489"></a><a name="p3720246489"></a>String（1-128）</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p971224124814"><a name="p971224124814"></a><a name="p971224124814"></a>文本选择器选定值增加的后缀字段</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p87524124816"><a name="p87524124816"></a><a name="p87524124816"></a>例如：“℃”。</p>
</td>
</tr>
</tbody>
</table>

## 多文本选择器类型Dialog<a name="section10946422184712"></a>

多列文本选择器类型Dialog用于在Dialog中选择多列文本，文本内容通过配置指定。

示例图：

![](figures/multi-column-picker.png)

对应样例：

```
{
  "name": "时长设置",
  "id": "duration",
  "path": "duration",
  "dialogType": "PICKER",
  "controlItems": [
    {
      "name": "取消",
      "type": "cancel"
    },
    {
      "name": "下一步",
      "type": "submit"
    }
  ],
  "pickerType": "multi-text",
  "range": [
    ["0分","1分","2分","3分","4分","5分","6分"],
    ["0秒","1秒","2秒","3秒","4秒","5秒","6秒"]
  ]
  }
```

相关的参数，定义如下：

<a name="table590882015489"></a>
<table><thead align="left"><tr id="row3909220184817"><th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.1"><p id="p8909182014481"><a name="p8909182014481"></a><a name="p8909182014481"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.2"><p id="p89091320194811"><a name="p89091320194811"></a><a name="p89091320194811"></a>可选/必选</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.3"><p id="p159093207482"><a name="p159093207482"></a><a name="p159093207482"></a>字段类型</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.4"><p id="p16909920114811"><a name="p16909920114811"></a><a name="p16909920114811"></a>字段描述</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.5"><p id="p1090915205489"><a name="p1090915205489"></a><a name="p1090915205489"></a>备注</p>
</th>
</tr>
</thead>
<tbody><tr id="row34961457482"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p13464184515488"><a name="p13464184515488"></a><a name="p13464184515488"></a>name</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p1246434512486"><a name="p1246434512486"></a><a name="p1246434512486"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p24647455480"><a name="p24647455480"></a><a name="p24647455480"></a>String（1-128）</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p1464345174819"><a name="p1464345174819"></a><a name="p1464345174819"></a>当前弹框显示名称</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p1746434584817"><a name="p1746434584817"></a><a name="p1746434584817"></a>例如：“时长设置”。</p>
</td>
</tr>
<tr id="row1049694520487"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p17464144520481"><a name="p17464144520481"></a><a name="p17464144520481"></a>id</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p18464145114814"><a name="p18464145114814"></a><a name="p18464145114814"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p94641645164816"><a name="p94641645164816"></a><a name="p94641645164816"></a>String（1-128）</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p1464154511483"><a name="p1464154511483"></a><a name="p1464154511483"></a>弹框唯一标识</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p194641045164810"><a name="p194641045164810"></a><a name="p194641045164810"></a>例如：“duration”。</p>
</td>
</tr>
<tr id="row174961345154818"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p204641245114816"><a name="p204641245114816"></a><a name="p204641245114816"></a>path</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p34641945124813"><a name="p34641945124813"></a><a name="p34641945124813"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p1746484514810"><a name="p1746484514810"></a><a name="p1746484514810"></a>String（1-128）</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p184651645124813"><a name="p184651645124813"></a><a name="p184651645124813"></a>动态内容条件值</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p11465194564813"><a name="p11465194564813"></a><a name="p11465194564813"></a>例如：“duration”。</p>
</td>
</tr>
<tr id="row12495154515481"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p11465164514489"><a name="p11465164514489"></a><a name="p11465164514489"></a>dialogType</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p74651345194818"><a name="p74651345194818"></a><a name="p74651345194818"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p1846534515486"><a name="p1846534515486"></a><a name="p1846534515486"></a>String（1-128）</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p104655457482"><a name="p104655457482"></a><a name="p104655457482"></a>弹框类型</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p646514518489"><a name="p646514518489"></a><a name="p646514518489"></a>弹框类型为：“RADIO”，“ENUM”，“PICKER”，“INFO”。</p>
</td>
</tr>
<tr id="row049512451482"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p10465194516488"><a name="p10465194516488"></a><a name="p10465194516488"></a>controlItems</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p746564511486"><a name="p746564511486"></a><a name="p746564511486"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p16465114517485"><a name="p16465114517485"></a><a name="p16465114517485"></a>ControlItems[]</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p9465154518486"><a name="p9465154518486"></a><a name="p9465154518486"></a>弹框底部控制项</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p3465845174815"><a name="p3465845174815"></a><a name="p3465845174815"></a>-</p>
</td>
</tr>
<tr id="row1249434524812"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p1546534584816"><a name="p1546534584816"></a><a name="p1546534584816"></a>pickerType</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p04651445184813"><a name="p04651445184813"></a><a name="p04651445184813"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p2046517456485"><a name="p2046517456485"></a><a name="p2046517456485"></a>String（1-128）</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p3465154564817"><a name="p3465154564817"></a><a name="p3465154564817"></a>选择器类型</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p1846514511485"><a name="p1846514511485"></a><a name="p1846514511485"></a>选择器类型为：“text”，“time”，“date”，“datetime”，“multi-text“。</p>
</td>
</tr>
<tr id="row449417455482"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p1146524515482"><a name="p1146524515482"></a><a name="p1146524515482"></a>range</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p8465184520488"><a name="p8465184520488"></a><a name="p8465184520488"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p84651445184815"><a name="p84651445184815"></a><a name="p84651445184815"></a>二维Array</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p104651645104812"><a name="p104651645104812"></a><a name="p104651645104812"></a>多列文本选择器的选择值</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p346554510486"><a name="p346554510486"></a><a name="p346554510486"></a>长度表示多少列，数组的每项表示每列的数据，如  [["a","b"], ["c","d"]]。</p>
</td>
</tr>
</tbody>
</table>

