# procfs


## Basic Concepts<a name="section146801917174017"></a>

The proc filesystem \(procfs\) is a virtual file system that displays process or other system information in a file-like structure. It is more convenient to obtain system information in file operation mode than API calling mode.

## Working Principles<a name="section479762916408"></a>

In the OpenHarmony kernel, procfs is automatically mounted to the  **/proc**  directory during startup. Only the kernel module can create file nodes to provide the query service.

## Development Guidelines<a name="section1221174524014"></a>

To create a procfs file, you need to use  **ProcMkdir**  to create a directory and use  **CreateProcEntry**  to create a file. The development of the file node function is to hook the read and write functions to the file created by  **CreateProcEntry**. When the procfs file is read or written, the hooked functions will be called to implement custom functions.

### Development Example<a name="section52016575401"></a>

The following describes how to create the  **/proc/hello/world**  file to implement the following functions:

1. Create a file in  **/proc/hello/world**.

2. Read the file. When the file is read, "HelloWorld!" is returned.

3. Write the file and print the data written in the file.

```
#include "proc_fs.h"

static int TestRead(struct SeqBuf *buf, void *arg)
{
    LosBufPrintf(buf, "Hello World! \n"); /* Print "Hello World!" to the buffer. The data in the buffer will be returned to the read result. */
    return 0;
}

static int TestWrite(struct ProcFile *pf, const char *buffer, size_t buflen, loff_t *ppos)
{
    if ((buffer == NULL) || (buflen <= 0)) {
        return -EINVAL;
    }

    PRINTK("your input is: %s\n", buffer); /* Different from the read API, the write API prints the data only to the console. */
    return buflen;
}
static const struct ProcFileOperations HELLO_WORLD_OPS = {
    .read = TestRead,
    .write = TestWrite,
};

void HelloWorldInit(void)
{
    /* Create the hello directory.*/
    struct ProcDirEntry *dir = ProcMkdir("hello", NULL);
    if (dir == NULL) {
        PRINT_ERR("create dir failed!\n");
        return;
    }

    /* Create the world file. */
    struct ProcDirEntry *entry = CreateProcEntry("world", 0, dir);
    if (entry == NULL) {
        PRINT_ERR("create entry failed!\n");
        return;
    }

    /* Hook the custom read and write APIs to the file. */
    entry->procFileOps = &HELLO_WORLD_OPS;
}
```

**Verification**

After the OS startup, run the following command in the shell:

```
OHOS # cat /proc/hello/world
OHOS # Hello World!
OHOS # echo "yo" > /proc/hello/world
OHOS # your input is: yo
```

