# 设置系统时间<a name="ZH-CN_TOPIC_0000001173920874"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从 API Version 7 开始支持。

## 支持设备<a name="section16881239114912"></a>

<a name="table857714145377"></a>
<table><thead align="left"><tr id="row55778146373"><th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.1"><p id="p7577141417376"><a name="p7577141417376"></a><a name="p7577141417376"></a>手机</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.2"><p id="p487719816463"><a name="p487719816463"></a><a name="p487719816463"></a>平板</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.3"><p id="p135771614203720"><a name="p135771614203720"></a><a name="p135771614203720"></a>智慧屏</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.4"><p id="p25772014133712"><a name="p25772014133712"></a><a name="p25772014133712"></a>智能穿戴</p>
</th>
</tr>
</thead>
<tbody><tr id="row8578151423715"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p65782014203718"><a name="p65782014203718"></a><a name="p65782014203718"></a>支持</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p148771182469"><a name="p148771182469"></a><a name="p148771182469"></a>支持</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="p45783141377"><a name="p45783141377"></a><a name="p45783141377"></a>支持</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="p11578161443718"><a name="p11578161443718"></a><a name="p11578161443718"></a>支持</p>
</td>
</tr>
</tbody>
</table>

## 导入模块<a name="s56d19203690d4782bfc74069abb6bd71"></a>

```
import systemTime from '@ohos.systemTime';
```

## systemTime.setTime<a name="section982814256"></a>

setTime\(time : number, callback : AsyncCallback<void\>\) : void

设置系统时间，需要ohos.permission.SET\_TIME权限。

-   参数：

    <a name="table69661135912"></a>
    <table><thead align="left"><tr id="row149668318915"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p7966738914"><a name="p7966738914"></a><a name="p7966738914"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="28.110000000000003%" id="mcps1.1.5.1.2"><p id="p296713699"><a name="p296713699"></a><a name="p296713699"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.31%" id="mcps1.1.5.1.3"><p id="p196718315911"><a name="p196718315911"></a><a name="p196718315911"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="46.760000000000005%" id="mcps1.1.5.1.4"><p id="p9967231197"><a name="p9967231197"></a><a name="p9967231197"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row99671533914"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p970454863617"><a name="p970454863617"></a><a name="p970454863617"></a>time</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.110000000000003%" headers="mcps1.1.5.1.2 "><p id="p638105118361"><a name="p638105118361"></a><a name="p638105118361"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.31%" headers="mcps1.1.5.1.3 "><p id="p10368918379"><a name="p10368918379"></a><a name="p10368918379"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.760000000000005%" headers="mcps1.1.5.1.4 "><p id="p1824111117261"><a name="p1824111117261"></a><a name="p1824111117261"></a>目标时间戳（毫秒）。</p>
    </td>
    </tr>
    <tr id="row18967831393"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p23472045113613"><a name="p23472045113613"></a><a name="p23472045113613"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.110000000000003%" headers="mcps1.1.5.1.2 "><p id="p228635433615"><a name="p228635433615"></a><a name="p228635433615"></a>AsyncCallback&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.31%" headers="mcps1.1.5.1.3 "><p id="p149671932919"><a name="p149671932919"></a><a name="p149671932919"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.760000000000005%" headers="mcps1.1.5.1.4 "><p id="p19675312911"><a name="p19675312911"></a><a name="p19675312911"></a>回调函数，可以在回调函数中处理接口返回值。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    // time对应的时间为2021-01-20 02:36:25
    var time = 1611081385000;
    systemTime.setTime(time, (error, data) => {
        if (error) {
            console.error(`failed to systemTime.setTime because ` + JSON.stringify(error));
            return;
        }
        console.log(`success to systemTime.setTime: ` + JSON.stringify(data));
    });
    ```


## systemTime.setTime<a name="section31619318454"></a>

setTime\(time : number\) : Promise<void\>

设置系统时间，需要ohos.permission.SET\_TIME权限。

-   参数：

    <a name="table26921924204918"></a>
    <table><thead align="left"><tr id="row19692102424918"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p9692224194911"><a name="p9692224194911"></a><a name="p9692224194911"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p1769214247491"><a name="p1769214247491"></a><a name="p1769214247491"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p46927245491"><a name="p46927245491"></a><a name="p46927245491"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p6692324174910"><a name="p6692324174910"></a><a name="p6692324174910"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row4692192484915"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p0689153917498"><a name="p0689153917498"></a><a name="p0689153917498"></a>time</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p08115441499"><a name="p08115441499"></a><a name="p08115441499"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p19671336916"><a name="p19671336916"></a><a name="p19671336916"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p26461059194919"><a name="p26461059194919"></a><a name="p26461059194919"></a>目标时间戳（毫秒）。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   返回值：

    <a name="table16391145317913"></a>
    <table><thead align="left"><tr id="row2391145319910"><th class="cellrowborder" valign="top" width="20.45%" id="mcps1.1.3.1.1"><p id="p13911353991"><a name="p13911353991"></a><a name="p13911353991"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.55%" id="mcps1.1.3.1.2"><p id="p193911531395"><a name="p193911531395"></a><a name="p193911531395"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1339114531391"><td class="cellrowborder" valign="top" width="20.45%" headers="mcps1.1.3.1.1 "><p id="p128951812478"><a name="p128951812478"></a><a name="p128951812478"></a>Promise&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.55%" headers="mcps1.1.3.1.2 "><p id="p863645294616"><a name="p863645294616"></a><a name="p863645294616"></a>返回的异步回调函数。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    // time对应的时间为2021-01-20 02:36:25
    var time = 1611081385000;
    systemTime.setTime(time).then((data) => {
        console.log(`success to systemTime.setTime: ` + JSON.stringify(data));
    }).catch((error) => {
        console.error(`failed to systemTime.setTime because ` + JSON.stringify(error));
    });
    ```


