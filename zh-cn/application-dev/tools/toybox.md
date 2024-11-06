# toybox

toybox 是一个轻量级的Linux命令行工具集合，它将常用的Linux命令行工具合并到一个单独的可执行文件中。

## 前置条件

### 使用方法1：

- 正常连接设备
- 使用hdc shell进入命令行执行模式

### 使用方法2：

- 应用沙箱内运行


## 命令行说明

toybox的执行方式有两种
- toybox [command] [arguments...]
- 直接执行 [command] [arguments...]

其中 [command] 可被替换为toybox支持的任意命令（可通过输入不带参数的toybox命令查询）。
[arguments...] 为[command]所需要的参数

<!--RP1-->
<!--RP1End-->

### 帮助命令
格式：toybox [--long | --help | --version | [command] [arguments...]]
| 选项 | 参数 | 说明 |
| :- | :- | :- |
| --help | NA | 显示命令帮助。 |
| --long | NA | 显示支持的所有命令的路径。 |
| --version | NA | 显示版本号。|
| NA | NA | 显示所有[command]支持的命令。 |
| [command] | [arguments] | 执行具体的命令。大部分命令也支持--help和--version参数 |

格式：help [-ah] [command]
| 参数 | 说明 |
| :- | :- |
| command | 显示command的帮助。[command] 可被替换为toybox支持的任意命令 |

| 选项 | 说明 |
| :- | :- |
| -a | 显示所有命令的帮助。 |
| -h | 以html格式显示帮助。 |

### 数学与计算机基础函数

| 命令 | 说明 |
| :- | :- |
| ascii     | 显示acsii编码表。<br />usage: ascii |
| factor     | 分解质因数。<br />usage: factor NUMBER... |
| mcookie    | 生成128位强随机数。<br />usage: mcookie [-vV] |
| mkpasswd | 对密码进行加密。<br />usage: mkpasswd [-P FD] [-m TYPE] [-S SALT] [PASSWORD] [SALT] |
| uuidgen    | 创建并打印新的RFC4122随机UUID。<br />usage: uuidgen |

### 终端操作

| 命令 | 说明 |
| :- | :- |
| chvt   | 切换到虚拟终端N。<br />usage: chvt N |
| chroot | 以指定的根目录运行命令。<br />usage: chroot NEWROOT [COMMAND [ARG...]] |
| clear  | 清空终端。<br />usage: clear |
| nohup  | 运行一个独立于终端的命令。<br />usage: nohup COMMAND [ARG...] |
| tty    | 显示连接到标准输入设备的终端的名称。<br />usage: tty [-s] |
| reset  | 复位终端。<br />usage: reset |
| microcom | 简单串口终端。<br />usage: microcom [-s SPEED] [-X] DEVICE |

### sh逻辑命令

| 命令 | 说明 |
| :- | :- |
| false | 返回非零值。<br />usage: false |
| sh    | shell命令解释器 |
| test  | 通过执行测试返回true或false。没有参数时返回false。<br />usage: test [-bcdefghLPrSsuwx PATH] [-nz STRING] [-t FD] [X ?? Y] |
| true  | 返回零。<br />usage: true |
| yes   | 反复输出行直到被杀死。如果没有参数，则输出“y”。<br />usage: yes [args...] |

### 系统操作

