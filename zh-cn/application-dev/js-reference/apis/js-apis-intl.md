# 国际化（Intl）<a name="ZH-CN_TOPIC_0000001163817108"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从 API Version 6 开始支持。

## 导入模块<a name="zh-cn_topic_0000001103315838_s56d19203690d4782bfc74069abb6bd71"></a>

```
import intl from '@ohos.intl';
```

## 权限<a name="zh-cn_topic_0000001103315838_section11257113618419"></a>

无

## Locale<a name="zh-cn_topic_0000001103315838_section422715643011"></a>

### 属性<a name="zh-cn_topic_0000001103315838_section1778221585513"></a>

<a name="zh-cn_topic_0000001103315838_table1378271515552"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001103315838_row1078291525514"><th class="cellrowborder" valign="top" width="15.870000000000001%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001103315838_p17821115155511"><a name="zh-cn_topic_0000001103315838_p17821115155511"></a><a name="zh-cn_topic_0000001103315838_p17821115155511"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="10.86%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001103315838_p47821215145515"><a name="zh-cn_topic_0000001103315838_p47821215145515"></a><a name="zh-cn_topic_0000001103315838_p47821215145515"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.34%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001103315838_p878221545513"><a name="zh-cn_topic_0000001103315838_p878221545513"></a><a name="zh-cn_topic_0000001103315838_p878221545513"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001103315838_p11782121518559"><a name="zh-cn_topic_0000001103315838_p11782121518559"></a><a name="zh-cn_topic_0000001103315838_p11782121518559"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001103315838_p97821715125513"><a name="zh-cn_topic_0000001103315838_p97821715125513"></a><a name="zh-cn_topic_0000001103315838_p97821715125513"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001103315838_row3782131535519"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001103315838_p7782615185518"><a name="zh-cn_topic_0000001103315838_p7782615185518"></a><a name="zh-cn_topic_0000001103315838_p7782615185518"></a>language</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001103315838_p1532011315106"><a name="zh-cn_topic_0000001103315838_p1532011315106"></a><a name="zh-cn_topic_0000001103315838_p1532011315106"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001103315838_p57831415165515"><a name="zh-cn_topic_0000001103315838_p57831415165515"></a><a name="zh-cn_topic_0000001103315838_p57831415165515"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001103315838_p17831515175518"><a name="zh-cn_topic_0000001103315838_p17831515175518"></a><a name="zh-cn_topic_0000001103315838_p17831515175518"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001103315838_p12783115145518"><a name="zh-cn_topic_0000001103315838_p12783115145518"></a><a name="zh-cn_topic_0000001103315838_p12783115145518"></a><span>与区域设置关联的语言</span></p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103315838_row18783101512558"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001103315838_p197832015125519"><a name="zh-cn_topic_0000001103315838_p197832015125519"></a><a name="zh-cn_topic_0000001103315838_p197832015125519"></a>script</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001103315838_p19814797107"><a name="zh-cn_topic_0000001103315838_p19814797107"></a><a name="zh-cn_topic_0000001103315838_p19814797107"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001103315838_p1178341516559"><a name="zh-cn_topic_0000001103315838_p1178341516559"></a><a name="zh-cn_topic_0000001103315838_p1178341516559"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001103315838_p207831615115519"><a name="zh-cn_topic_0000001103315838_p207831615115519"></a><a name="zh-cn_topic_0000001103315838_p207831615115519"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001103315838_p1878311155553"><a name="zh-cn_topic_0000001103315838_p1878311155553"></a><a name="zh-cn_topic_0000001103315838_p1878311155553"></a><span>语言的书写方式</span></p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103315838_row11401739287"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001103315838_p131413393816"><a name="zh-cn_topic_0000001103315838_p131413393816"></a><a name="zh-cn_topic_0000001103315838_p131413393816"></a>region</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001103315838_p414103920813"><a name="zh-cn_topic_0000001103315838_p414103920813"></a><a name="zh-cn_topic_0000001103315838_p414103920813"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001103315838_p1141183916819"><a name="zh-cn_topic_0000001103315838_p1141183916819"></a><a name="zh-cn_topic_0000001103315838_p1141183916819"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001103315838_p16936114313107"><a name="zh-cn_topic_0000001103315838_p16936114313107"></a><a name="zh-cn_topic_0000001103315838_p16936114313107"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001103315838_p16141183916818"><a name="zh-cn_topic_0000001103315838_p16141183916818"></a><a name="zh-cn_topic_0000001103315838_p16141183916818"></a><span>与区域设置相关的</span>地区</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103315838_row324144214819"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001103315838_p5245421082"><a name="zh-cn_topic_0000001103315838_p5245421082"></a><a name="zh-cn_topic_0000001103315838_p5245421082"></a>baseName</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001103315838_p2024144219810"><a name="zh-cn_topic_0000001103315838_p2024144219810"></a><a name="zh-cn_topic_0000001103315838_p2024144219810"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001103315838_p42415422813"><a name="zh-cn_topic_0000001103315838_p42415422813"></a><a name="zh-cn_topic_0000001103315838_p42415422813"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001103315838_p055911448108"><a name="zh-cn_topic_0000001103315838_p055911448108"></a><a name="zh-cn_topic_0000001103315838_p055911448108"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001103315838_p4246421818"><a name="zh-cn_topic_0000001103315838_p4246421818"></a><a name="zh-cn_topic_0000001103315838_p4246421818"></a>Locale的基本核心信息</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103315838_row2182164417817"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001103315838_p1318214441889"><a name="zh-cn_topic_0000001103315838_p1318214441889"></a><a name="zh-cn_topic_0000001103315838_p1318214441889"></a>caseFirst</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001103315838_p1418211440811"><a name="zh-cn_topic_0000001103315838_p1418211440811"></a><a name="zh-cn_topic_0000001103315838_p1418211440811"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001103315838_p181821344888"><a name="zh-cn_topic_0000001103315838_p181821344888"></a><a name="zh-cn_topic_0000001103315838_p181821344888"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001103315838_p119084591015"><a name="zh-cn_topic_0000001103315838_p119084591015"></a><a name="zh-cn_topic_0000001103315838_p119084591015"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001103315838_p111822441087"><a name="zh-cn_topic_0000001103315838_p111822441087"></a><a name="zh-cn_topic_0000001103315838_p111822441087"></a><span>区域的整理规则是否考虑大小写</span></p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103315838_row616319461180"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001103315838_p1416310461486"><a name="zh-cn_topic_0000001103315838_p1416310461486"></a><a name="zh-cn_topic_0000001103315838_p1416310461486"></a>calendar</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001103315838_p1216320461982"><a name="zh-cn_topic_0000001103315838_p1216320461982"></a><a name="zh-cn_topic_0000001103315838_p1216320461982"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001103315838_p916319461588"><a name="zh-cn_topic_0000001103315838_p916319461588"></a><a name="zh-cn_topic_0000001103315838_p916319461588"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001103315838_p667234511012"><a name="zh-cn_topic_0000001103315838_p667234511012"></a><a name="zh-cn_topic_0000001103315838_p667234511012"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001103315838_p1916315466811"><a name="zh-cn_topic_0000001103315838_p1916315466811"></a><a name="zh-cn_topic_0000001103315838_p1916315466811"></a>区域的日历信息</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103315838_row97016482083"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001103315838_p570124810815"><a name="zh-cn_topic_0000001103315838_p570124810815"></a><a name="zh-cn_topic_0000001103315838_p570124810815"></a>collation</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001103315838_p1270748588"><a name="zh-cn_topic_0000001103315838_p1270748588"></a><a name="zh-cn_topic_0000001103315838_p1270748588"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001103315838_p8701648186"><a name="zh-cn_topic_0000001103315838_p8701648186"></a><a name="zh-cn_topic_0000001103315838_p8701648186"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001103315838_p1327834619106"><a name="zh-cn_topic_0000001103315838_p1327834619106"></a><a name="zh-cn_topic_0000001103315838_p1327834619106"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001103315838_p117094811816"><a name="zh-cn_topic_0000001103315838_p117094811816"></a><a name="zh-cn_topic_0000001103315838_p117094811816"></a>区域的排序规则</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103315838_row22661650989"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001103315838_p826710501284"><a name="zh-cn_topic_0000001103315838_p826710501284"></a><a name="zh-cn_topic_0000001103315838_p826710501284"></a>hourCycle</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001103315838_p626745013817"><a name="zh-cn_topic_0000001103315838_p626745013817"></a><a name="zh-cn_topic_0000001103315838_p626745013817"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001103315838_p19267105018810"><a name="zh-cn_topic_0000001103315838_p19267105018810"></a><a name="zh-cn_topic_0000001103315838_p19267105018810"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001103315838_p692464614109"><a name="zh-cn_topic_0000001103315838_p692464614109"></a><a name="zh-cn_topic_0000001103315838_p692464614109"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001103315838_p19267155017816"><a name="zh-cn_topic_0000001103315838_p19267155017816"></a><a name="zh-cn_topic_0000001103315838_p19267155017816"></a>区域的时制信息</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103315838_row738595216815"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001103315838_p133851452181"><a name="zh-cn_topic_0000001103315838_p133851452181"></a><a name="zh-cn_topic_0000001103315838_p133851452181"></a>numberingSystem</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001103315838_p53851520819"><a name="zh-cn_topic_0000001103315838_p53851520819"></a><a name="zh-cn_topic_0000001103315838_p53851520819"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001103315838_p163851852980"><a name="zh-cn_topic_0000001103315838_p163851852980"></a><a name="zh-cn_topic_0000001103315838_p163851852980"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001103315838_p9827647161017"><a name="zh-cn_topic_0000001103315838_p9827647161017"></a><a name="zh-cn_topic_0000001103315838_p9827647161017"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001103315838_p63855529817"><a name="zh-cn_topic_0000001103315838_p63855529817"></a><a name="zh-cn_topic_0000001103315838_p63855529817"></a>区域使用的数字系统</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103315838_row1471125410817"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001103315838_p1571120541820"><a name="zh-cn_topic_0000001103315838_p1571120541820"></a><a name="zh-cn_topic_0000001103315838_p1571120541820"></a>numeric</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001103315838_p67111541886"><a name="zh-cn_topic_0000001103315838_p67111541886"></a><a name="zh-cn_topic_0000001103315838_p67111541886"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001103315838_p171115543810"><a name="zh-cn_topic_0000001103315838_p171115543810"></a><a name="zh-cn_topic_0000001103315838_p171115543810"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001103315838_p1845174816106"><a name="zh-cn_topic_0000001103315838_p1845174816106"></a><a name="zh-cn_topic_0000001103315838_p1845174816106"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001103315838_p87111354380"><a name="zh-cn_topic_0000001103315838_p87111354380"></a><a name="zh-cn_topic_0000001103315838_p87111354380"></a><span>是否对数字字符具有特殊的排序规则处理</span></p>
</td>
</tr>
</tbody>
</table>

