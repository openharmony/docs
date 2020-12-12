# IPC<a name="EN-US_TOPIC_0000001054829479"></a>

-   [Overview](#section1091545606165622)
-   [Summary](#section1598747749165622)
-   [Files](#files)
-   [Data Structures](#nested-classes)
-   [Macros](#define-members)
-   [Typedefs](#typedef-members)
-   [Functions](#func-members)
-   [Details](#section429935514165622)
-   [Function](#section870563513165622)
-   [kill\(\)](#ga4539db972bcf3dd8c8b429af0dc3789d)
-   [mq\_close\(\)](#ga3fbd3906296be63451c64d69be2bc371)
-   [mq\_getattr\(\)](#ga8fafe8b1183830322f8ff875f4e6cb4c)
-   [mq\_open\(\)](#gaf5d8bf423701bd1783849119511381a5)
-   [mq\_receive\(\)](#gafcd715bf914289ca502136ef7022eab7)
-   [mq\_send\(\)](#ga2d07e256d809a61bdc82178cb0dd1ba1)
-   [mq\_setattr\(\)](#gaf5cc07adf7823fac8611200b55fc3a27)
-   [mq\_timedreceive\(\)](#gaa291cc1bc8bb02fd24bd0d4c563350f4)
-   [mq\_timedsend\(\)](#gae59709d01cc34d009edfeae9900568cb)
-   [mq\_unlink\(\)](#gaccd8c5ee36e60d990963e1d544ef4140)
-   [psignal\(\)](#gada1fed9730b224a68e768e5f2eac53ff)
-   [pthread\_sigmask\(\)](#ga8ca5be75c386a4aacd17be00721bf0f8)
-   [raise\(\)](#ga350675984ca13ce9b056e69098bda5c6)
-   [sem\_close\(\)](#ga4e398fea1080fd7919e5c72ee94e2fc5)
-   [sem\_destroy\(\)](#ga6bc9a7dd941a9b5e319715b767af5682)
-   [sem\_getvalue\(\)](#ga934bcc3cbc0c67a9e3a8e7a43c023460)
-   [sem\_init\(\)](#ga532509bd8a6499f8193253192fb83a3d)
-   [sem\_post\(\)](#ga015dce85cab8477c679cc47968958247)
-   [sem\_timedwait\(\)](#ga9d832817226c594e7628e2cc7ed7d723)
-   [sem\_trywait\(\)](#ga4de7a9a334b01b6373b017aaefa07cf0)
-   [sem\_unlink\(\)](#ga776256d1a473906f8b7490689bfcb75c)
-   [sem\_wait\(\)](#gaad70020dca2241a2b78e272ca033271b)
-   [sigaction\(\)](#ga5263ce0feb3eb0934bc56ab81cae8ddb)
-   [sigaddset\(\)](#gae412e6a5436a6c28424b0173251d349c)
-   [sigandset\(\)](#ga2a0910ff9d18931a05b995143dc4576e)
-   [sigdelset\(\)](#gab0025e4f32ce2737c40cc0074cc6d7d2)
-   [sigemptyset\(\)](#ga5925352f90eb589393274fa0376d7def)
-   [sigfillset\(\)](#ga88d7bbc77ea1569ee21c90db549ea023)
-   [sighold\(\)](#ga4378a40ea3370c436d4e46c7a2a58172)
-   [sigisemptyset\(\)](#gac41035aa05cb4523ae93e8a6d55f9453)
-   [sigismember\(\)](#ga63693cc65f43d772729b588b453fe1ef)
-   [signal\(\)](#gaf0f8ed40d30773bdb68e858ef0139b58)
-   [sigorset\(\)](#ga1a0d037b7fd84fb392a4c2ffc6c3525c)
-   [sigpause\(\)](#ga95a78da8c44db11c7031b678504d0b34)
-   [sigpending\(\)](#ga7b91eecad5998acd6162fde3ab530d7a)
-   [sigprocmask\(\)](#gae11d1cbeb529d0050ab5600fe4b5fef9)
-   [sigrelse\(\)](#ga96c4aed60b8b727709887e1fae0f5bea)
-   [sigsuspend\(\)](#gae5f92586ad50092a7813465eeef792c0)
-   [sigtimedwait\(\)](#ga155a526c3da5ffd1a79ba2925bdd278a)
-   [sigwait\(\)](#ga900d91a9635b965dbbae6b3cee2d2a2b)
-   [sigwaitinfo\(\)](#ga786f18a8e5b7eceed0ddcdc722f3340b)

## **Overview**<a name="section1091545606165622"></a>

**Description:**

Provides functions and structures related to inter-process communication \(IPC\), including signals, semaphores, and message queues. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1598747749165622"></a>

## Files<a name="files"></a>

<a name="table1239209994165622"></a>
<table><thead align="left"><tr id="row1042864822165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1269057250165622"><a name="p1269057250165622"></a><a name="p1269057250165622"></a>File Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1179337790165622"><a name="p1179337790165622"></a><a name="p1179337790165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2063769523165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1143777381165622"><a name="p1143777381165622"></a><a name="p1143777381165622"></a><a href="ipcstat-h.md">ipcstat.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p230925612165622"><a name="p230925612165622"></a><a name="p230925612165622"></a>Defines the macros related to the IPC functions. </p>
</td>
</tr>
<tr id="row1702389804165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p867416020165622"><a name="p867416020165622"></a><a name="p867416020165622"></a><a href="mqueue-h.md">mqueue.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1310620856165622"><a name="p1310620856165622"></a><a name="p1310620856165622"></a>Provides message queue operation functions and related structures. </p>
</td>
</tr>
<tr id="row301905075165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p668829357165622"><a name="p668829357165622"></a><a name="p668829357165622"></a><a href="semaphore-h.md">semaphore.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p435854630165622"><a name="p435854630165622"></a><a name="p435854630165622"></a>Provides functions and structures related to semaphore operations. </p>
</td>
</tr>
<tr id="row110413300165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1426348409165622"><a name="p1426348409165622"></a><a name="p1426348409165622"></a><a href="signal-h.md">signal.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1299218038165622"><a name="p1299218038165622"></a><a name="p1299218038165622"></a>Provides signal operation functions and structures, including changing the signal processing mode and the process signal mask set. </p>
</td>
</tr>
<tr id="row859108220165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p116676717165622"><a name="p116676717165622"></a><a name="p116676717165622"></a><a href="ipc-h.md">ipc.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1225146340165622"><a name="p1225146340165622"></a><a name="p1225146340165622"></a>Defines IPC-related macros. </p>
</td>
</tr>
</tbody>
</table>

## Data Structures<a name="nested-classes"></a>

<a name="table19063706165622"></a>
<table><thead align="left"><tr id="row1563244441165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1808812174165622"><a name="p1808812174165622"></a><a name="p1808812174165622"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1741385591165622"><a name="p1741385591165622"></a><a name="p1741385591165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row297902065165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p364560375165622"><a name="p364560375165622"></a><a name="p364560375165622"></a><a href="mq_attr.md">mq_attr</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p705778833165622"><a name="p705778833165622"></a><a name="p705778833165622"></a>Describes message queue attributes. </p>
</td>
</tr>
<tr id="row776763152165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1147062717165622"><a name="p1147062717165622"></a><a name="p1147062717165622"></a><a href="sem_t.md">sem_t</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p894120980165622"><a name="p894120980165622"></a><a name="p894120980165622"></a>Defines semaphores. </p>
</td>
</tr>
<tr id="row815470682165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p185735792165622"><a name="p185735792165622"></a><a name="p185735792165622"></a><a href="sigaltstack.md">sigaltstack</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p792131154165622"><a name="p792131154165622"></a><a name="p792131154165622"></a>Describes a signal stack. </p>
</td>
</tr>
<tr id="row1266654726165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p42418344165622"><a name="p42418344165622"></a><a name="p42418344165622"></a><a href="__ucontext.md">__ucontext</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p841888764165622"><a name="p841888764165622"></a><a name="p841888764165622"></a>Describes the user execution context. </p>
</td>
</tr>
<tr id="row1150778120165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p677255238165622"><a name="p677255238165622"></a><a name="p677255238165622"></a><a href="__sigset_t.md">__sigset_t</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p747492667165622"><a name="p747492667165622"></a><a name="p747492667165622"></a>Defines the data type of a signal set. </p>
</td>
</tr>
<tr id="row1357073942165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p755849346165622"><a name="p755849346165622"></a><a name="p755849346165622"></a><a href="sigval.md">sigval</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1807141997165622"><a name="p1807141997165622"></a><a name="p1807141997165622"></a>Describes signal values in different cases. </p>
</td>
</tr>
<tr id="row1783873901165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1506581662165622"><a name="p1506581662165622"></a><a name="p1506581662165622"></a><a href="__si_fields.md">__si_fields</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1364559489165622"><a name="p1364559489165622"></a><a name="p1364559489165622"></a>Describes signal information. </p>
</td>
</tr>
<tr id="row1121954814165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1427530071165622"><a name="p1427530071165622"></a><a name="p1427530071165622"></a><a href="sigaction.md">sigaction</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1926200524165622"><a name="p1926200524165622"></a><a name="p1926200524165622"></a>Describes the signal processing actions and related attributes. </p>
</td>
</tr>
<tr id="row859512008165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p55168765165622"><a name="p55168765165622"></a><a name="p55168765165622"></a><a href="sigevent.md">sigevent</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p497268008165622"><a name="p497268008165622"></a><a name="p497268008165622"></a>Describes asynchronous notifications. </p>
</td>
</tr>
</tbody>
</table>

## Macros<a name="define-members"></a>

<a name="table641031735165622"></a>
<table><thead align="left"><tr id="row1785627300165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p151160895165622"><a name="p151160895165622"></a><a name="p151160895165622"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1735900858165622"><a name="p1735900858165622"></a><a name="p1735900858165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1243071834165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p643353223165622"><a name="p643353223165622"></a><a name="p643353223165622"></a><em id="ga16a91ee69c3cb6bfec425e1bfd5edd18"><a name="ga16a91ee69c3cb6bfec425e1bfd5edd18"></a><a name="ga16a91ee69c3cb6bfec425e1bfd5edd18"></a></em>IPC_STAT    2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1183171812165622"><a name="p1183171812165622"></a><a name="p1183171812165622"></a>Defines the input parameter used to obtain information from the kernel. </p>
</td>
</tr>
<tr id="row2072519930165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2083924614165622"><a name="p2083924614165622"></a><a name="p2083924614165622"></a><em id="ga2ef55dcb46a51cb0f879f4c1724bdded"><a name="ga2ef55dcb46a51cb0f879f4c1724bdded"></a><a name="ga2ef55dcb46a51cb0f879f4c1724bdded"></a></em>SEM_FAILED    ((<a href="sem_t.md">sem_t</a> *)0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1012576749165622"><a name="p1012576749165622"></a><a name="p1012576749165622"></a>Defines the semaphore failure flag. </p>
</td>
</tr>
<tr id="row388791410165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p462579450165622"><a name="p462579450165622"></a><a name="p462579450165622"></a><em id="gaf6a71c97263725437f59ceb16241fd32"><a name="gaf6a71c97263725437f59ceb16241fd32"></a><a name="gaf6a71c97263725437f59ceb16241fd32"></a></em>SA_NOCLDSTOP    1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p21772662165622"><a name="p21772662165622"></a><a name="p21772662165622"></a>Stops a child process without sending the <a href="ipc.md#ga0e63521a64cc8bc2b91d36a87d32c9f8">SIGCHLD</a> signal. </p>
</td>
</tr>
<tr id="row1425667345165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p431299716165622"><a name="p431299716165622"></a><a name="p431299716165622"></a><em id="gae4c1aad864ef72e4a2cce74b1b8a5a0b"><a name="gae4c1aad864ef72e4a2cce74b1b8a5a0b"></a><a name="gae4c1aad864ef72e4a2cce74b1b8a5a0b"></a></em>SA_NOCLDWAIT    2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p19736638165622"><a name="p19736638165622"></a><a name="p19736638165622"></a>Sets the <a href="ipc.md#ga0e63521a64cc8bc2b91d36a87d32c9f8">SIGCHLD</a> flag to prevent zombie processes. </p>
</td>
</tr>
<tr id="row1570531654165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1552685041165622"><a name="p1552685041165622"></a><a name="p1552685041165622"></a><em id="ga59b4c0774aace526b10b6d737075a790"><a name="ga59b4c0774aace526b10b6d737075a790"></a><a name="ga59b4c0774aace526b10b6d737075a790"></a></em>SA_SIGINFO    4</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2110820676165622"><a name="p2110820676165622"></a><a name="p2110820676165622"></a>Transfers the <strong id="b126764013165622"><a name="b126764013165622"></a><a name="b126764013165622"></a>siginfo_t</strong> structure with the signal. </p>
</td>
</tr>
<tr id="row1475697993165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p288255114165622"><a name="p288255114165622"></a><a name="p288255114165622"></a><em id="ga322c220e296393958ab4238145a0d273"><a name="ga322c220e296393958ab4238145a0d273"></a><a name="ga322c220e296393958ab4238145a0d273"></a></em>SA_ONSTACK    0x08000000</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1982448333165622"><a name="p1982448333165622"></a><a name="p1982448333165622"></a>Uses the signal stack specified by <a href="sigaltstack.md">sigaltstack</a> for signal processing. </p>
</td>
</tr>
<tr id="row1865620464165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p203698013165622"><a name="p203698013165622"></a><a name="p203698013165622"></a><em id="ga74ef0a27afcf55b6cd6d35cf0fa5d427"><a name="ga74ef0a27afcf55b6cd6d35cf0fa5d427"></a><a name="ga74ef0a27afcf55b6cd6d35cf0fa5d427"></a></em>SA_RESTART    0x10000000</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1054673584165622"><a name="p1054673584165622"></a><a name="p1054673584165622"></a>Obtains the restart signal. </p>
</td>
</tr>
<tr id="row304255127165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p591385587165622"><a name="p591385587165622"></a><a name="p591385587165622"></a><em id="gabec4abd80d73397fc2f78f57f178565f"><a name="gabec4abd80d73397fc2f78f57f178565f"></a><a name="gabec4abd80d73397fc2f78f57f178565f"></a></em>SA_NODEFER    0x40000000</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1179591711165622"><a name="p1179591711165622"></a><a name="p1179591711165622"></a>The signals being processed are not masked during signal processing. </p>
</td>
</tr>
<tr id="row1149108874165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1995944039165622"><a name="p1995944039165622"></a><a name="p1995944039165622"></a><em id="ga8d5fb4f35858d31035e7354c1d4048ea"><a name="ga8d5fb4f35858d31035e7354c1d4048ea"></a><a name="ga8d5fb4f35858d31035e7354c1d4048ea"></a></em>SA_RESETHAND    0x80000000</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p388602313165622"><a name="p388602313165622"></a><a name="p388602313165622"></a>The default processing mode is restored after the signal processing is complete. </p>
</td>
</tr>
<tr id="row1391272466165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1725768721165622"><a name="p1725768721165622"></a><a name="p1725768721165622"></a><em id="gaae6a742a8c5acf12caba1d148dd03f10"><a name="gaae6a742a8c5acf12caba1d148dd03f10"></a><a name="gaae6a742a8c5acf12caba1d148dd03f10"></a></em>MINSIGSTKSZ    2048</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1047635276165622"><a name="p1047635276165622"></a><a name="p1047635276165622"></a>Defines the minimum size of the replaceable signal stack. </p>
</td>
</tr>
<tr id="row939313868165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p716127913165622"><a name="p716127913165622"></a><a name="p716127913165622"></a><em id="ga8a433a10420a0c51355da26cfcab2131"><a name="ga8a433a10420a0c51355da26cfcab2131"></a><a name="ga8a433a10420a0c51355da26cfcab2131"></a></em>SIGSTKSZ    8192</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p725876169165622"><a name="p725876169165622"></a><a name="p725876169165622"></a>Defines the size of a signal stack. </p>
</td>
</tr>
<tr id="row574585525165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p942865186165622"><a name="p942865186165622"></a><a name="p942865186165622"></a><em id="ga275020780cb70a8b0cba8db5accc5d19"><a name="ga275020780cb70a8b0cba8db5accc5d19"></a><a name="ga275020780cb70a8b0cba8db5accc5d19"></a></em>_NSIG    65</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1541622742165622"><a name="p1541622742165622"></a><a name="p1541622742165622"></a>Number of supported signals. </p>
</td>
</tr>
<tr id="row455943970165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p336887505165622"><a name="p336887505165622"></a><a name="p336887505165622"></a><em id="ga15d5d2dce732343eece4e11ac487e003"><a name="ga15d5d2dce732343eece4e11ac487e003"></a><a name="ga15d5d2dce732343eece4e11ac487e003"></a></em>_NSIG_BPW    <a href="utils.md#ga0bf2a26a1f15f79f80319edbaa5cc9a5">__BITS_PER_LONG</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p472392459165622"><a name="p472392459165622"></a><a name="p472392459165622"></a>Number of bits occupied by a word. </p>
</td>
</tr>
<tr id="row61560257165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p910081967165622"><a name="p910081967165622"></a><a name="p910081967165622"></a><em id="gacd9297a3ab78048b3f46055fc7739c17"><a name="gacd9297a3ab78048b3f46055fc7739c17"></a><a name="gacd9297a3ab78048b3f46055fc7739c17"></a></em>_NSIG_WORDS    (<a href="ipc.md#ga275020780cb70a8b0cba8db5accc5d19">_NSIG</a> / <a href="ipc.md#ga15d5d2dce732343eece4e11ac487e003">_NSIG_BPW</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1248991042165622"><a name="p1248991042165622"></a><a name="p1248991042165622"></a>Number of words required by all signals. </p>
</td>
</tr>
<tr id="row1314417064165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1916218337165622"><a name="p1916218337165622"></a><a name="p1916218337165622"></a><em id="ga136c64ec2d1306de745e39d6aee362ca"><a name="ga136c64ec2d1306de745e39d6aee362ca"></a><a name="ga136c64ec2d1306de745e39d6aee362ca"></a></em>SIGHUP    1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1056447033165622"><a name="p1056447033165622"></a><a name="p1056447033165622"></a>Hangs up a process. </p>
</td>
</tr>
<tr id="row1924614595165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p602855878165622"><a name="p602855878165622"></a><a name="p602855878165622"></a><em id="ga487309e3e9e0527535644115204a639a"><a name="ga487309e3e9e0527535644115204a639a"></a><a name="ga487309e3e9e0527535644115204a639a"></a></em>SIGINT    2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p911970891165622"><a name="p911970891165622"></a><a name="p911970891165622"></a>Interrupts a process from keyboard. </p>
</td>
</tr>
<tr id="row1934919405165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p141610642165622"><a name="p141610642165622"></a><a name="p141610642165622"></a><em id="ga62045b465be11891160d53c10861b16c"><a name="ga62045b465be11891160d53c10861b16c"></a><a name="ga62045b465be11891160d53c10861b16c"></a></em>SIGQUIT    3</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p616919939165622"><a name="p616919939165622"></a><a name="p616919939165622"></a>Exits a process from keyboard. A core file is generated. </p>
</td>
</tr>
<tr id="row1475050920165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p188839605165622"><a name="p188839605165622"></a><a name="p188839605165622"></a><em id="ga4c9c5284f8c8d146bd7a93d25017fc62"><a name="ga4c9c5284f8c8d146bd7a93d25017fc62"></a><a name="ga4c9c5284f8c8d146bd7a93d25017fc62"></a></em>SIGILL    4</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1801986614165622"><a name="p1801986614165622"></a><a name="p1801986614165622"></a>Illegal instruction. </p>
</td>
</tr>
<tr id="row918208275165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p391578907165622"><a name="p391578907165622"></a><a name="p391578907165622"></a><em id="gaa2beb906ab1b46676e63823f4e773c38"><a name="gaa2beb906ab1b46676e63823f4e773c38"></a><a name="gaa2beb906ab1b46676e63823f4e773c38"></a></em>SIGTRAP    5</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p546381431165622"><a name="p546381431165622"></a><a name="p546381431165622"></a>Breakpoint, used for debugging. </p>
</td>
</tr>
<tr id="row1208451897165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1659148561165622"><a name="p1659148561165622"></a><a name="p1659148561165622"></a><em id="gaa86c630133e5b5174ac970227b273446"><a name="gaa86c630133e5b5174ac970227b273446"></a><a name="gaa86c630133e5b5174ac970227b273446"></a></em>SIGABRT    6</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1148836615165622"><a name="p1148836615165622"></a><a name="p1148836615165622"></a>Abnormal termination. </p>
</td>
</tr>
<tr id="row1649431208165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1967615200165622"><a name="p1967615200165622"></a><a name="p1967615200165622"></a><em id="gab12271d5e5911f8a85dc7c3f0e2364c7"><a name="gab12271d5e5911f8a85dc7c3f0e2364c7"></a><a name="gab12271d5e5911f8a85dc7c3f0e2364c7"></a></em>SIGIOT    6</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1907477832165622"><a name="p1907477832165622"></a><a name="p1907477832165622"></a>Equivalent to <a href="ipc.md#gaa86c630133e5b5174ac970227b273446">SIGABRT</a>. </p>
</td>
</tr>
<tr id="row551817522165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p257899337165622"><a name="p257899337165622"></a><a name="p257899337165622"></a><em id="gaead3d488474201acf18c4b63d91edc3c"><a name="gaead3d488474201acf18c4b63d91edc3c"></a><a name="gaead3d488474201acf18c4b63d91edc3c"></a></em>SIGBUS    7</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1312165685165622"><a name="p1312165685165622"></a><a name="p1312165685165622"></a>Invalid address access. </p>
</td>
</tr>
<tr id="row556253836165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1219779499165622"><a name="p1219779499165622"></a><a name="p1219779499165622"></a><em id="ga7fbba29aec3e4a8daae12935299df92d"><a name="ga7fbba29aec3e4a8daae12935299df92d"></a><a name="ga7fbba29aec3e4a8daae12935299df92d"></a></em>SIGFPE    8</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p290607610165622"><a name="p290607610165622"></a><a name="p290607610165622"></a>Floating-point exceptions. </p>
</td>
</tr>
<tr id="row1794354816165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p464513143165622"><a name="p464513143165622"></a><a name="p464513143165622"></a><em id="gaddd8dcd406ce514ab3b4f576a5343d42"><a name="gaddd8dcd406ce514ab3b4f576a5343d42"></a><a name="gaddd8dcd406ce514ab3b4f576a5343d42"></a></em>SIGKILL    9</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1579861591165622"><a name="p1579861591165622"></a><a name="p1579861591165622"></a>Forcibly stops a process. </p>
</td>
</tr>
<tr id="row675149954165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p164564462165622"><a name="p164564462165622"></a><a name="p164564462165622"></a><em id="ga944a8250e34bfd7991123abd3436d8c0"><a name="ga944a8250e34bfd7991123abd3436d8c0"></a><a name="ga944a8250e34bfd7991123abd3436d8c0"></a></em>SIGUSR1    10</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1286833628165622"><a name="p1286833628165622"></a><a name="p1286833628165622"></a>User-defined signal 1. </p>
</td>
</tr>
<tr id="row2066831116165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p72282231165622"><a name="p72282231165622"></a><a name="p72282231165622"></a><em id="gae20b4f7171a09516ea73c9d2745bd596"><a name="gae20b4f7171a09516ea73c9d2745bd596"></a><a name="gae20b4f7171a09516ea73c9d2745bd596"></a></em>SIGSEGV    11</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1788908415165622"><a name="p1788908415165622"></a><a name="p1788908415165622"></a>Illegal memory access. </p>
</td>
</tr>
<tr id="row1589214167165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1496321558165622"><a name="p1496321558165622"></a><a name="p1496321558165622"></a><em id="gabaaa61abe503c43481e35e21b0b5a031"><a name="gabaaa61abe503c43481e35e21b0b5a031"></a><a name="gabaaa61abe503c43481e35e21b0b5a031"></a></em>SIGUSR2    12</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p83114318165622"><a name="p83114318165622"></a><a name="p83114318165622"></a>User-defined signal 2. </p>
</td>
</tr>
<tr id="row74652190165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p315912241165622"><a name="p315912241165622"></a><a name="p315912241165622"></a><em id="ga57e9c8c5fa13bf86bc779a9f6f408b7c"><a name="ga57e9c8c5fa13bf86bc779a9f6f408b7c"></a><a name="ga57e9c8c5fa13bf86bc779a9f6f408b7c"></a></em>SIGPIPE    13</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1020237525165622"><a name="p1020237525165622"></a><a name="p1020237525165622"></a>The pipe is broken. </p>
</td>
</tr>
<tr id="row1518818178165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1318326839165622"><a name="p1318326839165622"></a><a name="p1318326839165622"></a><em id="gaa6946723c6b7a86ec3c33caaf832840b"><a name="gaa6946723c6b7a86ec3c33caaf832840b"></a><a name="gaa6946723c6b7a86ec3c33caaf832840b"></a></em>SIGALRM    14</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1192250020165622"><a name="p1192250020165622"></a><a name="p1192250020165622"></a>Timer signal. </p>
</td>
</tr>
<tr id="row2100980593165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1312256424165622"><a name="p1312256424165622"></a><a name="p1312256424165622"></a><em id="ga682182a5e5f38fd61f4311501e9dac5d"><a name="ga682182a5e5f38fd61f4311501e9dac5d"></a><a name="ga682182a5e5f38fd61f4311501e9dac5d"></a></em>SIGTERM    15</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1025598544165622"><a name="p1025598544165622"></a><a name="p1025598544165622"></a>Termination signal. </p>
</td>
</tr>
<tr id="row1878998502165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1714242364165622"><a name="p1714242364165622"></a><a name="p1714242364165622"></a><em id="ga03612fcda4ab9671dfa7051e7b666fb6"><a name="ga03612fcda4ab9671dfa7051e7b666fb6"></a><a name="ga03612fcda4ab9671dfa7051e7b666fb6"></a></em>SIGSTKFLT    16</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p442234562165622"><a name="p442234562165622"></a><a name="p442234562165622"></a>Coprocessor stack error. </p>
</td>
</tr>
<tr id="row1015106334165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1960564078165622"><a name="p1960564078165622"></a><a name="p1960564078165622"></a><em id="ga0e63521a64cc8bc2b91d36a87d32c9f8"><a name="ga0e63521a64cc8bc2b91d36a87d32c9f8"></a><a name="ga0e63521a64cc8bc2b91d36a87d32c9f8"></a></em>SIGCHLD    17</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p329956325165622"><a name="p329956325165622"></a><a name="p329956325165622"></a>Child process terminated or stopped. </p>
</td>
</tr>
<tr id="row1589488463165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p579603328165622"><a name="p579603328165622"></a><a name="p579603328165622"></a><em id="ga024f43063003e753afc6cca1acd6e104"><a name="ga024f43063003e753afc6cca1acd6e104"></a><a name="ga024f43063003e753afc6cca1acd6e104"></a></em>SIGCONT    18</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1718681554165622"><a name="p1718681554165622"></a><a name="p1718681554165622"></a>Resumes a suspended process. </p>
</td>
</tr>
<tr id="row1948178132165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p547413278165622"><a name="p547413278165622"></a><a name="p547413278165622"></a><em id="ga069e358bc9a864b7dc4fed2440eda14c"><a name="ga069e358bc9a864b7dc4fed2440eda14c"></a><a name="ga069e358bc9a864b7dc4fed2440eda14c"></a></em>SIGSTOP    19</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p148156247165622"><a name="p148156247165622"></a><a name="p148156247165622"></a>Suspends a process. </p>
</td>
</tr>
<tr id="row1548478838165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p158851029165622"><a name="p158851029165622"></a><a name="p158851029165622"></a><em id="gabe65c086e01f0d286b7a785a7e3cdd1a"><a name="gabe65c086e01f0d286b7a785a7e3cdd1a"></a><a name="gabe65c086e01f0d286b7a785a7e3cdd1a"></a></em>SIGTSTP    20</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1744854387165622"><a name="p1744854387165622"></a><a name="p1744854387165622"></a>Stops a process by entering the command on the terminal. </p>
</td>
</tr>
<tr id="row1896393492165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p828143558165622"><a name="p828143558165622"></a><a name="p828143558165622"></a><em id="ga2c146e34a6b5a78dfba41cded3331181"><a name="ga2c146e34a6b5a78dfba41cded3331181"></a><a name="ga2c146e34a6b5a78dfba41cded3331181"></a></em>SIGTTIN    21</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1354110277165622"><a name="p1354110277165622"></a><a name="p1354110277165622"></a>Input required by the background process. </p>
</td>
</tr>
<tr id="row1176177477165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p299023951165622"><a name="p299023951165622"></a><a name="p299023951165622"></a><em id="ga782864287613e2c5c030411fa9c5e9b1"><a name="ga782864287613e2c5c030411fa9c5e9b1"></a><a name="ga782864287613e2c5c030411fa9c5e9b1"></a></em>SIGTTOU    22</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2125395071165622"><a name="p2125395071165622"></a><a name="p2125395071165622"></a>Output required by the background process. </p>
</td>
</tr>
<tr id="row468118886165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p942615374165622"><a name="p942615374165622"></a><a name="p942615374165622"></a><em id="gad9ff13149e36144a4ea28788948c34dd"><a name="gad9ff13149e36144a4ea28788948c34dd"></a><a name="gad9ff13149e36144a4ea28788948c34dd"></a></em>SIGURG    23</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p248305932165622"><a name="p248305932165622"></a><a name="p248305932165622"></a>Urgent socket condition. </p>
</td>
</tr>
<tr id="row684039249165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1219391820165622"><a name="p1219391820165622"></a><a name="p1219391820165622"></a><em id="ga7265cbba4972503c1c30a2e52a929874"><a name="ga7265cbba4972503c1c30a2e52a929874"></a><a name="ga7265cbba4972503c1c30a2e52a929874"></a></em>SIGXCPU    24</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1359336812165622"><a name="p1359336812165622"></a><a name="p1359336812165622"></a>CPU time limit exceeded. </p>
</td>
</tr>
<tr id="row1283009851165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p249867588165622"><a name="p249867588165622"></a><a name="p249867588165622"></a><em id="ga75440a7aa885a1052dfd3b4393fd9baa"><a name="ga75440a7aa885a1052dfd3b4393fd9baa"></a><a name="ga75440a7aa885a1052dfd3b4393fd9baa"></a></em>SIGXFSZ    25</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1494497247165622"><a name="p1494497247165622"></a><a name="p1494497247165622"></a>File size limit exceeded. </p>
</td>
</tr>
<tr id="row1932407371165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1885638978165622"><a name="p1885638978165622"></a><a name="p1885638978165622"></a><em id="ga71403d2f5240e409e213060ea3301851"><a name="ga71403d2f5240e409e213060ea3301851"></a><a name="ga71403d2f5240e409e213060ea3301851"></a></em>SIGVTALRM    26</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2087450445165622"><a name="p2087450445165622"></a><a name="p2087450445165622"></a>Virtual timer, used to calculate the CPU occupation time of a process. </p>
</td>
</tr>
<tr id="row142997476165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p258878748165622"><a name="p258878748165622"></a><a name="p258878748165622"></a><em id="gab6bd2a2ff7e58d45965ef257f96dfe65"><a name="gab6bd2a2ff7e58d45965ef257f96dfe65"></a><a name="gab6bd2a2ff7e58d45965ef257f96dfe65"></a></em>SIGPROF    27</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p962788236165622"><a name="p962788236165622"></a><a name="p962788236165622"></a>Calculates the CPU time occupied by a process and the system calling time. </p>
</td>
</tr>
<tr id="row1911665485165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1235751797165622"><a name="p1235751797165622"></a><a name="p1235751797165622"></a><em id="ga13ba0e7c4365813312eb4566907bce4f"><a name="ga13ba0e7c4365813312eb4566907bce4f"></a><a name="ga13ba0e7c4365813312eb4566907bce4f"></a></em>SIGWINCH    28</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p386116452165622"><a name="p386116452165622"></a><a name="p386116452165622"></a>Window size change. </p>
</td>
</tr>
<tr id="row1444255975165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p195699536165622"><a name="p195699536165622"></a><a name="p195699536165622"></a><em id="ga929c5eace94ce2e099c6fa732450ce86"><a name="ga929c5eace94ce2e099c6fa732450ce86"></a><a name="ga929c5eace94ce2e099c6fa732450ce86"></a></em>SIGIO    29</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1130945780165622"><a name="p1130945780165622"></a><a name="p1130945780165622"></a>Input/Output. </p>
</td>
</tr>
<tr id="row2060323268165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1890086130165622"><a name="p1890086130165622"></a><a name="p1890086130165622"></a><em id="ga1614264a836d6a5642554775ef0134d0"><a name="ga1614264a836d6a5642554775ef0134d0"></a><a name="ga1614264a836d6a5642554775ef0134d0"></a></em>SIGPOLL    <a href="ipc.md#ga929c5eace94ce2e099c6fa732450ce86">SIGIO</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p632362553165622"><a name="p632362553165622"></a><a name="p632362553165622"></a>Equivalent to <a href="ipc.md#ga929c5eace94ce2e099c6fa732450ce86">SIGIO</a>. </p>
</td>
</tr>
<tr id="row1226402965165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p432855479165622"><a name="p432855479165622"></a><a name="p432855479165622"></a><em id="ga633dbd7dca7d839e6af0299bd4713f0a"><a name="ga633dbd7dca7d839e6af0299bd4713f0a"></a><a name="ga633dbd7dca7d839e6af0299bd4713f0a"></a></em>SIGPWR    30</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1377264750165622"><a name="p1377264750165622"></a><a name="p1377264750165622"></a>Power failure. </p>
</td>
</tr>
<tr id="row768920273165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p562933415165622"><a name="p562933415165622"></a><a name="p562933415165622"></a><em id="ga8bacf9eb18fd539099c1bb4666c45d60"><a name="ga8bacf9eb18fd539099c1bb4666c45d60"></a><a name="ga8bacf9eb18fd539099c1bb4666c45d60"></a></em>SIGSYS    31</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1561914939165622"><a name="p1561914939165622"></a><a name="p1561914939165622"></a>Non-existent system call. </p>
</td>
</tr>
<tr id="row411462389165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2000518164165622"><a name="p2000518164165622"></a><a name="p2000518164165622"></a><em id="ga11e925ada5a97c7bbb6b88de8ed543b4"><a name="ga11e925ada5a97c7bbb6b88de8ed543b4"></a><a name="ga11e925ada5a97c7bbb6b88de8ed543b4"></a></em>SIGUNUSED    31</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1236833184165622"><a name="p1236833184165622"></a><a name="p1236833184165622"></a>Equivalent to <a href="ipc.md#ga8bacf9eb18fd539099c1bb4666c45d60">SIGSYS</a>. </p>
</td>
</tr>
<tr id="row979301622165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p320633593165622"><a name="p320633593165622"></a><a name="p320633593165622"></a><em id="gae89f9a1282bd2d1b2a2b310c12ea16a5"><a name="gae89f9a1282bd2d1b2a2b310c12ea16a5"></a><a name="gae89f9a1282bd2d1b2a2b310c12ea16a5"></a></em>SIGRTMIN    32</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1134455894165622"><a name="p1134455894165622"></a><a name="p1134455894165622"></a>Start of a reliable signal. </p>
</td>
</tr>
<tr id="row737896653165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1191569165622"><a name="p1191569165622"></a><a name="p1191569165622"></a><em id="ga5336d2c76af22b10373e3dd28fb3b0f0"><a name="ga5336d2c76af22b10373e3dd28fb3b0f0"></a><a name="ga5336d2c76af22b10373e3dd28fb3b0f0"></a></em>SIGRTMAX    <a href="ipc.md#ga275020780cb70a8b0cba8db5accc5d19">_NSIG</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1086257226165622"><a name="p1086257226165622"></a><a name="p1086257226165622"></a>End of a reliable signal. </p>
</td>
</tr>
<tr id="row1865103805165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1418916040165622"><a name="p1418916040165622"></a><a name="p1418916040165622"></a><em id="ga93598c2382d6b05a1ff33edd21a1dcd0"><a name="ga93598c2382d6b05a1ff33edd21a1dcd0"></a><a name="ga93598c2382d6b05a1ff33edd21a1dcd0"></a></em>SA_THIRTYTWO    0x02000000</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p604959469165622"><a name="p604959469165622"></a><a name="p604959469165622"></a>Transfers signals in a 32-bit mode even if the task runs in a 26-bit mode. </p>
</td>
</tr>
<tr id="row321492390165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1833182129165622"><a name="p1833182129165622"></a><a name="p1833182129165622"></a><em id="ga43c1d5510c7bedd95c0e4deac99e1729"><a name="ga43c1d5510c7bedd95c0e4deac99e1729"></a><a name="ga43c1d5510c7bedd95c0e4deac99e1729"></a></em>SA_NOMASK    <a href="ipc.md#gabec4abd80d73397fc2f78f57f178565f">SA_NODEFER</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2097102190165622"><a name="p2097102190165622"></a><a name="p2097102190165622"></a>Signals being processed are not masked during signal processing. </p>
</td>
</tr>
<tr id="row531574257165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p585439444165622"><a name="p585439444165622"></a><a name="p585439444165622"></a><em id="ga40c57ae45831edc27ae9ff933b11aa50"><a name="ga40c57ae45831edc27ae9ff933b11aa50"></a><a name="ga40c57ae45831edc27ae9ff933b11aa50"></a></em>SA_ONESHOT    <a href="ipc.md#ga8d5fb4f35858d31035e7354c1d4048ea">SA_RESETHAND</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1450047970165622"><a name="p1450047970165622"></a><a name="p1450047970165622"></a>The default processing mode is restored after the signal processing is complete. </p>
</td>
</tr>
<tr id="row273718850165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1863690563165622"><a name="p1863690563165622"></a><a name="p1863690563165622"></a><em id="ga927f6ae16379576d638006c7498ac5d7"><a name="ga927f6ae16379576d638006c7498ac5d7"></a><a name="ga927f6ae16379576d638006c7498ac5d7"></a></em>SIG_BLOCK    0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p28315729165622"><a name="p28315729165622"></a><a name="p28315729165622"></a>Defines the function behaviors such as <a href="ipc.md#gae11d1cbeb529d0050ab5600fe4b5fef9">sigprocmask()</a> and <a href="ipc.md#ga8ca5be75c386a4aacd17be00721bf0f8">pthread_sigmask()</a>, which are used to add signals to the mask set. </p>
</td>
</tr>
<tr id="row1814317429165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p735844789165622"><a name="p735844789165622"></a><a name="p735844789165622"></a><em id="ga5fcd73313a63dac2cc7eb3b654215250"><a name="ga5fcd73313a63dac2cc7eb3b654215250"></a><a name="ga5fcd73313a63dac2cc7eb3b654215250"></a></em>SIG_UNBLOCK    1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p649123499165622"><a name="p649123499165622"></a><a name="p649123499165622"></a>Defines the function behaviors such as <a href="ipc.md#gae11d1cbeb529d0050ab5600fe4b5fef9">sigprocmask()</a> and <a href="ipc.md#ga8ca5be75c386a4aacd17be00721bf0f8">pthread_sigmask()</a>, which are used to remove signals from the mask set. </p>
</td>
</tr>
<tr id="row1681043233165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1203053250165622"><a name="p1203053250165622"></a><a name="p1203053250165622"></a><em id="ga37750b78b7ae75fe02ad26e70f6cc845"><a name="ga37750b78b7ae75fe02ad26e70f6cc845"></a><a name="ga37750b78b7ae75fe02ad26e70f6cc845"></a></em>SIG_SETMASK    2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2068106178165622"><a name="p2068106178165622"></a><a name="p2068106178165622"></a>Defines the function behaviors such as <a href="ipc.md#gae11d1cbeb529d0050ab5600fe4b5fef9">sigprocmask()</a> and <a href="ipc.md#ga8ca5be75c386a4aacd17be00721bf0f8">pthread_sigmask()</a>, which are used to set the mask set. </p>
</td>
</tr>
<tr id="row87268403165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p263710301165622"><a name="p263710301165622"></a><a name="p263710301165622"></a><em id="ga0fa971487344a463a7f0545c9c9ef2bf"><a name="ga0fa971487344a463a7f0545c9c9ef2bf"></a><a name="ga0fa971487344a463a7f0545c9c9ef2bf"></a></em>SIG_HOLD    ((void (*)(int)) 2)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p574659301165622"><a name="p574659301165622"></a><a name="p574659301165622"></a>Defines the function behaviors such as <strong id="b1699658834165622"><a name="b1699658834165622"></a><a name="b1699658834165622"></a>sigset()</strong> and adds a specified signal to the process signal mask without changing the current processing mode of the signal. </p>
</td>
</tr>
<tr id="row2044643095165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1117591735165622"><a name="p1117591735165622"></a><a name="p1117591735165622"></a><em id="ga51d2f3aecb6f42d152e5f319e6b178b9"><a name="ga51d2f3aecb6f42d152e5f319e6b178b9"></a><a name="ga51d2f3aecb6f42d152e5f319e6b178b9"></a></em>sa_handler    __sa_handler.sa_handler</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p407443912165622"><a name="p407443912165622"></a><a name="p407443912165622"></a>Defines the simplified writing used to indicate the <strong id="b1533945343165622"><a name="b1533945343165622"></a><a name="b1533945343165622"></a>__sa_handler.sa_handler</strong> field in <a href="sigaction.md">sigaction</a>. </p>
</td>
</tr>
<tr id="row615555308165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1378641557165622"><a name="p1378641557165622"></a><a name="p1378641557165622"></a><em id="ga14be6197399829e41a778070ecebd9a3"><a name="ga14be6197399829e41a778070ecebd9a3"></a><a name="ga14be6197399829e41a778070ecebd9a3"></a></em>sa_sigaction    __sa_handler.sa_sigaction</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1099417239165622"><a name="p1099417239165622"></a><a name="p1099417239165622"></a>Defines the simplified writing used to indicate the <strong id="b1398232374165622"><a name="b1398232374165622"></a><a name="b1398232374165622"></a>__sa_handler.sa_sigaction</strong> field in <a href="sigaction.md">sigaction</a>. </p>
</td>
</tr>
<tr id="row908023383165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1740716881165622"><a name="p1740716881165622"></a><a name="p1740716881165622"></a><em id="ga06d5881eeb84e6ac35f5b801c380dbb6"><a name="ga06d5881eeb84e6ac35f5b801c380dbb6"></a><a name="ga06d5881eeb84e6ac35f5b801c380dbb6"></a></em>SIGEV_SIGNAL    0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1014930791165622"><a name="p1014930791165622"></a><a name="p1014930791165622"></a>Sets the notification method in <a href="sigevent.md">sigevent</a>: signal notification. </p>
</td>
</tr>
<tr id="row2120925938165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p46449671165622"><a name="p46449671165622"></a><a name="p46449671165622"></a><em id="gaced9a66610d9d61756999ce4f103740e"><a name="gaced9a66610d9d61756999ce4f103740e"></a><a name="gaced9a66610d9d61756999ce4f103740e"></a></em>SIGEV_NONE    1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p290002406165622"><a name="p290002406165622"></a><a name="p290002406165622"></a>Sets the notification method in <a href="sigevent.md">sigevent</a>: no notification. </p>
</td>
</tr>
<tr id="row397844933165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p658867187165622"><a name="p658867187165622"></a><a name="p658867187165622"></a><em id="ga29ccb6a17fa90a1357b478f62af7fca0"><a name="ga29ccb6a17fa90a1357b478f62af7fca0"></a><a name="ga29ccb6a17fa90a1357b478f62af7fca0"></a></em>SIGEV_THREAD    2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p320810326165622"><a name="p320810326165622"></a><a name="p320810326165622"></a>Sets the notification method in <a href="sigevent.md">sigevent</a>: thread notification. </p>
</td>
</tr>
<tr id="row821285637165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p482396297165622"><a name="p482396297165622"></a><a name="p482396297165622"></a><em id="ga3c330fbddd84bf34e65af370b11998d6"><a name="ga3c330fbddd84bf34e65af370b11998d6"></a><a name="ga3c330fbddd84bf34e65af370b11998d6"></a></em>SIG_ERR    ((__sighandler_t)-1)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1334137995165622"><a name="p1334137995165622"></a><a name="p1334137995165622"></a>Defines the value returned when a function such as <a href="ipc.md#gaf0f8ed40d30773bdb68e858ef0139b58">signal()</a> fails. </p>
</td>
</tr>
<tr id="row1151669578165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1674382648165622"><a name="p1674382648165622"></a><a name="p1674382648165622"></a><em id="ga27d5dc561093d6243542e6a2465bc0f8"><a name="ga27d5dc561093d6243542e6a2465bc0f8"></a><a name="ga27d5dc561093d6243542e6a2465bc0f8"></a></em>SIG_DFL    ((__sighandler_t)0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p544838118165622"><a name="p544838118165622"></a><a name="p544838118165622"></a>Defines the default signal processing mode. </p>
</td>
</tr>
<tr id="row1456465365165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p645147098165622"><a name="p645147098165622"></a><a name="p645147098165622"></a><em id="gacf0e499b0ac946b366b4f47a3b3e8b9e"><a name="gacf0e499b0ac946b366b4f47a3b3e8b9e"></a><a name="gacf0e499b0ac946b366b4f47a3b3e8b9e"></a></em>SIG_IGN    ((__sighandler_t)1)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1004714443165622"><a name="p1004714443165622"></a><a name="p1004714443165622"></a>Defines the signal processing mode in which the signal is ignored. </p>
</td>
</tr>
<tr id="row1460548394165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1048557560165622"><a name="p1048557560165622"></a><a name="p1048557560165622"></a><em id="gace43f23fcb66ddaad964bb8ea8de6e9c"><a name="gace43f23fcb66ddaad964bb8ea8de6e9c"></a><a name="gace43f23fcb66ddaad964bb8ea8de6e9c"></a></em>IPC_CREAT    01000</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p544568529165622"><a name="p544568529165622"></a><a name="p544568529165622"></a>Defines the input parameter used to create an IPC object. </p>
</td>
</tr>
<tr id="row166814375165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1467193182165622"><a name="p1467193182165622"></a><a name="p1467193182165622"></a><em id="gacd312ab97691605718a3ee9a1c7c63e9"><a name="gacd312ab97691605718a3ee9a1c7c63e9"></a><a name="gacd312ab97691605718a3ee9a1c7c63e9"></a></em>IPC_EXCL    02000</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p661182949165622"><a name="p661182949165622"></a><a name="p661182949165622"></a>Defines the input parameter used together with <a href="ipc.md#gace43f23fcb66ddaad964bb8ea8de6e9c">IPC_CREAT</a> to prevent duplicate key values during IPC creation. </p>
</td>
</tr>
<tr id="row83428934165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p29275974165622"><a name="p29275974165622"></a><a name="p29275974165622"></a><em id="ga5afdf5fc48bb22fa27fbd85627b189b9"><a name="ga5afdf5fc48bb22fa27fbd85627b189b9"></a><a name="ga5afdf5fc48bb22fa27fbd85627b189b9"></a></em>IPC_NOWAIT    04000</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1531485729165622"><a name="p1531485729165622"></a><a name="p1531485729165622"></a>Defines the input parameter that specifies whether the communication is in non-blocking mode. </p>
</td>
</tr>
<tr id="row681215586165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1487662080165622"><a name="p1487662080165622"></a><a name="p1487662080165622"></a><em id="ga752c83032a7bec60c904d97508ea4599"><a name="ga752c83032a7bec60c904d97508ea4599"></a><a name="ga752c83032a7bec60c904d97508ea4599"></a></em>IPC_RMID    0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1047594216165622"><a name="p1047594216165622"></a><a name="p1047594216165622"></a>Defines the input parameter used to delete an IPC object. </p>
</td>
</tr>
<tr id="row1801640877165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p231666567165622"><a name="p231666567165622"></a><a name="p231666567165622"></a><em id="ga1f1cdce55426e50878b1c71a4fc67a41"><a name="ga1f1cdce55426e50878b1c71a4fc67a41"></a><a name="ga1f1cdce55426e50878b1c71a4fc67a41"></a></em>IPC_SET    1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1861407843165622"><a name="p1861407843165622"></a><a name="p1861407843165622"></a>Defines the input parameter used to set information to the kernel. </p>
</td>
</tr>
<tr id="row51932935165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1028661935165622"><a name="p1028661935165622"></a><a name="p1028661935165622"></a><em id="ga17d3735e2d47ffa00a2cdf3a066f40d0"><a name="ga17d3735e2d47ffa00a2cdf3a066f40d0"></a><a name="ga17d3735e2d47ffa00a2cdf3a066f40d0"></a></em>IPC_INFO    3</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1028769705165622"><a name="p1028769705165622"></a><a name="p1028769705165622"></a>Defines the input parameter used to obtain the system-level restriction information of a specified communication type, for example, <a href="shminfo.md">shminfo</a>. </p>
</td>
</tr>
<tr id="row268696486165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p808191048165622"><a name="p808191048165622"></a><a name="p808191048165622"></a><em id="gae2b9b856a4a657c250b0b2e1cc0835d9"><a name="gae2b9b856a4a657c250b0b2e1cc0835d9"></a><a name="gae2b9b856a4a657c250b0b2e1cc0835d9"></a></em>IPC_PRIVATE    ((<a href="utils.md#ga4f8c894a6c2b415e55f3f858afd9e7f5">key_t</a>) 0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2046567384165622"><a name="p2046567384165622"></a><a name="p2046567384165622"></a>Defines the IPC object as a private object. </p>
</td>
</tr>
</tbody>
</table>

## Typedefs<a name="typedef-members"></a>

<a name="table1997558084165622"></a>
<table><thead align="left"><tr id="row1422605628165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p314437370165622"><a name="p314437370165622"></a><a name="p314437370165622"></a>Typedef Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p368418639165622"><a name="p368418639165622"></a><a name="p368418639165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row441341740165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1476944454165622"><a name="p1476944454165622"></a><a name="p1476944454165622"></a>mqd_t </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p369593576165622"><a name="p369593576165622"></a><a name="p369593576165622"></a><strong id="ga4820b065fbcbb30569e78e64ef5ad809"><a name="ga4820b065fbcbb30569e78e64ef5ad809"></a><a name="ga4820b065fbcbb30569e78e64ef5ad809"></a></strong> typedef int </p>
<p id="p462924244165622"><a name="p462924244165622"></a><a name="p462924244165622"></a>Represents the data type of a message queue. </p>
</td>
</tr>
<tr id="row173085091165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p284041675165622"><a name="p284041675165622"></a><a name="p284041675165622"></a>ucontext_t </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1922490800165622"><a name="p1922490800165622"></a><a name="p1922490800165622"></a><strong id="ga1a2cdfb5c67c69b7aaab293b0946593b"><a name="ga1a2cdfb5c67c69b7aaab293b0946593b"></a><a name="ga1a2cdfb5c67c69b7aaab293b0946593b"></a></strong> typedef struct <a href="__ucontext.md">__ucontext</a> </p>
<p id="p571734704165622"><a name="p571734704165622"></a><a name="p571734704165622"></a>Describes the user execution context. </p>
</td>
</tr>
<tr id="row273557213165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1913752748165622"><a name="p1913752748165622"></a><a name="p1913752748165622"></a>sighandler_t ) (int)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1393419115165622"><a name="p1393419115165622"></a><a name="p1393419115165622"></a><strong id="ga754cdc0bcfffe07baa426dc252c9101a"><a name="ga754cdc0bcfffe07baa426dc252c9101a"></a><a name="ga754cdc0bcfffe07baa426dc252c9101a"></a></strong> typedef void(* </p>
<p id="p28241501165622"><a name="p28241501165622"></a><a name="p28241501165622"></a>Function pointer of signal handler. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table600935201165622"></a>
<table><thead align="left"><tr id="row445238374165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1060834593165622"><a name="p1060834593165622"></a><a name="p1060834593165622"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1993765608165622"><a name="p1993765608165622"></a><a name="p1993765608165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row894228097165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2029722982165622"><a name="p2029722982165622"></a><a name="p2029722982165622"></a><a href="ipc.md#ga3fbd3906296be63451c64d69be2bc371">mq_close</a> (<a href="ipc.md#ga4820b065fbcbb30569e78e64ef5ad809">mqd_t</a> mqdes)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1639301948165622"><a name="p1639301948165622"></a><a name="p1639301948165622"></a>int </p>
<p id="p2047247745165622"><a name="p2047247745165622"></a><a name="p2047247745165622"></a>Closes a message queue that is no longer used. </p>
</td>
</tr>
<tr id="row8176330165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p253920511165622"><a name="p253920511165622"></a><a name="p253920511165622"></a><a href="ipc.md#ga8fafe8b1183830322f8ff875f4e6cb4c">mq_getattr</a> (<a href="ipc.md#ga4820b065fbcbb30569e78e64ef5ad809">mqd_t</a> mqdes, struct <a href="mq_attr.md">mq_attr</a> *attr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p975121748165622"><a name="p975121748165622"></a><a name="p975121748165622"></a>int </p>
<p id="p1765042671165622"><a name="p1765042671165622"></a><a name="p1765042671165622"></a>Obtains the attributes of the message queue specified by the descriptor. The values of <strong id="b1806076839165622"><a name="b1806076839165622"></a><a name="b1806076839165622"></a>mq_maxmsg</strong>, <strong id="b112233015165622"><a name="b112233015165622"></a><a name="b112233015165622"></a>mq_msgsize</strong>, and <strong id="b408180956165622"><a name="b408180956165622"></a><a name="b408180956165622"></a>mq_curmsgs</strong> are fixed. </p>
</td>
</tr>
<tr id="row801947670165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p867409140165622"><a name="p867409140165622"></a><a name="p867409140165622"></a><a href="ipc.md#gaf5d8bf423701bd1783849119511381a5">mq_open</a> (const char *name, int oflag,...)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1676901614165622"><a name="p1676901614165622"></a><a name="p1676901614165622"></a><a href="ipc.md#ga4820b065fbcbb30569e78e64ef5ad809">mqd_t</a> </p>
<p id="p836676900165622"><a name="p836676900165622"></a><a name="p836676900165622"></a>Creates a message queue or opens an existing message queue. </p>
</td>
</tr>
<tr id="row2052549792165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1655514196165622"><a name="p1655514196165622"></a><a name="p1655514196165622"></a><a href="ipc.md#gafcd715bf914289ca502136ef7022eab7">mq_receive</a> (<a href="ipc.md#ga4820b065fbcbb30569e78e64ef5ad809">mqd_t</a> mqdes, char *buffer, size_t size, unsigned *prioptr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1926463223165622"><a name="p1926463223165622"></a><a name="p1926463223165622"></a>ssize_t </p>
<p id="p867148483165622"><a name="p867148483165622"></a><a name="p867148483165622"></a>Receives a message from a specified message queue. </p>
</td>
</tr>
<tr id="row225618105165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p894491444165622"><a name="p894491444165622"></a><a name="p894491444165622"></a><a href="ipc.md#ga2d07e256d809a61bdc82178cb0dd1ba1">mq_send</a> (<a href="ipc.md#ga4820b065fbcbb30569e78e64ef5ad809">mqd_t</a> mqdes, const char *buffer, size_t size, unsigned prio)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1131233534165622"><a name="p1131233534165622"></a><a name="p1131233534165622"></a>int </p>
<p id="p1666357248165622"><a name="p1666357248165622"></a><a name="p1666357248165622"></a>Sends a message to a specified message queue. </p>
</td>
</tr>
<tr id="row148652569165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p275006402165622"><a name="p275006402165622"></a><a name="p275006402165622"></a><a href="ipc.md#gaf5cc07adf7823fac8611200b55fc3a27">mq_setattr</a> (<a href="ipc.md#ga4820b065fbcbb30569e78e64ef5ad809">mqd_t</a> mqdes, const struct <a href="mq_attr.md">mq_attr</a> *__restrict newattr, struct <a href="mq_attr.md">mq_attr</a> *__restrict oldattr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1490483540165622"><a name="p1490483540165622"></a><a name="p1490483540165622"></a>int </p>
<p id="p390673510165622"><a name="p390673510165622"></a><a name="p390673510165622"></a>Sets the attributes of the message queue specified by the descriptor. The <strong id="b347524194165622"><a name="b347524194165622"></a><a name="b347524194165622"></a>mq_maxmsg</strong>, <strong id="b854568743165622"><a name="b854568743165622"></a><a name="b854568743165622"></a>mq_msgsize</strong>, and <strong id="b1771914040165622"><a name="b1771914040165622"></a><a name="b1771914040165622"></a>mq_curmsgs</strong> attributes cannot be modified. <strong id="b1276284557165622"><a name="b1276284557165622"></a><a name="b1276284557165622"></a>mq_flags</strong> supports the <strong id="b1107817925165622"><a name="b1107817925165622"></a><a name="b1107817925165622"></a>O_NONBLOCK</strong> attribute only. </p>
</td>
</tr>
<tr id="row1943254425165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1593841112165622"><a name="p1593841112165622"></a><a name="p1593841112165622"></a><a href="ipc.md#gaa291cc1bc8bb02fd24bd0d4c563350f4">mq_timedreceive</a> (<a href="ipc.md#ga4820b065fbcbb30569e78e64ef5ad809">mqd_t</a> mqdes, char *__restrict buffer, size_t size, unsigned *__restrict prioptr, const struct <a href="timespec.md">timespec</a> *__restrict timeout)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p806017742165622"><a name="p806017742165622"></a><a name="p806017742165622"></a>ssize_t </p>
<p id="p384010083165622"><a name="p384010083165622"></a><a name="p384010083165622"></a>Receives a message from the message queue, with a timeout period specified. </p>
</td>
</tr>
<tr id="row257611831165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1226908216165622"><a name="p1226908216165622"></a><a name="p1226908216165622"></a><a href="ipc.md#gae59709d01cc34d009edfeae9900568cb">mq_timedsend</a> (<a href="ipc.md#ga4820b065fbcbb30569e78e64ef5ad809">mqd_t</a> mqdes, const char *buffer, size_t size, unsigned prio, const struct <a href="timespec.md">timespec</a> *timeout)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2141318523165622"><a name="p2141318523165622"></a><a name="p2141318523165622"></a>int </p>
<p id="p867522890165622"><a name="p867522890165622"></a><a name="p867522890165622"></a>Sends a message to a specified message queue, with a timeout period specified. </p>
</td>
</tr>
<tr id="row1841733030165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1102584729165622"><a name="p1102584729165622"></a><a name="p1102584729165622"></a><a href="ipc.md#gaccd8c5ee36e60d990963e1d544ef4140">mq_unlink</a> (const char *name)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1988880704165622"><a name="p1988880704165622"></a><a name="p1988880704165622"></a>int </p>
<p id="p1101809150165622"><a name="p1101809150165622"></a><a name="p1101809150165622"></a>Decreases the reference count of the message queue by 1, or deletes the message queue if the reference count is <strong id="b75649798165622"><a name="b75649798165622"></a><a name="b75649798165622"></a>0</strong>. </p>
</td>
</tr>
<tr id="row2028455822165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1400596638165622"><a name="p1400596638165622"></a><a name="p1400596638165622"></a><a href="ipc.md#ga4e398fea1080fd7919e5c72ee94e2fc5">sem_close</a> (<a href="sem_t.md">sem_t</a> *sem)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p689767683165622"><a name="p689767683165622"></a><a name="p689767683165622"></a>int </p>
<p id="p711567646165622"><a name="p711567646165622"></a><a name="p711567646165622"></a>Closes a specified semaphore. </p>
</td>
</tr>
<tr id="row2050620431165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p990190686165622"><a name="p990190686165622"></a><a name="p990190686165622"></a><a href="ipc.md#ga6bc9a7dd941a9b5e319715b767af5682">sem_destroy</a> (<a href="sem_t.md">sem_t</a> *sem)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1809421333165622"><a name="p1809421333165622"></a><a name="p1809421333165622"></a>int </p>
<p id="p1865962241165622"><a name="p1865962241165622"></a><a name="p1865962241165622"></a>Destroys a specified anonymous semaphore that is no longer used. </p>
</td>
</tr>
<tr id="row1202074660165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p794788020165622"><a name="p794788020165622"></a><a name="p794788020165622"></a><a href="ipc.md#ga934bcc3cbc0c67a9e3a8e7a43c023460">sem_getvalue</a> (<a href="sem_t.md">sem_t</a> *__restrict sem, int *__restrict sval)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1581169302165622"><a name="p1581169302165622"></a><a name="p1581169302165622"></a>int </p>
<p id="p765365882165622"><a name="p765365882165622"></a><a name="p765365882165622"></a>Obtains the count value of a specified semaphore. </p>
</td>
</tr>
<tr id="row1370568641165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1819144484165622"><a name="p1819144484165622"></a><a name="p1819144484165622"></a><a href="ipc.md#ga532509bd8a6499f8193253192fb83a3d">sem_init</a> (<a href="sem_t.md">sem_t</a> *sem, int pshared, unsigned int value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1878442619165622"><a name="p1878442619165622"></a><a name="p1878442619165622"></a>int </p>
<p id="p1272999077165622"><a name="p1272999077165622"></a><a name="p1272999077165622"></a>Creates and initializes an anonymous semaphore. </p>
</td>
</tr>
<tr id="row1789075310165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p193512251165622"><a name="p193512251165622"></a><a name="p193512251165622"></a><a href="ipc.md#ga015dce85cab8477c679cc47968958247">sem_post</a> (<a href="sem_t.md">sem_t</a> *sem)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p434747485165622"><a name="p434747485165622"></a><a name="p434747485165622"></a>int </p>
<p id="p1151855848165622"><a name="p1151855848165622"></a><a name="p1151855848165622"></a>Increments the semaphore count by 1. </p>
</td>
</tr>
<tr id="row284162641165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1929535787165622"><a name="p1929535787165622"></a><a name="p1929535787165622"></a><a href="ipc.md#ga9d832817226c594e7628e2cc7ed7d723">sem_timedwait</a> (<a href="sem_t.md">sem_t</a> *__restrict sem, const struct <a href="timespec.md">timespec</a> *__restrict timeout)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1112055227165622"><a name="p1112055227165622"></a><a name="p1112055227165622"></a>int </p>
<p id="p33136097165622"><a name="p33136097165622"></a><a name="p33136097165622"></a>Obtains the semaphore, with a timeout period specified. </p>
</td>
</tr>
<tr id="row1096329721165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p500942214165622"><a name="p500942214165622"></a><a name="p500942214165622"></a><a href="ipc.md#ga4de7a9a334b01b6373b017aaefa07cf0">sem_trywait</a> (<a href="sem_t.md">sem_t</a> *sem)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1762277997165622"><a name="p1762277997165622"></a><a name="p1762277997165622"></a>int </p>
<p id="p1801395742165622"><a name="p1801395742165622"></a><a name="p1801395742165622"></a>Attempts to obtain the semaphore. </p>
</td>
</tr>
<tr id="row1584661226165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1779081939165622"><a name="p1779081939165622"></a><a name="p1779081939165622"></a><a href="ipc.md#ga776256d1a473906f8b7490689bfcb75c">sem_unlink</a> (const char *name)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1712769496165622"><a name="p1712769496165622"></a><a name="p1712769496165622"></a>int </p>
<p id="p1825073145165622"><a name="p1825073145165622"></a><a name="p1825073145165622"></a>Deletes a specified semaphore. </p>
</td>
</tr>
<tr id="row1314282393165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1026670596165622"><a name="p1026670596165622"></a><a name="p1026670596165622"></a><a href="ipc.md#gaad70020dca2241a2b78e272ca033271b">sem_wait</a> (<a href="sem_t.md">sem_t</a> *sem)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p723971612165622"><a name="p723971612165622"></a><a name="p723971612165622"></a>int </p>
<p id="p2016283739165622"><a name="p2016283739165622"></a><a name="p2016283739165622"></a>Obtains the semaphore. </p>
</td>
</tr>
<tr id="row416051762165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1569104884165622"><a name="p1569104884165622"></a><a name="p1569104884165622"></a><a href="ipc.md#ga4539db972bcf3dd8c8b429af0dc3789d">kill</a> (<a href="utils.md#ga30c34d3eead853c44f459f21b932984c">pid_t</a> pid, int sig)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p366276311165622"><a name="p366276311165622"></a><a name="p366276311165622"></a>int </p>
<p id="p1155632232165622"><a name="p1155632232165622"></a><a name="p1155632232165622"></a>Sends a signal to a specified process. </p>
</td>
</tr>
<tr id="row1141954098165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p826258634165622"><a name="p826258634165622"></a><a name="p826258634165622"></a><a href="ipc.md#ga5925352f90eb589393274fa0376d7def">sigemptyset</a> (sigset_t *set)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p126613276165622"><a name="p126613276165622"></a><a name="p126613276165622"></a>int </p>
<p id="p483195249165622"><a name="p483195249165622"></a><a name="p483195249165622"></a>Clears all signals in a specified signal set. </p>
</td>
</tr>
<tr id="row2083860326165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2039308567165622"><a name="p2039308567165622"></a><a name="p2039308567165622"></a><a href="ipc.md#ga88d7bbc77ea1569ee21c90db549ea023">sigfillset</a> (sigset_t *set)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p178263752165622"><a name="p178263752165622"></a><a name="p178263752165622"></a>int </p>
<p id="p138135725165622"><a name="p138135725165622"></a><a name="p138135725165622"></a>Adds all signals to a specified signal set. </p>
</td>
</tr>
<tr id="row1295055949165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1224933563165622"><a name="p1224933563165622"></a><a name="p1224933563165622"></a><a href="ipc.md#gae412e6a5436a6c28424b0173251d349c">sigaddset</a> (sigset_t *set, int signum)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p985792029165622"><a name="p985792029165622"></a><a name="p985792029165622"></a>int </p>
<p id="p2063728464165622"><a name="p2063728464165622"></a><a name="p2063728464165622"></a>Adds a signal to a specified signal set. </p>
</td>
</tr>
<tr id="row1669459250165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1574896906165622"><a name="p1574896906165622"></a><a name="p1574896906165622"></a><a href="ipc.md#gab0025e4f32ce2737c40cc0074cc6d7d2">sigdelset</a> (sigset_t *set, int signum)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1218748877165622"><a name="p1218748877165622"></a><a name="p1218748877165622"></a>int </p>
<p id="p152232718165622"><a name="p152232718165622"></a><a name="p152232718165622"></a>Delete a signal from a specified signal set. </p>
</td>
</tr>
<tr id="row1413387109165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p684196766165622"><a name="p684196766165622"></a><a name="p684196766165622"></a><a href="ipc.md#ga63693cc65f43d772729b588b453fe1ef">sigismember</a> (const sigset_t *set, int signum)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1894993170165622"><a name="p1894993170165622"></a><a name="p1894993170165622"></a>int </p>
<p id="p1698717159165622"><a name="p1698717159165622"></a><a name="p1698717159165622"></a>Checks whether a signal is in the signal set. </p>
</td>
</tr>
<tr id="row794464266165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1305038341165622"><a name="p1305038341165622"></a><a name="p1305038341165622"></a><a href="ipc.md#gae11d1cbeb529d0050ab5600fe4b5fef9">sigprocmask</a> (int how, const sigset_t *__restrict set, sigset_t *__restrict oldset)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p138046981165622"><a name="p138046981165622"></a><a name="p138046981165622"></a>int </p>
<p id="p1676033231165622"><a name="p1676033231165622"></a><a name="p1676033231165622"></a>Changes the signal mask of the calling thread. </p>
</td>
</tr>
<tr id="row1430274895165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p181994922165622"><a name="p181994922165622"></a><a name="p181994922165622"></a><a href="ipc.md#gae5f92586ad50092a7813465eeef792c0">sigsuspend</a> (const sigset_t *mask)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1096097363165622"><a name="p1096097363165622"></a><a name="p1096097363165622"></a>int </p>
<p id="p59850531165622"><a name="p59850531165622"></a><a name="p59850531165622"></a>Sets <strong id="b997593091165622"><a name="b997593091165622"></a><a name="b997593091165622"></a>mask</strong> as the signal mask set of the current process and suspends the process until a signal processing action is triggered. </p>
</td>
</tr>
<tr id="row1849625014165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1187851006165622"><a name="p1187851006165622"></a><a name="p1187851006165622"></a><a href="ipc.md#ga5263ce0feb3eb0934bc56ab81cae8ddb">sigaction</a> (int signum, const struct <a href="sigaction.md">sigaction</a> *__restrict act, struct <a href="sigaction.md">sigaction</a> *__restrict oldact)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p112592089165622"><a name="p112592089165622"></a><a name="p112592089165622"></a>int </p>
<p id="p770416417165622"><a name="p770416417165622"></a><a name="p770416417165622"></a>Checks or changes the processing action associated with a specified signal. Do not use the process creation function or thread creation function in the registered callback processing function. Otherwise, the process is abnormal. For example, do not use the <strong id="b1399623238165622"><a name="b1399623238165622"></a><a name="b1399623238165622"></a>fork</strong> or <strong id="b1631013116165622"><a name="b1631013116165622"></a><a name="b1631013116165622"></a>pthread_create</strong> function. </p>
</td>
</tr>
<tr id="row1000238723165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1093363316165622"><a name="p1093363316165622"></a><a name="p1093363316165622"></a><a href="ipc.md#ga7b91eecad5998acd6162fde3ab530d7a">sigpending</a> (sigset_t *set)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1196994288165622"><a name="p1196994288165622"></a><a name="p1196994288165622"></a>int </p>
<p id="p598321987165622"><a name="p598321987165622"></a><a name="p598321987165622"></a>Obtains the signal suspended by the current thread. </p>
</td>
</tr>
<tr id="row740615864165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1449330981165622"><a name="p1449330981165622"></a><a name="p1449330981165622"></a><a href="ipc.md#ga900d91a9635b965dbbae6b3cee2d2a2b">sigwait</a> (const sigset_t *__restrict set, int *__restrict sig)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2035363988165622"><a name="p2035363988165622"></a><a name="p2035363988165622"></a>int </p>
<p id="p600038022165622"><a name="p600038022165622"></a><a name="p600038022165622"></a>Suspends the calling thread and waits for the signal. </p>
</td>
</tr>
<tr id="row2095596538165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1778892157165622"><a name="p1778892157165622"></a><a name="p1778892157165622"></a><a href="ipc.md#ga786f18a8e5b7eceed0ddcdc722f3340b">sigwaitinfo</a> (const sigset_t *__restrict set, siginfo_t *__restrict info)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2145068592165622"><a name="p2145068592165622"></a><a name="p2145068592165622"></a>int </p>
<p id="p2125329814165622"><a name="p2125329814165622"></a><a name="p2125329814165622"></a>Suspends the calling thread and waits for the signal, with a timeout period specified. </p>
</td>
</tr>
<tr id="row59253279165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p846596895165622"><a name="p846596895165622"></a><a name="p846596895165622"></a><a href="ipc.md#ga155a526c3da5ffd1a79ba2925bdd278a">sigtimedwait</a> (const sigset_t *__restrict set, siginfo_t *__restrict info, const struct <a href="timespec.md">timespec</a> *__restrict timeout)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p286358093165622"><a name="p286358093165622"></a><a name="p286358093165622"></a>int </p>
<p id="p189725682165622"><a name="p189725682165622"></a><a name="p189725682165622"></a>Suspends the calling thread and waits for the signal, with a timeout period specified. </p>
</td>
</tr>
<tr id="row1564625065165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1777466692165622"><a name="p1777466692165622"></a><a name="p1777466692165622"></a><a href="ipc.md#ga8ca5be75c386a4aacd17be00721bf0f8">pthread_sigmask</a> (int how, const sigset_t *__restrict set, sigset_t *__restrict oldset)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p303635959165622"><a name="p303635959165622"></a><a name="p303635959165622"></a>int </p>
<p id="p1972459924165622"><a name="p1972459924165622"></a><a name="p1972459924165622"></a>Checks or changes the signal mask of the calling thread. </p>
</td>
</tr>
<tr id="row1940118214165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p437461222165622"><a name="p437461222165622"></a><a name="p437461222165622"></a><a href="ipc.md#gada1fed9730b224a68e768e5f2eac53ff">psignal</a> (int signum, const char *s)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1624469267165622"><a name="p1624469267165622"></a><a name="p1624469267165622"></a>void </p>
<p id="p1103829737165622"><a name="p1103829737165622"></a><a name="p1103829737165622"></a>Prints signal information. </p>
</td>
</tr>
<tr id="row556608077165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p833033294165622"><a name="p833033294165622"></a><a name="p833033294165622"></a><a href="ipc.md#ga95a78da8c44db11c7031b678504d0b34">sigpause</a> (int signum)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1502881889165622"><a name="p1502881889165622"></a><a name="p1502881889165622"></a>int </p>
<p id="p1609096110165622"><a name="p1609096110165622"></a><a name="p1609096110165622"></a>Deletes the signal specified by <strong id="b415529981165622"><a name="b415529981165622"></a><a name="b415529981165622"></a>signum</strong> from the signal mask of the calling process and suspends the process until the signal is received. </p>
</td>
</tr>
<tr id="row123902731165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2040495219165622"><a name="p2040495219165622"></a><a name="p2040495219165622"></a><a href="ipc.md#ga4378a40ea3370c436d4e46c7a2a58172">sighold</a> (int signum)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p932194696165622"><a name="p932194696165622"></a><a name="p932194696165622"></a>int </p>
<p id="p262554257165622"><a name="p262554257165622"></a><a name="p262554257165622"></a>Adds the signal specified by <strong id="b1690476858165622"><a name="b1690476858165622"></a><a name="b1690476858165622"></a>signum</strong> to the signal mask of the calling process. </p>
</td>
</tr>
<tr id="row950698506165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p80375481165622"><a name="p80375481165622"></a><a name="p80375481165622"></a><a href="ipc.md#ga96c4aed60b8b727709887e1fae0f5bea">sigrelse</a> (int signum)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p306358213165622"><a name="p306358213165622"></a><a name="p306358213165622"></a>int </p>
<p id="p1232484158165622"><a name="p1232484158165622"></a><a name="p1232484158165622"></a>Deletes the signal specified by <strong id="b859305667165622"><a name="b859305667165622"></a><a name="b859305667165622"></a>signum</strong> from the signal mask of the calling process. </p>
</td>
</tr>
<tr id="row1010462904165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1228997056165622"><a name="p1228997056165622"></a><a name="p1228997056165622"></a><a href="ipc.md#gac41035aa05cb4523ae93e8a6d55f9453">sigisemptyset</a> (const sigset_t *set)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p528756949165622"><a name="p528756949165622"></a><a name="p528756949165622"></a>int </p>
<p id="p1760547995165622"><a name="p1760547995165622"></a><a name="p1760547995165622"></a>Checks whether the signal set is empty. </p>
</td>
</tr>
<tr id="row878812892165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p334351160165622"><a name="p334351160165622"></a><a name="p334351160165622"></a><a href="ipc.md#ga1a0d037b7fd84fb392a4c2ffc6c3525c">sigorset</a> (sigset_t *dest, const sigset_t *left, const sigset_t *right)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p593430623165622"><a name="p593430623165622"></a><a name="p593430623165622"></a>int </p>
<p id="p787220789165622"><a name="p787220789165622"></a><a name="p787220789165622"></a>Adds the union set of <strong id="b428971317165622"><a name="b428971317165622"></a><a name="b428971317165622"></a>left</strong> and <strong id="b631795224165622"><a name="b631795224165622"></a><a name="b631795224165622"></a>right</strong> to <strong id="b651097508165622"><a name="b651097508165622"></a><a name="b651097508165622"></a>dest</strong>. </p>
</td>
</tr>
<tr id="row699189748165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1008002231165622"><a name="p1008002231165622"></a><a name="p1008002231165622"></a><a href="ipc.md#ga2a0910ff9d18931a05b995143dc4576e">sigandset</a> (sigset_t *dest, const sigset_t *left, const sigset_t *right)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1559466005165622"><a name="p1559466005165622"></a><a name="p1559466005165622"></a>int </p>
<p id="p1451653670165622"><a name="p1451653670165622"></a><a name="p1451653670165622"></a>Adds the intersection of <strong id="b112146463165622"><a name="b112146463165622"></a><a name="b112146463165622"></a>left</strong> and <strong id="b875347411165622"><a name="b875347411165622"></a><a name="b875347411165622"></a>right</strong> to <strong id="b1055175780165622"><a name="b1055175780165622"></a><a name="b1055175780165622"></a>dest</strong>. </p>
</td>
</tr>
<tr id="row427836821165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1465672804165622"><a name="p1465672804165622"></a><a name="p1465672804165622"></a><a href="ipc.md#gaf0f8ed40d30773bdb68e858ef0139b58">signal</a> (int signum, <a href="ipc.md#ga754cdc0bcfffe07baa426dc252c9101a">sighandler_t</a> handler)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p853578115165622"><a name="p853578115165622"></a><a name="p853578115165622"></a><a href="ipc.md#ga754cdc0bcfffe07baa426dc252c9101a">sighandler_t</a> </p>
<p id="p194444893165622"><a name="p194444893165622"></a><a name="p194444893165622"></a>Changes the processing action of a specified signal. Do not use the process creation function or thread creation function in the registered callback processing function. Otherwise, the process is abnormal. For example, do not use the <strong id="b1341863916165622"><a name="b1341863916165622"></a><a name="b1341863916165622"></a>fork</strong> or <strong id="b872539410165622"><a name="b872539410165622"></a><a name="b872539410165622"></a>pthread_create</strong> function. </p>
</td>
</tr>
<tr id="row1567921972165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1535714976165622"><a name="p1535714976165622"></a><a name="p1535714976165622"></a><a href="ipc.md#ga350675984ca13ce9b056e69098bda5c6">raise</a> (int signum)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p641222509165622"><a name="p641222509165622"></a><a name="p641222509165622"></a>int </p>
<p id="p2023659973165622"><a name="p2023659973165622"></a><a name="p2023659973165622"></a>Sends a signal to the calling process. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section429935514165622"></a>

## **Function **<a name="section870563513165622"></a>

## kill\(\)<a name="ga4539db972bcf3dd8c8b429af0dc3789d"></a>

```
int kill ([pid_t](utils.md#ga30c34d3eead853c44f459f21b932984c) pid, int sig )
```

 **Description:**

Sends a signal to a specified process. 

**Parameters:**

<a name="table695221347165622"></a>
<table><thead align="left"><tr id="row607090555165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p398151570165622"><a name="p398151570165622"></a><a name="p398151570165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1853140002165622"><a name="p1853140002165622"></a><a name="p1853140002165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row634715471165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">pid</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the target process ID. Parameters <strong id="b1908691919165622"><a name="b1908691919165622"></a><a name="b1908691919165622"></a>0</strong> and <strong id="b1348096975165622"><a name="b1348096975165622"></a><a name="b1348096975165622"></a>-1</strong> are not supported. </td>
</tr>
<tr id="row550073541165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sig</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the signal to be sent. </td>
</tr>
</tbody>
</table>

**Attention:**

The default signal behavior does not support  **STOP**  and  **CONTINUE**, and  **COREDUMP**  is not involved.  [SIGSTOP](ipc.md#ga069e358bc9a864b7dc4fed2440eda14c),  [SIGKILL](ipc.md#gaddd8dcd406ce514ab3b4f576a5343d42), and  [SIGCONT](ipc.md#ga024f43063003e753afc6cca1acd6e104)  cannot be masked. If a process is killed but its parent process is not recycled, a zombie process will be generated. After an asynchronous signal is sent to a process, the signal callback is executed only after the process is scheduled. The kernel cannot forcibly kill the process by using the signal. After the process is killed,  [SIGCHLD](ipc.md#ga0e63521a64cc8bc2b91d36a87d32c9f8)  is sent to its parent process. The sending action cannot be canceled. A sleeping process cannot be woken up by a signal. For example, a process invokes the  **sleep**  function to enter the sleeping state. Currently, suspended and zombie processes cannot be forcibly killed. 

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table284630016165622"></a>
<table><thead align="left"><tr id="row395163342165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p368790292165622"><a name="p368790292165622"></a><a name="p368790292165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1092346957165622"><a name="p1092346957165622"></a><a name="p1092346957165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row2078280536165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1453806320165622"><a name="p1453806320165622"></a><a name="p1453806320165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2131798954165622"><a name="p2131798954165622"></a><a name="p2131798954165622"></a><strong id="b332154474165622"><a name="b332154474165622"></a><a name="b332154474165622"></a>sig</strong> is invalid. </p>
</td>
</tr>
<tr id="row421189105165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1840239654165622"><a name="p1840239654165622"></a><a name="p1840239654165622"></a>EPERM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1672354355165622"><a name="p1672354355165622"></a><a name="p1672354355165622"></a>The current process does not have permission to send the signal to the target process. </p>
</td>
</tr>
</tbody>
</table>

## mq\_close\(\)<a name="ga3fbd3906296be63451c64d69be2bc371"></a>

```
int mq_close ([mqd_t](ipc.md#ga4820b065fbcbb30569e78e64ef5ad809) mqdes)
```

 **Description:**

Closes a message queue that is no longer used. 

**Parameters:**

<a name="table1415908713165622"></a>
<table><thead align="left"><tr id="row1597122712165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1642457194165622"><a name="p1642457194165622"></a><a name="p1642457194165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1558345714165622"><a name="p1558345714165622"></a><a name="p1558345714165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row403361952165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">mqdes</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the descriptor of the message queue to be closed. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the message queue is closed; returns  **-1**  and sets  **errno**  to a value in the following table if the message queue fails to be closed. 

<a name="table675249299165622"></a>
<table><thead align="left"><tr id="row933645208165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1309430426165622"><a name="p1309430426165622"></a><a name="p1309430426165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1864657958165622"><a name="p1864657958165622"></a><a name="p1864657958165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1027911283165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p826530809165622"><a name="p826530809165622"></a><a name="p826530809165622"></a>EBADF </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p854219440165622"><a name="p854219440165622"></a><a name="p854219440165622"></a><strong id="b492421895165622"><a name="b492421895165622"></a><a name="b492421895165622"></a>mqdes</strong> is invalid. </p>
</td>
</tr>
<tr id="row502600205165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1866984952165622"><a name="p1866984952165622"></a><a name="p1866984952165622"></a>EAGAIN </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p52364139165622"><a name="p52364139165622"></a><a name="p52364139165622"></a>Failed to delete the message queue in the function. </p>
</td>
</tr>
<tr id="row428710079165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p490966431165622"><a name="p490966431165622"></a><a name="p490966431165622"></a>EFAULT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p59491978165622"><a name="p59491978165622"></a><a name="p59491978165622"></a>Failed to release the space allocated with the message queue. </p>
</td>
</tr>
<tr id="row972024912165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1138100756165622"><a name="p1138100756165622"></a><a name="p1138100756165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p352045200165622"><a name="p352045200165622"></a><a name="p352045200165622"></a><strong id="b1737418417165622"><a name="b1737418417165622"></a><a name="b1737418417165622"></a>mqdes</strong> is invalid when the message queue is deleted in the function. </p>
</td>
</tr>
</tbody>
</table>

## mq\_getattr\(\)<a name="ga8fafe8b1183830322f8ff875f4e6cb4c"></a>

```
int mq_getattr ([mqd_t](ipc.md#ga4820b065fbcbb30569e78e64ef5ad809) mqdes, struct [mq_attr](mq_attr.md) * attr )
```

 **Description:**

Obtains the attributes of the message queue specified by the descriptor. The values of  **mq\_maxmsg**,  **mq\_msgsize**, and  **mq\_curmsgs**  are fixed. 

**Parameters:**

<a name="table1292349333165622"></a>
<table><thead align="left"><tr id="row1298064906165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1483896122165622"><a name="p1483896122165622"></a><a name="p1483896122165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1436968564165622"><a name="p1436968564165622"></a><a name="p1436968564165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row42903993165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">mqdes</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the message queue descriptor. </td>
</tr>
<tr id="row807697085165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">attr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the obtained message queue attributes. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table558880029165622"></a>
<table><thead align="left"><tr id="row519627136165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p687622013165622"><a name="p687622013165622"></a><a name="p687622013165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p69332243165622"><a name="p69332243165622"></a><a name="p69332243165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row2138518568165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1587094222165622"><a name="p1587094222165622"></a><a name="p1587094222165622"></a>EBADF </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p724700873165622"><a name="p724700873165622"></a><a name="p724700873165622"></a><strong id="b1017828915165622"><a name="b1017828915165622"></a><a name="b1017828915165622"></a>mqdes</strong> is invalid. </p>
</td>
</tr>
<tr id="row1143299076165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p208286577165622"><a name="p208286577165622"></a><a name="p208286577165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1105736948165622"><a name="p1105736948165622"></a><a name="p1105736948165622"></a><strong id="b482637315165622"><a name="b482637315165622"></a><a name="b482637315165622"></a>attr</strong> is <strong id="b796493360165622"><a name="b796493360165622"></a><a name="b796493360165622"></a>NULL</strong>. </p>
</td>
</tr>
</tbody>
</table>

## mq\_open\(\)<a name="gaf5d8bf423701bd1783849119511381a5"></a>

```
[mqd_t](ipc.md#ga4820b065fbcbb30569e78e64ef5ad809) mq_open (const char * name, int oflag,  ... )
```

 **Description:**

Creates a message queue or opens an existing message queue. 

**Parameters:**

<a name="table1281427256165622"></a>
<table><thead align="left"><tr id="row1721689957165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p583235897165622"><a name="p583235897165622"></a><a name="p583235897165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1875634512165622"><a name="p1875634512165622"></a><a name="p1875634512165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1683069173165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">name</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the name of the message queue to be created or opened. The maximum value is 259 bytes. </td>
</tr>
<tr id="row1638975892165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">oflag</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the open flag, including <a href="fs.md#ga7a68c9ffaac7dbcd652225dd7c06a54b">O_RDONLY</a>, <a href="fs.md#ga11b644a8526139c4cc1850dac1271ced">O_WRONLY</a>, <a href="fs.md#gabb0586253488ee61072b73557eeb873b">O_RDWR</a>, <strong id="b84833066165622"><a name="b84833066165622"></a><a name="b84833066165622"></a>O_CREAT</strong>, <strong id="b726235595165622"><a name="b726235595165622"></a><a name="b726235595165622"></a>O_EXCL</strong>, and <strong id="b162656977165622"><a name="b162656977165622"></a><a name="b162656977165622"></a>O_NONBLOCK</strong>. </td>
</tr>
<tr id="row860614389165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">mode</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Used for permission control (not supported currently). Its type is <strong id="b356751657165622"><a name="b356751657165622"></a><a name="b356751657165622"></a>mode_t</strong>. This is parameter is required only during the creation of a message queue. </td>
</tr>
<tr id="row1802190810165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">attr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the queue attributes to be set. Its type is <strong id="b666697946165622"><a name="b666697946165622"></a><a name="b666697946165622"></a>struct <a href="mq_attr.md">mq_attr</a></strong>. This parameter is optional and is used only during the creation of a message queue. </td>
</tr>
</tbody>
</table>

**Attention:**

The message consists of 64 bytes by default, and the maximum length of the message is 64 KB. A maximum of 1024 message queues can be created. The mq\_curmsgs field in  [mq\_attr](mq_attr.md)  is not supported. 

**Returns:**

Returns a message queue descriptor if the creation or opening is successful; returns  **\(mqd\_t\)-1**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table1296120209165622"></a>
<table><thead align="left"><tr id="row744506200165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p708450124165622"><a name="p708450124165622"></a><a name="p708450124165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1695858602165622"><a name="p1695858602165622"></a><a name="p1695858602165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row374462113165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1004165902165622"><a name="p1004165902165622"></a><a name="p1004165902165622"></a>EEXIST </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p274752062165622"><a name="p274752062165622"></a><a name="p274752062165622"></a>Both <strong id="b1297921380165622"><a name="b1297921380165622"></a><a name="b1297921380165622"></a>O_CREAT</strong> and <strong id="b809966185165622"><a name="b809966185165622"></a><a name="b809966185165622"></a>O_EXCL</strong> are specified in <strong id="b484689843165622"><a name="b484689843165622"></a><a name="b484689843165622"></a>oflag</strong>, and a queue with this name already exists. </p>
</td>
</tr>
<tr id="row857084634165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1573510875165622"><a name="p1573510875165622"></a><a name="p1573510875165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p807122868165622"><a name="p807122868165622"></a><a name="p807122868165622"></a><strong id="b590841962165622"><a name="b590841962165622"></a><a name="b590841962165622"></a>O_CREAT</strong> is specified in <strong id="b1470168123165622"><a name="b1470168123165622"></a><a name="b1470168123165622"></a>oflag</strong>, and <strong id="b308011390165622"><a name="b308011390165622"></a><a name="b308011390165622"></a>attr</strong> is invalid. To be specific, the attribute value of the <strong id="b327238725165622"><a name="b327238725165622"></a><a name="b327238725165622"></a>mq_maxmsg</strong> field is less than 0 or greater than <a href="utils.md#ga689b119da994dece91d44b5aeac643ed">USHRT_MAX</a>, or the attribute value of <strong id="b2145177760165622"><a name="b2145177760165622"></a><a name="b2145177760165622"></a>mq_msgsize</strong> is less than 0 or greater than <a href="utils.md#ga689b119da994dece91d44b5aeac643ed">USHRT_MAX</a>-4. <strong id="b481212704165622"><a name="b481212704165622"></a><a name="b481212704165622"></a>name</strong> is <strong id="b1014644703165622"><a name="b1014644703165622"></a><a name="b1014644703165622"></a>NULL</strong>, or the length of the string specified by <strong id="b1514505910165622"><a name="b1514505910165622"></a><a name="b1514505910165622"></a>name</strong> is <strong id="b616153953165622"><a name="b616153953165622"></a><a name="b616153953165622"></a>0</strong>. </p>
</td>
</tr>
<tr id="row589960639165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1735943195165622"><a name="p1735943195165622"></a><a name="p1735943195165622"></a>ENAMETOOLONG </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1612572431165622"><a name="p1612572431165622"></a><a name="p1612572431165622"></a><strong id="b1147211691165622"><a name="b1147211691165622"></a><a name="b1147211691165622"></a>name</strong> is too long. </p>
</td>
</tr>
<tr id="row460632144165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p43526554165622"><a name="p43526554165622"></a><a name="p43526554165622"></a>ENOENT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p674905809165622"><a name="p674905809165622"></a><a name="p674905809165622"></a><strong id="b1806505653165622"><a name="b1806505653165622"></a><a name="b1806505653165622"></a>O_CREAT</strong> is not specified in <strong id="b1795015944165622"><a name="b1795015944165622"></a><a name="b1795015944165622"></a>oflag</strong>, and no queue with this name exists. </p>
</td>
</tr>
<tr id="row9370063165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1578214170165622"><a name="p1578214170165622"></a><a name="p1578214170165622"></a>ENOSPC </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1154899343165622"><a name="p1154899343165622"></a><a name="p1154899343165622"></a>Insufficient memory. </p>
</td>
</tr>
<tr id="row881888470165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p687761612165622"><a name="p687761612165622"></a><a name="p687761612165622"></a>ENFILE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p597930718165622"><a name="p597930718165622"></a><a name="p597930718165622"></a>The number of opened message queues exceeds the maximum. </p>
</td>
</tr>
</tbody>
</table>

## mq\_receive\(\)<a name="gafcd715bf914289ca502136ef7022eab7"></a>

```
ssize_t mq_receive ([mqd_t](ipc.md#ga4820b065fbcbb30569e78e64ef5ad809) mqdes, char * buffer, size_t size, unsigned * prioptr )
```

 **Description:**

Receives a message from a specified message queue. 

The message queue must have been open by  [mq\_open\(\)](ipc.md#gaf5d8bf423701bd1783849119511381a5). 

**Parameters:**

<a name="table2034028325165622"></a>
<table><thead align="left"><tr id="row947625093165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p842910440165622"><a name="p842910440165622"></a><a name="p842910440165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1935138124165622"><a name="p1935138124165622"></a><a name="p1935138124165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row311941293165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">mqdes</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the message queue descriptor. </td>
</tr>
<tr id="row1450525554165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">buffer</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the buffer for receiving the message. </td>
</tr>
<tr id="row1389304375165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">size</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the size of the buffer for receiving the message. </td>
</tr>
<tr id="row1325854167165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">prioptr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the priority of the received message if the value is not <strong id="b912340799165622"><a name="b912340799165622"></a><a name="b912340799165622"></a>NULL</strong>. This parameter is not used because priority-based message processing is not supported. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the number of bytes in the received message if the message is received; returns  **\(mqd\_t\)-1**  and sets  **errno**  to a value in the following table if the message fails to be received. 

<a name="table1981225531165622"></a>
<table><thead align="left"><tr id="row1191127877165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2105732110165622"><a name="p2105732110165622"></a><a name="p2105732110165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p193365026165622"><a name="p193365026165622"></a><a name="p193365026165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row184940618165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p584836916165622"><a name="p584836916165622"></a><a name="p584836916165622"></a>EINTR </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1937531072165622"><a name="p1937531072165622"></a><a name="p1937531072165622"></a>Message receiving is interrupted. </p>
</td>
</tr>
<tr id="row1623272992165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p564608308165622"><a name="p564608308165622"></a><a name="p564608308165622"></a>EAGAIN </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p4957478165622"><a name="p4957478165622"></a><a name="p4957478165622"></a>The message queue is empty, and <strong id="b2022180709165622"><a name="b2022180709165622"></a><a name="b2022180709165622"></a>O_NONBLOCK</strong> is set for the message queue associated with <strong id="b331710879165622"><a name="b331710879165622"></a><a name="b331710879165622"></a>mqdes</strong>. </p>
</td>
</tr>
<tr id="row164888515165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1833765889165622"><a name="p1833765889165622"></a><a name="p1833765889165622"></a>EBADF </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1582381053165622"><a name="p1582381053165622"></a><a name="p1582381053165622"></a><strong id="b1543046450165622"><a name="b1543046450165622"></a><a name="b1543046450165622"></a>mqdes</strong> is invalid or you do not have the read permission. </p>
</td>
</tr>
<tr id="row1144410496165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1542201117165622"><a name="p1542201117165622"></a><a name="p1542201117165622"></a>EMSGSIZE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p977147636165622"><a name="p977147636165622"></a><a name="p977147636165622"></a>The size of the buffer for receiving the message is less than the message size attribute of the message queue. </p>
</td>
</tr>
<tr id="row1567291917165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1516406863165622"><a name="p1516406863165622"></a><a name="p1516406863165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1129019229165622"><a name="p1129019229165622"></a><a name="p1129019229165622"></a><strong id="b228962187165622"><a name="b228962187165622"></a><a name="b228962187165622"></a>mqdes</strong> is <strong id="b510121626165622"><a name="b510121626165622"></a><a name="b510121626165622"></a>NULL</strong> or the value of <strong id="b1221965464165622"><a name="b1221965464165622"></a><a name="b1221965464165622"></a>size</strong> is <strong id="b2051265737165622"><a name="b2051265737165622"></a><a name="b2051265737165622"></a>0</strong>. </p>
</td>
</tr>
</tbody>
</table>

## mq\_send\(\)<a name="ga2d07e256d809a61bdc82178cb0dd1ba1"></a>

```
int mq_send ([mqd_t](ipc.md#ga4820b065fbcbb30569e78e64ef5ad809) mqdes, const char * buffer, size_t size, unsigned prio )
```

 **Description:**

Sends a message to a specified message queue. 

The message queue must have been opened using  [mq\_open\(\)](ipc.md#gaf5d8bf423701bd1783849119511381a5). 

**Parameters:**

<a name="table1361384738165622"></a>
<table><thead align="left"><tr id="row1472927636165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p627534823165622"><a name="p627534823165622"></a><a name="p627534823165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1024899379165622"><a name="p1024899379165622"></a><a name="p1024899379165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1782468014165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">mqdes</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the message queue descriptor. </td>
</tr>
<tr id="row694561552165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">buffer</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the buffer for receiving the message. </td>
</tr>
<tr id="row347929390165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">size</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the size of the buffer for receiving the message. </td>
</tr>
<tr id="row240931919165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">prio</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the priority of the message to be sent. This parameter must be <strong id="b1395995196165622"><a name="b1395995196165622"></a><a name="b1395995196165622"></a>0</strong> because priority-based message processing is not supported. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the message is sent; returns  **-1**  and sets  **errno**  to a value in the following table if the message fails to be sent. 

<a name="table321967885165622"></a>
<table><thead align="left"><tr id="row326598258165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1763753302165622"><a name="p1763753302165622"></a><a name="p1763753302165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1990556679165622"><a name="p1990556679165622"></a><a name="p1990556679165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1361995826165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p186529967165622"><a name="p186529967165622"></a><a name="p186529967165622"></a>EINTR </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1618825112165622"><a name="p1618825112165622"></a><a name="p1618825112165622"></a>Message sending is interrupted. </p>
</td>
</tr>
<tr id="row2055419772165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1587001073165622"><a name="p1587001073165622"></a><a name="p1587001073165622"></a>EAGAIN </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1947589884165622"><a name="p1947589884165622"></a><a name="p1947589884165622"></a>The message queue is full, and <strong id="b284646058165622"><a name="b284646058165622"></a><a name="b284646058165622"></a>O_NONBLOCK</strong> is set for the message queue associated with <strong id="b1356081427165622"><a name="b1356081427165622"></a><a name="b1356081427165622"></a>mqdes</strong>. </p>
</td>
</tr>
<tr id="row1723192906165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p230926127165622"><a name="p230926127165622"></a><a name="p230926127165622"></a>EBADF </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p565173451165622"><a name="p565173451165622"></a><a name="p565173451165622"></a><strong id="b826666254165622"><a name="b826666254165622"></a><a name="b826666254165622"></a>mqdes</strong> is invalid or you do not have the write permission. </p>
</td>
</tr>
<tr id="row1520396462165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1285132041165622"><a name="p1285132041165622"></a><a name="p1285132041165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p127685179165622"><a name="p127685179165622"></a><a name="p127685179165622"></a><strong id="b134046726165622"><a name="b134046726165622"></a><a name="b134046726165622"></a>mqdes</strong> is <strong id="b486577676165622"><a name="b486577676165622"></a><a name="b486577676165622"></a>NULL</strong> or the value of <strong id="b957578163165622"><a name="b957578163165622"></a><a name="b957578163165622"></a>size</strong> is <strong id="b1809079495165622"><a name="b1809079495165622"></a><a name="b1809079495165622"></a>0</strong>. </p>
</td>
</tr>
<tr id="row1239890893165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p180993960165622"><a name="p180993960165622"></a><a name="p180993960165622"></a>EMSGSIZE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p573579493165622"><a name="p573579493165622"></a><a name="p573579493165622"></a>The size of the message to be sent is greater than the message size attribute of the message queue. </p>
</td>
</tr>
<tr id="row1954549558165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2109757933165622"><a name="p2109757933165622"></a><a name="p2109757933165622"></a>EOPNOTSUPP </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p239893121165622"><a name="p239893121165622"></a><a name="p239893121165622"></a>The operation is not supported. </p>
</td>
</tr>
<tr id="row1193518984165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p48862368165622"><a name="p48862368165622"></a><a name="p48862368165622"></a>ENOSPC </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1193472104165622"><a name="p1193472104165622"></a><a name="p1193472104165622"></a>Insufficient space. </p>
</td>
</tr>
</tbody>
</table>

## mq\_setattr\(\)<a name="gaf5cc07adf7823fac8611200b55fc3a27"></a>

```
int mq_setattr ([mqd_t](ipc.md#ga4820b065fbcbb30569e78e64ef5ad809) mqdes, const struct [mq_attr](mq_attr.md) *__restrict newattr, struct [mq_attr](mq_attr.md) *__restrict oldattr )
```

 **Description:**

Sets the attributes of the message queue specified by the descriptor. The  **mq\_maxmsg**,  **mq\_msgsize**, and  **mq\_curmsgs**  attributes cannot be modified.  **mq\_flags**  supports the  **O\_NONBLOCK**  attribute only. 

The message queue must have been opened using  [mq\_open\(\)](ipc.md#gaf5d8bf423701bd1783849119511381a5). 

**Parameters:**

<a name="table1112017859165622"></a>
<table><thead align="left"><tr id="row1470913104165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1425527804165622"><a name="p1425527804165622"></a><a name="p1425527804165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p837615736165622"><a name="p837615736165622"></a><a name="p837615736165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row865114502165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">mqdes</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the message queue descriptor. </td>
</tr>
<tr id="row450249825165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">newattr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the message queue attribute to be set. </td>
</tr>
<tr id="row1816063220165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">oldattr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the original attribute. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the setting is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the setting fails. 

<a name="table216622984165622"></a>
<table><thead align="left"><tr id="row1435221039165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p463956584165622"><a name="p463956584165622"></a><a name="p463956584165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1690790394165622"><a name="p1690790394165622"></a><a name="p1690790394165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1498615962165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1603787704165622"><a name="p1603787704165622"></a><a name="p1603787704165622"></a>EBADF </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p760972613165622"><a name="p760972613165622"></a><a name="p760972613165622"></a><strong id="b1290846541165622"><a name="b1290846541165622"></a><a name="b1290846541165622"></a>mqdes</strong> is invalid. </p>
</td>
</tr>
<tr id="row1281792990165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2142522329165622"><a name="p2142522329165622"></a><a name="p2142522329165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p947015759165622"><a name="p947015759165622"></a><a name="p947015759165622"></a><strong id="b1707421211165622"><a name="b1707421211165622"></a><a name="b1707421211165622"></a>newattr</strong> is <strong id="b835515063165622"><a name="b835515063165622"></a><a name="b835515063165622"></a>NULL</strong>. </p>
</td>
</tr>
</tbody>
</table>

## mq\_timedreceive\(\)<a name="gaa291cc1bc8bb02fd24bd0d4c563350f4"></a>

```
ssize_t mq_timedreceive ([mqd_t](ipc.md#ga4820b065fbcbb30569e78e64ef5ad809) mqdes, char *__restrict buffer, size_t size, unsigned *__restrict prioptr, const struct [timespec](timespec.md) *__restrict timeout )
```

 **Description:**

Receives a message from the message queue, with a timeout period specified. 

The message queue must have been open by  [mq\_open\(\)](ipc.md#gaf5d8bf423701bd1783849119511381a5). 

**Parameters:**

<a name="table1754620817165622"></a>
<table><thead align="left"><tr id="row408477035165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1085065892165622"><a name="p1085065892165622"></a><a name="p1085065892165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1824604608165622"><a name="p1824604608165622"></a><a name="p1824604608165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2106575488165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">mqdes</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the message queue descriptor. </td>
</tr>
<tr id="row856845213165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">buffer</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the buffer for receiving the message. </td>
</tr>
<tr id="row1378498095165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">size</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the size of the buffer for receiving the message. </td>
</tr>
<tr id="row1394139616165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">prioptr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the priority of the received message if the value is not <strong id="b1778158513165622"><a name="b1778158513165622"></a><a name="b1778158513165622"></a>NULL</strong>. This parameter is not used because priority-based message processing is not supported. </td>
</tr>
<tr id="row1409184073165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">timeout</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the timeout duration for returning a request. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the number of bytes in the message if the message is received; returns  **\(mqd\_t\)-1**  and sets  **errno**  to a value in the following table if the message fails to be received. 

<a name="table1737150699165622"></a>
<table><thead align="left"><tr id="row456963112165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1357557627165622"><a name="p1357557627165622"></a><a name="p1357557627165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1341816416165622"><a name="p1341816416165622"></a><a name="p1341816416165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row788898183165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p231517841165622"><a name="p231517841165622"></a><a name="p231517841165622"></a>EINTR </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1829253613165622"><a name="p1829253613165622"></a><a name="p1829253613165622"></a>Message receiving is interrupted. </p>
</td>
</tr>
<tr id="row920170545165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2013033295165622"><a name="p2013033295165622"></a><a name="p2013033295165622"></a>EAGAIN </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p576514802165622"><a name="p576514802165622"></a><a name="p576514802165622"></a>The message queue is empty, and <strong id="b456222681165622"><a name="b456222681165622"></a><a name="b456222681165622"></a>O_NONBLOCK</strong> is set for the message queue associated with <strong id="b296124353165622"><a name="b296124353165622"></a><a name="b296124353165622"></a>mqdes</strong>. </p>
</td>
</tr>
<tr id="row937114485165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1513849034165622"><a name="p1513849034165622"></a><a name="p1513849034165622"></a>EBADF </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p775921371165622"><a name="p775921371165622"></a><a name="p775921371165622"></a><strong id="b671380998165622"><a name="b671380998165622"></a><a name="b671380998165622"></a>mqdes</strong> is invalid or you do not have the read permission. </p>
</td>
</tr>
<tr id="row1613300878165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1823376858165622"><a name="p1823376858165622"></a><a name="p1823376858165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1055517624165622"><a name="p1055517624165622"></a><a name="p1055517624165622"></a><strong id="b653343210165622"><a name="b653343210165622"></a><a name="b653343210165622"></a>mqdes</strong> is <strong id="b1410825125165622"><a name="b1410825125165622"></a><a name="b1410825125165622"></a>NULL</strong> or the value of <strong id="b671747306165622"><a name="b671747306165622"></a><a name="b671747306165622"></a>size</strong> is <strong id="b1637424714165622"><a name="b1637424714165622"></a><a name="b1637424714165622"></a>0</strong>. <strong id="b513323647165622"><a name="b513323647165622"></a><a name="b513323647165622"></a>timeout</strong> is invalid. Specifically, the value of <strong id="b779438341165622"><a name="b779438341165622"></a><a name="b779438341165622"></a>tv_sec</strong> is less than 0, and the value of <strong id="b1595811653165622"><a name="b1595811653165622"></a><a name="b1595811653165622"></a>tv_nsec</strong> is less than 0 or greater than the ninth power of 10. </p>
</td>
</tr>
<tr id="row1494691037165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p400348132165622"><a name="p400348132165622"></a><a name="p400348132165622"></a>EMSGSIZE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1761547716165622"><a name="p1761547716165622"></a><a name="p1761547716165622"></a>The size of the buffer for receiving the message is less than the message size attribute of the message queue. </p>
</td>
</tr>
<tr id="row1100657723165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1682898985165622"><a name="p1682898985165622"></a><a name="p1682898985165622"></a>ETIMEDOUT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p63202333165622"><a name="p63202333165622"></a><a name="p63202333165622"></a>No message is received from the queue before the specified timeout period expires. </p>
</td>
</tr>
</tbody>
</table>

## mq\_timedsend\(\)<a name="gae59709d01cc34d009edfeae9900568cb"></a>

```
int mq_timedsend ([mqd_t](ipc.md#ga4820b065fbcbb30569e78e64ef5ad809) mqdes, const char * buffer, size_t size, unsigned prio, const struct [timespec](timespec.md) * timeout )
```

 **Description:**

Sends a message to a specified message queue, with a timeout period specified. 

The message queue must have been open by  [mq\_open\(\)](ipc.md#gaf5d8bf423701bd1783849119511381a5). 

**Parameters:**

<a name="table659238710165622"></a>
<table><thead align="left"><tr id="row1898421365165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1961779794165622"><a name="p1961779794165622"></a><a name="p1961779794165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p682812894165622"><a name="p682812894165622"></a><a name="p682812894165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row758274049165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">mqdes</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the message queue descriptor. </td>
</tr>
<tr id="row1503063064165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">buffer</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the buffer for sending the message. </td>
</tr>
<tr id="row232882591165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">size</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the size of the message to be sent. </td>
</tr>
<tr id="row1723768321165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">prio</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the priority of the message to be sent. This parameter must be <strong id="b1272809933165622"><a name="b1272809933165622"></a><a name="b1272809933165622"></a>0</strong> because priority-based message processing is not supported. </td>
</tr>
<tr id="row770744230165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">timeout</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the timeout duration for returning a request. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the message is sent; returns  **-1**  and sets  **errno**  to a value in the following table if the message fails to be sent. 

<a name="table926807560165622"></a>
<table><thead align="left"><tr id="row1543412782165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1627777128165622"><a name="p1627777128165622"></a><a name="p1627777128165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1904373767165622"><a name="p1904373767165622"></a><a name="p1904373767165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row400642129165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p518501261165622"><a name="p518501261165622"></a><a name="p518501261165622"></a>EINTR </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1162457989165622"><a name="p1162457989165622"></a><a name="p1162457989165622"></a>Message sending is interrupted. </p>
</td>
</tr>
<tr id="row569388268165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p102966400165622"><a name="p102966400165622"></a><a name="p102966400165622"></a>EAGAIN </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p904510817165622"><a name="p904510817165622"></a><a name="p904510817165622"></a>The message queue is full, and <strong id="b2139928798165622"><a name="b2139928798165622"></a><a name="b2139928798165622"></a>O_NONBLOCK</strong> is set for the message queue associated with <strong id="b1778582618165622"><a name="b1778582618165622"></a><a name="b1778582618165622"></a>mqdes</strong>. </p>
</td>
</tr>
<tr id="row1569593724165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1203406431165622"><a name="p1203406431165622"></a><a name="p1203406431165622"></a>EBADF </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p683260558165622"><a name="p683260558165622"></a><a name="p683260558165622"></a><strong id="b1000495544165622"><a name="b1000495544165622"></a><a name="b1000495544165622"></a>mqdes</strong> is invalid or you do not have the write permission. </p>
</td>
</tr>
<tr id="row915132384165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1011863207165622"><a name="p1011863207165622"></a><a name="p1011863207165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1783444139165622"><a name="p1783444139165622"></a><a name="p1783444139165622"></a><strong id="b683008947165622"><a name="b683008947165622"></a><a name="b683008947165622"></a>mqdes</strong> is <strong id="b584463651165622"><a name="b584463651165622"></a><a name="b584463651165622"></a>NULL</strong> or the value of <strong id="b313876027165622"><a name="b313876027165622"></a><a name="b313876027165622"></a>size</strong> is <strong id="b1859759067165622"><a name="b1859759067165622"></a><a name="b1859759067165622"></a>0</strong>. <strong id="b139119207165622"><a name="b139119207165622"></a><a name="b139119207165622"></a>timeout</strong> is invalid. Specifically, the value of <strong id="b2146191590165622"><a name="b2146191590165622"></a><a name="b2146191590165622"></a>tv_sec</strong> is less than 0, and the value of <strong id="b873036130165622"><a name="b873036130165622"></a><a name="b873036130165622"></a>tv_nsec</strong> is less than 0 or greater than the ninth power of 10. </p>
</td>
</tr>
<tr id="row665083244165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p210887081165622"><a name="p210887081165622"></a><a name="p210887081165622"></a>EMSGSIZE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p783106904165622"><a name="p783106904165622"></a><a name="p783106904165622"></a>The size of the message to be sent is greater than the message size attribute of the message queue. </p>
</td>
</tr>
<tr id="row2074847212165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1064547134165622"><a name="p1064547134165622"></a><a name="p1064547134165622"></a>EOPNOTSUPP </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1491771934165622"><a name="p1491771934165622"></a><a name="p1491771934165622"></a>The operation is not supported. </p>
</td>
</tr>
<tr id="row1666336605165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1129051047165622"><a name="p1129051047165622"></a><a name="p1129051047165622"></a>ETIMEDOUT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1947757599165622"><a name="p1947757599165622"></a><a name="p1947757599165622"></a>No message is sent to the queue before the specified timeout period expires. </p>
</td>
</tr>
</tbody>
</table>

## mq\_unlink\(\)<a name="gaccd8c5ee36e60d990963e1d544ef4140"></a>

```
int mq_unlink (const char * name)
```

 **Description:**

Decreases the reference count of the message queue by 1, or deletes the message queue if the reference count is  **0**. 

**Parameters:**

<a name="table1519520822165622"></a>
<table><thead align="left"><tr id="row185405348165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1203940378165622"><a name="p1203940378165622"></a><a name="p1203940378165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p865391398165622"><a name="p865391398165622"></a><a name="p865391398165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row405489721165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">name</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the message queue name. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table1171701894165622"></a>
<table><thead align="left"><tr id="row1086197444165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p312492864165622"><a name="p312492864165622"></a><a name="p312492864165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1661553566165622"><a name="p1661553566165622"></a><a name="p1661553566165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row67878989165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1137549797165622"><a name="p1137549797165622"></a><a name="p1137549797165622"></a>ENAMETOOLONG </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p753826104165622"><a name="p753826104165622"></a><a name="p753826104165622"></a><strong id="b42088393165622"><a name="b42088393165622"></a><a name="b42088393165622"></a>name</strong> is too long. </p>
</td>
</tr>
<tr id="row436414367165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1179694683165622"><a name="p1179694683165622"></a><a name="p1179694683165622"></a>ENOENT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p939469160165622"><a name="p939469160165622"></a><a name="p939469160165622"></a>There is no message queue with the given name. </p>
</td>
</tr>
<tr id="row1572971161165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1579211487165622"><a name="p1579211487165622"></a><a name="p1579211487165622"></a>EAGAIN </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1339252113165622"><a name="p1339252113165622"></a><a name="p1339252113165622"></a>Failed to delete the message queue. </p>
</td>
</tr>
<tr id="row1507432706165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1070569345165622"><a name="p1070569345165622"></a><a name="p1070569345165622"></a>EBUSY </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p279550620165622"><a name="p279550620165622"></a><a name="p279550620165622"></a>The message queue to be deleted is being used. </p>
</td>
</tr>
<tr id="row2033239187165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1049456355165622"><a name="p1049456355165622"></a><a name="p1049456355165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1489255662165622"><a name="p1489255662165622"></a><a name="p1489255662165622"></a><strong id="b233548643165622"><a name="b233548643165622"></a><a name="b233548643165622"></a>name</strong> is <strong id="b1361042062165622"><a name="b1361042062165622"></a><a name="b1361042062165622"></a>NULL</strong>, or the length of the string specified by <strong id="b2066270309165622"><a name="b2066270309165622"></a><a name="b2066270309165622"></a>name</strong> is <strong id="b428925166165622"><a name="b428925166165622"></a><a name="b428925166165622"></a>0</strong>. </p>
</td>
</tr>
</tbody>
</table>

## psignal\(\)<a name="gada1fed9730b224a68e768e5f2eac53ff"></a>

```
void psignal (int signum, const char * s )
```

 **Description:**

Prints signal information. 

This function is used to print a message on the standard error output. The message consists of the character string  **s**, a colon, a space, a string describing the signal information  **signum**, and a newline character. If the string  **s**  is  **NULL**  or empty, the colon and space are omitted. If  **signum**  is invalid, the message displayed will indicate an unknown signal. 

**Parameters:**

<a name="table1155464970165622"></a>
<table><thead align="left"><tr id="row1144919890165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p96077184165622"><a name="p96077184165622"></a><a name="p96077184165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p636548521165622"><a name="p636548521165622"></a><a name="p636548521165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1146334258165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">signum</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the signal to be operated. </td>
</tr>
<tr id="row239169290165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">s</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the customized string <strong id="b634366913165622"><a name="b634366913165622"></a><a name="b634366913165622"></a>s</strong> to be printed. </td>
</tr>
</tbody>
</table>

## pthread\_sigmask\(\)<a name="ga8ca5be75c386a4aacd17be00721bf0f8"></a>

```
int pthread_sigmask (int how, const sigset_t *__restrict set, sigset_t *__restrict oldset )
```

 **Description:**

Checks or changes the signal mask of the calling thread. 

**Parameters:**

<a name="table550250126165622"></a>
<table><thead align="left"><tr id="row1325684034165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p3719577165622"><a name="p3719577165622"></a><a name="p3719577165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1804750085165622"><a name="p1804750085165622"></a><a name="p1804750085165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1601717283165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">how</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the function behavior. </td>
</tr>
<tr id="row196388630165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">set</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the signal set to be changed. </td>
</tr>
<tr id="row397154794165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">oldset</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Used for returning the original mask set of the calling thread. </td>
</tr>
</tbody>
</table>

<a name="table1980330270165622"></a>
<table><thead align="left"><tr id="row1518769235165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1267420210165622"><a name="p1267420210165622"></a><a name="p1267420210165622"></a>flags </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1132299434165622"><a name="p1132299434165622"></a><a name="p1132299434165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1842077402165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p621605523165622"><a name="p621605523165622"></a><a name="p621605523165622"></a>SIG_BLOCK </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1386102490165622"><a name="p1386102490165622"></a><a name="p1386102490165622"></a>Adds the signals in <strong id="b1989158509165622"><a name="b1989158509165622"></a><a name="b1989158509165622"></a>set</strong> to the mask set of the thread. </p>
</td>
</tr>
<tr id="row1197294416165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1563610650165622"><a name="p1563610650165622"></a><a name="p1563610650165622"></a>SIG_UNBLOCK </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p527705469165622"><a name="p527705469165622"></a><a name="p527705469165622"></a>Removes the signals in <strong id="b1759659170165622"><a name="b1759659170165622"></a><a name="b1759659170165622"></a>set</strong> from the mask set of the thread. </p>
</td>
</tr>
<tr id="row754077448165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1388799521165622"><a name="p1388799521165622"></a><a name="p1388799521165622"></a>SIG_SETMASK </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1916553374165622"><a name="p1916553374165622"></a><a name="p1916553374165622"></a>Sets <strong id="b1534620083165622"><a name="b1534620083165622"></a><a name="b1534620083165622"></a>set</strong> of blocked signals as the mask set of the thread. </p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the change is successful; returns  **errno**  as described below if the change fails. 

<a name="table1355741187165622"></a>
<table><thead align="left"><tr id="row534226558165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1427921736165622"><a name="p1427921736165622"></a><a name="p1427921736165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p198274271165622"><a name="p198274271165622"></a><a name="p198274271165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row735906220165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p309632279165622"><a name="p309632279165622"></a><a name="p309632279165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1686719729165622"><a name="p1686719729165622"></a><a name="p1686719729165622"></a><strong id="b1386477906165622"><a name="b1386477906165622"></a><a name="b1386477906165622"></a>how</strong> is invalid. </p>
</td>
</tr>
<tr id="row553608678165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p170868399165622"><a name="p170868399165622"></a><a name="p170868399165622"></a>EFAULT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p335291505165622"><a name="p335291505165622"></a><a name="p335291505165622"></a>The <strong id="b980143331165622"><a name="b980143331165622"></a><a name="b980143331165622"></a>set</strong> or <strong id="b1483249326165622"><a name="b1483249326165622"></a><a name="b1483249326165622"></a>oldset</strong> points outside the process's allocated address space. </p>
</td>
</tr>
</tbody>
</table>

## raise\(\)<a name="ga350675984ca13ce9b056e69098bda5c6"></a>

```
int raise (int signum)
```

 **Description:**

Sends a signal to the calling process. 

**Parameters:**

<a name="table337485334165622"></a>
<table><thead align="left"><tr id="row1854208440165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1540632744165622"><a name="p1540632744165622"></a><a name="p1540632744165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2007029395165622"><a name="p2007029395165622"></a><a name="p2007029395165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1203151087165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">signum</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the signal to be sent. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns 0 if the operation is successful; returns nonzero if the operation fails. 

## sem\_close\(\)<a name="ga4e398fea1080fd7919e5c72ee94e2fc5"></a>

```
int sem_close ([sem_t](sem_t.md) * sem)
```

 **Description:**

Closes a specified semaphore. 

**Parameters:**

<a name="table1090528632165622"></a>
<table><thead align="left"><tr id="row222847441165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1261885990165622"><a name="p1261885990165622"></a><a name="p1261885990165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1894071916165622"><a name="p1894071916165622"></a><a name="p1894071916165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row117058087165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sem</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the semaphore to close. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the semaphore is closed. errno | Description 

## sem\_destroy\(\)<a name="ga6bc9a7dd941a9b5e319715b767af5682"></a>

```
int sem_destroy ([sem_t](sem_t.md) * sem)
```

 **Description:**

Destroys a specified anonymous semaphore that is no longer used. 

**Parameters:**

<a name="table467226041165622"></a>
<table><thead align="left"><tr id="row1994617768165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p399910676165622"><a name="p399910676165622"></a><a name="p399910676165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1394963073165622"><a name="p1394963073165622"></a><a name="p1394963073165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row39770063165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sem</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the semaphore to destroy. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the destruction is successful. 

## sem\_getvalue\(\)<a name="ga934bcc3cbc0c67a9e3a8e7a43c023460"></a>

```
int sem_getvalue ([sem_t](sem_t.md) *__restrict sem, int *__restrict sval )
```

 **Description:**

Obtains the count value of a specified semaphore. 

**Parameters:**

<a name="table600729567165622"></a>
<table><thead align="left"><tr id="row440688018165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2035135676165622"><a name="p2035135676165622"></a><a name="p2035135676165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1775990351165622"><a name="p1775990351165622"></a><a name="p1775990351165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1175889701165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sem</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the semaphore. </td>
</tr>
<tr id="row1345945248165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sval</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the obtained count value. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful. 

## sem\_init\(\)<a name="ga532509bd8a6499f8193253192fb83a3d"></a>

```
int sem_init ([sem_t](sem_t.md) * sem, int pshared, unsigned int value )
```

 **Description:**

Creates and initializes an anonymous semaphore. 

**Parameters:**

<a name="table151114157165622"></a>
<table><thead align="left"><tr id="row1923749202165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p643459095165622"><a name="p643459095165622"></a><a name="p643459095165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2001131067165622"><a name="p2001131067165622"></a><a name="p2001131067165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row884502194165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sem</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the semaphore to be created or initialized. </td>
</tr>
<tr id="row2086018178165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">pshared</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Specifies whether the semaphore can be shared between the threads of a process. <strong id="b220949537165622"><a name="b220949537165622"></a><a name="b220949537165622"></a>0</strong> indicates that the semaphore is shared between the threads of a process. A non-zero value indicates that the semaphore can be shared between processes. </td>
</tr>
<tr id="row1649018369165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the initial count value of the new semaphore. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the initialization is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the initialization fails. 

<a name="table1319008238165622"></a>
<table><thead align="left"><tr id="row1706768314165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1483269086165622"><a name="p1483269086165622"></a><a name="p1483269086165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1463964960165622"><a name="p1463964960165622"></a><a name="p1463964960165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row598695713165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2011889910165622"><a name="p2011889910165622"></a><a name="p2011889910165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1602501050165622"><a name="p1602501050165622"></a><a name="p1602501050165622"></a>The input parameters are invalid and the initial count value exceeds the limit. </p>
</td>
</tr>
</tbody>
</table>

## sem\_post\(\)<a name="ga015dce85cab8477c679cc47968958247"></a>

```
int sem_post ([sem_t](sem_t.md) * sem)
```

 **Description:**

Increments the semaphore count by 1. 

Generally, this function is used to increment the count of available shared resources when the process is to leave its critical section. This function is used together with  [sem\_wait\(\)](ipc.md#gaad70020dca2241a2b78e272ca033271b)  to protect shared resources. 

**Parameters:**

<a name="table1843788428165622"></a>
<table><thead align="left"><tr id="row1123260229165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1608594477165622"><a name="p1608594477165622"></a><a name="p1608594477165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2127295757165622"><a name="p2127295757165622"></a><a name="p2127295757165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1227454107165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sem</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the semaphore to be operated. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table1551478902165622"></a>
<table><thead align="left"><tr id="row1120175580165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1468998904165622"><a name="p1468998904165622"></a><a name="p1468998904165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p857281911165622"><a name="p857281911165622"></a><a name="p857281911165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row523791732165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p57742800165622"><a name="p57742800165622"></a><a name="p57742800165622"></a>EOVERFLOW </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p157622579165622"><a name="p157622579165622"></a><a name="p157622579165622"></a>The number of semaphores exceeds the maximum number. </p>
</td>
</tr>
</tbody>
</table>

## sem\_timedwait\(\)<a name="ga9d832817226c594e7628e2cc7ed7d723"></a>

```
int sem_timedwait ([sem_t](sem_t.md) *__restrict sem, const struct [timespec](timespec.md) *__restrict timeout )
```

 **Description:**

Obtains the semaphore, with a timeout period specified. 

If the semaphore count is greater than  **0**, the shared resources can be obtained and the semaphore count decreases by 1. After the function returns  **0**, the code execution enters the resource critical area. Otherwise, the shared resource is unavailable, the function keeps waiting, and code execution cannot enter the resource critical area. If no semaphore is obtained within the specified timeout period,  **-1**  is returned. This function is used together with  [sem\_post\(\)](ipc.md#ga015dce85cab8477c679cc47968958247)  to protect shared resources. 

**Parameters:**

<a name="table572074675165622"></a>
<table><thead align="left"><tr id="row1250254629165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p447467968165622"><a name="p447467968165622"></a><a name="p447467968165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p984559420165622"><a name="p984559420165622"></a><a name="p984559420165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2130067390165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sem</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the semaphore to be operated. </td>
</tr>
<tr id="row703825780165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">timeout</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the timeout period to be set. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the semaphore is obtained; returns  **-1**  and sets  **errno**  to a value in the following table if the semaphore fails to be obtained. 

<a name="table1197409029165622"></a>
<table><thead align="left"><tr id="row662215951165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p380097587165622"><a name="p380097587165622"></a><a name="p380097587165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p462045640165622"><a name="p462045640165622"></a><a name="p462045640165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1259253384165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p296941702165622"><a name="p296941702165622"></a><a name="p296941702165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p582353006165622"><a name="p582353006165622"></a><a name="p582353006165622"></a><strong id="b608615030165622"><a name="b608615030165622"></a><a name="b608615030165622"></a>sem</strong> or <strong id="b740007853165622"><a name="b740007853165622"></a><a name="b740007853165622"></a>timeout</strong> is invalid. </p>
</td>
</tr>
<tr id="row1651131131165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1468820836165622"><a name="p1468820836165622"></a><a name="p1468820836165622"></a>EINTR </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p580630799165622"><a name="p580630799165622"></a><a name="p580630799165622"></a>The waiting for the semaphore is interrupted. </p>
</td>
</tr>
<tr id="row1535496524165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p909066836165622"><a name="p909066836165622"></a><a name="p909066836165622"></a>EAGAIN </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1122631610165622"><a name="p1122631610165622"></a><a name="p1122631610165622"></a>The semaphore is set to non-blocking mode, and the semaphore count is <strong id="b979673353165622"><a name="b979673353165622"></a><a name="b979673353165622"></a>0</strong>. </p>
</td>
</tr>
<tr id="row1817792807165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1979059400165622"><a name="p1979059400165622"></a><a name="p1979059400165622"></a>ETIMEDOUT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p884342891165622"><a name="p884342891165622"></a><a name="p884342891165622"></a>Waiting for the semaphore timed out. </p>
</td>
</tr>
</tbody>
</table>

## sem\_trywait\(\)<a name="ga4de7a9a334b01b6373b017aaefa07cf0"></a>

```
int sem_trywait ([sem_t](sem_t.md) * sem)
```

 **Description:**

Attempts to obtain the semaphore. 

If the semaphore count is greater than  **0**, the shared resources can be obtained and the semaphore count decreases by 1. After the function returns  **0**, the code execution enters the resource critical area. Otherwise, the shared resource is unavailable, and the function returns  **-1**. This function is used together with  [sem\_post\(\)](ipc.md#ga015dce85cab8477c679cc47968958247)  to protect shared resources. 

**Parameters:**

<a name="table655368218165622"></a>
<table><thead align="left"><tr id="row938137437165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1360698929165622"><a name="p1360698929165622"></a><a name="p1360698929165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2034438032165622"><a name="p2034438032165622"></a><a name="p2034438032165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row372610579165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sem</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the semaphore to be operated. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the semaphore is obtained; returns  **-1**  and sets  **errno**  to a value in the following table if the semaphore fails to be obtained. 

<a name="table983345616165622"></a>
<table><thead align="left"><tr id="row391100026165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1105207365165622"><a name="p1105207365165622"></a><a name="p1105207365165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1115998224165622"><a name="p1115998224165622"></a><a name="p1115998224165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1557191758165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p188049613165622"><a name="p188049613165622"></a><a name="p188049613165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p35211203165622"><a name="p35211203165622"></a><a name="p35211203165622"></a><strong id="b583677005165622"><a name="b583677005165622"></a><a name="b583677005165622"></a>sem</strong> is invalid. </p>
</td>
</tr>
<tr id="row1959157642165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p646020302165622"><a name="p646020302165622"></a><a name="p646020302165622"></a>EAGAIN </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2033997825165622"><a name="p2033997825165622"></a><a name="p2033997825165622"></a>The semaphore is set to non-blocking mode, and the semaphore count is <strong id="b1213907738165622"><a name="b1213907738165622"></a><a name="b1213907738165622"></a>0</strong>. </p>
</td>
</tr>
</tbody>
</table>

## sem\_unlink\(\)<a name="ga776256d1a473906f8b7490689bfcb75c"></a>

```
int sem_unlink (const char * name)
```

 **Description:**

Deletes a specified semaphore. 

This function is used to subtract 1 from the open count of the semaphore. If the open count is  **0**, this function deletes the semaphore. 

**Parameters:**

<a name="table568600672165622"></a>
<table><thead align="left"><tr id="row931396163165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p239842613165622"><a name="p239842613165622"></a><a name="p239842613165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p16059175165622"><a name="p16059175165622"></a><a name="p16059175165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row913901244165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">name</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the name of the semaphore to be deleted. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table762722327165622"></a>
<table><thead align="left"><tr id="row211799663165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p141052659165622"><a name="p141052659165622"></a><a name="p141052659165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1186095749165622"><a name="p1186095749165622"></a><a name="p1186095749165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row203919796165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1771605168165622"><a name="p1771605168165622"></a><a name="p1771605168165622"></a>ENAMETOOLONG </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p977707912165622"><a name="p977707912165622"></a><a name="p977707912165622"></a><strong id="b395724156165622"><a name="b395724156165622"></a><a name="b395724156165622"></a>name</strong> is too long. </p>
</td>
</tr>
<tr id="row2081550933165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p387006605165622"><a name="p387006605165622"></a><a name="p387006605165622"></a>ENOENT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p602520230165622"><a name="p602520230165622"></a><a name="p602520230165622"></a>There is no semaphore with the given name. </p>
</td>
</tr>
</tbody>
</table>

## sem\_wait\(\)<a name="gaad70020dca2241a2b78e272ca033271b"></a>

```
int sem_wait ([sem_t](sem_t.md) * sem)
```

 **Description:**

Obtains the semaphore. 

If the semaphore count is greater than  **0**, the shared resources can be obtained and the semaphore count decreases by 1. After the function returns  **0**, the code execution enters the resource critical area. Otherwise, the shared resource is unavailable, the function keeps waiting, and code execution cannot enter the resource critical area. This function is used together with  [sem\_post\(\)](ipc.md#ga015dce85cab8477c679cc47968958247)  to protect shared resources. 

**Parameters:**

<a name="table491460299165622"></a>
<table><thead align="left"><tr id="row1735398878165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1555713300165622"><a name="p1555713300165622"></a><a name="p1555713300165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1944234932165622"><a name="p1944234932165622"></a><a name="p1944234932165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1406776310165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sem</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the semaphore to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the semaphore is obtained; returns  **-1**  and sets  **errno**  to a value in the following table if the semaphore fails to be obtained. 

<a name="table232039593165622"></a>
<table><thead align="left"><tr id="row1970565123165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1097991882165622"><a name="p1097991882165622"></a><a name="p1097991882165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1722375625165622"><a name="p1722375625165622"></a><a name="p1722375625165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1965922185165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p204677915165622"><a name="p204677915165622"></a><a name="p204677915165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p483646398165622"><a name="p483646398165622"></a><a name="p483646398165622"></a><strong id="b166533316165622"><a name="b166533316165622"></a><a name="b166533316165622"></a>sem</strong> is invalid. </p>
</td>
</tr>
<tr id="row1353378892165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p45004141165622"><a name="p45004141165622"></a><a name="p45004141165622"></a>EINTR </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1464131663165622"><a name="p1464131663165622"></a><a name="p1464131663165622"></a>The waiting for the semaphore is interrupted. </p>
</td>
</tr>
<tr id="row1199678043165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p762469560165622"><a name="p762469560165622"></a><a name="p762469560165622"></a>EAGAIN </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p267366039165622"><a name="p267366039165622"></a><a name="p267366039165622"></a>The semaphore is set to non-blocking mode, and the semaphore count is <strong id="b658110192165622"><a name="b658110192165622"></a><a name="b658110192165622"></a>0</strong>. </p>
</td>
</tr>
</tbody>
</table>

## sigaction\(\)<a name="ga5263ce0feb3eb0934bc56ab81cae8ddb"></a>

```
int [sigaction](sigaction.md) (int signum, const struct [sigaction](sigaction.md) *__restrict act, struct [sigaction](sigaction.md) *__restrict oldact )
```

 **Description:**

Checks or changes the processing action associated with a specified signal. Do not use the process creation function or thread creation function in the registered callback processing function. Otherwise, the process is abnormal. For example, do not use the  **fork**  or  **pthread\_create**  function. 

**Parameters:**

<a name="table1408431127165622"></a>
<table><thead align="left"><tr id="row299486216165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p606312172165622"><a name="p606312172165622"></a><a name="p606312172165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p443311177165622"><a name="p443311177165622"></a><a name="p443311177165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1285815170165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">signum</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the signal to be operated. </td>
</tr>
<tr id="row1837040726165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">act</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the new signal processing action. </td>
</tr>
<tr id="row1484992955165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">oldact</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the original signal processing action if the value is not <strong id="b336986728165622"><a name="b336986728165622"></a><a name="b336986728165622"></a>NULL</strong>. </td>
</tr>
</tbody>
</table>

**Attention:**

The  **sa\_flag**  field in  **act**  supports the  [SA\_SIGINFO](ipc.md#ga59b4c0774aace526b10b6d737075a790)  flag only. 

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table313717031165622"></a>
<table><thead align="left"><tr id="row2124133159165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p614972405165622"><a name="p614972405165622"></a><a name="p614972405165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p72783470165622"><a name="p72783470165622"></a><a name="p72783470165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row844875462165622"><td class="cellrowborder" rowspan="2" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p552821163165622"><a name="p552821163165622"></a><a name="p552821163165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p962673498165622"><a name="p962673498165622"></a><a name="p962673498165622"></a><strong id="b35974116165622"><a name="b35974116165622"></a><a name="b35974116165622"></a>signum</strong> is invalid or cannot be captured. </p>
</td>
</tr>
<tr id="row1387710443165622"><td class="cellrowborder" valign="top" headers="mcps1.1.3.1.1 "><p id="p1309541778165622"><a name="p1309541778165622"></a><a name="p1309541778165622"></a><strong id="b1088756413165622"><a name="b1088756413165622"></a><a name="b1088756413165622"></a>act</strong> is <strong id="b774130731165622"><a name="b774130731165622"></a><a name="b774130731165622"></a>NULL</strong>. </p>
</td>
</tr>
<tr id="row1964004698165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1532669895165622"><a name="p1532669895165622"></a><a name="p1532669895165622"></a>ENOMEM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p252028872165622"><a name="p252028872165622"></a><a name="p252028872165622"></a>Insufficient memory. </p>
</td>
</tr>
</tbody>
</table>

## sigaddset\(\)<a name="gae412e6a5436a6c28424b0173251d349c"></a>

```
int sigaddset (sigset_t * set, int signum )
```

 **Description:**

Adds a signal to a specified signal set. 

**Parameters:**

<a name="table108960517165622"></a>
<table><thead align="left"><tr id="row1062201569165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p57019051165622"><a name="p57019051165622"></a><a name="p57019051165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1361553767165622"><a name="p1361553767165622"></a><a name="p1361553767165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1710544348165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">set</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the signal set to hold signals. </td>
</tr>
<tr id="row404001270165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">signum</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the signal to be added. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful. If  **set**  or  **signum**  is invalid, the process is abnormal. 

## sigandset\(\)<a name="ga2a0910ff9d18931a05b995143dc4576e"></a>

```
int sigandset (sigset_t * dest, const sigset_t * left, const sigset_t * right )
```

 **Description:**

Adds the intersection of  **left**  and  **right**  to  **dest**. 

**Parameters:**

<a name="table1446093759165622"></a>
<table><thead align="left"><tr id="row515343548165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p112364574165622"><a name="p112364574165622"></a><a name="p112364574165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1307318996165622"><a name="p1307318996165622"></a><a name="p1307318996165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2055246084165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">dest</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the target signal set. </td>
</tr>
<tr id="row1623198323165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">left</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the <strong id="b757763947165622"><a name="b757763947165622"></a><a name="b757763947165622"></a>left</strong> set to be added. </td>
</tr>
<tr id="row359321067165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">right</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the <strong id="b997001272165622"><a name="b997001272165622"></a><a name="b997001272165622"></a>right</strong> set to be added. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful. 

## sigdelset\(\)<a name="gab0025e4f32ce2737c40cc0074cc6d7d2"></a>

```
int sigdelset (sigset_t * set, int signum )
```

 **Description:**

Delete a signal from a specified signal set. 

**Parameters:**

<a name="table720732664165622"></a>
<table><thead align="left"><tr id="row1172753460165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p213136704165622"><a name="p213136704165622"></a><a name="p213136704165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1980988029165622"><a name="p1980988029165622"></a><a name="p1980988029165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row258877524165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">set</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the signal set to hold signals. </td>
</tr>
<tr id="row62701324165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">signum</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the signal to be deleted. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful. If  **set**  or  **signum**  is invalid, the process is abnormal. 

## sigemptyset\(\)<a name="ga5925352f90eb589393274fa0376d7def"></a>

```
int sigemptyset (sigset_t * set)
```

 **Description:**

Clears all signals in a specified signal set. 

**Parameters:**

<a name="table1716285540165622"></a>
<table><thead align="left"><tr id="row666535138165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1981268249165622"><a name="p1981268249165622"></a><a name="p1981268249165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1770139902165622"><a name="p1770139902165622"></a><a name="p1770139902165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row572777440165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">set</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the signal set to be cleared. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful. If  **set**  is invalid, the process is abnormal. 

## sigfillset\(\)<a name="ga88d7bbc77ea1569ee21c90db549ea023"></a>

```
int sigfillset (sigset_t * set)
```

 **Description:**

Adds all signals to a specified signal set. 

**Parameters:**

<a name="table2125615574165622"></a>
<table><thead align="left"><tr id="row1563354462165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p117149174165622"><a name="p117149174165622"></a><a name="p117149174165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1942416243165622"><a name="p1942416243165622"></a><a name="p1942416243165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1945636570165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">set</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the signal set to hold signals. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful. If  **set**  is invalid, the process is abnormal. 

## sighold\(\)<a name="ga4378a40ea3370c436d4e46c7a2a58172"></a>

```
int sighold (int signum)
```

 **Description:**

Adds the signal specified by  **signum**  to the signal mask of the calling process. 

**Parameters:**

<a name="table43984267165622"></a>
<table><thead align="left"><tr id="row1165650584165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1306472162165622"><a name="p1306472162165622"></a><a name="p1306472162165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p854733541165622"><a name="p854733541165622"></a><a name="p854733541165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1423827938165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">signum</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the signal to be added. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  if the operation fails. 

## sigisemptyset\(\)<a name="gac41035aa05cb4523ae93e8a6d55f9453"></a>

```
int sigisemptyset (const sigset_t * set)
```

 **Description:**

Checks whether the signal set is empty. 

**Parameters:**

<a name="table1568424725165622"></a>
<table><thead align="left"><tr id="row259352278165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1092008298165622"><a name="p1092008298165622"></a><a name="p1092008298165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p814660075165622"><a name="p814660075165622"></a><a name="p814660075165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1552167917165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">set</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the signal set to be checked. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the set is not empty; returns  **1**  if the set is empty; returns  **-1**  if the operation fails. 

## sigismember\(\)<a name="ga63693cc65f43d772729b588b453fe1ef"></a>

```
int sigismember (const sigset_t * set, int signum )
```

 **Description:**

Checks whether a signal is in the signal set. 

**Parameters:**

<a name="table1811546320165622"></a>
<table><thead align="left"><tr id="row271252403165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p142642649165622"><a name="p142642649165622"></a><a name="p142642649165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p301289168165622"><a name="p301289168165622"></a><a name="p301289168165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1586807655165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">set</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the signal set to be checked. </td>
</tr>
<tr id="row52534095165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">signum</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the signal to be checked. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the signal is not in the set; returns  **1**  if the signal is in the set. If  **set**  or  **signum**  is invalid, the process is abnormal. 

## signal\(\)<a name="gaf0f8ed40d30773bdb68e858ef0139b58"></a>

```
[sighandler_t](ipc.md#ga754cdc0bcfffe07baa426dc252c9101a) signal (int signum, [sighandler_t](ipc.md#ga754cdc0bcfffe07baa426dc252c9101a) handler )
```

 **Description:**

Changes the processing action of a specified signal. Do not use the process creation function or thread creation function in the registered callback processing function. Otherwise, the process is abnormal. For example, do not use the  **fork**  or  **pthread\_create**  function. 

**Parameters:**

<a name="table1985259536165622"></a>
<table><thead align="left"><tr id="row1721565890165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p313773053165622"><a name="p313773053165622"></a><a name="p313773053165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1996354277165622"><a name="p1996354277165622"></a><a name="p1996354277165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1487967135165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">signum</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the signal to be operated. </td>
</tr>
<tr id="row487718423165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handler</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the specified processing action (<a href="ipc.md#gacf0e499b0ac946b366b4f47a3b3e8b9e">SIG_IGN</a> or <a href="ipc.md#ga27d5dc561093d6243542e6a2465bc0f8">SIG_DFL</a>, or to a custom processing action. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the pointer to the original processing action if the operation is successful; returns  [SIG\_ERR](ipc.md#ga3c330fbddd84bf34e65af370b11998d6)  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table1131549385165622"></a>
<table><thead align="left"><tr id="row1669954735165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p772755226165622"><a name="p772755226165622"></a><a name="p772755226165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1489609716165622"><a name="p1489609716165622"></a><a name="p1489609716165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row125986762165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1282857453165622"><a name="p1282857453165622"></a><a name="p1282857453165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p399842009165622"><a name="p399842009165622"></a><a name="p399842009165622"></a><strong id="b1830158463165622"><a name="b1830158463165622"></a><a name="b1830158463165622"></a>signum</strong> is invalid. </p>
</td>
</tr>
<tr id="row43121636165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p827276996165622"><a name="p827276996165622"></a><a name="p827276996165622"></a>ENOMEM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2145415266165622"><a name="p2145415266165622"></a><a name="p2145415266165622"></a>Insufficient memory. </p>
</td>
</tr>
</tbody>
</table>

## sigorset\(\)<a name="ga1a0d037b7fd84fb392a4c2ffc6c3525c"></a>

```
int sigorset (sigset_t * dest, const sigset_t * left, const sigset_t * right )
```

 **Description:**

Adds the union set of  **left**  and  **right**  to  **dest**. 

**Parameters:**

<a name="table1196948561165622"></a>
<table><thead align="left"><tr id="row1117797768165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1312857297165622"><a name="p1312857297165622"></a><a name="p1312857297165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p400781087165622"><a name="p400781087165622"></a><a name="p400781087165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1739617907165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">dest</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the target signal set. </td>
</tr>
<tr id="row638705130165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">left</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the <strong id="b501236093165622"><a name="b501236093165622"></a><a name="b501236093165622"></a>left</strong> set to be added. </td>
</tr>
<tr id="row568153857165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">right</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the <strong id="b325706709165622"><a name="b325706709165622"></a><a name="b325706709165622"></a>right</strong> set to be added. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful. 

## sigpause\(\)<a name="ga95a78da8c44db11c7031b678504d0b34"></a>

```
int sigpause (int signum)
```

 **Description:**

Deletes the signal specified by  **signum**  from the signal mask of the calling process and suspends the process until the signal is received. 

**Parameters:**

<a name="table161025209165622"></a>
<table><thead align="left"><tr id="row1345753930165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1626037225165622"><a name="p1626037225165622"></a><a name="p1626037225165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1323898102165622"><a name="p1323898102165622"></a><a name="p1323898102165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1399102965165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">signum</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the signal to be operated. </td>
</tr>
</tbody>
</table>

**Attention:**

After the signal is received, the original signal mask of the process is restored. 

**Returns:**

Returns  **-1**  and sets  **errno**  to a value in the following table. 

<a name="table68601110165622"></a>
<table><thead align="left"><tr id="row944072245165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p351947193165622"><a name="p351947193165622"></a><a name="p351947193165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p179308970165622"><a name="p179308970165622"></a><a name="p179308970165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1656561622165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p767034289165622"><a name="p767034289165622"></a><a name="p767034289165622"></a>EINTR </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1679091709165622"><a name="p1679091709165622"></a><a name="p1679091709165622"></a>The suspension wait is interrupted by the signal. </p>
</td>
</tr>
</tbody>
</table>

## sigpending\(\)<a name="ga7b91eecad5998acd6162fde3ab530d7a"></a>

```
int sigpending (sigset_t * set)
```

 **Description:**

Obtains the signal suspended by the current thread. 

**Parameters:**

<a name="table2088943610165622"></a>
<table><thead align="left"><tr id="row487937240165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p392341269165622"><a name="p392341269165622"></a><a name="p392341269165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1727063516165622"><a name="p1727063516165622"></a><a name="p1727063516165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1916779173165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">set</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the signal set used to store the signal suspended by the current thread. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table1138269023165622"></a>
<table><thead align="left"><tr id="row667342655165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p457203944165622"><a name="p457203944165622"></a><a name="p457203944165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1831110579165622"><a name="p1831110579165622"></a><a name="p1831110579165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row373971540165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1965413656165622"><a name="p1965413656165622"></a><a name="p1965413656165622"></a>EFAULT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p506389230165622"><a name="p506389230165622"></a><a name="p506389230165622"></a><strong id="b1165523238165622"><a name="b1165523238165622"></a><a name="b1165523238165622"></a>set</strong> points to an invalid space. </p>
</td>
</tr>
<tr id="row185718303165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p586243919165622"><a name="p586243919165622"></a><a name="p586243919165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1922454571165622"><a name="p1922454571165622"></a><a name="p1922454571165622"></a><strong id="b1521841681165622"><a name="b1521841681165622"></a><a name="b1521841681165622"></a>set</strong> is <strong id="b997557146165622"><a name="b997557146165622"></a><a name="b997557146165622"></a>NULL</strong>. </p>
</td>
</tr>
<tr id="row1788734153165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1020992579165622"><a name="p1020992579165622"></a><a name="p1020992579165622"></a>EINTR </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p570569303165622"><a name="p570569303165622"></a><a name="p570569303165622"></a>The suspension wait is interrupted by the signal. </p>
</td>
</tr>
</tbody>
</table>

## sigprocmask\(\)<a name="gae11d1cbeb529d0050ab5600fe4b5fef9"></a>

```
int sigprocmask (int how, const sigset_t *__restrict set, sigset_t *__restrict oldset )
```

 **Description:**

Changes the signal mask of the calling thread. 

**Parameters:**

<a name="table710749002165622"></a>
<table><thead align="left"><tr id="row380630854165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p17981920165622"><a name="p17981920165622"></a><a name="p17981920165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2142397274165622"><a name="p2142397274165622"></a><a name="p2142397274165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1650760963165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">how</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the function behavior. </td>
</tr>
<tr id="row1210088649165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">set</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the signal set to be changed. </td>
</tr>
<tr id="row1376758942165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">oldset</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the original mask set of the calling thread. </td>
</tr>
</tbody>
</table>

<a name="table1253559729165622"></a>
<table><thead align="left"><tr id="row330376713165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p700492977165622"><a name="p700492977165622"></a><a name="p700492977165622"></a>flags </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2069631329165622"><a name="p2069631329165622"></a><a name="p2069631329165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row306947271165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1918187310165622"><a name="p1918187310165622"></a><a name="p1918187310165622"></a>SIG_BLOCK </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p661195917165622"><a name="p661195917165622"></a><a name="p661195917165622"></a>Adds the signals in <strong id="b1762818434165622"><a name="b1762818434165622"></a><a name="b1762818434165622"></a>set</strong> to the mask set of the thread. </p>
</td>
</tr>
<tr id="row1113161937165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1044806817165622"><a name="p1044806817165622"></a><a name="p1044806817165622"></a>SIG_UNBLOCK </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p453903569165622"><a name="p453903569165622"></a><a name="p453903569165622"></a>Removes the signals in <strong id="b364057078165622"><a name="b364057078165622"></a><a name="b364057078165622"></a>set</strong> from the mask set of the thread. </p>
</td>
</tr>
<tr id="row1778321016165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p151672637165622"><a name="p151672637165622"></a><a name="p151672637165622"></a>SIG_SETMASK </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p326684257165622"><a name="p326684257165622"></a><a name="p326684257165622"></a>Sets <strong id="b132369234165622"><a name="b132369234165622"></a><a name="b132369234165622"></a>set</strong> of blocked signals as the mask set of the thread. </p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the change is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the change fails. 

<a name="table404808124165622"></a>
<table><thead align="left"><tr id="row1783575795165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p645306102165622"><a name="p645306102165622"></a><a name="p645306102165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p52264860165622"><a name="p52264860165622"></a><a name="p52264860165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1477682797165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1441835680165622"><a name="p1441835680165622"></a><a name="p1441835680165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1870331046165622"><a name="p1870331046165622"></a><a name="p1870331046165622"></a><strong id="b1066397251165622"><a name="b1066397251165622"></a><a name="b1066397251165622"></a>how</strong> is invalid. </p>
</td>
</tr>
<tr id="row1839103235165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1972644807165622"><a name="p1972644807165622"></a><a name="p1972644807165622"></a>EFAULT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1093817858165622"><a name="p1093817858165622"></a><a name="p1093817858165622"></a>The <strong id="b1201562540165622"><a name="b1201562540165622"></a><a name="b1201562540165622"></a>set</strong> or <strong id="b1776022293165622"><a name="b1776022293165622"></a><a name="b1776022293165622"></a>oldset</strong> points outside the process's allocated address space. </p>
</td>
</tr>
</tbody>
</table>

## sigrelse\(\)<a name="ga96c4aed60b8b727709887e1fae0f5bea"></a>

```
int sigrelse (int signum)
```

 **Description:**

Deletes the signal specified by  **signum**  from the signal mask of the calling process. 

**Parameters:**

<a name="table614095187165622"></a>
<table><thead align="left"><tr id="row1054782273165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1206743605165622"><a name="p1206743605165622"></a><a name="p1206743605165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p743090578165622"><a name="p743090578165622"></a><a name="p743090578165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row883767055165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">signum</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the signal to be deleted. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the deletion is successful; returns  **-1**  if the deletion fails. 

## sigsuspend\(\)<a name="gae5f92586ad50092a7813465eeef792c0"></a>

```
int sigsuspend (const sigset_t * mask)
```

 **Description:**

Sets  **mask**  as the signal mask set of the current process and suspends the process until a signal processing action is triggered. 

**Parameters:**

<a name="table1869068781165622"></a>
<table><thead align="left"><tr id="row940395508165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1261287014165622"><a name="p1261287014165622"></a><a name="p1261287014165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1608982275165622"><a name="p1608982275165622"></a><a name="p1608982275165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row779540418165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">mask</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the signal set to be set. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **-1**  and sets  **errno**  to a value in the following table. 

<a name="table1089673157165622"></a>
<table><thead align="left"><tr id="row118825380165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p954900421165622"><a name="p954900421165622"></a><a name="p954900421165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p612729343165622"><a name="p612729343165622"></a><a name="p612729343165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1444315759165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2147021610165622"><a name="p2147021610165622"></a><a name="p2147021610165622"></a>EFAULT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p204554407165622"><a name="p204554407165622"></a><a name="p204554407165622"></a><strong id="b887657384165622"><a name="b887657384165622"></a><a name="b887657384165622"></a>mask</strong> points to an invalid space. </p>
</td>
</tr>
<tr id="row1871674153165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p225815529165622"><a name="p225815529165622"></a><a name="p225815529165622"></a>EINTR </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1343898461165622"><a name="p1343898461165622"></a><a name="p1343898461165622"></a>The suspension wait is interrupted by the signal. </p>
</td>
</tr>
<tr id="row250437281165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1970467094165622"><a name="p1970467094165622"></a><a name="p1970467094165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p273541902165622"><a name="p273541902165622"></a><a name="p273541902165622"></a><strong id="b1926582864165622"><a name="b1926582864165622"></a><a name="b1926582864165622"></a>mask</strong> is <strong id="b196295302165622"><a name="b196295302165622"></a><a name="b196295302165622"></a>NULL</strong>. </p>
</td>
</tr>
</tbody>
</table>

## sigtimedwait\(\)<a name="ga155a526c3da5ffd1a79ba2925bdd278a"></a>

```
int sigtimedwait (const sigset_t *__restrict set, siginfo_t *__restrict info, const struct [timespec](timespec.md) *__restrict timeout )
```

 **Description:**

Suspends the calling thread and waits for the signal, with a timeout period specified. 

This function is used to suspend execution of the calling thread until one of the signals specified in the signal set becomes pending. This function specifies the timeout behavior. 

**Parameters:**

<a name="table1392498165165622"></a>
<table><thead align="left"><tr id="row1141071013165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p479376055165622"><a name="p479376055165622"></a><a name="p479376055165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p375198629165622"><a name="p375198629165622"></a><a name="p375198629165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row86747020165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">set</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the signal set to be waited. </td>
</tr>
<tr id="row1853358983165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">info</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Used to save the information about the waited signal if the value is not <strong id="b1255202803165622"><a name="b1255202803165622"></a><a name="b1255202803165622"></a>NULL</strong>. </td>
</tr>
<tr id="row815666666165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">timeout</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the timeout duration. </td>
</tr>
</tbody>
</table>

**Attention:**

The signal to be waited must be in the mask set of the current thread. Once the signal is received, it is deleted from the pending list. The waiting for the signal cannot be interrupted by other signals, that is,  **EINTR**  is not supported. 

**Returns:**

Returns the value of the waited signal if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table494930461165622"></a>
<table><thead align="left"><tr id="row1827105823165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1066236825165622"><a name="p1066236825165622"></a><a name="p1066236825165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1800979382165622"><a name="p1800979382165622"></a><a name="p1800979382165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1749909642165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p323554705165622"><a name="p323554705165622"></a><a name="p323554705165622"></a>EFAULT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p157187388165622"><a name="p157187388165622"></a><a name="p157187388165622"></a><strong id="b1386273795165622"><a name="b1386273795165622"></a><a name="b1386273795165622"></a>set</strong> points to an invalid space. </p>
</td>
</tr>
<tr id="row1088904816165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p566055099165622"><a name="p566055099165622"></a><a name="p566055099165622"></a>EAGAIN </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p954210457165622"><a name="p954210457165622"></a><a name="p954210457165622"></a>No signal specified by <strong id="b706883686165622"><a name="b706883686165622"></a><a name="b706883686165622"></a>set</strong> is generated within the specified timeout period. </p>
</td>
</tr>
<tr id="row695240338165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p221967210165622"><a name="p221967210165622"></a><a name="p221967210165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p589492830165622"><a name="p589492830165622"></a><a name="p589492830165622"></a><strong id="b2044327155165622"><a name="b2044327155165622"></a><a name="b2044327155165622"></a>timeout</strong> is invalid. </p>
</td>
</tr>
</tbody>
</table>

## sigwait\(\)<a name="ga900d91a9635b965dbbae6b3cee2d2a2b"></a>

```
int sigwait (const sigset_t *__restrict set, int *__restrict sig )
```

 **Description:**

Suspends the calling thread and waits for the signal. 

This function is used to suspend execution of the calling thread until one of the signals specified in the signal set becomes pending. 

**Parameters:**

<a name="table326484016165622"></a>
<table><thead align="left"><tr id="row1066975538165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1746974242165622"><a name="p1746974242165622"></a><a name="p1746974242165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1182443988165622"><a name="p1182443988165622"></a><a name="p1182443988165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row345843952165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">set</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the signal set to be waited. </td>
</tr>
<tr id="row605537481165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sig</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Used for saving the waited signal. </td>
</tr>
</tbody>
</table>

**Attention:**

The signal to be waited must be in the mask set of the current thread. Once the signal is received, it is deleted from the pending list. 

**Returns:**

Returns  **0**  if the signal is received; returns  **-1**  and sets  **errno**  to a value in the following table if the signal fails to be received. 

<a name="table1127081489165622"></a>
<table><thead align="left"><tr id="row2092822395165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1529382468165622"><a name="p1529382468165622"></a><a name="p1529382468165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p33062251165622"><a name="p33062251165622"></a><a name="p33062251165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row583732264165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p278537211165622"><a name="p278537211165622"></a><a name="p278537211165622"></a>EINTR </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1068707390165622"><a name="p1068707390165622"></a><a name="p1068707390165622"></a>The suspension wait is interrupted by the signal. </p>
</td>
</tr>
</tbody>
</table>

## sigwaitinfo\(\)<a name="ga786f18a8e5b7eceed0ddcdc722f3340b"></a>

```
int sigwaitinfo (const sigset_t *__restrict set, siginfo_t *__restrict info )
```

 **Description:**

Suspends the calling thread and waits for the signal, with a timeout period specified. 

This function is used to suspend execution of the calling thread until one of the signals specified in the signal set becomes pending. This function does not specify the timeout behavior. 

**Parameters:**

<a name="table1918155055165622"></a>
<table><thead align="left"><tr id="row88972476165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1945032448165622"><a name="p1945032448165622"></a><a name="p1945032448165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1674428871165622"><a name="p1674428871165622"></a><a name="p1674428871165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row24438078165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">set</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the signal set to be waited. </td>
</tr>
<tr id="row701868829165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">info</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Used to save the information about the waited signal if the value is not <strong id="b385825980165622"><a name="b385825980165622"></a><a name="b385825980165622"></a>NULL</strong>. </td>
</tr>
</tbody>
</table>

**Attention:**

The signal to be waited must be in the mask set of the current thread. Once the signal is received, it is deleted from the pending list. The waiting for the signal cannot be interrupted by other signals, that is,  **EINTR**  is not supported. 

**Returns:**

Returns the value of the waited signal if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table739640056165622"></a>
<table><thead align="left"><tr id="row507026170165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1145432660165622"><a name="p1145432660165622"></a><a name="p1145432660165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1224549958165622"><a name="p1224549958165622"></a><a name="p1224549958165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1421939628165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1561626588165622"><a name="p1561626588165622"></a><a name="p1561626588165622"></a>EFAULT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1234200343165622"><a name="p1234200343165622"></a><a name="p1234200343165622"></a><strong id="b809706398165622"><a name="b809706398165622"></a><a name="b809706398165622"></a>set</strong> points to an invalid space. </p>
</td>
</tr>
</tbody>
</table>

