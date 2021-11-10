# 应用程序的数据存储<a name="ZH-CN_TOPIC_0000001119929480"></a>

**AppStorage**是应用程序中的单例对象，由UI框架在应用程序启动时创建。它的目的是为可变应用程序状态属性提供中央存储。**AppStorage**包含整个应用程序中需要访问的所有状态属性。只要应用程序保持运行，**AppStorage**存储就会保留所有属性及其值，属性值可以通过唯一的键值进行访问。

UI组件可以通过装饰器将应用程序状态数据与**AppStorage**进行同步。应用业务逻辑的实现也可以通过接口访问**AppStorage**。

AppStorage的选择状态属性可以与不同的数据源或数据接收器同步。这些数据源和接收器可以是设备上的本地或远程，并具有不同的功能，如数据持久性。这样的数据源和接收器可以独立于UI在业务逻辑中实现。

默认情况下，**AppStorage**中的属性是可变的，**AppStorage**还可使用不可变（只读）属性。

## AppStorage接口说明<a name="zh-cn_topic_0000001103218748_section89909382526"></a>

<a name="zh-cn_topic_0000001103218748_table109mcpsimp"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001103218748_row115mcpsimp"><th class="cellrowborder" valign="top" width="11.700000000000001%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001103218748_p117mcpsimp"><a name="zh-cn_topic_0000001103218748_p117mcpsimp"></a><a name="zh-cn_topic_0000001103218748_p117mcpsimp"></a>方法</p>
</th>
<th class="cellrowborder" valign="top" width="13.96%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001103218748_p119mcpsimp"><a name="zh-cn_topic_0000001103218748_p119mcpsimp"></a><a name="zh-cn_topic_0000001103218748_p119mcpsimp"></a>参数说明</p>
</th>
<th class="cellrowborder" valign="top" width="12.379999999999999%" id="mcps1.1.5.1.3"><p id="p1566112607"><a name="p1566112607"></a><a name="p1566112607"></a>返回值</p>
</th>
<th class="cellrowborder" valign="top" width="61.96%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001103218748_p121mcpsimp"><a name="zh-cn_topic_0000001103218748_p121mcpsimp"></a><a name="zh-cn_topic_0000001103218748_p121mcpsimp"></a>定义</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001103218748_row122mcpsimp"><td class="cellrowborder" valign="top" width="11.700000000000001%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001103218748_p124mcpsimp"><a name="zh-cn_topic_0000001103218748_p124mcpsimp"></a><a name="zh-cn_topic_0000001103218748_p124mcpsimp"></a>Link</p>
</td>
<td class="cellrowborder" valign="top" width="13.96%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001103218748_p126mcpsimp"><a name="zh-cn_topic_0000001103218748_p126mcpsimp"></a><a name="zh-cn_topic_0000001103218748_p126mcpsimp"></a>key: string</p>
</td>
<td class="cellrowborder" valign="top" width="12.379999999999999%" headers="mcps1.1.5.1.3 "><p id="p185664215018"><a name="p185664215018"></a><a name="p185664215018"></a>@Link</p>
</td>
<td class="cellrowborder" valign="top" width="61.96%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001103218748_p128mcpsimp"><a name="zh-cn_topic_0000001103218748_p128mcpsimp"></a><a name="zh-cn_topic_0000001103218748_p128mcpsimp"></a>如果存在具有给定键的数据，则返回到此属性的双向数据绑定，该双向绑定意味着变量或者组件对数据的更改将同步到<strong id="zh-cn_topic_0000001103218748_b086010478369"><a name="zh-cn_topic_0000001103218748_b086010478369"></a><a name="zh-cn_topic_0000001103218748_b086010478369"></a>AppStorage</strong>，通过<strong id="zh-cn_topic_0000001103218748_b748595013369"><a name="zh-cn_topic_0000001103218748_b748595013369"></a><a name="zh-cn_topic_0000001103218748_b748595013369"></a>AppStorage</strong>对数据的修改将同步到变量或者组件。如果具有此键的属性不存在或属性为只读，则返回<strong id="zh-cn_topic_0000001103218748_b3740185374119"><a name="zh-cn_topic_0000001103218748_b3740185374119"></a><a name="zh-cn_topic_0000001103218748_b3740185374119"></a>undefined</strong>。</p>
</td>
</tr>
<tr id="row327610512417"><td class="cellrowborder" valign="top" width="11.700000000000001%" headers="mcps1.1.5.1.1 "><p id="p142761957415"><a name="p142761957415"></a><a name="p142761957415"></a>SetAndLink</p>
</td>
<td class="cellrowborder" valign="top" width="13.96%" headers="mcps1.1.5.1.2 "><p id="p240416172411"><a name="p240416172411"></a><a name="p240416172411"></a>key : String</p>
<p id="p540414171943"><a name="p540414171943"></a><a name="p540414171943"></a>defaultValue: T</p>
</td>
<td class="cellrowborder" valign="top" width="12.379999999999999%" headers="mcps1.1.5.1.3 "><p id="p96661522744"><a name="p96661522744"></a><a name="p96661522744"></a>@Link</p>
</td>
<td class="cellrowborder" valign="top" width="61.96%" headers="mcps1.1.5.1.4 "><p id="p13277851841"><a name="p13277851841"></a><a name="p13277851841"></a>与Link接口类似。如果当前的key在AppStorage有保存，则返回此key对应的value。如果此key未被创建，则创建一个对应default值的Link返回。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103218748_row129mcpsimp"><td class="cellrowborder" valign="top" width="11.700000000000001%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001103218748_p131mcpsimp"><a name="zh-cn_topic_0000001103218748_p131mcpsimp"></a><a name="zh-cn_topic_0000001103218748_p131mcpsimp"></a>Prop</p>
</td>
<td class="cellrowborder" valign="top" width="13.96%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001103218748_p133mcpsimp"><a name="zh-cn_topic_0000001103218748_p133mcpsimp"></a><a name="zh-cn_topic_0000001103218748_p133mcpsimp"></a>key: string</p>
</td>
<td class="cellrowborder" valign="top" width="12.379999999999999%" headers="mcps1.1.5.1.3 "><p id="p55660211014"><a name="p55660211014"></a><a name="p55660211014"></a>@Prop</p>
</td>
<td class="cellrowborder" valign="top" width="61.96%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001103218748_p135mcpsimp"><a name="zh-cn_topic_0000001103218748_p135mcpsimp"></a><a name="zh-cn_topic_0000001103218748_p135mcpsimp"></a>如果存在具有给定键的属性，则返回到此属性的单向数据绑定。该单向绑定意味着只能通过<strong id="zh-cn_topic_0000001103218748_b1388608184310"><a name="zh-cn_topic_0000001103218748_b1388608184310"></a><a name="zh-cn_topic_0000001103218748_b1388608184310"></a>AppStorage</strong>将属性的更改同步到变量或者组件。该方法返回的变量为不可变变量，适用于可变和不可变的状态属性，如果具有此键的属性不存在则返回<strong id="zh-cn_topic_0000001103218748_b14239023171713"><a name="zh-cn_topic_0000001103218748_b14239023171713"></a><a name="zh-cn_topic_0000001103218748_b14239023171713"></a>undefined</strong>。</p>
<div class="note" id="zh-cn_topic_0000001103218748_note1886831124618"><a name="zh-cn_topic_0000001103218748_note1886831124618"></a><a name="zh-cn_topic_0000001103218748_note1886831124618"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="p522015411452"><a name="p522015411452"></a><a name="p522015411452"></a>prop方法对应的属性值类型为简单类型。</p>
</div></div>
</td>
</tr>
<tr id="row13351212193"><td class="cellrowborder" valign="top" width="11.700000000000001%" headers="mcps1.1.5.1.1 "><p id="p835812194"><a name="p835812194"></a><a name="p835812194"></a>SetAndProp</p>
</td>
<td class="cellrowborder" valign="top" width="13.96%" headers="mcps1.1.5.1.2 "><p id="p1228852918920"><a name="p1228852918920"></a><a name="p1228852918920"></a>key : string</p>
<p id="p132888294919"><a name="p132888294919"></a><a name="p132888294919"></a>defaultValue: S</p>
</td>
<td class="cellrowborder" valign="top" width="12.379999999999999%" headers="mcps1.1.5.1.3 "><p id="p035712792"><a name="p035712792"></a><a name="p035712792"></a>@Prop</p>
</td>
<td class="cellrowborder" valign="top" width="61.96%" headers="mcps1.1.5.1.4 "><p id="p18161144416910"><a name="p18161144416910"></a><a name="p18161144416910"></a>与Prop接口类似。如果当前的key在AppStorage有保存，则返回此key对应的value。如果此key未被创建，则创建一个对应default值的Prop返回。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103218748_row136mcpsimp"><td class="cellrowborder" valign="top" width="11.700000000000001%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001103218748_p138mcpsimp"><a name="zh-cn_topic_0000001103218748_p138mcpsimp"></a><a name="zh-cn_topic_0000001103218748_p138mcpsimp"></a>Has</p>
</td>
<td class="cellrowborder" valign="top" width="13.96%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001103218748_p140mcpsimp"><a name="zh-cn_topic_0000001103218748_p140mcpsimp"></a><a name="zh-cn_topic_0000001103218748_p140mcpsimp"></a>key: string</p>
</td>
<td class="cellrowborder" valign="top" width="12.379999999999999%" headers="mcps1.1.5.1.3 "><p id="p125661627019"><a name="p125661627019"></a><a name="p125661627019"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="61.96%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001103218748_p142mcpsimp"><a name="zh-cn_topic_0000001103218748_p142mcpsimp"></a><a name="zh-cn_topic_0000001103218748_p142mcpsimp"></a><span>判断对应键值的属性是否存在</span>。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103218748_row150mcpsimp"><td class="cellrowborder" valign="top" width="11.700000000000001%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001103218748_p1363415429353"><a name="zh-cn_topic_0000001103218748_p1363415429353"></a><a name="zh-cn_topic_0000001103218748_p1363415429353"></a>Keys</p>
</td>
<td class="cellrowborder" valign="top" width="13.96%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001103218748_p154mcpsimp"><a name="zh-cn_topic_0000001103218748_p154mcpsimp"></a><a name="zh-cn_topic_0000001103218748_p154mcpsimp"></a>void</p>
</td>
<td class="cellrowborder" valign="top" width="12.379999999999999%" headers="mcps1.1.5.1.3 "><p id="p19566522014"><a name="p19566522014"></a><a name="p19566522014"></a>array&lt;string&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="61.96%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001103218748_p156mcpsimp"><a name="zh-cn_topic_0000001103218748_p156mcpsimp"></a><a name="zh-cn_topic_0000001103218748_p156mcpsimp"></a>返回包含所有键的字符串数组。</p>
</td>
</tr>
<tr id="row3460194012589"><td class="cellrowborder" valign="top" width="11.700000000000001%" headers="mcps1.1.5.1.1 "><p id="p1846mcpsimp"><a name="p1846mcpsimp"></a><a name="p1846mcpsimp"></a>Get</p>
</td>
<td class="cellrowborder" valign="top" width="13.96%" headers="mcps1.1.5.1.2 "><p id="p263019299243"><a name="p263019299243"></a><a name="p263019299243"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="12.379999999999999%" headers="mcps1.1.5.1.3 "><p id="p14566921105"><a name="p14566921105"></a><a name="p14566921105"></a>T或undefined</p>
</td>
<td class="cellrowborder" valign="top" width="61.96%" headers="mcps1.1.5.1.4 "><p id="p1850mcpsimp"><a name="p1850mcpsimp"></a><a name="p1850mcpsimp"></a>通过此接口获取对应此key值的value</p>
</td>
</tr>
<tr id="row4460184019583"><td class="cellrowborder" valign="top" width="11.700000000000001%" headers="mcps1.1.5.1.1 "><p id="p4826171212519"><a name="p4826171212519"></a><a name="p4826171212519"></a>Set</p>
</td>
<td class="cellrowborder" valign="top" width="13.96%" headers="mcps1.1.5.1.2 "><p id="p11826512152517"><a name="p11826512152517"></a><a name="p11826512152517"></a>string,  newValue ：T</p>
</td>
<td class="cellrowborder" valign="top" width="12.379999999999999%" headers="mcps1.1.5.1.3 "><p id="p185671321506"><a name="p185671321506"></a><a name="p185671321506"></a>void</p>
</td>
<td class="cellrowborder" valign="top" width="61.96%" headers="mcps1.1.5.1.4 "><p id="p1982671202510"><a name="p1982671202510"></a><a name="p1982671202510"></a>对已保存的key值，替换其value值。</p>
</td>
</tr>
<tr id="row546074014585"><td class="cellrowborder" valign="top" width="11.700000000000001%" headers="mcps1.1.5.1.1 "><p id="p1799852316279"><a name="p1799852316279"></a><a name="p1799852316279"></a>SetOrCreate</p>
</td>
<td class="cellrowborder" valign="top" width="13.96%" headers="mcps1.1.5.1.2 "><p id="p146505413272"><a name="p146505413272"></a><a name="p146505413272"></a>string,  newValue ：T</p>
</td>
<td class="cellrowborder" valign="top" width="12.379999999999999%" headers="mcps1.1.5.1.3 "><p id="p168731437917"><a name="p168731437917"></a><a name="p168731437917"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="61.96%" headers="mcps1.1.5.1.4 "><p id="p639717522815"><a name="p639717522815"></a><a name="p639717522815"></a>如果相同名字的属性存在：如果此属性可以被更改返回true，否则返回false</p>
<p id="p17541322112611"><a name="p17541322112611"></a><a name="p17541322112611"></a>如果相同名字的属性不存在：创建第一个赋值为defaultValue的属性，不支持null和undefined</p>
</td>
</tr>
<tr id="row350321491214"><td class="cellrowborder" valign="top" width="11.700000000000001%" headers="mcps1.1.5.1.1 "><p id="p17503121481216"><a name="p17503121481216"></a><a name="p17503121481216"></a>Delete</p>
</td>
<td class="cellrowborder" valign="top" width="13.96%" headers="mcps1.1.5.1.2 "><p id="p6503161417122"><a name="p6503161417122"></a><a name="p6503161417122"></a>key : string</p>
</td>
<td class="cellrowborder" valign="top" width="12.379999999999999%" headers="mcps1.1.5.1.3 "><p id="p205031814191212"><a name="p205031814191212"></a><a name="p205031814191212"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="61.96%" headers="mcps1.1.5.1.4 "><p id="p05031014141211"><a name="p05031014141211"></a><a name="p05031014141211"></a>删除属性，如果存在返回true，不存在返回false</p>
</td>
</tr>
<tr id="row12261203911401"><td class="cellrowborder" valign="top" width="11.700000000000001%" headers="mcps1.1.5.1.1 "><p id="p202611739204016"><a name="p202611739204016"></a><a name="p202611739204016"></a>Clear</p>
</td>
<td class="cellrowborder" valign="top" width="13.96%" headers="mcps1.1.5.1.2 "><p id="p526118395407"><a name="p526118395407"></a><a name="p526118395407"></a>none</p>
</td>
<td class="cellrowborder" valign="top" width="12.379999999999999%" headers="mcps1.1.5.1.3 "><p id="p326173910400"><a name="p326173910400"></a><a name="p326173910400"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="61.96%" headers="mcps1.1.5.1.4 "><p id="p22611139114012"><a name="p22611139114012"></a><a name="p22611139114012"></a>删除所有的属性，如果当前有状态变量依旧引用此属性，则返回false</p>
</td>
</tr>
<tr id="row14209473411"><td class="cellrowborder" valign="top" width="11.700000000000001%" headers="mcps1.1.5.1.1 "><p id="p12420347194115"><a name="p12420347194115"></a><a name="p12420347194115"></a>IsMutable</p>
</td>
<td class="cellrowborder" valign="top" width="13.96%" headers="mcps1.1.5.1.2 "><p id="p10420174754114"><a name="p10420174754114"></a><a name="p10420174754114"></a>key: string</p>
</td>
<td class="cellrowborder" valign="top" width="12.379999999999999%" headers="mcps1.1.5.1.3 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="61.96%" headers="mcps1.1.5.1.4 "><p id="p1942074711417"><a name="p1942074711417"></a><a name="p1942074711417"></a>返回此属性是否存在并且是否可以改变。</p>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>当前接口当前仅可以处理基础类型数据，对于修改object中某一个值尚未支持。

## 示例<a name="zh-cn_topic_0000001103218748_section195112274815"></a>

```
let link1 = AppStorage.Link('PropA')
let link2 = AppStorage.Link('PropA')
let prop = AppStorage.Prop('PropA')

link1 = 47  // causes link1 == link2 == prop == 47
link2 = link1 + prop  // causes link1 == link2 == prop == 94
prop = 1  // error, prop is immutable
```

