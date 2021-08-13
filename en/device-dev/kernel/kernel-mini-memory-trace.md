# Trace Debugging<a name="EN-US_TOPIC_0000001162019075"></a>

-   [Basic Concepts](#section44851752123712)
-   [Working Principles](#section5282148123813)
-   [Available APIs](#section16304193215387)
-   [Development Guidelines](#section498695853819)
    -   [How to Develop](#section1875652316393)
    -   [Development Example](#section0403134913395)
    -   [Sample Code](#section1492711418400)
    -   [Verification](#section869613984012)


## Basic Concepts<a name="section44851752123712"></a>

Trace debugging helps you learn about the kernel running process and the execution sequence of modules and tasks. With the information, you can better understand the code running process of the kernel and locate time sequence problems.

## Working Principles<a name="section5282148123813"></a>

The kernel provides a framework to embed hooks in main processes of modules. You can register callback functions at the required hooks. When the kernel runs the corresponding process, the kernel proactively calls the  **Hook**  function to transfer key data of the current process to you.

## Available APIs<a name="section16304193215387"></a>

The following table describes APIs available for the OpenHarmony trace module. For more details about the APIs, see the API reference.

**Table  1**  Trace module APIs

<a name="table208266479117"></a>
<table><thead align="left"><tr id="row19826947121114"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p16415637105612"><a name="p16415637105612"></a><a name="p16415637105612"></a>Category</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="p11415163718562"><a name="p11415163718562"></a><a name="p11415163718562"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p1641533755612"><a name="p1641533755612"></a><a name="p1641533755612"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row082617478118"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p1082624717117"><a name="p1082624717117"></a><a name="p1082624717117"></a>Registering a hook</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p1182654713112"><a name="p1182654713112"></a><a name="p1182654713112"></a>LOS_HookReg</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p1582614474114"><a name="p1582614474114"></a><a name="p1582614474114"></a>Registers a callback function at a specified hook.</p>
</td>
</tr>
<tr id="row19470201017154"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p1747021015152"><a name="p1747021015152"></a><a name="p1747021015152"></a>Unregistering a hook</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p16470410201517"><a name="p16470410201517"></a><a name="p16470410201517"></a>LOS_HookUnReg</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p147021017155"><a name="p147021017155"></a><a name="p147021017155"></a>Unregisters the callback function at the current hook.</p>
</td>
</tr>
</tbody>
</table>

## Development Guidelines<a name="section498695853819"></a>

### How to Develop<a name="section1875652316393"></a>

The typical process for enabling trace debugging is as follows:

1.  Configure the macros related to the trace module.

    Modify the configuration in the  **target\_config.h**  file.

    <a name="table1078714915105"></a>
    <table><thead align="left"><tr id="row1280518971010"><th class="cellrowborder" valign="top" width="27.24%" id="mcps1.1.4.1.1"><p id="p1380510912104"><a name="p1380510912104"></a><a name="p1380510912104"></a>Parameter</p>
    </th>
    <th class="cellrowborder" valign="top" width="30.330000000000002%" id="mcps1.1.4.1.2"><p id="p08051291106"><a name="p08051291106"></a><a name="p08051291106"></a>Description</p>
    </th>
    <th class="cellrowborder" valign="top" width="42.43%" id="mcps1.1.4.1.3"><p id="p12805149151012"><a name="p12805149151012"></a><a name="p12805149151012"></a>Value</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row168052913104"><td class="cellrowborder" valign="top" width="27.24%" headers="mcps1.1.4.1.1 "><p id="p180618915101"><a name="p180618915101"></a><a name="p180618915101"></a>LOSCFG_DEBUG_HOOK</p>
    </td>
    <td class="cellrowborder" valign="top" width="30.330000000000002%" headers="mcps1.1.4.1.2 "><p id="p198061196105"><a name="p198061196105"></a><a name="p198061196105"></a>Setting of the trace function</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.43%" headers="mcps1.1.4.1.3 "><p id="p1980609121010"><a name="p1980609121010"></a><a name="p1980609121010"></a><strong id="b263016731715"><a name="b263016731715"></a><a name="b263016731715"></a>0</strong>: disable; <strong id="b632420116171"><a name="b632420116171"></a><a name="b632420116171"></a>1</strong>: enable</p>
    </td>
    </tr>
    </tbody>
    </table>

2.  Select the hooks for registering callback functions. For details about the hook types, see  **liteos\_m/utils/internal/los\_hook\_types.h**.
3.  Call  **LOS\_HookReg**  to register functions.

### Development Example<a name="section0403134913395"></a>

This example invokes the malloc and free APIs to allocate and release memory of different sizes and records the malloc and free behavior and time sequence.

### Sample Code<a name="section1492711418400"></a>

The sample code is as follows:

```
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "los_hook.h"

#define SIZE_512        512
#define SIZE_1K         1024
#define SIZE_2K         2048

/* Print the size of malloc when the callback function is invoked. */
void MallocRecord(void *pool, unsigned int size)
{
    printf("malloc size = %u\n", size);
    return;
}

/* Print the free pointer address when the callback function is invoked. */
void FreeRecord(void *pool, void *ptr)
{
    printf("free pool = 0x%x ptr = 0x%x\n", pool, ptr);
    return;
}

void TestTrace(void)
{
    char *pool1 = NULL;
    char *pool2 = NULL;
    char *pool3 = NULL;
    char *retptr = NULL;
    /* Allocate memory of different sizes to pool1, pool2, and pool3. */
    pool1 = (char *)malloc(SIZE_512);
    if (pool1 == NULL) {
        printf("pool1 malloc failed!\n");
        return;
    }
    retptr = memset(pool1, 'a', SIZE_512);
    if (retptr == NULL) {
        printf("pool1 memset failed!\n");
        return;
    }
    printf("pool1 addr = 0x%x *pool1[0] = %c\n", pool1, *pool1);

    pool2 = (char *)malloc(SIZE_1K);
    if (pool2 == NULL) {
        printf("pool2 malloc failed!\n");
        return;
    }
    retptr = memset(pool2, 'b', SIZE_1K);
    if (retptr == NULL) {
        printf("pool2 memset failed!\n");
        return;
    }
    printf("pool2 addr = 0x%x *pool2[0] = %c\n", pool2, *pool2);

    pool3 = (char *)malloc(SIZE_2K);
    if (pool3 == NULL) {
        printf("pool3 malloc failed!\n");
        return;
    }
    retptr = memset(pool3, 'c', SIZE_2K);
    if (retptr == NULL) {
        printf("pool3 memset failed!\n");
        return;
    }
    printf("pool3 addr = 0x%x *pool3[0] = %c\n", pool3, *pool3);

    /* Release pool3, pool1, and pool2 in sequence to check the time sequence of the callback functions. */
    free(pool3);
    free(pool1);
    free(pool2);

    return;
}
/* Before the trace module is used, callback functions are registered. Note that the return value of the callback functions is void. */
void InitTest(void)
{
    printf("init hook\n");
    /* Register the hook based on the trace information to be obtained. For details about the hook types, see liteos_m/utils/internal/los_hook_types.h. */.
    LOS_HookReg(LOS_HOOK_TYPE_MEM_ALLOC, MallocRecord);
    LOS_HookReg(LOS_HOOK_TYPE_MEM_FREE, FreeRecord);
    return;
}
```

### Verification<a name="section869613984012"></a>

The output is as follows:

```
init hook
malloc size = 512
pool1 addr = 0x20002f44 *pool1[0] = a
malloc size = 1024
pool2 addr = 0x2000314c *pool2[0] = b
malloc size = 2048
pool3 addr = 0x20003554 *pool3[0] = c
free pool = 0x200002a4 ptr = 0x20003554
free pool = 0x200002a4 ptr = 0x20002f44
free pool = 0x200002a4 ptr = 0x2000314c
```

According to the address information, the sequence of free is pool3, pool1, and pool2.

