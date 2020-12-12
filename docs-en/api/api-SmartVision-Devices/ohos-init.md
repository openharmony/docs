# OHOS Init<a name="EN-US_TOPIC_0000001054598113"></a>

-   [Overview](#section109641664165625)
-   [Summary](#section769899064165625)
-   [Files](#files)
-   [Macros](#define-members)
-   [Details](#section1795684416165625)
-   [Macro Definition](#section1830576969165625)
-   [APP\_FEATURE\_INIT](#ga6ae79099e42a2ee7680cc9d5ae4817d6)
-   [APP\_FEATURE\_INIT\_PRI](#ga16168eb42790a913932f1ebd92a76fc1)
-   [APP\_SERVICE\_INIT](#gacd89f8f7d2c1e7490ae285f99f3a9d42)
-   [APP\_SERVICE\_INIT\_PRI](#gac678e25b6b7d9949220139741ffa4233)
-   [CORE\_INIT](#ga97a9cae685c8fe08b3ed438c4de4419d)
-   [CORE\_INIT\_PRI](#ga028481fe849c821d876df662158d5122)
-   [SYS\_FEATURE\_INIT](#ga0ade3a78723c48748ae5fbbb261538a2)
-   [SYS\_FEATURE\_INIT\_PRI](#ga561c8a47e7b929c7300a0c2acb458459)
-   [SYS\_RUN](#gaa6d9a034e9ee034240a023e8cb9c2c78)
-   [SYS\_RUN\_PRI](#ga2371a43afede3e4840893448c9f97843)
-   [SYS\_SERVICE\_INIT](#gaeecafaa1e903880d1d8570dc6b09aec7)
-   [SYS\_SERVICE\_INIT\_PRI](#ga8200637c1413a8ddfb2997668d325ba7)
-   [SYSEX\_FEATURE\_INIT](#ga7e321122cb4bfc41bfd266c39108e7c0)
-   [SYSEX\_FEATURE\_INIT\_PRI](#gabb08dfd40bae014ab94f4a3a0ff2180b)
-   [SYSEX\_SERVICE\_INIT](#ga0e8322b3ab1975d234bd7275b79ed7eb)
-   [SYSEX\_SERVICE\_INIT\_PRI](#gae0c14aff58448d4a428ad55cfee7c89b)

## **Overview**<a name="section109641664165625"></a>

**Description:**

Provides the entries for initializing and starting services and features. 

This module provides the entries for initializing services and features during service development. Services and features are initialized in the following sequence: core phase, core system service, core system feature, system startup, system service, system feature, application-layer service, and application-layer feature. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section769899064165625"></a>

## Files<a name="files"></a>

<a name="table68102638165625"></a>
<table><thead align="left"><tr id="row551989073165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1032049313165625"><a name="p1032049313165625"></a><a name="p1032049313165625"></a>File Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p496121825165625"><a name="p496121825165625"></a><a name="p496121825165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1719301561165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1807525987165625"><a name="p1807525987165625"></a><a name="p1807525987165625"></a><a href="ohos_init-h.md">ohos_init.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p885101315165625"><a name="p885101315165625"></a><a name="p885101315165625"></a>Provides the entries for initializing and starting services and features. </p>
</td>
</tr>
</tbody>
</table>

## Macros<a name="define-members"></a>

<a name="table844808036165625"></a>
<table><thead align="left"><tr id="row963344429165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p754914556165625"><a name="p754914556165625"></a><a name="p754914556165625"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p270622536165625"><a name="p270622536165625"></a><a name="p270622536165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1662319815165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1381584221165625"><a name="p1381584221165625"></a><a name="p1381584221165625"></a><a href="ohos-init.md#ga97a9cae685c8fe08b3ed438c4de4419d">CORE_INIT</a>(func)   LAYER_INITCALL_DEF(func, core, "core")</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2721876165625"><a name="p2721876165625"></a><a name="p2721876165625"></a>Identifies the entry for initializing and starting a core phase by the priority 2. </p>
</td>
</tr>
<tr id="row1182110502165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1073135620165625"><a name="p1073135620165625"></a><a name="p1073135620165625"></a><a href="ohos-init.md#ga028481fe849c821d876df662158d5122">CORE_INIT_PRI</a>(func, priority)   LAYER_INITCALL(func, core, "core", priority)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1516775129165625"><a name="p1516775129165625"></a><a name="p1516775129165625"></a>Identifies the entry for initializing and starting a core phase by the specified priority. </p>
</td>
</tr>
<tr id="row347611841165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p943469280165625"><a name="p943469280165625"></a><a name="p943469280165625"></a><a href="ohos-init.md#gaeecafaa1e903880d1d8570dc6b09aec7">SYS_SERVICE_INIT</a>(func)   LAYER_INITCALL_DEF(func, sys_service, "sys.service")</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p42160993165625"><a name="p42160993165625"></a><a name="p42160993165625"></a>Identifies the entry for initializing and starting a core system service by the priority 2. </p>
</td>
</tr>
<tr id="row1973714655165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1322788327165625"><a name="p1322788327165625"></a><a name="p1322788327165625"></a><a href="ohos-init.md#ga8200637c1413a8ddfb2997668d325ba7">SYS_SERVICE_INIT_PRI</a>(func, priority)   LAYER_INITCALL(func, sys_service, "sys.service", priority)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1559307224165625"><a name="p1559307224165625"></a><a name="p1559307224165625"></a>Identifies the entry for initializing and starting a core system service by the specified priority. </p>
</td>
</tr>
<tr id="row580262002165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1629194605165625"><a name="p1629194605165625"></a><a name="p1629194605165625"></a><a href="ohos-init.md#ga0ade3a78723c48748ae5fbbb261538a2">SYS_FEATURE_INIT</a>(func)   LAYER_INITCALL_DEF(func, sys_feature, "sys.feature")</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1284805776165625"><a name="p1284805776165625"></a><a name="p1284805776165625"></a>Identifies the entry for initializing and starting a core system feature by the priority 2. </p>
</td>
</tr>
<tr id="row1238795168165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p869362569165625"><a name="p869362569165625"></a><a name="p869362569165625"></a><a href="ohos-init.md#ga561c8a47e7b929c7300a0c2acb458459">SYS_FEATURE_INIT_PRI</a>(func, priority)   LAYER_INITCALL(func, sys_feature, "sys.feature", priority)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1134569837165625"><a name="p1134569837165625"></a><a name="p1134569837165625"></a>Identifies the entry for initializing and starting a core system feature by the specified priority. </p>
</td>
</tr>
<tr id="row183589750165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1620235675165625"><a name="p1620235675165625"></a><a name="p1620235675165625"></a><a href="ohos-init.md#gaa6d9a034e9ee034240a023e8cb9c2c78">SYS_RUN</a>(func)   LAYER_INITCALL_DEF(func, run, "run")</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1932476261165625"><a name="p1932476261165625"></a><a name="p1932476261165625"></a>Identifies the entry for initializing and starting a system running phase by the priority 2. </p>
</td>
</tr>
<tr id="row1719168936165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1134832446165625"><a name="p1134832446165625"></a><a name="p1134832446165625"></a><a href="ohos-init.md#ga2371a43afede3e4840893448c9f97843">SYS_RUN_PRI</a>(func, priority)   LAYER_INITCALL(func, run, "run", priority)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1140083152165625"><a name="p1140083152165625"></a><a name="p1140083152165625"></a>Identifies the entry for initializing and starting a system running phase by the specified priority. </p>
</td>
</tr>
<tr id="row631033020165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p129008545165625"><a name="p129008545165625"></a><a name="p129008545165625"></a><a href="ohos-init.md#ga0e8322b3ab1975d234bd7275b79ed7eb">SYSEX_SERVICE_INIT</a>(func)   LAYER_INITCALL_DEF(func, app_service, "app.service")</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p263141842165625"><a name="p263141842165625"></a><a name="p263141842165625"></a>Identifies the entry for initializing and starting a system service by the priority 2. </p>
</td>
</tr>
<tr id="row1013657097165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p213443354165625"><a name="p213443354165625"></a><a name="p213443354165625"></a><a href="ohos-init.md#gae0c14aff58448d4a428ad55cfee7c89b">SYSEX_SERVICE_INIT_PRI</a>(func, priority)   LAYER_INITCALL(func, app_service, "app.service", priority)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1420788337165625"><a name="p1420788337165625"></a><a name="p1420788337165625"></a>Identifies the entry for initializing and starting a system service by the specified priority. </p>
</td>
</tr>
<tr id="row1067128398165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1714642659165625"><a name="p1714642659165625"></a><a name="p1714642659165625"></a><a href="ohos-init.md#ga7e321122cb4bfc41bfd266c39108e7c0">SYSEX_FEATURE_INIT</a>(func)   LAYER_INITCALL_DEF(func, app_feature, "app.feature")</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p629382795165625"><a name="p629382795165625"></a><a name="p629382795165625"></a>Identifies the entry for initializing and starting a system feature by the priority 2. </p>
</td>
</tr>
<tr id="row902106022165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1973162043165625"><a name="p1973162043165625"></a><a name="p1973162043165625"></a><a href="ohos-init.md#gabb08dfd40bae014ab94f4a3a0ff2180b">SYSEX_FEATURE_INIT_PRI</a>(func, priority)   LAYER_INITCALL(func, app_feature, "app.feature", priority)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p345036971165625"><a name="p345036971165625"></a><a name="p345036971165625"></a>Identifies the entry for initializing and starting a system feature by the specified priority. </p>
</td>
</tr>
<tr id="row792799894165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1987573276165625"><a name="p1987573276165625"></a><a name="p1987573276165625"></a><a href="ohos-init.md#gacd89f8f7d2c1e7490ae285f99f3a9d42">APP_SERVICE_INIT</a>(func)   LAYER_INITCALL_DEF(func, app_service, "app.service")</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1005501432165625"><a name="p1005501432165625"></a><a name="p1005501432165625"></a>Identifies the entry for initializing and starting an application-layer service by the priority 2. </p>
</td>
</tr>
<tr id="row492862519165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p930588504165625"><a name="p930588504165625"></a><a name="p930588504165625"></a><a href="ohos-init.md#gac678e25b6b7d9949220139741ffa4233">APP_SERVICE_INIT_PRI</a>(func, priority)   LAYER_INITCALL(func, app_service, "app.service", priority)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1477880014165625"><a name="p1477880014165625"></a><a name="p1477880014165625"></a>Identifies the entry for initializing and starting an application-layer service by the specified priority. </p>
</td>
</tr>
<tr id="row1873240796165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1126933564165625"><a name="p1126933564165625"></a><a name="p1126933564165625"></a><a href="ohos-init.md#ga6ae79099e42a2ee7680cc9d5ae4817d6">APP_FEATURE_INIT</a>(func)   LAYER_INITCALL_DEF(func, app_feature, "app.feature")</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1219120530165625"><a name="p1219120530165625"></a><a name="p1219120530165625"></a>Identifies the entry for initializing and starting an application-layer feature by the priority 2. </p>
</td>
</tr>
<tr id="row1716280158165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1425691037165625"><a name="p1425691037165625"></a><a name="p1425691037165625"></a><a href="ohos-init.md#ga16168eb42790a913932f1ebd92a76fc1">APP_FEATURE_INIT_PRI</a>(func, priority)   LAYER_INITCALL(func, app_feature, "app.feature", priority)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p92447699165625"><a name="p92447699165625"></a><a name="p92447699165625"></a>Identifies the entry for initializing and starting an application-layer feature by the specified priority. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1795684416165625"></a>

## **Macro Definition **<a name="section1830576969165625"></a>

## APP\_FEATURE\_INIT<a name="ga6ae79099e42a2ee7680cc9d5ae4817d6"></a>

```
#define APP_FEATURE_INIT( func)   LAYER_INITCALL_DEF(func, app_feature, "app.feature")
```

 **Description:**

Identifies the entry for initializing and starting an application-layer feature by the priority 2. 

This macro is used to identify the entry called at the priority 2 of the application-layer feature phase of the startup process. 

**Parameters:**

<a name="table773232577165625"></a>
<table><thead align="left"><tr id="row1136062675165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1765734176165625"><a name="p1765734176165625"></a><a name="p1765734176165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1491578324165625"><a name="p1491578324165625"></a><a name="p1491578324165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row281673849165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">func</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the entry function for initializing and starting an application-layer feature. The type is void (*)(void). </td>
</tr>
</tbody>
</table>

## APP\_FEATURE\_INIT\_PRI<a name="ga16168eb42790a913932f1ebd92a76fc1"></a>

```
#define APP_FEATURE_INIT_PRI( func,  priority )   LAYER_INITCALL(func, app_feature, "app.feature", priority)
```

 **Description:**

Identifies the entry for initializing and starting an application-layer feature by the specified priority. 

This macro is used to identify the entry called at the specified priority of the application-layer feature phase of the startup process. 

**Parameters:**

<a name="table1242931431165625"></a>
<table><thead align="left"><tr id="row1044682837165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1674625315165625"><a name="p1674625315165625"></a><a name="p1674625315165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p875706886165625"><a name="p875706886165625"></a><a name="p875706886165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row784486620165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">func</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the entry function for initializing and starting an application-layer feature. The type is void (*)(void). </td>
</tr>
<tr id="row1018642209165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">priority</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the calling priority when starting the application-layer feature. The value range is [0, 5), and the calling sequence is 0, 1, 2, 3, and 4. </td>
</tr>
</tbody>
</table>

## APP\_SERVICE\_INIT<a name="gacd89f8f7d2c1e7490ae285f99f3a9d42"></a>

```
#define APP_SERVICE_INIT( func)   LAYER_INITCALL_DEF(func, app_service, "app.service")
```

 **Description:**

Identifies the entry for initializing and starting an application-layer service by the priority 2. 

This macro is used to identify the entry called at the priority 2 of the application-layer service phase of the startup process. 

**Parameters:**

<a name="table626023728165625"></a>
<table><thead align="left"><tr id="row2006465383165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p158154067165625"><a name="p158154067165625"></a><a name="p158154067165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p946272506165625"><a name="p946272506165625"></a><a name="p946272506165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1153508322165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">func</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the entry function for initializing and starting an application-layer service. The type is void (*)(void). </td>
</tr>
</tbody>
</table>

## APP\_SERVICE\_INIT\_PRI<a name="gac678e25b6b7d9949220139741ffa4233"></a>

```
#define APP_SERVICE_INIT_PRI( func,  priority )   LAYER_INITCALL(func, app_service, "app.service", priority)
```

 **Description:**

Identifies the entry for initializing and starting an application-layer service by the specified priority. 

This macro is used to identify the entry called at the specified priority of the application-layer service phase of the startup process. 

**Parameters:**

<a name="table2021263907165625"></a>
<table><thead align="left"><tr id="row743344948165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p387690191165625"><a name="p387690191165625"></a><a name="p387690191165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1374235569165625"><a name="p1374235569165625"></a><a name="p1374235569165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row982252775165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">func</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the entry function for initializing and starting an application-layer service. The type is void (*)(void). </td>
</tr>
<tr id="row565267557165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">priority</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the calling priority when starting the application-layer service phase. The value range is [0,5), and the calling sequence is 0, 1, 2, 3, and 4. </td>
</tr>
</tbody>
</table>

## CORE\_INIT<a name="ga97a9cae685c8fe08b3ed438c4de4419d"></a>

```
#define CORE_INIT( func)   LAYER_INITCALL_DEF(func, core, "core")
```

 **Description:**

Identifies the entry for initializing and starting a core phase by the priority 2. 

This macro is used when Samgr is initialized and started. This macro is used to identify the entry called at the priority 2 of the core phase of the startup process. 

**Parameters:**

<a name="table832376611165625"></a>
<table><thead align="left"><tr id="row1536212302165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1417812611165625"><a name="p1417812611165625"></a><a name="p1417812611165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1989529422165625"><a name="p1989529422165625"></a><a name="p1989529422165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1233696898165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">func</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the entry function for initializing and starting a core phase. The type is void (*)(void). </td>
</tr>
</tbody>
</table>

## CORE\_INIT\_PRI<a name="ga028481fe849c821d876df662158d5122"></a>

```
#define CORE_INIT_PRI( func,  priority )   LAYER_INITCALL(func, core, "core", priority)
```

 **Description:**

Identifies the entry for initializing and starting a core phase by the specified priority. 

This macro is used when Samgr is initialized and started. This macro is used to identify the entry called at the specified priority of the core phase of the startup process. 

**Parameters:**

<a name="table453606124165625"></a>
<table><thead align="left"><tr id="row665247197165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2133615232165625"><a name="p2133615232165625"></a><a name="p2133615232165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1626249666165625"><a name="p1626249666165625"></a><a name="p1626249666165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row645178154165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">func</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the entry function for initializing and starting a core phase. The type is void (*)(void). </td>
</tr>
<tr id="row1771051552165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">priority</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the calling priority when starting the core phase. The value range is [0,5), and the calling sequence is 0, 1, 2, 3, and 4. </td>
</tr>
</tbody>
</table>

## SYS\_FEATURE\_INIT<a name="ga0ade3a78723c48748ae5fbbb261538a2"></a>

```
#define SYS_FEATURE_INIT( func)   LAYER_INITCALL_DEF(func, sys_feature, "sys.feature")
```

 **Description:**

Identifies the entry for initializing and starting a core system feature by the priority 2. 

This macro is used to identify the entry called at the priority 2 in the core system feature phase of the startup process. 

**Parameters:**

<a name="table1478140980165625"></a>
<table><thead align="left"><tr id="row828916762165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1021207221165625"><a name="p1021207221165625"></a><a name="p1021207221165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1690664080165625"><a name="p1690664080165625"></a><a name="p1690664080165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row104787392165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">func</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the entry function for initializing and starting a core system service. The type is void (*)(void). </td>
</tr>
</tbody>
</table>

## SYS\_FEATURE\_INIT\_PRI<a name="ga561c8a47e7b929c7300a0c2acb458459"></a>

```
#define SYS_FEATURE_INIT_PRI( func,  priority )   LAYER_INITCALL(func, sys_feature, "sys.feature", priority)
```

 **Description:**

Identifies the entry for initializing and starting a core system feature by the specified priority. 

This macro is used to identify the entry called at the specified priority in the core system feature phase of the startup process. 

**Parameters:**

<a name="table1330485379165625"></a>
<table><thead align="left"><tr id="row21837847165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1508690428165625"><a name="p1508690428165625"></a><a name="p1508690428165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1700448761165625"><a name="p1700448761165625"></a><a name="p1700448761165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row441090689165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">func</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the entry function for initializing and starting a core system feature. The type is void (*)(void). </td>
</tr>
<tr id="row2082458690165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">priority</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the calling priority when starting the core system feature phase. The value range is [0, 5), and the calling sequence is 0, 1, 2, 3, and 4. </td>
</tr>
</tbody>
</table>

## SYS\_RUN<a name="gaa6d9a034e9ee034240a023e8cb9c2c78"></a>

```
#define SYS_RUN( func)   LAYER_INITCALL_DEF(func, run, "run")
```

 **Description:**

Identifies the entry for initializing and starting a system running phase by the priority 2. 

This macro is used to identify the entry called at the priority 2 in the system startup phase of the startup process. 

**Parameters:**

<a name="table168794009165625"></a>
<table><thead align="left"><tr id="row764189478165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1026879182165625"><a name="p1026879182165625"></a><a name="p1026879182165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2024444812165625"><a name="p2024444812165625"></a><a name="p2024444812165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1282138329165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">func</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the entry function for initializing and starting a system running phase. The type is void (*)(void). </td>
</tr>
</tbody>
</table>

## SYS\_RUN\_PRI<a name="ga2371a43afede3e4840893448c9f97843"></a>

```
#define SYS_RUN_PRI( func,  priority )   LAYER_INITCALL(func, run, "run", priority)
```

 **Description:**

Identifies the entry for initializing and starting a system running phase by the specified priority. 

This macro is used to identify the entry called at the specified priority in the system startup phase of the startup process. 

**Parameters:**

<a name="table441030821165625"></a>
<table><thead align="left"><tr id="row1233221984165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1448530696165625"><a name="p1448530696165625"></a><a name="p1448530696165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2018635545165625"><a name="p2018635545165625"></a><a name="p2018635545165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row456061399165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">func</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the entry function for initializing and starting a system running phase. The type is void (*)(void). </td>
</tr>
<tr id="row1964723004165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">priority</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the calling priority when starting the system startup phase. The value range is [0, 5), and the calling sequence is 0, 1, 2, 3, and 4. </td>
</tr>
</tbody>
</table>

## SYS\_SERVICE\_INIT<a name="gaeecafaa1e903880d1d8570dc6b09aec7"></a>

```
#define SYS_SERVICE_INIT( func)   LAYER_INITCALL_DEF(func, sys_service, "sys.service")
```

 **Description:**

Identifies the entry for initializing and starting a core system service by the priority 2. 

This macro is used to identify the entry called at the priority 2 in the core system service phase of the startup process. 

**Parameters:**

<a name="table1840946931165625"></a>
<table><thead align="left"><tr id="row2104579398165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p101858368165625"><a name="p101858368165625"></a><a name="p101858368165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1362653010165625"><a name="p1362653010165625"></a><a name="p1362653010165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1420398048165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">func</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the entry function for initializing and starting a core system service. The type is void (*)(void). </td>
</tr>
</tbody>
</table>

## SYS\_SERVICE\_INIT\_PRI<a name="ga8200637c1413a8ddfb2997668d325ba7"></a>

```
#define SYS_SERVICE_INIT_PRI( func,  priority )   LAYER_INITCALL(func, sys_service, "sys.service", priority)
```

 **Description:**

Identifies the entry for initializing and starting a core system service by the specified priority. 

This macro is used to identify the entry called at the specified priority in the core system service phase of the startup process. 

**Parameters:**

<a name="table804858476165625"></a>
<table><thead align="left"><tr id="row570460431165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p820173254165625"><a name="p820173254165625"></a><a name="p820173254165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p667462544165625"><a name="p667462544165625"></a><a name="p667462544165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1376741419165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">func</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the entry function for initializing and starting a core system service. The type is void (*)(void). </td>
</tr>
<tr id="row814924915165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">priority</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the calling priority when starting the core system service in the startup phase. The value range is [0,5), and the calling sequence is 0, 1, 2, 3, and 4. </td>
</tr>
</tbody>
</table>

## SYSEX\_FEATURE\_INIT<a name="ga7e321122cb4bfc41bfd266c39108e7c0"></a>

```
#define SYSEX_FEATURE_INIT( func)   LAYER_INITCALL_DEF(func, app_feature, "app.feature")
```

 **Description:**

Identifies the entry for initializing and starting a system feature by the priority 2. 

This macro is used to identify the entry called at the priority 2 of the system feature phase of the startup process. 

**Parameters:**

<a name="table1414008254165625"></a>
<table><thead align="left"><tr id="row167433932165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p583180723165625"><a name="p583180723165625"></a><a name="p583180723165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1576237708165625"><a name="p1576237708165625"></a><a name="p1576237708165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row711830695165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">func</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the entry function for initializing and starting a system feature. The type is void (*)(void). </td>
</tr>
</tbody>
</table>

## SYSEX\_FEATURE\_INIT\_PRI<a name="gabb08dfd40bae014ab94f4a3a0ff2180b"></a>

```
#define SYSEX_FEATURE_INIT_PRI( func,  priority )   LAYER_INITCALL(func, app_feature, "app.feature", priority)
```

 **Description:**

Identifies the entry for initializing and starting a system feature by the specified priority. 

This macro is used to identify the entry called at the specified priority of the system feature phase of the startup process. 

**Parameters:**

<a name="table263236966165625"></a>
<table><thead align="left"><tr id="row1635503233165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p330802179165625"><a name="p330802179165625"></a><a name="p330802179165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1401900169165625"><a name="p1401900169165625"></a><a name="p1401900169165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1152522068165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">func</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the entry function for initializing and starting a system feature. The type is void (*)(void). </td>
</tr>
<tr id="row1110764553165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">priority</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the calling priority when starting the system feature phase. The value range is [0,5), and the calling sequence is 0, 1, 2, 3, and 4. </td>
</tr>
</tbody>
</table>

## SYSEX\_SERVICE\_INIT<a name="ga0e8322b3ab1975d234bd7275b79ed7eb"></a>

```
#define SYSEX_SERVICE_INIT( func)   LAYER_INITCALL_DEF(func, app_service, "app.service")
```

 **Description:**

Identifies the entry for initializing and starting a system service by the priority 2. 

This macro is used to identify the entry called at the priority 2 in the system service phase of the startup process. 

**Parameters:**

<a name="table1928416183165625"></a>
<table><thead align="left"><tr id="row516964476165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1108012000165625"><a name="p1108012000165625"></a><a name="p1108012000165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1413962454165625"><a name="p1413962454165625"></a><a name="p1413962454165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row643392608165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">func</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the entry function for initializing and starting a system service. The type is void (*)(void). </td>
</tr>
</tbody>
</table>

## SYSEX\_SERVICE\_INIT\_PRI<a name="gae0c14aff58448d4a428ad55cfee7c89b"></a>

```
#define SYSEX_SERVICE_INIT_PRI( func,  priority )   LAYER_INITCALL(func, app_service, "app.service", priority)
```

 **Description:**

Identifies the entry for initializing and starting a system service by the specified priority. 

This macro is used to identify the entry called at the specified priority of the system service phase of the startup process. 

**Parameters:**

<a name="table1680837148165625"></a>
<table><thead align="left"><tr id="row1381299546165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p148712322165625"><a name="p148712322165625"></a><a name="p148712322165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1468887846165625"><a name="p1468887846165625"></a><a name="p1468887846165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row493340163165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">func</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the entry function for initializing and starting a system service. The type is void (*)(void). </td>
</tr>
<tr id="row1372269933165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">priority</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the calling priority when starting the system service phase. The value range is [0,5), and the calling sequence is 0, 1, 2, 3, and 4. </td>
</tr>
</tbody>
</table>

