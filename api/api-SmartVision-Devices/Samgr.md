# Samgr<a name="ZH-CN_TOPIC_0000001055078091"></a>

-   [Overview](#section780157231165625)
-   [Summary](#section39131248165625)
-   [Files](#files)
-   [Data Structures](#nested-classes)
-   [Macros](#define-members)
-   [Typedefs](#typedef-members)
-   [Enumerations](#enum-members)
-   [Functions](#func-members)
-   [Details](#section175715380165625)
-   [Macro Definition](#section944963564165625)
-   [DEFAULT\_IUNKNOWN\_IMPL](#gac8d8c9671531f9340427153d50ca4a2b)
-   [DEFAULT\_VERSION](#ga13dae059206df8d2d9b9b42e694b3f9c)
-   [GET\_IUNKNOWN](#ga9403f55c3f75fd03854dcd37c231e05b)
-   [GET\_OFFSIZE](#gab094855efe05ae51eaaf3e0ddf0346cc)
-   [INHERIT\_FEATURE](#ga63c2f681bde297cb28a9a300a462f3f4)
-   [INHERIT\_IUNKNOWN](#gab74532a22d6993d0ffc014d36253397f)
-   [INHERIT\_IUNKNOWNENTRY](#gad6324fd90dd636180efa2a59b377e65c)
-   [INHERIT\_SERVICE](#gae9253a7fc1d0acbab91414b4cacc1d84)
-   [IUNKNOWN\_ENTRY\_BEGIN](#ga52ec6b5b03d56b0dfe7277785246bda1)
-   [IUNKNOWN\_ENTRY\_END](#ga4ef734474ece49aa938d8ebd5b54bdb3)
-   [Typedef](#section1152235996165625)
-   [BootMessage](#gadc486c8d2698eab8a9f26f0eb6cc63c8)
-   [Handler](#ga5e13d943cc6a87a5c99fe604f3bc01e4)
-   [IUnknownEntry](#gacaa7db32a018a33a2bbf919cde8d8f9c)
-   [SamgrLite](#gaad729fe4f36b7b42a122349af334fb28)
-   [SpecifyTag](#gae9c7eed07272a46851d61e646b6e86d5)
-   [TaskPriority](#gaef69bbb3353ea484414c3bbaf8ec362b)
-   [TaskType](#gab265648f2dbef93878ad8c383712b43a)
-   [Vector](#ga255ca81c214b8a94a90f786ceef94514)
-   [Enumeration Type](#section2050728011165625)
-   [BootMessage](#gaf39e482610dca95f0dba85613755eb40)
-   [SpecifyTag](#ga704a59a45a705ef7a15d16e3cab8c1b0)
-   [TaskPriority](#gaee057e5f06a7b2533e6f58bde34d15fa)
-   [TaskType](#ga026844c14ab62f42a2e19b54d622609b)
-   [Function](#section677802347165625)
-   [IUNKNOWN\_AddRef\(\)](#ga9abef49ec89bf913c3bed03faf478c1e)
-   [IUNKNOWN\_QueryInterface\(\)](#gac857d12648500c7dab1cb43e85ae2ed4)
-   [IUNKNOWN\_Release\(\)](#gabd462f8a5e6460a68760cd0719982296)
-   [SAMGR\_Bootstrap\(\)](#ga756ac1f5376c72aa5d14b855a302d7b6)
-   [SAMGR\_GetInstance\(\)](#ga21f168d6f97d6991115ae1cf8bbd8deb)
-   [SAMGR\_SendRequest\(\)](#ga03b440d8dff9fcc8694ca8a3baa83462)
-   [SAMGR\_SendResponse\(\)](#gadba5f2881a6e1403cb642726d5fec3e2)
-   [SAMGR\_SendResponseByIdentity\(\)](#ga44ab9b4c98e2dd6ba3338d1d2664a6fe)
-   [SAMGR\_SendSharedDirectRequest\(\)](#ga0c8c20d2265f4eb8ec8b516300a94a63)
-   [SAMGR\_SendSharedRequest\(\)](#gae7c4d087b251949d10d81e88a47e8dbd)
-   [VECTOR\_Add\(\)](#ga234ba2452c973e9fa4a8be47eaea9d06)
-   [VECTOR\_At\(\)](#ga75210ba0bd37a38a1902c4904e61246a)
-   [VECTOR\_Clear\(\)](#gaebfe9ac38f2667d61bf39420aa8e7035)
-   [VECTOR\_Find\(\)](#gaabc5b0eda1ee6889411e6dacb233cb07)
-   [VECTOR\_FindByKey\(\)](#gac65bc6dc959a90d95dff93368abd97c7)
-   [VECTOR\_Make\(\)](#gae790345f8a2863c143bfee4bab3fb6d7)
-   [VECTOR\_Num\(\)](#ga90523bfd48091a0135f74670076af4d5)
-   [VECTOR\_Size\(\)](#ga1432f30c136d14bc00414d883d8be3bd)
-   [VECTOR\_Swap\(\)](#ga7f435d33ba61d145de9d5892b68a0eda)

## **Overview**<a name="section780157231165625"></a>

**Description:**

Manages system capabilities. 

This module provides the development framework base of the service-oriented architecture \(SOA\). You can develop your own abilities based on the Samgr development framework. This module provides basic models of services, features, and functions, and registration and discovery capabilities. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section39131248165625"></a>

## Files<a name="files"></a>

<a name="table975760587165625"></a>
<table><thead align="left"><tr id="row548703326165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1156677603165625"><a name="p1156677603165625"></a><a name="p1156677603165625"></a>File Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p927192075165625"><a name="p927192075165625"></a><a name="p927192075165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1764153061165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p760768191165625"><a name="p760768191165625"></a><a name="p760768191165625"></a><a href="common-h.md">common.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2139216317165625"><a name="p2139216317165625"></a><a name="p2139216317165625"></a>Provides common objects and functions for Samgr and external modules. </p>
</td>
</tr>
<tr id="row1408242848165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p579495616165625"><a name="p579495616165625"></a><a name="p579495616165625"></a><a href="feature-h.md">feature.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1850595396165625"><a name="p1850595396165625"></a><a name="p1850595396165625"></a>Defines the base class of a feature. </p>
</td>
</tr>
<tr id="row260101863165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p278444970165625"><a name="p278444970165625"></a><a name="p278444970165625"></a><a href="iunknown-h.md">iunknown.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2111502166165625"><a name="p2111502166165625"></a><a name="p2111502166165625"></a>Provides the base class and default implementation for external functions of system capabilities. </p>
</td>
</tr>
<tr id="row39598694165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1388713119165625"><a name="p1388713119165625"></a><a name="p1388713119165625"></a><a href="message-h.md">message.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p661635599165625"><a name="p661635599165625"></a><a name="p661635599165625"></a>Provides message communication APIs that help you to implement asynchronous functions of <a href="IUnknown.md">IUnknown</a>. </p>
</td>
</tr>
<tr id="row95441114165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p180705159165625"><a name="p180705159165625"></a><a name="p180705159165625"></a><a href="samgr_lite-h.md">samgr_lite.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p624025014165625"><a name="p624025014165625"></a><a name="p624025014165625"></a>Manages system capabilities. </p>
</td>
</tr>
<tr id="row796389694165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1198795947165625"><a name="p1198795947165625"></a><a name="p1198795947165625"></a><a href="service-h.md">service.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1848498197165625"><a name="p1848498197165625"></a><a name="p1848498197165625"></a>Provides basic types and constants of services. </p>
</td>
</tr>
</tbody>
</table>

## Data Structures<a name="nested-classes"></a>

<a name="table2050442521165625"></a>
<table><thead align="left"><tr id="row1557345048165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1587312799165625"><a name="p1587312799165625"></a><a name="p1587312799165625"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p527183728165625"><a name="p527183728165625"></a><a name="p527183728165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row311942878165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p20881578165625"><a name="p20881578165625"></a><a name="p20881578165625"></a><a href="SimpleVector.md">SimpleVector</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p749919288165625"><a name="p749919288165625"></a><a name="p749919288165625"></a>Defines the simplified vector class, which is extended by four elements. </p>
</td>
</tr>
<tr id="row1781377426165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1625987770165625"><a name="p1625987770165625"></a><a name="p1625987770165625"></a><a href="Feature.md">Feature</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1248201599165625"><a name="p1248201599165625"></a><a name="p1248201599165625"></a>Defines the base class of a feature. </p>
</td>
</tr>
<tr id="row2135766804165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p276364693165625"><a name="p276364693165625"></a><a name="p276364693165625"></a><a href="IUnknown.md">IUnknown</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1830864576165625"><a name="p1830864576165625"></a><a name="p1830864576165625"></a>Defines the <strong id="b1617277596165625"><a name="b1617277596165625"></a><a name="b1617277596165625"></a><a href="IUnknown.md">IUnknown</a></strong> class. </p>
</td>
</tr>
<tr id="row313254631165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p395418520165625"><a name="p395418520165625"></a><a name="p395418520165625"></a><a href="IUnknownEntry.md">IUnknownEntry</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2118992505165625"><a name="p2118992505165625"></a><a name="p2118992505165625"></a>Defines the <strong id="b943283125165625"><a name="b943283125165625"></a><a name="b943283125165625"></a><a href="IUnknown.md">IUnknown</a></strong> implementation class. </p>
</td>
</tr>
<tr id="row1822624227165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p780888590165625"><a name="p780888590165625"></a><a name="p780888590165625"></a><a href="Identity.md">Identity</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1531146277165625"><a name="p1531146277165625"></a><a name="p1531146277165625"></a>Identifies a service and feature. </p>
</td>
</tr>
<tr id="row1755255293165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1796480473165625"><a name="p1796480473165625"></a><a name="p1796480473165625"></a><a href="Request.md">Request</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1934248149165625"><a name="p1934248149165625"></a><a name="p1934248149165625"></a>Defines a request. </p>
</td>
</tr>
<tr id="row1688377925165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p638666645165625"><a name="p638666645165625"></a><a name="p638666645165625"></a><a href="Response.md">Response</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1388264624165625"><a name="p1388264624165625"></a><a name="p1388264624165625"></a>Defines a response. </p>
</td>
</tr>
<tr id="row607297495165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p108808040165625"><a name="p108808040165625"></a><a name="p108808040165625"></a><a href="SamgrLite.md">SamgrLite</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p220649670165625"><a name="p220649670165625"></a><a name="p220649670165625"></a>Represents the system ability management class. </p>
</td>
</tr>
<tr id="row1523256080165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p612171719165625"><a name="p612171719165625"></a><a name="p612171719165625"></a><a href="TaskConfig.md">TaskConfig</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2001994669165625"><a name="p2001994669165625"></a><a name="p2001994669165625"></a>Defines task configurations for a service. </p>
</td>
</tr>
<tr id="row2107450262165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p881442310165625"><a name="p881442310165625"></a><a name="p881442310165625"></a><a href="Service.md">Service</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2067455280165625"><a name="p2067455280165625"></a><a name="p2067455280165625"></a>Indicates the basic type of a service. </p>
</td>
</tr>
</tbody>
</table>

## Macros<a name="define-members"></a>

<a name="table741275617165625"></a>
<table><thead align="left"><tr id="row688071757165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p912820357165625"><a name="p912820357165625"></a><a name="p912820357165625"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2077841392165625"><a name="p2077841392165625"></a><a name="p2077841392165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row849999573165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p887838658165625"><a name="p887838658165625"></a><a name="p887838658165625"></a><a href="Samgr.md#gab094855efe05ae51eaaf3e0ddf0346cc">GET_OFFSIZE</a>(T, member)   (long)((char *)&amp;(((T *)(0))-&gt;member))</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p559858089165625"><a name="p559858089165625"></a><a name="p559858089165625"></a>Calculates the offset of the member in the T type. </p>
</td>
</tr>
<tr id="row1195990543165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p692055722165625"><a name="p692055722165625"></a><a name="p692055722165625"></a><a href="Samgr.md#ga63c2f681bde297cb28a9a300a462f3f4">INHERIT_FEATURE</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p17505350165625"><a name="p17505350165625"></a><a name="p17505350165625"></a>Inherits from the macro of the feature class. </p>
</td>
</tr>
<tr id="row672276115165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p432547494165625"><a name="p432547494165625"></a><a name="p432547494165625"></a><a href="Samgr.md#ga13dae059206df8d2d9b9b42e694b3f9c">DEFAULT_VERSION</a>   0x20</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1699460309165625"><a name="p1699460309165625"></a><a name="p1699460309165625"></a>Defines the default <a href="IUnknown.md">IUnknown</a> version. You can customize the version. </p>
</td>
</tr>
<tr id="row1558469693165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1203876690165625"><a name="p1203876690165625"></a><a name="p1203876690165625"></a><a href="Samgr.md#gab74532a22d6993d0ffc014d36253397f">INHERIT_IUNKNOWN</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1137492852165625"><a name="p1137492852165625"></a><a name="p1137492852165625"></a>Defines the macro for inheriting the <strong id="b1614861175165625"><a name="b1614861175165625"></a><a name="b1614861175165625"></a><a href="IUnknown.md">IUnknown</a></strong> interface. </p>
</td>
</tr>
<tr id="row188454676165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1004367142165625"><a name="p1004367142165625"></a><a name="p1004367142165625"></a><a href="Samgr.md#gad6324fd90dd636180efa2a59b377e65c">INHERIT_IUNKNOWNENTRY</a>(T)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p132985411165625"><a name="p132985411165625"></a><a name="p132985411165625"></a>Defines the macro for inheriting the classes that implement the <strong id="b322111377165625"><a name="b322111377165625"></a><a name="b322111377165625"></a><a href="IUnknown.md">IUnknown</a></strong> interface. </p>
</td>
</tr>
<tr id="row64476378165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1744487633165625"><a name="p1744487633165625"></a><a name="p1744487633165625"></a><a href="Samgr.md#gac8d8c9671531f9340427153d50ca4a2b">DEFAULT_IUNKNOWN_IMPL</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1499720930165625"><a name="p1499720930165625"></a><a name="p1499720930165625"></a>Defines the default marco for initializing the <strong id="b120257452165625"><a name="b120257452165625"></a><a name="b120257452165625"></a><a href="IUnknown.md">IUnknown</a></strong> interface. </p>
</td>
</tr>
<tr id="row1081334206165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p297593715165625"><a name="p297593715165625"></a><a name="p297593715165625"></a><a href="Samgr.md#ga52ec6b5b03d56b0dfe7277785246bda1">IUNKNOWN_ENTRY_BEGIN</a>(version)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1950737457165625"><a name="p1950737457165625"></a><a name="p1950737457165625"></a>Defines the macro for initializing the classes that implement the <strong id="b1350038347165625"><a name="b1350038347165625"></a><a name="b1350038347165625"></a><a href="IUnknown.md">IUnknown</a></strong> interface. </p>
</td>
</tr>
<tr id="row730902372165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p145976225165625"><a name="p145976225165625"></a><a name="p145976225165625"></a><a href="Samgr.md#ga4ef734474ece49aa938d8ebd5b54bdb3">IUNKNOWN_ENTRY_END</a>   }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1647436769165625"><a name="p1647436769165625"></a><a name="p1647436769165625"></a><a href="IUnknown.md">IUnknown</a> Defines the end macro for initializing the <strong id="b2074528939165625"><a name="b2074528939165625"></a><a name="b2074528939165625"></a><a href="IUnknown.md">IUnknown</a></strong> implementation object. </p>
</td>
</tr>
<tr id="row1193360103165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p423674263165625"><a name="p423674263165625"></a><a name="p423674263165625"></a><a href="Samgr.md#ga9403f55c3f75fd03854dcd37c231e05b">GET_IUNKNOWN</a>(T)   (<a href="IUnknown.md">IUnknown</a> *)(&amp;((T).iUnknown))</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p238785653165625"><a name="p238785653165625"></a><a name="p238785653165625"></a>Obtains the pointer of the <strong id="b894037023165625"><a name="b894037023165625"></a><a name="b894037023165625"></a><a href="IUnknown.md">IUnknown</a></strong> interface object from the subclass object T (generic macro) of the <strong id="b2034917440165625"><a name="b2034917440165625"></a><a name="b2034917440165625"></a><a href="IUnknown.md">IUnknown</a></strong> implementation class. </p>
</td>
</tr>
<tr id="row495150744165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2133833331165625"><a name="p2133833331165625"></a><a name="p2133833331165625"></a><em id="gadc00f0568236d4538c867ed7194d8960"><a name="gadc00f0568236d4538c867ed7194d8960"></a><a name="gadc00f0568236d4538c867ed7194d8960"></a></em>BOOTSTRAP_SERVICE    "Bootstrap"</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1220855085165625"><a name="p1220855085165625"></a><a name="p1220855085165625"></a>Starts a bootstrap service, which is used by samgr and implemented by system service developers. </p>
</td>
</tr>
<tr id="row1177616161165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p822157578165625"><a name="p822157578165625"></a><a name="p822157578165625"></a><a href="Samgr.md#gae9253a7fc1d0acbab91414b4cacc1d84">INHERIT_SERVICE</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1326892573165625"><a name="p1326892573165625"></a><a name="p1326892573165625"></a>Indicates the macro used to inherit the members from the <strong id="b1335029274165625"><a name="b1335029274165625"></a><a name="b1335029274165625"></a>service</strong> class. </p>
</td>
</tr>
</tbody>
</table>

## Typedefs<a name="typedef-members"></a>

<a name="table251761275165625"></a>
<table><thead align="left"><tr id="row900548006165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1676271012165625"><a name="p1676271012165625"></a><a name="p1676271012165625"></a>Typedef Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p343748940165625"><a name="p343748940165625"></a><a name="p343748940165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row422485546165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2075901206165625"><a name="p2075901206165625"></a><a name="p2075901206165625"></a><a href="Samgr.md#ga255ca81c214b8a94a90f786ceef94514">Vector</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p311448109165625"><a name="p311448109165625"></a><a name="p311448109165625"></a>typedef struct <a href="SimpleVector.md">SimpleVector</a> </p>
<p id="p1210801777165625"><a name="p1210801777165625"></a><a name="p1210801777165625"></a>Defines the simplified vector class, which is extended by four elements. </p>
</td>
</tr>
<tr id="row935359627165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1302736282165625"><a name="p1302736282165625"></a><a name="p1302736282165625"></a><a href="Samgr.md#gacaa7db32a018a33a2bbf919cde8d8f9c">IUnknownEntry</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p103369057165625"><a name="p103369057165625"></a><a name="p103369057165625"></a>typedef struct <a href="IUnknownEntry.md">IUnknownEntry</a> </p>
<p id="p1222269948165625"><a name="p1222269948165625"></a><a name="p1222269948165625"></a>Defines the <strong id="b1874448817165625"><a name="b1874448817165625"></a><a name="b1874448817165625"></a><a href="IUnknown.md">IUnknown</a></strong> implementation class. </p>
</td>
</tr>
<tr id="row1384540215165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p891097901165625"><a name="p891097901165625"></a><a name="p891097901165625"></a><a href="Samgr.md#ga5e13d943cc6a87a5c99fe604f3bc01e4">Handler</a>) (const <a href="Request.md">Request</a> *request, const <a href="Response.md">Response</a> *response)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p776703873165625"><a name="p776703873165625"></a><a name="p776703873165625"></a>typedef void(* </p>
<p id="p1862389547165625"><a name="p1862389547165625"></a><a name="p1862389547165625"></a>Handles asynchronous responses. </p>
</td>
</tr>
<tr id="row1142592329165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p820959958165625"><a name="p820959958165625"></a><a name="p820959958165625"></a><a href="Samgr.md#gadc486c8d2698eab8a9f26f0eb6cc63c8">BootMessage</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1096397769165625"><a name="p1096397769165625"></a><a name="p1096397769165625"></a>typedef enum <a href="Samgr.md#gaf39e482610dca95f0dba85613755eb40">BootMessage</a> </p>
<p id="p1923626067165625"><a name="p1923626067165625"></a><a name="p1923626067165625"></a>Enumerates the IDs of the message to be processed for starting the bootstrap service. </p>
</td>
</tr>
<tr id="row1356399952165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p52787959165625"><a name="p52787959165625"></a><a name="p52787959165625"></a><a href="Samgr.md#gaad729fe4f36b7b42a122349af334fb28">SamgrLite</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1115695479165625"><a name="p1115695479165625"></a><a name="p1115695479165625"></a>typedef struct <a href="SamgrLite.md">SamgrLite</a> </p>
<p id="p58274334165625"><a name="p58274334165625"></a><a name="p58274334165625"></a>Represents the system ability management class. </p>
</td>
</tr>
<tr id="row951417306165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p481952710165625"><a name="p481952710165625"></a><a name="p481952710165625"></a><a href="Samgr.md#gab265648f2dbef93878ad8c383712b43a">TaskType</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1762821556165625"><a name="p1762821556165625"></a><a name="p1762821556165625"></a>typedef enum <a href="Samgr.md#ga026844c14ab62f42a2e19b54d622609b">TaskType</a> </p>
<p id="p1883407546165625"><a name="p1883407546165625"></a><a name="p1883407546165625"></a>Enumerates task types. </p>
</td>
</tr>
<tr id="row1076770515165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1770739499165625"><a name="p1770739499165625"></a><a name="p1770739499165625"></a><a href="Samgr.md#gae9c7eed07272a46851d61e646b6e86d5">SpecifyTag</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p288055782165625"><a name="p288055782165625"></a><a name="p288055782165625"></a>typedef enum <a href="Samgr.md#ga704a59a45a705ef7a15d16e3cab8c1b0">SpecifyTag</a> </p>
<p id="p389640393165625"><a name="p389640393165625"></a><a name="p389640393165625"></a>Specifies the tag for the task shared by multiple services. </p>
</td>
</tr>
<tr id="row398317202165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p991293215165625"><a name="p991293215165625"></a><a name="p991293215165625"></a><a href="Samgr.md#gaef69bbb3353ea484414c3bbaf8ec362b">TaskPriority</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1945185078165625"><a name="p1945185078165625"></a><a name="p1945185078165625"></a>typedef enum <a href="Samgr.md#gaee057e5f06a7b2533e6f58bde34d15fa">TaskPriority</a> </p>
<p id="p1261962504165625"><a name="p1261962504165625"></a><a name="p1261962504165625"></a>Enumerates task priority. </p>
</td>
</tr>
</tbody>
</table>

## Enumerations<a name="enum-members"></a>

<a name="table444200253165625"></a>
<table><thead align="left"><tr id="row176521194165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1029633078165625"><a name="p1029633078165625"></a><a name="p1029633078165625"></a>Enumeration Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p12801599165625"><a name="p12801599165625"></a><a name="p12801599165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row830511653165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1443437801165625"><a name="p1443437801165625"></a><a name="p1443437801165625"></a><a href="Samgr.md#gaf39e482610dca95f0dba85613755eb40">BootMessage</a> { <a href="Samgr.md#ggaf39e482610dca95f0dba85613755eb40aee5f1e07de9a8e2e167f97dd2cc0c2d7">BOOT_SYS_COMPLETED</a>, <a href="Samgr.md#ggaf39e482610dca95f0dba85613755eb40a8b0613200e2b05f9309175fe9bd30ca1">BOOT_APP_COMPLETED</a>, <a href="Samgr.md#ggaf39e482610dca95f0dba85613755eb40a9aff5f5b8378e898076ee326da5cd572">BOOT_REG_SERVICE</a>, <a href="Samgr.md#ggaf39e482610dca95f0dba85613755eb40a515e06399df48a6d93435e7c30745eec">BOOTSTRAP_BUTT</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1627977962165625"><a name="p1627977962165625"></a><a name="p1627977962165625"></a>Enumerates the IDs of the message to be processed for starting the bootstrap service. </p>
</td>
</tr>
<tr id="row1346008978165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1867720206165625"><a name="p1867720206165625"></a><a name="p1867720206165625"></a><a href="Samgr.md#ga026844c14ab62f42a2e19b54d622609b">TaskType</a> { <a href="Samgr.md#gga026844c14ab62f42a2e19b54d622609ba5e16ebf94e3d37c775ce51bbe4468e99">SHARED_TASK</a> = 0, <a href="Samgr.md#gga026844c14ab62f42a2e19b54d622609baa1dcd6759a5b023d945ae8c955e48315">SINGLE_TASK</a> = 1, <a href="Samgr.md#gga026844c14ab62f42a2e19b54d622609ba84f51cfcf3f659a99aabbd85924c5376">SPECIFIED_TASK</a> = 2, <a href="Samgr.md#gga026844c14ab62f42a2e19b54d622609baf1a2b164c6a01dd1290f3e79171a8f11">NO_TASK</a> = 0xFF }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1247662260165625"><a name="p1247662260165625"></a><a name="p1247662260165625"></a>Enumerates task types. </p>
</td>
</tr>
<tr id="row1427332544165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p306501131165625"><a name="p306501131165625"></a><a name="p306501131165625"></a><a href="Samgr.md#ga704a59a45a705ef7a15d16e3cab8c1b0">SpecifyTag</a> { <a href="Samgr.md#gga704a59a45a705ef7a15d16e3cab8c1b0a5cf3038af9f9528363577dd32e4eb955">LEVEL_HIGH</a> = 0, <a href="Samgr.md#gga704a59a45a705ef7a15d16e3cab8c1b0a889647ca5662082ace422e57b1da6647">LEVEL_MIDDLE</a> = 1, <a href="Samgr.md#gga704a59a45a705ef7a15d16e3cab8c1b0a1541ce26187ac34e3e99559669751cf5">LEVEL_LOW</a> = 2, <a href="Samgr.md#gga704a59a45a705ef7a15d16e3cab8c1b0afc8d0aa33bc1d911f92931fa5e287263">LEVEL_CUSTOM_BEGIN</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1207927921165625"><a name="p1207927921165625"></a><a name="p1207927921165625"></a>Specifies the tag for the task shared by multiple services. </p>
</td>
</tr>
<tr id="row1538429150165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p857991279165625"><a name="p857991279165625"></a><a name="p857991279165625"></a><a href="Samgr.md#gaee057e5f06a7b2533e6f58bde34d15fa">TaskPriority</a> {   <a href="Samgr.md#ggaee057e5f06a7b2533e6f58bde34d15faaf8a2513dc9a78bb09c0520af65a3f402">PRI_LOW</a> = 9, <a href="Samgr.md#ggaee057e5f06a7b2533e6f58bde34d15faa6f05a14315026dd5f3e5bc87cf745258">PRI_BELOW_NORMAL</a> = 16, <a href="Samgr.md#ggaee057e5f06a7b2533e6f58bde34d15faa8ffe612e81f7db9099f774b853533063">PRI_NORMAL</a> = 24, <a href="Samgr.md#ggaee057e5f06a7b2533e6f58bde34d15faacb1f8848eb9a8c56779869b418ef9cb6">PRI_ABOVE_NORMAL</a> = 32,   <a href="Samgr.md#ggaee057e5f06a7b2533e6f58bde34d15faab9766c2f87357a5cc6e3b14ccbc2c54b">PRI_BUTT</a> = 39 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p976843705165625"><a name="p976843705165625"></a><a name="p976843705165625"></a>Enumerates task priority. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1255594313165625"></a>
<table><thead align="left"><tr id="row1570192986165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p961256891165625"><a name="p961256891165625"></a><a name="p961256891165625"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p853964324165625"><a name="p853964324165625"></a><a name="p853964324165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1062344577165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1162251516165625"><a name="p1162251516165625"></a><a name="p1162251516165625"></a><a href="Samgr.md#gae790345f8a2863c143bfee4bab3fb6d7">VECTOR_Make</a> (VECTOR_Key key, VECTOR_Compare compare)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p565792033165625"><a name="p565792033165625"></a><a name="p565792033165625"></a><a href="Samgr.md#ga255ca81c214b8a94a90f786ceef94514">Vector</a> </p>
<p id="p146212683165625"><a name="p146212683165625"></a><a name="p146212683165625"></a>Creates or initializes a vector object. </p>
</td>
</tr>
<tr id="row929297238165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2601229165625"><a name="p2601229165625"></a><a name="p2601229165625"></a><a href="Samgr.md#gaebfe9ac38f2667d61bf39420aa8e7035">VECTOR_Clear</a> (<a href="Samgr.md#ga255ca81c214b8a94a90f786ceef94514">Vector</a> *vector)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p871964950165625"><a name="p871964950165625"></a><a name="p871964950165625"></a>void </p>
<p id="p820611887165625"><a name="p820611887165625"></a><a name="p820611887165625"></a>Destruct a vector object. </p>
</td>
</tr>
<tr id="row1636431165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1500123535165625"><a name="p1500123535165625"></a><a name="p1500123535165625"></a><a href="Samgr.md#ga234ba2452c973e9fa4a8be47eaea9d06">VECTOR_Add</a> (<a href="Samgr.md#ga255ca81c214b8a94a90f786ceef94514">Vector</a> *vector, void *element)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1048893505165625"><a name="p1048893505165625"></a><a name="p1048893505165625"></a>int16 </p>
<p id="p1571966241165625"><a name="p1571966241165625"></a><a name="p1571966241165625"></a>Adds an element to the vector. </p>
</td>
</tr>
<tr id="row134353198165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p687734513165625"><a name="p687734513165625"></a><a name="p687734513165625"></a><a href="Samgr.md#ga1432f30c136d14bc00414d883d8be3bd">VECTOR_Size</a> (<a href="Samgr.md#ga255ca81c214b8a94a90f786ceef94514">Vector</a> *vector)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p83340828165625"><a name="p83340828165625"></a><a name="p83340828165625"></a>int16 </p>
<p id="p521841191165625"><a name="p521841191165625"></a><a name="p521841191165625"></a>Obtains the number of elements in the vector, including elements that have been set to <strong id="b307048750165625"><a name="b307048750165625"></a><a name="b307048750165625"></a>NULL</strong>. </p>
</td>
</tr>
<tr id="row1329850222165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1799450339165625"><a name="p1799450339165625"></a><a name="p1799450339165625"></a><a href="Samgr.md#ga90523bfd48091a0135f74670076af4d5">VECTOR_Num</a> (<a href="Samgr.md#ga255ca81c214b8a94a90f786ceef94514">Vector</a> *vector)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1384652875165625"><a name="p1384652875165625"></a><a name="p1384652875165625"></a>int16 </p>
<p id="p1408342011165625"><a name="p1408342011165625"></a><a name="p1408342011165625"></a>Obtains the number of valid elements in the vector, excluding elements that have been set to <strong id="b1722951383165625"><a name="b1722951383165625"></a><a name="b1722951383165625"></a>NULL</strong>. </p>
</td>
</tr>
<tr id="row21753310165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1172804086165625"><a name="p1172804086165625"></a><a name="p1172804086165625"></a><a href="Samgr.md#ga75210ba0bd37a38a1902c4904e61246a">VECTOR_At</a> (<a href="Samgr.md#ga255ca81c214b8a94a90f786ceef94514">Vector</a> *vector, int16 <a href="UTILS.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p644150652165625"><a name="p644150652165625"></a><a name="p644150652165625"></a>void * </p>
<p id="p1076240784165625"><a name="p1076240784165625"></a><a name="p1076240784165625"></a>Obtains the element at a specified position. </p>
</td>
</tr>
<tr id="row547094548165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p67262265165625"><a name="p67262265165625"></a><a name="p67262265165625"></a><a href="Samgr.md#ga7f435d33ba61d145de9d5892b68a0eda">VECTOR_Swap</a> (<a href="Samgr.md#ga255ca81c214b8a94a90f786ceef94514">Vector</a> *vector, int16 <a href="UTILS.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>, void *element)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p423266754165625"><a name="p423266754165625"></a><a name="p423266754165625"></a>void * </p>
<p id="p2071063804165625"><a name="p2071063804165625"></a><a name="p2071063804165625"></a>Swaps the element at a specified position in a vector with another element. </p>
</td>
</tr>
<tr id="row1041045436165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p20172340165625"><a name="p20172340165625"></a><a name="p20172340165625"></a><a href="Samgr.md#gaabc5b0eda1ee6889411e6dacb233cb07">VECTOR_Find</a> (<a href="Samgr.md#ga255ca81c214b8a94a90f786ceef94514">Vector</a> *vector, const void *element)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1969835643165625"><a name="p1969835643165625"></a><a name="p1969835643165625"></a>int16 </p>
<p id="p1999920835165625"><a name="p1999920835165625"></a><a name="p1999920835165625"></a>Checks the position of an element. </p>
</td>
</tr>
<tr id="row1857845846165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p676267485165625"><a name="p676267485165625"></a><a name="p676267485165625"></a><a href="Samgr.md#gac65bc6dc959a90d95dff93368abd97c7">VECTOR_FindByKey</a> (<a href="Samgr.md#ga255ca81c214b8a94a90f786ceef94514">Vector</a> *vector, const void *key)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p512188227165625"><a name="p512188227165625"></a><a name="p512188227165625"></a>int16 </p>
<p id="p1764523414165625"><a name="p1764523414165625"></a><a name="p1764523414165625"></a>Checks the position of the element with a specified key. </p>
</td>
</tr>
<tr id="row1340687406165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1426135706165625"><a name="p1426135706165625"></a><a name="p1426135706165625"></a><a href="Samgr.md#ga9abef49ec89bf913c3bed03faf478c1e">IUNKNOWN_AddRef</a> (<a href="IUnknown.md">IUnknown</a> *iUnknown)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p352429445165625"><a name="p352429445165625"></a><a name="p352429445165625"></a>int </p>
<p id="p1214098831165625"><a name="p1214098831165625"></a><a name="p1214098831165625"></a>Increments the reference count in this <strong id="b335769231165625"><a name="b335769231165625"></a><a name="b335769231165625"></a><a href="IUnknown.md">IUnknown</a></strong> interface. </p>
</td>
</tr>
<tr id="row145209140165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p168495826165625"><a name="p168495826165625"></a><a name="p168495826165625"></a><a href="Samgr.md#gac857d12648500c7dab1cb43e85ae2ed4">IUNKNOWN_QueryInterface</a> (<a href="IUnknown.md">IUnknown</a> *iUnknown, int ver, void **target)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p206810422165625"><a name="p206810422165625"></a><a name="p206810422165625"></a>int </p>
<p id="p114418100165625"><a name="p114418100165625"></a><a name="p114418100165625"></a>Queries the <strong id="b221323404165625"><a name="b221323404165625"></a><a name="b221323404165625"></a><a href="IUnknown.md">IUnknown</a></strong> interfaces of a specified version (downcasting). </p>
</td>
</tr>
<tr id="row14865842165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p624753312165625"><a name="p624753312165625"></a><a name="p624753312165625"></a><a href="Samgr.md#gabd462f8a5e6460a68760cd0719982296">IUNKNOWN_Release</a> (<a href="IUnknown.md">IUnknown</a> *iUnknown)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1922795704165625"><a name="p1922795704165625"></a><a name="p1922795704165625"></a>int </p>
<p id="p1112037127165625"><a name="p1112037127165625"></a><a name="p1112037127165625"></a>Releases a reference to an <strong id="b1292450618165625"><a name="b1292450618165625"></a><a name="b1292450618165625"></a><a href="IUnknown.md">IUnknown</a></strong> interface that is no longer used. </p>
</td>
</tr>
<tr id="row1055716126165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p989311238165625"><a name="p989311238165625"></a><a name="p989311238165625"></a><a href="Samgr.md#ga03b440d8dff9fcc8694ca8a3baa83462">SAMGR_SendRequest</a> (const <a href="Identity.md">Identity</a> *identity, const <a href="Request.md">Request</a> *request, <a href="Samgr.md#ga5e13d943cc6a87a5c99fe604f3bc01e4">Handler</a> handler)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p328355210165625"><a name="p328355210165625"></a><a name="p328355210165625"></a>int32 </p>
<p id="p1576559110165625"><a name="p1576559110165625"></a><a name="p1576559110165625"></a>Sends a request to a service or feature of a specified identity. </p>
</td>
</tr>
<tr id="row1543857226165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p958036230165625"><a name="p958036230165625"></a><a name="p958036230165625"></a><a href="Samgr.md#gae7c4d087b251949d10d81e88a47e8dbd">SAMGR_SendSharedRequest</a> (const <a href="Identity.md">Identity</a> *identity, const <a href="Request.md">Request</a> *request, uint32 *token, <a href="Samgr.md#ga5e13d943cc6a87a5c99fe604f3bc01e4">Handler</a> handler)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p168463574165625"><a name="p168463574165625"></a><a name="p168463574165625"></a>uint32 * </p>
<p id="p869581955165625"><a name="p869581955165625"></a><a name="p869581955165625"></a>Sends a request to multiple services or features to save memory. </p>
</td>
</tr>
<tr id="row1564182322165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p265434472165625"><a name="p265434472165625"></a><a name="p265434472165625"></a><a href="Samgr.md#ga0c8c20d2265f4eb8ec8b516300a94a63">SAMGR_SendSharedDirectRequest</a> (const <a href="Identity.md">Identity</a> *id, const <a href="Request.md">Request</a> *req, const <a href="Response.md">Response</a> *resp, uint32 **ref, <a href="Samgr.md#ga5e13d943cc6a87a5c99fe604f3bc01e4">Handler</a> handler)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p434433792165625"><a name="p434433792165625"></a><a name="p434433792165625"></a>int32 </p>
<p id="p460809519165625"><a name="p460809519165625"></a><a name="p460809519165625"></a>Sends a request and response of a caller to the feature thread. The handler is directly called to process the request and response without using the message processing functions. (Customized function for the broadcast service) </p>
</td>
</tr>
<tr id="row1069992573165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1618620912165625"><a name="p1618620912165625"></a><a name="p1618620912165625"></a><a href="Samgr.md#gadba5f2881a6e1403cb642726d5fec3e2">SAMGR_SendResponse</a> (const <a href="Request.md">Request</a> *request, const <a href="Response.md">Response</a> *response)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1180380390165625"><a name="p1180380390165625"></a><a name="p1180380390165625"></a>int32 </p>
<p id="p539952241165625"><a name="p539952241165625"></a><a name="p539952241165625"></a>Sends a response after processing a request. </p>
</td>
</tr>
<tr id="row60771302165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2107907103165625"><a name="p2107907103165625"></a><a name="p2107907103165625"></a><a href="Samgr.md#ga44ab9b4c98e2dd6ba3338d1d2664a6fe">SAMGR_SendResponseByIdentity</a> (const <a href="Identity.md">Identity</a> *id, const <a href="Request.md">Request</a> *request, const <a href="Response.md">Response</a> *response)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p268693144165625"><a name="p268693144165625"></a><a name="p268693144165625"></a>int32 </p>
<p id="p1873035755165625"><a name="p1873035755165625"></a><a name="p1873035755165625"></a>Sends a response to a specified service or feature after processing the original request. (Customized function for <strong id="b1689479327165625"><a name="b1689479327165625"></a><a name="b1689479327165625"></a>bootstrap</strong>) </p>
</td>
</tr>
<tr id="row514912374165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1846040882165625"><a name="p1846040882165625"></a><a name="p1846040882165625"></a><a href="Samgr.md#ga21f168d6f97d6991115ae1cf8bbd8deb">SAMGR_GetInstance</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p335443813165625"><a name="p335443813165625"></a><a name="p335443813165625"></a><a href="SamgrLite.md">SamgrLite</a> * </p>
<p id="p1730232560165625"><a name="p1730232560165625"></a><a name="p1730232560165625"></a>Obtains the singleton Samgr instance. </p>
</td>
</tr>
<tr id="row2039651111165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p833169049165625"><a name="p833169049165625"></a><a name="p833169049165625"></a><a href="Samgr.md#ga756ac1f5376c72aa5d14b855a302d7b6">SAMGR_Bootstrap</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1344442325165625"><a name="p1344442325165625"></a><a name="p1344442325165625"></a>void </p>
<p id="p346350135165625"><a name="p346350135165625"></a><a name="p346350135165625"></a>Starts system services and features. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section175715380165625"></a>

## **Macro Definition **<a name="section944963564165625"></a>

## DEFAULT\_IUNKNOWN\_IMPL<a name="gac8d8c9671531f9340427153d50ca4a2b"></a>

```
#define DEFAULT_IUNKNOWN_IMPL
```

```
Values: .QueryInterface = [IUNKNOWN_QueryInterface](Samgr.md#gac857d12648500c7dab1cb43e85ae2ed4), \

 .AddRef = [IUNKNOWN_AddRef](Samgr.md#ga9abef49ec89bf913c3bed03faf478c1e), \

 .Release = [IUNKNOWN_Release](Samgr.md#gabd462f8a5e6460a68760cd0719982296)


```

 **Description:**

Defines the default marco for initializing the  **[IUnknown](IUnknown.md)**  interface. 

When creating a subclass object of the  **[IUnknown](IUnknown.md)**  interface, you can use this macro to initialize members of the  **[IUnknown](IUnknown.md)**  interface to their default values. 

## DEFAULT\_VERSION<a name="ga13dae059206df8d2d9b9b42e694b3f9c"></a>

```
#define DEFAULT_VERSION   0x20
```

 **Description:**

Defines the default  [IUnknown](IUnknown.md)  version. You can customize the version. 

The  **[IUnknown](IUnknown.md)**  interface of the default version can be called only in the current process. Inter-process communication is not supported. 

## GET\_IUNKNOWN<a name="ga9403f55c3f75fd03854dcd37c231e05b"></a>

```
#define GET_IUNKNOWN( T)   ([IUnknown](IUnknown.md) *)(&((T).iUnknown))
```

 **Description:**

Obtains the pointer of the  **[IUnknown](IUnknown.md)**  interface object from the subclass object T \(generic macro\) of the  **[IUnknown](IUnknown.md)**  implementation class. 

Use this macro when registering  **[IUnknown](IUnknown.md)**  interfaces with Samgr so that you can obtain the interfaces from the subclass objects of different  **[IUnknown](IUnknown.md)**  implementation classes. 

## GET\_OFFSIZE<a name="gab094855efe05ae51eaaf3e0ddf0346cc"></a>

```
#define GET_OFFSIZE( T,  member )   (long)((char *)&(((T *)(0))->member))
```

 **Description:**

Calculates the offset of the member in the T type. 

**Parameters:**

<a name="table1425767620165625"></a>
<table><thead align="left"><tr id="row1743992741165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1069542937165625"><a name="p1069542937165625"></a><a name="p1069542937165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1786643570165625"><a name="p1786643570165625"></a><a name="p1786643570165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1445507787165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">Indicates</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">the T type. </td>
</tr>
<tr id="row20919468165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">member</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the name of the T member variable.</td>
</tr>
</tbody>
</table>

## INHERIT\_FEATURE<a name="ga63c2f681bde297cb28a9a300a462f3f4"></a>

```
#define INHERIT_FEATURE
```

```
Values: const char *(*GetName)([Feature](Feature.md) *feature); \

 void (*OnInitialize)([Feature](Feature.md) *feature, [Service](Service.md) *parent, [Identity](Identity.md) identity); \

 void (*OnStop)([Feature](Feature.md) *feature, [Identity](Identity.md) identity); \

 BOOL (*OnMessage)([Feature](Feature.md) *feature, [Request](Request.md) *request)


```

 **Description:**

Inherits from the macro of the feature class. 

This macro provides the capability of inheriting the feature lifecycle. 

## INHERIT\_IUNKNOWN<a name="gab74532a22d6993d0ffc014d36253397f"></a>

```
#define INHERIT_IUNKNOWN
```

```
Values: int (*QueryInterface)([IUnknown](IUnknown.md) *iUnknown, int version, void **target); \

 int (*AddRef)([IUnknown](IUnknown.md) *iUnknown); \

 int (*Release)([IUnknown](IUnknown.md) *iUnknown)


```

 **Description:**

Defines the macro for inheriting the  **[IUnknown](IUnknown.md)**  interface. 

When developing a subclass of the  **[IUnknown](IUnknown.md)**  class, you can use this macro to inherit the structures of the  **[IUnknown](IUnknown.md)**  interface. 

## INHERIT\_IUNKNOWNENTRY<a name="gad6324fd90dd636180efa2a59b377e65c"></a>

```
#define INHERIT_IUNKNOWNENTRY( T)
```

```
Values: uint16 ver; \

 int16 ref; \

 T iUnknown


```

 **Description:**

Defines the macro for inheriting the classes that implement the  **[IUnknown](IUnknown.md)**  interface. 

When developing a subclass of a class that implements the  **[IUnknown](IUnknown.md)**  interface, you can use this macro to inherit the structures of the  **[IUnknown](IUnknown.md)**  implementation class. 

## INHERIT\_SERVICE<a name="gae9253a7fc1d0acbab91414b4cacc1d84"></a>

```
#define INHERIT_SERVICE
```

```
Values: const char *(*GetName)([Service](Service.md) * service); \

 BOOL (*Initialize)([Service](Service.md) * service, [Identity](Identity.md) identity); \

 BOOL (*MessageHandle)([Service](Service.md) * service, [Request](Request.md) * request); \

 TaskConfig (*GetTaskConfig)([Service](Service.md) * service)


```

 **Description:**

Indicates the macro used to inherit the members from the  **service**  class. 

This macro provides the capability of inheriting the lifecycle functions of the  **service**  class. You can use this macro to customize the service structure. 

## IUNKNOWN\_ENTRY\_BEGIN<a name="ga52ec6b5b03d56b0dfe7277785246bda1"></a>

```
#define IUNKNOWN_ENTRY_BEGIN( version)
```

```
Values: .ver = (version), \

 .ref = 1, \

 .iUnknown = { \

 DEFAULT_IUNKNOWN_IMPL


```

 **Description:**

Defines the macro for initializing the classes that implement the  **[IUnknown](IUnknown.md)**  interface. 

When creating a subclass object of a class that implements the  **[IUnknown](IUnknown.md)**  interface, you can use this macro to initialize members of the  **[IUnknown](IUnknown.md)**  implementation class to their default values. You need to add the initialization of the customized member variable. 

## IUNKNOWN\_ENTRY\_END<a name="ga4ef734474ece49aa938d8ebd5b54bdb3"></a>

```
#define IUNKNOWN_ENTRY_END   }
```

 **Description:**

[IUnknown](IUnknown.md)  Defines the end macro for initializing the  **[IUnknown](IUnknown.md)**  implementation object. 

This macro is used when a subclass object of the  **[IUnknown](IUnknown.md)**  implementation class is initialized. 

## **Typedef **<a name="section1152235996165625"></a>

## BootMessage<a name="gadc486c8d2698eab8a9f26f0eb6cc63c8"></a>

```
typedef enum [BootMessage](Samgr.md#gaf39e482610dca95f0dba85613755eb40) [BootMessage](Samgr.md#gaf39e482610dca95f0dba85613755eb40)
```

 **Description:**

Enumerates the IDs of the message to be processed for starting the bootstrap service. 

This function is implemented by developers of the system service. Messages sent to the bootstrap service when Samgr is started. 

## Handler<a name="ga5e13d943cc6a87a5c99fe604f3bc01e4"></a>

```
typedef void(* Handler) (const [Request](Request.md) *request, const [Response](Response.md) *response)
```

 **Description:**

Handles asynchronous responses. 

This function will be used when a service or feature uses  [IUnknown](IUnknown.md)  to send a request. If the caller is a feature, this function is used to handle the response that is sent after the feature processes a request. If the caller is a service,  **Handler**  will run in the service thread. 

## IUnknownEntry<a name="gacaa7db32a018a33a2bbf919cde8d8f9c"></a>

```
typedef struct [IUnknownEntry](IUnknownEntry.md) [IUnknownEntry](IUnknownEntry.md)
```

 **Description:**

Defines the  **[IUnknown](IUnknown.md)**  implementation class. 

You need to inherit this structure when developing a subclass of the  **[IUnknown](IUnknown.md)**  implementation class. Each  **[IUnknown](IUnknown.md)**  interface must correspond to one or more  **[IUnknown](IUnknown.md)**  implementation classes. 

## SamgrLite<a name="gaad729fe4f36b7b42a122349af334fb28"></a>

```
typedef struct [SamgrLite](SamgrLite.md) [SamgrLite](SamgrLite.md)
```

 **Description:**

Represents the system ability management class. 

This class is used for registering and discovering services, features, and functions. 

## SpecifyTag<a name="gae9c7eed07272a46851d61e646b6e86d5"></a>

```
typedef enum [SpecifyTag](Samgr.md#ga704a59a45a705ef7a15d16e3cab8c1b0) [SpecifyTag](Samgr.md#ga704a59a45a705ef7a15d16e3cab8c1b0)
```

 **Description:**

Specifies the tag for the task shared by multiple services. 

These enumerations are used for specifying a multi-service sharing task. 

## TaskPriority<a name="gaef69bbb3353ea484414c3bbaf8ec362b"></a>

```
typedef enum [TaskPriority](Samgr.md#gaee057e5f06a7b2533e6f58bde34d15fa) [TaskPriority](Samgr.md#gaee057e5f06a7b2533e6f58bde34d15fa)
```

 **Description:**

Enumerates task priority. 

These enumerations are used for configuring the task priority. The valid range of the priority is \(9, 39\). 

## TaskType<a name="gab265648f2dbef93878ad8c383712b43a"></a>

```
typedef enum [TaskType](Samgr.md#ga026844c14ab62f42a2e19b54d622609b) [TaskType](Samgr.md#ga026844c14ab62f42a2e19b54d622609b)
```

 **Description:**

Enumerates task types. 

These enumerations are used for configuring the task type. 

## Vector<a name="ga255ca81c214b8a94a90f786ceef94514"></a>

```
typedef struct [SimpleVector](SimpleVector.md) [Vector](Samgr.md#ga255ca81c214b8a94a90f786ceef94514)
```

 **Description:**

Defines the simplified vector class, which is extended by four elements. 

This class is applicable to the C language development scenario where the data volume is small and dynamic expansion is required. 

## **Enumeration Type **<a name="section2050728011165625"></a>

## BootMessage<a name="gaf39e482610dca95f0dba85613755eb40"></a>

```
enum [BootMessage](Samgr.md#gaf39e482610dca95f0dba85613755eb40)
```

 **Description:**

Enumerates the IDs of the message to be processed for starting the bootstrap service. 

This function is implemented by developers of the system service. Messages sent to the bootstrap service when Samgr is started. 

<a name="table1264700368165625"></a>
<table><thead align="left"><tr id="row527424488165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1363962032165625"><a name="p1363962032165625"></a><a name="p1363962032165625"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1847009539165625"><a name="p1847009539165625"></a><a name="p1847009539165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row872849312165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaf39e482610dca95f0dba85613755eb40aee5f1e07de9a8e2e167f97dd2cc0c2d7"><a name="ggaf39e482610dca95f0dba85613755eb40aee5f1e07de9a8e2e167f97dd2cc0c2d7"></a><a name="ggaf39e482610dca95f0dba85613755eb40aee5f1e07de9a8e2e167f97dd2cc0c2d7"></a></strong>BOOT_SYS_COMPLETED </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p228425520165625"><a name="p228425520165625"></a><a name="p228425520165625"></a>Message indicating that the core system service is initialized </p>
 </td>
</tr>
<tr id="row687499333165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaf39e482610dca95f0dba85613755eb40a8b0613200e2b05f9309175fe9bd30ca1"><a name="ggaf39e482610dca95f0dba85613755eb40a8b0613200e2b05f9309175fe9bd30ca1"></a><a name="ggaf39e482610dca95f0dba85613755eb40a8b0613200e2b05f9309175fe9bd30ca1"></a></strong>BOOT_APP_COMPLETED </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1415697256165625"><a name="p1415697256165625"></a><a name="p1415697256165625"></a>Message indicating that the system and application-layer services are initialized </p>
 </td>
</tr>
<tr id="row837299460165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaf39e482610dca95f0dba85613755eb40a9aff5f5b8378e898076ee326da5cd572"><a name="ggaf39e482610dca95f0dba85613755eb40a9aff5f5b8378e898076ee326da5cd572"></a><a name="ggaf39e482610dca95f0dba85613755eb40a9aff5f5b8378e898076ee326da5cd572"></a></strong>BOOT_REG_SERVICE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1493408900165625"><a name="p1493408900165625"></a><a name="p1493408900165625"></a>Message indicating service registration during running </p>
 </td>
</tr>
<tr id="row1933366010165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaf39e482610dca95f0dba85613755eb40a515e06399df48a6d93435e7c30745eec"><a name="ggaf39e482610dca95f0dba85613755eb40a515e06399df48a6d93435e7c30745eec"></a><a name="ggaf39e482610dca95f0dba85613755eb40a515e06399df48a6d93435e7c30745eec"></a></strong>BOOTSTRAP_BUTT </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p621192292165625"><a name="p621192292165625"></a><a name="p621192292165625"></a>Maximum number of message IDs </p>
 </td>
</tr>
</tbody>
</table>

## SpecifyTag<a name="ga704a59a45a705ef7a15d16e3cab8c1b0"></a>

```
enum [SpecifyTag](Samgr.md#ga704a59a45a705ef7a15d16e3cab8c1b0)
```

 **Description:**

Specifies the tag for the task shared by multiple services. 

These enumerations are used for specifying a multi-service sharing task. 

<a name="table1368228761165625"></a>
<table><thead align="left"><tr id="row560675988165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2042410923165625"><a name="p2042410923165625"></a><a name="p2042410923165625"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1365518763165625"><a name="p1365518763165625"></a><a name="p1365518763165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row224246592165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga704a59a45a705ef7a15d16e3cab8c1b0a5cf3038af9f9528363577dd32e4eb955"><a name="gga704a59a45a705ef7a15d16e3cab8c1b0a5cf3038af9f9528363577dd32e4eb955"></a><a name="gga704a59a45a705ef7a15d16e3cab8c1b0a5cf3038af9f9528363577dd32e4eb955"></a></strong>LEVEL_HIGH </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1040469123165625"><a name="p1040469123165625"></a><a name="p1040469123165625"></a>Preset tag </p>
 </td>
</tr>
<tr id="row474899579165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga704a59a45a705ef7a15d16e3cab8c1b0a889647ca5662082ace422e57b1da6647"><a name="gga704a59a45a705ef7a15d16e3cab8c1b0a889647ca5662082ace422e57b1da6647"></a><a name="gga704a59a45a705ef7a15d16e3cab8c1b0a889647ca5662082ace422e57b1da6647"></a></strong>LEVEL_MIDDLE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p394646725165625"><a name="p394646725165625"></a><a name="p394646725165625"></a>Preset tag </p>
 </td>
</tr>
<tr id="row1301343255165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga704a59a45a705ef7a15d16e3cab8c1b0a1541ce26187ac34e3e99559669751cf5"><a name="gga704a59a45a705ef7a15d16e3cab8c1b0a1541ce26187ac34e3e99559669751cf5"></a><a name="gga704a59a45a705ef7a15d16e3cab8c1b0a1541ce26187ac34e3e99559669751cf5"></a></strong>LEVEL_LOW </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p958834939165625"><a name="p958834939165625"></a><a name="p958834939165625"></a>Preset tag </p>
 </td>
</tr>
<tr id="row325208625165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga704a59a45a705ef7a15d16e3cab8c1b0afc8d0aa33bc1d911f92931fa5e287263"><a name="gga704a59a45a705ef7a15d16e3cab8c1b0afc8d0aa33bc1d911f92931fa5e287263"></a><a name="gga704a59a45a705ef7a15d16e3cab8c1b0afc8d0aa33bc1d911f92931fa5e287263"></a></strong>LEVEL_CUSTOM_BEGIN </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p876942227165625"><a name="p876942227165625"></a><a name="p876942227165625"></a>Customized tag </p>
 </td>
</tr>
</tbody>
</table>

## TaskPriority<a name="gaee057e5f06a7b2533e6f58bde34d15fa"></a>

```
enum [TaskPriority](Samgr.md#gaee057e5f06a7b2533e6f58bde34d15fa)
```

 **Description:**

Enumerates task priority. 

These enumerations are used for configuring the task priority. The valid range of the priority is \(9, 39\). 

<a name="table930137050165625"></a>
<table><thead align="left"><tr id="row1800378288165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1513781819165625"><a name="p1513781819165625"></a><a name="p1513781819165625"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1203843569165625"><a name="p1203843569165625"></a><a name="p1203843569165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1980149957165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaee057e5f06a7b2533e6f58bde34d15faaf8a2513dc9a78bb09c0520af65a3f402"><a name="ggaee057e5f06a7b2533e6f58bde34d15faaf8a2513dc9a78bb09c0520af65a3f402"></a><a name="ggaee057e5f06a7b2533e6f58bde34d15faaf8a2513dc9a78bb09c0520af65a3f402"></a></strong>PRI_LOW </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1795881645165625"><a name="p1795881645165625"></a><a name="p1795881645165625"></a>Low-priority: (9, 15) </p>
 </td>
</tr>
<tr id="row2030501821165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaee057e5f06a7b2533e6f58bde34d15faa6f05a14315026dd5f3e5bc87cf745258"><a name="ggaee057e5f06a7b2533e6f58bde34d15faa6f05a14315026dd5f3e5bc87cf745258"></a><a name="ggaee057e5f06a7b2533e6f58bde34d15faa6f05a14315026dd5f3e5bc87cf745258"></a></strong>PRI_BELOW_NORMAL </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1775006416165625"><a name="p1775006416165625"></a><a name="p1775006416165625"></a>Lower than the normal priority: [16, 23) </p>
 </td>
</tr>
<tr id="row460622073165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaee057e5f06a7b2533e6f58bde34d15faa8ffe612e81f7db9099f774b853533063"><a name="ggaee057e5f06a7b2533e6f58bde34d15faa8ffe612e81f7db9099f774b853533063"></a><a name="ggaee057e5f06a7b2533e6f58bde34d15faa8ffe612e81f7db9099f774b853533063"></a></strong>PRI_NORMAL </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1236426124165625"><a name="p1236426124165625"></a><a name="p1236426124165625"></a>Normal priority: [24, 31). The log service is available. </p>
 </td>
</tr>
<tr id="row385207064165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaee057e5f06a7b2533e6f58bde34d15faacb1f8848eb9a8c56779869b418ef9cb6"><a name="ggaee057e5f06a7b2533e6f58bde34d15faacb1f8848eb9a8c56779869b418ef9cb6"></a><a name="ggaee057e5f06a7b2533e6f58bde34d15faacb1f8848eb9a8c56779869b418ef9cb6"></a></strong>PRI_ABOVE_NORMAL </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1444946687165625"><a name="p1444946687165625"></a><a name="p1444946687165625"></a>Higher than the normal priority: [32, 39). The communication service is available. </p>
 </td>
</tr>
<tr id="row1061004461165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaee057e5f06a7b2533e6f58bde34d15faab9766c2f87357a5cc6e3b14ccbc2c54b"><a name="ggaee057e5f06a7b2533e6f58bde34d15faab9766c2f87357a5cc6e3b14ccbc2c54b"></a><a name="ggaee057e5f06a7b2533e6f58bde34d15faab9766c2f87357a5cc6e3b14ccbc2c54b"></a></strong>PRI_BUTT </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p579969851165625"><a name="p579969851165625"></a><a name="p579969851165625"></a>Upper limit of the priority </p>
 </td>
</tr>
</tbody>
</table>

## TaskType<a name="ga026844c14ab62f42a2e19b54d622609b"></a>

```
enum [TaskType](Samgr.md#ga026844c14ab62f42a2e19b54d622609b)
```

 **Description:**

Enumerates task types. 

These enumerations are used for configuring the task type. 

<a name="table1585314902165625"></a>
<table><thead align="left"><tr id="row1605457905165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p603963124165625"><a name="p603963124165625"></a><a name="p603963124165625"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p468881651165625"><a name="p468881651165625"></a><a name="p468881651165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1319740939165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga026844c14ab62f42a2e19b54d622609ba5e16ebf94e3d37c775ce51bbe4468e99"><a name="gga026844c14ab62f42a2e19b54d622609ba5e16ebf94e3d37c775ce51bbe4468e99"></a><a name="gga026844c14ab62f42a2e19b54d622609ba5e16ebf94e3d37c775ce51bbe4468e99"></a></strong>SHARED_TASK </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p478413408165625"><a name="p478413408165625"></a><a name="p478413408165625"></a>Tasks shared based on their priority by services </p>
 </td>
</tr>
<tr id="row117543697165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga026844c14ab62f42a2e19b54d622609baa1dcd6759a5b023d945ae8c955e48315"><a name="gga026844c14ab62f42a2e19b54d622609baa1dcd6759a5b023d945ae8c955e48315"></a><a name="gga026844c14ab62f42a2e19b54d622609baa1dcd6759a5b023d945ae8c955e48315"></a></strong>SINGLE_TASK </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p581874763165625"><a name="p581874763165625"></a><a name="p581874763165625"></a>Task exclusively occupied by a service </p>
 </td>
</tr>
<tr id="row794337353165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga026844c14ab62f42a2e19b54d622609ba84f51cfcf3f659a99aabbd85924c5376"><a name="gga026844c14ab62f42a2e19b54d622609ba84f51cfcf3f659a99aabbd85924c5376"></a><a name="gga026844c14ab62f42a2e19b54d622609ba84f51cfcf3f659a99aabbd85924c5376"></a></strong>SPECIFIED_TASK </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p584884456165625"><a name="p584884456165625"></a><a name="p584884456165625"></a>A specified task shared by multiple services </p>
 </td>
</tr>
<tr id="row982919356165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga026844c14ab62f42a2e19b54d622609baf1a2b164c6a01dd1290f3e79171a8f11"><a name="gga026844c14ab62f42a2e19b54d622609baf1a2b164c6a01dd1290f3e79171a8f11"></a><a name="gga026844c14ab62f42a2e19b54d622609baf1a2b164c6a01dd1290f3e79171a8f11"></a></strong>NO_TASK </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p264313164165625"><a name="p264313164165625"></a><a name="p264313164165625"></a>No task for the service. Generally, this situation does not occur. </p>
 </td>
</tr>
</tbody>
</table>

## **Function **<a name="section677802347165625"></a>

## IUNKNOWN\_AddRef\(\)<a name="ga9abef49ec89bf913c3bed03faf478c1e"></a>

```
int IUNKNOWN_AddRef ([IUnknown](IUnknown.md) * iUnknown)
```

 **Description:**

Increments the reference count in this  **[IUnknown](IUnknown.md)**  interface. 

This function is called in  **QueryInterface**. Do not call this function in the  **[IUnknown](IUnknown.md)** interface. When the  **QueryInterface**  function is re-implemented, you need to call this function in the new  **QueryInterface**.****

****The system does not provide a lock to protect functions. Therefore, you need to re-implement functions if multiple developers are using them. ****

**Parameters:**

## IUNKNOWN\_QueryInterface\(\)<a name="gac857d12648500c7dab1cb43e85ae2ed4"></a>

```
int IUNKNOWN_QueryInterface ([IUnknown](IUnknown.md) * iUnknown, int ver, void ** target )
```

 **Description:**

Queries the  **[IUnknown](IUnknown.md)**  interfaces of a specified version \(downcasting\). 

After obtaining the  **[IUnknown](IUnknown.md)**  interface object, the function caller uses  **QueryInterface**  to convert the object to the required subclass type. The system converts  [DEFAULT\_VERSION](Samgr.md#ga13dae059206df8d2d9b9b42e694b3f9c)  into the subclass type required by the caller. If the type conversion requirements cannot be met, you need to re-implement this function. 

**Parameters:**

<a name="table2093998449165625"></a>
<table><thead align="left"><tr id="row1814318388165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1385322208165625"><a name="p1385322208165625"></a><a name="p1385322208165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p160884586165625"><a name="p160884586165625"></a><a name="p160884586165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row445722158165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">iUnknown</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the <strong id="b1615053267165625"><a name="b1615053267165625"></a><a name="b1615053267165625"></a><a href="IUnknown.md">IUnknown</a></strong> interface. </td>
</tr>
<tr id="row969608143165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">version</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the version of the <strong id="b2066200732165625"><a name="b2066200732165625"></a><a name="b2066200732165625"></a><a href="IUnknown.md">IUnknown</a></strong> interface object to be converted. </td>
</tr>
<tr id="row1243410846165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">target</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the <strong id="b1792094388165625"><a name="b1792094388165625"></a><a name="b1792094388165625"></a><a href="IUnknown.md">IUnknown</a></strong> subclass type required by the caller. This is an output parameter. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **EC\_SUCCESS**  if the conversion is successful; returns other error codes if the conversion fails.

## IUNKNOWN\_Release\(\)<a name="gabd462f8a5e6460a68760cd0719982296"></a>

```
int IUNKNOWN_Release ([IUnknown](IUnknown.md) * iUnknown)
```

 **Description:**

Releases a reference to an  **[IUnknown](IUnknown.md)**  interface that is no longer used. 

In the default implementation provided by the system, if the reference count is  **0**, the memory of the  **[IUnknown](IUnknown.md)**  interface object and implementation object is not released. If the memory of the  **[IUnknown](IUnknown.md)**  interface object and implementation object is dynamically allocated, this function needs to be re-implemented. If the reference count is  **0**, the memory of the  **[IUnknown](IUnknown.md)**  interface object and implementation object is released. 

**Parameters:**

<a name="table1747742582165625"></a>
<table><thead align="left"><tr id="row1621456437165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1368255204165625"><a name="p1368255204165625"></a><a name="p1368255204165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1038855478165625"><a name="p1038855478165625"></a><a name="p1038855478165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row922011225165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">iUnknown</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the <strong id="b842856775165625"><a name="b842856775165625"></a><a name="b842856775165625"></a><a href="IUnknown.md">IUnknown</a><strong id="b749221177165625"><a name="b749221177165625"></a><a name="b749221177165625"></a> interface object. </strong></strong></td>
</tr>
</tbody>
</table>

**Returns:**

**** Indicates the number of  **[IUnknown](IUnknown.md)** interface objects that are referenced after the current reference is released.********

## SAMGR\_Bootstrap\(\)<a name="ga756ac1f5376c72aa5d14b855a302d7b6"></a>

```
void SAMGR_Bootstrap (void )
```

 **Description:**

Starts system services and features. 

This function is called in the  **main**  function to start all services when an independent process is developed. This function is called after the dynamic library \(containing system services and features\) is loaded during system running. 

**Attention:**

This function cannot be called frequently. Otherwise, problems such as repeated service startup may occur. It is recommended that this function be called once in the  **main**  function or after the dynamic library is loaded. 

## SAMGR\_GetInstance\(\)<a name="ga21f168d6f97d6991115ae1cf8bbd8deb"></a>

```
[SamgrLite](SamgrLite.md)* SAMGR_GetInstance (void )
```

 **Description:**

Obtains the singleton Samgr instance. 

You need to call this function before using the Samgr capabilities. 

**Returns:**

Returns the pointer to the singleton instance  [SamgrLite](SamgrLite.md). 

## SAMGR\_SendRequest\(\)<a name="ga03b440d8dff9fcc8694ca8a3baa83462"></a>

```
int32 SAMGR_SendRequest (const [Identity](Identity.md) * identity, const [Request](Request.md) * request, [Handler](Samgr.md#ga5e13d943cc6a87a5c99fe604f3bc01e4) handler )
```

 **Description:**

Sends a request to a service or feature of a specified identity. 

This function is called by a service to send messages to its own features through the asynchronous function of  [IUnknown](IUnknown.md). 

**Parameters:**

<a name="table265512316165625"></a>
<table><thead align="left"><tr id="row739751498165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p854854577165625"><a name="p854854577165625"></a><a name="p854854577165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p613437141165625"><a name="p613437141165625"></a><a name="p613437141165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row99201468165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">identity</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the ID of the feature or service that processes the message. </td>
</tr>
<tr id="row231437739165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">request</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the request. </td>
</tr>
<tr id="row1579338323165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handler</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the function handling the response. If the value is <strong id="b246810940165625"><a name="b246810940165625"></a><a name="b246810940165625"></a>NULL</strong>, no response is required. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **EC\_SUCCESS**  if the request is sent successfully; returns other error codes if the request fails to be sent. The caller needs to release the memory applied in the request. 

## SAMGR\_SendResponse\(\)<a name="gadba5f2881a6e1403cb642726d5fec3e2"></a>

```
int32 SAMGR_SendResponse (const [Request](Request.md) * request, const [Response](Response.md) * response )
```

 **Description:**

Sends a response after processing a request. 

This function is called to send a response after processing a request by  **MessageHandle**  of a service or  **OnMessage**  of a feature. 

**Parameters:**

<a name="table1423019299165625"></a>
<table><thead align="left"><tr id="row1996111964165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1600582494165625"><a name="p1600582494165625"></a><a name="p1600582494165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p900469974165625"><a name="p900469974165625"></a><a name="p900469974165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row463144193165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">request</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the original request. </td>
</tr>
<tr id="row612754969165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">response</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the response content. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **EC\_SUCCESS**  if the response is sent successfully; returns other error codes if the response fails to be sent. 

**Attention:**

-    This function can be called only in  **MessageHandle**  or  **OnMessage**. 
-    The request must be the original one passed from  **MessageHandle**  or  **OnMessage**. Otherwise, a memory exception occurs. 
-    When the caller sends a request, the  **handler**  callback function must be carried. 
-    The response is sent to the message queue of the service to which the requester belongs for processing. Therefore, the requester should wait for the response in non-blocking mode. 

## SAMGR\_SendResponseByIdentity\(\)<a name="ga44ab9b4c98e2dd6ba3338d1d2664a6fe"></a>

```
int32 SAMGR_SendResponseByIdentity (const [Identity](Identity.md) * id, const [Request](Request.md) * request, const [Response](Response.md) * response )
```

 **Description:**

Sends a response to a specified service or feature after processing the original request. \(Customized function for  **bootstrap**\) 

This function is called to send a response after processing a request by  **MessageHandle**  of a service or  **OnMessage**  of a feature. This function can be customized to implement phased startup of different types of services. 

**Parameters:**

<a name="table521358788165625"></a>
<table><thead align="left"><tr id="row1923935527165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p312130790165625"><a name="p312130790165625"></a><a name="p312130790165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1438896196165625"><a name="p1438896196165625"></a><a name="p1438896196165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row121129158165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">id</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the ID of a service or feature. The response is sent to the thread of the service or feature for processing. </td>
</tr>
<tr id="row2125851712165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">request</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the original request. </td>
</tr>
<tr id="row263479275165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">response</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the response content. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **EC\_SUCCESS**  if the response is sent successfully; returns other error codes if the response fails to be sent. 

**Attention:**

-    This function can be called only in  **MessageHandle**  or  **OnMessage**. 
-    The request must be the original one passed from  **MessageHandle**  or  **OnMessage**. Otherwise, a memory exception occurs. 
-    When the caller sends a request, the  **handler**  callback function must be carried. 
-    The response is sent to the message queue of a specified ID for processing. Therefore, wait for the response in non-blocking mode. 

## SAMGR\_SendSharedDirectRequest\(\)<a name="ga0c8c20d2265f4eb8ec8b516300a94a63"></a>

```
int32 SAMGR_SendSharedDirectRequest (const [Identity](Identity.md) * id, const [Request](Request.md) * req, const [Response](Response.md) * resp, uint32 ** ref, [Handler](Samgr.md#ga5e13d943cc6a87a5c99fe604f3bc01e4) handler )
```

 **Description:**

Sends a request and response of a caller to the feature thread. The handler is directly called to process the request and response without using the message processing functions. \(Customized function for the broadcast service\) 

This function is used to publish topics for the  [Broadcast](Broadcast.md)  service to broadcast messages. The value of reference counting is incremented by one each time this function is called. 

**Parameters:**

<a name="table444448947165625"></a>
<table><thead align="left"><tr id="row376983761165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p167720086165625"><a name="p167720086165625"></a><a name="p167720086165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p371781744165625"><a name="p371781744165625"></a><a name="p371781744165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1674048391165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">id</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the IDs of services or features, to which the request and response are sent. </td>
</tr>
<tr id="row1691015850165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">request</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the request. </td>
</tr>
<tr id="row1605687777165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">resp</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the response. </td>
</tr>
<tr id="row96546559165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">ref</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the reference counting. </td>
</tr>
<tr id="row1170886717165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handler</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the function for handling the request and response. This parameter cannot be <strong id="b352151323165625"><a name="b352151323165625"></a><a name="b352151323165625"></a>NULL</strong>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **EC\_SUCCESS**  if the request and response are sent successfully; returns other error codes if the request and response fail to be sent. 

**Attention:**

-    Ensure that the thread specified by  **identity**  processes the message after all messages are sent. Common practice: Add a lock before sending a request and add the same lock during processing. 
-    If  **NULL**  is returned, the caller needs to release the memory of the request and response. 
-    If the response changes each time when a request is sent, ensure that the response will not be released. \(Set  **len**  to  **0**, the  **data**  of response will be the resident memory.\) 

## SAMGR\_SendSharedRequest\(\)<a name="gae7c4d087b251949d10d81e88a47e8dbd"></a>

```
uint32* SAMGR_SendSharedRequest (const [Identity](Identity.md) * identity, const [Request](Request.md) * request, uint32 * token, [Handler](Samgr.md#ga5e13d943cc6a87a5c99fe604f3bc01e4) handler )
```

 **Description:**

Sends a request to multiple services or features to save memory. 

This function is used to publish topics for the  [Broadcast](Broadcast.md)  service to broadcast messages. 

**Parameters:**

<a name="table695387513165625"></a>
<table><thead align="left"><tr id="row6030381165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1469509479165625"><a name="p1469509479165625"></a><a name="p1469509479165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1161962705165625"><a name="p1161962705165625"></a><a name="p1161962705165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row759960256165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">identity</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the IDs of services or features, to which requests are sent. </td>
</tr>
<tr id="row760354526165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">request</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the request. </td>
</tr>
<tr id="row1304626026165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">token</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to reference counting. </td>
</tr>
<tr id="row692856200165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handler</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the function handling the response. If the value is <strong id="b1182431729165625"><a name="b1182431729165625"></a><a name="b1182431729165625"></a>NULL</strong>, no response is required. </td>
</tr>
</tbody>
</table>

**Attention:**

-    Ensure that the thread specified by  **identity**  processes the message after all messages are sent. Common practice: Add a lock before sending a request and add the same lock during processing. 
-    If  **NULL**  is returned, the caller needs to release the memory of the request. 

## VECTOR\_Add\(\)<a name="ga234ba2452c973e9fa4a8be47eaea9d06"></a>

```
int16 VECTOR_Add ([Vector](Samgr.md#ga255ca81c214b8a94a90f786ceef94514) * vector, void * element )
```

 **Description:**

Adds an element to the vector. 

This function is used to add an element to the vector. 

**Parameters:**

<a name="table778134160165625"></a>
<table><thead align="left"><tr id="row964534204165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1456334874165625"><a name="p1456334874165625"></a><a name="p1456334874165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p394836022165625"><a name="p394836022165625"></a><a name="p394836022165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1420584407165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">vector</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the <strong id="b1661701024165625"><a name="b1661701024165625"></a><a name="b1661701024165625"></a>this</strong> pointer to the vector. </td>
</tr>
<tr id="row1615267899165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">element</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the element to add. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the location of the element to be added if the operation is successful; returns  **INVALID\_INDEX**  if the operation fails. 

## VECTOR\_At\(\)<a name="ga75210ba0bd37a38a1902c4904e61246a"></a>

```
void* VECTOR_At ([Vector](Samgr.md#ga255ca81c214b8a94a90f786ceef94514) * vector, int16 index )
```

 **Description:**

Obtains the element at a specified position. 

This function is used to obtain the element at a specified position.

**Parameters:**

<a name="table720001461165625"></a>
<table><thead align="left"><tr id="row1386829873165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1844808267165625"><a name="p1844808267165625"></a><a name="p1844808267165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1359933160165625"><a name="p1359933160165625"></a><a name="p1359933160165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row228331094165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">vector</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the <strong id="b374022322165625"><a name="b374022322165625"></a><a name="b374022322165625"></a>this</strong> pointer to the vector. </td>
</tr>
<tr id="row924935215165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">index</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the subscript to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the element if obtained; returns  **NULL**  otherwise. 

## VECTOR\_Clear\(\)<a name="gaebfe9ac38f2667d61bf39420aa8e7035"></a>

```
void VECTOR_Clear ([Vector](Samgr.md#ga255ca81c214b8a94a90f786ceef94514) * vector)
```

 **Description:**

Destruct a vector object. 

This function is used to clear the memory applied by the vector after the temporary vector in the stack is used. 

**Parameters:**

<a name="table87735478165625"></a>
<table><thead align="left"><tr id="row1016156808165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1968862629165625"><a name="p1968862629165625"></a><a name="p1968862629165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p220306466165625"><a name="p220306466165625"></a><a name="p220306466165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row91042477165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">vector</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the vector to clear. </td>
</tr>
</tbody>
</table>

## VECTOR\_Find\(\)<a name="gaabc5b0eda1ee6889411e6dacb233cb07"></a>

```
int16 VECTOR_Find ([Vector](Samgr.md#ga255ca81c214b8a94a90f786ceef94514) * vector, const void * element )
```

 **Description:**

Checks the position of an element. 

This function is used to check whether a vector has a specified element. 

**Parameters:**

<a name="table939060258165625"></a>
<table><thead align="left"><tr id="row239732536165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2104484465165625"><a name="p2104484465165625"></a><a name="p2104484465165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2019274490165625"><a name="p2019274490165625"></a><a name="p2019274490165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1230882689165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">vector</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the <strong id="b1799750241165625"><a name="b1799750241165625"></a><a name="b1799750241165625"></a>this</strong> pointer to the vector. </td>
</tr>
<tr id="row233593872165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">element</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the element to be checked. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the index of the element that is not less than 0 if the check is successful; returns  **INVALID\_INDEX**  if the check fails. 

## VECTOR\_FindByKey\(\)<a name="gac65bc6dc959a90d95dff93368abd97c7"></a>

```
int16 VECTOR_FindByKey ([Vector](Samgr.md#ga255ca81c214b8a94a90f786ceef94514) * vector, const void * key )
```

 **Description:**

Checks the position of the element with a specified key. 

This function is used to check an element based on its key value. 

**Parameters:**

<a name="table1111557147165625"></a>
<table><thead align="left"><tr id="row2507845165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2126006915165625"><a name="p2126006915165625"></a><a name="p2126006915165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p786599116165625"><a name="p786599116165625"></a><a name="p786599116165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row327406149165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">vector</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the <strong id="b1753386761165625"><a name="b1753386761165625"></a><a name="b1753386761165625"></a>this</strong> pointer to the vector. </td>
</tr>
<tr id="row1014164536165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">key</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the key value of the element to check. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the index of the key element that is not less than 0 if the check is successful; returns  **INVALID\_INDEX**  if the check fails. 

## VECTOR\_Make\(\)<a name="gae790345f8a2863c143bfee4bab3fb6d7"></a>

```
[Vector](Samgr.md#ga255ca81c214b8a94a90f786ceef94514) VECTOR_Make (VECTOR_Key key, VECTOR_Compare compare )
```

 **Description:**

Creates or initializes a vector object. 

This function is used to create or initialize a vector object. 

**Parameters:**

<a name="table571679435165625"></a>
<table><thead align="left"><tr id="row1237542915165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p354782421165625"><a name="p354782421165625"></a><a name="p354782421165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1876291479165625"><a name="p1876291479165625"></a><a name="p1876291479165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row189881648165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">key</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the function provided by users for converting data elements into key values. If this function is not provided, set it to <strong id="b1258829420165625"><a name="b1258829420165625"></a><a name="b1258829420165625"></a>NULL</strong>. </td>
</tr>
<tr id="row1854338954165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">compare</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the function for comparing the sizes of two elements. If this function is not provided, set it to <strong id="b365994004165625"><a name="b365994004165625"></a><a name="b365994004165625"></a>NULL</strong>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the vector right value object. 

## VECTOR\_Num\(\)<a name="ga90523bfd48091a0135f74670076af4d5"></a>

```
int16 VECTOR_Num ([Vector](Samgr.md#ga255ca81c214b8a94a90f786ceef94514) * vector)
```

 **Description:**

Obtains the number of valid elements in the vector, excluding elements that have been set to  **NULL**. 

This function is used to check whether the number of elements reaches the upper limit. 

**Parameters:**

<a name="table1025778279165625"></a>
<table><thead align="left"><tr id="row970320691165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1730866521165625"><a name="p1730866521165625"></a><a name="p1730866521165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p859906124165625"><a name="p859906124165625"></a><a name="p859906124165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1113114000165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">vector</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the <strong id="b1667574050165625"><a name="b1667574050165625"></a><a name="b1667574050165625"></a>this</strong> pointer to the vector. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the top - free value of the vector, which indicates the number of non-null elements. 

## VECTOR\_Size\(\)<a name="ga1432f30c136d14bc00414d883d8be3bd"></a>

```
int16 VECTOR_Size ([Vector](Samgr.md#ga255ca81c214b8a94a90f786ceef94514) * vector)
```

 **Description:**

Obtains the number of elements in the vector, including elements that have been set to  **NULL**. 

This function is used for full traversal. 

**Parameters:**

<a name="table1087145287165625"></a>
<table><thead align="left"><tr id="row1223651406165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p477066018165625"><a name="p477066018165625"></a><a name="p477066018165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1357073209165625"><a name="p1357073209165625"></a><a name="p1357073209165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2004135203165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">vector</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the <strong id="b407686178165625"><a name="b407686178165625"></a><a name="b407686178165625"></a>this</strong> pointer to the vector. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the top value of the vector, which indicates the number of elements. 

## VECTOR\_Swap\(\)<a name="ga7f435d33ba61d145de9d5892b68a0eda"></a>

```
void* VECTOR_Swap ([Vector](Samgr.md#ga255ca81c214b8a94a90f786ceef94514) * vector, int16 index, void * element )
```

 **Description:**

Swaps the element at a specified position in a vector with another element. 

This function is used to clear, sort, or update elements in the vector. 

**Parameters:**

<a name="table1863657902165625"></a>
<table><thead align="left"><tr id="row356333772165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2061654435165625"><a name="p2061654435165625"></a><a name="p2061654435165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p208198649165625"><a name="p208198649165625"></a><a name="p208198649165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row622744928165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">vector</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the <strong id="b929158642165625"><a name="b929158642165625"></a><a name="b929158642165625"></a>this</strong> pointer to the vector. </td>
</tr>
<tr id="row241229202165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">index</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the position of the element to be swapped. </td>
</tr>
<tr id="row2129813487165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">element</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the new element. </td>
</tr>
</tbody>
</table>

**Attention:**

Before using this function, ensure that the index is valid. You can use  **VECTOR\_Size**  to obtain the upper limit of the index. 

**Returns:**

Returns the original element if the swapping is successful; returns  **NULL**  if the swapping fails. 

**See also:**

[VECTOR\_Size](Samgr.md#ga1432f30c136d14bc00414d883d8be3bd) 

