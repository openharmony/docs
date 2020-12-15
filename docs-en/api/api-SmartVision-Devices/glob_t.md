# glob\_t<a name="EN-US_TOPIC_0000001054718171"></a>

-   [Overview](#section687133126165636)
-   [Summary](#section624234065165636)
-   [Data Fields](#pub-attribs)
-   [Details](#section341760664165636)
-   [Field](#section503539067165636)
-   [gl\_offs](#ada6945e8f6ca53ecf82c9d736fb5307e)
-   [gl\_pathc](#a69dc492f370a9793f06c11e3eb12f199)
-   [gl\_pathv](#abd9ba3e5bd7a4767af2cd3dd98a2a64f)

## **Overview**<a name="section687133126165636"></a>

**Related Modules:**

[FS](fs.md)

**Description:**

Defines the search information. 

This structure is used to store information about matched files. 

## **Summary**<a name="section624234065165636"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1645571188165636"></a>
<table><thead align="left"><tr id="row987874000165636"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p729766468165636"><a name="p729766468165636"></a><a name="p729766468165636"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p900807525165636"><a name="p900807525165636"></a><a name="p900807525165636"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1307546020165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2057856807165636"><a name="p2057856807165636"></a><a name="p2057856807165636"></a><a href="glob_t.md#a69dc492f370a9793f06c11e3eb12f199">gl_pathc</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p143616628165636"><a name="p143616628165636"></a><a name="p143616628165636"></a>size_t </p>
</td>
</tr>
<tr id="row668271798165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1488996309165636"><a name="p1488996309165636"></a><a name="p1488996309165636"></a><a href="glob_t.md#abd9ba3e5bd7a4767af2cd3dd98a2a64f">gl_pathv</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1834646503165636"><a name="p1834646503165636"></a><a name="p1834646503165636"></a>char ** </p>
</td>
</tr>
<tr id="row404332084165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1652138949165636"><a name="p1652138949165636"></a><a name="p1652138949165636"></a><a href="glob_t.md#ada6945e8f6ca53ecf82c9d736fb5307e">gl_offs</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p653403764165636"><a name="p653403764165636"></a><a name="p653403764165636"></a>size_t </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section341760664165636"></a>

## **Field **<a name="section503539067165636"></a>

## gl\_offs<a name="ada6945e8f6ca53ecf82c9d736fb5307e"></a>

```
size_t glob_t::gl_offs
```

 **Description:**

Slots to reserve in  **gl\_pathv** 

## gl\_pathc<a name="a69dc492f370a9793f06c11e3eb12f199"></a>

```
size_t glob_t::gl_pathc
```

 **Description:**

Number of matched paths so far 

## gl\_pathv<a name="abd9ba3e5bd7a4767af2cd3dd98a2a64f"></a>

```
char** glob_t::gl_pathv
```

 **Description:**

List of matched path names 

