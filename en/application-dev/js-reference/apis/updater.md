# Updater<a name="EN-US_TOPIC_0000001115974768"></a>

## Modules to Import<a name="en-us_topic_0000001149710363_section749mcpsimp"></a>

```
import client from 'libupdateclient.z.so'
```

## Required Permissions<a name="en-us_topic_0000001149710363_section752mcpsimp"></a>

None

## updater.getNewVersionInfo\(\)<a name="en-us_topic_0000001149710363_section755mcpsimp"></a>

Obtains new version information.

**Parameters**

<a name="en-us_topic_0000001149710363_table760mcpsimp"></a>
<table><thead align="left"><tr id="en-us_topic_0000001149710363_row767mcpsimp"><th class="cellrowborder" valign="top" width="11%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001149710363_p769mcpsimp"><a name="en-us_topic_0000001149710363_p769mcpsimp"></a><a name="en-us_topic_0000001149710363_p769mcpsimp"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="14.000000000000002%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001149710363_p771mcpsimp"><a name="en-us_topic_0000001149710363_p771mcpsimp"></a><a name="en-us_topic_0000001149710363_p771mcpsimp"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="24.060000000000002%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001149710363_p773mcpsimp"><a name="en-us_topic_0000001149710363_p773mcpsimp"></a><a name="en-us_topic_0000001149710363_p773mcpsimp"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="50.94%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001149710363_p775mcpsimp"><a name="en-us_topic_0000001149710363_p775mcpsimp"></a><a name="en-us_topic_0000001149710363_p775mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001149710363_row777mcpsimp"><td class="cellrowborder" valign="top" width="11%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001149710363_p779mcpsimp"><a name="en-us_topic_0000001149710363_p779mcpsimp"></a><a name="en-us_topic_0000001149710363_p779mcpsimp"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="14.000000000000002%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001149710363_p781mcpsimp"><a name="en-us_topic_0000001149710363_p781mcpsimp"></a><a name="en-us_topic_0000001149710363_p781mcpsimp"></a>Function</p>
</td>
<td class="cellrowborder" valign="top" width="24.060000000000002%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001149710363_p783mcpsimp"><a name="en-us_topic_0000001149710363_p783mcpsimp"></a><a name="en-us_topic_0000001149710363_p783mcpsimp"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="50.94%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001149710363_p785mcpsimp"><a name="en-us_topic_0000001149710363_p785mcpsimp"></a><a name="en-us_topic_0000001149710363_p785mcpsimp"></a>AsyncCallback&lt;NewVersionInfo&gt;</p>
</td>
</tr>
</tbody>
</table>

**Return Values**

<a name="en-us_topic_0000001149710363_table788mcpsimp"></a>
<table><thead align="left"><tr id="en-us_topic_0000001149710363_row794mcpsimp"><th class="cellrowborder" valign="top" width="19%" id="mcps1.1.4.1.1"><p id="en-us_topic_0000001149710363_p796mcpsimp"><a name="en-us_topic_0000001149710363_p796mcpsimp"></a><a name="en-us_topic_0000001149710363_p796mcpsimp"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="29.49%" id="mcps1.1.4.1.2"><p id="en-us_topic_0000001149710363_p798mcpsimp"><a name="en-us_topic_0000001149710363_p798mcpsimp"></a><a name="en-us_topic_0000001149710363_p798mcpsimp"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="51.51%" id="mcps1.1.4.1.3"><p id="en-us_topic_0000001149710363_p800mcpsimp"><a name="en-us_topic_0000001149710363_p800mcpsimp"></a><a name="en-us_topic_0000001149710363_p800mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001149710363_row802mcpsimp"><td class="cellrowborder" valign="top" width="19%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001149710363_p804mcpsimp"><a name="en-us_topic_0000001149710363_p804mcpsimp"></a><a name="en-us_topic_0000001149710363_p804mcpsimp"></a>info</p>
</td>
<td class="cellrowborder" valign="top" width="29.49%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001149710363_p806mcpsimp"><a name="en-us_topic_0000001149710363_p806mcpsimp"></a><a name="en-us_topic_0000001149710363_p806mcpsimp"></a>NewVersionInfo</p>
</td>
<td class="cellrowborder" valign="top" width="51.51%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001149710363_p808mcpsimp"><a name="en-us_topic_0000001149710363_p808mcpsimp"></a><a name="en-us_topic_0000001149710363_p808mcpsimp"></a>New version information</p>
</td>
</tr>
</tbody>
</table>

