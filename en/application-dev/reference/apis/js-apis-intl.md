# Internationalization \(intl\) <a name="EN-US_TOPIC_0000001200978209"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>-   The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>-   This module contains standard i18n APIs, which are defined in ECMA 402.


## Modules to Import<a name="s56d19203690d4782bfc74069abb6bd71"></a>

```
import Intl from '@ohos.intl';
```

## Required Permissions<a name="section11257113618419"></a>

None

## Locale<a name="section422715643011"></a>

### Attributes<a name="section1778221585513"></a>

<a name="table1378271515552"></a>
<table><thead align="left"><tr id="row1078291525514"><th class="cellrowborder" valign="top" width="15.870000000000001%" id="mcps1.1.6.1.1"><p id="p17821115155511"><a name="p17821115155511"></a><a name="p17821115155511"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="10.86%" id="mcps1.1.6.1.2"><p id="p47821215145515"><a name="p47821215145515"></a><a name="p47821215145515"></a>Parameter Type</p>
</th>
<th class="cellrowborder" valign="top" width="9.34%" id="mcps1.1.6.1.3"><p id="p878221545513"><a name="p878221545513"></a><a name="p878221545513"></a>Readable</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="p11782121518559"><a name="p11782121518559"></a><a name="p11782121518559"></a>Writable</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="p97821715125513"><a name="p97821715125513"></a><a name="p97821715125513"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row3782131535519"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p7782615185518"><a name="p7782615185518"></a><a name="p7782615185518"></a>language</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="p1532011315106"><a name="p1532011315106"></a><a name="p1532011315106"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="p57831415165515"><a name="p57831415165515"></a><a name="p57831415165515"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p17831515175518"><a name="p17831515175518"></a><a name="p17831515175518"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p12783115145518"><a name="p12783115145518"></a><a name="p12783115145518"></a>Language associated with the locale.</p>
</td>
</tr>
<tr id="row18783101512558"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p197832015125519"><a name="p197832015125519"></a><a name="p197832015125519"></a>script</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="p19814797107"><a name="p19814797107"></a><a name="p19814797107"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="p1178341516559"><a name="p1178341516559"></a><a name="p1178341516559"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p207831615115519"><a name="p207831615115519"></a><a name="p207831615115519"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p1878311155553"><a name="p1878311155553"></a><a name="p1878311155553"></a>Script type of the language.</p>
</td>
</tr>
<tr id="row11401739287"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p131413393816"><a name="p131413393816"></a><a name="p131413393816"></a>region</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="p414103920813"><a name="p414103920813"></a><a name="p414103920813"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="p1141183916819"><a name="p1141183916819"></a><a name="p1141183916819"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p16936114313107"><a name="p16936114313107"></a><a name="p16936114313107"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p16141183916818"><a name="p16141183916818"></a><a name="p16141183916818"></a>Region associated with the locale.</p>
</td>
</tr>
<tr id="row324144214819"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p5245421082"><a name="p5245421082"></a><a name="p5245421082"></a>baseName</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="p2024144219810"><a name="p2024144219810"></a><a name="p2024144219810"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="p42415422813"><a name="p42415422813"></a><a name="p42415422813"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p055911448108"><a name="p055911448108"></a><a name="p055911448108"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p4246421818"><a name="p4246421818"></a><a name="p4246421818"></a>Basic information about the locale.</p>
</td>
</tr>
<tr id="row2182164417817"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p1318214441889"><a name="p1318214441889"></a><a name="p1318214441889"></a>caseFirst</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="p1418211440811"><a name="p1418211440811"></a><a name="p1418211440811"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="p181821344888"><a name="p181821344888"></a><a name="p181821344888"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p119084591015"><a name="p119084591015"></a><a name="p119084591015"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p111822441087"><a name="p111822441087"></a><a name="p111822441087"></a>Whether case is taken into account for the locale's collation rules.</p>
</td>
</tr>
<tr id="row616319461180"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p1416310461486"><a name="p1416310461486"></a><a name="p1416310461486"></a>calendar</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="p1216320461982"><a name="p1216320461982"></a><a name="p1216320461982"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="p916319461588"><a name="p916319461588"></a><a name="p916319461588"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p667234511012"><a name="p667234511012"></a><a name="p667234511012"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p1916315466811"><a name="p1916315466811"></a><a name="p1916315466811"></a>Calendar for the locale.</p>
</td>
</tr>
<tr id="row97016482083"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p570124810815"><a name="p570124810815"></a><a name="p570124810815"></a>collation</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="p1270748588"><a name="p1270748588"></a><a name="p1270748588"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="p8701648186"><a name="p8701648186"></a><a name="p8701648186"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p1327834619106"><a name="p1327834619106"></a><a name="p1327834619106"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p117094811816"><a name="p117094811816"></a><a name="p117094811816"></a>Collation rules for the locale.</p>
</td>
</tr>
<tr id="row22661650989"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p826710501284"><a name="p826710501284"></a><a name="p826710501284"></a>hourCycle</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="p626745013817"><a name="p626745013817"></a><a name="p626745013817"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="p19267105018810"><a name="p19267105018810"></a><a name="p19267105018810"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p692464614109"><a name="p692464614109"></a><a name="p692464614109"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p19267155017816"><a name="p19267155017816"></a><a name="p19267155017816"></a>Time system for the locale.</p>
</td>
</tr>
<tr id="row738595216815"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p133851452181"><a name="p133851452181"></a><a name="p133851452181"></a>numberingSystem</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="p53851520819"><a name="p53851520819"></a><a name="p53851520819"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="p163851852980"><a name="p163851852980"></a><a name="p163851852980"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p9827647161017"><a name="p9827647161017"></a><a name="p9827647161017"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p63855529817"><a name="p63855529817"></a><a name="p63855529817"></a>Numbering system for the locale.</p>
</td>
</tr>
<tr id="row1471125410817"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p1571120541820"><a name="p1571120541820"></a><a name="p1571120541820"></a>numeric</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="p67111541886"><a name="p67111541886"></a><a name="p67111541886"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="p171115543810"><a name="p171115543810"></a><a name="p171115543810"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p1845174816106"><a name="p1845174816106"></a><a name="p1845174816106"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p87111354380"><a name="p87111354380"></a><a name="p87111354380"></a>Whether to apply special collation rules for numeric characters.</p>
</td>
</tr>
</tbody>
</table>

### constructor<a name="section32282618302"></a>

constructor\(locale: string, options?:options\)

Creates a  **Locale**  object.

