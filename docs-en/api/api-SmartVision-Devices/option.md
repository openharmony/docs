# option<a name="EN-US_TOPIC_0000001054718173"></a>

-   [Overview](#section1520105783165637)
-   [Summary](#section394430251165637)
-   [Data Fields](#pub-attribs)
-   [Details](#section903750371165637)
-   [Field](#section657119121165637)
-   [flag](#ab366eea5fe7be25c1928328ba715e353)
-   [has\_arg](#a90d7ee9a51eea5c002682dbd0af149e4)
-   [name](#adc503659d37af8017fb4b86d61c99086)
-   [val](#a13bd155ec3b405d29c41ab8d0793be11)

## **Overview**<a name="section1520105783165637"></a>

**Related Modules:**

[UTILS](utils.md)

**Description:**

Defines the command parsing option. 

## **Summary**<a name="section394430251165637"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table181664632165637"></a>
<table><thead align="left"><tr id="row1758499926165637"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2099531633165637"><a name="p2099531633165637"></a><a name="p2099531633165637"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1844602718165637"><a name="p1844602718165637"></a><a name="p1844602718165637"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row753135216165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2005961835165637"><a name="p2005961835165637"></a><a name="p2005961835165637"></a><a href="option.md#adc503659d37af8017fb4b86d61c99086">name</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1392635456165637"><a name="p1392635456165637"></a><a name="p1392635456165637"></a>const char * </p>
</td>
</tr>
<tr id="row2140339884165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p226311424165637"><a name="p226311424165637"></a><a name="p226311424165637"></a><a href="option.md#a90d7ee9a51eea5c002682dbd0af149e4">has_arg</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p671275521165637"><a name="p671275521165637"></a><a name="p671275521165637"></a>int </p>
</td>
</tr>
<tr id="row1060320127165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1453780106165637"><a name="p1453780106165637"></a><a name="p1453780106165637"></a><a href="option.md#ab366eea5fe7be25c1928328ba715e353">flag</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p919555486165637"><a name="p919555486165637"></a><a name="p919555486165637"></a>int * </p>
</td>
</tr>
<tr id="row1674008195165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p431552934165637"><a name="p431552934165637"></a><a name="p431552934165637"></a><a href="option.md#a13bd155ec3b405d29c41ab8d0793be11">val</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1027794085165637"><a name="p1027794085165637"></a><a name="p1027794085165637"></a>int </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section903750371165637"></a>

## **Field **<a name="section657119121165637"></a>

## flag<a name="ab366eea5fe7be25c1928328ba715e353"></a>

```
int* option::flag
```

 **Description:**

Determines the returned value of the  **[getopt\(\)](utils.md#ga5ffa4c677fc71cecd94f140ef9db624c)**  function. If  **flag**  is  **NULL**, the  **[getopt\(\)](utils.md#ga5ffa4c677fc71cecd94f140ef9db624c)**  function returns the  **val**  value that matches the option. If  **flag**  is not  **NULL**, assign the  **val**  value to the memory to which  **flag**  points, and set the returned value to  **0**. 

## has\_arg<a name="a90d7ee9a51eea5c002682dbd0af149e4"></a>

```
int option::has_arg
```

 **Description:**

**has\_arg**  has three values.  **0**  indicates that the argument is not followed by an argument value,  **1**  indicates that the argument must be followed by an argument value, and  **2**  indicates that the argument can be followed or not followed by an argument value. 

## name<a name="adc503659d37af8017fb4b86d61c99086"></a>

```
const char* option::name
```

 **Description:**

Long argument name 

## val<a name="a13bd155ec3b405d29c41ab8d0793be11"></a>

```
int option::val
```

 **Description:**

The returned value is determined by  **flag**. 