| 命令 | 说明 |
| :- | :- |
| acpi      | 查询电源、温度状态。<br />usage: acpi [-abctV] |
| arch      | 打印系统名称。<br />usage: arch |
| dmesg     | 显示或控制内核环形缓冲区。<br />usage: dmesg [-Cc] [-r \| -t \| -T] [-n LEVEL] [-s SIZE] [-w] |
| dnsdomainname | 显示系统的名称（与 hostname -d 一致）。<br />usage: dnsdomainname |
| getconf   | 获取系统配置值，部分值需要path参数。<br />usage: getconf -a [PATH] \| -l \| NAME [PATH] |
| env       | 设置命令调用的环境，或列出环境变量。<br />usage: env [-i] [-u NAME] [NAME=VALUE...] [COMMAND [ARG...]] |
| hostname  | 获取当前主机名。<br />usage: hostname [-bdsf] [-F FILENAME] [newname] |
| insmod    | 加载内核模块。<br />usage: insmod MODULE [MODULE_OPTIONS] |
| logger    | 记录系统日志。<br />usage: logger [-s] [-t TAG] [-p [FACILITY.]PRIORITY] [message...] |
| lsmod     | 显示当前已经加载的模块，他们的大小和依赖。<br />usage: lsmod |
| mix       | 显示OSS声道，或者设置音量。<br />usage: mix [-d DEV] [-c CHANNEL] [-l VOL] [-r RIGHT] |
| modinfo   | 显示内核模块信息。<br />usage: modinfo [-0] [-b basedir] [-k kernel] [-F field] [module \| file...] |
| nproc     | 打印处理器数量。<br />usage: nproc [--all] |
| oneit     | 简单的初始化程序。<br />usage: oneit [-p] [-c /dev/tty0] command [...] |
| partprobe | 通知内核分区表已经变化。<br />usage: partprobe DEVICE... |
| pivot_root | 修改根目录。<br />usage: pivot_root OLD NEW |
| printenv  | 打印环境变量。<br />usage: printenv [-0] [env\_var...] |
| reboot/halt/poweroff | 重启/停止/关机。<br />usage: reboot/halt/poweroff [-fn] |
| rfkill    | 开启/关闭无线设备。<br />usage: rfkill COMMAND [DEVICE] |
| rmmod     | 卸载内核模块。<br />usage: rmmod [-wf] [MODULE] |
| sendevent | 发送Linux输入事件。<br />usage: sendevent DEVICE TYPE CODE VALUE |
| swapoff   | 停用交换空间。<br />usage: swapoff swapregion |
| swapon    | 在指定的设备或文件上，使能内存交换。<br />usage: swapon [-d] [-p priority] filename |
| switch_root | 切换根目录，并执行新的INIT程序。<br />usage: switch_root [-c /dev/console] NEW_ROOT NEW_INIT... |
| uname     | 打印系统信息。<br />usage: uname [-asnrvm] |
| vmstat    | 打印虚拟内存信息。<br />usage: vmstat [-n] [DELAY [COUNT]] |

### 时间日期

| 命令 | 说明 |
| :- | :- |
| cal     | 打印日历。<br />usage: cal [[month] year] |
| date    | 设置/获取当前日期/时间。<br />usage: date [-u] [-r FILE] [-d DATE] [+DISPLAY\_FORMAT] [-D SET\_FORMAT] [SET] |
| hwclock | 获取/设置硬件时钟。<br />usage: hwclock [-rswtluf] |
| sleep   | 等待设置的时间后再退出。可以是小数。可选的后缀可以是“m”（分钟）、“h”（小时）、“d”（天）或“s”（秒，默认值）。<br />usage: sleep DURATION |
| time    | 运行命令行并报告真实时间、用户时间和系统时间（以秒为单位）。(真实时间=时钟时间，用户时间=命令代码使用cpu的时间，系统时间=操作系统使用cpu的时间。)<br />usage: time [-pv] COMMAND [ARGS...] |
| uptime  | 显示当前时间，系统运行了多长时间，用户数量，以及过去1、5和15分钟的系统负载平均值。<br />usage: uptime [-ps] |
| usleep  | 等待设置的时间后再退出，单位微秒。<br />usage: usleep MICROSECONDS |

### 登录用户操作

| 命令 | 说明 |
| :- | :- |
| groups  | 打印用户所在的组。<br />usage: groups [user] |
| id      | 打印用户和组ID。<br />usage: id [-nGgru] [USER...] |
| login   | 用户登录。<br />usage: login [-p] [-h host] [-f USERNAME] [USERNAME] |
| logname/whoami | 打印当前用户名。<br />usage: logname/whoami |
| passwd  | 更新用户的认证令牌。<br />usage: passwd [-a ALGO] [-dlu] [USER] |
| who     | 打印有关已登录用户的信息。 <br />usage: who |
| w       | 显示用户登录情况和登录时间。<br />usage: w |

### 进程操作

