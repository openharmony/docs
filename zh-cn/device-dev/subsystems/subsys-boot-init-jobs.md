# jobs管理
## 概述
### 功能简介
jobs是init组件下cfg文件中的一组命令构成的集合, 最多添加4096个job。 jobs可以在 **[cfg](subsys-boot-init-cfg.md)** 文件中配置，通常在init启动过程中执行，服务于service的正常启动或特定基础功能的初始化。

### 基本概念
job可以在init.cfg中配置，也可以在模块的自定义cfg中配置。init解析程序会把相同名字job的命令合并到一个job中。同一名字的job只能保证init.cfg中的命令优先执行，其他cfg间的命令执行顺序不保证。
- 基本jobs

  init启动的固定阶段，如“pre-init“，“init”，“post-init”，这类job在init启动的固定阶段执行。
  - pre-init：init前置阶段，其他服务所依赖的，类似于ueventd、watchdog、hilogd等的关键服务会在这一阶段启动，data分区的挂载也在这一阶段进行。
  - init：init进程的主要阶段，这一阶段除了大量命令的执行，同时也是init分组并行启动boot组（第一组）服务的启动阶段，一些关乎系统功能的重要服务会在这一阶段被拉起。
  - post-init：这一阶段主要是通过trigger命令触发其他阶段执行，可以把所有被触发的阶段看作一个个的小阶段，也可以把它们统一看作post-init阶段，这一阶段会执行大量命令，并且它还是init分组并行启动normal组（第二组）服务的启动阶段，cfg中配置的大部分服务都是在这一阶段被拉起的。

- 自定义jobs(仅标准系统以上提供)

  这类job按照一定的规则进行触发，用户根据需要定义的命令集合，通过trigger命令触发执行。

- 条件jobs(仅标准系统以上提供)

  用户通过在jobs中添加condition条件，在条件触发时执行。

  条件一般是某些系统参数值的组合，支持&& 、||等操作，例如"condition"："sys.usb.config = none && sys.usb.configfs = 0"。并且jobs在定义命令时，一般按照下面的规则"param:xxx", 可以根据不同的属性自行组合。

### 约束与限制
在标准系统下有系统参数模块的支持，支持基本jobs、条件jobs、自定义jobs。在小型系统中只支持基本jobs。

## 开发指导
### 场景介绍
job就是命令集合，jobs管理就是对要执行的一组命令集合进行管理， 一组命令集合最多添加4096个命令。在init启动过程中，jobs的执行为服务的正常运行提供支持。

### 参数说明

   **表1** 命令集说明
