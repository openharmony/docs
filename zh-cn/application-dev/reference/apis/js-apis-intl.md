# 国际化（Intl）<a name="ZH-CN_TOPIC_0000001103315838"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从 API Version 6 开始支持。

## 导入模块<a name="s56d19203690d4782bfc74069abb6bd71"></a>

```
import intl from '@ohos.intl';
```

## 权限<a name="section11257113618419"></a>

无

## Locale<a name="section422715643011"></a>

### 属性<a name="section1778221585513"></a>

<a name="table1378271515552"></a>
<table><thead align="left"><tr id="row1078291525514"><th class="cellrowborder" valign="top" width="15.870000000000001%" id="mcps1.1.6.1.1"><p id="p17821115155511"><a name="p17821115155511"></a><a name="p17821115155511"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="10.86%" id="mcps1.1.6.1.2"><p id="p47821215145515"><a name="p47821215145515"></a><a name="p47821215145515"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.34%" id="mcps1.1.6.1.3"><p id="p878221545513"><a name="p878221545513"></a><a name="p878221545513"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="p11782121518559"><a name="p11782121518559"></a><a name="p11782121518559"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="p97821715125513"><a name="p97821715125513"></a><a name="p97821715125513"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row3782131535519"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p7782615185518"><a name="p7782615185518"></a><a name="p7782615185518"></a>language</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="p1532011315106"><a name="p1532011315106"></a><a name="p1532011315106"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="p57831415165515"><a name="p57831415165515"></a><a name="p57831415165515"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p17831515175518"><a name="p17831515175518"></a><a name="p17831515175518"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p12783115145518"><a name="p12783115145518"></a><a name="p12783115145518"></a><span>与区域设置关联的语言</span></p>
</td>
</tr>
<tr id="row18783101512558"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p197832015125519"><a name="p197832015125519"></a><a name="p197832015125519"></a>script</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="p19814797107"><a name="p19814797107"></a><a name="p19814797107"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="p1178341516559"><a name="p1178341516559"></a><a name="p1178341516559"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p207831615115519"><a name="p207831615115519"></a><a name="p207831615115519"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p1878311155553"><a name="p1878311155553"></a><a name="p1878311155553"></a><span>语言的书写方式</span></p>
</td>
</tr>
<tr id="row11401739287"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p131413393816"><a name="p131413393816"></a><a name="p131413393816"></a>region</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="p414103920813"><a name="p414103920813"></a><a name="p414103920813"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="p1141183916819"><a name="p1141183916819"></a><a name="p1141183916819"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p16936114313107"><a name="p16936114313107"></a><a name="p16936114313107"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p16141183916818"><a name="p16141183916818"></a><a name="p16141183916818"></a><span>与区域设置相关的</span>地区</p>
</td>
</tr>
<tr id="row324144214819"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p5245421082"><a name="p5245421082"></a><a name="p5245421082"></a>baseName</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="p2024144219810"><a name="p2024144219810"></a><a name="p2024144219810"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="p42415422813"><a name="p42415422813"></a><a name="p42415422813"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p055911448108"><a name="p055911448108"></a><a name="p055911448108"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p4246421818"><a name="p4246421818"></a><a name="p4246421818"></a>Locale的基本核心信息</p>
</td>
</tr>
<tr id="row2182164417817"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p1318214441889"><a name="p1318214441889"></a><a name="p1318214441889"></a>caseFirst</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="p1418211440811"><a name="p1418211440811"></a><a name="p1418211440811"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="p181821344888"><a name="p181821344888"></a><a name="p181821344888"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p119084591015"><a name="p119084591015"></a><a name="p119084591015"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p111822441087"><a name="p111822441087"></a><a name="p111822441087"></a><span>区域的整理规则是否考虑大小写</span></p>
</td>
</tr>
<tr id="row616319461180"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p1416310461486"><a name="p1416310461486"></a><a name="p1416310461486"></a>calendar</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="p1216320461982"><a name="p1216320461982"></a><a name="p1216320461982"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="p916319461588"><a name="p916319461588"></a><a name="p916319461588"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p667234511012"><a name="p667234511012"></a><a name="p667234511012"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p1916315466811"><a name="p1916315466811"></a><a name="p1916315466811"></a>区域的日历信息</p>
</td>
</tr>
<tr id="row97016482083"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p570124810815"><a name="p570124810815"></a><a name="p570124810815"></a>collation</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="p1270748588"><a name="p1270748588"></a><a name="p1270748588"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="p8701648186"><a name="p8701648186"></a><a name="p8701648186"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p1327834619106"><a name="p1327834619106"></a><a name="p1327834619106"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p117094811816"><a name="p117094811816"></a><a name="p117094811816"></a>区域的排序规则</p>
</td>
</tr>
<tr id="row22661650989"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p826710501284"><a name="p826710501284"></a><a name="p826710501284"></a>hourCycle</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="p626745013817"><a name="p626745013817"></a><a name="p626745013817"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="p19267105018810"><a name="p19267105018810"></a><a name="p19267105018810"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p692464614109"><a name="p692464614109"></a><a name="p692464614109"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p19267155017816"><a name="p19267155017816"></a><a name="p19267155017816"></a>区域的时制信息</p>
</td>
</tr>
<tr id="row738595216815"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p133851452181"><a name="p133851452181"></a><a name="p133851452181"></a>numberingSystem</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="p53851520819"><a name="p53851520819"></a><a name="p53851520819"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="p163851852980"><a name="p163851852980"></a><a name="p163851852980"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p9827647161017"><a name="p9827647161017"></a><a name="p9827647161017"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p63855529817"><a name="p63855529817"></a><a name="p63855529817"></a>区域使用的数字系统</p>
</td>
</tr>
<tr id="row1471125410817"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p1571120541820"><a name="p1571120541820"></a><a name="p1571120541820"></a>numeric</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="p67111541886"><a name="p67111541886"></a><a name="p67111541886"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="p171115543810"><a name="p171115543810"></a><a name="p171115543810"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p1845174816106"><a name="p1845174816106"></a><a name="p1845174816106"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p87111354380"><a name="p87111354380"></a><a name="p87111354380"></a><span>是否对数字字符具有特殊的排序规则处理</span></p>
</td>
</tr>
</tbody>
</table>

### constructor<a name="section32282618302"></a>

constructor\(locale: string, options?:options\)

创建区域对象