### constructor<a name="zh-cn_topic_0000001103315838_section32282618302"></a>

constructor\(locale: string, options?:options\)

创建区域对象

-   参数：

    <a name="zh-cn_topic_0000001103315838_table69661135912"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001103315838_row149668318915"><th class="cellrowborder" valign="top" width="8.81%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001103315838_p7966738914"><a name="zh-cn_topic_0000001103315838_p7966738914"></a><a name="zh-cn_topic_0000001103315838_p7966738914"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="27.11%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001103315838_p296713699"><a name="zh-cn_topic_0000001103315838_p296713699"></a><a name="zh-cn_topic_0000001103315838_p296713699"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.710000000000001%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001103315838_p196718315911"><a name="zh-cn_topic_0000001103315838_p196718315911"></a><a name="zh-cn_topic_0000001103315838_p196718315911"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="57.37%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001103315838_p9967231197"><a name="zh-cn_topic_0000001103315838_p9967231197"></a><a name="zh-cn_topic_0000001103315838_p9967231197"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001103315838_row99671533914"><td class="cellrowborder" valign="top" width="8.81%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001103315838_p13838351705"><a name="zh-cn_topic_0000001103315838_p13838351705"></a><a name="zh-cn_topic_0000001103315838_p13838351705"></a>locale</p>
    </td>
    <td class="cellrowborder" valign="top" width="27.11%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001103315838_p11967433914"><a name="zh-cn_topic_0000001103315838_p11967433914"></a><a name="zh-cn_topic_0000001103315838_p11967433914"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.710000000000001%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001103315838_p19671336916"><a name="zh-cn_topic_0000001103315838_p19671336916"></a><a name="zh-cn_topic_0000001103315838_p19671336916"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="57.37%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001103315838_p69671631796"><a name="zh-cn_topic_0000001103315838_p69671631796"></a><a name="zh-cn_topic_0000001103315838_p69671631796"></a>包含区域设置信息的字符串，包括语言以及可选的脚本和区域。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001103315838_row14743191495712"><td class="cellrowborder" valign="top" width="8.81%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001103315838_p11743111475719"><a name="zh-cn_topic_0000001103315838_p11743111475719"></a><a name="zh-cn_topic_0000001103315838_p11743111475719"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="27.11%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001103315838_p1274415142572"><a name="zh-cn_topic_0000001103315838_p1274415142572"></a><a name="zh-cn_topic_0000001103315838_p1274415142572"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.710000000000001%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001103315838_p6744181425719"><a name="zh-cn_topic_0000001103315838_p6744181425719"></a><a name="zh-cn_topic_0000001103315838_p6744181425719"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="57.37%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001103315838_p1974414145576"><a name="zh-cn_topic_0000001103315838_p1974414145576"></a><a name="zh-cn_topic_0000001103315838_p1974414145576"></a>用于创建区域对象的选项。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例：

    ```
    var locale = new Locale("zh-CN");
    ```


### toString<a name="zh-cn_topic_0000001103315838_section6361163518520"></a>

toString\(\): string

将区域信息转换为字符串

-   返回值：

    <a name="zh-cn_topic_0000001103315838_table97866231562"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001103315838_row378662317610"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001103315838_p4786423668"><a name="zh-cn_topic_0000001103315838_p4786423668"></a><a name="zh-cn_topic_0000001103315838_p4786423668"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001103315838_p578682318614"><a name="zh-cn_topic_0000001103315838_p578682318614"></a><a name="zh-cn_topic_0000001103315838_p578682318614"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001103315838_row177861823963"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001103315838_p1078617238618"><a name="zh-cn_topic_0000001103315838_p1078617238618"></a><a name="zh-cn_topic_0000001103315838_p1078617238618"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001103315838_p578611231565"><a name="zh-cn_topic_0000001103315838_p578611231565"></a><a name="zh-cn_topic_0000001103315838_p578611231565"></a>字符串形式的区域信息</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例：

    ```
    var locale = new Locale("zh-CN");
    locale.toString();
    ```


### maximize<a name="zh-cn_topic_0000001103315838_section16459237152"></a>

maximize\(\): Locale

最大化区域信息，若缺少脚本与地区信息，则补齐。

-   返回值：

    <a name="zh-cn_topic_0000001103315838_table94114239714"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001103315838_row3411112311714"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001103315838_p04119231171"><a name="zh-cn_topic_0000001103315838_p04119231171"></a><a name="zh-cn_topic_0000001103315838_p04119231171"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001103315838_p164119231574"><a name="zh-cn_topic_0000001103315838_p164119231574"></a><a name="zh-cn_topic_0000001103315838_p164119231574"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001103315838_row941112231572"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001103315838_p341102317718"><a name="zh-cn_topic_0000001103315838_p341102317718"></a><a name="zh-cn_topic_0000001103315838_p341102317718"></a>Locale</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001103315838_p1341122314711"><a name="zh-cn_topic_0000001103315838_p1341122314711"></a><a name="zh-cn_topic_0000001103315838_p1341122314711"></a>最大化后的区域对象</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例：

    ```
    var locale = new Locale("zh-CN");
    locale.maximize();
    ```


### minimize<a name="zh-cn_topic_0000001103315838_section8112183915517"></a>

minimize\(\): Locale

最小化区域信息，若包含脚本与地区信息，则去除。

-   返回值：

    <a name="zh-cn_topic_0000001103315838_table128315221814"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001103315838_row6831152215817"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001103315838_p3831192213819"><a name="zh-cn_topic_0000001103315838_p3831192213819"></a><a name="zh-cn_topic_0000001103315838_p3831192213819"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001103315838_p1883214221088"><a name="zh-cn_topic_0000001103315838_p1883214221088"></a><a name="zh-cn_topic_0000001103315838_p1883214221088"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001103315838_row1183218227818"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001103315838_p483210226819"><a name="zh-cn_topic_0000001103315838_p483210226819"></a><a name="zh-cn_topic_0000001103315838_p483210226819"></a>Locale</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001103315838_p17832222781"><a name="zh-cn_topic_0000001103315838_p17832222781"></a><a name="zh-cn_topic_0000001103315838_p17832222781"></a>最小化后的区域对象</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例：

    ```
    var locale = new Locale("zh-CN");
    locale.minimize();
    ```


## DateTimeFormat<a name="zh-cn_topic_0000001103315838_section164003264319"></a>

### constructor<a name="zh-cn_topic_0000001103315838_section740052693112"></a>

constructor\(locale: string, options?:DateTimeOptions\)

创建时间日期格式化对象。

-   参数：

    <a name="zh-cn_topic_0000001103315838_table356962217321"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001103315838_row185691227322"><th class="cellrowborder" valign="top" width="11.119698579847357%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001103315838_p18569132213213"><a name="zh-cn_topic_0000001103315838_p18569132213213"></a><a name="zh-cn_topic_0000001103315838_p18569132213213"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="22.905999420345864%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001103315838_p25691822183218"><a name="zh-cn_topic_0000001103315838_p25691822183218"></a><a name="zh-cn_topic_0000001103315838_p25691822183218"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.356873732006569%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001103315838_p14569192218320"><a name="zh-cn_topic_0000001103315838_p14569192218320"></a><a name="zh-cn_topic_0000001103315838_p14569192218320"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.61742826780022%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001103315838_p556972263210"><a name="zh-cn_topic_0000001103315838_p556972263210"></a><a name="zh-cn_topic_0000001103315838_p556972263210"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001103315838_row1756982217321"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001103315838_p20569132223214"><a name="zh-cn_topic_0000001103315838_p20569132223214"></a><a name="zh-cn_topic_0000001103315838_p20569132223214"></a>locale</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001103315838_p1856902273219"><a name="zh-cn_topic_0000001103315838_p1856902273219"></a><a name="zh-cn_topic_0000001103315838_p1856902273219"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001103315838_p15569142233219"><a name="zh-cn_topic_0000001103315838_p15569142233219"></a><a name="zh-cn_topic_0000001103315838_p15569142233219"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001103315838_p18569162212321"><a name="zh-cn_topic_0000001103315838_p18569162212321"></a><a name="zh-cn_topic_0000001103315838_p18569162212321"></a>包含区域设置信息的字符串，包括语言以及可选的脚本和区域。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001103315838_row056902210325"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001103315838_p145697223321"><a name="zh-cn_topic_0000001103315838_p145697223321"></a><a name="zh-cn_topic_0000001103315838_p145697223321"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001103315838_p956962219323"><a name="zh-cn_topic_0000001103315838_p956962219323"></a><a name="zh-cn_topic_0000001103315838_p956962219323"></a><a href="#zh-cn_topic_0000001103315838_section12882825611">DateTimeOptions</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001103315838_p195695222325"><a name="zh-cn_topic_0000001103315838_p195695222325"></a><a name="zh-cn_topic_0000001103315838_p195695222325"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001103315838_p8569922103214"><a name="zh-cn_topic_0000001103315838_p8569922103214"></a><a name="zh-cn_topic_0000001103315838_p8569922103214"></a>用于创建时间日期格式化的选项。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例：

    ```
    var datefmt= new DateTimeFormat("zh-CN", { dateStyle: 'full', timeStyle: 'medium' });
    ```


