# ModuleInfo<a name="EN-US_TOPIC_0000001054879540"></a>

-   [Overview](#section1742385662165632)
-   [Summary](#section536720864165632)
-   [Data Fields](#pub-attribs)
-   [Details](#section1298459969165632)
-   [Field](#section1622035535165632)
-   [description](#af7211393306adaa07ad32c642539b7f6)
-   [deviceType](#a7166c89b6815875afcafaca7cec21ae0)
-   [isDeliveryInstall](#a6e76e2eb535e0d92a9e49652486c35ec)
-   [metaData](#a6731b378fc6b34c7e94ab3c0d8d08e5b)
-   [moduleName](#ae194862e3cf07df40e0d41b3aa9eb1c0)
-   [moduleType](#af8f4264764394fb20c75a18a1a816ac6)
-   [name](#adb9af8c6739aaf550e91119b146eb44e)

## **Overview**<a name="section1742385662165632"></a>

**Related Modules:**

[BundleManager](bundlemanager.md)

**Description:**

Defines the HAP information. 

## **Summary**<a name="section536720864165632"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table111797152165632"></a>
<table><thead align="left"><tr id="row900924011165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1279482695165632"><a name="p1279482695165632"></a><a name="p1279482695165632"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p14384933165632"><a name="p14384933165632"></a><a name="p14384933165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row346216274165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1024839696165632"><a name="p1024839696165632"></a><a name="p1024839696165632"></a><a href="moduleinfo.md#ae194862e3cf07df40e0d41b3aa9eb1c0">moduleName</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2061013559165632"><a name="p2061013559165632"></a><a name="p2061013559165632"></a>char * </p>
</td>
</tr>
<tr id="row705920526165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p267597975165632"><a name="p267597975165632"></a><a name="p267597975165632"></a><a href="moduleinfo.md#af7211393306adaa07ad32c642539b7f6">description</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1828817109165632"><a name="p1828817109165632"></a><a name="p1828817109165632"></a>char * </p>
</td>
</tr>
<tr id="row1271137815165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1354582799165632"><a name="p1354582799165632"></a><a name="p1354582799165632"></a><a href="moduleinfo.md#adb9af8c6739aaf550e91119b146eb44e">name</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1553485167165632"><a name="p1553485167165632"></a><a name="p1553485167165632"></a>char * </p>
</td>
</tr>
<tr id="row1302726094165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p157973652165632"><a name="p157973652165632"></a><a name="p157973652165632"></a><a href="moduleinfo.md#af8f4264764394fb20c75a18a1a816ac6">moduleType</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1967065313165632"><a name="p1967065313165632"></a><a name="p1967065313165632"></a>char * </p>
</td>
</tr>
<tr id="row655208366165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1595717464165632"><a name="p1595717464165632"></a><a name="p1595717464165632"></a><a href="moduleinfo.md#a6e76e2eb535e0d92a9e49652486c35ec">isDeliveryInstall</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1623018411165632"><a name="p1623018411165632"></a><a name="p1623018411165632"></a>bool </p>
</td>
</tr>
<tr id="row2146426936165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p595339022165632"><a name="p595339022165632"></a><a name="p595339022165632"></a><a href="moduleinfo.md#a7166c89b6815875afcafaca7cec21ae0">deviceType</a> [DEVICE_TYPE_SIZE]</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2112320323165632"><a name="p2112320323165632"></a><a name="p2112320323165632"></a>char * </p>
</td>
</tr>
<tr id="row1236419388165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p607879479165632"><a name="p607879479165632"></a><a name="p607879479165632"></a><a href="moduleinfo.md#a6731b378fc6b34c7e94ab3c0d8d08e5b">metaData</a> [METADATA_SIZE]</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p741744045165632"><a name="p741744045165632"></a><a name="p741744045165632"></a><a href="metadata.md">MetaData</a> * </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1298459969165632"></a>

## **Field **<a name="section1622035535165632"></a>

## description<a name="af7211393306adaa07ad32c642539b7f6"></a>

```
char* ModuleInfo::description
```

 **Description:**

Pointer to the description of the HAP package 

## deviceType<a name="a7166c89b6815875afcafaca7cec21ae0"></a>

```
char* ModuleInfo::deviceType[DEVICE_TYPE_SIZE]
```

 **Description:**

Pointer to the types of devices that can run the application. The maximum size of the device type array is  **DEVICE\_TYPE\_SIZE**. 

## isDeliveryInstall<a name="a6e76e2eb535e0d92a9e49652486c35ec"></a>

```
bool ModuleInfo::isDeliveryInstall
```

 **Description:**

Whether the HAP package is installed while the user is installing the application 

## metaData<a name="a6731b378fc6b34c7e94ab3c0d8d08e5b"></a>

```
[MetaData](metadata.md)* ModuleInfo::metaData[METADATA_SIZE]
```

 **Description:**

Pointer to the metadata array whose maximum size is  **METADATA\_SIZE** 

## moduleName<a name="ae194862e3cf07df40e0d41b3aa9eb1c0"></a>

```
char* ModuleInfo::moduleName
```

 **Description:**

Pointer to the HAP package name 

## moduleType<a name="af8f4264764394fb20c75a18a1a816ac6"></a>

```
char* ModuleInfo::moduleType
```

 **Description:**

Type of the HAP package, either  **Entry.hap**  or  **Feature.hap** 

## name<a name="adb9af8c6739aaf550e91119b146eb44e"></a>

```
char* ModuleInfo::name
```

 **Description:**

Pointer to the class name of the HAP package 

