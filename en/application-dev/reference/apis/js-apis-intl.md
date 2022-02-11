#  Internationalization (intl)<a name="EN-US_TOPIC_0000001176823690"></a>

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

### Attributes<a name="section6235445191017"></a>

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
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p12783115145518"><a name="p12783115145518"></a><a name="p12783115145518"></a>Language associated with the locale, for example, <strong id="b6789165520289"><a name="b6789165520289"></a><a name="b6789165520289"></a>zh</strong>.</p>
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
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p1878311155553"><a name="p1878311155553"></a><a name="p1878311155553"></a>Script type of the language, for example, <strong id="b14643185102915"><a name="b14643185102915"></a><a name="b14643185102915"></a>Hans</strong>.</p>
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
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p16141183916818"><a name="p16141183916818"></a><a name="p16141183916818"></a>Region associated with the locale, for example, <strong id="b4307013162914"><a name="b4307013162914"></a><a name="b4307013162914"></a>CN</strong>.</p>
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
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p4246421818"><a name="p4246421818"></a><a name="p4246421818"></a>Basic key information about the locale, which consists of the language, script, and region, for example, <strong id="b13800919142819"><a name="b13800919142819"></a><a name="b13800919142819"></a>zh-Hans-CN</strong>.</p>
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
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p111822441087"><a name="p111822441087"></a><a name="p111822441087"></a>Whether case is taken into account for the locale's collation rules. The value can be <strong id="b1072474043720"><a name="b1072474043720"></a><a name="b1072474043720"></a>upper</strong>, <strong id="b590544419371"><a name="b590544419371"></a><a name="b590544419371"></a>lower</strong>, or <strong id="b51211246193710"><a name="b51211246193710"></a><a name="b51211246193710"></a>false</strong>.</p>
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
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p1916315466811"><a name="p1916315466811"></a><a name="p1916315466811"></a>Calendar for the locale. The value can be <strong id="b1435117148383"><a name="b1435117148383"></a><a name="b1435117148383"></a>buddhist</strong>, <strong id="b20559101743815"><a name="b20559101743815"></a><a name="b20559101743815"></a>chinese</strong>, <strong id="b2697922173810"><a name="b2697922173810"></a><a name="b2697922173810"></a>coptic</strong>, <strong id="b09517154394"><a name="b09517154394"></a><a name="b09517154394"></a>dangi</strong>, <strong id="b197531733919"><a name="b197531733919"></a><a name="b197531733919"></a>ethioaa</strong>, <strong id="b426418182397"><a name="b426418182397"></a><a name="b426418182397"></a>ethiopic</strong>, <strong id="b4451219143915"><a name="b4451219143915"></a><a name="b4451219143915"></a>gregory</strong>, <strong id="b18925112220399"><a name="b18925112220399"></a><a name="b18925112220399"></a>hebrew</strong>, <strong id="b17677122563910"><a name="b17677122563910"></a><a name="b17677122563910"></a>indian</strong>, <strong id="b10905152663910"><a name="b10905152663910"></a><a name="b10905152663910"></a>islamic</strong>, <strong id="b1290583113396"><a name="b1290583113396"></a><a name="b1290583113396"></a>islamic-umalqura</strong>, <strong id="b132143519397"><a name="b132143519397"></a><a name="b132143519397"></a>islamic-tbla</strong>, <strong id="b332533923910"><a name="b332533923910"></a><a name="b332533923910"></a>islamic-civil</strong>, <strong id="b7453174273915"><a name="b7453174273915"></a><a name="b7453174273915"></a>islamic-rgsa</strong>, <strong id="b111815446396"><a name="b111815446396"></a><a name="b111815446396"></a>iso8601</strong>, <strong id="b2040316458398"><a name="b2040316458398"></a><a name="b2040316458398"></a>japanese</strong>, <strong id="b18626194623920"><a name="b18626194623920"></a><a name="b18626194623920"></a>persian</strong>, <strong id="b6918205033912"><a name="b6918205033912"></a><a name="b6918205033912"></a>roc</strong>, or <strong id="b10416214400"><a name="b10416214400"></a><a name="b10416214400"></a>islamicc</strong>.</p>
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
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p117094811816"><a name="p117094811816"></a><a name="p117094811816"></a>Collation rules for the locale. The value can be any of the following: <strong id="b141438489413"><a name="b141438489413"></a><a name="b141438489413"></a>big5han</strong>, <strong id="b8428849194115"><a name="b8428849194115"></a><a name="b8428849194115"></a>compat</strong>, <strong id="b189492504419"><a name="b189492504419"></a><a name="b189492504419"></a>dict</strong>, <strong id="b1351145204116"><a name="b1351145204116"></a><a name="b1351145204116"></a>direct</strong>, <strong id="b2670453204120"><a name="b2670453204120"></a><a name="b2670453204120"></a>ducet</strong>, <strong id="b94632552410"><a name="b94632552410"></a><a name="b94632552410"></a>eor</strong>, <strong id="b14468145984112"><a name="b14468145984112"></a><a name="b14468145984112"></a>gb2312</strong>, <strong id="b83801058144120"><a name="b83801058144120"></a><a name="b83801058144120"></a>phonebk</strong>, <strong id="b16471119427"><a name="b16471119427"></a><a name="b16471119427"></a>phonetic</strong>, <strong id="b2317627421"><a name="b2317627421"></a><a name="b2317627421"></a>pinyin</strong>, <strong id="b8457734421"><a name="b8457734421"></a><a name="b8457734421"></a>reformed</strong>, <strong id="b117796417427"><a name="b117796417427"></a><a name="b117796417427"></a>searchjl</strong>, <strong id="b188476512427"><a name="b188476512427"></a><a name="b188476512427"></a>stroke</strong>, <strong id="b1054516714426"><a name="b1054516714426"></a><a name="b1054516714426"></a>trad</strong>, <strong id="b9689924217"><a name="b9689924217"></a><a name="b9689924217"></a>unihan</strong>, and <strong id="b9511191018422"><a name="b9511191018422"></a><a name="b9511191018422"></a>zhuyin</strong>.</p>
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
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p19267155017816"><a name="p19267155017816"></a><a name="p19267155017816"></a>Time system for the locale. The value can be <strong id="b5426114354519"><a name="b5426114354519"></a><a name="b5426114354519"></a>h11</strong>, <strong id="b1042634354518"><a name="b1042634354518"></a><a name="b1042634354518"></a>h12</strong>, <strong id="b144261943124515"><a name="b144261943124515"></a><a name="b144261943124515"></a>h23</strong>, or <strong id="b1442694354510"><a name="b1442694354510"></a><a name="b1442694354510"></a>h24</strong>.</p>
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
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p63855529817"><a name="p63855529817"></a><a name="p63855529817"></a>Numbering system for the locale. The value can be any of the following: <strong id="b17496243124313"><a name="b17496243124313"></a><a name="b17496243124313"></a>adlm</strong>, <strong id="b54211451436"><a name="b54211451436"></a><a name="b54211451436"></a>ahom</strong>, <strong id="b9186246134312"><a name="b9186246134312"></a><a name="b9186246134312"></a>arab</strong>, <strong id="b1945411476434"><a name="b1945411476434"></a><a name="b1945411476434"></a>arabext</strong>, <strong id="b38241448174312"><a name="b38241448174312"></a><a name="b38241448174312"></a>bali</strong>, <strong id="b41541750174316"><a name="b41541750174316"></a><a name="b41541750174316"></a>beng</strong>, <strong id="b1502105213432"><a name="b1502105213432"></a><a name="b1502105213432"></a>bhks</strong>, <strong id="b298325424310"><a name="b298325424310"></a><a name="b298325424310"></a>brah</strong>, <strong id="b95351956164310"><a name="b95351956164310"></a><a name="b95351956164310"></a>cakm</strong>, <strong id="b181752584438"><a name="b181752584438"></a><a name="b181752584438"></a>cham</strong>, <strong id="b3394703448"><a name="b3394703448"></a><a name="b3394703448"></a>deva</strong>, <strong id="b59441912441"><a name="b59441912441"></a><a name="b59441912441"></a>diak</strong>, <strong id="b42983384419"><a name="b42983384419"></a><a name="b42983384419"></a>fullwide</strong>, <strong id="b129375144418"><a name="b129375144418"></a><a name="b129375144418"></a>gong</strong>, <strong id="b636815644413"><a name="b636815644413"></a><a name="b636815644413"></a>gonm</strong>, <strong id="b18617157104414"><a name="b18617157104414"></a><a name="b18617157104414"></a>gujr</strong>, <strong id="b1255559174419"><a name="b1255559174419"></a><a name="b1255559174419"></a>guru</strong>, <strong id="b19727910144415"><a name="b19727910144415"></a><a name="b19727910144415"></a>hanidec</strong>, <strong id="b178511411124419"><a name="b178511411124419"></a><a name="b178511411124419"></a>hmng</strong>, <strong id="b6174414124413"><a name="b6174414124413"></a><a name="b6174414124413"></a>hmnp</strong>, <strong id="b7736141514412"><a name="b7736141514412"></a><a name="b7736141514412"></a>java</strong>, <strong id="b392101784418"><a name="b392101784418"></a><a name="b392101784418"></a>kali</strong>, <strong id="b74001118144416"><a name="b74001118144416"></a><a name="b74001118144416"></a>khmr</strong>, <strong id="b468001944420"><a name="b468001944420"></a><a name="b468001944420"></a>knda</strong>, <strong id="b139511420164416"><a name="b139511420164416"></a><a name="b139511420164416"></a>lana</strong>, <strong id="b464220229445"><a name="b464220229445"></a><a name="b464220229445"></a>lanatham</strong>, <strong id="b72835619451"><a name="b72835619451"></a><a name="b72835619451"></a>laoo</strong>, <strong id="b12408158124513"><a name="b12408158124513"></a><a name="b12408158124513"></a>latn</strong>, <strong id="b20157410114519"><a name="b20157410114519"></a><a name="b20157410114519"></a>lepc</strong>, <strong id="b127911811134516"><a name="b127911811134516"></a><a name="b127911811134516"></a>limb</strong>, <strong id="b652314131451"><a name="b652314131451"></a><a name="b652314131451"></a>mathbold</strong>, <strong id="b16795216164519"><a name="b16795216164519"></a><a name="b16795216164519"></a>mathdbl</strong>, <strong id="b1762515150457"><a name="b1762515150457"></a><a name="b1762515150457"></a>mathmono</strong>, <strong id="b18181418154517"><a name="b18181418154517"></a><a name="b18181418154517"></a>mathsanb</strong>, <strong id="b984962414449"><a name="b984962414449"></a><a name="b984962414449"></a>mathsans</strong>, <strong id="b58395114518"><a name="b58395114518"></a><a name="b58395114518"></a>mlym</strong>, <strong id="b892713104513"><a name="b892713104513"></a><a name="b892713104513"></a>modi</strong>, <strong id="b16707823459"><a name="b16707823459"></a><a name="b16707823459"></a>mong</strong>, <strong id="b3484101194520"><a name="b3484101194520"></a><a name="b3484101194520"></a>mroo</strong>, <strong id="b154461204452"><a name="b154461204452"></a><a name="b154461204452"></a>mtei</strong>, <strong id="b18172759154417"><a name="b18172759154417"></a><a name="b18172759154417"></a>mymr</strong>, <strong id="b82845814443"><a name="b82845814443"></a><a name="b82845814443"></a>mymrshan</strong>, <strong id="b164205718442"><a name="b164205718442"></a><a name="b164205718442"></a>mymrtlng</strong>, <strong id="b8663122534418"><a name="b8663122534418"></a><a name="b8663122534418"></a>newa</strong>, <strong id="b111391041144417"><a name="b111391041144417"></a><a name="b111391041144417"></a>nkoo</strong>, <strong id="b124843426444"><a name="b124843426444"></a><a name="b124843426444"></a>olck</strong>, <strong id="b77851143114411"><a name="b77851143114411"></a><a name="b77851143114411"></a>orya</strong>, <strong id="b12972144164415"><a name="b12972144164415"></a><a name="b12972144164415"></a>osma</strong>, <strong id="b146814468446"><a name="b146814468446"></a><a name="b146814468446"></a>rohg</strong>, <strong id="b161990488444"><a name="b161990488444"></a><a name="b161990488444"></a>saur</strong>, <strong id="b55887516448"><a name="b55887516448"></a><a name="b55887516448"></a>segment</strong>, <strong id="b146836503443"><a name="b146836503443"></a><a name="b146836503443"></a>shrd</strong>, <strong id="b15477849144416"><a name="b15477849144416"></a><a name="b15477849144416"></a>sind</strong>, <strong id="b3155115310448"><a name="b3155115310448"></a><a name="b3155115310448"></a>sinh</strong>, <strong id="b1643055416448"><a name="b1643055416448"></a><a name="b1643055416448"></a>sora</strong>, <strong id="b1282095512444"><a name="b1282095512444"></a><a name="b1282095512444"></a>sund</strong>, <strong id="b965592694415"><a name="b965592694415"></a><a name="b965592694415"></a>takr</strong>, <strong id="b33171228114416"><a name="b33171228114416"></a><a name="b33171228114416"></a>talu</strong>, <strong id="b58803064419"><a name="b58803064419"></a><a name="b58803064419"></a>tamldec</strong>, <strong id="b8752631134414"><a name="b8752631134414"></a><a name="b8752631134414"></a>telu</strong>, <strong id="b333123394417"><a name="b333123394417"></a><a name="b333123394417"></a>thai</strong>, <strong id="b20611334144414"><a name="b20611334144414"></a><a name="b20611334144414"></a>tibt</strong>, <strong id="b20948335184415"><a name="b20948335184415"></a><a name="b20948335184415"></a>tirh</strong>, <strong id="b18452193716447"><a name="b18452193716447"></a><a name="b18452193716447"></a>vaii</strong>, <strong id="b5681238174410"><a name="b5681238174410"></a><a name="b5681238174410"></a>wara</strong>, and <strong id="b995703944412"><a name="b995703944412"></a><a name="b995703944412"></a>wcho</strong>.</p>
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

