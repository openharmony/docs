# Watchdog<a name="EN-US_TOPIC_0000001206372825"></a>

## Overview<a name="section14918241977"></a>

A watchdog, also called a watchdog timer, is a hardware timing device. If an error occurs in the main program of the system and fails to reset the watchdog timer, the watchdog timer sends a reset signal to restore the system to a normal state.

## Available APIs<a name="section1180575010271"></a>

**Table  1** Watchdog APIs

<a name="table1731550155318"></a>
<table><thead align="left"><tr id="row4419501537"><th class="cellrowborder" valign="top" width="26.619999999999997%" id="mcps1.2.4.1.1"><p id="p641050105320"><a name="p641050105320"></a><a name="p641050105320"></a>Capability</p>
</th>
<th class="cellrowborder" valign="top" width="32.800000000000004%" id="mcps1.2.4.1.2"><p id="p54150165315"><a name="p54150165315"></a><a name="p54150165315"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="40.58%" id="mcps1.2.4.1.3"><p id="p941150145313"><a name="p941150145313"></a><a name="p941150145313"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row837081981712"><td class="cellrowborder" rowspan="2" valign="top" width="26.619999999999997%" headers="mcps1.2.4.1.1 "><p id="p681292481718"><a name="p681292481718"></a><a name="p681292481718"></a>Open/Close</p>
</td>
<td class="cellrowborder" valign="top" width="32.800000000000004%" headers="mcps1.2.4.1.2 "><p id="p183701419141710"><a name="p183701419141710"></a><a name="p183701419141710"></a>WatchdogOpen</p>
</td>
<td class="cellrowborder" valign="top" width="40.58%" headers="mcps1.2.4.1.3 "><p id="p17370161911710"><a name="p17370161911710"></a><a name="p17370161911710"></a>Opens a watchdog.</p>
</td>
</tr>
<tr id="row5610415171719"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p661171510173"><a name="p661171510173"></a><a name="p661171510173"></a>WatchdogClose</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p11611715161713"><a name="p11611715161713"></a><a name="p11611715161713"></a>Closes a watchdog.</p>
</td>
</tr>
<tr id="row337105133315"><td class="cellrowborder" rowspan="2" valign="top" width="26.619999999999997%" headers="mcps1.2.4.1.1 "><p id="p07631557153319"><a name="p07631557153319"></a><a name="p07631557153319"></a>Start/Stop</p>
</td>
<td class="cellrowborder" valign="top" width="32.800000000000004%" headers="mcps1.2.4.1.2 "><p id="p163765113337"><a name="p163765113337"></a><a name="p163765113337"></a>WatchdogStart</p>
</td>
<td class="cellrowborder" valign="top" width="40.58%" headers="mcps1.2.4.1.3 "><p id="p18376517332"><a name="p18376517332"></a><a name="p18376517332"></a>Starts a watchdog.</p>
</td>
</tr>
<tr id="row18399184610337"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1740010461335"><a name="p1740010461335"></a><a name="p1740010461335"></a>WatchdogStop</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p19400194633318"><a name="p19400194633318"></a><a name="p19400194633318"></a>Stops a watchdog.</p>
</td>
</tr>
<tr id="row34145016535"><td class="cellrowborder" rowspan="2" valign="top" width="26.619999999999997%" headers="mcps1.2.4.1.1 "><p id="p229610227124"><a name="p229610227124"></a><a name="p229610227124"></a>Timeout duration</p>
</td>
<td class="cellrowborder" valign="top" width="32.800000000000004%" headers="mcps1.2.4.1.2 "><p id="p8296182221219"><a name="p8296182221219"></a><a name="p8296182221219"></a>WatchdogSetTimeout</p>
</td>
<td class="cellrowborder" valign="top" width="40.58%" headers="mcps1.2.4.1.3 "><p id="p16297172213125"><a name="p16297172213125"></a><a name="p16297172213125"></a>Sets the watchdog timeout duration.</p>
</td>
</tr>
<tr id="row11585016539"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1095722493616"><a name="p1095722493616"></a><a name="p1095722493616"></a>WatchdogGetTimeout</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p15297162215122"><a name="p15297162215122"></a><a name="p15297162215122"></a>Obtains the watchdog timeout duration.</p>
</td>
</tr>
<tr id="row105701653185811"><td class="cellrowborder" valign="top" width="26.619999999999997%" headers="mcps1.2.4.1.1 "><p id="p2571145325819"><a name="p2571145325819"></a><a name="p2571145325819"></a>Status</p>
</td>
<td class="cellrowborder" valign="top" width="32.800000000000004%" headers="mcps1.2.4.1.2 "><p id="p175711953195814"><a name="p175711953195814"></a><a name="p175711953195814"></a>WatchdogGetStatus</p>
</td>
<td class="cellrowborder" valign="top" width="40.58%" headers="mcps1.2.4.1.3 "><p id="p331961319210"><a name="p331961319210"></a><a name="p331961319210"></a>Obtains the watchdog status.</p>
</td>
</tr>
<tr id="row1028182217215"><td class="cellrowborder" valign="top" width="26.619999999999997%" headers="mcps1.2.4.1.1 "><p id="p182818227214"><a name="p182818227214"></a><a name="p182818227214"></a>Feeding</p>
</td>
<td class="cellrowborder" valign="top" width="32.800000000000004%" headers="mcps1.2.4.1.2 "><p id="p17281223219"><a name="p17281223219"></a><a name="p17281223219"></a>WatchdogFeed</p>
</td>
<td class="cellrowborder" valign="top" width="40.58%" headers="mcps1.2.4.1.3 "><p id="p62815221125"><a name="p62815221125"></a><a name="p62815221125"></a>Feeds a watchdog, or resets a watchdog timer.</p>
</td>
</tr>
</tbody>
</table>

