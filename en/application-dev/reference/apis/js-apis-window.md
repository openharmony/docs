# Window<a name="EN-US_TOPIC_0000001165276974"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import<a name="s56d19203690d4782bfc74069abb6bd71"></a>

```
import window from '@ohos.window';
```

## Required Permissions<a name="section11257113618419"></a>

ohos.permission.SYSTEM\_FLOAT\_WINDOW

## SystemBarProperties<a name="section6504105103120"></a>

Describes the properties of the status bar and navigation bar.

<a name="table1672925173717"></a>
<table><thead align="left"><tr id="row472225143713"><th class="cellrowborder" valign="top" width="29.349999999999998%" id="mcps1.1.6.1.1"><p id="p1872525113718"><a name="p1872525113718"></a><a name="p1872525113718"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="12.32%" id="mcps1.1.6.1.2"><p id="p272142513378"><a name="p272142513378"></a><a name="p272142513378"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="7.4399999999999995%" id="mcps1.1.6.1.3"><p id="p372112513717"><a name="p372112513717"></a><a name="p372112513717"></a>Readable</p>
</th>
<th class="cellrowborder" valign="top" width="9.89%" id="mcps1.1.6.1.4"><p id="p4731125133711"><a name="p4731125133711"></a><a name="p4731125133711"></a>Writable</p>
</th>
<th class="cellrowborder" valign="top" width="41%" id="mcps1.1.6.1.5"><p id="p3731625143714"><a name="p3731625143714"></a><a name="p3731625143714"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row14737257372"><td class="cellrowborder" valign="top" width="29.349999999999998%" headers="mcps1.1.6.1.1 "><p id="p14731125143713"><a name="p14731125143713"></a><a name="p14731125143713"></a>statusBarColor</p>
</td>
<td class="cellrowborder" valign="top" width="12.32%" headers="mcps1.1.6.1.2 "><p id="p2073192513373"><a name="p2073192513373"></a><a name="p2073192513373"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="7.4399999999999995%" headers="mcps1.1.6.1.3 "><p id="p973152514374"><a name="p973152514374"></a><a name="p973152514374"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="9.89%" headers="mcps1.1.6.1.4 "><p id="p1473625103717"><a name="p1473625103717"></a><a name="p1473625103717"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="41%" headers="mcps1.1.6.1.5 "><p id="p117352519378"><a name="p117352519378"></a><a name="p117352519378"></a>Color of the status bar. The color is a hexadecimal value, for example, <strong id="b7784147131316"><a name="b7784147131316"></a><a name="b7784147131316"></a>#00FF00</strong> or <strong id="b2784447161316"><a name="b2784447161316"></a><a name="b2784447161316"></a>#FF00FF00</strong>.</p>
</td>
</tr>
<tr id="row1294992812356"><td class="cellrowborder" valign="top" width="29.349999999999998%" headers="mcps1.1.6.1.1 "><p id="p829112508350"><a name="p829112508350"></a><a name="p829112508350"></a>isStatusBarLightIcon<sup id="sup1697865710211"><a name="sup1697865710211"></a><a name="sup1697865710211"></a>7+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="12.32%" headers="mcps1.1.6.1.2 "><p id="p1994982893517"><a name="p1994982893517"></a><a name="p1994982893517"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="7.4399999999999995%" headers="mcps1.1.6.1.3 "><p id="p194920288354"><a name="p194920288354"></a><a name="p194920288354"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="9.89%" headers="mcps1.1.6.1.4 "><p id="p595016285352"><a name="p595016285352"></a><a name="p595016285352"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="41%" headers="mcps1.1.6.1.5 "><p id="p79507281351"><a name="p79507281351"></a><a name="p79507281351"></a>Whether any icon on the status bar is highlighted.</p>
</td>
</tr>
<tr id="row97318254372"><td class="cellrowborder" valign="top" width="29.349999999999998%" headers="mcps1.1.6.1.1 "><p id="p157372511377"><a name="p157372511377"></a><a name="p157372511377"></a>navigationBarColor</p>
</td>
<td class="cellrowborder" valign="top" width="12.32%" headers="mcps1.1.6.1.2 "><p id="p13731625153714"><a name="p13731625153714"></a><a name="p13731625153714"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="7.4399999999999995%" headers="mcps1.1.6.1.3 "><p id="p4731025193718"><a name="p4731025193718"></a><a name="p4731025193718"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="9.89%" headers="mcps1.1.6.1.4 "><p id="p973202519378"><a name="p973202519378"></a><a name="p973202519378"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="41%" headers="mcps1.1.6.1.5 "><p id="p1873132553719"><a name="p1873132553719"></a><a name="p1873132553719"></a>Color of the navigation bar. The color is a hexadecimal value, for example, <strong id="b3146712181419"><a name="b3146712181419"></a><a name="b3146712181419"></a>#00FF00</strong> or <strong id="b101469126143"><a name="b101469126143"></a><a name="b101469126143"></a>#FF00FF00</strong>.</p>
</td>
</tr>
<tr id="row2537443350"><td class="cellrowborder" valign="top" width="29.349999999999998%" headers="mcps1.1.6.1.1 "><p id="p185371342355"><a name="p185371342355"></a><a name="p185371342355"></a>isNavigationBarLightIcon<sup id="sup1496314591426"><a name="sup1496314591426"></a><a name="sup1496314591426"></a>7+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="12.32%" headers="mcps1.1.6.1.2 "><p id="p135374433520"><a name="p135374433520"></a><a name="p135374433520"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="7.4399999999999995%" headers="mcps1.1.6.1.3 "><p id="p1953717414351"><a name="p1953717414351"></a><a name="p1953717414351"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="9.89%" headers="mcps1.1.6.1.4 "><p id="p05373463512"><a name="p05373463512"></a><a name="p05373463512"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="41%" headers="mcps1.1.6.1.5 "><p id="p155371148351"><a name="p155371148351"></a><a name="p155371148351"></a>Whether any icon on the navigation bar is highlighted.</p>
</td>
</tr>
</tbody>
</table>

## Rect<sup>7+</sup><a name="section763793512569"></a>

Describes a rectangle.

<a name="table1863793512562"></a>
<table><thead align="left"><tr id="row363814351563"><th class="cellrowborder" valign="top" width="19.46%" id="mcps1.1.6.1.1"><p id="p11638113575615"><a name="p11638113575615"></a><a name="p11638113575615"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="19.02%" id="mcps1.1.6.1.2"><p id="p17638173516566"><a name="p17638173516566"></a><a name="p17638173516566"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="6.84%" id="mcps1.1.6.1.3"><p id="p1363833517563"><a name="p1363833517563"></a><a name="p1363833517563"></a>Readable</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.6.1.4"><p id="p1463820355564"><a name="p1463820355564"></a><a name="p1463820355564"></a>Writable</p>
</th>
<th class="cellrowborder" valign="top" width="47.160000000000004%" id="mcps1.1.6.1.5"><p id="p9638103555611"><a name="p9638103555611"></a><a name="p9638103555611"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row7638143505619"><td class="cellrowborder" valign="top" width="19.46%" headers="mcps1.1.6.1.1 "><p id="p0909425125713"><a name="p0909425125713"></a><a name="p0909425125713"></a>left</p>
</td>
<td class="cellrowborder" valign="top" width="19.02%" headers="mcps1.1.6.1.2 "><p id="p6638163514562"><a name="p6638163514562"></a><a name="p6638163514562"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="6.84%" headers="mcps1.1.6.1.3 "><p id="p7638153515617"><a name="p7638153515617"></a><a name="p7638153515617"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p363912352563"><a name="p363912352563"></a><a name="p363912352563"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="47.160000000000004%" headers="mcps1.1.6.1.5 "><p id="p17639113555612"><a name="p17639113555612"></a><a name="p17639113555612"></a>Left boundary of the rectangle.</p>
</td>
</tr>
<tr id="row1363973520565"><td class="cellrowborder" valign="top" width="19.46%" headers="mcps1.1.6.1.1 "><p id="p4639133512562"><a name="p4639133512562"></a><a name="p4639133512562"></a>top</p>
</td>
<td class="cellrowborder" valign="top" width="19.02%" headers="mcps1.1.6.1.2 "><p id="p27981540185715"><a name="p27981540185715"></a><a name="p27981540185715"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="6.84%" headers="mcps1.1.6.1.3 "><p id="p146391335105618"><a name="p146391335105618"></a><a name="p146391335105618"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p36392353561"><a name="p36392353561"></a><a name="p36392353561"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="47.160000000000004%" headers="mcps1.1.6.1.5 "><p id="p14639435155614"><a name="p14639435155614"></a><a name="p14639435155614"></a>Top boundary of the rectangle.</p>
</td>
</tr>
<tr id="row663933520563"><td class="cellrowborder" valign="top" width="19.46%" headers="mcps1.1.6.1.1 "><p id="p1663943535617"><a name="p1663943535617"></a><a name="p1663943535617"></a>width</p>
</td>
<td class="cellrowborder" valign="top" width="19.02%" headers="mcps1.1.6.1.2 "><p id="p1784111409570"><a name="p1784111409570"></a><a name="p1784111409570"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="6.84%" headers="mcps1.1.6.1.3 "><p id="p1763918352569"><a name="p1763918352569"></a><a name="p1763918352569"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p1163993510564"><a name="p1163993510564"></a><a name="p1163993510564"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="47.160000000000004%" headers="mcps1.1.6.1.5 "><p id="p7639143585615"><a name="p7639143585615"></a><a name="p7639143585615"></a>Width of the rectangle.</p>
</td>
</tr>
<tr id="row364083555620"><td class="cellrowborder" valign="top" width="19.46%" headers="mcps1.1.6.1.1 "><p id="p26401335115612"><a name="p26401335115612"></a><a name="p26401335115612"></a>height</p>
</td>
<td class="cellrowborder" valign="top" width="19.02%" headers="mcps1.1.6.1.2 "><p id="p18812401574"><a name="p18812401574"></a><a name="p18812401574"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="6.84%" headers="mcps1.1.6.1.3 "><p id="p166407355563"><a name="p166407355563"></a><a name="p166407355563"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p7640123513565"><a name="p7640123513565"></a><a name="p7640123513565"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="47.160000000000004%" headers="mcps1.1.6.1.5 "><p id="p6640193575614"><a name="p6640193575614"></a><a name="p6640193575614"></a>Height of the rectangle.</p>
</td>
</tr>
</tbody>
</table>

## AvoidArea<sup>7+</sup><a name="section74393271254"></a>

Describes the area where the window cannot be displayed.

<a name="table1944014278510"></a>

<table><thead align="left"><tr id="row0440172711515"><th class="cellrowborder" valign="top" width="19.46%" id="mcps1.1.6.1.1"><p id="p1444017272516"><a name="p1444017272516"></a><a name="p1444017272516"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="19.02%" id="mcps1.1.6.1.2"><p id="p244013271852"><a name="p244013271852"></a><a name="p244013271852"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="6.84%" id="mcps1.1.6.1.3"><p id="p134411327257"><a name="p134411327257"></a><a name="p134411327257"></a>Readable</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.6.1.4"><p id="p18441327857"><a name="p18441327857"></a><a name="p18441327857"></a>Writable</p>
</th>
<th class="cellrowborder" valign="top" width="47.160000000000004%" id="mcps1.1.6.1.5"><p id="p1144116277515"><a name="p1144116277515"></a><a name="p1144116277515"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1944112271758"><td class="cellrowborder" valign="top" width="19.46%" headers="mcps1.1.6.1.1 "><p id="p9441132715519"><a name="p9441132715519"></a><a name="p9441132715519"></a>leftRect</p>
</td>
<td class="cellrowborder" valign="top" width="19.02%" headers="mcps1.1.6.1.2 "><p id="p164419277514"><a name="p164419277514"></a><a name="p164419277514"></a><a href="#section763793512569">Rect</a></p>
</td>
<td class="cellrowborder" valign="top" width="6.84%" headers="mcps1.1.6.1.3 "><p id="p644117275511"><a name="p644117275511"></a><a name="p644117275511"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p1444152718520"><a name="p1444152718520"></a><a name="p1444152718520"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="47.160000000000004%" headers="mcps1.1.6.1.5 "><p id="p1441152713512"><a name="p1441152713512"></a><a name="p1441152713512"></a>Rectangle on the left of the screen.</p>
</td>
</tr>
<tr id="row744172718519"><td class="cellrowborder" valign="top" width="19.46%" headers="mcps1.1.6.1.1 "><p id="p2441182715518"><a name="p2441182715518"></a><a name="p2441182715518"></a>topRect</p>
</td>
<td class="cellrowborder" valign="top" width="19.02%" headers="mcps1.1.6.1.2 "><p id="p525185213820"><a name="p525185213820"></a><a name="p525185213820"></a><a href="#section763793512569">Rect</a></p>
</td>
<td class="cellrowborder" valign="top" width="6.84%" headers="mcps1.1.6.1.3 "><p id="p1144216271354"><a name="p1144216271354"></a><a name="p1144216271354"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p2044217271158"><a name="p2044217271158"></a><a name="p2044217271158"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="47.160000000000004%" headers="mcps1.1.6.1.5 "><p id="p134425275514"><a name="p134425275514"></a><a name="p134425275514"></a>Rectangle at the top of the screen.</p>
</td>
</tr>
<tr id="row144423271351"><td class="cellrowborder" valign="top" width="19.46%" headers="mcps1.1.6.1.1 "><p id="p174424276516"><a name="p174424276516"></a><a name="p174424276516"></a>rightRect</p>
</td>
<td class="cellrowborder" valign="top" width="19.02%" headers="mcps1.1.6.1.2 "><p id="p158295215817"><a name="p158295215817"></a><a name="p158295215817"></a><a href="#section763793512569">Rect</a></p>
</td>
<td class="cellrowborder" valign="top" width="6.84%" headers="mcps1.1.6.1.3 "><p id="p16442122720515"><a name="p16442122720515"></a><a name="p16442122720515"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p16442192714511"><a name="p16442192714511"></a><a name="p16442192714511"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="47.160000000000004%" headers="mcps1.1.6.1.5 "><p id="p34426271959"><a name="p34426271959"></a><a name="p34426271959"></a>Rectangle on the right of the screen.</p>
</td>
</tr>
<tr id="row1544212271055"><td class="cellrowborder" valign="top" width="19.46%" headers="mcps1.1.6.1.1 "><p id="p54428271355"><a name="p54428271355"></a><a name="p54428271355"></a>bottomRect</p>
</td>
<td class="cellrowborder" valign="top" width="19.02%" headers="mcps1.1.6.1.2 "><p id="p013713521486"><a name="p013713521486"></a><a name="p013713521486"></a><a href="#section763793512569">Rect</a></p>
</td>
<td class="cellrowborder" valign="top" width="6.84%" headers="mcps1.1.6.1.3 "><p id="p1244332712516"><a name="p1244332712516"></a><a name="p1244332712516"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p1244342715511"><a name="p1244342715511"></a><a name="p1244342715511"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="47.160000000000004%" headers="mcps1.1.6.1.5 "><p id="p54435278519"><a name="p54435278519"></a><a name="p54435278519"></a>Rectangle at the bottom of the screen.</p>
</td>
</tr>
</tbody>
</table>

## Size<sup>7+</sup><a name="section695585431120"></a>

Describes the window size.

