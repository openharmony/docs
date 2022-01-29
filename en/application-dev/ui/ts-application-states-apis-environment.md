# Environment<a name="EN-US_TOPIC_0000001129032930"></a>

**Environment**  is a singleton object created by the framework when the application is started. It provides the  **AppStorage**  with a series of environment state attributes required by the application. These attributes describe the device environment where the application runs.  **Environment**  and its attributes are immutable, and all attribute values are of the simple type.

The following example shows how to obtain the voice environment from  **Environment**:

```
Environment.EnvProp("accessibilityEnabled", "default");
var enable = AppStorageGet("accessibilityEnabled");
```

**accessibilityEnabled**  is the default system variable identifier provided by  **Environment**. You need to bind the corresponding system attribute to the  **AppStorage**. Then, you can use the methods or decorators in the  **AppStorage**  to access the corresponding system attribute data.

## Environment APIs<a name="section12843192134"></a>

<a name="table384419171310"></a>
<table><thead align="left"><tr id="row284141915136"><th class="cellrowborder" valign="top" width="14.26%" id="mcps1.1.5.1.1"><p id="p1784419191310"><a name="p1784419191310"></a><a name="p1784419191310"></a><strong id="b88541913130"><a name="b88541913130"></a><a name="b88541913130"></a>key</strong></p>
</th>
<th class="cellrowborder" valign="top" width="25.330000000000002%" id="mcps1.1.5.1.2"><p id="p168921384172"><a name="p168921384172"></a><a name="p168921384172"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="8.82%" id="mcps1.1.5.1.3"><p id="p12851119141312"><a name="p12851119141312"></a><a name="p12851119141312"></a>Return Value</p>
</th>
<th class="cellrowborder" valign="top" width="51.59%" id="mcps1.1.5.1.4"><p id="p885719141315"><a name="p885719141315"></a><a name="p885719141315"></a><strong id="b7724111610402"><a name="b7724111610402"></a><a name="b7724111610402"></a>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row6857197134"><td class="cellrowborder" valign="top" width="14.26%" headers="mcps1.1.5.1.1 "><p id="p1385101911130"><a name="p1385101911130"></a><a name="p1385101911130"></a>EnvProp</p>
</td>
<td class="cellrowborder" valign="top" width="25.330000000000002%" headers="mcps1.1.5.1.2 "><p id="p5663204012204"><a name="p5663204012204"></a><a name="p5663204012204"></a>key : string</p>
<p id="p566354016203"><a name="p566354016203"></a><a name="p566354016203"></a>defaultValue: any</p>
</td>
<td class="cellrowborder" valign="top" width="8.82%" headers="mcps1.1.5.1.3 "><p id="p1585019161319"><a name="p1585019161319"></a><a name="p1585019161319"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="51.59%" headers="mcps1.1.5.1.4 "><p id="p385151931313"><a name="p385151931313"></a><a name="p385151931313"></a>Associates this system variable to the <strong id="b133309266408"><a name="b133309266408"></a><a name="b133309266408"></a>Appstorage</strong>. You are advised to use this API during application startup. If the attribute already exists in the <strong id="b1445964684012"><a name="b1445964684012"></a><a name="b1445964684012"></a>Appstorage</strong>, <strong id="b597684864017"><a name="b597684864017"></a><a name="b597684864017"></a>false</strong> is returned. Do not use the variables in the <strong id="b1363175314401"><a name="b1363175314401"></a><a name="b1363175314401"></a>AppStorage</strong>. Instead, call this method to bind environment variables.</p>
</td>
</tr>
<tr id="row685121921320"><td class="cellrowborder" valign="top" width="14.26%" headers="mcps1.1.5.1.1 "><p id="p89412247562"><a name="p89412247562"></a><a name="p89412247562"></a>EnvProps</p>
</td>
<td class="cellrowborder" valign="top" width="25.330000000000002%" headers="mcps1.1.5.1.2 "><p id="p16911327112814"><a name="p16911327112814"></a><a name="p16911327112814"></a>keys: {</p>
<p id="p260853217289"><a name="p260853217289"></a><a name="p260853217289"></a>key: string,</p>
<p id="p2084673414282"><a name="p2084673414282"></a><a name="p2084673414282"></a>defaultValue: any</p>
<p id="p1989210821720"><a name="p1989210821720"></a><a name="p1989210821720"></a>}[]</p>
</td>
<td class="cellrowborder" valign="top" width="8.82%" headers="mcps1.1.5.1.3 "><p id="p19487625142016"><a name="p19487625142016"></a><a name="p19487625142016"></a>void</p>
</td>
<td class="cellrowborder" valign="top" width="51.59%" headers="mcps1.1.5.1.4 "><p id="p2029419733518"><a name="p2029419733518"></a><a name="p2029419733518"></a>Associates this system item array with the <strong id="b18508171615413"><a name="b18508171615413"></a><a name="b18508171615413"></a>Appstorage</strong>.</p>
</td>
</tr>
<tr id="row198581961319"><td class="cellrowborder" valign="top" width="14.26%" headers="mcps1.1.5.1.1 "><p id="p1685319131316"><a name="p1685319131316"></a><a name="p1685319131316"></a>Keys</p>
</td>
<td class="cellrowborder" valign="top" width="25.330000000000002%" headers="mcps1.1.5.1.2 "><p id="p1282319383561"><a name="p1282319383561"></a><a name="p1282319383561"></a>Array&lt;string&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.82%" headers="mcps1.1.5.1.3 "><p id="p128511951310"><a name="p128511951310"></a><a name="p128511951310"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="51.59%" headers="mcps1.1.5.1.4 "><p id="p138551931318"><a name="p138551931318"></a><a name="p138551931318"></a>Returns the associated system item array.</p>
</td>
</tr>
</tbody>
</table>