>![](../public_sys-resources/icon-note.gif) **NOTE**<br>
>All watchdog functions provided in this document can be called only in kernel mode.

## Usage Guidelines<a name="section10103184312813"></a>

### How to Use<a name="section10181195910815"></a>

The figure below illustrates how to use the APIs.

**Figure  1** Using watchdog driver APIs  
![](figures/using-watchdog-process.png "process-of-using-a-watchdog")

### Opening a Watchdog<a name="section66089201107"></a>

Use **WatchdogOpen** to open a watchdog. A system may have multiple watchdogs. You can open the specified watchdog by using the ID.

int32\_t WatchdogOpen\(int16\_t wdtId\); 

**Table  2** Description of WatchdogOpen

<a name="table1413702552814"></a>
<table><thead align="left"><tr id="row131371325142819"><th class="cellrowborder" valign="top" width="44.99%" id="mcps1.2.3.1.1"><p id="p191372254283"><a name="p191372254283"></a><a name="p191372254283"></a><strong id="b9239182472212"><a name="b9239182472212"></a><a name="b9239182472212"></a>Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="55.010000000000005%" id="mcps1.2.3.1.2"><p id="p113819255284"><a name="p113819255284"></a><a name="p113819255284"></a><strong id="b2595142572219"><a name="b2595142572219"></a><a name="b2595142572219"></a>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row813812259282"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p101381625162813"><a name="p101381625162813"></a><a name="p101381625162813"></a>wdtId</p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p191381425142813"><a name="p191381425142813"></a><a name="p191381425142813"></a>Watchdog ID.</p>
</td>
</tr>
<tr id="row2138202515281"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p141387252287"><a name="p141387252287"></a><a name="p141387252287"></a><strong id="b185321027172216"><a name="b185321027172216"></a><a name="b185321027172216"></a>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p12138192512281"><a name="p12138192512281"></a><a name="p12138192512281"></a><strong id="b29359286226"><a name="b29359286226"></a><a name="b29359286226"></a>Description</strong></p>
</td>
</tr>
<tr id="row9138182519287"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p5138102532814"><a name="p5138102532814"></a><a name="p5138102532814"></a>NULL</p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p3138192512815"><a name="p3138192512815"></a><a name="p3138192512815"></a>Failed to open the watchdog.</p>
</td>
</tr>
<tr id="row15138192518283"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p1850115512916"><a name="p1850115512916"></a><a name="p1850115512916"></a><strong id="b17275323221"><a name="b17275323221"></a><a name="b17275323221"></a>DevHandle</strong> pointer</p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p16138122512817"><a name="p16138122512817"></a><a name="p16138122512817"></a>Pointer to the watchdog handle.</p>
</td>
</tr>
</tbody>
</table>

```
DevHandle handle = NULL;
handle = WatchdogOpen(0); /* Open watchdog 0.*/
if (handle == NULL) {
    HDF_LOGE("WatchdogOpen: failed, ret %d\n", ret);
    return;
}
```

### Obtaining the Watchdog Status<a name="section786624341011"></a>

int32\_t WatchdogGetStatus\(DevHandle handle, int32\_t \*status\); 