**Example**

```
updater.getNewVersionInfo(info => {
console.log("getNewVersionInfo success  " + info.status);
console.log(`info versionName = ` + info.result[0].versionName);
console.log(`info versionCode = ` + info.result[0].versionCode);
console.log(`info verifyInfo = ` + info.result[0].verifyInfo);
)};
```

## updater.checkNewVersion\(\)<a name="en-us_topic_0000001149710363_section817mcpsimp"></a>

Checks for a new version.

**Parameters**

<a name="en-us_topic_0000001149710363_table822mcpsimp"></a>
<table><thead align="left"><tr id="en-us_topic_0000001149710363_row829mcpsimp"><th class="cellrowborder" valign="top" width="11%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001149710363_p831mcpsimp"><a name="en-us_topic_0000001149710363_p831mcpsimp"></a><a name="en-us_topic_0000001149710363_p831mcpsimp"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001149710363_p833mcpsimp"><a name="en-us_topic_0000001149710363_p833mcpsimp"></a><a name="en-us_topic_0000001149710363_p833mcpsimp"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="24.529999999999998%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001149710363_p835mcpsimp"><a name="en-us_topic_0000001149710363_p835mcpsimp"></a><a name="en-us_topic_0000001149710363_p835mcpsimp"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="39.47%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001149710363_p837mcpsimp"><a name="en-us_topic_0000001149710363_p837mcpsimp"></a><a name="en-us_topic_0000001149710363_p837mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001149710363_row839mcpsimp"><td class="cellrowborder" valign="top" width="11%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001149710363_p841mcpsimp"><a name="en-us_topic_0000001149710363_p841mcpsimp"></a><a name="en-us_topic_0000001149710363_p841mcpsimp"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001149710363_p843mcpsimp"><a name="en-us_topic_0000001149710363_p843mcpsimp"></a><a name="en-us_topic_0000001149710363_p843mcpsimp"></a>Function</p>
</td>
<td class="cellrowborder" valign="top" width="24.529999999999998%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001149710363_p845mcpsimp"><a name="en-us_topic_0000001149710363_p845mcpsimp"></a><a name="en-us_topic_0000001149710363_p845mcpsimp"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="39.47%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001149710363_p847mcpsimp"><a name="en-us_topic_0000001149710363_p847mcpsimp"></a><a name="en-us_topic_0000001149710363_p847mcpsimp"></a>AsyncCallback&lt;NewVersionInfo&gt;</p>
</td>
</tr>
</tbody>
</table>

**Return Values**

