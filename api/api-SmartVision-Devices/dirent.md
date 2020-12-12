# dirent<a name="ZH-CN_TOPIC_0000001055198174"></a>

-   [Overview](#section1397390635165636)
-   [Summary](#section1943097188165636)
-   [Data Fields](#pub-attribs)
-   [Details](#section1485027188165636)
-   [Field](#section740521908165636)
-   [d\_ino](#aaea0878aa0629630d94e180f5dbc22c5)
-   [d\_name](#ae52d525c8057131d7f1155fe7039910d)
-   [d\_off](#af812e4ed54eeb48e843efa6fb9a5465f)
-   [d\_reclen](#a90dc47836e8ef510437317876368859e)
-   [d\_type](#adca3b20d5a245f0d8b9f2aa84844b1ff)

## **Overview**<a name="section1397390635165636"></a>

**Related Modules:**

[FS](FS.md)

**Description:**

Defines the content of the directory. 

## **Summary**<a name="section1943097188165636"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table368140534165636"></a>
<table><thead align="left"><tr id="row1768732888165636"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1095951529165636"><a name="p1095951529165636"></a><a name="p1095951529165636"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p124209812165636"><a name="p124209812165636"></a><a name="p124209812165636"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1799671262165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p862103301165636"><a name="p862103301165636"></a><a name="p862103301165636"></a><a href="dirent.md#aaea0878aa0629630d94e180f5dbc22c5">d_ino</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p918589604165636"><a name="p918589604165636"></a><a name="p918589604165636"></a>ino_t </p>
</td>
</tr>
<tr id="row1127669149165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p62307553165636"><a name="p62307553165636"></a><a name="p62307553165636"></a><a href="dirent.md#af812e4ed54eeb48e843efa6fb9a5465f">d_off</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p876167205165636"><a name="p876167205165636"></a><a name="p876167205165636"></a>off_t </p>
</td>
</tr>
<tr id="row1043141771165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p929779952165636"><a name="p929779952165636"></a><a name="p929779952165636"></a><a href="dirent.md#a90dc47836e8ef510437317876368859e">d_reclen</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1013082231165636"><a name="p1013082231165636"></a><a name="p1013082231165636"></a>unsigned short </p>
</td>
</tr>
<tr id="row337487376165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1892206625165636"><a name="p1892206625165636"></a><a name="p1892206625165636"></a><a href="dirent.md#adca3b20d5a245f0d8b9f2aa84844b1ff">d_type</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p139421312165636"><a name="p139421312165636"></a><a name="p139421312165636"></a>unsigned char </p>
</td>
</tr>
<tr id="row1370652209165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p498078041165636"><a name="p498078041165636"></a><a name="p498078041165636"></a><a href="dirent.md#ae52d525c8057131d7f1155fe7039910d">d_name</a> [256]</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p422487305165636"><a name="p422487305165636"></a><a name="p422487305165636"></a>char </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1485027188165636"></a>

## **Field **<a name="section740521908165636"></a>

## d\_ino<a name="aaea0878aa0629630d94e180f5dbc22c5"></a>

```
ino_t dirent::d_ino
```

 **Description:**

Inode number 

## d\_name<a name="ae52d525c8057131d7f1155fe7039910d"></a>

```
char dirent::d_name[256]
```

 **Description:**

File name 

## d\_off<a name="af812e4ed54eeb48e843efa6fb9a5465f"></a>

```
off_t dirent::d_off
```

 **Description:**

Offset in the directory stream 

## d\_reclen<a name="a90dc47836e8ef510437317876368859e"></a>

```
unsigned short dirent::d_reclen
```

 **Description:**

File name length 

## d\_type<a name="adca3b20d5a245f0d8b9f2aa84844b1ff"></a>

```
unsigned char dirent::d_type
```

 **Description:**

File type 

