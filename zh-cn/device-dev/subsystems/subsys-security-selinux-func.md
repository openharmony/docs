# OpenHarmony SELinux对外接口说明

## 概述

SELinux对外提供更新文件或目录SELinux标签的接口。

## 接口说明

所有接口均为Native C内部接口，仅提供底层能力，不对应用开放。相关接口列表如下：

| 接口名 | 接口说明 | 参数说明 |
| --------- | ---------- | ---------- |
| int **Restorecon**(const char *path); | **接口功能**：更新单个文件或者目录的标签，不递归遍历子目录。<br/>**返回值**：0表示成功，其他返回值表示失败。 | path表示绝对路径。 |
| int **RestoreconRecurse**(const char *path); | **接口功能**：单线程更新文件或者目录的标签，递归遍历更新子目录和文件标签。<br/>**返回值**：0表示成功，其他返回值表示失败。 | path表示绝对路径。 |
| int **RestoreconRecurseParallel**(const char *path, unsigned int nthreads); | **接口功能**：多线程更新文件或者目录的标签，递归遍历更新子目录和文件标签。<br/>**返回值**：0表示成功，其他返回值表示失败。 | path表示绝对路径。<br/>nthreads表示线程个数。 |
| int **RestoreconRecurseForce**(const char *path); | **接口功能**：单线程强制更新文件或者目录的标签，递归遍历更新子目录和文件标签。<br/>**返回值**：0表示成功，其他返回值表示失败。 | path表示绝对路径。 |
| int **RestoreconFromParentDir**(const char *path); | **接口功能**：根据当前路径的父目录标签，单线程更新当前路径的标签，递归遍历更新整个目录。<br/>**返回值**：0表示成功，其他返回值表示失败。 | path表示绝对路径。 |

## 开发步骤

1. 编译依赖添加

    ```text
    external_deps += [ "selinux_adapter:librestorecon" ]
    ```

2. 头文件依赖添加

    ```cpp
    #include "policycoreutils.h"
    ```

3. 接口调用

    以Restorecon接口为例：
    ```cpp
    // 更新/data路径标签：
    int ret = Restorecon("/data");
    ```