<a name="en-us_topic_0000001149710363_table850mcpsimp"></a>
<table><thead align="left"><tr id="en-us_topic_0000001149710363_row856mcpsimp"><th class="cellrowborder" valign="top" width="19%" id="mcps1.1.4.1.1"><p id="en-us_topic_0000001149710363_p858mcpsimp"><a name="en-us_topic_0000001149710363_p858mcpsimp"></a><a name="en-us_topic_0000001149710363_p858mcpsimp"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="20.330000000000002%" id="mcps1.1.4.1.2"><p id="en-us_topic_0000001149710363_p860mcpsimp"><a name="en-us_topic_0000001149710363_p860mcpsimp"></a><a name="en-us_topic_0000001149710363_p860mcpsimp"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="60.67%" id="mcps1.1.4.1.3"><p id="en-us_topic_0000001149710363_p862mcpsimp"><a name="en-us_topic_0000001149710363_p862mcpsimp"></a><a name="en-us_topic_0000001149710363_p862mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001149710363_row864mcpsimp"><td class="cellrowborder" valign="top" width="19%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001149710363_p866mcpsimp"><a name="en-us_topic_0000001149710363_p866mcpsimp"></a><a name="en-us_topic_0000001149710363_p866mcpsimp"></a>info</p>
</td>
<td class="cellrowborder" valign="top" width="20.330000000000002%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001149710363_p868mcpsimp"><a name="en-us_topic_0000001149710363_p868mcpsimp"></a><a name="en-us_topic_0000001149710363_p868mcpsimp"></a>NewVersionInfo</p>
</td>
<td class="cellrowborder" valign="top" width="60.67%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001149710363_p870mcpsimp"><a name="en-us_topic_0000001149710363_p870mcpsimp"></a><a name="en-us_topic_0000001149710363_p870mcpsimp"></a>New version information</p>
</td>
</tr>
</tbody>
</table>

**Example**

```
updater.checkNewVersion(info => {
console.log("checkNewVersion success  " + info.status);
console.log(`info versionName = ` + info.result[0].versionName);
console.log(`info versionCode = ` + info.result[0].versionCode);
console.log(`info verifyInfo = ` + info.result[0].verifyInfo);
)};
```

## updater.download\(\)<a name="en-us_topic_0000001149710363_section879mcpsimp"></a>

Downloads the new version and displays the download process.

**Parameters**

None

**Return Values**

None

**Example**

```
updater.on("downloadProgress", progress => {
console.log("downloadProgress on" + progress);
console.log(`downloadProgress status: ` + progress.status);
console.log(`downloadProgress percent: ` + progress.percent);
)};
updater.download();
```

## updater.upgrade\(\)<a name="en-us_topic_0000001149710363_section894mcpsimp"></a>

Starts an update.

**Parameters**

None

**Return Values**

None

**Example**

```
updater.on("upgradeProgress", progress => {
console.log("downloadProgress on" + progress);
console.log(`downloadProgress status: ` + progress.status);
console.log(`downloadProgress percent: ` + progress.percent);
)};
updater.upgrade();
```

## updater.setUpdatePolicy\(\)<a name="en-us_topic_0000001149710363_section909mcpsimp"></a>

Sets the update policy.

**Parameters**

<a name="en-us_topic_0000001149710363_table914mcpsimp"></a>
<table><thead align="left"><tr id="en-us_topic_0000001149710363_row921mcpsimp"><th class="cellrowborder" valign="top" width="11%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001149710363_p923mcpsimp"><a name="en-us_topic_0000001149710363_p923mcpsimp"></a><a name="en-us_topic_0000001149710363_p923mcpsimp"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="27.93%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001149710363_p925mcpsimp"><a name="en-us_topic_0000001149710363_p925mcpsimp"></a><a name="en-us_topic_0000001149710363_p925mcpsimp"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="24.529999999999998%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001149710363_p927mcpsimp"><a name="en-us_topic_0000001149710363_p927mcpsimp"></a><a name="en-us_topic_0000001149710363_p927mcpsimp"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="36.54%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001149710363_p929mcpsimp"><a name="en-us_topic_0000001149710363_p929mcpsimp"></a><a name="en-us_topic_0000001149710363_p929mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001149710363_row931mcpsimp"><td class="cellrowborder" valign="top" width="11%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001149710363_p933mcpsimp"><a name="en-us_topic_0000001149710363_p933mcpsimp"></a><a name="en-us_topic_0000001149710363_p933mcpsimp"></a>policy</p>
</td>
<td class="cellrowborder" valign="top" width="27.93%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001149710363_p935mcpsimp"><a name="en-us_topic_0000001149710363_p935mcpsimp"></a><a name="en-us_topic_0000001149710363_p935mcpsimp"></a>UpdatePolicy</p>
</td>
<td class="cellrowborder" valign="top" width="24.529999999999998%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001149710363_p937mcpsimp"><a name="en-us_topic_0000001149710363_p937mcpsimp"></a><a name="en-us_topic_0000001149710363_p937mcpsimp"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="36.54%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001149710363_p939mcpsimp"><a name="en-us_topic_0000001149710363_p939mcpsimp"></a><a name="en-us_topic_0000001149710363_p939mcpsimp"></a>Update policy</p>
</td>
</tr>
<tr id="en-us_topic_0000001149710363_row940mcpsimp"><td class="cellrowborder" valign="top" width="11%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001149710363_p942mcpsimp"><a name="en-us_topic_0000001149710363_p942mcpsimp"></a><a name="en-us_topic_0000001149710363_p942mcpsimp"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="27.93%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001149710363_p944mcpsimp"><a name="en-us_topic_0000001149710363_p944mcpsimp"></a><a name="en-us_topic_0000001149710363_p944mcpsimp"></a>Function</p>
</td>
<td class="cellrowborder" valign="top" width="24.529999999999998%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001149710363_p946mcpsimp"><a name="en-us_topic_0000001149710363_p946mcpsimp"></a><a name="en-us_topic_0000001149710363_p946mcpsimp"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="36.54%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001149710363_p948mcpsimp"><a name="en-us_topic_0000001149710363_p948mcpsimp"></a><a name="en-us_topic_0000001149710363_p948mcpsimp"></a>AsyncCallback&lt;number&gt;</p>
</td>
</tr>
</tbody>
</table>

