# MetaData<a name="ZH-CN_TOPIC_0000001054479571"></a>

-   [Overview](#section746570942165632)
-   [Summary](#section1210830936165632)
-   [Data Fields](#pub-attribs)
-   [Details](#section1583032792165632)
-   [Field](#section61534876165632)
-   [extra](#afb875615d3a2774cca2230a190815911)
-   [name](#ab3fee0041d776544e4305bcab5ff992a)
-   [value](#a33b9134160cc5481447142f021dd75ac)

## **Overview**<a name="section746570942165632"></a>

**Related Modules:**

[BundleManager](BundleManager.md)

**Description:**

Defines the metadata information in a  [ModuleInfo](ModuleInfo.md)  object. 

## **Summary**<a name="section1210830936165632"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table203026746165632"></a>
<table><thead align="left"><tr id="row1719554158165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1814232191165632"><a name="p1814232191165632"></a><a name="p1814232191165632"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p772471891165632"><a name="p772471891165632"></a><a name="p772471891165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row266928588165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p578527572165632"><a name="p578527572165632"></a><a name="p578527572165632"></a><a href="MetaData.md#ab3fee0041d776544e4305bcab5ff992a">name</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1937714842165632"><a name="p1937714842165632"></a><a name="p1937714842165632"></a>char * </p>
</td>
</tr>
<tr id="row818958159165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1012692732165632"><a name="p1012692732165632"></a><a name="p1012692732165632"></a><a href="MetaData.md#a33b9134160cc5481447142f021dd75ac">value</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p46557175165632"><a name="p46557175165632"></a><a name="p46557175165632"></a>char * </p>
</td>
</tr>
<tr id="row1953938405165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p134772417165632"><a name="p134772417165632"></a><a name="p134772417165632"></a><a href="MetaData.md#afb875615d3a2774cca2230a190815911">extra</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1578086402165632"><a name="p1578086402165632"></a><a name="p1578086402165632"></a>char * </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1583032792165632"></a>

## **Field **<a name="section61534876165632"></a>

## extra<a name="afb875615d3a2774cca2230a190815911"></a>

```
char* MetaData::extra
```

 **Description:**

Extra data. You can customize this field as required. 

## name<a name="ab3fee0041d776544e4305bcab5ff992a"></a>

```
char* MetaData::name
```

 **Description:**

Pointer to the metadata name 

## value<a name="a33b9134160cc5481447142f021dd75ac"></a>

```
char* MetaData::value
```

 **Description:**

Pointer to the metadata value 

