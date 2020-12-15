# statvfs<a name="EN-US_TOPIC_0000001055678142"></a>

-   [Overview](#section2044054788165637)
-   [Summary](#section1184727561165637)
-   [Data Fields](#pub-attribs)
-   [Details](#section1267364075165637)
-   [Field](#section1524441371165637)
-   [\_\_reserved](#a57b706767c1a69cdb86c33e7196fe647)
-   [f\_bavail](#a38e0b0109797e233de83ff9e8c4d0520)
-   [f\_bfree](#ab004873a74b951610b969a222116dccb)
-   [f\_blocks](#a83b2d1725a43fef463597eda75b7af1b)
-   [f\_bsize](#a3400d89a2627d6313da0cb39ff6209ec)
-   [f\_favail](#a6f336f60b6cba33b9380181ef413022f)
-   [f\_ffree](#a601437cadd9c607cba0c653706af3d22)
-   [f\_files](#a38f6a9335cabe3bff82c2d96cc538e6f)
-   [f\_flag](#adb8f52b3e1b3a90358ec3e97e56aafcd)
-   [f\_frsize](#af01dafa58ce2f665bc8b6ba1741f1896)
-   [f\_fsid](#a1a180e536ad58f06b0c05d913d0ae9cf)
-   [f\_namemax](#a138cd6cae031d89d7ae90649fb667696)

## **Overview**<a name="section2044054788165637"></a>

**Related Modules:**

[FS](fs.md)

**Description:**

Describes file system information. 

## **Summary**<a name="section1184727561165637"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1792759314165637"></a>
<table><thead align="left"><tr id="row2026818172165637"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p931549021165637"><a name="p931549021165637"></a><a name="p931549021165637"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1633803627165637"><a name="p1633803627165637"></a><a name="p1633803627165637"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2001834583165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p953761690165637"><a name="p953761690165637"></a><a name="p953761690165637"></a><a href="statvfs.md#a3400d89a2627d6313da0cb39ff6209ec">f_bsize</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p356960123165637"><a name="p356960123165637"></a><a name="p356960123165637"></a>unsigned long </p>
</td>
</tr>
<tr id="row699021029165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2124330337165637"><a name="p2124330337165637"></a><a name="p2124330337165637"></a><a href="statvfs.md#af01dafa58ce2f665bc8b6ba1741f1896">f_frsize</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1816512097165637"><a name="p1816512097165637"></a><a name="p1816512097165637"></a>unsigned long </p>
</td>
</tr>
<tr id="row1017889646165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1137399787165637"><a name="p1137399787165637"></a><a name="p1137399787165637"></a><a href="statvfs.md#a83b2d1725a43fef463597eda75b7af1b">f_blocks</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p530731059165637"><a name="p530731059165637"></a><a name="p530731059165637"></a>fsblkcnt_t </p>
</td>
</tr>
<tr id="row1837501157165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p532718118165637"><a name="p532718118165637"></a><a name="p532718118165637"></a><a href="statvfs.md#ab004873a74b951610b969a222116dccb">f_bfree</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1290920164165637"><a name="p1290920164165637"></a><a name="p1290920164165637"></a>fsblkcnt_t </p>
</td>
</tr>
<tr id="row1983035060165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p921892712165637"><a name="p921892712165637"></a><a name="p921892712165637"></a><a href="statvfs.md#a38e0b0109797e233de83ff9e8c4d0520">f_bavail</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1759613905165637"><a name="p1759613905165637"></a><a name="p1759613905165637"></a>fsblkcnt_t </p>
</td>
</tr>
<tr id="row791551050165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1226820710165637"><a name="p1226820710165637"></a><a name="p1226820710165637"></a><a href="statvfs.md#a38f6a9335cabe3bff82c2d96cc538e6f">f_files</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p827153462165637"><a name="p827153462165637"></a><a name="p827153462165637"></a>fsfilcnt_t </p>
</td>
</tr>
<tr id="row1926025095165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p435081367165637"><a name="p435081367165637"></a><a name="p435081367165637"></a><a href="statvfs.md#a601437cadd9c607cba0c653706af3d22">f_ffree</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p647566463165637"><a name="p647566463165637"></a><a name="p647566463165637"></a>fsfilcnt_t </p>
</td>
</tr>
<tr id="row283375812165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1476386138165637"><a name="p1476386138165637"></a><a name="p1476386138165637"></a><a href="statvfs.md#a6f336f60b6cba33b9380181ef413022f">f_favail</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p14203768165637"><a name="p14203768165637"></a><a name="p14203768165637"></a>fsfilcnt_t </p>
</td>
</tr>
<tr id="row1485160688165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p295392197165637"><a name="p295392197165637"></a><a name="p295392197165637"></a><a href="statvfs.md#a1a180e536ad58f06b0c05d913d0ae9cf">f_fsid</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1211103700165637"><a name="p1211103700165637"></a><a name="p1211103700165637"></a>unsigned long </p>
</td>
</tr>
<tr id="row408352132165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p542515778165637"><a name="p542515778165637"></a><a name="p542515778165637"></a><a href="statvfs.md#adb8f52b3e1b3a90358ec3e97e56aafcd">f_flag</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1062726209165637"><a name="p1062726209165637"></a><a name="p1062726209165637"></a>unsigned long </p>
</td>
</tr>
<tr id="row971797808165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p52349245165637"><a name="p52349245165637"></a><a name="p52349245165637"></a><a href="statvfs.md#a138cd6cae031d89d7ae90649fb667696">f_namemax</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p832210954165637"><a name="p832210954165637"></a><a name="p832210954165637"></a>unsigned long </p>
</td>
</tr>
<tr id="row383831073165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1884302589165637"><a name="p1884302589165637"></a><a name="p1884302589165637"></a><a href="statvfs.md#a57b706767c1a69cdb86c33e7196fe647">__reserved</a> [6]</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p510802318165637"><a name="p510802318165637"></a><a name="p510802318165637"></a>int </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1267364075165637"></a>

## **Field **<a name="section1524441371165637"></a>

## \_\_reserved<a name="a57b706767c1a69cdb86c33e7196fe647"></a>

```
int statvfs::__reserved[6]
```

 **Description:**

Reserved 

## f\_bavail<a name="a38e0b0109797e233de83ff9e8c4d0520"></a>

```
fsblkcnt_t statvfs::f_bavail
```

 **Description:**

Free blocks for unprivileged users 

## f\_bfree<a name="ab004873a74b951610b969a222116dccb"></a>

```
fsblkcnt_t statvfs::f_bfree
```

 **Description:**

Free blocks 

## f\_blocks<a name="a83b2d1725a43fef463597eda75b7af1b"></a>

```
fsblkcnt_t statvfs::f_blocks
```

 **Description:**

Size of  **fs**, in units of  **f\_frsize** 

## f\_bsize<a name="a3400d89a2627d6313da0cb39ff6209ec"></a>

```
unsigned long statvfs::f_bsize
```

 **Description:**

File system block size 

## f\_favail<a name="a6f336f60b6cba33b9380181ef413022f"></a>

```
fsfilcnt_t statvfs::f_favail
```

 **Description:**

Free inodes for unprivileged users 

## f\_ffree<a name="a601437cadd9c607cba0c653706af3d22"></a>

```
fsfilcnt_t statvfs::f_ffree
```

 **Description:**

Free inodes 

## f\_files<a name="a38f6a9335cabe3bff82c2d96cc538e6f"></a>

```
fsfilcnt_t statvfs::f_files
```

 **Description:**

File nodes \(inodes\) 

## f\_flag<a name="adb8f52b3e1b3a90358ec3e97e56aafcd"></a>

```
unsigned long statvfs::f_flag
```

 **Description:**

Mount flags 

## f\_frsize<a name="af01dafa58ce2f665bc8b6ba1741f1896"></a>

```
unsigned long statvfs::f_frsize
```

 **Description:**

Fragment size 

## f\_fsid<a name="a1a180e536ad58f06b0c05d913d0ae9cf"></a>

```
unsigned long statvfs::f_fsid
```

 **Description:**

File system ID 

## f\_namemax<a name="a138cd6cae031d89d7ae90649fb667696"></a>

```
unsigned long statvfs::f_namemax
```

 **Description:**

Maximum file name length 

