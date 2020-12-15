# wchar.h<a name="EN-US_TOPIC_0000001054748015"></a>

-   [Overview](#section46235498165630)
-   [Summary](#section2097880581165630)
-   [Functions](#func-members)

## **Overview**<a name="section46235498165630"></a>

**Related Modules:**

[UTILS](utils.md)

**Description:**

Declares commonly used functions related to wide characters. 

You can use functions provided in this file to perform operations such as reading, writing, comparing, concatenating, copying, and searching wide characters. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section2097880581165630"></a>

## Functions<a name="func-members"></a>

<a name="table659131578165630"></a>
<table><thead align="left"><tr id="row100599101165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1596003466165630"><a name="p1596003466165630"></a><a name="p1596003466165630"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1604452049165630"><a name="p1604452049165630"></a><a name="p1604452049165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row740530176165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1835076384165630"><a name="p1835076384165630"></a><a name="p1835076384165630"></a><a href="utils.md#gae6b223ed61020ed2abf0279af175b203">wcscpy</a> (wchar_t *dest, const wchar_t *src)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p258282460165630"><a name="p258282460165630"></a><a name="p258282460165630"></a>wchar_t * </p>
<p id="p822560084165630"><a name="p822560084165630"></a><a name="p822560084165630"></a>Copies the wide characters pointed to by <strong id="b1885076327165630"><a name="b1885076327165630"></a><a name="b1885076327165630"></a>src</strong> to the wide character array pointed to by <strong id="b413706094165630"><a name="b413706094165630"></a><a name="b413706094165630"></a>dest</strong>, including the terminating null character <strong id="b178396039165630"><a name="b178396039165630"></a><a name="b178396039165630"></a>'\0'</strong>. . </p>
</td>
</tr>
<tr id="row480895945165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p870820933165630"><a name="p870820933165630"></a><a name="p870820933165630"></a><a href="utils.md#gab1f03e735cf92afa01bef89682008c9b">wcsncpy</a> (wchar_t *dest, const wchar_t *src, size_t n)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1471749124165630"><a name="p1471749124165630"></a><a name="p1471749124165630"></a>wchar_t * </p>
<p id="p1996093989165630"><a name="p1996093989165630"></a><a name="p1996093989165630"></a>Copies the first <strong id="b191045118165630"><a name="b191045118165630"></a><a name="b191045118165630"></a>n</strong> wide characters pointed to by <strong id="b79455026165630"><a name="b79455026165630"></a><a name="b79455026165630"></a>src</strong> to the wide character array pointed to by <strong id="b558981621165630"><a name="b558981621165630"></a><a name="b558981621165630"></a>dest</strong>. </p>
</td>
</tr>
<tr id="row1146545979165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p829828484165630"><a name="p829828484165630"></a><a name="p829828484165630"></a><a href="utils.md#ga1fa2f722dd578b02ed196a74488f75f0">wcscat</a> (wchar_t *dest, const wchar_t *src)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1516562696165630"><a name="p1516562696165630"></a><a name="p1516562696165630"></a>wchar_t * </p>
<p id="p2016654568165630"><a name="p2016654568165630"></a><a name="p2016654568165630"></a>Appends a copy of the wide characters pointed to by <strong id="b453226239165630"><a name="b453226239165630"></a><a name="b453226239165630"></a>src</strong> to the end of the wide character array pointed to by <strong id="b564554053165630"><a name="b564554053165630"></a><a name="b564554053165630"></a>dest</strong> and adds a terminating null character <strong id="b1241045870165630"><a name="b1241045870165630"></a><a name="b1241045870165630"></a>'\0'</strong>. </p>
</td>
</tr>
<tr id="row1892350291165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p401787873165630"><a name="p401787873165630"></a><a name="p401787873165630"></a><a href="utils.md#ga8af5b08f466d2d6843f7ec250eddb41c">wcsncat</a> (wchar_t *dest, const wchar_t *src, size_t n)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1804493715165630"><a name="p1804493715165630"></a><a name="p1804493715165630"></a>wchar_t * </p>
<p id="p401134458165630"><a name="p401134458165630"></a><a name="p401134458165630"></a>Appends a copy of the first <strong id="b191999063165630"><a name="b191999063165630"></a><a name="b191999063165630"></a>n</strong> wide characters pointed to by <strong id="b663287757165630"><a name="b663287757165630"></a><a name="b663287757165630"></a>src</strong> to the end of the wide characters pointed to by <strong id="b1673883667165630"><a name="b1673883667165630"></a><a name="b1673883667165630"></a>dest</strong> and adds a terminating null character <strong id="b573547541165630"><a name="b573547541165630"></a><a name="b573547541165630"></a>'\0'</strong>. </p>
</td>
</tr>
<tr id="row621626404165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p6837801165630"><a name="p6837801165630"></a><a name="p6837801165630"></a><a href="utils.md#gab361438866831d03563fbb430c1514c5">wcscmp</a> (const wchar_t *s1, const wchar_t *s2)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1896838629165630"><a name="p1896838629165630"></a><a name="p1896838629165630"></a>int </p>
<p id="p1849776231165630"><a name="p1849776231165630"></a><a name="p1849776231165630"></a>Compares each character in the string pointed to by <strong id="b10212268165630"><a name="b10212268165630"></a><a name="b10212268165630"></a>s1</strong> with that in the string pointed to by <strong id="b58410849165630"><a name="b58410849165630"></a><a name="b58410849165630"></a>s2</strong> in ASCII-code order. </p>
</td>
</tr>
<tr id="row241332052165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p361411106165630"><a name="p361411106165630"></a><a name="p361411106165630"></a><a href="utils.md#ga422e6bb262f249f2d71b6a2d77408038">wcsncmp</a> (const wchar_t *s1, const wchar_t *s2, size_t n)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1670373980165630"><a name="p1670373980165630"></a><a name="p1670373980165630"></a>int </p>
<p id="p1040799059165630"><a name="p1040799059165630"></a><a name="p1040799059165630"></a>Compares the first <strong id="b1691542971165630"><a name="b1691542971165630"></a><a name="b1691542971165630"></a>n</strong> characters in the string pointed to by <strong id="b1823323348165630"><a name="b1823323348165630"></a><a name="b1823323348165630"></a>s1</strong> with those in the string pointed to by <strong id="b1354127383165630"><a name="b1354127383165630"></a><a name="b1354127383165630"></a>s2</strong> in ASCII-code order. </p>
</td>
</tr>
<tr id="row1892967501165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p564263276165630"><a name="p564263276165630"></a><a name="p564263276165630"></a><a href="utils.md#ga99ef4b8381c22d8db3b2b13d8c3a3c29">wcscoll</a> (const wchar_t *ws1, const wchar_t *ws2)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1959051990165630"><a name="p1959051990165630"></a><a name="p1959051990165630"></a>int </p>
<p id="p1738664750165630"><a name="p1738664750165630"></a><a name="p1738664750165630"></a>Compares the wide characters in the string pointed to by <strong id="b270380451165630"><a name="b270380451165630"></a><a name="b270380451165630"></a>ws1</strong> with those in the string pointed to by <strong id="b728495067165630"><a name="b728495067165630"></a><a name="b728495067165630"></a>ws2</strong> based on the specified locale <a href="io.md#gaab9cf7b1a206fb75e5884934c8d676db">LC_COLLATE</a>. </p>
</td>
</tr>
<tr id="row198218344165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1910597213165630"><a name="p1910597213165630"></a><a name="p1910597213165630"></a><a href="utils.md#ga3a0974b661a750f99ec204adf0921baf">wcsxfrm</a> (wchar_t *s1, const wchar_t *s2, size_t n)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p234075907165630"><a name="p234075907165630"></a><a name="p234075907165630"></a>size_t </p>
<p id="p1521080449165630"><a name="p1521080449165630"></a><a name="p1521080449165630"></a>Compares the first <strong id="b1813472537165630"><a name="b1813472537165630"></a><a name="b1813472537165630"></a>n</strong> wide characters in the string pointed to by <strong id="b508931084165630"><a name="b508931084165630"></a><a name="b508931084165630"></a>s1</strong> with those in the string pointed to by <strong id="b275060823165630"><a name="b275060823165630"></a><a name="b275060823165630"></a>s2</strong>. </p>
</td>
</tr>
<tr id="row1373890974165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1438592474165630"><a name="p1438592474165630"></a><a name="p1438592474165630"></a><a href="utils.md#ga3fe8f361d1cff837a204ef0f4fac68eb">wcschr</a> (const wchar_t *wcs, wchar_t wc)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1282297917165630"><a name="p1282297917165630"></a><a name="p1282297917165630"></a>wchar_t * </p>
<p id="p1108634573165630"><a name="p1108634573165630"></a><a name="p1108634573165630"></a>Locates the first occurrence of the wide character pointed to by <strong id="b787934865165630"><a name="b787934865165630"></a><a name="b787934865165630"></a>wc</strong> in the wide character string pointed to by <strong id="b291156023165630"><a name="b291156023165630"></a><a name="b291156023165630"></a>wcs</strong>. </p>
</td>
</tr>
<tr id="row868381726165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1974028103165630"><a name="p1974028103165630"></a><a name="p1974028103165630"></a><a href="utils.md#ga1e2b53d4a4eb975edfd1ec59099a43bd">wcsrchr</a> (const wchar_t *wcs, wchar_t wc)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p985520941165630"><a name="p985520941165630"></a><a name="p985520941165630"></a>wchar_t * </p>
<p id="p1302613732165630"><a name="p1302613732165630"></a><a name="p1302613732165630"></a>Locates the last occurrence of the wide character pointed to by <strong id="b1282054938165630"><a name="b1282054938165630"></a><a name="b1282054938165630"></a>wc</strong> in the wide character string pointed to by <strong id="b376642529165630"><a name="b376642529165630"></a><a name="b376642529165630"></a>wcs</strong>. </p>
</td>
</tr>
<tr id="row70274320165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1258891592165630"><a name="p1258891592165630"></a><a name="p1258891592165630"></a><a href="utils.md#ga188fb5a6a8c210ee46b885a671f55c61">wcscspn</a> (const wchar_t *wcs, const wchar_t *<a href="net.md#ga0807af5ac9dfc2a63624e8c3e0ae95ef">accept</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p591997380165630"><a name="p591997380165630"></a><a name="p591997380165630"></a>size_t </p>
<p id="p381858006165630"><a name="p381858006165630"></a><a name="p381858006165630"></a>Scans the wide character string pointed to by <strong id="b365631518165630"><a name="b365631518165630"></a><a name="b365631518165630"></a>wcs</strong> for any wide characters specified in <strong id="b1217990471165630"><a name="b1217990471165630"></a><a name="b1217990471165630"></a>reject</strong> and obtains the number of unmatched characters in <strong id="b1006830195165630"><a name="b1006830195165630"></a><a name="b1006830195165630"></a>wcs</strong>. </p>
</td>
</tr>
<tr id="row1165610635165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1536910766165630"><a name="p1536910766165630"></a><a name="p1536910766165630"></a><a href="utils.md#ga2a5d42d9b374cbffb3037d0e7efb97a9">wcsspn</a> (const wchar_t *wcs, const wchar_t *<a href="net.md#ga0807af5ac9dfc2a63624e8c3e0ae95ef">accept</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1360460749165630"><a name="p1360460749165630"></a><a name="p1360460749165630"></a>size_t </p>
<p id="p1013277459165630"><a name="p1013277459165630"></a><a name="p1013277459165630"></a>Scans the wide character string pointed to by <strong id="b1087901299165630"><a name="b1087901299165630"></a><a name="b1087901299165630"></a>wcs</strong> for any wide characters specified in <strong id="b256380026165630"><a name="b256380026165630"></a><a name="b256380026165630"></a>reject</strong> and obtains the number matched characters in <strong id="b1290887223165630"><a name="b1290887223165630"></a><a name="b1290887223165630"></a>wcs</strong>. </p>
</td>
</tr>
<tr id="row842879276165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1514169036165630"><a name="p1514169036165630"></a><a name="p1514169036165630"></a><a href="utils.md#ga65c3cbada5beb856956f682e7ab2d812">wcspbrk</a> (const wchar_t *wcs, const wchar_t *<a href="net.md#ga0807af5ac9dfc2a63624e8c3e0ae95ef">accept</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1818673273165630"><a name="p1818673273165630"></a><a name="p1818673273165630"></a>wchar_t * </p>
<p id="p527068290165630"><a name="p527068290165630"></a><a name="p527068290165630"></a>Scans the wide character string pointed to by <strong id="b1081783588165630"><a name="b1081783588165630"></a><a name="b1081783588165630"></a>wcs</strong> for any wide characters specified in <strong id="b1139760410165630"><a name="b1139760410165630"></a><a name="b1139760410165630"></a>accept</strong> and obtains the first occurrence of the matched character. </p>
</td>
</tr>
<tr id="row161020838165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p772760163165630"><a name="p772760163165630"></a><a name="p772760163165630"></a><a href="utils.md#ga01f67f93543c36fdae41b410a7f3d963">wcstok</a> (wchar_t *wcs, const wchar_t *delim, wchar_t **ptr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1279329384165630"><a name="p1279329384165630"></a><a name="p1279329384165630"></a>wchar_t * </p>
<p id="p1701956301165630"><a name="p1701956301165630"></a><a name="p1701956301165630"></a>Splits a wide character string pointed to by <strong id="b294366945165630"><a name="b294366945165630"></a><a name="b294366945165630"></a>wcs</strong> into tokens using the given delimiter. </p>
</td>
</tr>
<tr id="row1058269901165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1587877099165630"><a name="p1587877099165630"></a><a name="p1587877099165630"></a><a href="utils.md#ga7859e4ba07f77515772c4632d4caa4e0">wcslen</a> (const wchar_t *s)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p212533125165630"><a name="p212533125165630"></a><a name="p212533125165630"></a>size_t </p>
<p id="p1436941702165630"><a name="p1436941702165630"></a><a name="p1436941702165630"></a>Calculates the length of a wide character string pointed to by <strong id="b1158032532165630"><a name="b1158032532165630"></a><a name="b1158032532165630"></a>s</strong>. </p>
</td>
</tr>
<tr id="row1354493649165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1303546102165630"><a name="p1303546102165630"></a><a name="p1303546102165630"></a><a href="utils.md#ga844ce8231d55e4cc8010130477dd0d5a">wcswcs</a> (const wchar_t *haystack, const wchar_t *needle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p108307846165630"><a name="p108307846165630"></a><a name="p108307846165630"></a>wchar_t * </p>
<p id="p1987511903165630"><a name="p1987511903165630"></a><a name="p1987511903165630"></a>Searches the wide character string pointed to by <strong id="b1588232140165630"><a name="b1588232140165630"></a><a name="b1588232140165630"></a>dest</strong> for the first occurrence of the wide character string pointed to by <strong id="b1313330769165630"><a name="b1313330769165630"></a><a name="b1313330769165630"></a>src</strong>. </p>
</td>
</tr>
<tr id="row1353422725165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p396708372165630"><a name="p396708372165630"></a><a name="p396708372165630"></a><a href="utils.md#gacb1e61bbd4b15305803c0e558c00bcdd">wmemchr</a> (const wchar_t *s, wchar_t c, size_t n)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p758328357165630"><a name="p758328357165630"></a><a name="p758328357165630"></a>wchar_t * </p>
<p id="p577732894165630"><a name="p577732894165630"></a><a name="p577732894165630"></a>Searches for the first position of the matched wide character within the specified number of characters in a wide character string. </p>
</td>
</tr>
<tr id="row1323002855165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1956620529165630"><a name="p1956620529165630"></a><a name="p1956620529165630"></a><a href="utils.md#gaec76ca0ca875ef6cfcc1d7415052eb26">wmemcmp</a> (const wchar_t *lhs, const wchar_t *rhs, size_t count)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p776203441165630"><a name="p776203441165630"></a><a name="p776203441165630"></a>int </p>
<p id="p224943041165630"><a name="p224943041165630"></a><a name="p224943041165630"></a>Compares the first <strong id="b1220123447165630"><a name="b1220123447165630"></a><a name="b1220123447165630"></a>count</strong> characters in the string pointed to by <strong id="b1662032669165630"><a name="b1662032669165630"></a><a name="b1662032669165630"></a>lhs</strong> with the first <strong id="b1728225771165630"><a name="b1728225771165630"></a><a name="b1728225771165630"></a>count</strong> characters in the string pointed to by <strong id="b1254876008165630"><a name="b1254876008165630"></a><a name="b1254876008165630"></a>rhs</strong>. </p>
</td>
</tr>
<tr id="row1267597716165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1184248770165630"><a name="p1184248770165630"></a><a name="p1184248770165630"></a><a href="utils.md#gac20ec2fc709b45b0b89dbdc3ae6a537e">wmemcpy</a> (wchar_t *dest, const wchar_t *src, size_t count)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p981247930165630"><a name="p981247930165630"></a><a name="p981247930165630"></a>wchar_t * </p>
<p id="p52925201165630"><a name="p52925201165630"></a><a name="p52925201165630"></a>Copies <strong id="b1834220268165630"><a name="b1834220268165630"></a><a name="b1834220268165630"></a>count</strong> successive characters from the wide character array pointed to by <strong id="b1713864370165630"><a name="b1713864370165630"></a><a name="b1713864370165630"></a>src</strong> to the wide character array pointed to by <strong id="b776915138165630"><a name="b776915138165630"></a><a name="b776915138165630"></a>dest</strong>. </p>
</td>
</tr>
<tr id="row1105789920165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1695472366165630"><a name="p1695472366165630"></a><a name="p1695472366165630"></a><a href="utils.md#ga7eeab622d3eacdfd8ff0c4226cf85209">wmemmove</a> (wchar_t *dest, const wchar_t *src, size_t count)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1575767652165630"><a name="p1575767652165630"></a><a name="p1575767652165630"></a>wchar_t * </p>
<p id="p173507339165630"><a name="p173507339165630"></a><a name="p173507339165630"></a>Copies <strong id="b816791578165630"><a name="b816791578165630"></a><a name="b816791578165630"></a>count</strong> successive characters from the wide character array pointed to by <strong id="b379198679165630"><a name="b379198679165630"></a><a name="b379198679165630"></a>src</strong> to the wide character array pointed to by <strong id="b638105957165630"><a name="b638105957165630"></a><a name="b638105957165630"></a>dest</strong> (with possible array overlapping). </p>
</td>
</tr>
<tr id="row1240209093165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1495501135165630"><a name="p1495501135165630"></a><a name="p1495501135165630"></a><a href="utils.md#ga830c36f7d0d13b4dcb5059e7b1d9ab83">wmemset</a> (wchar_t *dest, wchar_t ch, size_t count)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1145294346165630"><a name="p1145294346165630"></a><a name="p1145294346165630"></a>wchar_t * </p>
<p id="p1826483931165630"><a name="p1826483931165630"></a><a name="p1826483931165630"></a>Fills <strong id="b1474911538165630"><a name="b1474911538165630"></a><a name="b1474911538165630"></a>count</strong> characters specified by <strong id="b1814330998165630"><a name="b1814330998165630"></a><a name="b1814330998165630"></a>ch</strong> to the wide character array pointed to by <strong id="b912064441165630"><a name="b912064441165630"></a><a name="b912064441165630"></a>dest</strong>. </p>
</td>
</tr>
<tr id="row351925483165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p454396465165630"><a name="p454396465165630"></a><a name="p454396465165630"></a><a href="utils.md#ga263759bc74f8621e89e6077095caa942">btowc</a> (int c)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p517338657165630"><a name="p517338657165630"></a><a name="p517338657165630"></a>wint_t </p>
<p id="p295862926165630"><a name="p295862926165630"></a><a name="p295862926165630"></a>Converts a single-byte character <strong id="b1528141492165630"><a name="b1528141492165630"></a><a name="b1528141492165630"></a>c</strong> into its wide-character representation. </p>
</td>
</tr>
<tr id="row678019831165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1392143718165630"><a name="p1392143718165630"></a><a name="p1392143718165630"></a><a href="utils.md#gafea1d08554775797ac259bf0aea62938">wctob</a> (wint_t c)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2088674901165630"><a name="p2088674901165630"></a><a name="p2088674901165630"></a>int </p>
<p id="p269198825165630"><a name="p269198825165630"></a><a name="p269198825165630"></a>Converts a wide character <strong id="b579083044165630"><a name="b579083044165630"></a><a name="b579083044165630"></a>c</strong> into its single-byte representation. </p>
</td>
</tr>
<tr id="row12507987165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1418987528165630"><a name="p1418987528165630"></a><a name="p1418987528165630"></a><a href="utils.md#gac87bb41cb64e86b29faf5b569c2533b4">mbsinit</a> (const mbstate_t *ps)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2000446238165630"><a name="p2000446238165630"></a><a name="p2000446238165630"></a>int </p>
<p id="p1603717858165630"><a name="p1603717858165630"></a><a name="p1603717858165630"></a>Checks whether the <strong id="b263127760165630"><a name="b263127760165630"></a><a name="b263127760165630"></a>mbstate_t</strong> object pointed to by <strong id="b1121108987165630"><a name="b1121108987165630"></a><a name="b1121108987165630"></a>ps</strong> is in the initial state. </p>
</td>
</tr>
<tr id="row470365583165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p442075767165630"><a name="p442075767165630"></a><a name="p442075767165630"></a><a href="utils.md#ga67e98eb761f2880dc93ceb3833bbf9bd">wcrtomb</a> (char *s, wchar_t wc, mbstate_t *ps)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1137279066165630"><a name="p1137279066165630"></a><a name="p1137279066165630"></a>size_t </p>
<p id="p1223713900165630"><a name="p1223713900165630"></a><a name="p1223713900165630"></a>Converts the wide character specified by <strong id="b573987904165630"><a name="b573987904165630"></a><a name="b573987904165630"></a>wc</strong> into a character string and stores the string to the beginning of the character array pointed to by <strong id="b1696097651165630"><a name="b1696097651165630"></a><a name="b1696097651165630"></a>s</strong>. </p>
</td>
</tr>
<tr id="row2028410441165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1286774616165630"><a name="p1286774616165630"></a><a name="p1286774616165630"></a><a href="utils.md#gab7c8a08e5174c1235b0e925dfc77b938">mbrlen</a> (const char *s, size_t n, mbstate_t *ps)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p313218555165630"><a name="p313218555165630"></a><a name="p313218555165630"></a>size_t </p>
<p id="p2026567775165630"><a name="p2026567775165630"></a><a name="p2026567775165630"></a>Determines the number of bytes in a character string pointed to by <strong id="b2034824409165630"><a name="b2034824409165630"></a><a name="b2034824409165630"></a>s</strong>. </p>
</td>
</tr>
<tr id="row1177373642165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p53073133165630"><a name="p53073133165630"></a><a name="p53073133165630"></a><a href="utils.md#gac3ebddff1a73c20b17986a6b7b68fe56">mbsrtowcs</a> (wchar_t *dest, const char **src, size_t len, mbstate_t *ps)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1414314343165630"><a name="p1414314343165630"></a><a name="p1414314343165630"></a>size_t </p>
<p id="p1968266590165630"><a name="p1968266590165630"></a><a name="p1968266590165630"></a>Converts a multi-byte character string with a length of <strong id="b684443437165630"><a name="b684443437165630"></a><a name="b684443437165630"></a>len</strong> into a wide character string. </p>
</td>
</tr>
<tr id="row273962593165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p336860392165630"><a name="p336860392165630"></a><a name="p336860392165630"></a><a href="utils.md#ga0a628490d6458cfc836ebf3721e68a98">wcsrtombs</a> (char *dest, const wchar_t **src, size_t len, mbstate_t *ps)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1140820664165630"><a name="p1140820664165630"></a><a name="p1140820664165630"></a>size_t </p>
<p id="p1808835304165630"><a name="p1808835304165630"></a><a name="p1808835304165630"></a>Converts a wide character string into a multi-byte string. </p>
</td>
</tr>
<tr id="row1924959049165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1897548565165630"><a name="p1897548565165630"></a><a name="p1897548565165630"></a><a href="utils.md#gadf99123a55665bf0669487a12aee795f">wcstof</a> (const wchar_t *str, wchar_t **endptr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p509934380165630"><a name="p509934380165630"></a><a name="p509934380165630"></a>float </p>
<p id="p1507082489165630"><a name="p1507082489165630"></a><a name="p1507082489165630"></a>Converts a wide character string pointed to by <strong id="b1190248538165630"><a name="b1190248538165630"></a><a name="b1190248538165630"></a>str</strong> into a floating-point value and assigns the next character in <strong id="b989875421165630"><a name="b989875421165630"></a><a name="b989875421165630"></a>str</strong> after the floating-point value to <strong id="b1256316372165630"><a name="b1256316372165630"></a><a name="b1256316372165630"></a>endptr</strong>. </p>
</td>
</tr>
<tr id="row985345417165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2113552582165630"><a name="p2113552582165630"></a><a name="p2113552582165630"></a><a href="utils.md#ga2030f1f318ded574650a1957574711a0">wcstod</a> (const wchar_t *str, wchar_t **endptr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1341635741165630"><a name="p1341635741165630"></a><a name="p1341635741165630"></a>double </p>
<p id="p1233552132165630"><a name="p1233552132165630"></a><a name="p1233552132165630"></a>Converts a wide character string pointed to by <strong id="b1891190393165630"><a name="b1891190393165630"></a><a name="b1891190393165630"></a>str</strong> into a double value and assigns the next character in <strong id="b1399774932165630"><a name="b1399774932165630"></a><a name="b1399774932165630"></a>str</strong> after the double value to <strong id="b223917838165630"><a name="b223917838165630"></a><a name="b223917838165630"></a>endptr</strong>. </p>
</td>
</tr>
<tr id="row59538903165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1229164092165630"><a name="p1229164092165630"></a><a name="p1229164092165630"></a><a href="utils.md#gaf1879aa0145431434cbac389629bee6a">wcstold</a> (const wchar_t *str, wchar_t **endptr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p420003150165630"><a name="p420003150165630"></a><a name="p420003150165630"></a>long double </p>
<p id="p34385181165630"><a name="p34385181165630"></a><a name="p34385181165630"></a>Converts a wide character string pointed to by <strong id="b1363276446165630"><a name="b1363276446165630"></a><a name="b1363276446165630"></a>str</strong> into a long double value and assigns the next character in <strong id="b414934418165630"><a name="b414934418165630"></a><a name="b414934418165630"></a>str</strong> after the long double value to <strong id="b944473327165630"><a name="b944473327165630"></a><a name="b944473327165630"></a>endptr</strong>. </p>
</td>
</tr>
<tr id="row1135153703165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p599192797165630"><a name="p599192797165630"></a><a name="p599192797165630"></a><a href="utils.md#ga623c775bac158351e308fd3811daeb9f">wcstol</a> (const wchar_t *str, wchar_t **endptr, int base)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p181654286165630"><a name="p181654286165630"></a><a name="p181654286165630"></a>long </p>
<p id="p1650252130165630"><a name="p1650252130165630"></a><a name="p1650252130165630"></a>Converts a wide character string pointed to by <strong id="b1036073881165630"><a name="b1036073881165630"></a><a name="b1036073881165630"></a>str</strong> into a long value. </p>
</td>
</tr>
<tr id="row1745548196165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p685032802165630"><a name="p685032802165630"></a><a name="p685032802165630"></a><a href="utils.md#ga71d821611320a733b3f51ff8077ce92c">wcstoul</a> (const wchar_t *str, wchar_t **endptr, int base)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p816103047165630"><a name="p816103047165630"></a><a name="p816103047165630"></a>unsigned long </p>
<p id="p2115762922165630"><a name="p2115762922165630"></a><a name="p2115762922165630"></a>Converts a wide character string pointed to by <strong id="b1488663702165630"><a name="b1488663702165630"></a><a name="b1488663702165630"></a>str</strong> into an unsigned long value of a specified base. </p>
</td>
</tr>
<tr id="row803946675165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1207264393165630"><a name="p1207264393165630"></a><a name="p1207264393165630"></a><a href="utils.md#ga1f43fe48b9afd42fb80b0560c1358ad3">wcstoll</a> (const wchar_t *str, wchar_t **endptr, int base)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1004608480165630"><a name="p1004608480165630"></a><a name="p1004608480165630"></a>long long </p>
<p id="p33925126165630"><a name="p33925126165630"></a><a name="p33925126165630"></a>Converts a wide character string pointed to by <strong id="b1633334064165630"><a name="b1633334064165630"></a><a name="b1633334064165630"></a>str</strong> into a long long value of a specified base. </p>
</td>
</tr>
<tr id="row1606474309165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1221250886165630"><a name="p1221250886165630"></a><a name="p1221250886165630"></a><a href="utils.md#gad28d6c39911a0d99ebaf2ee4e3b9f621">wcstoull</a> (const wchar_t *str, wchar_t **endptr, int base)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p640842886165630"><a name="p640842886165630"></a><a name="p640842886165630"></a>unsigned long long </p>
<p id="p937100030165630"><a name="p937100030165630"></a><a name="p937100030165630"></a>Converts a wide character string pointed to by <strong id="b1480868517165630"><a name="b1480868517165630"></a><a name="b1480868517165630"></a>str</strong> into an unsigned long long value of a specified base. </p>
</td>
</tr>
<tr id="row1784542613165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1614016062165630"><a name="p1614016062165630"></a><a name="p1614016062165630"></a><a href="utils.md#ga5438ce60b99b0455f356cd27726161ab">fwide</a> (<a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream, int mode)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p266115195165630"><a name="p266115195165630"></a><a name="p266115195165630"></a>int </p>
<p id="p535051055165630"><a name="p535051055165630"></a><a name="p535051055165630"></a>Sets and determines the orientation of the file stream. </p>
</td>
</tr>
<tr id="row180277255165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1572984230165630"><a name="p1572984230165630"></a><a name="p1572984230165630"></a><a href="utils.md#gaf30b50dd88f13675d890857755670a2d">wprintf</a> (const wchar_t *format,...)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1746177521165630"><a name="p1746177521165630"></a><a name="p1746177521165630"></a>int </p>
<p id="p1357992988165630"><a name="p1357992988165630"></a><a name="p1357992988165630"></a>Prints formatted data to the standard output (stdout). </p>
</td>
</tr>
<tr id="row950674810165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p348555732165630"><a name="p348555732165630"></a><a name="p348555732165630"></a><a href="utils.md#ga2b7ff2e4c9e4d1c0d6dc35bf93542d53">fwprintf</a> (<a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *__restrict fp, const wchar_t *__restrict fmt,...)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p696297813165630"><a name="p696297813165630"></a><a name="p696297813165630"></a>int </p>
<p id="p82110092165630"><a name="p82110092165630"></a><a name="p82110092165630"></a>Prints wide character strings to a specified file stream. </p>
</td>
</tr>
<tr id="row1860986840165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p726817693165630"><a name="p726817693165630"></a><a name="p726817693165630"></a><a href="utils.md#ga7c963d10722b32fbcf5508057ccf76ec">swprintf</a> (wchar_t *wcs, size_t maxlen, const wchar_t *format,...)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2100012501165630"><a name="p2100012501165630"></a><a name="p2100012501165630"></a>int </p>
<p id="p1467548225165630"><a name="p1467548225165630"></a><a name="p1467548225165630"></a>Prints formatted data to a specified string. </p>
</td>
</tr>
<tr id="row1580225161165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1873852480165630"><a name="p1873852480165630"></a><a name="p1873852480165630"></a><a href="utils.md#gadff14929a4410b3ac0ce28b55357e280">vwprintf</a> (const wchar_t *format, va_list args)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p168839034165630"><a name="p168839034165630"></a><a name="p168839034165630"></a>int </p>
<p id="p163607080165630"><a name="p163607080165630"></a><a name="p163607080165630"></a>Prints formatted data from a variable argument list to the standard output (stdout). </p>
</td>
</tr>
<tr id="row1724423618165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1692170062165630"><a name="p1692170062165630"></a><a name="p1692170062165630"></a><a href="utils.md#ga52697c5b86b8a3fa892b69f70fac8843">vfwprintf</a> (<a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream, const wchar_t *format, __isoc_va_list args)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p727009599165630"><a name="p727009599165630"></a><a name="p727009599165630"></a>int </p>
<p id="p95310251165630"><a name="p95310251165630"></a><a name="p95310251165630"></a>Prints formatted data from a variable argument list specified by <strong id="b509416525165630"><a name="b509416525165630"></a><a name="b509416525165630"></a>args</strong> to a specified file stream. </p>
</td>
</tr>
<tr id="row1122100427165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1846721042165630"><a name="p1846721042165630"></a><a name="p1846721042165630"></a><a href="utils.md#gad79402226fa58569bee4601eb029b717">vswprintf</a> (wchar_t *wcs, size_t maxlen, const wchar_t *format, __isoc_va_list args)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1138551525165630"><a name="p1138551525165630"></a><a name="p1138551525165630"></a>int </p>
<p id="p648278070165630"><a name="p648278070165630"></a><a name="p648278070165630"></a>Prints formatted data from a variable argument list specified by <strong id="b769115847165630"><a name="b769115847165630"></a><a name="b769115847165630"></a>args</strong> to a specified string. </p>
</td>
</tr>
<tr id="row118470397165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1522272136165630"><a name="p1522272136165630"></a><a name="p1522272136165630"></a><a href="utils.md#ga24e265f34e058454b9a9b6247b1694b0">wscanf</a> (const wchar_t *format,...)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p526269416165630"><a name="p526269416165630"></a><a name="p526269416165630"></a>int </p>
<p id="p262337744165630"><a name="p262337744165630"></a><a name="p262337744165630"></a>Reads formatted data from the standard input (stdin) and stores it based on the wide string format into the locations pointed to by the variable arguments. </p>
</td>
</tr>
<tr id="row542050289165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1953478597165630"><a name="p1953478597165630"></a><a name="p1953478597165630"></a><a href="utils.md#ga1e39ec126230aed6ffa3e922be38a014">fwscanf</a> (<a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream, const wchar_t *format,...)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1241702924165630"><a name="p1241702924165630"></a><a name="p1241702924165630"></a>int </p>
<p id="p2138924474165630"><a name="p2138924474165630"></a><a name="p2138924474165630"></a>Reads formatted data from a specified stream and stores it based on the wide string format into the locations pointed to by the variable arguments. </p>
</td>
</tr>
<tr id="row1866715082165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1166250307165630"><a name="p1166250307165630"></a><a name="p1166250307165630"></a><a href="utils.md#gaac90953229a0d08ce45ba328430d6637">swscanf</a> (const wchar_t *ws, const wchar_t *format,...)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2064552626165630"><a name="p2064552626165630"></a><a name="p2064552626165630"></a>int </p>
<p id="p1719436397165630"><a name="p1719436397165630"></a><a name="p1719436397165630"></a>Reads data from a wide character string pointed to by <strong id="b295381563165630"><a name="b295381563165630"></a><a name="b295381563165630"></a>ws</strong> and stores it based on the wide string format into the locations pointed to by the variable arguments. </p>
</td>
</tr>
<tr id="row1717420162165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1572173495165630"><a name="p1572173495165630"></a><a name="p1572173495165630"></a><a href="utils.md#ga4406b91b463b1fc3d4d43b44ccb46d1c">vwscanf</a> (const wchar_t *format, va_list arg)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p403001332165630"><a name="p403001332165630"></a><a name="p403001332165630"></a>int </p>
<p id="p488136566165630"><a name="p488136566165630"></a><a name="p488136566165630"></a>Reads data from the stdin and stores it based on the wide string format into the locations pointed to by the elements in the variable argument list identified by <strong id="b414191234165630"><a name="b414191234165630"></a><a name="b414191234165630"></a>arg</strong>. </p>
</td>
</tr>
<tr id="row1795763686165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p94759067165630"><a name="p94759067165630"></a><a name="p94759067165630"></a><a href="utils.md#ga0d7996cc31075571432fcc7a21c402fa">vfwscanf</a> (<a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream, const wchar_t *format, va_list arg)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1835592273165630"><a name="p1835592273165630"></a><a name="p1835592273165630"></a>int </p>
<p id="p191128904165630"><a name="p191128904165630"></a><a name="p191128904165630"></a>Reads data from a specified file stream and stores it based on the wide string format into the locations pointed to by the elements in the variable argument list identified by <strong id="b1453368708165630"><a name="b1453368708165630"></a><a name="b1453368708165630"></a>arg</strong>. </p>
</td>
</tr>
<tr id="row1783668179165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1643922848165630"><a name="p1643922848165630"></a><a name="p1643922848165630"></a><a href="utils.md#ga0b70af0bd7f82c6f81886d79ad41b2c1">vswscanf</a> (const wchar_t *ws, const wchar_t *format, va_list arg)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p737160696165630"><a name="p737160696165630"></a><a name="p737160696165630"></a>int </p>
<p id="p1520296894165630"><a name="p1520296894165630"></a><a name="p1520296894165630"></a>Reads data from a string pointed to by <strong id="b1552752262165630"><a name="b1552752262165630"></a><a name="b1552752262165630"></a>ws</strong> and stores it based on the wide string format into the locations pointed to by the elements in the variable argument list identified by <strong id="b640287515165630"><a name="b640287515165630"></a><a name="b640287515165630"></a>arg</strong>. </p>
</td>
</tr>
<tr id="row191903198165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1433982528165630"><a name="p1433982528165630"></a><a name="p1433982528165630"></a><a href="utils.md#ga2b545d8d6d3209a2eb6129d8ba646fe3">fgetwc</a> (<a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1117109930165630"><a name="p1117109930165630"></a><a name="p1117109930165630"></a>wint_t </p>
<p id="p679655594165630"><a name="p679655594165630"></a><a name="p679655594165630"></a>Reads a wide character from a specified file stream. </p>
</td>
</tr>
<tr id="row1607494006165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1360313598165630"><a name="p1360313598165630"></a><a name="p1360313598165630"></a><a href="utils.md#gaadd2028a176fe13a0d6090cec651a369">getwc</a> (<a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p84513851165630"><a name="p84513851165630"></a><a name="p84513851165630"></a>wint_t </p>
<p id="p2139970677165630"><a name="p2139970677165630"></a><a name="p2139970677165630"></a>Reads the first wide character from a specified file stream. </p>
</td>
</tr>
<tr id="row1166027821165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1644549063165630"><a name="p1644549063165630"></a><a name="p1644549063165630"></a><a href="utils.md#gaa1379ae6936df3415301dc580aa8756e">getwchar</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1306343844165630"><a name="p1306343844165630"></a><a name="p1306343844165630"></a>wint_t </p>
<p id="p2121094091165630"><a name="p2121094091165630"></a><a name="p2121094091165630"></a>Reads a wide character from the stdin. </p>
</td>
</tr>
<tr id="row1462701202165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p519334361165630"><a name="p519334361165630"></a><a name="p519334361165630"></a><a href="utils.md#gab405f6ad88ebd1c6150206d19d3c7f12">fputwc</a> (wchar_t wc, <a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1028650820165630"><a name="p1028650820165630"></a><a name="p1028650820165630"></a>wint_t </p>
<p id="p930111285165630"><a name="p930111285165630"></a><a name="p930111285165630"></a>Writes a wide character <strong id="b1884016357165630"><a name="b1884016357165630"></a><a name="b1884016357165630"></a>wc</strong> to a specified file stream. </p>
</td>
</tr>
<tr id="row166994083165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1208442512165630"><a name="p1208442512165630"></a><a name="p1208442512165630"></a><a href="utils.md#ga578ce42fa0cf04469cff45134114b701">putwc</a> (wchar_t wc, <a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p641349157165630"><a name="p641349157165630"></a><a name="p641349157165630"></a>wint_t </p>
<p id="p1526506758165630"><a name="p1526506758165630"></a><a name="p1526506758165630"></a>Writes a wide character <strong id="b27400224165630"><a name="b27400224165630"></a><a name="b27400224165630"></a>wc</strong> to a specified file stream. </p>
</td>
</tr>
<tr id="row811096984165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p573427789165630"><a name="p573427789165630"></a><a name="p573427789165630"></a><a href="utils.md#ga34ef116bac70390d5a2ff8c5fdb45777">putwchar</a> (wchar_t wc)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1630767589165630"><a name="p1630767589165630"></a><a name="p1630767589165630"></a>wint_t </p>
<p id="p1852556361165630"><a name="p1852556361165630"></a><a name="p1852556361165630"></a>Writes a wide character <strong id="b1637366796165630"><a name="b1637366796165630"></a><a name="b1637366796165630"></a>wc</strong> to the stdout. </p>
</td>
</tr>
<tr id="row1962960846165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1808581721165630"><a name="p1808581721165630"></a><a name="p1808581721165630"></a><a href="utils.md#ga6f98d7f5d5d1e6ad282ee1a348eab753">fgetws</a> (wchar_t *ws, int n, <a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1650024271165630"><a name="p1650024271165630"></a><a name="p1650024271165630"></a>wchar_t * </p>
<p id="p693583008165630"><a name="p693583008165630"></a><a name="p693583008165630"></a>Reads wide characters from a specified file stream. </p>
</td>
</tr>
<tr id="row1494361909165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1242745176165630"><a name="p1242745176165630"></a><a name="p1242745176165630"></a><a href="utils.md#gad3afb048298b1f152181fcac8e20d6e3">fputws</a> (const wchar_t *ws, <a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p289670594165630"><a name="p289670594165630"></a><a name="p289670594165630"></a>int </p>
<p id="p1508938358165630"><a name="p1508938358165630"></a><a name="p1508938358165630"></a>Writes a wide string pointed to by <strong id="b113286223165630"><a name="b113286223165630"></a><a name="b113286223165630"></a>ws</strong> to a specified file stream. </p>
</td>
</tr>
<tr id="row318237046165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p983232252165630"><a name="p983232252165630"></a><a name="p983232252165630"></a><a href="utils.md#ga35264055ce08ba6d23ba03075897a0fb">ungetwc</a> (wint_t ch, <a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p511941363165630"><a name="p511941363165630"></a><a name="p511941363165630"></a>wint_t </p>
<p id="p43128089165630"><a name="p43128089165630"></a><a name="p43128089165630"></a>Pushes a character back into a specified file stream. </p>
</td>
</tr>
<tr id="row2031244765165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p212425115165630"><a name="p212425115165630"></a><a name="p212425115165630"></a><a href="utils.md#ga6fd639ff3ac22621951452b380468327">mbrtowc</a> (wchar_t *pwc, const char *s, size_t n, mbstate_t *ps)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p485010428165630"><a name="p485010428165630"></a><a name="p485010428165630"></a>size_t </p>
<p id="p2047497348165630"><a name="p2047497348165630"></a><a name="p2047497348165630"></a>Converts a multi-byte character string with a length of <strong id="b975033536165630"><a name="b975033536165630"></a><a name="b975033536165630"></a>n</strong> into a wide character string. </p>
</td>
</tr>
<tr id="row1618022859165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1963696541165630"><a name="p1963696541165630"></a><a name="p1963696541165630"></a><a href="utils.md#ga08f9c737e4060d9e123e0fc28a1eb2f3">mbsnrtowcs</a> (wchar_t *dest, const char **src, size_t nwc, size_t len, mbstate_t *ps)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p523238279165630"><a name="p523238279165630"></a><a name="p523238279165630"></a>size_t </p>
<p id="p663468380165630"><a name="p663468380165630"></a><a name="p663468380165630"></a>Converts a multi-byte character string with a length of <strong id="b1255535247165630"><a name="b1255535247165630"></a><a name="b1255535247165630"></a>n</strong> into a wide character string that can hold a total of <strong id="b307008947165630"><a name="b307008947165630"></a><a name="b307008947165630"></a>nwc</strong> wide characters. </p>
</td>
</tr>
<tr id="row1430643452165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p375958475165630"><a name="p375958475165630"></a><a name="p375958475165630"></a><a href="utils.md#gaf189ea21a3aa444f88607ad23f448f37">wcsnrtombs</a> (char *dest, const wchar_t **src, size_t nwc, size_t len, mbstate_t *ps)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1986319043165630"><a name="p1986319043165630"></a><a name="p1986319043165630"></a>size_t </p>
<p id="p1879466745165630"><a name="p1879466745165630"></a><a name="p1879466745165630"></a>Converts <strong id="b1526461149165630"><a name="b1526461149165630"></a><a name="b1526461149165630"></a>nwc</strong> wide characters in the string pointed to by <strong id="b145064423165630"><a name="b145064423165630"></a><a name="b145064423165630"></a>src</strong> into a character string. </p>
</td>
</tr>
<tr id="row1528591846165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p495206730165630"><a name="p495206730165630"></a><a name="p495206730165630"></a><a href="utils.md#ga21234261a334fd22ff3d6ba8883eca3a">wcsdup</a> (const wchar_t *s)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1136634912165630"><a name="p1136634912165630"></a><a name="p1136634912165630"></a>wchar_t * </p>
<p id="p688002128165630"><a name="p688002128165630"></a><a name="p688002128165630"></a>Copies a specified wide character string to a newly allocated buffer. </p>
</td>
</tr>
<tr id="row896160435165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p546365349165630"><a name="p546365349165630"></a><a name="p546365349165630"></a><a href="utils.md#ga5ef7fc85c7678f86f1530fd52dbf2486">wcsnlen</a> (const wchar_t *s, size_t maxlen)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1203097571165630"><a name="p1203097571165630"></a><a name="p1203097571165630"></a>size_t </p>
<p id="p2090334026165630"><a name="p2090334026165630"></a><a name="p2090334026165630"></a>Calculates the length of a wide character string pointed to by <strong id="b1482748286165630"><a name="b1482748286165630"></a><a name="b1482748286165630"></a>s</strong>. </p>
</td>
</tr>
<tr id="row635755402165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p387032354165630"><a name="p387032354165630"></a><a name="p387032354165630"></a><a href="utils.md#gaa4f33e46d5c0263f0b3e9a1e8eb0a7a9">wcpcpy</a> (wchar_t *dest, const wchar_t *src)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1450419723165630"><a name="p1450419723165630"></a><a name="p1450419723165630"></a>wchar_t * </p>
<p id="p628507285165630"><a name="p628507285165630"></a><a name="p628507285165630"></a>Copies the wide characters (including the terminating null character <strong id="b885204531165630"><a name="b885204531165630"></a><a name="b885204531165630"></a>'\0'</strong>) pointed to by <strong id="b36959472165630"><a name="b36959472165630"></a><a name="b36959472165630"></a>src</strong> to the wide character array pointed to by <strong id="b349691867165630"><a name="b349691867165630"></a><a name="b349691867165630"></a>dest</strong>. </p>
</td>
</tr>
<tr id="row2108993973165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p805285865165630"><a name="p805285865165630"></a><a name="p805285865165630"></a><a href="utils.md#ga2b77c48e45c06857bae5c4720fd977b9">wcpncpy</a> (wchar_t *dest, const wchar_t *src, size_t n)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2146411332165630"><a name="p2146411332165630"></a><a name="p2146411332165630"></a>wchar_t * </p>
<p id="p1111136323165630"><a name="p1111136323165630"></a><a name="p1111136323165630"></a>Copies <strong id="b1416652255165630"><a name="b1416652255165630"></a><a name="b1416652255165630"></a>n</strong> wide characters (including the terminating null character <strong id="b2068974074165630"><a name="b2068974074165630"></a><a name="b2068974074165630"></a>'\0'</strong>) pointed to by <strong id="b1234505105165630"><a name="b1234505105165630"></a><a name="b1234505105165630"></a>src</strong> to the wide character array pointed to by <strong id="b953155971165630"><a name="b953155971165630"></a><a name="b953155971165630"></a>dest</strong>. </p>
</td>
</tr>
<tr id="row379985953165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p876903464165630"><a name="p876903464165630"></a><a name="p876903464165630"></a><a href="utils.md#ga1cfd283a315ce1081565d9370dadbd1e">wcscasecmp</a> (const wchar_t *s1, const wchar_t *s2)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1879419971165630"><a name="p1879419971165630"></a><a name="p1879419971165630"></a>int </p>
<p id="p1252316796165630"><a name="p1252316796165630"></a><a name="p1252316796165630"></a>Compares the wide characters in the string pointed to by <strong id="b1072380775165630"><a name="b1072380775165630"></a><a name="b1072380775165630"></a>s1</strong> with those in the string pointed to by <strong id="b911215833165630"><a name="b911215833165630"></a><a name="b911215833165630"></a>s2</strong>, with their case differences ignored. </p>
</td>
</tr>
<tr id="row1702215566165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p853088181165630"><a name="p853088181165630"></a><a name="p853088181165630"></a><a href="utils.md#gad5fd70aa458e05eaec03bb88d5eefdef">wcscasecmp_l</a> (const wchar_t *s1, const wchar_t *s2, locale_t locale)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1114134924165630"><a name="p1114134924165630"></a><a name="p1114134924165630"></a>int </p>
<p id="p287768636165630"><a name="p287768636165630"></a><a name="p287768636165630"></a>Compares the wide characters in the string pointed to by <strong id="b2017851390165630"><a name="b2017851390165630"></a><a name="b2017851390165630"></a>s1</strong> with those in the string pointed to by <strong id="b1825671433165630"><a name="b1825671433165630"></a><a name="b1825671433165630"></a>s2</strong> based on the specified <strong id="b1822729914165630"><a name="b1822729914165630"></a><a name="b1822729914165630"></a>locale</strong> environment, with their case differences ignored. </p>
</td>
</tr>
<tr id="row631275140165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p265883990165630"><a name="p265883990165630"></a><a name="p265883990165630"></a><a href="utils.md#ga5c9957285778ae41af839bb22cc4a9d0">wcsncasecmp</a> (const wchar_t *s1, const wchar_t *s2, size_t n)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p595804967165630"><a name="p595804967165630"></a><a name="p595804967165630"></a>int </p>
<p id="p1951503295165630"><a name="p1951503295165630"></a><a name="p1951503295165630"></a>Compares a maximum of <strong id="b1850234512165630"><a name="b1850234512165630"></a><a name="b1850234512165630"></a>n</strong> wide characters in the string pointed to by <strong id="b1517093298165630"><a name="b1517093298165630"></a><a name="b1517093298165630"></a>s1</strong> with those in the string pointed to by <strong id="b734155957165630"><a name="b734155957165630"></a><a name="b734155957165630"></a>s2</strong>, with their case differences ignored. </p>
</td>
</tr>
<tr id="row756181865165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p147304501165630"><a name="p147304501165630"></a><a name="p147304501165630"></a><a href="utils.md#ga157e21d5005c4af440f8fe0407dab8ec">wcsncasecmp_l</a> (const wchar_t *s1, const wchar_t *s2, size_t n, locale_t locale)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1417880617165630"><a name="p1417880617165630"></a><a name="p1417880617165630"></a>int </p>
<p id="p1004211388165630"><a name="p1004211388165630"></a><a name="p1004211388165630"></a>Compares a maximum of <strong id="b787347617165630"><a name="b787347617165630"></a><a name="b787347617165630"></a>n</strong> wide characters in the string pointed to by <strong id="b1829456357165630"><a name="b1829456357165630"></a><a name="b1829456357165630"></a>s1</strong> with those in the string pointed to by <strong id="b626532158165630"><a name="b626532158165630"></a><a name="b626532158165630"></a>s2</strong> based on the specified <strong id="b1870669131165630"><a name="b1870669131165630"></a><a name="b1870669131165630"></a>locale</strong> environment, with their case differences ignored. </p>
</td>
</tr>
<tr id="row1731228408165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p539650378165630"><a name="p539650378165630"></a><a name="p539650378165630"></a><a href="utils.md#ga8bdd5a976685e97d9ac7f45f7951a52c">wcscoll_l</a> (const wchar_t *s1, const wchar_t *s2, locale_t locale)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1090648589165630"><a name="p1090648589165630"></a><a name="p1090648589165630"></a>int </p>
<p id="p1664431302165630"><a name="p1664431302165630"></a><a name="p1664431302165630"></a>Compares wide characters in the string pointed to by <strong id="b628993018165630"><a name="b628993018165630"></a><a name="b628993018165630"></a>s1</strong> with those in the string pointed to by <strong id="b1654176080165630"><a name="b1654176080165630"></a><a name="b1654176080165630"></a>s2</strong> based on the specified <strong id="b751288304165630"><a name="b751288304165630"></a><a name="b751288304165630"></a>locale</strong> environment. </p>
</td>
</tr>
<tr id="row335282478165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p527591196165630"><a name="p527591196165630"></a><a name="p527591196165630"></a><a href="utils.md#ga215d4539e43613e57c992b87158084b4">wcsftime</a> (wchar_t *__restrict wcs, size_t n, const wchar_t *__restrict f, const struct <a href="tm.md">tm</a> *__restrict <a href="tm.md">tm</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p73634534165630"><a name="p73634534165630"></a><a name="p73634534165630"></a>size_t </p>
<p id="p1388022124165630"><a name="p1388022124165630"></a><a name="p1388022124165630"></a>Converts the date and time in the <strong id="b282350441165630"><a name="b282350441165630"></a><a name="b282350441165630"></a>tm</strong> structure to a wide character string. </p>
</td>
</tr>
<tr id="row2033844177165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1167063707165630"><a name="p1167063707165630"></a><a name="p1167063707165630"></a><a href="utils.md#gadd93407a6dc241056ae5198b356f07d4">wcsxfrm_l</a> (wchar_t *s1, const wchar_t *s2, size_t n, locale_t locale)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1583811571165630"><a name="p1583811571165630"></a><a name="p1583811571165630"></a>size_t </p>
<p id="p1138197609165630"><a name="p1138197609165630"></a><a name="p1138197609165630"></a>Compares the first <strong id="b998071867165630"><a name="b998071867165630"></a><a name="b998071867165630"></a>n</strong> wide characters in the string pointed to by <strong id="b1882626692165630"><a name="b1882626692165630"></a><a name="b1882626692165630"></a>s1</strong> with those in the string pointed to by <strong id="b130989638165630"><a name="b130989638165630"></a><a name="b130989638165630"></a>s2</strong> based on the specified <strong id="b1378933111165630"><a name="b1378933111165630"></a><a name="b1378933111165630"></a>locale</strong> environment. </p>
</td>
</tr>
</tbody>
</table>

