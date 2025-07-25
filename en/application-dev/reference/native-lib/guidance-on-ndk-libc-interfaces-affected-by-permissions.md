# NDK-Related musl libc Interface Usage Restrictions

## Overview

When developing an application using DevEco Studio or NDK, you may need to use the interface capabilities of musl libc. However, some interfaces of musl libc may be unavailable due to restrictions of multiple systems and environments. In this case, you can refer to this document to troubleshoot interface issues.

<!--RP1--><!--RP1End-->

## Seccomp-Affected musl Interfaces<!--Del-->
   For details about the secure computing mode (Seccomp) mechanism, see [Seccomp Policy Development](../../../device-dev/subsystems/subsys-boot-init-seccomp.md).<!--DelEnd-->

### Determining Process Termination Due to Seccomp

- Check the process fault logs. If the error cause is **signal:SIGSYS** and the stack top is in the ld-musl-{architecture}.so.1 library, the process termination may be caused by the Seccomp mechanism.
    ```
    cat /data/log/faultlog/faultlogger/cppcrash-xxxx
    ```
    Incorrect example:
    ```
    Process name:com.example.myapplication
    Reason:Signal:SIGSYS(UNKNOWN)
    Fault thread Info:
    Tid:13893, Name:e.myapplication
    #00 pc 000a5d30 /system/lib/ld-musl-arm.so.1(sethostname+16)(584c9d0a0e9000497bb0d66799a9526a)
    #01 pc 00002f68 /data/storage/el1/bundle/libs/arm/libentry.so(test()+64)
    ```
<!--Del-->
- Disable the Seccomp mechanism. If the process runs properly, the termination is caused by the Seccomp mechanism.
    
    When the device system version is an ENG version and the system is in root mode, execute the shell command to set the system parameter to disable the Seccomp mechanism.
    ```shell
    # Set the system parameter to disable Seccomp and restart the process.
    param set persist.init.debug.seccomp.enable 0
    reboot
    # Set the system parameter to enable Seccomp and restart the process.
    param set persist.init.debug.seccomp.enable 1
    reboot
    ```
<!--DelEnd-->

### Common Seccomp-Affected Interfaces

| Header File       | musl Interface     |
| ------------ | ----------------- |
| fcntl.h      | name_to_handle_at |
| fcntl.h      | open_by_handle_at |
| grp.h        | initgroups        |
| grp.h        | setgroups         |
| sched.h      | setns             |
| sched.h      | unshare           |
| sys/fanotify.h | fanotify_init   |
| sys/fanotify.h | fanotify_mark   |
| sys/fsuid.h  | setfsgid          |
| sys/fsuid.h  | setfsuid          |
| sys/klog.h   | klogctl           |
| sys/mount.h  | mount             |
| sys/mount.h  | umount2           |
| sys/mount.h  | umount            |
| sys/msg.h    | msgctl            |
| sys/msg.h    | msgget            |
| sys/msg.h    | msgrcv            |
| sys/msg.h    | msgsnd            |
| sys/reboot.h | reboot            |
| sys/sem.h    | semctl            |
| sys/sem.h    | semget            |
| sys/sem.h    | semop             |
| sys/sem.h    | semtimedop        |
| sys/shm.h    | shmat             |
| sys/shm.h    | shmctl            |
| sys/shm.h    | shmdt             |
| sys/shm.h    | shmget            |
| sys/stat.h   | mkfifo            |
| sys/stat.h   | mkfifoat          |
| sys/stat.h   | mknod             |
| sys/stat.h   | mknodat           |
| sys/swap.h   | swapoff           |
| sys/swap.h   | swapon            |
| time.h       | clock_settime     |
| sys/time.h   | settimeofday      |
| sys/timex.h  | adjtimex          |
| sys/timex.h  | clock_adjtime     |
| unistd.h     | acct              |
| unistd.h     | chroot            |
| unistd.h     | pause             |
| unistd.h     | setdomainname     |
| unistd.h     | setegid           |
| unistd.h     | setgid            |
| unistd.h     | sethostname       |
| unistd.h     | setregid          |
| unistd.h     | setresgid         |
| unistd.h     | setreuid          |
| unistd.h     | setuid            |
| None         | pivot_root        |
| None         | init_module       |
| None         | delete_module     |


