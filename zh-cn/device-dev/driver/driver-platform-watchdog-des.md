# WATCHDOG<a name="ZH-CN_TOPIC_0000001206372825"></a>

-   [概述](#section14918241977)
-   [接口说明](#section1180575010271)
-   [使用指导](#section10103184312813)
    -   [使用流程](#section10181195910815)
    -   [打开看门狗设备](#section66089201107)
    -   [获取看门狗状态](#section786624341011)
    -   [设置超时时间](#section182386137111)
    -   [获取超时时间](#section1883310371114)
    -   [启动看门狗](#section82501405123)
    -   [喂狗](#section3547530101211)
    -   [停止看门狗](#section944595841217)
    -   [关闭看门狗设备](#section96561824121311)

-   [使用实例](#section1724514523135)

## 概述<a name="section14918241977"></a>

看门狗（watchdog），又叫看门狗计时器（watchdog timer），是一种硬件的计时设备，当系统的主程序发生某些错误时，导致未及时清除看门狗计时器的计时值，这时看门狗计时器就会对系统发出复位信号，使系统从悬停状态恢复到正常运作状态。

## 接口说明<a name="section1180575010271"></a>

**表 1**  看门狗 API接口功能介绍

<a name="table1731550155318"></a>
<table><thead align="left"><tr id="row4419501537"><th class="cellrowborder" valign="top" width="26.619999999999997%" id="mcps1.2.4.1.1"><p id="p641050105320"><a name="p641050105320"></a><a name="p641050105320"></a>功能分类</p>
</th>
<th class="cellrowborder" valign="top" width="32.800000000000004%" id="mcps1.2.4.1.2"><p id="p54150165315"><a name="p54150165315"></a><a name="p54150165315"></a>接口名</p>
</th>
<th class="cellrowborder" valign="top" width="40.58%" id="mcps1.2.4.1.3"><p id="p941150145313"><a name="p941150145313"></a><a name="p941150145313"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row837081981712"><td class="cellrowborder" rowspan="2" valign="top" width="26.619999999999997%" headers="mcps1.2.4.1.1 "><p id="p681292481718"><a name="p681292481718"></a><a name="p681292481718"></a>打开/关闭看门狗</p>
</td>
<td class="cellrowborder" valign="top" width="32.800000000000004%" headers="mcps1.2.4.1.2 "><p id="p183701419141710"><a name="p183701419141710"></a><a name="p183701419141710"></a>WatchdogOpen</p>
</td>
<td class="cellrowborder" valign="top" width="40.58%" headers="mcps1.2.4.1.3 "><p id="p17370161911710"><a name="p17370161911710"></a><a name="p17370161911710"></a>打开看门狗设备</p>
</td>
</tr>
<tr id="row5610415171719"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p661171510173"><a name="p661171510173"></a><a name="p661171510173"></a>WatchdogClose</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p11611715161713"><a name="p11611715161713"></a><a name="p11611715161713"></a>关闭看门狗设备</p>
</td>
</tr>
<tr id="row337105133315"><td class="cellrowborder" rowspan="2" valign="top" width="26.619999999999997%" headers="mcps1.2.4.1.1 "><p id="p07631557153319"><a name="p07631557153319"></a><a name="p07631557153319"></a>启动/停止看门狗</p>
</td>
<td class="cellrowborder" valign="top" width="32.800000000000004%" headers="mcps1.2.4.1.2 "><p id="p163765113337"><a name="p163765113337"></a><a name="p163765113337"></a>WatchdogStart</p>
</td>
<td class="cellrowborder" valign="top" width="40.58%" headers="mcps1.2.4.1.3 "><p id="p18376517332"><a name="p18376517332"></a><a name="p18376517332"></a>启动看门狗</p>
</td>
</tr>
<tr id="row18399184610337"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1740010461335"><a name="p1740010461335"></a><a name="p1740010461335"></a>WatchdogStop</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p19400194633318"><a name="p19400194633318"></a><a name="p19400194633318"></a>停止看门狗</p>
</td>
</tr>
<tr id="row34145016535"><td class="cellrowborder" rowspan="2" valign="top" width="26.619999999999997%" headers="mcps1.2.4.1.1 "><p id="p229610227124"><a name="p229610227124"></a><a name="p229610227124"></a>设置/获取超时时间</p>
</td>
<td class="cellrowborder" valign="top" width="32.800000000000004%" headers="mcps1.2.4.1.2 "><p id="p8296182221219"><a name="p8296182221219"></a><a name="p8296182221219"></a>WatchdogSetTimeout</p>
</td>
<td class="cellrowborder" valign="top" width="40.58%" headers="mcps1.2.4.1.3 "><p id="p16297172213125"><a name="p16297172213125"></a><a name="p16297172213125"></a>设置看门狗超时时间</p>
</td>
</tr>
<tr id="row11585016539"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1095722493616"><a name="p1095722493616"></a><a name="p1095722493616"></a>WatchdogGetTimeout</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p15297162215122"><a name="p15297162215122"></a><a name="p15297162215122"></a>获取看门狗超时时间</p>
</td>
</tr>
<tr id="row105701653185811"><td class="cellrowborder" valign="top" width="26.619999999999997%" headers="mcps1.2.4.1.1 "><p id="p2571145325819"><a name="p2571145325819"></a><a name="p2571145325819"></a>获取看门狗状态</p>
</td>
<td class="cellrowborder" valign="top" width="32.800000000000004%" headers="mcps1.2.4.1.2 "><p id="p175711953195814"><a name="p175711953195814"></a><a name="p175711953195814"></a>WatchdogGetStatus</p>
</td>
<td class="cellrowborder" valign="top" width="40.58%" headers="mcps1.2.4.1.3 "><p id="p331961319210"><a name="p331961319210"></a><a name="p331961319210"></a>获取看门狗状态</p>
</td>
</tr>
<tr id="row1028182217215"><td class="cellrowborder" valign="top" width="26.619999999999997%" headers="mcps1.2.4.1.1 "><p id="p182818227214"><a name="p182818227214"></a><a name="p182818227214"></a>清除看门狗定时器</p>
</td>
<td class="cellrowborder" valign="top" width="32.800000000000004%" headers="mcps1.2.4.1.2 "><p id="p17281223219"><a name="p17281223219"></a><a name="p17281223219"></a>WatchdogFeed</p>
</td>
<td class="cellrowborder" valign="top" width="40.58%" headers="mcps1.2.4.1.3 "><p id="p62815221125"><a name="p62815221125"></a><a name="p62815221125"></a>清除看门狗定时器(喂狗)</p>
</td>
</tr>
</tbody>
</table>

>![](../public_sys-resources/icon-note.gif) **说明：** 
>本文涉及看门狗的所有接口，仅限内核态使用，不支持在用户态使用。

## 使用指导<a name="section10103184312813"></a>

### 使用流程<a name="section10181195910815"></a>

使用看门狗的一般流程如[图1](#fig430533913392)所示。

**图 1**  看门狗使用流程图<a name="fig430533913392"></a>  
![](figures/看门狗使用流程图.png "看门狗使用流程图")

### 打开看门狗设备<a name="section66089201107"></a>

在操作看门狗之前，需要使用WatchdogOpen打开一个看门狗设备，一个系统可能有多个看门狗，通过ID号来打开指定的看门狗设备：

DevHandle WatchdogOpen\(int16\_t wdtId\);

**表 2**  WatchdogOpen参数和返回值描述

<a name="table1413702552814"></a>
<table><thead align="left"><tr id="row131371325142819"><th class="cellrowborder" valign="top" width="44.99%" id="mcps1.2.3.1.1"><p id="p191372254283"><a name="p191372254283"></a><a name="p191372254283"></a><strong id="b1913716253285"><a name="b1913716253285"></a><a name="b1913716253285"></a>参数</strong></p>
</th>
<th class="cellrowborder" valign="top" width="55.010000000000005%" id="mcps1.2.3.1.2"><p id="p113819255284"><a name="p113819255284"></a><a name="p113819255284"></a><strong id="b151381725172812"><a name="b151381725172812"></a><a name="b151381725172812"></a>参数描述</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row813812259282"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p101381625162813"><a name="p101381625162813"></a><a name="p101381625162813"></a>wdtId</p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p191381425142813"><a name="p191381425142813"></a><a name="p191381425142813"></a>看门狗设备号</p>
</td>
</tr>
<tr id="row2138202515281"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p141387252287"><a name="p141387252287"></a><a name="p141387252287"></a><strong id="b11381325172810"><a name="b11381325172810"></a><a name="b11381325172810"></a>返回值</strong></p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p12138192512281"><a name="p12138192512281"></a><a name="p12138192512281"></a><strong id="b81380254286"><a name="b81380254286"></a><a name="b81380254286"></a>返回值描述</strong></p>
</td>
</tr>
<tr id="row9138182519287"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p5138102532814"><a name="p5138102532814"></a><a name="p5138102532814"></a>NULL</p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p3138192512815"><a name="p3138192512815"></a><a name="p3138192512815"></a>打开失败</p>
</td>
</tr>
<tr id="row15138192518283"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p1850115512916"><a name="p1850115512916"></a><a name="p1850115512916"></a>DevHandle类型指针</p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p16138122512817"><a name="p16138122512817"></a><a name="p16138122512817"></a>看门狗设备句柄</p>
</td>
</tr>
</tbody>
</table>

```
DevHandle handle = NULL;
handle = WatchdogOpen(0);  /* 打开0号看门狗设备 */
if (handle == NULL) {
    HDF_LOGE("WatchdogOpen: failed, ret %d\n", ret);
    return;
}
```

### 获取看门狗状态<a name="section786624341011"></a>

int32\_t WatchdogGetStatus\(DevHandle handle, int32\_t \*status\); 

**表 3**  WatchdogGetStatus参数和返回值描述

<a name="table1018490043"></a>
<table><thead align="left"><tr id="row31848013417"><th class="cellrowborder" valign="top" width="44.99%" id="mcps1.2.3.1.1"><p id="p1415816132411"><a name="p1415816132411"></a><a name="p1415816132411"></a><strong id="b129796117337"><a name="b129796117337"></a><a name="b129796117337"></a>参数</strong></p>
</th>
<th class="cellrowborder" valign="top" width="55.010000000000005%" id="mcps1.2.3.1.2"><p id="p11158111316410"><a name="p11158111316410"></a><a name="p11158111316410"></a><strong id="b1699118123314"><a name="b1699118123314"></a><a name="b1699118123314"></a>参数描述</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row3264122711222"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p15264727182211"><a name="p15264727182211"></a><a name="p15264727182211"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p2026452772210"><a name="p2026452772210"></a><a name="p2026452772210"></a>看门狗设备句柄</p>
</td>
</tr>
<tr id="row928111518418"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p4282955412"><a name="p4282955412"></a><a name="p4282955412"></a>status</p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p7282752412"><a name="p7282752412"></a><a name="p7282752412"></a>获取到的启动状态指针</p>
</td>
</tr>
<tr id="row17393154515328"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p8158313248"><a name="p8158313248"></a><a name="p8158313248"></a><strong id="b18542051332"><a name="b18542051332"></a><a name="b18542051332"></a>返回值</strong></p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p161591413741"><a name="p161591413741"></a><a name="p161591413741"></a><strong id="b45520523313"><a name="b45520523313"></a><a name="b45520523313"></a>返回值描述</strong></p>
</td>
</tr>
<tr id="row339324593215"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p103191916578"><a name="p103191916578"></a><a name="p103191916578"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p1231981611712"><a name="p1231981611712"></a><a name="p1231981611712"></a>获取成功</p>
</td>
</tr>
<tr id="row15393184519323"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p531916166716"><a name="p531916166716"></a><a name="p531916166716"></a>负数</p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p93191161174"><a name="p93191161174"></a><a name="p93191161174"></a>获取失败</p>
</td>
</tr>
</tbody>
</table>

```
int32_t ret;
int32_t status;
/* 获取Watchdog启动状态 */
ret = WatchdogGetStatus(handle, &status);
if (ret != 0) {
    HDF_LOGE("WatchdogGetStatus: failed, ret %d\n", ret);
    return;
}
```

### 设置超时时间<a name="section182386137111"></a>

int32\_t WatchdogSetTimeout\(DevHandle \*handle, uint32\_t seconds\); 

**表 4**  WatchdogSetTimeout参数和返回值描述

<a name="table9159112182210"></a>
<table><thead align="left"><tr id="row1216012212212"><th class="cellrowborder" valign="top" width="44.99%" id="mcps1.2.3.1.1"><p id="p1416017262215"><a name="p1416017262215"></a><a name="p1416017262215"></a><strong id="b181604212216"><a name="b181604212216"></a><a name="b181604212216"></a>参数</strong></p>
</th>
<th class="cellrowborder" valign="top" width="55.010000000000005%" id="mcps1.2.3.1.2"><p id="p16160182192213"><a name="p16160182192213"></a><a name="p16160182192213"></a><strong id="b16160142162216"><a name="b16160142162216"></a><a name="b16160142162216"></a>参数描述</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row199536232314"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p17685481236"><a name="p17685481236"></a><a name="p17685481236"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p196852811232"><a name="p196852811232"></a><a name="p196852811232"></a>看门狗设备句柄</p>
</td>
</tr>
<tr id="row141601729228"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p191601126226"><a name="p191601126226"></a><a name="p191601126226"></a>seconds</p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p5160172182214"><a name="p5160172182214"></a><a name="p5160172182214"></a>超时时间，单位为秒</p>
</td>
</tr>
<tr id="row18160192172212"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p101601123222"><a name="p101601123222"></a><a name="p101601123222"></a><strong id="b516062172215"><a name="b516062172215"></a><a name="b516062172215"></a>返回值</strong></p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p17160192182212"><a name="p17160192182212"></a><a name="p17160192182212"></a><strong id="b141601022227"><a name="b141601022227"></a><a name="b141601022227"></a>返回值描述</strong></p>
</td>
</tr>
<tr id="row171600202220"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p121601226224"><a name="p121601226224"></a><a name="p121601226224"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p151607218222"><a name="p151607218222"></a><a name="p151607218222"></a>设置成功</p>
</td>
</tr>
<tr id="row916012252211"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p19160026224"><a name="p19160026224"></a><a name="p19160026224"></a>负数</p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p816092142210"><a name="p816092142210"></a><a name="p816092142210"></a>设置失败</p>
</td>
</tr>
</tbody>
</table>

```
int32_t ret;
uint32_t timeOut = 60;
/* 设置超时时间，单位：秒 */
ret = WatchdogSetTimeout(handle, timeOut);
if (ret != 0) {
    HDF_LOGE("WatchdogSetTimeout: failed, ret %d\n", ret);
    return;
}
```

### 获取超时时间<a name="section1883310371114"></a>

int32\_t WatchdogGetTimeout\(DevHandle \*handle, uint32\_t \*seconds\);

**表 5**  WatchdogGetTimeout参数和返回值描述

<a name="table10147164819233"></a>
<table><thead align="left"><tr id="row14147848142313"><th class="cellrowborder" valign="top" width="44.99%" id="mcps1.2.3.1.1"><p id="p4147124892316"><a name="p4147124892316"></a><a name="p4147124892316"></a><strong id="b214784813238"><a name="b214784813238"></a><a name="b214784813238"></a>参数</strong></p>
</th>
<th class="cellrowborder" valign="top" width="55.010000000000005%" id="mcps1.2.3.1.2"><p id="p12147144817232"><a name="p12147144817232"></a><a name="p12147144817232"></a><strong id="b51476482234"><a name="b51476482234"></a><a name="b51476482234"></a>参数描述</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row8147124819230"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p21471248142313"><a name="p21471248142313"></a><a name="p21471248142313"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p12147134815233"><a name="p12147134815233"></a><a name="p12147134815233"></a>看门狗设备句柄</p>
</td>
</tr>
<tr id="row514754818232"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p1614713484235"><a name="p1614713484235"></a><a name="p1614713484235"></a>seconds</p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p71478484238"><a name="p71478484238"></a><a name="p71478484238"></a>接收超时时间的指针，单位为秒</p>
</td>
</tr>
<tr id="row214784814239"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p5147848152314"><a name="p5147848152314"></a><a name="p5147848152314"></a><strong id="b17147124822310"><a name="b17147124822310"></a><a name="b17147124822310"></a>返回值</strong></p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p914724811236"><a name="p914724811236"></a><a name="p914724811236"></a><strong id="b614704813231"><a name="b614704813231"></a><a name="b614704813231"></a>返回值描述</strong></p>
</td>
</tr>
<tr id="row714744892312"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p1014764832315"><a name="p1014764832315"></a><a name="p1014764832315"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p1314824872310"><a name="p1314824872310"></a><a name="p1314824872310"></a>获取成功</p>
</td>
</tr>
<tr id="row1514884815230"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p10148114822319"><a name="p10148114822319"></a><a name="p10148114822319"></a>负数</p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p1314864822311"><a name="p1314864822311"></a><a name="p1314864822311"></a>获取失败</p>
</td>
</tr>
</tbody>
</table>

```
int32_t ret;
uint32_t timeOut;
/* 获取超时时间，单位：秒 */
ret = WatchdogGetTimeout(handle, &timeOut);
if (ret != 0) {
    HDF_LOGE("WatchdogGetTimeout: failed, ret %d\n", ret);
    return;
}
```

### 启动看门狗<a name="section82501405123"></a>

int32\_t WatchdogStart\(DevHandle handle\);

**表 6**  WatchdogStart参数和返回值描述

<a name="table529165182515"></a>
<table><thead align="left"><tr id="row92915122513"><th class="cellrowborder" valign="top" width="44.99%" id="mcps1.2.3.1.1"><p id="p5292582517"><a name="p5292582517"></a><a name="p5292582517"></a><strong id="b12293510259"><a name="b12293510259"></a><a name="b12293510259"></a>参数</strong></p>
</th>
<th class="cellrowborder" valign="top" width="55.010000000000005%" id="mcps1.2.3.1.2"><p id="p929554258"><a name="p929554258"></a><a name="p929554258"></a><strong id="b82913542514"><a name="b82913542514"></a><a name="b82913542514"></a>参数描述</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row629852250"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p22975122515"><a name="p22975122515"></a><a name="p22975122515"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p7290515256"><a name="p7290515256"></a><a name="p7290515256"></a>看门狗设备句柄</p>
</td>
</tr>
<tr id="row183035162514"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p8302511255"><a name="p8302511255"></a><a name="p8302511255"></a><strong id="b183018513251"><a name="b183018513251"></a><a name="b183018513251"></a>返回值</strong></p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p16307522515"><a name="p16307522515"></a><a name="p16307522515"></a><strong id="b23010542510"><a name="b23010542510"></a><a name="b23010542510"></a>返回值描述</strong></p>
</td>
</tr>
<tr id="row12305552510"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p1730175132513"><a name="p1730175132513"></a><a name="p1730175132513"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p630754259"><a name="p630754259"></a><a name="p630754259"></a>启动成功</p>
</td>
</tr>
<tr id="row4306516252"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p15304502515"><a name="p15304502515"></a><a name="p15304502515"></a>负数</p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p0301559254"><a name="p0301559254"></a><a name="p0301559254"></a>启动失败</p>
</td>
</tr>
</tbody>
</table>

```
int32_t ret;
/* 启动看门狗 */
ret = WatchdogStart(handle);
if (ret != 0) {
    HDF_LOGE("WatchdogStart: failed, ret %d\n", ret);
    return;
}
```

### 喂狗<a name="section3547530101211"></a>

int32\_t WatchdogFeed\(DevHandle handle\);

**表 7**  WatchdogFeed参数和返回值描述

<a name="table091163515394"></a>
<table><thead align="left"><tr id="row891133515393"><th class="cellrowborder" valign="top" width="44.99%" id="mcps1.2.3.1.1"><p id="p1911143513918"><a name="p1911143513918"></a><a name="p1911143513918"></a><strong id="b1791193553911"><a name="b1791193553911"></a><a name="b1791193553911"></a>参数</strong></p>
</th>
<th class="cellrowborder" valign="top" width="55.010000000000005%" id="mcps1.2.3.1.2"><p id="p1191173553917"><a name="p1191173553917"></a><a name="p1191173553917"></a><strong id="b4911835183910"><a name="b4911835183910"></a><a name="b4911835183910"></a>参数描述</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row189111635143918"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p189111435173917"><a name="p189111435173917"></a><a name="p189111435173917"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p11911143511397"><a name="p11911143511397"></a><a name="p11911143511397"></a>看门狗设备句柄</p>
</td>
</tr>
<tr id="row15911835173916"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p7911123516396"><a name="p7911123516396"></a><a name="p7911123516396"></a><strong id="b59112352394"><a name="b59112352394"></a><a name="b59112352394"></a>返回值</strong></p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p169118356399"><a name="p169118356399"></a><a name="p169118356399"></a><strong id="b1091193593910"><a name="b1091193593910"></a><a name="b1091193593910"></a>返回值描述</strong></p>
</td>
</tr>
<tr id="row189119352393"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p1391113513917"><a name="p1391113513917"></a><a name="p1391113513917"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p149111435143911"><a name="p149111435143911"></a><a name="p149111435143911"></a>喂狗成功</p>
</td>
</tr>
<tr id="row5911123520392"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p49111335143920"><a name="p49111335143920"></a><a name="p49111335143920"></a>负数</p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p1891216356391"><a name="p1891216356391"></a><a name="p1891216356391"></a>喂狗失败</p>
</td>
</tr>
</tbody>
</table>

```
int32_t ret;
/* 喂狗 */
ret = WatchdogFeed(handle);
if (ret != 0) {
    HDF_LOGE("WatchdogFeed: failed, ret %d\n", ret);
    return;
}
```

### 停止看门狗<a name="section944595841217"></a>

int32\_t WatchdogStop\(DevHandle handle\);

**表 8**  WatchdogStop参数和返回值描述

<a name="table1286810515254"></a>
<table><thead align="left"><tr id="row28687517259"><th class="cellrowborder" valign="top" width="44.99%" id="mcps1.2.3.1.1"><p id="p6868185120254"><a name="p6868185120254"></a><a name="p6868185120254"></a><strong id="b986815142510"><a name="b986815142510"></a><a name="b986815142510"></a>参数</strong></p>
</th>
<th class="cellrowborder" valign="top" width="55.010000000000005%" id="mcps1.2.3.1.2"><p id="p15868185114252"><a name="p15868185114252"></a><a name="p15868185114252"></a><strong id="b148681451142517"><a name="b148681451142517"></a><a name="b148681451142517"></a>参数描述</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row1868165114256"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p6869105115256"><a name="p6869105115256"></a><a name="p6869105115256"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p19869951202513"><a name="p19869951202513"></a><a name="p19869951202513"></a>看门狗设备句柄</p>
</td>
</tr>
<tr id="row68696510259"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p2869165114256"><a name="p2869165114256"></a><a name="p2869165114256"></a><strong id="b386935117258"><a name="b386935117258"></a><a name="b386935117258"></a>返回值</strong></p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p158691551142517"><a name="p158691551142517"></a><a name="p158691551142517"></a><strong id="b78691751152513"><a name="b78691751152513"></a><a name="b78691751152513"></a>返回值描述</strong></p>
</td>
</tr>
<tr id="row9869851192516"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p686916516252"><a name="p686916516252"></a><a name="p686916516252"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p7869115192510"><a name="p7869115192510"></a><a name="p7869115192510"></a>停止成功</p>
</td>
</tr>
<tr id="row15869951122519"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p486925112518"><a name="p486925112518"></a><a name="p486925112518"></a>负数</p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p086945172518"><a name="p086945172518"></a><a name="p086945172518"></a>停止失败</p>
</td>
</tr>
</tbody>
</table>

```
int32_t ret;
/* 停止看门狗 */
ret = WatchdogStop(handle);
if (ret != 0) {
    HDF_LOGE("WatchdogStop: failed, ret %d\n", ret);
    return;
}
```

### 关闭看门狗设备<a name="section96561824121311"></a>

当操作完毕时，使用WatchdogClose关闭打开的设备句柄：

void WatchdogClose\(DevHandle handle\);

**表 9**  WatchdogClose参数和返回值描述

<a name="table1017315185320"></a>
<table><thead align="left"><tr id="row417314182327"><th class="cellrowborder" valign="top" width="44.99%" id="mcps1.2.3.1.1"><p id="p117310184320"><a name="p117310184320"></a><a name="p117310184320"></a><strong id="b141734185327"><a name="b141734185327"></a><a name="b141734185327"></a>参数</strong></p>
</th>
<th class="cellrowborder" valign="top" width="55.010000000000005%" id="mcps1.2.3.1.2"><p id="p7173191812324"><a name="p7173191812324"></a><a name="p7173191812324"></a><strong id="b2017318188327"><a name="b2017318188327"></a><a name="b2017318188327"></a>参数描述</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row1617331823211"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p17173191811326"><a name="p17173191811326"></a><a name="p17173191811326"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p538814308323"><a name="p538814308323"></a><a name="p538814308323"></a>看门狗设备句柄</p>
</td>
</tr>
</tbody>
</table>

```
/* 关闭看门狗 */
ret = WatchdogClose(handle);
```

## 使用实例<a name="section1724514523135"></a>

本例程提供看门狗的完整使用流程。

在本例程中，我们打开一个看门狗设备，设置超时时间并启动计时:

-   首先定期喂狗，即按时清除看门狗定时器，确保系统不会因定时器超时而复位。
-   接着再停止喂狗，观察定时器到期后系统是否发生复位行为。

示例如下：

```
#include "watchdog_if.h"
#include "hdf_log.h"
#include "osal_irq.h"
#include "osal_time.h"

#define WATCHDOG_TEST_TIMEOUT     2
#define WATCHDOG_TEST_FEED_TIME   6

static int32_t TestCaseWatchdog(void)
{
    int32_t i;
    int32_t ret;
    uint32_t timeout;
    DevHandle handle = NULL;

    /* 打开0号看门狗设备 */
    handle = WatchdogOpen(0);
    if (handle == NULL) {
        HDF_LOGE("Open watchdog fail!");
        return -1;
    }

    /* 设置超时时间 */
    ret = WatchdogSetTimeout(handle, WATCHDOG_TEST_TIMEOUT);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%s: set timeout fail! ret:%d\n", __func__, ret);
        WatchdogClose(handle);
        return ret;
    }

    /* 回读设置的超时时间值 */
    ret = WatchdogGetTimeout(handle, &timeout);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%s: get timeout fail! ret:%d\n", __func__, ret);
        WatchdogClose(handle);
        return ret;
    }
    HDF_LOGI("%s: read timeout back:%u\n", __func__, timeout);

    /* 启动看门狗，开始计时 */
    ret = WatchdogStart(handle);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%s: satrt fail! ret:%d\n", __func__, ret);
        WatchdogClose(handle);
        return ret;
    }

    /* 每隔1S喂狗一次 */
    for (i = 0; i < WATCHDOG_TEST_FEED_TIME; i++) {
        HDF_LOGE("%s: feeding watchdog %d times... \n", __func__, i);
        ret = WatchdogFeed(handle);
        if (ret != HDF_SUCCESS) {
            HDF_LOGE("%s: feed dog fail! ret:%d\n", __func__, ret);
            WatchdogClose(handle);
            return ret;
        }
        OsalSleep(1);
    }
    /* 由于喂狗间隔小于超时时间，系统不会发生复位，此日志可以正常打印 */
    HDF_LOGE("%s: no reset ... feeding test OK!!!\n", __func__);

    /* 接下来持续不喂狗，使得看门狗计时器超时 */
    for (i = 0; i < WATCHDOG_TEST_FEED_TIME; i++) {
        HDF_LOGE("%s: watiting dog back %d times... \n", __func__, i);
        OsalSleep(1);
    }

    /* 当不喂狗时间到达之前设定的超时时间的时候，系统会发生复位，理论上观察不到此日志的打印 */
    HDF_LOGE("%s: dog hasn't back!!! \n", __func__, i);
    WatchdogClose(handle);
    return -1;
}
```

