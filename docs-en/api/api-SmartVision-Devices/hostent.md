# hostent<a name="EN-US_TOPIC_0000001055678138"></a>

-   [Overview](#section862259847165636)
-   [Summary](#section75161095165636)
-   [Data Fields](#pub-attribs)
-   [Details](#section1086710868165636)
-   [Field](#section298257867165636)
-   [h\_addr\_list](#a4ff8499f29c5111435d6ed4adccfb621)
-   [h\_addrtype](#a405ebb31a6922898809635b03f0faf06)
-   [h\_aliases](#ac266a0b528443e9479f2d8e1680b5e78)
-   [h\_length](#ab9db18bfcc6adfc9c944b0c06ec2dccc)
-   [h\_name](#a439d6e5efa18bc14aab63b14a12ae371)

## **Overview**<a name="section862259847165636"></a>

**Related Modules:**

[NET](net.md)

**Description:**

Describes the host name and address information. 

## **Summary**<a name="section75161095165636"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1523938324165636"></a>
<table><thead align="left"><tr id="row1623690474165636"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2145720901165636"><a name="p2145720901165636"></a><a name="p2145720901165636"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2112395479165636"><a name="p2112395479165636"></a><a name="p2112395479165636"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row354329276165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1124026638165636"><a name="p1124026638165636"></a><a name="p1124026638165636"></a><a href="hostent.md#a439d6e5efa18bc14aab63b14a12ae371">h_name</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1644985406165636"><a name="p1644985406165636"></a><a name="p1644985406165636"></a>char * </p>
</td>
</tr>
<tr id="row1489591602165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p480890073165636"><a name="p480890073165636"></a><a name="p480890073165636"></a><a href="hostent.md#ac266a0b528443e9479f2d8e1680b5e78">h_aliases</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p700985326165636"><a name="p700985326165636"></a><a name="p700985326165636"></a>char ** </p>
</td>
</tr>
<tr id="row751426161165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p281871393165636"><a name="p281871393165636"></a><a name="p281871393165636"></a><a href="hostent.md#a405ebb31a6922898809635b03f0faf06">h_addrtype</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1593403933165636"><a name="p1593403933165636"></a><a name="p1593403933165636"></a>int </p>
</td>
</tr>
<tr id="row2127285309165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p556208867165636"><a name="p556208867165636"></a><a name="p556208867165636"></a><a href="hostent.md#ab9db18bfcc6adfc9c944b0c06ec2dccc">h_length</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1095617334165636"><a name="p1095617334165636"></a><a name="p1095617334165636"></a>int </p>
</td>
</tr>
<tr id="row903251405165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1638184392165636"><a name="p1638184392165636"></a><a name="p1638184392165636"></a><a href="hostent.md#a4ff8499f29c5111435d6ed4adccfb621">h_addr_list</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p161546041165636"><a name="p161546041165636"></a><a name="p161546041165636"></a>char ** </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1086710868165636"></a>

## **Field **<a name="section298257867165636"></a>

## h\_addr\_list<a name="a4ff8499f29c5111435d6ed4adccfb621"></a>

```
char** hostent::h_addr_list
```

 **Description:**

A pointer to an array of pointers to host addresses 

## h\_addrtype<a name="a405ebb31a6922898809635b03f0faf06"></a>

```
int hostent::h_addrtype
```

 **Description:**

IP address type 

## h\_aliases<a name="ac266a0b528443e9479f2d8e1680b5e78"></a>

```
char** hostent::h_aliases
```

 **Description:**

A pointer to an array of pointers to alternative host names 

## h\_length<a name="ab9db18bfcc6adfc9c944b0c06ec2dccc"></a>

```
int hostent::h_length
```

 **Description:**

Address length 

## h\_name<a name="a439d6e5efa18bc14aab63b14a12ae371"></a>

```
char* hostent::h_name
```

 **Description:**

A pointer to the host name 