<table border="0" cellpadding="0" cellspacing="0" width="770" style="border-collapse: collapse;table-layout:fixed;width:578pt;border-spacing: 0px;font-variant-ligatures: normal; font-variant-caps: normal;orphans: 2;text-align:start;widows: 2;-webkit-text-stroke-width: 0px; text-decoration-thickness: initial;text-decoration-style: initial;text-decoration-color: initial">
            <tbody>
                <tr height="39" style="height:18.0pt">
                    <th height="24" class="xl6521952" width="140" style="height:18.0pt;width:105pt">
                        命令
                    </td>
                    <th class="xl6521952" width="215" style="border-left:none;width:161pt">
                        命令格式和示例
                    </td>
                    <th class="xl6521952" width="225" style="border-left:none;width:169pt">
                        说明
                    </td>
                    <th class="xl6521952" width="190" style="border-left:none;width:143pt">
                        支持系统类型
                    </td>
                </tr>
                <tr height="231" style="height:173.25pt">
                    <td height="231" class="xl6621952" width="140" style="height:173.25pt;border-top: none;width:105pt">
                        mkdir
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        mkdir&nbsp;目标文件夹<br>如：mkdir&nbsp;/storage/myDirectory
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        创建文件夹命令，mkdir和目标文件夹之间有且只能有一个空格。
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        小型系统和标准系统
                    </td>
                </tr>
                <tr height="277" style="mso-height-source:userset;height:207.75pt">
                    <td height="277" class="xl6621952" width="140" style="height:207.75pt;border-top: none;width:105pt">
                        chmod
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        chmod&nbsp;权限&nbsp;目标<br>如：chmod&nbsp;0600&nbsp;/storage/myFile.txt<br>chmod&nbsp;0750&nbsp;/storage/myDir
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        修改权限命令，chmod权限目标之间间隔有且仅有一个空格，权限必须为0xxx格式。
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        小型系统和标准系统
                    </td>
                </tr>
                <tr height="295" style="mso-height-source:userset;height:221.25pt">
                    <td height="295" class="xl6621952" width="140" style="height:221.25pt;border-top: none;width:105pt">
                        chown
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        chown&nbsp;uid&nbsp;gid&nbsp;目标<br>如：chown&nbsp;900&nbsp;800&nbsp;/storage/myDir<br>chown&nbsp;100&nbsp;100&nbsp;/storage/myFile.txt
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        修改属组命令，chown&nbsp;uid&nbsp;gid目标之间间隔有且仅有一个空格。
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        小型系统和标准系统
                    </td>
                </tr>
                <tr height="355" style="mso-height-source:userset;height:266.25pt">
                    <td height="355" class="xl6621952" width="140" style="height:266.25pt;border-top: none;width:105pt">
                        mount
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        mount&nbsp;fileSystemType&nbsp;src&nbsp;dst&nbsp;flags&nbsp;data<br>如：mount&nbsp;vfat&nbsp;/dev/mmcblk0&nbsp;/sdc&nbsp;rw,umask=000<br>mount&nbsp;jffs2&nbsp;/dev/mtdblock3&nbsp;/storage&nbsp;nosuid
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        挂载命令，各参数之间有且仅有一个空格。flags当前仅支持nodev、noexec、nosuid、rdonly，data为可选字段。
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        小型系统和标准系统
                    </td>
                </tr>
                <tr height="238" style="mso-height-source:userset;height:178.5pt">
                    <td height="238" class="xl6621952" width="140" style="height:178.5pt;border-top: none;width:105pt">
                        start
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        start&nbsp;serviceName<br>如：start&nbsp;foundationstart&nbsp;shell
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        启动服务命令，start后面跟着service名称，该service名称必须能够在services数组中找到。
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        小型系统和标准系统
                    </td>
                </tr>
                <tr height="264" style="mso-height-source:userset;height:198.0pt">
                    <td height="264" class="xl6621952" width="140" style="height:198.0pt;border-top: none;width:105pt">
                        export
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        export key value<br>如：export TEST /data/test
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        设置环境变量命令。后面跟两个参数，第一个参数是环境变量名，第二个参数是环境变量值。
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        小型系统和标准系统
                    </td>
                </tr>
                <tr height="185" style="height:138.75pt">
                    <td height="185" class="xl6621952" width="140" style="height:138.75pt;border-top: none;width:105pt">
                        rm
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        rm filename<br>如：rm /data/testfile
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        删除文件命令。后面跟一个参数，即文件的绝对路径。
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        小型系统和标准系统
                    </td>
                </tr>
                <tr height="185" style="height:138.75pt">
                    <td height="185" class="xl6621952" width="140" style="height:138.75pt;border-top: none;width:105pt">
                        rmdir
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        rmdir dirname<br>如：rmdir /data/testdir
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        删除目录命令。后面跟一个参数，即目录的绝对路径。
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        小型系统和标准系统
                    </td>
                </tr>
                <tr height="266" style="mso-height-source:userset;height:199.5pt">
                    <td height="266" class="xl6621952" width="140" style="height:199.5pt;border-top: none;width:105pt">
                        write
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        write filename value<br>如：write /data/testfile 0
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        写文件命令。后面跟两个参数，第一个参数是文件的绝对路径，第二个参数是要写入文件的字符串。
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        小型系统和标准系统
                    </td>
                </tr>
                <tr height="185" style="height:138.75pt">
                    <td height="185" class="xl6621952" width="140" style="height:138.75pt;border-top: none;width:105pt">
                        stop
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        stop servicename<br>如：stop console
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        关闭服务命令。后面跟一个参数，即要关闭的服务名。
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        小型系统和标准系统
                    </td>
                </tr>
                <tr height="280" style="mso-height-source:userset;height:210.0pt">
                    <td height="280" class="xl6621952" width="140" style="height:210.0pt;border-top: none;width:105pt">
                        copy
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        copy oldfile newfile<br>如：copy /data/old /data/new
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        拷贝文件命令。后面跟两个参数，第一个参数是原文件绝对路径，第二个参数是新文件绝对路径。
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        小型系统和标准系统
                    </td>
                </tr>
                <tr height="382" style="mso-height-source:userset;height:286.5pt">
                    <td height="382" class="xl6621952" width="140" style="height:286.5pt;border-top: none;width:105pt">
                        reset
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        reset servicename<br>如：reset console
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        重启服务命令。后面跟一个参数，即要重启的服务名。目前reset命令的策略是，如果一个服务没有启动，则该命令会将其拉起，如果一个服务处于运行状态，则该命令会将其关闭后重启。
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        小型系统和标准系统
                    </td>
                </tr>
                <tr height="363" style="mso-height-source:userset;height:272.25pt">
                    <td height="363" class="xl6621952" width="140" style="height:272.25pt;border-top: none;width:105pt">
                        reboot
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        reboot (subsystem)<br>如：reboot updater
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        重启系统命令。后面可以跟一个参数，也可以没有参数，当没有参数时执行该命令，将会使设备重启到当前系统，当后面跟参数时，参数应当是子系统的名字，例如,reboot updater，将会重启进入updater子系统。
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        小型系统和标准系统
                    </td>
                </tr>
                <tr height="185" style="height:138.75pt">
                    <td height="185" class="xl6621952" width="140" style="height:138.75pt;border-top: none;width:105pt">
                        sleep
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        sleep time<br>如：sleep 5
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        睡眠命令。后面可以跟一个参数，该参数是睡眠时间。
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        小型系统和标准系统
                    </td>
                </tr>
                <tr height="185" style="height:138.75pt">
                    <td height="185" class="xl6621952" width="140" style="height:138.75pt;border-top: none;width:105pt">
                        domainname
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        domainname name<br>如：domainname localdomain
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        设置域名。
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        小型系统和标准系统
                    </td>
                </tr>
                <tr height="185" style="height:138.75pt">
                    <td height="185" class="xl6621952" width="140" style="height:138.75pt;border-top: none;width:105pt">
                        hostname
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        hostname name<br>如：hostname localhost
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        设置主机名命令。
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        小型系统和标准系统
                    </td>
                </tr>
                <tr height="116" style="height:87.0pt">
                    <td height="116" class="xl6621952" width="140" style="height:87.0pt;border-top: none;width:105pt">
                        wait
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        wait PID<br>如：wait pid
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        等待命令。
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        小型系统和标准系统
                    </td>
                </tr>
                <tr height="185" style="height:138.75pt">
                    <td height="185" class="xl6621952" width="140" style="height:138.75pt;border-top: none;width:105pt">
                        setrlimit
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        setrlimit resource curValue maxValue<br>如：setrlimit resource 10 100
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        设定资源使用限制命令。
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        小型系统和标准系统
                    </td>
                </tr>
                <tr height="208" style="height:156.0pt">
                    <td height="208" class="xl6621952" width="140" style="height:156.0pt;border-top: none;width:105pt">
                        write
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        write path content<br>如：write /proc/sys/kernel/sysrq 0
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        写文件命令。
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        小型系统和标准系统
                    </td>
                </tr>
                <tr height="228" style="mso-height-source:userset;height:171.0pt">
                    <td height="228" class="xl6621952" width="140" style="height:171.0pt;border-top: none;width:105pt">
                        exec
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        exec 可执行文件路径 可执行文件传的参数<br>如：exec /system/bin/udevadm trigger
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        系统调用命令。
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        小型系统和标准系统
                    </td>
                </tr>
                <tr height="231" style="height:173.25pt">
                    <td height="231" class="xl6621952" width="140" style="height:173.25pt;border-top: none;width:105pt">
                        mknode
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        mknod name { b | c } Major Minor<br>如：mknod path b 0644 1 9
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        建立一个目录项和一个特殊文件的对应索引节点。
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        标准系统
                    </td>
                </tr>
                <tr height="185" style="height:138.75pt">
                    <td height="185" class="xl6621952" width="140" style="height:138.75pt;border-top: none;width:105pt">
                        makedev
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        makedev major minor<br>如：makedev -v update
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        创建静态的设备节点命令，通常位于/dev目录下。
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        标准系统
                    </td>
                </tr>
                <tr height="231" style="height:173.25pt">
                    <td height="231" class="xl6621952" width="140" style="height:173.25pt;border-top: none;width:105pt">
                        symlink
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        symlink path1 path2<br>如：symlink /proc/self/fd/0 /dev/stdin
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        符号链接命令。
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        标准系统
                    </td>
                </tr>
                <tr height="139" style="height:104.25pt">
                    <td height="139" class="xl6621952" width="140" style="height:104.25pt;border-top: none;width:105pt">
                        trigger
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        trigger jobName<br>如：trigger early-fs
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        触发job执行的命令。
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        标准系统
                    </td>
                </tr>
                <tr height="116" style="height:87.0pt">
                    <td height="116" class="xl6621952" width="140" style="height:87.0pt;border-top: none;width:105pt">
                        insmod
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        insmod ko文件<br>如：insmod xxx.ko
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        内核模块文件载入命令。
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        标准系统
                    </td>
                </tr>
                <tr height="277" style="height:207.75pt">
                    <td height="277" class="xl6621952" width="140" style="height:207.75pt;border-top: none;width:105pt">
                        setparam
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        setparam paramname paramvalue<br>如：setparam sys.usb.config hdc
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        设置系统参数。
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        标准系统
                    </td>
                </tr>
                <tr height="231" style="height:173.25pt">
                    <td height="231" class="xl6621952" width="140" style="height:173.25pt;border-top: none;width:105pt">
                        load_persist_params
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        load persist params<br>如：load_persist_params&nbsp;
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        加载persist参数。load_persist_params命令后有且仅有一个空格。
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        标准系统
                    </td>
                </tr>
                <tr height="208" style="height:156.0pt">
                    <td height="208" class="xl6621952" width="140" style="height:156.0pt;border-top: none;width:105pt">
                        load_param
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        load params<br>如：load_param /data/test.normal.para
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        将文件里的param加载到内存。
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        标准系统
                    </td>
                </tr>
                <tr height="278" style="mso-height-source:userset;height:208.5pt">
                    <td height="278" class="xl6621952" width="140" style="height:208.5pt;border-top: none;width:105pt">
                        load_access_token_id
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        如：load_access_token_id&nbsp;
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        将access token信息写入data/service/el0/access_token/nativetoken.json文件，load_access_token_id后有且只有一个空格。
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        标准系统
                    </td>
                </tr>
                <tr height="139" style="height:104.25pt">
                    <td height="139" class="xl6621952" width="140" style="height:104.25pt;border-top: none;width:105pt">
                        ifup
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        ifup 激活网络接口<br>如：ifup eth0
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        激活指定的网络接口。
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        标准系统
                    </td>
                </tr>
                <tr height="208" style="height:156.0pt">
                    <td height="208" class="xl6621952" width="140" style="height:156.0pt;border-top: none;width:105pt">
                        mount_fstab
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        mount_fstab fstab.test<br>如：mount_fstab /vendor/etc/fstab.test
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        按照fstab挂载分区的命令。
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        标准系统
                    </td>
                </tr>
                <tr height="208" style="height:156.0pt">
                    <td height="208" class="xl6621952" width="140" style="height:156.0pt;border-top: none;width:105pt">
                        umount_fstab
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        umount_fstab fstab.test<br>如：umount_fstab /vendor/etc/fstab.test
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        按照fstab卸载分区的命令。
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        标准系统
                    </td>
                </tr>
                <tr height="162" style="height:121.5pt">
                    <td height="162" class="xl6621952" width="140" style="height:121.5pt;border-top: none;width:105pt">
                        restorecon
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        restorecon file or dir<br>如：restorecon /file
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        重新加载selinux 的context。
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        标准系统
                    </td>
                </tr>
                <tr height="254" style="height:190.5pt">
                    <td height="254" class="xl6621952" width="140" style="height:190.5pt;border-top: none;width:105pt">
                        stopAllServices
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        stopAllServices [bool]<br>如：stopAllServices false 或 stopAllServices
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        停止所有服务。
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        标准系统
                    </td>
                </tr>
                <tr height="162" style="height:121.5pt">
                    <td height="162" class="xl6621952" width="140" style="height:121.5pt;border-top: none;width:105pt">
                        umount
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        umount path<br>如：umount /vendor
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        卸载已经挂载的硬件设备 。
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        标准系统
                    </td>
                </tr>
                <tr height="185" style="height:138.75pt">
                    <td height="185" class="xl6621952" width="140" style="height:138.75pt;border-top: none;width:105pt">
                        sync
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        如：sync&nbsp;
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        同步写入数据到磁盘。sync后有且仅有一个空格。
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        标准系统
                    </td>
                </tr>
                <tr height="185" style="height:138.75pt">
                    <td height="185" class="xl6621952" width="140" style="height:138.75pt;border-top: none;width:105pt">
                        timer_start
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        timer_start serviceName<br>如：timer_start console
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        启动服务计时器。
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        标准系统
                    </td>
                </tr>
                <tr height="185" style="height:138.75pt">
                    <td height="185" class="xl6621952" width="140" style="height:138.75pt;border-top: none;width:105pt">
                        timer_stop
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        timer_stop serviceName<br>如：timer_stop console
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        停止服务计时器。
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        标准系统
                    </td>
                </tr>
                <tr height="162" style="height:121.5pt">
                    <td height="162" class="xl6621952" width="140" style="height:121.5pt;border-top: none;width:105pt">
                        init_global_key
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        init_global_key path <br>如：init_global_key /data
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        data分区文件加密key初始化。
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        标准系统
                    </td>
                </tr>
                <tr height="70" style="height:52.5pt">
                    <td height="70" class="xl6621952" width="140" style="height:52.5pt;border-top:none; width:105pt">
                        init_main_user
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        如：init_main_user
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        主用户目录加密。
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        标准系统
                    </td>
                </tr>
                <tr height="162" style="height:121.5pt">
                    <td height="162" class="xl6621952" width="140" style="height:121.5pt;border-top: none;width:105pt">
                        mkswap
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        mkswap file<br>如：mkswap /swapfile1
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        在一个文件或者设备上建立交换分区。
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        标准系统
                    </td>
                </tr>
                <tr height="162" style="height:121.5pt">
                    <td height="162" class="xl6621952" width="140" style="height:121.5pt;border-top: none;width:105pt">
                        swapon
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        swapon file <br>如：swapon /swapfile1
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        激活交换空间。
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        标准系统
                    </td>
                </tr>
                <tr height="384" style="mso-height-source:userset;height:288.0pt">
                    <td height="384" class="xl6621952" width="140" style="height:288.0pt;border-top: none;width:105pt">
                        loadcfg
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        loadcfg&nbsp;filePath<br>如：loadcfg&nbsp;/patch/fstab.cfg
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        加载其他cfg文件命令。后面跟着的目标文件大小不得超过50KB，且目前仅支持加载/patch/fstab.cfg，其他文件路径和文件名均不支持。/patch/fstab.cfg文件的每一行都是一条命令，命令类型和格式必须符合本表格描述，命令条数不得超过20条。
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        小型系统
                    </td>
                </tr><!--[endif]-->
            </tbody>
    </table>

