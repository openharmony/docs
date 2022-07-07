# GfxFuncs<a name="ZH-CN_TOPIC_0000001291040576"></a>

## **概述**<a name="section1130200403083932"></a>

**所属模块:**

[Display](_display.md)

## **汇总**<a name="section585607967083932"></a>

## Public 属性<a name="pub-attribs"></a>

<a name="table2025271588083932"></a>
<table><thead align="left"><tr id="row1728416274083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p685124050083932"><a name="p685124050083932"></a><a name="p685124050083932"></a>Public 属性</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p286393856083932"><a name="p286393856083932"></a><a name="p286393856083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row835561994083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p558254620083932"><a name="p558254620083932"></a><a name="p558254620083932"></a>( <a href="_gfx_funcs.md#a3ec8ed6a467ed0c88e4dd723723c0f41">InitGfx</a> )(void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p407941929083932"><a name="p407941929083932"></a><a name="p407941929083932"></a>初始化硬件加速。 <a href="_gfx_funcs.md#a3ec8ed6a467ed0c88e4dd723723c0f41">更多...</a></p>
</td>
</tr>
<tr id="row1196869413083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p981434764083932"><a name="p981434764083932"></a><a name="p981434764083932"></a>( <a href="_gfx_funcs.md#ad86b127aad2a6e7f01e07b77054d42b3">DeinitGfx</a> )(void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p637172514083932"><a name="p637172514083932"></a><a name="p637172514083932"></a>去初始化硬件加速。 <a href="_gfx_funcs.md#ad86b127aad2a6e7f01e07b77054d42b3">更多...</a></p>
</td>
</tr>
<tr id="row1712753449083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2032195551083932"><a name="p2032195551083932"></a><a name="p2032195551083932"></a>( <a href="_gfx_funcs.md#a12cf050a4c0d76f9816008fb102c7330">FillRect</a> )(<a href="_i_surface.md">ISurface</a> *surface, <a href="_i_rect.md">IRect</a> *rect, uint32_t color, <a href="_gfx_opt.md">GfxOpt</a> *opt)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1314070860083932"><a name="p1314070860083932"></a><a name="p1314070860083932"></a>填充矩形，用一种颜色填充画布上指定矩形区域的矩形框。 <a href="_gfx_funcs.md#a12cf050a4c0d76f9816008fb102c7330">更多...</a></p>
</td>
</tr>
<tr id="row1085573551083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1655558065083932"><a name="p1655558065083932"></a><a name="p1655558065083932"></a>( <a href="_gfx_funcs.md#a96785cdbc636179fc51026fc589cac17">DrawRectangle</a> )(<a href="_i_surface.md">ISurface</a> *surface, <a href="_rectangle.md">Rectangle</a> *rect, uint32_t color, <a href="_gfx_opt.md">GfxOpt</a> *opt)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p967598502083932"><a name="p967598502083932"></a><a name="p967598502083932"></a>绘制矩形框，用一种颜色在画布上绘制指定区域的矩形框。 <a href="_gfx_funcs.md#a96785cdbc636179fc51026fc589cac17">更多...</a></p>
</td>
</tr>
<tr id="row1270971670083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p492952618083932"><a name="p492952618083932"></a><a name="p492952618083932"></a>( <a href="_gfx_funcs.md#a5715347b14918e0dca51a9fd7b3d1a47">DrawLine</a> )(<a href="_i_surface.md">ISurface</a> *surface, <a href="_i_line.md">ILine</a> *line, <a href="_gfx_opt.md">GfxOpt</a> *opt)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1072239774083932"><a name="p1072239774083932"></a><a name="p1072239774083932"></a>绘制直线，使用一种颜色在画布上绘制一条直线。 <a href="_gfx_funcs.md#a5715347b14918e0dca51a9fd7b3d1a47">更多...</a></p>
</td>
</tr>
<tr id="row1935751761083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1900971555083932"><a name="p1900971555083932"></a><a name="p1900971555083932"></a>( <a href="_gfx_funcs.md#acac8893b6bf7ab9abdad1b563c4ab6f2">DrawCircle</a> )(<a href="_i_surface.md">ISurface</a> *surface, <a href="_i_circle.md">ICircle</a> *circle, <a href="_gfx_opt.md">GfxOpt</a> *opt)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p154879226083932"><a name="p154879226083932"></a><a name="p154879226083932"></a>绘制圆形，使用一种颜色在画布上绘制指定圆心和半径的圆。 <a href="_gfx_funcs.md#acac8893b6bf7ab9abdad1b563c4ab6f2">更多...</a></p>
</td>
</tr>
<tr id="row1447852160083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p846437781083932"><a name="p846437781083932"></a><a name="p846437781083932"></a>( <a href="_gfx_funcs.md#afa7103655ad7dae634865ca337e0aff3">Blit</a> )(<a href="_i_surface.md">ISurface</a> *srcSurface, <a href="_i_rect.md">IRect</a> *srcRect, <a href="_i_surface.md">ISurface</a> *dstSurface, <a href="_i_rect.md">IRect</a> *dstRect, <a href="_gfx_opt.md">GfxOpt</a> *opt)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1879342648083932"><a name="p1879342648083932"></a><a name="p1879342648083932"></a>位图搬移 <a href="_gfx_funcs.md#afa7103655ad7dae634865ca337e0aff3">更多...</a></p>
</td>
</tr>
<tr id="row1550682522083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2100200907083932"><a name="p2100200907083932"></a><a name="p2100200907083932"></a>( <a href="_gfx_funcs.md#a33d1cbc1082bb7f5786b4d9b0ca24697">Sync</a> )(int32_t timeOut)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2071882517083932"><a name="p2071882517083932"></a><a name="p2071882517083932"></a>硬件加速同步。 <a href="_gfx_funcs.md#a33d1cbc1082bb7f5786b4d9b0ca24697">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section589465957083932"></a>

显示硬件加速驱动接口结构体，定义硬件加速驱动接口函数指针。

## **类成员变量说明**<a name="section217081080083932"></a>

## Blit<a name="afa7103655ad7dae634865ca337e0aff3"></a>

```
int32_t(* GfxFuncs::Blit) (ISurface *srcSurface, IRect *srcRect, ISurface *dstSurface, IRect *dstRect, GfxOpt *opt)
```

**描述：**

位图搬移

在位图搬移过程中，可以实现色彩空间转换、缩放、旋转等功能。

**参数：**

<a name="table1932457126083932"></a>
<table><thead align="left"><tr id="row951189603083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2091943107083932"><a name="p2091943107083932"></a><a name="p2091943107083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1981562910083932"><a name="p1981562910083932"></a><a name="p1981562910083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1809961575083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2146001845083932p0"><a name="entry2146001845083932p0"></a><a name="entry2146001845083932p0"></a>srcSurface</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry932304036083932p0"><a name="entry932304036083932p0"></a><a name="entry932304036083932p0"></a>输入参数，源位图信息。</p>
</td>
</tr>
<tr id="row1715892197083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry510241469083932p0"><a name="entry510241469083932p0"></a><a name="entry510241469083932p0"></a>srcRect</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1196736405083932p0"><a name="entry1196736405083932p0"></a><a name="entry1196736405083932p0"></a>输入参数，源位图搬移区域。</p>
</td>
</tr>
<tr id="row1104655717083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1174333702083932p0"><a name="entry1174333702083932p0"></a><a name="entry1174333702083932p0"></a>dstSurface</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1939250481083932p0"><a name="entry1939250481083932p0"></a><a name="entry1939250481083932p0"></a>输出参数，目标位图信息。</p>
</td>
</tr>
<tr id="row1024593030083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry944916633083932p0"><a name="entry944916633083932p0"></a><a name="entry944916633083932p0"></a>dstRect</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1129648987083932p0"><a name="entry1129648987083932p0"></a><a name="entry1129648987083932p0"></a>输出参数，目标位图区域。</p>
</td>
</tr>
<tr id="row1152571971083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1792739567083932p0"><a name="entry1792739567083932p0"></a><a name="entry1792739567083932p0"></a>opt</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry492903065083932p0"><a name="entry492903065083932p0"></a><a name="entry492903065083932p0"></a>输入参数，硬件加速选项。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

DISPLAY\_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#ga12a925dadef7573cd74d63d06824f9b0)。

## DeinitGfx<a name="ad86b127aad2a6e7f01e07b77054d42b3"></a>

```
int32_t(* GfxFuncs::DeinitGfx) (void)
```

**描述：**

去初始化硬件加速。

**返回：**

DISPLAY\_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#ga12a925dadef7573cd74d63d06824f9b0)。

**参见：**

[InitGfx](_gfx_funcs.md#a3ec8ed6a467ed0c88e4dd723723c0f41)

## DrawCircle<a name="acac8893b6bf7ab9abdad1b563c4ab6f2"></a>

```
int32_t(* GfxFuncs::DrawCircle) (ISurface *surface, ICircle *circle, GfxOpt *opt)
```

**描述：**

绘制圆形，使用一种颜色在画布上绘制指定圆心和半径的圆。

**参数：**

<a name="table96942313083932"></a>
<table><thead align="left"><tr id="row1360782123083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1429324720083932"><a name="p1429324720083932"></a><a name="p1429324720083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1830730341083932"><a name="p1830730341083932"></a><a name="p1830730341083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1565540647083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1166345594083932p0"><a name="entry1166345594083932p0"></a><a name="entry1166345594083932p0"></a>surface</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry457200934083932p0"><a name="entry457200934083932p0"></a><a name="entry457200934083932p0"></a>输入参数，画布。</p>
</td>
</tr>
<tr id="row688194871083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1047217189083932p0"><a name="entry1047217189083932p0"></a><a name="entry1047217189083932p0"></a>circle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1343933374083932p0"><a name="entry1343933374083932p0"></a><a name="entry1343933374083932p0"></a>输入参数，圆形结构。</p>
</td>
</tr>
<tr id="row899247176083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1283853255083932p0"><a name="entry1283853255083932p0"></a><a name="entry1283853255083932p0"></a>opt</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry555399493083932p0"><a name="entry555399493083932p0"></a><a name="entry555399493083932p0"></a>输入参数，硬件加速选项。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

DISPLAY\_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#ga12a925dadef7573cd74d63d06824f9b0)。

## DrawLine<a name="a5715347b14918e0dca51a9fd7b3d1a47"></a>

```
int32_t(* GfxFuncs::DrawLine) (ISurface *surface, ILine *line, GfxOpt *opt)
```

**描述：**

绘制直线，使用一种颜色在画布上绘制一条直线。

**参数：**

<a name="table1404473333083932"></a>
<table><thead align="left"><tr id="row937071753083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1440166167083932"><a name="p1440166167083932"></a><a name="p1440166167083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p100638567083932"><a name="p100638567083932"></a><a name="p100638567083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1739969144083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry508063054083932p0"><a name="entry508063054083932p0"></a><a name="entry508063054083932p0"></a>surface</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1477821634083932p0"><a name="entry1477821634083932p0"></a><a name="entry1477821634083932p0"></a>输入参数，画布。</p>
</td>
</tr>
<tr id="row1275446998083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1970591423083932p0"><a name="entry1970591423083932p0"></a><a name="entry1970591423083932p0"></a>line</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1171268464083932p0"><a name="entry1171268464083932p0"></a><a name="entry1171268464083932p0"></a>输入参数，直线结构。</p>
</td>
</tr>
<tr id="row1955824907083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2127615385083932p0"><a name="entry2127615385083932p0"></a><a name="entry2127615385083932p0"></a>opt</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry369191327083932p0"><a name="entry369191327083932p0"></a><a name="entry369191327083932p0"></a>输入参数，硬件加速选项。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

DISPLAY\_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#ga12a925dadef7573cd74d63d06824f9b0)。

## DrawRectangle<a name="a96785cdbc636179fc51026fc589cac17"></a>

```
int32_t(* GfxFuncs::DrawRectangle) (ISurface *surface, Rectangle *rect, uint32_t color, GfxOpt *opt)
```

**描述：**

绘制矩形框，用一种颜色在画布上绘制指定区域的矩形框。

**参数：**

<a name="table792473233083932"></a>
<table><thead align="left"><tr id="row1580617150083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1901829765083932"><a name="p1901829765083932"></a><a name="p1901829765083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p873628500083932"><a name="p873628500083932"></a><a name="p873628500083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1254441132083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1785553539083932p0"><a name="entry1785553539083932p0"></a><a name="entry1785553539083932p0"></a>surface</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1492514714083932p0"><a name="entry1492514714083932p0"></a><a name="entry1492514714083932p0"></a>输入参数，画布。</p>
</td>
</tr>
<tr id="row967645435083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1938040853083932p0"><a name="entry1938040853083932p0"></a><a name="entry1938040853083932p0"></a>rect</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry337621259083932p0"><a name="entry337621259083932p0"></a><a name="entry337621259083932p0"></a>输入参数，矩形框结构。</p>
</td>
</tr>
<tr id="row397559186083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1100493604083932p0"><a name="entry1100493604083932p0"></a><a name="entry1100493604083932p0"></a>color</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1307195611083932p0"><a name="entry1307195611083932p0"></a><a name="entry1307195611083932p0"></a>输入参数，绘制的颜色。</p>
</td>
</tr>
<tr id="row1223713048083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1386470430083932p0"><a name="entry1386470430083932p0"></a><a name="entry1386470430083932p0"></a>opt</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry233882096083932p0"><a name="entry233882096083932p0"></a><a name="entry233882096083932p0"></a>输入参数，硬件加速选项。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

DISPLAY\_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#ga12a925dadef7573cd74d63d06824f9b0)。

## FillRect<a name="a12cf050a4c0d76f9816008fb102c7330"></a>

```
int32_t(* GfxFuncs::FillRect) (ISurface *surface, IRect *rect, uint32_t color, GfxOpt *opt)
```

**描述：**

填充矩形，用一种颜色填充画布上指定矩形区域的矩形框。

**参数：**

<a name="table162921153083932"></a>
<table><thead align="left"><tr id="row367596711083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p518342877083932"><a name="p518342877083932"></a><a name="p518342877083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1777671576083932"><a name="p1777671576083932"></a><a name="p1777671576083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row185796724083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1254874451083932p0"><a name="entry1254874451083932p0"></a><a name="entry1254874451083932p0"></a>surface</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1257261293083932p0"><a name="entry1257261293083932p0"></a><a name="entry1257261293083932p0"></a>输入参数，画布。</p>
</td>
</tr>
<tr id="row1300682319083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry430972502083932p0"><a name="entry430972502083932p0"></a><a name="entry430972502083932p0"></a>rect</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry368290106083932p0"><a name="entry368290106083932p0"></a><a name="entry368290106083932p0"></a>输入参数，填充的矩形区域。</p>
</td>
</tr>
<tr id="row2003288154083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1515235049083932p0"><a name="entry1515235049083932p0"></a><a name="entry1515235049083932p0"></a>color</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1566202576083932p0"><a name="entry1566202576083932p0"></a><a name="entry1566202576083932p0"></a>输入参数，填充的颜色。</p>
</td>
</tr>
<tr id="row1263447992083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry177917263083932p0"><a name="entry177917263083932p0"></a><a name="entry177917263083932p0"></a>opt</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry543912248083932p0"><a name="entry543912248083932p0"></a><a name="entry543912248083932p0"></a>输入参数，硬件加速选项。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

DISPLAY\_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#ga12a925dadef7573cd74d63d06824f9b0)。

## InitGfx<a name="a3ec8ed6a467ed0c88e4dd723723c0f41"></a>

```
int32_t(* GfxFuncs::InitGfx) (void)
```

**描述：**

初始化硬件加速。

**返回：**

DISPLAY\_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#ga12a925dadef7573cd74d63d06824f9b0)。

**参见：**

[DeinitGfx](_gfx_funcs.md#ad86b127aad2a6e7f01e07b77054d42b3)

## Sync<a name="a33d1cbc1082bb7f5786b4d9b0ca24697"></a>

```
int32_t(* GfxFuncs::Sync) (int32_t timeOut)
```

**描述：**

硬件加速同步。

在使用硬件加速模块进行图像绘制、图像叠加、图像搬移时，通过调用该接口进行硬件同步，该接口会等待硬件加速完成。

**参数：**

<a name="table1893409347083932"></a>
<table><thead align="left"><tr id="row1434138206083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p162937112083932"><a name="p162937112083932"></a><a name="p162937112083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p383924135083932"><a name="p383924135083932"></a><a name="p383924135083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row171325751083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry233728217083932p0"><a name="entry233728217083932p0"></a><a name="entry233728217083932p0"></a>timeOut</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2133283304083932p0"><a name="entry2133283304083932p0"></a><a name="entry2133283304083932p0"></a>输入参数，硬件加速同步超时设置，设置为0表示无超时，等待直到硬件加速完成。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

DISPLAY\_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#ga12a925dadef7573cd74d63d06824f9b0)。