### constructor<a name="section1128371911114"></a>

constructor\(locale: string, options?: options\)

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
    </tbody>
    </table>


-   Example

    ```
    var locale = new Intl.Locale("zh-CN");
    ```


### toString<a name="section67805581415"></a>

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


### maximize<a name="section7383202531417"></a>

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
    <tbody><tr id="row941112231572"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p341102317718"><a name="p341102317718"></a><a name="p341102317718"></a><a href="#section422715643011">Locale</a></p>
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


### minimize<a name="section1712717486146"></a>

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
    <tbody><tr id="row1183218227818"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p483210226819"><a name="p483210226819"></a><a name="p483210226819"></a><a href="#section422715643011">Locale</a></p>
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

### constructor<a name="section8176222111510"></a>

constructor\(locale: string, options?: DateTimeOptions\)

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
    <td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="p956962219323"><a name="p956962219323"></a><a name="p956962219323"></a><a href="#section1193171023919">DateTimeOptions</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="p195695222325"><a name="p195695222325"></a><a name="p195695222325"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="p8569922103214"><a name="p8569922103214"></a><a name="p8569922103214"></a>Options for creating a <strong id="b578411480289"><a name="b578411480289"></a><a name="b578411480289"></a>DateTimeFormat</strong> object.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var datefmt= new Intl.DateTimeFormat("zh-CN", { dateStyle: 'full', timeStyle: 'medium' });
    ```


### constructor<a name="section1974813464158"></a>

constructor\(locales: Array<string\>, options?: DateTimeOptions\)

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
    <td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="p83001783320"><a name="p83001783320"></a><a name="p83001783320"></a><a href="#section1193171023919">DateTimeOptions</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="p230013713339"><a name="p230013713339"></a><a name="p230013713339"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="p20300374333"><a name="p20300374333"></a><a name="p20300374333"></a>Options for creating a <strong id="b12484834152817"><a name="b12484834152817"></a><a name="b12484834152817"></a>DateTimeFormat</strong> object.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var datefmt= new Intl.DateTimeFormat(["ban", "zh"], { dateStyle: 'full', timeStyle: 'medium' });
    ```


### format<a name="section86991113167"></a>

format\(date: Date\): string

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


### formatRange<a name="section134812186167"></a>

formatRange\(fromDate: Date, toDate: Date\): string

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


### resolvedOptions<a name="section95181531161610"></a>

resolvedOptions\(\): DateTimeOptions

Obtains the formatting options for  **DateTimeFormat**  object.