### constructor<a name="zh-cn_topic_0000001103315838_section1400182613114"></a>

constructor\(locales: Array<string\>, options?:DateTimeOptions\)

创建时间日期格式化对象。

-   参数：

    <a name="zh-cn_topic_0000001103315838_table1429997153311"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001103315838_row229911773310"><th class="cellrowborder" valign="top" width="11.119698579847357%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001103315838_p15299171333"><a name="zh-cn_topic_0000001103315838_p15299171333"></a><a name="zh-cn_topic_0000001103315838_p15299171333"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="22.905999420345864%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001103315838_p1629912719331"><a name="zh-cn_topic_0000001103315838_p1629912719331"></a><a name="zh-cn_topic_0000001103315838_p1629912719331"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.356873732006569%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001103315838_p829916783311"><a name="zh-cn_topic_0000001103315838_p829916783311"></a><a name="zh-cn_topic_0000001103315838_p829916783311"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.61742826780022%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001103315838_p4299279331"><a name="zh-cn_topic_0000001103315838_p4299279331"></a><a name="zh-cn_topic_0000001103315838_p4299279331"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001103315838_row52991074332"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001103315838_p1229911717332"><a name="zh-cn_topic_0000001103315838_p1229911717332"></a><a name="zh-cn_topic_0000001103315838_p1229911717332"></a>locales</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001103315838_p83001273339"><a name="zh-cn_topic_0000001103315838_p83001273339"></a><a name="zh-cn_topic_0000001103315838_p83001273339"></a>Array&lt;string&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001103315838_p113001717331"><a name="zh-cn_topic_0000001103315838_p113001717331"></a><a name="zh-cn_topic_0000001103315838_p113001717331"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001103315838_p153001778336"><a name="zh-cn_topic_0000001103315838_p153001778336"></a><a name="zh-cn_topic_0000001103315838_p153001778336"></a>包含区域设置信息的字符串的数组。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001103315838_row23000715337"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001103315838_p133007743315"><a name="zh-cn_topic_0000001103315838_p133007743315"></a><a name="zh-cn_topic_0000001103315838_p133007743315"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001103315838_p83001783320"><a name="zh-cn_topic_0000001103315838_p83001783320"></a><a name="zh-cn_topic_0000001103315838_p83001783320"></a><a href="#zh-cn_topic_0000001103315838_section12882825611">DateTimeOptions</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001103315838_p230013713339"><a name="zh-cn_topic_0000001103315838_p230013713339"></a><a name="zh-cn_topic_0000001103315838_p230013713339"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001103315838_p20300374333"><a name="zh-cn_topic_0000001103315838_p20300374333"></a><a name="zh-cn_topic_0000001103315838_p20300374333"></a>用于创建时间日期格式化的选项。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例：

    ```
    var datefmt= new DateTimeFormat(["ban", "zh"], { dateStyle: 'full', timeStyle: 'medium' });
    ```


### format<a name="zh-cn_topic_0000001103315838_section1840262614313"></a>

format\(date: Date\): string;

格式化时间日期字符串。

-   参数：

    <a name="zh-cn_topic_0000001103315838_table104041622203411"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001103315838_row3405102263418"><th class="cellrowborder" valign="top" width="11.119698579847357%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001103315838_p164051422183414"><a name="zh-cn_topic_0000001103315838_p164051422183414"></a><a name="zh-cn_topic_0000001103315838_p164051422183414"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="22.905999420345864%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001103315838_p194051522123413"><a name="zh-cn_topic_0000001103315838_p194051522123413"></a><a name="zh-cn_topic_0000001103315838_p194051522123413"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.356873732006569%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001103315838_p1405922193417"><a name="zh-cn_topic_0000001103315838_p1405922193417"></a><a name="zh-cn_topic_0000001103315838_p1405922193417"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.61742826780022%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001103315838_p1140516225342"><a name="zh-cn_topic_0000001103315838_p1140516225342"></a><a name="zh-cn_topic_0000001103315838_p1140516225342"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001103315838_row9405822163419"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001103315838_p104051322173411"><a name="zh-cn_topic_0000001103315838_p104051322173411"></a><a name="zh-cn_topic_0000001103315838_p104051322173411"></a>date</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001103315838_p740519224344"><a name="zh-cn_topic_0000001103315838_p740519224344"></a><a name="zh-cn_topic_0000001103315838_p740519224344"></a>Date</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001103315838_p194051122173417"><a name="zh-cn_topic_0000001103315838_p194051122173417"></a><a name="zh-cn_topic_0000001103315838_p194051122173417"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001103315838_p19405172212342"><a name="zh-cn_topic_0000001103315838_p19405172212342"></a><a name="zh-cn_topic_0000001103315838_p19405172212342"></a>时间日期对象。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="zh-cn_topic_0000001103315838_table9402122612316"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001103315838_row104029264319"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001103315838_p440212633116"><a name="zh-cn_topic_0000001103315838_p440212633116"></a><a name="zh-cn_topic_0000001103315838_p440212633116"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001103315838_p144021226173112"><a name="zh-cn_topic_0000001103315838_p144021226173112"></a><a name="zh-cn_topic_0000001103315838_p144021226173112"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001103315838_row3402112617311"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001103315838_p340262673111"><a name="zh-cn_topic_0000001103315838_p340262673111"></a><a name="zh-cn_topic_0000001103315838_p340262673111"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001103315838_p1040215260316"><a name="zh-cn_topic_0000001103315838_p1040215260316"></a><a name="zh-cn_topic_0000001103315838_p1040215260316"></a>格式化后的时间日期字符串</p>
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


### formatRange<a name="zh-cn_topic_0000001103315838_section4402132614312"></a>

formatRange\(fromDate: Date, toDate: Date\): string;

格式化时间日期段字符串。

-   参数：

    <a name="zh-cn_topic_0000001103315838_table24021326153112"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001103315838_row15403126153116"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001103315838_p3403182693112"><a name="zh-cn_topic_0000001103315838_p3403182693112"></a><a name="zh-cn_topic_0000001103315838_p3403182693112"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001103315838_p1640372611319"><a name="zh-cn_topic_0000001103315838_p1640372611319"></a><a name="zh-cn_topic_0000001103315838_p1640372611319"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001103315838_p1540352615319"><a name="zh-cn_topic_0000001103315838_p1540352615319"></a><a name="zh-cn_topic_0000001103315838_p1540352615319"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001103315838_p17403152623117"><a name="zh-cn_topic_0000001103315838_p17403152623117"></a><a name="zh-cn_topic_0000001103315838_p17403152623117"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001103315838_row11403182693114"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001103315838_p15403726183117"><a name="zh-cn_topic_0000001103315838_p15403726183117"></a><a name="zh-cn_topic_0000001103315838_p15403726183117"></a>startDate</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001103315838_p124033261313"><a name="zh-cn_topic_0000001103315838_p124033261313"></a><a name="zh-cn_topic_0000001103315838_p124033261313"></a>Date</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001103315838_p124039266311"><a name="zh-cn_topic_0000001103315838_p124039266311"></a><a name="zh-cn_topic_0000001103315838_p124039266311"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001103315838_p840362633117"><a name="zh-cn_topic_0000001103315838_p840362633117"></a><a name="zh-cn_topic_0000001103315838_p840362633117"></a>起始的时间日期</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001103315838_row4629861544"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001103315838_p66299618414"><a name="zh-cn_topic_0000001103315838_p66299618414"></a><a name="zh-cn_topic_0000001103315838_p66299618414"></a>endDate</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001103315838_p136291962419"><a name="zh-cn_topic_0000001103315838_p136291962419"></a><a name="zh-cn_topic_0000001103315838_p136291962419"></a>Date</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001103315838_p186296610412"><a name="zh-cn_topic_0000001103315838_p186296610412"></a><a name="zh-cn_topic_0000001103315838_p186296610412"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001103315838_p116291262415"><a name="zh-cn_topic_0000001103315838_p116291262415"></a><a name="zh-cn_topic_0000001103315838_p116291262415"></a>结束的时间日期</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="zh-cn_topic_0000001103315838_table114031226173116"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001103315838_row204031126123119"><th class="cellrowborder" valign="top" width="20.05%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001103315838_p64036261318"><a name="zh-cn_topic_0000001103315838_p64036261318"></a><a name="zh-cn_topic_0000001103315838_p64036261318"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.95%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001103315838_p4403132613317"><a name="zh-cn_topic_0000001103315838_p4403132613317"></a><a name="zh-cn_topic_0000001103315838_p4403132613317"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001103315838_row19403162616316"><td class="cellrowborder" valign="top" width="20.05%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001103315838_p15404132673120"><a name="zh-cn_topic_0000001103315838_p15404132673120"></a><a name="zh-cn_topic_0000001103315838_p15404132673120"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.95%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001103315838_p94042261310"><a name="zh-cn_topic_0000001103315838_p94042261310"></a><a name="zh-cn_topic_0000001103315838_p94042261310"></a>格式化后的时间日期段字符串</p>
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


### resolvedOptions<a name="zh-cn_topic_0000001103315838_section1093513817123"></a>

resolvedOptions\(\): DateTimeOptions

获取DateTimeFormat 对象的格式化选项。