### 接口说明
jobs管理属于init启动过程中的一环，是一个流程化的功能，是完全服务于init启动过程的，并不对其他组件提供任何功能接口，其运行逻辑契合cfg中命令组的管理，无法对其他类型管理提供帮助。下述主要介绍其在init当中的调用逻辑。

**表2 job解析接口说明**
<table border="0" cellpadding="0" cellspacing="0" width="968" style="border-collapse: collapse;table-layout:fixed;width:727pt;orphans: 2;widows: 2;-webkit-text-stroke-width: 0px; text-decoration-thickness: initial;text-decoration-style: initial;text-decoration-color: initial; box-sizing: border-box;border-spacing: 0px;word-break:initial;font-variant-ligatures: normal; font-variant-caps: normal">
            <tbody>
                <tr height="39" style="height:29.25pt;box-sizing: border-box">
                    <th height="39" class="xl6320252" width="249" style="height:29.25pt;width:187pt">
                        函数名
                    </th>
                    <th class="xl6420252" width="235" style="width:176pt;border-image: initial">
                        入参
                    </th>
                    <th class="xl6420252" width="106" style="width:80pt;border-image: initial">
                        返回值
                    </th>
                    <th class="xl6420252" width="200" style="width:150pt;border-image: initial">
                        功能
                    </th>
                    <th class="xl6520252" width="178" style="width:134pt;border-image: initial">
                        支持系统类型
                    </th>
                </tr>
                <tr height="99" style="mso-height-source:userset;height:74.25pt;box-sizing: border-box">
                    <td height="99" class="xl6620252" width="249" style="height:74.25pt;width:187pt; border-image: initial;box-sizing: border-box">
                        void ParseAllJobs(const cJSON *fileRoot)
                    </td>
                    <td class="xl6720252" width="235" style="width:176pt;border-image: initial; box-sizing: border-box">
                        const cJSON *fileRoot
                    </td>
                    <td class="xl6720252" width="106" style="width:80pt;border-image: initial; box-sizing: border-box">
                        void
                    </td>
                    <td class="xl6720252" width="200" style="width:150pt;border-image: initial; box-sizing: border-box">
                        jobs解析总入口。
                    </td>
                    <td class="xl6720252" width="178" style="width:134pt;border-image: initial; box-sizing: border-box">
                        小型系统和标准系统
                    </td>
                </tr>
                <tr height="147" style="mso-height-source:userset;height:110.25pt;box-sizing: border-box">
                    <td height="147" class="xl6820252" width="249" style="height:110.25pt;width:187pt; border-image: initial;box-sizing: border-box">
                        static void ParseJob(const cJSON <span style="mso-spacerun:yes">&nbsp;</span>*jobItem, Job *resJob)
                    </td>
                    <td class="xl6920252" width="235" style="width:176pt;border-image: initial; box-sizing: border-box">
                        const cJSON *jobItem, Job *resJob
                    </td>
                    <td class="xl6920252" width="106" style="width:80pt;border-image: initial; box-sizing: border-box">
                        void
                    </td>
                    <td class="xl7020252" width="200" style="width:150pt;border-image: initial; box-sizing: border-box">
                        校验job是否已存在，解析cmds下命令的功能。
                    </td>
                    <td class="xl6920252" width="178" style="width:134pt;border-image: initial; box-sizing: border-box">
                        小型系统
                    </td>
                </tr>
                <tr height="177" style="mso-height-source:userset;height:132.75pt;box-sizing: border-box">
                    <td height="177" class="xl6620252" width="249" style="height:132.75pt;width:187pt; border-image: initial;box-sizing: border-box">
                        int GetCmdLinesFromJson(const cJSON *root, CmdLines **cmdLines)
                    </td>
                    <td class="xl6720252" width="235" style="width:176pt;border-image: initial; box-sizing: border-box">
                        const cJSON *root, CmdLines **cmdLines
                    </td>
                    <td class="xl6720252" width="106" style="width:80pt;border-image: initial; box-sizing: border-box">
                        int
                    </td>
                    <td class="xl6720252" width="200" style="width:150pt">
                        解析job中cmds命令。当前小型系统使用，标准系统由于涉及trigger功能和condition条件启动功能，并未使用该接口进行命令解析。
                    </td>
                    <td class="xl6720252" width="178" style="width:134pt;border-image: initial; box-sizing: border-box">
                        小型系统和标准系统
                    </td>
                </tr>
                <tr height="171" style="mso-height-source:userset;height:128.25pt;box-sizing: border-box">
                    <td height="171" class="xl6820252" width="249" style="height:128.25pt;width:187pt; border-image: initial;box-sizing: border-box">
                        int ParseTriggerConfig(const cJSON *fileRoot, int (*checkJobValid)(const char *jobName))
                    </td>
                    <td class="xl6920252" width="235" style="width:176pt;border-image: initial; box-sizing: border-box">
                        const cJSON *fileRoot, int (*checkJobValid)(const char *jobName)
                    </td>
                    <td class="xl6920252" width="106" style="width:80pt;border-image: initial; box-sizing: border-box">
                        int
                    </td>
                    <td class="xl6920252" width="200" style="width:150pt;border-image: initial; box-sizing: border-box">
                        解析job中Trigger命令。
                    </td>
                    <td class="xl6920252" width="178" style="width:134pt;border-image: initial; box-sizing: border-box">
                        标准系统
                    </td>
                </tr>
                <tr height="210" style="mso-height-source:userset;height:157.5pt;box-sizing: border-box">
                    <td height="210" class="xl6620252" width="249" style="height:157.5pt;width:187pt; border-image: initial;box-sizing: border-box">
                        static int ParseTrigger_(const TriggerWorkSpace *workSpace, const cJSON *triggerItem, int (*checkJobValid)(const char *jobName))
                    </td>
                    <td class="xl6720252" width="235" style="width:176pt;border-image: initial; box-sizing: border-box">
                        const TriggerWorkSpace *workSpace, const cJSON *triggerItem, int (*checkJobValid)(const char *jobName)
                    </td>
                    <td class="xl6720252" width="106" style="width:80pt;border-image: initial; box-sizing: border-box">
                        int
                    </td>
                    <td class="xl6720252" width="200" style="width:150pt">
                        获取job名称，condition属性以及cmds命令组的功能，解析到的job以hash表的形式存储，而命令的保存则使用了队列结构。
                    </td>
                    <td class="xl6720252" width="178" style="width:134pt;border-image: initial; box-sizing: border-box">
                        标准系统
                    </td>
                </tr><!--[endif]-->
            </tbody>
    </table>

