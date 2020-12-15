# OHOS::Ability<a name="EN-US_TOPIC_0000001054479575"></a>

-   [Overview](#section686627827165632)
-   [Summary](#section182016991165632)
-   [Public Member Functions](#pub-methods)

## **Overview**<a name="section686627827165632"></a>

**Related Modules:**

[AbilityKit](abilitykit.md)

**Description:**

Declares ability-related functions, including ability lifecycle callbacks and functions for connecting to or disconnecting from Particle Abilities. 

As the fundamental unit of OpenHarmony applications, abilities are classified into  [Feature](feature.md)  Abilities and Particle Abilities.  [Feature](feature.md)  Abilities support the Page template, and Particle Abilities support the  [Service](service.md)  template. An ability using the Page template is called Page ability for short and that using the  [Service](service.md)  template is called  [Service](service.md)  ability.

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section182016991165632"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table875809647165632"></a>
<table><thead align="left"><tr id="row1646590855165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1395536008165632"><a name="p1395536008165632"></a><a name="p1395536008165632"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1016693824165632"><a name="p1016693824165632"></a><a name="p1016693824165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row849508489165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1453686894165632"><a name="p1453686894165632"></a><a name="p1453686894165632"></a><a href="abilitykit.md#ga4d016d42397f33c7710db8544581c757">OnStart</a> (const <a href="want.md">Want</a> &amp;want)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p540301847165632"><a name="p540301847165632"></a><a name="p540301847165632"></a>virtual void </p>
<p id="p549128055165632"><a name="p549128055165632"></a><a name="p549128055165632"></a>Called when this ability is started. You must override this function if you want to perform some initialization operations during ability startup. </p>
</td>
</tr>
<tr id="row1652175935165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p930990971165632"><a name="p930990971165632"></a><a name="p930990971165632"></a><a href="abilitykit.md#gae251a38aa7c0aebd7498eef86deab7c1">OnInactive</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p940929638165632"><a name="p940929638165632"></a><a name="p940929638165632"></a>virtual void </p>
<p id="p542302668165632"><a name="p542302668165632"></a><a name="p542302668165632"></a>Called when this ability enters the <strong id="b2082006925165632"><a name="b2082006925165632"></a><a name="b2082006925165632"></a>STATE_INACTIVE</strong> state. </p>
</td>
</tr>
<tr id="row1726122509165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p140299007165632"><a name="p140299007165632"></a><a name="p140299007165632"></a><a href="abilitykit.md#ga3135bfa435f5aaa185f21014a9e86e59">OnActive</a> (const <a href="want.md">Want</a> &amp;want)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2018294143165632"><a name="p2018294143165632"></a><a name="p2018294143165632"></a>virtual void </p>
<p id="p1311118038165632"><a name="p1311118038165632"></a><a name="p1311118038165632"></a>Called when this ability enters the <strong id="b609388297165632"><a name="b609388297165632"></a><a name="b609388297165632"></a>STATE_ACTIVE</strong> state. </p>
</td>
</tr>
<tr id="row978088755165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1009009736165632"><a name="p1009009736165632"></a><a name="p1009009736165632"></a><a href="abilitykit.md#ga8185ad517d94ca99a00917d3d1f10620">OnBackground</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p795196067165632"><a name="p795196067165632"></a><a name="p795196067165632"></a>virtual void </p>
<p id="p709796004165632"><a name="p709796004165632"></a><a name="p709796004165632"></a>Called when this ability enters the <strong id="b453524171165632"><a name="b453524171165632"></a><a name="b453524171165632"></a>STATE_BACKGROUND</strong> state. </p>
</td>
</tr>
<tr id="row807327556165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1890229184165632"><a name="p1890229184165632"></a><a name="p1890229184165632"></a><a href="abilitykit.md#gaa4145b360bbe5cdb5d267b17ac12af6a">OnStop</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p293254190165632"><a name="p293254190165632"></a><a name="p293254190165632"></a>virtual void </p>
<p id="p1341843924165632"><a name="p1341843924165632"></a><a name="p1341843924165632"></a>Called when this ability enters the <strong id="b2067096314165632"><a name="b2067096314165632"></a><a name="b2067096314165632"></a>STATE_STOP</strong> state. </p>
</td>
</tr>
<tr id="row1791232489165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1859764241165632"><a name="p1859764241165632"></a><a name="p1859764241165632"></a><a href="abilitykit.md#ga88e9dbaaa083be9f06adeea27680ef76">OnConnect</a> (const <a href="want.md">Want</a> &amp;want)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1473587870165632"><a name="p1473587870165632"></a><a name="p1473587870165632"></a>virtual const SvcIdentity * </p>
<p id="p143215404165632"><a name="p143215404165632"></a><a name="p143215404165632"></a>Called when this <a href="service.md">Service</a> ability is connected for the first time. </p>
</td>
</tr>
<tr id="row1598548600165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1034830851165632"><a name="p1034830851165632"></a><a name="p1034830851165632"></a><a href="abilitykit.md#gac17d2b81d661134b63ee74b0212eace6">OnDisconnect</a> (const <a href="want.md">Want</a> &amp;want)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p675804049165632"><a name="p675804049165632"></a><a name="p675804049165632"></a>virtual void </p>
<p id="p1218740258165632"><a name="p1218740258165632"></a><a name="p1218740258165632"></a>Called when all abilities connected to this <a href="service.md">Service</a> ability are disconnected. </p>
</td>
</tr>
<tr id="row377002491165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p497533447165632"><a name="p497533447165632"></a><a name="p497533447165632"></a><a href="abilitykit.md#gac83a9af046458b7f6bfaf85071b093f4">SetMainRoute</a> (const std::string &amp;<a href="entry.md">entry</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p899951112165632"><a name="p899951112165632"></a><a name="p899951112165632"></a>void </p>
<p id="p1497803139165632"><a name="p1497803139165632"></a><a name="p1497803139165632"></a>Sets the main route for this ability. </p>
</td>
</tr>
<tr id="row1310926151165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p684980461165632"><a name="p684980461165632"></a><a name="p684980461165632"></a><a href="abilitykit.md#ga9b734c2ad8ad52f906d676f0c897a4aa">SetUIContent</a> (<a href="ohos-rootview.md">RootView</a> *rootView)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1843503935165632"><a name="p1843503935165632"></a><a name="p1843503935165632"></a>void </p>
<p id="p312039368165632"><a name="p312039368165632"></a><a name="p312039368165632"></a>Sets the UI layout for this ability. You can call <strong id="b959583830165632"><a name="b959583830165632"></a><a name="b959583830165632"></a>GetWindowRootView()</strong> to create a layout and add controls. </p>
</td>
</tr>
<tr id="row1266602865165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1073980064165632"><a name="p1073980064165632"></a><a name="p1073980064165632"></a><a href="abilitykit.md#gab2d208621c7236c3608afb77d8a02966">MsgHandle</a> (uint32_t funcId, IpcIo *request, IpcIo *reply)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p965820957165632"><a name="p965820957165632"></a><a name="p965820957165632"></a>virtual void </p>
<p id="p223694496165632"><a name="p223694496165632"></a><a name="p223694496165632"></a>Handles a message sent by the client to this <a href="service.md">Service</a> ability. </p>
</td>
</tr>
<tr id="row1422392272165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1536457536165632"><a name="p1536457536165632"></a><a name="p1536457536165632"></a><a href="abilitykit.md#ga5330624843c776ebe61366540d32eb92">Dump</a> (const std::string &amp;extra)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p269982077165632"><a name="p269982077165632"></a><a name="p269982077165632"></a>virtual void </p>
<p id="p219081160165632"><a name="p219081160165632"></a><a name="p219081160165632"></a>Prints ability information to the console. </p>
</td>
</tr>
<tr id="row1319167645165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1654716264165632"><a name="p1654716264165632"></a><a name="p1654716264165632"></a><a href="abilitykit.md#gab11d708d5eaa1eca54828fa88625681a">StartAbility</a> (const <a href="want.md">Want</a> &amp;want)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p753565405165632"><a name="p753565405165632"></a><a name="p753565405165632"></a>int </p>
<p id="p902271214165632"><a name="p902271214165632"></a><a name="p902271214165632"></a>Starts an <a href="ohos-ability.md">Ability</a> based on the specified <a href="want.md">Want</a> information. </p>
</td>
</tr>
<tr id="row1584313896165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1468965187165632"><a name="p1468965187165632"></a><a name="p1468965187165632"></a><a href="abilitykit.md#gadc670d5f6df0d485ee3062b70b3ffe99">StopAbility</a> (const <a href="want.md">Want</a> &amp;want)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p278864256165632"><a name="p278864256165632"></a><a name="p278864256165632"></a>int </p>
<p id="p1695931944165632"><a name="p1695931944165632"></a><a name="p1695931944165632"></a>Stops an <a href="ohos-ability.md">Ability</a> based on the specified <a href="want.md">Want</a> information. </p>
</td>
</tr>
<tr id="row1451207089165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1734005155165632"><a name="p1734005155165632"></a><a name="p1734005155165632"></a><a href="abilitykit.md#gac4a36f03c60fcbeca3b47192ccab1d24">TerminateAbility</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p44589026165632"><a name="p44589026165632"></a><a name="p44589026165632"></a>int </p>
<p id="p869582941165632"><a name="p869582941165632"></a><a name="p869582941165632"></a>Destroys this <a href="ohos-ability.md">Ability</a>. </p>
</td>
</tr>
<tr id="row1157209658165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p207932181165632"><a name="p207932181165632"></a><a name="p207932181165632"></a><a href="abilitykit.md#ga4da460ac085a8da1c665f317fcde2ba1">ConnectAbility</a> (const <a href="want.md">Want</a> &amp;want, const <a href="iabilityconnection.md">IAbilityConnection</a> &amp;conn, void *data)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p118292578165632"><a name="p118292578165632"></a><a name="p118292578165632"></a>int </p>
<p id="p564942328165632"><a name="p564942328165632"></a><a name="p564942328165632"></a>Connects to a <a href="service.md">Service</a> ability based on the specified <a href="want.md">Want</a> information. </p>
</td>
</tr>
<tr id="row1249520296165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1911507722165632"><a name="p1911507722165632"></a><a name="p1911507722165632"></a><a href="abilitykit.md#ga1d9023597a9889dbb4015565a10f3470">DisconnectAbility</a> (const <a href="iabilityconnection.md">IAbilityConnection</a> &amp;conn)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1978724604165632"><a name="p1978724604165632"></a><a name="p1978724604165632"></a>int </p>
<p id="p1472831483165632"><a name="p1472831483165632"></a><a name="p1472831483165632"></a>Disconnects from a <a href="service.md">Service</a> ability. </p>
</td>
</tr>
</tbody>
</table>

