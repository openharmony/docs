# shminfo<a name="EN-US_TOPIC_0000001055039564"></a>

-   [Overview](#section764815373165637)
-   [Summary](#section1169491627165637)
-   [Data Fields](#pub-attribs)
-   [Details](#section747444635165637)
-   [Field](#section1868399011165637)
-   [\_\_unused](#a68b65a802c7b3bc6d911ed41808203ef)
-   [shmall](#a4b74fbc85e2805f7b99f6aecde00c570)
-   [shmmax](#a2d7778854ce2e55499a2036da769905a)
-   [shmmin](#a9940d32ac5484be0f5df79296d9bc97a)
-   [shmmni](#a084bc8449e6683ede60a6445255d14bd)
-   [shmseg](#a11ee1150ca8aaad294c17fe939f35688)

## **Overview**<a name="section764815373165637"></a>

**Related Modules:**

[MEM](mem.md)

**Description:**

Describes limitations and attributes of system-level shared memory. 

## **Summary**<a name="section1169491627165637"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1687518525165637"></a>
<table><thead align="left"><tr id="row1444592544165637"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1349301954165637"><a name="p1349301954165637"></a><a name="p1349301954165637"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p972001067165637"><a name="p972001067165637"></a><a name="p972001067165637"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row752017582165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1655303934165637"><a name="p1655303934165637"></a><a name="p1655303934165637"></a><a href="shminfo.md#a2d7778854ce2e55499a2036da769905a">shmmax</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p886963319165637"><a name="p886963319165637"></a><a name="p886963319165637"></a>unsigned long </p>
</td>
</tr>
<tr id="row1838668115165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1590284906165637"><a name="p1590284906165637"></a><a name="p1590284906165637"></a><a href="shminfo.md#a9940d32ac5484be0f5df79296d9bc97a">shmmin</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p753499164165637"><a name="p753499164165637"></a><a name="p753499164165637"></a>unsigned long </p>
</td>
</tr>
<tr id="row262911906165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1230781778165637"><a name="p1230781778165637"></a><a name="p1230781778165637"></a><a href="shminfo.md#a084bc8449e6683ede60a6445255d14bd">shmmni</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p354399726165637"><a name="p354399726165637"></a><a name="p354399726165637"></a>unsigned long </p>
</td>
</tr>
<tr id="row1651544211165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p987008679165637"><a name="p987008679165637"></a><a name="p987008679165637"></a><a href="shminfo.md#a11ee1150ca8aaad294c17fe939f35688">shmseg</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p643027796165637"><a name="p643027796165637"></a><a name="p643027796165637"></a>unsigned long </p>
</td>
</tr>
<tr id="row1472178946165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p837185467165637"><a name="p837185467165637"></a><a name="p837185467165637"></a><a href="shminfo.md#a4b74fbc85e2805f7b99f6aecde00c570">shmall</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1484635494165637"><a name="p1484635494165637"></a><a name="p1484635494165637"></a>unsigned long </p>
</td>
</tr>
<tr id="row408052266165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1404758276165637"><a name="p1404758276165637"></a><a name="p1404758276165637"></a><a href="shminfo.md#a68b65a802c7b3bc6d911ed41808203ef">__unused</a> [4]</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p243982112165637"><a name="p243982112165637"></a><a name="p243982112165637"></a>unsigned long </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section747444635165637"></a>

## **Field **<a name="section1868399011165637"></a>

## \_\_unused<a name="a68b65a802c7b3bc6d911ed41808203ef"></a>

```
unsigned long shminfo::__unused[4]
```

 **Description:**

Reserved 

## shmall<a name="a4b74fbc85e2805f7b99f6aecde00c570"></a>

```
unsigned long shminfo::shmall
```

 **Description:**

Maximum size of all shared memory segments allowed by the system 

## shmmax<a name="a2d7778854ce2e55499a2036da769905a"></a>

```
unsigned long shminfo::shmmax
```

 **Description:**

Maximum size of a shared memory segment allowed by the system 

## shmmin<a name="a9940d32ac5484be0f5df79296d9bc97a"></a>

```
unsigned long shminfo::shmmin
```

 **Description:**

Minimum size of a shared memory segment allowed by the system 

## shmmni<a name="a084bc8449e6683ede60a6445255d14bd"></a>

```
unsigned long shminfo::shmmni
```

 **Description:**

Maximum number of shared memory segments allowed by the system 

## shmseg<a name="a11ee1150ca8aaad294c17fe939f35688"></a>

```
unsigned long shminfo::shmseg
```

 **Description:**

Maximum number of shared memory segments that can be attached by a process 