| 命令 | 说明 |
| :- | :- |
| chrt      | 获取/设置一个进程的调度策略和优先级。<br />usage: chrt [-Rmofrbi] {-p PID [PRIORITY] \| [PRIORITY COMMAND...]} |
| iorenice  | 显示/修改一个进程的IO优先级。<br />usage: iorenice PID [CLASS] [PRIORITY] |
| iotop     | 根据I/O对进程排序。<br />usage: iotop [-AaKObq] [-n NUMBER] [-d SECONDS] [-p PID,] [-u USER,] |
| ionice    | 显示/修改一个进程的IO调度优先级。<br />usage: ionice [-t] [-c CLASS] [-n LEVEL] [COMMAND...\|-p PID] |
| kill      | 向进程发送信号。<br />usage: kill [-l [SIGNAL] \| -s SIGNAL \| -SIGNAL] pid... |
| killall   | 向具有给定名称的所有进程发送信号（默认：SIGTERM）。<br />usage: killall [-l] [-iqv] [-SIGNAL \| -s SIGNAL]  PROCESS\_NAME... |
| killall5  | 对当前会话以外的所有进程发送信号。<br />usage: killall5 [-l [SIGNAL]] [-SIGNAL \| -s SIGNAL] [-o PID]... |
| pidof   | 打印具有给定名称的所有进程的PID。<br />usage: pidof [-s] [-o omitpid[,omitpid...]] [NAME...] |
| pkill   | 按照进程名来杀死进程。<br />usage: pkill [-fnovx] [-SIGNAL \| -l SIGNAL] [PATTERN] [-G GID,] [-g PGRP,] [-P PPID,] [-s SID,] [-t TERM,] [-U UID,] [-u EUID,] |
| pmap    | 查看进程的内存映射情况。<br />usage: pmap [-xq] [pids...] |
| ps      | 显示进程信息。<br />usage: ps [-AadefLlnwZ] [-gG GROUP,] [-k FIELD,] [-o FIELD,] [-p PID,] [-t TTY,] [-uU USER,] |
| pwdx    | 打印进程的工作目录。<br />usage: pwdx PID... |
| renice  | 调整进程/组/用户级别的进程优先级。<br />usage: renice [-gpu] -n increment ID ... |
| setsid  | 在新的会话中运行命令。<br />usage: setsid [-t] command [args...] |
| taskset | 启动一个仅在指定处理器上运行的任务，或者修改已经存在的进程的处理器偏好。<br />usage: taskset [-ap] [mask] [PID \| cmd [args...]] |
| timeout | 创建子进程执行命令，如果子进程超时未退出，则向子进程发送一个信号。DURATION可以是小数。可选的后缀可以是“m”（分钟）、“h”（小时）、“d”（天）或“s”（秒，默认值）。<br />usage: timeout [-k DURATION] [-s SIGNAL] DURATION COMMAND... |
| top     | 实时显示进程信息。<br />usage: top [-Hbq] [-k FIELD,] [-o FIELD,] [-s SORT] [-n NUMBER] [-m LINES] [-d SECONDS] [-p PID,] [-u USER,] |
| nice    | 以指定的优先级运行命令。<br />usage: nice [-n PRIORITY] COMMAND [ARG...] |
| nsenter | 在特定的命名空间中运行指令。<br />usage: nsenter [-t pid] [-F] [-i] [-m] [-n] [-p] [-u] [-U] COMMAND... |
| ulimit/prlimit | 显示或者设置进程的资源限制。<br />usage: ulimit/prlimit [-P PID] [-SHRacdefilmnpqrstuv] [LIMIT] |
| unshare | 给一个进程创建新的命名空间，部分属性不与父进程共享。<br />usage: unshare [-imnpuUr] COMMAND... |
| watch   | 每隔-n秒运行一次参数中的命令，显示执行结果。按q退出。<br />usage: watch [-teb] [-n SEC] PROG ARGS |
| xargs   | 运行命令行一次或多次，附加标准输入设备中的参数。<br />usage: xargs [-0prt] [-s NUM] [-n NUM] [-E STR] COMMAND... |

### 设备节点操作

