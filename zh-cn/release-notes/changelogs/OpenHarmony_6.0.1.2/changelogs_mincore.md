# Kernel子系统changelog

## cl.kernel.1 mincore接口功能补齐至与Linux一致

**访问级别**

系统接口

**变更原因**

由于部分应用需要使用`mincore`做内存相关的性能调优，出参结果影响使用者调优的准确性。

本次变更对齐`Linux`中的实现，mincore支持判断出对应的物理页是否在`pagecache`或`swapcache`中。

**变更影响**

此变更不涉及应用适配。

mincore详细使用方法可见[man mincore](https://man7.org/linux/man-pages/man2/mincore.2.html)。

变更前：判断对应物理页是否有有效物理地址，若有则mincore出参返回1，反之则返回0。

变更后：增加对pagecache和swapcache的校验，若对应物理页在RAM中，则mincore出参返回1，反之则返回0。

**起始 API Level**

不涉及

**变更发生版本**

 OpenHarmony SDK 6.0.1.2

**变更的接口/组件**

mincore

**适配指导**

 - 场景一：判断自身文件是否在RAM中

    如果用户态程序仅用于判断自身文件是否在RAM中（即文件由当前进程创建或拥有权限），则现有逻辑无需调整，不需要修改代码。因为在这种情况下，权限校验必然通过，因此vec的值能够准确反映页面是否在RAM中。

 - 场景二：判断非自身文件是否在RAM中

    如果用户态程序需要判断非自身文件是否在RAM中，则必须在调用`mincore`前增加权限校验逻辑。权限校验可以通过以下方式实现：
    1. 检查当前进程是否是文件的所有者；
    2. 检查当前进程是否拥有`POSIX_CAP_FOWNER`能力；
    3. 尝试以写权限重新打开文件（例如使用`open(file_path, O_WRONLY)`）。

    如果权限校验未通过，则不应继续调用`mincore`，避免因权限不足导致的误判。

示例分析

- 错误示例

```c
fd = open(file_path, O_RDONLY)
file_size = lseek(fd, 0, SEEK_END)
mapped_memory = mmap(NULL, file_size, PROT_READ, MAP_PRIVATE, fd, 0)
vec = allocate_array(num_pages)
if mincore(mapped_memory, file_size, vec) == -1:
        print("mincore 调用失败")
        munmap(mapped_memory, file_size)
        close(fd)
        return False
in_ram = False
for i from 0 to num_pages - 1:
        if vec[i] & 1:
                in_ram = True
                break
```

- 问题分析：

    如果file_path中的文件是非自身创建的文件，且当前进程没有足够的权限，则mincore返回的vec[i] = 1并不一定表示页面在RAM中，实际上可能是因为权限不足。

 - 正确示例

```c
fd = open(file_path, O_RDONLY)
file_size = lseek(fd, 0, SEEK_END)
mapped_memory = mmap(NULL, file_size, PROT_READ, MAP_PRIVATE, fd, 0)

// 增加权限校验
if !(is_file_owner && have_capability && can_write_file):
        munmap(mapped_memory, file_size)
        close(fd)
        return

vec = allocate_array(num_pages)
if mincore(mapped_memory, file_size, vec) == -1:
        print("mincore 调用失败")
        munmap(mapped_memory, file_size)
        close(fd)
        return False

in_ram = False
for i from 0 to num_pages - 1:
        if vec[i] & 1:
                in_ram = True
                break

munmap(mapped_memory, file_size)
close(fd)
return in_ram
```
