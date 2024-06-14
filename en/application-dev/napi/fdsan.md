# fdsan

## Functionality

### Overview

File descriptor sanitizer (fdsan) is a tool used to detect and clean up file descriptor (FD) errors. An FD is a process-unique identifier (handle) for a file, directory, network socket, or other I/O devices in an operating system. fdsan can detect double-free and use-after-close issues of FDs.

When a file or socket is opened in an application, an FD is generated. If the FD is repeatedly closed after use or is used after being closed, security risks such as file handle leaks and memory leaks may occur. This type of problems is difficult to locate. That is why fdsan comes in handy.


### Sample Code

```cpp
void thread_test_one() {
    int fd = open("/dev/null", O_RDONLY);
    close(fd);
    close(fd);
}

void thread_test_two() {
    while (true) {
        int fd = open("log", O_WRONLY | O_APPEND);
        if (write(fd, "foo", 3) != 3) {
            OH_LOG_ERROR(LOG_APP, "write failed!");
        }
    }
}
```
Run the preceding two threads at the same time. The execution result may be as follows:
```cpp
thread test one                           thread test two
open("/dev/null", O_RDONLY) = 123
close(123) = 0
                                          open("log", O_WRONLY | APPEND) = 123
close(123) = 0
                                          write(123, "foo", 3) = -1 (EBADF)
                                          OH_LOG_ERROR(LOG_APP, "write failed!")
```

Test thread 1 closes the same FD twice (double close), and test thread 2 opens a log file repeatedly without closing it. fdsan can catch these issues, which are difficult to be noticed on the thread (thread 2 in this example) which the error occurred.


## Design

### fdsan Design Mechanism

fdsan provides functions to associate FDs with owners and enforces detection of FD errors based on ownership. When a file is opened or created, the FD returned is associated with a tag, which indicates the owner responsible for closing it. Before the file is closed, the tag associated with the FD is checked to determine whether the owner is correct. If yes, the file will be closed. Otherwise, an exception will be thrown to trigger error handling.

A tag is of 64 bits, consisting of the following:

- **type**: an 8-bit string indicating how an FD is encapsulated for management. For example, **FDSAN_OWNER_TYPE_FILE** indicates that the FD is managed as a handle to a file. The value of **type** is defined in **fdsan_owner_type**.
- **value**: a 56-bit string uniquely identifying a tag.

**Figure** Tag

![](./figures/tag.png)

### fdsan APIs

#### fdsan_set_error_level
```
enum fdsan_error_level fdsan_set_error_level(enum fdsan_error_level new_level);
```
**Description**

Sets an error level, which determines the processing behavior when an exception is detected. The default value of **error_level** is **FDSAN_ERROR_LEVEL_WARN_ALWAYS**.

**Parameters**

The following table describes **fdsan_error_level**.

| Value                      | Description                                                        |
| -------------------------- | ------------------------------------------------------------ |
| `FDSAN_ERROR_LEVEL_DISABLED` | fdsan is disabled, that is, no processing is performed.                        |
| `FDSAN_ERROR_LEVEL_WARN_ONCE` | Give a warning in HiLog only when the error is detected for the first time and then continue execution with fdsan disabled (**FDSAN_ERROR_LEVEL_DISABLED**).|
| `FDSAN_ERROR_LEVEL_WARN_ALWAYS` | Give a warning in HiLog only each time the error is detected.|
| `FDSAN_ERROR_LEVEL_FATAL` | Call **abort** to terminate the process when the error is detected.|


#### fdsan_get_error_level

```
enum fdsan_error_level fdsan_get_error_level();
```

**Description**

Obtains the error level.

#### fdsan_create_owner_tag
```
uint64_t fdsan_create_owner_tag(enum fdsan_owner_type type, uint64_t tag);
```
**Description**

Creates a tag for an FD.

**Parameters**

The following describes **fdsan_owner_type**.

```cpp
	FDSAN_OWNER_TYPE_GENERIC_00 = 0,
	FDSAN_OWNER_TYPE_GENERIC_FF = 255,

	/* File. * */
	FDSAN_OWNER_TYPE_FILE = 1,

	/* Directory. * */
	FDSAN_OWNER_TYPE_DIR = 2,

	/* Unique FD. */
	FDSAN_OWNER_TYPE_UNIQUE_FD = 3,

	/* zip archive. */
	FDSAN_OWNER_TYPE_ZIPARCHIVE = 4,
```



