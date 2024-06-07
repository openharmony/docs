# NDK涉及的musl libc接口使用限制的说明

## 概述

开发者使用NDK进行应用开发时，可能涉及到使用musl libc的接口能力，而musl libc的个别接口可能受多种系统和环境的限制而无法使用。在使用DevEco Studio进行应用开发时，使用这些接口也会发生错误，此时也可以使用本文档进行问题排查。

## musl libc接口使用限制的场景

musl libc接口使用的限制包含如下类型：

1. 受Seccomp机制影响。<!--Del-->
   Seccomp机制可参考[Seccomp策略与开发指导](../../../device-dev/subsystems/subsys-boot-init-seccomp.md)。<!--DelEnd-->

    因Seccomp机制导致的常见报错有
    - 报错堆栈栈顶在musl的函数中。
    - 报错原因为`signal:SIGSYS`，例如：
        ```
        Process name:com.example.myapplication
        Reason:Signal:SIGSYS(UNKNOWN)
        Fault thread Info:
        Tid:13893, Name:e.myapplication
        #00 pc 000a5d30 /system/lib/ld-musl-arm.so.1(sethostname+16)(584c9d0a0e9000497bb0d66799a9526a)
        #01 pc 00002f68 /data/storage/el1/bundle/libs/arm/libentry.so(test()+64)
        ```

2. 内核相关接口未对外开放能力导致接口不可用。

3. 受SELinux限制影响。<!--Del-->
   SELinux的说明可参考[SELinux概述](../../../device-dev/subsystems/subsys-security-selinux-overview.md)。<!--DelEnd-->

4. 受沙箱机制影响，访问路径受到限制。沙箱机制可参考[应用沙箱目录](../../file-management/app-sandbox-directory.md)。

5. 空实现或默认失败。

6. 需要特殊权限才能执行的接口

## musl libc受限接口列表

受上述限制约束的影响，musl libc不可用的接口如下：