-   参数：

    <a name="table69661135912"></a>
    <table><thead align="left"><tr id="row149668318915"><th class="cellrowborder" valign="top" width="8.81%" id="mcps1.1.5.1.1"><p id="p7966738914"><a name="p7966738914"></a><a name="p7966738914"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="27.11%" id="mcps1.1.5.1.2"><p id="p296713699"><a name="p296713699"></a><a name="p296713699"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.710000000000001%" id="mcps1.1.5.1.3"><p id="p196718315911"><a name="p196718315911"></a><a name="p196718315911"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="57.37%" id="mcps1.1.5.1.4"><p id="p9967231197"><a name="p9967231197"></a><a name="p9967231197"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row99671533914"><td class="cellrowborder" valign="top" width="8.81%" headers="mcps1.1.5.1.1 "><p id="p13838351705"><a name="p13838351705"></a><a name="p13838351705"></a>locale</p>
    </td>
    <td class="cellrowborder" valign="top" width="27.11%" headers="mcps1.1.5.1.2 "><p id="p11967433914"><a name="p11967433914"></a><a name="p11967433914"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.710000000000001%" headers="mcps1.1.5.1.3 "><p id="p19671336916"><a name="p19671336916"></a><a name="p19671336916"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="57.37%" headers="mcps1.1.5.1.4 "><p id="p69671631796"><a name="p69671631796"></a><a name="p69671631796"></a>包含区域设置信息的字符串，包括语言以及可选的脚本和区域。</p>
    </td>
    </tr>
    <tr id="row14743191495712"><td class="cellrowborder" valign="top" width="8.81%" headers="mcps1.1.5.1.1 "><p id="p11743111475719"><a name="p11743111475719"></a><a name="p11743111475719"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="27.11%" headers="mcps1.1.5.1.2 "><p id="p1274415142572"><a name="p1274415142572"></a><a name="p1274415142572"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.710000000000001%" headers="mcps1.1.5.1.3 "><p id="p6744181425719"><a name="p6744181425719"></a><a name="p6744181425719"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="57.37%" headers="mcps1.1.5.1.4 "><p id="p1974414145576"><a name="p1974414145576"></a><a name="p1974414145576"></a>用于创建区域对象的选项。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例：

    ```
    var locale = new Locale("zh-CN");
    ```


### toString<a name="section6361163518520"></a>

toString\(\): string

将区域信息转换为字符串

-   返回值：

    <a name="table97866231562"></a>
    <table><thead align="left"><tr id="row378662317610"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p4786423668"><a name="p4786423668"></a><a name="p4786423668"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p578682318614"><a name="p578682318614"></a><a name="p578682318614"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row177861823963"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p1078617238618"><a name="p1078617238618"></a><a name="p1078617238618"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p578611231565"><a name="p578611231565"></a><a name="p578611231565"></a>字符串形式的区域信息</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例：

    ```
    var locale = new Locale("zh-CN");
    locale.toString();
    ```


### maximize<a name="section16459237152"></a>

maximize\(\): Locale

最大化区域信息，若缺少脚本与地区信息，则补齐。

-   返回值：

    <a name="table94114239714"></a>
    <table><thead align="left"><tr id="row3411112311714"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p04119231171"><a name="p04119231171"></a><a name="p04119231171"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p164119231574"><a name="p164119231574"></a><a name="p164119231574"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row941112231572"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p341102317718"><a name="p341102317718"></a><a name="p341102317718"></a>Locale</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p1341122314711"><a name="p1341122314711"></a><a name="p1341122314711"></a>最大化后的区域对象</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例：

    ```
    var locale = new Locale("zh-CN");
    locale.maximize();
    ```


### minimize<a name="section8112183915517"></a>

minimize\(\): Locale

最小化区域信息，若包含脚本与地区信息，则去除。

-   返回值：

    <a name="table128315221814"></a>
    <table><thead align="left"><tr id="row6831152215817"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p3831192213819"><a name="p3831192213819"></a><a name="p3831192213819"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p1883214221088"><a name="p1883214221088"></a><a name="p1883214221088"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1183218227818"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p483210226819"><a name="p483210226819"></a><a name="p483210226819"></a>Locale</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p17832222781"><a name="p17832222781"></a><a name="p17832222781"></a>最小化后的区域对象</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例：

    ```
    var locale = new Locale("zh-CN");
    locale.minimize();
    ```


## DateTimeFormat<a name="section164003264319"></a>

### constructor<a name="section740052693112"></a>

constructor\(locale: string, options?:DateTimeOptions\)

创建时间日期格式化对象。

-   参数：

    <a name="table356962217321"></a>
    <table><thead align="left"><tr id="row185691227322"><th class="cellrowborder" valign="top" width="11.119698579847357%" id="mcps1.1.5.1.1"><p id="p18569132213213"><a name="p18569132213213"></a><a name="p18569132213213"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="22.905999420345864%" id="mcps1.1.5.1.2"><p id="p25691822183218"><a name="p25691822183218"></a><a name="p25691822183218"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.356873732006569%" id="mcps1.1.5.1.3"><p id="p14569192218320"><a name="p14569192218320"></a><a name="p14569192218320"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.61742826780022%" id="mcps1.1.5.1.4"><p id="p556972263210"><a name="p556972263210"></a><a name="p556972263210"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1756982217321"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="p20569132223214"><a name="p20569132223214"></a><a name="p20569132223214"></a>locale</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="p1856902273219"><a name="p1856902273219"></a><a name="p1856902273219"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="p15569142233219"><a name="p15569142233219"></a><a name="p15569142233219"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="p18569162212321"><a name="p18569162212321"></a><a name="p18569162212321"></a>包含区域设置信息的字符串，包括语言以及可选的脚本和区域。</p>
    </td>
    </tr>
    <tr id="row056902210325"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="p145697223321"><a name="p145697223321"></a><a name="p145697223321"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="p956962219323"><a name="p956962219323"></a><a name="p956962219323"></a><a href="#section12882825611">DateTimeOptions</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="p195695222325"><a name="p195695222325"></a><a name="p195695222325"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="p8569922103214"><a name="p8569922103214"></a><a name="p8569922103214"></a>用于创建时间日期格式化的选项。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例：

    ```
    var datefmt= new DateTimeFormat("zh-CN", { dateStyle: 'full', timeStyle: 'medium' });
    ```


### constructor<a name="section1400182613114"></a>

