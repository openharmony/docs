# toybox

toybox 是一个轻量级的Linux命令行工具集合，它将常用的Linux命令行工具合并到一个单独的可执行文件中。

## 前置条件

### 使用方法1：

- 正常连接设备
- 使用hdc shell进入命令行执行模式

### 使用方法2：

- 应用沙箱内运行

> **说明**：
>
>由于权限管控，当进程缺少进程、目录、文件的权限时，执行相关的命令会失败。
>如果遇到命令执行失败，请确认执行命令的进程是否拥有对应的权限，可以从日志里找到相应的报错。

## 命令行说明

toybox的执行方式有两种

- 使用toybox cmd [arg...]
- 创建cmd到toybox的软连接，直接调用cmd

系统已经创建好了软连接，可以直接使用各种命令。

| 选项 | 参数 | 说明 |
| :- | :- | :- |
| --help | NA | 显示命令帮助。 |
| --long | NA | 显示支持的所有命令的路径。 |
| NA | NA | 显示所有支持的命令。 |

### 帮助命令

格式：help [-ah] [command]

| 参数 | 说明 |
| :- | :- |
| command | 显示command的帮助。 |

| 选项 | 说明 |
| :- | :- |
| -a | 显示所有命令的帮助。 |
| -h | 以html格式显示帮助。 |

### 数学计算与随机数

| 命令 | 说明 |
| :- | :- |
| factor     | 分解因数。<br />usage: factor NUMBER... |
| mcookie    | 生成128位强随机数。<br />usage: mcookie [-vV] |
| uuidgen    | 创建并打印新的RFC4122随机UUID。<br />usage: uuidgen |

### 终端操作

| 命令 | 说明 |
| :- | :- |
| nohup | 运行一个独立于终端的命令。<br />usage: nohup [COMMAND [ARGS...]] |
| reset | 复位终端。<br />usage: reset |
| clear | 清空终端。<br />usage: clear |

### sh逻辑命令

| 命令 | 说明 |
| :- | :- |
| false | 返回非零值。<br />usage: false |
| sh    | shell命令解释器 |
| test  | 通过执行测试返回true或false。没有参数时返回false。<br />usage: test [-bcdefghLPrSsuwx PATH] [-nz STRING] [-t FD] [X ?? Y] |
| true  | 返回零。<br />usage: true |
| yes   | 反复输出行直到被杀死。如果没有参数，则输出“y”。<br />usage: yes [args...] |

### 系统调用操作（仅支持查询）

| 命令 | 说明 |
| :- | :- |
| hostname | 获取当前主机名。<br />usage: hostname [-bdsf] [-F FILENAME] [newname] |
| nproc    | 打印处理器数量。<br />usage: nproc [--all] |
| printenv | 打印环境变量。<br />usage: printenv [-0] [env\_var...] |
| uname    | 打印系统信息。<br />usage: uname [-asnrvm] |
| iotop    | 按I/O对进程进行排名。<br />usage: iotop [-AaKObq] [-n NUMBER] [-d SECONDS] [-p PID,] [-u USER,] |
| env      | 设置命令调用的环境，或列出环境变量。<br />usage: env [-i] [-u NAME] [NAME=VALUE...] [COMMAND [ARG...]] |

### 时间日期

| 命令 | 说明 |
| :- | :- |
| cal    | 打印日历。<br />usage: cal [[month] year] |
| date   | 获取当前日期/时间。<br />usage: date [-u] [-r FILE] [-d DATE] [+DISPLAY\_FORMAT] [-D  SET\_FORMAT] [SET] |
| sleep  | 等待设置的时间后再退出。可以是小数。可选的后缀可以是“m”（分钟）、“h”（小时）、“d”（天）或“s”（秒，默认值）。<br />usage: sleep DURATION... |
| time   | 运行命令行并报告真实时间、用户时间和系统时间（以秒为单位）。（真实时间=时钟时间，用户时间=命令代码使用cpu的时间，系统时间=操作系统使用cpu的时间。)<br />usage: time [-pv] COMMAND [ARGS...] |
| uptime | 显示当前时间，系统运行了多长时间，用户数量，以及过去1、5和15分钟的系统负载平均值。<br />usage: uptime [-ps] |
| usleep | 暂停微秒。<br />usage: usleep MICROSECONDS |