**Return Values**

<a name="en-us_topic_0000001149710363_table951mcpsimp"></a>
<table><thead align="left"><tr id="en-us_topic_0000001149710363_row957mcpsimp"><th class="cellrowborder" valign="top" width="19%" id="mcps1.1.4.1.1"><p id="en-us_topic_0000001149710363_p959mcpsimp"><a name="en-us_topic_0000001149710363_p959mcpsimp"></a><a name="en-us_topic_0000001149710363_p959mcpsimp"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="23.62%" id="mcps1.1.4.1.2"><p id="en-us_topic_0000001149710363_p961mcpsimp"><a name="en-us_topic_0000001149710363_p961mcpsimp"></a><a name="en-us_topic_0000001149710363_p961mcpsimp"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="57.379999999999995%" id="mcps1.1.4.1.3"><p id="en-us_topic_0000001149710363_p963mcpsimp"><a name="en-us_topic_0000001149710363_p963mcpsimp"></a><a name="en-us_topic_0000001149710363_p963mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001149710363_row965mcpsimp"><td class="cellrowborder" valign="top" width="19%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001149710363_p967mcpsimp"><a name="en-us_topic_0000001149710363_p967mcpsimp"></a><a name="en-us_topic_0000001149710363_p967mcpsimp"></a>result</p>
</td>
<td class="cellrowborder" valign="top" width="23.62%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001149710363_p969mcpsimp"><a name="en-us_topic_0000001149710363_p969mcpsimp"></a><a name="en-us_topic_0000001149710363_p969mcpsimp"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="57.379999999999995%" headers="mcps1.1.4.1.3 ">&nbsp;&nbsp;</td>
</tr>
</tbody>
</table>

**Example**

```
// Set the update policy.
let policy = {
autoDownload: false,
autoDownloadNet: true,
mode: 2,
autoUpgradeInterval: [ 2, 3 ],
autoUpgradeCondition: 2
}
updater.setUpdatePolicy(policy, function(result) {
console.log("setUpdatePolicy ", result)
}
);
```

## updater.getUpdatePolicy\(\)<a name="en-us_topic_0000001149710363_section985mcpsimp"></a>

Checks the update policy.

**Parameters**

