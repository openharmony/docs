# getopt.h<a name="EN-US_TOPIC_0000001054948033"></a>

-   [Overview](#section240080464165627)
-   [Summary](#section396383330165627)
-   [Data Structures](#nested-classes)
-   [Functions](#func-members)

## **Overview**<a name="section240080464165627"></a>

**Related Modules:**

[UTILS](utils.md)

**Description:**

Provides functions and data structures, such as command-line argument parsing. 

You can use the functions provided in this file to perform operations related to wide character types during development, such as, command-line argument parsing. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section396383330165627"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table49943067165627"></a>
<table><thead align="left"><tr id="row2144923148165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1115813588165627"><a name="p1115813588165627"></a><a name="p1115813588165627"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p704671962165627"><a name="p704671962165627"></a><a name="p704671962165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1578851764165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1087991863165627"><a name="p1087991863165627"></a><a name="p1087991863165627"></a><a href="option.md">option</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p763327685165627"><a name="p763327685165627"></a><a name="p763327685165627"></a>Defines the command parsing option. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1911863488165627"></a>
<table><thead align="left"><tr id="row803449796165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1521781726165627"><a name="p1521781726165627"></a><a name="p1521781726165627"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1910106526165627"><a name="p1910106526165627"></a><a name="p1910106526165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1154829896165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p510123644165627"><a name="p510123644165627"></a><a name="p510123644165627"></a><a href="utils.md#ga3d26a6a51c3a1576b36c66798a64a3cf">getopt_long</a> (int argc, char *const *argv, const char *optstring, const struct <a href="option.md">option</a> *longopts, int *longindex)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1417843388165627"><a name="p1417843388165627"></a><a name="p1417843388165627"></a>int </p>
<p id="p192845766165627"><a name="p192845766165627"></a><a name="p192845766165627"></a>Parses the command-line arguments. </p>
</td>
</tr>
<tr id="row1501900761165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p784042592165627"><a name="p784042592165627"></a><a name="p784042592165627"></a><a href="utils.md#ga6606cd658b7339db0fab03d3454bd29c">getopt_long_only</a> (int argc, char *const *argv, const char *optstring, const struct <a href="option.md">option</a> *longopts, int *longindex)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1478065239165627"><a name="p1478065239165627"></a><a name="p1478065239165627"></a>int </p>
<p id="p1731393447165627"><a name="p1731393447165627"></a><a name="p1731393447165627"></a>Parses the command-line arguments. </p>
</td>
</tr>
</tbody>
</table>

