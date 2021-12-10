# 环境变量<a name="ZH-CN_TOPIC_0000001129032930"></a>

**Environment**是框架在应用程序启动时创建的单例对象，它为**AppStorage**提供了一系列应用程序需要的环境状态属性，这些属性描述了应用程序运行的设备环境。**Environment**及其属性是不可变的，所有属性值类型均为简单类型。

如下示例展示了从**Environment**获取语音环境：

```
Environment.EnvProp("accessibilityEnabled", "default");
var enable = AppStorageGet("accessibilityEnabled");
```

**accessibilityEnabled**是**Environment**提供默认系统变量识别符。首先需要将对应系统属性绑定到**Appstorage**中，后可以通过AppStorage中的方法或者装饰器，访问对应系统属性数据。

## Environment接口<a name="section12843192134"></a>

<a name="table384419171310"></a>
<table><thead align="left"><tr id="row284141915136"><th class="cellrowborder" valign="top" width="14.26%" id="mcps1.1.5.1.1"><p id="p1784419191310"><a name="p1784419191310"></a><a name="p1784419191310"></a><strong id="b88541913130"><a name="b88541913130"></a><a name="b88541913130"></a>key</strong></p>
</th>
<th class="cellrowborder" valign="top" width="25.330000000000002%" id="mcps1.1.5.1.2"><p id="p168921384172"><a name="p168921384172"></a><a name="p168921384172"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="12.590000000000002%" id="mcps1.1.5.1.3"><p id="p12851119141312"><a name="p12851119141312"></a><a name="p12851119141312"></a>返回值</p>
</th>
<th class="cellrowborder" valign="top" width="47.82%" id="mcps1.1.5.1.4"><p id="p885719141315"><a name="p885719141315"></a><a name="p885719141315"></a><strong id="b188551941314"><a name="b188551941314"></a><a name="b188551941314"></a>说明</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row6857197134"><td class="cellrowborder" valign="top" width="14.26%" headers="mcps1.1.5.1.1 "><p id="p1385101911130"><a name="p1385101911130"></a><a name="p1385101911130"></a>EnvProp</p>
</td>
<td class="cellrowborder" valign="top" width="25.330000000000002%" headers="mcps1.1.5.1.2 "><p id="p5663204012204"><a name="p5663204012204"></a><a name="p5663204012204"></a>key : string</p>
<p id="p566354016203"><a name="p566354016203"></a><a name="p566354016203"></a>defaultValue: any</p>
</td>
<td class="cellrowborder" valign="top" width="12.590000000000002%" headers="mcps1.1.5.1.3 "><p id="p1585019161319"><a name="p1585019161319"></a><a name="p1585019161319"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="47.82%" headers="mcps1.1.5.1.4 "><p id="p385151931313"><a name="p385151931313"></a><a name="p385151931313"></a>关联此系统项到Appstorage中。建议在app启动时使用此Api。如果此属性在Appstorage已经存在则返回false。请勿使用AppStorage中的变量，在调用此方法关联环境变量。</p>
</td>
</tr>
<tr id="row685121921320"><td class="cellrowborder" valign="top" width="14.26%" headers="mcps1.1.5.1.1 "><p id="p89412247562"><a name="p89412247562"></a><a name="p89412247562"></a>EnvProps</p>
</td>
<td class="cellrowborder" valign="top" width="25.330000000000002%" headers="mcps1.1.5.1.2 "><p id="p16911327112814"><a name="p16911327112814"></a><a name="p16911327112814"></a>keys: {</p>
<p id="p260853217289"><a name="p260853217289"></a><a name="p260853217289"></a>key: string,</p>
<p id="p2084673414282"><a name="p2084673414282"></a><a name="p2084673414282"></a>defaultValue: any</p>
<p id="p1989210821720"><a name="p1989210821720"></a><a name="p1989210821720"></a>}[]</p>
</td>
<td class="cellrowborder" valign="top" width="12.590000000000002%" headers="mcps1.1.5.1.3 "><p id="p19487625142016"><a name="p19487625142016"></a><a name="p19487625142016"></a>void</p>
</td>
<td class="cellrowborder" valign="top" width="47.82%" headers="mcps1.1.5.1.4 "><p id="p2029419733518"><a name="p2029419733518"></a><a name="p2029419733518"></a>关联此系统项数组到Appstorage中。</p>
</td>
</tr>
<tr id="row198581961319"><td class="cellrowborder" valign="top" width="14.26%" headers="mcps1.1.5.1.1 "><p id="p1685319131316"><a name="p1685319131316"></a><a name="p1685319131316"></a>Keys</p>
</td>
<td class="cellrowborder" valign="top" width="25.330000000000002%" headers="mcps1.1.5.1.2 "><p id="p1282319383561"><a name="p1282319383561"></a><a name="p1282319383561"></a>Array&lt;string&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.590000000000002%" headers="mcps1.1.5.1.3 "><p id="p128511951310"><a name="p128511951310"></a><a name="p128511951310"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="47.82%" headers="mcps1.1.5.1.4 "><p id="p138551931318"><a name="p138551931318"></a><a name="p138551931318"></a>返回关联的系统项。</p>
</td>
</tr>
</tbody>
</table>

## Environment内置的环境变量<a name="section76906244255"></a>

