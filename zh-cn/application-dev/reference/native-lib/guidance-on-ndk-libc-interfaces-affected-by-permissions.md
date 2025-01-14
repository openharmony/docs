# NDK涉及的musl libc接口使用限制的说明

## 概述

开发者使用NDK进行应用开发时，可能涉及到使用musl libc的接口能力，而musl libc的个别接口可能受多种系统和环境的限制而无法使用。在使用DevEco Studio进行应用开发时，使用这些接口也会发生错误，此时也可以使用本文档进行问题排查。

## musl libc接口使用限制的场景

musl libc接口使用的限制包含如下类型：

1. 受Seccomp机制影响。<!--Del-->
   Seccomp机制可参考[Seccomp策略使能开发指导](../../../device-dev/subsystems/subsys-boot-init-seccomp.md)。<!--DelEnd-->

    1、如何确定进程终止的是seccomp机制引起的
    - 查看进程faultlog日志，如果报错原因是`signal:SIGSYS`，且栈顶在`ld-musl-{架构}.so.1`库里，则进程终止可能是由Seccomp机制引起的。
        ```
        cat /data/log/faultlog/faultlogger/cppcrash-xxxx
        ```
        错误示例：
        ```
        Process name:com.example.myapplication
        Reason:Signal:SIGSYS(UNKNOWN)
        Fault thread Info:
        Tid:13893, Name:e.myapplication
        #00 pc 000a5d30 /system/lib/ld-musl-arm.so.1(sethostname+16)(584c9d0a0e9000497bb0d66799a9526a)
        #01 pc 00002f68 /data/storage/el1/bundle/libs/arm/libentry.so(test()+64)
        ```
    - 关闭Seccomp机制，如果进程能正常运行，则进程终止是由Seccomp机制引起的。
        
        当设备系统版本是ENG版本，且处于root模式下，执行shell命令设置系统参数，关闭整个系统的Seccomp机制。
        ```shell
        # 设置相关系统参数关闭Seccomp机制后重启
        param set persist.init.debug.seccomp.enable 0
        reboot
        # 设置相关系统参数开启Seccomp机制后重启
        param set persist.init.debug.seccomp.enable 1
        reboot
        ```

    2、常见可能受Seccomp机制影响的接口列表如下：
        
    | 头文件        | musl接口名称      | arm系统调用            | aarch64系统调用        | x86系统调用           |
    | ------------ | ----------------- | --------------------- | --------------------- | --------------------- |
    | fcntl.h      | name_to_handle_at | SYS_name_to_handle_at | SYS_name_to_handle_at | SYS_name_to_handle_at |
    | fcntl.h      | open_by_handle_at | SYS_open_by_handle_at | SYS_open_by_handle_at | SYS_open_by_handle_at |
    | grp.h        | initgroups        | SYS_setgroups         | SYS_setgroups         | SYS_setgroups         |
    | grp.h        | setgroups         | SYS_setgroups         | SYS_setgroups         | SYS_setgroups         |
    | sched.h      | setns             | SYS_setns             | SYS_setns             | SYS_setns             |
    | sched.h      | unshare           | SYS_unshare           | SYS_unshare           | SYS_unshare           |
    | sys/fanotify.h | fanotify_init   | SYS_fanotify_init     | SYS_fanotify_init     | SYS_fanotify_init     |
    | sys/fanotify.h | fanotify_mark   | SYS_fanotify_mark     | SYS_fanotify_mark     | SYS_fanotify_mark     |
    | sys/fsuid.h  | setfsgid          | SYS_setfsgid          | SYS_setfsgid          | SYS_setfsgid          |
    | sys/fsuid.h  | setfsuid          | SYS_setfsuid          | SYS_setfsuid          | SYS_setfsuid          |
    | sys/klog.h   | klogctl           | SYS_syslog            | SYS_syslog            | SYS_syslog            |
    | sys/mount.h  | mount             | SYS_mount             | SYS_mount             | SYS_mount             |
    | sys/mount.h  | umount2           | SYS_umount2           | SYS_umount2           | SYS_umount2           |
    | sys/mount.h  | umount            | SYS_umount2           | SYS_umount2           | SYS_umount2           |
    | sys/msg.h    | msgctl            | SYS_msgctl            | SYS_msgctl            | SYS_msgctl            |
    | sys/msg.h    | msgget            | SYS_msgget            | SYS_msgget            | SYS_msgget            |
    | sys/msg.h    | msgrcv            | SYS_msgrcv            | SYS_msgrcv            | SYS_msgrcv            |
    | sys/msg.h    | msgsnd            | SYS_msgsnd            | SYS_msgsnd            | SYS_msgsnd            |
    | sys/reboot.h | reboot            | SYS_reboot            | SYS_reboot            | SYS_reboot            |
    | sys/sem.h    | semctl            | SYS_semctl            | SYS_semctl            | SYS_semctl            |
    | sys/sem.h    | semget            | SYS_semget            | SYS_semget            | SYS_semget            |
    | sys/sem.h    | semop             | SYS_semop             | SYS_semop             | SYS_semop             |
    | sys/sem.h    | semtimedop        | SYS_semtimedop        | SYS_semtimedop        | SYS_semtimedop        |
    | sys/shm.h    | shmat             | SYS_shmat             | SYS_shmat             | SYS_shmat             |
    | sys/shm.h    | shmctl            | SYS_shmctl            | SYS_shmctl            | SYS_shmctl            |
    | sys/shm.h    | shmdt             | SYS_shmdt             | SYS_shmdt             | SYS_shmdt             |
    | sys/shm.h    | shmget            | SYS_shmget            | SYS_shmget            | SYS_shmget            |
    | sys/stat.h   | mkfifo            | SYS_mknod             | SYS_mknodat           | SYS_mknod             |
    | sys/stat.h   | mkfifoat          | SYS_mknodat           | SYS_mknodat           | SYS_mknodat           |
    | sys/stat.h   | mknod             | SYS_mknod             | SYS_mknodat           | SYS_mknod             |
    | sys/stat.h   | mknodat           | SYS_mknodat           | SYS_mknodat           | SYS_mknodat           |
    | sys/swap.h   | swapoff           | SYS_swapoff           | SYS_swapoff           | SYS_swapoff           |
    | sys/swap.h   | swapon            | SYS_swapon            | SYS_swapon            | SYS_swapon            |
    | time.h       | clock_settime     | SYS_clock_settime     | SYS_clock_settime     | SYS_clock_settime     |
    | sys/time.h   | settimeofday      | SYS_settimeofday      | SYS_settimeofday      | SYS_settimeofday      |
    | sys/timex.h  | adjtimex          | SYS_clock_adjtime64   | SYS_adjtimex          | SYS_adjtimex          |
    | sys/timex.h  | clock_adjtime     | SYS_clock_adjtime64   | SYS_adjtimex          | SYS_adjtimex          | 
    | unistd.h     | acct              | SYS_acct              | SYS_acct              | SYS_acct              |
    | unistd.h     | chroot            | SYS_chroot            | SYS_chroot            | SYS_chroot            |
    | unistd.h     | pause             | SYS_pause             | SYS_ppoll             | SYS_pause             |
    | unistd.h     | setdomainname     | SYS_setdomainname     | SYS_setdomainname     | SYS_setdomainname     |
    | unistd.h     | setegid           | SYS_setresgid         | SYS_setresgid         | SYS_setresgid         |
    | unistd.h     | setgid            | SYS_setgid            | SYS_setgid            | SYS_setgid            |
    | unistd.h     | sethostname       | SYS_sethostname       | SYS_sethostname       | SYS_sethostname       |
    | unistd.h     | setregid          | SYS_setregid          | SYS_setregid          | SYS_setregid          |
    | unistd.h     | setresgid         | SYS_setresgid         | SYS_setresgid         | SYS_setresgid         |
    | unistd.h     | setreuid          | SYS_setreuid          | SYS_setreuid          | SYS_setreuid          |
    | unistd.h     | setuid            | SYS_setuid            | SYS_setuid            | SYS_setuid            |
    | None         | pivot_root        | SYS_pivot_root        | SYS_pivot_root        | SYS_pivot_root        |
    | None         | init_module       | SYS_init_module       | SYS_init_module       | SYS_init_module       |
    | None         | delete_module     | SYS_delete_module     | SYS_delete_module     | SYS_delete_module     |


