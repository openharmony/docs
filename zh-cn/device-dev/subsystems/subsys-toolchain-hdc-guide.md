# hdc\_std 使用指导<a name="ZH-CN_TOPIC_0000001080478129"></a>

-   [环境准备](#section05992022154916)
-   [注意事项](#section19543134915210)
-   [option相关的命令](#section618522925119)
-   [查询设备列表的命令](#section174891132104218)
-   [服务进程相关命令](#section680531510497)
-   [网络相关的命令](#section71176123212)
-   [文件相关的命令](#section173133523013)
-   [应用相关的命令](#section2072647133819)
-   [调试相关的命令](#section112861250195015)
-   [常见问题](#section592920255582)
    -   [hdc\_std连接不到设备](#section74019384588)
    -   [hdc\_std运行不了](#section63291491267)


hdc\_std（OpenHarmony Device Connector）是OpenHarmony为开发人员提供的用于调试的命令行工具，通过该工具可以在Windows/Linux等系统上与开发机或者模拟器进行交互。

下文将介绍hdc\_std的环境准备和常用命令及使用举例。

## 环境准备<a name="section05992022154916"></a>

**hdc\_std 工具获取方式：**

通过OpenHarmony sdk获取，hdc_std在sdk的toolchains目录下。

**使用举例：**

下面以windows侧使用方式举例：

获取windows的sdk，将hdc_std.exe放到磁盘某个位置即可使用。

## 注意事项<a name="section19543134915210"></a>

-   使用hdc\_std，如果出现异常，可以尝试通过hdc\_std kill命令杀掉hdc\_std服务，或者通过hdc\_std start -r命令重启服务进程进行解决。
-   如果出现hdc\_std list targets获取不到设备信息，通过任务管理器查看是否有hdc.exe进程存在，如果进程存在，可以通过杀掉该进程进行解决。

## option相关的命令<a name="section618522925119"></a>

option涉及以下命令：

**-h/help -v/version**

用于显示hdc相关的帮助、版本信息。

**表 1**  命令说明

<a name="table2560141891610"></a>
<table><tbody><tr id="row11561818151618"><td class="cellrowborder" valign="top" width="50%"><p id="p1656118183162"><a name="p1656118183162"></a><a name="p1656118183162"></a><strong id="b2056121871613"><a name="b2056121871613"></a><a name="b2056121871613"></a>返回值</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p55613181166"><a name="p55613181166"></a><a name="p55613181166"></a><strong id="b1056131819161"><a name="b1056131819161"></a><a name="b1056131819161"></a>返回值说明</strong></p>
</td>
</tr>
<tr id="row19561618141617"><td class="cellrowborder" valign="top" width="50%"><p id="p15615185161"><a name="p15615185161"></a><a name="p15615185161"></a>返回对应信息</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p135611718111618"><a name="p135611718111618"></a><a name="p135611718111618"></a>帮助或者版本信息</p>
</td>
</tr>
</tbody>
</table>

使用方法：

hdc\_std -h / hdc\_std  help

hdc\_std -v / hdc\_std  version

**-t key**

用于连接指定设备标识为key的设备。

**表 2**  命令说明

<a name="table16605101217544"></a>
<table><tbody><tr id="row14605141255412"><td class="cellrowborder" valign="top" width="50%"><p id="p14605121212541"><a name="p14605121212541"></a><a name="p14605121212541"></a><strong id="b127831518145914"><a name="b127831518145914"></a><a name="b127831518145914"></a>参数</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p18605111285411"><a name="p18605111285411"></a><a name="p18605111285411"></a><strong id="b37960186590"><a name="b37960186590"></a><a name="b37960186590"></a>参数说明</strong></p>
</td>
</tr>
<tr id="row260514129547"><td class="cellrowborder" valign="top" width="50%"><p id="p1060512126548"><a name="p1060512126548"></a><a name="p1060512126548"></a><span>key</span></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p26051123547"><a name="p26051123547"></a><a name="p26051123547"></a><span>为tcp:port格式，或者USB序列号</span></p>
</td>
</tr>
<tr id="row46051121548"><td class="cellrowborder" valign="top" width="50%"><p id="p11605111285411"><a name="p11605111285411"></a><a name="p11605111285411"></a><strong id="b71816221599"><a name="b71816221599"></a><a name="b71816221599"></a>返回值</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p18605101265413"><a name="p18605101265413"></a><a name="p18605101265413"></a><strong id="b828172265915"><a name="b828172265915"></a><a name="b828172265915"></a>返回值说明</strong></p>
</td>
</tr>
<tr id="row1760531211546"><td class="cellrowborder" valign="top" width="50%"><p id="p232481834"><a name="p232481834"></a><a name="p232481834"></a>①error: device '***' not found</p>
<p id="p12191171320"><a name="p12191171320"></a><a name="p12191171320"></a>②Nothing to do...</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p85527328314"><a name="p85527328314"></a><a name="p85527328314"></a>①设备不存在</p>
<p id="p10343124416277"><a name="p10343124416277"></a><a name="p10343124416277"></a>②附加的命令不存在</p>
</td>
</tr>
</tbody>
</table>

使用方法：

该option需要与具体的操作命令搭配使用，下面以shell命令举例：

hdc\_std list targets  （获取设备信息）

hdc\_std  -t   _key_   shell  （-t后面添加的_key_  需要替换为上面查询的设备信息）

>![](../public_sys-resources/icon-note.gif) **说明：** 
>一台开发机可支持多个设备连接，每个设备有其唯一的设备标识，如果通过网络与设备连接,其标识为tcp:port格式，如果通过usb连接则标识为设备sn号。该命令需要跟随具体操作命令。

## 查询设备列表的命令<a name="section174891132104218"></a>

查询设备列表涉及以下命令：

**list targets\[-v\]**

显示所有已经连接的目标设备列表

**表 3**  命令说明

<a name="table1233315596432"></a>
<table><tbody><tr id="row1033313596434"><td class="cellrowborder" valign="top" width="50%"><p id="p13333115919432"><a name="p13333115919432"></a><a name="p13333115919432"></a><strong id="b1033325915433"><a name="b1033325915433"></a><a name="b1033325915433"></a>参数</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p033320595430"><a name="p033320595430"></a><a name="p033320595430"></a><strong id="b4333115912438"><a name="b4333115912438"></a><a name="b4333115912438"></a>参数说明</strong></p>
</td>
</tr>
<tr id="row733310596437"><td class="cellrowborder" valign="top" width="50%"><p id="p13333115911433"><a name="p13333115911433"></a><a name="p13333115911433"></a>-v</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p123331159134314"><a name="p123331159134314"></a><a name="p123331159134314"></a>添加-v选项，则会打印设备详细信息</p>
</td>
</tr>
<tr id="row1833305944314"><td class="cellrowborder" valign="top" width="50%"><p id="p833445916438"><a name="p833445916438"></a><a name="p833445916438"></a><strong id="b633495913438"><a name="b633495913438"></a><a name="b633495913438"></a>返回值</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p23341159134320"><a name="p23341159134320"></a><a name="p23341159134320"></a><strong id="b4334459154316"><a name="b4334459154316"></a><a name="b4334459154316"></a>返回值说明</strong></p>
</td>
</tr>
<tr id="row03341859154311"><td class="cellrowborder" valign="top" width="50%"><p id="p13334659154310"><a name="p13334659154310"></a><a name="p13334659154310"></a>①返回设备信息</p>
<p id="p19553114217533"><a name="p19553114217533"></a><a name="p19553114217533"></a>②[Empty]</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p6334859174310"><a name="p6334859174310"></a><a name="p6334859174310"></a>①已经连接的设备列表信息</p>
<p id="p57581926125318"><a name="p57581926125318"></a><a name="p57581926125318"></a>②没有查询到设备信息</p>
</td>
</tr>
</tbody>
</table>

使用方法：

hdc\_std list targets

hdc\_std list targets -v

## 服务进程相关命令<a name="section680531510497"></a>

服务进程涉及以下命令：

**target mount**

以读写模式挂载/system等分区。

**表 4**  命令说明

<a name="table5346719144119"></a>
<table><tbody><tr id="row9346419124120"><td class="cellrowborder" valign="top" width="50%"><p id="p134612191413"><a name="p134612191413"></a><a name="p134612191413"></a><strong id="b534681917414"><a name="b534681917414"></a><a name="b534681917414"></a>参数</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p12346141944113"><a name="p12346141944113"></a><a name="p12346141944113"></a><strong id="b1134631924116"><a name="b1134631924116"></a><a name="b1134631924116"></a>参数说明</strong></p>
</td>
</tr>
<tr id="row1534681974114"><td class="cellrowborder" valign="top" width="50%"><p id="p16346131914118"><a name="p16346131914118"></a><a name="p16346131914118"></a>无</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p18346191954119"><a name="p18346191954119"></a><a name="p18346191954119"></a><span>无</span></p>
</td>
</tr>
<tr id="row18346131964114"><td class="cellrowborder" valign="top" width="50%"><p id="p1934671934110"><a name="p1934671934110"></a><a name="p1934671934110"></a><strong id="b1934641911412"><a name="b1934641911412"></a><a name="b1934641911412"></a>返回值</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p18346101911411"><a name="p18346101911411"></a><a name="p18346101911411"></a><strong id="b1734641994117"><a name="b1734641994117"></a><a name="b1734641994117"></a>返回值说明</strong></p>
</td>
</tr>
<tr id="row19346919164116"><td class="cellrowborder" valign="top" width="50%"><p id="p44221428143012"><a name="p44221428143012"></a><a name="p44221428143012"></a>①Mount finish</p>
<p id="p43471519204114"><a name="p43471519204114"></a><a name="p43471519204114"></a>②返回具体信息</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p1551336123011"><a name="p1551336123011"></a><a name="p1551336123011"></a>①成功情况下返回的信息</p>
<p id="p2034731984115"><a name="p2034731984115"></a><a name="p2034731984115"></a>②失败情况下的具体信息</p>
</td>
</tr>
</tbody>
</table>

使用方法：

hdc\_std target mount

**smode \[off\]**

授予后台服务进程root权限， 使用off参数取消授权。

使用方法：

hdc\_std smode

hdc\_std smode off

**kill \[-r\]**

终止服务进程。

**表 5**  命令说明

<a name="table540423782919"></a>
<table><tbody><tr id="row8404937152910"><td class="cellrowborder" valign="top" width="50%"><p id="p7404113711295"><a name="p7404113711295"></a><a name="p7404113711295"></a><strong id="b440511373297"><a name="b440511373297"></a><a name="b440511373297"></a>参数</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p4405193792919"><a name="p4405193792919"></a><a name="p4405193792919"></a><strong id="b16405163711294"><a name="b16405163711294"></a><a name="b16405163711294"></a>参数说明</strong></p>
</td>
</tr>
<tr id="row174051037112912"><td class="cellrowborder" valign="top" width="50%"><p id="p134056375291"><a name="p134056375291"></a><a name="p134056375291"></a>-r</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p18405337142911"><a name="p18405337142911"></a><a name="p18405337142911"></a>触发服务重启</p>
</td>
</tr>
<tr id="row164052037162913"><td class="cellrowborder" valign="top" width="50%"><p id="p124051837182918"><a name="p124051837182918"></a><a name="p124051837182918"></a><strong id="b140573762917"><a name="b140573762917"></a><a name="b140573762917"></a>返回值</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p8405113782918"><a name="p8405113782918"></a><a name="p8405113782918"></a><strong id="b194057375291"><a name="b194057375291"></a><a name="b194057375291"></a>返回值说明</strong></p>
</td>
</tr>
<tr id="row15405163702915"><td class="cellrowborder" valign="top" width="50%"><p id="p0976152811311"><a name="p0976152811311"></a><a name="p0976152811311"></a>①Kill server finish</p>
<p id="p2405163713299"><a name="p2405163713299"></a><a name="p2405163713299"></a>②返回具体信息</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p10405123732915"><a name="p10405123732915"></a><a name="p10405123732915"></a>①成功情况下返回的信息</p>
<p id="p19405337152916"><a name="p19405337152916"></a><a name="p19405337152916"></a>②失败情况下的具体信息</p>
</td>
</tr>
</tbody>
</table>

使用方法：

hdc\_std kill

**start \[-r\]**

启动服务进程。

**表 6**  命令说明

<a name="table11605125417348"></a>
<table><tbody><tr id="row176051354123419"><td class="cellrowborder" valign="top" width="50%"><p id="p16605185413418"><a name="p16605185413418"></a><a name="p16605185413418"></a><strong id="b66051754163418"><a name="b66051754163418"></a><a name="b66051754163418"></a>参数</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p3605125413346"><a name="p3605125413346"></a><a name="p3605125413346"></a><strong id="b1360565453412"><a name="b1360565453412"></a><a name="b1360565453412"></a>参数说明</strong></p>
</td>
</tr>
<tr id="row1560575443411"><td class="cellrowborder" valign="top" width="50%"><p id="p17605135411347"><a name="p17605135411347"></a><a name="p17605135411347"></a>-r</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p1860525413414"><a name="p1860525413414"></a><a name="p1860525413414"></a>如果服务进程已经启动，-r选项会触发服务进程重新启动</p>
</td>
</tr>
<tr id="row14606154183415"><td class="cellrowborder" valign="top" width="50%"><p id="p160695453412"><a name="p160695453412"></a><a name="p160695453412"></a><strong id="b13606155473418"><a name="b13606155473418"></a><a name="b13606155473418"></a>返回值</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p1606154163419"><a name="p1606154163419"></a><a name="p1606154163419"></a><strong id="b16606175453419"><a name="b16606175453419"></a><a name="b16606175453419"></a>返回值说明</strong></p>
</td>
</tr>
<tr id="row7606135433416"><td class="cellrowborder" valign="top" width="50%"><p id="p716462216389"><a name="p716462216389"></a><a name="p716462216389"></a>无</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p360645453415"><a name="p360645453415"></a><a name="p360645453415"></a>无</p>
</td>
</tr>
</tbody>
</table>

使用方法：

hdc\_std start

## 网络相关的命令<a name="section71176123212"></a>

网络部分涉及以下命令：

**tconn host\[:port\]\[-remove\]**

通过【ip地址：端口号】来指定连接的设备

**表 7**  命令说明

<a name="table71285383412"></a>
<table><tbody><tr id="row6128123818419"><td class="cellrowborder" valign="top" width="50%"><p id="p812814386413"><a name="p812814386413"></a><a name="p812814386413"></a><strong id="b5129143810410"><a name="b5129143810410"></a><a name="b5129143810410"></a>参数</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p131291038641"><a name="p131291038641"></a><a name="p131291038641"></a><strong id="b15129638142"><a name="b15129638142"></a><a name="b15129638142"></a>参数说明</strong></p>
</td>
</tr>
<tr id="row101292381149"><td class="cellrowborder" valign="top" width="50%"><p id="p712914385410"><a name="p712914385410"></a><a name="p712914385410"></a>host[:port]</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p14129038443"><a name="p14129038443"></a><a name="p14129038443"></a><span>为tcp:port格式</span></p>
</td>
</tr>
<tr id="row18468719662"><td class="cellrowborder" valign="top" width="50%"><p id="p8469141919614"><a name="p8469141919614"></a><a name="p8469141919614"></a>-remove</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p24693194612"><a name="p24693194612"></a><a name="p24693194612"></a>表示断开与指定设备的连接</p>
</td>
</tr>
<tr id="row12129133811418"><td class="cellrowborder" valign="top" width="50%"><p id="p121301738546"><a name="p121301738546"></a><a name="p121301738546"></a><strong id="b1613012389412"><a name="b1613012389412"></a><a name="b1613012389412"></a>返回值</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p413019381140"><a name="p413019381140"></a><a name="p413019381140"></a><strong id="b11130123810417"><a name="b11130123810417"></a><a name="b11130123810417"></a>返回值说明</strong></p>
</td>
</tr>
<tr id="row1813093818415"><td class="cellrowborder" valign="top" width="50%"><p id="p453212235494"><a name="p453212235494"></a><a name="p453212235494"></a>①返回具体信息</p>
<p id="p753222334914"><a name="p753222334914"></a><a name="p753222334914"></a>②无</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p1353282314492"><a name="p1353282314492"></a><a name="p1353282314492"></a>①失败情况下的具体信息</p>
<p id="p053312316491"><a name="p053312316491"></a><a name="p053312316491"></a>②成功情况下无返回值</p>
</td>
</tr>
</tbody>
</table>

使用方法（举例）：

hdc\_std tconn 192.168.0.100:8710

**tmode usb**

执行后设备端对应daemon进程重启，并首先选用usb连接方式。

**表 8**  命令说明

<a name="table94491851798"></a>
<table><tbody><tr id="row3450451595"><td class="cellrowborder" valign="top" width="50%"><p id="p1450551394"><a name="p1450551394"></a><a name="p1450551394"></a><strong id="b645013511591"><a name="b645013511591"></a><a name="b645013511591"></a>参数</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p1645016511493"><a name="p1645016511493"></a><a name="p1645016511493"></a><strong id="b94509511699"><a name="b94509511699"></a><a name="b94509511699"></a>参数说明</strong></p>
</td>
</tr>
<tr id="row245010513917"><td class="cellrowborder" valign="top" width="50%"><p id="p64509517910"><a name="p64509517910"></a><a name="p64509517910"></a>无</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p134501517910"><a name="p134501517910"></a><a name="p134501517910"></a><span>无</span></p>
</td>
</tr>
<tr id="row184501851891"><td class="cellrowborder" valign="top" width="50%"><p id="p18450205118919"><a name="p18450205118919"></a><a name="p18450205118919"></a><strong id="b1045017518911"><a name="b1045017518911"></a><a name="b1045017518911"></a>返回值</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p44504518913"><a name="p44504518913"></a><a name="p44504518913"></a><strong id="b12450205111917"><a name="b12450205111917"></a><a name="b12450205111917"></a>返回值说明</strong></p>
</td>
</tr>
<tr id="row3450551196"><td class="cellrowborder" valign="top" width="50%"><p id="p819142715546"><a name="p819142715546"></a><a name="p819142715546"></a>①返回具体信息</p>
<p id="p11911427195411"><a name="p11911427195411"></a><a name="p11911427195411"></a>②无</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p81911527145413"><a name="p81911527145413"></a><a name="p81911527145413"></a>①失败情况下的具体信息</p>
<p id="p4191192720546"><a name="p4191192720546"></a><a name="p4191192720546"></a>②成功情况下无返回值</p>
</td>
</tr>
</tbody>
</table>

使用方法：

hdc\_std tmode usb

**tmode port port-number**

执行后设备端对应daemon进程重启，并优先使用网络方式连接设备，如果连接设备再选择usb连接。

**表 9**  命令说明

<a name="table019772118177"></a>
<table><tbody><tr id="row11972213173"><td class="cellrowborder" valign="top" width="50%"><p id="p319752111178"><a name="p319752111178"></a><a name="p319752111178"></a><strong id="b1719712210176"><a name="b1719712210176"></a><a name="b1719712210176"></a>参数</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p17198121121713"><a name="p17198121121713"></a><a name="p17198121121713"></a><strong id="b519832112179"><a name="b519832112179"></a><a name="b519832112179"></a>参数说明</strong></p>
</td>
</tr>
<tr id="row519812161713"><td class="cellrowborder" valign="top" width="50%"><p id="p819872114179"><a name="p819872114179"></a><a name="p819872114179"></a>port-number</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p18198921171715"><a name="p18198921171715"></a><a name="p18198921171715"></a><span>listen连接的网络端口</span>号</p>
</td>
</tr>
<tr id="row1519872118175"><td class="cellrowborder" valign="top" width="50%"><p id="p219882112179"><a name="p219882112179"></a><a name="p219882112179"></a><strong id="b20198142191716"><a name="b20198142191716"></a><a name="b20198142191716"></a>返回值</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p10198621111710"><a name="p10198621111710"></a><a name="p10198621111710"></a><strong id="b1319872171718"><a name="b1319872171718"></a><a name="b1319872171718"></a>返回值说明</strong></p>
</td>
</tr>
<tr id="row1019822118176"><td class="cellrowborder" valign="top" width="50%"><p id="p742693415541"><a name="p742693415541"></a><a name="p742693415541"></a>①返回具体信息</p>
<p id="p2426234155414"><a name="p2426234155414"></a><a name="p2426234155414"></a>②无</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p17426133416542"><a name="p17426133416542"></a><a name="p17426133416542"></a>①失败情况下的具体信息</p>
<p id="p20426834195419"><a name="p20426834195419"></a><a name="p20426834195419"></a>②成功情况下无返回值</p>
</td>
</tr>
</tbody>
</table>

使用方法：

hdc\_std tmode port 8710

>![](../public_sys-resources/icon-note.gif) **说明：** 
>执行完毕后，远端daemon将会退出并重启，默认启用TCP连接，如果不加上listen端口则listen随机端口。

## 文件相关的命令<a name="section173133523013"></a>

文件部分涉及以下命令：

**file send local remote**

发送文件至远端设备。

**表 10**  命令说明

<a name="table14621451193116"></a>
<table><tbody><tr id="row1062451113113"><td class="cellrowborder" valign="top" width="50%"><p id="p1262115173111"><a name="p1262115173111"></a><a name="p1262115173111"></a><strong id="b1162105119319"><a name="b1162105119319"></a><a name="b1162105119319"></a>参数</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p1362135193113"><a name="p1362135193113"></a><a name="p1362135193113"></a><strong id="b106225117317"><a name="b106225117317"></a><a name="b106225117317"></a>参数说明</strong></p>
</td>
</tr>
<tr id="row9627518318"><td class="cellrowborder" valign="top" width="50%"><p id="p14620519314"><a name="p14620519314"></a><a name="p14620519314"></a><span>l</span><span>ocal</span></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p176225193115"><a name="p176225193115"></a><a name="p176225193115"></a><span>本地待发送文件路径</span></p>
</td>
</tr>
<tr id="row1462451183119"><td class="cellrowborder" valign="top" width="50%"><p id="p14622051193115"><a name="p14622051193115"></a><a name="p14622051193115"></a><span>r</span><span>emote</span></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p1634515316"><a name="p1634515316"></a><a name="p1634515316"></a><span>远程待接收文件路径</span></p>
</td>
</tr>
<tr id="row2063145116319"><td class="cellrowborder" valign="top" width="50%"><p id="p4632515314"><a name="p4632515314"></a><a name="p4632515314"></a><strong id="b156385123119"><a name="b156385123119"></a><a name="b156385123119"></a>返回值</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p136375117312"><a name="p136375117312"></a><a name="p136375117312"></a><strong id="b196345113315"><a name="b196345113315"></a><a name="b196345113315"></a>返回值说明</strong></p>
</td>
</tr>
<tr id="row663125113314"><td class="cellrowborder" valign="top" width="50%"><p id="p17550131319559"><a name="p17550131319559"></a><a name="p17550131319559"></a>①返回具体信息</p>
<p id="p0550151385512"><a name="p0550151385512"></a><a name="p0550151385512"></a>②返回传输结果</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p1955091315517"><a name="p1955091315517"></a><a name="p1955091315517"></a>①失败情况下的具体信息</p>
<p id="p1555041375519"><a name="p1555041375519"></a><a name="p1555041375519"></a>②成功传输的结果信息</p>
</td>
</tr>
</tbody>
</table>

使用方法（举例）：

hdc\_std file send E:\\a.txt   /data/local/tmp/a.txt

**file recv \[-a\] remote local**

从远端设备接收文件至本地。

**表 11**  命令说明

<a name="table158381145153317"></a>
<table><tbody><tr id="row17838945183314"><td class="cellrowborder" valign="top" width="50%"><p id="p383884515338"><a name="p383884515338"></a><a name="p383884515338"></a><strong id="b18381445103315"><a name="b18381445103315"></a><a name="b18381445103315"></a>参数</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p583844511335"><a name="p583844511335"></a><a name="p583844511335"></a><strong id="b683819456338"><a name="b683819456338"></a><a name="b683819456338"></a>参数说明</strong></p>
</td>
</tr>
<tr id="row1983814583315"><td class="cellrowborder" valign="top" width="50%"><p id="p1383834510332"><a name="p1383834510332"></a><a name="p1383834510332"></a><span>-a</span></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p18391745103318"><a name="p18391745103318"></a><a name="p18391745103318"></a><span>文件保留时间戳模式</span></p>
</td>
</tr>
<tr id="row1683910452331"><td class="cellrowborder" valign="top" width="50%"><p id="p14839164511331"><a name="p14839164511331"></a><a name="p14839164511331"></a><span>l</span><span>ocal</span></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p1783912455333"><a name="p1783912455333"></a><a name="p1783912455333"></a><span>本地待接收文件路径</span></p>
</td>
</tr>
<tr id="row3941318173410"><td class="cellrowborder" valign="top" width="50%"><p id="p49411618153419"><a name="p49411618153419"></a><a name="p49411618153419"></a><span>r</span><span>emote</span></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p179411118193416"><a name="p179411118193416"></a><a name="p179411118193416"></a><span>远程待发送文件路径</span></p>
</td>
</tr>
<tr id="row88390451339"><td class="cellrowborder" valign="top" width="50%"><p id="p2839194516338"><a name="p2839194516338"></a><a name="p2839194516338"></a><strong id="b483914453337"><a name="b483914453337"></a><a name="b483914453337"></a>返回值</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p683984533315"><a name="p683984533315"></a><a name="p683984533315"></a><strong id="b208391045163315"><a name="b208391045163315"></a><a name="b208391045163315"></a>返回值说明</strong></p>
</td>
</tr>
<tr id="row48391459333"><td class="cellrowborder" valign="top" width="50%"><p id="p13206132716566"><a name="p13206132716566"></a><a name="p13206132716566"></a>①返回具体信息</p>
<p id="p620632745613"><a name="p620632745613"></a><a name="p620632745613"></a>②无</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p120662717562"><a name="p120662717562"></a><a name="p120662717562"></a>①失败情况下的具体信息</p>
<p id="p182060275563"><a name="p182060275563"></a><a name="p182060275563"></a>②成功情况下无返回值</p>
</td>
</tr>
</tbody>
</table>

使用方法（举例）：

hdc\_std file recv  /data/local/tmp/a.txt   ./a.txt

## 应用相关的命令<a name="section2072647133819"></a>

应用部分涉及以下命令：

**install \[-r/-d/-g\]  _package_**

安装OpenHarmony package。

**表 12**  命令说明

<a name="table17750145274216"></a>
<table><tbody><tr id="row20750115294217"><td class="cellrowborder" valign="top" width="50%"><p id="p075011520420"><a name="p075011520420"></a><a name="p075011520420"></a><strong id="b1575010525425"><a name="b1575010525425"></a><a name="b1575010525425"></a>参数</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p8750352174213"><a name="p8750352174213"></a><a name="p8750352174213"></a><strong id="b1475016528426"><a name="b1475016528426"></a><a name="b1475016528426"></a>参数说明</strong></p>
</td>
</tr>
<tr id="row10750145215423"><td class="cellrowborder" valign="top" width="50%"><p id="p87501852144219"><a name="p87501852144219"></a><a name="p87501852144219"></a>package</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p1175045234218"><a name="p1175045234218"></a><a name="p1175045234218"></a><span id="text16401191544314"><a name="text16401191544314"></a><a name="text16401191544314"></a>OpenHarmony</span>应用安装包</p>
</td>
</tr>
<tr id="row675055212422"><td class="cellrowborder" valign="top" width="50%"><p id="p875111524420"><a name="p875111524420"></a><a name="p875111524420"></a>-r</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p117511052144218"><a name="p117511052144218"></a><a name="p117511052144218"></a>替换已存在应用</p>
</td>
</tr>
<tr id="row27512529425"><td class="cellrowborder" valign="top" width="50%"><p id="p975125234214"><a name="p975125234214"></a><a name="p975125234214"></a>-d</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p13784141616446"><a name="p13784141616446"></a><a name="p13784141616446"></a>允许降级安装</p>
</td>
</tr>
<tr id="row137312316446"><td class="cellrowborder" valign="top" width="50%"><p id="p6374623104414"><a name="p6374623104414"></a><a name="p6374623104414"></a>-g</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p6374122319440"><a name="p6374122319440"></a><a name="p6374122319440"></a>动态授权</p>
</td>
</tr>
<tr id="row12751652184219"><td class="cellrowborder" valign="top" width="50%"><p id="p475195234219"><a name="p475195234219"></a><a name="p475195234219"></a><strong id="b1775110522425"><a name="b1775110522425"></a><a name="b1775110522425"></a>返回值</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p117511452174214"><a name="p117511452174214"></a><a name="p117511452174214"></a><strong id="b1175145217423"><a name="b1175145217423"></a><a name="b1175145217423"></a>返回值说明</strong></p>
</td>
</tr>
<tr id="row1275111528426"><td class="cellrowborder" valign="top" width="50%"><p id="p472019319564"><a name="p472019319564"></a><a name="p472019319564"></a>①返回具体信息</p>
<p id="p5720123110569"><a name="p5720123110569"></a><a name="p5720123110569"></a>②无</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p16720113145610"><a name="p16720113145610"></a><a name="p16720113145610"></a>①失败情况下的具体信息</p>
<p id="p8720031185611"><a name="p8720031185611"></a><a name="p8720031185611"></a>②成功情况下无返回值</p>
</td>
</tr>
</tbody>
</table>

使用方法（举例）：

hdc\_std install  _hwadmin.hap_

**uninstall \[-k\] package**

卸载OpenHarmony应用。

**表 13**  命令说明

<a name="table35114624716"></a>
<table><tbody><tr id="row125646174717"><td class="cellrowborder" valign="top" width="50%"><p id="p166204610478"><a name="p166204610478"></a><a name="p166204610478"></a><strong id="b156174612473"><a name="b156174612473"></a><a name="b156174612473"></a>参数</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p96146184715"><a name="p96146184715"></a><a name="p96146184715"></a><strong id="b166124617470"><a name="b166124617470"></a><a name="b166124617470"></a>参数说明</strong></p>
</td>
</tr>
<tr id="row26164617475"><td class="cellrowborder" valign="top" width="50%"><p id="p26124612474"><a name="p26124612474"></a><a name="p26124612474"></a>package</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p1634674710"><a name="p1634674710"></a><a name="p1634674710"></a><span id="text10156722486"><a name="text10156722486"></a><a name="text10156722486"></a>OpenHarmony</span>应用安装包</p>
</td>
</tr>
<tr id="row06104616471"><td class="cellrowborder" valign="top" width="50%"><p id="p1461146144719"><a name="p1461146144719"></a><a name="p1461146144719"></a>-k</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p19613463476"><a name="p19613463476"></a><a name="p19613463476"></a>保留/data/cache</p>
</td>
</tr>
<tr id="row3624614478"><td class="cellrowborder" valign="top" width="50%"><p id="p46114644719"><a name="p46114644719"></a><a name="p46114644719"></a><strong id="b156846164713"><a name="b156846164713"></a><a name="b156846164713"></a>返回值</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p186114618474"><a name="p186114618474"></a><a name="p186114618474"></a><strong id="b10617469472"><a name="b10617469472"></a><a name="b10617469472"></a>返回值说明</strong></p>
</td>
</tr>
<tr id="row17654616471"><td class="cellrowborder" valign="top" width="50%"><p id="p2071893615564"><a name="p2071893615564"></a><a name="p2071893615564"></a>①返回具体信息</p>
<p id="p1971893615560"><a name="p1971893615560"></a><a name="p1971893615560"></a>②无</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p167181136125610"><a name="p167181136125610"></a><a name="p167181136125610"></a>①失败情况下的具体信息</p>
<p id="p1371811369562"><a name="p1371811369562"></a><a name="p1371811369562"></a>②成功情况下无返回值</p>
</td>
</tr>
</tbody>
</table>

使用方法（举例）：

hdc\_std uninstall  _package_

## 调试相关的命令<a name="section112861250195015"></a>

调试涉及以下命令：

**hilog**

支持抓取log信息。

**表 14**  命令说明

<a name="table1494175214518"></a>
<table><tbody><tr id="row1994119527515"><td class="cellrowborder" valign="top" width="50%"><p id="p19411552205117"><a name="p19411552205117"></a><a name="p19411552205117"></a><strong id="b394145275116"><a name="b394145275116"></a><a name="b394145275116"></a>参数</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p139412052195113"><a name="p139412052195113"></a><a name="p139412052195113"></a><strong id="b1494285215519"><a name="b1494285215519"></a><a name="b1494285215519"></a>参数说明</strong></p>
</td>
</tr>
<tr id="row994275265110"><td class="cellrowborder" valign="top" width="50%"><p id="p69421852115119"><a name="p69421852115119"></a><a name="p69421852115119"></a>无</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p1694213525517"><a name="p1694213525517"></a><a name="p1694213525517"></a>无</p>
</td>
</tr>
<tr id="row149421752145113"><td class="cellrowborder" valign="top" width="50%"><p id="p16942152205114"><a name="p16942152205114"></a><a name="p16942152205114"></a><strong id="b11942165295116"><a name="b11942165295116"></a><a name="b11942165295116"></a>返回值</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p5942452195116"><a name="p5942452195116"></a><a name="p5942452195116"></a><strong id="b1394235216517"><a name="b1394235216517"></a><a name="b1394235216517"></a>返回值说明</strong></p>
</td>
</tr>
<tr id="row11942105275116"><td class="cellrowborder" valign="top" width="50%"><p id="p194213523517"><a name="p194213523517"></a><a name="p194213523517"></a>返回具体信息</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p4942155215112"><a name="p4942155215112"></a><a name="p4942155215112"></a>抓取的日志信息</p>
</td>
</tr>
</tbody>
</table>

抓取hilog日志：

hdc\_std hilog

清理hilog缓存日志：

hdc_std shell "hilog -r"

>![](../public_sys-resources/icon-note.gif) **说明：** 
>更多hilog操作命令请参考[hilog组件使用说明](https://gitee.com/openharmony/hiviewdfx_hilog/blob/master/README_zh.md#%E4%BD%BF%E7%94%A8%E8%AF%B4%E6%98%8E)。

**shell \[_command_\]**

远程执行命令或进入交互命令环境。

**表 15**  命令说明

<a name="table365554575617"></a>
<table><tbody><tr id="row26551545185617"><td class="cellrowborder" valign="top" width="50%"><p id="p126558451567"><a name="p126558451567"></a><a name="p126558451567"></a><strong id="b14655184513562"><a name="b14655184513562"></a><a name="b14655184513562"></a>参数</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p16655164518568"><a name="p16655164518568"></a><a name="p16655164518568"></a><strong id="b146551645115614"><a name="b146551645115614"></a><a name="b146551645115614"></a>参数说明</strong></p>
</td>
</tr>
<tr id="row1465534525610"><td class="cellrowborder" valign="top" width="50%"><p id="p1265511453563"><a name="p1265511453563"></a><a name="p1265511453563"></a><span>command</span></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p365616459567"><a name="p365616459567"></a><a name="p365616459567"></a><span>需要执行的单次命令</span></p>
</td>
</tr>
<tr id="row7656245165619"><td class="cellrowborder" valign="top" width="50%"><p id="p865624565611"><a name="p865624565611"></a><a name="p865624565611"></a><strong id="b156569454562"><a name="b156569454562"></a><a name="b156569454562"></a>返回值</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p10656194595611"><a name="p10656194595611"></a><a name="p10656194595611"></a><strong id="b1165654555613"><a name="b1165654555613"></a><a name="b1165654555613"></a>返回值说明</strong></p>
</td>
</tr>
<tr id="row9656114585615"><td class="cellrowborder" valign="top" width="50%"><p id="p765624513561"><a name="p765624513561"></a><a name="p765624513561"></a>返回具体信息</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p2481349195711"><a name="p2481349195711"></a><a name="p2481349195711"></a><span>shell后面执行命令的结果信息</span></p>
</td>
</tr>
</tbody>
</table>

使用方法：

hdc\_std shell

## 常见问题<a name="section592920255582"></a>

### hdc\_std连接不到设备<a name="section74019384588"></a>

-   **现象描述**

    执行 "hdc\_std list targets"命令后结果为：\[Empty\]

-   **解决方法**
    1.  设备没有被识别：

        在设备管理器中查看是否有hdc设备，在通用串行总线设备中会有“HDC Device”信息。如果没有，hdc无法连接。此时需要插拔设备，或者烧写最新的镜像。

    2.  hdc\_std工作异常：

        可以执行"hdc kill"或者"hdc start -r"杀掉hdc服务或者重启hdc服务，然后再执行hdc list targets查看是否已经可以获取设备信息。

    3.  hdc\_std与设备不匹配：

        如果设备烧写的是最新镜像，hdc\_std也需要使用最新版本。由于hdc\_std会持续更新，请从开源仓developtools\_hdc\_standard中获取，具体位置在该开源仓的prebuilt目录。



### hdc\_std运行不了<a name="section63291491267"></a>

-   **现象描述**

    点击hdc\_std.exe文件无法运行。

-   **解决方法**

    hdc\_std.exe不需要安装，直接放到磁盘上就能使用，也可以添加到环境变量中。通过打开cmd执行hdc\_std命令直接使用。


