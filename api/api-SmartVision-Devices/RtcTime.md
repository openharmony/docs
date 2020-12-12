# RtcTime<a name="ZH-CN_TOPIC_0000001054598197"></a>

-   [Overview](#section1920620469165636)
-   [Summary](#section702724698165636)
-   [Data Fields](#pub-attribs)
-   [Details](#section43113685165636)
-   [Field](#section618246028165636)
-   [day](#aad7e09d86beed6186b75ce2f1361f20b)
-   [hour](#a0dc9482d29a4b61184b281b766b0ff89)
-   [millisecond](#afbfa636802d9e4e3b8502d4619ed771f)
-   [minute](#a990d7d066bc918d0b2f19162deb1845f)
-   [month](#a527b18b3a0b709966d04106f0a5aed78)
-   [second](#a8d7d49086d28faf2f700c45aab23c58b)
-   [weekday](#aae45834a39c6b4a03dc85da72298b37e)
-   [year](#a7781f6e9f083f7f24aa359651eadd19b)

## **Overview**<a name="section1920620469165636"></a>

**Related Modules:**

[RTC](RTC.md)

**Description:**

Defines the RTC information. 

The RTC information includes the year, month, day, day of the week, hour, minute, second, and millisecond. The start time is 1970/01/01 Thursday 00:00:00 \(UTC\). 

## **Summary**<a name="section702724698165636"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1236802191165636"></a>
<table><thead align="left"><tr id="row1195771438165636"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1016881402165636"><a name="p1016881402165636"></a><a name="p1016881402165636"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2087501666165636"><a name="p2087501666165636"></a><a name="p2087501666165636"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1425147343165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p720271397165636"><a name="p720271397165636"></a><a name="p720271397165636"></a><a href="RtcTime.md#a8d7d49086d28faf2f700c45aab23c58b">second</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p181151251165636"><a name="p181151251165636"></a><a name="p181151251165636"></a>uint8_t </p>
</td>
</tr>
<tr id="row199491387165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1633145976165636"><a name="p1633145976165636"></a><a name="p1633145976165636"></a><a href="RtcTime.md#a990d7d066bc918d0b2f19162deb1845f">minute</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1809190093165636"><a name="p1809190093165636"></a><a name="p1809190093165636"></a>uint8_t </p>
</td>
</tr>
<tr id="row251369547165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p250044856165636"><a name="p250044856165636"></a><a name="p250044856165636"></a><a href="RtcTime.md#a0dc9482d29a4b61184b281b766b0ff89">hour</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p970334129165636"><a name="p970334129165636"></a><a name="p970334129165636"></a>uint8_t </p>
</td>
</tr>
<tr id="row882037824165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2077678990165636"><a name="p2077678990165636"></a><a name="p2077678990165636"></a><a href="RtcTime.md#aad7e09d86beed6186b75ce2f1361f20b">day</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p366903730165636"><a name="p366903730165636"></a><a name="p366903730165636"></a>uint8_t </p>
</td>
</tr>
<tr id="row544651578165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1360068906165636"><a name="p1360068906165636"></a><a name="p1360068906165636"></a><a href="RtcTime.md#aae45834a39c6b4a03dc85da72298b37e">weekday</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p913100679165636"><a name="p913100679165636"></a><a name="p913100679165636"></a>uint8_t </p>
</td>
</tr>
<tr id="row1969449793165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p651508245165636"><a name="p651508245165636"></a><a name="p651508245165636"></a><a href="RtcTime.md#a527b18b3a0b709966d04106f0a5aed78">month</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1993793859165636"><a name="p1993793859165636"></a><a name="p1993793859165636"></a>uint8_t </p>
</td>
</tr>
<tr id="row575381925165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2036303264165636"><a name="p2036303264165636"></a><a name="p2036303264165636"></a><a href="RtcTime.md#a7781f6e9f083f7f24aa359651eadd19b">year</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2134881469165636"><a name="p2134881469165636"></a><a name="p2134881469165636"></a>uint16_t </p>
</td>
</tr>
<tr id="row1315329353165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1961426479165636"><a name="p1961426479165636"></a><a name="p1961426479165636"></a><a href="RtcTime.md#afbfa636802d9e4e3b8502d4619ed771f">millisecond</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2022831001165636"><a name="p2022831001165636"></a><a name="p2022831001165636"></a>uint16_t </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section43113685165636"></a>

## **Field **<a name="section618246028165636"></a>

## day<a name="aad7e09d86beed6186b75ce2f1361f20b"></a>

```
uint8_t RtcTime::day
```

 **Description:**

Day. The value ranges from 1 to 31. 

## hour<a name="a0dc9482d29a4b61184b281b766b0ff89"></a>

```
uint8_t RtcTime::hour
```

 **Description:**

Hour. The value ranges from 0 to 23. 

## millisecond<a name="afbfa636802d9e4e3b8502d4619ed771f"></a>

```
uint16_t RtcTime::millisecond
```

 **Description:**

Millisecond. The value ranges from 0 to 990, with a precision of 10 milliseconds. 

## minute<a name="a990d7d066bc918d0b2f19162deb1845f"></a>

```
uint8_t RtcTime::minute
```

 **Description:**

Minute. The value ranges from 0 to 59. 

## month<a name="a527b18b3a0b709966d04106f0a5aed78"></a>

```
uint8_t RtcTime::month
```

 **Description:**

Month. The value ranges from 1 to 12. 

## second<a name="a8d7d49086d28faf2f700c45aab23c58b"></a>

```
uint8_t RtcTime::second
```

 **Description:**

Second. The value ranges from 0 to 59. 

## weekday<a name="aae45834a39c6b4a03dc85da72298b37e"></a>

```
uint8_t RtcTime::weekday
```

 **Description:**

Day of the week. The value ranges from 1 to 7, representing Monday to Sunday. 

## year<a name="a7781f6e9f083f7f24aa359651eadd19b"></a>

```
uint16_t RtcTime::year
```

 **Description:**

Year. The value is greater than or equal to 1970. 

