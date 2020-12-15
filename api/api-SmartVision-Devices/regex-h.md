# regex.h<a name="ZH-CN_TOPIC_0000001055089550"></a>

-   [Overview](#section533711568165628)
-   [Summary](#section520317974165628)
-   [Functions](#func-members)

## **Overview**<a name="section533711568165628"></a>

**Related Modules:**

[UTILS](UTILS.md)

**Description:**

Provides common functions for operating regular expressions. 

You can use functions provided in this file to perform operations on regular expressions during development. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section520317974165628"></a>

## Functions<a name="func-members"></a>

<a name="table1226911663165628"></a>
<table><thead align="left"><tr id="row573520667165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p464380596165628"><a name="p464380596165628"></a><a name="p464380596165628"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p900387391165628"><a name="p900387391165628"></a><a name="p900387391165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2053799420165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1775713072165628"><a name="p1775713072165628"></a><a name="p1775713072165628"></a><a href="UTILS.md#ga075d4ee229f48709667fe28313d2013e">regcomp</a> (regex_t *preg, const char *regex, int cflags)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2037235300165628"><a name="p2037235300165628"></a><a name="p2037235300165628"></a>int </p>
<p id="p1558867388165628"><a name="p1558867388165628"></a><a name="p1558867388165628"></a>Compiles a specified regular expression into a string of a specific format. </p>
</td>
</tr>
<tr id="row1116655255165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1997469707165628"><a name="p1997469707165628"></a><a name="p1997469707165628"></a><a href="UTILS.md#ga5fda573156393bb7d89b4291ded6e26b">regexec</a> (const regex_t *preg, const char *string, size_t nmatch, regmatch_t pmatch[], int eflags)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p67332718165628"><a name="p67332718165628"></a><a name="p67332718165628"></a>int </p>
<p id="p1305055861165628"><a name="p1305055861165628"></a><a name="p1305055861165628"></a>Matches a regular expression. </p>
</td>
</tr>
<tr id="row1357556847165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1684938692165628"><a name="p1684938692165628"></a><a name="p1684938692165628"></a><a href="UTILS.md#gad94d0de532eaa4fd959b8adde4d64898">regfree</a> (regex_t *preg)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2101209729165628"><a name="p2101209729165628"></a><a name="p2101209729165628"></a>void </p>
<p id="p641497075165628"><a name="p641497075165628"></a><a name="p641497075165628"></a>Releases a regular expression. </p>
</td>
</tr>
<tr id="row524475771165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p122732006165628"><a name="p122732006165628"></a><a name="p122732006165628"></a><a href="UTILS.md#ga091f175aa7e3ae5450ce2ee33495b901">regerror</a> (int errcode, const regex_t *preg, char *errbuf, size_t errbuf_size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1742604977165628"><a name="p1742604977165628"></a><a name="p1742604977165628"></a>size_t </p>
<p id="p1839436875165628"><a name="p1839436875165628"></a><a name="p1839436875165628"></a>Returns a string containing error information. </p>
</td>
</tr>
</tbody>
</table>

