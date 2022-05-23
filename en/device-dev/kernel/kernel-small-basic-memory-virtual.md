# Virtual Memory Management


## Basic Concepts<a name="section650193717411"></a>

Virtual memory management is a technology used by computer systems to manage memory. Each process has a continuous virtual address space. The size of the virtual address space is determined by the number of CPU bits. The maximum addressing space for a 32-bit hardware platform ranges from 0 GiB to 4 GiB. The 4 GiB space is divided into two parts: 3 GiB higher-address space for the LiteOS-A kernel and 1 GiB lower-address space for user-mode processes. The virtual address space of each process space is independent, and the code and data do not affect each other.

The system divides the virtual memory into memory blocks called virtual pages. The size of a virtual page is generally 4 KiB or 64 KiB. The virtual page of the LiteOS-A kernel is 4 KiB by default. You can configure memory management units \(MMUs\) as required. The minimum unit of the virtual memory management is a page. A virtual address region in the LiteOS-A kernel can contain one virtual page or multiple virtual pages with contiguous addresses. Similarly, the physical memory is also divided by page, and each memory block is called page frame. The virtual address space is divided as follows: 3 GiB \(**0x40000000**  to  **0xFFFFFFFF**\) for the kernel space and 1 GiB \(**0x01000000**  to  **0x3F000000**\) for the user space. The following tables describe the virtual address plan. You can view or configure virtual addresses in  **los\_vm\_zone.h**.

**Table  1**  Kernel-mode addresses

<a name="table9988174163613"></a>
<table><thead align="left"><tr id="row164675173616"><th class="cellrowborder" valign="top" width="19.99%" id="mcps1.2.4.1.1"><p id="p046752361"><a name="p046752361"></a><a name="p046752361"></a>Zone</p>
</th>
<th class="cellrowborder" valign="top" width="43.13%" id="mcps1.2.4.1.2"><p id="p0461651361"><a name="p0461651361"></a><a name="p0461651361"></a>Description</p>
</th>
<th class="cellrowborder" valign="top" width="36.88%" id="mcps1.2.4.1.3"><p id="p446195183611"><a name="p446195183611"></a><a name="p446195183611"></a>Property</p>
</th>
</tr>
</thead>
<tbody><tr id="row94619516367"><td class="cellrowborder" valign="top" width="19.99%" headers="mcps1.2.4.1.1 "><p id="p1846553363"><a name="p1846553363"></a><a name="p1846553363"></a>DMA zone</p>
</td>
<td class="cellrowborder" valign="top" width="43.13%" headers="mcps1.2.4.1.2 "><p id="p3461158364"><a name="p3461158364"></a><a name="p3461158364"></a>Addresses for direct memory access (DMA) of I/O devices.</p>
</td>
<td class="cellrowborder" valign="top" width="36.88%" headers="mcps1.2.4.1.3 "><p id="p10461152363"><a name="p10461152363"></a><a name="p10461152363"></a>Uncache</p>
</td>
</tr>
<tr id="row246551361"><td class="cellrowborder" valign="top" width="19.99%" headers="mcps1.2.4.1.1 "><p id="p3461259362"><a name="p3461259362"></a><a name="p3461259362"></a>Normal zone</p>
</td>
<td class="cellrowborder" valign="top" width="43.13%" headers="mcps1.2.4.1.2 "><p id="p1546056362"><a name="p1546056362"></a><a name="p1546056362"></a>Addresses for loading the kernel code segment, data segment, heap, and stack.</p>
</td>
<td class="cellrowborder" valign="top" width="36.88%" headers="mcps1.2.4.1.3 "><p id="p646125143613"><a name="p646125143613"></a><a name="p646125143613"></a>Cache</p>
</td>
</tr>
<tr id="row646165133613"><td class="cellrowborder" valign="top" width="19.99%" headers="mcps1.2.4.1.1 "><p id="p114675183615"><a name="p114675183615"></a><a name="p114675183615"></a>high mem zone</p>
</td>
<td class="cellrowborder" valign="top" width="43.13%" headers="mcps1.2.4.1.2 "><p id="p194611583613"><a name="p194611583613"></a><a name="p194611583613"></a>Addresses for allocating contiguous virtual memory. The mapped physical memory blocks may not be contiguous.</p>
</td>
<td class="cellrowborder" valign="top" width="36.88%" headers="mcps1.2.4.1.3 "><p id="p8461153369"><a name="p8461153369"></a><a name="p8461153369"></a>Cache</p>
</td>
</tr>
</tbody>
</table>