#### fdsan_exchange_owner_tag

```
void fdsan_exchange_owner_tag(int fd, uint64_t expected_tag, uint64_t new_tag);
```
**Description**

Modifies a tag.

The tool locates the **FdEntry** based on the FD and checks whether the value of **close_tag** is the same as that of **expected_tag**. If yes, you can change the value of **FdEntry** with the value of **new_tag** passed in.

If the value of **close_tag** is not the same as that of **expected_tag**, an error occurs. Perform error handling.

**Parameters**

| Name                      | Type              | Description                                                        |
| -------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| `fd` | int | FD, which serves as an index of **FdEntry**.|
| `expected_tag` | uint64_t | Expected value of the tag.    |
| `new_tag` | uint64_t | New value of the tag.  |



#### fdsan_close_with_tag

```
int fdsan_close_with_tag(int fd, uint64_t tag);
```
**Description**

Closes an FD based on the tag descriptor.

The tool locates the **FdEntry** based on the FD. If **close_tag** is the same as **tag**, the FD will be closed. Otherwise, an exception is detected.

**Parameters**

| Name                      | Type              | Description                                                        |
| -------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| `fd` | int | FD to close.|
| `tag` | uint64_t | Expected tag.    |

#### fdsan_get_owner_tag
```
uint64_t fdsan_get_owner_tag(int fd);
```
**Description**

Obtains tag information based on an FD.

The tool locates **FdEntry** based on the FD and obtains **close_tag**.

**Parameters**

| Name                      | Type              | Description                                                        |
| -------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| `tag` | uint64_t | ownership tag     |

#### fdsan_get_tag_type
```
const char* fdsan_get_tag_type(uint64_t tag);
```
**Description**

Obtains the type from a tag.

**Parameters**

| Name                      | Type              | Description                                                        |
| -------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| `tag` | uint64_t | Tag.     |

#### fdsan_get_tag_value
```
uint64_t fdsan_get_tag_value(uint64_t tag);
```
**Description**

Obtains the value from a tag.

**Parameters**

| Name                      | Type              | Description                                                        |
| -------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| `tag` | uint64_t | Tag.    |



## Usage

### Using fdsan

Use fdsan to detect a double-close problem.

```
void good_write()
{
    sleep(1);
    int fd = open(DEV_NULL_FILE, O_RDONLY);
    sleep(3);
    ssize_t ret = write(fd, "fdsan test\n", 11);
    if (ret == -1) {
        OH_LOG_ERROR(LOG_APP, "good write but failed?!");
    }
    close(fd);
}

void bad_close()
{
    int fd = open(DEV_NULL_FILE, O_RDONLY);
    close(fd);
    sleep(2);
    // This close expected to be detect by fdsan
    close(fd);
}

void functional_test()
{
    std::vector<std::thread> threads;
    for (auto function : { good_write, bad_close }) {
        threads.emplace_back(function);
    }
    for (auto& thread : threads) {
        thread.join();
    }
}

int main()
{
    functional_test();
    return 0;
}
```
When running the preceding code, the application execution status is as follows:

```cpp
thread test one                           thread test two
open("/dev/null", O_RDONLY) = 43
close(43) = 0
                                          open("log", O_WRONLY | APPEND) = 43
close(43) = 0
                                          write(43, "fdsan test", 11) = -1 (EBADF)
                                          OH_LOG_ERROR(LOG_APP, "good write but failed?!")
```

### Using Standard Library APIs

The **fopen**, **fdopen**, **opendir**, and **fdopendir** APIs in standard libraries have integrated fdsan. Using these APIs instead of **open** can help detect FD problems. For example, use **fopen** instead of **open**.

```cpp
void good_write()
{
    sleep(1);
    // fopen is protected by fdsan. Use fopen to replace open. 
    // int fd = open(DEV_NULL_FILE, O_RDONLY);
    FILE *f = fopen(DEV_NULL_FILE, O_RDONLY);
    sleep(3);
    ssize_t ret = write(fileno(f), "fdsan test\n", 11);
    if (ret == -1) {
        OH_LOG_ERROR(LOG_APP, "good write but failed?!");
    }
    close(fileno(f));
}
```

Each FD returned by **fopen** has a tag. When the FD is closed by **close**, fdsan checks whether the FD matches the tag. If the FD does not match the tag, related log information is displayed by default. The log information for the preceding code is as follows:

