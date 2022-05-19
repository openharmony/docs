# How to Use

By default, the OpenHarmony debug version is compiled when a project is built. The libc library of the debug version has integrated the APIs for memory debugging. You can enable memory debugging as required.

You can perform heap memory debugging by using either of the following:

-   API: By calling APIs, you can accurately check the heap memory information of a specific code logic segment. However, you have to modify user code.
-   CLI: By using the CLI, you do not need to modify user code. However, you cannot accurately check the heap memory information of a specific logic segment.

>![](../public_sys-resources/icon-note.gif) **NOTE**<br/> 
>After memory debugging is enabled, a heap memory leak check and a heap memory integrity check will be performed by default when a process exits. If memory debugging is disabled, the heap memory statistics, heap memory leak check, and heap memory integrity check cannot be enabled, and there is no response to the calling of any debug API.

-   **[Calling APIs](kernel-small-debug-user-guide-use-api.md)**  

-   **[Using the CLI](kernel-small-debug-user-guide-use-cli.md)**  


