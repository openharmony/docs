# stdlib.h<a name="ZH-CN_TOPIC_0000001054948039"></a>

-   [Overview](#section1567410899165629)
-   [Summary](#section1285719068165629)
-   [Data Structures](#nested-classes)
-   [Functions](#func-members)

## **Overview**<a name="section1567410899165629"></a>

**Related Modules:**

[UTILS](UTILS.md)

**Description:**

Declares common functions used for performing I/O operations. 

You can use the functions provided in this file to complete string conversion, random number generation, array sorting, and tree-related operations during development. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1285719068165629"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table1486850725165629"></a>
<table><thead align="left"><tr id="row434885340165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p218370752165629"><a name="p218370752165629"></a><a name="p218370752165629"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1178198977165629"><a name="p1178198977165629"></a><a name="p1178198977165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2119308628165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p796711764165629"><a name="p796711764165629"></a><a name="p796711764165629"></a><a href="div_t.md">div_t</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1052130341165629"><a name="p1052130341165629"></a><a name="p1052130341165629"></a>Defines the structures of the division operation result. </p>
</td>
</tr>
<tr id="row1645973254165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1432164898165629"><a name="p1432164898165629"></a><a name="p1432164898165629"></a><a href="ldiv_t.md">ldiv_t</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p25642251165629"><a name="p25642251165629"></a><a name="p25642251165629"></a>Defines the structures of the division operation result. </p>
</td>
</tr>
<tr id="row1360895856165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1620067308165629"><a name="p1620067308165629"></a><a name="p1620067308165629"></a><a href="lldiv_t.md">lldiv_t</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p498556460165629"><a name="p498556460165629"></a><a name="p498556460165629"></a>Defines the structures of the division operation result. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1094592826165629"></a>
<table><thead align="left"><tr id="row366874515165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p761750820165629"><a name="p761750820165629"></a><a name="p761750820165629"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p106823640165629"><a name="p106823640165629"></a><a name="p106823640165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1287925384165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p446164304165629"><a name="p446164304165629"></a><a name="p446164304165629"></a><a href="UTILS.md#gad228deceea1bac4d9f171f647c265059">atoi</a> (const char *nptr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p965772726165629"><a name="p965772726165629"></a><a name="p965772726165629"></a>int </p>
<p id="p1661486137165629"><a name="p1661486137165629"></a><a name="p1661486137165629"></a>Converts an input string to an integer. </p>
</td>
</tr>
<tr id="row2115808358165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2052658200165629"><a name="p2052658200165629"></a><a name="p2052658200165629"></a><a href="UTILS.md#ga185551efd32d058ef290ebe2d144219f">atol</a> (const char *nptr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1615293409165629"><a name="p1615293409165629"></a><a name="p1615293409165629"></a>long </p>
<p id="p975244793165629"><a name="p975244793165629"></a><a name="p975244793165629"></a>Converts an input string to a long integer. </p>
</td>
</tr>
<tr id="row737839229165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p391662657165629"><a name="p391662657165629"></a><a name="p391662657165629"></a><a href="UTILS.md#ga5d0555f6ac42472671281e5903244b7b">atoll</a> (const char *nptr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p605709634165629"><a name="p605709634165629"></a><a name="p605709634165629"></a>long long </p>
<p id="p1789941679165629"><a name="p1789941679165629"></a><a name="p1789941679165629"></a>Converts a string to an 8-byte long integer. </p>
</td>
</tr>
<tr id="row300712665165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1098419803165629"><a name="p1098419803165629"></a><a name="p1098419803165629"></a><a href="UTILS.md#gac03da055b7752247b034fb582cb4372f">atof</a> (const char *nptr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p667035016165629"><a name="p667035016165629"></a><a name="p667035016165629"></a>double </p>
<p id="p1383461191165629"><a name="p1383461191165629"></a><a name="p1383461191165629"></a>Converts an input string to a double-precision floating-point number. </p>
</td>
</tr>
<tr id="row215901020165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1120498350165629"><a name="p1120498350165629"></a><a name="p1120498350165629"></a><a href="UTILS.md#ga2370632318c3797a314f8eb62d37947c">strtof</a> (const char *nptr, char **endptr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2019416960165629"><a name="p2019416960165629"></a><a name="p2019416960165629"></a>float </p>
<p id="p525133216165629"><a name="p525133216165629"></a><a name="p525133216165629"></a>Converts an input string to a floating-point number. </p>
</td>
</tr>
<tr id="row1280133734165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p787715617165629"><a name="p787715617165629"></a><a name="p787715617165629"></a><a href="UTILS.md#ga0c17a0b44f572941d9f73518f99ea7ed">strtod</a> (const char *nptr, char **endptr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1473081450165629"><a name="p1473081450165629"></a><a name="p1473081450165629"></a>double </p>
<p id="p441501501165629"><a name="p441501501165629"></a><a name="p441501501165629"></a>Converts a string to <strong id="b1528272009165629"><a name="b1528272009165629"></a><a name="b1528272009165629"></a>double</strong>. </p>
</td>
</tr>
<tr id="row1509652895165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p613604324165629"><a name="p613604324165629"></a><a name="p613604324165629"></a><a href="UTILS.md#gad2ed05594fb04a126627c0fd5c7e2232">strtold</a> (const char *nptr, char **endptr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2126644321165629"><a name="p2126644321165629"></a><a name="p2126644321165629"></a>long double </p>
<p id="p194097942165629"><a name="p194097942165629"></a><a name="p194097942165629"></a>Converts a string to <strong id="b1887188484165629"><a name="b1887188484165629"></a><a name="b1887188484165629"></a>long double</strong>. </p>
</td>
</tr>
<tr id="row1483613721165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p684840832165629"><a name="p684840832165629"></a><a name="p684840832165629"></a><a href="UTILS.md#ga311071298c2fe3e5d7057f396a6acfdc">strtol</a> (const char *nptr, char **endptr, int base)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p959341413165629"><a name="p959341413165629"></a><a name="p959341413165629"></a>long </p>
<p id="p95887734165629"><a name="p95887734165629"></a><a name="p95887734165629"></a>Converts a string to a long integer according to the given <strong id="b1261111722165629"><a name="b1261111722165629"></a><a name="b1261111722165629"></a>base</strong>. </p>
</td>
</tr>
<tr id="row1560368908165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1504950720165629"><a name="p1504950720165629"></a><a name="p1504950720165629"></a><a href="UTILS.md#ga6d257fc3f00865d0556ed7327c312b55">strtoul</a> (const char *nptr, char **endptr, int base)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1447591828165629"><a name="p1447591828165629"></a><a name="p1447591828165629"></a>unsigned long </p>
<p id="p607334430165629"><a name="p607334430165629"></a><a name="p607334430165629"></a>Converts a string to an unsigned long integer according to the given <strong id="b830888949165629"><a name="b830888949165629"></a><a name="b830888949165629"></a>base</strong>. </p>
</td>
</tr>
<tr id="row1223501593165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1718553021165629"><a name="p1718553021165629"></a><a name="p1718553021165629"></a><a href="UTILS.md#gafb901aa665b7e2e3e27025ca77fecd1b">strtoll</a> (const char *nptr, char **endptr, int base)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1155097770165629"><a name="p1155097770165629"></a><a name="p1155097770165629"></a>long long </p>
<p id="p863402719165629"><a name="p863402719165629"></a><a name="p863402719165629"></a>Converts a string to a long long integer according to the given <strong id="b980507498165629"><a name="b980507498165629"></a><a name="b980507498165629"></a>base</strong>. </p>
</td>
</tr>
<tr id="row743767590165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2136742395165629"><a name="p2136742395165629"></a><a name="p2136742395165629"></a><a href="UTILS.md#gae5835422eb2dfc17ea8deb3b15bcc541">strtoull</a> (const char *nptr, char **endptr, int base)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2090391171165629"><a name="p2090391171165629"></a><a name="p2090391171165629"></a>unsigned long long </p>
<p id="p594572634165629"><a name="p594572634165629"></a><a name="p594572634165629"></a>Converts a string to an unsigned long long integer according to the given <strong id="b1480481216165629"><a name="b1480481216165629"></a><a name="b1480481216165629"></a>base</strong>. </p>
</td>
</tr>
<tr id="row1130356466165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p265449393165629"><a name="p265449393165629"></a><a name="p265449393165629"></a><a href="UTILS.md#gae23144bcbb8e3742b00eb687c36654d1">rand</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1515659980165629"><a name="p1515659980165629"></a><a name="p1515659980165629"></a>int </p>
<p id="p1625710899165629"><a name="p1625710899165629"></a><a name="p1625710899165629"></a>Generates a pseudo-random number. </p>
</td>
</tr>
<tr id="row246867525165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p115278984165629"><a name="p115278984165629"></a><a name="p115278984165629"></a><a href="UTILS.md#ga83a727cc697aea22e24cad5f39198dd2">srand</a> (unsigned int seed)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p429271957165629"><a name="p429271957165629"></a><a name="p429271957165629"></a>void </p>
<p id="p518609064165629"><a name="p518609064165629"></a><a name="p518609064165629"></a>Initializes a random number generator. </p>
</td>
</tr>
<tr id="row1847026937165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p105431828165629"><a name="p105431828165629"></a><a name="p105431828165629"></a><a href="UTILS.md#ga7ac38fce3243a7dcf448301ee9ffd392">malloc</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p433946153165629"><a name="p433946153165629"></a><a name="p433946153165629"></a>void * </p>
<p id="p503289049165629"><a name="p503289049165629"></a><a name="p503289049165629"></a>Dynamically allocates a memory block of <strong id="b1676600469165629"><a name="b1676600469165629"></a><a name="b1676600469165629"></a>size</strong>. </p>
</td>
</tr>
<tr id="row1556096041165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p946901628165629"><a name="p946901628165629"></a><a name="p946901628165629"></a><a href="UTILS.md#ga62b7798461bd461da64c5f9d35feddf7">calloc</a> (size_t nmemb, size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1478906950165629"><a name="p1478906950165629"></a><a name="p1478906950165629"></a>void * </p>
<p id="p610434255165629"><a name="p610434255165629"></a><a name="p610434255165629"></a>Dynamically allocates <strong id="b645773825165629"><a name="b645773825165629"></a><a name="b645773825165629"></a>nmemb</strong> memory blocks of <strong id="b582700489165629"><a name="b582700489165629"></a><a name="b582700489165629"></a>size</strong>. </p>
</td>
</tr>
<tr id="row1107310816165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p960668986165629"><a name="p960668986165629"></a><a name="p960668986165629"></a><a href="UTILS.md#ga1a6b5e8d2f1c37e5b43e4345586075be">realloc</a> (void *ptr, size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1468293385165629"><a name="p1468293385165629"></a><a name="p1468293385165629"></a>void * </p>
<p id="p1602528895165629"><a name="p1602528895165629"></a><a name="p1602528895165629"></a>Changes the size of the memory block pointed to by <strong id="b2045033603165629"><a name="b2045033603165629"></a><a name="b2045033603165629"></a>ptr</strong> to <strong id="b281756679165629"><a name="b281756679165629"></a><a name="b281756679165629"></a>size</strong> bytes. </p>
</td>
</tr>
<tr id="row1501636536165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1616188804165629"><a name="p1616188804165629"></a><a name="p1616188804165629"></a><a href="UTILS.md#gafbedc913aa4651b3c3b4b3aecd9b4711">free</a> (void *ptr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1457029846165629"><a name="p1457029846165629"></a><a name="p1457029846165629"></a>void </p>
<p id="p238218128165629"><a name="p238218128165629"></a><a name="p238218128165629"></a>Releases the memory space pointed to by <strong id="b88336359165629"><a name="b88336359165629"></a><a name="b88336359165629"></a>ptr</strong>. </p>
</td>
</tr>
<tr id="row275334522165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1611835506165629"><a name="p1611835506165629"></a><a name="p1611835506165629"></a><a href="UTILS.md#ga7d78319026a43c0a5f942436ad3f09a1">abort</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1534867623165629"><a name="p1534867623165629"></a><a name="p1534867623165629"></a>_Noreturn void </p>
<p id="p1810577081165629"><a name="p1810577081165629"></a><a name="p1810577081165629"></a>Terminates an abnormal process and sends the <strong id="b31177775165629"><a name="b31177775165629"></a><a name="b31177775165629"></a>SIGABRT</strong> signal to the caller. </p>
</td>
</tr>
<tr id="row19033653165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1095512617165629"><a name="p1095512617165629"></a><a name="p1095512617165629"></a><a href="UTILS.md#ga7fd89c82095df80e5e12d6b2834a2acc">atexit</a> (void(*func)(void))</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1698701393165629"><a name="p1698701393165629"></a><a name="p1698701393165629"></a>int </p>
<p id="p1213347860165629"><a name="p1213347860165629"></a><a name="p1213347860165629"></a>Registers a termination function. </p>
</td>
</tr>
<tr id="row1979979897165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1030339336165629"><a name="p1030339336165629"></a><a name="p1030339336165629"></a><a href="UTILS.md#ga55e99c539cf7723ec15e856b7e0a8cee">exit</a> (int status)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p366002157165629"><a name="p366002157165629"></a><a name="p366002157165629"></a>void </p>
<p id="p999725398165629"><a name="p999725398165629"></a><a name="p999725398165629"></a>Terminates the calling process, clears the used memory space and various data structures in the kernel, and sends the process end status to the parent process. All functions registered with atexit and on_exit are called in the reverse order. </p>
</td>
</tr>
<tr id="row1529198766165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p778431317165629"><a name="p778431317165629"></a><a name="p778431317165629"></a><a href="UTILS.md#gabc6595dbf6880c71628fecf0dbb23d66">getenv</a> (const char *name)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p754340801165629"><a name="p754340801165629"></a><a name="p754340801165629"></a>char * </p>
<p id="p565054920165629"><a name="p565054920165629"></a><a name="p565054920165629"></a>Obtains the value of an environment variable. </p>
</td>
</tr>
<tr id="row2119823414165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p123580435165629"><a name="p123580435165629"></a><a name="p123580435165629"></a><a href="UTILS.md#ga7631d470a867ad04b3272667ea4b643e">_Exit</a> (int status)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1663292531165629"><a name="p1663292531165629"></a><a name="p1663292531165629"></a>void </p>
<p id="p1496890580165629"><a name="p1496890580165629"></a><a name="p1496890580165629"></a>Terminates the calling process, clears the used memory space and various data structures in the kernel, and sends the process end status to the parent process. </p>
</td>
</tr>
<tr id="row552166419165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p890631793165629"><a name="p890631793165629"></a><a name="p890631793165629"></a><a href="UTILS.md#ga901e482eabd0dedb19224cf731e15403">assert</a> (scalar expression)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1214893090165629"><a name="p1214893090165629"></a><a name="p1214893090165629"></a>void </p>
<p id="p64902650165629"><a name="p64902650165629"></a><a name="p64902650165629"></a>Aborts the program if assertion is false. </p>
</td>
</tr>
<tr id="row741501166165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1501562149165629"><a name="p1501562149165629"></a><a name="p1501562149165629"></a><a href="UTILS.md#ga131d5a62230be50122c603018fdb3fc2">secure_getenv</a> (const char *name)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p103028774165629"><a name="p103028774165629"></a><a name="p103028774165629"></a>char * </p>
<p id="p1106284251165629"><a name="p1106284251165629"></a><a name="p1106284251165629"></a>Obtains the value of an environment variable. </p>
</td>
</tr>
<tr id="row1218050812165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p818307754165629"><a name="p818307754165629"></a><a name="p818307754165629"></a><a href="UTILS.md#gac1ed47dda697f858893a9a68882a9fab">bsearch</a> (const void *key, const void *base, size_t nel, size_t width, int(*compar)(const void *, const void *))</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1288966459165629"><a name="p1288966459165629"></a><a name="p1288966459165629"></a>void * </p>
<p id="p1532675646165629"><a name="p1532675646165629"></a><a name="p1532675646165629"></a>Searches for <strong id="b1992788139165629"><a name="b1992788139165629"></a><a name="b1992788139165629"></a>key</strong> using the binary search algorithm from the array element <strong id="b974404055165629"><a name="b974404055165629"></a><a name="b974404055165629"></a>base[0]</strong> to <strong id="b1341170785165629"><a name="b1341170785165629"></a><a name="b1341170785165629"></a>base[num-1]</strong>. </p>
</td>
</tr>
<tr id="row70136250165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p359394883165629"><a name="p359394883165629"></a><a name="p359394883165629"></a><a href="UTILS.md#ga56ba7474387aae0977ce6dbe9bef805f">qsort</a> (const void *base, size_t nel, size_t width, int(*compar)(const void *, const void *))</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2135313849165629"><a name="p2135313849165629"></a><a name="p2135313849165629"></a>void </p>
<p id="p733933377165629"><a name="p733933377165629"></a><a name="p733933377165629"></a>Sorts array elements <strong id="b134764466165629"><a name="b134764466165629"></a><a name="b134764466165629"></a>base[0]</strong> to <strong id="b881973169165629"><a name="b881973169165629"></a><a name="b881973169165629"></a>base[num-1]</strong> based on the comparison rules of <strong id="b1663843286165629"><a name="b1663843286165629"></a><a name="b1663843286165629"></a>compar</strong>. </p>
</td>
</tr>
<tr id="row508962536165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p389409562165629"><a name="p389409562165629"></a><a name="p389409562165629"></a><a href="UTILS.md#gaf15d7205d8d10c4820f997ce5c526279">abs</a> (int i)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1755388962165629"><a name="p1755388962165629"></a><a name="p1755388962165629"></a>int </p>
<p id="p435554275165629"><a name="p435554275165629"></a><a name="p435554275165629"></a>Obtains the absolute value of an integer value. </p>
</td>
</tr>
<tr id="row2017509713165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p50169317165629"><a name="p50169317165629"></a><a name="p50169317165629"></a><a href="UTILS.md#gac39409d0077cf980e4e6419bc6014d10">labs</a> (long i)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1173315157165629"><a name="p1173315157165629"></a><a name="p1173315157165629"></a>long </p>
<p id="p2031847463165629"><a name="p2031847463165629"></a><a name="p2031847463165629"></a>Calculates the absolute value of a long integer. </p>
</td>
</tr>
<tr id="row598859242165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1493803192165629"><a name="p1493803192165629"></a><a name="p1493803192165629"></a><a href="UTILS.md#ga7251caa2dd32261e7768d824c0a532c6">llabs</a> (long long i)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2020616957165629"><a name="p2020616957165629"></a><a name="p2020616957165629"></a>long long </p>
<p id="p507595142165629"><a name="p507595142165629"></a><a name="p507595142165629"></a>Calculates the absolute value of a long long integer. </p>
</td>
</tr>
<tr id="row905996450165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2071950913165629"><a name="p2071950913165629"></a><a name="p2071950913165629"></a><a href="UTILS.md#ga98cbdcca43b259bf545f16c72f07825b">div</a> (int numerator, int denominator)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p603246927165629"><a name="p603246927165629"></a><a name="p603246927165629"></a><a href="div_t.md">div_t</a> </p>
<p id="p1992639218165629"><a name="p1992639218165629"></a><a name="p1992639218165629"></a>Calculates the quotient and remainder of an integer after division. </p>
</td>
</tr>
<tr id="row1005050062165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1611378402165629"><a name="p1611378402165629"></a><a name="p1611378402165629"></a><a href="UTILS.md#ga9ce9bebe15110c3774f311cd587dc543">ldiv</a> (long numerator, long denominator)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p226138122165629"><a name="p226138122165629"></a><a name="p226138122165629"></a><a href="ldiv_t.md">ldiv_t</a> </p>
<p id="p2045117485165629"><a name="p2045117485165629"></a><a name="p2045117485165629"></a>Calculates the quotient and remainder of a long integer after division. </p>
</td>
</tr>
<tr id="row223093164165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1331368827165629"><a name="p1331368827165629"></a><a name="p1331368827165629"></a><a href="UTILS.md#ga28b92959777798288e1ac1def1c16ddc">lldiv</a> (long long numerator, long long denominator)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1798655245165629"><a name="p1798655245165629"></a><a name="p1798655245165629"></a><a href="lldiv_t.md">lldiv_t</a> </p>
<p id="p185875509165629"><a name="p185875509165629"></a><a name="p185875509165629"></a>Calculates the quotient and remainder of a long long integer after division. </p>
</td>
</tr>
<tr id="row859868594165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p292889327165629"><a name="p292889327165629"></a><a name="p292889327165629"></a><a href="UTILS.md#ga10b28b2a9d994195623066c344fcf1fd">mblen</a> (const char *s, size_t n)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p273498160165629"><a name="p273498160165629"></a><a name="p273498160165629"></a>int </p>
<p id="p1772746447165629"><a name="p1772746447165629"></a><a name="p1772746447165629"></a>Obtains the number of bytes in the next multi-byte string. </p>
</td>
</tr>
<tr id="row1650174041165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p302789367165629"><a name="p302789367165629"></a><a name="p302789367165629"></a><a href="UTILS.md#ga6d2e39eeb319f32608b467c0c0ca1393">mbtowc</a> (wchar_t *pwc, const char *s, size_t n)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1056928007165629"><a name="p1056928007165629"></a><a name="p1056928007165629"></a>int </p>
<p id="p182380034165629"><a name="p182380034165629"></a><a name="p182380034165629"></a>Converts a string constant to a wide character. </p>
</td>
</tr>
<tr id="row1279350665165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p976571187165629"><a name="p976571187165629"></a><a name="p976571187165629"></a><a href="UTILS.md#gab576ad05484aba7fe43b3d047a3fabb5">wctomb</a> (char *s, wchar_t wc)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p968804838165629"><a name="p968804838165629"></a><a name="p968804838165629"></a>int </p>
<p id="p496878261165629"><a name="p496878261165629"></a><a name="p496878261165629"></a>Converts a wide character to its multi-byte sequence and stores it in a character array. </p>
</td>
</tr>
<tr id="row672363919165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1318924604165629"><a name="p1318924604165629"></a><a name="p1318924604165629"></a><a href="UTILS.md#ga95b89e577f091ba05d6403ff542c2164">mbstowcs</a> (wchar_t *dest, const char *src, size_t n)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p632428612165629"><a name="p632428612165629"></a><a name="p632428612165629"></a>size_t </p>
<p id="p1371480713165629"><a name="p1371480713165629"></a><a name="p1371480713165629"></a>Converts a multi-byte string to a wide-character string. </p>
</td>
</tr>
<tr id="row131170225165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2025522193165629"><a name="p2025522193165629"></a><a name="p2025522193165629"></a><a href="UTILS.md#gae7586ae6f537a5fd64c8c2d7c850e3be">wcstombs</a> (char *dest, const wchar_t *src, size_t n)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p955617040165629"><a name="p955617040165629"></a><a name="p955617040165629"></a>size_t </p>
<p id="p668470702165629"><a name="p668470702165629"></a><a name="p668470702165629"></a>Converts a wide-character string to a multi-byte string. </p>
</td>
</tr>
<tr id="row938913043165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p76179012165629"><a name="p76179012165629"></a><a name="p76179012165629"></a><a href="UTILS.md#gaed1e9c27ea92f5ae3a480059bf45c311">posix_memalign</a> (void **memptr, size_t alignment, size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1357846269165629"><a name="p1357846269165629"></a><a name="p1357846269165629"></a>int </p>
<p id="p978929567165629"><a name="p978929567165629"></a><a name="p978929567165629"></a>Allocates memory with the specified size based on the given <strong id="b1245668052165629"><a name="b1245668052165629"></a><a name="b1245668052165629"></a>alignment</strong>. </p>
</td>
</tr>
<tr id="row2063006161165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2044372103165629"><a name="p2044372103165629"></a><a name="p2044372103165629"></a><a href="UTILS.md#ga1c8b16a3abcb4dc450a0a62b42c554dd">setenv</a> (const char *name, const char *value, int overwrite)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1301300970165629"><a name="p1301300970165629"></a><a name="p1301300970165629"></a>int </p>
<p id="p943631788165629"><a name="p943631788165629"></a><a name="p943631788165629"></a>Add or change an environment variable. </p>
</td>
</tr>
<tr id="row1480589495165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p226668516165629"><a name="p226668516165629"></a><a name="p226668516165629"></a><a href="UTILS.md#ga17a3a11d20a551951a4acbc3872b280c">unsetenv</a> (const char *name)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1337828964165629"><a name="p1337828964165629"></a><a name="p1337828964165629"></a>int </p>
<p id="p1621679492165629"><a name="p1621679492165629"></a><a name="p1621679492165629"></a>Deletes an environment variable. </p>
</td>
</tr>
<tr id="row406765488165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p963894648165629"><a name="p963894648165629"></a><a name="p963894648165629"></a><a href="UTILS.md#ga6abe6c5eb77aeaf05ad81a7425547d9e">mkstemp</a> (char *template)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p688463100165629"><a name="p688463100165629"></a><a name="p688463100165629"></a>int </p>
<p id="p1795559591165629"><a name="p1795559591165629"></a><a name="p1795559591165629"></a>Creates and opens a unique temporary file. </p>
</td>
</tr>
<tr id="row1754024201165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2135734648165629"><a name="p2135734648165629"></a><a name="p2135734648165629"></a><a href="UTILS.md#ga691bcfdddb46ab9b43a91217a0ff77c9">mkostemp</a> (char *template, int flags)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2143706350165629"><a name="p2143706350165629"></a><a name="p2143706350165629"></a>int </p>
<p id="p1674924425165629"><a name="p1674924425165629"></a><a name="p1674924425165629"></a>Creates and opens a unique temporary file. </p>
</td>
</tr>
<tr id="row1008589251165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p792776258165629"><a name="p792776258165629"></a><a name="p792776258165629"></a><a href="UTILS.md#ga4c366b8d0ad8a393cf6224b5fc9ee045">mkdtemp</a> (char *template)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1734315334165629"><a name="p1734315334165629"></a><a name="p1734315334165629"></a>char * </p>
<p id="p295435017165629"><a name="p295435017165629"></a><a name="p295435017165629"></a>Creates a unique temporary directory based on <strong id="b2122011740165629"><a name="b2122011740165629"></a><a name="b2122011740165629"></a>template</strong>. </p>
</td>
</tr>
<tr id="row194998160165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1113181106165629"><a name="p1113181106165629"></a><a name="p1113181106165629"></a><a href="UTILS.md#ga2959446c8426187f340f8d5a625bf2e6">getsubopt</a> (char **optionp, char *const *tokens, char **valuep)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1853276948165629"><a name="p1853276948165629"></a><a name="p1853276948165629"></a>int </p>
<p id="p2094368143165629"><a name="p2094368143165629"></a><a name="p2094368143165629"></a>Processes the parameters of an option in the command line. </p>
</td>
</tr>
<tr id="row868427921165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p712596756165629"><a name="p712596756165629"></a><a name="p712596756165629"></a><a href="UTILS.md#ga4d592bbc52a36404b05aa9ff5b7503c1">rand_r</a> (unsigned *seedp)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1727322816165629"><a name="p1727322816165629"></a><a name="p1727322816165629"></a>int </p>
<p id="p1352998225165629"><a name="p1352998225165629"></a><a name="p1352998225165629"></a>Generates a pseudo-random number. </p>
</td>
</tr>
<tr id="row844437045165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1442750986165629"><a name="p1442750986165629"></a><a name="p1442750986165629"></a><a href="UTILS.md#gaae6b0f26f4a57df79f7c497a65d174d9">realpath</a> (const char *__restrict path, char *__restrict resolved)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1710405251165629"><a name="p1710405251165629"></a><a name="p1710405251165629"></a>char * </p>
<p id="p608721754165629"><a name="p608721754165629"></a><a name="p608721754165629"></a>Obtains a normalized absolute path. </p>
</td>
</tr>
<tr id="row209907447165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p198224192165629"><a name="p198224192165629"></a><a name="p198224192165629"></a><a href="UTILS.md#ga350b5b3334c99bb57d2b39da0b2dd694">random</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1279342736165629"><a name="p1279342736165629"></a><a name="p1279342736165629"></a>long int </p>
<p id="p774895866165629"><a name="p774895866165629"></a><a name="p774895866165629"></a>Generates a pseudo-random number. </p>
</td>
</tr>
<tr id="row245848270165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p131068833165629"><a name="p131068833165629"></a><a name="p131068833165629"></a><a href="UTILS.md#gaf1e7e3d144face36372f9ae8b18aa009">srandom</a> (unsigned int seed)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1230318691165629"><a name="p1230318691165629"></a><a name="p1230318691165629"></a>void </p>
<p id="p1226414959165629"><a name="p1226414959165629"></a><a name="p1226414959165629"></a>Initializes a random number generator. </p>
</td>
</tr>
<tr id="row265544477165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p729498661165629"><a name="p729498661165629"></a><a name="p729498661165629"></a><a href="UTILS.md#ga9250c684f653b1bd715bab29d35d2423">initstate</a> (unsigned int seed, char *state, size_t n)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1960543458165629"><a name="p1960543458165629"></a><a name="p1960543458165629"></a>char * </p>
<p id="p686927235165629"><a name="p686927235165629"></a><a name="p686927235165629"></a>Initializes a random number generator. </p>
</td>
</tr>
<tr id="row158637287165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p532733539165629"><a name="p532733539165629"></a><a name="p532733539165629"></a><a href="UTILS.md#gaa4970d8361258d9b821ad83036a2da3a">setstate</a> (char *state)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1413375311165629"><a name="p1413375311165629"></a><a name="p1413375311165629"></a>char * </p>
<p id="p1194925464165629"><a name="p1194925464165629"></a><a name="p1194925464165629"></a>Sets the current state list for subsequent random use. </p>
</td>
</tr>
<tr id="row1160260839165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1030738670165629"><a name="p1030738670165629"></a><a name="p1030738670165629"></a><a href="UTILS.md#ga8a382cc6123c7cf09a144e28fdfe5bc1">putenv</a> (char *s)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1534713440165629"><a name="p1534713440165629"></a><a name="p1534713440165629"></a>int </p>
<p id="p887672071165629"><a name="p887672071165629"></a><a name="p887672071165629"></a>Configures an environment variable. </p>
</td>
</tr>
<tr id="row251867664165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1811725293165629"><a name="p1811725293165629"></a><a name="p1811725293165629"></a><a href="UTILS.md#ga4045440e70229bdb726924f628f66d92">l64a</a> (long value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1137048834165629"><a name="p1137048834165629"></a><a name="p1137048834165629"></a>char * </p>
<p id="p1848689867165629"><a name="p1848689867165629"></a><a name="p1848689867165629"></a>Converts a long integer to a 64-bit ASCII string. </p>
</td>
</tr>
<tr id="row1465135622165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2111059408165629"><a name="p2111059408165629"></a><a name="p2111059408165629"></a><a href="UTILS.md#gaed396b4eb37b2a1f5414f9c21749dadb">a64l</a> (const char *str64)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p591731170165629"><a name="p591731170165629"></a><a name="p591731170165629"></a>long </p>
<p id="p2096280653165629"><a name="p2096280653165629"></a><a name="p2096280653165629"></a>Converts between a 32-bit long integer and a little-endian 64-bit ASCII string. </p>
</td>
</tr>
<tr id="row34342816165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p564122212165629"><a name="p564122212165629"></a><a name="p564122212165629"></a><a href="UTILS.md#gaf9329f9acef07ca14ea2256191c3ce74">drand48</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p577322698165629"><a name="p577322698165629"></a><a name="p577322698165629"></a>double </p>
<p id="p1191014366165629"><a name="p1191014366165629"></a><a name="p1191014366165629"></a>Obtains a random number. </p>
</td>
</tr>
<tr id="row1403614114165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p806135630165629"><a name="p806135630165629"></a><a name="p806135630165629"></a><a href="UTILS.md#ga95f02f2831f093c6e151f0b782f20e48">erand48</a> (unsigned short xsubi[3])</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p677393515165629"><a name="p677393515165629"></a><a name="p677393515165629"></a>double </p>
<p id="p1480147852165629"><a name="p1480147852165629"></a><a name="p1480147852165629"></a>Obtains a random number. </p>
</td>
</tr>
<tr id="row951742503165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2031262068165629"><a name="p2031262068165629"></a><a name="p2031262068165629"></a><a href="UTILS.md#gad20ddf22bece340e3036c60cad913250">lrand48</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p672065168165629"><a name="p672065168165629"></a><a name="p672065168165629"></a>long int </p>
<p id="p1364415775165629"><a name="p1364415775165629"></a><a name="p1364415775165629"></a>Generates pseudo-random numbers evenly distributed between [0, 2^31). </p>
</td>
</tr>
<tr id="row1387812832165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1099978288165629"><a name="p1099978288165629"></a><a name="p1099978288165629"></a><a href="UTILS.md#gaae8f9c9ee0a49b3bd8bea3331dab500f">nrand48</a> (unsigned short xsubi[3])</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p884606212165629"><a name="p884606212165629"></a><a name="p884606212165629"></a>long int </p>
<p id="p444546006165629"><a name="p444546006165629"></a><a name="p444546006165629"></a>Generates pseudo-random numbers evenly distributed between [0, 2^31). </p>
</td>
</tr>
<tr id="row1743906785165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1388585998165629"><a name="p1388585998165629"></a><a name="p1388585998165629"></a><a href="UTILS.md#ga9c450a7a3d4437e3d5f8def180f68103">mrand48</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1627422109165629"><a name="p1627422109165629"></a><a name="p1627422109165629"></a>long </p>
<p id="p1179360562165629"><a name="p1179360562165629"></a><a name="p1179360562165629"></a>Generates pseudo-random numbers evenly distributed between [-2^31, 2^31). </p>
</td>
</tr>
<tr id="row79778297165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p12945733165629"><a name="p12945733165629"></a><a name="p12945733165629"></a><a href="UTILS.md#ga79163d3776f4009f0e7f1830f4be4d02">jrand48</a> (unsigned short xsubi[3])</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1977848955165629"><a name="p1977848955165629"></a><a name="p1977848955165629"></a>long </p>
<p id="p1020363497165629"><a name="p1020363497165629"></a><a name="p1020363497165629"></a>Generates pseudo-random numbers evenly distributed between [-2^31, 2^31). </p>
</td>
</tr>
<tr id="row448155870165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p221665517165629"><a name="p221665517165629"></a><a name="p221665517165629"></a><a href="UTILS.md#ga91c6acf8516086891c689926e49f1ddf">srand48</a> (long int seedval)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p236343556165629"><a name="p236343556165629"></a><a name="p236343556165629"></a>void </p>
<p id="p277117429165629"><a name="p277117429165629"></a><a name="p277117429165629"></a>Sets the start seed value for the pseudo-random number generator. </p>
</td>
</tr>
<tr id="row902668788165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1837147406165629"><a name="p1837147406165629"></a><a name="p1837147406165629"></a><a href="UTILS.md#ga0b86f7fc9964c291844e8112a367721c">seed48</a> (unsigned short[3])</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p598040369165629"><a name="p598040369165629"></a><a name="p598040369165629"></a>unsigned short * </p>
<p id="p975515381165629"><a name="p975515381165629"></a><a name="p975515381165629"></a>Generates an evenly distributed pseudo-random seed. </p>
</td>
</tr>
<tr id="row1571228047165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p34421260165629"><a name="p34421260165629"></a><a name="p34421260165629"></a><a href="UTILS.md#ga71e0019171f5584bb6957867691c3e10">lcong48</a> (unsigned short param[7])</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p966508058165629"><a name="p966508058165629"></a><a name="p966508058165629"></a>void </p>
<p id="p213980649165629"><a name="p213980649165629"></a><a name="p213980649165629"></a>Sets the seed and related algorithm parameters for the pseudo-random number generator. </p>
</td>
</tr>
<tr id="row278855693165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p694280835165629"><a name="p694280835165629"></a><a name="p694280835165629"></a><a href="UTILS.md#ga3db0418e1e0258f6a8809286c291cc5b">mktemp</a> (char *template)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1789559017165629"><a name="p1789559017165629"></a><a name="p1789559017165629"></a>char * </p>
<p id="p2139736306165629"><a name="p2139736306165629"></a><a name="p2139736306165629"></a>Creates a unique temporary file name. </p>
</td>
</tr>
<tr id="row857996584165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p320902422165629"><a name="p320902422165629"></a><a name="p320902422165629"></a><a href="UTILS.md#gab962063e3bb487de132da3016e2c813c">mkstemps</a> (char *template, int suffixlen)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1168441194165629"><a name="p1168441194165629"></a><a name="p1168441194165629"></a>int </p>
<p id="p1230647392165629"><a name="p1230647392165629"></a><a name="p1230647392165629"></a>Creates and opens a unique temporary file. </p>
</td>
</tr>
<tr id="row1812304872165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1380242863165629"><a name="p1380242863165629"></a><a name="p1380242863165629"></a><a href="UTILS.md#gafab16d88038590bdb4900150d2791081">mkostemps</a> (char *template, int suffixlen, int flags)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1706305017165629"><a name="p1706305017165629"></a><a name="p1706305017165629"></a>int </p>
<p id="p1572310930165629"><a name="p1572310930165629"></a><a name="p1572310930165629"></a>Creates and opens a unique temporary file. </p>
</td>
</tr>
<tr id="row7602721165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p459352682165629"><a name="p459352682165629"></a><a name="p459352682165629"></a><a href="UTILS.md#ga3d09e44a916600a38b367c1b6ebdf118">valloc</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p400083971165629"><a name="p400083971165629"></a><a name="p400083971165629"></a>void * </p>
<p id="p740128898165629"><a name="p740128898165629"></a><a name="p740128898165629"></a>Allocates memory with the specified size and aligns the allocated memory by page size. </p>
</td>
</tr>
<tr id="row1503462003165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p741502548165629"><a name="p741502548165629"></a><a name="p741502548165629"></a><a href="UTILS.md#ga888afe4104cd3bdc07445d8ed27b96bd">ecvt</a> (double number, int ndigits, int *decpt, int *sign)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p93875471165629"><a name="p93875471165629"></a><a name="p93875471165629"></a>char * </p>
<p id="p833609992165629"><a name="p833609992165629"></a><a name="p833609992165629"></a>Converts a double-precision floating-point number into a string. </p>
</td>
</tr>
<tr id="row1223962400165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1120293798165629"><a name="p1120293798165629"></a><a name="p1120293798165629"></a><a href="UTILS.md#gaf2658700b7da33eea87761f928b102de">fcvt</a> (double number, int ndigits, int *decpt, int *sign)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1998194520165629"><a name="p1998194520165629"></a><a name="p1998194520165629"></a>char * </p>
<p id="p1840703786165629"><a name="p1840703786165629"></a><a name="p1840703786165629"></a>Converts a floating-point number to a string. </p>
</td>
</tr>
<tr id="row1997913512165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1234691698165629"><a name="p1234691698165629"></a><a name="p1234691698165629"></a><a href="UTILS.md#gafabf46107539bb1ec32994c214b5eeba">gcvt</a> (double x, int n, char *b)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p449568942165629"><a name="p449568942165629"></a><a name="p449568942165629"></a>char * </p>
<p id="p492654995165629"><a name="p492654995165629"></a><a name="p492654995165629"></a>Converts a floating-point number to a string. </p>
</td>
</tr>
</tbody>
</table>

