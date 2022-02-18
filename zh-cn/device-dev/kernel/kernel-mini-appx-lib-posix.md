# POSIX支持

- [基本概念](#基本概念)
- [开发指导](#开发指导)
  - [接口说明](#接口说明)
  - [注意事项](#注意事项)
  - [编程实例](#编程实例)

## 基本概念

OpenHarmony内核使用**musl libc**库以及自研接口，支持部分标准POSIX接口，开发者可基于POSIX标准接口开发内核之上的组件及应用。


## 开发指导


### 接口说明

**表1** POSIX接口说明

| 类别 | 需要包含的头文件 | 接口名 | 描述 |
| -------- | -------- | -------- | -------- |
| process | #include <stdlib.h> | void abort(void); | 中止线程执行 |
|  | #include <assert.h> | void assert(scalar expression); | 断言为假终止线程 |
|  | #include <pthread.h> | int pthread_cond_destroy(pthread_cond_t *cond); | 销毁条件变量 |
|  | #include <pthread.h> | int pthread_cond_init(pthread_cond_t *restrict cond, const pthread_condattr_t *restrict attr); | 初始化条件变量 |
|  | #include <pthread.h> | int pthread_condattr_getpshared(const pthread_condattr_t *attr, int *shared); | 获取条件变量属性，目前只支持获取PTHREAD_PROCESS_PRIVATE条件变量属性 |
|  | #include <pthread.h> | int pthread_condattr_setpshared(pthread_condattr_t *attr, int shared); | 设置条件变量属性 |
|  | #include <pthread.h> | int pthread_condattr_getclock(const pthread_condattr_t *attr, clockid_t *clock); | 获取线程时钟 |
|  | #include <pthread.h> | int pthread_condattr_destroy(pthread_condattr_t *attr); | 删除存储并使属性对象无效 |
|  | #include <pthread.h> | int pthread_cond_timedwait(pthread_cond_t *restrict cond, pthread_mutex_t *restrict mutex, const struct timespec *restrict abstime); | 等待条件 |
|  | #include <pthread.h> | int pthread_condattr_init(pthread_condattr_t *attr); | 初始化条件变量属性对象 |
|  | #include <pthread.h> | int pthread_mutex_unlock(pthread_mutex_t *mutex); | 解锁互斥锁 |
|  | #include <pthread.h> | int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg); | 创建一个新的线程 |
|  | #include <pthread.h> | int pthread_join(pthread_t thread, void **retval); | 等待指定的线程结束 |
|  | #include <pthread.h> | pthread_t pthread_self(void); | 获取当前线程的ID |
|  | #include <pthread.h> | int pthread_getschedparam(pthread_t thread, int *policy, struct sched_param *param); | 获取线程的调度策略和参数 |
|  | #include <pthread.h> | int pthread_setschedparam(pthread_t thread, int policy, const struct sched_param *param); | 设置线程的调度策略和参数 |
|  | #include <pthread.h> | int pthread_setschedprio(pthread_t thread, int prio); | 设置线程优先级 |
|  | #include <pthread.h> | int pthread_once(pthread_once_t *onceControl, void (*initRoutine)(void)); | 一次性操作任务 |
|  | #include <pthread.h> | int pthread_setcancelstate(int state, int *oldState); | 线程cancel功能开关 |
|  | #include <pthread.h> | int pthread_setcanceltype(int type, int *oldType); | 设置线程cancel类型 |
|  | #include <pthread.h> | int pthread_cancel(pthread_t thread); | 取消线程，目前仅支持先设置PTHREAD_CANCEL_ASYNCHRONOUS状态，再调用pthread_cancel取消线程 |
|  | #include <pthread.h> | void pthread_testcancel(void); | cancel线程 |
|  | #include <pthread.h> | int pthread_equal(pthread_t thread1, pthread_t thread2); | 判断是否为同一线程 |
|  | #include <pthread.h> | int pthread_mutexattr_gettype(const pthread_mutexattr_t *attr, int *outType); | 获取互斥锁的类型属性 |
|  | #include <pthread.h> | int pthread_mutex_init(pthread_mutex_t *__restrict m, const pthread_mutexattr_t *__restrict a); | 初始化互斥锁 |
|  | #include <pthread.h> | int pthread_mutex_lock(pthread_mutex_t *m); | 互斥锁加锁操作 |
|  | #include <pthread.h> | int pthread_mutex_timedlock(pthread_mutex_t *mutex, const struct timespec *absTimeout); | 申请互斥锁（只在设定时间内阻塞） |
|  | #include <pthread.h> | int pthread_mutex_trylock(pthread_mutex_t *m); | 互斥锁尝试加锁操作 |
|  | #include <pthread.h> | int pthread_mutex_destroy(pthread_mutex_t *m); | 销毁互斥锁 |
|  | #include <pthread.h> | int pthread_attr_init(pthread_attr_t *attr); | 初始化线程属性对象 |
|  | #include <pthread.h> | int pthread_attr_destroy(pthread_attr_t *attr); | 销毁线程属性对象 |
|  | #include <pthread.h> | int pthread_attr_getstacksize(const pthread_attr_t *attr, size_t *stacksize); | 获取线程属性对象的堆栈大小 |
|  | #include <pthread.h> | int pthread_attr_setstacksize(pthread_attr_t *attr, size_t stacksize); | 设置线程属性对象的堆栈大小 |
|  | #include <pthread.h> | int pthread_attr_setstack(pthread_attr_t *attr, void *stackAddr, size_t stackSize); | 设置线程属性对象的堆栈属性（暂未实现） |
|  | #include <pthread.h> | int pthread_attr_getstack(const pthread_attr_t *attr, void **stackAddr, size_t *stackSize); | 获取线程属性对象的堆栈（暂未实现） |
|  | #include <pthread.h> | int pthread_attr_getschedparam(const pthread_attr_t *attr, struct sched_param *param); | 获取线程属性对象的调度参数属性 |
|  | #include <pthread.h> | int pthread_attr_setschedparam(pthread_attr_t *attr, const struct sched_param *param); | 设置线程属性对象的调度参数属性 |
|  | #include <pthread.h> | int pthread_getname_np(pthread_t pthread, char *name, size_t len); | 获取线程名称 |
|  | #include <pthread.h> | int pthread_setname_np(pthread_t pthread, const char *name); | 设置线程名称 |
|  | #include <pthread.h> | int pthread_cond_broadcast(pthread_cond_t *c); | 解除若干已被等待条件阻塞的线程 |
|  | #include <pthread.h> | int pthread_cond_signal(pthread_cond_t *c); | 解除被阻塞的线程 |
|  | #include <pthread.h> | int pthread_cond_wait(pthread_cond_t *__restrict c, pthread_mutex_t *__restrict m); | 等待条件 |
| fs | #include <libgen.h> | char *dirname(char *path); | 获取目录名 |
|  | #include <dirent.h> | struct dirent *readdir(DIR *dirp); | 读目录 |
|  | #include <sys/stat.h> | int stat(const char *restrict path, struct stat *restrict buf); | 获取文件信息 |
|  | #include <unistd.h> | int unlink(const char *pathname); | 删除文件 |
|  | #include <fcntl.h | int open(const char *path, int oflags, ...); | 用于打开文件，如文件不存在，创建文件并打开 |
|  | #include <nistd.h> | int close(int fd); | 关闭文件 |
|  | #include <stdio.h> | int rename(const char *oldpath, const char *newpath); | 重命名指定的文件 |
|  | #include <dirent.h> | DIR  *opendir(const char *dirname); | 打开指定目录 |
|  | #include <dirent.h> | int closedir(DIR *dir); | 关闭指定目录 |
|  | #include <sys/mount.h> | int mount(const char *source, const char *target, const char *filesystemtype, unsigned long mountflags, const void *data); | 挂载文件系统 |
|  | #include <sys/mount.h> | int umount(const char *target); | 卸载文件系统 |
|  | #include <sys/mount.h> | int umount2(const char *target, int flag); | 卸载文件系统 |
|  | #include <sys/stat.h> | int fsync(int fd); | 将与指定文件描述符关联的文件同步到存储设备 |
|  | #include <sys/stat.h> | int mkdir(const char *pathname, mode_t mode); | 创建目录 |
|  | #include <unistd.h> | int rmdir(const char *path); | 删除目录 |
|  | #include <sys/stat.h> | int fstat(int fd, struct stat *buf); | 获取文件状态信息 |
|  | #include <sys/statfs.h> | int statfs(const char *path, struct statfs *buf); | 获取指定路径下文件的文件系统信息 |
| time | #include <sys/time.h> | int gettimeofday(struct timeval *tv, struct timezone *tz); | 获取时间。当前暂无时区概念,tz返回为空 |
|  | #include <time.h> | struct tm *gmtime(const time_t *timep); | 将日期和时间转换为细分时间或ASCII |
|  | #include <time.h> | struct tm *localtime(const time_t *timep); | 获取时间 |
|  | #include <time.h> | struct tm *localtime_r(const time_t *timep, struct tm *result); | 获取时间 |
|  | #include <time.h> | time_t mktime(struct tm *tm); | 将日期和时间转换为细分时间或ASCII |
|  | #include <time.h> | size_t strftime(char *s, size_t max, const char *format,const struct tm *tm); | 格式化日期和时间字符串 |
|  | #include <time.h> | time_t time(time_t *tloc); | 获得日历时间 |
|  | #include <sys/times.h> | clock_t times(struct tms *buf); | 获取线程时间 |
|  | #include <sys/times.h> | int timer_getoverrun(timer_t timerID); | 获取定时器超时次数 |
|  | #include <unistd.h> | int usleep(useconds_t usec); | 休眠（微秒单位） |
|  | #include <time.h> | int nanosleep(const struct timespec *tspec1, struct timespec *tspec2); | 暂停当前线程直到指定的时间到达 |
|  | #include <time.h> | int clock_gettime(clockid_t id, struct timespec *tspec); | 获取时钟的时间 |
|  | #include <time.h> | int timer_create(clockid_t id, struct sigevent *__restrict evp, timer_t *__restrict t); | 为线程创建计时器 |
|  | #include <time.h> | int timer_delete(timer_t t); | 为线程删除计时器 |
|  | #include <time.h> | int timer_settime(timer_t t, int flags, const struct itimerspec *__restrict val, struct itimerspec *__restrict old); | 为线程设置计时器 |
|  | #include <time.h> | time_t time (time_t *t); | 获取时间 |
|  | #include <time.h> | char *strptime(const char *s, const char *format, struct tm *tm); | 将时间的字符串表示形式转换为时间tm结构 |
| util | #include <stdlib.h> | int atoi(const char *nptr); | 字符串转换整型（int） |
|  | #include <stdlib.h> | long atol(const char *nptr); | 字符串转换整型（long） |
|  | #include <stdlib.h> | long long atoll(const char *nptr); | 字符串转换整型（long long） |
|  | #include <ctype.h> | int isalnum(int c); | 检查字母数字字符 |
|  | #include <ctype.h> | int isascii(int c); | 检查ASCII |
|  | #include <ctype.h> | int isdigit(int c); | 检查数字字符 |
|  | #include <ctype.h> | int islower(int c); | 检查小写字符 |
|  | #include <ctype.h> | int isprint(int c); | 检查任何可打印字符，包括空格 |
|  | #include <ctype.h> | int isspace(int c); | 检查空格字符 |
|  | #include <ctype.h> | int isupper(int c); | 检查所传的字符是否是大写字母 |
|  | #include <ctype.h> | int isxdigit(int c); | 判断字符是否为十六进制数 |
|  | #include <stdlib.h> | long int random (void); | 生成伪随机数 |
|  | #include <stdlib.h> | void srandom(unsigned int seed); | 初始化随机数生成器 |
|  | #include <ctype.h> | int tolower(int c); | 字母转换成小写 |
|  | #include <ctype.h> | int toupper(int c); | 字母转换成大写 |
|  | #include <stdarg.h> | type va_arg(va_list ap, type); | 获取可变参数的当前参数，返回指定类型并将指针指向下一参数 |
|  | #include <stdarg.h> | void va_copy(va_list dest, va_list src); | 复制参数 |
|  | #include <stdarg.h> | void va_end(va_list ap); | 清空va_list可变参数列表 |
|  | #include <stdarg.h> | void va_start(va_list ap, last); | 定义变长参数列表的起始位置 |
|  | #include <string.h> | char *strchr(const char *s, int c); | 在字符串中定位字符 |
|  | #include <string.h> | int strcmp(const char *s1, const char *s2); | 比较字符串 |
|  | #include <string.h> | size_t strcspn(const char *s, const char *reject); | 获取前缀子串的长度 |
|  | #include <string.h> | char *strdup(const char *s); | 字符串拷贝到新建的位置处 |
|  | #include <string.h> | size_t strlen(const char *s); | 计算字符串长度 |
|  | #include <strings.h> | int strncasecmp(const char *s1, const char *s2, size_t n); | 比较固定长度字符串（忽略大小写） |
|  | #include <strings.h> | int strcasecmp(const char *s1, const char *s2); | 比较字符串（忽略大小写） |
|  | #include <string.h> | int strncmp(const char *s1, const char *s2, size_t n); | 比较字符串（指定长度） |
|  | #include <string.h> | char *strrchr(const char *s, int c); | 在字符串中定位字符 |
|  | #include <string.h> | char *strstr(const char *haystack, const char *needle); | 寻找指定的子串 |
|  | #include <stdlib.h> | long int strtol(const char *nptr, char **endptr, int base); | 将字符串转换为long型整数 |
|  | #include <stdlib.h> | unsigned long int strtoul(const char *nptr, char **endptr, int base); | 将字符串转换为unsigned long型整数 |
|  | #include <stdlib.h> | unsigned long long int strtoull(const char *nptr, char **endptr,int base); | 将字符串转换为unsigned long long型整数 |
|  | #include <regex.h> | int regcomp(regex_t *preg, const char *regex, int cflags); | 编译正则表达式 |
|  | #include <regex.h> | int regexec(const regex_t *preg, const char *string, size_t nmatch,regmatch_t pmatch[], int eflags); | 匹配正则表达式 |
|  | #include <regex.h> | void regfree(regex_t *preg); | 释放正则表达式 |
|  | #include <string.h> | char *strerror(int errnum); | 返回描述错误号的字符串 |
| math | #include <stdlib.h> | int abs(int i); | 取绝对值 |
|  | #include <math.h> | double log(double x); | 自然对数函数 |
|  | #include <math.h> | double pow(double x, double y); | 求x的指数y次幂 |
|  | #include <math.h> | double round(double x); | 从零开始，舍入到最接近的整数 |
|  | #include <math.h> | double sqrt(double x); | 平方根 |
| IO | #include <stdio.h> | void clearerr(FILE *stream); | 清除流的文件结尾和错误指示 |
|  | #include <stdio.h> | int fclose(FILE *stream); | 关闭文件流 |
|  | #include <stdio.h> | FILE *fdopen(int fd, const char *mode); | 通过文件描述符打开文件流 |
|  | #include <stdio.h> | int feof(FILE *stream); | 检测返回文件末尾指示位 |
|  | #include <stdio.h> | int fflush(FILE *stream); | 刷新流 |
|  | #include <stdio.h> | char *fgets(char *s, int size, FILE *stream); | 读取流的下一行 |
|  | #include <stdio.h> | int fileno(FILE *stream); | 返回流的文件描述符 |
|  | #include <stdio.h> | FILE *fopen(const char *path, const char *mode); | 打开流 |
|  | #include <stdio.h> | int fputs(const char *s, FILE *stream); | 向指定流写入一行 |
|  | #include <stdio.h> | size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream); | 读一个流 |
|  | #include <stdio.h> | int fseek(FILE *stream, long offset, int whence); | 设置流指针的位置 |
|  | #include <stdio.h> | long ftell(FILE *stream); | 获取流指针的位置 |
|  | #include <stdio.h> | size_t fwrite(const void *ptr, size_t size, size_t nmemb,FILE *stream); | 向流写入 |
|  | #include <stdio.h> | void perror(const char *s); | 打印系统错误信息 |
|  | #include <stdio.h> | void rewind(FILE *stream); | 重新定位流 |
|  | #include <unistd.h> | ssize_t write(int fd, const void *buf, size_t size); | 写文件内容 |
|  | #include <unistd.h> | ssize_t read(int fd, void *buf, size_t size); | 读文件内容 |
| net | #include <sys/socket.h> | void freeaddrinfo(struct addrinfo *res); | 释放调用getaddrinfo所分配的动态内存 |
|  | #include <sys/socket.h> | int getaddrinfo(const char *restrict nodename,const char *restrict servname,const struct addrinfo *restrict hints,struct addrinfo **restrict res); | 网络地址和服务转换 |
|  | #include <sys/socket.h> | int getnameinfo(const struct sockaddr *restrict sa, socklen_t salen,char *restrict node, socklen_t nodelen, char *restrict service,socklen_t servicelen, int flags); | 以协议无关的方式进行地址到名称的转换 |
|  | #include <net/if.h> | unsigned int if_nametoindex(const char *ifname); | 通过网络接口名得到索引 |
|  | #include <arpa/inet.h> | in_addr_t inet_addr(const char *cp); | 网络主机地址点分十进制形式转换位二进制形式 |
|  | #include <arpa/inet.h> | char *inet_ntoa(struct in_addr in); | 网络主机地址二进制形式转换位点分十进制形式 |
|  | #include <arpa/inet.h> | const char *inet_ntop(int af, const void *src,char *dst, socklen_t size); | 网络地址转换 |
|  | #include <arpa/inet.h> | int inet_pton(int af, const char *src, void *dst); | 网络地址转换 |
|  | #include <sys/socket.h> | int listen(int sockfd, int backlog); | 监听套接字 |
|  | #include <sys/socket.h> | ssize_t recvmsg(int sockfd, struct msghdr *msg, int flags); | 从套接字接收消息.只支持iov大小为1的场景，且不支持ancillary消息 |
|  | #include <sys/socket.h> | ssize_t send(int sockfd, const void *buf, size_t len, int flags); | 从socket发送消息 |
|  | #include <sys/socket.h> | ssize_t sendmsg(int sockfd, const struct msghdr *msg, int flags); | 从socket发送消息。不支持ancillary消息 |
|  | #include <sys/socket.h> | ssize_t sendto(int sockfd, const void *buf, size_t len, int flags,const struct sockaddr *dest_addr, socklen_t addrlen); | 从socket发送消息 |
|  | #include <sys/socket.h> | int setsockopt(int sockfd, int level, int optname,const void *optval, socklen_t optlen); | 设置与套接字关联的选项 |
| mem | #include <string.h> | int memcmp(const void *s1, const void *s2, size_t n); | 内存比较 |
|  | #include <string.h> | void *memcpy(void *dest, const void *src, size_t n); | 内存拷贝 |
|  | #include <string.h> | void *memset(void *s, int c, size_t n); | 内存初始化 |
|  | #include <stdlib.h> | void *realloc(void *ptr, size_t size); | 重分配内存 |
|  | #include <stdlib.h> | void *malloc(size_t size); | 动态分配内存块大小 |
|  | #include <stdlib.h> | void free(void *ptr); | 释放ptr所指向的内存空间 |
| IPC | #include <semaphore.h> | int sem_timedwait(sem_t *sem, const struct timespec *abs_timeout); | 计时锁定信号量 |
|  | #include <semaphore.h> | int sem_destroy(sem_t *sem); | 销毁指定的无名信号量 |
|  | #include <semaphore.h> | int sem_trywait(sem_t *sem); | 尝试申请一个信号量 |
|  | #include <semaphore.h> | int sem_init(sem_t *sem, int pshared, unsigned int value); | 创建并初始化一个无名信号量 |
|  | #include <semaphore.h> | int sem_post(sem_t *sem); | 增加信号量计数 |
|  | #include <semaphore.h> | int sem_wait(sem_t *sem); | 获取信号量 |
|  | #include <mqueue.h> | mqd_t mq_open(const char *mqName, int openFlag, ...); | 此API用于打开一个具有指定名称的已有消息队列或创建一个新的消息队列 |
|  | #include <mqueue.h> | int mq_close(mqd_t personal); | 此API用于关闭具有指定描述符的消息队列 |
|  | #include <mqueue.h> | int mq_unlink(const char *mqName); | 此API用于删除具有指定名称的消息队列 |
|  | #include <mqueue.h> | int mq_send(mqd_t personal, const char *msg, size_t msgLen, unsigned int msgPrio); | 此API用于将具有指定内容和长度的消息放入具有指定描述符的消息队列中 |
|  | #include <mqueue.h> | ssize_t mq_receive(mqd_t personal, char *msg, size_t msgLen, unsigned int *msgPrio); | 此API用于从具有指定描述符的消息队列中删除最老的消息，并将其放入msg_ptr所指向的缓冲区中 |
|  | #include <mqueue.h> | int mq_timedsend(mqd_t personal, const char *msg, size_t msgLen, unsigned int msgPrio, const struct timespec *absTimeout) | 此API用于在预定时间将具有指定内容和长度的消息放入具有描述符的消息队列中 |
|  | #include <mqueue.h> | ssize_t mq_timedreceive(mqd_t personal, char *msg, size_t msgLen, unsigned int *msgPrio, const struct timespec *absTimeout); | 此API用于从具有指定描述符的消息队列消息中获取具有指定消息内容和长度的消息 |
|  | #include <mqueue.h> | int mq_setattr(mqd_t mqdes, const struct mq_attr *__restrict newattr, struct mq_attr *__restrict oldattr); | 设置描述符指定的消息队列属性 |
|  | version | #include <libc.h> | const char *libc_get_version_string(void); |
|  | #include <libc.h> | int libc_get_version(void); | 获取libc版本号 |


### 注意事项

常用错误码对照表：

| C Name | Value | Description | 含义 |
| -------- | -------- | -------- | -------- |
| ENOERR | 0 | Success | 成功 |
| EPERM | 1 | Operation not permitted | 操作不允许 |
| ENOENT | 2 | No such file or directory | 没有这样的文件或目录 |
| ESRCH | 3 | No such process | 没有这样的进程(暂不支持) |
| EINTR | 4 | Interrupted system call | 系统调用被中断 |
| EIO | 5 | I/O error | I/O错误 |
| ENXIO | 6 | No such device or address | 没有这样的设备或地址 |
| E2BIG | 7 | Arg list too long | 参数列表太长 |
| ENOEXEC | 8 | Exec format error | 执行格式错误 |
| EBADF | 9 | Bad file number | 坏的文件描述符 |
| ECHILD | 10 | No child processes | 没有子进程(暂不支持) |
| EAGAIN | 11 | Try again | 资源暂时不可用 |
| ENOMEM | 12 | Out of memory | 内存溢出 |
| EACCES | 13 | Permission denied | 拒绝许可 |
| EFAULT | 14 | Bad address | 错误的地址 |
| ENOTBLK | 15 | Block device required | 块设备请求 |
| EBUSY | 16 | Device or resource busy | 设备或资源忙 |
| EEXIST | 17 | File exists | 文件存在 |
| EXDEV | 18 | Cross-device link | 无效的交叉链接 |
| ENODEV | 19 | No such device | 设备不存在 |
| ENOTDIR | 20 | Not a directory | 不是一个目录 |
| EISDIR | 21 | Is a directory | 是一个目录 |
| EINVAL | 22 | Invalid argument | 无效的参数 |
| ENFILE* | 23 | File table overflow | 打开太多的文件系统 |
| EMFILE | 24 | Too many open files | 打开的文件过多 |
| EFBIG | 27 | File too large | 文件太大 |
| ENOSPC | 28 | No space left on device | 设备上没有空间 |
| ESPIPE | 29 | Illegal seek | 非法移位 |
| EROFS | 30 | Read-only file system | 只读文件系统 |
| EMLINK | 31 | Too many links | 太多的链接 |
| EDOM | 33 | Math argument out of domain | 数值结果超出范围 |
| ERANGE | 34 | Math result not representable | 数值结果不具代表性 |
| EDEADLK | 35 | Resource deadlock would occur | 资源死锁错误 |
| ENAMETOOLONG | 36 | Filename too long | 文件名太长 |
| ENOLCK | 37 | No record locks available | 没有可用锁 |
| ENOSYS | 38 | Function not implemented | 功能没有实现 |
| ENOTEMPTY | 39 | Directory not empty | 目录不空 |
| ELOOP | 40 | Too many symbolic links encountered | 符号链接层次太多 |
| ENOMSG | 42 | No message of desired type | 没有期望类型的消息 |
| EIDRM | 43 | Identifier removed | 标识符删除 |
| ELNRNG | 48 | Link number out of range | 链接数超出范围 |
| EBADR | 53 | Invalid request descriptor | 请求描述符无效 |
| EBADRQC | 56 | Invalid request code | 无效的请求代码 |
| ENOSTR | 60 | Device not a stream | 设备不是字符流 |
| ENODATA | 61 | No data available | 无可用数据 |
| ETIME | 62 | Timer expired | 计时器过期 |
| EPROTO | 71 | Protocol error | 协议错误 |
| EBADMSG | 74 | Not a data message | 非数据消息 |
| EOVERFLOW | 75 | Value too large for defined data type | 值太大,对于定义数据类型 |
| EMSGSIZE | 90 | Message too long | 消息太长 |


### 编程实例

demo功能：

创建一个线程并将父线程中的信息传递给子线程，在子线程中打印传递过来的信息和自身线程id值。

```
#include <stdio.h>
#include <pthread.h>

pthread_t ntid;

void *ThreadFn(void *arg)
{
    pthread_t tid;
    while(1) {
        tid = pthread_self();
        printf("\n++++++++++++++  %s  %s  tid = %d ++++++++++++++\n", (char*)arg, __FUNCTION__, tid);
    }
    return ((void *)0);
}

void DemoForTest()
{
    int err;
    char* str = "Hello world";
    err = pthread_create(&ntid, NULL, ThreadFn, (void*)str);
    if(err != 0) {
        printf("can't create thread\n");
    }
}

```

执行DemoForTest运行结果如下：

```
++++++++++++++  Hello world  ThreadFn  tid = 48 ++++++++++++++

++++++++++++++  Hello world  ThreadFn  tid = 48 ++++++++++++++

++++++++++++++  Hello world  ThreadFn  tid = 48 ++++++++++++++
```