<a name="table1495675491116"></a>
<table><thead align="left"><tr id="row8956454121120"><th class="cellrowborder" valign="top" width="19.46%" id="mcps1.1.6.1.1"><p id="p5956185461117"><a name="p5956185461117"></a><a name="p5956185461117"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="19.02%" id="mcps1.1.6.1.2"><p id="p14956854171113"><a name="p14956854171113"></a><a name="p14956854171113"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="6.84%" id="mcps1.1.6.1.3"><p id="p295613546115"><a name="p295613546115"></a><a name="p295613546115"></a>Readable</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.6.1.4"><p id="p129561254161111"><a name="p129561254161111"></a><a name="p129561254161111"></a>Writable</p>
</th>
<th class="cellrowborder" valign="top" width="47.160000000000004%" id="mcps1.1.6.1.5"><p id="p2957354191115"><a name="p2957354191115"></a><a name="p2957354191115"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row295785414114"><td class="cellrowborder" valign="top" width="19.46%" headers="mcps1.1.6.1.1 "><p id="p159502211127"><a name="p159502211127"></a><a name="p159502211127"></a>width</p>
</td>
<td class="cellrowborder" valign="top" width="19.02%" headers="mcps1.1.6.1.2 "><p id="p695012121210"><a name="p695012121210"></a><a name="p695012121210"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="6.84%" headers="mcps1.1.6.1.3 "><p id="p19501221121213"><a name="p19501221121213"></a><a name="p19501221121213"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p159501821141211"><a name="p159501821141211"></a><a name="p159501821141211"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="47.160000000000004%" headers="mcps1.1.6.1.5 "><p id="p195710547114"><a name="p195710547114"></a><a name="p195710547114"></a>Window width.</p>
</td>
</tr>
<tr id="row19957654121113"><td class="cellrowborder" valign="top" width="19.46%" headers="mcps1.1.6.1.1 "><p id="p69503217122"><a name="p69503217122"></a><a name="p69503217122"></a>height</p>
</td>
<td class="cellrowborder" valign="top" width="19.02%" headers="mcps1.1.6.1.2 "><p id="p1595072113125"><a name="p1595072113125"></a><a name="p1595072113125"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="6.84%" headers="mcps1.1.6.1.3 "><p id="p16950182116121"><a name="p16950182116121"></a><a name="p16950182116121"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p1795052118124"><a name="p1795052118124"></a><a name="p1795052118124"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="47.160000000000004%" headers="mcps1.1.6.1.5 "><p id="p1195815414117"><a name="p1195815414117"></a><a name="p1195815414117"></a>Window height.</p>
</td>
</tr>
</tbody>
</table>

## WindowProperties<a name="section037811361536"></a>

Describes the window properties.

<a name="table1037813617312"></a>
<table><thead align="left"><tr id="row6379203613317"><th class="cellrowborder" valign="top" width="21.89%" id="mcps1.1.6.1.1"><p id="p1937919361836"><a name="p1937919361836"></a><a name="p1937919361836"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="17.27%" id="mcps1.1.6.1.2"><p id="p1737993617310"><a name="p1737993617310"></a><a name="p1737993617310"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="8.52%" id="mcps1.1.6.1.3"><p id="p93792361533"><a name="p93792361533"></a><a name="p93792361533"></a>Readable</p>
</th>
<th class="cellrowborder" valign="top" width="7.2700000000000005%" id="mcps1.1.6.1.4"><p id="p937914361033"><a name="p937914361033"></a><a name="p937914361033"></a>Writable</p>
</th>
<th class="cellrowborder" valign="top" width="45.050000000000004%" id="mcps1.1.6.1.5"><p id="p173791836333"><a name="p173791836333"></a><a name="p173791836333"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row6560173510364"><td class="cellrowborder" valign="top" width="21.89%" headers="mcps1.1.6.1.1 "><p id="p1256093517367"><a name="p1256093517367"></a><a name="p1256093517367"></a>windowRect<sup id="sup18371539909"><a name="sup18371539909"></a><a name="sup18371539909"></a>7+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="17.27%" headers="mcps1.1.6.1.2 "><p id="p12560133523618"><a name="p12560133523618"></a><a name="p12560133523618"></a><a href="#section763793512569">Rect</a></p>
</td>
<td class="cellrowborder" valign="top" width="8.52%" headers="mcps1.1.6.1.3 "><p id="p175604357360"><a name="p175604357360"></a><a name="p175604357360"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="7.2700000000000005%" headers="mcps1.1.6.1.4 "><p id="p13560153520360"><a name="p13560153520360"></a><a name="p13560153520360"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="45.050000000000004%" headers="mcps1.1.6.1.5 "><p id="p1556063513361"><a name="p1556063513361"></a><a name="p1556063513361"></a>Window size.</p>
</td>
</tr>
<tr id="row1571373313368"><td class="cellrowborder" valign="top" width="21.89%" headers="mcps1.1.6.1.1 "><p id="p16714103315368"><a name="p16714103315368"></a><a name="p16714103315368"></a>type<sup id="sup229223182811"><a name="sup229223182811"></a><a name="sup229223182811"></a>7+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="17.27%" headers="mcps1.1.6.1.2 "><p id="p971413353619"><a name="p971413353619"></a><a name="p971413353619"></a><a href="#section099619567453">WindowType</a></p>
</td>
<td class="cellrowborder" valign="top" width="8.52%" headers="mcps1.1.6.1.3 "><p id="p137141133163611"><a name="p137141133163611"></a><a name="p137141133163611"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="7.2700000000000005%" headers="mcps1.1.6.1.4 "><p id="p12714633123616"><a name="p12714633123616"></a><a name="p12714633123616"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="45.050000000000004%" headers="mcps1.1.6.1.5 "><p id="p207140331365"><a name="p207140331365"></a><a name="p207140331365"></a>Window type.</p>
</td>
</tr>
<tr id="row7379153615310"><td class="cellrowborder" valign="top" width="21.89%" headers="mcps1.1.6.1.1 "><p id="p43797361332"><a name="p43797361332"></a><a name="p43797361332"></a>brightness</p>
</td>
<td class="cellrowborder" valign="top" width="17.27%" headers="mcps1.1.6.1.2 "><p id="p637917362313"><a name="p637917362313"></a><a name="p637917362313"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.52%" headers="mcps1.1.6.1.3 "><p id="p7379236033"><a name="p7379236033"></a><a name="p7379236033"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="7.2700000000000005%" headers="mcps1.1.6.1.4 "><p id="p1537923616313"><a name="p1537923616313"></a><a name="p1537923616313"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="45.050000000000004%" headers="mcps1.1.6.1.5 "><p id="p43796361033"><a name="p43796361033"></a><a name="p43796361033"></a>Screen brightness. The value ranges from 0 to 1. The value <strong id="b8875123215188"><a name="b8875123215188"></a><a name="b8875123215188"></a>1</strong> indicates the maximum brightness.</p>
</td>
</tr>
<tr id="row28211038193812"><td class="cellrowborder" valign="top" width="21.89%" headers="mcps1.1.6.1.1 "><p id="p1112735425118"><a name="p1112735425118"></a><a name="p1112735425118"></a>isTransparent<sup id="sup62835241034"><a name="sup62835241034"></a><a name="sup62835241034"></a>7+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="17.27%" headers="mcps1.1.6.1.2 "><p id="p582113814384"><a name="p582113814384"></a><a name="p582113814384"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="8.52%" headers="mcps1.1.6.1.3 "><p id="p14450113819161"><a name="p14450113819161"></a><a name="p14450113819161"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="7.2700000000000005%" headers="mcps1.1.6.1.4 "><p id="p18450103815168"><a name="p18450103815168"></a><a name="p18450103815168"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="45.050000000000004%" headers="mcps1.1.6.1.5 "><p id="p2082113863810"><a name="p2082113863810"></a><a name="p2082113863810"></a>Whether the window is transparent. The default value is <strong id="b1642334017184"><a name="b1642334017184"></a><a name="b1642334017184"></a>false</strong>.</p>
</td>
</tr>
<tr id="row15379173617317"><td class="cellrowborder" valign="top" width="21.89%" headers="mcps1.1.6.1.1 "><p id="p8379736535"><a name="p8379736535"></a><a name="p8379736535"></a>isFullScreen</p>
</td>
<td class="cellrowborder" valign="top" width="17.27%" headers="mcps1.1.6.1.2 "><p id="p537913616313"><a name="p537913616313"></a><a name="p537913616313"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="8.52%" headers="mcps1.1.6.1.3 "><p id="p93799361739"><a name="p93799361739"></a><a name="p93799361739"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="7.2700000000000005%" headers="mcps1.1.6.1.4 "><p id="p13792364320"><a name="p13792364320"></a><a name="p13792364320"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="45.050000000000004%" headers="mcps1.1.6.1.5 "><p id="p43792362032"><a name="p43792362032"></a><a name="p43792362032"></a>Whether the window is displayed in full screen mode. The default value is <strong id="b153301545181820"><a name="b153301545181820"></a><a name="b153301545181820"></a>false</strong>.</p>
</td>
</tr>
<tr id="row2621493413"><td class="cellrowborder" valign="top" width="21.89%" headers="mcps1.1.6.1.1 "><p id="p5621391541"><a name="p5621391541"></a><a name="p5621391541"></a>isKeepScreenOn</p>
</td>
<td class="cellrowborder" valign="top" width="17.27%" headers="mcps1.1.6.1.2 "><p id="p116211914416"><a name="p116211914416"></a><a name="p116211914416"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="8.52%" headers="mcps1.1.6.1.3 "><p id="p4621391645"><a name="p4621391645"></a><a name="p4621391645"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="7.2700000000000005%" headers="mcps1.1.6.1.4 "><p id="p2062118912416"><a name="p2062118912416"></a><a name="p2062118912416"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="45.050000000000004%" headers="mcps1.1.6.1.5 "><p id="p1762112911415"><a name="p1762112911415"></a><a name="p1762112911415"></a>Whether the screen is always on. The default value is <strong id="b4391175111811"><a name="b4391175111811"></a><a name="b4391175111811"></a>false</strong>.</p>
</td>
</tr>
<tr id="row63895155185"><td class="cellrowborder" valign="top" width="21.89%" headers="mcps1.1.6.1.1 "><p id="p1738981514187"><a name="p1738981514187"></a><a name="p1738981514187"></a>dimBehindValue<sup id="sup151491219649"><a name="sup151491219649"></a><a name="sup151491219649"></a>7+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="17.27%" headers="mcps1.1.6.1.2 "><p id="p735312862012"><a name="p735312862012"></a><a name="p735312862012"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.52%" headers="mcps1.1.6.1.3 "><p id="p155402842010"><a name="p155402842010"></a><a name="p155402842010"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="7.2700000000000005%" headers="mcps1.1.6.1.4 "><p id="p135541728162018"><a name="p135541728162018"></a><a name="p135541728162018"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="45.050000000000004%" headers="mcps1.1.6.1.5 "><p id="p23907151189"><a name="p23907151189"></a><a name="p23907151189"></a>Dimness of the window that is not on top. The value ranges from 0 to 1. The value <strong id="b17305145816188"><a name="b17305145816188"></a><a name="b17305145816188"></a>1</strong> indicates the maximum dimness.</p>
</td>
</tr>
<tr id="row1837612318185"><td class="cellrowborder" valign="top" width="21.89%" headers="mcps1.1.6.1.1 "><p id="p10376172301815"><a name="p10376172301815"></a><a name="p10376172301815"></a>isLayoutFullScreen<sup id="sup524015528412"><a name="sup524015528412"></a><a name="sup524015528412"></a>7+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="17.27%" headers="mcps1.1.6.1.2 "><p id="p84042811208"><a name="p84042811208"></a><a name="p84042811208"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="8.52%" headers="mcps1.1.6.1.3 "><p id="p2019833116204"><a name="p2019833116204"></a><a name="p2019833116204"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="7.2700000000000005%" headers="mcps1.1.6.1.4 "><p id="p219833152013"><a name="p219833152013"></a><a name="p219833152013"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="45.050000000000004%" headers="mcps1.1.6.1.5 "><p id="p6377142311810"><a name="p6377142311810"></a><a name="p6377142311810"></a>Whether the window layout is in full-screen mode (whether the window is immersive). The default value is <strong id="b48410512195"><a name="b48410512195"></a><a name="b48410512195"></a>false</strong>.</p>
</td>
</tr>
<tr id="row162541726111811"><td class="cellrowborder" valign="top" width="21.89%" headers="mcps1.1.6.1.1 "><p id="p6255112614185"><a name="p6255112614185"></a><a name="p6255112614185"></a>focusable<sup id="sup18119135119516"><a name="sup18119135119516"></a><a name="sup18119135119516"></a>7+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="17.27%" headers="mcps1.1.6.1.2 "><p id="p1645619814208"><a name="p1645619814208"></a><a name="p1645619814208"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="8.52%" headers="mcps1.1.6.1.3 "><p id="p1767563482016"><a name="p1767563482016"></a><a name="p1767563482016"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="7.2700000000000005%" headers="mcps1.1.6.1.4 "><p id="p9675163482010"><a name="p9675163482010"></a><a name="p9675163482010"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="45.050000000000004%" headers="mcps1.1.6.1.5 "><p id="p13255192631813"><a name="p13255192631813"></a><a name="p13255192631813"></a>Whether the window can gain focus. The default value is <strong id="b1362618186193"><a name="b1362618186193"></a><a name="b1362618186193"></a>true</strong>.</p>
</td>
</tr>
<tr id="row11359142011189"><td class="cellrowborder" valign="top" width="21.89%" headers="mcps1.1.6.1.1 "><p id="p7359620191812"><a name="p7359620191812"></a><a name="p7359620191812"></a>touchable<sup id="sup10179531053"><a name="sup10179531053"></a><a name="sup10179531053"></a>7+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="17.27%" headers="mcps1.1.6.1.2 "><p id="p1508118162017"><a name="p1508118162017"></a><a name="p1508118162017"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="8.52%" headers="mcps1.1.6.1.3 "><p id="p38031738182010"><a name="p38031738182010"></a><a name="p38031738182010"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="7.2700000000000005%" headers="mcps1.1.6.1.4 "><p id="p18803183818208"><a name="p18803183818208"></a><a name="p18803183818208"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="45.050000000000004%" headers="mcps1.1.6.1.5 "><p id="p12359202081810"><a name="p12359202081810"></a><a name="p12359202081810"></a>Whether the window is touchable. The default value is <strong id="b19411182361913"><a name="b19411182361913"></a><a name="b19411182361913"></a>true</strong>.</p>
</td>
</tr>
<tr id="row12781131742116"><td class="cellrowborder" valign="top" width="21.89%" headers="mcps1.1.6.1.1 "><p id="p878221713212"><a name="p878221713212"></a><a name="p878221713212"></a>isPrivacyMode<sup id="sup567125512511"><a name="sup567125512511"></a><a name="sup567125512511"></a>7+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="17.27%" headers="mcps1.1.6.1.2 "><p id="p5873953182118"><a name="p5873953182118"></a><a name="p5873953182118"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="8.52%" headers="mcps1.1.6.1.3 "><p id="p2087311534218"><a name="p2087311534218"></a><a name="p2087311534218"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="7.2700000000000005%" headers="mcps1.1.6.1.4 "><p id="p12873165315217"><a name="p12873165315217"></a><a name="p12873165315217"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="45.050000000000004%" headers="mcps1.1.6.1.5 "><p id="p17782117122117"><a name="p17782117122117"></a><a name="p17782117122117"></a>Whether the window is in privacy mode. The default value is <strong id="b506283192"><a name="b506283192"></a><a name="b506283192"></a>false</strong>.</p>
</td>
</tr>
<tr id="row011017135211"><td class="cellrowborder" valign="top" width="21.89%" headers="mcps1.1.6.1.1 "><p id="p3111111362117"><a name="p3111111362117"></a><a name="p3111111362117"></a>isRoundCorner<sup id="sup59916168010"><a name="sup59916168010"></a><a name="sup59916168010"></a>7+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="17.27%" headers="mcps1.1.6.1.2 "><p id="p138731453122113"><a name="p138731453122113"></a><a name="p138731453122113"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="8.52%" headers="mcps1.1.6.1.3 "><p id="p188731753162116"><a name="p188731753162116"></a><a name="p188731753162116"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="7.2700000000000005%" headers="mcps1.1.6.1.4 "><p id="p48731553182119"><a name="p48731553182119"></a><a name="p48731553182119"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="45.050000000000004%" headers="mcps1.1.6.1.5 "><p id="p181111013192110"><a name="p181111013192110"></a><a name="p181111013192110"></a>Whether the window has rounded corners.</p>
</td>
</tr>
</tbody>
</table>