## Built-in Environment Variables<a name="section76906244255"></a>

<a name="table367mcpsimp"></a>
<table><thead align="left"><tr id="row373mcpsimp"><th class="cellrowborder" valign="top" width="15.42%" id="mcps1.1.4.1.1"><p id="p375mcpsimp"><a name="p375mcpsimp"></a><a name="p375mcpsimp"></a><strong id="b1320314815620"><a name="b1320314815620"></a><a name="b1320314815620"></a>key</strong></p>
</th>
<th class="cellrowborder" valign="top" width="12.83%" id="mcps1.1.4.1.2"><p id="p377mcpsimp"><a name="p377mcpsimp"></a><a name="p377mcpsimp"></a><strong id="b17897537411"><a name="b17897537411"></a><a name="b17897537411"></a>Type</strong></p>
</th>
<th class="cellrowborder" valign="top" width="71.75%" id="mcps1.1.4.1.3"><p id="p379mcpsimp"><a name="p379mcpsimp"></a><a name="p379mcpsimp"></a><strong id="b78735539419"><a name="b78735539419"></a><a name="b78735539419"></a>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row380mcpsimp"><td class="cellrowborder" valign="top" width="15.42%" headers="mcps1.1.4.1.1 "><p id="p7162853112520"><a name="p7162853112520"></a><a name="p7162853112520"></a>accessibilityEnabled</p>
</td>
<td class="cellrowborder" valign="top" width="12.83%" headers="mcps1.1.4.1.2 "><p id="p384mcpsimp"><a name="p384mcpsimp"></a><a name="p384mcpsimp"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="71.75%" headers="mcps1.1.4.1.3 "><p id="p386mcpsimp"><a name="p386mcpsimp"></a><a name="p386mcpsimp"></a>Whether to enable accessibility.</p>
</td>
</tr>
<tr id="row387mcpsimp"><td class="cellrowborder" valign="top" width="15.42%" headers="mcps1.1.4.1.1 "><p id="p389mcpsimp"><a name="p389mcpsimp"></a><a name="p389mcpsimp"></a>colorMode</p>
</td>
<td class="cellrowborder" valign="top" width="12.83%" headers="mcps1.1.4.1.2 "><p id="p391mcpsimp"><a name="p391mcpsimp"></a><a name="p391mcpsimp"></a>ColorMode</p>
</td>
<td class="cellrowborder" valign="top" width="71.75%" headers="mcps1.1.4.1.3 "><p id="p897319423383"><a name="p897319423383"></a><a name="p897319423383"></a>Color mode. The options are as follows:</p>
<a name="ul11210147183818"></a><a name="ul11210147183818"></a><ul id="ul11210147183818"><li><strong id="b66184249423"><a name="b66184249423"></a><a name="b66184249423"></a>ColorMode.LIGHT</strong>: light mode.</li><li><strong id="b624204315422"><a name="b624204315422"></a><a name="b624204315422"></a>ColorMode.DARK</strong>: dark mode.</li></ul>
</td>
</tr>
<tr id="row394mcpsimp"><td class="cellrowborder" valign="top" width="15.42%" headers="mcps1.1.4.1.1 "><p id="p396mcpsimp"><a name="p396mcpsimp"></a><a name="p396mcpsimp"></a>fontScale</p>
</td>
<td class="cellrowborder" valign="top" width="12.83%" headers="mcps1.1.4.1.2 "><p id="p398mcpsimp"><a name="p398mcpsimp"></a><a name="p398mcpsimp"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="71.75%" headers="mcps1.1.4.1.3 "><p id="p400mcpsimp"><a name="p400mcpsimp"></a><a name="p400mcpsimp"></a>Font scale. The value range is [0.85, 1.45].</p>
</td>
</tr>
<tr id="row401mcpsimp"><td class="cellrowborder" valign="top" width="15.42%" headers="mcps1.1.4.1.1 "><p id="p778417357267"><a name="p778417357267"></a><a name="p778417357267"></a>fontWeightScale</p>
</td>
<td class="cellrowborder" valign="top" width="12.83%" headers="mcps1.1.4.1.2 "><p id="p405mcpsimp"><a name="p405mcpsimp"></a><a name="p405mcpsimp"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="71.75%" headers="mcps1.1.4.1.3 "><p id="p407mcpsimp"><a name="p407mcpsimp"></a><a name="p407mcpsimp"></a>Font weight scale. The value range is [0.6, 1.6].</p>
</td>
</tr>
<tr id="row408mcpsimp"><td class="cellrowborder" valign="top" width="15.42%" headers="mcps1.1.4.1.1 "><p id="p410mcpsimp"><a name="p410mcpsimp"></a><a name="p410mcpsimp"></a>layoutDirection</p>
</td>
<td class="cellrowborder" valign="top" width="12.83%" headers="mcps1.1.4.1.2 "><p id="p412mcpsimp"><a name="p412mcpsimp"></a><a name="p412mcpsimp"></a>LayoutDirection</p>
</td>
<td class="cellrowborder" valign="top" width="71.75%" headers="mcps1.1.4.1.3 "><p id="p549615347406"><a name="p549615347406"></a><a name="p549615347406"></a>Layout direction. The options are as follows:</p>
<a name="ul370513428408"></a><a name="ul370513428408"></a><ul id="ul370513428408"><li><strong id="b10904132124313"><a name="b10904132124313"></a><a name="b10904132124313"></a>LayoutDirection.LTR</strong>: The direction is from left to right.</li><li><strong id="b66711929174317"><a name="b66711929174317"></a><a name="b66711929174317"></a>LayoutDirection.RTL</strong>: The direction is from right to left.</li></ul>
</td>
</tr>
<tr id="row415mcpsimp"><td class="cellrowborder" valign="top" width="15.42%" headers="mcps1.1.4.1.1 "><p id="p417mcpsimp"><a name="p417mcpsimp"></a><a name="p417mcpsimp"></a>languageCode</p>
</td>
<td class="cellrowborder" valign="top" width="12.83%" headers="mcps1.1.4.1.2 "><p id="p419mcpsimp"><a name="p419mcpsimp"></a><a name="p419mcpsimp"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="71.75%" headers="mcps1.1.4.1.3 "><p id="p421mcpsimp"><a name="p421mcpsimp"></a><a name="p421mcpsimp"></a>Current system language. The value is in lowercase, for example, <strong id="b1455024519431"><a name="b1455024519431"></a><a name="b1455024519431"></a>zh</strong>.</p>
</td>
</tr>
</tbody>
</table>

