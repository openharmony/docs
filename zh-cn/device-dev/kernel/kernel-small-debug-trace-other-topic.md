# 临终遗言<a name="ZH-CN_TOPIC_0000001078588210"></a>

-   [使用场景](#section158501652121514)
-   [功能说明](#section1186411122215)
-   [参数说明](#section1083765723015)
-   [开发流程](#section783435801510)

## 使用场景<a name="section158501652121514"></a>

在无串口的设备上，将系统异常时打印的信息保存到不丢失的存储介质上，方便对运行时问题进行定位。

## 功能说明<a name="section1186411122215"></a>

该调测功能提供了一种用于保存系统异常时打印信息到不丢失存储介质中的机制，用户可自行注册读写异常时打印信息的钩子函数，实现在不同存储介质上保存异常信息的能力，这样方便无串口的设备的问题定位。接口名为LOS\_ExcInfoRegHook，该函数声明在los\_config.h中，函数原型：

```
typedef VOID (*log_read_write_fn)(UINT32 startAddr, UINT32 space, UINT32 rwFlag, CHAR *buf);
......
VOID LOS_ExcInfoRegHook(UINT32 startAddr, UINT32 space, CHAR *buf, log_read_write_fn hook);
```

## 参数说明<a name="section1083765723015"></a>

**表 1**  LOS\_ExcInfoRegHook 参数说明

<a name="table1345253123117"></a>
<table><thead align="left"><tr id="row19452331143115"><th class="cellrowborder" valign="top" width="42.77%" id="mcps1.2.3.1.1"><p id="p1145253110313"><a name="p1145253110313"></a><a name="p1145253110313"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="57.230000000000004%" id="mcps1.2.3.1.2"><p id="p9452153114313"><a name="p9452153114313"></a><a name="p9452153114313"></a>参数说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row5452131123110"><td class="cellrowborder" valign="top" width="42.77%" headers="mcps1.2.3.1.1 "><p id="p1245233110317"><a name="p1245233110317"></a><a name="p1245233110317"></a>startAddr</p>
</td>
<td class="cellrowborder" valign="top" width="57.230000000000004%" headers="mcps1.2.3.1.2 "><p id="p1845203116313"><a name="p1845203116313"></a><a name="p1845203116313"></a>存取异常信息的物理介质起始地址</p>
</td>
</tr>
<tr id="row745217316312"><td class="cellrowborder" valign="top" width="42.77%" headers="mcps1.2.3.1.1 "><p id="p7452331133118"><a name="p7452331133118"></a><a name="p7452331133118"></a>space</p>
</td>
<td class="cellrowborder" valign="top" width="57.230000000000004%" headers="mcps1.2.3.1.2 "><p id="p9452203117312"><a name="p9452203117312"></a><a name="p9452203117312"></a>存取的空间大小</p>
</td>
</tr>
<tr id="row15578112463216"><td class="cellrowborder" valign="top" width="42.77%" headers="mcps1.2.3.1.1 "><p id="p5578202413220"><a name="p5578202413220"></a><a name="p5578202413220"></a>buf</p>
</td>
<td class="cellrowborder" valign="top" width="57.230000000000004%" headers="mcps1.2.3.1.2 "><p id="p1057816247322"><a name="p1057816247322"></a><a name="p1057816247322"></a>存取异常信息的内存缓冲区</p>
</td>
</tr>
<tr id="row0123932163215"><td class="cellrowborder" valign="top" width="42.77%" headers="mcps1.2.3.1.1 "><p id="p612320322321"><a name="p612320322321"></a><a name="p612320322321"></a>log_read_write_fn</p>
</td>
<td class="cellrowborder" valign="top" width="57.230000000000004%" headers="mcps1.2.3.1.2 "><p id="p17123143218322"><a name="p17123143218322"></a><a name="p17123143218322"></a>存取异常信息的函数</p>
</td>
</tr>
</tbody>
</table>

**表 2**  log\_read\_write\_fn 参数说明

<a name="table1950318463620"></a>
<table><thead align="left"><tr id="row45034463611"><th class="cellrowborder" valign="top" width="42.77%" id="mcps1.2.3.1.1"><p id="p950316412365"><a name="p950316412365"></a><a name="p950316412365"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="57.230000000000004%" id="mcps1.2.3.1.2"><p id="p1050304123619"><a name="p1050304123619"></a><a name="p1050304123619"></a>参数说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1850394153612"><td class="cellrowborder" valign="top" width="42.77%" headers="mcps1.2.3.1.1 "><p id="p155039453619"><a name="p155039453619"></a><a name="p155039453619"></a>startAddr</p>
</td>
<td class="cellrowborder" valign="top" width="57.230000000000004%" headers="mcps1.2.3.1.2 "><p id="p18503341366"><a name="p18503341366"></a><a name="p18503341366"></a>存取异常信息的物理介质起始地址</p>
</td>
</tr>
<tr id="row1450354113617"><td class="cellrowborder" valign="top" width="42.77%" headers="mcps1.2.3.1.1 "><p id="p115031642363"><a name="p115031642363"></a><a name="p115031642363"></a>space</p>
</td>
<td class="cellrowborder" valign="top" width="57.230000000000004%" headers="mcps1.2.3.1.2 "><p id="p1350354113619"><a name="p1350354113619"></a><a name="p1350354113619"></a>存取的空间大小</p>
</td>
</tr>
<tr id="row750314413361"><td class="cellrowborder" valign="top" width="42.77%" headers="mcps1.2.3.1.1 "><p id="p115031241361"><a name="p115031241361"></a><a name="p115031241361"></a>rwFlag</p>
</td>
<td class="cellrowborder" valign="top" width="57.230000000000004%" headers="mcps1.2.3.1.2 "><p id="p8503548362"><a name="p8503548362"></a><a name="p8503548362"></a>读写标记，0为写，1为读</p>
</td>
</tr>
<tr id="row250312420363"><td class="cellrowborder" valign="top" width="42.77%" headers="mcps1.2.3.1.1 "><p id="p850314493611"><a name="p850314493611"></a><a name="p850314493611"></a>buf</p>
</td>
<td class="cellrowborder" valign="top" width="57.230000000000004%" headers="mcps1.2.3.1.2 "><p id="p85033413613"><a name="p85033413613"></a><a name="p85033413613"></a>存取异常信息的内存缓冲区</p>
</td>
</tr>
</tbody>
</table>

## 开发流程<a name="section783435801510"></a>

该功能依赖于宏LOSCFG\_SAVE\_EXCINFO，使用临终遗言功能时，在配置项中开启“ Enable Saving Exception Information ”：Debug-\> Enable Saving Exception Information ；若关闭该选项，则该功能失效。功能开启后，可在SystemInit中调用LOS\_ExcInfoRegHook来注册存取异常信息的位置、大小、内存缓冲区以及存取函数。当系统进入异常时，会将异常时系统各类信息先保存在注册时传入的内存缓冲区中，最后调用注册的存取函数，将异常信息写入到物理存储介质中。

>![](../public_sys-resources/icon-note.gif) **说明：** 
>-   注册的存取位置不要跟其他存储重叠。
>-   注册的内存缓冲区不能太小，建议不低于16KiB，否则异常信息会存储不完整。
>-   注册的读写函数对应的具体存储介质的驱动功能正常，才能保证存取功能正常。

