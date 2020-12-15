# glob.h<a name="EN-US_TOPIC_0000001055308033"></a>

-   [Overview](#section828651866165627)
-   [Summary](#section1427259795165627)
-   [Data Structures](#nested-classes)
-   [Macros](#define-members)
-   [Functions](#func-members)

## **Overview**<a name="section828651866165627"></a>

**Related Modules:**

[FS](fs.md)

**Description:**

Provides functions and structures used to find path names matching a pattern and release the memory that was applied for during the search. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1427259795165627"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table1837026937165627"></a>
<table><thead align="left"><tr id="row1325564810165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1346532589165627"><a name="p1346532589165627"></a><a name="p1346532589165627"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p615323987165627"><a name="p615323987165627"></a><a name="p615323987165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row317179984165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1717457260165627"><a name="p1717457260165627"></a><a name="p1717457260165627"></a><a href="glob_t.md">glob_t</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p795994371165627"><a name="p795994371165627"></a><a name="p795994371165627"></a>Defines the search information. </p>
</td>
</tr>
</tbody>
</table>

## Macros<a name="define-members"></a>

<a name="table1495392646165627"></a>
<table><thead align="left"><tr id="row1789474779165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1497592296165627"><a name="p1497592296165627"></a><a name="p1497592296165627"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1987696763165627"><a name="p1987696763165627"></a><a name="p1987696763165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row805803420165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p94656457165627"><a name="p94656457165627"></a><a name="p94656457165627"></a><a href="fs.md#ga9e77b0b20a1c1d66cdf924a07776f360">GLOB_ERR</a>   0x01</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1850346273165627"><a name="p1850346273165627"></a><a name="p1850346273165627"></a>Return upon a read error. </p>
</td>
</tr>
<tr id="row365702874165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p215187493165627"><a name="p215187493165627"></a><a name="p215187493165627"></a><a href="fs.md#gac6ec2b6ae844d895de9685a689dd27f0">GLOB_MARK</a>   0x02</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p966631946165627"><a name="p966631946165627"></a><a name="p966631946165627"></a>Append a slash (/) to each path, which corresponds to a directory. </p>
</td>
</tr>
<tr id="row797205119165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1382177303165627"><a name="p1382177303165627"></a><a name="p1382177303165627"></a><a href="fs.md#ga4eba6cedebdfe13f924d9b4a489bfe83">GLOB_NOSORT</a>   0x04</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1212867169165627"><a name="p1212867169165627"></a><a name="p1212867169165627"></a>Do not sort the returned path names. </p>
</td>
</tr>
<tr id="row2025761224165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p900573243165627"><a name="p900573243165627"></a><a name="p900573243165627"></a><a href="fs.md#ga8ae13e97ae5da0993fe526c406337c62">GLOB_DOOFFS</a>   0x08</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p722215885165627"><a name="p722215885165627"></a><a name="p722215885165627"></a>In the <strong id="b779532989165627"><a name="b779532989165627"></a><a name="b779532989165627"></a>pglob</strong> parameter of the <a href="fs.md#gae98601409da7fd3c85a9c219e1a9020c">glob()</a> function, reserve a string that has a length of <strong id="b1546541901165627"><a name="b1546541901165627"></a><a name="b1546541901165627"></a>pglob-&gt;gl_offs</strong> and ends with <strong id="b64251786165627"><a name="b64251786165627"></a><a name="b64251786165627"></a>\0</strong> at the beginning of the string list in <strong id="b693671236165627"><a name="b693671236165627"></a><a name="b693671236165627"></a>pglob-&gt;pathv</strong>. That is, the newly matched string is appended to a position where the distance from the beginning of <strong id="b643045769165627"><a name="b643045769165627"></a><a name="b643045769165627"></a>pglob-&gt;pathv</strong> is the length of <strong id="b551085879165627"><a name="b551085879165627"></a><a name="b551085879165627"></a>pglob-&gt;gl_offs</strong>. </p>
</td>
</tr>
<tr id="row1520919379165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p833073786165627"><a name="p833073786165627"></a><a name="p833073786165627"></a><a href="fs.md#gaf183b2f40936442579be8d62b87e6fc6">GLOB_NOCHECK</a>   0x10</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1136794740165627"><a name="p1136794740165627"></a><a name="p1136794740165627"></a>If no pattern matches, return the original pattern. </p>
</td>
</tr>
<tr id="row1556451085165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1608576260165627"><a name="p1608576260165627"></a><a name="p1608576260165627"></a><a href="fs.md#ga7e586df07bb159e904a61d8470f1fda2">GLOB_APPEND</a>   0x20</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p259740246165627"><a name="p259740246165627"></a><a name="p259740246165627"></a>Append the results of this call to the results returned by a previous call to <strong id="b750157707165627"><a name="b750157707165627"></a><a name="b750157707165627"></a><a href="fs.md#gae98601409da7fd3c85a9c219e1a9020c">glob()</a></strong>. </p>
</td>
</tr>
<tr id="row1160765051165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1893405186165627"><a name="p1893405186165627"></a><a name="p1893405186165627"></a><a href="fs.md#gad21c37825788f86d5fefea803276f746">GLOB_NOESCAPE</a>   0x40</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1282124975165627"><a name="p1282124975165627"></a><a name="p1282124975165627"></a>Do not use a backslash () as an escape character. </p>
</td>
</tr>
<tr id="row1811699145165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1140780841165627"><a name="p1140780841165627"></a><a name="p1140780841165627"></a><a href="fs.md#gab548aece9c1254c6c08475ce8c6274a2">GLOB_PERIOD</a>   0x80</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1594457172165627"><a name="p1594457172165627"></a><a name="p1594457172165627"></a>Allow a leading period to be matched by metacharacters. </p>
</td>
</tr>
<tr id="row380802291165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p65850047165627"><a name="p65850047165627"></a><a name="p65850047165627"></a><a href="fs.md#ga4f1c6c0dae8dfefcf3032fed1b5cd0fe">GLOB_TILDE</a>   0x1000</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p79304981165627"><a name="p79304981165627"></a><a name="p79304981165627"></a>Carry out tilde expansion. If a tilde (~) is the only character in the pattern, or an initial tilde is followed immediately by a slash (/), then the home directory of the caller is substituted for the tilde. </p>
</td>
</tr>
<tr id="row624406009165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p526139007165627"><a name="p526139007165627"></a><a name="p526139007165627"></a><a href="fs.md#gacf779f5283225f7a1507122f75418103">GLOB_TILDE_CHECK</a>   0x4000</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2132025267165627"><a name="p2132025267165627"></a><a name="p2132025267165627"></a>Similar to <a href="fs.md#ga4f1c6c0dae8dfefcf3032fed1b5cd0fe">GLOB_TILDE</a>. The difference is that if the username is invalid, or the home directory cannot be determined, <a href="fs.md#gae98601409da7fd3c85a9c219e1a9020c">glob()</a> returns <a href="fs.md#gaed760cf90fd4398067cdb679ebe60312">GLOB_NOMATCH</a> to indicate an error. </p>
</td>
</tr>
<tr id="row396011982165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2116269362165627"><a name="p2116269362165627"></a><a name="p2116269362165627"></a><a href="fs.md#gab53de39e075e6fb9a11678341772930b">GLOB_NOSPACE</a>   1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1454859042165627"><a name="p1454859042165627"></a><a name="p1454859042165627"></a>Memory insufficient. </p>
</td>
</tr>
<tr id="row736178755165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p5393097165627"><a name="p5393097165627"></a><a name="p5393097165627"></a><a href="fs.md#gab5de50cedafa21283878657d05fb2ba8">GLOB_ABORTED</a>   2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1409374314165627"><a name="p1409374314165627"></a><a name="p1409374314165627"></a>Read error. </p>
</td>
</tr>
<tr id="row957982308165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p608790093165627"><a name="p608790093165627"></a><a name="p608790093165627"></a><a href="fs.md#gaed760cf90fd4398067cdb679ebe60312">GLOB_NOMATCH</a>   3</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1657102875165627"><a name="p1657102875165627"></a><a name="p1657102875165627"></a>No matching item is found. </p>
</td>
</tr>
<tr id="row2077124248165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p416519782165627"><a name="p416519782165627"></a><a name="p416519782165627"></a><a href="fs.md#ga121ff4729e5e2d403808f90e6a47a113">GLOB_NOSYS</a>   4</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1240828377165627"><a name="p1240828377165627"></a><a name="p1240828377165627"></a>The function is not supported. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table181966103165627"></a>
<table><thead align="left"><tr id="row1761933885165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p404894414165627"><a name="p404894414165627"></a><a name="p404894414165627"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p654694851165627"><a name="p654694851165627"></a><a name="p654694851165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1042039963165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1490319709165627"><a name="p1490319709165627"></a><a name="p1490319709165627"></a><a href="fs.md#gae98601409da7fd3c85a9c219e1a9020c">glob</a> (const char *__restrict pattern, int flags, int(*errfunc)(const char *, int), <a href="glob_t.md">glob_t</a> *__restrict pglob)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1287096829165627"><a name="p1287096829165627"></a><a name="p1287096829165627"></a>int </p>
<p id="p1854157058165627"><a name="p1854157058165627"></a><a name="p1854157058165627"></a>Searches for path names that meet a specified pattern. </p>
</td>
</tr>
<tr id="row148761266165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1204980100165627"><a name="p1204980100165627"></a><a name="p1204980100165627"></a><a href="fs.md#gaa43d417234c8572d6e98fb1dc12a4794">globfree</a> (<a href="glob_t.md">glob_t</a> *pglob)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p123984747165627"><a name="p123984747165627"></a><a name="p123984747165627"></a>void </p>
<p id="p515846000165627"><a name="p515846000165627"></a><a name="p515846000165627"></a>Frees allocated memory from a call to <strong id="b1265237455165627"><a name="b1265237455165627"></a><a name="b1265237455165627"></a><a href="fs.md#gae98601409da7fd3c85a9c219e1a9020c">glob()</a></strong>. </p>
</td>
</tr>
</tbody>
</table>