-   Parameters

    <a name="table69661135912"></a>
    <table><thead align="left"><tr id="row149668318915"><th class="cellrowborder" valign="top" width="8.81%" id="mcps1.1.5.1.1"><p id="p7966738914"><a name="p7966738914"></a><a name="p7966738914"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="27.11%" id="mcps1.1.5.1.2"><p id="p296713699"><a name="p296713699"></a><a name="p296713699"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.710000000000001%" id="mcps1.1.5.1.3"><p id="p196718315911"><a name="p196718315911"></a><a name="p196718315911"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="57.37%" id="mcps1.1.5.1.4"><p id="p9967231197"><a name="p9967231197"></a><a name="p9967231197"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row99671533914"><td class="cellrowborder" valign="top" width="8.81%" headers="mcps1.1.5.1.1 "><p id="p13838351705"><a name="p13838351705"></a><a name="p13838351705"></a>locale</p>
    </td>
    <td class="cellrowborder" valign="top" width="27.11%" headers="mcps1.1.5.1.2 "><p id="p11967433914"><a name="p11967433914"></a><a name="p11967433914"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.710000000000001%" headers="mcps1.1.5.1.3 "><p id="p19671336916"><a name="p19671336916"></a><a name="p19671336916"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="57.37%" headers="mcps1.1.5.1.4 "><p id="p69671631796"><a name="p69671631796"></a><a name="p69671631796"></a>A string containing locale information, including the language, optional script, and locale.</p>
    </td>
    </tr>
    <tr id="row14743191495712"><td class="cellrowborder" valign="top" width="8.81%" headers="mcps1.1.5.1.1 "><p id="p11743111475719"><a name="p11743111475719"></a><a name="p11743111475719"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="27.11%" headers="mcps1.1.5.1.2 "><p id="p1274415142572"><a name="p1274415142572"></a><a name="p1274415142572"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.710000000000001%" headers="mcps1.1.5.1.3 "><p id="p6744181425719"><a name="p6744181425719"></a><a name="p6744181425719"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="57.37%" headers="mcps1.1.5.1.4 "><p id="p1974414145576"><a name="p1974414145576"></a><a name="p1974414145576"></a>Options for creating the <strong id="b182446451078"><a name="b182446451078"></a><a name="b182446451078"></a>Locale</strong> object.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var locale = new Intl.Locale("zh-CN");
    ```


### toString<a name="section6361163518520"></a>

toString\(\): string

Converts locale information to a string.

-   Return values

    <a name="table97866231562"></a>
    <table><thead align="left"><tr id="row378662317610"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p4786423668"><a name="p4786423668"></a><a name="p4786423668"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p578682318614"><a name="p578682318614"></a><a name="p578682318614"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row177861823963"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p1078617238618"><a name="p1078617238618"></a><a name="p1078617238618"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p578611231565"><a name="p578611231565"></a><a name="p578611231565"></a>String containing locale information.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var locale = new Intl.Locale("zh-CN");
    locale.toString();
    ```


### maximize<a name="section16459237152"></a>

maximize\(\): Locale

Maximizes information of the  **Locale**  object. If the script and locale information is missing, add the information.

-   Return values

    <a name="table94114239714"></a>
    <table><thead align="left"><tr id="row3411112311714"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p04119231171"><a name="p04119231171"></a><a name="p04119231171"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p164119231574"><a name="p164119231574"></a><a name="p164119231574"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row941112231572"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p341102317718"><a name="p341102317718"></a><a name="p341102317718"></a>Locale</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p1341122314711"><a name="p1341122314711"></a><a name="p1341122314711"></a><strong id="b20993192011115"><a name="b20993192011115"></a><a name="b20993192011115"></a>Locale</strong> object with the maximized information.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var locale = new Intl.Locale("zh-CN");
    locale.maximize();
    ```


### minimize<a name="section8112183915517"></a>

minimize\(\): Locale

Minimizes information of the  **Locale**  object. If the script and locale information is present, delete the information.

-   Return values

    <a name="table128315221814"></a>
    <table><thead align="left"><tr id="row6831152215817"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p3831192213819"><a name="p3831192213819"></a><a name="p3831192213819"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p1883214221088"><a name="p1883214221088"></a><a name="p1883214221088"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1183218227818"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p483210226819"><a name="p483210226819"></a><a name="p483210226819"></a>Locale</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p17832222781"><a name="p17832222781"></a><a name="p17832222781"></a><strong id="b1847413194717"><a name="b1847413194717"></a><a name="b1847413194717"></a>Locale</strong> object with the minimized information.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var locale = new Intl.Locale("zh-CN");
    locale.minimize();
    ```


## DateTimeFormat<a name="section164003264319"></a>

### constructor<a name="section740052693112"></a>

constructor\(locale: string, options?:DateTimeOptions\)

Creates a  **DateTimeOptions**  object for the specified locale.

-   Parameters

    <a name="table356962217321"></a>
    <table><thead align="left"><tr id="row185691227322"><th class="cellrowborder" valign="top" width="11.119698579847357%" id="mcps1.1.5.1.1"><p id="p18569132213213"><a name="p18569132213213"></a><a name="p18569132213213"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="22.905999420345864%" id="mcps1.1.5.1.2"><p id="p25691822183218"><a name="p25691822183218"></a><a name="p25691822183218"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.356873732006569%" id="mcps1.1.5.1.3"><p id="p14569192218320"><a name="p14569192218320"></a><a name="p14569192218320"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.61742826780022%" id="mcps1.1.5.1.4"><p id="p556972263210"><a name="p556972263210"></a><a name="p556972263210"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1756982217321"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="p20569132223214"><a name="p20569132223214"></a><a name="p20569132223214"></a>locale</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="p1856902273219"><a name="p1856902273219"></a><a name="p1856902273219"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="p15569142233219"><a name="p15569142233219"></a><a name="p15569142233219"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="p18569162212321"><a name="p18569162212321"></a><a name="p18569162212321"></a>A string containing locale information, including the language, optional script, and locale.</p>
    </td>
    </tr>
    <tr id="row056902210325"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="p145697223321"><a name="p145697223321"></a><a name="p145697223321"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="p956962219323"><a name="p956962219323"></a><a name="p956962219323"></a><a href="#section12882825611">DateTimeOptions</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="p195695222325"><a name="p195695222325"></a><a name="p195695222325"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="p8569922103214"><a name="p8569922103214"></a><a name="p8569922103214"></a>Options of the <strong id="b791972343913"><a name="b791972343913"></a><a name="b791972343913"></a>DateTimeFormat</strong> object.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var datefmt= new Intl.DateTimeFormat("zh-CN", { dateStyle: 'full', timeStyle: 'medium' });
    ```


### constructor<a name="section1400182613114"></a>

constructor\(locales: Array<string\>, options?:DateTimeOptions\)

Creates a  **DateTimeOptions**  object for the specified array of locales.

-   Parameters

    <a name="table1429997153311"></a>
    <table><thead align="left"><tr id="row229911773310"><th class="cellrowborder" valign="top" width="11.119698579847357%" id="mcps1.1.5.1.1"><p id="p15299171333"><a name="p15299171333"></a><a name="p15299171333"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="22.905999420345864%" id="mcps1.1.5.1.2"><p id="p1629912719331"><a name="p1629912719331"></a><a name="p1629912719331"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.356873732006569%" id="mcps1.1.5.1.3"><p id="p829916783311"><a name="p829916783311"></a><a name="p829916783311"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.61742826780022%" id="mcps1.1.5.1.4"><p id="p4299279331"><a name="p4299279331"></a><a name="p4299279331"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row52991074332"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="p1229911717332"><a name="p1229911717332"></a><a name="p1229911717332"></a>locales</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="p83001273339"><a name="p83001273339"></a><a name="p83001273339"></a>Array&lt;string&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="p113001717331"><a name="p113001717331"></a><a name="p113001717331"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="p153001778336"><a name="p153001778336"></a><a name="p153001778336"></a>An array of strings containing locale information.</p>
    </td>
    </tr>
    <tr id="row23000715337"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="p133007743315"><a name="p133007743315"></a><a name="p133007743315"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="p83001783320"><a name="p83001783320"></a><a name="p83001783320"></a><a href="#section12882825611">DateTimeOptions</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="p230013713339"><a name="p230013713339"></a><a name="p230013713339"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="p20300374333"><a name="p20300374333"></a><a name="p20300374333"></a>Options of the <strong id="b1251125411394"><a name="b1251125411394"></a><a name="b1251125411394"></a>DateTimeFormat</strong> object.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var datefmt= new Intl.DateTimeFormat(["ban", "zh"], { dateStyle: 'full', timeStyle: 'medium' });
    ```