## SplitScreenBoundsInfo<sup>7+</sup><a name="section15380136104815"></a>

Describes information about the split-screen boundary.

<a name="table6380113619482"></a>
<table><thead align="left"><tr id="row11381836144817"><th class="cellrowborder" valign="top" width="27.900000000000002%" id="mcps1.1.4.1.1"><p id="p13381133612481"><a name="p13381133612481"></a><a name="p13381133612481"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="12.43%" id="mcps1.1.4.1.2"><p id="p93819363482"><a name="p93819363482"></a><a name="p93819363482"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="59.67%" id="mcps1.1.4.1.3"><p id="p2381536124818"><a name="p2381536124818"></a><a name="p2381536124818"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2381153614817"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p03812367483"><a name="p03812367483"></a><a name="p03812367483"></a><a href="#section1398211585344">splitMode7+</a></p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p123811236124818"><a name="p123811236124818"></a><a name="p123811236124818"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p12381103619489"><a name="p12381103619489"></a><a name="p12381103619489"></a>Split-screen mode.</p>
</td>
</tr>
<tr id="row0382163619489"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p16382203610486"><a name="p16382203610486"></a><a name="p16382203610486"></a>primaryBounds</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p976522218489"><a name="p976522218489"></a><a name="p976522218489"></a><a href="#section763793512569">Rect</a></p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p20382163615488"><a name="p20382163615488"></a><a name="p20382163615488"></a>Primary window boundary information, which is in the format of a <strong id="b14898114431917"><a name="b14898114431917"></a><a name="b14898114431917"></a>Rect</strong> instance.</p>
</td>
</tr>
<tr id="row173821136144818"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p2382133614812"><a name="p2382133614812"></a><a name="p2382133614812"></a>secondaryBounds</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p525372094811"><a name="p525372094811"></a><a name="p525372094811"></a><a href="#section763793512569">Rect</a></p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p340122975717"><a name="p340122975717"></a><a name="p340122975717"></a>Secondary window boundary information, which is in the format of a <strong id="b1031864921914"><a name="b1031864921914"></a><a name="b1031864921914"></a>Rect</strong> instance.</p>
</td>
</tr>
</tbody>
</table>

## window.getTopWindow<a name="section39061940191"></a>

getTopWindow\(callback: AsyncCallback<Window\>\): void

Obtains a  **Window**  instance.

-   Parameters

    <a name="table7573104221913"></a>
    <table><thead align="left"><tr id="row057415426191"><th class="cellrowborder" valign="top" width="11.21%" id="mcps1.1.5.1.1"><p id="p15749421191"><a name="p15749421191"></a><a name="p15749421191"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="30.159999999999997%" id="mcps1.1.5.1.2"><p id="p1357424291920"><a name="p1357424291920"></a><a name="p1357424291920"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="5.2299999999999995%" id="mcps1.1.5.1.3"><p id="p2574174211193"><a name="p2574174211193"></a><a name="p2574174211193"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="53.400000000000006%" id="mcps1.1.5.1.4"><p id="p1157414261911"><a name="p1157414261911"></a><a name="p1157414261911"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row557454291919"><td class="cellrowborder" valign="top" width="11.21%" headers="mcps1.1.5.1.1 "><p id="p10574134210197"><a name="p10574134210197"></a><a name="p10574134210197"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="30.159999999999997%" headers="mcps1.1.5.1.2 "><p id="p557414424197"><a name="p557414424197"></a><a name="p557414424197"></a>AsyncCallback&lt;<a href="#section122477411428">Window</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="5.2299999999999995%" headers="mcps1.1.5.1.3 "><p id="p257415425193"><a name="p257415425193"></a><a name="p257415425193"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="53.400000000000006%" headers="mcps1.1.5.1.4 "><p id="p6574174214198"><a name="p6574174214198"></a><a name="p6574174214198"></a>Callback used to return the current <strong id="b1260115322018"><a name="b1260115322018"></a><a name="b1260115322018"></a>Window</strong> object.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    window.getTopWindow((err, data) => {
        if (err) {
            console.error('Failed to obtain the top window. Cause: ' + JSON.stringify(err));
            return;
        }
        console.info('Succeeded in obtaining the top window. Data: ' + JSON.stringify(data));
        windowClass = data;
    });
    ```


## window.create<sup>7+</sup><a name="section115771918111115"></a>

create\(id: string, type: WindowType, callback: AsyncCallback<Window\>\): void

Creates a subwindow.

-   Parameters

    <a name="table1157891831112"></a>
    <table><thead align="left"><tr id="row557821814112"><th class="cellrowborder" valign="top" width="11.21%" id="mcps1.1.5.1.1"><p id="p457819189114"><a name="p457819189114"></a><a name="p457819189114"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="30.159999999999997%" id="mcps1.1.5.1.2"><p id="p18578191861114"><a name="p18578191861114"></a><a name="p18578191861114"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="5.2299999999999995%" id="mcps1.1.5.1.3"><p id="p6578151891117"><a name="p6578151891117"></a><a name="p6578151891117"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="53.400000000000006%" id="mcps1.1.5.1.4"><p id="p4578131818111"><a name="p4578131818111"></a><a name="p4578131818111"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row125783151720"><td class="cellrowborder" valign="top" width="11.21%" headers="mcps1.1.5.1.1 "><p id="p155784121719"><a name="p155784121719"></a><a name="p155784121719"></a>id</p>
    </td>
    <td class="cellrowborder" valign="top" width="30.159999999999997%" headers="mcps1.1.5.1.2 "><p id="p157871171711"><a name="p157871171711"></a><a name="p157871171711"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="5.2299999999999995%" headers="mcps1.1.5.1.3 "><p id="p157816118173"><a name="p157816118173"></a><a name="p157816118173"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="53.400000000000006%" headers="mcps1.1.5.1.4 "><p id="p1557819161715"><a name="p1557819161715"></a><a name="p1557819161715"></a>Window ID.</p>
    </td>
    </tr>
    <tr id="row342612580162"><td class="cellrowborder" valign="top" width="11.21%" headers="mcps1.1.5.1.1 "><p id="p1342665831612"><a name="p1342665831612"></a><a name="p1342665831612"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="30.159999999999997%" headers="mcps1.1.5.1.2 "><p id="p542610587167"><a name="p542610587167"></a><a name="p542610587167"></a><a href="#section099619567453">WindowType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="5.2299999999999995%" headers="mcps1.1.5.1.3 "><p id="p114261758121618"><a name="p114261758121618"></a><a name="p114261758121618"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="53.400000000000006%" headers="mcps1.1.5.1.4 "><p id="p16427185813162"><a name="p16427185813162"></a><a name="p16427185813162"></a>Window type.</p>
    </td>
    </tr>
    <tr id="row357951811118"><td class="cellrowborder" valign="top" width="11.21%" headers="mcps1.1.5.1.1 "><p id="p185791186115"><a name="p185791186115"></a><a name="p185791186115"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="30.159999999999997%" headers="mcps1.1.5.1.2 "><p id="p557915188112"><a name="p557915188112"></a><a name="p557915188112"></a>AsyncCallback&lt;<a href="#section122477411428">Window</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="5.2299999999999995%" headers="mcps1.1.5.1.3 "><p id="p85791918171115"><a name="p85791918171115"></a><a name="p85791918171115"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="53.400000000000006%" headers="mcps1.1.5.1.4 "><p id="p2579111851120"><a name="p2579111851120"></a><a name="p2579111851120"></a>Callback used to return the current <strong id="b4313162812015"><a name="b4313162812015"></a><a name="b4313162812015"></a>Window</strong> object.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

```
 window.create("first", 1, (err, data) => {
    windowClass = data;
    if (err) {
        console.error('Failed to create the subWindow. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('SubWindow created. Data: ' + JSON.stringify(data))
    windowClass.resetSize(500, 1000);
    windowClass.setOutsideTouchable(true);
    windowClass.loadContent("pages/index/index", (err, data) => {
   });
})
```

## window.find<sup>7+</sup><a name="section162151923192416"></a>

find\(id: string, callback: AsyncCallback<Window\>\): void

Finds a subwindow.

-   Parameters

    <a name="table18216142320241"></a>
    <table><thead align="left"><tr id="row13217923162412"><th class="cellrowborder" valign="top" width="11.21%" id="mcps1.1.5.1.1"><p id="p6217112320243"><a name="p6217112320243"></a><a name="p6217112320243"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="30.159999999999997%" id="mcps1.1.5.1.2"><p id="p121715232246"><a name="p121715232246"></a><a name="p121715232246"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="5.2299999999999995%" id="mcps1.1.5.1.3"><p id="p18217102322416"><a name="p18217102322416"></a><a name="p18217102322416"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="53.400000000000006%" id="mcps1.1.5.1.4"><p id="p6217122310249"><a name="p6217122310249"></a><a name="p6217122310249"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row021762316244"><td class="cellrowborder" valign="top" width="11.21%" headers="mcps1.1.5.1.1 "><p id="p4217182315243"><a name="p4217182315243"></a><a name="p4217182315243"></a>id</p>
    </td>
    <td class="cellrowborder" valign="top" width="30.159999999999997%" headers="mcps1.1.5.1.2 "><p id="p8218102313247"><a name="p8218102313247"></a><a name="p8218102313247"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="5.2299999999999995%" headers="mcps1.1.5.1.3 "><p id="p172182233241"><a name="p172182233241"></a><a name="p172182233241"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="53.400000000000006%" headers="mcps1.1.5.1.4 "><p id="p4218132322417"><a name="p4218132322417"></a><a name="p4218132322417"></a>Window ID.</p>
    </td>
    </tr>
    <tr id="row15219192316247"><td class="cellrowborder" valign="top" width="11.21%" headers="mcps1.1.5.1.1 "><p id="p5219162382413"><a name="p5219162382413"></a><a name="p5219162382413"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="30.159999999999997%" headers="mcps1.1.5.1.2 "><p id="p2219723112417"><a name="p2219723112417"></a><a name="p2219723112417"></a>AsyncCallback&lt;<a href="#section122477411428">Window</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="5.2299999999999995%" headers="mcps1.1.5.1.3 "><p id="p13219202362415"><a name="p13219202362415"></a><a name="p13219202362415"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="53.400000000000006%" headers="mcps1.1.5.1.4 "><p id="p12219142322416"><a name="p12219142322416"></a><a name="p12219142322416"></a>Callback used to return the current <strong id="b14713164216208"><a name="b14713164216208"></a><a name="b14713164216208"></a>Window</strong> object.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
     window.find("first", (err, data) => {
       if (err) {
           console.error('Failed to find the subWindow. Cause: ' + JSON.stringify(err));
           return;
       }
      console.info('SubWindow found. Data: ' + JSON.stringify(data))
      windowClass = data;
    })
    ```


## window.getAbilityWindowMode<sup>7+</sup><a name="section7318195416358"></a>

getAbilityWindowMode\(callback: AsyncCallback<WindowMode\>\): void

Obtains the mode of this window.

-   Parameters

    <a name="table64401916102719"></a>
    <table><thead align="left"><tr id="row174403165278"><th class="cellrowborder" valign="top" width="11.21%" id="mcps1.1.5.1.1"><p id="p1344020164271"><a name="p1344020164271"></a><a name="p1344020164271"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="30.159999999999997%" id="mcps1.1.5.1.2"><p id="p184401816182717"><a name="p184401816182717"></a><a name="p184401816182717"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="5.2299999999999995%" id="mcps1.1.5.1.3"><p id="p1441131619272"><a name="p1441131619272"></a><a name="p1441131619272"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="53.400000000000006%" id="mcps1.1.5.1.4"><p id="p94411716112719"><a name="p94411716112719"></a><a name="p94411716112719"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row5442171662711"><td class="cellrowborder" valign="top" width="11.21%" headers="mcps1.1.5.1.1 "><p id="p20442191610277"><a name="p20442191610277"></a><a name="p20442191610277"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="30.159999999999997%" headers="mcps1.1.5.1.2 "><p id="p19442101619274"><a name="p19442101619274"></a><a name="p19442101619274"></a>AsyncCallback&lt;<a href="#section972916531524">WindowMode</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="5.2299999999999995%" headers="mcps1.1.5.1.3 "><p id="p12442111642710"><a name="p12442111642710"></a><a name="p12442111642710"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="53.400000000000006%" headers="mcps1.1.5.1.4 "><p id="p20617967306"><a name="p20617967306"></a><a name="p20617967306"></a>Callback used to return the window mode.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    window.getAbilityWindowMode((err, data) => {
        if (err) {
            console.error(''Failed to obtain the window mode. Cause:' + JSON.stringify(err));
            return;
        }
        console.info('Window mode obtained. Data:' + JSON.stringify(data))
    
    });
    ```


## window.getSplitScreenBounds<sup>7+</sup><a name="section991985875219"></a>

getSplitScreenBounds\(splitRatio: SplitRatio, callback: AsyncCallback<SplitScreenBoundsInfo\>\): void

Obtains the position and area of multiple windows in split-screen mode.

-   Parameters

    <a name="table69661135912"></a>
    <table><thead align="left"><tr id="row149668318915"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p7966738914"><a name="p7966738914"></a><a name="p7966738914"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="19.91%" id="mcps1.1.5.1.2"><p id="p296713699"><a name="p296713699"></a><a name="p296713699"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p196718315911"><a name="p196718315911"></a><a name="p196718315911"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="56.11000000000001%" id="mcps1.1.5.1.4"><p id="p9967231197"><a name="p9967231197"></a><a name="p9967231197"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row99671533914"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p79671633910"><a name="p79671633910"></a><a name="p79671633910"></a>splitRatio</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.91%" headers="mcps1.1.5.1.2 "><p id="p11967433914"><a name="p11967433914"></a><a name="p11967433914"></a>SplitRatio</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p19671336916"><a name="p19671336916"></a><a name="p19671336916"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.11000000000001%" headers="mcps1.1.5.1.4 "><p id="p69671631796"><a name="p69671631796"></a><a name="p69671631796"></a>Screen split ratio. The default ratio is 1:1. The value <strong id="b204095913218"><a name="b204095913218"></a><a name="b204095913218"></a>1</strong> indicates the ratio 1:2, and the value <strong id="b540459112110"><a name="b540459112110"></a><a name="b540459112110"></a>2</strong> indicates the ratio 2:1.</p>
    </td>
    </tr>
    <tr id="row038911417222"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p139081442219"><a name="p139081442219"></a><a name="p139081442219"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.91%" headers="mcps1.1.5.1.2 "><p id="p16390514172214"><a name="p16390514172214"></a><a name="p16390514172214"></a>AsyncCallback&lt;<a href="#section15380136104815">SplitScreenBoundsInfo</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p1498719531224"><a name="p1498719531224"></a><a name="p1498719531224"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.11000000000001%" headers="mcps1.1.5.1.4 "><p id="p16390714172215"><a name="p16390714172215"></a><a name="p16390714172215"></a>Callback used to return a <strong id="b6993112272310"><a name="b6993112272310"></a><a name="b6993112272310"></a>SplitScreenBoundsInfo</strong> object that contains the split-screen boundary information.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var splitRatio = '1:1';
    window.getSplitScreenBounds(splitRatio, (err, data) => {
        if (err) {
            console.error('Failed to obtain the split-screen boundary information. Cause: ' + JSON.stringify(err));
            return;
        }
        console.info('Split-screen boundary information obtained. Data: ' + JSON.stringify(data))
    
    });
    ```


## window.isFloatingAbilityWindowVisible<sup>7+</sup><a name="section1531516329116"></a>

isFloatingAbilityWindowVisible\(callback:AsyncCallback<boolean\>\): void

Checks whether the floating window is visible.

-   Parameters

    <a name="table1325114353010"></a>
    <table><thead align="left"><tr id="row932514310307"><th class="cellrowborder" valign="top" width="11.23887611238876%" id="mcps1.1.5.1.1"><p id="p16325164343013"><a name="p16325164343013"></a><a name="p16325164343013"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="34.63653634636536%" id="mcps1.1.5.1.2"><p id="p19883132283212"><a name="p19883132283212"></a><a name="p19883132283212"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.55924407559244%" id="mcps1.1.5.1.3"><p id="p13325134317300"><a name="p13325134317300"></a><a name="p13325134317300"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="46.565343465653434%" id="mcps1.1.5.1.4"><p id="p4325134353017"><a name="p4325134353017"></a><a name="p4325134353017"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row266471412415"><td class="cellrowborder" valign="top" width="11.23887611238876%" headers="mcps1.1.5.1.1 "><p id="p143341319205"><a name="p143341319205"></a><a name="p143341319205"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.63653634636536%" headers="mcps1.1.5.1.2 "><p id="p1043316137200"><a name="p1043316137200"></a><a name="p1043316137200"></a>AsyncCallback&lt;boolean&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.55924407559244%" headers="mcps1.1.5.1.3 "><p id="p12659352195818"><a name="p12659352195818"></a><a name="p12659352195818"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.565343465653434%" headers="mcps1.1.5.1.4 "><p id="p3433161313204"><a name="p3433161313204"></a><a name="p3433161313204"></a>Callback used to indicate whether the floating window is visible.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    window.isFloatingAbilityWindowVisible( (err, data) => {
        if (err) {
            console.error('Failed to check whether the floating window is visible. Cause:' + JSON.stringify(err));
            return;
        }
        console.info('Succeeded in checking whether the floating window is visible. Data:' + JSON.stringify(data))
    
    });
    ```


## window.setSplitBarVisibility<sup>7+</sup><a name="section768981161011"></a>

setSplitBarVisibility\(isVisibility: boolean, callback: AsyncCallback<void\>\): void

Sets whether the split-screen divider is visible.

-   Parameters

    <a name="table187037244101"></a>
    <table><thead align="left"><tr id="row15703224111016"><th class="cellrowborder" valign="top" width="18.060000000000002%" id="mcps1.1.4.1.1"><p id="p187031124121018"><a name="p187031124121018"></a><a name="p187031124121018"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="21.91%" id="mcps1.1.4.1.2"><p id="p770319249102"><a name="p770319249102"></a><a name="p770319249102"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="60.029999999999994%" id="mcps1.1.4.1.3"><p id="p67033249101"><a name="p67033249101"></a><a name="p67033249101"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1770332413104"><td class="cellrowborder" valign="top" width="18.060000000000002%" headers="mcps1.1.4.1.1 "><p id="p270482431016"><a name="p270482431016"></a><a name="p270482431016"></a>isVisibility</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.91%" headers="mcps1.1.4.1.2 "><p id="p870422414104"><a name="p870422414104"></a><a name="p870422414104"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="60.029999999999994%" headers="mcps1.1.4.1.3 "><p id="p17704192420105"><a name="p17704192420105"></a><a name="p17704192420105"></a>Whether to display the divider. The value <strong id="b7537752132310"><a name="b7537752132310"></a><a name="b7537752132310"></a>true</strong> means to display the divider, and <strong id="b5537185292317"><a name="b5537185292317"></a><a name="b5537185292317"></a>false</strong> means the opposite.</p>
    </td>
    </tr>
    <tr id="row18641181493411"><td class="cellrowborder" valign="top" width="18.060000000000002%" headers="mcps1.1.4.1.1 "><p id="p19642201413415"><a name="p19642201413415"></a><a name="p19642201413415"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.91%" headers="mcps1.1.4.1.2 "><p id="p364251418348"><a name="p364251418348"></a><a name="p364251418348"></a>AsyncCallback&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="60.029999999999994%" headers="mcps1.1.4.1.3 "><p id="p4642181414346"><a name="p4642181414346"></a><a name="p4642181414346"></a>Callback used to return the execution result.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var isVisibility = false;
    window.setSplitBarVisibility(isVisibility , (err, data) => {
        if (err) {
            console.error('Failed to set the divider to be invisible. Cause:' + JSON.stringify(err));
            return;
        }
        console.info('Succeeded in setting the divider to be invisible. Data:' + JSON.stringify(data))
    });
    ```