2. 内核相关接口未对外开放能力导致接口不可用。

    未开放的接口列表如下：

    | 头文件          | musl接口名称   | arm系统调用            | aarch64系统调用        | x86系统调用           |
    | -------------- | -------------- | --------------------- | --------------------- | --------------------- |
    | sys/fanotify.h | fanotify_init  | SYS_fanotify_init     | SYS_fanotify_init     | SYS_fanotify_init     |
    | sys/fanotify.h | fanotify_mark  | SYS_fanotify_mark     | SYS_fanotify_mark     | SYS_fanotify_mark     |
    | unistd.h       | acct           | SYS_acct              | SYS_acct              | SYS_acct              |

3. 受SELinux限制影响。<!--Del-->
   SELinux的说明可参考[OpenHarmony SELinux概述](../../../device-dev/subsystems/subsys-security-selinux-overview.md)。<!--DelEnd-->

    1、如何确认接口报错是受SELinux机制引起的
    - 检查errno错误状态码，如果错误状态码是EACCES，则接口报错可能是由SELinux机制引起的。
    - 检查内核avc日志，排查type=1400的SELinux拦截日志，判断接口报错是否由SELinux机制引起的。

        ```shell
        # 搜索type=1400的内核Selinux日志（注意：因为执行效率的原因，内核会舍弃部分日志）
        dmesg -w | grep "pid=2854" | grep "type=1400"
        # 受SELinux机制影响的日志示例
        audit: type=1400 audit(1502785908.269:47562): avc:  denied  { ioctl } for  pid=2854 comm="sh" path="/dev/tty" dev="tmpfs" ino=40 ioctlcmd=0x5403 scontext=u:r:su:s0 tcontext=u:object_r:tty_device:s0 tclass=chr_file permissive=0
        # 日志解读
        ioctl                               # 访问客体的操作权限
        pid=2854                            # 主体进程号
        comm="sh"                           # 主体进程名
        path="/dev/tty"                     # 被访问的客体
        dev="tmpfs"                         # 被访问客体的文件系统
        ino=40                              # 文件节点编号
        ioctlcmd=0x5403                     # ioctl操作命令
        scontext=u:r:su:s0                  # 主体SELinux标签
        tcontext=u:object_r:tty_device:s0   # 客体SELinux标签
        tclass=chr_file                     # 权限类别，字符设备文件
        permissive=0                        # 0是严格模式，拦截访问；1是宽容模式，只记录日志
        # 日志结论
        主体进程（2854）访问客体（/dev/tty），调用客体的ioctl操作，因为进程缺少ioctlcmd=0x5403命令的执行权限，且由于当前SELinux机制处于严格模式下，所以内核拦截了进程操作，并且将errno设置成EACCES错误。
        ```
        
    - 关闭SELinux机制，如果接口调用成功，则接口报错是由SELinux机制引起的。
        
        当设备处于root模式下，执行shell命令设置系统参数，临时关闭整个系统的SELinux机制。
        ```shell
        # 设置相关系统参数关闭SELinux机制
        setenforce 0
        # 设置相关系统参数开启SELinux机制
        setenforce 1
        ```
    
    2、常见可能受SELinux机制影响的接口列表如下：

    | 头文件         |  musl接口名称   |
    | -------------- | -------------- |
    | net/if.h       | if_indextoname |
    | net/if.h       | if_nametoindex |
    | pty.h          | forkpty        |
    | pty.h          | openpty        |
    | semaphore.h    | sem_open       |
    | semaphore.h    | sem_unlink     |
    | stdlib.h       | ptsname        |
    | stdlib.h       | ptsname_r      |
    | stdlib.h       | posix_openpt   |
    | stdlib.h       | unlockpt       |
    | stdio.h        | popen          |
    | stdio.h        | pclose         |
    | sys/ioctl.h    | ioctl          |
    | sys/mman.h     | shm_open       |
    | sys/mman.h     | shm_unlink     |
    | sys/mount.h    | mount          |
    | sys/mount.h    | umount         |
    | sys/mount.h    | umount2        |
    | sys/msg.h      | msgctl         |
    | sys/msg.h      | msgget         |
    | sys/msg.h      | msgrcv         |
    | sys/msg.h      | msgsnd         |
    | sys/sem.h      | semget         |
    | sys/sem.h      | semctl         |
    | sys/sem.h      | semop          |
    | sys/sem.h      | semtimedop     |
    | sys/shm.h      | shmget         |
    | sys/shm.h      | shmat          |
    | sys/shm.h      | shmdt          |
    | sys/shm.h      | shmctl         |
    | sys/stat.h     | mkfifo         |
    | sys/stat.h     | mkfifoat       |
    | sys/stat.h     | mknod          |
    | sys/stat.h     | mknodat        |
    | termios.h      | tcgetattr      |
    | termios.h      | tcsetattr      |
    | termios.h      | tcsendbreak    |
    | termios.h      | tcdrain        |
    | termios.h      | tcflush        |
    | termios.h      | tcflow         |
    | termios.h      | tcgetsid       |
    | unistd.h       | link           |
    | unistd.h       | linkat         |
    | unistd.h       | readlink       |
    | unistd.h       | readlinkat     |
    | unistd.h       | symlink        |
    | unistd.h       | symlinkat      |
    | unistd.h       | tcgetpgrp      |
    | unistd.h       | tcsetpgrp      |
    | utmp.h         | login_tty      |