**表3 job触发接口说明**
<table border="0" cellpadding="0" cellspacing="0" width="906" style="border-collapse: collapse;table-layout:fixed;width:681pt;box-sizing: border-box;border-spacing: 0px; word-break:initial;font-variant-ligatures: normal;font-variant-caps: normal; orphans: 2;widows: 2;-webkit-text-stroke-width: 0px;text-decoration-thickness: initial; text-decoration-style: initial;text-decoration-color: initial">
            <tbody>
                <tr height="39" style="height:35.25pt;box-sizing: border-box">
                    <th height="47" class="xl6322245" width="239" style="height:35.25pt;width:153pt">
                        函数名
                    </th>
                    <th class="xl6322245" width="235" style="border-left:none;width:178pt">
                        入参
                    </th>
                    <th class="xl6322245" width="106" style="border-left:none;width:80pt">
                        返回值
                    </th>
                    <th class="xl6322245" width="200" style="border-left:none;width:128pt">
                        功能
                    </th>
                    <th class="xl6322245" width="178" style="border-left:none;width:133pt">
                        支持系统类型
                    </th>
                </tr>
                <tr height="257" style="mso-height-source:userset;height:192.75pt;box-sizing: border-box">
                    <td height="257" class="xl6422245" width="204" style="height:192.75pt;border-top: none;width:153pt;box-sizing: border-box">
                        void PostTrigger(EventType type, const char *content, uint32_t contentLen)
                    </td>
                    <td class="xl6422245" width="235" style="border-top:none;border-left:none; width:178pt;box-sizing: border-box">
                        EventType type, const char *content, uint32_t contentLen
                    </td>
                    <td class="xl6422245" width="106" style="border-top:none;border-left:none; width:80pt;box-sizing: border-box">
                        void
                    </td>
                    <td class="xl6422245" width="170" style="border-top:none;border-left:none; width:128pt;box-sizing: border-box">
                        校验名称的有效性并发送触发job事件的功能。
                    </td>
                    <td class="xl6422245" width="177" style="border-top:none;border-left:none; width:133pt;box-sizing: border-box">
                        标准系统
                    </td>
                </tr>
                <tr height="323" style="height:242.25pt;box-sizing: border-box">
                    <td height="323" class="xl6522245" width="204" style="height:242.25pt;border-top: none;width:153pt;box-sizing: border-box">
                        static void SendTriggerEvent(int type, const char *content, uint32_t contentLen)
                    </td>
                    <td class="xl6522245" width="235" style="border-top:none;border-left:none; width:178pt;box-sizing: border-box">
                        int type, const char *content, uint32_t contentLen
                    </td>
                    <td class="xl6522245" width="106" style="border-top:none;border-left:none; width:80pt;box-sizing: border-box">
                        void
                    </td>
                    <td class="xl6522245" width="170" style="border-top:none;border-left:none; width:128pt;box-sizing: border-box">
                        通过系统参数进行整机控制以及服务的启动与停止等。
                    </td>
                    <td class="xl6522245" width="177" style="border-top:none;border-left:none; width:133pt;box-sizing: border-box">
                        标准系统
                    </td>
                </tr>
                <tr height="188" style="mso-height-source:userset;height:141.0pt;box-sizing: border-box">
                    <td height="188" class="xl6422245" width="204" style="height:141.0pt;border-top: none;width:153pt;box-sizing: border-box">
                        static void DoTriggerCmd(const struct CmdArgs *ctx)
                    </td>
                    <td class="xl6422245" width="235" style="border-top:none;border-left:none; width:178pt;box-sizing: border-box">
                        const struct CmdArgs *ctx
                    </td>
                    <td class="xl6422245" width="106" style="border-top:none;border-left:none; width:80pt;box-sizing: border-box">
                        void
                    </td>
                    <td class="xl6422245" width="170" style="border-top:none;border-left:none; width:128pt;box-sizing: border-box">
                        trigger命令执行接口
                    </td>
                    <td class="xl6422245" width="177" style="border-top:none;border-left:none; width:133pt;box-sizing: border-box">
                        标准系统
                    </td>
                </tr>
                <tr height="258" style="mso-height-source:userset;height:193.5pt;box-sizing: border-box">
                    <td height="258" class="xl6522245" width="204" style="height:193.5pt;border-top: none;width:153pt;box-sizing: border-box">
                        void DoTriggerExec(const char *triggerName)
                    </td>
                    <td class="xl6522245" width="235" style="border-top:none;border-left:none; width:178pt;box-sizing: border-box">
                        const char *triggerName
                    </td>
                    <td class="xl6522245" width="106" style="border-top:none;border-left:none; width:80pt;box-sizing: border-box">
                        void
                    </td>
                    <td class="xl6522245" width="170" style="border-top:none;border-left:none; width:128pt;box-sizing: border-box">
                        仅标准系统可用。通过参数中的job名称找到对应命令组，并将命令推入执行队列依次执行。
                    </td>
                    <td class="xl6522245" width="177" style="border-top:none;border-left:none; width:133pt;box-sizing: border-box">
                        标准系统
                    </td>
                </tr>
                <tr height="254" style="height:190.5pt;box-sizing: border-box">
                    <td height="254" class="xl6422245" width="204" style="height:190.5pt;border-top: none;width:153pt;box-sizing: border-box">
                        void DoJob(const char *jobName)
                    </td>
                    <td class="xl6422245" width="235" style="border-top:none;border-left:none; width:178pt;box-sizing: border-box">
                        const char *jobName
                    </td>
                    <td class="xl6422245" width="118" style="border-top:none;border-left:none; width:80pt;box-sizing: border-box">
                        void
                    </td>
                    <td class="xl6422245" width="170" style="border-top:none;border-left:none; width:128pt;box-sizing: border-box">
                        通过jobName匹配对应job，调用DoCmdByIndex执行其中的命令。
                    </td>
                    <td class="xl6422245" width="177" style="border-top:none;border-left:none; width:133pt;box-sizing: border-box">
                        小型系统
                    </td>
                </tr>
                <tr height="208" style="height:156.0pt;box-sizing: border-box">
                    <td height="208" class="xl6522245" width="204" style="height:156.0pt;border-top: none;width:153pt;box-sizing: border-box">
                        void DoCmdByIndex(int index, const char *cmdContent)
                    </td>
                    <td class="xl6522245" width="235" style="border-top:none;border-left:none; width:178pt;box-sizing: border-box">
                        int index, const char *cmdContent
                    </td>
                    <td class="xl6522245" width="118" style="border-top:none;border-left:none; width:80pt;box-sizing: border-box">
                        void
                    </td>
                    <td class="xl6522245" width="170" style="border-top:none;border-left:none; width:128pt;box-sizing: border-box">
                        拼接参数与命令。
                    </td>
                    <td class="xl6522245" width="177" style="border-top:none;border-left:none; width:133pt;box-sizing: border-box">
                        小型系统和标准系统
                    </td>
                </tr><!--[endif]-->
            </tbody>
    </table>

