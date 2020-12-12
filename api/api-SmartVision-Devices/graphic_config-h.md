# graphic\_config.h<a name="ZH-CN_TOPIC_0000001054479531"></a>

-   [Overview](#section1314542427165627)
-   [Summary](#section1517014108165627)
-   [Macros](#define-members)

## **Overview**<a name="section1314542427165627"></a>

**Related Modules:**

[Graphic](Graphic.md)

**Description:**

Provides configuration items required for graphics. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1517014108165627"></a>

## Macros<a name="define-members"></a>

<a name="table1833721151165627"></a>
<table><thead align="left"><tr id="row2127019981165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1310108831165627"><a name="p1310108831165627"></a><a name="p1310108831165627"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p575015380165627"><a name="p575015380165627"></a><a name="p575015380165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1298324644165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2144205150165627"><a name="p2144205150165627"></a><a name="p2144205150165627"></a><a href="Graphic.md#ga2017774de578acba5afd77793c00205b">VERSION_STANDARD</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">&nbsp;</td>
</tr>
<tr id="row2128043994165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1178634449165627"><a name="p1178634449165627"></a><a name="p1178634449165627"></a><a href="Graphic.md#ga3d83acf19f4d5c59f7a29b6b29440dd2">ENABLE_DMA2D</a>   0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1783119789165627"><a name="p1783119789165627"></a><a name="p1783119789165627"></a>DMA2D hardware acceleration, which does not take effect on other platforms. </p>
</td>
</tr>
<tr id="row334510453165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1376354225165627"><a name="p1376354225165627"></a><a name="p1376354225165627"></a><a href="Graphic.md#gaef5d32e398c657450011db566a5fad04">ENABLE_DMA2D_TEXT</a>   0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1748790084165627"><a name="p1748790084165627"></a><a name="p1748790084165627"></a>DMA2D hardware acceleration for font rendering, which does not take effect on other platforms. </p>
</td>
</tr>
<tr id="row589548781165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p487363737165627"><a name="p487363737165627"></a><a name="p487363737165627"></a><a href="Graphic.md#ga1a28113245f31cacd0afacc80c7d12c1">ENABLE_ICU</a>   0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p117268500165627"><a name="p117268500165627"></a><a name="p117268500165627"></a>Advanced algorithm for line breaks, which is disabled by default on other platforms. </p>
</td>
</tr>
<tr id="row523720970165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2105397765165627"><a name="p2105397765165627"></a><a name="p2105397765165627"></a><a href="Graphic.md#ga8fffdbb807e226013ce790500b5c88e2">ENABLE_WINDOW</a>   1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p603820378165627"><a name="p603820378165627"></a><a name="p603820378165627"></a>Multi-window, which is enabled by default on other platforms. </p>
</td>
</tr>
<tr id="row954186149165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p89997510165627"><a name="p89997510165627"></a><a name="p89997510165627"></a><a href="Graphic.md#gaf319cb3be43a211a63f2ea97a1c3ae6d">ENABLE_FRAME_BUFFER</a>   0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2030381607165627"><a name="p2030381607165627"></a><a name="p2030381607165627"></a>Display buffer for rendering data refresh, which is disabled by default on other platforms. </p>
</td>
</tr>
<tr id="row1538943176165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2138919145165627"><a name="p2138919145165627"></a><a name="p2138919145165627"></a><a href="Graphic.md#ga2c3acabc94a483bd191a250f67c1f43b">ENABLE_VECTOR_FONT</a>   1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1592882793165627"><a name="p1592882793165627"></a><a name="p1592882793165627"></a>Vector type font，which is enabled by default on other platforms. </p>
</td>
</tr>
<tr id="row103705111165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1045405747165627"><a name="p1045405747165627"></a><a name="p1045405747165627"></a><a href="Graphic.md#ga8f198e8500b353e58b618b331f768f27">ENABLE_BUFFER_RGBA</a>   1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2070701025165627"><a name="p2070701025165627"></a><a name="p2070701025165627"></a>Graphics bottom-layer RGBA, which is enabled by default. </p>
</td>
</tr>
<tr id="row961675755165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1045753888165627"><a name="p1045753888165627"></a><a name="p1045753888165627"></a><a href="Graphic.md#ga8508eb8cc5346dbdc552a9fbc11dbb06">ENABLE_HARDWARE_ACCELERATION</a>   1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p95796057165627"><a name="p95796057165627"></a><a name="p95796057165627"></a>Graphics rendering hardware acceleration, which is enabled by default. </p>
</td>
</tr>
<tr id="row1919175913165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2112187345165627"><a name="p2112187345165627"></a><a name="p2112187345165627"></a><a href="Graphic.md#ga432138093c53d7580af9ec5c5dca387f">ENABLE_DEBUG</a>   1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p826536077165627"><a name="p826536077165627"></a><a name="p826536077165627"></a>Debug mode, which is disabled by default. </p>
</td>
</tr>
<tr id="row87656024165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1678071970165627"><a name="p1678071970165627"></a><a name="p1678071970165627"></a><a href="Graphic.md#gaa492b15de59b36af68c10a65952dc870">ENABLE_MEMORY_HOOKS</a>   0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1775467866165627"><a name="p1775467866165627"></a><a name="p1775467866165627"></a>Memory hook, which is enabled by default. The system memory allocation is taken over after it is enabled. </p>
</td>
</tr>
<tr id="row1234529497165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p153064894165627"><a name="p153064894165627"></a><a name="p153064894165627"></a><a href="Graphic.md#ga4c1dffa1615941394d376b12a8fbdf24">ENABLE_FPS_SUPPORT</a>   0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1410584079165627"><a name="p1410584079165627"></a><a name="p1410584079165627"></a>Function for monitoring the image refresh frame rate, which is disabled by default. </p>
</td>
</tr>
<tr id="row2129356032165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1916519213165627"><a name="p1916519213165627"></a><a name="p1916519213165627"></a><a href="Graphic.md#ga2e63917ecfb73182bcea30104c497bc9">ENABLE_ANTIALIAS</a>   1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2118814902165627"><a name="p2118814902165627"></a><a name="p2118814902165627"></a>Anti-aliasing, which is enabled by default. </p>
</td>
</tr>
<tr id="row1674109372165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p915575095165627"><a name="p915575095165627"></a><a name="p915575095165627"></a><a href="Graphic.md#gaade33b264d4ea661ff8f36976908b4ba">ENABLE_RECT_ANTIALIAS</a>   0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p93007716165627"><a name="p93007716165627"></a><a name="p93007716165627"></a><a href="Rectangle.md">Rectangle</a> anti-aliasing, which is disabled by default. </p>
</td>
</tr>
<tr id="row1743144088165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1081746680165627"><a name="p1081746680165627"></a><a name="p1081746680165627"></a><a href="Graphic.md#ga733acdcb7c5872a7b864ae108cd86413">ENABLE_SPEC_FONT</a>   0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p929256039165627"><a name="p929256039165627"></a><a name="p929256039165627"></a>Font color mode, which is disabled by default. After it is enabled, the font color mode is set to <strong id="b1010435670165627"><a name="b1010435670165627"></a><a name="b1010435670165627"></a>4</strong> to accelerate font rendering. </p>
</td>
</tr>
<tr id="row1320496684165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p471292372165627"><a name="p471292372165627"></a><a name="p471292372165627"></a><a href="Graphic.md#ga703e1a14b7cccc8074986836c5c1de02">ENABLE_GRAPHIC_LOG</a>   0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p779972321165627"><a name="p779972321165627"></a><a name="p779972321165627"></a>Log function of a graphics subsystem, which is disabled by default. </p>
</td>
</tr>
<tr id="row987296809165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1838132591165627"><a name="p1838132591165627"></a><a name="p1838132591165627"></a><a href="Graphic.md#ga31b6586b78d550c8b08abb87c8ae8d0b">ENABLE_AOD</a>   0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p872185699165627"><a name="p872185699165627"></a><a name="p872185699165627"></a>Function for receiving input events in screen-off mode, which is disabled by default. </p>
</td>
</tr>
<tr id="row1349521797165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1065906712165627"><a name="p1065906712165627"></a><a name="p1065906712165627"></a><a href="Graphic.md#gaca8a42c138892758d4d3252dddbd1373">GRAPHIC_LOG_LEVEL</a>   5</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1286402213165627"><a name="p1286402213165627"></a><a name="p1286402213165627"></a>Defines the log level. A smaller value indicates a higher priority. Logs whose priorities are higher than a specified level can be recorded. Log levels: NONE: disabling logs FATAL: fatal level ERROR: error level WARN: warning level INFO: info level DEBUG: debugging level. </p>
</td>
</tr>
<tr id="row1731014433165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p145477811165627"><a name="p145477811165627"></a><a name="p145477811165627"></a><a href="Graphic.md#ga70d330906276a996f7dab090a03ce2a5">COLOR_DEPTH</a>   32</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p917246244165627"><a name="p917246244165627"></a><a name="p917246244165627"></a>Defines the color depth of graphics rendering. The default value is <strong id="b794898166165627"><a name="b794898166165627"></a><a name="b794898166165627"></a>32</strong> bits. The value can be <strong id="b140224092165627"><a name="b140224092165627"></a><a name="b140224092165627"></a>16</strong> or <strong id="b1618367966165627"><a name="b1618367966165627"></a><a name="b1618367966165627"></a>32</strong>. </p>
</td>
</tr>
<tr id="row321553771165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p666515645165627"><a name="p666515645165627"></a><a name="p666515645165627"></a><a href="Graphic.md#ga50fe9a8f2025389ac5e373b572b2f2d2">LAYER_PF_CODE</a>   0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1642145639165627"><a name="p1642145639165627"></a><a name="p1642145639165627"></a>Represents the code number of the layer pixel format. 0: LAYER_PF_ARGB1555 1: LAYER_PF_ARGB8888 Other: LAYER_PF_ARGB8888. </p>
</td>
</tr>
<tr id="row183344528165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1230000804165627"><a name="p1230000804165627"></a><a name="p1230000804165627"></a><a href="Graphic.md#ga78a7a5cd4bd7deb45047b3ca9f088fb6">DEFAULT_VECTOR_FONT_FILENAME</a>   "SourceHanSansSC-Regular.otf"</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1814632262165627"><a name="p1814632262165627"></a><a name="p1814632262165627"></a>Defines the file name of default vector font. </p>
</td>
</tr>
</tbody>
</table>

