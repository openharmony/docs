# string.h<a name="ZH-CN_TOPIC_0000001054748013"></a>

-   [Overview](#section1515866369165629)
-   [Summary](#section432837237165629)
-   [Macros](#define-members)
-   [Functions](#func-members)

## **Overview**<a name="section1515866369165629"></a>

**Related Modules:**

[UTILS](UTILS.md)

**Description:**

Declares commonly used functions for string operations. 

You can use the functions provided in this file to perform the mathematical operations required during development. The operations include copying, searching for, locating, and appending a string, as well as comparing two strings. You must pay attention to memory management during function calls. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section432837237165629"></a>

## Macros<a name="define-members"></a>

<a name="table2130635429165629"></a>
<table><thead align="left"><tr id="row1911745680165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1905860701165629"><a name="p1905860701165629"></a><a name="p1905860701165629"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1089655047165629"><a name="p1089655047165629"></a><a name="p1089655047165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row424002273165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p991438012165629"><a name="p991438012165629"></a><a name="p991438012165629"></a><a href="UTILS.md#ga6dfceaa174558eaee80a23cb09139dfd">strdupa</a>(x)   <a href="UTILS.md#ga7a82515b5d377be04817715c5465b647">strcpy</a>(alloca(<a href="UTILS.md#gaa383452fe445bfae989358c9d7d96f4f">strlen</a>(x)+1),x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1649415956165629"><a name="p1649415956165629"></a><a name="p1649415956165629"></a>Copies a string to a new position. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1148291325165629"></a>
<table><thead align="left"><tr id="row1670661524165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1727377724165629"><a name="p1727377724165629"></a><a name="p1727377724165629"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1691631844165629"><a name="p1691631844165629"></a><a name="p1691631844165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row608295796165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1451975384165629"><a name="p1451975384165629"></a><a name="p1451975384165629"></a><a href="UTILS.md#ga0ee37e291991bef6e3f4b49a970171e7">memcpy</a> (void *__restrict dest, const void *__restrict src, size_t n)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p823720258165629"><a name="p823720258165629"></a><a name="p823720258165629"></a>void * </p>
<p id="p1150067117165629"><a name="p1150067117165629"></a><a name="p1150067117165629"></a>Copies a string (overlapping not allowed). </p>
</td>
</tr>
<tr id="row1389431082165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p224794956165629"><a name="p224794956165629"></a><a name="p224794956165629"></a><a href="UTILS.md#ga802c986820d3866639922b6bc9484f90">memmove</a> (void *dest, const void *src, size_t n)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p164073539165629"><a name="p164073539165629"></a><a name="p164073539165629"></a>void * </p>
<p id="p2049735558165629"><a name="p2049735558165629"></a><a name="p2049735558165629"></a>Copies a string (overlapping allowed). </p>
</td>
</tr>
<tr id="row867883235165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p862023291165629"><a name="p862023291165629"></a><a name="p862023291165629"></a><a href="UTILS.md#gace6ee45c30e71865e6eb635200379db9">memset</a> (void *s, int c, size_t n)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p631471247165629"><a name="p631471247165629"></a><a name="p631471247165629"></a>void * </p>
<p id="p1443856108165629"><a name="p1443856108165629"></a><a name="p1443856108165629"></a>Copies a character to the specified memory area. </p>
</td>
</tr>
<tr id="row667111730165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1175369463165629"><a name="p1175369463165629"></a><a name="p1175369463165629"></a><a href="UTILS.md#ga9e6df54ee04e18a3772335580e2ed872">memcmp</a> (const void *s1, const void *s2, size_t n)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p808866615165629"><a name="p808866615165629"></a><a name="p808866615165629"></a>int </p>
<p id="p156637444165629"><a name="p156637444165629"></a><a name="p156637444165629"></a>Compares two memory areas. </p>
</td>
</tr>
<tr id="row1431706364165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p31614191165629"><a name="p31614191165629"></a><a name="p31614191165629"></a><a href="UTILS.md#ga16d6b0bd660cc3f9910924c6b6f4af8e">memchr</a> (const void *s, int c, size_t n)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1970786376165629"><a name="p1970786376165629"></a><a name="p1970786376165629"></a>void * </p>
<p id="p1281894184165629"><a name="p1281894184165629"></a><a name="p1281894184165629"></a>Searches for a character in the specified memory area. </p>
</td>
</tr>
<tr id="row1282898588165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2126765781165629"><a name="p2126765781165629"></a><a name="p2126765781165629"></a><a href="UTILS.md#ga7a82515b5d377be04817715c5465b647">strcpy</a> (char *dest, const char *src)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1598453944165629"><a name="p1598453944165629"></a><a name="p1598453944165629"></a>char * </p>
<p id="p1941598728165629"><a name="p1941598728165629"></a><a name="p1941598728165629"></a>Copies a string. </p>
</td>
</tr>
<tr id="row1514232309165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p831484457165629"><a name="p831484457165629"></a><a name="p831484457165629"></a><a href="UTILS.md#ga47d54f24198df56da51078a6c540b9ed">strncpy</a> (char *dest, const char *src, size_t n)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p206714730165629"><a name="p206714730165629"></a><a name="p206714730165629"></a>char * </p>
<p id="p1130488936165629"><a name="p1130488936165629"></a><a name="p1130488936165629"></a>Copies <strong id="b28680031165629"><a name="b28680031165629"></a><a name="b28680031165629"></a>n</strong> characters of a string. </p>
</td>
</tr>
<tr id="row725903923165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1024719329165629"><a name="p1024719329165629"></a><a name="p1024719329165629"></a><a href="UTILS.md#gadb8723e585ed29f2370cddf90f6891bc">strcat</a> (char *dest, const char *src)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p781895274165629"><a name="p781895274165629"></a><a name="p781895274165629"></a>char * </p>
<p id="p1349106268165629"><a name="p1349106268165629"></a><a name="p1349106268165629"></a>Appends a string to another one. </p>
</td>
</tr>
<tr id="row1869664481165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p536255671165629"><a name="p536255671165629"></a><a name="p536255671165629"></a><a href="UTILS.md#ga0aee928c2844a269966e4832fd2255c5">strncat</a> (char *dest, const char *src, size_t n)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1077454572165629"><a name="p1077454572165629"></a><a name="p1077454572165629"></a>char * </p>
<p id="p835414181165629"><a name="p835414181165629"></a><a name="p835414181165629"></a>Appends the first <strong id="b860605098165629"><a name="b860605098165629"></a><a name="b860605098165629"></a>n</strong> bytes of a string to another one. </p>
</td>
</tr>
<tr id="row1039007198165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1506311146165629"><a name="p1506311146165629"></a><a name="p1506311146165629"></a><a href="UTILS.md#ga11bd144d7d44914099a3aeddf1c8567d">strcmp</a> (const char *s1, const char *s2)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p721030458165629"><a name="p721030458165629"></a><a name="p721030458165629"></a>int </p>
<p id="p1903495799165629"><a name="p1903495799165629"></a><a name="p1903495799165629"></a>Compares two strings by characters. </p>
</td>
</tr>
<tr id="row608589141165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p3851464165629"><a name="p3851464165629"></a><a name="p3851464165629"></a><a href="UTILS.md#ga07f4a84c11c106e95c32b6ab509346ef">strncmp</a> (const char *s1, const char *s2, size_t n)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p830429796165629"><a name="p830429796165629"></a><a name="p830429796165629"></a>int </p>
<p id="p961737338165629"><a name="p961737338165629"></a><a name="p961737338165629"></a>Compares the first n characters of two strings. </p>
</td>
</tr>
<tr id="row441861653165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p665985952165629"><a name="p665985952165629"></a><a name="p665985952165629"></a><a href="UTILS.md#gaa4718e50ed45c2275c5d85a121d68097">strcoll</a> (const char *s1, const char *s2)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p13169237165629"><a name="p13169237165629"></a><a name="p13169237165629"></a>int </p>
<p id="p1136480246165629"><a name="p1136480246165629"></a><a name="p1136480246165629"></a>Compares two strings by character for the program's current locale. </p>
</td>
</tr>
<tr id="row1651286324165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p140837152165629"><a name="p140837152165629"></a><a name="p140837152165629"></a><a href="UTILS.md#ga2294f2f1c4eaef870ef3d5d90e5cb36f">strcoll_l</a> (const char *s1, const char *s2, locale_t locale)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1972834017165629"><a name="p1972834017165629"></a><a name="p1972834017165629"></a>int </p>
<p id="p1346131061165629"><a name="p1346131061165629"></a><a name="p1346131061165629"></a>Compares two strings by character for the specified locale. </p>
</td>
</tr>
<tr id="row1298922405165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p110865905165629"><a name="p110865905165629"></a><a name="p110865905165629"></a><a href="UTILS.md#gadd1f1078b3303920c19fd68fcba3f908">strxfrm</a> (char *dest, const char *src, size_t n)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1964322353165629"><a name="p1964322353165629"></a><a name="p1964322353165629"></a>size_t </p>
<p id="p1762982290165629"><a name="p1762982290165629"></a><a name="p1762982290165629"></a>Converts the first n characters of the source string pointed to by <strong id="b896378269165629"><a name="b896378269165629"></a><a name="b896378269165629"></a>src</strong> based on the program's current locale specified by <a href="IO.md#gaab9cf7b1a206fb75e5884934c8d676db">LC_COLLATE</a>, and places them in the destination string pointed to by <strong id="b1826989181165629"><a name="b1826989181165629"></a><a name="b1826989181165629"></a>dest</strong>. </p>
</td>
</tr>
<tr id="row405914885165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p146759709165629"><a name="p146759709165629"></a><a name="p146759709165629"></a><a href="UTILS.md#ga12871ed234858ef0e363d2b8aa572fc1">strchr</a> (const char *s, int c)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p374112837165629"><a name="p374112837165629"></a><a name="p374112837165629"></a>char * </p>
<p id="p426247797165629"><a name="p426247797165629"></a><a name="p426247797165629"></a>Locates the first occurrence of a character in a string. </p>
</td>
</tr>
<tr id="row1498291227165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p599821161165629"><a name="p599821161165629"></a><a name="p599821161165629"></a><a href="UTILS.md#ga0c05a458deff028ef4d4e64059098db4">strrchr</a> (const char *s, int c)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1928362085165629"><a name="p1928362085165629"></a><a name="p1928362085165629"></a>char * </p>
<p id="p952817962165629"><a name="p952817962165629"></a><a name="p952817962165629"></a>Locates the last occurrence of a character in a string. </p>
</td>
</tr>
<tr id="row1578126144165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1413096546165629"><a name="p1413096546165629"></a><a name="p1413096546165629"></a><a href="UTILS.md#gaeb6c449e5d77477c057abf00eaaf88fe">strcspn</a> (const char *s, const char *reject)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p134428203165629"><a name="p134428203165629"></a><a name="p134428203165629"></a>size_t </p>
<p id="p1746555286165629"><a name="p1746555286165629"></a><a name="p1746555286165629"></a>Obtains the length of the initial segment of a string that contains characters not in reject. </p>
</td>
</tr>
<tr id="row766812288165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1809366335165629"><a name="p1809366335165629"></a><a name="p1809366335165629"></a><a href="UTILS.md#ga900a0edfa51f601d479244f7451cedd1">strspn</a> (const char *s, const char *<a href="NET.md#ga0807af5ac9dfc2a63624e8c3e0ae95ef">accept</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p550678582165629"><a name="p550678582165629"></a><a name="p550678582165629"></a>size_t </p>
<p id="p831609930165629"><a name="p831609930165629"></a><a name="p831609930165629"></a>Obtains the length of the initial segment of a string that contains characters in accept. </p>
</td>
</tr>
<tr id="row218960827165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p185231107165629"><a name="p185231107165629"></a><a name="p185231107165629"></a><a href="UTILS.md#ga119f23a5dcb4eb5f1c1eed3cbf5cb0ed">strpbrk</a> (const char *s, const char *<a href="NET.md#ga0807af5ac9dfc2a63624e8c3e0ae95ef">accept</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p824170041165629"><a name="p824170041165629"></a><a name="p824170041165629"></a>char * </p>
<p id="p1878860627165629"><a name="p1878860627165629"></a><a name="p1878860627165629"></a>Searches for any of a set of characters in a string. </p>
</td>
</tr>
<tr id="row1481070346165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p752311574165629"><a name="p752311574165629"></a><a name="p752311574165629"></a><a href="UTILS.md#ga4a710d86541afc6b7dafddcdb4b1c94f">strstr</a> (const char *haystack, const char *needle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p295805873165629"><a name="p295805873165629"></a><a name="p295805873165629"></a>char * </p>
<p id="p1093515804165629"><a name="p1093515804165629"></a><a name="p1093515804165629"></a>Searches for a needle string in its haystack string. </p>
</td>
</tr>
<tr id="row724338332165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p500719961165629"><a name="p500719961165629"></a><a name="p500719961165629"></a><a href="UTILS.md#ga8cb460f64c449f2a9b9b7a40569ce0fe">strtok</a> (char *str, const char *delim)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p167032337165629"><a name="p167032337165629"></a><a name="p167032337165629"></a>char * </p>
<p id="p1258602301165629"><a name="p1258602301165629"></a><a name="p1258602301165629"></a>Separates a string into a series of tokens separated by a delimiter. </p>
</td>
</tr>
<tr id="row1097995307165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p249979141165629"><a name="p249979141165629"></a><a name="p249979141165629"></a><a href="UTILS.md#gaa383452fe445bfae989358c9d7d96f4f">strlen</a> (const char *s)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1601779339165629"><a name="p1601779339165629"></a><a name="p1601779339165629"></a>size_t </p>
<p id="p291208740165629"><a name="p291208740165629"></a><a name="p291208740165629"></a>Calculates the length of a string. </p>
</td>
</tr>
<tr id="row1631570623165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1761938813165629"><a name="p1761938813165629"></a><a name="p1761938813165629"></a><a href="UTILS.md#gadd46ab98f32b76457852dbb872842bf2">strerror</a> (int errnum)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p383024766165629"><a name="p383024766165629"></a><a name="p383024766165629"></a>char * </p>
<p id="p187906639165629"><a name="p187906639165629"></a><a name="p187906639165629"></a>Obtains an error description string of the specified error code. </p>
</td>
</tr>
<tr id="row1385924670165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1425463073165629"><a name="p1425463073165629"></a><a name="p1425463073165629"></a><a href="UTILS.md#gab11d86a2a3af0a355cad2337c6f4e9f7">strtok_r</a> (char *str, const char *delim, char **saveptr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1108149143165629"><a name="p1108149143165629"></a><a name="p1108149143165629"></a>char * </p>
<p id="p1351816504165629"><a name="p1351816504165629"></a><a name="p1351816504165629"></a>Separates a string into a series of tokens separated by a delimiter, with the <strong id="b1952397647165629"><a name="b1952397647165629"></a><a name="b1952397647165629"></a>saveptr</strong> parameter specified. </p>
</td>
</tr>
<tr id="row1601505951165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1515249588165629"><a name="p1515249588165629"></a><a name="p1515249588165629"></a><a href="UTILS.md#ga8f7507e357cbd24048ae77e27e5d41d7">strerror_l</a> (int errnum, locale_t locale)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p7404054165629"><a name="p7404054165629"></a><a name="p7404054165629"></a>char * </p>
<p id="p1866846095165629"><a name="p1866846095165629"></a><a name="p1866846095165629"></a>Obtains an error description string of the specified error code for the specified locale. </p>
</td>
</tr>
<tr id="row240813387165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1704482224165629"><a name="p1704482224165629"></a><a name="p1704482224165629"></a><a href="UTILS.md#ga7253ba059153058c57952194237c6b55">strerror_r</a> (int errnum, char *buf, size_t buflen)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1751786492165629"><a name="p1751786492165629"></a><a name="p1751786492165629"></a>char * </p>
<p id="p490935466165629"><a name="p490935466165629"></a><a name="p490935466165629"></a>Obtains an error description string of the specified error code. </p>
</td>
</tr>
<tr id="row1579681040165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1602785083165629"><a name="p1602785083165629"></a><a name="p1602785083165629"></a><a href="UTILS.md#ga890dbcd7c456828c1b6ff714e405fcc1">stpcpy</a> (char *dest, const char *src)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p66712544165629"><a name="p66712544165629"></a><a name="p66712544165629"></a>char * </p>
<p id="p1636531390165629"><a name="p1636531390165629"></a><a name="p1636531390165629"></a>Copies a string. </p>
</td>
</tr>
<tr id="row1929440737165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1474730502165629"><a name="p1474730502165629"></a><a name="p1474730502165629"></a><a href="UTILS.md#ga217a70a69e2fc7727278516b7ad2fc26">stpncpy</a> (char *dest, const char *src, size_t n)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p771284723165629"><a name="p771284723165629"></a><a name="p771284723165629"></a>char * </p>
<p id="p1425357324165629"><a name="p1425357324165629"></a><a name="p1425357324165629"></a>Copies n characters of a string. </p>
</td>
</tr>
<tr id="row1585773497165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p783206602165629"><a name="p783206602165629"></a><a name="p783206602165629"></a><a href="UTILS.md#gafc92d2231e45d19988c7894aa2a07f0c">strnlen</a> (const char *s, size_t maxlen)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p449334737165629"><a name="p449334737165629"></a><a name="p449334737165629"></a>size_t </p>
<p id="p91048036165629"><a name="p91048036165629"></a><a name="p91048036165629"></a>Calculates the length of a string. </p>
</td>
</tr>
<tr id="row540157329165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1218877206165629"><a name="p1218877206165629"></a><a name="p1218877206165629"></a><a href="UTILS.md#gab1cc1a3ff560049e22576031c7c2345b">strdup</a> (const char *s)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p831689512165629"><a name="p831689512165629"></a><a name="p831689512165629"></a>char * </p>
<p id="p634977027165629"><a name="p634977027165629"></a><a name="p634977027165629"></a>Copies a string to a new position. </p>
</td>
</tr>
<tr id="row35284040165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1781241088165629"><a name="p1781241088165629"></a><a name="p1781241088165629"></a><a href="UTILS.md#ga8b860ba32fef12da8acd4507c059e509">strndup</a> (const char *s, size_t n)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1527705658165629"><a name="p1527705658165629"></a><a name="p1527705658165629"></a>char * </p>
<p id="p849475932165629"><a name="p849475932165629"></a><a name="p849475932165629"></a>Copies n characters of a string to a new position. </p>
</td>
</tr>
<tr id="row1737200029165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1688542037165629"><a name="p1688542037165629"></a><a name="p1688542037165629"></a><a href="UTILS.md#ga8f7c22bf1131bd6ffe6635e386fb4ebd">strsignal</a> (int sig)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1883008072165629"><a name="p1883008072165629"></a><a name="p1883008072165629"></a>char * </p>
<p id="p831102132165629"><a name="p831102132165629"></a><a name="p831102132165629"></a>Returns a string describing the signal number. </p>
</td>
</tr>
<tr id="row1119279199165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1833152260165629"><a name="p1833152260165629"></a><a name="p1833152260165629"></a><a href="UTILS.md#ga2ffbfe50042aaf5b987782dcd16ea1f0">memccpy</a> (void *__restrict dest, const void *__restrict src, int c, size_t n)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p570178111165629"><a name="p570178111165629"></a><a name="p570178111165629"></a>void * </p>
<p id="p1761743722165629"><a name="p1761743722165629"></a><a name="p1761743722165629"></a>Copies a memory area to another one. </p>
</td>
</tr>
<tr id="row2035278003165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p12251948165629"><a name="p12251948165629"></a><a name="p12251948165629"></a><a href="UTILS.md#ga93c766c6e86f4f79e7507c21f1794e15">strsep</a> (char **stringp, const char *delim)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1796235193165629"><a name="p1796235193165629"></a><a name="p1796235193165629"></a>char * </p>
<p id="p1520862055165629"><a name="p1520862055165629"></a><a name="p1520862055165629"></a>Separates a string into a series of tokens separated by a delimiter. </p>
</td>
</tr>
<tr id="row748529632165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p427395246165629"><a name="p427395246165629"></a><a name="p427395246165629"></a><a href="UTILS.md#ga0266462615f2f112003cdb591710d299">strlcat</a> (char *d, const char *s, size_t n)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p934521779165629"><a name="p934521779165629"></a><a name="p934521779165629"></a>size_t </p>
<p id="p2081656258165629"><a name="p2081656258165629"></a><a name="p2081656258165629"></a>Appends the first <strong id="b1294060319165629"><a name="b1294060319165629"></a><a name="b1294060319165629"></a>n</strong> bytes of a string to another one. </p>
</td>
</tr>
<tr id="row827122653165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p702213469165629"><a name="p702213469165629"></a><a name="p702213469165629"></a><a href="UTILS.md#ga50bd3317d65f3da7d180b8981e58c5a4">strlcpy</a> (char *d, const char *s, size_t n)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p722236950165629"><a name="p722236950165629"></a><a name="p722236950165629"></a>size_t </p>
<p id="p401179866165629"><a name="p401179866165629"></a><a name="p401179866165629"></a>Copies a string. </p>
</td>
</tr>
<tr id="row625544553165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1766931200165629"><a name="p1766931200165629"></a><a name="p1766931200165629"></a><a href="UTILS.md#ga1563a7059aabf95c0b588278e8bed575">strverscmp</a> (const char *s1, const char *s2)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1082061506165629"><a name="p1082061506165629"></a><a name="p1082061506165629"></a>int </p>
<p id="p943863353165629"><a name="p943863353165629"></a><a name="p943863353165629"></a>Compares strings of two versions (string 1 and string 2) and returns the comparison result. </p>
</td>
</tr>
<tr id="row1911050051165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1296378266165629"><a name="p1296378266165629"></a><a name="p1296378266165629"></a><a href="UTILS.md#gae9229017a4501f8d6a637b4498cfed2e">strcasestr</a> (const char *haystack, const char *needle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1381933591165629"><a name="p1381933591165629"></a><a name="p1381933591165629"></a>char * </p>
<p id="p1873645358165629"><a name="p1873645358165629"></a><a name="p1873645358165629"></a>Searches for a needle string in its haystack string and returns a pointer. </p>
</td>
</tr>
<tr id="row1786626789165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1534252469165629"><a name="p1534252469165629"></a><a name="p1534252469165629"></a><a href="UTILS.md#ga5f6423417e952f934be0a582d87b663a">memmem</a> (const void *haystack, size_t haystacklen, const void *needle, size_t needlelen)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p367143794165629"><a name="p367143794165629"></a><a name="p367143794165629"></a>void * </p>
<p id="p768441550165629"><a name="p768441550165629"></a><a name="p768441550165629"></a>Searches for a needle string in its haystack string. </p>
</td>
</tr>
<tr id="row553397453165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2099824071165629"><a name="p2099824071165629"></a><a name="p2099824071165629"></a><a href="UTILS.md#ga45623070e5e0b7008d44600a283ea2ee">memrchr</a> (const void *s, int c, size_t n)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1860554938165629"><a name="p1860554938165629"></a><a name="p1860554938165629"></a>void * </p>
<p id="p701632683165629"><a name="p701632683165629"></a><a name="p701632683165629"></a>Searches for a character in the specified memory area. </p>
</td>
</tr>
<tr id="row897136481165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1278015831165629"><a name="p1278015831165629"></a><a name="p1278015831165629"></a><a href="UTILS.md#ga7ac7c0f43132e3acf013e0c71a58cdc9">mempcpy</a> (void *dest, const void *src, size_t n)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p942824529165629"><a name="p942824529165629"></a><a name="p942824529165629"></a>void * </p>
<p id="p1525640848165629"><a name="p1525640848165629"></a><a name="p1525640848165629"></a>Copies a string (overlapping not allowed). </p>
</td>
</tr>
</tbody>
</table>