-   返回值：

    <a name="zh-cn_topic_0000001103315838_table1393663841210"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001103315838_row5936113816126"><th class="cellrowborder" valign="top" width="20.05%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001103315838_p1493614383126"><a name="zh-cn_topic_0000001103315838_p1493614383126"></a><a name="zh-cn_topic_0000001103315838_p1493614383126"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.95%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001103315838_p1293633819124"><a name="zh-cn_topic_0000001103315838_p1293633819124"></a><a name="zh-cn_topic_0000001103315838_p1293633819124"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001103315838_row393643871210"><td class="cellrowborder" valign="top" width="20.05%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001103315838_p9936163816125"><a name="zh-cn_topic_0000001103315838_p9936163816125"></a><a name="zh-cn_topic_0000001103315838_p9936163816125"></a><a href="#zh-cn_topic_0000001103315838_section12882825611">DateTimeOptions</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="79.95%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001103315838_p13936143812129"><a name="zh-cn_topic_0000001103315838_p13936143812129"></a><a name="zh-cn_topic_0000001103315838_p13936143812129"></a>DateTimeFormat 对象的格式化选项。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例：

    ```
    var datefmt = new Intl.DateTimeFormat("en-GB");
    datefmt.resolvedOptions();
    ```


## NumberFormat<a name="zh-cn_topic_0000001103315838_section10453336123119"></a>

### constructor<a name="zh-cn_topic_0000001103315838_section14453163693117"></a>

constructor\(locale: string, options?:NumberOptions\)

创建数字格式化对象。

参数：

<a name="zh-cn_topic_0000001103315838_table830832401619"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001103315838_row23081824181616"><th class="cellrowborder" valign="top" width="11.119698579847357%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001103315838_p1930892416168"><a name="zh-cn_topic_0000001103315838_p1930892416168"></a><a name="zh-cn_topic_0000001103315838_p1930892416168"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="22.905999420345864%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001103315838_p14308112431619"><a name="zh-cn_topic_0000001103315838_p14308112431619"></a><a name="zh-cn_topic_0000001103315838_p14308112431619"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="6.356873732006569%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001103315838_p173081324151614"><a name="zh-cn_topic_0000001103315838_p173081324151614"></a><a name="zh-cn_topic_0000001103315838_p173081324151614"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="59.61742826780022%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001103315838_p123092024101615"><a name="zh-cn_topic_0000001103315838_p123092024101615"></a><a name="zh-cn_topic_0000001103315838_p123092024101615"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001103315838_row14309192401619"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001103315838_p03096245167"><a name="zh-cn_topic_0000001103315838_p03096245167"></a><a name="zh-cn_topic_0000001103315838_p03096245167"></a>locale</p>
</td>
<td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001103315838_p73094243167"><a name="zh-cn_topic_0000001103315838_p73094243167"></a><a name="zh-cn_topic_0000001103315838_p73094243167"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001103315838_p5309192461611"><a name="zh-cn_topic_0000001103315838_p5309192461611"></a><a name="zh-cn_topic_0000001103315838_p5309192461611"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001103315838_p133091924181620"><a name="zh-cn_topic_0000001103315838_p133091924181620"></a><a name="zh-cn_topic_0000001103315838_p133091924181620"></a>包含区域设置信息的字符串，包括语言以及可选的脚本和区域。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103315838_row133091924171615"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001103315838_p53091824181619"><a name="zh-cn_topic_0000001103315838_p53091824181619"></a><a name="zh-cn_topic_0000001103315838_p53091824181619"></a>options</p>
</td>
<td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001103315838_p7309424171618"><a name="zh-cn_topic_0000001103315838_p7309424171618"></a><a name="zh-cn_topic_0000001103315838_p7309424171618"></a><a href="#zh-cn_topic_0000001103315838_section7200123494410">NumberOptions</a></p>
</td>
<td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001103315838_p3309202414168"><a name="zh-cn_topic_0000001103315838_p3309202414168"></a><a name="zh-cn_topic_0000001103315838_p3309202414168"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001103315838_p6309202413162"><a name="zh-cn_topic_0000001103315838_p6309202413162"></a><a name="zh-cn_topic_0000001103315838_p6309202413162"></a>用于创建数字格式化的选项。</p>
</td>
</tr>
</tbody>
</table>

-   示例：

    ```
    var numfmt = new Intl.NumberFormat("en-GB", {style:'decimal', notation:"scientific"});
    ```


### constructor<a name="zh-cn_topic_0000001103315838_section54533363319"></a>

constructor\(locales: Array<string\>, options?:NumberOptions\)

创建数字格式化对象。

-   参数：

    <a name="zh-cn_topic_0000001103315838_table1886184401618"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001103315838_row68615446163"><th class="cellrowborder" valign="top" width="10.73326248671626%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001103315838_p88611446168"><a name="zh-cn_topic_0000001103315838_p88611446168"></a><a name="zh-cn_topic_0000001103315838_p88611446168"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="23.29243551347696%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001103315838_p12861644191616"><a name="zh-cn_topic_0000001103315838_p12861644191616"></a><a name="zh-cn_topic_0000001103315838_p12861644191616"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.356873732006569%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001103315838_p7861174419169"><a name="zh-cn_topic_0000001103315838_p7861174419169"></a><a name="zh-cn_topic_0000001103315838_p7861174419169"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.61742826780022%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001103315838_p14862744191618"><a name="zh-cn_topic_0000001103315838_p14862744191618"></a><a name="zh-cn_topic_0000001103315838_p14862744191618"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001103315838_row20862544191620"><td class="cellrowborder" valign="top" width="10.73326248671626%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001103315838_p3862344191619"><a name="zh-cn_topic_0000001103315838_p3862344191619"></a><a name="zh-cn_topic_0000001103315838_p3862344191619"></a>locales</p>
    </td>
    <td class="cellrowborder" valign="top" width="23.29243551347696%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001103315838_p28621044131614"><a name="zh-cn_topic_0000001103315838_p28621044131614"></a><a name="zh-cn_topic_0000001103315838_p28621044131614"></a>Array&lt;string&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001103315838_p1086211440167"><a name="zh-cn_topic_0000001103315838_p1086211440167"></a><a name="zh-cn_topic_0000001103315838_p1086211440167"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001103315838_p386234417161"><a name="zh-cn_topic_0000001103315838_p386234417161"></a><a name="zh-cn_topic_0000001103315838_p386234417161"></a>包含区域设置信息的字符串的数组。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001103315838_row986254461614"><td class="cellrowborder" valign="top" width="10.73326248671626%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001103315838_p88621344181616"><a name="zh-cn_topic_0000001103315838_p88621344181616"></a><a name="zh-cn_topic_0000001103315838_p88621344181616"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="23.29243551347696%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001103315838_p486284417168"><a name="zh-cn_topic_0000001103315838_p486284417168"></a><a name="zh-cn_topic_0000001103315838_p486284417168"></a><a href="#zh-cn_topic_0000001103315838_section7200123494410">NumberOptions</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001103315838_p1986216442160"><a name="zh-cn_topic_0000001103315838_p1986216442160"></a><a name="zh-cn_topic_0000001103315838_p1986216442160"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001103315838_p4862104421615"><a name="zh-cn_topic_0000001103315838_p4862104421615"></a><a name="zh-cn_topic_0000001103315838_p4862104421615"></a>用于创建数字格式化的选项。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例：

    ```
    var numfmt = new Intl.NumberFormat(["en-GB", "zh"], {style:'decimal', notation:"scientific"});
    ```


### format<a name="zh-cn_topic_0000001103315838_section94551936203114"></a>

format\(number: number\): string;

格式化数字字符串。

-   参数：

    <a name="zh-cn_topic_0000001103315838_table1459775620188"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001103315838_row059755610184"><th class="cellrowborder" valign="top" width="11.119698579847357%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001103315838_p19597205631810"><a name="zh-cn_topic_0000001103315838_p19597205631810"></a><a name="zh-cn_topic_0000001103315838_p19597205631810"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="22.905999420345864%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001103315838_p18597856161815"><a name="zh-cn_topic_0000001103315838_p18597856161815"></a><a name="zh-cn_topic_0000001103315838_p18597856161815"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.356873732006569%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001103315838_p1859735614180"><a name="zh-cn_topic_0000001103315838_p1859735614180"></a><a name="zh-cn_topic_0000001103315838_p1859735614180"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.61742826780022%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001103315838_p145971656101812"><a name="zh-cn_topic_0000001103315838_p145971656101812"></a><a name="zh-cn_topic_0000001103315838_p145971656101812"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001103315838_row11597195617186"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001103315838_p1959755631818"><a name="zh-cn_topic_0000001103315838_p1959755631818"></a><a name="zh-cn_topic_0000001103315838_p1959755631818"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001103315838_p12597155613186"><a name="zh-cn_topic_0000001103315838_p12597155613186"></a><a name="zh-cn_topic_0000001103315838_p12597155613186"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001103315838_p1559865612186"><a name="zh-cn_topic_0000001103315838_p1559865612186"></a><a name="zh-cn_topic_0000001103315838_p1559865612186"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001103315838_p95981556161816"><a name="zh-cn_topic_0000001103315838_p95981556161816"></a><a name="zh-cn_topic_0000001103315838_p95981556161816"></a>数字对象</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="zh-cn_topic_0000001103315838_table114558369317"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001103315838_row12455133613312"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001103315838_p545515361318"><a name="zh-cn_topic_0000001103315838_p545515361318"></a><a name="zh-cn_topic_0000001103315838_p545515361318"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001103315838_p145512362311"><a name="zh-cn_topic_0000001103315838_p145512362311"></a><a name="zh-cn_topic_0000001103315838_p145512362311"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001103315838_row3455193617316"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001103315838_p745523619314"><a name="zh-cn_topic_0000001103315838_p745523619314"></a><a name="zh-cn_topic_0000001103315838_p745523619314"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001103315838_p1745519363315"><a name="zh-cn_topic_0000001103315838_p1745519363315"></a><a name="zh-cn_topic_0000001103315838_p1745519363315"></a>格式化后的数字字符串</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例：

    ```
    var numfmt = new Intl.NumberFormat(["en-GB", "zh"], {style:'decimal', notation:"scientific"});
    numfmt.format(1223);
    ```


