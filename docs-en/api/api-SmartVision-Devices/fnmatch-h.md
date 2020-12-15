# fnmatch.h<a name="EN-US_TOPIC_0000001055108021"></a>

-   [Overview](#section1458673508165627)
-   [Summary](#section455879264165627)
-   [Macros](#define-members)
-   [Functions](#func-members)

## **Overview**<a name="section1458673508165627"></a>

**Related Modules:**

[UTILS](utils.md)

**Description:**

Provides a function for checking whether a specified string matches a string that contains wildcards. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section455879264165627"></a>

## Macros<a name="define-members"></a>

<a name="table386731724165627"></a>
<table><thead align="left"><tr id="row1434554439165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p133074456165627"><a name="p133074456165627"></a><a name="p133074456165627"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1320155262165627"><a name="p1320155262165627"></a><a name="p1320155262165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row834463347165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p746618906165627"><a name="p746618906165627"></a><a name="p746618906165627"></a><a href="utils.md#gaed9e649990b20ba86e1aa7cacdc1bafe">FNM_PATHNAME</a>   0x1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1410815241165627"><a name="p1410815241165627"></a><a name="p1410815241165627"></a>If this flag is set, a slash (/) in <strong id="b977109022165627"><a name="b977109022165627"></a><a name="b977109022165627"></a>string</strong> can be matched by a slash (/) in <strong id="b1902471066165627"><a name="b1902471066165627"></a><a name="b1902471066165627"></a>pattern</strong>, but not by an asterisk (*), or a question mark (?), or a bracket expression ([]) containing a slash. </p>
</td>
</tr>
<tr id="row1146542593165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1210839888165627"><a name="p1210839888165627"></a><a name="p1210839888165627"></a><a href="utils.md#ga0c050a8a7551c2ca86560396de3d20d0">FNM_NOESCAPE</a>   0x2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p404425274165627"><a name="p404425274165627"></a><a name="p404425274165627"></a>If this flag is set, the backslash () is treated as an ordinary character, instead of an escape character. </p>
</td>
</tr>
<tr id="row315630317165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p846706667165627"><a name="p846706667165627"></a><a name="p846706667165627"></a><a href="utils.md#gaab98fecc02c06d6379bfcf416d6d297e">FNM_PERIOD</a>   0x4</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p254787868165627"><a name="p254787868165627"></a><a name="p254787868165627"></a>If this flag is set, a leading period (.) in <strong id="b1971789932165627"><a name="b1971789932165627"></a><a name="b1971789932165627"></a>string</strong> can be exactly matched by the period (.) in <strong id="b1047500994165627"><a name="b1047500994165627"></a><a name="b1047500994165627"></a>pattern</strong>. A period is considered to be leading if it is the first character in <strong id="b857246377165627"><a name="b857246377165627"></a><a name="b857246377165627"></a>string</strong>, or if both <strong id="b1948797730165627"><a name="b1948797730165627"></a><a name="b1948797730165627"></a>FNM_PATHNAME</strong> is set and the period immediately follows a slash. </p>
</td>
</tr>
<tr id="row2118334559165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1574271624165627"><a name="p1574271624165627"></a><a name="p1574271624165627"></a><a href="utils.md#ga94f8f78b6d024e35c971dd3ec057140c">FNM_LEADING_DIR</a>   0x8</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2081177760165627"><a name="p2081177760165627"></a><a name="p2081177760165627"></a>If this flag is set, a trailing sequence of characters starting with a slash (/) is ignored in <strong id="b210879801165627"><a name="b210879801165627"></a><a name="b210879801165627"></a>string</strong>. For example, if this flag is set, either <strong id="b1421219573165627"><a name="b1421219573165627"></a><a name="b1421219573165627"></a>foo*</strong> or <strong id="b1924047187165627"><a name="b1924047187165627"></a><a name="b1924047187165627"></a>foobar</strong> as a pattern would match the string <strong id="b1405286169165627"><a name="b1405286169165627"></a><a name="b1405286169165627"></a>foobar/frobozz</strong>. </p>
</td>
</tr>
<tr id="row1227169257165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1378191739165627"><a name="p1378191739165627"></a><a name="p1378191739165627"></a><a href="utils.md#gad41e3158a654dd4dfdab19d97745698a">FNM_CASEFOLD</a>   0x10</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2074845888165627"><a name="p2074845888165627"></a><a name="p2074845888165627"></a>If this flag is set, the pattern is matched case-insensitively. </p>
</td>
</tr>
<tr id="row886279641165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1453204374165627"><a name="p1453204374165627"></a><a name="p1453204374165627"></a><a href="utils.md#gad4df04c067e436af77a11440afbded0f">FNM_FILE_NAME</a>   <a href="utils.md#gaed9e649990b20ba86e1aa7cacdc1bafe">FNM_PATHNAME</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1222701309165627"><a name="p1222701309165627"></a><a name="p1222701309165627"></a>The definition is similar to that of <a href="utils.md#gaed9e649990b20ba86e1aa7cacdc1bafe">FNM_PATHNAME</a>. </p>
</td>
</tr>
<tr id="row1738756205165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p628510694165627"><a name="p628510694165627"></a><a name="p628510694165627"></a><a href="utils.md#gaf2661230e0cfc9970d6cdbe01571e753">FNM_NOMATCH</a>   1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1646039483165627"><a name="p1646039483165627"></a><a name="p1646039483165627"></a>The <strong id="b1149101786165627"><a name="b1149101786165627"></a><a name="b1149101786165627"></a>string</strong> parameter does not match the <strong id="b568475426165627"><a name="b568475426165627"></a><a name="b568475426165627"></a>pattern</strong> parameter. </p>
</td>
</tr>
<tr id="row839251533165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p444835681165627"><a name="p444835681165627"></a><a name="p444835681165627"></a><a href="utils.md#gabf296e95251824c90803dd3aa374190d">FNM_NOSYS</a>   (-1)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1150219826165627"><a name="p1150219826165627"></a><a name="p1150219826165627"></a>The function does not support the operation. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1112018681165627"></a>
<table><thead align="left"><tr id="row2114124178165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p955477042165627"><a name="p955477042165627"></a><a name="p955477042165627"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1888034082165627"><a name="p1888034082165627"></a><a name="p1888034082165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row124934684165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p795701840165627"><a name="p795701840165627"></a><a name="p795701840165627"></a><a href="utils.md#ga088b414f40eb0ce3dad9e5243816f68f">fnmatch</a> (const char *pattern, const char *string, int flags)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p869703331165627"><a name="p869703331165627"></a><a name="p869703331165627"></a>int </p>
<p id="p194423665165627"><a name="p194423665165627"></a><a name="p194423665165627"></a>Matches a file name or a path name. </p>
</td>
</tr>
</tbody>
</table>

