# bundle\_manager.h<a name="EN-US_TOPIC_0000001055358070"></a>

-   [Overview](#section846914803165626)
-   [Summary](#section1561006862165626)
-   [Typedefs](#typedef-members)
-   [Functions](#func-members)

## **Overview**<a name="section846914803165626"></a>

**Related Modules:**

[BundleManager](bundlemanager.md)

**Description:**

Declares functions used for managing application bundles and obtaining bundle information. 

You can use functions provided in this file to install, update, or uninstall an application, obtain  [AbilityInfo](abilityinfo.md)  and  [BundleInfo](bundleinfo.md)  about an application, obtain the bundle name of an application based on the application's user ID \(UID\), and obtain  [BundleInfo](bundleinfo.md)  objects of all applications or keep-alive applications in the system.

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1561006862165626"></a>

## Typedefs<a name="typedef-members"></a>

<a name="table634482138165626"></a>
<table><thead align="left"><tr id="row931883904165626"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p77754049165626"><a name="p77754049165626"></a><a name="p77754049165626"></a>Typedef Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p206822578165626"><a name="p206822578165626"></a><a name="p206822578165626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row721045269165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p539645095165626"><a name="p539645095165626"></a><a name="p539645095165626"></a><a href="bundlemanager.md#ga00f021e76d728d2d44e1a28887ccc3af">InstallerCallback</a>) (const uint8_t resultCode, const void *resultMessage)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1461698239165626"><a name="p1461698239165626"></a><a name="p1461698239165626"></a>typedef void(* </p>
<p id="p773570606165626"><a name="p773570606165626"></a><a name="p773570606165626"></a>Called when an application is installed, updated, or uninstalled. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1180439078165626"></a>
<table><thead align="left"><tr id="row661526162165626"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p702701448165626"><a name="p702701448165626"></a><a name="p702701448165626"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p900535685165626"><a name="p900535685165626"></a><a name="p900535685165626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row867141605165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p539002747165626"><a name="p539002747165626"></a><a name="p539002747165626"></a><a href="bundlemanager.md#ga5c49620ca8b752cd6f43fabc5d5c7416">RegisterCallback</a> (<a href="bundlestatuscallback.md">BundleStatusCallback</a> *<a href="bundlestatuscallback.md">BundleStatusCallback</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p708735747165626"><a name="p708735747165626"></a><a name="p708735747165626"></a>int32_t </p>
<p id="p1582538794165626"><a name="p1582538794165626"></a><a name="p1582538794165626"></a>Registers a callback to monitor the installation, update, and uninstallation state changes of an application. </p>
</td>
</tr>
<tr id="row366039124165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1124650929165626"><a name="p1124650929165626"></a><a name="p1124650929165626"></a><a href="bundlemanager.md#ga095eee592eff6ce71a2a67a1a0e3e344">UnregisterCallback</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p229067640165626"><a name="p229067640165626"></a><a name="p229067640165626"></a>int32_t </p>
<p id="p134605969165626"><a name="p134605969165626"></a><a name="p134605969165626"></a>Unregisters a callback previously registered for monitoring the installation, update, and uninstallation stat changes of an application. </p>
</td>
</tr>
<tr id="row1667867548165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1651916774165626"><a name="p1651916774165626"></a><a name="p1651916774165626"></a><a href="bundlemanager.md#gaf1f1521a64cc98f076b0082df6c0abdd">Install</a> (const char *hapPath, const <a href="installparam.md">InstallParam</a> *installParam, <a href="bundlemanager.md#ga00f021e76d728d2d44e1a28887ccc3af">InstallerCallback</a> installerCallback)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1768789153165626"><a name="p1768789153165626"></a><a name="p1768789153165626"></a>bool </p>
<p id="p1114402030165626"><a name="p1114402030165626"></a><a name="p1114402030165626"></a>Installs or updates an application. </p>
</td>
</tr>
<tr id="row1422554957165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1316592192165626"><a name="p1316592192165626"></a><a name="p1316592192165626"></a><a href="bundlemanager.md#gaa117e44378315a61b4e71fd252b2e496">Uninstall</a> (const char *bundleName, const <a href="installparam.md">InstallParam</a> *installParam, <a href="bundlemanager.md#ga00f021e76d728d2d44e1a28887ccc3af">InstallerCallback</a> installerCallback)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1988024541165626"><a name="p1988024541165626"></a><a name="p1988024541165626"></a>bool </p>
<p id="p1473535974165626"><a name="p1473535974165626"></a><a name="p1473535974165626"></a>Uninstalls an application. </p>
</td>
</tr>
<tr id="row1212345590165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p841640835165626"><a name="p841640835165626"></a><a name="p841640835165626"></a><a href="bundlemanager.md#ga4360375d15224d89632f59ee110b74c9">QueryAbilityInfo</a> (const <a href="want.md">Want</a> *want, <a href="abilityinfo.md">AbilityInfo</a> *abilityInfo)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1552839748165626"><a name="p1552839748165626"></a><a name="p1552839748165626"></a>uint8_t </p>
<p id="p39777193165626"><a name="p39777193165626"></a><a name="p39777193165626"></a>Queries the <a href="abilityinfo.md">AbilityInfo</a> of an ability based on the information carried in the <a href="want.md">Want</a> structure. </p>
</td>
</tr>
<tr id="row1582983129165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p246189998165626"><a name="p246189998165626"></a><a name="p246189998165626"></a><a href="bundlemanager.md#ga5e81134e037911654e34cc8a7ba01a2f">GetBundleInfo</a> (const char *bundleName, int32_t flags, <a href="bundleinfo.md">BundleInfo</a> *bundleInfo)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p447491028165626"><a name="p447491028165626"></a><a name="p447491028165626"></a>uint8_t </p>
<p id="p1609299059165626"><a name="p1609299059165626"></a><a name="p1609299059165626"></a>Obtains the <a href="bundleinfo.md">BundleInfo</a> of an application based on the specified bundle name. </p>
</td>
</tr>
<tr id="row2116074657165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1420542007165626"><a name="p1420542007165626"></a><a name="p1420542007165626"></a><a href="bundlemanager.md#ga2469dafbc61ba8e98b69041c13044cad">GetBundleInfos</a> (const int flags, <a href="bundleinfo.md">BundleInfo</a> **bundleInfos, int32_t *len)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1462506431165626"><a name="p1462506431165626"></a><a name="p1462506431165626"></a>uint8_t </p>
<p id="p1239658312165626"><a name="p1239658312165626"></a><a name="p1239658312165626"></a>Obtains the <a href="bundleinfo.md">BundleInfo</a> of all bundles in the system. </p>
</td>
</tr>
<tr id="row1491606930165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p209794018165626"><a name="p209794018165626"></a><a name="p209794018165626"></a><a href="bundlemanager.md#ga0c1cb00194993ecba7337fdf0a203314">QueryKeepAliveBundleInfos</a> (<a href="bundleinfo.md">BundleInfo</a> **bundleInfos, int32_t *len)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2089967698165626"><a name="p2089967698165626"></a><a name="p2089967698165626"></a>uint8_t </p>
<p id="p2044540732165626"><a name="p2044540732165626"></a><a name="p2044540732165626"></a>Obtains the <a href="bundleinfo.md">BundleInfo</a> of all keep-alive applications in the system. </p>
</td>
</tr>
<tr id="row1475638400165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p328534235165626"><a name="p328534235165626"></a><a name="p328534235165626"></a><a href="bundlemanager.md#ga711965038390aef4fa0a6b6a98f6998b">GetBundleInfosByMetaData</a> (const char *metaDataKey, <a href="bundleinfo.md">BundleInfo</a> **bundleInfos, int32_t *len)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p622361715165626"><a name="p622361715165626"></a><a name="p622361715165626"></a>uint8_t </p>
<p id="p1519823460165626"><a name="p1519823460165626"></a><a name="p1519823460165626"></a>Obtains the <a href="bundleinfo.md">BundleInfo</a> of application bundles based on the specified <a href="metadata.md">MetaData</a>. </p>
</td>
</tr>
<tr id="row185421783165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1963881236165626"><a name="p1963881236165626"></a><a name="p1963881236165626"></a><a href="bundlemanager.md#ga4afdc08ba78506fce95a066e137ac46d">GetBundleNameForUid</a> (int32_t uid, char **bundleName)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1229744337165626"><a name="p1229744337165626"></a><a name="p1229744337165626"></a>uint8_t </p>
<p id="p2040514255165626"><a name="p2040514255165626"></a><a name="p2040514255165626"></a>Obtains the bundle name of an application based on the specified UID. </p>
</td>
</tr>
</tbody>
</table>

