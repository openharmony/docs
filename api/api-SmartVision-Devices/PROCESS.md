# PROCESS<a name="ZH-CN_TOPIC_0000001055387978"></a>

-   [Overview](#section2028654109165622)
-   [Summary](#section1425157668165622)
-   [Files](#files)
-   [Data Structures](#nested-classes)
-   [Macros](#define-members)
-   [Typedefs](#typedef-members)
-   [Functions](#func-members)
-   [Details](#section2053292651165622)
-   [Function](#section1655463262165622)
-   [capget\(\)](#gaa284eba1654e9fc0672aca2a6d2cd0ce)
-   [capset\(\)](#gaaa15be01b20aff9efb09de5a8ead207e)
-   [getpriority\(\)](#gac2ee4921a8961060b4c7fcad8bf2b4e2)
-   [ohos\_capget\(\)](#gaf254b29504e9733ff55014acdf5fbcc7)
-   [ohos\_capset\(\)](#ga77ad7758babf522e7ffb28551332a659)
-   [pthread\_atfork\(\)](#ga80008474c3d68e9880da960a53d2f430)
-   [pthread\_attr\_destroy\(\)](#ga4bcdbf47c17c7dcc51e9f05f5cb56d81)
-   [pthread\_attr\_getdetachstate\(\)](#ga391c34da42e68ddd24f5ee0c070d5c4f)
-   [pthread\_attr\_getguardsize\(\)](#gaa8b692ecc3880fdd49a4d423ba1ce91e)
-   [pthread\_attr\_getinheritsched\(\)](#ga79a77b688c30213e5e52e6be178cde4e)
-   [pthread\_attr\_getschedparam\(\)](#gafd3d272d702481044f8a8cd253fd9b47)
-   [pthread\_attr\_getschedpolicy\(\)](#gaec4d8127833d1a573aa82539f898a8ed)
-   [pthread\_attr\_getscope\(\)](#gabfd252cd45081231018030e3878efa06)
-   [pthread\_attr\_getstack\(\)](#gaec19ad460995a9fe8aeb4eaf2bb1ed1d)
-   [pthread\_attr\_getstacksize\(\)](#gae23600d4670359ab12bfba20db2c9a37)
-   [pthread\_attr\_init\(\)](#ga0b85ebb1e3aac081a4c0a5e85ae3cbe9)
-   [pthread\_attr\_setdetachstate\(\)](#gae6ee78c307d8467b34a9b0c330993a54)
-   [pthread\_attr\_setguardsize\(\)](#ga532b31c11a9d87663053c5342400758c)
-   [pthread\_attr\_setinheritsched\(\)](#gad437fe8caa3ef9f0cb7d69f6f6479df9)
-   [pthread\_attr\_setschedparam\(\)](#ga579e6529f0ce482312a5e77ac61cb4d5)
-   [pthread\_attr\_setschedpolicy\(\)](#gab6cb2eb73f04abf328b2f39777c35dca)
-   [pthread\_attr\_setscope\(\)](#ga294aaacf59f34effeef978242cf08cbe)
-   [pthread\_attr\_setstack\(\)](#ga94ede89b99a3a4fa17e516d30aaf3409)
-   [pthread\_attr\_setstacksize\(\)](#ga812a9a455ae2ef2bb0dca4fff201a281)
-   [pthread\_barrier\_destroy\(\)](#gab05ae13769e61dea9c53ca7894743c8f)
-   [pthread\_barrier\_init\(\)](#ga4a324cd758cae702213ea41882f4cf41)
-   [pthread\_barrier\_wait\(\)](#gaf786372165ba080986ae4143928c5436)
-   [pthread\_barrierattr\_destroy\(\)](#ga3bd99d89e352ccc51d5b94d157f1218b)
-   [pthread\_barrierattr\_init\(\)](#ga2ff720e06488668dc0ae6779755946e6)
-   [pthread\_cancel\(\)](#ga9e77a80c073787bf9a593e9c619dce27)
-   [pthread\_cleanup\_pop\(\)](#gafbe33fb00cd24693796a0870a3374631)
-   [pthread\_cleanup\_push\(\)](#ga68bc26522daf418f3cc78360925374ef)
-   [pthread\_cond\_broadcast\(\)](#ga1c1ac7c8faaf8ad63e12bc3717f430f3)
-   [pthread\_cond\_destroy\(\)](#ga7f2a7328ee3a7743686adcd2d51771c4)
-   [pthread\_cond\_init\(\)](#gabdf02ed57b055f1920991e96e7d67043)
-   [pthread\_cond\_signal\(\)](#ga9b0f2c7dead8c628e081d76c86a1addc)
-   [pthread\_cond\_timedwait\(\)](#ga506c0350d597721ab24bba7129e8e0df)
-   [pthread\_cond\_wait\(\)](#gaea601b8ce596a5c54fb12758c56b10a1)
-   [pthread\_condattr\_destroy\(\)](#ga8ab009937339c899a5197eea2e48e6a1)
-   [pthread\_condattr\_getclock\(\)](#gadcf908971c2ea15ced780025772084e3)
-   [pthread\_condattr\_init\(\)](#ga487a919ab54fd47c8464507031957df0)
-   [pthread\_condattr\_setclock\(\)](#gaaf7ac0f85233c0effaf850a9c65b6d68)
-   [pthread\_create\(\)](#gae5d18438d4d20c8a2e42cd2500578d79)
-   [pthread\_detach\(\)](#ga7c275c509c26566b6dd95a2de1668a2f)
-   [pthread\_equal\(\)](#ga98ec817164a6641eda2341de473b659d)
-   [pthread\_exit\(\)](#gaadfb4e5de5a20880c6a40d4e73ce2597)
-   [pthread\_getaffinity\_np\(\)](#ga051df55ea1131f70f6f9356865a36798)
-   [pthread\_getattr\_np\(\)](#ga6bdca4b2c8a436c4651fb5e8d462408b)
-   [pthread\_getschedparam\(\)](#gaae9850b3759769c748727e171c4c6e61)
-   [pthread\_getspecific\(\)](#ga31469375891078185bda93f0e4411a2c)
-   [pthread\_join\(\)](#ga28a15bba47cab57cbc9f5dac9af99c8b)
-   [pthread\_key\_create\(\)](#gaf4b7ced8ecff505380fe8216244a3764)
-   [pthread\_key\_delete\(\)](#gaee96306dc79294927ee840bb4de2244b)
-   [pthread\_kill\(\)](#ga5aafacc071cdfafd0eb992004dee3e62)
-   [pthread\_mutex\_destroy\(\)](#gaf89d9cfa300f33b46720a96eac83d175)
-   [pthread\_mutex\_init\(\)](#gadd99221596e95a55f70c59c1c712bbde)
-   [pthread\_mutex\_lock\(\)](#gafd70d6f2c50e22b996c926fb9d6ad291)
-   [pthread\_mutex\_timedlock\(\)](#gabc6a044b418e942b91121b1babb61708)
-   [pthread\_mutex\_trylock\(\)](#gacc1ccbaf3d76572da85a8030bba1ede4)
-   [pthread\_mutex\_unlock\(\)](#ga02a3c64dac70730e226c31c0e7dbb45c)
-   [pthread\_mutexattr\_destroy\(\)](#ga2321aabf58224b06021185708d0f9658)
-   [pthread\_mutexattr\_gettype\(\)](#ga4789e2d3ada7aab2af1458bfec53ee3c)
-   [pthread\_mutexattr\_init\(\)](#gaf98f6b6c483077a39d1400b1de1577b8)
-   [pthread\_mutexattr\_settype\(\)](#ga8387c80e660e9426f801ac0217ecfae5)
-   [pthread\_once\(\)](#ga196103ac97710dad7a93fd6c188cc999)
-   [pthread\_rwlock\_destroy\(\)](#gaa106bb55bdd0e120519d5412823f8b29)
-   [pthread\_rwlock\_init\(\)](#ga1cf4bc49696c1a30db31219aef994401)
-   [pthread\_rwlock\_rdlock\(\)](#ga6153aca32112735053e6cc4a2a290feb)
-   [pthread\_rwlock\_timedrdlock\(\)](#ga8edbe14731fd79a80f72384334266715)
-   [pthread\_rwlock\_timedwrlock\(\)](#ga3fb8fb33e16653c5ad7b7f092959738e)
-   [pthread\_rwlock\_tryrdlock\(\)](#ga3ba2170f06184d12543c4a5b78715fa7)
-   [pthread\_rwlock\_trywrlock\(\)](#ga2b5044e2da304ae9666fdd4e05479905)
-   [pthread\_rwlock\_unlock\(\)](#gaffd8a19e83fc87d865d103d6fbce8c4f)
-   [pthread\_rwlock\_wrlock\(\)](#gaf2ca5563676ae3ac35d3bc7b3547e7f7)
-   [pthread\_rwlockattr\_destroy\(\)](#ga78a54e67f0afe2601dbda0a904fa0bdf)
-   [pthread\_rwlockattr\_init\(\)](#ga9d831af0179ed16d1b6cbeba0304810b)
-   [pthread\_self\(\)](#ga4c4f5f3b4f8f45d9d897847d53b11aaa)
-   [pthread\_setaffinity\_np\(\)](#ga217f60f9431c453c74b675e72bba307d)
-   [pthread\_setcancelstate\(\)](#ga37075410fbbaad7ee93c95375fc86e0e)
-   [pthread\_setcanceltype\(\)](#gaab579bcfcf0662a0c1e35fd82162e61d)
-   [pthread\_setname\_np\(\)](#ga185584d77295432838d8b839d916f160)
-   [pthread\_setschedparam\(\)](#ga14f50e1f5d815c90f1f4225eca5d3a8c)
-   [pthread\_setschedprio\(\)](#ga7a23cbcfc21a4e3edf531ed65f022370)
-   [pthread\_setspecific\(\)](#ga2187333dd46ce08d9d2e044f79fad705)
-   [pthread\_spin\_destroy\(\)](#ga822c2ff425ddad4c25b6a6092c6effff)
-   [pthread\_spin\_init\(\)](#ga665a56a7bed60c8eaa6c28af40d13cd4)
-   [pthread\_spin\_lock\(\)](#ga62cfd14d1f937a6e8f966e3a331bcf94)
-   [pthread\_spin\_trylock\(\)](#ga084834fa2d06f173f086ce23ec1ea5d9)
-   [pthread\_spin\_unlock\(\)](#ga3fe246007a85cee9d5f7af9b7d592b54)
-   [pthread\_testcancel\(\)](#gaf1c95282ab2bea25f0888a19652cd41f)
-   [sched\_get\_priority\_max\(\)](#gafaebd1698caeb9b9b9e614ad84edd609)
-   [sched\_get\_priority\_min\(\)](#gaf1f370fc36ea6b22ed42b5ee3cf82a81)
-   [sched\_getparam\(\)](#ga563c7ac53bac2c1b51379147e66c44ec)
-   [sched\_getscheduler\(\)](#ga99fcb2532b1482d236dc04495a3f194d)
-   [sched\_rr\_get\_interval\(\)](#ga484f0eb93529d29a66e24485725c4c7b)
-   [sched\_setparam\(\)](#ga06b497c4ea6bbabd2b62ba1a8a848a1b)
-   [sched\_setscheduler\(\)](#ga84ad29a6f2ad27370df09c664ac65eac)
-   [sched\_yield\(\)](#ga357cd4b34c13011749dfffb42b489f09)
-   [setpriority\(\)](#ga0a8d4c8043a7748c25dd551dc69dcad2)
-   [wait\(\)](#gabf2fbcf6df59fd5234e9eed4db1a1804)
-   [waitpid\(\)](#ga77de8005691d1f125540d66032a3cc62)
-   [Variable](#section1588843235165622)
-   [effective](#ga355bca6f4ddbe05cb7225ce1d7272ddd)
-   [inheritable](#ga22c2f1389233789296db2b270b98b79a)
-   [permitted](#ga39e42efd1f293a6c8cd0227cff1e7bb8)
-   [pid](#ga7d063c33a2986f7351ce84e033e63765)
-   [version](#ga75de99b99ceca627d834db0db344b609)

## **Overview**<a name="section2028654109165622"></a>

**Description:**

Provides process- and thread-related structures and functions. 

You can perform process- and thread-related operations, including creating and terminating a process, obtaining a process ID, creating or destroying a thread, and obtaining or modifying thread attributes, priorities, and scheduling policies.

**Since:**

1.0

**Version:**

1.0

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1425157668165622"></a>

## Files<a name="files"></a>

<a name="table1688332408165622"></a>
<table><thead align="left"><tr id="row1679736264165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1325277219165622"><a name="p1325277219165622"></a><a name="p1325277219165622"></a>File Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1586235710165622"><a name="p1586235710165622"></a><a name="p1586235710165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2028372000165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1106853289165622"><a name="p1106853289165622"></a><a name="p1106853289165622"></a><a href="pthread-h.md">pthread.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1816527276165622"><a name="p1816527276165622"></a><a name="p1816527276165622"></a>Provides process- and thread-related structures (providing fields such as thread attributes) and functions (including the functions for creating and destroying threads, and setting the thread detach state and blocking conditions). </p>
</td>
</tr>
<tr id="row2076488512165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p274269875165622"><a name="p274269875165622"></a><a name="p274269875165622"></a><a href="sched-h.md">sched.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p663929156165622"><a name="p663929156165622"></a><a name="p663929156165622"></a>Provides process- and thread-related structures and functions (for example, obtaining scheduling policies and parameters). </p>
</td>
</tr>
<tr id="row2117608726165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p18727739165622"><a name="p18727739165622"></a><a name="p18727739165622"></a><a href="capability-h.md">capability.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p302157384165622"><a name="p302157384165622"></a><a name="p302157384165622"></a>Declares functions and related data structures for obtaining and setting process capabilities. </p>
</td>
</tr>
<tr id="row1368736997165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1724732853165622"><a name="p1724732853165622"></a><a name="p1724732853165622"></a><a href="resource-h.md">resource.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p503482512165622"><a name="p503482512165622"></a><a name="p503482512165622"></a>Declares process-related structures and functions. </p>
</td>
</tr>
<tr id="row727480094165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1126226026165622"><a name="p1126226026165622"></a><a name="p1126226026165622"></a><a href="wait-h.md">wait.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1793967698165622"><a name="p1793967698165622"></a><a name="p1793967698165622"></a>Provides process- and thread-related structures and functions (for example, waiting for child processes to end and reclaiming resources). </p>
</td>
</tr>
</tbody>
</table>

## Data Structures<a name="nested-classes"></a>

<a name="table1412491855165622"></a>
<table><thead align="left"><tr id="row1175866956165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p750308105165622"><a name="p750308105165622"></a><a name="p750308105165622"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1726334780165622"><a name="p1726334780165622"></a><a name="p1726334780165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2052545632165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1134459643165622"><a name="p1134459643165622"></a><a name="p1134459643165622"></a><a href="sched_param.md">sched_param</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p547139508165622"><a name="p547139508165622"></a><a name="p547139508165622"></a>Defines process scheduling parameters. </p>
</td>
</tr>
<tr id="row1202800928165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p956120169165622"><a name="p956120169165622"></a><a name="p956120169165622"></a><a href="__user_cap_header_struct.md">__user_cap_header_struct</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1631766405165622"><a name="p1631766405165622"></a><a name="p1631766405165622"></a>Defines the user capability header. </p>
</td>
</tr>
<tr id="row30600976165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p727173041165622"><a name="p727173041165622"></a><a name="p727173041165622"></a><a href="__user_cap_data_struct.md">__user_cap_data_struct</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p770123611165622"><a name="p770123611165622"></a><a name="p770123611165622"></a>Defines user capability data. </p>
</td>
</tr>
</tbody>
</table>

## Macros<a name="define-members"></a>

<a name="table1578215862165622"></a>
<table><thead align="left"><tr id="row592113375165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p677133368165622"><a name="p677133368165622"></a><a name="p677133368165622"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2096366972165622"><a name="p2096366972165622"></a><a name="p2096366972165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row7842298165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1796909758165622"><a name="p1796909758165622"></a><a name="p1796909758165622"></a><em id="ga3da61b7092bd6eba9742619ed47fc554"><a name="ga3da61b7092bd6eba9742619ed47fc554"></a><a name="ga3da61b7092bd6eba9742619ed47fc554"></a></em>CAP_CHOWN    0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1111966568165622"><a name="p1111966568165622"></a><a name="p1111966568165622"></a>Indicates the capability of changing the file ownership. </p>
</td>
</tr>
<tr id="row1432358429165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1676951331165622"><a name="p1676951331165622"></a><a name="p1676951331165622"></a><em id="gad9000e5b8b0ccb4c7639a6c79206ab84"><a name="gad9000e5b8b0ccb4c7639a6c79206ab84"></a><a name="gad9000e5b8b0ccb4c7639a6c79206ab84"></a></em>CAP_DAC_OVERRIDE    1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p692506487165622"><a name="p692506487165622"></a><a name="p692506487165622"></a>Indicates the capability of ignoring discretionary access control (DAC) restrictions on files. </p>
</td>
</tr>
<tr id="row1407758361165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1747406702165622"><a name="p1747406702165622"></a><a name="p1747406702165622"></a><em id="ga852b6d011b35fc4a9440afab60818e7f"><a name="ga852b6d011b35fc4a9440afab60818e7f"></a><a name="ga852b6d011b35fc4a9440afab60818e7f"></a></em>CAP_DAC_READ_SEARCH    2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p356259682165622"><a name="p356259682165622"></a><a name="p356259682165622"></a>Indicates the capability of ignoring DAC restrictions on file read and search. </p>
</td>
</tr>
<tr id="row1932082709165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1390093409165622"><a name="p1390093409165622"></a><a name="p1390093409165622"></a><em id="ga5b98c4f060e4f89c9188d54eae2b1089"><a name="ga5b98c4f060e4f89c9188d54eae2b1089"></a><a name="ga5b98c4f060e4f89c9188d54eae2b1089"></a></em>CAP_FOWNER    3</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p350748107165622"><a name="p350748107165622"></a><a name="p350748107165622"></a>Indicates the capability of ignoring the restrictions on the matching between the user ID of the file owner and process ID. </p>
</td>
</tr>
<tr id="row873978200165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p567029511165622"><a name="p567029511165622"></a><a name="p567029511165622"></a><em id="ga2c299b6690bebc22f1b17faf8e003d74"><a name="ga2c299b6690bebc22f1b17faf8e003d74"></a><a name="ga2c299b6690bebc22f1b17faf8e003d74"></a></em>CAP_KILL    5</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1296822102165622"><a name="p1296822102165622"></a><a name="p1296822102165622"></a>Indicates the capability of ignoring the restrictions on sending signals to processes that do not belong to themselves. </p>
</td>
</tr>
<tr id="row2037632751165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p477604662165622"><a name="p477604662165622"></a><a name="p477604662165622"></a><em id="ga0d81450d3ead5e1b5eff72be7c5c85ea"><a name="ga0d81450d3ead5e1b5eff72be7c5c85ea"></a><a name="ga0d81450d3ead5e1b5eff72be7c5c85ea"></a></em>CAP_SETGID    6</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2021466512165622"><a name="p2021466512165622"></a><a name="p2021466512165622"></a>Indicates the capability of changing the group ID of a process. </p>
</td>
</tr>
<tr id="row48266975165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1523007170165622"><a name="p1523007170165622"></a><a name="p1523007170165622"></a><em id="ga3f7c3cf791b090c9e3dcff1a024301af"><a name="ga3f7c3cf791b090c9e3dcff1a024301af"></a><a name="ga3f7c3cf791b090c9e3dcff1a024301af"></a></em>CAP_SETUID    7</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1564881926165622"><a name="p1564881926165622"></a><a name="p1564881926165622"></a>Indicates the capability of changing the user ID of a process. </p>
</td>
</tr>
<tr id="row1621480971165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p323337888165622"><a name="p323337888165622"></a><a name="p323337888165622"></a><em id="gaf5f1284e7085a795e1af8304f97bd41c"><a name="gaf5f1284e7085a795e1af8304f97bd41c"></a><a name="gaf5f1284e7085a795e1af8304f97bd41c"></a></em>CAP_SETPCAP    8</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p643741788165622"><a name="p643741788165622"></a><a name="p643741788165622"></a>Indicates the capability of transferring capabilities to other processes and deleting capabilities. </p>
</td>
</tr>
<tr id="row882416704165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2058404933165622"><a name="p2058404933165622"></a><a name="p2058404933165622"></a><em id="ga0e2799d4126fb5265cdf89deb094d641"><a name="ga0e2799d4126fb5265cdf89deb094d641"></a><a name="ga0e2799d4126fb5265cdf89deb094d641"></a></em>CAP_NET_BIND_SERVICE    10</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p310851229165622"><a name="p310851229165622"></a><a name="p310851229165622"></a>Indicates the capability of binding a port. </p>
</td>
</tr>
<tr id="row903062973165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p984188806165622"><a name="p984188806165622"></a><a name="p984188806165622"></a><em id="ga8ed3167af6b08f73c71e1d97c094fd7b"><a name="ga8ed3167af6b08f73c71e1d97c094fd7b"></a><a name="ga8ed3167af6b08f73c71e1d97c094fd7b"></a></em>CAP_NET_BROADCAST    11</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1235490070165622"><a name="p1235490070165622"></a><a name="p1235490070165622"></a>Indicates the capability of network broadcasting or multicasting. </p>
</td>
</tr>
<tr id="row1417480096165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1004480332165622"><a name="p1004480332165622"></a><a name="p1004480332165622"></a><em id="gab0effe6e11720ce4c4821b6228c1aa77"><a name="gab0effe6e11720ce4c4821b6228c1aa77"></a><a name="gab0effe6e11720ce4c4821b6228c1aa77"></a></em>CAP_NET_ADMIN    12</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p568556864165622"><a name="p568556864165622"></a><a name="p568556864165622"></a>Indicates the capability of executing network management tasks. </p>
</td>
</tr>
<tr id="row2141567985165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p9326983165622"><a name="p9326983165622"></a><a name="p9326983165622"></a><em id="gab8562849ab09873a8764f4b3f29e445b"><a name="gab8562849ab09873a8764f4b3f29e445b"></a><a name="gab8562849ab09873a8764f4b3f29e445b"></a></em>CAP_NET_RAW    13</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p373799814165622"><a name="p373799814165622"></a><a name="p373799814165622"></a>Indicates the capability of using raw sockets. </p>
</td>
</tr>
<tr id="row114591492165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2012114970165622"><a name="p2012114970165622"></a><a name="p2012114970165622"></a><em id="ga2e789746fd07a8ec20095a832406c1dd"><a name="ga2e789746fd07a8ec20095a832406c1dd"></a><a name="ga2e789746fd07a8ec20095a832406c1dd"></a></em>CAP_SYS_PTRACE    19</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1933047574165622"><a name="p1933047574165622"></a><a name="p1933047574165622"></a>Indicates the capability of tracing any process. </p>
</td>
</tr>
<tr id="row596568865165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1907677431165622"><a name="p1907677431165622"></a><a name="p1907677431165622"></a><em id="gac2e0e57ff2c1f83a912b449da79e2e31"><a name="gac2e0e57ff2c1f83a912b449da79e2e31"></a><a name="gac2e0e57ff2c1f83a912b449da79e2e31"></a></em>CAP_SYS_ADMIN    21</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1176122528165622"><a name="p1176122528165622"></a><a name="p1176122528165622"></a>Indicates the capability of executing system management tasks. </p>
</td>
</tr>
<tr id="row196219554165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2095887885165622"><a name="p2095887885165622"></a><a name="p2095887885165622"></a><em id="ga2f1e1c5d163162c7003c8e5df2ff1e8d"><a name="ga2f1e1c5d163162c7003c8e5df2ff1e8d"></a><a name="ga2f1e1c5d163162c7003c8e5df2ff1e8d"></a></em>CAP_SYS_BOOT    22</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1199740052165622"><a name="p1199740052165622"></a><a name="p1199740052165622"></a>Indicates the capability of rebooting system. </p>
</td>
</tr>
<tr id="row1038503331165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p148806960165622"><a name="p148806960165622"></a><a name="p148806960165622"></a><em id="gac1f5d5cc7fecda8ab88019a5a1d6dd08"><a name="gac1f5d5cc7fecda8ab88019a5a1d6dd08"></a><a name="gac1f5d5cc7fecda8ab88019a5a1d6dd08"></a></em>CAP_SYS_NICE    23</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1802595801165622"><a name="p1802595801165622"></a><a name="p1802595801165622"></a>Indicates the capability of setting the priority. </p>
</td>
</tr>
<tr id="row1119144654165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1729898326165622"><a name="p1729898326165622"></a><a name="p1729898326165622"></a><em id="ga1dab8ee99a12ffcddc5fe17c31df2726"><a name="ga1dab8ee99a12ffcddc5fe17c31df2726"></a><a name="ga1dab8ee99a12ffcddc5fe17c31df2726"></a></em>CAP_SYS_TIME    25</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1639631480165622"><a name="p1639631480165622"></a><a name="p1639631480165622"></a>Indicates the capability of changing the system clock. </p>
</td>
</tr>
<tr id="row934407669165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p888905704165622"><a name="p888905704165622"></a><a name="p888905704165622"></a><em id="ga032cd8eaf96d91bca567c7938f8c2b3e"><a name="ga032cd8eaf96d91bca567c7938f8c2b3e"></a><a name="ga032cd8eaf96d91bca567c7938f8c2b3e"></a></em>OHOS_CAP_CHOWN    0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1376447894165622"><a name="p1376447894165622"></a><a name="p1376447894165622"></a>Indicates the capability of changing the file ownership. This macro is used by <a href="PROCESS.md#ga77ad7758babf522e7ffb28551332a659">ohos_capset</a>. </p>
</td>
</tr>
<tr id="row2086850209165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1657135111165622"><a name="p1657135111165622"></a><a name="p1657135111165622"></a><em id="gae473b71e022f789afd73d33e1feadb0f"><a name="gae473b71e022f789afd73d33e1feadb0f"></a><a name="gae473b71e022f789afd73d33e1feadb0f"></a></em>OHOS_CAP_DAC_EXECUTE    1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1874383596165622"><a name="p1874383596165622"></a><a name="p1874383596165622"></a>Indicates the capability of ignoring DAC restrictions on file execution. This macro is used by <a href="PROCESS.md#ga77ad7758babf522e7ffb28551332a659">ohos_capset</a>. </p>
</td>
</tr>
<tr id="row1179387116165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p510658699165622"><a name="p510658699165622"></a><a name="p510658699165622"></a><em id="ga99c916fddf88ab0dd4ec935714e2f496"><a name="ga99c916fddf88ab0dd4ec935714e2f496"></a><a name="ga99c916fddf88ab0dd4ec935714e2f496"></a></em>OHOS_CAP_DAC_WRITE    2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p203636628165622"><a name="p203636628165622"></a><a name="p203636628165622"></a>Indicates the capability of ignoring DAC restrictions on file write. This macro is used by <a href="PROCESS.md#ga77ad7758babf522e7ffb28551332a659">ohos_capset</a>. </p>
</td>
</tr>
<tr id="row194985016165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p412500505165622"><a name="p412500505165622"></a><a name="p412500505165622"></a><em id="ga374aed9e2e2e95a9c08dd14cae04d278"><a name="ga374aed9e2e2e95a9c08dd14cae04d278"></a><a name="ga374aed9e2e2e95a9c08dd14cae04d278"></a></em>OHOS_CAP_DAC_READ_SEARCH    3</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p932210345165622"><a name="p932210345165622"></a><a name="p932210345165622"></a>Indicates the capability of ignoring DAC restrictions on file read and search. This macro is used by <a href="PROCESS.md#ga77ad7758babf522e7ffb28551332a659">ohos_capset</a>. </p>
</td>
</tr>
<tr id="row71862077165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p157434080165622"><a name="p157434080165622"></a><a name="p157434080165622"></a><em id="gad07da2d2d65ce1df68cb580ed7a2a2ec"><a name="gad07da2d2d65ce1df68cb580ed7a2a2ec"></a><a name="gad07da2d2d65ce1df68cb580ed7a2a2ec"></a></em>OHOS_CAP_FOWNER    4</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p8271457165622"><a name="p8271457165622"></a><a name="p8271457165622"></a>Indicates the capability of ignoring the restrictions on the matching between the user ID of the file owner and process ID. This macro is used by <a href="PROCESS.md#ga77ad7758babf522e7ffb28551332a659">ohos_capset</a>. </p>
</td>
</tr>
<tr id="row1749530310165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p118733186165622"><a name="p118733186165622"></a><a name="p118733186165622"></a><em id="ga54cb89e233d122cd843423a638b5dc93"><a name="ga54cb89e233d122cd843423a638b5dc93"></a><a name="ga54cb89e233d122cd843423a638b5dc93"></a></em>OHOS_CAP_KILL    5</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p382946821165622"><a name="p382946821165622"></a><a name="p382946821165622"></a>Indicates the capability of ignoring the restrictions on sending signals to processes that do not belong to themselves. This macro is used by <a href="PROCESS.md#ga77ad7758babf522e7ffb28551332a659">ohos_capset</a>. </p>
</td>
</tr>
<tr id="row1642078200165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1752703993165622"><a name="p1752703993165622"></a><a name="p1752703993165622"></a><em id="ga371a19d3b06310544131d2141d5a6839"><a name="ga371a19d3b06310544131d2141d5a6839"></a><a name="ga371a19d3b06310544131d2141d5a6839"></a></em>OHOS_CAP_SETGID    6</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p289425578165622"><a name="p289425578165622"></a><a name="p289425578165622"></a>Indicates the capability of changing the group ID of a process. This macro is used by <a href="PROCESS.md#ga77ad7758babf522e7ffb28551332a659">ohos_capset</a>. </p>
</td>
</tr>
<tr id="row1948174198165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1453760765165622"><a name="p1453760765165622"></a><a name="p1453760765165622"></a><em id="ga90185cea91d0d291c11e141becf43450"><a name="ga90185cea91d0d291c11e141becf43450"></a><a name="ga90185cea91d0d291c11e141becf43450"></a></em>OHOS_CAP_SETUID    7</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2006182584165622"><a name="p2006182584165622"></a><a name="p2006182584165622"></a>Indicates the capability of changing the user ID of a process. This macro is used by <a href="PROCESS.md#ga77ad7758babf522e7ffb28551332a659">ohos_capset</a>. </p>
</td>
</tr>
<tr id="row296201023165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p44033000165622"><a name="p44033000165622"></a><a name="p44033000165622"></a><em id="ga560a6ed84e6d4e4b7589c8c706f60640"><a name="ga560a6ed84e6d4e4b7589c8c706f60640"></a><a name="ga560a6ed84e6d4e4b7589c8c706f60640"></a></em>OHOS_CAP_NET_BIND_SERVICE    8</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1490450862165622"><a name="p1490450862165622"></a><a name="p1490450862165622"></a>Indicates the capability of binding a port. This macro is used by <a href="PROCESS.md#ga77ad7758babf522e7ffb28551332a659">ohos_capset</a>. </p>
</td>
</tr>
<tr id="row435837435165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1388999221165622"><a name="p1388999221165622"></a><a name="p1388999221165622"></a><em id="ga807a12c78fd7702925c04df3fd8a9cbb"><a name="ga807a12c78fd7702925c04df3fd8a9cbb"></a><a name="ga807a12c78fd7702925c04df3fd8a9cbb"></a></em>OHOS_CAP_NET_BROADCAST    9</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1555751751165622"><a name="p1555751751165622"></a><a name="p1555751751165622"></a>Indicates the capability of network broadcasting or multicasting. This macro is used by <a href="PROCESS.md#ga77ad7758babf522e7ffb28551332a659">ohos_capset</a>. </p>
</td>
</tr>
<tr id="row1248250752165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p655489536165622"><a name="p655489536165622"></a><a name="p655489536165622"></a><em id="ga2d505755c54e0d2172ff5324ced29077"><a name="ga2d505755c54e0d2172ff5324ced29077"></a><a name="ga2d505755c54e0d2172ff5324ced29077"></a></em>OHOS_CAP_NET_ADMIN    10</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p288669231165622"><a name="p288669231165622"></a><a name="p288669231165622"></a>Indicates the capability of executing network management tasks. This macro is used by <a href="PROCESS.md#ga77ad7758babf522e7ffb28551332a659">ohos_capset</a>. </p>
</td>
</tr>
<tr id="row342863147165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1019650062165622"><a name="p1019650062165622"></a><a name="p1019650062165622"></a><em id="ga870f352726d87e7d1e543cbd7e1bce8d"><a name="ga870f352726d87e7d1e543cbd7e1bce8d"></a><a name="ga870f352726d87e7d1e543cbd7e1bce8d"></a></em>OHOS_CAP_NET_RAW    11</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1153831882165622"><a name="p1153831882165622"></a><a name="p1153831882165622"></a>Indicates the capability of using raw sockets. This macro is used by <a href="PROCESS.md#ga77ad7758babf522e7ffb28551332a659">ohos_capset</a>. </p>
</td>
</tr>
<tr id="row2030314591165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p842055080165622"><a name="p842055080165622"></a><a name="p842055080165622"></a><em id="ga9226dae5574b6386c87b0e6582560df9"><a name="ga9226dae5574b6386c87b0e6582560df9"></a><a name="ga9226dae5574b6386c87b0e6582560df9"></a></em>OHOS_CAP_FS_MOUNT    12</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1572299512165622"><a name="p1572299512165622"></a><a name="p1572299512165622"></a>Indicates the capability of mounting the file system. This macro is used by <a href="PROCESS.md#ga77ad7758babf522e7ffb28551332a659">ohos_capset</a>. </p>
</td>
</tr>
<tr id="row1204263246165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1374519717165622"><a name="p1374519717165622"></a><a name="p1374519717165622"></a><em id="ga5802143f3200cee5ecc1af6dbc5c3aa0"><a name="ga5802143f3200cee5ecc1af6dbc5c3aa0"></a><a name="ga5802143f3200cee5ecc1af6dbc5c3aa0"></a></em>OHOS_CAP_FS_FORMAT    13</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p82126134165622"><a name="p82126134165622"></a><a name="p82126134165622"></a>Indicates the capability of formatting the file system. This macro is used by <a href="PROCESS.md#ga77ad7758babf522e7ffb28551332a659">ohos_capset</a>. </p>
</td>
</tr>
<tr id="row555263591165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p218053816165622"><a name="p218053816165622"></a><a name="p218053816165622"></a><em id="ga65868d3c9629fc31f73678396aca3136"><a name="ga65868d3c9629fc31f73678396aca3136"></a><a name="ga65868d3c9629fc31f73678396aca3136"></a></em>OHOS_CAP_SCHED_SETPRIORITY    14</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p93628962165622"><a name="p93628962165622"></a><a name="p93628962165622"></a>Indicates the capability of setting the scheduling priority. This macro is used by <a href="PROCESS.md#ga77ad7758babf522e7ffb28551332a659">ohos_capset</a>. </p>
</td>
</tr>
<tr id="row1667221781165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1588578665165622"><a name="p1588578665165622"></a><a name="p1588578665165622"></a><em id="ga54901b8a0b89b410be9c846781b0a3ae"><a name="ga54901b8a0b89b410be9c846781b0a3ae"></a><a name="ga54901b8a0b89b410be9c846781b0a3ae"></a></em>OHOS_CAP_SET_TIMEOFDAY    15</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1052310616165622"><a name="p1052310616165622"></a><a name="p1052310616165622"></a>Indicates the capability of setting the date. This macro is used by <a href="PROCESS.md#ga77ad7758babf522e7ffb28551332a659">ohos_capset</a>. </p>
</td>
</tr>
<tr id="row687145934165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2095622687165622"><a name="p2095622687165622"></a><a name="p2095622687165622"></a><em id="ga880e395b85296d3e2561ec2fd1fe315b"><a name="ga880e395b85296d3e2561ec2fd1fe315b"></a><a name="ga880e395b85296d3e2561ec2fd1fe315b"></a></em>OHOS_CAP_CLOCK_SETTIME    16</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1001732184165622"><a name="p1001732184165622"></a><a name="p1001732184165622"></a>Indicates the capability of setting the clock. This macro is used by <a href="PROCESS.md#ga77ad7758babf522e7ffb28551332a659">ohos_capset</a>. </p>
</td>
</tr>
<tr id="row2140409981165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1277588741165622"><a name="p1277588741165622"></a><a name="p1277588741165622"></a><em id="gaaf53607491c593ba91afc8accc89574f"><a name="gaaf53607491c593ba91afc8accc89574f"></a><a name="gaaf53607491c593ba91afc8accc89574f"></a></em>OHOS_CAP_CAPSET    17</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1273633368165622"><a name="p1273633368165622"></a><a name="p1273633368165622"></a>Indicates the capability of setting the capabilities. This macro is used by <a href="PROCESS.md#ga77ad7758babf522e7ffb28551332a659">ohos_capset</a>. </p>
</td>
</tr>
<tr id="row986995669165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p957343689165622"><a name="p957343689165622"></a><a name="p957343689165622"></a><em id="gabc2e8c23ecf979bf3395d86a2d1eacfc"><a name="gabc2e8c23ecf979bf3395d86a2d1eacfc"></a><a name="gabc2e8c23ecf979bf3395d86a2d1eacfc"></a></em>OHOS_CAP_REBOOT    18</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1480062199165622"><a name="p1480062199165622"></a><a name="p1480062199165622"></a>Indicates the capability of rebooting system. This macro is used by <a href="PROCESS.md#ga77ad7758babf522e7ffb28551332a659">ohos_capset</a>. </p>
</td>
</tr>
<tr id="row12362711165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p612852843165622"><a name="p612852843165622"></a><a name="p612852843165622"></a><em id="gab4c5afb99569714f96f0bb05305ad0e7"><a name="gab4c5afb99569714f96f0bb05305ad0e7"></a><a name="gab4c5afb99569714f96f0bb05305ad0e7"></a></em>OHOS_CAP_SHELL_EXEC    19</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2037674639165622"><a name="p2037674639165622"></a><a name="p2037674639165622"></a>Indicates the capability of calling shell. This macro is used by <a href="PROCESS.md#ga77ad7758babf522e7ffb28551332a659">ohos_capset</a>. </p>
</td>
</tr>
<tr id="row954799916165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p294409551165622"><a name="p294409551165622"></a><a name="p294409551165622"></a><em id="ga5aab1c88012d4b577b034e9291e87419"><a name="ga5aab1c88012d4b577b034e9291e87419"></a><a name="ga5aab1c88012d4b577b034e9291e87419"></a></em>PRIO_PROCESS    0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p601871698165622"><a name="p601871698165622"></a><a name="p601871698165622"></a>Defines a process ID. </p>
</td>
</tr>
<tr id="row1385749002165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p161324469165622"><a name="p161324469165622"></a><a name="p161324469165622"></a><em id="ga9156ecb2854d071998278d63a107a215"><a name="ga9156ecb2854d071998278d63a107a215"></a><a name="ga9156ecb2854d071998278d63a107a215"></a></em>PRIO_PGRP    1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p543710277165622"><a name="p543710277165622"></a><a name="p543710277165622"></a>Defines a process group ID. </p>
</td>
</tr>
<tr id="row1392130697165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p499770920165622"><a name="p499770920165622"></a><a name="p499770920165622"></a><em id="gaee947842544cb755f74360d1da4aa193"><a name="gaee947842544cb755f74360d1da4aa193"></a><a name="gaee947842544cb755f74360d1da4aa193"></a></em>PRIO_USER    2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p368015419165622"><a name="p368015419165622"></a><a name="p368015419165622"></a>Defines a valid user ID. </p>
</td>
</tr>
</tbody>
</table>

## Typedefs<a name="typedef-members"></a>

<a name="table212241814165622"></a>
<table><thead align="left"><tr id="row219906878165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p736002074165622"><a name="p736002074165622"></a><a name="p736002074165622"></a>Typedef Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1757913714165622"><a name="p1757913714165622"></a><a name="p1757913714165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2105575087165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p784893022165622"><a name="p784893022165622"></a><a name="p784893022165622"></a>cap_user_header_t </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1828414750165622"><a name="p1828414750165622"></a><a name="p1828414750165622"></a><strong id="gaf042e68224162d4eb2ce7668904831d9"><a name="gaf042e68224162d4eb2ce7668904831d9"></a><a name="gaf042e68224162d4eb2ce7668904831d9"></a></strong> typedef struct <a href="__user_cap_header_struct.md">__user_cap_header_struct</a> * </p>
<p id="p321733377165622"><a name="p321733377165622"></a><a name="p321733377165622"></a>Defines the user capability header. </p>
</td>
</tr>
<tr id="row108384438165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p376494446165622"><a name="p376494446165622"></a><a name="p376494446165622"></a>cap_user_data_t </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p37825026165622"><a name="p37825026165622"></a><a name="p37825026165622"></a><strong id="gaafd3aaf8bb3f786614fee86c2fa93667"><a name="gaafd3aaf8bb3f786614fee86c2fa93667"></a><a name="gaafd3aaf8bb3f786614fee86c2fa93667"></a></strong> typedef struct <a href="__user_cap_data_struct.md">__user_cap_data_struct</a> * </p>
<p id="p1618168422165622"><a name="p1618168422165622"></a><a name="p1618168422165622"></a>Defines user capability data. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table701719796165622"></a>
<table><thead align="left"><tr id="row967907150165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p191487021165622"><a name="p191487021165622"></a><a name="p191487021165622"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2038388923165622"><a name="p2038388923165622"></a><a name="p2038388923165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1584203306165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1922155896165622"><a name="p1922155896165622"></a><a name="p1922155896165622"></a><a href="PROCESS.md#gae5d18438d4d20c8a2e42cd2500578d79">pthread_create</a> (<a href="UTILS.md#ga5250f47a8a0402a78bb51a2133e13c1f">pthread_t</a> *thread, const <a href="UTILS.md#gac8ee4471bbc35deb7589ac3615deb486">pthread_attr_t</a> *attr, void *(*start_routine)(void *), void *arg)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p13299565165622"><a name="p13299565165622"></a><a name="p13299565165622"></a>int </p>
<p id="p1420290435165622"><a name="p1420290435165622"></a><a name="p1420290435165622"></a>Creates a thread. </p>
</td>
</tr>
<tr id="row352770050165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p516280153165622"><a name="p516280153165622"></a><a name="p516280153165622"></a><a href="PROCESS.md#ga7c275c509c26566b6dd95a2de1668a2f">pthread_detach</a> (<a href="UTILS.md#ga5250f47a8a0402a78bb51a2133e13c1f">pthread_t</a> thread)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1436361808165622"><a name="p1436361808165622"></a><a name="p1436361808165622"></a>int </p>
<p id="p1258082455165622"><a name="p1258082455165622"></a><a name="p1258082455165622"></a>Detaches a thread. </p>
</td>
</tr>
<tr id="row1192833147165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p136036996165622"><a name="p136036996165622"></a><a name="p136036996165622"></a><a href="PROCESS.md#gaadfb4e5de5a20880c6a40d4e73ce2597">pthread_exit</a> (void *retval)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1735991194165622"><a name="p1735991194165622"></a><a name="p1735991194165622"></a>_Noreturn void </p>
<p id="p743041772165622"><a name="p743041772165622"></a><a name="p743041772165622"></a>Terminates the calling thread. </p>
</td>
</tr>
<tr id="row1000057617165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p933509019165622"><a name="p933509019165622"></a><a name="p933509019165622"></a><a href="PROCESS.md#ga28a15bba47cab57cbc9f5dac9af99c8b">pthread_join</a> (<a href="UTILS.md#ga5250f47a8a0402a78bb51a2133e13c1f">pthread_t</a> thread, void **retval)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1836488948165622"><a name="p1836488948165622"></a><a name="p1836488948165622"></a>int </p>
<p id="p723189045165622"><a name="p723189045165622"></a><a name="p723189045165622"></a>Waits for a thread to terminate. </p>
</td>
</tr>
<tr id="row722572677165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2097931441165622"><a name="p2097931441165622"></a><a name="p2097931441165622"></a><a href="PROCESS.md#ga4c4f5f3b4f8f45d9d897847d53b11aaa">pthread_self</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1671558764165622"><a name="p1671558764165622"></a><a name="p1671558764165622"></a><a href="UTILS.md#ga5250f47a8a0402a78bb51a2133e13c1f">pthread_t</a> </p>
<p id="p984802468165622"><a name="p984802468165622"></a><a name="p984802468165622"></a>Obtains the ID of the calling thread. </p>
</td>
</tr>
<tr id="row141745694165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p283459870165622"><a name="p283459870165622"></a><a name="p283459870165622"></a><a href="PROCESS.md#ga98ec817164a6641eda2341de473b659d">pthread_equal</a> (<a href="UTILS.md#ga5250f47a8a0402a78bb51a2133e13c1f">pthread_t</a> t1, <a href="UTILS.md#ga5250f47a8a0402a78bb51a2133e13c1f">pthread_t</a> t2)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p520534613165622"><a name="p520534613165622"></a><a name="p520534613165622"></a>int </p>
<p id="p360283072165622"><a name="p360283072165622"></a><a name="p360283072165622"></a>Compares whether two thread IDs are equal. </p>
</td>
</tr>
<tr id="row235233536165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p26062109165622"><a name="p26062109165622"></a><a name="p26062109165622"></a><a href="PROCESS.md#ga37075410fbbaad7ee93c95375fc86e0e">pthread_setcancelstate</a> (int state, int *oldstate)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p953302268165622"><a name="p953302268165622"></a><a name="p953302268165622"></a>int </p>
<p id="p337274235165622"><a name="p337274235165622"></a><a name="p337274235165622"></a>Sets the cancelability state for the calling thread. </p>
</td>
</tr>
<tr id="row589855880165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p853328665165622"><a name="p853328665165622"></a><a name="p853328665165622"></a><a href="PROCESS.md#gaab579bcfcf0662a0c1e35fd82162e61d">pthread_setcanceltype</a> (int type, int *oldtype)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p448604712165622"><a name="p448604712165622"></a><a name="p448604712165622"></a>int </p>
<p id="p139655743165622"><a name="p139655743165622"></a><a name="p139655743165622"></a>Sets the cancelability type for the calling thread. </p>
</td>
</tr>
<tr id="row689409197165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2010206267165622"><a name="p2010206267165622"></a><a name="p2010206267165622"></a><a href="PROCESS.md#gaf1c95282ab2bea25f0888a19652cd41f">pthread_testcancel</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p522788882165622"><a name="p522788882165622"></a><a name="p522788882165622"></a>void </p>
<p id="p1173217016165622"><a name="p1173217016165622"></a><a name="p1173217016165622"></a>Requests delivery of any pending cancellation request. </p>
</td>
</tr>
<tr id="row1866729995165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p404039977165622"><a name="p404039977165622"></a><a name="p404039977165622"></a><a href="PROCESS.md#ga9e77a80c073787bf9a593e9c619dce27">pthread_cancel</a> (<a href="UTILS.md#ga5250f47a8a0402a78bb51a2133e13c1f">pthread_t</a> thread)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1556897135165622"><a name="p1556897135165622"></a><a name="p1556897135165622"></a>int </p>
<p id="p1346214224165622"><a name="p1346214224165622"></a><a name="p1346214224165622"></a>Sends a cancellation request to a thread. </p>
</td>
</tr>
<tr id="row435229118165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1243159859165622"><a name="p1243159859165622"></a><a name="p1243159859165622"></a><a href="PROCESS.md#ga5aafacc071cdfafd0eb992004dee3e62">pthread_kill</a> (<a href="UTILS.md#ga5250f47a8a0402a78bb51a2133e13c1f">pthread_t</a> thread, int sig)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p866845499165622"><a name="p866845499165622"></a><a name="p866845499165622"></a>int </p>
<p id="p2118954744165622"><a name="p2118954744165622"></a><a name="p2118954744165622"></a>Sends a signal to a thread. </p>
</td>
</tr>
<tr id="row856116539165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1447089680165622"><a name="p1447089680165622"></a><a name="p1447089680165622"></a><a href="PROCESS.md#gaae9850b3759769c748727e171c4c6e61">pthread_getschedparam</a> (<a href="UTILS.md#ga5250f47a8a0402a78bb51a2133e13c1f">pthread_t</a> thread, int *policy, struct <a href="sched_param.md">sched_param</a> *param)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p209823447165622"><a name="p209823447165622"></a><a name="p209823447165622"></a>int </p>
<p id="p83796197165622"><a name="p83796197165622"></a><a name="p83796197165622"></a>Obtains the scheduling policy and parameters of a thread. </p>
</td>
</tr>
<tr id="row276321505165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p691327867165622"><a name="p691327867165622"></a><a name="p691327867165622"></a><a href="PROCESS.md#ga14f50e1f5d815c90f1f4225eca5d3a8c">pthread_setschedparam</a> (<a href="UTILS.md#ga5250f47a8a0402a78bb51a2133e13c1f">pthread_t</a> thread, int policy, const struct <a href="sched_param.md">sched_param</a> *param)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p646703169165622"><a name="p646703169165622"></a><a name="p646703169165622"></a>int </p>
<p id="p2027503168165622"><a name="p2027503168165622"></a><a name="p2027503168165622"></a>Sets a scheduling policy and parameters for a thread. </p>
</td>
</tr>
<tr id="row1033928288165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p301586951165622"><a name="p301586951165622"></a><a name="p301586951165622"></a><a href="PROCESS.md#ga7a23cbcfc21a4e3edf531ed65f022370">pthread_setschedprio</a> (<a href="UTILS.md#ga5250f47a8a0402a78bb51a2133e13c1f">pthread_t</a> thread, int prio)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p920298540165622"><a name="p920298540165622"></a><a name="p920298540165622"></a>int </p>
<p id="p879439863165622"><a name="p879439863165622"></a><a name="p879439863165622"></a>Sets a static scheduling priority for a thread. </p>
</td>
</tr>
<tr id="row359150701165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p832525532165622"><a name="p832525532165622"></a><a name="p832525532165622"></a><a href="PROCESS.md#ga196103ac97710dad7a93fd6c188cc999">pthread_once</a> (<a href="UTILS.md#gaf46ecab6116bf15713b10ddfab67bc07">pthread_once_t</a> *once_control, void(*init_routine)(void))</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1162195016165622"><a name="p1162195016165622"></a><a name="p1162195016165622"></a>int </p>
<p id="p1915322079165622"><a name="p1915322079165622"></a><a name="p1915322079165622"></a>Enables the initialization function to be called only once. </p>
</td>
</tr>
<tr id="row1749334943165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p956312407165622"><a name="p956312407165622"></a><a name="p956312407165622"></a><a href="PROCESS.md#gadd99221596e95a55f70c59c1c712bbde">pthread_mutex_init</a> (<a href="UTILS.md#ga75eeb2460f33f5f74cec3ff583ad9e94">pthread_mutex_t</a> *__restrict m, const <a href="UTILS.md#gaf2212c79151cc55f3a41c430908f3909">pthread_mutexattr_t</a> *__restrict a)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1890816214165622"><a name="p1890816214165622"></a><a name="p1890816214165622"></a>int </p>
<p id="p75961250165622"><a name="p75961250165622"></a><a name="p75961250165622"></a>Initializes a mutex. </p>
</td>
</tr>
<tr id="row825555424165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p748778567165622"><a name="p748778567165622"></a><a name="p748778567165622"></a><a href="PROCESS.md#gafd70d6f2c50e22b996c926fb9d6ad291">pthread_mutex_lock</a> (<a href="UTILS.md#ga75eeb2460f33f5f74cec3ff583ad9e94">pthread_mutex_t</a> *m)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2143163776165622"><a name="p2143163776165622"></a><a name="p2143163776165622"></a>int </p>
<p id="p1884301067165622"><a name="p1884301067165622"></a><a name="p1884301067165622"></a>Locks a mutex. </p>
</td>
</tr>
<tr id="row424137350165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p58305724165622"><a name="p58305724165622"></a><a name="p58305724165622"></a><a href="PROCESS.md#ga02a3c64dac70730e226c31c0e7dbb45c">pthread_mutex_unlock</a> (<a href="UTILS.md#ga75eeb2460f33f5f74cec3ff583ad9e94">pthread_mutex_t</a> *m)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p132156907165622"><a name="p132156907165622"></a><a name="p132156907165622"></a>int </p>
<p id="p1065683753165622"><a name="p1065683753165622"></a><a name="p1065683753165622"></a>Unlocks a mutex. </p>
</td>
</tr>
<tr id="row1896799713165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p161313252165622"><a name="p161313252165622"></a><a name="p161313252165622"></a><a href="PROCESS.md#gacc1ccbaf3d76572da85a8030bba1ede4">pthread_mutex_trylock</a> (<a href="UTILS.md#ga75eeb2460f33f5f74cec3ff583ad9e94">pthread_mutex_t</a> *m)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1977895341165622"><a name="p1977895341165622"></a><a name="p1977895341165622"></a>int </p>
<p id="p403312567165622"><a name="p403312567165622"></a><a name="p403312567165622"></a>Attempts to lock a mutex. </p>
</td>
</tr>
<tr id="row1326785498165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1244503835165622"><a name="p1244503835165622"></a><a name="p1244503835165622"></a><a href="PROCESS.md#gabc6a044b418e942b91121b1babb61708">pthread_mutex_timedlock</a> (<a href="UTILS.md#ga75eeb2460f33f5f74cec3ff583ad9e94">pthread_mutex_t</a> *__restrict m, const struct <a href="timespec.md">timespec</a> *__restrict at)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1139728918165622"><a name="p1139728918165622"></a><a name="p1139728918165622"></a>int </p>
<p id="p967687677165622"><a name="p967687677165622"></a><a name="p967687677165622"></a>Blocks the calling thread to lock a mutex. </p>
</td>
</tr>
<tr id="row756801848165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1233642215165622"><a name="p1233642215165622"></a><a name="p1233642215165622"></a><a href="PROCESS.md#gaf89d9cfa300f33b46720a96eac83d175">pthread_mutex_destroy</a> (<a href="UTILS.md#ga75eeb2460f33f5f74cec3ff583ad9e94">pthread_mutex_t</a> *m)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2073938964165622"><a name="p2073938964165622"></a><a name="p2073938964165622"></a>int </p>
<p id="p2126559785165622"><a name="p2126559785165622"></a><a name="p2126559785165622"></a>Destroys a mutex. </p>
</td>
</tr>
<tr id="row124164566165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1959384814165622"><a name="p1959384814165622"></a><a name="p1959384814165622"></a><a href="PROCESS.md#gabdf02ed57b055f1920991e96e7d67043">pthread_cond_init</a> (<a href="UTILS.md#gaf2111a9da165bafea75dabf5cb131042">pthread_cond_t</a> *__restrict c, const <a href="UTILS.md#gaa992c0a75a463b1c095248eec28086d3">pthread_condattr_t</a> *__restrict a)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1025552181165622"><a name="p1025552181165622"></a><a name="p1025552181165622"></a>int </p>
<p id="p1425633552165622"><a name="p1425633552165622"></a><a name="p1425633552165622"></a>Initializes a condition variable. </p>
</td>
</tr>
<tr id="row824062378165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2066757466165622"><a name="p2066757466165622"></a><a name="p2066757466165622"></a><a href="PROCESS.md#ga7f2a7328ee3a7743686adcd2d51771c4">pthread_cond_destroy</a> (<a href="UTILS.md#gaf2111a9da165bafea75dabf5cb131042">pthread_cond_t</a> *c)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p72525681165622"><a name="p72525681165622"></a><a name="p72525681165622"></a>int </p>
<p id="p197701259165622"><a name="p197701259165622"></a><a name="p197701259165622"></a>Destroys a condition variable. </p>
</td>
</tr>
<tr id="row1641770364165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1416088681165622"><a name="p1416088681165622"></a><a name="p1416088681165622"></a><a href="PROCESS.md#gaea601b8ce596a5c54fb12758c56b10a1">pthread_cond_wait</a> (<a href="UTILS.md#gaf2111a9da165bafea75dabf5cb131042">pthread_cond_t</a> *__restrict c, <a href="UTILS.md#ga75eeb2460f33f5f74cec3ff583ad9e94">pthread_mutex_t</a> *__restrict m)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p236939486165622"><a name="p236939486165622"></a><a name="p236939486165622"></a>int </p>
<p id="p406398733165622"><a name="p406398733165622"></a><a name="p406398733165622"></a>Blocks the calling thread to wait for the condition set by <strong id="b402455230165622"><a name="b402455230165622"></a><a name="b402455230165622"></a>pthread_con_signal()</strong>. </p>
</td>
</tr>
<tr id="row1818542291165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p343575804165622"><a name="p343575804165622"></a><a name="p343575804165622"></a><a href="PROCESS.md#ga506c0350d597721ab24bba7129e8e0df">pthread_cond_timedwait</a> (<a href="UTILS.md#gaf2111a9da165bafea75dabf5cb131042">pthread_cond_t</a> *__restrict c, <a href="UTILS.md#ga75eeb2460f33f5f74cec3ff583ad9e94">pthread_mutex_t</a> *__restrict m, const struct <a href="timespec.md">timespec</a> *__restrict ts)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1377784072165622"><a name="p1377784072165622"></a><a name="p1377784072165622"></a>int </p>
<p id="p1726021398165622"><a name="p1726021398165622"></a><a name="p1726021398165622"></a>Blocks the calling thread to wait for the condition set by <strong id="b1756643591165622"><a name="b1756643591165622"></a><a name="b1756643591165622"></a>pthread_con_signal()</strong> for a period of time specified by <strong id="b926917644165622"><a name="b926917644165622"></a><a name="b926917644165622"></a>ts</strong>. </p>
</td>
</tr>
<tr id="row1449771211165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p721401859165622"><a name="p721401859165622"></a><a name="p721401859165622"></a><a href="PROCESS.md#ga1c1ac7c8faaf8ad63e12bc3717f430f3">pthread_cond_broadcast</a> (<a href="UTILS.md#gaf2111a9da165bafea75dabf5cb131042">pthread_cond_t</a> *c)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p205047847165622"><a name="p205047847165622"></a><a name="p205047847165622"></a>int </p>
<p id="p330475233165622"><a name="p330475233165622"></a><a name="p330475233165622"></a>Unblocks all threads that are currently blocked on the condition variable <strong id="b725195203165622"><a name="b725195203165622"></a><a name="b725195203165622"></a>cond</strong>. </p>
</td>
</tr>
<tr id="row2098342424165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p170497488165622"><a name="p170497488165622"></a><a name="p170497488165622"></a><a href="PROCESS.md#ga9b0f2c7dead8c628e081d76c86a1addc">pthread_cond_signal</a> (<a href="UTILS.md#gaf2111a9da165bafea75dabf5cb131042">pthread_cond_t</a> *c)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1954389691165622"><a name="p1954389691165622"></a><a name="p1954389691165622"></a>int </p>
<p id="p1149166230165622"><a name="p1149166230165622"></a><a name="p1149166230165622"></a>Unblocks a thread. </p>
</td>
</tr>
<tr id="row620540028165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1628949749165622"><a name="p1628949749165622"></a><a name="p1628949749165622"></a><a href="PROCESS.md#ga1cf4bc49696c1a30db31219aef994401">pthread_rwlock_init</a> (<a href="UTILS.md#gadc0b6b9df00a6c3ed0d7f9afe8934d05">pthread_rwlock_t</a> *__restrict rw, const <a href="UTILS.md#gaac7b93dc39852a3374d6c0802ceb7aa5">pthread_rwlockattr_t</a> *__restrict a)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1188569568165622"><a name="p1188569568165622"></a><a name="p1188569568165622"></a>int </p>
<p id="p96360417165622"><a name="p96360417165622"></a><a name="p96360417165622"></a>Initializes a read-write lock. </p>
</td>
</tr>
<tr id="row364002817165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p769445886165622"><a name="p769445886165622"></a><a name="p769445886165622"></a><a href="PROCESS.md#gaa106bb55bdd0e120519d5412823f8b29">pthread_rwlock_destroy</a> (<a href="UTILS.md#gadc0b6b9df00a6c3ed0d7f9afe8934d05">pthread_rwlock_t</a> *rw)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1357900785165622"><a name="p1357900785165622"></a><a name="p1357900785165622"></a>int </p>
<p id="p1207209333165622"><a name="p1207209333165622"></a><a name="p1207209333165622"></a>Destroys a read-write lock. </p>
</td>
</tr>
<tr id="row1648498924165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p610533873165622"><a name="p610533873165622"></a><a name="p610533873165622"></a><a href="PROCESS.md#ga6153aca32112735053e6cc4a2a290feb">pthread_rwlock_rdlock</a> (<a href="UTILS.md#gadc0b6b9df00a6c3ed0d7f9afe8934d05">pthread_rwlock_t</a> *rw)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1161106904165622"><a name="p1161106904165622"></a><a name="p1161106904165622"></a>int </p>
<p id="p608579751165622"><a name="p608579751165622"></a><a name="p608579751165622"></a>Applies a read lock to a read-write lock. </p>
</td>
</tr>
<tr id="row1459279541165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p149856660165622"><a name="p149856660165622"></a><a name="p149856660165622"></a><a href="PROCESS.md#ga3ba2170f06184d12543c4a5b78715fa7">pthread_rwlock_tryrdlock</a> (<a href="UTILS.md#gadc0b6b9df00a6c3ed0d7f9afe8934d05">pthread_rwlock_t</a> *rw)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p266264740165622"><a name="p266264740165622"></a><a name="p266264740165622"></a>int </p>
<p id="p1660558155165622"><a name="p1660558155165622"></a><a name="p1660558155165622"></a>Attempts to apply a read lock to a read-write lock. </p>
</td>
</tr>
<tr id="row559560814165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p578563489165622"><a name="p578563489165622"></a><a name="p578563489165622"></a><a href="PROCESS.md#ga8edbe14731fd79a80f72384334266715">pthread_rwlock_timedrdlock</a> (<a href="UTILS.md#gadc0b6b9df00a6c3ed0d7f9afe8934d05">pthread_rwlock_t</a> *__restrict rw, const struct <a href="timespec.md">timespec</a> *__restrict at)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1823668963165622"><a name="p1823668963165622"></a><a name="p1823668963165622"></a>int </p>
<p id="p64537541165622"><a name="p64537541165622"></a><a name="p64537541165622"></a>Blocks the calling thread to lock a read-write lock for reading. </p>
</td>
</tr>
<tr id="row1875405048165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p165082290165622"><a name="p165082290165622"></a><a name="p165082290165622"></a><a href="PROCESS.md#gaf2ca5563676ae3ac35d3bc7b3547e7f7">pthread_rwlock_wrlock</a> (<a href="UTILS.md#gadc0b6b9df00a6c3ed0d7f9afe8934d05">pthread_rwlock_t</a> *rw)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p970363380165622"><a name="p970363380165622"></a><a name="p970363380165622"></a>int </p>
<p id="p169381477165622"><a name="p169381477165622"></a><a name="p169381477165622"></a>Applies a write lock to a read-write lock. </p>
</td>
</tr>
<tr id="row882627554165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p540523249165622"><a name="p540523249165622"></a><a name="p540523249165622"></a><a href="PROCESS.md#ga2b5044e2da304ae9666fdd4e05479905">pthread_rwlock_trywrlock</a> (<a href="UTILS.md#gadc0b6b9df00a6c3ed0d7f9afe8934d05">pthread_rwlock_t</a> *rw)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p28544181165622"><a name="p28544181165622"></a><a name="p28544181165622"></a>int </p>
<p id="p1558028253165622"><a name="p1558028253165622"></a><a name="p1558028253165622"></a>Attempts to apply a write lock to a read-write lock. </p>
</td>
</tr>
<tr id="row70539404165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1378179813165622"><a name="p1378179813165622"></a><a name="p1378179813165622"></a><a href="PROCESS.md#ga3fb8fb33e16653c5ad7b7f092959738e">pthread_rwlock_timedwrlock</a> (<a href="UTILS.md#gadc0b6b9df00a6c3ed0d7f9afe8934d05">pthread_rwlock_t</a> *__restrict rw, const struct <a href="timespec.md">timespec</a> *__restrict at)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p896892302165622"><a name="p896892302165622"></a><a name="p896892302165622"></a>int </p>
<p id="p90530364165622"><a name="p90530364165622"></a><a name="p90530364165622"></a>Blocks the calling thread to lock a read-write lock for writing. </p>
</td>
</tr>
<tr id="row2132659572165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1813286419165622"><a name="p1813286419165622"></a><a name="p1813286419165622"></a><a href="PROCESS.md#gaffd8a19e83fc87d865d103d6fbce8c4f">pthread_rwlock_unlock</a> (<a href="UTILS.md#gadc0b6b9df00a6c3ed0d7f9afe8934d05">pthread_rwlock_t</a> *rw)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p889291479165622"><a name="p889291479165622"></a><a name="p889291479165622"></a>int </p>
<p id="p178293756165622"><a name="p178293756165622"></a><a name="p178293756165622"></a>Unlocks a read-write lock. </p>
</td>
</tr>
<tr id="row1590756057165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p659581829165622"><a name="p659581829165622"></a><a name="p659581829165622"></a><a href="PROCESS.md#ga665a56a7bed60c8eaa6c28af40d13cd4">pthread_spin_init</a> (<a href="UTILS.md#gae13db7661b1f8f7028dd7a88c8185fd2">pthread_spinlock_t</a> *s, int shared)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1428647004165622"><a name="p1428647004165622"></a><a name="p1428647004165622"></a>int </p>
<p id="p45137164165622"><a name="p45137164165622"></a><a name="p45137164165622"></a>Initializes a spin lock. </p>
</td>
</tr>
<tr id="row616633014165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p27024982165622"><a name="p27024982165622"></a><a name="p27024982165622"></a><a href="PROCESS.md#ga822c2ff425ddad4c25b6a6092c6effff">pthread_spin_destroy</a> (<a href="UTILS.md#gae13db7661b1f8f7028dd7a88c8185fd2">pthread_spinlock_t</a> *s)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p773808169165622"><a name="p773808169165622"></a><a name="p773808169165622"></a>int </p>
<p id="p1512603484165622"><a name="p1512603484165622"></a><a name="p1512603484165622"></a>Destroys a spin lock. </p>
</td>
</tr>
<tr id="row1450223135165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1404779061165622"><a name="p1404779061165622"></a><a name="p1404779061165622"></a><a href="PROCESS.md#ga62cfd14d1f937a6e8f966e3a331bcf94">pthread_spin_lock</a> (<a href="UTILS.md#gae13db7661b1f8f7028dd7a88c8185fd2">pthread_spinlock_t</a> *s)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1518029433165622"><a name="p1518029433165622"></a><a name="p1518029433165622"></a>int </p>
<p id="p1177490897165622"><a name="p1177490897165622"></a><a name="p1177490897165622"></a>Locks a spin lock. </p>
</td>
</tr>
<tr id="row273989245165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p796463920165622"><a name="p796463920165622"></a><a name="p796463920165622"></a><a href="PROCESS.md#ga084834fa2d06f173f086ce23ec1ea5d9">pthread_spin_trylock</a> (<a href="UTILS.md#gae13db7661b1f8f7028dd7a88c8185fd2">pthread_spinlock_t</a> *s)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1379027979165622"><a name="p1379027979165622"></a><a name="p1379027979165622"></a>int </p>
<p id="p576087106165622"><a name="p576087106165622"></a><a name="p576087106165622"></a>Attempts to lock a spin lock. </p>
</td>
</tr>
<tr id="row597462306165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p137353290165622"><a name="p137353290165622"></a><a name="p137353290165622"></a><a href="PROCESS.md#ga3fe246007a85cee9d5f7af9b7d592b54">pthread_spin_unlock</a> (<a href="UTILS.md#gae13db7661b1f8f7028dd7a88c8185fd2">pthread_spinlock_t</a> *s)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p441181275165622"><a name="p441181275165622"></a><a name="p441181275165622"></a>int </p>
<p id="p2007153743165622"><a name="p2007153743165622"></a><a name="p2007153743165622"></a>Unlocks a spin lock. </p>
</td>
</tr>
<tr id="row230073847165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p632087094165622"><a name="p632087094165622"></a><a name="p632087094165622"></a><a href="PROCESS.md#ga4a324cd758cae702213ea41882f4cf41">pthread_barrier_init</a> (<a href="UTILS.md#ga2f6d30b3b873012dbd361d3f7d52db59">pthread_barrier_t</a> *__restrict b, const <a href="UTILS.md#ga506b5743098d9d38526b2fd1e21f9457">pthread_barrierattr_t</a> *__restrict a, unsigned count)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1810116053165622"><a name="p1810116053165622"></a><a name="p1810116053165622"></a>int </p>
<p id="p1640599993165622"><a name="p1640599993165622"></a><a name="p1640599993165622"></a>Initializes a barrier. </p>
</td>
</tr>
<tr id="row1941721021165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1384838817165622"><a name="p1384838817165622"></a><a name="p1384838817165622"></a><a href="PROCESS.md#gab05ae13769e61dea9c53ca7894743c8f">pthread_barrier_destroy</a> (<a href="UTILS.md#ga2f6d30b3b873012dbd361d3f7d52db59">pthread_barrier_t</a> *b)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1019171125165622"><a name="p1019171125165622"></a><a name="p1019171125165622"></a>int </p>
<p id="p385001487165622"><a name="p385001487165622"></a><a name="p385001487165622"></a>Destroys a barrier. </p>
</td>
</tr>
<tr id="row181942603165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1437274884165622"><a name="p1437274884165622"></a><a name="p1437274884165622"></a><a href="PROCESS.md#gaf786372165ba080986ae4143928c5436">pthread_barrier_wait</a> (<a href="UTILS.md#ga2f6d30b3b873012dbd361d3f7d52db59">pthread_barrier_t</a> *b)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1620876183165622"><a name="p1620876183165622"></a><a name="p1620876183165622"></a>int </p>
<p id="p84499618165622"><a name="p84499618165622"></a><a name="p84499618165622"></a>Synchronizes participating threads at a barrier. </p>
</td>
</tr>
<tr id="row1046613837165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1098081502165622"><a name="p1098081502165622"></a><a name="p1098081502165622"></a><a href="PROCESS.md#gaf4b7ced8ecff505380fe8216244a3764">pthread_key_create</a> (<a href="UTILS.md#gafeedfceab43831b6771f80aff6a519be">pthread_key_t</a> *key, void(*destructor)(void *))</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p228215616165622"><a name="p228215616165622"></a><a name="p228215616165622"></a>int </p>
<p id="p456392973165622"><a name="p456392973165622"></a><a name="p456392973165622"></a>Creates a key for thread data. </p>
</td>
</tr>
<tr id="row1745410572165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p540454685165622"><a name="p540454685165622"></a><a name="p540454685165622"></a><a href="PROCESS.md#gaee96306dc79294927ee840bb4de2244b">pthread_key_delete</a> (<a href="UTILS.md#gafeedfceab43831b6771f80aff6a519be">pthread_key_t</a> key)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1380657207165622"><a name="p1380657207165622"></a><a name="p1380657207165622"></a>int </p>
<p id="p1828976450165622"><a name="p1828976450165622"></a><a name="p1828976450165622"></a>Deletes a key for thread data. </p>
</td>
</tr>
<tr id="row351502528165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p520351552165622"><a name="p520351552165622"></a><a name="p520351552165622"></a><a href="PROCESS.md#ga31469375891078185bda93f0e4411a2c">pthread_getspecific</a> (<a href="UTILS.md#gafeedfceab43831b6771f80aff6a519be">pthread_key_t</a> key)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p530597520165622"><a name="p530597520165622"></a><a name="p530597520165622"></a>void * </p>
<p id="p926949868165622"><a name="p926949868165622"></a><a name="p926949868165622"></a>Obtains specific thread data. </p>
</td>
</tr>
<tr id="row1723497443165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1278647045165622"><a name="p1278647045165622"></a><a name="p1278647045165622"></a><a href="PROCESS.md#ga2187333dd46ce08d9d2e044f79fad705">pthread_setspecific</a> (<a href="UTILS.md#gafeedfceab43831b6771f80aff6a519be">pthread_key_t</a> key, const void *value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p442133539165622"><a name="p442133539165622"></a><a name="p442133539165622"></a>int </p>
<p id="p974063525165622"><a name="p974063525165622"></a><a name="p974063525165622"></a>Sets specific thread data. </p>
</td>
</tr>
<tr id="row1078318824165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p475106904165622"><a name="p475106904165622"></a><a name="p475106904165622"></a><a href="PROCESS.md#ga0b85ebb1e3aac081a4c0a5e85ae3cbe9">pthread_attr_init</a> (<a href="UTILS.md#gac8ee4471bbc35deb7589ac3615deb486">pthread_attr_t</a> *attr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p55953311165622"><a name="p55953311165622"></a><a name="p55953311165622"></a>int </p>
<p id="p2120252861165622"><a name="p2120252861165622"></a><a name="p2120252861165622"></a>Initializes a thread attribute object. </p>
</td>
</tr>
<tr id="row1159903984165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p775613049165622"><a name="p775613049165622"></a><a name="p775613049165622"></a><a href="PROCESS.md#ga4bcdbf47c17c7dcc51e9f05f5cb56d81">pthread_attr_destroy</a> (<a href="UTILS.md#gac8ee4471bbc35deb7589ac3615deb486">pthread_attr_t</a> *attr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1509150747165622"><a name="p1509150747165622"></a><a name="p1509150747165622"></a>int </p>
<p id="p119747023165622"><a name="p119747023165622"></a><a name="p119747023165622"></a>Destroys a thread attribute object. </p>
</td>
</tr>
<tr id="row612892666165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p395119757165622"><a name="p395119757165622"></a><a name="p395119757165622"></a><a href="PROCESS.md#gaa8b692ecc3880fdd49a4d423ba1ce91e">pthread_attr_getguardsize</a> (const <a href="UTILS.md#gac8ee4471bbc35deb7589ac3615deb486">pthread_attr_t</a> *attr, size_t *guardsize)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p955430533165622"><a name="p955430533165622"></a><a name="p955430533165622"></a>int </p>
<p id="p831324938165622"><a name="p831324938165622"></a><a name="p831324938165622"></a>Obtains the guard size of a thread attribute object. </p>
</td>
</tr>
<tr id="row1842302774165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1135159998165622"><a name="p1135159998165622"></a><a name="p1135159998165622"></a><a href="PROCESS.md#ga532b31c11a9d87663053c5342400758c">pthread_attr_setguardsize</a> (<a href="UTILS.md#gac8ee4471bbc35deb7589ac3615deb486">pthread_attr_t</a> *attr, size_t guardsize)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p700735769165622"><a name="p700735769165622"></a><a name="p700735769165622"></a>int </p>
<p id="p100982649165622"><a name="p100982649165622"></a><a name="p100982649165622"></a>Sets the guard size for a thread attribute object. </p>
</td>
</tr>
<tr id="row2084239647165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1601505600165622"><a name="p1601505600165622"></a><a name="p1601505600165622"></a><a href="PROCESS.md#gae23600d4670359ab12bfba20db2c9a37">pthread_attr_getstacksize</a> (const <a href="UTILS.md#gac8ee4471bbc35deb7589ac3615deb486">pthread_attr_t</a> *attr, size_t *stacksize)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1795664986165622"><a name="p1795664986165622"></a><a name="p1795664986165622"></a>int </p>
<p id="p108148228165622"><a name="p108148228165622"></a><a name="p108148228165622"></a>Obtains the stack size of a thread attribute object. </p>
</td>
</tr>
<tr id="row368774221165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p450309440165622"><a name="p450309440165622"></a><a name="p450309440165622"></a><a href="PROCESS.md#ga812a9a455ae2ef2bb0dca4fff201a281">pthread_attr_setstacksize</a> (<a href="UTILS.md#gac8ee4471bbc35deb7589ac3615deb486">pthread_attr_t</a> *attr, size_t stacksize)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1353415421165622"><a name="p1353415421165622"></a><a name="p1353415421165622"></a>int </p>
<p id="p1516324706165622"><a name="p1516324706165622"></a><a name="p1516324706165622"></a>Sets the stack size for a thread attribute object. </p>
</td>
</tr>
<tr id="row1661768907165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p95655065165622"><a name="p95655065165622"></a><a name="p95655065165622"></a><a href="PROCESS.md#ga391c34da42e68ddd24f5ee0c070d5c4f">pthread_attr_getdetachstate</a> (const <a href="UTILS.md#gac8ee4471bbc35deb7589ac3615deb486">pthread_attr_t</a> *attr, int *detachstate)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p915002544165622"><a name="p915002544165622"></a><a name="p915002544165622"></a>int </p>
<p id="p840843612165622"><a name="p840843612165622"></a><a name="p840843612165622"></a>Obtains the detach state of a thread attribute object. </p>
</td>
</tr>
<tr id="row868750566165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p681711260165622"><a name="p681711260165622"></a><a name="p681711260165622"></a><a href="PROCESS.md#gae6ee78c307d8467b34a9b0c330993a54">pthread_attr_setdetachstate</a> (<a href="UTILS.md#gac8ee4471bbc35deb7589ac3615deb486">pthread_attr_t</a> *attr, int detachstate)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1221088440165622"><a name="p1221088440165622"></a><a name="p1221088440165622"></a>int </p>
<p id="p1384923122165622"><a name="p1384923122165622"></a><a name="p1384923122165622"></a>Sets the detach state for a thread attribute object. </p>
</td>
</tr>
<tr id="row906272328165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p457767558165622"><a name="p457767558165622"></a><a name="p457767558165622"></a><a href="PROCESS.md#gaec19ad460995a9fe8aeb4eaf2bb1ed1d">pthread_attr_getstack</a> (const <a href="UTILS.md#gac8ee4471bbc35deb7589ac3615deb486">pthread_attr_t</a> *attr, void **stackaddr, size_t *stacksize)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1981065426165622"><a name="p1981065426165622"></a><a name="p1981065426165622"></a>int </p>
<p id="p1737654419165622"><a name="p1737654419165622"></a><a name="p1737654419165622"></a>Obtains stack attributes of a thread attribute object. </p>
</td>
</tr>
<tr id="row870303653165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1679549560165622"><a name="p1679549560165622"></a><a name="p1679549560165622"></a><a href="PROCESS.md#ga94ede89b99a3a4fa17e516d30aaf3409">pthread_attr_setstack</a> (<a href="UTILS.md#gac8ee4471bbc35deb7589ac3615deb486">pthread_attr_t</a> *attr, void *stackaddr, size_t stacksize)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1966559740165622"><a name="p1966559740165622"></a><a name="p1966559740165622"></a>int </p>
<p id="p1919497905165622"><a name="p1919497905165622"></a><a name="p1919497905165622"></a>Sets stack attributes for a thread attribute object. </p>
</td>
</tr>
<tr id="row229406954165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2132134650165622"><a name="p2132134650165622"></a><a name="p2132134650165622"></a><a href="PROCESS.md#gabfd252cd45081231018030e3878efa06">pthread_attr_getscope</a> (const <a href="UTILS.md#gac8ee4471bbc35deb7589ac3615deb486">pthread_attr_t</a> *attr, int *scope)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p122782448165622"><a name="p122782448165622"></a><a name="p122782448165622"></a>int </p>
<p id="p1910868113165622"><a name="p1910868113165622"></a><a name="p1910868113165622"></a>Obtains contention scope attributes of a thread attribute object. </p>
</td>
</tr>
<tr id="row86305339165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1303236385165622"><a name="p1303236385165622"></a><a name="p1303236385165622"></a><a href="PROCESS.md#ga294aaacf59f34effeef978242cf08cbe">pthread_attr_setscope</a> (<a href="UTILS.md#gac8ee4471bbc35deb7589ac3615deb486">pthread_attr_t</a> *attr, int scope)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p390948020165622"><a name="p390948020165622"></a><a name="p390948020165622"></a>int </p>
<p id="p1258759543165622"><a name="p1258759543165622"></a><a name="p1258759543165622"></a>Sets contention scope attributes for a thread attribute object. </p>
</td>
</tr>
<tr id="row1785893482165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p949440825165622"><a name="p949440825165622"></a><a name="p949440825165622"></a><a href="PROCESS.md#gaec4d8127833d1a573aa82539f898a8ed">pthread_attr_getschedpolicy</a> (const <a href="UTILS.md#gac8ee4471bbc35deb7589ac3615deb486">pthread_attr_t</a> *attr, int *schedpolicy)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p126548583165622"><a name="p126548583165622"></a><a name="p126548583165622"></a>int </p>
<p id="p1055487463165622"><a name="p1055487463165622"></a><a name="p1055487463165622"></a>Obtains scheduling policy attributes of a thread attribute object. </p>
</td>
</tr>
<tr id="row2120518402165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p441723135165622"><a name="p441723135165622"></a><a name="p441723135165622"></a><a href="PROCESS.md#gab6cb2eb73f04abf328b2f39777c35dca">pthread_attr_setschedpolicy</a> (<a href="UTILS.md#gac8ee4471bbc35deb7589ac3615deb486">pthread_attr_t</a> *attr, int schedpolicy)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2041292841165622"><a name="p2041292841165622"></a><a name="p2041292841165622"></a>int </p>
<p id="p1300176241165622"><a name="p1300176241165622"></a><a name="p1300176241165622"></a>Sets scheduling policy attributes for a thread attribute object. </p>
</td>
</tr>
<tr id="row441869175165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1947265262165622"><a name="p1947265262165622"></a><a name="p1947265262165622"></a><a href="PROCESS.md#gafd3d272d702481044f8a8cd253fd9b47">pthread_attr_getschedparam</a> (const <a href="UTILS.md#gac8ee4471bbc35deb7589ac3615deb486">pthread_attr_t</a> *attr, struct <a href="sched_param.md">sched_param</a> *param)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p31074917165622"><a name="p31074917165622"></a><a name="p31074917165622"></a>int </p>
<p id="p588054746165622"><a name="p588054746165622"></a><a name="p588054746165622"></a>Obtains scheduling parameter attributes of a thread attribute object. </p>
</td>
</tr>
<tr id="row728365416165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1088191095165622"><a name="p1088191095165622"></a><a name="p1088191095165622"></a><a href="PROCESS.md#ga579e6529f0ce482312a5e77ac61cb4d5">pthread_attr_setschedparam</a> (<a href="UTILS.md#gac8ee4471bbc35deb7589ac3615deb486">pthread_attr_t</a> *attr, const struct <a href="sched_param.md">sched_param</a> *param)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p23776759165622"><a name="p23776759165622"></a><a name="p23776759165622"></a>int </p>
<p id="p679322915165622"><a name="p679322915165622"></a><a name="p679322915165622"></a>Sets scheduling parameter attributes for a thread attribute object. </p>
</td>
</tr>
<tr id="row1569240491165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1150103366165622"><a name="p1150103366165622"></a><a name="p1150103366165622"></a><a href="PROCESS.md#ga79a77b688c30213e5e52e6be178cde4e">pthread_attr_getinheritsched</a> (const <a href="UTILS.md#gac8ee4471bbc35deb7589ac3615deb486">pthread_attr_t</a> *attr, int *inheritsched)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1184313647165622"><a name="p1184313647165622"></a><a name="p1184313647165622"></a>int </p>
<p id="p2120490825165622"><a name="p2120490825165622"></a><a name="p2120490825165622"></a>Obtains inherit scheduler attributes of a thread attribute object. </p>
</td>
</tr>
<tr id="row419663500165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p846009673165622"><a name="p846009673165622"></a><a name="p846009673165622"></a><a href="PROCESS.md#gad437fe8caa3ef9f0cb7d69f6f6479df9">pthread_attr_setinheritsched</a> (<a href="UTILS.md#gac8ee4471bbc35deb7589ac3615deb486">pthread_attr_t</a> *attr, int inheritsched)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p944560065165622"><a name="p944560065165622"></a><a name="p944560065165622"></a>int </p>
<p id="p1985121048165622"><a name="p1985121048165622"></a><a name="p1985121048165622"></a>Sets inherit scheduler attributes for a thread attribute object. </p>
</td>
</tr>
<tr id="row264670139165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1169458257165622"><a name="p1169458257165622"></a><a name="p1169458257165622"></a><a href="PROCESS.md#ga2321aabf58224b06021185708d0f9658">pthread_mutexattr_destroy</a> (<a href="UTILS.md#gaf2212c79151cc55f3a41c430908f3909">pthread_mutexattr_t</a> *attr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p983799339165622"><a name="p983799339165622"></a><a name="p983799339165622"></a>int </p>
<p id="p210679901165622"><a name="p210679901165622"></a><a name="p210679901165622"></a>Destroys a mutex attribute object. </p>
</td>
</tr>
<tr id="row1814321790165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p893932447165622"><a name="p893932447165622"></a><a name="p893932447165622"></a><a href="PROCESS.md#ga4789e2d3ada7aab2af1458bfec53ee3c">pthread_mutexattr_gettype</a> (const <a href="UTILS.md#gaf2212c79151cc55f3a41c430908f3909">pthread_mutexattr_t</a> *__restrict attr, int *__restrict type)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p202683244165622"><a name="p202683244165622"></a><a name="p202683244165622"></a>int </p>
<p id="p2090616015165622"><a name="p2090616015165622"></a><a name="p2090616015165622"></a>Obtains the mutex type attribute. </p>
</td>
</tr>
<tr id="row1672315383165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p952952978165622"><a name="p952952978165622"></a><a name="p952952978165622"></a><a href="PROCESS.md#gaf98f6b6c483077a39d1400b1de1577b8">pthread_mutexattr_init</a> (<a href="UTILS.md#gaf2212c79151cc55f3a41c430908f3909">pthread_mutexattr_t</a> *attr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p446425630165622"><a name="p446425630165622"></a><a name="p446425630165622"></a>int </p>
<p id="p560066985165622"><a name="p560066985165622"></a><a name="p560066985165622"></a>Initializes a mutex attribute object. </p>
</td>
</tr>
<tr id="row2138441580165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p156237619165622"><a name="p156237619165622"></a><a name="p156237619165622"></a><a href="PROCESS.md#ga8387c80e660e9426f801ac0217ecfae5">pthread_mutexattr_settype</a> (<a href="UTILS.md#gaf2212c79151cc55f3a41c430908f3909">pthread_mutexattr_t</a> *attr, int type)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p671281792165622"><a name="p671281792165622"></a><a name="p671281792165622"></a>int </p>
<p id="p1226851202165622"><a name="p1226851202165622"></a><a name="p1226851202165622"></a>Sets the mutex type attribute. </p>
</td>
</tr>
<tr id="row1806897101165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1918652392165622"><a name="p1918652392165622"></a><a name="p1918652392165622"></a><a href="PROCESS.md#ga487a919ab54fd47c8464507031957df0">pthread_condattr_init</a> (<a href="UTILS.md#gaa992c0a75a463b1c095248eec28086d3">pthread_condattr_t</a> *a)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2031457465165622"><a name="p2031457465165622"></a><a name="p2031457465165622"></a>int </p>
<p id="p845689429165622"><a name="p845689429165622"></a><a name="p845689429165622"></a>Initializes a condition variable attribute object. </p>
</td>
</tr>
<tr id="row506511938165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p964800097165622"><a name="p964800097165622"></a><a name="p964800097165622"></a><a href="PROCESS.md#ga8ab009937339c899a5197eea2e48e6a1">pthread_condattr_destroy</a> (<a href="UTILS.md#gaa992c0a75a463b1c095248eec28086d3">pthread_condattr_t</a> *a)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p852290563165622"><a name="p852290563165622"></a><a name="p852290563165622"></a>int </p>
<p id="p1496975079165622"><a name="p1496975079165622"></a><a name="p1496975079165622"></a>Destroys a condition variable attribute object. </p>
</td>
</tr>
<tr id="row2121391004165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p358134903165622"><a name="p358134903165622"></a><a name="p358134903165622"></a><a href="PROCESS.md#gaaf7ac0f85233c0effaf850a9c65b6d68">pthread_condattr_setclock</a> (<a href="UTILS.md#gaa992c0a75a463b1c095248eec28086d3">pthread_condattr_t</a> *a, <a href="UTILS.md#ga391e4a62662054e5d3e1e071b8e54329">clockid_t</a> clk)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1706435641165622"><a name="p1706435641165622"></a><a name="p1706435641165622"></a>int </p>
<p id="p1774103327165622"><a name="p1774103327165622"></a><a name="p1774103327165622"></a>Sets a clock for a condition variable attribute object. </p>
</td>
</tr>
<tr id="row1943150005165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p619690371165622"><a name="p619690371165622"></a><a name="p619690371165622"></a><a href="PROCESS.md#gadcf908971c2ea15ced780025772084e3">pthread_condattr_getclock</a> (const <a href="UTILS.md#gaa992c0a75a463b1c095248eec28086d3">pthread_condattr_t</a> *__restrict a, <a href="UTILS.md#ga391e4a62662054e5d3e1e071b8e54329">clockid_t</a> *__restrict clk)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1153368864165622"><a name="p1153368864165622"></a><a name="p1153368864165622"></a>int </p>
<p id="p811072390165622"><a name="p811072390165622"></a><a name="p811072390165622"></a>Obtains the clock of a condition variable attribute object. </p>
</td>
</tr>
<tr id="row587171146165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p471693295165622"><a name="p471693295165622"></a><a name="p471693295165622"></a><a href="PROCESS.md#ga9d831af0179ed16d1b6cbeba0304810b">pthread_rwlockattr_init</a> (<a href="UTILS.md#gaac7b93dc39852a3374d6c0802ceb7aa5">pthread_rwlockattr_t</a> *attr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p67910843165622"><a name="p67910843165622"></a><a name="p67910843165622"></a>int </p>
<p id="p909936336165622"><a name="p909936336165622"></a><a name="p909936336165622"></a>Initializes a read-write lock attribute object. </p>
</td>
</tr>
<tr id="row1593886749165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p713586371165622"><a name="p713586371165622"></a><a name="p713586371165622"></a><a href="PROCESS.md#ga78a54e67f0afe2601dbda0a904fa0bdf">pthread_rwlockattr_destroy</a> (<a href="UTILS.md#gaac7b93dc39852a3374d6c0802ceb7aa5">pthread_rwlockattr_t</a> *attr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2083306460165622"><a name="p2083306460165622"></a><a name="p2083306460165622"></a>int </p>
<p id="p884992946165622"><a name="p884992946165622"></a><a name="p884992946165622"></a>Destroys a read-write lock attribute object. </p>
</td>
</tr>
<tr id="row1633723049165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p140669953165622"><a name="p140669953165622"></a><a name="p140669953165622"></a><a href="PROCESS.md#ga3bd99d89e352ccc51d5b94d157f1218b">pthread_barrierattr_destroy</a> (<a href="UTILS.md#ga506b5743098d9d38526b2fd1e21f9457">pthread_barrierattr_t</a> *a)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1977418922165622"><a name="p1977418922165622"></a><a name="p1977418922165622"></a>int </p>
<p id="p1412420257165622"><a name="p1412420257165622"></a><a name="p1412420257165622"></a>Destroys a barrier attribute object. </p>
</td>
</tr>
<tr id="row157480836165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p368856034165622"><a name="p368856034165622"></a><a name="p368856034165622"></a><a href="PROCESS.md#ga2ff720e06488668dc0ae6779755946e6">pthread_barrierattr_init</a> (<a href="UTILS.md#ga506b5743098d9d38526b2fd1e21f9457">pthread_barrierattr_t</a> *a)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1120570694165622"><a name="p1120570694165622"></a><a name="p1120570694165622"></a>int </p>
<p id="p1272752465165622"><a name="p1272752465165622"></a><a name="p1272752465165622"></a>Initializes a barrier attribute object. </p>
</td>
</tr>
<tr id="row2110333339165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1512344386165622"><a name="p1512344386165622"></a><a name="p1512344386165622"></a><a href="PROCESS.md#ga80008474c3d68e9880da960a53d2f430">pthread_atfork</a> (void(*prepare)(void), void(*parent)(void), void(*child)(void))</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1457438912165622"><a name="p1457438912165622"></a><a name="p1457438912165622"></a>int </p>
<p id="p651617051165622"><a name="p651617051165622"></a><a name="p651617051165622"></a>Registers a fork handler to be called before and after <a href="UTILS.md#gaa4e4714e6e8927c80b2553a40094b6d9">fork()</a>. </p>
</td>
</tr>
<tr id="row1771070104165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1904495563165622"><a name="p1904495563165622"></a><a name="p1904495563165622"></a><a href="PROCESS.md#ga68bc26522daf418f3cc78360925374ef">pthread_cleanup_push</a> (void(*routine)(void *), void *arg)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p972279478165622"><a name="p972279478165622"></a><a name="p972279478165622"></a>void </p>
<p id="p272833013165622"><a name="p272833013165622"></a><a name="p272833013165622"></a>Pushes the routine to the top of the clean-up handler stack. </p>
</td>
</tr>
<tr id="row1440984673165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1289722622165622"><a name="p1289722622165622"></a><a name="p1289722622165622"></a><a href="PROCESS.md#gafbe33fb00cd24693796a0870a3374631">pthread_cleanup_pop</a> (int execute)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p932439599165622"><a name="p932439599165622"></a><a name="p932439599165622"></a>void </p>
<p id="p1914787355165622"><a name="p1914787355165622"></a><a name="p1914787355165622"></a>Removes the routine at the top of the clean-up handler stack. </p>
</td>
</tr>
<tr id="row520259511165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1948932057165622"><a name="p1948932057165622"></a><a name="p1948932057165622"></a><a href="PROCESS.md#ga6bdca4b2c8a436c4651fb5e8d462408b">pthread_getattr_np</a> (<a href="UTILS.md#ga5250f47a8a0402a78bb51a2133e13c1f">pthread_t</a> thread, <a href="UTILS.md#gac8ee4471bbc35deb7589ac3615deb486">pthread_attr_t</a> *attr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1989501175165622"><a name="p1989501175165622"></a><a name="p1989501175165622"></a>int </p>
<p id="p1507958461165622"><a name="p1507958461165622"></a><a name="p1507958461165622"></a>Obtains the attributes of a created thread. </p>
</td>
</tr>
<tr id="row1480446855165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p730530496165622"><a name="p730530496165622"></a><a name="p730530496165622"></a><a href="PROCESS.md#ga185584d77295432838d8b839d916f160">pthread_setname_np</a> (<a href="UTILS.md#ga5250f47a8a0402a78bb51a2133e13c1f">pthread_t</a> pthread, const char *name)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1493496944165622"><a name="p1493496944165622"></a><a name="p1493496944165622"></a>int </p>
<p id="p795407188165622"><a name="p795407188165622"></a><a name="p795407188165622"></a>Sets the thread name. </p>
</td>
</tr>
<tr id="row1469278802165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1169031002165622"><a name="p1169031002165622"></a><a name="p1169031002165622"></a><a href="PROCESS.md#ga051df55ea1131f70f6f9356865a36798">pthread_getaffinity_np</a> (<a href="UTILS.md#ga5250f47a8a0402a78bb51a2133e13c1f">pthread_t</a> td, size_t size, cpu_set_t *set)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p740744172165622"><a name="p740744172165622"></a><a name="p740744172165622"></a>int </p>
<p id="p801116042165622"><a name="p801116042165622"></a><a name="p801116042165622"></a>Gets the thread affinity. </p>
</td>
</tr>
<tr id="row27316513165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p916149048165622"><a name="p916149048165622"></a><a name="p916149048165622"></a><a href="PROCESS.md#ga217f60f9431c453c74b675e72bba307d">pthread_setaffinity_np</a> (<a href="UTILS.md#ga5250f47a8a0402a78bb51a2133e13c1f">pthread_t</a> td, size_t size, const cpu_set_t *set)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1848398608165622"><a name="p1848398608165622"></a><a name="p1848398608165622"></a>int </p>
<p id="p449239707165622"><a name="p449239707165622"></a><a name="p449239707165622"></a>Sets the thread affinity. </p>
</td>
</tr>
<tr id="row66099838165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p137739618165622"><a name="p137739618165622"></a><a name="p137739618165622"></a><a href="PROCESS.md#gafaebd1698caeb9b9b9e614ad84edd609">sched_get_priority_max</a> (int policy)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1641014201165622"><a name="p1641014201165622"></a><a name="p1641014201165622"></a>int </p>
<p id="p1439533043165622"><a name="p1439533043165622"></a><a name="p1439533043165622"></a>Obtains the maximum static priority that can be used for a process. </p>
</td>
</tr>
<tr id="row1582415684165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p532485697165622"><a name="p532485697165622"></a><a name="p532485697165622"></a><a href="PROCESS.md#gaf1f370fc36ea6b22ed42b5ee3cf82a81">sched_get_priority_min</a> (int policy)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1435323312165622"><a name="p1435323312165622"></a><a name="p1435323312165622"></a>int </p>
<p id="p600915792165622"><a name="p600915792165622"></a><a name="p600915792165622"></a>Obtains the minimum static priority that can be used for a process. </p>
</td>
</tr>
<tr id="row440681446165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1862660867165622"><a name="p1862660867165622"></a><a name="p1862660867165622"></a><a href="PROCESS.md#ga563c7ac53bac2c1b51379147e66c44ec">sched_getparam</a> (<a href="UTILS.md#ga30c34d3eead853c44f459f21b932984c">pid_t</a> pid, struct <a href="sched_param.md">sched_param</a> *param)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1443945760165622"><a name="p1443945760165622"></a><a name="p1443945760165622"></a>int </p>
<p id="p1176510505165622"><a name="p1176510505165622"></a><a name="p1176510505165622"></a>Obtains scheduling parameters of a process. </p>
</td>
</tr>
<tr id="row79268954165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p855149721165622"><a name="p855149721165622"></a><a name="p855149721165622"></a><a href="PROCESS.md#ga99fcb2532b1482d236dc04495a3f194d">sched_getscheduler</a> (<a href="UTILS.md#ga30c34d3eead853c44f459f21b932984c">pid_t</a> pid)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p716114566165622"><a name="p716114566165622"></a><a name="p716114566165622"></a>int </p>
<p id="p1014392581165622"><a name="p1014392581165622"></a><a name="p1014392581165622"></a>Obtains the scheduling policy of a process. </p>
</td>
</tr>
<tr id="row1121715905165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1073557452165622"><a name="p1073557452165622"></a><a name="p1073557452165622"></a><a href="PROCESS.md#ga484f0eb93529d29a66e24485725c4c7b">sched_rr_get_interval</a> (<a href="UTILS.md#ga30c34d3eead853c44f459f21b932984c">pid_t</a> pid, struct <a href="timespec.md">timespec</a> *interval)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2025925917165622"><a name="p2025925917165622"></a><a name="p2025925917165622"></a>int </p>
<p id="p787075529165622"><a name="p787075529165622"></a><a name="p787075529165622"></a>Obtains the execution time limit of a process. </p>
</td>
</tr>
<tr id="row900421586165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1854485335165622"><a name="p1854485335165622"></a><a name="p1854485335165622"></a><a href="PROCESS.md#ga06b497c4ea6bbabd2b62ba1a8a848a1b">sched_setparam</a> (<a href="UTILS.md#ga30c34d3eead853c44f459f21b932984c">pid_t</a> pid, const struct <a href="sched_param.md">sched_param</a> *param)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1481441093165622"><a name="p1481441093165622"></a><a name="p1481441093165622"></a>int </p>
<p id="p335516137165622"><a name="p335516137165622"></a><a name="p335516137165622"></a>Sets scheduling parameters related to a scheduling policy for a process. </p>
</td>
</tr>
<tr id="row348407560165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p818828364165622"><a name="p818828364165622"></a><a name="p818828364165622"></a><a href="PROCESS.md#ga84ad29a6f2ad27370df09c664ac65eac">sched_setscheduler</a> (<a href="UTILS.md#ga30c34d3eead853c44f459f21b932984c">pid_t</a> pid, int policy, const struct <a href="sched_param.md">sched_param</a> *param)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p727867836165622"><a name="p727867836165622"></a><a name="p727867836165622"></a>int </p>
<p id="p1954486676165622"><a name="p1954486676165622"></a><a name="p1954486676165622"></a>Sets a scheduling policy for a process. </p>
</td>
</tr>
<tr id="row646659185165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1438898546165622"><a name="p1438898546165622"></a><a name="p1438898546165622"></a><a href="PROCESS.md#ga357cd4b34c13011749dfffb42b489f09">sched_yield</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1425532438165622"><a name="p1425532438165622"></a><a name="p1425532438165622"></a>int </p>
<p id="p1822740190165622"><a name="p1822740190165622"></a><a name="p1822740190165622"></a>Yields the running process. </p>
</td>
</tr>
<tr id="row1568146581165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1652522288165622"><a name="p1652522288165622"></a><a name="p1652522288165622"></a><a href="PROCESS.md#gaa284eba1654e9fc0672aca2a6d2cd0ce">capget</a> (<a href="PROCESS.md#gaf042e68224162d4eb2ce7668904831d9">cap_user_header_t</a> hdr_ptr, <a href="PROCESS.md#gaafd3aaf8bb3f786614fee86c2fa93667">cap_user_data_t</a> data_ptr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1499637621165622"><a name="p1499637621165622"></a><a name="p1499637621165622"></a>int </p>
<p id="p994691168165622"><a name="p994691168165622"></a><a name="p994691168165622"></a>Obtains the capability information of a specified process based on the input parameters (compatible with the Linux API format). </p>
</td>
</tr>
<tr id="row768063781165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1729137777165622"><a name="p1729137777165622"></a><a name="p1729137777165622"></a><a href="PROCESS.md#gaaa15be01b20aff9efb09de5a8ead207e">capset</a> (<a href="PROCESS.md#gaf042e68224162d4eb2ce7668904831d9">cap_user_header_t</a> hdr_ptr, const <a href="PROCESS.md#gaafd3aaf8bb3f786614fee86c2fa93667">cap_user_data_t</a> data_ptr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1717553459165622"><a name="p1717553459165622"></a><a name="p1717553459165622"></a>int </p>
<p id="p84434004165622"><a name="p84434004165622"></a><a name="p84434004165622"></a>Sets the capability information for a specified process based on the input parameters (compatible with the Linux API format). </p>
</td>
</tr>
<tr id="row1203482113165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p210937209165622"><a name="p210937209165622"></a><a name="p210937209165622"></a><a href="PROCESS.md#gaf254b29504e9733ff55014acdf5fbcc7">ohos_capget</a> (<a href="UTILS.md#ga30c34d3eead853c44f459f21b932984c">pid_t</a> pid, unsigned int *caps)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1206954977165622"><a name="p1206954977165622"></a><a name="p1206954977165622"></a>int </p>
<p id="p2023111557165622"><a name="p2023111557165622"></a><a name="p2023111557165622"></a>Obtains the capability information of the specified process process based on the input parameters. </p>
</td>
</tr>
<tr id="row57543294165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p222062346165622"><a name="p222062346165622"></a><a name="p222062346165622"></a><a href="PROCESS.md#ga77ad7758babf522e7ffb28551332a659">ohos_capset</a> (unsigned int caps)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p388997867165622"><a name="p388997867165622"></a><a name="p388997867165622"></a>int </p>
<p id="p966471969165622"><a name="p966471969165622"></a><a name="p966471969165622"></a>Sets the capability information of the current process based on the input parameters. </p>
</td>
</tr>
<tr id="row614973217165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p750478321165622"><a name="p750478321165622"></a><a name="p750478321165622"></a><a href="PROCESS.md#gac2ee4921a8961060b4c7fcad8bf2b4e2">getpriority</a> (int which, <a href="UTILS.md#gab66157aef1dc726dccc825f07239da53">id_t</a> who)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1789425256165622"><a name="p1789425256165622"></a><a name="p1789425256165622"></a>int </p>
<p id="p1719173153165622"><a name="p1719173153165622"></a><a name="p1719173153165622"></a>Obtains the static priority of a specified ID. </p>
</td>
</tr>
<tr id="row1487335729165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p247901151165622"><a name="p247901151165622"></a><a name="p247901151165622"></a><a href="PROCESS.md#ga0a8d4c8043a7748c25dd551dc69dcad2">setpriority</a> (int which, <a href="UTILS.md#gab66157aef1dc726dccc825f07239da53">id_t</a> who, int value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p62677139165622"><a name="p62677139165622"></a><a name="p62677139165622"></a>int </p>
<p id="p855728185165622"><a name="p855728185165622"></a><a name="p855728185165622"></a>Sets the static priority of a specified ID. </p>
</td>
</tr>
<tr id="row1977929008165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p690949044165622"><a name="p690949044165622"></a><a name="p690949044165622"></a><a href="PROCESS.md#gabf2fbcf6df59fd5234e9eed4db1a1804">wait</a> (int *status)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1131386513165622"><a name="p1131386513165622"></a><a name="p1131386513165622"></a><a href="UTILS.md#ga30c34d3eead853c44f459f21b932984c">pid_t</a> </p>
<p id="p588529832165622"><a name="p588529832165622"></a><a name="p588529832165622"></a>Waits for any child process to end and reclaims its resources. </p>
</td>
</tr>
<tr id="row573808638165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p998151738165622"><a name="p998151738165622"></a><a name="p998151738165622"></a><a href="PROCESS.md#ga77de8005691d1f125540d66032a3cc62">waitpid</a> (<a href="UTILS.md#ga30c34d3eead853c44f459f21b932984c">pid_t</a> pid, int *status, int options)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p155645816165622"><a name="p155645816165622"></a><a name="p155645816165622"></a><a href="UTILS.md#ga30c34d3eead853c44f459f21b932984c">pid_t</a> </p>
<p id="p575872634165622"><a name="p575872634165622"></a><a name="p575872634165622"></a>Waits for a specified child process to end and reclaims its resources. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section2053292651165622"></a>

## **Function **<a name="section1655463262165622"></a>

## capget\(\)<a name="gaa284eba1654e9fc0672aca2a6d2cd0ce"></a>

```
int capget ([cap_user_header_t](PROCESS.md#gaf042e68224162d4eb2ce7668904831d9) hdr_ptr, [cap_user_data_t](PROCESS.md#gaafd3aaf8bb3f786614fee86c2fa93667) data_ptr )
```

 **Description:**

Obtains the capability information of a specified process based on the input parameters \(compatible with the Linux API format\). 

**Parameters:**

<a name="table1048584491165622"></a>
<table><thead align="left"><tr id="row2016660085165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1661855317165622"><a name="p1661855317165622"></a><a name="p1661855317165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2032294736165622"><a name="p2032294736165622"></a><a name="p2032294736165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row587622717165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">hdr_ptr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the data structure required for this function call, including the API version and the target PID. </td>
</tr>
<tr id="row422242452165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">data_ptr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the buffer space for storing the process capabilities. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table1922138204165622"></a>
<table><thead align="left"><tr id="row70755579165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p477586244165622"><a name="p477586244165622"></a><a name="p477586244165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p150453736165622"><a name="p150453736165622"></a><a name="p150453736165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1575831004165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p732497559165622"><a name="p732497559165622"></a><a name="p732497559165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p115742442165622"><a name="p115742442165622"></a><a name="p115742442165622"></a>Incorrect parameter. </p>
</td>
</tr>
<tr id="row447941448165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1198554564165622"><a name="p1198554564165622"></a><a name="p1198554564165622"></a>EPERM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p737164232165622"><a name="p737164232165622"></a><a name="p737164232165622"></a>No permission. </p>
</td>
</tr>
<tr id="row684624746165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p451504324165622"><a name="p451504324165622"></a><a name="p451504324165622"></a>EFAULT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p666154394165622"><a name="p666154394165622"></a><a name="p666154394165622"></a>Invalid memory address. </p>
</td>
</tr>
</tbody>
</table>

## capset\(\)<a name="gaaa15be01b20aff9efb09de5a8ead207e"></a>

```
int capset ([cap_user_header_t](PROCESS.md#gaf042e68224162d4eb2ce7668904831d9) hdr_ptr, const [cap_user_data_t](PROCESS.md#gaafd3aaf8bb3f786614fee86c2fa93667) data_ptr )
```

 **Description:**

Sets the capability information for a specified process based on the input parameters \(compatible with the Linux API format\). 

**Parameters:**

<a name="table1403761033165622"></a>
<table><thead align="left"><tr id="row1812820117165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1295186107165622"><a name="p1295186107165622"></a><a name="p1295186107165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p715814170165622"><a name="p715814170165622"></a><a name="p715814170165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row89290816165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">hdr_ptr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the data structure required for this function call, including the API version and the target PID. The PID can only be set to <strong id="b1961617167165622"><a name="b1961617167165622"></a><a name="b1961617167165622"></a>0</strong>, representing the current process. </td>
</tr>
<tr id="row262838602165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">data_ptr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the buffer space for storing the customized process capabilities. Currently, the following capabilities are supported (other values do not take effect): <a name="ul1656789337165622"></a><a name="ul1656789337165622"></a><ul id="ul1656789337165622"><li> <strong id="b2134323087165622"><a name="b2134323087165622"></a><a name="b2134323087165622"></a>CAP_CHOWN</strong>: changes the file ownership. </li><li> <strong id="b1743777004165622"><a name="b1743777004165622"></a><a name="b1743777004165622"></a>CAP_DAC_OVERRIDE</strong>: ignores DAC restrictions. </li><li> <strong id="b1554242421165622"><a name="b1554242421165622"></a><a name="b1554242421165622"></a>CAP_DAC_READ_SEARCH</strong>: ignores DAC restrictions on file read and search. </li><li> <strong id="b151455121165622"><a name="b151455121165622"></a><a name="b151455121165622"></a>CAP_FOWNER</strong>: allows other users (not the file owner) to modify file permission configurations. </li><li> <strong id="b1249734445165622"><a name="b1249734445165622"></a><a name="b1249734445165622"></a>CAP_KILL</strong>: allows the current process to send signals to other processes with different UIDs. </li><li> <strong id="b1261440969165622"><a name="b1261440969165622"></a><a name="b1261440969165622"></a>CAP_SETGID</strong>: allows changing the group ID of a process. </li><li> <strong id="b956674843165622"><a name="b956674843165622"></a><a name="b956674843165622"></a>CAP_SETUID</strong>: allows changing the user ID of a process. </li><li> <strong id="b590929116165622"><a name="b590929116165622"></a><a name="b590929116165622"></a>CAP_SETPCAP</strong>: allows changing the capabilities. </li><li> <strong id="b114781045165622"><a name="b114781045165622"></a><a name="b114781045165622"></a>CAP_NET_BIND_SERVICE</strong>: allows the process to be bound to a port whose number is smaller than 1024. </li><li> <strong id="b176191122165622"><a name="b176191122165622"></a><a name="b176191122165622"></a>CAP_NET_BROADCAST</strong>: allows network broadcast or multicast. </li><li> <strong id="b1872543900165622"><a name="b1872543900165622"></a><a name="b1872543900165622"></a>CAP_NET_ADMIN</strong>: allows network-related management functions. </li><li> <strong id="b1324891599165622"><a name="b1324891599165622"></a><a name="b1324891599165622"></a>CAP_NET_RAW</strong>: allows raw sockets to be used. </li><li> <strong id="b2040183126165622"><a name="b2040183126165622"></a><a name="b2040183126165622"></a>CAP_SYS_PTRACE</strong>: allows system commissioning. </li><li> <strong id="b362283017165622"><a name="b362283017165622"></a><a name="b362283017165622"></a>CAP_SYS_ADMIN</strong>: allows system management operations. </li><li> <strong id="b1407257060165622"><a name="b1407257060165622"></a><a name="b1407257060165622"></a>CAP_SYS_BOOT</strong>: allows rebooting system. </li><li> <strong id="b497045709165622"><a name="b497045709165622"></a><a name="b497045709165622"></a>CAP_SYS_NICE</strong>: allows priority increase and priority setting for other processes. </li><li> <strong id="b1368525706165622"><a name="b1368525706165622"></a><a name="b1368525706165622"></a>CAP_SYS_TIME</strong>: allows changing the system clock. </li></ul>
 The <strong id="b1581269184165622"><a name="b1581269184165622"></a><a name="b1581269184165622"></a>cap_user_data_t</strong> structure contains three members: <strong id="b187203340165622"><a name="b187203340165622"></a><a name="b187203340165622"></a>effective</strong>, <strong id="b1582640107165622"><a name="b1582640107165622"></a><a name="b1582640107165622"></a>permitted</strong>, and <strong id="b1627351773165622"><a name="b1627351773165622"></a><a name="b1627351773165622"></a>inheritable</strong>. Currently, only <strong id="b1506135604165622"><a name="b1506135604165622"></a><a name="b1506135604165622"></a>effective</strong> is valid. </td>
</tr>
</tbody>
</table>

**Attention:**

The difference between this function and the same function defined in Linux is that you can only use this function to disable capabilities for a process. 

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the creation fails. 

<a name="table196556604165622"></a>
<table><thead align="left"><tr id="row1802984421165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1982285577165622"><a name="p1982285577165622"></a><a name="p1982285577165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p701965364165622"><a name="p701965364165622"></a><a name="p701965364165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row2058416671165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p782135258165622"><a name="p782135258165622"></a><a name="p782135258165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p769955332165622"><a name="p769955332165622"></a><a name="p769955332165622"></a>Incorrect parameter. </p>
</td>
</tr>
<tr id="row201562431165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1838413306165622"><a name="p1838413306165622"></a><a name="p1838413306165622"></a>EPERM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1464650038165622"><a name="p1464650038165622"></a><a name="p1464650038165622"></a>No permission. </p>
</td>
</tr>
</tbody>
</table>

## getpriority\(\)<a name="gac2ee4921a8961060b4c7fcad8bf2b4e2"></a>

```
int getpriority (int which, [id_t](UTILS.md#gab66157aef1dc726dccc825f07239da53) who )
```

 **Description:**

Obtains the static priority of a specified ID. 

The ID type is determined by  **which**. 

**Parameters:**

<a name="table1360210210165622"></a>
<table><thead align="left"><tr id="row1944520130165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1458664154165622"><a name="p1458664154165622"></a><a name="p1458664154165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1022039629165622"><a name="p1022039629165622"></a><a name="p1022039629165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1010393438165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">which</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates a specified value, which can be: <a name="ul1568890488165622"></a><a name="ul1568890488165622"></a><ul id="ul1568890488165622"><li> PRIO_PROCESS: represents a process ID specified by <strong id="b115580547165622"><a name="b115580547165622"></a><a name="b115580547165622"></a>who</strong>. </li><li> PRIO_PGRP: represents a process group ID specified by <strong id="b623574658165622"><a name="b623574658165622"></a><a name="b623574658165622"></a>who</strong>. This value is not supported yet. </li><li> PRIO_USER: represents a valid user ID specified by <strong id="b1271226792165622"><a name="b1271226792165622"></a><a name="b1271226792165622"></a>who</strong>. This value is not supported yet. </li></ul>
 </td>
</tr>
<tr id="row234153933165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">who</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the specified ID. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the scheduling priority if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table otherwise. 

<a name="table1011578348165622"></a>
<table><thead align="left"><tr id="row1063181390165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1075314581165622"><a name="p1075314581165622"></a><a name="p1075314581165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1889272689165622"><a name="p1889272689165622"></a><a name="p1889272689165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1855359592165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p877568129165622"><a name="p877568129165622"></a><a name="p877568129165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p854694059165622"><a name="p854694059165622"></a><a name="p854694059165622"></a>Invalid parameter. </p>
</td>
</tr>
<tr id="row1467848166165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1873424949165622"><a name="p1873424949165622"></a><a name="p1873424949165622"></a>EOPNOTSUPP </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p602636488165622"><a name="p602636488165622"></a><a name="p602636488165622"></a>Unsupported value. </p>
</td>
</tr>
</tbody>
</table>

## ohos\_capget\(\)<a name="gaf254b29504e9733ff55014acdf5fbcc7"></a>

```
int ohos_capget ([pid_t](UTILS.md#ga30c34d3eead853c44f459f21b932984c) pid, unsigned int * caps )
```

 **Description:**

Obtains the capability information of the specified process process based on the input parameters. 

**Parameters:**

<a name="table1098508497165622"></a>
<table><thead align="left"><tr id="row421995643165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p613314636165622"><a name="p613314636165622"></a><a name="p613314636165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1915898941165622"><a name="p1915898941165622"></a><a name="p1915898941165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row578832300165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">pid</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the specified process. </td>
</tr>
<tr id="row1105783133165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">caps</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the memory address for storing the obtained capability information of a specified process. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table1764121218165622"></a>
<table><thead align="left"><tr id="row127126654165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2120941912165622"><a name="p2120941912165622"></a><a name="p2120941912165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p898476913165622"><a name="p898476913165622"></a><a name="p898476913165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1144363309165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1599603442165622"><a name="p1599603442165622"></a><a name="p1599603442165622"></a>EFAULT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p373957643165622"><a name="p373957643165622"></a><a name="p373957643165622"></a>Invalid memory address. </p>
</td>
</tr>
</tbody>
</table>

## ohos\_capset\(\)<a name="ga77ad7758babf522e7ffb28551332a659"></a>

```
int ohos_capset (unsigned int caps)
```

 **Description:**

Sets the capability information of the current process based on the input parameters. 

**Parameters:**

<a name="table1825011764165622"></a>
<table><thead align="left"><tr id="row1531275182165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1185093743165622"><a name="p1185093743165622"></a><a name="p1185093743165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p278833956165622"><a name="p278833956165622"></a><a name="p278833956165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2108971756165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">caps</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the customized capability information of the process. Currently, the following capabilities are supported (other values do not take effect): <a name="ul184240606165622"></a><a name="ul184240606165622"></a><ul id="ul184240606165622"><li> <strong id="b339662619165622"><a name="b339662619165622"></a><a name="b339662619165622"></a>OHOS_CAP_CHOWN</strong>: changes the file ownership. </li><li> <strong id="b248274618165622"><a name="b248274618165622"></a><a name="b248274618165622"></a>OHOS_CAP_DAC_EXECUTE</strong>: ignores discretionary access control (DAC) restrictions on file execution. </li><li> <strong id="b144131781165622"><a name="b144131781165622"></a><a name="b144131781165622"></a>OHOS_CAP_DAC_WRITE</strong>: ignores DAC restrictions on file write. </li><li> <strong id="b2021647156165622"><a name="b2021647156165622"></a><a name="b2021647156165622"></a>OHOS_CAP_DAC_READ_SEARCH</strong>: ignores DAC restrictions on file read and search. </li><li> <strong id="b1340261345165622"><a name="b1340261345165622"></a><a name="b1340261345165622"></a>OHOS_CAP_FOWNER</strong>: allows other users (not the file owner) to modify file permission configurations. </li><li> <strong id="b1885490445165622"><a name="b1885490445165622"></a><a name="b1885490445165622"></a>OHOS_CAP_KILL</strong>: allows the current process to send signals to other processes with different UIDs. </li><li> <strong id="b746338831165622"><a name="b746338831165622"></a><a name="b746338831165622"></a>OHOS_CAP_SETGID</strong>: allows changing the group ID of the process. </li><li> <strong id="b934864369165622"><a name="b934864369165622"></a><a name="b934864369165622"></a>OHOS_CAP_SETUID</strong>: allows changing the user ID of the process. </li><li> <strong id="b165382646165622"><a name="b165382646165622"></a><a name="b165382646165622"></a>OHOS_CAP_NET_BIND_SERVICE</strong>: allows the process to be bound to a port whose number is smaller than 1024. </li><li> <strong id="b714123273165622"><a name="b714123273165622"></a><a name="b714123273165622"></a>OHOS_CAP_NET_BROADCAST</strong>: allows network broadcast and multicast. </li><li> <strong id="b1591106871165622"><a name="b1591106871165622"></a><a name="b1591106871165622"></a>OHOS_CAP_NET_ADMIN</strong>: allows network-related management functions. </li><li> <strong id="b1231966714165622"><a name="b1231966714165622"></a><a name="b1231966714165622"></a>OHOS_CAP_NET_RAW</strong>: allows raw sockets to be used. </li><li> <strong id="b284686320165622"><a name="b284686320165622"></a><a name="b284686320165622"></a>OHOS_CAP_FS_MOUNT</strong>: allows mounting operations. </li><li> <strong id="b1750369363165622"><a name="b1750369363165622"></a><a name="b1750369363165622"></a>OHOS_CAP_FS_FORMAT</strong>: allows storage formatting operations. </li><li> <strong id="b7765722165622"><a name="b7765722165622"></a><a name="b7765722165622"></a>OHOS_CAP_SCHED_SETPRIORITY</strong>: allows priority increase and priority setting for other processes. </li><li> <strong id="b907378155165622"><a name="b907378155165622"></a><a name="b907378155165622"></a>OHOS_CAP_SET_TIMEOFDAY</strong>: allows calling of the timeofday API. </li><li> <strong id="b2053363331165622"><a name="b2053363331165622"></a><a name="b2053363331165622"></a>OHOS_CAP_CLOCK_SETTIME</strong>: allows calling of the clock_settime API. </li><li> <strong id="b1144340402165622"><a name="b1144340402165622"></a><a name="b1144340402165622"></a>OHOS_CAP_CAPSET</strong>: allows changing the capabilities. </li><li> <strong id="b1947802046165622"><a name="b1947802046165622"></a><a name="b1947802046165622"></a>OHOS_CAP_REBOOT</strong>: allows rebooting system. </li><li> <strong id="b1154686791165622"><a name="b1154686791165622"></a><a name="b1154686791165622"></a>OHOS_CAP_SHELL_EXEC</strong>: allows calling of the shellexec API. </li></ul>
 </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the creation fails. 

<a name="table1476960078165622"></a>
<table><thead align="left"><tr id="row319040241165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p301075402165622"><a name="p301075402165622"></a><a name="p301075402165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1392709909165622"><a name="p1392709909165622"></a><a name="p1392709909165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1864733756165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p17377984165622"><a name="p17377984165622"></a><a name="p17377984165622"></a>EPERM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1592846764165622"><a name="p1592846764165622"></a><a name="p1592846764165622"></a>No permission. </p>
</td>
</tr>
</tbody>
</table>

## pthread\_atfork\(\)<a name="ga80008474c3d68e9880da960a53d2f430"></a>

```
int pthread_atfork (void(*)(void) prepare, void(*)(void) parent, void(*)(void) child )
```

 **Description:**

Registers a fork handler to be called before and after  [fork\(\)](UTILS.md#gaa4e4714e6e8927c80b2553a40094b6d9). 

**Parameters:**

<a name="table1435413595165622"></a>
<table><thead align="left"><tr id="row2103734560165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p379071918165622"><a name="p379071918165622"></a><a name="p379071918165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1429336548165622"><a name="p1429336548165622"></a><a name="p1429336548165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1073882523165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">prepare</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the fork handler to be called before <a href="UTILS.md#gaa4e4714e6e8927c80b2553a40094b6d9">fork()</a>. </td>
</tr>
<tr id="row153323831165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">parent</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the fork handler to be called after <a href="UTILS.md#gaa4e4714e6e8927c80b2553a40094b6d9">fork()</a> in the parent process. </td>
</tr>
<tr id="row1229547007165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">child</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the fork handler to be called after <a href="UTILS.md#gaa4e4714e6e8927c80b2553a40094b6d9">fork()</a> in the child process. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  otherwise. 

## pthread\_attr\_destroy\(\)<a name="ga4bcdbf47c17c7dcc51e9f05f5cb56d81"></a>

```
int pthread_attr_destroy ([pthread_attr_t](UTILS.md#gac8ee4471bbc35deb7589ac3615deb486) * attr)
```

 **Description:**

Destroys a thread attribute object. 

This function always succeeds. 

**Parameters:**

<a name="table1681529692165622"></a>
<table><thead align="left"><tr id="row1475804791165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p38832946165622"><a name="p38832946165622"></a><a name="p38832946165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p298653283165622"><a name="p298653283165622"></a><a name="p298653283165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1566806720165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">attr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the thread attribute object to destroy. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**. 

## pthread\_attr\_getdetachstate\(\)<a name="ga391c34da42e68ddd24f5ee0c070d5c4f"></a>

```
int pthread_attr_getdetachstate (const [pthread_attr_t](UTILS.md#gac8ee4471bbc35deb7589ac3615deb486) * attr, int * detachstate )
```

 **Description:**

Obtains the detach state of a thread attribute object. 

This function always succeeds. 

**Parameters:**

<a name="table1326939487165622"></a>
<table><thead align="left"><tr id="row255978505165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1946207124165622"><a name="p1946207124165622"></a><a name="p1946207124165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1660342900165622"><a name="p1660342900165622"></a><a name="p1660342900165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row485833912165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">attr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the target thread attribute object. </td>
</tr>
<tr id="row1431931442165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">detachstate</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the obtained detach state. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**. 

## pthread\_attr\_getguardsize\(\)<a name="gaa8b692ecc3880fdd49a4d423ba1ce91e"></a>

```
int pthread_attr_getguardsize (const [pthread_attr_t](UTILS.md#gac8ee4471bbc35deb7589ac3615deb486) * attr, size_t * guardsize )
```

 **Description:**

Obtains the guard size of a thread attribute object. 

This function always succeeds. 

**Parameters:**

<a name="table607183964165622"></a>
<table><thead align="left"><tr id="row449972886165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2092358677165622"><a name="p2092358677165622"></a><a name="p2092358677165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1153300602165622"><a name="p1153300602165622"></a><a name="p1153300602165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1704055141165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">attr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the target thread attribute object. </td>
</tr>
<tr id="row630358074165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">guardsize</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the obtained guard size. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**. 

## pthread\_attr\_getinheritsched\(\)<a name="ga79a77b688c30213e5e52e6be178cde4e"></a>

```
int pthread_attr_getinheritsched (const [pthread_attr_t](UTILS.md#gac8ee4471bbc35deb7589ac3615deb486) * attr, int * inheritsched )
```

 **Description:**

Obtains inherit scheduler attributes of a thread attribute object. 

This function always succeeds. 

**Parameters:**

<a name="table2132297403165622"></a>
<table><thead align="left"><tr id="row379511297165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p74510005165622"><a name="p74510005165622"></a><a name="p74510005165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p820763790165622"><a name="p820763790165622"></a><a name="p820763790165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row695510106165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">attr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the target thread attribute object. </td>
</tr>
<tr id="row1655508437165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">inheritsched</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the obtained inherit scheduler attributes. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**. 

## pthread\_attr\_getschedparam\(\)<a name="gafd3d272d702481044f8a8cd253fd9b47"></a>

```
int pthread_attr_getschedparam (const [pthread_attr_t](UTILS.md#gac8ee4471bbc35deb7589ac3615deb486) * attr, struct [sched_param](sched_param.md) * param )
```

 **Description:**

Obtains scheduling parameter attributes of a thread attribute object. 

This function always succeeds. 

**Parameters:**

<a name="table2068017938165622"></a>
<table><thead align="left"><tr id="row1277780651165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p228722647165622"><a name="p228722647165622"></a><a name="p228722647165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1249924593165622"><a name="p1249924593165622"></a><a name="p1249924593165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row137374281165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">attr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the target thread attribute object. </td>
</tr>
<tr id="row544193518165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">param</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the obtained scheduling parameter attributes. Only the thread priority is supported. The priority ranges from 0 (highest priority) to 31 (lowest priority). </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**. 

## pthread\_attr\_getschedpolicy\(\)<a name="gaec4d8127833d1a573aa82539f898a8ed"></a>

```
int pthread_attr_getschedpolicy (const [pthread_attr_t](UTILS.md#gac8ee4471bbc35deb7589ac3615deb486) * attr, int * schedpolicy )
```

 **Description:**

Obtains scheduling policy attributes of a thread attribute object. 

This function always succeeds. 

**Parameters:**

<a name="table571916380165622"></a>
<table><thead align="left"><tr id="row83158729165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2061548257165622"><a name="p2061548257165622"></a><a name="p2061548257165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p274715010165622"><a name="p274715010165622"></a><a name="p274715010165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1206274414165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">attr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the target thread attribute object. </td>
</tr>
<tr id="row1420901283165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">schedpolicy</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the obtained scheduling policy attributes. Only <strong id="b1255080423165622"><a name="b1255080423165622"></a><a name="b1255080423165622"></a>SCHED_FIFO</strong> and <strong id="b385207917165622"><a name="b385207917165622"></a><a name="b385207917165622"></a>SCHED_RR</strong> are supported. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**. 

## pthread\_attr\_getscope\(\)<a name="gabfd252cd45081231018030e3878efa06"></a>

```
int pthread_attr_getscope (const [pthread_attr_t](UTILS.md#gac8ee4471bbc35deb7589ac3615deb486) * attr, int * scope )
```

 **Description:**

Obtains contention scope attributes of a thread attribute object. 

**Parameters:**

<a name="table1082173148165622"></a>
<table><thead align="left"><tr id="row1270326973165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p602758186165622"><a name="p602758186165622"></a><a name="p602758186165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p441283539165622"><a name="p441283539165622"></a><a name="p441283539165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row58981639165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">attr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the target thread attribute object. </td>
</tr>
<tr id="row119239348165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">scope</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the start address of the buffer that stores the target thread attribute object. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a value listed in  **errno**  otherwise. 

<a name="table494906216165622"></a>
<table><thead align="left"><tr id="row329400559165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1306820613165622"><a name="p1306820613165622"></a><a name="p1306820613165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p471724029165622"><a name="p471724029165622"></a><a name="p471724029165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1357884409165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1402535578165622"><a name="p1402535578165622"></a><a name="p1402535578165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1511885769165622"><a name="p1511885769165622"></a><a name="p1511885769165622"></a>Invalid <strong id="b900405599165622"><a name="b900405599165622"></a><a name="b900405599165622"></a>scope</strong> value. </p>
</td>
</tr>
</tbody>
</table>

## pthread\_attr\_getstack\(\)<a name="gaec19ad460995a9fe8aeb4eaf2bb1ed1d"></a>

```
int pthread_attr_getstack (const [pthread_attr_t](UTILS.md#gac8ee4471bbc35deb7589ac3615deb486) * attr, void ** stackaddr, size_t * stacksize )
```

 **Description:**

Obtains stack attributes of a thread attribute object. 

**Parameters:**

<a name="table1468054529165622"></a>
<table><thead align="left"><tr id="row201440617165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1476642130165622"><a name="p1476642130165622"></a><a name="p1476642130165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1600071177165622"><a name="p1600071177165622"></a><a name="p1600071177165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1086023897165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">attr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the target thread attribute object. </td>
</tr>
<tr id="row254621118165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">stackaddr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double pointer to the start address of the buffer that stores the obtained stack attributes. </td>
</tr>
<tr id="row770733025165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">stacksize</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the size of the buffer that stores the obtained stack attributes. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a value listed in  **errno**  otherwise. 

<a name="table793676970165622"></a>
<table><thead align="left"><tr id="row1189632798165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p259535854165622"><a name="p259535854165622"></a><a name="p259535854165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p497717641165622"><a name="p497717641165622"></a><a name="p497717641165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1946155172165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1886226422165622"><a name="p1886226422165622"></a><a name="p1886226422165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1641752543165622"><a name="p1641752543165622"></a><a name="p1641752543165622"></a>Invalid start address. </p>
</td>
</tr>
</tbody>
</table>

## pthread\_attr\_getstacksize\(\)<a name="gae23600d4670359ab12bfba20db2c9a37"></a>

```
int pthread_attr_getstacksize (const [pthread_attr_t](UTILS.md#gac8ee4471bbc35deb7589ac3615deb486) * attr, size_t * stacksize )
```

 **Description:**

Obtains the stack size of a thread attribute object. 

Obtains the stack size of the thread attribute object. The stack size of a thread has been specified when creating the thread. Only the main thread can have its stack size dynamically increased. 

**Parameters:**

<a name="table151566549165622"></a>
<table><thead align="left"><tr id="row61759101165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1191925166165622"><a name="p1191925166165622"></a><a name="p1191925166165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1440074869165622"><a name="p1440074869165622"></a><a name="p1440074869165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1581815730165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">attr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the target thread attribute object. </td>
</tr>
<tr id="row1352636199165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">stacksize</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the obtained stack size. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a value listed in  **errno**  otherwise. 

<a name="table1542977755165622"></a>
<table><thead align="left"><tr id="row1183405497165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1907211162165622"><a name="p1907211162165622"></a><a name="p1907211162165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1847972915165622"><a name="p1847972915165622"></a><a name="p1847972915165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1002858771165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1340508801165622"><a name="p1340508801165622"></a><a name="p1340508801165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p445518314165622"><a name="p445518314165622"></a><a name="p445518314165622"></a>The stack size has not been specified. </p>
</td>
</tr>
</tbody>
</table>

## pthread\_attr\_init\(\)<a name="ga0b85ebb1e3aac081a4c0a5e85ae3cbe9"></a>

```
int pthread_attr_init ([pthread_attr_t](UTILS.md#gac8ee4471bbc35deb7589ac3615deb486) * attr)
```

 **Description:**

Initializes a thread attribute object. 

This function always succeeds. 

**Parameters:**

<a name="table389263724165622"></a>
<table><thead align="left"><tr id="row1320759310165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p619588913165622"><a name="p619588913165622"></a><a name="p619588913165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p697703853165622"><a name="p697703853165622"></a><a name="p697703853165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row146619409165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">attr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the thread attribute object that is successfully initialized. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**. 

## pthread\_attr\_setdetachstate\(\)<a name="gae6ee78c307d8467b34a9b0c330993a54"></a>

```
int pthread_attr_setdetachstate ([pthread_attr_t](UTILS.md#gac8ee4471bbc35deb7589ac3615deb486) * attr, int detachstate )
```

 **Description:**

Sets the detach state for a thread attribute object. 

**Parameters:**

<a name="table356741262165622"></a>
<table><thead align="left"><tr id="row906445113165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1319914516165622"><a name="p1319914516165622"></a><a name="p1319914516165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1293682643165622"><a name="p1293682643165622"></a><a name="p1293682643165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2037672844165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">attr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the target thread attribute object. </td>
</tr>
<tr id="row304508862165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">detachstate</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the detach state to set. Available values are as follows: </td>
</tr>
</tbody>
</table>

<a name="table1335418389165622"></a>
<table><thead align="left"><tr id="row350010165165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1543920889165622"><a name="p1543920889165622"></a><a name="p1543920889165622"></a>detachstate </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1564850705165622"><a name="p1564850705165622"></a><a name="p1564850705165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1652979780165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2011847115165622"><a name="p2011847115165622"></a><a name="p2011847115165622"></a>PTHREAD_CREATE_DETACHED </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1427708196165622"><a name="p1427708196165622"></a><a name="p1427708196165622"></a>Threads using <strong id="b684232246165622"><a name="b684232246165622"></a><a name="b684232246165622"></a>attr</strong> are created in the detached state. </p>
</td>
</tr>
<tr id="row634018678165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p641908328165622"><a name="p641908328165622"></a><a name="p641908328165622"></a>PTHREAD_CREATE_JOINABLE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2070486236165622"><a name="p2070486236165622"></a><a name="p2070486236165622"></a>Threads using <strong id="b2108897585165622"><a name="b2108897585165622"></a><a name="b2108897585165622"></a>attr</strong> are created in the joinable state. </p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a value listed in  **errno**  otherwise. 

<a name="table1725281590165622"></a>
<table><thead align="left"><tr id="row2125575886165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p92618768165622"><a name="p92618768165622"></a><a name="p92618768165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1627396252165622"><a name="p1627396252165622"></a><a name="p1627396252165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row460815163165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1726995254165622"><a name="p1726995254165622"></a><a name="p1726995254165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1861547913165622"><a name="p1861547913165622"></a><a name="p1861547913165622"></a>Invalid detach state. </p>
</td>
</tr>
</tbody>
</table>

## pthread\_attr\_setguardsize\(\)<a name="ga532b31c11a9d87663053c5342400758c"></a>

```
int pthread_attr_setguardsize ([pthread_attr_t](UTILS.md#gac8ee4471bbc35deb7589ac3615deb486) * attr, size_t guardsize )
```

 **Description:**

Sets the guard size for a thread attribute object. 

**Parameters:**

<a name="table91680558165622"></a>
<table><thead align="left"><tr id="row1237895062165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1276713130165622"><a name="p1276713130165622"></a><a name="p1276713130165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p791472235165622"><a name="p791472235165622"></a><a name="p791472235165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2017442839165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">attr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the target thread attribute object. </td>
</tr>
<tr id="row491117461165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">guardsize</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the guard size to set. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a value listed in  **errno**  otherwise. 

<a name="table262667064165622"></a>
<table><thead align="left"><tr id="row784707610165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p939200185165622"><a name="p939200185165622"></a><a name="p939200185165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p263536086165622"><a name="p263536086165622"></a><a name="p263536086165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1386171691165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p936899964165622"><a name="p936899964165622"></a><a name="p936899964165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1462032170165622"><a name="p1462032170165622"></a><a name="p1462032170165622"></a>Invalid guard size. </p>
</td>
</tr>
</tbody>
</table>

## pthread\_attr\_setinheritsched\(\)<a name="gad437fe8caa3ef9f0cb7d69f6f6479df9"></a>

```
int pthread_attr_setinheritsched ([pthread_attr_t](UTILS.md#gac8ee4471bbc35deb7589ac3615deb486) * attr, int inheritsched )
```

 **Description:**

Sets inherit scheduler attributes for a thread attribute object. 

**Parameters:**

<a name="table1933932634165622"></a>
<table><thead align="left"><tr id="row1384755276165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p556878518165622"><a name="p556878518165622"></a><a name="p556878518165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1820583407165622"><a name="p1820583407165622"></a><a name="p1820583407165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2115625156165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">attr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the target thread attribute object. </td>
</tr>
<tr id="row835063865165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">inheritsched</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the inherit scheduler attributes to set. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a value listed in  **errno**  otherwise. 

<a name="table1600718659165622"></a>
<table><thead align="left"><tr id="row832752929165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p416462058165622"><a name="p416462058165622"></a><a name="p416462058165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p264014853165622"><a name="p264014853165622"></a><a name="p264014853165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1169082404165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p202928867165622"><a name="p202928867165622"></a><a name="p202928867165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1341139096165622"><a name="p1341139096165622"></a><a name="p1341139096165622"></a>Invalid inherit scheduler attribute. </p>
</td>
</tr>
</tbody>
</table>

## pthread\_attr\_setschedparam\(\)<a name="ga579e6529f0ce482312a5e77ac61cb4d5"></a>

```
int pthread_attr_setschedparam ([pthread_attr_t](UTILS.md#gac8ee4471bbc35deb7589ac3615deb486) * attr, const struct [sched_param](sched_param.md) * param )
```

 **Description:**

Sets scheduling parameter attributes for a thread attribute object. 

**Parameters:**

<a name="table2022714244165622"></a>
<table><thead align="left"><tr id="row1272901768165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p268111224165622"><a name="p268111224165622"></a><a name="p268111224165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1316597782165622"><a name="p1316597782165622"></a><a name="p1316597782165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row309718415165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">attr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the target thread attribute object. </td>
</tr>
<tr id="row1110592173165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">param</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the scheduling parameter attributes to set. Only the thread priority is supported. The priority ranges from 0 (highest priority) to 31 (lowest priority). </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a value listed in  **errno**  otherwise. 

<a name="table1533797405165622"></a>
<table><thead align="left"><tr id="row1164499410165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p156706747165622"><a name="p156706747165622"></a><a name="p156706747165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p756934382165622"><a name="p756934382165622"></a><a name="p756934382165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row826048763165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1434840553165622"><a name="p1434840553165622"></a><a name="p1434840553165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p802972122165622"><a name="p802972122165622"></a><a name="p802972122165622"></a>Invalid scheduling parameter attributes. </p>
</td>
</tr>
</tbody>
</table>

## pthread\_attr\_setschedpolicy\(\)<a name="gab6cb2eb73f04abf328b2f39777c35dca"></a>

```
int pthread_attr_setschedpolicy ([pthread_attr_t](UTILS.md#gac8ee4471bbc35deb7589ac3615deb486) * attr, int schedpolicy )
```

 **Description:**

Sets scheduling policy attributes for a thread attribute object. 

**Parameters:**

<a name="table533063322165622"></a>
<table><thead align="left"><tr id="row1479995778165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1390524868165622"><a name="p1390524868165622"></a><a name="p1390524868165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2146571072165622"><a name="p2146571072165622"></a><a name="p2146571072165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1704601500165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">attr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the target thread attribute object. </td>
</tr>
<tr id="row1522077605165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">schedpolicy</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the scheduling policy attributes to set. Only <strong id="b421629045165622"><a name="b421629045165622"></a><a name="b421629045165622"></a>SCHED_FIFO</strong> and <strong id="b427580929165622"><a name="b427580929165622"></a><a name="b427580929165622"></a>SCHED_RR</strong> are supported. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a value listed in  **errno**  otherwise. 

<a name="table1143215677165622"></a>
<table><thead align="left"><tr id="row143979297165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1290261597165622"><a name="p1290261597165622"></a><a name="p1290261597165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1407070402165622"><a name="p1407070402165622"></a><a name="p1407070402165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row422860726165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1355992912165622"><a name="p1355992912165622"></a><a name="p1355992912165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p297957313165622"><a name="p297957313165622"></a><a name="p297957313165622"></a>Invalid scheduling policy attribute. </p>
</td>
</tr>
</tbody>
</table>

## pthread\_attr\_setscope\(\)<a name="ga294aaacf59f34effeef978242cf08cbe"></a>

```
int pthread_attr_setscope ([pthread_attr_t](UTILS.md#gac8ee4471bbc35deb7589ac3615deb486) * attr, int scope )
```

 **Description:**

Sets contention scope attributes for a thread attribute object. 

The contention scope attribute defines a set of threads against which a thread competes for resources such as the CPU. POSIX.1-2001 specifies two values for  **scope**: 

POSIX.1-2001 does not specify how these threads contend with other threads in other process on the system or with other threads in the same process that were created with the  **PTHREAD\_SCOPE\_SYSTEM**  contention scope. 

**Parameters:**

<a name="table1532315279165622"></a>
<table><thead align="left"><tr id="row1687235204165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1791562125165622"><a name="p1791562125165622"></a><a name="p1791562125165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p549579116165622"><a name="p549579116165622"></a><a name="p549579116165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row703649686165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">attr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the target thread attribute object. </td>
</tr>
<tr id="row499455087165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">scope</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the start address of the buffer that stores the target thread attribute object. By default, only <strong id="b990488382165622"><a name="b990488382165622"></a><a name="b990488382165622"></a>PTHREAD_SCOPE_PROCESS</strong> is supported. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a value listed in  **errno**  otherwise. 

<a name="table1874332352165622"></a>
<table><thead align="left"><tr id="row1856821574165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1514412063165622"><a name="p1514412063165622"></a><a name="p1514412063165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1083390105165622"><a name="p1083390105165622"></a><a name="p1083390105165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1178657716165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1339090284165622"><a name="p1339090284165622"></a><a name="p1339090284165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1091322513165622"><a name="p1091322513165622"></a><a name="p1091322513165622"></a>Invalid <strong id="b2087501172165622"><a name="b2087501172165622"></a><a name="b2087501172165622"></a>scope</strong> value. </p>
</td>
</tr>
</tbody>
</table>

## pthread\_attr\_setstack\(\)<a name="ga94ede89b99a3a4fa17e516d30aaf3409"></a>

```
int pthread_attr_setstack ([pthread_attr_t](UTILS.md#gac8ee4471bbc35deb7589ac3615deb486) * attr, void * stackaddr, size_t stacksize )
```

 **Description:**

Sets stack attributes for a thread attribute object. 

**Parameters:**

<a name="table448620247165622"></a>
<table><thead align="left"><tr id="row424848279165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1998701471165622"><a name="p1998701471165622"></a><a name="p1998701471165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1152813879165622"><a name="p1152813879165622"></a><a name="p1152813879165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row557872820165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">attr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the thread attribute object. </td>
</tr>
<tr id="row167982643165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">stackaddr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the start address of the buffer that stores the stack attributes to set. </td>
</tr>
<tr id="row1080902831165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">stacksize</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the size of the buffer that stores the stack attributes to set. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a value listed in  **errno**  otherwise. 

<a name="table282482764165622"></a>
<table><thead align="left"><tr id="row1295105164165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p46921255165622"><a name="p46921255165622"></a><a name="p46921255165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1304827719165622"><a name="p1304827719165622"></a><a name="p1304827719165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row2025106186165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p412736718165622"><a name="p412736718165622"></a><a name="p412736718165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1447611299165622"><a name="p1447611299165622"></a><a name="p1447611299165622"></a>Invalid start address. </p>
</td>
</tr>
</tbody>
</table>

## pthread\_attr\_setstacksize\(\)<a name="ga812a9a455ae2ef2bb0dca4fff201a281"></a>

```
int pthread_attr_setstacksize ([pthread_attr_t](UTILS.md#gac8ee4471bbc35deb7589ac3615deb486) * attr, size_t stacksize )
```

 **Description:**

Sets the stack size for a thread attribute object. 

This function always succeeds. 

**Parameters:**

<a name="table1419450888165622"></a>
<table><thead align="left"><tr id="row1640897737165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1418539130165622"><a name="p1418539130165622"></a><a name="p1418539130165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1152803183165622"><a name="p1152803183165622"></a><a name="p1152803183165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row590262539165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">attr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the target thread attribute object. </td>
</tr>
<tr id="row1220850712165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">stacksize</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the stack size. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a value listed in  **errno**  otherwise. 

<a name="table289001968165622"></a>
<table><thead align="left"><tr id="row357049936165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1717236371165622"><a name="p1717236371165622"></a><a name="p1717236371165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1755696774165622"><a name="p1755696774165622"></a><a name="p1755696774165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row2068654467165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p934400125165622"><a name="p934400125165622"></a><a name="p934400125165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2133163489165622"><a name="p2133163489165622"></a><a name="p2133163489165622"></a>Invalid stack size. </p>
</td>
</tr>
</tbody>
</table>

## pthread\_barrier\_destroy\(\)<a name="gab05ae13769e61dea9c53ca7894743c8f"></a>

```
int pthread_barrier_destroy ([pthread_barrier_t](UTILS.md#ga2f6d30b3b873012dbd361d3f7d52db59) * b)
```

 **Description:**

Destroys a barrier. 

This function always succeeds. 

**Parameters:**

<a name="table108120066165622"></a>
<table><thead align="left"><tr id="row153724511165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2130462641165622"><a name="p2130462641165622"></a><a name="p2130462641165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p541566118165622"><a name="p541566118165622"></a><a name="p541566118165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row48693344165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">b</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the barrier to destroy. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**. 

## pthread\_barrier\_init\(\)<a name="ga4a324cd758cae702213ea41882f4cf41"></a>

```
int pthread_barrier_init ([pthread_barrier_t](UTILS.md#ga2f6d30b3b873012dbd361d3f7d52db59) *__restrict b, const [pthread_barrierattr_t](UTILS.md#ga506b5743098d9d38526b2fd1e21f9457) *__restrict a, unsigned count )
```

 **Description:**

Initializes a barrier. 

**Parameters:**

<a name="table1905685366165622"></a>
<table><thead align="left"><tr id="row1676696965165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1859987278165622"><a name="p1859987278165622"></a><a name="p1859987278165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p361667934165622"><a name="p361667934165622"></a><a name="p361667934165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row412328182165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">b</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the barrier to initialize. </td>
</tr>
<tr id="row42102678165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">a</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the barrier attribute object. If this parameter is set to <strong id="b281707548165622"><a name="b281707548165622"></a><a name="b281707548165622"></a>NULL</strong>, the default barrier attributes are used. </td>
</tr>
<tr id="row1439933248165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">count</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the number of threads that must call <a href="PROCESS.md#gaf786372165ba080986ae4143928c5436">pthread_barrier_wait()</a> before any of them successfully returns from the call. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a value listed in  **errno**  otherwise. 

<a name="table1956817960165622"></a>
<table><thead align="left"><tr id="row1167873189165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1954364474165622"><a name="p1954364474165622"></a><a name="p1954364474165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1419204315165622"><a name="p1419204315165622"></a><a name="p1419204315165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row472684966165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p183045473165622"><a name="p183045473165622"></a><a name="p183045473165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p306121286165622"><a name="p306121286165622"></a><a name="p306121286165622"></a>The value of <strong id="b2102582539165622"><a name="b2102582539165622"></a><a name="b2102582539165622"></a>count </strong> is greater than the maximum number of threads to block. </p>
</td>
</tr>
</tbody>
</table>

## pthread\_barrier\_wait\(\)<a name="gaf786372165ba080986ae4143928c5436"></a>

```
int pthread_barrier_wait ([pthread_barrier_t](UTILS.md#ga2f6d30b3b873012dbd361d3f7d52db59) * b)
```

 **Description:**

Synchronizes participating threads at a barrier. 

The call is blocked until the required number of threads have called this function with the specified barrier. 

**Parameters:**

<a name="table1493481894165622"></a>
<table><thead align="left"><tr id="row456714092165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p270629336165622"><a name="p270629336165622"></a><a name="p270629336165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1514163378165622"><a name="p1514163378165622"></a><a name="p1514163378165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1627500231165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">b</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the barrier to be used for synchronization. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **PTHREAD\_BARRIER\_SERIAL\_THREAD**  for the first restored thread and  **0**  for other threads. 

## pthread\_barrierattr\_destroy\(\)<a name="ga3bd99d89e352ccc51d5b94d157f1218b"></a>

```
int pthread_barrierattr_destroy ([pthread_barrierattr_t](UTILS.md#ga506b5743098d9d38526b2fd1e21f9457) * a)
```

 **Description:**

Destroys a barrier attribute object. 

This function always succeeds. 

**Parameters:**

<a name="table666068324165622"></a>
<table><thead align="left"><tr id="row767780896165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1778959404165622"><a name="p1778959404165622"></a><a name="p1778959404165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1003546982165622"><a name="p1003546982165622"></a><a name="p1003546982165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row107240906165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">a</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the barrier attribute object to destroy. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**. 

## pthread\_barrierattr\_init\(\)<a name="ga2ff720e06488668dc0ae6779755946e6"></a>

```
int pthread_barrierattr_init ([pthread_barrierattr_t](UTILS.md#ga506b5743098d9d38526b2fd1e21f9457) * a)
```

 **Description:**

Initializes a barrier attribute object. 

This function always succeeds. 

**Parameters:**

<a name="table1106563725165622"></a>
<table><thead align="left"><tr id="row1479771897165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1068432075165622"><a name="p1068432075165622"></a><a name="p1068432075165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1639295335165622"><a name="p1639295335165622"></a><a name="p1639295335165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1874177790165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">a</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the barrier attribute object to initialize. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**. 

## pthread\_cancel\(\)<a name="ga9e77a80c073787bf9a593e9c619dce27"></a>

```
int pthread_cancel ([pthread_t](UTILS.md#ga5250f47a8a0402a78bb51a2133e13c1f) thread)
```

 **Description:**

Sends a cancellation request to a thread. 

**Parameters:**

<a name="table715390134165622"></a>
<table><thead align="left"><tr id="row970844649165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1267200043165622"><a name="p1267200043165622"></a><a name="p1267200043165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1602390932165622"><a name="p1602390932165622"></a><a name="p1602390932165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1552906179165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">thread</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the thread to receive the cancellation request. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a value listed in  **errno**  otherwise. 

<a name="table2050287043165622"></a>
<table><thead align="left"><tr id="row2135380525165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p37150400165622"><a name="p37150400165622"></a><a name="p37150400165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p956959665165622"><a name="p956959665165622"></a><a name="p956959665165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1462092016165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1133285641165622"><a name="p1133285641165622"></a><a name="p1133285641165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p599035687165622"><a name="p599035687165622"></a><a name="p599035687165622"></a>Invalid parameter. </p>
</td>
</tr>
</tbody>
</table>

## pthread\_cleanup\_pop\(\)<a name="gafbe33fb00cd24693796a0870a3374631"></a>

```
void pthread_cleanup_pop (int execute)
```

 **Description:**

Removes the routine at the top of the clean-up handler stack. 

**Parameters:**

<a name="table1889105967165622"></a>
<table><thead align="left"><tr id="row2027214429165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p201282631165622"><a name="p201282631165622"></a><a name="p201282631165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1488538237165622"><a name="p1488538237165622"></a><a name="p1488538237165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row894954978165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">execute</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Specifies whether the routine at the top of the clean-up handler stack should be executed. If this parameter is set to a non-zero value, the routine at the top of the clean-up handler stack must be popped and executed. </td>
</tr>
</tbody>
</table>

## pthread\_cleanup\_push\(\)<a name="ga68bc26522daf418f3cc78360925374ef"></a>

```
void pthread_cleanup_push (void(*)(void *) routine, void * arg )
```

 **Description:**

Pushes the routine to the top of the clean-up handler stack. 

**Parameters:**

<a name="table633300027165622"></a>
<table><thead align="left"><tr id="row265120224165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1889051905165622"><a name="p1889051905165622"></a><a name="p1889051905165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p907495290165622"><a name="p907495290165622"></a><a name="p907495290165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1343744402165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">routine</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the routine used to complete the clean-up. </td>
</tr>
<tr id="row2097126687165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">arg</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the parameter to be passed to the routine. </td>
</tr>
</tbody>
</table>

## pthread\_cond\_broadcast\(\)<a name="ga1c1ac7c8faaf8ad63e12bc3717f430f3"></a>

```
int pthread_cond_broadcast ([pthread_cond_t](UTILS.md#gaf2111a9da165bafea75dabf5cb131042) * c)
```

 **Description:**

Unblocks all threads that are currently blocked on the condition variable  **cond**. 

This function always succeeds. 

**Parameters:**

<a name="table1217673399165622"></a>
<table><thead align="left"><tr id="row800927107165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1825967150165622"><a name="p1825967150165622"></a><a name="p1825967150165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1119014727165622"><a name="p1119014727165622"></a><a name="p1119014727165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1744352765165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">c</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the condition variable to broadcast. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**. 

## pthread\_cond\_destroy\(\)<a name="ga7f2a7328ee3a7743686adcd2d51771c4"></a>

```
int pthread_cond_destroy ([pthread_cond_t](UTILS.md#gaf2111a9da165bafea75dabf5cb131042) * c)
```

 **Description:**

Destroys a condition variable. 

This function always succeeds. 

**Parameters:**

<a name="table1070924440165622"></a>
<table><thead align="left"><tr id="row1425466878165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p565054169165622"><a name="p565054169165622"></a><a name="p565054169165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p889495153165622"><a name="p889495153165622"></a><a name="p889495153165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1359182207165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">c</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the condition variable to destroy. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**. 

## pthread\_cond\_init\(\)<a name="gabdf02ed57b055f1920991e96e7d67043"></a>

```
int pthread_cond_init ([pthread_cond_t](UTILS.md#gaf2111a9da165bafea75dabf5cb131042) *__restrict c, const [pthread_condattr_t](UTILS.md#gaa992c0a75a463b1c095248eec28086d3) *__restrict a )
```

 **Description:**

Initializes a condition variable. 

This function always succeeds. 

**Parameters:**

<a name="table362358299165622"></a>
<table><thead align="left"><tr id="row782985747165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1413162013165622"><a name="p1413162013165622"></a><a name="p1413162013165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p352584194165622"><a name="p352584194165622"></a><a name="p352584194165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row499104606165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">c</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the condition variable to initialize. </td>
</tr>
<tr id="row1416022127165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">a</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the condition variable attribute object. If this parameter is set to <strong id="b1074241310165622"><a name="b1074241310165622"></a><a name="b1074241310165622"></a>NULL</strong>, the default condition variable attributes are used. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**. 

## pthread\_cond\_signal\(\)<a name="ga9b0f2c7dead8c628e081d76c86a1addc"></a>

```
int pthread_cond_signal ([pthread_cond_t](UTILS.md#gaf2111a9da165bafea75dabf5cb131042) * c)
```

 **Description:**

Unblocks a thread. 

If multiple threads are blocked on the condition variable  **cond**, this function unblocks at least one thread. This function always succeeds. 

**Parameters:**

<a name="table179853119165622"></a>
<table><thead align="left"><tr id="row1550102117165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1539084350165622"><a name="p1539084350165622"></a><a name="p1539084350165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2091262672165622"><a name="p2091262672165622"></a><a name="p2091262672165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1309408718165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">c</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the condition variable to signal. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**. 

## pthread\_cond\_timedwait\(\)<a name="ga506c0350d597721ab24bba7129e8e0df"></a>

```
int pthread_cond_timedwait ([pthread_cond_t](UTILS.md#gaf2111a9da165bafea75dabf5cb131042) *__restrict c, [pthread_mutex_t](UTILS.md#ga75eeb2460f33f5f74cec3ff583ad9e94) *__restrict m, const struct [timespec](timespec.md) *__restrict ts )
```

 **Description:**

Blocks the calling thread to wait for the condition set by  **pthread\_con\_signal\(\)**  for a period of time specified by  **ts**. 

**Parameters:**

<a name="table1266730565165622"></a>
<table><thead align="left"><tr id="row875489079165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p222080553165622"><a name="p222080553165622"></a><a name="p222080553165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p528351864165622"><a name="p528351864165622"></a><a name="p528351864165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row382473242165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">c</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the condition variable to wait for. </td>
</tr>
<tr id="row1734887787165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">m</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the mutex associated with the condition variable. </td>
</tr>
<tr id="row471168762165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">ts</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the absolute system time when the calling thread stops blocking. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a value listed in  **errno**  otherwise. 

<a name="table1143333293165622"></a>
<table><thead align="left"><tr id="row1381759543165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p34504287165622"><a name="p34504287165622"></a><a name="p34504287165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2098318524165622"><a name="p2098318524165622"></a><a name="p2098318524165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1073327960165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p633682686165622"><a name="p633682686165622"></a><a name="p633682686165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p802457306165622"><a name="p802457306165622"></a><a name="p802457306165622"></a>Invalid <strong id="b1272775570165622"><a name="b1272775570165622"></a><a name="b1272775570165622"></a>ts</strong> value. </p>
</td>
</tr>
<tr id="row608945371165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1375253971165622"><a name="p1375253971165622"></a><a name="p1375253971165622"></a>EPERM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1880840990165622"><a name="p1880840990165622"></a><a name="p1880840990165622"></a>The associated mutex is invalid. </p>
</td>
</tr>
<tr id="row1159920814165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p254387968165622"><a name="p254387968165622"></a><a name="p254387968165622"></a>ETIMEDOUT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1401177214165622"><a name="p1401177214165622"></a><a name="p1401177214165622"></a>The time specified by abstime has passed. </p>
</td>
</tr>
</tbody>
</table>

## pthread\_cond\_wait\(\)<a name="gaea601b8ce596a5c54fb12758c56b10a1"></a>

```
int pthread_cond_wait ([pthread_cond_t](UTILS.md#gaf2111a9da165bafea75dabf5cb131042) *__restrict c, [pthread_mutex_t](UTILS.md#ga75eeb2460f33f5f74cec3ff583ad9e94) *__restrict m )
```

 **Description:**

Blocks the calling thread to wait for the condition set by  **pthread\_con\_signal\(\)**. 

**Parameters:**

<a name="table941646724165622"></a>
<table><thead align="left"><tr id="row630741889165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p729979088165622"><a name="p729979088165622"></a><a name="p729979088165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1369109643165622"><a name="p1369109643165622"></a><a name="p1369109643165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row287020527165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">c</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the condition variable to wait for. </td>
</tr>
<tr id="row926465028165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">m</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the mutex associated with the condition variable. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a value listed in  **errno**  otherwise. 

<a name="table724586714165622"></a>
<table><thead align="left"><tr id="row795406012165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p820143780165622"><a name="p820143780165622"></a><a name="p820143780165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1843037610165622"><a name="p1843037610165622"></a><a name="p1843037610165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row241167984165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p164543316165622"><a name="p164543316165622"></a><a name="p164543316165622"></a>EPERM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1202590114165622"><a name="p1202590114165622"></a><a name="p1202590114165622"></a>The associated mutex is invalid. </p>
</td>
</tr>
</tbody>
</table>

## pthread\_condattr\_destroy\(\)<a name="ga8ab009937339c899a5197eea2e48e6a1"></a>

```
int pthread_condattr_destroy ([pthread_condattr_t](UTILS.md#gaa992c0a75a463b1c095248eec28086d3) * a)
```

 **Description:**

Destroys a condition variable attribute object. 

This function always succeeds. 

**Parameters:**

<a name="table1310567715165622"></a>
<table><thead align="left"><tr id="row501614477165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1117895384165622"><a name="p1117895384165622"></a><a name="p1117895384165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p273213941165622"><a name="p273213941165622"></a><a name="p273213941165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1334374338165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">a</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the variable that contains the condition variable attributes. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**. 

## pthread\_condattr\_getclock\(\)<a name="gadcf908971c2ea15ced780025772084e3"></a>

```
int pthread_condattr_getclock (const [pthread_condattr_t](UTILS.md#gaa992c0a75a463b1c095248eec28086d3) *__restrict a, [clockid_t](UTILS.md#ga391e4a62662054e5d3e1e071b8e54329) *__restrict clk )
```

 **Description:**

Obtains the clock of a condition variable attribute object. 

This function always succeeds. 

**Parameters:**

<a name="table778868864165622"></a>
<table><thead align="left"><tr id="row1088953204165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p94012363165622"><a name="p94012363165622"></a><a name="p94012363165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1582929899165622"><a name="p1582929899165622"></a><a name="p1582929899165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row328455998165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">a</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the variable that contains the condition variable attributes. </td>
</tr>
<tr id="row457207158165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">clk</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the obtained clock ID. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**. 

## pthread\_condattr\_init\(\)<a name="ga487a919ab54fd47c8464507031957df0"></a>

```
int pthread_condattr_init ([pthread_condattr_t](UTILS.md#gaa992c0a75a463b1c095248eec28086d3) * a)
```

 **Description:**

Initializes a condition variable attribute object. 

This function always succeeds. 

**Parameters:**

<a name="table1566075444165622"></a>
<table><thead align="left"><tr id="row2121470806165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1942116418165622"><a name="p1942116418165622"></a><a name="p1942116418165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p742859420165622"><a name="p742859420165622"></a><a name="p742859420165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1372282792165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">a</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the variable that contains the condition variable attributes. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**. 

## pthread\_condattr\_setclock\(\)<a name="gaaf7ac0f85233c0effaf850a9c65b6d68"></a>

```
int pthread_condattr_setclock ([pthread_condattr_t](UTILS.md#gaa992c0a75a463b1c095248eec28086d3) * a, [clockid_t](UTILS.md#ga391e4a62662054e5d3e1e071b8e54329) clk )
```

 **Description:**

Sets a clock for a condition variable attribute object. 

**Parameters:**

<a name="table235219127165622"></a>
<table><thead align="left"><tr id="row2057923971165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1731519385165622"><a name="p1731519385165622"></a><a name="p1731519385165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1116834381165622"><a name="p1116834381165622"></a><a name="p1116834381165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row377797101165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">a</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the variable that contains the condition variable attributes. </td>
</tr>
<tr id="row678467888165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">clk</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the ID of the clock to set. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a value listed in  **errno**  otherwise. 

<a name="table1473423224165622"></a>
<table><thead align="left"><tr id="row631623009165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p302485397165622"><a name="p302485397165622"></a><a name="p302485397165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1960405075165622"><a name="p1960405075165622"></a><a name="p1960405075165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row2041649636165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2104578099165622"><a name="p2104578099165622"></a><a name="p2104578099165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p883470005165622"><a name="p883470005165622"></a><a name="p883470005165622"></a>Invalid <strong id="b1215712999165622"><a name="b1215712999165622"></a><a name="b1215712999165622"></a>clk&gt; value. </strong></p>
</td>
</tr>
</tbody>
</table>

## pthread\_create\(\)<a name="gae5d18438d4d20c8a2e42cd2500578d79"></a>

```
int pthread_create ([pthread_t](UTILS.md#ga5250f47a8a0402a78bb51a2133e13c1f) * thread, const [pthread_attr_t](UTILS.md#gac8ee4471bbc35deb7589ac3615deb486) * attr, void *(*)(void *) start_routine, void * arg )
```

 **Description:**

Creates a thread. 

This function creates a thread in the calling process. The new thread starts execution from the entry point  **star\_routine**.  **arg**  is passed as the unique argument of the entry point. 

**Parameters:**

<a name="table875336165165622"></a>
<table><thead align="left"><tr id="row1497363478165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1888319026165622"><a name="p1888319026165622"></a><a name="p1888319026165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1700057856165622"><a name="p1700057856165622"></a><a name="p1700057856165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row384840563165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">thread</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the buffer for storing the thread ID. </td>
</tr>
<tr id="row34540829165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">attr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the thread attribute object. If this parameter is set to <strong id="b1897312410165622"><a name="b1897312410165622"></a><a name="b1897312410165622"></a>NULL</strong>, the default thread attributes are used. </td>
</tr>
<tr id="row1923582245165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">start_routine</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the entry point of the thread. </td>
</tr>
<tr id="row1219438424165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">arg</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Functions as the unique argument of <strong id="b724914571165622"><a name="b724914571165622"></a><a name="b724914571165622"></a>start_routine</strong>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a value listed in  **errno**  otherwise. 

<a name="table633362278165622"></a>
<table><thead align="left"><tr id="row695188910165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1164823479165622"><a name="p1164823479165622"></a><a name="p1164823479165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1414479992165622"><a name="p1414479992165622"></a><a name="p1414479992165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row425916918165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1749191766165622"><a name="p1749191766165622"></a><a name="p1749191766165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1629437194165622"><a name="p1629437194165622"></a><a name="p1629437194165622"></a>Invalid parameter. </p>
</td>
</tr>
<tr id="row503355897165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p350410490165622"><a name="p350410490165622"></a><a name="p350410490165622"></a>EAGAIN </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1813585363165622"><a name="p1813585363165622"></a><a name="p1813585363165622"></a>Insufficient resource, or the maximum number of threads allowed by the system reached. </p>
</td>
</tr>
</tbody>
</table>

## pthread\_detach\(\)<a name="ga7c275c509c26566b6dd95a2de1668a2f"></a>

```
int pthread_detach ([pthread_t](UTILS.md#ga5250f47a8a0402a78bb51a2133e13c1f) thread)
```

 **Description:**

Detaches a thread. 

 

**Parameters:**

<a name="table906139991165622"></a>
<table><thead align="left"><tr id="row609273327165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1145905296165622"><a name="p1145905296165622"></a><a name="p1145905296165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p90401238165622"><a name="p90401238165622"></a><a name="p90401238165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1682100131165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">thread</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the ID of the user-level thread to detach. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a value listed in  **errno**  otherwise. 

<a name="table1122911317165622"></a>
<table><thead align="left"><tr id="row152548162165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2032952442165622"><a name="p2032952442165622"></a><a name="p2032952442165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p285642430165622"><a name="p285642430165622"></a><a name="p285642430165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1989323227165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1107279446165622"><a name="p1107279446165622"></a><a name="p1107279446165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1954597716165622"><a name="p1954597716165622"></a><a name="p1954597716165622"></a>The thread is not joinable. </p>
</td>
</tr>
<tr id="row1896242082165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p615837806165622"><a name="p615837806165622"></a><a name="p615837806165622"></a>ESRCH </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p354112513165622"><a name="p354112513165622"></a><a name="p354112513165622"></a>Invalid thread ID. </p>
</td>
</tr>
</tbody>
</table>

## pthread\_equal\(\)<a name="ga98ec817164a6641eda2341de473b659d"></a>

```
int pthread_equal ([pthread_t](UTILS.md#ga5250f47a8a0402a78bb51a2133e13c1f) t1, [pthread_t](UTILS.md#ga5250f47a8a0402a78bb51a2133e13c1f) t2 )
```

 **Description:**

Compares whether two thread IDs are equal. 

**Parameters:**

<a name="table1883121623165622"></a>
<table><thead align="left"><tr id="row825251743165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1931673300165622"><a name="p1931673300165622"></a><a name="p1931673300165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1840689394165622"><a name="p1840689394165622"></a><a name="p1840689394165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1138936166165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">t1</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the first thread. </td>
</tr>
<tr id="row293371778165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">t2</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the second thread. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the two are not equal; returns a non-zero value otherwise. 

## pthread\_exit\(\)<a name="gaadfb4e5de5a20880c6a40d4e73ce2597"></a>

```
_Noreturn void pthread_exit (void * retval)
```

 **Description:**

Terminates the calling thread. 

**Parameters:**

<a name="table230791863165622"></a>
<table><thead align="left"><tr id="row1279468759165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p709344860165622"><a name="p709344860165622"></a><a name="p709344860165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2052793945165622"><a name="p2052793945165622"></a><a name="p2052793945165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1071766373165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">retval</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the return value after the thread is terminated. </td>
</tr>
</tbody>
</table>

## pthread\_getaffinity\_np\(\)<a name="ga051df55ea1131f70f6f9356865a36798"></a>

```
int pthread_getaffinity_np ([pthread_t](UTILS.md#ga5250f47a8a0402a78bb51a2133e13c1f) td, size_t size, cpu_set_t * set )
```

 **Description:**

Gets the thread affinity. 

**Parameters:**

<a name="table1371598573165622"></a>
<table><thead align="left"><tr id="row1975350699165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1246953626165622"><a name="p1246953626165622"></a><a name="p1246953626165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1242879542165622"><a name="p1242879542165622"></a><a name="p1242879542165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2003439799165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">td</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the thread whose affinity is to be obtained. </td>
</tr>
<tr id="row1112936169165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">size</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">The size of the cpu_set_t struct. </td>
</tr>
<tr id="row315902928165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">set</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">The pointer to the cpu_set_t struct recording the getting affinity. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a value listed in  **errno**  otherwise. 

<a name="table721502672165622"></a>
<table><thead align="left"><tr id="row617404778165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p5272600165622"><a name="p5272600165622"></a><a name="p5272600165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1971432327165622"><a name="p1971432327165622"></a><a name="p1971432327165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row407264054165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p33316244165622"><a name="p33316244165622"></a><a name="p33316244165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p234106366165622"><a name="p234106366165622"></a><a name="p234106366165622"></a>The size is not equal to the cpu_set_t or the td is invalid. </p>
</td>
</tr>
</tbody>
</table>

## pthread\_getattr\_np\(\)<a name="ga6bdca4b2c8a436c4651fb5e8d462408b"></a>

```
int pthread_getattr_np ([pthread_t](UTILS.md#ga5250f47a8a0402a78bb51a2133e13c1f) thread, [pthread_attr_t](UTILS.md#gac8ee4471bbc35deb7589ac3615deb486) * attr )
```

 **Description:**

Obtains the attributes of a created thread. 

This function always succeeds. 

**Parameters:**

<a name="table1173937445165622"></a>
<table><thead align="left"><tr id="row1521121801165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1866740961165622"><a name="p1866740961165622"></a><a name="p1866740961165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p628440475165622"><a name="p628440475165622"></a><a name="p628440475165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2018966426165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">thread</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the thread that has been created. </td>
</tr>
<tr id="row1860922978165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">attr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the attribute values that describe the running thread. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**. 

## pthread\_getschedparam\(\)<a name="gaae9850b3759769c748727e171c4c6e61"></a>

```
int pthread_getschedparam ([pthread_t](UTILS.md#ga5250f47a8a0402a78bb51a2133e13c1f) thread, int * policy, struct [sched_param](sched_param.md) * param )
```

 **Description:**

Obtains the scheduling policy and parameters of a thread. 

**Parameters:**

<a name="table765973373165622"></a>
<table><thead align="left"><tr id="row1665263505165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p275440372165622"><a name="p275440372165622"></a><a name="p275440372165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1855781678165622"><a name="p1855781678165622"></a><a name="p1855781678165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1301522799165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">thread</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the target thread. </td>
</tr>
<tr id="row1487809648165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">policy</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the scheduling policy. The value can only be <strong id="b963496534165622"><a name="b963496534165622"></a><a name="b963496534165622"></a>SCHED_FIFO</strong> or <strong id="b1999967577165622"><a name="b1999967577165622"></a><a name="b1999967577165622"></a>SCHED_RR</strong>. </td>
</tr>
<tr id="row336669678165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">param</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the scheduling parameters. Only the thread priority is supported. The priority ranges from 0 (highest priority) to 31 (lowest priority). </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a value listed in  **errno**  otherwise. 

<a name="table174457853165622"></a>
<table><thead align="left"><tr id="row594923094165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p976019990165622"><a name="p976019990165622"></a><a name="p976019990165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1878472618165622"><a name="p1878472618165622"></a><a name="p1878472618165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1822684803165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p973710169165622"><a name="p973710169165622"></a><a name="p973710169165622"></a>ESRCH </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1902639679165622"><a name="p1902639679165622"></a><a name="p1902639679165622"></a>Invalid thread ID. </p>
</td>
</tr>
<tr id="row820791057165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p482774131165622"><a name="p482774131165622"></a><a name="p482774131165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2000010291165622"><a name="p2000010291165622"></a><a name="p2000010291165622"></a>Invalid parameter. </p>
</td>
</tr>
<tr id="row784168210165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1728771951165622"><a name="p1728771951165622"></a><a name="p1728771951165622"></a>EPERM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p553613290165622"><a name="p553613290165622"></a><a name="p553613290165622"></a>No permission to obtain the specified scheduling policy and parameters. </p>
</td>
</tr>
</tbody>
</table>

## pthread\_getspecific\(\)<a name="ga31469375891078185bda93f0e4411a2c"></a>

```
void* pthread_getspecific ([pthread_key_t](UTILS.md#gafeedfceab43831b6771f80aff6a519be) key)
```

 **Description:**

Obtains specific thread data. 

**Parameters:**

<a name="table344696961165622"></a>
<table><thead align="left"><tr id="row1100710874165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p578220636165622"><a name="p578220636165622"></a><a name="p578220636165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2018184383165622"><a name="p2018184383165622"></a><a name="p2018184383165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row912097668165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">key</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the key bound to the thread data. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the thread data value associated with the given key. 

## pthread\_join\(\)<a name="ga28a15bba47cab57cbc9f5dac9af99c8b"></a>

```
int pthread_join ([pthread_t](UTILS.md#ga5250f47a8a0402a78bb51a2133e13c1f) thread, void ** retval )
```

 **Description:**

Waits for a thread to terminate. 

This function returns a value immediately if the thread has already terminated. 

**Parameters:**

<a name="table1174612875165622"></a>
<table><thead align="left"><tr id="row1680681101165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p981399772165622"><a name="p981399772165622"></a><a name="p981399772165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p764373513165622"><a name="p764373513165622"></a><a name="p764373513165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1280209487165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">thread</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the target thread. </td>
</tr>
<tr id="row1575438861165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">retval</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double pointer to the exit or cancellation status of the target thread. This parameter can be <strong id="b1838485308165622"><a name="b1838485308165622"></a><a name="b1838485308165622"></a>NULL</strong>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a value listed in  **errno**  otherwise. 

<a name="table833899832165622"></a>
<table><thead align="left"><tr id="row1661500330165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p774658896165622"><a name="p774658896165622"></a><a name="p774658896165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p44958746165622"><a name="p44958746165622"></a><a name="p44958746165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1099905649165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1548107053165622"><a name="p1548107053165622"></a><a name="p1548107053165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p766810531165622"><a name="p766810531165622"></a><a name="p766810531165622"></a>The thread is not joinable, or the target thread is the calling thread. </p>
</td>
</tr>
</tbody>
</table>

## pthread\_key\_create\(\)<a name="gaf4b7ced8ecff505380fe8216244a3764"></a>

```
int pthread_key_create ([pthread_key_t](UTILS.md#gafeedfceab43831b6771f80aff6a519be) * key, void(*)(void *) destructor )
```

 **Description:**

Creates a key for thread data. 

**Parameters:**

<a name="table1995877311165622"></a>
<table><thead align="left"><tr id="row848191358165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p825314356165622"><a name="p825314356165622"></a><a name="p825314356165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2097865195165622"><a name="p2097865195165622"></a><a name="p2097865195165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row683785937165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">key</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the key to set for the thread data. </td>
</tr>
<tr id="row44141314165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">destructor</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the function to be bound to the key. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a value listed in  **errno**  otherwise. 

<a name="table214412810165622"></a>
<table><thead align="left"><tr id="row317390562165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1375796201165622"><a name="p1375796201165622"></a><a name="p1375796201165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1494600682165622"><a name="p1494600682165622"></a><a name="p1494600682165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row248911237165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p140615085165622"><a name="p140615085165622"></a><a name="p140615085165622"></a>EAGAIN </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p602593099165622"><a name="p602593099165622"></a><a name="p602593099165622"></a>The system lacks the necessary resources to create another thread-specific key, or the number of keys exceeds the limit specified by <strong id="b1112084546165622"><a name="b1112084546165622"></a><a name="b1112084546165622"></a>PTHREAD_KEYS_MAX</strong> for each process. </p>
</td>
</tr>
</tbody>
</table>

## pthread\_key\_delete\(\)<a name="gaee96306dc79294927ee840bb4de2244b"></a>

```
int pthread_key_delete ([pthread_key_t](UTILS.md#gafeedfceab43831b6771f80aff6a519be) key)
```

 **Description:**

Deletes a key for thread data. 

**Parameters:**

<a name="table599736965165622"></a>
<table><thead align="left"><tr id="row47610180165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1849407586165622"><a name="p1849407586165622"></a><a name="p1849407586165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p724816511165622"><a name="p724816511165622"></a><a name="p724816511165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1139677157165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">key</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the key to delete for the thread data. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a value listed in  **errno**  otherwise. 

## pthread\_kill\(\)<a name="ga5aafacc071cdfafd0eb992004dee3e62"></a>

```
int pthread_kill ([pthread_t](UTILS.md#ga5250f47a8a0402a78bb51a2133e13c1f) thread, int sig )
```

 **Description:**

Sends a signal to a thread. 

If  **sig**  is  **0**, no signal is sent, but error checking is still performed. Therefore, you can call this function with  **sig**  set to  **0**  to check whether a thread exists. 

**Parameters:**

<a name="table917700090165622"></a>
<table><thead align="left"><tr id="row1347993919165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p393422366165622"><a name="p393422366165622"></a><a name="p393422366165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p680217963165622"><a name="p680217963165622"></a><a name="p680217963165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row189238050165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">thread</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the thread to receive the signal. </td>
</tr>
<tr id="row1366604840165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sig</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the signal to send. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a value listed in  **errno**  otherwise. 

<a name="table801450279165622"></a>
<table><thead align="left"><tr id="row691576411165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1236593422165622"><a name="p1236593422165622"></a><a name="p1236593422165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p724659856165622"><a name="p724659856165622"></a><a name="p724659856165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row335792768165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1777049989165622"><a name="p1777049989165622"></a><a name="p1777049989165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p722169378165622"><a name="p722169378165622"></a><a name="p722169378165622"></a>Invalid signal. </p>
</td>
</tr>
<tr id="row1565569158165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p153446025165622"><a name="p153446025165622"></a><a name="p153446025165622"></a>ESRCH </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p214309509165622"><a name="p214309509165622"></a><a name="p214309509165622"></a>Invalid thread ID. </p>
</td>
</tr>
</tbody>
</table>

## pthread\_mutex\_destroy\(\)<a name="gaf89d9cfa300f33b46720a96eac83d175"></a>

```
int pthread_mutex_destroy ([pthread_mutex_t](UTILS.md#ga75eeb2460f33f5f74cec3ff583ad9e94) * m)
```

 **Description:**

Destroys a mutex. 

This function always succeeds. 

**Parameters:**

<a name="table928333180165622"></a>
<table><thead align="left"><tr id="row625542503165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p226089905165622"><a name="p226089905165622"></a><a name="p226089905165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1183452957165622"><a name="p1183452957165622"></a><a name="p1183452957165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row315448848165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">m</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the mutex to destroy. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**. 

## pthread\_mutex\_init\(\)<a name="gadd99221596e95a55f70c59c1c712bbde"></a>

```
int pthread_mutex_init ([pthread_mutex_t](UTILS.md#ga75eeb2460f33f5f74cec3ff583ad9e94) *__restrict m, const [pthread_mutexattr_t](UTILS.md#gaf2212c79151cc55f3a41c430908f3909) *__restrict a )
```

 **Description:**

Initializes a mutex. 

This function dynamically creates a mutex. The parameter  **a**  specifies the attributes of the mutex. This function always succeeds. 

**Parameters:**

<a name="table1454446106165622"></a>
<table><thead align="left"><tr id="row1311989511165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1292069095165622"><a name="p1292069095165622"></a><a name="p1292069095165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p831439770165622"><a name="p831439770165622"></a><a name="p831439770165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1316893556165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">m</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the mutex to initialize. </td>
</tr>
<tr id="row1749630586165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">a</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the mutex attribute object. If this parameter is set to <strong id="b2019838758165622"><a name="b2019838758165622"></a><a name="b2019838758165622"></a>NULL</strong>, the default mutex attributes are used. The default attributes indicate a fast mutex. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**. 

## pthread\_mutex\_lock\(\)<a name="gafd70d6f2c50e22b996c926fb9d6ad291"></a>

```
int pthread_mutex_lock ([pthread_mutex_t](UTILS.md#ga75eeb2460f33f5f74cec3ff583ad9e94) * m)
```

 **Description:**

Locks a mutex. 

If the mutex is already locked by a thread, the call is blocked until the holding thread unlocks the mutex by calling  [pthread\_mutex\_unlock\(\)](PROCESS.md#ga02a3c64dac70730e226c31c0e7dbb45c). 

**Parameters:**

<a name="table1223151487165622"></a>
<table><thead align="left"><tr id="row136895818165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p557524000165622"><a name="p557524000165622"></a><a name="p557524000165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p816991287165622"><a name="p816991287165622"></a><a name="p816991287165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1677917532165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">m</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the mutex to lock. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a value listed in  **errno**  otherwise. 

<a name="table954562977165622"></a>
<table><thead align="left"><tr id="row1109562224165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p920645146165622"><a name="p920645146165622"></a><a name="p920645146165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p971236676165622"><a name="p971236676165622"></a><a name="p971236676165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1539439837165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p644544590165622"><a name="p644544590165622"></a><a name="p644544590165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1282460721165622"><a name="p1282460721165622"></a><a name="p1282460721165622"></a>Incorrect parameter value. </p>
</td>
</tr>
<tr id="row1509933524165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p985717778165622"><a name="p985717778165622"></a><a name="p985717778165622"></a>EBADF </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1131046674165622"><a name="p1131046674165622"></a><a name="p1131046674165622"></a>The mutex has been damaged during the waiting. </p>
</td>
</tr>
<tr id="row816384085165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2092709906165622"><a name="p2092709906165622"></a><a name="p2092709906165622"></a>EDEADLK </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1399499360165622"><a name="p1399499360165622"></a><a name="p1399499360165622"></a>The thread attempts to relock the mutex that it has already locked, and the mutex is of the error check mutex type. </p>
</td>
</tr>
<tr id="row526079842165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p707361470165622"><a name="p707361470165622"></a><a name="p707361470165622"></a>EAGAIN </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1641914299165622"><a name="p1641914299165622"></a><a name="p1641914299165622"></a>The maximum number of recursive locks for the mutex has been exceeded. </p>
</td>
</tr>
</tbody>
</table>

## pthread\_mutex\_timedlock\(\)<a name="gabc6a044b418e942b91121b1babb61708"></a>

```
int pthread_mutex_timedlock ([pthread_mutex_t](UTILS.md#ga75eeb2460f33f5f74cec3ff583ad9e94) *__restrict m, const struct [timespec](timespec.md) *__restrict at )
```

 **Description:**

Blocks the calling thread to lock a mutex. 

If the mutex is already locked, the call is blocked until the specified timeout duration expires or the holding thread unlocks the mutex by calling  [pthread\_mutex\_unlock\(\)](PROCESS.md#ga02a3c64dac70730e226c31c0e7dbb45c). 

**Parameters:**

<a name="table455960312165622"></a>
<table><thead align="left"><tr id="row276023977165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2017087142165622"><a name="p2017087142165622"></a><a name="p2017087142165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p22662502165622"><a name="p22662502165622"></a><a name="p22662502165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1623087127165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">m</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the mutex to lock. </td>
</tr>
<tr id="row189297268165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">at</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the maximum duration that the calling thread waits for the mutex. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a value listed in  **errno**  otherwise. 

<a name="table223555814165622"></a>
<table><thead align="left"><tr id="row406796833165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p639306330165622"><a name="p639306330165622"></a><a name="p639306330165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1613203986165622"><a name="p1613203986165622"></a><a name="p1613203986165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row19064912165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1135286254165622"><a name="p1135286254165622"></a><a name="p1135286254165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1709918249165622"><a name="p1709918249165622"></a><a name="p1709918249165622"></a>Incorrect parameter value. </p>
</td>
</tr>
<tr id="row1752309154165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1736584677165622"><a name="p1736584677165622"></a><a name="p1736584677165622"></a>EBADF </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p611525190165622"><a name="p611525190165622"></a><a name="p611525190165622"></a>The mutex has been damaged during the waiting. </p>
</td>
</tr>
<tr id="row1674496312165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p725257814165622"><a name="p725257814165622"></a><a name="p725257814165622"></a>EBUSY </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p194811717165622"><a name="p194811717165622"></a><a name="p194811717165622"></a>The mutex is already locked. </p>
</td>
</tr>
<tr id="row1946098024165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p448760454165622"><a name="p448760454165622"></a><a name="p448760454165622"></a>EAGAIN </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2136983830165622"><a name="p2136983830165622"></a><a name="p2136983830165622"></a>The maximum number of recursive locks for the mutex has been exceeded. </p>
</td>
</tr>
<tr id="row1093887292165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1750291287165622"><a name="p1750291287165622"></a><a name="p1750291287165622"></a>ETIMEDOUT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2138524882165622"><a name="p2138524882165622"></a><a name="p2138524882165622"></a>The mutex cannot be acquired within the specified period of time. </p>
</td>
</tr>
</tbody>
</table>

## pthread\_mutex\_trylock\(\)<a name="gacc1ccbaf3d76572da85a8030bba1ede4"></a>

```
int pthread_mutex_trylock ([pthread_mutex_t](UTILS.md#ga75eeb2460f33f5f74cec3ff583ad9e94) * m)
```

 **Description:**

Attempts to lock a mutex. 

This function attempts to acquire a mutex, without blocking the calling thread. If the mutex is already locked, the error code  **EBUSY**  is returned immediately. 

**Parameters:**

<a name="table1342833821165622"></a>
<table><thead align="left"><tr id="row214259801165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p23689995165622"><a name="p23689995165622"></a><a name="p23689995165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1894920748165622"><a name="p1894920748165622"></a><a name="p1894920748165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row275952091165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">m</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the mutex to lock. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a value listed in  **errno**  otherwise. 

<a name="table1559447792165622"></a>
<table><thead align="left"><tr id="row1574095638165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p170369954165622"><a name="p170369954165622"></a><a name="p170369954165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p453161153165622"><a name="p453161153165622"></a><a name="p453161153165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1746425212165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p857573598165622"><a name="p857573598165622"></a><a name="p857573598165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1571285931165622"><a name="p1571285931165622"></a><a name="p1571285931165622"></a>Incorrect parameter value. </p>
</td>
</tr>
<tr id="row1214467864165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p41157828165622"><a name="p41157828165622"></a><a name="p41157828165622"></a>EBADF </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1325372542165622"><a name="p1325372542165622"></a><a name="p1325372542165622"></a>The mutex has been damaged during the waiting. </p>
</td>
</tr>
<tr id="row1207687305165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1082934475165622"><a name="p1082934475165622"></a><a name="p1082934475165622"></a>EBUSY </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p729492178165622"><a name="p729492178165622"></a><a name="p729492178165622"></a>The mutex is already locked. </p>
</td>
</tr>
<tr id="row157952790165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1460515582165622"><a name="p1460515582165622"></a><a name="p1460515582165622"></a>EAGAIN </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p782590273165622"><a name="p782590273165622"></a><a name="p782590273165622"></a>The maximum number of recursive locks for the mutex has been exceeded. </p>
</td>
</tr>
</tbody>
</table>

## pthread\_mutex\_unlock\(\)<a name="ga02a3c64dac70730e226c31c0e7dbb45c"></a>

```
int pthread_mutex_unlock ([pthread_mutex_t](UTILS.md#ga75eeb2460f33f5f74cec3ff583ad9e94) * m)
```

 **Description:**

Unlocks a mutex. 

If the calling thread attempts to unlock a mutex that it has not locked \(by calling  [pthread\_mutex\_lock\(\)](PROCESS.md#gafd70d6f2c50e22b996c926fb9d6ad291),  [pthread\_mutex\_trylock\(\)](PROCESS.md#gacc1ccbaf3d76572da85a8030bba1ede4), or  **pthread\_mutex\_timedlock\_np\(\)**, the unlock request fails and the error code  **EPERM**  is returned. 

**Parameters:**

<a name="table930769565165622"></a>
<table><thead align="left"><tr id="row2004113953165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p500371817165622"><a name="p500371817165622"></a><a name="p500371817165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1737525605165622"><a name="p1737525605165622"></a><a name="p1737525605165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row806725362165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">m</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the mutex to unlock. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a value listed in  **errno**  otherwise. 

<a name="table347121873165622"></a>
<table><thead align="left"><tr id="row263826042165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1685899994165622"><a name="p1685899994165622"></a><a name="p1685899994165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p739132219165622"><a name="p739132219165622"></a><a name="p739132219165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row680720108165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1800651353165622"><a name="p1800651353165622"></a><a name="p1800651353165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p469621114165622"><a name="p469621114165622"></a><a name="p469621114165622"></a>Incorrect parameter value. </p>
</td>
</tr>
<tr id="row971779438165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1902651033165622"><a name="p1902651033165622"></a><a name="p1902651033165622"></a>EPERM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1474955893165622"><a name="p1474955893165622"></a><a name="p1474955893165622"></a>The mutex has not been locked by the calling thread. </p>
</td>
</tr>
</tbody>
</table>

## pthread\_mutexattr\_destroy\(\)<a name="ga2321aabf58224b06021185708d0f9658"></a>

```
int pthread_mutexattr_destroy ([pthread_mutexattr_t](UTILS.md#gaf2212c79151cc55f3a41c430908f3909) * attr)
```

 **Description:**

Destroys a mutex attribute object. 

This function always succeeds. 

**Parameters:**

<a name="table566692577165622"></a>
<table><thead align="left"><tr id="row48388273165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p892451825165622"><a name="p892451825165622"></a><a name="p892451825165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2139917271165622"><a name="p2139917271165622"></a><a name="p2139917271165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1759415741165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">attr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the target mutex attribute object. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**. 

## pthread\_mutexattr\_gettype\(\)<a name="ga4789e2d3ada7aab2af1458bfec53ee3c"></a>

```
int pthread_mutexattr_gettype (const [pthread_mutexattr_t](UTILS.md#gaf2212c79151cc55f3a41c430908f3909) *__restrict attr, int *__restrict type )
```

 **Description:**

Obtains the mutex type attribute. 

This function always succeeds. 

**Parameters:**

<a name="table526650800165622"></a>
<table><thead align="left"><tr id="row1473007717165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1236231204165622"><a name="p1236231204165622"></a><a name="p1236231204165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p578615348165622"><a name="p578615348165622"></a><a name="p578615348165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1957091700165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">attr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the mutex attribute object. </td>
</tr>
<tr id="row1047778079165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">type</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the obtained mutex type attribute. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**. 

## pthread\_mutexattr\_init\(\)<a name="gaf98f6b6c483077a39d1400b1de1577b8"></a>

```
int pthread_mutexattr_init ([pthread_mutexattr_t](UTILS.md#gaf2212c79151cc55f3a41c430908f3909) * attr)
```

 **Description:**

Initializes a mutex attribute object. 

This function always succeeds. 

**Parameters:**

<a name="table866351299165622"></a>
<table><thead align="left"><tr id="row1520275516165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p446364469165622"><a name="p446364469165622"></a><a name="p446364469165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p340749359165622"><a name="p340749359165622"></a><a name="p340749359165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1012258062165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">attr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the target mutex attribute object. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**. 

## pthread\_mutexattr\_settype\(\)<a name="ga8387c80e660e9426f801ac0217ecfae5"></a>

```
int pthread_mutexattr_settype ([pthread_mutexattr_t](UTILS.md#gaf2212c79151cc55f3a41c430908f3909) * attr, int type )
```

 **Description:**

Sets the mutex type attribute. 

**Parameters:**

<a name="table1876637150165622"></a>
<table><thead align="left"><tr id="row859980742165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p631408930165622"><a name="p631408930165622"></a><a name="p631408930165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1701634594165622"><a name="p1701634594165622"></a><a name="p1701634594165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row475614230165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">attr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the mutex attribute object. </td>
</tr>
<tr id="row2056662967165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">type</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the type of the mutex. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a value listed in  **errno**  otherwise. 

<a name="table423682361165622"></a>
<table><thead align="left"><tr id="row2055212823165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1161775433165622"><a name="p1161775433165622"></a><a name="p1161775433165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1757167848165622"><a name="p1757167848165622"></a><a name="p1757167848165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1073623324165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1393729924165622"><a name="p1393729924165622"></a><a name="p1393729924165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1630819569165622"><a name="p1630819569165622"></a><a name="p1630819569165622"></a>Invalid mutex type attribute. </p>
</td>
</tr>
</tbody>
</table>

## pthread\_once\(\)<a name="ga196103ac97710dad7a93fd6c188cc999"></a>

```
int pthread_once ([pthread_once_t](UTILS.md#gaf46ecab6116bf15713b10ddfab67bc07) * once_control, void(*)(void) init_routine )
```

 **Description:**

Enables the initialization function to be called only once. 

This function dynamically initializes the function specified by  **init\_routine**  and ensures that it will be called only once. 

**Parameters:**

<a name="table1028270757165622"></a>
<table><thead align="left"><tr id="row2130879074165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1458391404165622"><a name="p1458391404165622"></a><a name="p1458391404165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p793041598165622"><a name="p793041598165622"></a><a name="p793041598165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row606790529165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">once_control</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to a variable specifying the execution status. The value <strong id="b213926836165622"><a name="b213926836165622"></a><a name="b213926836165622"></a>0</strong> means <strong id="b1940099311165622"><a name="b1940099311165622"></a><a name="b1940099311165622"></a>NEVER</strong>, <strong id="b647490970165622"><a name="b647490970165622"></a><a name="b647490970165622"></a>1</strong> means <strong id="b1331981150165622"><a name="b1331981150165622"></a><a name="b1331981150165622"></a>IN PROGRESS</strong>, and <strong id="b1543258430165622"><a name="b1543258430165622"></a><a name="b1543258430165622"></a>2</strong> means <strong id="b1856471695165622"><a name="b1856471695165622"></a><a name="b1856471695165622"></a>DONE</strong>. </td>
</tr>
<tr id="row419900918165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">init_routine</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the function that you want to call for any required initialization. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if  **once\_control**  is set to  **0**  or  **2**. If  **once\_control**  is  **1**, the calling thread waits until the other thread completes initialization. 

## pthread\_rwlock\_destroy\(\)<a name="gaa106bb55bdd0e120519d5412823f8b29"></a>

```
int pthread_rwlock_destroy ([pthread_rwlock_t](UTILS.md#gadc0b6b9df00a6c3ed0d7f9afe8934d05) * rw)
```

 **Description:**

Destroys a read-write lock. 

This function always succeeds. 

**Parameters:**

<a name="table279905894165622"></a>
<table><thead align="left"><tr id="row1376212525165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p442970646165622"><a name="p442970646165622"></a><a name="p442970646165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1826883937165622"><a name="p1826883937165622"></a><a name="p1826883937165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1398449828165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">rw</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the read-write lock to destroy. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**. 

## pthread\_rwlock\_init\(\)<a name="ga1cf4bc49696c1a30db31219aef994401"></a>

```
int pthread_rwlock_init ([pthread_rwlock_t](UTILS.md#gadc0b6b9df00a6c3ed0d7f9afe8934d05) *__restrict rw, const [pthread_rwlockattr_t](UTILS.md#gaac7b93dc39852a3374d6c0802ceb7aa5) *__restrict a )
```

 **Description:**

Initializes a read-write lock. 

This function always succeeds. 

**Parameters:**

<a name="table2045085591165622"></a>
<table><thead align="left"><tr id="row7241319165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p81877754165622"><a name="p81877754165622"></a><a name="p81877754165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p619729884165622"><a name="p619729884165622"></a><a name="p619729884165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row793317086165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">rw</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the read-write lock to initialize. </td>
</tr>
<tr id="row1987274347165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">a</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the read-write lock attribute object. If this parameter is set to <strong id="b1049583065165622"><a name="b1049583065165622"></a><a name="b1049583065165622"></a>NULL</strong>, the default read-write lock attributes are used. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**. 

## pthread\_rwlock\_rdlock\(\)<a name="ga6153aca32112735053e6cc4a2a290feb"></a>

```
int pthread_rwlock_rdlock ([pthread_rwlock_t](UTILS.md#gadc0b6b9df00a6c3ed0d7f9afe8934d05) * rw)
```

 **Description:**

Applies a read lock to a read-write lock. 

**Parameters:**

<a name="table2132642491165622"></a>
<table><thead align="left"><tr id="row689242352165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p325181382165622"><a name="p325181382165622"></a><a name="p325181382165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p295031534165622"><a name="p295031534165622"></a><a name="p295031534165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row288692572165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">rw</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the target read-write lock. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a value listed in  **errno**  otherwise. 

<a name="table269672520165622"></a>
<table><thead align="left"><tr id="row890797007165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p704409433165622"><a name="p704409433165622"></a><a name="p704409433165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p587369846165622"><a name="p587369846165622"></a><a name="p587369846165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row430367989165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p854415189165622"><a name="p854415189165622"></a><a name="p854415189165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1564620295165622"><a name="p1564620295165622"></a><a name="p1564620295165622"></a>Incorrect parameter value. </p>
</td>
</tr>
<tr id="row250398423165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p435805827165622"><a name="p435805827165622"></a><a name="p435805827165622"></a>EBADF </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1949139633165622"><a name="p1949139633165622"></a><a name="p1949139633165622"></a>The read-write lock has been damaged during the waiting. </p>
</td>
</tr>
</tbody>
</table>

## pthread\_rwlock\_timedrdlock\(\)<a name="ga8edbe14731fd79a80f72384334266715"></a>

```
int pthread_rwlock_timedrdlock ([pthread_rwlock_t](UTILS.md#gadc0b6b9df00a6c3ed0d7f9afe8934d05) *__restrict rw, const struct [timespec](timespec.md) *__restrict at )
```

 **Description:**

Blocks the calling thread to lock a read-write lock for reading. 

If the read-write lock is already locked, the calling thread is blocked until the specified timeout duration expires or the holding thread unlocks the read-write lock by calling  [pthread\_rwlock\_unlock\(\)](PROCESS.md#gaffd8a19e83fc87d865d103d6fbce8c4f). 

**Parameters:**

<a name="table1119303359165622"></a>
<table><thead align="left"><tr id="row644018506165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1213100589165622"><a name="p1213100589165622"></a><a name="p1213100589165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1424173087165622"><a name="p1424173087165622"></a><a name="p1424173087165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row336201524165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">rw</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the read-write lock to lock. </td>
</tr>
<tr id="row922559998165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">at</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the maximum duration that the calling thread waits for the read-write lock. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a value listed in  **errno**  otherwise. 

<a name="table344368751165622"></a>
<table><thead align="left"><tr id="row52248106165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p486927789165622"><a name="p486927789165622"></a><a name="p486927789165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1345048357165622"><a name="p1345048357165622"></a><a name="p1345048357165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1018076240165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1504211257165622"><a name="p1504211257165622"></a><a name="p1504211257165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1319405791165622"><a name="p1319405791165622"></a><a name="p1319405791165622"></a>Incorrect parameter value. </p>
</td>
</tr>
<tr id="row2132372303165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1423875798165622"><a name="p1423875798165622"></a><a name="p1423875798165622"></a>EBADF </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1112758373165622"><a name="p1112758373165622"></a><a name="p1112758373165622"></a>The read-write lock has been damaged during the waiting. </p>
</td>
</tr>
<tr id="row372957621165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p881899266165622"><a name="p881899266165622"></a><a name="p881899266165622"></a>EBUSY </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1670505037165622"><a name="p1670505037165622"></a><a name="p1670505037165622"></a>The read-write lock is already locked. </p>
</td>
</tr>
<tr id="row1937359112165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1285044806165622"><a name="p1285044806165622"></a><a name="p1285044806165622"></a>ETIMEDOUT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2031351198165622"><a name="p2031351198165622"></a><a name="p2031351198165622"></a>The read-write lock cannot be acquired within the specified period of time. </p>
</td>
</tr>
</tbody>
</table>

## pthread\_rwlock\_timedwrlock\(\)<a name="ga3fb8fb33e16653c5ad7b7f092959738e"></a>

```
int pthread_rwlock_timedwrlock ([pthread_rwlock_t](UTILS.md#gadc0b6b9df00a6c3ed0d7f9afe8934d05) *__restrict rw, const struct [timespec](timespec.md) *__restrict at )
```

 **Description:**

Blocks the calling thread to lock a read-write lock for writing. 

If the read-write lock is already locked, the calling thread is blocked until the specified timeout duration expires or the holding thread unlocks the read-write lock by calling  [pthread\_rwlock\_unlock\(\)](PROCESS.md#gaffd8a19e83fc87d865d103d6fbce8c4f). 

**Parameters:**

<a name="table1018659765165622"></a>
<table><thead align="left"><tr id="row1445417034165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1063450151165622"><a name="p1063450151165622"></a><a name="p1063450151165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1854504194165622"><a name="p1854504194165622"></a><a name="p1854504194165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1731908425165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">rw</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the read-write lock to lock. </td>
</tr>
<tr id="row554283986165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">at</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the maximum duration that the calling thread waits for the read-write lock. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a value listed in  **errno**  otherwise. 

<a name="table1904344913165622"></a>
<table><thead align="left"><tr id="row1188780772165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1632837140165622"><a name="p1632837140165622"></a><a name="p1632837140165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p466363644165622"><a name="p466363644165622"></a><a name="p466363644165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row2100997724165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1421839195165622"><a name="p1421839195165622"></a><a name="p1421839195165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p923920193165622"><a name="p923920193165622"></a><a name="p923920193165622"></a>Incorrect parameter value. </p>
</td>
</tr>
<tr id="row1647228069165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p267645093165622"><a name="p267645093165622"></a><a name="p267645093165622"></a>EBADF </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1404200776165622"><a name="p1404200776165622"></a><a name="p1404200776165622"></a>The read-write lock has been damaged during the waiting. </p>
</td>
</tr>
<tr id="row1238252721165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1958483244165622"><a name="p1958483244165622"></a><a name="p1958483244165622"></a>EBUSY </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p948392109165622"><a name="p948392109165622"></a><a name="p948392109165622"></a>The read-write lock is already locked. </p>
</td>
</tr>
<tr id="row97112657165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p181982801165622"><a name="p181982801165622"></a><a name="p181982801165622"></a>ETIMEDOUT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p320160346165622"><a name="p320160346165622"></a><a name="p320160346165622"></a>The read-write lock cannot be acquired within the specified period of time. </p>
</td>
</tr>
</tbody>
</table>

## pthread\_rwlock\_tryrdlock\(\)<a name="ga3ba2170f06184d12543c4a5b78715fa7"></a>

```
int pthread_rwlock_tryrdlock ([pthread_rwlock_t](UTILS.md#gadc0b6b9df00a6c3ed0d7f9afe8934d05) * rw)
```

 **Description:**

Attempts to apply a read lock to a read-write lock. 

This function attempts to lock a read-write lock for reading, without blocking the calling thread. If the read-write lock is already locked, the error code  **EBUSY**  is returned immediately. 

**Parameters:**

<a name="table423021864165622"></a>
<table><thead align="left"><tr id="row864742712165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1725779053165622"><a name="p1725779053165622"></a><a name="p1725779053165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1981457408165622"><a name="p1981457408165622"></a><a name="p1981457408165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row551483476165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">rw</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the target read-write lock. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a value listed in  **errno**  otherwise. 

<a name="table1944364275165622"></a>
<table><thead align="left"><tr id="row1882745486165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1003858139165622"><a name="p1003858139165622"></a><a name="p1003858139165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1993825081165622"><a name="p1993825081165622"></a><a name="p1993825081165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row671158000165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p290856060165622"><a name="p290856060165622"></a><a name="p290856060165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2072109514165622"><a name="p2072109514165622"></a><a name="p2072109514165622"></a>Incorrect parameter value. </p>
</td>
</tr>
<tr id="row206048624165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p961505389165622"><a name="p961505389165622"></a><a name="p961505389165622"></a>EBADF </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1834812806165622"><a name="p1834812806165622"></a><a name="p1834812806165622"></a>The read-write lock has been damaged during the waiting. </p>
</td>
</tr>
<tr id="row1154271575165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p453040054165622"><a name="p453040054165622"></a><a name="p453040054165622"></a>EBUSY </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p879376611165622"><a name="p879376611165622"></a><a name="p879376611165622"></a>The read-write lock is already locked. </p>
</td>
</tr>
</tbody>
</table>

## pthread\_rwlock\_trywrlock\(\)<a name="ga2b5044e2da304ae9666fdd4e05479905"></a>

```
int pthread_rwlock_trywrlock ([pthread_rwlock_t](UTILS.md#gadc0b6b9df00a6c3ed0d7f9afe8934d05) * rw)
```

 **Description:**

Attempts to apply a write lock to a read-write lock. 

This function attempts to lock a read-write lock for writing, without blocking the calling thread. If the read-write lock is already locked, the error code  **EBUSY**  is returned immediately. 

**Parameters:**

<a name="table1816428382165622"></a>
<table><thead align="left"><tr id="row1101916844165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p558031102165622"><a name="p558031102165622"></a><a name="p558031102165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1793958357165622"><a name="p1793958357165622"></a><a name="p1793958357165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1104533601165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">rw</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the read-write lock to lock. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a value listed in  **errno**  otherwise. 

<a name="table70835930165622"></a>
<table><thead align="left"><tr id="row1735971000165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1214675663165622"><a name="p1214675663165622"></a><a name="p1214675663165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p153031788165622"><a name="p153031788165622"></a><a name="p153031788165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row886014215165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p306022403165622"><a name="p306022403165622"></a><a name="p306022403165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1196622763165622"><a name="p1196622763165622"></a><a name="p1196622763165622"></a>Incorrect parameter value. </p>
</td>
</tr>
<tr id="row1249457800165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1431350234165622"><a name="p1431350234165622"></a><a name="p1431350234165622"></a>EBADF </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1878728462165622"><a name="p1878728462165622"></a><a name="p1878728462165622"></a>The read-write lock has been damaged during the waiting. </p>
</td>
</tr>
<tr id="row352970737165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2124231440165622"><a name="p2124231440165622"></a><a name="p2124231440165622"></a>EBUSY </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p862124821165622"><a name="p862124821165622"></a><a name="p862124821165622"></a>The read-write lock is already locked. </p>
</td>
</tr>
</tbody>
</table>

## pthread\_rwlock\_unlock\(\)<a name="gaffd8a19e83fc87d865d103d6fbce8c4f"></a>

```
int pthread_rwlock_unlock ([pthread_rwlock_t](UTILS.md#gadc0b6b9df00a6c3ed0d7f9afe8934d05) * rw)
```

 **Description:**

Unlocks a read-write lock. 

If the calling thread attempts to unlock a read-write lock that it has not locked, the unlock request fails and the error code  **EPERM**  is returned. 

**Parameters:**

<a name="table74129300165622"></a>
<table><thead align="left"><tr id="row1640429082165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2069932488165622"><a name="p2069932488165622"></a><a name="p2069932488165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1336298453165622"><a name="p1336298453165622"></a><a name="p1336298453165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1699934399165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">rw</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the read-write lock to unlock. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a value listed in  **errno**  otherwise. 

<a name="table359958031165622"></a>
<table><thead align="left"><tr id="row1508598717165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1159776199165622"><a name="p1159776199165622"></a><a name="p1159776199165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1139461422165622"><a name="p1139461422165622"></a><a name="p1139461422165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row558275298165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p234704596165622"><a name="p234704596165622"></a><a name="p234704596165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p337730126165622"><a name="p337730126165622"></a><a name="p337730126165622"></a>Incorrect parameter value. </p>
</td>
</tr>
<tr id="row1892018559165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1484398170165622"><a name="p1484398170165622"></a><a name="p1484398170165622"></a>EPERM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1694751071165622"><a name="p1694751071165622"></a><a name="p1694751071165622"></a>The read-write lock is not held by the calling thread. </p>
</td>
</tr>
</tbody>
</table>

## pthread\_rwlock\_wrlock\(\)<a name="gaf2ca5563676ae3ac35d3bc7b3547e7f7"></a>

```
int pthread_rwlock_wrlock ([pthread_rwlock_t](UTILS.md#gadc0b6b9df00a6c3ed0d7f9afe8934d05) * rw)
```

 **Description:**

Applies a write lock to a read-write lock. 

**Parameters:**

<a name="table1101490092165622"></a>
<table><thead align="left"><tr id="row607518429165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2061594478165622"><a name="p2061594478165622"></a><a name="p2061594478165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1596068847165622"><a name="p1596068847165622"></a><a name="p1596068847165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1665275347165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">rw</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the read-write lock to lock. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a value listed in  **errno**  otherwise. 

<a name="table849242536165622"></a>
<table><thead align="left"><tr id="row605822418165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p167700359165622"><a name="p167700359165622"></a><a name="p167700359165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1675966514165622"><a name="p1675966514165622"></a><a name="p1675966514165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1782549187165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1947469723165622"><a name="p1947469723165622"></a><a name="p1947469723165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1415322431165622"><a name="p1415322431165622"></a><a name="p1415322431165622"></a>Incorrect parameter value. </p>
</td>
</tr>
<tr id="row2052773392165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1563931580165622"><a name="p1563931580165622"></a><a name="p1563931580165622"></a>EBADF </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p695921738165622"><a name="p695921738165622"></a><a name="p695921738165622"></a>The read-write lock has been damaged during the waiting. </p>
</td>
</tr>
<tr id="row759126793165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p774994770165622"><a name="p774994770165622"></a><a name="p774994770165622"></a>EBUSY </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1592273849165622"><a name="p1592273849165622"></a><a name="p1592273849165622"></a>The read-write lock is already locked. </p>
</td>
</tr>
</tbody>
</table>

## pthread\_rwlockattr\_destroy\(\)<a name="ga78a54e67f0afe2601dbda0a904fa0bdf"></a>

```
int pthread_rwlockattr_destroy ([pthread_rwlockattr_t](UTILS.md#gaac7b93dc39852a3374d6c0802ceb7aa5) * attr)
```

 **Description:**

Destroys a read-write lock attribute object. 

This function always succeeds. 

**Parameters:**

<a name="table1806656091165622"></a>
<table><thead align="left"><tr id="row118146668165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p322098368165622"><a name="p322098368165622"></a><a name="p322098368165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p749670493165622"><a name="p749670493165622"></a><a name="p749670493165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1020071785165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">attr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the read-write lock attribute object to destroy. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**. 

## pthread\_rwlockattr\_init\(\)<a name="ga9d831af0179ed16d1b6cbeba0304810b"></a>

```
int pthread_rwlockattr_init ([pthread_rwlockattr_t](UTILS.md#gaac7b93dc39852a3374d6c0802ceb7aa5) * attr)
```

 **Description:**

Initializes a read-write lock attribute object. 

This function always succeeds. 

**Parameters:**

<a name="table1313430943165622"></a>
<table><thead align="left"><tr id="row2009087505165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p82377426165622"><a name="p82377426165622"></a><a name="p82377426165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p897399225165622"><a name="p897399225165622"></a><a name="p897399225165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row887301953165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">attr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the read-write lock attribute object to initialize. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**. 

## pthread\_self\(\)<a name="ga4c4f5f3b4f8f45d9d897847d53b11aaa"></a>

```
[pthread_t](UTILS.md#ga5250f47a8a0402a78bb51a2133e13c1f) pthread_self (void )
```

 **Description:**

Obtains the ID of the calling thread. 

This function always succeeds. 

**Returns:**

Returns the thread ID. 

## pthread\_setaffinity\_np\(\)<a name="ga217f60f9431c453c74b675e72bba307d"></a>

```
int pthread_setaffinity_np ([pthread_t](UTILS.md#ga5250f47a8a0402a78bb51a2133e13c1f) td, size_t size, const cpu_set_t * set )
```

 **Description:**

Sets the thread affinity. 

**Parameters:**

<a name="table1096420712165622"></a>
<table><thead align="left"><tr id="row190088778165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1086912779165622"><a name="p1086912779165622"></a><a name="p1086912779165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1543101145165622"><a name="p1543101145165622"></a><a name="p1543101145165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1046426810165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">td</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the thread whose affinity is to be changed. </td>
</tr>
<tr id="row786807730165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">size</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">The size of the cpu_set_t struct. </td>
</tr>
<tr id="row1213514743165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">set</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">The pointer to the cpu_set_t struct recording the setting affinity. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a value listed in  **errno**  otherwise. 

<a name="table1098566997165622"></a>
<table><thead align="left"><tr id="row74771013165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p30392442165622"><a name="p30392442165622"></a><a name="p30392442165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1911641207165622"><a name="p1911641207165622"></a><a name="p1911641207165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row44106023165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1675742580165622"><a name="p1675742580165622"></a><a name="p1675742580165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p314320170165622"><a name="p314320170165622"></a><a name="p314320170165622"></a>The size is not equal to the cpu_set_t or the td is invalid. </p>
</td>
</tr>
</tbody>
</table>

## pthread\_setcancelstate\(\)<a name="ga37075410fbbaad7ee93c95375fc86e0e"></a>

```
int pthread_setcancelstate (int state, int * oldstate )
```

 **Description:**

Sets the cancelability state for the calling thread. 

This function sets the cancelability state of the calling thread to the value specified by  **state**. The previous cancelability state is stored in the buffer pointed to by oldstate. 

**Parameters:**

<a name="table898640951165622"></a>
<table><thead align="left"><tr id="row991618914165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2130738738165622"><a name="p2130738738165622"></a><a name="p2130738738165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2120419630165622"><a name="p2120419630165622"></a><a name="p2120419630165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row12276115165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">state</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the cancelability state to set. Available values are as follows: </td>
</tr>
<tr id="row785947252165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">oldstate</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the previous cancelability state before the setting. </td>
</tr>
</tbody>
</table>

<a name="table180566243165622"></a>
<table><thead align="left"><tr id="row329061861165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p632353858165622"><a name="p632353858165622"></a><a name="p632353858165622"></a>state </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1523046119165622"><a name="p1523046119165622"></a><a name="p1523046119165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1274287022165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1854819807165622"><a name="p1854819807165622"></a><a name="p1854819807165622"></a>PTHREAD_CANCEL_ENABLE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1522237899165622"><a name="p1522237899165622"></a><a name="p1522237899165622"></a>The thread is cancelable. </p>
</td>
</tr>
<tr id="row2026565705165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p994167853165622"><a name="p994167853165622"></a><a name="p994167853165622"></a>PTHREAD_CANCEL_DISABLE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1140885743165622"><a name="p1140885743165622"></a><a name="p1140885743165622"></a>The thread is not cancelable. </p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a value listed in  **errno**  otherwise. 

<a name="table1045027306165622"></a>
<table><thead align="left"><tr id="row1779008315165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p267310328165622"><a name="p267310328165622"></a><a name="p267310328165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1577478703165622"><a name="p1577478703165622"></a><a name="p1577478703165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row870058017165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1218884252165622"><a name="p1218884252165622"></a><a name="p1218884252165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p945134139165622"><a name="p945134139165622"></a><a name="p945134139165622"></a>Invalid parameter. </p>
</td>
</tr>
</tbody>
</table>

## pthread\_setcanceltype\(\)<a name="gaab579bcfcf0662a0c1e35fd82162e61d"></a>

```
int pthread_setcanceltype (int type, int * oldtype )
```

 **Description:**

Sets the cancelability type for the calling thread. 

This function sets the cancelability type of the calling thread to the value specified by  **type**. The previous cancelability type is stored in the buffer pointed to by oldtype. 

**Parameters:**

<a name="table1123286687165622"></a>
<table><thead align="left"><tr id="row1619120133165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p376229122165622"><a name="p376229122165622"></a><a name="p376229122165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p993794868165622"><a name="p993794868165622"></a><a name="p993794868165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1521123391165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">type</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the cancelability type to set. Available values are as follows: </td>
</tr>
<tr id="row793174059165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">oldtype</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the previous cancelability type before the setting. </td>
</tr>
</tbody>
</table>

<a name="table1521563428165622"></a>
<table><thead align="left"><tr id="row329750703165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2089813124165622"><a name="p2089813124165622"></a><a name="p2089813124165622"></a>type </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p311141168165622"><a name="p311141168165622"></a><a name="p311141168165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row763722154165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p358790586165622"><a name="p358790586165622"></a><a name="p358790586165622"></a>PTHREAD_CANCEL_DEFERRED </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1149038704165622"><a name="p1149038704165622"></a><a name="p1149038704165622"></a>The thread is canceled until the next cancellation point. </p>
</td>
</tr>
<tr id="row333962628165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p306094308165622"><a name="p306094308165622"></a><a name="p306094308165622"></a>PTHREAD_CANCEL_ASYNCHRONOUS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1105781805165622"><a name="p1105781805165622"></a><a name="p1105781805165622"></a>The thread is canceled immediately upon receiving a cancellation request. </p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a value listed in  **errno**  otherwise. 

<a name="table1881074197165622"></a>
<table><thead align="left"><tr id="row1829079823165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1505206490165622"><a name="p1505206490165622"></a><a name="p1505206490165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p590016696165622"><a name="p590016696165622"></a><a name="p590016696165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1662548831165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p690566070165622"><a name="p690566070165622"></a><a name="p690566070165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1154994594165622"><a name="p1154994594165622"></a><a name="p1154994594165622"></a>Invalid parameter. </p>
</td>
</tr>
</tbody>
</table>

## pthread\_setname\_np\(\)<a name="ga185584d77295432838d8b839d916f160"></a>

```
int pthread_setname_np ([pthread_t](UTILS.md#ga5250f47a8a0402a78bb51a2133e13c1f) pthread, const char * name )
```

 **Description:**

Sets the thread name. 

**Parameters:**

<a name="table592653818165622"></a>
<table><thead align="left"><tr id="row361998576165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p937683240165622"><a name="p937683240165622"></a><a name="p937683240165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p438884692165622"><a name="p438884692165622"></a><a name="p438884692165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1569287225165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">thread</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the thread whose name is to be changed. </td>
</tr>
<tr id="row658129667165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">name</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the thread name to set. The value contains a maximum of 16 characters, including the terminating null byte ('\0'). </td>
</tr>
</tbody>
</table>

**Attention:**

Currently, a thread can change its own thread name only. 

**Returns:**

Returns  **0**  if the operation is successful; returns a value listed in  **errno**  otherwise. 

<a name="table1137854875165622"></a>
<table><thead align="left"><tr id="row1545218332165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1647324219165622"><a name="p1647324219165622"></a><a name="p1647324219165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1576593889165622"><a name="p1576593889165622"></a><a name="p1576593889165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1336599802165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p958208225165622"><a name="p958208225165622"></a><a name="p958208225165622"></a>ERANGE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2047735011165622"><a name="p2047735011165622"></a><a name="p2047735011165622"></a>The name is too long. </p>
</td>
</tr>
<tr id="row1598740106165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p199052130165622"><a name="p199052130165622"></a><a name="p199052130165622"></a>EPERM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p371525494165622"><a name="p371525494165622"></a><a name="p371525494165622"></a>Failed to copy data from the user-level thread. </p>
</td>
</tr>
</tbody>
</table>

## pthread\_setschedparam\(\)<a name="ga14f50e1f5d815c90f1f4225eca5d3a8c"></a>

```
int pthread_setschedparam ([pthread_t](UTILS.md#ga5250f47a8a0402a78bb51a2133e13c1f) thread, int policy, const struct [sched_param](sched_param.md) * param )
```

 **Description:**

Sets a scheduling policy and parameters for a thread. 

**Parameters:**

<a name="table185237200165622"></a>
<table><thead align="left"><tr id="row1292711312165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p262064958165622"><a name="p262064958165622"></a><a name="p262064958165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p790578729165622"><a name="p790578729165622"></a><a name="p790578729165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1510871871165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">thread</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the target thread. </td>
</tr>
<tr id="row2024218047165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">policy</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the scheduling policy to set. The value can only be <strong id="b885920700165622"><a name="b885920700165622"></a><a name="b885920700165622"></a>SCHED_FIFO</strong> or <strong id="b1816263283165622"><a name="b1816263283165622"></a><a name="b1816263283165622"></a>SCHED_RR</strong>. </td>
</tr>
<tr id="row666208227165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">param</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the scheduling parameters to set. Only the thread priority is supported. The priority ranges from 0 (highest priority) to 31 (lowest priority). </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a value listed in  **errno**  otherwise. If the operation fails, the scheduling policy and parameters of the target thread remain unchanged. 

<a name="table813619942165622"></a>
<table><thead align="left"><tr id="row136715917165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1343317554165622"><a name="p1343317554165622"></a><a name="p1343317554165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p546060142165622"><a name="p546060142165622"></a><a name="p546060142165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row379699212165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p331997069165622"><a name="p331997069165622"></a><a name="p331997069165622"></a>ESRCH </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1247988550165622"><a name="p1247988550165622"></a><a name="p1247988550165622"></a>Invalid thread ID. </p>
</td>
</tr>
<tr id="row584559076165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p464689000165622"><a name="p464689000165622"></a><a name="p464689000165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p876203640165622"><a name="p876203640165622"></a><a name="p876203640165622"></a>Invalid parameter. </p>
</td>
</tr>
<tr id="row125873654165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1719307792165622"><a name="p1719307792165622"></a><a name="p1719307792165622"></a>EPERM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1830211553165622"><a name="p1830211553165622"></a><a name="p1830211553165622"></a>No permission to set the specified scheduling policy and parameters. </p>
</td>
</tr>
</tbody>
</table>

## pthread\_setschedprio\(\)<a name="ga7a23cbcfc21a4e3edf531ed65f022370"></a>

```
int pthread_setschedprio ([pthread_t](UTILS.md#ga5250f47a8a0402a78bb51a2133e13c1f) thread, int prio )
```

 **Description:**

Sets a static scheduling priority for a thread. 

**Parameters:**

<a name="table1905946359165622"></a>
<table><thead align="left"><tr id="row1723085457165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1624223321165622"><a name="p1624223321165622"></a><a name="p1624223321165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p843684847165622"><a name="p843684847165622"></a><a name="p843684847165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1420332376165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">thread</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the target thread. </td>
</tr>
<tr id="row1725323096165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">priority</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the static scheduling priority to set. The value ranges from 0 (highest priority) to 31 (lowest priority). </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a value listed in  **errno**  otherwise. If the operation fails, the scheduling policy of the target thread remains unchanged. 

<a name="table637649811165622"></a>
<table><thead align="left"><tr id="row1652568005165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1328054224165622"><a name="p1328054224165622"></a><a name="p1328054224165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p708478321165622"><a name="p708478321165622"></a><a name="p708478321165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row713691539165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2003753802165622"><a name="p2003753802165622"></a><a name="p2003753802165622"></a>ESRCH </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p916987776165622"><a name="p916987776165622"></a><a name="p916987776165622"></a>Invalid thread ID. </p>
</td>
</tr>
<tr id="row1105152955165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1603638191165622"><a name="p1603638191165622"></a><a name="p1603638191165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p756220779165622"><a name="p756220779165622"></a><a name="p756220779165622"></a>Invalid parameter. </p>
</td>
</tr>
<tr id="row1243904336165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p404206004165622"><a name="p404206004165622"></a><a name="p404206004165622"></a>EPERM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p312774113165622"><a name="p312774113165622"></a><a name="p312774113165622"></a>No permission to set the specified scheduling policy and parameters. </p>
</td>
</tr>
</tbody>
</table>

## pthread\_setspecific\(\)<a name="ga2187333dd46ce08d9d2e044f79fad705"></a>

```
int pthread_setspecific ([pthread_key_t](UTILS.md#gafeedfceab43831b6771f80aff6a519be) key, const void * value )
```

 **Description:**

Sets specific thread data. 

This function always succeeds. 

**Parameters:**

<a name="table1605637807165622"></a>
<table><thead align="left"><tr id="row1397893297165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1281203937165622"><a name="p1281203937165622"></a><a name="p1281203937165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p150690702165622"><a name="p150690702165622"></a><a name="p150690702165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1193445262165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">key</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the key bound to the thread data. </td>
</tr>
<tr id="row380785009165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the thread data to be bound to the key. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**. 

## pthread\_spin\_destroy\(\)<a name="ga822c2ff425ddad4c25b6a6092c6effff"></a>

```
int pthread_spin_destroy ([pthread_spinlock_t](UTILS.md#gae13db7661b1f8f7028dd7a88c8185fd2) * s)
```

 **Description:**

Destroys a spin lock. 

This function always succeeds. 

**Parameters:**

<a name="table632699639165622"></a>
<table><thead align="left"><tr id="row1664910283165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p719806827165622"><a name="p719806827165622"></a><a name="p719806827165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p927820478165622"><a name="p927820478165622"></a><a name="p927820478165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row235570254165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">s</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the spin lock to destroy. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**. 

## pthread\_spin\_init\(\)<a name="ga665a56a7bed60c8eaa6c28af40d13cd4"></a>

```
int pthread_spin_init ([pthread_spinlock_t](UTILS.md#gae13db7661b1f8f7028dd7a88c8185fd2) * s, int shared )
```

 **Description:**

Initializes a spin lock. 

This function always succeeds. 

**Parameters:**

<a name="table441755809165622"></a>
<table><thead align="left"><tr id="row1532431567165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p525372263165622"><a name="p525372263165622"></a><a name="p525372263165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1887377924165622"><a name="p1887377924165622"></a><a name="p1887377924165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row436726057165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">s</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the spin lock to initialize. </td>
</tr>
<tr id="row1147450106165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">shared</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates thread process-shared synchronization, which is not supported. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**. 

## pthread\_spin\_lock\(\)<a name="ga62cfd14d1f937a6e8f966e3a331bcf94"></a>

```
int pthread_spin_lock ([pthread_spinlock_t](UTILS.md#gae13db7661b1f8f7028dd7a88c8185fd2) * s)
```

 **Description:**

Locks a spin lock. 

This function always succeeds. 

**Parameters:**

<a name="table1316846570165622"></a>
<table><thead align="left"><tr id="row299081496165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1583424016165622"><a name="p1583424016165622"></a><a name="p1583424016165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p359213436165622"><a name="p359213436165622"></a><a name="p359213436165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2091866456165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">s</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the spin lock to lock. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**. 

## pthread\_spin\_trylock\(\)<a name="ga084834fa2d06f173f086ce23ec1ea5d9"></a>

```
int pthread_spin_trylock ([pthread_spinlock_t](UTILS.md#gae13db7661b1f8f7028dd7a88c8185fd2) * s)
```

 **Description:**

Attempts to lock a spin lock. 

This function attempts to lock the spin lock, without blocking the calling thread. If the spin lock is already locked, the error code  **EBUSY**  is returned immediately. 

**Parameters:**

<a name="table496595288165622"></a>
<table><thead align="left"><tr id="row2133274844165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1692020931165622"><a name="p1692020931165622"></a><a name="p1692020931165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p203179313165622"><a name="p203179313165622"></a><a name="p203179313165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1153743835165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">s</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the spin lock to lock. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a value listed in  **errno**  otherwise. 

<a name="table1505513272165622"></a>
<table><thead align="left"><tr id="row972366816165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p669611726165622"><a name="p669611726165622"></a><a name="p669611726165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1057195816165622"><a name="p1057195816165622"></a><a name="p1057195816165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row352483838165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1664524715165622"><a name="p1664524715165622"></a><a name="p1664524715165622"></a>EBUSY </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p762344584165622"><a name="p762344584165622"></a><a name="p762344584165622"></a>The spin lock has been held by another thread. </p>
</td>
</tr>
</tbody>
</table>

## pthread\_spin\_unlock\(\)<a name="ga3fe246007a85cee9d5f7af9b7d592b54"></a>

```
int pthread_spin_unlock ([pthread_spinlock_t](UTILS.md#gae13db7661b1f8f7028dd7a88c8185fd2) * s)
```

 **Description:**

Unlocks a spin lock. 

This function always succeeds. 

**Parameters:**

<a name="table2141054275165622"></a>
<table><thead align="left"><tr id="row1184306807165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p676107246165622"><a name="p676107246165622"></a><a name="p676107246165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p609069092165622"><a name="p609069092165622"></a><a name="p609069092165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1109410023165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">s</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the spin lock to unlock. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**. 

## pthread\_testcancel\(\)<a name="gaf1c95282ab2bea25f0888a19652cd41f"></a>

```
void pthread_testcancel (void )
```

 **Description:**

Requests delivery of any pending cancellation request. 

This function creates a cancellation point in the calling thread. In this way, the thread executing code that contains no cancellation point responds to the cancellation request. This function always succeeds. 

**Returns:**

Returns the cancellation point. 

## sched\_get\_priority\_max\(\)<a name="gafaebd1698caeb9b9b9e614ad84edd609"></a>

```
int sched_get_priority_max (int policy)
```

 **Description:**

Obtains the maximum static priority that can be used for a process. 

This function returns the lowest priority of process scheduling in a scheduling policy specified by  **policy**. The value of  **policy**  must be a value defined in  [sched.h](sched-h.md). 

**Parameters:**

<a name="table2094105604165622"></a>
<table><thead align="left"><tr id="row223592368165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p221657462165622"><a name="p221657462165622"></a><a name="p221657462165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1533463120165622"><a name="p1533463120165622"></a><a name="p1533463120165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row51368090165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">policy</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the scheduling policy. The value can be <strong id="b842313815165622"><a name="b842313815165622"></a><a name="b842313815165622"></a>SCHED_FIFO</strong> or <strong id="b1734402857165622"><a name="b1734402857165622"></a><a name="b1734402857165622"></a>SCHED_RR</strong>, but not <strong id="b16647062165622"><a name="b16647062165622"></a><a name="b16647062165622"></a>SCHED_OTHER</strong>, <strong id="b1306355196165622"><a name="b1306355196165622"></a><a name="b1306355196165622"></a>SCHED_BATCH</strong>, <strong id="b2034006347165622"><a name="b2034006347165622"></a><a name="b2034006347165622"></a>SCHED_IDLE</strong>, or <strong id="b234952843165622"><a name="b234952843165622"></a><a name="b234952843165622"></a>SCHED_DEADLINE</strong>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the lowest priority of the scheduling policy if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table1489591894165622"></a>
<table><thead align="left"><tr id="row1893287200165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p656517924165622"><a name="p656517924165622"></a><a name="p656517924165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p81775600165622"><a name="p81775600165622"></a><a name="p81775600165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1103324600165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2092294800165622"><a name="p2092294800165622"></a><a name="p2092294800165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1296493165165622"><a name="p1296493165165622"></a><a name="p1296493165165622"></a>Invalid parameter. The value of <strong id="b425498710165622"><a name="b425498710165622"></a><a name="b425498710165622"></a>policy</strong> is not a defined scheduling policy. </p>
</td>
</tr>
</tbody>
</table>

## sched\_get\_priority\_min\(\)<a name="gaf1f370fc36ea6b22ed42b5ee3cf82a81"></a>

```
int sched_get_priority_min (int policy)
```

 **Description:**

Obtains the minimum static priority that can be used for a process. 

This function returns the highest priority of process scheduling in a scheduling policy specified by  **policy**. The value of  **policy**  must be a value defined in  [sched.h](sched-h.md). 

**Parameters:**

<a name="table695775394165622"></a>
<table><thead align="left"><tr id="row1114838821165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1026781527165622"><a name="p1026781527165622"></a><a name="p1026781527165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p279411544165622"><a name="p279411544165622"></a><a name="p279411544165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1796697068165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">policy</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the scheduling policy. The value can be <strong id="b1021386388165622"><a name="b1021386388165622"></a><a name="b1021386388165622"></a>SCHED_FIFO</strong> or <strong id="b378891558165622"><a name="b378891558165622"></a><a name="b378891558165622"></a>SCHED_RR</strong>, but not <strong id="b1788766964165622"><a name="b1788766964165622"></a><a name="b1788766964165622"></a>SCHED_OTHER</strong>, <strong id="b600322768165622"><a name="b600322768165622"></a><a name="b600322768165622"></a>SCHED_BATCH</strong>, <strong id="b266035722165622"><a name="b266035722165622"></a><a name="b266035722165622"></a>SCHED_IDLE</strong>, or <strong id="b1179227459165622"><a name="b1179227459165622"></a><a name="b1179227459165622"></a>SCHED_DEADLINE</strong>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the highest priority of the scheduling policy if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table452011454165622"></a>
<table><thead align="left"><tr id="row1549979001165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1707064860165622"><a name="p1707064860165622"></a><a name="p1707064860165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p140623796165622"><a name="p140623796165622"></a><a name="p140623796165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1107423701165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1660175432165622"><a name="p1660175432165622"></a><a name="p1660175432165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p724594608165622"><a name="p724594608165622"></a><a name="p724594608165622"></a>Invalid parameter. The value of <strong id="b1914265645165622"><a name="b1914265645165622"></a><a name="b1914265645165622"></a>policy</strong> is not a defined scheduling policy. </p>
</td>
</tr>
</tbody>
</table>

## sched\_getparam\(\)<a name="ga563c7ac53bac2c1b51379147e66c44ec"></a>

```
int sched_getparam ([pid_t](UTILS.md#ga30c34d3eead853c44f459f21b932984c) pid, struct [sched_param](sched_param.md) * param )
```

 **Description:**

Obtains scheduling parameters of a process. 

**Parameters:**

<a name="table1697551495165622"></a>
<table><thead align="left"><tr id="row579613311165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1666394631165622"><a name="p1666394631165622"></a><a name="p1666394631165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p842788453165622"><a name="p842788453165622"></a><a name="p842788453165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1839724309165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">pid</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the ID of the process for which the scheduling parameters are to be obtained. If this parameter is set to <strong id="b1611322619165622"><a name="b1611322619165622"></a><a name="b1611322619165622"></a>0</strong>, the scheduling parameters of the calling process are to be obtained. </td>
</tr>
<tr id="row915893220165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">param</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the scheduling parameters. Only the static priority is supported. The priority ranges from 10 (highest priority) to 31 (lowest priority). </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table1276805102165622"></a>
<table><thead align="left"><tr id="row137585845165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1999777684165622"><a name="p1999777684165622"></a><a name="p1999777684165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1559656793165622"><a name="p1559656793165622"></a><a name="p1559656793165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row130788593165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p664252268165622"><a name="p664252268165622"></a><a name="p664252268165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p695112912165622"><a name="p695112912165622"></a><a name="p695112912165622"></a>Invalid parameter. </p>
</td>
</tr>
<tr id="row1490677574165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p629067165622"><a name="p629067165622"></a><a name="p629067165622"></a>ESRCH </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1578335291165622"><a name="p1578335291165622"></a><a name="p1578335291165622"></a>The process specified by <strong id="b1312782615165622"><a name="b1312782615165622"></a><a name="b1312782615165622"></a>pid</strong> cannot be found. </p>
</td>
</tr>
</tbody>
</table>

## sched\_getscheduler\(\)<a name="ga99fcb2532b1482d236dc04495a3f194d"></a>

```
int sched_getscheduler ([pid_t](UTILS.md#ga30c34d3eead853c44f459f21b932984c) pid)
```

 **Description:**

Obtains the scheduling policy of a process. 

**Parameters:**

<a name="table427786527165622"></a>
<table><thead align="left"><tr id="row2144245891165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p281503714165622"><a name="p281503714165622"></a><a name="p281503714165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p108314544165622"><a name="p108314544165622"></a><a name="p108314544165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row713923375165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">pid</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the ID of the process for which the scheduling policy is to be obtained. If this parameter is set to <strong id="b623390903165622"><a name="b623390903165622"></a><a name="b623390903165622"></a>0</strong>, the scheduling policy of the calling process is to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table1805882733165622"></a>
<table><thead align="left"><tr id="row1951483849165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p434831099165622"><a name="p434831099165622"></a><a name="p434831099165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p48620083165622"><a name="p48620083165622"></a><a name="p48620083165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row958896919165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1862214174165622"><a name="p1862214174165622"></a><a name="p1862214174165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1754626394165622"><a name="p1754626394165622"></a><a name="p1754626394165622"></a>Invalid parameter. </p>
</td>
</tr>
<tr id="row1189163330165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1865462486165622"><a name="p1865462486165622"></a><a name="p1865462486165622"></a>EPERM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2068825275165622"><a name="p2068825275165622"></a><a name="p2068825275165622"></a>No permission. </p>
</td>
</tr>
<tr id="row1214302436165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2030849407165622"><a name="p2030849407165622"></a><a name="p2030849407165622"></a>ESRCH </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1479566726165622"><a name="p1479566726165622"></a><a name="p1479566726165622"></a>The process specified by <strong id="b1528379386165622"><a name="b1528379386165622"></a><a name="b1528379386165622"></a>pid</strong> cannot be found. </p>
</td>
</tr>
</tbody>
</table>

## sched\_rr\_get\_interval\(\)<a name="ga484f0eb93529d29a66e24485725c4c7b"></a>

```
int sched_rr_get_interval ([pid_t](UTILS.md#ga30c34d3eead853c44f459f21b932984c) pid, struct [timespec](timespec.md) * interval )
```

 **Description:**

Obtains the execution time limit of a process. 

This function updates the  **timespec**  structure referenced by the parameter  **interval**  to record the execution time limit of a process. 

**Parameters:**

<a name="table1011016157165622"></a>
<table><thead align="left"><tr id="row1073682550165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1289678003165622"><a name="p1289678003165622"></a><a name="p1289678003165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p328856656165622"><a name="p328856656165622"></a><a name="p328856656165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row858090260165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">pid</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the ID of the process for which the execution time limit is to be obtained. If this parameter is &lt;0&gt;0, the time quantum of the calling process is obtained and written into the parameter <strong id="b611143419165622"><a name="b611143419165622"></a><a name="b611143419165622"></a>interval</strong>. </td>
</tr>
<tr id="row644625371165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">interval</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the time structure that records the time limit. The time structure supports only seconds and nanoseconds. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table114040919165622"></a>
<table><thead align="left"><tr id="row198180207165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p566666743165622"><a name="p566666743165622"></a><a name="p566666743165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1821626517165622"><a name="p1821626517165622"></a><a name="p1821626517165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row151529815165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1925560394165622"><a name="p1925560394165622"></a><a name="p1925560394165622"></a>EFAULT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1871913736165622"><a name="p1871913736165622"></a><a name="p1871913736165622"></a>An error occurred when copying information to the user space. </p>
</td>
</tr>
<tr id="row1330864117165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1477094590165622"><a name="p1477094590165622"></a><a name="p1477094590165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2000109641165622"><a name="p2000109641165622"></a><a name="p2000109641165622"></a>Invalid parameter. </p>
</td>
</tr>
<tr id="row1741827894165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p681915708165622"><a name="p681915708165622"></a><a name="p681915708165622"></a>ESRCH </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p39911408165622"><a name="p39911408165622"></a><a name="p39911408165622"></a>The process specified by <strong id="b651211986165622"><a name="b651211986165622"></a><a name="b651211986165622"></a>pid</strong> cannot be found. </p>
</td>
</tr>
</tbody>
</table>

## sched\_setparam\(\)<a name="ga06b497c4ea6bbabd2b62ba1a8a848a1b"></a>

```
int sched_setparam ([pid_t](UTILS.md#ga30c34d3eead853c44f459f21b932984c) pid, const struct [sched_param](sched_param.md) * param )
```

 **Description:**

Sets scheduling parameters related to a scheduling policy for a process. 

 

**Parameters:**

<a name="table315720785165622"></a>
<table><thead align="left"><tr id="row1586491647165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2071436503165622"><a name="p2071436503165622"></a><a name="p2071436503165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p738362647165622"><a name="p738362647165622"></a><a name="p738362647165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row44018507165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">pid</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the ID of the process for which the scheduling parameters are to be set. If this parameter is set to <strong id="b1217575109165622"><a name="b1217575109165622"></a><a name="b1217575109165622"></a>0</strong>, the scheduling parameters of the calling process are to be set. </td>
</tr>
<tr id="row1423039000165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">param</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the scheduling parameters to set. Only the static priority can be set. The priority ranges from 10 (highest priority) to 31 (lowest priority). </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table1879841374165622"></a>
<table><thead align="left"><tr id="row1102443104165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p178287996165622"><a name="p178287996165622"></a><a name="p178287996165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p257045314165622"><a name="p257045314165622"></a><a name="p257045314165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row774409609165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p860840903165622"><a name="p860840903165622"></a><a name="p860840903165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1468283995165622"><a name="p1468283995165622"></a><a name="p1468283995165622"></a>Invalid parameter. </p>
</td>
</tr>
<tr id="row326938188165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2001273812165622"><a name="p2001273812165622"></a><a name="p2001273812165622"></a>EPERM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p975563010165622"><a name="p975563010165622"></a><a name="p975563010165622"></a>No permission. </p>
</td>
</tr>
<tr id="row465367187165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p544765454165622"><a name="p544765454165622"></a><a name="p544765454165622"></a>ESRCH </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p64867800165622"><a name="p64867800165622"></a><a name="p64867800165622"></a>The process specified by <strong id="b1713151867165622"><a name="b1713151867165622"></a><a name="b1713151867165622"></a>pid</strong> cannot be found. </p>
</td>
</tr>
</tbody>
</table>

## sched\_setscheduler\(\)<a name="ga84ad29a6f2ad27370df09c664ac65eac"></a>

```
int sched_setscheduler ([pid_t](UTILS.md#ga30c34d3eead853c44f459f21b932984c) pid, int policy, const struct [sched_param](sched_param.md) * param )
```

 **Description:**

Sets a scheduling policy for a process. 

**Parameters:**

<a name="table837133727165622"></a>
<table><thead align="left"><tr id="row582248495165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1562306300165622"><a name="p1562306300165622"></a><a name="p1562306300165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1068517715165622"><a name="p1068517715165622"></a><a name="p1068517715165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row858111610165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">pid</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the ID of the process for which the scheduling policy and parameters are to be set. If this parameter is set to <strong id="b1773093028165622"><a name="b1773093028165622"></a><a name="b1773093028165622"></a>0</strong>, the scheduling policy and parameters of the calling process are to be set. </td>
</tr>
<tr id="row469327980165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">policy</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the scheduling policy to set. The value can be <strong id="b205520784165622"><a name="b205520784165622"></a><a name="b205520784165622"></a>SCHED_FIFO</strong> or <strong id="b576545750165622"><a name="b576545750165622"></a><a name="b576545750165622"></a>SCHED_RR</strong>, but not <strong id="b590496727165622"><a name="b590496727165622"></a><a name="b590496727165622"></a>SCHED_OTHER</strong>, <strong id="b478239087165622"><a name="b478239087165622"></a><a name="b478239087165622"></a>SCHED_BATCH</strong>, <strong id="b1575355048165622"><a name="b1575355048165622"></a><a name="b1575355048165622"></a>SCHED_IDLE</strong>, or <strong id="b751799914165622"><a name="b751799914165622"></a><a name="b751799914165622"></a>SCHED_DEADLINE</strong>. </td>
</tr>
<tr id="row1460244952165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">param</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the scheduling parameters to set. Only the static priority can be set. The priority ranges from 10 (highest priority) to 31 (lowest priority). </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table1305994290165622"></a>
<table><thead align="left"><tr id="row1726340119165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2037764282165622"><a name="p2037764282165622"></a><a name="p2037764282165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1924693429165622"><a name="p1924693429165622"></a><a name="p1924693429165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row110175911165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1848211168165622"><a name="p1848211168165622"></a><a name="p1848211168165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1978109301165622"><a name="p1978109301165622"></a><a name="p1978109301165622"></a>Invalid parameter. </p>
</td>
</tr>
<tr id="row727578251165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1263910392165622"><a name="p1263910392165622"></a><a name="p1263910392165622"></a>EPERM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1048088016165622"><a name="p1048088016165622"></a><a name="p1048088016165622"></a>No permission. </p>
</td>
</tr>
<tr id="row624127377165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p201993088165622"><a name="p201993088165622"></a><a name="p201993088165622"></a>ESRCH </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p260863513165622"><a name="p260863513165622"></a><a name="p260863513165622"></a>The process specified by <strong id="b1735528282165622"><a name="b1735528282165622"></a><a name="b1735528282165622"></a>pid</strong> cannot be found. </p>
</td>
</tr>
</tbody>
</table>

## sched\_yield\(\)<a name="ga357cd4b34c13011749dfffb42b489f09"></a>

```
int sched_yield (void )
```

 **Description:**

Yields the running process. 

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  otherwise. 

## setpriority\(\)<a name="ga0a8d4c8043a7748c25dd551dc69dcad2"></a>

```
int setpriority (int which, [id_t](UTILS.md#gab66157aef1dc726dccc825f07239da53) who, int value )
```

 **Description:**

Sets the static priority of a specified ID. 

The ID type is determined by  **which**. 

**Parameters:**

<a name="table284792680165622"></a>
<table><thead align="left"><tr id="row875046162165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p536065190165622"><a name="p536065190165622"></a><a name="p536065190165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p406452565165622"><a name="p406452565165622"></a><a name="p406452565165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1115750966165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">which</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates a specified value, which can be: <a name="ul1271614817165622"></a><a name="ul1271614817165622"></a><ul id="ul1271614817165622"><li> PRIO_PROCESS: represents a process ID specified by <strong id="b1647139316165622"><a name="b1647139316165622"></a><a name="b1647139316165622"></a>who</strong>. </li><li> PRIO_PGRP: represents a process group ID specified by <strong id="b1502221146165622"><a name="b1502221146165622"></a><a name="b1502221146165622"></a>who</strong>. This value is not supported yet. </li><li> PRIO_USER: represents a valid user ID specified by <strong id="b324226322165622"><a name="b324226322165622"></a><a name="b324226322165622"></a>who</strong>. This value is not supported yet. </li></ul>
 </td>
</tr>
<tr id="row1440219205165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">who</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the specified ID. </td>
</tr>
<tr id="row260360146165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the target priority to set. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns 0 if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table otherwise. 

<a name="table1587255317165622"></a>
<table><thead align="left"><tr id="row489811202165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p248330158165622"><a name="p248330158165622"></a><a name="p248330158165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1551361692165622"><a name="p1551361692165622"></a><a name="p1551361692165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1959217269165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p720217186165622"><a name="p720217186165622"></a><a name="p720217186165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1011389920165622"><a name="p1011389920165622"></a><a name="p1011389920165622"></a>Invalid parameter. </p>
</td>
</tr>
<tr id="row792683144165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p519092272165622"><a name="p519092272165622"></a><a name="p519092272165622"></a>EPERM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p649916906165622"><a name="p649916906165622"></a><a name="p649916906165622"></a>The operation is not allowed. </p>
</td>
</tr>
<tr id="row1443309169165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1351679390165622"><a name="p1351679390165622"></a><a name="p1351679390165622"></a>EOPNOTSUPP </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p934902533165622"><a name="p934902533165622"></a><a name="p934902533165622"></a>Unsupported value. </p>
</td>
</tr>
</tbody>
</table>

## wait\(\)<a name="gabf2fbcf6df59fd5234e9eed4db1a1804"></a>

```
[pid_t](UTILS.md#ga30c34d3eead853c44f459f21b932984c) wait (int * status)
```

 **Description:**

Waits for any child process to end and reclaims its resources. 

**Parameters:**

<a name="table892228874165622"></a>
<table><thead align="left"><tr id="row41734045165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1667522597165622"><a name="p1667522597165622"></a><a name="p1667522597165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1118370458165622"><a name="p1118370458165622"></a><a name="p1118370458165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1202148504165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">status</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the obtained status information. If this parameter is not <strong id="b1366729468165622"><a name="b1366729468165622"></a><a name="b1366729468165622"></a>NULL</strong>, the status information is stored in the int value that it points to. You can use the following macros defined in <strong id="b1731552596165622"><a name="b1731552596165622"></a><a name="b1731552596165622"></a>private.h</strong> to check the integer (the macro uses the integer as a parameter instead of the pointer that points to it): <a name="ul1691324368165622"></a><a name="ul1691324368165622"></a><ul id="ul1691324368165622"><li> <strong id="b578536060165622"><a name="b578536060165622"></a><a name="b578536060165622"></a>WIFEXITED(status)</strong>: If the child process ends normally, <strong id="b5021466165622"><a name="b5021466165622"></a><a name="b5021466165622"></a>true</strong> is returned. Otherwise, <strong id="b1611090332165622"><a name="b1611090332165622"></a><a name="b1611090332165622"></a>false</strong> is returned. </li><li> <strong id="b311584676165622"><a name="b311584676165622"></a><a name="b311584676165622"></a>WEXITSTATUS(status)</strong>: If <strong id="b417175165165622"><a name="b417175165165622"></a><a name="b417175165165622"></a>WIFEXITED(status)</strong> is <strong id="b1321755387165622"><a name="b1321755387165622"></a><a name="b1321755387165622"></a>true</strong>, this macro can be used to obtain the exit code that the child process passed to <a href="UTILS.md#ga55e99c539cf7723ec15e856b7e0a8cee">exit()</a>. </li><li> <strong id="b1935759413165622"><a name="b1935759413165622"></a><a name="b1935759413165622"></a>WTERMSIG(status)</strong>: After a child process ends abnormally, the parent process can obtain the child process exit code <a href="IPC.md#gabaaa61abe503c43481e35e21b0b5a031">SIGUSR2</a> through <strong id="b1270533481165622"><a name="b1270533481165622"></a><a name="b1270533481165622"></a>WTERMSIG</strong>, indicating that the child process ends abnormally. This is the only case supported.</li></ul>
 </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the child process ID if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table344921102165622"></a>
<table><thead align="left"><tr id="row719652649165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p245250572165622"><a name="p245250572165622"></a><a name="p245250572165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p378712874165622"><a name="p378712874165622"></a><a name="p378712874165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row530229523165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1760037584165622"><a name="p1760037584165622"></a><a name="p1760037584165622"></a>ECHILD </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p875003120165622"><a name="p875003120165622"></a><a name="p875003120165622"></a>The child process does not exist, or the specified process group does not exist. </p>
</td>
</tr>
<tr id="row2023361797165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p503496823165622"><a name="p503496823165622"></a><a name="p503496823165622"></a>ESRCH </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1582251696165622"><a name="p1582251696165622"></a><a name="p1582251696165622"></a>The child process ends abnormally. </p>
</td>
</tr>
</tbody>
</table>

## waitpid\(\)<a name="ga77de8005691d1f125540d66032a3cc62"></a>

```
[pid_t](UTILS.md#ga30c34d3eead853c44f459f21b932984c) waitpid ([pid_t](UTILS.md#ga30c34d3eead853c44f459f21b932984c) pid, int * status, int options )
```

 **Description:**

Waits for a specified child process to end and reclaims its resources. 

**Parameters:**

<a name="table1225832001165622"></a>
<table><thead align="left"><tr id="row310163541165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p195993923165622"><a name="p195993923165622"></a><a name="p195993923165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p147526791165622"><a name="p147526791165622"></a><a name="p147526791165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1281704600165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">pid</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the ID of the child process to wait for. <a name="ul1060233211165622"></a><a name="ul1060233211165622"></a><ul id="ul1060233211165622"><li> If this parameter is less than <strong id="b35981248165622"><a name="b35981248165622"></a><a name="b35981248165622"></a>-1</strong>, the system waits for any child process whose process group ID is the absolute value of <strong id="b1964704916165622"><a name="b1964704916165622"></a><a name="b1964704916165622"></a>pid</strong>. </li><li> If this parameter is <strong id="b804503545165622"><a name="b804503545165622"></a><a name="b804503545165622"></a>-1</strong>, the system waits for any child process. In this case, this function is equivalent to <a href="PROCESS.md#gabf2fbcf6df59fd5234e9eed4db1a1804">wait()</a>. </li><li> If this parameter is <strong id="b1264509456165622"><a name="b1264509456165622"></a><a name="b1264509456165622"></a>0</strong>, the system waits for a child process whose process group ID is the same as the calling process (any process that is in the same process group as the calling process). </li><li> If this parameter is greater than <strong id="b956954998165622"><a name="b956954998165622"></a><a name="b956954998165622"></a>0</strong>, the system waits for the child process whose process ID is the value of <strong id="b143744736165622"><a name="b143744736165622"></a><a name="b143744736165622"></a>pid</strong>.</li></ul>
 </td>
</tr>
<tr id="row555803611165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">status</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the obtained status information. If this parameter is not <strong id="b658135639165622"><a name="b658135639165622"></a><a name="b658135639165622"></a>NULL</strong>, the status information is stored in the int value that it points to. You can use the following macros defined in <strong id="b1556981180165622"><a name="b1556981180165622"></a><a name="b1556981180165622"></a>private.h</strong> to check the integer (the macro uses the integer as a parameter instead of the pointer that points to it): <a name="ul906814543165622"></a><a name="ul906814543165622"></a><ul id="ul906814543165622"><li> <strong id="b407721468165622"><a name="b407721468165622"></a><a name="b407721468165622"></a>WIFEXITED(status)</strong>: If the child process ends normally, <strong id="b686149850165622"><a name="b686149850165622"></a><a name="b686149850165622"></a>true</strong> is returned. Otherwise, <strong id="b639386346165622"><a name="b639386346165622"></a><a name="b639386346165622"></a>false</strong> is returned. </li><li> <strong id="b1039223181165622"><a name="b1039223181165622"></a><a name="b1039223181165622"></a>WEXITSTATUS(status)</strong>: If <strong id="b1532854410165622"><a name="b1532854410165622"></a><a name="b1532854410165622"></a>WIFEXITED(status)</strong> is <strong id="b468614182165622"><a name="b468614182165622"></a><a name="b468614182165622"></a>true</strong>, this macro can be used to obtain the exit code that the child process passed to <a href="UTILS.md#ga55e99c539cf7723ec15e856b7e0a8cee">exit()</a>. </li><li> <strong id="b1727988722165622"><a name="b1727988722165622"></a><a name="b1727988722165622"></a>WTERMSIG(status)</strong>: After a child process ends abnormally, the parent process can obtain the child process exit code <a href="IPC.md#gabaaa61abe503c43481e35e21b0b5a031">SIGUSR2</a> through <strong id="b690559239165622"><a name="b690559239165622"></a><a name="b690559239165622"></a>WTERMSIG</strong>, indicating that the child process ends abnormally. This is the only case supported.</li></ul>
 <strong id="b1215242104165622"><a name="b1215242104165622"></a><a name="b1215242104165622"></a>WIFSIGNALED</strong>, <strong id="b1342828948165622"><a name="b1342828948165622"></a><a name="b1342828948165622"></a>WIFSTOPPED</strong>, <strong id="b1302707381165622"><a name="b1302707381165622"></a><a name="b1302707381165622"></a>WSTOPSIG</strong>, <strong id="b830160150165622"><a name="b830160150165622"></a><a name="b830160150165622"></a>WCOREDUMP</strong>, <strong id="b1414350656165622"><a name="b1414350656165622"></a><a name="b1414350656165622"></a>WIFCONTINUED</strong>, and <strong id="b1443993011165622"><a name="b1443993011165622"></a><a name="b1443993011165622"></a>WUNTRACED</strong> are not supported. </td>
</tr>
<tr id="row250542340165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">options</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Provides some options to control the behavior of this function. If you do not want to use these options, set this parameter to <strong id="b573377182165622"><a name="b573377182165622"></a><a name="b573377182165622"></a>0</strong>. <strong id="b1853341558165622"><a name="b1853341558165622"></a><a name="b1853341558165622"></a>WNOHANG</strong>: If the child process specified by <strong id="b1762940176165622"><a name="b1762940176165622"></a><a name="b1762940176165622"></a>pid</strong> is not ended, this function returns <strong id="b437178942165622"><a name="b437178942165622"></a><a name="b437178942165622"></a>0</strong> immediately instead of blocking the calling process. If the child process is ended, the process ID of the child process is returned. <strong id="b674047436165622"><a name="b674047436165622"></a><a name="b674047436165622"></a>WUNTRACED</strong>, <strong id="b144706694165622"><a name="b144706694165622"></a><a name="b144706694165622"></a>WEXITED</strong>, <strong id="b1404734422165622"><a name="b1404734422165622"></a><a name="b1404734422165622"></a>WSTOPPED</strong>, <strong id="b1873045703165622"><a name="b1873045703165622"></a><a name="b1873045703165622"></a>WCONTINUED</strong>, and <strong id="b1055347632165622"><a name="b1055347632165622"></a><a name="b1055347632165622"></a>WNOWAIT</strong> are not supported. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the child process ID if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table503345423165622"></a>
<table><thead align="left"><tr id="row1182031587165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p720084678165622"><a name="p720084678165622"></a><a name="p720084678165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p657806580165622"><a name="p657806580165622"></a><a name="p657806580165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row192614784165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p545755242165622"><a name="p545755242165622"></a><a name="p545755242165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1502094416165622"><a name="p1502094416165622"></a><a name="p1502094416165622"></a>Invalid options. </p>
</td>
</tr>
<tr id="row983508488165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p694808620165622"><a name="p694808620165622"></a><a name="p694808620165622"></a>EOPNOTSUPP </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1182475753165622"><a name="p1182475753165622"></a><a name="p1182475753165622"></a>Unsupported options. </p>
</td>
</tr>
<tr id="row1737762621165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p441937031165622"><a name="p441937031165622"></a><a name="p441937031165622"></a>ECHILD </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p834252168165622"><a name="p834252168165622"></a><a name="p834252168165622"></a>The child process does not exist, or the specified process group does not exist. </p>
</td>
</tr>
<tr id="row629467032165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1911816085165622"><a name="p1911816085165622"></a><a name="p1911816085165622"></a>ESRCH </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1727823046165622"><a name="p1727823046165622"></a><a name="p1727823046165622"></a>The child process ends abnormally. </p>
</td>
</tr>
</tbody>
</table>

## **Variable **<a name="section1588843235165622"></a>

## effective<a name="ga355bca6f4ddbe05cb7225ce1d7272ddd"></a>

```
__u32 __user_cap_data_struct::effective
```

 **Description:**

Current effective capability 

## inheritable<a name="ga22c2f1389233789296db2b270b98b79a"></a>

```
__u32 __user_cap_data_struct::inheritable
```

 **Description:**

Inheritable capability set 

## permitted<a name="ga39e42efd1f293a6c8cd0227cff1e7bb8"></a>

```
__u32 __user_cap_data_struct::permitted
```

 **Description:**

Permitted capability of the process 

## pid<a name="ga7d063c33a2986f7351ce84e033e63765"></a>

```
int __user_cap_header_struct::pid
```

 **Description:**

Process ID 

## version<a name="ga75de99b99ceca627d834db0db344b609"></a>

```
__u32 __user_cap_header_struct::version
```

 **Description:**

Version 