constructor\(locales: Array<string\>, options?:DateTimeOptions\)

创建时间日期格式化对象。

-   参数：

    <a name="table1429997153311"></a>
    <table><thead align="left"><tr id="row229911773310"><th class="cellrowborder" valign="top" width="11.119698579847357%" id="mcps1.1.5.1.1"><p id="p15299171333"><a name="p15299171333"></a><a name="p15299171333"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="22.905999420345864%" id="mcps1.1.5.1.2"><p id="p1629912719331"><a name="p1629912719331"></a><a name="p1629912719331"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.356873732006569%" id="mcps1.1.5.1.3"><p id="p829916783311"><a name="p829916783311"></a><a name="p829916783311"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.61742826780022%" id="mcps1.1.5.1.4"><p id="p4299279331"><a name="p4299279331"></a><a name="p4299279331"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row52991074332"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="p1229911717332"><a name="p1229911717332"></a><a name="p1229911717332"></a>locales</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="p83001273339"><a name="p83001273339"></a><a name="p83001273339"></a>Array&lt;string&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="p113001717331"><a name="p113001717331"></a><a name="p113001717331"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="p153001778336"><a name="p153001778336"></a><a name="p153001778336"></a>包含区域设置信息的字符串的数组。</p>
    </td>
    </tr>
    <tr id="row23000715337"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="p133007743315"><a name="p133007743315"></a><a name="p133007743315"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="p83001783320"><a name="p83001783320"></a><a name="p83001783320"></a><a href="#section12882825611">DateTimeOptions</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="p230013713339"><a name="p230013713339"></a><a name="p230013713339"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="p20300374333"><a name="p20300374333"></a><a name="p20300374333"></a>用于创建时间日期格式化的选项。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例：

    ```
    var datefmt= new DateTimeFormat(["ban", "zh"], { dateStyle: 'full', timeStyle: 'medium' });
    ```


### format<a name="section1840262614313"></a>

format\(date: Date\): string;

格式化时间日期字符串。

-   参数：

    <a name="table104041622203411"></a>
    <table><thead align="left"><tr id="row3405102263418"><th class="cellrowborder" valign="top" width="11.119698579847357%" id="mcps1.1.5.1.1"><p id="p164051422183414"><a name="p164051422183414"></a><a name="p164051422183414"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="22.905999420345864%" id="mcps1.1.5.1.2"><p id="p194051522123413"><a name="p194051522123413"></a><a name="p194051522123413"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.356873732006569%" id="mcps1.1.5.1.3"><p id="p1405922193417"><a name="p1405922193417"></a><a name="p1405922193417"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.61742826780022%" id="mcps1.1.5.1.4"><p id="p1140516225342"><a name="p1140516225342"></a><a name="p1140516225342"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row9405822163419"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="p104051322173411"><a name="p104051322173411"></a><a name="p104051322173411"></a>date</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="p740519224344"><a name="p740519224344"></a><a name="p740519224344"></a>Date</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="p194051122173417"><a name="p194051122173417"></a><a name="p194051122173417"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="p19405172212342"><a name="p19405172212342"></a><a name="p19405172212342"></a>时间日期对象。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="table9402122612316"></a>
    <table><thead align="left"><tr id="row104029264319"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p440212633116"><a name="p440212633116"></a><a name="p440212633116"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p144021226173112"><a name="p144021226173112"></a><a name="p144021226173112"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row3402112617311"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p340262673111"><a name="p340262673111"></a><a name="p340262673111"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p1040215260316"><a name="p1040215260316"></a><a name="p1040215260316"></a>格式化后的时间日期字符串</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例：

    ```
    var date = new Date(2021, 11, 17, 3, 24, 0);
    var datefmt = new Intl.DateTimeFormat("en-GB");
    datefmt.format(date);
    ```


### formatRange<a name="section4402132614312"></a>

formatRange\(fromDate: Date, toDate: Date\): string;

格式化时间日期段字符串。

-   参数：

    <a name="table24021326153112"></a>
    <table><thead align="left"><tr id="row15403126153116"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p3403182693112"><a name="p3403182693112"></a><a name="p3403182693112"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p1640372611319"><a name="p1640372611319"></a><a name="p1640372611319"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p1540352615319"><a name="p1540352615319"></a><a name="p1540352615319"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p17403152623117"><a name="p17403152623117"></a><a name="p17403152623117"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row11403182693114"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p15403726183117"><a name="p15403726183117"></a><a name="p15403726183117"></a>startDate</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p124033261313"><a name="p124033261313"></a><a name="p124033261313"></a>Date</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p124039266311"><a name="p124039266311"></a><a name="p124039266311"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p840362633117"><a name="p840362633117"></a><a name="p840362633117"></a>起始的时间日期</p>
    </td>
    </tr>
    <tr id="row4629861544"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p66299618414"><a name="p66299618414"></a><a name="p66299618414"></a>endDate</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p136291962419"><a name="p136291962419"></a><a name="p136291962419"></a>Date</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p186296610412"><a name="p186296610412"></a><a name="p186296610412"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p116291262415"><a name="p116291262415"></a><a name="p116291262415"></a>结束的时间日期</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="table114031226173116"></a>
    <table><thead align="left"><tr id="row204031126123119"><th class="cellrowborder" valign="top" width="20.05%" id="mcps1.1.3.1.1"><p id="p64036261318"><a name="p64036261318"></a><a name="p64036261318"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.95%" id="mcps1.1.3.1.2"><p id="p4403132613317"><a name="p4403132613317"></a><a name="p4403132613317"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row19403162616316"><td class="cellrowborder" valign="top" width="20.05%" headers="mcps1.1.3.1.1 "><p id="p15404132673120"><a name="p15404132673120"></a><a name="p15404132673120"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.95%" headers="mcps1.1.3.1.2 "><p id="p94042261310"><a name="p94042261310"></a><a name="p94042261310"></a>格式化后的时间日期段字符串</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例：

    ```
    var startDate = new Date(2021, 11, 17, 3, 24, 0);
    var endDate = new Date(2021, 11, 18, 3, 24, 0);
    var datefmt = new Intl.DateTimeFormat("en-GB");
    datefmt.formatRange(startDate, endDate);
    ```


### resolvedOptions<a name="section1093513817123"></a>

resolvedOptions\(\): DateTimeOptions

获取DateTimeFormat 对象的格式化选项。