### format<a name="section1840262614313"></a>

format\(date: Date\): string;

Formats the specified date and time.

-   Parameters

    <a name="table104041622203411"></a>
    <table><thead align="left"><tr id="row3405102263418"><th class="cellrowborder" valign="top" width="11.119698579847357%" id="mcps1.1.5.1.1"><p id="p164051422183414"><a name="p164051422183414"></a><a name="p164051422183414"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="22.905999420345864%" id="mcps1.1.5.1.2"><p id="p194051522123413"><a name="p194051522123413"></a><a name="p194051522123413"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.356873732006569%" id="mcps1.1.5.1.3"><p id="p1405922193417"><a name="p1405922193417"></a><a name="p1405922193417"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.61742826780022%" id="mcps1.1.5.1.4"><p id="p1140516225342"><a name="p1140516225342"></a><a name="p1140516225342"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row9405822163419"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="p104051322173411"><a name="p104051322173411"></a><a name="p104051322173411"></a>date</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="p740519224344"><a name="p740519224344"></a><a name="p740519224344"></a>Date</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="p194051122173417"><a name="p194051122173417"></a><a name="p194051122173417"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="p19405172212342"><a name="p19405172212342"></a><a name="p19405172212342"></a>Date and time to be formatted.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table9402122612316"></a>
    <table><thead align="left"><tr id="row104029264319"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p440212633116"><a name="p440212633116"></a><a name="p440212633116"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p144021226173112"><a name="p144021226173112"></a><a name="p144021226173112"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row3402112617311"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p340262673111"><a name="p340262673111"></a><a name="p340262673111"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p1040215260316"><a name="p1040215260316"></a><a name="p1040215260316"></a>A string containing the formatted date and time.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var date = new Date(2021, 11, 17, 3, 24, 0);
    var datefmt = new Intl.DateTimeFormat("en-GB");
    datefmt.format(date);
    ```


### formatRange<a name="section4402132614312"></a>

formatRange\(fromDate: Date, toDate: Date\): string;

Formats the specified date range.

-   Parameters

    <a name="table24021326153112"></a>
    <table><thead align="left"><tr id="row15403126153116"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p3403182693112"><a name="p3403182693112"></a><a name="p3403182693112"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p1640372611319"><a name="p1640372611319"></a><a name="p1640372611319"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p1540352615319"><a name="p1540352615319"></a><a name="p1540352615319"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p17403152623117"><a name="p17403152623117"></a><a name="p17403152623117"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row11403182693114"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p15403726183117"><a name="p15403726183117"></a><a name="p15403726183117"></a>startDate</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p124033261313"><a name="p124033261313"></a><a name="p124033261313"></a>Date</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p124039266311"><a name="p124039266311"></a><a name="p124039266311"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p840362633117"><a name="p840362633117"></a><a name="p840362633117"></a>Start date and time to be formatted.</p>
    </td>
    </tr>
    <tr id="row4629861544"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p66299618414"><a name="p66299618414"></a><a name="p66299618414"></a>endDate</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p136291962419"><a name="p136291962419"></a><a name="p136291962419"></a>Date</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p186296610412"><a name="p186296610412"></a><a name="p186296610412"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p116291262415"><a name="p116291262415"></a><a name="p116291262415"></a>End date and time to be formatted.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table114031226173116"></a>
    <table><thead align="left"><tr id="row204031126123119"><th class="cellrowborder" valign="top" width="20.05%" id="mcps1.1.3.1.1"><p id="p64036261318"><a name="p64036261318"></a><a name="p64036261318"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.95%" id="mcps1.1.3.1.2"><p id="p4403132613317"><a name="p4403132613317"></a><a name="p4403132613317"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row19403162616316"><td class="cellrowborder" valign="top" width="20.05%" headers="mcps1.1.3.1.1 "><p id="p15404132673120"><a name="p15404132673120"></a><a name="p15404132673120"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.95%" headers="mcps1.1.3.1.2 "><p id="p94042261310"><a name="p94042261310"></a><a name="p94042261310"></a>A string containing the formatted date and time range.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var startDate = new Date(2021, 11, 17, 3, 24, 0);
    var endDate = new Date(2021, 11, 18, 3, 24, 0);
    var datefmt = new Intl.DateTimeFormat("en-GB");
    datefmt.formatRange(startDate, endDate);
    ```


### resolvedOptions<a name="section1093513817123"></a>

resolvedOptions\(\): DateTimeOptions

Obtains the options of the  **DateTimeFormat**  object.

