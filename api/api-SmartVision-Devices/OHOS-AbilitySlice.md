# OHOS::AbilitySlice<a name="ZH-CN_TOPIC_0000001055078151"></a>

-   [Overview](#section991440798165632)
-   [Summary](#section1784243374165632)
-   [Public Member Functions](#pub-methods)

## **Overview**<a name="section991440798165632"></a>

**Related Modules:**

[AbilityKit](AbilityKit.md)

**Description:**

Provides ability slice-related functions, including ability slice lifecycle callbacks and functions for connecting to or disconnecting from ability slices. 

**[AbilitySlice](OHOS-AbilitySlice.md)**  instances, which are specific to  [Feature](Feature.md)  Abilities \(abilities using the Page template\), are used to present different screens on an application's user interface. A  [Feature](Feature.md) [Ability](OHOS-Ability.md)  can have multiple ability slices.

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1784243374165632"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table1310247832165632"></a>
<table><thead align="left"><tr id="row2001493941165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1757671680165632"><a name="p1757671680165632"></a><a name="p1757671680165632"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p617608130165632"><a name="p617608130165632"></a><a name="p617608130165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1685784336165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1982217703165632"><a name="p1982217703165632"></a><a name="p1982217703165632"></a><a href="AbilityKit.md#gad3ffda54b710b0b86e54bd6c13efae98">OnStart</a> (const <a href="Want.md">Want</a> &amp;want)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p20786846165632"><a name="p20786846165632"></a><a name="p20786846165632"></a>virtual void </p>
<p id="p1758823535165632"><a name="p1758823535165632"></a><a name="p1758823535165632"></a>Called when this ability slice is started. You must override this function if you want to perform some initialization operations during ability slice startup. </p>
</td>
</tr>
<tr id="row131398546165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p471683453165632"><a name="p471683453165632"></a><a name="p471683453165632"></a><a href="AbilityKit.md#gae050b00aa885765bb6808374be772615">OnInactive</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1498231072165632"><a name="p1498231072165632"></a><a name="p1498231072165632"></a>virtual void </p>
<p id="p709848377165632"><a name="p709848377165632"></a><a name="p709848377165632"></a>Called when this ability slice enters the <strong id="b137139134165632"><a name="b137139134165632"></a><a name="b137139134165632"></a>STATE_INACTIVE</strong> state. </p>
</td>
</tr>
<tr id="row820289857165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p722714525165632"><a name="p722714525165632"></a><a name="p722714525165632"></a><a href="AbilityKit.md#ga1a588eb6635e42979e18ac8013f9ea61">OnActive</a> (const <a href="Want.md">Want</a> &amp;want)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1563053296165632"><a name="p1563053296165632"></a><a name="p1563053296165632"></a>virtual void </p>
<p id="p1594585548165632"><a name="p1594585548165632"></a><a name="p1594585548165632"></a>Called when this ability slice enters the <strong id="b948774542165632"><a name="b948774542165632"></a><a name="b948774542165632"></a>STATE_ACTIVE</strong> state. </p>
</td>
</tr>
<tr id="row1355310435165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p690361143165632"><a name="p690361143165632"></a><a name="p690361143165632"></a><a href="AbilityKit.md#ga19217479f8468b525460be156827a524">OnBackground</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p124511161165632"><a name="p124511161165632"></a><a name="p124511161165632"></a>virtual void </p>
<p id="p133735619165632"><a name="p133735619165632"></a><a name="p133735619165632"></a>Called when this ability slice enters the <strong id="b1625504068165632"><a name="b1625504068165632"></a><a name="b1625504068165632"></a>STATE_BACKGROUND</strong> state. </p>
</td>
</tr>
<tr id="row780639063165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p904341470165632"><a name="p904341470165632"></a><a name="p904341470165632"></a><a href="AbilityKit.md#ga4e1556b780a1271e61328e659fc30eb9">OnStop</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1143701157165632"><a name="p1143701157165632"></a><a name="p1143701157165632"></a>virtual void </p>
<p id="p1892536984165632"><a name="p1892536984165632"></a><a name="p1892536984165632"></a>Called when this ability slice enters the <strong id="b1358579595165632"><a name="b1358579595165632"></a><a name="b1358579595165632"></a>STATE_STOP</strong> state. </p>
</td>
</tr>
<tr id="row387354776165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1982953502165632"><a name="p1982953502165632"></a><a name="p1982953502165632"></a><a href="AbilityKit.md#gab2ec8b885edd0d5818b4c60541c1875f">Present</a> (<a href="OHOS-AbilitySlice.md">AbilitySlice</a> &amp;abilitySlice, const <a href="Want.md">Want</a> &amp;want)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p259031923165632"><a name="p259031923165632"></a><a name="p259031923165632"></a>void </p>
<p id="p1110698678165632"><a name="p1110698678165632"></a><a name="p1110698678165632"></a>Presents another ability slice, which can be an ability slice that is not started or an existing ability slice in the host ability. </p>
</td>
</tr>
<tr id="row1537516923165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1020677965165632"><a name="p1020677965165632"></a><a name="p1020677965165632"></a><a href="AbilityKit.md#gaf424e47c7980ff92093c6b7b75888639">Terminate</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p427538382165632"><a name="p427538382165632"></a><a name="p427538382165632"></a>void </p>
<p id="p1341529894165632"><a name="p1341529894165632"></a><a name="p1341529894165632"></a>Destroys this ability slice. </p>
</td>
</tr>
<tr id="row525500963165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1385361314165632"><a name="p1385361314165632"></a><a name="p1385361314165632"></a><a href="AbilityKit.md#ga050a81cda49edb471594447f8f4cdaac">SetUIContent</a> (<a href="OHOS-RootView.md">RootView</a> *rootView)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p947048116165632"><a name="p947048116165632"></a><a name="p947048116165632"></a>void </p>
<p id="p1472971149165632"><a name="p1472971149165632"></a><a name="p1472971149165632"></a>Sets the UI layout for the host ability of this ability slice. </p>
</td>
</tr>
<tr id="row885303241165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1132568666165632"><a name="p1132568666165632"></a><a name="p1132568666165632"></a><a href="AbilityKit.md#gab11d708d5eaa1eca54828fa88625681a">StartAbility</a> (const <a href="Want.md">Want</a> &amp;want)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p43978903165632"><a name="p43978903165632"></a><a name="p43978903165632"></a>int </p>
<p id="p1609388168165632"><a name="p1609388168165632"></a><a name="p1609388168165632"></a>Starts an <a href="OHOS-Ability.md">Ability</a> based on the specified <a href="Want.md">Want</a> information. </p>
</td>
</tr>
<tr id="row741632043165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1652029001165632"><a name="p1652029001165632"></a><a name="p1652029001165632"></a><a href="AbilityKit.md#gadc670d5f6df0d485ee3062b70b3ffe99">StopAbility</a> (const <a href="Want.md">Want</a> &amp;want)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p660462495165632"><a name="p660462495165632"></a><a name="p660462495165632"></a>int </p>
<p id="p1819706708165632"><a name="p1819706708165632"></a><a name="p1819706708165632"></a>Stops an <a href="OHOS-Ability.md">Ability</a> based on the specified <a href="Want.md">Want</a> information. </p>
</td>
</tr>
<tr id="row1224564837165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p153470234165632"><a name="p153470234165632"></a><a name="p153470234165632"></a><a href="AbilityKit.md#gac4a36f03c60fcbeca3b47192ccab1d24">TerminateAbility</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p962298067165632"><a name="p962298067165632"></a><a name="p962298067165632"></a>int </p>
<p id="p516032728165632"><a name="p516032728165632"></a><a name="p516032728165632"></a>Destroys this <a href="OHOS-Ability.md">Ability</a>. </p>
</td>
</tr>
<tr id="row1889296978165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2097332298165632"><a name="p2097332298165632"></a><a name="p2097332298165632"></a><a href="AbilityKit.md#ga4da460ac085a8da1c665f317fcde2ba1">ConnectAbility</a> (const <a href="Want.md">Want</a> &amp;want, const <a href="IAbilityConnection.md">IAbilityConnection</a> &amp;conn, void *data)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2114198848165632"><a name="p2114198848165632"></a><a name="p2114198848165632"></a>int </p>
<p id="p1922129766165632"><a name="p1922129766165632"></a><a name="p1922129766165632"></a>Connects to a <a href="Service.md">Service</a> ability based on the specified <a href="Want.md">Want</a> information. </p>
</td>
</tr>
<tr id="row122713973165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1497192347165632"><a name="p1497192347165632"></a><a name="p1497192347165632"></a><a href="AbilityKit.md#ga1d9023597a9889dbb4015565a10f3470">DisconnectAbility</a> (const <a href="IAbilityConnection.md">IAbilityConnection</a> &amp;conn)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1488825686165632"><a name="p1488825686165632"></a><a name="p1488825686165632"></a>int </p>
<p id="p355880422165632"><a name="p355880422165632"></a><a name="p355880422165632"></a>Disconnects from a <a href="Service.md">Service</a> ability. </p>
</td>
</tr>
</tbody>
</table>