**Table  3** Description of WatchdogGetStatus

<a name="table1018490043"></a>
<table><thead align="left"><tr id="row31848013417"><th class="cellrowborder" valign="top" width="44.99%" id="mcps1.2.3.1.1"><p id="p1415816132411"><a name="p1415816132411"></a><a name="p1415816132411"></a><strong id="b8395121072312"><a name="b8395121072312"></a><a name="b8395121072312"></a>Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="55.010000000000005%" id="mcps1.2.3.1.2"><p id="p11158111316410"><a name="p11158111316410"></a><a name="p11158111316410"></a><strong id="b20193201115238"><a name="b20193201115238"></a><a name="b20193201115238"></a>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row3264122711222"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p15264727182211"><a name="p15264727182211"></a><a name="p15264727182211"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p2026452772210"><a name="p2026452772210"></a><a name="p2026452772210"></a>Watchdog handle.</p>
</td>
</tr>
<tr id="row928111518418"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p4282955412"><a name="p4282955412"></a><a name="p4282955412"></a>status</p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p7282752412"><a name="p7282752412"></a><a name="p7282752412"></a>Pointer to the watchdog status.</p>
</td>
</tr>
<tr id="row17393154515328"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p8158313248"><a name="p8158313248"></a><a name="p8158313248"></a><strong id="b12817162152319"><a name="b12817162152319"></a><a name="b12817162152319"></a>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p161591413741"><a name="p161591413741"></a><a name="p161591413741"></a><strong id="b112451923142314"><a name="b112451923142314"></a><a name="b112451923142314"></a>Description</strong></p>
</td>
</tr>
<tr id="row339324593215"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p103191916578"><a name="p103191916578"></a><a name="p103191916578"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p1231981611712"><a name="p1231981611712"></a><a name="p1231981611712"></a>The watchdog status is obtained.</p>
</td>
</tr>
<tr id="row15393184519323"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p531916166716"><a name="p531916166716"></a><a name="p531916166716"></a>Negative value</p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p93191161174"><a name="p93191161174"></a><a name="p93191161174"></a>Failed to obtain the watchdog status.</p>
</td>
</tr>
</tbody>
</table>

```
int32_t ret;
int32_t status;
/* Obtain the watchdog status. */
ret = WatchdogGetStatus(handle, &status);
if (ret != 0) {
    HDF_LOGE("WatchdogGetStatus: failed, ret %d\n", ret);
    return;
}
```

### Setting the Timeout Duration<a name="section182386137111"></a>

int32\_t WatchdogSetTimeout\(PalHandle \*handle, uint32\_t seconds\); 

**Table  4** Description of WatchdogSetTimeout

<a name="table9159112182210"></a>
<table><thead align="left"><tr id="row1216012212212"><th class="cellrowborder" valign="top" width="44.99%" id="mcps1.2.3.1.1"><p id="p1416017262215"><a name="p1416017262215"></a><a name="p1416017262215"></a><strong id="b16573184672318"><a name="b16573184672318"></a><a name="b16573184672318"></a>Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="55.010000000000005%" id="mcps1.2.3.1.2"><p id="p16160182192213"><a name="p16160182192213"></a><a name="p16160182192213"></a><strong id="b8612347182320"><a name="b8612347182320"></a><a name="b8612347182320"></a>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row199536232314"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p17685481236"><a name="p17685481236"></a><a name="p17685481236"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p196852811232"><a name="p196852811232"></a><a name="p196852811232"></a>Watchdog handle.</p>
</td>
</tr>
<tr id="row141601729228"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p191601126226"><a name="p191601126226"></a><a name="p191601126226"></a>seconds</p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p5160172182214"><a name="p5160172182214"></a><a name="p5160172182214"></a>Timeout duration, in seconds.</p>
</td>
</tr>
<tr id="row18160192172212"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p101601123222"><a name="p101601123222"></a><a name="p101601123222"></a><strong id="b12598352112317"><a name="b12598352112317"></a><a name="b12598352112317"></a>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p17160192182212"><a name="p17160192182212"></a><a name="p17160192182212"></a><strong id="b145511753122319"><a name="b145511753122319"></a><a name="b145511753122319"></a>Description</strong></p>
</td>
</tr>
<tr id="row171600202220"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p121601226224"><a name="p121601226224"></a><a name="p121601226224"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p151607218222"><a name="p151607218222"></a><a name="p151607218222"></a>The setting is successful.</p>
</td>
</tr>
<tr id="row916012252211"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p19160026224"><a name="p19160026224"></a><a name="p19160026224"></a>Negative value</p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p816092142210"><a name="p816092142210"></a><a name="p816092142210"></a>Setting failed.</p>
</td>
</tr>
</tbody>
</table>

