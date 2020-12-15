# unistd.h<a name="ZH-CN_TOPIC_0000001055387990"></a>

-   [Overview](#section263714719165629)
-   [Summary](#section1974795565165629)
-   [Macros](#define-members)
-   [Functions](#func-members)

## **Overview**<a name="section263714719165629"></a>

**Related Modules:**

[UTILS](UTILS.md)

**Description:**

Provides functions and data structures related to process operations. 

For example, you can use the functions to create and copy a process, and obtain a process ID.

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1974795565165629"></a>

## Macros<a name="define-members"></a>

<a name="table18548396165629"></a>
<table><thead align="left"><tr id="row127903125165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1387573554165629"><a name="p1387573554165629"></a><a name="p1387573554165629"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p831582874165629"><a name="p831582874165629"></a><a name="p831582874165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1900578717165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1450481784165629"><a name="p1450481784165629"></a><a name="p1450481784165629"></a><a href="UTILS.md#gafcf80a6d91178952d107ad00b165752b">STDIN_FILENO</a>   0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1380792355165629"><a name="p1380792355165629"></a><a name="p1380792355165629"></a>Descriptor ID of the standard input file. </p>
</td>
</tr>
<tr id="row1184729204165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p19319660165629"><a name="p19319660165629"></a><a name="p19319660165629"></a><a href="UTILS.md#gabd165ee6474b5b75bf075842fff13a04">STDOUT_FILENO</a>   1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1366789799165629"><a name="p1366789799165629"></a><a name="p1366789799165629"></a>Descriptor ID of the standard output file. </p>
</td>
</tr>
<tr id="row1822663813165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p179447839165629"><a name="p179447839165629"></a><a name="p179447839165629"></a><a href="UTILS.md#gae2fe1725bb5e9823d089c46b9ed5266e">STDERR_FILENO</a>   2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p190111979165629"><a name="p190111979165629"></a><a name="p190111979165629"></a>Descriptor ID of the standard error file. </p>
</td>
</tr>
<tr id="row260669642165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p893679901165629"><a name="p893679901165629"></a><a name="p893679901165629"></a><a href="UTILS.md#ga0d112bae8fd35be772185b6ec6bcbe64">SEEK_SET</a>   0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1311342110165629"><a name="p1311342110165629"></a><a name="p1311342110165629"></a>Relocation starts from the file header. </p>
</td>
</tr>
<tr id="row553413525165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p852963211165629"><a name="p852963211165629"></a><a name="p852963211165629"></a><a href="UTILS.md#ga4c8d0b76b470ba65a43ca46a88320f39">SEEK_CUR</a>   1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1258990845165629"><a name="p1258990845165629"></a><a name="p1258990845165629"></a>Relocation starts from the position of the currently accessed file. </p>
</td>
</tr>
<tr id="row563013128165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1146698197165629"><a name="p1146698197165629"></a><a name="p1146698197165629"></a><a href="UTILS.md#gad2a2e6c114780c3071efd24f16c7f7d8">SEEK_END</a>   2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p396268586165629"><a name="p396268586165629"></a><a name="p396268586165629"></a>Relocation starts from the end of the file. </p>
</td>
</tr>
<tr id="row1355013842165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1268587988165629"><a name="p1268587988165629"></a><a name="p1268587988165629"></a><a href="UTILS.md#ga070d2ce7b6bb7e5c05602aa8c308d0c4">NULL</a>   ((void*)0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1975050214165629"><a name="p1975050214165629"></a><a name="p1975050214165629"></a>NULL. </p>
</td>
</tr>
<tr id="row794946449165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p554315460165629"><a name="p554315460165629"></a><a name="p554315460165629"></a><a href="UTILS.md#gaf837744613408b57dc3654fbc3bcf900">F_OK</a>   0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p178370433165629"><a name="p178370433165629"></a><a name="p178370433165629"></a>Existing file. </p>
</td>
</tr>
<tr id="row177306419165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p810497992165629"><a name="p810497992165629"></a><a name="p810497992165629"></a><a href="UTILS.md#ga24a7a0ceb1e8f5f44cb1038bb829030d">R_OK</a>   4</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1781045152165629"><a name="p1781045152165629"></a><a name="p1781045152165629"></a>Readable file. </p>
</td>
</tr>
<tr id="row1143083874165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p947577976165629"><a name="p947577976165629"></a><a name="p947577976165629"></a><a href="UTILS.md#gae5acf4043c0903cda7436b108e29e8e6">W_OK</a>   2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1235960306165629"><a name="p1235960306165629"></a><a name="p1235960306165629"></a>Writable file. </p>
</td>
</tr>
<tr id="row904625262165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p240608942165629"><a name="p240608942165629"></a><a name="p240608942165629"></a><a href="UTILS.md#ga5e995ef7690698b62bf016b14fbc45ca">X_OK</a>   1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p986955367165629"><a name="p986955367165629"></a><a name="p986955367165629"></a>Executable file. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1726083599165629"></a>
<table><thead align="left"><tr id="row717432632165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1201739498165629"><a name="p1201739498165629"></a><a name="p1201739498165629"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1664923142165629"><a name="p1664923142165629"></a><a name="p1664923142165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1467582873165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1380164247165629"><a name="p1380164247165629"></a><a name="p1380164247165629"></a><a href="UTILS.md#ga3d8839f39526d15b100953d64cc08f10">pipe</a> (int pipefd[2])</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p190399880165629"><a name="p190399880165629"></a><a name="p190399880165629"></a>int </p>
<p id="p1324742059165629"><a name="p1324742059165629"></a><a name="p1324742059165629"></a>Creates an anonymous pipe. </p>
</td>
</tr>
<tr id="row279900771165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1848408019165629"><a name="p1848408019165629"></a><a name="p1848408019165629"></a><a href="UTILS.md#gaafbcde67669a1b96577e735ddebd8634">close</a> (int fd)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1730059519165629"><a name="p1730059519165629"></a><a name="p1730059519165629"></a>int </p>
<p id="p962324367165629"><a name="p962324367165629"></a><a name="p962324367165629"></a>Closes a file with a specified file descriptor. </p>
</td>
</tr>
<tr id="row1986424845165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p518472244165629"><a name="p518472244165629"></a><a name="p518472244165629"></a><a href="UTILS.md#ga2599c985f9cce0d9d7b11732941bd9dc">dup</a> (int oldfd)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p747103245165629"><a name="p747103245165629"></a><a name="p747103245165629"></a>int </p>
<p id="p1884486705165629"><a name="p1884486705165629"></a><a name="p1884486705165629"></a>Copies a specified file descriptor. </p>
</td>
</tr>
<tr id="row1298566067165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1973377895165629"><a name="p1973377895165629"></a><a name="p1973377895165629"></a><a href="UTILS.md#ga0bbddf8ae4f3dea6e57532be36c04268">dup2</a> (int oldfd, int newfd)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1972506835165629"><a name="p1972506835165629"></a><a name="p1972506835165629"></a>int </p>
<p id="p204166647165629"><a name="p204166647165629"></a><a name="p204166647165629"></a>Copies the descriptor of the target file to a specified descriptor. </p>
</td>
</tr>
<tr id="row1563041773165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1572633098165629"><a name="p1572633098165629"></a><a name="p1572633098165629"></a><a href="UTILS.md#ga8bd74caed008a66808d92d57fa74d9f6">lseek</a> (int fd, off_t offset, int whence)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2141039839165629"><a name="p2141039839165629"></a><a name="p2141039839165629"></a>off_t </p>
<p id="p819751767165629"><a name="p819751767165629"></a><a name="p819751767165629"></a>Sets the offset of the pointer to the file. </p>
</td>
</tr>
<tr id="row125705792165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1425403022165629"><a name="p1425403022165629"></a><a name="p1425403022165629"></a><a href="UTILS.md#ga9ba34c4ff72e21db486eedf77c2a18d0">fsync</a> (int fd)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p33841528165629"><a name="p33841528165629"></a><a name="p33841528165629"></a>int </p>
<p id="p1773932143165629"><a name="p1773932143165629"></a><a name="p1773932143165629"></a>Synchronizes a file associated with a specified file descriptor to the storage device. </p>
</td>
</tr>
<tr id="row1394466990165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p520314335165629"><a name="p520314335165629"></a><a name="p520314335165629"></a><a href="UTILS.md#ga5975018bea8d2811c4b3abe10d493bb6">read</a> (int fd, void *buf, size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1234729841165629"><a name="p1234729841165629"></a><a name="p1234729841165629"></a>ssize_t </p>
<p id="p333002397165629"><a name="p333002397165629"></a><a name="p333002397165629"></a>Reads the file contents and saves them in a specified buffer location. </p>
</td>
</tr>
<tr id="row579137659165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p238901375165629"><a name="p238901375165629"></a><a name="p238901375165629"></a><a href="UTILS.md#gac06af22e9ce132f563db5c918ceb1eb1">write</a> (int fd, const void *buf, size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p156230301165629"><a name="p156230301165629"></a><a name="p156230301165629"></a>ssize_t </p>
<p id="p718599128165629"><a name="p718599128165629"></a><a name="p718599128165629"></a>Writes the specified content to the file. </p>
</td>
</tr>
<tr id="row2057100797165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1170092997165629"><a name="p1170092997165629"></a><a name="p1170092997165629"></a><a href="UTILS.md#ga67ceebb141dbf6be0be4484804601e5b">pread</a> (int fd, void *buf, size_t count, off_t offset)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p782204131165629"><a name="p782204131165629"></a><a name="p782204131165629"></a>ssize_t </p>
<p id="p1030512675165629"><a name="p1030512675165629"></a><a name="p1030512675165629"></a>Reads data whose offset is <strong id="b1227492552165629"><a name="b1227492552165629"></a><a name="b1227492552165629"></a>offset</strong> and length is <strong id="b668330105165629"><a name="b668330105165629"></a><a name="b668330105165629"></a>count</strong> from <strong id="b2013411014165629"><a name="b2013411014165629"></a><a name="b2013411014165629"></a>fd</strong> to the buffer. </p>
</td>
</tr>
<tr id="row852938494165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1333782253165629"><a name="p1333782253165629"></a><a name="p1333782253165629"></a><a href="UTILS.md#ga6583cb37d551c2553bbb5e7df6c145be">pwrite</a> (int fd, const void *buf, size_t count, off_t offset)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p383800795165629"><a name="p383800795165629"></a><a name="p383800795165629"></a>ssize_t </p>
<p id="p1388478481165629"><a name="p1388478481165629"></a><a name="p1388478481165629"></a>Writes data from the buffer to <strong id="b1440872467165629"><a name="b1440872467165629"></a><a name="b1440872467165629"></a>fd</strong> whose offset is <strong id="b1959506641165629"><a name="b1959506641165629"></a><a name="b1959506641165629"></a>offset</strong> and length is <strong id="b1320056484165629"><a name="b1320056484165629"></a><a name="b1320056484165629"></a>count</strong>. </p>
</td>
</tr>
<tr id="row275296247165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p451392499165629"><a name="p451392499165629"></a><a name="p451392499165629"></a><a href="UTILS.md#ga28af9471bbdf262321af663e02899a47">unlink</a> (const char *path)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p310274714165629"><a name="p310274714165629"></a><a name="p310274714165629"></a>int </p>
<p id="p1865725440165629"><a name="p1865725440165629"></a><a name="p1865725440165629"></a>Deletes a specified file. </p>
</td>
</tr>
<tr id="row1388717880165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p467969139165629"><a name="p467969139165629"></a><a name="p467969139165629"></a><a href="UTILS.md#gaa06a637e291f5d288cae85ce32a2fe49">unlinkat</a> (int fd, const char *path, int flag)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p986622320165629"><a name="p986622320165629"></a><a name="p986622320165629"></a>int </p>
<p id="p2112412101165629"><a name="p2112412101165629"></a><a name="p2112412101165629"></a>Deletes a specified file. </p>
</td>
</tr>
<tr id="row548825913165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1821912972165629"><a name="p1821912972165629"></a><a name="p1821912972165629"></a><a href="UTILS.md#gab2df76f2c62ae012c2e417813b5fe8ce">rmdir</a> (const char *path)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p255311309165629"><a name="p255311309165629"></a><a name="p255311309165629"></a>int </p>
<p id="p168049647165629"><a name="p168049647165629"></a><a name="p168049647165629"></a>Deletes a directory. </p>
</td>
</tr>
<tr id="row8207231165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p35103165629"><a name="p35103165629"></a><a name="p35103165629"></a><a href="UTILS.md#ga87674838dd2bcf61e1a1fb5c9892ab6c">truncate</a> (const char *path, off_t length)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p585111236165629"><a name="p585111236165629"></a><a name="p585111236165629"></a>int </p>
<p id="p1625339246165629"><a name="p1625339246165629"></a><a name="p1625339246165629"></a>Truncates a file to a specified size based on the file path. </p>
</td>
</tr>
<tr id="row273040134165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p708926682165629"><a name="p708926682165629"></a><a name="p708926682165629"></a><a href="UTILS.md#ga0fb7c60877eacbfbd66eff04533ab0fe">ftruncate</a> (int fd, off_t length)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1485034368165629"><a name="p1485034368165629"></a><a name="p1485034368165629"></a>int </p>
<p id="p2102266569165629"><a name="p2102266569165629"></a><a name="p2102266569165629"></a>Truncates a file to a specified length. </p>
</td>
</tr>
<tr id="row643697575165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p511737257165629"><a name="p511737257165629"></a><a name="p511737257165629"></a><a href="UTILS.md#gaeff22ad09b35eda92f6c5632300b05da">access</a> (const char *path, int mode)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1136505588165629"><a name="p1136505588165629"></a><a name="p1136505588165629"></a>int </p>
<p id="p1365968773165629"><a name="p1365968773165629"></a><a name="p1365968773165629"></a>Checks whether a file has the corresponding permission. </p>
</td>
</tr>
<tr id="row2144035668165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2037279122165629"><a name="p2037279122165629"></a><a name="p2037279122165629"></a><a href="UTILS.md#ga03af571dfb595681bfa203c83385c07b">chdir</a> (const char *path)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1810297138165629"><a name="p1810297138165629"></a><a name="p1810297138165629"></a>int </p>
<p id="p1377976714165629"><a name="p1377976714165629"></a><a name="p1377976714165629"></a>Switches the current working directory to a specified directory. </p>
</td>
</tr>
<tr id="row282589993165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p978099828165629"><a name="p978099828165629"></a><a name="p978099828165629"></a><a href="UTILS.md#ga3284211bd28346254245c9d4fd071d7f">getcwd</a> (char *buf, size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1018933067165629"><a name="p1018933067165629"></a><a name="p1018933067165629"></a>char * </p>
<p id="p383627067165629"><a name="p383627067165629"></a><a name="p383627067165629"></a>Obtains the current working directory. </p>
</td>
</tr>
<tr id="row1584047864165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1549807419165629"><a name="p1549807419165629"></a><a name="p1549807419165629"></a><a href="UTILS.md#ga8c476685d78ea93ee343f8a0580c79fe">alarm</a> (unsigned int seconds)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1862564860165629"><a name="p1862564860165629"></a><a name="p1862564860165629"></a>unsigned int </p>
<p id="p725621476165629"><a name="p725621476165629"></a><a name="p725621476165629"></a>Arranges a signal to be sent to the current process after the number of seconds specified by <strong id="b896660388165629"><a name="b896660388165629"></a><a name="b896660388165629"></a>seconds</strong>. </p>
</td>
</tr>
<tr id="row112711180165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1747927028165629"><a name="p1747927028165629"></a><a name="p1747927028165629"></a><a href="UTILS.md#gad4669b3813c3b4a616a738317fdc974f">sleep</a> (unsigned seconds)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2088716315165629"><a name="p2088716315165629"></a><a name="p2088716315165629"></a>unsigned </p>
<p id="p848136871165629"><a name="p848136871165629"></a><a name="p848136871165629"></a>Sleeps for a period of time. </p>
</td>
</tr>
<tr id="row815363661165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p41102954165629"><a name="p41102954165629"></a><a name="p41102954165629"></a><a href="UTILS.md#ga47a6ff5872f457ee230458137f2b2409">pause</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1335333385165629"><a name="p1335333385165629"></a><a name="p1335333385165629"></a>int </p>
<p id="p1541104795165629"><a name="p1541104795165629"></a><a name="p1541104795165629"></a>Waits for signal. </p>
</td>
</tr>
<tr id="row1845371633165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1102947664165629"><a name="p1102947664165629"></a><a name="p1102947664165629"></a><a href="UTILS.md#gaa4e4714e6e8927c80b2553a40094b6d9">fork</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p793439178165629"><a name="p793439178165629"></a><a name="p793439178165629"></a><a href="UTILS.md#ga30c34d3eead853c44f459f21b932984c">pid_t</a> </p>
<p id="p1368870364165629"><a name="p1368870364165629"></a><a name="p1368870364165629"></a>Creates a new process that inherits from the user-mode data of its parent process. </p>
</td>
</tr>
<tr id="row207998376165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p298235754165629"><a name="p298235754165629"></a><a name="p298235754165629"></a><a href="UTILS.md#ga99ca2b673a47850c541b215ddfd6b23e">execve</a> (const char *path, char *const arg[], char *const envp[])</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p580978897165629"><a name="p580978897165629"></a><a name="p580978897165629"></a>int </p>
<p id="p1253311826165629"><a name="p1253311826165629"></a><a name="p1253311826165629"></a>Executes a specified user program file in ELF format. </p>
</td>
</tr>
<tr id="row716890096165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p733481221165629"><a name="p733481221165629"></a><a name="p733481221165629"></a><a href="UTILS.md#gadb609bbc5b9255bf715138cda88857b0">execv</a> (const char *path, char *const arg[])</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p155528128165629"><a name="p155528128165629"></a><a name="p155528128165629"></a>int </p>
<p id="p2049683848165629"><a name="p2049683848165629"></a><a name="p2049683848165629"></a>Executes a specified user program file in ELF format. </p>
</td>
</tr>
<tr id="row20344131165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p954431167165629"><a name="p954431167165629"></a><a name="p954431167165629"></a><a href="UTILS.md#ga2c2701379e4144b3105aa83c82363aa3">execle</a> (const char *path, const char *arg,...)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1523861140165629"><a name="p1523861140165629"></a><a name="p1523861140165629"></a>int </p>
<p id="p952198925165629"><a name="p952198925165629"></a><a name="p952198925165629"></a>Executes a specified user program file in ELF format. </p>
</td>
</tr>
<tr id="row1392486403165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p220015639165629"><a name="p220015639165629"></a><a name="p220015639165629"></a><a href="UTILS.md#ga1ade18bb3b763fbcefc507c770dc7e7e">execl</a> (const char *path, const char *arg,...)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1829672379165629"><a name="p1829672379165629"></a><a name="p1829672379165629"></a>int </p>
<p id="p556634725165629"><a name="p556634725165629"></a><a name="p556634725165629"></a>Executes a specified user program file in ELF format. </p>
</td>
</tr>
<tr id="row1286409588165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p477584362165629"><a name="p477584362165629"></a><a name="p477584362165629"></a><a href="UTILS.md#ga1bbb0ecd56c097ca82587115b4dfd540">execvp</a> (const char *path, char *const arg[])</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1856462730165629"><a name="p1856462730165629"></a><a name="p1856462730165629"></a>int </p>
<p id="p1672280536165629"><a name="p1672280536165629"></a><a name="p1672280536165629"></a>Executes a specified user program file in ELF format. </p>
</td>
</tr>
<tr id="row937556381165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1773197358165629"><a name="p1773197358165629"></a><a name="p1773197358165629"></a><a href="UTILS.md#ga4dd268acb7fc54f403ab6cb56b7ffd3f">execlp</a> (const char *path, const char *arg,...)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p400213153165629"><a name="p400213153165629"></a><a name="p400213153165629"></a>int </p>
<p id="p784739381165629"><a name="p784739381165629"></a><a name="p784739381165629"></a>Executes a specified user program file in ELF format. </p>
</td>
</tr>
<tr id="row943747406165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p498820669165629"><a name="p498820669165629"></a><a name="p498820669165629"></a><a href="UTILS.md#gaee2ffcdf92b92a337c592a7ef9174769">_exit</a> (int status)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1398359844165629"><a name="p1398359844165629"></a><a name="p1398359844165629"></a>_Noreturn void </p>
<p id="p1664491341165629"><a name="p1664491341165629"></a><a name="p1664491341165629"></a>Exits the process immediately and closes all opened file descriptors in the process. </p>
</td>
</tr>
<tr id="row2032507383165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1567123887165629"><a name="p1567123887165629"></a><a name="p1567123887165629"></a><a href="UTILS.md#ga27ee6e902becdb181addb45b69a50b8c">swab</a> (const void *from, void *to, ssize_t n)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1369474865165629"><a name="p1369474865165629"></a><a name="p1369474865165629"></a>void </p>
<p id="p236487812165629"><a name="p236487812165629"></a><a name="p236487812165629"></a>Swaps bytes. </p>
</td>
</tr>
<tr id="row457612733165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p556991343165629"><a name="p556991343165629"></a><a name="p556991343165629"></a><a href="UTILS.md#gac61b207337ca21b3b309593fd1a0cb82">getpid</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2103267394165629"><a name="p2103267394165629"></a><a name="p2103267394165629"></a><a href="UTILS.md#ga30c34d3eead853c44f459f21b932984c">pid_t</a> </p>
<p id="p1139972558165629"><a name="p1139972558165629"></a><a name="p1139972558165629"></a>Obtains the process ID. </p>
</td>
</tr>
<tr id="row94919125165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1453297910165629"><a name="p1453297910165629"></a><a name="p1453297910165629"></a><a href="UTILS.md#gac6d7f7ade00dcdc302b0da5664eee812">getppid</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1492027887165629"><a name="p1492027887165629"></a><a name="p1492027887165629"></a><a href="UTILS.md#ga30c34d3eead853c44f459f21b932984c">pid_t</a> </p>
<p id="p1854681346165629"><a name="p1854681346165629"></a><a name="p1854681346165629"></a>Obtains the parent process ID. </p>
</td>
</tr>
<tr id="row1152456704165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p45676118165629"><a name="p45676118165629"></a><a name="p45676118165629"></a><a href="UTILS.md#ga06f4ba65249f92cacdba5782a8d70eba">getpgrp</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p183054410165629"><a name="p183054410165629"></a><a name="p183054410165629"></a><a href="UTILS.md#ga30c34d3eead853c44f459f21b932984c">pid_t</a> </p>
<p id="p1430496729165629"><a name="p1430496729165629"></a><a name="p1430496729165629"></a>Obtains the ID of the process group of the calling process. </p>
</td>
</tr>
<tr id="row795371020165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p738998578165629"><a name="p738998578165629"></a><a name="p738998578165629"></a><a href="UTILS.md#ga48f523c98970793dfc2c5a05f6832006">getpgid</a> (<a href="UTILS.md#ga30c34d3eead853c44f459f21b932984c">pid_t</a> pid)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p326187057165629"><a name="p326187057165629"></a><a name="p326187057165629"></a><a href="UTILS.md#ga30c34d3eead853c44f459f21b932984c">pid_t</a> </p>
<p id="p590156657165629"><a name="p590156657165629"></a><a name="p590156657165629"></a>Obtains the ID of the process group whose process ID is specified by <strong id="b729472111165629"><a name="b729472111165629"></a><a name="b729472111165629"></a>pid</strong>. </p>
</td>
</tr>
<tr id="row2061968036165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2051174491165629"><a name="p2051174491165629"></a><a name="p2051174491165629"></a><a href="UTILS.md#gae5aae5b0275eefe79314a4673195e475">setpgid</a> (<a href="UTILS.md#ga30c34d3eead853c44f459f21b932984c">pid_t</a> pid, <a href="UTILS.md#ga30c34d3eead853c44f459f21b932984c">pid_t</a> pgid)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p301204489165629"><a name="p301204489165629"></a><a name="p301204489165629"></a>int </p>
<p id="p554534912165629"><a name="p554534912165629"></a><a name="p554534912165629"></a>Sets the ID of the process group whose process ID is specified by <strong id="b569121904165629"><a name="b569121904165629"></a><a name="b569121904165629"></a>pid</strong>. </p>
</td>
</tr>
<tr id="row153057905165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p162113567165629"><a name="p162113567165629"></a><a name="p162113567165629"></a><a href="UTILS.md#ga5ffa4c677fc71cecd94f140ef9db624c">getopt</a> (int argc, char *const argv[], const char *optstring)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p6632642165629"><a name="p6632642165629"></a><a name="p6632642165629"></a>int </p>
<p id="p1602084812165629"><a name="p1602084812165629"></a><a name="p1602084812165629"></a>Parses command-line arguments based on the specified option. </p>
</td>
</tr>
<tr id="row1899421570165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p317922395165629"><a name="p317922395165629"></a><a name="p317922395165629"></a><a href="UTILS.md#ga2f517436c22ef73337d3de4920908c6c">getuid</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p185409182165629"><a name="p185409182165629"></a><a name="p185409182165629"></a><a href="UTILS.md#ga66a6f1a27d4474144d59fb2b805ff50e">uid_t</a> </p>
<p id="p1422814633165629"><a name="p1422814633165629"></a><a name="p1422814633165629"></a>Obtains the real user ID (UID) of the calling process. </p>
</td>
</tr>
<tr id="row1287931910165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2145455433165629"><a name="p2145455433165629"></a><a name="p2145455433165629"></a><a href="UTILS.md#ga8b9a6dcf4e1d237f5607256dad93e26a">geteuid</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1402160971165629"><a name="p1402160971165629"></a><a name="p1402160971165629"></a><a href="UTILS.md#ga66a6f1a27d4474144d59fb2b805ff50e">uid_t</a> </p>
<p id="p852566823165629"><a name="p852566823165629"></a><a name="p852566823165629"></a>Obtains the effective user ID (UID) of the calling process. </p>
</td>
</tr>
<tr id="row153115733165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1162166956165629"><a name="p1162166956165629"></a><a name="p1162166956165629"></a><a href="UTILS.md#ga58ca281cc6931c62e6a85e2edb5b4b49">getgid</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p810327929165629"><a name="p810327929165629"></a><a name="p810327929165629"></a><a href="UTILS.md#ga7ba7f6123ac8905fbe36f596bea2437e">gid_t</a> </p>
<p id="p1087929721165629"><a name="p1087929721165629"></a><a name="p1087929721165629"></a>Obtains the real group ID (GID) of the calling process. </p>
</td>
</tr>
<tr id="row1505175575165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p311094661165629"><a name="p311094661165629"></a><a name="p311094661165629"></a><a href="UTILS.md#ga3e7c694d68b4e62c1f275612d30b6d9d">getegid</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1755754251165629"><a name="p1755754251165629"></a><a name="p1755754251165629"></a><a href="UTILS.md#ga7ba7f6123ac8905fbe36f596bea2437e">gid_t</a> </p>
<p id="p1039277279165629"><a name="p1039277279165629"></a><a name="p1039277279165629"></a>Obtains the effective group ID (GID) of the calling process. </p>
</td>
</tr>
<tr id="row1587628284165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p441011345165629"><a name="p441011345165629"></a><a name="p441011345165629"></a><a href="UTILS.md#gaacfa67f2aef6be4baceace6a00856d21">getgroups</a> (int size, <a href="UTILS.md#ga7ba7f6123ac8905fbe36f596bea2437e">gid_t</a> list[])</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p796145038165629"><a name="p796145038165629"></a><a name="p796145038165629"></a>int </p>
<p id="p1309813127165629"><a name="p1309813127165629"></a><a name="p1309813127165629"></a>Obtains a list of supplementary user group IDs specific to the calling process. </p>
</td>
</tr>
<tr id="row1562948142165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1830265597165629"><a name="p1830265597165629"></a><a name="p1830265597165629"></a><a href="UTILS.md#gaa426fc963bb0a4f469eef61d9f0c4a26">setuid</a> (<a href="UTILS.md#ga66a6f1a27d4474144d59fb2b805ff50e">uid_t</a> uid)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1140535409165629"><a name="p1140535409165629"></a><a name="p1140535409165629"></a>int </p>
<p id="p482930805165629"><a name="p482930805165629"></a><a name="p482930805165629"></a>Sets the real user ID for the calling process. </p>
</td>
</tr>
<tr id="row840311787165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1730074343165629"><a name="p1730074343165629"></a><a name="p1730074343165629"></a><a href="UTILS.md#ga1f3f88da554f543f01a02a06c79c7bdd">seteuid</a> (<a href="UTILS.md#ga66a6f1a27d4474144d59fb2b805ff50e">uid_t</a> euid)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p870633570165629"><a name="p870633570165629"></a><a name="p870633570165629"></a>int </p>
<p id="p371587088165629"><a name="p371587088165629"></a><a name="p371587088165629"></a>Sets the effective user ID of the calling process. </p>
</td>
</tr>
<tr id="row631077036165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1479868699165629"><a name="p1479868699165629"></a><a name="p1479868699165629"></a><a href="UTILS.md#ga3116233500c2c34795d437eaf34b69b5">setgid</a> (<a href="UTILS.md#ga7ba7f6123ac8905fbe36f596bea2437e">gid_t</a> gid)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1723403156165629"><a name="p1723403156165629"></a><a name="p1723403156165629"></a>int </p>
<p id="p2137925139165629"><a name="p2137925139165629"></a><a name="p2137925139165629"></a>Sets the user group ID of the calling process. </p>
</td>
</tr>
<tr id="row473814209165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1404078970165629"><a name="p1404078970165629"></a><a name="p1404078970165629"></a><a href="UTILS.md#ga201d5dad2108506c5db5ba8d126ffbb2">setegid</a> (<a href="UTILS.md#ga7ba7f6123ac8905fbe36f596bea2437e">gid_t</a> egid)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p612868177165629"><a name="p612868177165629"></a><a name="p612868177165629"></a>int </p>
<p id="p1331044624165629"><a name="p1331044624165629"></a><a name="p1331044624165629"></a>Sets the effective user group ID of the calling process. </p>
</td>
</tr>
<tr id="row818033083165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p864012133165629"><a name="p864012133165629"></a><a name="p864012133165629"></a><a href="UTILS.md#gaa4ea4bbebf4841965159e66b5d1a49e8">pathconf</a> (const char *path, int name)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1090270179165629"><a name="p1090270179165629"></a><a name="p1090270179165629"></a>long </p>
<p id="p1955470743165629"><a name="p1955470743165629"></a><a name="p1955470743165629"></a>Obtains the configuration value of a file. </p>
</td>
</tr>
<tr id="row1128171965165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p873943307165629"><a name="p873943307165629"></a><a name="p873943307165629"></a><a href="UTILS.md#ga0c1be1c8a11bac9cdf41613e996c841b">setreuid</a> (<a href="UTILS.md#ga66a6f1a27d4474144d59fb2b805ff50e">uid_t</a> ruid, <a href="UTILS.md#ga66a6f1a27d4474144d59fb2b805ff50e">uid_t</a> euid)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p663201599165629"><a name="p663201599165629"></a><a name="p663201599165629"></a>int </p>
<p id="p734737731165629"><a name="p734737731165629"></a><a name="p734737731165629"></a>Sets the real and effective user IDs of the calling process. </p>
</td>
</tr>
<tr id="row489442906165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1978329352165629"><a name="p1978329352165629"></a><a name="p1978329352165629"></a><a href="UTILS.md#ga869d651a498782b6f3625e2bdbc439d6">setregid</a> (<a href="UTILS.md#ga7ba7f6123ac8905fbe36f596bea2437e">gid_t</a> rgid, <a href="UTILS.md#ga7ba7f6123ac8905fbe36f596bea2437e">gid_t</a> egid)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p663884859165629"><a name="p663884859165629"></a><a name="p663884859165629"></a>int </p>
<p id="p1425713938165629"><a name="p1425713938165629"></a><a name="p1425713938165629"></a>Sets the real and effective user group IDs of the calling process. </p>
</td>
</tr>
<tr id="row408776040165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2069547508165629"><a name="p2069547508165629"></a><a name="p2069547508165629"></a><a href="UTILS.md#gada2b1e6782cd8fc506fde243f7d313ec">setpgrp</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p915543993165629"><a name="p915543993165629"></a><a name="p915543993165629"></a><a href="UTILS.md#ga30c34d3eead853c44f459f21b932984c">pid_t</a> </p>
<p id="p1706005638165629"><a name="p1706005638165629"></a><a name="p1706005638165629"></a>Sets the process group ID of the calling process. </p>
</td>
</tr>
<tr id="row522438511165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1979967507165629"><a name="p1979967507165629"></a><a name="p1979967507165629"></a><a href="UTILS.md#ga608e849b00b0ac57524b26f45d408a55">usleep</a> (unsigned useconds)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1071049894165629"><a name="p1071049894165629"></a><a name="p1071049894165629"></a>int </p>
<p id="p1313585908165629"><a name="p1313585908165629"></a><a name="p1313585908165629"></a>Sleeps for several microseconds. </p>
</td>
</tr>
<tr id="row302674490165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1540468715165629"><a name="p1540468715165629"></a><a name="p1540468715165629"></a><a href="UTILS.md#ga9d35348d3389a721ab5aef5f4f036c61">ualarm</a> (unsigned value, unsigned interval)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1019703085165629"><a name="p1019703085165629"></a><a name="p1019703085165629"></a>unsigned </p>
<p id="p1029393446165629"><a name="p1029393446165629"></a><a name="p1029393446165629"></a>Sets a microsecond-level timer. </p>
</td>
</tr>
<tr id="row1680123240165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p876127274165629"><a name="p876127274165629"></a><a name="p876127274165629"></a><a href="UTILS.md#gaf7df624933ff8690b60c537a29659718">setgroups</a> (size_t size, const <a href="UTILS.md#ga7ba7f6123ac8905fbe36f596bea2437e">gid_t</a> *list)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1936796985165629"><a name="p1936796985165629"></a><a name="p1936796985165629"></a>int </p>
<p id="p1403281605165629"><a name="p1403281605165629"></a><a name="p1403281605165629"></a>Sets the supplementary user group list of the calling process. </p>
</td>
</tr>
<tr id="row808151618165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p317266919165629"><a name="p317266919165629"></a><a name="p317266919165629"></a><a href="UTILS.md#gac3827ffb6833b1e282fc2ea856d534a1">setresuid</a> (<a href="UTILS.md#ga66a6f1a27d4474144d59fb2b805ff50e">uid_t</a> ruid, <a href="UTILS.md#ga66a6f1a27d4474144d59fb2b805ff50e">uid_t</a> euid, <a href="UTILS.md#ga66a6f1a27d4474144d59fb2b805ff50e">uid_t</a> suid)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p261327581165629"><a name="p261327581165629"></a><a name="p261327581165629"></a>int </p>
<p id="p1796390516165629"><a name="p1796390516165629"></a><a name="p1796390516165629"></a>Sets the real, effective, and saved user IDs of the calling process. </p>
</td>
</tr>
<tr id="row382310243165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1129723053165629"><a name="p1129723053165629"></a><a name="p1129723053165629"></a><a href="UTILS.md#gabb0ec1f467235bee75ee359400d817e4">setresgid</a> (<a href="UTILS.md#ga7ba7f6123ac8905fbe36f596bea2437e">gid_t</a> rgid, <a href="UTILS.md#ga7ba7f6123ac8905fbe36f596bea2437e">gid_t</a> egid, <a href="UTILS.md#ga7ba7f6123ac8905fbe36f596bea2437e">gid_t</a> sgid)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p473177640165629"><a name="p473177640165629"></a><a name="p473177640165629"></a>int </p>
<p id="p903681435165629"><a name="p903681435165629"></a><a name="p903681435165629"></a>Sets the real, effective, and saved group IDs of the calling process. </p>
</td>
</tr>
<tr id="row1033722020165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1339143747165629"><a name="p1339143747165629"></a><a name="p1339143747165629"></a><a href="UTILS.md#ga4e92f1f4fb48c6fa8cd15d328950bc68">getresuid</a> (<a href="UTILS.md#ga66a6f1a27d4474144d59fb2b805ff50e">uid_t</a> *ruid, <a href="UTILS.md#ga66a6f1a27d4474144d59fb2b805ff50e">uid_t</a> *euid, <a href="UTILS.md#ga66a6f1a27d4474144d59fb2b805ff50e">uid_t</a> *suid)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p882512639165629"><a name="p882512639165629"></a><a name="p882512639165629"></a>int </p>
<p id="p1736027589165629"><a name="p1736027589165629"></a><a name="p1736027589165629"></a>Obtains the real, effective, and saved user IDs of the calling process. </p>
</td>
</tr>
<tr id="row1323166351165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1347069378165629"><a name="p1347069378165629"></a><a name="p1347069378165629"></a><a href="UTILS.md#gaf74b37e12b6a9418c094479721e8cbf0">getresgid</a> (<a href="UTILS.md#ga7ba7f6123ac8905fbe36f596bea2437e">gid_t</a> *rgid, <a href="UTILS.md#ga7ba7f6123ac8905fbe36f596bea2437e">gid_t</a> *egid, <a href="UTILS.md#ga7ba7f6123ac8905fbe36f596bea2437e">gid_t</a> *sgid)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2072034242165629"><a name="p2072034242165629"></a><a name="p2072034242165629"></a>int </p>
<p id="p107881273165629"><a name="p107881273165629"></a><a name="p107881273165629"></a>Obtains the real, effective, and saved user group IDs of the calling process. </p>
</td>
</tr>
<tr id="row645887416165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1118431128165629"><a name="p1118431128165629"></a><a name="p1118431128165629"></a><a href="UTILS.md#gaa0cf2e9b2a054c6ea46db972840fbc51">get_current_dir_name</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1333938831165629"><a name="p1333938831165629"></a><a name="p1333938831165629"></a>char * </p>
<p id="p1940018747165629"><a name="p1940018747165629"></a><a name="p1940018747165629"></a>Obtains the name of the current working directory. </p>
</td>
</tr>
<tr id="row2069834650165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1474681029165629"><a name="p1474681029165629"></a><a name="p1474681029165629"></a><a href="UTILS.md#ga3b818446c640442e94e746319f5f2858">sbrk</a> (intptr_t increment)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p78276748165629"><a name="p78276748165629"></a><a name="p78276748165629"></a>void * </p>
<p id="p982308547165629"><a name="p982308547165629"></a><a name="p982308547165629"></a>Adjusts the heap size of a process. </p>
</td>
</tr>
<tr id="row1437066753165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2023633429165629"><a name="p2023633429165629"></a><a name="p2023633429165629"></a><a href="UTILS.md#ga638757347bd9bf886b3d442b98033cf1">getpagesize</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p561102071165629"><a name="p561102071165629"></a><a name="p561102071165629"></a>int </p>
<p id="p926584456165629"><a name="p926584456165629"></a><a name="p926584456165629"></a>Obtains the memory page size. </p>
</td>
</tr>
<tr id="row320303464165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p867427828165629"><a name="p867427828165629"></a><a name="p867427828165629"></a><a href="UTILS.md#ga7c080ffcae5180218dda2df501e0cb15">chown</a> (const char *pathname, <a href="UTILS.md#ga66a6f1a27d4474144d59fb2b805ff50e">uid_t</a> owner, <a href="UTILS.md#ga7ba7f6123ac8905fbe36f596bea2437e">gid_t</a> group)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p843085456165629"><a name="p843085456165629"></a><a name="p843085456165629"></a>int </p>
<p id="p1524751523165629"><a name="p1524751523165629"></a><a name="p1524751523165629"></a>Changes the user and group ownership of a file. </p>
</td>
</tr>
</tbody>
</table>

