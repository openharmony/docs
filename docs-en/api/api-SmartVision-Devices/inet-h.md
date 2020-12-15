# inet.h<a name="EN-US_TOPIC_0000001055069406"></a>

-   [Overview](#section1691201113165627)
-   [Summary](#section587103100165627)
-   [Functions](#func-members)

## **Overview**<a name="section1691201113165627"></a>

**Related Modules:**

[NET](net.md)

**Description:**

Provides functions and data structures related to network operations. 

For example, you can use the functions to send and receive network data, manage network addresses, and convert bytes.

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section587103100165627"></a>

## Functions<a name="func-members"></a>

<a name="table329737880165627"></a>
<table><thead align="left"><tr id="row203265760165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p879332644165627"><a name="p879332644165627"></a><a name="p879332644165627"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1815323657165627"><a name="p1815323657165627"></a><a name="p1815323657165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row628001621165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p405484990165627"><a name="p405484990165627"></a><a name="p405484990165627"></a><a href="net.md#gac7eed08cd3b67f42bf56063157c8fd55">htonl</a> (uint32_t n)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p603449036165627"><a name="p603449036165627"></a><a name="p603449036165627"></a>uint32_t </p>
<p id="p1278771066165627"><a name="p1278771066165627"></a><a name="p1278771066165627"></a>Converts an integer from the host byte order to the network byte order. </p>
</td>
</tr>
<tr id="row1472334844165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1777064307165627"><a name="p1777064307165627"></a><a name="p1777064307165627"></a><a href="net.md#gaabce0f8d453c3380e5b8a3d4947eb48c">htons</a> (uint16_t n)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1933431007165627"><a name="p1933431007165627"></a><a name="p1933431007165627"></a>uint16_t </p>
<p id="p307948237165627"><a name="p307948237165627"></a><a name="p307948237165627"></a>Converts a 16-bit integer from the host byte order to the network byte order. </p>
</td>
</tr>
<tr id="row1984394812165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1859035991165627"><a name="p1859035991165627"></a><a name="p1859035991165627"></a><a href="net.md#gae68530d41f32dfef707f20b2bbaa5a44">ntohl</a> (uint32_t n)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p848108714165627"><a name="p848108714165627"></a><a name="p848108714165627"></a>uint32_t </p>
<p id="p366993544165627"><a name="p366993544165627"></a><a name="p366993544165627"></a>Converts an integer from the network byte order to the host byte order. </p>
</td>
</tr>
<tr id="row1731839882165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p594198004165627"><a name="p594198004165627"></a><a name="p594198004165627"></a><a href="net.md#gaf8c87af507c59bd8fef112e5e35fe537">ntohs</a> (uint16_t n)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1690792391165627"><a name="p1690792391165627"></a><a name="p1690792391165627"></a>uint16_t </p>
<p id="p1829629959165627"><a name="p1829629959165627"></a><a name="p1829629959165627"></a>Converts a 16-bit integer from the network byte order to the host byte order. </p>
</td>
</tr>
<tr id="row1909380534165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2021292259165627"><a name="p2021292259165627"></a><a name="p2021292259165627"></a><a href="net.md#ga617651ec952a1f4c9cbddbf78f4b2e2e">inet_addr</a> (const char *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p339672390165627"><a name="p339672390165627"></a><a name="p339672390165627"></a><a href="net.md#ga98b38134a62f24554da0ffcabde8062c">in_addr_t</a> </p>
<p id="p922452610165627"><a name="p922452610165627"></a><a name="p922452610165627"></a>Converts a string from the IPv4 numbers-and-dots notation to the binary data in network byte order. </p>
</td>
</tr>
<tr id="row1344795898165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p198369125165627"><a name="p198369125165627"></a><a name="p198369125165627"></a><a href="net.md#ga6f478437c4810fce89cf0e77d94181f8">inet_network</a> (const char *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p961041757165627"><a name="p961041757165627"></a><a name="p961041757165627"></a><a href="net.md#ga98b38134a62f24554da0ffcabde8062c">in_addr_t</a> </p>
<p id="p1503297601165627"><a name="p1503297601165627"></a><a name="p1503297601165627"></a>Converts a string from the IPv4 numbers-and-dots notation to the binary data in host byte order. </p>
</td>
</tr>
<tr id="row436111088165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p671850135165627"><a name="p671850135165627"></a><a name="p671850135165627"></a><a href="net.md#ga08b9fff487151e004d9862cbf34a51ad">inet_ntoa</a> (struct <a href="in_addr.md">in_addr</a> in)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p688670764165627"><a name="p688670764165627"></a><a name="p688670764165627"></a>char * </p>
<p id="p227359582165627"><a name="p227359582165627"></a><a name="p227359582165627"></a>Converts a network address to a string in dotted-decimal format. </p>
</td>
</tr>
<tr id="row2100934546165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1614402820165627"><a name="p1614402820165627"></a><a name="p1614402820165627"></a><a href="net.md#ga3f6e2b2dae98a409d77c6e3b0cebc04b">inet_pton</a> (int af, const char *__restrict s, void *__restrict a0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p748066484165627"><a name="p748066484165627"></a><a name="p748066484165627"></a>int </p>
<p id="p1513281216165627"><a name="p1513281216165627"></a><a name="p1513281216165627"></a>Converts a string to a network address in the specified address family. </p>
</td>
</tr>
<tr id="row819938174165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p953440811165627"><a name="p953440811165627"></a><a name="p953440811165627"></a><a href="net.md#gae9a2182ca3255f16723adeea14665b55">inet_ntop</a> (int af, const void *restrict a0, char *restrict s, <a href="utils.md#ga531675af4e35aaa1cc9aeefa6cc2ccc4">socklen_t</a> l)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p765130075165627"><a name="p765130075165627"></a><a name="p765130075165627"></a>const char * </p>
<p id="p1998242122165627"><a name="p1998242122165627"></a><a name="p1998242122165627"></a>Converts a network address in the specified address family to a string. </p>
</td>
</tr>
<tr id="row2105611514165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1228692752165627"><a name="p1228692752165627"></a><a name="p1228692752165627"></a><a href="net.md#ga26ee8e8e3949699a9c0e02ece272d370">inet_aton</a> (const char *s0, struct <a href="in_addr.md">in_addr</a> *dest)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2012457855165627"><a name="p2012457855165627"></a><a name="p2012457855165627"></a>int </p>
<p id="p1819860275165627"><a name="p1819860275165627"></a><a name="p1819860275165627"></a>Converts an IP address from the string format to the 32-bit binary format in network byte order. </p>
</td>
</tr>
<tr id="row1651118765165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p348060405165627"><a name="p348060405165627"></a><a name="p348060405165627"></a><a href="net.md#gab28732d1d740597f53fb65a09d97800c">inet_makeaddr</a> (<a href="net.md#ga98b38134a62f24554da0ffcabde8062c">in_addr_t</a> n, <a href="net.md#ga98b38134a62f24554da0ffcabde8062c">in_addr_t</a> h)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1432463088165627"><a name="p1432463088165627"></a><a name="p1432463088165627"></a>struct <a href="in_addr.md">in_addr</a> </p>
<p id="p280591530165627"><a name="p280591530165627"></a><a name="p280591530165627"></a>Converts the network number and host address to the network address. </p>
</td>
</tr>
<tr id="row1320402396165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1707775859165627"><a name="p1707775859165627"></a><a name="p1707775859165627"></a><a href="net.md#ga1facb1380b7657ca9c72fb2633b60e3b">inet_lnaof</a> (struct <a href="in_addr.md">in_addr</a> in)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p245371124165627"><a name="p245371124165627"></a><a name="p245371124165627"></a><a href="net.md#ga98b38134a62f24554da0ffcabde8062c">in_addr_t</a> </p>
<p id="p510577885165627"><a name="p510577885165627"></a><a name="p510577885165627"></a>Converts an IP address into a host ID in host byte order without network bits. </p>
</td>
</tr>
<tr id="row1377256908165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p274118321165627"><a name="p274118321165627"></a><a name="p274118321165627"></a><a href="net.md#ga3a96aa4e6abe8e6959ea63fe338174dd">inet_netof</a> (struct <a href="in_addr.md">in_addr</a> in)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1476298402165627"><a name="p1476298402165627"></a><a name="p1476298402165627"></a><a href="net.md#ga98b38134a62f24554da0ffcabde8062c">in_addr_t</a> </p>
<p id="p851506362165627"><a name="p851506362165627"></a><a name="p851506362165627"></a>Extracts the network number from the <strong id="b882542212165627"><a name="b882542212165627"></a><a name="b882542212165627"></a><a href="in_addr.md">in_addr</a></strong> structure and converts it to the host byte order. </p>
</td>
</tr>
</tbody>
</table>