-   返回值：

    <a name="table1393663841210"></a>
    <table><thead align="left"><tr id="row5936113816126"><th class="cellrowborder" valign="top" width="20.05%" id="mcps1.1.3.1.1"><p id="p1493614383126"><a name="p1493614383126"></a><a name="p1493614383126"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.95%" id="mcps1.1.3.1.2"><p id="p1293633819124"><a name="p1293633819124"></a><a name="p1293633819124"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row393643871210"><td class="cellrowborder" valign="top" width="20.05%" headers="mcps1.1.3.1.1 "><p id="p9936163816125"><a name="p9936163816125"></a><a name="p9936163816125"></a><a href="#section12882825611">DateTimeOptions</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="79.95%" headers="mcps1.1.3.1.2 "><p id="p13936143812129"><a name="p13936143812129"></a><a name="p13936143812129"></a>DateTimeFormat 对象的格式化选项。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例：

    ```
    var datefmt = new Intl.DateTimeFormat("en-GB");
    datefmt.resolvedOptions();
    ```


## NumberFormat<a name="section10453336123119"></a>

### constructor<a name="section14453163693117"></a>

constructor\(locale: string, options?:NumberOptions\)

创建数字格式化对象。

参数：

<a name="table830832401619"></a>
<table><thead align="left"><tr id="row23081824181616"><th class="cellrowborder" valign="top" width="11.119698579847357%" id="mcps1.1.5.1.1"><p id="p1930892416168"><a name="p1930892416168"></a><a name="p1930892416168"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="22.905999420345864%" id="mcps1.1.5.1.2"><p id="p14308112431619"><a name="p14308112431619"></a><a name="p14308112431619"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="6.356873732006569%" id="mcps1.1.5.1.3"><p id="p173081324151614"><a name="p173081324151614"></a><a name="p173081324151614"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="59.61742826780022%" id="mcps1.1.5.1.4"><p id="p123092024101615"><a name="p123092024101615"></a><a name="p123092024101615"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row14309192401619"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="p03096245167"><a name="p03096245167"></a><a name="p03096245167"></a>locale</p>
</td>
<td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="p73094243167"><a name="p73094243167"></a><a name="p73094243167"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="p5309192461611"><a name="p5309192461611"></a><a name="p5309192461611"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="p133091924181620"><a name="p133091924181620"></a><a name="p133091924181620"></a>包含区域设置信息的字符串，包括语言以及可选的脚本和区域。</p>
</td>
</tr>
<tr id="row133091924171615"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="p53091824181619"><a name="p53091824181619"></a><a name="p53091824181619"></a>options</p>
</td>
<td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="p7309424171618"><a name="p7309424171618"></a><a name="p7309424171618"></a><a href="#section7200123494410">NumberOptions</a></p>
</td>
<td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="p3309202414168"><a name="p3309202414168"></a><a name="p3309202414168"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="p6309202413162"><a name="p6309202413162"></a><a name="p6309202413162"></a>用于创建数字格式化的选项。</p>
</td>
</tr>
</tbody>
</table>

-   示例：

    ```
    var numfmt = new Intl.NumberFormat("en-GB", {style:'decimal', notation:"scientific"});
    ```


### constructor<a name="section54533363319"></a>

constructor\(locales: Array<string\>, options?:NumberOptions\)

创建数字格式化对象。

-   参数：

    <a name="table1886184401618"></a>
    <table><thead align="left"><tr id="row68615446163"><th class="cellrowborder" valign="top" width="10.73326248671626%" id="mcps1.1.5.1.1"><p id="p88611446168"><a name="p88611446168"></a><a name="p88611446168"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="23.29243551347696%" id="mcps1.1.5.1.2"><p id="p12861644191616"><a name="p12861644191616"></a><a name="p12861644191616"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.356873732006569%" id="mcps1.1.5.1.3"><p id="p7861174419169"><a name="p7861174419169"></a><a name="p7861174419169"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.61742826780022%" id="mcps1.1.5.1.4"><p id="p14862744191618"><a name="p14862744191618"></a><a name="p14862744191618"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row20862544191620"><td class="cellrowborder" valign="top" width="10.73326248671626%" headers="mcps1.1.5.1.1 "><p id="p3862344191619"><a name="p3862344191619"></a><a name="p3862344191619"></a>locales</p>
    </td>
    <td class="cellrowborder" valign="top" width="23.29243551347696%" headers="mcps1.1.5.1.2 "><p id="p28621044131614"><a name="p28621044131614"></a><a name="p28621044131614"></a>Array&lt;string&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="p1086211440167"><a name="p1086211440167"></a><a name="p1086211440167"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="p386234417161"><a name="p386234417161"></a><a name="p386234417161"></a>包含区域设置信息的字符串的数组。</p>
    </td>
    </tr>
    <tr id="row986254461614"><td class="cellrowborder" valign="top" width="10.73326248671626%" headers="mcps1.1.5.1.1 "><p id="p88621344181616"><a name="p88621344181616"></a><a name="p88621344181616"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="23.29243551347696%" headers="mcps1.1.5.1.2 "><p id="p486284417168"><a name="p486284417168"></a><a name="p486284417168"></a><a href="#section7200123494410">NumberOptions</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="p1986216442160"><a name="p1986216442160"></a><a name="p1986216442160"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="p4862104421615"><a name="p4862104421615"></a><a name="p4862104421615"></a>用于创建数字格式化的选项。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例：

    ```
    var numfmt = new Intl.NumberFormat(["en-GB", "zh"], {style:'decimal', notation:"scientific"});
    ```


### format<a name="section94551936203114"></a>

format\(number: number\): string;

格式化数字字符串。