## Kernel-Related musl Interfaces Not Opened to the Public

| Header File         | musl Interface  |
| -------------- | -------------- |
| sys/fanotify.h | fanotify_init  |
| sys/fanotify.h | fanotify_mark  |
| unistd.h       | acct           |

## SELinux-Affected musl Interfaces<!--Del-->
   For details about SELinux, see [OpenHarmony SELinux Overview](../../../device-dev/subsystems/subsys-security-selinux-overview.md).<!--DelEnd-->

### Determining Interface Errors Caused by SELinux
- Include the **errno.h** header file and check the errno error status code. If the error status code is EACCES, the interface error may be caused by the SELinux mechanism.
<!--Del-->
- Check the kernel AVC logs for SELinux interception logs with type=1400 to determine whether the interface error is caused by the SELinux mechanism.
    
    ```shell
    # Search for type=1400 kernel Selinux logs (Note: Due to execution efficiency, the kernel may discard some logs.)
    dmesg -w | grep "pid=2854" | grep "type=1400"
    # Example of a log affected by the SELinux mechanism
    audit: type=1400 audit(1502785908.269:47562): avc:  denied  { ioctl } for  pid=2854 comm="sh" path="/dev/tty" dev="tmpfs" ino=40 ioctlcmd=0x5403 scontext=u:r:su:s0 tcontext=u:object_r:tty_device:s0 tclass=chr_file permissive=0
    # Log interpretation
    ioctl                               # Operation performed on the object
    pid=2854                            # Process ID of the subject
    comm="sh"                           # Process name of the subject
    path="/dev/tty"                     # Object being accessed
    dev="tmpfs"                         # File system of the object
    ino=40                              # Inode number of the object
    ioctlcmd=0x5403                     # ioctl command
    scontext=u:r:su:s0                  # SELinux context of the subject
    tcontext=u:object_r:tty_device:s0   # SELinux context of the object
    tclass=chr_file                     # Permission category (character device file)
    permissive=0                        # 0: enforcing mode; 1: permissive mode
    # Log conclusion
    The process (2854) attempted to perform an ioctl operation on /dev/tty. Due to a lack of permission for the ioctlcmd=0x5403 command and SELinux being in enforcing mode, the kernel blocked the process operation and set errno to EACCES.
    ```
        
- Disable the SELinux mechanism. If the interface call succeeds, the error is caused by the SELinux mechanism.
        
    When the device is in root mode, execute the shell command to set the system parameter to temporarily disable the SELinux mechanism.
    ```shell
    # Set the system parameter to disable the SELinux mechanism.
    setenforce 0
    # Set the system parameter to enable the SELinux mechanism.
    setenforce 1
    ```
<!--DelEnd-->

### Common SELinux-Affected Interfaces
    
| Header File        |  musl Interface  |
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


## Sandbox-Affected musl Interfaces

For details about the sandbox mechanism, see [Application Sandbox](../../file-management/app-sandbox-directory.md).

Include the **errno.h** header file and check the errno error status code. If the error status code is ENOENT, the interface error may be caused by the sandbox mechanism.

### Common Sandbox-Affected Interfaces

|  Header File       | musl Interface|
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


## No-Op or Default-Failure musl Interfaces
    
| Header File        |  musl Interface |
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


## musl Interfaces Requiring Special Permissions

Include the **errno.h** header file and check the errno error status code. If the error status code is EPERM, the interface error may be caused by the system capabilities security mechanism or other kernel security controls.

### Common Capabilities-Affected Interfaces
    
| Header File        |  musl Interface     | Capabilities Permission    |
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
