# errno.h<a name="ZH-CN_TOPIC_0000001055069404"></a>

-   [Overview](#section7537069165627)
-   [Summary](#section1432932423165627)
-   [Macros](#define-members)

## **Overview**<a name="section7537069165627"></a>

**Related Modules:**

[UTILS](UTILS.md)

**Description:**

Defines error codes. 

You can view the value of  **errno**  to check the error code definition in this file to preliminarily locate the fault. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1432932423165627"></a>

## Macros<a name="define-members"></a>

<a name="table1174886735165627"></a>
<table><thead align="left"><tr id="row1664904954165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1893963027165627"><a name="p1893963027165627"></a><a name="p1893963027165627"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1564811034165627"><a name="p1564811034165627"></a><a name="p1564811034165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1855730489165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p939559627165627"><a name="p939559627165627"></a><a name="p939559627165627"></a><a href="UTILS.md#gadd669d31505a077f769cff8e66c780b3">EPERM</a>   1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1267469973165627"><a name="p1267469973165627"></a><a name="p1267469973165627"></a>Operation not permitted. </p>
</td>
</tr>
<tr id="row380895295165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2066196728165627"><a name="p2066196728165627"></a><a name="p2066196728165627"></a><a href="UTILS.md#ga03e689f378f643d16ea7537918528a48">ENOENT</a>   2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p921793736165627"><a name="p921793736165627"></a><a name="p921793736165627"></a>No such file or path. </p>
</td>
</tr>
<tr id="row1800964927165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2004353752165627"><a name="p2004353752165627"></a><a name="p2004353752165627"></a><a href="UTILS.md#ga462e47a8af6288232a5df548221ada4c">ESRCH</a>   3</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1093283253165627"><a name="p1093283253165627"></a><a name="p1093283253165627"></a>No such process. </p>
</td>
</tr>
<tr id="row1485926540165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1003338454165627"><a name="p1003338454165627"></a><a name="p1003338454165627"></a><a href="UTILS.md#ga46b83d9f6c23b1b65a8cecfd775ddaed">EINTR</a>   4</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1077746567165627"><a name="p1077746567165627"></a><a name="p1077746567165627"></a>Interrupted function call. </p>
</td>
</tr>
<tr id="row1291946064165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2127828709165627"><a name="p2127828709165627"></a><a name="p2127828709165627"></a><a href="UTILS.md#ga70979f50f9c83e5aebab3d6a1bd4cf35">EIO</a>   5</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1220893783165627"><a name="p1220893783165627"></a><a name="p1220893783165627"></a>I/O error. </p>
</td>
</tr>
<tr id="row2099616056165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1566782752165627"><a name="p1566782752165627"></a><a name="p1566782752165627"></a><a href="UTILS.md#ga2b3884b11e4932bd372bb6d899d6fbfe">ENXIO</a>   6</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1696477383165627"><a name="p1696477383165627"></a><a name="p1696477383165627"></a>No such device or address. </p>
</td>
</tr>
<tr id="row1107532884165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1828973927165627"><a name="p1828973927165627"></a><a name="p1828973927165627"></a><a href="UTILS.md#gaba8481985c201ff726f349d7f2d09895">E2BIG</a>   7</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p949216926165627"><a name="p949216926165627"></a><a name="p949216926165627"></a>Parameter list too long. </p>
</td>
</tr>
<tr id="row1945601531165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1862682548165627"><a name="p1862682548165627"></a><a name="p1862682548165627"></a><a href="UTILS.md#ga4d0b1b435ec441e7d50a430b83df5832">ENOEXEC</a>   8</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p986540454165627"><a name="p986540454165627"></a><a name="p986540454165627"></a>Exec format error. </p>
</td>
</tr>
<tr id="row1184904608165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2131525521165627"><a name="p2131525521165627"></a><a name="p2131525521165627"></a><a href="UTILS.md#gac54507d66b43ad12f9356257323c0018">EBADF</a>   9</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p878428141165627"><a name="p878428141165627"></a><a name="p878428141165627"></a>Bad file descriptor. </p>
</td>
</tr>
<tr id="row1777076653165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1827286531165627"><a name="p1827286531165627"></a><a name="p1827286531165627"></a><a href="UTILS.md#ga47b42c351e0e011a048058d224205c0f">ECHILD</a>   10</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p325709076165627"><a name="p325709076165627"></a><a name="p325709076165627"></a>No child processes. </p>
</td>
</tr>
<tr id="row261182512165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1895101190165627"><a name="p1895101190165627"></a><a name="p1895101190165627"></a><a href="UTILS.md#gaf0fac1cea1165b4debec7f686edf3313">EAGAIN</a>   11</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1676255935165627"><a name="p1676255935165627"></a><a name="p1676255935165627"></a>Retry. </p>
</td>
</tr>
<tr id="row1981487020165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1757133337165627"><a name="p1757133337165627"></a><a name="p1757133337165627"></a><a href="UTILS.md#ga6a05c923dad0c1208043e9c20a58c8e5">ENOMEM</a>   12</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1876386819165627"><a name="p1876386819165627"></a><a name="p1876386819165627"></a>Not enough memory space. </p>
</td>
</tr>
<tr id="row1472200691165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1975674897165627"><a name="p1975674897165627"></a><a name="p1975674897165627"></a><a href="UTILS.md#gac2a2e9fa555401f94478f74e01868032">EACCES</a>   13</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2067394648165627"><a name="p2067394648165627"></a><a name="p2067394648165627"></a>Incorrect permission. </p>
</td>
</tr>
<tr id="row2018664438165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p684217996165627"><a name="p684217996165627"></a><a name="p684217996165627"></a><a href="UTILS.md#ga3f317946e043623f9d6b93dbf60e6316">EFAULT</a>   14</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p854373141165627"><a name="p854373141165627"></a><a name="p854373141165627"></a>Invalid address. </p>
</td>
</tr>
<tr id="row546843245165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p897773476165627"><a name="p897773476165627"></a><a name="p897773476165627"></a><a href="UTILS.md#gaa0a4b0e307e83f52be51099f01156936">ENOTBLK</a>   15</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p171038954165627"><a name="p171038954165627"></a><a name="p171038954165627"></a>Block device request. </p>
</td>
</tr>
<tr id="row567900020165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p159752471165627"><a name="p159752471165627"></a><a name="p159752471165627"></a><a href="UTILS.md#ga8368025077a0385849d6817b2007c095">EBUSY</a>   16</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1957911187165627"><a name="p1957911187165627"></a><a name="p1957911187165627"></a>Device or resource busy. </p>
</td>
</tr>
<tr id="row1394803616165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p28943337165627"><a name="p28943337165627"></a><a name="p28943337165627"></a><a href="UTILS.md#ga0a3bef9e5c47e42917692b5dae3b5498">EEXIST</a>   17</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1648451040165627"><a name="p1648451040165627"></a><a name="p1648451040165627"></a>File exists. </p>
</td>
</tr>
<tr id="row556625839165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p274693366165627"><a name="p274693366165627"></a><a name="p274693366165627"></a><a href="UTILS.md#ga3396cf9fb0ff5af3a18dd2a2bbdb21e1">EXDEV</a>   18</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1293715148165627"><a name="p1293715148165627"></a><a name="p1293715148165627"></a>Incorrect link. </p>
</td>
</tr>
<tr id="row57675437165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1334679343165627"><a name="p1334679343165627"></a><a name="p1334679343165627"></a><a href="UTILS.md#gab9b8cc17d1947160d13faaba7a18d6d1">ENODEV</a>   19</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1262541897165627"><a name="p1262541897165627"></a><a name="p1262541897165627"></a>No such device. </p>
</td>
</tr>
<tr id="row2105196038165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1184776101165627"><a name="p1184776101165627"></a><a name="p1184776101165627"></a><a href="UTILS.md#ga9262fb92f7ef662d0bdd577912a5b101">ENOTDIR</a>   20</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1836831361165627"><a name="p1836831361165627"></a><a name="p1836831361165627"></a>Not a directory. </p>
</td>
</tr>
<tr id="row2062280895165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1402340710165627"><a name="p1402340710165627"></a><a name="p1402340710165627"></a><a href="UTILS.md#gae22c3a1e0a38f3896de238cc30d0e19b">EISDIR</a>   21</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1651455120165627"><a name="p1651455120165627"></a><a name="p1651455120165627"></a>Is a directory. </p>
</td>
</tr>
<tr id="row42951286165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p20249736165627"><a name="p20249736165627"></a><a name="p20249736165627"></a><a href="UTILS.md#ga2d1678d5a7cc8ce499643f3b8957def4">EINVAL</a>   22</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1625638159165627"><a name="p1625638159165627"></a><a name="p1625638159165627"></a>Invalid parameter. </p>
</td>
</tr>
<tr id="row827226450165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p672095524165627"><a name="p672095524165627"></a><a name="p672095524165627"></a><a href="UTILS.md#ga5554094b3fb4bb6ebeb0157cb3f82a55">ENFILE</a>   23</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p59479748165627"><a name="p59479748165627"></a><a name="p59479748165627"></a>Too many opened files in system (the maximum number exceeded) </p>
</td>
</tr>
<tr id="row145124257165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1885654848165627"><a name="p1885654848165627"></a><a name="p1885654848165627"></a><a href="UTILS.md#ga64a75c174882ddbfa726c7fd040f87a1">EMFILE</a>   24</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1378493804165627"><a name="p1378493804165627"></a><a name="p1378493804165627"></a>Too many opened files in a process (the maximum number exceeded) </p>
</td>
</tr>
<tr id="row1710374720165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1437638474165627"><a name="p1437638474165627"></a><a name="p1437638474165627"></a><a href="UTILS.md#gac3daf409082bb528032f4452a81e1034">ENOTTY</a>   25</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1531323733165627"><a name="p1531323733165627"></a><a name="p1531323733165627"></a>Inappropriate I/O control operation. </p>
</td>
</tr>
<tr id="row1696297799165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1302687980165627"><a name="p1302687980165627"></a><a name="p1302687980165627"></a><a href="UTILS.md#gaaed12e82224923d599b6f1939c8e0971">ETXTBSY</a>   26</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p736950516165627"><a name="p736950516165627"></a><a name="p736950516165627"></a>Text file busy. </p>
</td>
</tr>
<tr id="row620108688165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1945984628165627"><a name="p1945984628165627"></a><a name="p1945984628165627"></a><a href="UTILS.md#gaf5401a500939ed1812c04ca200b95eef">EFBIG</a>   27</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p58962209165627"><a name="p58962209165627"></a><a name="p58962209165627"></a>File too large. </p>
</td>
</tr>
<tr id="row1152672375165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p830262223165627"><a name="p830262223165627"></a><a name="p830262223165627"></a><a href="UTILS.md#ga088abe8bad2df798edad3053d719b937">ENOSPC</a>   28</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p460783790165627"><a name="p460783790165627"></a><a name="p460783790165627"></a>No space left on device. </p>
</td>
</tr>
<tr id="row1044784265165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1043474554165627"><a name="p1043474554165627"></a><a name="p1043474554165627"></a><a href="UTILS.md#ga0e42d4f9fecdcf5fcca2b333252173c3">ESPIPE</a>   29</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1337675145165627"><a name="p1337675145165627"></a><a name="p1337675145165627"></a>Invalid query. </p>
</td>
</tr>
<tr id="row892821957165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1217137649165627"><a name="p1217137649165627"></a><a name="p1217137649165627"></a><a href="UTILS.md#gacb02bb67dddd7ca8cf82634a0781d58d">EROFS</a>   30</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1328775016165627"><a name="p1328775016165627"></a><a name="p1328775016165627"></a>Read-only file system. </p>
</td>
</tr>
<tr id="row2041506266165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p427999798165627"><a name="p427999798165627"></a><a name="p427999798165627"></a><a href="UTILS.md#ga97f59fa1a5a2f61b792c1b9dfc218072">EMLINK</a>   31</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1349350979165627"><a name="p1349350979165627"></a><a name="p1349350979165627"></a>Too many links. </p>
</td>
</tr>
<tr id="row1250684213165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p124411043165627"><a name="p124411043165627"></a><a name="p124411043165627"></a><a href="UTILS.md#ga5f8d33deb08fa27c04897b278ac7f965">EPIPE</a>   32</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1208904360165627"><a name="p1208904360165627"></a><a name="p1208904360165627"></a>The pipe file is incorrect or the read end of the pipe is closed during the write operation. </p>
</td>
</tr>
<tr id="row692335247165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1415351016165627"><a name="p1415351016165627"></a><a name="p1415351016165627"></a><a href="UTILS.md#ga5fe247e079b591a68e0fdbf7caec5b70">EDOM</a>   33</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1311620058165627"><a name="p1311620058165627"></a><a name="p1311620058165627"></a>Domain error. The value of at least one input parameter is out of the parameter range. </p>
</td>
</tr>
<tr id="row1190915212165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1475511054165627"><a name="p1475511054165627"></a><a name="p1475511054165627"></a><a href="UTILS.md#gaa1591a4f3a86360108de5b9ba34980ca">ERANGE</a>   34</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1574917720165627"><a name="p1574917720165627"></a><a name="p1574917720165627"></a>The actual return value exceeds the return value range. </p>
</td>
</tr>
<tr id="row1124953782165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p849432787165627"><a name="p849432787165627"></a><a name="p849432787165627"></a><a href="UTILS.md#ga55cc70ce0ba661298f3c412095dfeeb6">EDEADLK</a>   35</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1667349779165627"><a name="p1667349779165627"></a><a name="p1667349779165627"></a>Resource deadlock. </p>
</td>
</tr>
<tr id="row1541054067165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1643056893165627"><a name="p1643056893165627"></a><a name="p1643056893165627"></a><a href="UTILS.md#ga41d5ab3a8a05f9c5eab536c9cfba305b">ENAMETOOLONG</a>   36</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1367634413165627"><a name="p1367634413165627"></a><a name="p1367634413165627"></a>File name too long. </p>
</td>
</tr>
<tr id="row1079488056165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p113358157165627"><a name="p113358157165627"></a><a name="p113358157165627"></a><a href="UTILS.md#ga65e1a7bda392be276a701988d0604e63">ENOLCK</a>   37</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2069251194165627"><a name="p2069251194165627"></a><a name="p2069251194165627"></a>No locks available. </p>
</td>
</tr>
<tr id="row1261075507165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p358118458165627"><a name="p358118458165627"></a><a name="p358118458165627"></a><a href="UTILS.md#ga43785b9969e0bd1af532dbde06c5540b">ENOSYS</a>   38</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1732896073165627"><a name="p1732896073165627"></a><a name="p1732896073165627"></a>Function not implemented. </p>
</td>
</tr>
<tr id="row1765231752165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1971343612165627"><a name="p1971343612165627"></a><a name="p1971343612165627"></a><a href="UTILS.md#gaa0f602f3fd369a6fede82190710b9c5c">ENOTEMPTY</a>   39</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p990728392165627"><a name="p990728392165627"></a><a name="p990728392165627"></a>Directory not empty. </p>
</td>
</tr>
<tr id="row97424723165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1203331437165627"><a name="p1203331437165627"></a><a name="p1203331437165627"></a><a href="UTILS.md#ga2f78c246352d2bf2f19dc5d43da2f0c9">ELOOP</a>   40</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1521434387165627"><a name="p1521434387165627"></a><a name="p1521434387165627"></a>Too many levels of symbolic links. </p>
</td>
</tr>
<tr id="row534532539165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p402784390165627"><a name="p402784390165627"></a><a name="p402784390165627"></a><a href="UTILS.md#ga4a3a0b3605fd3b2336455062ee8e25f0">EWOULDBLOCK</a>   <a href="UTILS.md#gaf0fac1cea1165b4debec7f686edf3313">EAGAIN</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p73300716165627"><a name="p73300716165627"></a><a name="p73300716165627"></a>Operation would block (the same value as <a href="UTILS.md#gaf0fac1cea1165b4debec7f686edf3313">EAGAIN</a>) </p>
</td>
</tr>
<tr id="row806417929165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1036562293165627"><a name="p1036562293165627"></a><a name="p1036562293165627"></a><a href="UTILS.md#gae40596feaa3f66f5440b485bf7c1c2d1">ENOMSG</a>   42</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1767132359165627"><a name="p1767132359165627"></a><a name="p1767132359165627"></a>No message of the desired type. </p>
</td>
</tr>
<tr id="row1851746001165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p82887741165627"><a name="p82887741165627"></a><a name="p82887741165627"></a><a href="UTILS.md#gad9913290fef890d46a6b7e8b4bfb1c29">EIDRM</a>   43</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p514947467165627"><a name="p514947467165627"></a><a name="p514947467165627"></a>Identifier removed. </p>
</td>
</tr>
<tr id="row349431212165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1238598520165627"><a name="p1238598520165627"></a><a name="p1238598520165627"></a><a href="UTILS.md#ga15d68f826dc2f784d7d3627311e916c1">ECHRNG</a>   44</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1326510798165627"><a name="p1326510798165627"></a><a name="p1326510798165627"></a>Channel number out of range. </p>
</td>
</tr>
<tr id="row310564616165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2070351557165627"><a name="p2070351557165627"></a><a name="p2070351557165627"></a><a href="UTILS.md#gacdf97ac22e88c3988c28c9c8f7d14c5e">EL2NSYNC</a>   45</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1807504402165627"><a name="p1807504402165627"></a><a name="p1807504402165627"></a>Level 2 not synchronized. </p>
</td>
</tr>
<tr id="row1029917535165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p976561791165627"><a name="p976561791165627"></a><a name="p976561791165627"></a><a href="UTILS.md#ga2e4efb348b873846645cd56144b0ea1e">EL3HLT</a>   46</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1167507679165627"><a name="p1167507679165627"></a><a name="p1167507679165627"></a>Level 3 halted. </p>
</td>
</tr>
<tr id="row1724781457165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p635852092165627"><a name="p635852092165627"></a><a name="p635852092165627"></a><a href="UTILS.md#ga5117695086a9942c77befdbd650910cf">EL3RST</a>   47</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1399269164165627"><a name="p1399269164165627"></a><a name="p1399269164165627"></a>Level 3 reset. </p>
</td>
</tr>
<tr id="row178933952165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p628529383165627"><a name="p628529383165627"></a><a name="p628529383165627"></a><a href="UTILS.md#ga059ed0ab5dab96dfe00ffca40b35155f">ELNRNG</a>   48</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p320271003165627"><a name="p320271003165627"></a><a name="p320271003165627"></a>Link ID out of range. </p>
</td>
</tr>
<tr id="row492453141165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1381695569165627"><a name="p1381695569165627"></a><a name="p1381695569165627"></a><a href="UTILS.md#gac71878d33a396ae1a4e3fe16489f00a9">EUNATCH</a>   49</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p601767315165627"><a name="p601767315165627"></a><a name="p601767315165627"></a>Protocol driver not attached. </p>
</td>
</tr>
<tr id="row10319397165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1243901898165627"><a name="p1243901898165627"></a><a name="p1243901898165627"></a><a href="UTILS.md#ga2f1893e03a904a500dcb95ff8e35889b">ENOCSI</a>   50</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1526653880165627"><a name="p1526653880165627"></a><a name="p1526653880165627"></a>No available CSI structure. </p>
</td>
</tr>
<tr id="row1138263895165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1134357522165627"><a name="p1134357522165627"></a><a name="p1134357522165627"></a><a href="UTILS.md#ga81a4a94e4d7d996ad5d2a9137539e392">EL2HLT</a>   51</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1249522543165627"><a name="p1249522543165627"></a><a name="p1249522543165627"></a>Level 2 halted. </p>
</td>
</tr>
<tr id="row167939328165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p424072625165627"><a name="p424072625165627"></a><a name="p424072625165627"></a><a href="UTILS.md#ga0c17130b2933edfec68b2c70a2cd0a7f">EBADE</a>   52</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1372302630165627"><a name="p1372302630165627"></a><a name="p1372302630165627"></a>Invalid exchange. </p>
</td>
</tr>
<tr id="row769472038165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1360704887165627"><a name="p1360704887165627"></a><a name="p1360704887165627"></a><a href="UTILS.md#gaca1e9da0ef95864e910f550467d475fa">EBADR</a>   53</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p117482258165627"><a name="p117482258165627"></a><a name="p117482258165627"></a>Invalid request descriptor. </p>
</td>
</tr>
<tr id="row1238893742165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1959443622165627"><a name="p1959443622165627"></a><a name="p1959443622165627"></a><a href="UTILS.md#ga69aa360ec60f24c128556361f7729e48">EXFULL</a>   54</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p318905030165627"><a name="p318905030165627"></a><a name="p318905030165627"></a>Exchange full. </p>
</td>
</tr>
<tr id="row641329846165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p384037056165627"><a name="p384037056165627"></a><a name="p384037056165627"></a><a href="UTILS.md#ga7eb46ddb59ec78bac0de2d45ce2a5053">ENOANO</a>   55</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p402954527165627"><a name="p402954527165627"></a><a name="p402954527165627"></a>No anode. </p>
</td>
</tr>
<tr id="row24484287165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1119038309165627"><a name="p1119038309165627"></a><a name="p1119038309165627"></a><a href="UTILS.md#gabe200466dc512a9e314b9cc7d081c1ac">EBADRQC</a>   56</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1198969488165627"><a name="p1198969488165627"></a><a name="p1198969488165627"></a>Invalid request code. </p>
</td>
</tr>
<tr id="row1502654973165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2120975082165627"><a name="p2120975082165627"></a><a name="p2120975082165627"></a><a href="UTILS.md#ga45d8c9818d0bf75ad33ebab50631276a">EBADSLT</a>   57</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1043405587165627"><a name="p1043405587165627"></a><a name="p1043405587165627"></a>Invalid slot. </p>
</td>
</tr>
<tr id="row933758023165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p493978215165627"><a name="p493978215165627"></a><a name="p493978215165627"></a><a href="UTILS.md#gacfea92d35e42dd807a7e9beb1e394e4c">EDEADLOCK</a>   <a href="UTILS.md#ga55cc70ce0ba661298f3c412095dfeeb6">EDEADLK</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p167668650165627"><a name="p167668650165627"></a><a name="p167668650165627"></a>Resource deadlock (the same value as <a href="UTILS.md#ga55cc70ce0ba661298f3c412095dfeeb6">EDEADLK</a>) </p>
</td>
</tr>
<tr id="row1330015130165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p187318480165627"><a name="p187318480165627"></a><a name="p187318480165627"></a><a href="UTILS.md#gae4d80808cd12a64d14a3da0d39cad443">EBFONT</a>   59</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p208673643165627"><a name="p208673643165627"></a><a name="p208673643165627"></a>Incorrect font format. </p>
</td>
</tr>
<tr id="row321576016165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p285982363165627"><a name="p285982363165627"></a><a name="p285982363165627"></a><a href="UTILS.md#ga7cea86ddbdacae0b391674e680f17bdb">ENOSTR</a>   60</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p552188505165627"><a name="p552188505165627"></a><a name="p552188505165627"></a>Not a stream device. </p>
</td>
</tr>
<tr id="row11008735165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1028384612165627"><a name="p1028384612165627"></a><a name="p1028384612165627"></a><a href="UTILS.md#ga0030614bc864d1b24eaedd71585acc27">ENODATA</a>   61</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p386366123165627"><a name="p386366123165627"></a><a name="p386366123165627"></a>No message is available on the stream head read queue. </p>
</td>
</tr>
<tr id="row970329662165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1763227709165627"><a name="p1763227709165627"></a><a name="p1763227709165627"></a><a href="UTILS.md#gab59cf3c65eaf836d5c647fa2a24ca649">ETIME</a>   62</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p424933717165627"><a name="p424933717165627"></a><a name="p424933717165627"></a>Timer expired. </p>
</td>
</tr>
<tr id="row1708124303165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1734814122165627"><a name="p1734814122165627"></a><a name="p1734814122165627"></a><a href="UTILS.md#gad88bc6ea94ec1a5e91d3651677d85c00">ENOSR</a>   63</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1733281943165627"><a name="p1733281943165627"></a><a name="p1733281943165627"></a>No stream resources. </p>
</td>
</tr>
<tr id="row1457086315165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p299167745165627"><a name="p299167745165627"></a><a name="p299167745165627"></a><a href="UTILS.md#ga4a49ca5a72811f9950d2773806eaa641">ENONET</a>   64</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2064950543165627"><a name="p2064950543165627"></a><a name="p2064950543165627"></a>Machine is disconnected from the network. </p>
</td>
</tr>
<tr id="row671942647165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p568375505165627"><a name="p568375505165627"></a><a name="p568375505165627"></a><a href="UTILS.md#ga63fb0df2a890ace70f5093b26cbf7065">ENOPKG</a>   65</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p957511759165627"><a name="p957511759165627"></a><a name="p957511759165627"></a>Package not installed. </p>
</td>
</tr>
<tr id="row395909817165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p587484324165627"><a name="p587484324165627"></a><a name="p587484324165627"></a><a href="UTILS.md#ga5e1edba49c18fc631dbf54ff53702d4a">EREMOTE</a>   66</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p863737635165627"><a name="p863737635165627"></a><a name="p863737635165627"></a>Object is remote. </p>
</td>
</tr>
<tr id="row658196430165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p64966296165627"><a name="p64966296165627"></a><a name="p64966296165627"></a><a href="UTILS.md#gadd4408349a756880be9d91efadb8aed0">ENOLINK</a>   67</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1700959868165627"><a name="p1700959868165627"></a><a name="p1700959868165627"></a>Link has been severed. </p>
</td>
</tr>
<tr id="row1206975573165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p552776082165627"><a name="p552776082165627"></a><a name="p552776082165627"></a><a href="UTILS.md#ga7ef87d37bfaf88d1ad1de1b531330a42">EADV</a>   68</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1992980556165627"><a name="p1992980556165627"></a><a name="p1992980556165627"></a>Broadcast error. </p>
</td>
</tr>
<tr id="row44962065165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1463980200165627"><a name="p1463980200165627"></a><a name="p1463980200165627"></a><a href="UTILS.md#gae7df13cc989ed4b6921455a6eff3c249">ESRMNT</a>   69</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2115836603165627"><a name="p2115836603165627"></a><a name="p2115836603165627"></a>srmount error </p>
</td>
</tr>
<tr id="row1419257232165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p893225780165627"><a name="p893225780165627"></a><a name="p893225780165627"></a><a href="UTILS.md#gad9e159536fe852a5679a99a0b8191d69">ECOMM</a>   70</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1269623607165627"><a name="p1269623607165627"></a><a name="p1269623607165627"></a>Communication error on send. </p>
</td>
</tr>
<tr id="row1514741268165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1482564751165627"><a name="p1482564751165627"></a><a name="p1482564751165627"></a><a href="UTILS.md#ga5a92de56e8ebe19cbd8a2ce8c80ad03e">EPROTO</a>   71</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p815084264165627"><a name="p815084264165627"></a><a name="p815084264165627"></a>Protocol error. </p>
</td>
</tr>
<tr id="row495840475165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p504647503165627"><a name="p504647503165627"></a><a name="p504647503165627"></a><a href="UTILS.md#ga4d7b69d7ce0dfa0a9b998403b4ffe226">EMULTIHOP</a>   72</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p888172024165627"><a name="p888172024165627"></a><a name="p888172024165627"></a>Multi-hop attempt. </p>
</td>
</tr>
<tr id="row161665610165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1240078220165627"><a name="p1240078220165627"></a><a name="p1240078220165627"></a><a href="UTILS.md#ga66443788a7b1b20f15ac1a67b106f20d">EDOTDOT</a>   73</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1058522353165627"><a name="p1058522353165627"></a><a name="p1058522353165627"></a>RFS-specific error. </p>
</td>
</tr>
<tr id="row1036483398165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1540182629165627"><a name="p1540182629165627"></a><a name="p1540182629165627"></a><a href="UTILS.md#ga251e9b536ed96ccb16aa28ca2d5bd656">EBADMSG</a>   74</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1488429560165627"><a name="p1488429560165627"></a><a name="p1488429560165627"></a>Non-data message. </p>
</td>
</tr>
<tr id="row1029526103165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1944401709165627"><a name="p1944401709165627"></a><a name="p1944401709165627"></a><a href="UTILS.md#ga888552a5e3c78b5883904cf5d55244ab">EOVERFLOW</a>   75</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2104371417165627"><a name="p2104371417165627"></a><a name="p2104371417165627"></a>Value too large to be represented by the defined data type. </p>
</td>
</tr>
<tr id="row2105831923165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1673928523165627"><a name="p1673928523165627"></a><a name="p1673928523165627"></a><a href="UTILS.md#gafb498fa12135b33c784f3dc4445ce30f">ENOTUNIQ</a>   76</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1539338414165627"><a name="p1539338414165627"></a><a name="p1539338414165627"></a>Name not unique on the network. </p>
</td>
</tr>
<tr id="row1580654551165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1992415225165627"><a name="p1992415225165627"></a><a name="p1992415225165627"></a><a href="UTILS.md#gae9284c9860c0064da7dd8cba12c1f90f">EBADFD</a>   77</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p505025698165627"><a name="p505025698165627"></a><a name="p505025698165627"></a>File descriptor in the bad state. </p>
</td>
</tr>
<tr id="row11832275165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2138402233165627"><a name="p2138402233165627"></a><a name="p2138402233165627"></a><a href="UTILS.md#gaa8fa21a58da5282010753ae1bed331af">EREMCHG</a>   78</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1112700958165627"><a name="p1112700958165627"></a><a name="p1112700958165627"></a>Remote address changed. </p>
</td>
</tr>
<tr id="row1086781771165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p417506193165627"><a name="p417506193165627"></a><a name="p417506193165627"></a><a href="UTILS.md#ga438fa452772ae90a9ccef5d3711bd752">ELIBACC</a>   79</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2023714811165627"><a name="p2023714811165627"></a><a name="p2023714811165627"></a>Cannot access a needed shared library. </p>
</td>
</tr>
<tr id="row403800600165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p964163710165627"><a name="p964163710165627"></a><a name="p964163710165627"></a><a href="UTILS.md#ga6c0c4ad172a62cde82900773c875e259">ELIBBAD</a>   80</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p820819394165627"><a name="p820819394165627"></a><a name="p820819394165627"></a>Accessing a corrupted shared library. </p>
</td>
</tr>
<tr id="row1748530339165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1541885368165627"><a name="p1541885368165627"></a><a name="p1541885368165627"></a><a href="UTILS.md#gaf208def3c8b59e39e6fe3d3d97d71a86">ELIBSCN</a>   81</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p636612289165627"><a name="p636612289165627"></a><a name="p636612289165627"></a>lib section in a.out corrupted </p>
</td>
</tr>
<tr id="row911129590165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p861993719165627"><a name="p861993719165627"></a><a name="p861993719165627"></a><a href="UTILS.md#gad2084b03b9e1c7467ab1b8bdbdfc2fe6">ELIBMAX</a>   82</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1356225407165627"><a name="p1356225407165627"></a><a name="p1356225407165627"></a>Attempting to link in too many shared libraries. </p>
</td>
</tr>
<tr id="row1610357995165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1418346884165627"><a name="p1418346884165627"></a><a name="p1418346884165627"></a><a href="UTILS.md#ga95774ff58533d1e67961890ed30f87b2">ELIBEXEC</a>   83</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p707509738165627"><a name="p707509738165627"></a><a name="p707509738165627"></a>Cannot execute a shared library directly. </p>
</td>
</tr>
<tr id="row814139251165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1973033040165627"><a name="p1973033040165627"></a><a name="p1973033040165627"></a><a href="UTILS.md#gac6c071293826a4e66a717bb38db7794d">EILSEQ</a>   84</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p997618327165627"><a name="p997618327165627"></a><a name="p997618327165627"></a>Invalid byte sequence. </p>
</td>
</tr>
<tr id="row613399822165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2101486525165627"><a name="p2101486525165627"></a><a name="p2101486525165627"></a><a href="UTILS.md#ga0e5993319c80d5a93ed10b6253878ae5">ERESTART</a>   85</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2028769867165627"><a name="p2028769867165627"></a><a name="p2028769867165627"></a>Interrupted system call should be restarted. </p>
</td>
</tr>
<tr id="row1952570834165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1419750414165627"><a name="p1419750414165627"></a><a name="p1419750414165627"></a><a href="UTILS.md#ga07773d22c3eb7a4d4ea0696ee5f49841">ESTRPIPE</a>   86</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1727165082165627"><a name="p1727165082165627"></a><a name="p1727165082165627"></a>Stream pipe error. </p>
</td>
</tr>
<tr id="row1303683284165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p216834601165627"><a name="p216834601165627"></a><a name="p216834601165627"></a><a href="UTILS.md#ga9b153104ed38c8579f009f81bc7b2dc9">EUSERS</a>   87</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p39730723165627"><a name="p39730723165627"></a><a name="p39730723165627"></a>Too many users. </p>
</td>
</tr>
<tr id="row623467303165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1975435517165627"><a name="p1975435517165627"></a><a name="p1975435517165627"></a><a href="UTILS.md#gae34fa7a550ac1c415daa2e114a1c0f38">ENOTSOCK</a>   88</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1824087355165627"><a name="p1824087355165627"></a><a name="p1824087355165627"></a>Not a socket. </p>
</td>
</tr>
<tr id="row117210620165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2001759071165627"><a name="p2001759071165627"></a><a name="p2001759071165627"></a><a href="UTILS.md#ga0e416d3478cf030e37e90c55d68ad97a">EDESTADDRREQ</a>   89</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1237113573165627"><a name="p1237113573165627"></a><a name="p1237113573165627"></a>Destination address required. </p>
</td>
</tr>
<tr id="row225674362165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1664762660165627"><a name="p1664762660165627"></a><a name="p1664762660165627"></a><a href="UTILS.md#gae37becfaa095a9df5c5c788bce5aa06f">EMSGSIZE</a>   90</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1285984153165627"><a name="p1285984153165627"></a><a name="p1285984153165627"></a>Message too long. </p>
</td>
</tr>
<tr id="row940179302165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1335070826165627"><a name="p1335070826165627"></a><a name="p1335070826165627"></a><a href="UTILS.md#gae6014faa948366b8321d755204acf755">EPROTOTYPE</a>   91</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p404928825165627"><a name="p404928825165627"></a><a name="p404928825165627"></a>Socket protocol error. </p>
</td>
</tr>
<tr id="row3190310165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p773927057165627"><a name="p773927057165627"></a><a name="p773927057165627"></a><a href="UTILS.md#gacd570f8ab92198653b4459773dc3bca3">ENOPROTOOPT</a>   92</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1403762180165627"><a name="p1403762180165627"></a><a name="p1403762180165627"></a>Protocol not available. </p>
</td>
</tr>
<tr id="row694631812165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p426761218165627"><a name="p426761218165627"></a><a name="p426761218165627"></a><a href="UTILS.md#gad581c46fdd4dee9419f60eaff40415e7">EPROTONOSUPPORT</a>   93</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1138882288165627"><a name="p1138882288165627"></a><a name="p1138882288165627"></a>Protocol not supported. </p>
</td>
</tr>
<tr id="row550134229165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p957794096165627"><a name="p957794096165627"></a><a name="p957794096165627"></a><a href="UTILS.md#ga891103a0628442461b41d4d85fb6d945">ESOCKTNOSUPPORT</a>   94</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1217941257165627"><a name="p1217941257165627"></a><a name="p1217941257165627"></a>Socket type not supported. </p>
</td>
</tr>
<tr id="row1853815163165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1757792111165627"><a name="p1757792111165627"></a><a name="p1757792111165627"></a><a href="UTILS.md#ga4b807895c74cea4d0302bf27725d4b9d">EOPNOTSUPP</a>   95</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1362277358165627"><a name="p1362277358165627"></a><a name="p1362277358165627"></a>Operation not supported on socket. </p>
</td>
</tr>
<tr id="row1686965594165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p712611295165627"><a name="p712611295165627"></a><a name="p712611295165627"></a><a href="UTILS.md#ga91457bbf35f0f1085619a99423bb1f33">ENOTSUP</a>   <a href="UTILS.md#ga4b807895c74cea4d0302bf27725d4b9d">EOPNOTSUPP</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p719913467165627"><a name="p719913467165627"></a><a name="p719913467165627"></a>Operation not supported on socket. The value is the same as that of <a href="UTILS.md#ga4b807895c74cea4d0302bf27725d4b9d">EOPNOTSUPP</a>. </p>
</td>
</tr>
<tr id="row1531442403165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1551238382165627"><a name="p1551238382165627"></a><a name="p1551238382165627"></a><a href="UTILS.md#ga871b9fabb281dbc2d3b81cb79c163c20">EPFNOSUPPORT</a>   96</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1707487014165627"><a name="p1707487014165627"></a><a name="p1707487014165627"></a>Protocol family not supported. </p>
</td>
</tr>
<tr id="row809371448165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1129838586165627"><a name="p1129838586165627"></a><a name="p1129838586165627"></a><a href="UTILS.md#ga4c3a793b4d51cb7dd020af92e536fe21">EAFNOSUPPORT</a>   97</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1109785930165627"><a name="p1109785930165627"></a><a name="p1109785930165627"></a>Address family not supported. </p>
</td>
</tr>
<tr id="row808726678165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1093358240165627"><a name="p1093358240165627"></a><a name="p1093358240165627"></a><a href="UTILS.md#ga61676e39b42371c65c3b960a91887b03">EADDRINUSE</a>   98</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p316448160165627"><a name="p316448160165627"></a><a name="p316448160165627"></a>Address already in use. </p>
</td>
</tr>
<tr id="row1647819459165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1863711112165627"><a name="p1863711112165627"></a><a name="p1863711112165627"></a><a href="UTILS.md#ga556612e55358838192165684c971a44f">EADDRNOTAVAIL</a>   99</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p462390590165627"><a name="p462390590165627"></a><a name="p462390590165627"></a>Address not available. </p>
</td>
</tr>
<tr id="row2123068322165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1135955389165627"><a name="p1135955389165627"></a><a name="p1135955389165627"></a><a href="UTILS.md#gaac51995026fa19cdd0ad84a272304af0">ENETDOWN</a>   100</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1267272526165627"><a name="p1267272526165627"></a><a name="p1267272526165627"></a>Network is down. </p>
</td>
</tr>
<tr id="row1880702706165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1468565409165627"><a name="p1468565409165627"></a><a name="p1468565409165627"></a><a href="UTILS.md#ga3f91f1ad503432783c7a5d1481b45419">ENETUNREACH</a>   101</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1174522821165627"><a name="p1174522821165627"></a><a name="p1174522821165627"></a>Network unreachable. </p>
</td>
</tr>
<tr id="row2063459975165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p606314350165627"><a name="p606314350165627"></a><a name="p606314350165627"></a><a href="UTILS.md#ga92750db73ff8e83591c977bbb3a5bea1">ENETRESET</a>   102</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p489427425165627"><a name="p489427425165627"></a><a name="p489427425165627"></a>Network disconnection caused by restart. </p>
</td>
</tr>
<tr id="row745952741165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1152152836165627"><a name="p1152152836165627"></a><a name="p1152152836165627"></a><a href="UTILS.md#ga45342991e001e28bbf87916d92b7e09a">ECONNABORTED</a>   103</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p243493697165627"><a name="p243493697165627"></a><a name="p243493697165627"></a>Network disconnection caused by software problems. </p>
</td>
</tr>
<tr id="row2122371131165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p266681262165627"><a name="p266681262165627"></a><a name="p266681262165627"></a><a href="UTILS.md#gadd4258b08af02fbe4590fbaae7260037">ECONNRESET</a>   104</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1567235660165627"><a name="p1567235660165627"></a><a name="p1567235660165627"></a>Connection reset. </p>
</td>
</tr>
<tr id="row1150776558165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p972789364165627"><a name="p972789364165627"></a><a name="p972789364165627"></a><a href="UTILS.md#ga9e655f47bfd914a1174f281fc31cf63d">ENOBUFS</a>   105</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1508438173165627"><a name="p1508438173165627"></a><a name="p1508438173165627"></a>No buffer space available. </p>
</td>
</tr>
<tr id="row1706391607165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2105023432165627"><a name="p2105023432165627"></a><a name="p2105023432165627"></a><a href="UTILS.md#ga164ca8549da7a385e2fe1cba823b9eaf">EISCONN</a>   106</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p130562809165627"><a name="p130562809165627"></a><a name="p130562809165627"></a>Socket is connected. </p>
</td>
</tr>
<tr id="row733426617165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1203691394165627"><a name="p1203691394165627"></a><a name="p1203691394165627"></a><a href="UTILS.md#gaf23e48762a0676f49d480db91cfd5e4b">ENOTCONN</a>   107</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p743714614165627"><a name="p743714614165627"></a><a name="p743714614165627"></a>Socket disconnected. </p>
</td>
</tr>
<tr id="row1203596130165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1949250829165627"><a name="p1949250829165627"></a><a name="p1949250829165627"></a><a href="UTILS.md#ga2a55c5dd8b54ff5aace6c274c6726d68">ESHUTDOWN</a>   108</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1677904419165627"><a name="p1677904419165627"></a><a name="p1677904419165627"></a>Cannot send after transport endpoint shutdown. </p>
</td>
</tr>
<tr id="row381231651165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p58192438165627"><a name="p58192438165627"></a><a name="p58192438165627"></a><a href="UTILS.md#ga10426080250efba47f4aaf254036ff00">ETOOMANYREFS</a>   109</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p305529357165627"><a name="p305529357165627"></a><a name="p305529357165627"></a>Cannot splice due to too many references. </p>
</td>
</tr>
<tr id="row228037024165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1895692039165627"><a name="p1895692039165627"></a><a name="p1895692039165627"></a><a href="UTILS.md#ga597718e59a8fc9c4d4ab63f5a34e28b1">ETIMEDOUT</a>   110</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p129097134165627"><a name="p129097134165627"></a><a name="p129097134165627"></a>Connection timed out. </p>
</td>
</tr>
<tr id="row1709257548165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p961270427165627"><a name="p961270427165627"></a><a name="p961270427165627"></a><a href="UTILS.md#gaad88020b394ef1aa4af2f4ef9b4c8b39">ECONNREFUSED</a>   111</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1287997526165627"><a name="p1287997526165627"></a><a name="p1287997526165627"></a>Connection refused. </p>
</td>
</tr>
<tr id="row330969219165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p470257247165627"><a name="p470257247165627"></a><a name="p470257247165627"></a><a href="UTILS.md#gaa92bcaf70544db6998f4c503026359c5">EHOSTDOWN</a>   112</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p966592825165627"><a name="p966592825165627"></a><a name="p966592825165627"></a>Host is down. </p>
</td>
</tr>
<tr id="row75916432165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1202777247165627"><a name="p1202777247165627"></a><a name="p1202777247165627"></a><a href="UTILS.md#ga53e186028fc992c3341ccb0d4d239b24">EHOSTUNREACH</a>   113</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p180191854165627"><a name="p180191854165627"></a><a name="p180191854165627"></a>Host is unreachable. </p>
</td>
</tr>
<tr id="row1065660497165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1676923267165627"><a name="p1676923267165627"></a><a name="p1676923267165627"></a><a href="UTILS.md#gaa4ccb54aa806de3e41a8515f06db85d4">EALREADY</a>   114</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p395234936165627"><a name="p395234936165627"></a><a name="p395234936165627"></a>Operation already in process. </p>
</td>
</tr>
<tr id="row914336951165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1443316905165627"><a name="p1443316905165627"></a><a name="p1443316905165627"></a><a href="UTILS.md#ga6c045d5be06e715cc335784a7320714e">EINPROGRESS</a>   115</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1428476792165627"><a name="p1428476792165627"></a><a name="p1428476792165627"></a>Operation in progress. </p>
</td>
</tr>
<tr id="row2046298793165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1008230176165627"><a name="p1008230176165627"></a><a name="p1008230176165627"></a><a href="UTILS.md#ga09e189d2214d9fe2847d27bf270ca1d7">ESTALE</a>   116</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2018696992165627"><a name="p2018696992165627"></a><a name="p2018696992165627"></a>Stale file handle. </p>
</td>
</tr>
<tr id="row1529842797165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1284927764165627"><a name="p1284927764165627"></a><a name="p1284927764165627"></a><a href="UTILS.md#ga909dbec1577dd4de42e3de940449d991">EUCLEAN</a>   117</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p805361450165627"><a name="p805361450165627"></a><a name="p805361450165627"></a>Structure needs cleaning. </p>
</td>
</tr>
<tr id="row753142219165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1561198282165627"><a name="p1561198282165627"></a><a name="p1561198282165627"></a><a href="UTILS.md#ga604c754d9cff19a3f842f263939744ed">ENOTNAM</a>   118</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1748159078165627"><a name="p1748159078165627"></a><a name="p1748159078165627"></a>Not a XENIX named type file. </p>
</td>
</tr>
<tr id="row701226671165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p642303076165627"><a name="p642303076165627"></a><a name="p642303076165627"></a><a href="UTILS.md#ga4df8882de9228023855dc31287c1728c">ENAVAIL</a>   119</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p882223507165627"><a name="p882223507165627"></a><a name="p882223507165627"></a>No XENIX semaphores available. </p>
</td>
</tr>
<tr id="row1199753368165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1336154801165627"><a name="p1336154801165627"></a><a name="p1336154801165627"></a><a href="UTILS.md#gab43dd11ce0541c2bc2bdbd36cbcbd6b7">EISNAM</a>   120</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1402632188165627"><a name="p1402632188165627"></a><a name="p1402632188165627"></a>Duplicate file name. </p>
</td>
</tr>
<tr id="row1068943752165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1753190542165627"><a name="p1753190542165627"></a><a name="p1753190542165627"></a><a href="UTILS.md#gaa206a5818e8b3666cd46274d71ab7c45">EREMOTEIO</a>   121</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p793989656165627"><a name="p793989656165627"></a><a name="p793989656165627"></a>Remote I/O error. </p>
</td>
</tr>
<tr id="row1912308881165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1565965030165627"><a name="p1565965030165627"></a><a name="p1565965030165627"></a><a href="UTILS.md#gaa5a48566b00cf9062d9deeeb0682cdaf">EDQUOT</a>   122</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p119859288165627"><a name="p119859288165627"></a><a name="p119859288165627"></a>Quota exceeded. </p>
</td>
</tr>
<tr id="row165391178165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p523328583165627"><a name="p523328583165627"></a><a name="p523328583165627"></a><a href="UTILS.md#ga434a80cd2a94a829078d50b61ebd277d">ENOMEDIUM</a>   123</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1507056589165627"><a name="p1507056589165627"></a><a name="p1507056589165627"></a>No medium found. </p>
</td>
</tr>
<tr id="row709234529165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p380104620165627"><a name="p380104620165627"></a><a name="p380104620165627"></a><a href="UTILS.md#ga3431fd1c9d585b39b0089ebc0b97450f">EMEDIUMTYPE</a>   124</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p802976546165627"><a name="p802976546165627"></a><a name="p802976546165627"></a>Wrong medium type. </p>
</td>
</tr>
<tr id="row1478205762165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2105492315165627"><a name="p2105492315165627"></a><a name="p2105492315165627"></a><a href="UTILS.md#ga9532d840ef91fd8e1ecc5d7ca7cbf212">ECANCELED</a>   125</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p236521291165627"><a name="p236521291165627"></a><a name="p236521291165627"></a>Operation canceled. </p>
</td>
</tr>
<tr id="row1639577980165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p921659027165627"><a name="p921659027165627"></a><a name="p921659027165627"></a><a href="UTILS.md#ga21e1aad43086cf76131101b31ca391cc">ENOKEY</a>   126</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1079052210165627"><a name="p1079052210165627"></a><a name="p1079052210165627"></a>Required key not available. </p>
</td>
</tr>
<tr id="row342716823165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p598031508165627"><a name="p598031508165627"></a><a name="p598031508165627"></a><a href="UTILS.md#gac1eb981061f0b7e10a3460b48490e1e2">EKEYEXPIRED</a>   127</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p672026044165627"><a name="p672026044165627"></a><a name="p672026044165627"></a>Key has expired. </p>
</td>
</tr>
<tr id="row1494686129165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p491136053165627"><a name="p491136053165627"></a><a name="p491136053165627"></a><a href="UTILS.md#ga4dc832fdf410d2f441ce364a7f6d768a">EKEYREVOKED</a>   128</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1299515869165627"><a name="p1299515869165627"></a><a name="p1299515869165627"></a>Key has been revoked. </p>
</td>
</tr>
<tr id="row2065451381165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p686661104165627"><a name="p686661104165627"></a><a name="p686661104165627"></a><a href="UTILS.md#gaddb68626b2a7ebc047c14180b51a5d95">EKEYREJECTED</a>   129</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1178676195165627"><a name="p1178676195165627"></a><a name="p1178676195165627"></a>Key was rejected by service. </p>
</td>
</tr>
<tr id="row800978938165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p833777668165627"><a name="p833777668165627"></a><a name="p833777668165627"></a><a href="UTILS.md#gaf3f021d87caf24b44761036578c7beae">EOWNERDEAD</a>   130</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p868048443165627"><a name="p868048443165627"></a><a name="p868048443165627"></a>Resource owner died. </p>
</td>
</tr>
<tr id="row1818660856165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1884048422165627"><a name="p1884048422165627"></a><a name="p1884048422165627"></a><a href="UTILS.md#gac69acb8e9e296867cc3f9fdf4223d05d">ENOTRECOVERABLE</a>   131</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p469077812165627"><a name="p469077812165627"></a><a name="p469077812165627"></a>State not recoverable. </p>
</td>
</tr>
<tr id="row1881978314165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1421116333165627"><a name="p1421116333165627"></a><a name="p1421116333165627"></a><a href="UTILS.md#ga1ef2e2afa19fd790ef00003c23fc90dd">ERFKILL</a>   132</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1478023353165627"><a name="p1478023353165627"></a><a name="p1478023353165627"></a>Operation not possible due to RF-kill. </p>
</td>
</tr>
<tr id="row1569187035165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1732545222165627"><a name="p1732545222165627"></a><a name="p1732545222165627"></a><a href="UTILS.md#ga7ac6735b364cb147c6ce8b887506a281">EHWPOISON</a>   133</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2022878546165627"><a name="p2022878546165627"></a><a name="p2022878546165627"></a>Hardware errors on the memory page. </p>
</td>
</tr>
</tbody>
</table>