-   Return values

    <a name="table1393663841210"></a>
    <table><thead align="left"><tr id="row5936113816126"><th class="cellrowborder" valign="top" width="20.05%" id="mcps1.1.3.1.1"><p id="p1493614383126"><a name="p1493614383126"></a><a name="p1493614383126"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.95%" id="mcps1.1.3.1.2"><p id="p1293633819124"><a name="p1293633819124"></a><a name="p1293633819124"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row393643871210"><td class="cellrowborder" valign="top" width="20.05%" headers="mcps1.1.3.1.1 "><p id="p9936163816125"><a name="p9936163816125"></a><a name="p9936163816125"></a><a href="#section1193171023919">DateTimeOptions</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="79.95%" headers="mcps1.1.3.1.2 "><p id="p13936143812129"><a name="p13936143812129"></a><a name="p13936143812129"></a>Formatting options for <strong id="b18434201619431"><a name="b18434201619431"></a><a name="b18434201619431"></a>DateTimeFormat</strong> objects.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var datefmt = new Intl.DateTimeFormat("en-GB");
    datefmt.resolvedOptions();
    ```


## DateTimeOptions<a name="section1193171023919"></a>

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
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p12781024121115"><a name="p12781024121115"></a><a name="p12781024121115"></a>Locale, for example, <strong id="b102881715194619"><a name="b102881715194619"></a><a name="b102881715194619"></a>zh-Hans-CN</strong>.</p>
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
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p4532135152710"><a name="p4532135152710"></a><a name="p4532135152710"></a>Time system for the locale. The value can be <strong id="b74813597718"><a name="b74813597718"></a><a name="b74813597718"></a>h11</strong>, <strong id="b816924486"><a name="b816924486"></a><a name="b816924486"></a>h12</strong>, <strong id="b18410665814"><a name="b18410665814"></a><a name="b18410665814"></a>h23</strong>, or <strong id="b65635131782"><a name="b65635131782"></a><a name="b65635131782"></a>h24</strong>.</p>
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
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p16897111192718"><a name="p16897111192718"></a><a name="p16897111192718"></a>Numbering system for the locale. The value can be any of the following: <strong id="b175687166469"><a name="b175687166469"></a><a name="b175687166469"></a>adlm</strong>, <strong id="b956821654620"><a name="b956821654620"></a><a name="b956821654620"></a>ahom</strong>, <strong id="b656911613465"><a name="b656911613465"></a><a name="b656911613465"></a>arab</strong>, <strong id="b19569161654616"><a name="b19569161654616"></a><a name="b19569161654616"></a>arabext</strong>, <strong id="b135708168467"><a name="b135708168467"></a><a name="b135708168467"></a>bali</strong>, <strong id="b20570101613464"><a name="b20570101613464"></a><a name="b20570101613464"></a>beng</strong>, <strong id="b2570121620462"><a name="b2570121620462"></a><a name="b2570121620462"></a>bhks</strong>, <strong id="b15711616124610"><a name="b15711616124610"></a><a name="b15711616124610"></a>brah</strong>, <strong id="b7571416194620"><a name="b7571416194620"></a><a name="b7571416194620"></a>cakm</strong>, <strong id="b257214165462"><a name="b257214165462"></a><a name="b257214165462"></a>cham</strong>, <strong id="b157313166467"><a name="b157313166467"></a><a name="b157313166467"></a>deva</strong>, <strong id="b5573121619465"><a name="b5573121619465"></a><a name="b5573121619465"></a>diak</strong>, <strong id="b18574191644619"><a name="b18574191644619"></a><a name="b18574191644619"></a>fullwide</strong>, <strong id="b257401614612"><a name="b257401614612"></a><a name="b257401614612"></a>gong</strong>, <strong id="b757521624618"><a name="b757521624618"></a><a name="b757521624618"></a>gonm</strong>, <strong id="b6575151617462"><a name="b6575151617462"></a><a name="b6575151617462"></a>gujr</strong>, <strong id="b155765168461"><a name="b155765168461"></a><a name="b155765168461"></a>guru</strong>, <strong id="b18576316194617"><a name="b18576316194617"></a><a name="b18576316194617"></a>hanidec</strong>, <strong id="b857711161463"><a name="b857711161463"></a><a name="b857711161463"></a>hmng</strong>, <strong id="b1157718162463"><a name="b1157718162463"></a><a name="b1157718162463"></a>hmnp</strong>, <strong id="b1957718169461"><a name="b1957718169461"></a><a name="b1957718169461"></a>java</strong>, <strong id="b9578416184611"><a name="b9578416184611"></a><a name="b9578416184611"></a>kali</strong>, <strong id="b11578171612462"><a name="b11578171612462"></a><a name="b11578171612462"></a>khmr</strong>, <strong id="b35788162468"><a name="b35788162468"></a><a name="b35788162468"></a>knda</strong>, <strong id="b1357931614469"><a name="b1357931614469"></a><a name="b1357931614469"></a>lana</strong>, <strong id="b12579181616468"><a name="b12579181616468"></a><a name="b12579181616468"></a>lanatham</strong>, <strong id="b15580516194612"><a name="b15580516194612"></a><a name="b15580516194612"></a>laoo</strong>, <strong id="b1058013163462"><a name="b1058013163462"></a><a name="b1058013163462"></a>latn</strong>, <strong id="b155802161464"><a name="b155802161464"></a><a name="b155802161464"></a>lepc</strong>, <strong id="b458121624620"><a name="b458121624620"></a><a name="b458121624620"></a>limb</strong>, <strong id="b758171613467"><a name="b758171613467"></a><a name="b758171613467"></a>mathbold</strong>, <strong id="b135817163466"><a name="b135817163466"></a><a name="b135817163466"></a>mathdbl</strong>, <strong id="b158251611463"><a name="b158251611463"></a><a name="b158251611463"></a>mathmono</strong>, <strong id="b14582191618461"><a name="b14582191618461"></a><a name="b14582191618461"></a>mathsanb</strong>, <strong id="b55834163464"><a name="b55834163464"></a><a name="b55834163464"></a>mathsans</strong>, <strong id="b85832169466"><a name="b85832169466"></a><a name="b85832169466"></a>mlym</strong>, <strong id="b185831016124614"><a name="b185831016124614"></a><a name="b185831016124614"></a>modi</strong>, <strong id="b858415166464"><a name="b858415166464"></a><a name="b858415166464"></a>mong</strong>, <strong id="b2058420161469"><a name="b2058420161469"></a><a name="b2058420161469"></a>mroo</strong>, <strong id="b1658531619463"><a name="b1658531619463"></a><a name="b1658531619463"></a>mtei</strong>, <strong id="b25851163464"><a name="b25851163464"></a><a name="b25851163464"></a>mymr</strong>, <strong id="b3585181644615"><a name="b3585181644615"></a><a name="b3585181644615"></a>mymrshan</strong>, <strong id="b15862163465"><a name="b15862163465"></a><a name="b15862163465"></a>mymrtlng</strong>, <strong id="b158621614610"><a name="b158621614610"></a><a name="b158621614610"></a>newa</strong>, <strong id="b16586116204611"><a name="b16586116204611"></a><a name="b16586116204611"></a>nkoo</strong>, <strong id="b1058791674610"><a name="b1058791674610"></a><a name="b1058791674610"></a>olck</strong>, <strong id="b55872166462"><a name="b55872166462"></a><a name="b55872166462"></a>orya</strong>, <strong id="b95885169461"><a name="b95885169461"></a><a name="b95885169461"></a>osma</strong>, <strong id="b10588131654614"><a name="b10588131654614"></a><a name="b10588131654614"></a>rohg</strong>, <strong id="b65889160466"><a name="b65889160466"></a><a name="b65889160466"></a>saur</strong>, <strong id="b16589141634616"><a name="b16589141634616"></a><a name="b16589141634616"></a>segment</strong>, <strong id="b12589116174614"><a name="b12589116174614"></a><a name="b12589116174614"></a>shrd</strong>, <strong id="b75901916174616"><a name="b75901916174616"></a><a name="b75901916174616"></a>sind</strong>, <strong id="b2590131674612"><a name="b2590131674612"></a><a name="b2590131674612"></a>sinh</strong>, <strong id="b459011165465"><a name="b459011165465"></a><a name="b459011165465"></a>sora</strong>, <strong id="b9591516144615"><a name="b9591516144615"></a><a name="b9591516144615"></a>sund</strong>, <strong id="b1059151604611"><a name="b1059151604611"></a><a name="b1059151604611"></a>takr</strong>, <strong id="b10592816184612"><a name="b10592816184612"></a><a name="b10592816184612"></a>talu</strong>, <strong id="b145921316144612"><a name="b145921316144612"></a><a name="b145921316144612"></a>tamldec</strong>, <strong id="b7592316134616"><a name="b7592316134616"></a><a name="b7592316134616"></a>telu</strong>, <strong id="b165932016114614"><a name="b165932016114614"></a><a name="b165932016114614"></a>thai</strong>, <strong id="b185931716134613"><a name="b185931716134613"></a><a name="b185931716134613"></a>tibt</strong>, <strong id="b959351614462"><a name="b959351614462"></a><a name="b959351614462"></a>tirh</strong>, <strong id="b13594016154615"><a name="b13594016154615"></a><a name="b13594016154615"></a>vaii</strong>, <strong id="b12594141619462"><a name="b12594141619462"></a><a name="b12594141619462"></a>wara</strong>, and <strong id="b1159518167462"><a name="b1159518167462"></a><a name="b1159518167462"></a>wcho</strong>.</p>
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

## NumberFormat<a name="section10453336123119"></a>

### constructor<a name="section14453163693117"></a>

constructor\(locale: string, options?: NumberOptions\)

Creates a  **NumberFormat**  object for the specified locale.

-   Parameters

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
    <td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="p7309424171618"><a name="p7309424171618"></a><a name="p7309424171618"></a><a href="#section1359213512417">NumberOptions</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="p3309202414168"><a name="p3309202414168"></a><a name="p3309202414168"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="p6309202413162"><a name="p6309202413162"></a><a name="p6309202413162"></a>Options for creating a <strong id="b1971631024419"><a name="b1971631024419"></a><a name="b1971631024419"></a>NumberFormat</strong> object.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var numfmt = new Intl.NumberFormat("en-GB", {style:'decimal', notation:"scientific"});
    ```


### constructor<a name="section54533363319"></a>

constructor\(locales: Array<string\>, options?: NumberOptions\)

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
    <td class="cellrowborder" valign="top" width="23.29243551347696%" headers="mcps1.1.5.1.2 "><p id="p486284417168"><a name="p486284417168"></a><a name="p486284417168"></a><a href="#section1359213512417">NumberOptions</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="p1986216442160"><a name="p1986216442160"></a><a name="p1986216442160"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="p4862104421615"><a name="p4862104421615"></a><a name="p4862104421615"></a>Options for creating a <strong id="b728515579"><a name="b728515579"></a><a name="b728515579"></a>NumberFormat</strong> object.</p>
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
    <tbody><tr id="row1217814392214"><td class="cellrowborder" valign="top" width="20.05%" headers="mcps1.1.3.1.1 "><p id="p317903912212"><a name="p317903912212"></a><a name="p317903912212"></a><a href="#section1359213512417">NumberOptions</a></p>
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


