# 开发指导<a name="ZH-CN_TOPIC_0000001182409801"></a>

-   [接口说明](#section158501652121514)
-   [开发流程](#section5241132917523)
-   [编程实例](#section8708112313531)

## 接口说明<a name="section158501652121514"></a>

**表 1**  功能列表

<a name="table18293928155615"></a>
<table><thead align="left"><tr id="row129362875613"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p19444103765618"><a name="p19444103765618"></a><a name="p19444103765618"></a>功能分类</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="p944473716569"><a name="p944473716569"></a><a name="p944473716569"></a>接口名</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p144445378565"><a name="p144445378565"></a><a name="p144445378565"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row16964173231"><td class="cellrowborder" rowspan="4" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p106040172412"><a name="p106040172412"></a><a name="p106040172412"></a>动态加载功能接口</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p136961178237"><a name="p136961178237"></a><a name="p136961178237"></a>LOS_DynlinkInit</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p3697131710237"><a name="p3697131710237"></a><a name="p3697131710237"></a>初始化动态链接器链表以及互斥锁</p>
</td>
</tr>
<tr id="row18697201714231"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p66971817102319"><a name="p66971817102319"></a><a name="p66971817102319"></a>LOS_SoLoad</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1569711715233"><a name="p1569711715233"></a><a name="p1569711715233"></a>加载指定路径的共享库</p>
</td>
</tr>
<tr id="row18697117132313"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1697161732312"><a name="p1697161732312"></a><a name="p1697161732312"></a>LOS_FindSym</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p5697917132313"><a name="p5697917132313"></a><a name="p5697917132313"></a>根据共享库句柄查找指定符号</p>
</td>
</tr>
<tr id="row1925202662319"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p7925526112315"><a name="p7925526112315"></a><a name="p7925526112315"></a>LOS_SoUnload</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p492520269233"><a name="p492520269233"></a><a name="p492520269233"></a>卸载共享库句柄</p>
</td>
</tr>
</tbody>
</table>

## 开发流程<a name="section5241132917523"></a>

1.  利用arm-none-eabi-gcc交叉编译器编译共享库并制作FAT或LittleFS文件系统格式镜像烧写至flash中；
2.  在target\_config.h文件中定义宏LOSCFG\_DYNLINK为1使能动态加载模块；
3.  调用LOS\_SoLoad接口加载指定路径下的共享库；
4.  调用LOS\_FindSym接口查找指定符号，获取符号地址；
5.  调用LOS\_SoUnload卸载指定共享库句柄。

>![](../public_sys-resources/icon-note.gif) **说明：** 
>1.  利用交叉编译器编译共享库所需要的编译选项参考ELF支持规格一节。
>2.  制作文件系统镜像之前需要对特定单板适配FAT或LittleFS文件系统。
>3.  共享库不依赖编译器中的libc库，不支持c++。
>4.  共享库只能依赖内核提供的接口，不能依赖其他共享库。

## 编程实例<a name="section8708112313531"></a>

实例以cortex-m4单板为例。

1.  共享库示例代码及编译

    示例代码主要测试全局符号间的调用功能以及对内核接口maloc、free、memset接口的调用功能。

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

2.  导出共享库中使用到的malloc、free、memset符号，下述代码单独编写成一个.c文件，参与OS编译即可。

    ```
    #include "stdlib.h"
    #include "string.h"
    
    SYM_EXPORT(malloc);
    SYM_EXPORT(free);
    SYM_EXPORT(memset);
    ```

3.  确定内核的编译环境，在对应编译器的编译链接脚本中添加如下语句，保证符号表信息在编译链接的时候输出到指定的段。

    在IAR编译器.icf链接脚本中添加如下语句：

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

    在gcc编译器的.ld链接脚本中添加如下语句：

    ```
    __sym_table_start = .;
    KEEP(*( SORT (.sym.*)));
    __sym_table_end = .;
    ```

4.  共享库加载链接、执行与卸载

    示例代码主要测试LOS\_SoLoad、LOS\_FindSym、LOS\_SoUnload接口的功能是否正常以及通过LOS\_FindSym查找到的符号的调用是否正常。

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

5.  结果验证

    ```
    Success!
    ```


>![](../public_sys-resources/icon-note.gif) **说明：** 
>用例中文件系统路径为/lib/test.so；
>可以创建一个任务，在任务中调用DynlinkTest接口进行测试；

