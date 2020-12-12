# IO<a name="ZH-CN_TOPIC_0000001054909424"></a>

-   [Overview](#section1444219423165622)
-   [Summary](#section101471515165622)
-   [Files](#files)
-   [Data Structures](#nested-classes)
-   [Macros](#define-members)
-   [Typedefs](#typedef-members)
-   [Functions](#func-members)
-   [Details](#section611262313165622)
-   [Macro Definition](#section1524028957165622)
-   [FD\_CLR](#ga60efc4a969e971f91b7a73bcace62e58)
-   [FD\_ISSET](#ga99a3a0e4d7d1d3eb7be68f37554c0a30)
-   [FD\_SET](#gaa7701be461ce602ff7043cbd898a0c53)
-   [FD\_ZERO](#ga92ab86a10f942411365b9078833559f0)
-   [Function](#section398272795165622)
-   [asprintf\(\)](#ga1af9acc6b6efdca3576cb8223d95f401)
-   [clearerr\(\)](#ga81202d6a15259fbceb71a961a878b01a)
-   [dprintf\(\)](#ga5fe0fc8fe920b640d488856c5ca43cb5)
-   [err\(\)](#gaa6b66a9a8eb4be40e4424a4dc92ae056)
-   [errx\(\)](#gaeaca83913c785b95d6c50f35207ff739)
-   [fclose\(\)](#gac41a0ad4b31be2ad59d8222a0de30bda)
-   [feof\(\)](#gafb95de1535a5a185954819539f3c6ca5)
-   [ferror\(\)](#ga4a98383bb54291c2abede7aa28acf597)
-   [ferror\_unlocked\(\)](#ga089fd72e6218cf6805c8fc21123d3d5f)
-   [fflush\(\)](#gae4459e830d3e2abcf428337a661d9456)
-   [fgetc\(\)](#gab11a990e4f8863a1e7736e3c1d430092)
-   [fgetc\_unlocked\(\)](#ga9b8e6d63482eb1fe38f3eb9d7fc9bd8e)
-   [fgetln\(\)](#ga8e6fe2fcd5eaa8e2d146a50eeaae5b40)
-   [fgetpos\(\)](#gaf2e2b1a01359f5f7068b61d1dffcdcdd)
-   [fgets\(\)](#ga2b3df0e66b41edab3c039191fe6cc4f9)
-   [fileno\(\)](#ga03681b8592bba6fe02941b9abc182808)
-   [fmemopen\(\)](#ga6b2efc6515c53ab5f0c9800c35f65789)
-   [fopen\(\)](#ga58386e895d3c07b008c8865b2a9716fb)
-   [fprintf\(\)](#gad9291335f34e874c8431285d705bc3aa)
-   [fputc\(\)](#gabe6299d5823dd023e610aaa619735a3f)
-   [fputc\_unlocked\(\)](#gab8680ff3f49f3fe7ce0fb78b4cb8394c)
-   [fputs\(\)](#ga68236e664c1f0da049b25fba1c1695f6)
-   [fread\(\)](#ga091b3f41bdd6984d63ea48d87a62bfd2)
-   [freopen\(\)](#gaab336dbfc008a0873046ecd7db043df0)
-   [fscanf\(\)](#gae902a7b8796799a6e076f07e9d7de045)
-   [fseek\(\)](#gaece5d6e00c239ffd0847d8d2ef65bd57)
-   [fseeko\(\)](#ga6926f47b76b028f112045fbe7ced4115)
-   [fsetpos\(\)](#gae47e3f92dd8fc42ce0b6384c03ce6a9b)
-   [ftell\(\)](#gaae4231ac8066eb54ea1d9d12d551605c)
-   [ftello\(\)](#ga5f52ea043b9a2aa4d8cc92d674a2117b)
-   [ftrylockfile\(\)](#gab486b89691678e4873ec8b1b15c2678a)
-   [funlockfile\(\)](#ga4f016c54ff86ca62454417bb7b32ab11)
-   [fwrite\(\)](#gaf86a4505e5de39a100f7ea828377b585)
-   [getc\(\)](#gad5a0ea2c21a23a380b7c30fe35fa9456)
-   [getc\_unlocked\(\)](#ga169f9b7e933ba56156885e30f7263b28)
-   [getchar\(\)](#ga3e29caa20f7cffe18f410f01278905a8)
-   [getchar\_unlocked\(\)](#gafef7e39f2376c63728163cd5ccfbe99e)
-   [getdelim\(\)](#gab87a24b4c09e8fc3712a6d6090bfd371)
-   [getline\(\)](#gaaf07c1bbc2aa081a54bdd66f0e152312)
-   [gets\(\)](#gaab85b30d68ce9d9e0475e0f51bf610b1)
-   [getw\(\)](#ga6d475ead5d1f35e3f14423a99ef3a992)
-   [iconv\(\)](#gab7c1300a663def659ce6d4a01076c39d)
-   [iconv\_close\(\)](#ga062da5f802d9e274a8702f11921e691b)
-   [iconv\_open\(\)](#ga934548ab8aaae237ac5cce0ed0b3edec)
-   [open\_memstream\(\)](#gac7250554d80d31f4d8ad316c4c3c3c85)
-   [perror\(\)](#ga80b37b56a5a42139dccaef56da4bf82a)
-   [poll\(\)](#gab7fc0f6be5f13c81de180c1288ba3b6f)
-   [preadv\(\)](#ga94adc8dd94a6bdaaa9cf4d9f388418b3)
-   [printf\(\)](#ga98631211a4a8aee62f572375d5b637be)
-   [putc\(\)](#ga38f980218f04ebdddcdcd1b77e1cf6b1)
-   [putc\_unlocked\(\)](#ga340b21ecb337abb08905095e673672f6)
-   [putchar\(\)](#gaf4de2514b7778805db3815e8dd6cf09a)
-   [putchar\_unlocked\(\)](#ga07ff061a8fed45cdedbecdd899b5fdb1)
-   [puts\(\)](#gad41876f99f190c7488e64ef39c50a23f)
-   [putw\(\)](#gae3a2f96dac9fa87b964b69ff6d5cce46)
-   [pwritev\(\)](#ga3de6f9331d6bb930e748bb61860edbd6)
-   [readv\(\)](#gaa1952d693ed3c43292566e643ceb9858)
-   [remove\(\)](#ga02b13b56a188401119ea4da43c184913)
-   [rename\(\)](#ga4d4709508ed7604103d77c3fdc5ea4a2)
-   [rewind\(\)](#gaa0cd401f198d33d9d01a9e8aa4026819)
-   [scanf\(\)](#ga5c48433db9c04031772d5b36e6c4411d)
-   [select\(\)](#gaf916439863bed6ba92594e390c227c7e)
-   [setbuf\(\)](#ga36d24924e1acc69f9c3ce49a832615fe)
-   [setbuffer\(\)](#ga53a57437279b4ed57b7f116dfc9cbbcc)
-   [setlinebuf\(\)](#ga2e13e101d5a57cfccf1bab51f8768a5d)
-   [setvbuf\(\)](#gaf691eb990d669a9edec8a9ec721ce3bc)
-   [snprintf\(\)](#gad76145a6edfc98981ded8815a760e0cd)
-   [sprintf\(\)](#ga3082155ec11e7229f7a20439b31a169e)
-   [sscanf\(\)](#gaec1e54556dca3bd701d44395d34818dd)
-   [tempnam\(\)](#ga44dcf948b2c1dc3356d2937635a27839)
-   [ungetc\(\)](#ga54efa95b6d5b41adec98e5b8a1a9f27b)
-   [vasprintf\(\)](#ga5ec7fd90ebe6015636bce974c192c86a)
-   [vdprintf\(\)](#ga0d0a950c2b4e6fba795cb7d8f2e8b8b8)
-   [verr\(\)](#gaf5491fca8b356da75d96fc469bf32ea6)
-   [verrx\(\)](#ga4b5f9ccd84c00dc473329e4bf64125e1)
-   [vfprintf\(\)](#gad80f05917df38df3a5e1817498d67c26)
-   [vfscanf\(\)](#gabdd32e401e37c9d954f3f0a6907500d9)
-   [vprintf\(\)](#gaa715ef816dc040c8b367fde4ba84d6f3)
-   [vscanf\(\)](#ga40250d63904acd3e898061c9eab6ead3)
-   [vsnprintf\(\)](#ga2cadafbeb2d6e0d5781f6e5106d41fc2)
-   [vsprintf\(\)](#gaab3db67c98c32122fcb3d076d4207bbc)
-   [vsscanf\(\)](#gab1c4552aba80fe03c9b45fe27f4331ad)
-   [vwarn\(\)](#ga9ca1ffba0c6f5df7b172d25917611b4a)
-   [vwarnx\(\)](#ga22924aaaaa6b6e8bba4c76d0a0fe86cd)
-   [warn\(\)](#gaf80d19f1297a11626fab61a248959c71)
-   [warnx\(\)](#ga58f3d9691c146f86e562022d39567b7f)
-   [writev\(\)](#gad57f362a0aef72b52ea59288f74dd1ea)

## **Overview**<a name="section1444219423165622"></a>

**Description:**

Provides data structures and functions for performing input/output \(I/O\) operations, such as printf and scanf. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section101471515165622"></a>

## Files<a name="files"></a>

<a name="table341641629165622"></a>
<table><thead align="left"><tr id="row33194687165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p995650331165622"><a name="p995650331165622"></a><a name="p995650331165622"></a>File Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1200525988165622"><a name="p1200525988165622"></a><a name="p1200525988165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1056692776165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p65277287165622"><a name="p65277287165622"></a><a name="p65277287165622"></a><a href="err-h.md">err.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1215241758165622"><a name="p1215241758165622"></a><a name="p1215241758165622"></a>Provides common functions for error messages. </p>
</td>
</tr>
<tr id="row2097680242165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1004237680165622"><a name="p1004237680165622"></a><a name="p1004237680165622"></a><a href="iconv-h.md">iconv.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p745907502165622"><a name="p745907502165622"></a><a name="p745907502165622"></a>Declares functions related to the I/O character set conversion. </p>
</td>
</tr>
<tr id="row1724682600165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p64556810165622"><a name="p64556810165622"></a><a name="p64556810165622"></a><a href="locale-h.md">locale.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p98970605165622"><a name="p98970605165622"></a><a name="p98970605165622"></a>Provides functions to set and obtain the locale language environment. </p>
</td>
</tr>
<tr id="row735193385165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p924364130165622"><a name="p924364130165622"></a><a name="p924364130165622"></a><a href="nl_types-h.md">nl_types.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p778335409165622"><a name="p778335409165622"></a><a name="p778335409165622"></a>Defines I/O multiplexing functions related to message catalog operations. </p>
</td>
</tr>
<tr id="row468531141165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1740263416165622"><a name="p1740263416165622"></a><a name="p1740263416165622"></a><a href="poll-h.md">poll.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1819474611165622"><a name="p1819474611165622"></a><a name="p1819474611165622"></a>Declares I/O multiplexing functions. </p>
</td>
</tr>
<tr id="row348074177165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p603110013165622"><a name="p603110013165622"></a><a name="p603110013165622"></a><a href="stdio-h.md">stdio.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1368676316165622"><a name="p1368676316165622"></a><a name="p1368676316165622"></a>Declares common functions used for performing input and output (I/O) operations. </p>
</td>
</tr>
<tr id="row480445320165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p298279559165622"><a name="p298279559165622"></a><a name="p298279559165622"></a><a href="select-h.md">select.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1718068994165622"><a name="p1718068994165622"></a><a name="p1718068994165622"></a>Provides functions and structures related to I/O multiplexing. </p>
</td>
</tr>
<tr id="row1027350557165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1528904704165622"><a name="p1528904704165622"></a><a name="p1528904704165622"></a><a href="uio-h.md">uio.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p229958191165622"><a name="p229958191165622"></a><a name="p229958191165622"></a>Provides functions and structures related to input/output (I/O) to a file or buffer. </p>
</td>
</tr>
<tr id="row1443148912165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p468495202165622"><a name="p468495202165622"></a><a name="p468495202165622"></a><a href="wordexp-h.md">wordexp.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1310837270165622"><a name="p1310837270165622"></a><a name="p1310837270165622"></a>Declares functions related to word expansion. </p>
</td>
</tr>
</tbody>
</table>

## Data Structures<a name="nested-classes"></a>

<a name="table1248332772165622"></a>
<table><thead align="left"><tr id="row1062929090165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p884941144165622"><a name="p884941144165622"></a><a name="p884941144165622"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p988643444165622"><a name="p988643444165622"></a><a name="p988643444165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1115194928165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1292933232165622"><a name="p1292933232165622"></a><a name="p1292933232165622"></a><a href="lconv.md">lconv</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1859832370165622"><a name="p1859832370165622"></a><a name="p1859832370165622"></a>Indicates format information about a number. </p>
</td>
</tr>
<tr id="row304575656165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p232708382165622"><a name="p232708382165622"></a><a name="p232708382165622"></a><a href="pollfd.md">pollfd</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1287752176165622"><a name="p1287752176165622"></a><a name="p1287752176165622"></a>Defines I/O multiplexing. </p>
</td>
</tr>
<tr id="row946455205165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p718815873165622"><a name="p718815873165622"></a><a name="p718815873165622"></a><a href="fd_set.md">fd_set</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p592654600165622"><a name="p592654600165622"></a><a name="p592654600165622"></a>Defines a file descriptor set. </p>
</td>
</tr>
<tr id="row27844662165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1304264810165622"><a name="p1304264810165622"></a><a name="p1304264810165622"></a><a href="wordexp_t.md">wordexp_t</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p382025287165622"><a name="p382025287165622"></a><a name="p382025287165622"></a>Describes information about word expansion. </p>
</td>
</tr>
</tbody>
</table>

## Macros<a name="define-members"></a>

<a name="table208938215165622"></a>
<table><thead align="left"><tr id="row494206977165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2085235350165622"><a name="p2085235350165622"></a><a name="p2085235350165622"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p633651588165622"><a name="p633651588165622"></a><a name="p633651588165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1041450328165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p261378997165622"><a name="p261378997165622"></a><a name="p261378997165622"></a><em id="ga07c66689961056725d7f50231d740ba9"><a name="ga07c66689961056725d7f50231d740ba9"></a><a name="ga07c66689961056725d7f50231d740ba9"></a></em>LC_CTYPE    0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1678374229165622"><a name="p1678374229165622"></a><a name="p1678374229165622"></a>Language symbol type, which affects character classification and case conversion. </p>
</td>
</tr>
<tr id="row766019775165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p668815432165622"><a name="p668815432165622"></a><a name="p668815432165622"></a><em id="ga158abb82c565096465ade138c98970d0"><a name="ga158abb82c565096465ade138c98970d0"></a><a name="ga158abb82c565096465ade138c98970d0"></a></em>LC_NUMERIC    1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1796404169165622"><a name="p1796404169165622"></a><a name="p1796404169165622"></a>Number type, which affects the number format. </p>
</td>
</tr>
<tr id="row651891737165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2043303270165622"><a name="p2043303270165622"></a><a name="p2043303270165622"></a><em id="gaa652c62b53b6bf728d592bfbdc7d5852"><a name="gaa652c62b53b6bf728d592bfbdc7d5852"></a><a name="gaa652c62b53b6bf728d592bfbdc7d5852"></a></em>LC_TIME    2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p560363349165622"><a name="p560363349165622"></a><a name="p560363349165622"></a>Time type, which affects date and time formats. </p>
</td>
</tr>
<tr id="row1923883344165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p163019161165622"><a name="p163019161165622"></a><a name="p163019161165622"></a><em id="gaab9cf7b1a206fb75e5884934c8d676db"><a name="gaab9cf7b1a206fb75e5884934c8d676db"></a><a name="gaab9cf7b1a206fb75e5884934c8d676db"></a></em>LC_COLLATE    3</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p778286343165622"><a name="p778286343165622"></a><a name="p778286343165622"></a>Character sorting type, which affects string comparison and sorting habits. </p>
</td>
</tr>
<tr id="row353208926165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1777706674165622"><a name="p1777706674165622"></a><a name="p1777706674165622"></a><em id="ga6d033a83772ef6e6c10dbf13a6a58fb7"><a name="ga6d033a83772ef6e6c10dbf13a6a58fb7"></a><a name="ga6d033a83772ef6e6c10dbf13a6a58fb7"></a></em>LC_MONETARY    4</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p808749184165622"><a name="p808749184165622"></a><a name="p808749184165622"></a>Monetary type, which affects monetary information. </p>
</td>
</tr>
<tr id="row2026627067165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p468512249165622"><a name="p468512249165622"></a><a name="p468512249165622"></a><em id="ga7195d6f0a8d1b9d164a3988a1b8249e8"><a name="ga7195d6f0a8d1b9d164a3988a1b8249e8"></a><a name="ga7195d6f0a8d1b9d164a3988a1b8249e8"></a></em>LC_MESSAGES    5</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1550838327165622"><a name="p1550838327165622"></a><a name="p1550838327165622"></a>Message type, which affects prompt information, error information, status information, titles, labels, buttons, and menus. </p>
</td>
</tr>
<tr id="row1805424686165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1794422652165622"><a name="p1794422652165622"></a><a name="p1794422652165622"></a><em id="ga9cc5213b5dca4f8e48e64586ee444c33"><a name="ga9cc5213b5dca4f8e48e64586ee444c33"></a><a name="ga9cc5213b5dca4f8e48e64586ee444c33"></a></em>LC_ALL    6</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p681717748165622"><a name="p681717748165622"></a><a name="p681717748165622"></a>All types, which affect all content of locale settings. If <strong id="b841694757165622"><a name="b841694757165622"></a><a name="b841694757165622"></a>LC_ALL</strong> is set, the locale information of all types is set to be consistent with <strong id="b1113367205165622"><a name="b1113367205165622"></a><a name="b1113367205165622"></a>LC_ALL</strong>. </p>
</td>
</tr>
<tr id="row843413930165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1462926123165622"><a name="p1462926123165622"></a><a name="p1462926123165622"></a><em id="ga52ac479a805051f59643588b096024ff"><a name="ga52ac479a805051f59643588b096024ff"></a><a name="ga52ac479a805051f59643588b096024ff"></a></em>POLLIN    0x001</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1133934662165622"><a name="p1133934662165622"></a><a name="p1133934662165622"></a>POLLIN event. </p>
</td>
</tr>
<tr id="row1472835394165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1838902979165622"><a name="p1838902979165622"></a><a name="p1838902979165622"></a><em id="gab6f53b89c7a4cc5e8349f7c778d85168"><a name="gab6f53b89c7a4cc5e8349f7c778d85168"></a><a name="gab6f53b89c7a4cc5e8349f7c778d85168"></a></em>POLLPRI    0x002</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p375531697165622"><a name="p375531697165622"></a><a name="p375531697165622"></a>POLLPRI event. </p>
</td>
</tr>
<tr id="row1143086151165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p787392599165622"><a name="p787392599165622"></a><a name="p787392599165622"></a><em id="ga91b3c67129ac7675062f316b840a0d58"><a name="ga91b3c67129ac7675062f316b840a0d58"></a><a name="ga91b3c67129ac7675062f316b840a0d58"></a></em>POLLOUT    0x004</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p334844955165622"><a name="p334844955165622"></a><a name="p334844955165622"></a>POLLOUT event. </p>
</td>
</tr>
<tr id="row1626708103165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p114213815165622"><a name="p114213815165622"></a><a name="p114213815165622"></a><em id="gab1c532446408c98559d4aaaeeeb99820"><a name="gab1c532446408c98559d4aaaeeeb99820"></a><a name="gab1c532446408c98559d4aaaeeeb99820"></a></em>POLLERR    0x008</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p512333802165622"><a name="p512333802165622"></a><a name="p512333802165622"></a>POLLERR event. </p>
</td>
</tr>
<tr id="row1053844379165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1396048399165622"><a name="p1396048399165622"></a><a name="p1396048399165622"></a><em id="ga262754fe6bdf27c2cd3da43284ec8536"><a name="ga262754fe6bdf27c2cd3da43284ec8536"></a><a name="ga262754fe6bdf27c2cd3da43284ec8536"></a></em>POLLHUP    0x010</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1464804440165622"><a name="p1464804440165622"></a><a name="p1464804440165622"></a>POLLHUP event. </p>
</td>
</tr>
<tr id="row1638835023165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p678807346165622"><a name="p678807346165622"></a><a name="p678807346165622"></a><em id="gae8bffe35c61e12fb7b408b89721896df"><a name="gae8bffe35c61e12fb7b408b89721896df"></a><a name="gae8bffe35c61e12fb7b408b89721896df"></a></em>POLLNVAL    0x020</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2098779092165622"><a name="p2098779092165622"></a><a name="p2098779092165622"></a>POLLNVAL event. </p>
</td>
</tr>
<tr id="row1778948589165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1018430014165622"><a name="p1018430014165622"></a><a name="p1018430014165622"></a><em id="ga86c5dbf5a99358e288f573d6a1e0873f"><a name="ga86c5dbf5a99358e288f573d6a1e0873f"></a><a name="ga86c5dbf5a99358e288f573d6a1e0873f"></a></em>FD_SETSIZE    1024</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1106823270165622"><a name="p1106823270165622"></a><a name="p1106823270165622"></a>Defines the size of <strong id="b654130764165622"><a name="b654130764165622"></a><a name="b654130764165622"></a><a href="fd_set.md">fd_set</a></strong>, that is, the maximum number of monitored files. </p>
</td>
</tr>
<tr id="row1986799156165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p333350675165622"><a name="p333350675165622"></a><a name="p333350675165622"></a><a href="IO.md#ga92ab86a10f942411365b9078833559f0">FD_ZERO</a>(s)   do { int __i; unsigned long *__b=(s)-&gt;fds_bits; for(__i=sizeof (<a href="fd_set.md">fd_set</a>)/sizeof (long); __i; __i--) *__b++=0; } while(0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p343459551165622"><a name="p343459551165622"></a><a name="p343459551165622"></a>Clears all elements in the file descriptor set. </p>
</td>
</tr>
<tr id="row2068171937165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1381418182165622"><a name="p1381418182165622"></a><a name="p1381418182165622"></a><a href="IO.md#gaa7701be461ce602ff7043cbd898a0c53">FD_SET</a>(d, s)   ((s)-&gt;fds_bits[(d)/(8*sizeof(long))] |= (1UL&lt;&lt;((d)%(8*sizeof(long)))))</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1504107665165622"><a name="p1504107665165622"></a><a name="p1504107665165622"></a>Adds a file descriptor to a set. </p>
</td>
</tr>
<tr id="row1074188176165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p946741493165622"><a name="p946741493165622"></a><a name="p946741493165622"></a><a href="IO.md#ga60efc4a969e971f91b7a73bcace62e58">FD_CLR</a>(d, s)   ((s)-&gt;fds_bits[(d)/(8*sizeof(long))] &amp;= ~(1UL&lt;&lt;((d)%(8*sizeof(long)))))</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1592765880165622"><a name="p1592765880165622"></a><a name="p1592765880165622"></a>Removes a file descriptor from a set. </p>
</td>
</tr>
<tr id="row521720239165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p116453014165622"><a name="p116453014165622"></a><a name="p116453014165622"></a><a href="IO.md#ga99a3a0e4d7d1d3eb7be68f37554c0a30">FD_ISSET</a>(d, s)   !!((s)-&gt;fds_bits[(d)/(8*sizeof(long))] &amp; (1UL&lt;&lt;((d)%(8*sizeof(long)))))</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p353871268165622"><a name="p353871268165622"></a><a name="p353871268165622"></a>Checks whether a file descriptor is in a set. </p>
</td>
</tr>
</tbody>
</table>

## Typedefs<a name="typedef-members"></a>

<a name="table1960192163165622"></a>
<table><thead align="left"><tr id="row1440236975165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p955965232165622"><a name="p955965232165622"></a><a name="p955965232165622"></a>Typedef Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1131979617165622"><a name="p1131979617165622"></a><a name="p1131979617165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row741668867165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p679309707165622"><a name="p679309707165622"></a><a name="p679309707165622"></a>iconv_t </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p487103822165622"><a name="p487103822165622"></a><a name="p487103822165622"></a><strong id="ga72517f6ffadddaafa9d51dee9b535c9f"><a name="ga72517f6ffadddaafa9d51dee9b535c9f"></a><a name="ga72517f6ffadddaafa9d51dee9b535c9f"></a></strong> typedef void * </p>
<p id="p757366955165622"><a name="p757366955165622"></a><a name="p757366955165622"></a>Type of the character set conversion descriptor. </p>
</td>
</tr>
<tr id="row2023432796165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p446967971165622"><a name="p446967971165622"></a><a name="p446967971165622"></a>nl_catd </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1189793384165622"><a name="p1189793384165622"></a><a name="p1189793384165622"></a><strong id="ga3f305b6699c89f91aecfc0b5f8604a5f"><a name="ga3f305b6699c89f91aecfc0b5f8604a5f"></a><a name="ga3f305b6699c89f91aecfc0b5f8604a5f"></a></strong> typedef void * </p>
<p id="p519398654165622"><a name="p519398654165622"></a><a name="p519398654165622"></a>Type of message catalog descriptor. </p>
</td>
</tr>
<tr id="row1972291336165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1381490543165622"><a name="p1381490543165622"></a><a name="p1381490543165622"></a>nfds_t </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1602870324165622"><a name="p1602870324165622"></a><a name="p1602870324165622"></a><strong id="ga0af7a8bdafcd5532e620a11f0d373d52"><a name="ga0af7a8bdafcd5532e620a11f0d373d52"></a><a name="ga0af7a8bdafcd5532e620a11f0d373d52"></a></strong> typedef unsigned long </p>
<p id="p426070900165622"><a name="p426070900165622"></a><a name="p426070900165622"></a>Number of poll types. </p>
</td>
</tr>
<tr id="row1976064170165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p690455929165622"><a name="p690455929165622"></a><a name="p690455929165622"></a>FILE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p976408428165622"><a name="p976408428165622"></a><a name="p976408428165622"></a><strong id="ga912af5ab9f8a52ddd387b7defc0b49f1"><a name="ga912af5ab9f8a52ddd387b7defc0b49f1"></a><a name="ga912af5ab9f8a52ddd387b7defc0b49f1"></a></strong> typedef struct _IO_FILE </p>
<p id="p1217931696165622"><a name="p1217931696165622"></a><a name="p1217931696165622"></a>Struct of file stream. </p>
</td>
</tr>
<tr id="row393035912165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1776198583165622"><a name="p1776198583165622"></a><a name="p1776198583165622"></a>fd_mask </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1760001053165622"><a name="p1760001053165622"></a><a name="p1760001053165622"></a><strong id="gaf78c256e09db7de8ea18def79fc5e6b2"><a name="gaf78c256e09db7de8ea18def79fc5e6b2"></a><a name="gaf78c256e09db7de8ea18def79fc5e6b2"></a></strong> typedef unsigned long </p>
<p id="p719173928165622"><a name="p719173928165622"></a><a name="p719173928165622"></a>Defines <strong id="b1213043879165622"><a name="b1213043879165622"></a><a name="b1213043879165622"></a><a href="fd_set.md">fd_set</a></strong> as the alias of the element type. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table86748964165622"></a>
<table><thead align="left"><tr id="row400144543165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p558116800165622"><a name="p558116800165622"></a><a name="p558116800165622"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1955839349165622"><a name="p1955839349165622"></a><a name="p1955839349165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row347678146165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1141418622165622"><a name="p1141418622165622"></a><a name="p1141418622165622"></a><a href="IO.md#gaf80d19f1297a11626fab61a248959c71">warn</a> (const char *fmt,...)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p715568550165622"><a name="p715568550165622"></a><a name="p715568550165622"></a>void </p>
<p id="p621948612165622"><a name="p621948612165622"></a><a name="p621948612165622"></a>Displays a formatted error message on the standard error (stderr) output. </p>
</td>
</tr>
<tr id="row1530842540165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1500177302165622"><a name="p1500177302165622"></a><a name="p1500177302165622"></a><a href="IO.md#ga9ca1ffba0c6f5df7b172d25917611b4a">vwarn</a> (const char *fmt, va_list args)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1779457346165622"><a name="p1779457346165622"></a><a name="p1779457346165622"></a>void </p>
<p id="p1967168282165622"><a name="p1967168282165622"></a><a name="p1967168282165622"></a>Displays a formatted error message on the stderr output. </p>
</td>
</tr>
<tr id="row686284762165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1806195447165622"><a name="p1806195447165622"></a><a name="p1806195447165622"></a><a href="IO.md#ga58f3d9691c146f86e562022d39567b7f">warnx</a> (const char *fmt,...)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p691714859165622"><a name="p691714859165622"></a><a name="p691714859165622"></a>void </p>
<p id="p1020868302165622"><a name="p1020868302165622"></a><a name="p1020868302165622"></a>Displays a formatted error message on the stderr output. </p>
</td>
</tr>
<tr id="row646085084165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1650651953165622"><a name="p1650651953165622"></a><a name="p1650651953165622"></a><a href="IO.md#ga22924aaaaa6b6e8bba4c76d0a0fe86cd">vwarnx</a> (const char *fmt, va_list args)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1887011861165622"><a name="p1887011861165622"></a><a name="p1887011861165622"></a>void </p>
<p id="p2070580041165622"><a name="p2070580041165622"></a><a name="p2070580041165622"></a>Displays a formatted error message on the stderr output. </p>
</td>
</tr>
<tr id="row73681823165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1317250535165622"><a name="p1317250535165622"></a><a name="p1317250535165622"></a><a href="IO.md#gaa6b66a9a8eb4be40e4424a4dc92ae056">err</a> (int eval, const char *fmt, va_list args)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p32286247165622"><a name="p32286247165622"></a><a name="p32286247165622"></a>void </p>
<p id="p1832071450165622"><a name="p1832071450165622"></a><a name="p1832071450165622"></a>Displays error information. </p>
</td>
</tr>
<tr id="row361085526165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2047248669165622"><a name="p2047248669165622"></a><a name="p2047248669165622"></a><a href="IO.md#gaeaca83913c785b95d6c50f35207ff739">errx</a> (int eval, const char *fmt,...)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p597136731165622"><a name="p597136731165622"></a><a name="p597136731165622"></a>void </p>
<p id="p541619714165622"><a name="p541619714165622"></a><a name="p541619714165622"></a>Displays error information. </p>
</td>
</tr>
<tr id="row1221353312165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1081365734165622"><a name="p1081365734165622"></a><a name="p1081365734165622"></a><a href="IO.md#gaf5491fca8b356da75d96fc469bf32ea6">verr</a> (int eval, const char *fmt, va_list args)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p378798178165622"><a name="p378798178165622"></a><a name="p378798178165622"></a>void </p>
<p id="p1713052751165622"><a name="p1713052751165622"></a><a name="p1713052751165622"></a>Displays error information. </p>
</td>
</tr>
<tr id="row1808816341165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1993143958165622"><a name="p1993143958165622"></a><a name="p1993143958165622"></a><a href="IO.md#ga4b5f9ccd84c00dc473329e4bf64125e1">verrx</a> (int eval, const char *fmt, va_list args)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p442629052165622"><a name="p442629052165622"></a><a name="p442629052165622"></a>void </p>
<p id="p1706989192165622"><a name="p1706989192165622"></a><a name="p1706989192165622"></a>Displays a formatted error message. </p>
</td>
</tr>
<tr id="row353987064165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p471082217165622"><a name="p471082217165622"></a><a name="p471082217165622"></a><a href="IO.md#ga934548ab8aaae237ac5cce0ed0b3edec">iconv_open</a> (const char *to, const char *from)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p372494136165622"><a name="p372494136165622"></a><a name="p372494136165622"></a><a href="IO.md#ga72517f6ffadddaafa9d51dee9b535c9f">iconv_t</a> </p>
<p id="p1432061884165622"><a name="p1432061884165622"></a><a name="p1432061884165622"></a>Obtain a character set conversion descriptor. </p>
</td>
</tr>
<tr id="row1286685992165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1444745018165622"><a name="p1444745018165622"></a><a name="p1444745018165622"></a><a href="IO.md#gab7c1300a663def659ce6d4a01076c39d">iconv</a> (<a href="IO.md#ga72517f6ffadddaafa9d51dee9b535c9f">iconv_t</a> cd, char **restrict in, size_t *restrict inb, char **restrict out, size_t *restrict outb)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1509246521165622"><a name="p1509246521165622"></a><a name="p1509246521165622"></a>size_t </p>
<p id="p1901145538165622"><a name="p1901145538165622"></a><a name="p1901145538165622"></a>Converts a character set. </p>
</td>
</tr>
<tr id="row987212789165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p744956136165622"><a name="p744956136165622"></a><a name="p744956136165622"></a><a href="IO.md#ga062da5f802d9e274a8702f11921e691b">iconv_close</a> (<a href="IO.md#ga72517f6ffadddaafa9d51dee9b535c9f">iconv_t</a> cd)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1676994884165622"><a name="p1676994884165622"></a><a name="p1676994884165622"></a>int </p>
<p id="p23907243165622"><a name="p23907243165622"></a><a name="p23907243165622"></a>Closes a character set conversion descriptor. </p>
</td>
</tr>
<tr id="row893259067165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p839695585165622"><a name="p839695585165622"></a><a name="p839695585165622"></a><a href="IO.md#gab7fc0f6be5f13c81de180c1288ba3b6f">poll</a> (struct <a href="pollfd.md">pollfd</a> fds[], <a href="IO.md#ga0af7a8bdafcd5532e620a11f0d373d52">nfds_t</a> nfds, int timeout)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p400576461165622"><a name="p400576461165622"></a><a name="p400576461165622"></a>int </p>
<p id="p1879130715165622"><a name="p1879130715165622"></a><a name="p1879130715165622"></a>Defines the I/O multiplexing system. </p>
</td>
</tr>
<tr id="row66923503165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p461367407165622"><a name="p461367407165622"></a><a name="p461367407165622"></a><a href="IO.md#ga58386e895d3c07b008c8865b2a9716fb">fopen</a> (const char *__restrict path, const char *__restrict mode)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p922161867165622"><a name="p922161867165622"></a><a name="p922161867165622"></a><a href="IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> * </p>
<p id="p1739859318165622"><a name="p1739859318165622"></a><a name="p1739859318165622"></a>Opens the file stored in the specified path based on the given mode. </p>
</td>
</tr>
<tr id="row657292879165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1350583485165622"><a name="p1350583485165622"></a><a name="p1350583485165622"></a><a href="IO.md#gaab336dbfc008a0873046ecd7db043df0">freopen</a> (const char *__restrict path, const char *__restrict mode, <a href="IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *__restrict stream)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2010957257165622"><a name="p2010957257165622"></a><a name="p2010957257165622"></a><a href="IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> * </p>
<p id="p1157279707165622"><a name="p1157279707165622"></a><a name="p1157279707165622"></a>Opens the file stored in the specified path, and associates the stream by the given stream. </p>
</td>
</tr>
<tr id="row1757867825165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1644199265165622"><a name="p1644199265165622"></a><a name="p1644199265165622"></a><a href="IO.md#gac41a0ad4b31be2ad59d8222a0de30bda">fclose</a> (<a href="IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *fd)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1577416800165622"><a name="p1577416800165622"></a><a name="p1577416800165622"></a>int </p>
<p id="p174005916165622"><a name="p174005916165622"></a><a name="p174005916165622"></a>Closes a file based on the specified file descriptor. </p>
</td>
</tr>
<tr id="row57492954165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1223999827165622"><a name="p1223999827165622"></a><a name="p1223999827165622"></a><a href="IO.md#ga02b13b56a188401119ea4da43c184913">remove</a> (const char *pathname)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1225827390165622"><a name="p1225827390165622"></a><a name="p1225827390165622"></a>int </p>
<p id="p531415721165622"><a name="p531415721165622"></a><a name="p531415721165622"></a>Deletes a specified file or directory from the file system. </p>
</td>
</tr>
<tr id="row16747773165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1716809981165622"><a name="p1716809981165622"></a><a name="p1716809981165622"></a><a href="IO.md#ga4d4709508ed7604103d77c3fdc5ea4a2">rename</a> (const char *oldpath, const char *newpath)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1773759400165622"><a name="p1773759400165622"></a><a name="p1773759400165622"></a>int </p>
<p id="p352356957165622"><a name="p352356957165622"></a><a name="p352356957165622"></a>Renames a specified file. </p>
</td>
</tr>
<tr id="row925984392165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1298666094165622"><a name="p1298666094165622"></a><a name="p1298666094165622"></a><a href="IO.md#gafb95de1535a5a185954819539f3c6ca5">feof</a> (<a href="IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *fp)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p489304202165622"><a name="p489304202165622"></a><a name="p489304202165622"></a>int </p>
<p id="p339083037165622"><a name="p339083037165622"></a><a name="p339083037165622"></a>Tests the end-of-file indicator for a specified stream. </p>
</td>
</tr>
<tr id="row858257043165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2133551924165622"><a name="p2133551924165622"></a><a name="p2133551924165622"></a><a href="IO.md#ga4a98383bb54291c2abede7aa28acf597">ferror</a> (<a href="IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1255852371165622"><a name="p1255852371165622"></a><a name="p1255852371165622"></a>int </p>
<p id="p429619235165622"><a name="p429619235165622"></a><a name="p429619235165622"></a>Tests for the error identifier of a specified file stream. </p>
</td>
</tr>
<tr id="row483668080165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1447560270165622"><a name="p1447560270165622"></a><a name="p1447560270165622"></a><a href="IO.md#gae4459e830d3e2abcf428337a661d9456">fflush</a> (<a href="IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *fp)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p864433761165622"><a name="p864433761165622"></a><a name="p864433761165622"></a>int </p>
<p id="p898138099165622"><a name="p898138099165622"></a><a name="p898138099165622"></a>Flushes the output buffer of a specified stream. </p>
</td>
</tr>
<tr id="row1651914507165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1920483629165622"><a name="p1920483629165622"></a><a name="p1920483629165622"></a><a href="IO.md#ga81202d6a15259fbceb71a961a878b01a">clearerr</a> (<a href="IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *fp)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p918191728165622"><a name="p918191728165622"></a><a name="p918191728165622"></a>void </p>
<p id="p2079804649165622"><a name="p2079804649165622"></a><a name="p2079804649165622"></a>Resets the error indicators. </p>
</td>
</tr>
<tr id="row1803103727165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1500507638165622"><a name="p1500507638165622"></a><a name="p1500507638165622"></a><a href="IO.md#gaece5d6e00c239ffd0847d8d2ef65bd57">fseek</a> (<a href="IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *fp, long offset, int whence)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p15587769165622"><a name="p15587769165622"></a><a name="p15587769165622"></a>int </p>
<p id="p848160780165622"><a name="p848160780165622"></a><a name="p848160780165622"></a>Changes the position of a specified stream to a new position. </p>
</td>
</tr>
<tr id="row2121159040165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p20872216165622"><a name="p20872216165622"></a><a name="p20872216165622"></a><a href="IO.md#gaae4231ac8066eb54ea1d9d12d551605c">ftell</a> (<a href="IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *fp)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p701311481165622"><a name="p701311481165622"></a><a name="p701311481165622"></a>long </p>
<p id="p1596340579165622"><a name="p1596340579165622"></a><a name="p1596340579165622"></a>Obtains the current value of the file position indicator for a specified file stream. </p>
</td>
</tr>
<tr id="row974404045165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1897071375165622"><a name="p1897071375165622"></a><a name="p1897071375165622"></a><a href="IO.md#gaa0cd401f198d33d9d01a9e8aa4026819">rewind</a> (<a href="IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1073546442165622"><a name="p1073546442165622"></a><a name="p1073546442165622"></a>void </p>
<p id="p312117625165622"><a name="p312117625165622"></a><a name="p312117625165622"></a>Sets the position indicator of a specified stream to the beginning of the file. </p>
</td>
</tr>
<tr id="row1461763614165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1147818710165622"><a name="p1147818710165622"></a><a name="p1147818710165622"></a><a href="IO.md#gaf2e2b1a01359f5f7068b61d1dffcdcdd">fgetpos</a> (<a href="IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream, fpos_t *pos)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p219327369165622"><a name="p219327369165622"></a><a name="p219327369165622"></a>int </p>
<p id="p1362074420165622"><a name="p1362074420165622"></a><a name="p1362074420165622"></a>Obtains the current file position of a specified stream and writes it to the <strong id="b2072702348165622"><a name="b2072702348165622"></a><a name="b2072702348165622"></a>pos</strong> parameter. </p>
</td>
</tr>
<tr id="row1607337970165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1655108014165622"><a name="p1655108014165622"></a><a name="p1655108014165622"></a><a href="IO.md#gae47e3f92dd8fc42ce0b6384c03ce6a9b">fsetpos</a> (<a href="IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *fp, const fpos_t *pos)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1446705335165622"><a name="p1446705335165622"></a><a name="p1446705335165622"></a>int </p>
<p id="p1598815225165622"><a name="p1598815225165622"></a><a name="p1598815225165622"></a>Sets the file position indicator for a specified file stream. </p>
</td>
</tr>
<tr id="row913999804165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p757592138165622"><a name="p757592138165622"></a><a name="p757592138165622"></a><a href="IO.md#ga091b3f41bdd6984d63ea48d87a62bfd2">fread</a> (void *__restrict ptr, size_t size, size_t nmemb, <a href="IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *__restrict stream)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p491287964165622"><a name="p491287964165622"></a><a name="p491287964165622"></a>size_t </p>
<p id="p450325501165622"><a name="p450325501165622"></a><a name="p450325501165622"></a>Reads data from a specified stream. </p>
</td>
</tr>
<tr id="row1993255068165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1663554442165622"><a name="p1663554442165622"></a><a name="p1663554442165622"></a><a href="IO.md#gaf86a4505e5de39a100f7ea828377b585">fwrite</a> (const void *__restrict ptr, size_t size, size_t nmemb, <a href="IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *__restrict stream)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p642147225165622"><a name="p642147225165622"></a><a name="p642147225165622"></a>size_t </p>
<p id="p405191015165622"><a name="p405191015165622"></a><a name="p405191015165622"></a>Writes data to a specified stream. </p>
</td>
</tr>
<tr id="row646576825165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p663903032165622"><a name="p663903032165622"></a><a name="p663903032165622"></a><a href="IO.md#gad5a0ea2c21a23a380b7c30fe35fa9456">getc</a> (<a href="IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1657228395165622"><a name="p1657228395165622"></a><a name="p1657228395165622"></a>int </p>
<p id="p1843700999165622"><a name="p1843700999165622"></a><a name="p1843700999165622"></a>Reads a character from a specified file stream. </p>
</td>
</tr>
<tr id="row655142981165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p436009095165622"><a name="p436009095165622"></a><a name="p436009095165622"></a><a href="IO.md#ga3e29caa20f7cffe18f410f01278905a8">getchar</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1185250504165622"><a name="p1185250504165622"></a><a name="p1185250504165622"></a>int </p>
<p id="p2094937730165622"><a name="p2094937730165622"></a><a name="p2094937730165622"></a>Obtains the next character from the standard input (stdin). </p>
</td>
</tr>
<tr id="row1218425884165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1296239891165622"><a name="p1296239891165622"></a><a name="p1296239891165622"></a><a href="IO.md#ga54efa95b6d5b41adec98e5b8a1a9f27b">ungetc</a> (int c, <a href="IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p580330700165622"><a name="p580330700165622"></a><a name="p580330700165622"></a>int </p>
<p id="p1493114373165622"><a name="p1493114373165622"></a><a name="p1493114373165622"></a>Pushes a character back into a specified file stream. </p>
</td>
</tr>
<tr id="row1162119751165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p722425056165622"><a name="p722425056165622"></a><a name="p722425056165622"></a><a href="IO.md#gabe6299d5823dd023e610aaa619735a3f">fputc</a> (int c, <a href="IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2085118987165622"><a name="p2085118987165622"></a><a name="p2085118987165622"></a>int </p>
<p id="p128127952165622"><a name="p128127952165622"></a><a name="p128127952165622"></a>Writes a character into the position pointed to by a specified stream. </p>
</td>
</tr>
<tr id="row1693369725165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p689192598165622"><a name="p689192598165622"></a><a name="p689192598165622"></a><a href="IO.md#ga38f980218f04ebdddcdcd1b77e1cf6b1">putc</a> (int c, <a href="IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1076604956165622"><a name="p1076604956165622"></a><a name="p1076604956165622"></a>int </p>
<p id="p127982083165622"><a name="p127982083165622"></a><a name="p127982083165622"></a>Writes a character to a specified file stream. </p>
</td>
</tr>
<tr id="row368032689165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1352209322165622"><a name="p1352209322165622"></a><a name="p1352209322165622"></a><a href="IO.md#gaf4de2514b7778805db3815e8dd6cf09a">putchar</a> (int c)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p225343984165622"><a name="p225343984165622"></a><a name="p225343984165622"></a>int </p>
<p id="p685374854165622"><a name="p685374854165622"></a><a name="p685374854165622"></a>Writes a character into the standard output (stdout). </p>
</td>
</tr>
<tr id="row1249508596165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1878208440165622"><a name="p1878208440165622"></a><a name="p1878208440165622"></a><a href="IO.md#ga2b3df0e66b41edab3c039191fe6cc4f9">fgets</a> (char *s, int size, <a href="IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1965362212165622"><a name="p1965362212165622"></a><a name="p1965362212165622"></a>char * </p>
<p id="p1092703140165622"><a name="p1092703140165622"></a><a name="p1092703140165622"></a>Reads a line of characters from a specified file stream and stores it into the string pointed to by <strong id="b1734936029165622"><a name="b1734936029165622"></a><a name="b1734936029165622"></a>s</strong>. </p>
</td>
</tr>
<tr id="row1998673307165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p24364176165622"><a name="p24364176165622"></a><a name="p24364176165622"></a><a href="IO.md#gaab85b30d68ce9d9e0475e0f51bf610b1">gets</a> (char *s)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2005591250165622"><a name="p2005591250165622"></a><a name="p2005591250165622"></a>char * </p>
<p id="p1181322466165622"><a name="p1181322466165622"></a><a name="p1181322466165622"></a>Reads a line of characters from the stdin and stores it in the buffer. </p>
</td>
</tr>
<tr id="row1514060705165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p391128758165622"><a name="p391128758165622"></a><a name="p391128758165622"></a><a href="IO.md#ga68236e664c1f0da049b25fba1c1695f6">fputs</a> (const char *s, <a href="IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1005908566165622"><a name="p1005908566165622"></a><a name="p1005908566165622"></a>int </p>
<p id="p2034645119165622"><a name="p2034645119165622"></a><a name="p2034645119165622"></a>Writes a character string (excluding the terminating null character) to a specified file stream. </p>
</td>
</tr>
<tr id="row1357678689165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2007080246165622"><a name="p2007080246165622"></a><a name="p2007080246165622"></a><a href="IO.md#gad41876f99f190c7488e64ef39c50a23f">puts</a> (const char *s)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p526166003165622"><a name="p526166003165622"></a><a name="p526166003165622"></a>int </p>
<p id="p834852147165622"><a name="p834852147165622"></a><a name="p834852147165622"></a>Writes a character string and appends a new-line character to the stdout. </p>
</td>
</tr>
<tr id="row1862343735165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p941944491165622"><a name="p941944491165622"></a><a name="p941944491165622"></a><a href="IO.md#ga98631211a4a8aee62f572375d5b637be">printf</a> (const char *format,...)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1787743341165622"><a name="p1787743341165622"></a><a name="p1787743341165622"></a>int </p>
<p id="p1923561890165622"><a name="p1923561890165622"></a><a name="p1923561890165622"></a>Formats arguments based on <strong id="b1744267115165622"><a name="b1744267115165622"></a><a name="b1744267115165622"></a>format</strong> and prints formatted data to the stdout. </p>
</td>
</tr>
<tr id="row972822779165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p577726217165622"><a name="p577726217165622"></a><a name="p577726217165622"></a><a href="IO.md#gad9291335f34e874c8431285d705bc3aa">fprintf</a> (<a href="IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream, const char *format,...)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1107665611165622"><a name="p1107665611165622"></a><a name="p1107665611165622"></a>int </p>
<p id="p1137083507165622"><a name="p1137083507165622"></a><a name="p1137083507165622"></a>Formats arguments based on <strong id="b1615561695165622"><a name="b1615561695165622"></a><a name="b1615561695165622"></a>format</strong> and prints formatted data to a specified file stream. </p>
</td>
</tr>
<tr id="row461267789165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1161934415165622"><a name="p1161934415165622"></a><a name="p1161934415165622"></a><a href="IO.md#ga3082155ec11e7229f7a20439b31a169e">sprintf</a> (char *str, const char *format,...)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p250944952165622"><a name="p250944952165622"></a><a name="p250944952165622"></a>int </p>
<p id="p1730284657165622"><a name="p1730284657165622"></a><a name="p1730284657165622"></a>Prints formatted data from a variable argument list to a specified string. </p>
</td>
</tr>
<tr id="row1179625658165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1829753147165622"><a name="p1829753147165622"></a><a name="p1829753147165622"></a><a href="IO.md#gad76145a6edfc98981ded8815a760e0cd">snprintf</a> (char *str, size_t size, const char *format,...)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p544930936165622"><a name="p544930936165622"></a><a name="p544930936165622"></a>int </p>
<p id="p1219369038165622"><a name="p1219369038165622"></a><a name="p1219369038165622"></a>Prints formatted data of a maximum of <strong id="b78378469165622"><a name="b78378469165622"></a><a name="b78378469165622"></a>size</strong> bytes from a variable argument list to a specified string. </p>
</td>
</tr>
<tr id="row1683396208165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2066056200165622"><a name="p2066056200165622"></a><a name="p2066056200165622"></a><a href="IO.md#gaa715ef816dc040c8b367fde4ba84d6f3">vprintf</a> (const char *format, va_list ap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2031173408165622"><a name="p2031173408165622"></a><a name="p2031173408165622"></a>int </p>
<p id="p516363961165622"><a name="p516363961165622"></a><a name="p516363961165622"></a>Prints formatted data from a variable argument list to the stdout. </p>
</td>
</tr>
<tr id="row462762935165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p40565789165622"><a name="p40565789165622"></a><a name="p40565789165622"></a><a href="IO.md#gad80f05917df38df3a5e1817498d67c26">vfprintf</a> (<a href="IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream, const char *format, va_list ap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2023785477165622"><a name="p2023785477165622"></a><a name="p2023785477165622"></a>int </p>
<p id="p1609402132165622"><a name="p1609402132165622"></a><a name="p1609402132165622"></a>Prints formatted data from a variable argument list to a specified file stream. </p>
</td>
</tr>
<tr id="row264966081165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p773736055165622"><a name="p773736055165622"></a><a name="p773736055165622"></a><a href="IO.md#gaab3db67c98c32122fcb3d076d4207bbc">vsprintf</a> (char *str, const char *format, va_list ap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p230547520165622"><a name="p230547520165622"></a><a name="p230547520165622"></a>int </p>
<p id="p686846418165622"><a name="p686846418165622"></a><a name="p686846418165622"></a>Prints formatted data from a variable argument list to a specified string. </p>
</td>
</tr>
<tr id="row1163705933165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p863294647165622"><a name="p863294647165622"></a><a name="p863294647165622"></a><a href="IO.md#ga2cadafbeb2d6e0d5781f6e5106d41fc2">vsnprintf</a> (char *str, size_t size, const char *format, va_list ap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p205517215165622"><a name="p205517215165622"></a><a name="p205517215165622"></a>int </p>
<p id="p590499284165622"><a name="p590499284165622"></a><a name="p590499284165622"></a>Prints formatted data of a maximum of <strong id="b750344237165622"><a name="b750344237165622"></a><a name="b750344237165622"></a>size</strong> bytes from a variable argument list to a specified string. </p>
</td>
</tr>
<tr id="row853329705165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1460035149165622"><a name="p1460035149165622"></a><a name="p1460035149165622"></a><a href="IO.md#ga5c48433db9c04031772d5b36e6c4411d">scanf</a> (const char *format,...)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p964734666165622"><a name="p964734666165622"></a><a name="p964734666165622"></a>int </p>
<p id="p920561634165622"><a name="p920561634165622"></a><a name="p920561634165622"></a>Reads formatted data from the stdin and stores the data to the additional arguments based on <strong id="b1905004425165622"><a name="b1905004425165622"></a><a name="b1905004425165622"></a>format</strong>. </p>
</td>
</tr>
<tr id="row1899199497165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2122476826165622"><a name="p2122476826165622"></a><a name="p2122476826165622"></a><a href="IO.md#gae902a7b8796799a6e076f07e9d7de045">fscanf</a> (<a href="IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream, const char *format,...)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p842881652165622"><a name="p842881652165622"></a><a name="p842881652165622"></a>int </p>
<p id="p685959329165622"><a name="p685959329165622"></a><a name="p685959329165622"></a>Reads formatted data from a specified file stream and stores it based on <strong id="b427340262165622"><a name="b427340262165622"></a><a name="b427340262165622"></a>format</strong> into the locations pointed to by the variable arguments. </p>
</td>
</tr>
<tr id="row1070111478165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1363976687165622"><a name="p1363976687165622"></a><a name="p1363976687165622"></a><a href="IO.md#gaec1e54556dca3bd701d44395d34818dd">sscanf</a> (const char *str, const char *format,...)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1956201041165622"><a name="p1956201041165622"></a><a name="p1956201041165622"></a>int </p>
<p id="p687510073165622"><a name="p687510073165622"></a><a name="p687510073165622"></a>Reads data from a character string pointed to by <strong id="b1104357606165622"><a name="b1104357606165622"></a><a name="b1104357606165622"></a>str</strong> and stores it based on <strong id="b208477127165622"><a name="b208477127165622"></a><a name="b208477127165622"></a>format</strong> into the locations pointed to by the variable arguments. </p>
</td>
</tr>
<tr id="row289696659165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p761255279165622"><a name="p761255279165622"></a><a name="p761255279165622"></a><a href="IO.md#ga40250d63904acd3e898061c9eab6ead3">vscanf</a> (const char *format, va_list ap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p941224540165622"><a name="p941224540165622"></a><a name="p941224540165622"></a>int </p>
<p id="p1290847143165622"><a name="p1290847143165622"></a><a name="p1290847143165622"></a>Reads data from the stdin and stores it based on <strong id="b774436065165622"><a name="b774436065165622"></a><a name="b774436065165622"></a>format</strong> into the locations pointed to by the elements in the variable argument list identified by <strong id="b970977885165622"><a name="b970977885165622"></a><a name="b970977885165622"></a>ap</strong>. </p>
</td>
</tr>
<tr id="row584556272165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2018149699165622"><a name="p2018149699165622"></a><a name="p2018149699165622"></a><a href="IO.md#gabdd32e401e37c9d954f3f0a6907500d9">vfscanf</a> (<a href="IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream, const char *format, va_list ap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1635872129165622"><a name="p1635872129165622"></a><a name="p1635872129165622"></a>int </p>
<p id="p2030237752165622"><a name="p2030237752165622"></a><a name="p2030237752165622"></a>Reads data from a specified file stream and stores it based on <strong id="b847192785165622"><a name="b847192785165622"></a><a name="b847192785165622"></a>format</strong> into the locations pointed to by the elements in the variable argument list identified by <strong id="b1081596454165622"><a name="b1081596454165622"></a><a name="b1081596454165622"></a>ap</strong>. </p>
</td>
</tr>
<tr id="row168954546165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1463160687165622"><a name="p1463160687165622"></a><a name="p1463160687165622"></a><a href="IO.md#gab1c4552aba80fe03c9b45fe27f4331ad">vsscanf</a> (const char *str, const char *format, va_list ap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2000455860165622"><a name="p2000455860165622"></a><a name="p2000455860165622"></a>int </p>
<p id="p2133103720165622"><a name="p2133103720165622"></a><a name="p2133103720165622"></a>Reads data from a specified string and stores it based on <strong id="b1908271525165622"><a name="b1908271525165622"></a><a name="b1908271525165622"></a>format</strong> into the locations pointed to by the elements in the variable argument list identified by <strong id="b1075151827165622"><a name="b1075151827165622"></a><a name="b1075151827165622"></a>ap</strong>. </p>
</td>
</tr>
<tr id="row1732738779165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p143511336165622"><a name="p143511336165622"></a><a name="p143511336165622"></a><a href="IO.md#ga80b37b56a5a42139dccaef56da4bf82a">perror</a> (const char *msg)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1776369940165622"><a name="p1776369940165622"></a><a name="p1776369940165622"></a>void </p>
<p id="p421938574165622"><a name="p421938574165622"></a><a name="p421938574165622"></a>Prints the last error occurred during a call to a system or library function to the standard error output stream (stderr). </p>
</td>
</tr>
<tr id="row773696928165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p61218080165622"><a name="p61218080165622"></a><a name="p61218080165622"></a><a href="IO.md#gaf691eb990d669a9edec8a9ec721ce3bc">setvbuf</a> (<a href="IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream, char *buf, int mode, size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p506151965165622"><a name="p506151965165622"></a><a name="p506151965165622"></a>int </p>
<p id="p2007132614165622"><a name="p2007132614165622"></a><a name="p2007132614165622"></a>Sets the mode and size of the buffer for a specified stream. </p>
</td>
</tr>
<tr id="row805924718165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1384886271165622"><a name="p1384886271165622"></a><a name="p1384886271165622"></a><a href="IO.md#ga36d24924e1acc69f9c3ce49a832615fe">setbuf</a> (<a href="IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream, char *buf)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p682887850165622"><a name="p682887850165622"></a><a name="p682887850165622"></a>void </p>
<p id="p918163156165622"><a name="p918163156165622"></a><a name="p918163156165622"></a>Sets a buffer to be used by a specified stream. </p>
</td>
</tr>
<tr id="row1146136753165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p795726090165622"><a name="p795726090165622"></a><a name="p795726090165622"></a><a href="IO.md#ga6b2efc6515c53ab5f0c9800c35f65789">fmemopen</a> (void *buf, size_t size, const char *mode)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1141008623165622"><a name="p1141008623165622"></a><a name="p1141008623165622"></a><a href="IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> * </p>
<p id="p172655607165622"><a name="p172655607165622"></a><a name="p172655607165622"></a>Opens a memory stream that allows the access mode specified by <strong id="b1902576062165622"><a name="b1902576062165622"></a><a name="b1902576062165622"></a>mode</strong>. </p>
</td>
</tr>
<tr id="row646564550165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1321021830165622"><a name="p1321021830165622"></a><a name="p1321021830165622"></a><a href="IO.md#gac7250554d80d31f4d8ad316c4c3c3c85">open_memstream</a> (char **ptr, size_t *size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p912256047165622"><a name="p912256047165622"></a><a name="p912256047165622"></a><a href="IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> * </p>
<p id="p374190119165622"><a name="p374190119165622"></a><a name="p374190119165622"></a>Opens a stream for writing to a specified buffer. </p>
</td>
</tr>
<tr id="row1755837723165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p472832097165622"><a name="p472832097165622"></a><a name="p472832097165622"></a><a href="IO.md#ga03681b8592bba6fe02941b9abc182808">fileno</a> (<a href="IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *fp)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1230365815165622"><a name="p1230365815165622"></a><a name="p1230365815165622"></a>int </p>
<p id="p2097547868165622"><a name="p2097547868165622"></a><a name="p2097547868165622"></a>Obtains the file descriptor of a specified file stream. </p>
</td>
</tr>
<tr id="row871012806165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p29388963165622"><a name="p29388963165622"></a><a name="p29388963165622"></a><a href="IO.md#ga6926f47b76b028f112045fbe7ced4115">fseeko</a> (<a href="IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *fp, off_t offset, int whence)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p649550796165622"><a name="p649550796165622"></a><a name="p649550796165622"></a>int </p>
<p id="p80519776165622"><a name="p80519776165622"></a><a name="p80519776165622"></a>Sets the position of the next input or output operation on a specified file stream. </p>
</td>
</tr>
<tr id="row1402298926165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p709070380165622"><a name="p709070380165622"></a><a name="p709070380165622"></a><a href="IO.md#ga5f52ea043b9a2aa4d8cc92d674a2117b">ftello</a> (<a href="IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *fp)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p36606655165622"><a name="p36606655165622"></a><a name="p36606655165622"></a>off_t </p>
<p id="p743543756165622"><a name="p743543756165622"></a><a name="p743543756165622"></a>Obtains the current value of the file position indicator for a specified file stream. </p>
</td>
</tr>
<tr id="row750366794165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1552030663165622"><a name="p1552030663165622"></a><a name="p1552030663165622"></a><a href="IO.md#ga5fe0fc8fe920b640d488856c5ca43cb5">dprintf</a> (int fd, const char *format,...)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1922917730165622"><a name="p1922917730165622"></a><a name="p1922917730165622"></a>int </p>
<p id="p978971677165622"><a name="p978971677165622"></a><a name="p978971677165622"></a>Prints formatted data to a specified file. </p>
</td>
</tr>
<tr id="row2086877951165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1324789074165622"><a name="p1324789074165622"></a><a name="p1324789074165622"></a><a href="IO.md#ga0d0a950c2b4e6fba795cb7d8f2e8b8b8">vdprintf</a> (int fd, const char *format, va_list ap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1618926560165622"><a name="p1618926560165622"></a><a name="p1618926560165622"></a>int </p>
<p id="p1813369604165622"><a name="p1813369604165622"></a><a name="p1813369604165622"></a>Prints formatted data from a variable argument list to a specified file. </p>
</td>
</tr>
<tr id="row55641343165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1205096161165622"><a name="p1205096161165622"></a><a name="p1205096161165622"></a><a href="IO.md#gab486b89691678e4873ec8b1b15c2678a">ftrylockfile</a> (<a href="IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *filehandle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1714059313165622"><a name="p1714059313165622"></a><a name="p1714059313165622"></a>int </p>
<p id="p449043598165622"><a name="p449043598165622"></a><a name="p449043598165622"></a>Locks a specified file. </p>
</td>
</tr>
<tr id="row699667479165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1824105146165622"><a name="p1824105146165622"></a><a name="p1824105146165622"></a><a href="IO.md#ga4f016c54ff86ca62454417bb7b32ab11">funlockfile</a> (<a href="IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *filehandle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p441592701165622"><a name="p441592701165622"></a><a name="p441592701165622"></a>void </p>
<p id="p179320763165622"><a name="p179320763165622"></a><a name="p179320763165622"></a>Unlocks a specified file. </p>
</td>
</tr>
<tr id="row123559637165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p576777002165622"><a name="p576777002165622"></a><a name="p576777002165622"></a><a href="IO.md#ga169f9b7e933ba56156885e30f7263b28">getc_unlocked</a> (<a href="IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p501910518165622"><a name="p501910518165622"></a><a name="p501910518165622"></a>int </p>
<p id="p391352700165622"><a name="p391352700165622"></a><a name="p391352700165622"></a>Obtains a character from a specified file stream without locking the file stream or checking whether it is locked. </p>
</td>
</tr>
<tr id="row1486398147165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p543020140165622"><a name="p543020140165622"></a><a name="p543020140165622"></a><a href="IO.md#gafef7e39f2376c63728163cd5ccfbe99e">getchar_unlocked</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1279081758165622"><a name="p1279081758165622"></a><a name="p1279081758165622"></a>int </p>
<p id="p637309118165622"><a name="p637309118165622"></a><a name="p637309118165622"></a>Obtains the next character from stdin. </p>
</td>
</tr>
<tr id="row1986418765165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1691421021165622"><a name="p1691421021165622"></a><a name="p1691421021165622"></a><a href="IO.md#ga340b21ecb337abb08905095e673672f6">putc_unlocked</a> (int c, <a href="IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1469864530165622"><a name="p1469864530165622"></a><a name="p1469864530165622"></a>int </p>
<p id="p1412778381165622"><a name="p1412778381165622"></a><a name="p1412778381165622"></a>Writes a character to a specified file stream with the thread remains unlocked. </p>
</td>
</tr>
<tr id="row447902953165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1708409244165622"><a name="p1708409244165622"></a><a name="p1708409244165622"></a><a href="IO.md#ga07ff061a8fed45cdedbecdd899b5fdb1">putchar_unlocked</a> (int c)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1096872829165622"><a name="p1096872829165622"></a><a name="p1096872829165622"></a>int </p>
<p id="p1353165767165622"><a name="p1353165767165622"></a><a name="p1353165767165622"></a>Writes a character to the stdout with the thread remains unlocked. </p>
</td>
</tr>
<tr id="row1513585987165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1872618424165622"><a name="p1872618424165622"></a><a name="p1872618424165622"></a><a href="IO.md#gab87a24b4c09e8fc3712a6d6090bfd371">getdelim</a> (char **lineptr, size_t *n, int delim, <a href="IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p156469229165622"><a name="p156469229165622"></a><a name="p156469229165622"></a>ssize_t </p>
<p id="p456084001165622"><a name="p456084001165622"></a><a name="p456084001165622"></a>Reads an entire line from a specified file stream. </p>
</td>
</tr>
<tr id="row1362222341165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p770610871165622"><a name="p770610871165622"></a><a name="p770610871165622"></a><a href="IO.md#gaaf07c1bbc2aa081a54bdd66f0e152312">getline</a> (char **lineptr, size_t *n, <a href="IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1213198790165622"><a name="p1213198790165622"></a><a name="p1213198790165622"></a>ssize_t </p>
<p id="p673246091165622"><a name="p673246091165622"></a><a name="p673246091165622"></a>Reads an entire line from a specified file stream. </p>
</td>
</tr>
<tr id="row1835724364165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p260368565165622"><a name="p260368565165622"></a><a name="p260368565165622"></a><a href="IO.md#ga44dcf948b2c1dc3356d2937635a27839">tempnam</a> (const char *dir, const char *prefix)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1677942730165622"><a name="p1677942730165622"></a><a name="p1677942730165622"></a>char * </p>
<p id="p1800537785165622"><a name="p1800537785165622"></a><a name="p1800537785165622"></a>Creates a temporary file with a unique file name. </p>
</td>
</tr>
<tr id="row227334325165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p17274934165622"><a name="p17274934165622"></a><a name="p17274934165622"></a><a href="IO.md#ga53a57437279b4ed57b7f116dfc9cbbcc">setbuffer</a> (<a href="IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *f, char *buf, size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1719950998165622"><a name="p1719950998165622"></a><a name="p1719950998165622"></a>void </p>
<p id="p1290370356165622"><a name="p1290370356165622"></a><a name="p1290370356165622"></a>Sets the buffer for a specified file stream. </p>
</td>
</tr>
<tr id="row872984224165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p210474510165622"><a name="p210474510165622"></a><a name="p210474510165622"></a><a href="IO.md#ga2e13e101d5a57cfccf1bab51f8768a5d">setlinebuf</a> (<a href="IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *f)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1276623490165622"><a name="p1276623490165622"></a><a name="p1276623490165622"></a>void </p>
<p id="p485953514165622"><a name="p485953514165622"></a><a name="p485953514165622"></a>Sets the linear buffer for a specified file stream. </p>
</td>
</tr>
<tr id="row201267733165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p887078212165622"><a name="p887078212165622"></a><a name="p887078212165622"></a><a href="IO.md#gab11a990e4f8863a1e7736e3c1d430092">fgetc</a> (<a href="IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p792139842165622"><a name="p792139842165622"></a><a name="p792139842165622"></a>int </p>
<p id="p1193136659165622"><a name="p1193136659165622"></a><a name="p1193136659165622"></a>Reads a character from the file pointed to by <strong id="b1754776476165622"><a name="b1754776476165622"></a><a name="b1754776476165622"></a>stream</strong>. </p>
</td>
</tr>
<tr id="row7978197165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p369888571165622"><a name="p369888571165622"></a><a name="p369888571165622"></a><a href="IO.md#ga9b8e6d63482eb1fe38f3eb9d7fc9bd8e">fgetc_unlocked</a> (<a href="IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p652991312165622"><a name="p652991312165622"></a><a name="p652991312165622"></a>int </p>
<p id="p1646907105165622"><a name="p1646907105165622"></a><a name="p1646907105165622"></a>Reads a character from the file pointed to by <strong id="b1519396940165622"><a name="b1519396940165622"></a><a name="b1519396940165622"></a>stream</strong> with the thread remains unlocked. </p>
</td>
</tr>
<tr id="row500464597165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p643078783165622"><a name="p643078783165622"></a><a name="p643078783165622"></a><a href="IO.md#gab8680ff3f49f3fe7ce0fb78b4cb8394c">fputc_unlocked</a> (int c, <a href="IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1588214851165622"><a name="p1588214851165622"></a><a name="p1588214851165622"></a>int </p>
<p id="p541796268165622"><a name="p541796268165622"></a><a name="p541796268165622"></a>Writes a character to the file stream pointed to by <strong id="b924892555165622"><a name="b924892555165622"></a><a name="b924892555165622"></a>stream</strong> at the current position. </p>
</td>
</tr>
<tr id="row2089390628165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1282625975165622"><a name="p1282625975165622"></a><a name="p1282625975165622"></a><a href="IO.md#ga089fd72e6218cf6805c8fc21123d3d5f">ferror_unlocked</a> (<a href="IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p941153088165622"><a name="p941153088165622"></a><a name="p941153088165622"></a>int </p>
<p id="p1632158172165622"><a name="p1632158172165622"></a><a name="p1632158172165622"></a>Tests for the error identifier of a specified file stream. </p>
</td>
</tr>
<tr id="row454417496165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1415869241165622"><a name="p1415869241165622"></a><a name="p1415869241165622"></a><a href="IO.md#ga6d475ead5d1f35e3f14423a99ef3a992">getw</a> (<a href="IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1629599211165622"><a name="p1629599211165622"></a><a name="p1629599211165622"></a>int </p>
<p id="p1072581494165622"><a name="p1072581494165622"></a><a name="p1072581494165622"></a>Reads a word (an int value) from a specified file stream. </p>
</td>
</tr>
<tr id="row1064125249165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p453739209165622"><a name="p453739209165622"></a><a name="p453739209165622"></a><a href="IO.md#gae3a2f96dac9fa87b964b69ff6d5cce46">putw</a> (int w, <a href="IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1046534983165622"><a name="p1046534983165622"></a><a name="p1046534983165622"></a>int </p>
<p id="p1870694697165622"><a name="p1870694697165622"></a><a name="p1870694697165622"></a>Writes a word (an int value) to a specified file stream. </p>
</td>
</tr>
<tr id="row1864302394165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1642253028165622"><a name="p1642253028165622"></a><a name="p1642253028165622"></a><a href="IO.md#ga8e6fe2fcd5eaa8e2d146a50eeaae5b40">fgetln</a> (<a href="IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1">FILE</a> *stream, size_t *len)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p861321141165622"><a name="p861321141165622"></a><a name="p861321141165622"></a>char * </p>
<p id="p1764690919165622"><a name="p1764690919165622"></a><a name="p1764690919165622"></a>Reads a line of data from the current position of a specified file stream. </p>
</td>
</tr>
<tr id="row1163795119165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1511154907165622"><a name="p1511154907165622"></a><a name="p1511154907165622"></a><a href="IO.md#ga1af9acc6b6efdca3576cb8223d95f401">asprintf</a> (char **strp, const char *fmt,...)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1525395012165622"><a name="p1525395012165622"></a><a name="p1525395012165622"></a>int </p>
<p id="p436143877165622"><a name="p436143877165622"></a><a name="p436143877165622"></a>Prints formatted data to a specified character string. </p>
</td>
</tr>
<tr id="row1208954484165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p412918268165622"><a name="p412918268165622"></a><a name="p412918268165622"></a><a href="IO.md#ga5ec7fd90ebe6015636bce974c192c86a">vasprintf</a> (char **strp, const char *fmt, va_list ap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p739975189165622"><a name="p739975189165622"></a><a name="p739975189165622"></a>int </p>
<p id="p827739933165622"><a name="p827739933165622"></a><a name="p827739933165622"></a>Prints formatted data from a variable argument list to a specified character string. </p>
</td>
</tr>
<tr id="row432816692165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1257865944165622"><a name="p1257865944165622"></a><a name="p1257865944165622"></a><a href="IO.md#gaf916439863bed6ba92594e390c227c7e">select</a> (int nfds, <a href="fd_set.md">fd_set</a> *__restrict readfds, <a href="fd_set.md">fd_set</a> *__restrict writefds, <a href="fd_set.md">fd_set</a> *__restrict exceptfds, struct <a href="timeval.md">timeval</a> *__restrict timeout)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p398296810165622"><a name="p398296810165622"></a><a name="p398296810165622"></a>int </p>
<p id="p1268476126165622"><a name="p1268476126165622"></a><a name="p1268476126165622"></a>Monitors the I/O events of multiple file descriptors. </p>
</td>
</tr>
<tr id="row1848884928165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1451078837165622"><a name="p1451078837165622"></a><a name="p1451078837165622"></a><a href="IO.md#gaa1952d693ed3c43292566e643ceb9858">readv</a> (int fd, const struct iovec *iov, int iovcnt)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1957930599165622"><a name="p1957930599165622"></a><a name="p1957930599165622"></a>ssize_t </p>
<p id="p1894741973165622"><a name="p1894741973165622"></a><a name="p1894741973165622"></a>Reads the data of <strong id="b1363655194165622"><a name="b1363655194165622"></a><a name="b1363655194165622"></a>fd</strong> to <strong id="b1400566801165622"><a name="b1400566801165622"></a><a name="b1400566801165622"></a>iov</strong>. </p>
</td>
</tr>
<tr id="row1625400903165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1393654492165622"><a name="p1393654492165622"></a><a name="p1393654492165622"></a><a href="IO.md#gad57f362a0aef72b52ea59288f74dd1ea">writev</a> (int fd, const struct iovec *iov, int iovcnt)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p683029686165622"><a name="p683029686165622"></a><a name="p683029686165622"></a>ssize_t </p>
<p id="p657373023165622"><a name="p657373023165622"></a><a name="p657373023165622"></a>Writes a given length of data into a file. </p>
</td>
</tr>
<tr id="row553648922165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1817093754165622"><a name="p1817093754165622"></a><a name="p1817093754165622"></a><a href="IO.md#ga94adc8dd94a6bdaaa9cf4d9f388418b3">preadv</a> (int fd, const struct iovec *iov, int iovcnt, off_t offset)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1256851884165622"><a name="p1256851884165622"></a><a name="p1256851884165622"></a>ssize_t </p>
<p id="p812499770165622"><a name="p812499770165622"></a><a name="p812499770165622"></a>Reads the data in a file whose <strong id="b161542613165622"><a name="b161542613165622"></a><a name="b161542613165622"></a>fd</strong> offset is <strong id="b662639234165622"><a name="b662639234165622"></a><a name="b662639234165622"></a>offset</strong> to the multi-group buffer space pointed to by <strong id="b616734603165622"><a name="b616734603165622"></a><a name="b616734603165622"></a>iov</strong>. </p>
</td>
</tr>
<tr id="row1205328273165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1072934565165622"><a name="p1072934565165622"></a><a name="p1072934565165622"></a><a href="IO.md#ga3de6f9331d6bb930e748bb61860edbd6">pwritev</a> (int fd, const struct iovec *iov, int iovcnt, off_t offset)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p490628286165622"><a name="p490628286165622"></a><a name="p490628286165622"></a>ssize_t </p>
<p id="p396245922165622"><a name="p396245922165622"></a><a name="p396245922165622"></a>Writes the data of a multi-group buffer space pointed to by <strong id="b1451559259165622"><a name="b1451559259165622"></a><a name="b1451559259165622"></a>iov</strong> to the offset of <strong id="b390060740165622"><a name="b390060740165622"></a><a name="b390060740165622"></a>fd</strong>. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section611262313165622"></a>

## **Macro Definition **<a name="section1524028957165622"></a>

## FD\_CLR<a name="ga60efc4a969e971f91b7a73bcace62e58"></a>

```
#define FD_CLR( d,  s )   ((s)->fds_bits[(d)/(8*sizeof(long))] &= ~(1UL<<((d)%(8*sizeof(long)))))
```

 **Description:**

Removes a file descriptor from a set. 

**Parameters:**

<a name="table418315569165622"></a>
<table><thead align="left"><tr id="row2033409956165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p867289062165622"><a name="p867289062165622"></a><a name="p867289062165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1903454016165622"><a name="p1903454016165622"></a><a name="p1903454016165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1110507596165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">d</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the file descriptor of the <strong id="b1597299250165622"><a name="b1597299250165622"></a><a name="b1597299250165622"></a>int</strong> type. </td>
</tr>
<tr id="row1473309054165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">s</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the descriptor set of the <strong id="b1211635980165622"><a name="b1211635980165622"></a><a name="b1211635980165622"></a><a href="fd_set.md">fd_set</a></strong> type. </td>
</tr>
</tbody>
</table>

## FD\_ISSET<a name="ga99a3a0e4d7d1d3eb7be68f37554c0a30"></a>

```
#define FD_ISSET( d,  s )   !!((s)->fds_bits[(d)/(8*sizeof(long))] & (1UL<<((d)%(8*sizeof(long)))))
```

 **Description:**

Checks whether a file descriptor is in a set. 

**Parameters:**

<a name="table1838559826165622"></a>
<table><thead align="left"><tr id="row1288417399165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1509065803165622"><a name="p1509065803165622"></a><a name="p1509065803165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1913955297165622"><a name="p1913955297165622"></a><a name="p1913955297165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1685868760165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">d</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the file descriptor of the <strong id="b982547661165622"><a name="b982547661165622"></a><a name="b982547661165622"></a>int</strong> type. </td>
</tr>
<tr id="row151905528165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">s</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the descriptor set of the <strong id="b445946429165622"><a name="b445946429165622"></a><a name="b445946429165622"></a><a href="fd_set.md">fd_set</a></strong> type. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the file descriptor is not in the set; returns  **1**  if the file descriptor is in the set. 

## FD\_SET<a name="gaa7701be461ce602ff7043cbd898a0c53"></a>

```
#define FD_SET( d,  s )   ((s)->fds_bits[(d)/(8*sizeof(long))] |= (1UL<<((d)%(8*sizeof(long)))))
```

 **Description:**

Adds a file descriptor to a set. 

**Parameters:**

<a name="table1195321265165622"></a>
<table><thead align="left"><tr id="row297137872165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1783971257165622"><a name="p1783971257165622"></a><a name="p1783971257165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p412095300165622"><a name="p412095300165622"></a><a name="p412095300165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row242182830165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">d</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the file descriptor of the <strong id="b788266681165622"><a name="b788266681165622"></a><a name="b788266681165622"></a>int</strong> type. </td>
</tr>
<tr id="row1341816906165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">s</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the descriptor set of the <strong id="b198544681165622"><a name="b198544681165622"></a><a name="b198544681165622"></a><a href="fd_set.md">fd_set</a></strong> type. </td>
</tr>
</tbody>
</table>

## FD\_ZERO<a name="ga92ab86a10f942411365b9078833559f0"></a>

```
#define FD_ZERO( s)   do { int __i; unsigned long *__b=(s)->fds_bits; for(__i=sizeof ([fd_set](fd_set.md))/sizeof (long); __i; __i--) *__b++=0; } while(0)
```

 **Description:**

Clears all elements in the file descriptor set. 

**Parameters:**

<a name="table2087708048165622"></a>
<table><thead align="left"><tr id="row2026232588165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1155948346165622"><a name="p1155948346165622"></a><a name="p1155948346165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p931008035165622"><a name="p931008035165622"></a><a name="p931008035165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1249461140165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">s</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the descriptor set of the <strong id="b1412453526165622"><a name="b1412453526165622"></a><a name="b1412453526165622"></a><a href="fd_set.md">fd_set</a></strong> type. </td>
</tr>
</tbody>
</table>

## **Function **<a name="section398272795165622"></a>

## asprintf\(\)<a name="ga1af9acc6b6efdca3576cb8223d95f401"></a>

```
int asprintf (char ** strp, const char * fmt,  ... )
```

 **Description:**

Prints formatted data to a specified character string. 

If the length of the string is uncertain, this function applies for sufficient memory space based on the length of the formatted character string. 

**Parameters:**

<a name="table35463031165622"></a>
<table><thead align="left"><tr id="row565197858165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p20780842165622"><a name="p20780842165622"></a><a name="p20780842165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2100423629165622"><a name="p2100423629165622"></a><a name="p2100423629165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1072615933165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">strp</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double pointer to the start address of the target string. </td>
</tr>
<tr id="row2006018213165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fmt</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the format string. </td>
</tr>
<tr id="row89376481165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">...</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the list of arguments corresponding to the format specifiers. </td>
</tr>
</tbody>
</table>

**Attention:**

If  **strp**  is no longer used, the applied space must be released. 

**Returns:**

Returns the number of output characters if the operation is successful; returns  **-1**  otherwise. 

## clearerr\(\)<a name="ga81202d6a15259fbceb71a961a878b01a"></a>

```
void clearerr ([FILE](IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1) * fp)
```

 **Description:**

Resets the error indicators. 

This function is used to set both the file error indicator and end-of-file indicator to  **0**. 

**Parameters:**

<a name="table65548256165622"></a>
<table><thead align="left"><tr id="row1169902903165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1495017975165622"><a name="p1495017975165622"></a><a name="p1495017975165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1477653346165622"><a name="p1477653346165622"></a><a name="p1477653346165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row380777115165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fp</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the file object that identifies a stream to set. </td>
</tr>
</tbody>
</table>

## dprintf\(\)<a name="ga5fe0fc8fe920b640d488856c5ca43cb5"></a>

```
int dprintf (int fd, const char * format,  ... )
```

 **Description:**

Prints formatted data to a specified file. 

**Parameters:**

<a name="table97904745165622"></a>
<table><thead align="left"><tr id="row628459852165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1637955203165622"><a name="p1637955203165622"></a><a name="p1637955203165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p256698232165622"><a name="p256698232165622"></a><a name="p256698232165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1489481049165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fd</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the file descriptor that identifies a file. </td>
</tr>
<tr id="row304830780165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">format</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the format string. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the total number of written characters if the operation is successful; returns a negative value otherwise. 

## err\(\)<a name="gaa6b66a9a8eb4be40e4424a4dc92ae056"></a>

```
void err (int eval, const char * fmt, va_list args )
```

 **Description:**

Displays error information. 

If the  **fmt**  parameter is not  **NULL**, stderr displays the error code description obtained from strerror\(errno\), followed by a space and a colon \(:\), and the error message to print. 

**Parameters:**

<a name="table1164154599165622"></a>
<table><thead align="left"><tr id="row1531040619165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p465812315165622"><a name="p465812315165622"></a><a name="p465812315165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p952160114165622"><a name="p952160114165622"></a><a name="p952160114165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row297749452165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">eval</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">This function does not return, but exits with the value of <strong id="b1814982404165622"><a name="b1814982404165622"></a><a name="b1814982404165622"></a>eval</strong>. </td>
</tr>
<tr id="row469201769165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fmt</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the string to format. </td>
</tr>
<tr id="row141123530165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">args</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the parameters initialized by using <a href="UTILS.md#gaa0628ab596c3d7e78f5e08c2d98e24da">va_start</a>. </td>
</tr>
</tbody>
</table>

## errx\(\)<a name="gaeaca83913c785b95d6c50f35207ff739"></a>

```
void errx (int eval, const char * fmt,  ... )
```

 **Description:**

Displays error information. 

This function outputs the executable file name  **argv\[0\]**  and the accepted second formal parameter to stderr. 

**Parameters:**

<a name="table277448985165622"></a>
<table><thead align="left"><tr id="row1034053164165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p603498678165622"><a name="p603498678165622"></a><a name="p603498678165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1626481683165622"><a name="p1626481683165622"></a><a name="p1626481683165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1149910756165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">eval</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">This function does not return, but exits with the value of <strong id="b256622953165622"><a name="b256622953165622"></a><a name="b256622953165622"></a>eval</strong>. </td>
</tr>
<tr id="row513103907165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fmt</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the string to format. </td>
</tr>
</tbody>
</table>

## fclose\(\)<a name="gac41a0ad4b31be2ad59d8222a0de30bda"></a>

```
int fclose ([FILE](IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1) * fd)
```

 **Description:**

Closes a file based on the specified file descriptor. 

**Parameters:**

<a name="table250986084165622"></a>
<table><thead align="left"><tr id="row817728440165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p359818506165622"><a name="p359818506165622"></a><a name="p359818506165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p891162325165622"><a name="p891162325165622"></a><a name="p891162325165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row170973613165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fd</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the file descriptor of the file to close. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table1287132878165622"></a>
<table><thead align="left"><tr id="row1180063302165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1690783979165622"><a name="p1690783979165622"></a><a name="p1690783979165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p131280795165622"><a name="p131280795165622"></a><a name="p131280795165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row690759536165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p90073647165622"><a name="p90073647165622"></a><a name="p90073647165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p501935989165622"><a name="p501935989165622"></a><a name="p501935989165622"></a><strong id="b1804853749165622"><a name="b1804853749165622"></a><a name="b1804853749165622"></a>fd</strong> is <strong id="b346931531165622"><a name="b346931531165622"></a><a name="b346931531165622"></a>NULL</strong>. </p>
</td>
</tr>
</tbody>
</table>

## feof\(\)<a name="gafb95de1535a5a185954819539f3c6ca5"></a>

```
int feof ([FILE](IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1) * fp)
```

 **Description:**

Tests the end-of-file indicator for a specified stream. 

**Parameters:**

<a name="table1989504826165622"></a>
<table><thead align="left"><tr id="row424339643165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2031465345165622"><a name="p2031465345165622"></a><a name="p2031465345165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p727048598165622"><a name="p727048598165622"></a><a name="p727048598165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row954769860165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fp</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the file object that identifies a stream to test. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns a non-zero value if the end-of-file indicator is set; returns  **0**  otherwise. 

## ferror\(\)<a name="ga4a98383bb54291c2abede7aa28acf597"></a>

```
int ferror ([FILE](IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1) * stream)
```

 **Description:**

Tests for the error identifier of a specified file stream. 

**Parameters:**

<a name="table1036987328165622"></a>
<table><thead align="left"><tr id="row364054704165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p267762322165622"><a name="p267762322165622"></a><a name="p267762322165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1426048762165622"><a name="p1426048762165622"></a><a name="p1426048762165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row542923148165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">stream</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the file object that identifies a stream. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns a non-zero value to indicate an error for the stream if the operation is successful; returns  **0**  otherwise. 

## ferror\_unlocked\(\)<a name="ga089fd72e6218cf6805c8fc21123d3d5f"></a>

```
int ferror_unlocked ([FILE](IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1) * stream)
```

 **Description:**

Tests for the error identifier of a specified file stream. 

**Parameters:**

<a name="table1417437729165622"></a>
<table><thead align="left"><tr id="row561111607165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p780152370165622"><a name="p780152370165622"></a><a name="p780152370165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p794773045165622"><a name="p794773045165622"></a><a name="p794773045165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1602137042165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">stream</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the file object that identifies a stream. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns a non-zero value to indicate an error for the stream if the operation is successful; returns  **0**  otherwise. 

## fflush\(\)<a name="gae4459e830d3e2abcf428337a661d9456"></a>

```
int fflush ([FILE](IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1) * fp)
```

 **Description:**

Flushes the output buffer of a specified stream. 

**Parameters:**

<a name="table1272572290165622"></a>
<table><thead align="left"><tr id="row2097104711165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2009638988165622"><a name="p2009638988165622"></a><a name="p2009638988165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2041697224165622"><a name="p2041697224165622"></a><a name="p2041697224165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1343225180165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fp</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the file object that identifies a stream to flush. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table1902485312165622"></a>
<table><thead align="left"><tr id="row341873750165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1241823577165622"><a name="p1241823577165622"></a><a name="p1241823577165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p185990800165622"><a name="p185990800165622"></a><a name="p185990800165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1676626539165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p31384391165622"><a name="p31384391165622"></a><a name="p31384391165622"></a>EBADF </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1767835058165622"><a name="p1767835058165622"></a><a name="p1767835058165622"></a><strong id="b535631621165622"><a name="b535631621165622"></a><a name="b535631621165622"></a>fp</strong> points to an invalid stream. </p>
</td>
</tr>
</tbody>
</table>

## fgetc\(\)<a name="gab11a990e4f8863a1e7736e3c1d430092"></a>

```
int fgetc ([FILE](IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1) * stream)
```

 **Description:**

Reads a character from the file pointed to by  **stream**. 

This function reads the next character from the current position of the file stream and returns the character, then advances the file position indicator. You can read each character of the file by continuously calling this function. 

**Parameters:**

<a name="table1632049293165622"></a>
<table><thead align="left"><tr id="row1106204908165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p699159276165622"><a name="p699159276165622"></a><a name="p699159276165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1684473481165622"><a name="p1684473481165622"></a><a name="p1684473481165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row215140000165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">stream</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the file object that identifies a stream. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the character read as an int value if the operation is successful; returns  **EOF**  if the end-of-file is reached or a reading error occurs. 

## fgetc\_unlocked\(\)<a name="ga9b8e6d63482eb1fe38f3eb9d7fc9bd8e"></a>

```
int fgetc_unlocked ([FILE](IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1) * stream)
```

 **Description:**

Reads a character from the file pointed to by  **stream**  with the thread remains unlocked. 

This function reads the next character from the current position of the file stream and returns the character, then advances the file position indicator. You can read each character of the file by continuously calling this function. 

**Parameters:**

<a name="table807502260165622"></a>
<table><thead align="left"><tr id="row220544605165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p610666668165622"><a name="p610666668165622"></a><a name="p610666668165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p641375743165622"><a name="p641375743165622"></a><a name="p641375743165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row247663698165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">stream</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the file object that identifies a stream. </td>
</tr>
</tbody>
</table>

**Attention:**

This function cannot be used in a multi-thread process because it does not use locking during the call. \(It does not set locks itself, and does not test for the presence of locks set by others.\) An error occurs upon a multi-thread operation. 

**Returns:**

Returns the character read as an int value if the operation is successful; returns  **EOF**  if the end-of-file is reached or a reading error occurs. 

## fgetln\(\)<a name="ga8e6fe2fcd5eaa8e2d146a50eeaae5b40"></a>

```
char* fgetln ([FILE](IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1) * stream, size_t * len )
```

 **Description:**

Reads a line of data from the current position of a specified file stream. 

**Parameters:**

<a name="table1087298664165622"></a>
<table><thead align="left"><tr id="row421844743165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1460074472165622"><a name="p1460074472165622"></a><a name="p1460074472165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p764595389165622"><a name="p764595389165622"></a><a name="p764595389165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1765795354165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">stream</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the file object that identifies a stream. </td>
</tr>
<tr id="row1377759122165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">len</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the length of the string that is read. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the string read. 

## fgetpos\(\)<a name="gaf2e2b1a01359f5f7068b61d1dffcdcdd"></a>

```
int fgetpos ([FILE](IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1) * stream, fpos_t * pos )
```

 **Description:**

Obtains the current file position of a specified stream and writes it to the  **pos**  parameter. 

**Parameters:**

<a name="table1672191685165622"></a>
<table><thead align="left"><tr id="row2042305103165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p491797383165622"><a name="p491797383165622"></a><a name="p491797383165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1152298158165622"><a name="p1152298158165622"></a><a name="p1152298158165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row966723599165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">stream</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the file object that identifies a stream. </td>
</tr>
<tr id="row1006085024165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">pos</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the <strong id="b2047941384165622"><a name="b2047941384165622"></a><a name="b2047941384165622"></a>fpos_t</strong> object. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise. 

## fgets\(\)<a name="ga2b3df0e66b41edab3c039191fe6cc4f9"></a>

```
char* fgets (char * s, int size, [FILE](IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1) * stream )
```

 **Description:**

Reads a line of characters from a specified file stream and stores it into the string pointed to by  **s**. 

**Parameters:**

<a name="table2142722614165622"></a>
<table><thead align="left"><tr id="row113176733165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p924399899165622"><a name="p924399899165622"></a><a name="p924399899165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1925357095165622"><a name="p1925357095165622"></a><a name="p1925357095165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row616741179165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">s</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the character array for storing the obtained string. </td>
</tr>
<tr id="row1124430694165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">size</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the maximum number of characters to read (including the terminating null character). The value of this parameter is usually the length of the array pointed to by <strong id="b1285519358165622"><a name="b1285519358165622"></a><a name="b1285519358165622"></a>s</strong>. </td>
</tr>
<tr id="row1394114220165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">stream</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the file object that identifies a stream. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the pointer to the read string if the operation is successful; returns a null pointer if the end-of-file is reached, no characters have been read, or if an error occurs. 

## fileno\(\)<a name="ga03681b8592bba6fe02941b9abc182808"></a>

```
int fileno ([FILE](IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1) * fp)
```

 **Description:**

Obtains the file descriptor of a specified file stream. 

**Parameters:**

<a name="table1758429997165622"></a>
<table><thead align="left"><tr id="row1862596939165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p634778208165622"><a name="p634778208165622"></a><a name="p634778208165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2040954345165622"><a name="p2040954345165622"></a><a name="p2040954345165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row143108879165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fp</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the file object that identifies a stream for which the file descriptor is obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the file descriptor if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table otherwise. 

<a name="table425349400165622"></a>
<table><thead align="left"><tr id="row1583092802165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1367888996165622"><a name="p1367888996165622"></a><a name="p1367888996165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1514822979165622"><a name="p1514822979165622"></a><a name="p1514822979165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1889896479165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p569249743165622"><a name="p569249743165622"></a><a name="p569249743165622"></a>EBADF </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1079281945165622"><a name="p1079281945165622"></a><a name="p1079281945165622"></a><strong id="b286615211165622"><a name="b286615211165622"></a><a name="b286615211165622"></a>fp</strong> points to an invalid stream. </p>
</td>
</tr>
</tbody>
</table>

## fmemopen\(\)<a name="ga6b2efc6515c53ab5f0c9800c35f65789"></a>

```
[FILE](IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1)* fmemopen (void * buf, size_t size, const char * mode )
```

 **Description:**

Opens a memory stream that allows the access mode specified by  **mode**. 

This function is used for applications that do not support memory operations but support file operations. After the function call, you can directly operate the returned file stream, which is equivalent to operating the memory stream. 

**Parameters:**

<a name="table1949319514165622"></a>
<table><thead align="left"><tr id="row999775935165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p136120477165622"><a name="p136120477165622"></a><a name="p136120477165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2098224003165622"><a name="p2098224003165622"></a><a name="p2098224003165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row44495614165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">buf</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the buffer. </td>
</tr>
<tr id="row943087729165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">size</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the size of the buffer. </td>
</tr>
<tr id="row2091112822165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">mode</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the file operation mode. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the opened memory stream as a file stream. 

## fopen\(\)<a name="ga58386e895d3c07b008c8865b2a9716fb"></a>

```
[FILE](IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1)* fopen (const char *__restrict path, const char *__restrict mode )
```

 **Description:**

Opens the file stored in the specified path based on the given mode. 

**Parameters:**

<a name="table1610671366165622"></a>
<table><thead align="left"><tr id="row1566134699165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p941043104165622"><a name="p941043104165622"></a><a name="p941043104165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1492678753165622"><a name="p1492678753165622"></a><a name="p1492678753165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1345638894165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">path</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the path of the file to open. </td>
</tr>
<tr id="row1531168105165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">mode</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the file access mode. The following table describes the available values. </td>
</tr>
</tbody>
</table>

<a name="table1803626789165622"></a>
<table><thead align="left"><tr id="row344198502165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1877022924165622"><a name="p1877022924165622"></a><a name="p1877022924165622"></a>mode </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1282227742165622"><a name="p1282227742165622"></a><a name="p1282227742165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1098590698165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p611304186165622"><a name="p611304186165622"></a><a name="p611304186165622"></a>"r" </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1807142034165622"><a name="p1807142034165622"></a><a name="p1807142034165622"></a>Open a file in read-only mode. The file must exist. </p>
</td>
</tr>
<tr id="row155453094165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p380470109165622"><a name="p380470109165622"></a><a name="p380470109165622"></a>"w" </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1886649791165622"><a name="p1886649791165622"></a><a name="p1886649791165622"></a>Open a file in write-only mode. The file is created if it does not exist. If the file already exists, its existing contents will be cleared. </p>
</td>
</tr>
<tr id="row542345057165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p247626943165622"><a name="p247626943165622"></a><a name="p247626943165622"></a>"a" </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p935055699165622"><a name="p935055699165622"></a><a name="p935055699165622"></a>Open a write-only file in append mode. The file is created if it does not exist. If the file already exists, new contents will be written at the end of the file. </p>
</td>
</tr>
<tr id="row110218536165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1490841623165622"><a name="p1490841623165622"></a><a name="p1490841623165622"></a>"r+" </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1615635967165622"><a name="p1615635967165622"></a><a name="p1615635967165622"></a>Open a file in read and write mode. The file must exist. </p>
</td>
</tr>
<tr id="row1624818921165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1440887025165622"><a name="p1440887025165622"></a><a name="p1440887025165622"></a>"w+" </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p19775728165622"><a name="p19775728165622"></a><a name="p19775728165622"></a>Open a file for both reading and writing. The file is created if it does not exist. If the file already exists, its contents are cleared. </p>
</td>
</tr>
<tr id="row42064553165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1202818611165622"><a name="p1202818611165622"></a><a name="p1202818611165622"></a>"a+" </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1641753856165622"><a name="p1641753856165622"></a><a name="p1641753856165622"></a>Open a file in append mode for both reading and writing. The file is created if it does not exist. If the file already exists, new contents will be written at the end of the file. </p>
</td>
</tr>
<tr id="row1748754523165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1478100091165622"><a name="p1478100091165622"></a><a name="p1478100091165622"></a>"rb" </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p773779985165622"><a name="p773779985165622"></a><a name="p773779985165622"></a>Open a binary file in read-only mode. </p>
</td>
</tr>
<tr id="row687677993165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p953107552165622"><a name="p953107552165622"></a><a name="p953107552165622"></a>"wb" </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p64835220165622"><a name="p64835220165622"></a><a name="p64835220165622"></a>Open or create a binary file in write-only mode. </p>
</td>
</tr>
<tr id="row1232804646165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p90664472165622"><a name="p90664472165622"></a><a name="p90664472165622"></a>"ab" </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p521837064165622"><a name="p521837064165622"></a><a name="p521837064165622"></a>Open a binary file in append mode and write data at the end of the file. </p>
</td>
</tr>
<tr id="row442166183165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1738477569165622"><a name="p1738477569165622"></a><a name="p1738477569165622"></a>"rb+" </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1312033151165622"><a name="p1312033151165622"></a><a name="p1312033151165622"></a>Open a binary file in read and write mode. The file must exist. </p>
</td>
</tr>
<tr id="row971074988165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p612947102165622"><a name="p612947102165622"></a><a name="p612947102165622"></a>"wb+" </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1733132614165622"><a name="p1733132614165622"></a><a name="p1733132614165622"></a>Open or create a binary file in read and write mode. </p>
</td>
</tr>
<tr id="row1389432451165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1223648384165622"><a name="p1223648384165622"></a><a name="p1223648384165622"></a>"ab+" </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1410249342165622"><a name="p1410249342165622"></a><a name="p1410249342165622"></a>Open a binary file in append mode for wring data at the end of the file. The file is also readable. </p>
</td>
</tr>
<tr id="row1497942019165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1642052763165622"><a name="p1642052763165622"></a><a name="p1642052763165622"></a>"rt" </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1916073805165622"><a name="p1916073805165622"></a><a name="p1916073805165622"></a>Open a text file in read-only mode. </p>
</td>
</tr>
<tr id="row1775859523165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p445570856165622"><a name="p445570856165622"></a><a name="p445570856165622"></a>"wt" </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p714394808165622"><a name="p714394808165622"></a><a name="p714394808165622"></a>Open or create a text file in write-only mode. </p>
</td>
</tr>
<tr id="row1686123169165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1611736331165622"><a name="p1611736331165622"></a><a name="p1611736331165622"></a>"at" </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p815060575165622"><a name="p815060575165622"></a><a name="p815060575165622"></a>Open a text file in append mode and write data at the end of the file. </p>
</td>
</tr>
<tr id="row1564972419165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p725851214165622"><a name="p725851214165622"></a><a name="p725851214165622"></a>"rt+" </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p379563620165622"><a name="p379563620165622"></a><a name="p379563620165622"></a>Open a text file in read and write mode. </p>
</td>
</tr>
<tr id="row777979101165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2018556142165622"><a name="p2018556142165622"></a><a name="p2018556142165622"></a>"wt+" </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1839848602165622"><a name="p1839848602165622"></a><a name="p1839848602165622"></a>Open or create a text file in read and write mode. </p>
</td>
</tr>
<tr id="row2112643350165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p429388452165622"><a name="p429388452165622"></a><a name="p429388452165622"></a>"at+" </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2088707312165622"><a name="p2088707312165622"></a><a name="p2088707312165622"></a>Open a text file in append mode for writing data at the end of the file. The file is also readable. </p>
</td>
</tr>
</tbody>
</table>

**Attention:**

This function can NOT be used in the PROC file system to create a file. 

**Returns:**

Returns the pointer to the file if the operation is successful; returns  **NULL**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table1575876202165622"></a>
<table><thead align="left"><tr id="row1928726522165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1789869837165622"><a name="p1789869837165622"></a><a name="p1789869837165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2028053582165622"><a name="p2028053582165622"></a><a name="p2028053582165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1897935337165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1118649894165622"><a name="p1118649894165622"></a><a name="p1118649894165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p4008190165622"><a name="p4008190165622"></a><a name="p4008190165622"></a>Invalid mode. </p>
</td>
</tr>
<tr id="row1932852526165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1283041067165622"><a name="p1283041067165622"></a><a name="p1283041067165622"></a>EMFILE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p361167876165622"><a name="p361167876165622"></a><a name="p361167876165622"></a>The number of opened files exceeds the maximum number. </p>
</td>
</tr>
</tbody>
</table>

## fprintf\(\)<a name="gad9291335f34e874c8431285d705bc3aa"></a>

```
int fprintf ([FILE](IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1) * stream, const char * format,  ... )
```

 **Description:**

Formats arguments based on  **format**  and prints formatted data to a specified file stream. 

**Parameters:**

<a name="table1120948117165622"></a>
<table><thead align="left"><tr id="row396703107165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1609850750165622"><a name="p1609850750165622"></a><a name="p1609850750165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1933941399165622"><a name="p1933941399165622"></a><a name="p1933941399165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row167323762165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">stream</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the file object that identifies a stream. </td>
</tr>
<tr id="row1401784934165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">format</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the format string. </td>
</tr>
<tr id="row2080515609165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">...</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the list of arguments corresponding to the format specifiers. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the total number of characters \(excluding the terminating null character  **'\\0'**\) if the operation is successful; returns a negative value otherwise. 

## fputc\(\)<a name="gabe6299d5823dd023e610aaa619735a3f"></a>

```
int fputc (int c, [FILE](IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1) * stream )
```

 **Description:**

Writes a character into the position pointed to by a specified stream. 

**Parameters:**

<a name="table1367774003165622"></a>
<table><thead align="left"><tr id="row1563701668165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p334237146165622"><a name="p334237146165622"></a><a name="p334237146165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p594380265165622"><a name="p594380265165622"></a><a name="p594380265165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row27652445165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">c</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the int promotion of the character to write. </td>
</tr>
<tr id="row610319416165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">stream</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the file object that identifies a stream. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the ASCII code of the character written if the operation is successful; returns  **EOF**  otherwise. 

## fputc\_unlocked\(\)<a name="gab8680ff3f49f3fe7ce0fb78b4cb8394c"></a>

```
int fputc_unlocked (int c, [FILE](IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1) * stream )
```

 **Description:**

Writes a character to the file stream pointed to by  **stream**  at the current position. 

**Parameters:**

<a name="table1397003827165622"></a>
<table><thead align="left"><tr id="row1281768791165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1449239491165622"><a name="p1449239491165622"></a><a name="p1449239491165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p693539222165622"><a name="p693539222165622"></a><a name="p693539222165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row119654949165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">c</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the int promotion of the character to write. </td>
</tr>
<tr id="row1845533000165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">stream</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the file stream. </td>
</tr>
</tbody>
</table>

**Attention:**

This function cannot be used in a multi-thread process because it does not use locking during the call. \(It does not set locks itself, and does not test for the presence of locks set by others.\) An error occurs upon a multi-thread operation. 

**Returns:**

Returns the ASCII code of the character written if the operation is successful; returns  **EOF**  otherwise. 

## fputs\(\)<a name="ga68236e664c1f0da049b25fba1c1695f6"></a>

```
int fputs (const char * s, [FILE](IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1) * stream )
```

 **Description:**

Writes a character string \(excluding the terminating null character\) to a specified file stream. 

**Parameters:**

<a name="table983767272165622"></a>
<table><thead align="left"><tr id="row2130605711165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p883887456165622"><a name="p883887456165622"></a><a name="p883887456165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1838710999165622"><a name="p1838710999165622"></a><a name="p1838710999165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row377756536165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">s</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the character string to write. </td>
</tr>
<tr id="row1491216820165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">stream</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the file object that identifies a stream. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns a non-negative value if the operation is successful; returns  **EOF**  otherwise. 

## fread\(\)<a name="ga091b3f41bdd6984d63ea48d87a62bfd2"></a>

```
size_t fread (void *__restrict ptr, size_t size, size_t nmemb, [FILE](IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1) *__restrict stream )
```

 **Description:**

Reads data from a specified stream. 

**Parameters:**

<a name="table324337147165622"></a>
<table><thead align="left"><tr id="row476861012165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1437623209165622"><a name="p1437623209165622"></a><a name="p1437623209165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p44077046165622"><a name="p44077046165622"></a><a name="p44077046165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row709810308165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">ptr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the array for storing the read data. </td>
</tr>
<tr id="row1047759155165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">size</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the size of each element to read, in bytes. </td>
</tr>
<tr id="row466129475165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">nmemb</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the number of elements to read. </td>
</tr>
<tr id="row1420487338165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">stream</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the file object that identifies a stream to read. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if  **size**  or  **nmemb**  is  **0**; returns the number of elements successfully read otherwise. This function sets  **errno**  to a value in the following table if a reading error occurs or the end-of-file is reached \(**fread**  does not distinguish the two error reporting situations, and you can call  **feof**  and  **ferror**  to determine the specific situation\). 

<a name="table1238884815165622"></a>
<table><thead align="left"><tr id="row1780787145165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p291379299165622"><a name="p291379299165622"></a><a name="p291379299165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p12617731165622"><a name="p12617731165622"></a><a name="p12617731165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row23814507165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p83473349165622"><a name="p83473349165622"></a><a name="p83473349165622"></a>EBADF </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p642310138165622"><a name="p642310138165622"></a><a name="p642310138165622"></a><strong id="b1868965741165622"><a name="b1868965741165622"></a><a name="b1868965741165622"></a>stream</strong> points to an invalid stream. </p>
</td>
</tr>
<tr id="row130796976165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p133368864165622"><a name="p133368864165622"></a><a name="p133368864165622"></a>EEOF </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1165344799165622"><a name="p1165344799165622"></a><a name="p1165344799165622"></a>The end-of-file is reached. </p>
</td>
</tr>
</tbody>
</table>

## freopen\(\)<a name="gaab336dbfc008a0873046ecd7db043df0"></a>

```
[FILE](IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1)* freopen (const char *__restrict path, const char *__restrict mode, [FILE](IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1) *__restrict stream )
```

 **Description:**

Opens the file stored in the specified path, and associates the stream by the given stream. 

**Parameters:**

<a name="table1875861606165622"></a>
<table><thead align="left"><tr id="row1875105425165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1475583148165622"><a name="p1475583148165622"></a><a name="p1475583148165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p560970280165622"><a name="p560970280165622"></a><a name="p560970280165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row717473557165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">path</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the path of the file to open. </td>
</tr>
<tr id="row775170527165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">mode</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the file access mode. The usage is same as which in fopen function. </td>
</tr>
<tr id="row448246100165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">stream</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the stream to associates. </td>
</tr>
</tbody>
</table>

**Attention:**

This function can NOT be used in the PROC file system to create a file. 

**Returns:**

Returns the pointer to the file if the operation is successful; returns  **NULL**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table510526792165622"></a>
<table><thead align="left"><tr id="row929419589165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p770994717165622"><a name="p770994717165622"></a><a name="p770994717165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1886931849165622"><a name="p1886931849165622"></a><a name="p1886931849165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1461949195165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p244636513165622"><a name="p244636513165622"></a><a name="p244636513165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1317845990165622"><a name="p1317845990165622"></a><a name="p1317845990165622"></a>Invalid mode. </p>
</td>
</tr>
<tr id="row1003593641165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p98589419165622"><a name="p98589419165622"></a><a name="p98589419165622"></a>EMFILE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1729307571165622"><a name="p1729307571165622"></a><a name="p1729307571165622"></a>The number of opened files exceeds the maximum number. </p>
</td>
</tr>
<tr id="row1556167563165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1984012112165622"><a name="p1984012112165622"></a><a name="p1984012112165622"></a>EBADF </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1525512494165622"><a name="p1525512494165622"></a><a name="p1525512494165622"></a>The file descriptor of the stream is not valid. </p>
</td>
</tr>
</tbody>
</table>

## fscanf\(\)<a name="gae902a7b8796799a6e076f07e9d7de045"></a>

```
int fscanf ([FILE](IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1) * stream, const char * format,  ... )
```

 **Description:**

Reads formatted data from a specified file stream and stores it based on  **format**  into the locations pointed to by the variable arguments. 

The operation ends when a space or line feed character is encountered. 

**Parameters:**

<a name="table1997665355165622"></a>
<table><thead align="left"><tr id="row707937601165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2103441341165622"><a name="p2103441341165622"></a><a name="p2103441341165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p368099263165622"><a name="p368099263165622"></a><a name="p368099263165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row770577466165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">stream</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the file object that identifies a stream. </td>
</tr>
<tr id="row2009916783165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">format</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the format string. </td>
</tr>
<tr id="row1795976046165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">...</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the list of arguments corresponding to the format specifiers. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the number of variables that are successfully read. If the matching fails quickly, the return value may be less than the number of members in the argument list or even zero. If no complete conversion format is available or the input format fails to be matched,  **EOF**  is returned. The return value is also  **EOF**  if a reading error occurs. 

## fseek\(\)<a name="gaece5d6e00c239ffd0847d8d2ef65bd57"></a>

```
int fseek ([FILE](IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1) * fp, long offset, int whence )
```

 **Description:**

Changes the position of a specified stream to a new position. 

**Parameters:**

<a name="table2139793186165622"></a>
<table><thead align="left"><tr id="row1185039184165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1061901756165622"><a name="p1061901756165622"></a><a name="p1061901756165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1097301694165622"><a name="p1097301694165622"></a><a name="p1097301694165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row321775760165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fp</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the file object that identifies a stream for which the position is to set. </td>
</tr>
<tr id="row883242880165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">offset</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the offset that determines the position. </td>
</tr>
<tr id="row1469581996165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">whence</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the start position of the offset. The following table describes the available values. </td>
</tr>
</tbody>
</table>

<a name="table1077987528165622"></a>
<table><thead align="left"><tr id="row573171904165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p273712250165622"><a name="p273712250165622"></a><a name="p273712250165622"></a>value </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p488510675165622"><a name="p488510675165622"></a><a name="p488510675165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1888867490165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1568392905165622"><a name="p1568392905165622"></a><a name="p1568392905165622"></a>SEEK_SET </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1549272700165622"><a name="p1549272700165622"></a><a name="p1549272700165622"></a>Beginning of the file </p>
</td>
</tr>
<tr id="row495625044165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1788727182165622"><a name="p1788727182165622"></a><a name="p1788727182165622"></a>SEEK_CUR </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1877437730165622"><a name="p1877437730165622"></a><a name="p1877437730165622"></a>Current position </p>
</td>
</tr>
<tr id="row1473296971165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p857025757165622"><a name="p857025757165622"></a><a name="p857025757165622"></a>SEEK_END </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p42445957165622"><a name="p42445957165622"></a><a name="p42445957165622"></a>End of the file </p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table82240506165622"></a>
<table><thead align="left"><tr id="row946003154165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p340513080165622"><a name="p340513080165622"></a><a name="p340513080165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p583861995165622"><a name="p583861995165622"></a><a name="p583861995165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row277576611165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p481564370165622"><a name="p481564370165622"></a><a name="p481564370165622"></a>EBADF </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p662613324165622"><a name="p662613324165622"></a><a name="p662613324165622"></a><strong id="b457190903165622"><a name="b457190903165622"></a><a name="b457190903165622"></a>fp</strong> points to an invalid stream. </p>
</td>
</tr>
<tr id="row1803532599165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p215805643165622"><a name="p215805643165622"></a><a name="p215805643165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1225905576165622"><a name="p1225905576165622"></a><a name="p1225905576165622"></a>The value of <strong id="b82847734165622"><a name="b82847734165622"></a><a name="b82847734165622"></a>whence</strong> is not <strong id="b1378618669165622"><a name="b1378618669165622"></a><a name="b1378618669165622"></a>SEEK_SET</strong>, <strong id="b1232808258165622"><a name="b1232808258165622"></a><a name="b1232808258165622"></a>SEEK_END</strong>, or <strong id="b527846619165622"><a name="b527846619165622"></a><a name="b527846619165622"></a>SEEK_CUR</strong>. </p>
</td>
</tr>
<tr id="row916873773165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p784542124165622"><a name="p784542124165622"></a><a name="p784542124165622"></a>ESPIPE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1961638017165622"><a name="p1961638017165622"></a><a name="p1961638017165622"></a>Invalid seek. </p>
</td>
</tr>
</tbody>
</table>

## fseeko\(\)<a name="ga6926f47b76b028f112045fbe7ced4115"></a>

```
int fseeko ([FILE](IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1) * fp, off_t offset, int whence )
```

 **Description:**

Sets the position of the next input or output operation on a specified file stream. 

**Parameters:**

<a name="table1644123693165622"></a>
<table><thead align="left"><tr id="row618703827165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p352350633165622"><a name="p352350633165622"></a><a name="p352350633165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p54367691165622"><a name="p54367691165622"></a><a name="p54367691165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1222682131165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fp</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the file object that identifies a stream for which the position is to set. </td>
</tr>
<tr id="row625596676165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">offset</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the offset that determines the next operation. </td>
</tr>
<tr id="row80957137165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">whence</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the start position of the offset. The following table describes the available values. </td>
</tr>
</tbody>
</table>

<a name="table2015637694165622"></a>
<table><thead align="left"><tr id="row2011079529165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p329759525165622"><a name="p329759525165622"></a><a name="p329759525165622"></a>value </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1672645911165622"><a name="p1672645911165622"></a><a name="p1672645911165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1991218825165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1608005453165622"><a name="p1608005453165622"></a><a name="p1608005453165622"></a>SEEK_SET </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1939216243165622"><a name="p1939216243165622"></a><a name="p1939216243165622"></a>Beginning of the file </p>
</td>
</tr>
<tr id="row1638296628165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p709886507165622"><a name="p709886507165622"></a><a name="p709886507165622"></a>SEEK_CUR </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1484688553165622"><a name="p1484688553165622"></a><a name="p1484688553165622"></a>Current position </p>
</td>
</tr>
<tr id="row1469594570165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p604304200165622"><a name="p604304200165622"></a><a name="p604304200165622"></a>SEEK_END </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2100457686165622"><a name="p2100457686165622"></a><a name="p2100457686165622"></a>End of the file </p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table983378080165622"></a>
<table><thead align="left"><tr id="row705300714165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1954753927165622"><a name="p1954753927165622"></a><a name="p1954753927165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p265406190165622"><a name="p265406190165622"></a><a name="p265406190165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row541009159165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1520195576165622"><a name="p1520195576165622"></a><a name="p1520195576165622"></a>EBADF </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p540264614165622"><a name="p540264614165622"></a><a name="p540264614165622"></a><strong id="b413694159165622"><a name="b413694159165622"></a><a name="b413694159165622"></a>fp</strong> points to an invalid stream. </p>
</td>
</tr>
<tr id="row256698910165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p453864324165622"><a name="p453864324165622"></a><a name="p453864324165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2041844480165622"><a name="p2041844480165622"></a><a name="p2041844480165622"></a>The value of <strong id="b1077887257165622"><a name="b1077887257165622"></a><a name="b1077887257165622"></a>whence</strong> is not <strong id="b963032396165622"><a name="b963032396165622"></a><a name="b963032396165622"></a>SEEK_SET</strong>, <strong id="b1935112121165622"><a name="b1935112121165622"></a><a name="b1935112121165622"></a>SEEK_END</strong>, or <strong id="b1546873665165622"><a name="b1546873665165622"></a><a name="b1546873665165622"></a>SEEK_CUR</strong>. </p>
</td>
</tr>
<tr id="row2002352570165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p768960913165622"><a name="p768960913165622"></a><a name="p768960913165622"></a>ESPIPE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1256961240165622"><a name="p1256961240165622"></a><a name="p1256961240165622"></a>Invalid seek. </p>
</td>
</tr>
</tbody>
</table>

## fsetpos\(\)<a name="gae47e3f92dd8fc42ce0b6384c03ce6a9b"></a>

```
int fsetpos ([FILE](IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1) * fp, const fpos_t * pos )
```

 **Description:**

Sets the file position indicator for a specified file stream. 

**Parameters:**

<a name="table1158293789165622"></a>
<table><thead align="left"><tr id="row254707053165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1577632732165622"><a name="p1577632732165622"></a><a name="p1577632732165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1795515791165622"><a name="p1795515791165622"></a><a name="p1795515791165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2144878330165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fp</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the file object that identifies a stream for which the position is to set. </td>
</tr>
<tr id="row1433275989165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">pos</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the position to set. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table667978092165622"></a>
<table><thead align="left"><tr id="row117756856165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p269180228165622"><a name="p269180228165622"></a><a name="p269180228165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p222449816165622"><a name="p222449816165622"></a><a name="p222449816165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row574253326165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p879474801165622"><a name="p879474801165622"></a><a name="p879474801165622"></a>EBADF </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1800645434165622"><a name="p1800645434165622"></a><a name="p1800645434165622"></a><strong id="b34745873165622"><a name="b34745873165622"></a><a name="b34745873165622"></a>fp</strong> points to an invalid stream. </p>
</td>
</tr>
<tr id="row509718918165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p955073459165622"><a name="p955073459165622"></a><a name="p955073459165622"></a>ESPIPE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p592387468165622"><a name="p592387468165622"></a><a name="p592387468165622"></a>Invalid seek. </p>
</td>
</tr>
</tbody>
</table>

## ftell\(\)<a name="gaae4231ac8066eb54ea1d9d12d551605c"></a>

```
long ftell ([FILE](IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1) * fp)
```

 **Description:**

Obtains the current value of the file position indicator for a specified file stream. 

**Parameters:**

<a name="table2070107549165622"></a>
<table><thead align="left"><tr id="row1437132227165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2027966977165622"><a name="p2027966977165622"></a><a name="p2027966977165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p133616407165622"><a name="p133616407165622"></a><a name="p133616407165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1287118609165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fp</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the file object that identifies a stream for which the position is to obtain. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the current offset if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table375689589165622"></a>
<table><thead align="left"><tr id="row1595453173165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p338911171165622"><a name="p338911171165622"></a><a name="p338911171165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p943112507165622"><a name="p943112507165622"></a><a name="p943112507165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row128093773165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p362786180165622"><a name="p362786180165622"></a><a name="p362786180165622"></a>EBADF </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1022292937165622"><a name="p1022292937165622"></a><a name="p1022292937165622"></a><strong id="b1425377885165622"><a name="b1425377885165622"></a><a name="b1425377885165622"></a>fp</strong> points to an invalid stream. </p>
</td>
</tr>
</tbody>
</table>

## ftello\(\)<a name="ga5f52ea043b9a2aa4d8cc92d674a2117b"></a>

```
off_t ftello ([FILE](IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1) * fp)
```

 **Description:**

Obtains the current value of the file position indicator for a specified file stream. 

**Parameters:**

<a name="table271760502165622"></a>
<table><thead align="left"><tr id="row1655323437165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p335571909165622"><a name="p335571909165622"></a><a name="p335571909165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1948626862165622"><a name="p1948626862165622"></a><a name="p1948626862165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1372274225165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fp</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the file object that identifies a stream for which the position is to obtain. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the current offset if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table368185301165622"></a>
<table><thead align="left"><tr id="row138303220165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1023659916165622"><a name="p1023659916165622"></a><a name="p1023659916165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p872768414165622"><a name="p872768414165622"></a><a name="p872768414165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1995268045165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p859929408165622"><a name="p859929408165622"></a><a name="p859929408165622"></a>EBADF </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p643199459165622"><a name="p643199459165622"></a><a name="p643199459165622"></a><strong id="b519410962165622"><a name="b519410962165622"></a><a name="b519410962165622"></a>fp</strong> points to an invalid stream. </p>
</td>
</tr>
</tbody>
</table>

## ftrylockfile\(\)<a name="gab486b89691678e4873ec8b1b15c2678a"></a>

```
int ftrylockfile ([FILE](IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1) * filehandle)
```

 **Description:**

Locks a specified file. 

This function facilitates I/O operations in multiple threads. If the file has been locked by another thread, this function waits until the file object is no longer locked by any thread and then locks it. 

**Parameters:**

<a name="table744731074165622"></a>
<table><thead align="left"><tr id="row708554009165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p102164520165622"><a name="p102164520165622"></a><a name="p102164520165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1633148600165622"><a name="p1633148600165622"></a><a name="p1633148600165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row115621300165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">filehandle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the file object. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the locking is successful; returns a non-zero value otherwise. 

## funlockfile\(\)<a name="ga4f016c54ff86ca62454417bb7b32ab11"></a>

```
void funlockfile ([FILE](IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1) * filehandle)
```

 **Description:**

Unlocks a specified file. 

This function is used to reduce the lock count. 

**Parameters:**

<a name="table1010140664165622"></a>
<table><thead align="left"><tr id="row673548146165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1079214723165622"><a name="p1079214723165622"></a><a name="p1079214723165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p169742449165622"><a name="p169742449165622"></a><a name="p169742449165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row37824980165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">filehandle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the file whose lock count is to be reduced. </td>
</tr>
</tbody>
</table>

## fwrite\(\)<a name="gaf86a4505e5de39a100f7ea828377b585"></a>

```
size_t fwrite (const void *__restrict ptr, size_t size, size_t nmemb, [FILE](IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1) *__restrict stream )
```

 **Description:**

Writes data to a specified stream. 

**Parameters:**

<a name="table269391338165622"></a>
<table><thead align="left"><tr id="row1561375854165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1905874069165622"><a name="p1905874069165622"></a><a name="p1905874069165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1961353749165622"><a name="p1961353749165622"></a><a name="p1961353749165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1279315876165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">ptr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the data to write. </td>
</tr>
<tr id="row47986092165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">size</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the size of each element to write, in bytes. </td>
</tr>
<tr id="row2142862627165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">nmemb</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the number of elements to write. </td>
</tr>
<tr id="row1472700560165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">stream</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the file object that identifies a stream to which data is to write. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if  **size**  or  **nmemb**  is  **0**; returns the number of elements successfully written otherwise. If this number is not  **nmemb**, this function sets  **errno**  to a value in the following table if the number is not  **nmemb**. 

<a name="table916055627165622"></a>
<table><thead align="left"><tr id="row1725956630165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1980305686165622"><a name="p1980305686165622"></a><a name="p1980305686165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1603904574165622"><a name="p1603904574165622"></a><a name="p1603904574165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row895970885165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1925517903165622"><a name="p1925517903165622"></a><a name="p1925517903165622"></a>EBADF </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p6832439165622"><a name="p6832439165622"></a><a name="p6832439165622"></a><strong id="b1516600351165622"><a name="b1516600351165622"></a><a name="b1516600351165622"></a>stream</strong> points to an invalid stream. </p>
</td>
</tr>
</tbody>
</table>

## getc\(\)<a name="gad5a0ea2c21a23a380b7c30fe35fa9456"></a>

```
int getc ([FILE](IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1) * stream)
```

 **Description:**

Reads a character from a specified file stream. 

**Parameters:**

<a name="table1539510790165622"></a>
<table><thead align="left"><tr id="row75736170165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p532613521165622"><a name="p532613521165622"></a><a name="p532613521165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2044852343165622"><a name="p2044852343165622"></a><a name="p2044852343165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1302161859165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">stream</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the file object that identifies a stream. </td>
</tr>
</tbody>
</table>

**Attention:**

The difference between this function and  **fgetc**  is that this function can be implemented as a macro. 

**Returns:**

Returns the character read as an int value if the operation is successful; returns  **EOF**  if the end-of-file is reached or a reading error occurs. 

## getc\_unlocked\(\)<a name="ga169f9b7e933ba56156885e30f7263b28"></a>

```
int getc_unlocked ([FILE](IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1) * stream)
```

 **Description:**

Obtains a character from a specified file stream without locking the file stream or checking whether it is locked. 

**Parameters:**

<a name="table412100298165622"></a>
<table><thead align="left"><tr id="row1379244873165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1673013881165622"><a name="p1673013881165622"></a><a name="p1673013881165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p946224196165622"><a name="p946224196165622"></a><a name="p946224196165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1832077259165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">stream</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the file object that identifies a stream. </td>
</tr>
</tbody>
</table>

**Attention:**

Use this function with caution in multi-thread scenarios. 

**Returns:**

Returns the obtained character. 

## getchar\(\)<a name="ga3e29caa20f7cffe18f410f01278905a8"></a>

```
int getchar (void )
```

 **Description:**

Obtains the next character from the standard input \(stdin\). 

This function waits for user input and does not return until any input is available. 

**Returns:**

Returns the character read as an int value if the operation is successful; returns  **EOF**  if the end-of-file is reached or a reading error occurs. 

## getchar\_unlocked\(\)<a name="gafef7e39f2376c63728163cd5ccfbe99e"></a>

```
int getchar_unlocked (void )
```

 **Description:**

Obtains the next character from stdin. 

This function waits for user input and does not return until any input is available. 

**Attention:**

Use this function with caution in multi-thread scenarios. 

**Returns:**

Returns the character forcibly converted to an int value if the operation is successful; returns  **EOF**  if the end-of-file is reached or a reading error occurs. 

## getdelim\(\)<a name="gab87a24b4c09e8fc3712a6d6090bfd371"></a>

```
ssize_t getdelim (char ** lineptr, size_t * n, int delim, [FILE](IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1) * stream )
```

 **Description:**

Reads an entire line from a specified file stream. 

**Parameters:**

<a name="table1094246380165622"></a>
<table><thead align="left"><tr id="row1967277591165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p105072357165622"><a name="p105072357165622"></a><a name="p105072357165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1658535170165622"><a name="p1658535170165622"></a><a name="p1658535170165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row892642458165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">lineptr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double pointer to the buffer for storing the characters in the line. </td>
</tr>
<tr id="row2014460809165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">n</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the size of the buffer. If the system needs to dynamically allocate memory, set this parameter to <strong id="b1156440016165622"><a name="b1156440016165622"></a><a name="b1156440016165622"></a>0</strong>. </td>
</tr>
<tr id="row803837781165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">delim</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the line delimiter. </td>
</tr>
<tr id="row500420572165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">stream</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the file object that identifies a stream. </td>
</tr>
</tbody>
</table>

**Attention:**

If the system dynamically allocates memory, the memory needs to be released after being used. 

**Returns:**

Returns the number of bytes read if the operation is successful; returns  **-1**  otherwise. 

## getline\(\)<a name="gaaf07c1bbc2aa081a54bdd66f0e152312"></a>

```
ssize_t getline (char ** lineptr, size_t * n, [FILE](IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1) * stream )
```

 **Description:**

Reads an entire line from a specified file stream. 

**Parameters:**

<a name="table1754550205165622"></a>
<table><thead align="left"><tr id="row1764387596165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1299762613165622"><a name="p1299762613165622"></a><a name="p1299762613165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p778731433165622"><a name="p778731433165622"></a><a name="p778731433165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1556720481165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">lineptr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double pointer to the buffer for storing the characters in the line. </td>
</tr>
<tr id="row366507919165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">n</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the size of the buffer. If the system needs to dynamically allocate memory, set this parameter to <strong id="b827334524165622"><a name="b827334524165622"></a><a name="b827334524165622"></a>0</strong>. </td>
</tr>
<tr id="row2060255290165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">stream</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the file object that identifies a stream. </td>
</tr>
</tbody>
</table>

**Attention:**

If the system dynamically allocates memory, the memory needs to be released after being used. 

**Returns:**

Returns the number of bytes read if the operation is successful; returns  **-1**  otherwise. 

## gets\(\)<a name="gaab85b30d68ce9d9e0475e0f51bf610b1"></a>

```
char* gets (char * s)
```

 **Description:**

Reads a line of characters from the stdin and stores it in the buffer. 

**Parameters:**

<a name="table2143770594165622"></a>
<table><thead align="left"><tr id="row1083539997165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2079945900165622"><a name="p2079945900165622"></a><a name="p2079945900165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p658520029165622"><a name="p658520029165622"></a><a name="p658520029165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row887745361165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">s</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the memory buffer for storing the obtained string. </td>
</tr>
</tbody>
</table>

**Attention:**

The  **[gets\(\)](IO.md#gaab85b30d68ce9d9e0475e0f51bf610b1)**  function cannot predict the size of the line to be read, which may cause buffer overflow. You are recommended not to use this function. POSIX.1-2008 and ISO C11 have marked this function as obsolete. 

**Returns:**

Returns the value of  **s**  if the operation is successful; returns  **NULL**  otherwise. 

## getw\(\)<a name="ga6d475ead5d1f35e3f14423a99ef3a992"></a>

```
int getw ([FILE](IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1) * stream)
```

 **Description:**

Reads a word \(an int value\) from a specified file stream. 

**Parameters:**

<a name="table119754633165622"></a>
<table><thead align="left"><tr id="row1657879237165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1493363661165622"><a name="p1493363661165622"></a><a name="p1493363661165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1096029882165622"><a name="p1096029882165622"></a><a name="p1096029882165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row76660998165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">stream</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the file object that identifies a stream. </td>
</tr>
</tbody>
</table>

**Attention:**

This function is provided for compatibility with System V Release 4 \(SVR4\). You are advised to use  [fread](IO.md#ga091b3f41bdd6984d63ea48d87a62bfd2)  instead. The value returned upon an error is also a valid data value. 

**Returns:**

Returns the integer read if the operation is successful; returns  **EOP**  otherwise. 

## iconv\(\)<a name="gab7c1300a663def659ce6d4a01076c39d"></a>

```
size_t iconv ([iconv_t](IO.md#ga72517f6ffadddaafa9d51dee9b535c9f) cd, char **restrict in, size_t *restrict inb, char **restrict out, size_t *restrict outb )
```

 **Description:**

Converts a character set. 

**Parameters:**

<a name="table474048996165622"></a>
<table><thead align="left"><tr id="row450787615165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p270411440165622"><a name="p270411440165622"></a><a name="p270411440165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p894929618165622"><a name="p894929618165622"></a><a name="p894929618165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1099070301165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">cd</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the conversion descriptor obtained via <a href="IO.md#ga934548ab8aaae237ac5cce0ed0b3edec">iconv_open</a>. </td>
</tr>
<tr id="row1955617224165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">in</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double pointer to the buffer for storing the input character. </td>
</tr>
<tr id="row506359785165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">inb</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the length of the character input buffer. </td>
</tr>
<tr id="row1757629357165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">out</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double pointer to the buffer for storing the output character. </td>
</tr>
<tr id="row1120287567165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">outb</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to length of the character output buffer. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the number of irreversibly converted characters if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table563903864165622"></a>
<table><thead align="left"><tr id="row111911618165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1857725072165622"><a name="p1857725072165622"></a><a name="p1857725072165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p180414071165622"><a name="p180414071165622"></a><a name="p180414071165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1512061748165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1296932284165622"><a name="p1296932284165622"></a><a name="p1296932284165622"></a>EILSEQ </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p719359922165622"><a name="p719359922165622"></a><a name="p719359922165622"></a>An invalid multi-byte sequence is encountered in the input. </p>
</td>
</tr>
<tr id="row1978734473165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1845454620165622"><a name="p1845454620165622"></a><a name="p1845454620165622"></a>E2BIG </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p898670390165622"><a name="p898670390165622"></a><a name="p898670390165622"></a>The output buffer space is insufficient. </p>
</td>
</tr>
<tr id="row2069005121165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1873693207165622"><a name="p1873693207165622"></a><a name="p1873693207165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1133211301165622"><a name="p1133211301165622"></a><a name="p1133211301165622"></a>An incomplete multi-byte sequence is encountered in the input. </p>
</td>
</tr>
</tbody>
</table>

## iconv\_close\(\)<a name="ga062da5f802d9e274a8702f11921e691b"></a>

```
int iconv_close ([iconv_t](IO.md#ga72517f6ffadddaafa9d51dee9b535c9f) cd)
```

 **Description:**

Closes a character set conversion descriptor. 

**Parameters:**

<a name="table1536257029165622"></a>
<table><thead align="left"><tr id="row1027767705165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1055504547165622"><a name="p1055504547165622"></a><a name="p1055504547165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2134465808165622"><a name="p2134465808165622"></a><a name="p2134465808165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row583155601165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">cd</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the conversion descriptor to close. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**. 

## iconv\_open\(\)<a name="ga934548ab8aaae237ac5cce0ed0b3edec"></a>

```
[iconv_t](IO.md#ga72517f6ffadddaafa9d51dee9b535c9f) iconv_open (const char * to, const char * from )
```

 **Description:**

Obtain a character set conversion descriptor. 

**Parameters:**

<a name="table117074274165622"></a>
<table><thead align="left"><tr id="row555488059165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p499414937165622"><a name="p499414937165622"></a><a name="p499414937165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p42976630165622"><a name="p42976630165622"></a><a name="p42976630165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1596533124165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">to</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the source character set for conversion. </td>
</tr>
<tr id="row1356232903165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">from</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the target character set for conversion. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the character set conversion descriptor if the operation is successful; returns  **-1**  otherwise. 

## open\_memstream\(\)<a name="gac7250554d80d31f4d8ad316c4c3c3c85"></a>

```
[FILE](IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1)* open_memstream (char ** ptr, size_t * size )
```

 **Description:**

Opens a stream for writing to a specified buffer. 

The buffer is dynamically allocated and grown. After the stream is closed, call  [free\(\)](MEM.md#gafbedc913aa4651b3c3b4b3aecd9b4711)  to release the buffer. When  [fclose\(\)](IO.md#gac41a0ad4b31be2ad59d8222a0de30bda)  or  [fflush\(\)](IO.md#gae4459e830d3e2abcf428337a661d9456)  is called to close or flush the stream, the pointers to the allocated buffer address and buffer size are updated to  **ptr**  and  **size**, respectively. @attentions This function is defined in POSIX.1-2008. It is not defined in POSIX.1-2001 and is not widely used in other systems. 

**Parameters:**

<a name="table1712570666165622"></a>
<table><thead align="left"><tr id="row1791570233165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1054700915165622"><a name="p1054700915165622"></a><a name="p1054700915165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1823568686165622"><a name="p1823568686165622"></a><a name="p1823568686165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row126528287165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">ptr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the buffer address. </td>
</tr>
<tr id="row302787431165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">size</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the buffer size. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the pointer to the stream if the operation is successful; returns  **NULL**  and sets  **errno**  to indicate an error otherwise. 

## perror\(\)<a name="ga80b37b56a5a42139dccaef56da4bf82a"></a>

```
void perror (const char * msg)
```

 **Description:**

Prints the last error occurred during a call to a system or library function to the standard error output stream \(stderr\). 

**Parameters:**

<a name="table1463532218165622"></a>
<table><thead align="left"><tr id="row640971953165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1016049811165622"><a name="p1016049811165622"></a><a name="p1016049811165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1803712478165622"><a name="p1803712478165622"></a><a name="p1803712478165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row205064767165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">msg</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the prompt message printed to stderr before the error message itself. </td>
</tr>
</tbody>
</table>

**Attention:**

To make the output message more useful,  **msg**  should convey obvious information describing what happened. When a system call fails, it usually returns  **-1**  and sets  **errno**  to a value that describes what went wrong. The error codes can be found in  **errno.h**. 

## poll\(\)<a name="gab7fc0f6be5f13c81de180c1288ba3b6f"></a>

```
int poll (struct [pollfd](pollfd.md) fds[], [nfds_t](IO.md#ga0af7a8bdafcd5532e620a11f0d373d52) nfds, int timeout )
```

 **Description:**

Defines the I/O multiplexing system. 

This function is used to mount the pointer to the  **pollfd**  file to the waiting queue and then monitor the file. 

**Parameters:**

<a name="table561199508165622"></a>
<table><thead align="left"><tr id="row1034004365165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p325484592165622"><a name="p325484592165622"></a><a name="p325484592165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p69123425165622"><a name="p69123425165622"></a><a name="p69123425165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2037956935165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fds[]</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the <strong id="b1982331661165622"><a name="b1982331661165622"></a><a name="b1982331661165622"></a>pollfd</strong> array used to store the socket descriptor to be checked. </td>
</tr>
<tr id="row1918824869165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">nfds</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the <strong id="b779124622165622"><a name="b779124622165622"></a><a name="b779124622165622"></a>nfds_t</strong> parameter used to mark the total number of structure elements in <strong id="b2136535200165622"><a name="b2136535200165622"></a><a name="b2136535200165622"></a>fds</strong>. </td>
</tr>
<tr id="row1289554959165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">timeout</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the blocking time, in milliseconds. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns a value greater than 0 if the total number of socket descriptors in  **fds**  is ready for read or write, or on which errors occur; returns  **0**  otherwise, in which case  **poll**  timed out. Returns  **-1**  and sets  **errno**  to a value if this function fails to be called. 

## preadv\(\)<a name="ga94adc8dd94a6bdaaa9cf4d9f388418b3"></a>

```
ssize_t preadv (int fd, const struct iovec * iov, int iovcnt, off_t offset )
```

 **Description:**

Reads the data in a file whose  **fd**  offset is  **offset**  to the multi-group buffer space pointed to by  **iov**. 

**Parameters:**

<a name="table1664430512165622"></a>
<table><thead align="left"><tr id="row214923726165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p313704209165622"><a name="p313704209165622"></a><a name="p313704209165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1240034475165622"><a name="p1240034475165622"></a><a name="p1240034475165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row162811409165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fd</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the file descriptor. </td>
</tr>
<tr id="row417192251165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">iov</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the multi-group buffer. </td>
</tr>
<tr id="row1889281843165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">iovcnt</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the number of buffers. For details, see <a href="UTILS.md#ga25080e819a36fcf9aede01a6e7298ea4">IOV_MAX</a>. </td>
</tr>
<tr id="row314364825165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">offset</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the offset of the file descriptor to read. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the number of bytes read if the operation is successful; returns  **-1**  and sets  **errno**  to a value if the operation fails. If  **errno**  is set to  **EINVAL**, the sum of the  **iov\_len**  values overflows an  **ssize\_t**  value, or the vector count  **iovcnt**  is less than 0 or greater than the permitted maximum. 

## printf\(\)<a name="ga98631211a4a8aee62f572375d5b637be"></a>

```
int printf (const char * format,  ... )
```

 **Description:**

Formats arguments based on  **format**  and prints formatted data to the stdout. 

**Parameters:**

<a name="table1309096337165622"></a>
<table><thead align="left"><tr id="row2141047193165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1482917954165622"><a name="p1482917954165622"></a><a name="p1482917954165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p587945534165622"><a name="p587945534165622"></a><a name="p587945534165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1885898942165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">format</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the format string. </td>
</tr>
<tr id="row1366536605165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">...</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the list of arguments corresponding to the format specifiers. </td>
</tr>
</tbody>
</table>

**Attention:**

**format**  must correspond to the arguments specified in  **...**. Otherwise, an error is returned. 

**Returns:**

Returns the total number of characters \(excluding the terminating null character  **'\\0'**\) if the operation is successful; returns a negative value otherwise. 

## putc\(\)<a name="ga38f980218f04ebdddcdcd1b77e1cf6b1"></a>

```
int putc (int c, [FILE](IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1) * stream )
```

 **Description:**

Writes a character to a specified file stream. 

**Parameters:**

<a name="table1993955349165622"></a>
<table><thead align="left"><tr id="row293414609165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1931017529165622"><a name="p1931017529165622"></a><a name="p1931017529165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p326572268165622"><a name="p326572268165622"></a><a name="p326572268165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1082356463165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">c</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the int promotion of the character to write. </td>
</tr>
<tr id="row1426117550165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">stream</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the file stream. </td>
</tr>
</tbody>
</table>

**Attention:**

**Returns:**

Returns the ASCII code of the character written if the operation is successful; returns  **EOF**  otherwise. 

## putc\_unlocked\(\)<a name="ga340b21ecb337abb08905095e673672f6"></a>

```
int putc_unlocked (int c, [FILE](IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1) * stream )
```

 **Description:**

Writes a character to a specified file stream with the thread remains unlocked. 

**Parameters:**

<a name="table2146575308165622"></a>
<table><thead align="left"><tr id="row915188635165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p365233292165622"><a name="p365233292165622"></a><a name="p365233292165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1129772187165622"><a name="p1129772187165622"></a><a name="p1129772187165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row811921134165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">c</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the int promotion of the character to write. </td>
</tr>
<tr id="row1700900560165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">stream</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the file object that identifies a stream. </td>
</tr>
</tbody>
</table>

**Attention:**

This function cannot be used in a multi-thread process because it does not use locking during the call. 

**Returns:**

Returns the ASCII code of the character written if the operation is successful; returns  **EOF**  otherwise. 

## putchar\(\)<a name="gaf4de2514b7778805db3815e8dd6cf09a"></a>

```
int putchar (int c)
```

 **Description:**

Writes a character into the standard output \(stdout\). 

**Parameters:**

<a name="table1719077432165622"></a>
<table><thead align="left"><tr id="row1677124362165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p573918256165622"><a name="p573918256165622"></a><a name="p573918256165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p320196077165622"><a name="p320196077165622"></a><a name="p320196077165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row499431827165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">c</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the int promotion of the character to write. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the ASCII code of the character written if the operation is successful; returns  **EOF**  otherwise. 

## putchar\_unlocked\(\)<a name="ga07ff061a8fed45cdedbecdd899b5fdb1"></a>

```
int putchar_unlocked (int c)
```

 **Description:**

Writes a character to the stdout with the thread remains unlocked. 

**Parameters:**

<a name="table509215183165622"></a>
<table><thead align="left"><tr id="row203354680165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p173105150165622"><a name="p173105150165622"></a><a name="p173105150165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p59531445165622"><a name="p59531445165622"></a><a name="p59531445165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1563751923165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">c</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the int promotion of the character to write. </td>
</tr>
</tbody>
</table>

**Attention:**

This function cannot be used in a multi-thread process because it does not use locking during the call. 

**Returns:**

Returns the ASCII code of the character written if the operation is successful; returns  **EOF**  otherwise. 

## puts\(\)<a name="gad41876f99f190c7488e64ef39c50a23f"></a>

```
int puts (const char * s)
```

 **Description:**

Writes a character string and appends a new-line character to the stdout. 

**Parameters:**

<a name="table1230853475165622"></a>
<table><thead align="left"><tr id="row1209706857165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1181665843165622"><a name="p1181665843165622"></a><a name="p1181665843165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p521093657165622"><a name="p521093657165622"></a><a name="p521093657165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1461268292165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">s</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the start address of the output buffer. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns a non-negative value if the operation is successful; returns  **EOF**  otherwise. 

## putw\(\)<a name="gae3a2f96dac9fa87b964b69ff6d5cce46"></a>

```
int putw (int w, [FILE](IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1) * stream )
```

 **Description:**

Writes a word \(an int value\) to a specified file stream. 

**Parameters:**

<a name="table604670154165622"></a>
<table><thead align="left"><tr id="row1059064423165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1527725382165622"><a name="p1527725382165622"></a><a name="p1527725382165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1172572772165622"><a name="p1172572772165622"></a><a name="p1172572772165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row977566456165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">w</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the word to write. </td>
</tr>
<tr id="row1868487262165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">stream</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the file object that identifies a stream. </td>
</tr>
</tbody>
</table>

**Attention:**

This function is provided for compatibility with SVR4. You are advised to use  [fwrite](IO.md#gaf86a4505e5de39a100f7ea828377b585)  instead. 

**Returns:**

Returns  **0**  if the operation is successful; returns  **EOP**  otherwise. 

## pwritev\(\)<a name="ga3de6f9331d6bb930e748bb61860edbd6"></a>

```
ssize_t pwritev (int fd, const struct iovec * iov, int iovcnt, off_t offset )
```

 **Description:**

Writes the data of a multi-group buffer space pointed to by  **iov**  to the offset of  **fd**. 

**Parameters:**

<a name="table210719467165622"></a>
<table><thead align="left"><tr id="row2058626991165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1174891063165622"><a name="p1174891063165622"></a><a name="p1174891063165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1829674980165622"><a name="p1829674980165622"></a><a name="p1829674980165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1575781390165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fd</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the file descriptor. </td>
</tr>
<tr id="row1126463833165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">iov</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the multi-group buffer. </td>
</tr>
<tr id="row810240891165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">iovcnt</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the number of buffers. For details, see <a href="UTILS.md#ga25080e819a36fcf9aede01a6e7298ea4">IOV_MAX</a>. </td>
</tr>
<tr id="row141932737165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">offset</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the offset of the file descriptor to write. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the number of bytes written if the operation is successful; returns  **-1**  and sets  **errno**  to a value if the operation fails. If  **errno**  is set to  **EINVAL**, the sum of the  **iov\_len**  values overflows an  **ssize\_t**  value, or the vector count  **iovcnt**  is less than 0 or greater than the permitted maximum. 

## readv\(\)<a name="gaa1952d693ed3c43292566e643ceb9858"></a>

```
ssize_t readv (int fd, const struct iovec * iov, int iovcnt )
```

 **Description:**

Reads the data of  **fd**  to  **iov**. 

**Parameters:**

<a name="table1105456980165622"></a>
<table><thead align="left"><tr id="row817647373165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p152346431165622"><a name="p152346431165622"></a><a name="p152346431165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p726911193165622"><a name="p726911193165622"></a><a name="p726911193165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1664173495165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fd</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the file descriptor. </td>
</tr>
<tr id="row100025976165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">iov</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the multi-group buffer. </td>
</tr>
<tr id="row253629753165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">iovcnt</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the number of buffers. For details, see <a href="UTILS.md#ga25080e819a36fcf9aede01a6e7298ea4">IOV_MAX</a>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the number of bytes read if the operation is successful; returns  **-1**  and sets  **errno**  to a value if the operation fails. If  **errno**  is set to  **EINVAL**, the sum of the  **iov\_len**  values overflows an  **ssize\_t**  value, or the vector count  **iovcnt**  is less than 0 or greater than the permitted maximum. 

## remove\(\)<a name="ga02b13b56a188401119ea4da43c184913"></a>

```
int remove (const char * pathname)
```

 **Description:**

Deletes a specified file or directory from the file system. 

**Parameters:**

<a name="table1328039045165622"></a>
<table><thead align="left"><tr id="row109751815165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1971010153165622"><a name="p1971010153165622"></a><a name="p1971010153165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1268866091165622"><a name="p1268866091165622"></a><a name="p1268866091165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2146939144165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">pathname</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the file or directory to delete. </td>
</tr>
</tbody>
</table>

**Attention:**

This function can NOT be used in the PROC file system. 

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table1781759456165622"></a>
<table><thead align="left"><tr id="row1846092982165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p648821923165622"><a name="p648821923165622"></a><a name="p648821923165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p275273487165622"><a name="p275273487165622"></a><a name="p275273487165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row759887725165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p428650632165622"><a name="p428650632165622"></a><a name="p428650632165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1969802848165622"><a name="p1969802848165622"></a><a name="p1969802848165622"></a><strong id="b161233077165622"><a name="b161233077165622"></a><a name="b161233077165622"></a>pathname</strong> is a null pointer or an empty string. </p>
</td>
</tr>
<tr id="row467216847165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p63009746165622"><a name="p63009746165622"></a><a name="p63009746165622"></a>ENAMETOOLONG </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1113136104165622"><a name="p1113136104165622"></a><a name="p1113136104165622"></a>The length of <strong id="b139904239165622"><a name="b139904239165622"></a><a name="b139904239165622"></a>pathname</strong> is greater than <a href="UTILS.md#gac64541bdd81c961304b9babef1402640">NAME_MAX</a>. </p>
</td>
</tr>
<tr id="row1360191887165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p292844790165622"><a name="p292844790165622"></a><a name="p292844790165622"></a>ENOMEM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1846259127165622"><a name="p1846259127165622"></a><a name="p1846259127165622"></a>Insufficient memory. </p>
</td>
</tr>
<tr id="row1525095088165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1834219371165622"><a name="p1834219371165622"></a><a name="p1834219371165622"></a>ENOENT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1825480748165622"><a name="p1825480748165622"></a><a name="p1825480748165622"></a>The file or directory pointed to by <strong id="b730048148165622"><a name="b730048148165622"></a><a name="b730048148165622"></a>pathname</strong> does not exist. </p>
</td>
</tr>
<tr id="row1504582729165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p621761682165622"><a name="p621761682165622"></a><a name="p621761682165622"></a>EPERM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2100894807165622"><a name="p2100894807165622"></a><a name="p2100894807165622"></a>The path is a mount point or is neither a directory nor a file. </p>
</td>
</tr>
<tr id="row1444244254165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p373408324165622"><a name="p373408324165622"></a><a name="p373408324165622"></a>ENOTEMPTY </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2083464510165622"><a name="p2083464510165622"></a><a name="p2083464510165622"></a>When <strong id="b976851043165622"><a name="b976851043165622"></a><a name="b976851043165622"></a>pathname</strong> points to a directory, the directory is not empty. </p>
</td>
</tr>
<tr id="row1522242135165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p327128985165622"><a name="p327128985165622"></a><a name="p327128985165622"></a>ENXIO </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p544845809165622"><a name="p544845809165622"></a><a name="p544845809165622"></a>No such device or address. </p>
</td>
</tr>
<tr id="row130581612165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1556287437165622"><a name="p1556287437165622"></a><a name="p1556287437165622"></a>EACCES </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p167291153165622"><a name="p167291153165622"></a><a name="p167291153165622"></a>The search permission on the path prefix component is denied, or the write permission of the directory in the path is denied. </p>
</td>
</tr>
</tbody>
</table>

## rename\(\)<a name="ga4d4709508ed7604103d77c3fdc5ea4a2"></a>

```
int rename (const char * oldpath, const char * newpath )
```

 **Description:**

Renames a specified file. 

**Parameters:**

<a name="table1786708227165622"></a>
<table><thead align="left"><tr id="row1575542672165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1793425432165622"><a name="p1793425432165622"></a><a name="p1793425432165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p369201659165622"><a name="p369201659165622"></a><a name="p369201659165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row838663777165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">oldpath</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the old path name of the file to rename. </td>
</tr>
<tr id="row452504079165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">newpath</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the new path name of the file. </td>
</tr>
</tbody>
</table>

**Attention:**

This function can NOT be used in the PROC file system. 

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table216404946165622"></a>
<table><thead align="left"><tr id="row530462589165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2052565331165622"><a name="p2052565331165622"></a><a name="p2052565331165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1476069697165622"><a name="p1476069697165622"></a><a name="p1476069697165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row559388285165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p925870025165622"><a name="p925870025165622"></a><a name="p925870025165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p664868664165622"><a name="p664868664165622"></a><a name="p664868664165622"></a>Invalid input parameter. </p>
</td>
</tr>
<tr id="row121531241165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p325617076165622"><a name="p325617076165622"></a><a name="p325617076165622"></a>ENOENT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p455150427165622"><a name="p455150427165622"></a><a name="p455150427165622"></a>The file or directory does not exist. </p>
</td>
</tr>
<tr id="row1553499641165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p565153114165622"><a name="p565153114165622"></a><a name="p565153114165622"></a>EXDEV </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1710335617165622"><a name="p1710335617165622"></a><a name="p1710335617165622"></a><strong id="b954802744165622"><a name="b954802744165622"></a><a name="b954802744165622"></a>oldpath</strong> and <strong id="b934216296165622"><a name="b934216296165622"></a><a name="b934216296165622"></a>newpath</strong> are not on the same file system. </p>
</td>
</tr>
<tr id="row1454335041165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1870586356165622"><a name="p1870586356165622"></a><a name="p1870586356165622"></a>EBUSY </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p6727828165622"><a name="p6727828165622"></a><a name="p6727828165622"></a>The device or resource is in use by the system or another process. </p>
</td>
</tr>
<tr id="row1535126018165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p122369737165622"><a name="p122369737165622"></a><a name="p122369737165622"></a>EEXIST </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1807064928165622"><a name="p1807064928165622"></a><a name="p1807064928165622"></a>The file path pointed to by <strong id="b1524584862165622"><a name="b1524584862165622"></a><a name="b1524584862165622"></a>newpath</strong> already exists. </p>
</td>
</tr>
<tr id="row2050275708165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2111129653165622"><a name="p2111129653165622"></a><a name="p2111129653165622"></a>ENXIO </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1826047658165622"><a name="p1826047658165622"></a><a name="p1826047658165622"></a>The device or address does not exist. </p>
</td>
</tr>
</tbody>
</table>

## rewind\(\)<a name="gaa0cd401f198d33d9d01a9e8aa4026819"></a>

```
void rewind ([FILE](IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1) * stream)
```

 **Description:**

Sets the position indicator of a specified stream to the beginning of the file. 

**Parameters:**

<a name="table2124548636165622"></a>
<table><thead align="left"><tr id="row1624522072165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p619215157165622"><a name="p619215157165622"></a><a name="p619215157165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p5853841165622"><a name="p5853841165622"></a><a name="p5853841165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1480472508165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">stream</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the file object that identifies a stream. </td>
</tr>
</tbody>
</table>

## scanf\(\)<a name="ga5c48433db9c04031772d5b36e6c4411d"></a>

```
int scanf (const char * format,  ... )
```

 **Description:**

Reads formatted data from the stdin and stores the data to the additional arguments based on  **format**. 

**Parameters:**

<a name="table468664020165622"></a>
<table><thead align="left"><tr id="row1454375292165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p76134225165622"><a name="p76134225165622"></a><a name="p76134225165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1781212537165622"><a name="p1781212537165622"></a><a name="p1781212537165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row530069243165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">format</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the format string. </td>
</tr>
<tr id="row1071611318165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">...</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the list of arguments corresponding to the format specifiers. </td>
</tr>
</tbody>
</table>

**Attention:**

The type of each argument must match a format specifier in  **format**. 

**Returns:**

Returns the number of variables that are successfully read. If the matching fails quickly, the return value may be less than the number of members in the argument list or even zero. If no complete conversion format is available or the input format fails to be matched,  **EOF**  is returned. The return value is also  **EOF**  if a reading error occurs. If the number of arguments exceeds the number of the format specifiers, the excess arguments are ignored. 

## select\(\)<a name="gaf916439863bed6ba92594e390c227c7e"></a>

```
int select (int nfds, [fd_set](fd_set.md) *__restrict readfds, [fd_set](fd_set.md) *__restrict writefds, [fd_set](fd_set.md) *__restrict exceptfds, struct [timeval](timeval.md) *__restrict timeout )
```

 **Description:**

Monitors the I/O events of multiple file descriptors. 

**Parameters:**

<a name="table1520645875165622"></a>
<table><thead align="left"><tr id="row974316657165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p652194125165622"><a name="p652194125165622"></a><a name="p652194125165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1600747580165622"><a name="p1600747580165622"></a><a name="p1600747580165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1260770660165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">nfds</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the maximum value of the file descriptor of the <strong id="b1713563308165622"><a name="b1713563308165622"></a><a name="b1713563308165622"></a>int</strong> type. </td>
</tr>
<tr id="row1165249614165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">readfds</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the descriptor set of the readable event to observe, which is the <strong id="b1308006491165622"><a name="b1308006491165622"></a><a name="b1308006491165622"></a><a href="fd_set.md">fd_set</a> *</strong> type. </td>
</tr>
<tr id="row542241140165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">writefds</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the descriptor set of the writable event to observe, which is the <strong id="b1448525107165622"><a name="b1448525107165622"></a><a name="b1448525107165622"></a><a href="fd_set.md">fd_set</a> *</strong> type. </td>
</tr>
<tr id="row809878003165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">exceptfds</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the descriptor set of exception event to observe, which is the <strong id="b209475685165622"><a name="b209475685165622"></a><a name="b209475685165622"></a><a href="fd_set.md">fd_set</a> *</strong> type. </td>
</tr>
<tr id="row741597986165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">timeout</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the timeout interval, which is the <strong id="b1649706304165622"><a name="b1649706304165622"></a><a name="b1649706304165622"></a>struct timeval *</strong> type. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the total number of file descriptors of the observed events \(that is, the sum of all file descriptors in  **readfds**,  **writefds**, and  **exceptfds**\) if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table637660648165622"></a>
<table><thead align="left"><tr id="row1871830096165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1845369778165622"><a name="p1845369778165622"></a><a name="p1845369778165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p148967054165622"><a name="p148967054165622"></a><a name="p148967054165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1694545886165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p220152168165622"><a name="p220152168165622"></a><a name="p220152168165622"></a>EBADF </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p677269365165622"><a name="p677269365165622"></a><a name="p677269365165622"></a>An invalid file descriptor is given in one of the sets. </p>
</td>
</tr>
<tr id="row684622714165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p314603127165622"><a name="p314603127165622"></a><a name="p314603127165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1323054776165622"><a name="p1323054776165622"></a><a name="p1323054776165622"></a><strong id="b1597932250165622"><a name="b1597932250165622"></a><a name="b1597932250165622"></a>nfds</strong> is less than 0. </p>
</td>
</tr>
<tr id="row1618474355165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1559283734165622"><a name="p1559283734165622"></a><a name="p1559283734165622"></a>ENOMEM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p672939336165622"><a name="p672939336165622"></a><a name="p672939336165622"></a>Failed to apply for memory. </p>
</td>
</tr>
</tbody>
</table>

## setbuf\(\)<a name="ga36d24924e1acc69f9c3ce49a832615fe"></a>

```
void setbuf ([FILE](IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1) * stream, char * buf )
```

 **Description:**

Sets a buffer to be used by a specified stream. 

**Parameters:**

<a name="table1897902479165622"></a>
<table><thead align="left"><tr id="row463990086165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p761595138165622"><a name="p761595138165622"></a><a name="p761595138165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p197496833165622"><a name="p197496833165622"></a><a name="p197496833165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1659167654165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">stream</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the file object that identifies a stream. </td>
</tr>
<tr id="row579740171165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">buf</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the start address of the buffer. </td>
</tr>
</tbody>
</table>

**Attention:**

When the input parameter  **buf**  is not null, the buffer mode is  **\_IOFBF**. The default buffer size is determined by the value of  **BUFSIZ**  defined in this file. When  **buf**  is null, the buffer mode is  **\_IONBF**  \(unbuffered\). 

## setbuffer\(\)<a name="ga53a57437279b4ed57b7f116dfc9cbbcc"></a>

```
void setbuffer ([FILE](IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1) * f, char * buf, size_t size )
```

 **Description:**

Sets the buffer for a specified file stream. 

**Parameters:**

<a name="table1634954510165622"></a>
<table><thead align="left"><tr id="row1966971030165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p810865296165622"><a name="p810865296165622"></a><a name="p810865296165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p73787236165622"><a name="p73787236165622"></a><a name="p73787236165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row231091843165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">f</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the file object that identifies a stream to set. </td>
</tr>
<tr id="row516089934165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">buf</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the buffer to set. </td>
</tr>
<tr id="row2027779760165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">size</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the buffer size. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  otherwise. 

## setlinebuf\(\)<a name="ga2e13e101d5a57cfccf1bab51f8768a5d"></a>

```
void setlinebuf ([FILE](IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1) * f)
```

 **Description:**

Sets the linear buffer for a specified file stream. 

**Parameters:**

<a name="table605120078165622"></a>
<table><thead align="left"><tr id="row1388211906165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p462191754165622"><a name="p462191754165622"></a><a name="p462191754165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1429678415165622"><a name="p1429678415165622"></a><a name="p1429678415165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1098883387165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">f</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the file object that identifies a stream to set. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  otherwise. 

## setvbuf\(\)<a name="gaf691eb990d669a9edec8a9ec721ce3bc"></a>

```
int setvbuf ([FILE](IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1) * stream, char * buf, int mode, size_t size )
```

 **Description:**

Sets the mode and size of the buffer for a specified stream. 

**Parameters:**

<a name="table29948546165622"></a>
<table><thead align="left"><tr id="row580861310165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1097947923165622"><a name="p1097947923165622"></a><a name="p1097947923165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p234508757165622"><a name="p234508757165622"></a><a name="p234508757165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1611389530165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">stream</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the file object that identifies a stream. </td>
</tr>
<tr id="row1171063464165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">buf</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the start address of the buffer. </td>
</tr>
<tr id="row523989176165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">mode</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the buffer mode to set. There are three modes: <strong id="b391240232165622"><a name="b391240232165622"></a><a name="b391240232165622"></a>_IONBF</strong> (unbuffered), <strong id="b1902013114165622"><a name="b1902013114165622"></a><a name="b1902013114165622"></a> _IOLBF</strong> (line buffered), and <strong id="b903675007165622"><a name="b903675007165622"></a><a name="b903675007165622"></a>_IOFBF</strong> (fully buffered). </td>
</tr>
<tr id="row946705412165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">size</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the buffer block size when the buffer mode is <strong id="b739794344165622"><a name="b739794344165622"></a><a name="b739794344165622"></a>_IOFBF</strong>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise. 

## snprintf\(\)<a name="gad76145a6edfc98981ded8815a760e0cd"></a>

```
int snprintf (char * str, size_t size, const char * format,  ... )
```

 **Description:**

Prints formatted data of a maximum of  **size**  bytes from a variable argument list to a specified string. 

**Parameters:**

<a name="table1950853985165622"></a>
<table><thead align="left"><tr id="row1042992714165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1735314470165622"><a name="p1735314470165622"></a><a name="p1735314470165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p925063609165622"><a name="p925063609165622"></a><a name="p925063609165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1210427513165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">str</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the string to which the data is to be written. </td>
</tr>
<tr id="row771633766165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">size</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the maximum length of the destination string. </td>
</tr>
<tr id="row2122785998165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">format</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the format string. </td>
</tr>
<tr id="row2144449342165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">...</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the list of arguments corresponding to the format specifiers. </td>
</tr>
</tbody>
</table>

**Attention:**

This function can write a maximum of size-1 valid characters to the destination string. 

**Returns:**

Returns the number of formatted characters written \(excluding the terminating null character  **'\\0'**\) if the operation is successful; returns a negative value otherwise. If the return value is a non-negative value smaller than the value of  **size**, the string has been completely written.

## sprintf\(\)<a name="ga3082155ec11e7229f7a20439b31a169e"></a>

```
int sprintf (char * str, const char * format,  ... )
```

 **Description:**

Prints formatted data from a variable argument list to a specified string. 

**Parameters:**

<a name="table1654160234165622"></a>
<table><thead align="left"><tr id="row18140726165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1853193827165622"><a name="p1853193827165622"></a><a name="p1853193827165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1827655539165622"><a name="p1827655539165622"></a><a name="p1827655539165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row519919856165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">str</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the string to which the data is to be written. </td>
</tr>
<tr id="row888487955165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">format</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the format string. </td>
</tr>
<tr id="row1645841333165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">...</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the list of arguments corresponding to the format specifiers. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the total number of characters \(excluding the terminating null character  **'\\0'**\) if the operation is successful; returns a negative value otherwise. 

## sscanf\(\)<a name="gaec1e54556dca3bd701d44395d34818dd"></a>

```
int sscanf (const char * str, const char * format,  ... )
```

 **Description:**

Reads data from a character string pointed to by  **str**  and stores it based on  **format**  into the locations pointed to by the variable arguments. 

**Parameters:**

<a name="table1714711663165622"></a>
<table><thead align="left"><tr id="row756911053165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2063499781165622"><a name="p2063499781165622"></a><a name="p2063499781165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p21435980165622"><a name="p21435980165622"></a><a name="p21435980165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1531294229165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">str</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the character string to read. </td>
</tr>
<tr id="row910600171165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">format</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the format string. </td>
</tr>
<tr id="row1019620486165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">...</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the list of arguments corresponding to the format specifiers. </td>
</tr>
</tbody>
</table>

**Attention:**

An asterisk \(\*\) right after the percent symbol \(such as  **%\*d**  and  **%\*s**\) in the format denotes that the value for the format will be read but will not be stored into a variable. 

**Returns:**

Returns the number of fields successfully assigned to the argument list if the operation is successful; returns  **0**  if no fields are assigned; returns  **EOF**  if a reading error occurs or the end-of-file is reached during data reading. If an encoding error occurs when characters are parsed, this function sets  **errno**  to  [EILSEQ](UTILS.md#gac6c071293826a4e66a717bb38db7794d). 

## tempnam\(\)<a name="ga44dcf948b2c1dc3356d2937635a27839"></a>

```
char* tempnam (const char * dir, const char * prefix )
```

 **Description:**

Creates a temporary file with a unique file name. 

**Parameters:**

<a name="table590596857165622"></a>
<table><thead align="left"><tr id="row1812073993165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2092582515165622"><a name="p2092582515165622"></a><a name="p2092582515165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p454056526165622"><a name="p454056526165622"></a><a name="p454056526165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row947589357165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">dir</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to directory for creating the temporary file. </td>
</tr>
<tr id="row906193399165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">prefix</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the prefix of the file name. </td>
</tr>
</tbody>
</table>

**Attention:**

Do not use this function. Use  **[mkstemp\(\)](UTILS.md#ga6abe6c5eb77aeaf05ad81a7425547d9e)**  or  **tmpfile\(\)**  instead. 

**Returns:**

Returns the pointer to the unique name of the created temporary file if the operation is successful; returns  **NULL**  and sets  **errno**  to indicate an error otherwise. 

**See also:**

[mkstemp\(\)](UTILS.md#ga6abe6c5eb77aeaf05ad81a7425547d9e)  | tmpfile\(\) 

## ungetc\(\)<a name="ga54efa95b6d5b41adec98e5b8a1a9f27b"></a>

```
int ungetc (int c, [FILE](IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1) * stream )
```

 **Description:**

Pushes a character back into a specified file stream. 

This function is usually used together with  **getc**. 

**Parameters:**

<a name="table1895011836165622"></a>
<table><thead align="left"><tr id="row1001210291165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p356419031165622"><a name="p356419031165622"></a><a name="p356419031165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1740001437165622"><a name="p1740001437165622"></a><a name="p1740001437165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1559063654165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">c</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the int promotion of the character to be pushed back. </td>
</tr>
<tr id="row2063968061165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">stream</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the file object that identifies a stream. </td>
</tr>
</tbody>
</table>

**Attention:**

The pushed characters are returned in reverse order if multiple characters are pushed back. Only one pushback is guaranteed. 

**Returns:**

Returns the character specified in  **c**  if the operation is successful; returns  **EOF**  otherwise. 

## vasprintf\(\)<a name="ga5ec7fd90ebe6015636bce974c192c86a"></a>

```
int vasprintf (char ** strp, const char * fmt, va_list ap )
```

 **Description:**

Prints formatted data from a variable argument list to a specified character string. 

If the length of the string is uncertain, this function applies for sufficient memory space based on the length of the formatted character string. 

**Parameters:**

<a name="table1831603622165622"></a>
<table><thead align="left"><tr id="row1665766561165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1415724651165622"><a name="p1415724651165622"></a><a name="p1415724651165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1775223128165622"><a name="p1775223128165622"></a><a name="p1775223128165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row403003848165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">strp</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double pointer to the start address of the target string. </td>
</tr>
<tr id="row1221100244165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fmt</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the format string. </td>
</tr>
<tr id="row1631588642165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">ap</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates a value identifying a variable argument list initialized by using <strong id="b512863088165622"><a name="b512863088165622"></a><a name="b512863088165622"></a>va_start</strong>. </td>
</tr>
</tbody>
</table>

**Attention:**

If  **strp**  is no longer used, the applied space must be released. 

**Returns:**

Returns the number of output characters if the operation is successful; returns  **-1**  otherwise. 

## vdprintf\(\)<a name="ga0d0a950c2b4e6fba795cb7d8f2e8b8b8"></a>

```
int vdprintf (int fd, const char * format, va_list ap )
```

 **Description:**

Prints formatted data from a variable argument list to a specified file. 

**Parameters:**

<a name="table368790397165622"></a>
<table><thead align="left"><tr id="row1925715353165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2125305837165622"><a name="p2125305837165622"></a><a name="p2125305837165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1718136954165622"><a name="p1718136954165622"></a><a name="p1718136954165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1943756260165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fd</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the file descriptor that identifies a file. </td>
</tr>
<tr id="row1099457603165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">format</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the format string. </td>
</tr>
<tr id="row397039449165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">ap</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates a value identifying a variable argument list initialized by using <strong id="b1205278184165622"><a name="b1205278184165622"></a><a name="b1205278184165622"></a>va_start</strong>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the total number of written characters if the operation is successful; returns a negative value otherwise. 

## verr\(\)<a name="gaf5491fca8b356da75d96fc469bf32ea6"></a>

```
void verr (int eval, const char * fmt, va_list args )
```

 **Description:**

Displays error information. 

This function outputs the executable file name  **argv\[0\]**  and the accepted second formal parameter to stderr. 

**Parameters:**

<a name="table1723823952165622"></a>
<table><thead align="left"><tr id="row327976325165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2060101873165622"><a name="p2060101873165622"></a><a name="p2060101873165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p950708545165622"><a name="p950708545165622"></a><a name="p950708545165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1489415722165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">eval</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">This function does not return, but exits with the value of <strong id="b1911640826165622"><a name="b1911640826165622"></a><a name="b1911640826165622"></a>eval</strong>. </td>
</tr>
<tr id="row1794011250165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fmt</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the string to format. </td>
</tr>
<tr id="row230214951165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">args</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the parameters initialized by using <a href="UTILS.md#gaa0628ab596c3d7e78f5e08c2d98e24da">va_start</a>. </td>
</tr>
</tbody>
</table>

## verrx\(\)<a name="ga4b5f9ccd84c00dc473329e4bf64125e1"></a>

```
void verrx (int eval, const char * fmt, va_list args )
```

 **Description:**

Displays a formatted error message. 

**Parameters:**

<a name="table1492285781165622"></a>
<table><thead align="left"><tr id="row1782441147165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p904457989165622"><a name="p904457989165622"></a><a name="p904457989165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p669800560165622"><a name="p669800560165622"></a><a name="p669800560165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row962791164165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">eval</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">This function does not return, but exits with the value of <strong id="b730242800165622"><a name="b730242800165622"></a><a name="b730242800165622"></a>eval</strong>. </td>
</tr>
<tr id="row1019461389165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fmt</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the string to format. </td>
</tr>
<tr id="row384052786165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">args</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the parameters initialized by using <a href="UTILS.md#gaa0628ab596c3d7e78f5e08c2d98e24da">va_start</a>. </td>
</tr>
</tbody>
</table>

## vfprintf\(\)<a name="gad80f05917df38df3a5e1817498d67c26"></a>

```
int vfprintf ([FILE](IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1) * stream, const char * format, va_list ap )
```

 **Description:**

Prints formatted data from a variable argument list to a specified file stream. 

**Parameters:**

<a name="table1635425637165622"></a>
<table><thead align="left"><tr id="row782952496165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1849410389165622"><a name="p1849410389165622"></a><a name="p1849410389165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1732556869165622"><a name="p1732556869165622"></a><a name="p1732556869165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row974125805165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">stream</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the file object that identifies a stream. </td>
</tr>
<tr id="row718823817165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">format</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the format string. </td>
</tr>
<tr id="row2032049977165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">ap</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates a value identifying a variable argument list initialized by using <strong id="b1087328844165622"><a name="b1087328844165622"></a><a name="b1087328844165622"></a>va_start</strong>. </td>
</tr>
</tbody>
</table>

**Attention:**

This function is generally used together with  **va\_start**  and  **va\_end**. 

**Returns:**

Returns the total number of characters \(excluding the terminating null character  **'\\0'**\) if the operation is successful; returns a negative value otherwise. 

## vfscanf\(\)<a name="gabdd32e401e37c9d954f3f0a6907500d9"></a>

```
int vfscanf ([FILE](IO.md#ga912af5ab9f8a52ddd387b7defc0b49f1) * stream, const char * format, va_list ap )
```

 **Description:**

Reads data from a specified file stream and stores it based on  **format**  into the locations pointed to by the elements in the variable argument list identified by  **ap**. 

**Parameters:**

<a name="table1323487626165622"></a>
<table><thead align="left"><tr id="row1678073456165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1061006182165622"><a name="p1061006182165622"></a><a name="p1061006182165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p361804331165622"><a name="p361804331165622"></a><a name="p361804331165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1220108732165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">stream</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the file object that identifies a stream. </td>
</tr>
<tr id="row1487444107165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">format</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the format string. </td>
</tr>
<tr id="row143526144165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">ap</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates a value identifying a variable argument list initialized by using <strong id="b77988664165622"><a name="b77988664165622"></a><a name="b77988664165622"></a>va_start</strong>. </td>
</tr>
</tbody>
</table>

**Attention:**

This function is generally used together with  **va\_start**  and  **va\_end**. 

**Returns:**

Returns the number of fields successfully assigned to the argument list if the operation is successful; returns  **0**  if no fields are assigned; returns  **EOF**  if a reading error occurs or the end-of-file is reached during data reading. If an encoding error occurs when characters are parsed, this function sets  **errno**  to  [EILSEQ](UTILS.md#gac6c071293826a4e66a717bb38db7794d). 

## vprintf\(\)<a name="gaa715ef816dc040c8b367fde4ba84d6f3"></a>

```
int vprintf (const char * format, va_list ap )
```

 **Description:**

Prints formatted data from a variable argument list to the stdout. 

**Parameters:**

<a name="table2097891630165622"></a>
<table><thead align="left"><tr id="row2133166863165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1423889956165622"><a name="p1423889956165622"></a><a name="p1423889956165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2082832136165622"><a name="p2082832136165622"></a><a name="p2082832136165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2033224230165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">format</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the format string. </td>
</tr>
<tr id="row482986657165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">ap</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates a value identifying a variable argument list initialized by using <strong id="b786984824165622"><a name="b786984824165622"></a><a name="b786984824165622"></a>va_start</strong>. </td>
</tr>
</tbody>
</table>

**Attention:**

This function is generally used together with  **va\_start**  and  **va\_end**. 

**Returns:**

Returns the total number of characters \(excluding the terminating null character  **'\\0'**\) if the operation is successful; returns a negative value otherwise. 

## vscanf\(\)<a name="ga40250d63904acd3e898061c9eab6ead3"></a>

```
int vscanf (const char * format, va_list ap )
```

 **Description:**

Reads data from the stdin and stores it based on  **format**  into the locations pointed to by the elements in the variable argument list identified by  **ap**. 

**Parameters:**

<a name="table1140150591165622"></a>
<table><thead align="left"><tr id="row119094442165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p943038137165622"><a name="p943038137165622"></a><a name="p943038137165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p342088435165622"><a name="p342088435165622"></a><a name="p342088435165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1521253638165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">format</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the format string. </td>
</tr>
<tr id="row1309591872165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">ap</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates a value identifying a variable argument list initialized by using <strong id="b438847965165622"><a name="b438847965165622"></a><a name="b438847965165622"></a>va_start</strong>. </td>
</tr>
</tbody>
</table>

**Attention:**

This function is generally used together with  **va\_start**  and  **va\_end**. 

**Returns:**

Returns the number of fields successfully assigned to the argument list if the operation is successful; returns  **0**  if no fields are assigned; returns  **EOF**  if a reading error occurs or the end-of-file is reached during data reading. If an encoding error occurs when characters are parsed, this function sets  **errno**  to  [EILSEQ](UTILS.md#gac6c071293826a4e66a717bb38db7794d). 

## vsnprintf\(\)<a name="ga2cadafbeb2d6e0d5781f6e5106d41fc2"></a>

```
int vsnprintf (char * str, size_t size, const char * format, va_list ap )
```

 **Description:**

Prints formatted data of a maximum of  **size**  bytes from a variable argument list to a specified string. 

**Parameters:**

<a name="table845418093165622"></a>
<table><thead align="left"><tr id="row490910926165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1850732326165622"><a name="p1850732326165622"></a><a name="p1850732326165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p137314055165622"><a name="p137314055165622"></a><a name="p137314055165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1886446050165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">str</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the destination character string. </td>
</tr>
<tr id="row1064970782165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">size</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the maximum length of the destination string. </td>
</tr>
<tr id="row1689326891165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">format</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the format string. </td>
</tr>
<tr id="row1933601291165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">ap</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates a value identifying a variable argument list initialized by using <strong id="b373103196165622"><a name="b373103196165622"></a><a name="b373103196165622"></a>va_start</strong>. </td>
</tr>
</tbody>
</table>

**Attention:**

This function can write a maximum of size-1 characters to the destination string. 

**Returns:**

Returns the number of formatted characters written \(excluding the terminating null character  **'\\0'**\) if the operation is successful; returns a negative value otherwise. If the return value is a non-negative value smaller than the value of  **size**, the string has been completely written.

## vsprintf\(\)<a name="gaab3db67c98c32122fcb3d076d4207bbc"></a>

```
int vsprintf (char * str, const char * format, va_list ap )
```

 **Description:**

Prints formatted data from a variable argument list to a specified string. 

**Parameters:**

<a name="table2024797762165622"></a>
<table><thead align="left"><tr id="row1418366120165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1363495196165622"><a name="p1363495196165622"></a><a name="p1363495196165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p732743501165622"><a name="p732743501165622"></a><a name="p732743501165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row701246569165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">str</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the destination character string. </td>
</tr>
<tr id="row1118877262165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">format</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the format string. </td>
</tr>
<tr id="row1876479492165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">ap</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates a value identifying a variable argument list initialized by using <strong id="b2028610931165622"><a name="b2028610931165622"></a><a name="b2028610931165622"></a>va_start</strong>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the total number of characters written \(excluding the terminating null character  **'\\0'**\) if the operation is successful; returns a negative value otherwise. 

## vsscanf\(\)<a name="gab1c4552aba80fe03c9b45fe27f4331ad"></a>

```
int vsscanf (const char * str, const char * format, va_list ap )
```

 **Description:**

Reads data from a specified string and stores it based on  **format**  into the locations pointed to by the elements in the variable argument list identified by  **ap**. 

**Parameters:**

<a name="table231379981165622"></a>
<table><thead align="left"><tr id="row75272922165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1743185192165622"><a name="p1743185192165622"></a><a name="p1743185192165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p610908603165622"><a name="p610908603165622"></a><a name="p610908603165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1101028384165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">str</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the character string to read. </td>
</tr>
<tr id="row396530163165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">format</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the format string. </td>
</tr>
<tr id="row485691075165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">ap</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates a value identifying a variable argument list initialized by using <strong id="b1958719591165622"><a name="b1958719591165622"></a><a name="b1958719591165622"></a>va_start</strong>. </td>
</tr>
</tbody>
</table>

**Attention:**

This function is generally used together with  **va\_start**  and  **va\_end**. 

**Returns:**

Returns the number of fields successfully assigned to the argument list if the operation is successful; returns  **0**  if no fields are assigned; returns  **EOF**  if a reading error occurs or the end-of-file is reached during data reading. If an encoding error occurs when characters are parsed, this function sets  **errno**  to  [EILSEQ](UTILS.md#gac6c071293826a4e66a717bb38db7794d). 

## vwarn\(\)<a name="ga9ca1ffba0c6f5df7b172d25917611b4a"></a>

```
void vwarn (const char * fmt, va_list args )
```

 **Description:**

Displays a formatted error message on the stderr output. 

If the  **fmt**  parameter is not  **NULL**, stderr displays the error code description obtained from strerror\(errno\), followed by a space and a colon \(:\), and the error message to print. 

**Parameters:**

<a name="table1619913890165622"></a>
<table><thead align="left"><tr id="row1630438768165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2014546131165622"><a name="p2014546131165622"></a><a name="p2014546131165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p473200852165622"><a name="p473200852165622"></a><a name="p473200852165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1840848618165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fmt</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the string to format. </td>
</tr>
<tr id="row1919129862165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">args</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the parameters initialized by using <a href="UTILS.md#gaa0628ab596c3d7e78f5e08c2d98e24da">va_start</a>. </td>
</tr>
</tbody>
</table>

## vwarnx\(\)<a name="ga22924aaaaa6b6e8bba4c76d0a0fe86cd"></a>

```
void vwarnx (const char * fmt, va_list args )
```

 **Description:**

Displays a formatted error message on the stderr output. 

If the  **fmt**  parameter is not  **NULL**, stderr displays the error code description obtained from strerror\(errno\), followed by a space and a colon \(:\), and the error message to print. 

**Parameters:**

<a name="table112340430165622"></a>
<table><thead align="left"><tr id="row1297489619165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p473294411165622"><a name="p473294411165622"></a><a name="p473294411165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p867549381165622"><a name="p867549381165622"></a><a name="p867549381165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row339006944165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fmt</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the string to format. </td>
</tr>
<tr id="row1062293961165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">args</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the parameters initialized by using <a href="UTILS.md#gaa0628ab596c3d7e78f5e08c2d98e24da">va_start</a>. </td>
</tr>
</tbody>
</table>

## warn\(\)<a name="gaf80d19f1297a11626fab61a248959c71"></a>

```
void warn (const char * fmt,  ... )
```

 **Description:**

Displays a formatted error message on the standard error \(stderr\) output. 

If the  **fmt**  parameter is not  **NULL**, stderr displays the error code description obtained from strerror\(errno\), followed by a space and a colon \(:\), and the error message to print. 

**Parameters:**

<a name="table1257016534165622"></a>
<table><thead align="left"><tr id="row1801551538165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1588637268165622"><a name="p1588637268165622"></a><a name="p1588637268165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p869152678165622"><a name="p869152678165622"></a><a name="p869152678165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row726145241165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fmt</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the string to format. </td>
</tr>
<tr id="row919070525165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">...</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the parameters corresponding to the format declaration. </td>
</tr>
</tbody>
</table>

## warnx\(\)<a name="ga58f3d9691c146f86e562022d39567b7f"></a>

```
void warnx (const char * fmt,  ... )
```

 **Description:**

Displays a formatted error message on the stderr output. 

If the  **fmt**  parameter is not  **NULL**, stderr displays the error code description obtained from strerror\(errno\), followed by a space and a colon \(:\), and the error message to print. 

**Parameters:**

<a name="table1378697747165622"></a>
<table><thead align="left"><tr id="row253094706165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p263962812165622"><a name="p263962812165622"></a><a name="p263962812165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1674827990165622"><a name="p1674827990165622"></a><a name="p1674827990165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1937286949165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fmt</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the string to format. </td>
</tr>
<tr id="row1056187145165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">...</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the parameters corresponding to the format declaration. </td>
</tr>
</tbody>
</table>

## writev\(\)<a name="gad57f362a0aef72b52ea59288f74dd1ea"></a>

```
ssize_t writev (int fd, const struct iovec * iov, int iovcnt )
```

 **Description:**

Writes a given length of data into a file. 

This function is used to write the  **iovcnt**  length of  **iov**  to  **fd**. 

**Parameters:**

<a name="table1999483525165622"></a>
<table><thead align="left"><tr id="row12182165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1424410861165622"><a name="p1424410861165622"></a><a name="p1424410861165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p786591860165622"><a name="p786591860165622"></a><a name="p786591860165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row584022969165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fd</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the file descriptor. </td>
</tr>
<tr id="row640389614165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">iov</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the multi-group buffer. </td>
</tr>
<tr id="row308794707165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">iovcnt</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the number of buffers. For details, see <a href="UTILS.md#ga25080e819a36fcf9aede01a6e7298ea4">IOV_MAX</a>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the number of bytes written if the operation is successful; returns  **-1**  and sets  **errno**  to a value if the operation fails. If  **errno**  is set to  **EINVAL**, the sum of the  **iov\_len**  values overflows an  **ssize\_t**  value, or the vector count  **iovcnt**  is less than 0 or greater than the permitted maximum. 

