# Development Guidelines<a name="EN-US_TOPIC_0000001182409801"></a>

## Available APIs<a name="section158501652121514"></a>

**Table  1**  Functions

<a name="table18293928155615"></a>
<table><thead align="left"><tr id="row129362875613"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p19444103765618"><a name="p19444103765618"></a><a name="p19444103765618"></a>Category</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="p944473716569"><a name="p944473716569"></a><a name="p944473716569"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p144445378565"><a name="p144445378565"></a><a name="p144445378565"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row16964173231"><td class="cellrowborder" rowspan="4" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p106040172412"><a name="p106040172412"></a><a name="p106040172412"></a>Dynamic loading</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p136961178237"><a name="p136961178237"></a><a name="p136961178237"></a>LOS_DynlinkInit</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p3697131710237"><a name="p3697131710237"></a><a name="p3697131710237"></a>Initializes the dynamic linker linked list and mutex.</p>
</td>
</tr>
<tr id="row18697201714231"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p66971817102319"><a name="p66971817102319"></a><a name="p66971817102319"></a>LOS_SoLoad</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1569711715233"><a name="p1569711715233"></a><a name="p1569711715233"></a>Loads the shared library in a specified path.</p>
</td>
</tr>
<tr id="row18697117132313"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1697161732312"><a name="p1697161732312"></a><a name="p1697161732312"></a>LOS_FindSym</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p5697917132313"><a name="p5697917132313"></a><a name="p5697917132313"></a>Searches for the specified symbol based on the shared library handle.</p>
</td>
</tr>
<tr id="row1925202662319"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p7925526112315"><a name="p7925526112315"></a><a name="p7925526112315"></a>LOS_SoUnload</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p492520269233"><a name="p492520269233"></a><a name="p492520269233"></a>Unloads the shared library handle.</p>
</td>
</tr>
</tbody>
</table>

## How to Develop<a name="section5241132917523"></a>

1.  Use the arm-none-eabi-gcc cross compiler to compile the shared library and build a FAT or LittleFS image, and burn the image to the flash memory.
2.  In the  **target\_config.h**  file, set  **LOSCFG\_DYNLINK**  to  **1**  to enable the dynamic loading module.
3.  Call  **LOS\_SoLoad**  to load the shared library in the specified path.
4.  Call  **LOS\_FindSym**  to search for the specified symbol and obtain the symbol address.
5.  Call  **LOS\_SoUnload**  to unload the handle of the specified shared library.

>![](../public_sys-resources/icon-note.gif) **NOTE:** 
>1.  For details about the compilation options required for compiling the shared library using the cross compiler, see the ELF specifications.
>2.  Before creating a file system image, you need to adapt the FAT or LittleFS to the specific board.
>3.  The shared library does not depend on the libc library in the compiler and does not support C++.
>4.  The shared library depends only on the APIs provided by the kernel and cannot depend on other shared libraries.

## Development Example<a name="section8708112313531"></a>

The following uses the Arm Cortex-M4 board as an example.

1.  Sample Code and Compilation of the Shared Library

    The sample code is used to test the calling of global symbols and calling of the kernel APIs  **malloc**,  **free**, and  **memset**.

    ```
    #include <stdlib.h>
    #include <string.h>
    
    int g_param = 10;
    
    int callee(int a, int b)
    {
        char *addr = malloc(g_param);
        if (addr == NULL) {
            return 0;
        }
    
        memset(addr, '1', g_param);
    
        free(addr);
        return a + b + g_param;
    }
    
    int caller(int a, int b)
    {
        return callee(a, b);
    }
    ```

    ```
    $ arm-none-eabi-gcc -fPIC -shared -mcpu=cortex-m4 -nostdlib -nostartfiles -z max-page-size=4 -o test.so test.c
    ```

2.  Export the malloc, free, and memset symbols used in the shared library. Compile the following code into a .c file and use it for OS compilation.

    ```
    #include "stdlib.h"
    #include "string.h"
    
    SYM_EXPORT(malloc);
    SYM_EXPORT(free);
    SYM_EXPORT(memset);
    ```

3.  Determine the kernel compilation environment and add the following statement to the linking script of the compiler to ensure that the symbol table information is output to the specified section during compilation and linking.

    Add the following statement to the  **.icf**  linking script of the IAR compiler:

    ```
    keep {section .TABLE.START};
    keep {section .sym.*};
    keep {section .table.end};
    define block SYMBOL_TABLE with fixed order
    {
        section .TABLE.START,
        section .sym.*,
        section .table.end
    };
    place in ROM_region {readonly, block SYMBOL_TABLE};
    ```

    Add the following statement to the  **.ld**  linking script of the GCC compiler:

    ```
    __sym_table_start = .;
    KEEP(*( SORT (.sym.*)));
    __sym_table_end = .;
    ```

4.  Load, link, execute, and unload the shared library.

    The sample code is used to test whether the functions of the  **LOS\_SoLoad**,  **LOS\_FindSym**, and  **LOS\_SoUnload**  can be implemented normally and whether the symbols located by using  **LOS\_FindSym**  can be properly called.

    ```
    #include "los_dynlink.h"
    
    VOID DynlinkTest(VOID)
    {
        VOID *handle = NULL;
        INT32 (*func)(INT32, INT32) = NULL;
        CHAR *symbolName = "caller";
        CHAR *dsoName = "/lib/test.so";
        INT32 ret;
    
        handle = (VOID *)LOS_SoLoad(dsoName, NULL);
        if (handle == NULL) {
            printf("Failed to load so\n");
            return;
        }
    
        func = (INT32 (*)(INT32, INT32))LOS_FindSym(handle, symbolName);
        if (func == NULL) {
            printf("Failed to find symbol\n");
            LOS_SoUnload(handle);
            return;
        }
    
        ret = func(1, 1);
        if (ret != 12) {
            printf("Failed to execute function\n");
            LOS_SoUnload(handle);
            return;
        }
    
        ret = LOS_SoUnload(handle);
        if (ret != 0) {
            printf("Failed to unload so\n");
        }
    	
    	
        printf("Success!\n");
    }
    ```

5.  Verification

    ```
    Success!
    ```


>![](../public_sys-resources/icon-note.gif) **NOTE:** 
>In this example, the file system path is  **/lib/test.so**.
>You can create a task and call  **DynlinkTest**  in the task to perform the test.