4. 受沙箱机制影响，访问路径受到限制。沙箱机制可参考[应用沙箱目录](../../file-management/app-sandbox-directory.md)。

    检查errno错误状态码，如果错误状态码是ENOENT，则接口报错可能是由沙箱机制引起的。

    常见可能受沙箱机制影响的接口列表如下：

    |  头文件        | musl接口名称 |
    | -------------- | ----------- |
    | fcntl.h        | open        |
    | fcntl.h        | openat      |
    | nl_types.h     | catopen     |
    | stdio.h        | fopen       |
    | stdio.h        | freopen     |
    | stdio.h        | rename      |
    | stdio.h        | renameat    |
    | stdio.h        | renameat2   |
    | stdio.h        | tmpfile     |
    | stdio.h        | tmpfile64   |
    

5. 空实现或默认失败。

    空实现或默认失败接口列表如下：

    | 头文件         |  musl接口名称  |
    | -------------- | ------------- |
    | netdb.h        | getnetbyaddr  |
    | netdb.h        | getnetbyname  |
    | stdio_ext.h    | __fsetlocking |
    | unistd.h       | brk           |
    | utmp.h         | getutent      |
    | utmp.h         | pututline     |
    | utmp.h         | setutent      |
    | utmp.h         | pututline     |
    | utmp.h         | utmpname      |


