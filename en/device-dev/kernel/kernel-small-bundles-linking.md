# Dynamic Loading and Linking

## Basic Concepts<a name="section208951139453"></a>

The OpenHarmony dynamic loading and linking mechanism includes a kernel loader and a dynamic linker. The kernel loader loads application programs and the dynamic linker. The dynamic linker loads the shared library on which the application programs depend, and performs symbol relocation for the application programs and shared libraries. Compared with static linking, dynamic linking is a mechanism for delaying the linking of applications and dynamic libraries to run time.

**Advantages of Dynamic Linking**

1.  Dynamic linking allows multiple applications to share code. The minimum loading unit is page. Dynamic linking saves disk and memory space than static linking.
2.  When a shared library is upgraded, the new shared library overwrites the earlier version \(the APIs of the shared library are downward compatible\). You do not need to re-link the shared library.
3.  The loading address can be randomized to prevent attacks and ensure security.

## Working Principles<a name="section14140155320511"></a>

**Figure  1**  Dynamic loading process<a name="fig1797764116422"></a>  
![](figures/dynamic-loading-process.png "dynamic-loading-process")

1.  The kernel maps the  **PT\_LOAD**  section in the ELF file of the application to the process space. For files of the ET\_EXEC type, fixed address mapping is performed based on  **p\_vaddr**  in the  **PT\_LOAD**  section. For files of the ET\_DYN type \(position-independent executable programs, obtained through the compile option  **-fPIE**\), the kernel selects the  **base**  address via  **mmap**  for mapping \(load\_addr = base + p\_vaddr\).
2.  If the application is statically linked \(static linking does not support the compile option  **-fPIE**\), after the stack information is set, the system redirects to the address specified by  **e\_entry**  in the ELF file of the application and runs the application. If the program is dynamically linked, the application ELF file contains the  **PT\_INTERP**  section, which stores the dynamic linker path information \(ET\_DYN type\). The dynamic linker of musl is a part of the  **libc-musl.so**. The entry of  **libc-musl.so**  is the entry of the dynamic linker. The kernel selects the  **base**  address for mapping via the  **mmap**  API, sets the stack information, redirects to the  **base + e\_entry**  \(entry of the dynamic linker\) address, and runs the dynamic linker.
3.  The dynamic linker bootstraps and searches for all shared libraries on which the application depends, relocates the imported symbols, and finally redirects to the  **e\_entry**  \(or  **base + e\_entry**\) of the application to run the application.

**Figure  2**  Program execution process<a name="fig17879151310447"></a>  
![](figures/program-execution-process.png "program-execution-process")

1.  The loader and linker call  **mmap**  to map the  **PT\_LOAD**  section.
2.  The kernel calls  **map\_pages**  to search for and map the existing PageCache.
3.  If there is no physical memory for mapping in the virtual memory region during program execution, the system triggers a page missing interrupt, which allows the ELF file to be read into the physical memory and adds the memory block to the pagecache.
4.  Map the physical memory blocks of the file read to the virtual address region.
5.  The program continues to run.

## Development Guidelines<a name="section133501496612"></a>

### Available APIs<a name="section874113201669"></a>

**Table  1**  APIs of the kernel loader module

<a name="table1415203765610"></a>
<table><thead align="left"><tr id="row134151837125611"><th class="cellrowborder" valign="top" width="12.85128512851285%" id="mcps1.2.4.1.1"><p id="p16415637105612"><a name="p16415637105612"></a><a name="p16415637105612"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="29.8029802980298%" id="mcps1.2.4.1.2"><p id="p11415163718562"><a name="p11415163718562"></a><a name="p11415163718562"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="57.34573457345735%" id="mcps1.2.4.1.3"><p id="p1641533755612"><a name="p1641533755612"></a><a name="p1641533755612"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row0415737175610"><td class="cellrowborder" valign="top" width="12.85128512851285%" headers="mcps1.2.4.1.1 "><p id="p8866127195914"><a name="p8866127195914"></a><a name="p8866127195914"></a>Module initialization</p>
</td>
<td class="cellrowborder" valign="top" width="29.8029802980298%" headers="mcps1.2.4.1.2 "><p id="p58621910185914"><a name="p58621910185914"></a><a name="p58621910185914"></a>LOS_DoExecveFile</p>
</td>
<td class="cellrowborder" valign="top" width="57.34573457345735%" headers="mcps1.2.4.1.3 "><p id="p48623102592"><a name="p48623102592"></a><a name="p48623102592"></a>Executes the specified user program based on the input parameters.</p>
</td>
</tr>
</tbody>
</table>

### How to Develop<a name="section196712561563"></a>

The kernel cannot directly call the  **LOS\_DoExecveFile**  API to start a new process. This API is generally called through the  **exec\(\)**  API to create a new process using the system call mechanism.