```
int32_t ret;
uint32_t timeOut = 60;
/* Set the timeout duration, in seconds. */
ret = WatchdogSetTimeout(handle, timeOut);
if (ret != 0) {
    HDF_LOGE("WatchdogSetTimeout: failed, ret %d\n", ret);
    return;
}
```

### Obtaining the Timeout Duration<a name="section1883310371114"></a>

int32\_t WatchdogGetTimeout\(PalHandle \*handle, uint32\_t \*seconds\); 

**Table  5** Description of WatchdogGetTimeout

<a name="table10147164819233"></a>
<table><thead align="left"><tr id="row14147848142313"><th class="cellrowborder" valign="top" width="44.99%" id="mcps1.2.3.1.1"><p id="p4147124892316"><a name="p4147124892316"></a><a name="p4147124892316"></a><strong id="b1387481413247"><a name="b1387481413247"></a><a name="b1387481413247"></a>Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="55.010000000000005%" id="mcps1.2.3.1.2"><p id="p12147144817232"><a name="p12147144817232"></a><a name="p12147144817232"></a><strong id="b7800151515242"><a name="b7800151515242"></a><a name="b7800151515242"></a>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row8147124819230"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p21471248142313"><a name="p21471248142313"></a><a name="p21471248142313"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p12147134815233"><a name="p12147134815233"></a><a name="p12147134815233"></a>Watchdog handle.</p>
</td>
</tr>
<tr id="row514754818232"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p1614713484235"><a name="p1614713484235"></a><a name="p1614713484235"></a>seconds</p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p71478484238"><a name="p71478484238"></a><a name="p71478484238"></a>Pointer to the timeout duration, in seconds.</p>
</td>
</tr>
<tr id="row214784814239"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p5147848152314"><a name="p5147848152314"></a><a name="p5147848152314"></a><strong id="b2468182016249"><a name="b2468182016249"></a><a name="b2468182016249"></a>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p914724811236"><a name="p914724811236"></a><a name="p914724811236"></a><strong id="b18272182132419"><a name="b18272182132419"></a><a name="b18272182132419"></a>Description</strong></p>
</td>
</tr>
<tr id="row714744892312"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p1014764832315"><a name="p1014764832315"></a><a name="p1014764832315"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p1314824872310"><a name="p1314824872310"></a><a name="p1314824872310"></a>The watchdog status is obtained.</p>
</td>
</tr>
<tr id="row1514884815230"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p10148114822319"><a name="p10148114822319"></a><a name="p10148114822319"></a>Negative value</p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p1314864822311"><a name="p1314864822311"></a><a name="p1314864822311"></a>Failed to obtain the watchdog status.</p>
</td>
</tr>
</tbody>
</table>

```
int32_t ret;
uint32_t timeOut;
/* Obtain the timeout duration, in seconds. */
ret = WatchdogGetTimeout(handle, &timeOut);
if (ret != 0) {
    HDF_LOGE("WatchdogGetTimeout: failed, ret %d\n", ret);
    return;
}
```

### Starting a Watchdog<a name="section82501405123"></a>

int32\_t WatchdogStart\(DevHandle handle\); 

**Table  6** Description of WatchdogStart

<a name="table529165182515"></a>
<table><thead align="left"><tr id="row92915122513"><th class="cellrowborder" valign="top" width="44.99%" id="mcps1.2.3.1.1"><p id="p5292582517"><a name="p5292582517"></a><a name="p5292582517"></a><strong id="b99151951162417"><a name="b99151951162417"></a><a name="b99151951162417"></a>Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="55.010000000000005%" id="mcps1.2.3.1.2"><p id="p929554258"><a name="p929554258"></a><a name="p929554258"></a><strong id="b121171651142418"><a name="b121171651142418"></a><a name="b121171651142418"></a>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row629852250"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p22975122515"><a name="p22975122515"></a><a name="p22975122515"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p7290515256"><a name="p7290515256"></a><a name="p7290515256"></a>Watchdog handle.</p>
</td>
</tr>
<tr id="row183035162514"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p8302511255"><a name="p8302511255"></a><a name="p8302511255"></a><strong id="b1190315442414"><a name="b1190315442414"></a><a name="b1190315442414"></a>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p16307522515"><a name="p16307522515"></a><a name="p16307522515"></a><strong id="b333525652414"><a name="b333525652414"></a><a name="b333525652414"></a>Description</strong></p>
</td>
</tr>
<tr id="row12305552510"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p1730175132513"><a name="p1730175132513"></a><a name="p1730175132513"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p630754259"><a name="p630754259"></a><a name="p630754259"></a>The watchdog is started.</p>
</td>
</tr>
<tr id="row4306516252"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p15304502515"><a name="p15304502515"></a><a name="p15304502515"></a>Negative value</p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p0301559254"><a name="p0301559254"></a><a name="p0301559254"></a>Failed to start the watchdog.</p>
</td>
</tr>
</tbody>
</table>

