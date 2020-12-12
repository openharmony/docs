# wctype.h<a name="EN-US_TOPIC_0000001055707986"></a>

-   [Overview](#section596432344165630)
-   [Summary](#section459072639165630)
-   [Functions](#func-members)

## **Overview**<a name="section596432344165630"></a>

**Related Modules:**

[UTILS](utils.md)

**Description:**

Provides functions to detect, translate, and map wide characters. 

Wide characters are classified into the following types:  **alnum**,  **alpha**,  **upper**,  **lower**,  **digit**,  **xdigit**,  **graph**,  **cntrl**,  **punct**, and  **space**. You can use these functions to detect the type of wide characters and translate the type for the current locale  [LC\_CTYPE](io.md#ga07c66689961056725d7f50231d740ba9)  or a specified locale. You can use these functions to convert the case of wide characters, map the wide characters, and obtain the mapping descriptor for conversion. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section459072639165630"></a>

## Functions<a name="func-members"></a>

<a name="table328660041165630"></a>
<table><thead align="left"><tr id="row675852175165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p949409299165630"><a name="p949409299165630"></a><a name="p949409299165630"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p10743654165630"><a name="p10743654165630"></a><a name="p10743654165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row750412866165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1629302227165630"><a name="p1629302227165630"></a><a name="p1629302227165630"></a><a href="utils.md#gadafb512a79ac9274486d6ddbbbd9d9ba">iswalnum</a> (wint_t wc)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1446096364165630"><a name="p1446096364165630"></a><a name="p1446096364165630"></a>int </p>
<p id="p941192026165630"><a name="p941192026165630"></a><a name="p941192026165630"></a>Checks whether a wide character is a letter or digit. </p>
</td>
</tr>
<tr id="row235928263165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p39445741165630"><a name="p39445741165630"></a><a name="p39445741165630"></a><a href="utils.md#ga72477b4f142de340164deb7bf5a7ae7b">iswalpha</a> (wint_t wc)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2128360187165630"><a name="p2128360187165630"></a><a name="p2128360187165630"></a>int </p>
<p id="p2092630633165630"><a name="p2092630633165630"></a><a name="p2092630633165630"></a>Checks whether a wide character is a letter. </p>
</td>
</tr>
<tr id="row2075817637165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1522099534165630"><a name="p1522099534165630"></a><a name="p1522099534165630"></a><a href="utils.md#ga934cbdaad02f3df1b03e566103a5a118">iswblank</a> (wint_t wc)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p159163837165630"><a name="p159163837165630"></a><a name="p159163837165630"></a>int </p>
<p id="p1258204943165630"><a name="p1258204943165630"></a><a name="p1258204943165630"></a>Checks whether a wide character is a space or tab character (\t). </p>
</td>
</tr>
<tr id="row1490224324165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p484734117165630"><a name="p484734117165630"></a><a name="p484734117165630"></a><a href="utils.md#ga35f4bb15841d36c759ab271aa8033ba8">iswcntrl</a> (wint_t wc)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1820839533165630"><a name="p1820839533165630"></a><a name="p1820839533165630"></a>int </p>
<p id="p1552974688165630"><a name="p1552974688165630"></a><a name="p1552974688165630"></a>Checks whether a wide character is a control character. </p>
</td>
</tr>
<tr id="row508165240165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1549932000165630"><a name="p1549932000165630"></a><a name="p1549932000165630"></a><a href="utils.md#ga972fbaff0c1d4b4e612c789b8532e9af">iswdigit</a> (wint_t wc)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p966193289165630"><a name="p966193289165630"></a><a name="p966193289165630"></a>int </p>
<p id="p985519795165630"><a name="p985519795165630"></a><a name="p985519795165630"></a>Checks whether a wide character is a decimal digit. </p>
</td>
</tr>
<tr id="row1034923864165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p556463082165630"><a name="p556463082165630"></a><a name="p556463082165630"></a><a href="utils.md#ga27b090b588b25bacca79bd11926ce308">iswgraph</a> (wint_t wc)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p668936593165630"><a name="p668936593165630"></a><a name="p668936593165630"></a>int </p>
<p id="p1034088824165630"><a name="p1034088824165630"></a><a name="p1034088824165630"></a>Checks whether a wide character is visible. </p>
</td>
</tr>
<tr id="row560752813165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1070098715165630"><a name="p1070098715165630"></a><a name="p1070098715165630"></a><a href="utils.md#ga92c2a9aad2bf7e6c56a7c01597f59649">iswlower</a> (wint_t wc)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1270136668165630"><a name="p1270136668165630"></a><a name="p1270136668165630"></a>int </p>
<p id="p1388411006165630"><a name="p1388411006165630"></a><a name="p1388411006165630"></a>Checks whether a wide character is a lowercase letter. </p>
</td>
</tr>
<tr id="row1388774083165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1186684739165630"><a name="p1186684739165630"></a><a name="p1186684739165630"></a><a href="utils.md#ga3eef94f4b2065e786f96e231e871d521">iswprint</a> (wint_t wc)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1007235136165630"><a name="p1007235136165630"></a><a name="p1007235136165630"></a>int </p>
<p id="p2135888007165630"><a name="p2135888007165630"></a><a name="p2135888007165630"></a>Checks whether a wide character is printable. </p>
</td>
</tr>
<tr id="row403895439165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p670195441165630"><a name="p670195441165630"></a><a name="p670195441165630"></a><a href="utils.md#gacf0bab8aa20334835ea1b55f715ddd64">iswpunct</a> (wint_t wc)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1949016275165630"><a name="p1949016275165630"></a><a name="p1949016275165630"></a>int </p>
<p id="p702414021165630"><a name="p702414021165630"></a><a name="p702414021165630"></a>Checks whether a wide character is a punctuation mark. </p>
</td>
</tr>
<tr id="row465589591165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1071176836165630"><a name="p1071176836165630"></a><a name="p1071176836165630"></a><a href="utils.md#gaf9d04695802b960ca3765c72d73ddb7c">iswupper</a> (wint_t wc)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1856278375165630"><a name="p1856278375165630"></a><a name="p1856278375165630"></a>int </p>
<p id="p972128674165630"><a name="p972128674165630"></a><a name="p972128674165630"></a>Checks whether a wide character is an uppercase letter. </p>
</td>
</tr>
<tr id="row119268920165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1740918121165630"><a name="p1740918121165630"></a><a name="p1740918121165630"></a><a href="utils.md#ga4f1c74cab8bd862ddac6ad81a4e23f72">iswxdigit</a> (wint_t wc)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1798909754165630"><a name="p1798909754165630"></a><a name="p1798909754165630"></a>int </p>
<p id="p1630036026165630"><a name="p1630036026165630"></a><a name="p1630036026165630"></a>Checks whether a wide character is a hexadecimal digit. </p>
</td>
</tr>
<tr id="row38141584165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p170327737165630"><a name="p170327737165630"></a><a name="p170327737165630"></a><a href="utils.md#gae7bade1da794a7950ad25da75e43ad39">iswctype</a> (wint_t wc, <a href="utils.md#gaf3296ec762e8e6a66c8dd4bd7cf017fb">wctype_t</a> desc)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1114832665165630"><a name="p1114832665165630"></a><a name="p1114832665165630"></a>int </p>
<p id="p1825868758165630"><a name="p1825868758165630"></a><a name="p1825868758165630"></a>Checks whether the character specified by <strong id="b1777032823165630"><a name="b1777032823165630"></a><a name="b1777032823165630"></a>wc</strong> belongs to the <strong id="b761336406165630"><a name="b761336406165630"></a><a name="b761336406165630"></a>desc</strong> class. </p>
</td>
</tr>
<tr id="row1126445513165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p792384605165630"><a name="p792384605165630"></a><a name="p792384605165630"></a><a href="utils.md#gac1d7671abe2a106b481d5bb24717fd11">towctrans</a> (wint_t wc, <a href="utils.md#ga10b40cc6ecda73a91162017d2df251a3">wctrans_t</a> desc)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1118231896165630"><a name="p1118231896165630"></a><a name="p1118231896165630"></a>wint_t </p>
<p id="p1320764970165630"><a name="p1320764970165630"></a><a name="p1320764970165630"></a>Translates the type of a wide character based on the conversion mapping relationship. </p>
</td>
</tr>
<tr id="row152092298165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p479056037165630"><a name="p479056037165630"></a><a name="p479056037165630"></a><a href="utils.md#gab9cd9fba7f8437d2ad5242baa25fd176">towlower</a> (wint_t wc)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p174728783165630"><a name="p174728783165630"></a><a name="p174728783165630"></a>wint_t </p>
<p id="p1729518569165630"><a name="p1729518569165630"></a><a name="p1729518569165630"></a>Converts an uppercase wide character to lowercase. </p>
</td>
</tr>
<tr id="row2026251841165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p738588050165630"><a name="p738588050165630"></a><a name="p738588050165630"></a><a href="utils.md#gaaf8d2b2d230df873695d41757d5889f9">towupper</a> (wint_t wc)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p625473017165630"><a name="p625473017165630"></a><a name="p625473017165630"></a>wint_t </p>
<p id="p1324683721165630"><a name="p1324683721165630"></a><a name="p1324683721165630"></a>Converts a lowercase wide character to uppercase. </p>
</td>
</tr>
<tr id="row881712462165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1835316677165630"><a name="p1835316677165630"></a><a name="p1835316677165630"></a><a href="utils.md#ga98df6598dc60588b24067b97225070ed">wctrans</a> (const char *name)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1836297792165630"><a name="p1836297792165630"></a><a name="p1836297792165630"></a><a href="utils.md#ga10b40cc6ecda73a91162017d2df251a3">wctrans_t</a> </p>
<p id="p1892094752165630"><a name="p1892094752165630"></a><a name="p1892094752165630"></a>Determines a mapping which can map a wide character to another wide character. </p>
</td>
</tr>
<tr id="row1728691304165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p452643779165630"><a name="p452643779165630"></a><a name="p452643779165630"></a><a href="utils.md#gae8a9ddd29c6a369345a12c6cb93aabe1">wctype</a> (const char *name)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1609262318165630"><a name="p1609262318165630"></a><a name="p1609262318165630"></a><a href="utils.md#gaf3296ec762e8e6a66c8dd4bd7cf017fb">wctype_t</a> </p>
<p id="p932390061165630"><a name="p932390061165630"></a><a name="p932390061165630"></a>Checks whether a wide character type exists in the <a href="io.md#ga07c66689961056725d7f50231d740ba9">LC_CTYPE</a> locale. </p>
</td>
</tr>
<tr id="row1412916507165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p136292287165630"><a name="p136292287165630"></a><a name="p136292287165630"></a><a href="utils.md#ga8d6ca21d11b21620ff32e32ebc5b251a">iswalnum_l</a> (wint_t wc, locale_t locale)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p28542953165630"><a name="p28542953165630"></a><a name="p28542953165630"></a>int </p>
<p id="p1496458441165630"><a name="p1496458441165630"></a><a name="p1496458441165630"></a>Checks whether a wide character is a letter or digit for the specified locale. </p>
</td>
</tr>
<tr id="row2117740767165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1717443108165630"><a name="p1717443108165630"></a><a name="p1717443108165630"></a><a href="utils.md#gadfbb99771f4af02201ef68fc2377164b">iswalpha_l</a> (wint_t wc, locale_t locale)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p145407792165630"><a name="p145407792165630"></a><a name="p145407792165630"></a>int </p>
<p id="p527464250165630"><a name="p527464250165630"></a><a name="p527464250165630"></a>Checks whether a wide character is alphabetic for the specified locale. </p>
</td>
</tr>
<tr id="row1850337786165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p309942822165630"><a name="p309942822165630"></a><a name="p309942822165630"></a><a href="utils.md#ga7d5300cc6bbc4ba910a3f9b4d9da2f4d">iswblank_l</a> (wint_t wc, locale_t locale)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2098045326165630"><a name="p2098045326165630"></a><a name="p2098045326165630"></a>int </p>
<p id="p1348565241165630"><a name="p1348565241165630"></a><a name="p1348565241165630"></a>Checks whether a wide character is a blank or <strong id="b1571829676165630"><a name="b1571829676165630"></a><a name="b1571829676165630"></a>\t</strong> character for the specified locale. </p>
</td>
</tr>
<tr id="row596598584165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1596030585165630"><a name="p1596030585165630"></a><a name="p1596030585165630"></a><a href="utils.md#ga51c189ba9f96d6ed8207da1da81100ca">iswcntrl_l</a> (wint_t wc, locale_t locale)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1077085887165630"><a name="p1077085887165630"></a><a name="p1077085887165630"></a>int </p>
<p id="p763802440165630"><a name="p763802440165630"></a><a name="p763802440165630"></a>Checks whether a wide character is a control character for the specified locale. </p>
</td>
</tr>
<tr id="row1474743666165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p214715944165630"><a name="p214715944165630"></a><a name="p214715944165630"></a><a href="utils.md#gab84fd3a86d300fc49af9d708431566a9">iswdigit_l</a> (wint_t wc, locale_t locale)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1009871562165630"><a name="p1009871562165630"></a><a name="p1009871562165630"></a>int </p>
<p id="p1691671733165630"><a name="p1691671733165630"></a><a name="p1691671733165630"></a>Checks whether a wide character is a decimal digit for the specified locale. </p>
</td>
</tr>
<tr id="row1594990242165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1451384095165630"><a name="p1451384095165630"></a><a name="p1451384095165630"></a><a href="utils.md#gad7529291433b9e8f5e68caada7572244">iswgraph_l</a> (wint_t wc, locale_t locale)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p813519117165630"><a name="p813519117165630"></a><a name="p813519117165630"></a>int </p>
<p id="p1426770520165630"><a name="p1426770520165630"></a><a name="p1426770520165630"></a>Checks whether a wide character is visible for the specified locale. </p>
</td>
</tr>
<tr id="row998132894165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p335573625165630"><a name="p335573625165630"></a><a name="p335573625165630"></a><a href="utils.md#ga944498fac122e95a2da80137e7fffcb4">iswlower_l</a> (wint_t wc, locale_t locale)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1386496168165630"><a name="p1386496168165630"></a><a name="p1386496168165630"></a>int </p>
<p id="p54355158165630"><a name="p54355158165630"></a><a name="p54355158165630"></a>Checks whether a wide character is in lowercase for the specified locale. </p>
</td>
</tr>
<tr id="row2073098171165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p806828309165630"><a name="p806828309165630"></a><a name="p806828309165630"></a><a href="utils.md#gacd7a8387b98672ae64f222072eefd38e">iswprint_l</a> (wint_t wc, locale_t locale)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1827687500165630"><a name="p1827687500165630"></a><a name="p1827687500165630"></a>int </p>
<p id="p174151488165630"><a name="p174151488165630"></a><a name="p174151488165630"></a>Checks whether a wide character is printable for the specified locale. </p>
</td>
</tr>
<tr id="row441420978165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p296193521165630"><a name="p296193521165630"></a><a name="p296193521165630"></a><a href="utils.md#gad355af93606bf5c7688518d78a7c017c">iswpunct_l</a> (wint_t wc, locale_t locale)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1619802119165630"><a name="p1619802119165630"></a><a name="p1619802119165630"></a>int </p>
<p id="p212144912165630"><a name="p212144912165630"></a><a name="p212144912165630"></a>Checks whether <strong id="b1124879630165630"><a name="b1124879630165630"></a><a name="b1124879630165630"></a>wc</strong> is a punctuation wide character for the specified locale. </p>
</td>
</tr>
<tr id="row1914889547165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p427812822165630"><a name="p427812822165630"></a><a name="p427812822165630"></a><a href="utils.md#gafb90e73f1be310ac1fe22f0d652838bc">iswspace</a> (wint_t wc)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p288203159165630"><a name="p288203159165630"></a><a name="p288203159165630"></a>int </p>
<p id="p979501978165630"><a name="p979501978165630"></a><a name="p979501978165630"></a>Checks whether a wide character belongs to the wide-character class <strong id="b2105280005165630"><a name="b2105280005165630"></a><a name="b2105280005165630"></a>space</strong>. </p>
</td>
</tr>
<tr id="row1755266856165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p117536366165630"><a name="p117536366165630"></a><a name="p117536366165630"></a><a href="utils.md#gac9068379860381e27a47831612a85c25">iswspace_l</a> (wint_t wc, locale_t locale)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p879051872165630"><a name="p879051872165630"></a><a name="p879051872165630"></a>int </p>
<p id="p2080267324165630"><a name="p2080267324165630"></a><a name="p2080267324165630"></a>Checks whether a wide character belongs to the wide-character class <strong id="b772520713165630"><a name="b772520713165630"></a><a name="b772520713165630"></a>space</strong> for the specified locale. </p>
</td>
</tr>
<tr id="row513463360165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p151774295165630"><a name="p151774295165630"></a><a name="p151774295165630"></a><a href="utils.md#ga4f73f2368e29bb2fc350479157987bc8">iswupper_l</a> (wint_t wc, locale_t locale)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p393132655165630"><a name="p393132655165630"></a><a name="p393132655165630"></a>int </p>
<p id="p1885156976165630"><a name="p1885156976165630"></a><a name="p1885156976165630"></a>Checks whether a wide character is in uppercase for the specified locale. </p>
</td>
</tr>
<tr id="row1963860891165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p362354600165630"><a name="p362354600165630"></a><a name="p362354600165630"></a><a href="utils.md#ga2355dbfdaa44cb73ffd0216f97a7ad93">iswxdigit_l</a> (wint_t wc, locale_t locale)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1006359123165630"><a name="p1006359123165630"></a><a name="p1006359123165630"></a>int </p>
<p id="p2133395152165630"><a name="p2133395152165630"></a><a name="p2133395152165630"></a>Checks whether a wide character is a hexadecimal digit for the specified locale. </p>
</td>
</tr>
<tr id="row1875093473165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p781257829165630"><a name="p781257829165630"></a><a name="p781257829165630"></a><a href="utils.md#ga0f3b0048ef4d82840c1f7d1c78e25e6b">iswctype_l</a> (wint_t wc, <a href="utils.md#gaf3296ec762e8e6a66c8dd4bd7cf017fb">wctype_t</a> desc, locale_t locale)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1507239775165630"><a name="p1507239775165630"></a><a name="p1507239775165630"></a>int </p>
<p id="p2100087795165630"><a name="p2100087795165630"></a><a name="p2100087795165630"></a>Checks whether the character specified by <strong id="b1489920221165630"><a name="b1489920221165630"></a><a name="b1489920221165630"></a>wc</strong> belongs to the <strong id="b616122836165630"><a name="b616122836165630"></a><a name="b616122836165630"></a>desc</strong> class for the specified locale. </p>
</td>
</tr>
<tr id="row1427163674165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1684325967165630"><a name="p1684325967165630"></a><a name="p1684325967165630"></a><a href="utils.md#ga6333139346611f59c603f70b61b521b5">towlower_l</a> (wint_t wc, locale_t locale)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1128730076165630"><a name="p1128730076165630"></a><a name="p1128730076165630"></a>wint_t </p>
<p id="p1987007708165630"><a name="p1987007708165630"></a><a name="p1987007708165630"></a>Converts an uppercase wide character to lowercase for the specified locale. </p>
</td>
</tr>
<tr id="row771955651165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1914681289165630"><a name="p1914681289165630"></a><a name="p1914681289165630"></a><a href="utils.md#gac01816aef7bc2050e1b19db17a26bae8">towupper_l</a> (wint_t wc, locale_t locale)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1869957710165630"><a name="p1869957710165630"></a><a name="p1869957710165630"></a>wint_t </p>
<p id="p209183733165630"><a name="p209183733165630"></a><a name="p209183733165630"></a>Converts a lowercase wide character to uppercase for the specified locale. </p>
</td>
</tr>
<tr id="row1745380851165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1895256635165630"><a name="p1895256635165630"></a><a name="p1895256635165630"></a><a href="utils.md#gaa65f72b343b0d847933e6dbb7454a915">towctrans_l</a> (wint_t wc, <a href="utils.md#gaf3296ec762e8e6a66c8dd4bd7cf017fb">wctype_t</a> desc, locale_t locale)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p790088750165630"><a name="p790088750165630"></a><a name="p790088750165630"></a>wint_t </p>
<p id="p1407519074165630"><a name="p1407519074165630"></a><a name="p1407519074165630"></a>Translates the type of a wide character based on the translation mapping relationship for the specified locale. </p>
</td>
</tr>
<tr id="row1112531728165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p430073429165630"><a name="p430073429165630"></a><a name="p430073429165630"></a><a href="utils.md#ga85e85bc84a644c3a0686fd6e4cfd96d7">wctrans_l</a> (const char *name, locale_t locale)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1430883994165630"><a name="p1430883994165630"></a><a name="p1430883994165630"></a><a href="utils.md#ga10b40cc6ecda73a91162017d2df251a3">wctrans_t</a> </p>
<p id="p1298227070165630"><a name="p1298227070165630"></a><a name="p1298227070165630"></a>Determines a mapping which can map a wide character to another wide character. </p>
</td>
</tr>
<tr id="row1132415966165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2032870314165630"><a name="p2032870314165630"></a><a name="p2032870314165630"></a><a href="utils.md#gae43cf599bd1eb5674ed9cc17870f7472">wctype_l</a> (const char *name, locale_t locale)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p609829804165630"><a name="p609829804165630"></a><a name="p609829804165630"></a><a href="utils.md#gaf3296ec762e8e6a66c8dd4bd7cf017fb">wctype_t</a> </p>
<p id="p1813808936165630"><a name="p1813808936165630"></a><a name="p1813808936165630"></a>Checks whether a wide character type exists for the specified locale. </p>
</td>
</tr>
</tbody>
</table>