## NumberOptions<a name="section1359213512417"></a>

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
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p8689133923516"><a name="p8689133923516"></a><a name="p8689133923516"></a>Locale, for example, <strong id="b19118162894619"><a name="b19118162894619"></a><a name="b19118162894619"></a>zh-Hans-CN</strong>.</p>
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
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p112021341446"><a name="p112021341446"></a><a name="p112021341446"></a>Currency unit, for example, <strong id="b12457545486"><a name="b12457545486"></a><a name="b12457545486"></a>EUR</strong>, <strong id="b64587414813"><a name="b64587414813"></a><a name="b64587414813"></a>CNY</strong>, or <strong id="b54584494818"><a name="b54584494818"></a><a name="b54584494818"></a>USD</strong>.</p>
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
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p416563763115"><a name="p416563763115"></a><a name="p416563763115"></a>Currency unit symbol. The value can be <strong id="b164291039184719"><a name="b164291039184719"></a><a name="b164291039184719"></a>symbol</strong>, <strong id="b164441164714"><a name="b164441164714"></a><a name="b164441164714"></a>narrowSymbol</strong>, <strong id="b3388194264718"><a name="b3388194264718"></a><a name="b3388194264718"></a>code</strong>, or <strong id="b136441643144710"><a name="b136441643144710"></a><a name="b136441643144710"></a>name</strong>.</p>
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
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p2499410317"><a name="p2499410317"></a><a name="p2499410317"></a>Unit name, for example, <strong id="b184611418134816"><a name="b184611418134816"></a><a name="b184611418134816"></a>meter</strong>, <strong id="b155751719124813"><a name="b155751719124813"></a><a name="b155751719124813"></a>inch</strong>, or <strong id="b118611820184814"><a name="b118611820184814"></a><a name="b118611820184814"></a>hectare</strong>.</p>
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
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p8758119193219"><a name="p8758119193219"></a><a name="p8758119193219"></a>Unit display format. The value can be <strong id="b951522863410"><a name="b951522863410"></a><a name="b951522863410"></a>long</strong>, <strong id="b352212803414"><a name="b352212803414"></a><a name="b352212803414"></a>short</strong>, or <strong id="b6522172812347"><a name="b6522172812347"></a><a name="b6522172812347"></a>medium</strong>.</p>
</td>
</tr>
<tr id="row1767262114313"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p167311211833"><a name="p167311211833"></a><a name="p167311211833"></a>unitUsage</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p16739211316"><a name="p16739211316"></a><a name="p16739211316"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p124821631735"><a name="p124821631735"></a><a name="p124821631735"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p11482183119318"><a name="p11482183119318"></a><a name="p11482183119318"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p9673182115319"><a name="p9673182115319"></a><a name="p9673182115319"></a>Unit use case. The value can be any of the following: <strong id="b198241928114915"><a name="b198241928114915"></a><a name="b198241928114915"></a>default</strong>, <strong id="b9782163255015"><a name="b9782163255015"></a><a name="b9782163255015"></a>area-land-agricult</strong>, <strong id="b569422805016"><a name="b569422805016"></a><a name="b569422805016"></a>area-land-commercl</strong>, <strong id="b1716218239505"><a name="b1716218239505"></a><a name="b1716218239505"></a>area-land-residntl</strong>, <strong id="b7274525125011"><a name="b7274525125011"></a><a name="b7274525125011"></a>length-person</strong>, <strong id="b31216407506"><a name="b31216407506"></a><a name="b31216407506"></a>length-person-small</strong>, <strong id="b12400164245015"><a name="b12400164245015"></a><a name="b12400164245015"></a>length-rainfall</strong>, <strong id="b13888154455014"><a name="b13888154455014"></a><a name="b13888154455014"></a>length-road</strong>, <strong id="b104001548115017"><a name="b104001548115017"></a><a name="b104001548115017"></a>length-road-small</strong>, <strong id="b08888714507"><a name="b08888714507"></a><a name="b08888714507"></a>length-snowfall</strong>, <strong id="b19361451165013"><a name="b19361451165013"></a><a name="b19361451165013"></a>length-vehicle</strong>, <strong id="b149381648504"><a name="b149381648504"></a><a name="b149381648504"></a>length-visiblty</strong>, <strong id="b188073025016"><a name="b188073025016"></a><a name="b188073025016"></a>length-visiblty-small</strong>, <strong id="b16415115754914"><a name="b16415115754914"></a><a name="b16415115754914"></a>length-person-informal</strong>, <strong id="b12793195324910"><a name="b12793195324910"></a><a name="b12793195324910"></a>length-person-small-informal</strong>, <strong id="b2023424813498"><a name="b2023424813498"></a><a name="b2023424813498"></a>length-road-informal</strong>, <strong id="b1297273994918"><a name="b1297273994918"></a><a name="b1297273994918"></a>speed-road-travel</strong>, <strong id="b7416204214495"><a name="b7416204214495"></a><a name="b7416204214495"></a>speed-wind</strong>, <strong id="b48644624917"><a name="b48644624917"></a><a name="b48644624917"></a>temperature-person</strong>, <strong id="b83961637184916"><a name="b83961637184916"></a><a name="b83961637184916"></a>temperature-weather</strong>, and <strong id="b19148123215491"><a name="b19148123215491"></a><a name="b19148123215491"></a>volume-vehicle-fuel</strong>.</p>
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
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p669010518311"><a name="p669010518311"></a><a name="p669010518311"></a>Numbering system for the locale. The value can be any of the following: <strong id="b12826155595015"><a name="b12826155595015"></a><a name="b12826155595015"></a>adlm</strong>, <strong id="b4828055185013"><a name="b4828055185013"></a><a name="b4828055185013"></a>ahom</strong>, <strong id="b483065510503"><a name="b483065510503"></a><a name="b483065510503"></a>arab</strong>, <strong id="b38321055185013"><a name="b38321055185013"></a><a name="b38321055185013"></a>arabext</strong>, <strong id="b1583495565011"><a name="b1583495565011"></a><a name="b1583495565011"></a>bali</strong>, <strong id="b88351555509"><a name="b88351555509"></a><a name="b88351555509"></a>beng</strong>, <strong id="b18837155165015"><a name="b18837155165015"></a><a name="b18837155165015"></a>bhks</strong>, <strong id="b1983935514506"><a name="b1983935514506"></a><a name="b1983935514506"></a>brah</strong>, <strong id="b88401855175015"><a name="b88401855175015"></a><a name="b88401855175015"></a>cakm</strong>, <strong id="b684245510505"><a name="b684245510505"></a><a name="b684245510505"></a>cham</strong>, <strong id="b19844105512507"><a name="b19844105512507"></a><a name="b19844105512507"></a>deva</strong>, <strong id="b16846105595019"><a name="b16846105595019"></a><a name="b16846105595019"></a>diak</strong>, <strong id="b9848555145011"><a name="b9848555145011"></a><a name="b9848555145011"></a>fullwide</strong>, <strong id="b884925525019"><a name="b884925525019"></a><a name="b884925525019"></a>gong</strong>, <strong id="b19851555175010"><a name="b19851555175010"></a><a name="b19851555175010"></a>gonm</strong>, <strong id="b12853125555020"><a name="b12853125555020"></a><a name="b12853125555020"></a>gujr</strong>, <strong id="b11855455155013"><a name="b11855455155013"></a><a name="b11855455155013"></a>guru</strong>, <strong id="b8856255175019"><a name="b8856255175019"></a><a name="b8856255175019"></a>hanidec</strong>, <strong id="b9858955135011"><a name="b9858955135011"></a><a name="b9858955135011"></a>hmng</strong>, <strong id="b15860955195015"><a name="b15860955195015"></a><a name="b15860955195015"></a>hmnp</strong>, <strong id="b19862255155020"><a name="b19862255155020"></a><a name="b19862255155020"></a>java</strong>, <strong id="b1686310557509"><a name="b1686310557509"></a><a name="b1686310557509"></a>kali</strong>, <strong id="b586585525013"><a name="b586585525013"></a><a name="b586585525013"></a>khmr</strong>, <strong id="b15867455145013"><a name="b15867455145013"></a><a name="b15867455145013"></a>knda</strong>, <strong id="b98692555509"><a name="b98692555509"></a><a name="b98692555509"></a>lana</strong>, <strong id="b1487125595012"><a name="b1487125595012"></a><a name="b1487125595012"></a>lanatham</strong>, <strong id="b1087295518506"><a name="b1087295518506"></a><a name="b1087295518506"></a>laoo</strong>, <strong id="b78741155115010"><a name="b78741155115010"></a><a name="b78741155115010"></a>latn</strong>, <strong id="b208769556503"><a name="b208769556503"></a><a name="b208769556503"></a>lepc</strong>, <strong id="b787835520508"><a name="b787835520508"></a><a name="b787835520508"></a>limb</strong>, <strong id="b15879155135013"><a name="b15879155135013"></a><a name="b15879155135013"></a>mathbold</strong>, <strong id="b108818556503"><a name="b108818556503"></a><a name="b108818556503"></a>mathdbl</strong>, <strong id="b19883255135014"><a name="b19883255135014"></a><a name="b19883255135014"></a>mathmono</strong>, <strong id="b988545516507"><a name="b988545516507"></a><a name="b988545516507"></a>mathsanb</strong>, <strong id="b7886125512508"><a name="b7886125512508"></a><a name="b7886125512508"></a>mathsans</strong>, <strong id="b20888555175015"><a name="b20888555175015"></a><a name="b20888555175015"></a>mlym</strong>, <strong id="b289015585018"><a name="b289015585018"></a><a name="b289015585018"></a>modi</strong>, <strong id="b189295585012"><a name="b189295585012"></a><a name="b189295585012"></a>mong</strong>, <strong id="b689575545011"><a name="b689575545011"></a><a name="b689575545011"></a>mroo</strong>, <strong id="b48961255175019"><a name="b48961255175019"></a><a name="b48961255175019"></a>mtei</strong>, <strong id="b11898155518500"><a name="b11898155518500"></a><a name="b11898155518500"></a>mymr</strong>, <strong id="b1790075585017"><a name="b1790075585017"></a><a name="b1790075585017"></a>mymrshan</strong>, <strong id="b7902855155014"><a name="b7902855155014"></a><a name="b7902855155014"></a>mymrtlng</strong>, <strong id="b8903855145019"><a name="b8903855145019"></a><a name="b8903855145019"></a>newa</strong>, <strong id="b69051955165016"><a name="b69051955165016"></a><a name="b69051955165016"></a>nkoo</strong>, <strong id="b990765511507"><a name="b990765511507"></a><a name="b990765511507"></a>olck</strong>, <strong id="b1490875525015"><a name="b1490875525015"></a><a name="b1490875525015"></a>orya</strong>, <strong id="b491016550506"><a name="b491016550506"></a><a name="b491016550506"></a>osma</strong>, <strong id="b1991255516507"><a name="b1991255516507"></a><a name="b1991255516507"></a>rohg</strong>, <strong id="b11914105511506"><a name="b11914105511506"></a><a name="b11914105511506"></a>saur</strong>, <strong id="b39156559507"><a name="b39156559507"></a><a name="b39156559507"></a>segment</strong>, <strong id="b10917195515503"><a name="b10917195515503"></a><a name="b10917195515503"></a>shrd</strong>, <strong id="b891985555017"><a name="b891985555017"></a><a name="b891985555017"></a>sind</strong>, <strong id="b139201955185012"><a name="b139201955185012"></a><a name="b139201955185012"></a>sinh</strong>, <strong id="b5922755205011"><a name="b5922755205011"></a><a name="b5922755205011"></a>sora</strong>, <strong id="b2092435519506"><a name="b2092435519506"></a><a name="b2092435519506"></a>sund</strong>, <strong id="b139260552507"><a name="b139260552507"></a><a name="b139260552507"></a>takr</strong>, <strong id="b139281554503"><a name="b139281554503"></a><a name="b139281554503"></a>talu</strong>, <strong id="b13930255135018"><a name="b13930255135018"></a><a name="b13930255135018"></a>tamldec</strong>, <strong id="b139318556501"><a name="b139318556501"></a><a name="b139318556501"></a>telu</strong>, <strong id="b793365505014"><a name="b793365505014"></a><a name="b793365505014"></a>thai</strong>, <strong id="b2935655155012"><a name="b2935655155012"></a><a name="b2935655155012"></a>tibt</strong>, <strong id="b1937055165013"><a name="b1937055165013"></a><a name="b1937055165013"></a>tirh</strong>, <strong id="b1939175519504"><a name="b1939175519504"></a><a name="b1939175519504"></a>vaii</strong>, <strong id="b3941205515505"><a name="b3941205515505"></a><a name="b3941205515505"></a>wara</strong>, and <strong id="b1943155195018"><a name="b1943155195018"></a><a name="b1943155195018"></a>wcho</strong>.</p>
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
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p1639665815311"><a name="p1639665815311"></a><a name="p1639665815311"></a>Whether to use grouping for display.</p>
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
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p1816915914299"><a name="p1816915914299"></a><a name="p1816915914299"></a>Minimum number of digits allowed in the integer part of a number. The value ranges from <strong id="b101801936183911"><a name="b101801936183911"></a><a name="b101801936183911"></a>1</strong> to <strong id="b1071513717399"><a name="b1071513717399"></a><a name="b1071513717399"></a>21</strong>.</p>
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
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p1287821073012"><a name="p1287821073012"></a><a name="p1287821073012"></a>Minimum number of digits in the fraction part of a number. The value ranges from <strong id="b2088115413453"><a name="b2088115413453"></a><a name="b2088115413453"></a>0</strong> to <strong id="b1933025674516"><a name="b1933025674516"></a><a name="b1933025674516"></a>20</strong>.</p>
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
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p1723192113302"><a name="p1723192113302"></a><a name="p1723192113302"></a>Maximum number of digits in the fraction part of a number. The value ranges from <strong id="b133767377540"><a name="b133767377540"></a><a name="b133767377540"></a>1</strong> to <strong id="b17376103717545"><a name="b17376103717545"></a><a name="b17376103717545"></a>21</strong>.</p>
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
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p492643083012"><a name="p492643083012"></a><a name="p492643083012"></a>Minimum number of the least significant digits. The value ranges from <strong id="b1066413266184"><a name="b1066413266184"></a><a name="b1066413266184"></a>1</strong> to <strong id="b1674382721812"><a name="b1674382721812"></a><a name="b1674382721812"></a>21</strong>.</p>
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
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p9826164011305"><a name="p9826164011305"></a><a name="p9826164011305"></a>Maximum number of the least significant digits. The value ranges from <strong id="b17992744161819"><a name="b17992744161819"></a><a name="b17992744161819"></a>1</strong> to <strong id="b2992144451817"><a name="b2992144451817"></a><a name="b2992144451817"></a>21</strong>.</p>
</td>
</tr>
</tbody>
</table>

## Collator<sup>8+</sup><a name="section235715217348"></a>

### constructor<sup>8+</sup><a name="section18837131612590"></a>

constructor\(\)

Creates a  **Collator**  object.

-   Example

    ```
    var collator = new Intl.Collator();
    ```


### constructor<sup>8+</sup><a name="section7598254309"></a>

constructor\(locale: string | Array<string\>, options?: CollatorOptions\)

Creates a  **Collator**  object based on the specified locale and options.

Parameters

