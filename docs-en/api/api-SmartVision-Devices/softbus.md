# Softbus<a name="EN-US_TOPIC_0000001055678044"></a>

-   [Overview](#section1320862849165623)
-   [Summary](#section1861030385165623)
-   [Files](#files)
-   [Data Structures](#nested-classes)
-   [Typedefs](#typedef-members)
-   [Enumerations](#enum-members)
-   [Functions](#func-members)
-   [Details](#section779093396165623)
-   [Typedef](#section357911583165623)
-   [CommonDeviceInfo](#ga8dc0eb993aea9593f96da339edf042ff)
-   [DeviceType](#ga9334bacb3ded964dc3c3367a6b70bcf4)
-   [IPublishCallback](#gab622f2f40d12121620d464e43635a09b)
-   [PublishInfo](#gae0bb52450c28ea9be1c5475d0d89830e)
-   [Enumeration Type](#section574907679165623)
-   [CommonDeviceKey](#ga25be99ffbe88e41f7ce51d2678010254)
-   [DataBitMap](#gab839c7f1fd448f52f003ab0693f27bb4)
-   [DeviceTypeEnum](#gab20b49630026f3118d6c05b0a022f230)
-   [DiscoverMode](#ga7369479474cf45e9ca9c0f756473c74f)
-   [ExchanageMedium](#gaf5c7c122990f0ab5bd46b9bc47b5868b)
-   [ExchangeFre](#gacf2c77bd7e2c82784078762978123ea3)
-   [PublishFailReason](#ga6632fcae1db4a3a13370e3fb49e5e620)
-   [Function](#section606981660165623)
-   [CloseSession\(\)](#ga5b0c0b334f387f9c2753146ee0890780)
-   [CreateSessionServer\(\)](#gad7e95cced3378e8f489553d70b121392)
-   [GetMySessionName\(\)](#ga00611f717919f4156c74b7919b28c7d8)
-   [GetPeerDeviceId\(\)](#ga21b9a889069eea6e7fe653820e601c04)
-   [GetPeerSessionName\(\)](#ga92d5a47fcdf97a0e01797c77e644033e)
-   [PublishService\(\)](#ga010557e05b3f0b0b1a05157f1724e13a)
-   [RemoveSessionServer\(\)](#ga225a1e178544457263d94078e638b7b5)
-   [SendBytes\(\)](#ga0333c76724dbef71bca48fb2a82e6980)
-   [SetCommonDeviceInfo\(\)](#gaca3ae566d98727d111befb4a642bafc4)
-   [UnPublishService\(\)](#gac9463e62e324155634c01facdf642ea7)
-   [Variable](#section394223217165623)
-   [bitmap](#gaccfbfe7a48ef51a2bada9a711dfe8cdb)
-   [capability \[1/2\]](#gacf7c1f9daf2bf9c148ab9d8048d75358)
-   [capability \[2/2\]](#gaba08ca6b519055898dd60b6e98a796d4)
-   [capabilityData](#ga0d267dd5f6f198120f91759094f07ab7)
-   [dataLen](#ga0ae4b95fd8ba4fd0fca6d02dee79e643)
-   [devType](#ga0e85f0b19c5d5d8368b93b9751473fb1)
-   [freq](#gaf850489236b0efbc4b27ea5a867ec001)
-   [key](#gaf3ee5a07a887ab31517318e0d4ea8cc4)
-   [medium](#ga3997803d8bfec79f5ba6e264f8e35b52)
-   [mode](#ga1e1635bcdb216cd4a4756c4962c3f595)
-   [onBytesReceived](#ga95243f25fa04ef29f7f8f0b3a440dbd3)
-   [onPublishFail](#ga0f84feec4640c176938bbce26b8f25c8)
-   [onPublishSuccess](#gade0a74f5ae9b16a1fa7f03df5d9fbdf1)
-   [onSessionClosed](#ga2088a4e0e196030d8e428a828298eba0)
-   [onSessionOpened](#ga2b042b85e03d66f1988c348414b2db6e)
-   [publishId](#ga44a9b46ef719d882d4438a0c34a7f657)
-   [value \[1/2\]](#gaddf75957b595adaddd4f227b9834e20b)
-   [value \[2/2\]](#ga84452c64348251edfe90fc61a5c561ac)

## **Overview**<a name="section1320862849165623"></a>

**Description:**

Provides high-speed, secure communication between devices. 

This module implements unified distributed communication capability management between nearby devices, and provides link-independent device discovery and transmission interfaces to support service publishing and data transmission.

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1861030385165623"></a>

## Files<a name="files"></a>

<a name="table1687826830165623"></a>
<table><thead align="left"><tr id="row1046716891165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1473313799165623"><a name="p1473313799165623"></a><a name="p1473313799165623"></a>File Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p725805347165623"><a name="p725805347165623"></a><a name="p725805347165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row679445067165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2135278031165623"><a name="p2135278031165623"></a><a name="p2135278031165623"></a><a href="discovery_service-h.md">discovery_service.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2037270990165623"><a name="p2037270990165623"></a><a name="p2037270990165623"></a>Declares unified device service publishing interfaces. </p>
</td>
</tr>
<tr id="row1616477884165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1719597394165623"><a name="p1719597394165623"></a><a name="p1719597394165623"></a><a href="session-h.md">session.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1204569796165623"><a name="p1204569796165623"></a><a name="p1204569796165623"></a>Declares unified data transmission interfaces. </p>
</td>
</tr>
</tbody>
</table>

## Data Structures<a name="nested-classes"></a>

<a name="table948634633165623"></a>
<table><thead align="left"><tr id="row1776072129165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1751682209165623"><a name="p1751682209165623"></a><a name="p1751682209165623"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1072058696165623"><a name="p1072058696165623"></a><a name="p1072058696165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1769298797165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1224919902165623"><a name="p1224919902165623"></a><a name="p1224919902165623"></a><a href="publishinfo.md">PublishInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1428927574165623"><a name="p1428927574165623"></a><a name="p1428927574165623"></a>Defines service provisioning information sent to a discovering device. </p>
</td>
</tr>
<tr id="row2056196689165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p511568797165623"><a name="p511568797165623"></a><a name="p511568797165623"></a><a href="capabilitymap.md">CapabilityMap</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1257823305165623"><a name="p1257823305165623"></a><a name="p1257823305165623"></a>Defines the mapping between supported capabilities and bitmaps. </p>
</td>
</tr>
<tr id="row887875741165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1155818904165623"><a name="p1155818904165623"></a><a name="p1155818904165623"></a><a href="devicemap.md">DeviceMap</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p889702441165623"><a name="p889702441165623"></a><a name="p889702441165623"></a>Defines the mappings between the device type enumerations and device type names. </p>
</td>
</tr>
<tr id="row2065142503165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1730126656165623"><a name="p1730126656165623"></a><a name="p1730126656165623"></a><a href="ipublishcallback.md">IPublishCallback</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p511802626165623"><a name="p511802626165623"></a><a name="p511802626165623"></a>Defines the callbacks for successful and failed service publishing. </p>
</td>
</tr>
<tr id="row1616261410165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p119383474165623"><a name="p119383474165623"></a><a name="p119383474165623"></a><a href="commondeviceinfo.md">CommonDeviceInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1021129315165623"><a name="p1021129315165623"></a><a name="p1021129315165623"></a>Defines the type and content of a device to set. </p>
</td>
</tr>
<tr id="row438129130165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p545770474165623"><a name="p545770474165623"></a><a name="p545770474165623"></a><a href="isessionlistener.md">ISessionListener</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2028689079165623"><a name="p2028689079165623"></a><a name="p2028689079165623"></a>Defines session callbacks. </p>
</td>
</tr>
</tbody>
</table>

## Typedefs<a name="typedef-members"></a>

<a name="table1788111519165623"></a>
<table><thead align="left"><tr id="row489459766165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p975052454165623"><a name="p975052454165623"></a><a name="p975052454165623"></a>Typedef Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1864205305165623"><a name="p1864205305165623"></a><a name="p1864205305165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2021276421165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1012685198165623"><a name="p1012685198165623"></a><a name="p1012685198165623"></a><a href="softbus.md#gae0bb52450c28ea9be1c5475d0d89830e">PublishInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p206257726165623"><a name="p206257726165623"></a><a name="p206257726165623"></a>typedef struct <a href="publishinfo.md">PublishInfo</a> </p>
<p id="p511659322165623"><a name="p511659322165623"></a><a name="p511659322165623"></a>Defines service provisioning information sent to a discovering device. </p>
</td>
</tr>
<tr id="row1303768520165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p384848774165623"><a name="p384848774165623"></a><a name="p384848774165623"></a><a href="softbus.md#ga9334bacb3ded964dc3c3367a6b70bcf4">DeviceType</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1220106063165623"><a name="p1220106063165623"></a><a name="p1220106063165623"></a>typedef enum <a href="softbus.md#gab20b49630026f3118d6c05b0a022f230">DeviceTypeEnum</a> </p>
<p id="p1122967559165623"><a name="p1122967559165623"></a><a name="p1122967559165623"></a>Enumerates device types. </p>
</td>
</tr>
<tr id="row1618821977165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p279417113165623"><a name="p279417113165623"></a><a name="p279417113165623"></a><a href="softbus.md#gab622f2f40d12121620d464e43635a09b">IPublishCallback</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1284937350165623"><a name="p1284937350165623"></a><a name="p1284937350165623"></a>typedef struct <a href="ipublishcallback.md">IPublishCallback</a> </p>
<p id="p1538645962165623"><a name="p1538645962165623"></a><a name="p1538645962165623"></a>Defines the callbacks for successful and failed service publishing. </p>
</td>
</tr>
<tr id="row1979088644165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1073706491165623"><a name="p1073706491165623"></a><a name="p1073706491165623"></a><a href="softbus.md#ga8dc0eb993aea9593f96da339edf042ff">CommonDeviceInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p424543231165623"><a name="p424543231165623"></a><a name="p424543231165623"></a>typedef struct <a href="commondeviceinfo.md">CommonDeviceInfo</a> </p>
<p id="p2127067802165623"><a name="p2127067802165623"></a><a name="p2127067802165623"></a>Defines the type and content of a device to set. </p>
</td>
</tr>
</tbody>
</table>

## Enumerations<a name="enum-members"></a>

<a name="table275895017165623"></a>
<table><thead align="left"><tr id="row2069511795165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1329002825165623"><a name="p1329002825165623"></a><a name="p1329002825165623"></a>Enumeration Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1385377280165623"><a name="p1385377280165623"></a><a name="p1385377280165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row412290138165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1123040130165623"><a name="p1123040130165623"></a><a name="p1123040130165623"></a><a href="softbus.md#gaf5c7c122990f0ab5bd46b9bc47b5868b">ExchanageMedium</a> { <a href="softbus.md#ggaf5c7c122990f0ab5bd46b9bc47b5868baeef9468d1b98bca652a04bf5063fd9d6">AUTO</a> = 0, <a href="softbus.md#ggaf5c7c122990f0ab5bd46b9bc47b5868ba83ac6cc3119966e1e5a7908c9e2e3b6a">BLE</a> = 1, <a href="softbus.md#ggaf5c7c122990f0ab5bd46b9bc47b5868ba8aebc0006e14100ba0e37073b1910195">COAP</a> = 2, <a href="softbus.md#ggaf5c7c122990f0ab5bd46b9bc47b5868ba65f6b55fdc64778bf10632a795b97761">USB</a> = 3 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1099726663165623"><a name="p1099726663165623"></a><a name="p1099726663165623"></a>Enumerates media, such as Bluetooth, Wi-Fi, and USB, used for publishing services. </p>
</td>
</tr>
<tr id="row826434429165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p50857963165623"><a name="p50857963165623"></a><a name="p50857963165623"></a><a href="softbus.md#gacf2c77bd7e2c82784078762978123ea3">ExchangeFre</a> { <a href="softbus.md#ggacf2c77bd7e2c82784078762978123ea3a6a226f4143ca3b18999551694cdb72a8">LOW</a> = 0, <a href="softbus.md#ggacf2c77bd7e2c82784078762978123ea3a3bc56824c91d97fcda36dc99687bb236">MID</a> = 1, <a href="softbus.md#ggacf2c77bd7e2c82784078762978123ea3a0c3a1dacf94061154b3ee354359c5893">HIGH</a> = 2, <a href="softbus.md#ggacf2c77bd7e2c82784078762978123ea3a4c5a6024301ee8c176da7226fda23cdc">SUPER_HIGH</a> = 3 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p216297008165623"><a name="p216297008165623"></a><a name="p216297008165623"></a>Enumerates frequencies for publishing services. This enumeration is involved only in Bluetooth and is not supported currently. </p>
</td>
</tr>
<tr id="row1661619704165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p519599421165623"><a name="p519599421165623"></a><a name="p519599421165623"></a><a href="softbus.md#ga7369479474cf45e9ca9c0f756473c74f">DiscoverMode</a> { <a href="softbus.md#gga7369479474cf45e9ca9c0f756473c74fac6dc5925b6fb96b8e7e094dcb16b6ebf">DISCOVER_MODE_PASSIVE</a> = 0x55, <a href="softbus.md#gga7369479474cf45e9ca9c0f756473c74fa9223119d2d3b76ce474ba46fcc2b2cdb">DISCOVER_MODE_ACTIVE</a> = 0xAA }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p340705156165623"><a name="p340705156165623"></a><a name="p340705156165623"></a>Enumerates the modes in which services are published. The publishing service supports the passive mode. Lite devices support the passive mode only. </p>
</td>
</tr>
<tr id="row1566796033165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1151872861165623"><a name="p1151872861165623"></a><a name="p1151872861165623"></a><a href="softbus.md#ga6632fcae1db4a3a13370e3fb49e5e620">PublishFailReason</a> { <a href="softbus.md#gga6632fcae1db4a3a13370e3fb49e5e620a1e11e7c898876b4060ae96986331250d">PUBLISH_FAIL_REASON_NOT_SUPPORT_MEDIUM</a> = 1, <a href="softbus.md#gga6632fcae1db4a3a13370e3fb49e5e620aae6c44a3f6e7d11bc6373ca48898d9ca">PUBLISH_FAIL_REASON_PARAMETER_INVALID</a> = 2, <a href="softbus.md#gga6632fcae1db4a3a13370e3fb49e5e620a1cd5dc3834e78f257b99120932eaff8f">PUBLISH_FAIL_REASON_UNKNOWN</a> = 0xFF }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p856129668165623"><a name="p856129668165623"></a><a name="p856129668165623"></a>Enumerates failure reasons for publishing services. </p>
</td>
</tr>
<tr id="row283418301165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1773580414165623"><a name="p1773580414165623"></a><a name="p1773580414165623"></a><a href="softbus.md#gab839c7f1fd448f52f003ab0693f27bb4">DataBitMap</a> {   <a href="softbus.md#ggab839c7f1fd448f52f003ab0693f27bb4a773d83ceedb06bba15df8bf3f9c92f4c">HICALL_CAPABILITY_BITMAP</a> = 0, <a href="softbus.md#ggab839c7f1fd448f52f003ab0693f27bb4a2234c533a7dc926001be295d5af77dc3">PROFILE_CAPABILITY_BITMAP</a> = 1, <a href="softbus.md#ggab839c7f1fd448f52f003ab0693f27bb4a13f6092c03683a03ec1793a7fba9adc2">HOMEVISIONPIC_CAPABILITY_BITMAP</a> = 2, <a href="softbus.md#ggab839c7f1fd448f52f003ab0693f27bb4aa65f50213e151c5c1979639cba00e37f">CASTPLUS_CAPABILITY_BITMAP</a>,   <a href="softbus.md#ggab839c7f1fd448f52f003ab0693f27bb4a48fb1fbadf08443a5209176d2c8cf8a3">AA_CAPABILITY_BITMAP</a>, <a href="softbus.md#ggab839c7f1fd448f52f003ab0693f27bb4ade3b8cbbea290f02bdbccd8c200c5ab8">DVKIT_CAPABILITY_BITMAP</a>, <a href="softbus.md#ggab839c7f1fd448f52f003ab0693f27bb4ae0134ba56bf2fe5ca4d6d0a160d8861b">DDMP_CAPABILITY_BITMAP</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1987679230165623"><a name="p1987679230165623"></a><a name="p1987679230165623"></a>Enumerates supported capabilities published by a device. </p>
</td>
</tr>
<tr id="row869262574165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2131081923165623"><a name="p2131081923165623"></a><a name="p2131081923165623"></a><a href="softbus.md#gab20b49630026f3118d6c05b0a022f230">DeviceTypeEnum</a> {   <a href="softbus.md#ggab20b49630026f3118d6c05b0a022f230a1da3b620fee1e91433a53fc5559392f9">UNKOWN</a> = 0x00, <a href="softbus.md#ggab20b49630026f3118d6c05b0a022f230ae1f8e5380dc0849533e4a3b81468ddb1">PHONE</a> = 0x0E, <a href="softbus.md#ggab20b49630026f3118d6c05b0a022f230a58a4470bc0f9a4fcaf059b26e95ab9c2">PAD</a> = 0x11, <a href="softbus.md#ggab20b49630026f3118d6c05b0a022f230a818aafb4e6e34b988f90964cd884b8a2">TV</a> = 0x9C,   <a href="softbus.md#ggab20b49630026f3118d6c05b0a022f230aa2c62b62b658ac45e83749e9e9c1cb46">PC</a> = 0x0C, <a href="softbus.md#ggab20b49630026f3118d6c05b0a022f230ad45d481f1c1a6029ce6a398e52e53bfd">AUDIO</a> = 0x0A, <a href="softbus.md#ggab20b49630026f3118d6c05b0a022f230a5fc54ebcb1dd4bf1e1b93cbc77b57b40">CAR</a> = 0x83, <a href="softbus.md#ggab20b49630026f3118d6c05b0a022f230a51451264203360e0ffacec9b6d8ef7c9">L0</a> = 0xF1,   <a href="softbus.md#ggab20b49630026f3118d6c05b0a022f230ae5bc7ee7d6dda5340a28f91834f10543">L1</a> = 0xF2 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p139618769165623"><a name="p139618769165623"></a><a name="p139618769165623"></a>Enumerates device types. </p>
</td>
</tr>
<tr id="row447982279165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1495052524165623"><a name="p1495052524165623"></a><a name="p1495052524165623"></a><a href="softbus.md#ga25be99ffbe88e41f7ce51d2678010254">CommonDeviceKey</a> { <a href="softbus.md#gga25be99ffbe88e41f7ce51d2678010254a700842536bdaedb960842d6eaad40b10">COMM_DEVICE_KEY_DEVID</a> = 0, <a href="softbus.md#gga25be99ffbe88e41f7ce51d2678010254af943e70b688809585638337aba3fb816">COMM_DEVICE_KEY_DEVTYPE</a> = 1, <a href="softbus.md#gga25be99ffbe88e41f7ce51d2678010254a1e0a393d9715b263f5abe01d289fd341">COMM_DEVICE_KEY_DEVNAME</a> = 2, <a href="softbus.md#gga25be99ffbe88e41f7ce51d2678010254af7be5714543eb5632b641dac82ef4d84">COMM_DEVICE_KEY_MAX</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1367985145165623"><a name="p1367985145165623"></a><a name="p1367985145165623"></a>Enumerates device information, such as its ID, type, and name. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1806624688165623"></a>
<table><thead align="left"><tr id="row1633111222165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2130285475165623"><a name="p2130285475165623"></a><a name="p2130285475165623"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1106569995165623"><a name="p1106569995165623"></a><a name="p1106569995165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1719561795165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1662340043165623"><a name="p1662340043165623"></a><a name="p1662340043165623"></a><a href="softbus.md#ga010557e05b3f0b0b1a05157f1724e13a">PublishService</a> (const char *moduleName, const struct <a href="publishinfo.md">PublishInfo</a> *info, const struct <a href="ipublishcallback.md">IPublishCallback</a> *cb)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p742623038165623"><a name="p742623038165623"></a><a name="p742623038165623"></a>int </p>
<p id="p870766829165623"><a name="p870766829165623"></a><a name="p870766829165623"></a>Publishes a service to the discovering device in the LAN. </p>
</td>
</tr>
<tr id="row1662390303165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p216363984165623"><a name="p216363984165623"></a><a name="p216363984165623"></a><a href="softbus.md#gac9463e62e324155634c01facdf642ea7">UnPublishService</a> (const char *moduleName, int publishId)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1839720609165623"><a name="p1839720609165623"></a><a name="p1839720609165623"></a>int </p>
<p id="p1006170335165623"><a name="p1006170335165623"></a><a name="p1006170335165623"></a>Unpublishes a service based on the <strong id="b604056056165623"><a name="b604056056165623"></a><a name="b604056056165623"></a>publicId</strong> and <strong id="b1028546304165623"><a name="b1028546304165623"></a><a name="b1028546304165623"></a>moduleName</strong>. </p>
</td>
</tr>
<tr id="row2135460465165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1335756118165623"><a name="p1335756118165623"></a><a name="p1335756118165623"></a><a href="softbus.md#gaca3ae566d98727d111befb4a642bafc4">SetCommonDeviceInfo</a> (const struct <a href="commondeviceinfo.md">CommonDeviceInfo</a> *devInfo, unsigned int num)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1033198813165623"><a name="p1033198813165623"></a><a name="p1033198813165623"></a>int </p>
<p id="p147882073165623"><a name="p147882073165623"></a><a name="p147882073165623"></a>Sets common device information, such as its ID, type, and name. </p>
</td>
</tr>
<tr id="row1009451778165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p539716205165623"><a name="p539716205165623"></a><a name="p539716205165623"></a><a href="softbus.md#gad7e95cced3378e8f489553d70b121392">CreateSessionServer</a> (const char *mouduleName, const char *sessionName, struct <a href="isessionlistener.md">ISessionListener</a> *listener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1416187743165623"><a name="p1416187743165623"></a><a name="p1416187743165623"></a>int </p>
<p id="p1477066416165623"><a name="p1477066416165623"></a><a name="p1477066416165623"></a>Creates a session server based on a module name and session name. </p>
</td>
</tr>
<tr id="row458100473165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2019097636165623"><a name="p2019097636165623"></a><a name="p2019097636165623"></a><a href="softbus.md#ga225a1e178544457263d94078e638b7b5">RemoveSessionServer</a> (const char *mouduleName, const char *sessionName)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1611477182165623"><a name="p1611477182165623"></a><a name="p1611477182165623"></a>int </p>
<p id="p1934436935165623"><a name="p1934436935165623"></a><a name="p1934436935165623"></a>Removes a session server based on a module name and session name. </p>
</td>
</tr>
<tr id="row1236009738165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p619562451165623"><a name="p619562451165623"></a><a name="p619562451165623"></a><a href="softbus.md#ga0333c76724dbef71bca48fb2a82e6980">SendBytes</a> (int sessionId, const void *data, unsigned int len)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p312362597165623"><a name="p312362597165623"></a><a name="p312362597165623"></a>int </p>
<p id="p1045766258165623"><a name="p1045766258165623"></a><a name="p1045766258165623"></a>Sends data based on a session ID. </p>
</td>
</tr>
<tr id="row898185753165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1949728658165623"><a name="p1949728658165623"></a><a name="p1949728658165623"></a><a href="softbus.md#ga00611f717919f4156c74b7919b28c7d8">GetMySessionName</a> (int sessionId, char *sessionName, unsigned int len)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p203135819165623"><a name="p203135819165623"></a><a name="p203135819165623"></a>int </p>
<p id="p1583905267165623"><a name="p1583905267165623"></a><a name="p1583905267165623"></a>Obtains the session name registered by the local device based on the session ID. </p>
</td>
</tr>
<tr id="row1302675806165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p704899581165623"><a name="p704899581165623"></a><a name="p704899581165623"></a><a href="softbus.md#ga92d5a47fcdf97a0e01797c77e644033e">GetPeerSessionName</a> (int sessionId, char *sessionName, unsigned int len)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1890287191165623"><a name="p1890287191165623"></a><a name="p1890287191165623"></a>int </p>
<p id="p1379337074165623"><a name="p1379337074165623"></a><a name="p1379337074165623"></a>Obtains the session name registered by the peer device based on the session ID. </p>
</td>
</tr>
<tr id="row1311765172165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1589578995165623"><a name="p1589578995165623"></a><a name="p1589578995165623"></a><a href="softbus.md#ga21b9a889069eea6e7fe653820e601c04">GetPeerDeviceId</a> (int sessionId, char *devId, unsigned int len)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1823649584165623"><a name="p1823649584165623"></a><a name="p1823649584165623"></a>int </p>
<p id="p1965349694165623"><a name="p1965349694165623"></a><a name="p1965349694165623"></a>Obtains the peer device ID based on a session ID. </p>
</td>
</tr>
<tr id="row2099775523165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p538008612165623"><a name="p538008612165623"></a><a name="p538008612165623"></a><a href="softbus.md#ga5b0c0b334f387f9c2753146ee0890780">CloseSession</a> (int sessionId)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1973027619165623"><a name="p1973027619165623"></a><a name="p1973027619165623"></a>void </p>
<p id="p1872190541165623"><a name="p1872190541165623"></a><a name="p1872190541165623"></a>Closes a connected session based on a session ID. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section779093396165623"></a>

## **Typedef **<a name="section357911583165623"></a>

## CommonDeviceInfo<a name="ga8dc0eb993aea9593f96da339edf042ff"></a>

```
typedef struct [CommonDeviceInfo](commondeviceinfo.md) [CommonDeviceInfo](commondeviceinfo.md)
```

 **Description:**

Defines the type and content of a device to set. 

## DeviceType<a name="ga9334bacb3ded964dc3c3367a6b70bcf4"></a>

```
typedef enum [DeviceTypeEnum](softbus.md#gab20b49630026f3118d6c05b0a022f230) [DeviceType](softbus.md#ga9334bacb3ded964dc3c3367a6b70bcf4)
```

 **Description:**

Enumerates device types. 

## IPublishCallback<a name="gab622f2f40d12121620d464e43635a09b"></a>

```
typedef struct [IPublishCallback](ipublishcallback.md) [IPublishCallback](ipublishcallback.md)
```

 **Description:**

Defines the callbacks for successful and failed service publishing. 

## PublishInfo<a name="gae0bb52450c28ea9be1c5475d0d89830e"></a>

```
typedef struct [PublishInfo](publishinfo.md) [PublishInfo](publishinfo.md)
```

 **Description:**

Defines service provisioning information sent to a discovering device. 

## **Enumeration Type **<a name="section574907679165623"></a>

## CommonDeviceKey<a name="ga25be99ffbe88e41f7ce51d2678010254"></a>

```
enum [CommonDeviceKey](softbus.md#ga25be99ffbe88e41f7ce51d2678010254)
```

 **Description:**

Enumerates device information, such as its ID, type, and name. 

<a name="table194081629165623"></a>
<table><thead align="left"><tr id="row1403967977165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p786200018165623"><a name="p786200018165623"></a><a name="p786200018165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p359442223165623"><a name="p359442223165623"></a><a name="p359442223165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1524737771165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga25be99ffbe88e41f7ce51d2678010254a700842536bdaedb960842d6eaad40b10"><a name="gga25be99ffbe88e41f7ce51d2678010254a700842536bdaedb960842d6eaad40b10"></a><a name="gga25be99ffbe88e41f7ce51d2678010254a700842536bdaedb960842d6eaad40b10"></a></strong>COMM_DEVICE_KEY_DEVID </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p962903577165623"><a name="p962903577165623"></a><a name="p962903577165623"></a>Device ID. The value contains a maximum of 64 characters. </p>
 </td>
</tr>
<tr id="row324587795165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga25be99ffbe88e41f7ce51d2678010254af943e70b688809585638337aba3fb816"><a name="gga25be99ffbe88e41f7ce51d2678010254af943e70b688809585638337aba3fb816"></a><a name="gga25be99ffbe88e41f7ce51d2678010254af943e70b688809585638337aba3fb816"></a></strong>COMM_DEVICE_KEY_DEVTYPE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1330210997165623"><a name="p1330210997165623"></a><a name="p1330210997165623"></a>Device type. Currently, only <strong id="b1728803208165623"><a name="b1728803208165623"></a><a name="b1728803208165623"></a>ddmpCapability</strong> is supported. </p>
 </td>
</tr>
<tr id="row1969119257165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga25be99ffbe88e41f7ce51d2678010254a1e0a393d9715b263f5abe01d289fd341"><a name="gga25be99ffbe88e41f7ce51d2678010254a1e0a393d9715b263f5abe01d289fd341"></a><a name="gga25be99ffbe88e41f7ce51d2678010254a1e0a393d9715b263f5abe01d289fd341"></a></strong>COMM_DEVICE_KEY_DEVNAME </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p282628963165623"><a name="p282628963165623"></a><a name="p282628963165623"></a>Device name. The value contains a maximum of 63 characters. </p>
 </td>
</tr>
<tr id="row643704142165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga25be99ffbe88e41f7ce51d2678010254af7be5714543eb5632b641dac82ef4d84"><a name="gga25be99ffbe88e41f7ce51d2678010254af7be5714543eb5632b641dac82ef4d84"></a><a name="gga25be99ffbe88e41f7ce51d2678010254af7be5714543eb5632b641dac82ef4d84"></a></strong>COMM_DEVICE_KEY_MAX </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1605102480165623"><a name="p1605102480165623"></a><a name="p1605102480165623"></a>Reserved </p>
 </td>
</tr>
</tbody>
</table>

## DataBitMap<a name="gab839c7f1fd448f52f003ab0693f27bb4"></a>

```
enum [DataBitMap](softbus.md#gab839c7f1fd448f52f003ab0693f27bb4)
```

 **Description:**

Enumerates supported capabilities published by a device. 

<a name="table2136125362165623"></a>
<table><thead align="left"><tr id="row412027784165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1616963694165623"><a name="p1616963694165623"></a><a name="p1616963694165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p408604195165623"><a name="p408604195165623"></a><a name="p408604195165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row55812126165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggab839c7f1fd448f52f003ab0693f27bb4a773d83ceedb06bba15df8bf3f9c92f4c"><a name="ggab839c7f1fd448f52f003ab0693f27bb4a773d83ceedb06bba15df8bf3f9c92f4c"></a><a name="ggab839c7f1fd448f52f003ab0693f27bb4a773d83ceedb06bba15df8bf3f9c92f4c"></a></strong>HICALL_CAPABILITY_BITMAP </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p37264647165623"><a name="p37264647165623"></a><a name="p37264647165623"></a>MeeTime </p>
 </td>
</tr>
<tr id="row585976258165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggab839c7f1fd448f52f003ab0693f27bb4a2234c533a7dc926001be295d5af77dc3"><a name="ggab839c7f1fd448f52f003ab0693f27bb4a2234c533a7dc926001be295d5af77dc3"></a><a name="ggab839c7f1fd448f52f003ab0693f27bb4a2234c533a7dc926001be295d5af77dc3"></a></strong>PROFILE_CAPABILITY_BITMAP </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2030645385165623"><a name="p2030645385165623"></a><a name="p2030645385165623"></a>Video reverse connection in the smart domain </p>
 </td>
</tr>
<tr id="row2054394228165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggab839c7f1fd448f52f003ab0693f27bb4a13f6092c03683a03ec1793a7fba9adc2"><a name="ggab839c7f1fd448f52f003ab0693f27bb4a13f6092c03683a03ec1793a7fba9adc2"></a><a name="ggab839c7f1fd448f52f003ab0693f27bb4a13f6092c03683a03ec1793a7fba9adc2"></a></strong>HOMEVISIONPIC_CAPABILITY_BITMAP </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1752722823165623"><a name="p1752722823165623"></a><a name="p1752722823165623"></a>Gallery in Vision </p>
 </td>
</tr>
<tr id="row1598870926165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggab839c7f1fd448f52f003ab0693f27bb4aa65f50213e151c5c1979639cba00e37f"><a name="ggab839c7f1fd448f52f003ab0693f27bb4aa65f50213e151c5c1979639cba00e37f"></a><a name="ggab839c7f1fd448f52f003ab0693f27bb4aa65f50213e151c5c1979639cba00e37f"></a></strong>CASTPLUS_CAPABILITY_BITMAP </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p343197993165623"><a name="p343197993165623"></a><a name="p343197993165623"></a>cast+ </p>
 </td>
</tr>
<tr id="row1619158764165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggab839c7f1fd448f52f003ab0693f27bb4a48fb1fbadf08443a5209176d2c8cf8a3"><a name="ggab839c7f1fd448f52f003ab0693f27bb4a48fb1fbadf08443a5209176d2c8cf8a3"></a><a name="ggab839c7f1fd448f52f003ab0693f27bb4a48fb1fbadf08443a5209176d2c8cf8a3"></a></strong>AA_CAPABILITY_BITMAP </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p806795712165623"><a name="p806795712165623"></a><a name="p806795712165623"></a>Input method in Vision </p>
 </td>
</tr>
<tr id="row247358914165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggab839c7f1fd448f52f003ab0693f27bb4ade3b8cbbea290f02bdbccd8c200c5ab8"><a name="ggab839c7f1fd448f52f003ab0693f27bb4ade3b8cbbea290f02bdbccd8c200c5ab8"></a><a name="ggab839c7f1fd448f52f003ab0693f27bb4ade3b8cbbea290f02bdbccd8c200c5ab8"></a></strong>DVKIT_CAPABILITY_BITMAP </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1338450298165623"><a name="p1338450298165623"></a><a name="p1338450298165623"></a>Device virtualization tool package </p>
 </td>
</tr>
<tr id="row755030538165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggab839c7f1fd448f52f003ab0693f27bb4ae0134ba56bf2fe5ca4d6d0a160d8861b"><a name="ggab839c7f1fd448f52f003ab0693f27bb4ae0134ba56bf2fe5ca4d6d0a160d8861b"></a><a name="ggab839c7f1fd448f52f003ab0693f27bb4ae0134ba56bf2fe5ca4d6d0a160d8861b"></a></strong>DDMP_CAPABILITY_BITMAP </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p297692898165623"><a name="p297692898165623"></a><a name="p297692898165623"></a>Distributed middleware </p>
 </td>
</tr>
</tbody>
</table>

## DeviceTypeEnum<a name="gab20b49630026f3118d6c05b0a022f230"></a>

```
enum [DeviceTypeEnum](softbus.md#gab20b49630026f3118d6c05b0a022f230)
```

 **Description:**

Enumerates device types. 

<a name="table1988191088165623"></a>
<table><thead align="left"><tr id="row131179184165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p8625397165623"><a name="p8625397165623"></a><a name="p8625397165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p518754651165623"><a name="p518754651165623"></a><a name="p518754651165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2135458573165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggab20b49630026f3118d6c05b0a022f230a1da3b620fee1e91433a53fc5559392f9"><a name="ggab20b49630026f3118d6c05b0a022f230a1da3b620fee1e91433a53fc5559392f9"></a><a name="ggab20b49630026f3118d6c05b0a022f230a1da3b620fee1e91433a53fc5559392f9"></a></strong>UNKOWN </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1307331051165623"><a name="p1307331051165623"></a><a name="p1307331051165623"></a>Unknown </p>
 </td>
</tr>
<tr id="row1015940027165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggab20b49630026f3118d6c05b0a022f230ae1f8e5380dc0849533e4a3b81468ddb1"><a name="ggab20b49630026f3118d6c05b0a022f230ae1f8e5380dc0849533e4a3b81468ddb1"></a><a name="ggab20b49630026f3118d6c05b0a022f230ae1f8e5380dc0849533e4a3b81468ddb1"></a></strong>PHONE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1373680315165623"><a name="p1373680315165623"></a><a name="p1373680315165623"></a>Smartphone </p>
 </td>
</tr>
<tr id="row491451919165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggab20b49630026f3118d6c05b0a022f230a58a4470bc0f9a4fcaf059b26e95ab9c2"><a name="ggab20b49630026f3118d6c05b0a022f230a58a4470bc0f9a4fcaf059b26e95ab9c2"></a><a name="ggab20b49630026f3118d6c05b0a022f230a58a4470bc0f9a4fcaf059b26e95ab9c2"></a></strong>PAD </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1207153604165623"><a name="p1207153604165623"></a><a name="p1207153604165623"></a>Tablet </p>
 </td>
</tr>
<tr id="row939093661165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggab20b49630026f3118d6c05b0a022f230a818aafb4e6e34b988f90964cd884b8a2"><a name="ggab20b49630026f3118d6c05b0a022f230a818aafb4e6e34b988f90964cd884b8a2"></a><a name="ggab20b49630026f3118d6c05b0a022f230a818aafb4e6e34b988f90964cd884b8a2"></a></strong>TV </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p754465182165623"><a name="p754465182165623"></a><a name="p754465182165623"></a>Smart TV </p>
 </td>
</tr>
<tr id="row943172326165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggab20b49630026f3118d6c05b0a022f230aa2c62b62b658ac45e83749e9e9c1cb46"><a name="ggab20b49630026f3118d6c05b0a022f230aa2c62b62b658ac45e83749e9e9c1cb46"></a><a name="ggab20b49630026f3118d6c05b0a022f230aa2c62b62b658ac45e83749e9e9c1cb46"></a></strong>PC </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p779383706165623"><a name="p779383706165623"></a><a name="p779383706165623"></a>PC </p>
 </td>
</tr>
<tr id="row1545866642165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggab20b49630026f3118d6c05b0a022f230ad45d481f1c1a6029ce6a398e52e53bfd"><a name="ggab20b49630026f3118d6c05b0a022f230ad45d481f1c1a6029ce6a398e52e53bfd"></a><a name="ggab20b49630026f3118d6c05b0a022f230ad45d481f1c1a6029ce6a398e52e53bfd"></a></strong>AUDIO </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2146000704165623"><a name="p2146000704165623"></a><a name="p2146000704165623"></a>Audio device </p>
 </td>
</tr>
<tr id="row755895503165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggab20b49630026f3118d6c05b0a022f230a5fc54ebcb1dd4bf1e1b93cbc77b57b40"><a name="ggab20b49630026f3118d6c05b0a022f230a5fc54ebcb1dd4bf1e1b93cbc77b57b40"></a><a name="ggab20b49630026f3118d6c05b0a022f230a5fc54ebcb1dd4bf1e1b93cbc77b57b40"></a></strong>CAR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p272505264165623"><a name="p272505264165623"></a><a name="p272505264165623"></a>Vehicle-mounted device </p>
 </td>
</tr>
<tr id="row875906497165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggab20b49630026f3118d6c05b0a022f230a51451264203360e0ffacec9b6d8ef7c9"><a name="ggab20b49630026f3118d6c05b0a022f230a51451264203360e0ffacec9b6d8ef7c9"></a><a name="ggab20b49630026f3118d6c05b0a022f230a51451264203360e0ffacec9b6d8ef7c9"></a></strong>L0 </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p921853325165623"><a name="p921853325165623"></a><a name="p921853325165623"></a>Light device L0 </p>
 </td>
</tr>
<tr id="row1613260657165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggab20b49630026f3118d6c05b0a022f230ae5bc7ee7d6dda5340a28f91834f10543"><a name="ggab20b49630026f3118d6c05b0a022f230ae5bc7ee7d6dda5340a28f91834f10543"></a><a name="ggab20b49630026f3118d6c05b0a022f230ae5bc7ee7d6dda5340a28f91834f10543"></a></strong>L1 </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1162573788165623"><a name="p1162573788165623"></a><a name="p1162573788165623"></a>Light device L1 </p>
 </td>
</tr>
</tbody>
</table>

## DiscoverMode<a name="ga7369479474cf45e9ca9c0f756473c74f"></a>

```
enum [DiscoverMode](softbus.md#ga7369479474cf45e9ca9c0f756473c74f)
```

 **Description:**

Enumerates the modes in which services are published. The publishing service supports the passive mode. Lite devices support the passive mode only. 

<a name="table258693732165623"></a>
<table><thead align="left"><tr id="row1444648202165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2034731213165623"><a name="p2034731213165623"></a><a name="p2034731213165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1284158402165623"><a name="p1284158402165623"></a><a name="p1284158402165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1218944935165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga7369479474cf45e9ca9c0f756473c74fac6dc5925b6fb96b8e7e094dcb16b6ebf"><a name="gga7369479474cf45e9ca9c0f756473c74fac6dc5925b6fb96b8e7e094dcb16b6ebf"></a><a name="gga7369479474cf45e9ca9c0f756473c74fac6dc5925b6fb96b8e7e094dcb16b6ebf"></a></strong>DISCOVER_MODE_PASSIVE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p762728104165623"><a name="p762728104165623"></a><a name="p762728104165623"></a>Passive </p>
 </td>
</tr>
<tr id="row604878080165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga7369479474cf45e9ca9c0f756473c74fa9223119d2d3b76ce474ba46fcc2b2cdb"><a name="gga7369479474cf45e9ca9c0f756473c74fa9223119d2d3b76ce474ba46fcc2b2cdb"></a><a name="gga7369479474cf45e9ca9c0f756473c74fa9223119d2d3b76ce474ba46fcc2b2cdb"></a></strong>DISCOVER_MODE_ACTIVE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1327601534165623"><a name="p1327601534165623"></a><a name="p1327601534165623"></a>Proactive </p>
 </td>
</tr>
</tbody>
</table>

## ExchanageMedium<a name="gaf5c7c122990f0ab5bd46b9bc47b5868b"></a>

```
enum [ExchanageMedium](softbus.md#gaf5c7c122990f0ab5bd46b9bc47b5868b)
```

 **Description:**

Enumerates media, such as Bluetooth, Wi-Fi, and USB, used for publishing services. 

Currently, the media can only be set to coap. 

<a name="table1650346331165623"></a>
<table><thead align="left"><tr id="row783120778165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p765443862165623"><a name="p765443862165623"></a><a name="p765443862165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p559070533165623"><a name="p559070533165623"></a><a name="p559070533165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row377590500165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaf5c7c122990f0ab5bd46b9bc47b5868baeef9468d1b98bca652a04bf5063fd9d6"><a name="ggaf5c7c122990f0ab5bd46b9bc47b5868baeef9468d1b98bca652a04bf5063fd9d6"></a><a name="ggaf5c7c122990f0ab5bd46b9bc47b5868baeef9468d1b98bca652a04bf5063fd9d6"></a></strong>AUTO </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1733103513165623"><a name="p1733103513165623"></a><a name="p1733103513165623"></a>Automatic medium selection </p>
 </td>
</tr>
<tr id="row4145173165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaf5c7c122990f0ab5bd46b9bc47b5868ba83ac6cc3119966e1e5a7908c9e2e3b6a"><a name="ggaf5c7c122990f0ab5bd46b9bc47b5868ba83ac6cc3119966e1e5a7908c9e2e3b6a"></a><a name="ggaf5c7c122990f0ab5bd46b9bc47b5868ba83ac6cc3119966e1e5a7908c9e2e3b6a"></a></strong>BLE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p436514815165623"><a name="p436514815165623"></a><a name="p436514815165623"></a>Bluetooth </p>
 </td>
</tr>
<tr id="row1608468991165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaf5c7c122990f0ab5bd46b9bc47b5868ba8aebc0006e14100ba0e37073b1910195"><a name="ggaf5c7c122990f0ab5bd46b9bc47b5868ba8aebc0006e14100ba0e37073b1910195"></a><a name="ggaf5c7c122990f0ab5bd46b9bc47b5868ba8aebc0006e14100ba0e37073b1910195"></a></strong>COAP </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p999814621165623"><a name="p999814621165623"></a><a name="p999814621165623"></a>Wi-Fi </p>
 </td>
</tr>
<tr id="row257457696165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaf5c7c122990f0ab5bd46b9bc47b5868ba65f6b55fdc64778bf10632a795b97761"><a name="ggaf5c7c122990f0ab5bd46b9bc47b5868ba65f6b55fdc64778bf10632a795b97761"></a><a name="ggaf5c7c122990f0ab5bd46b9bc47b5868ba65f6b55fdc64778bf10632a795b97761"></a></strong>USB </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p88853209165623"><a name="p88853209165623"></a><a name="p88853209165623"></a>USB </p>
 </td>
</tr>
</tbody>
</table>

## ExchangeFre<a name="gacf2c77bd7e2c82784078762978123ea3"></a>

```
enum [ExchangeFre](softbus.md#gacf2c77bd7e2c82784078762978123ea3)
```

 **Description:**

Enumerates frequencies for publishing services. This enumeration is involved only in Bluetooth and is not supported currently. 

<a name="table616156770165623"></a>
<table><thead align="left"><tr id="row1662020352165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p684050659165623"><a name="p684050659165623"></a><a name="p684050659165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p374770948165623"><a name="p374770948165623"></a><a name="p374770948165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row824287548165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggacf2c77bd7e2c82784078762978123ea3a6a226f4143ca3b18999551694cdb72a8"><a name="ggacf2c77bd7e2c82784078762978123ea3a6a226f4143ca3b18999551694cdb72a8"></a><a name="ggacf2c77bd7e2c82784078762978123ea3a6a226f4143ca3b18999551694cdb72a8"></a></strong>LOW </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2044579659165623"><a name="p2044579659165623"></a><a name="p2044579659165623"></a>Low </p>
 </td>
</tr>
<tr id="row1114680058165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggacf2c77bd7e2c82784078762978123ea3a3bc56824c91d97fcda36dc99687bb236"><a name="ggacf2c77bd7e2c82784078762978123ea3a3bc56824c91d97fcda36dc99687bb236"></a><a name="ggacf2c77bd7e2c82784078762978123ea3a3bc56824c91d97fcda36dc99687bb236"></a></strong>MID </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p715939294165623"><a name="p715939294165623"></a><a name="p715939294165623"></a>Medium </p>
 </td>
</tr>
<tr id="row1504952687165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggacf2c77bd7e2c82784078762978123ea3a0c3a1dacf94061154b3ee354359c5893"><a name="ggacf2c77bd7e2c82784078762978123ea3a0c3a1dacf94061154b3ee354359c5893"></a><a name="ggacf2c77bd7e2c82784078762978123ea3a0c3a1dacf94061154b3ee354359c5893"></a></strong>HIGH </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p272130166165623"><a name="p272130166165623"></a><a name="p272130166165623"></a>High </p>
 </td>
</tr>
<tr id="row142487259165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggacf2c77bd7e2c82784078762978123ea3a4c5a6024301ee8c176da7226fda23cdc"><a name="ggacf2c77bd7e2c82784078762978123ea3a4c5a6024301ee8c176da7226fda23cdc"></a><a name="ggacf2c77bd7e2c82784078762978123ea3a4c5a6024301ee8c176da7226fda23cdc"></a></strong>SUPER_HIGH </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1528320793165623"><a name="p1528320793165623"></a><a name="p1528320793165623"></a>Super-high </p>
 </td>
</tr>
</tbody>
</table>

## PublishFailReason<a name="ga6632fcae1db4a3a13370e3fb49e5e620"></a>

```
enum [PublishFailReason](softbus.md#ga6632fcae1db4a3a13370e3fb49e5e620)
```

 **Description:**

Enumerates failure reasons for publishing services. 

The failure reason is returned to the caller through the callback function. 

<a name="table448597123165623"></a>
<table><thead align="left"><tr id="row635660245165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p995894727165623"><a name="p995894727165623"></a><a name="p995894727165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1803600816165623"><a name="p1803600816165623"></a><a name="p1803600816165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row395170469165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga6632fcae1db4a3a13370e3fb49e5e620a1e11e7c898876b4060ae96986331250d"><a name="gga6632fcae1db4a3a13370e3fb49e5e620a1e11e7c898876b4060ae96986331250d"></a><a name="gga6632fcae1db4a3a13370e3fb49e5e620a1e11e7c898876b4060ae96986331250d"></a></strong>PUBLISH_FAIL_REASON_NOT_SUPPORT_MEDIUM </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p794108934165623"><a name="p794108934165623"></a><a name="p794108934165623"></a>Unsupported medium </p>
 </td>
</tr>
<tr id="row494788531165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga6632fcae1db4a3a13370e3fb49e5e620aae6c44a3f6e7d11bc6373ca48898d9ca"><a name="gga6632fcae1db4a3a13370e3fb49e5e620aae6c44a3f6e7d11bc6373ca48898d9ca"></a><a name="gga6632fcae1db4a3a13370e3fb49e5e620aae6c44a3f6e7d11bc6373ca48898d9ca"></a></strong>PUBLISH_FAIL_REASON_PARAMETER_INVALID </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p59301194165623"><a name="p59301194165623"></a><a name="p59301194165623"></a>Invalid parameter </p>
 </td>
</tr>
<tr id="row179345199165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga6632fcae1db4a3a13370e3fb49e5e620a1cd5dc3834e78f257b99120932eaff8f"><a name="gga6632fcae1db4a3a13370e3fb49e5e620a1cd5dc3834e78f257b99120932eaff8f"></a><a name="gga6632fcae1db4a3a13370e3fb49e5e620a1cd5dc3834e78f257b99120932eaff8f"></a></strong>PUBLISH_FAIL_REASON_UNKNOWN </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1945552999165623"><a name="p1945552999165623"></a><a name="p1945552999165623"></a>Unknown reason </p>
 </td>
</tr>
</tbody>
</table>

## **Function **<a name="section606981660165623"></a>

## CloseSession\(\)<a name="ga5b0c0b334f387f9c2753146ee0890780"></a>

```
void CloseSession (int sessionId)
```

 **Description:**

Closes a connected session based on a session ID. 

**Parameters:**

<a name="table208103561165623"></a>
<table><thead align="left"><tr id="row517057702165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1371264238165623"><a name="p1371264238165623"></a><a name="p1371264238165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1523314915165623"><a name="p1523314915165623"></a><a name="p1523314915165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2137637346165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sessionId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the session ID. </td>
</tr>
</tbody>
</table>

## CreateSessionServer\(\)<a name="gad7e95cced3378e8f489553d70b121392"></a>

```
int CreateSessionServer (const char * mouduleName, const char * sessionName, struct [ISessionListener](isessionlistener.md) * listener )
```

 **Description:**

Creates a session server based on a module name and session name. 

A maximum of 18 session servers can be created.

**Parameters:**

<a name="table610070308165623"></a>
<table><thead align="left"><tr id="row1830985994165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p619876023165623"><a name="p619876023165623"></a><a name="p619876023165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1522046213165623"><a name="p1522046213165623"></a><a name="p1522046213165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row74400764165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">moduleName</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the module name, which can be used to check whether the session server is in this module. The value cannot be empty and can contain a maximum of 64 characters. </td>
</tr>
<tr id="row217866885165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sessionName</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the session name, which is the unique ID of the session server. The value cannot be empty and can contain a maximum of 64 characters. </td>
</tr>
<tr id="row1669731704165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">listener</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the session callback structure, which cannot be empty. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  otherwise. 

**See also:**

[RemoveSessionServer](softbus.md#ga225a1e178544457263d94078e638b7b5) 

## GetMySessionName\(\)<a name="ga00611f717919f4156c74b7919b28c7d8"></a>

```
int GetMySessionName (int sessionId, char * sessionName, unsigned int len )
```

 **Description:**

Obtains the session name registered by the local device based on the session ID. 

**Parameters:**

<a name="table1854807958165623"></a>
<table><thead align="left"><tr id="row1039498569165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p891754571165623"><a name="p891754571165623"></a><a name="p891754571165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p578835747165623"><a name="p578835747165623"></a><a name="p578835747165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1891500755165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sessionId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the session ID. </td>
</tr>
<tr id="row804226707165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sessionName</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the buffer for storing the session name. </td>
</tr>
<tr id="row1441739034165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">len</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the length of the buffer. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  otherwise. 

## GetPeerDeviceId\(\)<a name="ga21b9a889069eea6e7fe653820e601c04"></a>

```
int GetPeerDeviceId (int sessionId, char * devId, unsigned int len )
```

 **Description:**

Obtains the peer device ID based on a session ID. 

**Parameters:**

<a name="table1192284351165623"></a>
<table><thead align="left"><tr id="row279362054165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p827070875165623"><a name="p827070875165623"></a><a name="p827070875165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2035028922165623"><a name="p2035028922165623"></a><a name="p2035028922165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row306765342165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sessionId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the session ID. </td>
</tr>
<tr id="row803340717165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">devId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the buffer for storing the device ID. </td>
</tr>
<tr id="row1910359608165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">len</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the length of the buffer. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  otherwise. 

## GetPeerSessionName\(\)<a name="ga92d5a47fcdf97a0e01797c77e644033e"></a>

```
int GetPeerSessionName (int sessionId, char * sessionName, unsigned int len )
```

 **Description:**

Obtains the session name registered by the peer device based on the session ID. 

**Parameters:**

<a name="table1491246098165623"></a>
<table><thead align="left"><tr id="row98357095165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1198950474165623"><a name="p1198950474165623"></a><a name="p1198950474165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p479064994165623"><a name="p479064994165623"></a><a name="p479064994165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row773322450165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sessionId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the session ID. </td>
</tr>
<tr id="row1109530100165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sessionName</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the buffer for storing the session name. </td>
</tr>
<tr id="row1563323581165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">len</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the length of the buffer. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  otherwise. 

## PublishService\(\)<a name="ga010557e05b3f0b0b1a05157f1724e13a"></a>

```
int PublishService (const char * moduleName, const struct [PublishInfo](publishinfo.md) * info, const struct [IPublishCallback](ipublishcallback.md) * cb )
```

 **Description:**

Publishes a service to the discovering device in the LAN. 

The  **publicId**  and  **moduleName**  uniquely identify a service. A maximum of three services can be published.

**Parameters:**

<a name="table1907812279165623"></a>
<table><thead align="left"><tr id="row136405854165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1661692485165623"><a name="p1661692485165623"></a><a name="p1661692485165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p950640012165623"><a name="p950640012165623"></a><a name="p950640012165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1174432009165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">moduleName</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the module name of the upper-layer service. The value contains a maximum of 63 bytes. </td>
</tr>
<tr id="row825549112165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">info</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the service to publish. For details, see <a href="publishinfo.md">PublishInfo</a>. </td>
</tr>
<tr id="row139319922165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">cb</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the callback for service publishing. For details, see <a href="ipublishcallback.md">IPublishCallback</a>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  otherwise. 

## RemoveSessionServer\(\)<a name="ga225a1e178544457263d94078e638b7b5"></a>

```
int RemoveSessionServer (const char * mouduleName, const char * sessionName )
```

 **Description:**

Removes a session server based on a module name and session name. 

**Parameters:**

<a name="table1896176830165623"></a>
<table><thead align="left"><tr id="row1288296552165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p474503179165623"><a name="p474503179165623"></a><a name="p474503179165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1624590054165623"><a name="p1624590054165623"></a><a name="p1624590054165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2022283907165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">moduleName</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the name of the registered module, which can be used to check whether the session server is in this module. The value cannot be empty and can contain a maximum of 64 characters. </td>
</tr>
<tr id="row1607402345165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sessionName</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the session name. The value cannot be empty and can contain a maximum of 64 characters. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  otherwise. 

**See also:**

[CreateSessionServer](softbus.md#gad7e95cced3378e8f489553d70b121392) 

## SendBytes\(\)<a name="ga0333c76724dbef71bca48fb2a82e6980"></a>

```
int SendBytes (int sessionId, const void * data, unsigned int len )
```

 **Description:**

Sends data based on a session ID. 

**Parameters:**

<a name="table952665919165623"></a>
<table><thead align="left"><tr id="row877728415165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1532059543165623"><a name="p1532059543165623"></a><a name="p1532059543165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p441628048165623"><a name="p441628048165623"></a><a name="p441628048165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1051936181165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sessionId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the session ID. </td>
</tr>
<tr id="row1632146497165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">data</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the data to send, which cannot be <strong id="b283942808165623"><a name="b283942808165623"></a><a name="b283942808165623"></a>NULL</strong>. </td>
</tr>
<tr id="row1157119039165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">len</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the length of the data to send. The maximum length cannot exceed 984 characters. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the function is called successfully; returns  **-1**  otherwise. 

## SetCommonDeviceInfo\(\)<a name="gaca3ae566d98727d111befb4a642bafc4"></a>

```
int SetCommonDeviceInfo (const struct [CommonDeviceInfo](commondeviceinfo.md) * devInfo, unsigned int num )
```

 **Description:**

Sets common device information, such as its ID, type, and name. 

**Parameters:**

<a name="table584902829165623"></a>
<table><thead align="left"><tr id="row1332059746165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1532484883165623"><a name="p1532484883165623"></a><a name="p1532484883165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p523939405165623"><a name="p523939405165623"></a><a name="p523939405165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row837336736165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">devInfo</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the device information array. </td>
</tr>
<tr id="row2031031171165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">2</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">num Indicates the number of elements in the device information array. If the value is inconsistent with the length of the device information array, the program breaks down. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise. 

**See also:**

[PublishService](softbus.md#ga010557e05b3f0b0b1a05157f1724e13a) 

## UnPublishService\(\)<a name="gac9463e62e324155634c01facdf642ea7"></a>

```
int UnPublishService (const char * moduleName, int publishId )
```

 **Description:**

Unpublishes a service based on the  **publicId**  and  **moduleName**. 

**Parameters:**

<a name="table1177886436165623"></a>
<table><thead align="left"><tr id="row1369787136165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p402222622165623"><a name="p402222622165623"></a><a name="p402222622165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1568954349165623"><a name="p1568954349165623"></a><a name="p1568954349165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1339141207165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">moduleName</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the module name of the upper-layer service. The value contains a maximum of 63 bytes. </td>
</tr>
<tr id="row687417522165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">publishId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the ID of the service to unpublish. The value must be greater than <strong id="b364337681165623"><a name="b364337681165623"></a><a name="b364337681165623"></a>0</strong>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise. 

## **Variable **<a name="section394223217165623"></a>

## bitmap<a name="gaccfbfe7a48ef51a2bada9a711dfe8cdb"></a>

```
[DataBitMap](softbus.md#gab839c7f1fd448f52f003ab0693f27bb4) CapabilityMap::bitmap
```

 **Description:**

Bitmaps. For details, see  [DataBitMap](softbus.md#gab839c7f1fd448f52f003ab0693f27bb4). 

## capability \[1/2\]<a name="gacf7c1f9daf2bf9c148ab9d8048d75358"></a>

```
const char* PublishInfo::capability
```

 **Description:**

[Service](service.md)  publishing capabilities. For details, see  **g\_capabilityMap**. 

## capability \[2/2\]<a name="gaba08ca6b519055898dd60b6e98a796d4"></a>

```
char* CapabilityMap::capability
```

 **Description:**

Capability. For details, see  **g\_capabilityMap**. 

## capabilityData<a name="ga0d267dd5f6f198120f91759094f07ab7"></a>

```
unsigned char* PublishInfo::capabilityData
```

 **Description:**

Capability data for service publishing 

## dataLen<a name="ga0ae4b95fd8ba4fd0fca6d02dee79e643"></a>

```
unsigned int PublishInfo::dataLen
```

 **Description:**

Maximum length of the capability data for service publishing \(2 bytes\) 

## devType<a name="ga0e85f0b19c5d5d8368b93b9751473fb1"></a>

```
[DeviceType](softbus.md#ga9334bacb3ded964dc3c3367a6b70bcf4) DeviceMap::devType
```

 **Description:**

Enumeration of a device type. Only enumerations defined in  **g\_devMap**  are supported. 

## freq<a name="gaf850489236b0efbc4b27ea5a867ec001"></a>

```
[ExchangeFre](softbus.md#gacf2c77bd7e2c82784078762978123ea3) PublishInfo::freq
```

 **Description:**

[Service](service.md)  publishing frequency 

## key<a name="gaf3ee5a07a887ab31517318e0d4ea8cc4"></a>

```
[CommonDeviceKey](softbus.md#ga25be99ffbe88e41f7ce51d2678010254) CommonDeviceInfo::key
```

 **Description:**

Device information type. For details, see  [CommonDeviceKey](softbus.md#ga25be99ffbe88e41f7ce51d2678010254). 

## medium<a name="ga3997803d8bfec79f5ba6e264f8e35b52"></a>

```
[ExchanageMedium](softbus.md#gaf5c7c122990f0ab5bd46b9bc47b5868b) PublishInfo::medium
```

 **Description:**

[Service](service.md)  publishing medium 

## mode<a name="ga1e1635bcdb216cd4a4756c4962c3f595"></a>

```
int PublishInfo::mode
```

 **Description:**

[Service](service.md)  publishing mode, which can be  [DISCOVER\_MODE\_PASSIVE](softbus.md#gga7369479474cf45e9ca9c0f756473c74fac6dc5925b6fb96b8e7e094dcb16b6ebf)  or  [DISCOVER\_MODE\_ACTIVE](softbus.md#gga7369479474cf45e9ca9c0f756473c74fa9223119d2d3b76ce474ba46fcc2b2cdb) 

## onBytesReceived<a name="ga95243f25fa04ef29f7f8f0b3a440dbd3"></a>

```
void(* ISessionListener::onBytesReceived) (int sessionId, const void *data, unsigned int dataLen)
```

 **Description:**

Called when data is received. 

This function is used to notify that data is received.

**Parameters:**

<a name="table387979955165623"></a>
<table><thead align="left"><tr id="row1852900759165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p592725772165623"><a name="p592725772165623"></a><a name="p592725772165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1257104111165623"><a name="p1257104111165623"></a><a name="p1257104111165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1924818829165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sessionId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the session ID. </td>
</tr>
<tr id="row1093137732165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">data</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the data received. </td>
</tr>
<tr id="row2108068634165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">dataLen</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the length of the data received. </td>
</tr>
</tbody>
</table>

## onPublishFail<a name="ga0f84feec4640c176938bbce26b8f25c8"></a>

```
void(* IPublishCallback::onPublishFail) (int publishId, [PublishFailReason](softbus.md#ga6632fcae1db4a3a13370e3fb49e5e620) reason)
```

 **Description:**

Callback for failed publishing 

## onPublishSuccess<a name="gade0a74f5ae9b16a1fa7f03df5d9fbdf1"></a>

```
void(* IPublishCallback::onPublishSuccess) (int publishId)
```

 **Description:**

Callback for successful publishing 

## onSessionClosed<a name="ga2088a4e0e196030d8e428a828298eba0"></a>

```
void(* ISessionListener::onSessionClosed) (int sessionId)
```

 **Description:**

Called when a session is closed. 

This function can be used to release resources related to the session. You do not need to call  [CloseSession](softbus.md#ga5b0c0b334f387f9c2753146ee0890780).

**Parameters:**

<a name="table1460351485165623"></a>
<table><thead align="left"><tr id="row841755741165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1355936948165623"><a name="p1355936948165623"></a><a name="p1355936948165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1370005088165623"><a name="p1370005088165623"></a><a name="p1370005088165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row830390676165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sessionId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the session ID. </td>
</tr>
</tbody>
</table>

## onSessionOpened<a name="ga2b042b85e03d66f1988c348414b2db6e"></a>

```
int(* ISessionListener::onSessionOpened) (int sessionId)
```

 **Description:**

Called when a session is opened. 

This function can be used to verify the session or initialize resources related to the session.

**Parameters:**

<a name="table2137488407165623"></a>
<table><thead align="left"><tr id="row840434361165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2038897627165623"><a name="p2038897627165623"></a><a name="p2038897627165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1737455375165623"><a name="p1737455375165623"></a><a name="p1737455375165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row712394150165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sessionId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the session ID. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the session connection is accepted; returns a non-zero value otherwise \(you do not need to call  [CloseSession](softbus.md#ga5b0c0b334f387f9c2753146ee0890780)  to close the session\). 

## publishId<a name="ga44a9b46ef719d882d4438a0c34a7f657"></a>

```
int PublishInfo::publishId
```

 **Description:**

[Service](service.md)  publishing ID 

## value \[1/2\]<a name="gaddf75957b595adaddd4f227b9834e20b"></a>

```
char* DeviceMap::value
```

 **Description:**

Name of a device type. Only names defined in  **g\_devMap**  are supported. 

## value \[2/2\]<a name="ga84452c64348251edfe90fc61a5c561ac"></a>

```
const char* CommonDeviceInfo::value
```

 **Description:**

Content to set 

