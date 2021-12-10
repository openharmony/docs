# 资源限定与访问<a name="ZH-CN_TOPIC_0000001173164731"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>-   屏幕密度从API Version 4 开始支持。
>-   其余限定词从API Version 6 开始支持。

## 资源限定词<a name="section197802036142011"></a>

资源限定词可以由一个或多个表征应用场景或设备特征的限定词组合而成，包括屏幕密度等维度，限定词之间通过中划线（-）连接。开发者在**resources**目录下创建限定词文件时，需要掌握限定词文件的命名要求以及与限定词文件与设备状态的匹配规则。

## 资源限定词的命名要求<a name="section550585117202"></a>

-   限定词的组合顺序：屏幕密度。开发者可以根据应用的使用场景和设备特征，选择其中的一类或几类限定词组成目录名称，顺序不可颠倒。其中MCC和MNC须同时存在。
-   限定词的连接方式：限定词之间均采用中划线（-）连接。例如：res-dark-ldpi.json 。
-   限定词的取值范围：每类限定词的取值必须符合下表的条件，否则，将无法匹配目录中的资源文件，限定词大小写敏感。
-   限定词前缀：**resources**资源文件的资源限定词有前缀res，例如res-ldpi.json。
-   默认资源限定文件：**resources**资源文件的默认资源限定文件为res-defaults.json。
-   资源限定文件中不支持使用枚举格式的颜色来设置资源。

**表 1**  资源限定词

<a name="table153971631192110"></a>
<table><thead align="left"><tr id="row1397133152114"><th class="cellrowborder" valign="top" width="23.400000000000002%" id="mcps1.2.3.1.1"><p id="p7397331152114"><a name="p7397331152114"></a><a name="p7397331152114"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="76.6%" id="mcps1.2.3.1.2"><p id="p1139719318218"><a name="p1139719318218"></a><a name="p1139719318218"></a>含义与取值说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row23971331152113"><td class="cellrowborder" valign="top" width="23.400000000000002%" headers="mcps1.2.3.1.1 "><p id="p2039763152117"><a name="p2039763152117"></a><a name="p2039763152117"></a>MCC和MNC<sup id="sup7466692017"><a name="sup7466692017"></a><a name="sup7466692017"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="76.6%" headers="mcps1.2.3.1.2 "><p id="p639717316215"><a name="p639717316215"></a><a name="p639717316215"></a>移动设备国家代码 (MCC)，设备 SIM 卡中的移动设备网络代码 (MNC)，如mcc460-mnc01，mcc460-mnc02。</p>
</td>
</tr>
<tr id="row8397103116219"><td class="cellrowborder" valign="top" width="23.400000000000002%" headers="mcps1.2.3.1.1 "><p id="p839793118219"><a name="p839793118219"></a><a name="p839793118219"></a>横竖屏<sup id="sup78689519016"><a name="sup78689519016"></a><a name="sup78689519016"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="76.6%" headers="mcps1.2.3.1.2 "><p id="p11696114442212"><a name="p11696114442212"></a><a name="p11696114442212"></a>表示设备的屏幕方向，取值如下：</p>
<a name="ul1315894982211"></a><a name="ul1315894982211"></a><ul id="ul1315894982211"><li>vertical：竖屏</li><li>horizontal：横屏</li></ul>
</td>
</tr>
<tr id="row13397123192111"><td class="cellrowborder" valign="top" width="23.400000000000002%" headers="mcps1.2.3.1.1 "><p id="p9397931102115"><a name="p9397931102115"></a><a name="p9397931102115"></a>设备类型<sup id="sup1333010908"><a name="sup1333010908"></a><a name="sup1333010908"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="76.6%" headers="mcps1.2.3.1.2 "><p id="p38048942312"><a name="p38048942312"></a><a name="p38048942312"></a>表示设备的类型，取值如下：</p>
<a name="ul13333911182311"></a><a name="ul13333911182311"></a><ul id="ul13333911182311"><li>phone：手机</li><li>tablet：平板</li><li>tv：智慧屏</li><li>wearable：智能穿戴</li></ul>
</td>
</tr>
<tr id="row1890413245238"><td class="cellrowborder" valign="top" width="23.400000000000002%" headers="mcps1.2.3.1.1 "><p id="p2090532442315"><a name="p2090532442315"></a><a name="p2090532442315"></a>屏幕密度</p>
</td>
<td class="cellrowborder" valign="top" width="76.6%" headers="mcps1.2.3.1.2 "><p id="p2389144311231"><a name="p2389144311231"></a><a name="p2389144311231"></a>表示设备的屏幕密度（单位为dpi），取值如下：</p>
<a name="ul1311184562317"></a><a name="ul1311184562317"></a><ul id="ul1311184562317"><li>ldpi：表示低密度屏幕（~120dpi）（0.75基准密度）</li><li>mdpi：表示中密度屏幕（~160dpi）（基准密度）</li><li>hdpi：表示高密度屏幕（~240dpi）（1.5基准密度）</li><li>xhdpi：表示加高密度屏幕（~320dpi）（2.0基准密度）</li><li>xxhdpi：表示超超高密度屏幕（~480dpi）（3.0基准密度）</li><li>xxxhdpi：表示超超超高密度屏幕（~640dpi）（4.0基准密度）</li></ul>
</td>
</tr>
</tbody>
</table>

