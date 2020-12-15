# LayerAlpha<a name="EN-US_TOPIC_0000001054799607"></a>

-   [Overview](#section1838686204165632)
-   [Summary](#section300763369165632)
-   [Data Fields](#pub-attribs)
-   [Details](#section1045015011165632)
-   [Field](#section677756790165632)
-   [alpha0](#a3353553145a2a896ceaeef3b16149612)
-   [alpha1](#a2b1d0f73d9ab9a17b2b41ef93c003e62)
-   [enAlpha](#adcf7ccbaaabb8180fcc896bf251f56db)
-   [enChnAlpha](#a079f3b69885e57b552016ba3c748522d)
-   [gAlpha](#a4ad49522585efedeb70e86de72d84dc0)

## **Overview**<a name="section1838686204165632"></a>

**Related Modules:**

[Display](display.md)

**Description:**

Defines alpha operations on a layer. 

## **Summary**<a name="section300763369165632"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table181348980165632"></a>
<table><thead align="left"><tr id="row1289256183165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p302322958165632"><a name="p302322958165632"></a><a name="p302322958165632"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2019535502165632"><a name="p2019535502165632"></a><a name="p2019535502165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1251914534165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1320601648165632"><a name="p1320601648165632"></a><a name="p1320601648165632"></a><a href="layeralpha.md#adcf7ccbaaabb8180fcc896bf251f56db">enAlpha</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1151221848165632"><a name="p1151221848165632"></a><a name="p1151221848165632"></a>bool </p>
</td>
</tr>
<tr id="row1068997172165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p989506634165632"><a name="p989506634165632"></a><a name="p989506634165632"></a><a href="layeralpha.md#a079f3b69885e57b552016ba3c748522d">enChnAlpha</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p62295152165632"><a name="p62295152165632"></a><a name="p62295152165632"></a>bool </p>
</td>
</tr>
<tr id="row712779319165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2123795937165632"><a name="p2123795937165632"></a><a name="p2123795937165632"></a><a href="layeralpha.md#a3353553145a2a896ceaeef3b16149612">alpha0</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p55766692165632"><a name="p55766692165632"></a><a name="p55766692165632"></a>uint8_t </p>
</td>
</tr>
<tr id="row2120057358165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p798303820165632"><a name="p798303820165632"></a><a name="p798303820165632"></a><a href="layeralpha.md#a2b1d0f73d9ab9a17b2b41ef93c003e62">alpha1</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p885577992165632"><a name="p885577992165632"></a><a name="p885577992165632"></a>uint8_t </p>
</td>
</tr>
<tr id="row1537920211165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1387792295165632"><a name="p1387792295165632"></a><a name="p1387792295165632"></a><a href="layeralpha.md#a4ad49522585efedeb70e86de72d84dc0">gAlpha</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1058666691165632"><a name="p1058666691165632"></a><a name="p1058666691165632"></a>uint8_t </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1045015011165632"></a>

## **Field **<a name="section677756790165632"></a>

## alpha0<a name="a3353553145a2a896ceaeef3b16149612"></a>

```
uint8_t LayerAlpha::alpha0
```

 **Description:**

Alpha0 value, ranging from 0 to 255 

## alpha1<a name="a2b1d0f73d9ab9a17b2b41ef93c003e62"></a>

```
uint8_t LayerAlpha::alpha1
```

 **Description:**

Alpha1 value, ranging from 0 to 255 

## enAlpha<a name="adcf7ccbaaabb8180fcc896bf251f56db"></a>

```
bool LayerAlpha::enAlpha
```

 **Description:**

Pixel alpha enable bit 

## enChnAlpha<a name="a079f3b69885e57b552016ba3c748522d"></a>

```
bool LayerAlpha::enChnAlpha
```

 **Description:**

Channel alpha enable bit 

## gAlpha<a name="a4ad49522585efedeb70e86de72d84dc0"></a>

```
uint8_t LayerAlpha::gAlpha
```

 **Description:**

Global alpha value, ranging from 0 to 255 