### 登录用户操作（仅支持查询）

| 命令 | 说明 |
| :- | :- |
| groups  | 打印用户所在的组。<br />usage: groups [user] |
| id      | 打印用户和组ID。<br />usage: id [-nGgru] [USER...] |
| logname | 打印当前用户名。<br />usage: logname |
| who     | 打印有关已登录用户的信息。 <br />usage: who |
| whoami  | 打印当前用户名。<br />usage: whoami |

### 进程操作

hdc shell运行时，仅支持pidof/ps/watch/xargs。<br />
应用沙箱内运行时，仅支持本应用pid namespace里的进程操作。
> **说明**：
>
>以下命令操作权限外的进程会失效。

| 命令 | 说明 |
| :- | :- |
| kill | 向进程发送信号。<br />usage: kill [-l [SIGNAL] \| -s SIGNAL \| -SIGNAL] PID... |
| killall | 向具有给定名称的所有进程发送信号（默认：Term）。<br />usage: killall [-l] [-iqv] [-SIGNAL \|-s SIGNAL ]  PROCESS\_NAME... |
| pidof   | 打印具有给定名称的所有进程的PID。<br />usage: pidof [-s] [-o omitpid[,omitpid...]] [NAME]... |
| pkill   | 按照进程名来杀死进程。<br />usage: pkill [-fnovx]  [-SIGNAL\|-l SIGNAL] [PATTERN] [-G GID,] [-g PGRP,] [-P PPID,] [-s SID,] [-t  TERM,] [-U UID,] [-u EUID,] |
| ps      | 列出进程。<br />usage: ps [-AadefLlnwZ] [-gG GROUP,] [-k FIELD,] [-o FIELD,] [-p PID,] [-t  TTY,] [-uU USER,] |
| pwdx    | 打印命令行中列出的进程的工作目录。<br />usage: pwdx PID... |
| timeout | 创建子进程执行命令，如果子进程超时未退出，则向子进程发送一个信号。DURATION可以是小数。可选的后缀可以是“m”（分钟）、“h”（小时）、“d”（天）或“s”（秒，默认值）。<br />usage: timeout [-k DURATION] [-s SIGNAL] DURATION COMMAND... |
| top     | 实时显示进程信息。<br />usage: top [-Hbq] [-k FIELD,] [-o FIELD,] [-s SORT] [-n NUMBER] [-m LINES]  [-d SECONDS] [-p PID,] [-u USER,] |
| iotop   | 实时显示进程信息（按I/O对进程进行排名）。<br />usage: iotop [-AaKObq] [-n NUMBER] [-d SECONDS] [-p PID,] [-u USER,] |
| watch   | 每隔-n秒运行一次参数中的命令，显示执行结果。按q退出。<br />usage: watch [-teb] [-n SEC] COMMAND ARGS |
| xargs   | 运行命令行一次或多次，附加标准输入设备中的参数。<br />usage: xargs [-0prt] [-s NUM] [-n NUM] [-E STR]  COMMAND... |

### 设备节点操作(仅支持查询)

| 命令 | 说明 |
| :- | :- |
| df    | 显示命令行中列出的每个文件系统的总共、已使用和空闲的磁盘空间。无参数时显示已装载的所有文件系统。<br />usage: df [-HPkhi] [-t type] [FILESYSTEM...] |
| du    | 显示磁盘使用情况，文件和目录占用的空间。<br />usage: du [-d N] [-askxHLlmc] [file...] |
| free  | 显示物理内存和交换空间的总量、可用量和已用量。<br />usage: free [-bkmgt] |
| mount | 在目录上挂载新的文件系统。如果没有参数，则显示现有的挂载。<br />usage: mount [-afFrsvw] [-t TYPE] [-o OPTION,] [[DEVICE] DIR] |

### 文件操作（仅支持操作本应用沙箱的文件）