## WindowType<sup>7+</sup><a name="section099619567453"></a>

Window type.

<a name="table0509194135518"></a>
<table><thead align="left"><tr id="row6510104115556"><th class="cellrowborder" valign="top" width="27.900000000000002%" id="mcps1.1.4.1.1"><p id="p2510641195510"><a name="p2510641195510"></a><a name="p2510641195510"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="12.43%" id="mcps1.1.4.1.2"><p id="p9510184113557"><a name="p9510184113557"></a><a name="p9510184113557"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="59.67%" id="mcps1.1.4.1.3"><p id="p2051074114558"><a name="p2051074114558"></a><a name="p2051074114558"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row61165292280"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p372317419296"><a name="p372317419296"></a><a name="p372317419296"></a>TYPE_APP</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p21167297284"><a name="p21167297284"></a><a name="p21167297284"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p11177297281"><a name="p11177297281"></a><a name="p11177297281"></a>Application window.</p>
</td>
</tr>
<tr id="row71153328288"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p1811543212281"><a name="p1811543212281"></a><a name="p1811543212281"></a>TYPE_SYSTEM_ALERT</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p81157329286"><a name="p81157329286"></a><a name="p81157329286"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p14115203292816"><a name="p14115203292816"></a><a name="p14115203292816"></a>System pop-up window.</p>
</td>
</tr>
</tbody>
</table>

## AvoidAreaType<sup>7+</sup><a name="section86081127175715"></a>

Describes the type of the area where the window cannot be displayed.

<a name="table26081027205719"></a>
<table><thead align="left"><tr id="row1460818272576"><th class="cellrowborder" valign="top" width="27.900000000000002%" id="mcps1.1.4.1.1"><p id="p17608427145718"><a name="p17608427145718"></a><a name="p17608427145718"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="12.43%" id="mcps1.1.4.1.2"><p id="p166081927145717"><a name="p166081927145717"></a><a name="p166081927145717"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="59.67%" id="mcps1.1.4.1.3"><p id="p3608102718578"><a name="p3608102718578"></a><a name="p3608102718578"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row97970191284"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p9798131919287"><a name="p9798131919287"></a><a name="p9798131919287"></a>TYPE_SYSTEM</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p8798101992810"><a name="p8798101992810"></a><a name="p8798101992810"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p879818195283"><a name="p879818195283"></a><a name="p879818195283"></a>Default area of the system.</p>
</td>
</tr>
<tr id="row95792234288"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p1579172332813"><a name="p1579172332813"></a><a name="p1579172332813"></a>TYPE_CUTOUT</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p657942310286"><a name="p657942310286"></a><a name="p657942310286"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p18579122312814"><a name="p18579122312814"></a><a name="p18579122312814"></a>Notch.</p>
</td>
</tr>
</tbody>
</table>

## WindowMode<sup>7+</sup><a name="section972916531524"></a>

Describes the window mode of an application.

<a name="table97291353175217"></a>
<table><thead align="left"><tr id="row572985365214"><th class="cellrowborder" valign="top" width="27.900000000000002%" id="mcps1.1.4.1.1"><p id="p1173011535528"><a name="p1173011535528"></a><a name="p1173011535528"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="12.43%" id="mcps1.1.4.1.2"><p id="p8730135345215"><a name="p8730135345215"></a><a name="p8730135345215"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="59.67%" id="mcps1.1.4.1.3"><p id="p073055345214"><a name="p073055345214"></a><a name="p073055345214"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row7730853105219"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p1730105395216"><a name="p1730105395216"></a><a name="p1730105395216"></a>UNDEFINED</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p13730155365214"><a name="p13730155365214"></a><a name="p13730155365214"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p1173045310521"><a name="p1173045310521"></a><a name="p1173045310521"></a>The window mode is not defined by the application.</p>
</td>
</tr>
<tr id="row12730155375213"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p7731125375213"><a name="p7731125375213"></a><a name="p7731125375213"></a>FULLSCREEN</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p3731115314522"><a name="p3731115314522"></a><a name="p3731115314522"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p9731135365214"><a name="p9731135365214"></a><a name="p9731135365214"></a>The application is displayed in full screen.</p>
</td>
</tr>
<tr id="row57311953185217"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p173145313523"><a name="p173145313523"></a><a name="p173145313523"></a>PRIMARY</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p16731165375212"><a name="p16731165375212"></a><a name="p16731165375212"></a>3</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p19731195310529"><a name="p19731195310529"></a><a name="p19731195310529"></a>The application is displayed in the primary window in split-screen mode.</p>
</td>
</tr>
<tr id="row1373285319522"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p77321353185218"><a name="p77321353185218"></a><a name="p77321353185218"></a>SECONDARY</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p137321153155219"><a name="p137321153155219"></a><a name="p137321153155219"></a>4</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p8732145335216"><a name="p8732145335216"></a><a name="p8732145335216"></a>The application is displayed in the secondary window in split-screen mode.</p>
</td>
</tr>
<tr id="row107321653185211"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p17732105345216"><a name="p17732105345216"></a><a name="p17732105345216"></a>FLOATING</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p1773265375217"><a name="p1773265375217"></a><a name="p1773265375217"></a>5</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p1773215532523"><a name="p1773215532523"></a><a name="p1773215532523"></a>The application is displayed in a floating window.</p>
</td>
</tr>
</tbody>
</table>

## splitMode<sup>7+</sup><a name="section1398211585344"></a>

Describes the split-screen mode.

<a name="table20633101642315"></a>
<table><thead align="left"><tr id="row663331618238"><th class="cellrowborder" valign="top" width="27.900000000000002%" id="mcps1.1.4.1.1"><p id="a3d0fc780cc904c1cbab7991251622f65"><a name="a3d0fc780cc904c1cbab7991251622f65"></a><a name="a3d0fc780cc904c1cbab7991251622f65"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="12.43%" id="mcps1.1.4.1.2"><p id="aace9cae4ba0d4939bfa048460f61c3c7"><a name="aace9cae4ba0d4939bfa048460f61c3c7"></a><a name="aace9cae4ba0d4939bfa048460f61c3c7"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="59.67%" id="mcps1.1.4.1.3"><p id="afec895de33f94e3c87ee7acc20190a17"><a name="afec895de33f94e3c87ee7acc20190a17"></a><a name="afec895de33f94e3c87ee7acc20190a17"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row188481425182510"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p1388162319341"><a name="p1388162319341"></a><a name="p1388162319341"></a>VERTICAL</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p2282152962115"><a name="p2282152962115"></a><a name="p2282152962115"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p328012293211"><a name="p328012293211"></a><a name="p328012293211"></a>Vertical split-screen mode.</p>
</td>
</tr>
<tr id="row0461622112513"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p144841850133411"><a name="p144841850133411"></a><a name="p144841850133411"></a>HORIZONTAL</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p1310553911218"><a name="p1310553911218"></a><a name="p1310553911218"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p15865395215"><a name="p15865395215"></a><a name="p15865395215"></a>Horizontal split-screen mode.</p>
</td>
</tr>
</tbody>
</table>

## Window<a name="section122477411428"></a>

