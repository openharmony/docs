# AbilityKit<a name="EN-US_TOPIC_0000001054598111"></a>

-   [Overview](#section2113005606165623)
-   [Summary](#section50038972165623)
-   [Files](#files)
-   [Data Structures](#nested-classes)
-   [Macros](#define-members)
-   [Enumerations](#enum-members)
-   [Functions](#func-members)
-   [Details](#section268415259165623)
-   [Macro Definition](#section1597786070165623)
-   [REGISTER\_AA](#ga2c5bd891b502a92f937ae4bff3f80cad)
-   [REGISTER\_AS](#ga8e811999b2b7780e67cb746d045ab5b8)
-   [Enumeration Type](#section1266264770165623)
-   [anonymous enum](#ga99fb83031ce9923c84392b4e92f956b5)
-   [State](#ga5d74787dedbc4e11c1ab15bf487e61f8)
-   [Function](#section1829026629165623)
-   [ClearWant\(\)](#ga62ca448e092c81497ffdd1f0b1c56938)
-   [ConnectAbility\(\) \[1/2\]](#ga4da460ac085a8da1c665f317fcde2ba1)
-   [ConnectAbility\(\) \[2/2\]](#gaae6c2bbb6ab0df92e39c1daad2bd901f)
-   [DisconnectAbility\(\) \[1/2\]](#ga1d9023597a9889dbb4015565a10f3470)
-   [DisconnectAbility\(\) \[2/2\]](#ga2769216a4c2654d3297a2fdb4011ea7a)
-   [Dump\(\)](#ga5330624843c776ebe61366540d32eb92)
-   [GetBundleName\(\)](#gac893d7c01fabee34f80294e3e026c37d)
-   [GetCurrentHandler\(\)](#gad26d144aaecd3185be6902e6d7399b9e)
-   [GetDataPath\(\)](#ga9be6a002714f3fb61b2335dd13ed9787)
-   [GetSrcPath\(\)](#ga7cead123e67bea6db8a34c8ae100e6c5)
-   [MsgHandle\(\)](#gab2d208621c7236c3608afb77d8a02966)
-   [OnActive\(\) \[1/2\]](#ga1a588eb6635e42979e18ac8013f9ea61)
-   [OnActive\(\) \[2/2\]](#ga3135bfa435f5aaa185f21014a9e86e59)
-   [OnBackground\(\) \[1/2\]](#ga19217479f8468b525460be156827a524)
-   [OnBackground\(\) \[2/2\]](#ga8185ad517d94ca99a00917d3d1f10620)
-   [OnConnect\(\)](#ga88e9dbaaa083be9f06adeea27680ef76)
-   [OnDisconnect\(\)](#gac17d2b81d661134b63ee74b0212eace6)
-   [OnInactive\(\) \[1/2\]](#gae050b00aa885765bb6808374be772615)
-   [OnInactive\(\) \[2/2\]](#gae251a38aa7c0aebd7498eef86deab7c1)
-   [OnStart\(\) \[1/2\]](#gad3ffda54b710b0b86e54bd6c13efae98)
-   [OnStart\(\) \[2/2\]](#ga4d016d42397f33c7710db8544581c757)
-   [OnStop\(\) \[1/2\]](#ga4e1556b780a1271e61328e659fc30eb9)
-   [OnStop\(\) \[2/2\]](#gaa4145b360bbe5cdb5d267b17ac12af6a)
-   [PostTask\(\)](#gad4d0911a8bccd5aca32464bad867cb13)
-   [Present\(\)](#gab2ec8b885edd0d5818b4c60541c1875f)
-   [SetMainRoute\(\)](#gac83a9af046458b7f6bfaf85071b093f4)
-   [SetUIContent\(\) \[1/2\]](#ga050a81cda49edb471594447f8f4cdaac)
-   [SetUIContent\(\) \[2/2\]](#ga9b734c2ad8ad52f906d676f0c897a4aa)
-   [SetWantData\(\)](#ga89a719b5f730bc5fde9f637a5ed630c9)
-   [SetWantElement\(\)](#ga65f4d2eab99497e496dcd493bd0d047e)
-   [SetWantSvcIdentity\(\)](#gab8e5fac952fc6407f20cd9b7185d3a65)
-   [StartAbility\(\) \[1/2\]](#gab11d708d5eaa1eca54828fa88625681a)
-   [StartAbility\(\) \[2/2\]](#gae79800c4077afdc2851d5a74d8964111)
-   [StopAbility\(\) \[1/2\]](#gadc670d5f6df0d485ee3062b70b3ffe99)
-   [StopAbility\(\) \[2/2\]](#gaba99bbd4ff6da4fb072338f5ce95e6ae)
-   [Terminate\(\)](#gaf424e47c7980ff92093c6b7b75888639)
-   [TerminateAbility\(\)](#gac4a36f03c60fcbeca3b47192ccab1d24)
-   [WantParseUri\(\)](#ga43226d0858faa92e83bea33aaf4b614c)
-   [WantToUri\(\)](#ga31adc60981c10b22d0e9bbdc7126d17c)
-   [Variable](#section1912686851165623)
-   [OnAbilityConnectDone](#ga3b9bfacbcf1564c83cffbfff7889998a)
-   [OnAbilityDisconnectDone](#gaba7cf0abb517890ef1a3949e398aaf1d)

## **Overview**<a name="section2113005606165623"></a>

**Description:**

Provides ability-related functions, including ability lifecycle callbacks and functions for connecting to or disconnecting from Particle Abilities. 

Abilities are classified into  [Feature](feature.md)  Abilities and Particle Abilities.  [Feature](feature.md)  Abilities support the Page template, and Particle Abilities support the  [Service](service.md)  template. An ability using the Page template is called a Page ability for short and that using the  [Service](service.md)  template is called a  [Service](service.md)  ability.

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section50038972165623"></a>

## Files<a name="files"></a>

<a name="table62850785165623"></a>
<table><thead align="left"><tr id="row993133169165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p708083544165623"><a name="p708083544165623"></a><a name="p708083544165623"></a>File Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p114342141165623"><a name="p114342141165623"></a><a name="p114342141165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1897508259165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1130752629165623"><a name="p1130752629165623"></a><a name="p1130752629165623"></a><a href="ability-h.md">ability.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1200506241165623"><a name="p1200506241165623"></a><a name="p1200506241165623"></a>Declares ability-related functions, including ability lifecycle callbacks and functions for connecting to or disconnecting from Particle Abilities. </p>
</td>
</tr>
<tr id="row1027529617165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p47285002165623"><a name="p47285002165623"></a><a name="p47285002165623"></a><a href="ability_connection-h.md">ability_connection.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1634757145165623"><a name="p1634757145165623"></a><a name="p1634757145165623"></a>Declares callbacks to be invoked when a remote <a href="service.md">Service</a> ability is connected or disconnected. </p>
</td>
</tr>
<tr id="row1812005869165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1827920885165623"><a name="p1827920885165623"></a><a name="p1827920885165623"></a><a href="ability_context-h.md">ability_context.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1185466458165623"><a name="p1185466458165623"></a><a name="p1185466458165623"></a>Declares functions for starting and stopping an ability. </p>
</td>
</tr>
<tr id="row1908337349165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1906898267165623"><a name="p1906898267165623"></a><a name="p1906898267165623"></a><a href="ability_env-h.md">ability_env.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1420429572165623"><a name="p1420429572165623"></a><a name="p1420429572165623"></a>Declares functions for obtaining information about the runtime environment of the application to which the ability belongs, including the bundle name, source code path, and data path. </p>
</td>
</tr>
<tr id="row602284681165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p886871772165623"><a name="p886871772165623"></a><a name="p886871772165623"></a><a href="ability_errors-h.md">ability_errors.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p157786405165623"><a name="p157786405165623"></a><a name="p157786405165623"></a>Declares error codes returned by ability management functions. </p>
</td>
</tr>
<tr id="row528453078165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p536445523165623"><a name="p536445523165623"></a><a name="p536445523165623"></a><a href="ability_event_handler-h.md">ability_event_handler.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1185479816165623"><a name="p1185479816165623"></a><a name="p1185479816165623"></a>Declares functions for performing operations during inter-thread communication, including running and quitting the event loop of the current thread and posting tasks to an asynchronous thread. </p>
</td>
</tr>
<tr id="row881442514165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p540680237165623"><a name="p540680237165623"></a><a name="p540680237165623"></a><a href="ability_loader-h.md">ability_loader.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p519986597165623"><a name="p519986597165623"></a><a name="p519986597165623"></a>Declares functions for registering the class names of <strong id="b1437962188165623"><a name="b1437962188165623"></a><a name="b1437962188165623"></a>Ability</strong> and <strong id="b1078813795165623"><a name="b1078813795165623"></a><a name="b1078813795165623"></a>AbilitySlice</strong> with the ability management framework. </p>
</td>
</tr>
<tr id="row783989250165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1182863420165623"><a name="p1182863420165623"></a><a name="p1182863420165623"></a><a href="ability_manager-h.md">ability_manager.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1345472168165623"><a name="p1345472168165623"></a><a name="p1345472168165623"></a>Declares ability-related functions, including functions for starting, stopping, connecting to, and disconnecting from an ability, registering a callback, and unregistering a callback. </p>
</td>
</tr>
<tr id="row634276738165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p471951759165623"><a name="p471951759165623"></a><a name="p471951759165623"></a><a href="ability_slice-h.md">ability_slice.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p48287763165623"><a name="p48287763165623"></a><a name="p48287763165623"></a>Declares ability slice-related functions, including ability slice lifecycle callbacks and functions for connecting to or disconnecting from ability slices. </p>
</td>
</tr>
<tr id="row2066555927165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1071784249165623"><a name="p1071784249165623"></a><a name="p1071784249165623"></a><a href="ability_state-h.md">ability_state.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1887687121165623"><a name="p1887687121165623"></a><a name="p1887687121165623"></a>Declares ability-related functions, including ability lifecycle callbacks and functions for connecting to or disconnecting from Particle Abilities. As the fundamental unit of OpenHarmony applications, abilities are classified into <a href="feature.md">Feature</a> Abilities and Particle Abilities. <a href="feature.md">Feature</a> Abilities support the Page template, and Particle Abilities support the <a href="service.md">Service</a> template. An ability using the Page template is called a Page ability for short and that using the <a href="service.md">Service</a> template is called a <a href="service.md">Service</a> ability. </p>
</td>
</tr>
<tr id="row1763037614165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1854190489165623"><a name="p1854190489165623"></a><a name="p1854190489165623"></a><a href="want-h.md">want.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1503925968165623"><a name="p1503925968165623"></a><a name="p1503925968165623"></a>Declares the structure that provides abstract description of the operation to be performed, including the ability information and the carried data, and functions for setting data in the structure. </p>
</td>
</tr>
</tbody>
</table>

## Data Structures<a name="nested-classes"></a>

<a name="table1347462441165623"></a>
<table><thead align="left"><tr id="row1108840585165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p341968454165623"><a name="p341968454165623"></a><a name="p341968454165623"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p716963118165623"><a name="p716963118165623"></a><a name="p716963118165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row978813801165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p490572705165623"><a name="p490572705165623"></a><a name="p490572705165623"></a><a href="ohos-ability.md">OHOS::Ability</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p839714125165623"><a name="p839714125165623"></a><a name="p839714125165623"></a>Declares ability-related functions, including ability lifecycle callbacks and functions for connecting to or disconnecting from Particle Abilities. </p>
</td>
</tr>
<tr id="row1621150401165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p513144426165623"><a name="p513144426165623"></a><a name="p513144426165623"></a><a href="iabilityconnection.md">IAbilityConnection</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p318984509165623"><a name="p318984509165623"></a><a name="p318984509165623"></a>Provides callbacks to be invoked when a remote <a href="service.md">Service</a> ability is connected or disconnected. </p>
</td>
</tr>
<tr id="row978690111165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1372638095165623"><a name="p1372638095165623"></a><a name="p1372638095165623"></a><a href="ohos-abilitycontext.md">OHOS::AbilityContext</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2050799819165623"><a name="p2050799819165623"></a><a name="p2050799819165623"></a>Provides functions for starting and stopping an ability. </p>
</td>
</tr>
<tr id="row1967357444165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2076330370165623"><a name="p2076330370165623"></a><a name="p2076330370165623"></a><a href="ohos-abilityeventhandler.md">OHOS::AbilityEventHandler</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1652428203165623"><a name="p1652428203165623"></a><a name="p1652428203165623"></a>Declares functions for performing operations during inter-thread communication, including running and quitting the event loop of the current thread and posting tasks to an asynchronous thread. </p>
</td>
</tr>
<tr id="row1676933322165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p880190676165623"><a name="p880190676165623"></a><a name="p880190676165623"></a><a href="ohos-abilityloader.md">OHOS::AbilityLoader</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p293527311165623"><a name="p293527311165623"></a><a name="p293527311165623"></a>Declares functions for registering the class names of <a href="ohos-ability.md">Ability</a> and <a href="ohos-abilityslice.md">AbilitySlice</a> with the ability management framework. </p>
</td>
</tr>
<tr id="row808996378165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1205038970165623"><a name="p1205038970165623"></a><a name="p1205038970165623"></a><a href="ohos-abilityslice.md">OHOS::AbilitySlice</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p908656541165623"><a name="p908656541165623"></a><a name="p908656541165623"></a>Provides ability slice-related functions, including ability slice lifecycle callbacks and functions for connecting to or disconnecting from ability slices. </p>
</td>
</tr>
<tr id="row312459057165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1858331898165623"><a name="p1858331898165623"></a><a name="p1858331898165623"></a><a href="want.md">Want</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1709616198165623"><a name="p1709616198165623"></a><a name="p1709616198165623"></a>Defines the abstract description of an operation, including information about the ability and the extra data to carry. </p>
</td>
</tr>
</tbody>
</table>

## Macros<a name="define-members"></a>

<a name="table2019695592165623"></a>
<table><thead align="left"><tr id="row833209664165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1647154782165623"><a name="p1647154782165623"></a><a name="p1647154782165623"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p267647956165623"><a name="p267647956165623"></a><a name="p267647956165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row478117457165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p489255752165623"><a name="p489255752165623"></a><a name="p489255752165623"></a><a href="abilitykit.md#ga2c5bd891b502a92f937ae4bff3f80cad">REGISTER_AA</a>(className)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p535311278165623"><a name="p535311278165623"></a><a name="p535311278165623"></a>Registers the class name of an <strong id="b670514034165623"><a name="b670514034165623"></a><a name="b670514034165623"></a>Ability</strong> child class. </p>
</td>
</tr>
<tr id="row16460847165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p740657326165623"><a name="p740657326165623"></a><a name="p740657326165623"></a><a href="abilitykit.md#ga8e811999b2b7780e67cb746d045ab5b8">REGISTER_AS</a>(className)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1395532682165623"><a name="p1395532682165623"></a><a name="p1395532682165623"></a>Registers the class name of an <strong id="b805260073165623"><a name="b805260073165623"></a><a name="b805260073165623"></a>AbilitySlice</strong> child class. </p>
</td>
</tr>
</tbody>
</table>

## Enumerations<a name="enum-members"></a>

<a name="table132497443165623"></a>
<table><thead align="left"><tr id="row1790849804165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p244281591165623"><a name="p244281591165623"></a><a name="p244281591165623"></a>Enumeration Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1366719348165623"><a name="p1366719348165623"></a><a name="p1366719348165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1421426558165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1326435428165623"><a name="p1326435428165623"></a><a name="p1326435428165623"></a>{   <a href="abilitykit.md#gga99fb83031ce9923c84392b4e92f956b5aa26c163b80b1f6786ca81dadc14b00fb">ERR_OK</a> = 0, <a href="abilitykit.md#gga99fb83031ce9923c84392b4e92f956b5aa07793543807276aa96a35f35385266e">PARAM_NULL_ERROR</a>, <a href="abilitykit.md#gga99fb83031ce9923c84392b4e92f956b5ac6fa7d9ef451bee4ccabaf54a2d1dfc2">MEMORY_MALLOC_ERROR</a>, <a href="abilitykit.md#gga99fb83031ce9923c84392b4e92f956b5a9d4a52497266a38e4636693bb6cf965c">DUMP_ABILITIES_ERROR</a>,   <a href="abilitykit.md#gga99fb83031ce9923c84392b4e92f956b5a95357b37369351e52b2244efb3af4cbc">IPC_REQUEST_ERROR</a>, <a href="abilitykit.md#gga99fb83031ce9923c84392b4e92f956b5a05d12b70f719b309d4c6234a6bbc4214">SERIALIZE_ERROR</a>, <a href="abilitykit.md#gga99fb83031ce9923c84392b4e92f956b5a0cfd5af1f777f6919ddef94e81b94b00">COMMAND_ERROR</a> = 0x7fff }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p97626977165623"><a name="p97626977165623"></a><a name="p97626977165623"></a>Declares error codes returned by ability management functions. </p>
</td>
</tr>
<tr id="row1989366239165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1013026050165623"><a name="p1013026050165623"></a><a name="p1013026050165623"></a><a href="abilitykit.md#ga5d74787dedbc4e11c1ab15bf487e61f8">State</a> {   <a href="abilitykit.md#gga5d74787dedbc4e11c1ab15bf487e61f8a36e8e2958c7f6a4505cb8e8782717530">STATE_UNINITIALIZED</a>, <a href="abilitykit.md#gga5d74787dedbc4e11c1ab15bf487e61f8a24ac4e25affdf1bcda765d59e6cabcfd">STATE_INITIAL</a>, <a href="abilitykit.md#gga5d74787dedbc4e11c1ab15bf487e61f8a39e9fc11b119db5acccb179004077657">STATE_INACTIVE</a>, <a href="abilitykit.md#gga5d74787dedbc4e11c1ab15bf487e61f8a5f1f347a14f3373f19eb61973636f1a6">STATE_ACTIVE</a>,   <a href="abilitykit.md#gga5d74787dedbc4e11c1ab15bf487e61f8a701f6c0d2f4df7e2e37b07dacd0f514c">STATE_BACKGROUND</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p725352073165623"><a name="p725352073165623"></a><a name="p725352073165623"></a>Enumerates all lifecycle states that an ability will go through over the course of its lifetime. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1674905132165623"></a>
<table><thead align="left"><tr id="row1394685314165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1845377325165623"><a name="p1845377325165623"></a><a name="p1845377325165623"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1776444932165623"><a name="p1776444932165623"></a><a name="p1776444932165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row307802068165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1433287338165623"><a name="p1433287338165623"></a><a name="p1433287338165623"></a><a href="abilitykit.md#ga4d016d42397f33c7710db8544581c757">OHOS::Ability::OnStart</a> (const <a href="want.md">Want</a> &amp;want)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1075556817165623"><a name="p1075556817165623"></a><a name="p1075556817165623"></a>virtual void </p>
<p id="p820659720165623"><a name="p820659720165623"></a><a name="p820659720165623"></a>Called when this ability is started. You must override this function if you want to perform some initialization operations during ability startup. </p>
</td>
</tr>
<tr id="row1493613537165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p955579507165623"><a name="p955579507165623"></a><a name="p955579507165623"></a><a href="abilitykit.md#gae251a38aa7c0aebd7498eef86deab7c1">OHOS::Ability::OnInactive</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1522028187165623"><a name="p1522028187165623"></a><a name="p1522028187165623"></a>virtual void </p>
<p id="p365465704165623"><a name="p365465704165623"></a><a name="p365465704165623"></a>Called when this ability enters the <strong id="b1204688067165623"><a name="b1204688067165623"></a><a name="b1204688067165623"></a>STATE_INACTIVE</strong> state. </p>
</td>
</tr>
<tr id="row2007774530165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p784854989165623"><a name="p784854989165623"></a><a name="p784854989165623"></a><a href="abilitykit.md#ga3135bfa435f5aaa185f21014a9e86e59">OHOS::Ability::OnActive</a> (const <a href="want.md">Want</a> &amp;want)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2101750338165623"><a name="p2101750338165623"></a><a name="p2101750338165623"></a>virtual void </p>
<p id="p2055845547165623"><a name="p2055845547165623"></a><a name="p2055845547165623"></a>Called when this ability enters the <strong id="b1680806017165623"><a name="b1680806017165623"></a><a name="b1680806017165623"></a>STATE_ACTIVE</strong> state. </p>
</td>
</tr>
<tr id="row178321140165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p779396198165623"><a name="p779396198165623"></a><a name="p779396198165623"></a><a href="abilitykit.md#ga8185ad517d94ca99a00917d3d1f10620">OHOS::Ability::OnBackground</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1983370204165623"><a name="p1983370204165623"></a><a name="p1983370204165623"></a>virtual void </p>
<p id="p267595261165623"><a name="p267595261165623"></a><a name="p267595261165623"></a>Called when this ability enters the <strong id="b791796271165623"><a name="b791796271165623"></a><a name="b791796271165623"></a>STATE_BACKGROUND</strong> state. </p>
</td>
</tr>
<tr id="row1347296564165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1365293017165623"><a name="p1365293017165623"></a><a name="p1365293017165623"></a><a href="abilitykit.md#gaa4145b360bbe5cdb5d267b17ac12af6a">OHOS::Ability::OnStop</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p573296167165623"><a name="p573296167165623"></a><a name="p573296167165623"></a>virtual void </p>
<p id="p1718104601165623"><a name="p1718104601165623"></a><a name="p1718104601165623"></a>Called when this ability enters the <strong id="b793729919165623"><a name="b793729919165623"></a><a name="b793729919165623"></a>STATE_STOP</strong> state. </p>
</td>
</tr>
<tr id="row1227001436165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1561557040165623"><a name="p1561557040165623"></a><a name="p1561557040165623"></a><a href="abilitykit.md#ga88e9dbaaa083be9f06adeea27680ef76">OHOS::Ability::OnConnect</a> (const <a href="want.md">Want</a> &amp;want)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p814713829165623"><a name="p814713829165623"></a><a name="p814713829165623"></a>virtual const SvcIdentity * </p>
<p id="p292302214165623"><a name="p292302214165623"></a><a name="p292302214165623"></a>Called when this <a href="service.md">Service</a> ability is connected for the first time. </p>
</td>
</tr>
<tr id="row172129291165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p36897663165623"><a name="p36897663165623"></a><a name="p36897663165623"></a><a href="abilitykit.md#gac17d2b81d661134b63ee74b0212eace6">OHOS::Ability::OnDisconnect</a> (const <a href="want.md">Want</a> &amp;want)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p320806758165623"><a name="p320806758165623"></a><a name="p320806758165623"></a>virtual void </p>
<p id="p1789351705165623"><a name="p1789351705165623"></a><a name="p1789351705165623"></a>Called when all abilities connected to this <a href="service.md">Service</a> ability are disconnected. </p>
</td>
</tr>
<tr id="row482129353165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p71650165165623"><a name="p71650165165623"></a><a name="p71650165165623"></a><a href="abilitykit.md#gac83a9af046458b7f6bfaf85071b093f4">OHOS::Ability::SetMainRoute</a> (const std::string &amp;<a href="entry.md">entry</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p684279815165623"><a name="p684279815165623"></a><a name="p684279815165623"></a>void </p>
<p id="p239120040165623"><a name="p239120040165623"></a><a name="p239120040165623"></a>Sets the main route for this ability. </p>
</td>
</tr>
<tr id="row781730410165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p173679398165623"><a name="p173679398165623"></a><a name="p173679398165623"></a><a href="abilitykit.md#ga9b734c2ad8ad52f906d676f0c897a4aa">OHOS::Ability::SetUIContent</a> (<a href="ohos-rootview.md">RootView</a> *rootView)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p52805201165623"><a name="p52805201165623"></a><a name="p52805201165623"></a>void </p>
<p id="p125559223165623"><a name="p125559223165623"></a><a name="p125559223165623"></a>Sets the UI layout for this ability. You can call <strong id="b547931407165623"><a name="b547931407165623"></a><a name="b547931407165623"></a>GetWindowRootView()</strong> to create a layout and add controls. </p>
</td>
</tr>
<tr id="row767464668165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1725427435165623"><a name="p1725427435165623"></a><a name="p1725427435165623"></a><a href="abilitykit.md#gab2d208621c7236c3608afb77d8a02966">OHOS::Ability::MsgHandle</a> (uint32_t funcId, IpcIo *request, IpcIo *reply)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p526416364165623"><a name="p526416364165623"></a><a name="p526416364165623"></a>virtual void </p>
<p id="p330434211165623"><a name="p330434211165623"></a><a name="p330434211165623"></a>Handles a message sent by the client to this <a href="service.md">Service</a> ability. </p>
</td>
</tr>
<tr id="row1552521646165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p166659657165623"><a name="p166659657165623"></a><a name="p166659657165623"></a><a href="abilitykit.md#ga5330624843c776ebe61366540d32eb92">OHOS::Ability::Dump</a> (const std::string &amp;extra)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1457790550165623"><a name="p1457790550165623"></a><a name="p1457790550165623"></a>virtual void </p>
<p id="p1841907472165623"><a name="p1841907472165623"></a><a name="p1841907472165623"></a>Prints ability information to the console. </p>
</td>
</tr>
<tr id="row1448532365165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1080174251165623"><a name="p1080174251165623"></a><a name="p1080174251165623"></a><a href="abilitykit.md#gab11d708d5eaa1eca54828fa88625681a">OHOS::AbilityContext::StartAbility</a> (const <a href="want.md">Want</a> &amp;want)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1052709795165623"><a name="p1052709795165623"></a><a name="p1052709795165623"></a>int </p>
<p id="p1699458838165623"><a name="p1699458838165623"></a><a name="p1699458838165623"></a>Starts an <a href="ohos-ability.md">Ability</a> based on the specified <a href="want.md">Want</a> information. </p>
</td>
</tr>
<tr id="row643814690165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p422017025165623"><a name="p422017025165623"></a><a name="p422017025165623"></a><a href="abilitykit.md#gadc670d5f6df0d485ee3062b70b3ffe99">OHOS::AbilityContext::StopAbility</a> (const <a href="want.md">Want</a> &amp;want)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2133973370165623"><a name="p2133973370165623"></a><a name="p2133973370165623"></a>int </p>
<p id="p1930940912165623"><a name="p1930940912165623"></a><a name="p1930940912165623"></a>Stops an <a href="ohos-ability.md">Ability</a> based on the specified <a href="want.md">Want</a> information. </p>
</td>
</tr>
<tr id="row1126909395165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p888996718165623"><a name="p888996718165623"></a><a name="p888996718165623"></a><a href="abilitykit.md#gac4a36f03c60fcbeca3b47192ccab1d24">OHOS::AbilityContext::TerminateAbility</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1744242590165623"><a name="p1744242590165623"></a><a name="p1744242590165623"></a>int </p>
<p id="p2138606822165623"><a name="p2138606822165623"></a><a name="p2138606822165623"></a>Destroys this <a href="ohos-ability.md">Ability</a>. </p>
</td>
</tr>
<tr id="row1004611554165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1292945106165623"><a name="p1292945106165623"></a><a name="p1292945106165623"></a><a href="abilitykit.md#ga4da460ac085a8da1c665f317fcde2ba1">OHOS::AbilityContext::ConnectAbility</a> (const <a href="want.md">Want</a> &amp;want, const <a href="iabilityconnection.md">IAbilityConnection</a> &amp;conn, void *data)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p476627795165623"><a name="p476627795165623"></a><a name="p476627795165623"></a>int </p>
<p id="p1530048262165623"><a name="p1530048262165623"></a><a name="p1530048262165623"></a>Connects to a <a href="service.md">Service</a> ability based on the specified <a href="want.md">Want</a> information. </p>
</td>
</tr>
<tr id="row1161900781165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p936006020165623"><a name="p936006020165623"></a><a name="p936006020165623"></a><a href="abilitykit.md#ga1d9023597a9889dbb4015565a10f3470">OHOS::AbilityContext::DisconnectAbility</a> (const <a href="iabilityconnection.md">IAbilityConnection</a> &amp;conn)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1234025924165623"><a name="p1234025924165623"></a><a name="p1234025924165623"></a>int </p>
<p id="p94430054165623"><a name="p94430054165623"></a><a name="p94430054165623"></a>Disconnects from a <a href="service.md">Service</a> ability. </p>
</td>
</tr>
<tr id="row1172915348165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1394487482165623"><a name="p1394487482165623"></a><a name="p1394487482165623"></a><a href="abilitykit.md#gac893d7c01fabee34f80294e3e026c37d">GetBundleName</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1524497374165623"><a name="p1524497374165623"></a><a name="p1524497374165623"></a>const char * </p>
<p id="p1827659410165623"><a name="p1827659410165623"></a><a name="p1827659410165623"></a>Obtains the bundle name of the application to which this ability belongs. </p>
</td>
</tr>
<tr id="row1471321190165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p103440102165623"><a name="p103440102165623"></a><a name="p103440102165623"></a><a href="abilitykit.md#ga7cead123e67bea6db8a34c8ae100e6c5">GetSrcPath</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1638728419165623"><a name="p1638728419165623"></a><a name="p1638728419165623"></a>const char * </p>
<p id="p2037273542165623"><a name="p2037273542165623"></a><a name="p2037273542165623"></a>Obtains the source code path of this ability. </p>
</td>
</tr>
<tr id="row487341996165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2050730666165623"><a name="p2050730666165623"></a><a name="p2050730666165623"></a><a href="abilitykit.md#ga9be6a002714f3fb61b2335dd13ed9787">GetDataPath</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p948243482165623"><a name="p948243482165623"></a><a name="p948243482165623"></a>const char * </p>
<p id="p124545862165623"><a name="p124545862165623"></a><a name="p124545862165623"></a>Obtains the data path of this ability. </p>
</td>
</tr>
<tr id="row1398612745165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p680264823165623"><a name="p680264823165623"></a><a name="p680264823165623"></a>OHOS::AbilityEventHandler::Run ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p783021610165623"><a name="p783021610165623"></a><a name="p783021610165623"></a><strong id="gac534b1e3746d252944475b3ed9cb5bc7"><a name="gac534b1e3746d252944475b3ed9cb5bc7"></a><a name="gac534b1e3746d252944475b3ed9cb5bc7"></a></strong> void </p>
<p id="p631790500165623"><a name="p631790500165623"></a><a name="p631790500165623"></a>Starts running the event loop of the current thread. </p>
</td>
</tr>
<tr id="row1435460721165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1499937504165623"><a name="p1499937504165623"></a><a name="p1499937504165623"></a><a href="abilitykit.md#gad4d0911a8bccd5aca32464bad867cb13">OHOS::AbilityEventHandler::PostTask</a> (const Task &amp;task)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1060778239165623"><a name="p1060778239165623"></a><a name="p1060778239165623"></a>void </p>
<p id="p300420142165623"><a name="p300420142165623"></a><a name="p300420142165623"></a>Posts a task to an asynchronous thread. </p>
</td>
</tr>
<tr id="row689406080165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p85622922165623"><a name="p85622922165623"></a><a name="p85622922165623"></a>OHOS::AbilityEventHandler::PostQuit ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p925756796165623"><a name="p925756796165623"></a><a name="p925756796165623"></a><strong id="ga075bfbf9e5c9c2178f3183efd664dbaf"><a name="ga075bfbf9e5c9c2178f3183efd664dbaf"></a><a name="ga075bfbf9e5c9c2178f3183efd664dbaf"></a></strong> void </p>
<p id="p1194858927165623"><a name="p1194858927165623"></a><a name="p1194858927165623"></a>Quits the event loop of the current thread. </p>
</td>
</tr>
<tr id="row1755162659165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p25582482165623"><a name="p25582482165623"></a><a name="p25582482165623"></a><a href="abilitykit.md#gad26d144aaecd3185be6902e6d7399b9e">OHOS::AbilityEventHandler::GetCurrentHandler</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2007320631165623"><a name="p2007320631165623"></a><a name="p2007320631165623"></a>static <a href="ohos-abilityeventhandler.md">AbilityEventHandler</a> * </p>
<p id="p2141314716165623"><a name="p2141314716165623"></a><a name="p2141314716165623"></a>Obtains the event handler of the current thread. </p>
</td>
</tr>
<tr id="row1384603889165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1221031515165623"><a name="p1221031515165623"></a><a name="p1221031515165623"></a><a href="abilitykit.md#gae79800c4077afdc2851d5a74d8964111">StartAbility</a> (const <a href="want.md">Want</a> *want)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p689466763165623"><a name="p689466763165623"></a><a name="p689466763165623"></a>int </p>
<p id="p2105340558165623"><a name="p2105340558165623"></a><a name="p2105340558165623"></a>Starts an ability based on the specified <a href="want.md">Want</a> information. </p>
</td>
</tr>
<tr id="row1214955349165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p762293105165623"><a name="p762293105165623"></a><a name="p762293105165623"></a><a href="abilitykit.md#gaba99bbd4ff6da4fb072338f5ce95e6ae">StopAbility</a> (const <a href="want.md">Want</a> *want)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1508180600165623"><a name="p1508180600165623"></a><a name="p1508180600165623"></a>int </p>
<p id="p909184263165623"><a name="p909184263165623"></a><a name="p909184263165623"></a>Stops an ability based on the specified <a href="want.md">Want</a> information. </p>
</td>
</tr>
<tr id="row189820633165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1257919133165623"><a name="p1257919133165623"></a><a name="p1257919133165623"></a><a href="abilitykit.md#gaae6c2bbb6ab0df92e39c1daad2bd901f">ConnectAbility</a> (const <a href="want.md">Want</a> *want, const <a href="iabilityconnection.md">IAbilityConnection</a> *conn, void *data)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2041807164165623"><a name="p2041807164165623"></a><a name="p2041807164165623"></a>int </p>
<p id="p1104780210165623"><a name="p1104780210165623"></a><a name="p1104780210165623"></a>Connects to a <a href="service.md">Service</a> ability based on the specified <a href="want.md">Want</a> information. </p>
</td>
</tr>
<tr id="row2079123709165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1121079230165623"><a name="p1121079230165623"></a><a name="p1121079230165623"></a><a href="abilitykit.md#ga2769216a4c2654d3297a2fdb4011ea7a">DisconnectAbility</a> (const <a href="iabilityconnection.md">IAbilityConnection</a> *conn)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1192989931165623"><a name="p1192989931165623"></a><a name="p1192989931165623"></a>int </p>
<p id="p1124038636165623"><a name="p1124038636165623"></a><a name="p1124038636165623"></a>Disconnects from a <a href="service.md">Service</a> ability. </p>
</td>
</tr>
<tr id="row356960763165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p14169684165623"><a name="p14169684165623"></a><a name="p14169684165623"></a><a href="abilitykit.md#gad3ffda54b710b0b86e54bd6c13efae98">OHOS::AbilitySlice::OnStart</a> (const <a href="want.md">Want</a> &amp;want)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p467027924165623"><a name="p467027924165623"></a><a name="p467027924165623"></a>virtual void </p>
<p id="p2041533214165623"><a name="p2041533214165623"></a><a name="p2041533214165623"></a>Called when this ability slice is started. You must override this function if you want to perform some initialization operations during ability slice startup. </p>
</td>
</tr>
<tr id="row351449551165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1331928644165623"><a name="p1331928644165623"></a><a name="p1331928644165623"></a><a href="abilitykit.md#gae050b00aa885765bb6808374be772615">OHOS::AbilitySlice::OnInactive</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1912900876165623"><a name="p1912900876165623"></a><a name="p1912900876165623"></a>virtual void </p>
<p id="p1146856475165623"><a name="p1146856475165623"></a><a name="p1146856475165623"></a>Called when this ability slice enters the <strong id="b825517646165623"><a name="b825517646165623"></a><a name="b825517646165623"></a>STATE_INACTIVE</strong> state. </p>
</td>
</tr>
<tr id="row1126464179165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p241217229165623"><a name="p241217229165623"></a><a name="p241217229165623"></a><a href="abilitykit.md#ga1a588eb6635e42979e18ac8013f9ea61">OHOS::AbilitySlice::OnActive</a> (const <a href="want.md">Want</a> &amp;want)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1813904747165623"><a name="p1813904747165623"></a><a name="p1813904747165623"></a>virtual void </p>
<p id="p400809368165623"><a name="p400809368165623"></a><a name="p400809368165623"></a>Called when this ability slice enters the <strong id="b369780187165623"><a name="b369780187165623"></a><a name="b369780187165623"></a>STATE_ACTIVE</strong> state. </p>
</td>
</tr>
<tr id="row302969460165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1387008534165623"><a name="p1387008534165623"></a><a name="p1387008534165623"></a><a href="abilitykit.md#ga19217479f8468b525460be156827a524">OHOS::AbilitySlice::OnBackground</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1670185078165623"><a name="p1670185078165623"></a><a name="p1670185078165623"></a>virtual void </p>
<p id="p29896705165623"><a name="p29896705165623"></a><a name="p29896705165623"></a>Called when this ability slice enters the <strong id="b2074062338165623"><a name="b2074062338165623"></a><a name="b2074062338165623"></a>STATE_BACKGROUND</strong> state. </p>
</td>
</tr>
<tr id="row748461406165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p133720895165623"><a name="p133720895165623"></a><a name="p133720895165623"></a><a href="abilitykit.md#ga4e1556b780a1271e61328e659fc30eb9">OHOS::AbilitySlice::OnStop</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p928189576165623"><a name="p928189576165623"></a><a name="p928189576165623"></a>virtual void </p>
<p id="p1613156540165623"><a name="p1613156540165623"></a><a name="p1613156540165623"></a>Called when this ability slice enters the <strong id="b1530940669165623"><a name="b1530940669165623"></a><a name="b1530940669165623"></a>STATE_STOP</strong> state. </p>
</td>
</tr>
<tr id="row591774919165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1029755326165623"><a name="p1029755326165623"></a><a name="p1029755326165623"></a><a href="abilitykit.md#gab2ec8b885edd0d5818b4c60541c1875f">OHOS::AbilitySlice::Present</a> (<a href="ohos-abilityslice.md">AbilitySlice</a> &amp;abilitySlice, const <a href="want.md">Want</a> &amp;want)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1057859398165623"><a name="p1057859398165623"></a><a name="p1057859398165623"></a>void </p>
<p id="p2009403422165623"><a name="p2009403422165623"></a><a name="p2009403422165623"></a>Presents another ability slice, which can be an ability slice that is not started or an existing ability slice in the host ability. </p>
</td>
</tr>
<tr id="row401360811165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1856877509165623"><a name="p1856877509165623"></a><a name="p1856877509165623"></a><a href="abilitykit.md#gaf424e47c7980ff92093c6b7b75888639">OHOS::AbilitySlice::Terminate</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2092593347165623"><a name="p2092593347165623"></a><a name="p2092593347165623"></a>void </p>
<p id="p51721113165623"><a name="p51721113165623"></a><a name="p51721113165623"></a>Destroys this ability slice. </p>
</td>
</tr>
<tr id="row1633942634165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1644142564165623"><a name="p1644142564165623"></a><a name="p1644142564165623"></a><a href="abilitykit.md#ga050a81cda49edb471594447f8f4cdaac">OHOS::AbilitySlice::SetUIContent</a> (<a href="ohos-rootview.md">RootView</a> *rootView)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p438968625165623"><a name="p438968625165623"></a><a name="p438968625165623"></a>void </p>
<p id="p160551726165623"><a name="p160551726165623"></a><a name="p160551726165623"></a>Sets the UI layout for the host ability of this ability slice. </p>
</td>
</tr>
<tr id="row2121150620165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p710691943165623"><a name="p710691943165623"></a><a name="p710691943165623"></a><a href="abilitykit.md#ga62ca448e092c81497ffdd1f0b1c56938">ClearWant</a> (<a href="want.md">Want</a> *want)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p196042168165623"><a name="p196042168165623"></a><a name="p196042168165623"></a>void </p>
<p id="p1160845362165623"><a name="p1160845362165623"></a><a name="p1160845362165623"></a>Clears the memory of a specified <strong id="b629869106165623"><a name="b629869106165623"></a><a name="b629869106165623"></a><a href="want.md">Want</a></strong> object. </p>
</td>
</tr>
<tr id="row1690419627165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1113182788165623"><a name="p1113182788165623"></a><a name="p1113182788165623"></a><a href="abilitykit.md#ga65f4d2eab99497e496dcd493bd0d047e">SetWantElement</a> (<a href="want.md">Want</a> *want, <a href="elementname.md">ElementName</a> element)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1755443558165623"><a name="p1755443558165623"></a><a name="p1755443558165623"></a>bool </p>
<p id="p780727523165623"><a name="p780727523165623"></a><a name="p780727523165623"></a>Sets the <strong id="b1264266997165623"><a name="b1264266997165623"></a><a name="b1264266997165623"></a>element</strong> variable for a specified <strong id="b1590895620165623"><a name="b1590895620165623"></a><a name="b1590895620165623"></a><a href="want.md">Want</a></strong> object. </p>
</td>
</tr>
<tr id="row1416998876165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2000959709165623"><a name="p2000959709165623"></a><a name="p2000959709165623"></a><a href="abilitykit.md#ga89a719b5f730bc5fde9f637a5ed630c9">SetWantData</a> (<a href="want.md">Want</a> *want, const void *data, uint16_t dataLength)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p47065002165623"><a name="p47065002165623"></a><a name="p47065002165623"></a>bool </p>
<p id="p16102689165623"><a name="p16102689165623"></a><a name="p16102689165623"></a>Sets data to carry in a specified <strong id="b1049787133165623"><a name="b1049787133165623"></a><a name="b1049787133165623"></a><a href="want.md">Want</a></strong> object for starting a particular ability. </p>
</td>
</tr>
<tr id="row1591572738165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2080776610165623"><a name="p2080776610165623"></a><a name="p2080776610165623"></a><a href="abilitykit.md#gab8e5fac952fc6407f20cd9b7185d3a65">SetWantSvcIdentity</a> (<a href="want.md">Want</a> *want, SvcIdentity sid)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1343059581165623"><a name="p1343059581165623"></a><a name="p1343059581165623"></a>bool </p>
<p id="p1118503670165623"><a name="p1118503670165623"></a><a name="p1118503670165623"></a>Sets the <strong id="b1269317614165623"><a name="b1269317614165623"></a><a name="b1269317614165623"></a>sid</strong> member variable for a specified <strong id="b610713098165623"><a name="b610713098165623"></a><a name="b610713098165623"></a><a href="want.md">Want</a></strong> object. </p>
</td>
</tr>
<tr id="row358933255165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p18177394165623"><a name="p18177394165623"></a><a name="p18177394165623"></a><a href="abilitykit.md#ga31adc60981c10b22d0e9bbdc7126d17c">WantToUri</a> (<a href="want.md">Want</a> want)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1305782528165623"><a name="p1305782528165623"></a><a name="p1305782528165623"></a>const char * </p>
<p id="p2022027369165623"><a name="p2022027369165623"></a><a name="p2022027369165623"></a>Converts a specified <strong id="b2132598000165623"><a name="b2132598000165623"></a><a name="b2132598000165623"></a><a href="want.md">Want</a></strong> object into a character string. </p>
</td>
</tr>
<tr id="row596756417165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1774414990165623"><a name="p1774414990165623"></a><a name="p1774414990165623"></a><a href="abilitykit.md#ga43226d0858faa92e83bea33aaf4b614c">WantParseUri</a> (const char *uri)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1465631955165623"><a name="p1465631955165623"></a><a name="p1465631955165623"></a><a href="want.md">Want</a> * </p>
<p id="p891520569165623"><a name="p891520569165623"></a><a name="p891520569165623"></a>Converts a specified character string into a <strong id="b612904096165623"><a name="b612904096165623"></a><a name="b612904096165623"></a><a href="want.md">Want</a></strong> object. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section268415259165623"></a>

## **Macro Definition **<a name="section1597786070165623"></a>

## REGISTER\_AA<a name="ga2c5bd891b502a92f937ae4bff3f80cad"></a>

```
#define REGISTER_AA( className)
```

```
Values: __attribute__((constructor)) void RegisterAA##className() { \

 AbilityLoader::GetInstance().RegisterAbility(#className, []()->Ability* { \

 return new className; \

 }); \

 }


```

 **Description:**

Registers the class name of an  **Ability**  child class. 

After implementing your own  **Ability**  class, you should call this function so that the ability management framework can create  **Ability**  instances when loading your  **Ability**  class.

**Parameters:**

<a name="table166709373165623"></a>
<table><thead align="left"><tr id="row1463515091165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p931129222165623"><a name="p931129222165623"></a><a name="p931129222165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1732792284165623"><a name="p1732792284165623"></a><a name="p1732792284165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1755174233165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">className</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the <strong id="b1682177557165623"><a name="b1682177557165623"></a><a name="b1682177557165623"></a>Ability</strong> class name to register. </td>
</tr>
</tbody>
</table>

## REGISTER\_AS<a name="ga8e811999b2b7780e67cb746d045ab5b8"></a>

```
#define REGISTER_AS( className)
```

```
Values: __attribute__((constructor)) void RegisterAS##className() { \

 AbilityLoader::GetInstance().RegisterAbilitySlice(#className, []()->AbilitySlice* { \

 return new className; \

 }); \

 }


```

 **Description:**

Registers the class name of an  **AbilitySlice**  child class. 

After implementing your own  **AbilitySlice**  class, you should call this function so that the ability management framework can create  **AbilitySlice**  instances when loading your  **AbilitySlice**  class.

**Parameters:**

<a name="table1148257355165623"></a>
<table><thead align="left"><tr id="row2005940057165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1141836076165623"><a name="p1141836076165623"></a><a name="p1141836076165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p712013294165623"><a name="p712013294165623"></a><a name="p712013294165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row110848802165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">className</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the <strong id="b1380758259165623"><a name="b1380758259165623"></a><a name="b1380758259165623"></a>AbilitySlice</strong> class name to register. </td>
</tr>
</tbody>
</table>

## **Enumeration Type **<a name="section1266264770165623"></a>

## anonymous enum<a name="ga99fb83031ce9923c84392b4e92f956b5"></a>

```
anonymous enum
```

 **Description:**

Declares error codes returned by ability management functions. 

<a name="table1617103588165623"></a>
<table><thead align="left"><tr id="row647070971165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1996903110165623"><a name="p1996903110165623"></a><a name="p1996903110165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p437661934165623"><a name="p437661934165623"></a><a name="p437661934165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row302822728165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga99fb83031ce9923c84392b4e92f956b5aa26c163b80b1f6786ca81dadc14b00fb"><a name="gga99fb83031ce9923c84392b4e92f956b5aa26c163b80b1f6786ca81dadc14b00fb"></a><a name="gga99fb83031ce9923c84392b4e92f956b5aa26c163b80b1f6786ca81dadc14b00fb"></a></strong>ERR_OK </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p821360237165623"><a name="p821360237165623"></a><a name="p821360237165623"></a>The function is successfully called. </p>
 </td>
</tr>
<tr id="row1349644628165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga99fb83031ce9923c84392b4e92f956b5aa07793543807276aa96a35f35385266e"><a name="gga99fb83031ce9923c84392b4e92f956b5aa07793543807276aa96a35f35385266e"></a><a name="gga99fb83031ce9923c84392b4e92f956b5aa07793543807276aa96a35f35385266e"></a></strong>PARAM_NULL_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1607363648165623"><a name="p1607363648165623"></a><a name="p1607363648165623"></a>The parameter is null. </p>
 </td>
</tr>
<tr id="row285825083165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga99fb83031ce9923c84392b4e92f956b5ac6fa7d9ef451bee4ccabaf54a2d1dfc2"><a name="gga99fb83031ce9923c84392b4e92f956b5ac6fa7d9ef451bee4ccabaf54a2d1dfc2"></a><a name="gga99fb83031ce9923c84392b4e92f956b5ac6fa7d9ef451bee4ccabaf54a2d1dfc2"></a></strong>MEMORY_MALLOC_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1975256867165623"><a name="p1975256867165623"></a><a name="p1975256867165623"></a>Memory allocation error. </p>
 </td>
</tr>
<tr id="row661640034165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga99fb83031ce9923c84392b4e92f956b5a9d4a52497266a38e4636693bb6cf965c"><a name="gga99fb83031ce9923c84392b4e92f956b5a9d4a52497266a38e4636693bb6cf965c"></a><a name="gga99fb83031ce9923c84392b4e92f956b5a9d4a52497266a38e4636693bb6cf965c"></a></strong>DUMP_ABILITIES_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p280605933165623"><a name="p280605933165623"></a><a name="p280605933165623"></a>An error occurred during the execution of the <strong id="b355796750165623"><a name="b355796750165623"></a><a name="b355796750165623"></a>Dump</strong> function. </p>
 </td>
</tr>
<tr id="row1950823827165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga99fb83031ce9923c84392b4e92f956b5a95357b37369351e52b2244efb3af4cbc"><a name="gga99fb83031ce9923c84392b4e92f956b5a95357b37369351e52b2244efb3af4cbc"></a><a name="gga99fb83031ce9923c84392b4e92f956b5a95357b37369351e52b2244efb3af4cbc"></a></strong>IPC_REQUEST_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1738088570165623"><a name="p1738088570165623"></a><a name="p1738088570165623"></a>IPC request error. </p>
 </td>
</tr>
<tr id="row251001649165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga99fb83031ce9923c84392b4e92f956b5a05d12b70f719b309d4c6234a6bbc4214"><a name="gga99fb83031ce9923c84392b4e92f956b5a05d12b70f719b309d4c6234a6bbc4214"></a><a name="gga99fb83031ce9923c84392b4e92f956b5a05d12b70f719b309d4c6234a6bbc4214"></a></strong>SERIALIZE_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p151161265165623"><a name="p151161265165623"></a><a name="p151161265165623"></a>Serialization error. </p>
 </td>
</tr>
<tr id="row2129475501165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga99fb83031ce9923c84392b4e92f956b5a0cfd5af1f777f6919ddef94e81b94b00"><a name="gga99fb83031ce9923c84392b4e92f956b5a0cfd5af1f777f6919ddef94e81b94b00"></a><a name="gga99fb83031ce9923c84392b4e92f956b5a0cfd5af1f777f6919ddef94e81b94b00"></a></strong>COMMAND_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p34660101165623"><a name="p34660101165623"></a><a name="p34660101165623"></a>Command error. </p>
 </td>
</tr>
</tbody>
</table>

## State<a name="ga5d74787dedbc4e11c1ab15bf487e61f8"></a>

```
enum [State](abilitykit.md#ga5d74787dedbc4e11c1ab15bf487e61f8)
```

 **Description:**

Enumerates all lifecycle states that an ability will go through over the course of its lifetime. 

<a name="table779858884165623"></a>
<table><thead align="left"><tr id="row1281301548165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1596432673165623"><a name="p1596432673165623"></a><a name="p1596432673165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p866461964165623"><a name="p866461964165623"></a><a name="p866461964165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row870766126165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga5d74787dedbc4e11c1ab15bf487e61f8a36e8e2958c7f6a4505cb8e8782717530"><a name="gga5d74787dedbc4e11c1ab15bf487e61f8a36e8e2958c7f6a4505cb8e8782717530"></a><a name="gga5d74787dedbc4e11c1ab15bf487e61f8a36e8e2958c7f6a4505cb8e8782717530"></a></strong>STATE_UNINITIALIZED </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2062375306165623"><a name="p2062375306165623"></a><a name="p2062375306165623"></a>Uninitialized state: An ability is in this state when it has not been initialized after being created. </p>
 </td>
</tr>
<tr id="row1120584557165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga5d74787dedbc4e11c1ab15bf487e61f8a24ac4e25affdf1bcda765d59e6cabcfd"><a name="gga5d74787dedbc4e11c1ab15bf487e61f8a24ac4e25affdf1bcda765d59e6cabcfd"></a><a name="gga5d74787dedbc4e11c1ab15bf487e61f8a24ac4e25affdf1bcda765d59e6cabcfd"></a></strong>STATE_INITIAL </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p840000023165623"><a name="p840000023165623"></a><a name="p840000023165623"></a>Initial state: An ability is in this state after it is initialized or stopped. </p>
 </td>
</tr>
<tr id="row1785185675165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga5d74787dedbc4e11c1ab15bf487e61f8a39e9fc11b119db5acccb179004077657"><a name="gga5d74787dedbc4e11c1ab15bf487e61f8a39e9fc11b119db5acccb179004077657"></a><a name="gga5d74787dedbc4e11c1ab15bf487e61f8a39e9fc11b119db5acccb179004077657"></a></strong>STATE_INACTIVE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1521655505165623"><a name="p1521655505165623"></a><a name="p1521655505165623"></a>Inactive state: An ability is in this state when it is switched to the foreground but is not interactive. </p>
 </td>
</tr>
<tr id="row75917727165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga5d74787dedbc4e11c1ab15bf487e61f8a5f1f347a14f3373f19eb61973636f1a6"><a name="gga5d74787dedbc4e11c1ab15bf487e61f8a5f1f347a14f3373f19eb61973636f1a6"></a><a name="gga5d74787dedbc4e11c1ab15bf487e61f8a5f1f347a14f3373f19eb61973636f1a6"></a></strong>STATE_ACTIVE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p265824140165623"><a name="p265824140165623"></a><a name="p265824140165623"></a>Active state: An ability is in this state when it is switched to the foreground and is interactive. </p>
 </td>
</tr>
<tr id="row700640939165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga5d74787dedbc4e11c1ab15bf487e61f8a701f6c0d2f4df7e2e37b07dacd0f514c"><a name="gga5d74787dedbc4e11c1ab15bf487e61f8a701f6c0d2f4df7e2e37b07dacd0f514c"></a><a name="gga5d74787dedbc4e11c1ab15bf487e61f8a701f6c0d2f4df7e2e37b07dacd0f514c"></a></strong>STATE_BACKGROUND </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p845683894165623"><a name="p845683894165623"></a><a name="p845683894165623"></a>Background state: An ability is in this state after it returns to the background. </p>
 </td>
</tr>
</tbody>
</table>

## **Function **<a name="section1829026629165623"></a>

## ClearWant\(\)<a name="ga62ca448e092c81497ffdd1f0b1c56938"></a>

```
void ClearWant ([Want](want.md) * want)
```

 **Description:**

Clears the memory of a specified  **[Want](want.md)**  object. 

After calling functions such as  [SetWantElement](abilitykit.md#ga65f4d2eab99497e496dcd493bd0d047e), you should call this function to clear the memory.

**Parameters:**

<a name="table1373929252165623"></a>
<table><thead align="left"><tr id="row470401339165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p590635388165623"><a name="p590635388165623"></a><a name="p590635388165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p880335620165623"><a name="p880335620165623"></a><a name="p880335620165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1987847184165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">want</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the <strong id="b1500885093165623"><a name="b1500885093165623"></a><a name="b1500885093165623"></a><a href="want.md">Want</a></strong> object whose memory is to be released. </td>
</tr>
</tbody>
</table>

## ConnectAbility\(\) \[1/2\]<a name="ga4da460ac085a8da1c665f317fcde2ba1"></a>

```
int OHOS::AbilityContext::ConnectAbility (const [Want](want.md) & want, const [IAbilityConnection](iabilityconnection.md) & conn, void * data )
```

 **Description:**

Connects to a  [Service](service.md)  ability based on the specified  [Want](want.md)  information. 

After the  [Service](service.md)  ability is connected, the  [Ability](ohos-ability.md)  Manager  [Service](service.md)  invokes a particular callback and returns the ID of the  [Service](service.md)  ability. The client can use this ID to communicate with the connected  [Service](service.md)  ability.

**Parameters:**

<a name="table1939701001165623"></a>
<table><thead align="left"><tr id="row1765812816165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p779277165165623"><a name="p779277165165623"></a><a name="p779277165165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1916876969165623"><a name="p1916876969165623"></a><a name="p1916876969165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2000436102165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">want</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the <a href="want.md">Want</a> structure containing information about the <a href="service.md">Service</a> ability to connect. </td>
</tr>
<tr id="row995339552165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">conn</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the callback to be invoked when the connection is successful. </td>
</tr>
<tr id="row1177236031165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">data</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the data to be passed to the callback. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if this function is successfully called; returns another value otherwise. 

## ConnectAbility\(\) \[2/2\]<a name="gaae6c2bbb6ab0df92e39c1daad2bd901f"></a>

```
int ConnectAbility (const [Want](want.md) * want, const [IAbilityConnection](iabilityconnection.md) * conn, void * data )
```

 **Description:**

Connects to a  [Service](service.md)  ability based on the specified  [Want](want.md)  information. 

**Parameters:**

<a name="table2016308302165623"></a>
<table><thead align="left"><tr id="row226199228165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p795488497165623"><a name="p795488497165623"></a><a name="p795488497165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p967645606165623"><a name="p967645606165623"></a><a name="p967645606165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1878353148165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">want</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the <a href="want.md">Want</a> structure containing information about the <a href="service.md">Service</a> ability to connect. </td>
</tr>
<tr id="row1900426025165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">conn</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the callback object when the <a href="service.md">Service</a> ability is connected. </td>
</tr>
<tr id="row32658053165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">data</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the data to be passed to the callback. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if this function is successfully called; returns another value otherwise. 

## DisconnectAbility\(\) \[1/2\]<a name="ga1d9023597a9889dbb4015565a10f3470"></a>

```
int OHOS::AbilityContext::DisconnectAbility (const [IAbilityConnection](iabilityconnection.md) & conn)
```

 **Description:**

Disconnects from a  [Service](service.md)  ability. 

**Parameters:**

<a name="table1812720722165623"></a>
<table><thead align="left"><tr id="row1519286010165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1156288117165623"><a name="p1156288117165623"></a><a name="p1156288117165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1331771397165623"><a name="p1331771397165623"></a><a name="p1331771397165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2060428259165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">conn</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the callback to be invoked when the connection is successful. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if this function is successfully called; returns another value otherwise. 

## DisconnectAbility\(\) \[2/2\]<a name="ga2769216a4c2654d3297a2fdb4011ea7a"></a>

```
int DisconnectAbility (const [IAbilityConnection](iabilityconnection.md) * conn)
```

 **Description:**

Disconnects from a  [Service](service.md)  ability. 

**Parameters:**

<a name="table1618572644165623"></a>
<table><thead align="left"><tr id="row2101928856165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1508319038165623"><a name="p1508319038165623"></a><a name="p1508319038165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1445328333165623"><a name="p1445328333165623"></a><a name="p1445328333165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2120948130165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">conn</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the callback object when the <a href="service.md">Service</a> ability is connected. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if this function is successfully called; returns another value otherwise. 

## Dump\(\)<a name="ga5330624843c776ebe61366540d32eb92"></a>

```
virtual void OHOS::Ability::Dump (const std::string & extra)
```

 **Description:**

Prints ability information to the console. 

You can override this function to obtain or print extra parameters.

**Parameters:**

<a name="table982245886165623"></a>
<table><thead align="left"><tr id="row363988211165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p525323639165623"><a name="p525323639165623"></a><a name="p525323639165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1549813032165623"><a name="p1549813032165623"></a><a name="p1549813032165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row939982205165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">extra</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the extra parameter to be obtained or printed to the console. </td>
</tr>
</tbody>
</table>

## GetBundleName\(\)<a name="gac893d7c01fabee34f80294e3e026c37d"></a>

```
const char* GetBundleName ()
```

 **Description:**

Obtains the bundle name of the application to which this ability belongs. 

**Returns:**

Returns the pointer to the bundle name if the operation is successful; returns a null pointer otherwise. 

## GetCurrentHandler\(\)<a name="gad26d144aaecd3185be6902e6d7399b9e"></a>

```
static [AbilityEventHandler](ohos-abilityeventhandler.md)* OHOS::AbilityEventHandler::GetCurrentHandler ()
```

 **Description:**

Obtains the event handler of the current thread. 

**Returns:**

Returns the pointer to the  [AbilityEventHandler](ohos-abilityeventhandler.md)  object of the current thread. 

## GetDataPath\(\)<a name="ga9be6a002714f3fb61b2335dd13ed9787"></a>

```
const char* GetDataPath ()
```

 **Description:**

Obtains the data path of this ability. 

**Returns:**

Returns the pointer to the data path of this ability. 

## GetSrcPath\(\)<a name="ga7cead123e67bea6db8a34c8ae100e6c5"></a>

```
const char* GetSrcPath ()
```

 **Description:**

Obtains the source code path of this ability. 

**Returns:**

Returns the pointer to the source code path of this ability. 

## MsgHandle\(\)<a name="gab2d208621c7236c3608afb77d8a02966"></a>

```
virtual void OHOS::Ability::MsgHandle (uint32_t funcId, IpcIo * request, IpcIo * reply )
```

 **Description:**

Handles a message sent by the client to this  [Service](service.md)  ability. 

**Parameters:**

<a name="table2061832904165623"></a>
<table><thead align="left"><tr id="row1002036477165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1407680344165623"><a name="p1407680344165623"></a><a name="p1407680344165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p409767092165623"><a name="p409767092165623"></a><a name="p409767092165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1590596267165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">funcId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the type of the message sent by the client. </td>
</tr>
<tr id="row1219240198165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">request</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the serialized request parameters sent by the client. </td>
</tr>
<tr id="row1404922219165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">reply</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the serialized result returned to the client. </td>
</tr>
</tbody>
</table>

## OnActive\(\) \[1/2\]<a name="ga1a588eb6635e42979e18ac8013f9ea61"></a>

```
virtual void OHOS::AbilitySlice::OnActive (const [Want](want.md) & want)
```

 **Description:**

Called when this ability slice enters the  **STATE\_ACTIVE**  state. 

The ability slice in the  **STATE\_ACTIVE**  state is visible and has focus. You can override this function to implement your own processing logic.

**Parameters:**

<a name="table614842313165623"></a>
<table><thead align="left"><tr id="row26375556165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1728706632165623"><a name="p1728706632165623"></a><a name="p1728706632165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1736502165623"><a name="p1736502165623"></a><a name="p1736502165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1508217464165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">want</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the <a href="want.md">Want</a> structure containing activation information about the ability slice. </td>
</tr>
</tbody>
</table>

## OnActive\(\) \[2/2\]<a name="ga3135bfa435f5aaa185f21014a9e86e59"></a>

```
virtual void OHOS::Ability::OnActive (const [Want](want.md) & want)
```

 **Description:**

Called when this ability enters the  **STATE\_ACTIVE**  state. 

The ability in the  **STATE\_ACTIVE**  state is visible and has focus. You can override this function to implement your own processing logic.

**Parameters:**

<a name="table813459190165623"></a>
<table><thead align="left"><tr id="row461537270165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p878637112165623"><a name="p878637112165623"></a><a name="p878637112165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1303947841165623"><a name="p1303947841165623"></a><a name="p1303947841165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row731790700165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">want</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the <a href="want.md">Want</a> structure containing activation information about the ability. </td>
</tr>
</tbody>
</table>

## OnBackground\(\) \[1/2\]<a name="ga19217479f8468b525460be156827a524"></a>

```
virtual void OHOS::AbilitySlice::OnBackground ()
```

 **Description:**

Called when this ability slice enters the  **STATE\_BACKGROUND**  state. 

The ability slice in the  **STATE\_BACKGROUND**  state is invisible. You can override this function to implement your own processing logic. 

## OnBackground\(\) \[2/2\]<a name="ga8185ad517d94ca99a00917d3d1f10620"></a>

```
virtual void OHOS::Ability::OnBackground ()
```

 **Description:**

Called when this ability enters the  **STATE\_BACKGROUND**  state. 

The ability in the  **STATE\_BACKGROUND**  state is invisible. You can override this function to implement your own processing logic. 

## OnConnect\(\)<a name="ga88e9dbaaa083be9f06adeea27680ef76"></a>

```
virtual const SvcIdentity* OHOS::Ability::OnConnect (const [Want](want.md) & want)
```

 **Description:**

Called when this  [Service](service.md)  ability is connected for the first time. 

You can override this function to implement your own processing logic.

**Parameters:**

<a name="table1564044065165623"></a>
<table><thead align="left"><tr id="row280198659165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1213771074165623"><a name="p1213771074165623"></a><a name="p1213771074165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p448328913165623"><a name="p448328913165623"></a><a name="p448328913165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1565887410165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">want</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the <a href="want.md">Want</a> structure containing connection information about the <a href="service.md">Service</a> ability. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns a pointer to the  **sid**  of the connected  [Service](service.md)  ability. 

## OnDisconnect\(\)<a name="gac17d2b81d661134b63ee74b0212eace6"></a>

```
virtual void OHOS::Ability::OnDisconnect (const [Want](want.md) & want)
```

 **Description:**

Called when all abilities connected to this  [Service](service.md)  ability are disconnected. 

You can override this function to implement your own processing logic.

**Parameters:**

<a name="table1982135952165623"></a>
<table><thead align="left"><tr id="row212694337165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p757798666165623"><a name="p757798666165623"></a><a name="p757798666165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1703262542165623"><a name="p1703262542165623"></a><a name="p1703262542165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1948294043165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">want</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the <a href="want.md">Want</a> structure containing disconnection information about the <a href="service.md">Service</a> ability. </td>
</tr>
</tbody>
</table>

## OnInactive\(\) \[1/2\]<a name="gae050b00aa885765bb6808374be772615"></a>

```
virtual void OHOS::AbilitySlice::OnInactive ()
```

 **Description:**

Called when this ability slice enters the  **STATE\_INACTIVE**  state. 

**STATE\_INACTIVE**  is an instantaneous state. The ability slice in this state may be visible but does not have focus. You can override this function to implement your own processing logic. 

## OnInactive\(\) \[2/2\]<a name="gae251a38aa7c0aebd7498eef86deab7c1"></a>

```
virtual void OHOS::Ability::OnInactive ()
```

 **Description:**

Called when this ability enters the  **STATE\_INACTIVE**  state. 

**STATE\_INACTIVE**  is an instantaneous state. The ability in this state may be visible but does not have focus. You can override this function to implement your own processing logic. 

## OnStart\(\) \[1/2\]<a name="gad3ffda54b710b0b86e54bd6c13efae98"></a>

```
virtual void OHOS::AbilitySlice::OnStart (const [Want](want.md) & want)
```

 **Description:**

Called when this ability slice is started. You must override this function if you want to perform some initialization operations during ability slice startup. 

This function can be called only once in the entire lifecycle of an ability slice. You can override this function to implement your own processing logic. 

**Parameters:**

<a name="table1958686248165623"></a>
<table><thead align="left"><tr id="row1147040625165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p714736046165623"><a name="p714736046165623"></a><a name="p714736046165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1377949286165623"><a name="p1377949286165623"></a><a name="p1377949286165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row240462036165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">want</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the <a href="want.md">Want</a> structure containing startup information about the ability slice. </td>
</tr>
</tbody>
</table>

## OnStart\(\) \[2/2\]<a name="ga4d016d42397f33c7710db8544581c757"></a>

```
virtual void OHOS::Ability::OnStart (const [Want](want.md) & want)
```

 **Description:**

Called when this ability is started. You must override this function if you want to perform some initialization operations during ability startup. 

This function can be called only once in the entire lifecycle of an ability. 

**Parameters:**

<a name="table522634356165623"></a>
<table><thead align="left"><tr id="row158495962165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2115289405165623"><a name="p2115289405165623"></a><a name="p2115289405165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p24031222165623"><a name="p24031222165623"></a><a name="p24031222165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row808046980165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">want</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the <a href="want.md">Want</a> structure containing startup information about the ability. </td>
</tr>
</tbody>
</table>

## OnStop\(\) \[1/2\]<a name="ga4e1556b780a1271e61328e659fc30eb9"></a>

```
virtual void OHOS::AbilitySlice::OnStop ()
```

 **Description:**

Called when this ability slice enters the  **STATE\_STOP**  state. 

The ability slice in the  **STATE\_STOP**  state is being destroyed. You can override this function to implement your own processing logic. 

## OnStop\(\) \[2/2\]<a name="gaa4145b360bbe5cdb5d267b17ac12af6a"></a>

```
virtual void OHOS::Ability::OnStop ()
```

 **Description:**

Called when this ability enters the  **STATE\_STOP**  state. 

The ability in the  **STATE\_STOP**  is being destroyed. You can override this function to implement your own processing logic. 

## PostTask\(\)<a name="gad4d0911a8bccd5aca32464bad867cb13"></a>

```
void OHOS::AbilityEventHandler::PostTask (const Task & task)
```

 **Description:**

Posts a task to an asynchronous thread. 

**Parameters:**

<a name="table1697868363165623"></a>
<table><thead align="left"><tr id="row164933031165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1849517004165623"><a name="p1849517004165623"></a><a name="p1849517004165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p384664278165623"><a name="p384664278165623"></a><a name="p384664278165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row374021607165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">task</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the task to post. </td>
</tr>
</tbody>
</table>

## Present\(\)<a name="gab2ec8b885edd0d5818b4c60541c1875f"></a>

```
void OHOS::AbilitySlice::Present ([AbilitySlice](ohos-abilityslice.md) & abilitySlice, const [Want](want.md) & want )
```

 **Description:**

Presents another ability slice, which can be an ability slice that is not started or an existing ability slice in the host ability. 

**Parameters:**

<a name="table1429845087165623"></a>
<table><thead align="left"><tr id="row345079764165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1131378293165623"><a name="p1131378293165623"></a><a name="p1131378293165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p373541134165623"><a name="p373541134165623"></a><a name="p373541134165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row882770414165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">abilitySlice</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the target ability slice. This parameter cannot be null. </td>
</tr>
<tr id="row1142414331165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">want</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the <a href="want.md">Want</a> structure containing startup information about the target ability slice. </td>
</tr>
</tbody>
</table>

**Attention:**

This function can be called only when both of the following conditions are met: 

-    The host ability is in the  **STATE\_ACTIVE**  state. 
-    The target ability slice is not started or destroyed.

## SetMainRoute\(\)<a name="gac83a9af046458b7f6bfaf85071b093f4"></a>

```
void OHOS::Ability::SetMainRoute (const std::string & entry)
```

 **Description:**

Sets the main route for this ability. 

The main route, also called main entry, refers to the default  **[AbilitySlice](ohos-abilityslice.md)**  to present for this ability. This function should be called only on  [Feature](feature.md)  Abilities. If this function is not called in the  [OnStart\(const Want &want\)](abilitykit.md#ga4d016d42397f33c7710db8544581c757)  function for a  [Feature](feature.md) [Ability](ohos-ability.md), the  [Feature](feature.md) [Ability](ohos-ability.md)  will fail to start.

**Parameters:**

<a name="table933674329165623"></a>
<table><thead align="left"><tr id="row482874332165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p636795990165623"><a name="p636795990165623"></a><a name="p636795990165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p756993995165623"><a name="p756993995165623"></a><a name="p756993995165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row613801002165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">entry</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the main entry, which is the class name of the <strong id="b1761500752165623"><a name="b1761500752165623"></a><a name="b1761500752165623"></a><a href="ohos-abilityslice.md">AbilitySlice</a></strong> instance to start. </td>
</tr>
</tbody>
</table>

## SetUIContent\(\) \[1/2\]<a name="ga050a81cda49edb471594447f8f4cdaac"></a>

```
void OHOS::AbilitySlice::SetUIContent ([RootView](ohos-rootview.md) * rootView)
```

 **Description:**

Sets the UI layout for the host ability of this ability slice. 

You can call  **GetWindowRootView\(\)**  to create a layout and add controls.

**Parameters:**

<a name="table1602274157165623"></a>
<table><thead align="left"><tr id="row1027834328165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p894742433165623"><a name="p894742433165623"></a><a name="p894742433165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p444479405165623"><a name="p444479405165623"></a><a name="p444479405165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1274565244165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">rootView</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the custom layout view you have created. </td>
</tr>
</tbody>
</table>

## SetUIContent\(\) \[2/2\]<a name="ga9b734c2ad8ad52f906d676f0c897a4aa"></a>

```
void OHOS::Ability::SetUIContent ([RootView](ohos-rootview.md) * rootView)
```

 **Description:**

Sets the UI layout for this ability. You can call  **GetWindowRootView\(\)**  to create a layout and add controls. 

**Parameters:**

<a name="table1445484239165623"></a>
<table><thead align="left"><tr id="row1790463237165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p44979643165623"><a name="p44979643165623"></a><a name="p44979643165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p102891227165623"><a name="p102891227165623"></a><a name="p102891227165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row461703735165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">rootView</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the custom layout view you have created. </td>
</tr>
</tbody>
</table>

## SetWantData\(\)<a name="ga89a719b5f730bc5fde9f637a5ed630c9"></a>

```
bool SetWantData ([Want](want.md) * want, const void * data, uint16_t dataLength )
```

 **Description:**

Sets data to carry in a specified  **[Want](want.md)**  object for starting a particular ability. 

**Parameters:**

<a name="table1368875511165623"></a>
<table><thead align="left"><tr id="row344529369165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1550298268165623"><a name="p1550298268165623"></a><a name="p1550298268165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p130655330165623"><a name="p130655330165623"></a><a name="p130655330165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1723844677165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">want</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the <strong id="b1047481516165623"><a name="b1047481516165623"></a><a name="b1047481516165623"></a><a href="want.md">Want</a></strong> object to set. </td>
</tr>
<tr id="row1635434239165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">data</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the data to set. </td>
</tr>
<tr id="row97954041165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">dataLength</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the data length to set. The length must be the same as that of the data specified in <strong id="b1141234129165623"><a name="b1141234129165623"></a><a name="b1141234129165623"></a>data</strong>.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if the setting is successful; returns  **false**  otherwise. 

## SetWantElement\(\)<a name="ga65f4d2eab99497e496dcd493bd0d047e"></a>

```
bool SetWantElement ([Want](want.md) * want, [ElementName](elementname.md) element )
```

 **Description:**

Sets the  **element**  variable for a specified  **[Want](want.md)**  object. 

To start a specified ability, you should call this function to set the  [ElementName](elementname.md)  required for starting the ability.

**Parameters:**

<a name="table1634046269165623"></a>
<table><thead align="left"><tr id="row2046155881165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2032807256165623"><a name="p2032807256165623"></a><a name="p2032807256165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p16045398165623"><a name="p16045398165623"></a><a name="p16045398165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1931583542165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">want</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the <strong id="b544785363165623"><a name="b544785363165623"></a><a name="b544785363165623"></a><a href="want.md">Want</a></strong> object to set. </td>
</tr>
<tr id="row433301653165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">element</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the <a href="elementname.md">ElementName</a> containing information required for starting the ability.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if the setting is successful; returns  **false**  otherwise. 

## SetWantSvcIdentity\(\)<a name="gab8e5fac952fc6407f20cd9b7185d3a65"></a>

```
bool SetWantSvcIdentity ([Want](want.md) * want, SvcIdentity sid )
```

 **Description:**

Sets the  **sid**  member variable for a specified  **[Want](want.md)**  object. 

When starting an ability, you should call this function to set an  **SvcIdentity**  object if a callback needs to be invoked after the ability is started successfully.

**Parameters:**

<a name="table1704280301165623"></a>
<table><thead align="left"><tr id="row804734263165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1251934862165623"><a name="p1251934862165623"></a><a name="p1251934862165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p842507140165623"><a name="p842507140165623"></a><a name="p842507140165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1280616636165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">want</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the <strong id="b1164256281165623"><a name="b1164256281165623"></a><a name="b1164256281165623"></a><a href="want.md">Want</a></strong> object to set. </td>
</tr>
<tr id="row1562051619165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sid</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the <strong id="b1152895661165623"><a name="b1152895661165623"></a><a name="b1152895661165623"></a>SvcIdentity</strong> object to set.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if the setting is successful; returns  **false**  otherwise. 

## StartAbility\(\) \[1/2\]<a name="gab11d708d5eaa1eca54828fa88625681a"></a>

```
int OHOS::AbilityContext::StartAbility (const [Want](want.md) & want)
```

 **Description:**

Starts an  [Ability](ohos-ability.md)  based on the specified  [Want](want.md)  information. 

**Parameters:**

<a name="table816692212165623"></a>
<table><thead align="left"><tr id="row440983469165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p502354976165623"><a name="p502354976165623"></a><a name="p502354976165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1895715442165623"><a name="p1895715442165623"></a><a name="p1895715442165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1931879447165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">want</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the <a href="want.md">Want</a> structure containing information about the ability to start. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise. 

## StartAbility\(\) \[2/2\]<a name="gae79800c4077afdc2851d5a74d8964111"></a>

```
int StartAbility (const [Want](want.md) * want)
```

 **Description:**

Starts an ability based on the specified  [Want](want.md)  information. 

**Parameters:**

<a name="table244367342165623"></a>
<table><thead align="left"><tr id="row198123636165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p671290665165623"><a name="p671290665165623"></a><a name="p671290665165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p789194825165623"><a name="p789194825165623"></a><a name="p789194825165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row529868048165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">want</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the <a href="want.md">Want</a> structure containing information about the ability to start. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if this function is successfully called; returns another value otherwise. 

## StopAbility\(\) \[1/2\]<a name="gadc670d5f6df0d485ee3062b70b3ffe99"></a>

```
int OHOS::AbilityContext::StopAbility (const [Want](want.md) & want)
```

 **Description:**

Stops an  [Ability](ohos-ability.md)  based on the specified  [Want](want.md)  information. 

This function takes effect only on  [Service](service.md)  abilities.

**Parameters:**

<a name="table467960832165623"></a>
<table><thead align="left"><tr id="row259630777165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1708536763165623"><a name="p1708536763165623"></a><a name="p1708536763165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2081339192165623"><a name="p2081339192165623"></a><a name="p2081339192165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row462590798165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">want</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the <a href="want.md">Want</a> structure containing information about the ability to stop. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise. 

## StopAbility\(\) \[2/2\]<a name="gaba99bbd4ff6da4fb072338f5ce95e6ae"></a>

```
int StopAbility (const [Want](want.md) * want)
```

 **Description:**

Stops an ability based on the specified  [Want](want.md)  information. 

This function takes effect only on  [Service](service.md)  abilities.

**Parameters:**

<a name="table694135573165623"></a>
<table><thead align="left"><tr id="row128543528165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1800036134165623"><a name="p1800036134165623"></a><a name="p1800036134165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1869892193165623"><a name="p1869892193165623"></a><a name="p1869892193165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2085601309165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">want</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the <a href="want.md">Want</a> structure containing information about the ability to stop. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if this function is successfully called; returns another value otherwise. 

## Terminate\(\)<a name="gaf424e47c7980ff92093c6b7b75888639"></a>

```
void OHOS::AbilitySlice::Terminate ()
```

 **Description:**

Destroys this ability slice. 

This ability slice can call this function to destroy itself. If the ability slice to destroy is the only running one in the host ability, the host ability will also be destroyed. Otherwise, the host ability will not be affected. 

## TerminateAbility\(\)<a name="gac4a36f03c60fcbeca3b47192ccab1d24"></a>

```
int OHOS::AbilityContext::TerminateAbility ()
```

 **Description:**

Destroys this  [Ability](ohos-ability.md). 

This function can be called only by this ability.

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  otherwise. 

## WantParseUri\(\)<a name="ga43226d0858faa92e83bea33aaf4b614c"></a>

```
[Want](want.md)* WantParseUri (const char * uri)
```

 **Description:**

Converts a specified character string into a  **[Want](want.md)**  object. 

**Parameters:**

<a name="table1577371214165623"></a>
<table><thead align="left"><tr id="row137611667165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1702579122165623"><a name="p1702579122165623"></a><a name="p1702579122165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1455292388165623"><a name="p1455292388165623"></a><a name="p1455292388165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row908081884165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">uri</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the character string to convert.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the pointer to the converted  **[Want](want.md)**  object if the operation is successful; returns  **nullptr**  otherwise. 

## WantToUri\(\)<a name="ga31adc60981c10b22d0e9bbdc7126d17c"></a>

```
const char* WantToUri ([Want](want.md) want)
```

 **Description:**

Converts a specified  **[Want](want.md)**  object into a character string. 

**Parameters:**

<a name="table621406343165623"></a>
<table><thead align="left"><tr id="row1526644581165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1087752252165623"><a name="p1087752252165623"></a><a name="p1087752252165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p15056938165623"><a name="p15056938165623"></a><a name="p15056938165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row361297179165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">want</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the <strong id="b1543266955165623"><a name="b1543266955165623"></a><a name="b1543266955165623"></a><a href="want.md">Want</a></strong> object to convert.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the converted character string if the operation is successful; returns  **nullptr**  otherwise. 

## **Variable **<a name="section1912686851165623"></a>

## OnAbilityConnectDone<a name="ga3b9bfacbcf1564c83cffbfff7889998a"></a>

```
void(* IAbilityConnection::OnAbilityConnectDone) ([ElementName](elementname.md) *elementName, SvcIdentity *serviceSid, int resultCode, void *data)
```

 **Description:**

Called when a client is connected to a  [Service](service.md)  ability. 

This callback is invoked to receive the connection result after a client is connected to a  [Service](service.md)  ability.

**Parameters:**

<a name="table1183274249165623"></a>
<table><thead align="left"><tr id="row970627124165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2053156971165623"><a name="p2053156971165623"></a><a name="p2053156971165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1511333532165623"><a name="p1511333532165623"></a><a name="p1511333532165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2038109106165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">elementName</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the information about the connected <a href="service.md">Service</a> ability. </td>
</tr>
<tr id="row540713372165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">serviceSid</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the remote proxy object of the <a href="service.md">Service</a> ability. </td>
</tr>
<tr id="row1962322028165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">resultCode</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the connection result code. The value <strong id="b148724322165623"><a name="b148724322165623"></a><a name="b148724322165623"></a>0</strong> indicates a successful connection, and any other value indicates a connection failure. </td>
</tr>
<tr id="row1906320430165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">data</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the data stored during the connection. </td>
</tr>
</tbody>
</table>

## OnAbilityDisconnectDone<a name="gaba7cf0abb517890ef1a3949e398aaf1d"></a>

```
void(* IAbilityConnection::OnAbilityDisconnectDone) ([ElementName](elementname.md) *elementName, int resultCode, void *data)
```

 **Description:**

Called after all connections to a  [Service](service.md)  ability are disconnected. 

This callback is invoked to receive the disconnection result after the connected  [Service](service.md)  ability crashes or is killed. If the  [Service](service.md)  ability exits unexpectedly, all its connections are disconnected, and each ability previously connected to it will call  **OnAbilityDisconnectDone\(ElementName \*elementName, int resultCode, void \*data\)**.

**Parameters:**

<a name="table920796424165623"></a>
<table><thead align="left"><tr id="row2106554179165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2111531032165623"><a name="p2111531032165623"></a><a name="p2111531032165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p264911361165623"><a name="p264911361165623"></a><a name="p264911361165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row889277902165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">elementName</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the information about the disconnected <a href="service.md">Service</a> ability. </td>
</tr>
<tr id="row118796857165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">resultCode</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the disconnection result code. The value <strong id="b1194285719165623"><a name="b1194285719165623"></a><a name="b1194285719165623"></a>0</strong> indicates a successful disconnection, and any other value indicates a disconnection failure. </td>
</tr>
<tr id="row700439075165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">data</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the data stored during the connection. </td>
</tr>
</tbody>
</table>

