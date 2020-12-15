# OSAL<a name="EN-US_TOPIC_0000001054799547"></a>

-   [Overview](#section223828672165623)
-   [Summary](#section1437972704165623)
-   [Files](#files)
-   [Data Structures](#nested-classes)
-   [Macros](#define-members)
-   [Typedefs](#typedef-members)
-   [Enumerations](#enum-members)
-   [Functions](#func-members)
-   [Details](#section281237531165623)
-   [Macro Definition](#section1226510658165623)
-   [OSAL\_READB](#ga3de1529efbdabd4fb2f144c6f48df70b)
-   [OSAL\_READL](#ga14ce14451b2484b2e268a38757237f41)
-   [OSAL\_READW](#ga8bd523f234f24415fe733addd113e60b)
-   [OSAL\_WRITEB](#ga48e1f404639550c229aee3ec35a06d79)
-   [OSAL\_WRITEL](#gaba47d67efad3ad9d1a33a35d2982bd49)
-   [OSAL\_WRITEW](#ga3358a86c6bbb6f02ab108964962f441f)
-   [Enumeration Type](#section1297392036165623)
-   [OSAL\_IRQ\_TRIGGER\_MODE](#ga78cd126b10424753db6f39f9b72ea124)
-   [OSAL\_THREAD\_PRIORITY](#gab8c099a9c39fdde73c74b3f7367be5d0)
-   [Function](#section740670116165623)
-   [OsalAtomicDec\(\)](#gaa411f380e6b21c8467260030ceee38ff)
-   [OsalAtomicInc\(\)](#ga11214c11a9b875cb8ba0a67aeccc6ac9)
-   [OsalAtomicRead\(\)](#gaf7b7a860f5cf11bda3008ce16a5d79d5)
-   [OsalAtomicSet\(\)](#ga0b82ac10305c7ec5ae46707034b866c3)
-   [OsalClearBit\(\)](#gae3e5b84f326aa1a2c4b8427509f80cd9)
-   [OsalDiffTime\(\)](#ga36b0af6646f887175993e78391a5cabc)
-   [OsalDisableIrq\(\)](#gaf6ae039d209e46d45c683aeda3e7cd28)
-   [OsalEnableIrq\(\)](#ga7f27c6171678ab8cf925660068ac38ff)
-   [OsalFileClose\(\)](#ga8786ab2baa8669e79173ab7ab47d67bb)
-   [OsalFileLseek\(\)](#gaada4d66f4bb789bb4113e4084da6dea2)
-   [OsalFileOpen\(\)](#ga6707125b6ac5e13912a181877f18f292)
-   [OsalFileRead\(\)](#gac8ebc8dc4b9ce9725875868f69fd17a8)
-   [OsalFileWrite\(\)](#ga305f575f875ff26bb907c67c23dfb16a)
-   [OsalGetSysTimeMs\(\)](#gaf91cb1945b66e324fbb0761aa2f98ea3)
-   [OsalGetTime\(\)](#ga649d3090dcf9ba0e22649e11ac40831f)
-   [OsalIoRemap\(\)](#ga281757438906600ef89a13362151d955)
-   [OsalIoUnmap\(\)](#ga0a845edb56df0a35beeea338dc5121aa)
-   [OsalMDelay\(\)](#ga82ddd682a2441a22dd6148f634a6cea4)
-   [OsalMemAlloc\(\)](#ga0a1c85eaad6c1588ed091e0e89b74ed2)
-   [OsalMemAllocAlign\(\)](#gaf6d1b6e5583d9e1ca5abf5048bb3bad9)
-   [OsalMemCalloc\(\)](#ga7a6d0f6400e835bcbe9ec655bc9f43ee)
-   [OsalMemFree\(\)](#ga20dc9c415433effea4d481180a50cfa1)
-   [OsalMSleep\(\)](#ga2361dc099952df28aaef8968f9f4b9a7)
-   [OsalMutexDestroy\(\)](#gaa37328265ee97277516f6905f90a41b3)
-   [OsalMutexInit\(\)](#ga9bbc55785f8a533b0b099956bcbe258e)
-   [OsalMutexLock\(\)](#ga45d893bf49a8fb8caf76fa5d31822e0e)
-   [OsalMutexTimedLock\(\)](#ga57162c8f2e812ef3e5ace498bb85a3b6)
-   [OsalMutexUnlock\(\)](#gae76ffb4db66c988be5209e0dfdc7a35f)
-   [OsalReadFirmware\(\)](#ga2b721d36c177786841cd05cecdb01034)
-   [OsalRegisterIrq\(\)](#gade084a1942c1672f2148ccf8f6c06331)
-   [OsalReleaseFirmware\(\)](#gadfccddc78411a76ae8f4af4282da12f0)
-   [OsalRequestFirmware\(\)](#ga428b9de7fb95a20ab9e25b47a7d4272c)
-   [OsalSeekFirmware\(\)](#ga41ae4dade9246f3b30efd276cbd43474)
-   [OsalSemDestroy\(\)](#ga0b6642005b8a128ac01f69385bd6969f)
-   [OsalSemInit\(\)](#ga7e4325c951479e93abe072290162da0b)
-   [OsalSemPost\(\)](#gadc3205b416d3fc8e1fa9c332b82e634a)
-   [OsalSemWait\(\)](#ga0000b9ee1421950d5b3a04cbc839c6af)
-   [OsalSleep\(\)](#ga8b9ca3498c54b11dcbe88a2a456f23ab)
-   [OsalSpinDestroy\(\)](#gacd3824f292ddef395bd1a4a7b5546470)
-   [OsalSpinInit\(\)](#gae36a2d6e4e0191273c9f86a918befb5c)
-   [OsalSpinLock\(\)](#gae1c4b9ac8ea2a4820d73c20ae017dbd7)
-   [OsalSpinLockIrq\(\)](#ga7d409ec573a06078112a8ffae14afce5)
-   [OsalSpinLockIrqSave\(\)](#gab711d8d56055e78dd85f84bc530a4d3f)
-   [OsalSpinUnlock\(\)](#gada1f1826b19dc900af370a2bcd9681b9)
-   [OsalSpinUnlockIrq\(\)](#ga7d7848d572fbda413b3b5770e95a234e)
-   [OsalSpinUnlockIrqRestore\(\)](#ga3be4dbde6c9ae740b012e49ab90e7a8a)
-   [OsalTestBit\(\)](#gaf02c15a3593cac4add3f661b63aebf81)
-   [OsalTestClearBit\(\)](#ga8665e70c704921f443fd2db8193ff7cc)
-   [OsalTestSetBit\(\)](#gac0ff99812a327a4a595802a23b41b46f)
-   [OsalThreadCreate\(\)](#gad598b3f4b91f5e6aeeaf7b8a6e507f1e)
-   [OsalThreadDestroy\(\)](#ga223ce6b94770348a93168525c536e6f9)
-   [OsalThreadResume\(\)](#ga32f0b5c622518b7453f758d95b137a94)
-   [OsalThreadStart\(\)](#ga74c93bd48d27cde830451f63b224307a)
-   [OsalThreadSuspend\(\)](#gad556075f625d01557c0075a2c092a1da)
-   [OsalTimerCreate\(\)](#ga879d9a437e1423021f95cb9341f0d6af)
-   [OsalTimerDelete\(\)](#gab754f3522245e6b2f9ee1cdecae62b52)
-   [OsalTimerSetTimeout\(\)](#ga49c2fe3f54d548fe5ec0d03a79691376)
-   [OsalTimerStartLoop\(\)](#ga575e4f41359c737ab9690ab28838b99f)
-   [OsalTimerStartOnce\(\)](#gaf2e49d5b01b49e5f64a7701da8667141)
-   [OsalUDelay\(\)](#ga7ae78fa3318a82dbd769827d4f373958)
-   [OsalUnregisterIrq\(\)](#gade4ec4496eb07f1ff0610b53ba419dba)

## **Overview**<a name="section223828672165623"></a>

**Description:**

Defines the structures and interfaces for the Operating System Abstraction Layer \(OSAL\) module. 

The OSAL module harmonizes OS interface differences and provides unified OS interfaces externally, including the memory management, thread, mutex, spinlock, semaphore, timer, file, interrupt, time, atomic, firmware, and I/O operation modules.

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1437972704165623"></a>

## Files<a name="files"></a>

<a name="table1248703474165623"></a>
<table><thead align="left"><tr id="row1740072292165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1234979849165623"><a name="p1234979849165623"></a><a name="p1234979849165623"></a>File Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p869635850165623"><a name="p869635850165623"></a><a name="p869635850165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1119460236165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1443490371165623"><a name="p1443490371165623"></a><a name="p1443490371165623"></a><a href="osal_atomic-h.md">osal_atomic.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p258333294165623"><a name="p258333294165623"></a><a name="p258333294165623"></a>Declares atomic and bit operation interfaces. </p>
</td>
</tr>
<tr id="row1563671320165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1369842894165623"><a name="p1369842894165623"></a><a name="p1369842894165623"></a><a href="osal_file-h.md">osal_file.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p100514210165623"><a name="p100514210165623"></a><a name="p100514210165623"></a>Declares the file structures and interfaces. </p>
</td>
</tr>
<tr id="row420807585165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2136089563165623"><a name="p2136089563165623"></a><a name="p2136089563165623"></a><a href="osal_firmware-h.md">osal_firmware.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p922674250165623"><a name="p922674250165623"></a><a name="p922674250165623"></a>Declares firmware structures and interfaces. </p>
</td>
</tr>
<tr id="row1325948145165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p884010106165623"><a name="p884010106165623"></a><a name="p884010106165623"></a><a href="osal_io-h.md">osal_io.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p874926233165623"><a name="p874926233165623"></a><a name="p874926233165623"></a>Declares I/O interfaces. </p>
</td>
</tr>
<tr id="row672279061165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p473640677165623"><a name="p473640677165623"></a><a name="p473640677165623"></a><a href="osal_irq-h.md">osal_irq.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p813478088165623"><a name="p813478088165623"></a><a name="p813478088165623"></a>Declares interrupt request (IRQ) interfaces and common IRQ trigger modes. </p>
</td>
</tr>
<tr id="row1472913359165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1483621375165623"><a name="p1483621375165623"></a><a name="p1483621375165623"></a><a href="osal_mem-h.md">osal_mem.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2068698458165623"><a name="p2068698458165623"></a><a name="p2068698458165623"></a>Declares the driver memory request and release interfaces. </p>
</td>
</tr>
<tr id="row1444502003165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p582348110165623"><a name="p582348110165623"></a><a name="p582348110165623"></a><a href="osal_mutex-h.md">osal_mutex.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1096116255165623"><a name="p1096116255165623"></a><a name="p1096116255165623"></a>Declares mutex types and interfaces. </p>
</td>
</tr>
<tr id="row221577622165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p304272571165623"><a name="p304272571165623"></a><a name="p304272571165623"></a><a href="osal_sem-h.md">osal_sem.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1660308317165623"><a name="p1660308317165623"></a><a name="p1660308317165623"></a>Declares semaphore structures and interfaces. </p>
</td>
</tr>
<tr id="row591081687165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1000070778165623"><a name="p1000070778165623"></a><a name="p1000070778165623"></a><a href="osal_spinlock-h.md">osal_spinlock.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p116719706165623"><a name="p116719706165623"></a><a name="p116719706165623"></a>Declares spinlock types and interfaces. </p>
</td>
</tr>
<tr id="row1167527526165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1271166302165623"><a name="p1271166302165623"></a><a name="p1271166302165623"></a><a href="osal_thread-h.md">osal_thread.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1801388561165623"><a name="p1801388561165623"></a><a name="p1801388561165623"></a>Declares thread types and interfaces. </p>
</td>
</tr>
<tr id="row1482032070165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p122825222165623"><a name="p122825222165623"></a><a name="p122825222165623"></a><a href="osal_time-h.md">osal_time.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p787812953165623"><a name="p787812953165623"></a><a name="p787812953165623"></a>Declares the time, sleep, and delay interfaces. </p>
</td>
</tr>
<tr id="row1171409339165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1929919651165623"><a name="p1929919651165623"></a><a name="p1929919651165623"></a><a href="osal_timer-h.md">osal_timer.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p239232183165623"><a name="p239232183165623"></a><a name="p239232183165623"></a>Declares timer types and interfaces. </p>
</td>
</tr>
</tbody>
</table>

## Data Structures<a name="nested-classes"></a>

<a name="table1719273784165623"></a>
<table><thead align="left"><tr id="row1397549429165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1135877770165623"><a name="p1135877770165623"></a><a name="p1135877770165623"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1656475455165623"><a name="p1656475455165623"></a><a name="p1656475455165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row801939613165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1409325595165623"><a name="p1409325595165623"></a><a name="p1409325595165623"></a><a href="osalatomic.md">OsalAtomic</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1977292717165623"><a name="p1977292717165623"></a><a name="p1977292717165623"></a>Describes an atomic. </p>
</td>
</tr>
<tr id="row737129528165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2139921145165623"><a name="p2139921145165623"></a><a name="p2139921145165623"></a><a href="osalfile.md">OsalFile</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1802766252165623"><a name="p1802766252165623"></a><a name="p1802766252165623"></a>Declares a file type. </p>
</td>
</tr>
<tr id="row2086771153165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1736904991165623"><a name="p1736904991165623"></a><a name="p1736904991165623"></a><a href="osalfirmware.md">OsalFirmware</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1546945401165623"><a name="p1546945401165623"></a><a name="p1546945401165623"></a>Defines the data structure for operating a firmware file. </p>
</td>
</tr>
<tr id="row1365640046165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p156947935165623"><a name="p156947935165623"></a><a name="p156947935165623"></a><a href="osalfwblock.md">OsalFwBlock</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1765102155165623"><a name="p1765102155165623"></a><a name="p1765102155165623"></a>Defines the data structure for reading a firmware file. </p>
</td>
</tr>
<tr id="row1746106086165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1765862230165623"><a name="p1765862230165623"></a><a name="p1765862230165623"></a><a href="osalmutex.md">OsalMutex</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p920806201165623"><a name="p920806201165623"></a><a name="p920806201165623"></a>Describes a mutex. </p>
</td>
</tr>
<tr id="row2060421052165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p908528823165623"><a name="p908528823165623"></a><a name="p908528823165623"></a><a href="osalsem.md">OsalSem</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p788885760165623"><a name="p788885760165623"></a><a name="p788885760165623"></a>Describes a semaphore. </p>
</td>
</tr>
<tr id="row226754418165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1681362269165623"><a name="p1681362269165623"></a><a name="p1681362269165623"></a><a href="osalspinlock.md">OsalSpinlock</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p782411490165623"><a name="p782411490165623"></a><a name="p782411490165623"></a>Describes a spinlock. </p>
</td>
</tr>
<tr id="row1816526182165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p486969473165623"><a name="p486969473165623"></a><a name="p486969473165623"></a><a href="osalthreadparam.md">OsalThreadParam</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1837073209165623"><a name="p1837073209165623"></a><a name="p1837073209165623"></a>Describes thread parameters. </p>
</td>
</tr>
<tr id="row1162047142165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p873285432165623"><a name="p873285432165623"></a><a name="p873285432165623"></a><a href="osalthread.md">OsalThread</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1953568624165623"><a name="p1953568624165623"></a><a name="p1953568624165623"></a>Describes a thread. </p>
</td>
</tr>
<tr id="row1774260777165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1654065007165623"><a name="p1654065007165623"></a><a name="p1654065007165623"></a><a href="osaltimespec.md">OsalTimespec</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1207415148165623"><a name="p1207415148165623"></a><a name="p1207415148165623"></a>Defines time. </p>
</td>
</tr>
<tr id="row773123839165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1116458972165623"><a name="p1116458972165623"></a><a name="p1116458972165623"></a><a href="osaltimer.md">OsalTimer</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1719407106165623"><a name="p1719407106165623"></a><a name="p1719407106165623"></a>Describes a timer. </p>
</td>
</tr>
</tbody>
</table>

## Macros<a name="define-members"></a>

<a name="table1537722925165623"></a>
<table><thead align="left"><tr id="row624807992165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2053636447165623"><a name="p2053636447165623"></a><a name="p2053636447165623"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1836224926165623"><a name="p1836224926165623"></a><a name="p1836224926165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row560920719165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1601755505165623"><a name="p1601755505165623"></a><a name="p1601755505165623"></a><em id="gab208afeed35dd98f6a0ccf807e9c722d"><a name="gab208afeed35dd98f6a0ccf807e9c722d"></a><a name="gab208afeed35dd98f6a0ccf807e9c722d"></a></em>OSAL_O_RD_ONLY    0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1603008860165623"><a name="p1603008860165623"></a><a name="p1603008860165623"></a>Opens a file in read-only mode. </p>
</td>
</tr>
<tr id="row1754505599165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p648027935165623"><a name="p648027935165623"></a><a name="p648027935165623"></a><em id="ga1e37c3fb82a2bcff729f97478bc28f81"><a name="ga1e37c3fb82a2bcff729f97478bc28f81"></a><a name="ga1e37c3fb82a2bcff729f97478bc28f81"></a></em>OSAL_O_WR_ONLY    1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2114866194165623"><a name="p2114866194165623"></a><a name="p2114866194165623"></a>Opens a file in write-only mode. </p>
</td>
</tr>
<tr id="row1710267576165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p922376743165623"><a name="p922376743165623"></a><a name="p922376743165623"></a><em id="gabac6ceec2cb877ae0c4c0c89f2e13451"><a name="gabac6ceec2cb877ae0c4c0c89f2e13451"></a><a name="gabac6ceec2cb877ae0c4c0c89f2e13451"></a></em>OSAL_O_RDWR    2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p562889552165623"><a name="p562889552165623"></a><a name="p562889552165623"></a>Opens a file in read and write mode. </p>
</td>
</tr>
<tr id="row1655451302165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2096287106165623"><a name="p2096287106165623"></a><a name="p2096287106165623"></a><em id="ga9cb465f6d142e859258e14199702906e"><a name="ga9cb465f6d142e859258e14199702906e"></a><a name="ga9cb465f6d142e859258e14199702906e"></a></em>OSAL_S_IREAD    00400</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1356045166165623"><a name="p1356045166165623"></a><a name="p1356045166165623"></a>Defines the read permission for the owner. </p>
</td>
</tr>
<tr id="row93025280165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1301757084165623"><a name="p1301757084165623"></a><a name="p1301757084165623"></a><em id="gaf93f6ab3441029a84b5f04904daf68be"><a name="gaf93f6ab3441029a84b5f04904daf68be"></a><a name="gaf93f6ab3441029a84b5f04904daf68be"></a></em>OSAL_S_IWRITE    00200</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1810054516165623"><a name="p1810054516165623"></a><a name="p1810054516165623"></a>Defines the write permission for the owner. </p>
</td>
</tr>
<tr id="row524793587165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1449959273165623"><a name="p1449959273165623"></a><a name="p1449959273165623"></a><em id="gaa168a8495f19631b9d4de6e5da688e26"><a name="gaa168a8495f19631b9d4de6e5da688e26"></a><a name="gaa168a8495f19631b9d4de6e5da688e26"></a></em>OSAL_S_IEXEC    00100</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p67314987165623"><a name="p67314987165623"></a><a name="p67314987165623"></a>Defines the execution permission for the owner. </p>
</td>
</tr>
<tr id="row814985623165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p681423180165623"><a name="p681423180165623"></a><a name="p681423180165623"></a><em id="ga008dcb6a04b63ef620c25aa5b41f211a"><a name="ga008dcb6a04b63ef620c25aa5b41f211a"></a><a name="ga008dcb6a04b63ef620c25aa5b41f211a"></a></em>OSAL_S_IRGRP    00040</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2033562381165623"><a name="p2033562381165623"></a><a name="p2033562381165623"></a>Defines the read permission for the group. </p>
</td>
</tr>
<tr id="row1149051043165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p401879941165623"><a name="p401879941165623"></a><a name="p401879941165623"></a><em id="ga982f1e009c6caeb8060e6442a866803f"><a name="ga982f1e009c6caeb8060e6442a866803f"></a><a name="ga982f1e009c6caeb8060e6442a866803f"></a></em>OSAL_S_IWGRP    00020</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p197631120165623"><a name="p197631120165623"></a><a name="p197631120165623"></a>Defines the write permission for the group. </p>
</td>
</tr>
<tr id="row212364694165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1234342114165623"><a name="p1234342114165623"></a><a name="p1234342114165623"></a><em id="gaa1e6fa403fcd99229902e9a8cd98a74c"><a name="gaa1e6fa403fcd99229902e9a8cd98a74c"></a><a name="gaa1e6fa403fcd99229902e9a8cd98a74c"></a></em>OSAL_S_IXGRP    00010</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p795481662165623"><a name="p795481662165623"></a><a name="p795481662165623"></a>Defines the execution permission for the group. </p>
</td>
</tr>
<tr id="row944406811165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p557987779165623"><a name="p557987779165623"></a><a name="p557987779165623"></a><em id="ga01e4a94482a048060c250d3d5d899cd6"><a name="ga01e4a94482a048060c250d3d5d899cd6"></a><a name="ga01e4a94482a048060c250d3d5d899cd6"></a></em>OSAL_S_IROTH    00004</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1772943893165623"><a name="p1772943893165623"></a><a name="p1772943893165623"></a>Defines the read permission for others. </p>
</td>
</tr>
<tr id="row1965006585165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p600033268165623"><a name="p600033268165623"></a><a name="p600033268165623"></a><em id="gaea63281bfbac42036bb549c2bda2d192"><a name="gaea63281bfbac42036bb549c2bda2d192"></a><a name="gaea63281bfbac42036bb549c2bda2d192"></a></em>OSAL_S_IWOTH    00002</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2082528885165623"><a name="p2082528885165623"></a><a name="p2082528885165623"></a>Defines the write permission for others. </p>
</td>
</tr>
<tr id="row2019198216165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1236777764165623"><a name="p1236777764165623"></a><a name="p1236777764165623"></a><em id="ga9e308388be9855050060a87a93191d5e"><a name="ga9e308388be9855050060a87a93191d5e"></a><a name="ga9e308388be9855050060a87a93191d5e"></a></em>OSAL_S_IXOTH    00001</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p172237775165623"><a name="p172237775165623"></a><a name="p172237775165623"></a>Defines the execution permission for others. </p>
</td>
</tr>
<tr id="row1408010837165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1887832312165623"><a name="p1887832312165623"></a><a name="p1887832312165623"></a><em id="ga110fc469c88e83828679a3dedb4b5f3d"><a name="ga110fc469c88e83828679a3dedb4b5f3d"></a><a name="ga110fc469c88e83828679a3dedb4b5f3d"></a></em>OSAL_SEEK_SET    0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1373726265165623"><a name="p1373726265165623"></a><a name="p1373726265165623"></a>Defines the offset from the file header. </p>
</td>
</tr>
<tr id="row716540061165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1646573737165623"><a name="p1646573737165623"></a><a name="p1646573737165623"></a><em id="ga2ae6c04da45367479db0f914b250a0a7"><a name="ga2ae6c04da45367479db0f914b250a0a7"></a><a name="ga2ae6c04da45367479db0f914b250a0a7"></a></em>OSAL_SEEK_CUR    1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p287648695165623"><a name="p287648695165623"></a><a name="p287648695165623"></a>Defines the offset from the current position. </p>
</td>
</tr>
<tr id="row729362873165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1551110410165623"><a name="p1551110410165623"></a><a name="p1551110410165623"></a><em id="gaf282e1e5207b934c0c71ce9558ac1940"><a name="gaf282e1e5207b934c0c71ce9558ac1940"></a><a name="gaf282e1e5207b934c0c71ce9558ac1940"></a></em>OSAL_SEEK_END    2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2067764877165623"><a name="p2067764877165623"></a><a name="p2067764877165623"></a>Defines the offset from the end of the file. </p>
</td>
</tr>
<tr id="row691479086165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1344474508165623"><a name="p1344474508165623"></a><a name="p1344474508165623"></a><a href="osal.md#ga48e1f404639550c229aee3ec35a06d79">OSAL_WRITEB</a>(value, address)   writeb(value, address)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p264840536165623"><a name="p264840536165623"></a><a name="p264840536165623"></a>Writes one byte of data into an I/O address space. </p>
</td>
</tr>
<tr id="row1062848810165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p717428078165623"><a name="p717428078165623"></a><a name="p717428078165623"></a><a href="osal.md#ga3358a86c6bbb6f02ab108964962f441f">OSAL_WRITEW</a>(value, address)   writew(value, address)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p399033847165623"><a name="p399033847165623"></a><a name="p399033847165623"></a>Writes a short integer into an I/O address space. </p>
</td>
</tr>
<tr id="row147205803165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1757982961165623"><a name="p1757982961165623"></a><a name="p1757982961165623"></a><a href="osal.md#gaba47d67efad3ad9d1a33a35d2982bd49">OSAL_WRITEL</a>(value, address)   writel(value, address)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p987934922165623"><a name="p987934922165623"></a><a name="p987934922165623"></a>Writes an integer into an I/O address space. </p>
</td>
</tr>
<tr id="row377761111165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1194012786165623"><a name="p1194012786165623"></a><a name="p1194012786165623"></a><a href="osal.md#ga3de1529efbdabd4fb2f144c6f48df70b">OSAL_READB</a>(address)   readb(address)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p572794537165623"><a name="p572794537165623"></a><a name="p572794537165623"></a>Reads one byte of data from an I/O address space. </p>
</td>
</tr>
<tr id="row1991984124165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p821633313165623"><a name="p821633313165623"></a><a name="p821633313165623"></a><a href="osal.md#ga8bd523f234f24415fe733addd113e60b">OSAL_READW</a>(address)   readw(address)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p712186255165623"><a name="p712186255165623"></a><a name="p712186255165623"></a>Reads a short integer from an I/O address space. </p>
</td>
</tr>
<tr id="row1984102562165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p800416674165623"><a name="p800416674165623"></a><a name="p800416674165623"></a><a href="osal.md#ga14ce14451b2484b2e268a38757237f41">OSAL_READL</a>(address)   readl(address)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1943908246165623"><a name="p1943908246165623"></a><a name="p1943908246165623"></a>Reads an integer from an I/O address space. </p>
</td>
</tr>
<tr id="row302019085165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1798522119165623"><a name="p1798522119165623"></a><a name="p1798522119165623"></a><em id="ga63b1e9f0b9eacddc211f9a481c2597b3"><a name="ga63b1e9f0b9eacddc211f9a481c2597b3"></a><a name="ga63b1e9f0b9eacddc211f9a481c2597b3"></a></em>OSAL_DECLARE_MUTEX (mutex)   struct <a href="osalmutex.md">OsalMutex</a> mutex</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p96852228165623"><a name="p96852228165623"></a><a name="p96852228165623"></a>Defines a mutex. </p>
</td>
</tr>
<tr id="row1494861151165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p314556427165623"><a name="p314556427165623"></a><a name="p314556427165623"></a><em id="ga5e37d1f50835b70611517ad96146fc93"><a name="ga5e37d1f50835b70611517ad96146fc93"></a><a name="ga5e37d1f50835b70611517ad96146fc93"></a></em>OSAL_DECLARE_SEMAPHORE (sem)   struct <a href="osalsem.md">OsalSem</a> sem</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p26628301165623"><a name="p26628301165623"></a><a name="p26628301165623"></a>Defines a semaphore. </p>
</td>
</tr>
<tr id="row1395911405165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p237560377165623"><a name="p237560377165623"></a><a name="p237560377165623"></a><em id="gad624af1547135d60073f38b7f31ad826"><a name="gad624af1547135d60073f38b7f31ad826"></a><a name="gad624af1547135d60073f38b7f31ad826"></a></em>OSAL_DECLARE_SPINLOCK (spinlock)   <a href="osalspinlock.md">OsalSpinlock</a> spinlock</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p855251800165623"><a name="p855251800165623"></a><a name="p855251800165623"></a>Defines a spinlock. </p>
</td>
</tr>
<tr id="row1863403564165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p47013800165623"><a name="p47013800165623"></a><a name="p47013800165623"></a><em id="ga6178591bdeb64df97a5232350cc9bc26"><a name="ga6178591bdeb64df97a5232350cc9bc26"></a><a name="ga6178591bdeb64df97a5232350cc9bc26"></a></em>OSAL_DECLARE_THREAD (thread)   struct <a href="osalthread.md">OsalThread</a> thread</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1285805195165623"><a name="p1285805195165623"></a><a name="p1285805195165623"></a>Defines a thread macro. </p>
</td>
</tr>
<tr id="row1066872949165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1540935295165623"><a name="p1540935295165623"></a><a name="p1540935295165623"></a><em id="ga556360caa9ece72fcbbc6aef5fc648f1"><a name="ga556360caa9ece72fcbbc6aef5fc648f1"></a><a name="ga556360caa9ece72fcbbc6aef5fc648f1"></a></em>OSAL_DECLARE_TIMER (timer)   <a href="osaltimer.md">OsalTimer</a> timer</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p622257668165623"><a name="p622257668165623"></a><a name="p622257668165623"></a>Defines a timer macro. </p>
</td>
</tr>
</tbody>
</table>

## Typedefs<a name="typedef-members"></a>

<a name="table1350553220165623"></a>
<table><thead align="left"><tr id="row756307130165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p360966079165623"><a name="p360966079165623"></a><a name="p360966079165623"></a>Typedef Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1108383481165623"><a name="p1108383481165623"></a><a name="p1108383481165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row920165954165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p428655829165623"><a name="p428655829165623"></a><a name="p428655829165623"></a>OsalIRQHandle ) (uint32_t irqId, void *dev)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p238176347165623"><a name="p238176347165623"></a><a name="p238176347165623"></a><strong id="gab671a9e177f622a98af9ca1bd93198eb"><a name="gab671a9e177f622a98af9ca1bd93198eb"></a><a name="gab671a9e177f622a98af9ca1bd93198eb"></a></strong> typedef uint32_t(* </p>
<p id="p1189680030165623"><a name="p1189680030165623"></a><a name="p1189680030165623"></a>Defines an IRQ type. </p>
</td>
</tr>
<tr id="row399954243165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p549822723165623"><a name="p549822723165623"></a><a name="p549822723165623"></a>OsalThreadEntry ) (void *)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p727750606165623"><a name="p727750606165623"></a><a name="p727750606165623"></a><strong id="ga21ea0f87d53e65ec86a424c532d688d8"><a name="ga21ea0f87d53e65ec86a424c532d688d8"></a><a name="ga21ea0f87d53e65ec86a424c532d688d8"></a></strong> typedef int(* </p>
<p id="p1810454257165623"><a name="p1810454257165623"></a><a name="p1810454257165623"></a>Defines a thread callback function type. </p>
</td>
</tr>
<tr id="row1697242136165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p14073209165623"><a name="p14073209165623"></a><a name="p14073209165623"></a>OsalTimerFunc ) (uintptr_t arg)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1144322470165623"><a name="p1144322470165623"></a><a name="p1144322470165623"></a><strong id="gaf3e7a12075b25df5971049d8cd77c25c"><a name="gaf3e7a12075b25df5971049d8cd77c25c"></a><a name="gaf3e7a12075b25df5971049d8cd77c25c"></a></strong> typedef void(* </p>
<p id="p1288492515165623"><a name="p1288492515165623"></a><a name="p1288492515165623"></a>Describes a timer execution function type. </p>
</td>
</tr>
</tbody>
</table>

## Enumerations<a name="enum-members"></a>

<a name="table1211134233165623"></a>
<table><thead align="left"><tr id="row200283188165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p314320871165623"><a name="p314320871165623"></a><a name="p314320871165623"></a>Enumeration Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1090511138165623"><a name="p1090511138165623"></a><a name="p1090511138165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1877710865165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p415986867165623"><a name="p415986867165623"></a><a name="p415986867165623"></a><a href="osal.md#ga78cd126b10424753db6f39f9b72ea124">OSAL_IRQ_TRIGGER_MODE</a> {   <a href="osal.md#gga78cd126b10424753db6f39f9b72ea124aa0252cbf1f560b1d9951da4dfe896a1d">OSAL_IRQF_TRIGGER_NONE</a> = 0, <a href="osal.md#gga78cd126b10424753db6f39f9b72ea124ab98297946a624d99a3fad6adac899f2c">OSAL_IRQF_TRIGGER_RISING</a> = 1, <a href="osal.md#gga78cd126b10424753db6f39f9b72ea124a3088c6875fb44d05fd3a64a3d158295b">OSAL_IRQF_TRIGGER_FALLING</a> = 2, <a href="osal.md#gga78cd126b10424753db6f39f9b72ea124a9a997189554c568f66dd994a9f9e203d">OSAL_IRQF_TRIGGER_HIGH</a> = 4,   <a href="osal.md#gga78cd126b10424753db6f39f9b72ea124a7768ec0b5be5e88cfeb07dea96cd5865">OSAL_IRQF_TRIGGER_LOW</a> = 8 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1578483693165623"><a name="p1578483693165623"></a><a name="p1578483693165623"></a>Enumerates interrupt trigger modes. </p>
</td>
</tr>
<tr id="row1826974969165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p507639875165623"><a name="p507639875165623"></a><a name="p507639875165623"></a><a href="osal.md#gab8c099a9c39fdde73c74b3f7367be5d0">OSAL_THREAD_PRIORITY</a> { <a href="osal.md#ggab8c099a9c39fdde73c74b3f7367be5d0a077e53412997ddef962069a7cea4def6">OSAL_THREAD_PRI_LOW</a>, <a href="osal.md#ggab8c099a9c39fdde73c74b3f7367be5d0abc9ef48a9fc95f359a5c4d52041111e5">OSAL_THREAD_PRI_DEFAULT</a>, <a href="osal.md#ggab8c099a9c39fdde73c74b3f7367be5d0a61697eda5c5265d6d62271d00c098121">OSAL_THREAD_PRI_HIGH</a>, <a href="osal.md#ggab8c099a9c39fdde73c74b3f7367be5d0a9e66435e6d967adc68606b359a8753bd">OSAL_THREAD_PRI_HIGHEST</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1973239977165623"><a name="p1973239977165623"></a><a name="p1973239977165623"></a>Enumerates thread priorities. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table485756087165623"></a>
<table><thead align="left"><tr id="row966141968165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1085807773165623"><a name="p1085807773165623"></a><a name="p1085807773165623"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p791762211165623"><a name="p791762211165623"></a><a name="p791762211165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1422316773165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p823338264165623"><a name="p823338264165623"></a><a name="p823338264165623"></a><a href="osal.md#gaf7b7a860f5cf11bda3008ce16a5d79d5">OsalAtomicRead</a> (const <a href="osalatomic.md">OsalAtomic</a> *v)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p319921700165623"><a name="p319921700165623"></a><a name="p319921700165623"></a>int32_t </p>
<p id="p1583938964165623"><a name="p1583938964165623"></a><a name="p1583938964165623"></a>Reads the counter of an atomic. </p>
</td>
</tr>
<tr id="row931559895165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1437556533165623"><a name="p1437556533165623"></a><a name="p1437556533165623"></a><a href="osal.md#ga0b82ac10305c7ec5ae46707034b866c3">OsalAtomicSet</a> (<a href="osalatomic.md">OsalAtomic</a> *v, int32_t counter)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1160568065165623"><a name="p1160568065165623"></a><a name="p1160568065165623"></a>void </p>
<p id="p1794709795165623"><a name="p1794709795165623"></a><a name="p1794709795165623"></a>Sets the counter for an atomic. </p>
</td>
</tr>
<tr id="row459311228165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p114179616165623"><a name="p114179616165623"></a><a name="p114179616165623"></a><a href="osal.md#ga11214c11a9b875cb8ba0a67aeccc6ac9">OsalAtomicInc</a> (<a href="osalatomic.md">OsalAtomic</a> *v)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1690142315165623"><a name="p1690142315165623"></a><a name="p1690142315165623"></a>void </p>
<p id="p1947147763165623"><a name="p1947147763165623"></a><a name="p1947147763165623"></a>Increments the counter of an atomic by 1. </p>
</td>
</tr>
<tr id="row1255750072165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2103701457165623"><a name="p2103701457165623"></a><a name="p2103701457165623"></a><a href="osal.md#gaa411f380e6b21c8467260030ceee38ff">OsalAtomicDec</a> (<a href="osalatomic.md">OsalAtomic</a> *v)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p222142993165623"><a name="p222142993165623"></a><a name="p222142993165623"></a>void </p>
<p id="p413855320165623"><a name="p413855320165623"></a><a name="p413855320165623"></a>Decrements the counter of an atomic by 1. </p>
</td>
</tr>
<tr id="row1306171483165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1675508562165623"><a name="p1675508562165623"></a><a name="p1675508562165623"></a><a href="osal.md#gaf02c15a3593cac4add3f661b63aebf81">OsalTestBit</a> (unsigned long nr, const volatile unsigned long *addr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p505393017165623"><a name="p505393017165623"></a><a name="p505393017165623"></a>int32_t </p>
<p id="p166268189165623"><a name="p166268189165623"></a><a name="p166268189165623"></a>Tests the value of a specified bit of a variable. </p>
</td>
</tr>
<tr id="row1276633211165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1035422308165623"><a name="p1035422308165623"></a><a name="p1035422308165623"></a><a href="osal.md#gac0ff99812a327a4a595802a23b41b46f">OsalTestSetBit</a> (unsigned long nr, volatile unsigned long *addr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1825189121165623"><a name="p1825189121165623"></a><a name="p1825189121165623"></a>int32_t </p>
<p id="p2138313257165623"><a name="p2138313257165623"></a><a name="p2138313257165623"></a>Sets the value of a specified bit of the variable and returns the bit value before the setting. </p>
</td>
</tr>
<tr id="row1223387089165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p61494109165623"><a name="p61494109165623"></a><a name="p61494109165623"></a><a href="osal.md#ga8665e70c704921f443fd2db8193ff7cc">OsalTestClearBit</a> (unsigned long nr, volatile unsigned long *addr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1852398460165623"><a name="p1852398460165623"></a><a name="p1852398460165623"></a>int32_t </p>
<p id="p14838854165623"><a name="p14838854165623"></a><a name="p14838854165623"></a>Clears the value of a specified bit of the variable and returns the bit value before clearing. </p>
</td>
</tr>
<tr id="row329733709165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p919988286165623"><a name="p919988286165623"></a><a name="p919988286165623"></a><a href="osal.md#gae3e5b84f326aa1a2c4b8427509f80cd9">OsalClearBit</a> (unsigned long nr, volatile unsigned long *addr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p823411754165623"><a name="p823411754165623"></a><a name="p823411754165623"></a>void </p>
<p id="p290910773165623"><a name="p290910773165623"></a><a name="p290910773165623"></a>Clears the value of a specified bit of the variable. </p>
</td>
</tr>
<tr id="row22602533165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1244933498165623"><a name="p1244933498165623"></a><a name="p1244933498165623"></a><a href="osal.md#ga6707125b6ac5e13912a181877f18f292">OsalFileOpen</a> (<a href="osalfile.md">OsalFile</a> *file, const char *path, int flags, uint32_t rights)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1990496577165623"><a name="p1990496577165623"></a><a name="p1990496577165623"></a>int32_t </p>
<p id="p1523211821165623"><a name="p1523211821165623"></a><a name="p1523211821165623"></a>Opens a file. </p>
</td>
</tr>
<tr id="row53314805165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1581371633165623"><a name="p1581371633165623"></a><a name="p1581371633165623"></a><a href="osal.md#ga305f575f875ff26bb907c67c23dfb16a">OsalFileWrite</a> (<a href="osalfile.md">OsalFile</a> *file, const void *string, uint32_t length)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1531252468165623"><a name="p1531252468165623"></a><a name="p1531252468165623"></a>ssize_t </p>
<p id="p1305207445165623"><a name="p1305207445165623"></a><a name="p1305207445165623"></a>Writes a file. </p>
</td>
</tr>
<tr id="row525050317165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p751545830165623"><a name="p751545830165623"></a><a name="p751545830165623"></a><a href="osal.md#ga8786ab2baa8669e79173ab7ab47d67bb">OsalFileClose</a> (<a href="osalfile.md">OsalFile</a> *file)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p189432320165623"><a name="p189432320165623"></a><a name="p189432320165623"></a>void </p>
<p id="p949547366165623"><a name="p949547366165623"></a><a name="p949547366165623"></a>Closes a file. </p>
</td>
</tr>
<tr id="row1258993050165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p585311026165623"><a name="p585311026165623"></a><a name="p585311026165623"></a><a href="osal.md#gac8ebc8dc4b9ce9725875868f69fd17a8">OsalFileRead</a> (<a href="osalfile.md">OsalFile</a> *file, void *buf, uint32_t length)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p587585700165623"><a name="p587585700165623"></a><a name="p587585700165623"></a>ssize_t </p>
<p id="p1078898477165623"><a name="p1078898477165623"></a><a name="p1078898477165623"></a>Reads a file. </p>
</td>
</tr>
<tr id="row1239507285165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1075739403165623"><a name="p1075739403165623"></a><a name="p1075739403165623"></a><a href="osal.md#gaada4d66f4bb789bb4113e4084da6dea2">OsalFileLseek</a> (<a href="osalfile.md">OsalFile</a> *file, off_t offset, int32_t whence)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p289852413165623"><a name="p289852413165623"></a><a name="p289852413165623"></a>off_t </p>
<p id="p2030230269165623"><a name="p2030230269165623"></a><a name="p2030230269165623"></a>Sets the file read/write offset. </p>
</td>
</tr>
<tr id="row39559292165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1699545947165623"><a name="p1699545947165623"></a><a name="p1699545947165623"></a><a href="osal.md#ga428b9de7fb95a20ab9e25b47a7d4272c">OsalRequestFirmware</a> (struct <a href="osalfirmware.md">OsalFirmware</a> *fw, const char *fwName, void *device)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p902566450165623"><a name="p902566450165623"></a><a name="p902566450165623"></a>int32_t </p>
<p id="p1240728068165623"><a name="p1240728068165623"></a><a name="p1240728068165623"></a>Requests a firmware file based on its name and device information. </p>
</td>
</tr>
<tr id="row1173387980165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p139468609165623"><a name="p139468609165623"></a><a name="p139468609165623"></a><a href="osal.md#ga41ae4dade9246f3b30efd276cbd43474">OsalSeekFirmware</a> (struct <a href="osalfirmware.md">OsalFirmware</a> *fw, uint32_t offset)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1185000782165623"><a name="p1185000782165623"></a><a name="p1185000782165623"></a>int32_t </p>
<p id="p1811528942165623"><a name="p1811528942165623"></a><a name="p1811528942165623"></a>Reads a firmware file. </p>
</td>
</tr>
<tr id="row1957894827165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1330895993165623"><a name="p1330895993165623"></a><a name="p1330895993165623"></a><a href="osal.md#ga2b721d36c177786841cd05cecdb01034">OsalReadFirmware</a> (struct <a href="osalfirmware.md">OsalFirmware</a> *fw, struct <a href="osalfwblock.md">OsalFwBlock</a> *block)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p995600351165623"><a name="p995600351165623"></a><a name="p995600351165623"></a>int32_t </p>
<p id="p374032323165623"><a name="p374032323165623"></a><a name="p374032323165623"></a>Releases a firmware file. </p>
</td>
</tr>
<tr id="row602420749165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1629272714165623"><a name="p1629272714165623"></a><a name="p1629272714165623"></a><a href="osal.md#gadfccddc78411a76ae8f4af4282da12f0">OsalReleaseFirmware</a> (struct <a href="osalfirmware.md">OsalFirmware</a> *fw)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1287385442165623"><a name="p1287385442165623"></a><a name="p1287385442165623"></a>int32_t </p>
</td>
</tr>
<tr id="row873974683165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1979076507165623"><a name="p1979076507165623"></a><a name="p1979076507165623"></a><a href="osal.md#ga281757438906600ef89a13362151d955">OsalIoRemap</a> (unsigned long phys_addr, unsigned long size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1215451263165623"><a name="p1215451263165623"></a><a name="p1215451263165623"></a>static void * </p>
<p id="p1209221217165623"><a name="p1209221217165623"></a><a name="p1209221217165623"></a>Remaps an I/O physical address to its virtual address. </p>
</td>
</tr>
<tr id="row503873148165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p207355208165623"><a name="p207355208165623"></a><a name="p207355208165623"></a><a href="osal.md#ga0a845edb56df0a35beeea338dc5121aa">OsalIoUnmap</a> (void *addr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2055218042165623"><a name="p2055218042165623"></a><a name="p2055218042165623"></a>static void </p>
<p id="p386536632165623"><a name="p386536632165623"></a><a name="p386536632165623"></a>Unmaps an I/O virtual address associated with the physical address. </p>
</td>
</tr>
<tr id="row451437815165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1914964530165623"><a name="p1914964530165623"></a><a name="p1914964530165623"></a><a href="osal.md#gade084a1942c1672f2148ccf8f6c06331">OsalRegisterIrq</a> (uint32_t irqId, uint32_t config, <a href="osal.md#gab671a9e177f622a98af9ca1bd93198eb">OsalIRQHandle</a> handle, const char *name, void *dev)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p180726703165623"><a name="p180726703165623"></a><a name="p180726703165623"></a>int32_t </p>
<p id="p1771120835165623"><a name="p1771120835165623"></a><a name="p1771120835165623"></a>Registers an IRQ. </p>
</td>
</tr>
<tr id="row1227815897165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p770691889165623"><a name="p770691889165623"></a><a name="p770691889165623"></a><a href="osal.md#gade4ec4496eb07f1ff0610b53ba419dba">OsalUnregisterIrq</a> (uint32_t irqId)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1415638120165623"><a name="p1415638120165623"></a><a name="p1415638120165623"></a>int32_t </p>
<p id="p577340801165623"><a name="p577340801165623"></a><a name="p577340801165623"></a>Unregisters an IRQ. </p>
</td>
</tr>
<tr id="row1324189525165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1826825435165623"><a name="p1826825435165623"></a><a name="p1826825435165623"></a><a href="osal.md#ga7f27c6171678ab8cf925660068ac38ff">OsalEnableIrq</a> (uint32_t irqId)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p203029297165623"><a name="p203029297165623"></a><a name="p203029297165623"></a>int32_t </p>
<p id="p12716712165623"><a name="p12716712165623"></a><a name="p12716712165623"></a>Enables an IRQ. </p>
</td>
</tr>
<tr id="row806192137165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1096590177165623"><a name="p1096590177165623"></a><a name="p1096590177165623"></a><a href="osal.md#gaf6ae039d209e46d45c683aeda3e7cd28">OsalDisableIrq</a> (uint32_t irqId)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p977613132165623"><a name="p977613132165623"></a><a name="p977613132165623"></a>int32_t </p>
<p id="p374521958165623"><a name="p374521958165623"></a><a name="p374521958165623"></a>Disables an IRQ. </p>
</td>
</tr>
<tr id="row1248268866165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p691537245165623"><a name="p691537245165623"></a><a name="p691537245165623"></a><a href="osal.md#ga0a1c85eaad6c1588ed091e0e89b74ed2">OsalMemAlloc</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p352769943165623"><a name="p352769943165623"></a><a name="p352769943165623"></a>void * </p>
<p id="p1712773560165623"><a name="p1712773560165623"></a><a name="p1712773560165623"></a>Allocates memory of a specified size. </p>
</td>
</tr>
<tr id="row185352540165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1047360178165623"><a name="p1047360178165623"></a><a name="p1047360178165623"></a><a href="osal.md#ga7a6d0f6400e835bcbe9ec655bc9f43ee">OsalMemCalloc</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1766237619165623"><a name="p1766237619165623"></a><a name="p1766237619165623"></a>void * </p>
<p id="p678381150165623"><a name="p678381150165623"></a><a name="p678381150165623"></a>Allocates memory of a specified size, and clears the allocated memory. </p>
</td>
</tr>
<tr id="row677614660165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1147864412165623"><a name="p1147864412165623"></a><a name="p1147864412165623"></a><a href="osal.md#gaf6d1b6e5583d9e1ca5abf5048bb3bad9">OsalMemAllocAlign</a> (size_t alignment, size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1724491271165623"><a name="p1724491271165623"></a><a name="p1724491271165623"></a>void * </p>
<p id="p1653052730165623"><a name="p1653052730165623"></a><a name="p1653052730165623"></a>Allocates memory of a specified size, and aligns the memory address on a given boundary. </p>
</td>
</tr>
<tr id="row1242173390165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p352533371165623"><a name="p352533371165623"></a><a name="p352533371165623"></a><a href="osal.md#ga20dc9c415433effea4d481180a50cfa1">OsalMemFree</a> (void *mem)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p285701331165623"><a name="p285701331165623"></a><a name="p285701331165623"></a>void </p>
<p id="p156280550165623"><a name="p156280550165623"></a><a name="p156280550165623"></a>Releases memory. </p>
</td>
</tr>
<tr id="row490020760165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p862957425165623"><a name="p862957425165623"></a><a name="p862957425165623"></a><a href="osal.md#ga9bbc55785f8a533b0b099956bcbe258e">OsalMutexInit</a> (struct <a href="osalmutex.md">OsalMutex</a> *mutex)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1512729169165623"><a name="p1512729169165623"></a><a name="p1512729169165623"></a>int32_t </p>
<p id="p2144432885165623"><a name="p2144432885165623"></a><a name="p2144432885165623"></a>Initializes a mutex. </p>
</td>
</tr>
<tr id="row146402974165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1178773315165623"><a name="p1178773315165623"></a><a name="p1178773315165623"></a><a href="osal.md#gaa37328265ee97277516f6905f90a41b3">OsalMutexDestroy</a> (struct <a href="osalmutex.md">OsalMutex</a> *mutex)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1065977623165623"><a name="p1065977623165623"></a><a name="p1065977623165623"></a>int32_t </p>
<p id="p1174868300165623"><a name="p1174868300165623"></a><a name="p1174868300165623"></a>Destroys a mutex. </p>
</td>
</tr>
<tr id="row1133979376165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2140249421165623"><a name="p2140249421165623"></a><a name="p2140249421165623"></a><a href="osal.md#ga45d893bf49a8fb8caf76fa5d31822e0e">OsalMutexLock</a> (struct <a href="osalmutex.md">OsalMutex</a> *mutex)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1684526508165623"><a name="p1684526508165623"></a><a name="p1684526508165623"></a>int32_t </p>
<p id="p720612726165623"><a name="p720612726165623"></a><a name="p720612726165623"></a>Locks a mutex. </p>
</td>
</tr>
<tr id="row2036775432165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p29412573165623"><a name="p29412573165623"></a><a name="p29412573165623"></a><a href="osal.md#ga57162c8f2e812ef3e5ace498bb85a3b6">OsalMutexTimedLock</a> (struct <a href="osalmutex.md">OsalMutex</a> *mutex, uint32_t ms)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p110477731165623"><a name="p110477731165623"></a><a name="p110477731165623"></a>int32_t </p>
<p id="p477313316165623"><a name="p477313316165623"></a><a name="p477313316165623"></a>Locks a mutex with a specified timeout duration. </p>
</td>
</tr>
<tr id="row1465461261165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1783819364165623"><a name="p1783819364165623"></a><a name="p1783819364165623"></a><a href="osal.md#gae76ffb4db66c988be5209e0dfdc7a35f">OsalMutexUnlock</a> (struct <a href="osalmutex.md">OsalMutex</a> *mutex)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p105161730165623"><a name="p105161730165623"></a><a name="p105161730165623"></a>int32_t </p>
<p id="p1408319695165623"><a name="p1408319695165623"></a><a name="p1408319695165623"></a>Unlocks a mutex. </p>
</td>
</tr>
<tr id="row308577867165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1663982910165623"><a name="p1663982910165623"></a><a name="p1663982910165623"></a><a href="osal.md#ga7e4325c951479e93abe072290162da0b">OsalSemInit</a> (struct <a href="osalsem.md">OsalSem</a> *sem, uint32_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1102770135165623"><a name="p1102770135165623"></a><a name="p1102770135165623"></a>int32_t </p>
<p id="p887956228165623"><a name="p887956228165623"></a><a name="p887956228165623"></a>Initializes a semaphore. </p>
</td>
</tr>
<tr id="row315233242165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p835376092165623"><a name="p835376092165623"></a><a name="p835376092165623"></a><a href="osal.md#ga0000b9ee1421950d5b3a04cbc839c6af">OsalSemWait</a> (struct <a href="osalsem.md">OsalSem</a> *sem, uint32_t ms)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p603704342165623"><a name="p603704342165623"></a><a name="p603704342165623"></a>int32_t </p>
<p id="p973060648165623"><a name="p973060648165623"></a><a name="p973060648165623"></a>Waits for a semaphore. </p>
</td>
</tr>
<tr id="row1551949345165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p190996298165623"><a name="p190996298165623"></a><a name="p190996298165623"></a><a href="osal.md#gadc3205b416d3fc8e1fa9c332b82e634a">OsalSemPost</a> (struct <a href="osalsem.md">OsalSem</a> *sem)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1101645956165623"><a name="p1101645956165623"></a><a name="p1101645956165623"></a>int32_t </p>
<p id="p561592715165623"><a name="p561592715165623"></a><a name="p561592715165623"></a>Releases a semaphore. </p>
</td>
</tr>
<tr id="row1934921909165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1435548446165623"><a name="p1435548446165623"></a><a name="p1435548446165623"></a><a href="osal.md#ga0b6642005b8a128ac01f69385bd6969f">OsalSemDestroy</a> (struct <a href="osalsem.md">OsalSem</a> *sem)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1019408305165623"><a name="p1019408305165623"></a><a name="p1019408305165623"></a>int32_t </p>
<p id="p2129277127165623"><a name="p2129277127165623"></a><a name="p2129277127165623"></a>Destroys a semaphore. </p>
</td>
</tr>
<tr id="row2098102310165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1683577078165623"><a name="p1683577078165623"></a><a name="p1683577078165623"></a><a href="osal.md#gae36a2d6e4e0191273c9f86a918befb5c">OsalSpinInit</a> (<a href="osalspinlock.md">OsalSpinlock</a> *spinlock)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1278395058165623"><a name="p1278395058165623"></a><a name="p1278395058165623"></a>int32_t </p>
<p id="p1611421324165623"><a name="p1611421324165623"></a><a name="p1611421324165623"></a>Initializes a spinlock. </p>
</td>
</tr>
<tr id="row1842124494165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1541000989165623"><a name="p1541000989165623"></a><a name="p1541000989165623"></a><a href="osal.md#gacd3824f292ddef395bd1a4a7b5546470">OsalSpinDestroy</a> (<a href="osalspinlock.md">OsalSpinlock</a> *spinlock)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p414483750165623"><a name="p414483750165623"></a><a name="p414483750165623"></a>int32_t </p>
<p id="p1251888044165623"><a name="p1251888044165623"></a><a name="p1251888044165623"></a>Destroys a spinlock. </p>
</td>
</tr>
<tr id="row636390175165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p421965479165623"><a name="p421965479165623"></a><a name="p421965479165623"></a><a href="osal.md#gae1c4b9ac8ea2a4820d73c20ae017dbd7">OsalSpinLock</a> (<a href="osalspinlock.md">OsalSpinlock</a> *spinlock)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1982572415165623"><a name="p1982572415165623"></a><a name="p1982572415165623"></a>int32_t </p>
<p id="p744473012165623"><a name="p744473012165623"></a><a name="p744473012165623"></a>Obtains a spinlock. </p>
</td>
</tr>
<tr id="row483533597165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p295433032165623"><a name="p295433032165623"></a><a name="p295433032165623"></a><a href="osal.md#gada1f1826b19dc900af370a2bcd9681b9">OsalSpinUnlock</a> (<a href="osalspinlock.md">OsalSpinlock</a> *spinlock)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p890646973165623"><a name="p890646973165623"></a><a name="p890646973165623"></a>int32_t </p>
<p id="p341584789165623"><a name="p341584789165623"></a><a name="p341584789165623"></a>Releases a spinlock. </p>
</td>
</tr>
<tr id="row709063055165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p955184498165623"><a name="p955184498165623"></a><a name="p955184498165623"></a><a href="osal.md#ga7d409ec573a06078112a8ffae14afce5">OsalSpinLockIrq</a> (<a href="osalspinlock.md">OsalSpinlock</a> *spinlock)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1190489415165623"><a name="p1190489415165623"></a><a name="p1190489415165623"></a>int32_t </p>
<p id="p1223160965165623"><a name="p1223160965165623"></a><a name="p1223160965165623"></a>Obtains a spinlock and disables the IRQ. </p>
</td>
</tr>
<tr id="row49035754165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1960362418165623"><a name="p1960362418165623"></a><a name="p1960362418165623"></a><a href="osal.md#ga7d7848d572fbda413b3b5770e95a234e">OsalSpinUnlockIrq</a> (<a href="osalspinlock.md">OsalSpinlock</a> *spinlock)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p868816665165623"><a name="p868816665165623"></a><a name="p868816665165623"></a>int32_t </p>
<p id="p1462554115165623"><a name="p1462554115165623"></a><a name="p1462554115165623"></a>Releases a spinlock and enables the IRQ. </p>
</td>
</tr>
<tr id="row1249828832165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1697895417165623"><a name="p1697895417165623"></a><a name="p1697895417165623"></a><a href="osal.md#gab711d8d56055e78dd85f84bc530a4d3f">OsalSpinLockIrqSave</a> (<a href="osalspinlock.md">OsalSpinlock</a> *spinlock, uint32_t *flags)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p105648173165623"><a name="p105648173165623"></a><a name="p105648173165623"></a>int32_t </p>
<p id="p584531183165623"><a name="p584531183165623"></a><a name="p584531183165623"></a>Obtains a spinlock, disables the IRQ, and saves its status. </p>
</td>
</tr>
<tr id="row1746825581165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p793393701165623"><a name="p793393701165623"></a><a name="p793393701165623"></a><a href="osal.md#ga3be4dbde6c9ae740b012e49ab90e7a8a">OsalSpinUnlockIrqRestore</a> (<a href="osalspinlock.md">OsalSpinlock</a> *spinlock, uint32_t *flags)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1776124426165623"><a name="p1776124426165623"></a><a name="p1776124426165623"></a>int32_t </p>
<p id="p515425438165623"><a name="p515425438165623"></a><a name="p515425438165623"></a>Releases a spinlock, enables the IRQ, and restores the saved IRQ status. </p>
</td>
</tr>
<tr id="row1490565797165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1752423603165623"><a name="p1752423603165623"></a><a name="p1752423603165623"></a><a href="osal.md#gad598b3f4b91f5e6aeeaf7b8a6e507f1e">OsalThreadCreate</a> (struct <a href="osalthread.md">OsalThread</a> *thread, <a href="osal.md#ga21ea0f87d53e65ec86a424c532d688d8">OsalThreadEntry</a> threadEntry, void *entryPara)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p179674656165623"><a name="p179674656165623"></a><a name="p179674656165623"></a>int32_t </p>
<p id="p33045508165623"><a name="p33045508165623"></a><a name="p33045508165623"></a>Creates a thread. </p>
</td>
</tr>
<tr id="row282513083165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1545674982165623"><a name="p1545674982165623"></a><a name="p1545674982165623"></a><a href="osal.md#ga74c93bd48d27cde830451f63b224307a">OsalThreadStart</a> (struct <a href="osalthread.md">OsalThread</a> *thread, const struct <a href="osalthreadparam.md">OsalThreadParam</a> *param)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p815260927165623"><a name="p815260927165623"></a><a name="p815260927165623"></a>int32_t </p>
<p id="p1258191048165623"><a name="p1258191048165623"></a><a name="p1258191048165623"></a>Starts a thread. </p>
</td>
</tr>
<tr id="row1368046918165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p998185607165623"><a name="p998185607165623"></a><a name="p998185607165623"></a><a href="osal.md#ga223ce6b94770348a93168525c536e6f9">OsalThreadDestroy</a> (struct <a href="osalthread.md">OsalThread</a> *thread)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1556317104165623"><a name="p1556317104165623"></a><a name="p1556317104165623"></a>int32_t </p>
<p id="p1701409470165623"><a name="p1701409470165623"></a><a name="p1701409470165623"></a>Destroys a thread. </p>
</td>
</tr>
<tr id="row522086422165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p615114615165623"><a name="p615114615165623"></a><a name="p615114615165623"></a><a href="osal.md#gad556075f625d01557c0075a2c092a1da">OsalThreadSuspend</a> (struct <a href="osalthread.md">OsalThread</a> *thread)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1926547508165623"><a name="p1926547508165623"></a><a name="p1926547508165623"></a>int32_t </p>
<p id="p1034445340165623"><a name="p1034445340165623"></a><a name="p1034445340165623"></a>Suspends a thread. </p>
</td>
</tr>
<tr id="row6803221165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1307457806165623"><a name="p1307457806165623"></a><a name="p1307457806165623"></a><a href="osal.md#ga32f0b5c622518b7453f758d95b137a94">OsalThreadResume</a> (struct <a href="osalthread.md">OsalThread</a> *thread)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p61965242165623"><a name="p61965242165623"></a><a name="p61965242165623"></a>int32_t </p>
<p id="p1212126702165623"><a name="p1212126702165623"></a><a name="p1212126702165623"></a>Resumes a thread. </p>
</td>
</tr>
<tr id="row2040556564165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1551605181165623"><a name="p1551605181165623"></a><a name="p1551605181165623"></a><a href="osal.md#ga8b9ca3498c54b11dcbe88a2a456f23ab">OsalSleep</a> (uint32_t sec)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p829221676165623"><a name="p829221676165623"></a><a name="p829221676165623"></a>void </p>
<p id="p226493745165623"><a name="p226493745165623"></a><a name="p226493745165623"></a>Describes thread sleep, in seconds. </p>
</td>
</tr>
<tr id="row284502600165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2055524601165623"><a name="p2055524601165623"></a><a name="p2055524601165623"></a><a href="osal.md#ga2361dc099952df28aaef8968f9f4b9a7">OsalMSleep</a> (uint32_t ms)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p455163764165623"><a name="p455163764165623"></a><a name="p455163764165623"></a>void </p>
<p id="p1131915711165623"><a name="p1131915711165623"></a><a name="p1131915711165623"></a>Describes thread sleep, in milliseconds. </p>
</td>
</tr>
<tr id="row1683536410165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1637355767165623"><a name="p1637355767165623"></a><a name="p1637355767165623"></a><a href="osal.md#ga649d3090dcf9ba0e22649e11ac40831f">OsalGetTime</a> (<a href="osaltimespec.md">OsalTimespec</a> *<a href="time.md#gae7841e681c8c9d59818568d39553642c">time</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2032262552165623"><a name="p2032262552165623"></a><a name="p2032262552165623"></a>int32_t </p>
<p id="p632936499165623"><a name="p632936499165623"></a><a name="p632936499165623"></a>Obtains the second and microsecond time. </p>
</td>
</tr>
<tr id="row1889472351165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p561235483165623"><a name="p561235483165623"></a><a name="p561235483165623"></a><a href="osal.md#ga36b0af6646f887175993e78391a5cabc">OsalDiffTime</a> (const <a href="osaltimespec.md">OsalTimespec</a> *start, const <a href="osaltimespec.md">OsalTimespec</a> *end, <a href="osaltimespec.md">OsalTimespec</a> *diff)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1571594259165623"><a name="p1571594259165623"></a><a name="p1571594259165623"></a>int32_t </p>
<p id="p1090301452165623"><a name="p1090301452165623"></a><a name="p1090301452165623"></a>Obtains time difference. </p>
</td>
</tr>
<tr id="row2067543300165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p591757482165623"><a name="p591757482165623"></a><a name="p591757482165623"></a><a href="osal.md#gaf91cb1945b66e324fbb0761aa2f98ea3">OsalGetSysTimeMs</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2039136907165623"><a name="p2039136907165623"></a><a name="p2039136907165623"></a>uint64_t </p>
<p id="p1369089538165623"><a name="p1369089538165623"></a><a name="p1369089538165623"></a>Obtains the system time. </p>
</td>
</tr>
<tr id="row1650816765165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2081621496165623"><a name="p2081621496165623"></a><a name="p2081621496165623"></a><a href="osal.md#ga82ddd682a2441a22dd6148f634a6cea4">OsalMDelay</a> (uint32_t ms)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p657445140165623"><a name="p657445140165623"></a><a name="p657445140165623"></a>void </p>
<p id="p1292730393165623"><a name="p1292730393165623"></a><a name="p1292730393165623"></a>Describes thread delay, in milliseconds. </p>
</td>
</tr>
<tr id="row1179717482165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1813482650165623"><a name="p1813482650165623"></a><a name="p1813482650165623"></a><a href="osal.md#ga7ae78fa3318a82dbd769827d4f373958">OsalUDelay</a> (uint32_t us)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2122912964165623"><a name="p2122912964165623"></a><a name="p2122912964165623"></a>void </p>
<p id="p904704149165623"><a name="p904704149165623"></a><a name="p904704149165623"></a>Describes thread delay, in microseconds. </p>
</td>
</tr>
<tr id="row303199728165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1446858168165623"><a name="p1446858168165623"></a><a name="p1446858168165623"></a><a href="osal.md#ga879d9a437e1423021f95cb9341f0d6af">OsalTimerCreate</a> (<a href="osaltimer.md">OsalTimer</a> *timer, uint32_t interval, <a href="osal.md#gaf3e7a12075b25df5971049d8cd77c25c">OsalTimerFunc</a> func, uintptr_t arg)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1024565842165623"><a name="p1024565842165623"></a><a name="p1024565842165623"></a>int32_t </p>
<p id="p1141695587165623"><a name="p1141695587165623"></a><a name="p1141695587165623"></a>Creates a timer. </p>
</td>
</tr>
<tr id="row144332347165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2076569546165623"><a name="p2076569546165623"></a><a name="p2076569546165623"></a><a href="osal.md#gab754f3522245e6b2f9ee1cdecae62b52">OsalTimerDelete</a> (<a href="osaltimer.md">OsalTimer</a> *timer)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1816208496165623"><a name="p1816208496165623"></a><a name="p1816208496165623"></a>int32_t </p>
<p id="p1087425891165623"><a name="p1087425891165623"></a><a name="p1087425891165623"></a>Deletes a timer. </p>
</td>
</tr>
<tr id="row1560868133165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1702444520165623"><a name="p1702444520165623"></a><a name="p1702444520165623"></a><a href="osal.md#gaf2e49d5b01b49e5f64a7701da8667141">OsalTimerStartOnce</a> (<a href="osaltimer.md">OsalTimer</a> *timer)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p691469618165623"><a name="p691469618165623"></a><a name="p691469618165623"></a>int32_t </p>
<p id="p1238317556165623"><a name="p1238317556165623"></a><a name="p1238317556165623"></a>Starts a timer. </p>
</td>
</tr>
<tr id="row518327446165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1847667348165623"><a name="p1847667348165623"></a><a name="p1847667348165623"></a><a href="osal.md#ga575e4f41359c737ab9690ab28838b99f">OsalTimerStartLoop</a> (<a href="osaltimer.md">OsalTimer</a> *timer)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p920540631165623"><a name="p920540631165623"></a><a name="p920540631165623"></a>int32_t </p>
<p id="p591571087165623"><a name="p591571087165623"></a><a name="p591571087165623"></a>Starts a periodic timer. </p>
</td>
</tr>
<tr id="row1052020957165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1472257590165623"><a name="p1472257590165623"></a><a name="p1472257590165623"></a><a href="osal.md#ga49c2fe3f54d548fe5ec0d03a79691376">OsalTimerSetTimeout</a> (<a href="osaltimer.md">OsalTimer</a> *timer, uint32_t interval)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p214170610165623"><a name="p214170610165623"></a><a name="p214170610165623"></a>int32_t </p>
<p id="p1520490500165623"><a name="p1520490500165623"></a><a name="p1520490500165623"></a>Sets the interval of a timer. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section281237531165623"></a>

## **Macro Definition **<a name="section1226510658165623"></a>

## OSAL\_READB<a name="ga3de1529efbdabd4fb2f144c6f48df70b"></a>

```
#define OSAL_READB( address)   readb(address)
```

 **Description:**

Reads one byte of data from an I/O address space. 

**Parameters:**

<a name="table1313004823165623"></a>
<table><thead align="left"><tr id="row854687516165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1405351892165623"><a name="p1405351892165623"></a><a name="p1405351892165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1914779234165623"><a name="p1914779234165623"></a><a name="p1914779234165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row56281953165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">address</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the address to read. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the byte.

## OSAL\_READL<a name="ga14ce14451b2484b2e268a38757237f41"></a>

```
#define OSAL_READL( address)   readl(address)
```

 **Description:**

Reads an integer from an I/O address space. 

**Parameters:**

<a name="table398175257165623"></a>
<table><thead align="left"><tr id="row127687859165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p695882418165623"><a name="p695882418165623"></a><a name="p695882418165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1224571591165623"><a name="p1224571591165623"></a><a name="p1224571591165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row857692766165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">address</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the address to read. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the integer.

## OSAL\_READW<a name="ga8bd523f234f24415fe733addd113e60b"></a>

```
#define OSAL_READW( address)   readw(address)
```

 **Description:**

Reads a short integer from an I/O address space. 

**Parameters:**

<a name="table123558977165623"></a>
<table><thead align="left"><tr id="row2121410104165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1070768230165623"><a name="p1070768230165623"></a><a name="p1070768230165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1165300610165623"><a name="p1165300610165623"></a><a name="p1165300610165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1702014074165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">address</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the address to read. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the short integer.

## OSAL\_WRITEB<a name="ga48e1f404639550c229aee3ec35a06d79"></a>

```
#define OSAL_WRITEB( value,  address )   writeb(value, address)
```

 **Description:**

Writes one byte of data into an I/O address space. 

**Parameters:**

<a name="table1883215925165623"></a>
<table><thead align="left"><tr id="row1155006377165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1401611881165623"><a name="p1401611881165623"></a><a name="p1401611881165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2012687389165623"><a name="p2012687389165623"></a><a name="p2012687389165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row73642870165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the data to write. </td>
</tr>
<tr id="row1233101470165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">address</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the address to write.</td>
</tr>
</tbody>
</table>

## OSAL\_WRITEL<a name="gaba47d67efad3ad9d1a33a35d2982bd49"></a>

```
#define OSAL_WRITEL( value,  address )   writel(value, address)
```

 **Description:**

Writes an integer into an I/O address space. 

**Parameters:**

<a name="table1319007738165623"></a>
<table><thead align="left"><tr id="row169584212165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1098705384165623"><a name="p1098705384165623"></a><a name="p1098705384165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p569037695165623"><a name="p569037695165623"></a><a name="p569037695165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row568940135165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the data to write. </td>
</tr>
<tr id="row1116167588165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">address</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the address to write.</td>
</tr>
</tbody>
</table>

## OSAL\_WRITEW<a name="ga3358a86c6bbb6f02ab108964962f441f"></a>

```
#define OSAL_WRITEW( value,  address )   writew(value, address)
```

 **Description:**

Writes a short integer into an I/O address space. 

**Parameters:**

<a name="table1085716697165623"></a>
<table><thead align="left"><tr id="row1470474802165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p355795464165623"><a name="p355795464165623"></a><a name="p355795464165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p505528617165623"><a name="p505528617165623"></a><a name="p505528617165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row790015200165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the data to write. </td>
</tr>
<tr id="row63590264165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">address</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the address to write.</td>
</tr>
</tbody>
</table>

## **Enumeration Type **<a name="section1297392036165623"></a>

## OSAL\_IRQ\_TRIGGER\_MODE<a name="ga78cd126b10424753db6f39f9b72ea124"></a>

```
enum [OSAL_IRQ_TRIGGER_MODE](osal.md#ga78cd126b10424753db6f39f9b72ea124)
```

 **Description:**

Enumerates interrupt trigger modes. 

<a name="table625841585165623"></a>
<table><thead align="left"><tr id="row1422237661165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1208648814165623"><a name="p1208648814165623"></a><a name="p1208648814165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p266566755165623"><a name="p266566755165623"></a><a name="p266566755165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1896441293165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga78cd126b10424753db6f39f9b72ea124aa0252cbf1f560b1d9951da4dfe896a1d"><a name="gga78cd126b10424753db6f39f9b72ea124aa0252cbf1f560b1d9951da4dfe896a1d"></a><a name="gga78cd126b10424753db6f39f9b72ea124aa0252cbf1f560b1d9951da4dfe896a1d"></a></strong>OSAL_IRQF_TRIGGER_NONE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p880400350165623"><a name="p880400350165623"></a><a name="p880400350165623"></a>Edge-triggered is not set </p>
 </td>
</tr>
<tr id="row1313396295165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga78cd126b10424753db6f39f9b72ea124ab98297946a624d99a3fad6adac899f2c"><a name="gga78cd126b10424753db6f39f9b72ea124ab98297946a624d99a3fad6adac899f2c"></a><a name="gga78cd126b10424753db6f39f9b72ea124ab98297946a624d99a3fad6adac899f2c"></a></strong>OSAL_IRQF_TRIGGER_RISING </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p285859425165623"><a name="p285859425165623"></a><a name="p285859425165623"></a>Rising edge triggered </p>
 </td>
</tr>
<tr id="row1389702514165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga78cd126b10424753db6f39f9b72ea124a3088c6875fb44d05fd3a64a3d158295b"><a name="gga78cd126b10424753db6f39f9b72ea124a3088c6875fb44d05fd3a64a3d158295b"></a><a name="gga78cd126b10424753db6f39f9b72ea124a3088c6875fb44d05fd3a64a3d158295b"></a></strong>OSAL_IRQF_TRIGGER_FALLING </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1637993071165623"><a name="p1637993071165623"></a><a name="p1637993071165623"></a>Falling edge triggered </p>
 </td>
</tr>
<tr id="row950547270165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga78cd126b10424753db6f39f9b72ea124a9a997189554c568f66dd994a9f9e203d"><a name="gga78cd126b10424753db6f39f9b72ea124a9a997189554c568f66dd994a9f9e203d"></a><a name="gga78cd126b10424753db6f39f9b72ea124a9a997189554c568f66dd994a9f9e203d"></a></strong>OSAL_IRQF_TRIGGER_HIGH </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1413833162165623"><a name="p1413833162165623"></a><a name="p1413833162165623"></a>High-level triggered </p>
 </td>
</tr>
<tr id="row91306269165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga78cd126b10424753db6f39f9b72ea124a7768ec0b5be5e88cfeb07dea96cd5865"><a name="gga78cd126b10424753db6f39f9b72ea124a7768ec0b5be5e88cfeb07dea96cd5865"></a><a name="gga78cd126b10424753db6f39f9b72ea124a7768ec0b5be5e88cfeb07dea96cd5865"></a></strong>OSAL_IRQF_TRIGGER_LOW </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p88114037165623"><a name="p88114037165623"></a><a name="p88114037165623"></a>Low-level triggered </p>
 </td>
</tr>
</tbody>
</table>

## OSAL\_THREAD\_PRIORITY<a name="gab8c099a9c39fdde73c74b3f7367be5d0"></a>

```
enum [OSAL_THREAD_PRIORITY](osal.md#gab8c099a9c39fdde73c74b3f7367be5d0)
```

 **Description:**

Enumerates thread priorities. 

<a name="table1431699371165623"></a>
<table><thead align="left"><tr id="row162254281165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1320256811165623"><a name="p1320256811165623"></a><a name="p1320256811165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1196553774165623"><a name="p1196553774165623"></a><a name="p1196553774165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1086175818165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggab8c099a9c39fdde73c74b3f7367be5d0a077e53412997ddef962069a7cea4def6"><a name="ggab8c099a9c39fdde73c74b3f7367be5d0a077e53412997ddef962069a7cea4def6"></a><a name="ggab8c099a9c39fdde73c74b3f7367be5d0a077e53412997ddef962069a7cea4def6"></a></strong>OSAL_THREAD_PRI_LOW </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1694704253165623"><a name="p1694704253165623"></a><a name="p1694704253165623"></a>Low priority </p>
 </td>
</tr>
<tr id="row1911446515165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggab8c099a9c39fdde73c74b3f7367be5d0abc9ef48a9fc95f359a5c4d52041111e5"><a name="ggab8c099a9c39fdde73c74b3f7367be5d0abc9ef48a9fc95f359a5c4d52041111e5"></a><a name="ggab8c099a9c39fdde73c74b3f7367be5d0abc9ef48a9fc95f359a5c4d52041111e5"></a></strong>OSAL_THREAD_PRI_DEFAULT </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1329652627165623"><a name="p1329652627165623"></a><a name="p1329652627165623"></a>Default priority </p>
 </td>
</tr>
<tr id="row1899598873165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggab8c099a9c39fdde73c74b3f7367be5d0a61697eda5c5265d6d62271d00c098121"><a name="ggab8c099a9c39fdde73c74b3f7367be5d0a61697eda5c5265d6d62271d00c098121"></a><a name="ggab8c099a9c39fdde73c74b3f7367be5d0a61697eda5c5265d6d62271d00c098121"></a></strong>OSAL_THREAD_PRI_HIGH </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2083394635165623"><a name="p2083394635165623"></a><a name="p2083394635165623"></a>High priority </p>
 </td>
</tr>
<tr id="row93702436165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggab8c099a9c39fdde73c74b3f7367be5d0a9e66435e6d967adc68606b359a8753bd"><a name="ggab8c099a9c39fdde73c74b3f7367be5d0a9e66435e6d967adc68606b359a8753bd"></a><a name="ggab8c099a9c39fdde73c74b3f7367be5d0a9e66435e6d967adc68606b359a8753bd"></a></strong>OSAL_THREAD_PRI_HIGHEST </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1083435066165623"><a name="p1083435066165623"></a><a name="p1083435066165623"></a>Highest priority </p>
 </td>
</tr>
</tbody>
</table>

## **Function **<a name="section740670116165623"></a>

## OsalAtomicDec\(\)<a name="gaa411f380e6b21c8467260030ceee38ff"></a>

```
void OsalAtomicDec ([OsalAtomic](osalatomic.md) * v)
```

 **Description:**

Decrements the counter of an atomic by 1. 

**Parameters:**

<a name="table138781666165623"></a>
<table><thead align="left"><tr id="row1710277925165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p340691881165623"><a name="p340691881165623"></a><a name="p340691881165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1599017378165623"><a name="p1599017378165623"></a><a name="p1599017378165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row228693015165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">v</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the atomic <a href="osalatomic.md">OsalAtomic</a>.</td>
</tr>
</tbody>
</table>

## OsalAtomicInc\(\)<a name="ga11214c11a9b875cb8ba0a67aeccc6ac9"></a>

```
void OsalAtomicInc ([OsalAtomic](osalatomic.md) * v)
```

 **Description:**

Increments the counter of an atomic by 1. 

**Parameters:**

<a name="table644837386165623"></a>
<table><thead align="left"><tr id="row534548837165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1044756051165623"><a name="p1044756051165623"></a><a name="p1044756051165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p479889435165623"><a name="p479889435165623"></a><a name="p479889435165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row324715954165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">v</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the atomic <a href="osalatomic.md">OsalAtomic</a>.</td>
</tr>
</tbody>
</table>

## OsalAtomicRead\(\)<a name="gaf7b7a860f5cf11bda3008ce16a5d79d5"></a>

```
int32_t OsalAtomicRead (const [OsalAtomic](osalatomic.md) * v)
```

 **Description:**

Reads the counter of an atomic. 

**Parameters:**

<a name="table1525568309165623"></a>
<table><thead align="left"><tr id="row1606817447165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1046508966165623"><a name="p1046508966165623"></a><a name="p1046508966165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1492675511165623"><a name="p1492675511165623"></a><a name="p1492675511165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1759558449165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">v</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the atomic <a href="osalatomic.md">OsalAtomic</a>.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the counter. 

## OsalAtomicSet\(\)<a name="ga0b82ac10305c7ec5ae46707034b866c3"></a>

```
void OsalAtomicSet ([OsalAtomic](osalatomic.md) * v, int32_t counter )
```

 **Description:**

Sets the counter for an atomic. 

**Parameters:**

<a name="table1567104241165623"></a>
<table><thead align="left"><tr id="row131631053165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p835064929165623"><a name="p835064929165623"></a><a name="p835064929165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p600955485165623"><a name="p600955485165623"></a><a name="p600955485165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1227697479165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">v</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the atomic <a href="osalatomic.md">OsalAtomic</a>. </td>
</tr>
<tr id="row720563301165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">counter</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the counter to set.</td>
</tr>
</tbody>
</table>

## OsalClearBit\(\)<a name="gae3e5b84f326aa1a2c4b8427509f80cd9"></a>

```
void OsalClearBit (unsigned long nr, volatile unsigned long * addr )
```

 **Description:**

Clears the value of a specified bit of the variable. 

**Parameters:**

<a name="table78226289165623"></a>
<table><thead align="left"><tr id="row478848532165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1847945214165623"><a name="p1847945214165623"></a><a name="p1847945214165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p660610677165623"><a name="p660610677165623"></a><a name="p660610677165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row908551577165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">nr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the bit of the variable. The value ranges from <strong id="b2067587763165623"><a name="b2067587763165623"></a><a name="b2067587763165623"></a>0</strong> to <strong id="b574106612165623"><a name="b574106612165623"></a><a name="b574106612165623"></a>31</strong>. </td>
</tr>
<tr id="row488382200165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">addr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the variable.</td>
</tr>
</tbody>
</table>

## OsalDiffTime\(\)<a name="ga36b0af6646f887175993e78391a5cabc"></a>

```
int32_t OsalDiffTime (const [OsalTimespec](osaltimespec.md) * start, const [OsalTimespec](osaltimespec.md) * end, [OsalTimespec](osaltimespec.md) * diff )
```

 **Description:**

Obtains time difference. 

**Parameters:**

<a name="table41517840165623"></a>
<table><thead align="left"><tr id="row1708970913165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p712250904165623"><a name="p712250904165623"></a><a name="p712250904165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p73072891165623"><a name="p73072891165623"></a><a name="p73072891165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row428877862165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">start</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the start time <a href="osaltimespec.md">OsalTimespec</a>. </td>
</tr>
<tr id="row177933711165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">end</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the end time <a href="osaltimespec.md">OsalTimespec</a>. </td>
</tr>
<tr id="row867799716165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">diff</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the time difference <a href="osaltimespec.md">OsalTimespec</a>.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns a value listed below: 

<a name="table17154756165623"></a>
<table><thead align="left"><tr id="row1446615737165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p120001912165623"><a name="p120001912165623"></a><a name="p120001912165623"></a>HDF_STATUS </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1299015652165623"><a name="p1299015652165623"></a><a name="p1299015652165623"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1574449116165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2026784834165623"><a name="p2026784834165623"></a><a name="p2026784834165623"></a>HDF_SUCCESS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1479096195165623"><a name="p1479096195165623"></a><a name="p1479096195165623"></a>The operation is successful. </p>
</td>
</tr>
<tr id="row1467466101165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p214478758165623"><a name="p214478758165623"></a><a name="p214478758165623"></a>HDF_ERR_INVALID_PARAM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p899621432165623"><a name="p899621432165623"></a><a name="p899621432165623"></a>Invalid parameter. </p>
</td>
</tr>
</tbody>
</table>

## OsalDisableIrq\(\)<a name="gaf6ae039d209e46d45c683aeda3e7cd28"></a>

```
int32_t OsalDisableIrq (uint32_t irqId)
```

 **Description:**

Disables an IRQ. 

**Parameters:**

<a name="table732345227165623"></a>
<table><thead align="left"><tr id="row188158478165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p890135291165623"><a name="p890135291165623"></a><a name="p890135291165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p729121489165623"><a name="p729121489165623"></a><a name="p729121489165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2026681606165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">irqId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the IRQ ID.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns a value listed below: 

<a name="table1984281670165623"></a>
<table><thead align="left"><tr id="row1836984154165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1068355171165623"><a name="p1068355171165623"></a><a name="p1068355171165623"></a>HDF_STATUS </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p227913992165623"><a name="p227913992165623"></a><a name="p227913992165623"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row97892189165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p742118780165623"><a name="p742118780165623"></a><a name="p742118780165623"></a>HDF_SUCCESS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1067039530165623"><a name="p1067039530165623"></a><a name="p1067039530165623"></a>The operation is successful. </p>
</td>
</tr>
<tr id="row1978042503165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p787431276165623"><a name="p787431276165623"></a><a name="p787431276165623"></a>HDF_ERR_INVALID_PARAM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1245316522165623"><a name="p1245316522165623"></a><a name="p1245316522165623"></a>Invalid parameter. </p>
</td>
</tr>
</tbody>
</table>

## OsalEnableIrq\(\)<a name="ga7f27c6171678ab8cf925660068ac38ff"></a>

```
int32_t OsalEnableIrq (uint32_t irqId)
```

 **Description:**

Enables an IRQ. 

**Parameters:**

<a name="table553766135165623"></a>
<table><thead align="left"><tr id="row917944147165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p556024102165623"><a name="p556024102165623"></a><a name="p556024102165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p753913381165623"><a name="p753913381165623"></a><a name="p753913381165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1432447010165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">irqId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the IRQ ID.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns a value listed below: 

<a name="table752550639165623"></a>
<table><thead align="left"><tr id="row788804286165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1324092823165623"><a name="p1324092823165623"></a><a name="p1324092823165623"></a>HDF_STATUS </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1711006562165623"><a name="p1711006562165623"></a><a name="p1711006562165623"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1067021509165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1621381314165623"><a name="p1621381314165623"></a><a name="p1621381314165623"></a>HDF_SUCCESS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1168065162165623"><a name="p1168065162165623"></a><a name="p1168065162165623"></a>The operation is successful. </p>
</td>
</tr>
<tr id="row1303524904165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p387736481165623"><a name="p387736481165623"></a><a name="p387736481165623"></a>HDF_ERR_INVALID_PARAM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1513687919165623"><a name="p1513687919165623"></a><a name="p1513687919165623"></a>Invalid parameter. </p>
</td>
</tr>
</tbody>
</table>

## OsalFileClose\(\)<a name="ga8786ab2baa8669e79173ab7ab47d67bb"></a>

```
void OsalFileClose ([OsalFile](osalfile.md) * file)
```

 **Description:**

Closes a file. 

**Parameters:**

<a name="table1302716743165623"></a>
<table><thead align="left"><tr id="row53815581165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1801706113165623"><a name="p1801706113165623"></a><a name="p1801706113165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2136245096165623"><a name="p2136245096165623"></a><a name="p2136245096165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row499760965165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">file</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the file type <a href="osalfile.md">OsalFile</a>.</td>
</tr>
</tbody>
</table>

## OsalFileLseek\(\)<a name="gaada4d66f4bb789bb4113e4084da6dea2"></a>

```
off_t OsalFileLseek ([OsalFile](osalfile.md) * file, off_t offset, int32_t whence )
```

 **Description:**

Sets the file read/write offset. 

**Parameters:**

<a name="table1058004531165623"></a>
<table><thead align="left"><tr id="row1724427235165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p953144432165623"><a name="p953144432165623"></a><a name="p953144432165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1372900187165623"><a name="p1372900187165623"></a><a name="p1372900187165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row352548158165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">file</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the file type <a href="osalfile.md">OsalFile</a>. </td>
</tr>
<tr id="row1161179569165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">offset</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the offset to set. </td>
</tr>
<tr id="row1246650657165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">whence</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the position from which the offset is to set. For details, see <a href="osal.md#ga110fc469c88e83828679a3dedb4b5f3d">OSAL_SEEK_SET</a>.</td>
</tr>
</tbody>
</table>

## OsalFileOpen\(\)<a name="ga6707125b6ac5e13912a181877f18f292"></a>

```
int32_t OsalFileOpen ([OsalFile](osalfile.md) * file, const char * path, int flags, uint32_t rights )
```

 **Description:**

Opens a file. 

**Parameters:**

<a name="table1246482200165623"></a>
<table><thead align="left"><tr id="row2032619327165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p31893462165623"><a name="p31893462165623"></a><a name="p31893462165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1835027301165623"><a name="p1835027301165623"></a><a name="p1835027301165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1968761850165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">file</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the file type <a href="osalfile.md">OsalFile</a>. </td>
</tr>
<tr id="row1380465598165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">path</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the name of the file to open. </td>
</tr>
<tr id="row165648772165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">flags</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the mode of opening the file. For details, see <a href="osal.md#gab208afeed35dd98f6a0ccf807e9c722d">OSAL_O_RD_ONLY</a>. </td>
</tr>
<tr id="row923827251165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">rights</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the permissions required for opening the file. For details, see <a href="osal.md#ga9cb465f6d142e859258e14199702906e">OSAL_S_IREAD</a>.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns a value listed below: 

<a name="table1842543818165623"></a>
<table><thead align="left"><tr id="row388944868165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1091946478165623"><a name="p1091946478165623"></a><a name="p1091946478165623"></a>HDF_STATUS </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p481541834165623"><a name="p481541834165623"></a><a name="p481541834165623"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row285160338165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1393522307165623"><a name="p1393522307165623"></a><a name="p1393522307165623"></a>HDF_SUCCESS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1800429620165623"><a name="p1800429620165623"></a><a name="p1800429620165623"></a>The operation is successful. </p>
</td>
</tr>
<tr id="row1077099133165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p344054601165623"><a name="p344054601165623"></a><a name="p344054601165623"></a>HDF_FAILURE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p768590573165623"><a name="p768590573165623"></a><a name="p768590573165623"></a>Failed to invoke the system function to open the file. </p>
</td>
</tr>
<tr id="row908858778165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1962120317165623"><a name="p1962120317165623"></a><a name="p1962120317165623"></a>HDF_ERR_INVALID_PARAM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p85879944165623"><a name="p85879944165623"></a><a name="p85879944165623"></a>Invalid parameter. </p>
</td>
</tr>
</tbody>
</table>

## OsalFileRead\(\)<a name="gac8ebc8dc4b9ce9725875868f69fd17a8"></a>

```
ssize_t OsalFileRead ([OsalFile](osalfile.md) * file, void * buf, uint32_t length )
```

 **Description:**

Reads a file. 

**Parameters:**

<a name="table1550343286165623"></a>
<table><thead align="left"><tr id="row1708293793165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1876803846165623"><a name="p1876803846165623"></a><a name="p1876803846165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p200168963165623"><a name="p200168963165623"></a><a name="p200168963165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1984914932165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">file</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the file type <a href="osalfile.md">OsalFile</a>. </td>
</tr>
<tr id="row1677516248165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">buf</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the buffer for storing the content to read. </td>
</tr>
<tr id="row2049501209165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">length</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the length of the content to read.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns a value listed below: 

<a name="table932929741165623"></a>
<table><thead align="left"><tr id="row768530840165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1470607540165623"><a name="p1470607540165623"></a><a name="p1470607540165623"></a>ssize_t </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2105778167165623"><a name="p2105778167165623"></a><a name="p2105778167165623"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row77950682165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p791568240165623"><a name="p791568240165623"></a><a name="p791568240165623"></a>Greater than <strong id="b253371540165623"><a name="b253371540165623"></a><a name="b253371540165623"></a>0</strong> </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p978974708165623"><a name="p978974708165623"></a><a name="p978974708165623"></a>The length of the file content is successfully read. </p>
</td>
</tr>
<tr id="row665997807165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2084412965165623"><a name="p2084412965165623"></a><a name="p2084412965165623"></a>HDF_FAILURE <a href="driverutils.md#ga7e01536ecbe9b17563dd3fe256202a67">HDF_STATUS</a> </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1094648845165623"><a name="p1094648845165623"></a><a name="p1094648845165623"></a>Failed to invoke the system function to read the file. </p>
</td>
</tr>
<tr id="row853576518165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1209745436165623"><a name="p1209745436165623"></a><a name="p1209745436165623"></a>HDF_ERR_INVALID_PARAM <a href="driverutils.md#ga7e01536ecbe9b17563dd3fe256202a67">HDF_STATUS</a> </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p128157800165623"><a name="p128157800165623"></a><a name="p128157800165623"></a>Invalid parameter. </p>
</td>
</tr>
</tbody>
</table>

## OsalFileWrite\(\)<a name="ga305f575f875ff26bb907c67c23dfb16a"></a>

```
ssize_t OsalFileWrite ([OsalFile](osalfile.md) * file, const void * string, uint32_t length )
```

 **Description:**

Writes a file. 

**Parameters:**

<a name="table526944720165623"></a>
<table><thead align="left"><tr id="row370942425165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1782258965165623"><a name="p1782258965165623"></a><a name="p1782258965165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1163682625165623"><a name="p1163682625165623"></a><a name="p1163682625165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row801506512165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">file</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the file type <a href="osalfile.md">OsalFile</a>. </td>
</tr>
<tr id="row864654860165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">string</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the content to write. </td>
</tr>
<tr id="row29894120165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">length</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the length of the content to write.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns a value listed below: 

<a name="table11570968165623"></a>
<table><thead align="left"><tr id="row1633558905165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2055679638165623"><a name="p2055679638165623"></a><a name="p2055679638165623"></a>ssize_t </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p465308349165623"><a name="p465308349165623"></a><a name="p465308349165623"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1699333515165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p625643264165623"><a name="p625643264165623"></a><a name="p625643264165623"></a>Greater than <strong id="b1216556360165623"><a name="b1216556360165623"></a><a name="b1216556360165623"></a>0</strong> </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p628693571165623"><a name="p628693571165623"></a><a name="p628693571165623"></a>The length of the file content is successfully written. </p>
</td>
</tr>
<tr id="row1236466508165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1556773652165623"><a name="p1556773652165623"></a><a name="p1556773652165623"></a>HDF_FAILURE <a href="driverutils.md#ga7e01536ecbe9b17563dd3fe256202a67">HDF_STATUS</a> </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1691229356165623"><a name="p1691229356165623"></a><a name="p1691229356165623"></a>Failed to invoke the system function to write the file. </p>
</td>
</tr>
<tr id="row92208553165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1457709032165623"><a name="p1457709032165623"></a><a name="p1457709032165623"></a>HDF_ERR_INVALID_PARAM <a href="driverutils.md#ga7e01536ecbe9b17563dd3fe256202a67">HDF_STATUS</a> </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1705920383165623"><a name="p1705920383165623"></a><a name="p1705920383165623"></a>Invalid parameter. </p>
</td>
</tr>
</tbody>
</table>

## OsalGetSysTimeMs\(\)<a name="gaf91cb1945b66e324fbb0761aa2f98ea3"></a>

```
uint64_t OsalGetSysTimeMs (void )
```

 **Description:**

Obtains the system time. 

**Returns:**

Returns the system time, in milliseconds. 

## OsalGetTime\(\)<a name="ga649d3090dcf9ba0e22649e11ac40831f"></a>

```
int32_t OsalGetTime ([OsalTimespec](osaltimespec.md) * time)
```

 **Description:**

Obtains the second and microsecond time. 

**Parameters:**

<a name="table1504258401165623"></a>
<table><thead align="left"><tr id="row1855812166165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1244119656165623"><a name="p1244119656165623"></a><a name="p1244119656165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p133845165623"><a name="p133845165623"></a><a name="p133845165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row601874326165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">time</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the time structure <a href="osaltimespec.md">OsalTimespec</a>.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns a value listed below: 

<a name="table889258874165623"></a>
<table><thead align="left"><tr id="row449424210165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p338942076165623"><a name="p338942076165623"></a><a name="p338942076165623"></a>HDF_STATUS </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1805673343165623"><a name="p1805673343165623"></a><a name="p1805673343165623"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row329756367165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1336456608165623"><a name="p1336456608165623"></a><a name="p1336456608165623"></a>HDF_SUCCESS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p83395596165623"><a name="p83395596165623"></a><a name="p83395596165623"></a>The operation is successful. </p>
</td>
</tr>
<tr id="row135798981165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p411805848165623"><a name="p411805848165623"></a><a name="p411805848165623"></a>HDF_FAILURE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p580125841165623"><a name="p580125841165623"></a><a name="p580125841165623"></a>Failed to invoke the system function to obtain time. </p>
</td>
</tr>
<tr id="row935432447165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p336809666165623"><a name="p336809666165623"></a><a name="p336809666165623"></a>HDF_ERR_INVALID_PARAM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p552035479165623"><a name="p552035479165623"></a><a name="p552035479165623"></a>Invalid parameter. </p>
</td>
</tr>
</tbody>
</table>

## OsalIoRemap\(\)<a name="ga281757438906600ef89a13362151d955"></a>

```
static void* OsalIoRemap (unsigned long phys_addr, unsigned long size )
```

 **Description:**

Remaps an I/O physical address to its virtual address. 

**Parameters:**

<a name="table1424385119165623"></a>
<table><thead align="left"><tr id="row368801426165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p270612010165623"><a name="p270612010165623"></a><a name="p270612010165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1089669398165623"><a name="p1089669398165623"></a><a name="p1089669398165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row450348819165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">phys_addr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the I/O physical address. </td>
</tr>
<tr id="row244549186165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">size</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the size of the physical address to remap. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the virtual address.

## OsalIoUnmap\(\)<a name="ga0a845edb56df0a35beeea338dc5121aa"></a>

```
static void OsalIoUnmap (void * addr)
```

 **Description:**

Unmaps an I/O virtual address associated with the physical address. 

The virtual address is the one returned by calling  [OsalIoRemap](osal.md#ga281757438906600ef89a13362151d955).

**Parameters:**

<a name="table1665985462165623"></a>
<table><thead align="left"><tr id="row804524881165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1955305205165623"><a name="p1955305205165623"></a><a name="p1955305205165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1742062324165623"><a name="p1742062324165623"></a><a name="p1742062324165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1329838699165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">addr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the virtual address to unmap.</td>
</tr>
</tbody>
</table>

## OsalMDelay\(\)<a name="ga82ddd682a2441a22dd6148f634a6cea4"></a>

```
void OsalMDelay (uint32_t ms)
```

 **Description:**

Describes thread delay, in milliseconds. 

When a thread invokes this function, the CPU is not released. This function returns after waiting for milliseconds.

**Parameters:**

<a name="table1817380923165623"></a>
<table><thead align="left"><tr id="row74745617165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p608894547165623"><a name="p608894547165623"></a><a name="p608894547165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1395532074165623"><a name="p1395532074165623"></a><a name="p1395532074165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1652337821165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">ms</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the delay time, in milliseconds. </td>
</tr>
</tbody>
</table>

## OsalMemAlloc\(\)<a name="ga0a1c85eaad6c1588ed091e0e89b74ed2"></a>

```
void* OsalMemAlloc (size_t size)
```

 **Description:**

Allocates memory of a specified size. 

**Parameters:**

<a name="table1256140293165623"></a>
<table><thead align="left"><tr id="row1598366504165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p833898279165623"><a name="p833898279165623"></a><a name="p833898279165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1913290905165623"><a name="p1913290905165623"></a><a name="p1913290905165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1190023417165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">size</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the size of memory to allocate.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the pointer to the allocated memory if the operation is successful; returns  **NULL**  otherwise. 

## OsalMemAllocAlign\(\)<a name="gaf6d1b6e5583d9e1ca5abf5048bb3bad9"></a>

```
void* OsalMemAllocAlign (size_t alignment, size_t size )
```

 **Description:**

Allocates memory of a specified size, and aligns the memory address on a given boundary. 

**Parameters:**

<a name="table445460333165623"></a>
<table><thead align="left"><tr id="row679397968165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1070354554165623"><a name="p1070354554165623"></a><a name="p1070354554165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p656892624165623"><a name="p656892624165623"></a><a name="p656892624165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row932230210165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">alignment</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the memory boundary alignment. The value must be a power of 2. </td>
</tr>
<tr id="row505894049165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">size</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the size of memory to allocate.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the pointer to the allocated memory if the operation is successful; returns  **NULL**  otherwise. 

## OsalMemCalloc\(\)<a name="ga7a6d0f6400e835bcbe9ec655bc9f43ee"></a>

```
void* OsalMemCalloc (size_t size)
```

 **Description:**

Allocates memory of a specified size, and clears the allocated memory. 

**Parameters:**

<a name="table1823047325165623"></a>
<table><thead align="left"><tr id="row1635990904165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1366502883165623"><a name="p1366502883165623"></a><a name="p1366502883165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p403033934165623"><a name="p403033934165623"></a><a name="p403033934165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row743124920165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">size</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the size of memory to allocate.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the pointer to the allocated memory if the operation is successful; returns  **NULL**  otherwise. 

## OsalMemFree\(\)<a name="ga20dc9c415433effea4d481180a50cfa1"></a>

```
void OsalMemFree (void * mem)
```

 **Description:**

Releases memory. 

**Parameters:**

<a name="table896853090165623"></a>
<table><thead align="left"><tr id="row979722346165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p656990565165623"><a name="p656990565165623"></a><a name="p656990565165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p649199994165623"><a name="p649199994165623"></a><a name="p649199994165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1839905904165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">mem</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the memory to release. </td>
</tr>
</tbody>
</table>

## OsalMSleep\(\)<a name="ga2361dc099952df28aaef8968f9f4b9a7"></a>

```
void OsalMSleep (uint32_t ms)
```

 **Description:**

Describes thread sleep, in milliseconds. 

When a thread invokes this function, the CPU is released and the thread enters the sleep state.

**Parameters:**

<a name="table585216506165623"></a>
<table><thead align="left"><tr id="row569160165165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1388179129165623"><a name="p1388179129165623"></a><a name="p1388179129165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p358792872165623"><a name="p358792872165623"></a><a name="p358792872165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1407835836165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">ms</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the sleep time, in milliseconds. </td>
</tr>
</tbody>
</table>

## OsalMutexDestroy\(\)<a name="gaa37328265ee97277516f6905f90a41b3"></a>

```
int32_t OsalMutexDestroy (struct [OsalMutex](osalmutex.md) * mutex)
```

 **Description:**

Destroys a mutex. 

**Parameters:**

<a name="table386529053165623"></a>
<table><thead align="left"><tr id="row1192221829165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1720575267165623"><a name="p1720575267165623"></a><a name="p1720575267165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1919411597165623"><a name="p1919411597165623"></a><a name="p1919411597165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1381201593165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">mutex</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the mutex <a href="osalmutex.md">OsalMutex</a>.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns a value listed below: 

<a name="table291084196165623"></a>
<table><thead align="left"><tr id="row285454934165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1600041639165623"><a name="p1600041639165623"></a><a name="p1600041639165623"></a>HDF_STATUS </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p218274775165623"><a name="p218274775165623"></a><a name="p218274775165623"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1206580799165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1739569314165623"><a name="p1739569314165623"></a><a name="p1739569314165623"></a>HDF_SUCCESS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2044086771165623"><a name="p2044086771165623"></a><a name="p2044086771165623"></a>The operation is successful. </p>
</td>
</tr>
<tr id="row1087514114165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1645427897165623"><a name="p1645427897165623"></a><a name="p1645427897165623"></a>HDF_FAILURE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1176061804165623"><a name="p1176061804165623"></a><a name="p1176061804165623"></a>Failed to invoke the system function to destroy the mutex. </p>
</td>
</tr>
<tr id="row698443624165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2119319902165623"><a name="p2119319902165623"></a><a name="p2119319902165623"></a>HDF_ERR_INVALID_PARAM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1395680611165623"><a name="p1395680611165623"></a><a name="p1395680611165623"></a>Invalid parameter. </p>
</td>
</tr>
</tbody>
</table>

## OsalMutexInit\(\)<a name="ga9bbc55785f8a533b0b099956bcbe258e"></a>

```
int32_t OsalMutexInit (struct [OsalMutex](osalmutex.md) * mutex)
```

 **Description:**

Initializes a mutex. 

**Parameters:**

<a name="table1187121495165623"></a>
<table><thead align="left"><tr id="row1543635268165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p194163283165623"><a name="p194163283165623"></a><a name="p194163283165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p314623811165623"><a name="p314623811165623"></a><a name="p314623811165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1643013815165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">mutex</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the mutex <a href="osalmutex.md">OsalMutex</a>.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns a value listed below: 

<a name="table535784955165623"></a>
<table><thead align="left"><tr id="row972072391165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p196311832165623"><a name="p196311832165623"></a><a name="p196311832165623"></a>HDF_STATUS </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1783014152165623"><a name="p1783014152165623"></a><a name="p1783014152165623"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1415537414165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p436566408165623"><a name="p436566408165623"></a><a name="p436566408165623"></a>HDF_SUCCESS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1978629174165623"><a name="p1978629174165623"></a><a name="p1978629174165623"></a>The operation is successful. </p>
</td>
</tr>
<tr id="row1546135968165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p630526760165623"><a name="p630526760165623"></a><a name="p630526760165623"></a>HDF_FAILURE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1160177712165623"><a name="p1160177712165623"></a><a name="p1160177712165623"></a>Failed to invoke the system function to initialize the mutex. </p>
</td>
</tr>
<tr id="row1263571418165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1697420397165623"><a name="p1697420397165623"></a><a name="p1697420397165623"></a>HDF_ERR_INVALID_PARAM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p71069522165623"><a name="p71069522165623"></a><a name="p71069522165623"></a>Invalid parameter. </p>
</td>
</tr>
</tbody>
</table>

## OsalMutexLock\(\)<a name="ga45d893bf49a8fb8caf76fa5d31822e0e"></a>

```
int32_t OsalMutexLock (struct [OsalMutex](osalmutex.md) * mutex)
```

 **Description:**

Locks a mutex. 

**Parameters:**

<a name="table197431743165623"></a>
<table><thead align="left"><tr id="row152080082165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1151202626165623"><a name="p1151202626165623"></a><a name="p1151202626165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2613840165623"><a name="p2613840165623"></a><a name="p2613840165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2098365791165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">mutex</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the mutex <a href="osalmutex.md">OsalMutex</a>.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns a value listed below: 

<a name="table1116808814165623"></a>
<table><thead align="left"><tr id="row713755379165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1029731427165623"><a name="p1029731427165623"></a><a name="p1029731427165623"></a>HDF_STATUS </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p439556500165623"><a name="p439556500165623"></a><a name="p439556500165623"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row616109783165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2004188469165623"><a name="p2004188469165623"></a><a name="p2004188469165623"></a>HDF_SUCCESS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1521595648165623"><a name="p1521595648165623"></a><a name="p1521595648165623"></a>The operation is successful. </p>
</td>
</tr>
<tr id="row980005294165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p546588571165623"><a name="p546588571165623"></a><a name="p546588571165623"></a>HDF_FAILURE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2123815533165623"><a name="p2123815533165623"></a><a name="p2123815533165623"></a>Failed to invoke the system function to lock the mutex. </p>
</td>
</tr>
<tr id="row1527379932165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1515100695165623"><a name="p1515100695165623"></a><a name="p1515100695165623"></a>HDF_ERR_INVALID_PARAM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1550409839165623"><a name="p1550409839165623"></a><a name="p1550409839165623"></a>Invalid parameter. </p>
</td>
</tr>
</tbody>
</table>

## OsalMutexTimedLock\(\)<a name="ga57162c8f2e812ef3e5ace498bb85a3b6"></a>

```
int32_t OsalMutexTimedLock (struct [OsalMutex](osalmutex.md) * mutex, uint32_t ms )
```

 **Description:**

Locks a mutex with a specified timeout duration. 

**Parameters:**

<a name="table1908389368165623"></a>
<table><thead align="left"><tr id="row2127824447165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1969690309165623"><a name="p1969690309165623"></a><a name="p1969690309165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1532649315165623"><a name="p1532649315165623"></a><a name="p1532649315165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row280488618165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">mutex</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the mutex <a href="osalmutex.md">OsalMutex</a>. </td>
</tr>
<tr id="row1766447741165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">ms</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the timeout duration, in milliseconds.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns a value listed below: 

<a name="table127022203165623"></a>
<table><thead align="left"><tr id="row1849132348165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1319602939165623"><a name="p1319602939165623"></a><a name="p1319602939165623"></a>HDF_STATUS </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1968365737165623"><a name="p1968365737165623"></a><a name="p1968365737165623"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row909613851165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1362285050165623"><a name="p1362285050165623"></a><a name="p1362285050165623"></a>HDF_SUCCESS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p909832568165623"><a name="p909832568165623"></a><a name="p909832568165623"></a>The operation is successful. </p>
</td>
</tr>
<tr id="row1753531028165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p927679780165623"><a name="p927679780165623"></a><a name="p927679780165623"></a>HDF_FAILURE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p43155662165623"><a name="p43155662165623"></a><a name="p43155662165623"></a>Failed to invoke the system function to lock the mutex. </p>
</td>
</tr>
<tr id="row981310958165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1076597778165623"><a name="p1076597778165623"></a><a name="p1076597778165623"></a>HDF_ERR_INVALID_PARAM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p204007861165623"><a name="p204007861165623"></a><a name="p204007861165623"></a>Invalid parameter. </p>
</td>
</tr>
<tr id="row229377004165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p773571779165623"><a name="p773571779165623"></a><a name="p773571779165623"></a>HDF_ERR_TIMEOUT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1647536160165623"><a name="p1647536160165623"></a><a name="p1647536160165623"></a>Timeout occurs. </p>
</td>
</tr>
</tbody>
</table>

## OsalMutexUnlock\(\)<a name="gae76ffb4db66c988be5209e0dfdc7a35f"></a>

```
int32_t OsalMutexUnlock (struct [OsalMutex](osalmutex.md) * mutex)
```

 **Description:**

Unlocks a mutex. 

**Parameters:**

<a name="table521900709165623"></a>
<table><thead align="left"><tr id="row1939512429165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p376489674165623"><a name="p376489674165623"></a><a name="p376489674165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p355588860165623"><a name="p355588860165623"></a><a name="p355588860165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1456818851165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">mutex</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the mutex <a href="osalmutex.md">OsalMutex</a>.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns a value listed below: 

<a name="table639379379165623"></a>
<table><thead align="left"><tr id="row1222892300165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2141949429165623"><a name="p2141949429165623"></a><a name="p2141949429165623"></a>HDF_STATUS </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p228017391165623"><a name="p228017391165623"></a><a name="p228017391165623"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row338312899165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p148028593165623"><a name="p148028593165623"></a><a name="p148028593165623"></a>HDF_SUCCESS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1029828319165623"><a name="p1029828319165623"></a><a name="p1029828319165623"></a>The operation is successful. </p>
</td>
</tr>
<tr id="row1802998902165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p404542325165623"><a name="p404542325165623"></a><a name="p404542325165623"></a>HDF_FAILURE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1419670812165623"><a name="p1419670812165623"></a><a name="p1419670812165623"></a>Failed to invoke the system function to unlock the mutex. </p>
</td>
</tr>
<tr id="row892406081165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1171840258165623"><a name="p1171840258165623"></a><a name="p1171840258165623"></a>HDF_ERR_INVALID_PARAM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1191540203165623"><a name="p1191540203165623"></a><a name="p1191540203165623"></a>Invalid parameter. </p>
</td>
</tr>
</tbody>
</table>

## OsalReadFirmware\(\)<a name="ga2b721d36c177786841cd05cecdb01034"></a>

```
int32_t OsalReadFirmware (struct [OsalFirmware](osalfirmware.md) * fw, struct [OsalFwBlock](osalfwblock.md) * block )
```

 **Description:**

Releases a firmware file. 

After the firmware file is read, this function is called to release the firmware file.

**Parameters:**

<a name="table1429851689165623"></a>
<table><thead align="left"><tr id="row28178264165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p410778609165623"><a name="p410778609165623"></a><a name="p410778609165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1046416122165623"><a name="p1046416122165623"></a><a name="p1046416122165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1590090244165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fw</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the firmware file <a href="osalfirmware.md">OsalFirmware</a>.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns a value listed below: 

<a name="table1068575244165623"></a>
<table><thead align="left"><tr id="row1734814304165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1406790537165623"><a name="p1406790537165623"></a><a name="p1406790537165623"></a>HDF_STATUS </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p114723332165623"><a name="p114723332165623"></a><a name="p114723332165623"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row350756077165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1091797757165623"><a name="p1091797757165623"></a><a name="p1091797757165623"></a>HDF_SUCCESS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1757408188165623"><a name="p1757408188165623"></a><a name="p1757408188165623"></a>The operation is successful. </p>
</td>
</tr>
<tr id="row36565040165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p761288848165623"><a name="p761288848165623"></a><a name="p761288848165623"></a>HDF_FAILURE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1454832491165623"><a name="p1454832491165623"></a><a name="p1454832491165623"></a>Failed to invoke the system function. </p>
</td>
</tr>
<tr id="row1634731368165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2069743039165623"><a name="p2069743039165623"></a><a name="p2069743039165623"></a>HDF_ERR_INVALID_PARAM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p488820675165623"><a name="p488820675165623"></a><a name="p488820675165623"></a>Invalid parameter. </p>
</td>
</tr>
</tbody>
</table>

## OsalRegisterIrq\(\)<a name="gade084a1942c1672f2148ccf8f6c06331"></a>

```
int32_t OsalRegisterIrq (uint32_t irqId, uint32_t config, [OsalIRQHandle](osal.md#gab671a9e177f622a98af9ca1bd93198eb) handle, const char * name, void * dev )
```

 **Description:**

Registers an IRQ. 

**Parameters:**

<a name="table1837206620165623"></a>
<table><thead align="left"><tr id="row561740825165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1956899852165623"><a name="p1956899852165623"></a><a name="p1956899852165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p655671031165623"><a name="p655671031165623"></a><a name="p655671031165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1069478820165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">irqId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the IRQ ID. </td>
</tr>
<tr id="row1259898030165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">config</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the interrupt trigger mode. For details, see <a href="osal.md#ga78cd126b10424753db6f39f9b72ea124">OSAL_IRQ_TRIGGER_MODE</a>. </td>
</tr>
<tr id="row502466429165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the interrupt processing function. </td>
</tr>
<tr id="row1158900381165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">name</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the device name for registering an IRQ. </td>
</tr>
<tr id="row281013762165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">dev</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the parameter passed to the interrupt processing function.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns a value listed below: 

<a name="table60721506165623"></a>
<table><thead align="left"><tr id="row1926006216165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p252697654165623"><a name="p252697654165623"></a><a name="p252697654165623"></a>HDF_STATUS </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1202404411165623"><a name="p1202404411165623"></a><a name="p1202404411165623"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row27959441165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p208509702165623"><a name="p208509702165623"></a><a name="p208509702165623"></a>HDF_SUCCESS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p972447844165623"><a name="p972447844165623"></a><a name="p972447844165623"></a>The operation is successful. </p>
</td>
</tr>
<tr id="row772144355165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1402057304165623"><a name="p1402057304165623"></a><a name="p1402057304165623"></a>HDF_FAILURE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p964238322165623"><a name="p964238322165623"></a><a name="p964238322165623"></a>Failed to invoke the system function to register the IRQ. </p>
</td>
</tr>
<tr id="row173966314165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p262673626165623"><a name="p262673626165623"></a><a name="p262673626165623"></a>HDF_ERR_INVALID_PARAM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p852696265165623"><a name="p852696265165623"></a><a name="p852696265165623"></a>Invalid parameter. </p>
</td>
</tr>
</tbody>
</table>

## OsalReleaseFirmware\(\)<a name="gadfccddc78411a76ae8f4af4282da12f0"></a>

```
int32_t OsalReleaseFirmware (struct [OsalFirmware](osalfirmware.md) * fw)
```

 **Description:**

Release firmware resource

**Parameters:**

<a name="table63913056165623"></a>
<table><thead align="left"><tr id="row1703847131165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p711817064165623"><a name="p711817064165623"></a><a name="p711817064165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p161359137165623"><a name="p161359137165623"></a><a name="p161359137165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row515962870165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">&nbsp;</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">fw Firmware parameter, see detail in <a href="osalfirmware.md">OsalFirmware</a> block Firmware data block, see detail in hdf_FWBlock </td>
</tr>
</tbody>
</table>

**Returns:**

: true or false 

## OsalRequestFirmware\(\)<a name="ga428b9de7fb95a20ab9e25b47a7d4272c"></a>

```
int32_t OsalRequestFirmware (struct [OsalFirmware](osalfirmware.md) * fw, const char * fwName, void * device )
```

 **Description:**

Requests a firmware file based on its name and device information. 

**Parameters:**

<a name="table2099553101165623"></a>
<table><thead align="left"><tr id="row252912799165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1079086456165623"><a name="p1079086456165623"></a><a name="p1079086456165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1486612598165623"><a name="p1486612598165623"></a><a name="p1486612598165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row231789561165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fw</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the firmware file <a href="osalfirmware.md">OsalFirmware</a>, which cannot be empty. </td>
</tr>
<tr id="row654958210165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fwName</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the firmware file name, which cannot be empty. </td>
</tr>
<tr id="row424178195165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">device</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the information about the device that requests the firmware file.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns a value listed below: 

<a name="table1486647537165623"></a>
<table><thead align="left"><tr id="row1157253425165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1923293686165623"><a name="p1923293686165623"></a><a name="p1923293686165623"></a>HDF_STATUS </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p992852530165623"><a name="p992852530165623"></a><a name="p992852530165623"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1830566794165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1062833271165623"><a name="p1062833271165623"></a><a name="p1062833271165623"></a>HDF_SUCCESS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p214563273165623"><a name="p214563273165623"></a><a name="p214563273165623"></a>The operation is successful. </p>
</td>
</tr>
<tr id="row128056391165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1429391565165623"><a name="p1429391565165623"></a><a name="p1429391565165623"></a>HDF_FAILURE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p113619165623"><a name="p113619165623"></a><a name="p113619165623"></a>Failed to invoke the system function. </p>
</td>
</tr>
<tr id="row1045549554165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p451585739165623"><a name="p451585739165623"></a><a name="p451585739165623"></a>HDF_ERR_INVALID_PARAM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p261369453165623"><a name="p261369453165623"></a><a name="p261369453165623"></a>Invalid parameter. </p>
</td>
</tr>
<tr id="row557486292165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p720601986165623"><a name="p720601986165623"></a><a name="p720601986165623"></a>HDF_ERR_MALLOC_FAIL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1926646426165623"><a name="p1926646426165623"></a><a name="p1926646426165623"></a>Memory allocation fails. </p>
</td>
</tr>
</tbody>
</table>

## OsalSeekFirmware\(\)<a name="ga41ae4dade9246f3b30efd276cbd43474"></a>

```
int32_t OsalSeekFirmware (struct [OsalFirmware](osalfirmware.md) * fw, uint32_t offset )
```

 **Description:**

Reads a firmware file. 

**Parameters:**

<a name="table804565566165623"></a>
<table><thead align="left"><tr id="row1746159580165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1274472170165623"><a name="p1274472170165623"></a><a name="p1274472170165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p501801672165623"><a name="p501801672165623"></a><a name="p501801672165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row804032887165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fw</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the firmware file <a href="osalfirmware.md">OsalFirmware</a>. </td>
</tr>
<tr id="row513581147165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">block</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the firmware block to read. For details, see <a href="osalfwblock.md">OsalFwBlock</a>.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns a value listed below: 

<a name="table1979662533165623"></a>
<table><thead align="left"><tr id="row1452900491165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p997598794165623"><a name="p997598794165623"></a><a name="p997598794165623"></a>HDF_STATUS </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1082526697165623"><a name="p1082526697165623"></a><a name="p1082526697165623"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1789439622165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p290219493165623"><a name="p290219493165623"></a><a name="p290219493165623"></a>HDF_SUCCESS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1100221982165623"><a name="p1100221982165623"></a><a name="p1100221982165623"></a>The operation is successful. </p>
</td>
</tr>
<tr id="row958587366165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1730910447165623"><a name="p1730910447165623"></a><a name="p1730910447165623"></a>HDF_FAILURE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p565796473165623"><a name="p565796473165623"></a><a name="p565796473165623"></a>Failed to invoke the system function. </p>
</td>
</tr>
<tr id="row1628021863165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1088500872165623"><a name="p1088500872165623"></a><a name="p1088500872165623"></a>HDF_ERR_INVALID_PARAM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p676831338165623"><a name="p676831338165623"></a><a name="p676831338165623"></a>Invalid parameter. </p>
</td>
</tr>
</tbody>
</table>

## OsalSemDestroy\(\)<a name="ga0b6642005b8a128ac01f69385bd6969f"></a>

```
int32_t OsalSemDestroy (struct [OsalSem](osalsem.md) * sem)
```

 **Description:**

Destroys a semaphore. 

**Parameters:**

<a name="table892926614165623"></a>
<table><thead align="left"><tr id="row1314911631165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p105759635165623"><a name="p105759635165623"></a><a name="p105759635165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1050765535165623"><a name="p1050765535165623"></a><a name="p1050765535165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1952596671165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sem</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the semaphore <a href="osalsem.md">OsalSem</a>.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns a value listed below: 

<a name="table1033208087165623"></a>
<table><thead align="left"><tr id="row1177693542165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2071535589165623"><a name="p2071535589165623"></a><a name="p2071535589165623"></a>HDF_STATUS </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1154259991165623"><a name="p1154259991165623"></a><a name="p1154259991165623"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1386850615165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1279800220165623"><a name="p1279800220165623"></a><a name="p1279800220165623"></a>HDF_SUCCESS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p642335011165623"><a name="p642335011165623"></a><a name="p642335011165623"></a>The operation is successful. </p>
</td>
</tr>
<tr id="row2049639152165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p659293485165623"><a name="p659293485165623"></a><a name="p659293485165623"></a>HDF_FAILURE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1744584780165623"><a name="p1744584780165623"></a><a name="p1744584780165623"></a>Failed to invoke the system function to destroy the semaphore. </p>
</td>
</tr>
<tr id="row759395925165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1922152736165623"><a name="p1922152736165623"></a><a name="p1922152736165623"></a>HDF_ERR_INVALID_PARAM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p855567710165623"><a name="p855567710165623"></a><a name="p855567710165623"></a>Invalid parameter. </p>
</td>
</tr>
</tbody>
</table>

## OsalSemInit\(\)<a name="ga7e4325c951479e93abe072290162da0b"></a>

```
int32_t OsalSemInit (struct [OsalSem](osalsem.md) * sem, uint32_t value )
```

 **Description:**

Initializes a semaphore. 

**Parameters:**

<a name="table1318996356165623"></a>
<table><thead align="left"><tr id="row1276757216165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1508193622165623"><a name="p1508193622165623"></a><a name="p1508193622165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p282183307165623"><a name="p282183307165623"></a><a name="p282183307165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row93338279165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sem</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the semaphore <a href="osalsem.md">OsalSem</a>. </td>
</tr>
<tr id="row1960479776165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the initial value of the semaphore.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns a value listed below: 

<a name="table1760162557165623"></a>
<table><thead align="left"><tr id="row1069034416165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p893770767165623"><a name="p893770767165623"></a><a name="p893770767165623"></a>HDF_STATUS </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1098063877165623"><a name="p1098063877165623"></a><a name="p1098063877165623"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row2125048916165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p355493093165623"><a name="p355493093165623"></a><a name="p355493093165623"></a>HDF_SUCCESS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p503146274165623"><a name="p503146274165623"></a><a name="p503146274165623"></a>The operation is successful. </p>
</td>
</tr>
<tr id="row264916154165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p141016031165623"><a name="p141016031165623"></a><a name="p141016031165623"></a>HDF_FAILURE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1766055991165623"><a name="p1766055991165623"></a><a name="p1766055991165623"></a>Failed to invoke the system function to initialize the semaphore. </p>
</td>
</tr>
<tr id="row2145904386165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1723762040165623"><a name="p1723762040165623"></a><a name="p1723762040165623"></a>HDF_ERR_INVALID_PARAM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1188072062165623"><a name="p1188072062165623"></a><a name="p1188072062165623"></a>Invalid parameter. </p>
</td>
</tr>
</tbody>
</table>

## OsalSemPost\(\)<a name="gadc3205b416d3fc8e1fa9c332b82e634a"></a>

```
int32_t OsalSemPost (struct [OsalSem](osalsem.md) * sem)
```

 **Description:**

Releases a semaphore. 

**Parameters:**

<a name="table1556553376165623"></a>
<table><thead align="left"><tr id="row380098184165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p137029249165623"><a name="p137029249165623"></a><a name="p137029249165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p513295798165623"><a name="p513295798165623"></a><a name="p513295798165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row897784409165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sem</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the semaphore <a href="osalsem.md">OsalSem</a>.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns a value listed below: 

<a name="table469573945165623"></a>
<table><thead align="left"><tr id="row79720187165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1703941004165623"><a name="p1703941004165623"></a><a name="p1703941004165623"></a>HDF_STATUS </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p974924222165623"><a name="p974924222165623"></a><a name="p974924222165623"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1486583797165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1981372576165623"><a name="p1981372576165623"></a><a name="p1981372576165623"></a>HDF_SUCCESS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p774290713165623"><a name="p774290713165623"></a><a name="p774290713165623"></a>The operation is successful. </p>
</td>
</tr>
<tr id="row1936072856165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p904943139165623"><a name="p904943139165623"></a><a name="p904943139165623"></a>HDF_FAILURE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1437902891165623"><a name="p1437902891165623"></a><a name="p1437902891165623"></a>Failed to invoke the system function to release the semaphore. </p>
</td>
</tr>
<tr id="row1469991831165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1411690242165623"><a name="p1411690242165623"></a><a name="p1411690242165623"></a>HDF_ERR_INVALID_PARAM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p803440008165623"><a name="p803440008165623"></a><a name="p803440008165623"></a>Invalid parameter. </p>
</td>
</tr>
</tbody>
</table>

## OsalSemWait\(\)<a name="ga0000b9ee1421950d5b3a04cbc839c6af"></a>

```
int32_t OsalSemWait (struct [OsalSem](osalsem.md) * sem, uint32_t ms )
```

 **Description:**

Waits for a semaphore. 

**Parameters:**

<a name="table739923866165623"></a>
<table><thead align="left"><tr id="row1852309514165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p325832106165623"><a name="p325832106165623"></a><a name="p325832106165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1101639973165623"><a name="p1101639973165623"></a><a name="p1101639973165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row324913609165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sem</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the semaphore <a href="osalsem.md">OsalSem</a>. </td>
</tr>
<tr id="row649921110165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">ms</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the timeout interval.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns a value listed below: 

<a name="table674688751165623"></a>
<table><thead align="left"><tr id="row1249487286165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1123359147165623"><a name="p1123359147165623"></a><a name="p1123359147165623"></a>HDF_STATUS </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1845223240165623"><a name="p1845223240165623"></a><a name="p1845223240165623"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row435436937165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1627228022165623"><a name="p1627228022165623"></a><a name="p1627228022165623"></a>HDF_SUCCESS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1436076677165623"><a name="p1436076677165623"></a><a name="p1436076677165623"></a>The operation is successful. </p>
</td>
</tr>
<tr id="row1039747149165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1896595868165623"><a name="p1896595868165623"></a><a name="p1896595868165623"></a>HDF_FAILURE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p198846493165623"><a name="p198846493165623"></a><a name="p198846493165623"></a>Failed to invoke the system function to wait for the semaphore. </p>
</td>
</tr>
<tr id="row1241508993165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1829702908165623"><a name="p1829702908165623"></a><a name="p1829702908165623"></a>HDF_ERR_INVALID_PARAM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p580811305165623"><a name="p580811305165623"></a><a name="p580811305165623"></a>Invalid parameter. </p>
</td>
</tr>
<tr id="row1348586389165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p992998904165623"><a name="p992998904165623"></a><a name="p992998904165623"></a>HDF_ERR_TIMEOUT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p732826863165623"><a name="p732826863165623"></a><a name="p732826863165623"></a>Timeout occurs. </p>
</td>
</tr>
</tbody>
</table>

## OsalSleep\(\)<a name="ga8b9ca3498c54b11dcbe88a2a456f23ab"></a>

```
void OsalSleep (uint32_t sec)
```

 **Description:**

Describes thread sleep, in seconds. 

When a thread invokes this function, the CPU is released and the thread enters the sleep state.

**Parameters:**

<a name="table1521705155165623"></a>
<table><thead align="left"><tr id="row1635680919165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p881363844165623"><a name="p881363844165623"></a><a name="p881363844165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1190019328165623"><a name="p1190019328165623"></a><a name="p1190019328165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1497739102165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sec</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the sleep time, in seconds. </td>
</tr>
</tbody>
</table>

## OsalSpinDestroy\(\)<a name="gacd3824f292ddef395bd1a4a7b5546470"></a>

```
int32_t OsalSpinDestroy ([OsalSpinlock](osalspinlock.md) * spinlock)
```

 **Description:**

Destroys a spinlock. 

**Parameters:**

<a name="table1497940708165623"></a>
<table><thead align="left"><tr id="row628182701165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1674518029165623"><a name="p1674518029165623"></a><a name="p1674518029165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p87654381165623"><a name="p87654381165623"></a><a name="p87654381165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1756542911165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">spinlock</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the spinlock <a href="osalspinlock.md">OsalSpinlock</a>.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns a value listed below: 

<a name="table1134492949165623"></a>
<table><thead align="left"><tr id="row526490882165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p936343253165623"><a name="p936343253165623"></a><a name="p936343253165623"></a>HDF_STATUS </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1050287431165623"><a name="p1050287431165623"></a><a name="p1050287431165623"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row829171531165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1354656032165623"><a name="p1354656032165623"></a><a name="p1354656032165623"></a>HDF_SUCCESS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1549863171165623"><a name="p1549863171165623"></a><a name="p1549863171165623"></a>The operation is successful. </p>
</td>
</tr>
<tr id="row1923255763165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1244053759165623"><a name="p1244053759165623"></a><a name="p1244053759165623"></a>HDF_FAILURE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1053764287165623"><a name="p1053764287165623"></a><a name="p1053764287165623"></a>Failed to invoke the system function to destroy the spinlock. </p>
</td>
</tr>
<tr id="row1789559324165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p889372712165623"><a name="p889372712165623"></a><a name="p889372712165623"></a>HDF_ERR_INVALID_PARAM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1451461443165623"><a name="p1451461443165623"></a><a name="p1451461443165623"></a>Invalid parameter. </p>
</td>
</tr>
</tbody>
</table>

## OsalSpinInit\(\)<a name="gae36a2d6e4e0191273c9f86a918befb5c"></a>

```
int32_t OsalSpinInit ([OsalSpinlock](osalspinlock.md) * spinlock)
```

 **Description:**

Initializes a spinlock. 

**Parameters:**

<a name="table329847199165623"></a>
<table><thead align="left"><tr id="row704824326165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1123714829165623"><a name="p1123714829165623"></a><a name="p1123714829165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1151123090165623"><a name="p1151123090165623"></a><a name="p1151123090165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row410747720165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">spinlock</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the spinlock <a href="osalspinlock.md">OsalSpinlock</a>.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns a value listed below: 

<a name="table755099705165623"></a>
<table><thead align="left"><tr id="row1442502626165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p602241472165623"><a name="p602241472165623"></a><a name="p602241472165623"></a>HDF_STATUS </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p341323394165623"><a name="p341323394165623"></a><a name="p341323394165623"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row726238435165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p964295854165623"><a name="p964295854165623"></a><a name="p964295854165623"></a>HDF_SUCCESS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p196328659165623"><a name="p196328659165623"></a><a name="p196328659165623"></a>The operation is successful. </p>
</td>
</tr>
<tr id="row631898492165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1136570771165623"><a name="p1136570771165623"></a><a name="p1136570771165623"></a>HDF_FAILURE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1031794184165623"><a name="p1031794184165623"></a><a name="p1031794184165623"></a>Failed to invoke the system function to initialize the spinlock. </p>
</td>
</tr>
<tr id="row614510141165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p507670693165623"><a name="p507670693165623"></a><a name="p507670693165623"></a>HDF_ERR_INVALID_PARAM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1240731895165623"><a name="p1240731895165623"></a><a name="p1240731895165623"></a>Invalid parameter. </p>
</td>
</tr>
<tr id="row1660334603165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p142637707165623"><a name="p142637707165623"></a><a name="p142637707165623"></a>HDF_ERR_MALLOC_FAIL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1531917436165623"><a name="p1531917436165623"></a><a name="p1531917436165623"></a>Memory allocation fails. </p>
</td>
</tr>
</tbody>
</table>

## OsalSpinLock\(\)<a name="gae1c4b9ac8ea2a4820d73c20ae017dbd7"></a>

```
int32_t OsalSpinLock ([OsalSpinlock](osalspinlock.md) * spinlock)
```

 **Description:**

Obtains a spinlock. 

**Parameters:**

<a name="table2061788928165623"></a>
<table><thead align="left"><tr id="row1978714930165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2005848409165623"><a name="p2005848409165623"></a><a name="p2005848409165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p586077903165623"><a name="p586077903165623"></a><a name="p586077903165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row132075795165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">spinlock</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the spinlock <a href="osalspinlock.md">OsalSpinlock</a>.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns a value listed below: 

<a name="table971809357165623"></a>
<table><thead align="left"><tr id="row1222138692165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p894454787165623"><a name="p894454787165623"></a><a name="p894454787165623"></a>HDF_STATUS </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1513392675165623"><a name="p1513392675165623"></a><a name="p1513392675165623"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row618484117165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p674125488165623"><a name="p674125488165623"></a><a name="p674125488165623"></a>HDF_SUCCESS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1523117598165623"><a name="p1523117598165623"></a><a name="p1523117598165623"></a>The operation is successful. </p>
</td>
</tr>
<tr id="row569448194165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p775423171165623"><a name="p775423171165623"></a><a name="p775423171165623"></a>HDF_FAILURE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p347844136165623"><a name="p347844136165623"></a><a name="p347844136165623"></a>Failed to invoke the system function to obtain the spinlock. </p>
</td>
</tr>
<tr id="row1915912685165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p403747003165623"><a name="p403747003165623"></a><a name="p403747003165623"></a>HDF_ERR_INVALID_PARAM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p351828481165623"><a name="p351828481165623"></a><a name="p351828481165623"></a>Invalid parameter. </p>
</td>
</tr>
</tbody>
</table>

## OsalSpinLockIrq\(\)<a name="ga7d409ec573a06078112a8ffae14afce5"></a>

```
int32_t OsalSpinLockIrq ([OsalSpinlock](osalspinlock.md) * spinlock)
```

 **Description:**

Obtains a spinlock and disables the IRQ. 

**Parameters:**

<a name="table1148832177165623"></a>
<table><thead align="left"><tr id="row959300529165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1613411364165623"><a name="p1613411364165623"></a><a name="p1613411364165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1881322239165623"><a name="p1881322239165623"></a><a name="p1881322239165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row688339847165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">spinlock</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the spinlock <a href="osalspinlock.md">OsalSpinlock</a>.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns a value listed below: 

<a name="table151830901165623"></a>
<table><thead align="left"><tr id="row1880277839165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1580377231165623"><a name="p1580377231165623"></a><a name="p1580377231165623"></a>HDF_STATUS </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1963271396165623"><a name="p1963271396165623"></a><a name="p1963271396165623"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row767736658165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p136124018165623"><a name="p136124018165623"></a><a name="p136124018165623"></a>HDF_SUCCESS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1464604038165623"><a name="p1464604038165623"></a><a name="p1464604038165623"></a>The operation is successful. </p>
</td>
</tr>
<tr id="row1643663391165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p967695461165623"><a name="p967695461165623"></a><a name="p967695461165623"></a>HDF_FAILURE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1644831905165623"><a name="p1644831905165623"></a><a name="p1644831905165623"></a>Failed to invoke the system function to obtain the spinlock. </p>
</td>
</tr>
<tr id="row105142877165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2066940937165623"><a name="p2066940937165623"></a><a name="p2066940937165623"></a>HDF_ERR_INVALID_PARAM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1187249258165623"><a name="p1187249258165623"></a><a name="p1187249258165623"></a>Invalid parameter. </p>
</td>
</tr>
</tbody>
</table>

## OsalSpinLockIrqSave\(\)<a name="gab711d8d56055e78dd85f84bc530a4d3f"></a>

```
int32_t OsalSpinLockIrqSave ([OsalSpinlock](osalspinlock.md) * spinlock, uint32_t * flags )
```

 **Description:**

Obtains a spinlock, disables the IRQ, and saves its status. 

**Parameters:**

<a name="table365637777165623"></a>
<table><thead align="left"><tr id="row1592615122165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p766829951165623"><a name="p766829951165623"></a><a name="p766829951165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1878998877165623"><a name="p1878998877165623"></a><a name="p1878998877165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row540896913165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">spinlock</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the spinlock <a href="osalspinlock.md">OsalSpinlock</a>. </td>
</tr>
<tr id="row1604518954165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">flags</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the status of the IRQ register.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns a value listed below: 

<a name="table1561938941165623"></a>
<table><thead align="left"><tr id="row115027474165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1880501189165623"><a name="p1880501189165623"></a><a name="p1880501189165623"></a>HDF_STATUS </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p367424985165623"><a name="p367424985165623"></a><a name="p367424985165623"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row722292935165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p541364201165623"><a name="p541364201165623"></a><a name="p541364201165623"></a>HDF_SUCCESS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1986401440165623"><a name="p1986401440165623"></a><a name="p1986401440165623"></a>The operation is successful. </p>
</td>
</tr>
<tr id="row473721159165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p574265278165623"><a name="p574265278165623"></a><a name="p574265278165623"></a>HDF_FAILURE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2124437891165623"><a name="p2124437891165623"></a><a name="p2124437891165623"></a>Failed to invoke the system function to obtain the spinlock. </p>
</td>
</tr>
<tr id="row2008047551165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1113149934165623"><a name="p1113149934165623"></a><a name="p1113149934165623"></a>HDF_ERR_INVALID_PARAM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1197624292165623"><a name="p1197624292165623"></a><a name="p1197624292165623"></a>Invalid parameter. </p>
</td>
</tr>
</tbody>
</table>

## OsalSpinUnlock\(\)<a name="gada1f1826b19dc900af370a2bcd9681b9"></a>

```
int32_t OsalSpinUnlock ([OsalSpinlock](osalspinlock.md) * spinlock)
```

 **Description:**

Releases a spinlock. 

**Parameters:**

<a name="table1880067327165623"></a>
<table><thead align="left"><tr id="row95333604165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1620121722165623"><a name="p1620121722165623"></a><a name="p1620121722165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1650061910165623"><a name="p1650061910165623"></a><a name="p1650061910165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row816118975165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">spinlock</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the spinlock <a href="osalspinlock.md">OsalSpinlock</a>.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns a value listed below: 

<a name="table1911870041165623"></a>
<table><thead align="left"><tr id="row1307394054165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1061576626165623"><a name="p1061576626165623"></a><a name="p1061576626165623"></a>HDF_STATUS </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p825936513165623"><a name="p825936513165623"></a><a name="p825936513165623"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1341589728165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1911362281165623"><a name="p1911362281165623"></a><a name="p1911362281165623"></a>HDF_SUCCESS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1596784529165623"><a name="p1596784529165623"></a><a name="p1596784529165623"></a>The operation is successful. </p>
</td>
</tr>
<tr id="row592214727165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p882433285165623"><a name="p882433285165623"></a><a name="p882433285165623"></a>HDF_FAILURE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1127724749165623"><a name="p1127724749165623"></a><a name="p1127724749165623"></a>Failed to invoke the system function to release the spinlock. </p>
</td>
</tr>
<tr id="row2001680358165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1498301380165623"><a name="p1498301380165623"></a><a name="p1498301380165623"></a>HDF_ERR_INVALID_PARAM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1620595274165623"><a name="p1620595274165623"></a><a name="p1620595274165623"></a>Invalid parameter. </p>
</td>
</tr>
</tbody>
</table>

## OsalSpinUnlockIrq\(\)<a name="ga7d7848d572fbda413b3b5770e95a234e"></a>

```
int32_t OsalSpinUnlockIrq ([OsalSpinlock](osalspinlock.md) * spinlock)
```

 **Description:**

Releases a spinlock and enables the IRQ. 

**Parameters:**

<a name="table138793335165623"></a>
<table><thead align="left"><tr id="row1913781913165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p277069730165623"><a name="p277069730165623"></a><a name="p277069730165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p150893784165623"><a name="p150893784165623"></a><a name="p150893784165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1056909106165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">spinlock</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the spinlock <a href="osalspinlock.md">OsalSpinlock</a>.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns a value listed below: 

<a name="table1719688022165623"></a>
<table><thead align="left"><tr id="row1220303432165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2094706370165623"><a name="p2094706370165623"></a><a name="p2094706370165623"></a>HDF_STATUS </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p203850097165623"><a name="p203850097165623"></a><a name="p203850097165623"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row751310344165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p768825377165623"><a name="p768825377165623"></a><a name="p768825377165623"></a>HDF_SUCCESS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1378940922165623"><a name="p1378940922165623"></a><a name="p1378940922165623"></a>The operation is successful. </p>
</td>
</tr>
<tr id="row2088377350165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2108119797165623"><a name="p2108119797165623"></a><a name="p2108119797165623"></a>HDF_FAILURE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1580319007165623"><a name="p1580319007165623"></a><a name="p1580319007165623"></a>Failed to invoke the system function to release the spinlock. </p>
</td>
</tr>
<tr id="row266216596165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1355057356165623"><a name="p1355057356165623"></a><a name="p1355057356165623"></a>HDF_ERR_INVALID_PARAM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1764557181165623"><a name="p1764557181165623"></a><a name="p1764557181165623"></a>Invalid parameter. </p>
</td>
</tr>
</tbody>
</table>

## OsalSpinUnlockIrqRestore\(\)<a name="ga3be4dbde6c9ae740b012e49ab90e7a8a"></a>

```
int32_t OsalSpinUnlockIrqRestore ([OsalSpinlock](osalspinlock.md) * spinlock, uint32_t * flags )
```

 **Description:**

Releases a spinlock, enables the IRQ, and restores the saved IRQ status. 

**Parameters:**

<a name="table117374837165623"></a>
<table><thead align="left"><tr id="row1002906679165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p856249657165623"><a name="p856249657165623"></a><a name="p856249657165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2124725901165623"><a name="p2124725901165623"></a><a name="p2124725901165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row641962413165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">spinlock</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the spinlock <a href="osalspinlock.md">OsalSpinlock</a>. </td>
</tr>
<tr id="row490288576165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">flags</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the value used to restore the IRQ register.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns a value listed below: 

<a name="table918031303165623"></a>
<table><thead align="left"><tr id="row1724305602165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2112640761165623"><a name="p2112640761165623"></a><a name="p2112640761165623"></a>HDF_STATUS </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1978522834165623"><a name="p1978522834165623"></a><a name="p1978522834165623"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1042668254165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p117856381165623"><a name="p117856381165623"></a><a name="p117856381165623"></a>HDF_SUCCESS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p731481837165623"><a name="p731481837165623"></a><a name="p731481837165623"></a>The operation is successful. </p>
</td>
</tr>
<tr id="row946604283165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2008072662165623"><a name="p2008072662165623"></a><a name="p2008072662165623"></a>HDF_FAILURE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p586296993165623"><a name="p586296993165623"></a><a name="p586296993165623"></a>Failed to invoke the system function to release the spinlock. </p>
</td>
</tr>
<tr id="row581310368165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p658688785165623"><a name="p658688785165623"></a><a name="p658688785165623"></a>HDF_ERR_INVALID_PARAM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p787606994165623"><a name="p787606994165623"></a><a name="p787606994165623"></a>Invalid parameter. </p>
</td>
</tr>
</tbody>
</table>

## OsalTestBit\(\)<a name="gaf02c15a3593cac4add3f661b63aebf81"></a>

```
int32_t OsalTestBit (unsigned long nr, const volatile unsigned long * addr )
```

 **Description:**

Tests the value of a specified bit of a variable. 

**Parameters:**

<a name="table1854861516165623"></a>
<table><thead align="left"><tr id="row2039955331165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p920480530165623"><a name="p920480530165623"></a><a name="p920480530165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p610841975165623"><a name="p610841975165623"></a><a name="p610841975165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1666210448165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">nr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the bit of the variable. The value ranges from <strong id="b1021046546165623"><a name="b1021046546165623"></a><a name="b1021046546165623"></a>0</strong> to <strong id="b644088325165623"><a name="b644088325165623"></a><a name="b644088325165623"></a>31</strong>. </td>
</tr>
<tr id="row699122816165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">addr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the variable.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the bit value. 

## OsalTestClearBit\(\)<a name="ga8665e70c704921f443fd2db8193ff7cc"></a>

```
int32_t OsalTestClearBit (unsigned long nr, volatile unsigned long * addr )
```

 **Description:**

Clears the value of a specified bit of the variable and returns the bit value before clearing. 

**Parameters:**

<a name="table1641209857165623"></a>
<table><thead align="left"><tr id="row1186623466165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p213395121165623"><a name="p213395121165623"></a><a name="p213395121165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1460574293165623"><a name="p1460574293165623"></a><a name="p1460574293165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row149204879165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">nr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the bit of the variable. The value ranges from <strong id="b2109187026165623"><a name="b2109187026165623"></a><a name="b2109187026165623"></a>0</strong> to <strong id="b99104323165623"><a name="b99104323165623"></a><a name="b99104323165623"></a>31</strong>. </td>
</tr>
<tr id="row1082311208165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">addr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the variable.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the bit value before the bit is cleared. 

## OsalTestSetBit\(\)<a name="gac0ff99812a327a4a595802a23b41b46f"></a>

```
int32_t OsalTestSetBit (unsigned long nr, volatile unsigned long * addr )
```

 **Description:**

Sets the value of a specified bit of the variable and returns the bit value before the setting. 

**Parameters:**

<a name="table1018858565165623"></a>
<table><thead align="left"><tr id="row212359474165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1406571035165623"><a name="p1406571035165623"></a><a name="p1406571035165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1281105287165623"><a name="p1281105287165623"></a><a name="p1281105287165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row408718266165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">nr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the bit of the variable. The value ranges from <strong id="b1405598031165623"><a name="b1405598031165623"></a><a name="b1405598031165623"></a>0</strong> to <strong id="b1349001009165623"><a name="b1349001009165623"></a><a name="b1349001009165623"></a>31</strong>. </td>
</tr>
<tr id="row633536083165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">addr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the variable.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the bit value before the setting. 

## OsalThreadCreate\(\)<a name="gad598b3f4b91f5e6aeeaf7b8a6e507f1e"></a>

```
int32_t OsalThreadCreate (struct [OsalThread](osalthread.md) * thread, [OsalThreadEntry](osal.md#ga21ea0f87d53e65ec86a424c532d688d8) threadEntry, void * entryPara )
```

 **Description:**

Creates a thread. 

**Parameters:**

<a name="table56065397165623"></a>
<table><thead align="left"><tr id="row645084350165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1198486124165623"><a name="p1198486124165623"></a><a name="p1198486124165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1081190274165623"><a name="p1081190274165623"></a><a name="p1081190274165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row200327313165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">thread</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the thread <a href="osalthread.md">OsalThread</a>. </td>
</tr>
<tr id="row2101608467165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">threadEntry</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the thread callback function <a href="osal.md#ga21ea0f87d53e65ec86a424c532d688d8">OsalThreadEntry</a>. </td>
</tr>
<tr id="row1170073444165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">entryPara</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the parameter passed to the thread callback function.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns a value listed below: 

<a name="table271060015165623"></a>
<table><thead align="left"><tr id="row838678948165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p96881070165623"><a name="p96881070165623"></a><a name="p96881070165623"></a>HDF_STATUS </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1952818524165623"><a name="p1952818524165623"></a><a name="p1952818524165623"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1516398955165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p141318710165623"><a name="p141318710165623"></a><a name="p141318710165623"></a>HDF_SUCCESS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1585544756165623"><a name="p1585544756165623"></a><a name="p1585544756165623"></a>The operation is successful. </p>
</td>
</tr>
<tr id="row555754804165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p682572487165623"><a name="p682572487165623"></a><a name="p682572487165623"></a>HDF_ERR_INVALID_PARAM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p607858651165623"><a name="p607858651165623"></a><a name="p607858651165623"></a>Invalid parameter. </p>
</td>
</tr>
<tr id="row812362217165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1688629580165623"><a name="p1688629580165623"></a><a name="p1688629580165623"></a>HDF_ERR_MALLOC_FAIL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p157609715165623"><a name="p157609715165623"></a><a name="p157609715165623"></a>Memory allocation fails. </p>
</td>
</tr>
</tbody>
</table>

## OsalThreadDestroy\(\)<a name="ga223ce6b94770348a93168525c536e6f9"></a>

```
int32_t OsalThreadDestroy (struct [OsalThread](osalthread.md) * thread)
```

 **Description:**

Destroys a thread. 

**Parameters:**

<a name="table703620235165623"></a>
<table><thead align="left"><tr id="row1139414993165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1842761298165623"><a name="p1842761298165623"></a><a name="p1842761298165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p206573252165623"><a name="p206573252165623"></a><a name="p206573252165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2117670473165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">thread</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the thread <a href="osalthread.md">OsalThread</a>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns a value listed below: 

<a name="table1638445486165623"></a>
<table><thead align="left"><tr id="row1192118034165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p849916455165623"><a name="p849916455165623"></a><a name="p849916455165623"></a>HDF_STATUS </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1907032143165623"><a name="p1907032143165623"></a><a name="p1907032143165623"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row748348038165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p775567443165623"><a name="p775567443165623"></a><a name="p775567443165623"></a>HDF_SUCCESS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1337737781165623"><a name="p1337737781165623"></a><a name="p1337737781165623"></a>The operation is successful. </p>
</td>
</tr>
<tr id="row1681459193165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1276994911165623"><a name="p1276994911165623"></a><a name="p1276994911165623"></a>HDF_FAILURE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p10340288165623"><a name="p10340288165623"></a><a name="p10340288165623"></a>Failed to invoke the system function to destroy the thread. </p>
</td>
</tr>
<tr id="row963604707165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p863861741165623"><a name="p863861741165623"></a><a name="p863861741165623"></a>HDF_ERR_INVALID_PARAM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1622246144165623"><a name="p1622246144165623"></a><a name="p1622246144165623"></a>Invalid parameter. </p>
</td>
</tr>
</tbody>
</table>

## OsalThreadResume\(\)<a name="ga32f0b5c622518b7453f758d95b137a94"></a>

```
int32_t OsalThreadResume (struct [OsalThread](osalthread.md) * thread)
```

 **Description:**

Resumes a thread. 

**Parameters:**

<a name="table799949230165623"></a>
<table><thead align="left"><tr id="row1056969694165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1292109412165623"><a name="p1292109412165623"></a><a name="p1292109412165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1908659189165623"><a name="p1908659189165623"></a><a name="p1908659189165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row671166793165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">thread</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the thread <a href="osalthread.md">OsalThread</a>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns a value listed below: 

<a name="table410370110165623"></a>
<table><thead align="left"><tr id="row448021927165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p827782417165623"><a name="p827782417165623"></a><a name="p827782417165623"></a>HDF_STATUS </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p298663479165623"><a name="p298663479165623"></a><a name="p298663479165623"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row542106175165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1652504139165623"><a name="p1652504139165623"></a><a name="p1652504139165623"></a>HDF_SUCCESS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1258566111165623"><a name="p1258566111165623"></a><a name="p1258566111165623"></a>The operation is successful. </p>
</td>
</tr>
<tr id="row88144852165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1876025958165623"><a name="p1876025958165623"></a><a name="p1876025958165623"></a>HDF_FAILURE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p556847574165623"><a name="p556847574165623"></a><a name="p556847574165623"></a>Failed to invoke the system function to resume the thread. </p>
</td>
</tr>
<tr id="row934102633165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p49556421165623"><a name="p49556421165623"></a><a name="p49556421165623"></a>HDF_ERR_INVALID_PARAM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1123618466165623"><a name="p1123618466165623"></a><a name="p1123618466165623"></a>Invalid parameter. </p>
</td>
</tr>
</tbody>
</table>

## OsalThreadStart\(\)<a name="ga74c93bd48d27cde830451f63b224307a"></a>

```
int32_t OsalThreadStart (struct [OsalThread](osalthread.md) * thread, const struct [OsalThreadParam](osalthreadparam.md) * param )
```

 **Description:**

Starts a thread. 

**Parameters:**

<a name="table1133330247165623"></a>
<table><thead align="left"><tr id="row1693559547165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p294537095165623"><a name="p294537095165623"></a><a name="p294537095165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1168398951165623"><a name="p1168398951165623"></a><a name="p1168398951165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row831967883165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">thread</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the thread <a href="osalthread.md">OsalThread</a>. </td>
</tr>
<tr id="row1224501444165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">param</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the parameter used to start a thread. For details, see <a href="osalthreadparam.md">OsalThreadParam</a>.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns a value listed below: 

<a name="table1531758511165623"></a>
<table><thead align="left"><tr id="row794510410165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p288035024165623"><a name="p288035024165623"></a><a name="p288035024165623"></a>HDF_STATUS </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1010423741165623"><a name="p1010423741165623"></a><a name="p1010423741165623"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1668348716165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p195745191165623"><a name="p195745191165623"></a><a name="p195745191165623"></a>HDF_SUCCESS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p629795205165623"><a name="p629795205165623"></a><a name="p629795205165623"></a>The operation is successful. </p>
</td>
</tr>
<tr id="row626033920165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p533412567165623"><a name="p533412567165623"></a><a name="p533412567165623"></a>HDF_FAILURE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p179040878165623"><a name="p179040878165623"></a><a name="p179040878165623"></a>Failed to invoke the system function to start the thread. </p>
</td>
</tr>
<tr id="row786701641165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2000232189165623"><a name="p2000232189165623"></a><a name="p2000232189165623"></a>HDF_ERR_INVALID_PARAM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p833911559165623"><a name="p833911559165623"></a><a name="p833911559165623"></a>Invalid parameter. </p>
</td>
</tr>
</tbody>
</table>

## OsalThreadSuspend\(\)<a name="gad556075f625d01557c0075a2c092a1da"></a>

```
int32_t OsalThreadSuspend (struct [OsalThread](osalthread.md) * thread)
```

 **Description:**

Suspends a thread. 

**Parameters:**

<a name="table1235437481165623"></a>
<table><thead align="left"><tr id="row303053714165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p86230085165623"><a name="p86230085165623"></a><a name="p86230085165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1105520868165623"><a name="p1105520868165623"></a><a name="p1105520868165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row851365169165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">thread</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the thread <a href="osalthread.md">OsalThread</a>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns a value listed below: 

<a name="table1066758020165623"></a>
<table><thead align="left"><tr id="row1948299709165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p740705742165623"><a name="p740705742165623"></a><a name="p740705742165623"></a>HDF_STATUS </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1514629641165623"><a name="p1514629641165623"></a><a name="p1514629641165623"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1389838293165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2111553254165623"><a name="p2111553254165623"></a><a name="p2111553254165623"></a>HDF_SUCCESS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p222069742165623"><a name="p222069742165623"></a><a name="p222069742165623"></a>The operation is successful. </p>
</td>
</tr>
<tr id="row2032616051165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p988403825165623"><a name="p988403825165623"></a><a name="p988403825165623"></a>HDF_FAILURE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p519786936165623"><a name="p519786936165623"></a><a name="p519786936165623"></a>Failed to invoke the system function to suspend the thread. </p>
</td>
</tr>
<tr id="row1515196121165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1392478987165623"><a name="p1392478987165623"></a><a name="p1392478987165623"></a>HDF_ERR_INVALID_PARAM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p920684807165623"><a name="p920684807165623"></a><a name="p920684807165623"></a>Invalid parameter. </p>
</td>
</tr>
</tbody>
</table>

## OsalTimerCreate\(\)<a name="ga879d9a437e1423021f95cb9341f0d6af"></a>

```
int32_t OsalTimerCreate ([OsalTimer](osaltimer.md) * timer, uint32_t interval, [OsalTimerFunc](osal.md#gaf3e7a12075b25df5971049d8cd77c25c) func, uintptr_t arg )
```

 **Description:**

Creates a timer. 

**Parameters:**

<a name="table998439431165623"></a>
<table><thead align="left"><tr id="row1821467689165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2034322442165623"><a name="p2034322442165623"></a><a name="p2034322442165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p132929790165623"><a name="p132929790165623"></a><a name="p132929790165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row802559440165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">timer</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the timer <a href="osaltimer.md">OsalTimer</a>. </td>
</tr>
<tr id="row1548795165165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">interval</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the timer interval. </td>
</tr>
<tr id="row655828852165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">func</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the timer execution function <a href="osal.md#gaf3e7a12075b25df5971049d8cd77c25c">OsalTimerFunc</a>. </td>
</tr>
<tr id="row1054454047165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">arg</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the argument passed to the timer execution function.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns a value listed below: 

<a name="table412801647165623"></a>
<table><thead align="left"><tr id="row307128518165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p771518010165623"><a name="p771518010165623"></a><a name="p771518010165623"></a>HDF_STATUS </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1548023845165623"><a name="p1548023845165623"></a><a name="p1548023845165623"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row959577112165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1852123187165623"><a name="p1852123187165623"></a><a name="p1852123187165623"></a>HDF_SUCCESS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1299104442165623"><a name="p1299104442165623"></a><a name="p1299104442165623"></a>The operation is successful. </p>
</td>
</tr>
<tr id="row890141860165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p948876893165623"><a name="p948876893165623"></a><a name="p948876893165623"></a>HDF_FAILURE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1811221817165623"><a name="p1811221817165623"></a><a name="p1811221817165623"></a>Failed to invoke the system function. </p>
</td>
</tr>
<tr id="row121866164165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1320845475165623"><a name="p1320845475165623"></a><a name="p1320845475165623"></a>HDF_ERR_INVALID_PARAM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1934484782165623"><a name="p1934484782165623"></a><a name="p1934484782165623"></a>Invalid parameter. </p>
</td>
</tr>
<tr id="row1815072494165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1145283694165623"><a name="p1145283694165623"></a><a name="p1145283694165623"></a>HDF_ERR_MALLOC_FAIL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2078436515165623"><a name="p2078436515165623"></a><a name="p2078436515165623"></a>Memory allocation fails. </p>
</td>
</tr>
</tbody>
</table>

## OsalTimerDelete\(\)<a name="gab754f3522245e6b2f9ee1cdecae62b52"></a>

```
int32_t OsalTimerDelete ([OsalTimer](osaltimer.md) * timer)
```

 **Description:**

Deletes a timer. 

**Parameters:**

<a name="table355676784165623"></a>
<table><thead align="left"><tr id="row945289351165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1105597351165623"><a name="p1105597351165623"></a><a name="p1105597351165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1504975291165623"><a name="p1504975291165623"></a><a name="p1504975291165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row224321389165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">timer</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the timer <a href="osaltimer.md">OsalTimer</a>.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns a value listed below: 

<a name="table1765385547165623"></a>
<table><thead align="left"><tr id="row571080602165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1822670168165623"><a name="p1822670168165623"></a><a name="p1822670168165623"></a>HDF_STATUS </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p224753152165623"><a name="p224753152165623"></a><a name="p224753152165623"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1465119066165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1735859312165623"><a name="p1735859312165623"></a><a name="p1735859312165623"></a>HDF_SUCCESS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1464784970165623"><a name="p1464784970165623"></a><a name="p1464784970165623"></a>The operation is successful. </p>
</td>
</tr>
<tr id="row902754845165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1850837852165623"><a name="p1850837852165623"></a><a name="p1850837852165623"></a>HDF_FAILURE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p567832256165623"><a name="p567832256165623"></a><a name="p567832256165623"></a>Failed to invoke the system function to delete the timer. </p>
</td>
</tr>
<tr id="row146866810165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p27885110165623"><a name="p27885110165623"></a><a name="p27885110165623"></a>HDF_ERR_INVALID_PARAM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p82514785165623"><a name="p82514785165623"></a><a name="p82514785165623"></a>Invalid parameter. </p>
</td>
</tr>
</tbody>
</table>

## OsalTimerSetTimeout\(\)<a name="ga49c2fe3f54d548fe5ec0d03a79691376"></a>

```
int32_t OsalTimerSetTimeout ([OsalTimer](osaltimer.md) * timer, uint32_t interval )
```

 **Description:**

Sets the interval of a timer. 

**Parameters:**

<a name="table2007713677165623"></a>
<table><thead align="left"><tr id="row1513608232165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1720375314165623"><a name="p1720375314165623"></a><a name="p1720375314165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1307808214165623"><a name="p1307808214165623"></a><a name="p1307808214165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row156166656165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">timer</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the timer <a href="osaltimer.md">OsalTimer</a>. </td>
</tr>
<tr id="row1668955272165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">interval</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the timer interval, in milliseconds.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns a value listed below: 

<a name="table1700502588165623"></a>
<table><thead align="left"><tr id="row30542097165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p15965378165623"><a name="p15965378165623"></a><a name="p15965378165623"></a>HDF_STATUS </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1685453131165623"><a name="p1685453131165623"></a><a name="p1685453131165623"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row825643876165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1640069215165623"><a name="p1640069215165623"></a><a name="p1640069215165623"></a>HDF_SUCCESS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1852393276165623"><a name="p1852393276165623"></a><a name="p1852393276165623"></a>The operation is successful. </p>
</td>
</tr>
<tr id="row98460598165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1431977436165623"><a name="p1431977436165623"></a><a name="p1431977436165623"></a>HDF_FAILURE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p648970485165623"><a name="p648970485165623"></a><a name="p648970485165623"></a>Failed to invoke the system function. </p>
</td>
</tr>
<tr id="row2078904405165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p786082803165623"><a name="p786082803165623"></a><a name="p786082803165623"></a>HDF_ERR_INVALID_PARAM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p962433189165623"><a name="p962433189165623"></a><a name="p962433189165623"></a>Invalid parameter. </p>
</td>
</tr>
</tbody>
</table>

## OsalTimerStartLoop\(\)<a name="ga575e4f41359c737ab9690ab28838b99f"></a>

```
int32_t OsalTimerStartLoop ([OsalTimer](osaltimer.md) * timer)
```

 **Description:**

Starts a periodic timer. 

**Parameters:**

<a name="table1128518243165623"></a>
<table><thead align="left"><tr id="row1559221758165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p400859952165623"><a name="p400859952165623"></a><a name="p400859952165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p5374573165623"><a name="p5374573165623"></a><a name="p5374573165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row54976420165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">timer</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the timer <a href="osaltimer.md">OsalTimer</a>. </td>
</tr>
<tr id="row822380562165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">interval</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the timer interval, in milliseconds.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns a value listed below: 

<a name="table1644637989165623"></a>
<table><thead align="left"><tr id="row1830017503165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1400255188165623"><a name="p1400255188165623"></a><a name="p1400255188165623"></a>HDF_STATUS </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p287337304165623"><a name="p287337304165623"></a><a name="p287337304165623"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1996698097165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p108221118165623"><a name="p108221118165623"></a><a name="p108221118165623"></a>HDF_SUCCESS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1679898277165623"><a name="p1679898277165623"></a><a name="p1679898277165623"></a>The operation is successful. </p>
</td>
</tr>
<tr id="row1673818383165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1780812873165623"><a name="p1780812873165623"></a><a name="p1780812873165623"></a>HDF_FAILURE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1789874806165623"><a name="p1789874806165623"></a><a name="p1789874806165623"></a>Failed to invoke the system function to start the timer. </p>
</td>
</tr>
<tr id="row80155920165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p441003916165623"><a name="p441003916165623"></a><a name="p441003916165623"></a>HDF_ERR_INVALID_PARAM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2036928972165623"><a name="p2036928972165623"></a><a name="p2036928972165623"></a>Invalid parameter. </p>
</td>
</tr>
</tbody>
</table>

## OsalTimerStartOnce\(\)<a name="gaf2e49d5b01b49e5f64a7701da8667141"></a>

```
int32_t OsalTimerStartOnce ([OsalTimer](osaltimer.md) * timer)
```

 **Description:**

Starts a timer. 

**Parameters:**

<a name="table1464142976165623"></a>
<table><thead align="left"><tr id="row1929058184165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p18490188165623"><a name="p18490188165623"></a><a name="p18490188165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1786573373165623"><a name="p1786573373165623"></a><a name="p1786573373165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2019753380165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">timer</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the timer <a href="osaltimer.md">OsalTimer</a>.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns a value listed below: 

<a name="table214922366165623"></a>
<table><thead align="left"><tr id="row313143255165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1225087409165623"><a name="p1225087409165623"></a><a name="p1225087409165623"></a>HDF_STATUS </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1680335639165623"><a name="p1680335639165623"></a><a name="p1680335639165623"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row2126195841165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1157895740165623"><a name="p1157895740165623"></a><a name="p1157895740165623"></a>HDF_SUCCESS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1380988596165623"><a name="p1380988596165623"></a><a name="p1380988596165623"></a>The operation is successful. </p>
</td>
</tr>
<tr id="row485524246165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p72960692165623"><a name="p72960692165623"></a><a name="p72960692165623"></a>HDF_FAILURE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p113130495165623"><a name="p113130495165623"></a><a name="p113130495165623"></a>Failed to invoke the system function to start the timer. </p>
</td>
</tr>
<tr id="row1595533921165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p560831419165623"><a name="p560831419165623"></a><a name="p560831419165623"></a>HDF_ERR_INVALID_PARAM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p283139518165623"><a name="p283139518165623"></a><a name="p283139518165623"></a>Invalid parameter. </p>
</td>
</tr>
</tbody>
</table>

## OsalUDelay\(\)<a name="ga7ae78fa3318a82dbd769827d4f373958"></a>

```
void OsalUDelay (uint32_t us)
```

 **Description:**

Describes thread delay, in microseconds. 

When a thread invokes this function, the CPU is not released. This function returns after waiting for microseconds.

**Parameters:**

<a name="table729278454165623"></a>
<table><thead align="left"><tr id="row1941223393165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1829400993165623"><a name="p1829400993165623"></a><a name="p1829400993165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p285836409165623"><a name="p285836409165623"></a><a name="p285836409165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row349442100165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">us</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the delay time, in microseconds. </td>
</tr>
</tbody>
</table>

## OsalUnregisterIrq\(\)<a name="gade4ec4496eb07f1ff0610b53ba419dba"></a>

```
int32_t OsalUnregisterIrq (uint32_t irqId)
```

 **Description:**

Unregisters an IRQ. 

**Parameters:**

<a name="table2027522264165623"></a>
<table><thead align="left"><tr id="row2129618117165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1669098907165623"><a name="p1669098907165623"></a><a name="p1669098907165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1318587402165623"><a name="p1318587402165623"></a><a name="p1318587402165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row793810135165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">irqId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the IRQ ID.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns a value listed below: 

<a name="table1453975170165623"></a>
<table><thead align="left"><tr id="row60769971165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1444353399165623"><a name="p1444353399165623"></a><a name="p1444353399165623"></a>HDF_STATUS </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p303062415165623"><a name="p303062415165623"></a><a name="p303062415165623"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row509299217165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1626064215165623"><a name="p1626064215165623"></a><a name="p1626064215165623"></a>HDF_SUCCESS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1999097295165623"><a name="p1999097295165623"></a><a name="p1999097295165623"></a>The operation is successful. </p>
</td>
</tr>
<tr id="row956387279165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p979548747165623"><a name="p979548747165623"></a><a name="p979548747165623"></a>HDF_FAILURE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1648702477165623"><a name="p1648702477165623"></a><a name="p1648702477165623"></a>Failed to invoke the system function to unregister the IRQ. </p>
</td>
</tr>
<tr id="row985045572165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1470018401165623"><a name="p1470018401165623"></a><a name="p1470018401165623"></a>HDF_ERR_INVALID_PARAM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1527162200165623"><a name="p1527162200165623"></a><a name="p1527162200165623"></a>Invalid parameter. </p>
</td>
</tr>
</tbody>
</table>

