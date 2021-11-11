# lsfd<a name="ZH-CN_TOPIC_0000001179965849"></a>

-   [命令功能](#section2053406181716)
-   [命令格式](#section523771017172)
-   [使用指南](#section27241213201719)
-   [使用实例](#section442617197173)
-   [输出说明](#section42491639151813)

## 命令功能<a name="section2053406181716"></a>

lsfd命令用来显示当前已经打开的文件描述符及对应的文件名。

## 命令格式<a name="section523771017172"></a>

lsfd

## 使用指南<a name="section27241213201719"></a>

lsfd命令显示当前已经打开文件的fd号以及文件的名字。

## 使用实例<a name="section442617197173"></a>

举例：输入lsfd

## 输出说明<a name="section42491639151813"></a>

**示例 1**  lsfd输出说明

```shell
OHOS # lsfd
   fd    filename
    3   /dev/console1
    4   /dev/hilog
    5   /dev/hilog
    6   /dev/hilog
    7   /dev/lite_ipc
    8   /dev/hilog
    9   /dev/lite_ipc
   10   /dev/vb
   11   /dev/hilog
   12   /dev/vo
   13   /dev/hilog
   14   /dev/hilog
   15   /dev/sys
   16   /dev/lite_ipc
   17   /dev/lite_ipc
   18   /dev/hi_tde
   19   /dev/fb0
   20   /dev/vo
   21   /dev/mmz_userdev
   22   /dev/hi_tde
   23   /dev/lite_ipc
   24   /dev/hdf/hdf_input_event1
   25   /dev/lite_ipc
   26   /dev/mmz_userdev
   27   /dev/lite_ipc
   28   /dev/hilog
   29   /dev/hilog
   30   /dev/hdf/hdf_sensor_manager_ap
   31   /dev/hilog
   32   /dev/lite_ipc
   33   /dev/lite_ipc
   34   /dev/lite_ipc
```



