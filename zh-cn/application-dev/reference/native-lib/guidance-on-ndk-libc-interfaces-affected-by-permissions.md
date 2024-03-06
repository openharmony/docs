# NDK musl-libc接口受权限影响的说明

## 适用场景
开发者在通过DevEco Studio进行应用开发，使用到了musl libc的能力并调用相关接口发生错误时，可以参考此文档进行问题排查

## musl-libc部分接口可能由于以下5种原因，导致无法使用
### 1. Seccomp机制
> Seccomp机制可参考 <a href="../../../device-dev/subsystems/subsys-boot-init-seccomp.md">Seccomp策略与开发指导</a>

Seccomp常见报错
1. 报错堆栈栈顶在musl的函数中
2. 报错原因是signal:SIGSYS

> Process name:com.example.myapplication<br /> 
> <font color="#dd0000">**Reason:Signal:SIGSYS(UNKNOWN)**</font><br /> 
> Fault thread Info:<br /> 
> Tid:13893, Name:e.myapplication<br /> 
> #00 pc 000a5d30 /system/lib/ld-musl-arm.so.1(sethostname+16)(584c9d0a0e9000497bb0d66799a9526a)<br /> 
> #01 pc 00002f68 /data/storage/el1/bundle/libs/arm/libentry.so(test()+64)<br /> > (d7066771a87465422c6f22b93a382cd70f574098)<br /> 

### 2. 内核相关接口未对外开放能力导致接口不可用
### 3. SELinux 限制
> SELinux可参考<a href="../../../device-dev/subsystems/subsys-security-selinux-overview.md">SELinux概述</a>

### 4. 沙箱机制限制应用访问路径
> 基于沙箱机制，应用仅可访问应用沙箱内的路径。沙箱机制可参考<a href="../../file-management/app-sandbox-directory.md">应用沙箱目录</a>

### 5. 空实现或默认失败

## 当前不可用接口列表

