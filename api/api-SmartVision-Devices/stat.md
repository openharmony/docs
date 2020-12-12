# stat<a name="ZH-CN_TOPIC_0000001054718175"></a>

-   [Overview](#section61461440165637)
-   [Summary](#section273480706165637)
-   [Data Fields](#pub-attribs)
-   [Details](#section8458918165637)
-   [Field](#section896575698165637)
-   [st\_atime](#a69479adde11305b3952929a3788da6a4)
-   [st\_atime\_nsec](#a9ebc9f4f22737f17a8e85eaa192074d2)
-   [st\_blksize](#a637830d59004ce7b2bfbc684215cac5a)
-   [st\_blocks](#aa49bbffca4dfbe619ec4d25528db589c)
-   [st\_ctime](#adb96adc3e528fadacbc1f925d626a327)
-   [st\_ctime\_nsec](#a842e64ce0cb7833e4d6a4ca7ab9f2f4f)
-   [st\_dev](#a571c4887bc0064ba0f673eb19b61aa90)
-   [st\_gid](#a0a816257595eebd717ab8b9f7cb6e8d8)
-   [st\_ino](#a420fc2454334a400de3c5d55484b0b73)
-   [st\_mode](#a7278b9464298495a4c0d7a722598392a)
-   [st\_mtime](#a8e30df36b142416a21d280dcc5833fcc)
-   [st\_mtime\_nsec](#a5abfb8c4ff18fdbf3ecebe716976cf77)
-   [st\_nlink](#a7865ec265afbe7acf286d49c4a5be84b)
-   [st\_rdev](#aeda9f3b3d0caf6f087d5b3e7cc4c3ac3)
-   [st\_size](#ac5a52532e8a4feb60f82e60525ec8aa2)
-   [st\_uid](#a5d5f186135107ad27e7598919a40bdbd)

## **Overview**<a name="section61461440165637"></a>

**Related Modules:**

[FS](FS.md)

**Description:**

Defines the file information structure. 

## **Summary**<a name="section273480706165637"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table277462435165637"></a>
<table><thead align="left"><tr id="row1912873052165637"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p409528048165637"><a name="p409528048165637"></a><a name="p409528048165637"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1346989524165637"><a name="p1346989524165637"></a><a name="p1346989524165637"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1923382287165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p753313852165637"><a name="p753313852165637"></a><a name="p753313852165637"></a><a href="stat.md#a571c4887bc0064ba0f673eb19b61aa90">st_dev</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1794740612165637"><a name="p1794740612165637"></a><a name="p1794740612165637"></a>unsigned long </p>
</td>
</tr>
<tr id="row295220810165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2134935638165637"><a name="p2134935638165637"></a><a name="p2134935638165637"></a><a href="stat.md#a420fc2454334a400de3c5d55484b0b73">st_ino</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p122860322165637"><a name="p122860322165637"></a><a name="p122860322165637"></a>unsigned long </p>
</td>
</tr>
<tr id="row629164083165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p392460066165637"><a name="p392460066165637"></a><a name="p392460066165637"></a><a href="stat.md#a7278b9464298495a4c0d7a722598392a">st_mode</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p487783767165637"><a name="p487783767165637"></a><a name="p487783767165637"></a>unsigned short </p>
</td>
</tr>
<tr id="row177167285165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1935980755165637"><a name="p1935980755165637"></a><a name="p1935980755165637"></a><a href="stat.md#a7865ec265afbe7acf286d49c4a5be84b">st_nlink</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1643308424165637"><a name="p1643308424165637"></a><a name="p1643308424165637"></a>unsigned short </p>
</td>
</tr>
<tr id="row78771830165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1981267560165637"><a name="p1981267560165637"></a><a name="p1981267560165637"></a><a href="stat.md#a5d5f186135107ad27e7598919a40bdbd">st_uid</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p676178344165637"><a name="p676178344165637"></a><a name="p676178344165637"></a>unsigned short </p>
</td>
</tr>
<tr id="row1764905846165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1520009991165637"><a name="p1520009991165637"></a><a name="p1520009991165637"></a><a href="stat.md#a0a816257595eebd717ab8b9f7cb6e8d8">st_gid</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p65429680165637"><a name="p65429680165637"></a><a name="p65429680165637"></a>unsigned short </p>
</td>
</tr>
<tr id="row1788563612165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1172520147165637"><a name="p1172520147165637"></a><a name="p1172520147165637"></a><a href="stat.md#aeda9f3b3d0caf6f087d5b3e7cc4c3ac3">st_rdev</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p311661944165637"><a name="p311661944165637"></a><a name="p311661944165637"></a>unsigned long </p>
</td>
</tr>
<tr id="row1602397855165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1309630862165637"><a name="p1309630862165637"></a><a name="p1309630862165637"></a><a href="stat.md#ac5a52532e8a4feb60f82e60525ec8aa2">st_size</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1900412572165637"><a name="p1900412572165637"></a><a name="p1900412572165637"></a>unsigned long </p>
</td>
</tr>
<tr id="row1549050259165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1505185393165637"><a name="p1505185393165637"></a><a name="p1505185393165637"></a><a href="stat.md#a637830d59004ce7b2bfbc684215cac5a">st_blksize</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1142884112165637"><a name="p1142884112165637"></a><a name="p1142884112165637"></a>unsigned long </p>
</td>
</tr>
<tr id="row920585620165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1838221864165637"><a name="p1838221864165637"></a><a name="p1838221864165637"></a><a href="stat.md#aa49bbffca4dfbe619ec4d25528db589c">st_blocks</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1319298977165637"><a name="p1319298977165637"></a><a name="p1319298977165637"></a>unsigned long </p>
</td>
</tr>
<tr id="row1793815575165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p595538944165637"><a name="p595538944165637"></a><a name="p595538944165637"></a><a href="stat.md#a69479adde11305b3952929a3788da6a4">st_atime</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p289306834165637"><a name="p289306834165637"></a><a name="p289306834165637"></a>unsigned long </p>
</td>
</tr>
<tr id="row1960159679165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p28792425165637"><a name="p28792425165637"></a><a name="p28792425165637"></a><a href="stat.md#a9ebc9f4f22737f17a8e85eaa192074d2">st_atime_nsec</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2005783895165637"><a name="p2005783895165637"></a><a name="p2005783895165637"></a>unsigned long </p>
</td>
</tr>
<tr id="row541620356165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1672173605165637"><a name="p1672173605165637"></a><a name="p1672173605165637"></a><a href="stat.md#a8e30df36b142416a21d280dcc5833fcc">st_mtime</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p632664214165637"><a name="p632664214165637"></a><a name="p632664214165637"></a>unsigned long </p>
</td>
</tr>
<tr id="row944555169165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p426773897165637"><a name="p426773897165637"></a><a name="p426773897165637"></a><a href="stat.md#a5abfb8c4ff18fdbf3ecebe716976cf77">st_mtime_nsec</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p32078257165637"><a name="p32078257165637"></a><a name="p32078257165637"></a>unsigned long </p>
</td>
</tr>
<tr id="row1653085593165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1374198715165637"><a name="p1374198715165637"></a><a name="p1374198715165637"></a><a href="stat.md#adb96adc3e528fadacbc1f925d626a327">st_ctime</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2024160978165637"><a name="p2024160978165637"></a><a name="p2024160978165637"></a>unsigned long </p>
</td>
</tr>
<tr id="row1830358731165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2071282902165637"><a name="p2071282902165637"></a><a name="p2071282902165637"></a><a href="stat.md#a842e64ce0cb7833e4d6a4ca7ab9f2f4f">st_ctime_nsec</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1948529257165637"><a name="p1948529257165637"></a><a name="p1948529257165637"></a>unsigned long </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section8458918165637"></a>

## **Field **<a name="section896575698165637"></a>

## st\_atime<a name="a69479adde11305b3952929a3788da6a4"></a>

```
unsigned long stat::st_atime
```

 **Description:**

Time when the file is accessed for the last time which is represented by the number of seconds passed since 00:00:00 on January 1, 1970 

## st\_atime\_nsec<a name="a9ebc9f4f22737f17a8e85eaa192074d2"></a>

```
unsigned long stat::st_atime_nsec
```

 **Description:**

Time when the file is accessed for the last time, which is represented by the number of nanoseconds 

## st\_blksize<a name="a637830d59004ce7b2bfbc684215cac5a"></a>

```
unsigned long stat::st_blksize
```

 **Description:**

Size of the disk block that contains the file 

## st\_blocks<a name="aa49bbffca4dfbe619ec4d25528db589c"></a>

```
unsigned long stat::st_blocks
```

 **Description:**

Number of disk blocks occupied by the file 

## st\_ctime<a name="adb96adc3e528fadacbc1f925d626a327"></a>

```
unsigned long stat::st_ctime
```

 **Description:**

Time when the file state is modified for the last time, which is represented by the number of seconds 

## st\_ctime\_nsec<a name="a842e64ce0cb7833e4d6a4ca7ab9f2f4f"></a>

```
unsigned long stat::st_ctime_nsec
```

 **Description:**

Time when the file state is modified for the last time, which is represented by the number of nanoseconds 

## st\_dev<a name="a571c4887bc0064ba0f673eb19b61aa90"></a>

```
unsigned long stat::st_dev
```

 **Description:**

Device ID used by the file 

## st\_gid<a name="a0a816257595eebd717ab8b9f7cb6e8d8"></a>

```
unsigned short stat::st_gid
```

 **Description:**

Group ID 

## st\_ino<a name="a420fc2454334a400de3c5d55484b0b73"></a>

```
unsigned long stat::st_ino
```

 **Description:**

Inode number 

## st\_mode<a name="a7278b9464298495a4c0d7a722598392a"></a>

```
unsigned short stat::st_mode
```

 **Description:**

File mode, including  **S\_IFDIR**  \(Directory\),  **S\_IFCHR**  \(Character device\),  **S\_IFBLK**  \(Block device\),  **S\_IFREG**  \(Regular file\),  **S\_IFIFO**  \(FIFO\),  **S\_IFLNK**  \(Symbolic link\), and  **S\_IFSOCK**  \(Socket\) 

## st\_mtime<a name="a8e30df36b142416a21d280dcc5833fcc"></a>

```
unsigned long stat::st_mtime
```

 **Description:**

Time when the file is modified for the last time which is represented by the number of seconds passed since 00:00:00 on January 1, 1970 

## st\_mtime\_nsec<a name="a5abfb8c4ff18fdbf3ecebe716976cf77"></a>

```
unsigned long stat::st_mtime_nsec
```

 **Description:**

Time when the file is modified for the last time, which is represented by the number of nanoseconds 

## st\_nlink<a name="a7865ec265afbe7acf286d49c4a5be84b"></a>

```
unsigned short stat::st_nlink
```

 **Description:**

Number of hard links 

## st\_rdev<a name="aeda9f3b3d0caf6f087d5b3e7cc4c3ac3"></a>

```
unsigned long stat::st_rdev
```

 **Description:**

Device ID of the device file 

## st\_size<a name="ac5a52532e8a4feb60f82e60525ec8aa2"></a>

```
unsigned long stat::st_size
```

 **Description:**

File size in bytes 

## st\_uid<a name="a5d5f186135107ad27e7598919a40bdbd"></a>

```
unsigned short stat::st_uid
```

 **Description:**

User ID of owner 