<a name="table1259875413019"></a>
<table><thead align="left"><tr id="row2599155413011"><th class="cellrowborder" valign="top" width="11.119698579847357%" id="mcps1.1.5.1.1"><p id="p125991854804"><a name="p125991854804"></a><a name="p125991854804"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="22.905999420345864%" id="mcps1.1.5.1.2"><p id="p1159910546011"><a name="p1159910546011"></a><a name="p1159910546011"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="6.356873732006569%" id="mcps1.1.5.1.3"><p id="p2059916545014"><a name="p2059916545014"></a><a name="p2059916545014"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="59.61742826780022%" id="mcps1.1.5.1.4"><p id="p3599155415015"><a name="p3599155415015"></a><a name="p3599155415015"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row85995547019"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="p75996541301"><a name="p75996541301"></a><a name="p75996541301"></a>locale</p>
</td>
<td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="p18599105410016"><a name="p18599105410016"></a><a name="p18599105410016"></a>string|Array&lt;string&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="p1459975411018"><a name="p1459975411018"></a><a name="p1459975411018"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="p12599175415019"><a name="p12599175415019"></a><a name="p12599175415019"></a>A string containing locale information, including the language, optional script, and locale.</p>
</td>
</tr>
<tr id="row1059911541207"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="p559911541807"><a name="p559911541807"></a><a name="p559911541807"></a>options</p>
</td>
<td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="p485617734320"><a name="p485617734320"></a><a name="p485617734320"></a><a href="#section108211016144217">CollatorOptions</a></p>
</td>
<td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="p65992541709"><a name="p65992541709"></a><a name="p65992541709"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="p115991454502"><a name="p115991454502"></a><a name="p115991454502"></a>Options for creating a <strong id="b9299182502014"><a name="b9299182502014"></a><a name="b9299182502014"></a>Collator</strong> object.</p>
</td>
</tr>
</tbody>
</table>

-   Example

    ```
    var collator = new Intl.Collator("zh-CN", {"localeMatcher": "lookup", "usage": "sort"});
    ```


### compare<sup>8+</sup><a name="section11357165253410"></a>

compare\(first: string, second: string\): number

Compares two strings based on the sorting policy of the  **Collator**.

-   Parameters

    <a name="table1735716522346"></a>
    <table><thead align="left"><tr id="row23571252113418"><th class="cellrowborder" valign="top" width="11.119698579847357%" id="mcps1.1.5.1.1"><p id="p10357125220349"><a name="p10357125220349"></a><a name="p10357125220349"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="22.905999420345864%" id="mcps1.1.5.1.2"><p id="p1735795219342"><a name="p1735795219342"></a><a name="p1735795219342"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.356873732006569%" id="mcps1.1.5.1.3"><p id="p6357952143412"><a name="p6357952143412"></a><a name="p6357952143412"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.61742826780022%" id="mcps1.1.5.1.4"><p id="p43571352153410"><a name="p43571352153410"></a><a name="p43571352153410"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1635795219345"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="p15357125253410"><a name="p15357125253410"></a><a name="p15357125253410"></a>first</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="p935715213419"><a name="p935715213419"></a><a name="p935715213419"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="p19357135233415"><a name="p19357135233415"></a><a name="p19357135233415"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="p153578524344"><a name="p153578524344"></a><a name="p153578524344"></a>First string to compare.</p>
    </td>
    </tr>
    <tr id="row535765210341"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="p1335714529340"><a name="p1335714529340"></a><a name="p1335714529340"></a>second</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="p11240226133812"><a name="p11240226133812"></a><a name="p11240226133812"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="p1835855273414"><a name="p1835855273414"></a><a name="p1835855273414"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="p835811525341"><a name="p835811525341"></a><a name="p835811525341"></a>Second string to compare.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table6691123533613"></a>
    <table><thead align="left"><tr id="row14691935163611"><th class="cellrowborder" valign="top" width="20.05%" id="mcps1.1.3.1.1"><p id="p16692153513369"><a name="p16692153513369"></a><a name="p16692153513369"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.95%" id="mcps1.1.3.1.2"><p id="p11692173515369"><a name="p11692173515369"></a><a name="p11692173515369"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row16928352364"><td class="cellrowborder" valign="top" width="20.05%" headers="mcps1.1.3.1.1 "><p id="p1080975012364"><a name="p1080975012364"></a><a name="p1080975012364"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.95%" headers="mcps1.1.3.1.2 "><p id="p16564185893810"><a name="p16564185893810"></a><a name="p16564185893810"></a>Comparison result. If the value is a negative number, the first string is before the second string. If the value of number is <strong id="b1849452404716"><a name="b1849452404716"></a><a name="b1849452404716"></a>0</strong>, the first string is equal to the second string. If the value of number is a positive number, the first string is after the second string.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var collator = new intl.Collator("zh-Hans");
    collator.compare("first", "second");
    ```


### resolvedOptions<sup>8+</sup><a name="section15243163410393"></a>

resolvedOptions\(\): CollatorOptions

Returns properties reflecting the locale and collation options of a  **Collator**  object.

-   Return values

    <a name="table162458345399"></a>
    <table><thead align="left"><tr id="row4245634123916"><th class="cellrowborder" valign="top" width="20.05%" id="mcps1.1.3.1.1"><p id="p1424553413393"><a name="p1424553413393"></a><a name="p1424553413393"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.95%" id="mcps1.1.3.1.2"><p id="p32451346398"><a name="p32451346398"></a><a name="p32451346398"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row724533419397"><td class="cellrowborder" valign="top" width="20.05%" headers="mcps1.1.3.1.1 "><p id="p24019226402"><a name="p24019226402"></a><a name="p24019226402"></a><a href="#section108211016144217">CollatorOptions</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="79.95%" headers="mcps1.1.3.1.2 "><p id="p13363832134013"><a name="p13363832134013"></a><a name="p13363832134013"></a>Properties of the <strong id="b4567130102118"><a name="b4567130102118"></a><a name="b4567130102118"></a>Collator</strong> object.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var collator = new intl.Collator("zh-Hans");
    var options = collator.resolvedOptions();
    ```


## CollatorOptions<sup>8+</sup><a name="section108211016144217"></a>

Represents the properties of a  **Collator**  object.

<a name="table172555417444"></a>
<table><thead align="left"><tr id="row7725654154416"><th class="cellrowborder" valign="top" width="19.15%" id="mcps1.1.6.1.1"><p id="p7726205484410"><a name="p7726205484410"></a><a name="p7726205484410"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="10.8%" id="mcps1.1.6.1.2"><p id="p19726354164418"><a name="p19726354164418"></a><a name="p19726354164418"></a>Parameter Type</p>
</th>
<th class="cellrowborder" valign="top" width="6.12%" id="mcps1.1.6.1.3"><p id="p6726454194410"><a name="p6726454194410"></a><a name="p6726454194410"></a>Readable</p>
</th>
<th class="cellrowborder" valign="top" width="11.48%" id="mcps1.1.6.1.4"><p id="p47266544447"><a name="p47266544447"></a><a name="p47266544447"></a>Writable</p>
</th>
<th class="cellrowborder" valign="top" width="52.449999999999996%" id="mcps1.1.6.1.5"><p id="p27261954174414"><a name="p27261954174414"></a><a name="p27261954174414"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row37261854114415"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p1172685417444"><a name="p1172685417444"></a><a name="p1172685417444"></a>localeMatcher</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p14726135464412"><a name="p14726135464412"></a><a name="p14726135464412"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p1572610548442"><a name="p1572610548442"></a><a name="p1572610548442"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p772635484415"><a name="p772635484415"></a><a name="p772635484415"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p17265540445"><a name="p17265540445"></a><a name="p17265540445"></a>Locale matching algorithm. The value can be <strong id="b8012135310"><a name="b8012135310"></a><a name="b8012135310"></a>lookup</strong> or <strong id="b1522311395310"><a name="b1522311395310"></a><a name="b1522311395310"></a>best fit</strong>.</p>
</td>
</tr>
<tr id="row072665474415"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p2726155417448"><a name="p2726155417448"></a><a name="p2726155417448"></a>usage</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p10726854174420"><a name="p10726854174420"></a><a name="p10726854174420"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p2072619548447"><a name="p2072619548447"></a><a name="p2072619548447"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p1572713544445"><a name="p1572713544445"></a><a name="p1572713544445"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p2727125414441"><a name="p2727125414441"></a><a name="p2727125414441"></a>Whether the comparison is for sorting or for searching. The value can be <strong id="b77011012115817"><a name="b77011012115817"></a><a name="b77011012115817"></a>sort</strong> or <strong id="b5865118135813"><a name="b5865118135813"></a><a name="b5865118135813"></a>search</strong>.</p>
</td>
</tr>
<tr id="row17727105494410"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p9727205415445"><a name="p9727205415445"></a><a name="p9727205415445"></a>sensitivity</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p18727145411443"><a name="p18727145411443"></a><a name="p18727145411443"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p87275542443"><a name="p87275542443"></a><a name="p87275542443"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p8727135414410"><a name="p8727135414410"></a><a name="p8727135414410"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p18727155414445"><a name="p18727155414445"></a><a name="p18727155414445"></a>Differences in the strings that lead to non-zero return values. The value can be <strong id="b3397820257"><a name="b3397820257"></a><a name="b3397820257"></a>base</strong>, <strong id="b3629201610510"><a name="b3629201610510"></a><a name="b3629201610510"></a>accent</strong>, <strong id="b16792189353"><a name="b16792189353"></a><a name="b16792189353"></a>case</strong>, or <strong id="b1413413810515"><a name="b1413413810515"></a><a name="b1413413810515"></a>variant</strong>.</p>
</td>
</tr>
<tr id="row5727185434416"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p472715544443"><a name="p472715544443"></a><a name="p472715544443"></a>ignorePunctuation</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p127272549446"><a name="p127272549446"></a><a name="p127272549446"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p9727165434418"><a name="p9727165434418"></a><a name="p9727165434418"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p7727185415440"><a name="p7727185415440"></a><a name="p7727185415440"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p9727754134412"><a name="p9727754134412"></a><a name="p9727754134412"></a>Whether punctuation is ignored. The value can be <strong id="b21098284611"><a name="b21098284611"></a><a name="b21098284611"></a>true</strong> or <strong id="b433311291767"><a name="b433311291767"></a><a name="b433311291767"></a>false</strong>.</p>
</td>
</tr>
<tr id="row10727454184411"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p67271754184420"><a name="p67271754184420"></a><a name="p67271754184420"></a>collation</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p47271954184417"><a name="p47271954184417"></a><a name="p47271954184417"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p1472855417446"><a name="p1472855417446"></a><a name="p1472855417446"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p19728454104418"><a name="p19728454104418"></a><a name="p19728454104418"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p0728254114411"><a name="p0728254114411"></a><a name="p0728254114411"></a>Sorting policy. The value can be any of the following: <strong id="b107216261374"><a name="b107216261374"></a><a name="b107216261374"></a>big5han</strong>, <strong id="b1853152516719"><a name="b1853152516719"></a><a name="b1853152516719"></a>compat</strong>, <strong id="b2886327076"><a name="b2886327076"></a><a name="b2886327076"></a>dict</strong>, <strong id="b1523162913713"><a name="b1523162913713"></a><a name="b1523162913713"></a>direct</strong>, <strong id="b940618222719"><a name="b940618222719"></a><a name="b940618222719"></a>ducet</strong>, <strong id="b1852022113712"><a name="b1852022113712"></a><a name="b1852022113712"></a>eor</strong>, <strong id="b1024415201718"><a name="b1024415201718"></a><a name="b1024415201718"></a>gb2312</strong>, <strong id="b292063015711"><a name="b292063015711"></a><a name="b292063015711"></a>phonebk</strong>, <strong id="b1035611323715"><a name="b1035611323715"></a><a name="b1035611323715"></a>phonetic</strong>, <strong id="b158911331279"><a name="b158911331279"></a><a name="b158911331279"></a>pinyin</strong>, <strong id="b69901034372"><a name="b69901034372"></a><a name="b69901034372"></a>reformed</strong>, <strong id="b19248336377"><a name="b19248336377"></a><a name="b19248336377"></a>searchjl</strong>, <strong id="b310583813720"><a name="b310583813720"></a><a name="b310583813720"></a>stroke</strong>, <strong id="b17644839276"><a name="b17644839276"></a><a name="b17644839276"></a>trad</strong>, <strong id="b20863640873"><a name="b20863640873"></a><a name="b20863640873"></a>unihan</strong>, and <strong id="b117413189718"><a name="b117413189718"></a><a name="b117413189718"></a>zhuyin</strong>.</p>
</td>
</tr>
<tr id="row1172814546444"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p57281054164413"><a name="p57281054164413"></a><a name="p57281054164413"></a>numeric</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p8728155404415"><a name="p8728155404415"></a><a name="p8728155404415"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p57283545442"><a name="p57283545442"></a><a name="p57283545442"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p1572818545448"><a name="p1572818545448"></a><a name="p1572818545448"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p4728185411441"><a name="p4728185411441"></a><a name="p4728185411441"></a>Whether numeric collation is used. The value can be <strong id="b20979351189"><a name="b20979351189"></a><a name="b20979351189"></a>true</strong> or <strong id="b5976351281"><a name="b5976351281"></a><a name="b5976351281"></a>false</strong>.</p>
</td>
</tr>
<tr id="row147288548449"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p1472855454413"><a name="p1472855454413"></a><a name="p1472855454413"></a>caseFirst</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p872825410441"><a name="p872825410441"></a><a name="p872825410441"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p5728454184412"><a name="p5728454184412"></a><a name="p5728454184412"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p19728654134412"><a name="p19728654134412"></a><a name="p19728654134412"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p15728165414442"><a name="p15728165414442"></a><a name="p15728165414442"></a>Whether upper case or lower case is sorted first. The value can be <strong id="b9136115715911"><a name="b9136115715911"></a><a name="b9136115715911"></a>upper</strong>, <strong id="b17959711100"><a name="b17959711100"></a><a name="b17959711100"></a>lower</strong>, or <strong id="b15857137201011"><a name="b15857137201011"></a><a name="b15857137201011"></a>false</strong>.</p>
</td>
</tr>
</tbody>
</table>