-   参数：

    <a name="table1459775620188"></a>
    <table><thead align="left"><tr id="row059755610184"><th class="cellrowborder" valign="top" width="11.119698579847357%" id="mcps1.1.5.1.1"><p id="p19597205631810"><a name="p19597205631810"></a><a name="p19597205631810"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="22.905999420345864%" id="mcps1.1.5.1.2"><p id="p18597856161815"><a name="p18597856161815"></a><a name="p18597856161815"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.356873732006569%" id="mcps1.1.5.1.3"><p id="p1859735614180"><a name="p1859735614180"></a><a name="p1859735614180"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.61742826780022%" id="mcps1.1.5.1.4"><p id="p145971656101812"><a name="p145971656101812"></a><a name="p145971656101812"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row11597195617186"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="p1959755631818"><a name="p1959755631818"></a><a name="p1959755631818"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="p12597155613186"><a name="p12597155613186"></a><a name="p12597155613186"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="p1559865612186"><a name="p1559865612186"></a><a name="p1559865612186"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="p95981556161816"><a name="p95981556161816"></a><a name="p95981556161816"></a>数字对象</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="table114558369317"></a>
    <table><thead align="left"><tr id="row12455133613312"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p545515361318"><a name="p545515361318"></a><a name="p545515361318"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p145512362311"><a name="p145512362311"></a><a name="p145512362311"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row3455193617316"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p745523619314"><a name="p745523619314"></a><a name="p745523619314"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p1745519363315"><a name="p1745519363315"></a><a name="p1745519363315"></a>格式化后的数字字符串</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例：

    ```
    var numfmt = new Intl.NumberFormat(["en-GB", "zh"], {style:'decimal', notation:"scientific"});
    numfmt.format(1223);
    ```


### resolvedOptions<a name="section13178203919219"></a>

resolvedOptions\(\): NumberOptions

获取NumberFormat 对象的格式化选项。

-   返回值：

    <a name="table917813992117"></a>
    <table><thead align="left"><tr id="row1717883992116"><th class="cellrowborder" valign="top" width="20.05%" id="mcps1.1.3.1.1"><p id="p91781539202115"><a name="p91781539202115"></a><a name="p91781539202115"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.95%" id="mcps1.1.3.1.2"><p id="p151783399216"><a name="p151783399216"></a><a name="p151783399216"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1217814392214"><td class="cellrowborder" valign="top" width="20.05%" headers="mcps1.1.3.1.1 "><p id="p317903912212"><a name="p317903912212"></a><a name="p317903912212"></a><a href="#section7200123494410">NumberOptions</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="79.95%" headers="mcps1.1.3.1.2 "><p id="p111794399212"><a name="p111794399212"></a><a name="p111794399212"></a>NumberFormat 对象的格式化选项。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例：

    ```
    var numfmt = new Intl.NumberFormat(["en-GB", "zh"], {style:'decimal', notation:"scientific"});
    numfmt.resolvedOptions();
    ```


## DateTimeOptions<a name="section12882825611"></a>

表示时间日期格式化选项。

### 属性<a name="section1059684317312"></a>

