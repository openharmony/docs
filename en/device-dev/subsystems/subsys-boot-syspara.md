# syspara Module<a name="EN-US_TOPIC_0000001063362360"></a>

-   [Introduction](#section381564832813)
-   [System Parameter Definition Rules](#section431671411293)
    -   [System Parameter Value Definition File](#section885018321291)
    -   [System Parameter DAC Definition File](#section1333155762915)
    -   [Installation of the System Parameter Definition File](#section43801513193014)
    -   [Loading Sequence of the System Parameter Value Definition File](#section89971332173017)

-   [Usage of Shell Commands](#section2039119283111)
-   [Available APIs](#section0137175692616)
-   [How to Use](#section118404913233)

## Introduction<a name="section381564832813"></a>

This module provides an easy-to-use key-value pair access interface for system services to configure service functions based on their own system parameters. The following figure shows the basic primitives used to access and operate system parameters.

**Figure  1**  Operation primitives for system parameters<a name="fig1976004014480"></a>  
![](figure/operation-primitives-for-system-parameters.png "operation-primitives-for-system-parameters")

**Table  1**  Description of operation primitives

<a name="table899071145116"></a>
<table><thead align="left"><tr id="row699014115513"><th class="cellrowborder" valign="top" width="15.97%" id="mcps1.2.3.1.1"><p id="p9990111195119"><a name="p9990111195119"></a><a name="p9990111195119"></a>Primitive</p>
</th>
<th class="cellrowborder" valign="top" width="84.03%" id="mcps1.2.3.1.2"><p id="p5990614518"><a name="p5990614518"></a><a name="p5990614518"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1699011113511"><td class="cellrowborder" valign="top" width="15.97%" headers="mcps1.2.3.1.1 "><p id="p099071175116"><a name="p099071175116"></a><a name="p099071175116"></a>get</p>
</td>
<td class="cellrowborder" valign="top" width="84.03%" headers="mcps1.2.3.1.2 "><p id="p199021165116"><a name="p199021165116"></a><a name="p199021165116"></a>Obtains the value of a system parameter.</p>
</td>
</tr>
<tr id="row1299019117513"><td class="cellrowborder" valign="top" width="15.97%" headers="mcps1.2.3.1.1 "><p id="p159901918510"><a name="p159901918510"></a><a name="p159901918510"></a>set</p>
</td>
<td class="cellrowborder" valign="top" width="84.03%" headers="mcps1.2.3.1.2 "><p id="p1990181115112"><a name="p1990181115112"></a><a name="p1990181115112"></a>Sets the value of a system parameter.</p>
</td>
</tr>
<tr id="row19901812519"><td class="cellrowborder" valign="top" width="15.97%" headers="mcps1.2.3.1.1 "><p id="p1999014105117"><a name="p1999014105117"></a><a name="p1999014105117"></a>wait</p>
</td>
<td class="cellrowborder" valign="top" width="84.03%" headers="mcps1.2.3.1.2 "><p id="p399010135114"><a name="p399010135114"></a><a name="p399010135114"></a>Waits for value change of a system parameter synchronously.</p>
</td>
</tr>
<tr id="row1990161115119"><td class="cellrowborder" valign="top" width="15.97%" headers="mcps1.2.3.1.1 "><p id="p16990515518"><a name="p16990515518"></a><a name="p16990515518"></a>watch</p>
</td>
<td class="cellrowborder" valign="top" width="84.03%" headers="mcps1.2.3.1.2 "><p id="p49914114514"><a name="p49914114514"></a><a name="p49914114514"></a>Observes value change of a system parameter asynchronously.</p>
</td>
</tr>
</tbody>
</table>

A system parameter name consists of multiple segments in dotted notation. Each segment consists of letters, digits, and underscores \(\_\). The total length cannot exceed 96 bytes. System parameter names are categorized into the following two types.

**Table  2**  Naming of system parameters

<a name="table112542320396"></a>
<table><thead align="left"><tr id="row14254173103914"><th class="cellrowborder" valign="top" width="16.18%" id="mcps1.2.5.1.1"><p id="p14949687392"><a name="p14949687392"></a><a name="p14949687392"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="22.03%" id="mcps1.2.5.1.2"><p id="p694920810396"><a name="p694920810396"></a><a name="p694920810396"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="21.16%" id="mcps1.2.5.1.3"><p id="p294910814394"><a name="p294910814394"></a><a name="p294910814394"></a>Example</p>
</th>
<th class="cellrowborder" valign="top" width="40.63%" id="mcps1.2.5.1.4"><p id="p139499833914"><a name="p139499833914"></a><a name="p139499833914"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row925413163910"><td class="cellrowborder" valign="top" width="16.18%" headers="mcps1.2.5.1.1 "><p id="p1594948123911"><a name="p1594948123911"></a><a name="p1594948123911"></a>Parameter name</p>
</td>
<td class="cellrowborder" valign="top" width="22.03%" headers="mcps1.2.5.1.2 "><p id="p29497883916"><a name="p29497883916"></a><a name="p29497883916"></a>Parameter Name</p>
</td>
<td class="cellrowborder" valign="top" width="21.16%" headers="mcps1.2.5.1.3 "><p id="p0949128173919"><a name="p0949128173919"></a><a name="p0949128173919"></a>const.product.<strong id="b149490833912"><a name="b149490833912"></a><a name="b149490833912"></a>name</strong></p>
</td>
<td class="cellrowborder" valign="top" width="40.63%" headers="mcps1.2.5.1.4 "><p id="p179491489392"><a name="p179491489392"></a><a name="p179491489392"></a>Complete system parameter name. It does not end with a period (.).</p>
</td>
</tr>
<tr id="row92543373919"><td class="cellrowborder" valign="top" width="16.18%" headers="mcps1.2.5.1.1 "><p id="p159496813399"><a name="p159496813399"></a><a name="p159496813399"></a>Parameter directory</p>
</td>
<td class="cellrowborder" valign="top" width="22.03%" headers="mcps1.2.5.1.2 "><p id="p12950118133918"><a name="p12950118133918"></a><a name="p12950118133918"></a>Parameter Directory</p>
</td>
<td class="cellrowborder" valign="top" width="21.16%" headers="mcps1.2.5.1.3 "><p id="p49501863913"><a name="p49501863913"></a><a name="p49501863913"></a>const.product<strong id="b4950189395"><a name="b4950189395"></a><a name="b4950189395"></a>.</strong></p>
</td>
<td class="cellrowborder" valign="top" width="40.63%" headers="mcps1.2.5.1.4 "><p id="p49502843912"><a name="p49502843912"></a><a name="p49502843912"></a>Name of the directory storing system parameters with the same prefix. It ends with a period (.).</p>
</td>
</tr>
</tbody>
</table>

System parameters are categorized into three types.

**Table  3**  System parameter types

<a name="table115286426391"></a>
<table><thead align="left"><tr id="row1852954263910"><th class="cellrowborder" valign="top" width="16.6016601660166%" id="mcps1.2.4.1.1"><p id="p240948143911"><a name="p240948143911"></a><a name="p240948143911"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="21.242124212421242%" id="mcps1.2.4.1.2"><p id="p8403483399"><a name="p8403483399"></a><a name="p8403483399"></a>Prefix</p>
</th>
<th class="cellrowborder" valign="top" width="62.15621562156216%" id="mcps1.2.4.1.3"><p id="p1540748153916"><a name="p1540748153916"></a><a name="p1540748153916"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row145291642143915"><td class="cellrowborder" valign="top" width="16.6016601660166%" headers="mcps1.2.4.1.1 "><p id="p040134815392"><a name="p040134815392"></a><a name="p040134815392"></a>Constant</p>
</td>
<td class="cellrowborder" valign="top" width="21.242124212421242%" headers="mcps1.2.4.1.2 "><p id="p114014814391"><a name="p114014814391"></a><a name="p114014814391"></a><strong id="b16400482395"><a name="b16400482395"></a><a name="b16400482395"></a>const.</strong></p>
</td>
<td class="cellrowborder" valign="top" width="62.15621562156216%" headers="mcps1.2.4.1.3 "><p id="p04018486398"><a name="p04018486398"></a><a name="p04018486398"></a>Constant parameter, which will not be changed once a value is assigned. The value can contain a maximum of 4,096 bytes (including the terminator).</p>
</td>
</tr>
<tr id="row452954223914"><td class="cellrowborder" valign="top" width="16.6016601660166%" headers="mcps1.2.4.1.1 "><p id="p174064843918"><a name="p174064843918"></a><a name="p174064843918"></a>Writable</p>
</td>
<td class="cellrowborder" valign="top" width="21.242124212421242%" headers="mcps1.2.4.1.2 "><p id="p040114873910"><a name="p040114873910"></a><a name="p040114873910"></a>Others</p>
</td>
<td class="cellrowborder" valign="top" width="62.15621562156216%" headers="mcps1.2.4.1.3 "><p id="p17401548203919"><a name="p17401548203919"></a><a name="p17401548203919"></a>Writable parameter, which will be lost after system restart. The value can contain a maximum of 96 bytes (including the terminator).</p>
</td>
</tr>
<tr id="row125292042103912"><td class="cellrowborder" valign="top" width="16.6016601660166%" headers="mcps1.2.4.1.1 "><p id="p240154813918"><a name="p240154813918"></a><a name="p240154813918"></a>Persistent</p>
</td>
<td class="cellrowborder" valign="top" width="21.242124212421242%" headers="mcps1.2.4.1.2 "><p id="p1340124812396"><a name="p1340124812396"></a><a name="p1340124812396"></a><strong id="b74094893920"><a name="b74094893920"></a><a name="b74094893920"></a>persist.</strong></p>
</td>
<td class="cellrowborder" valign="top" width="62.15621562156216%" headers="mcps1.2.4.1.3 "><p id="p124011485394"><a name="p124011485394"></a><a name="p124011485394"></a>Writable and persistent parameter, which will not be lost after system restart. The value can contain a maximum of 96 bytes (including the terminator).</p>
</td>
</tr>
</tbody>
</table>

The naming format of system parameters is as follows: \[**const**|**persist**\].**$sub\_system**.**$desc**.

**$sub\_system**  is the name of the subsystem or module.

**$desc**  indicates the description of a system parameter. The description can contain multiple segments in dotted notation.

## System Parameter Definition Rules<a name="section431671411293"></a>

Each subsystem defines the system parameters of its own modules, including the system parameter name, default value, and access permission information.

### System Parameter Value Definition File<a name="section885018321291"></a>

The system parameter value definition file ends with the  **.para**  extension. An example of the file format is as follows:

```
# This is comment
const.product.name=OHOS-PRODUCT
const.os.version.api=26
const.telephony.enable=false|true

const.test.withblank=My Value
```

Note: System parameter values do not support comments and line breaks.

```
# Not supported
const.test.withcomment=MyValue # This should be ommitted
# Not supported
const.test.multiline="This is a multiline parameter.
Line2 value.
Last line."
```

You must use a complete system parameter command when assigning a value for a system parameter. The following table describes the value assignment modes.

**Table  4**  Value assignment modes

<a name="table52741681265"></a>
<table><thead align="left"><tr id="row127520817617"><th class="cellrowborder" valign="top" width="12.221222122212222%" id="mcps1.2.4.1.1"><p id="p34581418615"><a name="p34581418615"></a><a name="p34581418615"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="34.41344134413441%" id="mcps1.2.4.1.2"><p id="p134517146610"><a name="p134517146610"></a><a name="p134517146610"></a>Example</p>
</th>
<th class="cellrowborder" valign="top" width="53.36533653365336%" id="mcps1.2.4.1.3"><p id="p15451614166"><a name="p15451614166"></a><a name="p15451614166"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1527514815619"><td class="cellrowborder" valign="top" width="12.221222122212222%" headers="mcps1.2.4.1.1 "><p id="p045181414616"><a name="p045181414616"></a><a name="p045181414616"></a>String</p>
</td>
<td class="cellrowborder" valign="top" width="34.41344134413441%" headers="mcps1.2.4.1.2 "><p id="p1745111415617"><a name="p1745111415617"></a><a name="p1745111415617"></a>const.product.name=OHOS-PRODUCT</p>
</td>
<td class="cellrowborder" valign="top" width="53.36533653365336%" headers="mcps1.2.4.1.3 "><p id="p154513142069"><a name="p154513142069"></a><a name="p154513142069"></a>Multi-line character strings and comments are not supported.</p>
</td>
</tr>
<tr id="row627519814617"><td class="cellrowborder" valign="top" width="12.221222122212222%" headers="mcps1.2.4.1.1 "><p id="p5457144620"><a name="p5457144620"></a><a name="p5457144620"></a>Number</p>
</td>
<td class="cellrowborder" valign="top" width="34.41344134413441%" headers="mcps1.2.4.1.2 "><p id="p94519149617"><a name="p94519149617"></a><a name="p94519149617"></a>const.os.version.api=26</p>
</td>
<td class="cellrowborder" valign="top" width="53.36533653365336%" headers="mcps1.2.4.1.3 "><p id="p1453146614"><a name="p1453146614"></a><a name="p1453146614"></a>Numbers do not need to be enclosed in quotation marks.</p>
</td>
</tr>
<tr id="row92751882069"><td class="cellrowborder" valign="top" width="12.221222122212222%" headers="mcps1.2.4.1.1 "><p id="p17457141864"><a name="p17457141864"></a><a name="p17457141864"></a>Boolean</p>
</td>
<td class="cellrowborder" valign="top" width="34.41344134413441%" headers="mcps1.2.4.1.2 "><p id="p945131413611"><a name="p945131413611"></a><a name="p945131413611"></a>const.telephony.enable=false</p>
</td>
<td class="cellrowborder" valign="top" width="53.36533653365336%" headers="mcps1.2.4.1.3 "><p id="p164551415610"><a name="p164551415610"></a><a name="p164551415610"></a>A Boolean value can be <strong id="b8188102315415"><a name="b8188102315415"></a><a name="b8188102315415"></a>0</strong>, <strong id="b64910241414"><a name="b64910241414"></a><a name="b64910241414"></a>1</strong>, <strong id="b116922684114"><a name="b116922684114"></a><a name="b116922684114"></a>false</strong>, or <strong id="b13402102744114"><a name="b13402102744114"></a><a name="b13402102744114"></a>true</strong>.</p>
</td>
</tr>
</tbody>
</table>

### System Parameter DAC Definition File<a name="section1333155762915"></a>

Currently, access permissions of system parameters are managed in Discretionary Access Control \(DAC\) mode. The access permission definition file ends with the  **.para.dac**  extension. The following is an example:

```
const.product.="root:root:660"
```

As shown above, we can use  **parameter directory**  to define the same access permission for system parameters with the same prefix. The DAC information is divided into three segments, user, group, and UGO rule information, which are separated using a semicolon \(:\).

The following figure shows the structure of the UGO rule information.

**Figure  2**  Rule information<a name="fig929815371095"></a>  
![](figure/rule-information.png "rule-information")

### Installation of the System Parameter Definition File<a name="section43801513193014"></a>

The  **.para**  and  **.para.dac**  files are installed in the  **/etc/param/**  directory. An example of the GN script is as follows:

```
ohos_prebuilt_etc("ohos.para") {
    source = "//base/startup/init_lite/services/etc/ohos.para"
    part_name = "init"
    module_install_dir = "etc/param"
}

ohos_prebuilt_etc("ohos.para.dac") {
    source = "//base/startup/init_lite/services/etc/ohos.para.dac"
    part_name = "init"
    module_install_dir = "etc/param"
}
```

### Loading Sequence of the System Parameter Value Definition File<a name="section89971332173017"></a>

The following table provides the sequence of loading system parameter value definition files.

**Table  5**  Sequence of loading system parameter value definition files

<a name="table1799911716110"></a>
<table><thead align="left"><tr id="row19993720112"><th class="cellrowborder" valign="top" width="16.661666166616662%" id="mcps1.2.4.1.1"><p id="p934241851112"><a name="p934241851112"></a><a name="p934241851112"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="30.183018301830185%" id="mcps1.2.4.1.2"><p id="p6342018191114"><a name="p6342018191114"></a><a name="p6342018191114"></a>Directory</p>
</th>
<th class="cellrowborder" valign="top" width="53.15531553155315%" id="mcps1.2.4.1.3"><p id="p193421518141113"><a name="p193421518141113"></a><a name="p193421518141113"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1299987141116"><td class="cellrowborder" valign="top" width="16.661666166616662%" headers="mcps1.2.4.1.1 "><p id="p4342171816117"><a name="p4342171816117"></a><a name="p4342171816117"></a>Kernel parameters</p>
</td>
<td class="cellrowborder" valign="top" width="30.183018301830185%" headers="mcps1.2.4.1.2 "><p id="p19342141817113"><a name="p19342141817113"></a><a name="p19342141817113"></a>/proc/cmdline</p>
</td>
<td class="cellrowborder" valign="top" width="53.15531553155315%" headers="mcps1.2.4.1.3 "><p id="p7342151818115"><a name="p7342151818115"></a><a name="p7342151818115"></a>In kernel parameters, <strong id="b93436589497"><a name="b93436589497"></a><a name="b93436589497"></a>ohospara.xxx=valXXX</strong> is converted to <strong id="b5967204145020"><a name="b5967204145020"></a><a name="b5967204145020"></a>ohos.boot.xxx=valXXX</strong>.</p>
</td>
</tr>
<tr id="row1899910718117"><td class="cellrowborder" valign="top" width="16.661666166616662%" headers="mcps1.2.4.1.1 "><p id="p23421818131112"><a name="p23421818131112"></a><a name="p23421818131112"></a>OS constants</p>
</td>
<td class="cellrowborder" valign="top" width="30.183018301830185%" headers="mcps1.2.4.1.2 "><p id="p20342161881115"><a name="p20342161881115"></a><a name="p20342161881115"></a>/system/etc/param/ohos_const/*.para</p>
</td>
<td class="cellrowborder" valign="top" width="53.15531553155315%" headers="mcps1.2.4.1.3 "><p id="p163421186115"><a name="p163421186115"></a><a name="p163421186115"></a>The definition file containing OS constants is preferentially loaded.</p>
</td>
</tr>
<tr id="row1098101119"><td class="cellrowborder" valign="top" width="16.661666166616662%" headers="mcps1.2.4.1.1 "><p id="p14342171815115"><a name="p14342171815115"></a><a name="p14342171815115"></a>System parameters in the <strong id="b19874122065519"><a name="b19874122065519"></a><a name="b19874122065519"></a>vendor</strong> directory</p>
</td>
<td class="cellrowborder" valign="top" width="30.183018301830185%" headers="mcps1.2.4.1.2 "><p id="p33425183117"><a name="p33425183117"></a><a name="p33425183117"></a>/vendor/etc/param/*.para</p>
</td>
<td class="cellrowborder" valign="top" width="53.15531553155315%" headers="mcps1.2.4.1.3 "><p id="p9342171861112"><a name="p9342171861112"></a><a name="p9342171861112"></a>The definition file containing system parameters in the <strong id="b974219911015"><a name="b974219911015"></a><a name="b974219911015"></a>vendor</strong> directory is loaded with the secondary priority. It can overwrite the definition file containing system parrameters in the <strong id="b1544125011115"><a name="b1544125011115"></a><a name="b1544125011115"></a>system</strong> directory.</p>
</td>
</tr>
<tr id="row1301784115"><td class="cellrowborder" valign="top" width="16.661666166616662%" headers="mcps1.2.4.1.1 "><p id="p234241851115"><a name="p234241851115"></a><a name="p234241851115"></a>System parameters in the <strong id="b0483162515513"><a name="b0483162515513"></a><a name="b0483162515513"></a>system</strong> directory</p>
</td>
<td class="cellrowborder" valign="top" width="30.183018301830185%" headers="mcps1.2.4.1.2 "><p id="p123421618161111"><a name="p123421618161111"></a><a name="p123421618161111"></a>/system/etc/param/*.para</p>
</td>
<td class="cellrowborder" valign="top" width="53.15531553155315%" headers="mcps1.2.4.1.3 "><p id="p134351881120"><a name="p134351881120"></a><a name="p134351881120"></a>The definition file containing system parameters in the <strong id="b1769018221223"><a name="b1769018221223"></a><a name="b1769018221223"></a>system</strong> directory is last loaded. If a system parameter value already exists in the file, it will be ignored.</p>
</td>
</tr>
</tbody>
</table>

## Usage of Shell Commands<a name="section2039119283111"></a>

The following table describes the shell commands used to set system parameters.

**Table  6**  Description of shell commands

<a name="table59129731519"></a>
<table><thead align="left"><tr id="row209121710156"><th class="cellrowborder" valign="top" width="20.5%" id="mcps1.2.3.1.1"><p id="p119421012181520"><a name="p119421012181520"></a><a name="p119421012181520"></a>Command</p>
</th>
<th class="cellrowborder" valign="top" width="79.5%" id="mcps1.2.3.1.2"><p id="p394210128157"><a name="p394210128157"></a><a name="p394210128157"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row169122781510"><td class="cellrowborder" valign="top" width="20.5%" headers="mcps1.2.3.1.1 "><p id="p6942112161517"><a name="p6942112161517"></a><a name="p6942112161517"></a>param get [<strong id="b1942161281515"><a name="b1942161281515"></a><a name="b1942161281515"></a>key</strong>]</p>
</td>
<td class="cellrowborder" valign="top" width="79.5%" headers="mcps1.2.3.1.2 "><p id="p594291216151"><a name="p594291216151"></a><a name="p594291216151"></a>Obtains the system parameter value of the specified key. If no key name is specified, all system parameter values will be returned.</p>
</td>
</tr>
<tr id="row17912472157"><td class="cellrowborder" valign="top" width="20.5%" headers="mcps1.2.3.1.1 "><p id="p3942191271519"><a name="p3942191271519"></a><a name="p3942191271519"></a>param set <strong id="b7942171219153"><a name="b7942171219153"></a><a name="b7942171219153"></a>key value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="79.5%" headers="mcps1.2.3.1.2 "><p id="p1494271218159"><a name="p1494271218159"></a><a name="p1494271218159"></a>Sets the specified value for the specified key.</p>
</td>
</tr>
<tr id="row0912572155"><td class="cellrowborder" valign="top" width="20.5%" headers="mcps1.2.3.1.1 "><p id="p194221231518"><a name="p194221231518"></a><a name="p194221231518"></a>param wait <strong id="b16942141213156"><a name="b16942141213156"></a><a name="b16942141213156"></a>key</strong> <strong id="b10943312161515"><a name="b10943312161515"></a><a name="b10943312161515"></a>value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="79.5%" headers="mcps1.2.3.1.2 "><p id="p6943912161512"><a name="p6943912161512"></a><a name="p6943912161512"></a>Waits for the system parameter value of the specified key to match the specified value. Fuzzy match is supported. For example, <strong id="b79411030762"><a name="b79411030762"></a><a name="b79411030762"></a>*</strong> indicates any value, and <strong id="b162794371964"><a name="b162794371964"></a><a name="b162794371964"></a>val*</strong> indicates matching of only the first three val characters.</p>
</td>
</tr>
<tr id="row1091287141516"><td class="cellrowborder" valign="top" width="20.5%" headers="mcps1.2.3.1.1 "><p id="p3943712191519"><a name="p3943712191519"></a><a name="p3943712191519"></a>param dump</p>
</td>
<td class="cellrowborder" valign="top" width="79.5%" headers="mcps1.2.3.1.2 "><p id="p89431212201516"><a name="p89431212201516"></a><a name="p89431212201516"></a>Displays the statistics of system parameters.</p>
</td>
</tr>
</tbody>
</table>

## Available APIs<a name="section0137175692616"></a>

**Table  7**  APIs for the syspara module

<a name="table1731550155318"></a>
<table><thead align="left"><tr id="row4419501537"><th class="cellrowborder" valign="top" width="57.29%" id="mcps1.2.3.1.1"><p id="p54150165315"><a name="p54150165315"></a><a name="p54150165315"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="42.71%" id="mcps1.2.3.1.2"><p id="p941150145313"><a name="p941150145313"></a><a name="p941150145313"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row34145016535"><td class="cellrowborder" valign="top" width="57.29%" headers="mcps1.2.3.1.1 "><p id="p15146174185515"><a name="p15146174185515"></a><a name="p15146174185515"></a>int GetParameter(const char* key, const char* def, char* value, unsigned int len)</p>
</td>
<td class="cellrowborder" valign="top" width="42.71%" headers="mcps1.2.3.1.2 "><p id="p13562171015712"><a name="p13562171015712"></a><a name="p13562171015712"></a>Obtains a system parameter.</p>
</td>
</tr>
<tr id="row57882012954"><td class="cellrowborder" valign="top" width="57.29%" headers="mcps1.2.3.1.1 "><p id="p77897122517"><a name="p77897122517"></a><a name="p77897122517"></a>int SetParameter(const char* key, const char* value)</p>
</td>
<td class="cellrowborder" valign="top" width="42.71%" headers="mcps1.2.3.1.2 "><p id="p8150164120555"><a name="p8150164120555"></a><a name="p8150164120555"></a>Sets or updates a system parameter.</p>
</td>
</tr>
<tr id="row1746172917474"><td class="cellrowborder" valign="top" width="57.29%" headers="mcps1.2.3.1.1 "><p id="p1315210414552"><a name="p1315210414552"></a><a name="p1315210414552"></a>const char* GetDeviceType(void)</p>
</td>
<td class="cellrowborder" valign="top" width="42.71%" headers="mcps1.2.3.1.2 "><p id="p12366194110514"><a name="p12366194110514"></a><a name="p12366194110514"></a>Obtains the device type.</p>
</td>
</tr>
<tr id="row10992232154714"><td class="cellrowborder" valign="top" width="57.29%" headers="mcps1.2.3.1.1 "><p id="p19154174135517"><a name="p19154174135517"></a><a name="p19154174135517"></a>const char* GetManufacture(void)</p>
</td>
<td class="cellrowborder" valign="top" width="42.71%" headers="mcps1.2.3.1.2 "><p id="p191521415555"><a name="p191521415555"></a><a name="p191521415555"></a>Obtains the device manufacturer.</p>
</td>
</tr>
<tr id="row137112185917"><td class="cellrowborder" valign="top" width="57.29%" headers="mcps1.2.3.1.1 "><p id="p16371201145918"><a name="p16371201145918"></a><a name="p16371201145918"></a>const char* GetBrand(void)</p>
</td>
<td class="cellrowborder" valign="top" width="42.71%" headers="mcps1.2.3.1.2 "><p id="p2371719599"><a name="p2371719599"></a><a name="p2371719599"></a>Obtains the device brand.</p>
</td>
</tr>
<tr id="row981535875818"><td class="cellrowborder" valign="top" width="57.29%" headers="mcps1.2.3.1.1 "><p id="p18151586589"><a name="p18151586589"></a><a name="p18151586589"></a>const char* GetMarketName(void)</p>
</td>
<td class="cellrowborder" valign="top" width="42.71%" headers="mcps1.2.3.1.2 "><p id="p1081545865810"><a name="p1081545865810"></a><a name="p1081545865810"></a>Obtains the device marketing name.</p>
</td>
</tr>
<tr id="row45019563583"><td class="cellrowborder" valign="top" width="57.29%" headers="mcps1.2.3.1.1 "><p id="p3501195617581"><a name="p3501195617581"></a><a name="p3501195617581"></a>const char* GetProductSeries(void)</p>
</td>
<td class="cellrowborder" valign="top" width="42.71%" headers="mcps1.2.3.1.2 "><p id="p65011156165811"><a name="p65011156165811"></a><a name="p65011156165811"></a>Obtains the device series name.</p>
</td>
</tr>
<tr id="row732525410585"><td class="cellrowborder" valign="top" width="57.29%" headers="mcps1.2.3.1.1 "><p id="p10325125465819"><a name="p10325125465819"></a><a name="p10325125465819"></a>const char* GetProductModel(void)</p>
</td>
<td class="cellrowborder" valign="top" width="42.71%" headers="mcps1.2.3.1.2 "><p id="p332565412582"><a name="p332565412582"></a><a name="p332565412582"></a>Obtains the device authentication model.</p>
</td>
</tr>
<tr id="row5746145116588"><td class="cellrowborder" valign="top" width="57.29%" headers="mcps1.2.3.1.1 "><p id="p20746145145812"><a name="p20746145145812"></a><a name="p20746145145812"></a>const char* GetSoftwareModel(void)</p>
</td>
<td class="cellrowborder" valign="top" width="42.71%" headers="mcps1.2.3.1.2 "><p id="p14746175165810"><a name="p14746175165810"></a><a name="p14746175165810"></a>Obtains the device software model.</p>
</td>
</tr>
<tr id="row536404914589"><td class="cellrowborder" valign="top" width="57.29%" headers="mcps1.2.3.1.1 "><p id="p1364749135819"><a name="p1364749135819"></a><a name="p1364749135819"></a>const char* GetHardwareModel(void)</p>
</td>
<td class="cellrowborder" valign="top" width="42.71%" headers="mcps1.2.3.1.2 "><p id="p1536424935819"><a name="p1536424935819"></a><a name="p1536424935819"></a>Obtains the device hardware model.</p>
</td>
</tr>
<tr id="row453414616584"><td class="cellrowborder" valign="top" width="57.29%" headers="mcps1.2.3.1.1 "><p id="p15534164685817"><a name="p15534164685817"></a><a name="p15534164685817"></a>const char* GetHardwareProfile(void)</p>
</td>
<td class="cellrowborder" valign="top" width="42.71%" headers="mcps1.2.3.1.2 "><p id="p15534154619588"><a name="p15534154619588"></a><a name="p15534154619588"></a>Obtains the device hardware profile.</p>
</td>
</tr>
<tr id="row3279655002"><td class="cellrowborder" valign="top" width="57.29%" headers="mcps1.2.3.1.1 "><p id="p112791755204"><a name="p112791755204"></a><a name="p112791755204"></a>const char* GetSerial(void)</p>
</td>
<td class="cellrowborder" valign="top" width="42.71%" headers="mcps1.2.3.1.2 "><p id="p1827910551901"><a name="p1827910551901"></a><a name="p1827910551901"></a>Obtains the device serial number (SN).</p>
</td>
</tr>
<tr id="row101032053602"><td class="cellrowborder" valign="top" width="57.29%" headers="mcps1.2.3.1.1 "><p id="p810395319016"><a name="p810395319016"></a><a name="p810395319016"></a>const char* GetOSFullName(void)</p>
</td>
<td class="cellrowborder" valign="top" width="42.71%" headers="mcps1.2.3.1.2 "><p id="p181037531301"><a name="p181037531301"></a><a name="p181037531301"></a>Obtains the operating system name.</p>
</td>
</tr>
<tr id="row081175112010"><td class="cellrowborder" valign="top" width="57.29%" headers="mcps1.2.3.1.1 "><p id="p13821151707"><a name="p13821151707"></a><a name="p13821151707"></a>const char* GetDisplayVersion(void)</p>
</td>
<td class="cellrowborder" valign="top" width="42.71%" headers="mcps1.2.3.1.2 "><p id="p582251708"><a name="p582251708"></a><a name="p582251708"></a>Obtains the software version visible to users.</p>
</td>
</tr>
<tr id="row19112249108"><td class="cellrowborder" valign="top" width="57.29%" headers="mcps1.2.3.1.1 "><p id="p1411224911016"><a name="p1411224911016"></a><a name="p1411224911016"></a>const char* GetBootloaderVersion(void)</p>
</td>
<td class="cellrowborder" valign="top" width="42.71%" headers="mcps1.2.3.1.2 "><p id="p11122497014"><a name="p11122497014"></a><a name="p11122497014"></a>Obtains the bootloader version of this device.</p>
</td>
</tr>
<tr id="row138384461706"><td class="cellrowborder" valign="top" width="57.29%" headers="mcps1.2.3.1.1 "><p id="p20839194620019"><a name="p20839194620019"></a><a name="p20839194620019"></a>const char* GetSecurityPatchTag(void)</p>
</td>
<td class="cellrowborder" valign="top" width="42.71%" headers="mcps1.2.3.1.2 "><p id="p118393469018"><a name="p118393469018"></a><a name="p118393469018"></a>Obtains the security patch tag.</p>
</td>
</tr>
<tr id="row58521914120"><td class="cellrowborder" valign="top" width="57.29%" headers="mcps1.2.3.1.1 "><p id="p48527149215"><a name="p48527149215"></a><a name="p48527149215"></a>const char* GetAbiList(void)</p>
</td>
<td class="cellrowborder" valign="top" width="42.71%" headers="mcps1.2.3.1.2 "><p id="p8852114628"><a name="p8852114628"></a><a name="p8852114628"></a>Obtains the list of application binary interfaces (ABIs) supported on this device.</p>
</td>
</tr>
<tr id="row394071216210"><td class="cellrowborder" valign="top" width="57.29%" headers="mcps1.2.3.1.1 "><p id="p6140142115818"><a name="p6140142115818"></a><a name="p6140142115818"></a>int GetSdkApiVersion(void)</p>
</td>
<td class="cellrowborder" valign="top" width="42.71%" headers="mcps1.2.3.1.2 "><p id="p18940171215214"><a name="p18940171215214"></a><a name="p18940171215214"></a>Obtains the SDK API version that matches the current system software.</p>
</td>
</tr>
<tr id="row138205101425"><td class="cellrowborder" valign="top" width="57.29%" headers="mcps1.2.3.1.1 "><p id="p19239130582"><a name="p19239130582"></a><a name="p19239130582"></a>int GetFirstApiVersion(void)</p>
</td>
<td class="cellrowborder" valign="top" width="42.71%" headers="mcps1.2.3.1.2 "><p id="p3820810521"><a name="p3820810521"></a><a name="p3820810521"></a>Obtains the first SDK API version of the system software.</p>
</td>
</tr>
<tr id="row156198627"><td class="cellrowborder" valign="top" width="57.29%" headers="mcps1.2.3.1.1 "><p id="p75622084212"><a name="p75622084212"></a><a name="p75622084212"></a>const char* GetIncrementalVersion(void)</p>
</td>
<td class="cellrowborder" valign="top" width="42.71%" headers="mcps1.2.3.1.2 "><p id="p95621087211"><a name="p95621087211"></a><a name="p95621087211"></a>Obtains the incremental version.</p>
</td>
</tr>
<tr id="row138721511320"><td class="cellrowborder" valign="top" width="57.29%" headers="mcps1.2.3.1.1 "><p id="p28715156318"><a name="p28715156318"></a><a name="p28715156318"></a>const char* GetVersionId(void)</p>
</td>
<td class="cellrowborder" valign="top" width="42.71%" headers="mcps1.2.3.1.2 "><p id="p148761512312"><a name="p148761512312"></a><a name="p148761512312"></a>Obtains the version ID.</p>
</td>
</tr>
<tr id="row18749712234"><td class="cellrowborder" valign="top" width="57.29%" headers="mcps1.2.3.1.1 "><p id="p10749912738"><a name="p10749912738"></a><a name="p10749912738"></a>const char* GetBuildType(void)</p>
</td>
<td class="cellrowborder" valign="top" width="42.71%" headers="mcps1.2.3.1.2 "><p id="p67491212437"><a name="p67491212437"></a><a name="p67491212437"></a>Obtains the build type.</p>
</td>
</tr>
<tr id="row178451710639"><td class="cellrowborder" valign="top" width="57.29%" headers="mcps1.2.3.1.1 "><p id="p58461810136"><a name="p58461810136"></a><a name="p58461810136"></a>const char* GetBuildUser(void)</p>
</td>
<td class="cellrowborder" valign="top" width="42.71%" headers="mcps1.2.3.1.2 "><p id="p178466109315"><a name="p178466109315"></a><a name="p178466109315"></a>Obtains the build account user name.</p>
</td>
</tr>
<tr id="row126721685315"><td class="cellrowborder" valign="top" width="57.29%" headers="mcps1.2.3.1.1 "><p id="p9673781832"><a name="p9673781832"></a><a name="p9673781832"></a>const char* GetBuildHost(void)</p>
</td>
<td class="cellrowborder" valign="top" width="42.71%" headers="mcps1.2.3.1.2 "><p id="p12673089315"><a name="p12673089315"></a><a name="p12673089315"></a>Obtains the build host name.</p>
</td>
</tr>
<tr id="row146494315815"><td class="cellrowborder" valign="top" width="57.29%" headers="mcps1.2.3.1.1 "><p id="p565184335811"><a name="p565184335811"></a><a name="p565184335811"></a>const char* GetBuildTime(void)</p>
</td>
<td class="cellrowborder" valign="top" width="42.71%" headers="mcps1.2.3.1.2 "><p id="p1466114365814"><a name="p1466114365814"></a><a name="p1466114365814"></a>Obtains the build time.</p>
</td>
</tr>
<tr id="row933265824817"><td class="cellrowborder" valign="top" width="57.29%" headers="mcps1.2.3.1.1 "><p id="p18200134111553"><a name="p18200134111553"></a><a name="p18200134111553"></a>const char* GetBuildRootHash(void)</p>
</td>
<td class="cellrowborder" valign="top" width="42.71%" headers="mcps1.2.3.1.2 "><p id="p7945171118466"><a name="p7945171118466"></a><a name="p7945171118466"></a>Obtains the buildroot hash value of this version.</p>
</td>
</tr>
<tr id="row9489179195318"><td class="cellrowborder" valign="top" width="57.29%" headers="mcps1.2.3.1.1 "><p id="p8489119105313"><a name="p8489119105313"></a><a name="p8489119105313"></a>const char* GetOsReleaseType(void)</p>
</td>
<td class="cellrowborder" valign="top" width="42.71%" headers="mcps1.2.3.1.2 "><p id="p1510173425513"><a name="p1510173425513"></a><a name="p1510173425513"></a>Obtains the system release type.</p>
</td>
</tr>
<tr id="row39251243533"><td class="cellrowborder" valign="top" width="57.29%" headers="mcps1.2.3.1.1 "><p id="p119261643535"><a name="p119261643535"></a><a name="p119261643535"></a>int GetDevUdid(char *udid, int size)</p>
</td>
<td class="cellrowborder" valign="top" width="42.71%" headers="mcps1.2.3.1.2 "><p id="p1292654125319"><a name="p1292654125319"></a><a name="p1292654125319"></a>Obtains the device identifier (UDID).</p>
</td>
</tr>
</tbody>
</table>

## How to Use<a name="section118404913233"></a>

The following is an example of using syspara.

```
// set && get
char key1[] = "rw.sys.version";
char value1[] = "10.1.0";
int ret = SetParameter(key1, value1);
char valueGet1[128] = {0};
ret = GetParameter(key1, "version=10.1.0", valueGet1, 128);

// get sysparm
char* value1 = GetDeviceType();
printf("Product type =%s\n", value1);
free(value1);
char* value2 = GetManufacture();
printf("Manufacture =%s\n", value2);
free(value2);
char* value3 = GetBrand();
printf("GetBrand =%s\n", value3);
free(value3);
char* value4 = GetMarketName();
printf("MarketName =%s\n", value4);
free(value4);
char* value5 = GetProductSeries();
printf("ProductSeries =%s\n", value5);
free(value5);
char* value6 = GetProductModel();
printf("ProductModel =%s\n", value6);
free(value6);
char* value7 = GetSoftwareModel();
printf("SoftwareModel =%s\n", value7);
free(value7);
char* value8 = GetHardwareModel();
printf("HardwareModel =%s\n", value8);
free(value8);
char* value9 = GetHardwareProfile();
printf("Software profile =%s\n", value9);
free(value9);
char* value10 = GetSerial();
printf("Serial =%s\n", value10);
free(value10);
char* value11 = GetOSFullName();
printf("OS name =%s\n", value11);
free(value11);
char* value12 = GetDisplayVersion();
printf("Display version =%s\n", value12);
free(value12);
char* value13 = GetBootloaderVersion();
printf("bootloader version =%s\n", value13);
free(value13);
char* value14 = GetSecurityPatchTag();
printf("secure patch level =%s\n", value14);
free(value14);
char* value15 = GetAbiList();
printf("abi list =%s\n", value15);
free(value15);
int value16 = GetFirstApiVersion();
printf("first api level =%d\n", value16);
free(value16);
char* value17 = GetIncrementalVersion();
printf("Incremental version = %s\n", value17);
free(value17);
char* value18 = GetVersionId();
printf("formal id =%s\n", value18);
free(value18);
char* value19 = GetBuildType();
printf("build type =%s\n", value19);
free(value19);
char* value20 = GetBuildUser();
printf("build user =%s\n", value20);
free(value20);
char* value21 = GetBuildHost();
printf("Build host = %s\n", value21);
free(value21);
char* value22 = GetBuildTime();
printf("build time =%s\n", value22);
free(value22);
char* value23 = GetBuildRootHash();
printf("build root later..., %s\n", value23);
free(value23);
char* value24 = GetOsReleaseType();
printf("OS release type =%s\n", value24);
free(value24);
char* value25 = GetOsReleaseType();
printf("OS release type =%s\n", value25);
free(value25);
char value26[65] = {0};
GetDevUdid(value26, 65);
printf("device udid =%s\n", value26);
free(value26);
```

