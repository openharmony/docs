# message.h<a name="ZH-CN_TOPIC_0000001054879506"></a>

-   [Overview](#section1811080524165628)
-   [Summary](#section1278442855165628)
-   [Data Structures](#nested-classes)
-   [Typedefs](#typedef-members)
-   [Functions](#func-members)

## **Overview**<a name="section1811080524165628"></a>

**Related Modules:**

[Samgr](Samgr.md)

**Description:**

Provides message communication APIs that help you to implement asynchronous functions of  [IUnknown](IUnknown.md). 

This API is used to implement asynchronous functions of  [IUnknown](IUnknown.md). 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1278442855165628"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table689765306165628"></a>
<table><thead align="left"><tr id="row304318902165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p91559945165628"><a name="p91559945165628"></a><a name="p91559945165628"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p708275396165628"><a name="p708275396165628"></a><a name="p708275396165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row200606799165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1627887216165628"><a name="p1627887216165628"></a><a name="p1627887216165628"></a><a href="Identity.md">Identity</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p884907104165628"><a name="p884907104165628"></a><a name="p884907104165628"></a>Identifies a service and feature. </p>
</td>
</tr>
<tr id="row846011197165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p577690925165628"><a name="p577690925165628"></a><a name="p577690925165628"></a><a href="Request.md">Request</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1153316861165628"><a name="p1153316861165628"></a><a name="p1153316861165628"></a>Defines a request. </p>
</td>
</tr>
<tr id="row1828087382165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p560768606165628"><a name="p560768606165628"></a><a name="p560768606165628"></a><a href="Response.md">Response</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1585063046165628"><a name="p1585063046165628"></a><a name="p1585063046165628"></a>Defines a response. </p>
</td>
</tr>
</tbody>
</table>

## Typedefs<a name="typedef-members"></a>

<a name="table1209191552165628"></a>
<table><thead align="left"><tr id="row223618001165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1646009010165628"><a name="p1646009010165628"></a><a name="p1646009010165628"></a>Typedef Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1148450842165628"><a name="p1148450842165628"></a><a name="p1148450842165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1576655396165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p87534596165628"><a name="p87534596165628"></a><a name="p87534596165628"></a><a href="Samgr.md#ga5e13d943cc6a87a5c99fe604f3bc01e4">Handler</a>) (const <a href="Request.md">Request</a> *request, const <a href="Response.md">Response</a> *response)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1637020319165628"><a name="p1637020319165628"></a><a name="p1637020319165628"></a>typedef void(* </p>
<p id="p330014035165628"><a name="p330014035165628"></a><a name="p330014035165628"></a>Handles asynchronous responses. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table130054695165628"></a>
<table><thead align="left"><tr id="row1165570266165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2014748192165628"><a name="p2014748192165628"></a><a name="p2014748192165628"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1995839121165628"><a name="p1995839121165628"></a><a name="p1995839121165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row785744202165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p961740429165628"><a name="p961740429165628"></a><a name="p961740429165628"></a><a href="Samgr.md#ga03b440d8dff9fcc8694ca8a3baa83462">SAMGR_SendRequest</a> (const <a href="Identity.md">Identity</a> *identity, const <a href="Request.md">Request</a> *request, <a href="Samgr.md#ga5e13d943cc6a87a5c99fe604f3bc01e4">Handler</a> handler)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1298668684165628"><a name="p1298668684165628"></a><a name="p1298668684165628"></a>int32 </p>
<p id="p1347878746165628"><a name="p1347878746165628"></a><a name="p1347878746165628"></a>Sends a request to a service or feature of a specified identity. </p>
</td>
</tr>
<tr id="row267829267165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p632975878165628"><a name="p632975878165628"></a><a name="p632975878165628"></a><a href="Samgr.md#gae7c4d087b251949d10d81e88a47e8dbd">SAMGR_SendSharedRequest</a> (const <a href="Identity.md">Identity</a> *identity, const <a href="Request.md">Request</a> *request, uint32 *token, <a href="Samgr.md#ga5e13d943cc6a87a5c99fe604f3bc01e4">Handler</a> handler)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p290504862165628"><a name="p290504862165628"></a><a name="p290504862165628"></a>uint32 * </p>
<p id="p1296679162165628"><a name="p1296679162165628"></a><a name="p1296679162165628"></a>Sends a request to multiple services or features to save memory. </p>
</td>
</tr>
<tr id="row792969858165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p993006821165628"><a name="p993006821165628"></a><a name="p993006821165628"></a><a href="Samgr.md#ga0c8c20d2265f4eb8ec8b516300a94a63">SAMGR_SendSharedDirectRequest</a> (const <a href="Identity.md">Identity</a> *id, const <a href="Request.md">Request</a> *req, const <a href="Response.md">Response</a> *resp, uint32 **ref, <a href="Samgr.md#ga5e13d943cc6a87a5c99fe604f3bc01e4">Handler</a> handler)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1961333815165628"><a name="p1961333815165628"></a><a name="p1961333815165628"></a>int32 </p>
<p id="p832592899165628"><a name="p832592899165628"></a><a name="p832592899165628"></a>Sends a request and response of a caller to the feature thread. The handler is directly called to process the request and response without using the message processing functions. (Customized function for the broadcast service) </p>
</td>
</tr>
<tr id="row583561874165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p519148356165628"><a name="p519148356165628"></a><a name="p519148356165628"></a><a href="Samgr.md#gadba5f2881a6e1403cb642726d5fec3e2">SAMGR_SendResponse</a> (const <a href="Request.md">Request</a> *request, const <a href="Response.md">Response</a> *response)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p815819809165628"><a name="p815819809165628"></a><a name="p815819809165628"></a>int32 </p>
<p id="p113417812165628"><a name="p113417812165628"></a><a name="p113417812165628"></a>Sends a response after processing a request. </p>
</td>
</tr>
<tr id="row933676435165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1268302525165628"><a name="p1268302525165628"></a><a name="p1268302525165628"></a><a href="Samgr.md#ga44ab9b4c98e2dd6ba3338d1d2664a6fe">SAMGR_SendResponseByIdentity</a> (const <a href="Identity.md">Identity</a> *id, const <a href="Request.md">Request</a> *request, const <a href="Response.md">Response</a> *response)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p437964940165628"><a name="p437964940165628"></a><a name="p437964940165628"></a>int32 </p>
<p id="p1038086613165628"><a name="p1038086613165628"></a><a name="p1038086613165628"></a>Sends a response to a specified service or feature after processing the original request. (Customized function for <strong id="b1001247832165628"><a name="b1001247832165628"></a><a name="b1001247832165628"></a>bootstrap</strong>) </p>
</td>
</tr>
</tbody>
</table>

