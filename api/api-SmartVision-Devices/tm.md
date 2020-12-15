# tm<a name="ZH-CN_TOPIC_0000001055358158"></a>

-   [Overview](#section213291014165637)
-   [Summary](#section2100853605165637)
-   [Data Fields](#pub-attribs)
-   [Details](#section1912810085165637)
-   [Field](#section627624112165637)
-   [\_\_tm\_gmtoff](#ab077b3fcacf0aa575918483856c9cc7c)
-   [\_\_tm\_zone](#ada643d899220f1284814158a9efaf0f0)
-   [tm\_hour](#a3e7ca4e37f1abcaf56b8a916c38eb9fe)
-   [tm\_isdst](#a5645ca0580c8ab2c24f6c2965d9c9f9c)
-   [tm\_mday](#ab8d8904bad43b0c8b96e61941c5b5310)
-   [tm\_min](#af414eb7c86cc3099595211eee4d4211b)
-   [tm\_mon](#a112ac36fa2f593777138a417cf031e17)
-   [tm\_sec](#a4d098a9a5c03a00b2ee61e10851de81e)
-   [tm\_wday](#afe81a8c46f1c693c43f259b288859f4f)
-   [tm\_year](#a33adf78fd6476b2120ce3b9c4a852053)

## **Overview**<a name="section213291014165637"></a>

**Related Modules:**

[TIME](TIME.md)

**Description:**

Describes date and time information. 

## **Summary**<a name="section2100853605165637"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1052911242165637"></a>
<table><thead align="left"><tr id="row2092348828165637"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p688383844165637"><a name="p688383844165637"></a><a name="p688383844165637"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1222123289165637"><a name="p1222123289165637"></a><a name="p1222123289165637"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row231482111165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1278393952165637"><a name="p1278393952165637"></a><a name="p1278393952165637"></a><a href="tm.md#a4d098a9a5c03a00b2ee61e10851de81e">tm_sec</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1502865552165637"><a name="p1502865552165637"></a><a name="p1502865552165637"></a>int </p>
</td>
</tr>
<tr id="row230061828165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p399121745165637"><a name="p399121745165637"></a><a name="p399121745165637"></a><a href="tm.md#af414eb7c86cc3099595211eee4d4211b">tm_min</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p445927044165637"><a name="p445927044165637"></a><a name="p445927044165637"></a>int </p>
</td>
</tr>
<tr id="row649943631165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1557346461165637"><a name="p1557346461165637"></a><a name="p1557346461165637"></a><a href="tm.md#a3e7ca4e37f1abcaf56b8a916c38eb9fe">tm_hour</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p862583660165637"><a name="p862583660165637"></a><a name="p862583660165637"></a>int </p>
</td>
</tr>
<tr id="row1710551281165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p909730434165637"><a name="p909730434165637"></a><a name="p909730434165637"></a><a href="tm.md#ab8d8904bad43b0c8b96e61941c5b5310">tm_mday</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1297981051165637"><a name="p1297981051165637"></a><a name="p1297981051165637"></a>int </p>
</td>
</tr>
<tr id="row125341739165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2014893510165637"><a name="p2014893510165637"></a><a name="p2014893510165637"></a><a href="tm.md#a112ac36fa2f593777138a417cf031e17">tm_mon</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1687688377165637"><a name="p1687688377165637"></a><a name="p1687688377165637"></a>int </p>
</td>
</tr>
<tr id="row1992725178165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p175182350165637"><a name="p175182350165637"></a><a name="p175182350165637"></a><a href="tm.md#a33adf78fd6476b2120ce3b9c4a852053">tm_year</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1170264427165637"><a name="p1170264427165637"></a><a name="p1170264427165637"></a>int </p>
</td>
</tr>
<tr id="row259585164165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p291048426165637"><a name="p291048426165637"></a><a name="p291048426165637"></a><a href="tm.md#afe81a8c46f1c693c43f259b288859f4f">tm_wday</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p257709963165637"><a name="p257709963165637"></a><a name="p257709963165637"></a>int </p>
</td>
</tr>
<tr id="row1705036226165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1189608357165637"><a name="p1189608357165637"></a><a name="p1189608357165637"></a><a href="tm.md#a5645ca0580c8ab2c24f6c2965d9c9f9c">tm_isdst</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1383255074165637"><a name="p1383255074165637"></a><a name="p1383255074165637"></a>int </p>
</td>
</tr>
<tr id="row1493074539165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1044077013165637"><a name="p1044077013165637"></a><a name="p1044077013165637"></a><a href="tm.md#ab077b3fcacf0aa575918483856c9cc7c">__tm_gmtoff</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1498349964165637"><a name="p1498349964165637"></a><a name="p1498349964165637"></a>long </p>
</td>
</tr>
<tr id="row2082073370165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p284689614165637"><a name="p284689614165637"></a><a name="p284689614165637"></a><a href="tm.md#ada643d899220f1284814158a9efaf0f0">__tm_zone</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1381101024165637"><a name="p1381101024165637"></a><a name="p1381101024165637"></a>const char * </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1912810085165637"></a>

## **Field **<a name="section627624112165637"></a>

## \_\_tm\_gmtoff<a name="ab077b3fcacf0aa575918483856c9cc7c"></a>

```
long tm::__tm_gmtoff
```

 **Description:**

Seconds east of UTC 

## \_\_tm\_zone<a name="ada643d899220f1284814158a9efaf0f0"></a>

```
const char* tm::__tm_zone
```

 **Description:**

Time zone 

## tm\_hour<a name="a3e7ca4e37f1abcaf56b8a916c38eb9fe"></a>

```
int tm::tm_hour
```

 **Description:**

Hour. The value ranges from 0 to 23. 

## tm\_isdst<a name="a5645ca0580c8ab2c24f6c2965d9c9f9c"></a>

```
int tm::tm_isdst
```

 **Description:**

Daylight saving time \(DST\) 

## tm\_mday<a name="ab8d8904bad43b0c8b96e61941c5b5310"></a>

```
int tm::tm_mday
```

 **Description:**

Day. The value ranges from 1 to 31. 

## tm\_min<a name="af414eb7c86cc3099595211eee4d4211b"></a>

```
int tm::tm_min
```

 **Description:**

Minute. The value ranges from 0 to 59. 

## tm\_mon<a name="a112ac36fa2f593777138a417cf031e17"></a>

```
int tm::tm_mon
```

 **Description:**

Month. The value ranges from 0 to 11. 

## tm\_sec<a name="a4d098a9a5c03a00b2ee61e10851de81e"></a>

```
int tm::tm_sec
```

 **Description:**

Second. The value ranges from 0 to 60. 

## tm\_wday<a name="afe81a8c46f1c693c43f259b288859f4f"></a>

```
int tm::tm_wday
```

 **Description:**

Week. The value ranges from 0 to 6. The value  **0**  indicates Sunday, the value  **1**  indicates Monday, and so on. 

## tm\_year<a name="a33adf78fd6476b2120ce3b9c4a852053"></a>

```
int tm::tm_year
```

 **Description:**

Year. The value is the actual year minus 1900. 

