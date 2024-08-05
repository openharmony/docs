# hilog


HiLog日志系统，提供给系统框架、服务、以及应用，用于打印日志，记录用户操作、系统运行状态等。开发者可以通过hilog命令行查询相关日志信息。


## 前置条件

- 根据hdc命令行工具指导，完成[环境准备](hdc.md#环境准备)。

- 正常连接设备。


## 命令行说明

hilog命令行使用方式：

| 短选项 | 长选项 | 参数 | 说明 | 
| -------- | -------- | -------- | -------- |
| -h | --help |  | 帮助命令。 | 
| 缺省 | 缺省 |  | 阻塞读日志，不退出。 | 
| -x | --exit |  | 非阻塞读日志，读完退出。 | 
| -g |  |  | 查询buffer的大小，配合-t指定某一类型使用，默认app和core。 | 
| -G | --buffer-size | &lt;size&gt; | 设置指定&lt;type&gt;日志类型缓冲区的大小，配合-t指定某一类型使用，默认app和core， 可使用B/K/M/G为单位。 | 
| -r |  |  | 清除buffer日志，配合-t指定某一类型使用，默认app和core。 | 
| <!--DelRow-->-p | --privacy | &lt;on/off&gt; | 支持系统调试时日志隐私开关控制。 | 
| <!--DelRow--> |  | on | 打开隐私开关，显示&lt;private&gt;。 | 
| <!--DelRow--> |  | off | 关闭隐私开关，显示明文。 | 
| -k |  | &lt;on/off&gt; | Kernel日志读取开关控制。 | 
|  |  | on | 打开读取kernel日志。 | 
|  |  | off | 关闭读取kernel日志。 | 
| -s | --statistics |  | 查询统计信息，需配合-t或-D使用。 | 
| -S |  |  | 清除统计信息，需配合-t或-D使用。 | 
| -Q |  | &lt;control-type&gt; | 流控缺省配额开关控制。 | 
|  |  | pidon | 进程流控开关打开。 | 
|  |  | pidoff | 进程流控开关关闭。 | 
|  |  | domainon | domain流控开关打开。 | 
|  |  | domainoff | domain流控开关关闭。 | 
| -L | --level | &lt;level&gt; | 指定级别的日志，示例：-L D/I/W/E/F。 | 
| -t | --type | &lt;type&gt; | 指定类型的日志，示例：-t app core init。 | 
| -D | --domain | &lt;domain&gt; | 指定domain。 | 
| -T | --Tag | &lt;tag&gt; | 指定tag。 | 
| -a | --head | &lt;n&gt; | 只显示前&lt;n&gt;行日志。 | 
| -z | --tail | &lt;n&gt; | 只显示后&lt;n&gt;行日志。 | 
| -P | --pid | &lt;pid&gt; | 标识不同的pid。 | 
| -e | --regex | &lt;expr&gt; | 只打印日志消息与&lt;expr&gt;匹配的行，其中&lt;expr&gt;是一个正则表达式。 | 
| -f | --filename | &lt;filename&gt; | 设置落盘的文件名。 | 
| -l | --length | &lt;length&gt; | 设置落盘的文件大小，需要大于等于64K。 | 
| -n | --number | &lt;number&gt; | 设置落盘文件的个数。 | 
| -j | --jobid | &lt;jobid&gt; | 设置落盘任务的ID。 | 
| -w | --write | &lt;control&gt; | 落盘任务控制。 | 
|  |  | query | 落盘任务查询。 | 
|  |  | start | 落盘任务开始，命令行参数为文件名、单文件大小、落盘算法、rotate文件数目。 | 
|  |  | stop | 落盘任务停止。 | 
| -m | --stream | &lt;algorithm&gt; | 落盘方式控制。 | 
|  |  | none | 无压缩方式落盘。 | 
|  |  | zlib | zlib压缩算法落盘，落盘文件为.gz。 | 
|  |  | zstd | zstd压缩算法落盘，落盘文件为.zst。 | 
| -v | --format | &lt;format&gt; |  | 
|  |  | time | 显示本地时间。 | 
|  |  | color | 显示不同级别显示不同颜色，参数缺省级别颜色模式处理（按黑白方式）。 | 
|  |  | epoch | 显示相对1970时间。 | 
|  |  | monotonic | 显示相对启动时间。 | 
|  |  | usec | 显示微秒精度时间。 | 
|  |  | nsec | 显示纳秒精度时间。 | 
|  |  | year | 显示将年份添加到显示的时间。 | 
|  |  | zone | 显示将本地时区添加到显示的时间。 | 
| -b | --baselevel | &lt;loglevel&gt; | 设置可打印日志的最低等级：D(DEBUG)/I(INFO)/W(WARN)/E(ERROR)/F(FATAL)。 | 


### 查询相关命令

| 短选项 | 长选项 | 说明 | 
| -------- | -------- | -------- |
| -h | --help | 打印hilog的命令帮助信息。 | 


### 时间相关命令

| 短选项 | 长选项 | 参数 | 说明 | 
| -------- | -------- | -------- | -------- |
| -v | --format | &lt;format&gt; | 时间显示格式。 | 

**参数：**

| 参数名 | 说明 | 
| -------- | -------- |
| time | 显示本地时间。 | 
| color | 显示不同级别显示不同颜色，参数缺省级别颜色模式处理（按黑白方式）。 | 
| epoch | 显示相对1970时间。 | 
| monotonic | 显示相对启动时间。 | 
| usec | 显示微秒精度时间。 | 
| nsec | 显示纳秒精度时间。 | 
| year | 显示将年份添加到显示的时间。 | 
| zone | 显示将本地时区添加到显示的时间。 | 