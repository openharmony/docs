# FormatCallback<a name="ZH-CN_TOPIC_0000001055358106"></a>

-   [Overview](#section2025395648165631)
-   [Summary](#section1628089547165631)
-   [Data Fields](#pub-attribs)
-   [Details](#section516987346165631)
-   [Field](#section160156636165631)
-   [OnError](#a47f30ebe4db3087e01c4259c0a983588)
-   [OnInfo](#a24b3d9a290f39522c4a733d141772cb1)
-   [privateDataHandle](#a4e4c7c6789cbf8bfc1aa0444dcd106b5)

## **Overview**<a name="section2025395648165631"></a>

**Related Modules:**

[Format](Format.md)

**Description:**

Defines listener callbacks for the format. 

## **Summary**<a name="section1628089547165631"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table709587583165631"></a>
<table><thead align="left"><tr id="row946310061165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p96249159165631"><a name="p96249159165631"></a><a name="p96249159165631"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p924909369165631"><a name="p924909369165631"></a><a name="p924909369165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row629097074165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1966122668165631"><a name="p1966122668165631"></a><a name="p1966122668165631"></a><a href="FormatCallback.md#a4e4c7c6789cbf8bfc1aa0444dcd106b5">privateDataHandle</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1204800892165631"><a name="p1204800892165631"></a><a name="p1204800892165631"></a><a href="Format.md#gab928f39c359734527bda3fd160f89331">CALLBACK_HANDLE</a> </p>
</td>
</tr>
<tr id="row1527051293165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1993286622165631"><a name="p1993286622165631"></a><a name="p1993286622165631"></a><a href="FormatCallback.md#a47f30ebe4db3087e01c4259c0a983588">OnError</a> )(<a href="Format.md#gab928f39c359734527bda3fd160f89331">CALLBACK_HANDLE</a> <a href="FormatCallback.md#a4e4c7c6789cbf8bfc1aa0444dcd106b5">privateDataHandle</a>, int32_t errorType, int32_t errorCode)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1422905631165631"><a name="p1422905631165631"></a><a name="p1422905631165631"></a>int32_t(* </p>
<p id="p635699712165631"><a name="p635699712165631"></a><a name="p635699712165631"></a>Called when a format error occurs during capturing. This callback is used to report the errors. </p>
</td>
</tr>
<tr id="row946652630165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p757264507165631"><a name="p757264507165631"></a><a name="p757264507165631"></a><a href="FormatCallback.md#a24b3d9a290f39522c4a733d141772cb1">OnInfo</a> )(<a href="Format.md#gab928f39c359734527bda3fd160f89331">CALLBACK_HANDLE</a> <a href="FormatCallback.md#a4e4c7c6789cbf8bfc1aa0444dcd106b5">privateDataHandle</a>, int32_t type, int32_t extra)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1846346690165631"><a name="p1846346690165631"></a><a name="p1846346690165631"></a>int32_t(* </p>
<p id="p402537600165631"><a name="p402537600165631"></a><a name="p402537600165631"></a>Called when an information event occurs during capturing. This callback is used to report capturing information. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section516987346165631"></a>

## **Field **<a name="section160156636165631"></a>

## OnError<a name="a47f30ebe4db3087e01c4259c0a983588"></a>

```
int32_t(* FormatCallback::OnError) ([CALLBACK_HANDLE](Format.md#gab928f39c359734527bda3fd160f89331) [privateDataHandle](FormatCallback.md#a4e4c7c6789cbf8bfc1aa0444dcd106b5), int32_t errorType, int32_t errorCode)
```

 **Description:**

Called when a format error occurs during capturing. This callback is used to report the errors. 

**Parameters:**

<a name="table54852415165631"></a>
<table><thead align="left"><tr id="row2109745952165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p802347312165631"><a name="p802347312165631"></a><a name="p802347312165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1114119377165631"><a name="p1114119377165631"></a><a name="p1114119377165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row706748530165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">privateDataHandle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the private data handle. </td>
</tr>
<tr id="row2112034002165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">errorType</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the error type. For details, see <a href="Format.md#ga31e7fcf42722fa15e4e5489c2fef9092">FormatErrorType</a>. </td>
</tr>
<tr id="row1172459167165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">errorCode</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the error code. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise. 

## OnInfo<a name="a24b3d9a290f39522c4a733d141772cb1"></a>

```
int32_t(* FormatCallback::OnInfo) ([CALLBACK_HANDLE](Format.md#gab928f39c359734527bda3fd160f89331) [privateDataHandle](FormatCallback.md#a4e4c7c6789cbf8bfc1aa0444dcd106b5), int32_t type, int32_t extra)
```

 **Description:**

Called when an information event occurs during capturing. This callback is used to report capturing information. 

**Parameters:**

<a name="table819378564165631"></a>
<table><thead align="left"><tr id="row1895357909165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p129534052165631"><a name="p129534052165631"></a><a name="p129534052165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p129590092165631"><a name="p129590092165631"></a><a name="p129590092165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1901082466165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">privateDataHandle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the private data handle. </td>
</tr>
<tr id="row732648488165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">type</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the information type. For details, see <a href="Format.md#ga6f00342925d3d5e586c76f8695985cad">FormatInfoType</a>. </td>
</tr>
<tr id="row1708396419165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">extra</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates other information, for example, the start time position of the captured file. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise. 

## privateDataHandle<a name="a4e4c7c6789cbf8bfc1aa0444dcd106b5"></a>

```
[CALLBACK_HANDLE](Format.md#gab928f39c359734527bda3fd160f89331) FormatCallback::privateDataHandle
```

 **Description:**

Private data handle 