```
# hilog | grep MUSL-FDSAN
04-30 15:03:41.760 10933  1624 E C03f00/MUSL-FDSAN: attempted to close file descriptor 43,                             expected to be unowned, actually owned by FILE* 0x00000000f7b90aa2
```

As indicated by the log, the file of the FILE interface body is closed by others by mistake. The address of the FILE interface body can be used to further locate the fault.

In addition, you can use **fdsan_set_error_level** to set the error level. If **error_level** is set to **FDSAN_ERROR_LEVEL_FATAL**, fdsan also provides stack information for fault locating in addition to the log information. The following is an example of the stack information generated upon a crash after **error_level** is set to **FDSAN_ERROR_LEVEL_FATAL**:

```
Generated by HiviewDFX@OpenHarmony
================================================================
Device info:OpenHarmony 3.2
Build info:OpenHarmony 5.0.0.22
Fingerprint:fd76f9ca51bf1b4215afa4826513915fca42ac22cfd82260fe81614668929017
Module name:com.example.myapplication
Version:1.0.0
VersionCode:1000000
PreInstalled:No
Foreground:Yes
Timestamp:2024-04-30 15:51:27.000
Pid:15284
Uid:20010043
Process name:com.example.myapplication
Process life time:4s
Reason:Signal:SIGABRT(SI_TKILL)@0x0000076e from:1902:20010043
Fault thread info:
Tid:15312, Name:e.myapplication
#00 pc 000e65bc /system/lib/ld-musl-arm.so.1(raise+176)(3de40c79448a2bbced06997e583ef614)
#01 pc 0009c3bc /system/lib/ld-musl-arm.so.1(abort+16)(3de40c79448a2bbced06997e583ef614)
#02 pc 0009de4c /system/lib/ld-musl-arm.so.1(fdsan_error+116)(3de40c79448a2bbced06997e583ef614)
#03 pc 0009e2e8 /system/lib/ld-musl-arm.so.1(fdsan_close_with_tag+836)(3de40c79448a2bbced06997e583ef614)
#04 pc 0009e56c /system/lib/ld-musl-arm.so.1(close+20)(3de40c79448a2bbced06997e583ef614)
#05 pc 000055d8 /data/storage/el1/bundle/libs/arm/libentry.so(bad_close()+96)(f3339aac824c099f449153e92718e1b56f80b2ba)
#06 pc 00006cf4 /data/storage/el1/bundle/libs/arm/libentry.so(decltype(std::declval<void (*)()>()()) std::__n1::__invoke[abi:v15004]<void (*)()>(void (*&&)())+24)(f3339aac824c099f449153e92718e1b56f80b2ba)
#07 pc 00006c94 /data/storage/el1/bundle/libs/arm/libentry.so(f3339aac824c099f449153e92718e1b56f80b2ba)
#08 pc 000067b8 /data/storage/el1/bundle/libs/arm/libentry.so(void* std::__n1::__thread_proxy[abi:v15004]<std::__n1::tuple<std::__n1::unique_ptr<std::__n1::__thread_struct, std::__n1::default_delete<std::__n1::__thread_struct>>, void (*)()>>(void*)+100)(f3339aac824c099f449153e92718e1b56f80b2ba)
#09 pc 00105a6c /system/lib/ld-musl-arm.so.1(start+248)(3de40c79448a2bbced06997e583ef614)
#10 pc 000700b0 /system/lib/ld-musl-arm.so.1(3de40c79448a2bbced06997e583ef614)
```

The stack information provides information about **bad_close**. Besides, information about all opened files is provided, helping quickly locate faults.