## PluralRules<sup>8+</sup><a name="section723424617417"></a>

### constructor<sup>8+</sup><a name="section962717442119"></a>

constructor\(\)

Create a  **PluralRules**  object.

-   Example

    ```
    var pluralRules = new Intl.PluralRules();
    ```


### constructor<sup>8+</sup><a name="section186273446118"></a>

constructor\(locale: string | Array<string\>, options?: PluralRulesOptions\)

Creates a  **PluralRules**  object based on the specified locale and options.

Parameters

<a name="table6627244111119"></a>
<table><thead align="left"><tr id="row562834412111"><th class="cellrowborder" valign="top" width="11.119698579847357%" id="mcps1.1.5.1.1"><p id="p1462854451114"><a name="p1462854451114"></a><a name="p1462854451114"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="22.905999420345864%" id="mcps1.1.5.1.2"><p id="p1762819446119"><a name="p1762819446119"></a><a name="p1762819446119"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="6.356873732006569%" id="mcps1.1.5.1.3"><p id="p15628044141119"><a name="p15628044141119"></a><a name="p15628044141119"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="59.61742826780022%" id="mcps1.1.5.1.4"><p id="p76286443111"><a name="p76286443111"></a><a name="p76286443111"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row7628164419115"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="p8628124414113"><a name="p8628124414113"></a><a name="p8628124414113"></a>locale</p>
</td>
<td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="p862864421112"><a name="p862864421112"></a><a name="p862864421112"></a>string|Array&lt;string&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="p2062864441119"><a name="p2062864441119"></a><a name="p2062864441119"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="p0628344161114"><a name="p0628344161114"></a><a name="p0628344161114"></a>A string containing locale information, including the language, optional script, and locale.</p>
</td>
</tr>
<tr id="row1628344191118"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="p7628114421115"><a name="p7628114421115"></a><a name="p7628114421115"></a>options</p>
</td>
<td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="p19629144491117"><a name="p19629144491117"></a><a name="p19629144491117"></a><a href="#section1841753254214">PluralRulesOptions</a></p>
</td>
<td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="p11629134471115"><a name="p11629134471115"></a><a name="p11629134471115"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="p2629134411115"><a name="p2629134411115"></a><a name="p2629134411115"></a>Options for creating a <strong id="b951941519119"><a name="b951941519119"></a><a name="b951941519119"></a>PluralRules</strong> object.</p>
</td>
</tr>
</tbody>
</table>

-   Example

    ```
    var pluralRules= new Intl.PluraRules("zh-CN", {"localeMatcher": "lookup", "type": "cardinal"});
    ```


### select<sup>8+</sup><a name="section15234174634111"></a>

select\(n: number\): string

Obtains a string that represents the singular-plural type of the specified number.

