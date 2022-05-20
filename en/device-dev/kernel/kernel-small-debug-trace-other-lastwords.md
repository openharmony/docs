# Dying Gasp

## When to Use<a name="section158501652121514"></a>

For a device without a serial port, the dying gasp saves the exception information to a non-volatile storage medium to facilitate fault location during system running.

## Available APIs<a name="section1186411122215"></a>

The system provides a mechanism to save printed exception information to a non-volatile storage medium. You can register the hook function of the information printed when the read and write operations are abnormal. In this way, fault information can be saved on different storage media, facilitating fault locating for devices without serial ports. The API is  **LOS\_ExcInfoRegHook**. This function is declared in  **los\_config.h**. The function prototype is as follows:

```
typedef VOID (*log_read_write_fn)(UINT32 startAddr, UINT32 space, UINT32 rwFlag, CHAR *buf);
...
VOID LOS_ExcInfoRegHook(UINT32 startAddr, UINT32 space, CHAR *buf, log_read_write_fn hook);
```

## Parameters<a name="section1083765723015"></a>

**Table  1**  LOS\_ExcInfoRegHook parameter description

<a name="table1345253123117"></a>
<table><thead align="left"><tr id="row19452331143115"><th class="cellrowborder" valign="top" width="42.77%" id="mcps1.2.3.1.1"><p id="p1145253110313"><a name="p1145253110313"></a><a name="p1145253110313"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="57.230000000000004%" id="mcps1.2.3.1.2"><p id="p9452153114313"><a name="p9452153114313"></a><a name="p9452153114313"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row5452131123110"><td class="cellrowborder" valign="top" width="42.77%" headers="mcps1.2.3.1.1 "><p id="p1245233110317"><a name="p1245233110317"></a><a name="p1245233110317"></a>startAddr</p>
</td>
<td class="cellrowborder" valign="top" width="57.230000000000004%" headers="mcps1.2.3.1.2 "><p id="p1845203116313"><a name="p1845203116313"></a><a name="p1845203116313"></a>Start address of the physical medium to be got or set</p>
</td>
</tr>
<tr id="row745217316312"><td class="cellrowborder" valign="top" width="42.77%" headers="mcps1.2.3.1.1 "><p id="p7452331133118"><a name="p7452331133118"></a><a name="p7452331133118"></a>space</p>
</td>
<td class="cellrowborder" valign="top" width="57.230000000000004%" headers="mcps1.2.3.1.2 "><p id="p9452203117312"><a name="p9452203117312"></a><a name="p9452203117312"></a>Size of the space</p>
</td>
</tr>
<tr id="row15578112463216"><td class="cellrowborder" valign="top" width="42.77%" headers="mcps1.2.3.1.1 "><p id="p5578202413220"><a name="p5578202413220"></a><a name="p5578202413220"></a>buf</p>
</td>
<td class="cellrowborder" valign="top" width="57.230000000000004%" headers="mcps1.2.3.1.2 "><p id="p1057816247322"><a name="p1057816247322"></a><a name="p1057816247322"></a>Memory buffer used to get or set the exception information</p>
</td>
</tr>
<tr id="row0123932163215"><td class="cellrowborder" valign="top" width="42.77%" headers="mcps1.2.3.1.1 "><p id="p612320322321"><a name="p612320322321"></a><a name="p612320322321"></a>log_read_write_fn</p>
</td>
<td class="cellrowborder" valign="top" width="57.230000000000004%" headers="mcps1.2.3.1.2 "><p id="p17123143218322"><a name="p17123143218322"></a><a name="p17123143218322"></a>Function used to get or set the exception information</p>
</td>
</tr>
</tbody>
</table>

**Table  2**  log\_read\_write\_fn parameter description

<a name="table1950318463620"></a>
<table><thead align="left"><tr id="row45034463611"><th class="cellrowborder" valign="top" width="42.77%" id="mcps1.2.3.1.1"><p id="p950316412365"><a name="p950316412365"></a><a name="p950316412365"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="57.230000000000004%" id="mcps1.2.3.1.2"><p id="p1050304123619"><a name="p1050304123619"></a><a name="p1050304123619"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1850394153612"><td class="cellrowborder" valign="top" width="42.77%" headers="mcps1.2.3.1.1 "><p id="p155039453619"><a name="p155039453619"></a><a name="p155039453619"></a>startAddr</p>
</td>
<td class="cellrowborder" valign="top" width="57.230000000000004%" headers="mcps1.2.3.1.2 "><p id="p18503341366"><a name="p18503341366"></a><a name="p18503341366"></a>Start address of the physical medium to be got or set</p>
</td>
</tr>
<tr id="row1450354113617"><td class="cellrowborder" valign="top" width="42.77%" headers="mcps1.2.3.1.1 "><p id="p115031642363"><a name="p115031642363"></a><a name="p115031642363"></a>space</p>
</td>
<td class="cellrowborder" valign="top" width="57.230000000000004%" headers="mcps1.2.3.1.2 "><p id="p1350354113619"><a name="p1350354113619"></a><a name="p1350354113619"></a>Size of the space</p>
</td>
</tr>
<tr id="row750314413361"><td class="cellrowborder" valign="top" width="42.77%" headers="mcps1.2.3.1.1 "><p id="p115031241361"><a name="p115031241361"></a><a name="p115031241361"></a>rwFlag</p>
</td>
<td class="cellrowborder" valign="top" width="57.230000000000004%" headers="mcps1.2.3.1.2 "><p id="p8503548362"><a name="p8503548362"></a><a name="p8503548362"></a>Read/Write flag. The value <strong id="b1039910495392"><a name="b1039910495392"></a><a name="b1039910495392"></a>0</strong> indicates write, and the value <strong id="b236735363912"><a name="b236735363912"></a><a name="b236735363912"></a>1</strong> indicates read.</p>
</td>
</tr>
<tr id="row250312420363"><td class="cellrowborder" valign="top" width="42.77%" headers="mcps1.2.3.1.1 "><p id="p850314493611"><a name="p850314493611"></a><a name="p850314493611"></a>buf</p>
</td>
<td class="cellrowborder" valign="top" width="57.230000000000004%" headers="mcps1.2.3.1.2 "><p id="p85033413613"><a name="p85033413613"></a><a name="p85033413613"></a>Memory buffer used to get or set the exception information</p>
</td>
</tr>
</tbody>
</table>

## How to Develop<a name="section783435801510"></a>

The dying gasp function depends on the macro  **LOSCFG\_SAVE\_EXCINFO**. Before using this function, choose  **Debug**-\>  **Enable Saving Exception Information**  in the configuration items to enable this macro. If this macro is disabled, this function cannot be used. Then, call  **LOS\_ExcInfoRegHook**  in  **SystemInit**  to register the position, size, memory buffer, and access function for accessing the exception information. When an exception occurs in the system, the system saves the exception information in the memory buffer passed in the registration, and then calls the registered access function to write the exception information to the physical storage medium.

>![](../public_sys-resources/icon-note.gif) **NOTE:** 
>-   The location registered to store the exception information cannot overlap with other storage locations.
>-   The registered memory buffer should be greater than or equal to 16 KiB. Otherwise, the exception information stored may be incomplete.
>-   The exception information can be accessed successfully only when the driver of the storage medium corresponding to the registered read/write function is normal.

