# Procfs


## 基本概念

procfs是进程文件系统的简称，是一种虚拟文件系统，他用文件的形式，展示进程或其他系统信息。相比调用接口的方式获取信息，以文件操作的方式获取系统信息更为方便。


## 运行机制

OpenHarmony内核中，procfs在开机时会自动挂载到/proc目录下，仅支持内核模块创建文件节点来提供查询服务。


## 开发指导

procfs文件的创建无法使用一般的文件系统接口，需要使用ProcMkdir接口创建目录，使用CreateProcEntry接口创建文件。文件节点功能的开发就是实现read和write函数的钩子挂到CreateProcEntry创建的文件中。当用户使用读写procfs的文件时，就会调用到钩子函数来实现自定义的功能。


编程实例

下面我们以创建/proc/hello/world文件为例，实现如下功能：

1.在/proc/hello/world位置创建一个文件

2.当读文件内容时，返回"HelloWorld!"

3.当写文件内容时，打印写入的内容

  
```
#include "proc_fs.h"

static int TestRead(struct SeqBuf *buf, void *arg)
{
    LosBufPrintf(buf, "Hello World!\n"); /* 将数据打印到buffer中，这个buffer中的数据会返回到read的结果中 */
    return 0;
}

static int TestWrite(struct ProcFile *pf, const char *buffer, size_t buflen, loff_t *ppos)
{
    if ((buffer == NULL) || (buflen <= 0)) {
        return -EINVAL;
    }

    PRINTK("your input is: %s\n", buffer); /* 注意和上面的read接口区别，这是对write接口输入命令的反馈，这个打印只会打印到控制台 */
    return buflen;
}
static const struct ProcFileOperations HELLO_WORLD_OPS = {
    .read = TestRead,
    .write = TestWrite,
};

void HelloWorldInit(void)
{
    /* 创建hello目录 */
    struct ProcDirEntry *dir = ProcMkdir("hello", NULL);
    if (dir == NULL) {
        PRINT_ERR("create dir failed!\n");
        return;
    }

    /* 创建world文件 */
    struct ProcDirEntry *entry = CreateProcEntry("world", 0, dir);
    if (entry == NULL) {
        PRINT_ERR("create entry failed!\n");
        return;
    }

    /* 将自定义的read和write钩子挂到文件中 */
    entry->procFileOps = &HELLO_WORLD_OPS;
}
```

**结果验证**

启动后在shell输入如下命令

  
```
OHOS # cat /proc/hello/world
OHOS # Hello World!
OHOS # echo "yo" > /proc/hello/world
OHOS # your input is: yo
```