| 命令 | 说明 |
| :- | :- |
| blkid       | 打印文件系统的类型，标签和UUID等信息。<br />usage: blkid [-s TAG] [-UL] DEV... |
| blockdev    | 对每个命令中的块设备调用ioctl。<br />usage: blockdev --OPTION... BLOCKDEV... |
| devmem      | 通过 /dev/mem 读写物理地址。<br />usage: devmem ADDR [WIDTH [DATA]] |
| df          | 显示命令行中列出的每个文件系统的总共、已使用和空闲的磁盘空间。无参数时显示已装载的所有文件系统。<br />usage: df [-HPkhi] [-t type] [FILESYSTEM ...] |
| du          | 显示磁盘使用情况，文件和目录占用的空间。<br />usage: du [-d N] [-askxHLlmc] [file...] |
| eject       | 弹出设备，默认为 /dev/cdrom 。<br />usage: eject [-stT] [DEVICE] |
| free        | 显示物理内存和交换空间的总量、可用量和已用量。<br />usage: free [-bkmgt] |
| freeramdisk | 释放特定ramdisk的所有内存。<br />usage: freeramdisk [RAM device] |
| fsfreeze    | 冻结或解冻一个文件系统。<br />usage: fsfreeze {-f \| -u} MOUNTPOINT |
| fstype      | 打印文件系统的类型。<br />usage: fstype DEV... |
| fsync       | 将文件状态与存储设备同步。<br />usage: fsync [-d] [FILE...] |
| i2cdetect   | 检测 i2c 设备。<br />usage:<br />&emsp;i2cdetect [-ary] BUS [FIRST LAST] <br />&emsp;i2cdetect -F BUS<br />&emsp;i2cdetect -l|
| i2cdump     | 打印所有 i2c 寄存器。<br />usage: i2cdump [-fy] BUS CHIP |
| i2cget      | 读取 i2c 寄存器。<br />usage: i2cget [-fy] BUS CHIP ADDR |
| i2cset      | 写 i2c 寄存器。<br />usage: i2cset [-fy] BUS CHIP ADDR VALUE... MODE |
| losetup     | 设置循环设备。<br />usage: losetup [-cdrs] [-o OFFSET] [-S SIZE] {-d DEVICE... \| -j FILE \| -af \| {DEVICE FILE}} |
| lspci       | 显示 PCI 设备信息。<br />usage: lspci [-ekmn] [-i FILE ] |
| lsusb       | 显示 USB 设备信息。<br />usage: lsusb |
| makedevs    | 创建一系列特殊的文件，包括块设备文件，字符设备文件等。<br />usage: makedevs [-d device_table] rootdir |
| mount       | 在目录上挂载新的文件系统。如果没有参数，则显示现有的挂载。<br />usage: mount [-afFrsvw] [-t TYPE] [-o OPTION,] [[DEVICE] DIR] |
| mountpoint  | 检查目录或者设备是否是挂载点。<br />usage:<br />&emsp;mountpoint [-qd] DIR <br />&emsp;mountpoint [-qx] DEVICE |
| sync        | 将缓存的数据写到磁盘，。<br />usage: sync |
| sysctl      | 读写 /proc/sys 下的系统控制数据。<br />usage: sysctl [-aAeNnqw] [-p [FILE] \| KEY[=VALUE]...] |
| tunctl      | 创建或删除tun/tap虚拟以太设备。<br />usage: tunctl [-dtT] [-u USER] NAME |
| vconfig     | 创建或删除虚拟以太设备。<br />usage: vconfig COMMAND [OPTIONS] |
| umount      | 取消挂载文件系统。<br />usage: umount [-a [-t TYPE[,TYPE...]]] [-vrfD] [DIR...] |

### 网络操作

| 命令 | 说明 |
| :- | :- |
| ftpget/ftpput | 与FTP服务器沟通，支持读、写、列举文件等操作。ftpget自带-g选项。ftpput自带-s选项。<br />usage: ftpget/ftpput [-cvgslLmMdD] [-p PORT] [-P PASSWORD] [-u USER] HOST [LOCAL] REMOTE |
| ifconfig      | 显示或配置网络接口。<br />usage: ifconfig [-aS] [INTERFACE [ACTION...]] |
| nbd-client    | 创建nbd客户端。<br />usage: nbd-client [-ns] HOST PORT DEVICE |
| netstat   | 显示网络信息。<br />usage: netstat [-pWrxwutneal] |
| ping/ping6    | 检测网络连通性。ping6自带-6选项。<br />usage: ping/ping6 [OPTIONS] HOST |
| sntp    | SNTP客户端。<br />usage: sntp [-saSdDqm] [-r SHIFT] [-m ADDRESS] [-p PORT] [SERVER] |
| telnet  | 连接telnet服务器。<br />usage: telnet HOST [PORT] |
| traceroute/traceroute6 | 跟踪报文到HOST的路径。traceroute6自带-6选项。<br />usage: traceroute [-46FUIldnvr] [-f 1ST_TTL] [-m MAXTTL] [-p PORT] [-q PROBES] [-s SRC_IP] [-t TOS] [-w WAIT_SEC] [-g GATEWAY] [-i IFACE] [-z PAUSE_MSEC] HOST [BYTES]<br />usage: traceroute6 [-dnrv] [-m MAXTTL] [-p PORT] [-q PROBES][-s SRC_IP] [-t TOS] [-w WAIT_SEC] [-i IFACE] HOST [BYTES] |
| wget    | 从网络上下载资源。<br />usage: wget [OPTIONS]... [URL] |