-   Return values

    <a name="table1393663841210"></a>
    <table><thead align="left"><tr id="row5936113816126"><th class="cellrowborder" valign="top" width="20.05%" id="mcps1.1.3.1.1"><p id="p1493614383126"><a name="p1493614383126"></a><a name="p1493614383126"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.95%" id="mcps1.1.3.1.2"><p id="p1293633819124"><a name="p1293633819124"></a><a name="p1293633819124"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row393643871210"><td class="cellrowborder" valign="top" width="20.05%" headers="mcps1.1.3.1.1 "><p id="p9936163816125"><a name="p9936163816125"></a><a name="p9936163816125"></a><a href="#section12882825611">DateTimeOptions</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="79.95%" headers="mcps1.1.3.1.2 "><p id="p13936143812129"><a name="p13936143812129"></a><a name="p13936143812129"></a>Options of the <strong id="b18434201619431"><a name="b18434201619431"></a><a name="b18434201619431"></a>DateTimeFormat</strong> object.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var datefmt = new Intl.DateTimeFormat("en-GB");
    datefmt.resolvedOptions();
    ```


## NumberFormat<a name="section10453336123119"></a>

### constructor<a name="section14453163693117"></a>

constructor\(locale: string, options?:NumberOptions\)

Creates a  **NumberFormat**  object for the specified locale.

Parameters

<a name="table830832401619"></a>
<table><thead align="left"><tr id="row23081824181616"><th class="cellrowborder" valign="top" width="11.119698579847357%" id="mcps1.1.5.1.1"><p id="p1930892416168"><a name="p1930892416168"></a><a name="p1930892416168"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="22.905999420345864%" id="mcps1.1.5.1.2"><p id="p14308112431619"><a name="p14308112431619"></a><a name="p14308112431619"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="6.356873732006569%" id="mcps1.1.5.1.3"><p id="p173081324151614"><a name="p173081324151614"></a><a name="p173081324151614"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="59.61742826780022%" id="mcps1.1.5.1.4"><p id="p123092024101615"><a name="p123092024101615"></a><a name="p123092024101615"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row14309192401619"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="p03096245167"><a name="p03096245167"></a><a name="p03096245167"></a>locale</p>
</td>
<td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="p73094243167"><a name="p73094243167"></a><a name="p73094243167"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="p5309192461611"><a name="p5309192461611"></a><a name="p5309192461611"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="p133091924181620"><a name="p133091924181620"></a><a name="p133091924181620"></a>A string containing locale information, including the language, optional script, and locale.</p>
</td>
</tr>
<tr id="row133091924171615"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="p53091824181619"><a name="p53091824181619"></a><a name="p53091824181619"></a>options</p>
</td>
<td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="p7309424171618"><a name="p7309424171618"></a><a name="p7309424171618"></a><a href="#section7200123494410">NumberOptions</a></p>
</td>
<td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="p3309202414168"><a name="p3309202414168"></a><a name="p3309202414168"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="p6309202413162"><a name="p6309202413162"></a><a name="p6309202413162"></a>Options of the <strong id="b1971631024419"><a name="b1971631024419"></a><a name="b1971631024419"></a>NumberFormat</strong> object.</p>
</td>
</tr>
</tbody>
</table>

-   Example

    ```
    var numfmt = new Intl.NumberFormat("en-GB", {style:'decimal', notation:"scientific"});
    ```


### constructor<a name="section54533363319"></a>

constructor\(locales: Array<string\>, options?:NumberOptions\)

Creates a  **NumberFormat**  object for the specified array of locales.

-   Parameters

    <a name="table1886184401618"></a>
    <table><thead align="left"><tr id="row68615446163"><th class="cellrowborder" valign="top" width="10.73326248671626%" id="mcps1.1.5.1.1"><p id="p88611446168"><a name="p88611446168"></a><a name="p88611446168"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="23.29243551347696%" id="mcps1.1.5.1.2"><p id="p12861644191616"><a name="p12861644191616"></a><a name="p12861644191616"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.356873732006569%" id="mcps1.1.5.1.3"><p id="p7861174419169"><a name="p7861174419169"></a><a name="p7861174419169"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.61742826780022%" id="mcps1.1.5.1.4"><p id="p14862744191618"><a name="p14862744191618"></a><a name="p14862744191618"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row20862544191620"><td class="cellrowborder" valign="top" width="10.73326248671626%" headers="mcps1.1.5.1.1 "><p id="p3862344191619"><a name="p3862344191619"></a><a name="p3862344191619"></a>locales</p>
    </td>
    <td class="cellrowborder" valign="top" width="23.29243551347696%" headers="mcps1.1.5.1.2 "><p id="p28621044131614"><a name="p28621044131614"></a><a name="p28621044131614"></a>Array&lt;string&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="p1086211440167"><a name="p1086211440167"></a><a name="p1086211440167"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="p386234417161"><a name="p386234417161"></a><a name="p386234417161"></a>An array of strings containing locale information.</p>
    </td>
    </tr>
    <tr id="row986254461614"><td class="cellrowborder" valign="top" width="10.73326248671626%" headers="mcps1.1.5.1.1 "><p id="p88621344181616"><a name="p88621344181616"></a><a name="p88621344181616"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="23.29243551347696%" headers="mcps1.1.5.1.2 "><p id="p486284417168"><a name="p486284417168"></a><a name="p486284417168"></a><a href="#section7200123494410">NumberOptions</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="p1986216442160"><a name="p1986216442160"></a><a name="p1986216442160"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="p4862104421615"><a name="p4862104421615"></a><a name="p4862104421615"></a>Options of the <strong id="b269374612509"><a name="b269374612509"></a><a name="b269374612509"></a>NumberFormat</strong> object.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var numfmt = new Intl.NumberFormat(["en-GB", "zh"], {style:'decimal', notation:"scientific"});
    ```


### format<a name="section94551936203114"></a>

format\(number: number\): string;

Formats a number.

-   Parameters

    <a name="table1459775620188"></a>
    <table><thead align="left"><tr id="row059755610184"><th class="cellrowborder" valign="top" width="11.119698579847357%" id="mcps1.1.5.1.1"><p id="p19597205631810"><a name="p19597205631810"></a><a name="p19597205631810"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="22.905999420345864%" id="mcps1.1.5.1.2"><p id="p18597856161815"><a name="p18597856161815"></a><a name="p18597856161815"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.356873732006569%" id="mcps1.1.5.1.3"><p id="p1859735614180"><a name="p1859735614180"></a><a name="p1859735614180"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.61742826780022%" id="mcps1.1.5.1.4"><p id="p145971656101812"><a name="p145971656101812"></a><a name="p145971656101812"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row11597195617186"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="p1959755631818"><a name="p1959755631818"></a><a name="p1959755631818"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="p12597155613186"><a name="p12597155613186"></a><a name="p12597155613186"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="p1559865612186"><a name="p1559865612186"></a><a name="p1559865612186"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="p95981556161816"><a name="p95981556161816"></a><a name="p95981556161816"></a>Number to be formatted.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table114558369317"></a>
    <table><thead align="left"><tr id="row12455133613312"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p545515361318"><a name="p545515361318"></a><a name="p545515361318"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p145512362311"><a name="p145512362311"></a><a name="p145512362311"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row3455193617316"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p745523619314"><a name="p745523619314"></a><a name="p745523619314"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p1745519363315"><a name="p1745519363315"></a><a name="p1745519363315"></a>Formatted number.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var numfmt = new Intl.NumberFormat(["en-GB", "zh"], {style:'decimal', notation:"scientific"});
    numfmt.format(1223);
    ```


### resolvedOptions<a name="section13178203919219"></a>

resolvedOptions\(\): NumberOptions

Obtains the options of the  **NumberFormat**  object.

-   Return values

    <a name="table917813992117"></a>
    <table><thead align="left"><tr id="row1717883992116"><th class="cellrowborder" valign="top" width="20.05%" id="mcps1.1.3.1.1"><p id="p91781539202115"><a name="p91781539202115"></a><a name="p91781539202115"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.95%" id="mcps1.1.3.1.2"><p id="p151783399216"><a name="p151783399216"></a><a name="p151783399216"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1217814392214"><td class="cellrowborder" valign="top" width="20.05%" headers="mcps1.1.3.1.1 "><p id="p317903912212"><a name="p317903912212"></a><a name="p317903912212"></a><a href="#section7200123494410">NumberOptions</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="79.95%" headers="mcps1.1.3.1.2 "><p id="p111794399212"><a name="p111794399212"></a><a name="p111794399212"></a>Options of the <strong id="b520810418585"><a name="b520810418585"></a><a name="b520810418585"></a>NumberFormat</strong> object.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var numfmt = new Intl.NumberFormat(["en-GB", "zh"], {style:'decimal', notation:"scientific"});
    numfmt.resolvedOptions();
    ```


## DateTimeOptions<a name="section12882825611"></a>

Provides the options for the  **DateTimeFormat**  object.

