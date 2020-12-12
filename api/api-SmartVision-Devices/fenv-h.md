# fenv.h<a name="ZH-CN_TOPIC_0000001055189443"></a>

-   [Overview](#section792694826165627)
-   [Summary](#section154874694165627)
-   [Data Structures](#nested-classes)
-   [Macros](#define-members)
-   [Typedefs](#typedef-members)

## **Overview**<a name="section792694826165627"></a>

**Related Modules:**

[MATH](MATH.md)

**Description:**

Declares specific functions for performing operations for floating-point exceptions and rounding modes. 

You can use the functions provided in this file to set, clear, and store the current floating-point exception and to obtain and set the current rounding mode. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section154874694165627"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table1945632051165627"></a>
<table><thead align="left"><tr id="row333172877165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1940084251165627"><a name="p1940084251165627"></a><a name="p1940084251165627"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p827493708165627"><a name="p827493708165627"></a><a name="p827493708165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row40312745165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1073598406165627"><a name="p1073598406165627"></a><a name="p1073598406165627"></a><a href="fenv_t.md">fenv_t</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1157132706165627"><a name="p1157132706165627"></a><a name="p1157132706165627"></a>Defines the floating-point environment. </p>
</td>
</tr>
</tbody>
</table>

## Macros<a name="define-members"></a>

<a name="table1245443705165627"></a>
<table><thead align="left"><tr id="row205944817165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1914543461165627"><a name="p1914543461165627"></a><a name="p1914543461165627"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1816222497165627"><a name="p1816222497165627"></a><a name="p1816222497165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2110408939165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p554488034165627"><a name="p554488034165627"></a><a name="p554488034165627"></a><a href="MATH.md#ga638c8489adb1fac7204b07ece42998ae">FE_INVALID</a>   1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1392014161165627"><a name="p1392014161165627"></a><a name="p1392014161165627"></a>Indicates an invalid floating-point exception. At least one parameter value is not defined in the function. </p>
</td>
</tr>
<tr id="row996798516165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p684830717165627"><a name="p684830717165627"></a><a name="p684830717165627"></a><a href="MATH.md#gab1317930189d1a14841893fb4bd9b5a0">FE_DIVBYZERO</a>   2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1610573179165627"><a name="p1610573179165627"></a><a name="p1610573179165627"></a>Indicates a pole error exception. The return value is asymptotically infinite when the divisor is zero or the input is asymptotic to zero. </p>
</td>
</tr>
<tr id="row2072622928165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p320607115165627"><a name="p320607115165627"></a><a name="p320607115165627"></a><a href="MATH.md#gad373306add36e7227d9c9620b6962323">FE_OVERFLOW</a>   4</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2103994306165627"><a name="p2103994306165627"></a><a name="p2103994306165627"></a>Indicates an overflow floating-point exception. The result is too large to be represented in the normal return value. </p>
</td>
</tr>
<tr id="row1182875898165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1261753590165627"><a name="p1261753590165627"></a><a name="p1261753590165627"></a><a href="MATH.md#ga57b80dfe7d5ce60c3c76e517fce89ffe">FE_UNDERFLOW</a>   8</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p101441909165627"><a name="p101441909165627"></a><a name="p101441909165627"></a>Indicates an underflow floating-point exception. The result is too small to be represented in the normal return value. </p>
</td>
</tr>
<tr id="row487745431165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1970909963165627"><a name="p1970909963165627"></a><a name="p1970909963165627"></a><a href="MATH.md#ga6e24165ff28571734b3e14530219faab">FE_INEXACT</a>   16</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1797890878165627"><a name="p1797890878165627"></a><a name="p1797890878165627"></a>Indicates an inexact floating-point exception. </p>
</td>
</tr>
<tr id="row1973899181165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2016348710165627"><a name="p2016348710165627"></a><a name="p2016348710165627"></a><a href="MATH.md#ga09e405b3782b934813075e48366dda9a">FE_ALL_EXCEPT</a>   31</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1903189774165627"><a name="p1903189774165627"></a><a name="p1903189774165627"></a>Indicates bitwise OR of all the preceding supported floating-point exceptions. </p>
</td>
</tr>
<tr id="row624582147165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p772933851165627"><a name="p772933851165627"></a><a name="p772933851165627"></a><a href="MATH.md#ga5b5383719a63f98b7c95cc2feccaa1a7">FE_TONEAREST</a>   0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p867109956165627"><a name="p867109956165627"></a><a name="p867109956165627"></a>Indicates rounding towards the nearest integer. </p>
</td>
</tr>
<tr id="row2107971333165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p904140293165627"><a name="p904140293165627"></a><a name="p904140293165627"></a><a href="MATH.md#ga5e011a345a41ad4622da05932e83536f">FE_DOWNWARD</a>   0x800000</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2140027237165627"><a name="p2140027237165627"></a><a name="p2140027237165627"></a>Indicates rounding towards negative infinity. </p>
</td>
</tr>
<tr id="row1620003496165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p369702220165627"><a name="p369702220165627"></a><a name="p369702220165627"></a><a href="MATH.md#ga5aa71a164a4b4d7780570d97058890f1">FE_UPWARD</a>   0x400000</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2100948586165627"><a name="p2100948586165627"></a><a name="p2100948586165627"></a>Indicates rounding towards positive infinity. </p>
</td>
</tr>
<tr id="row930224226165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p287763778165627"><a name="p287763778165627"></a><a name="p287763778165627"></a><a href="MATH.md#gac171099e006285a9e8be5683be71591c">FE_TOWARDZERO</a>   0xc00000</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1966400248165627"><a name="p1966400248165627"></a><a name="p1966400248165627"></a>Indicates rounding towards zero. </p>
</td>
</tr>
<tr id="row814468734165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2123643320165627"><a name="p2123643320165627"></a><a name="p2123643320165627"></a><a href="MATH.md#ga5777a3689f7f4c555df1c643d28b5bc0">FE_DFL_ENV</a>   ((const <a href="fenv_t.md">fenv_t</a> *) -1)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1906353808165627"><a name="p1906353808165627"></a><a name="p1906353808165627"></a>Defines the default floating-point environment. </p>
</td>
</tr>
</tbody>
</table>

## Typedefs<a name="typedef-members"></a>

<a name="table479914861165627"></a>
<table><thead align="left"><tr id="row84387353165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1050196679165627"><a name="p1050196679165627"></a><a name="p1050196679165627"></a>Typedef Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p886106271165627"><a name="p886106271165627"></a><a name="p886106271165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row219045385165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1480104320165627"><a name="p1480104320165627"></a><a name="p1480104320165627"></a><a href="MATH.md#ga3eec78fdb9921de3f7254105f546c624">fexcept_t</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2147225507165627"><a name="p2147225507165627"></a><a name="p2147225507165627"></a> typedef unsigned long </p>
<p id="p253867955165627"><a name="p253867955165627"></a><a name="p253867955165627"></a>Floating-point exception type. </p>
</td>
</tr>
</tbody>
</table>

