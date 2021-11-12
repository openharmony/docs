# Control类型控件配置说明<a name="ZH-CN_TOPIC_0000001158764267"></a>

-   [Control类型控件配置说明](#section7914183213491)
-   [Display控件](#section16681645104918)
-   [Enum控件](#section566910277516)
-   [Reversal控件](#section162211550155113)
-   [Increase\_Decrease控件](#section1092141210525)
-   [Progress控件](#section04131030125215)
-   [Multifunction控件](#section1114919529527)

## Control类型控件配置说明<a name="section7914183213491"></a>

Control类型控件一共有六个，分别是Display类型控件、Enum类型控件、Reversal类型控件、Progress类型控件、IncreaseDecrease类型控件和Multifunction类型控件。

## Display控件<a name="section16681645104918"></a>

Display控件用于信息展示，支持显示两个或者三个区域内容，支持左右对齐（不带分割线）或者居中（带分割线）。

每个区域内容支持文字， 或者文字加图片（图片显示大小为 24vp \*24vp），文字颜色支持自定义，颜色和图片支持根据数据范围来选择。

示例图：

![](figures/display-component.png)

对应样例：

```
{
  "gravity": "default",
  "heightType": "default",
  "name": "电量",
  "span": 1,
  "uiList": [
    {
      "subType": "text",
      "textDisplay": {
        "down": {},
        "upLeft": {
          "description": {
            "path": "bluetoothConnectStatus/bluetoothConnectStatus",
            "value": [
              {
                "scope": "0",
                "target": "未连接"
              },
              {
                "scope": "1",
                "target": "已连接"
              }
            ]
          },
          "type": "dynamicText",
          "value": "${bluetoothConnectStatus/bluetoothConnectStatus}"
        },
        "upRight": {}
      }
    },
    {
      "icon": {
        "path": "infoDisplay/battery",
        "value": [
          {
            "defaultTarget ": "/template/pic/battery_10_default.png",
            "disableTarget ": "/template/pic/battery_10_default.png",
            "scope": "-10",
            "target": "/template/pic/battery_10_default.png"
          },
          {
            "defaultTarget ": "/template/pic/battery_20_default.png",
            "disableTarget ": "/template/pic/battery_20_default.png",
            "scope": "10-20",
            "target": "/template/pic/battery_20_default.png"
          },
          {
            "defaultTarget ": "/template/pic/battery_30_default.png",
            "disableTarget ": "/template/pic/battery_30_default.png",
            "scope": "20-30",
            "target": "/template/pic/battery_30_default.png"
          },
          {
            "defaultTarget ": "/template/pic/battery_40_default.png",
            "disableTarget ": "/template/pic/battery_40_default.png",
            "scope": "30-40",
            "target": "/template/pic/battery_40_default.png"
          },
          {
            "defaultTarget ": "/template/pic/battery_50_default.png",
            "disableTarget ": "/template/pic/battery_50_default.png",
            "scope": "40-50",
            "target": "/template/pic/battery_50_default.png"
          },
          {
            "defaultTarget ": "/template/pic/battery_60_default.png",
            "disableTarget ": "/template/pic/battery_60_default.png",
            "scope": "50-60",
            "target": "/template/pic/battery_60_default.png"
          },
          {
            "defaultTarget ": "/template/pic/battery_70_default.png",
            "disableTarget ": "/template/pic/battery_70_default.png",
            "scope": "60-70",
            "target": "/template/pic/battery_70_default.png"
          },
          {
            "defaultTarget ": "/template/pic/battery_80_default.png",
            "disableTarget ": "/template/pic/battery_80_default.png",
            "scope": "70-80",
            "target": "/template/pic/battery_80_default.png"
          },
          {
            "defaultTarget ": "/template/pic/battery_90_default.png",
            "disableTarget ": "/template/pic/battery_90_default.png",
            "scope": "80-90",
            "target": "/template/pic/battery_90_default.png"
          },
          {
            "defaultTarget ": "/template/pic/battery_99_default.png",
            "disableTarget ": "/template/pic/battery_99_default.png",
            "scope": "90-100",
            "target": "/template/pic/battery_99_default.png"
          },
          {
            "defaultTarget ": "/template/pic/battery_100_default.png",
            "disableTarget ": "/template/pic/battery_100_default.png",
            "scope": "100-",
            "target": "/template/pic/battery_100_default.png"
          }
        ]
      },
      "iconText": {
        "type": "dynamicText",
        "value": "${infoDisplay/battery}%",
        "range": "100-0"
      },
      "subType": "iconTextHorizontal"
    }
  ],
  "uiType": "DISPLAY"
}
```

相关的参数，定义如下：

<a name="table4180471364"></a>
<table><thead align="left"><tr id="row3260872613"><th class="cellrowborder" valign="top" width="9.629999999999999%" id="mcps1.1.6.1.1"><p id="p42600710618"><a name="p42600710618"></a><a name="p42600710618"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="7.88%" id="mcps1.1.6.1.2"><p id="p9260776618"><a name="p9260776618"></a><a name="p9260776618"></a>可选/必选</p>
</th>
<th class="cellrowborder" valign="top" width="10.14%" id="mcps1.1.6.1.3"><p id="p182601471267"><a name="p182601471267"></a><a name="p182601471267"></a>字段类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.959999999999999%" id="mcps1.1.6.1.4"><p id="p826016714616"><a name="p826016714616"></a><a name="p826016714616"></a>字段描述</p>
</th>
<th class="cellrowborder" valign="top" width="62.39%" id="mcps1.1.6.1.5"><p id="p13260271669"><a name="p13260271669"></a><a name="p13260271669"></a>备注</p>
</th>
</tr>
</thead>
<tbody><tr id="row826077267"><td class="cellrowborder" valign="top" width="9.629999999999999%" headers="mcps1.1.6.1.1 "><p id="p172601271967"><a name="p172601271967"></a><a name="p172601271967"></a>name</p>
</td>
<td class="cellrowborder" valign="top" width="7.88%" headers="mcps1.1.6.1.2 "><p id="p62601274615"><a name="p62601274615"></a><a name="p62601274615"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="10.14%" headers="mcps1.1.6.1.3 "><p id="p152611278614"><a name="p152611278614"></a><a name="p152611278614"></a>String (1-128)</p>
</td>
<td class="cellrowborder" valign="top" width="9.959999999999999%" headers="mcps1.1.6.1.4 "><p id="p026115712610"><a name="p026115712610"></a><a name="p026115712610"></a>当前控件显示名称</p>
</td>
<td class="cellrowborder" valign="top" width="62.39%" headers="mcps1.1.6.1.5 "><p id="p13261278610"><a name="p13261278610"></a><a name="p13261278610"></a>例如：“电量”。</p>
</td>
</tr>
<tr id="row626119718611"><td class="cellrowborder" valign="top" width="9.629999999999999%" headers="mcps1.1.6.1.1 "><p id="p182615714619"><a name="p182615714619"></a><a name="p182615714619"></a>span</p>
</td>
<td class="cellrowborder" valign="top" width="7.88%" headers="mcps1.1.6.1.2 "><p id="p1261171567"><a name="p1261171567"></a><a name="p1261171567"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="10.14%" headers="mcps1.1.6.1.3 "><p id="p182611275615"><a name="p182611275615"></a><a name="p182611275615"></a>float</p>
</td>
<td class="cellrowborder" valign="top" width="9.959999999999999%" headers="mcps1.1.6.1.4 "><p id="p82616717611"><a name="p82616717611"></a><a name="p82616717611"></a>跨度</p>
</td>
<td class="cellrowborder" valign="top" width="62.39%" headers="mcps1.1.6.1.5 "><p id="p10261775612"><a name="p10261775612"></a><a name="p10261775612"></a>根据手机设置控件的宽度占比，为1表示占满普通手机的宽。</p>
</td>
</tr>
<tr id="row3261157461"><td class="cellrowborder" valign="top" width="9.629999999999999%" headers="mcps1.1.6.1.1 "><p id="p172622718615"><a name="p172622718615"></a><a name="p172622718615"></a>uiType</p>
</td>
<td class="cellrowborder" valign="top" width="7.88%" headers="mcps1.1.6.1.2 "><p id="p9262117264"><a name="p9262117264"></a><a name="p9262117264"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="10.14%" headers="mcps1.1.6.1.3 "><p id="p112628720618"><a name="p112628720618"></a><a name="p112628720618"></a>String(1-128)</p>
</td>
<td class="cellrowborder" valign="top" width="9.959999999999999%" headers="mcps1.1.6.1.4 "><p id="p8262671262"><a name="p8262671262"></a><a name="p8262671262"></a>控件风格</p>
</td>
<td class="cellrowborder" valign="top" width="62.39%" headers="mcps1.1.6.1.5 "><p id="p626219718614"><a name="p626219718614"></a><a name="p626219718614"></a>控件风格为：“DISPLAY” ，“REVERSAL”,“INCREASE_DECREASE”，“ENUM” ，“MULTIFUNCTION”。</p>
</td>
</tr>
<tr id="row626214710615"><td class="cellrowborder" valign="top" width="9.629999999999999%" headers="mcps1.1.6.1.1 "><p id="p112621171164"><a name="p112621171164"></a><a name="p112621171164"></a>heightType</p>
</td>
<td class="cellrowborder" valign="top" width="7.88%" headers="mcps1.1.6.1.2 "><p id="p22631471369"><a name="p22631471369"></a><a name="p22631471369"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="10.14%" headers="mcps1.1.6.1.3 "><p id="p1426357964"><a name="p1426357964"></a><a name="p1426357964"></a>String(1-128)</p>
</td>
<td class="cellrowborder" valign="top" width="9.959999999999999%" headers="mcps1.1.6.1.4 "><p id="p16263107764"><a name="p16263107764"></a><a name="p16263107764"></a>高度类型</p>
</td>
<td class="cellrowborder" valign="top" width="62.39%" headers="mcps1.1.6.1.5 "><p id="p52632711619"><a name="p52632711619"></a><a name="p52632711619"></a>“default”，“low”；默认为“default”。</p>
</td>
</tr>
<tr id="row20263187469"><td class="cellrowborder" valign="top" width="9.629999999999999%" headers="mcps1.1.6.1.1 "><p id="p52641176615"><a name="p52641176615"></a><a name="p52641176615"></a>gravity</p>
</td>
<td class="cellrowborder" valign="top" width="7.88%" headers="mcps1.1.6.1.2 "><p id="p122648710618"><a name="p122648710618"></a><a name="p122648710618"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="10.14%" headers="mcps1.1.6.1.3 "><p id="p1726407566"><a name="p1726407566"></a><a name="p1726407566"></a>String(1-128)</p>
</td>
<td class="cellrowborder" valign="top" width="9.959999999999999%" headers="mcps1.1.6.1.4 "><p id="p11264771961"><a name="p11264771961"></a><a name="p11264771961"></a>子视图位置样式</p>
</td>
<td class="cellrowborder" valign="top" width="62.39%" headers="mcps1.1.6.1.5 "><p id="p122646711613"><a name="p122646711613"></a><a name="p122646711613"></a>样式分为：”default”,” “centerDivider”。默认为“default”，位置样式为俩边靠，无分隔线。” centerDivider”为等分居中且带分隔线。</p>
</td>
</tr>
<tr id="row172641471664"><td class="cellrowborder" valign="top" width="9.629999999999999%" headers="mcps1.1.6.1.1 "><p id="p8264373613"><a name="p8264373613"></a><a name="p8264373613"></a>uiList</p>
</td>
<td class="cellrowborder" valign="top" width="7.88%" headers="mcps1.1.6.1.2 "><p id="p32641171967"><a name="p32641171967"></a><a name="p32641171967"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="10.14%" headers="mcps1.1.6.1.3 "><p id="p626412711616"><a name="p626412711616"></a><a name="p626412711616"></a>DisplayItem[]</p>
</td>
<td class="cellrowborder" valign="top" width="9.959999999999999%" headers="mcps1.1.6.1.4 "><p id="p14265272065"><a name="p14265272065"></a><a name="p14265272065"></a>子视图列表</p>
</td>
<td class="cellrowborder" valign="top" width="62.39%" headers="mcps1.1.6.1.5 "><p id="p15265127360"><a name="p15265127360"></a><a name="p15265127360"></a>子视图列表，具体根据实际显示需要配置对应个数的显示控件。</p>
</td>
</tr>
</tbody>
</table>

子属性DisplayItem

<a name="table132132211713"></a>
<table><thead align="left"><tr id="row1317712215716"><th class="cellrowborder" valign="top" width="9.49%" id="mcps1.1.6.1.1"><p id="p1417712221976"><a name="p1417712221976"></a><a name="p1417712221976"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="7.920000000000001%" id="mcps1.1.6.1.2"><p id="p01777226719"><a name="p01777226719"></a><a name="p01777226719"></a>可选/必选</p>
</th>
<th class="cellrowborder" valign="top" width="9.94%" id="mcps1.1.6.1.3"><p id="p917711221578"><a name="p917711221578"></a><a name="p917711221578"></a>字段类型</p>
</th>
<th class="cellrowborder" valign="top" width="29.95%" id="mcps1.1.6.1.4"><p id="p1117742216716"><a name="p1117742216716"></a><a name="p1117742216716"></a>字段描述</p>
</th>
<th class="cellrowborder" valign="top" width="42.699999999999996%" id="mcps1.1.6.1.5"><p id="p191771722674"><a name="p191771722674"></a><a name="p191771722674"></a>备注</p>
</th>
</tr>
</thead>
<tbody><tr id="row1517710225719"><td class="cellrowborder" valign="top" width="9.49%" headers="mcps1.1.6.1.1 "><p id="p17178152210720"><a name="p17178152210720"></a><a name="p17178152210720"></a>subType</p>
</td>
<td class="cellrowborder" valign="top" width="7.920000000000001%" headers="mcps1.1.6.1.2 "><p id="p817816228720"><a name="p817816228720"></a><a name="p817816228720"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="9.94%" headers="mcps1.1.6.1.3 "><p id="p1178822471"><a name="p1178822471"></a><a name="p1178822471"></a>String(1-128)</p>
</td>
<td class="cellrowborder" valign="top" width="29.95%" headers="mcps1.1.6.1.4 "><p id="p10178622374"><a name="p10178622374"></a><a name="p10178622374"></a>子类型</p>
</td>
<td class="cellrowborder" valign="top" width="42.699999999999996%" headers="mcps1.1.6.1.5 "><p id="p171781222879"><a name="p171781222879"></a><a name="p171781222879"></a>纯文本，图标，图标+文本“text”，“icon”，“iconTextVertical”, “iconTextHorizontal”。</p>
</td>
</tr>
<tr id="row21781822778"><td class="cellrowborder" valign="top" width="9.49%" headers="mcps1.1.6.1.1 "><p id="p71781822479"><a name="p71781822479"></a><a name="p71781822479"></a>icon</p>
</td>
<td class="cellrowborder" valign="top" width="7.920000000000001%" headers="mcps1.1.6.1.2 "><p id="p11785221575"><a name="p11785221575"></a><a name="p11785221575"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="9.94%" headers="mcps1.1.6.1.3 "><p id="p1617816228718"><a name="p1617816228718"></a><a name="p1617816228718"></a>DynamicContent</p>
</td>
<td class="cellrowborder" valign="top" width="29.95%" headers="mcps1.1.6.1.4 "><p id="p13178102213716"><a name="p13178102213716"></a><a name="p13178102213716"></a>动态颜色、图标，文本，根据path路径下数据的范围动态匹配对应的值。同时写icon和text时，形成icon上，文字下的上下结构</p>
</td>
<td class="cellrowborder" valign="top" width="42.699999999999996%" headers="mcps1.1.6.1.5 "><pre class="screen" id="screen9696135614515"><a name="screen9696135614515"></a><a name="screen9696135614515"></a>示例代码如下：
"icon": {
    "defaultIcon":  "",
    "path":  "battery/useDay",
    "disableIcon":  "",
    "value": [
        {
            "scope":  "-50",
            "target":  ""
        },
        {
            "scope":  "50-100",
            "target":  ""
        },
        {
            "scope":  "100-",
            "target":  ""
        }
    ]
}</pre>
</td>
</tr>
<tr id="row31781622274"><td class="cellrowborder" valign="top" width="9.49%" headers="mcps1.1.6.1.1 "><p id="p1517816221278"><a name="p1517816221278"></a><a name="p1517816221278"></a>iconText</p>
</td>
<td class="cellrowborder" valign="top" width="7.920000000000001%" headers="mcps1.1.6.1.2 "><p id="p141783223717"><a name="p141783223717"></a><a name="p141783223717"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="9.94%" headers="mcps1.1.6.1.3 "><p id="p171781622975"><a name="p171781622975"></a><a name="p171781622975"></a>NormalText/DynamicText</p>
</td>
<td class="cellrowborder" valign="top" width="29.95%" headers="mcps1.1.6.1.4 "><p id="p11782221971"><a name="p11782221971"></a><a name="p11782221971"></a>图标描述文本</p>
</td>
<td class="cellrowborder" valign="top" width="42.699999999999996%" headers="mcps1.1.6.1.5 "><pre class="screen" id="screen45901443526"><a name="screen45901443526"></a><a name="screen45901443526"></a>"iconText":{
    "color": "",
    "type":  "normalText",
    "value":  "电量"
}</pre>
</td>
</tr>
<tr id="row1178112212715"><td class="cellrowborder" valign="top" width="9.49%" headers="mcps1.1.6.1.1 "><p id="p181788221478"><a name="p181788221478"></a><a name="p181788221478"></a>textDisplay</p>
</td>
<td class="cellrowborder" valign="top" width="7.920000000000001%" headers="mcps1.1.6.1.2 "><p id="p817832218710"><a name="p817832218710"></a><a name="p817832218710"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="9.94%" headers="mcps1.1.6.1.3 "><p id="p917882219713"><a name="p917882219713"></a><a name="p917882219713"></a>DiaplayContent</p>
</td>
<td class="cellrowborder" valign="top" width="29.95%" headers="mcps1.1.6.1.4 "><p id="p217810229718"><a name="p217810229718"></a><a name="p217810229718"></a>文字模板，分为上左，上右和下。3处文字根据实际需求填写，分为普通文本类型NormalText和动态文本类型DynamicText</p>
</td>
<td class="cellrowborder" valign="top" width="42.699999999999996%" headers="mcps1.1.6.1.5 "><pre class="screen" id="screen1195428183512"><a name="screen1195428183512"></a><a name="screen1195428183512"></a>"textDisplay": {
        "down": {},
        "upLeft": {
          "description": {
            "path": "bluetoothConnectStatus/bluetoothConnectStatus",
            "value": [
              {
                "scope": "0",
                "target": "未连接"
              },
              {
                "scope": "1",
                "target": "已连接"
              }
            ]
          },
          "type": "dynamicText",
          "value": "${bluetoothConnectStatus/bluetoothConnectStatus}"
        },
        "upRight": {}
      }</pre>
</td>
</tr>
</tbody>
</table>

子属性DynamicContent

<a name="table1360615314131"></a>
<table><thead align="left"><tr id="row208414391313"><th class="cellrowborder" valign="top" width="9.68%" id="mcps1.1.6.1.1"><p id="p19841123151311"><a name="p19841123151311"></a><a name="p19841123151311"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="8.27%" id="mcps1.1.6.1.2"><p id="p8841538131"><a name="p8841538131"></a><a name="p8841538131"></a>可选/必选</p>
</th>
<th class="cellrowborder" valign="top" width="9.39%" id="mcps1.1.6.1.3"><p id="p284273121310"><a name="p284273121310"></a><a name="p284273121310"></a>字段类型</p>
</th>
<th class="cellrowborder" valign="top" width="19.36%" id="mcps1.1.6.1.4"><p id="p1284212320137"><a name="p1284212320137"></a><a name="p1284212320137"></a>字段描述</p>
</th>
<th class="cellrowborder" valign="top" width="53.300000000000004%" id="mcps1.1.6.1.5"><p id="p284219331318"><a name="p284219331318"></a><a name="p284219331318"></a>备注</p>
</th>
</tr>
</thead>
<tbody><tr id="row184215310136"><td class="cellrowborder" valign="top" width="9.68%" headers="mcps1.1.6.1.1 "><p id="p68425311313"><a name="p68425311313"></a><a name="p68425311313"></a>path</p>
</td>
<td class="cellrowborder" valign="top" width="8.27%" headers="mcps1.1.6.1.2 "><p id="p1784213391317"><a name="p1784213391317"></a><a name="p1784213391317"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="9.39%" headers="mcps1.1.6.1.3 "><p id="p148429331310"><a name="p148429331310"></a><a name="p148429331310"></a>String  (1-128)</p>
</td>
<td class="cellrowborder" valign="top" width="19.36%" headers="mcps1.1.6.1.4 "><p id="p384213381320"><a name="p384213381320"></a><a name="p384213381320"></a>动态内容条件值，可能需要动态获取设备数据填充</p>
</td>
<td class="cellrowborder" valign="top" width="53.300000000000004%" headers="mcps1.1.6.1.5 "><p id="p184210351313"><a name="p184210351313"></a><a name="p184210351313"></a>例如：“bluetoothConnectStatus/bluetoothConnectStatus” ，表示当前设备状态的值。</p>
</td>
</tr>
<tr id="row68421032133"><td class="cellrowborder" valign="top" width="9.68%" headers="mcps1.1.6.1.1 "><p id="p108428351316"><a name="p108428351316"></a><a name="p108428351316"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="8.27%" headers="mcps1.1.6.1.2 "><p id="p684283111317"><a name="p684283111317"></a><a name="p684283111317"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="9.39%" headers="mcps1.1.6.1.3 "><p id="p4842238139"><a name="p4842238139"></a><a name="p4842238139"></a>Variation</p>
</td>
<td class="cellrowborder" valign="top" width="19.36%" headers="mcps1.1.6.1.4 "><p id="p884273101316"><a name="p884273101316"></a><a name="p884273101316"></a>动态范围值</p>
</td>
<td class="cellrowborder" valign="top" width="53.300000000000004%" headers="mcps1.1.6.1.5 "><p id="p184216351316"><a name="p184216351316"></a><a name="p184216351316"></a>{     "scope": "0",     "target": "未连接" }。</p>
</td>
</tr>
</tbody>
</table>

子属性Variation

<a name="table1962012331312"></a>
<table><thead align="left"><tr id="row2084217311131"><th class="cellrowborder" valign="top" width="9.9%" id="mcps1.1.6.1.1"><p id="p118423311311"><a name="p118423311311"></a><a name="p118423311311"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="10.68%" id="mcps1.1.6.1.2"><p id="p68421235132"><a name="p68421235132"></a><a name="p68421235132"></a>可选/必选</p>
</th>
<th class="cellrowborder" valign="top" width="11.37%" id="mcps1.1.6.1.3"><p id="p18429317136"><a name="p18429317136"></a><a name="p18429317136"></a>字段类型</p>
</th>
<th class="cellrowborder" valign="top" width="14.95%" id="mcps1.1.6.1.4"><p id="p128429321313"><a name="p128429321313"></a><a name="p128429321313"></a>字段描述</p>
</th>
<th class="cellrowborder" valign="top" width="53.1%" id="mcps1.1.6.1.5"><p id="p38436314139"><a name="p38436314139"></a><a name="p38436314139"></a>备注</p>
</th>
</tr>
</thead>
<tbody><tr id="row184317317132"><td class="cellrowborder" valign="top" width="9.9%" headers="mcps1.1.6.1.1 "><p id="p984318311135"><a name="p984318311135"></a><a name="p984318311135"></a>scope</p>
</td>
<td class="cellrowborder" valign="top" width="10.68%" headers="mcps1.1.6.1.2 "><p id="p1484317315136"><a name="p1484317315136"></a><a name="p1484317315136"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="11.37%" headers="mcps1.1.6.1.3 "><p id="p584373151316"><a name="p584373151316"></a><a name="p584373151316"></a>String  (1-128)</p>
</td>
<td class="cellrowborder" valign="top" width="14.95%" headers="mcps1.1.6.1.4 "><p id="p484314321315"><a name="p484314321315"></a><a name="p484314321315"></a>条件范围</p>
</td>
<td class="cellrowborder" valign="top" width="53.1%" headers="mcps1.1.6.1.5 "><p id="p15843143151310"><a name="p15843143151310"></a><a name="p15843143151310"></a>用“-”区分范围，有五种类型：  1，-50：表示小于等于50的值  2，50-100；表示大于50小于等于100；  3，100-：表示大于100的值  4，"scope": "-"时，表示可以匹配任意场景。  5，50：表示等于50。</p>
</td>
</tr>
<tr id="row184318313138"><td class="cellrowborder" valign="top" width="9.9%" headers="mcps1.1.6.1.1 "><p id="p178432371315"><a name="p178432371315"></a><a name="p178432371315"></a>target</p>
</td>
<td class="cellrowborder" valign="top" width="10.68%" headers="mcps1.1.6.1.2 "><p id="p158434341310"><a name="p158434341310"></a><a name="p158434341310"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="11.37%" headers="mcps1.1.6.1.3 "><p id="p48431331320"><a name="p48431331320"></a><a name="p48431331320"></a>String (1-128)</p>
</td>
<td class="cellrowborder" valign="top" width="14.95%" headers="mcps1.1.6.1.4 "><p id="p1484313361315"><a name="p1484313361315"></a><a name="p1484313361315"></a>条件对应的值</p>
</td>
<td class="cellrowborder" valign="top" width="53.1%" headers="mcps1.1.6.1.5 "><p id="p5843737131"><a name="p5843737131"></a><a name="p5843737131"></a>可能是颜色值，资源值等，例如："11FCFC"，图标url。</p>
</td>
</tr>
<tr id="row984317321315"><td class="cellrowborder" valign="top" width="9.9%" headers="mcps1.1.6.1.1 "><p id="p584323141313"><a name="p584323141313"></a><a name="p584323141313"></a>defaultTarget</p>
</td>
<td class="cellrowborder" valign="top" width="10.68%" headers="mcps1.1.6.1.2 "><p id="p168431033131"><a name="p168431033131"></a><a name="p168431033131"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="11.37%" headers="mcps1.1.6.1.3 "><p id="p12843183131317"><a name="p12843183131317"></a><a name="p12843183131317"></a>String  (1-128)</p>
</td>
<td class="cellrowborder" valign="top" width="14.95%" headers="mcps1.1.6.1.4 "><p id="p148432371313"><a name="p148432371313"></a><a name="p148432371313"></a>默认图标url</p>
</td>
<td class="cellrowborder" valign="top" width="53.1%" headers="mcps1.1.6.1.5 "><p id="p684320341314"><a name="p684320341314"></a><a name="p684320341314"></a>默认图标url。</p>
</td>
</tr>
<tr id="row10843183151316"><td class="cellrowborder" valign="top" width="9.9%" headers="mcps1.1.6.1.1 "><p id="p1884310361313"><a name="p1884310361313"></a><a name="p1884310361313"></a>disableTarget</p>
</td>
<td class="cellrowborder" valign="top" width="10.68%" headers="mcps1.1.6.1.2 "><p id="p684343161319"><a name="p684343161319"></a><a name="p684343161319"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="11.37%" headers="mcps1.1.6.1.3 "><p id="p08438351315"><a name="p08438351315"></a><a name="p08438351315"></a>String  (1-128)</p>
</td>
<td class="cellrowborder" valign="top" width="14.95%" headers="mcps1.1.6.1.4 "><p id="p2084314316139"><a name="p2084314316139"></a><a name="p2084314316139"></a>不可用图标url</p>
</td>
<td class="cellrowborder" valign="top" width="53.1%" headers="mcps1.1.6.1.5 "><p id="p2844163151317"><a name="p2844163151317"></a><a name="p2844163151317"></a>不可用图标url。</p>
</td>
</tr>
</tbody>
</table>

子属性NormalText

<a name="table176350316130"></a>
<table><thead align="left"><tr id="row28441138131"><th class="cellrowborder" valign="top" width="10.17%" id="mcps1.1.6.1.1"><p id="p138441137137"><a name="p138441137137"></a><a name="p138441137137"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="8.19%" id="mcps1.1.6.1.2"><p id="p28441437136"><a name="p28441437136"></a><a name="p28441437136"></a>可选/必选</p>
</th>
<th class="cellrowborder" valign="top" width="10.03%" id="mcps1.1.6.1.3"><p id="p148444316135"><a name="p148444316135"></a><a name="p148444316135"></a>字段类型</p>
</th>
<th class="cellrowborder" valign="top" width="18.88%" id="mcps1.1.6.1.4"><p id="p58441035134"><a name="p58441035134"></a><a name="p58441035134"></a>字段描述</p>
</th>
<th class="cellrowborder" valign="top" width="52.73%" id="mcps1.1.6.1.5"><p id="p188441930137"><a name="p188441930137"></a><a name="p188441930137"></a>备注</p>
</th>
</tr>
</thead>
<tbody><tr id="row984433181311"><td class="cellrowborder" valign="top" width="10.17%" headers="mcps1.1.6.1.1 "><p id="p17844103191310"><a name="p17844103191310"></a><a name="p17844103191310"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="8.19%" headers="mcps1.1.6.1.2 "><p id="p108441534132"><a name="p108441534132"></a><a name="p108441534132"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="10.03%" headers="mcps1.1.6.1.3 "><p id="p13844123201319"><a name="p13844123201319"></a><a name="p13844123201319"></a>String  (1-128)</p>
</td>
<td class="cellrowborder" valign="top" width="18.88%" headers="mcps1.1.6.1.4 "><p id="p78448301318"><a name="p78448301318"></a><a name="p78448301318"></a>类型字段</p>
</td>
<td class="cellrowborder" valign="top" width="52.73%" headers="mcps1.1.6.1.5 "><p id="p118441737135"><a name="p118441737135"></a><a name="p118441737135"></a>固定为NormalText。</p>
</td>
</tr>
<tr id="row12844133111312"><td class="cellrowborder" valign="top" width="10.17%" headers="mcps1.1.6.1.1 "><p id="p48446311139"><a name="p48446311139"></a><a name="p48446311139"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="8.19%" headers="mcps1.1.6.1.2 "><p id="p984416318139"><a name="p984416318139"></a><a name="p984416318139"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="10.03%" headers="mcps1.1.6.1.3 "><p id="p68441235131"><a name="p68441235131"></a><a name="p68441235131"></a>String  (1-128)</p>
</td>
<td class="cellrowborder" valign="top" width="18.88%" headers="mcps1.1.6.1.4 "><p id="p1844163131317"><a name="p1844163131317"></a><a name="p1844163131317"></a>当前控件显示名称</p>
</td>
<td class="cellrowborder" valign="top" width="52.73%" headers="mcps1.1.6.1.5 "><p id="p48441737133"><a name="p48441737133"></a><a name="p48441737133"></a>固定值，例如："value":  "电量"。</p>
</td>
</tr>
<tr id="row68440318132"><td class="cellrowborder" valign="top" width="10.17%" headers="mcps1.1.6.1.1 "><p id="p1484493161313"><a name="p1484493161313"></a><a name="p1484493161313"></a>color</p>
</td>
<td class="cellrowborder" valign="top" width="8.19%" headers="mcps1.1.6.1.2 "><p id="p178448311138"><a name="p178448311138"></a><a name="p178448311138"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="10.03%" headers="mcps1.1.6.1.3 "><p id="p684414331318"><a name="p684414331318"></a><a name="p684414331318"></a>String  (1-128)</p>
</td>
<td class="cellrowborder" valign="top" width="18.88%" headers="mcps1.1.6.1.4 "><p id="p158455310131"><a name="p158455310131"></a><a name="p158455310131"></a>当前控件显示颜色</p>
</td>
<td class="cellrowborder" valign="top" width="52.73%" headers="mcps1.1.6.1.5 "><p id="p1084513111320"><a name="p1084513111320"></a><a name="p1084513111320"></a>固定值，例如："11FCFC"。</p>
</td>
</tr>
</tbody>
</table>

子属性DynamicText

<a name="table5647103101317"></a>
<table><thead align="left"><tr id="row1184516391320"><th class="cellrowborder" valign="top" width="10.43%" id="mcps1.1.6.1.1"><p id="p98457311131"><a name="p98457311131"></a><a name="p98457311131"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="8.27%" id="mcps1.1.6.1.2"><p id="p78453361313"><a name="p78453361313"></a><a name="p78453361313"></a>可选/必选</p>
</th>
<th class="cellrowborder" valign="top" width="10.05%" id="mcps1.1.6.1.3"><p id="p188458316132"><a name="p188458316132"></a><a name="p188458316132"></a>字段类型</p>
</th>
<th class="cellrowborder" valign="top" width="18.63%" id="mcps1.1.6.1.4"><p id="p168451734134"><a name="p168451734134"></a><a name="p168451734134"></a>字段描述</p>
</th>
<th class="cellrowborder" valign="top" width="52.62%" id="mcps1.1.6.1.5"><p id="p98455313134"><a name="p98455313134"></a><a name="p98455313134"></a>备注</p>
</th>
</tr>
</thead>
<tbody><tr id="row1884512320131"><td class="cellrowborder" valign="top" width="10.43%" headers="mcps1.1.6.1.1 "><p id="p168452311319"><a name="p168452311319"></a><a name="p168452311319"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="8.27%" headers="mcps1.1.6.1.2 "><p id="p198450320131"><a name="p198450320131"></a><a name="p198450320131"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="10.05%" headers="mcps1.1.6.1.3 "><p id="p284510312132"><a name="p284510312132"></a><a name="p284510312132"></a>String  (1-128)</p>
</td>
<td class="cellrowborder" valign="top" width="18.63%" headers="mcps1.1.6.1.4 "><p id="p4845153131317"><a name="p4845153131317"></a><a name="p4845153131317"></a>类型字段</p>
</td>
<td class="cellrowborder" valign="top" width="52.62%" headers="mcps1.1.6.1.5 "><p id="p684593121317"><a name="p684593121317"></a><a name="p684593121317"></a>固定为DynamicText。</p>
</td>
</tr>
<tr id="row15845123161318"><td class="cellrowborder" valign="top" width="10.43%" headers="mcps1.1.6.1.1 "><p id="p108457371314"><a name="p108457371314"></a><a name="p108457371314"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="8.27%" headers="mcps1.1.6.1.2 "><p id="p7845193121311"><a name="p7845193121311"></a><a name="p7845193121311"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="10.05%" headers="mcps1.1.6.1.3 "><p id="p148458316137"><a name="p148458316137"></a><a name="p148458316137"></a>String  (1-128)</p>
</td>
<td class="cellrowborder" valign="top" width="18.63%" headers="mcps1.1.6.1.4 "><p id="p284573191319"><a name="p284573191319"></a><a name="p284573191319"></a>当前控件显示名称</p>
</td>
<td class="cellrowborder" valign="top" width="52.62%" headers="mcps1.1.6.1.5 "><p id="p1684563181310"><a name="p1684563181310"></a><a name="p1684563181310"></a>例如：“${bluetoothConnectStatus/bluetoothConnectStatus}”注意：此处<strong id="b188451310130"><a name="b188451310130"></a><a name="b188451310130"></a>${}</strong>表示占位符，内部数据需要根据设备上报结果进行动态匹配。</p>
</td>
</tr>
<tr id="row16845163151311"><td class="cellrowborder" valign="top" width="10.43%" headers="mcps1.1.6.1.1 "><p id="p2846035131"><a name="p2846035131"></a><a name="p2846035131"></a>ratio</p>
</td>
<td class="cellrowborder" valign="top" width="8.27%" headers="mcps1.1.6.1.2 "><p id="p7846832138"><a name="p7846832138"></a><a name="p7846832138"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="10.05%" headers="mcps1.1.6.1.3 "><p id="p10846153171316"><a name="p10846153171316"></a><a name="p10846153171316"></a>float</p>
</td>
<td class="cellrowborder" valign="top" width="18.63%" headers="mcps1.1.6.1.4 "><p id="p28461934134"><a name="p28461934134"></a><a name="p28461934134"></a>补偿因子</p>
</td>
<td class="cellrowborder" valign="top" width="52.62%" headers="mcps1.1.6.1.5 "><p id="p1684612311131"><a name="p1684612311131"></a><a name="p1684612311131"></a>例如：牙刷的电量是0.5，实际页面显示为百分数，显示内容为50%，那么补偿因子为0.01，再选中页面数值后，控制的过程中，要再次除以补偿因子，进行命令下发。</p>
</td>
</tr>
<tr id="row15847123121315"><td class="cellrowborder" valign="top" width="10.43%" headers="mcps1.1.6.1.1 "><p id="p284715317137"><a name="p284715317137"></a><a name="p284715317137"></a>color</p>
</td>
<td class="cellrowborder" valign="top" width="8.27%" headers="mcps1.1.6.1.2 "><p id="p784711320139"><a name="p784711320139"></a><a name="p784711320139"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="10.05%" headers="mcps1.1.6.1.3 "><p id="p128479313138"><a name="p128479313138"></a><a name="p128479313138"></a>DynamicContent</p>
</td>
<td class="cellrowborder" valign="top" width="18.63%" headers="mcps1.1.6.1.4 "><p id="p10847163151316"><a name="p10847163151316"></a><a name="p10847163151316"></a>当前控件显示颜色，动态值</p>
</td>
<td class="cellrowborder" valign="top" width="52.62%" headers="mcps1.1.6.1.5 "><pre class="screen" id="screen27471327175210"><a name="screen27471327175210"></a><a name="screen27471327175210"></a>"color": {
    "path": "battery/useDay",
    "value": [
        {
            "scope": "-50",
            "target": "11FCFC"
        },
        {
            "scope": "50-100",
            "target": "22FCFC"
        },
        {
            "scope": "100-",
            "target": "33FCFC"
        }
    ]
}</pre>
</td>
</tr>
<tr id="row7847133131311"><td class="cellrowborder" valign="top" width="10.43%" headers="mcps1.1.6.1.1 "><p id="p158471033135"><a name="p158471033135"></a><a name="p158471033135"></a>description</p>
</td>
<td class="cellrowborder" valign="top" width="8.27%" headers="mcps1.1.6.1.2 "><p id="p118478317135"><a name="p118478317135"></a><a name="p118478317135"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="10.05%" headers="mcps1.1.6.1.3 "><p id="p9847153191319"><a name="p9847153191319"></a><a name="p9847153191319"></a>DynamicContent</p>
</td>
<td class="cellrowborder" valign="top" width="18.63%" headers="mcps1.1.6.1.4 "><p id="p384716319139"><a name="p384716319139"></a><a name="p384716319139"></a>当前控件描述转换，动态值</p>
</td>
<td class="cellrowborder" valign="top" width="52.62%" headers="mcps1.1.6.1.5 "><pre class="screen" id="screen8602174085214"><a name="screen8602174085214"></a><a name="screen8602174085214"></a>"description": {
    "path": "bluetoothConnectStatus/bluetoothConnectStatus",
    "value": [
        {
            "scope": "0",
            "target": "未连接"
        },
        {
            "scope": "1",
            "target": "已连接"
        }
    ]
}</pre>
</td>
</tr>
</tbody>
</table>

## Enum控件<a name="section566910277516"></a>

Enum控件用于类型选择，支持显示一行或两行区域内容，每行里面有一到四个区域内容，内容之间带分割线。每个区域内容由图片和文字构成，图片在上方，文字在下方。每个区域内容可以点击，点击后将会根据用户设置切换为对应的图片，表示此区域状态改变。如下方阅读区域，图片切换为蓝色，表示处于激活状态。

示例图：

![](figures/enum-component.png)

对应样例：

```
{
      "gravity": "centerDivider",
      "heightType": "default",
      "name": "模式",
      "span": 1,
      "command": [
        {
          "characteristic": "mode",
          "enumInfo": [
            {
              "displayItem":{
                "icon": {
                  "path": "lightMode/mode",
                  "value": [
                    {
                      "defaultTarget": "/ic_read_nor.png",
                      "scope": "-",
                      "target": "/ic_read_on.png"
                    }
                  ],
                  "valueNight": [
                    {
                      "defaultTarget": "/ic_read_nor_dark.png",
                      "scope": "-",
                      "target": "/ic_read_on_dark.png"
                    }
                  ]
                },
                "iconText": {
                  "type": "normalText",
                  "value": "阅读"
                },
                "subType": "iconTextVertical"
              },
              "value": 2
            },
            {
              "displayItem": {
                "icon": {
                  "path": "lightMode/mode",
                  "value": [
                    {
                      "defaultTarget": "/ic_write_nor.png",
                      "scope": "-",
                      "target": "/ic_write_on.png"
                    }
                  ],
                  "valueNight": [
                    {
                      "defaultTarget": "/ic_write_nor_dark.png",
                      "scope": "-",
                      "target": "/ic_write_on_dark.png"
                    }
                  ]
                },
                "iconText": {
                  "type": "normalText",
                  "value": "书写"
                },
                "subType": "iconTextVertical"
              },
              "value": 3
            },
            {
              "displayItem": {
                "icon": {
                  "path": "lightMode/mode",
                  "value": [
                    {
                      "defaultTarget": "/ic_computer_nor.png",
                      "scope": "-",
                      "target": "/ic_computer_on.png"
                    }
                  ],
                  "valueNight": [
                    {
                      "defaultTarget": "/ic_computer_nor_dark.png",
                      "scope": "-",
                      "target": "/ic_computer_on_dark.png"
                    }
                  ]
                },
                "iconText": {
                  "type": "normalText",
                  "value": "电脑"
                },
                "subType": "iconTextVertical"
              },
              "value": 4
            },
            {
              "displayItem": {
                "icon": {
                  "path": "lightMode/mode",
                  "value": [
                    {
                      "defaultTarget": "/ic_favorite_nor.png",
                      "scope": "-",
                      "target": "/ic_favorite_on.png"
                    }
                  ],
                  "valueNight": [
                    {
                      "defaultTarget": "/ic_favorite_nor_dark.png",
                      "scope": "-",
                      "target": "/ic_favorite_on_dark.png"
                    }
                  ]
                },
                "iconText": {
                  "type": "normalText",
                  "value": "最爱"
                },
                "subType": "iconTextVertical"
              },
              "value": 5
            }
          ],
          "sid": "lightMode"
        }
      ],
      "uiType": "ENUM"
    }
```

相关的参数，定义如下：

<a name="table171451016102714"></a>
<table><thead align="left"><tr id="row1634761618278"><th class="cellrowborder" valign="top" width="20.02%" id="mcps1.1.6.1.1"><p id="p4347816132719"><a name="p4347816132719"></a><a name="p4347816132719"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="19.98%" id="mcps1.1.6.1.2"><p id="p434711662719"><a name="p434711662719"></a><a name="p434711662719"></a>可选/必选</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.3"><p id="p2034731622715"><a name="p2034731622715"></a><a name="p2034731622715"></a>字段类型</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.4"><p id="p163471316112712"><a name="p163471316112712"></a><a name="p163471316112712"></a>字段描述</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.5"><p id="p12347416152710"><a name="p12347416152710"></a><a name="p12347416152710"></a>备注</p>
</th>
</tr>
</thead>
<tbody><tr id="row4347171613278"><td class="cellrowborder" valign="top" width="20.02%" headers="mcps1.1.6.1.1 "><p id="p334711169272"><a name="p334711169272"></a><a name="p334711169272"></a>name</p>
</td>
<td class="cellrowborder" valign="top" width="19.98%" headers="mcps1.1.6.1.2 "><p id="p14347816202717"><a name="p14347816202717"></a><a name="p14347816202717"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p15347191632713"><a name="p15347191632713"></a><a name="p15347191632713"></a>String (1-128)</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p20347141692714"><a name="p20347141692714"></a><a name="p20347141692714"></a>当前控件显示名称</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p17347181617271"><a name="p17347181617271"></a><a name="p17347181617271"></a>例如：“亮度”。</p>
</td>
</tr>
<tr id="row1634791615273"><td class="cellrowborder" valign="top" width="20.02%" headers="mcps1.1.6.1.1 "><p id="p123481316162717"><a name="p123481316162717"></a><a name="p123481316162717"></a>span</p>
</td>
<td class="cellrowborder" valign="top" width="19.98%" headers="mcps1.1.6.1.2 "><p id="p12348121612720"><a name="p12348121612720"></a><a name="p12348121612720"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p9348101612713"><a name="p9348101612713"></a><a name="p9348101612713"></a>float</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p20348101618270"><a name="p20348101618270"></a><a name="p20348101618270"></a>跨度</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p1034817165273"><a name="p1034817165273"></a><a name="p1034817165273"></a>根据手机设置控件的宽度占比，为1表示占满普通手机的宽。</p>
</td>
</tr>
<tr id="row134891662711"><td class="cellrowborder" valign="top" width="20.02%" headers="mcps1.1.6.1.1 "><p id="p934881642719"><a name="p934881642719"></a><a name="p934881642719"></a>uiType</p>
</td>
<td class="cellrowborder" valign="top" width="19.98%" headers="mcps1.1.6.1.2 "><p id="p234831652715"><a name="p234831652715"></a><a name="p234831652715"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p123481416152712"><a name="p123481416152712"></a><a name="p123481416152712"></a>String(1-128)</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p14349101692710"><a name="p14349101692710"></a><a name="p14349101692710"></a>控件风格</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p1534931612710"><a name="p1534931612710"></a><a name="p1534931612710"></a>控件风格为：“DISPLAY” ，“REVERSAL”,“INCREASE_DECREASE”，“ENUM” ，“MULTIFUNCTION”。</p>
</td>
</tr>
<tr id="row19349181692711"><td class="cellrowborder" valign="top" width="20.02%" headers="mcps1.1.6.1.1 "><p id="p11349191610274"><a name="p11349191610274"></a><a name="p11349191610274"></a>tag</p>
</td>
<td class="cellrowborder" valign="top" width="19.98%" headers="mcps1.1.6.1.2 "><p id="p63491816192715"><a name="p63491816192715"></a><a name="p63491816192715"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p5349111672712"><a name="p5349111672712"></a><a name="p5349111672712"></a>String(1-128)</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p15349151611274"><a name="p15349151611274"></a><a name="p15349151611274"></a>标记</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p734981614270"><a name="p734981614270"></a><a name="p734981614270"></a>扩展字段，用作标记特殊控件处理。</p>
</td>
</tr>
<tr id="row5349151617276"><td class="cellrowborder" valign="top" width="20.02%" headers="mcps1.1.6.1.1 "><p id="p2349181617273"><a name="p2349181617273"></a><a name="p2349181617273"></a>heightType</p>
</td>
<td class="cellrowborder" valign="top" width="19.98%" headers="mcps1.1.6.1.2 "><p id="p133491716182716"><a name="p133491716182716"></a><a name="p133491716182716"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p7349151610278"><a name="p7349151610278"></a><a name="p7349151610278"></a>String(1-128)</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p11349151682711"><a name="p11349151682711"></a><a name="p11349151682711"></a>高度类型</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p1334921692713"><a name="p1334921692713"></a><a name="p1334921692713"></a>“default”，“low”；默认为“default”。</p>
</td>
</tr>
<tr id="row10349516102719"><td class="cellrowborder" valign="top" width="20.02%" headers="mcps1.1.6.1.1 "><p id="p3349131620272"><a name="p3349131620272"></a><a name="p3349131620272"></a>command</p>
</td>
<td class="cellrowborder" valign="top" width="19.98%" headers="mcps1.1.6.1.2 "><p id="p19349191642710"><a name="p19349191642710"></a><a name="p19349191642710"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p434911602717"><a name="p434911602717"></a><a name="p434911602717"></a>Command[]</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p183501716162714"><a name="p183501716162714"></a><a name="p183501716162714"></a>控件对应的动作数组</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p1135010166270"><a name="p1135010166270"></a><a name="p1135010166270"></a>ACTION_NORMAL在前面，ACTION_ENUM在后面，下发命令为串行下发，先发完所有的ACTION_NORMAL再发ACTION_ENUM。</p>
</td>
</tr>
<tr id="row0350151610277"><td class="cellrowborder" valign="top" width="20.02%" headers="mcps1.1.6.1.1 "><p id="p173501716162720"><a name="p173501716162720"></a><a name="p173501716162720"></a>gravity</p>
</td>
<td class="cellrowborder" valign="top" width="19.98%" headers="mcps1.1.6.1.2 "><p id="p143504167271"><a name="p143504167271"></a><a name="p143504167271"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p735021692719"><a name="p735021692719"></a><a name="p735021692719"></a>String(1-128)</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p183501616202712"><a name="p183501616202712"></a><a name="p183501616202712"></a>子视图位置样式</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p163501616102716"><a name="p163501616102716"></a><a name="p163501616102716"></a>样式分为：”default”,” center”，“centerDivider”。默认为“default”，位置样式为俩边靠，无分隔线。” center”为等分居中，” centerDivider”为等分居中且带分隔线。</p>
</td>
</tr>
</tbody>
</table>

NormalCommand

<a name="table14168216192719"></a>
<table><thead align="left"><tr id="row123502160271"><th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.1"><p id="p3350141652716"><a name="p3350141652716"></a><a name="p3350141652716"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.2"><p id="p2350171632710"><a name="p2350171632710"></a><a name="p2350171632710"></a>可选/必选</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.3"><p id="p19350101692718"><a name="p19350101692718"></a><a name="p19350101692718"></a>字段类型</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.4"><p id="p113501516182719"><a name="p113501516182719"></a><a name="p113501516182719"></a>字段描述</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.5"><p id="p16350161616271"><a name="p16350161616271"></a><a name="p16350161616271"></a>备注</p>
</th>
</tr>
</thead>
<tbody><tr id="row2350121613279"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p18350131602711"><a name="p18350131602711"></a><a name="p18350131602711"></a>sid</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p435151672710"><a name="p435151672710"></a><a name="p435151672710"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p16351121614279"><a name="p16351121614279"></a><a name="p16351121614279"></a>String  (1-32)</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p13515161279"><a name="p13515161279"></a><a name="p13515161279"></a>命令对应的服务</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p5351181692711"><a name="p5351181692711"></a><a name="p5351181692711"></a>例如：“lightMode”。</p>
</td>
</tr>
<tr id="row1835111692713"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p735101662715"><a name="p735101662715"></a><a name="p735101662715"></a>characteristic</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p23515165276"><a name="p23515165276"></a><a name="p23515165276"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p16351141632714"><a name="p16351141632714"></a><a name="p16351141632714"></a>String  (1-32)</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p1635181610279"><a name="p1635181610279"></a><a name="p1635181610279"></a>命令对应的属性</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p18351141619279"><a name="p18351141619279"></a><a name="p18351141619279"></a>例如：“mode”。</p>
</td>
</tr>
<tr id="row535111167274"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p143511716102716"><a name="p143511716102716"></a><a name="p143511716102716"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p835211610276"><a name="p835211610276"></a><a name="p835211610276"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p123521716172713"><a name="p123521716172713"></a><a name="p123521716172713"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p133527165274"><a name="p133527165274"></a><a name="p133527165274"></a>下发命令值</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p23521816192710"><a name="p23521816192710"></a><a name="p23521816192710"></a>例如："value": 1。</p>
</td>
</tr>
</tbody>
</table>

EnumCommand

<a name="table181799166277"></a>
<table><thead align="left"><tr id="row18352201614276"><th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.1"><p id="p835281612714"><a name="p835281612714"></a><a name="p835281612714"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.2"><p id="p83521116162714"><a name="p83521116162714"></a><a name="p83521116162714"></a>可选/必选</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.3"><p id="p143521216192719"><a name="p143521216192719"></a><a name="p143521216192719"></a>字段类型</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.4"><p id="p153521516112714"><a name="p153521516112714"></a><a name="p153521516112714"></a>字段描述</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.5"><p id="p7352111672717"><a name="p7352111672717"></a><a name="p7352111672717"></a>备注</p>
</th>
</tr>
</thead>
<tbody><tr id="row23520164271"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p11352101614274"><a name="p11352101614274"></a><a name="p11352101614274"></a>sid</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p1135251616271"><a name="p1135251616271"></a><a name="p1135251616271"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p1352151682712"><a name="p1352151682712"></a><a name="p1352151682712"></a>String  (1-32)</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p123521616142712"><a name="p123521616142712"></a><a name="p123521616142712"></a>命令对应的服务</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p2035218164275"><a name="p2035218164275"></a><a name="p2035218164275"></a>例如：“lightMode”。</p>
</td>
</tr>
<tr id="row1635218165273"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p12352016192715"><a name="p12352016192715"></a><a name="p12352016192715"></a>characteristic</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p0353151613274"><a name="p0353151613274"></a><a name="p0353151613274"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p1835314160272"><a name="p1835314160272"></a><a name="p1835314160272"></a>String  (1-32)</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p1935315168272"><a name="p1935315168272"></a><a name="p1935315168272"></a>命令对应的属性</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p113531168277"><a name="p113531168277"></a><a name="p113531168277"></a>例如：“mode”。</p>
</td>
</tr>
<tr id="row535318165272"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p8353101612277"><a name="p8353101612277"></a><a name="p8353101612277"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p1435320165277"><a name="p1435320165277"></a><a name="p1435320165277"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p163535167279"><a name="p163535167279"></a><a name="p163535167279"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p113532016112717"><a name="p113532016112717"></a><a name="p113532016112717"></a>下发命令值</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p113541816112712"><a name="p113541816112712"></a><a name="p113541816112712"></a>例如："value": 1。</p>
</td>
</tr>
</tbody>
</table>

EnumInfo

<a name="table1019021682716"></a>
<table><thead align="left"><tr id="row535441618278"><th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.1"><p id="p435471692710"><a name="p435471692710"></a><a name="p435471692710"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.2"><p id="p63541416142715"><a name="p63541416142715"></a><a name="p63541416142715"></a>可选/必选</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.3"><p id="p1735419161278"><a name="p1735419161278"></a><a name="p1735419161278"></a>字段类型</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.4"><p id="p12354111620274"><a name="p12354111620274"></a><a name="p12354111620274"></a>字段描述</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.5"><p id="p1235491614277"><a name="p1235491614277"></a><a name="p1235491614277"></a>备注</p>
</th>
</tr>
</thead>
<tbody><tr id="row10355131642719"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p1735581632716"><a name="p1735581632716"></a><a name="p1735581632716"></a>displayItem</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p15355016182710"><a name="p15355016182710"></a><a name="p15355016182710"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p143551716142719"><a name="p143551716142719"></a><a name="p143551716142719"></a>DisplayItem</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p5355181613275"><a name="p5355181613275"></a><a name="p5355181613275"></a>通用展示子视图</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p16355216192713"><a name="p16355216192713"></a><a name="p16355216192713"></a>通用展示子视图。</p>
</td>
</tr>
<tr id="row73555163278"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p16355131619273"><a name="p16355131619273"></a><a name="p16355131619273"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p1935581612710"><a name="p1935581612710"></a><a name="p1935581612710"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p1735581662715"><a name="p1735581662715"></a><a name="p1735581662715"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p43551816182710"><a name="p43551816182710"></a><a name="p43551816182710"></a>命令对应的服务属性值</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p13551160270"><a name="p13551160270"></a><a name="p13551160270"></a>例如：4。</p>
</td>
</tr>
<tr id="row103551716132717"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p1735681611273"><a name="p1735681611273"></a><a name="p1735681611273"></a>disable</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p173569164276"><a name="p173569164276"></a><a name="p173569164276"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p1135615161278"><a name="p1135615161278"></a><a name="p1135615161278"></a>String[]</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p11356111632717"><a name="p11356111632717"></a><a name="p11356111632717"></a>命令触发后禁用的标签数组</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p113562167273"><a name="p113562167273"></a><a name="p113562167273"></a>例如：["亮度"]，例如：台灯关闭的时候，禁用亮度调节。</p>
</td>
</tr>
</tbody>
</table>

## Reversal控件<a name="section162211550155113"></a>

Reversal控件用于开关选择，支持显示两个或三个区域。每个区域可显示内容如下表所示。文字颜色支持自定义，颜色和图片支持需根据数据范围来选择。右边的区域内容只可用于显示开关图片。

**表 1**  Reversal控件开关选择内容介绍

<a name="table7929192110592"></a>
<table><thead align="left"><tr id="row49307215590"><th class="cellrowborder" valign="top" width="12.521252125212524%" id="mcps1.2.4.1.1"><p id="p99301921135916"><a name="p99301921135916"></a><a name="p99301921135916"></a>区域</p>
</th>
<th class="cellrowborder" valign="top" width="54.14541454145414%" id="mcps1.2.4.1.2"><p id="p199302021195915"><a name="p199302021195915"></a><a name="p199302021195915"></a>可显示内容</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p3930112112595"><a name="p3930112112595"></a><a name="p3930112112595"></a>是否必须</p>
</th>
</tr>
</thead>
<tbody><tr id="row493010219594"><td class="cellrowborder" valign="top" width="12.521252125212524%" headers="mcps1.2.4.1.1 "><p id="p1793062105916"><a name="p1793062105916"></a><a name="p1793062105916"></a>左边区域</p>
</td>
<td class="cellrowborder" valign="top" width="54.14541454145414%" headers="mcps1.2.4.1.2 "><p id="p319946603"><a name="p319946603"></a><a name="p319946603"></a>文字或者文字加图片（图片显示大小固定为 24vp *24vp）</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p793082117593"><a name="p793082117593"></a><a name="p793082117593"></a>必选</p>
</td>
</tr>
<tr id="row493072135919"><td class="cellrowborder" valign="top" width="12.521252125212524%" headers="mcps1.2.4.1.1 "><p id="p59307216598"><a name="p59307216598"></a><a name="p59307216598"></a>中间区域</p>
</td>
<td class="cellrowborder" valign="top" width="54.14541454145414%" headers="mcps1.2.4.1.2 "><p id="p10930321175918"><a name="p10930321175918"></a><a name="p10930321175918"></a>文字或者文字加图片（图片显示大小固定为 24vp *24vp）</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p2930122145916"><a name="p2930122145916"></a><a name="p2930122145916"></a>可选</p>
</td>
</tr>
<tr id="row1893014213595"><td class="cellrowborder" valign="top" width="12.521252125212524%" headers="mcps1.2.4.1.1 "><p id="p1893072116591"><a name="p1893072116591"></a><a name="p1893072116591"></a>右边区域</p>
</td>
<td class="cellrowborder" valign="top" width="54.14541454145414%" headers="mcps1.2.4.1.2 "><p id="p39301421145912"><a name="p39301421145912"></a><a name="p39301421145912"></a>图片（图片显示大小固定为 24vp *24vp）</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p209302217599"><a name="p209302217599"></a><a name="p209302217599"></a>可选</p>
</td>
</tr>
</tbody>
</table>

示例图：

![](figures/reversal-component.png)

对应样例：

```
{
      "gravity": "default",
      "heightType": "default",
      "name": "电源",
      "span": 1,
      "command": [
        {
          "characteristic": "on",
          "reversal": [
            {
              "disableIcon": "/ic_power_nor.png",
              "icon": "/ic_on.png",
              "disableIconNight": "/ic_power_nor_dark.png",
              "iconNight": "/ic_on_dark.png",
              "value": 1
            },
            {
              "disable": {
                "name": [
                  "模式",
                  "亮度"
                ]
              },
              "disableIcon": "/ic_power_nor.png",
              "icon": "/ic_off.png",
              "disableIconNight": "/ic_power_nor_dark.png",
              "iconNight": "/ic_off_dark.png",
              "value": 0
            }
          ],
          "sid": "switch"
        }
      ],
      "displayItemOne": {
        "subType": "text",
        "textDisplay": {
          "down": {},
          "upLeft": {
            "description": {
              "path": "switch/on",
              "value": [
                {
                  "scope": "0",
                  "target": "已关闭"
                },
                {
                  "scope": "1",
                  "target": "已开启"
                }
              ]
            },
            "type": "dynamicText",
            "value": "${switch/on}"
          },
          "upRight": {}
        }
      },
      "uiType": "REVERSAL"
    }
```

相关的参数，定义如下：

<a name="table131358623513"></a>
<table><thead align="left"><tr id="row1237020653517"><th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.1"><p id="p1937018603510"><a name="p1937018603510"></a><a name="p1937018603510"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.2"><p id="p17370106183510"><a name="p17370106183510"></a><a name="p17370106183510"></a>可选/必选</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.3"><p id="p5370365350"><a name="p5370365350"></a><a name="p5370365350"></a>字段类型</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.4"><p id="p203701669354"><a name="p203701669354"></a><a name="p203701669354"></a>字段描述</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.5"><p id="p143701168353"><a name="p143701168353"></a><a name="p143701168353"></a>备注</p>
</th>
</tr>
</thead>
<tbody><tr id="row53704673512"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p1737096173515"><a name="p1737096173515"></a><a name="p1737096173515"></a>name</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p537026103511"><a name="p537026103511"></a><a name="p537026103511"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p173708618350"><a name="p173708618350"></a><a name="p173708618350"></a>String (1-128)</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p1137013673520"><a name="p1137013673520"></a><a name="p1137013673520"></a>当前控件显示名称</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p173700693519"><a name="p173700693519"></a><a name="p173700693519"></a>例如：“Battery”。</p>
</td>
</tr>
<tr id="row2037096133514"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p037012663516"><a name="p037012663516"></a><a name="p037012663516"></a>span</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p10370186143515"><a name="p10370186143515"></a><a name="p10370186143515"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p10370186193514"><a name="p10370186193514"></a><a name="p10370186193514"></a>float</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p113701769353"><a name="p113701769353"></a><a name="p113701769353"></a>跨度</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p183711867354"><a name="p183711867354"></a><a name="p183711867354"></a>根据手机设置控件的宽度占比，为1表示占满普通手机的宽。0.5表示占普通手机一半的宽。</p>
</td>
</tr>
<tr id="row237116183511"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p163714612352"><a name="p163714612352"></a><a name="p163714612352"></a>uiType</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p83716618359"><a name="p83716618359"></a><a name="p83716618359"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p1237186163510"><a name="p1237186163510"></a><a name="p1237186163510"></a>String(1-128)</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p133714613357"><a name="p133714613357"></a><a name="p133714613357"></a>控件风格</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p1037118633517"><a name="p1037118633517"></a><a name="p1037118633517"></a>控件风格为：“DISPLAY” ，“REVERSAL”,“INCREASE_DECREASE”，“ENUM” ，“MULTIFUNCTION”。</p>
</td>
</tr>
<tr id="row1937166103520"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p1337114612352"><a name="p1337114612352"></a><a name="p1337114612352"></a>tag</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p18371116103514"><a name="p18371116103514"></a><a name="p18371116103514"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p1337118614359"><a name="p1337118614359"></a><a name="p1337118614359"></a>String(1-128)</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p437116610357"><a name="p437116610357"></a><a name="p437116610357"></a>标记</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p203711168353"><a name="p203711168353"></a><a name="p203711168353"></a>扩展字段，用作标记特殊控件处理。</p>
</td>
</tr>
<tr id="row23711367355"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p1437117623516"><a name="p1437117623516"></a><a name="p1437117623516"></a>heightType</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p163711867358"><a name="p163711867358"></a><a name="p163711867358"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p5371268357"><a name="p5371268357"></a><a name="p5371268357"></a>String(1-128)</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p637114611359"><a name="p637114611359"></a><a name="p637114611359"></a>高度类型</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p23711643518"><a name="p23711643518"></a><a name="p23711643518"></a>高度类型为：“default”，“low”；默认为“default”。</p>
</td>
</tr>
<tr id="row13716643520"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p1371106103512"><a name="p1371106103512"></a><a name="p1371106103512"></a>displayItemOne</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p1637116603520"><a name="p1637116603520"></a><a name="p1637116603520"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p103711363350"><a name="p103711363350"></a><a name="p103711363350"></a>DisplayItem</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p2371186133517"><a name="p2371186133517"></a><a name="p2371186133517"></a>通用展示子视图</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p337276163518"><a name="p337276163518"></a><a name="p337276163518"></a>排第一个的展示视图</p>
</td>
</tr>
<tr id="row937219623512"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p137211693519"><a name="p137211693519"></a><a name="p137211693519"></a>displayItemTwo</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p037226143517"><a name="p037226143517"></a><a name="p037226143517"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p137211614353"><a name="p137211614353"></a><a name="p137211614353"></a>DisplayItem</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p9372186113519"><a name="p9372186113519"></a><a name="p9372186113519"></a>通用展示子视图</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p1737210653520"><a name="p1737210653520"></a><a name="p1737210653520"></a>可选，用于一排显示3个的情况，前俩个显示通用视图，第3个为反转开关。</p>
</td>
</tr>
<tr id="row237246103518"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p3372186113520"><a name="p3372186113520"></a><a name="p3372186113520"></a>command</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p13721360359"><a name="p13721360359"></a><a name="p13721360359"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p15372469353"><a name="p15372469353"></a><a name="p15372469353"></a>ReversalCommand[]</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p537219611359"><a name="p537219611359"></a><a name="p537219611359"></a>控件对应的动作数组</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p1737296133510"><a name="p1737296133510"></a><a name="p1737296133510"></a>-</p>
</td>
</tr>
<tr id="row20372196143519"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p537214613352"><a name="p537214613352"></a><a name="p537214613352"></a>gravity</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p637266163511"><a name="p637266163511"></a><a name="p637266163511"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p83728619358"><a name="p83728619358"></a><a name="p83728619358"></a>String(1-128)</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p143736617351"><a name="p143736617351"></a><a name="p143736617351"></a>子视图位置样式</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p837319610355"><a name="p837319610355"></a><a name="p837319610355"></a>样式分为：”default”,” center”，“centerDivider”。默认为“default”，位置样式为俩边靠，无分隔线。” center”为等分居中，” centerDivider”为等分居中且带分隔线。</p>
</td>
</tr>
</tbody>
</table>

ReversalCommand

<a name="table12164166103516"></a>
<table><thead align="left"><tr id="row13736617355"><th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.1"><p id="p837316633511"><a name="p837316633511"></a><a name="p837316633511"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.2"><p id="p19373116153515"><a name="p19373116153515"></a><a name="p19373116153515"></a>可选/必选</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.3"><p id="p637313614352"><a name="p637313614352"></a><a name="p637313614352"></a>字段类型</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.4"><p id="p1637386183514"><a name="p1637386183514"></a><a name="p1637386183514"></a>字段描述</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.5"><p id="p17373661357"><a name="p17373661357"></a><a name="p17373661357"></a>备注</p>
</th>
</tr>
</thead>
<tbody><tr id="row937311633517"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p1437313611352"><a name="p1437313611352"></a><a name="p1437313611352"></a>sid</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p113730653518"><a name="p113730653518"></a><a name="p113730653518"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p83732673519"><a name="p83732673519"></a><a name="p83732673519"></a>String (1-32)</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p18374365357"><a name="p18374365357"></a><a name="p18374365357"></a>命令对应的服务</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p18374463359"><a name="p18374463359"></a><a name="p18374463359"></a>例如：“switch”。</p>
</td>
</tr>
<tr id="row537486163513"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p1037414673519"><a name="p1037414673519"></a><a name="p1037414673519"></a>characteristic</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p183741767357"><a name="p183741767357"></a><a name="p183741767357"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p4374167359"><a name="p4374167359"></a><a name="p4374167359"></a>String (1-32)</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p1837446193515"><a name="p1837446193515"></a><a name="p1837446193515"></a>命令对应的属性</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p193744613512"><a name="p193744613512"></a><a name="p193744613512"></a>例如：“on”。</p>
</td>
</tr>
<tr id="row1037410643519"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p2037436123511"><a name="p2037436123511"></a><a name="p2037436123511"></a>reversal</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p237426133511"><a name="p237426133511"></a><a name="p237426133511"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p737418613358"><a name="p737418613358"></a><a name="p737418613358"></a>Reversal[]</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p1537426133510"><a name="p1537426133510"></a><a name="p1537426133510"></a>反转命令属性</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p20374666354"><a name="p20374666354"></a><a name="p20374666354"></a>数组，对应switch/on的不同属性值，控制的时候，可以相互切换。</p>
</td>
</tr>
</tbody>
</table>

Reversal

<a name="table91739614358"></a>
<table><thead align="left"><tr id="row8374126103511"><th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.1"><p id="p123748614359"><a name="p123748614359"></a><a name="p123748614359"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.2"><p id="p93743693514"><a name="p93743693514"></a><a name="p93743693514"></a>可选/必选</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.3"><p id="p1937536153511"><a name="p1937536153511"></a><a name="p1937536153511"></a>字段类型</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.4"><p id="p737510633511"><a name="p737510633511"></a><a name="p737510633511"></a>字段描述</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.5"><p id="p1037512619358"><a name="p1037512619358"></a><a name="p1037512619358"></a>备注</p>
</th>
</tr>
</thead>
<tbody><tr id="row037513619353"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p637566103514"><a name="p637566103514"></a><a name="p637566103514"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p9375361356"><a name="p9375361356"></a><a name="p9375361356"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p16375156123513"><a name="p16375156123513"></a><a name="p16375156123513"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p133753619355"><a name="p133753619355"></a><a name="p133753619355"></a>命令下发对应的属性值</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p1837515614357"><a name="p1837515614357"></a><a name="p1837515614357"></a>表示开关值。</p>
</td>
</tr>
<tr id="row13765683510"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p937620616353"><a name="p937620616353"></a><a name="p937620616353"></a>icon</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p537616183517"><a name="p537616183517"></a><a name="p537616183517"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p437696153514"><a name="p437696153514"></a><a name="p437696153514"></a>String (1-128)</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p13376767358"><a name="p13376767358"></a><a name="p13376767358"></a>命令对应的图像标签</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p1137666123520"><a name="p1137666123520"></a><a name="p1137666123520"></a>命令对应的图标url。</p>
</td>
</tr>
<tr id="row153767614359"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p73762062356"><a name="p73762062356"></a><a name="p73762062356"></a>disableIcon</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p1537614613359"><a name="p1537614613359"></a><a name="p1537614613359"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p9376165351"><a name="p9376165351"></a><a name="p9376165351"></a>String (1-128)</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p437615623514"><a name="p437615623514"></a><a name="p437615623514"></a>不可用图标url</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p53761965350"><a name="p53761965350"></a><a name="p53761965350"></a>不可用图标url。</p>
</td>
</tr>
<tr id="row103778618356"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p53771867358"><a name="p53771867358"></a><a name="p53771867358"></a>disable</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p53779611356"><a name="p53779611356"></a><a name="p53779611356"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p237719663512"><a name="p237719663512"></a><a name="p237719663512"></a>String[]</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p1837719633519"><a name="p1837719633519"></a><a name="p1837719633519"></a>命令触发后禁用的标签数组</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p63772613515"><a name="p63772613515"></a><a name="p63772613515"></a>例如：["亮度"]，例如：台灯关闭的时候，禁用亮度调节。</p>
</td>
</tr>
<tr id="row2031720356445"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p18318133520449"><a name="p18318133520449"></a><a name="p18318133520449"></a>dialogList</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p1831812358444"><a name="p1831812358444"></a><a name="p1831812358444"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p6318183524419"><a name="p6318183524419"></a><a name="p6318183524419"></a>String[]</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p123184355442"><a name="p123184355442"></a><a name="p123184355442"></a>命令触发后会弹出的对话框列表</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p1431843512445"><a name="p1431843512445"></a><a name="p1431843512445"></a>dialogList里面的值对应dialog的id值。</p>
</td>
</tr>
</tbody>
</table>

Property

<a name="table1618818653512"></a>
<table><thead align="left"><tr id="row11377196113511"><th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.1"><p id="p73778612358"><a name="p73778612358"></a><a name="p73778612358"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.2"><p id="p637715633511"><a name="p637715633511"></a><a name="p637715633511"></a>可选/必选</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.3"><p id="p5377566352"><a name="p5377566352"></a><a name="p5377566352"></a>字段类型</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.4"><p id="p1137726173517"><a name="p1137726173517"></a><a name="p1137726173517"></a>字段描述</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.5"><p id="p437715615357"><a name="p437715615357"></a><a name="p437715615357"></a>备注</p>
</th>
</tr>
</thead>
<tbody><tr id="row837711618352"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p16377206183516"><a name="p16377206183516"></a><a name="p16377206183516"></a>path</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p4377186193511"><a name="p4377186193511"></a><a name="p4377186193511"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p837726153515"><a name="p837726153515"></a><a name="p837726153515"></a>String  (1-32)</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p123779617354"><a name="p123779617354"></a><a name="p123779617354"></a>属性路径</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p53776613351"><a name="p53776613351"></a><a name="p53776613351"></a>例如："switch/on"，其中switch表示服务，on表示属性。</p>
</td>
</tr>
<tr id="row10377566356"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p12377136173519"><a name="p12377136173519"></a><a name="p12377136173519"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p537817683512"><a name="p537817683512"></a><a name="p537817683512"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p1937817663519"><a name="p1937817663519"></a><a name="p1937817663519"></a>String  (1-32)</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p1937810653515"><a name="p1937810653515"></a><a name="p1937810653515"></a>属性值</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p937814613516"><a name="p937814613516"></a><a name="p937814613516"></a>例如：1，表示path的值为1。</p>
</td>
</tr>
</tbody>
</table>

## Increase\_Decrease控件<a name="section1092141210525"></a>

Increase\_Decrease控件用于增加或减少数据，支持显示三个区域内容。左边区域内容是减少按钮，右边区域内容是增加按钮，中间区域内容用于显示操作的数据，点击增加或减少按钮可以改变中间的数据。

示例图：

![](figures/increase-decrease-component.png)

对应样例：

```
{
  "name": "湿度",
  "span": 1,
  "gravity": "default",
  "uiType": "INCREASE_DECREASE",
  "heightType": "low",
  "displayItem": {
    "subType": "text",
    "textDisplay": {
      "down": {},
      "upLeft": {
        "type": "normalText",
        "value": "目标湿度"
      },
      "upRight": {}
    }
  },
  "command": [
    {
      "sid": "temperature",
      "characteristic": "temperature",
      "max": 36,
      "min": 17,
      "ratio": 1,
      "step": 1,
      "defaultValue": 26,
      "disableIconDecrease": "",
      "iconDecrease": "",
      "disableIconIncrease": "",
      "iconIncrease": ""
    }
  ]
}
```

相关的参数，定义如下：

<a name="table3913172264010"></a>
<table><thead align="left"><tr id="row191491023174017"><th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.1"><p id="p31501423154016"><a name="p31501423154016"></a><a name="p31501423154016"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.2"><p id="p715082374019"><a name="p715082374019"></a><a name="p715082374019"></a>可选/必选</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.3"><p id="p8150172313407"><a name="p8150172313407"></a><a name="p8150172313407"></a>字段类型</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.4"><p id="p2150223174013"><a name="p2150223174013"></a><a name="p2150223174013"></a>字段描述</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.5"><p id="p151501523114014"><a name="p151501523114014"></a><a name="p151501523114014"></a>备注</p>
</th>
</tr>
</thead>
<tbody><tr id="row315062344011"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p01503236400"><a name="p01503236400"></a><a name="p01503236400"></a>name</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p121501023194016"><a name="p121501023194016"></a><a name="p121501023194016"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p3150162374020"><a name="p3150162374020"></a><a name="p3150162374020"></a>String (1-128)</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p6150182313408"><a name="p6150182313408"></a><a name="p6150182313408"></a>当前控件显示名称</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p11150523114013"><a name="p11150523114013"></a><a name="p11150523114013"></a>例如：“湿度”。</p>
</td>
</tr>
<tr id="row7150192317401"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p1915012312409"><a name="p1915012312409"></a><a name="p1915012312409"></a>span</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p1215011233406"><a name="p1215011233406"></a><a name="p1215011233406"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p16150423144018"><a name="p16150423144018"></a><a name="p16150423144018"></a>float</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p11501723154014"><a name="p11501723154014"></a><a name="p11501723154014"></a>跨度</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p3150182314015"><a name="p3150182314015"></a><a name="p3150182314015"></a>根据手机设置控件的宽度占比，为1表示占满普通手机的宽。</p>
</td>
</tr>
<tr id="row81501023134010"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p6150723104013"><a name="p6150723104013"></a><a name="p6150723104013"></a>uiType</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p16150623154015"><a name="p16150623154015"></a><a name="p16150623154015"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p215032320403"><a name="p215032320403"></a><a name="p215032320403"></a>String(1-128)</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p15150142312405"><a name="p15150142312405"></a><a name="p15150142312405"></a>控件风格</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p1315072374011"><a name="p1315072374011"></a><a name="p1315072374011"></a>控件风格为：“DISPLAY” ，“REVERSAL”,“INCREASE_DECREASE”，“ENUM” ，“MULTIFUNCTION”。</p>
</td>
</tr>
<tr id="row4150182374015"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p91511523114020"><a name="p91511523114020"></a><a name="p91511523114020"></a>tag</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p10151923184018"><a name="p10151923184018"></a><a name="p10151923184018"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p151511323104018"><a name="p151511323104018"></a><a name="p151511323104018"></a>String(1-128)</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p141517232400"><a name="p141517232400"></a><a name="p141517232400"></a>标记</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p10151023184012"><a name="p10151023184012"></a><a name="p10151023184012"></a>扩展字段，用作标记特殊控件处理。</p>
</td>
</tr>
<tr id="row615115235404"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p8151162344017"><a name="p8151162344017"></a><a name="p8151162344017"></a>heightType</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p8151423174014"><a name="p8151423174014"></a><a name="p8151423174014"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p61511723114016"><a name="p61511723114016"></a><a name="p61511723114016"></a>String(1-128)</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p1115114237405"><a name="p1115114237405"></a><a name="p1115114237405"></a>高度类型</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p17151162314015"><a name="p17151162314015"></a><a name="p17151162314015"></a>“default”，“low”；默认为“default”。</p>
</td>
</tr>
<tr id="row715182354013"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p1151172384015"><a name="p1151172384015"></a><a name="p1151172384015"></a>displayItem</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p13151202314403"><a name="p13151202314403"></a><a name="p13151202314403"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p2151923154010"><a name="p2151923154010"></a><a name="p2151923154010"></a>DisplayItem</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p31511723154013"><a name="p31511723154013"></a><a name="p31511723154013"></a>通用展示子视图</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p2151102364012"><a name="p2151102364012"></a><a name="p2151102364012"></a>中间的展示视图。</p>
</td>
</tr>
<tr id="row215192354019"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p19151172354013"><a name="p19151172354013"></a><a name="p19151172354013"></a>command</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p1215192312401"><a name="p1215192312401"></a><a name="p1215192312401"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p131513239409"><a name="p131513239409"></a><a name="p131513239409"></a>IncreaseDecreaseCommand[]</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p8151182354016"><a name="p8151182354016"></a><a name="p8151182354016"></a>控件对应的动作数组</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p1215272364015"><a name="p1215272364015"></a><a name="p1215272364015"></a>-</p>
</td>
</tr>
<tr id="row71521223124014"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p51527231406"><a name="p51527231406"></a><a name="p51527231406"></a>gravity</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p7152623174018"><a name="p7152623174018"></a><a name="p7152623174018"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p101522023164019"><a name="p101522023164019"></a><a name="p101522023164019"></a>String(1-128)</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p1815252319405"><a name="p1815252319405"></a><a name="p1815252319405"></a>子视图位置样式</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p215242316401"><a name="p215242316401"></a><a name="p215242316401"></a>样式分为：”default”,” center”，“centerDivider”。默认为“default”，位置样式为俩边靠，无分隔线。” center”为等分居中，” centerDivider”为等分居中且带分隔线。</p>
</td>
</tr>
</tbody>
</table>

IncreaseDecreaseCommand

<a name="table8936142216409"></a>
<table><thead align="left"><tr id="row0152523194014"><th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.1"><p id="p131529232400"><a name="p131529232400"></a><a name="p131529232400"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.2"><p id="p161521223104017"><a name="p161521223104017"></a><a name="p161521223104017"></a>可选/必选</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.3"><p id="p2152202313409"><a name="p2152202313409"></a><a name="p2152202313409"></a>字段类型</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.4"><p id="p11152123104018"><a name="p11152123104018"></a><a name="p11152123104018"></a>字段描述</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.5"><p id="p13152112320402"><a name="p13152112320402"></a><a name="p13152112320402"></a>备注</p>
</th>
</tr>
</thead>
<tbody><tr id="row15152023124013"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p41521123194016"><a name="p41521123194016"></a><a name="p41521123194016"></a>sid</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p1815213238402"><a name="p1815213238402"></a><a name="p1815213238402"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p15152152316409"><a name="p15152152316409"></a><a name="p15152152316409"></a>String  (1-32)</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p8152192316401"><a name="p8152192316401"></a><a name="p8152192316401"></a>命令对应的服务</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p01521523154015"><a name="p01521523154015"></a><a name="p01521523154015"></a>例如：“humidity”。</p>
</td>
</tr>
<tr id="row191521623184012"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p1715214236408"><a name="p1715214236408"></a><a name="p1715214236408"></a>characteristic</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p18152623174018"><a name="p18152623174018"></a><a name="p18152623174018"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p10152202344019"><a name="p10152202344019"></a><a name="p10152202344019"></a>String  (1-32)</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p715316235402"><a name="p715316235402"></a><a name="p715316235402"></a>命令对应的属性</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p13153182324013"><a name="p13153182324013"></a><a name="p13153182324013"></a>例如：“humidity”。</p>
</td>
</tr>
<tr id="row111538231404"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p1615319237407"><a name="p1615319237407"></a><a name="p1615319237407"></a>max</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p10153523154015"><a name="p10153523154015"></a><a name="p10153523154015"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p1415382314012"><a name="p1415382314012"></a><a name="p1415382314012"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p115392324012"><a name="p115392324012"></a><a name="p115392324012"></a>范围最大值</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p191531623164018"><a name="p191531623164018"></a><a name="p191531623164018"></a>例如：湿度最大值为100。</p>
</td>
</tr>
<tr id="row31531823154019"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p1415314236403"><a name="p1415314236403"></a><a name="p1415314236403"></a>min</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p191531023184010"><a name="p191531023184010"></a><a name="p191531023184010"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p8153182344019"><a name="p8153182344019"></a><a name="p8153182344019"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p115317236407"><a name="p115317236407"></a><a name="p115317236407"></a>范围最小值</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p31531523174012"><a name="p31531523174012"></a><a name="p31531523174012"></a>例如：湿度最小值为0。</p>
</td>
</tr>
<tr id="row9153182311407"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p2153132319405"><a name="p2153132319405"></a><a name="p2153132319405"></a>ratio</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p9153132318409"><a name="p9153132318409"></a><a name="p9153132318409"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p1153182312409"><a name="p1153182312409"></a><a name="p1153182312409"></a>float</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p6153172313401"><a name="p6153172313401"></a><a name="p6153172313401"></a>补偿因子</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p12153132374011"><a name="p12153132374011"></a><a name="p12153132374011"></a>例如：检测到的湿度为0.5，实际显示的湿度为50，那么补偿因子为0.01，再选中页面数值后，控制的过程中，要再次除以补偿因子，进行命令下发。</p>
</td>
</tr>
<tr id="row1415382316401"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p515372310409"><a name="p515372310409"></a><a name="p515372310409"></a>step</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p10153102334010"><a name="p10153102334010"></a><a name="p10153102334010"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p1015342317401"><a name="p1015342317401"></a><a name="p1015342317401"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p3154162394011"><a name="p3154162394011"></a><a name="p3154162394011"></a>步进值</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p1615472324015"><a name="p1615472324015"></a><a name="p1615472324015"></a>每次变化的值。</p>
</td>
</tr>
<tr id="row15154182314016"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p10154102319403"><a name="p10154102319403"></a><a name="p10154102319403"></a>iconDecrease</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p1415482344010"><a name="p1415482344010"></a><a name="p1415482344010"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p16154192324011"><a name="p16154192324011"></a><a name="p16154192324011"></a>String</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p1915462313401"><a name="p1915462313401"></a><a name="p1915462313401"></a>减少的图标</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p10154152311402"><a name="p10154152311402"></a><a name="p10154152311402"></a>减少的图标。</p>
</td>
</tr>
<tr id="row13154223114019"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p9154123114011"><a name="p9154123114011"></a><a name="p9154123114011"></a>disableIconDecrease</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p1315413238401"><a name="p1315413238401"></a><a name="p1315413238401"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p1154192316404"><a name="p1154192316404"></a><a name="p1154192316404"></a>String</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p615411235406"><a name="p615411235406"></a><a name="p615411235406"></a>减少的不可用图标</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p1815402310408"><a name="p1815402310408"></a><a name="p1815402310408"></a>减少的不可用图标。</p>
</td>
</tr>
<tr id="row715472316408"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p1115482314401"><a name="p1115482314401"></a><a name="p1115482314401"></a>iconIncrease</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p9154132324014"><a name="p9154132324014"></a><a name="p9154132324014"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p315413239407"><a name="p315413239407"></a><a name="p315413239407"></a>String</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p1315410232401"><a name="p1315410232401"></a><a name="p1315410232401"></a>增加的图标</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p1115422304013"><a name="p1115422304013"></a><a name="p1115422304013"></a>增加的图标。</p>
</td>
</tr>
<tr id="row1615413239402"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p115442318404"><a name="p115442318404"></a><a name="p115442318404"></a>disableIconIncrease</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p9154132311403"><a name="p9154132311403"></a><a name="p9154132311403"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p15154192314011"><a name="p15154192314011"></a><a name="p15154192314011"></a>String</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p1115442394011"><a name="p1115442394011"></a><a name="p1115442394011"></a>增加的不可用图标</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p1155142314408"><a name="p1155142314408"></a><a name="p1155142314408"></a>增加的不可用图标。</p>
</td>
</tr>
<tr id="row1815511238407"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p615512315405"><a name="p615512315405"></a><a name="p615512315405"></a>defaultValue</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p161551123174010"><a name="p161551123174010"></a><a name="p161551123174010"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p7155202310409"><a name="p7155202310409"></a><a name="p7155202310409"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p81551323204018"><a name="p81551323204018"></a><a name="p81551323204018"></a>默认值</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p015572310407"><a name="p015572310407"></a><a name="p015572310407"></a>-</p>
</td>
</tr>
<tr id="row17155102318401"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p61554233400"><a name="p61554233400"></a><a name="p61554233400"></a>disable</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p115552319400"><a name="p115552319400"></a><a name="p115552319400"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p14155122310405"><a name="p14155122310405"></a><a name="p14155122310405"></a>String[]</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p13155182311405"><a name="p13155182311405"></a><a name="p13155182311405"></a>命令触发后禁用的标签数组</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p17677174115"><a name="p17677174115"></a><a name="p17677174115"></a>例如：["亮度"]，例如：台灯关闭的时候，禁用亮度调节。</p>
</td>
</tr>
</tbody>
</table>

## Progress控件<a name="section04131030125215"></a>

Progress控件用于控制进度，支持显示两个区域内容，左边区域内容是对当前进度的描述，支持文字，或者文字加图片（图片显示大小为 24vp \*24vp），文字颜色支持自定义，颜色和图片支持根据数据范围来选择。右边的区域用于显示进度条。

示例图：

![](figures/process-component.png)

对应样例：

```
{
      "gravity": "default",
      "heightType": "low",
      "name": "亮度",
      "span": 1,
      "command": [
        {
          "characteristic": "brightness",
          "defaultValue": 100,
          "max" : 255,
          "min": 0,
          "radio" : 1,
          "sid": "brightness"
        }
      ],
      "displayItemLeft": {
        "subType": "text",
        "textDisplay": {
          "down": {
            "color": {
              "path" : "brightness/brightness",
              "value" : [{
                "scope": "-",
                "target": "007DFF"
              }]
            },
            "ratio": "0.392156",
            "type": "dynamicText",
            "value": "${brightness/brightness}%"
          },
          "upLeft": {
            "type": "normalText",
            "value": "亮度"
          },
          "upRight": {}
        }
      },
      "uiType": "PROGRESS"
    }
```

相关的参数，定义如下：

<a name="table0650132810435"></a>
<table><thead align="left"><tr id="row281042884320"><th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.1"><p id="p5810628174312"><a name="p5810628174312"></a><a name="p5810628174312"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.2"><p id="p18811172818437"><a name="p18811172818437"></a><a name="p18811172818437"></a>可选/必选</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.3"><p id="p8811162818430"><a name="p8811162818430"></a><a name="p8811162818430"></a>字段类型</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.4"><p id="p1281115285433"><a name="p1281115285433"></a><a name="p1281115285433"></a>字段描述</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.5"><p id="p0811122874311"><a name="p0811122874311"></a><a name="p0811122874311"></a>备注</p>
</th>
</tr>
</thead>
<tbody><tr id="row68111928134314"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p481152834313"><a name="p481152834313"></a><a name="p481152834313"></a>name</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p9811182834314"><a name="p9811182834314"></a><a name="p9811182834314"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p14811182813435"><a name="p14811182813435"></a><a name="p14811182813435"></a>String (1-128)</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p168111428104317"><a name="p168111428104317"></a><a name="p168111428104317"></a>当前控件显示名称</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p11811102864313"><a name="p11811102864313"></a><a name="p11811102864313"></a>例如：“亮度”。</p>
</td>
</tr>
<tr id="row158111128174310"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p1881112285431"><a name="p1881112285431"></a><a name="p1881112285431"></a>span</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p6811102812432"><a name="p6811102812432"></a><a name="p6811102812432"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p2811192819434"><a name="p2811192819434"></a><a name="p2811192819434"></a>float</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p6811122811439"><a name="p6811122811439"></a><a name="p6811122811439"></a>跨度</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p98111828164313"><a name="p98111828164313"></a><a name="p98111828164313"></a>根据手机设置控件的宽度占比，为1表示占满普通手机的宽。</p>
</td>
</tr>
<tr id="row4811228144311"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p18116289436"><a name="p18116289436"></a><a name="p18116289436"></a>uiType</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p14812102884316"><a name="p14812102884316"></a><a name="p14812102884316"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p5812228114317"><a name="p5812228114317"></a><a name="p5812228114317"></a>String(1-128)</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p10812182804316"><a name="p10812182804316"></a><a name="p10812182804316"></a>控件风格</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p1281292813432"><a name="p1281292813432"></a><a name="p1281292813432"></a>控件风格为：“DISPLAY” ，“REVERSAL”,“INCREASE_DECREASE”，“ENUM” ，“MULTIFUNCTION”。</p>
</td>
</tr>
<tr id="row18812132894313"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p1381342815437"><a name="p1381342815437"></a><a name="p1381342815437"></a>heightType</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p58131288435"><a name="p58131288435"></a><a name="p58131288435"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p381322854314"><a name="p381322854314"></a><a name="p381322854314"></a>String(1-128)</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p5813142816432"><a name="p5813142816432"></a><a name="p5813142816432"></a>高度类型</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p187064183586"><a name="p187064183586"></a><a name="p187064183586"></a>高度类型为：“default”，“low”；默认为“default”</p>
</td>
</tr>
<tr id="row481382824317"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p7813102884311"><a name="p7813102884311"></a><a name="p7813102884311"></a>displayItem</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p4814102818434"><a name="p4814102818434"></a><a name="p4814102818434"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p18149285438"><a name="p18149285438"></a><a name="p18149285438"></a>DisplayItem</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p1081415281439"><a name="p1081415281439"></a><a name="p1081415281439"></a>通用展示子视图</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p281420289437"><a name="p281420289437"></a><a name="p281420289437"></a>中间的展示视图。</p>
</td>
</tr>
<tr id="row58149280433"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p10814928164318"><a name="p10814928164318"></a><a name="p10814928164318"></a>command</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p1881432813435"><a name="p1881432813435"></a><a name="p1881432813435"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p681411282431"><a name="p681411282431"></a><a name="p681411282431"></a>ProgressCommand[]</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p7814102818434"><a name="p7814102818434"></a><a name="p7814102818434"></a>控件对应的动作数组</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p181412874319"><a name="p181412874319"></a><a name="p181412874319"></a>-</p>
</td>
</tr>
</tbody>
</table>

ProgressCommand

<a name="table06954515447"></a>
<table><thead align="left"><tr id="row469565184416"><th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.1"><p id="p14695105114449"><a name="p14695105114449"></a><a name="p14695105114449"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.2"><p id="p069585119442"><a name="p069585119442"></a><a name="p069585119442"></a>可选/必选</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.3"><p id="p9696451164419"><a name="p9696451164419"></a><a name="p9696451164419"></a>字段类型</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.4"><p id="p46961151184418"><a name="p46961151184418"></a><a name="p46961151184418"></a>字段描述</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.5"><p id="p186961751174415"><a name="p186961751174415"></a><a name="p186961751174415"></a>备注</p>
</th>
</tr>
</thead>
<tbody><tr id="row18696165117443"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p146964514441"><a name="p146964514441"></a><a name="p146964514441"></a>sid</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p2696115111447"><a name="p2696115111447"></a><a name="p2696115111447"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p146962051184412"><a name="p146962051184412"></a><a name="p146962051184412"></a>String  (1-32)</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p176971351114415"><a name="p176971351114415"></a><a name="p176971351114415"></a>命令对应的服务</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p136971351144417"><a name="p136971351144417"></a><a name="p136971351144417"></a>例如：“brightness”。</p>
</td>
</tr>
<tr id="row196971518441"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p1669716512443"><a name="p1669716512443"></a><a name="p1669716512443"></a>characteristic</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p5697651154418"><a name="p5697651154418"></a><a name="p5697651154418"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p1169711514441"><a name="p1169711514441"></a><a name="p1169711514441"></a>String  (1-32)</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p176971513442"><a name="p176971513442"></a><a name="p176971513442"></a>命令对应的属性</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p169765117443"><a name="p169765117443"></a><a name="p169765117443"></a>例如：“brightness”。</p>
</td>
</tr>
<tr id="row6697125114418"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p1069725194412"><a name="p1069725194412"></a><a name="p1069725194412"></a>max</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p1769745114447"><a name="p1769745114447"></a><a name="p1769745114447"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p56989516440"><a name="p56989516440"></a><a name="p56989516440"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p26982051144414"><a name="p26982051144414"></a><a name="p26982051144414"></a>范围最大值</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p6698125113449"><a name="p6698125113449"></a><a name="p6698125113449"></a>例如：亮度最大值为100。</p>
</td>
</tr>
<tr id="row169845174414"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p3698125154411"><a name="p3698125154411"></a><a name="p3698125154411"></a>min</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p969875118444"><a name="p969875118444"></a><a name="p969875118444"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p169825111448"><a name="p169825111448"></a><a name="p169825111448"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p116981851134420"><a name="p116981851134420"></a><a name="p116981851134420"></a>范围最小值</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p56981551104410"><a name="p56981551104410"></a><a name="p56981551104410"></a>例如：亮度最小值为0。</p>
</td>
</tr>
<tr id="row9698551134418"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p14699105174410"><a name="p14699105174410"></a><a name="p14699105174410"></a>ratio</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p15699185124410"><a name="p15699185124410"></a><a name="p15699185124410"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p46996518446"><a name="p46996518446"></a><a name="p46996518446"></a>float</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p12699135111446"><a name="p12699135111446"></a><a name="p12699135111446"></a>补偿因子</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p1012514336013"><a name="p1012514336013"></a><a name="p1012514336013"></a>例如：台灯的亮度是0.5，实际页面显示为百分数，显示内容为50%，那么补偿因子为0.01，再选中页面数值后，控制的过程中，要再次除以补偿因子，进行命令下发。</p>
</td>
</tr>
<tr id="row97009514441"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p270013511443"><a name="p270013511443"></a><a name="p270013511443"></a>step</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p14700205184411"><a name="p14700205184411"></a><a name="p14700205184411"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p4700195120442"><a name="p4700195120442"></a><a name="p4700195120442"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p370017518444"><a name="p370017518444"></a><a name="p370017518444"></a>步进值</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p1270035144420"><a name="p1270035144420"></a><a name="p1270035144420"></a>每次变化的值。</p>
</td>
</tr>
<tr id="row1370317511443"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p19703751164413"><a name="p19703751164413"></a><a name="p19703751164413"></a>defaultValue</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p18703165116446"><a name="p18703165116446"></a><a name="p18703165116446"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p16703195134419"><a name="p16703195134419"></a><a name="p16703195134419"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p127031351184414"><a name="p127031351184414"></a><a name="p127031351184414"></a>默认值</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p1370385134419"><a name="p1370385134419"></a><a name="p1370385134419"></a>-</p>
</td>
</tr>
<tr id="row6703155119446"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p16703145119442"><a name="p16703145119442"></a><a name="p16703145119442"></a>disable</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p0703135174410"><a name="p0703135174410"></a><a name="p0703135174410"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p770313511447"><a name="p770313511447"></a><a name="p770313511447"></a>String[]</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p17704115115443"><a name="p17704115115443"></a><a name="p17704115115443"></a>命令触发后禁用的标签数组</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p970414517445"><a name="p970414517445"></a><a name="p970414517445"></a>例如：["亮度"]，例如：台灯关闭的时候，禁用亮度调节。</p>
</td>
</tr>
</tbody>
</table>

## Multifunction控件<a name="section1114919529527"></a>

Multifunction控件用于功能控制，支持显示两个或三个区域内容。左边的区域内容用于描述当前状态，中间的区域内容可不显示或用于计时，右边的区域内容用于显示操作按钮。示例图：

![](figures/multifunction-component.png)

对应样例：

```
{
      "name": "制作",
      "span": 1,
      "uiType": "MULTIFUNCTION",
      "displayItemOne": {
        "subType":"text",
        "textDisplay": {
          "down": {},
          "upLeft": {
            "description": {
              "path": "workingStatus/status",
              "value": [
                {
                  "scope": "1",
                  "target": "待机中"
                },
                {
                  "scope": "2",
                  "target": "准备中"
                },
                {
                  "scope": "3",
                  "target": "制作中"
                },
                {
                  "scope": "4",
                  "target": "制作完成"
                },
                {
                  "scope": "5",
                  "target": "预约中"
                }
              ]
            },
            "type": "dynamicText",
            "value": "${workingStatus/status}"
          },
          "upRight": {}
        }
      },
      "displayItemTwo": {
        "subType":"text",
        "textDisplay":{
          "down":{
            "type":"normaltext",
            "value":"剩余时间"
          },
          "upLeft":{
            "type":"dynamicText",
            "value":"${remainingTime/time}"
          },
          "upRight":{


          }
        }
      },
      "multifunctionInfo": {
        "path": "workingStatus/action",
        "value": [
          {
            "scope": "1",
            "commandOne": [
              {
                "characteristic": "action",
                "disableIcon": "/ic_prepare.png",
                "icon": "/ic_prepare.png",
                "disableIconNight": "/ic_prepare.png",
                "iconNight": "/ic_prepare.png",
                "value": 3,
                "sid": "workingStatus"
              }
            ]
          },
          {
            "scope": "2",
            "commandOne": [
              {
                "characteristic": "action",
                "disableIcon": "/ic_prepare.png",
                "icon": "/ic_prepare.png",
                "disableIconNight": "/ic_prepare.png",
                "iconNight": "/ic_prepare.png",
                "value": 3,
                "sid": "workingStatus"
              }
            ],
            "commandTwo": [
              {
                "characteristic": "action",
                "disableIcon": "/ic_cancel.png",
                "icon": "/ic_cancel.png",
                "disableIconNight": "/ic_cancel.png",
                "iconNight": "/ic_cancel.png",
                "value": 0,
                "sid": "workingStatus"
              }
            ]
          },
          {
            "scope": "3",
            "commandOne": [
              {
                "characteristic": "action",
                "disableIcon": "/ic_cancel.png",
                "icon": "/ic_cancel.png",
                "disableIconNight": "/ic_cancel.png",
                "iconNight": "/ic_cancel.png",
                "value": 0,
                "sid": "workingStatus"
              }
            ]
          },
          {
            "scope": "4",
            "commandOne": [
              {
                "characteristic": "action",
                "disableIcon": "/ic_complete.png",
                "icon": "/ic_complete.png",
                "disableIconNight": "/ic_complete.png",
                "iconNight": "/ic_complete.png",
                "value": 0,
                "sid": "workingStatus"
              }
            ]
          },
          {
            "scope": "5",
            "commandOne": [
              {
                "characteristic": "action",
                "disableIcon": "/ic_cancel.png",
                "icon": "/ic_cancel.png",
                "disableIconNight": "/ic_cancel.png",
                "iconNight": "/ic_cancel.png",
                "value": 0,
                "sid": "workingStatus"
              }
            ]
          }
        ]
      }
    }
```

相关的参数，定义如下：

<a name="table031214513466"></a>
<table><thead align="left"><tr id="row1761755112467"><th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.1"><p id="p2617145118469"><a name="p2617145118469"></a><a name="p2617145118469"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.2"><p id="p186170516468"><a name="p186170516468"></a><a name="p186170516468"></a>可选/必选</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.3"><p id="p76171651134610"><a name="p76171651134610"></a><a name="p76171651134610"></a>字段类型</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.4"><p id="p9617165184612"><a name="p9617165184612"></a><a name="p9617165184612"></a>字段描述</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.5"><p id="p10617115116462"><a name="p10617115116462"></a><a name="p10617115116462"></a>备注</p>
</th>
</tr>
</thead>
<tbody><tr id="row1061718517462"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p11617105120464"><a name="p11617105120464"></a><a name="p11617105120464"></a>name</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p1861735164617"><a name="p1861735164617"></a><a name="p1861735164617"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p1961713511465"><a name="p1961713511465"></a><a name="p1961713511465"></a>String (1-128)</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p1961755194612"><a name="p1961755194612"></a><a name="p1961755194612"></a>当前控件显示名称</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p461785184617"><a name="p461785184617"></a><a name="p461785184617"></a>例如：“Battery”。</p>
</td>
</tr>
<tr id="row12617185116467"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p1061815519469"><a name="p1061815519469"></a><a name="p1061815519469"></a>span</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p361875134619"><a name="p361875134619"></a><a name="p361875134619"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p1561895119462"><a name="p1561895119462"></a><a name="p1561895119462"></a>float</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p661820519460"><a name="p661820519460"></a><a name="p661820519460"></a>跨度</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p136183515469"><a name="p136183515469"></a><a name="p136183515469"></a>根据手机设置控件的宽度占比，为1表示占满普通手机的宽。</p>
</td>
</tr>
<tr id="row361815184620"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p361815513460"><a name="p361815513460"></a><a name="p361815513460"></a>uiType</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p19618195154612"><a name="p19618195154612"></a><a name="p19618195154612"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p176181551104615"><a name="p176181551104615"></a><a name="p176181551104615"></a>String(1-128)</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p9618175113469"><a name="p9618175113469"></a><a name="p9618175113469"></a>控件风格</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p12618115124615"><a name="p12618115124615"></a><a name="p12618115124615"></a>控件风格为：“DISPLAY” ，“REVERSAL”,“INCREASE_DECREASE”，“ENUM” ，“MULTIFUNCTION”。</p>
</td>
</tr>
<tr id="row26181751114618"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p1961875113464"><a name="p1961875113464"></a><a name="p1961875113464"></a>heightType</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p136187511464"><a name="p136187511464"></a><a name="p136187511464"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p19618151134614"><a name="p19618151134614"></a><a name="p19618151134614"></a>String(1-128)</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p1161815519463"><a name="p1161815519463"></a><a name="p1161815519463"></a>高度类型</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p1651618408217"><a name="p1651618408217"></a><a name="p1651618408217"></a>高度类型为：“default”，“low”；默认为“default”。</p>
</td>
</tr>
<tr id="row9618145194613"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p16618115174613"><a name="p16618115174613"></a><a name="p16618115174613"></a>displayItemOne</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p661835114466"><a name="p661835114466"></a><a name="p661835114466"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p166181251114619"><a name="p166181251114619"></a><a name="p166181251114619"></a>DisplayItem</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p1561810517466"><a name="p1561810517466"></a><a name="p1561810517466"></a>通用展示子视图</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p136191651164614"><a name="p136191651164614"></a><a name="p136191651164614"></a>排第一个的展示视图。</p>
</td>
</tr>
<tr id="row12619551104614"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p16191151104617"><a name="p16191151104617"></a><a name="p16191151104617"></a>displayItemTwo</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p19619145112468"><a name="p19619145112468"></a><a name="p19619145112468"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p361985134613"><a name="p361985134613"></a><a name="p361985134613"></a>DisplayItem</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p18619145118466"><a name="p18619145118466"></a><a name="p18619145118466"></a>通用展示子视图</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p10619851134614"><a name="p10619851134614"></a><a name="p10619851134614"></a>可选，用于一排显示3个的情况，前俩个显示通用视图，第3个为多功能按钮。</p>
</td>
</tr>
<tr id="row961995117465"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p1561916516464"><a name="p1561916516464"></a><a name="p1561916516464"></a>multifunctionInfo</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p1561975110468"><a name="p1561975110468"></a><a name="p1561975110468"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p6619195144610"><a name="p6619195144610"></a><a name="p6619195144610"></a>DynamicCommandContent</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p1619185113461"><a name="p1619185113461"></a><a name="p1619185113461"></a>多功能按钮</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p186191551144614"><a name="p186191551144614"></a><a name="p186191551144614"></a>-</p>
</td>
</tr>
</tbody>
</table>

DynamicCommandContent

<a name="table193361351154616"></a>
<table><thead align="left"><tr id="row14619551194615"><th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.1"><p id="p1461975124610"><a name="p1461975124610"></a><a name="p1461975124610"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.2"><p id="p8619151204615"><a name="p8619151204615"></a><a name="p8619151204615"></a>可选/必选</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.3"><p id="p17619105113469"><a name="p17619105113469"></a><a name="p17619105113469"></a>字段类型</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.4"><p id="p1061975134611"><a name="p1061975134611"></a><a name="p1061975134611"></a>字段描述</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.5"><p id="p3619165114610"><a name="p3619165114610"></a><a name="p3619165114610"></a>备注</p>
</th>
</tr>
</thead>
<tbody><tr id="row20620125194615"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p13620145154614"><a name="p13620145154614"></a><a name="p13620145154614"></a>path</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p262075154610"><a name="p262075154610"></a><a name="p262075154610"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p262075134611"><a name="p262075134611"></a><a name="p262075134611"></a>String  (1-128)</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p962016516462"><a name="p962016516462"></a><a name="p962016516462"></a>动态内容条件值，可能需要动态获取设备数据填充</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p4620951124613"><a name="p4620951124613"></a><a name="p4620951124613"></a>例如：“workingStatus/status” ，表示当前设备状态。</p>
</td>
</tr>
<tr id="row19620251104615"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p16620451124620"><a name="p16620451124620"></a><a name="p16620451124620"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p8620451134615"><a name="p8620451134615"></a><a name="p8620451134615"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p1762025112466"><a name="p1762025112466"></a><a name="p1762025112466"></a>VariationCommand</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p146201518469"><a name="p146201518469"></a><a name="p146201518469"></a>动态范围值</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p1062005113466"><a name="p1062005113466"></a><a name="p1062005113466"></a>{      "scope": "-50",       "target": "11FCFC"  }。</p>
</td>
</tr>
</tbody>
</table>

VariationCommand

<a name="table143449515460"></a>
<table><thead align="left"><tr id="row15620175114467"><th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.1"><p id="p1262095184611"><a name="p1262095184611"></a><a name="p1262095184611"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.2"><p id="p0620151194611"><a name="p0620151194611"></a><a name="p0620151194611"></a>可选/必选</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.3"><p id="p11620115113460"><a name="p11620115113460"></a><a name="p11620115113460"></a>字段类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.6%" id="mcps1.1.6.1.4"><p id="p17620451124611"><a name="p17620451124611"></a><a name="p17620451124611"></a>字段描述</p>
</th>
<th class="cellrowborder" valign="top" width="30.4%" id="mcps1.1.6.1.5"><p id="p16201251134617"><a name="p16201251134617"></a><a name="p16201251134617"></a>备注</p>
</th>
</tr>
</thead>
<tbody><tr id="row15621165116469"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p3621185118464"><a name="p3621185118464"></a><a name="p3621185118464"></a>scope</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p36217518466"><a name="p36217518466"></a><a name="p36217518466"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p1162145184613"><a name="p1162145184613"></a><a name="p1162145184613"></a>String  (1-128)</p>
</td>
<td class="cellrowborder" valign="top" width="9.6%" headers="mcps1.1.6.1.4 "><p id="p8621251124614"><a name="p8621251124614"></a><a name="p8621251124614"></a>条件范围</p>
</td>
<td class="cellrowborder" valign="top" width="30.4%" headers="mcps1.1.6.1.5 "><p id="p862135144619"><a name="p862135144619"></a><a name="p862135144619"></a>用“-”区分范围，有五种类型：  1，-50：表示小于等于50的值  2，50-100；表示大于50小于等于100；  3，100-：表示大于100的值  4，"scope": "-"时，表示可以匹配任意场景。  5，50：表示等于50。</p>
</td>
</tr>
<tr id="row13621175144614"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p862115510463"><a name="p862115510463"></a><a name="p862115510463"></a>commandOne</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p36211051104618"><a name="p36211051104618"></a><a name="p36211051104618"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p1762116515468"><a name="p1762116515468"></a><a name="p1762116515468"></a>MultifunctionCommand</p>
</td>
<td class="cellrowborder" valign="top" width="9.6%" headers="mcps1.1.6.1.4 "><p id="p162195119468"><a name="p162195119468"></a><a name="p162195119468"></a>执行动作1</p>
</td>
<td class="cellrowborder" valign="top" width="30.4%" headers="mcps1.1.6.1.5 "><pre class="screen" id="screen1323674071018"><a name="screen1323674071018"></a><a name="screen1323674071018"></a>示例代码如下：
{ 
    "characteristic":  "action", 
    "disableIcon":  "icon_start_dis.png",
    "icon":  "icon_start.png", 
    "value":  1,    
    "sid":  "action" 
}</pre>
</td>
</tr>
<tr id="row126212051124615"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p17621251174612"><a name="p17621251174612"></a><a name="p17621251174612"></a>commandTwo</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p156211251114613"><a name="p156211251114613"></a><a name="p156211251114613"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p126216512467"><a name="p126216512467"></a><a name="p126216512467"></a>MultifunctionCommand</p>
</td>
<td class="cellrowborder" valign="top" width="9.6%" headers="mcps1.1.6.1.4 "><p id="p196212051124613"><a name="p196212051124613"></a><a name="p196212051124613"></a>执行动作2</p>
</td>
<td class="cellrowborder" valign="top" width="30.4%" headers="mcps1.1.6.1.5 "><pre class="screen" id="screen7422145017106"><a name="screen7422145017106"></a><a name="screen7422145017106"></a>示例代码如下：
{ 
    "characteristic":  "action", 
    "disableIcon":  "icon_start_dis.png",
    "icon":  "icon_start.png", 
    "value":  1,    
    "sid":  "action" 
}</pre>
</td>
</tr>
</tbody>
</table>

MultifunctionCommand

<a name="table17358185110465"></a>
<table><thead align="left"><tr id="row7621205112463"><th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.1"><p id="p762135113460"><a name="p762135113460"></a><a name="p762135113460"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.2"><p id="p12621651184611"><a name="p12621651184611"></a><a name="p12621651184611"></a>可选/必选</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.3"><p id="p0621135117460"><a name="p0621135117460"></a><a name="p0621135117460"></a>字段类型</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.4"><p id="p156215517461"><a name="p156215517461"></a><a name="p156215517461"></a>字段描述</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.5"><p id="p15622155194615"><a name="p15622155194615"></a><a name="p15622155194615"></a>备注</p>
</th>
</tr>
</thead>
<tbody><tr id="row1762212515468"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p1062211519464"><a name="p1062211519464"></a><a name="p1062211519464"></a>sid</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p06221951144617"><a name="p06221951144617"></a><a name="p06221951144617"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p186221951134619"><a name="p186221951134619"></a><a name="p186221951134619"></a>String (1-32)</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p06221451124615"><a name="p06221451124615"></a><a name="p06221451124615"></a>命令对应的服务</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p4622115114462"><a name="p4622115114462"></a><a name="p4622115114462"></a>例如：“switch”。</p>
</td>
</tr>
<tr id="row1462265116462"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p5622651104612"><a name="p5622651104612"></a><a name="p5622651104612"></a>characteristic</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p16622751144610"><a name="p16622751144610"></a><a name="p16622751144610"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p86222512462"><a name="p86222512462"></a><a name="p86222512462"></a>String (1-32)</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p6622105174612"><a name="p6622105174612"></a><a name="p6622105174612"></a>命令对应的属性</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p1162295111468"><a name="p1162295111468"></a><a name="p1162295111468"></a>例如：“on”。</p>
</td>
</tr>
<tr id="row4622165124620"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p15622115114463"><a name="p15622115114463"></a><a name="p15622115114463"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p762265144610"><a name="p762265144610"></a><a name="p762265144610"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p962235114465"><a name="p962235114465"></a><a name="p962235114465"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p1462235104619"><a name="p1462235104619"></a><a name="p1462235104619"></a>命令下发对应的属性值</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p662295117463"><a name="p662295117463"></a><a name="p662295117463"></a>value和valueString二者存在其一。其中wifi设备使用value，蓝牙设备使用value或者valueString。</p>
</td>
</tr>
<tr id="row06222513466"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p14622451164614"><a name="p14622451164614"></a><a name="p14622451164614"></a>valueString</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p4622751144612"><a name="p4622751144612"></a><a name="p4622751144612"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p46222510461"><a name="p46222510461"></a><a name="p46222510461"></a>String (1-128)</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p1262345113467"><a name="p1262345113467"></a><a name="p1262345113467"></a>命令下发对应的属性值</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p11623165194612"><a name="p11623165194612"></a><a name="p11623165194612"></a>value和valueString二者存在其一。其中wifi设备使用value，蓝牙设备使用value或者valueString。</p>
</td>
</tr>
<tr id="row126237517463"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p96231151174614"><a name="p96231151174614"></a><a name="p96231151174614"></a>icon</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p96235518469"><a name="p96235518469"></a><a name="p96235518469"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p186231951134619"><a name="p186231951134619"></a><a name="p186231951134619"></a>String (1-128)</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p362313513464"><a name="p362313513464"></a><a name="p362313513464"></a>命令对应的图像标签</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p1662315515462"><a name="p1662315515462"></a><a name="p1662315515462"></a>命令对应的图标url。</p>
</td>
</tr>
<tr id="row136232519466"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p17623165117465"><a name="p17623165117465"></a><a name="p17623165117465"></a>disableIcon</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p106237517468"><a name="p106237517468"></a><a name="p106237517468"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p6623195116462"><a name="p6623195116462"></a><a name="p6623195116462"></a>String (1-128)</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p1362385117460"><a name="p1362385117460"></a><a name="p1362385117460"></a>不可用图标url</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p1262311515467"><a name="p1262311515467"></a><a name="p1262311515467"></a>不可用图标url。</p>
</td>
</tr>
<tr id="row76231351124616"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p562335114464"><a name="p562335114464"></a><a name="p562335114464"></a>disable</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="p9623115120469"><a name="p9623115120469"></a><a name="p9623115120469"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="p19623115124619"><a name="p19623115124619"></a><a name="p19623115124619"></a>String[]</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p26232517466"><a name="p26232517466"></a><a name="p26232517466"></a>命令触发后禁用的标签数组</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p96233511464"><a name="p96233511464"></a><a name="p96233511464"></a>例如：["蒸功能"]，例如：豆浆机关闭的时候，禁用蒸功能。</p>
</td>
</tr>
</tbody>
</table>