<a name="table1459620431636"></a>
<table><thead align="left"><tr id="row25971143435"><th class="cellrowborder" valign="top" width="18.91%" id="mcps1.1.6.1.1"><p id="p1559716434320"><a name="p1559716434320"></a><a name="p1559716434320"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="7.82%" id="mcps1.1.6.1.2"><p id="p3597743539"><a name="p3597743539"></a><a name="p3597743539"></a>Parameter Type</p>
</th>
<th class="cellrowborder" valign="top" width="9.33%" id="mcps1.1.6.1.3"><p id="p15971343131"><a name="p15971343131"></a><a name="p15971343131"></a>Readable</p>
</th>
<th class="cellrowborder" valign="top" width="11.52%" id="mcps1.1.6.1.4"><p id="p1459715436311"><a name="p1459715436311"></a><a name="p1459715436311"></a>Writable</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="p75975439316"><a name="p75975439316"></a><a name="p75975439316"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row95971943839"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.6.1.1 "><p id="p85976431431"><a name="p85976431431"></a><a name="p85976431431"></a>locale</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.2 "><p id="p1427924663417"><a name="p1427924663417"></a><a name="p1427924663417"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.1.6.1.3 "><p id="p1059711439317"><a name="p1059711439317"></a><a name="p1059711439317"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.6.1.4 "><p id="p659715430317"><a name="p659715430317"></a><a name="p659715430317"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p12781024121115"><a name="p12781024121115"></a><a name="p12781024121115"></a>Locale information.</p>
</td>
</tr>
<tr id="row185973435316"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.6.1.1 "><p id="p1559710432310"><a name="p1559710432310"></a><a name="p1559710432310"></a>dateStyle</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.2 "><p id="p16597144318312"><a name="p16597144318312"></a><a name="p16597144318312"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.1.6.1.3 "><p id="p12597194313317"><a name="p12597194313317"></a><a name="p12597194313317"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.6.1.4 "><p id="p892910583102"><a name="p892910583102"></a><a name="p892910583102"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p1916912791117"><a name="p1916912791117"></a><a name="p1916912791117"></a>Date display format. The value can be <strong id="b16274925323"><a name="b16274925323"></a><a name="b16274925323"></a>long</strong>, <strong id="b1719510291621"><a name="b1719510291621"></a><a name="b1719510291621"></a>short</strong>, <strong id="b158693332020"><a name="b158693332020"></a><a name="b158693332020"></a>medium</strong>, or <strong id="b21692407219"><a name="b21692407219"></a><a name="b21692407219"></a>full</strong>.</p>
</td>
</tr>
<tr id="row892411307269"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.6.1.1 "><p id="p139241230192614"><a name="p139241230192614"></a><a name="p139241230192614"></a>timeStyle</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.2 "><p id="p4924183062614"><a name="p4924183062614"></a><a name="p4924183062614"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.1.6.1.3 "><p id="p15401682357"><a name="p15401682357"></a><a name="p15401682357"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.6.1.4 "><p id="p1896275851018"><a name="p1896275851018"></a><a name="p1896275851018"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p2925830132619"><a name="p2925830132619"></a><a name="p2925830132619"></a>Time display format. The value can be <strong id="b134864481921"><a name="b134864481921"></a><a name="b134864481921"></a>long</strong>, <strong id="b34921481824"><a name="b34921481824"></a><a name="b34921481824"></a>short</strong>, <strong id="b74931548722"><a name="b74931548722"></a><a name="b74931548722"></a>medium</strong>, or <strong id="b164938487215"><a name="b164938487215"></a><a name="b164938487215"></a>full</strong>.</p>
</td>
</tr>
<tr id="row155315532719"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.6.1.1 "><p id="p185321542713"><a name="p185321542713"></a><a name="p185321542713"></a>hourCycle</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.2 "><p id="p1053218512273"><a name="p1053218512273"></a><a name="p1053218512273"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.1.6.1.3 "><p id="p18721483357"><a name="p18721483357"></a><a name="p18721483357"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.6.1.4 "><p id="p799415812103"><a name="p799415812103"></a><a name="p799415812103"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p4532135152710"><a name="p4532135152710"></a><a name="p4532135152710"></a>Hour cycle. The value can be <strong id="b74813597718"><a name="b74813597718"></a><a name="b74813597718"></a>h11</strong>, <strong id="b816924486"><a name="b816924486"></a><a name="b816924486"></a>h12</strong>, <strong id="b18410665814"><a name="b18410665814"></a><a name="b18410665814"></a>h23</strong>, or <strong id="b65635131782"><a name="b65635131782"></a><a name="b65635131782"></a>h24</strong>.</p>
</td>
</tr>
<tr id="row46421838277"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.6.1.1 "><p id="p136422030277"><a name="p136422030277"></a><a name="p136422030277"></a>timeZone</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.2 "><p id="p1364283182710"><a name="p1364283182710"></a><a name="p1364283182710"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.1.6.1.3 "><p id="p11029833510"><a name="p11029833510"></a><a name="p11029833510"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.6.1.4 "><p id="p18260598105"><a name="p18260598105"></a><a name="p18260598105"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p5642103122711"><a name="p5642103122711"></a><a name="p5642103122711"></a>Time zone represented by a valid IANA time zone ID.</p>
</td>
</tr>
<tr id="row589712142718"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.6.1.1 "><p id="p1689719132719"><a name="p1689719132719"></a><a name="p1689719132719"></a>numberingSystem</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.2 "><p id="p28971919276"><a name="p28971919276"></a><a name="p28971919276"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.1.6.1.3 "><p id="p9132118153512"><a name="p9132118153512"></a><a name="p9132118153512"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.6.1.4 "><p id="p95865961017"><a name="p95865961017"></a><a name="p95865961017"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p16897111192718"><a name="p16897111192718"></a><a name="p16897111192718"></a>Numbering system.</p>
</td>
</tr>
<tr id="row1190575820265"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.6.1.1 "><p id="p1590585832620"><a name="p1590585832620"></a><a name="p1590585832620"></a>hour12</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.2 "><p id="p119051584269"><a name="p119051584269"></a><a name="p119051584269"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.1.6.1.3 "><p id="p131611815350"><a name="p131611815350"></a><a name="p131611815350"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.6.1.4 "><p id="p1190559111013"><a name="p1190559111013"></a><a name="p1190559111013"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p13905558122617"><a name="p13905558122617"></a><a name="p13905558122617"></a>Whether to use the 12-hour clock.</p>
</td>
</tr>
<tr id="row62191578267"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.6.1.1 "><p id="p122191578263"><a name="p122191578263"></a><a name="p122191578263"></a>weekday</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.2 "><p id="p8219145713262"><a name="p8219145713262"></a><a name="p8219145713262"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.1.6.1.3 "><p id="p719114893513"><a name="p719114893513"></a><a name="p719114893513"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.6.1.4 "><p id="p712345916107"><a name="p712345916107"></a><a name="p712345916107"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p10220457132611"><a name="p10220457132611"></a><a name="p10220457132611"></a>Workday display format. The value can be <strong id="b1071219283159"><a name="b1071219283159"></a><a name="b1071219283159"></a>long</strong>, <strong id="b1758811328159"><a name="b1758811328159"></a><a name="b1758811328159"></a>short</strong>, or <strong id="b7530133721515"><a name="b7530133721515"></a><a name="b7530133721515"></a>narrow</strong>.</p>
</td>
</tr>
<tr id="row02045559268"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.6.1.1 "><p id="p14205155152614"><a name="p14205155152614"></a><a name="p14205155152614"></a>era</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.2 "><p id="p1820525515263"><a name="p1820525515263"></a><a name="p1820525515263"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.1.6.1.3 "><p id="p112201486359"><a name="p112201486359"></a><a name="p112201486359"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.6.1.4 "><p id="p3155195991017"><a name="p3155195991017"></a><a name="p3155195991017"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p10205255192611"><a name="p10205255192611"></a><a name="p10205255192611"></a>Era display format. The value can be <strong id="b122171010101610"><a name="b122171010101610"></a><a name="b122171010101610"></a>long</strong>, <strong id="b132276109163"><a name="b132276109163"></a><a name="b132276109163"></a>short</strong>, or <strong id="b623011021611"><a name="b623011021611"></a><a name="b623011021611"></a>narrow</strong>.</p>
</td>
</tr>
<tr id="row3849155211268"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.6.1.1 "><p id="p284995232620"><a name="p284995232620"></a><a name="p284995232620"></a>year</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.2 "><p id="p10849115213267"><a name="p10849115213267"></a><a name="p10849115213267"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.1.6.1.3 "><p id="p182511818353"><a name="p182511818353"></a><a name="p182511818353"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.6.1.4 "><p id="p20187185951015"><a name="p20187185951015"></a><a name="p20187185951015"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p15849135232613"><a name="p15849135232613"></a><a name="p15849135232613"></a>Year display format. The value can be <strong id="b1256714481718"><a name="b1256714481718"></a><a name="b1256714481718"></a>numeric</strong> or <strong id="b15678410171"><a name="b15678410171"></a><a name="b15678410171"></a>2-digit</strong>.</p>
</td>
</tr>
<tr id="row34024782614"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.6.1.1 "><p id="p164034752617"><a name="p164034752617"></a><a name="p164034752617"></a>month</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.2 "><p id="p1940947142619"><a name="p1940947142619"></a><a name="p1940947142619"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.1.6.1.3 "><p id="p828220873520"><a name="p828220873520"></a><a name="p828220873520"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.6.1.4 "><p id="p2022014593105"><a name="p2022014593105"></a><a name="p2022014593105"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p141304632716"><a name="p141304632716"></a><a name="p141304632716"></a>Month display format. The value can be <strong id="b516418310171"><a name="b516418310171"></a><a name="b516418310171"></a>numeric</strong>, <strong id="b1316443171714"><a name="b1316443171714"></a><a name="b1316443171714"></a>2-digit</strong>, <strong id="b9748114611718"><a name="b9748114611718"></a><a name="b9748114611718"></a>long</strong>, <strong id="b3506194913177"><a name="b3506194913177"></a><a name="b3506194913177"></a>short</strong>, or <strong id="b1779371210184"><a name="b1779371210184"></a><a name="b1779371210184"></a>narrow</strong>.</p>
</td>
</tr>
<tr id="row118165484263"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.6.1.1 "><p id="p158165489261"><a name="p158165489261"></a><a name="p158165489261"></a>day</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.2 "><p id="p18161948102618"><a name="p18161948102618"></a><a name="p18161948102618"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.1.6.1.3 "><p id="p73121981351"><a name="p73121981351"></a><a name="p73121981351"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.6.1.4 "><p id="p132521859111016"><a name="p132521859111016"></a><a name="p132521859111016"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p1181619481262"><a name="p1181619481262"></a><a name="p1181619481262"></a>Day display format. The value can be <strong id="b14384223111810"><a name="b14384223111810"></a><a name="b14384223111810"></a>numeric</strong> or <strong id="b1939792320180"><a name="b1939792320180"></a><a name="b1939792320180"></a>2-digit</strong>.</p>
</td>
</tr>
<tr id="row7924115012611"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.6.1.1 "><p id="p159241050202616"><a name="p159241050202616"></a><a name="p159241050202616"></a>hour</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.2 "><p id="p18924195042619"><a name="p18924195042619"></a><a name="p18924195042619"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.1.6.1.3 "><p id="p93411811352"><a name="p93411811352"></a><a name="p93411811352"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.6.1.4 "><p id="p8285165918102"><a name="p8285165918102"></a><a name="p8285165918102"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p11925185010261"><a name="p11925185010261"></a><a name="p11925185010261"></a>Hour display format. The value can be <strong id="b1572653814197"><a name="b1572653814197"></a><a name="b1572653814197"></a>numeric</strong> or <strong id="b1273212381192"><a name="b1273212381192"></a><a name="b1273212381192"></a>2-digit</strong>.</p>
</td>
</tr>
<tr id="row1315614310269"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.6.1.1 "><p id="p11571431266"><a name="p11571431266"></a><a name="p11571431266"></a>minute</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.2 "><p id="p20157443172618"><a name="p20157443172618"></a><a name="p20157443172618"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.1.6.1.3 "><p id="p18370168193519"><a name="p18370168193519"></a><a name="p18370168193519"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.6.1.4 "><p id="p83171059181017"><a name="p83171059181017"></a><a name="p83171059181017"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p1615714382614"><a name="p1615714382614"></a><a name="p1615714382614"></a>Minute display format. The value can be <strong id="b58941247121913"><a name="b58941247121913"></a><a name="b58941247121913"></a>numeric</strong> or <strong id="b10900184791918"><a name="b10900184791918"></a><a name="b10900184791918"></a>2-digit</strong>.</p>
</td>
</tr>
<tr id="row1126474532619"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.6.1.1 "><p id="p426414514261"><a name="p426414514261"></a><a name="p426414514261"></a>second</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.2 "><p id="p182641245182611"><a name="p182641245182611"></a><a name="p182641245182611"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.1.6.1.3 "><p id="p0400489357"><a name="p0400489357"></a><a name="p0400489357"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.6.1.4 "><p id="p8350125917104"><a name="p8350125917104"></a><a name="p8350125917104"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p521718134287"><a name="p521718134287"></a><a name="p521718134287"></a>Second display format. The value can be <strong id="b6936155112018"><a name="b6936155112018"></a><a name="b6936155112018"></a>numeric</strong> or <strong id="b694316515204"><a name="b694316515204"></a><a name="b694316515204"></a>2-digit</strong>.</p>
</td>
</tr>
<tr id="row132981741152616"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.6.1.1 "><p id="p1029894117268"><a name="p1029894117268"></a><a name="p1029894117268"></a>timeZoneName</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.2 "><p id="p9298174119264"><a name="p9298174119264"></a><a name="p9298174119264"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.1.6.1.3 "><p id="p942998103512"><a name="p942998103512"></a><a name="p942998103512"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.6.1.4 "><p id="p133831591107"><a name="p133831591107"></a><a name="p133831591107"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p2299104182619"><a name="p2299104182619"></a><a name="p2299104182619"></a>Localized representation of a time zone name.</p>
</td>
</tr>
<tr id="row2912163872615"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.6.1.1 "><p id="p19131838162614"><a name="p19131838162614"></a><a name="p19131838162614"></a>dayPeriod</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.2 "><p id="p991383832614"><a name="p991383832614"></a><a name="p991383832614"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.1.6.1.3 "><p id="p2458980359"><a name="p2458980359"></a><a name="p2458980359"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.6.1.4 "><p id="p541713599102"><a name="p541713599102"></a><a name="p541713599102"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p1591343818268"><a name="p1591343818268"></a><a name="p1591343818268"></a>Time period display format. The value can be <strong id="b4911359182012"><a name="b4911359182012"></a><a name="b4911359182012"></a>long</strong>, <strong id="b119177592209"><a name="b119177592209"></a><a name="b119177592209"></a>short</strong>, or <strong id="b891775952010"><a name="b891775952010"></a><a name="b891775952010"></a>narrow</strong>.</p>
</td>
</tr>
<tr id="row1971020367261"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.6.1.1 "><p id="p8710193620264"><a name="p8710193620264"></a><a name="p8710193620264"></a>localeMatcher</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.2 "><p id="p187102362268"><a name="p187102362268"></a><a name="p187102362268"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.1.6.1.3 "><p id="p17487882353"><a name="p17487882353"></a><a name="p17487882353"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.6.1.4 "><p id="p144995901011"><a name="p144995901011"></a><a name="p144995901011"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p1071013692610"><a name="p1071013692610"></a><a name="p1071013692610"></a>Locale matching algorithm. The value can be <strong id="b154121013258"><a name="b154121013258"></a><a name="b154121013258"></a>lookup</strong> or <strong id="b7282166162510"><a name="b7282166162510"></a><a name="b7282166162510"></a>best fit</strong>.</p>
</td>
</tr>
<tr id="row3436123312264"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.6.1.1 "><p id="p18437163318262"><a name="p18437163318262"></a><a name="p18437163318262"></a>formatMatcher</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.2 "><p id="p443773315263"><a name="p443773315263"></a><a name="p443773315263"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.1.6.1.3 "><p id="p185163893515"><a name="p185163893515"></a><a name="p185163893515"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.6.1.4 "><p id="p1448195961012"><a name="p1448195961012"></a><a name="p1448195961012"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p043711339264"><a name="p043711339264"></a><a name="p043711339264"></a>Format matching algorithm. The value can be <strong id="b12431171652519"><a name="b12431171652519"></a><a name="b12431171652519"></a>basic</strong> or <strong id="b114388161255"><a name="b114388161255"></a><a name="b114388161255"></a>best fit</strong>.</p>
</td>
</tr>
</tbody>
</table>

