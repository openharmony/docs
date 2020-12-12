# HiLog<a name="EN-US_TOPIC_0000001055198086"></a>

-   [Overview](#section662654821165625)
-   [Summary](#section1225783138165625)
-   [Macros](#define-members)
-   [Enumerations](#enum-members)
-   [Functions](#func-members)
-   [Details](#section1302429224165625)
-   [Macro Definition](#section517686992165625)
-   [HILOG\_DEBUG](#ga131e23e4dd8a01f7871851ac23ce3cfc)
-   [HILOG\_ERROR](#ga90b1019911094577057834ab3208e454)
-   [HILOG\_FATAL](#gac76a098606b7f1e2f73b14158abe0b25)
-   [HILOG\_INFO](#ga54d6ebdb0a272e51e3dc2e5cc9775677)
-   [HILOG\_WARN](#gab6e05f702fa067419ab6d2b241f70d96)
-   [LOG\_DOMAIN](#ga95a1d08c807e0aada863b5298a61d08d)
-   [LOG\_TAG](#ga7ce0df38eb467e59f209470c8f5ac4e6)
-   [Enumeration Type](#section1363762227165625)
-   [HiLogModuleType](#ga125ab0014dcc2b2152e0be2e39e31b9e)
-   [LogLevel](#gaca1fd1d8935433e6ba2e3918214e07f9)
-   [LogType](#gaf67907baa897e9fb84df0cb89795b87c)
-   [Function](#section2032748084165625)
-   [HiLogPrint\(\)](#ga09fb4cb8cda1a4353752964b3ac02c7b)

## **Overview**<a name="section662654821165625"></a>

**Description:**

Provides logging functions. 

For example, you can use these functions to output logs of the specified log type, service domain, log tag, and log level.

**Since:**

1.1

**Version:**

1.0

## **Summary**<a name="section1225783138165625"></a>

## Macros<a name="define-members"></a>

<a name="table773898148165625"></a>
<table><thead align="left"><tr id="row1378096436165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1426648008165625"><a name="p1426648008165625"></a><a name="p1426648008165625"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p395863248165625"><a name="p395863248165625"></a><a name="p395863248165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row246306547165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p992152465165625"><a name="p992152465165625"></a><a name="p992152465165625"></a><a href="hilog.md#ga95a1d08c807e0aada863b5298a61d08d">LOG_DOMAIN</a>   0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1166931885165625"><a name="p1166931885165625"></a><a name="p1166931885165625"></a>Defines the service domain for a log file. </p>
</td>
</tr>
<tr id="row175438285165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p152676432165625"><a name="p152676432165625"></a><a name="p152676432165625"></a><a href="hilog.md#ga7ce0df38eb467e59f209470c8f5ac4e6">LOG_TAG</a>   <a href="utils.md#ga070d2ce7b6bb7e5c05602aa8c308d0c4">NULL</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p76169172165625"><a name="p76169172165625"></a><a name="p76169172165625"></a>Defines a string constant used to identify the class, file, or service behavior. </p>
</td>
</tr>
<tr id="row789993060165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1360388865165625"><a name="p1360388865165625"></a><a name="p1360388865165625"></a><a href="hilog.md#ga131e23e4dd8a01f7871851ac23ce3cfc">HILOG_DEBUG</a>(type, ...)   ((void)<a href="hilog.md#ga09fb4cb8cda1a4353752964b3ac02c7b">HiLogPrint</a>(LOG_CORE, <a href="hilog.md#ggaca1fd1d8935433e6ba2e3918214e07f9ab9f002c6ffbfd511da8090213227454e">LOG_DEBUG</a>, <a href="hilog.md#ga95a1d08c807e0aada863b5298a61d08d">LOG_DOMAIN</a>, <a href="hilog.md#ga7ce0df38eb467e59f209470c8f5ac4e6">LOG_TAG</a>, __VA_ARGS__))</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p369321061165625"><a name="p369321061165625"></a><a name="p369321061165625"></a>Outputs debug logs. This is a function-like macro. </p>
</td>
</tr>
<tr id="row1521811251165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1983405153165625"><a name="p1983405153165625"></a><a name="p1983405153165625"></a><a href="hilog.md#ga54d6ebdb0a272e51e3dc2e5cc9775677">HILOG_INFO</a>(type, ...)   ((void)<a href="hilog.md#ga09fb4cb8cda1a4353752964b3ac02c7b">HiLogPrint</a>(LOG_CORE, <a href="hilog.md#ggaca1fd1d8935433e6ba2e3918214e07f9a6e98ff471e3ce6c4ef2d75c37ee51837">LOG_INFO</a>, <a href="hilog.md#ga95a1d08c807e0aada863b5298a61d08d">LOG_DOMAIN</a>, <a href="hilog.md#ga7ce0df38eb467e59f209470c8f5ac4e6">LOG_TAG</a>, __VA_ARGS__))</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1260349606165625"><a name="p1260349606165625"></a><a name="p1260349606165625"></a>Outputs informational logs. This is a function-like macro. </p>
</td>
</tr>
<tr id="row1787062247165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p17090450165625"><a name="p17090450165625"></a><a name="p17090450165625"></a><a href="hilog.md#gab6e05f702fa067419ab6d2b241f70d96">HILOG_WARN</a>(type, ...)   ((void)<a href="hilog.md#ga09fb4cb8cda1a4353752964b3ac02c7b">HiLogPrint</a>(LOG_CORE, <a href="hilog.md#ggaca1fd1d8935433e6ba2e3918214e07f9ac8041ffa22bc823d4726701cdb13fc13">LOG_WARN</a>, <a href="hilog.md#ga95a1d08c807e0aada863b5298a61d08d">LOG_DOMAIN</a>, <a href="hilog.md#ga7ce0df38eb467e59f209470c8f5ac4e6">LOG_TAG</a>, __VA_ARGS__))</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p121721090165625"><a name="p121721090165625"></a><a name="p121721090165625"></a>Outputs warning logs. This is a function-like macro. </p>
</td>
</tr>
<tr id="row1310606348165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1062899188165625"><a name="p1062899188165625"></a><a name="p1062899188165625"></a><a href="hilog.md#ga90b1019911094577057834ab3208e454">HILOG_ERROR</a>(type, ...)   ((void)<a href="hilog.md#ga09fb4cb8cda1a4353752964b3ac02c7b">HiLogPrint</a>(LOG_CORE, <a href="hilog.md#ggaca1fd1d8935433e6ba2e3918214e07f9a230506cce5c68c3bac5a821c42ed3473">LOG_ERROR</a>, <a href="hilog.md#ga95a1d08c807e0aada863b5298a61d08d">LOG_DOMAIN</a>, <a href="hilog.md#ga7ce0df38eb467e59f209470c8f5ac4e6">LOG_TAG</a>, __VA_ARGS__))</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p523341015165625"><a name="p523341015165625"></a><a name="p523341015165625"></a>Outputs error logs. This is a function-like macro. </p>
</td>
</tr>
<tr id="row1920540822165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1643627137165625"><a name="p1643627137165625"></a><a name="p1643627137165625"></a><a href="hilog.md#gac76a098606b7f1e2f73b14158abe0b25">HILOG_FATAL</a>(type, ...)   ((void)<a href="hilog.md#ga09fb4cb8cda1a4353752964b3ac02c7b">HiLogPrint</a>(LOG_CORE, <a href="hilog.md#ggaca1fd1d8935433e6ba2e3918214e07f9ac630750884d91cb9767ef2200bbb048b">LOG_FATAL</a>, <a href="hilog.md#ga95a1d08c807e0aada863b5298a61d08d">LOG_DOMAIN</a>, <a href="hilog.md#ga7ce0df38eb467e59f209470c8f5ac4e6">LOG_TAG</a>, __VA_ARGS__))</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p337468493165625"><a name="p337468493165625"></a><a name="p337468493165625"></a>Outputs fatal logs. This is a function-like macro. </p>
</td>
</tr>
</tbody>
</table>

## Enumerations<a name="enum-members"></a>

<a name="table2067195920165625"></a>
<table><thead align="left"><tr id="row1720872290165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1942846179165625"><a name="p1942846179165625"></a><a name="p1942846179165625"></a>Enumeration Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p737342275165625"><a name="p737342275165625"></a><a name="p737342275165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row584131446165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p691526806165625"><a name="p691526806165625"></a><a name="p691526806165625"></a><a href="hilog.md#ga125ab0014dcc2b2152e0be2e39e31b9e">HiLogModuleType</a> {   <a href="hilog.md#gga125ab0014dcc2b2152e0be2e39e31b9ea6eef5ce03266c8d2f0ef2ff63e86230b">HILOG_MODULE_HIVIEW</a> = 0, <a href="hilog.md#gga125ab0014dcc2b2152e0be2e39e31b9eac1f60668255cfb6314d4fb8083f50ea3">HILOG_MODULE_SAMGR</a>, <a href="hilog.md#gga125ab0014dcc2b2152e0be2e39e31b9ea7dd731467818fc45a8474442af2f3302">HILOG_MODULE_ACE</a>, <a href="hilog.md#gga125ab0014dcc2b2152e0be2e39e31b9ea7194cace682dfd6f7cce00a6a7f96ac3">HILOG_MODULE_APP</a>,   <a href="hilog.md#gga125ab0014dcc2b2152e0be2e39e31b9ea746b8468c1657750bf0d5487a3cbbb33">HILOG_MODULE_MAX</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1102110443165625"><a name="p1102110443165625"></a><a name="p1102110443165625"></a>Enumerates logging module types. </p>
</td>
</tr>
<tr id="row1078902380165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p877397053165625"><a name="p877397053165625"></a><a name="p877397053165625"></a><a href="hilog.md#gaf67907baa897e9fb84df0cb89795b87c">LogType</a> </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p189718463165625"><a name="p189718463165625"></a><a name="p189718463165625"></a>Enumerates log types. </p>
</td>
</tr>
<tr id="row438242951165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p660369749165625"><a name="p660369749165625"></a><a name="p660369749165625"></a><a href="hilog.md#gaca1fd1d8935433e6ba2e3918214e07f9">LogLevel</a> {   <a href="hilog.md#ggaca1fd1d8935433e6ba2e3918214e07f9ab9f002c6ffbfd511da8090213227454e">LOG_DEBUG</a> = 3, <a href="hilog.md#ggaca1fd1d8935433e6ba2e3918214e07f9a6e98ff471e3ce6c4ef2d75c37ee51837">LOG_INFO</a> = 4, <a href="hilog.md#ggaca1fd1d8935433e6ba2e3918214e07f9ac8041ffa22bc823d4726701cdb13fc13">LOG_WARN</a> = 5, <a href="hilog.md#ggaca1fd1d8935433e6ba2e3918214e07f9a230506cce5c68c3bac5a821c42ed3473">LOG_ERROR</a> = 6,   <a href="hilog.md#ggaca1fd1d8935433e6ba2e3918214e07f9ac630750884d91cb9767ef2200bbb048b">LOG_FATAL</a> = 7 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p521114159165625"><a name="p521114159165625"></a><a name="p521114159165625"></a>Enumerates log levels. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table205968871165625"></a>
<table><thead align="left"><tr id="row1303126762165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p935949927165625"><a name="p935949927165625"></a><a name="p935949927165625"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1713517218165625"><a name="p1713517218165625"></a><a name="p1713517218165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row139851586165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1163487239165625"><a name="p1163487239165625"></a><a name="p1163487239165625"></a><a href="hilog.md#ga09fb4cb8cda1a4353752964b3ac02c7b">HiLogPrint</a> (<a href="hilog.md#gaf67907baa897e9fb84df0cb89795b87c">LogType</a> type, <a href="hilog.md#gaca1fd1d8935433e6ba2e3918214e07f9">LogLevel</a> level, unsigned int domain, const char *tag, const char *fmt,...) __attribute__((format(<a href="io.md#ga98631211a4a8aee62f572375d5b637be">printf</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p188135296165625"><a name="p188135296165625"></a><a name="p188135296165625"></a>int </p>
<p id="p908856552165625"><a name="p908856552165625"></a><a name="p908856552165625"></a>Outputs logs. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1302429224165625"></a>

## **Macro Definition **<a name="section517686992165625"></a>

## HILOG\_DEBUG<a name="ga131e23e4dd8a01f7871851ac23ce3cfc"></a>

```
#define HILOG_DEBUG( type,  ... )   ((void)[HiLogPrint](hilog.md#ga09fb4cb8cda1a4353752964b3ac02c7b)(LOG_CORE, [LOG_DEBUG](hilog.md#ggaca1fd1d8935433e6ba2e3918214e07f9ab9f002c6ffbfd511da8090213227454e), [LOG_DOMAIN](hilog.md#ga95a1d08c807e0aada863b5298a61d08d), [LOG_TAG](hilog.md#ga7ce0df38eb467e59f209470c8f5ac4e6), __VA_ARGS__))
```

 **Description:**

Outputs debug logs. This is a function-like macro. 

Before calling this function, define the log service domain and log tag. Generally, you need to define them at the beginning of the source file. 

**Parameters:**

<a name="table1648191470165625"></a>
<table><thead align="left"><tr id="row1946880758165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p477983596165625"><a name="p477983596165625"></a><a name="p477983596165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1705421369165625"><a name="p1705421369165625"></a><a name="p1705421369165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row968562099165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">type</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the log type. The type for third-party applications is defined by <strong id="b333313544165625"><a name="b333313544165625"></a><a name="b333313544165625"></a>LOG_APP</strong>. </td>
</tr>
<tr id="row1751503051165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fmt</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the format string, which is an enhancement of a printf format string and supports the privacy identifier. Specifically, {public} or {private} is added between the % character and the format specifier in each parameter. </td>
</tr>
<tr id="row545342655165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">...</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates a list of parameters. The number and type of parameters must map onto the format specifiers in the format string. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  or a larger value if the operation is successful; returns a value smaller than  **0**  otherwise. 

**See also:**

[HiLogPrint](hilog.md#ga09fb4cb8cda1a4353752964b3ac02c7b) 

## HILOG\_ERROR<a name="ga90b1019911094577057834ab3208e454"></a>

```
#define HILOG_ERROR( type,  ... )   ((void)[HiLogPrint](hilog.md#ga09fb4cb8cda1a4353752964b3ac02c7b)(LOG_CORE, [LOG_ERROR](hilog.md#ggaca1fd1d8935433e6ba2e3918214e07f9a230506cce5c68c3bac5a821c42ed3473), [LOG_DOMAIN](hilog.md#ga95a1d08c807e0aada863b5298a61d08d), [LOG_TAG](hilog.md#ga7ce0df38eb467e59f209470c8f5ac4e6), __VA_ARGS__))
```

 **Description:**

Outputs error logs. This is a function-like macro. 

Before calling this function, define the log service domain and log tag. Generally, you need to define them at the beginning of the source file. 

**Parameters:**

<a name="table1009112866165625"></a>
<table><thead align="left"><tr id="row1869770561165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p176343827165625"><a name="p176343827165625"></a><a name="p176343827165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p850677039165625"><a name="p850677039165625"></a><a name="p850677039165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1909567700165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">type</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the log type. The type for third-party applications is defined by <strong id="b1516486762165625"><a name="b1516486762165625"></a><a name="b1516486762165625"></a>LOG_APP</strong>. </td>
</tr>
<tr id="row474822615165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fmt</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the format string, which is an enhancement of a printf format string and supports the privacy identifier. Specifically, {public} or {private} is added between the % character and the format specifier in each parameter. </td>
</tr>
<tr id="row1779816607165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">...</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates a list of parameters. The number and type of parameters must map onto the format specifiers in the format string. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  or a larger value if the operation is successful; returns a value smaller than  **0**  otherwise. 

**See also:**

[HiLogPrint](hilog.md#ga09fb4cb8cda1a4353752964b3ac02c7b) 

## HILOG\_FATAL<a name="gac76a098606b7f1e2f73b14158abe0b25"></a>

```
#define HILOG_FATAL( type,  ... )   ((void)[HiLogPrint](hilog.md#ga09fb4cb8cda1a4353752964b3ac02c7b)(LOG_CORE, [LOG_FATAL](hilog.md#ggaca1fd1d8935433e6ba2e3918214e07f9ac630750884d91cb9767ef2200bbb048b), [LOG_DOMAIN](hilog.md#ga95a1d08c807e0aada863b5298a61d08d), [LOG_TAG](hilog.md#ga7ce0df38eb467e59f209470c8f5ac4e6), __VA_ARGS__))
```

 **Description:**

Outputs fatal logs. This is a function-like macro. 

Before calling this function, define the log service domain and log tag. Generally, you need to define them at the beginning of the source file. 

**Parameters:**

<a name="table1555099126165625"></a>
<table><thead align="left"><tr id="row968415533165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1835866044165625"><a name="p1835866044165625"></a><a name="p1835866044165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1963797999165625"><a name="p1963797999165625"></a><a name="p1963797999165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2039463476165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">type</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the log type. The type for third-party applications is defined by <strong id="b1015158671165625"><a name="b1015158671165625"></a><a name="b1015158671165625"></a>LOG_APP</strong>. </td>
</tr>
<tr id="row1890359739165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fmt</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the format string, which is an enhancement of a printf format string and supports the privacy identifier. Specifically, {public} or {private} is added between the % character and the format specifier in each parameter. </td>
</tr>
<tr id="row277273060165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">...</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates a list of parameters. The number and type of parameters must map onto the format specifiers in the format string. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  or a larger value if the operation is successful; returns a value smaller than  **0**  otherwise. 

**See also:**

[HiLogPrint](hilog.md#ga09fb4cb8cda1a4353752964b3ac02c7b) 

## HILOG\_INFO<a name="ga54d6ebdb0a272e51e3dc2e5cc9775677"></a>

```
#define HILOG_INFO( type,  ... )   ((void)[HiLogPrint](hilog.md#ga09fb4cb8cda1a4353752964b3ac02c7b)(LOG_CORE, [LOG_INFO](hilog.md#ggaca1fd1d8935433e6ba2e3918214e07f9a6e98ff471e3ce6c4ef2d75c37ee51837), [LOG_DOMAIN](hilog.md#ga95a1d08c807e0aada863b5298a61d08d), [LOG_TAG](hilog.md#ga7ce0df38eb467e59f209470c8f5ac4e6), __VA_ARGS__))
```

 **Description:**

Outputs informational logs. This is a function-like macro. 

Before calling this function, define the log service domain and log tag. Generally, you need to define them at the beginning of the source file. 

**Parameters:**

<a name="table1599150749165625"></a>
<table><thead align="left"><tr id="row1229647572165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1124835847165625"><a name="p1124835847165625"></a><a name="p1124835847165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p825923679165625"><a name="p825923679165625"></a><a name="p825923679165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row575814504165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">type</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the log type. The type for third-party applications is defined by <strong id="b1652731003165625"><a name="b1652731003165625"></a><a name="b1652731003165625"></a>LOG_APP</strong>. </td>
</tr>
<tr id="row1349029785165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fmt</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the format string, which is an enhancement of a printf format string and supports the privacy identifier. Specifically, {public} or {private} is added between the % character and the format specifier in each parameter. </td>
</tr>
<tr id="row525667472165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">...</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates a list of parameters. The number and type of parameters must map onto the format specifiers in the format string. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  or a larger value if the operation is successful; returns a value smaller than  **0**  otherwise. 

**See also:**

[HiLogPrint](hilog.md#ga09fb4cb8cda1a4353752964b3ac02c7b) 

## HILOG\_WARN<a name="gab6e05f702fa067419ab6d2b241f70d96"></a>

```
#define HILOG_WARN( type,  ... )   ((void)[HiLogPrint](hilog.md#ga09fb4cb8cda1a4353752964b3ac02c7b)(LOG_CORE, [LOG_WARN](hilog.md#ggaca1fd1d8935433e6ba2e3918214e07f9ac8041ffa22bc823d4726701cdb13fc13), [LOG_DOMAIN](hilog.md#ga95a1d08c807e0aada863b5298a61d08d), [LOG_TAG](hilog.md#ga7ce0df38eb467e59f209470c8f5ac4e6), __VA_ARGS__))
```

 **Description:**

Outputs warning logs. This is a function-like macro. 

Before calling this function, define the log service domain and log tag. Generally, you need to define them at the beginning of the source file. 

**Parameters:**

<a name="table247034704165625"></a>
<table><thead align="left"><tr id="row2139174124165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p424118846165625"><a name="p424118846165625"></a><a name="p424118846165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p846271246165625"><a name="p846271246165625"></a><a name="p846271246165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1649397920165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">type</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the log type. The type for third-party applications is defined by <strong id="b218157256165625"><a name="b218157256165625"></a><a name="b218157256165625"></a>LOG_APP</strong>. </td>
</tr>
<tr id="row1831476165165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fmt</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the format string, which is an enhancement of a printf format string and supports the privacy identifier. Specifically, {public} or {private} is added between the % character and the format specifier in each parameter. </td>
</tr>
<tr id="row568891734165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">...</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates a list of parameters. The number and type of parameters must map onto the format specifiers in the format string. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  or a larger value if the operation is successful; returns a value smaller than  **0**  otherwise. 

**See also:**

[HiLogPrint](hilog.md#ga09fb4cb8cda1a4353752964b3ac02c7b) 

## LOG\_DOMAIN<a name="ga95a1d08c807e0aada863b5298a61d08d"></a>

```
#define LOG_DOMAIN   0
```

 **Description:**

Defines the service domain for a log file. 

The service domain is used to identify the subsystem and module of a service. Its value is a hexadecimal integer ranging from 0x0 to 0xFFFFF. If the value is beyond the range, its significant bits are automatically truncated. The recommended format is 0xAAABB, where AAA indicates the subsystem and BB indicates the module. 

## LOG\_TAG<a name="ga7ce0df38eb467e59f209470c8f5ac4e6"></a>

```
#define LOG_TAG   [NULL](utils.md#ga070d2ce7b6bb7e5c05602aa8c308d0c4)
```

 **Description:**

Defines a string constant used to identify the class, file, or service behavior. 

## **Enumeration Type **<a name="section1363762227165625"></a>

## HiLogModuleType<a name="ga125ab0014dcc2b2152e0be2e39e31b9e"></a>

```
enum [HiLogModuleType](hilog.md#ga125ab0014dcc2b2152e0be2e39e31b9e)
```

 **Description:**

Enumerates logging module types. 

The module type must be globally unique. A maximum of 64 module types can be defined.

<a name="table175659934165625"></a>
<table><thead align="left"><tr id="row2029709723165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1930330936165625"><a name="p1930330936165625"></a><a name="p1930330936165625"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1770619026165625"><a name="p1770619026165625"></a><a name="p1770619026165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row227791745165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga125ab0014dcc2b2152e0be2e39e31b9ea6eef5ce03266c8d2f0ef2ff63e86230b"><a name="gga125ab0014dcc2b2152e0be2e39e31b9ea6eef5ce03266c8d2f0ef2ff63e86230b"></a><a name="gga125ab0014dcc2b2152e0be2e39e31b9ea6eef5ce03266c8d2f0ef2ff63e86230b"></a></strong>HILOG_MODULE_HIVIEW </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1173882854165625"><a name="p1173882854165625"></a><a name="p1173882854165625"></a>DFX </p>
 </td>
</tr>
<tr id="row1485837004165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga125ab0014dcc2b2152e0be2e39e31b9eac1f60668255cfb6314d4fb8083f50ea3"><a name="gga125ab0014dcc2b2152e0be2e39e31b9eac1f60668255cfb6314d4fb8083f50ea3"></a><a name="gga125ab0014dcc2b2152e0be2e39e31b9eac1f60668255cfb6314d4fb8083f50ea3"></a></strong>HILOG_MODULE_SAMGR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1408702715165625"><a name="p1408702715165625"></a><a name="p1408702715165625"></a>System Ability Manager </p>
 </td>
</tr>
<tr id="row663228852165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga125ab0014dcc2b2152e0be2e39e31b9ea7dd731467818fc45a8474442af2f3302"><a name="gga125ab0014dcc2b2152e0be2e39e31b9ea7dd731467818fc45a8474442af2f3302"></a><a name="gga125ab0014dcc2b2152e0be2e39e31b9ea7dd731467818fc45a8474442af2f3302"></a></strong>HILOG_MODULE_ACE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1564194444165625"><a name="p1564194444165625"></a><a name="p1564194444165625"></a>Update </p>
 </td>
</tr>
<tr id="row1204810445165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga125ab0014dcc2b2152e0be2e39e31b9ea7194cace682dfd6f7cce00a6a7f96ac3"><a name="gga125ab0014dcc2b2152e0be2e39e31b9ea7194cace682dfd6f7cce00a6a7f96ac3"></a><a name="gga125ab0014dcc2b2152e0be2e39e31b9ea7194cace682dfd6f7cce00a6a7f96ac3"></a></strong>HILOG_MODULE_APP </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1686898085165625"><a name="p1686898085165625"></a><a name="p1686898085165625"></a>Third-party applications </p>
 </td>
</tr>
<tr id="row1978795269165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga125ab0014dcc2b2152e0be2e39e31b9ea746b8468c1657750bf0d5487a3cbbb33"><a name="gga125ab0014dcc2b2152e0be2e39e31b9ea746b8468c1657750bf0d5487a3cbbb33"></a><a name="gga125ab0014dcc2b2152e0be2e39e31b9ea746b8468c1657750bf0d5487a3cbbb33"></a></strong>HILOG_MODULE_MAX </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1985833507165625"><a name="p1985833507165625"></a><a name="p1985833507165625"></a>Maximum number of modules </p>
 </td>
</tr>
</tbody>
</table>

## LogLevel<a name="gaca1fd1d8935433e6ba2e3918214e07f9"></a>

```
enum [LogLevel](hilog.md#gaca1fd1d8935433e6ba2e3918214e07f9)
```

 **Description:**

Enumerates log levels. 

You are advised to select log levels based on their respective usage scenarios: 

 

<a name="table884489364165625"></a>
<table><thead align="left"><tr id="row209529538165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p155098461165625"><a name="p155098461165625"></a><a name="p155098461165625"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1015753185165625"><a name="p1015753185165625"></a><a name="p1015753185165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1423521089165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaca1fd1d8935433e6ba2e3918214e07f9ab9f002c6ffbfd511da8090213227454e"><a name="ggaca1fd1d8935433e6ba2e3918214e07f9ab9f002c6ffbfd511da8090213227454e"></a><a name="ggaca1fd1d8935433e6ba2e3918214e07f9ab9f002c6ffbfd511da8090213227454e"></a></strong>LOG_DEBUG </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p871905316165625"><a name="p871905316165625"></a><a name="p871905316165625"></a>Debug level to be used by <a href="hilog.md#ga131e23e4dd8a01f7871851ac23ce3cfc">HILOG_DEBUG</a> </p>
 </td>
</tr>
<tr id="row1527859860165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaca1fd1d8935433e6ba2e3918214e07f9a6e98ff471e3ce6c4ef2d75c37ee51837"><a name="ggaca1fd1d8935433e6ba2e3918214e07f9a6e98ff471e3ce6c4ef2d75c37ee51837"></a><a name="ggaca1fd1d8935433e6ba2e3918214e07f9a6e98ff471e3ce6c4ef2d75c37ee51837"></a></strong>LOG_INFO </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1267333751165625"><a name="p1267333751165625"></a><a name="p1267333751165625"></a>Informational level to be used by <a href="hilog.md#ga54d6ebdb0a272e51e3dc2e5cc9775677">HILOG_INFO</a> </p>
 </td>
</tr>
<tr id="row1573243961165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaca1fd1d8935433e6ba2e3918214e07f9ac8041ffa22bc823d4726701cdb13fc13"><a name="ggaca1fd1d8935433e6ba2e3918214e07f9ac8041ffa22bc823d4726701cdb13fc13"></a><a name="ggaca1fd1d8935433e6ba2e3918214e07f9ac8041ffa22bc823d4726701cdb13fc13"></a></strong>LOG_WARN </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2051011620165625"><a name="p2051011620165625"></a><a name="p2051011620165625"></a>Warning level to be used by <a href="hilog.md#gab6e05f702fa067419ab6d2b241f70d96">HILOG_WARN</a> </p>
 </td>
</tr>
<tr id="row966828451165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaca1fd1d8935433e6ba2e3918214e07f9a230506cce5c68c3bac5a821c42ed3473"><a name="ggaca1fd1d8935433e6ba2e3918214e07f9a230506cce5c68c3bac5a821c42ed3473"></a><a name="ggaca1fd1d8935433e6ba2e3918214e07f9a230506cce5c68c3bac5a821c42ed3473"></a></strong>LOG_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p342222750165625"><a name="p342222750165625"></a><a name="p342222750165625"></a>Error level to be used by <a href="hilog.md#ga90b1019911094577057834ab3208e454">HILOG_ERROR</a> </p>
 </td>
</tr>
<tr id="row45044138165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaca1fd1d8935433e6ba2e3918214e07f9ac630750884d91cb9767ef2200bbb048b"><a name="ggaca1fd1d8935433e6ba2e3918214e07f9ac630750884d91cb9767ef2200bbb048b"></a><a name="ggaca1fd1d8935433e6ba2e3918214e07f9ac630750884d91cb9767ef2200bbb048b"></a></strong>LOG_FATAL </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1627447380165625"><a name="p1627447380165625"></a><a name="p1627447380165625"></a>Fatal level to be used by <a href="hilog.md#gac76a098606b7f1e2f73b14158abe0b25">HILOG_FATAL</a> </p>
 </td>
</tr>
</tbody>
</table>

## LogType<a name="gaf67907baa897e9fb84df0cb89795b87c"></a>

```
enum [LogType](hilog.md#gaf67907baa897e9fb84df0cb89795b87c)
```

 **Description:**

Enumerates log types. 

Currently,  **LOG\_APP**  is available. 

## **Function **<a name="section2032748084165625"></a>

## HiLogPrint\(\)<a name="ga09fb4cb8cda1a4353752964b3ac02c7b"></a>

```
int HiLogPrint ([LogType](hilog.md#gaf67907baa897e9fb84df0cb89795b87c) type, [LogLevel](hilog.md#gaca1fd1d8935433e6ba2e3918214e07f9) level, unsigned int domain, const char * tag, const char * fmt,  ... )
```

 **Description:**

Outputs logs. 

You can use this function to output logs based on the specified log type, log level, service domain, log tag, and variable parameters determined by the format specifier and privacy identifier in the printf format.

**Parameters:**

<a name="table1139700931165625"></a>
<table><thead align="left"><tr id="row1128441334165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1412077868165625"><a name="p1412077868165625"></a><a name="p1412077868165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1118702480165625"><a name="p1118702480165625"></a><a name="p1118702480165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1332655659165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">type</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the log type. The type for third-party applications is defined by <strong id="b90313698165625"><a name="b90313698165625"></a><a name="b90313698165625"></a>LOG_APP</strong>. </td>
</tr>
<tr id="row1331278393165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">level</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the log level, which can be <strong id="b1526672122165625"><a name="b1526672122165625"></a><a name="b1526672122165625"></a>LOG_DEBUG</strong>, <strong id="b633846163165625"><a name="b633846163165625"></a><a name="b633846163165625"></a>LOG_INFO</strong>, <strong id="b2045988830165625"><a name="b2045988830165625"></a><a name="b2045988830165625"></a>LOG_WARN</strong>, <strong id="b471686893165625"><a name="b471686893165625"></a><a name="b471686893165625"></a>LOG_ERROR</strong>, and <strong id="b982994027165625"><a name="b982994027165625"></a><a name="b982994027165625"></a>LOG_FATAL</strong>. </td>
</tr>
<tr id="row738264670165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">domain</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the service domain of logs. Its value is a hexadecimal integer ranging from 0x0 to 0xFFFFF. The recommended format is 0xAAABB, where AAA indicates the subsystem and BB indicates the module. </td>
</tr>
<tr id="row399916305165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">tag</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the log tag, which is a string used to identify the class, file, or service behavior. </td>
</tr>
<tr id="row1188955254165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fmt</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the format string, which is an enhancement of a printf format string and supports the privacy identifier. Specifically, {public} or {private} is added between the % character and the format specifier in each parameter. </td>
</tr>
<tr id="row1647853973165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">...</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates a list of parameters. The number and type of parameters must map onto the format specifiers in the format string. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  or a larger value if the operation is successful; returns a value smaller than  **0**  otherwise. 