**Table  2**  User-mode virtual addresses

<a name="table19965411366"></a>
<table><thead align="left"><tr id="row646185183618"><th class="cellrowborder" valign="top" width="20%" id="mcps1.2.4.1.1"><p id="p3466593612"><a name="p3466593612"></a><a name="p3466593612"></a>Zone</p>
</th>
<th class="cellrowborder" valign="top" width="43.120000000000005%" id="mcps1.2.4.1.2"><p id="p84645143613"><a name="p84645143613"></a><a name="p84645143613"></a>Description</p>
</th>
<th class="cellrowborder" valign="top" width="36.88%" id="mcps1.2.4.1.3"><p id="p1146115203615"><a name="p1146115203615"></a><a name="p1146115203615"></a>Property</p>
</th>
</tr>
</thead>
<tbody><tr id="row7462511363"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.4.1.1 "><p id="p2467516363"><a name="p2467516363"></a><a name="p2467516363"></a>Code segment</p>
</td>
<td class="cellrowborder" valign="top" width="43.120000000000005%" headers="mcps1.2.4.1.2 "><p id="p7472523618"><a name="p7472523618"></a><a name="p7472523618"></a>User-mode code segment address range</p>
</td>
<td class="cellrowborder" valign="top" width="36.88%" headers="mcps1.2.4.1.3 "><p id="p14476563611"><a name="p14476563611"></a><a name="p14476563611"></a>Cache</p>
</td>
</tr>
<tr id="row34755153614"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.4.1.1 "><p id="p194735173612"><a name="p194735173612"></a><a name="p194735173612"></a>Heap</p>
</td>
<td class="cellrowborder" valign="top" width="43.120000000000005%" headers="mcps1.2.4.1.2 "><p id="p114720518362"><a name="p114720518362"></a><a name="p114720518362"></a>User-mode heap address range</p>
</td>
<td class="cellrowborder" valign="top" width="36.88%" headers="mcps1.2.4.1.3 "><p id="p9474515364"><a name="p9474515364"></a><a name="p9474515364"></a>Cache</p>
</td>
</tr>
<tr id="row9476518368"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.4.1.1 "><p id="p34714516369"><a name="p34714516369"></a><a name="p34714516369"></a>Stack</p>
</td>
<td class="cellrowborder" valign="top" width="43.120000000000005%" headers="mcps1.2.4.1.2 "><p id="p74705163612"><a name="p74705163612"></a><a name="p74705163612"></a>User-mode stack address range</p>
</td>
<td class="cellrowborder" valign="top" width="36.88%" headers="mcps1.2.4.1.3 "><p id="p144775143613"><a name="p144775143613"></a><a name="p144775143613"></a>Cache</p>
</td>
</tr>
<tr id="row1047353364"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.4.1.1 "><p id="p1947145163615"><a name="p1947145163615"></a><a name="p1947145163615"></a>Shared library</p>
</td>
<td class="cellrowborder" valign="top" width="43.120000000000005%" headers="mcps1.2.4.1.2 "><p id="p24745193617"><a name="p24745193617"></a><a name="p24745193617"></a>Address range for loading the user-mode shared library, including the address range mapped by mmap.</p>
</td>
<td class="cellrowborder" valign="top" width="36.88%" headers="mcps1.2.4.1.3 "><p id="p11472510363"><a name="p11472510363"></a><a name="p11472510363"></a>Cache</p>
</td>
</tr>
</tbody>
</table>

## Working Principles<a name="section072885512412"></a>

In virtual memory management, the virtual address space is contiguous, but the mapped physical memory is not necessarily contiguous, as depicted in the following figure. When an executable program is loaded and runs, the CPU accesses the code or data in the virtual address space in the following two cases:

-   If the page \(for example, V0\) containing the virtual address accessed by the CPU is mapped to a physical page \(for example, P0\), the CPU locates the page table entry corresponding to the process \(for details, see  [Virtual-to-Physical Mapping](kernel-small-basic-inner-reflect.md)"\), accesses the physical memory based on the physical address information in the page table entry, and returns the content.
-   If the page \(for example, V2\) containing the virtual address accessed by the CPU is not mapped to a physical page, the system triggers a page missing fault, requests a physical page, copies the corresponding information to the physical page, and updates the start address of the physical page to the page table entry. Then, the CPU can access specific code or data by executing the instruction for accessing the virtual memory again.

**Figure  1**  Mapping between the virtual and physical memory addresses<a name="fig144371159135620"></a>  
![](figures/mapping-between-the-virtual-and-physical-memory-addresses.png "mapping-between-the-virtual-and-physical-memory-addresses")

## Development Guidelines<a name="section20956116050"></a>

### Available APIs<a name="section166137221657"></a>

**Table  3**  APIs of the virtual memory management module

<a name="table1415203765610"></a>
<table><thead align="left"><tr id="row134151837125611"><th class="cellrowborder" valign="top" width="12.811281128112812%" id="mcps1.2.4.1.1"><p id="p16415637105612"><a name="p16415637105612"></a><a name="p16415637105612"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="29.84298429842984%" id="mcps1.2.4.1.2"><p id="p11415163718562"><a name="p11415163718562"></a><a name="p11415163718562"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="57.34573457345735%" id="mcps1.2.4.1.3"><p id="p1641533755612"><a name="p1641533755612"></a><a name="p1641533755612"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row0415737175610"><td class="cellrowborder" rowspan="5" valign="top" width="12.811281128112812%" headers="mcps1.2.4.1.1 "><p id="p4917132105710"><a name="p4917132105710"></a><a name="p4917132105710"></a>Obtaining process memory space</p>
</td>
<td class="cellrowborder" valign="top" width="29.84298429842984%" headers="mcps1.2.4.1.2 "><p id="p341513372561"><a name="p341513372561"></a><a name="p341513372561"></a>LOS_CurrSpaceGet</p>
</td>
<td class="cellrowborder" valign="top" width="57.34573457345735%" headers="mcps1.2.4.1.3 "><p id="p74151037185617"><a name="p74151037185617"></a><a name="p74151037185617"></a>Obtains the pointer to the current process space structure.</p>
</td>
</tr>
<tr id="row1841519376561"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p64151837155618"><a name="p64151837155618"></a><a name="p64151837155618"></a>LOS_SpaceGet</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p441516379562"><a name="p441516379562"></a><a name="p441516379562"></a>Obtains the pointer to the process space structure corresponding to the virtual address.</p>
</td>
</tr>
<tr id="row536885134010"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p236819594010"><a name="p236819594010"></a><a name="p236819594010"></a>LOS_GetKVmSpace</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p736918564019"><a name="p736918564019"></a><a name="p736918564019"></a>Obtains the pointer to the kernel process space structure.</p>
</td>
</tr>
<tr id="row11567448194112"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p0568204814115"><a name="p0568204814115"></a><a name="p0568204814115"></a>LOS_GetVmallocSpace</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p05681348204114"><a name="p05681348204114"></a><a name="p05681348204114"></a>Obtains the pointer to the vmalloc space structure.</p>
</td>
</tr>
<tr id="row1141513373562"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p17765212416"><a name="p17765212416"></a><a name="p17765212416"></a>LOS_GetVmSpaceList</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1972971913115"><a name="p1972971913115"></a><a name="p1972971913115"></a>Obtains the pointer to the process space linked list.</p>
</td>
</tr>
<tr id="row137812054195014"><td class="cellrowborder" rowspan="15" valign="top" width="12.811281128112812%" headers="mcps1.2.4.1.1 "><p id="p15344719152113"><a name="p15344719152113"></a><a name="p15344719152113"></a>Operations related to the virtual address region</p>
</td>
<td class="cellrowborder" valign="top" width="29.84298429842984%" headers="mcps1.2.4.1.2 "><p id="p97821654195014"><a name="p97821654195014"></a><a name="p97821654195014"></a>LOS_RegionFind</p>
</td>
<td class="cellrowborder" valign="top" width="57.34573457345735%" headers="mcps1.2.4.1.3 "><p id="p137821854205011"><a name="p137821854205011"></a><a name="p137821854205011"></a>Searches for and returns the virtual address region corresponding to the specified address in the process space.</p>
</td>
</tr>
<tr id="row254713575505"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p954785720501"><a name="p954785720501"></a><a name="p954785720501"></a>LOS_RegionRangeFind</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p20547557175013"><a name="p20547557175013"></a><a name="p20547557175013"></a>Searches for and returns the virtual address region corresponding to the specified address range in the process space.</p>
</td>
</tr>
<tr id="row1692045119"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1510110115114"><a name="p1510110115114"></a><a name="p1510110115114"></a>LOS_IsRegionFileValid</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p61011045112"><a name="p61011045112"></a><a name="p61011045112"></a>Checks whether the virtual address region is mapped to a file.</p>
</td>
</tr>
<tr id="row186701424548"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1967018210546"><a name="p1967018210546"></a><a name="p1967018210546"></a>LOS_RegionAlloc</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p196701221548"><a name="p196701221548"></a><a name="p196701221548"></a>Requests a free virtual address region.</p>
</td>
</tr>
<tr id="row1955586175412"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p555626195420"><a name="p555626195420"></a><a name="p555626195420"></a>LOS_RegionFree</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p85568612547"><a name="p85568612547"></a><a name="p85568612547"></a>Releases a specific region in the process space.</p>
</td>
</tr>
<tr id="row259111510282"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p3591135110288"><a name="p3591135110288"></a><a name="p3591135110288"></a>LOS_RegionEndAddr</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p4675183817474"><a name="p4675183817474"></a><a name="p4675183817474"></a>Obtains the end address of the specified address region.</p>
</td>
</tr>
<tr id="row12894115716285"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p889418577280"><a name="p889418577280"></a><a name="p889418577280"></a>LOS_RegionSize</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p68941757112813"><a name="p68941757112813"></a><a name="p68941757112813"></a>Obtains the size of a region.</p>
</td>
</tr>
<tr id="row14931456182812"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1293135611287"><a name="p1293135611287"></a><a name="p1293135611287"></a>LOS_IsRegionTypeFile</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1393185613288"><a name="p1393185613288"></a><a name="p1393185613288"></a>Checks whether the address region is a file memory mapping.</p>
</td>
</tr>
<tr id="row12153854132814"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p115335452819"><a name="p115335452819"></a><a name="p115335452819"></a>LOS_IsRegionPermUserReadOnly</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1415314545285"><a name="p1415314545285"></a><a name="p1415314545285"></a>Checks whether the address region is read-only in the user space.</p>
</td>
</tr>
<tr id="row29249497282"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1492415495284"><a name="p1492415495284"></a><a name="p1492415495284"></a>LOS_IsRegionFlagPrivateOnly</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1392434982817"><a name="p1392434982817"></a><a name="p1392434982817"></a>Checks whether the address region has private attributes.</p>
</td>
</tr>
<tr id="row1233194042814"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p3339401289"><a name="p3339401289"></a><a name="p3339401289"></a>LOS_SetRegionTypeFile</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p193317409285"><a name="p193317409285"></a><a name="p193317409285"></a>Sets the file memory mapping attribute.</p>
</td>
</tr>
<tr id="row178971473283"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p4898184782815"><a name="p4898184782815"></a><a name="p4898184782815"></a>LOS_IsRegionTypeDev</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p11898144722818"><a name="p11898144722818"></a><a name="p11898144722818"></a>Checks whether the address region is device memory mapping.</p>
</td>
</tr>
<tr id="row11137546152811"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p20137194672812"><a name="p20137194672812"></a><a name="p20137194672812"></a>LOS_SetRegionTypeDev</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p81384462287"><a name="p81384462287"></a><a name="p81384462287"></a>Sets the device memory mapping attribute. </p>
</td>
</tr>
<tr id="row1023564216285"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p92351842162819"><a name="p92351842162819"></a><a name="p92351842162819"></a>LOS_IsRegionTypeAnon</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p6235842132818"><a name="p6235842132818"></a><a name="p6235842132818"></a>Checks whether the address region is an anonymous mapping.</p>
</td>
</tr>
<tr id="row1646364402813"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p44631644152814"><a name="p44631644152814"></a><a name="p44631644152814"></a>LOS_SetRegionTypeAnon</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p174631844182818"><a name="p174631844182818"></a><a name="p174631844182818"></a>Sets the anonymous mapping attribute. </p>
</td>
</tr>
<tr id="row038233717288"><td class="cellrowborder" rowspan="5" valign="top" width="12.811281128112812%" headers="mcps1.2.4.1.1 "><p id="p6820331185317"><a name="p6820331185317"></a><a name="p6820331185317"></a>Verifying address</p>
</td>
<td class="cellrowborder" valign="top" width="29.84298429842984%" headers="mcps1.2.4.1.2 "><p id="p838383720282"><a name="p838383720282"></a><a name="p838383720282"></a>LOS_IsUserAddress</p>
</td>
<td class="cellrowborder" valign="top" width="57.34573457345735%" headers="mcps1.2.4.1.3 "><p id="p12383837102818"><a name="p12383837102818"></a><a name="p12383837102818"></a>Checks whether the address is in the user space.</p>
</td>
</tr>
<tr id="row61506354284"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p2151113517288"><a name="p2151113517288"></a><a name="p2151113517288"></a>LOS_IsUserAddressRange</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p615123552814"><a name="p615123552814"></a><a name="p615123552814"></a>Checks whether the address region is in the user space.</p>
</td>
</tr>
<tr id="row18301515194210"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p19301141519421"><a name="p19301141519421"></a><a name="p19301141519421"></a>LOS_IsKernelAddress</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p730110154427"><a name="p730110154427"></a><a name="p730110154427"></a>Checks whether the address is in the kernel space.</p>
</td>
</tr>
<tr id="row191211718204213"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1112121812423"><a name="p1112121812423"></a><a name="p1112121812423"></a>LOS_IsKernelAddressRange</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p6122101814219"><a name="p6122101814219"></a><a name="p6122101814219"></a>Checks whether the address region is in the kernel space.</p>
</td>
</tr>
<tr id="row774964092115"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p17152102415416"><a name="p17152102415416"></a><a name="p17152102415416"></a>LOS_IsRangeInSpace</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p115218248547"><a name="p115218248547"></a><a name="p115218248547"></a>Checks whether the address region is in the process space.</p>
</td>
</tr>
<tr id="row179196525521"><td class="cellrowborder" rowspan="3" valign="top" width="12.811281128112812%" headers="mcps1.2.4.1.1 "><p id="p153501191535"><a name="p153501191535"></a><a name="p153501191535"></a>vmalloc operations</p>
</td>
<td class="cellrowborder" valign="top" width="29.84298429842984%" headers="mcps1.2.4.1.2 "><p id="p152945155531"><a name="p152945155531"></a><a name="p152945155531"></a>LOS_VMalloc</p>
</td>
<td class="cellrowborder" valign="top" width="57.34573457345735%" headers="mcps1.2.4.1.3 "><p id="p1229461512535"><a name="p1229461512535"></a><a name="p1229461512535"></a>Requests memory using <strong id="b2981120154115"><a name="b2981120154115"></a><a name="b2981120154115"></a>vmalloc</strong>.</p>
</td>
</tr>
<tr id="row1934135935211"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p162941115155315"><a name="p162941115155315"></a><a name="p162941115155315"></a>LOS_VFree</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p12294171516536"><a name="p12294171516536"></a><a name="p12294171516536"></a>Releases memory using <strong id="b1911793812416"><a name="b1911793812416"></a><a name="b1911793812416"></a>vmalloc</strong>.</p>
</td>
</tr>
<tr id="row944214919304"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p644229163016"><a name="p644229163016"></a><a name="p644229163016"></a>LOS_IsVmallocAddress</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1344220993011"><a name="p1344220993011"></a><a name="p1344220993011"></a>Checks whether the address is requested by using <strong id="b11623210425"><a name="b11623210425"></a><a name="b11623210425"></a>vmalloc</strong>.</p>
</td>
</tr>
<tr id="row72131845145315"><td class="cellrowborder" rowspan="4" valign="top" width="12.811281128112812%" headers="mcps1.2.4.1.1 "><p id="p84847816543"><a name="p84847816543"></a><a name="p84847816543"></a>Requesting memory</p>
</td>
<td class="cellrowborder" valign="top" width="29.84298429842984%" headers="mcps1.2.4.1.2 "><p id="p8787345546"><a name="p8787345546"></a><a name="p8787345546"></a>LOS_KernelMalloc</p>
</td>
<td class="cellrowborder" valign="top" width="57.34573457345735%" headers="mcps1.2.4.1.3 "><p id="p17787444543"><a name="p17787444543"></a><a name="p17787444543"></a>Allocates memory from the heap memory pool if the requested memory is less than 16 KiB; allocates multiple contiguous physical pages for memory allocation if the requested memory is greater than 16 KiB.</p>
</td>
</tr>
<tr id="row48491549145311"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p14787149541"><a name="p14787149541"></a><a name="p14787149541"></a>LOS_KernelMallocAlign</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p478719411543"><a name="p478719411543"></a><a name="p478719411543"></a>Allocates memory with alignment attributes. The allocation rule is the same as that of the <strong id="b13365164915813"><a name="b13365164915813"></a><a name="b13365164915813"></a>LOS_KernelMalloc</strong> API.</p>
</td>
</tr>
<tr id="row151093538536"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p15787134185412"><a name="p15787134185412"></a><a name="p15787134185412"></a>LOS_KernelFree</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p878712410546"><a name="p878712410546"></a><a name="p878712410546"></a>Releases the memory requested by <strong id="b426742412595"><a name="b426742412595"></a><a name="b426742412595"></a>LOS_KernelMalloc</strong> and <strong id="b20812228205916"><a name="b20812228205916"></a><a name="b20812228205916"></a>LOS_KernelMallocAlign</strong>.</p>
</td>
</tr>
<tr id="row5126856205319"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p197871646545"><a name="p197871646545"></a><a name="p197871646545"></a>LOS_KernelRealloc</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p378813416547"><a name="p378813416547"></a><a name="p378813416547"></a>Reallocates the memory requested by <strong id="b161871016807"><a name="b161871016807"></a><a name="b161871016807"></a>LOS_KernelMalloc</strong> and <strong id="b1368514211001"><a name="b1368514211001"></a><a name="b1368514211001"></a>LOS_KernelMallocAlign</strong>.</p>
</td>
</tr>
<tr id="row12397132718549"><td class="cellrowborder" rowspan="4" valign="top" width="12.811281128112812%" headers="mcps1.2.4.1.1 "><p id="p112971954115419"><a name="p112971954115419"></a><a name="p112971954115419"></a>Others</p>
</td>
<td class="cellrowborder" valign="top" width="29.84298429842984%" headers="mcps1.2.4.1.2 "><p id="p2777034145414"><a name="p2777034145414"></a><a name="p2777034145414"></a>LOS_PaddrQuery</p>
</td>
<td class="cellrowborder" valign="top" width="57.34573457345735%" headers="mcps1.2.4.1.3 "><p id="p13777834115413"><a name="p13777834115413"></a><a name="p13777834115413"></a>Obtains the physical address based on the virtual address.</p>
</td>
</tr>
<tr id="row5558122119542"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p9558421155418"><a name="p9558421155418"></a><a name="p9558421155418"></a>LOS_VmSpaceFree</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p755852119545"><a name="p755852119545"></a><a name="p755852119545"></a>Releases the process space, including the virtual memory region and page table.</p>
</td>
</tr>
<tr id="row15860142919544"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p168603298547"><a name="p168603298547"></a><a name="p168603298547"></a>LOS_VmSpaceReserve</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p12860429185410"><a name="p12860429185410"></a><a name="p12860429185410"></a>Reserves a memory space in the process space.</p>
</td>
</tr>
<tr id="row394217543569"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p11943125419566"><a name="p11943125419566"></a><a name="p11943125419566"></a>LOS_VaddrToPaddrMmap</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p16943954105613"><a name="p16943954105613"></a><a name="p16943954105613"></a>Maps the physical address region with the specified length to a virtual address region. You need to request the physical address region before the operation.</p>
</td>
</tr>
</tbody>
</table>

### How to Develop<a name="section8752103914513"></a>

To use APIs related to virtual memory:

1.  Obtain the process space structure using the APIs for obtaining the process space, and access the structure information.
2.  Perform the following operations on the virtual address region:
    -   Call  **LOS\_RegionAlloc**  to request a virtual address region.

    -   Call  **LOS\_RegionFind**  and  **LOS\_RegionRangeFind**  to check whether the corresponding address region exists.
    -   Call  **LOS\_RegionFree**  to release a virtual address region.

3.  Call  **vmalloc**  and memory requesting APIs to apply for memory in the kernel as demanded.

>![](../public_sys-resources/icon-note.gif) **NOTE:** 
>The physical memory requested by using the memory requesting APIs must be contiguous. If the system cannot provide a large number of contiguous memory blocks, the request fails. Therefore, the memory requesting APIs are recommended for requesting small memory blocks.  **vmalloc**  is recommended for requesting non-contiguous physical memory. However, the memory is allocated in the unit of pages \(4096 bytes/page in the current system\). If you want memory that is an integer multiple of a page, you can use  **vmalloc**. For example, you can use  **vmalloc**  to request memory for file reading in a file system, which demands a large cache.