-   Parameters

    <a name="table72341046194119"></a>
    <table><thead align="left"><tr id="row18235204612418"><th class="cellrowborder" valign="top" width="11.119698579847357%" id="mcps1.1.5.1.1"><p id="p323564613414"><a name="p323564613414"></a><a name="p323564613414"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="22.905999420345864%" id="mcps1.1.5.1.2"><p id="p3235346104113"><a name="p3235346104113"></a><a name="p3235346104113"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.356873732006569%" id="mcps1.1.5.1.3"><p id="p9235146184111"><a name="p9235146184111"></a><a name="p9235146184111"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.61742826780022%" id="mcps1.1.5.1.4"><p id="p112351546164112"><a name="p112351546164112"></a><a name="p112351546164112"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row32351946114112"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="p1523524624111"><a name="p1523524624111"></a><a name="p1523524624111"></a>n</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="p132354467414"><a name="p132354467414"></a><a name="p132354467414"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="p8235174620414"><a name="p8235174620414"></a><a name="p8235174620414"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="p101692039174312"><a name="p101692039174312"></a><a name="p101692039174312"></a>Number for which the singular-plural type is to be obtained.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table7236246114115"></a>
    <table><thead align="left"><tr id="row023674613411"><th class="cellrowborder" valign="top" width="20.05%" id="mcps1.1.3.1.1"><p id="p19236154610413"><a name="p19236154610413"></a><a name="p19236154610413"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.95%" id="mcps1.1.3.1.2"><p id="p1823612467419"><a name="p1823612467419"></a><a name="p1823612467419"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row623654616412"><td class="cellrowborder" valign="top" width="20.05%" headers="mcps1.1.3.1.1 "><p id="p923654619418"><a name="p923654619418"></a><a name="p923654619418"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.95%" headers="mcps1.1.3.1.2 "><p id="p191471117444"><a name="p191471117444"></a><a name="p191471117444"></a>Singular-plural type. The options are as follows: <strong id="b1724317811219"><a name="b1724317811219"></a><a name="b1724317811219"></a>zero</strong>, <strong id="b11930511521"><a name="b11930511521"></a><a name="b11930511521"></a>one</strong>, <strong id="b1511013141520"><a name="b1511013141520"></a><a name="b1511013141520"></a>two</strong>, <strong id="b111925431425"><a name="b111925431425"></a><a name="b111925431425"></a>few</strong>, <strong id="b9636144416210"><a name="b9636144416210"></a><a name="b9636144416210"></a>many</strong>, and <strong id="b181312461219"><a name="b181312461219"></a><a name="b181312461219"></a>others</strong>.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var pluralRules = new intl.PluralRules("zh-Hans");
    pluralRules.select(1);
    ```


## PluralRulesOptions<sup>8+</sup><a name="section1841753254214"></a>

Represents the properties of a  **PluralRules**  object.

<a name="table581363516811"></a>
<table><thead align="left"><tr id="row581393517817"><th class="cellrowborder" valign="top" width="19.15%" id="mcps1.1.6.1.1"><p id="p881312351783"><a name="p881312351783"></a><a name="p881312351783"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="10.8%" id="mcps1.1.6.1.2"><p id="p138134351288"><a name="p138134351288"></a><a name="p138134351288"></a>Parameter Type</p>
</th>
<th class="cellrowborder" valign="top" width="6.12%" id="mcps1.1.6.1.3"><p id="p1481313351381"><a name="p1481313351381"></a><a name="p1481313351381"></a>Readable</p>
</th>
<th class="cellrowborder" valign="top" width="11.48%" id="mcps1.1.6.1.4"><p id="p28132351689"><a name="p28132351689"></a><a name="p28132351689"></a>Writable</p>
</th>
<th class="cellrowborder" valign="top" width="52.449999999999996%" id="mcps1.1.6.1.5"><p id="p7813635689"><a name="p7813635689"></a><a name="p7813635689"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row158131835687"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p1181443520810"><a name="p1181443520810"></a><a name="p1181443520810"></a>localeMatcher</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p1581416352086"><a name="p1581416352086"></a><a name="p1581416352086"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p9814133515816"><a name="p9814133515816"></a><a name="p9814133515816"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p12814435287"><a name="p12814435287"></a><a name="p12814435287"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p781453518814"><a name="p781453518814"></a><a name="p781453518814"></a>Locale matching algorithm. The value can be <strong id="b23681479211"><a name="b23681479211"></a><a name="b23681479211"></a>lookup</strong> or <strong id="b621814499210"><a name="b621814499210"></a><a name="b621814499210"></a>best fit</strong>.</p>
</td>
</tr>
<tr id="row381416351488"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p5814203520818"><a name="p5814203520818"></a><a name="p5814203520818"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p1981423516817"><a name="p1981423516817"></a><a name="p1981423516817"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p681414358815"><a name="p681414358815"></a><a name="p681414358815"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p208147356810"><a name="p208147356810"></a><a name="p208147356810"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p781416351785"><a name="p781416351785"></a><a name="p781416351785"></a>Sorting type. The value can be <strong id="b982732712225"><a name="b982732712225"></a><a name="b982732712225"></a>cardinal</strong> or <strong id="b31202035112217"><a name="b31202035112217"></a><a name="b31202035112217"></a>ordinal</strong>.</p>
</td>
</tr>
<tr id="row128144352083"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p181420359814"><a name="p181420359814"></a><a name="p181420359814"></a>minimumIntegerDigits</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p7814235483"><a name="p7814235483"></a><a name="p7814235483"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p1814173518813"><a name="p1814173518813"></a><a name="p1814173518813"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p18815103511810"><a name="p18815103511810"></a><a name="p18815103511810"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p188158351084"><a name="p188158351084"></a><a name="p188158351084"></a>Minimum number of digits allowed in the integer part of a number. The value ranges from <strong id="b113900459227"><a name="b113900459227"></a><a name="b113900459227"></a>1</strong> to <strong id="b839674520221"><a name="b839674520221"></a><a name="b839674520221"></a>21</strong>.</p>
</td>
</tr>
<tr id="row68158351181"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p148159351386"><a name="p148159351386"></a><a name="p148159351386"></a>minimumFractionDigits</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p181543512811"><a name="p181543512811"></a><a name="p181543512811"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p3815335288"><a name="p3815335288"></a><a name="p3815335288"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p58154351081"><a name="p58154351081"></a><a name="p58154351081"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p4815123517813"><a name="p4815123517813"></a><a name="p4815123517813"></a>Minimum number of digits in the fraction part of a number. The value ranges from <strong id="b17179105210224"><a name="b17179105210224"></a><a name="b17179105210224"></a>0</strong> to <strong id="b1018511524226"><a name="b1018511524226"></a><a name="b1018511524226"></a>20</strong>.</p>
</td>
</tr>
<tr id="row1181543517816"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p16815163519818"><a name="p16815163519818"></a><a name="p16815163519818"></a>maximumFractionDigits</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p178155357817"><a name="p178155357817"></a><a name="p178155357817"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p1481512351383"><a name="p1481512351383"></a><a name="p1481512351383"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p13815735787"><a name="p13815735787"></a><a name="p13815735787"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p1181583515811"><a name="p1181583515811"></a><a name="p1181583515811"></a>Maximum number of digits in the fraction part of a number. The value ranges from <strong id="b7831105412211"><a name="b7831105412211"></a><a name="b7831105412211"></a>1</strong> to <strong id="b1583185462220"><a name="b1583185462220"></a><a name="b1583185462220"></a>21</strong>.</p>
</td>
</tr>
<tr id="row581515351487"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p15815133518814"><a name="p15815133518814"></a><a name="p15815133518814"></a>minimumSignificantDigits</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p1081683511810"><a name="p1081683511810"></a><a name="p1081683511810"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p68160359817"><a name="p68160359817"></a><a name="p68160359817"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p5816153516817"><a name="p5816153516817"></a><a name="p5816153516817"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p14816113510816"><a name="p14816113510816"></a><a name="p14816113510816"></a>Minimum number of the least significant digits. The value ranges from <strong id="b158681056172216"><a name="b158681056172216"></a><a name="b158681056172216"></a>1</strong> to <strong id="b686917568221"><a name="b686917568221"></a><a name="b686917568221"></a>21</strong>.</p>
</td>
</tr>
<tr id="row381653513815"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p881643510817"><a name="p881643510817"></a><a name="p881643510817"></a>maximumSignificantDigits</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p1816735285"><a name="p1816735285"></a><a name="p1816735285"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p1981614351884"><a name="p1981614351884"></a><a name="p1981614351884"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p1681613351682"><a name="p1681613351682"></a><a name="p1681613351682"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p68161435287"><a name="p68161435287"></a><a name="p68161435287"></a>Maximum number of the least significant digits. The value ranges from <strong id="b11755917223"><a name="b11755917223"></a><a name="b11755917223"></a>1</strong> to <strong id="b177359192215"><a name="b177359192215"></a><a name="b177359192215"></a>21</strong>.</p>
</td>
</tr>
</tbody>
</table>

## RelativeTimeFormat<sup>8+</sup><a name="section12691145262"></a>

### constructor<sup>8+</sup><a name="section1492214108187"></a>

constructor\(\)

Creates a  **RelativeTimeFormat**  object.

-   Example

    ```
    var relativetimefmt = new Intl.RelativeTimeFormat();
    ```


### constructor<sup>8+</sup><a name="section119221810141812"></a>

constructor\(locale: string | Array<string\>, options?: RelativeTimeFormatInputOptions\)

Creates a  **RelativeTimeFormat**  object based on the specified locale and options.

Parameters

<a name="table3923710191817"></a>
<table><thead align="left"><tr id="row14923131031814"><th class="cellrowborder" valign="top" width="11.119698579847357%" id="mcps1.1.5.1.1"><p id="p16923131051816"><a name="p16923131051816"></a><a name="p16923131051816"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="22.905999420345864%" id="mcps1.1.5.1.2"><p id="p1923111014180"><a name="p1923111014180"></a><a name="p1923111014180"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="6.356873732006569%" id="mcps1.1.5.1.3"><p id="p292316108182"><a name="p292316108182"></a><a name="p292316108182"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="59.61742826780022%" id="mcps1.1.5.1.4"><p id="p19923171091815"><a name="p19923171091815"></a><a name="p19923171091815"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row199231610151813"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="p392381041811"><a name="p392381041811"></a><a name="p392381041811"></a>locale</p>
</td>
<td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="p1392318109189"><a name="p1392318109189"></a><a name="p1392318109189"></a>string|Array&lt;string&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="p2092381071819"><a name="p2092381071819"></a><a name="p2092381071819"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="p49249104184"><a name="p49249104184"></a><a name="p49249104184"></a>A string containing locale information, including the language, optional script, and locale.</p>
</td>
</tr>
<tr id="row192451013183"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="p49244106183"><a name="p49244106183"></a><a name="p49244106183"></a>options</p>
</td>
<td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="p1924121011813"><a name="p1924121011813"></a><a name="p1924121011813"></a><a href="#section13434174316429">RelativeTimeFormatInputOptions</a></p>
</td>
<td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="p79249106186"><a name="p79249106186"></a><a name="p79249106186"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="p10924121010188"><a name="p10924121010188"></a><a name="p10924121010188"></a>Options for creating a <strong id="b17306422182713"><a name="b17306422182713"></a><a name="b17306422182713"></a>RelativeTimeFormat</strong> object.</p>
</td>
</tr>
</tbody>
</table>

-   Example

    ```
    var relativeTimeFormat = new Intl.RelativeTimeFormat("zh-CN", {"localeMatcher": "lookup", "numeric": "always", "style": "long"});
    ```


### format<sup>8+</sup><a name="section772213281272"></a>

format\(value: numeric, unit: string\): string

Formats the value and unit based on the specified locale and formatting options.

-   Parameters

    <a name="table153401772300"></a>
    <table><thead align="left"><tr id="row20341175308"><th class="cellrowborder" valign="top" width="11.119698579847357%" id="mcps1.1.5.1.1"><p id="p173412710304"><a name="p173412710304"></a><a name="p173412710304"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="22.905999420345864%" id="mcps1.1.5.1.2"><p id="p7341167193019"><a name="p7341167193019"></a><a name="p7341167193019"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.356873732006569%" id="mcps1.1.5.1.3"><p id="p0341774305"><a name="p0341774305"></a><a name="p0341774305"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.61742826780022%" id="mcps1.1.5.1.4"><p id="p734113713307"><a name="p734113713307"></a><a name="p734113713307"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row133414743017"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="p153416733020"><a name="p153416733020"></a><a name="p153416733020"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="p33411377303"><a name="p33411377303"></a><a name="p33411377303"></a>numeric</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="p14341207143015"><a name="p14341207143015"></a><a name="p14341207143015"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="p193412714308"><a name="p193412714308"></a><a name="p193412714308"></a>Value to format.</p>
    </td>
    </tr>
    <tr id="row1059201311327"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="p13601613183217"><a name="p13601613183217"></a><a name="p13601613183217"></a>unit</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="p156031373214"><a name="p156031373214"></a><a name="p156031373214"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="p13601813183218"><a name="p13601813183218"></a><a name="p13601813183218"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="p060181310321"><a name="p060181310321"></a><a name="p060181310321"></a>Unit to format. The value can be <strong id="b1080143716299"><a name="b1080143716299"></a><a name="b1080143716299"></a>year</strong>, <strong id="b189345417291"><a name="b189345417291"></a><a name="b189345417291"></a>quarter</strong>, <strong id="b1032817449295"><a name="b1032817449295"></a><a name="b1032817449295"></a>month</strong>, <strong id="b101371946112910"><a name="b101371946112910"></a><a name="b101371946112910"></a>week</strong>, <strong id="b16295114872912"><a name="b16295114872912"></a><a name="b16295114872912"></a>day</strong>, <strong id="b15844134917293"><a name="b15844134917293"></a><a name="b15844134917293"></a>hour</strong>, <strong id="b724785120299"><a name="b724785120299"></a><a name="b724785120299"></a>minute</strong>, or <strong id="b1502652192918"><a name="b1502652192918"></a><a name="b1502652192918"></a>second</strong>.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table133411723011"></a>
    <table><thead align="left"><tr id="row73411573307"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p1534114710307"><a name="p1534114710307"></a><a name="p1534114710307"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p1934114716300"><a name="p1934114716300"></a><a name="p1934114716300"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row183411279305"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p1634147113014"><a name="p1634147113014"></a><a name="p1634147113014"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p173417753017"><a name="p173417753017"></a><a name="p173417753017"></a>Relative time after formatting.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var relativetimefmt = new Intl.RelativeTimeFormat("zh-CN");
    relativetimefmt.format(3, "quarter")
    ```


### formatToParts<sup>8+</sup><a name="section97312511713"></a>

formatToParts\(value: numeric, unit: string\): Array<Object\>

Returns an array of  **RelativeTimeFormat**  objects in parts for locale-aware formatting.