```
int32_t ret;
/* Start the watchdog. */
ret = WatchdogStart(handle);
if (ret != 0) {
    HDF_LOGE("WatchdogStart: failed, ret %d\n", ret);
    return;
}
```

### Feeding a Watchdog<a name="section3547530101211"></a>

int32\_t WatchdogFeed\(DevHandle handle\);

**Table  7** Description of WatchdogFeed

<a name="table091163515394"></a>
<table><thead align="left"><tr id="row891133515393"><th class="cellrowborder" valign="top" width="44.99%" id="mcps1.2.3.1.1"><p id="p1911143513918"><a name="p1911143513918"></a><a name="p1911143513918"></a><strong id="b16850010142518"><a name="b16850010142518"></a><a name="b16850010142518"></a>Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="55.010000000000005%" id="mcps1.2.3.1.2"><p id="p1191173553917"><a name="p1191173553917"></a><a name="p1191173553917"></a><strong id="b8711511102516"><a name="b8711511102516"></a><a name="b8711511102516"></a>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row189111635143918"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p189111435173917"><a name="p189111435173917"></a><a name="p189111435173917"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p11911143511397"><a name="p11911143511397"></a><a name="p11911143511397"></a>Watchdog handle.</p>
</td>
</tr>
<tr id="row15911835173916"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p7911123516396"><a name="p7911123516396"></a><a name="p7911123516396"></a><strong id="b11359914162517"><a name="b11359914162517"></a><a name="b11359914162517"></a>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p169118356399"><a name="p169118356399"></a><a name="p169118356399"></a><strong id="b7180915162512"><a name="b7180915162512"></a><a name="b7180915162512"></a>Description</strong></p>
</td>
</tr>
<tr id="row189119352393"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p1391113513917"><a name="p1391113513917"></a><a name="p1391113513917"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p149111435143911"><a name="p149111435143911"></a><a name="p149111435143911"></a>The watchdog is fed.</p>
</td>
</tr>
<tr id="row5911123520392"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p49111335143920"><a name="p49111335143920"></a><a name="p49111335143920"></a>Negative value</p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p1891216356391"><a name="p1891216356391"></a><a name="p1891216356391"></a>Failed to feed the watchdog.</p>
</td>
</tr>
</tbody>
</table>

```
int32_t ret;
/* Feed the watchdog. */
ret = WatchdogFeed(handle);
if (ret != 0) {
    HDF_LOGE("WatchdogFeed: failed, ret %d\n", ret);
    return;
}
```

### Stopping a Watchdog<a name="section944595841217"></a>

int32\_t WatchdogStop\(DevHandle handle\); 

**Table  8** Description of WatchdogStop

<a name="table1286810515254"></a>
<table><thead align="left"><tr id="row28687517259"><th class="cellrowborder" valign="top" width="44.99%" id="mcps1.2.3.1.1"><p id="p6868185120254"><a name="p6868185120254"></a><a name="p6868185120254"></a><strong id="b204221347152519"><a name="b204221347152519"></a><a name="b204221347152519"></a>Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="55.010000000000005%" id="mcps1.2.3.1.2"><p id="p15868185114252"><a name="p15868185114252"></a><a name="p15868185114252"></a><strong id="b8153154862516"><a name="b8153154862516"></a><a name="b8153154862516"></a>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row1868165114256"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p6869105115256"><a name="p6869105115256"></a><a name="p6869105115256"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p19869951202513"><a name="p19869951202513"></a><a name="p19869951202513"></a>Watchdog handle.</p>
</td>
</tr>
<tr id="row68696510259"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p2869165114256"><a name="p2869165114256"></a><a name="p2869165114256"></a><strong id="b2116105210253"><a name="b2116105210253"></a><a name="b2116105210253"></a>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p158691551142517"><a name="p158691551142517"></a><a name="p158691551142517"></a><strong id="b8888115292518"><a name="b8888115292518"></a><a name="b8888115292518"></a>Description</strong></p>
</td>
</tr>
<tr id="row9869851192516"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p686916516252"><a name="p686916516252"></a><a name="p686916516252"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p7869115192510"><a name="p7869115192510"></a><a name="p7869115192510"></a>The watchdog is stopped.</p>
</td>
</tr>
<tr id="row15869951122519"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p486925112518"><a name="p486925112518"></a><a name="p486925112518"></a>Negative value</p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p086945172518"><a name="p086945172518"></a><a name="p086945172518"></a>Stopping the watchdog failed.</p>
</td>
</tr>
</tbody>
</table>