| 命令 | 说明 |
| :- | :- |
| base64    | 通过base64算法进行加密/解密。<br />usage: base64 [-di] [-w COLUMNS] [FILE...] |
| basename  | 返回删除后缀的路径名的非目录部分。<br />usage: basename [-a] [-s SUFFIX] NAME... \| NAME [SUFFIX] |
| cat       | 复制（连接）文件到标准输出设备。如果未列出任何文件，则从标准输入设备复制。“-”代表标准输入设备<br />usage: cat [-etuv] [FILE...] |
| chmod     | 更改列出的文件的模式（使用-R递归）。<br />usage: chmod [-R] MODE FILE... |
| cksum     | 对于每个文件，输出crc32的校验和、长度和文件名。如果未列出任何文件，则从标准输入设备复制。“-”代表标准输入设备<br />usage: cksum [-IPLN] [FILE...] |
| cmp       | 比较文件的内容（如果只给出一个，则与标准输入设备进行比较），可选在开始时跳过字节。<br />usage: cmp [-l] [-s] FILE1 [FILE2 [SKIP1 [SKIP2]]] |
| comm      | 读取FILE1和FILE2（这两个文件应该是有序的），并生成三个文本列作为输出：仅在FILE1中的行；仅在FILE2中的行；在两个文件中。“-”代表标准输入设备<br />usage: comm [-123] FILE1 FILE2  |
| count     | 将标准输入设备复制到标准输出设备，将简单的进度指示器显示到标准错误输出stderr。<br />usage: count |
| cp        | 将文件从SOURCE复制到DEST。如果有多个源，DEST必须是一个目录。<br />usage: cp [--preserve=motcxa] [-adlnrsvfipRHLP] SOURCE...  [DEST] |
| cpio      | 将文件复制到和从“newc”格式的cpio归档文件中。<br />usage: cpio -{o\|t\|i\|p DEST} [-v] [--verbose] [-F FILE] [--no-preserve-owner] [ignored: -mdu -H newc] |
| crc32     | 输出每个文件的crc32校验和。<br />usage: crc32 [file...] |
| cut       | 将每个FILE中的行的选定部分打印到标准输出。每个选择列表以逗号分隔，可以是数字（从1开始计数）或破折号分隔的范围(包括，其中X-表示行尾，-X表示行尾从开始)。默认情况下，选择范围是排序和校对的，使用-D来防止这种情况的发生。<br />usage: cut [-Ds] [-bcCfF LIST] [-dO DELIM] [FILE...] |
| dd        |  用于转换和复制文件的命令，可以用于创建磁盘镜像、备份数据、转换字符编码等任务。<br />usage: dd [if=FILE] [of=FILE] [ibs=N] [obs=N] [iflag=FLAGS] [oflag=FLAGS][bs=N] [count=N] [seek=N] [skip=N][conv=notrunc\|noerror\|sync\|fsync] [status=noxfer\|none] |
| dirname   | 显示路径的目录部分。<br />usage: dirname PATH... |
| dos2unix  | 将换行符格式从dos“\\r\\n”转换为unix“\\n”。如果没有列出文件，从标准输入设备获取输入。“-”代表标准输入设备。<br />usage: dos2unix [FILE...] |
| echo      | 将每个参数写入标准输出设备，每个参数之间有一个空格，后跟一个换行符。<br />usage: echo [-neE] [args...] |
| egrep     | 显示匹配正则表达式的行。如果没有-e，则第一个参数为要匹配的正则表达式。没有文件（或“-”文件名）读取标准输入设备。如果匹配，则返回0；如果找不到匹配，则返回1；如果命令错误，则返回2。<br />usage: egrep [-EFrivwcloqsHbhn] [-ABC NUM] [-m MAX] [-e REGEX]... [-MS  PATTERN]... [-f REGFILE] [FILE]... |
| expand    | 根据制表符展开制表符为空格。<br />usage: expand [-t TABLIST] [FILE...] |
| fgrep     | 显示匹配正则表达式的行。如果没有-e，则第一个参数为要匹配的正则表达式。没有文件（或“-”文件名）读取标准输入设备。如果匹配，则返回0；如果找不到匹配，则返回1；如果命令错误，则返回2。<br />usage: fgrep [-EFrivwcloqsHbhn] [-ABC NUM] [-m MAX] [-e REGEX]... [-MS  PATTERN]... [-f REGFILE] [FILE]... |
| file      | 检查给定的文件并描述其内容类型。<br />usage: file [-bhLs] [file...] |
| find      | 在目录中搜索匹配的文件。默认：搜索“.”，匹配所有，-print匹配。<br />usage: find [-HL] [DIR...] [&lt;options&gt;] |
| fmt       | 将输入重新格式化为给定行长的换行，保留现有的缩进级别，写入标准输出设备。<br />usage: fmt [-w WIDTH] [FILE...] |
| grep      | 显示与正则表达式匹配的行。<br />usage: grep [-EFrivwcloqsHbhn] [-ABC NUM] [-m MAX] [-e REGEX]... [-MS  PATTERN]... [-f REGFILE] [FILE]... |
| gunzip    | 解压文件。如果没有文件，则将标准输入设备解压为标准输出设备。成功后，输入文件将被删除并替换为新的没有.gz后缀的文件。<br />usage: gunzip [-cfkt] [FILE...] |
| head      | 将文件中的第一行复制到标准输出设备中。如果未列出任何文件从标准输入设备拷贝. “-”代表标准输入设备<br />usage: head [-n number] [file...] |
| ls        | 查看当前目录有哪些文件/文件夹。<br />usage: ls [-ACFHLRSZacdfhiklmnpqrstux1] [--color[=auto]] [directory...] |
| lsattr    | 列出Linux文件系统中的文件属性。标志字母在chattr帮助中定义。<br />usage: lsattr [-Radlv] [Files...] |
| lsof      | 列出属于所有活动进程的所有打开的文件，或使用列出的FILE的进程。<br />usage: lsof [-lt] [-p PID1,PID2,...] [FILE...] |
| md5sum    | 计算每个输入文件的哈希，如果没有，则从标准输入设备读取。每个输入文件输出一行哈希后跟文件名。<br />usage: md5sum [-bcs] [FILE]... |
| mkdir     | 创建一个或多个目录。<br />usage: mkdir [-vp] [-m mode] [dirname...] |
| mktemp    | 安全地创建一个新文件“DIR/TEMPLATE”并打印其名称。<br />usage: mktemp [-dqu] [-p DIR] [TEMPLATE] |
| mv        | 移动或重命名文件。<br />usage: mv [-fivn] SOURCE... DEST |
| nl        | 输入的行数。<br />usage: nl [-E] [-l #] [-b MODE] [-n STYLE] [-s SEPARATOR] [-v #] [-w WIDTH]  [FILE...] |
| od        | 以八进制/十六进制格式转储数据。<br />usage: od [-bcdosxv] [-j #] [-N #] [-w #] [-A doxn] [-t acdfoux[#]] |
| paste     | 从每个输入文件中合并相应的行。<br />usage: paste [-s] [-d DELIMITERS] [FILE...] |
| patch     | 将统一的diff应用于一个或多个文件。<br />usage: patch [-d DIR] [-i file] [-p depth] [-Rlsu] [--dry-run] |
| pgrep     | 查找进程(es)。PATTERN是检查的扩展正则表达式与命令名称对应。<br />usage: pgrep [-clfnovx] [-d DELIM] [-L SIGNAL] [PATTERN] [-G GID,] [-g  PGRP,] [-P PPID,] [-s SID,] [-t TERM,] [-U UID,] [-u EUID,] |
| printf    | 使用C  printf语法，根据Format格式化并打印（对于cdeEfgGiosuxX, \\转义为abefnrtv0或\\OCTAL或\\xHEX）。<br />usage: printf FORMAT [ARGUMENT...] |
| pwd       | 打印工作（当前）目录。<br />usage: pwd [-L\|-P] |
| readahead | 将文件预加载到磁盘缓存中。<br />usage: readahead FILE... |
| readlink  | 如果没有选项，则显示symlink指向什么，如果不是symlink则返回错误。<br />usage: readlink FILE... |
| realpath  | 显示规范绝对路径名。<br />usage: realpath FILE... |
| rev       | 逆向输出每一行。<br />usage: rev [FILE...] |
| rm        | 删除文件。<br />usage: rm [-fiRrv] FILE... |
| rmdir     | 删除一个或多个目录。<br />usage: rmdir [-p] [dirname...] |
| sed       | 流编辑器。将编辑脚本应用于输入行。<br />usage: sed [-inrszE] [-e SCRIPT]...\|SCRIPT [-f SCRIPT\_FILE]... [FILE...] |
| seq       | 从头到尾按递增计数。省略参数默认值为1。使用两个参数作为第一个和最后一个。参数可以是负数或浮点数。<br />usage: seq [-w\|-f fmt\_str] [-s sep\_str] [first] [increment] last |
| sort      | 对从输入文件（或标准输入设备）到标准输出设备的所有文本行进行排序。<br />usage: sort [-Mbcdfginrsuz] [FILE...] [-k#[,#[x]] [-t X]] [-o FILE] |
| split     | 将输入（或标准输入设备）数据复制到一系列输出（或“x”）文件，使用按字母顺序递增的后缀（aa,ab,ac...az,ba,bb...）。<br />usage: split [-a SUFFIX\_LEN] [-b BYTES] [-l LINES] [INPUT [OUTPUT]] |
| stat      | 显示文件或文件系统的状态。<br />usage: stat [-tfL] [-c FORMAT] FILE... |
| strings   | 在二进制文件中显示可打印字符串<br />usage: strings [-fo] [-t oxd] [-n LEN] [FILE...] |
| tac       | 以相反的顺序输出行。<br />usage: tac [FILE...] |
| tail      | 将文件中的最后一行复制到标准输出设备中。“-”代表标准输入设备<br />usage: tail [-n\|c NUMBER] [-f] [FILE...] |
| tar       | 在.tar文件中创建、解压缩或列出文件。<br />usage: tar [-cxt] [-fvohmjkOS] [-XTCf NAME] [FILE...] |
| tee       | 将标准输入设备复制到每个列出的文件，也复制到标准输出设备。文件名“-”是标准输出设备的同义词。<br />usage: tee [-ai] [FILE...] |
| touch     | 更新每个FILE的访问和修改时间为当前时间。<br />usage: touch [-amch] [-d DATE] [-t TIME] [-r FILE] FILE... |
| truncate  | 设置文件的长度，必要时稀疏扩展。<br />usage: truncate [-c] -s SIZE file... |
| uniq      | 报告或过滤文件中的重复行。<br />usage: uniq [-cduiz] [-w MAXCHARS] [-f FIELDS] [-s CHAR] [INFILE [OUTFILE]] |
| unix2dos  | 将换行符格式从unix“\\n”转换为dos“\\r\\n”。如果没有列出文件，从标准输入设备获取输入。“-”是标准输入设备的同义词。<br />usage: unix2dos [FILE...] |
| unlink    | 删除一个文件。<br />usage: unlink FILE |
| uudecode  | 从标准输入设备（或INFILE）解码文件。<br />usage: uudecode [-o OUTFILE] [INFILE] |
| uuencode  | Uuencode  标准输入设备（或INFILE）到标准输出设备，在输出中使用ENCODE\_FILENAME。<br />usage: uuencode [-m] [INFILE] ENCODE\_FILENAME |
| wc        | 统计输入中的行数、单词和字符。<br />usage: wc -lwcm [FILE...] |
| which     | 在\$PATH中搜索与文件名匹配的可执行文件。<br />usage: which [-a] filename ... |
| xxd       | Hexdump将文件转储到标准输出设备。若没有列出任何文件，请从标准输入设备复制。<br />usage: xxd [-c n] [-g n] [-i] [-l n] [-o n] [-p] [-r] [-s n] [file] |
| zcat      |将文件解压缩到标准输出设备。比如“gzip-dc”。<br /> usage: zcat [FILE...] |
