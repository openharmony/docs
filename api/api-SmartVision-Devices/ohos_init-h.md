# ohos\_init.h<a name="ZH-CN_TOPIC_0000001055078113"></a>

-   [Overview](#section446760383165628)
-   [Summary](#section1423954258165628)
-   [Macros](#define-members)

## **Overview**<a name="section446760383165628"></a>

**Related Modules:**

[OHOS Init](OHOS-Init.md)

**Description:**

Provides the entries for initializing and starting services and features. 

This file provides the entries for initializing services and features during service development. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1423954258165628"></a>

## Macros<a name="define-members"></a>

<a name="table1844014573165628"></a>
<table><thead align="left"><tr id="row1910596212165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1783331300165628"><a name="p1783331300165628"></a><a name="p1783331300165628"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1157592477165628"><a name="p1157592477165628"></a><a name="p1157592477165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1314013520165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1372688202165628"><a name="p1372688202165628"></a><a name="p1372688202165628"></a><a href="OHOS-Init.md#ga97a9cae685c8fe08b3ed438c4de4419d">CORE_INIT</a>(func)   LAYER_INITCALL_DEF(func, core, "core")</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1322882476165628"><a name="p1322882476165628"></a><a name="p1322882476165628"></a>Identifies the entry for initializing and starting a core phase by the priority 2. </p>
</td>
</tr>
<tr id="row837341741165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1811414338165628"><a name="p1811414338165628"></a><a name="p1811414338165628"></a><a href="OHOS-Init.md#ga028481fe849c821d876df662158d5122">CORE_INIT_PRI</a>(func, priority)   LAYER_INITCALL(func, core, "core", priority)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p832127920165628"><a name="p832127920165628"></a><a name="p832127920165628"></a>Identifies the entry for initializing and starting a core phase by the specified priority. </p>
</td>
</tr>
<tr id="row44864552165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p929895639165628"><a name="p929895639165628"></a><a name="p929895639165628"></a><a href="OHOS-Init.md#gaeecafaa1e903880d1d8570dc6b09aec7">SYS_SERVICE_INIT</a>(func)   LAYER_INITCALL_DEF(func, sys_service, "sys.service")</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1401518380165628"><a name="p1401518380165628"></a><a name="p1401518380165628"></a>Identifies the entry for initializing and starting a core system service by the priority 2. </p>
</td>
</tr>
<tr id="row1624741950165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1677431341165628"><a name="p1677431341165628"></a><a name="p1677431341165628"></a><a href="OHOS-Init.md#ga8200637c1413a8ddfb2997668d325ba7">SYS_SERVICE_INIT_PRI</a>(func, priority)   LAYER_INITCALL(func, sys_service, "sys.service", priority)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1502792000165628"><a name="p1502792000165628"></a><a name="p1502792000165628"></a>Identifies the entry for initializing and starting a core system service by the specified priority. </p>
</td>
</tr>
<tr id="row354866293165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p921222457165628"><a name="p921222457165628"></a><a name="p921222457165628"></a><a href="OHOS-Init.md#ga0ade3a78723c48748ae5fbbb261538a2">SYS_FEATURE_INIT</a>(func)   LAYER_INITCALL_DEF(func, sys_feature, "sys.feature")</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1065702614165628"><a name="p1065702614165628"></a><a name="p1065702614165628"></a>Identifies the entry for initializing and starting a core system feature by the priority 2. </p>
</td>
</tr>
<tr id="row47053387165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1175846533165628"><a name="p1175846533165628"></a><a name="p1175846533165628"></a><a href="OHOS-Init.md#ga561c8a47e7b929c7300a0c2acb458459">SYS_FEATURE_INIT_PRI</a>(func, priority)   LAYER_INITCALL(func, sys_feature, "sys.feature", priority)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1702547607165628"><a name="p1702547607165628"></a><a name="p1702547607165628"></a>Identifies the entry for initializing and starting a core system feature by the specified priority. </p>
</td>
</tr>
<tr id="row401138152165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1627235677165628"><a name="p1627235677165628"></a><a name="p1627235677165628"></a><a href="OHOS-Init.md#gaa6d9a034e9ee034240a023e8cb9c2c78">SYS_RUN</a>(func)   LAYER_INITCALL_DEF(func, run, "run")</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p291082090165628"><a name="p291082090165628"></a><a name="p291082090165628"></a>Identifies the entry for initializing and starting a system running phase by the priority 2. </p>
</td>
</tr>
<tr id="row607148218165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2066977438165628"><a name="p2066977438165628"></a><a name="p2066977438165628"></a><a href="OHOS-Init.md#ga2371a43afede3e4840893448c9f97843">SYS_RUN_PRI</a>(func, priority)   LAYER_INITCALL(func, run, "run", priority)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1117341929165628"><a name="p1117341929165628"></a><a name="p1117341929165628"></a>Identifies the entry for initializing and starting a system running phase by the specified priority. </p>
</td>
</tr>
<tr id="row878790109165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1779507720165628"><a name="p1779507720165628"></a><a name="p1779507720165628"></a><a href="OHOS-Init.md#ga0e8322b3ab1975d234bd7275b79ed7eb">SYSEX_SERVICE_INIT</a>(func)   LAYER_INITCALL_DEF(func, app_service, "app.service")</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p12151874165628"><a name="p12151874165628"></a><a name="p12151874165628"></a>Identifies the entry for initializing and starting a system service by the priority 2. </p>
</td>
</tr>
<tr id="row638043908165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1670716318165628"><a name="p1670716318165628"></a><a name="p1670716318165628"></a><a href="OHOS-Init.md#gae0c14aff58448d4a428ad55cfee7c89b">SYSEX_SERVICE_INIT_PRI</a>(func, priority)   LAYER_INITCALL(func, app_service, "app.service", priority)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1787022192165628"><a name="p1787022192165628"></a><a name="p1787022192165628"></a>Identifies the entry for initializing and starting a system service by the specified priority. </p>
</td>
</tr>
<tr id="row71172530165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1347928806165628"><a name="p1347928806165628"></a><a name="p1347928806165628"></a><a href="OHOS-Init.md#ga7e321122cb4bfc41bfd266c39108e7c0">SYSEX_FEATURE_INIT</a>(func)   LAYER_INITCALL_DEF(func, app_feature, "app.feature")</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1135942665165628"><a name="p1135942665165628"></a><a name="p1135942665165628"></a>Identifies the entry for initializing and starting a system feature by the priority 2. </p>
</td>
</tr>
<tr id="row1098633161165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1849481936165628"><a name="p1849481936165628"></a><a name="p1849481936165628"></a><a href="OHOS-Init.md#gabb08dfd40bae014ab94f4a3a0ff2180b">SYSEX_FEATURE_INIT_PRI</a>(func, priority)   LAYER_INITCALL(func, app_feature, "app.feature", priority)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1211753165165628"><a name="p1211753165165628"></a><a name="p1211753165165628"></a>Identifies the entry for initializing and starting a system feature by the specified priority. </p>
</td>
</tr>
<tr id="row477919442165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1396006311165628"><a name="p1396006311165628"></a><a name="p1396006311165628"></a><a href="OHOS-Init.md#gacd89f8f7d2c1e7490ae285f99f3a9d42">APP_SERVICE_INIT</a>(func)   LAYER_INITCALL_DEF(func, app_service, "app.service")</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1557395446165628"><a name="p1557395446165628"></a><a name="p1557395446165628"></a>Identifies the entry for initializing and starting an application-layer service by the priority 2. </p>
</td>
</tr>
<tr id="row1213635580165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p614238130165628"><a name="p614238130165628"></a><a name="p614238130165628"></a><a href="OHOS-Init.md#gac678e25b6b7d9949220139741ffa4233">APP_SERVICE_INIT_PRI</a>(func, priority)   LAYER_INITCALL(func, app_service, "app.service", priority)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p949544955165628"><a name="p949544955165628"></a><a name="p949544955165628"></a>Identifies the entry for initializing and starting an application-layer service by the specified priority. </p>
</td>
</tr>
<tr id="row936201173165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p744515108165628"><a name="p744515108165628"></a><a name="p744515108165628"></a><a href="OHOS-Init.md#ga6ae79099e42a2ee7680cc9d5ae4817d6">APP_FEATURE_INIT</a>(func)   LAYER_INITCALL_DEF(func, app_feature, "app.feature")</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p879239619165628"><a name="p879239619165628"></a><a name="p879239619165628"></a>Identifies the entry for initializing and starting an application-layer feature by the priority 2. </p>
</td>
</tr>
<tr id="row1723465332165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p840134691165628"><a name="p840134691165628"></a><a name="p840134691165628"></a><a href="OHOS-Init.md#ga16168eb42790a913932f1ebd92a76fc1">APP_FEATURE_INIT_PRI</a>(func, priority)   LAYER_INITCALL(func, app_feature, "app.feature", priority)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1882536366165628"><a name="p1882536366165628"></a><a name="p1882536366165628"></a>Identifies the entry for initializing and starting an application-layer feature by the specified priority. </p>
</td>
</tr>
</tbody>
</table>