## systemTime.setDate<a name="section2771164881119"></a>

setDate\(date: Date, callback: AsyncCallback<void\>\): void

设置系统日期，需要ohos.permission.SET\_TIME权限。

-   参数：

    <a name="table1681904211503"></a>
    <table><thead align="left"><tr id="row3819154212503"><th class="cellrowborder" valign="top" width="14.46841745582349%" id="mcps1.1.5.1.1"><p id="p1082034265013"><a name="p1082034265013"></a><a name="p1082034265013"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="25.9982427023333%" id="mcps1.1.5.1.2"><p id="p9820242105016"><a name="p9820242105016"></a><a name="p9820242105016"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.301083666894465%" id="mcps1.1.5.1.3"><p id="p682018424506"><a name="p682018424506"></a><a name="p682018424506"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="47.232256174948745%" id="mcps1.1.5.1.4"><p id="p178200429507"><a name="p178200429507"></a><a name="p178200429507"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row12820742105011"><td class="cellrowborder" valign="top" width="14.46841745582349%" headers="mcps1.1.5.1.1 "><p id="p79671633910"><a name="p79671633910"></a><a name="p79671633910"></a>date</p>
    </td>
    <td class="cellrowborder" valign="top" width="25.9982427023333%" headers="mcps1.1.5.1.2 "><p id="p11967433914"><a name="p11967433914"></a><a name="p11967433914"></a>Date</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.301083666894465%" headers="mcps1.1.5.1.3 "><p id="p1162123785218"><a name="p1162123785218"></a><a name="p1162123785218"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="47.232256174948745%" headers="mcps1.1.5.1.4 "><p id="p69671631796"><a name="p69671631796"></a><a name="p69671631796"></a>目标日期。</p>
    </td>
    </tr>
    <tr id="row482024265019"><td class="cellrowborder" valign="top" width="14.46841745582349%" headers="mcps1.1.5.1.1 "><p id="p39671131590"><a name="p39671131590"></a><a name="p39671131590"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="25.9982427023333%" headers="mcps1.1.5.1.2 "><p id="p126051952172518"><a name="p126051952172518"></a><a name="p126051952172518"></a>AsyncCallback&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.301083666894465%" headers="mcps1.1.5.1.3 "><p id="p1882214210506"><a name="p1882214210506"></a><a name="p1882214210506"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="47.232256174948745%" headers="mcps1.1.5.1.4 "><p id="p1822104212508"><a name="p1822104212508"></a><a name="p1822104212508"></a>回调函数，可以在回调函数中处理接口返回值。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    var data = new Date("October 13, 2020 11:13:00");
    systemTime.setDate(data,(error, data) => {       
        if (error) {            
        console.error('SystemTimePlugin setDate failed because ' + JSON.stringify(error));           
        return;       
    }        
        console.info('SystemTimePlugin setDate success data : ' + JSON.stringify(data));    
    });
    ```


## systemTime.setDate<a name="section596619465012"></a>

setDate\(date: Date\): Promise<void\>

设置系统日期，需要ohos.permission.SET\_TIME权限。

-   参数：

    <a name="table3305192618117"></a>
    <table><thead align="left"><tr id="row33061262012"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p1230611261715"><a name="p1230611261715"></a><a name="p1230611261715"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p430652616111"><a name="p430652616111"></a><a name="p430652616111"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p0306112616110"><a name="p0306112616110"></a><a name="p0306112616110"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p930614264120"><a name="p930614264120"></a><a name="p930614264120"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row63069263118"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p7306226219"><a name="p7306226219"></a><a name="p7306226219"></a>date</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p430615264118"><a name="p430615264118"></a><a name="p430615264118"></a>Date</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p592475219117"><a name="p592475219117"></a><a name="p592475219117"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p830610266114"><a name="p830610266114"></a><a name="p830610266114"></a>目标日期。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="table03077266115"></a>
    <table><thead align="left"><tr id="row163079261911"><th class="cellrowborder" valign="top" width="22.03%" id="mcps1.1.3.1.1"><p id="p63077261313"><a name="p63077261313"></a><a name="p63077261313"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="77.97%" id="mcps1.1.3.1.2"><p id="p153071826219"><a name="p153071826219"></a><a name="p153071826219"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row130714268115"><td class="cellrowborder" valign="top" width="22.03%" headers="mcps1.1.3.1.1 "><p id="p73929531797"><a name="p73929531797"></a><a name="p73929531797"></a>Promise&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.97%" headers="mcps1.1.3.1.2 "><p id="p1699815101432"><a name="p1699815101432"></a><a name="p1699815101432"></a>返回的异步回调函数。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    var data = new Date("October 13, 2020 11:13:00"); 
    systemTime.setDate(data).then((value) => {        
        console.log(`SystemTimePlugin success to systemTime.setDate: ` + JSON.stringify(value));    
    }).catch((error) => {        
        console.error(`SystemTimePlugin failed to systemTime.setDate because: ` + JSON.stringify(error));
    });
    ```