<a name="en-us_topic_0000001149710363_table990mcpsimp"></a>
<table><thead align="left"><tr id="en-us_topic_0000001149710363_row997mcpsimp"><th class="cellrowborder" valign="top" width="11%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001149710363_p999mcpsimp"><a name="en-us_topic_0000001149710363_p999mcpsimp"></a><a name="en-us_topic_0000001149710363_p999mcpsimp"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="16.41%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001149710363_p1001mcpsimp"><a name="en-us_topic_0000001149710363_p1001mcpsimp"></a><a name="en-us_topic_0000001149710363_p1001mcpsimp"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="24.72%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001149710363_p1003mcpsimp"><a name="en-us_topic_0000001149710363_p1003mcpsimp"></a><a name="en-us_topic_0000001149710363_p1003mcpsimp"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="47.870000000000005%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001149710363_p1005mcpsimp"><a name="en-us_topic_0000001149710363_p1005mcpsimp"></a><a name="en-us_topic_0000001149710363_p1005mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001149710363_row1007mcpsimp"><td class="cellrowborder" valign="top" width="11%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001149710363_p1009mcpsimp"><a name="en-us_topic_0000001149710363_p1009mcpsimp"></a><a name="en-us_topic_0000001149710363_p1009mcpsimp"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="16.41%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001149710363_p1011mcpsimp"><a name="en-us_topic_0000001149710363_p1011mcpsimp"></a><a name="en-us_topic_0000001149710363_p1011mcpsimp"></a>Function</p>
</td>
<td class="cellrowborder" valign="top" width="24.72%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001149710363_p1013mcpsimp"><a name="en-us_topic_0000001149710363_p1013mcpsimp"></a><a name="en-us_topic_0000001149710363_p1013mcpsimp"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="47.870000000000005%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001149710363_p1015mcpsimp"><a name="en-us_topic_0000001149710363_p1015mcpsimp"></a><a name="en-us_topic_0000001149710363_p1015mcpsimp"></a>AsyncCallback&lt;UpdatePolicy&gt;</p>
</td>
</tr>
</tbody>
</table>

**Return Values**

<a name="en-us_topic_0000001149710363_table1018mcpsimp"></a>
<table><thead align="left"><tr id="en-us_topic_0000001149710363_row1024mcpsimp"><th class="cellrowborder" valign="top" width="19%" id="mcps1.1.4.1.1"><p id="en-us_topic_0000001149710363_p1026mcpsimp"><a name="en-us_topic_0000001149710363_p1026mcpsimp"></a><a name="en-us_topic_0000001149710363_p1026mcpsimp"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="29.64%" id="mcps1.1.4.1.2"><p id="en-us_topic_0000001149710363_p1028mcpsimp"><a name="en-us_topic_0000001149710363_p1028mcpsimp"></a><a name="en-us_topic_0000001149710363_p1028mcpsimp"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="51.35999999999999%" id="mcps1.1.4.1.3"><p id="en-us_topic_0000001149710363_p1030mcpsimp"><a name="en-us_topic_0000001149710363_p1030mcpsimp"></a><a name="en-us_topic_0000001149710363_p1030mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001149710363_row1032mcpsimp"><td class="cellrowborder" valign="top" width="19%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001149710363_p1034mcpsimp"><a name="en-us_topic_0000001149710363_p1034mcpsimp"></a><a name="en-us_topic_0000001149710363_p1034mcpsimp"></a>policy</p>
</td>
<td class="cellrowborder" valign="top" width="29.64%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001149710363_p1036mcpsimp"><a name="en-us_topic_0000001149710363_p1036mcpsimp"></a><a name="en-us_topic_0000001149710363_p1036mcpsimp"></a>UpdatePolicy</p>
</td>
<td class="cellrowborder" valign="top" width="51.35999999999999%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001149710363_p1038mcpsimp"><a name="en-us_topic_0000001149710363_p1038mcpsimp"></a><a name="en-us_topic_0000001149710363_p1038mcpsimp"></a>Update policy</p>
</td>
</tr>
</tbody>
</table>

**Example**

```
updater.getUpdatePolicy(policy => {
console.log("getUpdatePolicy success", policy)
});
```