In the following API examples, you must use  [getTopWindow\(\)](#section39061940191)  to obtain a  **Window**  instance and then call the corresponding methods based on this instance.

## setBrightness<a name="section117171344135516"></a>

setBrightness\(brightness:number, callback: AsyncCallback<void\>\): void

Sets the brightness for this window.

-   Parameters

    <a name="table1771718448559"></a>
    <table><thead align="left"><tr id="row137174444559"><th class="cellrowborder" valign="top" width="14.85%" id="mcps1.1.5.1.1"><p id="p671754419554"><a name="p671754419554"></a><a name="p671754419554"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="35.14%" id="mcps1.1.5.1.2"><p id="p1471710445550"><a name="p1471710445550"></a><a name="p1471710445550"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.610000000000001%" id="mcps1.1.5.1.3"><p id="p671824495514"><a name="p671824495514"></a><a name="p671824495514"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="40.400000000000006%" id="mcps1.1.5.1.4"><p id="p97181544115516"><a name="p97181544115516"></a><a name="p97181544115516"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row10718164435510"><td class="cellrowborder" valign="top" width="14.85%" headers="mcps1.1.5.1.1 "><p id="p15718154415518"><a name="p15718154415518"></a><a name="p15718154415518"></a>brightness</p>
    </td>
    <td class="cellrowborder" valign="top" width="35.14%" headers="mcps1.1.5.1.2 "><p id="p1471864415554"><a name="p1471864415554"></a><a name="p1471864415554"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.610000000000001%" headers="mcps1.1.5.1.3 "><p id="p9718644155514"><a name="p9718644155514"></a><a name="p9718644155514"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.400000000000006%" headers="mcps1.1.5.1.4 "><p id="p11718944105520"><a name="p11718944105520"></a><a name="p11718944105520"></a>Brightness to set, which ranges from 0 to 1. The value <strong id="b0478304267"><a name="b0478304267"></a><a name="b0478304267"></a>1</strong> indicates the brightest.</p>
    </td>
    </tr>
    <tr id="row0245184372713"><td class="cellrowborder" valign="top" width="14.85%" headers="mcps1.1.5.1.1 "><p id="p2341346152720"><a name="p2341346152720"></a><a name="p2341346152720"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="35.14%" headers="mcps1.1.5.1.2 "><p id="p163415464271"><a name="p163415464271"></a><a name="p163415464271"></a>AsyncCallback&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.610000000000001%" headers="mcps1.1.5.1.3 "><p id="p18341246162718"><a name="p18341246162718"></a><a name="p18341246162718"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.400000000000006%" headers="mcps1.1.5.1.4 "><p id="p153424662716"><a name="p153424662716"></a><a name="p153424662716"></a>Callback invoked to return the result.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var brightness = 10;
    windowClass.setBrightness(brightness, (err, data) => {
        if (err) {
            console.error('Failed to set the brightness. Cause: ' + JSON.stringify(err));
            return;
        }
        console.info('Succeeded in setting the brightness. Data: ' + JSON.stringify(data));
    });
    ```


## setBackgroundColor<a name="section497614491098"></a>

setBackgroundColor\(color: string, callback: AsyncCallback<void\>\): void

Sets the background color for this window.

-   Parameters

    <a name="table159765491792"></a>
    <table><thead align="left"><tr id="row129768499913"><th class="cellrowborder" valign="top" width="11.03%" id="mcps1.1.5.1.1"><p id="p597654913913"><a name="p597654913913"></a><a name="p597654913913"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.64%" id="mcps1.1.5.1.2"><p id="p1797616497916"><a name="p1797616497916"></a><a name="p1797616497916"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.1499999999999995%" id="mcps1.1.5.1.3"><p id="p3976174914914"><a name="p3976174914914"></a><a name="p3976174914914"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="70.17999999999999%" id="mcps1.1.5.1.4"><p id="p1976154918915"><a name="p1976154918915"></a><a name="p1976154918915"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row797612498910"><td class="cellrowborder" valign="top" width="11.03%" headers="mcps1.1.5.1.1 "><p id="p197624915914"><a name="p197624915914"></a><a name="p197624915914"></a>color</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.64%" headers="mcps1.1.5.1.2 "><p id="p99764493918"><a name="p99764493918"></a><a name="p99764493918"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.1499999999999995%" headers="mcps1.1.5.1.3 "><p id="p097616499910"><a name="p097616499910"></a><a name="p097616499910"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="70.17999999999999%" headers="mcps1.1.5.1.4 "><p id="p08577592250"><a name="p08577592250"></a><a name="p08577592250"></a>Background color to set. The color is a hexadecimal value, for example, <strong id="b59831558261"><a name="b59831558261"></a><a name="b59831558261"></a>#00FF00</strong> or <strong id="b1983258267"><a name="b1983258267"></a><a name="b1983258267"></a>#FF00FF00</strong>.</p>
    </td>
    </tr>
    <tr id="row10941125432615"><td class="cellrowborder" valign="top" width="11.03%" headers="mcps1.1.5.1.1 "><p id="p3674165672619"><a name="p3674165672619"></a><a name="p3674165672619"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.64%" headers="mcps1.1.5.1.2 "><p id="p767410561263"><a name="p767410561263"></a><a name="p767410561263"></a>AsyncCallback&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.1499999999999995%" headers="mcps1.1.5.1.3 "><p id="p2674456102617"><a name="p2674456102617"></a><a name="p2674456102617"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="70.17999999999999%" headers="mcps1.1.5.1.4 "><p id="p15674165614268"><a name="p15674165614268"></a><a name="p15674165614268"></a>Callback invoked to return the result.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var color = '#00ff33';
    windowClass.setBackgroundColor(color, (err, data) => {
        if (err) {
            console.error('Failed to set the background color. Cause: ' + JSON.stringify(err));
            return;
        }
        console.info('Succeeded in setting the background color. Data: ' + JSON.stringify(data));
    });
    ```


## setTransparent<sup>7+</sup><a name="section192031529155819"></a>

setTransparent\(isTransparent: boolean, callback: AsyncCallback<void\>\): void

Sets whether this window is transparent.

-   Parameters

    <a name="table137409337442"></a>
    <table><thead align="left"><tr id="row1374017338445"><th class="cellrowborder" valign="top" width="19.18%" id="mcps1.1.5.1.1"><p id="p1574163319445"><a name="p1574163319445"></a><a name="p1574163319445"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="37.62%" id="mcps1.1.5.1.2"><p id="p1174183310444"><a name="p1174183310444"></a><a name="p1174183310444"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.97%" id="mcps1.1.5.1.3"><p id="p1774112337449"><a name="p1774112337449"></a><a name="p1774112337449"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="31.230000000000004%" id="mcps1.1.5.1.4"><p id="p1074116335447"><a name="p1074116335447"></a><a name="p1074116335447"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row9741163384410"><td class="cellrowborder" valign="top" width="19.18%" headers="mcps1.1.5.1.1 "><p id="p974133318440"><a name="p974133318440"></a><a name="p974133318440"></a>isTransparent</p>
    </td>
    <td class="cellrowborder" valign="top" width="37.62%" headers="mcps1.1.5.1.2 "><p id="p27411133114419"><a name="p27411133114419"></a><a name="p27411133114419"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.97%" headers="mcps1.1.5.1.3 "><p id="p5741933144417"><a name="p5741933144417"></a><a name="p5741933144417"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="31.230000000000004%" headers="mcps1.1.5.1.4 "><p id="p1774153313446"><a name="p1774153313446"></a><a name="p1774153313446"></a>Whether the window is transparent.</p>
    </td>
    </tr>
    <tr id="row17928163383018"><td class="cellrowborder" valign="top" width="19.18%" headers="mcps1.1.5.1.1 "><p id="p16425357309"><a name="p16425357309"></a><a name="p16425357309"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="37.62%" headers="mcps1.1.5.1.2 "><p id="p26421935123020"><a name="p26421935123020"></a><a name="p26421935123020"></a>AsyncCallback&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.97%" headers="mcps1.1.5.1.3 "><p id="p664273533016"><a name="p664273533016"></a><a name="p664273533016"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="31.230000000000004%" headers="mcps1.1.5.1.4 "><p id="p86431359309"><a name="p86431359309"></a><a name="p86431359309"></a>Callback invoked to return the result.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var isTransparent = true;
    windowClass.setTransparent(isTransparent, (err, data) => {
        if (err) {
            console.error('Failed to set the window to be transparent. Cause: ' + JSON.stringify(err));
            return;
        }
        console.info('Succeeded in setting the window to be transparent. Data: ' + JSON.stringify(data))
    });
    ```


## setFullScreen<a name="section7714104485515"></a>

setFullScreen\(isFullScreen: boolean, callback: AsyncCallback<void\>\): void

Sets whether to enable the full-screen mode for this window.

-   Parameters

    <a name="table871414475519"></a>
    <table><thead align="left"><tr id="row371511445551"><th class="cellrowborder" valign="top" width="14.6%" id="mcps1.1.5.1.1"><p id="p671519441550"><a name="p671519441550"></a><a name="p671519441550"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="41.08%" id="mcps1.1.5.1.2"><p id="p171515445551"><a name="p171515445551"></a><a name="p171515445551"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.48%" id="mcps1.1.5.1.3"><p id="p15715644155518"><a name="p15715644155518"></a><a name="p15715644155518"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="32.84%" id="mcps1.1.5.1.4"><p id="p47156449552"><a name="p47156449552"></a><a name="p47156449552"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row18715104425517"><td class="cellrowborder" valign="top" width="14.6%" headers="mcps1.1.5.1.1 "><p id="p147151844145512"><a name="p147151844145512"></a><a name="p147151844145512"></a>isFullScreen</p>
    </td>
    <td class="cellrowborder" valign="top" width="41.08%" headers="mcps1.1.5.1.2 "><p id="p1871584416559"><a name="p1871584416559"></a><a name="p1871584416559"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.5.1.3 "><p id="p871617449552"><a name="p871617449552"></a><a name="p871617449552"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.84%" headers="mcps1.1.5.1.4 "><p id="p171664455512"><a name="p171664455512"></a><a name="p171664455512"></a>Whether to enable the full-screen mode.</p>
    </td>
    </tr>
    <tr id="row9638102912279"><td class="cellrowborder" valign="top" width="14.6%" headers="mcps1.1.5.1.1 "><p id="p176181310272"><a name="p176181310272"></a><a name="p176181310272"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="41.08%" headers="mcps1.1.5.1.2 "><p id="p1361853112279"><a name="p1361853112279"></a><a name="p1361853112279"></a>AsyncCallback&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.5.1.3 "><p id="p116181631102717"><a name="p116181631102717"></a><a name="p116181631102717"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.84%" headers="mcps1.1.5.1.4 "><p id="p166181331132716"><a name="p166181331132716"></a><a name="p166181331132716"></a>Callback invoked to return the result.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var isFullScreen = true;
    windowClass.setFullScreen(isFullScreen, (err, data) => {
        if (err) {
            console.error('Failed to enable the full-screen mode. Cause: ' + JSON.stringify(err));
            return;
        }
        console.info('Succeeded in enabling the full-screen mode. Data: ' + JSON.stringify(data));
    });
    ```


## setKeepScreenOn<a name="section2712244165510"></a>

setKeepScreenOn\(isKeepScreenOn: boolean, callback: AsyncCallback<void\>\): void

Sets whether to keep the screen always on.

-   Parameters

    <a name="table2712744165515"></a>
    <table><thead align="left"><tr id="row471210442555"><th class="cellrowborder" valign="top" width="18.86%" id="mcps1.1.5.1.1"><p id="p1271294455510"><a name="p1271294455510"></a><a name="p1271294455510"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="28.349999999999998%" id="mcps1.1.5.1.2"><p id="p18713104419552"><a name="p18713104419552"></a><a name="p18713104419552"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.2%" id="mcps1.1.5.1.3"><p id="p20713544125517"><a name="p20713544125517"></a><a name="p20713544125517"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="42.59%" id="mcps1.1.5.1.4"><p id="p177131445553"><a name="p177131445553"></a><a name="p177131445553"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row671374455516"><td class="cellrowborder" valign="top" width="18.86%" headers="mcps1.1.5.1.1 "><p id="p2071374455512"><a name="p2071374455512"></a><a name="p2071374455512"></a>isKeepScreenOn</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.349999999999998%" headers="mcps1.1.5.1.2 "><p id="p1571315442557"><a name="p1571315442557"></a><a name="p1571315442557"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.2%" headers="mcps1.1.5.1.3 "><p id="p5713144413553"><a name="p5713144413553"></a><a name="p5713144413553"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.59%" headers="mcps1.1.5.1.4 "><p id="p1271317444558"><a name="p1271317444558"></a><a name="p1271317444558"></a>Whether to keep the screen always on.</p>
    </td>
    </tr>
    <tr id="row101731514122712"><td class="cellrowborder" valign="top" width="18.86%" headers="mcps1.1.5.1.1 "><p id="p132081652713"><a name="p132081652713"></a><a name="p132081652713"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.349999999999998%" headers="mcps1.1.5.1.2 "><p id="p22051612271"><a name="p22051612271"></a><a name="p22051612271"></a>AsyncCallback&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.2%" headers="mcps1.1.5.1.3 "><p id="p162021619271"><a name="p162021619271"></a><a name="p162021619271"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.59%" headers="mcps1.1.5.1.4 "><p id="p1220416152719"><a name="p1220416152719"></a><a name="p1220416152719"></a>Callback invoked to return the result.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var isKeepScreenOn = true;
    windowClass.setKeepScreenOn(isKeepScreenOn, (err, data) => {
        if (err) {
            console.error('Failed to set the screen to be always on. Cause: ' + JSON.stringify(err));
            return;
        }
        console.info('Succeeded in setting the screen to be always on. Data: ' + JSON.stringify(data));
    });
    ```

### setWindowType<sup>7+</sup>

setWindowType(type: WindowType, callback: AsyncCallback&lt;void&gt;): void

Sets the window type.

- Parameters

  | Name     | Type                               | Mandatory | Description                              |
  | -------- | ---------------------------------- | --------- | ---------------------------------------- |
  | type     | [WindowType](#section099619567453) | Yes       | Window type.                             |
  | callback | AsyncCallback&lt;void&gt;          | Yes       | Callback used to return the window type. |


- Example
  ```
  var type = window.TYPE_APP;
  windowClass.setWindowType(type, (err, data) => {
    if (err) {
        console.error('Failed to set the window type. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in setting the window type. Data: ' + JSON.stringify(data))
  });
  ```


## setDimBehind<sup>7+</sup><a name="section1291661141917"></a>

setDimBehind\(dimBehindValue: number, callback: AsyncCallback<void\>\): void

Sets the dimness of the window that is not on top.

-   Parameters

    <a name="table16916101110199"></a>
    <table><thead align="left"><tr id="row179161411151911"><th class="cellrowborder" valign="top" width="20.900000000000002%" id="mcps1.1.5.1.1"><p id="p4917191141913"><a name="p4917191141913"></a><a name="p4917191141913"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="25.930000000000003%" id="mcps1.1.5.1.2"><p id="p791771112192"><a name="p791771112192"></a><a name="p791771112192"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.920000000000002%" id="mcps1.1.5.1.3"><p id="p691751111914"><a name="p691751111914"></a><a name="p691751111914"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="43.25000000000001%" id="mcps1.1.5.1.4"><p id="p149171113199"><a name="p149171113199"></a><a name="p149171113199"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1591701191918"><td class="cellrowborder" valign="top" width="20.900000000000002%" headers="mcps1.1.5.1.1 "><p id="p191791110198"><a name="p191791110198"></a><a name="p191791110198"></a>dimBehindValue</p>
    </td>
    <td class="cellrowborder" valign="top" width="25.930000000000003%" headers="mcps1.1.5.1.2 "><p id="p39173112198"><a name="p39173112198"></a><a name="p39173112198"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.920000000000002%" headers="mcps1.1.5.1.3 "><p id="p9917151121920"><a name="p9917151121920"></a><a name="p9917151121920"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="43.25000000000001%" headers="mcps1.1.5.1.4 "><p id="p12917111191916"><a name="p12917111191916"></a><a name="p12917111191916"></a>Dimness of the window to set. The value ranges from 0 to 1. The value <strong id="b14108824172919"><a name="b14108824172919"></a><a name="b14108824172919"></a>1</strong> indicates the dimmest.</p>
    </td>
    </tr>
    <tr id="row425481373214"><td class="cellrowborder" valign="top" width="20.900000000000002%" headers="mcps1.1.5.1.1 "><p id="p1336214158329"><a name="p1336214158329"></a><a name="p1336214158329"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="25.930000000000003%" headers="mcps1.1.5.1.2 "><p id="p436220151322"><a name="p436220151322"></a><a name="p436220151322"></a>AsyncCallback&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.920000000000002%" headers="mcps1.1.5.1.3 "><p id="p193621415183219"><a name="p193621415183219"></a><a name="p193621415183219"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="43.25000000000001%" headers="mcps1.1.5.1.4 "><p id="p036261593219"><a name="p036261593219"></a><a name="p036261593219"></a>Callback invoked to return the result.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    windowClass.setDimBehind(0.5, (err, data) => {
        if (err) {
            console.error('Failed to set the dimness. Cause: ' + JSON.stringify(err));
            return;
        }
        console.info('Succeeded in setting the dimness. Data:' + JSON.stringify(data));
    });
    ```


## setLayoutFullScreen<sup>7+</sup><a name="section22582029171217"></a>

setLayoutFullScreen\(isLayoutFullScreen: boolean, callback: AsyncCallback<void\>\): void

Sets whether the window layout is in full-screen mode.

-   Parameters

    <a name="table1625852915123"></a>
    <table><thead align="left"><tr id="row22587297124"><th class="cellrowborder" valign="top" width="15.049999999999999%" id="mcps1.1.5.1.1"><p id="p125862918127"><a name="p125862918127"></a><a name="p125862918127"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.58%" id="mcps1.1.5.1.2"><p id="p13259142941219"><a name="p13259142941219"></a><a name="p13259142941219"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.06%" id="mcps1.1.5.1.3"><p id="p62592295128"><a name="p62592295128"></a><a name="p62592295128"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="68.31%" id="mcps1.1.5.1.4"><p id="p20259202915129"><a name="p20259202915129"></a><a name="p20259202915129"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row8259102921219"><td class="cellrowborder" valign="top" width="15.049999999999999%" headers="mcps1.1.5.1.1 "><p id="p14259172991217"><a name="p14259172991217"></a><a name="p14259172991217"></a>isLayoutFullScreen</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.58%" headers="mcps1.1.5.1.2 "><p id="p10259182951214"><a name="p10259182951214"></a><a name="p10259182951214"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.06%" headers="mcps1.1.5.1.3 "><p id="p1725992971219"><a name="p1725992971219"></a><a name="p1725992971219"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="68.31%" headers="mcps1.1.5.1.4 "><p id="p102591529101210"><a name="p102591529101210"></a><a name="p102591529101210"></a>Whether the window layout is in full-screen mode.</p>
    </td>
    </tr>
    <tr id="row631616518309"><td class="cellrowborder" valign="top" width="15.049999999999999%" headers="mcps1.1.5.1.1 "><p id="p71098531304"><a name="p71098531304"></a><a name="p71098531304"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.58%" headers="mcps1.1.5.1.2 "><p id="p1010919538307"><a name="p1010919538307"></a><a name="p1010919538307"></a>AsyncCallback&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.06%" headers="mcps1.1.5.1.3 "><p id="p6109145313012"><a name="p6109145313012"></a><a name="p6109145313012"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="68.31%" headers="mcps1.1.5.1.4 "><p id="p010920539300"><a name="p010920539300"></a><a name="p010920539300"></a>Callback invoked to return the result.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var isLayoutFullScreen= true;
    windowClass.setLayoutFullScreen(isLayoutFullScreen, (err, data) => {
        if (err) {
            console.error('Failed to set the window layout to full-screen mode. Cause:' + JSON.stringify(err));
            return;
        }
        console.info('Succeeded in setting the window layout to full-screen mode. Data:' + JSON.stringify(data));
    });
    ```


## setFocusable<sup>7+</sup><a name="section9951153119124"></a>

setFocusable\(isFocusable: boolean, callback: AsyncCallback<void\>\): void

Sets whether this window can gain focus.

-   Parameters

    <a name="table895116314128"></a>
    <table><thead align="left"><tr id="row29526317128"><th class="cellrowborder" valign="top" width="11.03%" id="mcps1.1.5.1.1"><p id="p189522031121220"><a name="p189522031121220"></a><a name="p189522031121220"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.64%" id="mcps1.1.5.1.2"><p id="p199521319123"><a name="p199521319123"></a><a name="p199521319123"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.1499999999999995%" id="mcps1.1.5.1.3"><p id="p995213318127"><a name="p995213318127"></a><a name="p995213318127"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="70.17999999999999%" id="mcps1.1.5.1.4"><p id="p495217312126"><a name="p495217312126"></a><a name="p495217312126"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row49521231141219"><td class="cellrowborder" valign="top" width="11.03%" headers="mcps1.1.5.1.1 "><p id="p1195223161217"><a name="p1195223161217"></a><a name="p1195223161217"></a>isFocusable</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.64%" headers="mcps1.1.5.1.2 "><p id="p16952113116120"><a name="p16952113116120"></a><a name="p16952113116120"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.1499999999999995%" headers="mcps1.1.5.1.3 "><p id="p2952123117127"><a name="p2952123117127"></a><a name="p2952123117127"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="70.17999999999999%" headers="mcps1.1.5.1.4 "><p id="p119521731161218"><a name="p119521731161218"></a><a name="p119521731161218"></a>Whether the window can gain focus.</p>
    </td>
    </tr>
    <tr id="row1522218510314"><td class="cellrowborder" valign="top" width="11.03%" headers="mcps1.1.5.1.1 "><p id="p19867661317"><a name="p19867661317"></a><a name="p19867661317"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.64%" headers="mcps1.1.5.1.2 "><p id="p1186716612317"><a name="p1186716612317"></a><a name="p1186716612317"></a>AsyncCallback&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.1499999999999995%" headers="mcps1.1.5.1.3 "><p id="p1886718613310"><a name="p1886718613310"></a><a name="p1886718613310"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="70.17999999999999%" headers="mcps1.1.5.1.4 "><p id="p1486713673113"><a name="p1486713673113"></a><a name="p1486713673113"></a>Callback invoked to return the result.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var isFocusable= true;
    windowClass.setFocusable(isFocusable, (err, data) => {
        if (err) {
            console.error('Failed to set the window to be focusable. Cause:' + JSON.stringify(err));
            return;
        }
        console.info('Succeeded in setting the window to be focusable. Data: ' + JSON.stringify(data));
    });
    ```


## setTouchable<sup>7+</sup><a name="section13924334125"></a>

setTouchable\(isTouchable: boolean, callback: AsyncCallback<void\>\): void

Sets whether this window is touchable.

-   Parameters

    <a name="table2921733201219"></a>
    <table><thead align="left"><tr id="row119303313121"><th class="cellrowborder" valign="top" width="11.03%" id="mcps1.1.5.1.1"><p id="p169313321213"><a name="p169313321213"></a><a name="p169313321213"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.64%" id="mcps1.1.5.1.2"><p id="p193833141217"><a name="p193833141217"></a><a name="p193833141217"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.1499999999999995%" id="mcps1.1.5.1.3"><p id="p129313332128"><a name="p129313332128"></a><a name="p129313332128"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="70.17999999999999%" id="mcps1.1.5.1.4"><p id="p1393533171214"><a name="p1393533171214"></a><a name="p1393533171214"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row493133312121"><td class="cellrowborder" valign="top" width="11.03%" headers="mcps1.1.5.1.1 "><p id="p1393193317122"><a name="p1393193317122"></a><a name="p1393193317122"></a>isTouchable</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.64%" headers="mcps1.1.5.1.2 "><p id="p6934336122"><a name="p6934336122"></a><a name="p6934336122"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.1499999999999995%" headers="mcps1.1.5.1.3 "><p id="p993233101210"><a name="p993233101210"></a><a name="p993233101210"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="70.17999999999999%" headers="mcps1.1.5.1.4 "><p id="p49319333124"><a name="p49319333124"></a><a name="p49319333124"></a>Whether the window is touchable.</p>
    </td>
    </tr>
    <tr id="row634792043120"><td class="cellrowborder" valign="top" width="11.03%" headers="mcps1.1.5.1.1 "><p id="p6887172110315"><a name="p6887172110315"></a><a name="p6887172110315"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.64%" headers="mcps1.1.5.1.2 "><p id="p10887142183116"><a name="p10887142183116"></a><a name="p10887142183116"></a>AsyncCallback&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.1499999999999995%" headers="mcps1.1.5.1.3 "><p id="p088712163117"><a name="p088712163117"></a><a name="p088712163117"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="70.17999999999999%" headers="mcps1.1.5.1.4 "><p id="p158879213311"><a name="p158879213311"></a><a name="p158879213311"></a>Callback invoked to return the result.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var isTouchable = true;
    windowClass.setTouchable(isTouchable, (err, data) => {
        if (err) {
            console.error('Failed to set the window to be touchable. Cause:' + JSON.stringify(err));
            return;
        }
        console.info('Succeeded in setting the window to be touchable. Data:' + JSON.stringify(data));
    
    });
    ```


## setPrivacyMode<sup>7+</sup><a name="section1977484864511"></a>

setPrivacyMode\(isPrivacyMode: boolean, callback: AsyncCallback<void\>\): void

Sets whether this window is in privacy mode.

-   Parameters

    <a name="table77741748184518"></a>
    <table><thead align="left"><tr id="row187741948144512"><th class="cellrowborder" valign="top" width="25.729999999999997%" id="mcps1.1.5.1.1"><p id="p1777464854519"><a name="p1777464854519"></a><a name="p1777464854519"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="34.77%" id="mcps1.1.5.1.2"><p id="p4774124811458"><a name="p4774124811458"></a><a name="p4774124811458"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.86%" id="mcps1.1.5.1.3"><p id="p17751448124510"><a name="p17751448124510"></a><a name="p17751448124510"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="27.639999999999997%" id="mcps1.1.5.1.4"><p id="p077594884515"><a name="p077594884515"></a><a name="p077594884515"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row7775144817455"><td class="cellrowborder" valign="top" width="25.729999999999997%" headers="mcps1.1.5.1.1 "><p id="p12775174814513"><a name="p12775174814513"></a><a name="p12775174814513"></a>isPrivacyMode</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.77%" headers="mcps1.1.5.1.2 "><p id="p17751848174519"><a name="p17751848174519"></a><a name="p17751848174519"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.86%" headers="mcps1.1.5.1.3 "><p id="p077504814513"><a name="p077504814513"></a><a name="p077504814513"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="27.639999999999997%" headers="mcps1.1.5.1.4 "><p id="p197751848184510"><a name="p197751848184510"></a><a name="p197751848184510"></a>Whether the window is in privacy mode.</p>
    </td>
    </tr>
    <tr id="row119552363315"><td class="cellrowborder" valign="top" width="25.729999999999997%" headers="mcps1.1.5.1.1 "><p id="p550813953113"><a name="p550813953113"></a><a name="p550813953113"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.77%" headers="mcps1.1.5.1.2 "><p id="p2508163920316"><a name="p2508163920316"></a><a name="p2508163920316"></a>AsyncCallback&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.86%" headers="mcps1.1.5.1.3 "><p id="p1050817391311"><a name="p1050817391311"></a><a name="p1050817391311"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="27.639999999999997%" headers="mcps1.1.5.1.4 "><p id="p18508193920311"><a name="p18508193920311"></a><a name="p18508193920311"></a>Callback invoked to return the result.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var isPrivacyMode = true;
    windowClass.setPrivacyMode(isPrivacyMode, (err, data) => {
        if (err) {
            console.error('Failed to set the window to privacy mode. Cause:' + JSON.stringify(err));
            return;
        }
        console.info('Succeeded in setting the window to privacy mode. Data:' + JSON.stringify(data));
    
    });
    ```


## setSystemBarEnable<sup>7+</sup><a name="section14161941154819"></a>

setSystemBarEnable\(names: Array, callback: AsyncCallback<void\>\): void

Sets whether to display the status bar and navigation bar in this window.

-   Parameters

    <a name="table101611841144815"></a>
    <table><thead align="left"><tr id="row19161184114811"><th class="cellrowborder" valign="top" width="11.03%" id="mcps1.1.5.1.1"><p id="p1016194124818"><a name="p1016194124818"></a><a name="p1016194124818"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="25.6%" id="mcps1.1.5.1.2"><p id="p516120415483"><a name="p516120415483"></a><a name="p516120415483"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.1%" id="mcps1.1.5.1.3"><p id="p116116418483"><a name="p116116418483"></a><a name="p116116418483"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="51.27%" id="mcps1.1.5.1.4"><p id="p6161164194817"><a name="p6161164194817"></a><a name="p6161164194817"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row151611841134820"><td class="cellrowborder" valign="top" width="11.03%" headers="mcps1.1.5.1.1 "><p id="p516214415483"><a name="p516214415483"></a><a name="p516214415483"></a>names</p>
    </td>
    <td class="cellrowborder" valign="top" width="25.6%" headers="mcps1.1.5.1.2 "><p id="p5162174164820"><a name="p5162174164820"></a><a name="p5162174164820"></a>Array</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.1%" headers="mcps1.1.5.1.3 "><p id="p41621441184813"><a name="p41621441184813"></a><a name="p41621441184813"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.27%" headers="mcps1.1.5.1.4 "><p id="p181628412488"><a name="p181628412488"></a><a name="p181628412488"></a>Whether to display the status bar and navigation bar. For example, to display the status bar and navigation bar, set this parameter to <strong id="b31031649360"><a name="b31031649360"></a><a name="b31031649360"></a>["status", "navigation"]</strong>.</p>
    </td>
    </tr>
    <tr id="row1010014515319"><td class="cellrowborder" valign="top" width="11.03%" headers="mcps1.1.5.1.1 "><p id="p14982852133115"><a name="p14982852133115"></a><a name="p14982852133115"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="25.6%" headers="mcps1.1.5.1.2 "><p id="p169822052113119"><a name="p169822052113119"></a><a name="p169822052113119"></a>AsyncCallback&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.1%" headers="mcps1.1.5.1.3 "><p id="p1398245293113"><a name="p1398245293113"></a><a name="p1398245293113"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.27%" headers="mcps1.1.5.1.4 "><p id="p8983125220315"><a name="p8983125220315"></a><a name="p8983125220315"></a>Callback invoked to return the result.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var names = ["status", "navigation"];
    windowClass.setSystemBarEnable(names, (err, data) => {
        if (err) {
            console.error('Failed to set the system bar to be visible. Cause:' + JSON.stringify(err));
            return;
        }
        console.info('Succeeded in setting the system bar to be visible. Data: ' + JSON.stringify(data));
    });
    ```


## setSystemBarProperties<a name="section129251146697"></a>

setSystemBarProperties\(systemBarProperties: SystemBarProperties, callback: AsyncCallback<void\>\): void

Sets the properties of the status bar and navigation bar in this window.

-   Parameters

    <a name="table1092564620913"></a>
    <table><thead align="left"><tr id="row16925134615910"><th class="cellrowborder" valign="top" width="15.770000000000001%" id="mcps1.1.5.1.1"><p id="p12925646392"><a name="p12925646392"></a><a name="p12925646392"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.3%" id="mcps1.1.5.1.2"><p id="p109255468915"><a name="p109255468915"></a><a name="p109255468915"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6%" id="mcps1.1.5.1.3"><p id="p492514461919"><a name="p492514461919"></a><a name="p492514461919"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.92999999999999%" id="mcps1.1.5.1.4"><p id="p169251046893"><a name="p169251046893"></a><a name="p169251046893"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row69266461497"><td class="cellrowborder" valign="top" width="15.770000000000001%" headers="mcps1.1.5.1.1 "><p id="p0926104611918"><a name="p0926104611918"></a><a name="p0926104611918"></a>SystemBarProperties</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.3%" headers="mcps1.1.5.1.2 "><p id="p4926184619915"><a name="p4926184619915"></a><a name="p4926184619915"></a><a href="#section6504105103120">SystemBarProperties</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="6%" headers="mcps1.1.5.1.3 "><p id="p139264465911"><a name="p139264465911"></a><a name="p139264465911"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.92999999999999%" headers="mcps1.1.5.1.4 "><p id="p119261466920"><a name="p119261466920"></a><a name="p119261466920"></a>Properties of the status bar and navigation bar to set.</p>
    </td>
    </tr>
    <tr id="row10168121052120"><td class="cellrowborder" valign="top" width="15.770000000000001%" headers="mcps1.1.5.1.1 "><p id="p5880612122117"><a name="p5880612122117"></a><a name="p5880612122117"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.3%" headers="mcps1.1.5.1.2 "><p id="p288071215218"><a name="p288071215218"></a><a name="p288071215218"></a>AsyncCallback&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="6%" headers="mcps1.1.5.1.3 "><p id="p98801212152110"><a name="p98801212152110"></a><a name="p98801212152110"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.92999999999999%" headers="mcps1.1.5.1.4 "><p id="p1988051242118"><a name="p1988051242118"></a><a name="p1988051242118"></a>Callback invoked to return the result.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var SystemBarProperties={
        statusBarColor: '#ff00ff',
        navigationBarColor: '#00ff00',
        // The following properties are supported since API version 7.
        isStatusBarLightIcon: true,
        isNavigationBarLightIcon:false
    };
    windowClass.setSystemBarProperties(SystemBarProperties, (err, data) => {
        if (err) {
            console.error('Failed to set the system bar properties. Cause: ' + JSON.stringify(err));
            return;
        }
        console.info('Succeeded in setting the system bar properties. Data: ' + JSON.stringify(data));
    });
    ```


## getProperties<a name="section19708144419553"></a>

getProperties\(callback: AsyncCallback<WindowProperties\>\): void

Obtains the properties of this window. This method uses an asynchronous callback to return the window properties.

-   Parameters

    <a name="table1889910298214"></a>
    <table><thead align="left"><tr id="row38991829162119"><th class="cellrowborder" valign="top" width="14.95%" id="mcps1.1.5.1.1"><p id="p17899192918217"><a name="p17899192918217"></a><a name="p17899192918217"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="39.56%" id="mcps1.1.5.1.2"><p id="p1389972922116"><a name="p1389972922116"></a><a name="p1389972922116"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.22%" id="mcps1.1.5.1.3"><p id="p089952919215"><a name="p089952919215"></a><a name="p089952919215"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.269999999999996%" id="mcps1.1.5.1.4"><p id="p178998291215"><a name="p178998291215"></a><a name="p178998291215"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row18900102982117"><td class="cellrowborder" valign="top" width="14.95%" headers="mcps1.1.5.1.1 "><p id="p1590019292215"><a name="p1590019292215"></a><a name="p1590019292215"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="39.56%" headers="mcps1.1.5.1.2 "><p id="p1290017293214"><a name="p1290017293214"></a><a name="p1290017293214"></a>AsyncCallback&lt;<a href="#section037811361536">WindowProperties</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.22%" headers="mcps1.1.5.1.3 "><p id="p990042932115"><a name="p990042932115"></a><a name="p990042932115"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.269999999999996%" headers="mcps1.1.5.1.4 "><p id="p1790072917218"><a name="p1790072917218"></a><a name="p1790072917218"></a>Callback used to return the window properties.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    windowClass.getProperties((err, data) => {
        if (err) {
            console.error('Failed to obtain the window properties. Cause: ' + JSON.stringify(err));
            return;
        }
        console.info('Succeeded in obtaining the window properties. Data: ' + JSON.stringify(data));
    });
    ```


## getAvoidArea<sup>7+</sup><a name="section253382794817"></a>

getAvoidArea\(type: AvoidAreaType, callback: AsyncCallback<AvoidArea\>\): void

Obtains the area where this window cannot be displayed, for example, the system bar area and notch area.

-   Parameters

    <a name="table153392774817"></a>
    <table><thead align="left"><tr id="row15331127104811"><th class="cellrowborder" valign="top" width="11.03%" id="mcps1.1.5.1.1"><p id="p17533122710484"><a name="p17533122710484"></a><a name="p17533122710484"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="29.5%" id="mcps1.1.5.1.2"><p id="p1853319275482"><a name="p1853319275482"></a><a name="p1853319275482"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.03%" id="mcps1.1.5.1.3"><p id="p953315272486"><a name="p953315272486"></a><a name="p953315272486"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="51.44%" id="mcps1.1.5.1.4"><p id="p7534142719481"><a name="p7534142719481"></a><a name="p7534142719481"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row195344279482"><td class="cellrowborder" valign="top" width="11.03%" headers="mcps1.1.5.1.1 "><p id="p17534152718484"><a name="p17534152718484"></a><a name="p17534152718484"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.5%" headers="mcps1.1.5.1.2 "><p id="p7534122714489"><a name="p7534122714489"></a><a name="p7534122714489"></a><a href="#section86081127175715">AvoidAreaType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="8.03%" headers="mcps1.1.5.1.3 "><p id="p1534192744818"><a name="p1534192744818"></a><a name="p1534192744818"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.44%" headers="mcps1.1.5.1.4 "><p id="p205341727164818"><a name="p205341727164818"></a><a name="p205341727164818"></a>Type of the area. <strong id="b197921453714"><a name="b197921453714"></a><a name="b197921453714"></a>TYPE_SYSTEM</strong> indicates the default area of the system. <strong id="b1364997103715"><a name="b1364997103715"></a><a name="b1364997103715"></a>TYPE_CUTOUT</strong> indicates the notch area.</p>
    </td>
    </tr>
    <tr id="row2499137173311"><td class="cellrowborder" valign="top" width="11.03%" headers="mcps1.1.5.1.1 "><p id="p19445511123319"><a name="p19445511123319"></a><a name="p19445511123319"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.5%" headers="mcps1.1.5.1.2 "><p id="p1944661113312"><a name="p1944661113312"></a><a name="p1944661113312"></a>AsyncCallback&lt;<a href="#section74393271254">AvoidArea</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.03%" headers="mcps1.1.5.1.3 "><p id="p1144610117336"><a name="p1144610117336"></a><a name="p1144610117336"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.44%" headers="mcps1.1.5.1.4 "><p id="p1144619116337"><a name="p1144619116337"></a><a name="p1144619116337"></a>Callback used to return the area.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var type = window.AvoidAreaType.TYPE_SYSTEM;
    windowClass.getAvoidArea(type, (err, data) => {
        if (err) {
            console.error('Failed to obtain the area. Cause:' + JSON.stringify(err));
            return;
        }
        console.info('Succeeded in obtaining the area. Data:' + JSON.stringify(data));
    });
    ```


