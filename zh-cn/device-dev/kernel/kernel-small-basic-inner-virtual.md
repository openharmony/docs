# 虚拟内存管理<a name="ZH-CN_TOPIC_0000001123800847"></a>

-   [基本概念](#section650193717411)
-   [运行机制](#section072885512412)
-   [开发指导](#section20956116050)
    -   [接口说明](#section166137221657)
    -   [开发流程](#section8752103914513)


## 基本概念<a name="section650193717411"></a>

虚拟内存管理是计算机系统管理内存的一种技术。每个进程都有连续的虚拟地址空间，虚拟地址空间的大小由CPU的位数决定，32位的硬件平台可以提供的最大的寻址空间为0-4G。整个4G空间分成两部分，LiteOS-A内核占据3G的高地址空间，1G的低地址空间留给进程使用。各个进程空间的虚拟地址空间是独立的，代码、数据互不影响。

系统将虚拟内存分割为称为虚拟页的内存块，大小一般为4k或64k，LiteOS-A内核默认的页的大小是4k，根据需要可以对MMU（Memory Management Units）进行配置。虚拟内存管理操作的最小单位就是一个页，LiteOS-A内核中一个虚拟地址区间region包含地址连续的多个虚拟页，也可只有一个页。同样，物理内存也会按照页大小进行分割，分割后的每个内存块称为页帧。虚拟地址空间划分：内核态占高地址3G\(0x40000000 \~ 0xFFFFFFFF\)，用户态占低地址1G\(0x01000000 \~ 0x3F000000\)，具体见下表，详细可以查看或配置los\_vm\_zone.h。

**表 1**  内核态地址规划：

<a name="table9988174163613"></a>
<table><thead align="left"><tr id="row164675173616"><th class="cellrowborder" valign="top" width="11.761176117611761%" id="mcps1.2.6.1.1"><p id="p046752361"><a name="p046752361"></a><a name="p046752361"></a>Zone名称</p>
</th>
<th class="cellrowborder" valign="top" width="22.792279227922794%" id="mcps1.2.6.1.2"><p id="p746165113619"><a name="p746165113619"></a><a name="p746165113619"></a>起始地址</p>
</th>
<th class="cellrowborder" valign="top" width="18.381838183818385%" id="mcps1.2.6.1.3"><p id="p6461957362"><a name="p6461957362"></a><a name="p6461957362"></a>结束地址</p>
</th>
<th class="cellrowborder" valign="top" width="25.372537253725376%" id="mcps1.2.6.1.4"><p id="p0461651361"><a name="p0461651361"></a><a name="p0461651361"></a>用途</p>
</th>
<th class="cellrowborder" valign="top" width="21.692169216921695%" id="mcps1.2.6.1.5"><p id="p446195183611"><a name="p446195183611"></a><a name="p446195183611"></a>属性</p>
</th>
</tr>
</thead>
<tbody><tr id="row94619516367"><td class="cellrowborder" valign="top" width="11.761176117611761%" headers="mcps1.2.6.1.1 "><p id="p1846553363"><a name="p1846553363"></a><a name="p1846553363"></a>DMA zone</p>
</td>
<td class="cellrowborder" valign="top" width="22.792279227922794%" headers="mcps1.2.6.1.2 "><p id="p2463543619"><a name="p2463543619"></a><a name="p2463543619"></a>0x40000000</p>
</td>
<td class="cellrowborder" valign="top" width="18.381838183818385%" headers="mcps1.2.6.1.3 "><p id="p13461954361"><a name="p13461954361"></a><a name="p13461954361"></a>0x43FFFFFF</p>
</td>
<td class="cellrowborder" valign="top" width="25.372537253725376%" headers="mcps1.2.6.1.4 "><p id="p3461158364"><a name="p3461158364"></a><a name="p3461158364"></a>USB、网络等dma内存访问</p>
</td>
<td class="cellrowborder" valign="top" width="21.692169216921695%" headers="mcps1.2.6.1.5 "><p id="p10461152363"><a name="p10461152363"></a><a name="p10461152363"></a>Uncache</p>
</td>
</tr>
<tr id="row246551361"><td class="cellrowborder" valign="top" width="11.761176117611761%" headers="mcps1.2.6.1.1 "><p id="p3461259362"><a name="p3461259362"></a><a name="p3461259362"></a>Normal zone</p>
</td>
<td class="cellrowborder" valign="top" width="22.792279227922794%" headers="mcps1.2.6.1.2 "><p id="p746059367"><a name="p746059367"></a><a name="p746059367"></a>0x80000000</p>
</td>
<td class="cellrowborder" valign="top" width="18.381838183818385%" headers="mcps1.2.6.1.3 "><p id="p74615519368"><a name="p74615519368"></a><a name="p74615519368"></a>0x83FFFFFF</p>
</td>
<td class="cellrowborder" valign="top" width="25.372537253725376%" headers="mcps1.2.6.1.4 "><p id="p1546056362"><a name="p1546056362"></a><a name="p1546056362"></a>内核代码、数据段和堆内存和栈</p>
</td>
<td class="cellrowborder" valign="top" width="21.692169216921695%" headers="mcps1.2.6.1.5 "><p id="p646125143613"><a name="p646125143613"></a><a name="p646125143613"></a>Cache</p>
</td>
</tr>
<tr id="row646165133613"><td class="cellrowborder" valign="top" width="11.761176117611761%" headers="mcps1.2.6.1.1 "><p id="p114675183615"><a name="p114675183615"></a><a name="p114675183615"></a>high mem zone</p>
</td>
<td class="cellrowborder" valign="top" width="22.792279227922794%" headers="mcps1.2.6.1.2 "><p id="p13462058362"><a name="p13462058362"></a><a name="p13462058362"></a>0x84000000</p>
</td>
<td class="cellrowborder" valign="top" width="18.381838183818385%" headers="mcps1.2.6.1.3 "><p id="p64655183614"><a name="p64655183614"></a><a name="p64655183614"></a>0x8BFFFFFF</p>
</td>
<td class="cellrowborder" valign="top" width="25.372537253725376%" headers="mcps1.2.6.1.4 "><p id="p194611583613"><a name="p194611583613"></a><a name="p194611583613"></a>连续虚拟内存分配，物理内存不连续</p>
</td>
<td class="cellrowborder" valign="top" width="21.692169216921695%" headers="mcps1.2.6.1.5 "><p id="p8461153369"><a name="p8461153369"></a><a name="p8461153369"></a>Cache</p>
</td>
</tr>
</tbody>
</table>

**表 2**  用户态虚地址规划：

<a name="table19965411366"></a>
<table><thead align="left"><tr id="row646185183618"><th class="cellrowborder" valign="top" width="11.721172117211722%" id="mcps1.2.6.1.1"><p id="p3466593612"><a name="p3466593612"></a><a name="p3466593612"></a>Zone名称</p>
</th>
<th class="cellrowborder" valign="top" width="22.712271227122713%" id="mcps1.2.6.1.2"><p id="p164605153615"><a name="p164605153615"></a><a name="p164605153615"></a>起始地址</p>
</th>
<th class="cellrowborder" valign="top" width="18.681868186818683%" id="mcps1.2.6.1.3"><p id="p4464512361"><a name="p4464512361"></a><a name="p4464512361"></a>结束地址</p>
</th>
<th class="cellrowborder" valign="top" width="25.27252725272527%" id="mcps1.2.6.1.4"><p id="p84645143613"><a name="p84645143613"></a><a name="p84645143613"></a>用途</p>
</th>
<th class="cellrowborder" valign="top" width="21.61216121612161%" id="mcps1.2.6.1.5"><p id="p1146115203615"><a name="p1146115203615"></a><a name="p1146115203615"></a>属性</p>
</th>
</tr>
</thead>
<tbody><tr id="row7462511363"><td class="cellrowborder" valign="top" width="11.721172117211722%" headers="mcps1.2.6.1.1 "><p id="p2467516363"><a name="p2467516363"></a><a name="p2467516363"></a>代码段</p>
</td>
<td class="cellrowborder" valign="top" width="22.712271227122713%" headers="mcps1.2.6.1.2 "><p id="p747135163620"><a name="p747135163620"></a><a name="p747135163620"></a>0x0200000</p>
</td>
<td class="cellrowborder" valign="top" width="18.681868186818683%" headers="mcps1.2.6.1.3 "><p id="p647651366"><a name="p647651366"></a><a name="p647651366"></a>0x09FFFFFF</p>
</td>
<td class="cellrowborder" valign="top" width="25.27252725272527%" headers="mcps1.2.6.1.4 "><p id="p7472523618"><a name="p7472523618"></a><a name="p7472523618"></a>用户态代码段地址空间</p>
</td>
<td class="cellrowborder" valign="top" width="21.61216121612161%" headers="mcps1.2.6.1.5 "><p id="p14476563611"><a name="p14476563611"></a><a name="p14476563611"></a>Cache</p>
</td>
</tr>
<tr id="row34755153614"><td class="cellrowborder" valign="top" width="11.721172117211722%" headers="mcps1.2.6.1.1 "><p id="p194735173612"><a name="p194735173612"></a><a name="p194735173612"></a>堆</p>
</td>
<td class="cellrowborder" valign="top" width="22.712271227122713%" headers="mcps1.2.6.1.2 "><p id="p7474533616"><a name="p7474533616"></a><a name="p7474533616"></a>0x0FC00000(起始地址随机)</p>
</td>
<td class="cellrowborder" valign="top" width="18.681868186818683%" headers="mcps1.2.6.1.3 "><p id="p194717573615"><a name="p194717573615"></a><a name="p194717573615"></a>0x17BFFFFF</p>
</td>
<td class="cellrowborder" valign="top" width="25.27252725272527%" headers="mcps1.2.6.1.4 "><p id="p114720518362"><a name="p114720518362"></a><a name="p114720518362"></a>用户态堆地址空间</p>
</td>
<td class="cellrowborder" valign="top" width="21.61216121612161%" headers="mcps1.2.6.1.5 "><p id="p9474515364"><a name="p9474515364"></a><a name="p9474515364"></a>Cache</p>
</td>
</tr>
<tr id="row9476518368"><td class="cellrowborder" valign="top" width="11.721172117211722%" headers="mcps1.2.6.1.1 "><p id="p34714516369"><a name="p34714516369"></a><a name="p34714516369"></a>栈</p>
</td>
<td class="cellrowborder" valign="top" width="22.712271227122713%" headers="mcps1.2.6.1.2 "><p id="p134785173617"><a name="p134785173617"></a><a name="p134785173617"></a>0x37000000</p>
</td>
<td class="cellrowborder" valign="top" width="18.681868186818683%" headers="mcps1.2.6.1.3 "><p id="p20474510368"><a name="p20474510368"></a><a name="p20474510368"></a>0x3EFFFFFF(起始地址随机)</p>
</td>
<td class="cellrowborder" valign="top" width="25.27252725272527%" headers="mcps1.2.6.1.4 "><p id="p74705163612"><a name="p74705163612"></a><a name="p74705163612"></a>用户态栈空间地址</p>
</td>
<td class="cellrowborder" valign="top" width="21.61216121612161%" headers="mcps1.2.6.1.5 "><p id="p144775143613"><a name="p144775143613"></a><a name="p144775143613"></a>Cache</p>
</td>
</tr>
<tr id="row1047353364"><td class="cellrowborder" valign="top" width="11.721172117211722%" headers="mcps1.2.6.1.1 "><p id="p1947145163615"><a name="p1947145163615"></a><a name="p1947145163615"></a>共享库</p>
</td>
<td class="cellrowborder" valign="top" width="22.712271227122713%" headers="mcps1.2.6.1.2 "><p id="p147053364"><a name="p147053364"></a><a name="p147053364"></a>0x1F800000(起始地址随机)</p>
</td>
<td class="cellrowborder" valign="top" width="18.681868186818683%" headers="mcps1.2.6.1.3 "><p id="p2476517362"><a name="p2476517362"></a><a name="p2476517362"></a>0x277FFFFF</p>
</td>
<td class="cellrowborder" valign="top" width="25.27252725272527%" headers="mcps1.2.6.1.4 "><p id="p24745193617"><a name="p24745193617"></a><a name="p24745193617"></a>用户态共享库加载地址空间，包括mmap</p>
</td>
<td class="cellrowborder" valign="top" width="21.61216121612161%" headers="mcps1.2.6.1.5 "><p id="p11472510363"><a name="p11472510363"></a><a name="p11472510363"></a>Cache</p>
</td>
</tr>
</tbody>
</table>

## 运行机制<a name="section072885512412"></a>

虚拟内存管理中，虚拟地址空间是连续的，但是其映射的物理内存并不一定是连续的，如下图所示。可执行程序加载运行，CPU访问虚拟地址空间的代码或数据时存在两种情况：

-   CPU访问的虚拟地址所在的页，如V0，已经与具体的物理页P0做映射，CPU通过找到进程对应的页表条目（详见虚实映射一节），根据页表条目中的物理地址信息访问物理内存中的内容并返回。
-   CPU访问的虚拟地址所在的页，如V2，没有与具体的物理页做映射，系统会触发缺页异常，系统申请一个物理页，并把相应的信息拷贝到物理页中，并且把物理页的起始地址更新到页表条目中。此时CPU重新执行访问虚拟内存的指令便能够访问到具体的代码或数据。

**图 1**  内存映射示意图<a name="fig144371159135620"></a>  
![](figure/内存映射示意图.png "内存映射示意图")

## 开发指导<a name="section20956116050"></a>

### 接口说明<a name="section166137221657"></a>

**表 3**  虚拟内存管理模块接口

<a name="table1415203765610"></a>
<table><thead align="left"><tr id="row134151837125611"><th class="cellrowborder" valign="top" width="12.811281128112812%" id="mcps1.2.4.1.1"><p id="p16415637105612"><a name="p16415637105612"></a><a name="p16415637105612"></a>功能分类</p>
</th>
<th class="cellrowborder" valign="top" width="29.84298429842984%" id="mcps1.2.4.1.2"><p id="p11415163718562"><a name="p11415163718562"></a><a name="p11415163718562"></a>接口<strong id="b197068338312"><a name="b197068338312"></a><a name="b197068338312"></a>名称</strong></p>
</th>
<th class="cellrowborder" valign="top" width="57.34573457345735%" id="mcps1.2.4.1.3"><p id="p1641533755612"><a name="p1641533755612"></a><a name="p1641533755612"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row0415737175610"><td class="cellrowborder" rowspan="5" valign="top" width="12.811281128112812%" headers="mcps1.2.4.1.1 "><p id="p4917132105710"><a name="p4917132105710"></a><a name="p4917132105710"></a>获取进程空间系列接口</p>
</td>
<td class="cellrowborder" valign="top" width="29.84298429842984%" headers="mcps1.2.4.1.2 "><p id="p341513372561"><a name="p341513372561"></a><a name="p341513372561"></a>LOS_CurrSpaceGet</p>
</td>
<td class="cellrowborder" valign="top" width="57.34573457345735%" headers="mcps1.2.4.1.3 "><p id="p74151037185617"><a name="p74151037185617"></a><a name="p74151037185617"></a>获取当前进程空间结构体指针</p>
</td>
</tr>
<tr id="row1841519376561"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p64151837155618"><a name="p64151837155618"></a><a name="p64151837155618"></a>LOS_SpaceGet</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p441516379562"><a name="p441516379562"></a><a name="p441516379562"></a>获取虚拟地址对应的进程空间结构体指针</p>
</td>
</tr>
<tr id="row536885134010"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p236819594010"><a name="p236819594010"></a><a name="p236819594010"></a>LOS_GetKVmSpace</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p736918564019"><a name="p736918564019"></a><a name="p736918564019"></a>获取内核进程空间结构体指针</p>
</td>
</tr>
<tr id="row11567448194112"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p0568204814115"><a name="p0568204814115"></a><a name="p0568204814115"></a>LOS_GetVmallocSpace</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p05681348204114"><a name="p05681348204114"></a><a name="p05681348204114"></a>获取vmalloc空间结构体指针</p>
</td>
</tr>
<tr id="row1141513373562"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p17765212416"><a name="p17765212416"></a><a name="p17765212416"></a>LOS_GetVmSpaceList</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1972971913115"><a name="p1972971913115"></a><a name="p1972971913115"></a>获取进程空间链表指针</p>
</td>
</tr>
<tr id="row137812054195014"><td class="cellrowborder" rowspan="15" valign="top" width="12.811281128112812%" headers="mcps1.2.4.1.1 "><p id="p15344719152113"><a name="p15344719152113"></a><a name="p15344719152113"></a>虚拟地址区间region相关的操作</p>
</td>
<td class="cellrowborder" valign="top" width="29.84298429842984%" headers="mcps1.2.4.1.2 "><p id="p97821654195014"><a name="p97821654195014"></a><a name="p97821654195014"></a>LOS_RegionFind</p>
</td>
<td class="cellrowborder" valign="top" width="57.34573457345735%" headers="mcps1.2.4.1.3 "><p id="p137821854205011"><a name="p137821854205011"></a><a name="p137821854205011"></a>根据起始地址在进程空间内查找是否存在虚拟地址区间</p>
</td>
</tr>
<tr id="row254713575505"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p954785720501"><a name="p954785720501"></a><a name="p954785720501"></a>LOS_RegionRangeFind</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p20547557175013"><a name="p20547557175013"></a><a name="p20547557175013"></a>根据地址区间在进程空间内查找是否存在虚拟地址区间</p>
</td>
</tr>
<tr id="row1692045119"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1510110115114"><a name="p1510110115114"></a><a name="p1510110115114"></a>LOS_IsRegionFileValid</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p61011045112"><a name="p61011045112"></a><a name="p61011045112"></a>判断虚拟地址区间region是否与文件关联映射</p>
</td>
</tr>
<tr id="row186701424548"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1967018210546"><a name="p1967018210546"></a><a name="p1967018210546"></a>LOS_RegionAlloc</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p196701221548"><a name="p196701221548"></a><a name="p196701221548"></a>申请空闲的虚拟地址区间</p>
</td>
</tr>
<tr id="row1955586175412"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p555626195420"><a name="p555626195420"></a><a name="p555626195420"></a>LOS_RegionFree</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p85568612547"><a name="p85568612547"></a><a name="p85568612547"></a>释放进程空间内特定的region</p>
</td>
</tr>
<tr id="row259111510282"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p3591135110288"><a name="p3591135110288"></a><a name="p3591135110288"></a>LOS_RegionEndAddr</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p4675183817474"><a name="p4675183817474"></a><a name="p4675183817474"></a>获取指定地址区间region的结束地址</p>
</td>
</tr>
<tr id="row12894115716285"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p889418577280"><a name="p889418577280"></a><a name="p889418577280"></a>LOS_RegionSize</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p68941757112813"><a name="p68941757112813"></a><a name="p68941757112813"></a>获取region的大小</p>
</td>
</tr>
<tr id="row14931456182812"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1293135611287"><a name="p1293135611287"></a><a name="p1293135611287"></a>LOS_IsRegionTypeFile</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1393185613288"><a name="p1393185613288"></a><a name="p1393185613288"></a>判断是否为文件内存映射</p>
</td>
</tr>
<tr id="row12153854132814"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p115335452819"><a name="p115335452819"></a><a name="p115335452819"></a>LOS_IsRegionPermUserReadOnly</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1415314545285"><a name="p1415314545285"></a><a name="p1415314545285"></a>判断地址区间是否是用户空间只读属性</p>
</td>
</tr>
<tr id="row29249497282"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1492415495284"><a name="p1492415495284"></a><a name="p1492415495284"></a>LOS_IsRegionFlagPrivateOnly</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1392434982817"><a name="p1392434982817"></a><a name="p1392434982817"></a>判断地址区间是否是具有私有属性</p>
</td>
</tr>
<tr id="row1233194042814"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p3339401289"><a name="p3339401289"></a><a name="p3339401289"></a>LOS_SetRegionTypeFile</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p193317409285"><a name="p193317409285"></a><a name="p193317409285"></a>设置文件内存映射属性</p>
</td>
</tr>
<tr id="row178971473283"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p4898184782815"><a name="p4898184782815"></a><a name="p4898184782815"></a>LOS_IsRegionTypeDev</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p11898144722818"><a name="p11898144722818"></a><a name="p11898144722818"></a>判断是否为设备内存映射</p>
</td>
</tr>
<tr id="row11137546152811"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p20137194672812"><a name="p20137194672812"></a><a name="p20137194672812"></a>LOS_SetRegionTypeDev</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p81384462287"><a name="p81384462287"></a><a name="p81384462287"></a>设置设备内存映射属性</p>
</td>
</tr>
<tr id="row1023564216285"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p92351842162819"><a name="p92351842162819"></a><a name="p92351842162819"></a>LOS_IsRegionTypeAnon</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p6235842132818"><a name="p6235842132818"></a><a name="p6235842132818"></a>判断是否为匿名映射</p>
</td>
</tr>
<tr id="row1646364402813"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p44631644152814"><a name="p44631644152814"></a><a name="p44631644152814"></a>LOS_SetRegionTypeAnon</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p174631844182818"><a name="p174631844182818"></a><a name="p174631844182818"></a>设置匿名映射属性</p>
</td>
</tr>
<tr id="row038233717288"><td class="cellrowborder" rowspan="5" valign="top" width="12.811281128112812%" headers="mcps1.2.4.1.1 "><p id="p6820331185317"><a name="p6820331185317"></a><a name="p6820331185317"></a>地址校验</p>
</td>
<td class="cellrowborder" valign="top" width="29.84298429842984%" headers="mcps1.2.4.1.2 "><p id="p838383720282"><a name="p838383720282"></a><a name="p838383720282"></a>LOS_IsUserAddress</p>
</td>
<td class="cellrowborder" valign="top" width="57.34573457345735%" headers="mcps1.2.4.1.3 "><p id="p12383837102818"><a name="p12383837102818"></a><a name="p12383837102818"></a>判断地址是否在用户态空间</p>
</td>
</tr>
<tr id="row61506354284"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p2151113517288"><a name="p2151113517288"></a><a name="p2151113517288"></a>LOS_IsUserAddressRange</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p615123552814"><a name="p615123552814"></a><a name="p615123552814"></a>判断地址区间是否在用户态空间</p>
</td>
</tr>
<tr id="row18301515194210"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p19301141519421"><a name="p19301141519421"></a><a name="p19301141519421"></a>LOS_IsKernelAddress</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p730110154427"><a name="p730110154427"></a><a name="p730110154427"></a>判断地址是否在内核空间</p>
</td>
</tr>
<tr id="row191211718204213"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1112121812423"><a name="p1112121812423"></a><a name="p1112121812423"></a>LOS_IsKernelAddressRange</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p6122101814219"><a name="p6122101814219"></a><a name="p6122101814219"></a>判断地址区间是否在内核空间</p>
</td>
</tr>
<tr id="row774964092115"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p17152102415416"><a name="p17152102415416"></a><a name="p17152102415416"></a>LOS_IsRangeInSpace</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p115218248547"><a name="p115218248547"></a><a name="p115218248547"></a>判断地址区间是否在进程空间内</p>
</td>
</tr>
<tr id="row179196525521"><td class="cellrowborder" rowspan="3" valign="top" width="12.811281128112812%" headers="mcps1.2.4.1.1 "><p id="p153501191535"><a name="p153501191535"></a><a name="p153501191535"></a>vmalloc操作</p>
</td>
<td class="cellrowborder" valign="top" width="29.84298429842984%" headers="mcps1.2.4.1.2 "><p id="p152945155531"><a name="p152945155531"></a><a name="p152945155531"></a>LOS_VMalloc</p>
</td>
<td class="cellrowborder" valign="top" width="57.34573457345735%" headers="mcps1.2.4.1.3 "><p id="p1229461512535"><a name="p1229461512535"></a><a name="p1229461512535"></a>vmalloc申请内存</p>
</td>
</tr>
<tr id="row1934135935211"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p162941115155315"><a name="p162941115155315"></a><a name="p162941115155315"></a>LOS_VFree</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p12294171516536"><a name="p12294171516536"></a><a name="p12294171516536"></a>vmalloc释放内存</p>
</td>
</tr>
<tr id="row944214919304"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p644229163016"><a name="p644229163016"></a><a name="p644229163016"></a>LOS_IsVmallocAddress</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1344220993011"><a name="p1344220993011"></a><a name="p1344220993011"></a>判断地址是否是通过vmalloc申请的</p>
</td>
</tr>
<tr id="row72131845145315"><td class="cellrowborder" rowspan="4" valign="top" width="12.811281128112812%" headers="mcps1.2.4.1.1 "><p id="p84847816543"><a name="p84847816543"></a><a name="p84847816543"></a>内存申请系列接口</p>
</td>
<td class="cellrowborder" valign="top" width="29.84298429842984%" headers="mcps1.2.4.1.2 "><p id="p8787345546"><a name="p8787345546"></a><a name="p8787345546"></a>LOS_KernelMalloc</p>
</td>
<td class="cellrowborder" valign="top" width="57.34573457345735%" headers="mcps1.2.4.1.3 "><p id="p17787444543"><a name="p17787444543"></a><a name="p17787444543"></a>申请小于16k的内存则通过堆内存池获取，否则申请多个连续物理页</p>
</td>
</tr>
<tr id="row48491549145311"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p14787149541"><a name="p14787149541"></a><a name="p14787149541"></a>LOS_KernelMallocAlign</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p478719411543"><a name="p478719411543"></a><a name="p478719411543"></a>申请具有对齐属性的内存，申请规则：申请小于16k的内存则通过堆内存池获取，否则申请多个连续物理页</p>
</td>
</tr>
<tr id="row151093538536"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p15787134185412"><a name="p15787134185412"></a><a name="p15787134185412"></a>LOS_KernelFree</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p878712410546"><a name="p878712410546"></a><a name="p878712410546"></a>释放内核堆内存</p>
</td>
</tr>
<tr id="row5126856205319"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p197871646545"><a name="p197871646545"></a><a name="p197871646545"></a>LOS_KernelRealloc</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p378813416547"><a name="p378813416547"></a><a name="p378813416547"></a>重新分配内核内存空间</p>
</td>
</tr>
<tr id="row12397132718549"><td class="cellrowborder" rowspan="5" valign="top" width="12.811281128112812%" headers="mcps1.2.4.1.1 "><p id="p112971954115419"><a name="p112971954115419"></a><a name="p112971954115419"></a>其他</p>
</td>
<td class="cellrowborder" valign="top" width="29.84298429842984%" headers="mcps1.2.4.1.2 "><p id="p2777034145414"><a name="p2777034145414"></a><a name="p2777034145414"></a>LOS_PaddrQuery</p>
</td>
<td class="cellrowborder" valign="top" width="57.34573457345735%" headers="mcps1.2.4.1.3 "><p id="p13777834115413"><a name="p13777834115413"></a><a name="p13777834115413"></a>根据虚拟地址获取对应的物理地址</p>
</td>
</tr>
<tr id="row5558122119542"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p9558421155418"><a name="p9558421155418"></a><a name="p9558421155418"></a>LOS_VmSpaceFree</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p755852119545"><a name="p755852119545"></a><a name="p755852119545"></a>释放进程空间，包括虚拟内存区间、页表等信息</p>
</td>
</tr>
<tr id="row15860142919544"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p168603298547"><a name="p168603298547"></a><a name="p168603298547"></a>LOS_VmSpaceReserve</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p12860429185410"><a name="p12860429185410"></a><a name="p12860429185410"></a>在进程空间中预留一块内存空间</p>
</td>
</tr>
<tr id="row394217543569"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p11943125419566"><a name="p11943125419566"></a><a name="p11943125419566"></a>LOS_VaddrToPaddrMmap</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p16943954105613"><a name="p16943954105613"></a><a name="p16943954105613"></a>将指定长度的物理地址区间与虚拟地址区间做映射，需提前申请物理地址区间</p>
</td>
</tr>
<tr id="row18527155718"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p118526110579"><a name="p118526110579"></a><a name="p118526110579"></a>LOS_UserSpaceVmAlloc</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1485214117575"><a name="p1485214117575"></a><a name="p1485214117575"></a>根据地址、大小、权限等信息在用户进程空间内申请地址区间region</p>
</td>
</tr>
</tbody>
</table>

### 开发流程<a name="section8752103914513"></a>

虚拟内存相关接口的使用：

1.  根据进程空间获取的系列接口可以得到进程空间结构体，进而可以读取结构体相应信息。
2.  对虚拟地址区间做相关操作：
    -   通过LOS\_RegionAlloc申请虚拟地址区间；

    -   通过LOS\_RegionFind、LOS\_RegionRangeFind可以查询是否存在相应的地址区间；
    -   通过LOS\_RegionFree释放虚拟地址区间。

3.  vmalloc接口及内存申请系列接口可以在内核中根据需要申请内存。

>![](../public_sys-resources/icon-note.gif) **说明：** 
>内存申请系列接口申请的内存要求物理内存是连续的，当系统内存无法满足大块连续内存的申请条件时会申请失败，一般适用于小块内存的申请；vmalloc相关接口申请的内存可以获得不连续的物理内存，但其是以页（当前系统一个页为4096字节）为单位的，当需要申请以页为整数倍的内存时可以通过vmalloc申请，例如文件系统中文件读取需要较大的缓存，便可以通过vmalloc相关接口申请内存。

