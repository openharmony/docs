# bytrace使用指导<a name="ZH-CN_TOPIC_0000001083359811"></a>

-   [简介](#section11388623181619)
-   [命令行开发指导](#section1595564317164)
    -   [bytrace命令](#section2344125731617)
    -   [bytrace命令使用举例](#section5402591174)


## 简介<a name="section11388623181619"></a>

bytrace是开发人员用于追踪进程轨迹、分析性能的一种工具，主要对内核ftrace进行了封装和扩展，来支持用户态的打点。通过该工具可以打开想要查看的用户态和内核label（通过下面命令行bytrace -l，查看支持的所有label），然后通过命令行进行抓取trace信息到指定文件中。

## 命令行开发指导<a name="section1595564317164"></a>

### bytrace命令<a name="section2344125731617"></a>

bytrace当前支持以下命令:

**表 1**  命令行列表

<a name="table16802195914247"></a>
<table><thead align="left"><tr id="row14804759142412"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p1280465972411"><a name="p1280465972411"></a><a name="p1280465972411"></a>Option</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p380414595249"><a name="p380414595249"></a><a name="p380414595249"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1714512123414"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1915412133419"><a name="p1915412133419"></a><a name="p1915412133419"></a>-h，--help</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p6156126341"><a name="p6156126341"></a><a name="p6156126341"></a>查看option帮助</p>
</td>
</tr>
<tr id="row13804135982416"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p18051959152410"><a name="p18051959152410"></a><a name="p18051959152410"></a>-b <em id="i35979186184"><a name="i35979186184"></a><a name="i35979186184"></a>n</em>，--buffer_size <em id="i144491624181811"><a name="i144491624181811"></a><a name="i144491624181811"></a>n</em></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p0805165932419"><a name="p0805165932419"></a><a name="p0805165932419"></a>指定<em id="i134241333181817"><a name="i134241333181817"></a><a name="i134241333181817"></a>n</em>(KB)内存大小用于存取trace日志，默认2048KB</p>
</td>
</tr>
<tr id="row580519592245"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p880510591241"><a name="p880510591241"></a><a name="p880510591241"></a>-t <em id="i8668143912203"><a name="i8668143912203"></a><a name="i8668143912203"></a>n</em>，--time <em id="i841433614202"><a name="i841433614202"></a><a name="i841433614202"></a>n</em></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1480517591245"><a name="p1480517591245"></a><a name="p1480517591245"></a>用来指定trace运行的时间（单位：s），取决于需要分析过程的时间</p>
</td>
</tr>
<tr id="row4806175913247"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p980655912242"><a name="p980655912242"></a><a name="p980655912242"></a>--trace_clock <em id="i19464452217"><a name="i19464452217"></a><a name="i19464452217"></a>clock</em></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p11806959142416"><a name="p11806959142416"></a><a name="p11806959142416"></a>trace输出的时钟类型，一般设备支持boot、global、mono、uptime、perf等，默认为boot</p>
</td>
</tr>
<tr id="row1280635917242"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p180715591244"><a name="p180715591244"></a><a name="p180715591244"></a>--trace_begin</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p480795916243"><a name="p480795916243"></a><a name="p480795916243"></a>启动抓trace</p>
</td>
</tr>
<tr id="row1580717599245"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p38073598242"><a name="p38073598242"></a><a name="p38073598242"></a>--trace_dump</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p148077595245"><a name="p148077595245"></a><a name="p148077595245"></a>将数据输出到指定位置（默认控制台）</p>
</td>
</tr>
<tr id="row180811592242"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p11808165922419"><a name="p11808165922419"></a><a name="p11808165922419"></a>--trace_finish</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p18809559182420"><a name="p18809559182420"></a><a name="p18809559182420"></a>停止抓trace，并将数据输出到指定位置（默认控制台）</p>
</td>
</tr>
<tr id="row2809185972420"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p2080925922418"><a name="p2080925922418"></a><a name="p2080925922418"></a>-l，--list_categories</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p38091159142414"><a name="p38091159142414"></a><a name="p38091159142414"></a>输出手机能支持的trace模块</p>
</td>
</tr>
<tr id="row1880912598248"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1681014595244"><a name="p1681014595244"></a><a name="p1681014595244"></a>--overwrite</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p12810165914248"><a name="p12810165914248"></a><a name="p12810165914248"></a>当缓冲区满的时候，将丢弃最新的信息。（默认丢弃最老的日志）</p>
</td>
</tr>
<tr id="row1181015992414"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p168101859152415"><a name="p168101859152415"></a><a name="p168101859152415"></a>-o <em id="i1367232742113"><a name="i1367232742113"></a><a name="i1367232742113"></a>filename</em>，--output <em id="i4305133012219"><a name="i4305133012219"></a><a name="i4305133012219"></a>filename</em></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p9810559132410"><a name="p9810559132410"></a><a name="p9810559132410"></a>指定输出的目标文件名称</p>
</td>
</tr>
<tr id="row8810155982415"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p381145912410"><a name="p381145912410"></a><a name="p381145912410"></a>-z</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1281117592249"><a name="p1281117592249"></a><a name="p1281117592249"></a>抓取trace后进行压缩</p>
</td>
</tr>
</tbody>
</table>

### bytrace命令使用举例<a name="section5402591174"></a>

以下是常用bytrace命令示例，供开发者参考：

-   查询支持的label。

```
bytrace -l  
```

或者

```
bytrace --list_categories
```

-   设置4M缓存，抓取10秒，抓取label为ability的trace信息。

```
bytrace -b 4096 -t 10 --overwrite ability > /data/mytrace.ftrace
```

-   设置trace的输出时钟为mono。

```
bytrace --trace_clock mono  -b 4096 -t 10 --overwrite ability > /data/mytrace.ftrace
```

-   抓取trace后进行压缩。

```
bytrace -z  -b 4096 -t 10 --overwrite ability > /data/mytrace.ftrace
```