## NumberOptions<a name="section7200123494410"></a>

Provides the device capability.

<a name="table16201103444414"></a>
<table><thead align="left"><tr id="row620123444415"><th class="cellrowborder" valign="top" width="19.15%" id="mcps1.1.6.1.1"><p id="p1620163494418"><a name="p1620163494418"></a><a name="p1620163494418"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="10.8%" id="mcps1.1.6.1.2"><p id="p15201434124418"><a name="p15201434124418"></a><a name="p15201434124418"></a>Parameter Type</p>
</th>
<th class="cellrowborder" valign="top" width="6.12%" id="mcps1.1.6.1.3"><p id="p13201123484412"><a name="p13201123484412"></a><a name="p13201123484412"></a>Readable</p>
</th>
<th class="cellrowborder" valign="top" width="11.48%" id="mcps1.1.6.1.4"><p id="p1320123412448"><a name="p1320123412448"></a><a name="p1320123412448"></a>Writable</p>
</th>
<th class="cellrowborder" valign="top" width="52.449999999999996%" id="mcps1.1.6.1.5"><p id="p9201934134419"><a name="p9201934134419"></a><a name="p9201934134419"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row3201103494415"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p20826502499"><a name="p20826502499"></a><a name="p20826502499"></a>locale</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p120143413448"><a name="p120143413448"></a><a name="p120143413448"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p18201334114417"><a name="p18201334114417"></a><a name="p18201334114417"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p420113347441"><a name="p420113347441"></a><a name="p420113347441"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p8689133923516"><a name="p8689133923516"></a><a name="p8689133923516"></a>Locale information.</p>
</td>
</tr>
<tr id="row19202113413445"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p82028341442"><a name="p82028341442"></a><a name="p82028341442"></a>currency</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p20653010153513"><a name="p20653010153513"></a><a name="p20653010153513"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p142021134164413"><a name="p142021134164413"></a><a name="p142021134164413"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p163525312356"><a name="p163525312356"></a><a name="p163525312356"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p112021341446"><a name="p112021341446"></a><a name="p112021341446"></a>Currency for the specified locale.</p>
</td>
</tr>
<tr id="row181651537153112"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p6165137193115"><a name="p6165137193115"></a><a name="p6165137193115"></a>currencySign</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p26712105353"><a name="p26712105353"></a><a name="p26712105353"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p20320102716353"><a name="p20320102716353"></a><a name="p20320102716353"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p53383279356"><a name="p53383279356"></a><a name="p53383279356"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p416563763115"><a name="p416563763115"></a><a name="p416563763115"></a>Currency symbol.</p>
</td>
</tr>
<tr id="row02243913313"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p922173963114"><a name="p922173963114"></a><a name="p922173963114"></a>currencyDisplay</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p146881510173515"><a name="p146881510173515"></a><a name="p146881510173515"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p18355122710359"><a name="p18355122710359"></a><a name="p18355122710359"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p237211277353"><a name="p237211277353"></a><a name="p237211277353"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p15225393313"><a name="p15225393313"></a><a name="p15225393313"></a>Currency display mode. The value can be <strong id="b166165019292"><a name="b166165019292"></a><a name="b166165019292"></a>symbol</strong>, <strong id="b86561052142914"><a name="b86561052142914"></a><a name="b86561052142914"></a>narrowSymbol</strong>, <strong id="b35020562295"><a name="b35020562295"></a><a name="b35020562295"></a>code</strong>, or <strong id="b19851200143017"><a name="b19851200143017"></a><a name="b19851200143017"></a>name</strong>.</p>
</td>
</tr>
<tr id="row04912413319"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p349204110313"><a name="p349204110313"></a><a name="p349204110313"></a>unit</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p4705161018358"><a name="p4705161018358"></a><a name="p4705161018358"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p938862743518"><a name="p938862743518"></a><a name="p938862743518"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p440462743518"><a name="p440462743518"></a><a name="p440462743518"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p2499410317"><a name="p2499410317"></a><a name="p2499410317"></a>Currency unit.</p>
</td>
</tr>
<tr id="row17758199133220"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p13758129103211"><a name="p13758129103211"></a><a name="p13758129103211"></a>unitDisplay</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p1772013101356"><a name="p1772013101356"></a><a name="p1772013101356"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p1342018270359"><a name="p1342018270359"></a><a name="p1342018270359"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p184363276352"><a name="p184363276352"></a><a name="p184363276352"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p8758119193219"><a name="p8758119193219"></a><a name="p8758119193219"></a>Currency unit display format. The value can be <strong id="b951522863410"><a name="b951522863410"></a><a name="b951522863410"></a>long</strong>, <strong id="b352212803414"><a name="b352212803414"></a><a name="b352212803414"></a>short</strong>, or <strong id="b6522172812347"><a name="b6522172812347"></a><a name="b6522172812347"></a>medium</strong>.</p>
</td>
</tr>
<tr id="row1244996173217"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p845017623210"><a name="p845017623210"></a><a name="p845017623210"></a>signDisplay</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p1373617108355"><a name="p1373617108355"></a><a name="p1373617108355"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p545216279357"><a name="p545216279357"></a><a name="p545216279357"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p746817276358"><a name="p746817276358"></a><a name="p746817276358"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p154508613320"><a name="p154508613320"></a><a name="p154508613320"></a>Number sign display format. The value can be <strong id="b16809183410355"><a name="b16809183410355"></a><a name="b16809183410355"></a>auto</strong>, <strong id="b131362038173519"><a name="b131362038173519"></a><a name="b131362038173519"></a>never</strong>, <strong id="b7579144163516"><a name="b7579144163516"></a><a name="b7579144163516"></a>always</strong>, or <strong id="b35038457355"><a name="b35038457355"></a><a name="b35038457355"></a>expectZero</strong>.</p>
</td>
</tr>
<tr id="row119376594318"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p2093765973119"><a name="p2093765973119"></a><a name="p2093765973119"></a>compactDisplay</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p1375319107353"><a name="p1375319107353"></a><a name="p1375319107353"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p19485202719353"><a name="p19485202719353"></a><a name="p19485202719353"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p35017277357"><a name="p35017277357"></a><a name="p35017277357"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p4938135915318"><a name="p4938135915318"></a><a name="p4938135915318"></a>Compact display format. The value can be <strong id="b19718715366"><a name="b19718715366"></a><a name="b19718715366"></a>long</strong> or <strong id="b195951012143618"><a name="b195951012143618"></a><a name="b195951012143618"></a>short</strong>.</p>
</td>
</tr>
<tr id="row149571783218"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p1095712718329"><a name="p1095712718329"></a><a name="p1095712718329"></a>notation</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p137691110193512"><a name="p137691110193512"></a><a name="p137691110193512"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p351792714359"><a name="p351792714359"></a><a name="p351792714359"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p12533152715355"><a name="p12533152715355"></a><a name="p12533152715355"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p1095817719324"><a name="p1095817719324"></a><a name="p1095817719324"></a>Number notation. The value can be <strong id="b10991192874015"><a name="b10991192874015"></a><a name="b10991192874015"></a>standard</strong>, <strong id="b7680231144012"><a name="b7680231144012"></a><a name="b7680231144012"></a>scientific</strong>, <strong id="b154876351403"><a name="b154876351403"></a><a name="b154876351403"></a>engineering</strong>, or <strong id="b327916409404"><a name="b327916409404"></a><a name="b327916409404"></a>compact</strong>.</p>
</td>
</tr>
<tr id="row651913243210"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p1851916215327"><a name="p1851916215327"></a><a name="p1851916215327"></a>localeMatcher</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p278511013358"><a name="p278511013358"></a><a name="p278511013358"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p13551122714352"><a name="p13551122714352"></a><a name="p13551122714352"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p8567027123516"><a name="p8567027123516"></a><a name="p8567027123516"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p135202213324"><a name="p135202213324"></a><a name="p135202213324"></a>Locale matching algorithm. The value can be <strong id="b72701939194120"><a name="b72701939194120"></a><a name="b72701939194120"></a>lookup</strong> or <strong id="b82785391417"><a name="b82785391417"></a><a name="b82785391417"></a>best fit</strong>.</p>
</td>
</tr>
<tr id="row6142417329"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p9141247329"><a name="p9141247329"></a><a name="p9141247329"></a>style</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p580151013516"><a name="p580151013516"></a><a name="p580151013516"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p8584427163520"><a name="p8584427163520"></a><a name="p8584427163520"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p12601427193516"><a name="p12601427193516"></a><a name="p12601427193516"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p0147411321"><a name="p0147411321"></a><a name="p0147411321"></a>Number display format. The value can be <strong id="b1458516110422"><a name="b1458516110422"></a><a name="b1458516110422"></a>decimal</strong>, <strong id="b198973314214"><a name="b198973314214"></a><a name="b198973314214"></a>currency</strong>, <strong id="b154101067424"><a name="b154101067424"></a><a name="b154101067424"></a>percent</strong>, or <strong id="b116509918423"><a name="b116509918423"></a><a name="b116509918423"></a>unit</strong>.</p>
</td>
</tr>
<tr id="row10690651163120"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p206901951193115"><a name="p206901951193115"></a><a name="p206901951193115"></a>numberingSystem</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p18179104357"><a name="p18179104357"></a><a name="p18179104357"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p106179271351"><a name="p106179271351"></a><a name="p106179271351"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p96342278351"><a name="p96342278351"></a><a name="p96342278351"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p669010518311"><a name="p669010518311"></a><a name="p669010518311"></a>Numbering system.</p>
</td>
</tr>
<tr id="row1539618585317"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p93961258123112"><a name="p93961258123112"></a><a name="p93961258123112"></a>useGrouping</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p9396358133113"><a name="p9396358133113"></a><a name="p9396358133113"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p1650202763514"><a name="p1650202763514"></a><a name="p1650202763514"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p1667152753514"><a name="p1667152753514"></a><a name="p1667152753514"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p1639665815311"><a name="p1639665815311"></a><a name="p1639665815311"></a>Whether to enable grouping for display.</p>
</td>
</tr>
<tr id="row072885623114"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p972925613314"><a name="p972925613314"></a><a name="p972925613314"></a>miniumumIntegerDigits</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p1772915560312"><a name="p1772915560312"></a><a name="p1772915560312"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p16831027113518"><a name="p16831027113518"></a><a name="p16831027113518"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p370042710357"><a name="p370042710357"></a><a name="p370042710357"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p372995623120"><a name="p372995623120"></a><a name="p372995623120"></a>Minimum number of integer digits.</p>
</td>
</tr>
<tr id="row16189155013112"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p1318945073110"><a name="p1318945073110"></a><a name="p1318945073110"></a>miniumumFractionDigits</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p18773192153515"><a name="p18773192153515"></a><a name="p18773192153515"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p871602718354"><a name="p871602718354"></a><a name="p871602718354"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p1273214274357"><a name="p1273214274357"></a><a name="p1273214274357"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p19189195053112"><a name="p19189195053112"></a><a name="p19189195053112"></a>Minimum number of fraction digits.</p>
</td>
</tr>
<tr id="row666184819318"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p1066194810314"><a name="p1066194810314"></a><a name="p1066194810314"></a>maxiumumFractionDigits</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p9790152114352"><a name="p9790152114352"></a><a name="p9790152114352"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p2748427163512"><a name="p2748427163512"></a><a name="p2748427163512"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p476412763517"><a name="p476412763517"></a><a name="p476412763517"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p1866154811315"><a name="p1866154811315"></a><a name="p1866154811315"></a>Maximum number of fraction digits.</p>
</td>
</tr>
<tr id="row18191543113111"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p7191134310318"><a name="p7191134310318"></a><a name="p7191134310318"></a>miniumumSignificantDigits</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p68061821193514"><a name="p68061821193514"></a><a name="p68061821193514"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p7780182718358"><a name="p7780182718358"></a><a name="p7780182718358"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p479622793511"><a name="p479622793511"></a><a name="p479622793511"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p81919438317"><a name="p81919438317"></a><a name="p81919438317"></a>Minimum number of significant digits.</p>
</td>
</tr>
<tr id="row1514134520316"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p5141045153119"><a name="p5141045153119"></a><a name="p5141045153119"></a>maxiumumSignificantDigits</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p16822182103515"><a name="p16822182103515"></a><a name="p16822182103515"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p1081342717358"><a name="p1081342717358"></a><a name="p1081342717358"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p382912713352"><a name="p382912713352"></a><a name="p382912713352"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p11418457317"><a name="p11418457317"></a><a name="p11418457317"></a>Maximum number of significant digits.</p>
</td>
</tr>
</tbody>
</table>