### 开发实例
下述为cfg文件中jobs配置模板，可验证jobs管理的功能。
```
{
    "jobs" : [{     // 基本job
            "name" : "stage1",
            "cmds" : [
                "start service1",
                "mkdir dir1"
            ]
        }, {        // 条件job
            "name" : "param:test.name1=0",
            "condition" : "test.name1=0",
            "cmds" : [
                "chmod 0755 dir1",
                "chown root root dir1"
            ]
        }, {        // 自定义job
            "name" : "param:test.name2=*",
            "condition" : "test.name2=*",
            "cmds" : [
                "chmod 0644 dir1",
                "chown system system dir1"
            ]
        }
    ]
}
```
以上展示了三种job配置的方式，下面对其中的配置差别分别进行介绍：

1. "name"和"cmds"是一个job中的必选项，并且"cmds"中应当包含系统支持的命令，否则就是浪费资源的无意义配置。

2. "condition"是一个job中的可选属性，这一属性的配置代表着该job是一个条件触发的job，不通过代码或trigger命令在固定阶段触发执行，而是在condition中的条件满足后才被触发执行。

3. job的命名需满足一定的规则，对于条件是系统参数的job，以"param:"为前缀。

4. 一个新的job命名需要在其他可执行的job命令组中通过trigger命令触发才可执行，提供的默认trigger命令执行阶段是post-init阶段。

5. 一个已经存在的job名称仍可以在不同文件中继续使用，相同名称的job将会被视为同一job，通过trigger触发时其中的命令合并执行。

6. 条件执行job的condition配置通常是系统参数，可以指定某个系统参数被设定为某个值时该job触发执行，也可以使用"*"符号，代表只要该系统参数被设置，不论为何值，条件都满足，该job可以被触发执行。

7. 在小型系统中，jobs中的post-init 部分不支持trigger命令。