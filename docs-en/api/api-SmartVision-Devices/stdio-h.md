# stdio.h<a name="EN-US_TOPIC_0000001054829489"></a>

-   [Overview](#section1433362214165629)
-   [Summary](#section163311508165629)
-   [Typedefs](#typedef-members)
-   [Functions](#func-members)

## **Overview**<a name="section1433362214165629"></a>

**Related Modules:**

[IO](io.md)

**Description:**

Declares common functions used for performing input and output \(I/O\) operations. 

You can use the functions provided in this file to perform the I/O operations required during development. Distinguished by I/O targets, there are standard I/O, file stream I/O, and string I/O. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section163311508165629"></a>

## Typedefs<a name="typedef-members"></a>

<a name="table721746165629"></a>
<table><thead align="left"><tr id="row1722405002165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1163928898165629"><a name="p1163928898165629"></a><a name="p1163928898165629"></a>Typedef Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p148046621165629"><a name="p148046621165629"></a><a name="p148046621165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1232975034165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2117586378165629"><a name="p2117586378165629"></a><a name="p2117586378165629"></a><a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p388615750165629"><a name="p388615750165629"></a><a name="p388615750165629"></a> typedef struct _IO_FILE </p>
<p id="p1449943632165629"><a name="p1449943632165629"></a><a name="p1449943632165629"></a>Struct of file stream. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1011093656165629"></a>
<table><thead align="left"><tr id="row856704785165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p502100954165629"><a name="p502100954165629"></a><a name="p502100954165629"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1294937658165629"><a name="p1294937658165629"></a><a name="p1294937658165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1166112002165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p487752042165629"><a name="p487752042165629"></a><a name="p487752042165629"></a><a href="io.md#ga58386e895d3c07b008c8865b2a9716fb">fopen</a> (const char *__restrict path, const char *__restrict mode)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1694317581165629"><a name="p1694317581165629"></a><a name="p1694317581165629"></a><a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> * </p>
<p id="p1401077596165629"><a name="p1401077596165629"></a><a name="p1401077596165629"></a>Opens the file stored in the specified path based on the given mode. </p>
</td>
</tr>
<tr id="row2102467176165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1926897103165629"><a name="p1926897103165629"></a><a name="p1926897103165629"></a><a href="io.md#gaab336dbfc008a0873046ecd7db043df0">freopen</a> (const char *__restrict path, const char *__restrict mode, <a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *__restrict stream)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p611151286165629"><a name="p611151286165629"></a><a name="p611151286165629"></a><a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> * </p>
<p id="p749093316165629"><a name="p749093316165629"></a><a name="p749093316165629"></a>Opens the file stored in the specified path, and associates the stream by the given stream. </p>
</td>
</tr>
<tr id="row559230143165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p279154592165629"><a name="p279154592165629"></a><a name="p279154592165629"></a><a href="io.md#gac41a0ad4b31be2ad59d8222a0de30bda">fclose</a> (<a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *fd)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1403147376165629"><a name="p1403147376165629"></a><a name="p1403147376165629"></a>int </p>
<p id="p1636015985165629"><a name="p1636015985165629"></a><a name="p1636015985165629"></a>Closes a file based on the specified file descriptor. </p>
</td>
</tr>
<tr id="row1015517195165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p997828903165629"><a name="p997828903165629"></a><a name="p997828903165629"></a><a href="io.md#ga02b13b56a188401119ea4da43c184913">remove</a> (const char *pathname)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p411458094165629"><a name="p411458094165629"></a><a name="p411458094165629"></a>int </p>
<p id="p2038611845165629"><a name="p2038611845165629"></a><a name="p2038611845165629"></a>Deletes a specified file or directory from the file system. </p>
</td>
</tr>
<tr id="row2102565988165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1579979846165629"><a name="p1579979846165629"></a><a name="p1579979846165629"></a><a href="io.md#ga4d4709508ed7604103d77c3fdc5ea4a2">rename</a> (const char *oldpath, const char *newpath)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p796789152165629"><a name="p796789152165629"></a><a name="p796789152165629"></a>int </p>
<p id="p1385475294165629"><a name="p1385475294165629"></a><a name="p1385475294165629"></a>Renames a specified file. </p>
</td>
</tr>
<tr id="row153077293165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p413178353165629"><a name="p413178353165629"></a><a name="p413178353165629"></a><a href="io.md#gafb95de1535a5a185954819539f3c6ca5">feof</a> (<a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *fp)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1080134274165629"><a name="p1080134274165629"></a><a name="p1080134274165629"></a>int </p>
<p id="p1129318414165629"><a name="p1129318414165629"></a><a name="p1129318414165629"></a>Tests the end-of-file indicator for a specified stream. </p>
</td>
</tr>
<tr id="row625976815165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2110953464165629"><a name="p2110953464165629"></a><a name="p2110953464165629"></a><a href="io.md#ga4a98383bb54291c2abede7aa28acf597">ferror</a> (<a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1903232308165629"><a name="p1903232308165629"></a><a name="p1903232308165629"></a>int </p>
<p id="p710867735165629"><a name="p710867735165629"></a><a name="p710867735165629"></a>Tests for the error identifier of a specified file stream. </p>
</td>
</tr>
<tr id="row113155328165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p235649401165629"><a name="p235649401165629"></a><a name="p235649401165629"></a><a href="io.md#gae4459e830d3e2abcf428337a661d9456">fflush</a> (<a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *fp)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1639279450165629"><a name="p1639279450165629"></a><a name="p1639279450165629"></a>int </p>
<p id="p2081094612165629"><a name="p2081094612165629"></a><a name="p2081094612165629"></a>Flushes the output buffer of a specified stream. </p>
</td>
</tr>
<tr id="row2068417642165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p517586528165629"><a name="p517586528165629"></a><a name="p517586528165629"></a><a href="io.md#ga81202d6a15259fbceb71a961a878b01a">clearerr</a> (<a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *fp)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1860710722165629"><a name="p1860710722165629"></a><a name="p1860710722165629"></a>void </p>
<p id="p268802769165629"><a name="p268802769165629"></a><a name="p268802769165629"></a>Resets the error indicators. </p>
</td>
</tr>
<tr id="row568893391165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1320837998165629"><a name="p1320837998165629"></a><a name="p1320837998165629"></a><a href="io.md#gaece5d6e00c239ffd0847d8d2ef65bd57">fseek</a> (<a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *fp, long offset, int whence)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1268500654165629"><a name="p1268500654165629"></a><a name="p1268500654165629"></a>int </p>
<p id="p118933857165629"><a name="p118933857165629"></a><a name="p118933857165629"></a>Changes the position of a specified stream to a new position. </p>
</td>
</tr>
<tr id="row544025592165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1867680900165629"><a name="p1867680900165629"></a><a name="p1867680900165629"></a><a href="io.md#gaae4231ac8066eb54ea1d9d12d551605c">ftell</a> (<a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *fp)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1947740318165629"><a name="p1947740318165629"></a><a name="p1947740318165629"></a>long </p>
<p id="p2103125208165629"><a name="p2103125208165629"></a><a name="p2103125208165629"></a>Obtains the current value of the file position indicator for a specified file stream. </p>
</td>
</tr>
<tr id="row1981588776165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p993793880165629"><a name="p993793880165629"></a><a name="p993793880165629"></a><a href="io.md#gaa0cd401f198d33d9d01a9e8aa4026819">rewind</a> (<a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1047501194165629"><a name="p1047501194165629"></a><a name="p1047501194165629"></a>void </p>
<p id="p608226385165629"><a name="p608226385165629"></a><a name="p608226385165629"></a>Sets the position indicator of a specified stream to the beginning of the file. </p>
</td>
</tr>
<tr id="row436915897165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p621468248165629"><a name="p621468248165629"></a><a name="p621468248165629"></a><a href="io.md#gaf2e2b1a01359f5f7068b61d1dffcdcdd">fgetpos</a> (<a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream, fpos_t *pos)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p933058491165629"><a name="p933058491165629"></a><a name="p933058491165629"></a>int </p>
<p id="p531309512165629"><a name="p531309512165629"></a><a name="p531309512165629"></a>Obtains the current file position of a specified stream and writes it to the <strong id="b1506160031165629"><a name="b1506160031165629"></a><a name="b1506160031165629"></a>pos</strong> parameter. </p>
</td>
</tr>
<tr id="row1737136278165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p705913503165629"><a name="p705913503165629"></a><a name="p705913503165629"></a><a href="io.md#gae47e3f92dd8fc42ce0b6384c03ce6a9b">fsetpos</a> (<a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *fp, const fpos_t *pos)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1083005360165629"><a name="p1083005360165629"></a><a name="p1083005360165629"></a>int </p>
<p id="p1489275551165629"><a name="p1489275551165629"></a><a name="p1489275551165629"></a>Sets the file position indicator for a specified file stream. </p>
</td>
</tr>
<tr id="row535341910165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p955758410165629"><a name="p955758410165629"></a><a name="p955758410165629"></a><a href="io.md#ga091b3f41bdd6984d63ea48d87a62bfd2">fread</a> (void *__restrict ptr, size_t size, size_t nmemb, <a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *__restrict stream)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p43858487165629"><a name="p43858487165629"></a><a name="p43858487165629"></a>size_t </p>
<p id="p964940528165629"><a name="p964940528165629"></a><a name="p964940528165629"></a>Reads data from a specified stream. </p>
</td>
</tr>
<tr id="row1733517463165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p829502273165629"><a name="p829502273165629"></a><a name="p829502273165629"></a><a href="io.md#gaf86a4505e5de39a100f7ea828377b585">fwrite</a> (const void *__restrict ptr, size_t size, size_t nmemb, <a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *__restrict stream)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1596563787165629"><a name="p1596563787165629"></a><a name="p1596563787165629"></a>size_t </p>
<p id="p1969590605165629"><a name="p1969590605165629"></a><a name="p1969590605165629"></a>Writes data to a specified stream. </p>
</td>
</tr>
<tr id="row1587231744165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1874161482165629"><a name="p1874161482165629"></a><a name="p1874161482165629"></a><a href="io.md#gad5a0ea2c21a23a380b7c30fe35fa9456">getc</a> (<a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1690604582165629"><a name="p1690604582165629"></a><a name="p1690604582165629"></a>int </p>
<p id="p1073190023165629"><a name="p1073190023165629"></a><a name="p1073190023165629"></a>Reads a character from a specified file stream. </p>
</td>
</tr>
<tr id="row2084623365165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p235461842165629"><a name="p235461842165629"></a><a name="p235461842165629"></a><a href="io.md#ga3e29caa20f7cffe18f410f01278905a8">getchar</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p897400738165629"><a name="p897400738165629"></a><a name="p897400738165629"></a>int </p>
<p id="p1311180196165629"><a name="p1311180196165629"></a><a name="p1311180196165629"></a>Obtains the next character from the standard input (stdin). </p>
</td>
</tr>
<tr id="row1864494308165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p614200231165629"><a name="p614200231165629"></a><a name="p614200231165629"></a><a href="io.md#ga54efa95b6d5b41adec98e5b8a1a9f27b">ungetc</a> (int c, <a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1264114747165629"><a name="p1264114747165629"></a><a name="p1264114747165629"></a>int </p>
<p id="p1482522104165629"><a name="p1482522104165629"></a><a name="p1482522104165629"></a>Pushes a character back into a specified file stream. </p>
</td>
</tr>
<tr id="row53049012165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1996871382165629"><a name="p1996871382165629"></a><a name="p1996871382165629"></a><a href="io.md#gabe6299d5823dd023e610aaa619735a3f">fputc</a> (int c, <a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p24485421165629"><a name="p24485421165629"></a><a name="p24485421165629"></a>int </p>
<p id="p1755756710165629"><a name="p1755756710165629"></a><a name="p1755756710165629"></a>Writes a character into the position pointed to by a specified stream. </p>
</td>
</tr>
<tr id="row1826489992165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1854246833165629"><a name="p1854246833165629"></a><a name="p1854246833165629"></a><a href="io.md#ga38f980218f04ebdddcdcd1b77e1cf6b1">putc</a> (int c, <a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p511492679165629"><a name="p511492679165629"></a><a name="p511492679165629"></a>int </p>
<p id="p727764130165629"><a name="p727764130165629"></a><a name="p727764130165629"></a>Writes a character to a specified file stream. </p>
</td>
</tr>
<tr id="row1705153769165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2103169748165629"><a name="p2103169748165629"></a><a name="p2103169748165629"></a><a href="io.md#gaf4de2514b7778805db3815e8dd6cf09a">putchar</a> (int c)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1898952272165629"><a name="p1898952272165629"></a><a name="p1898952272165629"></a>int </p>
<p id="p263065399165629"><a name="p263065399165629"></a><a name="p263065399165629"></a>Writes a character into the standard output (stdout). </p>
</td>
</tr>
<tr id="row1466324520165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2046249184165629"><a name="p2046249184165629"></a><a name="p2046249184165629"></a><a href="io.md#ga2b3df0e66b41edab3c039191fe6cc4f9">fgets</a> (char *s, int size, <a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1800008188165629"><a name="p1800008188165629"></a><a name="p1800008188165629"></a>char * </p>
<p id="p2129836975165629"><a name="p2129836975165629"></a><a name="p2129836975165629"></a>Reads a line of characters from a specified file stream and stores it into the string pointed to by <strong id="b1940672576165629"><a name="b1940672576165629"></a><a name="b1940672576165629"></a>s</strong>. </p>
</td>
</tr>
<tr id="row1810300544165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1908436660165629"><a name="p1908436660165629"></a><a name="p1908436660165629"></a><a href="io.md#gaab85b30d68ce9d9e0475e0f51bf610b1">gets</a> (char *s)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p296985868165629"><a name="p296985868165629"></a><a name="p296985868165629"></a>char * </p>
<p id="p624231235165629"><a name="p624231235165629"></a><a name="p624231235165629"></a>Reads a line of characters from the stdin and stores it in the buffer. </p>
</td>
</tr>
<tr id="row1085706684165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p254665834165629"><a name="p254665834165629"></a><a name="p254665834165629"></a><a href="io.md#ga68236e664c1f0da049b25fba1c1695f6">fputs</a> (const char *s, <a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1050306933165629"><a name="p1050306933165629"></a><a name="p1050306933165629"></a>int </p>
<p id="p1098587393165629"><a name="p1098587393165629"></a><a name="p1098587393165629"></a>Writes a character string (excluding the terminating null character) to a specified file stream. </p>
</td>
</tr>
<tr id="row610674015165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1412630765165629"><a name="p1412630765165629"></a><a name="p1412630765165629"></a><a href="io.md#gad41876f99f190c7488e64ef39c50a23f">puts</a> (const char *s)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1610858784165629"><a name="p1610858784165629"></a><a name="p1610858784165629"></a>int </p>
<p id="p1995395577165629"><a name="p1995395577165629"></a><a name="p1995395577165629"></a>Writes a character string and appends a new-line character to the stdout. </p>
</td>
</tr>
<tr id="row1057512075165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1570140141165629"><a name="p1570140141165629"></a><a name="p1570140141165629"></a><a href="io.md#ga98631211a4a8aee62f572375d5b637be">printf</a> (const char *format,...)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1030943106165629"><a name="p1030943106165629"></a><a name="p1030943106165629"></a>int </p>
<p id="p1814144089165629"><a name="p1814144089165629"></a><a name="p1814144089165629"></a>Formats arguments based on <strong id="b1720848132165629"><a name="b1720848132165629"></a><a name="b1720848132165629"></a>format</strong> and prints formatted data to the stdout. </p>
</td>
</tr>
<tr id="row1506408316165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p408892891165629"><a name="p408892891165629"></a><a name="p408892891165629"></a><a href="io.md#gad9291335f34e874c8431285d705bc3aa">fprintf</a> (<a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream, const char *format,...)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2028902824165629"><a name="p2028902824165629"></a><a name="p2028902824165629"></a>int </p>
<p id="p289301827165629"><a name="p289301827165629"></a><a name="p289301827165629"></a>Formats arguments based on <strong id="b1697166663165629"><a name="b1697166663165629"></a><a name="b1697166663165629"></a>format</strong> and prints formatted data to a specified file stream. </p>
</td>
</tr>
<tr id="row1569016107165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p722439659165629"><a name="p722439659165629"></a><a name="p722439659165629"></a><a href="io.md#ga3082155ec11e7229f7a20439b31a169e">sprintf</a> (char *str, const char *format,...)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1242010097165629"><a name="p1242010097165629"></a><a name="p1242010097165629"></a>int </p>
<p id="p1493281331165629"><a name="p1493281331165629"></a><a name="p1493281331165629"></a>Prints formatted data from a variable argument list to a specified string. </p>
</td>
</tr>
<tr id="row2120370336165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1821014848165629"><a name="p1821014848165629"></a><a name="p1821014848165629"></a><a href="io.md#gad76145a6edfc98981ded8815a760e0cd">snprintf</a> (char *str, size_t size, const char *format,...)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1250100737165629"><a name="p1250100737165629"></a><a name="p1250100737165629"></a>int </p>
<p id="p623132027165629"><a name="p623132027165629"></a><a name="p623132027165629"></a>Prints formatted data of a maximum of <strong id="b983317054165629"><a name="b983317054165629"></a><a name="b983317054165629"></a>size</strong> bytes from a variable argument list to a specified string. </p>
</td>
</tr>
<tr id="row1237576385165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1594421315165629"><a name="p1594421315165629"></a><a name="p1594421315165629"></a><a href="io.md#gaa715ef816dc040c8b367fde4ba84d6f3">vprintf</a> (const char *format, va_list ap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p99030259165629"><a name="p99030259165629"></a><a name="p99030259165629"></a>int </p>
<p id="p1604382000165629"><a name="p1604382000165629"></a><a name="p1604382000165629"></a>Prints formatted data from a variable argument list to the stdout. </p>
</td>
</tr>
<tr id="row1131067863165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p928715374165629"><a name="p928715374165629"></a><a name="p928715374165629"></a><a href="io.md#gad80f05917df38df3a5e1817498d67c26">vfprintf</a> (<a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream, const char *format, va_list ap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1626804217165629"><a name="p1626804217165629"></a><a name="p1626804217165629"></a>int </p>
<p id="p1161562628165629"><a name="p1161562628165629"></a><a name="p1161562628165629"></a>Prints formatted data from a variable argument list to a specified file stream. </p>
</td>
</tr>
<tr id="row1934563997165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1227817285165629"><a name="p1227817285165629"></a><a name="p1227817285165629"></a><a href="io.md#gaab3db67c98c32122fcb3d076d4207bbc">vsprintf</a> (char *str, const char *format, va_list ap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1581403527165629"><a name="p1581403527165629"></a><a name="p1581403527165629"></a>int </p>
<p id="p2114336053165629"><a name="p2114336053165629"></a><a name="p2114336053165629"></a>Prints formatted data from a variable argument list to a specified string. </p>
</td>
</tr>
<tr id="row697195482165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p682903268165629"><a name="p682903268165629"></a><a name="p682903268165629"></a><a href="io.md#ga2cadafbeb2d6e0d5781f6e5106d41fc2">vsnprintf</a> (char *str, size_t size, const char *format, va_list ap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1523262186165629"><a name="p1523262186165629"></a><a name="p1523262186165629"></a>int </p>
<p id="p885870894165629"><a name="p885870894165629"></a><a name="p885870894165629"></a>Prints formatted data of a maximum of <strong id="b2073702249165629"><a name="b2073702249165629"></a><a name="b2073702249165629"></a>size</strong> bytes from a variable argument list to a specified string. </p>
</td>
</tr>
<tr id="row1948779013165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p78264972165629"><a name="p78264972165629"></a><a name="p78264972165629"></a><a href="io.md#ga5c48433db9c04031772d5b36e6c4411d">scanf</a> (const char *format,...)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p938195878165629"><a name="p938195878165629"></a><a name="p938195878165629"></a>int </p>
<p id="p1534986526165629"><a name="p1534986526165629"></a><a name="p1534986526165629"></a>Reads formatted data from the stdin and stores the data to the additional arguments based on <strong id="b1108486012165629"><a name="b1108486012165629"></a><a name="b1108486012165629"></a>format</strong>. </p>
</td>
</tr>
<tr id="row1182464042165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1577701190165629"><a name="p1577701190165629"></a><a name="p1577701190165629"></a><a href="io.md#gae902a7b8796799a6e076f07e9d7de045">fscanf</a> (<a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream, const char *format,...)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p163643537165629"><a name="p163643537165629"></a><a name="p163643537165629"></a>int </p>
<p id="p1215842295165629"><a name="p1215842295165629"></a><a name="p1215842295165629"></a>Reads formatted data from a specified file stream and stores it based on <strong id="b226783316165629"><a name="b226783316165629"></a><a name="b226783316165629"></a>format</strong> into the locations pointed to by the variable arguments. </p>
</td>
</tr>
<tr id="row1002329220165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1799936046165629"><a name="p1799936046165629"></a><a name="p1799936046165629"></a><a href="io.md#gaec1e54556dca3bd701d44395d34818dd">sscanf</a> (const char *str, const char *format,...)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1165862782165629"><a name="p1165862782165629"></a><a name="p1165862782165629"></a>int </p>
<p id="p77185291165629"><a name="p77185291165629"></a><a name="p77185291165629"></a>Reads data from a character string pointed to by <strong id="b1107269997165629"><a name="b1107269997165629"></a><a name="b1107269997165629"></a>str</strong> and stores it based on <strong id="b1992581388165629"><a name="b1992581388165629"></a><a name="b1992581388165629"></a>format</strong> into the locations pointed to by the variable arguments. </p>
</td>
</tr>
<tr id="row1503208573165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p708417121165629"><a name="p708417121165629"></a><a name="p708417121165629"></a><a href="io.md#ga40250d63904acd3e898061c9eab6ead3">vscanf</a> (const char *format, va_list ap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p739361012165629"><a name="p739361012165629"></a><a name="p739361012165629"></a>int </p>
<p id="p1826401784165629"><a name="p1826401784165629"></a><a name="p1826401784165629"></a>Reads data from the stdin and stores it based on <strong id="b1536929719165629"><a name="b1536929719165629"></a><a name="b1536929719165629"></a>format</strong> into the locations pointed to by the elements in the variable argument list identified by <strong id="b1768852231165629"><a name="b1768852231165629"></a><a name="b1768852231165629"></a>ap</strong>. </p>
</td>
</tr>
<tr id="row821586960165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p838729644165629"><a name="p838729644165629"></a><a name="p838729644165629"></a><a href="io.md#gabdd32e401e37c9d954f3f0a6907500d9">vfscanf</a> (<a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream, const char *format, va_list ap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p933233841165629"><a name="p933233841165629"></a><a name="p933233841165629"></a>int </p>
<p id="p392225590165629"><a name="p392225590165629"></a><a name="p392225590165629"></a>Reads data from a specified file stream and stores it based on <strong id="b653710745165629"><a name="b653710745165629"></a><a name="b653710745165629"></a>format</strong> into the locations pointed to by the elements in the variable argument list identified by <strong id="b581035570165629"><a name="b581035570165629"></a><a name="b581035570165629"></a>ap</strong>. </p>
</td>
</tr>
<tr id="row1796034322165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p698080694165629"><a name="p698080694165629"></a><a name="p698080694165629"></a><a href="io.md#gab1c4552aba80fe03c9b45fe27f4331ad">vsscanf</a> (const char *str, const char *format, va_list ap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p158622054165629"><a name="p158622054165629"></a><a name="p158622054165629"></a>int </p>
<p id="p1520324204165629"><a name="p1520324204165629"></a><a name="p1520324204165629"></a>Reads data from a specified string and stores it based on <strong id="b1193378495165629"><a name="b1193378495165629"></a><a name="b1193378495165629"></a>format</strong> into the locations pointed to by the elements in the variable argument list identified by <strong id="b437323894165629"><a name="b437323894165629"></a><a name="b437323894165629"></a>ap</strong>. </p>
</td>
</tr>
<tr id="row1473106467165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1718560393165629"><a name="p1718560393165629"></a><a name="p1718560393165629"></a><a href="io.md#ga80b37b56a5a42139dccaef56da4bf82a">perror</a> (const char *msg)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p501193787165629"><a name="p501193787165629"></a><a name="p501193787165629"></a>void </p>
<p id="p967431880165629"><a name="p967431880165629"></a><a name="p967431880165629"></a>Prints the last error occurred during a call to a system or library function to the standard error output stream (stderr). </p>
</td>
</tr>
<tr id="row1720325013165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p832945036165629"><a name="p832945036165629"></a><a name="p832945036165629"></a><a href="io.md#gaf691eb990d669a9edec8a9ec721ce3bc">setvbuf</a> (<a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream, char *buf, int mode, size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p449236333165629"><a name="p449236333165629"></a><a name="p449236333165629"></a>int </p>
<p id="p644989339165629"><a name="p644989339165629"></a><a name="p644989339165629"></a>Sets the mode and size of the buffer for a specified stream. </p>
</td>
</tr>
<tr id="row1935755283165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p643637484165629"><a name="p643637484165629"></a><a name="p643637484165629"></a><a href="io.md#ga36d24924e1acc69f9c3ce49a832615fe">setbuf</a> (<a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream, char *buf)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1491569375165629"><a name="p1491569375165629"></a><a name="p1491569375165629"></a>void </p>
<p id="p939580739165629"><a name="p939580739165629"></a><a name="p939580739165629"></a>Sets a buffer to be used by a specified stream. </p>
</td>
</tr>
<tr id="row717409320165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1444904850165629"><a name="p1444904850165629"></a><a name="p1444904850165629"></a><a href="io.md#ga6b2efc6515c53ab5f0c9800c35f65789">fmemopen</a> (void *buf, size_t size, const char *mode)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1081527925165629"><a name="p1081527925165629"></a><a name="p1081527925165629"></a><a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> * </p>
<p id="p1839629809165629"><a name="p1839629809165629"></a><a name="p1839629809165629"></a>Opens a memory stream that allows the access mode specified by <strong id="b748717626165629"><a name="b748717626165629"></a><a name="b748717626165629"></a>mode</strong>. </p>
</td>
</tr>
<tr id="row1041216228165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1691723355165629"><a name="p1691723355165629"></a><a name="p1691723355165629"></a><a href="io.md#gac7250554d80d31f4d8ad316c4c3c3c85">open_memstream</a> (char **ptr, size_t *size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p192690090165629"><a name="p192690090165629"></a><a name="p192690090165629"></a><a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> * </p>
<p id="p687137435165629"><a name="p687137435165629"></a><a name="p687137435165629"></a>Opens a stream for writing to a specified buffer. </p>
</td>
</tr>
<tr id="row1784623469165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1572300645165629"><a name="p1572300645165629"></a><a name="p1572300645165629"></a><a href="io.md#ga03681b8592bba6fe02941b9abc182808">fileno</a> (<a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *fp)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1650524971165629"><a name="p1650524971165629"></a><a name="p1650524971165629"></a>int </p>
<p id="p654032784165629"><a name="p654032784165629"></a><a name="p654032784165629"></a>Obtains the file descriptor of a specified file stream. </p>
</td>
</tr>
<tr id="row1151378457165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p958268996165629"><a name="p958268996165629"></a><a name="p958268996165629"></a><a href="io.md#ga6926f47b76b028f112045fbe7ced4115">fseeko</a> (<a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *fp, off_t offset, int whence)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1997169725165629"><a name="p1997169725165629"></a><a name="p1997169725165629"></a>int </p>
<p id="p645082921165629"><a name="p645082921165629"></a><a name="p645082921165629"></a>Sets the position of the next input or output operation on a specified file stream. </p>
</td>
</tr>
<tr id="row106650560165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2037808082165629"><a name="p2037808082165629"></a><a name="p2037808082165629"></a><a href="io.md#ga5f52ea043b9a2aa4d8cc92d674a2117b">ftello</a> (<a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *fp)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2116827325165629"><a name="p2116827325165629"></a><a name="p2116827325165629"></a>off_t </p>
<p id="p598498357165629"><a name="p598498357165629"></a><a name="p598498357165629"></a>Obtains the current value of the file position indicator for a specified file stream. </p>
</td>
</tr>
<tr id="row1559398528165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p568829705165629"><a name="p568829705165629"></a><a name="p568829705165629"></a><a href="io.md#ga5fe0fc8fe920b640d488856c5ca43cb5">dprintf</a> (int fd, const char *format,...)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p631603572165629"><a name="p631603572165629"></a><a name="p631603572165629"></a>int </p>
<p id="p860285983165629"><a name="p860285983165629"></a><a name="p860285983165629"></a>Prints formatted data to a specified file. </p>
</td>
</tr>
<tr id="row512788089165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p79235101165629"><a name="p79235101165629"></a><a name="p79235101165629"></a><a href="io.md#ga0d0a950c2b4e6fba795cb7d8f2e8b8b8">vdprintf</a> (int fd, const char *format, va_list ap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1914455294165629"><a name="p1914455294165629"></a><a name="p1914455294165629"></a>int </p>
<p id="p968363164165629"><a name="p968363164165629"></a><a name="p968363164165629"></a>Prints formatted data from a variable argument list to a specified file. </p>
</td>
</tr>
<tr id="row93485724165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2012668368165629"><a name="p2012668368165629"></a><a name="p2012668368165629"></a><a href="io.md#gab486b89691678e4873ec8b1b15c2678a">ftrylockfile</a> (<a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *filehandle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2136030868165629"><a name="p2136030868165629"></a><a name="p2136030868165629"></a>int </p>
<p id="p1773161573165629"><a name="p1773161573165629"></a><a name="p1773161573165629"></a>Locks a specified file. </p>
</td>
</tr>
<tr id="row1861096221165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2141205023165629"><a name="p2141205023165629"></a><a name="p2141205023165629"></a><a href="io.md#ga4f016c54ff86ca62454417bb7b32ab11">funlockfile</a> (<a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *filehandle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1835335364165629"><a name="p1835335364165629"></a><a name="p1835335364165629"></a>void </p>
<p id="p949390484165629"><a name="p949390484165629"></a><a name="p949390484165629"></a>Unlocks a specified file. </p>
</td>
</tr>
<tr id="row1377018667165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1397003551165629"><a name="p1397003551165629"></a><a name="p1397003551165629"></a><a href="io.md#ga169f9b7e933ba56156885e30f7263b28">getc_unlocked</a> (<a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1779440576165629"><a name="p1779440576165629"></a><a name="p1779440576165629"></a>int </p>
<p id="p1573166906165629"><a name="p1573166906165629"></a><a name="p1573166906165629"></a>Obtains a character from a specified file stream without locking the file stream or checking whether it is locked. </p>
</td>
</tr>
<tr id="row1859591226165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1031191174165629"><a name="p1031191174165629"></a><a name="p1031191174165629"></a><a href="io.md#gafef7e39f2376c63728163cd5ccfbe99e">getchar_unlocked</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p697062314165629"><a name="p697062314165629"></a><a name="p697062314165629"></a>int </p>
<p id="p1704594680165629"><a name="p1704594680165629"></a><a name="p1704594680165629"></a>Obtains the next character from stdin. </p>
</td>
</tr>
<tr id="row1752592169165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1180855786165629"><a name="p1180855786165629"></a><a name="p1180855786165629"></a><a href="io.md#ga340b21ecb337abb08905095e673672f6">putc_unlocked</a> (int c, <a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1200479308165629"><a name="p1200479308165629"></a><a name="p1200479308165629"></a>int </p>
<p id="p1544457816165629"><a name="p1544457816165629"></a><a name="p1544457816165629"></a>Writes a character to a specified file stream with the thread remains unlocked. </p>
</td>
</tr>
<tr id="row1148782789165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p597068686165629"><a name="p597068686165629"></a><a name="p597068686165629"></a><a href="io.md#ga07ff061a8fed45cdedbecdd899b5fdb1">putchar_unlocked</a> (int c)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2007157687165629"><a name="p2007157687165629"></a><a name="p2007157687165629"></a>int </p>
<p id="p875059948165629"><a name="p875059948165629"></a><a name="p875059948165629"></a>Writes a character to the stdout with the thread remains unlocked. </p>
</td>
</tr>
<tr id="row1040696632165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1902768351165629"><a name="p1902768351165629"></a><a name="p1902768351165629"></a><a href="io.md#gab87a24b4c09e8fc3712a6d6090bfd371">getdelim</a> (char **lineptr, size_t *n, int delim, <a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p480062186165629"><a name="p480062186165629"></a><a name="p480062186165629"></a>ssize_t </p>
<p id="p422067786165629"><a name="p422067786165629"></a><a name="p422067786165629"></a>Reads an entire line from a specified file stream. </p>
</td>
</tr>
<tr id="row268761018165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1066264844165629"><a name="p1066264844165629"></a><a name="p1066264844165629"></a><a href="io.md#gaaf07c1bbc2aa081a54bdd66f0e152312">getline</a> (char **lineptr, size_t *n, <a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1128940074165629"><a name="p1128940074165629"></a><a name="p1128940074165629"></a>ssize_t </p>
<p id="p907375930165629"><a name="p907375930165629"></a><a name="p907375930165629"></a>Reads an entire line from a specified file stream. </p>
</td>
</tr>
<tr id="row1244101444165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1539040548165629"><a name="p1539040548165629"></a><a name="p1539040548165629"></a><a href="io.md#ga44dcf948b2c1dc3356d2937635a27839">tempnam</a> (const char *dir, const char *prefix)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p57381363165629"><a name="p57381363165629"></a><a name="p57381363165629"></a>char * </p>
<p id="p1457521331165629"><a name="p1457521331165629"></a><a name="p1457521331165629"></a>Creates a temporary file with a unique file name. </p>
</td>
</tr>
<tr id="row1886531884165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1113123100165629"><a name="p1113123100165629"></a><a name="p1113123100165629"></a><a href="io.md#ga53a57437279b4ed57b7f116dfc9cbbcc">setbuffer</a> (<a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *f, char *buf, size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p369372825165629"><a name="p369372825165629"></a><a name="p369372825165629"></a>void </p>
<p id="p248221843165629"><a name="p248221843165629"></a><a name="p248221843165629"></a>Sets the buffer for a specified file stream. </p>
</td>
</tr>
<tr id="row1328638917165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1833771834165629"><a name="p1833771834165629"></a><a name="p1833771834165629"></a><a href="io.md#ga2e13e101d5a57cfccf1bab51f8768a5d">setlinebuf</a> (<a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *f)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1118374180165629"><a name="p1118374180165629"></a><a name="p1118374180165629"></a>void </p>
<p id="p1422660204165629"><a name="p1422660204165629"></a><a name="p1422660204165629"></a>Sets the linear buffer for a specified file stream. </p>
</td>
</tr>
<tr id="row1723175796165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p469502341165629"><a name="p469502341165629"></a><a name="p469502341165629"></a><a href="io.md#gab11a990e4f8863a1e7736e3c1d430092">fgetc</a> (<a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1744220476165629"><a name="p1744220476165629"></a><a name="p1744220476165629"></a>int </p>
<p id="p1562208662165629"><a name="p1562208662165629"></a><a name="p1562208662165629"></a>Reads a character from the file pointed to by <strong id="b67204389165629"><a name="b67204389165629"></a><a name="b67204389165629"></a>stream</strong>. </p>
</td>
</tr>
<tr id="row176359073165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p156512010165629"><a name="p156512010165629"></a><a name="p156512010165629"></a><a href="io.md#ga9b8e6d63482eb1fe38f3eb9d7fc9bd8e">fgetc_unlocked</a> (<a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p709032059165629"><a name="p709032059165629"></a><a name="p709032059165629"></a>int </p>
<p id="p24372850165629"><a name="p24372850165629"></a><a name="p24372850165629"></a>Reads a character from the file pointed to by <strong id="b648095958165629"><a name="b648095958165629"></a><a name="b648095958165629"></a>stream</strong> with the thread remains unlocked. </p>
</td>
</tr>
<tr id="row2094498526165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1646447571165629"><a name="p1646447571165629"></a><a name="p1646447571165629"></a><a href="io.md#gab8680ff3f49f3fe7ce0fb78b4cb8394c">fputc_unlocked</a> (int c, <a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1549648462165629"><a name="p1549648462165629"></a><a name="p1549648462165629"></a>int </p>
<p id="p49652701165629"><a name="p49652701165629"></a><a name="p49652701165629"></a>Writes a character to the file stream pointed to by <strong id="b1273184754165629"><a name="b1273184754165629"></a><a name="b1273184754165629"></a>stream</strong> at the current position. </p>
</td>
</tr>
<tr id="row1631348069165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1791698552165629"><a name="p1791698552165629"></a><a name="p1791698552165629"></a><a href="io.md#ga089fd72e6218cf6805c8fc21123d3d5f">ferror_unlocked</a> (<a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1926184418165629"><a name="p1926184418165629"></a><a name="p1926184418165629"></a>int </p>
<p id="p674210184165629"><a name="p674210184165629"></a><a name="p674210184165629"></a>Tests for the error identifier of a specified file stream. </p>
</td>
</tr>
<tr id="row284352949165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1053026646165629"><a name="p1053026646165629"></a><a name="p1053026646165629"></a><a href="io.md#ga6d475ead5d1f35e3f14423a99ef3a992">getw</a> (<a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p732191557165629"><a name="p732191557165629"></a><a name="p732191557165629"></a>int </p>
<p id="p2029328372165629"><a name="p2029328372165629"></a><a name="p2029328372165629"></a>Reads a word (an int value) from a specified file stream. </p>
</td>
</tr>
<tr id="row1207151545165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p358547463165629"><a name="p358547463165629"></a><a name="p358547463165629"></a><a href="io.md#gae3a2f96dac9fa87b964b69ff6d5cce46">putw</a> (int w, <a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p565164955165629"><a name="p565164955165629"></a><a name="p565164955165629"></a>int </p>
<p id="p1942402735165629"><a name="p1942402735165629"></a><a name="p1942402735165629"></a>Writes a word (an int value) to a specified file stream. </p>
</td>
</tr>
<tr id="row1609074663165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p176117107165629"><a name="p176117107165629"></a><a name="p176117107165629"></a><a href="io.md#ga8e6fe2fcd5eaa8e2d146a50eeaae5b40">fgetln</a> (<a href="io.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream, size_t *len)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1833347918165629"><a name="p1833347918165629"></a><a name="p1833347918165629"></a>char * </p>
<p id="p1812987354165629"><a name="p1812987354165629"></a><a name="p1812987354165629"></a>Reads a line of data from the current position of a specified file stream. </p>
</td>
</tr>
<tr id="row2033019224165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1262740829165629"><a name="p1262740829165629"></a><a name="p1262740829165629"></a><a href="io.md#ga1af9acc6b6efdca3576cb8223d95f401">asprintf</a> (char **strp, const char *fmt,...)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p408087046165629"><a name="p408087046165629"></a><a name="p408087046165629"></a>int </p>
<p id="p1658547000165629"><a name="p1658547000165629"></a><a name="p1658547000165629"></a>Prints formatted data to a specified character string. </p>
</td>
</tr>
<tr id="row1023183079165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p588581332165629"><a name="p588581332165629"></a><a name="p588581332165629"></a><a href="io.md#ga5ec7fd90ebe6015636bce974c192c86a">vasprintf</a> (char **strp, const char *fmt, va_list ap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1091400117165629"><a name="p1091400117165629"></a><a name="p1091400117165629"></a>int </p>
<p id="p1178361509165629"><a name="p1178361509165629"></a><a name="p1178361509165629"></a>Prints formatted data from a variable argument list to a specified character string. </p>
</td>
</tr>
</tbody>
</table>

