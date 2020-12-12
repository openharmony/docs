# ctype.h<a name="EN-US_TOPIC_0000001054948031"></a>

-   [Overview](#section1070357859165626)
-   [Summary](#section385956529165626)
-   [Macros](#define-members)
-   [Functions](#func-members)

## **Overview**<a name="section1070357859165626"></a>

**Related Modules:**

[UTILS](utils.md)

**Description:**

Provides functions used for parameter identification. 

You can use the functions in this file to perform the mathematical operations required during development, for example, check whether the passed parameter is an alphabetic character, a blank character, not a number \(NaN\), a control character, or a decimal digit. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section385956529165626"></a>

## Macros<a name="define-members"></a>

<a name="table293742759165626"></a>
<table><thead align="left"><tr id="row636648207165626"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p374063164165626"><a name="p374063164165626"></a><a name="p374063164165626"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1273244140165626"><a name="p1273244140165626"></a><a name="p1273244140165626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1414175885165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p252210134165626"><a name="p252210134165626"></a><a name="p252210134165626"></a><a href="utils.md#ga803da2fa3d4650c493068eb474e5e874">_tolower</a>(a)   ((a)|0x20)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1344356579165626"><a name="p1344356579165626"></a><a name="p1344356579165626"></a>Converts an uppercase letter to its lowercase equivalent. </p>
</td>
</tr>
<tr id="row1862763163165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1573694292165626"><a name="p1573694292165626"></a><a name="p1573694292165626"></a><a href="utils.md#ga2a220adaae919f631f86e4ee91667ac2">_toupper</a>(a)   ((a)&amp;0x5f)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1247717553165626"><a name="p1247717553165626"></a><a name="p1247717553165626"></a>Converts a lowercase letter to its uppercase equivalent. </p>
</td>
</tr>
<tr id="row647856781165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1356181657165626"><a name="p1356181657165626"></a><a name="p1356181657165626"></a><a href="utils.md#ga325ce1f1d55d5b154a914a37b1094cf2">isascii</a>(a)   (0 ? isascii(a) : (unsigned)(a) &lt; 128)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1337844793165626"><a name="p1337844793165626"></a><a name="p1337844793165626"></a>Checks whether a parameter is an ASCII character. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1295111909165626"></a>
<table><thead align="left"><tr id="row1196679595165626"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1821558530165626"><a name="p1821558530165626"></a><a name="p1821558530165626"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p920357155165626"><a name="p920357155165626"></a><a name="p920357155165626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row589220891165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1517245009165626"><a name="p1517245009165626"></a><a name="p1517245009165626"></a><a href="utils.md#gadf38e126f73a010f30af76db2a28c6e1">isalnum</a> (int c)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1316239174165626"><a name="p1316239174165626"></a><a name="p1316239174165626"></a>int </p>
<p id="p148134245165626"><a name="p148134245165626"></a><a name="p148134245165626"></a>Checks whether a parameter is an alphabetic character or a decimal digit. </p>
</td>
</tr>
<tr id="row1291781630165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p531714169165626"><a name="p531714169165626"></a><a name="p531714169165626"></a><a href="utils.md#ga25908ae63aac2df990634e1ae5bd14d9">isalpha</a> (int c)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1411900532165626"><a name="p1411900532165626"></a><a name="p1411900532165626"></a>int </p>
<p id="p1891350172165626"><a name="p1891350172165626"></a><a name="p1891350172165626"></a>Checks whether a parameter is an alphabetic character. </p>
</td>
</tr>
<tr id="row690429006165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p991024124165626"><a name="p991024124165626"></a><a name="p991024124165626"></a><a href="utils.md#gaea4929b1b41f1a6d723e0312b1f050ed">isblank</a> (int c)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1818632929165626"><a name="p1818632929165626"></a><a name="p1818632929165626"></a>int </p>
<p id="p363629054165626"><a name="p363629054165626"></a><a name="p363629054165626"></a>Checks whether a parameter is a blank character (space or tap). </p>
</td>
</tr>
<tr id="row348844131165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p442371150165626"><a name="p442371150165626"></a><a name="p442371150165626"></a><a href="utils.md#ga0008a4e8e7889734dc1d83297de07158">iscntrl</a> (int c)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p559664718165626"><a name="p559664718165626"></a><a name="p559664718165626"></a>int </p>
<p id="p1582183479165626"><a name="p1582183479165626"></a><a name="p1582183479165626"></a>Checks whether a parameter is a control character. A control character is invisible and does not occupy a printing position on a display. </p>
</td>
</tr>
<tr id="row1905770407165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p784387475165626"><a name="p784387475165626"></a><a name="p784387475165626"></a><a href="utils.md#ga3fa45b35c8abf67a950b6d3d4063dede">isdigit</a> (int c)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p806310968165626"><a name="p806310968165626"></a><a name="p806310968165626"></a>int </p>
<p id="p273513592165626"><a name="p273513592165626"></a><a name="p273513592165626"></a>Checks whether a parameter is a decimal digit (0-9). </p>
</td>
</tr>
<tr id="row2000788800165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p884736546165626"><a name="p884736546165626"></a><a name="p884736546165626"></a><a href="utils.md#ga49f40fd869fd0c90e4497fda08c89561">isgraph</a> (int c)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1919485801165626"><a name="p1919485801165626"></a><a name="p1919485801165626"></a>int </p>
<p id="p1109561249165626"><a name="p1109561249165626"></a><a name="p1109561249165626"></a>Checks whether a parameter is any printable character except the space character. </p>
</td>
</tr>
<tr id="row1427452837165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p280726698165626"><a name="p280726698165626"></a><a name="p280726698165626"></a><a href="utils.md#ga7b8f652a0423a80922dd89d8829db5f2">islower</a> (int c)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1039484969165626"><a name="p1039484969165626"></a><a name="p1039484969165626"></a>int </p>
<p id="p1334546318165626"><a name="p1334546318165626"></a><a name="p1334546318165626"></a>Checks whether a parameter is a lowercase letter. </p>
</td>
</tr>
<tr id="row1633559832165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p762615363165626"><a name="p762615363165626"></a><a name="p762615363165626"></a><a href="utils.md#ga99355d8f0fb41ec43effb95189db0ed4">isprint</a> (int c)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1081042274165626"><a name="p1081042274165626"></a><a name="p1081042274165626"></a>int </p>
<p id="p1409980652165626"><a name="p1409980652165626"></a><a name="p1409980652165626"></a>Checks whether a parameter is a printable character (including space). </p>
</td>
</tr>
<tr id="row2018662729165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p422367616165626"><a name="p422367616165626"></a><a name="p422367616165626"></a><a href="utils.md#gaf29554b3ec04ea7684482bffed5dbce6">ispunct</a> (int c)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1101114453165626"><a name="p1101114453165626"></a><a name="p1101114453165626"></a>int </p>
<p id="p78488786165626"><a name="p78488786165626"></a><a name="p78488786165626"></a>Checks whether a parameter is a punctuation or special character. </p>
</td>
</tr>
<tr id="row69930623165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1693809900165626"><a name="p1693809900165626"></a><a name="p1693809900165626"></a><a href="utils.md#ga56be4166e4673843042a548a7f513dbc">isspace</a> (int c)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1455351341165626"><a name="p1455351341165626"></a><a name="p1455351341165626"></a>int </p>
<p id="p1768419999165626"><a name="p1768419999165626"></a><a name="p1768419999165626"></a>Checks whether a parameter is a space character. </p>
</td>
</tr>
<tr id="row1435698575165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2053049193165626"><a name="p2053049193165626"></a><a name="p2053049193165626"></a><a href="utils.md#gadadd6582d46775aab6a51e29d16d9f77">isupper</a> (int c)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1837578188165626"><a name="p1837578188165626"></a><a name="p1837578188165626"></a>int </p>
<p id="p1204570559165626"><a name="p1204570559165626"></a><a name="p1204570559165626"></a>Checks whether a parameter is an uppercase letter. </p>
</td>
</tr>
<tr id="row1838126626165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p777312151165626"><a name="p777312151165626"></a><a name="p777312151165626"></a><a href="utils.md#gadaf3aadefe3fc4fb07b6be0d7b880f53">isxdigit</a> (int c)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p905732543165626"><a name="p905732543165626"></a><a name="p905732543165626"></a>int </p>
<p id="p1639965863165626"><a name="p1639965863165626"></a><a name="p1639965863165626"></a>Checks whether a parameter is a hexadecimal digit. </p>
</td>
</tr>
<tr id="row588241208165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1911585722165626"><a name="p1911585722165626"></a><a name="p1911585722165626"></a><a href="utils.md#gac79d6114c9df7350cedcd8cf921a6ea4">tolower</a> (int c)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1336838824165626"><a name="p1336838824165626"></a><a name="p1336838824165626"></a>int </p>
<p id="p1551188300165626"><a name="p1551188300165626"></a><a name="p1551188300165626"></a>Converts an uppercase letter specified by <strong id="b381247879165626"><a name="b381247879165626"></a><a name="b381247879165626"></a>c</strong> to its lowercase equivalent. </p>
</td>
</tr>
<tr id="row1914803806165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p752062696165626"><a name="p752062696165626"></a><a name="p752062696165626"></a><a href="utils.md#ga9c2f57ac3865af9006fdbfd5db9fd517">toupper</a> (int c)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1208721350165626"><a name="p1208721350165626"></a><a name="p1208721350165626"></a>int </p>
<p id="p1963757508165626"><a name="p1963757508165626"></a><a name="p1963757508165626"></a>Converts a lowercase letter specified by <strong id="b680643142165626"><a name="b680643142165626"></a><a name="b680643142165626"></a>c</strong> to its uppercase equivalent. </p>
</td>
</tr>
<tr id="row1772946921165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1462722321165626"><a name="p1462722321165626"></a><a name="p1462722321165626"></a><a href="utils.md#gad87736859769a262b411b49819bc7a25">isalnum_l</a> (int c, locale_t locale)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1484224075165626"><a name="p1484224075165626"></a><a name="p1484224075165626"></a>int </p>
<p id="p1024231164165626"><a name="p1024231164165626"></a><a name="p1024231164165626"></a>Checks whether a parameter is an alphabetic character or digit for the specified locale. </p>
</td>
</tr>
<tr id="row1676805223165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p315424238165626"><a name="p315424238165626"></a><a name="p315424238165626"></a><a href="utils.md#ga6de33cb463fb34283dc5c7c4c230aec4">isalpha_l</a> (int c, locale_t locale)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p130425786165626"><a name="p130425786165626"></a><a name="p130425786165626"></a>int </p>
<p id="p2132619967165626"><a name="p2132619967165626"></a><a name="p2132619967165626"></a>Checks whether a parameter is an alphabetic character for the specified locale. </p>
</td>
</tr>
<tr id="row528618866165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1931840872165626"><a name="p1931840872165626"></a><a name="p1931840872165626"></a><a href="utils.md#ga650853c2fb9fcf2e9c34ac06e1f6f2d6">isblank_l</a> (int c, locale_t locale)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p989658841165626"><a name="p989658841165626"></a><a name="p989658841165626"></a>int </p>
<p id="p1823894501165626"><a name="p1823894501165626"></a><a name="p1823894501165626"></a>Checks whether a parameter is a blank character (including spaces and tabs) for the specified locale. </p>
</td>
</tr>
<tr id="row2084008036165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p298882629165626"><a name="p298882629165626"></a><a name="p298882629165626"></a><a href="utils.md#gad475d7607e183036b0add584bdf61b35">iscntrl_l</a> (int c, locale_t locale)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p456736748165626"><a name="p456736748165626"></a><a name="p456736748165626"></a>int </p>
<p id="p1611980442165626"><a name="p1611980442165626"></a><a name="p1611980442165626"></a>Checks whether a parameter is a control character for the specified locale. </p>
</td>
</tr>
<tr id="row1056907173165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1805049846165626"><a name="p1805049846165626"></a><a name="p1805049846165626"></a><a href="utils.md#ga378e9ee0e69cbbb9ed948598f9aa920d">isdigit_l</a> (int c, locale_t locale)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p984278515165626"><a name="p984278515165626"></a><a name="p984278515165626"></a>int </p>
<p id="p1122210796165626"><a name="p1122210796165626"></a><a name="p1122210796165626"></a>Checks whether a parameter is a decimal digit for the specified locale. </p>
</td>
</tr>
<tr id="row455827485165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p914785055165626"><a name="p914785055165626"></a><a name="p914785055165626"></a><a href="utils.md#gaab3732d493eec8b0c0a720d90dba210c">isgraph_l</a> (int c, locale_t locale)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1668339808165626"><a name="p1668339808165626"></a><a name="p1668339808165626"></a>int </p>
<p id="p260905492165626"><a name="p260905492165626"></a><a name="p260905492165626"></a>Checks whether a parameter is any printable character except the space character for the specified locale. </p>
</td>
</tr>
<tr id="row1273535600165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p626140424165626"><a name="p626140424165626"></a><a name="p626140424165626"></a><a href="utils.md#gad7c9319bbe71c048505cd30da34334ea">islower_l</a> (int c, locale_t locale)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p386696764165626"><a name="p386696764165626"></a><a name="p386696764165626"></a>int </p>
<p id="p1316380940165626"><a name="p1316380940165626"></a><a name="p1316380940165626"></a>Checks whether a parameter is a character of lowercase letters for the specified locale. </p>
</td>
</tr>
<tr id="row1534089100165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p261185628165626"><a name="p261185628165626"></a><a name="p261185628165626"></a><a href="utils.md#gaaae36b62a22be9fa67640255ae77ee0d">isprint_l</a> (int c, locale_t locale)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2011572925165626"><a name="p2011572925165626"></a><a name="p2011572925165626"></a>int </p>
<p id="p1370142641165626"><a name="p1370142641165626"></a><a name="p1370142641165626"></a>Checks whether a parameter is a printable character (including space) for the specified locale. A printable character is visible and occupies a printing position on a display. </p>
</td>
</tr>
<tr id="row1678137259165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p770849899165626"><a name="p770849899165626"></a><a name="p770849899165626"></a><a href="utils.md#gaa04b7d22f0c24a9aa5a6f12e933405f8">ispunct_l</a> (int c, locale_t locale)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1049156007165626"><a name="p1049156007165626"></a><a name="p1049156007165626"></a>int </p>
<p id="p1860600408165626"><a name="p1860600408165626"></a><a name="p1860600408165626"></a>Checks whether a parameter is a punctuation or special character for the specified locale. </p>
</td>
</tr>
<tr id="row1238073099165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1550171776165626"><a name="p1550171776165626"></a><a name="p1550171776165626"></a><a href="utils.md#ga6a6e04048d6363a76a333d17cac62f8a">isspace_l</a> (int c, locale_t locale)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1189046420165626"><a name="p1189046420165626"></a><a name="p1189046420165626"></a>int </p>
<p id="p619544562165626"><a name="p619544562165626"></a><a name="p619544562165626"></a>Checks whether a parameter is a blank character for the specified locale. </p>
</td>
</tr>
<tr id="row829424968165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1182866603165626"><a name="p1182866603165626"></a><a name="p1182866603165626"></a><a href="utils.md#gae10ce576a584fe302d364196d48332c6">isupper_l</a> (int c, locale_t locale)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1064266694165626"><a name="p1064266694165626"></a><a name="p1064266694165626"></a>int </p>
<p id="p1732827716165626"><a name="p1732827716165626"></a><a name="p1732827716165626"></a>Checks whether a parameter is a character of uppercase letters for the specified locale. </p>
</td>
</tr>
<tr id="row1530939091165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2041609118165626"><a name="p2041609118165626"></a><a name="p2041609118165626"></a><a href="utils.md#ga21c1d42504e331cf330026dcb47dcbe2">isxdigit_l</a> (int c, locale_t locale)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1427236093165626"><a name="p1427236093165626"></a><a name="p1427236093165626"></a>int </p>
<p id="p88622605165626"><a name="p88622605165626"></a><a name="p88622605165626"></a>Checks whether a parameter is a hexadecimal digit for the specified locale. </p>
</td>
</tr>
<tr id="row1608556533165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p497576519165626"><a name="p497576519165626"></a><a name="p497576519165626"></a><a href="utils.md#ga1921ca31e425387ecff9c9c7657cd4b7">tolower_l</a> (int c, locale_t locale)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p682900063165626"><a name="p682900063165626"></a><a name="p682900063165626"></a>int </p>
<p id="p572033032165626"><a name="p572033032165626"></a><a name="p572033032165626"></a>Converts an upper letter specified by <strong id="b326381378165626"><a name="b326381378165626"></a><a name="b326381378165626"></a>c</strong> to its lowercase equivalent for the specified locale. </p>
</td>
</tr>
<tr id="row1546675072165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p673071257165626"><a name="p673071257165626"></a><a name="p673071257165626"></a><a href="utils.md#ga77ed6ccc1ae9841df0fc54ad62860715">toupper_l</a> (int c, locale_t locale)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1501799940165626"><a name="p1501799940165626"></a><a name="p1501799940165626"></a>int </p>
<p id="p185523859165626"><a name="p185523859165626"></a><a name="p185523859165626"></a>Converts a lowercase letter specified by <strong id="b708957495165626"><a name="b708957495165626"></a><a name="b708957495165626"></a>c</strong> to its uppercase equivalent for the specified locale. </p>
</td>
</tr>
<tr id="row17720036165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1867347953165626"><a name="p1867347953165626"></a><a name="p1867347953165626"></a><a href="utils.md#gae2edadcc847fa6a98adc9c485da806de">toascii</a> (int c)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1905588937165626"><a name="p1905588937165626"></a><a name="p1905588937165626"></a>int </p>
<p id="p546470392165626"><a name="p546470392165626"></a><a name="p546470392165626"></a>Converts a parameter of the integer type to an ASCII code. </p>
</td>
</tr>
</tbody>
</table>