## moveTo<sup>7+</sup><a name="section48053165196"></a>

moveTo\(x: number, y: number, callback: AsyncCallback<void\>\): void

Moves this window.

-   Parameters

    <a name="table6805151610199"></a>
    <table><thead align="left"><tr id="row1180601614190"><th class="cellrowborder" valign="top" width="11.03%" id="mcps1.1.5.1.1"><p id="p1180610161190"><a name="p1180610161190"></a><a name="p1180610161190"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="25.679999999999996%" id="mcps1.1.5.1.2"><p id="p11806101618191"><a name="p11806101618191"></a><a name="p11806101618191"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="17.78%" id="mcps1.1.5.1.3"><p id="p380621619194"><a name="p380621619194"></a><a name="p380621619194"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="45.51%" id="mcps1.1.5.1.4"><p id="p880621611194"><a name="p880621611194"></a><a name="p880621611194"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row9806016141919"><td class="cellrowborder" valign="top" width="11.03%" headers="mcps1.1.5.1.1 "><p id="p78061163194"><a name="p78061163194"></a><a name="p78061163194"></a>x</p>
    </td>
    <td class="cellrowborder" valign="top" width="25.679999999999996%" headers="mcps1.1.5.1.2 "><p id="p980614161192"><a name="p980614161192"></a><a name="p980614161192"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.78%" headers="mcps1.1.5.1.3 "><p id="p1480681617197"><a name="p1480681617197"></a><a name="p1480681617197"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.51%" headers="mcps1.1.5.1.4 "><p id="p1758111692511"><a name="p1758111692511"></a><a name="p1758111692511"></a>Distance that the window moves along the x-axis. A positive value indicates that the window moves to the right.</p>
    </td>
    </tr>
    <tr id="row772964315202"><td class="cellrowborder" valign="top" width="11.03%" headers="mcps1.1.5.1.1 "><p id="p67294439202"><a name="p67294439202"></a><a name="p67294439202"></a>y</p>
    </td>
    <td class="cellrowborder" valign="top" width="25.679999999999996%" headers="mcps1.1.5.1.2 "><p id="p3729174392010"><a name="p3729174392010"></a><a name="p3729174392010"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.78%" headers="mcps1.1.5.1.3 "><p id="p14729194319203"><a name="p14729194319203"></a><a name="p14729194319203"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.51%" headers="mcps1.1.5.1.4 "><p id="p17298430205"><a name="p17298430205"></a><a name="p17298430205"></a>Distance that the window moves along the y-axis. A positive value indicates that the window moves downwards.</p>
    </td>
    </tr>
    <tr id="row1783102915323"><td class="cellrowborder" valign="top" width="11.03%" headers="mcps1.1.5.1.1 "><p id="p135651330183218"><a name="p135651330183218"></a><a name="p135651330183218"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="25.679999999999996%" headers="mcps1.1.5.1.2 "><p id="p45658306323"><a name="p45658306323"></a><a name="p45658306323"></a>AsyncCallback&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.78%" headers="mcps1.1.5.1.3 "><p id="p15651430143211"><a name="p15651430143211"></a><a name="p15651430143211"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.51%" headers="mcps1.1.5.1.4 "><p id="p20565163017328"><a name="p20565163017328"></a><a name="p20565163017328"></a>Callback invoked to return the result.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    windowClass.moveTo(300, 300, (err, data)=>{
        if (err) {
            console.error('Failed to move the window. Cause:' + JSON.stringify(err));
            return;
        }
        console.info('Window moved. Data:' + JSON.stringify(data));
    
    });
    ```


## resetSize<sup>7+</sup><a name="section7617318191917"></a>

resetSize\(width: number, height: number, callback: AsyncCallback<void\>\): void

Changes the size of this window.

-   Parameters

    <a name="table6617151810196"></a>
    <table><thead align="left"><tr id="row1617018151918"><th class="cellrowborder" valign="top" width="14.97%" id="mcps1.1.5.1.1"><p id="p156171918181916"><a name="p156171918181916"></a><a name="p156171918181916"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="36.620000000000005%" id="mcps1.1.5.1.2"><p id="p20618918111913"><a name="p20618918111913"></a><a name="p20618918111913"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.03%" id="mcps1.1.5.1.3"><p id="p10618518121910"><a name="p10618518121910"></a><a name="p10618518121910"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="35.38%" id="mcps1.1.5.1.4"><p id="p1861851815192"><a name="p1861851815192"></a><a name="p1861851815192"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row87276372114"><td class="cellrowborder" valign="top" width="14.97%" headers="mcps1.1.5.1.1 "><p id="p8727536214"><a name="p8727536214"></a><a name="p8727536214"></a>width</p>
    </td>
    <td class="cellrowborder" valign="top" width="36.620000000000005%" headers="mcps1.1.5.1.2 "><p id="p12727123202118"><a name="p12727123202118"></a><a name="p12727123202118"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.03%" headers="mcps1.1.5.1.3 "><p id="p147276317216"><a name="p147276317216"></a><a name="p147276317216"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="35.38%" headers="mcps1.1.5.1.4 "><p id="p1372712312117"><a name="p1372712312117"></a><a name="p1372712312117"></a>New width of the window.</p>
    </td>
    </tr>
    <tr id="row1661818181192"><td class="cellrowborder" valign="top" width="14.97%" headers="mcps1.1.5.1.1 "><p id="p15618181851911"><a name="p15618181851911"></a><a name="p15618181851911"></a>height</p>
    </td>
    <td class="cellrowborder" valign="top" width="36.620000000000005%" headers="mcps1.1.5.1.2 "><p id="p11618618121916"><a name="p11618618121916"></a><a name="p11618618121916"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.03%" headers="mcps1.1.5.1.3 "><p id="p17618151871913"><a name="p17618151871913"></a><a name="p17618151871913"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="35.38%" headers="mcps1.1.5.1.4 "><p id="p1561881811191"><a name="p1561881811191"></a><a name="p1561881811191"></a>New height of the window.</p>
    </td>
    </tr>
    <tr id="row1970704193219"><td class="cellrowborder" valign="top" width="14.97%" headers="mcps1.1.5.1.1 "><p id="p14368114310324"><a name="p14368114310324"></a><a name="p14368114310324"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="36.620000000000005%" headers="mcps1.1.5.1.2 "><p id="p193681543203219"><a name="p193681543203219"></a><a name="p193681543203219"></a>AsyncCallback&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.03%" headers="mcps1.1.5.1.3 "><p id="p1436844316327"><a name="p1436844316327"></a><a name="p1436844316327"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="35.38%" headers="mcps1.1.5.1.4 "><p id="p113697438325"><a name="p113697438325"></a><a name="p113697438325"></a>Callback invoked to return the result.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    windowClass.resetSize(500, 1000, (err, data) => {
        if (err) {
            console.error('Failed to change the window size. Cause:' + JSON.stringify(err));
            return;
        }
        console.info('Window size changed. Data:' + JSON.stringify(data));
    });
    ```