<a name="table367mcpsimp"></a>
<table><thead align="left"><tr id="row373mcpsimp"><th class="cellrowborder" valign="top" width="25.919999999999998%" id="mcps1.1.4.1.1"><p id="p375mcpsimp"><a name="p375mcpsimp"></a><a name="p375mcpsimp"></a><strong id="b1320314815620"><a name="b1320314815620"></a><a name="b1320314815620"></a>key</strong></p>
</th>
<th class="cellrowborder" valign="top" width="22.02%" id="mcps1.1.4.1.2"><p id="p377mcpsimp"><a name="p377mcpsimp"></a><a name="p377mcpsimp"></a><strong id="b2204581618"><a name="b2204581618"></a><a name="b2204581618"></a>类型</strong></p>
</th>
<th class="cellrowborder" valign="top" width="52.059999999999995%" id="mcps1.1.4.1.3"><p id="p379mcpsimp"><a name="p379mcpsimp"></a><a name="p379mcpsimp"></a><strong id="b1220514815611"><a name="b1220514815611"></a><a name="b1220514815611"></a>说明</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row380mcpsimp"><td class="cellrowborder" valign="top" width="25.919999999999998%" headers="mcps1.1.4.1.1 "><p id="p7162853112520"><a name="p7162853112520"></a><a name="p7162853112520"></a>accessibilityEnabled</p>
</td>
<td class="cellrowborder" valign="top" width="22.02%" headers="mcps1.1.4.1.2 "><p id="p384mcpsimp"><a name="p384mcpsimp"></a><a name="p384mcpsimp"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="52.059999999999995%" headers="mcps1.1.4.1.3 "><p id="p386mcpsimp"><a name="p386mcpsimp"></a><a name="p386mcpsimp"></a>无障碍屏幕朗读是否启用。</p>
</td>
</tr>
<tr id="row387mcpsimp"><td class="cellrowborder" valign="top" width="25.919999999999998%" headers="mcps1.1.4.1.1 "><p id="p389mcpsimp"><a name="p389mcpsimp"></a><a name="p389mcpsimp"></a>colorMode</p>
</td>
<td class="cellrowborder" valign="top" width="22.02%" headers="mcps1.1.4.1.2 "><p id="p391mcpsimp"><a name="p391mcpsimp"></a><a name="p391mcpsimp"></a>ColorMode</p>
</td>
<td class="cellrowborder" valign="top" width="52.059999999999995%" headers="mcps1.1.4.1.3 "><p id="p897319423383"><a name="p897319423383"></a><a name="p897319423383"></a>深浅色模式，选项值为：</p>
<a name="ul11210147183818"></a><a name="ul11210147183818"></a><ul id="ul11210147183818"><li>ColorMode.LIGHT：浅色模式；</li><li>ColorMode.DARK：深色模式。</li></ul>
</td>
</tr>
<tr id="row394mcpsimp"><td class="cellrowborder" valign="top" width="25.919999999999998%" headers="mcps1.1.4.1.1 "><p id="p396mcpsimp"><a name="p396mcpsimp"></a><a name="p396mcpsimp"></a>fontScale</p>
</td>
<td class="cellrowborder" valign="top" width="22.02%" headers="mcps1.1.4.1.2 "><p id="p398mcpsimp"><a name="p398mcpsimp"></a><a name="p398mcpsimp"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="52.059999999999995%" headers="mcps1.1.4.1.3 "><p id="p400mcpsimp"><a name="p400mcpsimp"></a><a name="p400mcpsimp"></a>字体大小比例，范围为：[0.85, 1.45]。</p>
</td>
</tr>
<tr id="row401mcpsimp"><td class="cellrowborder" valign="top" width="25.919999999999998%" headers="mcps1.1.4.1.1 "><p id="p778417357267"><a name="p778417357267"></a><a name="p778417357267"></a>fontWeightScale</p>
</td>
<td class="cellrowborder" valign="top" width="22.02%" headers="mcps1.1.4.1.2 "><p id="p405mcpsimp"><a name="p405mcpsimp"></a><a name="p405mcpsimp"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="52.059999999999995%" headers="mcps1.1.4.1.3 "><p id="p407mcpsimp"><a name="p407mcpsimp"></a><a name="p407mcpsimp"></a>字体权重比例，取值范围：[0.6, 1.6]。</p>
</td>
</tr>
<tr id="row408mcpsimp"><td class="cellrowborder" valign="top" width="25.919999999999998%" headers="mcps1.1.4.1.1 "><p id="p410mcpsimp"><a name="p410mcpsimp"></a><a name="p410mcpsimp"></a>layoutDirection</p>
</td>
<td class="cellrowborder" valign="top" width="22.02%" headers="mcps1.1.4.1.2 "><p id="p412mcpsimp"><a name="p412mcpsimp"></a><a name="p412mcpsimp"></a>LayoutDirection</p>
</td>
<td class="cellrowborder" valign="top" width="52.059999999999995%" headers="mcps1.1.4.1.3 "><p id="p549615347406"><a name="p549615347406"></a><a name="p549615347406"></a>布局方向类型，可选值为：</p>
<a name="ul370513428408"></a><a name="ul370513428408"></a><ul id="ul370513428408"><li>LayoutDirection.LTR：从左到右；</li><li>LayoutDirection.RTL：从右到左。</li></ul>
</td>
</tr>
<tr id="row415mcpsimp"><td class="cellrowborder" valign="top" width="25.919999999999998%" headers="mcps1.1.4.1.1 "><p id="p417mcpsimp"><a name="p417mcpsimp"></a><a name="p417mcpsimp"></a>languageCode</p>
</td>
<td class="cellrowborder" valign="top" width="22.02%" headers="mcps1.1.4.1.2 "><p id="p419mcpsimp"><a name="p419mcpsimp"></a><a name="p419mcpsimp"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="52.059999999999995%" headers="mcps1.1.4.1.3 "><p id="p421mcpsimp"><a name="p421mcpsimp"></a><a name="p421mcpsimp"></a>当前系统语言值，小写字母，例如zh。</p>
</td>
</tr>
</tbody>
</table>