| 权限限制原因          | 头文件        | 符号名称         |
| -------------------- | ------------ | ---------------- |
| 受Seccomp机制影响     | sys/fsuid.h  | setfsgid |
| 受Seccomp机制影响     | sys/fsuid.h  | setfsuid |
| 受Seccomp机制影响     | unistd.h     | setgid |
| 受Seccomp机制影响     | unistd.h     | setegid |
| 受Seccomp机制影响     | unistd.h     | setreuid |
| 受Seccomp机制影响     | unistd.h     | setregid |
| 受Seccomp机制影响     | unistd.h     | setresgid |
| 受Seccomp机制影响     | unistd.h     | setgroups |
| 受Seccomp机制影响     | unistd.h     | chroot |
| 受Seccomp机制影响     | unistd.h     | sethostname |
| 受Seccomp机制影响     | unistd.h     | setdomainname |
| 受Seccomp机制影响     | unistd.h     | acct |
| 受Seccomp机制影响     | sys/xattr.h  | setxattr |
| 受Seccomp机制影响     | time.h       | clock_settime |
| 受Seccomp机制影响     | time.h       | settimeofday |
| 受Seccomp机制影响     | sys/stat.h   | mknod |
| 受Seccomp机制影响     | sys/stat.h   | mknodat |
| 受Seccomp机制影响     | sys/stat.h   | mkfifo |
| 受Seccomp机制影响     | fcntl.h      | name_to_handle_at |
| 受Seccomp机制影响     | fcntl.h      | open_by_handle_at |
| 受Seccomp机制影响     | sys/klog.h   | klogctl |
| 受Seccomp机制影响     | sys/swap.h   | swapon |
| 受Seccomp机制影响     | sys/swap.h   | swapoff |
| 受Seccomp机制影响     | sys/sem.h    | semctl |
| 受Seccomp机制影响     | sys/sem.h    | semop |
| 受Seccomp机制影响     | sys/sem.h    | semtimedop |
| 受Seccomp机制影响     | sys/mount.h  | mount |
| 受Seccomp机制影响     | sys/mount.h  | umount2 |
| 受Seccomp机制影响     | sys/mount.h  | umount |
| 受Seccomp机制影响     | sys/msg.h    | msgctl |
| 受Seccomp机制影响     | sys/msg.h    | msgget |
| 受Seccomp机制影响     | sys/msg.h    | msgrcv |
| 受Seccomp机制影响     | sys/msg.h    | msgsnd |
| 受Seccomp机制影响     | grp.h        | initgroups |
| 受Seccomp机制影响     | grp.h        | init_module |
| 受Seccomp机制影响     | sched.h      | unshare |
| 受Seccomp机制影响     | sched.h      | setns |
| 受Seccomp机制影响     | None         | pivot_root |
| 内核相关接口未对外开放 | sys/fanotify.h | fanotify_init |
| 内核相关接口未对外开放 | sys/fanotify.h | fanotify_mark |
| 内核相关接口未对外开放 | syslog.h       | syslog |
| 内核相关接口未对外开放 | syslog.h       | vsyslog |
| 受SELinux限制影响     | pty.h          | forkpty |
| 受SELinux限制影响     | pty.h          | openpty |
| 受SELinux限制影响     | stdlib.h       | ptsname |
| 受SELinux限制影响     | stdlib.h       | ptsname_r |
| 受SELinux限制影响     | stdlib.h       | posix_openpt |
| 受SELinux限制影响     | stdlib.h       | unlockpt |
| 受SELinux限制影响     | sys/shm.h      | shmget |
| 受SELinux限制影响     | sys/shm.h      | shmat |
| 受SELinux限制影响     | sys/shm.h      | shmdt |
| 受SELinux限制影响     | sys/shm.h      | shmctl |
| 受SELinux限制影响     | sys/sem.h      | semget |
| 受SELinux限制影响     | stdio.h        | popen |
| 受SELinux限制影响     | stdio.h        | pclose |
| 受SELinux限制影响     | unistd.h       | tcgetpgrp |
| 受SELinux限制影响     | unistd.h       | tcsetpgrp |
| 受SELinux限制影响     | unistd.h       | link |
| 受SELinux限制影响     | unistd.h       | linkat |
| 受SELinux限制影响     | unistd.h       | readlink |
| 受SELinux限制影响     | unistd.h       | readlinkat |
| 受SELinux限制影响     | unistd.h       | symlink |
| 受SELinux限制影响     | unistd.h       | symlinkat |
| 受SELinux限制影响     | sys/stat.h     | mkfifoat |
| 受SELinux限制影响     | termios        | tcgetattr |
| 受SELinux限制影响     | termios        | tcsetattr |
| 受SELinux限制影响     | termios        | tcsendbreak |
| 受SELinux限制影响     | termios        | tcdrain |
| 受SELinux限制影响     | termios        | tcflush |
| 受SELinux限制影响     | termios        | tcflow |
| 受SELinux限制影响     | termios        | tcgetsid |
| 受SELinux限制影响     | net/if.h       | if_indextoname |
| 受SELinux限制影响     | net/if.h       | if_nametoindex |
| 受沙箱机制影响        | stdio.h        | tmpfile |
| 受沙箱机制影响        | stdio.h        | tmpfile64 |
| 受沙箱机制影响        | nl_type.h      | catgets |
| 受沙箱机制影响        | nl_type.h      | catclose |
| 空实现或默认失败      | utmp.h         | setutent |
| 空实现或默认失败      | utmp.h         | pututline |
| 空实现或默认失败      | utmp.h         | getutent |
| 空实现或默认失败      | utmp.h         | utmpname |
| 空实现或默认失败      | unistd.h       | brk |
| 空实现或默认失败      | stdio_ext.h    | __fsetlocking |
| 空实现或默认失败      | netdb.h        | getnetbyaddr |
| 空实现或默认失败      | netdb.h        | getnetbyname |
| 需要CAP_SYS_ADMIN权限 | None          | pivot_root |