### resolvedOptions<a name="zh-cn_topic_0000001103315838_section13178203919219"></a>

resolvedOptions\(\): NumberOptions

获取NumberFormat 对象的格式化选项。

-   返回值：

    <a name="zh-cn_topic_0000001103315838_table917813992117"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001103315838_row1717883992116"><th class="cellrowborder" valign="top" width="20.05%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001103315838_p91781539202115"><a name="zh-cn_topic_0000001103315838_p91781539202115"></a><a name="zh-cn_topic_0000001103315838_p91781539202115"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.95%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001103315838_p151783399216"><a name="zh-cn_topic_0000001103315838_p151783399216"></a><a name="zh-cn_topic_0000001103315838_p151783399216"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001103315838_row1217814392214"><td class="cellrowborder" valign="top" width="20.05%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001103315838_p317903912212"><a name="zh-cn_topic_0000001103315838_p317903912212"></a><a name="zh-cn_topic_0000001103315838_p317903912212"></a><a href="#zh-cn_topic_0000001103315838_section7200123494410">NumberOptions</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="79.95%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001103315838_p111794399212"><a name="zh-cn_topic_0000001103315838_p111794399212"></a><a name="zh-cn_topic_0000001103315838_p111794399212"></a>NumberFormat 对象的格式化选项。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例：

    ```
    var numfmt = new Intl.NumberFormat(["en-GB", "zh"], {style:'decimal', notation:"scientific"});
    numfmt.resolvedOptions();
    ```


## DateTimeOptions<a name="zh-cn_topic_0000001103315838_section12882825611"></a>

表示时间日期格式化选项。

### 属性<a name="zh-cn_topic_0000001103315838_section1059684317312"></a>