<a name="table1459620431636"></a>
<table><thead align="left"><tr id="row25971143435"><th class="cellrowborder" valign="top" width="18.91%" id="mcps1.1.6.1.1"><p id="p1559716434320"><a name="p1559716434320"></a><a name="p1559716434320"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="7.82%" id="mcps1.1.6.1.2"><p id="p3597743539"><a name="p3597743539"></a><a name="p3597743539"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.33%" id="mcps1.1.6.1.3"><p id="p15971343131"><a name="p15971343131"></a><a name="p15971343131"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="11.52%" id="mcps1.1.6.1.4"><p id="p1459715436311"><a name="p1459715436311"></a><a name="p1459715436311"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="p75975439316"><a name="p75975439316"></a><a name="p75975439316"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row95971943839"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.6.1.1 "><p id="p85976431431"><a name="p85976431431"></a><a name="p85976431431"></a>locale</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.2 "><p id="p1427924663417"><a name="p1427924663417"></a><a name="p1427924663417"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.1.6.1.3 "><p id="p1059711439317"><a name="p1059711439317"></a><a name="p1059711439317"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.6.1.4 "><p id="p659715430317"><a name="p659715430317"></a><a name="p659715430317"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p12781024121115"><a name="p12781024121115"></a><a name="p12781024121115"></a>区域参数</p>
</td>
</tr>
<tr id="row185973435316"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.6.1.1 "><p id="p1559710432310"><a name="p1559710432310"></a><a name="p1559710432310"></a>dateStyle</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.2 "><p id="p16597144318312"><a name="p16597144318312"></a><a name="p16597144318312"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.1.6.1.3 "><p id="p12597194313317"><a name="p12597194313317"></a><a name="p12597194313317"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.6.1.4 "><p id="p892910583102"><a name="p892910583102"></a><a name="p892910583102"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p1916912791117"><a name="p1916912791117"></a><a name="p1916912791117"></a>日期显示格式，取值范围："long", "short", "medium", "full"</p>
</td>
</tr>
<tr id="row892411307269"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.6.1.1 "><p id="p139241230192614"><a name="p139241230192614"></a><a name="p139241230192614"></a>timeStyle</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.2 "><p id="p4924183062614"><a name="p4924183062614"></a><a name="p4924183062614"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.1.6.1.3 "><p id="p15401682357"><a name="p15401682357"></a><a name="p15401682357"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.6.1.4 "><p id="p1896275851018"><a name="p1896275851018"></a><a name="p1896275851018"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p2925830132619"><a name="p2925830132619"></a><a name="p2925830132619"></a>时间显示格式，取值范围："long", "short", "medium", "full"</p>
</td>
</tr>
<tr id="row155315532719"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.6.1.1 "><p id="p185321542713"><a name="p185321542713"></a><a name="p185321542713"></a>hourCycle</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.2 "><p id="p1053218512273"><a name="p1053218512273"></a><a name="p1053218512273"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.1.6.1.3 "><p id="p18721483357"><a name="p18721483357"></a><a name="p18721483357"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.6.1.4 "><p id="p799415812103"><a name="p799415812103"></a><a name="p799415812103"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p4532135152710"><a name="p4532135152710"></a><a name="p4532135152710"></a>时制格式，取值范围："h11", "h12", "h23", "h24".</p>
</td>
</tr>
<tr id="row46421838277"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.6.1.1 "><p id="p136422030277"><a name="p136422030277"></a><a name="p136422030277"></a>timeZone</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.2 "><p id="p1364283182710"><a name="p1364283182710"></a><a name="p1364283182710"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.1.6.1.3 "><p id="p11029833510"><a name="p11029833510"></a><a name="p11029833510"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.6.1.4 "><p id="p18260598105"><a name="p18260598105"></a><a name="p18260598105"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p5642103122711"><a name="p5642103122711"></a><a name="p5642103122711"></a>使用的时区（<span>合法的</span><span>IANA</span><span>时区</span>ID）</p>
</td>
</tr>
<tr id="row589712142718"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.6.1.1 "><p id="p1689719132719"><a name="p1689719132719"></a><a name="p1689719132719"></a>numberingSystem</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.2 "><p id="p28971919276"><a name="p28971919276"></a><a name="p28971919276"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.1.6.1.3 "><p id="p9132118153512"><a name="p9132118153512"></a><a name="p9132118153512"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.6.1.4 "><p id="p95865961017"><a name="p95865961017"></a><a name="p95865961017"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p16897111192718"><a name="p16897111192718"></a><a name="p16897111192718"></a>数字系统</p>
</td>
</tr>
<tr id="row1190575820265"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.6.1.1 "><p id="p1590585832620"><a name="p1590585832620"></a><a name="p1590585832620"></a>hour12</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.2 "><p id="p119051584269"><a name="p119051584269"></a><a name="p119051584269"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.1.6.1.3 "><p id="p131611815350"><a name="p131611815350"></a><a name="p131611815350"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.6.1.4 "><p id="p1190559111013"><a name="p1190559111013"></a><a name="p1190559111013"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p13905558122617"><a name="p13905558122617"></a><a name="p13905558122617"></a>是否使用12小时制</p>
</td>
</tr>
<tr id="row62191578267"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.6.1.1 "><p id="p122191578263"><a name="p122191578263"></a><a name="p122191578263"></a>weekday</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.2 "><p id="p8219145713262"><a name="p8219145713262"></a><a name="p8219145713262"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.1.6.1.3 "><p id="p719114893513"><a name="p719114893513"></a><a name="p719114893513"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.6.1.4 "><p id="p712345916107"><a name="p712345916107"></a><a name="p712345916107"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p10220457132611"><a name="p10220457132611"></a><a name="p10220457132611"></a>工作日的显示格式，取值范围："long", "short", "narrow"</p>
</td>
</tr>
<tr id="row02045559268"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.6.1.1 "><p id="p14205155152614"><a name="p14205155152614"></a><a name="p14205155152614"></a>era</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.2 "><p id="p1820525515263"><a name="p1820525515263"></a><a name="p1820525515263"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.1.6.1.3 "><p id="p112201486359"><a name="p112201486359"></a><a name="p112201486359"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.6.1.4 "><p id="p3155195991017"><a name="p3155195991017"></a><a name="p3155195991017"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p10205255192611"><a name="p10205255192611"></a><a name="p10205255192611"></a>时代的显示格式，取值范围："long", "short", "narrow"</p>
</td>
</tr>
<tr id="row3849155211268"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.6.1.1 "><p id="p284995232620"><a name="p284995232620"></a><a name="p284995232620"></a>year</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.2 "><p id="p10849115213267"><a name="p10849115213267"></a><a name="p10849115213267"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.1.6.1.3 "><p id="p182511818353"><a name="p182511818353"></a><a name="p182511818353"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.6.1.4 "><p id="p20187185951015"><a name="p20187185951015"></a><a name="p20187185951015"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p15849135232613"><a name="p15849135232613"></a><a name="p15849135232613"></a>年份的显示格式，取值范围："numeric", "2-digit"</p>
</td>
</tr>
<tr id="row34024782614"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.6.1.1 "><p id="p164034752617"><a name="p164034752617"></a><a name="p164034752617"></a>month</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.2 "><p id="p1940947142619"><a name="p1940947142619"></a><a name="p1940947142619"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.1.6.1.3 "><p id="p828220873520"><a name="p828220873520"></a><a name="p828220873520"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.6.1.4 "><p id="p2022014593105"><a name="p2022014593105"></a><a name="p2022014593105"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p141304632716"><a name="p141304632716"></a><a name="p141304632716"></a>月份的显示格式，取值范围："numeric", "2-digit", "long", "short", "narrow"</p>
</td>
</tr>
<tr id="row118165484263"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.6.1.1 "><p id="p158165489261"><a name="p158165489261"></a><a name="p158165489261"></a>day</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.2 "><p id="p18161948102618"><a name="p18161948102618"></a><a name="p18161948102618"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.1.6.1.3 "><p id="p73121981351"><a name="p73121981351"></a><a name="p73121981351"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.6.1.4 "><p id="p132521859111016"><a name="p132521859111016"></a><a name="p132521859111016"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p1181619481262"><a name="p1181619481262"></a><a name="p1181619481262"></a>日期的显示格式，取值范围："numeric", "2-digit"</p>
</td>
</tr>
<tr id="row7924115012611"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.6.1.1 "><p id="p159241050202616"><a name="p159241050202616"></a><a name="p159241050202616"></a>hour</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.2 "><p id="p18924195042619"><a name="p18924195042619"></a><a name="p18924195042619"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.1.6.1.3 "><p id="p93411811352"><a name="p93411811352"></a><a name="p93411811352"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.6.1.4 "><p id="p8285165918102"><a name="p8285165918102"></a><a name="p8285165918102"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p11925185010261"><a name="p11925185010261"></a><a name="p11925185010261"></a>小时的显示格式，取值范围："numeric", "2-digit"</p>
</td>
</tr>
<tr id="row1315614310269"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.6.1.1 "><p id="p11571431266"><a name="p11571431266"></a><a name="p11571431266"></a>minute</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.2 "><p id="p20157443172618"><a name="p20157443172618"></a><a name="p20157443172618"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.1.6.1.3 "><p id="p18370168193519"><a name="p18370168193519"></a><a name="p18370168193519"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.6.1.4 "><p id="p83171059181017"><a name="p83171059181017"></a><a name="p83171059181017"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p1615714382614"><a name="p1615714382614"></a><a name="p1615714382614"></a>分钟的显示格式，取值范围："numeric", "2-digit"</p>
</td>
</tr>
<tr id="row1126474532619"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.6.1.1 "><p id="p426414514261"><a name="p426414514261"></a><a name="p426414514261"></a>second</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.2 "><p id="p182641245182611"><a name="p182641245182611"></a><a name="p182641245182611"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.1.6.1.3 "><p id="p0400489357"><a name="p0400489357"></a><a name="p0400489357"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.6.1.4 "><p id="p8350125917104"><a name="p8350125917104"></a><a name="p8350125917104"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p521718134287"><a name="p521718134287"></a><a name="p521718134287"></a>秒钟的显示格式，取值范围："numeric", "2-digit"</p>
</td>
</tr>
<tr id="row132981741152616"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.6.1.1 "><p id="p1029894117268"><a name="p1029894117268"></a><a name="p1029894117268"></a>timeZoneName</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.2 "><p id="p9298174119264"><a name="p9298174119264"></a><a name="p9298174119264"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.1.6.1.3 "><p id="p942998103512"><a name="p942998103512"></a><a name="p942998103512"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.6.1.4 "><p id="p133831591107"><a name="p133831591107"></a><a name="p133831591107"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p2299104182619"><a name="p2299104182619"></a><a name="p2299104182619"></a>时区名称的本地化表示</p>
</td>
</tr>
<tr id="row2912163872615"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.6.1.1 "><p id="p19131838162614"><a name="p19131838162614"></a><a name="p19131838162614"></a>dayPeriod</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.2 "><p id="p991383832614"><a name="p991383832614"></a><a name="p991383832614"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.1.6.1.3 "><p id="p2458980359"><a name="p2458980359"></a><a name="p2458980359"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.6.1.4 "><p id="p541713599102"><a name="p541713599102"></a><a name="p541713599102"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p1591343818268"><a name="p1591343818268"></a><a name="p1591343818268"></a>时段的显示格式，取值范围："long", "short", "narrow"</p>
</td>
</tr>
<tr id="row1971020367261"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.6.1.1 "><p id="p8710193620264"><a name="p8710193620264"></a><a name="p8710193620264"></a>localeMatcher</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.2 "><p id="p187102362268"><a name="p187102362268"></a><a name="p187102362268"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.1.6.1.3 "><p id="p17487882353"><a name="p17487882353"></a><a name="p17487882353"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.6.1.4 "><p id="p144995901011"><a name="p144995901011"></a><a name="p144995901011"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p1071013692610"><a name="p1071013692610"></a><a name="p1071013692610"></a>要使用的区域匹配算法，取值范围："lookup", "best fit"</p>
</td>
</tr>
<tr id="row3436123312264"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.6.1.1 "><p id="p18437163318262"><a name="p18437163318262"></a><a name="p18437163318262"></a>formatMatcher</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.2 "><p id="p443773315263"><a name="p443773315263"></a><a name="p443773315263"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.1.6.1.3 "><p id="p185163893515"><a name="p185163893515"></a><a name="p185163893515"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.6.1.4 "><p id="p1448195961012"><a name="p1448195961012"></a><a name="p1448195961012"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p043711339264"><a name="p043711339264"></a><a name="p043711339264"></a>要使用的格式匹配算法，取值范围："basic", "best fit"</p>
</td>
</tr>
</tbody>
</table>