<table>
    <tr>
        <td>权限限制原因</td>
        <td>头文件</td>
        <td>符号名称</td>
    </tr>
    <tr>
        <td rowspan="39">Seccomp机制</td>
        <td rowspan="2">sys/fsuid.h</td>
        <td>setfsgid</td>
    </tr>
    <tr>
        <td>setfsuid</td>
    </tr>
    <tr>
        <td rowspan="10">unistd.h</td>
        <td>setgid</td>
    </tr>
    <tr>
        <td>setegid</td>
    </tr>
    <tr>
        <td>setreuid</td>
    </tr>
    <tr>
        <td>setregid</td>
    </tr>
    <tr>
        <td>setresgid</td>
    </tr>
    <tr>
        <td>setgroups</td>
    </tr>
    <tr>
        <td>chroot</td>
    </tr>
    <tr>
        <td>sethostname</td>
    </tr>
    <tr>
        <td>setdomainname</td>
    </tr>
    <tr>
        <td>acct</td>
    </tr>
    <tr>
        <td>sys/xattr.h</td>
        <td>setxattr</td>
    </tr>
    <tr>
        <td rowspan="2">time.h</td>
        <td>clock_settime</td>
    </tr>
    <tr>
        <td>settimeofday</td>
    </tr>
    <tr>
        <td rowspan="2"> </td>
        <td>adjtime</td>
    </tr>
    <tr>
        <td>stime</td>
    </tr>
    <tr>
        <td rowspan="3">sys/stat.h</td>
        <td>mknod</td>
    </tr>
    <tr>
        <td>mknodat</td>
    </tr>
    <tr>
        <td>mkfifo</td>
    </tr>
    <tr>
        <td rowspan="2">fcntl.h</td>
        <td>name_to_handle_at</td>
    </tr>
    <tr>
        <td>open_by_handle_at</td>
    </tr>
    <tr>
        <td>sys/klog.h</td>
        <td>klogctl</td>
    </tr>
    <tr>
        <td rowspan="2">sys/swap.h</td>
        <td>swapon</td>
    </tr>
    <tr>
        <td>swapoff</td>
    </tr>
    <tr>
        <td rowspan="3">sys/sem.h</td>
        <td>semctl</td>
    </tr>
    <tr>
        <td>semop</td>
    </tr>
    <tr>
        <td>semtimedop</td>
    </tr>
    <tr>
        <td rowspan="3">sys/mount.h</td>
        <td>mount</td>
    </tr>
    <tr>
        <td>umount2</td>
    </tr>
    <tr>
        <td>umount</td>
    </tr>
    <tr>
        <td rowspan="4">sys/msg.h</td>
        <td>msgctl</td>
    </tr>
    <tr>
        <td>msgget</td>
    </tr>
    <tr>
        <td>msgrcv</td>
    </tr>
    <tr>
        <td>msgsnd</td>
    </tr>
    <tr>
        <td>grp.h</td>
        <td>initgroups</td>
    </tr>
    <tr>
        <td> </td>
        <td>init_module</td>
    </tr>
    <tr>
        <td rowspan="2">sched.h</td>
        <td>unshare</td>
    </tr>
    <tr>
        <td>setns</td>
    </tr>
    <tr>
        <td rowspan="4">内核相关接口未对外开放能力导致接口不可用</td>
        <td rowspan="2">sys/fanotify.h</td>
        <td>fanotify_init</td>
    </tr>
    <tr>
        <td>fanotify_mark</td>
    </tr>
    <tr>
        <td rowspan="2">syslog.h</td>
        <td>syslog</td>
    </tr>
    <tr>
        <td>vsyslog</td>
    </tr>
    <tr>
        <td rowspan="31">SELinux的限制</td>
        <td rowspan="2">pty.h</td>
        <td>forkpty</td>
    </tr>
    <tr>
        <td>openpty</td>
    </tr>
    <tr>
        <td rowspan="4">stdlib.h</td>
        <td>ptsname</td>
    </tr>
    <tr>
        <td>ptsname_r</td>
    </tr>
    <tr>
        <td>posix_openpt</td>
    </tr>
    <tr>
        <td>unlockpt</td>
    </tr>
    <tr>
        <td rowspan="4">sys/shm.h</td>
        <td>shmget</td>
    </tr>
    <tr>
        <td>shmat</td>
    </tr>
    <tr>
        <td>shmdt</td>
    </tr>
    <tr>
        <td>shmctl</td>
    </tr>
    <tr>
        <td>sys/sem.h</td>
        <td>semget</td>
    </tr>
    <tr>
        <td rowspan="2">stdio.h</td>
        <td>popen</td>
    </tr>
    <tr>
        <td>pclose</td>
    </tr>
    <tr>
        <td rowspan="8">unistd.h</td>
        <td>tcgetpgrp</td>
    </tr>
    <tr>
        <td>tcsetpgrp</td>
    </tr>
    <tr>
        <td>link</td>
    </tr>
    <tr>
        <td>linkat</td>
    </tr>
    <tr>
        <td>readlinkat</td>
    </tr>
    <tr>
        <td>readlink</td>
    </tr>
    <tr>
        <td>symlink</td>
    </tr>
    <tr>
        <td>symlinkat</td>
    </tr>
    <tr>
        <td>sys/stat.h</td>
        <td>mkfifoat</td>
    </tr>
    <tr>
        <td rowspan="7">termios.h</td>
        <td>tcgetattr</td>
    </tr>
    <tr>
        <td>tcsetattr</td>
    </tr>
    <tr>
        <td>tcsendbreak</td>
    </tr>
    <tr>
        <td>tcdrain</td>
    </tr>
    <tr>
        <td>tcflush</td>
    </tr>
    <tr>
        <td>tcflow</td>
    </tr>
    <tr>
        <td>tcgetsid</td>
    </tr>
    <tr>
        <td rowspan="2">net/if.h</td>
        <td>if_indextoname</td>
    </tr>
    <tr>
        <td>if_nametoindex</td>
    </tr>
    <tr>
        <td rowspan="4">沙箱机制</td>
        <td rowspan="2">stdio.h</td>
        <td>tmpfile</td>
    </tr>
    <tr>
        <td>tmpfile64</td>
    </tr>
    <tr>
        <td rowspan="2">nl_type.h</td>
        <td>catgets</td>
    </tr>
    <tr>
        <td>catclose</td>
    </tr>
    <tr>
        <td rowspan="8">空实现或默认失败</td>
        <td rowspan="4">utmp.h</td>
        <td>setutent</td>
    </tr>
    <tr>
        <td>pututline</td>
    </tr>
    <tr>
        <td>getutent</td>
    </tr>
    <tr>
        <td>utmpname</td>
    </tr>
    <tr>
        <td>unistd.h</td>
        <td>brk</td>
    </tr>
    <tr>
        <td>stdio_ext.h</td>
        <td>__fsetlocking</td>
    </tr>
    <tr>
        <td rowspan="2">netdb.h</td>
        <td>getnetbyaddr</td>
    </tr>
    <tr>
        <td>getnetbyname</td>
    </tr>

</table>