### 文件操作

| 命令 | 说明 |
| :- | :- |
| awk       | awk是一个处理文本的工具，可对文档内容进行筛选、分析。<br />usage: awk [-F sepstring] [-v assignment]... program [argument...]<br />&emsp;awk [-F sepstring] -f progfile [-v assignment]... [argument...] |
| base64    | 通过base64算法进行加密/解密。<br />usage: base64 [-di] [-w COLUMNS] [FILE...] |
| basename  | 返回删除后缀的路径名的非目录部分。<br />usage: basename [-a] [-s SUFFIX] NAME... \| NAME [SUFFIX] |
| bunzip2   | 解压bz格式的文件。<br />usage: bunzip2 [-cftkv] [FILE...] |
| bzcat     | 解压列举的文件到标准输出。<br />usage: bzcat [FILE...] |
| cat       | 复制（连接）文件到标准输出设备。如果未列出任何文件，则从标准输入设备复制。“-”代表标准输入设备<br />usage: cat [-etuv] [FILE...] |
| chattr    | 修改Linux ext2文件系统的文件属性。<br />usage: chattr [-R] [-+=AacDdijsStTu] [-v version] [File...] |
| chcon     | 修改文件的SELinux安全上下文。<br />usage: chcon [-hRv] CONTEXT FILE... |
| chgrp/chown | 修改文件的组。<br />usage: chgrp/chown [-RHLP] [-fvh] group file... |
| chmod     | 更改列出的文件的模式（使用-R递归）。<br />usage: chmod [-R] MODE FILE... |
| cksum     | 对于每个文件，输出crc32的校验和、长度和文件名。如果未列出任何文件，则从标准输入设备复制。“-”代表标准输入设备<br />usage: cksum [-IPLN] [file...] |
| cmp       | 比较文件的内容（如果只给出一个，则与标准输入设备进行比较），可选在开始时跳过字节。<br />usage: cmp [-l] [-s] FILE1 [FILE2 [SKIP1 [SKIP2]]] |
| comm      | 读取FILE1和FILE2（这两个文件应该是有序的），并生成三个文本列作为输出：仅在FILE1中的行；仅在FILE2中的行；在两个文件中都有的行。“-”代表标准输入设备<br />usage: comm [-123] FILE1 FILE2  |
| count     | 将标准输入设备复制到标准输出设备，将简单的进度指示器显示到标准错误输出stderr。<br />usage: count |
| cp        | 将文件从SOURCE复制到DEST。如果有多个源，DEST必须是一个目录。<br />usage: cp [--preserve=motcxa] [-adlnrsvfipRHLP] SOURCE... DEST |
| cpio      | 从“newc”格式的cpio档案中中读写文件。<br />usage: cpio -{o\|t\|i\|p DEST} [-v] [--verbose] [-F FILE] [--no-preserve-owner]<br />&emsp;[ignored: -mdu -H newc] |
| crc32     | 输出每个文件的crc32校验和。<br />usage: crc32 [file...] |
| cut       | 将每个FILE中的行的选定部分打印到标准输出。每个选择列表以逗号分隔，可以是数字（从1开始计数）或破折号分隔的范围(其中X-表示X到行尾，-X表示从开始到X)。<br />usage: cut [-Ds] [-bcfF LIST] [-dO DELIM] [FILE...] |
| dd        |  用于转换和复制文件的命令，可以用于创建磁盘镜像、备份数据、转换字符编码等任务。<br />usage:<br />&emsp; dd [if=FILE] [of=FILE] [ibs=N] [obs=N] [iflag=FLAGS] [oflag=FLAGS]<br />&emsp; [bs=N] [count=N] [seek=N] [skip=N]<br />&emsp; [conv=notrunc\|noerror\|sync\|fsync] [status=noxfer\|none] |
| diff      | 比较文件/文件夹，输出差异。<br />usage: diff [-abBdiNqrTstw] [-L LABEL] [-S FILE] [-U LINES] FILE1 FILE2 |
| dirname   | 显示路径的目录部分。<br />usage: dirname PATH... |
| dos2unix  | 将换行符格式从dos“\\r\\n”转换为unix“\\n”。如果没有列出文件，从标准输入设备获取输入。“-”代表标准输入设备。<br />usage: dos2unix [FILE...] |
| echo      | 将每个参数写入标准输出设备，每个参数之间有一个空格，后跟一个换行符。<br />usage: echo [-neE] [args...] |
| grep/egrep/fgrep | 显示匹配正则表达式的行。如果没有-e，则第一个参数为要匹配的正则表达式。没有文件（或“-”文件名）读取标准输入设备。如果匹配，则返回0；如果找不到匹配，则返回1；如果命令错误，则返回2。<br />egrep自带-E选项，fgrep自带-F选项。E和F选项不能同时选。<br />usage: grep/egrep/fgrep [-EFrivwcloqsHbhn] [-ABC NUM] [-m MAX] [-e REGEX]... [-MS PATTERN]... [-f REGFILE] [FILE]... |
| gzip      | 压缩文件。<br />usage: gzip [-19cdfk] [FILE...] |
| expand    | 根据输入参数将制表符展开为空格。<br />usage: expand [-t TABLIST] [FILE...] |
| fallocate | 让文件系统给文件预留空间。<br />usage: fallocate [-l size] [-o offset] file |
| file      | 检查给定的文件并描述其内容类型。<br />usage: file [-bhLs] [file...] |
| find      | 在目录中搜索匹配的文件。<br />usage: find [-HL] [DIR...] [&lt;options&gt;] |
| flock     | 管理文件锁(advisory lock)。<br />usage: flock [-sxun] fd |
| fmt       | 将输入重新格式化为给定行长的换行，保留现有的缩进级别，写入标准输出设备。<br />usage: fmt [-w WIDTH] [FILE...] |
| gunzip    | 解压文件。如果没有文件，则从标准输入设备解压到标准输出设备。成功后，输入文件将被删除并替换为新的没有.gz后缀的文件。<br />usage: gunzip [-cfk] [FILE...] |
| head      | 将文件中的第一行复制到标准输出设备中。如果未列出任何文件，从标准输入设备拷贝. “-”代表标准输入设备<br />usage: head [-n number] [file...] |
| hexedit   | 十六进制文件编辑器，所有修改立刻写入磁盘。<br />usage: hexedit FILENAME |
| iconv     | 转换文件编码。<br />usage: iconv [-f FROM] [-t TO] [FILE...] |
| inotifyd  | 在文件系统事件出现的时候，运行特定的程序。<br />usage: inotifyd PROG FILE[:MASK] ... |
| install   | 复制文件并设置文件属性。<br />usage: install [-dDpsv] [-o USER] [-g GROUP] [-m MODE] [SOURCE...] DEST |
| link      | 创建文件的硬链接。<br />usage: link FILE NEWLINK |
| ln        | 在 FROM 和 TO 之间创建软/硬链接。<br />usage: ln [-sfnv] [-t DIR] [FROM...] TO |
| ls        | 查看当前目录有哪些文件/文件夹。<br />usage: ls [-ACFHLRSZacdfhiklmnpqrstux1] [--color[=auto]] [directory...] |
| lsattr    | 列出Linux文件系统中的文件属性。标志字母在chattr帮助中定义。<br />usage: lsattr [-Radlv] [Files...] |
| lsof      | 列出属于所有活跃进程的所有打开的文件，或使用列出的FILE的进程。<br />usage: lsof [-lt] [-p PID1,PID2,...] [FILE...] |
| md5sum    | 计算每个输入文件的哈希，如果没有，则从标准输入设备读取。每个输入文件输出一行哈希后跟文件名。<br />usage: md5sum [-bcs] [FILE]... |
| mkdir     | 创建一个或多个目录。<br />usage: mkdir [-vp] [-m mode] [dirname...] |
| mkfifo    | 创建FIFO文件（命名管道）。<br />usage: mkfifo [NAME...] |
| mkswap    | 创建Linux的交换空间。<br />usage: mkswap [-L LABEL] DEVICE |
| mktemp    | 安全地创建一个新文件“DIR/TEMPLATE”并打印其名称。<br />usage: mktemp [-dqu] [-p DIR] [TEMPLATE] |
| mknod     | 创建一个特殊的文件(b为块设备，c或u为字符设备，p为命名管道)。<br />usage: mknod [-m MODE] NAME TYPE [MAJOR MINOR] |
| more      | 查看文件，一次一页。<br />usage: more [FILE...] |
| mv        | 移动或重命名文件。<br />usage: mv [-fivn] SOURCE... DEST |
| nl        | 给输入的文件添加行号。<br />usage: nl [-E] [-l #] [-b MODE] [-n STYLE] [-s SEPARATOR] [-v #] [-w WIDTH] [FILE...] |
| od        | 以八进制/十六进制格式转储数据。<br />usage: od [-bcdosxv] [-j #] [-N #] [-w #] [-A doxn] [-t acdfoux[#]] |
| paste     | 从每个输入文件中合并相应的行。<br />usage: paste [-s] [-d DELIMITERS] [FILE...] |
| patch     | 将统一的diff应用于一个或多个文件。<br />usage: patch [-d DIR] [-i file] [-p depth] [-Rlsu] [--dry-run] |
| pgrep     | 查找进程。PATTERN是扩展正则表达式，用于命令名称的检测。<br />usage: pgrep [-clfnovx] [-d DELIM] [-L SIGNAL] [PATTERN] [-G GID,] [-g PGRP,] [-P PPID,] [-s SID,] [-t TERM,] [-U UID,] [-u EUID,] |
| printf    | 使用C语言的printf语法，根据Format格式化并打印参数。<br />usage: printf FORMAT [ARGUMENT...] |
| pwd       | 打印工作（当前）目录。<br />usage: pwd [-L \| -P] |
| readahead | 将文件预加载到磁盘缓存中。<br />usage: readahead FILE... |
| readlink  | 如果没有选项，则显示symlink指向什么，如果不是symlink则返回错误。<br />usage: readlink FILE... |
| realpath  | 显示规范绝对路径名。<br />usage: realpath FILE... |
| rev       | 逆向输出每一行。<br />usage: rev [FILE...] |
| rm        | 删除文件。<br />usage: rm [-fiRrv] FILE... |
| rmdir     | 删除一个或多个目录。<br />usage: rmdir [-p] [dirname...] |
| sed       | 流编辑器。将编辑脚本应用于输入行。<br />usage: sed [-inrzE] [-e SCRIPT]... \| SCRIPT [-f SCRIPT\_FILE]... [FILE...] |
| seq       | 从头到尾按递增计数。省略参数默认值为1。使用两个参数作为第一个和最后一个。参数可以是负数或浮点数。<br />usage: seq [-w \| -f fmt\_str] [-s sep\_str] [first] [increment] last |
| setfattr  | 写入 POSIX 扩展属性。<br />usage: setfattr [-h] [-x \| -n NAME] [-v VALUE] FILE... |
| sha1sum/sha256sum | 计算sha系列哈希值。<br />usage: sha?sum [-bcs] [FILE]... |
| shred     | 安全的删除文件（用随机数据覆盖文件内容）。<br />usage: shred [-fuz] [-n COUNT] [-s SIZE] FILE... |
| sort      | 对从输入文件（或标准输入设备）到标准输出设备的所有文本行进行排序。<br />usage: sort [-Mbcdfginrsuz] [FILE...] [-k#[,#[x]] [-t X]] [-o FILE] |
| split     | 将输入（或标准输入设备）数据复制到一系列输出（或“x”）文件，使用按字母顺序递增的后缀（aa,ab,ac...az,ba,bb...）。<br />usage: split [-a SUFFIX\_LEN] [-b BYTES] [-l LINES] [INPUT [OUTPUT]] |
| stat      | 显示文件或文件系统的状态。<br />usage: stat [-tfL] [-c FORMAT] FILE... |
| strings   | 在二进制文件中显示可打印字符串。<br />usage: strings [-fo] [-t oxd] [-n LEN] [FILE...] |
| tac       | 以相反的顺序输出行。<br />usage: tac [FILE...] |
| tail      | 将文件中的最后几行复制到标准输出设备中。“-”代表标准输入设备。<br />usage: tail [-n\|c NUMBER] [-f] [FILE...] |
| tar       | 在.tar文件中创建、解压缩或列出文件。<br />usage: tar [-cxt] [-fvohmjkOS] [-XTCf NAME] [FILES] |
| tee       | 将标准输入设备复制到每个列出的文件，也复制到标准输出设备。“-”代表标准输出设备。<br />usage: tee [-ai] [file...] |
| touch     | 更新每个FILE的访问和修改时间为当前时间。<br />usage: touch [-amch] [-d DATE] [-t TIME] [-r FILE] FILE... |
| truncate  | 设置文件的长度，必要时稀疏扩展。<br />usage: truncate [-c] -s SIZE file... |
| uniq      | 报告或过滤文件中的重复行。<br />usage: uniq [-cduiz] [-w maxchars] [-f fields] [-s char] [input\_file [output\_file]] |
| unix2dos  | 将换行符格式从unix“\\n”转换为dos“\\r\\n”。如果没有列出文件，从标准输入设备获取输入。“-”代表标准输入设备。<br />usage: unix2dos [FILE...] |
| unlink    | 删除文件。<br />usage: unlink FILE |
| uudecode  | 从标准输入设备（或INFILE）解码文件。<br />usage: uudecode [-o OUTFILE] [INFILE] |
| uuencode  | 标准输入设备（或文件）进行编码，输出到标准输出设备，在输出中包含encode-filename。<br />usage: uuencode [-m] [file] encode-filename |
| wc        | 统计输入中的行数、单词和字符。<br />usage: wc -lwcm [FILE...] |
| which     | 在\$PATH中搜索与文件名匹配的可执行文件。<br />usage: which [-a] filename ... |
| xxd       | 以16进制的形式显示文件内容。若没有列出任何文件，从标准输入设备复制。<br />usage: xxd [-c n] [-g n] [-i] [-l n] [-o n] [-p] [-r] [-s n] [file] |
| zcat      | 将文件解压缩到标准输出设备。比如“gzip -dc”。<br /> usage: zcat [FILE...] |

## 常见问题

### 报错："Unknown command xxx"
在命令行中输入"xxx" 或 "toybox xxx" 或 "help xxx"时，如果遇到报错 "Unknown command xxx"，表示toybox不支持xxx命令。
<!--RP2-->
如果该命令在本文的描述中，则证明产品未编译该命令，建议前往OpenHarmony官方论坛提问反馈。
<!--RP2End-->

### 报错："Operation not permitted"/"Permission denied"
toybox存在大量操作文件和进程的命令，如果调用者缺少对被操作对象的权限，就会报错。
1. 权限缺失。请检查被操作的文件，以及所属文件夹的读、写、执行权限，确认自己是否有权限执行。
2. SELinux拦截。可以在内核日志中搜索"avc: denied"关键字。
例子：
如果出现类似 avc: denied { xxx } for comm="ls" xxxxxx 的日志，表示命令ls触发了SELinux拦截。

<!--RP3-->
如遇权限缺失问题，又需要执行该命令，建议前往OpenHarmony官方论坛提问反馈。
<!--RP3End-->

### 其他Linux标准报错
toybox大部分命令为对内核的调用，出错时会通过perror打印Linux内核错误码对应的文本。
常见的错误有："File exists"/"Not a directory"/"Read-only file system"等。
这些为Linux标准错误，可以参考Linux相关资料查询报错原因。请根据具体报错，检查命令的参数或者命令的格式是否出现错误。

例子：
试图在只读文件系统中进行创建文件的操作，会有报错 "Read-only file system"。
cat可以打印文件内容，如果试图cat一个目录，会有报错 "Is a directory"。
试图用ls命令查看一个不存在的文件或目录，会有报错 "No such file or directory"。

### 命令与toybox描述不符合
如果发现在shell下输入"命令 参数"的表现与"toybox 命令 参数"不一致，可能有两种原因导致。

1. 实际调用的是shell的实现而非toybox。

对于time/test/pwd/realpath/ulimit/kill等命令，shell会直接使用自己的实现。
此时如果想要调用toybox命令，请使用"toybox [command] [arguments...]"的格式。

2. 设备未将该命令配置给toybox，而是有另外的实现。

此时如果想要调用toybox命令，请使用"toybox [command] [arguments...]"的格式。