```
int32_t ret;
/* Stop the watchdog. */
ret = WatchdogStop(handle);
if (ret != 0) {
    HDF_LOGE("WatchdogStop: failed, ret %d\n", ret);
    return;
}
```

### Closing a Watchdog<a name="section96561824121311"></a>

If the watchdog is no longer required, call **WatchdogClose** to close the watchdog handle.

void WatchdogClose\(DevHandle handle\);

**Table  9** Description of WatchdogClose

<a name="table1017315185320"></a>
<table><thead align="left"><tr id="row417314182327"><th class="cellrowborder" valign="top" width="44.99%" id="mcps1.2.3.1.1"><p id="p117310184320"><a name="p117310184320"></a><a name="p117310184320"></a><strong id="b97421847122514"><a name="b97421847122514"></a><a name="b97421847122514"></a>Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="55.010000000000005%" id="mcps1.2.3.1.2"><p id="p7173191812324"><a name="p7173191812324"></a><a name="p7173191812324"></a><strong id="b14503748122514"><a name="b14503748122514"></a><a name="b14503748122514"></a>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row1617331823211"><td class="cellrowborder" valign="top" width="44.99%" headers="mcps1.2.3.1.1 "><p id="p17173191811326"><a name="p17173191811326"></a><a name="p17173191811326"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="55.010000000000005%" headers="mcps1.2.3.1.2 "><p id="p538814308323"><a name="p538814308323"></a><a name="p538814308323"></a>Watchdog handle.</p>
</td>
</tr>
</tbody>
</table>

```
/* Close the watchdog. */
ret = WatchdogClose(handle);
```

## Usage Example<a name="section1724514523135"></a>

This example provides a complete process for using a watchdog.

In this example, open a watchdog, set the timeout duration, and start the watchdog.

-   Feed the watchdog periodically to ensure that the system is not reset due to timer expiry.
-   Stop feeding the watchdog and check whether the system is reset after the timer expires.

Example:

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

    /* Open watchdog 0. */
    handle = WatchdogOpen(0);
    if (handle == NULL) {
        HDF_LOGE("Open watchdog fail!");
        return -1;
    }

    /* Set the timeout duration. */
    ret = WatchdogSetTimeout(handle, WATCHDOG_TEST_TIMEOUT);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%s: set timeout fail! ret:%d\n", __func__, ret);
        WatchdogClose(handle);
        return ret;
    }

    /* Obtain the configured timeout duration. */
    ret = WatchdogGetTimeout(handle, &timeout);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%s: get timeout fail! ret:%d\n", __func__, ret);
        WatchdogClose(handle);
        return ret;
    }
    HDF_LOGI("%s: read timeout back:%u\n", __func__, timeout);

    /* Start the watchdog. The timer starts. */
    ret = WatchdogStart(handle);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%s: satrt fail! ret:%d\n", __func__, ret);
        WatchdogClose(handle);
        return ret;
    }

    /* Feed the watchdog every 1s. */
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
    /* Because the interval for feeding the watchdog is shorter than the timeout duration, the system does not reset, and logs can be printed normally. */
    HDF_LOGE("%s: no reset ... feeding test OK!!!\n", __func__);

    /* Enable the timer to expire by stopping feeding the watchdog. */
    for (i = 0; i < WATCHDOG_TEST_FEED_TIME; i++) {
        HDF_LOGE("%s: watiting dog buck %d times... \n", __func__, i);
        OsalSleep(1);
    }

    /* The system resets when the timer expires. If the code is correct, the log below is not displayed. */
    HDF_LOGE("%s: dog has't buck!!! \n", __func__, i);
    WatchdogClose(handle);
    return -1;
}
```