## loadContent<sup>7+</sup><a name="section3666192491418"></a>

loadContent\(path: string, callback: AsyncCallback<void\>\): void

Loads content to the subwindow.

-   Parameters

    <a name="table196661824161415"></a>
    <table><thead align="left"><tr id="row36671624191412"><th class="cellrowborder" valign="top" width="21.04%" id="mcps1.1.5.1.1"><p id="p20667142415145"><a name="p20667142415145"></a><a name="p20667142415145"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="30.04%" id="mcps1.1.5.1.2"><p id="p1266772411141"><a name="p1266772411141"></a><a name="p1266772411141"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.18%" id="mcps1.1.5.1.3"><p id="p66672242146"><a name="p66672242146"></a><a name="p66672242146"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="40.739999999999995%" id="mcps1.1.5.1.4"><p id="p116677244142"><a name="p116677244142"></a><a name="p116677244142"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row8667152411412"><td class="cellrowborder" valign="top" width="21.04%" headers="mcps1.1.5.1.1 "><p id="p36681524151410"><a name="p36681524151410"></a><a name="p36681524151410"></a>path</p>
    </td>
    <td class="cellrowborder" valign="top" width="30.04%" headers="mcps1.1.5.1.2 "><p id="p6668202420145"><a name="p6668202420145"></a><a name="p6668202420145"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.18%" headers="mcps1.1.5.1.3 "><p id="p1666817247148"><a name="p1666817247148"></a><a name="p1666817247148"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.739999999999995%" headers="mcps1.1.5.1.4 "><p id="p3668152481419"><a name="p3668152481419"></a><a name="p3668152481419"></a>Path of the page to which the content will be loaded.</p>
    </td>
    </tr>
    <tr id="row206681124151415"><td class="cellrowborder" valign="top" width="21.04%" headers="mcps1.1.5.1.1 "><p id="p466882491414"><a name="p466882491414"></a><a name="p466882491414"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="30.04%" headers="mcps1.1.5.1.2 "><p id="p11668122411411"><a name="p11668122411411"></a><a name="p11668122411411"></a>AsyncCallback&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.18%" headers="mcps1.1.5.1.3 "><p id="p17668142420146"><a name="p17668142420146"></a><a name="p17668142420146"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.739999999999995%" headers="mcps1.1.5.1.4 "><p id="p1366932491410"><a name="p1366932491410"></a><a name="p1366932491410"></a>Callback invoked to return the result.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    windowClass.loadContent("pages/page2/page2", (err, data) => {
       if (err) {
             console.error('Failed to load the content. Cause:' + JSON.stringify(err));
             return;
       }
      console.info('Succeeded in loading the content. Data:' + JSON.stringify(data));
    });
    ```


## hide<sup>7+</sup><a name="section1943153502019"></a>

hide \(callback: AsyncCallback<void\>\): void

Hides the subwindow.

-   Parameters

    <a name="table14321135122019"></a>
    <table><thead align="left"><tr id="row5432163522019"><th class="cellrowborder" valign="top" width="21.04%" id="mcps1.1.5.1.1"><p id="p11433153532017"><a name="p11433153532017"></a><a name="p11433153532017"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="30.04%" id="mcps1.1.5.1.2"><p id="p1943353514208"><a name="p1943353514208"></a><a name="p1943353514208"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.18%" id="mcps1.1.5.1.3"><p id="p11433135112020"><a name="p11433135112020"></a><a name="p11433135112020"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="40.739999999999995%" id="mcps1.1.5.1.4"><p id="p843373518204"><a name="p843373518204"></a><a name="p843373518204"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row24341235172018"><td class="cellrowborder" valign="top" width="21.04%" headers="mcps1.1.5.1.1 "><p id="p134341735182014"><a name="p134341735182014"></a><a name="p134341735182014"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="30.04%" headers="mcps1.1.5.1.2 "><p id="p19434835102015"><a name="p19434835102015"></a><a name="p19434835102015"></a>AsyncCallback&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.18%" headers="mcps1.1.5.1.3 "><p id="p12434835132012"><a name="p12434835132012"></a><a name="p12434835132012"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.739999999999995%" headers="mcps1.1.5.1.4 "><p id="p16434635172017"><a name="p16434635172017"></a><a name="p16434635172017"></a>Callback invoked to return the result.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    windowClass.hide((err, data) => {
        if (err) {
            console.error('Failed to hide the subwindow. Cause: ' + JSON.stringify(err));
            return;
        }
        console.info('Subwindow hidden. Data:' + JSON.stringify(data))
    })
    ```


## show<sup>7+</sup><a name="section26163572310"></a>

show\(callback: AsyncCallback<void\>\): void

Shows the subwindow.