## systemTime.setTimezone<a name="section1412025610420"></a>

setTimezone\(timezone: string, callback: AsyncCallback<void\>\): void

设置系统时区，需要ohos.permission.SET\_TIME\_ZONE权限。

-   参数：

    <a name="table1176953158"></a>
    <table><thead align="left"><tr id="row8176165312517"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p141768531055"><a name="p141768531055"></a><a name="p141768531055"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="28.48%" id="mcps1.1.5.1.2"><p id="p01761953355"><a name="p01761953355"></a><a name="p01761953355"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.35%" id="mcps1.1.5.1.3"><p id="p31763533511"><a name="p31763533511"></a><a name="p31763533511"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="44.35%" id="mcps1.1.5.1.4"><p id="p171763531510"><a name="p171763531510"></a><a name="p171763531510"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row191761753752"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1906202016614"><a name="p1906202016614"></a><a name="p1906202016614"></a>timezone</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.48%" headers="mcps1.1.5.1.2 "><p id="p17176145315519"><a name="p17176145315519"></a><a name="p17176145315519"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.35%" headers="mcps1.1.5.1.3 "><p id="p141772531456"><a name="p141772531456"></a><a name="p141772531456"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="44.35%" headers="mcps1.1.5.1.4 "><p id="p81778538510"><a name="p81778538510"></a><a name="p81778538510"></a>系统时区。</p>
    </td>
    </tr>
    <tr id="row5706122620610"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p47071326467"><a name="p47071326467"></a><a name="p47071326467"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.48%" headers="mcps1.1.5.1.2 "><p id="p1870710261061"><a name="p1870710261061"></a><a name="p1870710261061"></a>AsyncCallback&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.35%" headers="mcps1.1.5.1.3 "><p id="p197072262618"><a name="p197072262618"></a><a name="p197072262618"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="44.35%" headers="mcps1.1.5.1.4 "><p id="p1670792610618"><a name="p1670792610618"></a><a name="p1670792610618"></a>回调函数，可以在回调函数中处理接口返回值。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    systemTime.setTimezone('Asia/Shanghai', (error, data) => {       
        if (error) {          
            console.error('SystemTimePlugin setTimezone failed because ' + JSON.stringify(error));          
            return;       
        }       
        console.info('SystemTimePlugin setTimezone success data : ' + JSON.stringify(data)); 
    });
    ```


## systemTime.setTimezone<a name="section8580990917"></a>

setTimezone\(timezone: string\): Promise<void\>

设置系统时区，需要ohos.permission.SET\_TIME\_ZONE权限。

-   参数：

    <a name="table9229203416911"></a>
    <table><thead align="left"><tr id="row42307349918"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p142309343913"><a name="p142309343913"></a><a name="p142309343913"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p142307348918"><a name="p142307348918"></a><a name="p142307348918"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p623003414912"><a name="p623003414912"></a><a name="p623003414912"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p62301342917"><a name="p62301342917"></a><a name="p62301342917"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row92301342914"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p192303349914"><a name="p192303349914"></a><a name="p192303349914"></a>timezone</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p172305341790"><a name="p172305341790"></a><a name="p172305341790"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p178271541012"><a name="p178271541012"></a><a name="p178271541012"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p11915237106"><a name="p11915237106"></a><a name="p11915237106"></a>系统时区。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="table182311434691"></a>
    <table><thead align="left"><tr id="row1123118341890"><th class="cellrowborder" valign="top" width="23.05%" id="mcps1.1.3.1.1"><p id="p1523213413910"><a name="p1523213413910"></a><a name="p1523213413910"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="76.95%" id="mcps1.1.3.1.2"><p id="p1523243415918"><a name="p1523243415918"></a><a name="p1523243415918"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row73921953298"><td class="cellrowborder" valign="top" width="23.05%" headers="mcps1.1.3.1.1 "><p id="p15305153761717"><a name="p15305153761717"></a><a name="p15305153761717"></a>Promise&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="76.95%" headers="mcps1.1.3.1.2 "><p id="p780206191118"><a name="p780206191118"></a><a name="p780206191118"></a>返回的异步回调函数。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    systemTime.setTimezone('Asia/Shanghai').then((data) => {        
        console.log(`SystemTimePlugin success to systemTime.setTimezone: ` + JSON.stringify(data));     
    }).catch((error) => {        
        console.error(`SystemTimePlugin failed to systemTime.setTimezone because: ` + JSON.stringify(error));    
    });
    ```