-   Parameters

    <a name="table1857281113389"></a>
    <table><thead align="left"><tr id="row12572311173813"><th class="cellrowborder" valign="top" width="11.119698579847357%" id="mcps1.1.5.1.1"><p id="p2572181183819"><a name="p2572181183819"></a><a name="p2572181183819"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="22.905999420345864%" id="mcps1.1.5.1.2"><p id="p14572711193816"><a name="p14572711193816"></a><a name="p14572711193816"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.356873732006569%" id="mcps1.1.5.1.3"><p id="p8572161116386"><a name="p8572161116386"></a><a name="p8572161116386"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.61742826780022%" id="mcps1.1.5.1.4"><p id="p1357310118382"><a name="p1357310118382"></a><a name="p1357310118382"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row175733110387"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="p357319117385"><a name="p357319117385"></a><a name="p357319117385"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="p15573311143810"><a name="p15573311143810"></a><a name="p15573311143810"></a>numeric</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="p757320114386"><a name="p757320114386"></a><a name="p757320114386"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="p15731711123810"><a name="p15731711123810"></a><a name="p15731711123810"></a>Value to format.</p>
    </td>
    </tr>
    <tr id="row195731111113820"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="p7573121118385"><a name="p7573121118385"></a><a name="p7573121118385"></a>unit</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="p105731711153811"><a name="p105731711153811"></a><a name="p105731711153811"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="p5573201113381"><a name="p5573201113381"></a><a name="p5573201113381"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="p7573121153814"><a name="p7573121153814"></a><a name="p7573121153814"></a>Unit to format. The value can be <strong id="b227510227115"><a name="b227510227115"></a><a name="b227510227115"></a>year</strong>, <strong id="b92808221315"><a name="b92808221315"></a><a name="b92808221315"></a>quarter</strong>, <strong id="b92811622219"><a name="b92811622219"></a><a name="b92811622219"></a>month</strong>, <strong id="b728119221013"><a name="b728119221013"></a><a name="b728119221013"></a>week</strong>, <strong id="b128119221419"><a name="b128119221419"></a><a name="b128119221419"></a>day</strong>, <strong id="b728112218116"><a name="b728112218116"></a><a name="b728112218116"></a>hour</strong>, <strong id="b228117221613"><a name="b228117221613"></a><a name="b228117221613"></a>minute</strong>, or <strong id="b728152217110"><a name="b728152217110"></a><a name="b728152217110"></a>second</strong>.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table1457420114389"></a>
    <table><thead align="left"><tr id="row257411123817"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p15741611113813"><a name="p15741611113813"></a><a name="p15741611113813"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p6574151143819"><a name="p6574151143819"></a><a name="p6574151143819"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row75749116385"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p157411117381"><a name="p157411117381"></a><a name="p157411117381"></a>Array&lt;Object&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p12734113617442"><a name="p12734113617442"></a><a name="p12734113617442"></a>An array of <strong id="b18873161045910"><a name="b18873161045910"></a><a name="b18873161045910"></a>RelativeTimeFormat</strong> objects in parts.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var relativetimefmt = new Intl.RelativeTimeFormat("en", {"numeric": "auto"});
    var parts = relativetimefmt.format(10, "seconds");
    ```


### resolvedOptions<sup>8+</sup><a name="section43038316814"></a>

resolvedOptions\(\): RelativeTimeFormatResolvedOptions

Obtains the formatting options for  **RelativeTimeFormat**  objects.

-   Return values

    <a name="table17671173914915"></a>
    <table><thead align="left"><tr id="row11671153914918"><th class="cellrowborder" valign="top" width="20.05%" id="mcps1.1.3.1.1"><p id="p5671183919490"><a name="p5671183919490"></a><a name="p5671183919490"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.95%" id="mcps1.1.3.1.2"><p id="p167211392497"><a name="p167211392497"></a><a name="p167211392497"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row156728399490"><td class="cellrowborder" valign="top" width="20.05%" headers="mcps1.1.3.1.1 "><p id="p827161075013"><a name="p827161075013"></a><a name="p827161075013"></a><a href="#section441474654220">RelativeTimeFormatResolvedOptions</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="79.95%" headers="mcps1.1.3.1.2 "><p id="p1967203910493"><a name="p1967203910493"></a><a name="p1967203910493"></a>Formatting options for <strong id="b1410313141307"><a name="b1410313141307"></a><a name="b1410313141307"></a>RelativeTimeFormat</strong> objects.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var relativetimefmt= new Intl.RelativeTimeFormat("en-GB");
    relativetimefmt.resolvedOptions();
    ```


## RelativeTimeFormatInputOptions<sup>8+</sup><a name="section13434174316429"></a>

Represents the properties of a  **RelativeTimeFormat**  object.

<a name="table06645448207"></a>
<table><thead align="left"><tr id="row86642446206"><th class="cellrowborder" valign="top" width="19.15%" id="mcps1.1.6.1.1"><p id="p966404417205"><a name="p966404417205"></a><a name="p966404417205"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="10.8%" id="mcps1.1.6.1.2"><p id="p8665644122010"><a name="p8665644122010"></a><a name="p8665644122010"></a>Parameter Type</p>
</th>
<th class="cellrowborder" valign="top" width="6.12%" id="mcps1.1.6.1.3"><p id="p1866510447209"><a name="p1866510447209"></a><a name="p1866510447209"></a>Readable</p>
</th>
<th class="cellrowborder" valign="top" width="11.48%" id="mcps1.1.6.1.4"><p id="p966544413201"><a name="p966544413201"></a><a name="p966544413201"></a>Writable</p>
</th>
<th class="cellrowborder" valign="top" width="52.449999999999996%" id="mcps1.1.6.1.5"><p id="p126655442201"><a name="p126655442201"></a><a name="p126655442201"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1466564413206"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p136653446205"><a name="p136653446205"></a><a name="p136653446205"></a>localeMatcher</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p16665154472016"><a name="p16665154472016"></a><a name="p16665154472016"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p8665154492011"><a name="p8665154492011"></a><a name="p8665154492011"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p8665544142016"><a name="p8665544142016"></a><a name="p8665544142016"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p1666594462010"><a name="p1666594462010"></a><a name="p1666594462010"></a>Locale matching algorithm. The value can be <strong id="b767412210320"><a name="b767412210320"></a><a name="b767412210320"></a>lookup</strong> or <strong id="b16680722932"><a name="b16680722932"></a><a name="b16680722932"></a>best fit</strong>.</p>
</td>
</tr>
<tr id="row7666844182010"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p1266617445201"><a name="p1266617445201"></a><a name="p1266617445201"></a>numeric</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p106661044102019"><a name="p106661044102019"></a><a name="p106661044102019"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p166661444142017"><a name="p166661444142017"></a><a name="p166661444142017"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p2066694442012"><a name="p2066694442012"></a><a name="p2066694442012"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p86661344162020"><a name="p86661344162020"></a><a name="p86661344162020"></a>Format of the output message. The value can be <strong id="b0481258238"><a name="b0481258238"></a><a name="b0481258238"></a>always</strong> or <strong id="b15389132745"><a name="b15389132745"></a><a name="b15389132745"></a>auto</strong>.</p>
</td>
</tr>
<tr id="row866617448204"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p20690185818217"><a name="p20690185818217"></a><a name="p20690185818217"></a>style</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p1266644412204"><a name="p1266644412204"></a><a name="p1266644412204"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p11666194419207"><a name="p11666194419207"></a><a name="p11666194419207"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p4667444132016"><a name="p4667444132016"></a><a name="p4667444132016"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p966794419201"><a name="p966794419201"></a><a name="p966794419201"></a>Length of the internationalized message. The value can be <strong id="b1373134714816"><a name="b1373134714816"></a><a name="b1373134714816"></a>long</strong>, <strong id="b11972481385"><a name="b11972481385"></a><a name="b11972481385"></a>short</strong>, or <strong id="b1351664912810"><a name="b1351664912810"></a><a name="b1351664912810"></a>narrow</strong>.</p>
</td>
</tr>
</tbody>
</table>

## RelativeTimeFormatResolvedOptions<sup>8+</sup><a name="section441474654220"></a>

Represents the properties of a  **RelativeTimeFormat**  object.

<a name="table1697188434"></a>
<table><thead align="left"><tr id="row1498168174315"><th class="cellrowborder" valign="top" width="19.15%" id="mcps1.1.6.1.1"><p id="p1298288433"><a name="p1298288433"></a><a name="p1298288433"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="10.8%" id="mcps1.1.6.1.2"><p id="p15986874313"><a name="p15986874313"></a><a name="p15986874313"></a>Parameter Type</p>
</th>
<th class="cellrowborder" valign="top" width="6.12%" id="mcps1.1.6.1.3"><p id="p29868174317"><a name="p29868174317"></a><a name="p29868174317"></a>Readable</p>
</th>
<th class="cellrowborder" valign="top" width="11.48%" id="mcps1.1.6.1.4"><p id="p89811884311"><a name="p89811884311"></a><a name="p89811884311"></a>Writable</p>
</th>
<th class="cellrowborder" valign="top" width="52.449999999999996%" id="mcps1.1.6.1.5"><p id="p14987817436"><a name="p14987817436"></a><a name="p14987817436"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row129819844311"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p129911816436"><a name="p129911816436"></a><a name="p129911816436"></a>locale</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p5994814311"><a name="p5994814311"></a><a name="p5994814311"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p14991584436"><a name="p14991584436"></a><a name="p14991584436"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p14996894319"><a name="p14996894319"></a><a name="p14996894319"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p14561269443"><a name="p14561269443"></a><a name="p14561269443"></a>A string containing locale information, including the language, optional script, and locale.</p>
</td>
</tr>
<tr id="row119978194311"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p39913811434"><a name="p39913811434"></a><a name="p39913811434"></a>numeric</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p199918813439"><a name="p199918813439"></a><a name="p199918813439"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p199916813430"><a name="p199916813430"></a><a name="p199916813430"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p59914817435"><a name="p59914817435"></a><a name="p59914817435"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p61005854317"><a name="p61005854317"></a><a name="p61005854317"></a>Format of the output message. The value can be <strong id="b1150713718510"><a name="b1150713718510"></a><a name="b1150713718510"></a>always</strong> or <strong id="b195131471458"><a name="b195131471458"></a><a name="b195131471458"></a>auto</strong>.</p>
</td>
</tr>
<tr id="row10100158174310"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p151001585436"><a name="p151001585436"></a><a name="p151001585436"></a>style</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p17100148114312"><a name="p17100148114312"></a><a name="p17100148114312"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p11009815435"><a name="p11009815435"></a><a name="p11009815435"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p111009884316"><a name="p111009884316"></a><a name="p111009884316"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p191008814318"><a name="p191008814318"></a><a name="p191008814318"></a>Length of the internationalized message. The value can be <strong id="b1782351519610"><a name="b1782351519610"></a><a name="b1782351519610"></a>long</strong>, <strong id="b59781217963"><a name="b59781217963"></a><a name="b59781217963"></a>short</strong>, or <strong id="b46725196613"><a name="b46725196613"></a><a name="b46725196613"></a>narrow</strong>.</p>
</td>
</tr>
<tr id="row31241030174419"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p10124930164412"><a name="p10124930164412"></a><a name="p10124930164412"></a>numberingSystem</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p111241530174413"><a name="p111241530174413"></a><a name="p111241530174413"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p16124143017447"><a name="p16124143017447"></a><a name="p16124143017447"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p1712463034417"><a name="p1712463034417"></a><a name="p1712463034417"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p14124113074410"><a name="p14124113074410"></a><a name="p14124113074410"></a>Numbering system.</p>
</td>
</tr>
</tbody>
</table>