## 限定词与设备状态的匹配规则<a name="section59927387241"></a>

-   在为设备匹配对应的资源文件时，限定词目录匹配的优先级从高到低依次为：MCC和MNC\> 横竖屏 \> 深色模式 \> 设备类型 \> 屏幕密度。在资源限定词目录均未匹配的情况下，则匹配默认资源限定文件。
-   如果限定词目录中包含资源限定词，则对应限定词的取值必须与当前的设备状态完全一致，该目录才能够参与设备的资源匹配。例如：资源限定文件res-hdpi.json与当前设备密度xhdpi无法匹配。

## 引用JS模块内resources资源<a name="section7516798256"></a>

在应用开发的hml和js文件中使用$r的语法，可以对JS模块内的resources目录下的json资源进行格式化，获取相应的资源内容。

<a name="table1595144416585"></a>
<table><thead align="left"><tr id="row1295119445588"><th class="cellrowborder" valign="top" width="11.41114111411141%" id="mcps1.1.4.1.1"><p id="p18951844195815"><a name="p18951844195815"></a><a name="p18951844195815"></a>属性</p>
</th>
<th class="cellrowborder" valign="top" width="23.17231723172317%" id="mcps1.1.4.1.2"><p id="p16951044135813"><a name="p16951044135813"></a><a name="p16951044135813"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="65.41654165416541%" id="mcps1.1.4.1.3"><p id="p1795154417586"><a name="p1795154417586"></a><a name="p1795154417586"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row8951164435812"><td class="cellrowborder" valign="top" width="11.41114111411141%" headers="mcps1.1.4.1.1 "><p id="p195124495814"><a name="p195124495814"></a><a name="p195124495814"></a>$r</p>
</td>
<td class="cellrowborder" valign="top" width="23.17231723172317%" headers="mcps1.1.4.1.2 "><p id="p3952164418589"><a name="p3952164418589"></a><a name="p3952164418589"></a>(key: string) =&gt; string</p>
</td>
<td class="cellrowborder" valign="top" width="65.41654165416541%" headers="mcps1.1.4.1.3 "><p id="p204636815564"><a name="p204636815564"></a><a name="p204636815564"></a>获取资源限定下具体的资源内容。例如：this.$r('strings.hello')。</p>
<p id="p1146311815615"><a name="p1146311815615"></a><a name="p1146311815615"></a>参数说明：</p>
<a name="ul18463178185617"></a><a name="ul18463178185617"></a><ul id="ul18463178185617"><li>key：定义在资源限定文件中的键值，如strings.hello。</li></ul>
<p id="p174645835614"><a name="p174645835614"></a><a name="p174645835614"></a><strong id="b74640855613"><a name="b74640855613"></a><a name="b74640855613"></a>res-defaults.json示例：</strong></p>
<pre class="screen" id="screen8464178165613"><a name="screen8464178165613"></a><a name="screen8464178165613"></a>{
    strings: {
        hello: 'hello world'
    }
}</pre>
</td>
</tr>
</tbody>
</table>

## 示例<a name="section9710101017318"></a>

resources/res-dark.json:

```
{
    "image": {
        "clockFace": "common/dark_face.png"
    },
    "colors": {
	"background": "#000000"
    }
}
```

resources/res-defaults.json:

```
{
    "image": {
        "clockFace": "common/face.png"
    },
    "colors": {
	"background": "#ffffff"
    }
}
```

```
<!-- xxx.hml -->
<div style="background-color: {{ $r('colors.background') }}">
    <image src="{{ $r('image.clockFace') }}"></image>
</div>
```

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>资源限定文件中不支持颜色枚举格式。