6. 需要特殊权限才能执行的接口

    检查errno错误状态码，如果错误状态码是EPERM，则接口报错可能是由系统Capabilities安全机制引起的，也有可能是其他内核安全管控引起的。

    常见可能受Capabilities机制影响的接口如下：

    | 头文件         |  musl接口名称      | Capabilities权限     |
    | -------------- | ----------------- | -------------------- |
    | None           | pivot_root        | CAP_SYS_ADMIN        |
    | None           | init_module       | CAP_SYS_MODULE       |
    | None           | delete_module     | CAP_SYS_MODULE       |
    | fcntl.h        | open_by_handle_at | CAP_DAC_READ_SEARCH  |
    | sys/klog.h     | klogctl           | CAP_SYS_ADMIN        |
    | sys/mount.h    | mount             | CAP_SYS_ADMIN        |
    | sys/mount.h    | umount            | CAP_SYS_ADMIN        |
    | sys/mount.h    | umount2           | CAP_SYS_ADMIN        |
    | sys/reboot.h   | reboot            | CAP_SYS_BOOT         |
    | sys/swap.h     | swapon            | CAP_SYS_ADMIN        |
    | sys/swap.h     | swapoff           | CAP_SYS_ADMIN        |
    | sys/time.h     | settimeofday      | CAP_SYS_TIME         |
    | unistd.h       | setdomainname     | CAP_SYS_ADMIN        |
    | unistd.h       | sethostname       | CAP_SYS_ADMIN        |
    | unistd.h       | chroot            | CAP_SYS_CHROOT       |