## NumberOptions<a name="section7200123494410"></a>

表示设备支持的能力。

### 属性<a name="section2201153419440"></a>

<a name="table16201103444414"></a>
<table><thead align="left"><tr id="row620123444415"><th class="cellrowborder" valign="top" width="19.15%" id="mcps1.1.6.1.1"><p id="p1620163494418"><a name="p1620163494418"></a><a name="p1620163494418"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="10.8%" id="mcps1.1.6.1.2"><p id="p15201434124418"><a name="p15201434124418"></a><a name="p15201434124418"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="6.12%" id="mcps1.1.6.1.3"><p id="p13201123484412"><a name="p13201123484412"></a><a name="p13201123484412"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="11.48%" id="mcps1.1.6.1.4"><p id="p1320123412448"><a name="p1320123412448"></a><a name="p1320123412448"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="52.449999999999996%" id="mcps1.1.6.1.5"><p id="p9201934134419"><a name="p9201934134419"></a><a name="p9201934134419"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row3201103494415"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p20826502499"><a name="p20826502499"></a><a name="p20826502499"></a>locale</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p120143413448"><a name="p120143413448"></a><a name="p120143413448"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p18201334114417"><a name="p18201334114417"></a><a name="p18201334114417"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p420113347441"><a name="p420113347441"></a><a name="p420113347441"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p8689133923516"><a name="p8689133923516"></a><a name="p8689133923516"></a>区域参数</p>
</td>
</tr>
<tr id="row19202113413445"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p82028341442"><a name="p82028341442"></a><a name="p82028341442"></a>currency</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p20653010153513"><a name="p20653010153513"></a><a name="p20653010153513"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p142021134164413"><a name="p142021134164413"></a><a name="p142021134164413"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p163525312356"><a name="p163525312356"></a><a name="p163525312356"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p112021341446"><a name="p112021341446"></a><a name="p112021341446"></a>货币单位</p>
</td>
</tr>
<tr id="row181651537153112"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p6165137193115"><a name="p6165137193115"></a><a name="p6165137193115"></a>currencySign</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p26712105353"><a name="p26712105353"></a><a name="p26712105353"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p20320102716353"><a name="p20320102716353"></a><a name="p20320102716353"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p53383279356"><a name="p53383279356"></a><a name="p53383279356"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p416563763115"><a name="p416563763115"></a><a name="p416563763115"></a>货币单位的符号显示</p>
</td>
</tr>
<tr id="row02243913313"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p922173963114"><a name="p922173963114"></a><a name="p922173963114"></a>currencyDisplay</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p146881510173515"><a name="p146881510173515"></a><a name="p146881510173515"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p18355122710359"><a name="p18355122710359"></a><a name="p18355122710359"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p237211277353"><a name="p237211277353"></a><a name="p237211277353"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p15225393313"><a name="p15225393313"></a><a name="p15225393313"></a>货币的显示方式，取值范围："symbol", "narrowSymbol", "code", "name"</p>
</td>
</tr>
<tr id="row04912413319"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p349204110313"><a name="p349204110313"></a><a name="p349204110313"></a>unit</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p4705161018358"><a name="p4705161018358"></a><a name="p4705161018358"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p938862743518"><a name="p938862743518"></a><a name="p938862743518"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p440462743518"><a name="p440462743518"></a><a name="p440462743518"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p2499410317"><a name="p2499410317"></a><a name="p2499410317"></a>单位</p>
</td>
</tr>
<tr id="row17758199133220"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p13758129103211"><a name="p13758129103211"></a><a name="p13758129103211"></a>unitDisplay</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p1772013101356"><a name="p1772013101356"></a><a name="p1772013101356"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p1342018270359"><a name="p1342018270359"></a><a name="p1342018270359"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p184363276352"><a name="p184363276352"></a><a name="p184363276352"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p8758119193219"><a name="p8758119193219"></a><a name="p8758119193219"></a>单位的显示格式，取值范围："long", "short", "medium"</p>
</td>
</tr>
<tr id="row1244996173217"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p845017623210"><a name="p845017623210"></a><a name="p845017623210"></a>signDisplay</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p1373617108355"><a name="p1373617108355"></a><a name="p1373617108355"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p545216279357"><a name="p545216279357"></a><a name="p545216279357"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p746817276358"><a name="p746817276358"></a><a name="p746817276358"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p154508613320"><a name="p154508613320"></a><a name="p154508613320"></a>数字符号的显示格式，取值范围："auto", "never", "always", "expectZero"</p>
</td>
</tr>
<tr id="row119376594318"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p2093765973119"><a name="p2093765973119"></a><a name="p2093765973119"></a>compactDisplay</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p1375319107353"><a name="p1375319107353"></a><a name="p1375319107353"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p19485202719353"><a name="p19485202719353"></a><a name="p19485202719353"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p35017277357"><a name="p35017277357"></a><a name="p35017277357"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p4938135915318"><a name="p4938135915318"></a><a name="p4938135915318"></a>紧凑型的显示格式，取值范围："long", "short"</p>
</td>
</tr>
<tr id="row149571783218"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p1095712718329"><a name="p1095712718329"></a><a name="p1095712718329"></a>notation</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p137691110193512"><a name="p137691110193512"></a><a name="p137691110193512"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p351792714359"><a name="p351792714359"></a><a name="p351792714359"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p12533152715355"><a name="p12533152715355"></a><a name="p12533152715355"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p1095817719324"><a name="p1095817719324"></a><a name="p1095817719324"></a>数字的格式化规格，取值范围："standard", "scientific", "engineering", "compact"</p>
</td>
</tr>
<tr id="row651913243210"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p1851916215327"><a name="p1851916215327"></a><a name="p1851916215327"></a>localeMatcher</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p278511013358"><a name="p278511013358"></a><a name="p278511013358"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p13551122714352"><a name="p13551122714352"></a><a name="p13551122714352"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p8567027123516"><a name="p8567027123516"></a><a name="p8567027123516"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p135202213324"><a name="p135202213324"></a><a name="p135202213324"></a>要使用的区域匹配算法，取值范围："lookup", "best fit"</p>
</td>
</tr>
<tr id="row6142417329"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p9141247329"><a name="p9141247329"></a><a name="p9141247329"></a>style</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p580151013516"><a name="p580151013516"></a><a name="p580151013516"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p8584427163520"><a name="p8584427163520"></a><a name="p8584427163520"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p12601427193516"><a name="p12601427193516"></a><a name="p12601427193516"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p0147411321"><a name="p0147411321"></a><a name="p0147411321"></a>数字的显示格式，取值范围："decimal", "currency", "percent", "unit"</p>
</td>
</tr>
<tr id="row10690651163120"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p206901951193115"><a name="p206901951193115"></a><a name="p206901951193115"></a>numberingSystem</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p18179104357"><a name="p18179104357"></a><a name="p18179104357"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p106179271351"><a name="p106179271351"></a><a name="p106179271351"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p96342278351"><a name="p96342278351"></a><a name="p96342278351"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p669010518311"><a name="p669010518311"></a><a name="p669010518311"></a>数字系统</p>
</td>
</tr>
<tr id="row1539618585317"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p93961258123112"><a name="p93961258123112"></a><a name="p93961258123112"></a>useGrouping</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p9396358133113"><a name="p9396358133113"></a><a name="p9396358133113"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p1650202763514"><a name="p1650202763514"></a><a name="p1650202763514"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p1667152753514"><a name="p1667152753514"></a><a name="p1667152753514"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p1639665815311"><a name="p1639665815311"></a><a name="p1639665815311"></a>是否分组显示</p>
</td>
</tr>
<tr id="row072885623114"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p972925613314"><a name="p972925613314"></a><a name="p972925613314"></a>miniumumIntegerDigits</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p1772915560312"><a name="p1772915560312"></a><a name="p1772915560312"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p16831027113518"><a name="p16831027113518"></a><a name="p16831027113518"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p370042710357"><a name="p370042710357"></a><a name="p370042710357"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p372995623120"><a name="p372995623120"></a><a name="p372995623120"></a>最少整数个数</p>
</td>
</tr>
<tr id="row16189155013112"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p1318945073110"><a name="p1318945073110"></a><a name="p1318945073110"></a>miniumumFractionDigits</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p18773192153515"><a name="p18773192153515"></a><a name="p18773192153515"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p871602718354"><a name="p871602718354"></a><a name="p871602718354"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p1273214274357"><a name="p1273214274357"></a><a name="p1273214274357"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p19189195053112"><a name="p19189195053112"></a><a name="p19189195053112"></a>最少小数个数</p>
</td>
</tr>
<tr id="row666184819318"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p1066194810314"><a name="p1066194810314"></a><a name="p1066194810314"></a>maxiumumFractionDigits</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p9790152114352"><a name="p9790152114352"></a><a name="p9790152114352"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p2748427163512"><a name="p2748427163512"></a><a name="p2748427163512"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p476412763517"><a name="p476412763517"></a><a name="p476412763517"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p1866154811315"><a name="p1866154811315"></a><a name="p1866154811315"></a>最多小数个数</p>
</td>
</tr>
<tr id="row18191543113111"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p7191134310318"><a name="p7191134310318"></a><a name="p7191134310318"></a>miniumumSignificantDigits</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p68061821193514"><a name="p68061821193514"></a><a name="p68061821193514"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p7780182718358"><a name="p7780182718358"></a><a name="p7780182718358"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p479622793511"><a name="p479622793511"></a><a name="p479622793511"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p81919438317"><a name="p81919438317"></a><a name="p81919438317"></a>最少有效位个数</p>
</td>
</tr>
<tr id="row1514134520316"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p5141045153119"><a name="p5141045153119"></a><a name="p5141045153119"></a>maxiumumSignificantDigits</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p16822182103515"><a name="p16822182103515"></a><a name="p16822182103515"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p1081342717358"><a name="p1081342717358"></a><a name="p1081342717358"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p382912713352"><a name="p382912713352"></a><a name="p382912713352"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p11418457317"><a name="p11418457317"></a><a name="p11418457317"></a>最多有效位个数</p>
</td>
</tr>
</tbody>
</table>

