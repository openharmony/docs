# Restricted musl libc APIs

## Overview

You may need to use musl libc APIs when developing your app with the NDK. However, some musl libc APIs cannot be used due to system or environment restrictions. Errors may occur when some musl libc APIs are used with DevEco Studio. This topic helps you learn about the musl libc APIs that cannot be used with the NDK.

## Scenarios

The use of musl libc APIs may be restricted by the following factors:

1. The use of the musl libc API is restricted by the secure computing (seccomp) mechanism.<!--Del-->
   For details about the seccomp mechanism, see [Seccomp Policy Development](../../../device-dev/subsystems/subsys-boot-init-seccomp.md).<!--DelEnd-->

    A common error caused by seccomp is as follows:
    - Top function is the musl function in stacktrace.
    - The reason is "signal:SIGSYS", as shown in the following example:
        ```
        Process name:com.example.myapplication
        Reason:Signal:SIGSYS(UNKNOWN)
        Fault thread Info:
        Tid:13893, Name:e.myapplication
        #00 pc 000a5d30 /system/lib/ld-musl-arm.so.1(sethostname+16)(584c9d0a0e9000497bb0d66799a9526a)
        #01 pc 00002f68 /data/storage/el1/bundle/libs/arm/libentry.so(test()+64)
        ```

2. The API cannot be used because it is a kernel API that is not exposed.

3. The use of the musl libc API is restricted by SELinux.<!--Del-->
   For details about SELinux, see [OpenHarmony SELinux Overview](../../../device-dev/subsystems/subsys-security-selinux-overview.md).<!--DelEnd-->

4. The use of the musl libc API is restricted by the sandbox mechanism. For details about the sandbox mechanism, see [Application Sandbox](../../file-management/app-sandbox-directory.md).

5. The musl libc API is a null implementation or failed by default.

6. The API can be executed after special permissions are granted.

## Restricted musl libc APIs

The following table lists the musl libc APIs that cannot be used.

| Restricted By         | Header File       | Symbol        |
| -------------------- | ------------ | ---------------- |
| seccomp    | sys/fsuid.h  | setfsgid |
| seccomp    | sys/fsuid.h  | setfsuid |
| seccomp    | unistd.h     | setgid |
| seccomp    | unistd.h     | setegid |
| seccomp    | unistd.h     | setreuid |
| seccomp    | unistd.h     | setregid |
| seccomp    | unistd.h     | setresgid |
| seccomp    | unistd.h     | setgroups |
| seccomp    | unistd.h     | chroot |
| seccomp    | unistd.h     | sethostname |
| seccomp    | unistd.h     | setdomainname |
| seccomp    | unistd.h     | acct |
| seccomp    | sys/xattr.h  | setxattr |
| seccomp    | time.h       | clock_settime |
| seccomp    | time.h       | settimeofday |
| seccomp    | sys/stat.h   | mknod |
| seccomp    | sys/stat.h   | mknodat |
| seccomp    | sys/stat.h   | mkfifo |
| seccomp    | fcntl.h      | name_to_handle_at |
| seccomp    | fcntl.h      | open_by_handle_at |
| seccomp    | sys/klog.h   | klogctl |
| seccomp    | sys/swap.h   | swapon |
| seccomp    | sys/swap.h   | swapoff |
| seccomp    | sys/sem.h    | semctl |
| seccomp    | sys/sem.h    | semop |
| seccomp    | sys/sem.h    | semtimedop |
| seccomp    | sys/mount.h  | mount |
| seccomp    | sys/mount.h  | umount2 |
| seccomp    | sys/mount.h  | umount |
| seccomp    | sys/msg.h    | msgctl |
| seccomp    | sys/msg.h    | msgget |
| seccomp    | sys/msg.h    | msgrcv |
| seccomp    | sys/msg.h    | msgsnd |
| seccomp    | grp.h        | initgroups |
| seccomp    | grp.h        | init_module |
| seccomp    | sched.h      | unshare |
| seccomp    | sched.h      | setns |
| seccomp    | None         | pivot_root |
| Kernel API not exposed| sys/fanotify.h | fanotify_init |
| Kernel API not exposed| sys/fanotify.h | fanotify_mark |
| Kernel API not exposed| syslog.h       | syslog |
| Kernel API not exposed| syslog.h       | vsyslog |
| SELinux    | pty.h          | forkpty |
| SELinux    | pty.h          | openpty |
| SELinux    | stdlib.h       | ptsname |
| SELinux    | stdlib.h       | ptsname_r |
| SELinux    | stdlib.h       | posix_openpt |
| SELinux    | stdlib.h       | unlockpt |
| SELinux    | sys/shm.h      | shmget |
| SELinux    | sys/shm.h      | shmat |
| SELinux    | sys/shm.h      | shmdt |
| SELinux    | sys/shm.h      | shmctl |
| SELinux    | sys/sem.h      | semget |
| SELinux    | stdio.h        | popen |
| SELinux    | stdio.h        | pclose |
| SELinux    | unistd.h       | tcgetpgrp |
| SELinux    | unistd.h       | tcsetpgrp |
| SELinux    | unistd.h       | link |
| SELinux    | unistd.h       | linkat |
| SELinux    | unistd.h       | readlink |
| SELinux    | unistd.h       | readlinkat |
| SELinux    | unistd.h       | symlink |
| SELinux    | unistd.h       | symlinkat |
| SELinux    | sys/stat.h     | mkfifoat |
| SELinux    | termios        | tcgetattr |
| SELinux    | termios        | tcsetattr |
| SELinux    | termios        | tcsendbreak |
| SELinux    | termios        | tcdrain |
| SELinux    | termios        | tcflush |
| SELinux    | termios        | tcflow |
| SELinux    | termios        | tcgetsid |
| SELinux    | net/if.h       | if_indextoname |
| SELinux    | net/if.h       | if_nametoindex |
| Sandbox       | stdio.h        | tmpfile |
| Sandbox       | stdio.h        | tmpfile64 |
| Sandbox       | nl_type.h      | catgets |
| Sandbox       | nl_type.h      | catclose |
| Null implementation or failed by default     | utmp.h         | setutent |
| Null implementation or failed by default     | utmp.h         | pututline |
| Null implementation or failed by default     | utmp.h         | getutent |
| Null implementation or failed by default     | utmp.h         | utmpname |
| Null implementation or failed by default     | unistd.h       | brk |
| Null implementation or failed by default     | stdio_ext.h    | __fsetlocking |
| Null implementation or failed by default     | netdb.h        | getnetbyaddr |
| Null implementation or failed by default     | netdb.h        | getnetbyname |
| **CAP_SYS_ADMIN** permission required| None          | pivot_root |