-   Parameters

    <a name="table77133516238"></a>
    <table><thead align="left"><tr id="row47133511236"><th class="cellrowborder" valign="top" width="21.04%" id="mcps1.1.5.1.1"><p id="p87193542311"><a name="p87193542311"></a><a name="p87193542311"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="30.04%" id="mcps1.1.5.1.2"><p id="p1072035172315"><a name="p1072035172315"></a><a name="p1072035172315"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.18%" id="mcps1.1.5.1.3"><p id="p16833512235"><a name="p16833512235"></a><a name="p16833512235"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="40.739999999999995%" id="mcps1.1.5.1.4"><p id="p148143562310"><a name="p148143562310"></a><a name="p148143562310"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row3833517235"><td class="cellrowborder" valign="top" width="21.04%" headers="mcps1.1.5.1.1 "><p id="p198183511238"><a name="p198183511238"></a><a name="p198183511238"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="30.04%" headers="mcps1.1.5.1.2 "><p id="p128103512232"><a name="p128103512232"></a><a name="p128103512232"></a>AsyncCallback&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.18%" headers="mcps1.1.5.1.3 "><p id="p6823513233"><a name="p6823513233"></a><a name="p6823513233"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.739999999999995%" headers="mcps1.1.5.1.4 "><p id="p1810357235"><a name="p1810357235"></a><a name="p1810357235"></a>Callback invoked to return the result.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    windowClass.show((err, data) => {
        if (err) {
            console.error('Failed to show the subwindow. Cause: ' + JSON.stringify(err));
            return;
        }
        console.info('Succeeded in showing the subwindow. Data: ' + JSON.stringify(data))
    })
    ```


## isShowing<sup>7+</sup><a name="section1990720428251"></a>

isShowing\(callback: AsyncCallback<boolean\>\): void

Checks whether the subwindow is displayed.

-   Parameters

    <a name="table119071542102518"></a>
    <table><thead align="left"><tr id="row109087420251"><th class="cellrowborder" valign="top" width="21.04%" id="mcps1.1.5.1.1"><p id="p1790814425253"><a name="p1790814425253"></a><a name="p1790814425253"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="30.04%" id="mcps1.1.5.1.2"><p id="p13908184282515"><a name="p13908184282515"></a><a name="p13908184282515"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.18%" id="mcps1.1.5.1.3"><p id="p1990919427259"><a name="p1990919427259"></a><a name="p1990919427259"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="40.739999999999995%" id="mcps1.1.5.1.4"><p id="p1690911421258"><a name="p1690911421258"></a><a name="p1690911421258"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row159097421254"><td class="cellrowborder" valign="top" width="21.04%" headers="mcps1.1.5.1.1 "><p id="p19093427258"><a name="p19093427258"></a><a name="p19093427258"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="30.04%" headers="mcps1.1.5.1.2 "><p id="p1690917420250"><a name="p1690917420250"></a><a name="p1690917420250"></a>AsyncCallback&lt;boolean&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.18%" headers="mcps1.1.5.1.3 "><p id="p890904210255"><a name="p890904210255"></a><a name="p890904210255"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.739999999999995%" headers="mcps1.1.5.1.4 "><p id="p390914213257"><a name="p390914213257"></a><a name="p390914213257"></a>Callback used to indicate whether the subwindow is displayed.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    windowClass.isShowing((err, data) => {
        if (err) {
            console.error('Failed to check whether the subwindow is showing. Cause:' + JSON.stringify(err));
            return;
        }
        console.info('Succeeded in checking whether the subwindow is showing. Cause:' + JSON.stringify(data))
    })
    ```


## destroy<sup>7+</sup><a name="section746911516277"></a>

destroy\(callback: AsyncCallback<void\>\): void

Destroys the subwindow.

-   Parameters

    <a name="table12470105118277"></a>
    <table><thead align="left"><tr id="row15470451152716"><th class="cellrowborder" valign="top" width="21.04%" id="mcps1.1.5.1.1"><p id="p194701451172712"><a name="p194701451172712"></a><a name="p194701451172712"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="30.04%" id="mcps1.1.5.1.2"><p id="p164701951102718"><a name="p164701951102718"></a><a name="p164701951102718"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.18%" id="mcps1.1.5.1.3"><p id="p9470125117273"><a name="p9470125117273"></a><a name="p9470125117273"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="40.739999999999995%" id="mcps1.1.5.1.4"><p id="p94716519273"><a name="p94716519273"></a><a name="p94716519273"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row6471105111278"><td class="cellrowborder" valign="top" width="21.04%" headers="mcps1.1.5.1.1 "><p id="p947115118272"><a name="p947115118272"></a><a name="p947115118272"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="30.04%" headers="mcps1.1.5.1.2 "><p id="p685125118283"><a name="p685125118283"></a><a name="p685125118283"></a>AsyncCallback&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.18%" headers="mcps1.1.5.1.3 "><p id="p2047195110270"><a name="p2047195110270"></a><a name="p2047195110270"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.739999999999995%" headers="mcps1.1.5.1.4 "><p id="p16471125182716"><a name="p16471125182716"></a><a name="p16471125182716"></a>Callback invoked to return the result.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    windowClass.destroy((err, data) => {
        if (err) {
            console.error('Failed to destroy the subwindow. Cause:' + JSON.stringify(err));
            return;
        }
        console.info('Succeeded in destroying the subwindow. Data:' + JSON.stringify(data))
    })
    ```


## setOutsideTouchable<sup>7+</sup><a name="section25411655193018"></a>

setOutsideTouchable\(touchable: boolean, callback: AsyncCallback<void\>\): void;

Sets whether the area outside the subwindow is touchable.

-   Parameters

    <a name="table10541755123016"></a>
    <table><thead align="left"><tr id="row854212559309"><th class="cellrowborder" valign="top" width="21.04%" id="mcps1.1.5.1.1"><p id="p14542555133018"><a name="p14542555133018"></a><a name="p14542555133018"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="30.04%" id="mcps1.1.5.1.2"><p id="p1954215520304"><a name="p1954215520304"></a><a name="p1954215520304"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.18%" id="mcps1.1.5.1.3"><p id="p205424558309"><a name="p205424558309"></a><a name="p205424558309"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="40.739999999999995%" id="mcps1.1.5.1.4"><p id="p1154313552309"><a name="p1154313552309"></a><a name="p1154313552309"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row9637932123316"><td class="cellrowborder" valign="top" width="21.04%" headers="mcps1.1.5.1.1 "><p id="p763818322338"><a name="p763818322338"></a><a name="p763818322338"></a>touchable</p>
    </td>
    <td class="cellrowborder" valign="top" width="30.04%" headers="mcps1.1.5.1.2 "><p id="p14638193223316"><a name="p14638193223316"></a><a name="p14638193223316"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.18%" headers="mcps1.1.5.1.3 "><p id="p116386329333"><a name="p116386329333"></a><a name="p116386329333"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.739999999999995%" headers="mcps1.1.5.1.4 "><p id="p14638163253316"><a name="p14638163253316"></a><a name="p14638163253316"></a>Whether the area outside the subwindow is touchable. The value <strong id="b12349596366"><a name="b12349596366"></a><a name="b12349596366"></a>true</strong> means that such an area is touchable, and <strong id="b53405917364"><a name="b53405917364"></a><a name="b53405917364"></a>false</strong> means the opposite.</p>
    </td>
    </tr>
    <tr id="row55431255203017"><td class="cellrowborder" valign="top" width="21.04%" headers="mcps1.1.5.1.1 "><p id="p854319557303"><a name="p854319557303"></a><a name="p854319557303"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="30.04%" headers="mcps1.1.5.1.2 "><p id="p454335511302"><a name="p454335511302"></a><a name="p454335511302"></a>AsyncCallback&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.18%" headers="mcps1.1.5.1.3 "><p id="p854395533013"><a name="p854395533013"></a><a name="p854395533013"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.739999999999995%" headers="mcps1.1.5.1.4 "><p id="p185431655183020"><a name="p185431655183020"></a><a name="p185431655183020"></a>Callback invoked to return the result.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    windowClass.setOutsideTouchable(true, (err, data) => {
        if (err) {
            console.error('Failed to set the area to be touchable. Cause: ' + JSON.stringify(err));
            return;
        }
        console.info('Succeeded in setting the area to be touchable. Data: ' + JSON.stringify(data))
    })
    ```


## on\('keyboardHeightChange'\)<a name="section2719124410557"></a>

on\(type: string, callback: AsyncCallback<number\>\): void

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>This method is deprecated since API version 7.

Enables listening for keyboard height changes.

-   Parameters

    <a name="table7719844105514"></a>
    <table><thead align="left"><tr id="row1872014465512"><th class="cellrowborder" valign="top" width="21.04%" id="mcps1.1.5.1.1"><p id="p127201044135511"><a name="p127201044135511"></a><a name="p127201044135511"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="30.04%" id="mcps1.1.5.1.2"><p id="p1772094412555"><a name="p1772094412555"></a><a name="p1772094412555"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.18%" id="mcps1.1.5.1.3"><p id="p13720184419559"><a name="p13720184419559"></a><a name="p13720184419559"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="40.739999999999995%" id="mcps1.1.5.1.4"><p id="p1472084413557"><a name="p1472084413557"></a><a name="p1472084413557"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row3720184417558"><td class="cellrowborder" valign="top" width="21.04%" headers="mcps1.1.5.1.1 "><p id="p20721144410554"><a name="p20721144410554"></a><a name="p20721144410554"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="30.04%" headers="mcps1.1.5.1.2 "><p id="p17215448551"><a name="p17215448551"></a><a name="p17215448551"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.18%" headers="mcps1.1.5.1.3 "><p id="p187211044145514"><a name="p187211044145514"></a><a name="p187211044145514"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.739999999999995%" headers="mcps1.1.5.1.4 "><p id="p10721104405517"><a name="p10721104405517"></a><a name="p10721104405517"></a>Listening type. Set it to <strong id="b963918138375"><a name="b963918138375"></a><a name="b963918138375"></a>keyboardHeightChange</strong>, which indicates listening for keyboard height changes.</p>
    </td>
    </tr>
    <tr id="row2048713742814"><td class="cellrowborder" valign="top" width="21.04%" headers="mcps1.1.5.1.1 "><p id="p8121191411281"><a name="p8121191411281"></a><a name="p8121191411281"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="30.04%" headers="mcps1.1.5.1.2 "><p id="p17121514202815"><a name="p17121514202815"></a><a name="p17121514202815"></a>AsyncCallback&lt;number&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.18%" headers="mcps1.1.5.1.3 "><p id="p7121514202813"><a name="p7121514202813"></a><a name="p7121514202813"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.739999999999995%" headers="mcps1.1.5.1.4 "><p id="p12121111416285"><a name="p12121111416285"></a><a name="p12121111416285"></a>Callback used to return the keyboard height.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var type= 'keyboardHeightChange';
    windowClass.on(type, (err, data) => {
        if (err) {
            console.error('Failed to enable the listener for keyboard height changes. Cause: ' + JSON.stringify(err));
            return;
        }
        console.info('Succeeded in enabling the listener for keyboard height changes. Data: ' + JSON.stringify(data));
    });
    ```


## off\('keyboardHeightChange'\)<a name="section272294475520"></a>

off\(type: string, callback?: AsyncCallback<number\>\): void

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>This method is deprecated since API version 7.

Disables listening for keyboard height changes.

-   Parameters

    <a name="table114111141141218"></a>
    <table><thead align="left"><tr id="row341284112125"><th class="cellrowborder" valign="top" width="21.04%" id="mcps1.1.5.1.1"><p id="p14412741181220"><a name="p14412741181220"></a><a name="p14412741181220"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="20.57%" id="mcps1.1.5.1.2"><p id="p6412174141211"><a name="p6412174141211"></a><a name="p6412174141211"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.3999999999999995%" id="mcps1.1.5.1.3"><p id="p34121841111214"><a name="p34121841111214"></a><a name="p34121841111214"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="50.99%" id="mcps1.1.5.1.4"><p id="p1741214151211"><a name="p1741214151211"></a><a name="p1741214151211"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row194124414128"><td class="cellrowborder" valign="top" width="21.04%" headers="mcps1.1.5.1.1 "><p id="p154121841121211"><a name="p154121841121211"></a><a name="p154121841121211"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.57%" headers="mcps1.1.5.1.2 "><p id="p24121413122"><a name="p24121413122"></a><a name="p24121413122"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.3999999999999995%" headers="mcps1.1.5.1.3 "><p id="p041210417120"><a name="p041210417120"></a><a name="p041210417120"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="50.99%" headers="mcps1.1.5.1.4 "><p id="p1141212411125"><a name="p1141212411125"></a><a name="p1141212411125"></a>Listener type. Set it to <strong id="b6503031161014"><a name="b6503031161014"></a><a name="b6503031161014"></a>keyboardHeightChange</strong>, which indicates a listener for keyboard height changes.</p>
    </td>
    </tr>
    <tr id="row953705517288"><td class="cellrowborder" valign="top" width="21.04%" headers="mcps1.1.5.1.1 "><p id="p529225892820"><a name="p529225892820"></a><a name="p529225892820"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.57%" headers="mcps1.1.5.1.2 "><p id="p11292165862815"><a name="p11292165862815"></a><a name="p11292165862815"></a>AsyncCallback&lt;number&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.3999999999999995%" headers="mcps1.1.5.1.3 "><p id="p729295815288"><a name="p729295815288"></a><a name="p729295815288"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="50.99%" headers="mcps1.1.5.1.4 "><p id="p1529275815286"><a name="p1529275815286"></a><a name="p1529275815286"></a>Callback used to return the keyboard height.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var type= 'keyboardHeightChange';
    windowClass.off(type);
    ```

### on('keyboardHeightChange'|'windowSizeChange'<sup>7+</sup>|'systemAvoidAreaChange'<sup>7+</sup>)

on(type: string, callback: Callback&lt;AvoidArea | Size | number&gt;): void

Enables listening.

- Parameters

  | Name     | Type                                                         | Mandatory | Description                                                  |
  | -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
  | type     | string                                                       | Yes       | Listening type. <br/>-&nbsp;**keyboardHeightChange**: listening for keyboard height changes.<br/>-&nbsp;**windowSizeChange'7+**: listening for window size changes.<br/>-&nbsp;**systemAvoidAreaChange'7+**: listening for changes to the area where the window cannot be displayed. |
  | callback | Callback&lt;[AvoidArea](#section74393271254)&nbsp;\|&nbsp;[Size](#section695585431120)&nbsp;\|&nbsp;number&gt; | Yes       | Callback used to return the information.                     |

- Example

  ```
  var type = 'windowSizeChange';
  windowClass.on(type, (data) => {
      console.info('Succeeded in enabling the listener for window size changes. Data: ' + JSON.stringify(data));
  });
  ```

### off('keyboardHeightChange'|'windowSizeChange'<sup>7+</sup>|'systemAvoidAreaChange'<sup>7+</sup>)

off(type: string, callback?: Callback&lt;AvoidArea | Size | number&gt;): void

Disables listening.

- Parameters

  | Name     | Type                                                         | Mandatory | Description                                                  |
  | -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
  | type     | string                                                       | Yes       | Listening type. <br/>-&nbsp;**'keyboardHeightChange'**: listening for keyboard height changes.<br/>-&nbsp;**'windowSizeChange'<sup>7+</sup>**: listening for window size changes.<br/>-&nbsp;**'systemAvoidAreaChange'<sup>7+</sup>**: listening for changes to the area where the window cannot be displayed. |
  | callback | Callback&lt;[AvoidArea](#section74393271254)&nbsp;\|&nbsp;[Size](#section695585431120)&nbsp;\|&nbsp;number&gt; | No        | Callback used to return the information.                     |

- Example

  ```
  var type = 'windowSizeChange';
  windowClass.off(type);
  ```