<a name="zh-cn_topic_0000001103315838_table1459620431636"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001103315838_row25971143435"><th class="cellrowborder" valign="top" width="18.91%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001103315838_p1559716434320"><a name="zh-cn_topic_0000001103315838_p1559716434320"></a><a name="zh-cn_topic_0000001103315838_p1559716434320"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="7.82%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001103315838_p3597743539"><a name="zh-cn_topic_0000001103315838_p3597743539"></a><a name="zh-cn_topic_0000001103315838_p3597743539"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.33%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001103315838_p15971343131"><a name="zh-cn_topic_0000001103315838_p15971343131"></a><a name="zh-cn_topic_0000001103315838_p15971343131"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="11.52%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001103315838_p1459715436311"><a name="zh-cn_topic_0000001103315838_p1459715436311"></a><a name="zh-cn_topic_0000001103315838_p1459715436311"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001103315838_p75975439316"><a name="zh-cn_topic_0000001103315838_p75975439316"></a><a name="zh-cn_topic_0000001103315838_p75975439316"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001103315838_row95971943839"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001103315838_p85976431431"><a name="zh-cn_topic_0000001103315838_p85976431431"></a><a name="zh-cn_topic_0000001103315838_p85976431431"></a>locale</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001103315838_p1427924663417"><a name="zh-cn_topic_0000001103315838_p1427924663417"></a><a name="zh-cn_topic_0000001103315838_p1427924663417"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001103315838_p1059711439317"><a name="zh-cn_topic_0000001103315838_p1059711439317"></a><a name="zh-cn_topic_0000001103315838_p1059711439317"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001103315838_p659715430317"><a name="zh-cn_topic_0000001103315838_p659715430317"></a><a name="zh-cn_topic_0000001103315838_p659715430317"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001103315838_p12781024121115"><a name="zh-cn_topic_0000001103315838_p12781024121115"></a><a name="zh-cn_topic_0000001103315838_p12781024121115"></a>区域参数</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103315838_row185973435316"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001103315838_p1559710432310"><a name="zh-cn_topic_0000001103315838_p1559710432310"></a><a name="zh-cn_topic_0000001103315838_p1559710432310"></a>dateStyle</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001103315838_p16597144318312"><a name="zh-cn_topic_0000001103315838_p16597144318312"></a><a name="zh-cn_topic_0000001103315838_p16597144318312"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001103315838_p12597194313317"><a name="zh-cn_topic_0000001103315838_p12597194313317"></a><a name="zh-cn_topic_0000001103315838_p12597194313317"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001103315838_p892910583102"><a name="zh-cn_topic_0000001103315838_p892910583102"></a><a name="zh-cn_topic_0000001103315838_p892910583102"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001103315838_p1916912791117"><a name="zh-cn_topic_0000001103315838_p1916912791117"></a><a name="zh-cn_topic_0000001103315838_p1916912791117"></a>日期显示格式，取值范围："long", "short", "medium", "full"</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103315838_row892411307269"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001103315838_p139241230192614"><a name="zh-cn_topic_0000001103315838_p139241230192614"></a><a name="zh-cn_topic_0000001103315838_p139241230192614"></a>timeStyle</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001103315838_p4924183062614"><a name="zh-cn_topic_0000001103315838_p4924183062614"></a><a name="zh-cn_topic_0000001103315838_p4924183062614"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001103315838_p15401682357"><a name="zh-cn_topic_0000001103315838_p15401682357"></a><a name="zh-cn_topic_0000001103315838_p15401682357"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001103315838_p1896275851018"><a name="zh-cn_topic_0000001103315838_p1896275851018"></a><a name="zh-cn_topic_0000001103315838_p1896275851018"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001103315838_p2925830132619"><a name="zh-cn_topic_0000001103315838_p2925830132619"></a><a name="zh-cn_topic_0000001103315838_p2925830132619"></a>时间显示格式，取值范围："long", "short", "medium", "full"</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103315838_row155315532719"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001103315838_p185321542713"><a name="zh-cn_topic_0000001103315838_p185321542713"></a><a name="zh-cn_topic_0000001103315838_p185321542713"></a>hourCycle</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001103315838_p1053218512273"><a name="zh-cn_topic_0000001103315838_p1053218512273"></a><a name="zh-cn_topic_0000001103315838_p1053218512273"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001103315838_p18721483357"><a name="zh-cn_topic_0000001103315838_p18721483357"></a><a name="zh-cn_topic_0000001103315838_p18721483357"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001103315838_p799415812103"><a name="zh-cn_topic_0000001103315838_p799415812103"></a><a name="zh-cn_topic_0000001103315838_p799415812103"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001103315838_p4532135152710"><a name="zh-cn_topic_0000001103315838_p4532135152710"></a><a name="zh-cn_topic_0000001103315838_p4532135152710"></a>时制格式，取值范围："h11", "h12", "h23", "h24".</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103315838_row46421838277"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001103315838_p136422030277"><a name="zh-cn_topic_0000001103315838_p136422030277"></a><a name="zh-cn_topic_0000001103315838_p136422030277"></a>timeZone</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001103315838_p1364283182710"><a name="zh-cn_topic_0000001103315838_p1364283182710"></a><a name="zh-cn_topic_0000001103315838_p1364283182710"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001103315838_p11029833510"><a name="zh-cn_topic_0000001103315838_p11029833510"></a><a name="zh-cn_topic_0000001103315838_p11029833510"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001103315838_p18260598105"><a name="zh-cn_topic_0000001103315838_p18260598105"></a><a name="zh-cn_topic_0000001103315838_p18260598105"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001103315838_p5642103122711"><a name="zh-cn_topic_0000001103315838_p5642103122711"></a><a name="zh-cn_topic_0000001103315838_p5642103122711"></a>使用的时区（<span>合法的</span><span>IANA</span><span>时区</span>ID）</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103315838_row589712142718"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001103315838_p1689719132719"><a name="zh-cn_topic_0000001103315838_p1689719132719"></a><a name="zh-cn_topic_0000001103315838_p1689719132719"></a>numberingSystem</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001103315838_p28971919276"><a name="zh-cn_topic_0000001103315838_p28971919276"></a><a name="zh-cn_topic_0000001103315838_p28971919276"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001103315838_p9132118153512"><a name="zh-cn_topic_0000001103315838_p9132118153512"></a><a name="zh-cn_topic_0000001103315838_p9132118153512"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001103315838_p95865961017"><a name="zh-cn_topic_0000001103315838_p95865961017"></a><a name="zh-cn_topic_0000001103315838_p95865961017"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001103315838_p16897111192718"><a name="zh-cn_topic_0000001103315838_p16897111192718"></a><a name="zh-cn_topic_0000001103315838_p16897111192718"></a>数字系统</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103315838_row1190575820265"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001103315838_p1590585832620"><a name="zh-cn_topic_0000001103315838_p1590585832620"></a><a name="zh-cn_topic_0000001103315838_p1590585832620"></a>hour12</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001103315838_p119051584269"><a name="zh-cn_topic_0000001103315838_p119051584269"></a><a name="zh-cn_topic_0000001103315838_p119051584269"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001103315838_p131611815350"><a name="zh-cn_topic_0000001103315838_p131611815350"></a><a name="zh-cn_topic_0000001103315838_p131611815350"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001103315838_p1190559111013"><a name="zh-cn_topic_0000001103315838_p1190559111013"></a><a name="zh-cn_topic_0000001103315838_p1190559111013"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001103315838_p13905558122617"><a name="zh-cn_topic_0000001103315838_p13905558122617"></a><a name="zh-cn_topic_0000001103315838_p13905558122617"></a>是否使用12小时制</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103315838_row62191578267"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001103315838_p122191578263"><a name="zh-cn_topic_0000001103315838_p122191578263"></a><a name="zh-cn_topic_0000001103315838_p122191578263"></a>weekday</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001103315838_p8219145713262"><a name="zh-cn_topic_0000001103315838_p8219145713262"></a><a name="zh-cn_topic_0000001103315838_p8219145713262"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001103315838_p719114893513"><a name="zh-cn_topic_0000001103315838_p719114893513"></a><a name="zh-cn_topic_0000001103315838_p719114893513"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001103315838_p712345916107"><a name="zh-cn_topic_0000001103315838_p712345916107"></a><a name="zh-cn_topic_0000001103315838_p712345916107"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001103315838_p10220457132611"><a name="zh-cn_topic_0000001103315838_p10220457132611"></a><a name="zh-cn_topic_0000001103315838_p10220457132611"></a>工作日的显示格式，取值范围："long", "short", "narrow"</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103315838_row02045559268"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001103315838_p14205155152614"><a name="zh-cn_topic_0000001103315838_p14205155152614"></a><a name="zh-cn_topic_0000001103315838_p14205155152614"></a>era</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001103315838_p1820525515263"><a name="zh-cn_topic_0000001103315838_p1820525515263"></a><a name="zh-cn_topic_0000001103315838_p1820525515263"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001103315838_p112201486359"><a name="zh-cn_topic_0000001103315838_p112201486359"></a><a name="zh-cn_topic_0000001103315838_p112201486359"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001103315838_p3155195991017"><a name="zh-cn_topic_0000001103315838_p3155195991017"></a><a name="zh-cn_topic_0000001103315838_p3155195991017"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001103315838_p10205255192611"><a name="zh-cn_topic_0000001103315838_p10205255192611"></a><a name="zh-cn_topic_0000001103315838_p10205255192611"></a>时代的显示格式，取值范围："long", "short", "narrow"</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103315838_row3849155211268"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001103315838_p284995232620"><a name="zh-cn_topic_0000001103315838_p284995232620"></a><a name="zh-cn_topic_0000001103315838_p284995232620"></a>year</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001103315838_p10849115213267"><a name="zh-cn_topic_0000001103315838_p10849115213267"></a><a name="zh-cn_topic_0000001103315838_p10849115213267"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001103315838_p182511818353"><a name="zh-cn_topic_0000001103315838_p182511818353"></a><a name="zh-cn_topic_0000001103315838_p182511818353"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001103315838_p20187185951015"><a name="zh-cn_topic_0000001103315838_p20187185951015"></a><a name="zh-cn_topic_0000001103315838_p20187185951015"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001103315838_p15849135232613"><a name="zh-cn_topic_0000001103315838_p15849135232613"></a><a name="zh-cn_topic_0000001103315838_p15849135232613"></a>年份的显示格式，取值范围："numeric", "2-digit"</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103315838_row34024782614"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001103315838_p164034752617"><a name="zh-cn_topic_0000001103315838_p164034752617"></a><a name="zh-cn_topic_0000001103315838_p164034752617"></a>month</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001103315838_p1940947142619"><a name="zh-cn_topic_0000001103315838_p1940947142619"></a><a name="zh-cn_topic_0000001103315838_p1940947142619"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001103315838_p828220873520"><a name="zh-cn_topic_0000001103315838_p828220873520"></a><a name="zh-cn_topic_0000001103315838_p828220873520"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001103315838_p2022014593105"><a name="zh-cn_topic_0000001103315838_p2022014593105"></a><a name="zh-cn_topic_0000001103315838_p2022014593105"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001103315838_p141304632716"><a name="zh-cn_topic_0000001103315838_p141304632716"></a><a name="zh-cn_topic_0000001103315838_p141304632716"></a>月份的显示格式，取值范围："numeric", "2-digit", "long", "short", "narrow"</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103315838_row118165484263"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001103315838_p158165489261"><a name="zh-cn_topic_0000001103315838_p158165489261"></a><a name="zh-cn_topic_0000001103315838_p158165489261"></a>day</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001103315838_p18161948102618"><a name="zh-cn_topic_0000001103315838_p18161948102618"></a><a name="zh-cn_topic_0000001103315838_p18161948102618"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001103315838_p73121981351"><a name="zh-cn_topic_0000001103315838_p73121981351"></a><a name="zh-cn_topic_0000001103315838_p73121981351"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001103315838_p132521859111016"><a name="zh-cn_topic_0000001103315838_p132521859111016"></a><a name="zh-cn_topic_0000001103315838_p132521859111016"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001103315838_p1181619481262"><a name="zh-cn_topic_0000001103315838_p1181619481262"></a><a name="zh-cn_topic_0000001103315838_p1181619481262"></a>日期的显示格式，取值范围："numeric", "2-digit"</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103315838_row7924115012611"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001103315838_p159241050202616"><a name="zh-cn_topic_0000001103315838_p159241050202616"></a><a name="zh-cn_topic_0000001103315838_p159241050202616"></a>hour</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001103315838_p18924195042619"><a name="zh-cn_topic_0000001103315838_p18924195042619"></a><a name="zh-cn_topic_0000001103315838_p18924195042619"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001103315838_p93411811352"><a name="zh-cn_topic_0000001103315838_p93411811352"></a><a name="zh-cn_topic_0000001103315838_p93411811352"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001103315838_p8285165918102"><a name="zh-cn_topic_0000001103315838_p8285165918102"></a><a name="zh-cn_topic_0000001103315838_p8285165918102"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001103315838_p11925185010261"><a name="zh-cn_topic_0000001103315838_p11925185010261"></a><a name="zh-cn_topic_0000001103315838_p11925185010261"></a>小时的显示格式，取值范围："numeric", "2-digit"</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103315838_row1315614310269"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001103315838_p11571431266"><a name="zh-cn_topic_0000001103315838_p11571431266"></a><a name="zh-cn_topic_0000001103315838_p11571431266"></a>minute</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001103315838_p20157443172618"><a name="zh-cn_topic_0000001103315838_p20157443172618"></a><a name="zh-cn_topic_0000001103315838_p20157443172618"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001103315838_p18370168193519"><a name="zh-cn_topic_0000001103315838_p18370168193519"></a><a name="zh-cn_topic_0000001103315838_p18370168193519"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001103315838_p83171059181017"><a name="zh-cn_topic_0000001103315838_p83171059181017"></a><a name="zh-cn_topic_0000001103315838_p83171059181017"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001103315838_p1615714382614"><a name="zh-cn_topic_0000001103315838_p1615714382614"></a><a name="zh-cn_topic_0000001103315838_p1615714382614"></a>分钟的显示格式，取值范围："numeric", "2-digit"</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103315838_row1126474532619"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001103315838_p426414514261"><a name="zh-cn_topic_0000001103315838_p426414514261"></a><a name="zh-cn_topic_0000001103315838_p426414514261"></a>second</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001103315838_p182641245182611"><a name="zh-cn_topic_0000001103315838_p182641245182611"></a><a name="zh-cn_topic_0000001103315838_p182641245182611"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001103315838_p0400489357"><a name="zh-cn_topic_0000001103315838_p0400489357"></a><a name="zh-cn_topic_0000001103315838_p0400489357"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001103315838_p8350125917104"><a name="zh-cn_topic_0000001103315838_p8350125917104"></a><a name="zh-cn_topic_0000001103315838_p8350125917104"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001103315838_p521718134287"><a name="zh-cn_topic_0000001103315838_p521718134287"></a><a name="zh-cn_topic_0000001103315838_p521718134287"></a>秒钟的显示格式，取值范围："numeric", "2-digit"</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103315838_row132981741152616"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001103315838_p1029894117268"><a name="zh-cn_topic_0000001103315838_p1029894117268"></a><a name="zh-cn_topic_0000001103315838_p1029894117268"></a>timeZoneName</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001103315838_p9298174119264"><a name="zh-cn_topic_0000001103315838_p9298174119264"></a><a name="zh-cn_topic_0000001103315838_p9298174119264"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001103315838_p942998103512"><a name="zh-cn_topic_0000001103315838_p942998103512"></a><a name="zh-cn_topic_0000001103315838_p942998103512"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001103315838_p133831591107"><a name="zh-cn_topic_0000001103315838_p133831591107"></a><a name="zh-cn_topic_0000001103315838_p133831591107"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001103315838_p2299104182619"><a name="zh-cn_topic_0000001103315838_p2299104182619"></a><a name="zh-cn_topic_0000001103315838_p2299104182619"></a>时区名称的本地化表示</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103315838_row2912163872615"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001103315838_p19131838162614"><a name="zh-cn_topic_0000001103315838_p19131838162614"></a><a name="zh-cn_topic_0000001103315838_p19131838162614"></a>dayPeriod</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001103315838_p991383832614"><a name="zh-cn_topic_0000001103315838_p991383832614"></a><a name="zh-cn_topic_0000001103315838_p991383832614"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001103315838_p2458980359"><a name="zh-cn_topic_0000001103315838_p2458980359"></a><a name="zh-cn_topic_0000001103315838_p2458980359"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001103315838_p541713599102"><a name="zh-cn_topic_0000001103315838_p541713599102"></a><a name="zh-cn_topic_0000001103315838_p541713599102"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001103315838_p1591343818268"><a name="zh-cn_topic_0000001103315838_p1591343818268"></a><a name="zh-cn_topic_0000001103315838_p1591343818268"></a>时段的显示格式，取值范围："long", "short", "narrow"</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103315838_row1971020367261"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001103315838_p8710193620264"><a name="zh-cn_topic_0000001103315838_p8710193620264"></a><a name="zh-cn_topic_0000001103315838_p8710193620264"></a>localeMatcher</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001103315838_p187102362268"><a name="zh-cn_topic_0000001103315838_p187102362268"></a><a name="zh-cn_topic_0000001103315838_p187102362268"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001103315838_p17487882353"><a name="zh-cn_topic_0000001103315838_p17487882353"></a><a name="zh-cn_topic_0000001103315838_p17487882353"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001103315838_p144995901011"><a name="zh-cn_topic_0000001103315838_p144995901011"></a><a name="zh-cn_topic_0000001103315838_p144995901011"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001103315838_p1071013692610"><a name="zh-cn_topic_0000001103315838_p1071013692610"></a><a name="zh-cn_topic_0000001103315838_p1071013692610"></a>要使用的区域匹配算法，取值范围："lookup", "best fit"</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103315838_row3436123312264"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001103315838_p18437163318262"><a name="zh-cn_topic_0000001103315838_p18437163318262"></a><a name="zh-cn_topic_0000001103315838_p18437163318262"></a>formatMatcher</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001103315838_p443773315263"><a name="zh-cn_topic_0000001103315838_p443773315263"></a><a name="zh-cn_topic_0000001103315838_p443773315263"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001103315838_p185163893515"><a name="zh-cn_topic_0000001103315838_p185163893515"></a><a name="zh-cn_topic_0000001103315838_p185163893515"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001103315838_p1448195961012"><a name="zh-cn_topic_0000001103315838_p1448195961012"></a><a name="zh-cn_topic_0000001103315838_p1448195961012"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001103315838_p043711339264"><a name="zh-cn_topic_0000001103315838_p043711339264"></a><a name="zh-cn_topic_0000001103315838_p043711339264"></a>要使用的格式匹配算法，取值范围："basic", "best fit"</p>
</td>
</tr>
</tbody>
</table>

