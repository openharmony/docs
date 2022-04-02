# 临终遗言


## 使用场景

在无串口的设备上，将系统异常时打印的信息保存到不丢失的存储介质上，方便对运行时问题进行定位。


## 功能说明

该调测功能提供了一种用于保存系统异常时打印信息到不丢失存储介质中的机制，用户可自行注册读写异常时打印信息的钩子函数，实现在不同存储介质上保存异常信息的能力，这样方便无串口的设备的问题定位。接口名为LOS_ExcInfoRegHook，该函数声明在los_config.h中，函数原型：

```
typedef VOID (*log_read_write_fn)(UINT32 startAddr, UINT32 space, UINT32 rwFlag, CHAR *buf);
......
VOID LOS_ExcInfoRegHook(UINT32 startAddr, UINT32 space, CHAR *buf, log_read_write_fn hook);
```


## 参数说明

  **表1** LOS_ExcInfoRegHook 参数说明

| 参数 | 参数说明 |
| -------- | -------- |
| startAddr | 存取异常信息的物理介质起始地址 |
| space | 存取的空间大小 |
| buf | 存取异常信息的内存缓冲区 |
| log_read_write_fn | 存取异常信息的函数 |

  **表2** log_read_write_fn 参数说明

| 参数 | 参数说明 |
| -------- | -------- |
| startAddr | 存取异常信息的物理介质起始地址 |
| space | 存取的空间大小 |
| rwFlag | 读写标记，0为写，1为读 |
| buf | 存取异常信息的内存缓冲区 |


## 开发流程

该功能依赖于宏LOSCFG_SAVE_EXCINFO，使用临终遗言功能时，在配置项中开启“ Enable Saving Exception Information ”：Debug-&gt; Enable Saving Exception Information ；若关闭该选项，则该功能失效。功能开启后，可在SystemInit中调用LOS_ExcInfoRegHook来注册存取异常信息的位置、大小、内存缓冲区以及存取函数。当系统进入异常时，会将异常时系统各类信息先保存在注册时传入的内存缓冲区中，最后调用注册的存取函数，将异常信息写入到物理存储介质中。


> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> - 注册的存取位置不要跟其他存储重叠。
> 
> - 注册的内存缓冲区不能太小，建议不低于16KiB，否则异常信息会存储不完整。
> 
> - 注册的读写函数对应的具体存储介质的驱动功能正常，才能保证存取功能正常。