```
OpenFiles:
0->/dev/null native object of unknown type 0
1->/dev/null native object of unknown type 0
2->/dev/null native object of unknown type 0
3->socket:[28102] native object of unknown type 0
4->socket:[28103] native object of unknown type 0
5->anon_inode:[eventpoll] native object of unknown type 0
6->/sys/kernel/debug/tracing/trace_marker native object of unknown type 0
7->anon_inode:[eventpoll] native object of unknown type 0
8->anon_inode:[eventpoll] native object of unknown type 0
9->/dev/console native object of unknown type 0
10->pipe:[95598] native object of unknown type 0
11->pipe:[95598] native object of unknown type 0
12->socket:[18542] native object of unknown type 0
13->pipe:[96594] native object of unknown type 0
14->socket:[18545] native object of unknown type 0
15->pipe:[96594] native object of unknown type 0
16->anon_inode:[eventfd] native object of unknown type 0
17->/dev/binder native object of unknown type 0
18->/data/storage/el1/bundle/entry.hap native object of unknown type 0
19->anon_inode:[eventpoll] native object of unknown type 0
20->anon_inode:[signalfd] native object of unknown type 0
21->socket:[29603] native object of unknown type 0
22->anon_inode:[eventfd] native object of unknown type 0
23->anon_inode:[eventpoll] native object of unknown type 0
24->anon_inode:[eventfd] native object of unknown type 0
25->anon_inode:[eventpoll] native object of unknown type 0
26->anon_inode:[eventfd] native object of unknown type 0
27->anon_inode:[eventpoll] native object of unknown type 0
28->anon_inode:[eventfd] native object of unknown type 0
29->anon_inode:[eventpoll] native object of unknown type 0
30->anon_inode:[eventfd] native object of unknown type 0
31->anon_inode:[eventpoll] native object of unknown type 0
32->anon_inode:[eventfd] native object of unknown type 0
33->anon_inode:[eventpoll] native object of unknown type 0
34->anon_inode:[eventfd] native object of unknown type 0
35->socket:[97409] native object of unknown type 0
36->socket:[94716] native object of unknown type 0
38->socket:[94720] native object of unknown type 0
40->/data/storage/el1/bundle/entry_test.hap native object of unknown type 0
41->socket:[95617] native object of unknown type 0
42->/sys/kernel/debug/tracing/trace_marker native object of unknown type 0
43->/dev/null FILE* 4155724704
44->socket:[94737] native object of unknown type 0
45->pipe:[95634] native object of unknown type 0
46->pipe:[95634] native object of unknown type 0
47->pipe:[95635] native object of unknown type 0
49->pipe:[95636] native object of unknown type 0
50->pipe:[95636] native object of unknown type 0
```


### Implementing APIs with fdsan

You can also implement APIs with fdsan by using **fdsan_exchange_owner_tag** and **fdsan_close_with_tag**. The former can be used to set a tag for an FD; the latter can be used to check the tag before a file is closed.

The following is an example:

```cpp
struct unique_fd {
    unique_fd() = default;

    explicit unique_fd(int fd)
    {
        reset(fd);
    }

    unique_fd(const unique_fd& copy) = delete;
    unique_fd(unique_fd&& move)
    {
        *this = std::move(move);
    }

    ~unique_fd()
    {
        reset();
    }

    unique_fd& operator=(const unique_fd& copy) = delete;
    unique_fd& operator=(unique_fd&& move)
    {
        if (this == &move) {
            return *this;
        }
        reset();
        if (move.fd_ != -1) {
            fd_ = move.fd_;
            move.fd_ = -1;
            // Obtain the ownership from the moved-from object.
            exchange_tag(fd_, move.tag(), tag());
        }
        return *this;
    }

    int get()
    {
        return fd_;
    }

    void reset(int new_fd = -1)
    {
        if (fd_ != -1) {
            close(fd_, tag());
            fd_ = -1;
        }
        if (new_fd != -1) {
            fd_ = new_fd;
            // Obtain the ownership of the presumably unowned FD.
            exchange_tag(fd_, 0, tag());
        }
    }

  private:
    int fd_ = -1;

    // Use the address of object as the file tag.
    uint64_t tag()
    {
        return reinterpret_cast<uint64_t>(this);
    }

    static void exchange_tag(int fd, uint64_t old_tag, uint64_t new_tag)
    {
        if (&fdsan_exchange_owner_tag) {
            fdsan_exchange_owner_tag(fd, old_tag, new_tag);
        }
    }

    static int close(int fd, uint64_t tag)
    {
        if (&fdsan_close_with_tag) {
            return fdsan_close_with_tag(fd, tag);
        }
    }
};
```

In this example, **fdsan_exchange_owner_tag** is used to bind an FD and the address of a struct object. Then, **fdsan_close_with_tag** is used to check whether the tag matches the FD before the file is closed. The expected tag is the struct object address.

You can also set **error_level** to **FDSAN_ERROR_LEVEL_FATAL** so that fdsan can proactively crash when detecting an error to provide more information for fault locating.