## NumberOptions<a name="zh-cn_topic_0000001103315838_section7200123494410"></a>

表示设备支持的能力。

### 属性<a name="zh-cn_topic_0000001103315838_section2201153419440"></a>

<a name="zh-cn_topic_0000001103315838_table16201103444414"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001103315838_row620123444415"><th class="cellrowborder" valign="top" width="19.15%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001103315838_p1620163494418"><a name="zh-cn_topic_0000001103315838_p1620163494418"></a><a name="zh-cn_topic_0000001103315838_p1620163494418"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="10.8%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001103315838_p15201434124418"><a name="zh-cn_topic_0000001103315838_p15201434124418"></a><a name="zh-cn_topic_0000001103315838_p15201434124418"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="6.12%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001103315838_p13201123484412"><a name="zh-cn_topic_0000001103315838_p13201123484412"></a><a name="zh-cn_topic_0000001103315838_p13201123484412"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="11.48%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001103315838_p1320123412448"><a name="zh-cn_topic_0000001103315838_p1320123412448"></a><a name="zh-cn_topic_0000001103315838_p1320123412448"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="52.449999999999996%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001103315838_p9201934134419"><a name="zh-cn_topic_0000001103315838_p9201934134419"></a><a name="zh-cn_topic_0000001103315838_p9201934134419"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001103315838_row3201103494415"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001103315838_p20826502499"><a name="zh-cn_topic_0000001103315838_p20826502499"></a><a name="zh-cn_topic_0000001103315838_p20826502499"></a>locale</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001103315838_p120143413448"><a name="zh-cn_topic_0000001103315838_p120143413448"></a><a name="zh-cn_topic_0000001103315838_p120143413448"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001103315838_p18201334114417"><a name="zh-cn_topic_0000001103315838_p18201334114417"></a><a name="zh-cn_topic_0000001103315838_p18201334114417"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001103315838_p420113347441"><a name="zh-cn_topic_0000001103315838_p420113347441"></a><a name="zh-cn_topic_0000001103315838_p420113347441"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001103315838_p8689133923516"><a name="zh-cn_topic_0000001103315838_p8689133923516"></a><a name="zh-cn_topic_0000001103315838_p8689133923516"></a>区域参数</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103315838_row19202113413445"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001103315838_p82028341442"><a name="zh-cn_topic_0000001103315838_p82028341442"></a><a name="zh-cn_topic_0000001103315838_p82028341442"></a>currency</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001103315838_p20653010153513"><a name="zh-cn_topic_0000001103315838_p20653010153513"></a><a name="zh-cn_topic_0000001103315838_p20653010153513"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001103315838_p142021134164413"><a name="zh-cn_topic_0000001103315838_p142021134164413"></a><a name="zh-cn_topic_0000001103315838_p142021134164413"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001103315838_p163525312356"><a name="zh-cn_topic_0000001103315838_p163525312356"></a><a name="zh-cn_topic_0000001103315838_p163525312356"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001103315838_p112021341446"><a name="zh-cn_topic_0000001103315838_p112021341446"></a><a name="zh-cn_topic_0000001103315838_p112021341446"></a>货币单位</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103315838_row181651537153112"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001103315838_p6165137193115"><a name="zh-cn_topic_0000001103315838_p6165137193115"></a><a name="zh-cn_topic_0000001103315838_p6165137193115"></a>currencySign</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001103315838_p26712105353"><a name="zh-cn_topic_0000001103315838_p26712105353"></a><a name="zh-cn_topic_0000001103315838_p26712105353"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001103315838_p20320102716353"><a name="zh-cn_topic_0000001103315838_p20320102716353"></a><a name="zh-cn_topic_0000001103315838_p20320102716353"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001103315838_p53383279356"><a name="zh-cn_topic_0000001103315838_p53383279356"></a><a name="zh-cn_topic_0000001103315838_p53383279356"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001103315838_p416563763115"><a name="zh-cn_topic_0000001103315838_p416563763115"></a><a name="zh-cn_topic_0000001103315838_p416563763115"></a>货币单位的符号显示</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103315838_row02243913313"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001103315838_p922173963114"><a name="zh-cn_topic_0000001103315838_p922173963114"></a><a name="zh-cn_topic_0000001103315838_p922173963114"></a>currencyDisplay</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001103315838_p146881510173515"><a name="zh-cn_topic_0000001103315838_p146881510173515"></a><a name="zh-cn_topic_0000001103315838_p146881510173515"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001103315838_p18355122710359"><a name="zh-cn_topic_0000001103315838_p18355122710359"></a><a name="zh-cn_topic_0000001103315838_p18355122710359"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001103315838_p237211277353"><a name="zh-cn_topic_0000001103315838_p237211277353"></a><a name="zh-cn_topic_0000001103315838_p237211277353"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001103315838_p15225393313"><a name="zh-cn_topic_0000001103315838_p15225393313"></a><a name="zh-cn_topic_0000001103315838_p15225393313"></a>货币的显示方式，取值范围："symbol", "narrowSymbol", "code", "name"</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103315838_row04912413319"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001103315838_p349204110313"><a name="zh-cn_topic_0000001103315838_p349204110313"></a><a name="zh-cn_topic_0000001103315838_p349204110313"></a>unit</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001103315838_p4705161018358"><a name="zh-cn_topic_0000001103315838_p4705161018358"></a><a name="zh-cn_topic_0000001103315838_p4705161018358"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001103315838_p938862743518"><a name="zh-cn_topic_0000001103315838_p938862743518"></a><a name="zh-cn_topic_0000001103315838_p938862743518"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001103315838_p440462743518"><a name="zh-cn_topic_0000001103315838_p440462743518"></a><a name="zh-cn_topic_0000001103315838_p440462743518"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001103315838_p2499410317"><a name="zh-cn_topic_0000001103315838_p2499410317"></a><a name="zh-cn_topic_0000001103315838_p2499410317"></a>单位</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103315838_row17758199133220"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001103315838_p13758129103211"><a name="zh-cn_topic_0000001103315838_p13758129103211"></a><a name="zh-cn_topic_0000001103315838_p13758129103211"></a>unitDisplay</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001103315838_p1772013101356"><a name="zh-cn_topic_0000001103315838_p1772013101356"></a><a name="zh-cn_topic_0000001103315838_p1772013101356"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001103315838_p1342018270359"><a name="zh-cn_topic_0000001103315838_p1342018270359"></a><a name="zh-cn_topic_0000001103315838_p1342018270359"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001103315838_p184363276352"><a name="zh-cn_topic_0000001103315838_p184363276352"></a><a name="zh-cn_topic_0000001103315838_p184363276352"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001103315838_p8758119193219"><a name="zh-cn_topic_0000001103315838_p8758119193219"></a><a name="zh-cn_topic_0000001103315838_p8758119193219"></a>单位的显示格式，取值范围："long", "short", "medium"</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103315838_row1244996173217"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001103315838_p845017623210"><a name="zh-cn_topic_0000001103315838_p845017623210"></a><a name="zh-cn_topic_0000001103315838_p845017623210"></a>signDisplay</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001103315838_p1373617108355"><a name="zh-cn_topic_0000001103315838_p1373617108355"></a><a name="zh-cn_topic_0000001103315838_p1373617108355"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001103315838_p545216279357"><a name="zh-cn_topic_0000001103315838_p545216279357"></a><a name="zh-cn_topic_0000001103315838_p545216279357"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001103315838_p746817276358"><a name="zh-cn_topic_0000001103315838_p746817276358"></a><a name="zh-cn_topic_0000001103315838_p746817276358"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001103315838_p154508613320"><a name="zh-cn_topic_0000001103315838_p154508613320"></a><a name="zh-cn_topic_0000001103315838_p154508613320"></a>数字符号的显示格式，取值范围："auto", "never", "always", "expectZero"</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103315838_row119376594318"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001103315838_p2093765973119"><a name="zh-cn_topic_0000001103315838_p2093765973119"></a><a name="zh-cn_topic_0000001103315838_p2093765973119"></a>compactDisplay</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001103315838_p1375319107353"><a name="zh-cn_topic_0000001103315838_p1375319107353"></a><a name="zh-cn_topic_0000001103315838_p1375319107353"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001103315838_p19485202719353"><a name="zh-cn_topic_0000001103315838_p19485202719353"></a><a name="zh-cn_topic_0000001103315838_p19485202719353"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001103315838_p35017277357"><a name="zh-cn_topic_0000001103315838_p35017277357"></a><a name="zh-cn_topic_0000001103315838_p35017277357"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001103315838_p4938135915318"><a name="zh-cn_topic_0000001103315838_p4938135915318"></a><a name="zh-cn_topic_0000001103315838_p4938135915318"></a>紧凑型的显示格式，取值范围："long", "short"</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103315838_row149571783218"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001103315838_p1095712718329"><a name="zh-cn_topic_0000001103315838_p1095712718329"></a><a name="zh-cn_topic_0000001103315838_p1095712718329"></a>notation</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001103315838_p137691110193512"><a name="zh-cn_topic_0000001103315838_p137691110193512"></a><a name="zh-cn_topic_0000001103315838_p137691110193512"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001103315838_p351792714359"><a name="zh-cn_topic_0000001103315838_p351792714359"></a><a name="zh-cn_topic_0000001103315838_p351792714359"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001103315838_p12533152715355"><a name="zh-cn_topic_0000001103315838_p12533152715355"></a><a name="zh-cn_topic_0000001103315838_p12533152715355"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001103315838_p1095817719324"><a name="zh-cn_topic_0000001103315838_p1095817719324"></a><a name="zh-cn_topic_0000001103315838_p1095817719324"></a>数字的格式化规格，取值范围："standard", "scientific", "engineering", "compact"</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103315838_row651913243210"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001103315838_p1851916215327"><a name="zh-cn_topic_0000001103315838_p1851916215327"></a><a name="zh-cn_topic_0000001103315838_p1851916215327"></a>localeMatcher</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001103315838_p278511013358"><a name="zh-cn_topic_0000001103315838_p278511013358"></a><a name="zh-cn_topic_0000001103315838_p278511013358"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001103315838_p13551122714352"><a name="zh-cn_topic_0000001103315838_p13551122714352"></a><a name="zh-cn_topic_0000001103315838_p13551122714352"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001103315838_p8567027123516"><a name="zh-cn_topic_0000001103315838_p8567027123516"></a><a name="zh-cn_topic_0000001103315838_p8567027123516"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001103315838_p135202213324"><a name="zh-cn_topic_0000001103315838_p135202213324"></a><a name="zh-cn_topic_0000001103315838_p135202213324"></a>要使用的区域匹配算法，取值范围："lookup", "best fit"</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103315838_row6142417329"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001103315838_p9141247329"><a name="zh-cn_topic_0000001103315838_p9141247329"></a><a name="zh-cn_topic_0000001103315838_p9141247329"></a>style</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001103315838_p580151013516"><a name="zh-cn_topic_0000001103315838_p580151013516"></a><a name="zh-cn_topic_0000001103315838_p580151013516"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001103315838_p8584427163520"><a name="zh-cn_topic_0000001103315838_p8584427163520"></a><a name="zh-cn_topic_0000001103315838_p8584427163520"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001103315838_p12601427193516"><a name="zh-cn_topic_0000001103315838_p12601427193516"></a><a name="zh-cn_topic_0000001103315838_p12601427193516"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001103315838_p0147411321"><a name="zh-cn_topic_0000001103315838_p0147411321"></a><a name="zh-cn_topic_0000001103315838_p0147411321"></a>数字的显示格式，取值范围："decimal", "currency", "percent", "unit"</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103315838_row10690651163120"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001103315838_p206901951193115"><a name="zh-cn_topic_0000001103315838_p206901951193115"></a><a name="zh-cn_topic_0000001103315838_p206901951193115"></a>numberingSystem</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001103315838_p18179104357"><a name="zh-cn_topic_0000001103315838_p18179104357"></a><a name="zh-cn_topic_0000001103315838_p18179104357"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001103315838_p106179271351"><a name="zh-cn_topic_0000001103315838_p106179271351"></a><a name="zh-cn_topic_0000001103315838_p106179271351"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001103315838_p96342278351"><a name="zh-cn_topic_0000001103315838_p96342278351"></a><a name="zh-cn_topic_0000001103315838_p96342278351"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001103315838_p669010518311"><a name="zh-cn_topic_0000001103315838_p669010518311"></a><a name="zh-cn_topic_0000001103315838_p669010518311"></a>数字系统</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103315838_row1539618585317"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001103315838_p93961258123112"><a name="zh-cn_topic_0000001103315838_p93961258123112"></a><a name="zh-cn_topic_0000001103315838_p93961258123112"></a>useGrouping</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001103315838_p9396358133113"><a name="zh-cn_topic_0000001103315838_p9396358133113"></a><a name="zh-cn_topic_0000001103315838_p9396358133113"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001103315838_p1650202763514"><a name="zh-cn_topic_0000001103315838_p1650202763514"></a><a name="zh-cn_topic_0000001103315838_p1650202763514"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001103315838_p1667152753514"><a name="zh-cn_topic_0000001103315838_p1667152753514"></a><a name="zh-cn_topic_0000001103315838_p1667152753514"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001103315838_p1639665815311"><a name="zh-cn_topic_0000001103315838_p1639665815311"></a><a name="zh-cn_topic_0000001103315838_p1639665815311"></a>是否分组显示</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103315838_row072885623114"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001103315838_p972925613314"><a name="zh-cn_topic_0000001103315838_p972925613314"></a><a name="zh-cn_topic_0000001103315838_p972925613314"></a>miniumumIntegerDigits</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001103315838_p1772915560312"><a name="zh-cn_topic_0000001103315838_p1772915560312"></a><a name="zh-cn_topic_0000001103315838_p1772915560312"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001103315838_p16831027113518"><a name="zh-cn_topic_0000001103315838_p16831027113518"></a><a name="zh-cn_topic_0000001103315838_p16831027113518"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001103315838_p370042710357"><a name="zh-cn_topic_0000001103315838_p370042710357"></a><a name="zh-cn_topic_0000001103315838_p370042710357"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001103315838_p372995623120"><a name="zh-cn_topic_0000001103315838_p372995623120"></a><a name="zh-cn_topic_0000001103315838_p372995623120"></a>最少整数个数</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103315838_row16189155013112"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001103315838_p1318945073110"><a name="zh-cn_topic_0000001103315838_p1318945073110"></a><a name="zh-cn_topic_0000001103315838_p1318945073110"></a>miniumumFractionDigits</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001103315838_p18773192153515"><a name="zh-cn_topic_0000001103315838_p18773192153515"></a><a name="zh-cn_topic_0000001103315838_p18773192153515"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001103315838_p871602718354"><a name="zh-cn_topic_0000001103315838_p871602718354"></a><a name="zh-cn_topic_0000001103315838_p871602718354"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001103315838_p1273214274357"><a name="zh-cn_topic_0000001103315838_p1273214274357"></a><a name="zh-cn_topic_0000001103315838_p1273214274357"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001103315838_p19189195053112"><a name="zh-cn_topic_0000001103315838_p19189195053112"></a><a name="zh-cn_topic_0000001103315838_p19189195053112"></a>最少小数个数</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103315838_row666184819318"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001103315838_p1066194810314"><a name="zh-cn_topic_0000001103315838_p1066194810314"></a><a name="zh-cn_topic_0000001103315838_p1066194810314"></a>maxiumumFractionDigits</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001103315838_p9790152114352"><a name="zh-cn_topic_0000001103315838_p9790152114352"></a><a name="zh-cn_topic_0000001103315838_p9790152114352"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001103315838_p2748427163512"><a name="zh-cn_topic_0000001103315838_p2748427163512"></a><a name="zh-cn_topic_0000001103315838_p2748427163512"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001103315838_p476412763517"><a name="zh-cn_topic_0000001103315838_p476412763517"></a><a name="zh-cn_topic_0000001103315838_p476412763517"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001103315838_p1866154811315"><a name="zh-cn_topic_0000001103315838_p1866154811315"></a><a name="zh-cn_topic_0000001103315838_p1866154811315"></a>最多小数个数</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103315838_row18191543113111"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001103315838_p7191134310318"><a name="zh-cn_topic_0000001103315838_p7191134310318"></a><a name="zh-cn_topic_0000001103315838_p7191134310318"></a>miniumumSignificantDigits</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001103315838_p68061821193514"><a name="zh-cn_topic_0000001103315838_p68061821193514"></a><a name="zh-cn_topic_0000001103315838_p68061821193514"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001103315838_p7780182718358"><a name="zh-cn_topic_0000001103315838_p7780182718358"></a><a name="zh-cn_topic_0000001103315838_p7780182718358"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001103315838_p479622793511"><a name="zh-cn_topic_0000001103315838_p479622793511"></a><a name="zh-cn_topic_0000001103315838_p479622793511"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001103315838_p81919438317"><a name="zh-cn_topic_0000001103315838_p81919438317"></a><a name="zh-cn_topic_0000001103315838_p81919438317"></a>最少有效位个数</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103315838_row1514134520316"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001103315838_p5141045153119"><a name="zh-cn_topic_0000001103315838_p5141045153119"></a><a name="zh-cn_topic_0000001103315838_p5141045153119"></a>maxiumumSignificantDigits</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001103315838_p16822182103515"><a name="zh-cn_topic_0000001103315838_p16822182103515"></a><a name="zh-cn_topic_0000001103315838_p16822182103515"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001103315838_p1081342717358"><a name="zh-cn_topic_0000001103315838_p1081342717358"></a><a name="zh-cn_topic_0000001103315838_p1081342717358"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001103315838_p382912713352"><a name="zh-cn_topic_0000001103315838_p382912713352"></a><a name="zh-cn_topic_0000001103315838_p382912713352"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001103315838_p11418457317"><a name="zh-cn_topic_0000001103315838_p11418457317"></a><a name="zh-cn_topic_0000001103315838_p11418457317"></a>最多有效位个数</p>
</td>
</tr>
</tbody>
</table>

