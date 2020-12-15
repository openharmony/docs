# shmid\_ds<a name="EN-US_TOPIC_0000001054799647"></a>

-   [Overview](#section1832863686165637)
-   [Summary](#section1525067479165637)
-   [Data Fields](#pub-attribs)
-   [Details](#section1064688726165637)
-   [Field](#section53433227165637)
-   [\_\_pad1](#a34a4da4fb1e217399487b201f8f3c621)
-   [\_\_pad2](#ae9dd2a694b91cf85c9989a42e7ce07cb)
-   [shm\_atime](#af82fd8f5fdd9d93e3985f5b888382bf8)
-   [shm\_cpid](#afe5c739b33bfa41eb55563571410e52c)
-   [shm\_ctime](#a1bee5edd96bfc138b5ca07cb558a10c5)
-   [shm\_dtime](#a27ee9289548d67c2036b695a25dca11b)
-   [shm\_lpid](#a5539fd4cdac73e375697bbd59c39c29f)
-   [shm\_nattch](#a68a95433988a55ce183358e4e9fe4d41)
-   [shm\_perm](#aa211c549a679c1b3eed093b44958a18a)
-   [shm\_segsz](#a0c5defd6c73b4224d9944c770bfa77b9)

## **Overview**<a name="section1832863686165637"></a>

**Related Modules:**

[MEM](mem.md)

**Description:**

Stores information about a shared memory segment. 

## **Summary**<a name="section1525067479165637"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1628065751165637"></a>
<table><thead align="left"><tr id="row1669225897165637"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1152560798165637"><a name="p1152560798165637"></a><a name="p1152560798165637"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2019189588165637"><a name="p2019189588165637"></a><a name="p2019189588165637"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row742915120165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1099108169165637"><a name="p1099108169165637"></a><a name="p1099108169165637"></a><a href="shmid_ds.md#aa211c549a679c1b3eed093b44958a18a">shm_perm</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p65416806165637"><a name="p65416806165637"></a><a name="p65416806165637"></a>struct ipc_perm </p>
</td>
</tr>
<tr id="row1049705678165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1657257683165637"><a name="p1657257683165637"></a><a name="p1657257683165637"></a><a href="shmid_ds.md#a0c5defd6c73b4224d9944c770bfa77b9">shm_segsz</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p166427956165637"><a name="p166427956165637"></a><a name="p166427956165637"></a>size_t </p>
</td>
</tr>
<tr id="row1064434651165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p274318948165637"><a name="p274318948165637"></a><a name="p274318948165637"></a><a href="shmid_ds.md#af82fd8f5fdd9d93e3985f5b888382bf8">shm_atime</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p286916911165637"><a name="p286916911165637"></a><a name="p286916911165637"></a><a href="utils.md#ga138ad62ac7715e7161bf6223e35d8323">time_t</a> </p>
</td>
</tr>
<tr id="row666780027165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p92909376165637"><a name="p92909376165637"></a><a name="p92909376165637"></a><a href="shmid_ds.md#a27ee9289548d67c2036b695a25dca11b">shm_dtime</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p672283669165637"><a name="p672283669165637"></a><a name="p672283669165637"></a><a href="utils.md#ga138ad62ac7715e7161bf6223e35d8323">time_t</a> </p>
</td>
</tr>
<tr id="row1861089603165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1043373181165637"><a name="p1043373181165637"></a><a name="p1043373181165637"></a><a href="shmid_ds.md#a1bee5edd96bfc138b5ca07cb558a10c5">shm_ctime</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p59968756165637"><a name="p59968756165637"></a><a name="p59968756165637"></a><a href="utils.md#ga138ad62ac7715e7161bf6223e35d8323">time_t</a> </p>
</td>
</tr>
<tr id="row1131787613165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1865180417165637"><a name="p1865180417165637"></a><a name="p1865180417165637"></a><a href="shmid_ds.md#afe5c739b33bfa41eb55563571410e52c">shm_cpid</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p875363987165637"><a name="p875363987165637"></a><a name="p875363987165637"></a><a href="utils.md#ga30c34d3eead853c44f459f21b932984c">pid_t</a> </p>
</td>
</tr>
<tr id="row423324357165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1831395045165637"><a name="p1831395045165637"></a><a name="p1831395045165637"></a><a href="shmid_ds.md#a5539fd4cdac73e375697bbd59c39c29f">shm_lpid</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1862407937165637"><a name="p1862407937165637"></a><a name="p1862407937165637"></a><a href="utils.md#ga30c34d3eead853c44f459f21b932984c">pid_t</a> </p>
</td>
</tr>
<tr id="row1589246497165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p754125494165637"><a name="p754125494165637"></a><a name="p754125494165637"></a><a href="shmid_ds.md#a68a95433988a55ce183358e4e9fe4d41">shm_nattch</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p756515490165637"><a name="p756515490165637"></a><a name="p756515490165637"></a>unsigned long </p>
</td>
</tr>
<tr id="row1879720983165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1422251647165637"><a name="p1422251647165637"></a><a name="p1422251647165637"></a><a href="shmid_ds.md#a34a4da4fb1e217399487b201f8f3c621">__pad1</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2040342870165637"><a name="p2040342870165637"></a><a name="p2040342870165637"></a>unsigned long </p>
</td>
</tr>
<tr id="row496011664165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p88413665165637"><a name="p88413665165637"></a><a name="p88413665165637"></a><a href="shmid_ds.md#ae9dd2a694b91cf85c9989a42e7ce07cb">__pad2</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p143708179165637"><a name="p143708179165637"></a><a name="p143708179165637"></a>unsigned long </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1064688726165637"></a>

## **Field **<a name="section53433227165637"></a>

## \_\_pad1<a name="a34a4da4fb1e217399487b201f8f3c621"></a>

```
unsigned long shmid_ds::__pad1
```

 **Description:**

Padding field 

## \_\_pad2<a name="ae9dd2a694b91cf85c9989a42e7ce07cb"></a>

```
unsigned long shmid_ds::__pad2
```

 **Description:**

Padding field 

## shm\_atime<a name="af82fd8f5fdd9d93e3985f5b888382bf8"></a>

```
[time_t](utils.md#ga138ad62ac7715e7161bf6223e35d8323) shmid_ds::shm_atime
```

 **Description:**

Time when the last process is attached to this segment 

## shm\_cpid<a name="afe5c739b33bfa41eb55563571410e52c"></a>

```
[pid_t](utils.md#ga30c34d3eead853c44f459f21b932984c) shmid_ds::shm_cpid
```

 **Description:**

ID of the process that created this segment 

## shm\_ctime<a name="a1bee5edd96bfc138b5ca07cb558a10c5"></a>

```
[time_t](utils.md#ga138ad62ac7715e7161bf6223e35d8323) shmid_ds::shm_ctime
```

 **Description:**

Time when the last process modified this segment 

## shm\_dtime<a name="a27ee9289548d67c2036b695a25dca11b"></a>

```
[time_t](utils.md#ga138ad62ac7715e7161bf6223e35d8323) shmid_ds::shm_dtime
```

 **Description:**

Time when the last process is detached from this segment 

## shm\_lpid<a name="a5539fd4cdac73e375697bbd59c39c29f"></a>

```
[pid_t](utils.md#ga30c34d3eead853c44f459f21b932984c) shmid_ds::shm_lpid
```

 **Description:**

ID of the last process that operated this segment 

## shm\_nattch<a name="a68a95433988a55ce183358e4e9fe4d41"></a>

```
unsigned long shmid_ds::shm_nattch
```

 **Description:**

Number of processes attached to this segment 

## shm\_perm<a name="aa211c549a679c1b3eed093b44958a18a"></a>

```
struct ipc_perm shmid_ds::shm_perm
```

 **Description:**

Operation permissions on this segment 

## shm\_segsz<a name="a0c5defd6c73b4224d9944c770bfa77b9"></a>

```
size_t shmid_ds::shm_segsz
```

 **Description:**

Segment size, in bytes 

